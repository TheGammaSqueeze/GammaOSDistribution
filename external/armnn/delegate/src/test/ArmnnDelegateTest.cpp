//
// Copyright © 2020 Arm Ltd and Contributors. All rights reserved.
// SPDX-License-Identifier: MIT
//

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

#include <armnn_delegate.hpp>
#include "ElementwiseUnaryTestHelper.hpp"

#include "tensorflow/lite/kernels/builtin_op_kernels.h"
#include <tensorflow/lite/interpreter.h>

namespace armnnDelegate
{

TEST_SUITE("ArmnnDelegate")
{

TEST_CASE ("ArmnnDelegate Registered")
{
    using namespace tflite;
    auto tfLiteInterpreter =  std::make_unique<Interpreter>();

    tfLiteInterpreter->AddTensors(3);
    tfLiteInterpreter->SetInputs({0, 1});
    tfLiteInterpreter->SetOutputs({2});

    tfLiteInterpreter->SetTensorParametersReadWrite(0, kTfLiteFloat32, "input1", {1,2,2,1}, TfLiteQuantization());
    tfLiteInterpreter->SetTensorParametersReadWrite(1, kTfLiteFloat32, "input2", {1,2,2,1}, TfLiteQuantization());
    tfLiteInterpreter->SetTensorParametersReadWrite(2, kTfLiteFloat32, "output", {1,2,2,1}, TfLiteQuantization());

    tflite::ops::builtin::BuiltinOpResolver opResolver;
    const TfLiteRegistration* opRegister = opResolver.FindOp(BuiltinOperator_ADD, 1);
    tfLiteInterpreter->AddNodeWithParameters({0, 1}, {2}, "", 0, nullptr, opRegister);

    // Create the Armnn Delegate
    std::vector<armnn::BackendId> backends = { armnn::Compute::CpuRef };
    std::vector<armnn::BackendOptions> backendOptions;
    backendOptions.emplace_back(
        armnn::BackendOptions{ "BackendName",
                               {
                                  { "Option1", 42 },
                                  { "Option2", true }
                               }}
    );

    armnnDelegate::DelegateOptions delegateOptions(backends, backendOptions);
    std::unique_ptr<TfLiteDelegate, decltype(&armnnDelegate::TfLiteArmnnDelegateDelete)>
                       theArmnnDelegate(armnnDelegate::TfLiteArmnnDelegateCreate(delegateOptions),
                                        armnnDelegate::TfLiteArmnnDelegateDelete);

    auto status = tfLiteInterpreter->ModifyGraphWithDelegate(std::move(theArmnnDelegate));
    CHECK(status == kTfLiteOk);
    CHECK(tfLiteInterpreter != nullptr);
}

}

} // namespace armnnDelegate
