//
// Copyright © 2017 Arm Ltd. All rights reserved.
// SPDX-License-Identifier: MIT
//

#pragma once

#include <backendsCommon/Workload.hpp>

#include <arm_compute/core/Error.h>
#include <arm_compute/runtime/IFunction.h>
#include <arm_compute/runtime/MemoryManagerOnDemand.h>

#include <memory>

namespace armnn
{

arm_compute::Status NeonNormalizationWorkloadValidate(const TensorInfo& input,
                                                      const TensorInfo& output,
                                                      const NormalizationDescriptor& descriptor);

class NeonNormalizationFloatWorkload : public FloatWorkload<NormalizationQueueDescriptor>
{
public:
    NeonNormalizationFloatWorkload(const NormalizationQueueDescriptor& descriptor, const WorkloadInfo& info,
                                   std::shared_ptr<arm_compute::MemoryManagerOnDemand>& memoryManager);
    virtual void Execute() const override;

private:
    std::unique_ptr<arm_compute::IFunction> m_NormalizationLayer;
};

} //namespace armnn




