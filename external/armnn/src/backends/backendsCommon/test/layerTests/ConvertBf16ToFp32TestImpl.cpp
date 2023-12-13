//
// Copyright © 2020 Arm Ltd and Contributors. All rights reserved.
// SPDX-License-Identifier: MIT
//

#include "ConvertBf16ToFp32TestImpl.hpp"

#include <backendsCommon/test/TensorCopyUtils.hpp>
#include <backendsCommon/test/WorkloadTestUtils.hpp>

#include <test/TensorHelpers.hpp>

LayerTestResult<float, 4> ConvertBf16ToFp32Test(
    armnn::IWorkloadFactory& workloadFactory,
    const armnn::IBackendInternal::IMemoryManagerSharedPtr& memoryManager,
    const armnn::ITensorHandleFactory& tensorHandleFactory)
{
    IgnoreUnused(memoryManager);

    const armnn::TensorInfo inputTensorInfo({1, 3, 2, 3}, armnn::DataType::BFloat16);
    const armnn::TensorInfo outputTensorInfo({1, 3, 2, 3}, armnn::DataType::Float32);

    std::vector<armnn::BFloat16> inputValues = armnnUtils::QuantizedVector<armnn::BFloat16>(
        {
            -37.5f, -15.2f, -8.76f, -2.0f, -1.5f, -1.3f, -0.5f, -0.4f, 0.0f,
          1.0f, 0.4f, 0.5f, 1.3f, 1.5f, 2.0f, 8.76f, 15.2f, 37.5f
        },
        1.0f, 0);

    auto input = MakeTensor<armnn::BFloat16, 4>(inputTensorInfo, std::vector<armnn::BFloat16>(inputValues));

    LayerTestResult<float, 4> ret(outputTensorInfo);
    ret.outputExpected = MakeTensor<float, 4>(outputTensorInfo,
        { -37.5f, -15.2f, -8.76f, -2.0f, -1.5f, -1.3f, -0.5f, -0.4f, 0.0f,
          1.0f, 0.4f, 0.5f, 1.3f, 1.5f, 2.0f, 8.76f, 15.2f, 37.5f });

    std::unique_ptr<armnn::ITensorHandle> inputHandle = tensorHandleFactory.CreateTensorHandle(inputTensorInfo);
    std::unique_ptr<armnn::ITensorHandle> outputHandle = tensorHandleFactory.CreateTensorHandle(outputTensorInfo);

    armnn::ConvertBf16ToFp32QueueDescriptor data;
    armnn::WorkloadInfo info;
    AddInputToWorkload(data, info, inputTensorInfo, inputHandle.get());
    AddOutputToWorkload(data, info, outputTensorInfo, outputHandle.get());

    std::unique_ptr<armnn::IWorkload> workload = workloadFactory.CreateConvertBf16ToFp32(data, info);

    inputHandle->Allocate();
    outputHandle->Allocate();

    CopyDataToITensorHandle(inputHandle.get(), &input[0][0][0][0]);

    workload->Execute();

    CopyDataFromITensorHandle(&ret.output[0][0][0][0], outputHandle.get());

    return ret;
}
