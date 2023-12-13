//
// Copyright © 2017 Arm Ltd and Contributors. All rights reserved.
// SPDX-License-Identifier: MIT
//

#include "PadLayer.hpp"
#include "LayerCloneBase.hpp"

#include <backendsCommon/CpuTensorHandle.hpp>
#include <backendsCommon/WorkloadData.hpp>
#include <backendsCommon/WorkloadFactory.hpp>

#include <cstring>

namespace armnn
{

PadLayer::PadLayer(const armnn::PadDescriptor& param, const char* name)
    : LayerWithParameters(1, 1, LayerType::Pad, param, name)
{}

std::unique_ptr<IWorkload> PadLayer::CreateWorkload(const armnn::IWorkloadFactory& factory) const
{
    PadQueueDescriptor descriptor;
    descriptor.m_Parameters.m_PadList = m_Param.m_PadList;
    SetAdditionalInfo(descriptor);

    return factory.CreatePad(descriptor, PrepInfoAndDesc(descriptor));
}

PadLayer* PadLayer::Clone(Graph& graph) const
{
    auto layer = CloneBase<PadLayer>(graph, m_Param, GetName());

    layer->m_Param.m_PadList = m_Param.m_PadList;

    return std::move(layer);
}

std::vector<TensorShape> PadLayer::InferOutputShapes(const std::vector<TensorShape>& inputShapes) const
{
    ARMNN_ASSERT(inputShapes.size() == 1);
    const TensorShape& inputShape = inputShapes[0];

    unsigned int rank = inputShape.GetNumDimensions();
    ARMNN_ASSERT(m_Param.m_PadList.size() == rank);
    ARMNN_ASSERT(rank != 0);

    std::vector<unsigned int> outputDimensionSizes;
    outputDimensionSizes.reserve(rank);
    for (unsigned int i = 0; i < rank; ++i)
    {
        outputDimensionSizes[i] = inputShape[i] + m_Param.m_PadList[i].first + m_Param.m_PadList[i].second;
    }

    TensorShape tensorShape = TensorShape( rank, outputDimensionSizes.data());
    return std::vector<TensorShape>({ tensorShape });
}

void PadLayer::ValidateTensorShapesFromInputs()
{
    VerifyLayerConnections(1, CHECK_LOCATION());

    const TensorShape& outputShape = GetOutputSlot(0).GetTensorInfo().GetShape();

    VerifyShapeInferenceType(outputShape, m_ShapeInferenceMethod);

    auto inferredShapes = InferOutputShapes({ GetInputSlot(0).GetConnection()->GetTensorInfo().GetShape() });

    ARMNN_ASSERT(inferredShapes.size() == 1);

    ValidateAndCopyShape(outputShape, inferredShapes[0], m_ShapeInferenceMethod, "PadLayer");
}

void PadLayer::Accept(ILayerVisitor& visitor) const
{
    visitor.VisitPadLayer(this, GetParameters(), GetName());
}

} // namespace armnn