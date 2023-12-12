//
// Copyright © 2019 Arm Ltd and Contributors. All rights reserved.
// SPDX-License-Identifier: MIT
//

#include <Filesystem.hpp>
#include <LabelsAndEventClasses.hpp>
#include <ProfilingService.hpp>
#include "ProfilingTestUtils.hpp"
#include "PrintPacketHeaderHandler.hpp"
#include <Runtime.hpp>
#include "TestTimelinePacketHandler.hpp"

#include <boost/test/unit_test.hpp>

#include <cstdio>
#include <sstream>
#include <sys/stat.h>

using namespace armnn::profiling;
using namespace armnn;

using namespace std::chrono_literals;

class FileOnlyHelperService : public ProfilingService
{
    public:
    // Wait for a notification from the send thread
    bool WaitForPacketsSent(uint32_t timeout = 1000)
    {
        return ProfilingService::WaitForPacketSent(m_ProfilingService, timeout);
    }
    armnn::profiling::ProfilingService m_ProfilingService;
};

BOOST_AUTO_TEST_SUITE(FileOnlyProfilingDecoratorTests)

BOOST_AUTO_TEST_CASE(TestFileOnlyProfiling)
{
    // Get all registered backends
    std::vector<BackendId> suitableBackends = GetSuitableBackendRegistered();

    // Run test for each backend separately
    for (auto const& backend : suitableBackends)
    {
        // Enable m_FileOnly but also provide ILocalPacketHandler which should consume the packets.
        // This won't dump anything to file.
        armnn::Runtime::CreationOptions creationOptions;
        creationOptions.m_ProfilingOptions.m_EnableProfiling     = true;
        creationOptions.m_ProfilingOptions.m_FileOnly            = true;
        creationOptions.m_ProfilingOptions.m_CapturePeriod       = 100;
        creationOptions.m_ProfilingOptions.m_TimelineEnabled     = true;
        ILocalPacketHandlerSharedPtr localPacketHandlerPtr = std::make_shared<TestTimelinePacketHandler>();
        creationOptions.m_ProfilingOptions.m_LocalPacketHandlers.push_back(localPacketHandlerPtr);

        armnn::Runtime runtime(creationOptions);
        // ensure the GUID generator is reset to zero
        GetProfilingService(&runtime).ResetGuidGenerator();

        // Load a simple network
        // build up the structure of the network
        INetworkPtr net(INetwork::Create());

        IConnectableLayer* input = net->AddInputLayer(0, "input");

        ElementwiseUnaryDescriptor descriptor(UnaryOperation::Rsqrt);
        IConnectableLayer* Rsqrt = net->AddElementwiseUnaryLayer(descriptor, "Rsqrt");

        IConnectableLayer* output = net->AddOutputLayer(0, "output");

        input->GetOutputSlot(0).Connect(Rsqrt->GetInputSlot(0));
        Rsqrt->GetOutputSlot(0).Connect(output->GetInputSlot(0));

        input->GetOutputSlot(0).SetTensorInfo(TensorInfo({ 1, 1, 4, 4 }, DataType::Float32));
        Rsqrt->GetOutputSlot(0).SetTensorInfo(TensorInfo({ 1, 1, 4, 4 }, DataType::Float32));

        std::vector<armnn::BackendId> backendsVec {backend};
        IOptimizedNetworkPtr optNet = Optimize(*net, backendsVec, runtime.GetDeviceSpec());

        // Load it into the runtime. It should succeed.
        armnn::NetworkId netId;
        BOOST_TEST(runtime.LoadNetwork(netId, std::move(optNet)) == Status::Success);

        // Creates structures for input & output.
        std::vector<float> inputData(16);
        std::vector<float> outputData(16);
        for (unsigned int i = 0; i < 16; ++i) {
            inputData[i] = 9.0;
            outputData[i] = 3.0;
        }

        InputTensors inputTensors
        {
            {0, ConstTensor(runtime.GetInputTensorInfo(netId, 0), inputData.data())}
        };
        OutputTensors outputTensors
        {
            {0, Tensor(runtime.GetOutputTensorInfo(netId, 0), outputData.data())}
        };

        // Does the inference.
        runtime.EnqueueWorkload(netId, inputTensors, outputTensors);

        static_cast<TestTimelinePacketHandler *>(localPacketHandlerPtr.get())->WaitOnInferenceCompletion(3000);

        const TimelineModel &model =
                static_cast<TestTimelinePacketHandler *>(localPacketHandlerPtr.get())->GetTimelineModel();

        for (auto &error : model.GetErrors()) {
            std::cout << error.what() << std::endl;
        }
        BOOST_TEST(model.GetErrors().empty());
        std::vector<std::string> desc = GetModelDescription(model);
        std::vector<std::string> expectedOutput;
        expectedOutput.push_back("Entity [0] name = input type = layer");
        expectedOutput.push_back("   connection [17] from entity [0] to entity [1]");
        expectedOutput.push_back("   child: Entity [26] backendId = " + backend.Get() + " type = workload");
        expectedOutput.push_back("Entity [1] name = Rsqrt type = layer");
        expectedOutput.push_back("   connection [25] from entity [1] to entity [2]");
        expectedOutput.push_back("   child: Entity [18] backendId = " + backend.Get() + " type = workload");
        expectedOutput.push_back("Entity [2] name = output type = layer");
        expectedOutput.push_back("   child: Entity [30] backendId = " + backend.Get() + " type = workload");
        expectedOutput.push_back("Entity [6] processId = [processId] type = network");
        expectedOutput.push_back("   child: Entity [0] name = input type = layer");
        expectedOutput.push_back("   child: Entity [1] name = Rsqrt type = layer");
        expectedOutput.push_back("   child: Entity [2] name = output type = layer");
        expectedOutput.push_back("   execution: Entity [34] type = inference");
        expectedOutput.push_back("   event: [8] class [start_of_life]");
        expectedOutput.push_back("Entity [18] backendId = " + backend.Get() + " type = workload");
        expectedOutput.push_back("   execution: Entity [47] type = workload_execution");
        expectedOutput.push_back("Entity [26] backendId = " + backend.Get() + " type = workload");
        expectedOutput.push_back("   execution: Entity [39] type = workload_execution");
        expectedOutput.push_back("Entity [30] backendId = " + backend.Get() + " type = workload");
        expectedOutput.push_back("   execution: Entity [55] type = workload_execution");
        expectedOutput.push_back("Entity [34] type = inference");
        expectedOutput.push_back("   child: Entity [39] type = workload_execution");
        expectedOutput.push_back("   child: Entity [47] type = workload_execution");
        expectedOutput.push_back("   child: Entity [55] type = workload_execution");
        expectedOutput.push_back("   event: [37] class [start_of_life]");
        expectedOutput.push_back("   event: [63] class [end_of_life]");
        expectedOutput.push_back("Entity [39] type = workload_execution");
        expectedOutput.push_back("   event: [43] class [start_of_life]");
        expectedOutput.push_back("   event: [45] class [end_of_life]");
        expectedOutput.push_back("Entity [47] type = workload_execution");
        expectedOutput.push_back("   event: [51] class [start_of_life]");
        expectedOutput.push_back("   event: [53] class [end_of_life]");
        expectedOutput.push_back("Entity [55] type = workload_execution");
        expectedOutput.push_back("   event: [59] class [start_of_life]");
        expectedOutput.push_back("   event: [61] class [end_of_life]");
        BOOST_TEST(CompareOutput(desc, expectedOutput));
    }
}

BOOST_AUTO_TEST_CASE(DumpOutgoingValidFileEndToEnd)
{
    // Get all registered backends
    std::vector<BackendId> suitableBackends = GetSuitableBackendRegistered();

    // Run test for each backend separately
    for (auto const& backend : suitableBackends)
    {
        // Create a temporary file name.
        fs::path tempPath = armnnUtils::Filesystem::NamedTempFile("DumpOutgoingValidFileEndToEnd_CaptureFile.txt");
        // Make sure the file does not exist at this point
        BOOST_CHECK(!fs::exists(tempPath));

        armnn::Runtime::CreationOptions options;
        options.m_ProfilingOptions.m_EnableProfiling     = true;
        options.m_ProfilingOptions.m_FileOnly            = true;
        options.m_ProfilingOptions.m_IncomingCaptureFile = "";
        options.m_ProfilingOptions.m_OutgoingCaptureFile = tempPath.string();
        options.m_ProfilingOptions.m_CapturePeriod       = 100;
        options.m_ProfilingOptions.m_TimelineEnabled     = true;

        ILocalPacketHandlerSharedPtr localPacketHandlerPtr = std::make_shared<TestTimelinePacketHandler>();
        options.m_ProfilingOptions.m_LocalPacketHandlers.push_back(localPacketHandlerPtr);

        armnn::Runtime runtime(options);
        // ensure the GUID generator is reset to zero
        GetProfilingService(&runtime).ResetGuidGenerator();

        // Load a simple network
        // build up the structure of the network
        INetworkPtr net(INetwork::Create());

        IConnectableLayer* input = net->AddInputLayer(0, "input");

        ElementwiseUnaryDescriptor descriptor(UnaryOperation::Rsqrt);
        IConnectableLayer* Rsqrt = net->AddElementwiseUnaryLayer(descriptor, "Rsqrt");

        IConnectableLayer* output = net->AddOutputLayer(0, "output");

        input->GetOutputSlot(0).Connect(Rsqrt->GetInputSlot(0));
        Rsqrt->GetOutputSlot(0).Connect(output->GetInputSlot(0));

        input->GetOutputSlot(0).SetTensorInfo(TensorInfo({ 1, 1, 4, 4 }, DataType::Float32));
        Rsqrt->GetOutputSlot(0).SetTensorInfo(TensorInfo({ 1, 1, 4, 4 }, DataType::Float32));


        std::vector<BackendId> backendsVec{backend};
        IOptimizedNetworkPtr optNet = Optimize(*net, backendsVec, runtime.GetDeviceSpec());

        // Load it into the runtime. It should succeed.
        armnn::NetworkId netId;
        BOOST_TEST(runtime.LoadNetwork(netId, std::move(optNet)) == Status::Success);

        // Creates structures for input & output.
        std::vector<float> inputData(16);
        std::vector<float> outputData(16);
        for (unsigned int i = 0; i < 16; ++i) {
            inputData[i] = 9.0;
            outputData[i] = 3.0;
        }

        InputTensors inputTensors
        {
            {0, ConstTensor(runtime.GetInputTensorInfo(netId, 0), inputData.data())}
        };
        OutputTensors outputTensors
        {
            {0, Tensor(runtime.GetOutputTensorInfo(netId, 0), outputData.data())}
        };

        // Does the inference.
        runtime.EnqueueWorkload(netId, inputTensors, outputTensors);

        static_cast<TestTimelinePacketHandler *>(localPacketHandlerPtr.get())->WaitOnInferenceCompletion(3000);

        // In order to flush the files we need to gracefully close the profiling service.
        options.m_ProfilingOptions.m_EnableProfiling = false;
        GetProfilingService(&runtime).ResetExternalProfilingOptions(options.m_ProfilingOptions, true);

        // The output file size should be greater than 0.
        BOOST_CHECK(fs::file_size(tempPath) > 0);

        // NOTE: would be an interesting exercise to take this file and decode it

        // Delete the tmp file.
        BOOST_CHECK(fs::remove(tempPath));
    }
}

BOOST_AUTO_TEST_SUITE_END()
