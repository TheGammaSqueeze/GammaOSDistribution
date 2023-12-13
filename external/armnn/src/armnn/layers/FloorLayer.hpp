//
// Copyright © 2017 Arm Ltd and Contributors. All rights reserved.
// SPDX-License-Identifier: MIT
//
#pragma once

#include <Layer.hpp>

namespace armnn
{

/// This layer represents a floor operation.
class FloorLayer : public Layer
{
public:
    /// Makes a workload for the Floor type.
    /// @param [in] graph The graph where this layer can be found.
    /// @param [in] factory The workload factory which will create the workload.
    /// @return A pointer to the created workload, or nullptr if not created.
    virtual std::unique_ptr<IWorkload> CreateWorkload(const IWorkloadFactory& factory) const override;

    /// Creates a dynamically-allocated copy of this layer.
    /// @param [in] graph The graph into which this layer is being cloned.
    FloorLayer* Clone(Graph& graph) const override;

    /// Check if the input tensor shape(s)
    /// will lead to a valid configuration of @ref FloorLayer.
    /// @param [in] shapeInferenceMethod Indicates if output shape shall be overwritten or just validate.
    void ValidateTensorShapesFromInputs() override;

    void Accept(ILayerVisitor& visitor) const override;

protected:
    /// Constructor to create a FloorLayer.
    /// @param [in] name Optional name for the layer.
    FloorLayer(const char* name);

    /// Default destructor
    ~FloorLayer() = default;
};

} // namespace
