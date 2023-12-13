//
// Copyright © 2020 Arm Ltd. All rights reserved.
// SPDX-License-Identifier: MIT
//

#pragma once

#include <backendsCommon/Workload.hpp>
#include <backendsCommon/WorkloadData.hpp>
#include <neon/workloads/NeonWorkloadUtils.hpp>

#include <armnn/TypesUtils.hpp>
#include <arm_compute/runtime/NEON/functions/NEPermute.h>

#include <string>

namespace armnn
{
arm_compute::Status NeonTransposeWorkloadValidate(const TensorInfo& input, const TensorInfo& output,
                                                  const TransposeDescriptor& descriptor);

class NeonTransposeWorkload : public BaseWorkload<TransposeQueueDescriptor>
{
public:
    static const std::string& GetName()
    {
        static const std::string name = std::string("NeonTransposeWorkload");
        return name;
    }

    NeonTransposeWorkload(const TransposeQueueDescriptor& descriptor, const WorkloadInfo& info);
    void Execute() const override;

private:
    using BaseWorkload<TransposeQueueDescriptor>::m_Data;
    mutable arm_compute::NEPermute m_PermuteFunction;
};

} // namespace armnn
