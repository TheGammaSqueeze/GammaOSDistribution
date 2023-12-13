//
// Copyright © 2017 Arm Ltd. All rights reserved.
// SPDX-License-Identifier: MIT
//
#pragma once

#include "armnnOnnxParser/IOnnxParser.hpp"
#include "google/protobuf/repeated_field.h"
#include <unordered_map>

#include <onnx/onnx.pb.h>


namespace armnn
{
class TensorInfo;
enum class ActivationFunction;
}

namespace armnnOnnxParser
{

using ModelPtr = std::unique_ptr<onnx::ModelProto>;

class OnnxParser : public IOnnxParser
{

using OperationParsingFunction = void(OnnxParser::*)(const onnx::NodeProto& NodeProto);

public:

    using GraphPtr = std::unique_ptr<onnx::GraphProto>;

    /// Create the network from a protobuf binary file on disk
    virtual armnn::INetworkPtr CreateNetworkFromBinaryFile(const char* graphFile) override;

    /// Create the network from a protobuf text file on disk
    virtual armnn::INetworkPtr CreateNetworkFromTextFile(const char* graphFile) override;

    /// Create the network directly from protobuf text in a string. Useful for debugging/testing
    virtual armnn::INetworkPtr CreateNetworkFromString(const std::string& protoText) override;

    /// Retrieve binding info (layer id and tensor info) for the network input identified by the given layer name
    virtual BindingPointInfo GetNetworkInputBindingInfo(const std::string& name) const override;

    /// Retrieve binding info (layer id and tensor info) for the network output identified by the given layer name
    virtual BindingPointInfo GetNetworkOutputBindingInfo(const std::string& name) const override;

public:

    OnnxParser();

    static ModelPtr LoadModelFromBinaryFile(const char * fileName);
    static ModelPtr LoadModelFromTextFile(const char * fileName);
    static ModelPtr LoadModelFromString(const std::string& inputString);

    /// Retrieve inputs names
    static std::vector<std::string> GetInputs(ModelPtr& model);

    /// Retrieve outputs names
    static std::vector<std::string> GetOutputs(ModelPtr& model);

private:

    /// Parses a ModelProto loaded into memory from one of the other CreateNetwork*
    armnn::INetworkPtr CreateNetworkFromModel(onnx::ModelProto& model);

    /// Parse every node and make the connection between the resulting tensors
    void LoadGraph();

    void SetupInfo(const google::protobuf::RepeatedPtrField<onnx::ValueInfoProto >* list);

    std::vector<armnn::TensorInfo> ComputeOutputInfo(std::vector<std::string> outNames,
                                                     const armnn::IConnectableLayer* layer,
                                                     std::vector<armnn::TensorShape> inputShapes);

    void DetectFullyConnected();

    template <typename Location>
    void GetInputAndParam(const onnx::NodeProto& node,
                          std::string* inputName,
                          std::string* constName,
                          const Location& location);

    template <typename Location>
    void To1DTensor(const std::string &name, const Location& location);

    //Broadcast Preparation functions
    std::pair<std::string, std::string> AddPrepareBroadcast(const std::string& input0, const std::string& input1);
    void PrependForBroadcast(const std::string& outputName, const std::string& input0, const std::string& input1);

    void AddConvLayerWithDepthwiseConv(const onnx::NodeProto& node, const armnn::Convolution2dDescriptor& convDesc);
    void AddFullyConnected(const onnx::NodeProto& matmulNode, const onnx::NodeProto* addNode = nullptr);
    void AddPoolingLayer(const onnx::NodeProto& nodeProto, armnn::Pooling2dDescriptor& desc);

    void CreateConstantLayer(const std::string& tensorName, const std::string& layerName);
    void CreateReshapeLayer(const std::string& inputName,
                            const std::string& outputName,
                            const std::string& layerName);

    void ParseActivation(const onnx::NodeProto& nodeProto, const armnn::ActivationFunction func);
    void ParseClip(const onnx::NodeProto& nodeProto);
    void ParseSigmoid(const onnx::NodeProto& nodeProto);
    void ParseTanh(const onnx::NodeProto& nodeProto);
    void ParseRelu(const onnx::NodeProto& nodeProto);
    void ParseLeakyRelu(const onnx::NodeProto& nodeProto);

    void ParseAdd(const onnx::NodeProto& nodeProto);
    void ParseAveragePool(const onnx::NodeProto& nodeProto);
    void ParseBatchNormalization(const onnx::NodeProto& node);
    void ParseConstant(const onnx::NodeProto& nodeProto);
    void ParseConv(const onnx::NodeProto& nodeProto);
    void ParseFlatten(const onnx::NodeProto& node);
    void ParseGlobalAveragePool(const onnx::NodeProto& node);
    void ParseMaxPool(const onnx::NodeProto& nodeProto);
    void ParseReshape(const onnx::NodeProto& nodeProto);

    void RegisterInputSlots(armnn::IConnectableLayer* layer, const std::vector<std::string>& tensorIndexes);
    void RegisterOutputSlots(armnn::IConnectableLayer* layer, const std::vector<std::string>& tensorIndexes);

    void SetupInputLayers();
    void SetupOutputLayers();

    void ResetParser();
    void Cleanup();

    std::pair<armnn::ConstTensor, std::unique_ptr<float[]>> CreateConstTensor(const std::string name);

    template <typename TypeList, typename Location>
    void ValidateInputs(const onnx::NodeProto& node,
                        TypeList validInputs,
                        const Location& location);

    /// The network we're building. Gets cleared after it is passed to the user
    armnn::INetworkPtr m_Network;

    /// Ptr to the graph we're building the network from
    GraphPtr m_Graph;

    /// Map of the information for every tensor
    struct OnnxTensor
    {
        std::unique_ptr<armnn::TensorInfo>          m_info;
        std::unique_ptr<const onnx::TensorProto>    m_tensor;
        onnx::TensorProto::DataType                 m_dtype;

        OnnxTensor() : m_info(nullptr), m_tensor(nullptr), m_dtype(onnx::TensorProto::FLOAT) { }
        bool isConstant() { return m_tensor != nullptr; }
    };

    std::unordered_map<std::string, OnnxTensor> m_TensorsInfo;

    /// map of onnx operation names to parsing member functions
    static const std::map<std::string, OperationParsingFunction> m_ParserFunctions;

    /// A mapping of an output slot to each of the input slots it should be connected to
    /// The outputSlot is from the layer that creates this tensor as one of its ouputs
    /// The inputSlots are from the layers that use this tensor as one of their inputs
    struct TensorSlots
    {
        armnn::IOutputSlot* outputSlot;
        std::vector<armnn::IInputSlot*> inputSlots;

        TensorSlots() : outputSlot(nullptr) { }
    };
    /// Map of the tensor names to their connections for the connections of the layers of the graph
    std::unordered_map<std::string, TensorSlots> m_TensorConnections;

    /// Map of the tensor names to their node and index in graph.node()
    std::unordered_map<std::string, std::pair<const onnx::NodeProto*, int>> m_OutputsMap;

    /// Number of times a specific node (identified by his index number) was used as input
    /// and list of the nodes it was fused with
    struct UsageSummary
    {
        std::vector<size_t> fusedWithNodes;
        size_t inputForNodes;

        UsageSummary() : fusedWithNodes({}), inputForNodes(0) { }

    };

    std::vector<UsageSummary> m_OutputsFusedAndUsed;

};
}
