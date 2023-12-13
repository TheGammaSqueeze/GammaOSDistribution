//
// Copyright © 2017 Arm Ltd. All rights reserved.
// SPDX-License-Identifier: MIT
//

#include <armnn/Descriptors.hpp>
#include <armnn/IRuntime.hpp>
#include <armnn/INetwork.hpp>

#include <boost/test/unit_test.hpp>

#include <set>

BOOST_AUTO_TEST_SUITE(FlowControl)

BOOST_AUTO_TEST_CASE(ErrorOnLoadNetwork)
{
    using namespace armnn;

    // Create runtime in which test will run
    IRuntime::CreationOptions options;
    IRuntimePtr runtime(IRuntime::Create(options));

    // build up the structure of the network
    // It's equivalent to something like
    // if (0) {} else {}
    INetworkPtr net(INetwork::Create());

    std::vector<uint8_t> falseData = {0};
    ConstTensor falseTensor(armnn::TensorInfo({1}, armnn::DataType::Boolean), falseData);
    IConnectableLayer* constLayer = net->AddConstantLayer(falseTensor, "const");
    constLayer->GetOutputSlot(0).SetTensorInfo(armnn::TensorInfo({1}, armnn::DataType::Boolean));

    IConnectableLayer* input = net->AddInputLayer(0);
    input->GetOutputSlot(0).SetTensorInfo(armnn::TensorInfo({1}, armnn::DataType::Boolean));

    IConnectableLayer* switchLayer = net->AddSwitchLayer("switch");
    switchLayer->GetOutputSlot(0).SetTensorInfo(armnn::TensorInfo({1}, armnn::DataType::Boolean));
    switchLayer->GetOutputSlot(1).SetTensorInfo(armnn::TensorInfo({1}, armnn::DataType::Boolean));

    IConnectableLayer* mergeLayer = net->AddMergeLayer("merge");
    mergeLayer->GetOutputSlot(0).SetTensorInfo(armnn::TensorInfo({1}, armnn::DataType::Boolean));

    IConnectableLayer* output = net->AddOutputLayer(0);

    input->GetOutputSlot(0).Connect(switchLayer->GetInputSlot(0));
    constLayer->GetOutputSlot(0).Connect(switchLayer->GetInputSlot(1));
    switchLayer->GetOutputSlot(0).Connect(mergeLayer->GetInputSlot(0));
    switchLayer->GetOutputSlot(1).Connect(mergeLayer->GetInputSlot(1));
    mergeLayer->GetOutputSlot(0).Connect(output->GetInputSlot(0));

    // optimize the network
    std::vector<BackendId> backends = {Compute::CpuRef};
    std::vector<std::string> errMessages;

    try
    {
        Optimize(*net, backends, runtime->GetDeviceSpec(), OptimizerOptions(), errMessages);
        BOOST_FAIL("Should have thrown an exception.");
    }
    catch (const InvalidArgumentException& e)
    {
        // Different exceptions are thrown on different backends
    }
    BOOST_TEST(errMessages.size() > 0);
}

BOOST_AUTO_TEST_SUITE_END()
