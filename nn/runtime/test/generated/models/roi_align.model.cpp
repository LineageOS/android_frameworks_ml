// clang-format off
// Generated file (from: roi_align.mod.py). Do not edit
void CreateModel_nhwc(Model *model) {
  OperandType type0(Type::BOOL, {});
  OperandType type1(Type::TENSOR_FLOAT32, {1, 4, 4, 1});
  OperandType type2(Type::TENSOR_FLOAT32, {4, 4});
  OperandType type3(Type::TENSOR_FLOAT32, {4, 2, 2, 1});
  OperandType type4(Type::INT32, {});
  OperandType type5(Type::FLOAT32, {});
  // Phase 1, operands
  auto in = model->addOperand(&type1);
  auto roi = model->addOperand(&type2);
  auto param = model->addOperand(&type4);
  auto param1 = model->addOperand(&type4);
  auto param2 = model->addOperand(&type5);
  auto param3 = model->addOperand(&type5);
  auto param4 = model->addOperand(&type4);
  auto param5 = model->addOperand(&type4);
  auto layout = model->addOperand(&type0);
  auto out = model->addOperand(&type3);
  // Phase 2, operations
  static int32_t param_init[] = {2};
  model->setOperandValue(param, param_init, sizeof(int32_t) * 1);
  static int32_t param1_init[] = {2};
  model->setOperandValue(param1, param1_init, sizeof(int32_t) * 1);
  static float param2_init[] = {0.5f};
  model->setOperandValue(param2, param2_init, sizeof(float) * 1);
  static float param3_init[] = {0.5f};
  model->setOperandValue(param3, param3_init, sizeof(float) * 1);
  static int32_t param4_init[] = {4};
  model->setOperandValue(param4, param4_init, sizeof(int32_t) * 1);
  static int32_t param5_init[] = {4};
  model->setOperandValue(param5, param5_init, sizeof(int32_t) * 1);
  static bool8 layout_init[] = {false};
  model->setOperandValue(layout, layout_init, sizeof(bool8) * 1);
  model->addOperation(ANEURALNETWORKS_ROI_ALIGN, {in, roi, param, param1, param2, param3, param4, param5, layout}, {out});
  // Phase 3, inputs and outputs
  model->identifyInputsAndOutputs(
    {in, roi},
    {out});
  assert(model->isValid());
}

inline bool is_ignored_nhwc(int i) {
  static std::set<int> ignore = {};
  return ignore.find(i) != ignore.end();
}

void CreateModel_nhwc_relaxed(Model *model) {
  OperandType type0(Type::BOOL, {});
  OperandType type1(Type::TENSOR_FLOAT32, {1, 4, 4, 1});
  OperandType type2(Type::TENSOR_FLOAT32, {4, 4});
  OperandType type3(Type::TENSOR_FLOAT32, {4, 2, 2, 1});
  OperandType type4(Type::INT32, {});
  OperandType type5(Type::FLOAT32, {});
  // Phase 1, operands
  auto in = model->addOperand(&type1);
  auto roi = model->addOperand(&type2);
  auto param = model->addOperand(&type4);
  auto param1 = model->addOperand(&type4);
  auto param2 = model->addOperand(&type5);
  auto param3 = model->addOperand(&type5);
  auto param4 = model->addOperand(&type4);
  auto param5 = model->addOperand(&type4);
  auto layout = model->addOperand(&type0);
  auto out = model->addOperand(&type3);
  // Phase 2, operations
  static int32_t param_init[] = {2};
  model->setOperandValue(param, param_init, sizeof(int32_t) * 1);
  static int32_t param1_init[] = {2};
  model->setOperandValue(param1, param1_init, sizeof(int32_t) * 1);
  static float param2_init[] = {0.5f};
  model->setOperandValue(param2, param2_init, sizeof(float) * 1);
  static float param3_init[] = {0.5f};
  model->setOperandValue(param3, param3_init, sizeof(float) * 1);
  static int32_t param4_init[] = {4};
  model->setOperandValue(param4, param4_init, sizeof(int32_t) * 1);
  static int32_t param5_init[] = {4};
  model->setOperandValue(param5, param5_init, sizeof(int32_t) * 1);
  static bool8 layout_init[] = {false};
  model->setOperandValue(layout, layout_init, sizeof(bool8) * 1);
  model->addOperation(ANEURALNETWORKS_ROI_ALIGN, {in, roi, param, param1, param2, param3, param4, param5, layout}, {out});
  // Phase 3, inputs and outputs
  model->identifyInputsAndOutputs(
    {in, roi},
    {out});
  // Phase 4: set relaxed execution
  model->relaxComputationFloat32toFloat16(true);
  assert(model->isValid());
}

inline bool is_ignored_nhwc_relaxed(int i) {
  static std::set<int> ignore = {};
  return ignore.find(i) != ignore.end();
}

void CreateModel_nhwc_quant8(Model *model) {
  OperandType type0(Type::BOOL, {});
  OperandType type11(Type::TENSOR_QUANT8_ASYMM, {1, 4, 4, 1}, 0.25f, 128);
  OperandType type12(Type::TENSOR_QUANT8_ASYMM, {4, 2, 2, 1}, 0.0625f, 128);
  OperandType type2(Type::TENSOR_FLOAT32, {4, 4});
  OperandType type4(Type::INT32, {});
  OperandType type5(Type::FLOAT32, {});
  // Phase 1, operands
  auto in = model->addOperand(&type11);
  auto roi = model->addOperand(&type2);
  auto param = model->addOperand(&type4);
  auto param1 = model->addOperand(&type4);
  auto param2 = model->addOperand(&type5);
  auto param3 = model->addOperand(&type5);
  auto param4 = model->addOperand(&type4);
  auto param5 = model->addOperand(&type4);
  auto layout = model->addOperand(&type0);
  auto out = model->addOperand(&type12);
  // Phase 2, operations
  static int32_t param_init[] = {2};
  model->setOperandValue(param, param_init, sizeof(int32_t) * 1);
  static int32_t param1_init[] = {2};
  model->setOperandValue(param1, param1_init, sizeof(int32_t) * 1);
  static float param2_init[] = {0.5f};
  model->setOperandValue(param2, param2_init, sizeof(float) * 1);
  static float param3_init[] = {0.5f};
  model->setOperandValue(param3, param3_init, sizeof(float) * 1);
  static int32_t param4_init[] = {4};
  model->setOperandValue(param4, param4_init, sizeof(int32_t) * 1);
  static int32_t param5_init[] = {4};
  model->setOperandValue(param5, param5_init, sizeof(int32_t) * 1);
  static bool8 layout_init[] = {false};
  model->setOperandValue(layout, layout_init, sizeof(bool8) * 1);
  model->addOperation(ANEURALNETWORKS_ROI_ALIGN, {in, roi, param, param1, param2, param3, param4, param5, layout}, {out});
  // Phase 3, inputs and outputs
  model->identifyInputsAndOutputs(
    {in, roi},
    {out});
  assert(model->isValid());
}

inline bool is_ignored_nhwc_quant8(int i) {
  static std::set<int> ignore = {};
  return ignore.find(i) != ignore.end();
}

void CreateModel_nhwc_float16(Model *model) {
  OperandType type0(Type::BOOL, {});
  OperandType type13(Type::TENSOR_FLOAT16, {1, 4, 4, 1});
  OperandType type14(Type::TENSOR_FLOAT16, {4, 2, 2, 1});
  OperandType type15(Type::FLOAT16, {});
  OperandType type16(Type::TENSOR_FLOAT16, {4, 4});
  OperandType type4(Type::INT32, {});
  // Phase 1, operands
  auto in = model->addOperand(&type13);
  auto roi = model->addOperand(&type16);
  auto param = model->addOperand(&type4);
  auto param1 = model->addOperand(&type4);
  auto param2 = model->addOperand(&type15);
  auto param3 = model->addOperand(&type15);
  auto param4 = model->addOperand(&type4);
  auto param5 = model->addOperand(&type4);
  auto layout = model->addOperand(&type0);
  auto out = model->addOperand(&type14);
  // Phase 2, operations
  static int32_t param_init[] = {2};
  model->setOperandValue(param, param_init, sizeof(int32_t) * 1);
  static int32_t param1_init[] = {2};
  model->setOperandValue(param1, param1_init, sizeof(int32_t) * 1);
  static _Float16 param2_init[] = {0.5f};
  model->setOperandValue(param2, param2_init, sizeof(_Float16) * 1);
  static _Float16 param3_init[] = {0.5f};
  model->setOperandValue(param3, param3_init, sizeof(_Float16) * 1);
  static int32_t param4_init[] = {4};
  model->setOperandValue(param4, param4_init, sizeof(int32_t) * 1);
  static int32_t param5_init[] = {4};
  model->setOperandValue(param5, param5_init, sizeof(int32_t) * 1);
  static bool8 layout_init[] = {false};
  model->setOperandValue(layout, layout_init, sizeof(bool8) * 1);
  model->addOperation(ANEURALNETWORKS_ROI_ALIGN, {in, roi, param, param1, param2, param3, param4, param5, layout}, {out});
  // Phase 3, inputs and outputs
  model->identifyInputsAndOutputs(
    {in, roi},
    {out});
  assert(model->isValid());
}

inline bool is_ignored_nhwc_float16(int i) {
  static std::set<int> ignore = {};
  return ignore.find(i) != ignore.end();
}

void CreateModel_nchw(Model *model) {
  OperandType type0(Type::BOOL, {});
  OperandType type17(Type::TENSOR_FLOAT32, {1, 1, 4, 4});
  OperandType type18(Type::TENSOR_FLOAT32, {4, 1, 2, 2});
  OperandType type2(Type::TENSOR_FLOAT32, {4, 4});
  OperandType type4(Type::INT32, {});
  OperandType type5(Type::FLOAT32, {});
  // Phase 1, operands
  auto in = model->addOperand(&type17);
  auto roi = model->addOperand(&type2);
  auto param = model->addOperand(&type4);
  auto param1 = model->addOperand(&type4);
  auto param2 = model->addOperand(&type5);
  auto param3 = model->addOperand(&type5);
  auto param4 = model->addOperand(&type4);
  auto param5 = model->addOperand(&type4);
  auto layout = model->addOperand(&type0);
  auto out = model->addOperand(&type18);
  // Phase 2, operations
  static int32_t param_init[] = {2};
  model->setOperandValue(param, param_init, sizeof(int32_t) * 1);
  static int32_t param1_init[] = {2};
  model->setOperandValue(param1, param1_init, sizeof(int32_t) * 1);
  static float param2_init[] = {0.5f};
  model->setOperandValue(param2, param2_init, sizeof(float) * 1);
  static float param3_init[] = {0.5f};
  model->setOperandValue(param3, param3_init, sizeof(float) * 1);
  static int32_t param4_init[] = {4};
  model->setOperandValue(param4, param4_init, sizeof(int32_t) * 1);
  static int32_t param5_init[] = {4};
  model->setOperandValue(param5, param5_init, sizeof(int32_t) * 1);
  static bool8 layout_init[] = {true};
  model->setOperandValue(layout, layout_init, sizeof(bool8) * 1);
  model->addOperation(ANEURALNETWORKS_ROI_ALIGN, {in, roi, param, param1, param2, param3, param4, param5, layout}, {out});
  // Phase 3, inputs and outputs
  model->identifyInputsAndOutputs(
    {in, roi},
    {out});
  assert(model->isValid());
}

inline bool is_ignored_nchw(int i) {
  static std::set<int> ignore = {};
  return ignore.find(i) != ignore.end();
}

void CreateModel_nchw_relaxed(Model *model) {
  OperandType type0(Type::BOOL, {});
  OperandType type17(Type::TENSOR_FLOAT32, {1, 1, 4, 4});
  OperandType type18(Type::TENSOR_FLOAT32, {4, 1, 2, 2});
  OperandType type2(Type::TENSOR_FLOAT32, {4, 4});
  OperandType type4(Type::INT32, {});
  OperandType type5(Type::FLOAT32, {});
  // Phase 1, operands
  auto in = model->addOperand(&type17);
  auto roi = model->addOperand(&type2);
  auto param = model->addOperand(&type4);
  auto param1 = model->addOperand(&type4);
  auto param2 = model->addOperand(&type5);
  auto param3 = model->addOperand(&type5);
  auto param4 = model->addOperand(&type4);
  auto param5 = model->addOperand(&type4);
  auto layout = model->addOperand(&type0);
  auto out = model->addOperand(&type18);
  // Phase 2, operations
  static int32_t param_init[] = {2};
  model->setOperandValue(param, param_init, sizeof(int32_t) * 1);
  static int32_t param1_init[] = {2};
  model->setOperandValue(param1, param1_init, sizeof(int32_t) * 1);
  static float param2_init[] = {0.5f};
  model->setOperandValue(param2, param2_init, sizeof(float) * 1);
  static float param3_init[] = {0.5f};
  model->setOperandValue(param3, param3_init, sizeof(float) * 1);
  static int32_t param4_init[] = {4};
  model->setOperandValue(param4, param4_init, sizeof(int32_t) * 1);
  static int32_t param5_init[] = {4};
  model->setOperandValue(param5, param5_init, sizeof(int32_t) * 1);
  static bool8 layout_init[] = {true};
  model->setOperandValue(layout, layout_init, sizeof(bool8) * 1);
  model->addOperation(ANEURALNETWORKS_ROI_ALIGN, {in, roi, param, param1, param2, param3, param4, param5, layout}, {out});
  // Phase 3, inputs and outputs
  model->identifyInputsAndOutputs(
    {in, roi},
    {out});
  // Phase 4: set relaxed execution
  model->relaxComputationFloat32toFloat16(true);
  assert(model->isValid());
}

inline bool is_ignored_nchw_relaxed(int i) {
  static std::set<int> ignore = {};
  return ignore.find(i) != ignore.end();
}

void CreateModel_nchw_quant8(Model *model) {
  OperandType type0(Type::BOOL, {});
  OperandType type19(Type::TENSOR_QUANT8_ASYMM, {1, 1, 4, 4}, 0.25f, 128);
  OperandType type2(Type::TENSOR_FLOAT32, {4, 4});
  OperandType type20(Type::TENSOR_QUANT8_ASYMM, {4, 1, 2, 2}, 0.0625f, 128);
  OperandType type4(Type::INT32, {});
  OperandType type5(Type::FLOAT32, {});
  // Phase 1, operands
  auto in = model->addOperand(&type19);
  auto roi = model->addOperand(&type2);
  auto param = model->addOperand(&type4);
  auto param1 = model->addOperand(&type4);
  auto param2 = model->addOperand(&type5);
  auto param3 = model->addOperand(&type5);
  auto param4 = model->addOperand(&type4);
  auto param5 = model->addOperand(&type4);
  auto layout = model->addOperand(&type0);
  auto out = model->addOperand(&type20);
  // Phase 2, operations
  static int32_t param_init[] = {2};
  model->setOperandValue(param, param_init, sizeof(int32_t) * 1);
  static int32_t param1_init[] = {2};
  model->setOperandValue(param1, param1_init, sizeof(int32_t) * 1);
  static float param2_init[] = {0.5f};
  model->setOperandValue(param2, param2_init, sizeof(float) * 1);
  static float param3_init[] = {0.5f};
  model->setOperandValue(param3, param3_init, sizeof(float) * 1);
  static int32_t param4_init[] = {4};
  model->setOperandValue(param4, param4_init, sizeof(int32_t) * 1);
  static int32_t param5_init[] = {4};
  model->setOperandValue(param5, param5_init, sizeof(int32_t) * 1);
  static bool8 layout_init[] = {true};
  model->setOperandValue(layout, layout_init, sizeof(bool8) * 1);
  model->addOperation(ANEURALNETWORKS_ROI_ALIGN, {in, roi, param, param1, param2, param3, param4, param5, layout}, {out});
  // Phase 3, inputs and outputs
  model->identifyInputsAndOutputs(
    {in, roi},
    {out});
  assert(model->isValid());
}

inline bool is_ignored_nchw_quant8(int i) {
  static std::set<int> ignore = {};
  return ignore.find(i) != ignore.end();
}

void CreateModel_nchw_float16(Model *model) {
  OperandType type0(Type::BOOL, {});
  OperandType type15(Type::FLOAT16, {});
  OperandType type16(Type::TENSOR_FLOAT16, {4, 4});
  OperandType type21(Type::TENSOR_FLOAT16, {1, 1, 4, 4});
  OperandType type22(Type::TENSOR_FLOAT16, {4, 1, 2, 2});
  OperandType type4(Type::INT32, {});
  // Phase 1, operands
  auto in = model->addOperand(&type21);
  auto roi = model->addOperand(&type16);
  auto param = model->addOperand(&type4);
  auto param1 = model->addOperand(&type4);
  auto param2 = model->addOperand(&type15);
  auto param3 = model->addOperand(&type15);
  auto param4 = model->addOperand(&type4);
  auto param5 = model->addOperand(&type4);
  auto layout = model->addOperand(&type0);
  auto out = model->addOperand(&type22);
  // Phase 2, operations
  static int32_t param_init[] = {2};
  model->setOperandValue(param, param_init, sizeof(int32_t) * 1);
  static int32_t param1_init[] = {2};
  model->setOperandValue(param1, param1_init, sizeof(int32_t) * 1);
  static _Float16 param2_init[] = {0.5f};
  model->setOperandValue(param2, param2_init, sizeof(_Float16) * 1);
  static _Float16 param3_init[] = {0.5f};
  model->setOperandValue(param3, param3_init, sizeof(_Float16) * 1);
  static int32_t param4_init[] = {4};
  model->setOperandValue(param4, param4_init, sizeof(int32_t) * 1);
  static int32_t param5_init[] = {4};
  model->setOperandValue(param5, param5_init, sizeof(int32_t) * 1);
  static bool8 layout_init[] = {true};
  model->setOperandValue(layout, layout_init, sizeof(bool8) * 1);
  model->addOperation(ANEURALNETWORKS_ROI_ALIGN, {in, roi, param, param1, param2, param3, param4, param5, layout}, {out});
  // Phase 3, inputs and outputs
  model->identifyInputsAndOutputs(
    {in, roi},
    {out});
  assert(model->isValid());
}

inline bool is_ignored_nchw_float16(int i) {
  static std::set<int> ignore = {};
  return ignore.find(i) != ignore.end();
}

void CreateModel_nhwc_2(Model *model) {
  OperandType type0(Type::BOOL, {});
  OperandType type4(Type::INT32, {});
  OperandType type5(Type::FLOAT32, {});
  OperandType type6(Type::TENSOR_FLOAT32, {2, 4, 8, 2});
  OperandType type7(Type::TENSOR_FLOAT32, {4, 5});
  OperandType type8(Type::TENSOR_FLOAT32, {4, 2, 3, 2});
  // Phase 1, operands
  auto in1 = model->addOperand(&type6);
  auto roi1 = model->addOperand(&type7);
  auto param6 = model->addOperand(&type4);
  auto param7 = model->addOperand(&type4);
  auto param8 = model->addOperand(&type5);
  auto param9 = model->addOperand(&type5);
  auto param10 = model->addOperand(&type4);
  auto param11 = model->addOperand(&type4);
  auto layout = model->addOperand(&type0);
  auto out1 = model->addOperand(&type8);
  // Phase 2, operations
  static int32_t param6_init[] = {2};
  model->setOperandValue(param6, param6_init, sizeof(int32_t) * 1);
  static int32_t param7_init[] = {3};
  model->setOperandValue(param7, param7_init, sizeof(int32_t) * 1);
  static float param8_init[] = {0.25f};
  model->setOperandValue(param8, param8_init, sizeof(float) * 1);
  static float param9_init[] = {0.25f};
  model->setOperandValue(param9, param9_init, sizeof(float) * 1);
  static int32_t param10_init[] = {4};
  model->setOperandValue(param10, param10_init, sizeof(int32_t) * 1);
  static int32_t param11_init[] = {4};
  model->setOperandValue(param11, param11_init, sizeof(int32_t) * 1);
  static bool8 layout_init[] = {false};
  model->setOperandValue(layout, layout_init, sizeof(bool8) * 1);
  model->addOperation(ANEURALNETWORKS_ROI_ALIGN, {in1, roi1, param6, param7, param8, param9, param10, param11, layout}, {out1});
  // Phase 3, inputs and outputs
  model->identifyInputsAndOutputs(
    {in1, roi1},
    {out1});
  assert(model->isValid());
}

inline bool is_ignored_nhwc_2(int i) {
  static std::set<int> ignore = {};
  return ignore.find(i) != ignore.end();
}

void CreateModel_nhwc_relaxed_2(Model *model) {
  OperandType type0(Type::BOOL, {});
  OperandType type4(Type::INT32, {});
  OperandType type5(Type::FLOAT32, {});
  OperandType type6(Type::TENSOR_FLOAT32, {2, 4, 8, 2});
  OperandType type7(Type::TENSOR_FLOAT32, {4, 5});
  OperandType type8(Type::TENSOR_FLOAT32, {4, 2, 3, 2});
  // Phase 1, operands
  auto in1 = model->addOperand(&type6);
  auto roi1 = model->addOperand(&type7);
  auto param6 = model->addOperand(&type4);
  auto param7 = model->addOperand(&type4);
  auto param8 = model->addOperand(&type5);
  auto param9 = model->addOperand(&type5);
  auto param10 = model->addOperand(&type4);
  auto param11 = model->addOperand(&type4);
  auto layout = model->addOperand(&type0);
  auto out1 = model->addOperand(&type8);
  // Phase 2, operations
  static int32_t param6_init[] = {2};
  model->setOperandValue(param6, param6_init, sizeof(int32_t) * 1);
  static int32_t param7_init[] = {3};
  model->setOperandValue(param7, param7_init, sizeof(int32_t) * 1);
  static float param8_init[] = {0.25f};
  model->setOperandValue(param8, param8_init, sizeof(float) * 1);
  static float param9_init[] = {0.25f};
  model->setOperandValue(param9, param9_init, sizeof(float) * 1);
  static int32_t param10_init[] = {4};
  model->setOperandValue(param10, param10_init, sizeof(int32_t) * 1);
  static int32_t param11_init[] = {4};
  model->setOperandValue(param11, param11_init, sizeof(int32_t) * 1);
  static bool8 layout_init[] = {false};
  model->setOperandValue(layout, layout_init, sizeof(bool8) * 1);
  model->addOperation(ANEURALNETWORKS_ROI_ALIGN, {in1, roi1, param6, param7, param8, param9, param10, param11, layout}, {out1});
  // Phase 3, inputs and outputs
  model->identifyInputsAndOutputs(
    {in1, roi1},
    {out1});
  // Phase 4: set relaxed execution
  model->relaxComputationFloat32toFloat16(true);
  assert(model->isValid());
}

inline bool is_ignored_nhwc_relaxed_2(int i) {
  static std::set<int> ignore = {};
  return ignore.find(i) != ignore.end();
}

void CreateModel_nhwc_quant8_2(Model *model) {
  OperandType type0(Type::BOOL, {});
  OperandType type23(Type::TENSOR_QUANT8_ASYMM, {2, 4, 8, 2}, 0.04f, 0);
  OperandType type24(Type::TENSOR_QUANT8_ASYMM, {4, 2, 3, 2}, 0.03125f, 10);
  OperandType type4(Type::INT32, {});
  OperandType type5(Type::FLOAT32, {});
  OperandType type7(Type::TENSOR_FLOAT32, {4, 5});
  // Phase 1, operands
  auto in1 = model->addOperand(&type23);
  auto roi1 = model->addOperand(&type7);
  auto param6 = model->addOperand(&type4);
  auto param7 = model->addOperand(&type4);
  auto param8 = model->addOperand(&type5);
  auto param9 = model->addOperand(&type5);
  auto param10 = model->addOperand(&type4);
  auto param11 = model->addOperand(&type4);
  auto layout = model->addOperand(&type0);
  auto out1 = model->addOperand(&type24);
  // Phase 2, operations
  static int32_t param6_init[] = {2};
  model->setOperandValue(param6, param6_init, sizeof(int32_t) * 1);
  static int32_t param7_init[] = {3};
  model->setOperandValue(param7, param7_init, sizeof(int32_t) * 1);
  static float param8_init[] = {0.25f};
  model->setOperandValue(param8, param8_init, sizeof(float) * 1);
  static float param9_init[] = {0.25f};
  model->setOperandValue(param9, param9_init, sizeof(float) * 1);
  static int32_t param10_init[] = {4};
  model->setOperandValue(param10, param10_init, sizeof(int32_t) * 1);
  static int32_t param11_init[] = {4};
  model->setOperandValue(param11, param11_init, sizeof(int32_t) * 1);
  static bool8 layout_init[] = {false};
  model->setOperandValue(layout, layout_init, sizeof(bool8) * 1);
  model->addOperation(ANEURALNETWORKS_ROI_ALIGN, {in1, roi1, param6, param7, param8, param9, param10, param11, layout}, {out1});
  // Phase 3, inputs and outputs
  model->identifyInputsAndOutputs(
    {in1, roi1},
    {out1});
  assert(model->isValid());
}

inline bool is_ignored_nhwc_quant8_2(int i) {
  static std::set<int> ignore = {};
  return ignore.find(i) != ignore.end();
}

void CreateModel_nhwc_float16_2(Model *model) {
  OperandType type0(Type::BOOL, {});
  OperandType type15(Type::FLOAT16, {});
  OperandType type25(Type::TENSOR_FLOAT16, {2, 4, 8, 2});
  OperandType type26(Type::TENSOR_FLOAT16, {4, 2, 3, 2});
  OperandType type27(Type::TENSOR_FLOAT16, {4, 5});
  OperandType type4(Type::INT32, {});
  // Phase 1, operands
  auto in1 = model->addOperand(&type25);
  auto roi1 = model->addOperand(&type27);
  auto param6 = model->addOperand(&type4);
  auto param7 = model->addOperand(&type4);
  auto param8 = model->addOperand(&type15);
  auto param9 = model->addOperand(&type15);
  auto param10 = model->addOperand(&type4);
  auto param11 = model->addOperand(&type4);
  auto layout = model->addOperand(&type0);
  auto out1 = model->addOperand(&type26);
  // Phase 2, operations
  static int32_t param6_init[] = {2};
  model->setOperandValue(param6, param6_init, sizeof(int32_t) * 1);
  static int32_t param7_init[] = {3};
  model->setOperandValue(param7, param7_init, sizeof(int32_t) * 1);
  static _Float16 param8_init[] = {0.25f};
  model->setOperandValue(param8, param8_init, sizeof(_Float16) * 1);
  static _Float16 param9_init[] = {0.25f};
  model->setOperandValue(param9, param9_init, sizeof(_Float16) * 1);
  static int32_t param10_init[] = {4};
  model->setOperandValue(param10, param10_init, sizeof(int32_t) * 1);
  static int32_t param11_init[] = {4};
  model->setOperandValue(param11, param11_init, sizeof(int32_t) * 1);
  static bool8 layout_init[] = {false};
  model->setOperandValue(layout, layout_init, sizeof(bool8) * 1);
  model->addOperation(ANEURALNETWORKS_ROI_ALIGN, {in1, roi1, param6, param7, param8, param9, param10, param11, layout}, {out1});
  // Phase 3, inputs and outputs
  model->identifyInputsAndOutputs(
    {in1, roi1},
    {out1});
  assert(model->isValid());
}

inline bool is_ignored_nhwc_float16_2(int i) {
  static std::set<int> ignore = {};
  return ignore.find(i) != ignore.end();
}

void CreateModel_nchw_2(Model *model) {
  OperandType type0(Type::BOOL, {});
  OperandType type28(Type::TENSOR_FLOAT32, {2, 2, 4, 8});
  OperandType type29(Type::TENSOR_FLOAT32, {4, 2, 2, 3});
  OperandType type4(Type::INT32, {});
  OperandType type5(Type::FLOAT32, {});
  OperandType type7(Type::TENSOR_FLOAT32, {4, 5});
  // Phase 1, operands
  auto in1 = model->addOperand(&type28);
  auto roi1 = model->addOperand(&type7);
  auto param6 = model->addOperand(&type4);
  auto param7 = model->addOperand(&type4);
  auto param8 = model->addOperand(&type5);
  auto param9 = model->addOperand(&type5);
  auto param10 = model->addOperand(&type4);
  auto param11 = model->addOperand(&type4);
  auto layout = model->addOperand(&type0);
  auto out1 = model->addOperand(&type29);
  // Phase 2, operations
  static int32_t param6_init[] = {2};
  model->setOperandValue(param6, param6_init, sizeof(int32_t) * 1);
  static int32_t param7_init[] = {3};
  model->setOperandValue(param7, param7_init, sizeof(int32_t) * 1);
  static float param8_init[] = {0.25f};
  model->setOperandValue(param8, param8_init, sizeof(float) * 1);
  static float param9_init[] = {0.25f};
  model->setOperandValue(param9, param9_init, sizeof(float) * 1);
  static int32_t param10_init[] = {4};
  model->setOperandValue(param10, param10_init, sizeof(int32_t) * 1);
  static int32_t param11_init[] = {4};
  model->setOperandValue(param11, param11_init, sizeof(int32_t) * 1);
  static bool8 layout_init[] = {true};
  model->setOperandValue(layout, layout_init, sizeof(bool8) * 1);
  model->addOperation(ANEURALNETWORKS_ROI_ALIGN, {in1, roi1, param6, param7, param8, param9, param10, param11, layout}, {out1});
  // Phase 3, inputs and outputs
  model->identifyInputsAndOutputs(
    {in1, roi1},
    {out1});
  assert(model->isValid());
}

inline bool is_ignored_nchw_2(int i) {
  static std::set<int> ignore = {};
  return ignore.find(i) != ignore.end();
}

void CreateModel_nchw_relaxed_2(Model *model) {
  OperandType type0(Type::BOOL, {});
  OperandType type28(Type::TENSOR_FLOAT32, {2, 2, 4, 8});
  OperandType type29(Type::TENSOR_FLOAT32, {4, 2, 2, 3});
  OperandType type4(Type::INT32, {});
  OperandType type5(Type::FLOAT32, {});
  OperandType type7(Type::TENSOR_FLOAT32, {4, 5});
  // Phase 1, operands
  auto in1 = model->addOperand(&type28);
  auto roi1 = model->addOperand(&type7);
  auto param6 = model->addOperand(&type4);
  auto param7 = model->addOperand(&type4);
  auto param8 = model->addOperand(&type5);
  auto param9 = model->addOperand(&type5);
  auto param10 = model->addOperand(&type4);
  auto param11 = model->addOperand(&type4);
  auto layout = model->addOperand(&type0);
  auto out1 = model->addOperand(&type29);
  // Phase 2, operations
  static int32_t param6_init[] = {2};
  model->setOperandValue(param6, param6_init, sizeof(int32_t) * 1);
  static int32_t param7_init[] = {3};
  model->setOperandValue(param7, param7_init, sizeof(int32_t) * 1);
  static float param8_init[] = {0.25f};
  model->setOperandValue(param8, param8_init, sizeof(float) * 1);
  static float param9_init[] = {0.25f};
  model->setOperandValue(param9, param9_init, sizeof(float) * 1);
  static int32_t param10_init[] = {4};
  model->setOperandValue(param10, param10_init, sizeof(int32_t) * 1);
  static int32_t param11_init[] = {4};
  model->setOperandValue(param11, param11_init, sizeof(int32_t) * 1);
  static bool8 layout_init[] = {true};
  model->setOperandValue(layout, layout_init, sizeof(bool8) * 1);
  model->addOperation(ANEURALNETWORKS_ROI_ALIGN, {in1, roi1, param6, param7, param8, param9, param10, param11, layout}, {out1});
  // Phase 3, inputs and outputs
  model->identifyInputsAndOutputs(
    {in1, roi1},
    {out1});
  // Phase 4: set relaxed execution
  model->relaxComputationFloat32toFloat16(true);
  assert(model->isValid());
}

inline bool is_ignored_nchw_relaxed_2(int i) {
  static std::set<int> ignore = {};
  return ignore.find(i) != ignore.end();
}

void CreateModel_nchw_quant8_2(Model *model) {
  OperandType type0(Type::BOOL, {});
  OperandType type30(Type::TENSOR_QUANT8_ASYMM, {2, 2, 4, 8}, 0.04f, 0);
  OperandType type31(Type::TENSOR_QUANT8_ASYMM, {4, 2, 2, 3}, 0.03125f, 10);
  OperandType type4(Type::INT32, {});
  OperandType type5(Type::FLOAT32, {});
  OperandType type7(Type::TENSOR_FLOAT32, {4, 5});
  // Phase 1, operands
  auto in1 = model->addOperand(&type30);
  auto roi1 = model->addOperand(&type7);
  auto param6 = model->addOperand(&type4);
  auto param7 = model->addOperand(&type4);
  auto param8 = model->addOperand(&type5);
  auto param9 = model->addOperand(&type5);
  auto param10 = model->addOperand(&type4);
  auto param11 = model->addOperand(&type4);
  auto layout = model->addOperand(&type0);
  auto out1 = model->addOperand(&type31);
  // Phase 2, operations
  static int32_t param6_init[] = {2};
  model->setOperandValue(param6, param6_init, sizeof(int32_t) * 1);
  static int32_t param7_init[] = {3};
  model->setOperandValue(param7, param7_init, sizeof(int32_t) * 1);
  static float param8_init[] = {0.25f};
  model->setOperandValue(param8, param8_init, sizeof(float) * 1);
  static float param9_init[] = {0.25f};
  model->setOperandValue(param9, param9_init, sizeof(float) * 1);
  static int32_t param10_init[] = {4};
  model->setOperandValue(param10, param10_init, sizeof(int32_t) * 1);
  static int32_t param11_init[] = {4};
  model->setOperandValue(param11, param11_init, sizeof(int32_t) * 1);
  static bool8 layout_init[] = {true};
  model->setOperandValue(layout, layout_init, sizeof(bool8) * 1);
  model->addOperation(ANEURALNETWORKS_ROI_ALIGN, {in1, roi1, param6, param7, param8, param9, param10, param11, layout}, {out1});
  // Phase 3, inputs and outputs
  model->identifyInputsAndOutputs(
    {in1, roi1},
    {out1});
  assert(model->isValid());
}

inline bool is_ignored_nchw_quant8_2(int i) {
  static std::set<int> ignore = {};
  return ignore.find(i) != ignore.end();
}

void CreateModel_nchw_float16_2(Model *model) {
  OperandType type0(Type::BOOL, {});
  OperandType type15(Type::FLOAT16, {});
  OperandType type27(Type::TENSOR_FLOAT16, {4, 5});
  OperandType type32(Type::TENSOR_FLOAT16, {2, 2, 4, 8});
  OperandType type33(Type::TENSOR_FLOAT16, {4, 2, 2, 3});
  OperandType type4(Type::INT32, {});
  // Phase 1, operands
  auto in1 = model->addOperand(&type32);
  auto roi1 = model->addOperand(&type27);
  auto param6 = model->addOperand(&type4);
  auto param7 = model->addOperand(&type4);
  auto param8 = model->addOperand(&type15);
  auto param9 = model->addOperand(&type15);
  auto param10 = model->addOperand(&type4);
  auto param11 = model->addOperand(&type4);
  auto layout = model->addOperand(&type0);
  auto out1 = model->addOperand(&type33);
  // Phase 2, operations
  static int32_t param6_init[] = {2};
  model->setOperandValue(param6, param6_init, sizeof(int32_t) * 1);
  static int32_t param7_init[] = {3};
  model->setOperandValue(param7, param7_init, sizeof(int32_t) * 1);
  static _Float16 param8_init[] = {0.25f};
  model->setOperandValue(param8, param8_init, sizeof(_Float16) * 1);
  static _Float16 param9_init[] = {0.25f};
  model->setOperandValue(param9, param9_init, sizeof(_Float16) * 1);
  static int32_t param10_init[] = {4};
  model->setOperandValue(param10, param10_init, sizeof(int32_t) * 1);
  static int32_t param11_init[] = {4};
  model->setOperandValue(param11, param11_init, sizeof(int32_t) * 1);
  static bool8 layout_init[] = {true};
  model->setOperandValue(layout, layout_init, sizeof(bool8) * 1);
  model->addOperation(ANEURALNETWORKS_ROI_ALIGN, {in1, roi1, param6, param7, param8, param9, param10, param11, layout}, {out1});
  // Phase 3, inputs and outputs
  model->identifyInputsAndOutputs(
    {in1, roi1},
    {out1});
  assert(model->isValid());
}

inline bool is_ignored_nchw_float16_2(int i) {
  static std::set<int> ignore = {};
  return ignore.find(i) != ignore.end();
}

void CreateModel_nhwc_3(Model *model) {
  OperandType type0(Type::BOOL, {});
  OperandType type4(Type::INT32, {});
  OperandType type5(Type::FLOAT32, {});
  OperandType type6(Type::TENSOR_FLOAT32, {2, 4, 8, 2});
  OperandType type7(Type::TENSOR_FLOAT32, {4, 5});
  OperandType type8(Type::TENSOR_FLOAT32, {4, 2, 3, 2});
  // Phase 1, operands
  auto in2 = model->addOperand(&type6);
  auto roi2 = model->addOperand(&type7);
  auto param12 = model->addOperand(&type4);
  auto param13 = model->addOperand(&type4);
  auto param14 = model->addOperand(&type5);
  auto param15 = model->addOperand(&type5);
  auto param16 = model->addOperand(&type4);
  auto param17 = model->addOperand(&type4);
  auto layout = model->addOperand(&type0);
  auto out2 = model->addOperand(&type8);
  // Phase 2, operations
  static int32_t param12_init[] = {2};
  model->setOperandValue(param12, param12_init, sizeof(int32_t) * 1);
  static int32_t param13_init[] = {3};
  model->setOperandValue(param13, param13_init, sizeof(int32_t) * 1);
  static float param14_init[] = {0.25f};
  model->setOperandValue(param14, param14_init, sizeof(float) * 1);
  static float param15_init[] = {0.25f};
  model->setOperandValue(param15, param15_init, sizeof(float) * 1);
  static int32_t param16_init[] = {0};
  model->setOperandValue(param16, param16_init, sizeof(int32_t) * 1);
  static int32_t param17_init[] = {0};
  model->setOperandValue(param17, param17_init, sizeof(int32_t) * 1);
  static bool8 layout_init[] = {false};
  model->setOperandValue(layout, layout_init, sizeof(bool8) * 1);
  model->addOperation(ANEURALNETWORKS_ROI_ALIGN, {in2, roi2, param12, param13, param14, param15, param16, param17, layout}, {out2});
  // Phase 3, inputs and outputs
  model->identifyInputsAndOutputs(
    {in2, roi2},
    {out2});
  assert(model->isValid());
}

inline bool is_ignored_nhwc_3(int i) {
  static std::set<int> ignore = {};
  return ignore.find(i) != ignore.end();
}

void CreateModel_nhwc_relaxed_3(Model *model) {
  OperandType type0(Type::BOOL, {});
  OperandType type4(Type::INT32, {});
  OperandType type5(Type::FLOAT32, {});
  OperandType type6(Type::TENSOR_FLOAT32, {2, 4, 8, 2});
  OperandType type7(Type::TENSOR_FLOAT32, {4, 5});
  OperandType type8(Type::TENSOR_FLOAT32, {4, 2, 3, 2});
  // Phase 1, operands
  auto in2 = model->addOperand(&type6);
  auto roi2 = model->addOperand(&type7);
  auto param12 = model->addOperand(&type4);
  auto param13 = model->addOperand(&type4);
  auto param14 = model->addOperand(&type5);
  auto param15 = model->addOperand(&type5);
  auto param16 = model->addOperand(&type4);
  auto param17 = model->addOperand(&type4);
  auto layout = model->addOperand(&type0);
  auto out2 = model->addOperand(&type8);
  // Phase 2, operations
  static int32_t param12_init[] = {2};
  model->setOperandValue(param12, param12_init, sizeof(int32_t) * 1);
  static int32_t param13_init[] = {3};
  model->setOperandValue(param13, param13_init, sizeof(int32_t) * 1);
  static float param14_init[] = {0.25f};
  model->setOperandValue(param14, param14_init, sizeof(float) * 1);
  static float param15_init[] = {0.25f};
  model->setOperandValue(param15, param15_init, sizeof(float) * 1);
  static int32_t param16_init[] = {0};
  model->setOperandValue(param16, param16_init, sizeof(int32_t) * 1);
  static int32_t param17_init[] = {0};
  model->setOperandValue(param17, param17_init, sizeof(int32_t) * 1);
  static bool8 layout_init[] = {false};
  model->setOperandValue(layout, layout_init, sizeof(bool8) * 1);
  model->addOperation(ANEURALNETWORKS_ROI_ALIGN, {in2, roi2, param12, param13, param14, param15, param16, param17, layout}, {out2});
  // Phase 3, inputs and outputs
  model->identifyInputsAndOutputs(
    {in2, roi2},
    {out2});
  // Phase 4: set relaxed execution
  model->relaxComputationFloat32toFloat16(true);
  assert(model->isValid());
}

inline bool is_ignored_nhwc_relaxed_3(int i) {
  static std::set<int> ignore = {};
  return ignore.find(i) != ignore.end();
}

void CreateModel_nhwc_quant8_3(Model *model) {
  OperandType type0(Type::BOOL, {});
  OperandType type23(Type::TENSOR_QUANT8_ASYMM, {2, 4, 8, 2}, 0.04f, 0);
  OperandType type24(Type::TENSOR_QUANT8_ASYMM, {4, 2, 3, 2}, 0.03125f, 10);
  OperandType type4(Type::INT32, {});
  OperandType type5(Type::FLOAT32, {});
  OperandType type7(Type::TENSOR_FLOAT32, {4, 5});
  // Phase 1, operands
  auto in2 = model->addOperand(&type23);
  auto roi2 = model->addOperand(&type7);
  auto param12 = model->addOperand(&type4);
  auto param13 = model->addOperand(&type4);
  auto param14 = model->addOperand(&type5);
  auto param15 = model->addOperand(&type5);
  auto param16 = model->addOperand(&type4);
  auto param17 = model->addOperand(&type4);
  auto layout = model->addOperand(&type0);
  auto out2 = model->addOperand(&type24);
  // Phase 2, operations
  static int32_t param12_init[] = {2};
  model->setOperandValue(param12, param12_init, sizeof(int32_t) * 1);
  static int32_t param13_init[] = {3};
  model->setOperandValue(param13, param13_init, sizeof(int32_t) * 1);
  static float param14_init[] = {0.25f};
  model->setOperandValue(param14, param14_init, sizeof(float) * 1);
  static float param15_init[] = {0.25f};
  model->setOperandValue(param15, param15_init, sizeof(float) * 1);
  static int32_t param16_init[] = {0};
  model->setOperandValue(param16, param16_init, sizeof(int32_t) * 1);
  static int32_t param17_init[] = {0};
  model->setOperandValue(param17, param17_init, sizeof(int32_t) * 1);
  static bool8 layout_init[] = {false};
  model->setOperandValue(layout, layout_init, sizeof(bool8) * 1);
  model->addOperation(ANEURALNETWORKS_ROI_ALIGN, {in2, roi2, param12, param13, param14, param15, param16, param17, layout}, {out2});
  // Phase 3, inputs and outputs
  model->identifyInputsAndOutputs(
    {in2, roi2},
    {out2});
  assert(model->isValid());
}

inline bool is_ignored_nhwc_quant8_3(int i) {
  static std::set<int> ignore = {};
  return ignore.find(i) != ignore.end();
}

void CreateModel_nhwc_float16_3(Model *model) {
  OperandType type0(Type::BOOL, {});
  OperandType type15(Type::FLOAT16, {});
  OperandType type25(Type::TENSOR_FLOAT16, {2, 4, 8, 2});
  OperandType type26(Type::TENSOR_FLOAT16, {4, 2, 3, 2});
  OperandType type27(Type::TENSOR_FLOAT16, {4, 5});
  OperandType type4(Type::INT32, {});
  // Phase 1, operands
  auto in2 = model->addOperand(&type25);
  auto roi2 = model->addOperand(&type27);
  auto param12 = model->addOperand(&type4);
  auto param13 = model->addOperand(&type4);
  auto param14 = model->addOperand(&type15);
  auto param15 = model->addOperand(&type15);
  auto param16 = model->addOperand(&type4);
  auto param17 = model->addOperand(&type4);
  auto layout = model->addOperand(&type0);
  auto out2 = model->addOperand(&type26);
  // Phase 2, operations
  static int32_t param12_init[] = {2};
  model->setOperandValue(param12, param12_init, sizeof(int32_t) * 1);
  static int32_t param13_init[] = {3};
  model->setOperandValue(param13, param13_init, sizeof(int32_t) * 1);
  static _Float16 param14_init[] = {0.25f};
  model->setOperandValue(param14, param14_init, sizeof(_Float16) * 1);
  static _Float16 param15_init[] = {0.25f};
  model->setOperandValue(param15, param15_init, sizeof(_Float16) * 1);
  static int32_t param16_init[] = {0};
  model->setOperandValue(param16, param16_init, sizeof(int32_t) * 1);
  static int32_t param17_init[] = {0};
  model->setOperandValue(param17, param17_init, sizeof(int32_t) * 1);
  static bool8 layout_init[] = {false};
  model->setOperandValue(layout, layout_init, sizeof(bool8) * 1);
  model->addOperation(ANEURALNETWORKS_ROI_ALIGN, {in2, roi2, param12, param13, param14, param15, param16, param17, layout}, {out2});
  // Phase 3, inputs and outputs
  model->identifyInputsAndOutputs(
    {in2, roi2},
    {out2});
  assert(model->isValid());
}

inline bool is_ignored_nhwc_float16_3(int i) {
  static std::set<int> ignore = {};
  return ignore.find(i) != ignore.end();
}

void CreateModel_nchw_3(Model *model) {
  OperandType type0(Type::BOOL, {});
  OperandType type28(Type::TENSOR_FLOAT32, {2, 2, 4, 8});
  OperandType type29(Type::TENSOR_FLOAT32, {4, 2, 2, 3});
  OperandType type4(Type::INT32, {});
  OperandType type5(Type::FLOAT32, {});
  OperandType type7(Type::TENSOR_FLOAT32, {4, 5});
  // Phase 1, operands
  auto in2 = model->addOperand(&type28);
  auto roi2 = model->addOperand(&type7);
  auto param12 = model->addOperand(&type4);
  auto param13 = model->addOperand(&type4);
  auto param14 = model->addOperand(&type5);
  auto param15 = model->addOperand(&type5);
  auto param16 = model->addOperand(&type4);
  auto param17 = model->addOperand(&type4);
  auto layout = model->addOperand(&type0);
  auto out2 = model->addOperand(&type29);
  // Phase 2, operations
  static int32_t param12_init[] = {2};
  model->setOperandValue(param12, param12_init, sizeof(int32_t) * 1);
  static int32_t param13_init[] = {3};
  model->setOperandValue(param13, param13_init, sizeof(int32_t) * 1);
  static float param14_init[] = {0.25f};
  model->setOperandValue(param14, param14_init, sizeof(float) * 1);
  static float param15_init[] = {0.25f};
  model->setOperandValue(param15, param15_init, sizeof(float) * 1);
  static int32_t param16_init[] = {0};
  model->setOperandValue(param16, param16_init, sizeof(int32_t) * 1);
  static int32_t param17_init[] = {0};
  model->setOperandValue(param17, param17_init, sizeof(int32_t) * 1);
  static bool8 layout_init[] = {true};
  model->setOperandValue(layout, layout_init, sizeof(bool8) * 1);
  model->addOperation(ANEURALNETWORKS_ROI_ALIGN, {in2, roi2, param12, param13, param14, param15, param16, param17, layout}, {out2});
  // Phase 3, inputs and outputs
  model->identifyInputsAndOutputs(
    {in2, roi2},
    {out2});
  assert(model->isValid());
}

inline bool is_ignored_nchw_3(int i) {
  static std::set<int> ignore = {};
  return ignore.find(i) != ignore.end();
}

void CreateModel_nchw_relaxed_3(Model *model) {
  OperandType type0(Type::BOOL, {});
  OperandType type28(Type::TENSOR_FLOAT32, {2, 2, 4, 8});
  OperandType type29(Type::TENSOR_FLOAT32, {4, 2, 2, 3});
  OperandType type4(Type::INT32, {});
  OperandType type5(Type::FLOAT32, {});
  OperandType type7(Type::TENSOR_FLOAT32, {4, 5});
  // Phase 1, operands
  auto in2 = model->addOperand(&type28);
  auto roi2 = model->addOperand(&type7);
  auto param12 = model->addOperand(&type4);
  auto param13 = model->addOperand(&type4);
  auto param14 = model->addOperand(&type5);
  auto param15 = model->addOperand(&type5);
  auto param16 = model->addOperand(&type4);
  auto param17 = model->addOperand(&type4);
  auto layout = model->addOperand(&type0);
  auto out2 = model->addOperand(&type29);
  // Phase 2, operations
  static int32_t param12_init[] = {2};
  model->setOperandValue(param12, param12_init, sizeof(int32_t) * 1);
  static int32_t param13_init[] = {3};
  model->setOperandValue(param13, param13_init, sizeof(int32_t) * 1);
  static float param14_init[] = {0.25f};
  model->setOperandValue(param14, param14_init, sizeof(float) * 1);
  static float param15_init[] = {0.25f};
  model->setOperandValue(param15, param15_init, sizeof(float) * 1);
  static int32_t param16_init[] = {0};
  model->setOperandValue(param16, param16_init, sizeof(int32_t) * 1);
  static int32_t param17_init[] = {0};
  model->setOperandValue(param17, param17_init, sizeof(int32_t) * 1);
  static bool8 layout_init[] = {true};
  model->setOperandValue(layout, layout_init, sizeof(bool8) * 1);
  model->addOperation(ANEURALNETWORKS_ROI_ALIGN, {in2, roi2, param12, param13, param14, param15, param16, param17, layout}, {out2});
  // Phase 3, inputs and outputs
  model->identifyInputsAndOutputs(
    {in2, roi2},
    {out2});
  // Phase 4: set relaxed execution
  model->relaxComputationFloat32toFloat16(true);
  assert(model->isValid());
}

inline bool is_ignored_nchw_relaxed_3(int i) {
  static std::set<int> ignore = {};
  return ignore.find(i) != ignore.end();
}

void CreateModel_nchw_quant8_3(Model *model) {
  OperandType type0(Type::BOOL, {});
  OperandType type30(Type::TENSOR_QUANT8_ASYMM, {2, 2, 4, 8}, 0.04f, 0);
  OperandType type31(Type::TENSOR_QUANT8_ASYMM, {4, 2, 2, 3}, 0.03125f, 10);
  OperandType type4(Type::INT32, {});
  OperandType type5(Type::FLOAT32, {});
  OperandType type7(Type::TENSOR_FLOAT32, {4, 5});
  // Phase 1, operands
  auto in2 = model->addOperand(&type30);
  auto roi2 = model->addOperand(&type7);
  auto param12 = model->addOperand(&type4);
  auto param13 = model->addOperand(&type4);
  auto param14 = model->addOperand(&type5);
  auto param15 = model->addOperand(&type5);
  auto param16 = model->addOperand(&type4);
  auto param17 = model->addOperand(&type4);
  auto layout = model->addOperand(&type0);
  auto out2 = model->addOperand(&type31);
  // Phase 2, operations
  static int32_t param12_init[] = {2};
  model->setOperandValue(param12, param12_init, sizeof(int32_t) * 1);
  static int32_t param13_init[] = {3};
  model->setOperandValue(param13, param13_init, sizeof(int32_t) * 1);
  static float param14_init[] = {0.25f};
  model->setOperandValue(param14, param14_init, sizeof(float) * 1);
  static float param15_init[] = {0.25f};
  model->setOperandValue(param15, param15_init, sizeof(float) * 1);
  static int32_t param16_init[] = {0};
  model->setOperandValue(param16, param16_init, sizeof(int32_t) * 1);
  static int32_t param17_init[] = {0};
  model->setOperandValue(param17, param17_init, sizeof(int32_t) * 1);
  static bool8 layout_init[] = {true};
  model->setOperandValue(layout, layout_init, sizeof(bool8) * 1);
  model->addOperation(ANEURALNETWORKS_ROI_ALIGN, {in2, roi2, param12, param13, param14, param15, param16, param17, layout}, {out2});
  // Phase 3, inputs and outputs
  model->identifyInputsAndOutputs(
    {in2, roi2},
    {out2});
  assert(model->isValid());
}

inline bool is_ignored_nchw_quant8_3(int i) {
  static std::set<int> ignore = {};
  return ignore.find(i) != ignore.end();
}

void CreateModel_nchw_float16_3(Model *model) {
  OperandType type0(Type::BOOL, {});
  OperandType type15(Type::FLOAT16, {});
  OperandType type27(Type::TENSOR_FLOAT16, {4, 5});
  OperandType type32(Type::TENSOR_FLOAT16, {2, 2, 4, 8});
  OperandType type33(Type::TENSOR_FLOAT16, {4, 2, 2, 3});
  OperandType type4(Type::INT32, {});
  // Phase 1, operands
  auto in2 = model->addOperand(&type32);
  auto roi2 = model->addOperand(&type27);
  auto param12 = model->addOperand(&type4);
  auto param13 = model->addOperand(&type4);
  auto param14 = model->addOperand(&type15);
  auto param15 = model->addOperand(&type15);
  auto param16 = model->addOperand(&type4);
  auto param17 = model->addOperand(&type4);
  auto layout = model->addOperand(&type0);
  auto out2 = model->addOperand(&type33);
  // Phase 2, operations
  static int32_t param12_init[] = {2};
  model->setOperandValue(param12, param12_init, sizeof(int32_t) * 1);
  static int32_t param13_init[] = {3};
  model->setOperandValue(param13, param13_init, sizeof(int32_t) * 1);
  static _Float16 param14_init[] = {0.25f};
  model->setOperandValue(param14, param14_init, sizeof(_Float16) * 1);
  static _Float16 param15_init[] = {0.25f};
  model->setOperandValue(param15, param15_init, sizeof(_Float16) * 1);
  static int32_t param16_init[] = {0};
  model->setOperandValue(param16, param16_init, sizeof(int32_t) * 1);
  static int32_t param17_init[] = {0};
  model->setOperandValue(param17, param17_init, sizeof(int32_t) * 1);
  static bool8 layout_init[] = {true};
  model->setOperandValue(layout, layout_init, sizeof(bool8) * 1);
  model->addOperation(ANEURALNETWORKS_ROI_ALIGN, {in2, roi2, param12, param13, param14, param15, param16, param17, layout}, {out2});
  // Phase 3, inputs and outputs
  model->identifyInputsAndOutputs(
    {in2, roi2},
    {out2});
  assert(model->isValid());
}

inline bool is_ignored_nchw_float16_3(int i) {
  static std::set<int> ignore = {};
  return ignore.find(i) != ignore.end();
}

void CreateModel_nhwc_4(Model *model) {
  OperandType type0(Type::BOOL, {});
  OperandType type1(Type::TENSOR_FLOAT32, {1, 4, 4, 1});
  OperandType type10(Type::TENSOR_FLOAT32, {5, 2, 2, 1});
  OperandType type4(Type::INT32, {});
  OperandType type5(Type::FLOAT32, {});
  OperandType type9(Type::TENSOR_FLOAT32, {5, 4});
  // Phase 1, operands
  auto in3 = model->addOperand(&type1);
  auto roi3 = model->addOperand(&type9);
  auto param18 = model->addOperand(&type4);
  auto param19 = model->addOperand(&type4);
  auto param20 = model->addOperand(&type5);
  auto param21 = model->addOperand(&type5);
  auto param22 = model->addOperand(&type4);
  auto param23 = model->addOperand(&type4);
  auto layout = model->addOperand(&type0);
  auto out3 = model->addOperand(&type10);
  // Phase 2, operations
  static int32_t param18_init[] = {2};
  model->setOperandValue(param18, param18_init, sizeof(int32_t) * 1);
  static int32_t param19_init[] = {2};
  model->setOperandValue(param19, param19_init, sizeof(int32_t) * 1);
  static float param20_init[] = {0.5f};
  model->setOperandValue(param20, param20_init, sizeof(float) * 1);
  static float param21_init[] = {1.0f};
  model->setOperandValue(param21, param21_init, sizeof(float) * 1);
  static int32_t param22_init[] = {0};
  model->setOperandValue(param22, param22_init, sizeof(int32_t) * 1);
  static int32_t param23_init[] = {4};
  model->setOperandValue(param23, param23_init, sizeof(int32_t) * 1);
  static bool8 layout_init[] = {false};
  model->setOperandValue(layout, layout_init, sizeof(bool8) * 1);
  model->addOperation(ANEURALNETWORKS_ROI_ALIGN, {in3, roi3, param18, param19, param20, param21, param22, param23, layout}, {out3});
  // Phase 3, inputs and outputs
  model->identifyInputsAndOutputs(
    {in3, roi3},
    {out3});
  assert(model->isValid());
}

inline bool is_ignored_nhwc_4(int i) {
  static std::set<int> ignore = {};
  return ignore.find(i) != ignore.end();
}

void CreateModel_nhwc_relaxed_4(Model *model) {
  OperandType type0(Type::BOOL, {});
  OperandType type1(Type::TENSOR_FLOAT32, {1, 4, 4, 1});
  OperandType type10(Type::TENSOR_FLOAT32, {5, 2, 2, 1});
  OperandType type4(Type::INT32, {});
  OperandType type5(Type::FLOAT32, {});
  OperandType type9(Type::TENSOR_FLOAT32, {5, 4});
  // Phase 1, operands
  auto in3 = model->addOperand(&type1);
  auto roi3 = model->addOperand(&type9);
  auto param18 = model->addOperand(&type4);
  auto param19 = model->addOperand(&type4);
  auto param20 = model->addOperand(&type5);
  auto param21 = model->addOperand(&type5);
  auto param22 = model->addOperand(&type4);
  auto param23 = model->addOperand(&type4);
  auto layout = model->addOperand(&type0);
  auto out3 = model->addOperand(&type10);
  // Phase 2, operations
  static int32_t param18_init[] = {2};
  model->setOperandValue(param18, param18_init, sizeof(int32_t) * 1);
  static int32_t param19_init[] = {2};
  model->setOperandValue(param19, param19_init, sizeof(int32_t) * 1);
  static float param20_init[] = {0.5f};
  model->setOperandValue(param20, param20_init, sizeof(float) * 1);
  static float param21_init[] = {1.0f};
  model->setOperandValue(param21, param21_init, sizeof(float) * 1);
  static int32_t param22_init[] = {0};
  model->setOperandValue(param22, param22_init, sizeof(int32_t) * 1);
  static int32_t param23_init[] = {4};
  model->setOperandValue(param23, param23_init, sizeof(int32_t) * 1);
  static bool8 layout_init[] = {false};
  model->setOperandValue(layout, layout_init, sizeof(bool8) * 1);
  model->addOperation(ANEURALNETWORKS_ROI_ALIGN, {in3, roi3, param18, param19, param20, param21, param22, param23, layout}, {out3});
  // Phase 3, inputs and outputs
  model->identifyInputsAndOutputs(
    {in3, roi3},
    {out3});
  // Phase 4: set relaxed execution
  model->relaxComputationFloat32toFloat16(true);
  assert(model->isValid());
}

inline bool is_ignored_nhwc_relaxed_4(int i) {
  static std::set<int> ignore = {};
  return ignore.find(i) != ignore.end();
}

void CreateModel_nhwc_quant8_4(Model *model) {
  OperandType type0(Type::BOOL, {});
  OperandType type11(Type::TENSOR_QUANT8_ASYMM, {1, 4, 4, 1}, 0.25f, 128);
  OperandType type34(Type::TENSOR_QUANT8_ASYMM, {5, 2, 2, 1}, 0.0625f, 128);
  OperandType type4(Type::INT32, {});
  OperandType type5(Type::FLOAT32, {});
  OperandType type9(Type::TENSOR_FLOAT32, {5, 4});
  // Phase 1, operands
  auto in3 = model->addOperand(&type11);
  auto roi3 = model->addOperand(&type9);
  auto param18 = model->addOperand(&type4);
  auto param19 = model->addOperand(&type4);
  auto param20 = model->addOperand(&type5);
  auto param21 = model->addOperand(&type5);
  auto param22 = model->addOperand(&type4);
  auto param23 = model->addOperand(&type4);
  auto layout = model->addOperand(&type0);
  auto out3 = model->addOperand(&type34);
  // Phase 2, operations
  static int32_t param18_init[] = {2};
  model->setOperandValue(param18, param18_init, sizeof(int32_t) * 1);
  static int32_t param19_init[] = {2};
  model->setOperandValue(param19, param19_init, sizeof(int32_t) * 1);
  static float param20_init[] = {0.5f};
  model->setOperandValue(param20, param20_init, sizeof(float) * 1);
  static float param21_init[] = {1.0f};
  model->setOperandValue(param21, param21_init, sizeof(float) * 1);
  static int32_t param22_init[] = {0};
  model->setOperandValue(param22, param22_init, sizeof(int32_t) * 1);
  static int32_t param23_init[] = {4};
  model->setOperandValue(param23, param23_init, sizeof(int32_t) * 1);
  static bool8 layout_init[] = {false};
  model->setOperandValue(layout, layout_init, sizeof(bool8) * 1);
  model->addOperation(ANEURALNETWORKS_ROI_ALIGN, {in3, roi3, param18, param19, param20, param21, param22, param23, layout}, {out3});
  // Phase 3, inputs and outputs
  model->identifyInputsAndOutputs(
    {in3, roi3},
    {out3});
  assert(model->isValid());
}

inline bool is_ignored_nhwc_quant8_4(int i) {
  static std::set<int> ignore = {};
  return ignore.find(i) != ignore.end();
}

void CreateModel_nhwc_float16_4(Model *model) {
  OperandType type0(Type::BOOL, {});
  OperandType type13(Type::TENSOR_FLOAT16, {1, 4, 4, 1});
  OperandType type15(Type::FLOAT16, {});
  OperandType type35(Type::TENSOR_FLOAT16, {5, 2, 2, 1});
  OperandType type36(Type::TENSOR_FLOAT16, {5, 4});
  OperandType type4(Type::INT32, {});
  // Phase 1, operands
  auto in3 = model->addOperand(&type13);
  auto roi3 = model->addOperand(&type36);
  auto param18 = model->addOperand(&type4);
  auto param19 = model->addOperand(&type4);
  auto param20 = model->addOperand(&type15);
  auto param21 = model->addOperand(&type15);
  auto param22 = model->addOperand(&type4);
  auto param23 = model->addOperand(&type4);
  auto layout = model->addOperand(&type0);
  auto out3 = model->addOperand(&type35);
  // Phase 2, operations
  static int32_t param18_init[] = {2};
  model->setOperandValue(param18, param18_init, sizeof(int32_t) * 1);
  static int32_t param19_init[] = {2};
  model->setOperandValue(param19, param19_init, sizeof(int32_t) * 1);
  static _Float16 param20_init[] = {0.5f};
  model->setOperandValue(param20, param20_init, sizeof(_Float16) * 1);
  static _Float16 param21_init[] = {1.0f};
  model->setOperandValue(param21, param21_init, sizeof(_Float16) * 1);
  static int32_t param22_init[] = {0};
  model->setOperandValue(param22, param22_init, sizeof(int32_t) * 1);
  static int32_t param23_init[] = {4};
  model->setOperandValue(param23, param23_init, sizeof(int32_t) * 1);
  static bool8 layout_init[] = {false};
  model->setOperandValue(layout, layout_init, sizeof(bool8) * 1);
  model->addOperation(ANEURALNETWORKS_ROI_ALIGN, {in3, roi3, param18, param19, param20, param21, param22, param23, layout}, {out3});
  // Phase 3, inputs and outputs
  model->identifyInputsAndOutputs(
    {in3, roi3},
    {out3});
  assert(model->isValid());
}

inline bool is_ignored_nhwc_float16_4(int i) {
  static std::set<int> ignore = {};
  return ignore.find(i) != ignore.end();
}

void CreateModel_nchw_4(Model *model) {
  OperandType type0(Type::BOOL, {});
  OperandType type17(Type::TENSOR_FLOAT32, {1, 1, 4, 4});
  OperandType type37(Type::TENSOR_FLOAT32, {5, 1, 2, 2});
  OperandType type4(Type::INT32, {});
  OperandType type5(Type::FLOAT32, {});
  OperandType type9(Type::TENSOR_FLOAT32, {5, 4});
  // Phase 1, operands
  auto in3 = model->addOperand(&type17);
  auto roi3 = model->addOperand(&type9);
  auto param18 = model->addOperand(&type4);
  auto param19 = model->addOperand(&type4);
  auto param20 = model->addOperand(&type5);
  auto param21 = model->addOperand(&type5);
  auto param22 = model->addOperand(&type4);
  auto param23 = model->addOperand(&type4);
  auto layout = model->addOperand(&type0);
  auto out3 = model->addOperand(&type37);
  // Phase 2, operations
  static int32_t param18_init[] = {2};
  model->setOperandValue(param18, param18_init, sizeof(int32_t) * 1);
  static int32_t param19_init[] = {2};
  model->setOperandValue(param19, param19_init, sizeof(int32_t) * 1);
  static float param20_init[] = {0.5f};
  model->setOperandValue(param20, param20_init, sizeof(float) * 1);
  static float param21_init[] = {1.0f};
  model->setOperandValue(param21, param21_init, sizeof(float) * 1);
  static int32_t param22_init[] = {0};
  model->setOperandValue(param22, param22_init, sizeof(int32_t) * 1);
  static int32_t param23_init[] = {4};
  model->setOperandValue(param23, param23_init, sizeof(int32_t) * 1);
  static bool8 layout_init[] = {true};
  model->setOperandValue(layout, layout_init, sizeof(bool8) * 1);
  model->addOperation(ANEURALNETWORKS_ROI_ALIGN, {in3, roi3, param18, param19, param20, param21, param22, param23, layout}, {out3});
  // Phase 3, inputs and outputs
  model->identifyInputsAndOutputs(
    {in3, roi3},
    {out3});
  assert(model->isValid());
}

inline bool is_ignored_nchw_4(int i) {
  static std::set<int> ignore = {};
  return ignore.find(i) != ignore.end();
}

void CreateModel_nchw_relaxed_4(Model *model) {
  OperandType type0(Type::BOOL, {});
  OperandType type17(Type::TENSOR_FLOAT32, {1, 1, 4, 4});
  OperandType type37(Type::TENSOR_FLOAT32, {5, 1, 2, 2});
  OperandType type4(Type::INT32, {});
  OperandType type5(Type::FLOAT32, {});
  OperandType type9(Type::TENSOR_FLOAT32, {5, 4});
  // Phase 1, operands
  auto in3 = model->addOperand(&type17);
  auto roi3 = model->addOperand(&type9);
  auto param18 = model->addOperand(&type4);
  auto param19 = model->addOperand(&type4);
  auto param20 = model->addOperand(&type5);
  auto param21 = model->addOperand(&type5);
  auto param22 = model->addOperand(&type4);
  auto param23 = model->addOperand(&type4);
  auto layout = model->addOperand(&type0);
  auto out3 = model->addOperand(&type37);
  // Phase 2, operations
  static int32_t param18_init[] = {2};
  model->setOperandValue(param18, param18_init, sizeof(int32_t) * 1);
  static int32_t param19_init[] = {2};
  model->setOperandValue(param19, param19_init, sizeof(int32_t) * 1);
  static float param20_init[] = {0.5f};
  model->setOperandValue(param20, param20_init, sizeof(float) * 1);
  static float param21_init[] = {1.0f};
  model->setOperandValue(param21, param21_init, sizeof(float) * 1);
  static int32_t param22_init[] = {0};
  model->setOperandValue(param22, param22_init, sizeof(int32_t) * 1);
  static int32_t param23_init[] = {4};
  model->setOperandValue(param23, param23_init, sizeof(int32_t) * 1);
  static bool8 layout_init[] = {true};
  model->setOperandValue(layout, layout_init, sizeof(bool8) * 1);
  model->addOperation(ANEURALNETWORKS_ROI_ALIGN, {in3, roi3, param18, param19, param20, param21, param22, param23, layout}, {out3});
  // Phase 3, inputs and outputs
  model->identifyInputsAndOutputs(
    {in3, roi3},
    {out3});
  // Phase 4: set relaxed execution
  model->relaxComputationFloat32toFloat16(true);
  assert(model->isValid());
}

inline bool is_ignored_nchw_relaxed_4(int i) {
  static std::set<int> ignore = {};
  return ignore.find(i) != ignore.end();
}

void CreateModel_nchw_quant8_4(Model *model) {
  OperandType type0(Type::BOOL, {});
  OperandType type19(Type::TENSOR_QUANT8_ASYMM, {1, 1, 4, 4}, 0.25f, 128);
  OperandType type38(Type::TENSOR_QUANT8_ASYMM, {5, 1, 2, 2}, 0.0625f, 128);
  OperandType type4(Type::INT32, {});
  OperandType type5(Type::FLOAT32, {});
  OperandType type9(Type::TENSOR_FLOAT32, {5, 4});
  // Phase 1, operands
  auto in3 = model->addOperand(&type19);
  auto roi3 = model->addOperand(&type9);
  auto param18 = model->addOperand(&type4);
  auto param19 = model->addOperand(&type4);
  auto param20 = model->addOperand(&type5);
  auto param21 = model->addOperand(&type5);
  auto param22 = model->addOperand(&type4);
  auto param23 = model->addOperand(&type4);
  auto layout = model->addOperand(&type0);
  auto out3 = model->addOperand(&type38);
  // Phase 2, operations
  static int32_t param18_init[] = {2};
  model->setOperandValue(param18, param18_init, sizeof(int32_t) * 1);
  static int32_t param19_init[] = {2};
  model->setOperandValue(param19, param19_init, sizeof(int32_t) * 1);
  static float param20_init[] = {0.5f};
  model->setOperandValue(param20, param20_init, sizeof(float) * 1);
  static float param21_init[] = {1.0f};
  model->setOperandValue(param21, param21_init, sizeof(float) * 1);
  static int32_t param22_init[] = {0};
  model->setOperandValue(param22, param22_init, sizeof(int32_t) * 1);
  static int32_t param23_init[] = {4};
  model->setOperandValue(param23, param23_init, sizeof(int32_t) * 1);
  static bool8 layout_init[] = {true};
  model->setOperandValue(layout, layout_init, sizeof(bool8) * 1);
  model->addOperation(ANEURALNETWORKS_ROI_ALIGN, {in3, roi3, param18, param19, param20, param21, param22, param23, layout}, {out3});
  // Phase 3, inputs and outputs
  model->identifyInputsAndOutputs(
    {in3, roi3},
    {out3});
  assert(model->isValid());
}

inline bool is_ignored_nchw_quant8_4(int i) {
  static std::set<int> ignore = {};
  return ignore.find(i) != ignore.end();
}

void CreateModel_nchw_float16_4(Model *model) {
  OperandType type0(Type::BOOL, {});
  OperandType type15(Type::FLOAT16, {});
  OperandType type21(Type::TENSOR_FLOAT16, {1, 1, 4, 4});
  OperandType type36(Type::TENSOR_FLOAT16, {5, 4});
  OperandType type39(Type::TENSOR_FLOAT16, {5, 1, 2, 2});
  OperandType type4(Type::INT32, {});
  // Phase 1, operands
  auto in3 = model->addOperand(&type21);
  auto roi3 = model->addOperand(&type36);
  auto param18 = model->addOperand(&type4);
  auto param19 = model->addOperand(&type4);
  auto param20 = model->addOperand(&type15);
  auto param21 = model->addOperand(&type15);
  auto param22 = model->addOperand(&type4);
  auto param23 = model->addOperand(&type4);
  auto layout = model->addOperand(&type0);
  auto out3 = model->addOperand(&type39);
  // Phase 2, operations
  static int32_t param18_init[] = {2};
  model->setOperandValue(param18, param18_init, sizeof(int32_t) * 1);
  static int32_t param19_init[] = {2};
  model->setOperandValue(param19, param19_init, sizeof(int32_t) * 1);
  static _Float16 param20_init[] = {0.5f};
  model->setOperandValue(param20, param20_init, sizeof(_Float16) * 1);
  static _Float16 param21_init[] = {1.0f};
  model->setOperandValue(param21, param21_init, sizeof(_Float16) * 1);
  static int32_t param22_init[] = {0};
  model->setOperandValue(param22, param22_init, sizeof(int32_t) * 1);
  static int32_t param23_init[] = {4};
  model->setOperandValue(param23, param23_init, sizeof(int32_t) * 1);
  static bool8 layout_init[] = {true};
  model->setOperandValue(layout, layout_init, sizeof(bool8) * 1);
  model->addOperation(ANEURALNETWORKS_ROI_ALIGN, {in3, roi3, param18, param19, param20, param21, param22, param23, layout}, {out3});
  // Phase 3, inputs and outputs
  model->identifyInputsAndOutputs(
    {in3, roi3},
    {out3});
  assert(model->isValid());
}

inline bool is_ignored_nchw_float16_4(int i) {
  static std::set<int> ignore = {};
  return ignore.find(i) != ignore.end();
}

