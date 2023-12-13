//
// Copyright © 2017 Arm Ltd and Contributors. All rights reserved.
// SPDX-License-Identifier: MIT
//
#pragma once

#include <Layer.hpp>

namespace armnn
{

/// This layer converts data type Float 32 to Float 16.
class ConvertFp32ToFp16Layer : public Layer
{
public:
    /// Makes a workload for the ConvertFp32ToFp16 type.
    /// @param [in] factory The workload factory which will create the workload.
    /// @return A pointer to the created workload, or nullptr if not created.
    virtual std::unique_ptr<IWorkload> CreateWorkload(const IWorkloadFactory& factory) const override;

    /// Creates a dynamically-allocated copy of this layer.
    /// @param [in] graph The graph into which this layer is being cloned.
    ConvertFp32ToFp16Layer* Clone(Graph& graph) const override;

    /// Check if the input tensor shape(s)
    /// will lead to a valid configuration of @ref ConvertFp32ToFp16Layer.
    /// @param [in] shapeInferenceMethod Indicates if output shape shall be overwritten or just validated.
    void ValidateTensorShapesFromInputs() override;

    void Accept(ILayerVisitor& visitor) const override;

protected:
    /// Constructor to create a ConvertFp32ToFp16Layer.
    /// @param [in] name Optional name for the layer.
    ConvertFp32ToFp16Layer(const char* name);

    /// Default destructor
    ~ConvertFp32ToFp16Layer() = default;
};

} // namespace
