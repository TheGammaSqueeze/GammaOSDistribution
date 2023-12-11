/*
 * Copyright 2015-2021 NXP
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

#include <android-base/file.h>
#include <sys/stat.h>
#include <phNxpNciHal.h>
#include <phNxpNciHal_ext.h>
#include <phNxpNciHal_Dnld.h>
#include <phNxpNciHal_Adaptation.h>
#include <phTmlNfc.h>
#include <phDnldNfc.h>
#include <phDal4Nfc_messageQueueLib.h>
#include <cutils/properties.h>
#include <phNxpLog.h>
#include <phNxpConfig.h>
#include <phNxpNciHal_NfcDepSWPrio.h>
#include <phTmlNfc_i2c.h>
#include "phNxpNciHal_nciParser.h"
#include <EseAdaptation.h>
#include "spi_spm.h"
#include <vendor/nxp/nxpnfc/2.0/types.h>
#include "Nxp_Features.h"
#include "NxpNfc.h"

using namespace android::hardware::nfc::V1_1;
using namespace android::hardware::nfc::V1_2;
using android::hardware::nfc::V1_1::NfcEvent;
using android::base::WriteStringToFile;

/*********************** Global Variables *************************************/
#define HAL_ESE_IOCTL_NFC_JCOP_DWNLD 182
#define PN547C2_CLOCK_SETTING
#undef PN547C2_FACTORY_RESET_DEBUG
#define CORE_RES_STATUS_BYTE 3
#define SIGNAL_TRIGGER_NOT_REQD 0x10
#define MAX_NXP_HAL_EXTN_BYTES 10

static ThreadMutex gsHalOpenCloseLock;

const char RF_BLOCK_LIST[6][18] =
{
    NAME_NXP_RF_CONF_BLK_1,
    NAME_NXP_RF_CONF_BLK_2,
    NAME_NXP_RF_CONF_BLK_3,
    NAME_NXP_RF_CONF_BLK_4,
    NAME_NXP_RF_CONF_BLK_5,
    NAME_NXP_RF_CONF_BLK_6
};

const char TVDD_CONFIG_LIST[3][19] =
{
    NAME_NXP_EXT_TVDD_CFG_1,
    NAME_NXP_EXT_TVDD_CFG_2,
    NAME_NXP_EXT_TVDD_CFG_3
};
#define NXP_NCI_HAL_CORE_INIT_RECOVER(recoveryCount, recoveryLabel)\
do\
{\
    recoveryCount++;\
    goto recoveryLabel;\
}while(0)

bool bEnableMfcExtns = false;
bool bEnableMfcReader = false;
bool bDisableLegacyMfcExtns = true;

/* Processing of ISO 15693 EOF */
extern uint8_t icode_send_eof;
extern uint8_t icode_detected;
static uint8_t cmd_icode_eof[] = {0x00, 0x00, 0x00};
static uint8_t read_failed_disable_nfc = false;
static uint8_t pwr_link_required = false;
static uint8_t config_access = false;
static uint8_t config_success = true;
static uint8_t fw_download_success = 0;
static NFCSTATUS phNxpNciHal_FwDwnld(uint16_t aType);
/* NCI HAL Control structure */
phNxpNciHal_Control_t nxpncihal_ctrl;

/* NXP Poll Profile structure */
phNxpNciProfile_Control_t nxpprofile_ctrl;

/* TML Context */
extern phTmlNfc_Context_t* gpphTmlNfc_Context;
extern void phTmlNfc_set_fragmentation_enabled(
    phTmlNfc_i2cfragmentation_t result);

extern int phNxpNciHal_CheckFwRegFlashRequired(uint8_t* fw_update_req,
                                               uint8_t* rf_update_req);
extern int phPalEse_spi_ioctl(phPalEse_ControlCode_t eControlCode,
                              void* pDevHandle, long level);
extern void phNxpNciHal_conf_nfc_forum_mode();
static int phNxpNciHal_fw_mw_ver_check();
phNxpNci_getCfg_info_t* mGetCfg_info = NULL;
uint32_t gSvddSyncOff_Delay = 10;
bool_t force_fw_download_req = false;
bool_t gParserCreated = FALSE;
bool nfc_debug_enabled = true;
ESE_UPDATE_STATE eseUpdateSpi = ESE_UPDATE_COMPLETED;
ESE_UPDATE_STATE eseUpdateDwp = ESE_UPDATE_COMPLETED;
nfc_stack_callback_t* p_nfc_stack_cback_backup;
/* global variable to get FW version from NCI response*/
uint32_t wFwVerRsp;
EseAdaptation *gpEseAdapt = NULL;
/* External global variable to get FW version */
extern uint16_t wFwVer;

extern uint16_t rom_version;
extern uint8_t
    gRecFWDwnld; /* flag  set to true to  indicate dummy FW download */
static uint8_t gRecFwRetryCount;  // variable to hold dummy FW recovery count
static uint8_t write_unlocked_status = NFCSTATUS_SUCCESS;
static uint8_t Rx_data[NCI_MAX_DATA_LEN];
uint32_t timeoutTimerId = 0;
/*  Used to send Callback Transceive data during Mifare Write.
 *  If this flag is enabled, no need to send response to Upper layer */
bool sendRspToUpperLayer = true;

phNxpNciHal_Sem_t config_data;

phNxpNciClock_t phNxpNciClock = {0, {0}};

phNxpNciRfSetting_t phNxpNciRfSet = {false, {0}};

/**************** local methods used in this file only ************************/
static NFCSTATUS phNxpNciHal_fw_download(void);
tNFC_chipType phNxpNciHal_getChipType(void);
static void phNxpNciHal_open_complete(NFCSTATUS status);
static void phNxpNciHal_MinOpen_complete(NFCSTATUS status);
static void phNxpNciHal_write_complete(void* pContext,
                                       phTmlNfc_TransactInfo_t* pInfo);
static void phNxpNciHal_read_complete(void* pContext,
                                      phTmlNfc_TransactInfo_t* pInfo);
static void phNxpNciHal_close_complete(NFCSTATUS status);
static void phNxpNciHal_core_initialized_complete(NFCSTATUS status);
static void phNxpNciHal_power_cycle_complete(NFCSTATUS status);
static void phNxpNciHal_kill_client_thread(
    phNxpNciHal_Control_t* p_nxpncihal_ctrl);
static void* phNxpNciHal_client_thread(void* arg);
static void phNxpNciHal_nfccClockCfgRead(void);
static NFCSTATUS phNxpNciHal_nfccClockCfgApply(void);
static void phNxpNciHal_txNfccClockSetCmd(void);
static NFCSTATUS phNxpNciHal_check_eSE_Session_Identity(void);
static void phNxpNciHal_hci_network_reset(void);
static void phNxpNciHal_print_res_status(uint8_t* p_rx_data, uint16_t* p_len);
static NFCSTATUS phNxpNciHal_CheckValidFwVersion(void);
static void phNxpNciHal_enable_i2c_fragmentation();
static void phNxpNciHal_core_MinInitialized_complete(NFCSTATUS status);
NFCSTATUS phNxpNciHal_set_china_region_configs(void);
static void phNxpNciHal_configNciParser(void);
static void phNxpNciHal_initialize_debug_enabled_flag();
static void phNxpNciHal_initialize_mifare_flag();
static NFCSTATUS phNxpNciHalRFConfigCmdRecSequence();
static NFCSTATUS phNxpNciHal_CheckRFCmdRespStatus();
static NFCSTATUS phNxpNciHal_uicc_baud_rate();
static void phNxpNciHal_gpio_restore(phNxpNciHal_GpioInfoState state);
NFCSTATUS phNxpNciHal_nfcc_core_reset_init();
NFCSTATUS phNxpNciHal_getChipInfoInFwDnldMode(void);
static void phNxpNciHal_notifyHciEvtProcessComplete();
#ifdef FactoryOTA
void phNxpNciHal_isFactoryOTAModeActive();
static NFCSTATUS phNxpNciHal_disableFactoryOTAMode(void);
#endif

/******************************************************************************
 * Function         phNxpNciHal_initialize_debug_enabled_flag
 *
 * Description      This function gets the value for nfc_debug_enabled
 *
 * Returns          void
 *
 ******************************************************************************/
static void phNxpNciHal_initialize_debug_enabled_flag() {
  unsigned long num = 0;
  char valueStr[PROPERTY_VALUE_MAX] = {0};
  if(GetNxpNumValue(NAME_NFC_DEBUG_ENABLED, &num, sizeof(num))) {
    nfc_debug_enabled = (num == 0) ? false : true;

  }

  int len = property_get("nfc.debug_enabled", valueStr, "");
  if (len > 0) {
        // let Android property override .conf variable
    unsigned debug_enabled = 0;
    sscanf(valueStr, "%u", &debug_enabled);
    nfc_debug_enabled = (debug_enabled == 0) ? false : true;
  }
  NXPLOG_NCIHAL_D("nfc_debug_enabled : %d",nfc_debug_enabled);

}
//static tNfc_featureList phNxpNciHal_getFeatureList();
/******************************************************************************
 * Function         phNxpNciHal_client_thread
 *
 * Description      This function is a thread handler which handles all TML and
 *                  NCI messages.
 *
 * Returns          void
 *
 ******************************************************************************/
static void* phNxpNciHal_client_thread(void* arg) {
  phNxpNciHal_Control_t* p_nxpncihal_ctrl = (phNxpNciHal_Control_t*)arg;
  phLibNfc_Message_t msg;

  NXPLOG_NCIHAL_D("thread started");

  p_nxpncihal_ctrl->thread_running = 1;

  while (p_nxpncihal_ctrl->thread_running == 1) {
    /* Fetch next message from the NFC stack message queue */
    if (phDal4Nfc_msgrcv(p_nxpncihal_ctrl->gDrvCfg.nClientId, &msg, 0, 0) ==
        -1) {
      NXPLOG_NCIHAL_E("NFC client received bad message");
      continue;
    }

    if (p_nxpncihal_ctrl->thread_running == 0) {
      break;
    }
    switch (msg.eMsgType) {
      case PH_LIBNFC_DEFERREDCALL_MSG: {
        phLibNfc_DeferredCall_t* deferCall =
            (phLibNfc_DeferredCall_t*)(msg.pMsgData);

        REENTRANCE_LOCK();
        deferCall->pCallback(deferCall->pParameter);
        REENTRANCE_UNLOCK();

        break;
      }

      case NCI_HAL_OPEN_CPLT_MSG: {
        REENTRANCE_LOCK();
        if (nxpncihal_ctrl.p_nfc_stack_cback != NULL) {
          /* Send the event */
          (*nxpncihal_ctrl.p_nfc_stack_cback)(HAL_NFC_OPEN_CPLT_EVT,
                                              HAL_NFC_STATUS_OK);
        }
        REENTRANCE_UNLOCK();
        break;
      }

      case NCI_HAL_CLOSE_CPLT_MSG: {
        REENTRANCE_LOCK();
        if (nxpncihal_ctrl.p_nfc_stack_cback != NULL) {
          /* Send the event */
          (*nxpncihal_ctrl.p_nfc_stack_cback)(HAL_NFC_CLOSE_CPLT_EVT,
                                              HAL_NFC_STATUS_OK);
        }
        phNxpNciHal_kill_client_thread(&nxpncihal_ctrl);
        REENTRANCE_UNLOCK();
        break;
      }

      case NCI_HAL_POST_INIT_CPLT_MSG: {
        REENTRANCE_LOCK();
        if (nxpncihal_ctrl.p_nfc_stack_cback != NULL) {
          /* Send the event */
          (*nxpncihal_ctrl.p_nfc_stack_cback)(HAL_NFC_POST_INIT_CPLT_EVT,
                                              HAL_NFC_STATUS_OK);
        }
        REENTRANCE_UNLOCK();
        break;
      }

      case NCI_HAL_PRE_DISCOVER_CPLT_MSG: {
        REENTRANCE_LOCK();
        if (nxpncihal_ctrl.p_nfc_stack_cback != NULL) {
          /* Send the event */
          (*nxpncihal_ctrl.p_nfc_stack_cback)(HAL_NFC_PRE_DISCOVER_CPLT_EVT,
                                              HAL_NFC_STATUS_OK);
        }
        REENTRANCE_UNLOCK();
        break;
      }

      case NCI_HAL_HCI_NETWORK_RESET_MSG: {
        REENTRANCE_LOCK();
        if (nxpncihal_ctrl.p_nfc_stack_cback != NULL) {
          /* Send the event */
          (*nxpncihal_ctrl.p_nfc_stack_cback)(
              (uint32_t)NfcEvent::HCI_NETWORK_RESET, HAL_NFC_STATUS_OK);
          property_set("persist.vendor.nfc.hci_network_reset_req", "false");
        }
        REENTRANCE_UNLOCK();
        break;
      }

      case NCI_HAL_ERROR_MSG: {
        REENTRANCE_LOCK();
        if (nxpncihal_ctrl.p_nfc_stack_cback != NULL) {
          /* Send the event */
          (*nxpncihal_ctrl.p_nfc_stack_cback)(HAL_NFC_ERROR_EVT,
                                              HAL_NFC_STATUS_FAILED);
        }
        REENTRANCE_UNLOCK();
        break;
      }

      case NCI_HAL_RX_MSG: {
        REENTRANCE_LOCK();
        if (nxpncihal_ctrl.p_nfc_stack_data_cback != NULL) {
          (*nxpncihal_ctrl.p_nfc_stack_data_cback)(nxpncihal_ctrl.rsp_len,
                                                   nxpncihal_ctrl.p_rsp_data);
        }
        REENTRANCE_UNLOCK();
        break;
      }
      case NCI_HAL_POST_MIN_INIT_CPLT_MSG: {
        REENTRANCE_LOCK();
        if (nxpncihal_ctrl.p_nfc_stack_cback != NULL) {
          /* Send the event */
          (*nxpncihal_ctrl.p_nfc_stack_cback)(HAL_NFC_POST_MIN_INIT_CPLT_EVT,
                                              HAL_NFC_STATUS_OK);
        }
        REENTRANCE_UNLOCK();
        break;
      }
    }
  }

  NXPLOG_NCIHAL_D("NxpNciHal thread stopped");

  return NULL;
}

/******************************************************************************
 * Function         phNxpNciHal_kill_client_thread
 *
 * Description      This function safely kill the client thread and clean all
 *                  resources.
 *
 * Returns          void.
 *
 ******************************************************************************/
static void phNxpNciHal_kill_client_thread(
    phNxpNciHal_Control_t* p_nxpncihal_ctrl) {
  NXPLOG_NCIHAL_D("Terminating phNxpNciHal client thread...");

  p_nxpncihal_ctrl->p_nfc_stack_cback = NULL;
  p_nxpncihal_ctrl->p_nfc_stack_data_cback = NULL;
  p_nxpncihal_ctrl->thread_running = 0;

  return;
}
/******************************************************************************
 * Function         phNxpNciHal_gpio_restore
 *
 * Description      This function restores the gpio values into eeprom
 *
 * Returns          void
 *
 ******************************************************************************/
static void phNxpNciHal_gpio_restore(phNxpNciHal_GpioInfoState state) {
  NFCSTATUS status = NFCSTATUS_SUCCESS;
  uint8_t get_gpio_values_cmd[] = {0x20, 0x03, 0x03, 0x01, 0xA0, 0x00};
  uint8_t set_gpio_values_cmd[] = {
      0x20, 0x02, 0x00, 0x01, 0xA0, 0x00, 0x20, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

  if (state == GPIO_STORE) {
    nxpncihal_ctrl.phNxpNciGpioInfo.state = GPIO_STORE;
    get_gpio_values_cmd[5] = 0x08;
    status = phNxpNciHal_send_ext_cmd(sizeof(get_gpio_values_cmd),
                                      get_gpio_values_cmd);
    if (status != NFCSTATUS_SUCCESS) {
      NXPLOG_NCIHAL_E("Failed to get GPIO values!!!\n");
      return;
    }

    nxpncihal_ctrl.phNxpNciGpioInfo.state = GPIO_STORE_DONE;
    set_gpio_values_cmd[2] = 0x24;
    set_gpio_values_cmd[5] = 0x14;
    NXPLOG_NCIHAL_D("%s: Storing Actual GPIO Values...", __func__);
    set_gpio_values_cmd[7] = nxpncihal_ctrl.phNxpNciGpioInfo.values[0];
    set_gpio_values_cmd[8] = nxpncihal_ctrl.phNxpNciGpioInfo.values[1];
    status = phNxpNciHal_send_ext_cmd(sizeof(set_gpio_values_cmd),
                                      set_gpio_values_cmd);
    if (status != NFCSTATUS_SUCCESS) {
      NXPLOG_NCIHAL_E("Failed to set GPIO values!!!\n");
      return;
    }
  } else if (state == GPIO_RESTORE) {
    nxpncihal_ctrl.phNxpNciGpioInfo.state = GPIO_RESTORE;
    get_gpio_values_cmd[5] = 0x14;
    status = phNxpNciHal_send_ext_cmd(sizeof(get_gpio_values_cmd),
                                      get_gpio_values_cmd);
    if (status != NFCSTATUS_SUCCESS) {
      NXPLOG_NCIHAL_E("Failed to get GPIO values!!!\n");
      return;
    }

    nxpncihal_ctrl.phNxpNciGpioInfo.state = GPIO_RESTORE_DONE;
    set_gpio_values_cmd[2] = 0x06;
    set_gpio_values_cmd[5] = 0x08; // update TAG
    set_gpio_values_cmd[6] = 0x02; // update length
    NXPLOG_NCIHAL_D("%s: Restoring Stored GPIO Values...", __func__);
    set_gpio_values_cmd[7] = nxpncihal_ctrl.phNxpNciGpioInfo.values[0];
    set_gpio_values_cmd[8] = nxpncihal_ctrl.phNxpNciGpioInfo.values[1];
    status = phNxpNciHal_send_ext_cmd(9, set_gpio_values_cmd);
    if (status != NFCSTATUS_SUCCESS) {
      NXPLOG_NCIHAL_E("Failed to set GPIO values!!!\n");
      return;
    }
  } else {
    NXPLOG_NCIHAL_E("GPIO Restore Invalid Option!!!\n");
  }
}
/******************************************************************************
 * Function         phNxpNciHal_getChipInfoInFwDnldMode
 *
 * Description      Helper function to get the chip info in download mode
 *
 * Returns          Status
 *
 ******************************************************************************/
NFCSTATUS phNxpNciHal_getChipInfoInFwDnldMode(void) {
  NFCSTATUS status = NFCSTATUS_FAILED;
  uint8_t retry_cnt = 0;
  uint8_t get_chip_info_cmd[] = {0x00, 0x04, 0xF1, 0x00,
                                 0x00, 0x00, 0x6E, 0xEF};
  NXPLOG_NCIHAL_D("%s:enter", __func__);
retry:
  status =
      phNxpNciHal_send_ext_cmd(sizeof(get_chip_info_cmd), get_chip_info_cmd);
  if (status != NFCSTATUS_SUCCESS) {
    if (retry_cnt < 3) {
      NXPLOG_NCIHAL_D("Retry: get chip info");
      retry_cnt++;
      goto retry;
    } else {
      NXPLOG_NCIHAL_E("Failed: get chip info");
    }
  } else {
    phNxpNciHal_configFeatureList(nxpncihal_ctrl.p_rx_data,
                                  nxpncihal_ctrl.rx_data_len);
  }
  NXPLOG_NCIHAL_D("%s:exit  status: 0x%02x", __func__, status);
  return status;
}

/******************************************************************************
 * Function         phNxpNciHal_fw_download
 *
 * Description      This function download the PN54X secure firmware to IC. If
 *                  firmware version in Android filesystem and firmware in the
 *                  IC is same then firmware download will return with success
 *                  without downloading the firmware.
 *
 * Returns          NFCSTATUS_SUCCESS if firmware download successful
 *                  NFCSTATUS_FAILED in case of failure
 *                  NFCSTATUS_REJECTED if FW version is invalid or if hardware
 *                                     criteria is not matching
 *
 ******************************************************************************/
static NFCSTATUS phNxpNciHal_fw_download(void) {
  NFCSTATUS readRestoreStatus = NFCSTATUS_FAILED;
  if (NFCSTATUS_SUCCESS != phNxpNciHal_CheckValidFwVersion()) {
    return NFCSTATUS_REJECTED;
  }

  if (nfcFL.nfcNxpEse == true) {
    uint32_t level = 0x03;
    int spi_current_state = phNxpNciHal_getSPMStatus(level);
    NXPLOG_NCIHAL_D("spi_current_state  = %4x ", spi_current_state);
    if (spi_current_state != P61_STATE_IDLE) {
      NXPLOG_NCIHAL_E("FW download denied while SPI in use, Continue NFC init");
      return NFCSTATUS_REJECTED;
    }
  }

  nxpncihal_ctrl.phNxpNciGpioInfo.state = GPIO_UNKNOWN;
  phNxpNciHal_gpio_restore(GPIO_STORE);

  int fw_retry_count = 0;
  NFCSTATUS status = NFCSTATUS_REJECTED;
  NXPLOG_NCIHAL_D("Starting FW update");
  do {
    fw_download_success = 0;
    // phNxpNciHal_get_clk_freq();
    status = phTmlNfc_IoCtl(phTmlNfc_e_EnableDownloadMode);
    if (NFCSTATUS_SUCCESS != status) {
      fw_retry_count++;
      NXPLOG_NCIHAL_D("Retrying: FW download");
      continue;
    }

    if (nxpncihal_ctrl.bIsForceFwDwnld) {
      status = phNxpNciHal_getChipInfoInFwDnldMode();
      if (status != NFCSTATUS_SUCCESS) {
        NXPLOG_NCIHAL_E("Unknown chip type, FW can't be upgraded");
        return status;
      }
    }

    /* Set the obtained device handle to download module */
    phDnldNfc_SetHwDevHandle();
    NXPLOG_NCIHAL_D("Calling Seq handler for FW Download \n");
    if (nfcFL.nfccFL._NFCC_FORCE_FW_DOWNLOAD) {
      status = phNxpNciHal_fw_download_seq(nxpprofile_ctrl.bClkSrcVal,
                                           nxpprofile_ctrl.bClkFreqVal,
                                           force_fw_download_req);
    } else {
      status = phNxpNciHal_fw_download_seq(nxpprofile_ctrl.bClkSrcVal,
                                           nxpprofile_ctrl.bClkFreqVal, false);
    }
    if (status != NFCSTATUS_SUCCESS) {
      phDnldNfc_ReSetHwDevHandle();
      fw_retry_count++;
      if (phTmlNfc_ReadAbort() != NFCSTATUS_SUCCESS) {
        NXPLOG_NCIHAL_E("Tml Read Abort failed!!");
      }
      /*Keep Read Pending on I2C*/
      readRestoreStatus = phTmlNfc_Read(
          nxpncihal_ctrl.p_cmd_data, NCI_MAX_DATA_LEN,
          (pphTmlNfc_TransactCompletionCb_t)&phNxpNciHal_read_complete, NULL);
      if (readRestoreStatus != NFCSTATUS_PENDING) {
        status = NFCSTATUS_FAILED;
        NXPLOG_NCIHAL_E("TML Read status error status = %x", readRestoreStatus);
        break;
      }
      NXPLOG_NCIHAL_D("Retrying: FW download");
    }
  } while ((fw_retry_count < 3) && (status != NFCSTATUS_SUCCESS));

  if (status != NFCSTATUS_SUCCESS) {
    if (NFCSTATUS_SUCCESS != phNxpNciHal_fw_mw_ver_check()) {
      NXPLOG_NCIHAL_D("Chip Version Middleware Version mismatch!!!!");
      phOsalNfc_Timer_Cleanup();
      phTmlNfc_Shutdown_CleanUp();
      status = NFCSTATUS_FAILED;
    } else {
      NXPLOG_NCIHAL_E("FW download failed, Continue NFCC init");
    }
  } else {
    status = NFCSTATUS_SUCCESS;
    fw_download_success = 1;
    property_set("persist.vendor.nfc.hci_network_reset_req", "true");
  }

  /*Keep Read Pending on I2C*/
  readRestoreStatus = phTmlNfc_Read(
      nxpncihal_ctrl.p_cmd_data, NCI_MAX_DATA_LEN,
      (pphTmlNfc_TransactCompletionCb_t)&phNxpNciHal_read_complete, NULL);
  if (readRestoreStatus != NFCSTATUS_PENDING) {
    NXPLOG_NCIHAL_E("TML Read status error status = %x", readRestoreStatus);
    readRestoreStatus = phTmlNfc_Shutdown_CleanUp();
    if (readRestoreStatus != NFCSTATUS_SUCCESS) {
      NXPLOG_NCIHAL_E("TML Shutdown failed. Status  = %x", readRestoreStatus);
    }
  }
  phDnldNfc_ReSetHwDevHandle();
  if (status == NFCSTATUS_SUCCESS) {
    status = phNxpNciHal_nfcc_core_reset_init();
    if (status == NFCSTATUS_SUCCESS) {
      phNxpNciHal_gpio_restore(GPIO_RESTORE);
    } else {
      NXPLOG_NCIHAL_D("Failed to restore GPIO values!!!\n");
    }
  }

  return status;
}

/******************************************************************************
 * Function         phNxpNciHal_nfcc_core_reset_init
 *
 * Description      Helper function to do nfcc core reset & core init
 *
 * Returns          Status
 *
 ******************************************************************************/
NFCSTATUS phNxpNciHal_nfcc_core_reset_init() {
  NFCSTATUS status = NFCSTATUS_FAILED;
  uint8_t retry_cnt = 0;
  uint8_t cmd_reset_nci[] = {0x20, 0x00, 0x01, 0x01};

retry_core_reset:
  status = phNxpNciHal_send_ext_cmd(sizeof(cmd_reset_nci), cmd_reset_nci);
  if ((status != NFCSTATUS_SUCCESS) && (retry_cnt < 3)) {
    NXPLOG_NCIHAL_D("Retry: NCI_CORE_RESET");
    retry_cnt++;
    goto retry_core_reset;
  } else if (status != NFCSTATUS_SUCCESS) {
    NXPLOG_NCIHAL_E("NCI_CORE_RESET failed!!!\n");
    return status;
  }

  retry_cnt = 0;
  uint8_t cmd_init_nci[] = {0x20, 0x01, 0x00};
  uint8_t cmd_init_nci2_0[] = {0x20, 0x01, 0x02, 0x00, 0x00};
retry_core_init:
  if (nxpncihal_ctrl.nci_info.nci_version == NCI_VERSION_2_0) {
    status = phNxpNciHal_send_ext_cmd(sizeof(cmd_init_nci2_0), cmd_init_nci2_0);
  } else {
    status = phNxpNciHal_send_ext_cmd(sizeof(cmd_init_nci), cmd_init_nci);
  }

  if ((status != NFCSTATUS_SUCCESS) && (retry_cnt < 3)) {
    NXPLOG_NCIHAL_D("Retry: NCI_CORE_INIT\n");
    retry_cnt++;
    goto retry_core_init;
  } else if (status != NFCSTATUS_SUCCESS) {
    NXPLOG_NCIHAL_E("NCI_CORE_INIT failed!!!\n");
    return status;
  }

  return status;
}

/******************************************************************************
 * Function         phNxpNciHal_CheckValidFwVersion
 *
 * Description      This function checks the valid FW for Mobile device.
 *                  If the FW doesn't belong the Mobile device it further
 *                  checks nxp config file to override.
 *
 * Returns          NFCSTATUS_SUCCESS if valid fw version found
 *                  NFCSTATUS_NOT_ALLOWED in case of FW not valid for mobile
 *                  device
 *
 ******************************************************************************/
static NFCSTATUS phNxpNciHal_CheckValidFwVersion(void) {
  NFCSTATUS status = NFCSTATUS_NOT_ALLOWED;
  const unsigned char sfw_infra_major_no = 0x02;
  unsigned char ufw_current_major_no = 0x00;
  unsigned long num = 0;
  int isfound = 0;

  /* extract the firmware's major no */
  ufw_current_major_no = ((0x00FF) & (wFwVer >> 8U));

  NXPLOG_NCIHAL_D("%s current_major_no = 0x%x", __func__, ufw_current_major_no);

  if (nfcFL.chipType >= pn547C2 && nfcFL.chipType <= pn81T) {
    unsigned char fw_major_no = 0x00;
    if(wFwVerRsp != 0x00) {
      fw_major_no = ((wFwVerRsp >> 8) & 0x000000FF);
      if(ufw_current_major_no >= fw_major_no) {
        status = NFCSTATUS_SUCCESS;
      } else {
        NXPLOG_NCIHAL_E("Wrong FW Version >>> Firmware download not allowed");
      }
    } else {
      NXPLOG_NCIHAL_E(
          "FW Version not received by NCI command >>> Force Firmware download");
      status = NFCSTATUS_SUCCESS;
    }
  } else if (ufw_current_major_no == nfcFL.nfcMwFL._FW_MOBILE_MAJOR_NUMBER) {
    status = NFCSTATUS_SUCCESS;
  } else if (ufw_current_major_no == sfw_infra_major_no) {
        if(rom_version == FW_MOBILE_ROM_VERSION_PN553 || rom_version == FW_MOBILE_ROM_VERSION_PN557) {
          NXPLOG_NCIHAL_D(" PN557  allow Fw download with major number =  0x%x",
          ufw_current_major_no);
          status = NFCSTATUS_SUCCESS;
        } else {
    /* Check the nxp config file if still want to go for download */
    /* By default NAME_NXP_FW_PROTECION_OVERRIDE will not be defined in config
       file.
       If user really want to override the Infra firmware over mobile firmware,
       please
       put "NXP_FW_PROTECION_OVERRIDE=0x01" in libnfc-nxp.conf file.
       Please note once Infra firmware downloaded to Mobile device, The device
       can never be updated to Mobile firmware*/
    isfound = GetNxpNumValue(NAME_NXP_FW_PROTECION_OVERRIDE, &num, sizeof(num));
    if (isfound > 0) {
      if (num == 0x01) {
        NXPLOG_NCIHAL_D("Override Infra FW over Mobile");
        status = NFCSTATUS_SUCCESS;
      } else {
        NXPLOG_NCIHAL_D(
            "Firmware download not allowed (NXP_FW_PROTECION_OVERRIDE invalid "
            "value)");
      }
    } else {
      NXPLOG_NCIHAL_D(
          "Firmware download not allowed (NXP_FW_PROTECION_OVERRIDE not "
          "defiend)");
    }
  }
  }
  else if ((nfcFL.chipType != pn547C2) && (gRecFWDwnld == TRUE)) {
    status = NFCSTATUS_SUCCESS;
  }
  else if (wFwVerRsp == 0) {
    NXPLOG_NCIHAL_E(
        "FW Version not received by NCI command >>> Force Firmware download");
    status = NFCSTATUS_SUCCESS;
  } else {
    NXPLOG_NCIHAL_E("Wrong FW Version >>> Firmware download not allowed");
  }

  return status;
}

/******************************************************************************
 * Function         phNxpNciHal_FwDwnld
 *
 * Description      This function is called by libnfc-nci after core init is
 *                  completed, to download the firmware.
 *
 * Returns          This function return NFCSTATUS_SUCCES (0) in case of success
 *                  In case of failure returns other failure value.
 *
 ******************************************************************************/
static NFCSTATUS phNxpNciHal_FwDwnld(uint16_t aType) {
   NFCSTATUS status = NFCSTATUS_SUCCESS;

   if(aType != NFC_STATUS_NOT_INITIALIZED) {
    phDnldNfc_InitImgInfo();
    status= phNxpNciHal_CheckValidFwVersion();
   }
   if (NFCSTATUS_SUCCESS == status) {
     NXPLOG_NCIHAL_D("Found Valid Firmware Type");
       status = phNxpNciHal_fw_download();
       if (status != NFCSTATUS_SUCCESS) {
         if (NFCSTATUS_SUCCESS != phNxpNciHal_fw_mw_ver_check()) {
           NXPLOG_NCIHAL_D("Chip Version Middleware Version mismatch!!!!");
           goto clean_and_return;
         }
         NXPLOG_NCIHAL_E("FW Download failed - NFCC init will continue");
       }
   } else {
     if (wFwVerRsp == 0) phDnldNfc_ReSetHwDevHandle();
   }
clean_and_return:
  return status;
}
/******************************************************************************
 * Function         phNxpNciHal_MinInit
 *
 * Description      This function is called by libnfc-nci during the minimum
 *                  initialization of the NFCC. It opens the physical connection
 *                  with NFCC (PN54X) and creates required client thread for
 *                  operation.
 *                  After open is complete, status is informed to libnfc-nci
 *                  through callback function.
 *
 * Returns          This function return NFCSTATUS_SUCCES (0) in case of success
 *                  In case of failure returns other failure value.
 *                  NFCSTATUS_FAILED(0xFF)
 *
 ******************************************************************************/
int phNxpNciHal_MinInit(nfc_stack_callback_t* p_cback,
                        nfc_stack_data_callback_t* p_data_cback) {
  NXPLOG_NCIHAL_E("Init monitor phNxpNciHal_MinInit");
  NFCSTATUS status = NFCSTATUS_SUCCESS;
  phOsalNfc_Config_t tOsalConfig;
  phTmlNfc_Config_t tTmlConfig;
  int init_retry_cnt = 0;
  uint8_t boot_mode = nxpncihal_ctrl.hal_boot_mode;
  char* nfc_dev_node = NULL;
  const uint16_t max_len = 260;

  phNxpNciHal_initialize_debug_enabled_flag();
  phNxpLog_InitializeLogLevel();

  /* initialize Mifare flags*/
  phNxpNciHal_initialize_mifare_flag();

  /*Create the timer for extns write response*/
  timeoutTimerId = phOsalNfc_Timer_Create();
  if (timeoutTimerId == PH_OSALNFC_TIMER_ID_INVALID) {
    NXPLOG_NCIHAL_E("Invalid Timer Id, Timer Creation failed");
    return NFCSTATUS_FAILED;
  }

  if (phNxpNciHal_init_monitor() == NULL) {
    NXPLOG_NCIHAL_E("Init monitor failed");
    phOsalNfc_Timer_Delete(timeoutTimerId);
    return NFCSTATUS_FAILED;
  }

  CONCURRENCY_LOCK();

  memset(&nxpncihal_ctrl, 0x00, sizeof(nxpncihal_ctrl));
  memset(&tOsalConfig, 0x00, sizeof(tOsalConfig));
  memset(&tTmlConfig, 0x00, sizeof(tTmlConfig));
  memset(&nxpprofile_ctrl, 0, sizeof(phNxpNciProfile_Control_t));

  /* By default HAL status is HAL_STATUS_OPEN */
  nxpncihal_ctrl.halStatus = HAL_STATUS_OPEN;

  nxpncihal_ctrl.p_nfc_stack_cback = p_cback;
  nxpncihal_ctrl.p_nfc_stack_data_cback = p_data_cback;

  /* Configure hardware link */
  nxpncihal_ctrl.gDrvCfg.nClientId = phDal4Nfc_msgget(0, 0600);
  nxpncihal_ctrl.gDrvCfg.nLinkType = ENUM_LINK_TYPE_I2C; /* For PN54X */
  nxpncihal_ctrl.hal_boot_mode = boot_mode;

  /*Get the device node name from config file*/
  /* Read the nfc device node name */
  nfc_dev_node = (char*)nxp_malloc(max_len * sizeof(char));
  if (nfc_dev_node == NULL) {
    NXPLOG_NCIHAL_D("malloc of nfc_dev_node failed ");

    CONCURRENCY_UNLOCK();

    return NFCSTATUS_FAILED;
  } else if (!GetNxpStrValue(NAME_NXP_NFC_DEV_NODE, nfc_dev_node,
                             max_len * sizeof(uint8_t))) {
    NXPLOG_NCIHAL_E(
        "Invalid nfc device node name keeping the default device node "
        "/dev/pn54x");
    strncpy(nfc_dev_node, "/dev/pn54x", strlen("/dev/pn54x") + 1);
  }

  tTmlConfig.pDevName = (int8_t*)nfc_dev_node;

  tOsalConfig.dwCallbackThreadId = (uintptr_t)nxpncihal_ctrl.gDrvCfg.nClientId;
  tOsalConfig.pLogFile = NULL;
  tTmlConfig.dwGetMsgThreadId = (uintptr_t)nxpncihal_ctrl.gDrvCfg.nClientId;

  /* Initialize TML layer */
  status = phTmlNfc_Init(&tTmlConfig);
  if (status == NFCSTATUS_SUCCESS) {
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
    if (pthread_create(&nxpncihal_ctrl.client_thread, &attr,
                       phNxpNciHal_client_thread, &nxpncihal_ctrl) == 0x00) {
      status = phTmlNfc_Read(
          nxpncihal_ctrl.p_cmd_data, NCI_MAX_DATA_LEN,
          (pphTmlNfc_TransactCompletionCb_t)&phNxpNciHal_read_complete, NULL);
      if (status == NFCSTATUS_PENDING) {
        phNxpNciHal_ext_init();
        status = phNxpNciHal_nfcc_core_reset_init();
        if (status != NFCSTATUS_SUCCESS) {
          status = phNxpNciHal_FwDwnld(NFC_STATUS_NOT_INITIALIZED);
          if (status != NFCSTATUS_SUCCESS) {
            return NFCSTATUS_FAILED;
          } else {
            do {
              status = phNxpNciHal_nfcc_core_reset_init();
              if (status != NFCSTATUS_SUCCESS) {
                (void)phNxpNciHal_power_cycle();
              } else {
                break;
              }
              init_retry_cnt++;
            } while (init_retry_cnt < 0x03);
          }
        } else {
          /*Do Nothing*/
        }
      }
    }
    pthread_attr_destroy(&attr);
  }
  CONCURRENCY_UNLOCK();
  init_retry_cnt = 0;
  if (status == NFCSTATUS_SUCCESS) {
    /* print message*/
    phNxpNciHal_core_MinInitialized_complete(status);
  } else {
    phTmlNfc_Shutdown_CleanUp();
    if (p_cback != NULL) {
      (*p_cback)(HAL_NFC_OPEN_CPLT_EVT, HAL_NFC_STATUS_FAILED);
  }
    /* Report error status */
    nxpncihal_ctrl.p_nfc_stack_cback = NULL;
    nxpncihal_ctrl.p_nfc_stack_data_cback = NULL;
    phNxpNciHal_cleanup_monitor();
    nxpncihal_ctrl.halStatus = HAL_STATUS_CLOSE;
  }
  if (nfc_dev_node != NULL) {
    free(nfc_dev_node);
    nfc_dev_node = NULL;
  }
  return status;
}

/******************************************************************************
 * Function         phNxpNciHal_MinOpen
 *
 * Description      This function initializes the least required resources to
 *                  communicate to NFCC.This is mainly used to communicate to
 *                  NFCC when NFC service is not available.
 *
 *
 * Returns          This function return NFCSTATUS_SUCCES (0) in case of success
 *                  In case of failure returns other failure value.
 *
 ******************************************************************************/
int phNxpNciHal_MinOpen() {
  phOsalNfc_Config_t tOsalConfig;
  phTmlNfc_Config_t tTmlConfig;
  char* nfc_dev_node = NULL;
  const uint16_t max_len = 260;
  NFCSTATUS wConfigStatus = NFCSTATUS_SUCCESS;
  NFCSTATUS status = NFCSTATUS_SUCCESS;
  uint8_t boot_mode = nxpncihal_ctrl.hal_boot_mode;
  nxpncihal_ctrl.bIsForceFwDwnld = false;
  static bool sIsForceFwDownloadReqd = false;
  NXPLOG_NCIHAL_D("phNxpNci_MinOpen(): enter");
  /*NCI_INIT_CMD*/
  static uint8_t cmd_init_nci[] = {0x20, 0x01, 0x00};
  /*NCI_RESET_CMD*/
  static uint8_t cmd_reset_nci[] = {0x20, 0x00, 0x01, 0x00};
  /*NCI2_0_INIT_CMD*/
  static uint8_t cmd_init_nci2_0[] = {0x20, 0x01, 0x02, 0x00, 0x00};
  if (nxpncihal_ctrl.halStatus == HAL_STATUS_MIN_OPEN) {
    NXPLOG_NCIHAL_D("phNxpNciHal_MinOpen(): already open");
    return NFCSTATUS_SUCCESS;
  }

  int init_retry_cnt = 0;
  int8_t ret_val = 0x00;
  uint8_t fwFlashReq =0, rfUpdateReq = 0;

  phNxpNciHal_initialize_debug_enabled_flag();
  /* initialize trace level */
  phNxpLog_InitializeLogLevel();
  /* initialize Mifare flags*/
  phNxpNciHal_initialize_mifare_flag();

  /*Create the timer for extns write response*/
  timeoutTimerId = phOsalNfc_Timer_Create();
  if (timeoutTimerId == PH_OSALNFC_TIMER_ID_INVALID) {
    NXPLOG_NCIHAL_E("Invalid Timer Id, Timer Creation failed");
    return NFCSTATUS_FAILED;
  }

  if (phNxpNciHal_init_monitor() == NULL) {
    NXPLOG_NCIHAL_E("Init monitor failed");
    return NFCSTATUS_FAILED;
  }

  CONCURRENCY_LOCK();
  memset(&tOsalConfig, 0x00, sizeof(tOsalConfig));
  memset(&tTmlConfig, 0x00, sizeof(tTmlConfig));

  /*Init binary semaphore for Spi Nfc synchronization*/
  if (0 != sem_init(&nxpncihal_ctrl.syncSpiNfc, 0, 1)) {
    NXPLOG_NCIHAL_E("sem_init() FAiled, errno = 0x%02X", errno);
    goto minCleanAndreturn;
  }

  /* By default HAL status is HAL_STATUS_OPEN */
  nxpncihal_ctrl.halStatus = HAL_STATUS_OPEN;
  nxpncihal_ctrl.is_wait_for_ce_ntf = false;
  nxpncihal_ctrl.hal_boot_mode = boot_mode;

   gpEseAdapt = &EseAdaptation::GetInstance();
   gpEseAdapt->Initialize();

  /*nci version NCI_VERSION_UNKNOWN version by default*/
  nxpncihal_ctrl.nci_info.nci_version = NCI_VERSION_UNKNOWN;

    /*Structure related to set config management*/
  mGetCfg_info = NULL;
  mGetCfg_info = (phNxpNci_getCfg_info_t*) nxp_malloc(sizeof(phNxpNci_getCfg_info_t));
  if (mGetCfg_info == NULL) {
    goto minCleanAndreturn;
  }
  memset(mGetCfg_info, 0x00, sizeof(phNxpNci_getCfg_info_t));

  /* Read the nfc device node name */
  nfc_dev_node = (char*)malloc(max_len * sizeof(char));
  if (nfc_dev_node == NULL) {
    NXPLOG_NCIHAL_E("malloc of nfc_dev_node failed ");
    goto minCleanAndreturn;
  } else if (!GetNxpStrValue(NAME_NXP_NFC_DEV_NODE, nfc_dev_node,
                             max_len * sizeof(char))) {
    NXPLOG_NCIHAL_D(
        "Invalid nfc device node name keeping the default device node "
        "/dev/pn54x");
    strncpy(nfc_dev_node, "/dev/pn54x", strlen("/dev/pn54x") + 1);
  }

  /* Configure hardware link */
  nxpncihal_ctrl.gDrvCfg.nClientId = phDal4Nfc_msgget(0, 0600);
  nxpncihal_ctrl.gDrvCfg.nLinkType = ENUM_LINK_TYPE_I2C; /* For PN54X */
  tTmlConfig.pDevName = (int8_t*)nfc_dev_node;
  tOsalConfig.dwCallbackThreadId = (uintptr_t)nxpncihal_ctrl.gDrvCfg.nClientId;
  tOsalConfig.pLogFile = NULL;
  tTmlConfig.dwGetMsgThreadId = (uintptr_t)nxpncihal_ctrl.gDrvCfg.nClientId;

  /* Initialize TML layer */
  wConfigStatus = phTmlNfc_Init(&tTmlConfig);
  if (wConfigStatus != NFCSTATUS_SUCCESS) {
    NXPLOG_NCIHAL_E("phTmlNfc_Init Failed");
    goto minCleanAndreturn;
  } else {
    if (nfc_dev_node != NULL) {
      free(nfc_dev_node);
      nfc_dev_node = NULL;
    }
  }

  /* Create the client thread */
  ret_val = pthread_create(&nxpncihal_ctrl.client_thread, NULL,
                           phNxpNciHal_client_thread, &nxpncihal_ctrl);
  if (ret_val != 0) {
    NXPLOG_NCIHAL_E("pthread_create failed");
    wConfigStatus = phTmlNfc_Shutdown_CleanUp();
    goto minCleanAndreturn;
  }

  CONCURRENCY_UNLOCK();

  /* call read pending */
  status = phTmlNfc_Read(
      nxpncihal_ctrl.p_cmd_data, NCI_MAX_DATA_LEN,
      (pphTmlNfc_TransactCompletionCb_t)&phNxpNciHal_read_complete, NULL);
  if (status != NFCSTATUS_PENDING) {
    NXPLOG_NCIHAL_E("TML Read status error status = %x", status);
    wConfigStatus = phTmlNfc_Shutdown_CleanUp();
    wConfigStatus = NFCSTATUS_FAILED;
    goto minCleanAndreturn;
  }

init_retry:

  phNxpNciHal_ext_init();

  status = phNxpNciHal_send_ext_cmd(sizeof(cmd_reset_nci), cmd_reset_nci);
  if (status == NFCSTATUS_SUCCESS) {
    sIsForceFwDownloadReqd = false;
  } else if (sIsForceFwDownloadReqd) {
    NXPLOG_NCIHAL_E("%s: Failed after Force FW updated. Exit", __func__);
    goto minCleanAndreturn;
  }

  sIsForceFwDownloadReqd = ((init_retry_cnt >= 3) /*No response for reset/init*/ ||
         ((status != NFCSTATUS_SUCCESS) &&
         (nxpncihal_ctrl.retry_cnt >= MAX_RETRY_COUNT)) /*write failure*/);
  if (sIsForceFwDownloadReqd) {
    NXPLOG_NCIHAL_E("NFCC not coming out from Standby");
    NXPLOG_NCIHAL_E("Trying Force FW download");
    nxpncihal_ctrl.bIsForceFwDwnld = true;
    wConfigStatus = NFCSTATUS_FAILED;
    goto force_download;
  } else if (status != NFCSTATUS_SUCCESS) {
    NXPLOG_NCIHAL_E("NCI_CORE_RESET: Failed");
    if (init_retry_cnt < 3) {
      init_retry_cnt++;
      (void)phNxpNciHal_power_cycle();
      goto init_retry;
    }
  }
  if (nxpncihal_ctrl.nci_info.nci_version == NCI_VERSION_2_0) {
    status = phNxpNciHal_send_ext_cmd(sizeof(cmd_init_nci2_0), cmd_init_nci2_0);
  } else {
    status = phNxpNciHal_send_ext_cmd(sizeof(cmd_init_nci), cmd_init_nci);
    if (status == NFCSTATUS_SUCCESS && (nfcFL.chipType == pn557)) {
      NXPLOG_NCIHAL_D("Chip is in NCI1.0 mode reset the chip to 2.0 mode");
      status = phNxpNciHal_send_ext_cmd(sizeof(cmd_reset_nci), cmd_reset_nci);
      if (status == NFCSTATUS_SUCCESS) {
        status =
            phNxpNciHal_send_ext_cmd(sizeof(cmd_init_nci2_0), cmd_init_nci2_0);
        if (status == NFCSTATUS_SUCCESS) {
          goto init_retry;
        }
      }
    }
  }

  if (status != NFCSTATUS_SUCCESS) {
    NXPLOG_NCIHAL_E("COMMAND Failed");
    if (init_retry_cnt < 3) {
      init_retry_cnt++;
      (void)phNxpNciHal_power_cycle();
      goto init_retry;
    }
  }
  phNxpNciHal_conf_nfc_forum_mode();

  if (!nxpncihal_ctrl.bIsForceFwDwnld) {
    phNxpNciHal_CheckFwRegFlashRequired(&fwFlashReq, &rfUpdateReq);
  } else {
    nxpncihal_ctrl.bIsForceFwDwnld = false;
  }

  if (fwFlashReq) {
    NXPLOG_NCIHAL_D("fwFlashReq = %d", fwFlashReq);
    status = phNxpNciHal_FwDwnld(NFCSTATUS_SUCCESS);
    if (NFCSTATUS_FAILED == status) {
      wConfigStatus = NFCSTATUS_FAILED;
      NXPLOG_NCIHAL_D("FW download Failed");
      goto minCleanAndreturn;
    } else if (NFCSTATUS_REJECTED == status) {
      wConfigStatus = NFCSTATUS_SUCCESS;
      NXPLOG_NCIHAL_D("FW download Rejected. Continuing Nfc Init");
    } else {
      uint8_t p_core_init_rsp_params = 0;
      phNxpNciHal_core_initialized(&p_core_init_rsp_params);
      wConfigStatus = NFCSTATUS_SUCCESS;
      NXPLOG_NCIHAL_D("FW download Success");
    }
  }

  phNxpNciHal_MinOpen_complete(wConfigStatus);
  NXPLOG_NCIHAL_D("phNxpNciHal_MinOpen(): exit");
  return wConfigStatus;

force_download:
  wFwVerRsp = 0;
  status = phNxpNciHal_FwDwnld(NFC_STATUS_NOT_INITIALIZED);
  if (status == NFCSTATUS_SUCCESS) {
    uint8_t p_core_init_rsp_params = 0;
    phNxpNciHal_core_initialized(&p_core_init_rsp_params);
    wConfigStatus = NFCSTATUS_SUCCESS;
  }
  goto init_retry;

minCleanAndreturn:
  phNxpNciHal_Minclose();
  CONCURRENCY_UNLOCK();
  if (nfc_dev_node != NULL) {
    free(nfc_dev_node);
    nfc_dev_node = NULL;
  }
  if (mGetCfg_info != NULL) {
    free(mGetCfg_info);
    mGetCfg_info = NULL;
  }
  nxpncihal_ctrl.halStatus = HAL_STATUS_CLOSE;
  return NFCSTATUS_FAILED;
}

/******************************************************************************
 * Function         phNxpNciHal_open
 *
 * Description      This function is called by libnfc-nci during the
 *                  initialization of the NFCC. It opens the physical connection
 *                  with NFCC (PN54X) and creates required client thread for
 *                  operation.
 *                  After open is complete, status is informed to libnfc-nci
 *                  through callback function.
 *
 * Returns          This function return NFCSTATUS_SUCCES (0) in case of success
 *                  In case of failure returns other failure value.
 *
 ******************************************************************************/
int phNxpNciHal_open(nfc_stack_callback_t* p_cback,
                     nfc_stack_data_callback_t* p_data_cback) {
  AutoThreadMutex a(gsHalOpenCloseLock);
  NFCSTATUS wConfigStatus = NFCSTATUS_SUCCESS;

  if((eseUpdateSpi != ESE_UPDATE_COMPLETED) || (eseUpdateDwp != ESE_UPDATE_COMPLETED))
  {
    ALOGD("%s BLOCK NFC HAL OPEN", __func__);
    if (p_cback != NULL) {
        p_nfc_stack_cback_backup = p_cback;
        (*p_cback)(HAL_NFC_OPEN_CPLT_EVT,
                   HAL_NFC_STATUS_FAILED);
      }
    return NFCSTATUS_FAILED;
  }

  if (nxpncihal_ctrl.hal_boot_mode == NFC_FAST_BOOT_MODE ) {
    NXPLOG_NCIHAL_E(" HAL NFC fast init mode calling min_open %d",
                    nxpncihal_ctrl.hal_boot_mode);
    wConfigStatus = phNxpNciHal_MinInit(p_cback, p_data_cback);
    return wConfigStatus;
  }

  if (nxpncihal_ctrl.halStatus == HAL_STATUS_OPEN) {
    NXPLOG_NCIHAL_D("phNxpNciHal_open already open");
    return NFCSTATUS_SUCCESS;
  }
  nxpncihal_ctrl.p_nfc_stack_cback = p_cback;
  nxpncihal_ctrl.p_nfc_stack_data_cback = p_data_cback;

  if (nxpncihal_ctrl.halStatus == HAL_STATUS_CLOSE) {
    memset(&nxpncihal_ctrl, 0x00, sizeof(nxpncihal_ctrl));
    memset(&nxpprofile_ctrl, 0, sizeof(phNxpNciProfile_Control_t));
    wConfigStatus = phNxpNciHal_MinOpen();
    if (wConfigStatus != NFCSTATUS_SUCCESS) {
      NXPLOG_NCIHAL_E("phNxpNciHal_MinOpen failed");
      goto clean_and_return;
    }
  }
  nxpncihal_ctrl.p_nfc_stack_cback = p_cback;
  nxpncihal_ctrl.p_nfc_stack_data_cback = p_data_cback;
   /*else its already in MIN_OPEN state. continue with rest of functionality*/
  NXPLOG_NCIHAL_D("phNxpNciHal_open Done.");
  /* Call open complete */
  phNxpNciHal_open_complete(wConfigStatus);
  NXPLOG_NCIHAL_D("phNxpNciHal_open Exit.");

  return wConfigStatus;

clean_and_return:
  /* Report error status */
  if (p_cback != NULL) {
    (*p_cback)(HAL_NFC_OPEN_CPLT_EVT, HAL_NFC_STATUS_FAILED);
  }
  nxpncihal_ctrl.p_nfc_stack_cback = NULL;
  nxpncihal_ctrl.p_nfc_stack_data_cback = NULL;
  phNxpNciHal_cleanup_monitor();
  nxpncihal_ctrl.halStatus = HAL_STATUS_CLOSE;
  return NFCSTATUS_FAILED;
}

/******************************************************************************
 * Function         phNxpNciHal_fw_mw_check
 *
 * Description      This function inform the status of phNxpNciHal_fw_mw_check
 *                  function to libnfc-nci.
 *
 * Returns          int.
 *
 ******************************************************************************/
static int phNxpNciHal_fw_mw_ver_check() {
    NFCSTATUS status = NFCSTATUS_FAILED;
    if (((nfcFL.chipType == pn557)||(nfcFL.chipType == pn81T)) &&
           (rom_version == FW_MOBILE_ROM_VERSION_PN557)) {
      status = NFCSTATUS_SUCCESS;
    } else if (((nfcFL.chipType == pn553)||(nfcFL.chipType == pn80T)) &&
           (rom_version == FW_MOBILE_ROM_VERSION_PN553)) {
        status = NFCSTATUS_SUCCESS;
    } else if (((nfcFL.chipType == pn551)||(nfcFL.chipType == pn67T)) &&
            (rom_version == FW_MOBILE_ROM_VERSION_PN551)) {
        status = NFCSTATUS_SUCCESS;
    } else if (((nfcFL.chipType == pn548C2)||(nfcFL.chipType == pn66T)) &&
            (rom_version == FW_MOBILE_ROM_VERSION_PN551)) {
        status = NFCSTATUS_SUCCESS;
    } else if (((nfcFL.chipType == pn547C2)||(nfcFL.chipType == pn65T)) &&
            (rom_version == FW_MOBILE_ROM_VERSION_PN547C2)) {
        status = NFCSTATUS_SUCCESS;
    }
    return status;
}

/******************************************************************************
 * Function         phNxpNciHal_MinOpen_complete
 *
 * Description      This function updates the status of phNxpNciHal_MinOpen_complete
 *                  to halstatus.
 *
 * Returns          void.
 *
 ******************************************************************************/
static void phNxpNciHal_MinOpen_complete(NFCSTATUS status) {

  if (status == NFCSTATUS_SUCCESS) {
    nxpncihal_ctrl.halStatus = HAL_STATUS_MIN_OPEN;
  }

  return;
}

/******************************************************************************
 * Function         phNxpNciHal_open_complete
 *
 * Description      This function inform the status of phNxpNciHal_open
 *                  function to libnfc-nci.
 *
 * Returns          void.
 *
 ******************************************************************************/
static void phNxpNciHal_open_complete(NFCSTATUS status) {
  static phLibNfc_Message_t msg;

  if (status == NFCSTATUS_SUCCESS) {
    msg.eMsgType = NCI_HAL_OPEN_CPLT_MSG;
    nxpncihal_ctrl.hal_open_status = true;
    nxpncihal_ctrl.halStatus = HAL_STATUS_OPEN;
  } else {
    msg.eMsgType = NCI_HAL_ERROR_MSG;
  }

  msg.pMsgData = NULL;
  msg.Size = 0;
  phTmlNfc_DeferredCall(gpphTmlNfc_Context->dwCallbackThreadId,
                        (phLibNfc_Message_t*)&msg);

  return;
}

/******************************************************************************
 * Function         phNxpNciHal_write
 *
 * Description      This function write the data to NFCC through physical
 *                  interface (e.g. I2C) using the PN54X driver interface.
 *                  Before sending the data to NFCC, phNxpNciHal_write_ext
 *                  is called to check if there is any extension processing
 *                  is required for the NCI packet being sent out.
 *
 * Returns          It returns number of bytes successfully written to NFCC.
 *
 ******************************************************************************/
int phNxpNciHal_write(uint16_t data_len, const uint8_t* p_data) {
  if (bDisableLegacyMfcExtns && bEnableMfcExtns && p_data[0] == 0x00) {
    return NxpMfcReaderInstance.Write(data_len, p_data);
  }
  return phNxpNciHal_write_internal(data_len, p_data);
}

/******************************************************************************
 * Function         phNxpNciHal_write_internal
 *
 * Description      This function write the data to NFCC through physical
 *                  interface (e.g. I2C) using the PN54X driver interface.
 *                  Before sending the data to NFCC, phNxpNciHal_write_ext
 *                  is called to check if there is any extension processing
 *                  is required for the NCI packet being sent out.
 *
 * Returns          It returns number of bytes successfully written to NFCC.
 *
 ******************************************************************************/
int phNxpNciHal_write_internal(uint16_t data_len, const uint8_t* p_data) {
  NFCSTATUS status = NFCSTATUS_FAILED;
  static phLibNfc_Message_t msg;

  CONCURRENCY_LOCK();

  if (nxpncihal_ctrl.halStatus != HAL_STATUS_OPEN) {
    CONCURRENCY_UNLOCK();
    return NFCSTATUS_FAILED;
  }

  /* Create local copy of cmd_data */
  nxpncihal_ctrl.cmd_len = data_len;
  if (nxpncihal_ctrl.cmd_len + MAX_NXP_HAL_EXTN_BYTES > NCI_MAX_DATA_LEN) {
    NXPLOG_NCIHAL_D("cmd_len exceeds limit NCI_MAX_DATA_LEN");
    goto clean_and_return;
  }
  memcpy(nxpncihal_ctrl.p_cmd_data, p_data, data_len);
#ifdef P2P_PRIO_LOGIC_HAL_IMP
  /* Specific logic to block RF disable when P2P priority logic is busy */
  if (p_data[0] == 0x21 && p_data[1] == 0x06 && p_data[2] == 0x01 &&
      EnableP2P_PrioLogic == true) {
    NXPLOG_NCIHAL_D("P2P priority logic busy: Disable it.");
    phNxpNciHal_clean_P2P_Prio();
  }
#endif

  /* Check for NXP ext before sending write */
  status =
      phNxpNciHal_write_ext(&nxpncihal_ctrl.cmd_len, nxpncihal_ctrl.p_cmd_data,
                            &nxpncihal_ctrl.rsp_len, nxpncihal_ctrl.p_rsp_data);
  if (status != NFCSTATUS_SUCCESS) {
    /* Do not send packet to PN54X, send response directly */
    msg.eMsgType = NCI_HAL_RX_MSG;
    msg.pMsgData = NULL;
    msg.Size = 0;

    phTmlNfc_DeferredCall(gpphTmlNfc_Context->dwCallbackThreadId,
                          (phLibNfc_Message_t*)&msg);
    goto clean_and_return;
  }

  data_len = phNxpNciHal_write_unlocked(nxpncihal_ctrl.cmd_len,
                                        nxpncihal_ctrl.p_cmd_data);

  if (icode_send_eof == 1) {
    usleep(10000);
    icode_send_eof = 2;
    status = phNxpNciHal_send_ext_cmd(3, cmd_icode_eof);
    if (status != NFCSTATUS_SUCCESS) {
       NXPLOG_NCIHAL_E("ICODE end of frame command failed");
    }
  }

clean_and_return:
  CONCURRENCY_UNLOCK();
  /* No data written */
  return data_len;
}

/******************************************************************************
 * Function         phNxpNciHal_write_unlocked
 *
 * Description      This is the actual function which is being called by
 *                  phNxpNciHal_write. This function writes the data to NFCC.
 *                  It waits till write callback provide the result of write
 *                  process.
 *
 * Returns          It returns number of bytes successfully written to NFCC.
 *
 ******************************************************************************/
int phNxpNciHal_write_unlocked(uint16_t data_len, const uint8_t* p_data) {
  NFCSTATUS status = NFCSTATUS_INVALID_PARAMETER;
  phNxpNciHal_Sem_t cb_data;
  nxpncihal_ctrl.retry_cnt = 0;
  static uint8_t reset_ntf[] = {0x60, 0x00, 0x06, 0xA0, 0x00,
                                0xC7, 0xD4, 0x00, 0x00};

  /* Create the local semaphore */
  if (phNxpNciHal_init_cb_data(&cb_data, NULL) != NFCSTATUS_SUCCESS) {
    NXPLOG_NCIHAL_D("phNxpNciHal_write_unlocked Create cb data failed");
    data_len = 0;
    goto clean_and_return;
  }

  /* Create local copy of cmd_data */
  memcpy(nxpncihal_ctrl.p_cmd_data, p_data, data_len);
  nxpncihal_ctrl.cmd_len = data_len;


  /* check for write synchronyztion */
  if(phNxpNciHal_check_ncicmd_write_window(nxpncihal_ctrl.cmd_len,
                         nxpncihal_ctrl.p_cmd_data) != NFCSTATUS_SUCCESS) {
    NXPLOG_NCIHAL_D("phNxpNciHal_write_unlocked write synchronization failed");
    data_len = 0;
    goto clean_and_return;
  }

retry:

  data_len = nxpncihal_ctrl.cmd_len;

  status = phTmlNfc_Write(
      (uint8_t*)nxpncihal_ctrl.p_cmd_data, (uint16_t)nxpncihal_ctrl.cmd_len,
      (pphTmlNfc_TransactCompletionCb_t)&phNxpNciHal_write_complete,
      (void*)&cb_data);
  if (status != NFCSTATUS_PENDING) {
    NXPLOG_NCIHAL_E("write_unlocked status error");
    data_len = 0;
    goto clean_and_return;
  }

  /* Wait for callback response */
  if (SEM_WAIT(cb_data)) {
    NXPLOG_NCIHAL_E("write_unlocked semaphore error");
    data_len = 0;
    goto clean_and_return;
  }

  if (cb_data.status != NFCSTATUS_SUCCESS) {
    data_len = 0;
    if (nxpncihal_ctrl.retry_cnt++ < MAX_RETRY_COUNT) {
      NXPLOG_NCIHAL_D(
          "write_unlocked failed - PN54X Maybe in Standby Mode - Retry");
      if(nfcFL.nfccFL._NFCC_I2C_READ_WRITE_IMPROVEMENT) {
          /* 5ms delay to give NFCC wake up delay */
          usleep(5000);
      } else {
          /* 10ms delay to give NFCC wake up delay */
          usleep(1000 * 10);
}
      goto retry;
    } else {
      NXPLOG_NCIHAL_E(
          "write_unlocked failed - PN54X Maybe in Standby Mode (max count = "
          "0x%x)",
          nxpncihal_ctrl.retry_cnt);
      sem_post(&(nxpncihal_ctrl.syncSpiNfc));

      status = phTmlNfc_IoCtl(phTmlNfc_e_ResetDevice);

      if (NFCSTATUS_SUCCESS == status) {
        NXPLOG_NCIHAL_D("PN54X Reset - SUCCESS\n");
      } else {
        NXPLOG_NCIHAL_D("PN54X Reset - FAILED\n");
      }
      if (nxpncihal_ctrl.p_nfc_stack_data_cback != NULL &&
          nxpncihal_ctrl.hal_open_status == true) {
        if (nxpncihal_ctrl.p_rx_data != NULL) {
          NXPLOG_NCIHAL_D(
              "Send the Core Reset NTF to upper layer, which will trigger the "
              "recovery\n");
          // Send the Core Reset NTF to upper layer, which will trigger the
          // recovery.
          nxpncihal_ctrl.rx_data_len = sizeof(reset_ntf);
          memcpy(nxpncihal_ctrl.p_rx_data, reset_ntf, sizeof(reset_ntf));
          (*nxpncihal_ctrl.p_nfc_stack_data_cback)(nxpncihal_ctrl.rx_data_len,
                                                   nxpncihal_ctrl.p_rx_data);
        } else {
          (*nxpncihal_ctrl.p_nfc_stack_data_cback)(0x00, NULL);
        }
        write_unlocked_status = NFCSTATUS_FAILED;
      }
    }
  } else {
    write_unlocked_status = NFCSTATUS_SUCCESS;
  }

clean_and_return:
  phNxpNciHal_cleanup_cb_data(&cb_data);
  return data_len;
}

/******************************************************************************
 * Function         phNxpNciHal_write_complete
 *
 * Description      This function handles write callback.
 *
 * Returns          void.
 *
 ******************************************************************************/
static void phNxpNciHal_write_complete(void* pContext,
                                       phTmlNfc_TransactInfo_t* pInfo) {
  phNxpNciHal_Sem_t* p_cb_data = (phNxpNciHal_Sem_t*)pContext;

  if (pInfo->wStatus == NFCSTATUS_SUCCESS) {
    NXPLOG_NCIHAL_D("write successful status = 0x%x", pInfo->wStatus);
  } else {
    NXPLOG_NCIHAL_E("write error status = 0x%x", pInfo->wStatus);
  }

  p_cb_data->status = pInfo->wStatus;

  SEM_POST(p_cb_data);

  return;
}

/******************************************************************************
 * Function         phNxpNciHal_read_complete
 *
 * Description      This function is called whenever there is an NCI packet
 *                  received from NFCC. It could be RSP or NTF packet. This
 *                  function provide the received NCI packet to libnfc-nci
 *                  using data callback of libnfc-nci.
 *                  There is a pending read called from each
 *                  phNxpNciHal_read_complete so each a packet received from
 *                  NFCC can be provide to libnfc-nci.
 *
 * Returns          void.
 *
 ******************************************************************************/
static void phNxpNciHal_read_complete(void* pContext,
                                      phTmlNfc_TransactInfo_t* pInfo) {
  NFCSTATUS status = NFCSTATUS_FAILED;
  UNUSED(pContext);
  int sem_val;
  if (nxpncihal_ctrl.read_retry_cnt == 1) {
    nxpncihal_ctrl.read_retry_cnt = 0;
  }
  if (nfcFL.nfccFL._NFCC_I2C_READ_WRITE_IMPROVEMENT &&
          (pInfo->wStatus == NFCSTATUS_READ_FAILED)) {
      if (nxpncihal_ctrl.p_nfc_stack_cback != NULL) {
          read_failed_disable_nfc = true;
          /* Send the event */
          (*nxpncihal_ctrl.p_nfc_stack_cback)(HAL_NFC_ERROR_EVT,
                  HAL_NFC_STATUS_ERR_CMD_TIMEOUT);
      }
      return;
  }

  if (pInfo->wStatus == NFCSTATUS_SUCCESS) {
    NXPLOG_NCIHAL_D("read successful status = 0x%x", pInfo->wStatus);

    sem_getvalue(&(nxpncihal_ctrl.syncSpiNfc), &sem_val);
    if (((pInfo->pBuff[0] & NCI_MT_MASK) == NCI_MT_RSP) && sem_val == 0) {
      sem_post(&(nxpncihal_ctrl.syncSpiNfc));
    }
    nxpncihal_ctrl.p_rx_data = pInfo->pBuff;
    nxpncihal_ctrl.rx_data_len = pInfo->wLength;
    /*Check the Omapi command response and store in dedicated buffer to solve
     * sync issue*/
    if (pInfo->pBuff[0] == 0x4F && pInfo->pBuff[1] == 0x01 &&
        pInfo->pBuff[2] == 0x01) {
      nxpncihal_ctrl.p_rx_ese_data = pInfo->pBuff;
      nxpncihal_ctrl.rx_ese_data_len = pInfo->wLength;
      SEM_POST(&(nxpncihal_ctrl.ext_cb_data));
    } else {
      nxpncihal_ctrl.p_rx_data = pInfo->pBuff;
      nxpncihal_ctrl.rx_data_len = pInfo->wLength;
      status = phNxpNciHal_process_ext_rsp(nxpncihal_ctrl.p_rx_data,
                                           &nxpncihal_ctrl.rx_data_len);
    }

    phNxpNciHal_print_res_status(pInfo->pBuff, &pInfo->wLength);

    /* Notification Checking */
    if (nfcFL.nfccFL._NFCC_FORCE_NCI1_0_INIT && ((nxpncihal_ctrl.hal_ext_enabled == 1) &&
        (nxpncihal_ctrl.p_rx_data[0x00] == 0x60) &&
        (nxpncihal_ctrl.p_rx_data[0x03] == 0x02))) {
      nxpncihal_ctrl.ext_cb_data.status = NFCSTATUS_SUCCESS;
      SEM_POST(&(nxpncihal_ctrl.ext_cb_data));
    } else if (nxpncihal_ctrl.hal_ext_enabled == TRUE && /* Check if response should go to hal module only */
            ((nxpncihal_ctrl.p_rx_data[0x00] & NCI_MT_MASK) == NCI_MT_RSP ||
             ((icode_detected == true) && (icode_send_eof == 3)))) {
      if (status == NFCSTATUS_FAILED) {
        NXPLOG_NCIHAL_D("enter into NFCC init recovery");
        nxpncihal_ctrl.ext_cb_data.status = status;
      }

      /* Unlock semaphore */
      SEM_POST(&(nxpncihal_ctrl.ext_cb_data));
    }
     //Notification Checking
    else if((nxpncihal_ctrl.hal_ext_enabled == TRUE)    &&
            ((nxpncihal_ctrl.p_rx_data[0x00]  & NCI_MT_MASK) == NCI_MT_NTF) &&
            (nxpncihal_ctrl.nci_info.wait_for_ntf == TRUE)) {
        /* Unlock semaphore waiting for only  ntf*/
      SEM_POST(&(nxpncihal_ctrl.ext_cb_data));
      nxpncihal_ctrl.nci_info.wait_for_ntf = FALSE;
    } else if (bDisableLegacyMfcExtns && !sendRspToUpperLayer &&
               (nxpncihal_ctrl.p_rx_data[0x00] == 0x00)) {
      sendRspToUpperLayer = true;
      NFCSTATUS mfcRspStatus = NxpMfcReaderInstance.CheckMfcResponse(
          nxpncihal_ctrl.p_rx_data, nxpncihal_ctrl.rx_data_len);
      NXPLOG_NCIHAL_D("Mfc Response Status = 0x%x", mfcRspStatus);
      SEM_POST(&(nxpncihal_ctrl.ext_cb_data));
    }
    /* Read successful send the event to higher layer */
    else if ((nxpncihal_ctrl.p_nfc_stack_data_cback != NULL) &&
             (status == NFCSTATUS_SUCCESS)) {
      (*nxpncihal_ctrl.p_nfc_stack_data_cback)(nxpncihal_ctrl.rx_data_len,
                                               nxpncihal_ctrl.p_rx_data);
      /* sending NFCEE_RF_DISC NTF to upper layer if eSE DISCT_NTF with
       * connected & enabled. */
      if ((nfcFL.chipType == pn557) && nxpncihal_ctrl.p_rx_data[0] == 0x62 &&
          nxpncihal_ctrl.p_rx_data[1] == 0x00 &&
          nxpncihal_ctrl.p_rx_data[3] == 0xC0 &&
          nxpncihal_ctrl.p_rx_data[4] == 0x00) {
        uint8_t nfcee_notifiations[3][9] = {
            {0x61, 0x0A, 0x06, 0x01, 0x00, 0x03, 0xC0, 0x80, 0x04},
            {0x61, 0x0A, 0x06, 0x01, 0x00, 0x03, 0xC0, 0x81, 0x04},
            {0x61, 0x0A, 0x06, 0x01, 0x00, 0x03, 0xC0, 0x82, 0x03},
        };

        for (int i = 0; i < 3; i++) {
          (*nxpncihal_ctrl.p_nfc_stack_data_cback)(
              sizeof(nfcee_notifiations[i]), nfcee_notifiations[i]);
        }
      }
    }
  } else {
    NXPLOG_NCIHAL_E("read error status = 0x%x", pInfo->wStatus);
  }

  if (nxpncihal_ctrl.halStatus == HAL_STATUS_CLOSE &&
    nxpncihal_ctrl.nci_info.wait_for_ntf == FALSE) {
    NXPLOG_NCIHAL_D(" Ignoring read , HAL close triggered");
    return;
  }
  /* Read again because read must be pending always.*/
  status = phTmlNfc_Read(
      Rx_data, NCI_MAX_DATA_LEN,
      (pphTmlNfc_TransactCompletionCb_t)&phNxpNciHal_read_complete, NULL);
  if (status != NFCSTATUS_PENDING) {
    NXPLOG_NCIHAL_E("read status error status = %x", status);
    /* TODO: Not sure how to handle this ? */
  }

  return;
}

/******************************************************************************
 * Function         phNxpNciHal_core_initialized
 *
 * Description      This function is called by libnfc-nci after successful open
 *                  of NFCC. All proprietary setting for PN54X are done here.
 *                  After completion of proprietary settings notification is
 *                  provided to libnfc-nci through callback function.
 *
 * Returns          Always returns NFCSTATUS_SUCCESS (0).
 *
 ******************************************************************************/
int phNxpNciHal_core_initialized(uint8_t* p_core_init_rsp_params) {
  NFCSTATUS status = NFCSTATUS_SUCCESS;
  uint8_t* buffer = NULL;
  uint8_t isfound = false;
  uint8_t setConfigAlways = false;
  char valueStr[PROPERTY_VALUE_MAX] = {0};
  bool persist_hci_network_reset_req =false;
  bool persist_core_reset_debug_info_req = false;
  static uint8_t retry_core_init_cnt = 0;
  static uint8_t p2p_listen_mode_routing_cmd[] = {0x21, 0x01, 0x07, 0x00, 0x01,
                                                  0x01, 0x03, 0x00, 0x01, 0x05};
  uint8_t swp_full_pwr_mode_on_cmd[] = {0x20, 0x02, 0x05, 0x01,
                                        0xA0, 0xF1, 0x01, 0x01};
  static uint8_t cmd_ven_pulld_enable_nci[] = {0x20, 0x02, 0x05, 0x01,
                                     0xA0, 0x07, 0x01, 0x03};
  static uint8_t swp_switch_timeout_cmd[] = {0x20, 0x02, 0x06, 0x01, 0xA0,
                                             0xF3, 0x02, 0x00, 0x00};
  static uint8_t cmd_init_nci[] = {0x20, 0x01, 0x00};
  static uint8_t cmd_reset_nci[] = {0x20, 0x00, 0x01, 0x00};
  static uint8_t cmd_init_nci2_0[] = {0x20,0x01,0x02,0x00,0x00};
  static uint8_t cmd_get_cfg_dbg_info[] = {0x20, 0x03, 0x4, 0xA0, 0x1B, 0xA0, 0x27};
  /*fix to disable mifare clt emulation for jcop v4.1*/
  static uint8_t cmd_mf_clt_jcop_cfg[] = {0x20, 0x02, 0x05, 0x01,
                                          0xA0, 0x6B, 0x01, 0x00};

  config_success = true;
  long bufflen = 260;
  long retlen = 0;
  unsigned long num = 0;
  static uint8_t  init_param;
  init_param = *p_core_init_rsp_params;
  phNxpNci_EEPROM_info_t mEEPROM_info = {.request_mode = 0};
  static uint8_t android_l_aid_matching_mode_on_cmd[] = {
      0x20, 0x02, 0x05, 0x01, 0xA0, 0x91, 0x01, 0x01};

  int len = property_get("persist.vendor.nfc.hci_network_reset_req", valueStr, "false");
  if (len > 0) {
    persist_hci_network_reset_req = (len == 4 && (memcmp(valueStr, "true", len) == 0)) ? true : false;
  }
  len = property_get("persist.vendor.nfc.core_reset_debug_info", valueStr, "false");
    if (len > 0) {
    persist_core_reset_debug_info_req = (len == 4 && (memcmp(valueStr, "true", len) == 0)) ? true : false;
  }

  /*initialize dummy FW recovery variables*/
  if(nfcFL.chipType != pn547C2) {
      gRecFwRetryCount = 0;
      gRecFWDwnld = false;
  }
  if (nxpncihal_ctrl.halStatus != HAL_STATUS_OPEN) {
    return NFCSTATUS_FAILED;
  }

  NXPLOG_NCIHAL_D("phNxpNciHal_core_initialized::p_core_init_rsp_params : %d", *p_core_init_rsp_params);

  /*MW recovery -- begins*/
  if ((*p_core_init_rsp_params > 0) && (*p_core_init_rsp_params < 4)) {
  retry_core_init:
    *p_core_init_rsp_params = init_param;
    config_access = false;
    if (mGetCfg_info != NULL) {
      mGetCfg_info->isGetcfg = false;
    }
    if (buffer != NULL) {
      free(buffer);
      buffer = NULL;
    }
    if (retry_core_init_cnt > 3) {
        if (nfcFL.nfccFL._NFCC_I2C_READ_WRITE_IMPROVEMENT &&
                (nxpncihal_ctrl.p_nfc_stack_cback != NULL)) {
            NXPLOG_NCIHAL_D("Posting Core Init Failed\n");
            read_failed_disable_nfc = true;
            (*nxpncihal_ctrl.p_nfc_stack_cback)(HAL_NFC_ERROR_EVT,
                    HAL_NFC_STATUS_ERR_CMD_TIMEOUT);
        }
        return NFCSTATUS_FAILED;
    }

    int sem_val;
    sem_getvalue(&(nxpncihal_ctrl.syncSpiNfc), &sem_val);
    if (sem_val == 0) {
      sem_post(&(nxpncihal_ctrl.syncSpiNfc));
    }
    status = phTmlNfc_IoCtl(phTmlNfc_e_ResetDevice);
    if (NFCSTATUS_SUCCESS == status) {
      NXPLOG_NCIHAL_D("PN54X Reset - SUCCESS\n");
    } else {
      NXPLOG_NCIHAL_D("PN54X Reset - FAILED\n");
    }

    if(nfcFL.nfccFL._NFCC_FORCE_NCI1_0_INIT) {
        status = phNxpNciHal_send_ext_cmd_ntf(sizeof(cmd_reset_nci), cmd_reset_nci);
    }
    else {
        status = phNxpNciHal_send_ext_cmd(sizeof(cmd_reset_nci), cmd_reset_nci);
    }

    if ((status != NFCSTATUS_SUCCESS) &&
        (nxpncihal_ctrl.retry_cnt >= MAX_RETRY_COUNT)) {
      NXPLOG_NCIHAL_E(
          "NFCC not coming out from Standby Max retry count reached");
      NXP_NCI_HAL_CORE_INIT_RECOVER(retry_core_init_cnt, retry_core_init);
    } else if (status != NFCSTATUS_SUCCESS) {
      NXPLOG_NCIHAL_E("NCI_CORE_RESET: Failed");
      NXP_NCI_HAL_CORE_INIT_RECOVER(retry_core_init_cnt, retry_core_init);
    }

    if (*p_core_init_rsp_params == 2) {
      NXPLOG_NCIHAL_E(" Last command is CORE_RESET!!");
      goto invoke_callback;
    }

    if (nxpncihal_ctrl.nci_info.nci_version == NCI_VERSION_2_0) {
      status = phNxpNciHal_send_ext_cmd(sizeof(cmd_init_nci2_0), cmd_init_nci2_0);
    } else {
      status = phNxpNciHal_send_ext_cmd(sizeof(cmd_init_nci), cmd_init_nci);
    }
    if (status != NFCSTATUS_SUCCESS) {
      NXPLOG_NCIHAL_E("NCI_CORE_INIT : Failed");
      NXP_NCI_HAL_CORE_INIT_RECOVER(retry_core_init_cnt, retry_core_init);
    }

    if (*p_core_init_rsp_params == 3) {
      NXPLOG_NCIHAL_E(" Last command is CORE_INIT!!");
      goto invoke_callback;
    }
  }

  /*MW recovery --ended*/

  buffer = (uint8_t*)nxp_malloc(bufflen * sizeof(uint8_t));
  if (NULL == buffer) {
    return NFCSTATUS_FAILED;
  }

  config_access = true;
  retlen = 0;
  isfound = GetNxpByteArrayValue(NAME_NXP_ACT_PROP_EXTN, (char*)buffer, bufflen,
                                 &retlen);
  if (retlen > 0) {
    /* NXP ACT Proprietary Ext */
    status = phNxpNciHal_send_ext_cmd(retlen, buffer);
    if (status != NFCSTATUS_SUCCESS) {
      NXPLOG_NCIHAL_E("NXP ACT Proprietary Ext failed");
      NXP_NCI_HAL_CORE_INIT_RECOVER(retry_core_init_cnt, retry_core_init);
    }
  }

  retlen = 0;
  isfound = GetNxpByteArrayValue(NAME_NXP_CORE_STANDBY, (char*)buffer, bufflen,
                                 &retlen);
  if (retlen > 0) {
    /* NXP ACT Proprietary Ext */
    status = phNxpNciHal_send_ext_cmd(retlen, buffer);
    if (status != NFCSTATUS_SUCCESS) {
      NXPLOG_NCIHAL_E("NXP Standby Proprietary Ext failed");
      NXP_NCI_HAL_CORE_INIT_RECOVER(retry_core_init_cnt, retry_core_init);
    }
  }

  status = phNxpNciHal_send_ext_cmd(sizeof(cmd_ven_pulld_enable_nci),
                                    cmd_ven_pulld_enable_nci);
  if (status != NFCSTATUS_SUCCESS) {
    NXPLOG_NCIHAL_E("cmd_ven_pulld_enable_nci: Failed");
    retry_core_init_cnt++;
    goto retry_core_init;
  }

  retlen = 0;
  if ((nfcFL.chipType == pn553) || (nfcFL.chipType == pn557)) {
    if (GetNxpNumValue(NAME_NXP_MF_CLT_JCOP_CFG, (void *)&retlen,
                       sizeof(retlen))) {
      cmd_mf_clt_jcop_cfg[7] = 0x01 & retlen;
      status = phNxpNciHal_send_ext_cmd(sizeof(cmd_mf_clt_jcop_cfg),
                                        cmd_mf_clt_jcop_cfg);
      if (status != NFCSTATUS_SUCCESS) {
        NXPLOG_NCIHAL_E("cmd_mf_clt_jcop_cfg: Failed");
        retry_core_init_cnt++;
        goto retry_core_init;
      }
    }
  }

  if(nfcFL.eseFL._ESE_SVDD_SYNC) {
      if (GetNxpNumValue(NAME_NXP_SVDD_SYNC_OFF_DELAY, (void*)&gSvddSyncOff_Delay,
              sizeof(gSvddSyncOff_Delay))) {
          if (gSvddSyncOff_Delay > 20) gSvddSyncOff_Delay = 10;
          NXPLOG_NCIHAL_E("NAME_NXP_SVDD_SYNC_OFF_DELAY success value = %d",
                  gSvddSyncOff_Delay);
      } else {
          NXPLOG_NCIHAL_E("NAME_NXP_SVDD_SYNC_OFF_DELAY failed");
          gSvddSyncOff_Delay = 10;
      }
  }
  config_access = false;
  if(nfcFL.eseFL._EXCLUDE_NV_MEM_DEPENDENCY == false) {
    phNxpNciHal_reset_nfcee_session(false);
  }

  if((nfcFL.chipType != pn547C2) && (nfcFL.chipType != pn557) &&
      nfcFL.nfccFL._NFCC_ROUTING_BLOCK_BIT_PROP) {
      if (isNxpConfigModified() || (fw_download_success == 0x01)) {
          uint8_t value;
          retlen = 0;
          if (GetNxpNumValue(NAME_NXP_PROP_BLACKLIST_ROUTING,
                  (void*)&retlen, sizeof(retlen))) {
              if (retlen == 0x00 || retlen == 0x01) {
                  value = (uint8_t)retlen;
                  mEEPROM_info.buffer = &value;
                  mEEPROM_info.bufflen = sizeof(value);
                  mEEPROM_info.request_type = EEPROM_PROP_ROUTING;
                  mEEPROM_info.request_mode = SET_EEPROM_DATA;
                  status = request_EEPROM(&mEEPROM_info);
                  if (status != NFCSTATUS_SUCCESS) {
                    NXPLOG_NCIHAL_E(
                      "request EEPROM settings for EEPROM_PROP_ROUTING Failed");
                  }
              }
          }
      }
}

  if((nfcFL.chipType != pn547C2) && (nfcFL.eseFL._ESE_DUAL_MODE_PRIO_SCHEME ==
          nfcFL.eseFL._ESE_WIRED_MODE_RESUME)) {
      uint8_t resume_timeout_buf[NXP_WIREDMODE_RESUME_TIMEOUT_LEN];
      mEEPROM_info.request_mode = GET_EEPROM_DATA;
      NXPLOG_NCIHAL_D("Timeout value");
      if (isNxpConfigModified() || (fw_download_success == 0x01)) {
          NXPLOG_NCIHAL_D("Timeout value - 1");
          if (GetNxpByteArrayValue(NAME_NXP_WIREDMODE_RESUME_TIMEOUT, (char*)buffer,
                  bufflen, &retlen)) {
              NXPLOG_NCIHAL_D("Time out value %x %x %x %x retlen=%ld", buffer[0],
                      buffer[1], buffer[2], buffer[3], retlen);
              if (retlen >= NXP_WIREDMODE_RESUME_TIMEOUT_LEN) {
                  memcpy(&resume_timeout_buf, buffer, NXP_STAG_TIMEOUT_BUF_LEN);
                  mEEPROM_info.request_mode = SET_EEPROM_DATA;
              }
          }
      }
      mEEPROM_info.buffer = resume_timeout_buf;
      mEEPROM_info.bufflen = sizeof(resume_timeout_buf);
      mEEPROM_info.request_type = EEPROM_WIREDMODE_RESUME_TIMEOUT;
      (void)request_EEPROM(&mEEPROM_info);
  }

#if (NXP_EXTNS == TRUE)
  if(nfcFL.eseFL._ESE_POWER_MODE &&
    (isNxpConfigModified() || (fw_download_success == 0x01)))
  {
    uint8_t value;
    retlen = 0;
    if (GetNxpNumValue(NAME_NXP_ESE_POWER_DH_CONTROL, (void*)&retlen,
                       sizeof(retlen))) {
      if (retlen == 0x01 || retlen == 0x02) {
        value = (uint8_t)retlen;
        if (value == 2) value = 0;
        mEEPROM_info.buffer = &value;
        mEEPROM_info.bufflen = sizeof(value);
        mEEPROM_info.request_type = EEPROM_ESE_SVDD_POWER;
        mEEPROM_info.request_mode = SET_EEPROM_DATA;
        status = request_EEPROM(&mEEPROM_info);
        if (status != NFCSTATUS_SUCCESS) {
          NXPLOG_NCIHAL_E(
              "request EEPROM settings for EEPROM_ESE_SVDD_POWER Failed");
        }
      }
      if (retlen == 0x01) {
        retlen = 0;
        value = 0x40;
        mEEPROM_info.buffer = &value;
        mEEPROM_info.bufflen = sizeof(value);
        mEEPROM_info.request_type = EEPROM_ESE_POWER_EXT_PMU;
        mEEPROM_info.request_mode = SET_EEPROM_DATA;
        phTmlNfc_IoCtl(phTmlNfc_e_SetLegacyPowerScheme);
        status = request_EEPROM(&mEEPROM_info);
        if (status != NFCSTATUS_SUCCESS) {
          NXPLOG_NCIHAL_E("request EEPROM settings for ESE_POWER_EXT_PMU Failed");
        }
      } else if (retlen == 0x02) {
        retlen = 0;
        value = 0;
        if (GetNxpNumValue(NAME_NXP_ESE_POWER_EXT_PMU, (void*)&retlen,
                           sizeof(retlen))) {
          if (retlen == 0x01 || retlen == 0x02) {
            value = (uint8_t)retlen;
            if (value == 1) {
              value = 0x50;
            } else {
              value = 0x48;
            }
            phTmlNfc_IoCtl(phTmlNfc_e_SetExtPMUPowerScheme);
            mEEPROM_info.buffer = &value;
            mEEPROM_info.bufflen = sizeof(value);
            mEEPROM_info.request_type = EEPROM_ESE_POWER_EXT_PMU;
            mEEPROM_info.request_mode = SET_EEPROM_DATA;
            status = request_EEPROM(&mEEPROM_info);
            if (status != NFCSTATUS_SUCCESS) {
              NXPLOG_NCIHAL_E("request EEPROM settings for ESE_POWER_EXT_PMU Failed");
            }
          }
        }
      }
    }
    retlen = 0;
    value = (uint8_t)retlen;
    mEEPROM_info.bufflen = sizeof(value);
    mEEPROM_info.request_type = EEPROM_NDEF_INTF_CFG;
    mEEPROM_info.request_mode = SET_EEPROM_DATA;
    if(GetNxpNumValue(NAME_WTAG_SUPPORT, (void*)&retlen, sizeof(retlen))) {
      if(retlen == 0x01) {
        value = 0x03; //Set T4T from NFCC for W_TAG
        mEEPROM_info.buffer = &value;
      }
    } else {
      mEEPROM_info.buffer = &value;
    }
    status = request_EEPROM(&mEEPROM_info);
    if (status != NFCSTATUS_SUCCESS) {
      NXPLOG_NCIHAL_E("request EEPROM settings for NDEF_INTF_CFG Failed");
    }
  }
#endif
  if(persist_core_reset_debug_info_req){
    status = phNxpNciHal_send_ext_cmd(sizeof(cmd_get_cfg_dbg_info), cmd_get_cfg_dbg_info);
    if (status != NFCSTATUS_SUCCESS) {
      NXPLOG_NCIHAL_E("NFCC texted reset ntf failed");
    }
    NXPLOG_NCIHAL_D("NFCC txed reset ntf with reason code 0xA3");
    property_set("persist.vendor.nfc.core_reset_debug_info", "false");
  }
  setConfigAlways = false;
  isfound = GetNxpNumValue(NAME_NXP_SET_CONFIG_ALWAYS, &num, sizeof(num));
  if (isfound > 0) {
    setConfigAlways = num;
  }
  NXPLOG_NCIHAL_D("fw_download_success : 0x%02x SetConfigAlways flag : 0x%02x",
                  fw_download_success, setConfigAlways);

  if ((true == fw_download_success) || (true == setConfigAlways) ||
       isNxpConfigModified()) {
    config_access = true;
    retlen = 0;
    if (phNxpNciHal_nfccClockCfgApply() != NFCSTATUS_SUCCESS) {
        NXPLOG_NCIHAL_E("phNxpNciHal_nfccClockCfgApply failed");
        NXP_NCI_HAL_CORE_INIT_RECOVER(retry_core_init_cnt, retry_core_init);
    }

#ifdef PN547C2_CLOCK_SETTING
#if (NFC_NXP_HFO_SETTINGS == TRUE)
    NXPLOG_NCIHAL_D("Applying Default Clock setting and DPLL register at power on");
    /*
    # A0, 0D, 06, 06, 83, 55, 2A, 04, 00 RF_CLIF_CFG_TARGET CLIF_DPLL_GEAR_REG
    # A0, 0D, 06, 06, 82, 33, 14, 17, 00 RF_CLIF_CFG_TARGET CLIF_DPLL_INIT_REG
    # A0, 0D, 06, 06, 84, AA, 85, 00, 80 RF_CLIF_CFG_TARGET CLIF_DPLL_INIT_FREQ_REG
    # A0, 0D, 06, 06, 81, 63, 00, 00, 00 RF_CLIF_CFG_TARGET CLIF_DPLL_CONTROL_REG
    */
    static uint8_t cmd_dpll_set_reg_nci[] = {0x20, 0x02, 0x25, 0x04,
                                             0xA0, 0x0D, 0x06, 0x06, 0x83, 0x55, 0x2A, 0x04, 0x00,
                                             0xA0, 0x0D, 0x06, 0x06, 0x82, 0x33, 0x14, 0x17, 0x00,
                                             0xA0, 0x0D, 0x06, 0x06, 0x84, 0xAA, 0x85, 0x00, 0x80,
                                             0xA0, 0x0D, 0x06, 0x06, 0x81, 0x63, 0x00, 0x00, 0x00};

    status = phNxpNciHal_send_ext_cmd(sizeof(cmd_dpll_set_reg_nci), cmd_dpll_set_reg_nci);
    if (status != NFCSTATUS_SUCCESS) {
        NXPLOG_NCIHAL_E("NXP DPLL REG ACT Proprietary Ext failed");
        NXP_NCI_HAL_CORE_INIT_RECOVER(retry_core_init_cnt, retry_core_init);
    }
    /* reset the NFCC after applying the clock setting and DPLL setting */
    //phTmlNfc_IoCtl(phTmlNfc_e_ResetDevice);
#endif
#endif
  }
  retlen = 0;
  isfound = GetNxpByteArrayValue(NAME_NXP_NFC_PROFILE_EXTN, (char*)buffer,
                                 bufflen, &retlen);
  if (retlen > 0) {
    /* NXP ACT Proprietary Ext */
    status = phNxpNciHal_send_ext_cmd(retlen, buffer);
    if (status != NFCSTATUS_SUCCESS) {
      NXPLOG_NCIHAL_E("NXP ACT Proprietary Ext failed");
      NXP_NCI_HAL_CORE_INIT_RECOVER(retry_core_init_cnt, retry_core_init);
    }
  }

  if ((true == fw_download_success) || (true == setConfigAlways) ||
       isNxpConfigModified()) {
    config_access = true;
    retlen = 0;
    if (nfcFL.chipType != pn547C2) {
      NXPLOG_NCIHAL_D("Performing TVDD Settings");
      /*TVDD settings commented for PN553 bringup FW  */
      isfound = GetNxpNumValue(NAME_NXP_EXT_TVDD_CFG, &num, sizeof(num));
      if (isfound > 0 && (num > 0 && num <= 3)) {
        isfound = GetNxpByteArrayValue(TVDD_CONFIG_LIST[num - 1],
            (char*) buffer, bufflen, &retlen);
        if (retlen > 0) {
          status = phNxpNciHal_send_ext_cmd(retlen, buffer);
          if (status != NFCSTATUS_SUCCESS) {
            NXPLOG_NCIHAL_E("EXT TVDD CFG 1 Settings failed");
            NXP_NCI_HAL_CORE_INIT_RECOVER(retry_core_init_cnt, retry_core_init);
          }
        }
      } else {
        NXPLOG_NCIHAL_E("Wrong Configuration Value %ld", num);
      }
    }
  }

    retlen = 0;
    if ((true == fw_download_success) || (true == setConfigAlways) ||
         isNxpRFConfigModified()) {
      if(nfcFL.chipType != pn547C2) {
          config_access = false;
      }
      uint8_t numOfBlocks = sizeof(RF_BLOCK_LIST)/sizeof(RF_BLOCK_LIST[0]);
      for(int i=0; i< numOfBlocks; i++)
      {
        retlen = 0;
        NXPLOG_NCIHAL_D("Performing RF Settings BLK %u", i+1);
        isfound = GetNxpByteArrayValue(RF_BLOCK_LIST[i], (char*)buffer,
                                       bufflen, &retlen);
        if (retlen > 0) {
          status = phNxpNciHal_send_ext_cmd(retlen, buffer);
          if ((nfcFL.chipType != pn547C2) && (status == NFCSTATUS_SUCCESS)) {
              status = phNxpNciHal_CheckRFCmdRespStatus();
              /*STATUS INVALID PARAM 0x09*/
              if (status == 0x09) {
                  phNxpNciHalRFConfigCmdRecSequence();
                  //NXP_NCI_HAL_CORE_INIT_RECOVER(retry_core_init_cnt, retry_core_init);
                  break;
              }
          } else if (status != NFCSTATUS_SUCCESS) {
              NXPLOG_NCIHAL_E("RF Settings BLK %u failed", i+1);
              //NXP_NCI_HAL_CORE_INIT_RECOVER(retry_core_init_cnt, retry_core_init);
              break;
          }
        }
      }
      if(status != NFCSTATUS_SUCCESS)
        NXP_NCI_HAL_CORE_INIT_RECOVER(retry_core_init_cnt, retry_core_init);

      retlen = 0;
      if (nfcFL.chipType != pn547C2) {
          config_access = true;
      }

      NXPLOG_NCIHAL_D("Performing NAME_NXP_CORE_CONF_EXTN Settings");
      isfound = GetNxpByteArrayValue(NAME_NXP_CORE_CONF_EXTN, (char*)buffer,
                                     bufflen, &retlen);
      if (retlen > 0) {
        /* NXP ACT Proprietary Ext */
        status = phNxpNciHal_send_ext_cmd(retlen, buffer);
        if (status != NFCSTATUS_SUCCESS) {
          NXPLOG_NCIHAL_E("NXP Core configuration failed");
          NXP_NCI_HAL_CORE_INIT_RECOVER(retry_core_init_cnt, retry_core_init);
        }
      }

      NXPLOG_NCIHAL_D("Performing NAME_NXP_CORE_CONF Settings");
      retlen = 0;
      isfound = GetNxpByteArrayValue(NAME_NXP_CORE_CONF, (char*)buffer, bufflen,
                                     &retlen);
      if (retlen > 0) {
        /* NXP ACT Proprietary Ext */
        status = phNxpNciHal_send_ext_cmd(retlen, buffer);
        if (status != NFCSTATUS_SUCCESS) {
          NXPLOG_NCIHAL_E("Core Set Config failed");
          NXP_NCI_HAL_CORE_INIT_RECOVER(retry_core_init_cnt, retry_core_init);
        }
      }
    }

  if ((true == fw_download_success) || (true == setConfigAlways)
      || isNxpConfigModified() || isNxpRFConfigModified()) {
    if (nfcFL.eseFL._ESE_ETSI12_PROP_INIT) {
      uint8_t swp_info_buff[2];
      uint8_t swp_intf_status = 0x00;
      uint8_t swp1A_intf_status = 0x00;
      NFCSTATUS status = NFCSTATUS_FAILED;
      phNxpNci_EEPROM_info_t swp_intf_info;

      memset(swp_info_buff, 0, sizeof(swp_info_buff));
      /*Read SWP1 data*/
      memset(&swp_intf_info, 0, sizeof(swp_intf_info));
      swp_intf_info.request_mode = GET_EEPROM_DATA;
      swp_intf_info.request_type = EEPROM_SWP1_INTF;
      swp_intf_info.buffer = &swp_intf_status;
      swp_intf_info.bufflen = sizeof(uint8_t);
      status = request_EEPROM(&swp_intf_info);
      if (status == NFCSTATUS_OK)
        swp_info_buff[0] = swp_intf_status;
      else {
        NXPLOG_NCIHAL_E("request_EEPROM error occured %d", status);
        NXP_NCI_HAL_CORE_INIT_RECOVER(retry_core_init_cnt, retry_core_init);
      }
      if (nfcFL.nfccFL._NFC_NXP_STAT_DUAL_UICC_WO_EXT_SWITCH) {
        /*Read SWP1A data*/
        memset(&swp_intf_info, 0, sizeof(swp_intf_info));
        swp_intf_info.request_mode = GET_EEPROM_DATA;
        swp_intf_info.request_type = EEPROM_SWP1A_INTF;
        swp_intf_info.buffer = &swp1A_intf_status;
        swp_intf_info.bufflen = sizeof(uint8_t);
        status = request_EEPROM(&swp_intf_info);
        if (status == NFCSTATUS_OK)
          swp_info_buff[1] = swp1A_intf_status;
        else {
          NXPLOG_NCIHAL_E("request_EEPROM error occured %d", status);
          NXP_NCI_HAL_CORE_INIT_RECOVER(retry_core_init_cnt, retry_core_init);
        }
      }
      phNxpNci_EEPROM_info_t mEEPROM_info = { .request_mode = 0 };
      mEEPROM_info.buffer = swp_info_buff;
      mEEPROM_info.bufflen = sizeof(swp_info_buff);
      mEEPROM_info.request_type = EEPROM_RF_CFG;
      mEEPROM_info.request_mode = SET_EEPROM_DATA;
      status = request_EEPROM(&mEEPROM_info);
      NXPLOG_NCIHAL_D(
          "Setting value %d %d", swp_info_buff[1], swp_info_buff[0]);
    } // END_OF_NFC_NXP_ESE_ETSI12_PROP_INIT

    retlen = 0;
    isfound = GetNxpByteArrayValue(NAME_NXP_CORE_MFCKEY_SETTING, (char*) buffer,
        bufflen, &retlen);
    if (retlen > 0) {
      /* NXP ACT Proprietary Ext */
      status = phNxpNciHal_send_ext_cmd(retlen, buffer);
      if (status != NFCSTATUS_SUCCESS) {
        NXPLOG_NCIHAL_E("Setting mifare keys failed");
        NXP_NCI_HAL_CORE_INIT_RECOVER(retry_core_init_cnt, retry_core_init);
      }
    }

    retlen = 0;
    if (nfcFL.chipType != pn547C2) {
      config_access = false;
    }
    isfound = GetNxpByteArrayValue(NAME_NXP_CORE_RF_FIELD, (char*) buffer,
        bufflen, &retlen);
    if (retlen > 0) {
      /* NXP ACT Proprietary Ext */
      status = phNxpNciHal_send_ext_cmd(retlen, buffer);
      if ((nfcFL.chipType != pn547C2) && (status == NFCSTATUS_SUCCESS)) {
        status = phNxpNciHal_CheckRFCmdRespStatus();
        /*STATUS INVALID PARAM 0x09*/
        if (status == 0x09) {
          phNxpNciHalRFConfigCmdRecSequence();
          NXP_NCI_HAL_CORE_INIT_RECOVER(retry_core_init_cnt, retry_core_init);
        }
      } else if (status != NFCSTATUS_SUCCESS) {
        NXPLOG_NCIHAL_E("Setting NXP_CORE_RF_FIELD status failed");
        NXP_NCI_HAL_CORE_INIT_RECOVER(retry_core_init_cnt, retry_core_init);
      }
    }
    if (nfcFL.chipType != pn547C2) {
      config_access = true;
    }
    num = 0;

    if (nfcFL.chipType != pn547C2) {
      /* NXP SWP switch timeout Setting*/
      if (GetNxpNumValue(NAME_NXP_SWP_SWITCH_TIMEOUT, (void*) &num,
          sizeof(num))) {
        // Check the permissible range [0 - 60]
        if (num <= 60) {
          if (0 < num) {
            uint16_t timeout = num * 1000;
            swp_switch_timeout_cmd[7] = (timeout & 0xFF);
            swp_switch_timeout_cmd[8] = ((timeout & 0xFF00) >> 8);
          }

          status = phNxpNciHal_send_ext_cmd(sizeof(swp_switch_timeout_cmd),
              swp_switch_timeout_cmd);
          if (status != NFCSTATUS_SUCCESS) {
            NXPLOG_NCIHAL_E("SWP switch timeout Setting Failed");
            NXP_NCI_HAL_CORE_INIT_RECOVER(retry_core_init_cnt, retry_core_init);
          }
        } else {
          NXPLOG_NCIHAL_E("SWP switch timeout Setting Failed - out of range!");
        }
      }
    }
    if (nfcFL.chipType != pn547C2) {
      status = phNxpNciHal_set_china_region_configs();
      if (status != NFCSTATUS_SUCCESS) {
        NXPLOG_NCIHAL_E("phNxpNciHal_set_china_region_configs failed");
        NXP_NCI_HAL_CORE_INIT_RECOVER(retry_core_init_cnt, retry_core_init);
      }
    }

    if (nfcFL.chipType == pn547C2) {
      status = phNxpNciHal_uicc_baud_rate();
      if (status != NFCSTATUS_SUCCESS) {
        NXPLOG_NCIHAL_E("Setting NXP_CORE_RF_FIELD status failed");
        NXP_NCI_HAL_CORE_INIT_RECOVER(retry_core_init_cnt, retry_core_init);
      }
    }

    config_access = false;
    // if recovery mode and length of last command is 0 then only reset the P2P
    // listen mode routing.
    if ((*p_core_init_rsp_params > 0) && (*p_core_init_rsp_params < 4)
        && p_core_init_rsp_params[35] == 0) {
      /* P2P listen mode routing */
      status = phNxpNciHal_send_ext_cmd(sizeof(p2p_listen_mode_routing_cmd),
          p2p_listen_mode_routing_cmd);
      if (status != NFCSTATUS_SUCCESS) {
        NXPLOG_NCIHAL_E("P2P listen mode routing failed");
        NXP_NCI_HAL_CORE_INIT_RECOVER(retry_core_init_cnt, retry_core_init);
      }
    }

    num = 0;
    /* SWP FULL PWR MODE SETTING ON */
    if (GetNxpNumValue(NAME_NXP_SWP_FULL_PWR_ON, (void*) &num, sizeof(num))) {
      if (1 == num) {
        status = phNxpNciHal_send_ext_cmd(sizeof(swp_full_pwr_mode_on_cmd),
            swp_full_pwr_mode_on_cmd);
        if (status != NFCSTATUS_SUCCESS) {
          NXPLOG_NCIHAL_E("SWP FULL PWR MODE SETTING ON CMD FAILED");
          NXP_NCI_HAL_CORE_INIT_RECOVER(retry_core_init_cnt, retry_core_init);
        }
      } else {
        swp_full_pwr_mode_on_cmd[7] = 0x00;
        status = phNxpNciHal_send_ext_cmd(sizeof(swp_full_pwr_mode_on_cmd),
            swp_full_pwr_mode_on_cmd);
        if (status != NFCSTATUS_SUCCESS) {
          NXPLOG_NCIHAL_E("SWP FULL PWR MODE SETTING OFF CMD FAILED");
          NXP_NCI_HAL_CORE_INIT_RECOVER(retry_core_init_cnt, retry_core_init);
        }
      }
    }
    if (nfcFL.nfccFL._NFCC_AID_MATCHING_PLATFORM_CONFIG == true) {
      num = 0;
      /* Android L AID Matching Platform Setting*/
      if (GetNxpNumValue(NAME_AID_MATCHING_PLATFORM, (void*) &num,
          sizeof(num))) {
        if (1 == num) {
          status = phNxpNciHal_send_ext_cmd(
              sizeof(android_l_aid_matching_mode_on_cmd),
              android_l_aid_matching_mode_on_cmd);
          if (status != NFCSTATUS_SUCCESS) {
            NXPLOG_NCIHAL_E("Android L AID Matching Platform Setting Failed");
            NXP_NCI_HAL_CORE_INIT_RECOVER(retry_core_init_cnt, retry_core_init);
          }
        } else if (2 == num) {
          android_l_aid_matching_mode_on_cmd[7] = 0x00;
          status = phNxpNciHal_send_ext_cmd(
              sizeof(android_l_aid_matching_mode_on_cmd),
              android_l_aid_matching_mode_on_cmd);
          if (status != NFCSTATUS_SUCCESS) {
            NXPLOG_NCIHAL_E("Android L AID Matching Platform Setting Failed");
            NXP_NCI_HAL_CORE_INIT_RECOVER(retry_core_init_cnt, retry_core_init);
          }
        }
      }
    }
  }

  if (persist_hci_network_reset_req) {
    phNxpNciHal_hci_network_reset();
  }

  config_access = false;
  if (!((*p_core_init_rsp_params > 0) && (*p_core_init_rsp_params < 4))) {
      if(nfcFL.nfcNxpEse == true && nfcFL.eseFL._ESE_ETSI12_PROP_INIT) {
          status = phNxpNciHal_check_eSE_Session_Identity();
          if (status != NFCSTATUS_SUCCESS) {
              NXPLOG_NCIHAL_E("Session id/ SWP intf reset Failed");
              NXP_NCI_HAL_CORE_INIT_RECOVER(retry_core_init_cnt, retry_core_init);
          }
      }
    status = phNxpNciHal_send_ext_cmd(sizeof(cmd_reset_nci), cmd_reset_nci);
    if (status == NFCSTATUS_SUCCESS) {
        if (nxpncihal_ctrl.nci_info.nci_version == NCI_VERSION_2_0) {
          status = phNxpNciHal_send_ext_cmd(sizeof(cmd_init_nci2_0), cmd_init_nci2_0);
        } else {
          status = phNxpNciHal_send_ext_cmd(sizeof(cmd_init_nci), cmd_init_nci);
        }
        if (status != NFCSTATUS_SUCCESS)
            return status;
    } else {
      return NFCSTATUS_FAILED;
    }
    status = phNxpNciHal_send_get_cfgs();
    if (status == NFCSTATUS_SUCCESS) {
      NXPLOG_NCIHAL_E("Send get Configs SUCCESS");
    } else {
      NXPLOG_NCIHAL_E("Send get Configs FAILED");
    }
  }

  if(nfcFL.eseFL._WIRED_MODE_STANDBY == true) {
      if (nxpncihal_ctrl.hal_boot_mode == NFC_OSU_BOOT_MODE) {
          status = phNxpNciHal_send_nfcee_pwr_cntl_cmd(POWER_ALWAYS_ON);
          if (status == NFCSTATUS_SUCCESS) {
              NXPLOG_NCIHAL_E("Send nfcee_pwrcntl cmd SUCCESS");
          } else {
              NXPLOG_NCIHAL_E("Send nfcee_pwrcntl cmd FAILED");
          }
      }

      if (pwr_link_required == true) {
          phNxpNciHal_send_nfcee_pwr_cntl_cmd(POWER_ALWAYS_ON | LINK_ALWAYS_ON);
          pwr_link_required = false;
      }
  }

  if ((*p_core_init_rsp_params > 0) && (*p_core_init_rsp_params < 4)) {
    static phLibNfc_Message_t msg;
    uint16_t tmp_len = 0;
    uint8_t set_screen_state[] = {0x2F, 0x15, 01, 00};  // SCREEN ON
    uint8_t set_screen_state_nci2[] = {0x20,0x09,0x01,0x00};
    uint8_t nfcc_core_conn_create[] = {0x20, 0x04, 0x06, 0x03, 0x01,
                                       0x01, 0x02, 0x01, 0x01};
    uint8_t nfcc_mode_set_on[] = {0x22, 0x01, 0x02, 0x01, 0x01};
    if(nxpncihal_ctrl.nci_info.nci_version != NCI_VERSION_2_0)
   {
    NXPLOG_NCIHAL_W(
        "Sending DH and NFCC core connection command as raw packet!!");
    status = phNxpNciHal_send_ext_cmd(sizeof(nfcc_core_conn_create),
                                      nfcc_core_conn_create);

    if (status != NFCSTATUS_SUCCESS) {
      NXPLOG_NCIHAL_E(
          "Sending DH and NFCC core connection command as raw packet!! Failed");
      NXP_NCI_HAL_CORE_INIT_RECOVER(retry_core_init_cnt, retry_core_init);
    }

    NXPLOG_NCIHAL_W("Sending DH and NFCC mode set as raw packet!!");
    status =
        phNxpNciHal_send_ext_cmd(sizeof(nfcc_mode_set_on), nfcc_mode_set_on);

    if (status != NFCSTATUS_SUCCESS) {
      NXPLOG_NCIHAL_E("Sending DH and NFCC mode set as raw packet!! Failed");
      NXP_NCI_HAL_CORE_INIT_RECOVER(retry_core_init_cnt, retry_core_init);
    }
   }

    // Set the proper screen state
    switch (p_core_init_rsp_params[295]) {
      case 0x0:
      case 0x8:
        NXPLOG_NCIHAL_E("Last Screen State Sent = 0x0");
        set_screen_state[3] = 0x00;  // SCREEN ON UNLOCKED (listen and poll
                                     // mode)
        break;
      case 0x2:
        NXPLOG_NCIHAL_E("Last Screen State Sent = 0x1");
        set_screen_state[3] = 0x01;  // SCREEN OFF LOCKED
        set_screen_state_nci2[3] = 0x03;
        break;
      case 0x4:
        NXPLOG_NCIHAL_E("Last Screen State Sent = 0x2");
        set_screen_state[3] = 0x02;  // SCREEN ON LOCKED (only listen mode)
        set_screen_state_nci2[3] = 0x02;
        break;
      case 1:
        set_screen_state_nci2[3] = 0x01;
        set_screen_state[3] = 0x02;  // SCREEN OFF UNLOCKED (only listen mode)
        break;
      default:
        NXPLOG_NCIHAL_E("Setting default as SCREEN ON UNLOCKED");
        set_screen_state[3] = 0x00;  // SCREEN ON UNLOCKED (listen and poll
                                     // mode)
        break;
    }

    if (*(p_core_init_rsp_params + 1) == 1)  // RF state is Discovery!!
    {
      NXPLOG_NCIHAL_W("Sending Set Screen ON State Command as raw packet!!");
      if(nxpncihal_ctrl.nci_info.nci_version != NCI_VERSION_2_0)
      {
      status =
          phNxpNciHal_send_ext_cmd(sizeof(set_screen_state), set_screen_state);
      }else
      {
          status =
              phNxpNciHal_send_ext_cmd(sizeof(set_screen_state_nci2), set_screen_state_nci2);
      }
      if (status != NFCSTATUS_SUCCESS) {
        NXPLOG_NCIHAL_E(
            "Sending Set Screen ON State Command as raw packet!! Failed");
        NXP_NCI_HAL_CORE_INIT_RECOVER(retry_core_init_cnt, retry_core_init);
      }

      NXPLOG_NCIHAL_W("Sending discovery as raw packet!!");
      status = phNxpNciHal_send_ext_cmd(p_core_init_rsp_params[2],
                                        (uint8_t*)&p_core_init_rsp_params[3]);
      if (status != NFCSTATUS_SUCCESS) {
        NXPLOG_NCIHAL_E("Sending discovery as raw packet Failed");
        NXP_NCI_HAL_CORE_INIT_RECOVER(retry_core_init_cnt, retry_core_init);
      }
    } else {
      NXPLOG_NCIHAL_W("Sending Set Screen OFF State Command as raw packet!!");
      if(nxpncihal_ctrl.nci_info.nci_version != NCI_VERSION_2_0)
      {
      status =
          phNxpNciHal_send_ext_cmd(sizeof(set_screen_state), set_screen_state);
      }else
      {
          status =
              phNxpNciHal_send_ext_cmd(sizeof(set_screen_state_nci2), set_screen_state_nci2);
      }
      if (status != NFCSTATUS_SUCCESS) {
        NXPLOG_NCIHAL_E(
            "Sending Set Screen OFF State Command as raw packet!! Failed");
        NXP_NCI_HAL_CORE_INIT_RECOVER(retry_core_init_cnt, retry_core_init);
        }
      }

    if (nxpprofile_ctrl.profile_type == EMV_CO_PROFILE) {
      NXPLOG_NCIHAL_E(
          "Current Profile : EMV_CO_PROFILE. Resetting to "
          "NFC_FORUM_PROFILE...");
      nxpprofile_ctrl.profile_type = NFC_FORUM_PROFILE;
    }

    NXPLOG_NCIHAL_W("Sending last command for Recovery ");

    if (p_core_init_rsp_params[35] == 1) {
      if (!((p_core_init_rsp_params[36] == 0x21) &&
            (p_core_init_rsp_params[37] == 0x03) &&
            (*(p_core_init_rsp_params + 1) == 0x01)) &&
          !((p_core_init_rsp_params[36] == 0x21) &&
            (p_core_init_rsp_params[37] == 0x06) &&
            (p_core_init_rsp_params[39] == 0x00) &&
            (*(p_core_init_rsp_params + 1) == 0x00)))
      // if last command is discovery and RF status is also discovery state,
      // then it doesn't need to execute or similarly
      // if the last command is deactivate to idle and RF status is also idle ,
      // no need to execute the command .
      {
          tmp_len = p_core_init_rsp_params[38] + 3; //Field 38 gives length of data + 3 - header and length field
        /* Check for NXP ext before sending write */
        status = phNxpNciHal_write_ext(
            &tmp_len, (uint8_t*)&p_core_init_rsp_params[36],
            &nxpncihal_ctrl.rsp_len, nxpncihal_ctrl.p_rsp_data);
        if (status != NFCSTATUS_SUCCESS) {
          if (buffer) {
            free(buffer);
            buffer = NULL;
          }
          /* Do not send packet to PN54X, send response directly */
          msg.eMsgType = NCI_HAL_RX_MSG;
          msg.pMsgData = NULL;
          msg.Size = 0;

          phTmlNfc_DeferredCall(gpphTmlNfc_Context->dwCallbackThreadId,
                                (phLibNfc_Message_t*)&msg);
          return NFCSTATUS_SUCCESS;
        }

        status = phNxpNciHal_send_ext_cmd(
                tmp_len, (uint8_t*)&p_core_init_rsp_params[36]);
        if (status != NFCSTATUS_SUCCESS) {
          NXPLOG_NCIHAL_E("Sending last command for Recovery Failed");
          NXP_NCI_HAL_CORE_INIT_RECOVER(retry_core_init_cnt, retry_core_init);
        }
      }
    }
  }

  isfound = GetNxpNumValue(NAME_NXP_NCI_PARSER_LIBRARY, &num, sizeof(num));
  if(isfound > 0 && num == 0x01)
  {
    phNxpNciHal_configNciParser();
  }

  retry_core_init_cnt = 0;

  if (buffer) {
    free(buffer);
    buffer = NULL;
  }
  config_access = false;

  if(nfcFL.chipType != pn547C2) {
  // initialize dummy FW recovery variables
  gRecFWDwnld = false;
  gRecFwRetryCount = 0;
}
  if (!((*p_core_init_rsp_params > 0) && (*p_core_init_rsp_params < 4)))
    phNxpNciHal_core_initialized_complete(status);
  else {
  invoke_callback:
    config_access = false;
    if (nxpncihal_ctrl.p_nfc_stack_data_cback != NULL) {
      *p_core_init_rsp_params = 0;
      NXPLOG_NCIHAL_W("Invoking data callback!!");
      (*nxpncihal_ctrl.p_nfc_stack_data_cback)(nxpncihal_ctrl.rx_data_len,
                                               nxpncihal_ctrl.p_rx_data);
    }
  }
  if (isNxpRFConfigModified() || isNxpConfigModified()) {
    updateNxpConfigTimestamp();
  }
  if (config_success == false)
    return NFCSTATUS_FAILED;
  else
    return NFCSTATUS_SUCCESS;
}
/******************************************************************************
 * Function         phNxpNciHal_hci_network_reset
 *
 * Description      This function resets the session id's of all the se's
 *                  in the HCI network and notify to HCI_NETWORK_RESET event to
 *                  NFC HAL Client.
 *
 * Returns          void.
 *
 ******************************************************************************/
static void phNxpNciHal_hci_network_reset(void) {
  NXPLOG_NCIHAL_D("%s: enter", __func__);
  static phLibNfc_Message_t msg;
  phNxpNciHal_reset_nfcee_session(true);
  msg.eMsgType = NCI_HAL_HCI_NETWORK_RESET_MSG;
  phTmlNfc_DeferredCall(gpphTmlNfc_Context->dwCallbackThreadId, &msg);
  NXPLOG_NCIHAL_D("%s: exit", __func__);
}
/******************************************************************************
 * Function         phNxpNciHal_check_eSE_Session_Identity
 *
 * Description      This function is called at init time to check
 *                  the presence of ese related info and disable SWP interfaces.
 *
 * Returns          void.
 *
 ******************************************************************************/
static NFCSTATUS phNxpNciHal_check_eSE_Session_Identity(void) {
  NFCSTATUS status = NFCSTATUS_FAILED;
  static uint8_t session_identity[8] = {0x00};
  uint8_t default_session[8] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
  uint8_t swp2_intf_status = 0x00;
  static uint8_t disable_dual_swp_intf[] = {0x20, 0x02, 0x09, 0x02, 0xA0, 0xEC,
                                       0x01, 0x00, 0xA0, 0xD4, 0x01, 0x00};
  static uint8_t disable_swp_intf[] = {0x20, 0x02, 0x05, 0x01,
                                       0xA0, 0xEC, 0x01, 0x00};

  phNxpNci_EEPROM_info_t swp_intf_info;

  memset(&swp_intf_info, 0, sizeof(swp_intf_info));
  swp_intf_info.request_mode = GET_EEPROM_DATA;
  swp_intf_info.request_type = EEPROM_SWP2_INTF;
  swp_intf_info.buffer = &swp2_intf_status;
  swp_intf_info.bufflen = sizeof(uint8_t);
  status = request_EEPROM(&swp_intf_info);
  NXPLOG_NCIHAL_D("%s swp2_intf_status = 0x%02X", __func__, swp2_intf_status);
  if ((status == NFCSTATUS_OK) && (swp2_intf_status == 0x00)) {
    pwr_link_required = false;
    return NFCSTATUS_SUCCESS;
  }

    phNxpNci_EEPROM_info_t mEEPROM_info = {.request_mode = 0};
    mEEPROM_info.request_mode = GET_EEPROM_DATA;
    mEEPROM_info.request_type = EEPROM_ESE_SESSION_ID;
    mEEPROM_info.buffer = session_identity;
    mEEPROM_info.bufflen = sizeof(session_identity);
    status = request_EEPROM(&mEEPROM_info);
    if (status == NFCSTATUS_OK) {
      if (!memcmp((uint8_t*)session_identity, (uint8_t*)default_session,
                  sizeof(session_identity))) {
        status = NFCSTATUS_FAILED;
      } else {
        status = NFCSTATUS_OK;
      }
    }

  if (status == NFCSTATUS_FAILED) {
    /*Disable SWP1 and 1A interfaces*/
      if(nfcFL.nfccFL._NFC_NXP_STAT_DUAL_UICC_WO_EXT_SWITCH) {
          status = phNxpNciHal_send_ext_cmd(sizeof(disable_dual_swp_intf),
                  disable_dual_swp_intf);
      }
      else {
          status = phNxpNciHal_send_ext_cmd(sizeof(disable_swp_intf),
                  disable_swp_intf);
      }
    if (status != NFCSTATUS_SUCCESS) {
      NXPLOG_NCIHAL_E("NXP disable SWP interface_set command failed");
    }
    pwr_link_required = true;
  }
  return status;
}

/******************************************************************************
 * Function         phNxpNciHal_CheckRFCmdRespStatus
 *
 * Description      This function is called to check the resp status of
 *                  RF update commands.
 *
 * Returns          NFCSTATUS_SUCCESS           if successful,
 *                  NFCSTATUS_INVALID_PARAMETER if parameter is inavlid
 *                  NFCSTATUS_FAILED            if failed response
 *
 ******************************************************************************/
NFCSTATUS phNxpNciHal_CheckRFCmdRespStatus() {
    NXPLOG_NCIHAL_D("phNxpNciHal_CheckRFCmdRespStatus () Enter");
    if(nfcFL.chipType == pn547C2) {
        NXPLOG_NCIHAL_D("chipType : pn547C2. Not allowed. Returning");
        return NFCSTATUS_FAILED;
    }
  NFCSTATUS status = NFCSTATUS_SUCCESS;
  static uint16_t INVALID_PARAM = 0x09;
  if ((nxpncihal_ctrl.rx_data_len > 0) && (nxpncihal_ctrl.p_rx_data[2] > 0)) {
    if (nxpncihal_ctrl.p_rx_data[3] == 0x09) {
      status = INVALID_PARAM;
    } else if (nxpncihal_ctrl.p_rx_data[3] != NFCSTATUS_SUCCESS) {
      status = NFCSTATUS_FAILED;
    }
  }
  return status;
}

/******************************************************************************
 * Function         phNxpNciHalRFConfigCmdRecSequence
 *
 * Description      This function is called to handle dummy FW recovery sequence
 *                  Whenever RF settings are failed to apply with invalid param
 *                  response , recovery mechanism  includes dummy firmware
 *download
 *                  followed by irmware downlaod and then config settings. The
 *dummy
 *                  firmware changes the major number of the firmware inside
 *NFCC.
 *                  Then actual firmware dowenload will be successful.This can
 *be
 *                  retried maximum three times.
 *
 * Returns          Always returns NFCSTATUS_SUCCESS
 *
 ******************************************************************************/
NFCSTATUS phNxpNciHalRFConfigCmdRecSequence() {
    NXPLOG_NCIHAL_D("phNxpNciHalRFConfigCmdRecSequence () Enter");
    if(nfcFL.chipType == pn547C2) {
        NXPLOG_NCIHAL_D("chipType : pn547C2. Not allowed. Returning");
        return NFCSTATUS_FAILED;
    }
  NFCSTATUS status = NFCSTATUS_SUCCESS;
  uint16_t recFWState = 1;
  if(nfcFL.nfccFL._NFCC_FORCE_FW_DOWNLOAD == true) {
      gRecFWDwnld = false;
      force_fw_download_req = true;
  } else {
      gRecFWDwnld = true;
  }
  gRecFwRetryCount++;
  if (gRecFwRetryCount > 0x03) {
    NXPLOG_NCIHAL_D("Max retry count for RF config FW recovery exceeded ");
    gRecFWDwnld = false;
    if(nfcFL.nfccFL._NFCC_FORCE_FW_DOWNLOAD == true) {
        force_fw_download_req = false;
    }
    return NFCSTATUS_FAILED;
  }
  do {
    phDnldNfc_InitImgInfo();
    if (NFCSTATUS_SUCCESS == phNxpNciHal_CheckValidFwVersion()) {
      status = phNxpNciHal_fw_download();
      if (status == NFCSTATUS_FAILED) {
        break;
      }
    }
    gRecFWDwnld = false;
  } while (recFWState--);
  gRecFWDwnld = false;
  if(nfcFL.nfccFL._NFCC_FORCE_FW_DOWNLOAD == true) {
      force_fw_download_req = false;
  }
  return status;
}

/******************************************************************************
 * Function         phNxpNciHal_uicc_baud_rate
 *
 * Description      This function is used to restrict the UICC baud
 *                  rate for type A and type B UICC.
 *
 * Returns          Status.
 *
 ******************************************************************************/
static NFCSTATUS phNxpNciHal_uicc_baud_rate() {
    NXPLOG_NCIHAL_D("phNxpNciHal_uicc_baud_rate () Enter");
    if(nfcFL.chipType != pn547C2) {
        NXPLOG_NCIHAL_D("chipType != pn547C2. Not allowed. Returning");
        return NFCSTATUS_FAILED;
    }
  unsigned long configValue = 0x00;
  uint16_t bitRateCmdLen = 0x04;  // HDR + LEN + PARAMS   2 + 1 + 1
  uint8_t uiccTypeAValue = 0x00;  // read uicc type A value
  uint8_t uiccTypeBValue = 0x00;  // read uicc type B value
  uint8_t setUiccBitRateBuf[] = {0x20, 0x02, 0x01, 0x00, 0xA0, 0x86,
                                 0x01, 0x91, 0xA0, 0x87, 0x01, 0x91};
  uint8_t getUiccBitRateBuf[] = {0x20, 0x03, 0x05, 0x02,
                                 0xA0, 0x86, 0xA0, 0x87};
  NFCSTATUS status = NFCSTATUS_SUCCESS;
  status =
      phNxpNciHal_send_ext_cmd(sizeof(getUiccBitRateBuf), getUiccBitRateBuf);
  if (status == NFCSTATUS_SUCCESS && nxpncihal_ctrl.rx_data_len >= 0x0D) {
    if (nxpncihal_ctrl.p_rx_data[0] == 0x40 &&
        nxpncihal_ctrl.p_rx_data[1] == 0x03 &&
        nxpncihal_ctrl.p_rx_data[2] > 0x00 &&
        nxpncihal_ctrl.p_rx_data[3] == 0x00) {
      uiccTypeAValue = nxpncihal_ctrl.p_rx_data[8];
      uiccTypeBValue = nxpncihal_ctrl.p_rx_data[12];
    }
  }
  /* NXP Restrict Type A UICC baud rate */
  if (GetNxpNumValue(NAME_NXP_TYPEA_UICC_BAUD_RATE, (void*)&configValue,
                     sizeof(configValue))) {
    if (configValue == 0x00) {
      NXPLOG_NCIHAL_D("Default UICC TypeA Baud Rate supported");
    } else {
      setUiccBitRateBuf[2] += 0x04;  // length byte
      setUiccBitRateBuf[3] = 0x01;   // param byte
      bitRateCmdLen += 0x04;
      if (configValue == 0x01 && uiccTypeAValue != 0x91) {
        NXPLOG_NCIHAL_D("UICC TypeA Baud Rate 212kbps supported");
        setUiccBitRateBuf[7] = 0x91;  // set config value for 212
      } else if (configValue == 0x02 && uiccTypeAValue != 0xB3) {
        NXPLOG_NCIHAL_D("UICC TypeA Baud Rate 424kbps supported");
        setUiccBitRateBuf[7] = 0xB3;  // set config value for 424
      } else if (configValue == 0x03 && uiccTypeAValue != 0xF7) {
        NXPLOG_NCIHAL_D("UICC TypeA Baud Rate 848kbps supported");
        setUiccBitRateBuf[7] = 0xF7;  // set config value for 848
      } else {
        setUiccBitRateBuf[3] = 0x00;
        setUiccBitRateBuf[2] -= 0x04;
        bitRateCmdLen -= 0x04;
      }
    }
  }
  configValue = 0;
  /* NXP Restrict Type B UICC baud rate*/
  if (GetNxpNumValue(NAME_NXP_TYPEB_UICC_BAUD_RATE, (void*)&configValue,
                     sizeof(configValue))) {
    if (configValue == 0x00) {
      NXPLOG_NCIHAL_D("Default UICC TypeB Baud Rate supported");
    } else {
      setUiccBitRateBuf[2] += 0x04;
      setUiccBitRateBuf[3] += 0x01;
      setUiccBitRateBuf[bitRateCmdLen++] = 0xA0;
      setUiccBitRateBuf[bitRateCmdLen++] = 0x87;
      setUiccBitRateBuf[bitRateCmdLen++] = 0x01;
      if (configValue == 0x01 && uiccTypeBValue != 0x91) {
        NXPLOG_NCIHAL_D("UICC TypeB Baud Rate 212kbps supported");
        setUiccBitRateBuf[bitRateCmdLen++] = 0x91;  // set config value for 212
      } else if (configValue == 0x02 && uiccTypeBValue != 0xB3) {
        NXPLOG_NCIHAL_D("UICC TypeB Baud Rate 424kbps supported");
        setUiccBitRateBuf[bitRateCmdLen++] = 0xB3;  // set config value for 424
      } else if (configValue == 0x03 && uiccTypeBValue != 0xF7) {
        NXPLOG_NCIHAL_D("UICC TypeB Baud Rate 848kbps supported");
        setUiccBitRateBuf[bitRateCmdLen++] = 0xF7;  // set config value for 848
      } else {
        setUiccBitRateBuf[2] -= 0x04;
        setUiccBitRateBuf[3] -= 0x01;
        bitRateCmdLen -= 0x04;
      }
    }
  }
  if (bitRateCmdLen > 0x04) {
    status = phNxpNciHal_send_ext_cmd(bitRateCmdLen, setUiccBitRateBuf);
  }
  return status;
}

#ifdef FactoryOTA
void phNxpNciHal_isFactoryOTAModeActive() {
  uint8_t check_factoryOTA[] = {0x20, 0x03, 0x05, 0x02, 0xA0, 0x08, 0xA0, 0x88};
  NFCSTATUS status = NFCSTATUS_FAILED;
  NXPLOG_NCIHAL_D("check FactoryOTA mode status");

  status = phNxpNciHal_send_ext_cmd(sizeof(check_factoryOTA), check_factoryOTA);

  if (status == NFCSTATUS_SUCCESS) {
    if(nxpncihal_ctrl.p_rx_data[9] == 0x1 && nxpncihal_ctrl.p_rx_data[13] == 0x1) {
      NXPLOG_NCIHAL_E("FactoryOTA mode is active");
    } else {
      NXPLOG_NCIHAL_D("FactoryOTA mode is disabled");
    }
  } else {
    NXPLOG_NCIHAL_E("Fail to get FactoryOTA mode status");
  }
  return;
}

NFCSTATUS phNxpNciHal_disableFactoryOTAMode() {
  // NFCC GPIO output control
  uint8_t nfcc_system_gpio[] = {0x20, 0x02, 0x06, 0x01, 0xA0, 0x08, 0x02, 0x00, 0x00};
  // NFCC automatically sets GPIO once a specific RF pattern is detected
  uint8_t nfcc_gpio_pattern[] = {0x20, 0x02, 0x08, 0x01, 0xA0, 0x88, 0x04, 0x00, 0x96, 0x96, 0x03};

  NFCSTATUS status = NFCSTATUS_SUCCESS;
  NXPLOG_NCIHAL_D("Disable FactoryOTA mode");
  status = phNxpNciHal_send_ext_cmd(sizeof(nfcc_system_gpio), nfcc_system_gpio);
  if (status != NFCSTATUS_SUCCESS ) {
    NXPLOG_NCIHAL_E("Can't disable A008 for FactoryOTA mode");
  }
  status = phNxpNciHal_send_ext_cmd(sizeof(nfcc_gpio_pattern), nfcc_gpio_pattern);
  if (status != NFCSTATUS_SUCCESS ) {
    NXPLOG_NCIHAL_E("Can't disable A088 for FactoryOTA mode");
  }
  return status;
}
#endif

/******************************************************************************
 * Function         phNxpNciHal_core_initialized_complete
 *
 * Description      This function is called when phNxpNciHal_core_initialized
 *                  complete all proprietary command exchanges. This function
 *                  informs libnfc-nci about completion of core initialize
 *                  and result of that through callback.
 *
 * Returns          void.
 *
 ******************************************************************************/
static void phNxpNciHal_core_initialized_complete(NFCSTATUS status) {
  static phLibNfc_Message_t msg;

  if (status == NFCSTATUS_SUCCESS) {
    msg.eMsgType = NCI_HAL_POST_INIT_CPLT_MSG;
  } else {
    msg.eMsgType = NCI_HAL_ERROR_MSG;
  }
  msg.pMsgData = NULL;
  msg.Size = 0;

  phTmlNfc_DeferredCall(gpphTmlNfc_Context->dwCallbackThreadId,
                        (phLibNfc_Message_t*)&msg);

  return;
}
/******************************************************************************
 * Function         phNxpNciHal_core_MinInitialized_complete
 *
 * Description      This function is called when phNxpNciHal_core_initialized
 *                  complete all proprietary command exchanges. This function
 *                  informs libnfc-nci about completion of core initialize
 *                  and result of that through callback.
 *
 * Returns          void.
 *
 ******************************************************************************/
static void phNxpNciHal_core_MinInitialized_complete(NFCSTATUS status) {
  static phLibNfc_Message_t msg;

  if (status == NFCSTATUS_SUCCESS) {
    msg.eMsgType = NCI_HAL_POST_MIN_INIT_CPLT_MSG;
  } else {
    msg.eMsgType = NCI_HAL_ERROR_MSG;
  }
  msg.pMsgData = NULL;
  msg.Size = 0;

  phTmlNfc_DeferredCall(gpphTmlNfc_Context->dwCallbackThreadId,
                        (phLibNfc_Message_t*)&msg);

  return;
}
/******************************************************************************
 * Function         phNxpNciHal_pre_discover
 *
 * Description      This function is called by libnfc-nci to perform any
 *                  proprietary exchange before RF discovery.
 *
 * Returns          It always returns NFCSTATUS_SUCCESS (0).
 *
 ******************************************************************************/
int phNxpNciHal_pre_discover(void) {
  /* Nothing to do here for initial version */
  return NFCSTATUS_SUCCESS;
}

/******************************************************************************
 * Function         phNxpNciHal_release_info
 *
 * Description      This function frees allocated memory for mGetCfg_info
 *
 * Returns          void.
 *
 ******************************************************************************/
static void phNxpNciHal_release_info(void) {
  NXPLOG_NCIHAL_D("phNxpNciHal_release_info mGetCfg_info");
  if (mGetCfg_info != NULL) {
    free(mGetCfg_info);
    mGetCfg_info = NULL;
  }
}

/******************************************************************************
 * Function         phNxpNciHal_close
 *
 * Description      This function close the NFCC interface and free all
 *                  resources.This is called by libnfc-nci on NFC service stop.
 *
 * Returns          Always return NFCSTATUS_SUCCESS (0).
 *
 ******************************************************************************/
int phNxpNciHal_close(bool bShutdown) {
  AutoThreadMutex a(gsHalOpenCloseLock);
  NFCSTATUS status = NFCSTATUS_FAILED;
  static uint8_t cmd_core_reset_nci[] = {0x20, 0x00, 0x01, 0x00};
  static uint8_t cmd_ven_disable_nci[] = {0x20, 0x02, 0x05, 0x01,
                                         0xA0, 0x07, 0x01, 0x02};
  unsigned long uiccListenMask = 0x00;
  unsigned long eseListenMask = 0x00;

  unsigned long num = 0;

  if (!(GetNxpNumValue(NAME_NXP_UICC_LISTEN_TECH_MASK, &uiccListenMask,
                       sizeof(uiccListenMask)))) {
    uiccListenMask = 0x07;
    NXPLOG_NCIHAL_D("UICC_LISTEN_TECH_MASK = 0x%0lX", uiccListenMask);
  }

  if (!(GetNxpNumValue(NAME_NXP_ESE_LISTEN_TECH_MASK, &eseListenMask,
                      sizeof(eseListenMask)))) {
    eseListenMask = 0x07;
    NXPLOG_NCIHAL_D ("NXP_ESE_LISTEN_TECH_MASK = 0x%0lX", eseListenMask);
  }

  if (nxpncihal_ctrl.hal_boot_mode == NFC_FAST_BOOT_MODE) {
    NXPLOG_NCIHAL_E(" HAL NFC fast init mode calling min_close %d",
                    nxpncihal_ctrl.hal_boot_mode);
    status = phNxpNciHal_Minclose();
    return status;
  }

  if (nxpncihal_ctrl.halStatus == HAL_STATUS_CLOSE) {
    NXPLOG_NCIHAL_D("phNxpNciHal_close is already closed, ignoring close");
    return NFCSTATUS_FAILED;
  }

  CONCURRENCY_LOCK();
  phNxpNciHal_sendRfEvtToEseHal(0x00);
  if (nfcFL.nfccFL._NFCC_I2C_READ_WRITE_IMPROVEMENT &&
          read_failed_disable_nfc) {
      read_failed_disable_nfc = false;
      goto close_and_return;
  }

  if (write_unlocked_status == NFCSTATUS_FAILED) {
    NXPLOG_NCIHAL_D("phNxpNciHal_close i2c write failed .Clean and Return");
    goto close_and_return;
  }

  int sem_val;
  sem_getvalue(&(nxpncihal_ctrl.syncSpiNfc), &sem_val);
  if (sem_val == 0) {
    sem_post(&(nxpncihal_ctrl.syncSpiNfc));
  }
  if (!bShutdown) {
    status = phNxpNciHal_send_ext_cmd(sizeof(cmd_ven_disable_nci),
                                      cmd_ven_disable_nci);
    if (status != NFCSTATUS_SUCCESS) {
      NXPLOG_NCIHAL_E("CMD_VEN_DISABLE_NCI: Failed");
    }
  }

#ifdef FactoryOTA
  char valueStr[PROPERTY_VALUE_MAX] = {0};
  bool factoryOTA_terminate = false;
  int len = property_get("persist.factoryota.reboot", valueStr, "normal");
  if (len > 0) {
    factoryOTA_terminate = (len == 9 && (memcmp(valueStr, "terminate", len) == 0)) ? true : false;
  }
  NXPLOG_NCIHAL_D("factoryOTA_terminate: %d", factoryOTA_terminate);
  if (factoryOTA_terminate) {
    phNxpNciHal_disableFactoryOTAMode();
    phNxpNciHal_isFactoryOTAModeActive();
  }
#endif

  if (GetNxpNumValue(NAME_NXP_CORE_PWR_OFF_AUTONOMOUS_ENABLE, &num, sizeof(num))) {
    NXPLOG_NCIHAL_D("Power shutdown with autonomous mode status: %lu", num);
  }
  nxpncihal_ctrl.halStatus = HAL_STATUS_CLOSE;

  if (bShutdown && (num == 0x01) ) {
    NXPLOG_NCIHAL_D("Power shutdown with autonomous mode enable");
    static uint8_t coreStandBy[] = {0x2F, 0x00, 0x01, 0x02};
    status = phNxpNciHal_send_ext_cmd(sizeof(coreStandBy), coreStandBy);

    if (status != NFCSTATUS_SUCCESS) {
      NXPLOG_NCIHAL_E("NXP Standby Proprietary Ext failed");
    }
  } else {
    status =
        phNxpNciHal_send_ext_cmd(sizeof(cmd_core_reset_nci), cmd_core_reset_nci);
    if (status != NFCSTATUS_SUCCESS) {
      NXPLOG_NCIHAL_E("NCI_CORE_RESET: Failed");
    }
  }

  sem_destroy(&nxpncihal_ctrl.syncSpiNfc);

  if (gParserCreated) {
    phNxpNciHal_deinitParser();
    gParserCreated = FALSE;
  }
close_and_return:

  if (NULL != gpphTmlNfc_Context->pDevHandle) {
    phNxpNciHal_close_complete(NFCSTATUS_SUCCESS);
    /* Abort any pending read and write */
    status = phTmlNfc_ReadAbort();

    status = phTmlNfc_WriteAbort();

    phOsalNfc_Timer_Cleanup();

    status = phTmlNfc_Shutdown();

    if (0 != pthread_join(nxpncihal_ctrl.client_thread, (void **)NULL)) {
      NXPLOG_TML_E("Fail to kill client thread!");
    }

    phTmlNfc_CleanUp();

    phDal4Nfc_msgrelease(nxpncihal_ctrl.gDrvCfg.nClientId);

    memset(&nxpncihal_ctrl, 0x00, sizeof(nxpncihal_ctrl));

    NXPLOG_NCIHAL_D("phNxpNciHal_close - phOsalNfc_DeInit completed");
  }

  CONCURRENCY_UNLOCK();

  phNxpNciHal_cleanup_monitor();
  write_unlocked_status = NFCSTATUS_SUCCESS;
  phNxpNciHal_release_info();
  /* reset config cache */
  resetNxpConfig();
  /* Return success always */
  return NFCSTATUS_SUCCESS;
}

/******************************************************************************
 * Function         phNxpNciHal_Minclose
 *
 * Description      This function close the NFCC interface and free all
 *                  resources.This is called by libnfc-nci on NFC service stop.
 *
 * Returns          Always return NFCSTATUS_SUCCESS (0).
 *
 ******************************************************************************/
int phNxpNciHal_Minclose(void) {
  NFCSTATUS status;
  /*NCI_RESET_CMD*/
  uint8_t cmd_reset_nci[] = {0x20, 0x00, 0x01, 0x00};
  CONCURRENCY_LOCK();
  nxpncihal_ctrl.halStatus = HAL_STATUS_CLOSE;
  status = phNxpNciHal_send_ext_cmd(sizeof(cmd_reset_nci), cmd_reset_nci);
  if (status != NFCSTATUS_SUCCESS) {
    NXPLOG_NCIHAL_E("NCI_CORE_RESET: Failed");
  }
  sem_destroy(&nxpncihal_ctrl.syncSpiNfc);
  if (NULL != gpphTmlNfc_Context->pDevHandle) {
    phNxpNciHal_close_complete(NFCSTATUS_SUCCESS);
    /* Abort any pending read and write */
    status = phTmlNfc_ReadAbort();
    status = phTmlNfc_WriteAbort();

    phOsalNfc_Timer_Cleanup();

    status = phTmlNfc_Shutdown();

    if (0 != pthread_join(nxpncihal_ctrl.client_thread, (void **)NULL)) {
      NXPLOG_TML_E("Fail to kill client thread!");
    }

    phTmlNfc_CleanUp();

    phDal4Nfc_msgrelease(nxpncihal_ctrl.gDrvCfg.nClientId);

    memset(&nxpncihal_ctrl, 0x00, sizeof(nxpncihal_ctrl));

    NXPLOG_NCIHAL_D("phNxpNciHal_close - phOsalNfc_DeInit completed");
  }

  CONCURRENCY_UNLOCK();

  phNxpNciHal_cleanup_monitor();

  write_unlocked_status = NFCSTATUS_SUCCESS;
  phNxpNciHal_release_info();
  /* reset config cache */
  resetNxpConfig();
  /* Return success always */
  return NFCSTATUS_SUCCESS;
}
/******************************************************************************
 * Function         phNxpNciHal_close_complete
 *
 * Description      This function inform libnfc-nci about result of
 *                  phNxpNciHal_close.
 *
 * Returns          void.
 *
 ******************************************************************************/
void phNxpNciHal_close_complete(NFCSTATUS status) {
  static phLibNfc_Message_t msg;

  if (status == NFCSTATUS_SUCCESS) {
    msg.eMsgType = NCI_HAL_CLOSE_CPLT_MSG;
  } else {
    msg.eMsgType = NCI_HAL_ERROR_MSG;
  }
  msg.pMsgData = NULL;
  msg.Size = 0;

  phTmlNfc_DeferredCall(gpphTmlNfc_Context->dwCallbackThreadId, &msg);

  return;
}

/******************************************************************************
 * Function         phNxpNciHal_configDiscShutdown
 *
 * Description      Enable the CE and VEN config during shutdown.
 *
 * Returns          Always return NFCSTATUS_SUCCESS (0).
 *
 ******************************************************************************/
int phNxpNciHal_configDiscShutdown(void) {
  NFCSTATUS status;

  status = phNxpNciHal_close(true);
  if(status != NFCSTATUS_SUCCESS) {
    NXPLOG_NCIHAL_E("NCI_HAL_CLOSE: Failed");
  }

  /* Return success always */
  return NFCSTATUS_SUCCESS;
}

/******************************************************************************
 * Function         phNxpNciHal_getNxp
 *
 * Description      This function can be used by HAL to inform
 *                 to update vendor configuration parametres
 *
 * Returns          void.
 *
 ******************************************************************************/
 void phNxpNciHal_getNxpConfig(phNxpNfcHalConfig *pNxpNfcHalConfig) {
   unsigned long num = 0;
   long retlen = 0;
   uint8_t *buffer = NULL;
   long bufflen = 260;

   buffer = (uint8_t *)malloc(bufflen * sizeof(uint8_t));
  memset(pNxpNfcHalConfig, 0x00, sizeof(phNxpNfcHalConfig));
   if (GetNxpNumValue(NAME_NXP_ESE_LISTEN_TECH_MASK, &num, sizeof(num))) {
    pNxpNfcHalConfig->ese_listen_tech_mask = num;
   }else {
    pNxpNfcHalConfig->ese_listen_tech_mask = 0x07;
   }
   if (GetNxpNumValue(NAME_NXP_DEFAULT_NFCEE_DISC_TIMEOUT, &num, sizeof(num))) {
    pNxpNfcHalConfig->default_nfcee_disc_timeout = num;
   }
   if (GetNxpNumValue(NAME_NXP_DEFAULT_NFCEE_TIMEOUT, &num, sizeof(num))) {
    pNxpNfcHalConfig->default_nfcee_timeout = num;
   }
   if (GetNxpNumValue(NAME_NXP_ESE_WIRED_PRT_MASK, &num, sizeof(num))) {
    pNxpNfcHalConfig->ese_wired_prt_mask = num;
   }
   if (GetNxpNumValue(NAME_NXP_UICC_WIRED_PRT_MASK, &num, sizeof(num))) {
    pNxpNfcHalConfig->uicc_wired_prt_mask = num;
   }
   if (GetNxpNumValue(NAME_NXP_WIRED_MODE_RF_FIELD_ENABLE, &num, sizeof(num))) {
    pNxpNfcHalConfig->wired_mode_rf_field_enable = num;
   }
   if (GetNxpNumValue(NAME_AID_BLOCK_ROUTE, &num, sizeof(num))) {
    pNxpNfcHalConfig->aid_block_route = num;
   }
   if (GetNxpNumValue(NAME_NXP_ESE_POWER_DH_CONTROL, &num, sizeof(num))) {
    pNxpNfcHalConfig->esePowerDhControl = num;
   }
   if (GetNxpNumValue(NAME_NXP_SWP_RD_TAG_OP_TIMEOUT, &num, sizeof(num))) {
    pNxpNfcHalConfig->tagOpTimeout = num;
   }
   if (GetNxpNumValue(NAME_NXP_LOADER_SERICE_VERSION, &num, sizeof(num))) {
    pNxpNfcHalConfig->loaderServiceVersion = num;
   }
   if (GetNxpNumValue(NAME_NXP_DEFAULT_NFCEE_DISC_TIMEOUT, &num, sizeof(num))) {
    pNxpNfcHalConfig->defaultNfceeDiscTimeout = num;
   }
   if (GetNxpNumValue(NAME_NXP_DUAL_UICC_ENABLE, &num, sizeof(num))) {
    pNxpNfcHalConfig->dualUiccEnable = num;
   }
   if (GetNxpNumValue(NAME_NXP_CE_ROUTE_STRICT_DISABLE, &num, sizeof(num))) {
    pNxpNfcHalConfig->ceRouteStrictDisable = num;
   }
   if (GetNxpNumValue(NAME_OS_DOWNLOAD_TIMEOUT_VALUE, &num, sizeof(num))) {
    pNxpNfcHalConfig->osDownloadTimeoutValue = num;
   }
   if (GetNxpNumValue(NAME_DEFAULT_AID_ROUTE, &num, sizeof(num))) {
    pNxpNfcHalConfig->defaultAidRoute = num;
   }
   if (GetNxpNumValue(NAME_DEFAULT_AID_PWR_STATE, &num, sizeof(num))) {
    pNxpNfcHalConfig->defaultAidPwrState = num;
   }
   if (GetNxpNumValue(NAME_DEFAULT_ISODEP_PWR_STATE, &num, sizeof(num))) {
    pNxpNfcHalConfig->defaultRoutePwrState = num;
   }
   if (GetNxpNumValue(NAME_DEFAULT_OFFHOST_PWR_STATE, &num, sizeof(num))) {
    pNxpNfcHalConfig->defaultOffHostPwrState = num;
   }
   if (GetNxpNumValue(NAME_NXP_JCOPDL_AT_BOOT_ENABLE, &num, sizeof(num))) {
    pNxpNfcHalConfig->jcopDlAtBootEnable = num;
   }
   if (GetNxpNumValue(NAME_NXP_DEFAULT_NFCEE_TIMEOUT, &num, sizeof(num))) {
    pNxpNfcHalConfig->defaultNfceeTimeout = num;
   }
   if (GetNxpNumValue(NAME_NXP_NFC_CHIP, &num, sizeof(num))) {
    pNxpNfcHalConfig->nxpNfcChip = num;
   }
   if (GetNxpNumValue(NAME_NXP_CORE_SCRN_OFF_AUTONOMOUS_ENABLE, &num,
                      sizeof(num))) {
    pNxpNfcHalConfig->coreScrnOffAutonomousEnable = num;
   }
   if (GetNxpNumValue(NAME_NXP_ESE_LS_DEFAULT_INTERFACE, &num, sizeof(num))) {
    pNxpNfcHalConfig->p61LsDefaultInterface = num;
   }
   if (GetNxpNumValue(NAME_NXP_ESE_JCOP_DEFAULT_INTERFACE, &num, sizeof(num))) {
    pNxpNfcHalConfig->p61JcopDefaultInterface = num;
   }
   if (GetNxpNumValue(NAME_NXP_AGC_DEBUG_ENABLE, &num, sizeof(num))) {
    pNxpNfcHalConfig->agcDebugEnable = num;
   }
   if (GetNxpNumValue(NAME_DEFAULT_NFCF_PWR_STATE, &num, sizeof(num))) {
    pNxpNfcHalConfig->felicaCltPowerState = num;
   } else {
    pNxpNfcHalConfig->felicaCltPowerState = 0x3F;
   }
   if (GetNxpNumValue(NAME_NXP_HCEF_CMD_RSP_TIMEOUT_VALUE, &num, sizeof(num))) {
    pNxpNfcHalConfig->cmdRspTimeoutValue = num;
   }
   if (GetNxpNumValue(NAME_CHECK_DEFAULT_PROTO_SE_ID, &num, sizeof(num))) {
    pNxpNfcHalConfig->checkDefaultProtoSeId = num;
   }
   if (GetNxpNumValue(NAME_NXP_NFCC_PASSIVE_LISTEN_TIMEOUT, &num, sizeof(num))) {
    pNxpNfcHalConfig->nfccPassiveListenTimeout = num;
   }
   if (GetNxpNumValue(NAME_NXP_NFCC_STANDBY_TIMEOUT, &num, sizeof(num))) {
    pNxpNfcHalConfig->nfccStandbyTimeout = num;
   }
   if (GetNxpNumValue(NAME_NXP_WM_MAX_WTX_COUNT, &num, sizeof(num))) {
    pNxpNfcHalConfig->wmMaxWtxCount = num;
   }
   if (GetNxpNumValue(NAME_NXP_NFCC_RF_FIELD_EVENT_TIMEOUT, &num, sizeof(num))) {
    pNxpNfcHalConfig->nfccRfFieldEventTimeout = num;
   }
   if (GetNxpNumValue(NAME_NXP_ALLOW_WIRED_IN_MIFARE_DESFIRE_CLT, &num,
                      sizeof(num))) {
    pNxpNfcHalConfig->allowWiredInMifareDesfireClt = num;
   }
   if (GetNxpNumValue(NAME_NXP_DWP_INTF_RESET_ENABLE, &num, sizeof(num))) {
    pNxpNfcHalConfig->dwpIntfResetEnable = num;
   }
   if (GetNxpNumValue(NAME_NXPLOG_HAL_LOGLEVEL, &num, sizeof(num))) {
    pNxpNfcHalConfig->nxpLogHalLoglevel = num;
   }
   if (GetNxpNumValue(NAME_NXPLOG_EXTNS_LOGLEVEL, &num, sizeof(num))) {
    pNxpNfcHalConfig->nxpLogExtnsLogLevel = num;
   }
   if (GetNxpNumValue(NAME_NXPLOG_TML_LOGLEVEL, &num, sizeof(num))) {
    pNxpNfcHalConfig->nxpLogTmlLogLevel = num;
   }
   if (GetNxpNumValue(NAME_NXPLOG_FWDNLD_LOGLEVEL, &num, sizeof(num))) {
    pNxpNfcHalConfig->nxpLogFwDnldLogLevel = num;
   }
   if (GetNxpNumValue(NAME_NXPLOG_NCIX_LOGLEVEL, &num, sizeof(num))) {
    pNxpNfcHalConfig->nxpLogNcixLogLevel = num;
   }
   if (GetNxpNumValue(NAME_NXPLOG_NCIR_LOGLEVEL, &num, sizeof(num))) {
    pNxpNfcHalConfig->nxpLogNcirLogLevel = num;
   }
   if (GetNxpNumValue(NAME_NFA_CONFIG_FORMAT, &num, sizeof(num))) {
    pNxpNfcHalConfig->scrCfgFormat = num;
   }
   if (GetNxpNumValue(NAME_ETSI_READER_ENABLE, &num, sizeof(num))) {
    pNxpNfcHalConfig->etsiReaderEnable = num;
   }
   if (GetNxpNumValue(NAME_DEFAULT_TECH_ABF_ROUTE, &num, sizeof(num))) {
    pNxpNfcHalConfig->techAbfRoute = num;
   }
   if (GetNxpNumValue(NAME_DEFAULT_TECH_ABF_PWR_STATE, &num, sizeof(num))) {
    pNxpNfcHalConfig->techAbfPwrState = num;
   }
   if (GetNxpNumValue(NAME_WTAG_SUPPORT, &num, sizeof(num))) {
    pNxpNfcHalConfig->wTagSupport = num;
   }
   if (GetNxpNumValue(NAME_DEFAULT_T4TNFCEE_AID_POWER_STATE, &num, sizeof(num))) {
    pNxpNfcHalConfig->t4tNfceePwrState = num;
   } else {
     //sete Default power state as Phone off (Low power mode)
    pNxpNfcHalConfig->t4tNfceePwrState = 0x02;
   }
   if (buffer) {
     if (GetNxpByteArrayValue(NAME_NXP_PROP_RESET_EMVCO_CMD, (char *)buffer,
                              bufflen, &retlen)) {
      memcpy(pNxpNfcHalConfig->scrResetEmvco.cmd, (char *)buffer,
              retlen);
      pNxpNfcHalConfig->scrResetEmvco.len = retlen;
    }
    free(buffer);
    buffer = NULL;
  }
}

/******************************************************************************
 * Function         phNxpNciHal_getNxpTransitConfig
 *
 * Description      This function overwrite libnfc-nxpTransit.conf file
 *                  with transitConfValue.
 *
 * Returns          void.
 *
 ******************************************************************************/
bool phNxpNciHal_setNxpTransitConfig(char *transitConfValue) {
  bool status = true;
  NXPLOG_NCIHAL_D("%s : Enter", __func__);
  std::string transitConfFileName = "/data/vendor/nfc/libnfc-nxpTransit.conf";
  if (transitConfValue != NULL) {
    if (!WriteStringToFile(transitConfValue, transitConfFileName)) {
      status = false;
      NXPLOG_NCIHAL_D("Failed to write transit values in the config values");
    }
  } else {
    if (remove(transitConfFileName.c_str())) {
      status = false;
      NXPLOG_NCIHAL_D("File deletion failed");
    }
  }
  NXPLOG_NCIHAL_D("%s : Exit", __func__);
  return status;
}
/******************************************************************************
 * Function         phNxpNciHal_getVendorConfig
 *
 * Description      This function can be used by HAL to inform
 *                 to update vendor configuration parametres
 *
 * Returns          void.
 *
 ******************************************************************************/
void phNxpNciHal_getVendorConfig(
    android::hardware::nfc::V1_1::NfcConfig &config) {
  unsigned long num = 0;
  std::array<uint8_t, NXP_MAX_CONFIG_STRING_LEN> buffer;
  buffer.fill(0);
  long retlen = 0;
  memset(&config, 0x00, sizeof(android::hardware::nfc::V1_1::NfcConfig));

  if (GetNxpNumValue(NAME_ISO_DEP_MAX_TRANSCEIVE, &num, sizeof(num))) {
    config.maxIsoDepTransceiveLength = num;
  }
  if (GetNxpNumValue(NAME_NFA_POLL_BAIL_OUT_MODE, &num, sizeof(num))
       && (num == 1)) {
    config.nfaPollBailOutMode = true;
  }
  if (GetNxpNumValue(NAME_DEFAULT_OFFHOST_ROUTE, &num, sizeof(num))) {
    config.defaultOffHostRoute = num;
  }
  if (GetNxpNumValue(NAME_DEFAULT_NFCF_ROUTE, &num, sizeof(num))) {
    config.defaultOffHostRouteFelica = num;
  }
  if (GetNxpNumValue(NAME_DEFAULT_SYS_CODE_ROUTE, &num, sizeof(num))) {
    config.defaultSystemCodeRoute = num;
  }
  if (GetNxpNumValue(NAME_DEFAULT_SYS_CODE_PWR_STATE, &num, sizeof(num))) {
    config.defaultSystemCodePowerState = num;
  }
  if (GetNxpNumValue(NAME_DEFAULT_ROUTE, &num, sizeof(num))) {
    config.defaultRoute = num;
  }
  if (GetNxpByteArrayValue(NAME_DEVICE_HOST_WHITE_LIST, (char*)buffer.data(),
                           buffer.size(), &retlen)) {
    config.hostWhitelist.resize(retlen);
    for (int i = 0; i < retlen; i++) config.hostWhitelist[i] = buffer[i];
  }
  if (GetNxpNumValue(NAME_OFF_HOST_ESE_PIPE_ID, &num, sizeof(num))) {
    config.offHostESEPipeId = num;
  }
  if (GetNxpNumValue(NAME_OFF_HOST_SIM_PIPE_ID, &num, sizeof(num))) {
    config.offHostSIMPipeId = num;
  }
  if ((GetNxpByteArrayValue(NAME_NFA_PROPRIETARY_CFG, (char*)buffer.data(), buffer.size(), &retlen))
         && (retlen == 9)) {
    config.nfaProprietaryCfg.protocol18092Active = (uint8_t) buffer[0];
    config.nfaProprietaryCfg.protocolBPrime = (uint8_t) buffer[1];
    config.nfaProprietaryCfg.protocolDual = (uint8_t) buffer[2];
    config.nfaProprietaryCfg.protocol15693 = (uint8_t) buffer[3];
    config.nfaProprietaryCfg.protocolKovio = (uint8_t) buffer[4];
    config.nfaProprietaryCfg.protocolMifare = (uint8_t) buffer[5];
    config.nfaProprietaryCfg.discoveryPollKovio = (uint8_t) buffer[6];
    config.nfaProprietaryCfg.discoveryPollBPrime = (uint8_t) buffer[7];
    config.nfaProprietaryCfg.discoveryListenBPrime = (uint8_t) buffer[8];
  } else {
    memset(&config.nfaProprietaryCfg, 0xFF, sizeof(ProtocolDiscoveryConfig));
  }
  if ((GetNxpNumValue(NAME_PRESENCE_CHECK_ALGORITHM, &num, sizeof(num))) && (num <= 2) ) {
      config.presenceCheckAlgorithm = (PresenceCheckAlgorithm)num;
  }
}

/******************************************************************************
 * Function         phNxpNciHal_getVendorConfig_1_2
 *
 * Description      This function can be used by HAL to inform
 *                 to update vendor configuration parametres
 *
 * Returns          void.
 *
 ******************************************************************************/

void phNxpNciHal_getVendorConfig_1_2(
    android::hardware::nfc::V1_2::NfcConfig &config) {
  unsigned long num = 0;
  std::array<uint8_t, NXP_MAX_CONFIG_STRING_LEN> buffer;
  buffer.fill(0);
  long retlen = 0;
  memset(&config, 0x00, sizeof(android::hardware::nfc::V1_2::NfcConfig));
  phNxpNciHal_getVendorConfig(config.v1_1);

  if (GetNxpByteArrayValue(NAME_OFFHOST_ROUTE_UICC, (char *)buffer.data(),
                           buffer.size(), &retlen)) {
    config.offHostRouteUicc.resize(retlen);
    for (int i = 0; i < retlen; i++)
      config.offHostRouteUicc[i] = buffer[i];
  }

  if (GetNxpByteArrayValue(NAME_OFFHOST_ROUTE_ESE, (char *)buffer.data(),
                           buffer.size(), &retlen)) {
    config.offHostRouteEse.resize(retlen);
    for (int i = 0; i < retlen; i++)
      config.offHostRouteEse[i] = buffer[i];
  }

  if ((GetNxpNumValue(NAME_DEFAULT_ISODEP_ROUTE, &num, sizeof(num))) &&
      (num <= 2)) {
    config.defaultIsoDepRoute = num;
  }
}

/******************************************************************************
 * Function         phNxpNciHal_notify_i2c_fragmentation
 *
 * Description      This function can be used by HAL to inform
 *                 libnfc-nci that i2c fragmentation is enabled/disabled
 *
 * Returns          void.
 *
 ******************************************************************************/
void phNxpNciHal_notify_i2c_fragmentation(void) {
  if (nxpncihal_ctrl.p_nfc_stack_cback != NULL) {
    /*inform libnfc-nci that i2c fragmentation is enabled/disabled */
    (*nxpncihal_ctrl.p_nfc_stack_cback)(HAL_NFC_ENABLE_I2C_FRAGMENTATION_EVT,
                                        HAL_NFC_STATUS_OK);
  }
}
/******************************************************************************
 * Function         phNxpNciHal_control_granted
 *
 * Description      Called by libnfc-nci when NFCC control is granted to HAL.
 *
 * Returns          Always returns NFCSTATUS_SUCCESS (0).
 *
 ******************************************************************************/
int phNxpNciHal_control_granted(void) {
  /* Take the concurrency lock so no other calls from upper layer
   * will be allowed
   */
  CONCURRENCY_LOCK();

  if (NULL != nxpncihal_ctrl.p_control_granted_cback) {
    (*nxpncihal_ctrl.p_control_granted_cback)();
  }
  /* At the end concurrency unlock so calls from upper layer will
   * be allowed
   */
  CONCURRENCY_UNLOCK();
  return NFCSTATUS_SUCCESS;
}

/******************************************************************************
 * Function         phNxpNciHal_request_control
 *
 * Description      This function can be used by HAL to request control of
 *                  NFCC to libnfc-nci. When control is provided to HAL it is
 *                  notified through phNxpNciHal_control_granted.
 *
 * Returns          void.
 *
 ******************************************************************************/
void phNxpNciHal_request_control(void) {
  if (nxpncihal_ctrl.p_nfc_stack_cback != NULL) {
    /* Request Control of NCI Controller from NCI NFC Stack */
    (*nxpncihal_ctrl.p_nfc_stack_cback)(HAL_NFC_REQUEST_CONTROL_EVT,
                                        HAL_NFC_STATUS_OK);
  }

  return;
}

/******************************************************************************
 * Function         phNxpNciHal_release_control
 *
 * Description      This function can be used by HAL to release the control of
 *                  NFCC back to libnfc-nci.
 *
 * Returns          void.
 *
 ******************************************************************************/
void phNxpNciHal_release_control(void) {
  if (nxpncihal_ctrl.p_nfc_stack_cback != NULL) {
    /* Release Control of NCI Controller to NCI NFC Stack */
    (*nxpncihal_ctrl.p_nfc_stack_cback)(HAL_NFC_RELEASE_CONTROL_EVT,
                                        HAL_NFC_STATUS_OK);
  }

  return;
}

/******************************************************************************
 * Function         phNxpNciHal_power_cycle
 *
 * Description      This function is called by libnfc-nci when power cycling is
 *                  performed. When processing is complete it is notified to
 *                  libnfc-nci through phNxpNciHal_power_cycle_complete.
 *
 * Returns          Always return NFCSTATUS_SUCCESS (0).
 *
 ******************************************************************************/
int phNxpNciHal_power_cycle(void) {
  NXPLOG_NCIHAL_D("Power Cycle");
  NFCSTATUS status = NFCSTATUS_FAILED;
  if (nxpncihal_ctrl.halStatus != HAL_STATUS_OPEN) {
    NXPLOG_NCIHAL_D("Power Cycle failed due to hal status not open");
    return NFCSTATUS_FAILED;
  }
  status = phTmlNfc_IoCtl(phTmlNfc_e_ResetDevice);

  if (NFCSTATUS_SUCCESS == status) {
    NXPLOG_NCIHAL_D("PN54X Reset - SUCCESS\n");
  } else {
    NXPLOG_NCIHAL_D("PN54X Reset - FAILED\n");
  }

  phNxpNciHal_power_cycle_complete(NFCSTATUS_SUCCESS);
  return NFCSTATUS_SUCCESS;
}

/******************************************************************************
 * Function         phNxpNciHal_power_cycle_complete
 *
 * Description      This function is called to provide the status of
 *                  phNxpNciHal_power_cycle to libnfc-nci through callback.
 *
 * Returns          return 0 on success and -1 on fail.
 *
 ******************************************************************************/
static void phNxpNciHal_power_cycle_complete(NFCSTATUS status) {
  static phLibNfc_Message_t msg;

  if (status == NFCSTATUS_SUCCESS) {
    msg.eMsgType = NCI_HAL_OPEN_CPLT_MSG;
  } else {
    msg.eMsgType = NCI_HAL_ERROR_MSG;
  }
  msg.pMsgData = NULL;
  msg.Size = 0;

  phTmlNfc_DeferredCall(gpphTmlNfc_Context->dwCallbackThreadId, &msg);

  return;
}

/******************************************************************************
* Function         phNxpNciHal_check_ncicmd_write_window
*
* Description      This function is called to check the write synchroniztion
*                  status if write already aquired then wait for corresponding
*                   read to complete.
*
* Returns          void.
*
******************************************************************************/

int phNxpNciHal_check_ncicmd_write_window(uint16_t cmd_len, uint8_t* p_cmd) {
  UNUSED(cmd_len);
  NFCSTATUS status = NFCSTATUS_FAILED;
  int sem_timedout = 2, s;
  struct timespec ts;

  if (cmd_len < 1) {
    android_errorWriteLog(0x534e4554, "153880357");
    return NFCSTATUS_FAILED;
  }

  if ((p_cmd[0] & 0xF0) == 0x20) {
    clock_gettime(CLOCK_REALTIME, &ts);
    ts.tv_sec += sem_timedout;
    while ((s = sem_timedwait(&nxpncihal_ctrl.syncSpiNfc, &ts)) == -1 &&
           errno == EINTR)
      continue; /* Restart if interrupted by handler */

    if (s == -1) {
      if (errno == ETIMEDOUT)
        ALOGD_IF(nfc_debug_enabled, "sem_timedwait() timed out");
      else
        ALOGD_IF(nfc_debug_enabled, "sem_timedwait");
    } else {
      ALOGD_IF(nfc_debug_enabled, "sem_timedwait() succeeded");
      status = NFCSTATUS_SUCCESS;
    }
  }
  else {
    /* cmd window check not required for writing data packet */
    status = NFCSTATUS_SUCCESS;
   }
  return status;
}

void phNxpNciHal_MinCloseForOmapiClose(phNxpNci_Extn_Cmd_t *inp) {
  if ((nxpncihal_ctrl.halStatus == HAL_STATUS_MIN_OPEN) &&
      (inp->p_cmd[0] == 0x2F) &&
      (inp->p_cmd[1] == 0x01) &&
      (inp->p_cmd[3] == 0x00)) {
    phNxpNciHal_Minclose();
  }
}
/******************************************************************************
 * Function         phNxpNciHal_ioctl
 *
 * Description      This function is called by jni when wired mode is
 *                  performed.First Pn54x driver will give the access
 *                  permission whether wired mode is allowed or not
 *                  arg (0):
 * Returns          return 0 on success and -1 on fail, On success
 *                  update the acutual state of operation in arg pointer
 *
 ******************************************************************************/
int phNxpNciHal_ioctl(long arg, void* p_data) {
  NXPLOG_NCIHAL_D("%s : enter - arg = %ld", __func__, arg);
  ese_nxp_IoctlInOutData_t* pInpOutData = (ese_nxp_IoctlInOutData_t*)p_data;
  int ret = -1;
  if (nxpncihal_ctrl.halStatus == HAL_STATUS_CLOSE &&
    (arg != HAL_ESE_IOCTL_NFC_JCOP_DWNLD)) {
    NFCSTATUS status = NFCSTATUS_FAILED;
    status = phNxpNciHal_MinOpen();
    if (status != NFCSTATUS_SUCCESS) {
      return -1;
    }
  }
  switch (arg) {
    case HAL_ESE_IOCTL_NFC_JCOP_DWNLD :
        NXPLOG_NCIHAL_D("HAL_ESE_IOCTL_NFC_JCOP_DWNLD Enter value is %d: \n",pInpOutData->inp.data.nxpCmd.p_cmd[0]);
        if(gpEseAdapt !=  NULL)
          ret = gpEseAdapt->HalIoctl(HAL_ESE_IOCTL_NFC_JCOP_DWNLD,pInpOutData);
        [[fallthrough]];
      default:
        NXPLOG_NCIHAL_E("%s : Wrong arg = %ld", __func__, arg);
        break;
  }
  NXPLOG_NCIHAL_D("%s : exit - ret = %d", __func__, ret);
  return ret;
}

/******************************************************************************
 * Function         phNxpNciHal_nfccClockCfgRead
 *
 * Description      This function is called for loading a data strcuture from
 *                  the config file with clock source and clock frequency values
 *
 * Returns          void.
 *
 ******************************************************************************/
static void phNxpNciHal_nfccClockCfgRead(void)
{
    unsigned long num = 0;
    int isfound = 0;

    nxpprofile_ctrl.bClkSrcVal = 0;
    nxpprofile_ctrl.bClkFreqVal = 0;
    nxpprofile_ctrl.bTimeout = 0;

    isfound = GetNxpNumValue(NAME_NXP_SYS_CLK_SRC_SEL, &num, sizeof(num));
    if (isfound > 0)
    {
        nxpprofile_ctrl.bClkSrcVal = num;
    }

    num = 0;
    isfound = 0;
    isfound = GetNxpNumValue(NAME_NXP_SYS_CLK_FREQ_SEL, &num, sizeof(num));
    if (isfound > 0)
    {
        nxpprofile_ctrl.bClkFreqVal = num;
    }

    num = 0;
    isfound = 0;
    isfound = GetNxpNumValue(NAME_NXP_SYS_CLOCK_TO_CFG, &num, sizeof(num));
    if (isfound > 0)
    {
        nxpprofile_ctrl.bTimeout = num;
    }

    NXPLOG_FWDNLD_D("gphNxpNciHal_fw_IoctlCtx.bClkSrcVal = 0x%x", nxpprofile_ctrl.bClkSrcVal);
    NXPLOG_FWDNLD_D("gphNxpNciHal_fw_IoctlCtx.bClkFreqVal = 0x%x", nxpprofile_ctrl.bClkFreqVal);
    NXPLOG_FWDNLD_D("gphNxpNciHal_fw_IoctlCtx.bClkFreqVal = 0x%x", nxpprofile_ctrl.bTimeout);

    if ((nxpprofile_ctrl.bClkSrcVal < CLK_SRC_XTAL) ||
            (nxpprofile_ctrl.bClkSrcVal > CLK_SRC_PLL))
    {
        NXPLOG_FWDNLD_E("Clock source value is wrong in config file, setting it as default");
        nxpprofile_ctrl.bClkSrcVal = NXP_SYS_CLK_SRC_SEL;
    }
    if ((nxpprofile_ctrl.bClkFreqVal < CLK_FREQ_13MHZ) ||
            (nxpprofile_ctrl.bClkFreqVal > CLK_FREQ_52MHZ))
    {
        NXPLOG_FWDNLD_E("Clock frequency value is wrong in config file, setting it as default");
        nxpprofile_ctrl.bClkFreqVal = NXP_SYS_CLK_FREQ_SEL;
    }
    if ((nxpprofile_ctrl.bTimeout < CLK_TO_CFG_DEF) || (nxpprofile_ctrl.bTimeout > CLK_TO_CFG_MAX))
    {
        NXPLOG_FWDNLD_E("Clock timeout value is wrong in config file, setting it as default");
        nxpprofile_ctrl.bTimeout = CLK_TO_CFG_DEF;
    }

}

/******************************************************************************
 * Function         phNxpNciHal_txNfccClockSetCmd
 *
 * Description      This function is called after successfull download
 *                  to apply the clock setting provided in config file
 *
 * Returns          void.
 *
 ******************************************************************************/
static void phNxpNciHal_txNfccClockSetCmd(void) {
  NFCSTATUS status = NFCSTATUS_FAILED;

if(nfcFL.chipType == pn553) {
    static uint8_t set_clock_cmd[] = {0x20, 0x02, 0x05, 0x01, 0xA0, 0x03, 0x01, 0x08};
    uint8_t setClkCmdLen = sizeof(set_clock_cmd);
    unsigned long  clockSource = 0;
    unsigned long frequency = 0;
    uint32_t pllSetRetryCount = 3, dpllSetRetryCount = 3,setClockCmdWriteRetryCnt = 0;
    uint8_t *pCmd4PllSetting = NULL;
    uint8_t *pCmd4DpllSetting = NULL;
    uint32_t pllCmdLen = 0, dpllCmdLen = 0;
    int srcCfgFound = 0, freqCfgFound = 0;

    srcCfgFound = (GetNxpNumValue(NAME_NXP_SYS_CLK_SRC_SEL, &clockSource, sizeof(clockSource)) > 0);

    freqCfgFound = (GetNxpNumValue(NAME_NXP_SYS_CLK_FREQ_SEL, &frequency, sizeof(frequency)) > 0);

    NXPLOG_NCIHAL_D("%s : clock source = %lu, frequency = %lu", __FUNCTION__, clockSource, frequency);

    if(srcCfgFound && freqCfgFound && (clockSource == CLK_SRC_PLL))
    {
         phNxpNciClock.isClockSet = TRUE;

        switch(frequency)
        {
            case CLK_FREQ_13MHZ:
            {
                NXPLOG_NCIHAL_D("PLL setting for CLK_FREQ_13MHZ");
                pCmd4PllSetting = (uint8_t*) SET_CONFIG_CMD_PLL_13MHZ;
                pllCmdLen = sizeof(SET_CONFIG_CMD_PLL_13MHZ);
                pCmd4DpllSetting = (uint8_t*) SET_CONFIG_CMD_DPLL_13MHZ;
                dpllCmdLen = sizeof(SET_CONFIG_CMD_DPLL_13MHZ);
                break;
            }
            case CLK_FREQ_19_2MHZ:
            {
                NXPLOG_NCIHAL_D("PLL setting for CLK_FREQ_19_2MHZ");
                pCmd4PllSetting = (uint8_t*)SET_CONFIG_CMD_PLL_19_2MHZ;
                pllCmdLen = sizeof(SET_CONFIG_CMD_PLL_19_2MHZ);
                pCmd4DpllSetting = (uint8_t*) SET_CONFIG_CMD_DPLL_19_2MHZ;
                dpllCmdLen = sizeof(SET_CONFIG_CMD_DPLL_19_2MHZ);
                break;
              }
            case CLK_FREQ_24MHZ:
            {
                NXPLOG_NCIHAL_D("PLL setting for CLK_FREQ_24MHZ");
                pCmd4PllSetting = (uint8_t*)SET_CONFIG_CMD_PLL_24MHZ;
                pllCmdLen = sizeof(SET_CONFIG_CMD_PLL_24MHZ);
                pCmd4DpllSetting = (uint8_t*) SET_CONFIG_CMD_DPLL_24MHZ;
                dpllCmdLen = sizeof(SET_CONFIG_CMD_DPLL_24MHZ);
                break;
            }
            case CLK_FREQ_26MHZ:
            {
                NXPLOG_NCIHAL_D("PLL setting for CLK_FREQ_26MHZ");
                pCmd4PllSetting = (uint8_t*)SET_CONFIG_CMD_PLL_26MHZ;
                pllCmdLen = sizeof(SET_CONFIG_CMD_PLL_26MHZ);
                pCmd4DpllSetting = (uint8_t*) SET_CONFIG_CMD_DPLL_26MHZ;
                dpllCmdLen = sizeof(SET_CONFIG_CMD_DPLL_26MHZ);
                break;
            }
            case CLK_FREQ_32MHZ:
            {
                NXPLOG_NCIHAL_D("PLL setting for CLK_FREQ_32MHZ");
                pCmd4PllSetting = (uint8_t*)SET_CONFIG_CMD_PLL_32MHZ;
                pllCmdLen = sizeof(SET_CONFIG_CMD_PLL_32MHZ);
                pCmd4DpllSetting = (uint8_t*) SET_CONFIG_CMD_DPLL_32MHZ;
                dpllCmdLen = sizeof(SET_CONFIG_CMD_DPLL_32MHZ);
                break;
            }
            case CLK_FREQ_38_4MHZ:
            {
                NXPLOG_NCIHAL_D("PLL setting for CLK_FREQ_38_4MHZ");
                pCmd4PllSetting = (uint8_t*)SET_CONFIG_CMD_PLL_38_4MHZ;
                pllCmdLen = sizeof(SET_CONFIG_CMD_PLL_38_4MHZ);
                pCmd4DpllSetting = (uint8_t*) SET_CONFIG_CMD_DPLL_38_4MHZ;
                dpllCmdLen = sizeof(SET_CONFIG_CMD_DPLL_38_4MHZ);
                break;
            }
            default:
                phNxpNciClock.isClockSet = FALSE;
                NXPLOG_NCIHAL_E("ERROR: Invalid clock frequency!!");
                return;
        }
    }
    switch(clockSource)
    {
        case CLK_SRC_PLL:
        {
            set_clock_cmd[setClkCmdLen -1] = 0x00;
            while(status != NFCSTATUS_SUCCESS && setClockCmdWriteRetryCnt++ < MAX_RETRY_COUNT)
            status = phNxpNciHal_send_ext_cmd(setClkCmdLen, set_clock_cmd);

            status = NFCSTATUS_FAILED;

            while(status != NFCSTATUS_SUCCESS && pllSetRetryCount -- > 0)
                status = phNxpNciHal_send_ext_cmd(pllCmdLen, pCmd4PllSetting);

            status = NFCSTATUS_FAILED;

            while(status != NFCSTATUS_SUCCESS && dpllSetRetryCount -- > 0)
                status = phNxpNciHal_send_ext_cmd(dpllCmdLen, pCmd4DpllSetting);

            break;
        }
        case CLK_SRC_XTAL:
        {
            status = phNxpNciHal_send_ext_cmd(setClkCmdLen, set_clock_cmd);
            if (status != NFCSTATUS_SUCCESS)
            {
                NXPLOG_NCIHAL_E("XTAL clock setting failed !!");
            }
            break;
        }
        default:
            NXPLOG_NCIHAL_E("Wrong clock source. Dont apply any modification");
            return;
    }
    phNxpNciClock.isClockSet = FALSE;
    if(status == NFCSTATUS_SUCCESS && phNxpNciClock.p_rx_data[3] == NFCSTATUS_SUCCESS)
    {
        NXPLOG_NCIHAL_D("PLL and DPLL settings applied successfully");
    }
    return;
}
else {
    NXPLOG_NCIHAL_D("Clock setting older version");
  }

int retryCount = 0;

retrySetclock:
  phNxpNciClock.isClockSet = true;
  if (nxpprofile_ctrl.bClkSrcVal == CLK_SRC_PLL) {
    static uint8_t set_clock_cmd[] = {0x20, 0x02, 0x09, 0x02, 0xA0, 0x03,
                                      0x01, 0x11, 0xA0, 0x04, 0x01, 0x01};
    uint8_t param_clock_src;

    param_clock_src = CLK_SRC_PLL;
    param_clock_src = param_clock_src << 3;

    if (nxpprofile_ctrl.bClkFreqVal == CLK_FREQ_13MHZ) {
      param_clock_src |= 0x00;
    } else if (nxpprofile_ctrl.bClkFreqVal == CLK_FREQ_19_2MHZ) {
      param_clock_src |= 0x01;
    } else if (nxpprofile_ctrl.bClkFreqVal == CLK_FREQ_24MHZ) {
      param_clock_src |= 0x02;
    } else if (nxpprofile_ctrl.bClkFreqVal == CLK_FREQ_26MHZ) {
      param_clock_src |= 0x03;
    } else if (nxpprofile_ctrl.bClkFreqVal == CLK_FREQ_38_4MHZ) {
      param_clock_src |= 0x04;
    } else if (nxpprofile_ctrl.bClkFreqVal == CLK_FREQ_52MHZ) {
      param_clock_src |= 0x05;
    } else {
      NXPLOG_NCIHAL_E("Wrong clock freq, send default PLL@19.2MHz");

      param_clock_src = 0x11;

    }

    set_clock_cmd[7] = param_clock_src;
    set_clock_cmd[11] = nxpprofile_ctrl.bTimeout;
    status = phNxpNciHal_send_ext_cmd(sizeof(set_clock_cmd), set_clock_cmd);
    if (status != NFCSTATUS_SUCCESS) {
      NXPLOG_NCIHAL_E("PLL colck setting failed !!");
    }
  } else if (nxpprofile_ctrl.bClkSrcVal == CLK_SRC_XTAL) {
    static uint8_t set_clock_cmd[] = {0x20, 0x02, 0x05, 0x01,
                                      0xA0, 0x03, 0x01, 0x08};
    status = phNxpNciHal_send_ext_cmd(sizeof(set_clock_cmd), set_clock_cmd);
    if (status != NFCSTATUS_SUCCESS) {
      NXPLOG_NCIHAL_E("XTAL colck setting failed !!");
    }
  } else {
    NXPLOG_NCIHAL_E("Wrong clock source. Dont apply any modification")
  }

  // Checking for SET CONFG SUCCESS, re-send the command  if not.
  phNxpNciClock.isClockSet = false;
  if (phNxpNciClock.p_rx_data[3] != NFCSTATUS_SUCCESS) {
    if (retryCount++ < 3) {
      NXPLOG_NCIHAL_D("Set-clk failed retry again ");
      goto retrySetclock;
    } else {
      NXPLOG_NCIHAL_E("Set clk  failed -  max count = 0x%x exceeded ",
                      retryCount);
      //            NXPLOG_NCIHAL_E("Set Config is failed for Clock Due to
      //            elctrical disturbances, aborting the NFC process");
      //            abort ();
    }
  }
}

/******************************************************************************
 * Function         phNxpNciHal_determineConfiguredClockSrc
 *
 * Description      This function determines and encodes clock source based on
 *                  clock frequency
 *
 * Returns          encoded form of clock source
 *
 *****************************************************************************/
int   phNxpNciHal_determineConfiguredClockSrc()
{
    uint8_t param_clock_src = CLK_SRC_PLL;
    if (nxpprofile_ctrl.bClkSrcVal == CLK_SRC_PLL)
    {

    if(nfcFL.chipType == pn553) {
        param_clock_src = param_clock_src << 3;
    }

        if (nxpprofile_ctrl.bClkFreqVal == CLK_FREQ_13MHZ)
        {
            param_clock_src |= 0x00;
        }
        else if (nxpprofile_ctrl.bClkFreqVal == CLK_FREQ_19_2MHZ)
        {
            param_clock_src |= 0x01;
        }
        else if (nxpprofile_ctrl.bClkFreqVal == CLK_FREQ_24MHZ)
        {
            param_clock_src |= 0x02;
        }
        else if (nxpprofile_ctrl.bClkFreqVal == CLK_FREQ_26MHZ)
        {
            param_clock_src |= 0x03;
        }
        else if (nxpprofile_ctrl.bClkFreqVal == CLK_FREQ_38_4MHZ)
        {
            param_clock_src |= 0x04;
        }
        else if (nxpprofile_ctrl.bClkFreqVal == CLK_FREQ_52MHZ)
        {
            param_clock_src |= 0x05;
        }
        else
        {
            NXPLOG_NCIHAL_E("Wrong clock freq, send default PLL@19.2MHz");
            param_clock_src = 0x11;
        }
    }
    else if(nxpprofile_ctrl.bClkSrcVal == CLK_SRC_XTAL)
    {
        param_clock_src = 0x08;

    }
    else
    {
        NXPLOG_NCIHAL_E("Wrong clock source. Dont apply any modification")
    }
    return param_clock_src;
  }

/******************************************************************************
 * Function         phNxpNciHal_nfccClockCfgApply
 *
 * Description      This function is called after successfull download
 *                  to check if clock settings in config file and chip
 *                  is same
 *
 * Returns          void.
 *
 ******************************************************************************/
NFCSTATUS phNxpNciHal_nfccClockCfgApply(void) {
  NFCSTATUS status = NFCSTATUS_SUCCESS;
  uint8_t nfcc_cfg_clock_src, nfcc_cur_clock_src;
  uint8_t nfcc_clock_set_needed;
  static uint8_t get_clock_cmd[] = {0x20, 0x03, 0x07, 0x03, 0xA0,
                                    0x02, 0xA0, 0x03, 0xA0, 0x04};
  phNxpNciHal_nfccClockCfgRead();
  phNxpNciClock.isClockSet = true;
  status = phNxpNciHal_send_ext_cmd(sizeof(get_clock_cmd), get_clock_cmd);
  phNxpNciClock.isClockSet = false;

  if (status != NFCSTATUS_SUCCESS) {
    NXPLOG_NCIHAL_E("unable to retrieve get_clk_src_sel");
    return status;
  }

  nfcc_cfg_clock_src = phNxpNciHal_determineConfiguredClockSrc();
  nfcc_cur_clock_src = phNxpNciClock.p_rx_data[12];

  nfcc_clock_set_needed = (nfcc_cfg_clock_src != nfcc_cur_clock_src ||
                              phNxpNciClock.p_rx_data[16] == nxpprofile_ctrl.bTimeout) ?\
                              true : false;
  if(nfcc_clock_set_needed) {
    NXPLOG_NCIHAL_D ("Setting Clock Source and Frequency");
    phNxpNciHal_txNfccClockSetCmd();
  }

  return status;
}

/******************************************************************************
 * Function         phNxpNciHal_set_china_region_configs
 *
 * Description      This function is called to set china region specific configs
 *
 * Returns          Status.
 *
 ******************************************************************************/
NFCSTATUS phNxpNciHal_set_china_region_configs(void) {
  NFCSTATUS status = NFCSTATUS_SUCCESS;
  int isfound = 0;
  unsigned long rf_enable = false;
  unsigned long cfg_blk_chk_enable = false;
  unsigned long cma_bypass_enable = false;
  int rf_val = 0;
  int flag_send_tianjin_config = true;
  int flag_send_transit_config = true;
  int flag_send_cmabypass_config = true;
  uint8_t retry_cnt = 0;
  int enable_bit = 0;
  int enable_blk_num_chk_bit = 0;
  static uint8_t get_rf_cmd[] = {0x20, 0x03, 0x03, 0x01, 0xA0, 0x85};
  NXPLOG_NCIHAL_D("phNxpNciHal_set_china_region_configs - Enter");

retry_send_ext:
  if (retry_cnt > 3) {
    return NFCSTATUS_FAILED;
  }

  phNxpNciRfSet.isGetRfSetting = true;
  status = phNxpNciHal_send_ext_cmd(sizeof(get_rf_cmd), get_rf_cmd);
  if (status != NFCSTATUS_SUCCESS) {
    NXPLOG_NCIHAL_E("unable to get the RF setting");
    phNxpNciRfSet.isGetRfSetting = false;
    retry_cnt++;
    goto retry_send_ext;
  }
  phNxpNciRfSet.isGetRfSetting = false;
  if (phNxpNciRfSet.p_rx_data[3] != 0x00) {
    NXPLOG_NCIHAL_E("GET_CONFIG_RSP is FAILED for CHINA TIANJIN");
    return status;
  }

  /* check if tianjin_rf_setting is required */
  rf_val = phNxpNciRfSet.p_rx_data[10];
  isfound = (GetNxpNumValue(NAME_NXP_CHINA_TIANJIN_RF_ENABLED,
                            (void*)&rf_enable, sizeof(rf_enable)));
  if (isfound > 0) {
      enable_bit = rf_val & 0x40;
      if(nfcFL.nfccFL._NFCC_MIFARE_TIANJIN) {
          if ((enable_bit != 0x40) && (rf_enable == 1)) {
              phNxpNciRfSet.p_rx_data[10] |= 0x40;  // Enable if it is disabled
          } else if ((enable_bit == 0x40) && (rf_enable == 0)) {
              phNxpNciRfSet.p_rx_data[10] &= 0xBF;  // Disable if it is Enabled
          } else {
              flag_send_tianjin_config = false;  // No need to change in RF setting
          }
      }
      else {
          enable_bit = phNxpNciRfSet.p_rx_data[11] & 0x10;
          if ((rf_enable == 1) && (enable_bit != 0x10)) {
              NXPLOG_NCIHAL_E("Setting Non-Mifare reader for china tianjin");
              phNxpNciRfSet.p_rx_data[11] |= 0x10;
          } else if ((rf_enable == 0) && (enable_bit == 0x10)) {
              NXPLOG_NCIHAL_E("Setting Non-Mifare reader for china tianjin");
              phNxpNciRfSet.p_rx_data[11] &= 0xEF;
          } else {
              flag_send_tianjin_config = false;
          }
      }
  }
  else {
    flag_send_tianjin_config = false;
  }
  /*check if china block number check is required*/
  rf_val = phNxpNciRfSet.p_rx_data[8];
  isfound =
      (GetNxpNumValue(NAME_NXP_CHINA_BLK_NUM_CHK_ENABLE,
                      (void*)&cfg_blk_chk_enable, sizeof(cfg_blk_chk_enable)));
  if (isfound > 0) {
    enable_blk_num_chk_bit = rf_val & 0x40;
    if ((enable_blk_num_chk_bit != 0x40) && (cfg_blk_chk_enable == 1)) {
      phNxpNciRfSet.p_rx_data[8] |= 0x40;  // Enable if it is disabled
    } else if ((enable_blk_num_chk_bit == 0x40) && (cfg_blk_chk_enable == 0)) {
      phNxpNciRfSet.p_rx_data[8] &= ~0x40;  // Disable if it is Enabled
    } else {
      flag_send_transit_config = false;  // No need to change in RF setting
    }
  }
  else
    {
        flag_send_transit_config = FALSE;  // No need to change in RF setting
    }

    isfound = (GetNxpNumValue(NAME_NXP_CN_TRANSIT_CMA_BYPASSMODE_ENABLE, (void *)&cma_bypass_enable, sizeof(cma_bypass_enable)));
    if(isfound >0) {
        if(cma_bypass_enable == 0 && ((phNxpNciRfSet.p_rx_data[10] & 0x80) == 0x80)) {
            NXPLOG_NCIHAL_D("Disable CMA_BYPASSMODE Supports EMVCo PICC Complaincy");
            phNxpNciRfSet.p_rx_data[10] &=~0x80;        //set 24th bit of RF MISC SETTING to 0 for EMVCo PICC Complaincy support
        }
        else if(cma_bypass_enable == 1 && ((phNxpNciRfSet.p_rx_data[10] & 0x80) == 0)) {
            NXPLOG_NCIHAL_D("Enable CMA_BYPASSMODE bypass the ISO14443-3A state machine from READY to ACTIVE and backward compatibility with MIfrae Reader ");
            phNxpNciRfSet.p_rx_data[10] |=0x80;        //set 24th bit of RF MISC SETTING to 1 for backward compatibility with MIfrae Reader
        }
        else {
            flag_send_cmabypass_config = FALSE;  // No need to change in RF setting
        }
    }
    else {
       flag_send_cmabypass_config = FALSE;
    }

  if (flag_send_tianjin_config || flag_send_transit_config || flag_send_cmabypass_config) {
    static uint8_t set_rf_cmd[] = {0x20, 0x02, 0x08, 0x01, 0xA0, 0x85,
                                   0x04, 0x50, 0x08, 0x68, 0x00};
    memcpy(&set_rf_cmd[4], &phNxpNciRfSet.p_rx_data[5], 7);
    status = phNxpNciHal_send_ext_cmd(sizeof(set_rf_cmd), set_rf_cmd);
    if (status != NFCSTATUS_SUCCESS) {
      NXPLOG_NCIHAL_E("unable to set the RF setting");
      retry_cnt++;
      goto retry_send_ext;
    }
  }

  return status;
}

/******************************************************************************
 * Function         phNxpNciHal_enable_i2c_fragmentation
 *
 * Description      This function is called to process the response status
 *                  and print the status byte.
 *
 * Returns          void.
 *
 ******************************************************************************/
__attribute__((unused)) void phNxpNciHal_enable_i2c_fragmentation() {
  NFCSTATUS status = NFCSTATUS_FAILED;
  static uint8_t fragmentation_enable_config_cmd[] = {0x20, 0x02, 0x05, 0x01,
                                                      0xA0, 0x05, 0x01, 0x10};
  unsigned long i2c_status = 0x00;
  unsigned long config_i2c_value = 0xff;
  /*NCI_RESET_CMD*/
  static uint8_t cmd_reset_nci[] = {0x20, 0x00, 0x01, 0x00};
  /*NCI_INIT_CMD*/
  static uint8_t cmd_init_nci[] = {0x20, 0x01, 0x00};
  static uint8_t cmd_init_nci2_0[] = {0x20,0x01,0x02,0x00,0x00};
  static uint8_t get_i2c_fragmentation_cmd[] = {0x20, 0x03, 0x03,
                                                0x01, 0xA0, 0x05};
  if (GetNxpNumValue(NAME_NXP_I2C_FRAGMENTATION_ENABLED, (void *)&i2c_status,
                     sizeof(i2c_status))) {
    NXPLOG_NCIHAL_D("NAME_NXP_I2C_FRAGMENTATION_ENABLED : %lu", i2c_status);
  }
  status = phNxpNciHal_send_ext_cmd(sizeof(get_i2c_fragmentation_cmd),
                                    get_i2c_fragmentation_cmd);
  if (status != NFCSTATUS_SUCCESS) {
    NXPLOG_NCIHAL_E("unable to retrieve  get_i2c_fragmentation_cmd");
  } else {
    if (nxpncihal_ctrl.p_rx_data[8] == 0x10) {
      config_i2c_value = 0x01;
      phNxpNciHal_notify_i2c_fragmentation();
      phTmlNfc_set_fragmentation_enabled(I2C_FRAGMENTATION_ENABLED);
    } else if (nxpncihal_ctrl.p_rx_data[8] == 0x00) {
      config_i2c_value = 0x00;
    }
    // if the value already matches, nothing to be done
    if (config_i2c_value != i2c_status) {
      if (i2c_status == 0x01) {
        /* NXP I2C fragmenation enabled*/
        status =
            phNxpNciHal_send_ext_cmd(sizeof(fragmentation_enable_config_cmd),
                                     fragmentation_enable_config_cmd);
        if (status != NFCSTATUS_SUCCESS) {
          NXPLOG_NCIHAL_E("NXP fragmentation enable failed");
        }
      } else if (i2c_status == 0x00 || config_i2c_value == 0xff) {
        fragmentation_enable_config_cmd[7] = 0x00;
        /* NXP I2C fragmentation disabled*/
        status =
            phNxpNciHal_send_ext_cmd(sizeof(fragmentation_enable_config_cmd),
                                     fragmentation_enable_config_cmd);
        if (status != NFCSTATUS_SUCCESS) {
          NXPLOG_NCIHAL_E("NXP fragmentation disable failed");
        }
      }
      status = phNxpNciHal_send_ext_cmd(sizeof(cmd_reset_nci), cmd_reset_nci);
      if (status != NFCSTATUS_SUCCESS) {
        NXPLOG_NCIHAL_E("NCI_CORE_RESET: Failed");
      }
      if (nxpncihal_ctrl.nci_info.nci_version == NCI_VERSION_2_0) {
        status = phNxpNciHal_send_ext_cmd(sizeof(cmd_init_nci2_0), cmd_init_nci2_0);
      } else {
        status = phNxpNciHal_send_ext_cmd(sizeof(cmd_init_nci), cmd_init_nci);
      }
      if (status != NFCSTATUS_SUCCESS) {
        NXPLOG_NCIHAL_E("NCI_CORE_INIT : Failed");
      } else if (i2c_status == 0x01) {
        phNxpNciHal_notify_i2c_fragmentation();
        phTmlNfc_set_fragmentation_enabled(I2C_FRAGMENTATION_ENABLED);
      }
    }
  }
}
/******************************************************************************
 * Function         phNxpNciHal_reset_nfcee_session
 *
 * Description      This function is called at init time to check
 *                  the presence of ese related info. If file are not
 *                  present set the SWP_INT_SESSION_ID_CFG to FF to
 *                  force the NFCEE to re-run its initialization sequence.
 *
 * Returns          void.
 *
 ******************************************************************************/
void phNxpNciHal_reset_nfcee_session(bool force_session_reset) {
  size_t length;

  NFCSTATUS status = NFCSTATUS_FAILED;
  if (nxpncihal_ctrl.halStatus == HAL_STATUS_CLOSE) {
    status = phNxpNciHal_MinOpen();
    if (status != NFCSTATUS_SUCCESS) {
      NXPLOG_NCIHAL_E("%s: NXP Nfc Open failed", __func__);
      return;
    }
  }
  uint8_t *reset_ese_session_identity_set;
  uint8_t ese_session_dyn_uicc_nv[] = {
            0x20, 0x02, 0x22, 0x03, 0xA0, 0xEA, 0x08, 0xFF, 0xFF, 0xFF,
            0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xA0, 0x1E, 0x08, 0xFF, 0xFF,
            0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xA0, 0xEB, 0x08, 0xFF,
            0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
  uint8_t ese_session_dyn_uicc[] = {0x20, 0x02, 0x17, 0x02, 0xA0, 0xEA, 0x08,
                                    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
                                    0xFF, 0xA0, 0x1E, 0x08, 0xFF, 0xFF, 0xFF,
                                    0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
  uint8_t ese_session_nv[] = {0x20, 0x02, 0x17, 0x02, 0xA0, 0xEA, 0x08,
                              0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
                              0xFF, 0xA0, 0xEB, 0x08, 0xFF, 0xFF, 0xFF,
                              0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
  uint8_t ese_session[] = {0x20, 0x02, 0x0C, 0x01, 0xA0, 0xEA, 0x08, 0xFF,
                           0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
  if(nfcFL.nfccFL._NFC_NXP_STAT_DUAL_UICC_WO_EXT_SWITCH || nfcFL.nfccFL._NFCC_DYNAMIC_DUAL_UICC) {
    if(nfcFL.eseFL._EXCLUDE_NV_MEM_DEPENDENCY) {
      reset_ese_session_identity_set = ese_session_dyn_uicc_nv;
      length = sizeof(ese_session_dyn_uicc_nv);
    }
    else {
      reset_ese_session_identity_set = ese_session_dyn_uicc;
      length = sizeof(ese_session_dyn_uicc);
    }
  }
  else {
    if(nfcFL.eseFL._EXCLUDE_NV_MEM_DEPENDENCY) {
      reset_ese_session_identity_set = ese_session_nv;
      length = sizeof(ese_session_nv);
    }
    else {
      reset_ese_session_identity_set = ese_session;
      length = sizeof(ese_session);
    }
  }


#ifdef PN547C2_FACTORY_RESET_DEBUG
  static uint8_t reset_session_identity[] = {0x20, 0x03, 0x05, 0x02,
                                                 0xA0, 0xEA, 0xA0, 0xEB};
#endif

  if (force_session_reset) {
#ifdef PN547C2_FACTORY_RESET_DEBUG
    /* NXP ACT Proprietary Ext */
    status = phNxpNciHal_send_ext_cmd(length, reset_session_identity);
    if (status != NFCSTATUS_SUCCESS) {
      NXPLOG_NCIHAL_E("NXP reset_session_identity command failed");
    }
#endif
    if((nfcFL.nfccFL._NFC_NXP_STAT_DUAL_UICC_WO_EXT_SWITCH) &&
            (nfcFL.nfccFL._NFCC_DYNAMIC_DUAL_UICC)) {
      status = phNxpNciHal_send_ext_cmd(length, reset_ese_session_identity_set);
    }
    if (status != NFCSTATUS_SUCCESS) {
      NXPLOG_NCIHAL_E("NXP reset_ese_session_identity_set command failed");
    }
#ifdef PN547C2_FACTORY_RESET_DEBUG
    /* NXP ACT Proprietary Ext */
    status = phNxpNciHal_send_ext_cmd(length, reset_session_identity);
    if (status != NFCSTATUS_SUCCESS) {
      NXPLOG_NCIHAL_E("NXP reset_ese_session_identity command failed");
    }
#endif
  }
}

/******************************************************************************
 * Function         phNxpNciHal_print_res_status
 *
 * Description      This function is called to process the response status
 *                  and print the status byte.
 *
 * Returns          void.
 *
 ******************************************************************************/
static void phNxpNciHal_print_res_status(uint8_t* p_rx_data, uint16_t* p_len) {
  static uint8_t response_buf[][30] = {
      "STATUS_OK", "STATUS_REJECTED", "STATUS_RF_FRAME_CORRUPTED",
      "STATUS_FAILED", "STATUS_NOT_INITIALIZED", "STATUS_SYNTAX_ERROR",
      "STATUS_SEMANTIC_ERROR", "RFU", "RFU", "STATUS_INVALID_PARAM",
      "STATUS_MESSAGE_SIZE_EXCEEDED", "STATUS_UNDEFINED"};
  int status_byte;
  if (p_rx_data[0] == 0x40 && (p_rx_data[1] == 0x02 || p_rx_data[1] == 0x03)) {
    if (p_rx_data[2] && p_rx_data[3] <= 10) {
      status_byte = p_rx_data[CORE_RES_STATUS_BYTE];
      NXPLOG_NCIHAL_D("%s: response status =%s", __func__,
                      response_buf[status_byte]);
    } else {
      NXPLOG_NCIHAL_D("%s: response status =%s", __func__, response_buf[11]);
    }
    if (phNxpNciClock.isClockSet) {
      int i, len = sizeof(phNxpNciClock.p_rx_data);
      if (*p_len > len) {
        android_errorWriteLog(0x534e4554, "169257710");
      } else {
        len = *p_len;
      }
      for (i = 0; i < len; i++) {
        phNxpNciClock.p_rx_data[i] = p_rx_data[i];
      }
    }

    if (phNxpNciRfSet.isGetRfSetting) {
      int i, len = sizeof(phNxpNciRfSet.p_rx_data);
      if (*p_len > len) {
        android_errorWriteLog(0x534e4554, "169258733");
      } else {
        len = *p_len;
      }
      for (i = 0; i < len; i++) {
        phNxpNciRfSet.p_rx_data[i] = p_rx_data[i];
        // NXPLOG_NCIHAL_D("%s: response status =0x%x",__func__,p_rx_data[i]);
      }
    }
  }

  if ((p_rx_data[2]) && (config_access == true)) {
    if (p_rx_data[3] != NFCSTATUS_SUCCESS) {
        NXPLOG_NCIHAL_W("Invalid Data from config file.");
        config_success = false;
    }
  }
}

/*****************************************************************************
 * Function         phNxpNciHal_send_get_cfgs
 *
 * Description      This function is called to  send get configs
 *                  for all the types in get_cfg_arr.
 *                  Response of getConfigs(EEPROM stored) will be
 *                  compared with request coming from MW during discovery.
 *                  If same, then current setConfigs will be dropped
 *
 * Returns          Returns NFCSTATUS_SUCCESS if sending cmd is successful and
 *                  response is received.
 *
 *****************************************************************************/
NFCSTATUS phNxpNciHal_send_get_cfgs() {
  NXPLOG_NCIHAL_D("%s Enter", __func__);
  NFCSTATUS status = NFCSTATUS_FAILED;
  uint8_t num_cfgs = sizeof(get_cfg_arr) / sizeof(uint8_t);
  uint8_t cfg_count = 0, retry_cnt = 0;
  if (mGetCfg_info != NULL) {
      mGetCfg_info->isGetcfg = true;
  }
  uint8_t cmd_get_cfg[] = {0x20, 0x03, 0x02, 0x01, 0x00};

  while (cfg_count < num_cfgs) {
    cmd_get_cfg[sizeof(cmd_get_cfg) - 1] = get_cfg_arr[cfg_count];

  retry_get_cfg:
    status = phNxpNciHal_send_ext_cmd(sizeof(cmd_get_cfg), cmd_get_cfg);
    if (status != NFCSTATUS_SUCCESS && retry_cnt < 3) {
      NXPLOG_NCIHAL_E("cmd_get_cfg failed");
      retry_cnt++;
      goto retry_get_cfg;
    }
    if (retry_cnt == 3) {
      break;
    }
    cfg_count++;
    retry_cnt = 0;
  }
  mGetCfg_info->isGetcfg = false;
  return status;
}
NFCSTATUS phNxpNciHal_send_nfcee_pwr_cntl_cmd(uint8_t type) {
  NFCSTATUS status = NFCSTATUS_FAILED;
  uint8_t cmd_buf[] = {0x22, 0x03, 0x02, 0xC0, 0x00};
  uint8_t retry_cnt = 0;

  NXPLOG_NCIHAL_D("phNxpNciHal_send_nfcee_pwr_cntl_cmd; enter");
  cmd_buf[sizeof(cmd_buf) - 1] = type;
  while (status != NFCSTATUS_SUCCESS && retry_cnt < 3) {
    status = phNxpNciHal_send_ext_cmd(sizeof(cmd_buf), cmd_buf);
    NXPLOG_NCIHAL_E("cmd_nfcee_pwr_cntl_cfg failed");
    retry_cnt++;
  }
  retry_cnt = 0;
  return status;
}

/*******************************************************************************
**
** Function         phNxpNciHal_getFWDownloadFlags
**
** Description      Returns the current mode
**
** Parameters       none
**
** Returns          Current mode download/NCI
*******************************************************************************/
int phNxpNciHal_getFWDownloadFlag(uint8_t* fwDnldRequest) {
  int status = NFCSTATUS_FAILED;

  NXPLOG_NCIHAL_D("notifyFwrequest %d", notifyFwrequest);
  if (fwDnldRequest != NULL) {
    status = NFCSTATUS_OK;
    if (notifyFwrequest == true) {
      *fwDnldRequest = true;
      notifyFwrequest = false;
    } else {
      *fwDnldRequest = false;
    }
  }

  return status;
}

/*******************************************************************************
**
** Function         phNxpNciHal_configFeatureList
**
** Description      Configures the featureList based on chip type
**                  HW Version information number will provide chipType.
**                  HW Version can be obtained from CORE_INIT_RESPONSE(NCI 1.0)
**                  or CORE_RST_NTF(NCI 2.0)
**
** Parameters       CORE_INIT_RESPONSE/CORE_RST_NTF, len
**
** Returns          none
*******************************************************************************/
void phNxpNciHal_configFeatureList(uint8_t* msg, uint16_t msg_len) {
    nxpncihal_ctrl.chipType = configChipType(msg,msg_len);
    tNFC_chipType chipType = nxpncihal_ctrl.chipType;
    CONFIGURE_FEATURELIST(chipType);
    NXPLOG_NCIHAL_D("NFC_GetFeatureList ()chipType = %d", chipType);
}

/*******************************************************************************
**
** Function         phNxpNciHal_getChipType
**
** Description      Gets the chipType which is configured during bootup
**
** Parameters       none
**
** Returns          chipType
*******************************************************************************/
tNFC_chipType phNxpNciHal_getChipType() {
    return nxpncihal_ctrl.chipType;
}

/*******************************************************************************
**
** Function         phNxpNciHal_configLxDebug(void)
**
** Description      Helper function to configure LxDebug modes
**
** Parameters       none
**
** Returns          void
*******************************************************************************/
void phNxpNciHal_configNciParser(void)
{
    NFCSTATUS status = NFCSTATUS_SUCCESS;
    unsigned long num = 0;
    uint8_t  isfound = 0;
    static uint8_t cmd_lxdebug[] = { 0x20, 0x02, 0x06, 0x01, 0xA0, 0x1D, 0x02, 0x00, 0x00 };

    isfound = GetNxpNumValue(NAME_NXP_CORE_PROP_SYSTEM_DEBUG, &num, sizeof(num));

    if(isfound > 0)
    {
        if(num == 0x00)
        {
            NXPLOG_NCIHAL_D("Disable LxDebug");
        }
        else if(num == 0x01)
        {
            NXPLOG_NCIHAL_D("Enable L1 RF NTF debugs");
            cmd_lxdebug[7] = 0x10;
        }
        else if(num == 0x02)
        {
            NXPLOG_NCIHAL_D("Enable L2 RF NTF debugs");
            cmd_lxdebug[7] = 0x01;
        }
        else if(num == 0x03)
        {
            NXPLOG_NCIHAL_D("Enable L1 & L2 RF NTF debugs");
            cmd_lxdebug[7] = 0x31;
        }
        else if(num == 0x04)
        {
            NXPLOG_NCIHAL_D("Enable L1 & L2 & RSSI NTF debugs");
            cmd_lxdebug[7] = 0x31;
            cmd_lxdebug[8] = 0x01;
        }
        else if(num == 0x05)
        {
            NXPLOG_NCIHAL_D("Enable L2 & Felica RF NTF debugs");
            cmd_lxdebug[7] = 0x03;
        }
        else
            NXPLOG_NCIHAL_E("Invalid Level, Disable LxDebug");

        status = phNxpNciHal_send_ext_cmd(sizeof(cmd_lxdebug)/sizeof(cmd_lxdebug[0]),cmd_lxdebug);
        if (status != NFCSTATUS_SUCCESS)
        {
            NXPLOG_NCIHAL_E("Set lxDebug config failed");
        }
    }

    // try initializing parser library
    NXPLOG_NCIHAL_D("Try Init Parser gParserCreated:%d",gParserCreated);

    if(!gParserCreated) {
        gParserCreated = phNxpNciHal_initParser();
    } else {
        NXPLOG_NCIHAL_D("Parser Already Initialized");
    }

    if(gParserCreated) {
        NXPLOG_NCIHAL_D("Parser Initialized Successfully");
        if(isfound) {
            NXPLOG_NCIHAL_D("Setting lxdebug levels in library");
            phNxpNciHal_parsePacket(cmd_lxdebug,sizeof(cmd_lxdebug)/sizeof(cmd_lxdebug[0]));
        }
    } else {
        NXPLOG_NCIHAL_E("Parser Library Not Available");
    }
  }

/******************************************************************************
 * Function         phNxpNciHal_notifyHciEvtProcessComplete
 *
 * Description      This function is called for to notify HCI Event process
 *                  completion to libnfc
 *
 * Returns          void.
 *
 ******************************************************************************/
static void phNxpNciHal_notifyHciEvtProcessComplete() {
  NXPLOG_NCIHAL_D("%s Enter ", __func__);
  if (nxpncihal_ctrl.isHciCfgEvtRequested &&
      nxpncihal_ctrl.p_nfc_stack_cback != NULL) {
    nxpncihal_ctrl.isHciCfgEvtRequested = false;
    (*nxpncihal_ctrl.p_nfc_stack_cback)(
        (uint32_t)HAL_NFC_CONFIG_ESE_LINK_COMPLETE, HAL_NFC_STATUS_OK);
  }
}

/******************************************************************************
 * Function         phNxpNciHal_setEseState
 *
 * Description      This function is called for to update ese state
 *
 * Returns          void.
 *
 ******************************************************************************/
NFCSTATUS phNxpNciHal_setEseState(phNxpNfcHalEseState eSEstate){
    NXPLOG_NCIHAL_D("%s Enter ", __func__);
    NFCSTATUS status = NFCSTATUS_FAILED;

    if(eSEstate == phNxpNciHalNfc_e_SetIdleMode)
      status = phTmlNfc_IoCtl(phTmlNfc_e_SetP61IdleMode);

    if(eSEstate == phNxpNciHalNfc_e_SetWiredMode)
      status = phTmlNfc_IoCtl(phTmlNfc_e_SetP61WiredMode);

    return status;
}


/*******************************************************************************
 **
 ** Function         phNxpHal_getchipType
 **
 ** Description      Gets the chipType from hal which is already configured
 **                  during init time.
 **
 ** Returns          chipType
 *******************************************************************************/
uint8_t phNxpHal_getchipType()
{
    uint8_t phNxpNciHal_chiptype;
    NXPLOG_NCIHAL_D("%s Enter ", __func__);
    phNxpNciHal_chiptype = (uint8_t)phNxpNciHal_getChipType();

    return phNxpNciHal_chiptype;
}

/*******************************************************************************
**
** Function         phNxpNciHal_setNfcServicePid
**
** Description      This function request to pn54x driver to
**                  update NFC service process ID for signalling.
**
** Returns          0 if api call success, else -1
**
*******************************************************************************/
uint16_t phNxpNciHal_setNfcServicePid(uint64_t phNxpNfcHalpid)
{
  NXPLOG_NCIHAL_D("%s Enter ", __func__);
  NFCSTATUS status = NFCSTATUS_FAILED;
  gpphTmlNfc_Context->nfc_service_pid = phNxpNfcHalpid;
  status = phTmlNfc_IoCtl(phTmlNfc_e_SetNfcServicePid);

  return status;
}

/******************************************************************************
 * Function         phNxpNciHal_getEseState
 *
 * Description      This function is called for to get ese  state
 *
 * Returns          void.
 *
 ******************************************************************************/
NFCSTATUS phNxpNciHal_getEseState(){
    NXPLOG_NCIHAL_D("%s Enter ", __func__);
    NFCSTATUS status = NFCSTATUS_FAILED;
    status = phTmlNfc_IoCtl(phTmlNfc_e_GetP61PwrMode);
    return status;
}

/******************************************************************************
 * Function         phNxpNciHal_initialize_mifare_flag
 *
 * Description      This function gets the value for Mfc flags.
 *
 * Returns          void
 *
 ******************************************************************************/
static void phNxpNciHal_initialize_mifare_flag() {
  unsigned long num = 0;
  bEnableMfcReader = false;
  bDisableLegacyMfcExtns = true;
  //1: Enable Mifare Classic protocol in RF Discovery.
  //0: Remove Mifare Classic protocol in RF Discovery.
  if(GetNxpNumValue(NAME_MIFARE_READER_ENABLE, &num, sizeof(num))) {
    bEnableMfcReader = (num == 0) ? false : true;
  }
  //1: Use legacy JNI MFC extns.
  //0: Disable legacy JNI MFC extns, use hal MFC Extns instead.
  if(GetNxpNumValue(NAME_LEGACY_MIFARE_READER, &num, sizeof(num))) {
    bDisableLegacyMfcExtns = (num == 0) ? true : false;
  }
}

/******************************************************************************
 * Function         phNxpNciHal_ReleaseSVDDWait
 *
 * Description      This function release wait for svdd change
 *                  of P61.
 *
 * Returns          NFCSTATUS.
 *
 ******************************************************************************/
NFCSTATUS phNxpNciHal_ReleaseSVDDWait(uint32_t level){
    NFCSTATUS status = NFCSTATUS_FAILED;
    NXPLOG_NCIHAL_D("%s Enter ", __func__);

    if(nfcFL.nfcNxpEse && nfcFL.eseFL._ESE_SVDD_SYNC) {
        status = phTmlNfc_rel_svdd_wait(gpphTmlNfc_Context->pDevHandle,
                                        level);
        NXPLOG_NCIHAL_D("phTmlNfc_rel_svdd_wait retval = %d\n",
                        status);
    }
    NXPLOG_NCIHAL_D("%s Exit ", __func__);

    return status;
}

/******************************************************************************
 * Function         phNxpNciHal_ReleaseDWPOnOffWait
 *
 * Description      This function release wait for DWP On/Off
 *                  of P73. output returned as Status
 * Returns          NFCSTATUS.
 *
 ******************************************************************************/
NFCSTATUS phNxpNciHal_ReleaseDWPOnOffWait(uint32_t level){
    NFCSTATUS status = NFCSTATUS_FAILED;
    NXPLOG_NCIHAL_D("%s Enter ", __func__);

    if(nfcFL.nfcNxpEse) {
      status = phTmlNfc_rel_dwpOnOff_wait(gpphTmlNfc_Context->pDevHandle,
                                          level);
      NXPLOG_NCIHAL_D("phNxpNciHal_ReleaseDWPWait retval = %d\n",
                      status);
    }

    NXPLOG_NCIHAL_D("%s Exit ", __func__);
    return status;
}

/******************************************************************************
 * Function         phNxpNciHal_getSPMStatus
 *
 * Description      This function gets the SPM state before FW download
 *
 * Returns          0 as success -1 as failed.
 *
 *******************************************************************************/
int phNxpNciHal_getSPMStatus(uint32_t level){
    int ret = -1;
    NXPLOG_NCIHAL_D("%s Enter ", __func__);

    ret = phPalEse_spi_ioctl(phPalEse_e_GetSPMStatus,
                             gpphTmlNfc_Context->pDevHandle, level);

    NXPLOG_NCIHAL_D("%s Exit ", __func__);
    return ret;
}

/******************************************************************************
 * Function         phNxpNciHal_hciInitUpdateState
 *
 * Description      This function Sends HCI Events to nfc HAL
 *
 * Returns          0 as success -1 as failed.
 *
 *******************************************************************************/
int32_t phNxpNciHal_hciInitUpdateState(phNxpNfcHciInitStatus HciStatus){
    int ret = -1;
    ese_nxp_IoctlInOutData_t InpOutData;
    NXPLOG_NCIHAL_D("%s Enter ", __func__);

    nxpncihal_ctrl.isHciCfgEvtRequested = true;
    InpOutData.inp.data.nxpCmd.p_cmd[0] = HciStatus;
    NXPLOG_NCIHAL_D("phNxpNciHal_hciInitUpdateState value is %d: \n",
                      InpOutData.inp.data.nxpCmd.p_cmd[0]);
    if (gpEseAdapt != NULL)
      gpEseAdapt->HalNfccNtf(HAL_ESE_IOCTL_HCI_INIT_STATUS_UPDATE, &InpOutData);

    NXPLOG_NCIHAL_D("%s Exit ", __func__);
    return ret;
}

/******************************************************************************
 * Function         phNxpNciHal_hciInitUpdateStateComplete
 *
 * Description      This function posts event HAL_NFC_CONFIG_ESE_LINK_COMPLETE
 *
 * Returns          void.
 *
 *******************************************************************************/
int32_t phNxpNciHal_hciInitUpdateStateComplete(){
    int32_t ret = 0;
    NXPLOG_NCIHAL_D("%s Enter ", __func__);

    phNxpNciHal_notifyHciEvtProcessComplete();

    NXPLOG_NCIHAL_D("%s Exit ", __func__);
    return ret;
}

/******************************************************************************
 * Function         phNxpNciHal_GetCachedNfccConfig
 *
 * Description      This function receives the cached configinfo.
 *
 * Returns          void.
 *
 *******************************************************************************/
void phNxpNciHal_GetCachedNfccConfig(phNxpNci_getCfg_info_t *pGetCfg_info){

    NXPLOG_NCIHAL_D("%s Enter ", __func__);

    if (mGetCfg_info && pGetCfg_info != NULL) {
      memcpy(pGetCfg_info, mGetCfg_info,
             sizeof(phNxpNci_getCfg_info_t));
    } else {
      NXPLOG_NCIHAL_E("%s : Error! mgetCfg_info is Empty ", __func__);
    }

    NXPLOG_NCIHAL_D("%s Exit ", __func__);
}

/*******************************************************************************
**
** Function         phNxpNciHal_resetEse
**
** Description      It shall be used to reset eSE by proprietary command.
**
** Parameters
**
** Returns          status of eSE reset response
*******************************************************************************/
NFCSTATUS phNxpNciHal_resetEse(uint64_t resetType) {
  NFCSTATUS status = NFCSTATUS_FAILED;

  NXPLOG_NCIHAL_D("%s Entry ", __func__);

  if (nxpncihal_ctrl.halStatus == HAL_STATUS_CLOSE) {
    NFCSTATUS status = NFCSTATUS_FAILED;
    status = phNxpNciHal_MinOpen();
    if (status != NFCSTATUS_SUCCESS) {
      return status;
    }
  }

  if (nfcFL.chipType == pn557) {
    resetType |= SIGNAL_TRIGGER_NOT_REQD;
    status = phPalEse_spi_ioctl(phPalEse_e_ChipRst,
                             gpphTmlNfc_Context->pDevHandle, resetType);
    if(status == NFCSTATUS_SUCCESS) {
      ALOGD("HAL_NFC_ESE_HARD_RESET completed");
    } else {
      ALOGD("HAL_NFC_ESE_HARD_RESET failed");
    }
  } else {
    ALOGD("ESE Reset Feature not supported");
  }

  return status;
}

void seteSEClientState(uint8_t state) {
  DwpEseUpdater::setSpiEseClientState(state);
}

/******************************************************************************
** Function         phNxpNciHal_Abort
**
** Description      This function shall be used to trigger the abort
**
** Parameters       None
**
** Returns          bool.
**
*******************************************************************************/
bool phNxpNciHal_Abort() {
  bool ret = true;

  seteSEClientState(ESE_UPDATE_COMPLETED);
  NXPLOG_NCIHAL_D("phNxpNciHal_Abort aborting. \n");
  /* When JCOP download is triggered phNxpNciHal_open is blocked, in this case only
     we need to abort the libnfc , this can be done only by check the p_nfc_stack_cback_backup
     pointer which is assigned before the JCOP download.*/
  if (p_nfc_stack_cback_backup != NULL){
      abort();
  }
  else {
    NXPLOG_NCIHAL_D("phNxpNciHal_Abort not triggered\n");
  }
  return ret;
}

bool getJcopUpdateRequired() { return false; }

bool getLsUpdateRequired() { return false; }

string phNxpNciHal_getSystemProperty(string key) {
  string value(NXP_MAX_CONFIG_STRING_LEN, ' ');
  if (GetNxpValueAsString(key.c_str(), const_cast<char*>(value.c_str()),
                          value.size()))
    return value;
  /*In case no match found, return empty string*/
  return {};
}

bool phNxpNciHal_setSystemProperty(string key, string value) { key = value = ""; return false; }

void eSEClientUpdate_NFC_Thread() {
  DwpEseUpdater::eSEClientUpdate_NFC_Thread();
}

/******************************************************************************
 * Function         phNxpNciHal_nciTransceive
 *
 * Description      This function does tarnsceive of nci command
 *
 * Returns          void.
 *
 *******************************************************************************/
void phNxpNciHal_nciTransceive(phNxpNci_Extn_Cmd_t *in, phNxpNci_Extn_Resp_t *out){
    uint32_t status = 0;
    NXPLOG_NCIHAL_D("%s Enter ", __func__);

    if (in == NULL ||(in->cmd_len <= 0) || out == NULL)  {
      return;
    }

        /* check for sync command and proceed */
    if((in->p_cmd[0] == 0x2F) && (in->p_cmd[1] == 0x01) && (in->p_cmd[2] = 0x01)) {
      /* logic to skip delay */
      if (nxpncihal_ctrl.halStatus == HAL_STATUS_CLOSE) {
        NFCSTATUS status = NFCSTATUS_FAILED;
        status = phNxpNciHal_MinOpen();
        if (status != NFCSTATUS_SUCCESS) {
          if (nfcFL.eseFL._NXP_SPI_DWP_SYNC) {
            /* p_rsp[3] is the status for DWP sync response. value 0x00 equals
            Success and 0x01 for Fail. */
          out->p_rsp[3] = 0x01;
        }
        goto exit;
      }
    }

    if (!nfcFL.eseFL._NXP_SPI_DWP_SYNC) {
        ALOGD_IF(nfc_debug_enabled,
                 "phNxpNciHal_ioctl HAL_NFC_IOCTL_SPI_DWP_SYNC not supported. "
                 "Returning..");
        phNxpNciHal_MinCloseForOmapiClose(in);
        out->p_rsp[3] = 0x00;
        goto exit;
    }
    phNxpNciHal_SendHalCmd(in,out);

    } else {
      status = phNxpNciHal_send_ext_cmd(in->cmd_len,
                                     in->p_cmd);
      out->rsp_len = nxpncihal_ctrl.rx_data_len;
      if ((nxpncihal_ctrl.rx_data_len > 0) &&
          (nxpncihal_ctrl.rx_data_len <= MAX_IOCTL_TRANSCEIVE_RESP_LEN) &&
          (nxpncihal_ctrl.p_rx_data != NULL)) {
        memcpy(out->p_rsp, nxpncihal_ctrl.p_rx_data,
               nxpncihal_ctrl.rx_data_len);
      }
    }

exit :

    out->status = status;

    NXPLOG_NCIHAL_D("%s Exit ", __func__);
    return;
}

/******************************************************************************
 * Function         phNxpNciHal_nciTransceive
 *
 * Description      This function does tarnsceive of proprietary nci command
 *
 * Returns          void.
 *
 *******************************************************************************/
int phNxpNciHal_SendHalCmd(phNxpNci_Extn_Cmd_t *in, phNxpNci_Extn_Resp_t *out){
    int ret = -1;

    if (!nfcFL.eseFL._NXP_SPI_DWP_SYNC) {
      ALOGD_IF(nfc_debug_enabled,
              "phNxpNciHal_ioctl HAL_NFC_IOCTL_SPI_DWP_SYNC not supported. "
              "Returning..");
      ret = 0;
      phNxpNciHal_MinCloseForOmapiClose(in);
      return ret;
    }

    ret = phNxpNciHal_send_ese_hal_cmd(in->cmd_len,
                                       in->p_cmd);
    out->rsp_len = nxpncihal_ctrl.rx_ese_data_len;
    if ((nxpncihal_ctrl.rx_ese_data_len > 0) &&
        (nxpncihal_ctrl.rx_ese_data_len <= MAX_IOCTL_TRANSCEIVE_RESP_LEN) &&
        (nxpncihal_ctrl.p_rx_ese_data != NULL)) {
      memcpy(out->p_rsp, nxpncihal_ctrl.p_rx_ese_data,
             nxpncihal_ctrl.rx_ese_data_len);
    }

    if (out->p_rsp[0] == 0x4F &&
        out->p_rsp[1] == 0x01 &&
        out->p_rsp[2] == 0x01 &&
        out->p_rsp[3] == 0x00 &&
        in->p_cmd[3] == 0x01) {
        NXPLOG_NCIHAL_D("OMAPI COMMAND for Open SUCCESS : 0x%x",
                        out->p_rsp[3]);
        ret = out->p_rsp[3];
    } else if (  out->p_rsp[0] == 0x4F &&
                 out->p_rsp[1] == 0x01 &&
                 out->p_rsp[2] == 0x01 &&
                 out->p_rsp[3] == 0x00 &&
                 in->p_cmd[3] == 0x00)
      {
        NXPLOG_NCIHAL_D("OMAPI COMMAND for Close SUCCESS : 0x%x",
                        out->p_rsp[3]);
        ret = out->p_rsp[3];
      } else if (out->p_rsp[0] == 0x4F &&
                 out->p_rsp[1] == 0x01 &&
                 out->p_rsp[2] == 0x01 &&
                 out->p_rsp[3] == 0x00 &&
                 in->p_cmd[3] == 0x02) {
        NXPLOG_NCIHAL_D("OMAPI COMMAND for Switch Allowed SUCCESS : 0x%x",
                        out->p_rsp[3]);
        ret = out->p_rsp[3];
        phNxpNciHal_notifyHciEvtProcessComplete();
      } else {
        NXPLOG_NCIHAL_D("OMAPI COMMAND FAILURE : 0x%x",
                        out->p_rsp[3]);
        ret = out->p_rsp[3] =
            3;  // magic number for omapi failure
      }
      phNxpNciHal_MinCloseForOmapiClose(in);

      return ret;
}
