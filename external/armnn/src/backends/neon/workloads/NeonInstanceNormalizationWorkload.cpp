//
// Copyright © 2019 Arm Ltd. All rights reserved.
// SPDX-License-Identifier: MIT
//

#include "NeonInstanceNormalizationWorkload.hpp"

#include "NeonWorkloadUtils.hpp"

#include <aclCommon/ArmComputeTensorUtils.hpp>
#include <backendsCommon/CpuTensorHandle.hpp>
#include <neon/NeonTensorHandle.hpp>

using namespace armnn::armcomputetensorutils;

namespace armnn
{

arm_compute::Status NeonInstanceNormalizationWorkloadValidate(const TensorInfo& input,
                                                              const TensorInfo& output,
                                                              const InstanceNormalizationDescriptor& descriptor)
{
    const arm_compute::TensorInfo aclInputInfo  = BuildArmComputeTensorInfo(input, descriptor.m_DataLayout);
    const arm_compute::TensorInfo aclOutputInfo = BuildArmComputeTensorInfo(output, descriptor.m_DataLayout);

    return arm_compute::NEInstanceNormalizationLayer::validate(&aclInputInfo,
                                                               &aclOutputInfo,
                                                               descriptor.m_Gamma,
                                                               descriptor.m_Beta,
                                                               descriptor.m_Eps);
}

NeonInstanceNormalizationWorkload::NeonInstanceNormalizationWorkload(
    const InstanceNormalizationQueueDescriptor& descriptor,
    const WorkloadInfo& info)
    : BaseWorkload<InstanceNormalizationQueueDescriptor>(descriptor, info)
{
    m_Data.ValidateInputsOutputs("NeonInstanceNormalizationWorkload", 1, 1);

    arm_compute::ITensor& input  = static_cast<IAclTensorHandle*>(m_Data.m_Inputs[0])->GetTensor();
    arm_compute::ITensor& output = static_cast<IAclTensorHandle*>(m_Data.m_Outputs[0])->GetTensor();

    arm_compute::DataLayout aclDataLayout = ConvertDataLayout(m_Data.m_Parameters.m_DataLayout);
    input.info()->set_data_layout(aclDataLayout);
    output.info()->set_data_layout(aclDataLayout);

    m_Layer.configure(&input,
                      &output,
                      descriptor.m_Parameters.m_Gamma,
                      descriptor.m_Parameters.m_Beta,
                      descriptor.m_Parameters.m_Eps);
};

void NeonInstanceNormalizationWorkload::Execute() const
{
    ARMNN_SCOPED_PROFILING_EVENT_NEON("NeonInstanceNormalizationWorkload_Execute");
    m_Layer.run();
}

} // namespace armnn