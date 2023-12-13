//
// Copyright © 2017 Arm Ltd. All rights reserved.
// SPDX-License-Identifier: MIT
//

#include "ClQuantizeWorkload.hpp"
#include "ClWorkloadUtils.hpp"

#include <aclCommon/ArmComputeUtils.hpp>
#include <aclCommon/ArmComputeTensorUtils.hpp>

#include <backendsCommon/CpuTensorHandle.hpp>

#include <cl/ClLayerSupport.hpp>
#include <cl/ClTensorHandle.hpp>
#include <cl/ClLayerSupport.hpp>

namespace armnn
{
using namespace armcomputetensorutils;

arm_compute::Status ClQuantizeWorkloadValidate(const TensorInfo& input,
                                               const TensorInfo& output)
{
    const arm_compute::TensorInfo aclInputInfo  = BuildArmComputeTensorInfo(input);
    const arm_compute::TensorInfo aclOutputInfo = BuildArmComputeTensorInfo(output);

    return arm_compute::CLQuantizationLayer::validate(&aclInputInfo,
                                                      &aclOutputInfo);
}

ClQuantizeWorkload::ClQuantizeWorkload(const QuantizeQueueDescriptor& descriptor, const WorkloadInfo& info)
    : BaseWorkload<QuantizeQueueDescriptor>(descriptor, info)
{
    m_Data.ValidateInputsOutputs("ClQuantizeWorkload", 1, 1);

    arm_compute::ICLTensor& input  = static_cast<IClTensorHandle*>(m_Data.m_Inputs[0])->GetTensor();
    arm_compute::ICLTensor& output = static_cast<IClTensorHandle*>(m_Data.m_Outputs[0])->GetTensor();

    m_Layer.configure(&input, &output);
}

void ClQuantizeWorkload::Execute() const
{
    ARMNN_SCOPED_PROFILING_EVENT_CL("ClQuantizeWorkload_Execute");
    RunClFunction(m_Layer, CHECK_LOCATION());
}

} //namespace armnn
