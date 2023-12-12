//
// Copyright © 2017 Arm Ltd and Contributors. All rights reserved.
// SPDX-License-Identifier: MIT
//

#include "DebugTestImpl.hpp"

#include <QuantizeHelper.hpp>
#include <ResolveType.hpp>


#include <backendsCommon/test/TensorCopyUtils.hpp>
#include <backendsCommon/test/WorkloadTestUtils.hpp>

#include <test/TensorHelpers.hpp>

namespace
{

template<typename T, std::size_t Dim>
LayerTestResult<T, Dim> DebugTestImpl(
    armnn::IWorkloadFactory& workloadFactory,
    const armnn::IBackendInternal::IMemoryManagerSharedPtr& memoryManager,
    armnn::TensorInfo& inputTensorInfo,
    armnn::TensorInfo& outputTensorInfo,
    std::vector<float>& inputData,
    std::vector<float>& outputExpectedData,
    armnn::DebugQueueDescriptor descriptor,
    const std::string expectedStringOutput,
    const float qScale = 1.0f,
    const int32_t qOffset = 0)
{
    IgnoreUnused(memoryManager);
    if(armnn::IsQuantizedType<T>())
    {
        inputTensorInfo.SetQuantizationScale(qScale);
        inputTensorInfo.SetQuantizationOffset(qOffset);

        outputTensorInfo.SetQuantizationScale(qScale);
        outputTensorInfo.SetQuantizationOffset(qOffset);
    }

    boost::multi_array<T, Dim> input =
        MakeTensor<T, Dim>(inputTensorInfo, armnnUtils::QuantizedVector<T>(inputData, qScale, qOffset));

    LayerTestResult<T, Dim> ret(outputTensorInfo);
    ret.outputExpected =
        MakeTensor<T, Dim>(outputTensorInfo, armnnUtils::QuantizedVector<T>(outputExpectedData, qScale, qOffset));

    ARMNN_NO_DEPRECATE_WARN_BEGIN
    std::unique_ptr<armnn::ITensorHandle> inputHandle = workloadFactory.CreateTensorHandle(inputTensorInfo);
    std::unique_ptr<armnn::ITensorHandle> outputHandle = workloadFactory.CreateTensorHandle(outputTensorInfo);
    ARMNN_NO_DEPRECATE_WARN_END

    armnn::WorkloadInfo info;
    AddInputToWorkload(descriptor, info, inputTensorInfo, inputHandle.get());
    AddOutputToWorkload(descriptor, info, outputTensorInfo, outputHandle.get());

    std::unique_ptr<armnn::IWorkload> workload = workloadFactory.CreateDebug(descriptor, info);

    inputHandle->Allocate();
    outputHandle->Allocate();

    CopyDataToITensorHandle(inputHandle.get(), input.data());

    std::ostringstream oss;
    std::streambuf* coutStreambuf = std::cout.rdbuf();
    std::cout.rdbuf(oss.rdbuf());

    ExecuteWorkload(*workload, memoryManager);

    std::cout.rdbuf(coutStreambuf);

    BOOST_TEST(oss.str() == expectedStringOutput);

    CopyDataFromITensorHandle(ret.output.data(), outputHandle.get());

    return ret;
}

template <armnn::DataType ArmnnType, typename T = armnn::ResolveType<ArmnnType>>
LayerTestResult<T, 4> Debug4dTest(
    armnn::IWorkloadFactory& workloadFactory,
    const armnn::IBackendInternal::IMemoryManagerSharedPtr& memoryManager)
{
    armnn::TensorInfo inputTensorInfo;
    armnn::TensorInfo outputTensorInfo;

    unsigned int inputShape[]  = {1, 2, 2, 3};
    unsigned int outputShape[] = {1, 2, 2, 3};

    armnn::DebugQueueDescriptor desc;
    desc.m_Guid = 1;
    desc.m_LayerName = "TestOutput";
    desc.m_SlotIndex = 0;

    inputTensorInfo = armnn::TensorInfo(4, inputShape, ArmnnType);
    outputTensorInfo = armnn::TensorInfo(4, outputShape, ArmnnType);

    std::vector<float> input = std::vector<float>(
    {
        1.0f,   2.0f,  3.0f,
        4.0f,   5.0f,  6.0f,
        7.0f,   8.0f,  9.0f,
        10.0f, 11.0f, 12.0f,
    });

    std::vector<float> outputExpected = std::vector<float>(
    {
        1.0f,   2.0f,  3.0f,
        4.0f,   5.0f,  6.0f,
        7.0f,   8.0f,  9.0f,
        10.0f, 11.0f, 12.0f,
    });

    const std::string expectedStringOutput =
        "{ \"layerGuid\": 1,"
        " \"layerName\": \"TestOutput\","
        " \"outputSlot\": 0,"
        " \"shape\": [1, 2, 2, 3],"
        " \"min\": 1, \"max\": 12,"
        " \"data\": [[[[1, 2, 3], [4, 5, 6]], [[7, 8, 9], [10, 11, 12]]]] }\n";

    return DebugTestImpl<T, 4>(workloadFactory,
                               memoryManager,
                               inputTensorInfo,
                               outputTensorInfo,
                               input,
                               outputExpected,
                               desc,
                               expectedStringOutput);
}

template <armnn::DataType ArmnnType, typename T = armnn::ResolveType<ArmnnType>>
LayerTestResult<T, 3> Debug3dTest(
    armnn::IWorkloadFactory& workloadFactory,
    const armnn::IBackendInternal::IMemoryManagerSharedPtr& memoryManager)
{
    armnn::TensorInfo inputTensorInfo;
    armnn::TensorInfo outputTensorInfo;

    unsigned int inputShape[]  = {3, 3, 1};
    unsigned int outputShape[] = {3, 3, 1};

    armnn::DebugQueueDescriptor desc;
    desc.m_Guid = 1;
    desc.m_LayerName = "TestOutput";
    desc.m_SlotIndex = 0;

    inputTensorInfo = armnn::TensorInfo(3, inputShape, ArmnnType);
    outputTensorInfo = armnn::TensorInfo(3, outputShape, ArmnnType);

    std::vector<float> input = std::vector<float>(
    {
        1.0f, 2.0f, 3.0f,
        4.0f, 5.0f, 6.0f,
        7.0f, 8.0f, 9.0f,
    });

    std::vector<float> outputExpected = std::vector<float>(
    {
        1.0f, 2.0f, 3.0f,
        4.0f, 5.0f, 6.0f,
        7.0f, 8.0f, 9.0f,
    });

    const std::string expectedStringOutput =
        "{ \"layerGuid\": 1,"
        " \"layerName\": \"TestOutput\","
        " \"outputSlot\": 0,"
        " \"shape\": [3, 3, 1],"
        " \"min\": 1, \"max\": 9,"
        " \"data\": [[[1], [2], [3]], [[4], [5], [6]], [[7], [8], [9]]] }\n";

    return DebugTestImpl<T, 3>(workloadFactory,
                               memoryManager,
                               inputTensorInfo,
                               outputTensorInfo,
                               input,
                               outputExpected,
                               desc,
                               expectedStringOutput);
}

template <armnn::DataType ArmnnType, typename T = armnn::ResolveType<ArmnnType>>
LayerTestResult<T, 2> Debug2dTest(
    armnn::IWorkloadFactory& workloadFactory,
    const armnn::IBackendInternal::IMemoryManagerSharedPtr& memoryManager)
{
    armnn::TensorInfo inputTensorInfo;
    armnn::TensorInfo outputTensorInfo;

    unsigned int inputShape[]  = {2, 2};
    unsigned int outputShape[] = {2, 2};

    armnn::DebugQueueDescriptor desc;
    desc.m_Guid = 1;
    desc.m_LayerName = "TestOutput";
    desc.m_SlotIndex = 0;

    inputTensorInfo = armnn::TensorInfo(2, inputShape, ArmnnType);
    outputTensorInfo = armnn::TensorInfo(2, outputShape, ArmnnType);

    std::vector<float> input = std::vector<float>(
    {
        1.0f, 2.0f,
        3.0f, 4.0f,
    });

    std::vector<float> outputExpected = std::vector<float>(
    {
        1.0f, 2.0f,
        3.0f, 4.0f,
    });

    const std::string expectedStringOutput =
        "{ \"layerGuid\": 1,"
        " \"layerName\": \"TestOutput\","
        " \"outputSlot\": 0,"
        " \"shape\": [2, 2],"
        " \"min\": 1, \"max\": 4,"
        " \"data\": [[1, 2], [3, 4]] }\n";

    return DebugTestImpl<T, 2>(workloadFactory,
                               memoryManager,
                               inputTensorInfo,
                               outputTensorInfo,
                               input,
                               outputExpected,
                               desc,
                               expectedStringOutput);
}

template <armnn::DataType ArmnnType, typename T = armnn::ResolveType<ArmnnType>>
LayerTestResult<T, 1> Debug1dTest(
    armnn::IWorkloadFactory& workloadFactory,
    const armnn::IBackendInternal::IMemoryManagerSharedPtr& memoryManager)
{
    armnn::TensorInfo inputTensorInfo;
    armnn::TensorInfo outputTensorInfo;

    unsigned int inputShape[]  = {4};
    unsigned int outputShape[] = {4};

    armnn::DebugQueueDescriptor desc;
    desc.m_Guid = 1;
    desc.m_LayerName = "TestOutput";
    desc.m_SlotIndex = 0;

    inputTensorInfo = armnn::TensorInfo(1, inputShape, ArmnnType);
    outputTensorInfo = armnn::TensorInfo(1, outputShape, ArmnnType);

    std::vector<float> input = std::vector<float>(
    {
        1.0f, 2.0f, 3.0f, 4.0f,
    });

    std::vector<float> outputExpected = std::vector<float>(
    {
        1.0f, 2.0f, 3.0f, 4.0f,
    });

    const std::string expectedStringOutput =
        "{ \"layerGuid\": 1,"
        " \"layerName\": \"TestOutput\","
        " \"outputSlot\": 0,"
        " \"shape\": [4],"
        " \"min\": 1, \"max\": 4,"
        " \"data\": [1, 2, 3, 4] }\n";

    return DebugTestImpl<T, 1>(workloadFactory,
                               memoryManager,
                               inputTensorInfo,
                               outputTensorInfo,
                               input,
                               outputExpected,
                               desc,
                               expectedStringOutput);
}

} // anonymous namespace

LayerTestResult<float, 4> Debug4dFloat32Test(
    armnn::IWorkloadFactory& workloadFactory,
    const armnn::IBackendInternal::IMemoryManagerSharedPtr& memoryManager)
{
    return Debug4dTest<armnn::DataType::Float32>(workloadFactory, memoryManager);
}

LayerTestResult<float, 3> Debug3dFloat32Test(
    armnn::IWorkloadFactory& workloadFactory,
    const armnn::IBackendInternal::IMemoryManagerSharedPtr& memoryManager)
{
    return Debug3dTest<armnn::DataType::Float32>(workloadFactory, memoryManager);
}

LayerTestResult<float, 2> Debug2dFloat32Test(
    armnn::IWorkloadFactory& workloadFactory,
    const armnn::IBackendInternal::IMemoryManagerSharedPtr& memoryManager)
{
    return Debug2dTest<armnn::DataType::Float32>(workloadFactory, memoryManager);
}

LayerTestResult<float, 1> Debug1dFloat32Test(
    armnn::IWorkloadFactory& workloadFactory,
    const armnn::IBackendInternal::IMemoryManagerSharedPtr& memoryManager)
{
    return Debug1dTest<armnn::DataType::Float32>(workloadFactory, memoryManager);
}

LayerTestResult<armnn::BFloat16, 4> Debug4dBFloat16Test(
    armnn::IWorkloadFactory& workloadFactory,
    const armnn::IBackendInternal::IMemoryManagerSharedPtr& memoryManager)
{
    return Debug4dTest<armnn::DataType::BFloat16>(workloadFactory, memoryManager);
}

LayerTestResult<armnn::BFloat16, 3> Debug3dBFloat16Test(
    armnn::IWorkloadFactory& workloadFactory,
    const armnn::IBackendInternal::IMemoryManagerSharedPtr& memoryManager)
{
    return Debug3dTest<armnn::DataType::BFloat16>(workloadFactory, memoryManager);
}

LayerTestResult<armnn::BFloat16, 2> Debug2dBFloat16Test(
    armnn::IWorkloadFactory& workloadFactory,
    const armnn::IBackendInternal::IMemoryManagerSharedPtr& memoryManager)
{
    return Debug2dTest<armnn::DataType::BFloat16>(workloadFactory, memoryManager);
}

LayerTestResult<armnn::BFloat16, 1> Debug1dBFloat16Test(
    armnn::IWorkloadFactory& workloadFactory,
    const armnn::IBackendInternal::IMemoryManagerSharedPtr& memoryManager)
{
    return Debug1dTest<armnn::DataType::BFloat16>(workloadFactory, memoryManager);
}

LayerTestResult<uint8_t, 4> Debug4dUint8Test(
    armnn::IWorkloadFactory& workloadFactory,
    const armnn::IBackendInternal::IMemoryManagerSharedPtr& memoryManager)
{
    return Debug4dTest<armnn::DataType::QAsymmU8>(workloadFactory, memoryManager);
}

LayerTestResult<uint8_t, 3> Debug3dUint8Test(
    armnn::IWorkloadFactory& workloadFactory,
    const armnn::IBackendInternal::IMemoryManagerSharedPtr& memoryManager)
{
    return Debug3dTest<armnn::DataType::QAsymmU8>(workloadFactory, memoryManager);
}

LayerTestResult<uint8_t, 2> Debug2dUint8Test(
    armnn::IWorkloadFactory& workloadFactory,
    const armnn::IBackendInternal::IMemoryManagerSharedPtr& memoryManager)
{
    return Debug2dTest<armnn::DataType::QAsymmU8>(workloadFactory, memoryManager);
}

LayerTestResult<uint8_t, 1> Debug1dUint8Test(
    armnn::IWorkloadFactory& workloadFactory,
    const armnn::IBackendInternal::IMemoryManagerSharedPtr& memoryManager)
{
    return Debug1dTest<armnn::DataType::QAsymmU8>(workloadFactory, memoryManager);
}

LayerTestResult<int16_t, 4> Debug4dInt16Test(
    armnn::IWorkloadFactory& workloadFactory,
    const armnn::IBackendInternal::IMemoryManagerSharedPtr& memoryManager)
{
    return Debug4dTest<armnn::DataType::QSymmS16>(workloadFactory, memoryManager);
}

LayerTestResult<int16_t, 3> Debug3dInt16Test(
    armnn::IWorkloadFactory& workloadFactory,
    const armnn::IBackendInternal::IMemoryManagerSharedPtr& memoryManager)
{
    return Debug3dTest<armnn::DataType::QSymmS16>(workloadFactory, memoryManager);
}

LayerTestResult<int16_t, 2> Debug2dInt16Test(
    armnn::IWorkloadFactory& workloadFactory,
    const armnn::IBackendInternal::IMemoryManagerSharedPtr& memoryManager)
{
    return Debug2dTest<armnn::DataType::QSymmS16>(workloadFactory, memoryManager);
}

LayerTestResult<int16_t, 1> Debug1dInt16Test(
    armnn::IWorkloadFactory& workloadFactory,
    const armnn::IBackendInternal::IMemoryManagerSharedPtr& memoryManager)
{
    return Debug1dTest<armnn::DataType::QSymmS16>(workloadFactory, memoryManager);
}
