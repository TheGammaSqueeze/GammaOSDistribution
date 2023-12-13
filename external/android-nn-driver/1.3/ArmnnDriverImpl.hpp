//
// Copyright © 2020 Arm Ltd. All rights reserved.
// SPDX-License-Identifier: MIT
//

#pragma once

#include <HalInterfaces.h>

#include "../DriverOptions.hpp"

#include <armnn/ArmNN.hpp>

using namespace android::nn;

namespace V1_0 = ::android::hardware::neuralnetworks::V1_0;
namespace V1_2 = ::android::hardware::neuralnetworks::V1_2;
namespace V1_3 = ::android::hardware::neuralnetworks::V1_3;

namespace armnn_driver
{
namespace hal_1_3
{

class ArmnnDriverImpl
{
public:
    static android::hardware::Return<V1_3::ErrorStatus> prepareArmnnModel_1_3(const armnn::IRuntimePtr& runtime,
                                                           const armnn::IGpuAccTunedParametersPtr& clTunedParameters,
                                                           const DriverOptions& options,
                                                           const V1_3::Model& model,
                                                           const android::sp<V1_3::IPreparedModelCallback>& cb,
                                                           bool float32ToFloat16 = false,
                                                           V1_3::Priority priority = V1_3::Priority::MEDIUM);

    static android::hardware::Return<void> getCapabilities_1_3(const armnn::IRuntimePtr& runtime,
                                            V1_3::IDevice::getCapabilities_1_3_cb cb);
};

} // namespace hal_1_3
} // namespace armnn_driver
