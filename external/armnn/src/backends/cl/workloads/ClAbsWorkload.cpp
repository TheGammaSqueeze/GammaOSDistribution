//
// Copyright © 2017 Arm Ltd. All rights reserved.
// SPDX-License-Identifier: MIT
//

#include "ClAbsWorkload.hpp"

#include "ClWorkloadUtils.hpp"

#include <armnn/utility/PolymorphicDowncast.hpp>

#include <aclCommon/ArmComputeTensorUtils.hpp>

#include <cl/ClTensorHandle.hpp>

namespace armnn
{

arm_compute::Status ClAbsWorkloadValidate(const TensorInfo& input, const TensorInfo& output)
{
    const arm_compute::TensorInfo aclInput  = armcomputetensorutils::BuildArmComputeTensorInfo(input);
    const arm_compute::TensorInfo aclOutput = armcomputetensorutils::BuildArmComputeTensorInfo(output);

    return arm_compute::CLAbsLayer::validate(&aclInput, &aclOutput);
}

ClAbsWorkload::ClAbsWorkload(const AbsQueueDescriptor& descriptor, const WorkloadInfo& info)
    : BaseWorkload<AbsQueueDescriptor>(descriptor, info)
{
    m_Data.ValidateInputsOutputs("ClAbsWorkload", 1, 1);

    arm_compute::ICLTensor& input  = PolymorphicDowncast<ClTensorHandle*>(m_Data.m_Inputs[0])->GetTensor();
    arm_compute::ICLTensor& output = PolymorphicDowncast<ClTensorHandle*>(m_Data.m_Outputs[0])->GetTensor();

    m_AbsLayer.configure(&input, &output);
}

void ClAbsWorkload::Execute() const
{
    ARMNN_SCOPED_PROFILING_EVENT_CL("ClAbsWorkload_Execute");
    RunClFunction(m_AbsLayer, CHECK_LOCATION());
}

} // namespace armnn
