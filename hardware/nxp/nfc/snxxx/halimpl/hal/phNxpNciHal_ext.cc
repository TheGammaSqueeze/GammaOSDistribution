/*
 * Copyright 2012-2021 NXP
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
#include <log/log.h>
#include <phDal4Nfc_messageQueueLib.h>
#include <phDnldNfc.h>
#include <phNxpConfig.h>
#include <phNxpLog.h>
#include <phNxpNciHal.h>
#include <phNxpNciHal_Adaptation.h>
#include <phNxpNciHal_NfcDepSWPrio.h>
#include <phNxpNciHal_ext.h>
#include <phTmlNfc.h>
#if (NXP_EXTNS == TRUE)
#include "phNxpNciHal.h"
#include "phNxpNciHal_IoctlOperations.h"
#include "phNxpNciHal_nciParser.h"
#endif
/* Timeout value to wait for response from PN548AD */
#define HAL_EXTNS_WRITE_RSP_TIMEOUT (1000)

#undef P2P_PRIO_LOGIC_HAL_IMP

/******************* Global variables *****************************************/
extern phNxpNciHal_Control_t nxpncihal_ctrl;
extern phNxpNciProfile_Control_t nxpprofile_ctrl;
extern phNxpNci_getCfg_info_t* mGetCfg_info;

extern bool_t gsIsFwRecoveryRequired;

extern uint32_t cleanup_timer;
extern bool nfc_debug_enabled;
uint8_t icode_detected = 0x00;
uint8_t icode_send_eof = 0x00;
static uint8_t ee_disc_done = 0x00;
uint8_t EnableP2P_PrioLogic = false;
extern bool bEnableMfcExtns;
extern bool bEnableMfcReader;
extern bool bDisableLegacyMfcExtns;
static uint32_t RfDiscID = 1;
static uint32_t RfProtocolType = 4;
/* NFCEE Set mode */
static uint8_t setEEModeDone = 0x00;
/* External global variable to get FW version from NCI response*/
extern uint32_t wFwVerRsp;
/* External global variable to get FW version from FW file*/
extern uint16_t wFwVer;
extern bool_t gParserCreated;
uint16_t fw_maj_ver;
uint16_t rom_version;
/* local buffer to store CORE_INIT response */
static uint32_t bCoreInitRsp[40];
static uint32_t iCoreInitRspLen;

extern uint32_t timeoutTimerId;

/************** HAL extension functions ***************************************/
static void hal_extns_write_rsp_timeout_cb(uint32_t TimerId, void* pContext);

/*Proprietary cmd sent to HAL to send reader mode flag
 * Last byte of 4 byte proprietary cmd data contains ReaderMode flag
 * If this flag is enabled, NFC-DEP protocol is modified to T3T protocol
 * if FrameRF interface is selected. This needs to be done as the FW
 * always sends Ntf for FrameRF with NFC-DEP even though FrameRF with T3T is
 * previously selected with DISCOVER_SELECT_CMD
 */
#define PROPRIETARY_CMD_FELICA_READER_MODE 0xFE
static uint8_t gFelicaReaderMode;
static bool mfc_mode = false;

static NFCSTATUS phNxpNciHal_ext_process_nfc_init_rsp(uint8_t* p_ntf,
                                                      uint16_t* p_len);
/*******************************************************************************
**
** Function         phNxpNciHal_ext_init
**
** Description      initialize extension function
**
*******************************************************************************/
void phNxpNciHal_ext_init(void) {
  icode_detected = 0x00;
  if (nfcFL.chipType < sn100u) {
    icode_send_eof = 0x00;
  }
  setEEModeDone = 0x00;
  EnableP2P_PrioLogic = false;
}

/*******************************************************************************
**
** Function         phNxpNciHal_ext_send_sram_config_to_flash
**
** Description      This function is called to update the SRAM contents such as
**                  set config to FLASH for permanent storage.
**                  Note: This function has to be called after set config and
**                  before sending  core_reset command again.
**
*******************************************************************************/
NFCSTATUS phNxpNciHal_ext_send_sram_config_to_flash() {
  NXPLOG_NCIHAL_D("phNxpNciHal_ext_send_sram_config_to_flash  send");
  NFCSTATUS status = NFCSTATUS_SUCCESS;
  uint8_t send_sram_flash[] = {NXP_PROPCMD_GID, NXP_FLUSH_SRAM_AO_TO_FLASH,
                               0x00};
  status = phNxpNciHal_send_ext_cmd(sizeof(send_sram_flash), send_sram_flash);
  return status;
}
/*******************************************************************************
**
** Function         phNxpNciHal_process_ext_rsp
**
** Description      Process extension function response
**
** Returns          NFCSTATUS_SUCCESS if success
**
*******************************************************************************/
NFCSTATUS phNxpNciHal_process_ext_rsp(uint8_t* p_ntf, uint16_t* p_len) {
  NFCSTATUS status = NFCSTATUS_SUCCESS;

#if (NXP_EXTNS == TRUE)
  /*parse and decode LxDebug Notifications*/
  if (p_ntf[0] == 0x6F && (p_ntf[1] == 0x35 || p_ntf[1] == 0x36)) {
    if (gParserCreated) phNxpNciHal_parsePacket(p_ntf, *p_len);
  }
#if (NXP_SRD == TRUE)
  if (p_ntf[0] == 0x01 && p_ntf[1] == 0x00 && p_ntf[5] == 0x81 &&
      p_ntf[23] == 0x82 && p_ntf[26] == 0xA0 && p_ntf[27] == 0xFE) {
    if (p_ntf[29] == 0x01) {
      nxpprofile_ctrl.profile_type = SRD_PROFILE;
    } else if (p_ntf[29] == 0x00) {
      nxpprofile_ctrl.profile_type = NFC_FORUM_PROFILE;
    }
  } else if (p_ntf[0] == 0x60 && p_ntf[1] == 0x07 && p_ntf[2] == 0x01 &&
             p_ntf[3] == 0xE2) {
    nxpprofile_ctrl.profile_type = NFC_FORUM_PROFILE;
  }
#endif
#endif

  if (p_ntf[0] == 0x61 && p_ntf[1] == 0x05 && *p_len < 14) {
    if (*p_len <= 6) {
      android_errorWriteLog(0x534e4554, "118152591");
    }
    NXPLOG_NCIHAL_E("RF_INTF_ACTIVATED_NTF length error!");
    status = NFCSTATUS_FAILED;
    return status;
  }

  if (p_ntf[0] == 0x61 && p_ntf[1] == 0x05 && p_ntf[4] == 0x03 &&
      p_ntf[5] == 0x05 && nxpprofile_ctrl.profile_type == EMV_CO_PROFILE) {
    p_ntf[4] = 0xFF;
    p_ntf[5] = 0xFF;
    p_ntf[6] = 0xFF;
    NXPLOG_NCIHAL_D("Nfc-Dep Detect in EmvCo profile - Restart polling");
  }

  if (p_ntf[0] == 0x61 && p_ntf[1] == 0x05 && p_ntf[4] == 0x01 &&
      p_ntf[5] == 0x05 && p_ntf[6] == 0x02 && gFelicaReaderMode) {
    /*If FelicaReaderMode is enabled,Change Protocol to T3T from NFC-DEP
     * when FrameRF interface is selected*/
    p_ntf[5] = 0x03;
    NXPLOG_NCIHAL_D("FelicaReaderMode:Activity 1.1");
  }

#ifdef P2P_PRIO_LOGIC_HAL_IMP
  if (p_ntf[0] == 0x61 && p_ntf[1] == 0x05 && p_ntf[4] == 0x02 &&
      p_ntf[5] == 0x04 && nxpprofile_ctrl.profile_type == NFC_FORUM_PROFILE) {
    EnableP2P_PrioLogic = true;
  }

  NXPLOG_NCIHAL_D("Is EnableP2P_PrioLogic: 0x0%X", EnableP2P_PrioLogic);
  if (phNxpDta_IsEnable() == false) {
    if ((icode_detected != 1) && (EnableP2P_PrioLogic == true)) {
      if (phNxpNciHal_NfcDep_comapre_ntf(p_ntf, *p_len) == NFCSTATUS_FAILED) {
        status = phNxpNciHal_NfcDep_rsp_ext(p_ntf, p_len);
        if (status != NFCSTATUS_INVALID_PARAMETER) {
          return status;
        }
      }
    }
  }
#endif

  status = NFCSTATUS_SUCCESS;

  if (bDisableLegacyMfcExtns && bEnableMfcExtns && p_ntf[0] == 0) {
    uint16_t extlen;
    extlen = *p_len - NCI_HEADER_SIZE;
    NxpMfcReaderInstance.AnalyzeMfcResp(&p_ntf[3], &extlen);
    p_ntf[2] = extlen;
    *p_len = extlen + NCI_HEADER_SIZE;
  }

  if (p_ntf[0] == 0x61 && p_ntf[1] == 0x05) {
    bEnableMfcExtns = false;
    if (bDisableLegacyMfcExtns && p_ntf[4] == 0x80 && p_ntf[5] == 0x80) {
      bEnableMfcExtns = true;
      NXPLOG_NCIHAL_D("NxpNci: RF Interface = Mifare Enable MifareExtns");
    }
    switch (p_ntf[4]) {
      case 0x00:
        NXPLOG_NCIHAL_D("NxpNci: RF Interface = NFCEE Direct RF");
        break;
      case 0x01:
        NXPLOG_NCIHAL_D("NxpNci: RF Interface = Frame RF");
        break;
      case 0x02:
        NXPLOG_NCIHAL_D("NxpNci: RF Interface = ISO-DEP");
        break;
      case 0x03:
        NXPLOG_NCIHAL_D("NxpNci: RF Interface = NFC-DEP");
        break;
      case 0x80:
        NXPLOG_NCIHAL_D("NxpNci: RF Interface = MIFARE");
        break;
      default:
        NXPLOG_NCIHAL_D("NxpNci: RF Interface = Unknown");
        break;
    }

    switch (p_ntf[5]) {
      case 0x01:
        NXPLOG_NCIHAL_D("NxpNci: Protocol = T1T");
        phNxpDta_T1TEnable();
        break;
      case 0x02:
        NXPLOG_NCIHAL_D("NxpNci: Protocol = T2T");
        break;
      case 0x03:
        NXPLOG_NCIHAL_D("NxpNci: Protocol = T3T");
        break;
      case 0x04:
        NXPLOG_NCIHAL_D("NxpNci: Protocol = ISO-DEP");
        break;
      case 0x05:
        NXPLOG_NCIHAL_D("NxpNci: Protocol = NFC-DEP");
        break;
      case 0x06:
        NXPLOG_NCIHAL_D("NxpNci: Protocol = 15693");
        break;
      case 0x80:
        NXPLOG_NCIHAL_D("NxpNci: Protocol = MIFARE");
        break;
      case 0x81:
        NXPLOG_NCIHAL_D("NxpNci: Protocol = Kovio");
        break;
      default:
        NXPLOG_NCIHAL_D("NxpNci: Protocol = Unknown");
        break;
    }

    switch (p_ntf[6]) {
      case 0x00:
        NXPLOG_NCIHAL_D("NxpNci: Mode = A Passive Poll");
        break;
      case 0x01:
        NXPLOG_NCIHAL_D("NxpNci: Mode = B Passive Poll");
        break;
      case 0x02:
        NXPLOG_NCIHAL_D("NxpNci: Mode = F Passive Poll");
        break;
      case 0x03:
        NXPLOG_NCIHAL_D("NxpNci: Mode = A Active Poll");
        break;
      case 0x05:
        NXPLOG_NCIHAL_D("NxpNci: Mode = F Active Poll");
        break;
      case 0x06:
        NXPLOG_NCIHAL_D("NxpNci: Mode = 15693 Passive Poll");
        break;
      case 0x70:
        NXPLOG_NCIHAL_D("NxpNci: Mode = Kovio");
        break;
      case 0x80:
        NXPLOG_NCIHAL_D("NxpNci: Mode = A Passive Listen");
        break;
      case 0x81:
        NXPLOG_NCIHAL_D("NxpNci: Mode = B Passive Listen");
        break;
      case 0x82:
        NXPLOG_NCIHAL_D("NxpNci: Mode = F Passive Listen");
        break;
      case 0x83:
        NXPLOG_NCIHAL_D("NxpNci: Mode = A Active Listen");
        break;
      case 0x85:
        NXPLOG_NCIHAL_D("NxpNci: Mode = F Active Listen");
        break;
      case 0x86:
        NXPLOG_NCIHAL_D("NxpNci: Mode = 15693 Passive Listen");
        break;
      default:
        NXPLOG_NCIHAL_D("NxpNci: Mode = Unknown");
        break;
    }
  }
  phNxpNciHal_ext_process_nfc_init_rsp(p_ntf, p_len);
  if (p_ntf[0] == 0x42 && p_ntf[1] == 0x01 && p_ntf[2] == 0x01 &&
      p_ntf[3] == 0x00) {
    if (nxpncihal_ctrl.hal_ext_enabled == TRUE && nfcFL.chipType >= sn100u) {
      nxpncihal_ctrl.nci_info.wait_for_ntf = TRUE;
      NXPLOG_NCIHAL_D(" Mode set received");
    }
  } else if (p_ntf[0] == 0x61 && p_ntf[1] == 0x05 && p_ntf[2] == 0x15 &&
             p_ntf[4] == 0x01 && p_ntf[5] == 0x06 && p_ntf[6] == 0x06) {
    NXPLOG_NCIHAL_D("> Going through workaround - notification of ISO 15693");
    icode_detected = 0x01;
    p_ntf[21] = 0x01;
    p_ntf[22] = 0x01;
  } else if (nfcFL.chipType < sn100u && icode_detected == 1 &&
             icode_send_eof == 2) {
    icode_send_eof = 3;
  } else if (nfcFL.chipType < sn100u && p_ntf[0] == 0x00 && p_ntf[1] == 0x00 &&
             icode_detected == 1) {
    if (icode_send_eof == 3) {
      icode_send_eof = 0;
    }
    if (nxpncihal_ctrl.nci_info.nci_version != NCI_VERSION_2_0) {
      if (p_ntf[p_ntf[2] + 2] == 0x00) {
        NXPLOG_NCIHAL_D("> Going through workaround - data of ISO 15693");
        p_ntf[2]--;
        (*p_len)--;
      } else {
        p_ntf[p_ntf[2] + 2] |= 0x01;
      }
    }
  } else if (nfcFL.chipType < sn100u && p_ntf[2] == 0x02 && p_ntf[1] == 0x00 &&
             icode_detected == 1) {
    NXPLOG_NCIHAL_D("> ICODE EOF response do not send to upper layer");
  } else if (p_ntf[0] == 0x61 && p_ntf[1] == 0x06 && icode_detected == 1) {
    NXPLOG_NCIHAL_D("> Polling Loop Re-Started");
    icode_detected = 0;
    if (nfcFL.chipType < sn100u) icode_send_eof = 0;
  } else if (*p_len == 4 && p_ntf[0] == 0x40 && p_ntf[1] == 0x02 &&
             p_ntf[2] == 0x01 && p_ntf[3] == 0x06) {
    NXPLOG_NCIHAL_D("> Deinit workaround for LLCP set_config 0x%x 0x%x 0x%x",
                    p_ntf[21], p_ntf[22], p_ntf[23]);
    p_ntf[0] = 0x40;
    p_ntf[1] = 0x02;
    p_ntf[2] = 0x02;
    p_ntf[3] = 0x00;
    p_ntf[4] = 0x00;
    *p_len = 5;
  }

  if (p_ntf[0] == 0x60 && p_ntf[1] == 0x07 && p_ntf[2] == 0x01) {
    if (p_ntf[3] == 0xEA) {
      gsIsFwRecoveryRequired = true;
      NXPLOG_NCIHAL_D("FW update required");
      status = NFCSTATUS_FAILED;
    } else if ((p_ntf[3] == 0xE5) || (p_ntf[3] == 0x60)) {
      NXPLOG_NCIHAL_D("ignore core generic error");
      status = NFCSTATUS_FAILED;
    }
    return status;
  } else if (p_ntf[0] == 0x61 && p_ntf[1] == 0x21 && p_ntf[2] == 0x00) {
    status = NFCSTATUS_FAILED;
    NXPLOG_NCIHAL_D("ignore core generic error");
    return status;
  }
  // 4200 02 00 01
  else if (p_ntf[0] == 0x42 && p_ntf[1] == 0x00 && ee_disc_done == 0x01) {
    NXPLOG_NCIHAL_D("Going through workaround - NFCEE_DISCOVER_RSP");
    if (p_ntf[4] == 0x01) {
      p_ntf[4] = 0x00;

      ee_disc_done = 0x00;
    }
    NXPLOG_NCIHAL_D("Going through workaround - NFCEE_DISCOVER_RSP - END");

  } else if (p_ntf[0] == 0x61 && p_ntf[1] == 0x03 /*&& cleanup_timer!=0*/) {
    if (cleanup_timer != 0) {
      /* if RF Notification Type of RF_DISCOVER_NTF is Last Notification */
      if (0 == (*(p_ntf + 2 + (*(p_ntf + 2))))) {
        phNxpNciHal_select_RF_Discovery(RfDiscID, RfProtocolType);
        status = NFCSTATUS_FAILED;
        return status;
      } else {
        RfDiscID = p_ntf[3];
        RfProtocolType = p_ntf[4];
      }
      status = NFCSTATUS_FAILED;
      return status;
    }
  } else if (p_ntf[0] == 0x41 && p_ntf[1] == 0x04 && cleanup_timer != 0) {
    status = NFCSTATUS_FAILED;
    return status;
  } else if (*p_len == 4 && p_ntf[0] == 0x4F && p_ntf[1] == 0x11 &&
             p_ntf[2] == 0x01) {
    if (p_ntf[3] == 0x00) {
      NXPLOG_NCIHAL_D(
          ">  Workaround for ISO-DEP Presence Check, ignore response and wait "
          "for notification");
      p_ntf[0] = 0x60;
      p_ntf[1] = 0x06;
      p_ntf[2] = 0x03;
      p_ntf[3] = 0x01;
      p_ntf[4] = 0x00;
      p_ntf[5] = 0x01;
      *p_len = 6;
    } else {
      NXPLOG_NCIHAL_D(
          ">  Workaround for ISO-DEP Presence Check, presence check return "
          "failed");
      p_ntf[0] = 0x60;
      p_ntf[1] = 0x08;
      p_ntf[2] = 0x02;
      p_ntf[3] = 0xB2;
      p_ntf[4] = 0x00;
      *p_len = 5;
    }
  } else if (*p_len == 4 && p_ntf[0] == 0x6F && p_ntf[1] == 0x11 &&
             p_ntf[2] == 0x01) {
    if (p_ntf[3] == 0x01) {
      NXPLOG_NCIHAL_D(
          ">  Workaround for ISO-DEP Presence Check - Card still in field");
      p_ntf[0] = 0x00;
      p_ntf[1] = 0x00;
      p_ntf[2] = 0x01;
      p_ntf[3] = 0x7E;
    } else {
      NXPLOG_NCIHAL_D(
          ">  Workaround for ISO-DEP Presence Check - Card not in field");
      p_ntf[0] = 0x60;
      p_ntf[1] = 0x08;
      p_ntf[2] = 0x02;
      p_ntf[3] = 0xB2;
      p_ntf[4] = 0x00;
      *p_len = 5;
    }
  }

  return status;
}

/******************************************************************************
 * Function         phNxpNciHal_ext_process_nfc_init_rsp
 *
 * Description      This function is used to process the HAL NFC core reset rsp
 *                  and ntf and core init rsp of NCI 1.0 or NCI2.0 and update
 *                  NCI version.
 *                  It also handles error response such as core_reset_ntf with
 *                  error status in both NCI2.0 and NCI1.0.
 *
 * Returns          Returns NFCSTATUS_SUCCESS if parsing response is successful
 *                  or returns failure.
 *
 ******************************************************************************/
static NFCSTATUS phNxpNciHal_ext_process_nfc_init_rsp(uint8_t* p_ntf,
                                                      uint16_t* p_len) {
  NFCSTATUS status = NFCSTATUS_SUCCESS;
  /* Parsing CORE_RESET_RSP and CORE_RESET_NTF to update NCI version.*/
  if (p_ntf == NULL || *p_len == 0x00) {
    return NFCSTATUS_FAILED;
  }
  if (p_ntf[0] == NCI_MT_RSP &&
      ((p_ntf[1] & NCI_OID_MASK) == NCI_MSG_CORE_RESET)) {
    if (p_ntf[2] == 0x01 && p_ntf[3] == 0x00) {
      NXPLOG_NCIHAL_D("CORE_RESET_RSP NCI2.0");
      if (nxpncihal_ctrl.hal_ext_enabled == TRUE &&
          nxpncihal_ctrl.fwdnld_mode_reqd != TRUE) {
        nxpncihal_ctrl.nci_info.wait_for_ntf = TRUE;
      }
    } else if (p_ntf[2] == 0x03 && p_ntf[3] == 0x00) {
      NXPLOG_NCIHAL_D("CORE_RESET_RSP NCI1.0");
      nxpncihal_ctrl.nci_info.nci_version = p_ntf[4];
    } else
      status = NFCSTATUS_FAILED;
  } else if (p_ntf[0] == NCI_MT_NTF &&
             ((p_ntf[1] & NCI_OID_MASK) == NCI_MSG_CORE_RESET)) {
    if (p_ntf[3] == CORE_RESET_TRIGGER_TYPE_CORE_RESET_CMD_RECEIVED) {
      NXPLOG_NCIHAL_D("CORE_RESET_NTF NCI2.0 reason CORE_RESET_CMD received !");
      nxpncihal_ctrl.nci_info.nci_version = p_ntf[5];
      if (!nxpncihal_ctrl.hal_open_status)
        phNxpNciHal_configFeatureList(p_ntf, *p_len);
      int len = p_ntf[2] + 2; /*include 2 byte header*/
      if (len != *p_len - 1) {
        NXPLOG_NCIHAL_E(
            "phNxpNciHal_ext_process_nfc_init_rsp invalid NTF length");
        android_errorWriteLog(0x534e4554, "121263487");
        return NFCSTATUS_FAILED;
      }
      wFwVerRsp = (((uint32_t)p_ntf[len - 2]) << 16U) |
                  (((uint32_t)p_ntf[len - 1]) << 8U) | p_ntf[len];
      fw_maj_ver = p_ntf[len - 1];
      rom_version = p_ntf[len - 2];
      NXPLOG_NCIHAL_D("NxpNci> FW Version: %x.%x.%x", p_ntf[len - 2],
                      p_ntf[len - 1], p_ntf[len]);
    } else {
      uint32_t i;
      char print_buffer[*p_len * 3 + 1];

      memset(print_buffer, 0, sizeof(print_buffer));
      for (i = 0; i < *p_len; i++) {
        snprintf(&print_buffer[i * 2], 3, "%02X", p_ntf[i]);
      }
      NXPLOG_NCIHAL_D("CORE_RESET_NTF received !");
      NXPLOG_NCIR_E("len = %3d > %s", *p_len, print_buffer);
      phNxpNciHal_emergency_recovery(p_ntf[3]);
      status = NFCSTATUS_FAILED;
    } /* Parsing CORE_INIT_RSP*/
  } else if (p_ntf[0] == NCI_MT_RSP &&
             ((p_ntf[1] & NCI_OID_MASK) == NCI_MSG_CORE_INIT)) {
    if (nxpncihal_ctrl.nci_info.nci_version == NCI_VERSION_2_0) {
      NXPLOG_NCIHAL_D("CORE_INIT_RSP NCI2.0 received !");
    } else {
      NXPLOG_NCIHAL_D("CORE_INIT_RSP NCI1.0 received !");
      if (!nxpncihal_ctrl.hal_open_status &&
          nxpncihal_ctrl.nci_info.nci_version != NCI_VERSION_2_0) {
        phNxpNciHal_configFeatureList(p_ntf, *p_len);
      }
      int len = p_ntf[2] + 2; /*include 2 byte header*/
      if (len != *p_len - 1) {
        NXPLOG_NCIHAL_E(
            "phNxpNciHal_ext_process_nfc_init_rsp invalid NTF length");
        android_errorWriteLog(0x534e4554, "121263487");
        return NFCSTATUS_FAILED;
      }
      wFwVerRsp = (((uint32_t)p_ntf[len - 2]) << 16U) |
                  (((uint32_t)p_ntf[len - 1]) << 8U) | p_ntf[len];
      if (wFwVerRsp == 0) status = NFCSTATUS_FAILED;
      iCoreInitRspLen = *p_len;
      memcpy(bCoreInitRsp, p_ntf, *p_len);
      NXPLOG_NCIHAL_D("NxpNci> FW Version: %x.%x.%x", p_ntf[len - 2],
                      p_ntf[len - 1], p_ntf[len]);
      fw_maj_ver = p_ntf[len - 1];
      rom_version = p_ntf[len - 2];
    }
  }
  return status;
}

/******************************************************************************
 * Function         phNxpNciHal_process_ext_cmd_rsp
 *
 * Description      This function process the extension command response. It
 *                  also checks the received response to expected response.
 *
 * Returns          returns NFCSTATUS_SUCCESS if response is as expected else
 *                  returns failure.
 *
 ******************************************************************************/
static NFCSTATUS phNxpNciHal_process_ext_cmd_rsp(uint16_t cmd_len,
                                                 uint8_t* p_cmd) {
  NFCSTATUS status = NFCSTATUS_FAILED;
  uint16_t data_written = 0;

  /* Create the local semaphore */
  if (phNxpNciHal_init_cb_data(&nxpncihal_ctrl.ext_cb_data, NULL) !=
      NFCSTATUS_SUCCESS) {
    NXPLOG_NCIHAL_D("Create ext_cb_data failed");
    return NFCSTATUS_FAILED;
  }

  nxpncihal_ctrl.ext_cb_data.status = NFCSTATUS_SUCCESS;

  /* Send ext command */
  data_written = phNxpNciHal_write_unlocked(cmd_len, p_cmd, ORIG_NXPHAL);
  if (data_written != cmd_len) {
    NXPLOG_NCIHAL_D("phNxpNciHal_write failed for hal ext");
    goto clean_and_return;
  }

  /* Start timer */
  status = phOsalNfc_Timer_Start(timeoutTimerId, HAL_EXTNS_WRITE_RSP_TIMEOUT,
                                 &hal_extns_write_rsp_timeout_cb, NULL);
  if (NFCSTATUS_SUCCESS == status) {
    NXPLOG_NCIHAL_D("Response timer started");
  } else {
    NXPLOG_NCIHAL_E("Response timer not started!!!");
    status = NFCSTATUS_FAILED;
    goto clean_and_return;
  }

  /* Wait for rsp */
  NXPLOG_NCIHAL_D("Waiting after ext cmd sent");
  if (SEM_WAIT(nxpncihal_ctrl.ext_cb_data)) {
    NXPLOG_NCIHAL_E("p_hal_ext->ext_cb_data.sem semaphore error");
    goto clean_and_return;
  }

  /* Stop Timer */
  status = phOsalNfc_Timer_Stop(timeoutTimerId);
  if (NFCSTATUS_SUCCESS == status) {
    NXPLOG_NCIHAL_D("Response timer stopped");
  } else {
    NXPLOG_NCIHAL_E("Response timer stop ERROR!!!");
    status = NFCSTATUS_FAILED;
    goto clean_and_return;
  }
  /* No NTF expected for OMAPI command */
  if (p_cmd[0] == 0x2F && p_cmd[1] == 0x1 && p_cmd[2] == 0x01) {
    nxpncihal_ctrl.nci_info.wait_for_ntf = FALSE;
  }
  /* Start timer to wait for NTF*/
  if (nxpncihal_ctrl.nci_info.wait_for_ntf == TRUE) {
    status = phOsalNfc_Timer_Start(timeoutTimerId, HAL_EXTNS_WRITE_RSP_TIMEOUT,
                                   &hal_extns_write_rsp_timeout_cb, NULL);
    if (NFCSTATUS_SUCCESS == status) {
      NXPLOG_NCIHAL_D("Response timer started");
    } else {
      NXPLOG_NCIHAL_E("Response timer not started!!!");
      status = NFCSTATUS_FAILED;
      goto clean_and_return;
    }
    if (SEM_WAIT(nxpncihal_ctrl.ext_cb_data)) {
      NXPLOG_NCIHAL_E("p_hal_ext->ext_cb_data.sem semaphore error");
      /* Stop Timer */
      status = phOsalNfc_Timer_Stop(timeoutTimerId);
      goto clean_and_return;
    }
    status = phOsalNfc_Timer_Stop(timeoutTimerId);
    if (NFCSTATUS_SUCCESS == status) {
      NXPLOG_NCIHAL_D("Response timer stopped");
    } else {
      NXPLOG_NCIHAL_E("Response timer stop ERROR!!!");
      status = NFCSTATUS_FAILED;
      goto clean_and_return;
    }
  }

  if (nxpncihal_ctrl.ext_cb_data.status != NFCSTATUS_SUCCESS) {
    NXPLOG_NCIHAL_E(
        "Callback Status is failed!! Timer Expired!! Couldn't read it! 0x%x",
        nxpncihal_ctrl.ext_cb_data.status);
    status = NFCSTATUS_FAILED;
    goto clean_and_return;
  }

  NXPLOG_NCIHAL_D("Checking response");
  status = NFCSTATUS_SUCCESS;

clean_and_return:
  phNxpNciHal_cleanup_cb_data(&nxpncihal_ctrl.ext_cb_data);
  nxpncihal_ctrl.nci_info.wait_for_ntf = FALSE;
  HAL_DISABLE_EXT();
  return status;
}

/******************************************************************************
 * Function         phNxpNciHal_write_ext
 *
 * Description      This function inform the status of phNxpNciHal_open
 *                  function to libnfc-nci.
 *
 * Returns          It return NFCSTATUS_SUCCESS then continue with send else
 *                  sends NFCSTATUS_FAILED direct response is prepared and
 *                  do not send anything to NFCC.
 *
 ******************************************************************************/
NFCSTATUS phNxpNciHal_write_ext(uint16_t* cmd_len, uint8_t* p_cmd_data,
                                uint16_t* rsp_len, uint8_t* p_rsp_data) {
  NFCSTATUS status = NFCSTATUS_SUCCESS;

  phNxpNciHal_NfcDep_cmd_ext(p_cmd_data, cmd_len);

  if (phNxpDta_IsEnable() == true) {
    status = phNxpNHal_DtaUpdate(cmd_len, p_cmd_data, rsp_len, p_rsp_data);
  }

  if (p_cmd_data[0] == PROPRIETARY_CMD_FELICA_READER_MODE &&
      p_cmd_data[1] == PROPRIETARY_CMD_FELICA_READER_MODE &&
      p_cmd_data[2] == PROPRIETARY_CMD_FELICA_READER_MODE) {
    NXPLOG_NCIHAL_D("Received proprietary command to set Felica Reader mode:%d",
                    p_cmd_data[3]);
    gFelicaReaderMode = p_cmd_data[3];
    /* frame the fake response */
    *rsp_len = 4;
    p_rsp_data[0] = 0x00;
    p_rsp_data[1] = 0x00;
    p_rsp_data[2] = 0x00;
    p_rsp_data[3] = 0x00;
    status = NFCSTATUS_FAILED;
  } else if (p_cmd_data[0] == 0x20 && p_cmd_data[1] == 0x02 &&
             (p_cmd_data[2] == 0x05 || p_cmd_data[2] == 0x32) &&
             (p_cmd_data[3] == 0x01 || p_cmd_data[3] == 0x02) &&
             p_cmd_data[4] == 0xA0 && p_cmd_data[5] == 0x44 &&
             p_cmd_data[6] == 0x01 && p_cmd_data[7] == 0x01) {
    nxpprofile_ctrl.profile_type = EMV_CO_PROFILE;
    NXPLOG_NCIHAL_D("EMV_CO_PROFILE mode - Enabled");
    status = NFCSTATUS_SUCCESS;
  } else if (p_cmd_data[0] == 0x20 && p_cmd_data[1] == 0x02 &&
             (p_cmd_data[2] == 0x05 || p_cmd_data[2] == 0x32) &&
             (p_cmd_data[3] == 0x01 || p_cmd_data[3] == 0x02) &&
             p_cmd_data[4] == 0xA0 && p_cmd_data[5] == 0x44 &&
             p_cmd_data[6] == 0x01 && p_cmd_data[7] == 0x00) {
    NXPLOG_NCIHAL_D("NFC_FORUM_PROFILE mode - Enabled");
    nxpprofile_ctrl.profile_type = NFC_FORUM_PROFILE;
    status = NFCSTATUS_SUCCESS;
  }

  if (nxpprofile_ctrl.profile_type == EMV_CO_PROFILE) {
    if (p_cmd_data[0] == 0x21 && p_cmd_data[1] == 0x06 &&
        p_cmd_data[2] == 0x01 && p_cmd_data[3] == 0x03) {
#if 0
            //Needs clarification whether to keep it or not
            NXPLOG_NCIHAL_D ("EmvCo Poll mode - RF Deactivate discard");
            phNxpNciHal_print_packet("SEND", p_cmd_data, *cmd_len);
            *rsp_len = 4;
            p_rsp_data[0] = 0x41;
            p_rsp_data[1] = 0x06;
            p_rsp_data[2] = 0x01;
            p_rsp_data[3] = 0x00;
            phNxpNciHal_print_packet("RECV", p_rsp_data, 4);
            status = NFCSTATUS_FAILED;
#endif
    } else if (p_cmd_data[0] == 0x21 && p_cmd_data[1] == 0x03) {
      NXPLOG_NCIHAL_D("EmvCo Poll mode - Discover map only for A and B");
      p_cmd_data[2] = 0x05;
      p_cmd_data[3] = 0x02;
      p_cmd_data[4] = 0x00;
      p_cmd_data[5] = 0x01;
      p_cmd_data[6] = 0x01;
      p_cmd_data[7] = 0x01;
      *cmd_len = 8;
    }
  }

  if (mfc_mode == true && p_cmd_data[0] == 0x21 && p_cmd_data[1] == 0x03) {
    NXPLOG_NCIHAL_D("EmvCo Poll mode - Discover map only for A and B");
    p_cmd_data[2] = 0x03;
    p_cmd_data[3] = 0x01;
    p_cmd_data[4] = 0x00;
    p_cmd_data[5] = 0x01;
    *cmd_len = 6;
    mfc_mode = false;
  }

  if (*cmd_len <= (NCI_MAX_DATA_LEN - 3) && bEnableMfcReader &&
      (p_cmd_data[0] == 0x21 && p_cmd_data[1] == 0x00) &&
      (nxpprofile_ctrl.profile_type == NFC_FORUM_PROFILE)) {
    unsigned long retval = 0;
    if (p_cmd_data[2] == 0x04 && p_cmd_data[3] == 0x01 &&
        p_cmd_data[4] == 0x80 && p_cmd_data[5] == 0x01 &&
        p_cmd_data[6] == 0x83) {
      mfc_mode = true;
    } else {
      if (!GetNxpNumValue(NAME_MIFARE_READER_ENABLE, &retval,
                          sizeof(unsigned long))) {
        NXPLOG_NCIHAL_E(
            "Reading of MIFARE_READER_ENABLE failed. Default retval = %lu",
            retval);
      }
      if (retval == 0x01) {
        NXPLOG_NCIHAL_D("Going through extns - Adding Mifare in RF Discovery");
        p_cmd_data[2] += 3;
        p_cmd_data[3] += 1;
        p_cmd_data[*cmd_len] = 0x80;
        p_cmd_data[*cmd_len + 1] = 0x01;
        p_cmd_data[*cmd_len + 2] = 0x80;
        *cmd_len += 3;
        status = NFCSTATUS_SUCCESS;
        NXPLOG_NCIHAL_D(
            "Going through extns - Adding Mifare in RF Discovery - END");
      }
    }
  } else if ((*cmd_len >= 6) &&
             (p_cmd_data[3] == 0x81 && p_cmd_data[4] == 0x01 &&
              p_cmd_data[5] == 0x03)) {
    NXPLOG_NCIHAL_D("> Going through the set host list");
    if (nfcFL.chipType >= sn100u) {
      *cmd_len = 10;

      p_cmd_data[2] = 0x07;

      p_cmd_data[6] = 0x02;
      p_cmd_data[7] = 0x80;
      p_cmd_data[8] = 0x81;
      p_cmd_data[9] = 0xC0;
    } else {
      *cmd_len = 8;

      p_cmd_data[2] = 0x05;
      p_cmd_data[6] = 0x02;
      p_cmd_data[7] = 0xC0;
    }
    status = NFCSTATUS_SUCCESS;
  } else if (icode_detected) {
    if (nfcFL.chipType < sn100u && (p_cmd_data[3] & 0x40) == 0x40 &&
        (p_cmd_data[4] == 0x21 || p_cmd_data[4] == 0x22 ||
         p_cmd_data[4] == 0x24 || p_cmd_data[4] == 0x27 ||
         p_cmd_data[4] == 0x28 || p_cmd_data[4] == 0x29 ||
         p_cmd_data[4] == 0x2a)) {
      NXPLOG_NCIHAL_D("> Send EOF set");
      icode_send_eof = 1;
    }

    if (p_cmd_data[3] == 0x20 || p_cmd_data[3] == 0x24 ||
        p_cmd_data[3] == 0x60) {
      NXPLOG_NCIHAL_D("> NFC ISO_15693 Proprietary CMD ");
      p_cmd_data[3] += 0x02;
    }
  } else if (p_cmd_data[0] == 0x21 && p_cmd_data[1] == 0x03) {
    NXPLOG_NCIHAL_D("> Polling Loop Started");
    icode_detected = 0;
    if (nfcFL.chipType < sn100u) {
      icode_send_eof = 0;
    }
  }
  // 22000100
  else if (p_cmd_data[0] == 0x22 && p_cmd_data[1] == 0x00 &&
           p_cmd_data[2] == 0x01 && p_cmd_data[3] == 0x00) {
    // ee_disc_done = 0x01;//Reader Over SWP event getting
    *rsp_len = 0x05;
    p_rsp_data[0] = 0x42;
    p_rsp_data[1] = 0x00;
    p_rsp_data[2] = 0x02;
    p_rsp_data[3] = 0x00;
    p_rsp_data[4] = 0x00;
    phNxpNciHal_print_packet("RECV", p_rsp_data, 5);
    status = NFCSTATUS_FAILED;
  }
  // 2002 0904 3000 3100 3200 5000
  else if (*cmd_len <= (NCI_MAX_DATA_LEN - 1) &&
           (p_cmd_data[0] == 0x20 && p_cmd_data[1] == 0x02) &&
           ((p_cmd_data[2] == 0x09 && p_cmd_data[3] == 0x04) /*||
            (p_cmd_data[2] == 0x0D && p_cmd_data[3] == 0x04)*/
            )) {
    *cmd_len += 0x01;
    p_cmd_data[2] += 0x01;
    p_cmd_data[9] = 0x01;
    p_cmd_data[10] = 0x40;
    p_cmd_data[11] = 0x50;
    p_cmd_data[12] = 0x00;

    NXPLOG_NCIHAL_D("> Going through workaround - Dirty Set Config ");
    //        phNxpNciHal_print_packet("SEND", p_cmd_data, *cmd_len);
    NXPLOG_NCIHAL_D("> Going through workaround - Dirty Set Config - End ");
  }
  //    20020703300031003200
  //    2002 0301 3200
  else if ((p_cmd_data[0] == 0x20 && p_cmd_data[1] == 0x02) &&
           ((p_cmd_data[2] == 0x07 && p_cmd_data[3] == 0x03) ||
            (p_cmd_data[2] == 0x03 && p_cmd_data[3] == 0x01 &&
             p_cmd_data[4] == 0x32))) {
    NXPLOG_NCIHAL_D("> Going through workaround - Dirty Set Config ");
    phNxpNciHal_print_packet("SEND", p_cmd_data, *cmd_len);
    *rsp_len = 5;
    p_rsp_data[0] = 0x40;
    p_rsp_data[1] = 0x02;
    p_rsp_data[2] = 0x02;
    p_rsp_data[3] = 0x00;
    p_rsp_data[4] = 0x00;

    phNxpNciHal_print_packet("RECV", p_rsp_data, 5);
    status = NFCSTATUS_FAILED;
    NXPLOG_NCIHAL_D("> Going through workaround - Dirty Set Config - End ");
  }

  // 2002 0D04 300104 310100 320100 500100
  // 2002 0401 320100
  else if ((p_cmd_data[0] == 0x20 && p_cmd_data[1] == 0x02) &&
           (
               /*(p_cmd_data[2] == 0x0D && p_cmd_data[3] == 0x04)*/
               (p_cmd_data[2] == 0x04 && p_cmd_data[3] == 0x01 &&
                p_cmd_data[4] == 0x32 && p_cmd_data[5] == 0x00))) {
    //        p_cmd_data[12] = 0x40;

    NXPLOG_NCIHAL_D("> Going through workaround - Dirty Set Config ");
    phNxpNciHal_print_packet("SEND", p_cmd_data, *cmd_len);
    p_cmd_data[6] = 0x60;

    phNxpNciHal_print_packet("RECV", p_rsp_data, 5);
    //        status = NFCSTATUS_FAILED;
    NXPLOG_NCIHAL_D("> Going through workaround - Dirty Set Config - End ");
  }
#if 0
    else if ( (p_cmd_data[0] == 0x20 && p_cmd_data[1] == 0x02 ) &&
                 ((p_cmd_data[2] == 0x09 && p_cmd_data[3] == 0x04) ||
                     (p_cmd_data[2] == 0x0B && p_cmd_data[3] == 0x05) ||
                     (p_cmd_data[2] == 0x07 && p_cmd_data[3] == 0x02) ||
                     (p_cmd_data[2] == 0x0A && p_cmd_data[3] == 0x03) ||
                     (p_cmd_data[2] == 0x0A && p_cmd_data[3] == 0x04) ||
                     (p_cmd_data[2] == 0x05 && p_cmd_data[3] == 0x02))
             )
    {
        NXPLOG_NCIHAL_D ("> Going through workaround - Dirty Set Config ");
        phNxpNciHal_print_packet("SEND", p_cmd_data, *cmd_len);
        *rsp_len = 5;
        p_rsp_data[0] = 0x40;
        p_rsp_data[1] = 0x02;
        p_rsp_data[2] = 0x02;
        p_rsp_data[3] = 0x00;
        p_rsp_data[4] = 0x00;

        phNxpNciHal_print_packet("RECV", p_rsp_data, 5);
        status = NFCSTATUS_FAILED;
        NXPLOG_NCIHAL_D ("> Going through workaround - Dirty Set Config - End ");
    }

    else if((p_cmd_data[0] == 0x20 && p_cmd_data[1] == 0x02) &&
           ((p_cmd_data[3] == 0x00) ||
           ((*cmd_len >= 0x06) && (p_cmd_data[5] == 0x00)))) /*If the length of the first param id is zero don't allow*/
    {
        NXPLOG_NCIHAL_D ("> Going through workaround - Dirty Set Config ");
        phNxpNciHal_print_packet("SEND", p_cmd_data, *cmd_len);
        *rsp_len = 5;
        p_rsp_data[0] = 0x40;
        p_rsp_data[1] = 0x02;
        p_rsp_data[2] = 0x02;
        p_rsp_data[3] = 0x00;
        p_rsp_data[4] = 0x00;

        phNxpNciHal_print_packet("RECV", p_rsp_data, 5);
        status = NFCSTATUS_FAILED;
        NXPLOG_NCIHAL_D ("> Going through workaround - Dirty Set Config - End ");
    }
#endif
  else if ((wFwVerRsp & 0x0000FFFF) == wFwVer) {
    /* skip CORE_RESET and CORE_INIT from Brcm */
    if (p_cmd_data[0] == 0x20 && p_cmd_data[1] == 0x00 &&
        p_cmd_data[2] == 0x01 && p_cmd_data[3] == 0x01) {
      //            *rsp_len = 6;
      //
      //            NXPLOG_NCIHAL_D("> Going - core reset optimization");
      //
      //            p_rsp_data[0] = 0x40;
      //            p_rsp_data[1] = 0x00;
      //            p_rsp_data[2] = 0x03;
      //            p_rsp_data[3] = 0x00;
      //            p_rsp_data[4] = 0x10;
      //            p_rsp_data[5] = 0x01;
      //
      //            status = NFCSTATUS_FAILED;
      //            NXPLOG_NCIHAL_D("> Going - core reset optimization - END");
    }
    /* CORE_INIT */
    else if (p_cmd_data[0] == 0x20 && p_cmd_data[1] == 0x01 &&
             p_cmd_data[2] == 0x00) {
      //            NXPLOG_NCIHAL_D("> Going - core init optimization");
      //            *rsp_len = iCoreInitRspLen;
      //            memcpy(p_rsp_data, bCoreInitRsp, iCoreInitRspLen);
      //            status = NFCSTATUS_FAILED;
      //            NXPLOG_NCIHAL_D("> Going - core init optimization - END");
    }
  }

  return status;
}

/******************************************************************************
 * Function         phNxpNciHal_send_ext_cmd
 *
 * Description      This function send the extension command to NFCC. No
 *                  response is checked by this function but it waits for
 *                  the response to come.
 *
 * Returns          Returns NFCSTATUS_SUCCESS if sending cmd is successful and
 *                  response is received.
 *
 ******************************************************************************/
NFCSTATUS phNxpNciHal_send_ext_cmd(uint16_t cmd_len, uint8_t* p_cmd) {
  NFCSTATUS status = NFCSTATUS_FAILED;
  nxpncihal_ctrl.cmd_len = cmd_len;
  memcpy(nxpncihal_ctrl.p_cmd_data, p_cmd, cmd_len);
  status = phNxpNciHal_process_ext_cmd_rsp(nxpncihal_ctrl.cmd_len,
                                           nxpncihal_ctrl.p_cmd_data);

  return status;
}

/******************************************************************************
 * Function         phNxpNciHal_send_ese_hal_cmd
 *
 * Description      This function send the extension command to NFCC. No
 *                  response is checked by this function but it waits for
 *                  the response to come.
 *
 * Returns          Returns NFCSTATUS_SUCCESS if sending cmd is successful and
 *                  response is received.
 *
 ******************************************************************************/
NFCSTATUS phNxpNciHal_send_ese_hal_cmd(uint16_t cmd_len, uint8_t* p_cmd) {
  NFCSTATUS status = NFCSTATUS_FAILED;
  if (cmd_len > NCI_MAX_DATA_LEN) {
    NXPLOG_NCIHAL_E("cmd_len exceeds limit NCI_MAX_DATA_LEN");
    return status;
  }
  nxpncihal_ctrl.cmd_len = cmd_len;
  memcpy(nxpncihal_ctrl.p_cmd_data, p_cmd, cmd_len);
  status = phNxpNciHal_process_ext_cmd_rsp(nxpncihal_ctrl.cmd_len,
                                           nxpncihal_ctrl.p_cmd_data);
  return status;
}

/******************************************************************************
 * Function         hal_extns_write_rsp_timeout_cb
 *
 * Description      Timer call back function
 *
 * Returns          None
 *
 ******************************************************************************/
static void hal_extns_write_rsp_timeout_cb(uint32_t timerId, void* pContext) {
  UNUSED_PROP(timerId);
  UNUSED_PROP(pContext);
  NXPLOG_NCIHAL_D("hal_extns_write_rsp_timeout_cb - write timeout!!!");
  nxpncihal_ctrl.ext_cb_data.status = NFCSTATUS_FAILED;
  usleep(1);
  sem_post(&(nxpncihal_ctrl.syncSpiNfc));
  SEM_POST(&(nxpncihal_ctrl.ext_cb_data));

  return;
}

/*******************************************************************************
 **
 ** Function:        request_EEPROM()
 **
 ** Description:     get and set EEPROM data
 **                  In case of request_modes GET_EEPROM_DATA or
 *SET_EEPROM_DATA,
 **                   1.caller has to pass the buffer and the length of data
 *required
 **                     to be read/written.
 **                   2.Type of information required to be read/written
 **                     (Example - EEPROM_RF_CFG)
 **
 ** Returns:         Returns NFCSTATUS_SUCCESS if sending cmd is successful and
 **                  status failed if not successful
 **
 *******************************************************************************/
NFCSTATUS request_EEPROM(phNxpNci_EEPROM_info_t* mEEPROM_info) {
  NXPLOG_NCIHAL_D(
      "%s Enter  request_type : 0x%02x,  request_mode : 0x%02x,  bufflen : "
      "0x%02x",
      __func__, mEEPROM_info->request_type, mEEPROM_info->request_mode,
      mEEPROM_info->bufflen);
  NFCSTATUS status = NFCSTATUS_FAILED;
  uint8_t retry_cnt = 0;
  uint8_t getCfgStartIndex = 0x08;
  uint8_t setCfgStartIndex = 0x07;
  uint8_t memIndex = 0x00;
  uint8_t fieldLen = 0x01;  // Memory field len 1bytes
  char addr[2] = {0};
  uint8_t cur_value = 0, len = 5;
  uint8_t b_position = 0;
  bool_t update_req = false;
  uint8_t set_cfg_cmd_len = 0;
  uint8_t *set_cfg_eeprom, *base_addr;

  mEEPROM_info->update_mode = BITWISE;

  switch (mEEPROM_info->request_type) {
    case EEPROM_RF_CFG:
      memIndex = 0x00;
      fieldLen = 0x20;
      len = fieldLen + 4;  // 4 - numParam+2add+val
      addr[0] = 0xA0;
      addr[1] = 0x14;
      mEEPROM_info->update_mode = BYTEWISE;
      break;

    case EEPROM_FW_DWNLD:
      fieldLen = 0x20;
      memIndex = 0x0C;
      len = fieldLen + 4;
      addr[0] = 0xA0;
      addr[1] = 0x0F;
      mEEPROM_info->update_mode = BYTEWISE;
      break;

    case EEPROM_WIREDMODE_RESUME_TIMEOUT:
      mEEPROM_info->update_mode = BYTEWISE;
      memIndex = 0x00;
      fieldLen = 0x04;
      len = fieldLen + 4;
      addr[0] = 0xA0;
      addr[1] = 0xFC;
      break;

    case EEPROM_ESE_SVDD_POWER:
      b_position = 0;
      memIndex = 0x00;
      addr[0] = 0xA0;
      addr[1] = 0xF2;
      break;
    case EEPROM_ESE_POWER_EXT_PMU:
      mEEPROM_info->update_mode = BYTEWISE;
      memIndex = 0x00;
      addr[0] = 0xA0;
      addr[1] = 0xD7;
      break;

    case EEPROM_PROP_ROUTING:
      b_position = 7;
      memIndex = 0x00;
      addr[0] = 0xA0;
      addr[1] = 0x98;
      break;

    case EEPROM_ESE_SESSION_ID:
      b_position = 0;
      memIndex = 0x00;
      addr[0] = 0xA0;
      addr[1] = 0xEB;
      break;

    case EEPROM_SWP1_INTF:
      b_position = 0;
      memIndex = 0x00;
      addr[0] = 0xA0;
      addr[1] = 0xEC;
      break;

    case EEPROM_SWP1A_INTF:
      b_position = 0;
      memIndex = 0x00;
      addr[0] = 0xA0;
      addr[1] = 0xD4;
      break;
    case EEPROM_SWP2_INTF:
      b_position = 0;
      memIndex = 0x00;
      addr[0] = 0xA0;
      addr[1] = 0xED;
      break;
    case EEPROM_FLASH_UPDATE:
      /* This flag is no more used in MW */
      fieldLen = 0x20;
      memIndex = 0x00;
      len = fieldLen + 4;
      addr[0] = 0xA0;
      addr[1] = 0x0F;
      break;
    case EEPROM_AUTH_CMD_TIMEOUT:
      mEEPROM_info->update_mode = BYTEWISE;
      memIndex = 0x00;
      fieldLen = 0x05;
      len = fieldLen + 4;
      addr[0] = 0xA0;
      addr[1] = 0xF7;
      break;
    case EEPROM_GUARD_TIMER:
      mEEPROM_info->update_mode = BYTEWISE;
      memIndex = 0x00;
      addr[0] = 0xA1;
      addr[1] = 0x0B;
      break;
    case EEPROM_AUTONOMOUS_MODE:
      mEEPROM_info->update_mode = BYTEWISE;
      memIndex = 0x00;
      addr[0] = 0xA0;
      addr[1] = 0x15;
      break;
    case EEPROM_T4T_NFCEE_ENABLE:
      mEEPROM_info->update_mode = BYTEWISE;
      b_position = 0;
      memIndex = 0x00;
      addr[0] = 0xA0;
      addr[1] = 0x95;
      break;
    case EEPROM_CE_PHONE_OFF_CFG:
      mEEPROM_info->update_mode = BYTEWISE;
      b_position = 0;
      memIndex = 0x00;
      addr[0] = 0xA0;
      addr[1] = 0x8E;
      break;
    case EEPROM_ENABLE_VEN_CFG:
      mEEPROM_info->update_mode = BYTEWISE;
      b_position = 0;
      memIndex = 0x00;
      addr[0] = 0xA0;
      addr[1] = 0x07;
      break;
    case EEPROM_ISODEP_MERGE_SAK:
      mEEPROM_info->update_mode = BYTEWISE;
      b_position = 0;
      memIndex = 0x00;
      addr[0] = 0xA1;
      addr[1] = 0x1B;
      break;
    case EEPROM_SRD_TIMEOUT:
      mEEPROM_info->update_mode = BYTEWISE;
      memIndex = 0x00;
      fieldLen = 0x02;
      len = fieldLen + 4;
      addr[0] = 0xA1;
      addr[1] = 0x17;
      break;
    case EEPROM_UICC1_SESSION_ID:
      fieldLen = mEEPROM_info->bufflen;
      len = fieldLen + 4;
      memIndex = 0x00;
      addr[0] = 0xA0;
      addr[1] = 0xE4;
      mEEPROM_info->update_mode = BYTEWISE;
      break;
    case EEPROM_UICC2_SESSION_ID:
      fieldLen = mEEPROM_info->bufflen;
      len = fieldLen + 4;
      memIndex = 0x00;
      addr[0] = 0xA0;
      addr[1] = 0xE5;
      mEEPROM_info->update_mode = BYTEWISE;
      break;
    default:
      ALOGE("No valid request information found");
      break;
  }

  uint8_t get_cfg_eeprom[6] = {
      0x20,
      0x03,              // get_cfg header
      0x03,              // len of following value
      0x01,              // Num Parameters
      (uint8_t)addr[0],  // First byte of Address
      (uint8_t)addr[1]   // Second byte of Address
  };
  uint8_t set_cfg_cmd_hdr[7] = {
      0x20,
      0x02,              // set_cfg header
      len,               // len of following value
      0x01,              // Num Param
      (uint8_t)addr[0],  // First byte of Address
      (uint8_t)addr[1],  // Second byte of Address
      fieldLen           // Data len
  };

  set_cfg_cmd_len = sizeof(set_cfg_cmd_hdr) + fieldLen;
  set_cfg_eeprom = (uint8_t*)malloc(set_cfg_cmd_len);
  if (set_cfg_eeprom == NULL) {
    ALOGE("memory allocation failed");
    return status;
  }
  base_addr = set_cfg_eeprom;
  memset(set_cfg_eeprom, 0, set_cfg_cmd_len);
  memcpy(set_cfg_eeprom, set_cfg_cmd_hdr, sizeof(set_cfg_cmd_hdr));

retryget:
  status = phNxpNciHal_send_ext_cmd(sizeof(get_cfg_eeprom), get_cfg_eeprom);
  if (status == NFCSTATUS_SUCCESS) {
    status = nxpncihal_ctrl.p_rx_data[3];
    if (status != NFCSTATUS_SUCCESS) {
      ALOGE("failed to get requested memory address");
    } else if (mEEPROM_info->request_mode == GET_EEPROM_DATA) {
      if (mEEPROM_info->bufflen == 0xFF) {
        /* Max bufferlenth for single Get Config Command is 0xFF.
         * If buffer length set to max value, reassign buffer value
         * depends on response from Get Config command */
        mEEPROM_info->bufflen =
            *(nxpncihal_ctrl.p_rx_data + getCfgStartIndex + memIndex - 1);
      }
      memcpy(mEEPROM_info->buffer,
             nxpncihal_ctrl.p_rx_data + getCfgStartIndex + memIndex,
             mEEPROM_info->bufflen);
    } else if (mEEPROM_info->request_mode == SET_EEPROM_DATA) {
      // Clear the buffer first
      memset(set_cfg_eeprom + setCfgStartIndex, 0x00,
             (set_cfg_cmd_len - setCfgStartIndex));

      // copy get config data into set_cfg_eeprom
      memcpy(set_cfg_eeprom + setCfgStartIndex,
             nxpncihal_ctrl.p_rx_data + getCfgStartIndex, fieldLen);
      if (mEEPROM_info->update_mode == BITWISE) {
        cur_value =
            (set_cfg_eeprom[setCfgStartIndex + memIndex] >> b_position) & 0x01;
        if (cur_value != mEEPROM_info->buffer[0]) {
          update_req = true;
          if (mEEPROM_info->buffer[0] == 1) {
            set_cfg_eeprom[setCfgStartIndex + memIndex] |= (1 << b_position);
          } else if (mEEPROM_info->buffer[0] == 0) {
            set_cfg_eeprom[setCfgStartIndex + memIndex] &= (~(1 << b_position));
          }
        }
      } else if (mEEPROM_info->update_mode == BYTEWISE) {
        if (memcmp(set_cfg_eeprom + setCfgStartIndex + memIndex,
                   mEEPROM_info->buffer, mEEPROM_info->bufflen)) {
          update_req = true;
          memcpy(set_cfg_eeprom + setCfgStartIndex + memIndex,
                 mEEPROM_info->buffer, mEEPROM_info->bufflen);
        }
      } else {
        ALOGE("%s, invalid update mode", __func__);
      }

      if (update_req) {
      // do set config
      retryset:
        status = phNxpNciHal_send_ext_cmd(set_cfg_cmd_len, set_cfg_eeprom);
        if (status != NFCSTATUS_SUCCESS && retry_cnt < 3) {
          retry_cnt++;
          ALOGE("Set Cfg Retry cnt=%x", retry_cnt);
          goto retryset;
        }
      } else {
        ALOGD("%s: values are same no update required", __func__);
      }
    }
  } else if (retry_cnt < 3) {
    retry_cnt++;
    ALOGE("Get Cfg Retry cnt=%x", retry_cnt);
    goto retryget;
  }

  if (base_addr != NULL) {
    free(base_addr);
    base_addr = NULL;
  }
  retry_cnt = 0;
  return status;
}

/*******************************************************************************
 **
 ** Function:        phNxpNciHal_enableDefaultUICC2SWPline()
 **
 ** Description:     Select UICC2 or UICC3
 **
 ** Returns:         status
 **
 ********************************************************************************/
NFCSTATUS phNxpNciHal_enableDefaultUICC2SWPline(uint8_t uicc2_sel) {
  NFCSTATUS status = NFCSTATUS_FAILED;
  uint8_t p_data[255] = {NCI_MT_CMD, NXP_CORE_SET_CONFIG_CMD};
  uint8_t LEN_INDEX = 2, PARAM_INDEX = 3;
  uint8_t* p = p_data;
  NXPLOG_NCIHAL_D("phNxpNciHal_enableDefaultUICC2SWPline %d", uicc2_sel);
  p_data[LEN_INDEX] = 1;
  p += 4;
  if (uicc2_sel == 0x03) {
    UINT8_TO_STREAM(p, NXP_NFC_SET_CONFIG_PARAM_EXT);
    UINT8_TO_STREAM(p, NXP_NFC_PARAM_ID_SWP2);
    UINT8_TO_STREAM(p, 0x01);
    UINT8_TO_STREAM(p, 0x01);
    p_data[LEN_INDEX] += 4;
    p_data[PARAM_INDEX] += 1;
  }
  if (uicc2_sel == 0x04) {
    UINT8_TO_STREAM(p, NXP_NFC_SET_CONFIG_PARAM_EXT);
    UINT8_TO_STREAM(p, NXP_NFC_PARAM_ID_SWPUICC3);
    UINT8_TO_STREAM(p, 0x01);
    UINT8_TO_STREAM(p, 0x01);
    p_data[LEN_INDEX] += 4;
    p_data[PARAM_INDEX] += 1;
  }
  if (p_data[PARAM_INDEX] > 0x00)
    status = phNxpNciHal_send_ext_cmd(p - p_data, p_data);
  return status;
}

/******************************************************************************
 * Function         phNxpNciHal_prop_conf_lpcd
 *
 * Description      If NFCC is not in Nfc Forum mode, then this function will
 *                  configure it back to the Nfc Forum mode.
 *
 * Returns          none
 *
 ******************************************************************************/
void phNxpNciHal_prop_conf_lpcd(bool enableLPCD) {
  uint8_t cmd_get_lpcdval[] = {0x20, 0x03, 0x03, 0x01, 0xA0, 0x68};
  vector<uint8_t> cmd_set_lpcdval{0x20, 0x02, 0x2E};

  if (NFCSTATUS_SUCCESS ==
      phNxpNciHal_send_ext_cmd(sizeof(cmd_get_lpcdval), cmd_get_lpcdval)) {
    if (NFCSTATUS_SUCCESS == nxpncihal_ctrl.p_rx_data[3]) {
      if (!(nxpncihal_ctrl.p_rx_data[17] & (1 << 7)) && enableLPCD) {
        nxpncihal_ctrl.p_rx_data[17] |= (1 << 7);
        cmd_set_lpcdval.insert(
            cmd_set_lpcdval.end(), &nxpncihal_ctrl.p_rx_data[4],
            (&nxpncihal_ctrl.p_rx_data[4] + cmd_set_lpcdval[2]));
        if (NFCSTATUS_SUCCESS ==
            phNxpNciHal_send_ext_cmd(cmd_set_lpcdval.size(),
                                     &cmd_set_lpcdval[0])) {
          return;
        }
      } else if (!enableLPCD && (nxpncihal_ctrl.p_rx_data[17] & (1 << 7))) {
        nxpncihal_ctrl.p_rx_data[17] &= ~(1 << 7);
        cmd_set_lpcdval.insert(
            cmd_set_lpcdval.end(), &nxpncihal_ctrl.p_rx_data[4],
            (&nxpncihal_ctrl.p_rx_data[4] + cmd_set_lpcdval[2]));
        if (NFCSTATUS_SUCCESS ==
            phNxpNciHal_send_ext_cmd(cmd_set_lpcdval.size(),
                                     &cmd_set_lpcdval[0])) {
          return;
        }
      } else {
        return;
      }
    }
  }
  NXPLOG_NCIHAL_E("%s: failed!!", __func__);
  return;
}

/******************************************************************************
 * Function         phNxpNciHal_conf_nfc_forum_mode
 *
 * Description      If NFCC is not in Nfc Forum mode, then this function will
 *                  configure it back to the Nfc Forum mode.
 *
 * Returns          none
 *
 ******************************************************************************/
void phNxpNciHal_conf_nfc_forum_mode() {
  uint8_t cmd_get_emvcocfg[] = {0x20, 0x03, 0x03, 0x01, 0xA0, 0x44};
  uint8_t cmd_reset_emvcocfg[8];
  long cmdlen = 8;
  long retlen = 0;

  if (GetNxpByteArrayValue(NAME_NXP_PROP_RESET_EMVCO_CMD,
                           (char*)cmd_reset_emvcocfg, cmdlen, &retlen)) {
  }
  if (retlen != 0x08) {
    NXPLOG_NCIHAL_E("%s: command is not provided", __func__);
    return;
  }
  /* Update the flag address from the Nxp config file */
  cmd_get_emvcocfg[4] = cmd_reset_emvcocfg[4];
  cmd_get_emvcocfg[5] = cmd_reset_emvcocfg[5];

  if (NFCSTATUS_SUCCESS ==
      phNxpNciHal_send_ext_cmd(sizeof(cmd_get_emvcocfg), cmd_get_emvcocfg)) {
    if (NFCSTATUS_SUCCESS == nxpncihal_ctrl.p_rx_data[3]) {
      if (0x01 & nxpncihal_ctrl.p_rx_data[8]) {
        if (NFCSTATUS_SUCCESS ==
            phNxpNciHal_send_ext_cmd(sizeof(cmd_reset_emvcocfg),
                                     cmd_reset_emvcocfg)) {
          return;
        }
      } else {
        return;
      }
    }
  }
  NXPLOG_NCIHAL_E("%s: failed!!", __func__);
  return;
}
