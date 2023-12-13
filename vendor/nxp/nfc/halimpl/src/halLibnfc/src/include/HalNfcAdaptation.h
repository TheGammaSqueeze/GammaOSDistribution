/******************************************************************************
 *
 *  Copyright (C) 2011-2012 Broadcom Corporation
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at:
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
/******************************************************************************
 *
 *  The original Work has been changed by NXP Semiconductors.
 *
 *  Copyright 2015-2020 NXP
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
#pragma once
#include <pthread.h>

#include "nfc_hal_api.h"
#include "nfc_target.h"
#include <android/hardware/nfc/1.0/INfc.h>
#include <android/hardware/nfc/1.0/INfcClientCallback.h>
#include <android/hardware/nfc/1.0/types.h>
#include <hardware/nfc.h>
#include <utils/RefBase.h>
#include <vendor/nxp/nxpnfclegacy/1.0/INxpNfcLegacy.h>
#include <vendor/nxp/nxpnfclegacy/1.0/types.h>
#include <vendor/nxp/nxpnfc/2.0/INxpNfc.h>

using ::android::sp;
using vendor::nxp::nxpnfc::V2_0::INxpNfc;

namespace android {
namespace hardware {
namespace nfc {
namespace V1_0 {
struct INfc;
struct INfcClientCallback;
} // namespace V1_0
namespace V1_1 {
struct INfc;
struct INfcClientCallback;
} // namespace V1_1
} // namespace nfc
} // namespace hardware
} // namespace android

class HalAdaptationThreadMutex {
public:
  HalAdaptationThreadMutex();
  virtual ~HalAdaptationThreadMutex();
  void lock();
  void unlock();
  operator pthread_mutex_t *() { return &mMutex; }

private:
  pthread_mutex_t mMutex;
};

class HalAdaptationThreadCondVar : public HalAdaptationThreadMutex {
public:
  HalAdaptationThreadCondVar();
  virtual ~HalAdaptationThreadCondVar();
  void signal();
  void wait();
  operator pthread_cond_t *() { return &mCondVar; }
  operator pthread_mutex_t *() {
    return HalAdaptationThreadMutex::operator pthread_mutex_t *();
  }

private:
  pthread_cond_t mCondVar;
};

class HalAdaptationAutoThreadMutex {
public:
  HalAdaptationAutoThreadMutex(HalAdaptationThreadMutex &m);
  virtual ~HalAdaptationAutoThreadMutex();
  operator HalAdaptationThreadMutex &() { return mm; }
  operator pthread_mutex_t *() { return (pthread_mutex_t *)mm; }

private:
  HalAdaptationThreadMutex &mm;
};

class NfcDeathRecipient;

class HalNfcAdaptation {
public:
  virtual ~HalNfcAdaptation();
  void Initialize();
  void Finalize();
  void FactoryReset();
  void DeviceShutdown();
  static uint8_t HalgetchipType();
  static HalNfcAdaptation &GetInstance();
  tHAL_NFC_ENTRY *GetHalEntryFuncs();
  void DownloadFirmware();
  void Dump(int fd);
#if (NXP_EXTNS == TRUE)
  void MinInitialize();
  int HalGetFwDwnldFlag(uint8_t *fwDnldRequest);
#endif

private:
  HalNfcAdaptation();
  void signal();
  static HalNfcAdaptation *mpInstance;
  static HalAdaptationThreadMutex sLock;
  static HalAdaptationThreadMutex sIoctlLock;
  HalAdaptationThreadCondVar mCondVar;
  tHAL_NFC_ENTRY mHalEntryFuncs; // function pointers for HAL entry points
  static tHAL_NFC_CBACK *mHalCallback;
  static tHAL_NFC_DATA_CBACK *mHalDataCallback;
  static HalAdaptationThreadCondVar mHalOpenCompletedEvent;
  static HalAdaptationThreadCondVar mHalCloseCompletedEvent;
  static HalAdaptationThreadCondVar mHalIoctlEvent;
  static android::sp<android::hardware::nfc::V1_0::INfc> mHal;
  static android::sp<android::hardware::nfc::V1_1::INfc> mHal_1_1;
  static android::sp<vendor::nxp::nxpnfc::V2_0::INxpNfc> mHalNxpNfc;
  static android::hardware::nfc::V1_1::INfcClientCallback *mCallback;
  static android::sp<vendor::nxp::nxpnfclegacy::V1_0::INxpNfcLegacy> mHalNxpNfcLegacy;
  sp<NfcDeathRecipient> mNfcHalDeathRecipient;
#if (NXP_EXTNS == TRUE)
  static HalAdaptationThreadCondVar mHalCoreResetCompletedEvent;
  static HalAdaptationThreadCondVar mHalCoreInitCompletedEvent;
  static HalAdaptationThreadCondVar mHalInitCompletedEvent;
#endif
  static uint32_t NFCA_TASK(uint32_t arg);
  static uint32_t Thread(uint32_t arg);
  void InitializeHalDeviceContext();
  static void HalDeviceContextCallback(nfc_event_t event,
                                       nfc_status_t event_status);
  static void HalDeviceContextDataCallback(uint16_t data_len, uint8_t *p_data);

  static void HalInitialize();
  static void HalTerminate();
  static void HalOpen(tHAL_NFC_CBACK *p_hal_cback,
                      tHAL_NFC_DATA_CBACK *p_data_cback);
  static void HalClose();
  static void HalCoreInitialized(uint16_t data_len,
                                 uint8_t *p_core_init_rsp_params);
  static void HalWrite(uint16_t data_len, uint8_t *p_data);
  static bool HalPrediscover();
  static void HalControlGranted();
};
