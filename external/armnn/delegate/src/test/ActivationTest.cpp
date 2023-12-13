//
// Copyright © 2020 Arm Ltd and Contributors. All rights reserved.
// SPDX-License-Identifier: MIT
//

#include "ActivationTestHelper.hpp"

#include <armnn_delegate.hpp>

#include <flatbuffers/flatbuffers.h>
#include <tensorflow/lite/interpreter.h>
#include <tensorflow/lite/kernels/register.h>
#include <tensorflow/lite/model.h>
#include <tensorflow/lite/schema/schema_generated.h>
#include <tensorflow/lite/version.h>

#include <doctest/doctest.h>

namespace armnnDelegate
{


void ActivationReLuTest(std::vector<armnn::BackendId>& backends)
{

    std::vector<float> inputData = {
            -0.1f, -0.2f, -0.3f, -0.4f,
            0.1f,  0.2f,  0.3f,  0.4f,
            -1.0f, -2.0f, -3.0f, -4.0f,
            1.0f,  2.0f,  3.0f,  4.0f
    };

    // Calculate output values for input.
    auto f = [](float value)
    {
        return std::fmax(0.0f, value);
    };
    std::vector<float> outputExpectedData(inputData.size());
    std::transform(inputData.begin(), inputData.end(), outputExpectedData.begin(), f);

    ActivationTest(tflite::BuiltinOperator_RELU,
                   backends,
                   inputData,
                   outputExpectedData);
}

void ActivationBoundedReluTest(std::vector<armnn::BackendId>& backends)
{
    std::vector<float> inputData = {
            -0.1f, -0.2f, -0.3f, -0.4f,
            0.1f,  0.2f,  0.3f,  0.4f,
            -1.0f, -2.0f, -3.0f, -4.0f,
            1.0f,  2.0f,  3.0f,  4.0f
    };

    const float a = 6.0f;
    const float b = 0.0f;
    // Calculate output values for input.
    auto f = [a, b](float value)
    {
        return std::min(a, std::max(b, value));
    };
    std::vector<float> outputExpectedData(inputData.size());
    std::transform(inputData.begin(), inputData.end(), outputExpectedData.begin(), f);

    ActivationTest(tflite::BuiltinOperator_RELU6,
                   backends,
                   inputData,
                   outputExpectedData);
}

void ActivationSigmoidTest(std::vector<armnn::BackendId>& backends)
{
    std::vector<float> inputData = {
            -0.1f, -0.2f, -0.3f, -0.4f,
            0.1f,  0.2f,  0.3f,  0.4f,
            -1.0f, -2.0f, -3.0f, -4.0f,
            1.0f,  2.0f,  3.0f,  4.0f
    };

    // Calculate output values for input.
    auto f = [](float value)
    {
        return 1.0f / (1.0f + std::exp(-value));
    };
    std::vector<float> outputExpectedData(inputData.size());
    std::transform(inputData.begin(), inputData.end(), outputExpectedData.begin(), f);

    ActivationTest(tflite::BuiltinOperator_LOGISTIC,
                   backends,
                   inputData,
                   outputExpectedData);
}


void ActivationTanHTest(std::vector<armnn::BackendId>& backends)
{
    std::vector<float> inputData = {
            -0.1f, -0.2f, -0.3f, -0.4f,
            0.1f,  0.2f,  0.3f,  0.4f,
            -1.0f, -2.0f, -3.0f, -4.0f,
            1.0f,  2.0f,  3.0f,  4.0f
    };

    // Calculate output values for input.
    auto f = [](float value)
    {
        return tanhf(value);
    };
    std::vector<float> outputExpectedData(inputData.size());
    std::transform(inputData.begin(), inputData.end(), outputExpectedData.begin(), f);

    ActivationTest(tflite::BuiltinOperator_TANH,
                   backends,
                   inputData,
                   outputExpectedData);
}

TEST_SUITE("Activation_CpuRefTests")
{

TEST_CASE ("Activation_ReLu_CpuRef_Test")
{
    std::vector<armnn::BackendId> backends = { armnn::Compute::CpuRef };
    ActivationReLuTest(backends);
}

TEST_CASE ("Activation_Bounded_Relu6_CpuRef_Test")
{
    std::vector<armnn::BackendId> backends = { armnn::Compute::CpuRef };
    ActivationBoundedReluTest(backends);
}

TEST_CASE ("Activation_Sigmoid_CpuRef_Test")
{
    std::vector<armnn::BackendId> backends = { armnn::Compute::CpuRef };
    ActivationSigmoidTest(backends);
}


TEST_CASE ("Activation_TanH_CpuRef_Test")
{
    std::vector<armnn::BackendId> backends = { armnn::Compute::CpuRef };
    ActivationTanHTest(backends);
}

}

TEST_SUITE("Activation_CpuAccTests")
{

TEST_CASE ("Activation_ReLu_CpuAcc_Test")
{
    std::vector<armnn::BackendId> backends = { armnn::Compute::CpuAcc };
    ActivationReLuTest(backends);
}

TEST_CASE ("Activation_Bounded_Relu6_CpuAcc_Test")
{
    std::vector<armnn::BackendId> backends = { armnn::Compute::CpuAcc };
    ActivationBoundedReluTest(backends);
}

TEST_CASE ("Activation_Sigmoid_CpuAcc_Test")
{
    std::vector<armnn::BackendId> backends = { armnn::Compute::CpuAcc };
    ActivationSigmoidTest(backends);
}


TEST_CASE ("Activation_TanH_CpuAcc_Test")
{
    std::vector<armnn::BackendId> backends = { armnn::Compute::CpuAcc };
    ActivationTanHTest(backends);
}

}

TEST_SUITE("Activation_GpuAccTests")
{

TEST_CASE ("Activation_ReLu_GpuAcc_Test")
{
    std::vector<armnn::BackendId> backends = { armnn::Compute::GpuAcc };
    ActivationReLuTest(backends);
}

TEST_CASE ("Activation_Bounded_Relu6_GpuAcc_Test")
{
    std::vector<armnn::BackendId> backends = { armnn::Compute::GpuAcc };
    ActivationBoundedReluTest(backends);
}

TEST_CASE ("Activation_Sigmoid_GpuAcc_Test")
{
    std::vector<armnn::BackendId> backends = { armnn::Compute::GpuAcc };
    ActivationSigmoidTest(backends);
}


TEST_CASE ("Activation_TanH_GpuAcc_Test")
{
    std::vector<armnn::BackendId> backends = { armnn::Compute::GpuAcc };
    ActivationTanHTest(backends);
}

}

} // namespace armnnDelegate