//
// Copyright © 2017 Arm Ltd. All rights reserved.
// SPDX-License-Identifier: MIT
//

#include "NeonL2NormalizationFloatWorkload.hpp"

#include "NeonWorkloadUtils.hpp"

#include <aclCommon/ArmComputeUtils.hpp>
#include <armnn/utility/PolymorphicDowncast.hpp>

#include <arm_compute/runtime/NEON/functions/NEL2NormalizeLayer.h>

namespace armnn
{
using namespace armcomputetensorutils;

arm_compute::Status NeonL2NormalizationWorkloadValidate(const TensorInfo& input,
                                                        const TensorInfo& output,
                                                        const L2NormalizationDescriptor& descriptor)
{
    const arm_compute::TensorInfo aclInput = BuildArmComputeTensorInfo(input, descriptor.m_DataLayout);
    const arm_compute::TensorInfo aclOutput = BuildArmComputeTensorInfo(output, descriptor.m_DataLayout);

    int axis = (descriptor.m_DataLayout == DataLayout::NCHW) ? 2 : 0;

    return arm_compute::NEL2NormalizeLayer::validate(&aclInput, &aclOutput, axis, descriptor.m_Eps);
}

NeonL2NormalizationFloatWorkload::NeonL2NormalizationFloatWorkload(const L2NormalizationQueueDescriptor& descriptor,
    const WorkloadInfo& info, std::shared_ptr<arm_compute::MemoryManagerOnDemand>& memoryManager)
    : FloatWorkload<L2NormalizationQueueDescriptor>(descriptor, info)
{
    m_Data.ValidateInputsOutputs("NeonL2NormalizationFloatWorkload", 1, 1);

    arm_compute::ITensor& input = PolymorphicDowncast<IAclTensorHandle*>(m_Data.m_Inputs[0])->GetTensor();
    arm_compute::ITensor& output = PolymorphicDowncast<IAclTensorHandle*>(m_Data.m_Outputs[0])->GetTensor();

    arm_compute::DataLayout aclDataLayout = ConvertDataLayout(m_Data.m_Parameters.m_DataLayout);
    input.info()->set_data_layout(aclDataLayout);
    output.info()->set_data_layout(aclDataLayout);

    int axis = (m_Data.m_Parameters.m_DataLayout == DataLayout::NCHW) ? 2 : 0;

    auto layer = std::make_unique<arm_compute::NEL2NormalizeLayer>(memoryManager);
    layer->configure(&input, &output, axis, m_Data.m_Parameters.m_Eps);
    m_Layer.reset(layer.release());
}

void NeonL2NormalizationFloatWorkload::Execute() const
{
    ARMNN_SCOPED_PROFILING_EVENT_NEON("NeonL2NormalizationFloatWorkload_Execute");
    m_Layer->run();
}

} //namespace armnn
