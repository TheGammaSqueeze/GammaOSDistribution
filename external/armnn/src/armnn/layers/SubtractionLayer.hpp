//
// Copyright © 2017 Arm Ltd and Contributors. All rights reserved.
// SPDX-License-Identifier: MIT
//

#pragma once

#include "ElementwiseBaseLayer.hpp"

namespace armnn
{

/// This layer represents a subtraction operation.
class SubtractionLayer : public ElementwiseBaseLayer
{
public:
    /// Makes a workload for the Subtraction type.
    /// @param [in] graph The graph where this layer can be found.
    /// @param [in] factory The workload factory which will create the workload.
    /// @return A pointer to the created workload, or nullptr if not created.
    virtual std::unique_ptr<IWorkload> CreateWorkload(const IWorkloadFactory& factory) const override;

    /// Creates a dynamically-allocated copy of this layer.
    /// @param [in] graph The graph into which this layer is being cloned.
    SubtractionLayer* Clone(Graph& graph) const override;

    void Accept(ILayerVisitor& visitor) const override;

protected:
    /// Constructor to create a SubtractionLayer.
    /// @param [in] name Optional name for the layer.
    SubtractionLayer(const char* name);

    /// Default destructor
    ~SubtractionLayer() = default;
};

} // namespace
