/*
 * Copyright (c) 2017-2020, The Linux Foundation. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above
 *       copyright notice, this list of conditions and the following
 *       disclaimer in the documentation and/or other materials provided
 *       with the distribution.
 *     * Neither the name of The Linux Foundation nor the names of its
 *       contributors may be used to endorse or promote products derived
 *       from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
 * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
 * IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 * Not a contribution.
 */

/*
 *  Copyright 2018-2020 NXP
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */

#ifndef VENDOR_NXP_HARDWARE_NFC_V2_0_NQNFC_H
#define VENDOR_NXP_HARDWARE_NFC_V2_0_NQNFC_H

#include <vendor/nxp/hardware/nfc/2.0/INqNfc.h>
#include <hidl/MQDescriptor.h>
#include <hidl/Status.h>

enum Constants : uint16_t {
    HAL_NFC_ESE_HARD_RESET = 5,
};


namespace vendor {
namespace nxp {
namespace hardware {
namespace nfc {
namespace V2_0 {
namespace implementation {

using ::android::hidl::base::V1_0::IBase;
using ::vendor::nxp::hardware::nfc::V2_0::INqNfc;
using ::android::hardware::hidl_vec;
using ::android::hardware::Return;
using ::android::hardware::Void;

struct NqNfc : public INqNfc {
    // Methods from ::vendor::nxp::hardware::nfc::V2_0::INqNfc follow.
    Return<void> getNfcChipId(getNfcChipId_cb _hidl_cb);
    Return<void> getNfcFirmwareVersion(getNfcFirmwareVersion_cb _hidl_cb);
    Return<void> getVendorParam(const ::android::hardware::hidl_string &key,
          getVendorParam_cb _hidl_cb) override;
    Return<bool> setVendorParam(const ::android::hardware::hidl_string &key,
          const ::android::hardware::hidl_string &value) override;
    Return<bool> resetEse(uint64_t resetType) override;
    Return<bool> setEseUpdateState(NxpNfcHalEseState state) override;
    Return<bool> setNxpTransitConfig(const ::android::hardware::hidl_string &strval) override;
    Return<bool> isJcopUpdateRequired() override;
    Return<bool> isLsUpdateRequired() override;
};

}  // namespace implementation
}  // namespace V2_0
}  // namespace nfc
}  // namespace hardware
}  // namespace nxp
}  // namespace vendor

#endif  // VENDOR_NXP_HARDWARE_NFC_V2_0_NQNFC_H
