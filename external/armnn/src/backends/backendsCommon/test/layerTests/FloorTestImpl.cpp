//
// Copyright © 2017 Arm Ltd and Contributors. All rights reserved.
// SPDX-License-Identifier: MIT
//

#include "FloorTestImpl.hpp"

#include <backendsCommon/test/DataTypeUtils.hpp>
#include <backendsCommon/test/TensorCopyUtils.hpp>
#include <backendsCommon/test/WorkloadTestUtils.hpp>

#include <test/TensorHelpers.hpp>

template<armnn::DataType ArmnnType, typename T>
LayerTestResult<T, 4> SimpleFloorTest(
    armnn::IWorkloadFactory& workloadFactory,
    const armnn::IBackendInternal::IMemoryManagerSharedPtr& memoryManager,
    const armnn::ITensorHandleFactory& tensorHandleFactory)
{
    IgnoreUnused(memoryManager);
    armnn::TensorInfo inputTensorInfo({1, 3, 2, 3}, ArmnnType);
    inputTensorInfo.SetQuantizationScale(0.1f);

    armnn::TensorInfo outputTensorInfo(inputTensorInfo);
    outputTensorInfo.SetQuantizationScale(0.1f);

    auto input = MakeTensor<T, 4>(inputTensorInfo, ConvertToDataType<ArmnnType>(
        { -37.5f, -15.2f, -8.76f, -2.0f, -1.5f, -1.3f, -0.5f, -0.4f, 0.0f,
        1.0f, 0.4f, 0.5f, 1.3f, 1.5f, 2.0f, 8.76f, 15.2f, 37.5f },
        inputTensorInfo));

    LayerTestResult<T, 4> ret(outputTensorInfo);
    ret.outputExpected = MakeTensor<T, 4>(outputTensorInfo, ConvertToDataType<ArmnnType>(
        { -38.0f, -16.0f, -9.0f, -2.0f, -2.0f, -2.0f, -1.0f, -1.0f, 0.0f,
        1.0f, 0.0f, 0.0f, 1.0f, 1.0f, 2.0f, 8.0f, 15.0f, 37.0f },
        outputTensorInfo));

    std::unique_ptr<armnn::ITensorHandle> inputHandle = tensorHandleFactory.CreateTensorHandle(inputTensorInfo);
    std::unique_ptr<armnn::ITensorHandle> outputHandle = tensorHandleFactory.CreateTensorHandle(outputTensorInfo);

    armnn::FloorQueueDescriptor data;
    armnn::WorkloadInfo info;
    AddInputToWorkload(data, info, inputTensorInfo, inputHandle.get());
    AddOutputToWorkload(data, info, outputTensorInfo, outputHandle.get());

    std::unique_ptr<armnn::IWorkload> workload = workloadFactory.CreateFloor(data, info);

    inputHandle->Allocate();
    outputHandle->Allocate();

    CopyDataToITensorHandle(inputHandle.get(), &input[0][0][0][0]);

    workload->Execute();

    CopyDataFromITensorHandle(&ret.output[0][0][0][0], outputHandle.get());

    return ret;
}

//
// Explicit template specializations
//

template LayerTestResult<armnn::ResolveType<armnn::DataType::Float32>, 4>
SimpleFloorTest<armnn::DataType::Float32>(
    armnn::IWorkloadFactory& workloadFactory,
    const armnn::IBackendInternal::IMemoryManagerSharedPtr& memoryManager,
    const armnn::ITensorHandleFactory& tensorHandleFactory);

template LayerTestResult<armnn::ResolveType<armnn::DataType::Float16>, 4>
SimpleFloorTest<armnn::DataType::Float16>(
    armnn::IWorkloadFactory& workloadFactory,
    const armnn::IBackendInternal::IMemoryManagerSharedPtr& memoryManager,
    const armnn::ITensorHandleFactory& tensorHandleFactory);


template LayerTestResult<armnn::ResolveType<armnn::DataType::QSymmS16>, 4>
SimpleFloorTest<armnn::DataType::QSymmS16>(
    armnn::IWorkloadFactory& workloadFactory,
    const armnn::IBackendInternal::IMemoryManagerSharedPtr& memoryManager,
    const armnn::ITensorHandleFactory& tensorHandleFactory);
