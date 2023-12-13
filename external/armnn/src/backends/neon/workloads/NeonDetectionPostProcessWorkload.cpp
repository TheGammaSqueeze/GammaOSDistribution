//
// Copyright © 2019 Arm Ltd. All rights reserved.
// SPDX-License-Identifier: MIT
//

#include "NeonDetectionPostProcessWorkload.hpp"

#include "NeonWorkloadUtils.hpp"

#include <aclCommon/ArmComputeTensorHandle.hpp>
#include <aclCommon/ArmComputeTensorUtils.hpp>
#include <armnn/utility/PolymorphicDowncast.hpp>

namespace armnn
{

arm_compute::DetectionPostProcessLayerInfo MakeInfo(const DetectionPostProcessDescriptor& desc)
{
    return arm_compute::DetectionPostProcessLayerInfo(desc.m_MaxDetections,
                                                      desc.m_MaxClassesPerDetection,
                                                      desc.m_NmsScoreThreshold,
                                                      desc.m_NmsIouThreshold,
                                                      desc.m_NumClasses,
                                                      { desc.m_ScaleX,
                                                        desc.m_ScaleY,
                                                        desc.m_ScaleW,
                                                        desc.m_ScaleH },
                                                      desc.m_UseRegularNms,
                                                      desc.m_DetectionsPerClass);
}

arm_compute::Status NeonDetectionPostProcessValidate(const TensorInfo& boxEncodings,
                                                     const TensorInfo& scores,
                                                     const TensorInfo& anchors,
                                                     const TensorInfo& detectionBoxes,
                                                     const TensorInfo& detectionClasses,
                                                     const TensorInfo& detectionScores,
                                                     const TensorInfo& numDetections,
                                                     const DetectionPostProcessDescriptor &desc)
{
    arm_compute::DetectionPostProcessLayerInfo info = MakeInfo(desc);

    const arm_compute::TensorInfo aclBoxEncodings =
        armcomputetensorutils::BuildArmComputeTensorInfo(boxEncodings);

    const arm_compute::TensorInfo aclScores =
        armcomputetensorutils::BuildArmComputeTensorInfo(scores);

    const arm_compute::TensorInfo aclAnchors =
        armcomputetensorutils::BuildArmComputeTensorInfo(anchors);

    arm_compute::TensorInfo aclDetectionBoxes =
        armcomputetensorutils::BuildArmComputeTensorInfo(detectionBoxes);

    arm_compute::TensorInfo aclDetectionClasses =
        armcomputetensorutils::BuildArmComputeTensorInfo(detectionClasses);

    arm_compute::TensorInfo aclDetectionScores =
        armcomputetensorutils::BuildArmComputeTensorInfo(detectionScores);

    arm_compute::TensorInfo aclNumDetections =
        armcomputetensorutils::BuildArmComputeTensorInfo(numDetections);

    return arm_compute::NEDetectionPostProcessLayer::validate(
            &aclBoxEncodings,
            &aclScores,
            &aclAnchors,
            &aclDetectionBoxes,
            &aclDetectionClasses,
            &aclDetectionScores,
            &aclNumDetections,
            info);
}

NeonDetectionPostProcessWorkload::NeonDetectionPostProcessWorkload(
    const DetectionPostProcessQueueDescriptor& descriptor,
    const WorkloadInfo& info)
    : BaseWorkload<DetectionPostProcessQueueDescriptor>(descriptor, info)
{
    m_Anchors = std::make_unique<arm_compute::Tensor>();
    BuildArmComputeTensor(*m_Anchors, descriptor.m_Anchors->GetTensorInfo());

    arm_compute::DetectionPostProcessLayerInfo di = MakeInfo(m_Data.m_Parameters);

    auto AclTensorRef = [](ITensorHandle* tensor) -> arm_compute::ITensor&
        {
            return PolymorphicDowncast<IAclTensorHandle*>(tensor)->GetTensor();
        };

    arm_compute::ITensor& boxEncodings  = AclTensorRef(m_Data.m_Inputs[0]);
    arm_compute::ITensor& scores        = AclTensorRef(m_Data.m_Inputs[1]);

    arm_compute::ITensor& detectionBoxes    = AclTensorRef(m_Data.m_Outputs[0]);
    arm_compute::ITensor& detectionClasses  = AclTensorRef(m_Data.m_Outputs[1]);
    arm_compute::ITensor& detectionScores   = AclTensorRef(m_Data.m_Outputs[2]);
    arm_compute::ITensor& numDetections     = AclTensorRef(m_Data.m_Outputs[3]);

    m_Func.configure(&boxEncodings, &scores, m_Anchors.get(),
                     &detectionBoxes, &detectionClasses, &detectionScores, &numDetections,
                     di);

    InitializeArmComputeTensorData(*m_Anchors, m_Data.m_Anchors);
}

void NeonDetectionPostProcessWorkload::Execute() const
{
    ARMNN_SCOPED_PROFILING_EVENT_NEON("NeonDetectionPostProcessWorkload_Execute");
    m_Func.run();
}

} // namespace armnn
