// Generated from split_quant8_3.mod.py
// DO NOT EDIT
// clang-format off
#include "TestHarness.h"

using namespace test_helper;

namespace generated_tests::split_quant8_3 {

const TestModel& get_test_model() {
    static TestModel model = {
        .expectedMultinomialDistributionTolerance = 0,
        .inputIndexes = {0},
        .isRelaxed = false,
        .operands = {{
                .channelQuant = {},
                .data = TestBuffer::createFromVector<uint8_t>({1, 2, 3, 4, 5, 6}),
                .dimensions = {2, 3},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::MODEL_INPUT,
                .numberOfConsumers = 1,
                .scale = 2.0f,
                .type = TestOperandType::TENSOR_QUANT8_ASYMM,
                .zeroPoint = 3
            }, {
                .channelQuant = {},
                .data = TestBuffer::createFromVector<int32_t>({1}),
                .dimensions = {},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::CONSTANT_COPY,
                .numberOfConsumers = 1,
                .scale = 0.0f,
                .type = TestOperandType::INT32,
                .zeroPoint = 0
            }, {
                .channelQuant = {},
                .data = TestBuffer::createFromVector<int32_t>({3}),
                .dimensions = {},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::CONSTANT_COPY,
                .numberOfConsumers = 1,
                .scale = 0.0f,
                .type = TestOperandType::INT32,
                .zeroPoint = 0
            }, {
                .channelQuant = {},
                .data = TestBuffer::createFromVector<uint8_t>({1, 4}),
                .dimensions = {2, 1},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::MODEL_OUTPUT,
                .numberOfConsumers = 0,
                .scale = 2.0f,
                .type = TestOperandType::TENSOR_QUANT8_ASYMM,
                .zeroPoint = 3
            }, {
                .channelQuant = {},
                .data = TestBuffer::createFromVector<uint8_t>({2, 5}),
                .dimensions = {2, 1},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::MODEL_OUTPUT,
                .numberOfConsumers = 0,
                .scale = 2.0f,
                .type = TestOperandType::TENSOR_QUANT8_ASYMM,
                .zeroPoint = 3
            }, {
                .channelQuant = {},
                .data = TestBuffer::createFromVector<uint8_t>({3, 6}),
                .dimensions = {2, 1},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::MODEL_OUTPUT,
                .numberOfConsumers = 0,
                .scale = 2.0f,
                .type = TestOperandType::TENSOR_QUANT8_ASYMM,
                .zeroPoint = 3
            }},
        .operations = {{
                .inputs = {0, 1, 2},
                .outputs = {3, 4, 5},
                .type = TestOperationType::SPLIT
            }},
        .outputIndexes = {3, 4, 5}
    };
    return model;
}

}  // namespace generated_tests::split_quant8_3

namespace generated_tests::split_quant8_3 {

const TestModel& get_test_model_all_inputs_as_internal() {
    static TestModel model = {
        .expectedMultinomialDistributionTolerance = 0,
        .inputIndexes = {6},
        .isRelaxed = false,
        .operands = {{
                .channelQuant = {},
                .data = TestBuffer::createFromVector<uint8_t>({}),
                .dimensions = {2, 3},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::TEMPORARY_VARIABLE,
                .numberOfConsumers = 1,
                .scale = 2.0f,
                .type = TestOperandType::TENSOR_QUANT8_ASYMM,
                .zeroPoint = 3
            }, {
                .channelQuant = {},
                .data = TestBuffer::createFromVector<int32_t>({1}),
                .dimensions = {},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::CONSTANT_COPY,
                .numberOfConsumers = 1,
                .scale = 0.0f,
                .type = TestOperandType::INT32,
                .zeroPoint = 0
            }, {
                .channelQuant = {},
                .data = TestBuffer::createFromVector<int32_t>({3}),
                .dimensions = {},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::CONSTANT_COPY,
                .numberOfConsumers = 1,
                .scale = 0.0f,
                .type = TestOperandType::INT32,
                .zeroPoint = 0
            }, {
                .channelQuant = {},
                .data = TestBuffer::createFromVector<uint8_t>({1, 4}),
                .dimensions = {2, 1},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::MODEL_OUTPUT,
                .numberOfConsumers = 0,
                .scale = 2.0f,
                .type = TestOperandType::TENSOR_QUANT8_ASYMM,
                .zeroPoint = 3
            }, {
                .channelQuant = {},
                .data = TestBuffer::createFromVector<uint8_t>({2, 5}),
                .dimensions = {2, 1},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::MODEL_OUTPUT,
                .numberOfConsumers = 0,
                .scale = 2.0f,
                .type = TestOperandType::TENSOR_QUANT8_ASYMM,
                .zeroPoint = 3
            }, {
                .channelQuant = {},
                .data = TestBuffer::createFromVector<uint8_t>({3, 6}),
                .dimensions = {2, 1},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::MODEL_OUTPUT,
                .numberOfConsumers = 0,
                .scale = 2.0f,
                .type = TestOperandType::TENSOR_QUANT8_ASYMM,
                .zeroPoint = 3
            }, {
                .channelQuant = {},
                .data = TestBuffer::createFromVector<uint8_t>({1, 2, 3, 4, 5, 6}),
                .dimensions = {2, 3},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::MODEL_INPUT,
                .numberOfConsumers = 1,
                .scale = 2.0f,
                .type = TestOperandType::TENSOR_QUANT8_ASYMM,
                .zeroPoint = 3
            }, {
                .channelQuant = {},
                .data = TestBuffer::createFromVector<uint8_t>({3}),
                .dimensions = {1},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::CONSTANT_COPY,
                .numberOfConsumers = 1,
                .scale = 2.0f,
                .type = TestOperandType::TENSOR_QUANT8_ASYMM,
                .zeroPoint = 3
            }, {
                .channelQuant = {},
                .data = TestBuffer::createFromVector<int32_t>({0}),
                .dimensions = {},
                .isIgnored = false,
                .lifetime = TestOperandLifeTime::CONSTANT_COPY,
                .numberOfConsumers = 1,
                .scale = 0.0f,
                .type = TestOperandType::INT32,
                .zeroPoint = 0
            }},
        .operations = {{
                .inputs = {6, 7, 8},
                .outputs = {0},
                .type = TestOperationType::ADD
            }, {
                .inputs = {0, 1, 2},
                .outputs = {3, 4, 5},
                .type = TestOperationType::SPLIT
            }},
        .outputIndexes = {3, 4, 5}
    };
    return model;
}

}  // namespace generated_tests::split_quant8_3

