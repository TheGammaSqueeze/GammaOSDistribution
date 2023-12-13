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
 *  Copyright 2015-2020 NXP
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 ******************************************************************************/

#ifndef _NXP_CONFIG_H
#define _NXP_CONFIG_H

#define NAME_NXP_AGC_DEBUG_ENABLE "NXP_AGC_DEBUG_ENABLE"
#define NAME_NXP_WIRED_MODE_RF_FIELD_ENABLE "NXP_WIRED_MODE_RF_FIELD_ENABLE"
#define NAME_NXP_UICC_WIRED_PRT_MASK "NXP_UICC_WIRED_PRT_MASK"
#define NAME_NXP_ESE_WIRED_PRT_MASK "NXP_ESE_WIRED_PRT_MASK"
#define NAME_NXP_ENABLE_ADD_AID "NXP_ENABLE_ADD_AID"
#define NAME_NXP_ESE_POWER_DH_CONTROL "NXP_ESE_POWER_DH_CONTROL"
#define NAME_NXP_DWP_INTF_RESET_ENABLE "NXP_DWP_INTF_RESET_ENABLE"
#define NAME_NFA_CONFIG_FORMAT "NFA_CONFIG_FORMAT"

/**
 *  @brief defines the different config files used.
 */

#define config_name_mtp         "libnfc-mtp_default.conf"
#define config_name_mtp1        "libnfc-mtp_rf1.conf"
#define config_name_mtp2        "libnfc-mtp_rf2.conf"
#define config_name_mtp_NQ3XX   "libnfc-mtp-NQ3XX.conf"
#define config_name_mtp_NQ4XX   "libnfc-mtp-NQ4XX.conf"
#define config_name_qrd         "libnfc-qrd_default.conf"
#define config_name_qrd1        "libnfc-qrd_rf1.conf"
#define config_name_qrd2        "libnfc-qrd_rf2.conf"
#define config_name_qrd_NQ3XX   "libnfc-qrd-NQ3XX.conf"
#define config_name_qrd_NQ4XX   "libnfc-qrd-NQ4XX.conf"
#define config_name_default     "libnfc-nxp_default.conf"

/**
 *  @brief defines the different major number used.
 */
#define FW_MAJOR_NUM_NQ2xx     "10"
#define FW_MAJOR_NUM_NQ3xx     "11"
#define FW_MAJOR_NUM_NQ4xx     "12"

#define FW_MAJOR_NUM_LENGTH    2

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



#endif //_NXP_CONFIG_H
