/*
 * Copyright (c) 2016, The Linux Foundation. All rights reserved.
 * Not a Contribution.
 *
 * Copyright (C) 2015-2020 NXP
 * The original Work has been changed by NXP.
 *
 * Copyright (C) 2013 The Android Open Source Project
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
/*
 *  Manage the listen-mode routing table.
 */

#include <android-base/stringprintf.h>
#include <base/logging.h>
#include <nativehelper/JNIHelp.h>
#include <nativehelper/ScopedLocalRef.h>
#include "JavaClassConstants.h"
#include "SecureElement.h"
#include "RoutingManager.h"
#include "nfc_config.h"
#include "nfa_ee_api.h"
#if (NXP_EXTNS == TRUE)
#include "MposManager.h"
#include "nfa_api.h"
#include "nfc_api.h"
#include "phNxpConfig.h"
#include "nfc_config.h"

using android::base::StringPrintf;

extern int32_t gSeDiscoverycount;
extern SyncEvent gNfceeDiscCbEvent;
extern bool nfc_debug_enabled;

uint8_t nfcee_swp_discovery_status;
extern int32_t gActualSeCount;
extern int32_t gdisc_timeout;
extern uint16_t sCurrentSelectedUICCSlot;
static void LmrtRspTimerCb(union sigval);
static jint getUiccRoute(jint uicc_slot);
int gUICCVirtualWiredProtectMask = 0;
int gEseVirtualWiredProtectMask = 0;
int gWiredModeRfFieldEnable = 0;
#endif
extern bool sHCEEnabled;

const JNINativeMethod RoutingManager::sMethods[] = {
    {"doGetDefaultRouteDestination", "()I",
     (void*)RoutingManager::
         com_android_nfc_cardemulation_doGetDefaultRouteDestination},
    {"doGetOffHostEseDestination", "()[B",
     (void*)RoutingManager::
         com_android_nfc_cardemulation_doGetOffHostEseDestination},
    {"doGetOffHostUiccDestination", "()[B",
     (void*)RoutingManager::
         com_android_nfc_cardemulation_doGetOffHostUiccDestination},
    {"doGetDefaultOffHostRouteDestination", "()I",
     (void*)RoutingManager::
         com_android_nfc_cardemulation_doGetDefaultOffHostRouteDestination},
    {"doGetAidMatchingMode", "()I",
     (void*)RoutingManager::com_android_nfc_cardemulation_doGetAidMatchingMode},
    {"doGetDefaultIsoDepRouteDestination", "()I",
     (void*)RoutingManager::
         com_android_nfc_cardemulation_doGetDefaultIsoDepRouteDestination}};

uint16_t lastcehandle = 0;
// SCBR from host works only when App is in foreground
static const uint8_t SYS_CODE_PWR_STATE_HOST = 0x01;
static const uint16_t DEFAULT_SYS_CODE = 0xFEFE;
extern jint nfcManager_getUiccId(jint uicc_slot);
extern jint nfcManager_getUiccRoute(jint uicc_slot);
namespace android {
extern void checkforTranscation(uint8_t connEvent, void* eventData);
#if (NXP_EXTNS == TRUE)
extern bool nfcManager_sendEmptyDataMsg();
extern bool gIsEmptyRspSentByHceFApk;
extern uint16_t sRoutingBuffLen;
extern bool rfActivation;
extern bool isNfcInitializationDone();
extern void startRfDiscovery(bool isStart);
extern bool isDiscoveryStarted();
extern int getScreenState();
#if (NXP_NFCC_HCE_F == TRUE)
extern bool nfcManager_getTransanctionRequest(int t3thandle,
                                              bool registerRequest);
#endif
#endif
}  // namespace android

#if (NXP_EXTNS == TRUE)
static const uint8_t AID_ROUTE_QUAL_PREFIX = 0x10;
#endif

RoutingManager::RoutingManager()
    : mNativeData(NULL),
      mSecureNfcEnabled(false),
      mDefaultTechABFRoute(0),
      mDefaultEe(NFA_HANDLE_INVALID),
      mHostListnTechMask(0),
      mUiccListnTechMask(0),
      mFwdFuntnEnable(true),
      mAddAid(0),
      mDefaultHCEFRspTimeout(5000) {
  static const char fn[] = "RoutingManager::RoutingManager()";
  DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf("%s:enter", fn);
  mRxDataBuffer.clear();
  mOffHostRouteUicc.clear();
  mOffHostRouteEse.clear();
  if (NfcConfig::hasKey(NAME_OFFHOST_ROUTE_UICC)) {
    mOffHostRouteUicc = NfcConfig::getBytes(NAME_OFFHOST_ROUTE_UICC);
  }

  if (NfcConfig::hasKey(NAME_OFFHOST_ROUTE_ESE)) {
    mOffHostRouteEse = NfcConfig::getBytes(NAME_OFFHOST_ROUTE_ESE);
  }
  mDefaultOffHostRoute =
      NfcConfig::getUnsigned(NAME_DEFAULT_OFFHOST_ROUTE, 0x00);

  mDefaultTechABFRoute =
      NfcConfig::getUnsigned(NAME_DEFAULT_TECH_ABF_ROUTE, 0x00);

  mAidMatchingMode =
      NfcConfig::getUnsigned(NAME_AID_MATCHING_MODE, AID_MATCHING_EXACT_ONLY);

  mAidMatchingPlatform =
      NfcConfig::getUnsigned("AID_MATCHING_PLATFORM", AID_MATCHING_L);

  mDefaultSysCodeRoute =
      NfcConfig::getUnsigned(NAME_DEFAULT_SYS_CODE_ROUTE, 0x01);

  mDefaultSysCodePowerstate =
      NfcConfig::getUnsigned(NAME_DEFAULT_SYS_CODE_PWR_STATE, 0x19);

  mOffHostAidRoutingPowerState =
      NfcConfig::getUnsigned(NAME_OFFHOST_AID_ROUTE_PWR_STATE, 0x01);

  mDefaultSysCode = DEFAULT_SYS_CODE;
  if (NfcConfig::hasKey(NAME_DEFAULT_SYS_CODE)) {
    std::vector<uint8_t> pSysCode = NfcConfig::getBytes(NAME_DEFAULT_SYS_CODE);
    if (pSysCode.size() == 0x02) {
      mDefaultSysCode = ((pSysCode[0] << 8) | ((int)pSysCode[1] << 0));
      DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf(
          "%s: DEFAULT_SYS_CODE: 0x%02X", __func__, mDefaultSysCode);
    }
  }

  mHostListenTechMask =
      NfcConfig::getUnsigned(NAME_HOST_LISTEN_TECH_MASK,
                             NFA_TECHNOLOGY_MASK_A | NFA_TECHNOLOGY_MASK_F);

  memset(&mEeInfo, 0, sizeof(mEeInfo));
  mSeTechMask = 0x00;  // unused
  mReceivedEeInfo = false;
  mNfcFOnDhHandle = NFA_HANDLE_INVALID;
  mIsScbrSupported = false;
  mDefaultIsoDepRoute = NfcConfig::getUnsigned(NAME_DEFAULT_ISODEP_ROUTE, 0x00);
  DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf(
      "%s: mDefaultIsoDepRoute: 0x%02X", __func__, mDefaultIsoDepRoute);
  mOffHostAidRoutingPowerState =
      NfcConfig::getUnsigned(NAME_OFFHOST_AID_ROUTE_PWR_STATE, 0x01);
  DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf("%s:exit", fn);

#if(NXP_EXTNS == TRUE)
  memset (mProtoTableEntries, 0, sizeof(mProtoTableEntries));
  memset (mTechTableEntries, 0, sizeof(mTechTableEntries));
  memset (mLmrtEntries, 0, sizeof(mLmrtEntries));
  mCeRouteStrictDisable = 0;
  mDefaultTechASeID = 0;
  mTechSupportedByEse = 0;
  mTechSupportedByUicc1 = 0;
  mTechSupportedByUicc2 = 0;
#endif
}

int RoutingManager::mChipId = 0;
#if (NXP_EXTNS == TRUE)
bool recovery;
#endif

RoutingManager::~RoutingManager() {}

bool RoutingManager::initialize(nfc_jni_native_data* native) {
  static const char fn[] = "RoutingManager::initialize()";
  unsigned long num = 0;
  mNativeData = native;
  mRxDataBuffer.clear();

  uint8_t ActualNumEe = nfcFL.nfccFL._NFA_EE_MAX_EE_SUPPORTED;
  tNFA_EE_INFO mEeInfo[ActualNumEe];

  DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf("%s: enter", fn);

  mDefaultOffHostRoute =
      NfcConfig::getUnsigned(NAME_DEFAULT_OFFHOST_ROUTE, 0x00);

  mDefaultTechABFRoute =
      NfcConfig::getUnsigned(NAME_DEFAULT_TECH_ABF_ROUTE, 0x00);

  mAidMatchingMode =
      NfcConfig::getUnsigned(NAME_AID_MATCHING_MODE, AID_MATCHING_EXACT_ONLY);

  mAidMatchingPlatform =
      NfcConfig::getUnsigned("AID_MATCHING_PLATFORM", AID_MATCHING_L);

  mDefaultSysCodeRoute =
      NfcConfig::getUnsigned(NAME_DEFAULT_SYS_CODE_ROUTE, 0x01);

  mDefaultSysCodePowerstate =
      NfcConfig::getUnsigned(NAME_DEFAULT_SYS_CODE_PWR_STATE, 0x19);

  mOffHostAidRoutingPowerState =
      NfcConfig::getUnsigned(NAME_OFFHOST_AID_ROUTE_PWR_STATE, 0x01);

  if (NfcConfig::hasKey(NAME_DEFAULT_SYS_CODE)) {
    std::vector<uint8_t> pSysCode = NfcConfig::getBytes(NAME_DEFAULT_SYS_CODE);
    if (pSysCode.size() == 0x02) {
      mDefaultSysCode = ((pSysCode[0] << 8) | ((int)pSysCode[1] << 0));
      DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf(
          "%s: DEFAULT_SYS_CODE: 0x%02X", __func__, mDefaultSysCode);
    }
  }

#if (NXP_EXTNS == TRUE)
  nfcee_swp_discovery_status = SWP_DEFAULT;

  if (NfcConfig::hasKey(NAME_HOST_LISTEN_TECH_MASK)) {
    mHostListnTechMask = NfcConfig::getUnsigned(NAME_HOST_LISTEN_TECH_MASK);
  } else {
    mHostListnTechMask = 0x07;
  }

  if (NfcConfig::hasKey(NAME_NXP_FWD_FUNCTIONALITY_ENABLE)) {
    mFwdFuntnEnable = NfcConfig::getUnsigned(NAME_NXP_FWD_FUNCTIONALITY_ENABLE);
  } else {
    mFwdFuntnEnable = false;
  }

  LOG(ERROR) << StringPrintf("%s: mFwdFuntnEnable=0x%X", fn, mFwdFuntnEnable);

  if (NfcConfig::hasKey(NAME_UICC_LISTEN_TECH_MASK)) {
    mUiccListnTechMask = NfcConfig::getUnsigned(NAME_UICC_LISTEN_TECH_MASK);
  } else {
    mUiccListnTechMask = 0x07;
  }

  if (NfcConfig::hasKey(NAME_DEFAULT_ROUTE)) {
    mDefaultEe = NfcConfig::getUnsigned(NAME_DEFAULT_ROUTE);
  } else {
    mDefaultEe = 0x00;
  }


  if (NfcConfig::hasKey(NAME_NXP_ENABLE_ADD_AID)) {
    mAddAid = NfcConfig::getUnsigned(NAME_NXP_ENABLE_ADD_AID);
  } else {
    mAddAid = 0x01;
  }

  if (nfcFL.nfcNxpEse && (nfcFL.chipType != pn547C2)) {
    if (NfcConfig::hasKey(NAME_NXP_ESE_WIRED_PRT_MASK)) {
      gEseVirtualWiredProtectMask =
          NfcConfig::getUnsigned(NAME_NXP_ESE_WIRED_PRT_MASK);
    } else {
      gEseVirtualWiredProtectMask = 0x00;
    }

    if (NfcConfig::hasKey(NAME_NXP_UICC_WIRED_PRT_MASK)) {
      gUICCVirtualWiredProtectMask =
          NfcConfig::getUnsigned(NAME_NXP_UICC_WIRED_PRT_MASK);
    } else {
      gUICCVirtualWiredProtectMask = 0x00;
    }

    if (NfcConfig::hasKey(NAME_NXP_WIRED_MODE_RF_FIELD_ENABLE)) {
      gWiredModeRfFieldEnable =
          NfcConfig::getUnsigned(NAME_NXP_WIRED_MODE_RF_FIELD_ENABLE);
    } else {
      gWiredModeRfFieldEnable = 0x00;
    }
  }
#if (NXP_EXTNS != TRUE)
  mDefaultFelicaRoute = NfcConfig::getUnsigned(NAME_DEFAULT_NFCF_ROUTE, 0x00);
#endif
  if (NfcConfig::hasKey(NAME_NXP_HCEF_CMD_RSP_TIMEOUT_VALUE)) {
    num = NfcConfig::getUnsigned(NAME_NXP_HCEF_CMD_RSP_TIMEOUT_VALUE);
    if (num > 0) {
      mDefaultHCEFRspTimeout = num;
    }
  }
#endif
  if (NfcConfig::hasKey(NAME_NXP_NFC_CHIP)) {
    num = NfcConfig::getUnsigned(NAME_NXP_NFC_CHIP);
    mChipId = num;
  }

  tNFA_STATUS nfaStat = NFA_STATUS_FAILED;
  {
    SyncEventGuard guard(mEeRegisterEvent);
    DLOG_IF(INFO, nfc_debug_enabled) << fn << ": try ee register";
    tNFA_STATUS nfaStat = NFA_EeRegister(nfaEeCallback);
    if (nfaStat != NFA_STATUS_OK) {
      LOG(ERROR) << StringPrintf("%s: fail ee register; error=0x%X", fn,
                                 nfaStat);
      return false;
    }
    mEeRegisterEvent.wait();
  }

  if (mDefaultTechABFRoute != 0) {
    // Wait for EE info if needed
    SyncEventGuard guard(mEeInfoEvent);
    if (!mReceivedEeInfo) {
      LOG(INFO) << fn << "Waiting for EE info";
      mEeInfoEvent.wait();
    }
  }

  mReceivedEeInfo = false;

#if (NXP_EXTNS != TRUE)
  mSeTechMask = updateEeTechRouteSetting();
#endif

  // Set the host-routing Tech
  nfaStat = NFA_CeSetIsoDepListenTech(
    mHostListenTechMask & (NFA_TECHNOLOGY_MASK_A | NFA_TECHNOLOGY_MASK_B));
  if (nfaStat != NFA_STATUS_OK)
    LOG(ERROR) << StringPrintf("Failed to configure CE IsoDep technologies");

  // Tell the host-routing to only listen on Nfc-A/Nfc-B
  nfaStat = NFA_CeRegisterAidOnDH(NULL, 0, stackCallback);
  if (nfaStat != NFA_STATUS_OK)
    LOG(ERROR) << StringPrintf("Failed to register wildcard AID for DH");

  if ((nfaStat = NFA_AllEeGetInfo(&ActualNumEe, mEeInfo)) != NFA_STATUS_OK) {
    LOG(ERROR) << StringPrintf("%s: fail get info; error=0x%X", fn, nfaStat);
    ActualNumEe = 0;
  } else {
    // gSeDiscoverycount = ActualNumEe;
    SecureElement::getInstance().updateNfceeDiscoverInfo();
    DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf(
        "%s:gSeDiscoverycount=0x%d;", __func__, gSeDiscoverycount);

    tNFA_TECHNOLOGY_MASK seTechMask = 0;
    for (uint8_t i = 0; i < ActualNumEe; i++) {
      if (mEeInfo[i].ee_handle != SecureElement::EE_HANDLE_0xF3) continue;
      if (mEeInfo[i].la_protocol != 0)
        seTechMask |= NFA_TECHNOLOGY_MASK_A;
      if (mEeInfo[i].lb_protocol != 0)
        seTechMask |= NFA_TECHNOLOGY_MASK_B;
      if (mEeInfo[i].lf_protocol != 0)
        seTechMask |= NFA_TECHNOLOGY_MASK_F;
      break;
    }

    DLOG_IF(INFO, nfc_debug_enabled)
        << StringPrintf("%s:seTechMask=0x%x;", __func__, seTechMask);
    if (seTechMask) {
      SyncEventGuard guard(SecureElement::getInstance().mEseListenEvent);
      nfaStat = NFA_CeConfigureEseListenTech(SecureElement::EE_HANDLE_0xF3,
                                             seTechMask);
      if (nfaStat == NFA_STATUS_OK) {
        SecureElement::getInstance().mEseListenEvent.wait(500);
      } else
        LOG(ERROR) << StringPrintf("fail to start ESE listen");
    }
  }
  printMemberData();
  updateDefaultRoute();
#if (NXP_EXTNS != TRUE)
  updateDefaultProtocolRoute();
#endif

  DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf("%s: exit", fn);
  return true;
}

RoutingManager& RoutingManager::getInstance() {
  static RoutingManager manager;
  return manager;
}

void RoutingManager::enableRoutingToHost() {
  static const char fn[] = "RoutingManager::enableRoutingToHost()";
  tNFA_STATUS nfaStat = NFA_STATUS_FAILED;
  SyncEventGuard guard(mRoutingEvent);
  // Default routing for T3T protocol
  if (!mIsScbrSupported && mDefaultEe == NFC_DH_ID) {
    nfaStat = NFA_EeSetDefaultProtoRouting(NFC_DH_ID, NFA_PROTOCOL_MASK_T3T, 0,
                                           0, 0, 0, 0);
    if (nfaStat == NFA_STATUS_OK)
      mRoutingEvent.wait();
    else
      LOG(ERROR) << fn << "Fail to set default proto routing for T3T";
  }

  // Default routing for IsoDep protocol
  tNFA_PROTOCOL_MASK protoMask = NFA_PROTOCOL_MASK_ISO_DEP;
  if (mDefaultIsoDepRoute == NFC_DH_ID) {
    nfaStat = NFA_EeSetDefaultProtoRouting(
        NFC_DH_ID, protoMask, 0, 0, mSecureNfcEnabled ? 0 : protoMask, 0, 0);
    if (nfaStat == NFA_STATUS_OK)
      mRoutingEvent.wait();
    else
      LOG(ERROR) << fn << "Fail to set default proto routing for IsoDep";
  }

  // Route Nfc-A to host if we don't have a SE
  tNFA_TECHNOLOGY_MASK techMask = NFA_TECHNOLOGY_MASK_A;
  if ((mHostListenTechMask & NFA_TECHNOLOGY_MASK_A) &&
      (mSeTechMask & NFA_TECHNOLOGY_MASK_A) == 0) {
    nfaStat = NFA_EeSetDefaultTechRouting(
        NFC_DH_ID, techMask, 0, 0, mSecureNfcEnabled ? 0 : techMask,
        mSecureNfcEnabled ? 0 : techMask, mSecureNfcEnabled ? 0 : techMask);
    if (nfaStat == NFA_STATUS_OK)
      mRoutingEvent.wait();
    else
      LOG(ERROR) << fn << "Fail to set default tech routing for Nfc-A";
  }

  // Route Nfc-B to host if we don't have a SE
  techMask = NFA_TECHNOLOGY_MASK_B;
  if ((mHostListenTechMask & NFA_TECHNOLOGY_MASK_B) &&
      (mSeTechMask & NFA_TECHNOLOGY_MASK_B) == 0) {
    nfaStat = NFA_EeSetDefaultTechRouting(
        NFC_DH_ID, techMask, 0, 0, mSecureNfcEnabled ? 0 : techMask,
        mSecureNfcEnabled ? 0 : techMask, mSecureNfcEnabled ? 0 : techMask);
    if (nfaStat == NFA_STATUS_OK)
      mRoutingEvent.wait();
    else
      LOG(ERROR) << fn << "Fail to set default tech routing for Nfc-B";
  }

  // Route Nfc-F to host if we don't have a SE
  techMask = NFA_TECHNOLOGY_MASK_F;
  if ((mHostListenTechMask & NFA_TECHNOLOGY_MASK_F) &&
      (mSeTechMask & NFA_TECHNOLOGY_MASK_F) == 0) {
    nfaStat = NFA_EeSetDefaultTechRouting(
        NFC_DH_ID, techMask, 0, 0, mSecureNfcEnabled ? 0 : techMask,
        mSecureNfcEnabled ? 0 : techMask, mSecureNfcEnabled ? 0 : techMask);
    if (nfaStat == NFA_STATUS_OK)
      mRoutingEvent.wait();
    else
      LOG(ERROR) << fn << "Fail to set default tech routing for Nfc-F";
  }
}

void RoutingManager::disableRoutingToHost() {
  static const char fn[] = "RoutingManager::disableRoutingToHost()";
  tNFA_STATUS nfaStat = NFA_STATUS_FAILED;
  SyncEventGuard guard(mRoutingEvent);

  // Clear default routing for IsoDep protocol
  if (mDefaultIsoDepRoute == NFC_DH_ID) {
    nfaStat =
        NFA_EeClearDefaultProtoRouting(NFC_DH_ID, NFA_PROTOCOL_MASK_ISO_DEP);
    if (nfaStat == NFA_STATUS_OK)
      mRoutingEvent.wait();
    else
      LOG(ERROR) << fn << "Fail to clear default proto routing for IsoDep";
  }

  // Clear default routing for Nfc-A technology if we don't have a SE
  if ((mHostListenTechMask & NFA_TECHNOLOGY_MASK_A) &&
      (mSeTechMask & NFA_TECHNOLOGY_MASK_A) == 0) {
    nfaStat = NFA_EeClearDefaultTechRouting(NFC_DH_ID, NFA_TECHNOLOGY_MASK_A);
    if (nfaStat == NFA_STATUS_OK)
      mRoutingEvent.wait();
    else
      LOG(ERROR) << fn << "Fail to clear default tech routing for Nfc-A";
  }

  // Clear default routing for Nfc-B technology if we don't have a SE
  if ((mHostListenTechMask & NFA_TECHNOLOGY_MASK_B) &&
      (mSeTechMask & NFA_TECHNOLOGY_MASK_B) == 0) {
    nfaStat = NFA_EeClearDefaultTechRouting(NFC_DH_ID, NFA_TECHNOLOGY_MASK_B);
    if (nfaStat == NFA_STATUS_OK)
      mRoutingEvent.wait();
    else
      LOG(ERROR) << fn << "Fail to clear default tech routing for Nfc-B";
  }

  // Clear default routing for Nfc-F technology if we don't have a SE
  if ((mHostListenTechMask & NFA_TECHNOLOGY_MASK_F) &&
      (mSeTechMask & NFA_TECHNOLOGY_MASK_F) == 0) {
    nfaStat = NFA_EeClearDefaultTechRouting(NFC_DH_ID, NFA_TECHNOLOGY_MASK_F);
    if (nfaStat == NFA_STATUS_OK)
      mRoutingEvent.wait();
    else
      LOG(ERROR) << fn << "Fail to clear default tech routing for Nfc-F";
  }

  // Clear default routing for T3T protocol
  if (!mIsScbrSupported && mDefaultEe == NFC_DH_ID) {
    nfaStat = NFA_EeClearDefaultProtoRouting(NFC_DH_ID, NFA_PROTOCOL_MASK_T3T);
    if (nfaStat == NFA_STATUS_OK)
      mRoutingEvent.wait();
    else
      LOG(ERROR) << fn << "Fail to clear default proto routing for T3T";
  }
}

#if (NXP_EXTNS == TRUE)
void RoutingManager::setRouting(bool isHCEEnabled) {
  tNFA_STATUS nfaStat = NFA_STATUS_FAILED;
  tNFA_HANDLE defaultHandle = NFA_HANDLE_INVALID;
  tNFA_HANDLE ee_handleList[nfcFL.nfccFL._NFA_EE_MAX_EE_SUPPORTED];
  uint8_t i = 0, count;
  static const char fn[] = "SecureElement::setRouting";
  unsigned long num = 0;

  if (NfcConfig::hasKey(NAME_UICC_LISTEN_TECH_MASK)) {
    num = NfcConfig::getUnsigned(NAME_UICC_LISTEN_TECH_MASK);
    DLOG_IF(INFO, nfc_debug_enabled)
        << StringPrintf("%s:UICC_LISTEN_MASK=0x0%lu;", __func__, num);
  }

  SecureElement& se = SecureElement::getInstance();
  if (isHCEEnabled) {
    defaultHandle = NFA_EE_HANDLE_DH;
  } else {
    SecureElement::getInstance().getEeHandleList(ee_handleList, &count);
    defaultHandle = ee_handleList[0];
  }
  DLOG_IF(INFO, nfc_debug_enabled)
      << StringPrintf("%s: defaultHandle %u = 0x%X", fn, i, defaultHandle);

  if (defaultHandle != NFA_HANDLE_INVALID) {
    {
      SyncEventGuard guard(mRoutingEvent);

      tNFA_STATUS status = NFA_EeSetDefaultTechRouting(
          se.EE_HANDLE_0xF4, 0, 0, 0, 0, 0, 0);  // UICC clear

      if (status == NFA_STATUS_OK) {
        mRoutingEvent.wait();
      }
    }

    {
      SyncEventGuard guard(mRoutingEvent);

      tNFA_STATUS status = NFA_EeSetDefaultProtoRouting(
          se.EE_HANDLE_0xF4, 0, 0, 0, 0, 0, 0);  // UICC clear

      if (status == NFA_STATUS_OK) {
        mRoutingEvent.wait();
      }
    }

    {
      SyncEventGuard guard(mRoutingEvent);

      tNFA_STATUS status = NFA_EeSetDefaultTechRouting(
          SecureElement::EE_HANDLE_0xF3, 0, 0, 0, 0, 0, 0);  // SMX clear

      if (status == NFA_STATUS_OK) {
        mRoutingEvent.wait();
      }
    }

    {
      SyncEventGuard guard(mRoutingEvent);

      tNFA_STATUS status = NFA_EeSetDefaultProtoRouting(
          SecureElement::EE_HANDLE_0xF3, 0, 0, 0, 0, 0, 0);  // SMX clear

      if (status == NFA_STATUS_OK) {
        mRoutingEvent.wait();
      }
    }

    {
      SyncEventGuard guard(mRoutingEvent);

      tNFA_STATUS status =
          NFA_EeSetDefaultTechRouting(0x400, 0, 0, 0, 0, 0, 0);  // HOST clear

      if (status == NFA_STATUS_OK) {
        mRoutingEvent.wait();
      }
    }

    {
      SyncEventGuard guard(mRoutingEvent);

      tNFA_STATUS status =
          NFA_EeSetDefaultProtoRouting(0x400, 0, 0, 0, 0, 0, 0);  // HOST clear

      if (status == NFA_STATUS_OK) {
        mRoutingEvent.wait();
      }
    }
    if (defaultHandle == NFA_EE_HANDLE_DH) {
      SyncEventGuard guard(mRoutingEvent);
      // Default routing for NFC-A technology
      if (mCeRouteStrictDisable == 0x01) {
        nfaStat =
            NFA_EeSetDefaultTechRouting(defaultHandle, 0x01, 0, 0, 0x01, 0, 0);
      } else {
        nfaStat =
            NFA_EeSetDefaultTechRouting(defaultHandle, 0x01, 0, 0, 0, 0, 0);
      }

      if (nfaStat == NFA_STATUS_OK)
        mRoutingEvent.wait();
      else
        LOG(ERROR) << StringPrintf("Fail to set default tech routing");
    } else {
      SyncEventGuard guard(mRoutingEvent);
      // Default routing for NFC-A technology
      if (mCeRouteStrictDisable == 0x01) {
        nfaStat = NFA_EeSetDefaultTechRouting(defaultHandle, num, num, num, num,
                                              num, num);
      } else {
        nfaStat =
            NFA_EeSetDefaultTechRouting(defaultHandle, num, num, num, 0, 0, 0);
      }
      if (nfaStat == NFA_STATUS_OK)
        mRoutingEvent.wait();
      else
        LOG(ERROR) << StringPrintf("Fail to set default tech routing");
    }

    if (defaultHandle == NFA_EE_HANDLE_DH) {
      SyncEventGuard guard(mRoutingEvent);
      // Default routing for IsoDep protocol
      if (mCeRouteStrictDisable == 0x01) {
        nfaStat = NFA_EeSetDefaultProtoRouting(
            defaultHandle, NFA_PROTOCOL_MASK_ISO_DEP, 0, 0,
            mSecureNfcEnabled ? 0 : NFA_PROTOCOL_MASK_ISO_DEP, 0, 0);
      } else {
        nfaStat = NFA_EeSetDefaultProtoRouting(
            defaultHandle, NFA_PROTOCOL_MASK_ISO_DEP, 0, 0, 0, 0, 0);
      }
      if (nfaStat == NFA_STATUS_OK)
        mRoutingEvent.wait();
      else
        LOG(ERROR) << StringPrintf("Fail to set default proto routing");
    } else {
      SyncEventGuard guard(mRoutingEvent);
      // Default routing for IsoDep protocol
      if (mCeRouteStrictDisable == 0x01) {
        nfaStat = NFA_EeSetDefaultProtoRouting(
            defaultHandle, NFA_PROTOCOL_MASK_ISO_DEP,
            mSecureNfcEnabled ? 0 : NFA_PROTOCOL_MASK_ISO_DEP,
            mSecureNfcEnabled ? 0 : NFA_PROTOCOL_MASK_ISO_DEP,
            mSecureNfcEnabled ? 0 : NFA_PROTOCOL_MASK_ISO_DEP,
            mSecureNfcEnabled ? 0 : NFA_PROTOCOL_MASK_ISO_DEP,
            mSecureNfcEnabled ? 0 : NFA_PROTOCOL_MASK_ISO_DEP);
      } else {
        nfaStat = NFA_EeSetDefaultProtoRouting(
            defaultHandle, NFA_PROTOCOL_MASK_ISO_DEP,
            mSecureNfcEnabled ? 0 : NFA_PROTOCOL_MASK_ISO_DEP,
            mSecureNfcEnabled ? 0 : NFA_PROTOCOL_MASK_ISO_DEP, 0, 0, 0);
      }
      if (nfaStat == NFA_STATUS_OK)
        mRoutingEvent.wait();
      else
        LOG(ERROR) << StringPrintf("Fail to set default proto routing");
    }

    if (defaultHandle != NFA_EE_HANDLE_DH) {
      {
        SyncEventGuard guard(SecureElement::getInstance().mUiccListenEvent);
        nfaStat = NFA_CeConfigureUiccListenTech(defaultHandle, 0x00);
        if (nfaStat == NFA_STATUS_OK) {
          SecureElement::getInstance().mUiccListenEvent.wait();
        } else
          LOG(ERROR) << StringPrintf("fail to start UICC listen");
      }

      {
        SyncEventGuard guard(SecureElement::getInstance().mUiccListenEvent);
        nfaStat = NFA_CeConfigureUiccListenTech(defaultHandle, (num & 0x07));
        if (nfaStat == NFA_STATUS_OK) {
          SecureElement::getInstance().mUiccListenEvent.wait();
        } else
          LOG(ERROR) << StringPrintf("fail to start UICC listen");
      }
    }
  }

  // Commit the routing configuration
  nfaStat = NFA_EeUpdateNow();
  if (nfaStat != NFA_STATUS_OK)
    LOG(ERROR) << StringPrintf("Failed to commit routing configuration");
}

void RoutingManager::setCeRouteStrictDisable(uint32_t state) {
  DLOG_IF(INFO, nfc_debug_enabled)
      << StringPrintf("%s: mCeRouteScreenLock = 0x%u", __func__, state);
  mCeRouteStrictDisable = state;
}

/******************************************************************************
 ** Function:    nfaEEConnect
 **
 ** Description: This function is invoked in case of eSE session reset.
 **              in this case we already discovered eSE earlierhence eSE the eSE
 *count is
 **              decremented from gSeDiscoveryCount so that only pending
 *NFCEE(UICC1 & UICC2)
 **              would be rediscovered.
 **
 ** Returns:     None
 ********************************************************************************/
void RoutingManager::nfaEEConnect() {
  tNFA_STATUS nfaStat = NFA_STATUS_FAILED;
  if (NFA_GetNCIVersion() != NCI_VERSION_2_0) {
    nfaStat = NFA_EeConnect(EE_HCI_DEFAULT_HANDLE,
                            NFC_NFCEE_INTERFACE_HCI_ACCESS, nfaEeCallback);
  } else {
    nfaStat = NFA_EeDiscover(nfaEeCallback);
  }
  if (nfaStat == NFA_STATUS_OK) {
    SyncEventGuard g(gNfceeDiscCbEvent);
    DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf(
        "%s, Sem wait for gNfceeDiscCbEvent %d", __FUNCTION__, gdisc_timeout);
    gNfceeDiscCbEvent.wait(gdisc_timeout);
  }
}

/******************************************************************************
 ** Function: nfaEEDisconnect
 **
 ** Description: This function can be called to delete the core logical
 *connection
 ** already created , to create connection again.
 **
 ** Returns: None
 ********************************************************************************/
void RoutingManager::nfaEEDisconnect() {
  if (NFA_STATUS_OK == NFA_EeDisconnect(EE_HCI_DEFAULT_HANDLE)) {
    SyncEventGuard guard(mEEDisconnectEvt);
    DLOG_IF(INFO, nfc_debug_enabled)
        << StringPrintf("%s, Sem wait for mEEDisconnectEvt", __FUNCTION__);
    mEEDisconnectEvt.wait(1000);
  }
}

void RoutingManager::printMemberData() {
  DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf(
      "%s: AID_MATCHING_MODE = 0x%0X", __func__, mAidMatchingMode);
  DLOG_IF(INFO, nfc_debug_enabled)
      << StringPrintf("%s: DEFAULT_ISODEP_ROUTE = 0x%0X", __func__, mDefaultIsoDepRoute);
  DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf(
      "%s: AID_MATCHING_PLATFORM = 0x%0X", __func__, mAidMatchingPlatform);
  DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf(
      "%s: HOST_LISTEN_TECH_MASK = 0x%0X;", __func__, mHostListnTechMask);
  DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf(
      "%s: UICC_LISTEN_TECH_MASK = 0x%0X;", __func__, mUiccListnTechMask);

  DLOG_IF(INFO, nfc_debug_enabled)
      << StringPrintf("%s: NXP_NFC_CHIP = 0x%0X;", __func__, mChipId);
  DLOG_IF(INFO, nfc_debug_enabled)
      << StringPrintf("%s: NXP_DEFAULT_ROUTE = 0x%0X;", __func__, mDefaultEe);
  DLOG_IF(INFO, nfc_debug_enabled)
      << StringPrintf("%s: NXP_ENABLE_ADD_AID = 0x%0u;", __func__, mAddAid);
  DLOG_IF(INFO, nfc_debug_enabled)
      << StringPrintf("%s: NXP_ESE_WIRED_PRT_MASK = 0x%0X;", __func__,
                      gEseVirtualWiredProtectMask);
  DLOG_IF(INFO, nfc_debug_enabled)
      << StringPrintf("%s: NXP_UICC_WIRED_PRT_MASK = 0x%0X;", __func__,
                      gUICCVirtualWiredProtectMask);
  DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf(
      "%s: NXP_FWD_FUNCTIONALITY_ENABLE = 0x%0X;", __func__, mFwdFuntnEnable);
  DLOG_IF(INFO, nfc_debug_enabled)
      << StringPrintf("%s: NXP_WIRED_MODE_RF_FIELD_ENABLE = 0x%0X;", __func__,
                      gWiredModeRfFieldEnable);
  DLOG_IF(INFO, nfc_debug_enabled)
      << StringPrintf("%s: NAME_DEFAULT_OFFHOST_ROUTE = 0x%0X;", __func__,
                      mDefaultOffHostRoute);
  DLOG_IF(INFO, nfc_debug_enabled)
      << StringPrintf("%s: NAME_DEFAULT_TECH_ABF_ROUTE = 0x%0X;", __func__,
                      mDefaultTechABFRoute);
}

/* Based on the features enabled :- NXP_NFCC_DYNAMIC_DUAL_UICC,
 * NFC_NXP_STAT_DUAL_UICC_WO_EXT_SWITCH & NFC_NXP_STAT_DUAL_UICC_EXT_SWITCH,
 * Calculate the UICC route location ID.
 * For DynamicDualUicc,Route location is based on the user configuration(6th &
 * 7th bit) of route
 * For StaticDualUicc without External Switch(with DynamicDualUicc enabled),
 * Route location is based on user selection from selectUicc() API
 * For StaticDualUicc(With External Switch), Route location is always
 * ROUTE_LOC_UICC1_ID
 */
uint16_t RoutingManager::getUiccRouteLocId(const int route) {
  if (nfcFL.nfccFL._NFCC_DYNAMIC_DUAL_UICC &&
      nfcFL.nfccFL._NFC_NXP_STAT_DUAL_UICC_WO_EXT_SWITCH)
    return getUiccRoute(sCurrentSelectedUICCSlot);
  else if (nfcFL.nfccFL._NFCC_DYNAMIC_DUAL_UICC)
    return ((((route & 0x0300) >> 8) == 0x02)
                ? SecureElement::getInstance().EE_HANDLE_0xF4
                : ROUTE_LOC_UICC2_ID);
  else /*#if (NFC_NXP_STAT_DUAL_UICC_EXT_SWITCH == true)*/
    return SecureElement::getInstance().EE_HANDLE_0xF4;
}




/* Forward Functionality is to handle either technology which is supported by
 * UICC
 * We are handling it by setting the alternate technology(A/B) to HOST
 * */
void RoutingManager::processTechEntriesForFwdfunctionality(void) {
  static const char fn[] =
      "RoutingManager::processTechEntriesForFwdfunctionality";
  uint32_t techSupportedByUICC = mTechSupportedByUicc1;
  if (nfcFL.nfccFL._NFCC_DYNAMIC_DUAL_UICC &&
      nfcFL.nfccFL._NFC_NXP_STAT_DUAL_UICC_WO_EXT_SWITCH) {
    techSupportedByUICC = (getUiccRoute(sCurrentSelectedUICCSlot) ==
                           SecureElement::getInstance().EE_HANDLE_0xF4)
                              ? mTechSupportedByUicc1
                              : mTechSupportedByUicc2;
  } else if (nfcFL.nfccFL._NFCC_DYNAMIC_DUAL_UICC) {
    techSupportedByUICC =
        (mDefaultTechASeID == SecureElement::getInstance().EE_HANDLE_0xF4)
            ? mTechSupportedByUicc1
            : mTechSupportedByUicc2;
  }
  DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf("%s: enter", fn);

  switch (mHostListnTechMask) {
    case 0x01:  // Host wants to listen ISO-DEP in A tech only then following
                // cases will arises:-
      // i.Tech A only UICC present(Dont route Tech B to HOST),
      // ii.Tech B only UICC present(Route Tech A to HOST),
      // iii.Tech AB UICC present(Dont route any tech to HOST)
      if (((mTechTableEntries[TECH_B_IDX].routeLoc ==
            SecureElement::getInstance().EE_HANDLE_0xF4) ||
           (mTechTableEntries[TECH_B_IDX].routeLoc == ROUTE_LOC_UICC2_ID)) &&
          ((((techSupportedByUICC & NFA_TECHNOLOGY_MASK_B) == 0) &&
            (techSupportedByUICC & NFA_TECHNOLOGY_MASK_A) !=
                0)))  // Tech A only supported UICC
      {
        // Tech A will goto UICC according to previous table
        // Disable Tech B entry as host wants to listen A only
        mTechTableEntries[TECH_B_IDX].enable = false;
      }
      if (((mTechTableEntries[TECH_A_IDX].routeLoc ==
            SecureElement::getInstance().EE_HANDLE_0xF4) ||
           (mTechTableEntries[TECH_A_IDX].routeLoc == ROUTE_LOC_UICC2_ID)) &&
          ((((techSupportedByUICC & NFA_TECHNOLOGY_MASK_A) == 0) &&
            (techSupportedByUICC & NFA_TECHNOLOGY_MASK_B) !=
                0)))  // Tech B only supported UICC
      {
        // Tech B will goto UICC according to previous table
        // Route Tech A to HOST as Host wants to listen A only
        mTechTableEntries[TECH_A_IDX].routeLoc = ROUTE_LOC_HOST_ID;
        /*Allow only (screen On+unlock) and (screen On+lock) power state when
         * routing to HOST*/
        mTechTableEntries[TECH_A_IDX].power =
            (mTechTableEntries[TECH_A_IDX].power & HOST_SCREEN_STATE_MASK);
        mTechTableEntries[TECH_A_IDX].enable = true;
      }
      if ((techSupportedByUICC & 0x03) == 0x03)  // AB both supported UICC
      {
        // Do Nothing
        // Tech A and Tech B will goto according to previous table
        // HCE A only / HCE-B only functionality wont work in this case
      }
      break;
    case 0x02:  // Host wants to listen ISO-DEP in B tech only then if Cases:
                // Tech A only UICC present(Route Tech B to HOST), Tech B only
                // UICC present(Dont route Tech A to HOST), Tech AB UICC
                // present(Dont route any tech to HOST)
      if (((mTechTableEntries[TECH_B_IDX].routeLoc ==
            SecureElement::getInstance().EE_HANDLE_0xF4) ||
           (mTechTableEntries[TECH_B_IDX].routeLoc == ROUTE_LOC_UICC2_ID)) &&
          ((((techSupportedByUICC & NFA_TECHNOLOGY_MASK_B) == 0) &&
            (techSupportedByUICC & NFA_TECHNOLOGY_MASK_A) !=
                0)))  // Tech A only supported UICC
      {
        // Tech A will goto UICC according to previous table
        // Route Tech B to HOST as host wants to listen B only
        mTechTableEntries[TECH_B_IDX].routeLoc = ROUTE_LOC_HOST_ID;
        /*Allow only (screen On+unlock) and (screen On+lock) power state when
         * routing to HOST*/
        mTechTableEntries[TECH_B_IDX].power =
            (mTechTableEntries[TECH_A_IDX].power & HOST_SCREEN_STATE_MASK);
        mTechTableEntries[TECH_B_IDX].enable = true;
      }
      if (((mTechTableEntries[TECH_A_IDX].routeLoc ==
            SecureElement::getInstance().EE_HANDLE_0xF4) ||
           (mTechTableEntries[TECH_A_IDX].routeLoc == ROUTE_LOC_UICC2_ID)) &&
          ((((techSupportedByUICC & NFA_TECHNOLOGY_MASK_A) == 0) &&
            (techSupportedByUICC & NFA_TECHNOLOGY_MASK_B) !=
                0)))  // Tech B only supported UICC
      {
        // Tech B will goto UICC according to previous table
        // Disable Tech A to HOST as host wants to listen B only
        mTechTableEntries[TECH_A_IDX].enable = false;
      }
      if ((techSupportedByUICC & 0x03) == 0x03)  // AB both supported UICC
      {
        // Do Nothing
        // Tech A and Tech B will goto UICC
        // HCE A only / HCE-B only functionality wont work in this case
      }
      break;
    case 0x03:
    case 0x07:  // Host wants to listen ISO-DEP in AB both tech then if Cases:
                // Tech A only UICC present(Route Tech B to HOST), Tech B only
                // UICC present(Route Tech A to HOST), Tech AB UICC present(Dont
                // route any tech to HOST)
      /*If selected EE is UICC and it supports Bonly , then Set Tech A to Host
       */
      /*Host doesn't support Tech Routing, To enable FWD functionality enabling
       * tech route to Host.*/
      if (((mTechTableEntries[TECH_A_IDX].routeLoc ==
            SecureElement::getInstance().EE_HANDLE_0xF4) ||
           (mTechTableEntries[TECH_A_IDX].routeLoc == ROUTE_LOC_UICC2_ID)) &&
          ((((techSupportedByUICC & NFA_TECHNOLOGY_MASK_A) == 0) &&
            (techSupportedByUICC & NFA_TECHNOLOGY_MASK_B) != 0))) {
        mTechTableEntries[TECH_A_IDX].routeLoc = ROUTE_LOC_HOST_ID;
        /*Allow only (screen On+unlock) and (screen On+lock) power state when
         * routing to HOST*/
        mTechTableEntries[TECH_A_IDX].power =
            (mTechTableEntries[TECH_A_IDX].power & HOST_SCREEN_STATE_MASK);
        mTechTableEntries[TECH_A_IDX].enable = true;
      }
      /*If selected EE is UICC and it supports Aonly , then Set Tech B to Host*/
      if (((mTechTableEntries[TECH_B_IDX].routeLoc ==
            SecureElement::getInstance().EE_HANDLE_0xF4) ||
           (mTechTableEntries[TECH_B_IDX].routeLoc == ROUTE_LOC_UICC2_ID)) &&
          ((((techSupportedByUICC & NFA_TECHNOLOGY_MASK_B) == 0) &&
            (techSupportedByUICC & NFA_TECHNOLOGY_MASK_A) != 0))) {
        mTechTableEntries[TECH_B_IDX].routeLoc = ROUTE_LOC_HOST_ID;
        /*Allow only (screen On+unlock) and (screen On+lock) power state when
         * routing to HOST*/
        mTechTableEntries[TECH_B_IDX].power =
            (mTechTableEntries[TECH_A_IDX].power & HOST_SCREEN_STATE_MASK);
        mTechTableEntries[TECH_B_IDX].enable = true;
      }
      if ((techSupportedByUICC & 0x03) == 0x03)  // AB both supported UICC
      {
        // Do Nothing
        // Tech A and Tech B will goto UICC
        // HCE A only / HCE-B only functionality wont work in this case
      }
      break;
  }
  dumpTables(3);
  DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf("%s: exit", fn);
}

void RoutingManager::dumpTables(int xx) {
  switch (xx) {
    case 1:  // print only proto table
      DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf(
          "--------------------Proto Table Entries------------------");
      for (int xx = 0; xx < AVAILABLE_PROTO_ENTRIES(); xx++) {
        DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf(
            "|Index=%d|RouteLoc=0x%03X|Proto=0x%02X|Power=0x%02X|Enable=0x%"
            "01X|",
            xx, mProtoTableEntries[xx].routeLoc,
            mProtoTableEntries[xx].protocol, mProtoTableEntries[xx].power,
            mProtoTableEntries[xx].enable);
      }
      DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf(
          "---------------------------------------------------------");
      break;
    case 2:  // print Lmrt proto table
      DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf(
          "----------------------------------------Lmrt Proto "
          "Entries------------------------------------");
      for (int xx = 0; xx < AVAILABLE_PROTO_ENTRIES(); xx++) {
        DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf(
            "|Index=%d|nfceeID=0x%03X|SWTCH-ON=0x%02X|SWTCH-OFF=0x%02X|BAT-OFF="
            "0x%02X|SCRN-LOCK=0x%02X|SCRN-OFF=0x%02X|SCRN-OFF_LOCK=0x%02X",
            xx, mLmrtEntries[xx].nfceeID, mLmrtEntries[xx].proto_switch_on,
            mLmrtEntries[xx].proto_switch_off,
            mLmrtEntries[xx].proto_battery_off,
            mLmrtEntries[xx].proto_screen_lock,
            mLmrtEntries[xx].proto_screen_off,
            mLmrtEntries[xx].proto_screen_off_lock);
      }
      DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf(
          "--------------------------------------------------------------------"
          "--------------------------");
      break;
    case 3:  // print only tech table
      DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf(
          "--------------------Tech Table Entries------------------");
      for (int xx = 0; xx < MAX_TECH_ENTRIES; xx++) {
        DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf(
            "|Index=%d|RouteLoc=0x%03X|Tech=0x%02X|Power=0x%02X|Enable=0x%01X|",
            xx, mTechTableEntries[xx].routeLoc,
            mTechTableEntries[xx].technology, mTechTableEntries[xx].power,
            mTechTableEntries[xx].enable);
      }
      DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf(
          "--------------------------------------------------------");
      break;
    case 4:  // print Lmrt tech table
      DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf(
          "-----------------------------------------Lmrt Tech "
          "Entries------------------------------------");
      for (int xx = 0; xx < MAX_TECH_ENTRIES; xx++) {
        DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf(
            "|Index=%d|nfceeID=0x%03X|SWTCH-ON=0x%02X|SWTCH-OFF=0x%02X|BAT-OFF="
            "0x%02X|SCRN-LOCK=0x%02X|SCRN-OFF=0x%02X|SCRN-OFF_LOCK=0x%02X",
            xx, mLmrtEntries[xx].nfceeID, mLmrtEntries[xx].tech_switch_on,
            mLmrtEntries[xx].tech_switch_off, mLmrtEntries[xx].tech_battery_off,
            mLmrtEntries[xx].tech_screen_lock, mLmrtEntries[xx].tech_screen_off,
            mLmrtEntries[xx].tech_screen_off_lock);
      }
      DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf(
          "--------------------------------------------------------------------"
          "--------------------------");
      break;
  }
}
#endif

#if (NXP_EXTNS == TRUE)
bool RoutingManager::clearRoutingEntry(int type) {
  DLOG_IF(INFO, nfc_debug_enabled)
      << StringPrintf("%s: Enter . Clear Routing Type = %d", __func__, type);
  tNFA_STATUS nfaStat = NFA_STATUS_FAILED;
  tNFA_HANDLE ee_handleList[nfcFL.nfccFL._NFA_EE_MAX_EE_SUPPORTED];
  uint8_t i, count;
  SyncEventGuard guard(mRoutingEvent);
  SecureElement::getInstance().getEeHandleList(ee_handleList, &count);
  if (count > nfcFL.nfccFL._NFA_EE_MAX_EE_SUPPORTED) {
    count = nfcFL.nfccFL._NFA_EE_MAX_EE_SUPPORTED;
    DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf(
        "Count is more than SecureElement::MAX_NUM_EE,Forcing to "
        "SecureElement::MAX_NUM_EE");
  }
  if (NFA_SET_TECHNOLOGY_ROUTING & type) {
    for (i = 0; i < count; i++) {
      nfaStat = NFA_EeClearDefaultTechRouting(
          ee_handleList[i], (NFA_TECHNOLOGY_MASK_A | NFA_TECHNOLOGY_MASK_B |
                             NFA_TECHNOLOGY_MASK_F));
      if (nfaStat == NFA_STATUS_OK) {
        mRoutingEvent.wait();
      }
    }
    nfaStat = NFA_EeClearDefaultTechRouting(
        NFA_EE_HANDLE_DH, (NFA_TECHNOLOGY_MASK_A | NFA_TECHNOLOGY_MASK_B |
                           NFA_TECHNOLOGY_MASK_F));
    if (nfaStat == NFA_STATUS_OK) {
      mRoutingEvent.wait();
    }
  }
  if (NFA_SET_PROTOCOL_ROUTING & type) {
    for (i = 0; i < count; i++) {
      nfaStat = NFA_EeClearDefaultProtoRouting(
          ee_handleList[i],
          (NFA_PROTOCOL_MASK_ISO_DEP | NFC_PROTOCOL_MASK_ISO7816));
      if (nfaStat == NFA_STATUS_OK) {
        mRoutingEvent.wait();
      }
    }
    nfaStat = NFA_EeClearDefaultProtoRouting(
        NFA_EE_HANDLE_DH,
        (NFA_PROTOCOL_MASK_ISO_DEP | NFC_PROTOCOL_MASK_ISO7816));
    if (nfaStat == NFA_STATUS_OK) {
      mRoutingEvent.wait();
    }
  }

  if (NFA_SET_AID_ROUTING & type) {
    clearAidTable();
  }
  return nfaStat;
}

/*
 * In NCI2.0 Protocol 7816 routing is replaced with empty AID
 * Routing entry Format :
 *  Type   = [0x12]
 *  Length = 2 [0x02]
 *  Value  = [Route_loc, Power_state]
 * */
void RoutingManager::setEmptyAidEntry(int routeAndPowerState) {
  DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf("%s: enter", __func__);
  uint32_t routeLoc = ((routeAndPowerState >> 8) & 0xFF);
  uint32_t power = (routeAndPowerState & 0xFF);
  int max_tech_mask = 0;

  routeLoc = ((routeLoc == 0x00)
                  ? ROUTE_LOC_HOST_ID
                  : ((routeLoc == 0x01)
                         ? ROUTE_LOC_ESE_ID
                         : getUiccRouteLocId(routeLoc)));

  DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf("%s: route %x", __func__, routeLoc);
  if (routeLoc == ROUTE_LOC_HOST_ID) power &= 0x11;
  if (routeLoc == NFA_HANDLE_INVALID) {
    LOG(ERROR) << StringPrintf("%s: Invalid routeLoc. Return.", __func__);
    return;
  }
  max_tech_mask = SecureElement::getInstance().getSETechnology(routeLoc);
  if ((routeLoc != ROUTE_LOC_HOST_ID) && ((max_tech_mask & 0x03) == 0)) {
    return;
  }

  tNFA_STATUS nfaStat =
      NFA_EeAddAidRouting(routeLoc, 0, NULL, mSecureNfcEnabled ? 0x01 : power,
                          AID_ROUTE_QUAL_PREFIX);
  DLOG_IF(INFO, nfc_debug_enabled)
      << StringPrintf("%s: Status :0x%2x", __func__, nfaStat);
}
#endif
bool RoutingManager::addAidRouting(const uint8_t* aid, uint8_t aidLen,
                                   int route, int aidInfo, int power) {
  static const char fn[] = "RoutingManager::addAidRouting";
  uint8_t powerState = 0x01;
  DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf("%s: enter", fn);
#if (NXP_EXTNS == TRUE)
  tNFA_HANDLE handle;
  tNFA_HANDLE current_handle;
  SecureElement& se = SecureElement::getInstance();

  if ((aid == nullptr) && (aidLen == 0x00)) {
    power = mCeRouteStrictDisable ? power : (power & POWER_STATE_MASK);
  }

  DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf(
      "%s: enter, route:%x power:0x%x aidInfo:%x", fn, route, power, aidInfo);
  handle = SecureElement::getInstance().getEseHandleFromGenericId(route);
  DLOG_IF(INFO, nfc_debug_enabled)
      << StringPrintf("%s: enter, route:%x", fn, handle);
  if (handle == NFA_HANDLE_INVALID) {
    return false;
  }
  if (mAddAid == 0x00) {
    DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf(
        "%s: enter, mAddAid set to 0 from config file, ignoring all aids", fn);
    return false;
  }
  if (nfcFL.nfccFL._NFCC_DYNAMIC_DUAL_UICC) {
    current_handle =
        ((handle == SecureElement::EE_HANDLE_0xF3)
             ? 0xF3
             : (handle == se.EE_HANDLE_0xF4) ? SecureElement::UICC_ID
                                             : SecureElement::UICC2_ID);
  } else
    current_handle =
        ((handle == SecureElement::EE_HANDLE_0xF3) ? SecureElement::ESE_ID
                                                   : SecureElement::UICC_ID);

  if (handle == 0x400) current_handle = 0x00;

  DLOG_IF(INFO, nfc_debug_enabled)
      << StringPrintf("%s: enter, mDefaultEe:%x", fn, current_handle);
  // SecureElement::getInstance().activate(current_handle);
  // Set power config

  SyncEventGuard guard(SecureElement::getInstance().mAidAddRemoveEvent);
#endif
  if (!mSecureNfcEnabled) {
    if (power == 0x00) {
      powerState = (route != SecureElement::DH_ID)
                       ? mOffHostAidRoutingPowerState
                       : HOST_PWR_STATE;
    } else {
      powerState = (route != SecureElement::DH_ID)
                       ? mOffHostAidRoutingPowerState & power
                       : power;
    }
  }
  if (handle == ROUTE_LOC_HOST_ID) powerState &= 0x11;
  tNFA_STATUS nfaStat =
      NFA_EeAddAidRouting(handle, aidLen, (uint8_t*)aid, powerState, aidInfo);

  if (nfaStat == NFA_STATUS_OK) {
    DLOG_IF(INFO, nfc_debug_enabled) << fn << ": routed AID";
#if (NXP_EXTNS == TRUE)
    SecureElement::getInstance().mAidAddRemoveEvent.wait();
#endif
    return true;
  } else {
    LOG(ERROR) << fn << ": failed to route AID";
    return false;
  }
}

bool RoutingManager::removeAidRouting(const uint8_t* aid, uint8_t aidLen) {
  static const char fn[] = "RoutingManager::removeAidRouting";
  DLOG_IF(INFO, nfc_debug_enabled) << fn << ": enter";
  SyncEventGuard guard(SecureElement::getInstance().mAidAddRemoveEvent);
  tNFA_STATUS nfaStat = NFA_EeRemoveAidRouting(aidLen, (uint8_t*)aid);
  if (nfaStat == NFA_STATUS_OK) {
    SecureElement::getInstance().mAidAddRemoveEvent.wait();
    DLOG_IF(INFO, nfc_debug_enabled) << fn << ": removed AID";
    return true;
  } else {
    LOG(WARNING) << fn << ": failed to remove AID";
    return false;
  }
}

#if (NXP_EXTNS == TRUE)
void RoutingManager::setDefaultTechRouting(int seId, int tech_switchon,
                                           int tech_switchoff) {
  SecureElement& se = SecureElement::getInstance();
  DLOG_IF(INFO, nfc_debug_enabled)
      << StringPrintf("ENTER setDefaultTechRouting");
  tNFA_STATUS nfaStat = NFA_STATUS_FAILED;
  /*// !!! CLEAR ALL REGISTERED TECHNOLOGIES !!!*/
  {
    SyncEventGuard guard(mRoutingEvent);
    tNFA_STATUS status =
        NFA_EeSetDefaultTechRouting(0x400, 0, 0, 0, 0, 0, 0);  // HOST clear
    if (status == NFA_STATUS_OK) {
      mRoutingEvent.wait();
    }
  }

  {
    SyncEventGuard guard(mRoutingEvent);
    tNFA_STATUS status = NFA_EeSetDefaultTechRouting(se.EE_HANDLE_0xF4, 0, 0, 0,
                                                     0, 0, 0);  // UICC clear
    if (status == NFA_STATUS_OK) {
      mRoutingEvent.wait();
    }
  }

  {
    SyncEventGuard guard(mRoutingEvent);
    tNFA_STATUS status = NFA_EeSetDefaultTechRouting(
        SecureElement::EE_HANDLE_0xF3, 0, 0, 0, 0, 0, 0);  // SMX clear
    if (status == NFA_STATUS_OK) {
      mRoutingEvent.wait();
    }
  }

  if (nfcFL.nfccFL._NFC_NXP_STAT_DUAL_UICC_WO_EXT_SWITCH ||
      nfcFL.nfccFL._NFCC_DYNAMIC_DUAL_UICC) {
    SyncEventGuard guard(mRoutingEvent);
    tNFA_STATUS status = NFA_EeSetDefaultTechRouting(
        SecureElement::EE_HANDLE_0xF8, 0, 0, 0, 0, 0, 0);  // SMX clear
    if (status == NFA_STATUS_OK) {
      mRoutingEvent.wait();
    }
  }

  {
    SyncEventGuard guard(mRoutingEvent);
    if (mCeRouteStrictDisable == 0x01) {
      nfaStat = NFA_EeSetDefaultTechRouting(
          seId, tech_switchon, tech_switchoff, 0,
          NFA_TECHNOLOGY_MASK_A | NFA_TECHNOLOGY_MASK_B,
          NFA_TECHNOLOGY_MASK_A | NFA_TECHNOLOGY_MASK_B,
          NFA_TECHNOLOGY_MASK_A | NFA_TECHNOLOGY_MASK_B);
    } else {
      nfaStat = NFA_EeSetDefaultTechRouting(seId, tech_switchon, tech_switchoff,
                                            0, 0, 0, 0);
    }
    if (nfaStat == NFA_STATUS_OK) {
      mRoutingEvent.wait();
      DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf("tech routing SUCCESS");
    } else {
      LOG(ERROR) << StringPrintf("Fail to set default tech routing");
    }
  }

  nfaStat = NFA_EeUpdateNow();
  if (nfaStat != NFA_STATUS_OK) {
    LOG(ERROR) << StringPrintf("Failed to commit routing configuration");
  }
}

void RoutingManager::setDefaultProtoRouting(int seId, int proto_switchon,
                                            int proto_switchoff) {
  tNFA_STATUS nfaStat = NFA_STATUS_FAILED;
  DLOG_IF(INFO, nfc_debug_enabled)
      << StringPrintf("ENTER setDefaultProtoRouting");
  SyncEventGuard guard(mRoutingEvent);
  if (mCeRouteStrictDisable == 0x01) {
    nfaStat = NFA_EeSetDefaultProtoRouting(
        seId, proto_switchon, mSecureNfcEnabled ? 0 : proto_switchoff, 0,
        mSecureNfcEnabled ? 0 : NFA_PROTOCOL_MASK_ISO_DEP,
        mSecureNfcEnabled ? 0 : NFA_PROTOCOL_MASK_ISO_DEP,
        mSecureNfcEnabled ? 0 : NFA_PROTOCOL_MASK_ISO_DEP);
  } else {
    nfaStat = NFA_EeSetDefaultProtoRouting(
        seId, proto_switchon, mSecureNfcEnabled ? 0 : proto_switchoff, 0, 0, 0,
        0);
  }
  if (nfaStat == NFA_STATUS_OK) {
    mRoutingEvent.wait();
    DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf("proto routing SUCCESS");
  } else {
    LOG(ERROR) << StringPrintf("Fail to set default proto routing");
  }
  //    nfaStat = NFA_EeUpdateNow();
  //    if (nfaStat != NFA_STATUS_OK){
  //        LOG(ERROR) << StringPrintf("Failed to commit routing
  //        configuration");
  //    }
}

bool RoutingManager::setRoutingEntry(int type, int value, int route,
                                     int power) {
  static const char fn[] = "RoutingManager::setRoutingEntry";
  DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf(
      "%s: enter, >>>>>>>> type:0x%x value =0x%x route:%x power:0x%x", fn, type,
      value, route, power);
  unsigned long max_tech_mask = 0x03;
  unsigned long uiccListenTech = 0;
  unsigned long eseListenTech = 0;

  if (!nfcFL.nfccFL._NFCC_DYNAMIC_DUAL_UICC) {
    if (nfcManager_getUiccRoute(sCurrentSelectedUICCSlot) != 0xFF) {
      max_tech_mask = SecureElement::getInstance().getSETechnology(
          nfcManager_getUiccRoute(sCurrentSelectedUICCSlot));
    } else {
      max_tech_mask = SecureElement::getInstance().getSETechnology(
          SecureElement::getInstance().EE_HANDLE_0xF4);
    }
  } else {
    max_tech_mask = SecureElement::getInstance().getSETechnology(
        SecureElement::getInstance().EE_HANDLE_0xF4);
  }

  DLOG_IF(INFO, nfc_debug_enabled)
      << StringPrintf("%s: enter,max_tech_mask :%lx", fn, max_tech_mask);

  tNFA_STATUS nfaStat = NFA_STATUS_FAILED;
  tNFA_HANDLE ee_handle = NFA_HANDLE_INVALID;
  uint8_t switch_on_mask = 0x00;
  uint8_t switch_off_mask = 0x00;
  uint8_t battery_off_mask = 0x00;
  uint8_t screen_lock_mask = 0x00;
  uint8_t screen_off_mask = 0x00;
  uint8_t screen_off_lock_mask = 0x00;
  uint8_t protocol_mask = 0x00;

  if (nfcFL.nfccFL._NFCC_DYNAMIC_DUAL_UICC && nfcFL.nfccFL._NFC_NXP_STAT_DUAL_UICC_WO_EXT_SWITCH) {
    if (nfcManager_getUiccRoute(sCurrentSelectedUICCSlot) != 0xFF) {
      ee_handle =
          ((route == 0x01)
               ? 0x4C0
               : ((route == 0x02)
                      ? nfcManager_getUiccRoute(sCurrentSelectedUICCSlot)
                      : NFA_HANDLE_INVALID));
    } else {
      ee_handle =
          ((route == 0x01)
               ? 0x4C0
               : ((route == 0x02) ? SecureElement::getInstance().EE_HANDLE_0xF4
                                  : NFA_HANDLE_INVALID));
    }
  } else {
    ee_handle =
        ((route == 0x01)
             ? 0x4C0
             : ((route == 0x02) ? SecureElement::getInstance().EE_HANDLE_0xF4
                                : NFA_HANDLE_INVALID));
  }

  if (0x00 == route) {
    ee_handle = 0x400;
  }
  if (ee_handle == NFA_HANDLE_INVALID) {
    DLOG_IF(INFO, nfc_debug_enabled)
        << StringPrintf("%s: enter, handle:%x invalid", fn, ee_handle);
    return nfaStat;
  }

  tNFA_HANDLE ActDevHandle = NFA_HANDLE_INVALID;
  uint8_t count, seId = 0;
  uint8_t isSeIDPresent = 0;
  tNFA_HANDLE ee_handleList[SecureElement::MAX_NUM_EE];
  SecureElement::getInstance().getEeHandleList(ee_handleList, &count);

  for (int i = 0; ((count != 0) && (i < count)); i++) {
    seId = SecureElement::getInstance().getGenericEseId(ee_handleList[i]);
    ActDevHandle = SecureElement::getInstance().getEseHandleFromGenericId(seId);
    DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf(
        "%s: enter, ee_handleList[%d]:%x", fn, i, ee_handleList[i]);
    if ((ee_handle != 0x400) && (ee_handle == ActDevHandle)) {
      isSeIDPresent = 1;
      break;
    }
  }

  max_tech_mask = SecureElement::getInstance().getSETechnology(ee_handle);
  DLOG_IF(INFO, nfc_debug_enabled)
      << StringPrintf("%s: enter,max_tech_mask :%lx", fn, max_tech_mask);
  if (NFA_SET_TECHNOLOGY_ROUTING == type) {
    /*  Masking with available SE Technologies */
    value &= max_tech_mask;
    DLOG_IF(INFO, nfc_debug_enabled)
        << StringPrintf("%s: enter >>>> max_tech_mask :%lx value :0x%x", fn,
                        max_tech_mask, value);
    switch_on_mask = (power & 0x01) ? value : 0;
    switch_off_mask = (power & 0x02) ? value : 0;
    battery_off_mask = (power & 0x04) ? value : 0;
    screen_off_mask = (power & 0x08) ? value : 0;
    screen_lock_mask = (power & 0x10) ? value : 0;
    screen_off_lock_mask = (power & 0x20) ? value : 0;

    if ((max_tech_mask != 0x01) && (max_tech_mask == 0x02))  // type B only
    {
      switch_on_mask &= ~NFA_TECHNOLOGY_MASK_A;
      switch_off_mask &= ~NFA_TECHNOLOGY_MASK_A;
      battery_off_mask &= ~NFA_TECHNOLOGY_MASK_A;
      screen_off_mask &= ~NFA_TECHNOLOGY_MASK_A;
      screen_lock_mask &= ~NFA_TECHNOLOGY_MASK_A;
      screen_off_lock_mask &= ~NFA_TECHNOLOGY_MASK_A;
    } else if ((max_tech_mask == 0x01) &&
               (max_tech_mask != 0x02))  // type A only
    {
      switch_on_mask &= ~NFA_TECHNOLOGY_MASK_B;
      switch_off_mask &= ~NFA_TECHNOLOGY_MASK_B;
      battery_off_mask &= ~NFA_TECHNOLOGY_MASK_B;
      screen_off_mask &= ~NFA_TECHNOLOGY_MASK_B;
      screen_lock_mask &= ~NFA_TECHNOLOGY_MASK_B;
      screen_off_lock_mask &= ~NFA_TECHNOLOGY_MASK_B;
    }

    if ((mHostListnTechMask) && (mFwdFuntnEnable == true)) {
      if ((max_tech_mask != 0x01) && (max_tech_mask == 0x02)) {
        {
          SyncEventGuard guard(mRoutingEvent);
          if (mSecureNfcEnabled) {
            nfaStat = NFA_EeSetDefaultTechRouting(0x400, NFA_TECHNOLOGY_MASK_A,
                                                  0, 0, 0, 0, 0);
          } else {
            nfaStat = NFA_EeSetDefaultTechRouting(
                0x400, (mFwdFuntnEnable & 0x01) ? NFA_TECHNOLOGY_MASK_A : 0, 0,
                0, (mFwdFuntnEnable & 0x10) ? NFA_TECHNOLOGY_MASK_A : 0,
                (mFwdFuntnEnable & 0x08) ? NFA_TECHNOLOGY_MASK_A : 0,
                (mFwdFuntnEnable & 0x20) ? NFA_TECHNOLOGY_MASK_A : 0);
          }
          if (nfaStat == NFA_STATUS_OK)
            mRoutingEvent.wait();
          else {
            DLOG_IF(ERROR, nfc_debug_enabled)
                << StringPrintf("Fail to set tech routing");
          }
        }
      } else if ((max_tech_mask == 0x01) && (max_tech_mask != 0x02)) {
        {
          SyncEventGuard guard(mRoutingEvent);
          if (mSecureNfcEnabled) {
            nfaStat = NFA_EeSetDefaultTechRouting(0x400, NFA_TECHNOLOGY_MASK_B,
                                                  0, 0, 0, 0, 0);
          } else {
            nfaStat = NFA_EeSetDefaultTechRouting(
                0x400, (mFwdFuntnEnable & 0x01) ? NFA_TECHNOLOGY_MASK_B : 0, 0,
                0, (mFwdFuntnEnable & 0x10) ? NFA_TECHNOLOGY_MASK_B : 0,
                (mFwdFuntnEnable & 0x08) ? NFA_TECHNOLOGY_MASK_B : 0,
                (mFwdFuntnEnable & 0x20) ? NFA_TECHNOLOGY_MASK_B : 0);
          }
          if (nfaStat == NFA_STATUS_OK)
            mRoutingEvent.wait();
          else {
            DLOG_IF(ERROR, nfc_debug_enabled)
                << StringPrintf("Fail to set tech routing");
          }
        }
      }
    }
    {
      SyncEventGuard guard(mRoutingEvent);
      nfaStat = NFA_EeSetDefaultTechRouting(
          ee_handle, switch_on_mask, mSecureNfcEnabled ? 0 : switch_off_mask,
          mSecureNfcEnabled ? 0 : battery_off_mask,
          mSecureNfcEnabled ? 0 : screen_lock_mask,
          mSecureNfcEnabled ? 0 : screen_off_mask,
          mSecureNfcEnabled ? 0 : screen_off_lock_mask);
      if (nfaStat == NFA_STATUS_OK) {
        mRoutingEvent.wait();
        DLOG_IF(INFO, nfc_debug_enabled)
            << StringPrintf("tech routing SUCCESS");
      } else {
        DLOG_IF(ERROR, nfc_debug_enabled)
            << StringPrintf("Fail to set default tech routing");
      }
    }
  } else if (NFA_SET_PROTOCOL_ROUTING == type) {
    while (value) {
      if (value & 0x01) {
        protocol_mask = NFA_PROTOCOL_MASK_ISO_DEP;
        value &= ~(0x01);
      } else if (value & 0x02) {
        protocol_mask = NFA_PROTOCOL_MASK_NFC_DEP;
        value &= ~(0x02);
      } else if (value & 0x04) {
        protocol_mask = NFA_PROTOCOL_MASK_T3T;
        value &= ~(0x04);
      } else if (value & 0x20) {
        protocol_mask = NFC_PROTOCOL_MASK_ISO7816;
        value &= ~(0x20);
      }

      /*if NFCEE doesn't support tech A/B don't configure ISO-DEP/ISO7816 proto
       * route */
      if ((protocol_mask &
           (NFA_PROTOCOL_MASK_ISO_DEP | NFC_PROTOCOL_MASK_ISO7816)) &&
          (ee_handle != NFA_EE_HANDLE_DH) && ((max_tech_mask & 0x03) == 0)) {
        DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf(
            "%s: Proto Entry rejected. ee_handle 0x%x doesn't support proto "
            "mask 0x%x.",
            fn, ee_handle, protocol_mask);
        return nfaStat;
      }

      if (protocol_mask) {
        switch_on_mask = (power & 0x01) ? protocol_mask : 0;
        switch_off_mask = (power & 0x02) ? protocol_mask : 0;
        battery_off_mask = (power & 0x04) ? protocol_mask : 0;
        screen_off_mask = (power & 0x08) ? protocol_mask : 0;
        screen_lock_mask = (power & 0x10) ? protocol_mask : 0;
        screen_off_lock_mask = (power & 0x20) ? protocol_mask : 0;
        DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf(
            "%s: enter >>>> ee_handle:%x %x %x %x %x %x %x", fn, ee_handle,
            switch_on_mask, switch_off_mask, battery_off_mask, screen_lock_mask,
            screen_off_mask, screen_off_lock_mask);
        registerProtoRouteEnrty(ee_handle, switch_on_mask,
                                mSecureNfcEnabled ? 0 : switch_off_mask,
                                mSecureNfcEnabled ? 0 : battery_off_mask,
                                mSecureNfcEnabled ? 0 : screen_lock_mask,
                                mSecureNfcEnabled ? 0 : screen_off_mask,
                                mSecureNfcEnabled ? 0 : screen_off_lock_mask);
        protocol_mask = 0;
      }
    }
  }

  uiccListenTech = NfcConfig::getUnsigned(NAME_UICC_LISTEN_TECH_MASK, 0x07);
  if ((ActDevHandle != NFA_HANDLE_INVALID) && (0 != uiccListenTech)) {
    if ((ActDevHandle != SecureElement::EE_HANDLE_0xF3) &&
        (ActDevHandle != 0x00)) {
      {
        SyncEventGuard guard(SecureElement::getInstance().mUiccListenEvent);
        nfaStat = NFA_CeConfigureUiccListenTech(ActDevHandle, 0x00);
        if (nfaStat == NFA_STATUS_OK) {
          SecureElement::getInstance().mUiccListenEvent.wait();
        } else
          DLOG_IF(ERROR, nfc_debug_enabled)
              << StringPrintf("fail to start UICC listen");
      }
      {
        SyncEventGuard guard(SecureElement::getInstance().mUiccListenEvent);
        nfaStat = NFA_CeConfigureUiccListenTech(ActDevHandle,
                                                (uiccListenTech & 0x07));
        if (nfaStat == NFA_STATUS_OK) {
          SecureElement::getInstance().mUiccListenEvent.wait();
        } else
          DLOG_IF(ERROR, nfc_debug_enabled)
              << StringPrintf("fail to start UICC listen");
      }
    }
  }
  eseListenTech = NfcConfig::getUnsigned(NAME_NXP_ESE_LISTEN_TECH_MASK, 0x07);
  if ((ActDevHandle != NFA_HANDLE_INVALID) && (0 != eseListenTech)) {
    if (ActDevHandle == SecureElement::EE_HANDLE_0xF3) {
      {
        SyncEventGuard guard(SecureElement::getInstance().mEseListenEvent);
        nfaStat = NFA_CeConfigureEseListenTech(ActDevHandle, 0x00);
        if (nfaStat == NFA_STATUS_OK) {
          SecureElement::getInstance().mEseListenEvent.wait();
        } else
          DLOG_IF(ERROR, nfc_debug_enabled)
              << StringPrintf("fail to start eSE listen");
      }
      {
        SyncEventGuard guard(SecureElement::getInstance().mEseListenEvent);
        nfaStat =
            NFA_CeConfigureEseListenTech(ActDevHandle, (eseListenTech & 0x07));
        if (nfaStat == NFA_STATUS_OK) {
          SecureElement::getInstance().mEseListenEvent.wait();
        } else
          DLOG_IF(ERROR, nfc_debug_enabled)
              << StringPrintf("fail to start eSE listen");
      }
    }
  }
  return nfaStat;
}

bool RoutingManager::clearAidTable() {
  static const char fn[] = "RoutingManager::clearAidTable";
  DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf("%s: enter", fn);
  SyncEventGuard guard(SecureElement::getInstance().mAidAddRemoveEvent);
  tNFA_STATUS nfaStat = NFA_EeRemoveAidRouting(NFA_REMOVE_ALL_AID_LEN,
                                               (uint8_t*)NFA_REMOVE_ALL_AID);
  if (nfaStat == NFA_STATUS_OK) {
    SecureElement::getInstance().mAidAddRemoveEvent.wait();
    DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf("%s: removed AID", fn);
    return true;
  } else {
    LOG(ERROR) << StringPrintf("%s: failed to remove AID", fn);
    return false;
  }
}

#endif

bool RoutingManager::commitRouting() {
  static const char fn[] = "RoutingManager::commitRouting";
  tNFA_STATUS nfaStat = 0;
  DLOG_IF(INFO, nfc_debug_enabled) << fn;
  {
    RoutingManager::getInstance().LmrtRspTimer.set(1000, LmrtRspTimerCb);
    SyncEventGuard guard(mEeUpdateEvent);
    nfaStat = NFA_EeUpdateNow();
    if (nfaStat == NFA_STATUS_OK) {
      mEeUpdateEvent.wait();  // wait for NFA_EE_UPDATED_EVT
    }
  }
  return (nfaStat == NFA_STATUS_OK);
}

void RoutingManager::onNfccShutdown() {
  static const char fn[] = "RoutingManager:onNfccShutdown";
  tNFA_STATUS nfaStat = NFA_STATUS_FAILED;
  uint8_t actualNumEe = nfcFL.nfccFL._NFA_EE_MAX_EE_SUPPORTED;
  tNFA_EE_INFO eeInfo[actualNumEe];

  if (mDefaultTechABFRoute == 0x00) return;

  memset(&eeInfo, 0, sizeof(eeInfo));

  if ((nfaStat = NFA_EeGetInfo(&actualNumEe, eeInfo)) != NFA_STATUS_OK) {
    LOG(ERROR) << StringPrintf("%s: fail get info; error=0x%X", fn, nfaStat);
    return;
  }
  if (actualNumEe != 0) {
    for (uint8_t xx = 0; xx < actualNumEe; xx++) {
      if ((eeInfo[xx].ee_interface[0] != NCI_NFCEE_INTERFACE_HCI_ACCESS) &&
          (eeInfo[xx].ee_status == NFA_EE_STATUS_ACTIVE)) {
        DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf(
            "%s: Handle: 0x%04x Change Status Active to Inactive", fn,
            eeInfo[xx].ee_handle);
#if (NXP_EXTNS == TRUE)
        if ((nfaStat = SecureElement::getInstance().SecElem_EeModeSet(
                 eeInfo[xx].ee_handle, NFA_EE_MD_DEACTIVATE)) != NFA_STATUS_OK)
#endif
        {
          LOG(ERROR) << StringPrintf("Failed to set EE inactive");
        }
      }
    }
  } else {
    DLOG_IF(INFO, nfc_debug_enabled)
        << StringPrintf("%s: No active EEs found", fn);
  }
}

void RoutingManager::notifyActivated(uint8_t technology) {
  JNIEnv* e = NULL;
  ScopedAttach attach(mNativeData->vm, &e);
  if (e == NULL) {
    LOG(ERROR) << "jni env is null";
    return;
  }

  e->CallVoidMethod(mNativeData->manager,
                    android::gCachedNfcManagerNotifyHostEmuActivated,
                    (int)technology);
  if (e->ExceptionCheck()) {
    e->ExceptionClear();
    LOG(ERROR) << "fail notify";
  }
}

void RoutingManager::notifyDeactivated(uint8_t technology) {
  SecureElement::getInstance().notifyListenModeState(false);
  mRxDataBuffer.clear();
  JNIEnv* e = NULL;
  ScopedAttach attach(mNativeData->vm, &e);
  if (e == NULL) {
    LOG(ERROR) << "jni env is null";
    return;
  }

  e->CallVoidMethod(mNativeData->manager,
                    android::gCachedNfcManagerNotifyHostEmuDeactivated,
                    (int)technology);
  if (e->ExceptionCheck()) {
    e->ExceptionClear();
    LOG(ERROR) << StringPrintf("fail notify");
  }
}

#if (NXP_EXTNS == TRUE)
void RoutingManager::nfcFRspTimerCb(union sigval) {
  if (!nfcFL.nfccFL._NXP_NFCC_EMPTY_DATA_PACKET) {
    DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf(
        "%s; NFCC_EMPTY_DATA_PACKET not available.Returning", __func__);
    return;
  }
  static const char fn[] = "RoutingManager::nfcFRspTimerCb";
  DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf("%s; enter", fn);
  if (android::gIsEmptyRspSentByHceFApk)
    android::gIsEmptyRspSentByHceFApk = false;
  else
    android::nfcManager_sendEmptyDataMsg();
  DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf("%s; exit", fn);
}
#endif

void RoutingManager::handleData(uint8_t technology, const uint8_t* data,
                                uint32_t dataLen, tNFA_STATUS status) {
  if (status == NFC_STATUS_CONTINUE) {
    LOG(ERROR) << StringPrintf("jni env is null");
    if (dataLen > 0) {
      mRxDataBuffer.insert(mRxDataBuffer.end(), &data[0],
                           &data[dataLen]);  // append data; more to come
    }
    return;  // expect another NFA_CE_DATA_EVT to come
  } else if (status == NFA_STATUS_OK) {
    if (dataLen > 0) {
      mRxDataBuffer.insert(mRxDataBuffer.end(), &data[0],
                           &data[dataLen]);  // append data
#if (NXP_EXTNS == TRUE)
      if (nfcFL.nfccFL._NXP_NFCC_EMPTY_DATA_PACKET &&
          (technology == NFA_TECHNOLOGY_MASK_F)) {
        bool ret = false;
        ret = mNfcFRspTimer.set(mDefaultHCEFRspTimeout, nfcFRspTimerCb);
        if (!ret)
          DLOG_IF(INFO, nfc_debug_enabled)
              << StringPrintf("%s; rsp timer create failed", __func__);
      }
#endif
    }
    // entire data packet has been received; no more NFA_CE_DATA_EVT
  } else if (status == NFA_STATUS_FAILED) {
    LOG(ERROR) << "RoutingManager::handleData: read data fail";
    goto TheEnd;
  }
  {
    JNIEnv* e = NULL;
    ScopedAttach attach(mNativeData->vm, &e);
    if (e == NULL) {
      LOG(ERROR) << "jni env is null";
      goto TheEnd;
    }

    ScopedLocalRef<jobject> dataJavaArray(
        e, e->NewByteArray(mRxDataBuffer.size()));
    if (dataJavaArray.get() == NULL) {
      LOG(ERROR) << "fail allocate array";
      goto TheEnd;
    }

    e->SetByteArrayRegion((jbyteArray)dataJavaArray.get(), 0,
                          mRxDataBuffer.size(), (jbyte*)(&mRxDataBuffer[0]));
    if (e->ExceptionCheck()) {
      e->ExceptionClear();
      LOG(ERROR) << "fail fill array";
      goto TheEnd;
    }

    e->CallVoidMethod(mNativeData->manager,
                      android::gCachedNfcManagerNotifyHostEmuData,
                      (int)technology, dataJavaArray.get());
    if (e->ExceptionCheck()) {
      e->ExceptionClear();
      LOG(ERROR) << "fail notify";
    }
  }
TheEnd:
  mRxDataBuffer.clear();
}

void RoutingManager::stackCallback(uint8_t event,
                                   tNFA_CONN_EVT_DATA* eventData) {
  static const char fn[] = "RoutingManager::stackCallback";
  DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf("%s: event=0x%X", fn, event);
  RoutingManager& routingManager = RoutingManager::getInstance();

  SecureElement& se = SecureElement::getInstance();

  switch (event) {
    case NFA_CE_REGISTERED_EVT: {
      tNFA_CE_REGISTERED& ce_registered = eventData->ce_registered;
      DLOG_IF(INFO, nfc_debug_enabled)
          << StringPrintf("%s: NFA_CE_REGISTERED_EVT; status=0x%X; h=0x%X", fn,
                          ce_registered.status, ce_registered.handle);
      SyncEventGuard guard(routingManager.mCeRegisterEvent);
      if (ce_registered.status == NFA_STATUS_OK) {
        lastcehandle = ce_registered.handle;
      } else {
        lastcehandle = 0xFF;
      }
      routingManager.mCeRegisterEvent.notifyOne();
    } break;

    case NFA_CE_DEREGISTERED_EVT: {
      tNFA_CE_DEREGISTERED& ce_deregistered = eventData->ce_deregistered;
      DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf(
          "%s: NFA_CE_DEREGISTERED_EVT; h=0x%X", fn, ce_deregistered.handle);
      SyncEventGuard guard(routingManager.mCeDeRegisterEvent);
      routingManager.mCeDeRegisterEvent.notifyOne();
    } break;

    case NFA_CE_ACTIVATED_EVT: {
#if (NXP_EXTNS == TRUE)
      android::rfActivation = true;
#endif
      android::checkforTranscation(NFA_CE_ACTIVATED_EVT, (void*)eventData);
      routingManager.notifyActivated(NFA_TECHNOLOGY_MASK_A);
    } break;
    case NFA_DEACTIVATED_EVT:
    case NFA_CE_DEACTIVATED_EVT: {
      android::checkforTranscation(NFA_CE_DEACTIVATED_EVT, (void*)eventData);
      routingManager.notifyDeactivated(NFA_TECHNOLOGY_MASK_A);
      if (nfcFL.nfcNxpEse &&
          nfcFL.eseFL._NFCC_ESE_UICC_CONCURRENT_ACCESS_PROTECTION &&
          (se.mIsWiredModeOpen && se.mPassiveListenEnabled)) {
        se.startThread(0x00);
      }
    }
#if (NXP_EXTNS == TRUE)
      android::rfActivation = false;
#endif
      break;
    case NFA_CE_DATA_EVT: {
#if (NXP_EXTNS == TRUE)
      if (nfcFL.nfcNxpEse &&
          nfcFL.eseFL._NFCC_ESE_UICC_CONCURRENT_ACCESS_PROTECTION &&
          (nfcFL.eseFL._ESE_DUAL_MODE_PRIO_SCHEME !=
           nfcFL.eseFL._ESE_WIRED_MODE_RESUME)) {
        se.setDwpTranseiveState(false, NFCC_CE_DATA_EVT);
      }
#endif
      tNFA_CE_DATA& ce_data = eventData->ce_data;
      DLOG_IF(INFO, nfc_debug_enabled)
          << StringPrintf("%s: NFA_CE_DATA_EVT; stat=0x%X; h=0x%X; data len=%u",
                          fn, ce_data.status, ce_data.handle, ce_data.len);
      getInstance().handleData(NFA_TECHNOLOGY_MASK_A, ce_data.p_data,
                               ce_data.len, ce_data.status);
    } break;
  }
}
/*******************************************************************************
**
** Function:        nfaEeCallback
**
** Description:     Receive execution environment-related events from stack.
**                  event: Event code.
**                  eventData: Event data.
**
** Returns:         None
**
*******************************************************************************/
void RoutingManager::nfaEeCallback(tNFA_EE_EVT event,
                                   tNFA_EE_CBACK_DATA* eventData) {
  static const char fn[] = "RoutingManager::nfaEeCallback";

  SecureElement& se = SecureElement::getInstance();
  RoutingManager& routingManager = RoutingManager::getInstance();
  if (!eventData) {
    DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf(
          "%s: No eventdata", fn);
  return;
  }
  routingManager.mCbEventData = *eventData;

  switch (event) {
    case NFA_EE_REGISTER_EVT: {
      SyncEventGuard guard(routingManager.mEeRegisterEvent);
      DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf(
          "%s: NFA_EE_REGISTER_EVT; status=%u", fn, eventData->ee_register);
      routingManager.mEeRegisterEvent.notifyOne();
    } break;

    case NFA_EE_ADD_SYSCODE_EVT: {
      SyncEventGuard guard(routingManager.mRoutingEvent);
      routingManager.mRoutingEvent.notifyOne();
      DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf(
          "%s: NFA_EE_ADD_SYSCODE_EVT  status=%u", fn, eventData->status);
    } break;

    case NFA_EE_REMOVE_SYSCODE_EVT: {
      SyncEventGuard guard(routingManager.mRoutingEvent);
      routingManager.mRoutingEvent.notifyOne();
      DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf(
          "%s: NFA_EE_REMOVE_SYSCODE_EVT  status=%u", fn, eventData->status);
    } break;

    case NFA_EE_DEREGISTER_EVT: {
      DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf(
          "%s: NFA_EE_DEREGISTER_EVT; status=0x%X", fn, eventData->status);
      routingManager.mReceivedEeInfo = false;
    } break;

    case NFA_EE_MODE_SET_EVT: {
      SyncEventGuard guard(routingManager.mEeSetModeEvent);
      DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf(
          "%s: NFA_EE_MODE_SET_EVT; status: 0x%04X  handle: 0x%04X  "
          "mActiveEeHandle: 0x%04X",
          fn, eventData->mode_set.status, eventData->mode_set.ee_handle,
          se.mActiveEeHandle);
      routingManager.mEeSetModeEvent.notifyOne();
      se.notifyModeSet(eventData->mode_set.ee_handle,
                       !(eventData->mode_set.status),
                       eventData->mode_set.ee_status);
    } break;
#if (NXP_EXTNS == TRUE)
    case NFA_EE_SET_MODE_INFO_EVT: {
      DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf(
          "%s: NFA_EE_SET_MODE_INFO_EVT; nfcee_id = 0x%02x, status: 0x%04X ",
          fn, eventData->ee_set_mode_info.nfcee_id,
          eventData->ee_set_mode_info.status);
      se.mModeSetInfo = eventData->ee_set_mode_info.status;
      if (eventData->ee_set_mode_info.nfcee_id ==
          (se.EE_HANDLE_0xF3 & ~NFA_HANDLE_GROUP_EE)) {
        recovery = false;
        SyncEventGuard guard(se.mModeSetNtf);
        se.mModeSetNtf.notifyOne();
      }
    } break;

    case NFA_EE_DISCONNECT_EVT: {
      DLOG_IF(INFO, nfc_debug_enabled)
          << StringPrintf("%s: NFA_EE_DISCONNECT_EVT received", fn);
      SyncEventGuard guard(routingManager.mEEDisconnectEvt);
      routingManager.mEEDisconnectEvt.notifyOne();
    } break;

    case NFA_EE_PWR_LINK_CTRL_EVT:
      if (nfcFL.eseFL._WIRED_MODE_STANDBY) {
        DLOG_IF(INFO, nfc_debug_enabled)
            << StringPrintf("%s: NFA_EE_PWR_LINK_CTRL_EVT; status: 0x%04X ", fn,
                            eventData->pwr_lnk_ctrl.status);
        se.mPwrCmdstatus = eventData->pwr_lnk_ctrl.status;
        SyncEventGuard guard(se.mPwrLinkCtrlEvent);
        se.mPwrLinkCtrlEvent.notifyOne();
      }
      break;
#endif
    case NFA_EE_SET_TECH_CFG_EVT: {
      DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf(
          "%s: NFA_EE_SET_TECH_CFG_EVT; status=0x%X", fn, eventData->status);
      SyncEventGuard guard(routingManager.mRoutingEvent);
      routingManager.mRoutingEvent.notifyOne();
    } break;

    case NFA_EE_CLEAR_TECH_CFG_EVT: {
      DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf(
          "%s: NFA_EE_CLEAR_TECH_CFG_EVT; status=0x%X", fn, eventData->status);
      SyncEventGuard guard(routingManager.mRoutingEvent);
      routingManager.mRoutingEvent.notifyOne();
    } break;

    case NFA_EE_SET_PROTO_CFG_EVT: {
      DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf(
          "%s: NFA_EE_SET_PROTO_CFG_EVT; status=0x%X", fn, eventData->status);
      SyncEventGuard guard(routingManager.mRoutingEvent);
      routingManager.mRoutingEvent.notifyOne();
    } break;

    case NFA_EE_CLEAR_PROTO_CFG_EVT: {
      DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf(
          "%s: NFA_EE_CLEAR_PROTO_CFG_EVT; status=0x%X", fn, eventData->status);
      SyncEventGuard guard(routingManager.mRoutingEvent);
      routingManager.mRoutingEvent.notifyOne();
    } break;

    case NFA_EE_ACTION_EVT: {
      tNFA_EE_ACTION& action = eventData->action;
      tNFC_APP_INIT& app_init = action.param.app_init;
      android::checkforTranscation(NFA_EE_ACTION_EVT, (void*)eventData);

      if (action.trigger == NFC_EE_TRIG_SELECT) {
        DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf(
            "%s: NFA_EE_ACTION_EVT; h=0x%X; trigger=select (0x%X); aid len=%u",
            fn, action.ee_handle, action.trigger, app_init.len_aid);
      } else if (action.trigger == NFC_EE_TRIG_APP_INIT) {
        DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf(
            "%s: NFA_EE_ACTION_EVT; h=0x%X; trigger=app-init (0x%X); aid "
            "len=%u; data len=%u",
            fn, action.ee_handle, action.trigger, app_init.len_aid,
            app_init.len_data);
        // if app-init operation is successful;
        // app_init.data[] contains two bytes, which are the status codes of the
        // event;
        // app_init.data[] does not contain an APDU response;
        // see EMV Contactless Specification for Payment Systems; Book B; Entry
        // Point Specification;
        // version 2.1; March 2011; section 3.3.3.5;
        if ((app_init.len_data > 1) && (app_init.data[0] == 0x90) &&
            (app_init.data[1] == 0x00)) {
          se.notifyTransactionListenersOfAid(
              app_init.aid, app_init.len_aid, app_init.data, app_init.len_data,
              SecureElement::getInstance().getGenericEseId(
                  action.ee_handle & ~NFA_HANDLE_GROUP_EE));
        }
      } else if (action.trigger == NFC_EE_TRIG_RF_PROTOCOL)
        DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf(
            "%s: NFA_EE_ACTION_EVT; h=0x%X; trigger=rf protocol (0x%X)", fn,
            action.ee_handle, action.trigger);
      else if (action.trigger == NFC_EE_TRIG_RF_TECHNOLOGY)
        DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf(
            "%s: NFA_EE_ACTION_EVT; h=0x%X; trigger=rf tech (0x%X)", fn,
            action.ee_handle, action.trigger);
      else
        LOG(ERROR) << StringPrintf(
            "%s: NFA_EE_ACTION_EVT; h=0x%X; unknown trigger (0x%X)", fn,
            action.ee_handle, action.trigger);
#if ((NXP_EXTNS == TRUE))
      if (nfcFL.nfcNxpEse) {
        if (action.ee_handle == SecureElement::EE_HANDLE_0xF3) {
          LOG(ERROR) << StringPrintf(
              "%s: NFA_EE_ACTION_EVT; h=0x%X;DWP CL activated (0x%X)", fn,
              action.ee_handle, action.trigger);
          se.setCLState(true);
        }

        if (nfcFL.eseFL._ESE_DUAL_MODE_PRIO_SCHEME !=
            nfcFL.eseFL._ESE_WIRED_MODE_RESUME) {
          if (action.ee_handle == SecureElement::EE_HANDLE_0xF3 &&
              (action.trigger != NFC_EE_TRIG_RF_TECHNOLOGY) &&
              ((se.mIsAllowWiredInDesfireMifareCE) ||
               !(action.trigger == NFC_EE_TRIG_RF_PROTOCOL &&
                 action.param.protocol == NFA_PROTOCOL_ISO_DEP))) {
            LOG(ERROR) << StringPrintf("%s,Allow wired mode connection", fn);
            se.setDwpTranseiveState(false, NFCC_ACTION_NTF);
          } else {
            LOG(ERROR) << StringPrintf("%s,Blocked wired mode connection", fn);
            se.setDwpTranseiveState(true, NFCC_ACTION_NTF);
          }
        }
#endif
      }
    } break;

    case NFA_EE_DISCOVER_EVT: {
      uint8_t num_ee = eventData->ee_discover.num_ee;
      tNFA_EE_DISCOVER ee_disc_info = eventData->ee_discover;
      DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf(
          "%s: NFA_EE_DISCOVER_EVT; status=0x%X; num ee=%u", __func__,
          eventData->status, eventData->ee_discover.num_ee);
      if ((nfcFL.nfccFL._NFCEE_REMOVED_NTF_RECOVERY) &&
          (((mChipId != pn80T) &&
            (android::isNfcInitializationDone() == true)) ||
           ((mChipId == pn80T) &&
            (SecureElement::getInstance().mETSI12InitStatus ==
             NFA_STATUS_OK)))) {
        if ((mChipId == pn65T || mChipId == pn66T || mChipId == pn67T ||
             mChipId == pn80T || mChipId == pn81T)) {
          for (int xx = 0; xx < num_ee; xx++) {
            LOG(ERROR) << StringPrintf("xx=%d, ee_handle=0x0%x, status=0x0%x",
                                       xx, ee_disc_info.ee_info[xx].ee_handle,
                                       ee_disc_info.ee_info[xx].ee_status);
            if (ee_disc_info.ee_info[xx].ee_handle ==
                SecureElement::EE_HANDLE_0xF3) {
              if (ee_disc_info.ee_info[xx].ee_status == NFA_EE_STATUS_REMOVED) {
                recovery = true;
                routingManager.ee_removed_disc_ntf_handler(
                    ee_disc_info.ee_info[xx].ee_handle,
                    ee_disc_info.ee_info[xx].ee_status);
                break;
              } else if ((ee_disc_info.ee_info[xx].ee_status ==
                          NFA_EE_STATUS_ACTIVE) &&
                         (recovery == true)) {
                recovery = false;
                SyncEventGuard guard(se.mEEdatapacketEvent);
                se.mEEdatapacketEvent.notifyOne();
              }
            }
          }
        }
      }
      /*gSeDiscoverycount++ incremented for new NFCEE discovery;*/
      SecureElement::getInstance().updateNfceeDiscoverInfo();
      DLOG_IF(INFO, nfc_debug_enabled)
          << StringPrintf(" gSeDiscoverycount = %d gActualSeCount=%d",
                          gSeDiscoverycount, gActualSeCount);
      if (gSeDiscoverycount >= gActualSeCount) {
        SyncEventGuard g(gNfceeDiscCbEvent);
        DLOG_IF(INFO, nfc_debug_enabled)
            << StringPrintf("%s: Sem Post for gNfceeDiscCbEvent", __func__);
        // usleep(1000000); // wait for 1000 millisec
        // wait for atleast 1 sec to receive all ntf
        gNfceeDiscCbEvent.notifyOne();
      }
    } break;

    case NFA_EE_DISCOVER_REQ_EVT: {
      DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf(
          "%s: NFA_EE_DISCOVER_REQ_EVT; status=0x%X; num ee=%u", __func__,
          eventData->discover_req.status, eventData->discover_req.num_ee);
      SyncEventGuard guard(routingManager.mEeInfoEvent);
      memcpy(&routingManager.mEeInfo, &eventData->discover_req,
             sizeof(routingManager.mEeInfo));
      routingManager.mReceivedEeInfo = true;
      routingManager.mEeInfoEvent.notifyOne();
    }
      break;

    case NFA_EE_NO_CB_ERR_EVT:
      DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf(
          "%s: NFA_EE_NO_CB_ERR_EVT  status=%u", fn, eventData->status);
      break;

    case NFA_EE_ADD_AID_EVT: {
      DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf(
          "%s: NFA_EE_ADD_AID_EVT  status=%u", fn, eventData->status);
      if (eventData->status == NFA_STATUS_BUFFER_FULL) {
        DLOG_IF(INFO, nfc_debug_enabled)
            << StringPrintf("%s: AID routing table is FULL!!!", fn);
        // RoutingManager::getInstance().notifyLmrtFull();
      }
      SyncEventGuard guard(se.mAidAddRemoveEvent);
      se.mAidAddRemoveEvent.notifyOne();
    } break;

    case NFA_EE_REMOVE_AID_EVT: {
      DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf(
          "%s: NFA_EE_REMOVE_AID_EVT  status=%u", fn, eventData->status);
      SyncEventGuard guard(se.mAidAddRemoveEvent);
      se.mAidAddRemoveEvent.notifyOne();
    } break;
    case NFA_EE_NEW_EE_EVT: {
      DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf(
          "%s: NFA_EE_NEW_EE_EVT  h=0x%X; status=%u", fn,
          eventData->new_ee.ee_handle, eventData->new_ee.ee_status);
    } break;
    case NFA_EE_ROUT_ERR_EVT: {
      DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf(
          "%s: NFA_EE_ROUT_ERR_EVT  status=%u", fn, eventData->status);
    } break;
    case NFA_EE_UPDATED_EVT: {
      DLOG_IF(INFO, nfc_debug_enabled)
          << StringPrintf("%s: NFA_EE_UPDATED_EVT", fn);
      SyncEventGuard guard(routingManager.mEeUpdateEvent);
      routingManager.mEeUpdateEvent.notifyOne();
      routingManager.LmrtRspTimer.kill();
    } break;
    default:
      LOG(ERROR) << StringPrintf("%s: unknown event=%u ????", fn, event);
      break;
  }
}

int RoutingManager::registerT3tIdentifier(uint8_t* t3tId, uint8_t t3tIdLen) {
  static const char fn[] = "RoutingManager::registerT3tIdentifier";

  DLOG_IF(INFO, nfc_debug_enabled)
      << fn << ": Start to register NFC-F system on DH";

  if (t3tIdLen != (2 + NCI_RF_F_UID_LEN + NCI_T3T_PMM_LEN)) {
    LOG(ERROR) << fn << ": Invalid length of T3T Identifier";
    return NFA_HANDLE_INVALID;
  }

#if (NXP_EXTNS == TRUE && NXP_NFCC_HCE_F == TRUE)
  if (android::nfcManager_getTransanctionRequest(0, true)) {
    DLOG_IF(INFO, nfc_debug_enabled)
        << StringPrintf("%s: Busy in nfcManager_getTransanctionRequest", fn);
    return NFA_HANDLE_INVALID;
  }
#endif

  mNfcFOnDhHandle = NFA_HANDLE_INVALID;

  uint16_t systemCode;
  uint8_t nfcid2[NCI_RF_F_UID_LEN];
  uint8_t t3tPmm[NCI_T3T_PMM_LEN];

  systemCode = (((int)t3tId[0] << 8) | ((int)t3tId[1] << 0));
  memcpy(nfcid2, t3tId + 2, NCI_RF_F_UID_LEN);
  memcpy(t3tPmm, t3tId + 10, NCI_T3T_PMM_LEN);

  {
    SyncEventGuard guard(mRoutingEvent);
    tNFA_STATUS nfaStat = NFA_CeRegisterFelicaSystemCodeOnDH(
        systemCode, nfcid2, t3tPmm, nfcFCeCallback);
    if (nfaStat == NFA_STATUS_OK) {
      mRoutingEvent.wait();
    } else {
      LOG(ERROR) << StringPrintf("%s: Fail to register NFC-F system on DH", fn);
      return NFA_HANDLE_INVALID;
    }
   }

  DLOG_IF(INFO, nfc_debug_enabled)
      << StringPrintf("%s: Succeed to register NFC-F system on DH", fn);

  // Register System Code for routing
  if (mIsScbrSupported) {
    SyncEventGuard guard(mRoutingEvent);
    tNFA_STATUS nfaStat = NFA_EeAddSystemCodeRouting(systemCode, NCI_DH_ID,
                                                     SYS_CODE_PWR_STATE_HOST);
    if (nfaStat == NFA_STATUS_OK) {
      mRoutingEvent.wait();
    }
    if ((nfaStat != NFA_STATUS_OK) || (mCbEventData.status != NFA_STATUS_OK)) {
      LOG(ERROR) << StringPrintf("%s: Fail to register system code on DH", fn);
      return NFA_HANDLE_INVALID;
    }
    DLOG_IF(INFO, nfc_debug_enabled)
        << StringPrintf("%s: Succeed to register system code on DH", fn);
    // add handle and system code pair to the map
    mMapScbrHandle.emplace(mNfcFOnDhHandle, systemCode);
  } else {
    LOG(ERROR) << StringPrintf("%s: SCBR Not supported", fn);
  }

  return mNfcFOnDhHandle;
}

void RoutingManager::deregisterT3tIdentifier(int handle) {
  static const char fn[] = "RoutingManager::deregisterT3tIdentifier";
  DLOG_IF(INFO, nfc_debug_enabled)
      << StringPrintf("%s: Start to deregister NFC-F system on DH", fn);
#if (NXP_EXTNS == TRUE && NXP_NFCC_HCE_F == TRUE)
  if (android::nfcManager_getTransanctionRequest(handle, false)) {
    DLOG_IF(INFO, nfc_debug_enabled)
        << StringPrintf("%s: Busy in nfcManager_getTransanctionRequest", fn);
    return;
  }
#endif
   {
    SyncEventGuard guard(mRoutingEvent);
    tNFA_STATUS nfaStat = NFA_CeDeregisterFelicaSystemCodeOnDH(handle);
    if (nfaStat == NFA_STATUS_OK) {
      mRoutingEvent.wait();
      DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf(
          "%s: Succeeded in deregistering NFC-F system on DH", fn);
    } else {
      LOG(ERROR) << StringPrintf("%s: Fail to deregister NFC-F system on DH",
                                 fn);
    }
  }
  if (mIsScbrSupported) {
    map<int, uint16_t>::iterator it = mMapScbrHandle.find(handle);
    // find system code for given handle
    if (it != mMapScbrHandle.end()) {
      uint16_t systemCode = it->second;
      mMapScbrHandle.erase(handle);
      if (systemCode != 0) {
        SyncEventGuard guard(mRoutingEvent);
        tNFA_STATUS nfaStat = NFA_EeRemoveSystemCodeRouting(systemCode);
        if (nfaStat == NFA_STATUS_OK) {
          mRoutingEvent.wait();
          DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf(
              "%s: Succeeded in deregistering system Code on DH", fn);
        } else {
          LOG(ERROR) << StringPrintf("%s: Fail to deregister system Code on DH",
                                     fn);
        }
      }
    }
   }
}

#if (NXP_EXTNS == TRUE)
void RoutingManager::ClearSystemCodeRouting() {
  if (mIsScbrSupported) {
    SyncEventGuard guard(mRoutingEvent);
    tNFA_STATUS nfaStat = NFA_EeRemoveSystemCodeRouting(mDefaultSysCode);
    if (nfaStat == NFA_STATUS_OK) {
      mRoutingEvent.wait();
      DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf(
          "%s: Succeeded in deregistering system Code on DH", __func__);
    } else {
      LOG(ERROR) << StringPrintf("%s: Fail to deregister system Code on DH",
                                 __func__);
    }
  }
}
#endif
void RoutingManager::nfcFCeCallback(uint8_t event,
                                    tNFA_CONN_EVT_DATA* eventData) {
  static const char fn[] = "RoutingManager::nfcFCeCallback";
  RoutingManager& routingManager = RoutingManager::getInstance();

#if (NXP_EXTNS == TRUE)
  SecureElement& se = SecureElement::getInstance();
#endif

  DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf("%s: 0x%x", __func__, event);

  switch (event) {
    case NFA_CE_REGISTERED_EVT: {
      DLOG_IF(INFO, nfc_debug_enabled)
          << StringPrintf("%s: registerd event notified", fn);
      routingManager.mNfcFOnDhHandle = eventData->ce_registered.handle;
      SyncEventGuard guard(routingManager.mRoutingEvent);
      routingManager.mRoutingEvent.notifyOne();
    } break;
    case NFA_CE_DEREGISTERED_EVT: {
      DLOG_IF(INFO, nfc_debug_enabled)
          << StringPrintf("%s: deregisterd event notified", fn);
      SyncEventGuard guard(routingManager.mRoutingEvent);
      routingManager.mRoutingEvent.notifyOne();
    } break;
    case NFA_CE_ACTIVATED_EVT: {
      DLOG_IF(INFO, nfc_debug_enabled)
          << StringPrintf("%s: activated event notified", fn);
#if (NXP_EXTNS == TRUE)
      android::checkforTranscation(NFA_CE_ACTIVATED_EVT, (void*)eventData);
#endif
      routingManager.notifyActivated(NFA_TECHNOLOGY_MASK_F);
    } break;
    case NFA_CE_DEACTIVATED_EVT: {
      DLOG_IF(INFO, nfc_debug_enabled)
          << StringPrintf("%s: deactivated event notified", fn);
#if (NXP_EXTNS == TRUE)
      android::checkforTranscation(NFA_CE_DEACTIVATED_EVT, (void*)eventData);
#endif
      routingManager.notifyDeactivated(NFA_TECHNOLOGY_MASK_F);
    } break;
    case NFA_CE_DATA_EVT: {
      DLOG_IF(INFO, nfc_debug_enabled)
          << StringPrintf("%s: data event notified", fn);

#if (NXP_EXTNS == TRUE)
      if (nfcFL.nfcNxpEse && (nfcFL.eseFL._ESE_DUAL_MODE_PRIO_SCHEME !=
                              nfcFL.eseFL._ESE_WIRED_MODE_RESUME)) {
        se.setDwpTranseiveState(false, NFCC_CE_DATA_EVT);
      }
#endif
      tNFA_CE_DATA& ce_data = eventData->ce_data;
      routingManager.handleData(NFA_TECHNOLOGY_MASK_F, ce_data.p_data,
                                ce_data.len, ce_data.status);
    } break;
    default: {
      LOG(ERROR) << StringPrintf("%s: unknown event=%u ????", fn, event);
    } break;
  }
}

bool RoutingManager::setNfcSecure(bool enable) {
  mSecureNfcEnabled = enable;
  DLOG_IF(INFO, true) << "setNfcSecure NfcService " << enable;
  return true;
}

void RoutingManager::deinitialize() {
  onNfccShutdown();
  NFA_EeDeregister(nfaEeCallback);
}

int RoutingManager::registerJniFunctions(JNIEnv* e) {
  static const char fn[] = "RoutingManager::registerJniFunctions";
  DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf("%s", fn);
  return jniRegisterNativeMethods(
      e, "com/android/nfc/cardemulation/AidRoutingManager", sMethods,
      NELEM(sMethods));
}

jbyteArray
RoutingManager::com_android_nfc_cardemulation_doGetOffHostUiccDestination(
    JNIEnv* e) {
  std::vector<uint8_t> uicc = getInstance().mOffHostRouteUicc;
  if (uicc.size() == 0) {
    return NULL;
  }
  CHECK(e);
  jbyteArray uiccJavaArray = e->NewByteArray(uicc.size());
  CHECK(uiccJavaArray);
  e->SetByteArrayRegion(uiccJavaArray, 0, uicc.size(), (jbyte*)&uicc[0]);
  return uiccJavaArray;
}

jbyteArray
RoutingManager::com_android_nfc_cardemulation_doGetOffHostEseDestination(
    JNIEnv* e) {
  std::vector<uint8_t> ese = getInstance().mOffHostRouteEse;
  if (ese.size() == 0) {
    return NULL;
  }
  CHECK(e);
  jbyteArray eseJavaArray = e->NewByteArray(ese.size());
  CHECK(eseJavaArray);
  e->SetByteArrayRegion(eseJavaArray, 0, ese.size(), (jbyte*)&ese[0]);
  return eseJavaArray;
}
int RoutingManager::com_android_nfc_cardemulation_doGetDefaultRouteDestination(
    JNIEnv*) {
  return getInstance().mDefaultEe;
}

int RoutingManager::
    com_android_nfc_cardemulation_doGetDefaultOffHostRouteDestination(JNIEnv*) {
  getInstance().mDefaultOffHostRoute =
      NfcConfig::getUnsigned(NAME_DEFAULT_OFFHOST_ROUTE, 0x00);
  return getInstance().mDefaultOffHostRoute;
}

int RoutingManager::com_android_nfc_cardemulation_doGetAidMatchingMode(
    JNIEnv*) {
  return getInstance().mAidMatchingMode;
}

int RoutingManager::
    com_android_nfc_cardemulation_doGetDefaultIsoDepRouteDestination(JNIEnv*) {
  return RoutingManager::getInstance().mDefaultIsoDepRoute;
}

__attribute__((unused)) int
RoutingManager::com_android_nfc_cardemulation_doGetAidMatchingPlatform(
    JNIEnv*) {
  return getInstance().mAidMatchingPlatform;
}

/*
*This fn gets called when timer gets expired.
*When reader requested events (add for polling tech - tech A/tech B)comes it is
expected to come back to back with in timer expiry value(50ms)
*case 1:If all the add request comes before the timer expiry , poll request for
all isn handled
*case 2:If the second add request comes after timer expiry, it is not handled

*When reader requested events (remove polling tech - tech A/tech B)comes it is
expected to come back to back for the add requestes before
 timer expiry happens(50ms)
*case 1:If all the removal request comes before the timer expiry , poll removal
request for all is handled
*case 2:If the only one of the removal request is reached before timer expiry,
it is not handled
           :When ever the second removal request is also reached , it is
handled.

*/
#if (NXP_EXTNS == TRUE)
extern int active_ese_reset_control;
#endif

void* ee_removed_ntf_handler_thread(void* data) {
  static const char fn[] = "ee_removed_ntf_handler_thread";
  tNFA_STATUS stat = NFA_STATUS_FAILED;
  SecureElement& se = SecureElement::getInstance();
  RoutingManager& rm = RoutingManager::getInstance();
  DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf("%s: Enter: ", fn);
  rm.mResetHandlerMutex.lock();
  DLOG_IF(INFO, nfc_debug_enabled)
      << StringPrintf("%s: enter sEseRemovedHandlerMutex lock", fn);
  if (nfcFL.nfccFL._NFCEE_REMOVED_NTF_RECOVERY) {
    NFA_HciW4eSETransaction_Complete(Release);
  }

  if (nfcFL.nfcNxpEse && nfcFL.eseFL._WIRED_MODE_STANDBY &&
      se.mIsWiredModeOpen) {
    stat = se.setNfccPwrConfig(se.NFCC_DECIDES);
    if (stat != NFA_STATUS_OK) {
      DLOG_IF(INFO, nfc_debug_enabled)
          << StringPrintf("%s: power link command failed", __func__);
    }
  }
  {
    SyncEventGuard guard(se.mEeSetModeEvent);
    stat = NFA_EeModeSet(SecureElement::EE_HANDLE_0xF3, NFA_EE_MD_DEACTIVATE);

    if (stat == NFA_STATUS_OK) {
      if (se.mEeSetModeEvent.wait(500) == false) {
        DLOG_IF(INFO, nfc_debug_enabled)
            << StringPrintf("%s:SetMode rsp timeout", __func__);
      }
    }
  }
  if (nfcFL.nfcNxpEse) {
    if (nfcFL.eseFL._WIRED_MODE_STANDBY && se.mIsWiredModeOpen) {
      stat = se.setNfccPwrConfig(se.POWER_ALWAYS_ON | se.COMM_LINK_ACTIVE);
      if (stat != NFA_STATUS_OK) {
        DLOG_IF(INFO, nfc_debug_enabled)
            << StringPrintf("%s: power link command failed", __func__);
      }
    }
  }
  if (nfcFL.eseFL._WIRED_MODE_STANDBY) {
    SyncEventGuard guard(se.mModeSetNtf);
    stat = NFA_EeModeSet(SecureElement::EE_HANDLE_0xF3, NFA_EE_MD_ACTIVATE);
    if (stat == NFA_STATUS_OK) {
      if (se.mModeSetNtf.wait(500) == false) {
        DLOG_IF(INFO, nfc_debug_enabled)
            << StringPrintf("%s:SetMode ntf timeout", __func__);
      } else {
        // do nothing
      }
    } else {
      // do nothing
    }
  } else {
    SyncEventGuard guard(se.mEeSetModeEvent);
    stat = NFA_EeModeSet(SecureElement::EE_HANDLE_0xF3, NFA_EE_MD_ACTIVATE);
    if (stat == NFA_STATUS_OK) {
      if (se.mEeSetModeEvent.wait(500) == false) {
        DLOG_IF(INFO, nfc_debug_enabled)
            << StringPrintf("%s:SetMode rsp timeout", __func__);
      } else {
        // do nothing
      }
    } else {
      // do nothing
    }
  }
  rm.mResetHandlerMutex.unlock();
#if (NXP_EXTNS == TRUE)
  if (nfcFL.nfcNxpEse) {
    if (active_ese_reset_control & TRANS_WIRED_ONGOING) {
      SyncEventGuard guard(se.mTransceiveEvent);
      se.mTransceiveEvent.notifyOne();
    }
    if (nfcFL.eseFL._ESE_DWP_SPI_SYNC_ENABLE) {
      /* restart the discovery */
      usleep(100 * 100);
      if (android::isDiscoveryStarted() == true) {
        android::startRfDiscovery(false);
        usleep(100 * 100);
        android::startRfDiscovery(true);
      }
    }
  }
#endif
  DLOG_IF(INFO, nfc_debug_enabled)
      << StringPrintf("%s: exit sEseRemovedHandlerMutex lock ", fn);
  DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf("%s: exit ", fn);
  pthread_exit(NULL);
  return NULL;
}

void RoutingManager::ee_removed_disc_ntf_handler(tNFA_HANDLE handle,
                                                 tNFA_EE_STATUS status) {
  static const char fn[] = "RoutingManager::ee_disc_ntf_handler";
  pthread_t thread;
  pthread_attr_t attr;
  pthread_attr_init(&attr);
  pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
  LOG(ERROR) << StringPrintf("%s; ee_handle=0x0%x, status=0x0%x", fn, handle,
                             status);
  if (pthread_create(&thread, &attr, &ee_removed_ntf_handler_thread,
                     (void*)NULL) < 0) {
    DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf("Thread creation failed");
  } else {
    DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf("Thread creation success");
  }
  pthread_attr_destroy(&attr);
}

void RoutingManager::updateRoutingTable() {
#if (NXP_EXTNS != TRUE)
  updateEeTechRouteSetting();
  updateDefaultProtocolRoute();
#endif
  updateDefaultRoute();
}

void RoutingManager::updateDefaultProtocolRoute() {
  static const char fn[] = "RoutingManager::updateDefaultProtocolRoute";

  // Default Routing for ISO-DEP
  tNFA_PROTOCOL_MASK protoMask = NFA_PROTOCOL_MASK_ISO_DEP;
  tNFA_STATUS nfaStat = NFA_STATUS_FAILED;
  if (mDefaultIsoDepRoute != NFC_DH_ID) {
    nfaStat = NFA_EeClearDefaultProtoRouting(mDefaultIsoDepRoute, protoMask);
    nfaStat = NFA_EeSetDefaultProtoRouting(
        mDefaultIsoDepRoute, protoMask, mSecureNfcEnabled ? 0 : protoMask, 0,
        mSecureNfcEnabled ? 0 : protoMask, mSecureNfcEnabled ? 0 : protoMask,
        mSecureNfcEnabled ? 0 : protoMask);
  } else {
    nfaStat = NFA_EeClearDefaultProtoRouting(NFC_DH_ID, protoMask);
    nfaStat = NFA_EeSetDefaultProtoRouting(
        NFC_DH_ID, protoMask, 0, 0, mSecureNfcEnabled ? 0 : protoMask, 0, 0);
  }
  if (nfaStat == NFA_STATUS_OK)
    DLOG_IF(INFO, nfc_debug_enabled)
        << fn << ": Succeed to register default ISO-DEP route";
  else
    LOG(ERROR) << fn << ": failed to register default ISO-DEP route";

  // Default routing for T3T protocol
  if (!mIsScbrSupported) {
    SyncEventGuard guard(mRoutingEvent);
    tNFA_PROTOCOL_MASK protoMask = NFA_PROTOCOL_MASK_T3T;
    if (mDefaultEe == NFC_DH_ID) {
      nfaStat =
          NFA_EeSetDefaultProtoRouting(NFC_DH_ID, protoMask, 0, 0, 0, 0, 0);
    } else {
      nfaStat = NFA_EeClearDefaultProtoRouting(mDefaultEe, protoMask);
      nfaStat = NFA_EeSetDefaultProtoRouting(
          mDefaultEe, protoMask, 0, 0, mSecureNfcEnabled ? 0 : protoMask,
          mSecureNfcEnabled ? 0 : protoMask, mSecureNfcEnabled ? 0 : protoMask);
    }
    if (nfaStat == NFA_STATUS_OK)
      mRoutingEvent.wait();
    else
      LOG(ERROR) << fn << "Fail to set default proto routing for T3T";
  }
}

void RoutingManager::updateDefaultRoute() {
  static const char fn[] = "RoutingManager::updateDefaultRoute";
  if (NFC_GetNCIVersion() != NCI_VERSION_2_0) return;

#if (NXP_EXTNS == TRUE)
  uint16_t routeLoc = ((mDefaultSysCodeRoute == 0x00)
                           ? ROUTE_LOC_HOST_ID
                           : ((mDefaultSysCodeRoute == 0x01)
                                  ? ROUTE_LOC_ESE_ID
                                  : getUiccRouteLocId(mDefaultSysCodeRoute)));
  if (mDefaultSysCodeRoute == 0) {
    mDefaultSysCodePowerstate &= 0x11;
  }
#endif

  // Register System Code for routing
  SyncEventGuard guard(mRoutingEvent);
#if (NXP_EXTNS == TRUE)
  tNFA_STATUS nfaStat = NFA_EeAddSystemCodeRouting(
      mDefaultSysCode, routeLoc,
      (mSecureNfcEnabled && mDefaultSysCodePowerstate)
          ? 0x01 : mDefaultSysCodePowerstate);
#else
  tNFA_STATUS nfaStat = NFA_EeAddSystemCodeRouting(
      mDefaultSysCode, mDefaultSysCodeRoute,
      mSecureNfcEnabled ? 0x01 : mDefaultSysCodePowerstate);
#endif
  if (nfaStat == NFA_STATUS_NOT_SUPPORTED) {
    mIsScbrSupported = false;
    LOG(ERROR) << fn << ": SCBR not supported";
  } else if (nfaStat == NFA_STATUS_OK) {
    mIsScbrSupported = true;
    mRoutingEvent.wait();
    DLOG_IF(INFO, nfc_debug_enabled)
        << fn << ": Succeed to register system code";
  } else {
    LOG(ERROR) << fn << ": Fail to register system code";
    //still support SCBR routing for other NFCEEs
    mIsScbrSupported = true;
  }

#if (NXP_EXTNS != TRUE)
  // Register zero lengthy Aid for default Aid Routing
  if (mDefaultEe != mDefaultIsoDepRoute) {
    uint8_t powerState = 0x01;
    if (!mSecureNfcEnabled)
      powerState = (mDefaultEe != 0x00) ? mOffHostAidRoutingPowerState : 0x11;
    nfaStat = NFA_EeAddAidRouting(mDefaultEe, 0, NULL, powerState,
                                  AID_ROUTE_QUAL_PREFIX);
    if (nfaStat == NFA_STATUS_OK)
      DLOG_IF(INFO, nfc_debug_enabled)
          << fn << ": Succeed to register zero length AID";
    else
      LOG(ERROR) << fn << ": failed to register zero length AID";
  }
#endif
}

#if (NXP_EXTNS != TRUE)
tNFA_TECHNOLOGY_MASK RoutingManager::updateEeTechRouteSetting() {
  static const char fn[] = "RoutingManager::updateEeTechRouteSetting";
  tNFA_TECHNOLOGY_MASK allSeTechMask = 0x00;

  if (mDefaultOffHostRoute == 0 && mDefaultFelicaRoute == 0)
    return allSeTechMask;

  DLOG_IF(INFO, nfc_debug_enabled)
      << fn << ": Number of EE is " << (int)mEeInfo.num_ee;

  tNFA_STATUS nfaStat = NFA_STATUS_FAILED;
  for (uint8_t i = 0; i < mEeInfo.num_ee; i++) {
    tNFA_HANDLE eeHandle = mEeInfo.ee_disc_info[i].ee_handle;
    tNFA_TECHNOLOGY_MASK seTechMask = 0;

    DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf(
        "%s   EE[%u] Handle: 0x%04x  techA: 0x%02x  techB: "
        "0x%02x  techF: 0x%02x  techBprime: 0x%02x",
        fn, i, eeHandle, mEeInfo.ee_disc_info[i].la_protocol,
        mEeInfo.ee_disc_info[i].lb_protocol,
        mEeInfo.ee_disc_info[i].lf_protocol,
        mEeInfo.ee_disc_info[i].lbp_protocol);

    if ((mDefaultOffHostRoute != 0) &&
        (eeHandle == (mDefaultOffHostRoute | NFA_HANDLE_GROUP_EE))) {
      if (mEeInfo.ee_disc_info[i].la_protocol != 0)
        seTechMask |= NFA_TECHNOLOGY_MASK_A;
      if (mEeInfo.ee_disc_info[i].lb_protocol != 0)
        seTechMask |= NFA_TECHNOLOGY_MASK_B;
    }
    if ((mDefaultFelicaRoute != 0) &&
        (eeHandle == (mDefaultFelicaRoute | NFA_HANDLE_GROUP_EE))) {
      if (mEeInfo.ee_disc_info[i].lf_protocol != 0)
        seTechMask |= NFA_TECHNOLOGY_MASK_F;
    }

    DLOG_IF(INFO, nfc_debug_enabled)
        << StringPrintf("%s: seTechMask[%u]=0x%02x", fn, i, seTechMask);

    if (seTechMask != 0x00) {
      DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf(
          "Configuring tech mask 0x%02x on EE 0x%04x", seTechMask, eeHandle);

      nfaStat = NFA_CeConfigureUiccListenTech(eeHandle, seTechMask);
      if (nfaStat != NFA_STATUS_OK)
        LOG(ERROR) << fn << "Failed to configure UICC listen technologies.";

      // clear previous before setting new power state
      nfaStat = NFA_EeClearDefaultTechRouting(eeHandle, seTechMask);
      if (nfaStat != NFA_STATUS_OK)
        LOG(ERROR) << fn << "Failed to clear EE technology routing.";

      nfaStat = NFA_EeSetDefaultTechRouting(
          eeHandle, seTechMask, mSecureNfcEnabled ? 0 : seTechMask, 0,
          mSecureNfcEnabled ? 0 : seTechMask,
          mSecureNfcEnabled ? 0 : seTechMask,
          mSecureNfcEnabled ? 0 : seTechMask);
      if (nfaStat != NFA_STATUS_OK)
        LOG(ERROR) << fn << "Failed to configure UICC technology routing.";

      allSeTechMask |= seTechMask;
    }
  }

  // Clear DH technology route on NFC-A
  if ((mHostListenTechMask & NFA_TECHNOLOGY_MASK_A) &&
      (allSeTechMask & NFA_TECHNOLOGY_MASK_A) != 0) {
    nfaStat = NFA_EeClearDefaultTechRouting(NFC_DH_ID, NFA_TECHNOLOGY_MASK_A);
    if (nfaStat != NFA_STATUS_OK)
      LOG(ERROR) << "Failed to clear DH technology routing on NFC-A.";
  }

  // Clear DH technology route on NFC-B
  if ((mHostListenTechMask & NFA_TECHNOLOGY_MASK_B) &&
      (allSeTechMask & NFA_TECHNOLOGY_MASK_B) != 0) {
    nfaStat = NFA_EeClearDefaultTechRouting(NFC_DH_ID, NFA_TECHNOLOGY_MASK_B);
    if (nfaStat != NFA_STATUS_OK)
      LOG(ERROR) << "Failed to clear DH technology routing on NFC-B.";
  }

  // Clear DH technology route on NFC-F
  if ((mHostListenTechMask & NFA_TECHNOLOGY_MASK_F) &&
      (allSeTechMask & NFA_TECHNOLOGY_MASK_F) != 0) {
    nfaStat = NFA_EeClearDefaultTechRouting(NFC_DH_ID, NFA_TECHNOLOGY_MASK_F);
    if (nfaStat != NFA_STATUS_OK)
      LOG(ERROR) << "Failed to clear DH technology routing on NFC-F.";
  }
  return allSeTechMask;
}
#endif

#if (NXP_EXTNS == TRUE)
bool RoutingManager::is_ee_recovery_ongoing() {
  static const char fn[] = "RoutingManager::is_ee_recovery_ongoing";
  if (!nfcFL.nfccFL._NFCEE_REMOVED_NTF_RECOVERY) {
    DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf(
        "%s : NFCEE_REMOVED_NTF_RECOVERY not avaialble.Returning", __func__);
    return false;
  }
  DLOG_IF(INFO, nfc_debug_enabled)
      << StringPrintf("%s := %s", fn, ((recovery == true) ? "true" : "false"));
  return recovery;
}

void RoutingManager::setEERecovery(bool value) {
  if (!nfcFL.nfccFL._NFCEE_REMOVED_NTF_RECOVERY) {
    DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf(
        "%s : NFCEE_REMOVED_NTF_RECOVERY not avaialble.Returning", __func__);
    return;
  }
  DLOG_IF(INFO, nfc_debug_enabled)
      << StringPrintf("%s: value %x", __func__, value);
  recovery = value;
}

/*******************************************************************************
**
** Function:        processGetRouting
**
** Description:     Process the eventData(current routing info) received during
**                  getRouting
**                  eventData : eventData
**                  sRoutingBuff : Array containing processed data
**
** Returns:         None
**
*******************************************************************************/
void RoutingManager::processGetRoutingRsp(tNFA_DM_CBACK_DATA* eventData,
                                          uint8_t* sRoutingBuff) {
  DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf("%s : Enter", __func__);
  uint8_t xx = 0, numTLVs = 0, currPos = 0, curTLVLen = 0;
  uint8_t sRoutingCurrent[256];
  numTLVs = *(eventData->get_routing.param_tlvs + 1);
  /*Copying only routing Entries.
  Skipping fields,
  More                  : 1Byte
  No of Routing Entries : 1Byte*/
  memcpy(sRoutingCurrent, eventData->get_routing.param_tlvs + 2,
         eventData->get_routing.tlv_size - 2);

  while (xx < numTLVs) {
    curTLVLen = *(sRoutingCurrent + currPos + 1);
    /*Filtering out Routing Entry corresponding to PROTOCOL_NFC_DEP*/
    if ((*(sRoutingCurrent + currPos) == PROTOCOL_BASED_ROUTING) &&
        (*(sRoutingCurrent + currPos + (curTLVLen + 1)) ==
         NFA_PROTOCOL_NFC_DEP)) {
      currPos = currPos + curTLVLen + TYPE_LENGTH_SIZE;
    } else {
      memcpy(sRoutingBuff + android::sRoutingBuffLen, sRoutingCurrent + currPos,
             curTLVLen + TYPE_LENGTH_SIZE);
      currPos = currPos + curTLVLen + TYPE_LENGTH_SIZE;
      android::sRoutingBuffLen =
          android::sRoutingBuffLen + curTLVLen + TYPE_LENGTH_SIZE;
    }
    xx++;
  }
}
/*******************************************************************************
**
** Function:        handleSERemovedNtf()
**
** Description:     The Function checks whether eSE is Removed Ntf
**
** Returns:         None
**
*******************************************************************************/
void RoutingManager::handleSERemovedNtf() {
  if (!nfcFL.nfccFL._NFCEE_REMOVED_NTF_RECOVERY) {
    DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf(
        "%s : NFCEE_REMOVED_NTF_RECOVERY not avaialble.Returning", __func__);
    return;
  }
  static const char fn[] = "RoutingManager::handleSERemovedNtf()";
  uint8_t ActualNumEe = nfcFL.nfccFL._NFA_EE_MAX_EE_SUPPORTED;
  tNFA_EE_INFO mEeInfo[ActualNumEe];
  tNFA_STATUS nfaStat = NFA_STATUS_FAILED;
  LOG(ERROR) << StringPrintf("%s:Enter", __func__);
  if ((nfaStat = NFA_AllEeGetInfo(&ActualNumEe, mEeInfo)) != NFA_STATUS_OK) {
    LOG(ERROR) << StringPrintf("%s: fail get info; error=0x%X", fn, nfaStat);
    ActualNumEe = 0;
  } else {
    if ((mChipId == pn65T) || (mChipId == pn66T) || (mChipId == pn67T) ||
        (mChipId == pn80T)) {
      for (int xx = 0; xx < ActualNumEe; xx++) {
        LOG(ERROR) << StringPrintf("xx=%d, ee_handle=0x0%x, status=0x0%x", xx,
                                   mEeInfo[xx].ee_handle,
                                   mEeInfo[xx].ee_status);
        if ((mEeInfo[xx].ee_handle == SecureElement::EE_HANDLE_0xF3) &&
            (mEeInfo[xx].ee_status == 0x02)) {
          recovery = true;
          ee_removed_disc_ntf_handler(mEeInfo[xx].ee_handle,
                                      mEeInfo[xx].ee_status);
          break;
        }
      }
    }
  }
}
/*******************************************************************************
**
** Function:        LmrtRspTimerCb
**
** Description:     Routing Timer callback
**
*******************************************************************************/
static void LmrtRspTimerCb(union sigval) {
  static const char fn[] = "LmrtRspTimerCb";
  DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf("%s:  ", fn);
  SyncEventGuard guard(RoutingManager::getInstance().mEeUpdateEvent);
  RoutingManager::getInstance().mEeUpdateEvent.notifyOne();
}

/*******************************************************************************
 **
 ** Function:        getUiccRoute
 **
 ** Description:     returns EE Id corresponding to slot number
 **
 ** Returns:         route location
 **
 *******************************************************************************/
static jint getUiccRoute(jint uicc_slot) {
  if (!nfcFL.nfccFL._NFC_NXP_STAT_DUAL_UICC_WO_EXT_SWITCH) {
    DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf(
        "%s : STAT_DUAL_UICC_WO_EXT_SWITCH not avaialble.Returning", __func__);
    return 0xFF;
  }
  DLOG_IF(INFO, nfc_debug_enabled)
      << StringPrintf("%s: Enter slot num = %d", __func__, uicc_slot);
  if ((uicc_slot == 0x00) || (uicc_slot == 0x01)) {
    return SecureElement::getInstance().EE_HANDLE_0xF4;
  } else if (uicc_slot == 0x02) {
    return SecureElement::EE_HANDLE_0xF8;
  } else {
    return 0xFF;
  }
}

void RoutingManager::registerProtoRouteEnrty(
    tNFA_HANDLE ee_handle, tNFA_PROTOCOL_MASK protocols_switch_on,
    tNFA_PROTOCOL_MASK protocols_switch_off,
    tNFA_PROTOCOL_MASK protocols_battery_off,
    tNFA_PROTOCOL_MASK protocols_screen_lock,
    tNFA_PROTOCOL_MASK protocols_screen_off,
    tNFA_PROTOCOL_MASK protocols_screen_off_lock) {
  tNFA_STATUS nfaStat = NFA_STATUS_FAILED;
  {
    SyncEventGuard guard(mRoutingEvent);
    nfaStat = NFA_EeSetDefaultProtoRouting(
        ee_handle, protocols_switch_on, protocols_switch_off,
        protocols_battery_off, protocols_screen_lock, protocols_screen_off,
        protocols_screen_off_lock);
    if (nfaStat == NFA_STATUS_OK) {
      mRoutingEvent.wait();
      DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf("proto routing SUCCESS");
    } else {
      DLOG_IF(ERROR, nfc_debug_enabled)
          << StringPrintf("Fail to set proto routing");
    }
  }
}
#endif
