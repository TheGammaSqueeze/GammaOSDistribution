//
// Copyright © 2020 Arm Ltd and Contributors. All rights reserved.
// SPDX-License-Identifier: MIT
//

#include "ConvertFp32ToBf16TestImpl.hpp"

#include <backendsCommon/test/TensorCopyUtils.hpp>
#include <backendsCommon/test/WorkloadTestUtils.hpp>

#include <test/TensorHelpers.hpp>

LayerTestResult<armnn::BFloat16, 4> ConvertFp32ToBf16Test(
    armnn::IWorkloadFactory& workloadFactory,
    const armnn::IBackendInternal::IMemoryManagerSharedPtr& memoryManager,
    const armnn::ITensorHandleFactory& tensorHandleFactory)
{
    IgnoreUnused(memoryManager);

    const armnn::TensorInfo inputTensorInfo({1, 2, 4, 3}, armnn::DataType::Float32);
    const armnn::TensorInfo outputTensorInfo({1, 2, 4, 3}, armnn::DataType::BFloat16);

    auto input = MakeTensor<float, 4>(inputTensorInfo,
        { -37.5f, -15.2f, -8.76f,
          -2.0f, -1.5f, -1.3f,
          -0.5f, -0.4f, 0.0f,
          1.0f, 0.4f, 0.5f,
          1.3f, 1.5f, 2.0f,
          8.76f, 15.2f, 37.5f,
          3.8f, // 0x40733333 Round down
          3.1055E+29f, // 0x707ADC3C Round up
          9.149516E-10f, // 0x307B7FFF Round down
          -3.8f, // 0xC0733333 Round down
          -3.1055E+29f, // 0xF07ADC3C Round up
          -9.149516E-10f // 0xB07B7FFF Round down
        });

    std::vector<armnn::BFloat16> outputValues = armnnUtils::QuantizedVector<armnn::BFloat16>(
        {
            -37.5f, -15.2f, -8.76f,
            -2.0f, -1.5f, -1.3f,
            -0.5f, -0.4f, 0.0f,
          1.0f, 0.4f, 0.5f,
          1.3f, 1.5f, 2.0f,
          8.76f, 15.2f, 37.5f,
          3.796875f, // 0x4073
          3.1072295E29f, // 0x707B
          9.131327E-10f, // 0x307B
          -3.796875f, // 0xC073
          -3.1072295E29f, // 0xF07B
          -9.131327E-10f // 0xB07B
        },
        1.0f, 0);

    LayerTestResult<armnn::BFloat16, 4> ret(outputTensorInfo);
    ret.outputExpected = MakeTensor<armnn::BFloat16, 4>(outputTensorInfo, outputValues);

    std::unique_ptr<armnn::ITensorHandle> inputHandle = tensorHandleFactory.CreateTensorHandle(inputTensorInfo);
    std::unique_ptr<armnn::ITensorHandle> outputHandle = tensorHandleFactory.CreateTensorHandle(outputTensorInfo);

    armnn::ConvertFp32ToBf16QueueDescriptor data;
    armnn::WorkloadInfo info;
    AddInputToWorkload(data, info, inputTensorInfo, inputHandle.get());
    AddOutputToWorkload(data, info, outputTensorInfo, outputHandle.get());

    std::unique_ptr<armnn::IWorkload> workload = workloadFactory.CreateConvertFp32ToBf16(data, info);

    inputHandle->Allocate();
    outputHandle->Allocate();

    CopyDataToITensorHandle(inputHandle.get(), &input[0][0][0][0]);

    workload->Execute();

    CopyDataFromITensorHandle(&ret.output[0][0][0][0], outputHandle.get());

    return ret;
}
