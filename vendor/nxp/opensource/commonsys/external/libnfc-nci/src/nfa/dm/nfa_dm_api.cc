/******************************************************************************
 *
 *  Copyright (C) 2010-2014 Broadcom Corporation
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
 *  The original Work has been changed by NXP.
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

/******************************************************************************
 *
 *  NFA interface for device management
 *
 ******************************************************************************/
#include <string.h>

#include <android-base/stringprintf.h>
#include <base/logging.h>
#include <log/log.h>
#include "nfa_api.h"
#include "nfa_ce_int.h"
#include "ndef_utils.h"
#if (NXP_EXTNS == TRUE)
#include "nfa_sys_int.h"

uint32_t gFelicaReaderMode;
tHAL_NFC_CONTEXT hal_Initcntxt;
#endif

using android::base::StringPrintf;

extern bool nfc_debug_enabled;

/*****************************************************************************
**  Constants
*****************************************************************************/

/*****************************************************************************
**  APIs
*****************************************************************************/
/*******************************************************************************
**
** Function         NFA_Init
**
** Description      This function initializes control blocks for NFA
**
**                  p_hal_entry_tbl points to a table of HAL entry points
**
**                  NOTE: the buffer that p_hal_entry_tbl points must be
**                  persistent until NFA is disabled.
**
** Returns          none
**
*******************************************************************************/
void NFA_Init(tHAL_NFC_ENTRY* p_hal_entry_tbl) {
  DLOG_IF(INFO, nfc_debug_enabled) << __func__;
#if (NXP_EXTNS == TRUE)
  hal_Initcntxt.hal_entry_func = p_hal_entry_tbl;
#endif
  nfa_sys_init();
  nfa_dm_init();
#if (NXP_EXTNS == TRUE)
  if (hal_Initcntxt.boot_mode != NFA_FAST_BOOT_MODE) {
#endif
    nfa_p2p_init();
    nfa_snep_init(false);
    nfa_rw_init();
    nfa_ce_init();
    nfa_ee_init();
    if (nfa_ee_max_ee_cfg != 0) {
      nfa_dm_cb.get_max_ee = p_hal_entry_tbl->get_max_ee;
#if (NXP_EXTNS == TRUE)
      nfa_scr_init();
#endif
      nfa_hci_init();
    }
#if (NXP_EXTNS == TRUE)
  }
#endif
/* Initialize NFC module */
#if (NXP_EXTNS == TRUE)
  NFC_Init(&hal_Initcntxt);
#else
  NFC_Init(p_hal_entry_tbl);
#endif
}

/*******************************************************************************
**
** Function         NFA_Enable
**
** Description      This function enables NFC. Prior to calling NFA_Enable,
**                  the NFCC must be powered up, and ready to receive commands.
**                  This function enables the tasks needed by NFC, opens the NCI
**                  transport, resets the NFC controller, downloads patches to
**                  the NFCC (if necessary), and initializes the NFC subsystems.
**
**                  This function should only be called once - typically when
**                  NFC is enabled during boot-up, or when NFC is enabled from a
**                  settings UI. Subsequent calls to NFA_Enable while NFA is
**                  enabling or enabled will be ignored. When the NFC startup
**                  procedure is completed, an NFA_DM_ENABLE_EVT is returned to
**                  the application using the tNFA_DM_CBACK.
**
** Returns          NFA_STATUS_OK if successfully initiated
**                  NFA_STATUS_FAILED otherwise
**
*******************************************************************************/
tNFA_STATUS NFA_Enable(tNFA_DM_CBACK* p_dm_cback,
                       tNFA_CONN_CBACK* p_conn_cback) {
  tNFA_DM_API_ENABLE* p_msg;

  DLOG_IF(INFO, nfc_debug_enabled) << __func__;

  /* Validate parameters */
  if ((!p_dm_cback) || (!p_conn_cback)) {
    LOG(ERROR) << StringPrintf("NFA_Enable (): error null callback");
    return (NFA_STATUS_FAILED);
  }

  p_msg = (tNFA_DM_API_ENABLE*)GKI_getbuf(sizeof(tNFA_DM_API_ENABLE));
  if (p_msg != nullptr) {
    p_msg->hdr.event = NFA_DM_API_ENABLE_EVT;
    p_msg->p_dm_cback = p_dm_cback;
    p_msg->p_conn_cback = p_conn_cback;

    nfa_sys_sendmsg(p_msg);

    return (NFA_STATUS_OK);
  }

  return (NFA_STATUS_FAILED);
}

/*******************************************************************************
**
** Function         NFA_Disable
**
** Description      This function is called to shutdown NFC. The tasks for NFC
**                  are terminated, and clean up routines are performed. This
**                  function is typically called during platform shut-down, or
**                  when NFC is disabled from a settings UI. When the NFC
**                  shutdown procedure is completed, an NFA_DM_DISABLE_EVT is
**                  returned to the application using the tNFA_DM_CBACK.
**
**                  The platform should wait until the NFC_DISABLE_REVT is
**                  received before powering down the NFC chip and NCI
**                  transport. This is required to so that NFA can gracefully
**                  shut down any open connections.
**
** Returns          NFA_STATUS_OK if successfully initiated
**                  NFA_STATUS_FAILED otherwise
**
*******************************************************************************/
tNFA_STATUS NFA_Disable(bool graceful) {
  tNFA_DM_API_DISABLE* p_msg;

  DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf("NFA_Disable (graceful=%i)", graceful);

  p_msg = (tNFA_DM_API_DISABLE*)GKI_getbuf(sizeof(tNFA_DM_API_DISABLE));
  if (p_msg != nullptr) {
    p_msg->hdr.event = NFA_DM_API_DISABLE_EVT;
    p_msg->graceful = graceful;

    nfa_sys_sendmsg(p_msg);

    return (NFA_STATUS_OK);
  }

  return (NFA_STATUS_FAILED);
}
/*******************************************************************************
**
** Function         NFA_SetPowerSubStateForScreenState
**
** Description      Update the power sub-state as per current screen state to
**                  NFCC.
**
** Returns          NFA_STATUS_OK if successfully initiated
**                  NFA_STATUS_FAILED otherwise
**
*******************************************************************************/
tNFA_STATUS NFA_SetPowerSubStateForScreenState(uint8_t screenState) {
  DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf("%s: state:0x%X", __func__, screenState);

  uint8_t nci_scren_state = 0xFF;
  uint16_t buf_size = sizeof(tNFA_DM_API_SET_POWER_SUB_STATE);
  tNFA_DM_API_SET_POWER_SUB_STATE* p_msg =
      (tNFA_DM_API_SET_POWER_SUB_STATE*)GKI_getbuf(buf_size);

  if (p_msg != nullptr) {
    p_msg->hdr.event = NFA_DM_API_SET_POWER_SUB_STATE_EVT;
    switch (screenState) {
      case NFA_SCREEN_STATE_ON_UNLOCKED:
        nci_scren_state = SCREEN_STATE_ON_UNLOCKED;
        break;
      case NFA_SCREEN_STATE_OFF_UNLOCKED:
        nci_scren_state = SCREEN_STATE_OFF_UNLOCKED;
        break;
      case NFA_SCREEN_STATE_ON_LOCKED:
        nci_scren_state = SCREEN_STATE_ON_LOCKED;
        break;
      case NFA_SCREEN_STATE_OFF_LOCKED:
        nci_scren_state = SCREEN_STATE_OFF_LOCKED;
        break;

      default:
        DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf("%s, unknown screen state", __func__);
        break;
    }

    p_msg->screen_state = nci_scren_state;

    nfa_sys_sendmsg(p_msg);
    return (NFA_STATUS_OK);
  }
  return (NFA_STATUS_FAILED);
}
/*******************************************************************************
**
** Function         NFA_SetConfig
**
** Description      Set the configuration parameters to NFCC. The result is
**                  reported with an NFA_DM_SET_CONFIG_EVT in the tNFA_DM_CBACK
**                  callback.
**
** Note:            If RF discovery is started,
**                  NFA_StopRfDiscovery()/NFA_RF_DISCOVERY_STOPPED_EVT should
**                  happen before calling this function. Most Configuration
**                  parameters are related to RF discovery.
**
** Returns          NFA_STATUS_OK if successfully initiated
**                  NFA_STATUS_BUSY if previous setting is on-going
**                  NFA_STATUS_FAILED otherwise
**
*******************************************************************************/
tNFA_STATUS NFA_SetConfig(tNFA_PMID param_id, uint8_t length, uint8_t* p_data) {
  tNFA_DM_API_SET_CONFIG* p_msg;

  DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf("NFA_SetConfig (): param_id:0x%X", param_id);

  p_msg = (tNFA_DM_API_SET_CONFIG*)GKI_getbuf(
      (uint16_t)(sizeof(tNFA_DM_API_SET_CONFIG) + length));
  if (p_msg != nullptr) {
    p_msg->hdr.event = NFA_DM_API_SET_CONFIG_EVT;

    p_msg->param_id = param_id;
    p_msg->length = length;
    p_msg->p_data = (uint8_t*)(p_msg + 1);

    /* Copy parameter data */
    memcpy(p_msg->p_data, p_data, length);

    nfa_sys_sendmsg(p_msg);

    return (NFA_STATUS_OK);
  }

  return (NFA_STATUS_FAILED);
}

/*******************************************************************************
**
** Function         NFA_GetConfig
**
** Description      Get the configuration parameters from NFCC. The result is
**                  reported with an NFA_DM_GET_CONFIG_EVT in the tNFA_DM_CBACK
**                  callback.
**
** Returns          NFA_STATUS_OK if successfully initiated
**                  NFA_STATUS_FAILED otherwise
**
*******************************************************************************/
tNFA_STATUS NFA_GetConfig(uint8_t num_ids, tNFA_PMID* p_param_ids) {
  tNFA_DM_API_GET_CONFIG* p_msg;
#if (NXP_EXTNS == TRUE)
  uint8_t bytes;
  uint8_t propConfigCnt;

  DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf("NFA_GetConfig (): num_ids: %i", num_ids);
  // NXP_EXTN code added to handle propritory config IDs
  uint32_t idx = 0;
  uint8_t* params = p_param_ids;
  propConfigCnt = 0;

  for (idx = 0; idx < num_ids; idx++) {
    if (*params == 0xA0) {
      params++;
      propConfigCnt++;
    }
    params++;
  }

  bytes = (num_ids - propConfigCnt) + (propConfigCnt << 1);

  p_msg = (tNFA_DM_API_GET_CONFIG*)GKI_getbuf(
      (uint16_t)(sizeof(tNFA_DM_API_GET_CONFIG) + bytes));
#else
  DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf("NFA_GetConfig (): num_ids: %i", num_ids);
  p_msg = (tNFA_DM_API_GET_CONFIG*)GKI_getbuf(
      (uint16_t)(sizeof(tNFA_DM_API_GET_CONFIG) + num_ids));
#endif
  if (p_msg != nullptr) {
    p_msg->hdr.event = NFA_DM_API_GET_CONFIG_EVT;

    p_msg->num_ids = num_ids;
    p_msg->p_pmids = (tNFA_PMID*)(p_msg + 1);

/* Copy the param IDs */
#if (NXP_EXTNS == TRUE)
    memcpy(p_msg->p_pmids, p_param_ids, bytes);
#else
    memcpy(p_msg->p_pmids, p_param_ids, num_ids);
#endif

    nfa_sys_sendmsg(p_msg);

    return (NFA_STATUS_OK);
  }

  return (NFA_STATUS_FAILED);
}

/*******************************************************************************
**
** Function         NFA_SetTransitConfig
**
** Description      Get the Transit configuration value from NFC Service. The
**                  result is reported with an NFA_DM_SET_TRANSIT_CONFIG_EVT in
**                  the tNFA_DM_CBACK callback.
**
** Returns          NFA_STATUS_OK if successfully initiated
**                  NFA_STATUS_FAILED otherwise
**
*******************************************************************************/
tNFA_STATUS NFA_SetTransitConfig(std::string config) {
  tNFA_DM_API_SET_TRANSIT_CONFIG* p_msg;
  uint16_t strsize = strlen(config.c_str());
  if (strsize == 0) {
    LOG(ERROR) << StringPrintf("Selecting Default Config");
  }
  DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf("%s ", __func__);
  p_msg = (tNFA_DM_API_SET_TRANSIT_CONFIG*)GKI_getbuf(
      sizeof(tNFA_DM_API_SET_TRANSIT_CONFIG) + strsize + 1);

  if (p_msg != nullptr) {
    p_msg->hdr.event = NFA_DM_SET_TRANSIT_CONFIG;
    p_msg->transitConfig = (char*)(p_msg + 1);
    memcpy(p_msg->transitConfig, config.c_str(), strsize + 1);

    nfa_sys_sendmsg(p_msg);
    return (NFA_STATUS_OK);
  }
  return (NFA_STATUS_FAILED);
}
/*******************************************************************************
**
** Function         NFA_RequestExclusiveRfControl
**
** Description      Request exclusive control of NFC.
**                  - Previous behavior (polling/tag reading, DH card emulation)
**                    will be suspended .
**                  - Polling and listening will be done based on the specified
**                    params
**
**                  The NFA_EXCLUSIVE_RF_CONTROL_STARTED_EVT event of
**                  tNFA_CONN_CBACK indicates the status of the operation.
**
**                  NFA_ACTIVATED_EVT and NFA_DEACTIVATED_EVT indicates link
**                  activation/deactivation.
**
**                  NFA_SendRawFrame is used to send data to the peer.
**                  NFA_DATA_EVT indicates data from the peer.
**
**                  If a tag is activated, then the NFA_RW APIs may be used to
**                  send commands to the tag. Incoming NDEF messages are sent to
**                  the NDEF callback.
**
**                  Once exclusive RF control has started, NFA will not activate
**                  LLCP internally. The application has exclusive control of
**                  the link.
**
** Note:            If RF discovery is started,
**                  NFA_StopRfDiscovery()/NFA_RF_DISCOVERY_STOPPED_EVT should
**                  happen before calling this function
**
** Returns          NFA_STATUS_OK if successfully initiated
**                  NFA_STATUS_FAILED otherwise
**
*******************************************************************************/
tNFA_STATUS NFA_RequestExclusiveRfControl(tNFA_TECHNOLOGY_MASK poll_mask,
                                          tNFA_LISTEN_CFG* p_listen_cfg,
                                          tNFA_CONN_CBACK* p_conn_cback,
                                          tNFA_NDEF_CBACK* p_ndef_cback) {
  tNFA_DM_API_REQ_EXCL_RF_CTRL* p_msg;

  DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf("NFA_RequestExclusiveRfControl () poll_mask=0x%x", poll_mask);

  if (!p_conn_cback) {
    LOG(ERROR) << StringPrintf("NFA_RequestExclusiveRfControl (): error null callback");
    return (NFA_STATUS_FAILED);
  }

  p_msg = (tNFA_DM_API_REQ_EXCL_RF_CTRL*)GKI_getbuf(
      sizeof(tNFA_DM_API_REQ_EXCL_RF_CTRL));
  if (p_msg != nullptr) {
    p_msg->hdr.event = NFA_DM_API_REQUEST_EXCL_RF_CTRL_EVT;
    p_msg->poll_mask = poll_mask;
    p_msg->p_conn_cback = p_conn_cback;
    p_msg->p_ndef_cback = p_ndef_cback;

    if (p_listen_cfg)
      memcpy(&p_msg->listen_cfg, p_listen_cfg, sizeof(tNFA_LISTEN_CFG));
    else
      memset(&p_msg->listen_cfg, 0x00, sizeof(tNFA_LISTEN_CFG));

    nfa_sys_sendmsg(p_msg);

    return (NFA_STATUS_OK);
  }

  return (NFA_STATUS_FAILED);
}

/*******************************************************************************
**
** Function         NFA_ReleaseExclusiveRfControl
**
** Description      Release exclusive control of NFC. Once released, behavior
**                  prior to obtaining exclusive RF control will resume.
**
** Returns          NFA_STATUS_OK if successfully initiated
**                  NFA_STATUS_FAILED otherwise
**
*******************************************************************************/
tNFA_STATUS NFA_ReleaseExclusiveRfControl(void) {
  NFC_HDR* p_msg;

  DLOG_IF(INFO, nfc_debug_enabled) << __func__;

  if (!nfa_dm_cb.p_excl_conn_cback) {
    LOG(ERROR) << StringPrintf(
        "NFA_ReleaseExclusiveRfControl (): Exclusive rf control is not in "
        "progress");
    return (NFA_STATUS_FAILED);
  }

  p_msg = (NFC_HDR*)GKI_getbuf(sizeof(NFC_HDR));
  if (p_msg != nullptr) {
    p_msg->event = NFA_DM_API_RELEASE_EXCL_RF_CTRL_EVT;
    nfa_sys_sendmsg(p_msg);
    return (NFA_STATUS_OK);
  }

  return (NFA_STATUS_FAILED);
}

/*******************************************************************************
**
** Function         NFA_EnablePolling
**
** Description      Enable polling for technologies specified by poll_mask.
**
**                  The following events (notified using the connection
**                  callback registered with NFA_Enable) are generated during
**                  polling:
**
**                  - NFA_POLL_ENABLED_EVT indicates whether or not polling
**                    successfully enabled.
**                  - NFA_DISC_RESULT_EVT indicates there are more than one
**                    devices, so application must select one of tags by calling
**                    NFA_Select().
**                  - NFA_SELECT_RESULT_EVT indicates whether previous selection
**                    was successful or not. If it was failed then application
**                    must select again or deactivate by calling
**                    NFA_Deactivate().
**                  - NFA_ACTIVATED_EVT is generated when an NFC link is
**                    activated.
**                  - NFA_NDEF_DETECT_EVT is generated if tag is activated
**                  - NFA_LLCP_ACTIVATED_EVT/NFA_LLCP_DEACTIVATED_EVT is
**                    generated if NFC-DEP is activated
**                  - NFA_DEACTIVATED_EVT will be returned after deactivating
**                    NFC link.
**
** Note:            If RF discovery is started,
**                  NFA_StopRfDiscovery()/NFA_RF_DISCOVERY_STOPPED_EVT should
**                  happen before calling this function
**
** Returns          NFA_STATUS_OK if successfully initiated
**                  NFA_STATUS_FAILED otherwise
**
*******************************************************************************/
tNFA_STATUS NFA_EnablePolling(tNFA_TECHNOLOGY_MASK poll_mask) {
  tNFA_DM_API_ENABLE_POLL* p_msg;

  DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf("NFA_EnablePolling () 0x%X", poll_mask);

  p_msg = (tNFA_DM_API_ENABLE_POLL*)GKI_getbuf(sizeof(tNFA_DM_API_ENABLE_POLL));
  if (p_msg != nullptr) {
    p_msg->hdr.event = NFA_DM_API_ENABLE_POLLING_EVT;
    p_msg->poll_mask = poll_mask;

    nfa_sys_sendmsg(p_msg);

    return (NFA_STATUS_OK);
  }

  return (NFA_STATUS_FAILED);
}

/*******************************************************************************
**
** Function         NFA_DisablePolling
**
** Description      Disable polling
**                  NFA_POLL_DISABLED_EVT will be returned after stopping
**                  polling.
**
** Note:            If RF discovery is started,
**                  NFA_StopRfDiscovery()/NFA_RF_DISCOVERY_STOPPED_EVT should
**                  happen before calling this function
**
** Returns          NFA_STATUS_OK if successfully initiated
**                  NFA_STATUS_FAILED otherwise
**
*******************************************************************************/
tNFA_STATUS NFA_DisablePolling(void) {
  NFC_HDR* p_msg;

  DLOG_IF(INFO, nfc_debug_enabled) << __func__;

  p_msg = (NFC_HDR*)GKI_getbuf(sizeof(NFC_HDR));
  if (p_msg != nullptr) {
    p_msg->event = NFA_DM_API_DISABLE_POLLING_EVT;

    nfa_sys_sendmsg(p_msg);

    return (NFA_STATUS_OK);
  }

  return (NFA_STATUS_FAILED);
}

/*******************************************************************************
**
** Function         NFA_EnableListening
**
** Description      Enable listening.
**                  NFA_LISTEN_ENABLED_EVT will be returned after listening is
**                  allowed.
**
**                  The actual listening technologies are specified by other NFA
**                  API functions. Such functions include (but not limited to)
**                  NFA_CeConfigureUiccListenTech.
**                  If NFA_DisableListening () is called to ignore the listening
**                  technologies, NFA_EnableListening () is called to restore
**                  the listening technologies set by these functions.
**
** Note:            If RF discovery is started,
**                  NFA_StopRfDiscovery()/NFA_RF_DISCOVERY_STOPPED_EVT should
**                  happen before calling this function
**
** Returns          NFA_STATUS_OK if successfully initiated
**                  NFA_STATUS_FAILED otherwise
**
*******************************************************************************/
tNFA_STATUS NFA_EnableListening(void) {
  NFC_HDR* p_msg;

  DLOG_IF(INFO, nfc_debug_enabled) << __func__;

  p_msg = (NFC_HDR*)GKI_getbuf(sizeof(NFC_HDR));
  if (p_msg != nullptr) {
    p_msg->event = NFA_DM_API_ENABLE_LISTENING_EVT;

    nfa_sys_sendmsg(p_msg);

    return (NFA_STATUS_OK);
  }

  return (NFA_STATUS_FAILED);
}

/*******************************************************************************
**
** Function         NFA_DisableListening
**
** Description      Disable listening
**                  NFA_LISTEN_DISABLED_EVT will be returned after stopping
**                  listening. This function is called to exclude listen at RF
**                  discovery.
**
** Note:            If RF discovery is started,
**                  NFA_StopRfDiscovery()/NFA_RF_DISCOVERY_STOPPED_EVT should
**                  happen before calling this function
**
** Returns          NFA_STATUS_OK if successfully initiated
**                  NFA_STATUS_FAILED otherwise
**
*******************************************************************************/
tNFA_STATUS NFA_DisableListening(void) {
  NFC_HDR* p_msg;

  DLOG_IF(INFO, nfc_debug_enabled) << __func__;

  p_msg = (NFC_HDR*)GKI_getbuf(sizeof(NFC_HDR));
  if (p_msg != nullptr) {
    p_msg->event = NFA_DM_API_DISABLE_LISTENING_EVT;

    nfa_sys_sendmsg(p_msg);

    return (NFA_STATUS_OK);
  }

  return (NFA_STATUS_FAILED);
}

#if (NXP_EXTNS == TRUE)
/*******************************************************************************
**
** Function         NFA_DisablePassiveListening
**
** Description      Disable Passive listening
**                  NFA_LISTEN_DISABLED_EVT will be returned after stopping
*listening.
**                  This function is called to exclude listen at eSE wired mode
*session open.
**
** Note:            If RF discovery is started,
*NFA_StopRfDiscovery()/NFA_RF_DISCOVERY_STOPPED_EVT
**                  should happen before calling this function
**
** Returns          NFA_STATUS_OK if successfully initiated
**                  NFA_STATUS_FAILED otherwise
**
*******************************************************************************/
tNFA_STATUS NFA_DisablePassiveListening(void) {
    DLOG_IF(INFO, nfc_debug_enabled) << __func__;
    if(!nfcFL.eseFL._NFCC_ESE_UICC_CONCURRENT_ACCESS_PROTECTION) {
        DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf(" NFCC_ESE_UICC_CONCURRENT_ACCESS_PROTECTION"
                " feature is not available!!");
        return (NFA_STATUS_FAILED);
    }
  NFC_HDR* p_msg;

  DLOG_IF(INFO, nfc_debug_enabled) << __func__;

  if ((p_msg = (NFC_HDR*)GKI_getbuf(sizeof(NFC_HDR))) != nullptr) {
    p_msg->event = NFA_DM_API_DISABLE_PASSIVE_LISTENING_EVT;

    nfa_sys_sendmsg(p_msg);

    return (NFA_STATUS_OK);
  }

  return (NFA_STATUS_FAILED);
}

/*******************************************************************************
**
** Function:        NFA_SetPreferredUiccId
**
** Description:     Set Preferred Uicc ID
**                  0x02 - UICC1
**                  0x81 - UICC2
**
** Returns:         none:
**
*******************************************************************************/
void NFA_SetPreferredUiccId(uint8_t uicc_id) {
    DLOG_IF(INFO, nfc_debug_enabled) << __func__;
    if(!nfcFL.nfccFL._NFC_NXP_STAT_DUAL_UICC_WO_EXT_SWITCH) {
        DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf("NFC_NXP_STAT_DUAL_UICC_WO_EXT_SWITCH"
                " feature is not available!!");
        return;
    }
    nfa_dm_cb.selected_uicc_id = uicc_id;
}
#endif

/*******************************************************************************
**
** Function         NFA_PauseP2p
**
** Description      Pause P2P services.
**                  NFA_P2P_PAUSED_EVT will be returned after P2P services are
**                  disabled.
**
**                  The P2P services enabled by NFA_P2p* API functions are not
**                  available. NFA_ResumeP2p() is called to resume the P2P
**                  services.
**
** Note:            If RF discovery is started,
**                  NFA_StopRfDiscovery()/NFA_RF_DISCOVERY_STOPPED_EVT should
**                  happen before calling this function
**
** Returns          NFA_STATUS_OK if successfully initiated
**                  NFA_STATUS_FAILED otherwise
**
*******************************************************************************/
tNFA_STATUS NFA_PauseP2p(void) {
  NFC_HDR* p_msg;

  DLOG_IF(INFO, nfc_debug_enabled) << __func__;

  p_msg = (NFC_HDR*)GKI_getbuf(sizeof(NFC_HDR));
  if (p_msg != nullptr) {
    p_msg->event = NFA_DM_API_PAUSE_P2P_EVT;

    nfa_sys_sendmsg(p_msg);

    return (NFA_STATUS_OK);
  }

  return (NFA_STATUS_FAILED);
}

/*******************************************************************************
**
** Function         NFA_ResumeP2p
**
** Description      Resume P2P services.
**                  NFA_P2P_RESUMED_EVT will be returned after P2P services are.
**                  enables again.
**
** Note:            If RF discovery is started,
**                  NFA_StopRfDiscovery()/NFA_RF_DISCOVERY_STOPPED_EVT should
**                  happen before calling this function
**
** Returns          NFA_STATUS_OK if successfully initiated
**                  NFA_STATUS_FAILED otherwise
**
*******************************************************************************/
tNFA_STATUS NFA_ResumeP2p(void) {
  NFC_HDR* p_msg;

  DLOG_IF(INFO, nfc_debug_enabled) << __func__;

  p_msg = (NFC_HDR*)GKI_getbuf(sizeof(NFC_HDR));
  if (p_msg != nullptr) {
    p_msg->event = NFA_DM_API_RESUME_P2P_EVT;

    nfa_sys_sendmsg(p_msg);

    return (NFA_STATUS_OK);
  }

  return (NFA_STATUS_FAILED);
}

/*******************************************************************************
**
** Function         NFA_SetP2pListenTech
**
** Description      This function is called to set listen technology for
**                  NFC-DEP. This funtion may be called before or after starting
**                  any server on NFA P2P/CHO/SNEP.
**                  If there is no technology for NFC-DEP, P2P listening will be
**                  stopped.
**
**                  NFA_SET_P2P_LISTEN_TECH_EVT without data will be returned.
**
** Note:            If RF discovery is started,
**                  NFA_StopRfDiscovery()/NFA_RF_DISCOVERY_STOPPED_EVT should
**                  happen before calling this function
**
** Returns          NFA_STATUS_OK if successfully initiated
**                  NFA_STATUS_FAILED otherwise
**
*******************************************************************************/
tNFA_STATUS NFA_SetP2pListenTech(tNFA_TECHNOLOGY_MASK tech_mask) {
  tNFA_DM_API_SET_P2P_LISTEN_TECH* p_msg;

  DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf("NFA_P2pSetListenTech (): tech_mask:0x%X", tech_mask);

  p_msg = (tNFA_DM_API_SET_P2P_LISTEN_TECH*)GKI_getbuf(
      sizeof(tNFA_DM_API_SET_P2P_LISTEN_TECH));
  if (p_msg != nullptr) {
    p_msg->hdr.event = NFA_DM_API_SET_P2P_LISTEN_TECH_EVT;
    p_msg->tech_mask = tech_mask;

    nfa_sys_sendmsg(p_msg);

    return (NFA_STATUS_OK);
  }

  return (NFA_STATUS_FAILED);
}

/*******************************************************************************
**
** Function         NFA_StartRfDiscovery
**
** Description      Start RF discovery
**                  RF discovery parameters shall be set by other APIs.
**
**                  An NFA_RF_DISCOVERY_STARTED_EVT indicates whether starting
**                  was successful or not.
**
** Returns          NFA_STATUS_OK if successfully initiated
**                  NFA_STATUS_FAILED otherwise
**
*******************************************************************************/
tNFA_STATUS NFA_StartRfDiscovery(void) {
  NFC_HDR* p_msg;

  DLOG_IF(INFO, nfc_debug_enabled) << __func__;

  p_msg = (NFC_HDR*)GKI_getbuf(sizeof(NFC_HDR));
  if (p_msg != nullptr) {
    p_msg->event = NFA_DM_API_START_RF_DISCOVERY_EVT;

    nfa_sys_sendmsg(p_msg);

    return (NFA_STATUS_OK);
  }

  return (NFA_STATUS_FAILED);
}

/*******************************************************************************
**
** Function         NFA_StopRfDiscovery
**
** Description      Stop RF discovery
**
**                  An NFA_RF_DISCOVERY_STOPPED_EVT indicates whether stopping
**                  was successful or not.
**
** Returns          NFA_STATUS_OK if successfully initiated
**                  NFA_STATUS_FAILED otherwise
**
*******************************************************************************/
tNFA_STATUS NFA_StopRfDiscovery(void) {
  NFC_HDR* p_msg;

  DLOG_IF(INFO, nfc_debug_enabled) << __func__;

  p_msg = (NFC_HDR*)GKI_getbuf(sizeof(NFC_HDR));
  if (p_msg != nullptr) {
    p_msg->event = NFA_DM_API_STOP_RF_DISCOVERY_EVT;

    nfa_sys_sendmsg(p_msg);

    return (NFA_STATUS_OK);
  }

  return (NFA_STATUS_FAILED);
}

/*******************************************************************************
**
** Function         NFA_SetRfDiscoveryDuration
**
** Description      Set the duration of the single discovery period in [ms].
**                  Allowable range: 0 ms to 0xFFFF ms.
**
**                  If discovery is already started, the application should
**                  call NFA_StopRfDiscovery prior to calling
**                  NFA_SetRfDiscoveryDuration, and then call
**                  NFA_StartRfDiscovery afterwards to restart discovery using
**                  the new duration.
**
** Note:            If RF discovery is started,
**                  NFA_StopRfDiscovery()/NFA_RF_DISCOVERY_STOPPED_EVT should
**                  happen before calling this function
**
** Returns:
**                  NFA_STATUS_OK, if command accepted
**                  NFA_STATUS_FAILED: otherwise
**
*******************************************************************************/
tNFA_STATUS NFA_SetRfDiscoveryDuration(uint16_t discovery_period_ms) {
  tNFA_DM_API_SET_RF_DISC_DUR* p_msg;

  DLOG_IF(INFO, nfc_debug_enabled) << __func__;

  /* Post the API message */
  p_msg = (tNFA_DM_API_SET_RF_DISC_DUR*)GKI_getbuf(sizeof(NFC_HDR));
  if (p_msg != nullptr) {
    p_msg->hdr.event = NFA_DM_API_SET_RF_DISC_DURATION_EVT;

    /* Set discovery duration */
    p_msg->rf_disc_dur_ms = discovery_period_ms;

    nfa_sys_sendmsg(p_msg);

    return (NFA_STATUS_OK);
  }

  return (NFA_STATUS_FAILED);
}

/*******************************************************************************
**
** Function         NFA_Select
**
** Description      Select one from detected devices during discovery
**                  (from NFA_DISC_RESULT_EVTs). The application should wait for
**                  the final NFA_DISC_RESULT_EVT before selecting.
**
**                  An NFA_SELECT_RESULT_EVT indicates whether selection was
**                  successful or not. If failed then application must select
**                  again or deactivate by NFA_Deactivate().
**
** Returns          NFA_STATUS_OK if successfully initiated
**                  NFA_STATUS_INVALID_PARAM if RF interface is not matched
**                  protocol
**                  NFA_STATUS_FAILED otherwise
**
*******************************************************************************/
tNFA_STATUS NFA_Select(uint8_t rf_disc_id, tNFA_NFC_PROTOCOL protocol,
                       tNFA_INTF_TYPE rf_interface) {
  tNFA_DM_API_SELECT* p_msg;

  DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf(
      "NFA_Select (): rf_disc_id:0x%X, protocol:0x%X, rf_interface:0x%X",
      rf_disc_id, protocol, rf_interface);

  if (((rf_interface == NFA_INTERFACE_ISO_DEP) &&
       (protocol != NFA_PROTOCOL_ISO_DEP)) ||
      ((rf_interface == NFA_INTERFACE_NFC_DEP) &&
       (protocol != NFA_PROTOCOL_NFC_DEP))) {
    LOG(ERROR) << StringPrintf("NFA_Select (): RF interface is not matched protocol");
    return (NFA_STATUS_INVALID_PARAM);
  }

  p_msg =
      (tNFA_DM_API_SELECT*)GKI_getbuf((uint16_t)(sizeof(tNFA_DM_API_SELECT)));
  if (p_msg != nullptr) {
    p_msg->hdr.event = NFA_DM_API_SELECT_EVT;
    p_msg->rf_disc_id = rf_disc_id;
    p_msg->protocol = protocol;
    p_msg->rf_interface = rf_interface;

    nfa_sys_sendmsg(p_msg);

    return (NFA_STATUS_OK);
  }

  return (NFA_STATUS_FAILED);
}

/*******************************************************************************
**
** Function         NFA_UpdateRFCommParams
**
** Description      This function is called to update RF Communication
**                  parameters once the Frame RF Interface has been activated.
**
**                  An NFA_UPDATE_RF_PARAM_RESULT_EVT indicates whether updating
**                  was successful or not.
**
** Returns          NFA_STATUS_OK if successfully initiated
**                  NFA_STATUS_FAILED otherwise
**
*******************************************************************************/
tNFA_STATUS NFA_UpdateRFCommParams(tNFA_RF_COMM_PARAMS* p_params) {
  tNFA_DM_API_UPDATE_RF_PARAMS* p_msg;

  DLOG_IF(INFO, nfc_debug_enabled) << __func__;

  p_msg = (tNFA_DM_API_UPDATE_RF_PARAMS*)GKI_getbuf(
      (uint16_t)(sizeof(tNFA_DM_API_UPDATE_RF_PARAMS)));
  if (p_msg != nullptr) {
    p_msg->hdr.event = NFA_DM_API_UPDATE_RF_PARAMS_EVT;
    memcpy(&p_msg->params, p_params, sizeof(tNFA_RF_COMM_PARAMS));

    nfa_sys_sendmsg(p_msg);

    return (NFA_STATUS_OK);
  }

  return (NFA_STATUS_FAILED);
}

/*******************************************************************************
**
** Function         NFA_Deactivate
**
** Description
**                  If sleep_mode=true:
**                      Deselect the activated device by deactivating into sleep
**                      mode.
**
**                      An NFA_DEACTIVATE_FAIL_EVT indicates that selection was
**                      not successful. Application can select another
**                      discovered device or deactivate by NFA_Deactivate ()
**                      after receiving NFA_DEACTIVATED_EVT.
**
**                      Deactivating to sleep mode is not allowed when NFCC is
**                      in wait-for-host-select mode, or in listen-sleep states;
**                      NFA will deactivate to idle or discovery state
**                      for these cases respectively.
**
**
**                  If sleep_mode=false:
**                      Deactivate the connection (e.g. as a result of presence
**                      check failure) NFA_DEACTIVATED_EVT will indicate that
**                      link is deactivated. Polling/listening will resume
**                      (unless the nfcc is in wait_for-all-discoveries state)
**
**
** Returns          NFA_STATUS_OK if successfully initiated
**                  NFA_STATUS_FAILED otherwise
**
*******************************************************************************/
extern tNFA_STATUS NFA_Deactivate(bool sleep_mode) {
  tNFA_DM_API_DEACTIVATE* p_msg;

  DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf("NFA_Deactivate (): sleep_mode:%i", sleep_mode);

  p_msg = (tNFA_DM_API_DEACTIVATE*)GKI_getbuf(
      (uint16_t)(sizeof(tNFA_DM_API_DEACTIVATE)));
  if (p_msg != nullptr) {
    p_msg->hdr.event = NFA_DM_API_DEACTIVATE_EVT;
    p_msg->sleep_mode = sleep_mode;

    nfa_sys_sendmsg(p_msg);

    return (NFA_STATUS_OK);
  }

  return (NFA_STATUS_FAILED);
}

/*******************************************************************************
**
** Function         NFA_SendRawFrame
**
** Description      Send a raw frame over the activated interface with the NFCC.
**                  This function can only be called after NFC link is
**                  activated.
**
**                  If the activated interface is a tag and auto-presence check
**                  is enabled then presence_check_start_delay can be used to
**                  indicate the delay in msec after which the next auto
**                  presence check command can be sent.
**                  NFA_DM_DEFAULT_PRESENCE_CHECK_START_DELAY can be used as the
**                  default value for the delay.
**
** Returns          NFA_STATUS_OK if successfully initiated
**                  NFA_STATUS_FAILED otherwise
**
*******************************************************************************/
tNFA_STATUS NFA_SendRawFrame(uint8_t* p_raw_data, uint16_t data_len,
                             uint16_t presence_check_start_delay) {
  NFC_HDR* p_msg;
  uint16_t size;
  uint8_t* p;

  DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf("NFA_SendRawFrame () data_len:%d", data_len);

/* Validate parameters */
  if (nfcFL.nfccFL._NXP_NFCC_EMPTY_DATA_PACKET) {
      if(((data_len == 0) || (p_raw_data == nullptr)) &&
              (!(nfa_dm_cb.disc_cb.disc_state == NFA_DM_RFST_LISTEN_ACTIVE &&
                      nfa_dm_cb.disc_cb.activated_protocol ==
                              NFA_PROTOCOL_T3T))){
          return (NFA_STATUS_INVALID_PARAM);
      } else {
          //Do Nothing.
      }
  }else if((data_len == 0) || (p_raw_data == nullptr)) {
      return (NFA_STATUS_INVALID_PARAM);
  }

  size = NFC_HDR_SIZE + NCI_MSG_OFFSET_SIZE + NCI_DATA_HDR_SIZE + data_len;  /* Check for integer overflow */
  if (size < data_len) {
    android_errorWriteLog(0x534e4554, "120664978");
    return NFA_STATUS_INVALID_PARAM;
  }
  p_msg = (NFC_HDR*)GKI_getbuf(size);

  if (p_msg != nullptr) {
    p_msg->event = NFA_DM_API_RAW_FRAME_EVT;
    p_msg->layer_specific = presence_check_start_delay;
    p_msg->offset = NCI_MSG_OFFSET_SIZE + NCI_DATA_HDR_SIZE;
    p_msg->len = data_len;

    p = (uint8_t*)(p_msg + 1) + p_msg->offset;

    if (nfcFL.nfccFL._NXP_NFCC_EMPTY_DATA_PACKET) {
      if (p_raw_data != nullptr) {
        memcpy(p, p_raw_data, data_len);
      }
    } else {
      memcpy(p, p_raw_data, data_len);
    }

    nfa_sys_sendmsg(p_msg);

    return (NFA_STATUS_OK);
  }

  return (NFA_STATUS_FAILED);
}

/*******************************************************************************
** NDEF Handler APIs
*******************************************************************************/

/*******************************************************************************
**
** Function         NFA_RegisterNDefTypeHandler
**
** Description      This function allows the applications to register for
**                  specific types of NDEF records. When NDEF records are
**                  received, NFA will parse the record-type field, and pass
**                  the record to the registered tNFA_NDEF_CBACK.
**
**                  For records types which were not registered, the record will
**                  be sent to the default handler. A default type-handler may
**                  be registered by calling this NFA_RegisterNDefTypeHandler
**                  with tnf=NFA_TNF_DEFAULT. In this case, all un-registered
**                  record types will be sent to the callback. Only one default
**                  handler may be registered at a time.
**
**                  An NFA_NDEF_REGISTER_EVT will be sent to the tNFA_NDEF_CBACK
**                  to indicate that registration was successful, and provide a
**                  handle for this record type.
**
** Returns          NFA_STATUS_OK if successfully initiated
**                  NFA_STATUS_FAILED otherwise
**
*******************************************************************************/
tNFA_STATUS NFA_RegisterNDefTypeHandler(bool handle_whole_message, tNFA_TNF tnf,
                                        uint8_t* p_type_name,
                                        uint8_t type_name_len,
                                        tNFA_NDEF_CBACK* p_ndef_cback) {
  tNFA_DM_API_REG_NDEF_HDLR* p_msg;

  DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf(
      "NFA_RegisterNDefTypeHandler (): handle whole ndef message: %i, "
      "tnf=0x%02x",
      handle_whole_message, tnf);

  /* Check for NULL callback */
  if (!p_ndef_cback) {
    LOG(ERROR) << StringPrintf("NFA_RegisterNDefTypeHandler (): error - null callback");
    return (NFA_STATUS_INVALID_PARAM);
  }

  p_msg = (tNFA_DM_API_REG_NDEF_HDLR*)GKI_getbuf(
      (uint16_t)(sizeof(tNFA_DM_API_REG_NDEF_HDLR) + type_name_len));
  if (p_msg != nullptr) {
    p_msg->hdr.event = NFA_DM_API_REG_NDEF_HDLR_EVT;

    p_msg->flags =
        (handle_whole_message ? NFA_NDEF_FLAGS_HANDLE_WHOLE_MESSAGE : 0);
    p_msg->tnf = tnf;
    p_msg->name_len = type_name_len;
    p_msg->p_ndef_cback = p_ndef_cback;
    memcpy(p_msg->name, p_type_name, type_name_len);

    nfa_sys_sendmsg(p_msg);

    return (NFA_STATUS_OK);
  }

  return (NFA_STATUS_FAILED);
}

/*******************************************************************************
**
** Function         NFA_RegisterNDefUriHandler
**
** Description      This API is a special-case of NFA_RegisterNDefTypeHandler
**                  with TNF=NFA_TNF_WKT, and type_name='U' (URI record); and
**                  allows registering for specific URI types (e.g. 'tel:' or
**                  'mailto:').
**
**                  An NFA_NDEF_REGISTER_EVT will be sent to the tNFA_NDEF_CBACK
**                  to indicate that registration was successful, and provide a
**                  handle for this registration.
**
**                  If uri_id=NFA_NDEF_URI_ID_ABSOLUTE, then p_abs_uri contains
**                  the unabridged URI. For all other uri_id values,
**                  the p_abs_uri parameter is ignored (i.e the URI prefix is
**                  implied by uri_id). See [NFC RTD URI] for more information.
**
** Returns          NFA_STATUS_OK if successfully initiated
**                  NFA_STATUS_FAILED otherwise
**
*******************************************************************************/
extern tNFA_STATUS NFA_RegisterNDefUriHandler(bool handle_whole_message,
                                              tNFA_NDEF_URI_ID uri_id,
                                              uint8_t* p_abs_uri,
                                              uint8_t uri_id_len,
                                              tNFA_NDEF_CBACK* p_ndef_cback) {
  tNFA_DM_API_REG_NDEF_HDLR* p_msg;

  DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf(
      "NFA_RegisterNDefUriHandler (): handle whole ndef message: %i, "
      "uri_id=0x%02x",
      handle_whole_message, uri_id);

  /* Check for NULL callback */
  if (!p_ndef_cback) {
    LOG(ERROR) << StringPrintf("NFA_RegisterNDefUriHandler (): error - null callback");
    return (NFA_STATUS_INVALID_PARAM);
  }

  p_msg = (tNFA_DM_API_REG_NDEF_HDLR*)GKI_getbuf(
      (uint16_t)(sizeof(tNFA_DM_API_REG_NDEF_HDLR) + uri_id_len));
  if (p_msg != nullptr) {
    p_msg->hdr.event = NFA_DM_API_REG_NDEF_HDLR_EVT;

    p_msg->flags = NFA_NDEF_FLAGS_WKT_URI;

    if (handle_whole_message) {
      p_msg->flags |= NFA_NDEF_FLAGS_HANDLE_WHOLE_MESSAGE;
    }

    /* abs_uri is only valid fir uri_id=NFA_NDEF_URI_ID_ABSOLUTE */
    if (uri_id != NFA_NDEF_URI_ID_ABSOLUTE) {
      uri_id_len = 0;
    }

    p_msg->tnf = NFA_TNF_WKT;
    p_msg->uri_id = uri_id;
    p_msg->name_len = uri_id_len;
    p_msg->p_ndef_cback = p_ndef_cback;
    memcpy(p_msg->name, p_abs_uri, uri_id_len);

    nfa_sys_sendmsg(p_msg);

    return (NFA_STATUS_OK);
  }

  return (NFA_STATUS_FAILED);
}

/*******************************************************************************
**
** Function         NFA_DeregisterNDefTypeHandler
**
** Description      Deregister NDEF record type handler.
**
** Returns          NFA_STATUS_OK if successfully initiated
**                  NFA_STATUS_FAILED otherwise
**
*******************************************************************************/
extern tNFA_STATUS NFA_DeregisterNDefTypeHandler(tNFA_HANDLE ndef_type_handle) {
  tNFA_DM_API_DEREG_NDEF_HDLR* p_msg;

  DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf("NFA_DeregisterNDefHandler (): handle 0x%08x",
                 ndef_type_handle);

  p_msg = (tNFA_DM_API_DEREG_NDEF_HDLR*)GKI_getbuf(
      (uint16_t)(sizeof(tNFA_DM_API_DEREG_NDEF_HDLR)));
  if (p_msg != nullptr) {
    p_msg->hdr.event = NFA_DM_API_DEREG_NDEF_HDLR_EVT;
    p_msg->ndef_type_handle = ndef_type_handle;

    nfa_sys_sendmsg(p_msg);

    return (NFA_STATUS_OK);
  }

  return (NFA_STATUS_FAILED);
}

/*******************************************************************************
**
** Function         NFA_PowerOffSleepMode
**
** Description      This function is called to enter or leave NFCC Power Off
**                  Sleep mode NFA_DM_PWR_MODE_CHANGE_EVT will be sent to
**                  indicate status.
**
**                  start_stop : true if entering Power Off Sleep mode
**                               false if leaving Power Off Sleep mode
**
** Returns          NFA_STATUS_OK if successfully initiated
**                  NFA_STATUS_FAILED otherwise
**
*******************************************************************************/
tNFA_STATUS NFA_PowerOffSleepMode(bool start_stop) {
  NFC_HDR* p_msg;

  DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf("NFA_PowerOffSleepState () start_stop=%d", start_stop);
  if (nfa_dm_cb.flags & NFA_DM_FLAGS_SETTING_PWR_MODE) {
    LOG(ERROR) << StringPrintf(
        "NFA_PowerOffSleepState (): NFA DM is busy to update power mode");
    return (NFA_STATUS_FAILED);
  } else {
    nfa_dm_cb.flags |= NFA_DM_FLAGS_SETTING_PWR_MODE;
  }

  p_msg = (NFC_HDR*)GKI_getbuf(sizeof(NFC_HDR));
  if (p_msg != nullptr) {
    p_msg->event = NFA_DM_API_POWER_OFF_SLEEP_EVT;
    p_msg->layer_specific = start_stop;

    nfa_sys_sendmsg(p_msg);

    return (NFA_STATUS_OK);
  }

  return (NFA_STATUS_FAILED);
}

/*******************************************************************************
**
** Function         NFA_RegVSCback
**
** Description      This function is called to register or de-register a
**                  callback function to receive Proprietary NCI response and
**                  notification events. The maximum number of callback
**                  functions allowed is NFC_NUM_VS_CBACKS
**
** Returns          tNFC_STATUS
**
*******************************************************************************/
tNFC_STATUS NFA_RegVSCback(bool is_register, tNFA_VSC_CBACK* p_cback) {
  tNFA_DM_API_REG_VSC* p_msg;

  DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf("NFA_RegVSCback() is_register=%d", is_register);

  if (p_cback == nullptr) {
    LOG(ERROR) << StringPrintf("NFA_RegVSCback() requires a valid callback function");
    return (NFA_STATUS_FAILED);
  }

  p_msg = (tNFA_DM_API_REG_VSC*)GKI_getbuf(sizeof(tNFA_DM_API_REG_VSC));
  if (p_msg != nullptr) {
    p_msg->hdr.event = NFA_DM_API_REG_VSC_EVT;
    p_msg->is_register = is_register;
    p_msg->p_cback = p_cback;

    nfa_sys_sendmsg(p_msg);

    return (NFA_STATUS_OK);
  }

  return (NFA_STATUS_FAILED);
}

/*******************************************************************************
**
** Function         NFA_SendVsCommand
**
** Description      This function is called to send an NCI Vendor Specific
**                  command to NFCC.
**
**                  oid             - The opcode of the VS command.
**                  cmd_params_len  - The command parameter len
**                  p_cmd_params    - The command parameter
**                  p_cback         - The callback function to receive the
**                                    command status
**
** Returns          NFA_STATUS_OK if successfully initiated
**                  NFA_STATUS_FAILED otherwise
**
*******************************************************************************/
tNFA_STATUS NFA_SendVsCommand(uint8_t oid, uint8_t cmd_params_len,
                              uint8_t* p_cmd_params, tNFA_VSC_CBACK* p_cback) {
  tNFA_DM_API_SEND_VSC* p_msg;
  uint16_t size = sizeof(tNFA_DM_API_SEND_VSC) + cmd_params_len;

  DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf("NFA_SendVsCommand() oid=0x%x", oid);

  p_msg = (tNFA_DM_API_SEND_VSC*)GKI_getbuf(size);
  if (p_msg != nullptr) {
    p_msg->hdr.event = NFA_DM_API_SEND_VSC_EVT;
    p_msg->oid = oid;
    p_msg->p_cback = p_cback;
    if (cmd_params_len && p_cmd_params) {
      p_msg->cmd_params_len = cmd_params_len;
      p_msg->p_cmd_params = (uint8_t*)(p_msg + 1);
      memcpy(p_msg->p_cmd_params, p_cmd_params, cmd_params_len);
    } else {
      p_msg->cmd_params_len = 0;
      p_msg->p_cmd_params = nullptr;
    }

    nfa_sys_sendmsg(p_msg);

    return (NFA_STATUS_OK);
  }

  return (NFA_STATUS_FAILED);
}

/*******************************************************************************
**
** Function         NFA_SendRawVsCommand
**
** Description      This function is called to send raw Vendor Specific
**                  command to NFCC.
**
**                  cmd_params_len  - The command parameter len
**                  p_cmd_params    - The command parameter
**                  p_cback         - The callback function to receive the
**                                    command
**
** Returns          NFA_STATUS_OK if successfully initiated
**                  NFA_STATUS_FAILED otherwise
**
*******************************************************************************/
tNFA_STATUS NFA_SendRawVsCommand(uint8_t cmd_params_len, uint8_t* p_cmd_params,
                                 tNFA_VSC_CBACK* p_cback) {
  if (cmd_params_len == 0x00 || p_cmd_params == nullptr || p_cback == nullptr) {
    return NFA_STATUS_INVALID_PARAM;
  }
  uint16_t size = sizeof(tNFA_DM_API_SEND_VSC) + cmd_params_len;
  tNFA_DM_API_SEND_VSC* p_msg = (tNFA_DM_API_SEND_VSC*)GKI_getbuf(size);

  if (p_msg != nullptr) {
    p_msg->hdr.event = NFA_DM_API_SEND_RAW_VS_EVT;
    p_msg->p_cback = p_cback;
    if (cmd_params_len && p_cmd_params) {
      p_msg->cmd_params_len = cmd_params_len;
      p_msg->p_cmd_params = (uint8_t*)(p_msg + 1);
      memcpy(p_msg->p_cmd_params, p_cmd_params, cmd_params_len);
    } else {
      p_msg->cmd_params_len = 0;
      p_msg->p_cmd_params = NULL;
    }

    nfa_sys_sendmsg(p_msg);

    return NFA_STATUS_OK;
  }

  return NFA_STATUS_FAILED;
}

/*******************************************************************************
**
** Function:        NFA_EnableDtamode
**
** Description:     Enable DTA Mode
**
** Returns:         none:
**
*******************************************************************************/
void NFA_EnableDtamode(tNFA_eDtaModes eDtaMode) {
  DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf("%s: 0x%x ", __func__, eDtaMode);
  appl_dta_mode_flag = 0x01;
  nfa_dm_cb.eDtaMode = eDtaMode;
}
#if (NXP_EXTNS == TRUE)
/*******************************************************************************
**
** Function         NFA_checkNfcStateBusy()
**
** Description      This function returns whether NFC process is busy or not

**
** Returns          if Nfc state busy return true otherwise false.
**
*******************************************************************************/
bool NFA_checkNfcStateBusy() {
  if (nfa_dm_cb.disc_cb.disc_state == NFA_DM_RFST_DISCOVERY) return false;

  return true;
}

/*******************************************************************************
**
** Function       NFA_SetReaderMode
**
** Description:
**    This function enable/disable  reader mode. In reader mode, even though if
**    P2P & CE from UICC is detected, Priority will be given to TypeF UICC read.
**    Its currently implemented for TypeF
**
**    ReaderModeFlag   Enable/Disable Reader Mode
**    Technologies     Type of technologies to be set for Reader mode
**                     Currently not used and reader mode is enabled for TypeF
*Only
**
** Returns:
**    void
*******************************************************************************/
void NFA_SetReaderMode(bool ReaderModeFlag, uint32_t Technologies) {
  (void)Technologies;

  DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf("NFA_SetReaderMode =0x%x", ReaderModeFlag);
  gFelicaReaderMode = ReaderModeFlag;
  return;
}

/*******************************************************************************
**
** Function         NFA_SetBootMode
**
** Description      This function enables the boot mode for NFC.
**                  boot_mode  0 NORMAL_BOOT 1 FAST_BOOT
**                  By default , the mode is set to NORMAL_BOOT.

**
** Returns          none
**
*******************************************************************************/
void NFA_SetBootMode(uint8_t boot_mode) { hal_Initcntxt.boot_mode = boot_mode; }
tNFA_MW_VERSION NFA_GetMwVersion() {
  tNFA_MW_VERSION mwVer;
  mwVer.cust_id = NFC_NXP_MW_CUSTOMER_ID;
  mwVer.validation =
      (NXP_EN_PN547C2 | (NXP_EN_PN65T << 1) | (NXP_EN_PN548C2 << 2) |
       (NXP_EN_PN66T << 3) | (NXP_EN_PN551 << 4) | (NXP_EN_PN67T << 5) |
       (NXP_EN_PN553 << 6) | (NXP_EN_PN80T << 7) | (NXP_EN_PN553_MR1 << 8)
        | (NXP_EN_PN81A << 9) | (NXP_EN_PN553_MR2 << 10) | (NXP_EN_PN557 << 11)
        | (NXP_EN_PN81T << 12));
  mwVer.android_version = NXP_ANDROID_VER;
  DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf("0x%x:NFC MW Major Version:", NFC_NXP_MW_VERSION_MAJ);
  DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf("0x%x:NFC MW Minor Version:", NFC_NXP_MW_VERSION_MIN);
  mwVer.major_version = NFC_NXP_MW_VERSION_MAJ;
  mwVer.minor_version = NFC_NXP_MW_VERSION_MIN;
  DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf("mwVer:Major=0x%x,Minor=0x%x", mwVer.major_version,
                 mwVer.minor_version);
  return mwVer;
}

/*******************************************************************************
**
** Function         NFA_SetLowRamDevice
**
** Description      This function sets the device is LOW RAM enabled or not
**                  param mode is either true or false
**                  true - LOW RAM DEVICE
**                  false - NOT A LOW RAM DEVICE
** Returns          none
**
*******************************************************************************/
void NFA_SetLowRamDevice(bool mode)
{
  hal_Initcntxt.isLowRam = mode;
}

/*******************************************************************************
**
** Function:        NFA_ResetNfcc
**
** Description:     Reset the NFCC
**
** Returns:         NFA_STATUS_OK if successfully initiated
**                  NFA_STATUS_FAILED otherwise
**
*******************************************************************************/
tNFA_STATUS NFA_ResetNfcc() {
    DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf("NFA_ResetNfcc()");
    if(!nfcFL.nfccFL._NFC_NXP_STAT_DUAL_UICC_EXT_SWITCH) {
        DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf("NFC_NXP_STAT_DUAL_UICC_EXT_SWITCH"
                " feature is not available!!");
        return (NFA_STATUS_FAILED);
    }
  tNFA_STATUS status = NFA_STATUS_FAILED;
  status = nfc_ncif_reset_nfcc();
  return status;
}
/*******************************************************************************
**
** Function:        NFA_EE_HCI_Control
**
** Description:     Enable/Disable EE&HCI subsystem based on mode flag.
**                  Since NFCC reset being done, to receive Ntf corresponding to
**                  UICC/ESE, EE and HCI Network has to be reset.
**                  In MW corresponding context will be cleared and
*re-initialized
**
** Returns:         none:
**
*******************************************************************************/
void NFA_EE_HCI_Control(bool flagEnable) {
  DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf("NFA_EE_HCI_Control()");
    if(!nfcFL.nfccFL._NFC_NXP_STAT_DUAL_UICC_EXT_SWITCH) {
        DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf("NFC_NXP_STAT_DUAL_UICC_EXT_SWITCH"
                " feature is not available!!");
        return;
    }
  uint8_t id[2] = {NFA_ID_HCI, NFA_ID_EE};
  uint8_t i = 0;
  if (!flagEnable) {
    DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf("NFA_EE_HCI_Control (); Disable system");
    nfa_sys_cb.graceful_disable = true;
    for (i = 0; i < 2; i++) {
      if (nfa_sys_cb.is_reg[id[i]]) {
        if (nfa_sys_cb.reg[id[i]]->disable != nullptr) {
          (*nfa_sys_cb.reg[id[i]]->disable)();
        } else {
          nfa_sys_deregister(id[i]);
          ;
        }
      }
    }
  } else {
    nfa_ee_init();
    nfa_hci_init();

    DLOG_IF(INFO, nfc_debug_enabled) << StringPrintf("NFA_EE_HCI_Control (); Enable system");
    for (i = 0; i < 2; i++) {
      if (nfa_sys_cb.is_reg[id[i]]) {
        if (nfa_sys_cb.reg[id[i]]->enable != nullptr) {
          (*nfa_sys_cb.reg[id[i]]->enable)();
        } else {
          nfa_sys_cback_notify_enable_complete(id[i]);
        }
      }
    }
  }
}

/*******************************************************************************
**
** Function         NFA_setFieldDetectMode
**
** Description      Updates field detect mode true/false
**
** Returns          void
**
*******************************************************************************/
void NFA_SetFieldDetectMode(bool mode) {
  nfa_dm_cb.isFieldDetectEnabled = mode;
  DLOG_IF(INFO, nfc_debug_enabled)
      << StringPrintf("%s fieldDetectMode = 0x%s", __func__,
                      (nfa_dm_cb.isFieldDetectEnabled) ? "ENABLE" : "DISABLE");
}

/*******************************************************************************
**
** Function         NFA_IsFieldDetectEnabled
**
** Description      Returns current status of field detect mode
**
** Returns          true/false
**
*******************************************************************************/
bool NFA_IsFieldDetectEnabled() {
    DLOG_IF(INFO, nfc_debug_enabled)
      << StringPrintf("%s Current fieldDetectMode = 0x%s", __func__,
                      (nfa_dm_cb.isFieldDetectEnabled) ? "ENABLE" : "DISABLE");
      return nfa_dm_cb.isFieldDetectEnabled;
}
#endif

/*******************************************************************************
**
** Function         NFA_GetNCIVersion
**
** Description      Returns the NCI version of the NFCC to upper layer
**
**
** Returns          NCI version NCI2.0 / NCI1.0
**
*******************************************************************************/
uint8_t NFA_GetNCIVersion()
{
    return NFC_GetNCIVersion();
}

/*******************************************************************************
**
** Function         NFA_Send_Core_Reset
**
** Description      Performs NCI Core Reset dynamically based on NCI version
**
**
** Returns          SUCCESS/FAIL
**
*******************************************************************************/
tNFA_STATUS NFA_Send_Core_Reset() {
    return nfc_hal_nfcc_reset();
}

/*******************************************************************************
**
** Function         NFA_Send_Core_Init
**
** Description      Performs NCI Core Init dynamically based on NCI version
**
**
** Returns          void
**
*******************************************************************************/
void NFA_Send_Core_Init() {
    nfc_hal_nfcc_init();
}
