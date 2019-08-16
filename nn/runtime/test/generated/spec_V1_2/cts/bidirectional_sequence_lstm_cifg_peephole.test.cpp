// Generated from bidirectional_sequence_lstm_cifg_peephole.mod.py
// DO NOT EDIT
// clang-format off
#include "TestGenerated.h"

namespace generated_tests::bidirectional_sequence_lstm_cifg_peephole {

void CreateModel(Model *model);
bool is_ignored(int);
std::vector<::test_helper::MixedTypedExample>& get_examples_blackbox();

TEST_F(GeneratedTests, bidirectional_sequence_lstm_cifg_peephole_blackbox) {
    execute(CreateModel,
            is_ignored,
            get_examples_blackbox());
}

} // namespace generated_tests::bidirectional_sequence_lstm_cifg_peephole
TEST_AVAILABLE_SINCE(V1_2, bidirectional_sequence_lstm_cifg_peephole_blackbox, generated_tests::bidirectional_sequence_lstm_cifg_peephole::CreateModel)

namespace generated_tests::bidirectional_sequence_lstm_cifg_peephole {

void CreateModel_dynamic_output_shape(Model *model);
bool is_ignored_dynamic_output_shape(int);
std::vector<::test_helper::MixedTypedExample>& get_examples_blackbox_dynamic_output_shape();

TEST_F(DynamicOutputShapeTest, bidirectional_sequence_lstm_cifg_peephole_blackbox_dynamic_output_shape) {
    execute(CreateModel_dynamic_output_shape,
            is_ignored_dynamic_output_shape,
            get_examples_blackbox_dynamic_output_shape());
}

} // namespace generated_tests::bidirectional_sequence_lstm_cifg_peephole

namespace generated_tests::bidirectional_sequence_lstm_cifg_peephole {

void CreateModel_all_inputs_as_internal(Model *model);
bool is_ignored_all_inputs_as_internal(int);
std::vector<::test_helper::MixedTypedExample>& get_examples_blackbox_all_inputs_as_internal();

TEST_F(GeneratedTests, bidirectional_sequence_lstm_cifg_peephole_blackbox_all_inputs_as_internal) {
    execute(CreateModel_all_inputs_as_internal,
            is_ignored_all_inputs_as_internal,
            get_examples_blackbox_all_inputs_as_internal());
}

} // namespace generated_tests::bidirectional_sequence_lstm_cifg_peephole
TEST_AVAILABLE_SINCE(V1_2, bidirectional_sequence_lstm_cifg_peephole_blackbox_all_inputs_as_internal, generated_tests::bidirectional_sequence_lstm_cifg_peephole::CreateModel_all_inputs_as_internal)

namespace generated_tests::bidirectional_sequence_lstm_cifg_peephole {

void CreateModel_all_inputs_as_internal_dynamic_output_shape(Model *model);
bool is_ignored_all_inputs_as_internal_dynamic_output_shape(int);
std::vector<::test_helper::MixedTypedExample>& get_examples_blackbox_all_inputs_as_internal_dynamic_output_shape();

TEST_F(DynamicOutputShapeTest, bidirectional_sequence_lstm_cifg_peephole_blackbox_all_inputs_as_internal_dynamic_output_shape) {
    execute(CreateModel_all_inputs_as_internal_dynamic_output_shape,
            is_ignored_all_inputs_as_internal_dynamic_output_shape,
            get_examples_blackbox_all_inputs_as_internal_dynamic_output_shape());
}

} // namespace generated_tests::bidirectional_sequence_lstm_cifg_peephole
