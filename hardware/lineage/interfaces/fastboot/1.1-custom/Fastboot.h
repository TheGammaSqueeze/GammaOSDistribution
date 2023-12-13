/*
 * Copyright (C) 2020 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#pragma once

#include <android/hardware/fastboot/1.1/IFastboot.h>
#include <hidl/Status.h>

namespace android {
namespace hardware {
namespace fastboot {
namespace V1_1 {
namespace implementation {

#define FB_OEM_GET_PROP "getprop"

using ::android::hardware::hidl_string;
using ::android::hardware::Return;
using ::android::hardware::Void;
using ::android::hardware::fastboot::V1_0::FileSystemType;
using ::android::hardware::fastboot::V1_0::Status;
using ::android::hardware::fastboot::V1_0::Result;

struct Fastboot : public IFastboot {
    // Methods from ::android::hardware::fastboot::V1_0::IFastboot follow.
    Return<void> getPartitionType(const hidl_string& partitionName,
                                  getPartitionType_cb _hidl_cb) override;
    Return<void> doOemCommand(const hidl_string& oemCmd, doOemCommand_cb _hidl_cb) override;
    Return<void> getVariant(getVariant_cb _hidl_cb) override;
    Return<void> getOffModeChargeState(getOffModeChargeState_cb _hidl_cb) override;
    Return<void> getBatteryVoltageFlashingThreshold(
            getBatteryVoltageFlashingThreshold_cb _hidl_cb) override;
    Return<void> doOemSpecificErase(doOemSpecificErase_cb _hidl_cb) override;
};

extern "C" IFastboot* HIDL_FETCH_IFastboot(const char* name);

}  // namespace implementation
}  // namespace V1_1
}  // namespace fastboot
}  // namespace hardware
}  // namespace android
