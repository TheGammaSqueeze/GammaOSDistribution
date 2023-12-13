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

#include <hardware/hardware.h>
#include <log/log.h>
#include "NqNfc.h"
#include "phNxpNciHal.h"
#include "phNxpNciHal_Adaptation.h"

namespace vendor {
namespace nxp {
namespace hardware {
namespace nfc {
namespace V2_0 {
namespace implementation {

// Methods from ::vendor::nxp::hardware::nfc::V2_0::INqNfc follow.
Return<void> NqNfc::getNfcChipId(getNfcChipId_cb _hidl_cb) {
    std::string value = phNxpNciHal_getNfcChipId();
    _hidl_cb(value);
    return Void();
}

Return<void> NqNfc::getNfcFirmwareVersion(getNfcFirmwareVersion_cb _hidl_cb) {
    std::string value = phNxpNciHal_getNfcFirmwareVersion();
    _hidl_cb(value);
    return Void();
}

Return<void> NqNfc::getVendorParam(const ::android::hardware::hidl_string &key,
                          getVendorParam_cb _hidl_cb) {
    string val = phNxpNciHal_getSystemProperty(key);
    _hidl_cb(val);
    return Void();
}

Return<bool> NqNfc::setVendorParam(const ::android::hardware::hidl_string &key,
                          const ::android::hardware::hidl_string &value) {
    return phNxpNciHal_setSystemProperty(key, value);
}

Return<bool> NqNfc::resetEse(uint64_t resetType) {
    NFCSTATUS status = NFCSTATUS_FAILED;
    bool ret = false;

    ALOGD("NqNfc::resetEse Entry");
    status = phNxpNciHal_resetEse(resetType);
    if(NFCSTATUS_SUCCESS == status) {
        ret = true;
        status = NFCSTATUS_SUCCESS;
        ALOGD("HAL_NFC_ESE_HARD_RESET completed");
    } else {
        ALOGD("HAL_NFC_ESE_HARD_RESET failed");
    }
    ALOGD("NqNfc::resetEse Exit");
    return ret;
}

Return<bool> NqNfc::setEseUpdateState(NxpNfcHalEseState eSEState) {
    bool status = false;

    ALOGD("NqNfc::setEseUpdateState Entry");

    if(eSEState == NxpNfcHalEseState::HAL_NFC_ESE_JCOP_UPDATE_COMPLETED
            || eSEState == NxpNfcHalEseState::HAL_NFC_ESE_LS_UPDATE_COMPLETED) {
        ALOGD("NqNfc::setEseUpdateState state == HAL_NFC_ESE_JCOP_UPDATE_COMPLETED");
        seteSEClientState((uint8_t)eSEState);
        eSEClientUpdate_NFC_Thread();
    }
    if (eSEState == NxpNfcHalEseState::HAL_NFC_ESE_UPDATE_COMPLETED) {
        status = phNxpNciHal_Abort();
    }
    ALOGD("NqNfc::setEseUpdateState Exit");
    return status;
}

Return<bool> NqNfc::setNxpTransitConfig(const ::android::hardware::hidl_string &strval) {
    bool status = true;

    ALOGD("NqNfc::setNxpTransitConfig Entry");
    status = phNxpNciHal_setNxpTransitConfig((char *)strval.c_str());
    ALOGD("NqNfc::setNxpTransitConfig Exit");
    return status;
}

Return<bool> NqNfc::isJcopUpdateRequired() {
    bool status = 0;

    ALOGD("NqNfc::isJcopUpdateRequired Entry");
    status = getJcopUpdateRequired();
    ALOGD("NqNfc::isJcopUpdateRequired Exit");
    return status;
}

Return<bool> NqNfc::isLsUpdateRequired() {
    bool status = 0;

    ALOGD("NqNfc::isLsUpdateRequired Entry");
    status = getLsUpdateRequired();
    ALOGD("NqNfc::isLsUpdateRequired Exit");
    return status;
}

}  // namespace implementation
}  // namespace V2_0
}  // namespace nfc
}  // namespace hardware
}  // namespace nxp
}  // namespace vendor
