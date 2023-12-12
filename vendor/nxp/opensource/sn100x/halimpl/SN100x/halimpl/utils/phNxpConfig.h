/******************************************************************************
 *
 *  Copyright (C) 1999-2012 Broadcom Corporation
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
 *  Copyright (C) 2013-2020 NXP
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

#ifndef __CONFIG_H
#define __CONFIG_H

#ifdef __cplusplus
extern "C" {
#endif

int GetNxpStrValue(const char* name, char* p_value, unsigned long len);
int GetNxpNumValue(const char* name, void* p_value, unsigned long len);
int GetNxpByteArrayValue(const char* name, char* pValue, long bufflen,
                         long* len);
void resetNxpConfig(void);
int isNxpRFConfigModified();
int isNxpConfigModified();
int updateNxpConfigTimestamp();
int updateNxpRfConfigTimestamp();
void setNxpRfConfigPath(const char* name);
void setNxpFwConfigPath(const char* name);

#ifdef __cplusplus
};
#endif

extern char Fw_Lib_Path[256];

#define NAME_NXPLOG_EXTNS_LOGLEVEL "NXPLOG_EXTNS_LOGLEVEL"
#define NAME_NXPLOG_NCIHAL_LOGLEVEL "NXPLOG_NCIHAL_LOGLEVEL"
#define NAME_NXPLOG_NCIX_LOGLEVEL "NXPLOG_NCIX_LOGLEVEL"
#define NAME_NXPLOG_NCIR_LOGLEVEL "NXPLOG_NCIR_LOGLEVEL"
#define NAME_NXPLOG_FWDNLD_LOGLEVEL "NXPLOG_FWDNLD_LOGLEVEL"
#define NAME_NXPLOG_TML_LOGLEVEL "NXPLOG_TML_LOGLEVEL"

#define NAME_MIFARE_READER_ENABLE "MIFARE_READER_ENABLE"
#define NAME_LEGACY_MIFARE_READER "LEGACY_MIFARE_READER"
#define NAME_FW_STORAGE "FW_STORAGE"
#define NAME_NXP_NFC_DEV_NODE "NXP_NFC_DEV_NODE"
#define NAME_NXP_NFC_CHIP "NXP_NFC_CHIP"
#define NAME_NXP_FW_NAME "NXP_FW_NAME"
#define NAME_NXP_FW_TYPE "NXP_FW_TYPE"
#define NAME_NXP_FW_PROTECION_OVERRIDE "NXP_FW_PROTECION_OVERRIDE"
#define NAME_NXP_SYS_CLK_SRC_SEL "NXP_SYS_CLK_SRC_SEL"
#define NAME_NXP_SYS_CLK_FREQ_SEL "NXP_SYS_CLK_FREQ_SEL"
#define NAME_NXP_SYS_CLOCK_TO_CFG "NXP_SYS_CLOCK_TO_CFG"
#define NAME_NXP_CLOCK_REQ_DELAY "NXP_CLOCK_REQ_DELAY"
#define NAME_NXP_ACT_PROP_EXTN "NXP_ACT_PROP_EXTN"
#define NAME_NXP_EXT_TVDD_CFG "NXP_EXT_TVDD_CFG"
#define NAME_NXP_EXT_TVDD_CFG_1 "NXP_EXT_TVDD_CFG_1"
#define NAME_NXP_EXT_TVDD_CFG_2 "NXP_EXT_TVDD_CFG_2"
#define NAME_NXP_EXT_TVDD_CFG_3 "NXP_EXT_TVDD_CFG_3"
#define NAME_NXP_CORE_CONF_EXTN "NXP_CORE_CONF_EXTN"
#define NAME_NXP_CORE_CONF "NXP_CORE_CONF"
#define NAME_NXP_NFC_PROFILE_EXTN "NXP_NFC_PROFILE_EXTN"
#define NAME_NXP_CHINA_TIANJIN_RF_ENABLED "NXP_CHINA_TIANJIN_RF_ENABLED"
#define NAME_NXP_CHINA_BLK_NUM_CHK_ENABLE "NXP_CN_TRANSIT_BLK_NUM_CHECK_ENABLE"
#define NAME_NXP_CN_TRANSIT_CMA_BYPASSMODE_ENABLE  "NXP_CN_TRANSIT_CMA_BYPASSMODE_ENABLE"
#define NAME_NXP_ESE_POWER_DH_CONTROL "NXP_ESE_POWER_DH_CONTROL"
#define NAME_NXP_ESE_POWER_EXT_PMU "NXP_ESE_POWER_EXT_PMU"
#define NAME_NXP_ESE_POWER_DH_CONTROL_CFG_1 "NXP_ESE_POWER_DH_CONTROL_CFG_1"
#define NAME_NXP_SWP_SWITCH_TIMEOUT "NXP_SWP_SWITCH_TIMEOUT"
#define NAME_NXP_SWP_FULL_PWR_ON "NXP_SWP_FULL_PWR_ON"
#define NAME_NXP_CORE_RF_FIELD "NXP_CORE_RF_FIELD"
#define NAME_NXP_NFC_MERGE_RF_PARAMS "NXP_NFC_MERGE_RF_PARAMS"
#define NAME_NXP_I2C_FRAGMENTATION_ENABLED "NXP_I2C_FRAGMENTATION_ENABLED"
#define NAME_NFC_DEBUG_ENABLED "NFC_DEBUG_ENABLED"
#define NAME_AID_MATCHING_PLATFORM "AID_MATCHING_PLATFORM"
#define NAME_NXP_TYPEA_UICC_BAUD_RATE "NXP_TYPEA_UICC_BAUD_RATE"
#define NAME_NXP_TYPEB_UICC_BAUD_RATE "NXP_TYPEB_UICC_BAUD_RATE"
#define NAME_NXP_SET_CONFIG_ALWAYS "NXP_SET_CONFIG_ALWAYS"
#define NAME_NXP_PROP_BLACKLIST_ROUTING "NXP_PROP_BLACKLIST_ROUTING"
#define NAME_NXP_WIREDMODE_RESUME_TIMEOUT "NXP_WIREDMODE_RESUME_TIMEOUT"
#define NAME_NXP_UICC_LISTEN_TECH_MASK "UICC_LISTEN_TECH_MASK"
#define NAME_NXP_ESE_LISTEN_TECH_MASK "NXP_ESE_LISTEN_TECH_MASK"
#define NAME_NXP_SVDD_SYNC_OFF_DELAY "NXP_SVDD_SYNC_OFF_DELAY"
#define NAME_NXP_CORE_PROP_SYSTEM_DEBUG "NXP_CORE_PROP_SYSTEM_DEBUG"
#define NAME_NXP_NCI_PARSER_LIBRARY "NXP_NCI_PARSER_LIBRARY"
#define NAME_NXP_DEFAULT_UICC2_SELECT "NXP_DEFAULT_UICC2_SELECT"
#define NAME_NXP_ALWAYS_FW_UPDATE   "NXP_ALWAYS_FW_UPDATE"
#define NAME_NXP_P61_JCOP_DEFAULT_INTERFACE "NXP_P61_JCOP_DEFAULT_INTERFACE"
#define NAME_RF_STATUS_UPDATE_ENABLE "RF_STATUS_UPDATE_ENABLE"
#define NAME_DEFAULT_ROUTE "DEFAULT_ROUTE"
#define NAME_DEFAULT_SYS_CODE_ROUTE "DEFAULT_SYS_CODE_ROUTE"
#define NAME_DEFAULT_SYS_CODE_PWR_STATE "DEFAULT_SYS_CODE_PWR_STATE"
#define NAME_OFF_HOST_ESE_PIPE_ID "OFF_HOST_ESE_PIPE_ID"
#define NAME_OFF_HOST_SIM_PIPE_ID "OFF_HOST_SIM_PIPE_ID"
#define NAME_DEFAULT_OFFHOST_ROUTE "DEFAULT_OFFHOST_ROUTE"
#define NAME_DEFAULT_NFCF_ROUTE "DEFAULT_NFCF_ROUTE"
#define NAME_ISO_DEP_MAX_TRANSCEIVE "ISO_DEP_MAX_TRANSCEIVE"
#define NAME_NFA_POLL_BAIL_OUT_MODE "NFA_POLL_BAIL_OUT_MODE"
#define NAME_ACTIVE_SE "ACTIVE_SE"
#define NAME_ACTIVE_SE_NFCF "ACTIVE_SE_NFCF"
#define NAME_DEFAULT_FELICA_SYS_CODE_ROUTE "DEFAULT_FELICA_SYS_CODE_ROUTE"
#define NAME_DEVICE_HOST_WHITE_LIST "DEVICE_HOST_WHITE_LIST"
#define NAME_NFA_PROPRIETARY_CFG "NFA_PROPRIETARY_CFG"
#define NAME_PRESENCE_CHECK_ALGORITHM "PRESENCE_CHECK_ALGORITHM"
#define NAME_NXP_CORE_PROP_SYSTEM_DEBUG "NXP_CORE_PROP_SYSTEM_DEBUG"
#define NAME_NXP_AUTONOMOUS_ENABLE "NXP_AUTONOMOUS_ENABLE"
#define NAME_NXP_P61_LS_DEFAULT_INTERFACE "NXP_P61_LS_DEFAULT_INTERFACE"
#define NAME_NXP_LS_FORCE_UPDATE_REQUIRED "NXP_LS_FORCE_UPDATE_REQUIRED"
#define NAME_NXP_JCOP_FORCE_UPDATE_REQUIRED "NXP_JCOP_FORCE_UPDATE_REQUIRED"
#define NAME_RF_STORAGE "RF_STORAGE"
#define NAME_NXP_FLASH_CONFIG "NXP_FLASH_CONFIG"
#define NAME_OFFHOST_ROUTE_ESE "OFFHOST_ROUTE_ESE"
#define NAME_OFFHOST_ROUTE_UICC "OFFHOST_ROUTE_UICC"
#define NAME_DEFAULT_ISODEP_ROUTE "DEFAULT_ISODEP_ROUTE"
#define NAME_ENABLE_VEN_TOGGLE "ENABLE_VEN_TOGGLE"
#define NAME_NFC_INTERFACE "NFC_INTERFACE"
#if(NXP_EXTNS == TRUE)
#define NAME_NXP_SE_COLD_TEMP_ERROR_DELAY "NXP_SE_COLD_TEMP_ERROR_DELAY"
#define NAME_P2P_LISTEN_TECH_MASK "P2P_LISTEN_TECH_MASK"
#define NAME_HOST_LISTEN_TECH_MASK "HOST_LISTEN_TECH_MASK"
#define NAME_UICC_LISTEN_TECH_MASK "UICC_LISTEN_TECH_MASK"
#define NAME_POLLING_TECH_MASK "POLLING_TECH_MASK"
#define NAME_NXP_DEFAULT_SE "NXP_DEFAULT_SE"
#define NAME_NXP_SWP_RD_TAG_OP_TIMEOUT "NXP_SWP_RD_TAG_OP_TIMEOUT"
#define NAME_NXP_DUAL_UICC_ENABLE "NXP_DUAL_UICC_ENABLE"
#define NAME_DEFAULT_AID_ROUTE "DEFAULT_AID_ROUTE"
#define NAME_DEFAULT_MIFARE_CLT_ROUTE "DEFAULT_MIFARE_CLT_ROUTE"
#define NAME_DEFAULT_FELICA_CLT_ROUTE "DEFAULT_FELICA_CLT_ROUTE"
#define NAME_DEFAULT_AID_PWR_STATE "DEFAULT_AID_PWR_STATE"
#define NAME_DEFAULT_DESFIRE_PWR_STATE "DEFAULT_DESFIRE_PWR_STATE"
#define NAME_DEFAULT_MIFARE_CLT_PWR_STATE "DEFAULT_MIFARE_CLT_PWR_STATE"
#define NAME_DEFAULT_T4TNFCEE_AID_POWER_STATE "DEFAULT_T4TNFCEE_AID_POWER_STATE"
#define NAME_FORWARD_FUNCTIONALITY_ENABLE "FORWARD_FUNCTIONALITY_ENABLE"
#define NAME_DEFAULT_FELICA_CLT_PWR_STATE "DEFAULT_FELICA_CLT_PWR_STATE"
#define NAME_CHECK_DEFAULT_PROTO_SE_ID "NXP_CHECK_DEFAULT_PROTO_SE_ID"
#define NAME_NXP_DEFAULT_UICC2_SELECT "NXP_DEFAULT_UICC2_SELECT"
#define NAME_NXP_T4T_NFCEE_ENABLE "NXP_T4T_NFCEE_ENABLE"
#define NAME_NXP_SMB_TRANSCEIVE_TIMEOUT "NXP_SMB_TRANSCEIVE_TIMEOUT"
#define NAME_NXP_SMB_ERROR_RETRY "NXP_SMB_ERROR_RETRY"
#define NAME_DEFUALT_GSMA_PWR_STATE "DEFUALT_GSMA_PWR_STATE"
#define NAME_NXP_NFC_SE_TERMINAL_NUM "NXP_NFC_SE_TERMINAL_NUM"
#define NAME_NXP_POLL_FOR_EFD_TIMEDELAY "NXP_POLL_FOR_EFD_TIMEDELAY"
#define NAME_NXP_NFCC_MERGE_SAK_ENABLE "NXP_NFCC_MERGE_SAK_ENABLE"
#define NAME_NXP_STAG_TIMEOUT_CFG "NXP_STAG_TIMEOUT_CFG"
#define NAME_NXP_RF_FILE_VERSION_INFO "NXP_RF_FILE_VERSION_INFO"
#define NAME_RF_STORAGE "RF_STORAGE"
#define NAME_FW_STORAGE "FW_STORAGE"
#define NAME_NXP_CORE_CONF "NXP_CORE_CONF"
#define NAME_NXP_GUARD_TIMER_VALUE "NXP_GUARD_TIMER_VALUE"
#define NAME_NXP_PROP_RESET_EMVCO_CMD "NXP_PROP_RESET_EMVCO_CMD"
#define NAME_NFA_CONFIG_FORMAT "NFA_CONFIG_FORMAT"
#define NAME_NXP_DISCONNECT_TAG_IN_SCRN_OFF "NXP_DISCONNECT_TAG_IN_SCRN_OFF"
#define NAME_NXP_ENABLE_DISABLE_LOGS "NXP_ENABLE_DISABLE_LOGS"
#define NAME_NXP_RDR_DISABLE_ENABLE_LPCD "NXP_RDR_DISABLE_ENABLE_LPCD"
#endif

/**
 *  @brief defines the different config files used.
 */

#define config_name_mtp         "libnfc-mtp_default.conf"
#define config_name_mtp1        "libnfc-mtp_rf1.conf"
#define config_name_mtp2        "libnfc-mtp_rf2.conf"
#define config_name_mtp_NQ3XX   "libnfc-mtp-NQ3XX.conf"
#define config_name_mtp_NQ4XX   "libnfc-mtp-NQ4XX.conf"
#define config_name_mtp_SN100   "libnfc-mtp-SN100.conf"
#define config_name_mtp_SN100_38_4MHZ   "libnfc-mtp-SN100_38_4MHZ.conf"
#define config_name_qrd         "libnfc-qrd_default.conf"
#define config_name_qrd1        "libnfc-qrd_rf1.conf"
#define config_name_qrd2        "libnfc-qrd_rf2.conf"
#define config_name_qrd_NQ3XX   "libnfc-qrd-NQ3XX.conf"
#define config_name_qrd_NQ4XX   "libnfc-qrd-NQ4XX.conf"
#define config_name_qrd_SN100   "libnfc-qrd-SN100.conf"
#define config_name_qrd_SN100_38_4MHZ   "libnfc-qrd-SN100_38_4MHZ.conf"
#define config_name_default     "libnfc-nxp_default.conf"

/**
 *  @brief defines the different major number used.
 */
#define FW_MAJOR_NUM_NQ2xx      "10"
#define FW_MAJOR_NUM_NQ3xx      "11"
#define FW_MAJOR_NUM_NQ4xx      "12"

#define FW_MAJOR_NUM_LENGTH     2

/**
 *  @brief defines the maximum length of the target name.
 */

#define MAX_SOC_INFO_NAME_LEN (15)

/**
 *  @brief Defines the type of hardware platform.
 */

#define QRD_HW_PLATFORM  "qrd"
#define MTP_HW_PLATFORM  "mtp"

/**
 *  @brief Defines the path where the hardware platform details are present.
 */

#define SYSFS_HW_PLATFORM_PATH1  "/sys/devices/soc0/hw_platform"
#define SYSFS_HW_PLATFORM_PATH2   "/sys/devices/system/soc/soc0/hw_platform"

/**
 *  @brief Defines the path where the soc_id details are present.
 */

#define SYSFS_SOCID_PATH1    "/sys/devices/soc0/soc_id"
#define SYSFS_SOCID_PATH2    "/sys/devices/system/soc/soc0/id"

/**
 *  @brief Defines the maximum length of the config file name.
 */

#define MAX_DATA_CONFIG_PATH_LEN 64

/**
 *  @brief Defines the NQ chip type.
 */

#define NQ210 "0x48"
#define NQ220 "0x58"

/**
 *  @brief Defines whether debugging is enabled or disabled.
 */

#define DEBUG 0

/* default configuration */
#define default_storage_location "/data/vendor/nfc"
#define NAME_NXP_AUTH_TIMEOUT_CFG "NXP_AUTH_TIMEOUT_CFG"
#endif
