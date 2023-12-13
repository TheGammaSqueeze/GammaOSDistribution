//
// Copyright © 2020 Arm Ltd and Contributors. All rights reserved.
// SPDX-License-Identifier: MIT
//

#pragma once

#include <backendsCommon/Workload.hpp>

#include <arm_compute/core/Error.h>
#include <arm_compute/runtime/CL/functions/CLLogicalOr.h>

namespace armnn
{

arm_compute::Status ClLogicalOrWorkloadValidate(const TensorInfo& input0,
                                                const TensorInfo& input1,
                                                const TensorInfo& output);

class ClLogicalOrWorkload : public BaseWorkload<LogicalBinaryQueueDescriptor>
{
public:
    ClLogicalOrWorkload(const LogicalBinaryQueueDescriptor& descriptor, const WorkloadInfo& info);
    virtual void Execute() const override;

private:
    mutable arm_compute::CLLogicalOr m_LogicalOrLayer;
};

} //namespace armnn
