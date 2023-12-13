//
// Copyright © 2019 Arm Ltd and Contributors. All rights reserved.
// SPDX-License-Identifier: MIT
//

#pragma once

#include "LayerWithParameters.hpp"

namespace armnn
{

/// This layer represents a log softmax operation.
class LogSoftmaxLayer : public LayerWithParameters<LogSoftmaxDescriptor>
{
public:
    /// Makes a workload for the LogSoftmax type.
    /// @param [in] graph The graph where this layer can be found.
    /// @param [in] factory The workload factory which will create the workload.
    /// @return A pointer to the created workload, or nullptr if not created.
    virtual std::unique_ptr<IWorkload> CreateWorkload(const IWorkloadFactory& factory) const override;

    /// Creates a dynamically-allocated copy of this layer.
    /// @param [in] graph The graph into which this layer is being cloned.
    LogSoftmaxLayer* Clone(Graph& graph) const override;

    /// Check if the input tensor shape(s)
    /// will lead to a valid configuration of @ref LogSoftmaxLayer.
    /// @param [in] shapeInferenceMethod Indicates if output shape shall be overwritten or just validated.
    void ValidateTensorShapesFromInputs() override;

    void Accept(ILayerVisitor& visitor) const override;

protected:
    /// Constructor to create a LogSoftmaxLayer.
    /// @param [in] param LogSoftmaxDescriptor to configure the log softmax operation.
    /// @param [in] name Optional name for the layer.
    LogSoftmaxLayer(const LogSoftmaxDescriptor& param, const char* name);

    /// Default destructor
    ~LogSoftmaxLayer() = default;
};

} // namespace
