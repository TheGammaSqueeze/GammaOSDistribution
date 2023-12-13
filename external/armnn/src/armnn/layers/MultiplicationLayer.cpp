//
// Copyright © 2017 Arm Ltd and Contributors. All rights reserved.
// SPDX-License-Identifier: MIT
//

#include "MultiplicationLayer.hpp"

#include "LayerCloneBase.hpp"

#include <armnn/TypesUtils.hpp>
#include <backendsCommon/WorkloadData.hpp>
#include <backendsCommon/WorkloadFactory.hpp>

namespace armnn
{

MultiplicationLayer::MultiplicationLayer(const char* name)
    : ElementwiseBaseLayer(2, 1, LayerType::Multiplication, name)
{
}

std::unique_ptr<IWorkload> MultiplicationLayer::CreateWorkload(const IWorkloadFactory& factory) const
{
    MultiplicationQueueDescriptor descriptor;
    SetAdditionalInfo(descriptor);

    return factory.CreateMultiplication(descriptor, PrepInfoAndDesc(descriptor));
}

MultiplicationLayer* MultiplicationLayer::Clone(Graph& graph) const
{
    return CloneBase<MultiplicationLayer>(graph, GetName());
}

void MultiplicationLayer::Accept(ILayerVisitor& visitor) const
{
    visitor.VisitMultiplicationLayer(this, GetName());
}

} // namespace armnn
