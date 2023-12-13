//
// Copyright © 2019 Arm Ltd. All rights reserved.
// SPDX-License-Identifier: MIT
//

#pragma once

#include <armnn/Descriptors.hpp>

#include <backendsCommon/Workload.hpp>

#include <arm_compute/runtime/NEON/functions/NEDepthToSpaceLayer.h>

namespace armnn
{

arm_compute::Status NeonDepthToSpaceWorkloadValidate(const TensorInfo& input,
                                                     const TensorInfo& output,
                                                     const DepthToSpaceDescriptor& descriptor);

class NeonDepthToSpaceWorkload : public BaseWorkload<DepthToSpaceQueueDescriptor>
{
public:
    NeonDepthToSpaceWorkload(const DepthToSpaceQueueDescriptor& descriptor, const WorkloadInfo& info);
    void Execute() const override;

private:
    mutable arm_compute::NEDepthToSpaceLayer m_Layer;
};

} // namespace armnn
