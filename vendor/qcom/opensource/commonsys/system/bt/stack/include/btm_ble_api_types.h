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

#ifndef BTM_BLE_API_TYPES_H
#define BTM_BLE_API_TYPES_H

#include "osi/include/alarm.h"

#include <base/callback_forward.h>
#include <hardware/bt_common_types.h>
#include <vector>
#include <map>

#define CHNL_MAP_LEN 5
typedef uint8_t tBTM_BLE_CHNL_MAP[CHNL_MAP_LEN];

/* 0x00-0x04 only used for set advertising parameter command */
#define BTM_BLE_CONNECT_EVT 0x00
/* Connectable directed advertising */
#define BTM_BLE_CONNECT_DIR_EVT 0x01
/* Scannable undirected advertising */
#define BTM_BLE_DISCOVER_EVT 0x02
/* Non connectable undirected advertising */
#define BTM_BLE_NON_CONNECT_EVT 0x03
/* Connectable low duty cycle directed advertising  */
#define BTM_BLE_CONNECT_LO_DUTY_DIR_EVT 0x04
/* 0x00 - 0x05 can be received on adv event type */
#define BTM_BLE_SCAN_RSP_EVT 0x04
#define BTM_BLE_SCAN_REQ_EVT 0x05
#define BTM_BLE_UNKNOWN_EVT 0xff

#define BTM_BLE_UNKNOWN_EVT 0xff

typedef uint8_t tBTM_BLE_EVT;
typedef uint8_t tBTM_BLE_CONN_MODE;

typedef uint32_t tBTM_BLE_REF_VALUE;

#define BTM_BLE_SCAN_MODE_PASS 0
#define BTM_BLE_SCAN_MODE_ACTI 1
#define BTM_BLE_SCAN_MODE_NONE 0xff
typedef uint8_t tBLE_SCAN_MODE;

#define BTM_BLE_BATCH_SCAN_MODE_DISABLE 0
#define BTM_BLE_BATCH_SCAN_MODE_PASS 1
#define BTM_BLE_BATCH_SCAN_MODE_ACTI 2
#define BTM_BLE_BATCH_SCAN_MODE_PASS_ACTI 3

typedef uint8_t tBTM_BLE_BATCH_SCAN_MODE;

#define PHY_LE_1M_IN             1
#define PHY_LE_CODED_IN          3
#define PHY_LE_ALL_SUPPORTED_IN  255

#define SCAN_PHY_LE_1M             1
#define SCAN_PHY_LE_CODED          4
#define SCAN_PHY_LE_ALL_SUPPORTED  5

/* advertising channel map */
#define BTM_BLE_ADV_CHNL_37 (0x01 << 0)
#define BTM_BLE_ADV_CHNL_38 (0x01 << 1)
#define BTM_BLE_ADV_CHNL_39 (0x01 << 2)
typedef uint8_t tBTM_BLE_ADV_CHNL_MAP;

/*d efault advertising channel map */
#ifndef BTM_BLE_DEFAULT_ADV_CHNL_MAP
#define BTM_BLE_DEFAULT_ADV_CHNL_MAP \
  (BTM_BLE_ADV_CHNL_37 | BTM_BLE_ADV_CHNL_38 | BTM_BLE_ADV_CHNL_39)
#endif

/* advertising filter policy */
#define AP_SCAN_CONN_ALL 0x00 /* default */
#define AP_SCAN_WL_CONN_ALL 0x01
#define AP_SCAN_ALL_CONN_WL 0x02
#define AP_SCAN_CONN_WL 0x03
#define AP_SCAN_CONN_POLICY_MAX 0x04
typedef uint8_t tBTM_BLE_AFP;

/* default advertising filter policy */
#ifndef BTM_BLE_DEFAULT_AFP
#define BTM_BLE_DEFAULT_AFP AP_SCAN_CONN_ALL
#endif

/* scanning filter policy */
/* 0: accept adv packet from all, directed adv pkt not directed */
/*    to local device is ignored */
#define SP_ADV_ALL 0x00
/* 1: accept adv packet from device in white list, directed adv */
/*    packet not directed to local device is ignored */
#define SP_ADV_WL 0x01
/* 2: accept adv packet from all, directed adv pkt */
/*    not directed to me is ignored except direct adv with RPA */
#define SP_ADV_ALL_RPA_DIR_ADV 0x02
/* 3: accept adv packet from device in white list, directed */
/*    adv pkt not directed to me is ignored except direct adv with RPA */
#define SP_ADV_WL_RPA_DIR_ADV 0x03

typedef uint8_t tBTM_BLE_SFP;
typedef uint8_t tBTM_STATUS;

#ifndef BTM_BLE_DEFAULT_SFP
#define BTM_BLE_DEFAULT_SFP SP_ADV_ALL
#endif

/* adv parameter boundary values */
#define BTM_BLE_ADV_INT_MIN 0x0020
#define BTM_BLE_ADV_INT_MAX 0x4000

/* Full scan boundary values */
#define BTM_BLE_ADV_SCAN_FULL_MIN 0x00
#define BTM_BLE_ADV_SCAN_FULL_MAX 0x64

/* Partial scan boundary values */
#define BTM_BLE_ADV_SCAN_TRUNC_MIN BTM_BLE_ADV_SCAN_FULL_MIN
#define BTM_BLE_ADV_SCAN_TRUNC_MAX BTM_BLE_ADV_SCAN_FULL_MAX

/* Threshold values */
#define BTM_BLE_ADV_SCAN_THR_MIN BTM_BLE_ADV_SCAN_FULL_MIN
#define BTM_BLE_ADV_SCAN_THR_MAX BTM_BLE_ADV_SCAN_FULL_MAX

/* connection parameter boundary values */
#define BTM_BLE_SCAN_INT_MIN 0x0004
#define BTM_BLE_SCAN_INT_MAX 0x4000
#define BTM_BLE_SCAN_WIN_MIN 0x0004
#define BTM_BLE_SCAN_WIN_MAX 0x4000
#define BTM_BLE_EXT_SCAN_INT_MAX 0x00FFFFFF
#define BTM_BLE_EXT_SCAN_WIN_MAX 0xFFFF
#define BTM_BLE_CONN_INT_MIN 0x0006
#define BTM_BLE_CONN_INT_MAX 0x0C80
#define BTM_BLE_CONN_LATENCY_MAX 500
#define BTM_BLE_CONN_SUP_TOUT_MIN 0x000A
#define BTM_BLE_CONN_SUP_TOUT_MAX 0x0C80
/* use this value when a specific value not to be overwritten */
#define BTM_BLE_CONN_PARAM_UNDEF 0xffff
#define BTM_BLE_SCAN_PARAM_UNDEF 0xffff

/* default connection parameters if not configured, use GAP recommended value
 * for auto/selective connection */
/* default scan interval */
#ifndef BTM_BLE_SCAN_FAST_INT
#define BTM_BLE_SCAN_FAST_INT 96 /* 30 ~ 60 ms (use 60)  = 96 *0.625 */
#endif
/* default scan window for background connection, applicable for auto connection
 * or selective connection */
#ifndef BTM_BLE_SCAN_FAST_WIN
#define BTM_BLE_SCAN_FAST_WIN 48 /* 30 ms = 48 *0.625 */
#endif

/* default scan paramter used in reduced power cycle (background scanning) */
#ifndef BTM_BLE_SCAN_SLOW_INT_1
#define BTM_BLE_SCAN_SLOW_INT_1 2048 /* 1.28 s   = 2048 *0.625 */
#endif
#ifndef BTM_BLE_SCAN_SLOW_WIN_1
#define BTM_BLE_SCAN_SLOW_WIN_1 48 /* 30 ms = 48 *0.625 */
#endif

/* default scan paramter used in reduced power cycle (background scanning) */
#ifndef BTM_BLE_SCAN_SLOW_INT_2
#define BTM_BLE_SCAN_SLOW_INT_2 4096 /* 2.56 s   = 4096 *0.625 */
#endif
#ifndef BTM_BLE_SCAN_SLOW_WIN_2
#define BTM_BLE_SCAN_SLOW_WIN_2 36 /* 22.5 ms = 36 *0.625 */
#endif

/* default connection interval min */
#ifndef BTM_BLE_CONN_INT_MIN_DEF
/* recommended min: 30ms  = 24 * 1.25 */
#define BTM_BLE_CONN_INT_MIN_DEF 24
#endif

/* default connectino interval max */
#ifndef BTM_BLE_CONN_INT_MAX_DEF
/* recommended max: 50 ms = 56 * 1.25 */
#define BTM_BLE_CONN_INT_MAX_DEF 40
#endif

/* default slave latency */
#ifndef BTM_BLE_CONN_SLAVE_LATENCY_DEF
#define BTM_BLE_CONN_SLAVE_LATENCY_DEF 0 /* 0 */
#endif

/* default supervision timeout */
#ifndef BTM_BLE_CONN_TIMEOUT_DEF
#define BTM_BLE_CONN_TIMEOUT_DEF 500
#endif

/* minimum supervision timeout */
#ifndef BTM_BLE_CONN_TIMEOUT_MIN_DEF
#define BTM_BLE_CONN_TIMEOUT_MIN_DEF 100
#endif

/* minimum acceptable connection interval */
#ifndef BTM_BLE_CONN_INT_MIN_LIMIT
#define BTM_BLE_CONN_INT_MIN_LIMIT 0x0009
#endif

/* minimum acceptable connection interval when there is bonded Hearing Aid
 * device */
#ifndef BTM_BLE_CONN_INT_MIN_HEARINGAID
#define BTM_BLE_CONN_INT_MIN_HEARINGAID 0x0010
#endif

#define BTM_CMAC_TLEN_SIZE 8 /* 64 bits */
#define BTM_BLE_AUTH_SIGN_LEN \
  12 /* BLE data signature length 8 Bytes + 4 bytes counter*/
typedef uint8_t BLE_SIGNATURE[BTM_BLE_AUTH_SIGN_LEN]; /* Device address */

#ifndef BTM_BLE_HOST_SUPPORT
#define BTM_BLE_HOST_SUPPORT 0x01
#endif

#ifndef BTM_BLE_SIMULTANEOUS_HOST
#define BTM_BLE_SIMULTANEOUS_HOST 0x00
#endif

/* Appearance Values Reported with BTM_BLE_AD_TYPE_APPEARANCE */
#define BTM_BLE_APPEARANCE_UKNOWN 0x0000
#define BTM_BLE_APPEARANCE_GENERIC_PHONE 0x0040
#define BTM_BLE_APPEARANCE_GENERIC_COMPUTER 0x0080
#define BTM_BLE_APPEARANCE_GENERIC_WATCH 0x00C0
#define BTM_BLE_APPEARANCE_SPORTS_WATCH 0x00C1
#define BTM_BLE_APPEARANCE_GENERIC_CLOCK 0x0100
#define BTM_BLE_APPEARANCE_GENERIC_DISPLAY 0x0140
#define BTM_BLE_APPEARANCE_GENERIC_REMOTE 0x0180
#define BTM_BLE_APPEARANCE_GENERIC_EYEGLASSES 0x01C0
#define BTM_BLE_APPEARANCE_GENERIC_TAG 0x0200
#define BTM_BLE_APPEARANCE_GENERIC_KEYRING 0x0240
#define BTM_BLE_APPEARANCE_GENERIC_MEDIA_PLAYER 0x0280
#define BTM_BLE_APPEARANCE_GENERIC_BARCODE_SCANNER 0x02C0
#define BTM_BLE_APPEARANCE_GENERIC_THERMOMETER 0x0300
#define BTM_BLE_APPEARANCE_THERMOMETER_EAR 0x0301
#define BTM_BLE_APPEARANCE_GENERIC_HEART_RATE 0x0340
#define BTM_BLE_APPEARANCE_HEART_RATE_BELT 0x0341
#define BTM_BLE_APPEARANCE_GENERIC_BLOOD_PRESSURE 0x0380
#define BTM_BLE_APPEARANCE_BLOOD_PRESSURE_ARM 0x0381
#define BTM_BLE_APPEARANCE_BLOOD_PRESSURE_WRIST 0x0382
#define BTM_BLE_APPEARANCE_GENERIC_HID 0x03C0
#define BTM_BLE_APPEARANCE_HID_KEYBOARD 0x03C1
#define BTM_BLE_APPEARANCE_HID_MOUSE 0x03C2
#define BTM_BLE_APPEARANCE_HID_JOYSTICK 0x03C3
#define BTM_BLE_APPEARANCE_HID_GAMEPAD 0x03C4
#define BTM_BLE_APPEARANCE_HID_DIGITIZER_TABLET 0x03C5
#define BTM_BLE_APPEARANCE_HID_CARD_READER 0x03C6
#define BTM_BLE_APPEARANCE_HID_DIGITAL_PEN 0x03C7
#define BTM_BLE_APPEARANCE_HID_BARCODE_SCANNER 0x03C8
#define BTM_BLE_APPEARANCE_GENERIC_GLUCOSE 0x0400
#define BTM_BLE_APPEARANCE_GENERIC_WALKING 0x0440
#define BTM_BLE_APPEARANCE_WALKING_IN_SHOE 0x0441
#define BTM_BLE_APPEARANCE_WALKING_ON_SHOE 0x0442
#define BTM_BLE_APPEARANCE_WALKING_ON_HIP 0x0443
#define BTM_BLE_APPEARANCE_GENERIC_CYCLING 0x0480
#define BTM_BLE_APPEARANCE_CYCLING_COMPUTER 0x0481
#define BTM_BLE_APPEARANCE_CYCLING_SPEED 0x0482
#define BTM_BLE_APPEARANCE_CYCLING_CADENCE 0x0483
#define BTM_BLE_APPEARANCE_CYCLING_POWER 0x0484
#define BTM_BLE_APPEARANCE_CYCLING_SPEED_CADENCE 0x0485
#define BTM_BLE_APPEARANCE_GENERIC_PULSE_OXIMETER 0x0C40
#define BTM_BLE_APPEARANCE_PULSE_OXIMETER_FINGERTIP 0x0C41
#define BTM_BLE_APPEARANCE_PULSE_OXIMETER_WRIST 0x0C42
#define BTM_BLE_APPEARANCE_GENERIC_WEIGHT 0x0C80
#define BTM_BLE_APPEARANCE_GENERIC_OUTDOOR_SPORTS 0x1440
#define BTM_BLE_APPEARANCE_OUTDOOR_SPORTS_LOCATION 0x1441
#define BTM_BLE_APPEARANCE_OUTDOOR_SPORTS_LOCATION_AND_NAV 0x1442
#define BTM_BLE_APPEARANCE_OUTDOOR_SPORTS_LOCATION_POD 0x1443
#define BTM_BLE_APPEARANCE_OUTDOOR_SPORTS_LOCATION_POD_AND_NAV 0x1444

/* Structure returned with Rand/Encrypt complete callback */
typedef struct {
  uint8_t status;
  uint8_t param_len;
  uint16_t opcode;
  uint8_t param_buf[OCTET16_LEN];
} tBTM_RAND_ENC;

/* General callback function for notifying an application that a synchronous
 * BTM function is complete. The pointer contains the address of any returned
 * data.
*/
typedef void(tBTM_RAND_ENC_CB)(tBTM_RAND_ENC* p1);

#define BTM_BLE_FILTER_TARGET_SCANNER 0x01
#define BTM_BLE_FILTER_TARGET_ADVR 0x00

#define BTM_BLE_POLICY_BLACK_ALL 0x00  /* relevant to both */
#define BTM_BLE_POLICY_ALLOW_SCAN 0x01 /* relevant to advertiser */
#define BTM_BLE_POLICY_ALLOW_CONN 0x02 /* relevant to advertiser */
#define BTM_BLE_POLICY_WHITE_ALL 0x03  /* relevant to both */

/* ADV data flag bit definition used for BTM_BLE_AD_TYPE_FLAG */
#define BTM_BLE_LIMIT_DISC_FLAG (0x01 << 0)
#define BTM_BLE_GEN_DISC_FLAG (0x01 << 1)
#define BTM_BLE_BREDR_NOT_SPT (0x01 << 2)
/* 4.1 spec adv flag for simultaneous BR/EDR+LE connection support */
#define BTM_BLE_DMT_CONTROLLER_SPT (0x01 << 3)
#define BTM_BLE_DMT_HOST_SPT (0x01 << 4)
#define BTM_BLE_NON_LIMIT_DISC_FLAG (0x00) /* lowest bit unset */
#define BTM_BLE_ADV_FLAG_MASK \
  (BTM_BLE_LIMIT_DISC_FLAG | BTM_BLE_BREDR_NOT_SPT | BTM_BLE_GEN_DISC_FLAG)
#define BTM_BLE_LIMIT_DISC_MASK (BTM_BLE_LIMIT_DISC_FLAG)

// TODO(jpawlowski): this should be removed with code that depend on it.
#define BTM_BLE_AD_BIT_FLAGS (0x00000001 << 1)

#define BTM_BLE_AD_TYPE_FLAG HCI_EIR_FLAGS_TYPE /* 0x01 */
#define BTM_BLE_AD_TYPE_16SRV_CMPL          \
  HCI_EIR_COMPLETE_16BITS_UUID_TYPE /* 0x03 \
                                       */
#define BTM_BLE_AD_TYPE_NAME_SHORT                                         \
  HCI_EIR_SHORTENED_LOCAL_NAME_TYPE                                /* 0x08 \
                                                                      */
#define BTM_BLE_AD_TYPE_NAME_CMPL HCI_EIR_COMPLETE_LOCAL_NAME_TYPE /* 0x09 */

#define BTM_BLE_AD_TYPE_APPEARANCE 0x19

/*  Security settings used with L2CAP LE COC */
#define BTM_SEC_LE_LINK_ENCRYPTED 0x01
#define BTM_SEC_LE_LINK_PAIRED_WITHOUT_MITM 0x02
#define BTM_SEC_LE_LINK_PAIRED_WITH_MITM 0x04

/*  Min/max Preferred  number of payload octets that the local Controller
    should include in a single Link Layer Data Channel PDU. */
#define BTM_BLE_DATA_SIZE_MAX 0x00fb
#define BTM_BLE_DATA_SIZE_MIN 0x001b

/*  Preferred maximum number of microseconds that the local Controller
    should use to transmit a single Link Layer Data Channel PDU. */
#define BTM_BLE_DATA_TX_TIME_MIN 0x0148
#define BTM_BLE_DATA_TX_TIME_MAX_LEGACY  0x0848
#define BTM_BLE_DATA_TX_TIME_MAX         0x4290

/* adv tx power level */
#define BTM_BLE_ADV_TX_POWER_MIN 0   /* minimum tx power */
#define BTM_BLE_ADV_TX_POWER_LOW 1   /* low tx power     */
#define BTM_BLE_ADV_TX_POWER_MID 2   /* middle tx power  */
#define BTM_BLE_ADV_TX_POWER_UPPER 3 /* upper tx power   */
#define BTM_BLE_ADV_TX_POWER_MAX 4   /* maximum tx power */
typedef uint8_t tBTM_BLE_ADV_TX_POWER;

/* adv tx power in dBm */
typedef struct {
  uint8_t adv_inst_max; /* max adv instance supported in controller */
  uint8_t rpa_offloading;
  uint16_t tot_scan_results_strg;
  uint8_t max_irk_list_sz;
  uint8_t filter_support;
  uint8_t max_filter;
  uint8_t energy_support;
  bool values_read;
  uint16_t version_supported;
  uint16_t total_trackable_advertisers;
  uint8_t extended_scan_support;
  uint8_t debug_logging_supported;
  uint8_t le_address_generation_offloading_support;
  uint32_t a2dp_source_offload_capability_mask;
  uint8_t quality_report_support;
  uint32_t dynamic_audio_buffer_support;
} tBTM_BLE_VSC_CB;

/* Stored the default/maximum/minimum buffer time for dynamic audio buffer.
 * For A2DP offload usage, the unit is millisecond.
 * For A2DP legacy usage, the unit is buffer queue size*/
typedef struct {
  uint16_t default_buffer_time;
  uint16_t maximum_buffer_time;
  uint16_t minimum_buffer_time;
} tBTM_BT_DYNAMIC_AUDIO_BUFFER_CB;

typedef void(tBTM_BLE_ADV_DATA_CMPL_CBACK)(tBTM_STATUS status);

#ifndef BTM_BLE_MULTI_ADV_MAX
#define BTM_BLE_MULTI_ADV_MAX                           \
  16 /* controller returned adv_inst_max should be less \
        than this number */
#endif

typedef uint8_t tGATT_IF;

typedef void(tBTM_BLE_SCAN_THRESHOLD_CBACK)(tBTM_BLE_REF_VALUE ref_value);
using tBTM_BLE_SCAN_REP_CBACK =
    base::Callback<void(uint8_t /* status */, uint8_t /* report_format */,
                        uint8_t /* num_reports */, std::vector<uint8_t>)>;

#ifndef BTM_BLE_BATCH_SCAN_MAX
#define BTM_BLE_BATCH_SCAN_MAX 5
#endif

#ifndef BTM_BLE_BATCH_REP_MAIN_Q_SIZE
#define BTM_BLE_BATCH_REP_MAIN_Q_SIZE 2
#endif

typedef enum {
  BTM_BLE_SCAN_INVALID_STATE = 0,
  BTM_BLE_SCAN_ENABLE_CALLED = 1,
  BTM_BLE_SCAN_ENABLED_STATE = 2,
  BTM_BLE_SCAN_DISABLE_CALLED = 3,
  BTM_BLE_SCAN_DISABLED_STATE = 4
} tBTM_BLE_BATCH_SCAN_STATE;

enum { BTM_BLE_DISCARD_OLD_ITEMS, BTM_BLE_DISCARD_LOWER_RSSI_ITEMS };
typedef uint8_t tBTM_BLE_DISCARD_RULE;

typedef struct {
  tBTM_BLE_BATCH_SCAN_STATE cur_state;
  tBTM_BLE_BATCH_SCAN_MODE scan_mode;
  uint32_t scan_interval;
  uint32_t scan_window;
  tBLE_ADDR_TYPE addr_type;
  tBTM_BLE_DISCARD_RULE discard_rule;
  tBTM_BLE_SCAN_THRESHOLD_CBACK* p_thres_cback;
  tBTM_BLE_REF_VALUE ref_value;
} tBTM_BLE_BATCH_SCAN_CB;

/* filter selection bit index  */
#define BTM_BLE_PF_ADDR_FILTER 0
#define BTM_BLE_PF_SRVC_DATA 1
#define BTM_BLE_PF_SRVC_UUID 2
#define BTM_BLE_PF_SRVC_SOL_UUID 3
#define BTM_BLE_PF_LOCAL_NAME 4
#define BTM_BLE_PF_MANU_DATA 5
#define BTM_BLE_PF_SRVC_DATA_PATTERN 6
#define BTM_BLE_PF_TDS_DATA 7
#define BTM_BLE_PF_GROUP_FILTER 8
/* when passed in payload filter type all, only clear action is applicable */
#define BTM_BLE_PF_TYPE_ALL 9
#define BTM_BLE_PF_TYPE_MAX 10

/* max number of filter spot fors different filter type */
#ifndef BTM_BLE_MAX_UUID_FILTER
#define BTM_BLE_MAX_UUID_FILTER 8
#endif
#ifndef BTM_BLE_MAX_ADDR_FILTER
#define BTM_BLE_MAX_ADDR_FILTER 8
#endif
#ifndef BTM_BLE_PF_STR_COND_MAX
#define BTM_BLE_PF_STR_COND_MAX 4 /* apply to manu data , or local name */
#endif
#ifndef BTM_BLE_PF_STR_LEN_MAX
#define BTM_BLE_PF_STR_LEN_MAX 29 /* match for first 29 bytes */
#endif
#ifndef BTM_BLE_PF_GROUP_DATA_LEN
#define BTM_BLE_PF_GROUP_DATA_LEN 6 /* length of GROUP data */
#endif

typedef uint8_t tBTM_BLE_PF_COND_TYPE;

#define BTM_BLE_PF_LOGIC_OR 0
#define BTM_BLE_PF_LOGIC_AND 1
typedef uint8_t tBTM_BLE_PF_LOGIC_TYPE;

#define BTM_BLE_PF_ENABLE 1
#define BTM_BLE_PF_CONFIG 2
typedef uint8_t tBTM_BLE_PF_ACTION;

typedef uint8_t tBTM_BLE_PF_FILT_INDEX;

typedef uint8_t tBTM_BLE_PF_AVBL_SPACE;

enum {
  BTM_BLE_SCAN_COND_ADD,
  BTM_BLE_SCAN_COND_DELETE,
  BTM_BLE_SCAN_COND_CLEAR = 2
};
typedef uint8_t tBTM_BLE_SCAN_COND_OP;

/* BLE adv payload filtering config complete callback */
using tBTM_BLE_PF_CFG_CBACK = base::Callback<void(
    uint8_t /* avbl_space */, uint8_t /* action */, uint8_t /* status */)>;

/* BLE adv payload filtering status setup complete callback */
using tBTM_BLE_PF_STATUS_CBACK =
    base::Callback<void(uint8_t /*action*/, tBTM_STATUS /* status */)>;

/* BLE adv payload filtering param setup complete callback */
using tBTM_BLE_PF_PARAM_CB = base::Callback<void(
    uint8_t /* avbl_space */, uint8_t /* action */, uint8_t /* status */)>;

/* per device filter + one generic filter indexed by 0 */
#define BTM_BLE_MAX_FILTER_COUNTER (BTM_BLE_MAX_ADDR_FILTER + 1)

#ifndef BTM_CS_IRK_LIST_MAX
#define BTM_CS_IRK_LIST_MAX 0x20
#endif

typedef struct {
  bool in_use;
  RawAddress bd_addr;
  uint8_t pf_counter[BTM_BLE_PF_TYPE_MAX]; /* number of filter indexed by
                                              tBTM_BLE_PF_COND_TYPE */
} tBTM_BLE_PF_COUNT;

typedef struct {
  bool enable;
  uint8_t op_type;
  tBTM_BLE_PF_COUNT* p_addr_filter_count; /* per BDA filter array */
  tBLE_BD_ADDR cur_filter_target;
} tBTM_BLE_ADV_FILTER_CB;

/* Sub codes */
#define BTM_BLE_META_PF_ENABLE 0x00
#define BTM_BLE_META_PF_FEAT_SEL 0x01
#define BTM_BLE_META_PF_ADDR 0x02
#define BTM_BLE_META_PF_UUID 0x03
#define BTM_BLE_META_PF_SOL_UUID 0x04
#define BTM_BLE_META_PF_LOCAL_NAME 0x05
#define BTM_BLE_META_PF_MANU_DATA 0x06
#define BTM_BLE_META_PF_SRVC_DATA 0x07
#define BTM_BLE_META_PF_TDS_DATA 0x08
#define BTM_BLE_META_PF_GROUP 0x09
#define BTM_BLE_META_PF_ALL 0x0A

typedef uint8_t BTM_BLE_ADV_STATE;
typedef uint8_t BTM_BLE_ADV_INFO_PRESENT;
typedef uint8_t BTM_BLE_RSSI_VALUE;
typedef uint16_t BTM_BLE_ADV_INFO_TIMESTAMP;

#define ADV_INFO_PRESENT 0x00
#define NO_ADV_INFO_PRESENT 0x01

typedef btgatt_track_adv_info_t tBTM_BLE_TRACK_ADV_DATA;

typedef void(tBTM_BLE_TRACK_ADV_CBACK)(
    tBTM_BLE_TRACK_ADV_DATA* p_track_adv_data);

typedef uint8_t tBTM_BLE_TRACK_ADV_EVT;

typedef struct {
  tBTM_BLE_REF_VALUE ref_value;
  tBTM_BLE_TRACK_ADV_CBACK* p_track_cback;
} tBTM_BLE_ADV_TRACK_CB;

enum { BTM_BLE_TRACK_ADV_ADD, BTM_BLE_TRACK_ADV_REMOVE };

typedef uint8_t tBTM_BLE_TRACK_ADV_ACTION;

typedef uint8_t tBTM_BLE_BATCH_SCAN_EVT;

typedef uint32_t tBTM_BLE_TX_TIME_MS;
typedef uint32_t tBTM_BLE_RX_TIME_MS;
typedef uint32_t tBTM_BLE_IDLE_TIME_MS;
typedef uint32_t tBTM_BLE_ENERGY_USED;

typedef void(tBTM_BLE_ENERGY_INFO_CBACK)(tBTM_BLE_TX_TIME_MS tx_time,
                                         tBTM_BLE_RX_TIME_MS rx_time,
                                         tBTM_BLE_IDLE_TIME_MS idle_time,
                                         tBTM_BLE_ENERGY_USED energy_used,
                                         tBTM_STATUS status);

typedef struct {
  tBTM_BLE_ENERGY_INFO_CBACK* p_ener_cback;
} tBTM_BLE_ENERGY_INFO_CB;

typedef void(tBTM_BLE_CTRL_FEATURES_CBACK)(tBTM_STATUS status);

typedef void (*tBLE_SCAN_PARAM_SETUP_CBACK)(tGATT_IF client_if,
                                            tBTM_STATUS status);

#endif  // BTM_BLE_API_TYPES_H

#ifndef LE_ISO_HCI_CMD_PARAM
#define LE_ISO_HCI_CMD_PARAM

/* Return parameters of HCI_LE_Set_CIG_Parameters command complete*/
typedef struct {
    uint8_t status;
    uint8_t cig_id;
    uint8_t cis_count;
    uint16_t *conn_handle;
} tBTM_BLE_SET_CIG_RET_PARAM;

/* Return parameters of HCI_LE_CIS_Established Event*/
typedef struct {
    uint8_t status;
    uint16_t connection_handle;
    SYNC_DELAY cig_sync_delay;
    SYNC_DELAY cis_sync_delay;
    TRANSPORT_LATENCY transport_latency_m_to_s;
    TRANSPORT_LATENCY transport_latency_s_to_m;
    uint8_t phy_m_to_s;
    uint8_t phy_s_to_m;
    uint8_t nse;
    uint8_t bn_m_to_s;
    uint8_t bn_s_to_m;
    uint8_t ft_m_to_s;
    uint8_t ft_s_to_m;
    uint16_t max_pdu_m_to_s;
    uint16_t max_pdu_s_to_m;
    uint16_t iso_interval;
} tBTM_BLE_CIS_ESTABLISHED_EVT_PARAM;

/* Return parameters of HCI_LE_Request_Peer_SCA_Complete Event*/
typedef struct {
  uint8_t status;
  uint16_t conn_handle;
  uint8_t sca;
} tBTM_BLE_PEER_SCA_PARAM;

/* Return parameters of HCI_LE_CIS_REQUEST EVENT*/
typedef struct {
  uint16_t acl_conn_handle;
  uint16_t cis_conn_handle;
  uint8_t cig_id;
  uint8_t cis_id;
} tBTM_BLE_CIS_REQ_EVT_PARAM;

/* Return parameters of HCI_LE_Read_ISO_Link_Quality command complete*/
typedef struct {
  uint8_t status;
  uint16_t conn_handle;
  uint32_t tx_unacked_packets;
  uint32_t tx_flushed_packets;
  uint32_t tx_last_subevent_packets;
  uint32_t retransmitted_packets;
  uint32_t crc_error_packets;
  uint32_t rx_unreceived_packets;
  uint32_t duplicate_packets;
} tBTM_BLE_ISO_LINK_QLT;

/* Return parameters of HCI_LE_Read_ISO_TX_Sync command complete*/
typedef struct {
  uint8_t status;
  uint16_t conn_handle;
  uint16_t packet_sequence_number;
  uint32_t time_stamp;
  TIME_OFFSET time_offset;
} tBTM_BLE_READ_ISO_TX_SYNC_PARAM;

/* Return parameters of HCI_LE_Enhanced_Read_Transmit_Power_Level command complete*/
typedef struct {
  uint8_t status;
  uint16_t conn_handle;
  uint8_t phy;
  uint8_t current_transmit_power_level;
  uint8_t max_transmit_power_level;
} tBTM_BLE_ENH_READ_TX_POWER_LEVEL;

/* Return parameters of HCI_LE_Read_Remote_Transmit_Power_Level command complete*/
typedef struct {
  uint8_t status;
  uint16_t conn_handle;
  uint8_t phy;
  uint8_t current_transmit_power_level;
  uint8_t max_transmit_power_level;
  uint8_t delta;
} tBTM_BLE_READ_REMOTE_TX_POWER_LEVEL;

/* Return parameters of HCI_LE_Transmit_Power_Reporting Event*/
typedef struct {
  uint8_t status;
  uint16_t conn_handle;
  uint8_t reason;
  uint8_t phy;
  int8_t tx_pow_level;
  uint8_t tx_pow_level_flag;
  int8_t delta;
} tBTM_BLE_TX_POW_EVT_PARAM;

/* Return parameters of HCI_LE_Set_CIG_Parameters_Test command complete*/
typedef struct {
  uint8_t status;
  uint8_t cig_id;
  uint8_t cis_count;
  uint16_t* conn_handle;
} tBTM_BLE_SET_CIG_PARAM_TEST_RET;

/* Return parameters of HCI_LE_ISO_Test_End command complete*/
typedef struct {
  uint8_t status;
  uint16_t conn_handle;
  uint32_t received_packet_count;
  uint32_t missed_packet_count;
  uint32_t failed_packet_count;
} tBTM_BLE_ISO_TEST_END_RET;

/* Return parameters of HCI_LE_ISO_Read_Test_Counters command complete*/
typedef struct {
  uint8_t status;
  uint16_t conn_handle;
  uint32_t received_packet_count;
  uint32_t missed_packet_count;
  uint32_t failed_packet_count;
} tBTM_BLE_ISO_TEST_COUNTERS_RET;

/* Return parameters of HCI_LE_Path_Loss_Threshold Event*/
typedef struct {
  uint16_t conn_handle;
  uint8_t current_path_loss;
  uint8_t zone_entered;
} tBTM_BLE_PATHLOSS_THRESHOLD_RET;

// Bluetooth Spec 5.2 HCI Command Callbacks
/* HCI_LE_Set_CIG_Parameters command complete callback*/
typedef void (tBTM_BLE_SET_CIG_PARAM_CMPL_CB) (tBTM_BLE_SET_CIG_RET_PARAM* param);

/* HCI_LE_CIS_Established command status event */
typedef void (tBTM_BLE_CREATE_CIS_CB) (uint8_t status);

/* HCI_LE_CIS_Established event callback*/
typedef void (tBTM_BLE_CIS_ESTABLISHED_CB) (tBTM_BLE_CIS_ESTABLISHED_EVT_PARAM * param);

/* Disconnection complete callback for CIS*/
typedef void (tBTM_BLE_CIS_DISCONNECTED_CB) (uint8_t status, uint16_t cis_handle,
                                             uint8_t reason);

/* HCI_LE_CIS_Request event callback*/
typedef void (tBTM_BLE_CIS_REQ_EVT_CB) (tBTM_BLE_CIS_REQ_EVT_PARAM* param);

/* HCI_LE_Remove_CIG command complete callback*/
typedef void (tBTM_BLE_REMOVE_CIG_CMPL_CB) (uint8_t status, uint8_t cig_id);

/* HCI_LE_Setup_ISO_Data_Path command complete callback*/
typedef void (tBTM_BLE_SETUP_ISO_DATA_PATH_CMPL_CB) (uint8_t status, uint16_t conn_handle);

/* HCI_LE_Remove_ISO_Data_Path command complete callback*/
typedef void (tBTM_BLE_REMOVE_ISO_DATA_PATH_CMPL_CB) (uint8_t status, uint16_t conn_handle);

/* HCI_LE_Request_Peer_SCA_Complete event callback*/
typedef void (tBTM_BLE_REQUEST_PEER_SCA_COMPLETE_CB) (tBTM_BLE_PEER_SCA_PARAM* peer_sca_param);

/* HCI_LE_Reject_CIS_Request command complete callback*/
typedef void (tBTM_BLE_REJECT_CIS_CB) (uint8_t status, uint16_t conn_handle);

/* HCI_LE_Read_ISO_Link_Quality command complete callback*/
typedef void (tBTM_BLE_READ_ISO_LINK_QLT_CB) (tBTM_BLE_ISO_LINK_QLT* lnk_qlt_param);

/* HCI_LE_Read_ISO_TX_Sync command complete callback*/
typedef void (tBTM_BLE_READ_ISO_TX_SYNC_CB) (tBTM_BLE_READ_ISO_TX_SYNC_PARAM *ret_param);

/* HCI_LE_Enhanced_Read_Transmit_Power_Level command complete callback*/
typedef void (tBTM_BLE_ENHANCED_READ_TRANSMIT_POWER_LEVEL_CB) (
                                            tBTM_BLE_ENH_READ_TX_POWER_LEVEL* ret_param);

/* HCI_LE_TRANSMIT_POWER_REPORTING callback*/
typedef void (tBTM_BLE_READ_REMOTE_TX_POW_LEVEL_CB) (
              tBTM_BLE_READ_REMOTE_TX_POWER_LEVEL* ret_param);

/* HCI_LE_Set_Path_Loss_Reporting_Parameters callback*/
typedef void (tBTM_BLE_SET_PATH_LOSS_REPORTING_CB) (uint8_t status, uint16_t conn_handle);

/* HCI_LE_Set_Path_Loss_Reporting_Enable command complete callback*/
typedef void (tBTM_BLE_SET_PATH_LOSS_REPORTING_ENABLE_CB) (uint8_t status,
                                                           uint16_t conn_handle);

/* HCI_LE_Path_Loss_Threshold Event callback*/
typedef void (tBTM_BLE_PATH_LOSS_THRESHOLD_CB) (tBTM_BLE_PATHLOSS_THRESHOLD_RET* ret_param);

/* HCI_LE_Set_Transmit_Power_Reporting_Enable command complete callback*/
typedef void (tBTM_BLE_SET_TRANSMIT_POWER_REPORTING_ENABLE_CB) (uint8_t status,
                                                                uint16_t conn_handle);

/* HCI_LE_Transmit_Power_Reporting event callback*/
typedef void (tBTM_BLE_TRANSMIT_POWER_REPORTING_EVENT_CB) (tBTM_BLE_TX_POW_EVT_PARAM* param);

/* HCI_LE_Set_CIG_Parameters_Test command complete callback*/
typedef void (tBTM_BLE_SET_CIG_PARAMETERS_TEST_CB) (tBTM_BLE_SET_CIG_PARAM_TEST_RET* ret_param);

/* HCI_LE_ISO_Test_End command complete callback*/
typedef void (tBTM_BLE_ISO_TEST_END_CB) (tBTM_BLE_ISO_TEST_END_RET* ret_param);

/* HCI_LE_ISO_Read_Test_Counters  command complete callback*/
typedef void (tBTM_BLE_ISO_READ_TEST_COUNTERS_CB) (tBTM_BLE_ISO_TEST_COUNTERS_RET* ret_param);

/* HCI_LE_ISO_Receive_Test command complete callback*/
typedef void (tBTM_BLE_ISO_RECEIVE_TEST_CB) (uint8_t status,	uint16_t conn_handle);

/* HCI_LE_ISO_Transmit_Test command complete callback*/
typedef void (tBTM_BLE_ISO_TRANSMIT_TEST_CB) (uint8_t status, uint16_t conn_handle);

/* HCI_LE_Transmitter_Test_v4 command complete callback*/
typedef void (tBTM_BLE_TRANSMITTER_TEST_V4_CB) (uint8_t status);

// Callabck function pointers of HCI Commands after receiving Command Complete or HCI Event
typedef struct {
  tBTM_BLE_SET_CIG_PARAM_CMPL_CB* set_cig_param = NULL;
  tBTM_BLE_CREATE_CIS_CB* create_cis_status_cb = NULL;
  tBTM_BLE_CIS_ESTABLISHED_CB* cis_established_evt_cb = NULL;
  tBTM_BLE_CIS_REQ_EVT_CB* cis_request_evt_cb = NULL;
  tBTM_BLE_REMOVE_CIG_CMPL_CB* remove_cig = NULL;
  tBTM_BLE_CIS_DISCONNECTED_CB* cis_disconnected_cb = NULL;
  tBTM_BLE_SETUP_ISO_DATA_PATH_CMPL_CB* setup_iso_datapath = NULL;
  tBTM_BLE_REMOVE_ISO_DATA_PATH_CMPL_CB* remove_iso_datapath = NULL;
  tBTM_BLE_REQUEST_PEER_SCA_COMPLETE_CB* peer_sca_cmpl = NULL;
  tBTM_BLE_REJECT_CIS_CB* reject_cis_cb = NULL;
  tBTM_BLE_READ_ISO_LINK_QLT_CB* iso_link_qly_cb = NULL;
  tBTM_BLE_READ_ISO_TX_SYNC_CB* iso_tx_sync_cb = NULL;
  tBTM_BLE_ENHANCED_READ_TRANSMIT_POWER_LEVEL_CB* tx_pow_level_cb = NULL;
  tBTM_BLE_READ_REMOTE_TX_POW_LEVEL_CB* remote_tx_pow_cb = NULL;
  tBTM_BLE_SET_PATH_LOSS_REPORTING_CB* pathloss_rpt_cb = NULL;
  tBTM_BLE_SET_PATH_LOSS_REPORTING_ENABLE_CB* pathloss_rpt_enable_cb = NULL;
  tBTM_BLE_PATH_LOSS_THRESHOLD_CB* pathloss_threshold_evt_cb = NULL;
  tBTM_BLE_SET_TRANSMIT_POWER_REPORTING_ENABLE_CB* tx_pow_rpt_enable_cb = NULL;
  tBTM_BLE_TRANSMIT_POWER_REPORTING_EVENT_CB* tx_pow_rpt_evt_cb = NULL;
  tBTM_BLE_SET_CIG_PARAMETERS_TEST_CB* cig_param_test_cmpl = NULL;
  tBTM_BLE_ISO_TEST_END_CB* iso_test_end_cmpl = NULL;
  tBTM_BLE_ISO_READ_TEST_COUNTERS_CB* read_test_cnt_cmpl = NULL;
  tBTM_BLE_ISO_RECEIVE_TEST_CB* iso_rcv_test_cmpl = NULL;
  tBTM_BLE_ISO_TRANSMIT_TEST_CB* iso_tx_test_cmpl = NULL;
  tBTM_BLE_TRANSMITTER_TEST_V4_CB* tx_test_v4_cmpl = NULL;
} tBTM_BLE_HCI_CMD_CB;

/* CIS configuration params used in HCI_LE_Set_CIG_Parameters*/
typedef struct {
  uint8_t cis_id;
  uint16_t max_sdu_m_to_s;
  uint16_t max_sdu_s_to_m;
  uint8_t phy_m_to_s;
  uint8_t phy_s_to_m;
  uint8_t rtn_m_to_s;
  uint8_t rtn_s_to_m;
} tBTM_BLE_CIS_CONFIG;

/* command parameters of HCI_LE_Set_CIG_Parameters */
typedef struct {
  uint8_t cig_id;
  SDU_INTERVAL sdu_int_m_to_s;
  SDU_INTERVAL sdu_int_s_to_m;
  uint8_t slave_clock_accuracy;
  uint8_t packing;
  uint8_t framing;
  uint16_t max_transport_latency_m_to_s;
  uint16_t max_transport_latency_s_to_m;
  uint8_t cis_count;
  std::vector<tBTM_BLE_CIS_CONFIG> cis_config;
  tBTM_BLE_SET_CIG_PARAM_CMPL_CB* p_cb;
} tBTM_BLE_ISO_SET_CIG_CMD_PARAM;

/* Associated connection handles of ACL and ISO link*/
typedef struct {
  uint16_t cis_conn_handle;
  uint16_t acl_conn_handle;
} tBTM_BLE_CHANNEL_MAP;

/* command parameters of HCI_LE_Create_CIS Command*/
typedef struct {
  uint8_t cis_count;
  std::vector<tBTM_BLE_CHANNEL_MAP> link_conn_handles;
  tBTM_BLE_CREATE_CIS_CB* p_cb;
  tBTM_BLE_CIS_ESTABLISHED_CB* p_evt_cb;
} tBTM_BLE_ISO_CREATE_CIS_CMD_PARAM;

/* command parameters of HCI_LE_Setup_ISO_Data_Path*/
typedef struct {
  uint16_t conn_handle;
  uint8_t data_path_dir;
  uint8_t data_path_id;
  CODEC_ID codec_id;
  CONTROLLER_DELAY cont_delay;
  uint8_t codec_config_length;
  uint8_t *codec_config;
  tBTM_BLE_SETUP_ISO_DATA_PATH_CMPL_CB* p_cb;
} tBTM_BLE_SET_ISO_DATA_PATH_PARAM;

/* command parameters of HCI_LE_Set_Path_Loss_Reporting_Parameters*/
typedef struct {
  uint16_t conn_handle;
  uint8_t high_threshold;
  uint8_t high_hysteresis;
  uint8_t low_threshold;
  uint8_t low_hysteresis;
  uint16_t min_time_spent;
  tBTM_BLE_SET_PATH_LOSS_REPORTING_CB* p_cb;
} tBTM_BLE_SET_PATH_LOSS_REPORTING_PARAM;

/* CIS configuration params used in HCI_LE_Set_CIG_Parameters*/
typedef struct {
  uint8_t cis_id;
  uint8_t nse;
  uint16_t max_sdu_m_to_s;
  uint16_t max_sdu_s_to_m;
  uint16_t max_pdu_m_to_s;
  uint16_t max_pdu_s_to_m;
  uint8_t phy_m_to_s;
  uint8_t phy_s_to_m;
  uint8_t bn_m_to_s;
  uint8_t bn_s_to_m;
} tBTM_BLE_CIS_TEST_CONFIG;

/* command parameters of HCI_LE_Set_CIG_Parameters_Test*/
typedef struct {
  uint8_t cig_id;
  SDU_INTERVAL sdu_int_m_to_s;
  SDU_INTERVAL sdu_int_s_to_m;
  uint8_t ft_m_to_s;
  uint8_t ft_s_to_m;
  uint16_t iso_interval;
  uint8_t slave_clock_accuracy;
  uint8_t packing;
  uint8_t framing;
  uint8_t cis_count;
  std::vector<tBTM_BLE_CIS_TEST_CONFIG> cis_config;
  tBTM_BLE_SET_CIG_PARAMETERS_TEST_CB* p_cb;
} tBTM_BLE_SET_CIG_PARAM_TEST;

/* command parameters of HCI_LE_Transmitter_Test[v4]*/
typedef struct {
  uint8_t tx_channel;
  uint8_t test_data_length;
  uint8_t packet_payload;
  uint8_t phy;
  uint8_t cte_length;
  uint8_t cte_type;
  uint8_t switching_pattern_length;
  uint8_t* antenna_ids;
  uint8_t transmit_power_level;
  tBTM_BLE_TRANSMITTER_TEST_V4_CB* p_cb;
} tBTM_BLE_TRANSMITTER_TEST_PARAM;

/* Pending CIS connection management control block */
typedef struct {
  std::vector<uint16_t> *cis_handles;
  alarm_t* conn_timeout_alarm = NULL;;
  tBTM_BLE_CREATE_CIS_CB* create_cis_status_cb = NULL;
  tBTM_BLE_CIS_ESTABLISHED_CB* cis_established_evt_cb = NULL;
} tBTM_BLE_PENDING_CIS_CONN;

#endif
