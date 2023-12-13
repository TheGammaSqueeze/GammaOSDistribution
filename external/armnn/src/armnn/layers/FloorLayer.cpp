//
// Copyright © 2017 Arm Ltd and Contributors. All rights reserved.
// SPDX-License-Identifier: MIT
//
#include "FloorLayer.hpp"

#include "LayerCloneBase.hpp"

#include <armnn/TypesUtils.hpp>
#include <backendsCommon/WorkloadData.hpp>
#include <backendsCommon/WorkloadFactory.hpp>

namespace armnn
{

FloorLayer::FloorLayer(const char* name)
 : Layer(1, 1, LayerType::Floor, name)
{
}

std::unique_ptr<IWorkload> FloorLayer::CreateWorkload(const IWorkloadFactory& factory) const
{
    FloorQueueDescriptor descriptor;
    SetAdditionalInfo(descriptor);

    return factory.CreateFloor(descriptor, PrepInfoAndDesc(descriptor));
}

FloorLayer* FloorLayer::Clone(Graph& graph) const
{
    return CloneBase<FloorLayer>(graph, GetName());
}

void FloorLayer::ValidateTensorShapesFromInputs()
{
    VerifyLayerConnections(1, CHECK_LOCATION());

    const TensorShape& outputShape = GetOutputSlot(0).GetTensorInfo().GetShape();

    VerifyShapeInferenceType(outputShape, m_ShapeInferenceMethod);

    auto inferredShapes = InferOutputShapes({ GetInputSlot(0).GetConnection()->GetTensorInfo().GetShape() });
    ARMNN_ASSERT(inferredShapes.size() == 1);

    ValidateAndCopyShape(outputShape, inferredShapes[0], m_ShapeInferenceMethod, "FloorLayer");
}

void FloorLayer::Accept(ILayerVisitor& visitor) const
{
    visitor.VisitFloorLayer(this, GetName());
}

} // namespace armnn
