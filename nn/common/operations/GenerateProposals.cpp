/*
 * Copyright (C) 2018 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "CpuOperationUtils.h"
#include "OperationResolver.h"
#include "OperationsUtils.h"

#include <cfloat>
#include <cmath>

#include "Tracing.h"

namespace android {
namespace nn {
namespace generate_proposals {

namespace {

struct BoxEncodingCorner {
    float x1, y1, x2, y2;
};
struct BoxEncodingCenter {
    float w, h, x, y;
};
BoxEncodingCorner toBoxEncodingCorner(const BoxEncodingCenter& ctr) {
    return {.x1 = ctr.x - ctr.w / 2,
            .y1 = ctr.y - ctr.h / 2,
            .x2 = ctr.x + ctr.w / 2,
            .y2 = ctr.y + ctr.h / 2};
}
BoxEncodingCenter toBoxEncodingCenter(const BoxEncodingCorner& cnr) {
    return {.w = cnr.x2 - cnr.x1,
            .h = cnr.y2 - cnr.y1,
            .x = (cnr.x1 + cnr.x2) / 2,
            .y = (cnr.y1 + cnr.y2) / 2};
}

inline bool bboxTransformFloat32(const float* roiData, const Shape& roiShape,
                                 const float* bboxDeltasData, const Shape& bboxDeltasShape,
                                 const int32_t* batchSplitData, const Shape& batchSplitShape,
                                 const float* imageInfoData, const Shape& imageInfoDataShape,
                                 float* outputData, const Shape& outputShape) {
    const uint32_t roiLength = 4;
    const uint32_t imageLength = 2;

    uint32_t numClasses = getSizeOfDimension(bboxDeltasShape, 1) / roiLength;
    uint32_t numBatches = getSizeOfDimension(batchSplitShape, 0);

    const float* roiDataEnd = roiData + getNumberOfElements(roiShape);
    const float* deltas = bboxDeltasData;
    float* outPtr = outputData;
    uint32_t batchIndex = 0, roiIndex = 0;
    for (const float* roiBase = roiData; roiBase < roiDataEnd; roiBase += roiLength, roiIndex++) {
        while (roiIndex >= batchSplitData[batchIndex]) {
            batchIndex++;
            roiIndex = 0;
        }

        // Check for malformed data
        // 1. invalid batch id
        // 2. Invalid region: x2 <= x1 || y2 <= y1
        NN_RET_CHECK_GE(batchIndex, 0);
        NN_RET_CHECK_LT(batchIndex, numBatches);
        NN_RET_CHECK_LT(roiBase[0], roiBase[2]);
        NN_RET_CHECK_LT(roiBase[1], roiBase[3]);

        const float* imageInfoBase = imageInfoData + batchIndex * imageLength;
        float imageHeight = imageInfoBase[0];
        float imageWidth = imageInfoBase[1];
        auto roiBefore = toBoxEncodingCenter(
                {.x1 = roiBase[0], .y1 = roiBase[1], .x2 = roiBase[2], .y2 = roiBase[3]});
        for (uint32_t i = 0; i < numClasses; i++) {
            auto roiAfter = toBoxEncodingCorner({.w = std::exp(deltas[2]) * roiBefore.w,
                                                 .h = std::exp(deltas[3]) * roiBefore.h,
                                                 .x = roiBefore.x + deltas[0] * roiBefore.w,
                                                 .y = roiBefore.y + deltas[1] * roiBefore.h});
            BoxEncodingCorner cliped = {.x1 = std::min(std::max(roiAfter.x1, 0.0f), imageWidth),
                                        .y1 = std::min(std::max(roiAfter.y1, 0.0f), imageHeight),
                                        .x2 = std::min(std::max(roiAfter.x2, 0.0f), imageWidth),
                                        .y2 = std::min(std::max(roiAfter.y2, 0.0f), imageHeight)};
            outPtr[0] = cliped.x1;
            outPtr[1] = cliped.y1;
            outPtr[2] = cliped.x2;
            outPtr[3] = cliped.y2;
            deltas += roiLength;
            outPtr += roiLength;
        }
    }
    return true;
}

inline bool bboxTransformFloat16(const _Float16* roiData, const Shape& roiShape,
                                 const _Float16* bboxDeltasData, const Shape& bboxDeltasShape,
                                 const int32_t* batchSplitData, const Shape& batchSplitShape,
                                 const _Float16* imageInfoData, const Shape& imageInfoDataShape,
                                 _Float16* outputData, const Shape& outputShape) {
    std::vector<float> roi_float32(getNumberOfElements(roiShape));
    convertFloat16ToFloat32(roiData, &roi_float32);
    std::vector<float> delta_float32(getNumberOfElements(bboxDeltasShape));
    convertFloat16ToFloat32(bboxDeltasData, &delta_float32);
    std::vector<float> imageInfo_float32(getNumberOfElements(imageInfoDataShape));
    convertFloat16ToFloat32(imageInfoData, &imageInfo_float32);
    std::vector<float> output_float32(getNumberOfElements(outputShape));
    NN_RET_CHECK(bboxTransformFloat32(roi_float32.data(), roiShape, delta_float32.data(),
                                      bboxDeltasShape, batchSplitData, batchSplitShape,
                                      imageInfo_float32.data(), imageInfoDataShape,
                                      output_float32.data(), outputShape));
    convertFloat32ToFloat16(output_float32, outputData);
    return true;
}

inline bool bboxTransformQuant(const uint16_t* roiData, const Shape& roiShape,
                               const uint8_t* bboxDeltasData, const Shape& bboxDeltasShape,
                               const int32_t* batchSplitData, const Shape& batchSplitShape,
                               const uint16_t* imageInfoData, const Shape& imageInfoDataShape,
                               uint16_t* outputData, const Shape& outputShape) {
    std::vector<float> roi_float32(getNumberOfElements(roiShape));
    convertQuantToFloat32(roiData, roiShape.scale, roiShape.offset, &roi_float32);
    std::vector<float> delta_float32(getNumberOfElements(bboxDeltasShape));
    convertQuantToFloat32(bboxDeltasData, bboxDeltasShape.scale, bboxDeltasShape.offset,
                          &delta_float32);
    std::vector<float> imageInfo_float32(getNumberOfElements(imageInfoDataShape));
    convertQuantToFloat32(imageInfoData, imageInfoDataShape.scale, imageInfoDataShape.offset,
                          &imageInfo_float32);
    std::vector<float> output_float32(getNumberOfElements(outputShape));
    NN_RET_CHECK(bboxTransformFloat32(roi_float32.data(), roiShape, delta_float32.data(),
                                      bboxDeltasShape, batchSplitData, batchSplitShape,
                                      imageInfo_float32.data(), imageInfoDataShape,
                                      output_float32.data(), outputShape));
    convertFloat32ToQuant(output_float32, outputShape.scale, outputShape.offset, outputData);
    return true;
}

// Taking two indices of bounding boxes, return the intersection-of-union.
float getIoUAxisAligned(const float* roiBase, uint32_t ind1, uint32_t ind2) {
    const uint32_t kRoiDim = 4;
    const float* roi1 = roiBase + ind1 * kRoiDim;
    const float* roi2 = roiBase + ind2 * kRoiDim;
    const float area1 = (roi1[2] - roi1[0]) * (roi1[3] - roi1[1]);
    const float area2 = (roi2[2] - roi2[0]) * (roi2[3] - roi2[1]);
    const float x1 = std::max(roi1[0], roi2[0]);
    const float x2 = std::min(roi1[2], roi2[2]);
    const float y1 = std::max(roi1[1], roi2[1]);
    const float y2 = std::min(roi1[3], roi2[3]);
    const float w = std::max(x2 - x1, 0.0f);
    const float h = std::max(y2 - y1, 0.0f);
    const float areaIntersect = w * h;
    const float areaUnion = area1 + area2 - areaIntersect;
    return areaIntersect / areaUnion;
}

}  // namespace

namespace axis_aligned_bbox_transform {

constexpr char kOperationName[] = "AXIS_ALIGNED_BBOX_TRANSFORM";

constexpr uint32_t kNumInputs = 4;
constexpr uint32_t kRoiTensor = 0;
constexpr uint32_t kDeltaTensor = 1;
constexpr uint32_t kBatchSplitTensor = 2;
constexpr uint32_t kImageInfoTensor = 3;

constexpr uint32_t kNumOutputs = 1;
constexpr uint32_t kOutputTensor = 0;

bool validate(const IOperationValidationContext* context) {
    NN_RET_CHECK_EQ(context->getNumInputs(), kNumInputs);
    NN_RET_CHECK_EQ(context->getNumOutputs(), kNumOutputs);
    std::vector<OperandType> inExpectedTypes;
    auto inputType = context->getInputType(kRoiTensor);
    if (inputType == OperandType::TENSOR_FLOAT32 || inputType == OperandType::TENSOR_FLOAT16) {
        inExpectedTypes = {inputType, inputType, OperandType::TENSOR_INT32, inputType};
    } else if (inputType == OperandType::TENSOR_QUANT16_ASYMM) {
        inExpectedTypes = {OperandType::TENSOR_QUANT16_ASYMM, OperandType::TENSOR_QUANT8_ASYMM,
                           OperandType::TENSOR_INT32, OperandType::TENSOR_QUANT16_ASYMM};
    } else {
        LOG(ERROR) << "Unsupported input tensor type for operation " << kOperationName;
        return false;
    }
    NN_RET_CHECK(validateInputTypes(context, inExpectedTypes));
    NN_RET_CHECK(validateOutputTypes(context, {inputType}));
    return validateHalVersion(context, HalVersion::V1_2);
}

bool prepare(IOperationExecutionContext* context) {
    Shape roiShape = context->getInputShape(kRoiTensor);
    Shape bboxDeltasShape = context->getInputShape(kDeltaTensor);
    Shape batchSplitShape = context->getInputShape(kBatchSplitTensor);
    Shape imageInfoShape = context->getInputShape(kImageInfoTensor);
    Shape outputShape = context->getOutputShape(kOutputTensor);

    NN_OPS_CHECK(getNumberOfDimensions(roiShape) == 2);
    NN_OPS_CHECK(getNumberOfDimensions(bboxDeltasShape) == 2);
    NN_OPS_CHECK(getNumberOfDimensions(batchSplitShape) == 1);
    NN_OPS_CHECK(getNumberOfDimensions(imageInfoShape) == 2);

    const uint32_t kRoiDim = 4;
    uint32_t numRois = getSizeOfDimension(roiShape, 0);
    uint32_t numClasses = getSizeOfDimension(bboxDeltasShape, 1) / kRoiDim;
    uint32_t numBatches = getSizeOfDimension(batchSplitShape, 0);

    NN_OPS_CHECK(getSizeOfDimension(roiShape, 1) == kRoiDim);
    NN_OPS_CHECK(getSizeOfDimension(bboxDeltasShape, 0) == numRois);
    NN_OPS_CHECK(getSizeOfDimension(bboxDeltasShape, 1) == kRoiDim * numClasses);
    NN_OPS_CHECK(getSizeOfDimension(imageInfoShape, 0) == numBatches);
    NN_OPS_CHECK(getSizeOfDimension(imageInfoShape, 1) == 2);

    if (roiShape.type == OperandType::TENSOR_QUANT16_ASYMM) {
        NN_RET_CHECK_EQ(roiShape.scale, 0.125f);
        NN_RET_CHECK_EQ(roiShape.offset, 0);
        NN_RET_CHECK_EQ(imageInfoShape.scale, 0.125f);
        NN_RET_CHECK_EQ(imageInfoShape.offset, 0);
    }

    outputShape.type = roiShape.type;
    outputShape.dimensions = {numRois, numClasses * kRoiDim};
    outputShape.scale = 0.125f;
    outputShape.offset = 0;
    NN_RET_CHECK(context->setOutputShape(kOutputTensor, outputShape));
    return true;
}

bool execute(IOperationExecutionContext* context) {
    NNTRACE_TRANS("axisAlignedBBoxTransform");
    switch (context->getInputType(kRoiTensor)) {
        case OperandType::TENSOR_FLOAT16: {
            return bboxTransformFloat16(context->getInputBuffer<_Float16>(kRoiTensor),
                                        context->getInputShape(kRoiTensor),
                                        context->getInputBuffer<_Float16>(kDeltaTensor),
                                        context->getInputShape(kDeltaTensor),
                                        context->getInputBuffer<int32_t>(kBatchSplitTensor),
                                        context->getInputShape(kBatchSplitTensor),
                                        context->getInputBuffer<_Float16>(kImageInfoTensor),
                                        context->getInputShape(kImageInfoTensor),
                                        context->getOutputBuffer<_Float16>(kOutputTensor),
                                        context->getOutputShape(kOutputTensor));
        }
        case OperandType::TENSOR_FLOAT32: {
            return bboxTransformFloat32(context->getInputBuffer<float>(kRoiTensor),
                                        context->getInputShape(kRoiTensor),
                                        context->getInputBuffer<float>(kDeltaTensor),
                                        context->getInputShape(kDeltaTensor),
                                        context->getInputBuffer<int32_t>(kBatchSplitTensor),
                                        context->getInputShape(kBatchSplitTensor),
                                        context->getInputBuffer<float>(kImageInfoTensor),
                                        context->getInputShape(kImageInfoTensor),
                                        context->getOutputBuffer<float>(kOutputTensor),
                                        context->getOutputShape(kOutputTensor));
        }
        case OperandType::TENSOR_QUANT16_ASYMM: {
            return bboxTransformQuant(context->getInputBuffer<uint16_t>(kRoiTensor),
                                      context->getInputShape(kRoiTensor),
                                      context->getInputBuffer<uint8_t>(kDeltaTensor),
                                      context->getInputShape(kDeltaTensor),
                                      context->getInputBuffer<int32_t>(kBatchSplitTensor),
                                      context->getInputShape(kBatchSplitTensor),
                                      context->getInputBuffer<uint16_t>(kImageInfoTensor),
                                      context->getInputShape(kImageInfoTensor),
                                      context->getOutputBuffer<uint16_t>(kOutputTensor),
                                      context->getOutputShape(kOutputTensor));
        }
        default:
            NN_RET_CHECK_FAIL() << "Unsupported tensor type for operation " << kOperationName;
    }
}

}  // namespace axis_aligned_bbox_transform

namespace box_with_nms_limit {

constexpr char kOperationName[] = "BOX_WITH_NMS_LIMIT";

constexpr uint32_t kNumInputs = 6;
constexpr uint32_t kScoreTensor = 0;
constexpr uint32_t kRoiTensor = 1;
constexpr uint32_t kBatchSplitTensor = 2;
constexpr uint32_t kScoreThresholdScalar = 3;
constexpr uint32_t kIoUThresholdScalar = 4;
constexpr uint32_t kMaxNumDetectionScalar = 5;

constexpr uint32_t kNumOutputs = 4;
constexpr uint32_t kOutputScoreTensor = 0;
constexpr uint32_t kOutputRoiTensor = 1;
constexpr uint32_t kOutputClassTensor = 2;
constexpr uint32_t kOutputBatchSplitTensor = 3;

namespace {

// Inplace hard NMS within range [select, select + selectLength).
uint32_t* hardNmsSingleClass(const float* scoresData, const float* roiData, float iouThreshold,
                             uint32_t* select, uint32_t selectLength) {
    uint32_t *selectStart = select, *selectEnd = select + selectLength;
    while (selectStart < selectEnd) {
        // find max score and swap to the front
        auto& maxScore = *std::max_element(selectStart, selectEnd,
                                           [&scoresData](const uint32_t& lhs, const uint32_t& rhs) {
                                               return scoresData[lhs] < scoresData[rhs];
                                           });
        std::swap(maxScore, *selectStart);

        // Calculate IoU of the rest, swap to the end (disgard) if needed.
        for (uint32_t* i = selectStart + 1; i < selectEnd; i++) {
            float iou = getIoUAxisAligned(roiData, *i, *selectStart);
            if (iou >= iouThreshold) {
                std::swap(*i--, *(--selectEnd));
            }
        }
        selectStart++;
    }
    return selectStart;
}

void hardNmsMultiClass(const float* scoresData, const float* roiData, std::vector<uint32_t>& select,
                       uint32_t numClasses, uint32_t numRois, float scoreThreshold,
                       float iouThreshold, int32_t maxNumDetections) {
    // Exclude class 0 (background)
    for (uint32_t c = 1; c < numClasses; c++) {
        uint32_t size = select.size();
        for (uint32_t b = 0; b < numRois; b++) {
            const uint32_t index = b * numClasses + c;
            const float score = scoresData[index];
            if (score > scoreThreshold) {
                select.push_back(index);
            }
        }
        uint32_t* selectStart = select.data() + size;
        uint32_t selectLength = select.size() - size;
        uint32_t* selectEnd =
                hardNmsSingleClass(scoresData, roiData, iouThreshold, selectStart, selectLength);
        select.resize(selectEnd - select.data());
    }

    // Take top maxNumDetections.
    if (maxNumDetections < 0 || select.size() <= maxNumDetections) {
        return;
    }
    std::sort(select.begin(), select.end(),
              [&scoresData](const uint32_t& lhs, const uint32_t& rhs) {
                  return scoresData[lhs] > scoresData[rhs];
              });
    select.resize(maxNumDetections);

    // Sort again by class.
    std::sort(select.begin(), select.end(),
              [&scoresData, numClasses](const uint32_t& lhs, const uint32_t& rhs) {
                  uint32_t lhsClass = lhs % numClasses, rhsClass = rhs % numClasses;
                  return lhsClass == rhsClass ? scoresData[lhs] > scoresData[rhs]
                                              : lhsClass < rhsClass;
              });
}

bool boxWithNmsLimitFloat32(const float* scoresData, const Shape& scoresShape, const float* roiData,
                            const Shape& roiShape, const int32_t* batchSplitData,
                            const Shape& batchSplitShape, float scoreThreshold, float iouThreshold,
                            int32_t maxNumDetections, float* scoresOutData, Shape scoresOutShape,
                            float* roiOutData, Shape roiOutShape, int32_t* classesOutData,
                            Shape classesOutShape, int32_t* batchSplitOutData,
                            const Shape& batchSplitOutShape, IOperationExecutionContext* context) {
    NNTRACE_TRANS("boxWithNmsLimit");
    const uint32_t kRoiDim = 4;
    uint32_t numClasses = getSizeOfDimension(scoresShape, 1);
    uint32_t numBatches = getSizeOfDimension(batchSplitShape, 0);

    const float* scoresBase = scoresData;
    const float* roiBase = roiData;
    int32_t* batchSplitOutPtr = batchSplitOutData;
    std::vector<uint32_t> selected;
    for (uint32_t b = 0; b < numBatches; b++) {
        std::vector<uint32_t> result;
        hardNmsMultiClass(scoresBase, roiBase, result, numClasses, batchSplitData[b],
                          scoreThreshold, iouThreshold, maxNumDetections);
        selected.insert(selected.end(), result.begin(), result.end());
        *batchSplitOutPtr++ = result.size();
        scoresBase += batchSplitData[b] * numClasses;
        roiBase += batchSplitData[b] * numClasses * kRoiDim;
    }

    // Set output dimensions.
    uint32_t numOutRois = selected.size();
    scoresOutShape.dimensions = {numOutRois};
    NN_RET_CHECK(context->setOutputShape(kOutputScoreTensor, scoresOutShape));
    roiOutShape.dimensions = {numOutRois, 4};
    NN_RET_CHECK(context->setOutputShape(kOutputRoiTensor, roiOutShape));
    classesOutShape.dimensions = {numOutRois};
    NN_RET_CHECK(context->setOutputShape(kOutputClassTensor, classesOutShape));

    // Write outputs.
    float* scoresOutPtr = scoresOutData;
    float* roiOutPtr = roiOutData;
    int32_t* classesOutPtr = classesOutData;
    scoresBase = scoresData;
    roiBase = roiData;
    uint32_t i = 0;
    for (uint32_t b = 0; b < numBatches; b++) {
        for (uint32_t j = 0; j < batchSplitOutData[b]; j++) {
            uint32_t index = selected[i++];
            *scoresOutPtr++ = scoresBase[index];
            memcpy(roiOutPtr, roiBase + index * kRoiDim, kRoiDim * sizeof(float));
            roiOutPtr += kRoiDim;
            *classesOutPtr++ = index % numClasses;
        }
        scoresBase += batchSplitData[b] * numClasses;
        roiBase += batchSplitData[b] * numClasses * kRoiDim;
    }
    return true;
}

bool boxWithNmsLimitFloat16(const _Float16* scoresData, const Shape& scoresShape,
                            const _Float16* roiData, const Shape& roiShape,
                            const int32_t* batchSplitData, const Shape& batchSplitShape,
                            _Float16 scoreThreshold, _Float16 iouThreshold,
                            int32_t maxNumDetections, _Float16* scoresOutData,
                            const Shape& scoresOutShape, _Float16* roiOutData,
                            const Shape& roiOutShape, int32_t* classesOutData,
                            const Shape& classesOutShape, int32_t* batchSplitOutData,
                            const Shape& batchSplitOutShape, IOperationExecutionContext* context) {
    std::vector<float> scores_float32(getNumberOfElements(scoresShape));
    convertFloat16ToFloat32(scoresData, &scores_float32);
    std::vector<float> roi_float32(getNumberOfElements(roiShape));
    convertFloat16ToFloat32(roiData, &roi_float32);
    std::vector<float> outputScores_float32(getNumberOfElements(scoresOutShape));
    std::vector<float> outputRoi_float32(getNumberOfElements(roiOutShape));
    NN_RET_CHECK(boxWithNmsLimitFloat32(
            scores_float32.data(), scoresShape, roi_float32.data(), roiShape, batchSplitData,
            batchSplitShape, scoreThreshold, iouThreshold, maxNumDetections,
            outputScores_float32.data(), scoresOutShape, outputRoi_float32.data(), roiOutShape,
            classesOutData, classesOutShape, batchSplitOutData, batchSplitOutShape, context));
    convertFloat32ToFloat16(outputScores_float32, scoresOutData);
    convertFloat32ToFloat16(outputRoi_float32, roiOutData);
    return true;
}

bool boxWithNmsLimitQuant(const uint8_t* scoresData, const Shape& scoresShape,
                          const uint16_t* roiData, const Shape& roiShape,
                          const int32_t* batchSplitData, const Shape& batchSplitShape,
                          float scoreThreshold, float iouThreshold, int32_t maxNumDetections,
                          uint8_t* scoresOutData, const Shape& scoresOutShape, uint16_t* roiOutData,
                          const Shape& roiOutShape, int32_t* classesOutData,
                          const Shape& classesOutShape, int32_t* batchSplitOutData,
                          const Shape& batchSplitOutShape, IOperationExecutionContext* context) {
    std::vector<float> scores_float32(getNumberOfElements(scoresShape));
    convertQuantToFloat32(scoresData, scoresShape.scale, scoresShape.offset, &scores_float32);
    std::vector<float> roi_float32(getNumberOfElements(roiShape));
    convertQuantToFloat32(roiData, roiShape.scale, roiShape.offset, &roi_float32);
    std::vector<float> outputScores_float32(getNumberOfElements(scoresOutShape));
    std::vector<float> outputRoi_float32(getNumberOfElements(roiOutShape));
    NN_RET_CHECK(boxWithNmsLimitFloat32(
            scores_float32.data(), scoresShape, roi_float32.data(), roiShape, batchSplitData,
            batchSplitShape, scoreThreshold, iouThreshold, maxNumDetections,
            outputScores_float32.data(), scoresOutShape, outputRoi_float32.data(), roiOutShape,
            classesOutData, classesOutShape, batchSplitOutData, batchSplitOutShape, context));
    convertFloat32ToQuant(outputScores_float32, scoresOutShape.scale, scoresOutShape.offset,
                          scoresOutData);
    convertFloat32ToQuant(outputRoi_float32, roiOutShape.scale, roiOutShape.offset, roiOutData);
    return true;
}

}  // namespace

bool validate(const IOperationValidationContext* context) {
    NN_RET_CHECK_EQ(context->getNumInputs(), kNumInputs);
    NN_RET_CHECK_EQ(context->getNumOutputs(), kNumOutputs);
    std::vector<OperandType> inExpectedTypes;
    std::vector<OperandType> outExpectedTypes;
    auto inputType = context->getInputType(kScoreTensor);
    if (inputType == OperandType::TENSOR_FLOAT16) {
        inExpectedTypes = {OperandType::TENSOR_FLOAT16, OperandType::TENSOR_FLOAT16,
                           OperandType::TENSOR_INT32,   OperandType::FLOAT16,
                           OperandType::FLOAT16,        OperandType::INT32};
        outExpectedTypes = {OperandType::TENSOR_FLOAT16, OperandType::TENSOR_FLOAT16,
                            OperandType::TENSOR_INT32, OperandType::TENSOR_INT32};
    } else if (inputType == OperandType::TENSOR_FLOAT32) {
        inExpectedTypes = {OperandType::TENSOR_FLOAT32, OperandType::TENSOR_FLOAT32,
                           OperandType::TENSOR_INT32,   OperandType::FLOAT32,
                           OperandType::FLOAT32,        OperandType::INT32};
        outExpectedTypes = {OperandType::TENSOR_FLOAT32, OperandType::TENSOR_FLOAT32,
                            OperandType::TENSOR_INT32, OperandType::TENSOR_INT32};
    } else if (inputType == OperandType::TENSOR_QUANT8_ASYMM) {
        inExpectedTypes = {OperandType::TENSOR_QUANT8_ASYMM,
                           OperandType::TENSOR_QUANT16_ASYMM,
                           OperandType::TENSOR_INT32,
                           OperandType::FLOAT32,
                           OperandType::FLOAT32,
                           OperandType::INT32};
        outExpectedTypes = {OperandType::TENSOR_QUANT8_ASYMM, OperandType::TENSOR_QUANT16_ASYMM,
                            OperandType::TENSOR_INT32, OperandType::TENSOR_INT32};
    } else {
        NN_RET_CHECK_FAIL() << "Unsupported tensor type for operation " << kOperationName;
    }
    NN_RET_CHECK(validateInputTypes(context, inExpectedTypes));
    NN_RET_CHECK(validateOutputTypes(context, outExpectedTypes));
    return validateHalVersion(context, HalVersion::V1_2);
}

bool prepare(IOperationExecutionContext* context) {
    Shape scoreShape = context->getInputShape(kScoreTensor);
    Shape roiShape = context->getInputShape(kRoiTensor);
    Shape batchSplitShape = context->getInputShape(kBatchSplitTensor);
    Shape outputScoreShape = context->getOutputShape(kOutputScoreTensor);
    Shape outputRoiShape = context->getOutputShape(kOutputRoiTensor);
    Shape outputClassShape = context->getOutputShape(kOutputClassTensor);
    Shape outputBatchSplitShape = context->getOutputShape(kOutputBatchSplitTensor);

    NN_RET_CHECK(getNumberOfDimensions(scoreShape) == 2);
    NN_RET_CHECK(getNumberOfDimensions(roiShape) == 2);
    NN_RET_CHECK(getNumberOfDimensions(batchSplitShape) == 1);

    const uint32_t kRoiDim = 4;
    uint32_t numRois = getSizeOfDimension(scoreShape, 0);
    uint32_t numClasses = getSizeOfDimension(scoreShape, 1);
    uint32_t numBatches = getSizeOfDimension(batchSplitShape, 0);
    NN_RET_CHECK(getSizeOfDimension(roiShape, 0) == numRois);
    NN_RET_CHECK(getSizeOfDimension(roiShape, 1) == kRoiDim * numClasses);
    NN_RET_CHECK_GT(numClasses, 1);

    if (scoreShape.type == OperandType::TENSOR_QUANT8_ASYMM) {
        NN_RET_CHECK_EQ(roiShape.scale, 0.125f);
        NN_RET_CHECK_EQ(roiShape.offset, 0);
    }

    outputScoreShape.type = scoreShape.type;
    outputScoreShape.dimensions = {0};
    outputScoreShape.scale = scoreShape.scale;
    outputScoreShape.offset = scoreShape.offset;
    NN_RET_CHECK(context->setOutputShape(kOutputScoreTensor, outputScoreShape));

    outputRoiShape.type = roiShape.type;
    outputRoiShape.dimensions = {0, 4};
    outputRoiShape.scale = 0.125f;
    outputRoiShape.offset = 0;
    NN_RET_CHECK(context->setOutputShape(kOutputRoiTensor, outputRoiShape));

    outputClassShape.type = OperandType::TENSOR_INT32;
    outputClassShape.dimensions = {0};
    NN_RET_CHECK(context->setOutputShape(kOutputClassTensor, outputClassShape));

    outputBatchSplitShape.type = batchSplitShape.type;
    outputBatchSplitShape.dimensions = {numBatches};
    NN_RET_CHECK(context->setOutputShape(kOutputBatchSplitTensor, outputBatchSplitShape));
    return true;
}

bool execute(IOperationExecutionContext* context) {
    NNTRACE_TRANS("boxWithNMSLimit");
    switch (context->getInputType(kScoreTensor)) {
        case OperandType::TENSOR_FLOAT16: {
            return boxWithNmsLimitFloat16(
                    context->getInputBuffer<_Float16>(kScoreTensor),
                    context->getInputShape(kScoreTensor),
                    context->getInputBuffer<_Float16>(kRoiTensor),
                    context->getInputShape(kRoiTensor),
                    context->getInputBuffer<int32_t>(kBatchSplitTensor),
                    context->getInputShape(kBatchSplitTensor),
                    context->getInputValue<_Float16>(kScoreThresholdScalar),
                    context->getInputValue<_Float16>(kIoUThresholdScalar),
                    context->getInputValue<int32_t>(kMaxNumDetectionScalar),
                    context->getOutputBuffer<_Float16>(kOutputScoreTensor),
                    context->getOutputShape(kOutputScoreTensor),
                    context->getOutputBuffer<_Float16>(kOutputRoiTensor),
                    context->getOutputShape(kOutputRoiTensor),
                    context->getOutputBuffer<int32_t>(kOutputClassTensor),
                    context->getOutputShape(kOutputClassTensor),
                    context->getOutputBuffer<int32_t>(kOutputBatchSplitTensor),
                    context->getOutputShape(kOutputBatchSplitTensor), context);
        }
        case OperandType::TENSOR_FLOAT32: {
            return boxWithNmsLimitFloat32(
                    context->getInputBuffer<float>(kScoreTensor),
                    context->getInputShape(kScoreTensor),
                    context->getInputBuffer<float>(kRoiTensor), context->getInputShape(kRoiTensor),
                    context->getInputBuffer<int32_t>(kBatchSplitTensor),
                    context->getInputShape(kBatchSplitTensor),
                    context->getInputValue<float>(kScoreThresholdScalar),
                    context->getInputValue<float>(kIoUThresholdScalar),
                    context->getInputValue<int32_t>(kMaxNumDetectionScalar),
                    context->getOutputBuffer<float>(kOutputScoreTensor),
                    context->getOutputShape(kOutputScoreTensor),
                    context->getOutputBuffer<float>(kOutputRoiTensor),
                    context->getOutputShape(kOutputRoiTensor),
                    context->getOutputBuffer<int32_t>(kOutputClassTensor),
                    context->getOutputShape(kOutputClassTensor),
                    context->getOutputBuffer<int32_t>(kOutputBatchSplitTensor),
                    context->getOutputShape(kOutputBatchSplitTensor), context);
        }
        case OperandType::TENSOR_QUANT8_ASYMM: {
            return boxWithNmsLimitQuant(context->getInputBuffer<uint8_t>(kScoreTensor),
                                        context->getInputShape(kScoreTensor),
                                        context->getInputBuffer<uint16_t>(kRoiTensor),
                                        context->getInputShape(kRoiTensor),
                                        context->getInputBuffer<int32_t>(kBatchSplitTensor),
                                        context->getInputShape(kBatchSplitTensor),
                                        context->getInputValue<float>(kScoreThresholdScalar),
                                        context->getInputValue<float>(kIoUThresholdScalar),
                                        context->getInputValue<int32_t>(kMaxNumDetectionScalar),
                                        context->getOutputBuffer<uint8_t>(kOutputScoreTensor),
                                        context->getOutputShape(kOutputScoreTensor),
                                        context->getOutputBuffer<uint16_t>(kOutputRoiTensor),
                                        context->getOutputShape(kOutputRoiTensor),
                                        context->getOutputBuffer<int32_t>(kOutputClassTensor),
                                        context->getOutputShape(kOutputClassTensor),
                                        context->getOutputBuffer<int32_t>(kOutputBatchSplitTensor),
                                        context->getOutputShape(kOutputBatchSplitTensor), context);
        }
        default:
            NN_RET_CHECK_FAIL() << "Unsupported tensor type for operation " << kOperationName;
    }
}

}  // namespace box_with_nms_limit

}  // namespace generate_proposals

NN_REGISTER_OPERATION(AXIS_ALIGNED_BBOX_TRANSFORM,
                      generate_proposals::axis_aligned_bbox_transform::kOperationName,
                      generate_proposals::axis_aligned_bbox_transform::validate,
                      generate_proposals::axis_aligned_bbox_transform::prepare,
                      generate_proposals::axis_aligned_bbox_transform::execute);

NN_REGISTER_OPERATION(BOX_WITH_NMS_LIMIT, generate_proposals::box_with_nms_limit::kOperationName,
                      generate_proposals::box_with_nms_limit::validate,
                      generate_proposals::box_with_nms_limit::prepare,
                      generate_proposals::box_with_nms_limit::execute);
}  // namespace nn
}  // namespace android
