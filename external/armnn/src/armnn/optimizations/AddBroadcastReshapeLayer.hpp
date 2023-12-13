//
// Copyright © 2020 Arm Ltd and Contributors. All rights reserved.
// SPDX-License-Identifier: MIT
//
#pragma once

#include "Optimization.hpp"

#include <armnn/utility/IgnoreUnused.hpp>
#include <armnn/utility/PolymorphicDowncast.hpp>

namespace armnn
{
namespace optimizations
{

static const std::set<armnn::LayerType> broadcastOps {
    LayerType::Addition,
    LayerType::Division,
    LayerType::Maximum,
    LayerType::Minimum,
    LayerType::Multiplication,
    LayerType::Subtraction
};

class AddBroadcastReshapeLayerImpl
{
public:
    /// Run for every ElementwiseBaseLayer. Add Broadcast reshape layer if the inputs shape are different.
    void Run(Graph& graph, Layer& layer) const
    {
        if (std::find(broadcastOps.begin(), broadcastOps.end(), layer.GetType()) != broadcastOps.end())
        {
            layer.GetInputSlot(0).GetConnectedOutputSlot()->IsTensorInfoSet();
            layer.GetInputSlot(1).GetConnectedOutputSlot()->IsTensorInfoSet();

            const TensorInfo &inputInfo0 = layer.GetInputSlot(0).GetConnectedOutputSlot()->GetTensorInfo();
            const TensorInfo &inputInfo1 = layer.GetInputSlot(1).GetConnectedOutputSlot()->GetTensorInfo();

            if (inputInfo0.GetNumDimensions() == inputInfo1.GetNumDimensions())
            {
                return;
            }

            unsigned int reshapeSlot = 1;
            TensorInfo reshapeInfo = inputInfo1;
            TensorInfo inputInfo = inputInfo0;

            if (inputInfo0.GetNumDimensions() < inputInfo1.GetNumDimensions())
            {
                reshapeSlot = 0;
                reshapeInfo = inputInfo0;
                inputInfo = inputInfo1;
            }

            uint32_t numDimensions = inputInfo.GetNumDimensions();

            std::vector<unsigned> reshapedDim;
            for (unsigned int i = 0; i < reshapeInfo.GetNumDimensions(); ++i)
            {
                reshapedDim.push_back(reshapeInfo.GetShape()[i]);
            }

            std::vector<unsigned int> reshapedDimensions(numDimensions, 1);
            std::copy_backward (reshapedDim.begin(), reshapedDim.end(), reshapedDimensions.end());

            reshapeInfo.SetShape(armnn::TensorShape{ numDimensions, reshapedDimensions.data() });
            const std::string layerName = "Reshape_for:" + layer.GetNameStr() + "-" + std::to_string(reshapeSlot);
            const ReshapeDescriptor descriptor{reshapeInfo.GetShape()};
            ReshapeLayer *reshapeLayer = graph.InsertNewLayer<ReshapeLayer>(layer.GetInputSlot(reshapeSlot),
                                                                            descriptor,
                                                                            layerName.c_str());
            reshapeLayer->GetOutputSlot().SetTensorInfo(reshapeInfo);
        }
    }

protected:
    AddBroadcastReshapeLayerImpl() = default;
    ~AddBroadcastReshapeLayerImpl() = default;
};

using AddBroadcastReshapeLayer = OptimizeForType<Layer, AddBroadcastReshapeLayerImpl>;

} // namespace optimizations
} // namespace armnn
