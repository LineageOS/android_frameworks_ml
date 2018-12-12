// clang-format off
// DO NOT EDIT;
// Generated by ml/nn/runtime/test/specs/generate_test.sh
#include "../GeneratedUtils.cpp"
#include "../generated/tests/add.mod.py.cpp"
#include "../generated/tests/add_broadcast_quant8.mod.py.cpp"
#include "../generated/tests/add_quant8.mod.py.cpp"
#include "../generated/tests/avg_pool_float_1.mod.py.cpp"
#include "../generated/tests/avg_pool_float_2.mod.py.cpp"
#include "../generated/tests/avg_pool_float_3.mod.py.cpp"
#include "../generated/tests/avg_pool_float_4.mod.py.cpp"
#include "../generated/tests/avg_pool_float_5.mod.py.cpp"
#include "../generated/tests/avg_pool_quant8_1.mod.py.cpp"
#include "../generated/tests/avg_pool_quant8_2.mod.py.cpp"
#include "../generated/tests/avg_pool_quant8_3.mod.py.cpp"
#include "../generated/tests/avg_pool_quant8_4.mod.py.cpp"
#include "../generated/tests/avg_pool_quant8_5.mod.py.cpp"
#include "../generated/tests/concat_float_1.mod.py.cpp"
#include "../generated/tests/concat_float_2.mod.py.cpp"
#include "../generated/tests/concat_float_3.mod.py.cpp"
#include "../generated/tests/concat_quant8_1.mod.py.cpp"
#include "../generated/tests/concat_quant8_2.mod.py.cpp"
#include "../generated/tests/concat_quant8_3.mod.py.cpp"
#include "../generated/tests/conv_1_h3_w2_SAME.mod.py.cpp"
#include "../generated/tests/conv_1_h3_w2_VALID.mod.py.cpp"
#include "../generated/tests/conv_3_h3_w2_SAME.mod.py.cpp"
#include "../generated/tests/conv_3_h3_w2_VALID.mod.py.cpp"
#include "../generated/tests/conv_float.mod.py.cpp"
#include "../generated/tests/conv_float_2.mod.py.cpp"
#include "../generated/tests/conv_float_channels.mod.py.cpp"
#include "../generated/tests/conv_float_channels_weights_as_inputs.mod.py.cpp"
#include "../generated/tests/conv_float_large.mod.py.cpp"
#include "../generated/tests/conv_float_large_weights_as_inputs.mod.py.cpp"
#include "../generated/tests/conv_float_weights_as_inputs.mod.py.cpp"
#include "../generated/tests/conv_quant8.mod.py.cpp"
#include "../generated/tests/conv_quant8_2.mod.py.cpp"
#include "../generated/tests/conv_quant8_channels.mod.py.cpp"
#include "../generated/tests/conv_quant8_channels_weights_as_inputs.mod.py.cpp"
#include "../generated/tests/conv_quant8_large.mod.py.cpp"
#include "../generated/tests/conv_quant8_large_weights_as_inputs.mod.py.cpp"
#include "../generated/tests/conv_quant8_overflow.mod.py.cpp"
#include "../generated/tests/conv_quant8_overflow_weights_as_inputs.mod.py.cpp"
#include "../generated/tests/conv_quant8_weights_as_inputs.mod.py.cpp"
#include "../generated/tests/depth_to_space_float_1.mod.py.cpp"
#include "../generated/tests/depth_to_space_float_2.mod.py.cpp"
#include "../generated/tests/depth_to_space_float_3.mod.py.cpp"
#include "../generated/tests/depth_to_space_quant8_1.mod.py.cpp"
#include "../generated/tests/depth_to_space_quant8_2.mod.py.cpp"
#include "../generated/tests/depthwise_conv.mod.py.cpp"
#include "../generated/tests/depthwise_conv2d_float.mod.py.cpp"
#include "../generated/tests/depthwise_conv2d_float_2.mod.py.cpp"
#include "../generated/tests/depthwise_conv2d_float_large.mod.py.cpp"
#include "../generated/tests/depthwise_conv2d_float_large_2.mod.py.cpp"
#include "../generated/tests/depthwise_conv2d_float_large_2_weights_as_inputs.mod.py.cpp"
#include "../generated/tests/depthwise_conv2d_float_large_weights_as_inputs.mod.py.cpp"
#include "../generated/tests/depthwise_conv2d_float_weights_as_inputs.mod.py.cpp"
#include "../generated/tests/depthwise_conv2d_quant8.mod.py.cpp"
#include "../generated/tests/depthwise_conv2d_quant8_2.mod.py.cpp"
#include "../generated/tests/depthwise_conv2d_quant8_large.mod.py.cpp"
#include "../generated/tests/depthwise_conv2d_quant8_large_weights_as_inputs.mod.py.cpp"
#include "../generated/tests/depthwise_conv2d_quant8_weights_as_inputs.mod.py.cpp"
#include "../generated/tests/dequantize.mod.py.cpp"
#include "../generated/tests/embedding_lookup.mod.py.cpp"
#include "../generated/tests/floor.mod.py.cpp"
#include "../generated/tests/fully_connected_float.mod.py.cpp"
#include "../generated/tests/fully_connected_float_2.mod.py.cpp"
#include "../generated/tests/fully_connected_float_3.mod.py.cpp"
#include "../generated/tests/fully_connected_float_large.mod.py.cpp"
#include "../generated/tests/fully_connected_float_large_weights_as_inputs.mod.py.cpp"
#include "../generated/tests/fully_connected_float_weights_as_inputs.mod.py.cpp"
#include "../generated/tests/fully_connected_quant8.mod.py.cpp"
#include "../generated/tests/fully_connected_quant8_2.mod.py.cpp"
#include "../generated/tests/fully_connected_quant8_large.mod.py.cpp"
#include "../generated/tests/fully_connected_quant8_large_weights_as_inputs.mod.py.cpp"
#include "../generated/tests/fully_connected_quant8_weights_as_inputs.mod.py.cpp"
#include "../generated/tests/hashtable_lookup_float.mod.py.cpp"
#include "../generated/tests/hashtable_lookup_quant8.mod.py.cpp"
#include "../generated/tests/l2_normalization.mod.py.cpp"
#include "../generated/tests/l2_normalization_2.mod.py.cpp"
#include "../generated/tests/l2_normalization_large.mod.py.cpp"
#include "../generated/tests/l2_pool_float.mod.py.cpp"
#include "../generated/tests/l2_pool_float_2.mod.py.cpp"
#include "../generated/tests/l2_pool_float_large.mod.py.cpp"
#include "../generated/tests/local_response_norm_float_1.mod.py.cpp"
#include "../generated/tests/local_response_norm_float_2.mod.py.cpp"
#include "../generated/tests/local_response_norm_float_3.mod.py.cpp"
#include "../generated/tests/local_response_norm_float_4.mod.py.cpp"
#include "../generated/tests/logistic_float_1.mod.py.cpp"
#include "../generated/tests/logistic_float_2.mod.py.cpp"
#include "../generated/tests/logistic_quant8_1.mod.py.cpp"
#include "../generated/tests/logistic_quant8_2.mod.py.cpp"
#include "../generated/tests/lsh_projection.mod.py.cpp"
#include "../generated/tests/lsh_projection_2.mod.py.cpp"
#include "../generated/tests/lsh_projection_weights_as_inputs.mod.py.cpp"
#include "../generated/tests/lstm.mod.py.cpp"
#include "../generated/tests/lstm2.mod.py.cpp"
#include "../generated/tests/lstm2_state.mod.py.cpp"
#include "../generated/tests/lstm2_state2.mod.py.cpp"
#include "../generated/tests/lstm3.mod.py.cpp"
#include "../generated/tests/lstm3_state.mod.py.cpp"
#include "../generated/tests/lstm3_state2.mod.py.cpp"
#include "../generated/tests/lstm3_state3.mod.py.cpp"
#include "../generated/tests/lstm_state.mod.py.cpp"
#include "../generated/tests/lstm_state2.mod.py.cpp"
#include "../generated/tests/max_pool_float_1.mod.py.cpp"
#include "../generated/tests/max_pool_float_2.mod.py.cpp"
#include "../generated/tests/max_pool_float_3.mod.py.cpp"
#include "../generated/tests/max_pool_float_4.mod.py.cpp"
#include "../generated/tests/max_pool_quant8_1.mod.py.cpp"
#include "../generated/tests/max_pool_quant8_2.mod.py.cpp"
#include "../generated/tests/max_pool_quant8_3.mod.py.cpp"
#include "../generated/tests/max_pool_quant8_4.mod.py.cpp"
#include "../generated/tests/mobilenet_224_gender_basic_fixed.mod.py.cpp"
#include "../generated/tests/mobilenet_quantized.mod.py.cpp"
#include "../generated/tests/mul.mod.py.cpp"
#include "../generated/tests/mul_broadcast_quant8.mod.py.cpp"
#include "../generated/tests/mul_quant8.mod.py.cpp"
#include "../generated/tests/mul_relu.mod.py.cpp"
#include "../generated/tests/relu1_float_1.mod.py.cpp"
#include "../generated/tests/relu1_float_2.mod.py.cpp"
#include "../generated/tests/relu1_quant8_1.mod.py.cpp"
#include "../generated/tests/relu1_quant8_2.mod.py.cpp"
#include "../generated/tests/relu6_float_1.mod.py.cpp"
#include "../generated/tests/relu6_float_2.mod.py.cpp"
#include "../generated/tests/relu6_quant8_1.mod.py.cpp"
#include "../generated/tests/relu6_quant8_2.mod.py.cpp"
#include "../generated/tests/relu_float_1.mod.py.cpp"
#include "../generated/tests/relu_float_2.mod.py.cpp"
#include "../generated/tests/relu_quant8_1.mod.py.cpp"
#include "../generated/tests/relu_quant8_2.mod.py.cpp"
#include "../generated/tests/reshape.mod.py.cpp"
#include "../generated/tests/reshape_quant8.mod.py.cpp"
#include "../generated/tests/reshape_quant8_weights_as_inputs.mod.py.cpp"
#include "../generated/tests/reshape_weights_as_inputs.mod.py.cpp"
#include "../generated/tests/resize_bilinear.mod.py.cpp"
#include "../generated/tests/resize_bilinear_2.mod.py.cpp"
#include "../generated/tests/rnn.mod.py.cpp"
#include "../generated/tests/rnn_state.mod.py.cpp"
#include "../generated/tests/softmax_float_1.mod.py.cpp"
#include "../generated/tests/softmax_float_2.mod.py.cpp"
#include "../generated/tests/softmax_quant8_1.mod.py.cpp"
#include "../generated/tests/softmax_quant8_2.mod.py.cpp"
#include "../generated/tests/space_to_depth_float_1.mod.py.cpp"
#include "../generated/tests/space_to_depth_float_2.mod.py.cpp"
#include "../generated/tests/space_to_depth_float_3.mod.py.cpp"
#include "../generated/tests/space_to_depth_quant8_1.mod.py.cpp"
#include "../generated/tests/space_to_depth_quant8_2.mod.py.cpp"
#include "../generated/tests/svdf.mod.py.cpp"
#include "../generated/tests/svdf2.mod.py.cpp"
#include "../generated/tests/svdf_state.mod.py.cpp"
#include "../generated/tests/tanh.mod.py.cpp"
#include "../generated/tests/add_relaxed.mod.py.cpp"
#include "../generated/tests/avg_pool_float_1_relaxed.mod.py.cpp"
#include "../generated/tests/avg_pool_float_2_relaxed.mod.py.cpp"
#include "../generated/tests/avg_pool_float_3_relaxed.mod.py.cpp"
#include "../generated/tests/avg_pool_float_4_relaxed.mod.py.cpp"
#include "../generated/tests/avg_pool_float_5_relaxed.mod.py.cpp"
#include "../generated/tests/batch_to_space.mod.py.cpp"
#include "../generated/tests/batch_to_space_float_1.mod.py.cpp"
#include "../generated/tests/batch_to_space_float_1_relaxed.mod.py.cpp"
#include "../generated/tests/batch_to_space_quant8_1.mod.py.cpp"
#include "../generated/tests/batch_to_space_relaxed.mod.py.cpp"
#include "../generated/tests/concat_float_1_relaxed.mod.py.cpp"
#include "../generated/tests/concat_float_2_relaxed.mod.py.cpp"
#include "../generated/tests/concat_float_3_relaxed.mod.py.cpp"
#include "../generated/tests/conv_1_h3_w2_SAME_relaxed.mod.py.cpp"
#include "../generated/tests/conv_1_h3_w2_VALID_relaxed.mod.py.cpp"
#include "../generated/tests/conv_3_h3_w2_SAME_relaxed.mod.py.cpp"
#include "../generated/tests/conv_3_h3_w2_VALID_relaxed.mod.py.cpp"
#include "../generated/tests/conv_float_2_relaxed.mod.py.cpp"
#include "../generated/tests/conv_float_channels_relaxed.mod.py.cpp"
#include "../generated/tests/conv_float_channels_weights_as_inputs_relaxed.mod.py.cpp"
#include "../generated/tests/conv_float_large_relaxed.mod.py.cpp"
#include "../generated/tests/conv_float_large_weights_as_inputs_relaxed.mod.py.cpp"
#include "../generated/tests/conv_float_relaxed.mod.py.cpp"
#include "../generated/tests/conv_float_weights_as_inputs_relaxed.mod.py.cpp"
#include "../generated/tests/depth_to_space_float_1_relaxed.mod.py.cpp"
#include "../generated/tests/depth_to_space_float_2_relaxed.mod.py.cpp"
#include "../generated/tests/depth_to_space_float_3_relaxed.mod.py.cpp"
#include "../generated/tests/depthwise_conv2d_float_2_relaxed.mod.py.cpp"
#include "../generated/tests/depthwise_conv2d_float_large_2_relaxed.mod.py.cpp"
#include "../generated/tests/depthwise_conv2d_float_large_2_weights_as_inputs_relaxed.mod.py.cpp"
#include "../generated/tests/depthwise_conv2d_float_large_relaxed.mod.py.cpp"
#include "../generated/tests/depthwise_conv2d_float_large_weights_as_inputs_relaxed.mod.py.cpp"
#include "../generated/tests/depthwise_conv2d_float_relaxed.mod.py.cpp"
#include "../generated/tests/depthwise_conv2d_float_weights_as_inputs_relaxed.mod.py.cpp"
#include "../generated/tests/depthwise_conv_relaxed.mod.py.cpp"
#include "../generated/tests/dequantize_relaxed.mod.py.cpp"
#include "../generated/tests/div.mod.py.cpp"
#include "../generated/tests/div_broadcast_float.mod.py.cpp"
#include "../generated/tests/div_broadcast_float_relaxed.mod.py.cpp"
#include "../generated/tests/div_relaxed.mod.py.cpp"
#include "../generated/tests/embedding_lookup_relaxed.mod.py.cpp"
#include "../generated/tests/floor_relaxed.mod.py.cpp"
#include "../generated/tests/fully_connected_float_2_relaxed.mod.py.cpp"
#include "../generated/tests/fully_connected_float_4d_simple.mod.py.cpp"
#include "../generated/tests/fully_connected_float_4d_simple_relaxed.mod.py.cpp"
#include "../generated/tests/fully_connected_float_large_relaxed.mod.py.cpp"
#include "../generated/tests/fully_connected_float_large_weights_as_inputs_relaxed.mod.py.cpp"
#include "../generated/tests/fully_connected_float_relaxed.mod.py.cpp"
#include "../generated/tests/fully_connected_float_weights_as_inputs_relaxed.mod.py.cpp"
#include "../generated/tests/hashtable_lookup_float_relaxed.mod.py.cpp"
#include "../generated/tests/l2_normalization_2_relaxed.mod.py.cpp"
#include "../generated/tests/l2_normalization_large_relaxed.mod.py.cpp"
#include "../generated/tests/l2_normalization_relaxed.mod.py.cpp"
#include "../generated/tests/l2_pool_float_2_relaxed.mod.py.cpp"
#include "../generated/tests/l2_pool_float_large_relaxed.mod.py.cpp"
#include "../generated/tests/l2_pool_float_relaxed.mod.py.cpp"
#include "../generated/tests/local_response_norm_float_1_relaxed.mod.py.cpp"
#include "../generated/tests/local_response_norm_float_2_relaxed.mod.py.cpp"
#include "../generated/tests/local_response_norm_float_3_relaxed.mod.py.cpp"
#include "../generated/tests/local_response_norm_float_4_relaxed.mod.py.cpp"
#include "../generated/tests/logistic_float_1_relaxed.mod.py.cpp"
#include "../generated/tests/logistic_float_2_relaxed.mod.py.cpp"
#include "../generated/tests/lsh_projection_2_relaxed.mod.py.cpp"
#include "../generated/tests/lsh_projection_relaxed.mod.py.cpp"
#include "../generated/tests/lsh_projection_weights_as_inputs_relaxed.mod.py.cpp"
#include "../generated/tests/lstm2_relaxed.mod.py.cpp"
#include "../generated/tests/lstm2_state2_relaxed.mod.py.cpp"
#include "../generated/tests/lstm2_state_relaxed.mod.py.cpp"
#include "../generated/tests/lstm3_relaxed.mod.py.cpp"
#include "../generated/tests/lstm3_state2_relaxed.mod.py.cpp"
#include "../generated/tests/lstm3_state3_relaxed.mod.py.cpp"
#include "../generated/tests/lstm3_state_relaxed.mod.py.cpp"
#include "../generated/tests/lstm_relaxed.mod.py.cpp"
#include "../generated/tests/lstm_state2_relaxed.mod.py.cpp"
#include "../generated/tests/lstm_state_relaxed.mod.py.cpp"
#include "../generated/tests/max_pool_float_1_relaxed.mod.py.cpp"
#include "../generated/tests/max_pool_float_2_relaxed.mod.py.cpp"
#include "../generated/tests/max_pool_float_3_relaxed.mod.py.cpp"
#include "../generated/tests/max_pool_float_4_relaxed.mod.py.cpp"
#include "../generated/tests/mean.mod.py.cpp"
#include "../generated/tests/mean_float_1.mod.py.cpp"
#include "../generated/tests/mean_float_1_relaxed.mod.py.cpp"
#include "../generated/tests/mean_float_2.mod.py.cpp"
#include "../generated/tests/mean_float_2_relaxed.mod.py.cpp"
#include "../generated/tests/mean_quant8_1.mod.py.cpp"
#include "../generated/tests/mean_quant8_2.mod.py.cpp"
#include "../generated/tests/mean_relaxed.mod.py.cpp"
#include "../generated/tests/mobilenet_224_gender_basic_fixed_relaxed.mod.py.cpp"
#include "../generated/tests/mul_relaxed.mod.py.cpp"
#include "../generated/tests/mul_relu_relaxed.mod.py.cpp"
#include "../generated/tests/pad.mod.py.cpp"
#include "../generated/tests/pad_float_1.mod.py.cpp"
#include "../generated/tests/pad_float_1_relaxed.mod.py.cpp"
#include "../generated/tests/pad_relaxed.mod.py.cpp"
#include "../generated/tests/relu1_float_1_relaxed.mod.py.cpp"
#include "../generated/tests/relu1_float_2_relaxed.mod.py.cpp"
#include "../generated/tests/relu6_float_1_relaxed.mod.py.cpp"
#include "../generated/tests/relu6_float_2_relaxed.mod.py.cpp"
#include "../generated/tests/relu_float_1_relaxed.mod.py.cpp"
#include "../generated/tests/relu_float_2_relaxed.mod.py.cpp"
#include "../generated/tests/reshape_relaxed.mod.py.cpp"
#include "../generated/tests/reshape_weights_as_inputs_relaxed.mod.py.cpp"
#include "../generated/tests/resize_bilinear_2_relaxed.mod.py.cpp"
#include "../generated/tests/resize_bilinear_relaxed.mod.py.cpp"
#include "../generated/tests/rnn_relaxed.mod.py.cpp"
#include "../generated/tests/rnn_state_relaxed.mod.py.cpp"
#include "../generated/tests/softmax_float_1_relaxed.mod.py.cpp"
#include "../generated/tests/softmax_float_2_relaxed.mod.py.cpp"
#include "../generated/tests/space_to_batch.mod.py.cpp"
#include "../generated/tests/space_to_batch_float_1.mod.py.cpp"
#include "../generated/tests/space_to_batch_float_1_relaxed.mod.py.cpp"
#include "../generated/tests/space_to_batch_float_2.mod.py.cpp"
#include "../generated/tests/space_to_batch_float_2_relaxed.mod.py.cpp"
#include "../generated/tests/space_to_batch_float_3.mod.py.cpp"
#include "../generated/tests/space_to_batch_float_3_relaxed.mod.py.cpp"
#include "../generated/tests/space_to_batch_quant8_1.mod.py.cpp"
#include "../generated/tests/space_to_batch_quant8_2.mod.py.cpp"
#include "../generated/tests/space_to_batch_quant8_3.mod.py.cpp"
#include "../generated/tests/space_to_batch_relaxed.mod.py.cpp"
#include "../generated/tests/space_to_depth_float_1_relaxed.mod.py.cpp"
#include "../generated/tests/space_to_depth_float_2_relaxed.mod.py.cpp"
#include "../generated/tests/space_to_depth_float_3_relaxed.mod.py.cpp"
#include "../generated/tests/squeeze.mod.py.cpp"
#include "../generated/tests/squeeze_float_1.mod.py.cpp"
#include "../generated/tests/squeeze_float_1_relaxed.mod.py.cpp"
#include "../generated/tests/squeeze_quant8_1.mod.py.cpp"
#include "../generated/tests/squeeze_relaxed.mod.py.cpp"
#include "../generated/tests/strided_slice.mod.py.cpp"
#include "../generated/tests/strided_slice_float_1.mod.py.cpp"
#include "../generated/tests/strided_slice_float_10.mod.py.cpp"
#include "../generated/tests/strided_slice_float_10_relaxed.mod.py.cpp"
#include "../generated/tests/strided_slice_float_11.mod.py.cpp"
#include "../generated/tests/strided_slice_float_11_relaxed.mod.py.cpp"
#include "../generated/tests/strided_slice_float_1_relaxed.mod.py.cpp"
#include "../generated/tests/strided_slice_float_2.mod.py.cpp"
#include "../generated/tests/strided_slice_float_2_relaxed.mod.py.cpp"
#include "../generated/tests/strided_slice_float_3.mod.py.cpp"
#include "../generated/tests/strided_slice_float_3_relaxed.mod.py.cpp"
#include "../generated/tests/strided_slice_float_4.mod.py.cpp"
#include "../generated/tests/strided_slice_float_4_relaxed.mod.py.cpp"
#include "../generated/tests/strided_slice_float_5.mod.py.cpp"
#include "../generated/tests/strided_slice_float_5_relaxed.mod.py.cpp"
#include "../generated/tests/strided_slice_float_6.mod.py.cpp"
#include "../generated/tests/strided_slice_float_6_relaxed.mod.py.cpp"
#include "../generated/tests/strided_slice_float_7.mod.py.cpp"
#include "../generated/tests/strided_slice_float_7_relaxed.mod.py.cpp"
#include "../generated/tests/strided_slice_float_8.mod.py.cpp"
#include "../generated/tests/strided_slice_float_8_relaxed.mod.py.cpp"
#include "../generated/tests/strided_slice_float_9.mod.py.cpp"
#include "../generated/tests/strided_slice_float_9_relaxed.mod.py.cpp"
#include "../generated/tests/strided_slice_qaunt8_10.mod.py.cpp"
#include "../generated/tests/strided_slice_qaunt8_11.mod.py.cpp"
#include "../generated/tests/strided_slice_quant8_1.mod.py.cpp"
#include "../generated/tests/strided_slice_quant8_2.mod.py.cpp"
#include "../generated/tests/strided_slice_quant8_3.mod.py.cpp"
#include "../generated/tests/strided_slice_quant8_4.mod.py.cpp"
#include "../generated/tests/strided_slice_quant8_5.mod.py.cpp"
#include "../generated/tests/strided_slice_quant8_6.mod.py.cpp"
#include "../generated/tests/strided_slice_quant8_7.mod.py.cpp"
#include "../generated/tests/strided_slice_quant8_8.mod.py.cpp"
#include "../generated/tests/strided_slice_quant8_9.mod.py.cpp"
#include "../generated/tests/strided_slice_relaxed.mod.py.cpp"
#include "../generated/tests/sub.mod.py.cpp"
#include "../generated/tests/sub_broadcast_float.mod.py.cpp"
#include "../generated/tests/sub_broadcast_float_relaxed.mod.py.cpp"
#include "../generated/tests/sub_relaxed.mod.py.cpp"
#include "../generated/tests/svdf2_relaxed.mod.py.cpp"
#include "../generated/tests/svdf_relaxed.mod.py.cpp"
#include "../generated/tests/svdf_state_relaxed.mod.py.cpp"
#include "../generated/tests/tanh_relaxed.mod.py.cpp"
#include "../generated/tests/transpose.mod.py.cpp"
#include "../generated/tests/transpose_float_1.mod.py.cpp"
#include "../generated/tests/transpose_float_1_relaxed.mod.py.cpp"
#include "../generated/tests/transpose_quant8_1.mod.py.cpp"
#include "../generated/tests/transpose_relaxed.mod.py.cpp"
#include "../generated/tests/abs.mod.py.cpp"
#include "../generated/tests/add_broadcast_float16.mod.py.cpp"
#include "../generated/tests/add_float16.mod.py.cpp"
#include "../generated/tests/argmax_1.mod.py.cpp"
#include "../generated/tests/argmax_2.mod.py.cpp"
#include "../generated/tests/argmax_3.mod.py.cpp"
#include "../generated/tests/argmin_1.mod.py.cpp"
#include "../generated/tests/argmin_2.mod.py.cpp"
#include "../generated/tests/argmin_3.mod.py.cpp"
#include "../generated/tests/avg_pool_v1_2.mod.py.cpp"
#include "../generated/tests/axis_aligned_bbox_transform.mod.py.cpp"
#include "../generated/tests/batch_to_space_v1_2.mod.py.cpp"
#include "../generated/tests/cast.mod.py.cpp"
#include "../generated/tests/channel_shuffle.mod.py.cpp"
#include "../generated/tests/concat_float16_1.mod.py.cpp"
#include "../generated/tests/concat_float16_2.mod.py.cpp"
#include "../generated/tests/concat_float16_3.mod.py.cpp"
#include "../generated/tests/concat_mixed_quant.mod.py.cpp"
#include "../generated/tests/conv2d_v1_2.mod.py.cpp"
#include "../generated/tests/depth_to_space_v1_2.mod.py.cpp"
#include "../generated/tests/depthwise_conv2d_v1_2.mod.py.cpp"
#include "../generated/tests/dequantize_float16.mod.py.cpp"
#include "../generated/tests/div_broadcast_float16.mod.py.cpp"
#include "../generated/tests/div_float16.mod.py.cpp"
#include "../generated/tests/equal.mod.py.cpp"
#include "../generated/tests/expand_dims.mod.py.cpp"
#include "../generated/tests/floor_float16.mod.py.cpp"
#include "../generated/tests/fully_connected_float16.mod.py.cpp"
#include "../generated/tests/gather.mod.py.cpp"
#include "../generated/tests/gather_higher_rank.mod.py.cpp"
#include "../generated/tests/greater.mod.py.cpp"
#include "../generated/tests/greater_equal.mod.py.cpp"
#include "../generated/tests/grouped_conv2d.mod.py.cpp"
#include "../generated/tests/heatmap_max_keypoint.mod.py.cpp"
#include "../generated/tests/l2_normalization_v1_2.mod.py.cpp"
#include "../generated/tests/l2_pool_v1_2.mod.py.cpp"
#include "../generated/tests/layer_norm_lstm.mod.py.cpp"
#include "../generated/tests/less.mod.py.cpp"
#include "../generated/tests/less_equal.mod.py.cpp"
#include "../generated/tests/local_response_normalization_v1_2.mod.py.cpp"
#include "../generated/tests/log_softmax.mod.py.cpp"
#include "../generated/tests/logical_and.mod.py.cpp"
#include "../generated/tests/logical_not.mod.py.cpp"
#include "../generated/tests/logical_or.mod.py.cpp"
#include "../generated/tests/logistic_float16_1.mod.py.cpp"
#include "../generated/tests/logistic_float16_2.mod.py.cpp"
#include "../generated/tests/lsh_projection_3_relaxed.mod.py.cpp"
#include "../generated/tests/lsh_projection_4_relaxed.mod.py.cpp"
#include "../generated/tests/lsh_projection_deprecated.mod.py.cpp"
#include "../generated/tests/max_pool_v1_2.mod.py.cpp"
#include "../generated/tests/maximum.mod.py.cpp"
#include "../generated/tests/mean_float16.mod.py.cpp"
#include "../generated/tests/minimum.mod.py.cpp"
#include "../generated/tests/mul_broadcast_float16.mod.py.cpp"
#include "../generated/tests/mul_float16.mod.py.cpp"
#include "../generated/tests/neg.mod.py.cpp"
#include "../generated/tests/not_equal.mod.py.cpp"
#include "../generated/tests/pad_float16.mod.py.cpp"
#include "../generated/tests/pad_v2_1_float.mod.py.cpp"
#include "../generated/tests/pad_v2_1_float_relaxed.mod.py.cpp"
#include "../generated/tests/pad_v2_1_quant8.mod.py.cpp"
#include "../generated/tests/pow.mod.py.cpp"
#include "../generated/tests/prelu.mod.py.cpp"
#include "../generated/tests/quantize.mod.py.cpp"
#include "../generated/tests/quantized_lstm.mod.py.cpp"
#include "../generated/tests/random_multinomial.mod.py.cpp"
#include "../generated/tests/random_multinomial_float16.mod.py.cpp"
#include "../generated/tests/reduce_all.mod.py.cpp"
#include "../generated/tests/reduce_any.mod.py.cpp"
#include "../generated/tests/reduce_max.mod.py.cpp"
#include "../generated/tests/reduce_min.mod.py.cpp"
#include "../generated/tests/reduce_prod.mod.py.cpp"
#include "../generated/tests/reduce_sum.mod.py.cpp"
#include "../generated/tests/relu1_float16_1.mod.py.cpp"
#include "../generated/tests/relu1_float16_2.mod.py.cpp"
#include "../generated/tests/relu6_float16_1.mod.py.cpp"
#include "../generated/tests/relu6_float16_2.mod.py.cpp"
#include "../generated/tests/relu_float16_1.mod.py.cpp"
#include "../generated/tests/relu_float16_2.mod.py.cpp"
#include "../generated/tests/reshape_float16.mod.py.cpp"
#include "../generated/tests/resize_bilinear_v1_2.mod.py.cpp"
#include "../generated/tests/roi_align.mod.py.cpp"
#include "../generated/tests/roi_pooling.mod.py.cpp"
#include "../generated/tests/rotated_bbox_transform.mod.py.cpp"
#include "../generated/tests/select_v1_2.mod.py.cpp"
#include "../generated/tests/slice.mod.py.cpp"
#include "../generated/tests/softmax_v1_2.mod.py.cpp"
#include "../generated/tests/space_to_batch_v1_2.mod.py.cpp"
#include "../generated/tests/space_to_depth_v1_2.mod.py.cpp"
#include "../generated/tests/split_float_1.mod.py.cpp"
#include "../generated/tests/split_float_2.mod.py.cpp"
#include "../generated/tests/split_float_3.mod.py.cpp"
#include "../generated/tests/split_float_4.mod.py.cpp"
#include "../generated/tests/split_float_5.mod.py.cpp"
#include "../generated/tests/split_int32_1.mod.py.cpp"
#include "../generated/tests/split_int32_2.mod.py.cpp"
#include "../generated/tests/split_int32_3.mod.py.cpp"
#include "../generated/tests/split_int32_4.mod.py.cpp"
#include "../generated/tests/split_quant8_1.mod.py.cpp"
#include "../generated/tests/split_quant8_2.mod.py.cpp"
#include "../generated/tests/split_quant8_3.mod.py.cpp"
#include "../generated/tests/split_quant8_4.mod.py.cpp"
#include "../generated/tests/squeeze_float16.mod.py.cpp"
#include "../generated/tests/strided_slice_float16.mod.py.cpp"
#include "../generated/tests/sub_float16.mod.py.cpp"
#include "../generated/tests/sub_float16_broadcast.mod.py.cpp"
#include "../generated/tests/sub_quantized.mod.py.cpp"
#include "../generated/tests/sub_quantized_broadcast.mod.py.cpp"
#include "../generated/tests/sub_quantized_different_scales.mod.py.cpp"
#include "../generated/tests/tanh_float16.mod.py.cpp"
#include "../generated/tests/tanh_quantized.mod.py.cpp"
#include "../generated/tests/tile_1.mod.py.cpp"
#include "../generated/tests/tile_2.mod.py.cpp"
#include "../generated/tests/tile_3.mod.py.cpp"
#include "../generated/tests/topk_v2.mod.py.cpp"
#include "../generated/tests/transpose_conv2d.mod.py.cpp"
#include "../generated/tests/transpose_float16.mod.py.cpp"
#include "../generated/tests/transpose_v1_2.mod.py.cpp"
