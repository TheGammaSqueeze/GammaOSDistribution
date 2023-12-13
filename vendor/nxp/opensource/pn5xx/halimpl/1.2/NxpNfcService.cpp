/******************************************************************************
 *
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
 *
 ******************************************************************************/

#define LOG_TAG "nxpnfc@1.2-service"
#include <android/hardware/nfc/1.2/INfc.h>
#include <vendor/nxp/nxpnfc/2.0/INxpNfc.h>
#include <vendor/nxp/nxpnfclegacy/1.0/INxpNfcLegacy.h>

#include "DwpEseUpdater.h"
#include "DwpSeChannelCallback.h"
#include "DwpSeEvtCallback.h"
#include "Nfc.h"
#include "NxpNfc.h"
#include "nxpnfclegacy/1.0/NxpNfcLegacy.h"
#include <hidl/LegacySupport.h>

// Generated HIDL files
using android::OK;
using android::sp;
using android::status_t;
using android::hardware::configureRpcThreadpool;
using android::hardware::joinRpcThreadpool;
using android::hardware::nfc::V1_2::INfc;
using android::hardware::nfc::V1_2::implementation::Nfc;
using vendor::nxp::nxpnfc::V2_0::INxpNfc;
using vendor::nxp::nxpnfc::V2_0::implementation::NxpNfc;
using vendor::nxp::nxpnfclegacy::V1_0::INxpNfcLegacy;
using vendor::nxp::nxpnfclegacy::V1_0::implementation::NxpNfcLegacy;

int main() {
  ALOGD("Registering NFC HALIMPL Service v1.2...");
  sp<INfc> nfc_service = new Nfc();

  configureRpcThreadpool(1, true /*callerWillJoin*/);
  eseClient.checkIfEseClientUpdateReqd();
  status_t status = nfc_service->registerAsService();
  if (status != OK) {
    LOG_ALWAYS_FATAL("Could not register service for NFC HAL Iface (%d).",
                     status);
    return -1;
  }

  ALOGD("Registering NFC HALIOCTL Service v1.0...");
  sp<INxpNfc> nxp_nfc_service = new NxpNfc();
  status = nxp_nfc_service->registerAsService();
  if (status != OK) {
    ALOGD("Could not register service for NXP NFC Extn Iface (%d).", status);
  }

  ALOGD("Registering NFC HAL Legacy Service v1.0...");
  sp<INxpNfcLegacy> nxp_nfc_legacy_service = new NxpNfcLegacy();
  status = nxp_nfc_legacy_service->registerAsService();
  if (status != OK) {
    ALOGD("Could not register service for NXP NFC Legacy Extn Iface (%d).", status);
  }
  ALOGE("Before calling JCOP JCOS_doDownload");
  eseClient.doEseUpdateIfReqd();
  ALOGE("After calling JCOS_doDownload");
  ALOGD("NFC HAL Service is ready");
  joinRpcThreadpool();
  return 1;
}
