//
// Copyright © 2017 Arm Ltd and Contributors. All rights reserved.
// SPDX-License-Identifier: MIT
//

#pragma once

#include "LayerTestResult.hpp"


#include <ResolveType.hpp>

#include <armnn/backends/IBackendInternal.hpp>
#include <backendsCommon/Workload.hpp>
#include <backendsCommon/WorkloadData.hpp>
#include <backendsCommon/WorkloadFactory.hpp>

#include <backendsCommon/test/DataTypeUtils.hpp>
#include <backendsCommon/test/TensorCopyUtils.hpp>
#include <backendsCommon/test/WorkloadTestUtils.hpp>

#include <test/TensorHelpers.hpp>

#include <memory>

template<typename DescriptorType>
std::unique_ptr<armnn::IWorkload> CreateWorkload(
    const armnn::IWorkloadFactory& workloadFactory,
    const armnn::WorkloadInfo& info,
    const DescriptorType& descriptor)
{
    return CreateWorkload(workloadFactory, info, descriptor);
}

template <std::size_t NumDims,
          typename Descriptor,
          armnn::DataType ArmnnTypeInput,
          armnn::DataType ArmnnTypeOutput,
          typename TInput  = armnn::ResolveType<ArmnnTypeInput>,
          typename TOutput = armnn::ResolveType<ArmnnTypeOutput>>
LayerTestResult<TOutput, NumDims> ElementwiseTestHelper(
    armnn::IWorkloadFactory & workloadFactory,
    const armnn::IBackendInternal::IMemoryManagerSharedPtr & memoryManager,
    const unsigned int shape0[NumDims],
    std::vector<TInput> values0,
    float quantScale0,
    int quantOffset0,
    const unsigned int shape1[NumDims],
    std::vector<TInput> values1,
    float quantScale1,
    int quantOffset1,
    const unsigned int outShape[NumDims],
    std::vector<TOutput> outValues,
    const armnn::ITensorHandleFactory& tensorHandleFactory,
    float outQuantScale,
    int outQuantOffset)
{
    armnn::TensorInfo inputTensorInfo0{NumDims, shape0, ArmnnTypeInput};
    armnn::TensorInfo inputTensorInfo1{NumDims, shape1, ArmnnTypeInput};
    armnn::TensorInfo outputTensorInfo{NumDims, outShape, ArmnnTypeOutput};

    auto input0 = MakeTensor<TInput, NumDims>(inputTensorInfo0, values0);
    auto input1 = MakeTensor<TInput, NumDims>(inputTensorInfo1, values1);

    inputTensorInfo0.SetQuantizationScale(quantScale0);
    inputTensorInfo0.SetQuantizationOffset(quantOffset0);

    inputTensorInfo1.SetQuantizationScale(quantScale1);
    inputTensorInfo1.SetQuantizationOffset(quantOffset1);

    outputTensorInfo.SetQuantizationScale(outQuantScale);
    outputTensorInfo.SetQuantizationOffset(outQuantOffset);

    LayerTestResult<TOutput, NumDims> ret(outputTensorInfo);

    if(ArmnnTypeOutput == armnn::DataType::Boolean)
    {
        ret.compareBoolean = true;
    }

    std::unique_ptr<armnn::ITensorHandle> inputHandle0 = tensorHandleFactory.CreateTensorHandle(inputTensorInfo0);
    std::unique_ptr<armnn::ITensorHandle> inputHandle1 = tensorHandleFactory.CreateTensorHandle(inputTensorInfo1);
    std::unique_ptr<armnn::ITensorHandle> outputHandle = tensorHandleFactory.CreateTensorHandle(outputTensorInfo);

    Descriptor data;
    armnn::WorkloadInfo info;
    AddInputToWorkload(data, info, inputTensorInfo0, inputHandle0.get());
    AddInputToWorkload(data, info, inputTensorInfo1, inputHandle1.get());
    AddOutputToWorkload(data, info, outputTensorInfo, outputHandle.get());
    auto workload = CreateWorkload<Descriptor>(workloadFactory, info, data);

    inputHandle0->Allocate();
    inputHandle1->Allocate();
    outputHandle->Allocate();

    CopyDataToITensorHandle(inputHandle0.get(), input0.origin());
    CopyDataToITensorHandle(inputHandle1.get(), input1.origin());

    workload->PostAllocationConfigure();
    ExecuteWorkload(*workload, memoryManager);

    CopyDataFromITensorHandle(ret.output.origin(), outputHandle.get());

    ret.outputExpected = MakeTensor<TOutput, NumDims>(outputTensorInfo, outValues);
    return ret;
}

template <std::size_t NumDims,
          typename Descriptor,
          armnn::DataType ArmnnType,
          typename T = armnn::ResolveType<ArmnnType>>
LayerTestResult<T, NumDims> ElementwiseTestHelper(
    armnn::IWorkloadFactory & workloadFactory,
    const armnn::IBackendInternal::IMemoryManagerSharedPtr & memoryManager,
    const unsigned int shape0[NumDims],
    std::vector<T> values0,
    float quantScale0,
    int quantOffset0,
    const unsigned int shape1[NumDims],
    std::vector<T> values1,
    float quantScale1,
    int quantOffset1,
    const unsigned int outShape[NumDims],
    std::vector<T> outValues,
    const armnn::ITensorHandleFactory& tensorHandleFactory,
    float outQuantScale,
    int outQuantOffset)
{
    return ElementwiseTestHelper<NumDims, Descriptor, ArmnnType, ArmnnType>(
        workloadFactory,
        memoryManager,
        shape0,
        values0,
        quantScale0,
        quantOffset0,
        shape1,
        values1,
        quantScale1,
        quantOffset1,
        outShape,
        outValues,
        tensorHandleFactory,
        outQuantScale,
        outQuantOffset);
}

template <std::size_t NumDims,
          typename Descriptor,
          armnn::DataType ArmnnTypeInput,
          armnn::DataType ArmnnTypeOutput,
          typename TInput  = armnn::ResolveType<ArmnnTypeInput>,
          typename TOutput = armnn::ResolveType<ArmnnTypeOutput>>
LayerTestResult<TOutput, NumDims> ElementwiseTestHelper(
    armnn::IWorkloadFactory & workloadFactory,
    const armnn::IBackendInternal::IMemoryManagerSharedPtr & memoryManager,
    const unsigned int shape0[NumDims],
    std::vector<TInput> values0,
    const unsigned int shape1[NumDims],
    std::vector<TInput> values1,
    const unsigned int outShape[NumDims],
    std::vector<TOutput> outValues,
    const armnn::ITensorHandleFactory& tensorHandleFactory,
    float quantScale = 1.0f,
    int quantOffset = 0)
{
    return ElementwiseTestHelper<NumDims, Descriptor, ArmnnTypeInput, ArmnnTypeOutput>(
        workloadFactory,
        memoryManager,
        shape0,
        values0,
        quantScale,
        quantOffset,
        shape1,
        values1,
        quantScale,
        quantOffset,
        outShape,
        outValues,
        tensorHandleFactory,
        quantScale,
        quantOffset);
}

template <std::size_t NumDims,
          typename Descriptor,
          armnn::DataType ArmnnType,
          typename T = armnn::ResolveType<ArmnnType>>
LayerTestResult<T, NumDims> ElementwiseTestHelper(
    armnn::IWorkloadFactory & workloadFactory,
    const armnn::IBackendInternal::IMemoryManagerSharedPtr & memoryManager,
    const unsigned int shape0[NumDims],
    std::vector<T> values0,
    const unsigned int shape1[NumDims],
    std::vector<T> values1,
    const unsigned int outShape[NumDims],
    std::vector<T> outValues,
    const armnn::ITensorHandleFactory& tensorHandleFactory,
    float quantScale = 1.0f,
    int quantOffset = 0)
{
    return ElementwiseTestHelper<NumDims, Descriptor, ArmnnType, ArmnnType>(
        workloadFactory,
        memoryManager,
        shape0,
        values0,
        shape1,
        values1,
        outShape,
        outValues,
        tensorHandleFactory,
        quantScale,
        quantOffset);
}