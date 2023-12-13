/******************************************************************************
 *
 *  Copyright 2018 NXP
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
 *
 ******************************************************************************/
/*
 * Copyright (c) 2018, The Linux Foundation. All rights reserved.
 * Not a contribution.
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

#define LOG_TAG "android.hardware.nfc@1.2-impl"
#include <log/log.h>
#include "Nfc.h"
#include "phNxpNciHal_Adaptation.h"
#include "phNfcStatus.h"

#define CHK_STATUS(x) ((x) == NFCSTATUS_SUCCESS) \
      ? (V1_0::NfcStatus::OK) : (V1_0::NfcStatus::FAILED)

extern bool nfc_debug_enabled;

namespace android {
namespace hardware {
namespace nfc {
namespace V1_2 {
namespace implementation {

sp<V1_1::INfcClientCallback> Nfc::mCallbackV1_1 = nullptr;
sp<V1_0::INfcClientCallback> Nfc::mCallbackV1_0 = nullptr;

Return<V1_0::NfcStatus> Nfc::open_1_1(
    const sp<V1_1::INfcClientCallback>& clientCallback) {
  if (clientCallback == nullptr) {
    ALOGD_IF(nfc_debug_enabled, "Nfc::open null callback");
    return V1_0::NfcStatus::FAILED;
  } else {
    mCallbackV1_1 = clientCallback;
    mCallbackV1_1->linkToDeath(this, 0 /*cookie*/);
  }
  return open(clientCallback);
}

// Methods from ::android::hardware::nfc::V1_0::INfc follow.
Return<V1_0::NfcStatus> Nfc::open(
    const sp<V1_0::INfcClientCallback>& clientCallback) {
  ALOGD_IF(nfc_debug_enabled, "Nfc::open Enter");
  if (clientCallback == nullptr) {
    ALOGD_IF(nfc_debug_enabled, "Nfc::open null callback");
    return V1_0::NfcStatus::FAILED;
  } else {
    mCallbackV1_0 = clientCallback;
    mCallbackV1_0->linkToDeath(this, 0 /*cookie*/);
  }

  NFCSTATUS status = phNxpNciHal_open(eventCallback, dataCallback);
  ALOGD_IF(nfc_debug_enabled, "Nfc::open Exit");
  return CHK_STATUS(status);
}

Return<uint32_t> Nfc::write(const hidl_vec<uint8_t>& data) {
  hidl_vec<uint8_t> copy = data;
  return phNxpNciHal_write(copy.size(), &copy[0]);
}

Return<V1_0::NfcStatus> Nfc::coreInitialized(const hidl_vec<uint8_t>& data) {
  hidl_vec<uint8_t> copy = data;
  NFCSTATUS status = phNxpNciHal_core_initialized(&copy[0]);
  return CHK_STATUS(status);
}

Return<V1_0::NfcStatus> Nfc::prediscover() {
  NFCSTATUS status = phNxpNciHal_pre_discover();
  return CHK_STATUS(status);
}

Return<V1_0::NfcStatus> Nfc::close() {
  if (mCallbackV1_1 == nullptr && mCallbackV1_0 == nullptr) {
    return V1_0::NfcStatus::FAILED;
  }
  NFCSTATUS status = phNxpNciHal_close(false);

  if (mCallbackV1_1 != nullptr) {
    mCallbackV1_1->unlinkToDeath(this);
    mCallbackV1_1 = nullptr;
  }
  if (mCallbackV1_0 != nullptr) {
    mCallbackV1_0->unlinkToDeath(this);
    mCallbackV1_0 = nullptr;
  }
  return CHK_STATUS(status);
}

Return<V1_0::NfcStatus> Nfc::controlGranted() {
  NFCSTATUS status = phNxpNciHal_control_granted();
  return CHK_STATUS(status);
}

Return<V1_0::NfcStatus> Nfc::powerCycle() {
  NFCSTATUS status = phNxpNciHal_power_cycle();
  return CHK_STATUS(status);
}

// Methods from ::android::hardware::nfc::V1_1::INfc follow.
Return<void> Nfc::factoryReset() {
  phNxpNciHal_do_factory_reset();
  return Void();
}

Return<V1_0::NfcStatus> Nfc::closeForPowerOffCase() {
  if (mCallbackV1_1 == nullptr && mCallbackV1_0 == nullptr) {
    return V1_0::NfcStatus::FAILED;
  }
  NFCSTATUS status = phNxpNciHal_configDiscShutdown();

  if (mCallbackV1_1 != nullptr) {
    mCallbackV1_1->unlinkToDeath(this);
    mCallbackV1_1 = nullptr;
  }
  if (mCallbackV1_0 != nullptr) {
    mCallbackV1_0->unlinkToDeath(this);
    mCallbackV1_0 = nullptr;
  }
  return CHK_STATUS(status);
}

Return<void> Nfc::getConfig(getConfig_cb hidl_cb) {
  android::hardware::nfc::V1_1::NfcConfig nfcVendorConfig;
  phNxpNciHal_getVendorConfig(nfcVendorConfig);
  hidl_cb(nfcVendorConfig);
  return Void();
}
Return<void> Nfc::getConfig_1_2(getConfig_1_2_cb hidl_cb) {
  NfcConfig nfcVendorConfig;
  phNxpNciHal_getVendorConfig_1_2(nfcVendorConfig);
  hidl_cb(nfcVendorConfig);
  return Void();
}

}  // namespace implementation
}  // namespace V1_1
}  // namespace nfc
}  // namespace hardware
}  // namespace android
