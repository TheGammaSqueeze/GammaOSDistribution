//
// Copyright © 2020 Arm Ltd. All rights reserved.
// SPDX-License-Identifier: MIT
//

#include "../TestUtils.hpp"

#include <Optimizer.hpp>

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(Optimizer)
using namespace armnn::optimizations;

BOOST_AUTO_TEST_CASE(Fp32NetworkToBf16OptimizationNoConversionTest)
{
    armnn::Graph graph;

    const armnn::TensorInfo infoFP32({ 2, 2, 1, 3 }, armnn::DataType::Float32);

    // Create the simple test network without Conv2D/FullyConnected.
    auto input = graph.AddLayer<armnn::InputLayer>(0, "input");
    input->GetOutputSlot().SetTensorInfo(infoFP32);

    auto floor = graph.AddLayer<armnn::FloorLayer>("floor");
    floor->GetOutputSlot().SetTensorInfo(infoFP32);

    auto output = graph.AddLayer<armnn::OutputLayer>(1, "output");

    // Connect up the layers
    input->GetOutputSlot().Connect(floor->GetInputSlot(0));
    floor->GetOutputSlot().Connect(output->GetInputSlot(0));

    BOOST_TEST(CheckSequence(graph.cbegin(), graph.cend(), &IsLayerOfType<armnn::InputLayer>,
                             &IsLayerOfType<armnn::FloorLayer>, &IsLayerOfType<armnn::OutputLayer>));

    // Run the optimizer
    armnn::Optimizer::Pass(graph, armnn::MakeOptimizations(Fp32NetworkToBf16Converter()));

    BOOST_TEST(CheckSequence(graph.cbegin(), graph.cend(), &IsLayerOfType<armnn::InputLayer>,
                             &IsLayerOfType<armnn::FloorLayer>,
                             &IsLayerOfType<armnn::OutputLayer>));
}

BOOST_AUTO_TEST_CASE(Fp32NetworkToBf16OptimizationConv2DTest)
{
    armnn::Graph graph;

    const armnn::TensorInfo infoFP32({ 2, 3, 8, 1 }, armnn::DataType::Float32);

    // Create const tensor fp32 data
    unsigned int dims[] = { 4, 2, 1, 1 };
    std::vector<float> floatWeights{ 0.0f, -1.0f,
                                     3.8f, // 0x40733333 Round down
                                     3.1055E+29f, // 0x707ADC3C Round up
                                     9.149516E-10f, // 0x307B7FFF Round down
                                    -3.8f, // 0xC0733333 Round down
                                    -3.1055E+29f, // 0xF07ADC3C Round up
                                    -9.149516E-10f // 0xB07B7FFF Round down
                                   };
    armnn::ConstTensor weights(armnn::TensorInfo(4, dims, armnn::DataType::Float32), floatWeights);

    // Create const bias fp32 data
    unsigned int biasDims[] {4};
    std::vector<float> floatBias{ 1.0f, 2.0f, 3.0f, 4.0f };
    armnn::ConstTensor bias(armnn::TensorInfo(1, biasDims, armnn::DataType::Float32), floatBias);

    // A network with Convolution2d layer
    auto input = graph.AddLayer<armnn::InputLayer>(0, "input");
    input->GetOutputSlot().SetTensorInfo(infoFP32);

    armnn::Convolution2dDescriptor descriptor;

    auto conv = graph.AddLayer<armnn::Convolution2dLayer>(descriptor, "conv2d");
    conv->m_Weight = std::make_unique<armnn::ScopedCpuTensorHandle>(weights);
    conv->m_Bias = std::make_unique<armnn::ScopedCpuTensorHandle>(bias);
    conv->GetOutputSlot().SetTensorInfo(infoFP32);

    auto output = graph.AddLayer<armnn::OutputLayer>(1, "output");

    // Connect up the layers
    input->GetOutputSlot().Connect(conv->GetInputSlot(0));
    conv->GetOutputSlot().Connect(output->GetInputSlot(0));

    BOOST_TEST(CheckSequence(graph.cbegin(), graph.cend(), &IsLayerOfType<armnn::InputLayer>,
                             &IsLayerOfType<armnn::Convolution2dLayer>, &IsLayerOfType<armnn::OutputLayer>));

    // Run the optimizer
    armnn::Optimizer::Pass(graph, armnn::MakeOptimizations(Fp32NetworkToBf16Converter()));

    BOOST_TEST(CheckSequence(graph.cbegin(), graph.cend(), &IsLayerOfType<armnn::InputLayer>,
                             &IsLayerOfType<armnn::ConvertFp32ToBf16Layer>, &IsLayerOfType<armnn::Convolution2dLayer>,
                             &IsLayerOfType<armnn::OutputLayer>));

    armnn::TensorInfo inputTensor = conv->GetInputSlot(0).GetConnectedOutputSlot()->GetTensorInfo();
    armnn::TensorInfo outputTensor = conv->GetOutputSlot(0).GetTensorInfo();
    BOOST_TEST((conv->GetDataType() == armnn::DataType::BFloat16));
    BOOST_TEST((conv->m_Weight->GetTensorInfo().GetDataType() == armnn::DataType::BFloat16));
    BOOST_TEST((conv->m_Bias->GetTensorInfo().GetDataType() == armnn::DataType::Float32));
    BOOST_TEST((inputTensor.GetDataType() == armnn::DataType::BFloat16));
    BOOST_TEST((outputTensor.GetDataType() == armnn::DataType::Float32));

    // Check whether data matches expected Bf16 data
    armnn::BFloat16* data = conv->m_Weight->GetTensor<armnn::BFloat16>();
    BOOST_CHECK(data[0] == armnn::BFloat16(0.0f));
    BOOST_CHECK(data[1] == armnn::BFloat16(-1.0f));
    BOOST_CHECK(data[2] == armnn::BFloat16(3.796875f)); // 0x4073
    BOOST_CHECK(data[3] == armnn::BFloat16(3.1072295E29f)); // 0x707B
    BOOST_CHECK(data[4] == armnn::BFloat16(9.131327E-10f)); // 0x307B
    BOOST_CHECK(data[5] == armnn::BFloat16(-3.796875f)); // 0xC073
    BOOST_CHECK(data[6] == armnn::BFloat16(-3.1072295E29f)); // 0xF07B
    BOOST_CHECK(data[7] == armnn::BFloat16(-9.131327E-10f)); // 0xB07B
}

BOOST_AUTO_TEST_CASE(Fp32NetworkToBf16OptimizationFullyConnectedTest)
{
    armnn::Graph graph;

    const armnn::TensorInfo infoFP32({ 2, 3, 8, 1 }, armnn::DataType::Float32);

    // Create const tensor fp32 data
    unsigned int dims[] = { 4, 2, 1, 1 };
    std::vector<float> floatWeights{ 0.0f, -1.0f,
                                     3.8f, // 0x40733333 Round down
                                     3.1055E+29f, // 0x707ADC3C Round up
                                     9.149516E-10f, // 0x307B7FFF Round down
                                    -3.8f, // 0xC0733333 Round down
                                    -3.1055E+29f, // 0xF07ADC3C Round up
                                    -9.149516E-10f // 0xB07B7FFF Round down
                                   };
    armnn::ConstTensor weights(armnn::TensorInfo(4, dims, armnn::DataType::Float32), floatWeights);

    // Create const bias fp32 data
    unsigned int biasDims[] {4};
    std::vector<float> floatBias{ 1.0f, 2.0f, 3.0f, 4.0f };
    armnn::ConstTensor bias(armnn::TensorInfo(1, biasDims, armnn::DataType::Float32), floatBias);

    // A network with FullyConnected layer
    auto input = graph.AddLayer<armnn::InputLayer>(0, "input");
    input->GetOutputSlot().SetTensorInfo(infoFP32);

    armnn::FullyConnectedDescriptor descriptor;

    auto fc = graph.AddLayer<armnn::FullyConnectedLayer>(descriptor, "fully");
    fc->m_Weight = std::make_unique<armnn::ScopedCpuTensorHandle>(weights);
    fc->m_Bias = std::make_unique<armnn::ScopedCpuTensorHandle>(bias);
    fc->GetOutputSlot().SetTensorInfo(infoFP32);

    auto output = graph.AddLayer<armnn::OutputLayer>(1, "output");

    // Connect up the layers
    input->GetOutputSlot().Connect(fc->GetInputSlot(0));
    fc->GetOutputSlot().Connect(output->GetInputSlot(0));

    BOOST_TEST(CheckSequence(graph.cbegin(), graph.cend(), &IsLayerOfType<armnn::InputLayer>,
                             &IsLayerOfType<armnn::FullyConnectedLayer>, &IsLayerOfType<armnn::OutputLayer>));

    // Run the optimizer
    armnn::Optimizer::Pass(graph, armnn::MakeOptimizations(Fp32NetworkToBf16Converter()));

    BOOST_TEST(CheckSequence(graph.cbegin(), graph.cend(), &IsLayerOfType<armnn::InputLayer>,
                             &IsLayerOfType<armnn::ConvertFp32ToBf16Layer>, &IsLayerOfType<armnn::FullyConnectedLayer>,
                             &IsLayerOfType<armnn::OutputLayer>));

    armnn::TensorInfo inputTensor = fc->GetInputSlot(0).GetConnectedOutputSlot()->GetTensorInfo();
    armnn::TensorInfo outputTensor = fc->GetOutputSlot(0).GetTensorInfo();
    BOOST_TEST((fc->GetDataType() == armnn::DataType::BFloat16));
    BOOST_TEST((fc->m_Weight->GetTensorInfo().GetDataType() == armnn::DataType::BFloat16));
    BOOST_TEST((fc->m_Bias->GetTensorInfo().GetDataType() == armnn::DataType::Float32));
    BOOST_TEST((inputTensor.GetDataType() == armnn::DataType::BFloat16));
    BOOST_TEST((outputTensor.GetDataType() == armnn::DataType::Float32));

    // Check whether data matches expected Bf16 data
    armnn::BFloat16* data = fc->m_Weight->GetTensor<armnn::BFloat16>();
    BOOST_CHECK(data[0] == armnn::BFloat16(0.0f));
    BOOST_CHECK(data[1] == armnn::BFloat16(-1.0f));
    BOOST_CHECK(data[2] == armnn::BFloat16(3.796875f)); // 0x4073
    BOOST_CHECK(data[3] == armnn::BFloat16(3.1072295E29f)); // 0x707B
    BOOST_CHECK(data[4] == armnn::BFloat16(9.131327E-10f)); // 0x307B
    BOOST_CHECK(data[5] == armnn::BFloat16(-3.796875f)); // 0xC073
    BOOST_CHECK(data[6] == armnn::BFloat16(-3.1072295E29f)); // 0xF07B
    BOOST_CHECK(data[7] == armnn::BFloat16(-9.131327E-10f)); // 0xB07B
}

BOOST_AUTO_TEST_SUITE_END()