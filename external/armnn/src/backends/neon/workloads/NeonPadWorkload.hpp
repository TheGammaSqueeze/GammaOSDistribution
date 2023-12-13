//
// Copyright © 2017 Arm Ltd. All rights reserved.
// SPDX-License-Identifier: MIT
//

#pragma once

#include <backendsCommon/WorkloadData.hpp>
#include <backendsCommon/Workload.hpp>
#include <arm_compute/runtime/IFunction.h>
#include <arm_compute/core/Error.h>

namespace armnn {

class NeonPadWorkload : public BaseWorkload<PadQueueDescriptor>
{
public:
    NeonPadWorkload(const PadQueueDescriptor& descriptor, const WorkloadInfo& info);

    void Execute() const override;

private:
    std::unique_ptr<arm_compute::IFunction> m_Layer;
};

arm_compute::Status NeonPadWorkloadValidate(const TensorInfo& input,
                                            const TensorInfo& output,
                                            const PadDescriptor& descriptor);

} //namespace armnn
