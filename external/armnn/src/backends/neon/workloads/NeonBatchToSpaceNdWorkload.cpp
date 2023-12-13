//
// Copyright © 2020 Arm Ltd. All rights reserved.
// SPDX-License-Identifier: MIT
//

#include "NeonBatchToSpaceNdWorkload.hpp"

#include "NeonWorkloadUtils.hpp"

#include <armnn/utility/NumericCast.hpp>
#include <armnn/utility/PolymorphicDowncast.hpp>

#include <ResolveType.hpp>

namespace armnn
{

using namespace armcomputetensorutils;

arm_compute::Status NeonBatchToSpaceNdWorkloadValidate(const TensorInfo& input,
                                                       const TensorInfo& output,
                                                       const BatchToSpaceNdDescriptor& desc)
{
    const arm_compute::TensorInfo aclInputInfo = BuildArmComputeTensorInfo(input, desc.m_DataLayout);
    const arm_compute::TensorInfo aclOutputInfo = BuildArmComputeTensorInfo(output, desc.m_DataLayout);

    // ArmNN blockShape is [H, W] Cl asks for W, H
    int32_t blockHeight = armnn::numeric_cast<int32_t>(desc.m_BlockShape[0]);
    int32_t blockWidth = armnn::numeric_cast<int32_t>(desc.m_BlockShape[1]);

    const arm_compute::Status aclStatus = arm_compute::NEBatchToSpaceLayer::validate(&aclInputInfo,
                                                                                     blockWidth,
                                                                                     blockHeight,
                                                                                     &aclOutputInfo);
    return aclStatus;
}

NeonBatchToSpaceNdWorkload::NeonBatchToSpaceNdWorkload(const BatchToSpaceNdQueueDescriptor& desc,
                                                       const WorkloadInfo& info)
    : BaseWorkload<BatchToSpaceNdQueueDescriptor>(desc, info)
{
    m_Data.ValidateInputsOutputs("NeonBatchToSpaceNdWorkload", 1, 1);

    arm_compute::ITensor& input  =
            armnn::PolymorphicPointerDowncast<IAclTensorHandle>(m_Data.m_Inputs[0])->GetTensor();
    arm_compute::ITensor& output =
            armnn::PolymorphicPointerDowncast<IAclTensorHandle>(m_Data.m_Outputs[0])->GetTensor();

    arm_compute::DataLayout aclDataLayout = ConvertDataLayout(m_Data.m_Parameters.m_DataLayout);
    input.info()->set_data_layout(aclDataLayout);
    output.info()->set_data_layout(aclDataLayout);

    // ArmNN blockShape is [H, W] Cl asks for W, H
    int32_t blockHeight = armnn::numeric_cast<int32_t>(desc.m_Parameters.m_BlockShape[0]);
    int32_t blockWidth = armnn::numeric_cast<int32_t>(desc.m_Parameters.m_BlockShape[1]);

    m_Layer.reset(new arm_compute::NEBatchToSpaceLayer());
    m_Layer->configure(&input, blockWidth, blockHeight, &output);
    m_Layer->prepare();
}

void NeonBatchToSpaceNdWorkload::Execute() const
{
    if (m_Layer)
    {
        ARMNN_SCOPED_PROFILING_EVENT_NEON("NeonSpaceToBatchNdWorkload_Execute");
        m_Layer->run();
    }
}

} //namespace armnn
