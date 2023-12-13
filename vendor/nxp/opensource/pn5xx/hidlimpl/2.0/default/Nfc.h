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

#ifndef ANDROID_HARDWARE_NFC_V1_2_NFC_H
#define ANDROID_HARDWARE_NFC_V1_2_NFC_H

#include <android/hardware/nfc/1.2/INfc.h>
#include <android/hardware/nfc/1.2/types.h>
#include <hidl/MQDescriptor.h>
#include <hidl/Status.h>
#include <log/log.h>

namespace android {
namespace hardware {
namespace nfc {
namespace V1_2 {
namespace implementation {

using ::android::hidl::base::V1_0::IBase;
using ::android::hardware::nfc::V1_2::INfc;
using ::android::hardware::hidl_array;
using ::android::hardware::hidl_memory;
using ::android::hardware::hidl_string;
using ::android::hardware::hidl_vec;
using ::android::hardware::Return;
using ::android::hardware::Void;
using ::android::sp;
struct Nfc : public V1_2::INfc, public hidl_death_recipient {
 public:
  // Methods from ::android::hardware::nfc::V1_0::INfc follow.
  Return<V1_0::NfcStatus> open(
      const sp<V1_0::INfcClientCallback>& clientCallback) override;
  Return<V1_0::NfcStatus> open_1_1(
      const sp<V1_1::INfcClientCallback>& clientCallback) override;
  Return<uint32_t> write(const hidl_vec<uint8_t>& data) override;
  Return<V1_0::NfcStatus> coreInitialized(
      const hidl_vec<uint8_t>& data) override;
  Return<V1_0::NfcStatus> prediscover() override;
  Return<V1_0::NfcStatus> close() override;
  Return<V1_0::NfcStatus> controlGranted() override;
  Return<V1_0::NfcStatus> powerCycle() override;

  // Methods from ::android::hardware::nfc::V1_1::INfc follow.
  Return<void> factoryReset();
  Return<V1_0::NfcStatus> closeForPowerOffCase();
  Return<void> getConfig(getConfig_cb config);
  Return<void> getConfig_1_2(getConfig_1_2_cb config);

  // Methods from ::android::hidl::base::V1_0::IBase follow.

  static void eventCallback(uint8_t event, uint8_t status) {
    if (mCallbackV1_1 != nullptr) {
      auto ret = mCallbackV1_1->sendEvent_1_1((V1_1::NfcEvent)event,
                                              (V1_0::NfcStatus)status);
      if (!ret.isOk()) {
        ALOGW("failed to send event for mCallbackV1_1!!!");
      }
    } else if (mCallbackV1_0 != nullptr) {
      auto ret = mCallbackV1_0->sendEvent((V1_0::NfcEvent)event,
                                          (V1_0::NfcStatus)status);
      if (!ret.isOk()) {
        ALOGE("failed to send event for mCallbackV1_0!!!");
      }
    }
  }

  static void dataCallback(uint16_t data_len, uint8_t* p_data) {
    hidl_vec<uint8_t> data;
    data.setToExternal(p_data, data_len);
    if (mCallbackV1_1 != nullptr) {
      auto ret = mCallbackV1_1->sendData(data);
      if (!ret.isOk()) {
        ALOGW("failed to send data for mCallbackV1_1!!!");
      }
    } else if (mCallbackV1_0 != nullptr) {
      auto ret = mCallbackV1_0->sendData(data);
      if (!ret.isOk()) {
        ALOGE("failed to send data for mCallbackV1_0!!!");
      }
    }
  }

  virtual void serviceDied(uint64_t /*cookie*/, const wp<IBase>& /*who*/) {
    close();
  }

 private:
  static sp<V1_1::INfcClientCallback> mCallbackV1_1;
  static sp<V1_0::INfcClientCallback> mCallbackV1_0;
};

}  // namespace implementation
}  // namespace V1_1
}  // namespace nfc
}  // namespace hardware
}  // namespace android

#endif  // ANDROID_HARDWARE_NFC_V1_1_NFC_H
