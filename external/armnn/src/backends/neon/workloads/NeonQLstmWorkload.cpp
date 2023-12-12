//
// Copyright © 2020 Arm Ltd and Contributors. All rights reserved.
// SPDX-License-Identifier: MIT
//

#include "NeonQLstmWorkload.hpp"
#include "NeonWorkloadUtils.hpp"

#include "aclCommon/ArmComputeTensorUtils.hpp"

#include "neon/NeonTensorHandle.hpp"

namespace armnn
{
using namespace armcomputetensorutils;

NeonQLstmWorkload::NeonQLstmWorkload(const QLstmQueueDescriptor& descriptor, const WorkloadInfo& info)
        : BaseWorkload<QLstmQueueDescriptor>(descriptor, info)
{
    arm_compute::LSTMParams<arm_compute::ITensor> qLstmParams;

    // Mandatory params
    m_InputToForgetWeightsTensor = std::make_unique<arm_compute::Tensor>();
    BuildArmComputeTensor(*m_InputToForgetWeightsTensor, m_Data.m_InputToForgetWeights->GetTensorInfo());

    m_InputToCellWeightsTensor = std::make_unique<arm_compute::Tensor>();
    BuildArmComputeTensor(*m_InputToCellWeightsTensor, m_Data.m_InputToCellWeights->GetTensorInfo());

    m_InputToOutputWeightsTensor = std::make_unique<arm_compute::Tensor>();
    BuildArmComputeTensor(*m_InputToOutputWeightsTensor, m_Data.m_InputToOutputWeights->GetTensorInfo());

    m_RecurrentToForgetWeightsTensor = std::make_unique<arm_compute::Tensor>();
    BuildArmComputeTensor(*m_RecurrentToForgetWeightsTensor, m_Data.m_RecurrentToForgetWeights->GetTensorInfo());

    m_RecurrentToCellWeightsTensor = std::make_unique<arm_compute::Tensor>();
    BuildArmComputeTensor(*m_RecurrentToCellWeightsTensor, m_Data.m_RecurrentToCellWeights->GetTensorInfo());

    m_RecurrentToOutputWeightsTensor = std::make_unique<arm_compute::Tensor>();
    BuildArmComputeTensor(*m_RecurrentToOutputWeightsTensor, m_Data.m_RecurrentToOutputWeights->GetTensorInfo());

    m_ForgetGateBiasTensor = std::make_unique<arm_compute::Tensor>();
    BuildArmComputeTensor(*m_ForgetGateBiasTensor, m_Data.m_ForgetGateBias->GetTensorInfo());

    m_CellBiasTensor = std::make_unique<arm_compute::Tensor>();
    BuildArmComputeTensor(*m_CellBiasTensor, m_Data.m_CellBias->GetTensorInfo());

    m_OutputGateBiasTensor = std::make_unique<arm_compute::Tensor>();
    BuildArmComputeTensor(*m_OutputGateBiasTensor, m_Data.m_OutputGateBias->GetTensorInfo());

    // Create tensors for optional params if they are enabled
    if (m_Data.m_Parameters.m_PeepholeEnabled)
    {
        m_CellToInputWeightsTensor = std::make_unique<arm_compute::Tensor>();

        if (!m_Data.m_Parameters.m_CifgEnabled)
        {
            // In ACL this is categorised as a CIFG param and not a Peephole param
            BuildArmComputeTensor(*m_CellToInputWeightsTensor, m_Data.m_CellToInputWeights->GetTensorInfo());
        }

        m_CellToForgetWeightsTensor = std::make_unique<arm_compute::Tensor>();
        BuildArmComputeTensor(*m_CellToForgetWeightsTensor, m_Data.m_CellToForgetWeights->GetTensorInfo());

        m_CellToOutputWeightsTensor = std::make_unique<arm_compute::Tensor>();
        BuildArmComputeTensor(*m_CellToOutputWeightsTensor, m_Data.m_CellToOutputWeights->GetTensorInfo());

        // Set Peephole params
        qLstmParams.set_peephole_params(m_CellToForgetWeightsTensor.get(),
                                        m_CellToOutputWeightsTensor.get());
    }

    if (m_Data.m_Parameters.m_ProjectionEnabled)
    {
        m_ProjectionWeightsTensor = std::make_unique<arm_compute::Tensor>();
        BuildArmComputeTensor(*m_ProjectionWeightsTensor, m_Data.m_ProjectionWeights->GetTensorInfo());

        m_ProjectionBiasTensor = std::make_unique<arm_compute::Tensor>();
        if (m_Data.m_ProjectionBias != nullptr)
        {
            BuildArmComputeTensor(*m_ProjectionBiasTensor, m_Data.m_ProjectionBias->GetTensorInfo());
        }

        // Set projection params
        qLstmParams.set_projection_params(
            m_ProjectionWeightsTensor.get(),
            m_Data.m_ProjectionBias != nullptr ? m_ProjectionBiasTensor.get() : nullptr);
    }

    if (m_Data.m_Parameters.m_LayerNormEnabled)
    {
        m_InputLayerNormWeightsTensor = std::make_unique<arm_compute::Tensor>();

        if (!m_Data.m_Parameters.m_CifgEnabled)
        {
            BuildArmComputeTensor(*m_InputLayerNormWeightsTensor, m_Data.m_InputLayerNormWeights->GetTensorInfo());
        }

        m_ForgetLayerNormWeightsTensor = std::make_unique<arm_compute::Tensor>();
        BuildArmComputeTensor(*m_ForgetLayerNormWeightsTensor, m_Data.m_ForgetLayerNormWeights->GetTensorInfo());

        m_CellLayerNormWeightsTensor = std::make_unique<arm_compute::Tensor>();
        BuildArmComputeTensor(*m_CellLayerNormWeightsTensor, m_Data.m_CellLayerNormWeights->GetTensorInfo());

        m_OutputLayerNormWeightsTensor = std::make_unique<arm_compute::Tensor>();
        BuildArmComputeTensor(*m_OutputLayerNormWeightsTensor, m_Data.m_OutputLayerNormWeights->GetTensorInfo());

        // Set layer norm params
        qLstmParams.set_layer_normalization_params(
            m_Data.m_InputLayerNormWeights != nullptr ? m_InputLayerNormWeightsTensor.get() : nullptr,
            m_ForgetLayerNormWeightsTensor.get(),
            m_CellLayerNormWeightsTensor.get(),
            m_OutputLayerNormWeightsTensor.get());
    }

    if (!m_Data.m_Parameters.m_CifgEnabled)
    {
        m_InputToInputWeightsTensor = std::make_unique<arm_compute::Tensor>();
        BuildArmComputeTensor(*m_InputToInputWeightsTensor, m_Data.m_InputToInputWeights->GetTensorInfo());

        m_RecurrentToInputWeightsTensor = std::make_unique<arm_compute::Tensor>();
        BuildArmComputeTensor(*m_RecurrentToInputWeightsTensor, m_Data.m_RecurrentToInputWeights->GetTensorInfo());

        m_InputGateBiasTensor = std::make_unique<arm_compute::Tensor>();
        BuildArmComputeTensor(*m_InputGateBiasTensor, m_Data.m_InputGateBias->GetTensorInfo());

        // Set CIFG params
        qLstmParams.set_cifg_params(
            m_InputToInputWeightsTensor.get(),
            m_RecurrentToInputWeightsTensor.get(),
            m_Data.m_CellToInputWeights != nullptr ? m_CellToInputWeightsTensor.get() : nullptr,
            m_InputGateBiasTensor.get());
    }

    // Input/Output tensors
    const arm_compute::ITensor& input         = static_cast<IAclTensorHandle*>(m_Data.m_Inputs[0])->GetTensor();
    arm_compute::ITensor& outputStateIn = static_cast<IAclTensorHandle*>(m_Data.m_Inputs[1])->GetTensor();
    const arm_compute::ITensor& cellStateIn   = static_cast<IAclTensorHandle*>(m_Data.m_Inputs[2])->GetTensor();

    arm_compute::ITensor& outputStateOut = static_cast<IAclTensorHandle*>(m_Data.m_Outputs[0])->GetTensor();
    arm_compute::ITensor& cellStateOut   = static_cast<IAclTensorHandle*>(m_Data.m_Outputs[1])->GetTensor();
    arm_compute::ITensor& output         = static_cast<IAclTensorHandle*>(m_Data.m_Outputs[2])->GetTensor();

    // Set scalar descriptor params
    qLstmParams.set_cell_clip_params(m_Data.m_Parameters.m_CellClip);
    qLstmParams.set_projection_clip_params(m_Data.m_Parameters.m_ProjectionClip);
    qLstmParams.set_hidden_state_params(m_Data.m_Parameters.m_HiddenStateZeroPoint,
                                        m_Data.m_Parameters.m_HiddenStateScale);
    qLstmParams.set_matmul_scale_params(m_Data.m_Parameters.m_InputIntermediateScale,
                                        m_Data.m_Parameters.m_ForgetIntermediateScale,
                                        m_Data.m_Parameters.m_CellIntermediateScale,
                                        m_Data.m_Parameters.m_OutputIntermediateScale);

    // QLSTM NEON configure
    m_QLstmLayer.configure(&input,
                           m_InputToForgetWeightsTensor.get(),
                           m_InputToCellWeightsTensor.get(),
                           m_InputToOutputWeightsTensor.get(),
                           m_RecurrentToForgetWeightsTensor.get(),
                           m_RecurrentToCellWeightsTensor.get(),
                           m_RecurrentToOutputWeightsTensor.get(),
                           m_ForgetGateBiasTensor.get(),
                           m_CellBiasTensor.get(),
                           m_OutputGateBiasTensor.get(),
                           &cellStateIn,
                           &outputStateIn,
                           &cellStateOut,
                           &outputStateOut,
                           &output,
                           qLstmParams);

    // Initialise ACL tensor data for mandatory params
    InitializeArmComputeTensorData(*m_InputToForgetWeightsTensor, m_Data.m_InputToForgetWeights);
    InitializeArmComputeTensorData(*m_InputToCellWeightsTensor,   m_Data.m_InputToCellWeights);
    InitializeArmComputeTensorData(*m_InputToOutputWeightsTensor, m_Data.m_InputToOutputWeights);

    InitializeArmComputeTensorData(*m_RecurrentToForgetWeightsTensor, m_Data.m_RecurrentToForgetWeights);
    InitializeArmComputeTensorData(*m_RecurrentToCellWeightsTensor,   m_Data.m_RecurrentToCellWeights);
    InitializeArmComputeTensorData(*m_RecurrentToOutputWeightsTensor, m_Data.m_RecurrentToOutputWeights);

    InitializeArmComputeTensorData(*m_ForgetGateBiasTensor, m_Data.m_ForgetGateBias);
    InitializeArmComputeTensorData(*m_CellBiasTensor,       m_Data.m_CellBias);
    InitializeArmComputeTensorData(*m_OutputGateBiasTensor, m_Data.m_OutputGateBias);

    // Initialise ACL tensor data for optional params
    if (!m_Data.m_Parameters.m_CifgEnabled)
    {
        InitializeArmComputeTensorData(*m_InputToInputWeightsTensor,     m_Data.m_InputToInputWeights);
        InitializeArmComputeTensorData(*m_RecurrentToInputWeightsTensor, m_Data.m_RecurrentToInputWeights);
        InitializeArmComputeTensorData(*m_InputGateBiasTensor,           m_Data.m_InputGateBias);
    }

    if (m_Data.m_Parameters.m_ProjectionEnabled)
    {
        InitializeArmComputeTensorData(*m_ProjectionWeightsTensor, m_Data.m_ProjectionWeights);

        if (m_Data.m_ProjectionBias != nullptr)
        {
            InitializeArmComputeTensorData(*m_ProjectionBiasTensor, m_Data.m_ProjectionBias);
        }
    }

    if (m_Data.m_Parameters.m_PeepholeEnabled)
    {
        if (!m_Data.m_Parameters.m_CifgEnabled)
        {
            InitializeArmComputeTensorData(*m_CellToInputWeightsTensor, m_Data.m_CellToInputWeights);
        }

        InitializeArmComputeTensorData(*m_CellToForgetWeightsTensor, m_Data.m_CellToForgetWeights);
        InitializeArmComputeTensorData(*m_CellToOutputWeightsTensor, m_Data.m_CellToOutputWeights);
    }

    if (m_Data.m_Parameters.m_LayerNormEnabled)
    {
        if (!m_Data.m_Parameters.m_CifgEnabled)
        {
            InitializeArmComputeTensorData(*m_InputLayerNormWeightsTensor, m_Data.m_InputLayerNormWeights);
        }

        InitializeArmComputeTensorData(*m_ForgetLayerNormWeightsTensor, m_Data.m_ForgetLayerNormWeights);
        InitializeArmComputeTensorData(*m_CellLayerNormWeightsTensor,   m_Data.m_CellLayerNormWeights);
        InitializeArmComputeTensorData(*m_OutputLayerNormWeightsTensor, m_Data.m_OutputLayerNormWeights);
    }

    // QLSTM NEON prepare
    m_QLstmLayer.prepare();

    FreeUnusedTensors();
}

void NeonQLstmWorkload::Execute() const
{
    m_QLstmLayer.run();
}

arm_compute::Status NeonQLstmWorkloadValidate(const TensorInfo& input,
                                              const TensorInfo& cellStateIn,
                                              const TensorInfo& outputStateIn,
                                              const TensorInfo& cellStateOut,
                                              const TensorInfo& outputStateOut,
                                              const TensorInfo& output,
                                              const QLstmDescriptor& descriptor,
                                              const LstmInputParamsInfo& paramsInfo)
{
    arm_compute::LSTMParams<arm_compute::ITensorInfo> aclParamsInfo;

    // Input/Output tensor info
    const arm_compute::TensorInfo aclInputInfo         = BuildArmComputeTensorInfo(input);
    const arm_compute::TensorInfo aclOutputStateInInfo = BuildArmComputeTensorInfo(outputStateIn);
    const arm_compute::TensorInfo aclCellStateInInfo   = BuildArmComputeTensorInfo(cellStateIn);

    const arm_compute::TensorInfo aclOutputStateOutInfo = BuildArmComputeTensorInfo(outputStateOut);
    const arm_compute::TensorInfo aclCellStateOutInfo   = BuildArmComputeTensorInfo(cellStateOut);
    const arm_compute::TensorInfo aclOutputInfo         = BuildArmComputeTensorInfo(output);

    // Mandatory tensor info
    const arm_compute::TensorInfo aclInputToForgetWeightsInfo
            = BuildArmComputeTensorInfo(paramsInfo.GetInputToForgetWeights());
    const arm_compute::TensorInfo aclInputToCellWeightsInfo
            = BuildArmComputeTensorInfo(paramsInfo.GetInputToCellWeights());
    const arm_compute::TensorInfo aclInputToOutputWeightsInfo
            = BuildArmComputeTensorInfo(paramsInfo.GetInputToOutputWeights());
    const arm_compute::TensorInfo aclRecurrentToForgetWeightsInfo
            = BuildArmComputeTensorInfo(paramsInfo.GetRecurrentToForgetWeights());
    const arm_compute::TensorInfo aclRecurrentToCellWeightsInfo
            = BuildArmComputeTensorInfo(paramsInfo.GetRecurrentToCellWeights());
    const arm_compute::TensorInfo aclRecurrentToOutputWeightsInfo
            = BuildArmComputeTensorInfo(paramsInfo.GetRecurrentToOutputWeights());
    const arm_compute::TensorInfo aclForgetGateBiasInfo
            = BuildArmComputeTensorInfo(paramsInfo.GetForgetGateBias());
    const arm_compute::TensorInfo aclCellBiasInfo
            = BuildArmComputeTensorInfo(paramsInfo.GetCellBias());
    const arm_compute::TensorInfo aclOutputGateBiasInfo
            = BuildArmComputeTensorInfo(paramsInfo.GetOutputGateBias());

    // Optional tensor info
    arm_compute::TensorInfo aclInputToInputWeightsInfo;
    arm_compute::TensorInfo aclRecurrentToInputWeightsInfo;

    arm_compute::TensorInfo aclCellToInputWeightsInfo;
    arm_compute::TensorInfo aclCellToForgetWeightsInfo;
    arm_compute::TensorInfo aclCellToOutputWeightsInfo;

    arm_compute::TensorInfo aclInputGateBiasInfo;

    arm_compute::TensorInfo aclProjectionWeightsInfo;
    arm_compute::TensorInfo aclProjectionBiasInfo;

    arm_compute::TensorInfo aclInputLayerNormWeightsInfo;
    arm_compute::TensorInfo aclForgetLayerNormWeightsInfo;
    arm_compute::TensorInfo aclCellLayerNormWeightsInfo;
    arm_compute::TensorInfo aclOutputLayerNormWeightsInfo;

    // Create tensor info for optional params if they are enabled
    if (descriptor.m_PeepholeEnabled)
    {
        if (!descriptor.m_CifgEnabled)
        {
            aclCellToInputWeightsInfo = BuildArmComputeTensorInfo(paramsInfo.GetCellToInputWeights());
        }

        aclCellToForgetWeightsInfo = BuildArmComputeTensorInfo(paramsInfo.GetCellToForgetWeights());
        aclCellToOutputWeightsInfo = BuildArmComputeTensorInfo(paramsInfo.GetCellToOutputWeights());

        // Set peephole params info
        aclParamsInfo.set_peephole_params(&aclCellToForgetWeightsInfo,
                                          &aclCellToOutputWeightsInfo);
    }

    if (descriptor.m_ProjectionEnabled)
    {
        aclProjectionWeightsInfo = BuildArmComputeTensorInfo(paramsInfo.GetProjectionWeights());

        if (paramsInfo.m_ProjectionBias != nullptr)
        {
            aclProjectionBiasInfo = BuildArmComputeTensorInfo(paramsInfo.GetProjectionBias());
        }

        // Set projection params info
        aclParamsInfo.set_projection_params(
            &aclProjectionWeightsInfo,
            paramsInfo.m_ProjectionBias != nullptr ? &aclProjectionBiasInfo : nullptr);
    }

    if (descriptor.m_LayerNormEnabled)
    {
        if (!descriptor.m_CifgEnabled)
        {
            aclInputLayerNormWeightsInfo = BuildArmComputeTensorInfo(paramsInfo.GetInputLayerNormWeights());
        }

        aclForgetLayerNormWeightsInfo = BuildArmComputeTensorInfo(paramsInfo.GetForgetLayerNormWeights());
        aclCellLayerNormWeightsInfo   = BuildArmComputeTensorInfo(paramsInfo.GetCellLayerNormWeights());
        aclOutputLayerNormWeightsInfo = BuildArmComputeTensorInfo(paramsInfo.GetOutputLayerNormWeights());

        // Set layer norm params info
        aclParamsInfo.set_layer_normalization_params(
            paramsInfo.m_InputLayerNormWeights != nullptr ? &aclInputLayerNormWeightsInfo : nullptr,
            &aclForgetLayerNormWeightsInfo,
            &aclCellLayerNormWeightsInfo,
            &aclOutputLayerNormWeightsInfo);
    }

    if (!descriptor.m_CifgEnabled)
    {
        aclInputToInputWeightsInfo     = BuildArmComputeTensorInfo(paramsInfo.GetInputToInputWeights());
        aclRecurrentToInputWeightsInfo = BuildArmComputeTensorInfo(paramsInfo.GetRecurrentToInputWeights());
        aclInputGateBiasInfo           = BuildArmComputeTensorInfo(paramsInfo.GetInputGateBias());

        // Set CIFG params info
        aclParamsInfo.set_cifg_params(
            &aclInputToInputWeightsInfo,
            &aclRecurrentToInputWeightsInfo,
            paramsInfo.m_CellToInputWeights != nullptr ? &aclCellToInputWeightsInfo : nullptr,
            &aclInputGateBiasInfo);
    }

    // Set scalar descriptor params
    aclParamsInfo.set_cell_clip_params(descriptor.m_CellClip);
    aclParamsInfo.set_projection_clip_params(descriptor.m_ProjectionClip);
    aclParamsInfo.set_hidden_state_params(descriptor.m_HiddenStateZeroPoint, descriptor.m_HiddenStateScale);
    aclParamsInfo.set_matmul_scale_params(descriptor.m_InputIntermediateScale,
                                          descriptor.m_ForgetIntermediateScale,
                                          descriptor.m_CellIntermediateScale,
                                          descriptor.m_OutputIntermediateScale);

    // QLSTM NEON validate
    return arm_compute::NEQLSTMLayer::validate(&aclInputInfo,
                                               &aclInputToForgetWeightsInfo,
                                               &aclInputToCellWeightsInfo,
                                               &aclInputToOutputWeightsInfo,
                                               &aclRecurrentToForgetWeightsInfo,
                                               &aclRecurrentToCellWeightsInfo,
                                               &aclRecurrentToOutputWeightsInfo,
                                               &aclForgetGateBiasInfo,
                                               &aclCellBiasInfo,
                                               &aclOutputGateBiasInfo,
                                               &aclCellStateInInfo,
                                               &aclOutputStateInInfo,
                                               &aclCellStateOutInfo,
                                               &aclOutputStateOutInfo,
                                               &aclOutputInfo,
                                               aclParamsInfo);
}

void NeonQLstmWorkload::FreeUnusedTensors()
{
    FreeTensorIfUnused(m_InputToInputWeightsTensor);
    FreeTensorIfUnused(m_InputToForgetWeightsTensor);
    FreeTensorIfUnused(m_InputToCellWeightsTensor);
    FreeTensorIfUnused(m_InputToOutputWeightsTensor);

    FreeTensorIfUnused(m_RecurrentToInputWeightsTensor);
    FreeTensorIfUnused(m_RecurrentToForgetWeightsTensor);
    FreeTensorIfUnused(m_RecurrentToCellWeightsTensor);
    FreeTensorIfUnused(m_RecurrentToOutputWeightsTensor);

    FreeTensorIfUnused(m_CellToInputWeightsTensor);
    FreeTensorIfUnused(m_CellToForgetWeightsTensor);
    FreeTensorIfUnused(m_CellToOutputWeightsTensor);

    FreeTensorIfUnused(m_InputGateBiasTensor);
    FreeTensorIfUnused(m_ForgetGateBiasTensor);
    FreeTensorIfUnused(m_CellBiasTensor);
    FreeTensorIfUnused(m_OutputGateBiasTensor);

    FreeTensorIfUnused(m_ProjectionWeightsTensor);
    FreeTensorIfUnused(m_ProjectionBiasTensor);

    FreeTensorIfUnused(m_InputLayerNormWeightsTensor);
    FreeTensorIfUnused(m_ForgetLayerNormWeightsTensor);
    FreeTensorIfUnused(m_CellLayerNormWeightsTensor);
    FreeTensorIfUnused(m_OutputLayerNormWeightsTensor);
}

} //namespace armnn