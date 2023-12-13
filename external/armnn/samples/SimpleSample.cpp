//
// Copyright © 2017 Arm Ltd. All rights reserved.
// SPDX-License-Identifier: MIT
//
#include <armnn/INetwork.hpp>
#include <armnn/IRuntime.hpp>
#include <armnn/Utils.hpp>
#include <armnn/Descriptors.hpp>

#include <iostream>

/// A simple example of using the ArmNN SDK API. In this sample, the users single input number is multiplied by 1.0f
/// using a fully connected layer with a single neuron to produce an output number that is the same as the input.
int main()
{
    using namespace armnn;

    float number;
    std::cout << "Please enter a number: " << std::endl;
    std::cin >> number;

    // Turn on logging to standard output
    // This is useful in this sample so that users can learn more about what is going on
    armnn::ConfigureLogging(true, false, LogSeverity::Warning);

    // Construct ArmNN network
    armnn::NetworkId networkIdentifier;
    INetworkPtr myNetwork = INetwork::Create();

    armnn::FullyConnectedDescriptor fullyConnectedDesc;
    float weightsData[] = {1.0f}; // Identity
    TensorInfo weightsInfo(TensorShape({1, 1}), DataType::Float32);
    armnn::ConstTensor weights(weightsInfo, weightsData);
    IConnectableLayer *fullyConnected = myNetwork->AddFullyConnectedLayer(fullyConnectedDesc,
                                                                          weights,
                                                                          EmptyOptional(),
                                                                          "fully connected");

    IConnectableLayer *InputLayer = myNetwork->AddInputLayer(0);
    IConnectableLayer *OutputLayer = myNetwork->AddOutputLayer(0);

    InputLayer->GetOutputSlot(0).Connect(fullyConnected->GetInputSlot(0));
    fullyConnected->GetOutputSlot(0).Connect(OutputLayer->GetInputSlot(0));

    // Create ArmNN runtime
    IRuntime::CreationOptions options; // default options
    IRuntimePtr run = IRuntime::Create(options);

    //Set the tensors in the network.
    TensorInfo inputTensorInfo(TensorShape({1, 1}), DataType::Float32);
    InputLayer->GetOutputSlot(0).SetTensorInfo(inputTensorInfo);

    TensorInfo outputTensorInfo(TensorShape({1, 1}), DataType::Float32);
    fullyConnected->GetOutputSlot(0).SetTensorInfo(outputTensorInfo);

    // Optimise ArmNN network
    armnn::IOptimizedNetworkPtr optNet = Optimize(*myNetwork, {Compute::CpuRef}, run->GetDeviceSpec());
    if (!optNet)
    {
        // This shouldn't happen for this simple sample, with reference backend.
        // But in general usage Optimize could fail if the hardware at runtime cannot
        // support the model that has been provided.
        std::cerr << "Error: Failed to optimise the input network." << std::endl;
        return 1;
    }

    // Load graph into runtime
    run->LoadNetwork(networkIdentifier, std::move(optNet));

    //Creates structures for inputs and outputs.
    std::vector<float> inputData{number};
    std::vector<float> outputData(1);


    armnn::InputTensors inputTensors{{0, armnn::ConstTensor(run->GetInputTensorInfo(networkIdentifier, 0),
                                                            inputData.data())}};
    armnn::OutputTensors outputTensors{{0, armnn::Tensor(run->GetOutputTensorInfo(networkIdentifier, 0),
                                                         outputData.data())}};

    // Execute network
    run->EnqueueWorkload(networkIdentifier, inputTensors, outputTensors);

    std::cout << "Your number was " << outputData[0] << std::endl;
    return 0;

}
