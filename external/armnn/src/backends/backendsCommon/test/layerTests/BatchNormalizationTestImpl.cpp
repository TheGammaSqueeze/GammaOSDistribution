//
// Copyright © 2017 Arm Ltd and Contributors. All rights reserved.
// SPDX-License-Identifier: MIT
//

#include "BatchNormalizationTestImpl.hpp"

#include <QuantizeHelper.hpp>
#include <ResolveType.hpp>

#include <armnn/utility/IgnoreUnused.hpp>
#include <armnnUtils/DataLayoutIndexed.hpp>

#include <backendsCommon/CpuTensorHandle.hpp>
#include <armnn/backends/IBackendInternal.hpp>
#include <backendsCommon/WorkloadFactory.hpp>
#include <reference/test/RefWorkloadFactoryHelper.hpp>

#include <backendsCommon/test/TensorCopyUtils.hpp>
#include <backendsCommon/test/WorkloadTestUtils.hpp>

#include <test/TensorHelpers.hpp>

namespace
{

using namespace armnnUtils;

template<armnn::DataType ArmnnType, typename T = armnn::ResolveType<ArmnnType>>
LayerTestResult<T, 4> BatchNormTestImpl(
    armnn::IWorkloadFactory& workloadFactory,
    const armnn::IBackendInternal::IMemoryManagerSharedPtr& memoryManager,
    const armnn::ITensorHandleFactory& tensorHandleFactory,
    const armnn::TensorShape& inputOutputTensorShape,
    const std::vector<float>& inputValues,
    const std::vector<float>& expectedOutputValues,
    float qScale,
    int32_t qOffset,
    armnn::DataLayout dataLayout)
{
    IgnoreUnused(memoryManager);
    armnn::TensorInfo inputTensorInfo(inputOutputTensorShape, ArmnnType);
    armnn::TensorInfo outputTensorInfo(inputOutputTensorShape, ArmnnType);

    armnnUtils::DataLayoutIndexed dataLayoutIndexed(dataLayout);

    armnn::TensorInfo tensorInfo({ inputOutputTensorShape[dataLayoutIndexed.GetChannelsIndex()] },
                                 ArmnnType);

    // Set quantization parameters if the requested type is a quantized type.
    if (armnn::IsQuantizedType<T>())
    {
        inputTensorInfo.SetQuantizationScale(qScale);
        inputTensorInfo.SetQuantizationOffset(qOffset);
        outputTensorInfo.SetQuantizationScale(qScale);
        outputTensorInfo.SetQuantizationOffset(qOffset);
        tensorInfo.SetQuantizationScale(qScale);
        tensorInfo.SetQuantizationOffset(qOffset);
    }

    auto inputTensor = MakeTensor<T, 4>(inputTensorInfo, QuantizedVector<T>(inputValues, qScale, qOffset));

    // These values are per-channel of the input.
    auto mean     = MakeTensor<T, 1>(tensorInfo, QuantizedVector<T>({ 3, -2 }, qScale, qOffset));
    auto variance = MakeTensor<T, 1>(tensorInfo, QuantizedVector<T>({ 4,  9 }, qScale, qOffset));
    auto beta     = MakeTensor<T, 1>(tensorInfo, QuantizedVector<T>({ 3,  2 }, qScale, qOffset));
    auto gamma    = MakeTensor<T, 1>(tensorInfo, QuantizedVector<T>({ 2,  1 }, qScale, qOffset));

    LayerTestResult<T, 4> result(outputTensorInfo);

    result.outputExpected = MakeTensor<T, 4>(inputTensorInfo,
                                             QuantizedVector<T>(expectedOutputValues, qScale, qOffset));

    std::unique_ptr<armnn::ITensorHandle> inputHandle = tensorHandleFactory.CreateTensorHandle(inputTensorInfo);
    std::unique_ptr<armnn::ITensorHandle> outputHandle = tensorHandleFactory.CreateTensorHandle(outputTensorInfo);

    armnn::ScopedCpuTensorHandle meanTensor(tensorInfo);
    armnn::ScopedCpuTensorHandle varianceTensor(tensorInfo);
    armnn::ScopedCpuTensorHandle betaTensor(tensorInfo);
    armnn::ScopedCpuTensorHandle gammaTensor(tensorInfo);

    armnn::BatchNormalizationQueueDescriptor descriptor;
    descriptor.m_Mean                    = &meanTensor;
    descriptor.m_Variance                = &varianceTensor;
    descriptor.m_Beta                    = &betaTensor;
    descriptor.m_Gamma                   = &gammaTensor;
    descriptor.m_Parameters.m_Eps        = 0.0f;
    descriptor.m_Parameters.m_DataLayout = dataLayout;
    armnn::WorkloadInfo info;

    AllocateAndCopyDataToITensorHandle(&meanTensor, &mean[0]);
    AllocateAndCopyDataToITensorHandle(&varianceTensor, &variance[0]);
    AllocateAndCopyDataToITensorHandle(&betaTensor, &beta[0]);
    AllocateAndCopyDataToITensorHandle(&gammaTensor, &gamma[0]);

    AddInputToWorkload(descriptor, info, inputTensorInfo, inputHandle.get());
    AddOutputToWorkload(descriptor, info, outputTensorInfo, outputHandle.get());

    std::unique_ptr<armnn::IWorkload> workload = workloadFactory.CreateBatchNormalization(descriptor, info);

    inputHandle->Allocate();
    outputHandle->Allocate();

    CopyDataToITensorHandle(inputHandle.get(), &inputTensor[0][0][0][0]);

    workload->Execute();

    CopyDataFromITensorHandle(&result.output[0][0][0][0], outputHandle.get());

    return result;
}

template<armnn::DataType ArmnnType, typename T = armnn::ResolveType<ArmnnType>>
LayerTestResult<T,4> BatchNormTestNhwcImpl(
    armnn::IWorkloadFactory& workloadFactory,
    const armnn::IBackendInternal::IMemoryManagerSharedPtr& memoryManager,
    const armnn::ITensorHandleFactory& tensorHandleFactory,
    float qScale,
    int32_t qOffset)
{
    IgnoreUnused(memoryManager);

    const unsigned int width    = 2;
    const unsigned int height   = 3;
    const unsigned int channels = 2;
    const unsigned int num      = 1;

    armnn::TensorInfo inputTensorInfo({num, height, width, channels}, ArmnnType);
    armnn::TensorInfo outputTensorInfo({num, height, width, channels}, ArmnnType);
    armnn::TensorInfo tensorInfo({channels}, ArmnnType);

    // Set quantization parameters if the requested type is a quantized type.
    if(armnn::IsQuantizedType<T>())
    {
        inputTensorInfo.SetQuantizationScale(qScale);
        inputTensorInfo.SetQuantizationOffset(qOffset);
        outputTensorInfo.SetQuantizationScale(qScale);
        outputTensorInfo.SetQuantizationOffset(qOffset);
        tensorInfo.SetQuantizationScale(qScale);
        tensorInfo.SetQuantizationOffset(qOffset);
    }

    auto input = MakeTensor<T, 4>(inputTensorInfo,
        QuantizedVector<T>(
        {
            1.f, 1.f, 4.f, 1.f,
            4.f, 4.f, 2.f, 1.f,
            1.f, -2.f, 6.f, 4.f
        },
        qScale, qOffset));
    // These values are per-channel of the input.
    auto mean     = MakeTensor<T, 1>(tensorInfo, QuantizedVector<T>({ 3, -2 }, qScale, qOffset));
    auto variance = MakeTensor<T, 1>(tensorInfo, QuantizedVector<T>({ 4,  9 }, qScale, qOffset));
    auto beta     = MakeTensor<T, 1>(tensorInfo, QuantizedVector<T>({ 3,  2 }, qScale, qOffset));
    auto gamma    = MakeTensor<T, 1>(tensorInfo, QuantizedVector<T>({ 2,  1 }, qScale, qOffset));
    LayerTestResult<T,4> ret(outputTensorInfo);

    std::unique_ptr<armnn::ITensorHandle> inputHandle = tensorHandleFactory.CreateTensorHandle(inputTensorInfo);
    std::unique_ptr<armnn::ITensorHandle> outputHandle = tensorHandleFactory.CreateTensorHandle(outputTensorInfo);

    armnn::BatchNormalizationQueueDescriptor data;
    armnn::WorkloadInfo info;
    armnn::ScopedCpuTensorHandle meanTensor(tensorInfo);
    armnn::ScopedCpuTensorHandle varianceTensor(tensorInfo);
    armnn::ScopedCpuTensorHandle betaTensor(tensorInfo);
    armnn::ScopedCpuTensorHandle gammaTensor(tensorInfo);

    AllocateAndCopyDataToITensorHandle(&meanTensor, &mean[0]);
    AllocateAndCopyDataToITensorHandle(&varianceTensor, &variance[0]);
    AllocateAndCopyDataToITensorHandle(&betaTensor, &beta[0]);
    AllocateAndCopyDataToITensorHandle(&gammaTensor, &gamma[0]);

    AddInputToWorkload(data, info, inputTensorInfo, inputHandle.get());
    AddOutputToWorkload(data, info, outputTensorInfo, outputHandle.get());
    data.m_Mean             = &meanTensor;
    data.m_Variance         = &varianceTensor;
    data.m_Beta             = &betaTensor;
    data.m_Gamma            = &gammaTensor;
    data.m_Parameters.m_Eps = 0.0f;
    data.m_Parameters.m_DataLayout = armnn::DataLayout::NHWC;

    // For each channel:
    // substract mean, divide by standard deviation (with an epsilon to avoid div by 0),
    // multiply by gamma and add beta
    ret.outputExpected = MakeTensor<T, 4>(outputTensorInfo,
        QuantizedVector<T>(
        {
            1.f, 3.f, 4.f, 3.f,
            4.f, 4.f, 2.f, 3.f,
            1.f, 2.f, 6.f, 4.f
        },
        qScale, qOffset));

    std::unique_ptr<armnn::IWorkload> workload = workloadFactory.CreateBatchNormalization(data, info);

    inputHandle->Allocate();
    outputHandle->Allocate();

    CopyDataToITensorHandle(inputHandle.get(), &input[0][0][0][0]);

    workload->Execute();

    CopyDataFromITensorHandle(&ret.output[0][0][0][0], outputHandle.get());

    return ret;
}

} // anonymous namespace

LayerTestResult<float, 4> BatchNormFloat32Test(
    armnn::IWorkloadFactory& workloadFactory,
    const armnn::IBackendInternal::IMemoryManagerSharedPtr& memoryManager,
    const armnn::ITensorHandleFactory& tensorHandleFactory)
{
    // BatchSize: 1
    // Channels: 2
    // Height: 3
    // Width: 2

    const armnn::TensorShape inputOutputShape{ 1, 2, 3, 2 };
    std::vector<float> inputValues
    {
        // Batch 0, Channel 0, Height (3) x Width (2)
         1.f, 4.f,
         4.f, 2.f,
         1.f, 6.f,

        // Batch 0, Channel 1, Height (3) x Width (2)
         1.f, 1.f,
         4.f, 1.f,
        -2.f, 4.f
    };
    std::vector<float> expectedOutputValues
    {
        // Batch 0, Channel 0, Height (3) x Width (2)
        1.f, 4.f,
        4.f, 2.f,
        1.f, 6.f,

        // Batch 0, Channel 1, Height (3) x Width (2)
        3.f, 3.f,
        4.f, 3.f,
        2.f, 4.f
    };

    return BatchNormTestImpl<armnn::DataType::Float32>(
        workloadFactory,
        memoryManager,
        tensorHandleFactory,
        inputOutputShape,
        inputValues,
        expectedOutputValues,
        0.f,
        0,
        armnn::DataLayout::NCHW);
}

LayerTestResult<float, 4> BatchNormFloat32NhwcTest(
    armnn::IWorkloadFactory& workloadFactory,
    const armnn::IBackendInternal::IMemoryManagerSharedPtr& memoryManager,
    const armnn::ITensorHandleFactory& tensorHandleFactory)
{
    // BatchSize: 1
    // Height: 3
    // Width: 2
    // Channels: 2

    const armnn::TensorShape inputOutputShape{ 1, 3, 2, 2 };
    std::vector<float> inputValues
    {
        // Batch 0, Height 0, Width (2) x Channel (2)
        1.f,  1.f,
        4.f,  1.f,

        // Batch 0, Height 1, Width (2) x Channel (2)
        4.f,  4.f,
        2.f,  1.f,

        // Batch 0, Height 2, Width (2) x Channel (2)
        1.f, -2.f,
        6.f,  4.f
    };
    std::vector<float> expectedOutputValues
    {
        // Batch 0, Height 0, Width (2) x Channel (2)
        1.f, 3.f,
        4.f, 3.f,

        // Batch 0, Height 1, Width (2) x Channel (2)
        4.f, 4.f,
        2.f, 3.f,

        // Batch 0, Height 2, Width (2) x Channel (2)
        1.f, 2.f,
        6.f, 4.f
    };

    return BatchNormTestImpl<armnn::DataType::Float32>(
        workloadFactory,
        memoryManager,
        tensorHandleFactory,
        inputOutputShape,
        inputValues,
        expectedOutputValues,
        0.f,
        0,
        armnn::DataLayout::NHWC);
}

LayerTestResult<armnn::Half, 4> BatchNormFloat16Test(
    armnn::IWorkloadFactory& workloadFactory,
    const armnn::IBackendInternal::IMemoryManagerSharedPtr& memoryManager,
    const armnn::ITensorHandleFactory& tensorHandleFactory)
{
    // BatchSize: 1
    // Channels: 2
    // Height: 3
    // Width: 2

    const armnn::TensorShape inputOutputShape{ 1, 2, 3, 2 };
    std::vector<float> inputValues
    {
        // Batch 0, Channel 0, Height (3) x Width (2)
         1.f, 4.f,
         4.f, 2.f,
         1.f, 6.f,

        // Batch 0, Channel 1, Height (3) x Width (2)
         1.f, 1.f,
         4.f, 1.f,
        -2.f, 4.f
    };
    std::vector<float> expectedOutputValues
    {
        // Batch 0, Channel 0, Height (3) x Width (2)
        1.f, 4.f,
        4.f, 2.f,
        1.f, 6.f,

        // Batch 0, Channel 1, Height (3) x Width (2)
        3.f, 3.f,
        4.f, 3.f,
        2.f, 4.f
    };

    return BatchNormTestImpl<armnn::DataType::Float16>(
        workloadFactory,
        memoryManager,
        tensorHandleFactory,
        inputOutputShape,
        inputValues,
        expectedOutputValues,
        0.f,
        0,
        armnn::DataLayout::NCHW);
}

LayerTestResult<armnn::Half, 4> BatchNormFloat16NhwcTest(
    armnn::IWorkloadFactory& workloadFactory,
    const armnn::IBackendInternal::IMemoryManagerSharedPtr& memoryManager,
    const armnn::ITensorHandleFactory& tensorHandleFactory)
{
    // BatchSize: 1
    // Height: 3
    // Width: 2
    // Channels: 2

    const armnn::TensorShape inputOutputShape{ 1, 3, 2, 2 };
    std::vector<float> inputValues
    {
        // Batch 0, Height 0, Width (2) x Channel (2)
        1.f,  1.f,
        4.f,  1.f,

        // Batch 0, Height 1, Width (2) x Channel (2)
        4.f,  4.f,
        2.f,  1.f,

        // Batch 0, Height 2, Width (2) x Channel (2)
        1.f, -2.f,
        6.f,  4.f
    };
    std::vector<float> expectedOutputValues
    {
        // Batch 0, Height 0, Width (2) x Channel (2)
        1.f, 3.f,
        4.f, 3.f,

        // Batch 0, Height 1, Width (2) x Channel (2)
        4.f, 4.f,
        2.f, 3.f,

        // Batch 0, Height 2, Width (2) x Channel (2)
        1.f, 2.f,
        6.f, 4.f
    };

    return BatchNormTestImpl<armnn::DataType::Float16>(
        workloadFactory,
        memoryManager,
        tensorHandleFactory,
        inputOutputShape,
        inputValues,
        expectedOutputValues,
        0.f,
        0,
        armnn::DataLayout::NHWC);
}

LayerTestResult<uint8_t, 4> BatchNormUint8Test(
    armnn::IWorkloadFactory& workloadFactory,
    const armnn::IBackendInternal::IMemoryManagerSharedPtr& memoryManager,
    const armnn::ITensorHandleFactory& tensorHandleFactory)
{
    // BatchSize: 1
    // Channels: 2
    // Height: 3
    // Width: 2

    const armnn::TensorShape inputOutputShape{ 1, 2, 3, 2 };
    std::vector<float> inputValues
    {
        // Batch 0, Channel 0, Height (3) x Width (2)
         1.f, 4.f,
         4.f, 2.f,
         1.f, 6.f,

        // Batch 0, Channel 1, Height (3) x Width (2)
         1.f, 1.f,
         4.f, 1.f,
        -2.f, 4.f
    };
    std::vector<float> expectedOutputValues
    {
        // Batch 0, Channel 0, Height (3) x Width (2)
        1.f, 4.f,
        4.f, 2.f,
        1.f, 6.f,

        // Batch 0, Channel 1, Height (3) x Width (2)
        3.f, 3.f,
        4.f, 3.f,
        2.f, 4.f
    };

    return BatchNormTestImpl<armnn::DataType::QAsymmU8>(
        workloadFactory,
        memoryManager,
        tensorHandleFactory,
        inputOutputShape,
        inputValues,
        expectedOutputValues,
        1.f / 20.f,
        50,
        armnn::DataLayout::NCHW);
}

LayerTestResult<uint8_t, 4> BatchNormUint8NhwcTest(
    armnn::IWorkloadFactory& workloadFactory,
    const armnn::IBackendInternal::IMemoryManagerSharedPtr& memoryManager,
    const armnn::ITensorHandleFactory& tensorHandleFactory)
{
    // BatchSize: 1
    // Height: 3
    // Width: 2
    // Channels: 2

    const armnn::TensorShape inputOutputShape{ 1, 3, 2, 2 };
    std::vector<float> inputValues
    {
        // Batch 0, Height 0, Width (2) x Channel (2)
        1.f,  1.f,
        4.f,  1.f,

        // Batch 0, Height 1, Width (2) x Channel (2)
        4.f,  4.f,
        2.f,  1.f,

        // Batch 0, Height 2, Width (2) x Channel (2)
        1.f, -2.f,
        6.f,  4.f
    };
    std::vector<float> expectedOutputValues
    {
        // Batch 0, Height 0, Width (2) x Channel (2)
        1.f, 3.f,
        4.f, 3.f,

        // Batch 0, Height 1, Width (2) x Channel (2)
        4.f, 4.f,
        2.f, 3.f,

        // Batch 0, Height 2, Width (2) x Channel (2)
        1.f, 2.f,
        6.f, 4.f
    };

    return BatchNormTestImpl<armnn::DataType::QAsymmU8>(
        workloadFactory,
        memoryManager,
        tensorHandleFactory,
        inputOutputShape, inputValues, expectedOutputValues,
         1.f/20.f, 50, armnn::DataLayout::NHWC);
}

LayerTestResult<int16_t, 4> BatchNormInt16Test(
    armnn::IWorkloadFactory& workloadFactory,
    const armnn::IBackendInternal::IMemoryManagerSharedPtr& memoryManager,
    const armnn::ITensorHandleFactory& tensorHandleFactory)
{
    // BatchSize: 1
    // Channels: 2
    // Height: 3
    // Width: 2

    const armnn::TensorShape inputOutputShape{ 1, 2, 3, 2 };
    std::vector<float> inputValues
    {
        // Batch 0, Channel 0, Height (3) x Width (2)
         1.f, 4.f,
         4.f, 2.f,
         1.f, 6.f,

        // Batch 0, Channel 1, Height (3) x Width (2)
         1.f, 1.f,
         4.f, 1.f,
        -2.f, 4.f
    };
    std::vector<float> expectedOutputValues
    {
        // Batch 0, Channel 0, Height (3) x Width (2)
        1.f, 4.f,
        4.f, 2.f,
        1.f, 6.f,

        // Batch 0, Channel 1, Height (3) x Width (2)
        3.f, 3.f,
        4.f, 3.f,
        2.f, 4.f
    };

    return BatchNormTestImpl<armnn::DataType::QSymmS16>(
        workloadFactory,
        memoryManager,
        tensorHandleFactory,
        inputOutputShape,
        inputValues,
        expectedOutputValues,
        1.f / 20.f,
        50,
        armnn::DataLayout::NCHW);
}

LayerTestResult<int16_t, 4> BatchNormInt16NhwcTest(
    armnn::IWorkloadFactory& workloadFactory,
    const armnn::IBackendInternal::IMemoryManagerSharedPtr& memoryManager,
    const armnn::ITensorHandleFactory& tensorHandleFactory)
{
    // BatchSize: 1
    // Height: 3
    // Width: 2
    // Channels: 2

    const armnn::TensorShape inputOutputShape{ 1, 3, 2, 2 };
    std::vector<float> inputValues
    {
        // Batch 0, Height 0, Width (2) x Channel (2)
        1.f,  1.f,
        4.f,  1.f,

        // Batch 0, Height 1, Width (2) x Channel (2)
        4.f,  4.f,
        2.f,  1.f,

        // Batch 0, Height 2, Width (2) x Channel (2)
        1.f, -2.f,
        6.f,  4.f
    };
    std::vector<float> expectedOutputValues
    {
        // Batch 0, Height 0, Width (2) x Channel (2)
        1.f, 3.f,
        4.f, 3.f,

        // Batch 0, Height 1, Width (2) x Channel (2)
        4.f, 4.f,
        2.f, 3.f,

        // Batch 0, Height 2, Width (2) x Channel (2)
        1.f, 2.f,
        6.f, 4.f
    };

    return BatchNormTestImpl<armnn::DataType::QSymmS16>(
        workloadFactory,
        memoryManager,
        tensorHandleFactory,
        inputOutputShape,
        inputValues,
        expectedOutputValues,
        1.f / 20.f,
        50,
        armnn::DataLayout::NHWC);
}

LayerTestResult<float,4> CompareBatchNormTest(
    armnn::IWorkloadFactory& workloadFactory,
    const armnn::IBackendInternal::IMemoryManagerSharedPtr& memoryManager,
    armnn::IWorkloadFactory& refWorkloadFactory,
    const armnn::ITensorHandleFactory& tensorHandleFactory,
    const armnn::ITensorHandleFactory& refTensorHandleFactory)
{
    IgnoreUnused(memoryManager);
    const unsigned int width     = 2;
    const unsigned int height    = 3;
    const unsigned int channels  = 5;
    const unsigned int batchSize = 3;

    armnn::TensorInfo inputTensorInfo;
    armnn::TensorInfo outputTensorInfo;
    armnn::TensorInfo tensorInfo;

    constexpr unsigned int shape[]       = {batchSize, channels, height, width};
    constexpr unsigned int tensorShape[] = {channels};

    inputTensorInfo = armnn::TensorInfo(4, shape, armnn::DataType::Float32);
    outputTensorInfo = armnn::TensorInfo(4, shape, armnn::DataType::Float32);
    tensorInfo = armnn::TensorInfo(1, tensorShape, armnn::DataType::Float32);

    auto input = MakeRandomTensor<float, 4>(inputTensorInfo, 21312);

    auto mean     = MakeRandomTensor<float, 1>(tensorInfo, 123);
    auto variance = MakeRandomTensor<float, 1>(tensorInfo, 234, 0.0f);
    auto beta     = MakeRandomTensor<float, 1>(tensorInfo, 123);
    auto gamma    = MakeRandomTensor<float, 1>(tensorInfo, 345);

    LayerTestResult<float,4> ret(outputTensorInfo);

    std::unique_ptr<armnn::ITensorHandle> inputHandle  = tensorHandleFactory.CreateTensorHandle(inputTensorInfo);
    std::unique_ptr<armnn::ITensorHandle> outputHandle = tensorHandleFactory.CreateTensorHandle(outputTensorInfo);

    std::unique_ptr<armnn::ITensorHandle> inputHandleRef  = refTensorHandleFactory.CreateTensorHandle(inputTensorInfo);
    std::unique_ptr<armnn::ITensorHandle> outputHandleRef = refTensorHandleFactory.CreateTensorHandle(outputTensorInfo);

    armnn::BatchNormalizationQueueDescriptor data;
    armnn::WorkloadInfo info;
    armnn::ScopedCpuTensorHandle meanTensor(tensorInfo);
    armnn::ScopedCpuTensorHandle varianceTensor(tensorInfo);
    armnn::ScopedCpuTensorHandle betaTensor(tensorInfo);
    armnn::ScopedCpuTensorHandle gammaTensor(tensorInfo);

    AllocateAndCopyDataToITensorHandle(&meanTensor, &mean[0]);
    AllocateAndCopyDataToITensorHandle(&varianceTensor, &variance[0]);
    AllocateAndCopyDataToITensorHandle(&betaTensor, &beta[0]);
    AllocateAndCopyDataToITensorHandle(&gammaTensor, &gamma[0]);

    AddInputToWorkload(data, info, inputTensorInfo, inputHandle.get());
    AddOutputToWorkload(data, info, outputTensorInfo, outputHandle.get());
    data.m_Mean             = &meanTensor;
    data.m_Variance         = &varianceTensor;
    data.m_Beta             = &betaTensor;
    data.m_Gamma            = &gammaTensor;
    data.m_Parameters.m_Eps = 0.01f;

    armnn::BatchNormalizationQueueDescriptor refData = data;
    armnn::WorkloadInfo refInfo = info;
    SetWorkloadInput(refData, refInfo, 0, inputTensorInfo, inputHandleRef.get());
    SetWorkloadOutput(refData, refInfo, 0, outputTensorInfo, outputHandleRef.get());

    std::unique_ptr<armnn::IWorkload> workload = workloadFactory.CreateBatchNormalization(data, info);
    std::unique_ptr<armnn::IWorkload> workloadRef = refWorkloadFactory.CreateBatchNormalization(refData, refInfo);

    inputHandle->Allocate();
    outputHandle->Allocate();
    inputHandleRef->Allocate();
    outputHandleRef->Allocate();

    CopyDataToITensorHandle(inputHandle.get(), &input[0][0][0][0]);
    CopyDataToITensorHandle(inputHandleRef.get(), &input[0][0][0][0]);

    workload->PostAllocationConfigure();
    workload->Execute();
    workloadRef->PostAllocationConfigure();
    workloadRef->Execute();

    CopyDataFromITensorHandle(&ret.output[0][0][0][0], outputHandle.get());
    CopyDataFromITensorHandle(&ret.outputExpected[0][0][0][0], outputHandleRef.get());

    return ret;
}
