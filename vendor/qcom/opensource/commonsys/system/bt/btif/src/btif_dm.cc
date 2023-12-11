/******************************************************************************
 * Copyright (C) 2017, The Linux Foundation. All rights reserved.
 * Not a Contribution.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted (subject to the limitations in the
 * disclaimer below) provided that the following conditions are met:
 *
 * * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *
 * * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *
 * * Neither the name of The Linux Foundation nor the names of its
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 * NO EXPRESS OR IMPLIED LICENSES TO ANY PARTY'S PATENT RIGHTS ARE
 * GRANTED BY THIS LICENSE. THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT
 * HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
 * GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER
 * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
 * IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 ******************************************************************************/
/******************************************************************************
 *
 *  Copyright (C) 2009-2012 Broadcom Corporation
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

/*******************************************************************************
 *
 *  Filename:      btif_dm.c
 *
 *  Description:   Contains Device Management (DM) related functionality
 *
 *
 ******************************************************************************/

#define LOG_TAG "bt_btif_dm"

#include "btif_dm.h"

#include <base/bind.h>
#include <base/logging.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>
#include <iterator>
#include <map>

#include <mutex>

#include <bluetooth/uuid.h>
#include "hardware/vendor.h"

#include <hardware/bluetooth.h>
#include <hardware/bt_hearing_aid.h>

#include "advertise_data_parser.h"
#include "bt_common.h"
#include "bta_closure_api.h"
#include "bta_gatt_api.h"
#include "btif_api.h"
#include "btif_bqr.h"
#include "btif_config.h"
#include "btif_dm.h"
#include "btif_av.h"
#include "btif_gatt.h"
#include "btif_hf.h"
#include "btif_hd.h"
#include "btif_hh.h"
#include "btif_sdp.h"
#include "btif_storage.h"
#include "btif_util.h"
#include "btu.h"
#include "bta/include/bta_dm_api.h"
#include "device/include/controller.h"
#include "device/include/interop.h"
#include "internal_include/stack_config.h"
#include "osi/include/allocator.h"
#include "osi/include/log.h"
#include "osi/include/metrics.h"
#include "osi/include/osi.h"
#include "osi/include/properties.h"
#include "stack/btm/btm_int.h"
#include "stack_config.h"
#include "stack/sdp/sdpint.h"


#include "stack/sdp/sdpint.h"
#include "btif_tws_plus.h"
#include "device/include/device_iot_config.h"
#include "stack_interface.h"
#ifdef ADV_AUDIO_FEATURE
#include "btif_dm_adv_audio.h"
#include "bta_dm_adv_audio.h"
#endif

using bluetooth::Uuid;
/******************************************************************************
 *  Constants & Macros
 *****************************************************************************/
#define BTIF_DM_GET_REMOTE_PROP(b,t,v,l,p) \
      {p.type=t;p.val=v;p.len=l;btif_storage_get_remote_device_property(b,&p);}

const Uuid UUID_HEARING_AID = Uuid::FromString("FDF0");

#define COD_MASK 0x07FF

#define COD_UNCLASSIFIED ((0x1F) << 8)
#define COD_HID_KEYBOARD 0x0540
#define COD_HID_POINTING 0x0580
#define COD_HID_COMBO 0x05C0
#define COD_HID_MAJOR 0x0500
#define COD_HID_MASK 0x0700
#define COD_AV_HEADSETS 0x0404
#define COD_AV_HANDSFREE 0x0408
#define COD_AV_HEADPHONES 0x0418
#define COD_AV_PORTABLE_AUDIO 0x041C
#define COD_AV_HIFI_AUDIO 0x0428

#define BTIF_DM_DEFAULT_INQ_MAX_RESULTS 0
#define BTIF_DM_DEFAULT_INQ_MAX_DURATION 10
#define BTIF_DM_MAX_SDP_ATTEMPTS_AFTER_PAIRING 2

#define NUM_TIMEOUT_RETRIES 2

#define PROPERTY_PRODUCT_MODEL "ro.product.model"
#define DEFAULT_LOCAL_NAME_MAX 31
#if (DEFAULT_LOCAL_NAME_MAX > BTM_MAX_LOC_BD_NAME_LEN)
#error "default btif local name size exceeds stack supported length"
#endif

#if (BTA_HOST_INTERLEAVE_SEARCH == TRUE)
#define BTIF_DM_INTERLEAVE_DURATION_BR_ONE 2
#define BTIF_DM_INTERLEAVE_DURATION_LE_ONE 2
#define BTIF_DM_INTERLEAVE_DURATION_BR_TWO 3
#define BTIF_DM_INTERLEAVE_DURATION_LE_TWO 4
#endif

#define BTIF_DM_SDP_DELAY_TIMER_MS 500

#define ENCRYPTED_BREDR 2
#define ENCRYPTED_LE 4

#define INVALID_MANUFACTURER 0

#define BTIF_DM_ENABLE_MCAST_RESTRICTIONS FALSE
typedef struct {
  bt_bond_state_t state;
  RawAddress static_bdaddr;
  RawAddress bd_addr;
  tBTM_BOND_TYPE bond_type;
  uint8_t pin_code_len;
  uint8_t is_ssp;
  uint8_t auth_req;
  uint8_t io_cap;
  uint8_t autopair_attempts;
  uint8_t timeout_retries;
  uint8_t is_local_initiated;
  uint8_t sdp_attempts;
  uint8_t is_adv_audio;
  bool is_le_only;
  bool is_le_nc; /* LE Numeric comparison */
  btif_dm_ble_cb_t ble;
} btif_dm_pairing_cb_t;

// TODO(jpawlowski): unify ?
// btif_dm_local_key_id_t == tBTM_BLE_LOCAL_ID_KEYS == tBTA_BLE_LOCAL_ID_KEYS
typedef struct {
  Octet16 ir;
  Octet16 irk;
  Octet16 dhk;
} btif_dm_local_key_id_t;

typedef struct {
  bool is_er_rcvd;
  Octet16 er;
  bool is_id_keys_rcvd;
  btif_dm_local_key_id_t id_keys; /* ID kyes */

} btif_dm_local_key_cb_t;

typedef struct {
  RawAddress bd_addr;
  BD_NAME bd_name;
} btif_dm_remote_name_t;

/* this structure holds optional OOB data for remote device */
typedef struct {
  RawAddress bdaddr;       /* peer bdaddr */
  tBT_TRANSPORT transport; /* BR/EDR or LE */
  int data_present;        /* What type(s) of OOB Data present */
  bt_oob_data_t p192_data; /* P192 Data or empty */
  bt_oob_data_t p256_data; /* P256 Data or empty */
} btif_dm_oob_cb_t;

typedef struct {
  RawAddress bdaddr;
  uint8_t transport; /* 0=Unknown, 1=BR/EDR, 2=LE */
} btif_dm_create_bond_cb_t;

typedef struct {
  uint8_t status;
  uint8_t ctrl_state;
  uint64_t tx_time;
  uint64_t rx_time;
  uint64_t idle_time;
  uint64_t energy_used;
} btif_activity_energy_info_cb_t;

typedef struct { unsigned int manufact_id; } skip_sdp_entry_t;

typedef enum {
  BTIF_DM_FUNC_CREATE_BOND,
  BTIF_DM_FUNC_CANCEL_BOND,
  BTIF_DM_FUNC_REMOVE_BOND,
  BTIF_DM_FUNC_BOND_STATE_CHANGED,
} bt_bond_function_t;

typedef struct {
  RawAddress bd_addr;
  bt_bond_function_t function;
  bt_bond_state_t state;
  struct timespec timestamp;
} btif_bond_event_t;

typedef struct {
  RawAddress bd_addr;
  alarm_t *sdp_delay_timer;
} btif_dm_bl_device_t;

#define BTIF_STORAGE_GET_REMOTE_PROP(b, t, v, l, p)     \
    do {                                                  \
          (p).type = (t);                                     \
          (p).val = (v);                                      \
          (p).len = (l);                                      \
          btif_storage_get_remote_device_property((b), &(p)); \
        } while (0)

#define UUID_EMPTY "00000000-0000-0000-0000-000000000000"

#define MAX_BTIF_BOND_EVENT_ENTRIES 15

#define ADV_AUDIO_COD_BIT 14
#define BT_PROPERTY_REMOTE_GROUP_DATA 0xFE
#define GROUP_DATA_LEN 6

/* This flag will be true if HCI_Inquiry is in progress */
static bool btif_dm_inquiry_in_progress = false;

bool twsplus_enabled = false;


/*******************************************************************************
 *  Static variables
 ******************************************************************************/
static char btif_default_local_name[DEFAULT_LOCAL_NAME_MAX + 1] = {'\0'};
static uid_set_t* uid_set = NULL;

/* A circular array to keep track of the most recent bond events */
static btif_bond_event_t btif_dm_bond_events[MAX_BTIF_BOND_EVENT_ENTRIES + 1];

static std::mutex bond_event_lock;

static btif_dm_bl_device_t bl_device;

/* |btif_num_bond_events| keeps track of the total number of events and can be
   greater than |MAX_BTIF_BOND_EVENT_ENTRIES| */
static size_t btif_num_bond_events = 0;
static size_t btif_events_start_index = 0;
static size_t btif_events_end_index = 0;

/******************************************************************************
 *  Static functions
 *****************************************************************************/
static btif_dm_pairing_cb_t pairing_cb;
static btif_dm_oob_cb_t oob_cb;
static uint16_t num_active_br_edr_links;
static uint16_t num_active_le_links;
static void btif_dm_generic_evt(uint16_t event, char* p_param);
static void btif_dm_cb_create_bond(const RawAddress& bd_addr,
                                   tBTA_TRANSPORT transport);
static void btif_dm_cb_hid_remote_name(tBTM_REMOTE_DEV_NAME* p_remote_name);
static void btif_update_remote_properties(const RawAddress& bd_addr,
                                          BD_NAME bd_name, DEV_CLASS dev_class,
                                          tBT_DEVICE_TYPE dev_type);
static btif_dm_local_key_cb_t ble_local_key_cb;
static void btif_dm_ble_key_notif_evt(tBTA_DM_SP_KEY_NOTIF* p_ssp_key_notif);
static void btif_dm_ble_auth_cmpl_evt(tBTA_DM_AUTH_CMPL* p_auth_cmpl);
static void btif_dm_ble_passkey_req_evt(tBTA_DM_PIN_REQ* p_pin_req);
static void btif_dm_ble_key_nc_req_evt(tBTA_DM_SP_KEY_NOTIF* p_notif_req);
static void btif_dm_ble_oob_req_evt(tBTA_DM_SP_RMT_OOB* req_oob_type);
static void btif_dm_ble_sc_oob_req_evt(tBTA_DM_SP_RMT_OOB* req_oob_type);

static void bte_scan_filt_param_cfg_evt(uint8_t action_type, uint8_t avbl_space,
                                        uint8_t ref_value, uint8_t status);

static char* btif_get_default_local_name();

static void btif_stats_add_bond_event(const RawAddress& bd_addr,
                                      bt_bond_function_t function,
                                      bt_bond_state_t state);

/******************************************************************************
 *  Externs
 *****************************************************************************/
extern bt_status_t btif_hf_execute_service(bool b_enable);
extern bt_status_t btif_av_execute_service(bool b_enable);
extern bt_status_t btif_av_sink_execute_service(bool b_enable);
extern bt_status_t btif_hh_execute_service(bool b_enable);
extern bt_status_t btif_hf_client_execute_service(bool b_enable);
extern bt_status_t btif_sdp_execute_service(bool b_enable);
extern int btif_hh_connect(const RawAddress* bd_addr);
extern void btif_av_move_idle(RawAddress bd_addr);
extern bt_status_t btif_hd_execute_service(bool b_enable);
extern void btif_av_trigger_suspend();
extern bool btif_av_get_ongoing_multicast();
extern void btif_av_peer_config_dump();
extern bool is_codec_config_dump;
extern void btif_vendor_iot_device_broadcast_event(RawAddress* bd_addr,
                uint16_t error, uint16_t error_info, uint32_t event_mask,
                uint8_t power_level, int8_t rssi, uint8_t link_quality,
                uint16_t glitch_count);
extern bluetooth::hearing_aid::HearingAidInterface*
btif_hearing_aid_get_interface();
#if (BT_IOT_LOGGING_ENABLED == TRUE)
extern void btif_iot_update_remote_info(tBTA_DM_AUTH_CMPL* p_auth_cmpl,
                bool is_ble, bool is_ssp);
#endif

#ifdef ADV_AUDIO_FEATURE
extern bool is_remote_support_adv_audio(const RawAddress remote_bdaddr);
extern void bta_adv_audio_update_bond_db(RawAddress p_bd_addr, uint8_t transport);
extern void btif_store_adv_audio_pair_info(RawAddress bd_addr);
#endif
/******************************************************************************
 *  Functions
 *****************************************************************************/

static bool is_empty_128bit(uint8_t* data) {
  static const uint8_t zero[16] = {0};
  return !memcmp(zero, data, sizeof(zero));
}

static bool is_bonding_or_sdp() {
  return pairing_cb.state == BT_BOND_STATE_BONDING ||
         (pairing_cb.state == BT_BOND_STATE_BONDED && pairing_cb.sdp_attempts);
}

static void btif_dm_data_copy(uint16_t event, char* dst, char* src) {
  tBTA_DM_SEC* dst_dm_sec = (tBTA_DM_SEC*)dst;
  tBTA_DM_SEC* src_dm_sec = (tBTA_DM_SEC*)src;

  if (!src_dm_sec) return;

  CHECK(dst_dm_sec);
  maybe_non_aligned_memcpy(dst_dm_sec, src_dm_sec, sizeof(*src_dm_sec));

  if (event == BTA_DM_BLE_KEY_EVT) {
    dst_dm_sec->ble_key.p_key_value =
        (tBTM_LE_KEY_VALUE*)osi_malloc(sizeof(tBTM_LE_KEY_VALUE));
    CHECK(src_dm_sec->ble_key.p_key_value);
    memcpy(dst_dm_sec->ble_key.p_key_value, src_dm_sec->ble_key.p_key_value,
           sizeof(tBTM_LE_KEY_VALUE));
  }
}

static void btif_dm_data_free(uint16_t event, tBTA_DM_SEC* dm_sec) {
  if (event == BTA_DM_BLE_KEY_EVT)
    osi_free_and_reset((void**)&dm_sec->ble_key.p_key_value);
}

void btif_dm_init(uid_set_t* set) {
  uid_set = set;
  bl_device.sdp_delay_timer = alarm_new("btif_dm.sdp_delay_timer");
}

void btif_dm_cleanup(void) {
  alarm_free(bl_device.sdp_delay_timer);
  if (uid_set) {
    uid_set_destroy(uid_set);
    uid_set = NULL;
  }
}

static void btif_dm_sdp_delay_timer_cback(void* data) {

  BTIF_TRACE_DEBUG("%s: initiating SDP after delay ", __func__);
  // Ensure inquiry is stopped before attempting service discovery
  btif_dm_cancel_discovery();

  /* Trigger SDP on the device */
  btif_dm_get_remote_services_by_transport((RawAddress*)data, BT_TRANSPORT_BR_EDR);
}

void btif_dm_sdp_delay_timer(const RawAddress * bl_bdaddr) {

  bl_device.bd_addr = *bl_bdaddr;

  if (!bl_device.sdp_delay_timer) {
    BTIF_TRACE_ERROR("%s:unable to allocate sdp_delay_timer",__func__);
    return;
  }
  alarm_set(bl_device.sdp_delay_timer, BTIF_DM_SDP_DELAY_TIMER_MS,
            btif_dm_sdp_delay_timer_cback, &bl_device.bd_addr);
  BTIF_TRACE_DEBUG("%s: sdp delay timer started", __func__);
 }

bt_status_t btif_in_execute_service_request(tBTA_SERVICE_ID service_id,
                                            bool b_enable) {
  BTIF_TRACE_DEBUG("%s service_id: %d", __func__, service_id);
  /* Check the service_ID and invoke the profile's BT state changed API */
  switch (service_id) {
    case BTA_HFP_SERVICE_ID:
    case BTA_HSP_SERVICE_ID: {
      bluetooth::headset::btif_hf_execute_service(b_enable);
    } break;
    case BTA_A2DP_SOURCE_SERVICE_ID: {
      btif_av_execute_service(b_enable);
    } break;
    case BTA_A2DP_SINK_SERVICE_ID: {
      btif_av_sink_execute_service(b_enable);
    } break;
    case BTA_HID_SERVICE_ID: {
      btif_hh_execute_service(b_enable);
    } break;
    case BTA_HFP_HS_SERVICE_ID: {
      btif_hf_client_execute_service(b_enable);
    } break;
    case BTA_SDP_SERVICE_ID: {
      btif_sdp_execute_service(b_enable);
    } break;
    case BTA_HIDD_SERVICE_ID: {
      btif_hd_execute_service(b_enable);
    } break;
     case BTA_TWS_PLUS_SERVICE_ID: {
      btif_tws_plus_execute_service(b_enable);
    } break;
    default:
      BTIF_TRACE_ERROR("%s: Unknown service %d being %s", __func__, service_id,
                       (b_enable) ? "enabled" : "disabled");
      return BT_STATUS_FAIL;
  }
  return BT_STATUS_SUCCESS;
}

/*******************************************************************************
**
** Function         check_eir_is_remote_name_short
**
** Description      Check if remote name is shortened
**
** Returns          TRUE if remote name found
**                  else FALSE
**
*******************************************************************************/
static bool check_eir_is_remote_name_short(tBTA_DM_SEARCH *p_search_data) {

  const uint8_t* p_eir_remote_name = NULL;
  uint8_t remote_name_len = 0;

  /* Check EIR for remote name and services */
  if (p_search_data->inq_res.p_eir) {

    p_eir_remote_name = AdvertiseDataParser::GetFieldByType(
          p_search_data->inq_res.p_eir, p_search_data->inq_res.eir_len,
          BTM_EIR_SHORTENED_LOCAL_NAME_TYPE, &remote_name_len);

    if (p_eir_remote_name) {
      return TRUE;
    }
  }
  return FALSE;
}

/*******************************************************************************
**
 * Function         check_eir_remote_name
 *
 * Description      Check if remote name is in the EIR data
 *
 * Returns          true if remote name found
 *                  Populate p_remote_name, if provided and remote name found
 *
 ******************************************************************************/
static bool check_eir_remote_name(tBTA_DM_SEARCH* p_search_data,
                                  uint8_t* p_remote_name,
                                  uint8_t* p_remote_name_len) {
  const uint8_t* p_eir_remote_name = NULL;
  uint8_t remote_name_len = 0;

  /* Check EIR for remote name and services */
  if (p_search_data->inq_res.p_eir) {
    p_eir_remote_name = AdvertiseDataParser::GetFieldByType(
        p_search_data->inq_res.p_eir, p_search_data->inq_res.eir_len,
        BTM_EIR_COMPLETE_LOCAL_NAME_TYPE, &remote_name_len);
    if (!p_eir_remote_name) {
      p_eir_remote_name = AdvertiseDataParser::GetFieldByType(
          p_search_data->inq_res.p_eir, p_search_data->inq_res.eir_len,
          BTM_EIR_SHORTENED_LOCAL_NAME_TYPE, &remote_name_len);
    }

    if (p_eir_remote_name) {
      if (remote_name_len > BD_NAME_LEN) remote_name_len = BD_NAME_LEN;

      if (p_remote_name && p_remote_name_len) {
        memcpy(p_remote_name, p_eir_remote_name, remote_name_len);
        *(p_remote_name + remote_name_len) = 0;
        *p_remote_name_len = remote_name_len;
      }

      return true;
    }
  }

  return false;
}

/*******************************************************************************
 *
 * Function         check_cached_remote_name
 *
 * Description      Check if remote name is in the NVRAM cache
 *
 * Returns          true if remote name found
 *                  Populate p_remote_name, if provided and remote name found
 *
 ******************************************************************************/
static bool check_cached_remote_name(tBTA_DM_SEARCH* p_search_data,
                                     uint8_t* p_remote_name,
                                     uint8_t* p_remote_name_len) {
  bt_bdname_t bdname;
  bt_property_t prop_name;

  /* check if we already have it in our btif_storage cache */

  BTIF_STORAGE_FILL_PROPERTY(&prop_name, BT_PROPERTY_BDNAME,
                             sizeof(bt_bdname_t), &bdname);
  if (btif_storage_get_remote_device_property(
          &p_search_data->inq_res.bd_addr, &prop_name) == BT_STATUS_SUCCESS) {
    if (p_remote_name && p_remote_name_len) {
      strcpy((char*)p_remote_name, (char*)bdname.name);
      *p_remote_name_len = strlen((char*)p_remote_name);
    }
    return true;
  }

  return false;
}

static uint32_t get_cod(const RawAddress* remote_bdaddr) {
  uint32_t remote_cod;
  bt_property_t prop_name;

  /* check if we already have it in our btif_storage cache */
  BTIF_STORAGE_FILL_PROPERTY(&prop_name, BT_PROPERTY_CLASS_OF_DEVICE,
                             sizeof(uint32_t), &remote_cod);
  if (btif_storage_get_remote_device_property(
          (RawAddress*)remote_bdaddr, &prop_name) == BT_STATUS_SUCCESS) {
    LOG_INFO(LOG_TAG, "%s remote_cod = 0x%08x", __func__, remote_cod);
    return remote_cod & COD_MASK;
  }

  return 0;
}

bool check_cod(const RawAddress* remote_bdaddr, uint32_t cod) {
  return get_cod(remote_bdaddr) == cod;
}

bool check_cod_hid(const RawAddress* remote_bdaddr) {
  return (get_cod(remote_bdaddr) & COD_HID_MASK) == COD_HID_MAJOR;
}

bool check_hid_le(const RawAddress* remote_bdaddr) {
  uint32_t remote_dev_type;
  bt_property_t prop_name;

  /* check if we already have it in our btif_storage cache */
  BTIF_STORAGE_FILL_PROPERTY(&prop_name, BT_PROPERTY_TYPE_OF_DEVICE,
                             sizeof(uint32_t), &remote_dev_type);
  if (btif_storage_get_remote_device_property(
          (RawAddress*)remote_bdaddr, &prop_name) == BT_STATUS_SUCCESS) {
    if (remote_dev_type == BT_DEVICE_DEVTYPE_BLE) {
      if (btif_config_exist(remote_bdaddr->ToString().c_str(), "HidAppId"))
        return true;
    }
  }
  return false;
}

/*****************************************************************************
 *
 * Function        interop_skip_sdp
 *
 * Description     Checks if a given device is blacklisted to skip sdp
 *
 * Parameters     remote_bdaddr
 *
 * Returns         true if the device is present in blacklist, else false
 *
 ******************************************************************************/
bool check_sdp_bl(const RawAddress* remote_bdaddr) {
  uint16_t manufacturer = 0;
  uint8_t lmp_ver = 0;
  uint16_t lmp_subver = 0;

  if (remote_bdaddr->IsEmpty()) {
    LOG_WARN(LOG_TAG, "%s: remote_bdaddr = NULL, returning false", __func__);
    return false;
  }

  if (interop_match_addr_or_name(INTEROP_DISABLE_SDP_AFTER_PAIRING, remote_bdaddr)) {
    LOG_WARN(LOG_TAG, "%s: device is in blacklist for skipping sdp", __func__);
    return true;
  }

  bt_property_t prop_name;

  /* fetch additional info about remote device used in iop query */
  BTM_ReadRemoteVersion(*remote_bdaddr, &lmp_ver, &manufacturer, &lmp_subver);

  bt_remote_version_t info;

  /* if not available yet, try fetching from config database */
  BTIF_STORAGE_FILL_PROPERTY(&prop_name, BT_PROPERTY_REMOTE_VERSION_INFO,
                             sizeof(bt_remote_version_t), &info);


 if (btif_storage_get_remote_device_property(remote_bdaddr, &prop_name) !=
        BT_STATUS_SUCCESS) {
    APPL_TRACE_WARNING(
        "%s: BT_PROPERTY_REMOTE_VERSION_INFO failed, returning false",
        __func__);
    return false;
  }
  manufacturer = info.manufacturer;

  return (manufacturer != INVALID_MANUFACTURER &&
          interop_match_manufacturer(INTEROP_DISABLE_SDP_AFTER_PAIRING,
                                     manufacturer));
}

/*****************************************************************************
 *
 * Function        fetch_whitelisted_media_players
 *
 * Description     fetch whitelisted players from interop Database
 *
 * Returns         true if the whitelisted players list is present, else false
 *
 ******************************************************************************/
bool fetch_whitelisted_media_players(list_t** bl_devices) {
  APPL_TRACE_DEBUG("%s",__func__);
  if (interop_get_whitelisted_media_players_list(bl_devices)) {
    APPL_TRACE_WARNING(
        "%s: Found list of Whitelisted media players ",
        __func__);

    return true;
  }
  return false;
}

void bond_state_changed(bt_status_t status, const RawAddress& bd_addr,
                               bt_bond_state_t state) {
  btif_stats_add_bond_event(bd_addr, BTIF_DM_FUNC_BOND_STATE_CHANGED, state);

#ifdef ADV_AUDIO_FEATURE
  if (is_remote_support_adv_audio(bd_addr)) {
    if (state == BT_BOND_STATE_BONDED) {
      btif_store_adv_audio_pair_info(bd_addr);
    }
  }
#endif

  if ((pairing_cb.state == state) && (state == BT_BOND_STATE_BONDING)) {
    // Cross key pairing so send callback for static address
    if (!pairing_cb.static_bdaddr.IsEmpty()) {
      auto tmp = bd_addr;
      HAL_CBACK(bt_hal_cbacks, bond_state_changed_cb, status, &tmp, state);
    }
    return;
  }

  if (pairing_cb.bond_type == BOND_TYPE_TEMPORARY) {
    state = BT_BOND_STATE_NONE;
  }

  BTIF_TRACE_DEBUG("%s: state=%d, prev_state=%d, sdp_attempts = %d", __func__,
                   state, pairing_cb.state, pairing_cb.sdp_attempts);

  auto tmp = bd_addr;
  HAL_CBACK(bt_hal_cbacks, bond_state_changed_cb, status, &tmp, state);

  if (state == BT_BOND_STATE_BONDING ||
      (state == BT_BOND_STATE_BONDED && pairing_cb.sdp_attempts > 0)) {
    // Save state for the device is bonding or SDP.
    pairing_cb.state = state;
    pairing_cb.bd_addr = bd_addr;
  } else {
   if ((pairing_cb.state == BT_BOND_STATE_BONDING)
     && (state == BT_BOND_STATE_NONE)
     && (pairing_cb.bd_addr != bd_addr)) {
     BTIF_TRACE_DEBUG("%s: Another pairing is in progress", __func__);
    } else {
      pairing_cb = {};
    }
  }
  if (state == BT_BOND_STATE_NONE) {
    // Update Pbap 1.2 entry, set rebonded to true
    update_pce_entry_after_cancelling_bonding(bd_addr);
    // Update Map 1.4 entry, set rebonded to true
    update_mce_entry_after_cancelling_bonding(bd_addr);
  }
}

/* store remote version in bt config to always have access
   to it post pairing*/
static void btif_update_remote_version_property(RawAddress* p_bd) {
  bt_property_t property;
  uint8_t lmp_ver = 0;
  uint16_t lmp_subver = 0;
  uint16_t mfct_set = 0;
  tBTM_STATUS btm_status;
  bt_remote_version_t info;
  bt_status_t status;

  btm_status = BTM_ReadRemoteVersion(*p_bd, &lmp_ver, &mfct_set, &lmp_subver);

  LOG_DEBUG(LOG_TAG, "remote version info [%s]: %x, %x, %x",
            p_bd->ToString().c_str(), lmp_ver, mfct_set, lmp_subver);

  if (btm_status == BTM_SUCCESS &&
      (lmp_ver || lmp_subver || mfct_set)) {
    // Always update cache to ensure we have availability whenever BTM API is
    // not populated
    info.manufacturer = mfct_set;
    info.sub_ver = lmp_subver;
    info.version = lmp_ver;
    BTIF_STORAGE_FILL_PROPERTY(&property, BT_PROPERTY_REMOTE_VERSION_INFO,
                               sizeof(bt_remote_version_t), &info);
    status = btif_storage_set_remote_device_property(p_bd, &property);
    ASSERTC(status == BT_STATUS_SUCCESS, "failed to save remote version",
            status);
  }
}

static void btif_update_remote_properties(const RawAddress& bdaddr,
                                          BD_NAME bd_name, DEV_CLASS dev_class,
                                          tBT_DEVICE_TYPE device_type) {
  int num_properties = 0;
  bt_property_t properties[3];
  bt_status_t status;
  uint32_t cod;
  bt_device_type_t dev_type;

  memset(properties, 0, sizeof(properties));

  /* remote name */
  if (strlen((const char*)bd_name)) {
    BTIF_STORAGE_FILL_PROPERTY(&properties[num_properties], BT_PROPERTY_BDNAME,
                               strlen((char*)bd_name), bd_name);
    status = btif_storage_set_remote_device_property(
        &bdaddr, &properties[num_properties]);
    ASSERTC(status == BT_STATUS_SUCCESS, "failed to save remote device name",
            status);
    num_properties++;
  }

  /* class of device */
  cod = devclass2uint(dev_class);
  BTIF_TRACE_DEBUG("%s cod is 0x%06x", __func__, cod);
  if (cod == 0) {
    /* Try to retrieve cod from storage */
    BTIF_TRACE_DEBUG("%s cod is 0, checking cod from storage", __func__);
    BTIF_STORAGE_FILL_PROPERTY(&properties[num_properties],
                               BT_PROPERTY_CLASS_OF_DEVICE, sizeof(cod), &cod);
    status = btif_storage_get_remote_device_property(
        &bdaddr, &properties[num_properties]);
    BTIF_TRACE_DEBUG("%s cod retrieved from storage is 0x%06x", __func__, cod);
    if (cod == 0) {
      BTIF_TRACE_DEBUG("%s cod is again 0, set as unclassified", __func__);
      cod = COD_UNCLASSIFIED;
    }
  }

  BTIF_STORAGE_FILL_PROPERTY(&properties[num_properties],
                             BT_PROPERTY_CLASS_OF_DEVICE, sizeof(cod), &cod);
  status = btif_storage_set_remote_device_property(&bdaddr,
                                                   &properties[num_properties]);
  ASSERTC(status == BT_STATUS_SUCCESS, "failed to save remote device class",
          status);
  num_properties++;

  /* device type */
  bt_property_t prop_name;
  uint8_t remote_dev_type;
  BTIF_STORAGE_FILL_PROPERTY(&prop_name, BT_PROPERTY_TYPE_OF_DEVICE,
                             sizeof(uint8_t), &remote_dev_type);
  if (btif_storage_get_remote_device_property(&bdaddr, &prop_name) ==
      BT_STATUS_SUCCESS)
    dev_type = (bt_device_type_t)(remote_dev_type | device_type);
  else
    dev_type = (bt_device_type_t)device_type;

  BTIF_STORAGE_FILL_PROPERTY(&properties[num_properties],
                             BT_PROPERTY_TYPE_OF_DEVICE, sizeof(dev_type),
                             &dev_type);
  status = btif_storage_set_remote_device_property(&bdaddr,
                                                   &properties[num_properties]);
  ASSERTC(status == BT_STATUS_SUCCESS, "failed to save remote device type",
          status);
  num_properties++;

  auto tmp = bdaddr;
  HAL_CBACK(bt_hal_cbacks, remote_device_properties_cb, status, &tmp,
            num_properties, properties);
}

/*******************************************************************************
 *
 * Function         btif_dm_cb_hid_remote_name
 *
 * Description      Remote name callback for HID device. Called in btif context
 *                  Special handling for HID devices
 *
 * Returns          void
 *
 ******************************************************************************/
static void btif_dm_cb_hid_remote_name(tBTM_REMOTE_DEV_NAME* p_remote_name) {
  BTIF_TRACE_DEBUG("%s: status=%d pairing_cb.state=%d", __func__,
                   p_remote_name->status, pairing_cb.state);
  if (pairing_cb.state == BT_BOND_STATE_BONDING) {
    BTA_DmResetPairingflag(pairing_cb.bd_addr);
    if (p_remote_name->status == BTM_SUCCESS) {
      bond_state_changed(BT_STATUS_SUCCESS, pairing_cb.bd_addr,
                         BT_BOND_STATE_BONDED);
    } else
      bond_state_changed(BT_STATUS_FAIL, pairing_cb.bd_addr,
                         BT_BOND_STATE_NONE);
  }
}

/*******************************************************************************
 *
 * Function         btif_dm_cb_create_bond
 *
 * Description      Create bond initiated from the BTIF thread context
 *                  Special handling for HID devices
 *
 * Returns          void
 *
 ******************************************************************************/
static void btif_dm_cb_create_bond(const RawAddress& bd_addr,
                                   tBTA_TRANSPORT transport) {
  bool is_hid = check_cod(&bd_addr, COD_HID_POINTING);

  if (btm_cb.pairing_state != BTM_PAIR_STATE_IDLE ) {
    BTIF_TRACE_DEBUG("%s: btm_cb.pairing_state = %d, one pairing in progress ",
                      __func__, btm_cb.pairing_state);
    auto tmp = bd_addr;
    HAL_CBACK(bt_hal_cbacks, bond_state_changed_cb, BT_STATUS_FAIL, &tmp, BT_BOND_STATE_NONE);
    return;
  }

  bond_state_changed(BT_STATUS_SUCCESS, bd_addr, BT_BOND_STATE_BONDING);

  int device_type;
  int addr_type;
  std::string addrstr = bd_addr.ToString();
  const char* bdstr = addrstr.c_str();
  if (transport == BT_TRANSPORT_LE) {
    if (!btif_config_get_int(bdstr, "DevType", &device_type)) {
      btif_config_set_int(bdstr, "DevType", BT_DEVICE_TYPE_BLE);
    }
    if (btif_storage_get_remote_addr_type(&bd_addr, &addr_type) !=
        BT_STATUS_SUCCESS) {
      // Try to read address type. OOB pairing might have set it earlier, but
      // didn't store it, it defaults to BLE_ADDR_PUBLIC
      uint8_t tmp_dev_type;
      uint8_t tmp_addr_type;
      BTM_ReadDevInfo(bd_addr, &tmp_dev_type, &tmp_addr_type);
      addr_type = tmp_addr_type;

      btif_storage_set_remote_addr_type(&bd_addr, addr_type);
    }
  }
  if ((btif_config_get_int(bdstr, "DevType", &device_type) &&
       (btif_storage_get_remote_addr_type(&bd_addr, &addr_type) ==
        BT_STATUS_SUCCESS) &&
       (device_type & BT_DEVICE_TYPE_BLE) == BT_DEVICE_TYPE_BLE) ||
      (transport == BT_TRANSPORT_LE)) {
    BTA_DmAddBleDevice(bd_addr, addr_type, device_type);
  }

  if (is_hid && (device_type & BT_DEVICE_TYPE_BLE) == 0) {
    bt_status_t status;
    status = (bt_status_t)btif_hh_connect(&bd_addr);
    if (status != BT_STATUS_SUCCESS)
      bond_state_changed(status, bd_addr, BT_BOND_STATE_NONE);
  } else {
#ifdef ADV_AUDIO_FEATURE
    if (is_remote_support_adv_audio(bd_addr)) {
      transport = btif_dm_get_adv_audio_transport(bd_addr);
      bta_adv_audio_update_bond_db(bd_addr, transport);
      pairing_cb.is_adv_audio = 1;
    }
#endif
    BTIF_TRACE_DEBUG("%s bonding through TRANPORT %d ",
          __func__, transport);
    BTA_DmBondByTransport(bd_addr, transport);
  }
  /*  Track  originator of bond creation  */
  pairing_cb.is_local_initiated = true;
}

/*******************************************************************************
 *
 * Function         btif_dm_cb_remove_bond
 *
 * Description      remove bond initiated from the BTIF thread context
 *                  Special handling for HID devices
 *
 * Returns          void
 *
 ******************************************************************************/
void btif_dm_cb_remove_bond(const RawAddress* bd_addr) {

  bt_bdname_t alias;
  bt_property_t properties[1];
  uint32_t num_properties = 0;
  memset(&alias, 0, sizeof(alias));
  BTIF_DM_GET_REMOTE_PROP(bd_addr, BT_PROPERTY_REMOTE_FRIENDLY_NAME,
          &alias, sizeof(alias), properties[num_properties]);

  if(alias.name[0] != '\0') {
       properties[0].type = BT_PROPERTY_REMOTE_FRIENDLY_NAME;
       properties[0].val = (void *) "";
       properties[0].len = 1;

       btif_storage_set_remote_device_property(bd_addr, &properties[0]);
  }

/*special handling for HID devices */
/*  VUP needs to be sent if its a HID Device. The HID HOST module will check if
there
is a valid hid connection with this bd_addr. If yes VUP will be issued.*/
#if (BTA_HH_INCLUDED == TRUE)
  if (btif_hh_virtual_unplug(bd_addr) != BT_STATUS_SUCCESS)
#endif
  {
    BTIF_TRACE_DEBUG("%s: Removing HH device", __func__);
    BTA_DmRemoveDevice(*bd_addr);
  }
}

/*******************************************************************************
 *
 * Function         btif_dm_get_connection_state
 *
 * Description      Returns whether the remote device is currently connected
 *                  and whether encryption is active for the connection
 *
 * Returns          0 if not connected; 1 if connected and > 1 if connection is
 *                  encrypted
 *
 ******************************************************************************/
uint16_t btif_dm_get_connection_state(const RawAddress* bd_addr) {
  uint16_t rc = BTA_DmGetConnectionState(*bd_addr);

  if (rc != 0) {
    uint8_t flags = 0;

    BTM_GetSecurityFlagsByTransport(*bd_addr, &flags, BT_TRANSPORT_BR_EDR);
    BTIF_TRACE_DEBUG("%s: security flags (BR/EDR)=0x%02x", __func__, flags);
    if (flags & BTM_SEC_FLAG_ENCRYPTED) rc |= ENCRYPTED_BREDR;

    BTM_GetSecurityFlagsByTransport(*bd_addr, &flags, BT_TRANSPORT_LE);
    BTIF_TRACE_DEBUG("%s: security flags (LE)=0x%02x", __func__, flags);
    if (flags & BTM_SEC_FLAG_ENCRYPTED) rc |= ENCRYPTED_LE;
  }

  return rc;
}

/*******************************************************************************
 *
 * Function         search_devices_copy_cb
 *
 * Description      Deep copy callback for search devices event
 *
 * Returns          void
 *
 ******************************************************************************/
static void search_devices_copy_cb(uint16_t event, char* p_dest, char* p_src) {
  tBTA_DM_SEARCH* p_dest_data = (tBTA_DM_SEARCH*)p_dest;
  tBTA_DM_SEARCH* p_src_data = (tBTA_DM_SEARCH*)p_src;

  if (!p_src) return;

  BTIF_TRACE_DEBUG("%s: event=%s", __func__, dump_dm_search_event(event));
  maybe_non_aligned_memcpy(p_dest_data, p_src_data, sizeof(*p_src_data));
  switch (event) {
    case BTA_DM_INQ_RES_EVT: {
      if (p_src_data->inq_res.p_eir) {
        p_dest_data->inq_res.p_eir =
            (uint8_t*)(p_dest + sizeof(tBTA_DM_SEARCH));
        memcpy(p_dest_data->inq_res.p_eir, p_src_data->inq_res.p_eir,
               p_src_data->inq_res.eir_len);
        p_dest_data->inq_res.eir_len = p_src_data->inq_res.eir_len;
      }
    } break;

    case BTA_DM_DISC_RES_EVT: {
      if (p_src_data->disc_res.raw_data_size &&
          p_src_data->disc_res.p_raw_data) {
        p_dest_data->disc_res.p_raw_data =
            (uint8_t*)(p_dest + sizeof(tBTA_DM_SEARCH));
        memcpy(p_dest_data->disc_res.p_raw_data,
               p_src_data->disc_res.p_raw_data,
               p_src_data->disc_res.raw_data_size);
      }
    } break;
  }
}

void search_services_copy_cb(uint16_t event, char* p_dest, char* p_src) {
  tBTA_DM_SEARCH* p_dest_data = (tBTA_DM_SEARCH*)p_dest;
  tBTA_DM_SEARCH* p_src_data = (tBTA_DM_SEARCH*)p_src;

  if (!p_src) return;
  maybe_non_aligned_memcpy(p_dest_data, p_src_data, sizeof(*p_src_data));
  switch (event) {
    case BTA_DM_DISC_RES_EVT: {
      if (p_src_data->disc_res.result == BTA_SUCCESS) {
        if (p_src_data->disc_res.num_uuids > 0) {
          p_dest_data->disc_res.p_uuid_list =
              (Uuid*)(p_dest + sizeof(tBTA_DM_SEARCH));
          memcpy(p_dest_data->disc_res.p_uuid_list,
                 p_src_data->disc_res.p_uuid_list,
                 p_src_data->disc_res.num_uuids * sizeof(Uuid));
          osi_free_and_reset((void**)&p_src_data->disc_res.p_uuid_list);
        }
        osi_free_and_reset((void**)&p_src_data->disc_res.p_raw_data);
      }
    } break;
  }
}
/******************************************************************************
 *
 *  BTIF DM callback events
 *
 ****************************************************************************/

/*******************************************************************************
 *
 * Function         btif_dm_pin_req_evt
 *
 * Description      Executes pin request event in btif context
 *
 * Returns          void
 *
 ******************************************************************************/
static void btif_dm_pin_req_evt(tBTA_DM_PIN_REQ* p_pin_req) {
  bt_bdname_t bd_name;
  uint32_t cod;
  bt_pin_code_t pin_code;
  int dev_type;

  /* Remote properties update */
  if (!btif_get_device_type(p_pin_req->bd_addr, &dev_type)) {
    dev_type = BT_DEVICE_TYPE_BREDR;
  }
  btif_update_remote_properties(p_pin_req->bd_addr, p_pin_req->bd_name,
                                p_pin_req->dev_class,
                                (tBT_DEVICE_TYPE)dev_type);

  const RawAddress& bd_addr = p_pin_req->bd_addr;
  memcpy(bd_name.name, p_pin_req->bd_name, BD_NAME_LEN);
  bd_name.name[BD_NAME_LEN] = '\0';

  if (pairing_cb.state == BT_BOND_STATE_BONDING &&
        !(bd_addr == pairing_cb.bd_addr)) {
      BTIF_TRACE_WARNING("%s(): already in bonding state, reject request", __FUNCTION__);
      btif_dm_pin_reply(&bd_addr, 0, 0, NULL);
      return;
  }
  bond_state_changed(BT_STATUS_SUCCESS, bd_addr, BT_BOND_STATE_BONDING);

  cod = devclass2uint(p_pin_req->dev_class);

  if (cod == 0) {
    BTIF_TRACE_DEBUG("%s cod is 0, set as unclassified", __func__);
    cod = COD_UNCLASSIFIED;
  }

  /* check for auto pair possiblity only if bond was initiated by local device
   */
  if (pairing_cb.is_local_initiated && (p_pin_req->min_16_digit == false)) {
    if (pairing_cb.bd_addr != bd_addr)
      {
        /* Pin code from different device reject it as we dont support more than 1 pairing */
        BTIF_TRACE_DEBUG("%s()rejecting pairing request", __FUNCTION__);
        BTA_DmPinReply(bd_addr, FALSE, 0, NULL);
        return;
      }
    if (check_cod(&bd_addr, COD_AV_HEADSETS) ||
        check_cod(&bd_addr, COD_AV_HEADPHONES) ||
        check_cod(&bd_addr, COD_AV_PORTABLE_AUDIO) ||
        check_cod(&bd_addr, COD_AV_HIFI_AUDIO) ||
        check_cod(&bd_addr, COD_HID_POINTING)) {
      /*  Check if this device can be auto paired  */
      if (!interop_match_addr_or_name(INTEROP_DISABLE_AUTO_PAIRING, &bd_addr)
          && (pairing_cb.autopair_attempts == 0)) {
        BTIF_TRACE_DEBUG("%s() Attempting auto pair", __func__);
        pin_code.pin[0] = 0x30;
        pin_code.pin[1] = 0x30;
        pin_code.pin[2] = 0x30;
        pin_code.pin[3] = 0x30;

        pairing_cb.autopair_attempts++;
        BTA_DmPinReply(bd_addr, true, 4, pin_code.pin);
        return;
      }
    } else if (check_cod(&bd_addr, COD_HID_KEYBOARD) ||
               check_cod(&bd_addr, COD_HID_COMBO)) {
      if ((interop_match_addr_or_name(INTEROP_KEYBOARD_REQUIRES_FIXED_PIN, &bd_addr) ==
           true) &&
          (pairing_cb.autopair_attempts == 0)) {
        BTIF_TRACE_DEBUG("%s() Attempting auto pair", __func__);
        pin_code.pin[0] = 0x30;
        pin_code.pin[1] = 0x30;
        pin_code.pin[2] = 0x30;
        pin_code.pin[3] = 0x30;

        pairing_cb.autopair_attempts++;
        BTA_DmPinReply(bd_addr, true, 4, pin_code.pin);
        return;
      }
    }
  }
  // TODO: make cback accept const and get rid of tmp!
  auto tmp = bd_addr;
  HAL_CBACK(bt_hal_cbacks, pin_request_cb, &tmp, &bd_name, cod,
            p_pin_req->min_16_digit);
}

/*******************************************************************************
 *
 * Function         btif_dm_ssp_cfm_req_evt
 *
 * Description      Executes SSP confirm request event in btif context
 *
 * Returns          void
 *
 ******************************************************************************/
static void btif_dm_ssp_cfm_req_evt(tBTA_DM_SP_CFM_REQ* p_ssp_cfm_req) {
  bt_bdname_t bd_name;
  uint32_t cod;
  bool is_incoming = !(pairing_cb.state == BT_BOND_STATE_BONDING);
  int dev_type;

  BTIF_TRACE_DEBUG("%s", __func__);

  /* Remote properties update */
  if (!btif_get_device_type(p_ssp_cfm_req->bd_addr, &dev_type)) {
    dev_type = BT_DEVICE_TYPE_BREDR;
  }
  btif_update_remote_properties(p_ssp_cfm_req->bd_addr, p_ssp_cfm_req->bd_name,
                                p_ssp_cfm_req->dev_class,
                                (tBT_DEVICE_TYPE)dev_type);

  RawAddress bd_addr = p_ssp_cfm_req->bd_addr;
  memcpy(bd_name.name, p_ssp_cfm_req->bd_name, BD_NAME_LEN);
  bd_name.name[BD_NAME_LEN] = '\0';

  if (pairing_cb.state == BT_BOND_STATE_BONDING &&
        !(bd_addr == pairing_cb.bd_addr)) {
     BTIF_TRACE_WARNING("%s(): already in bonding state, reject request", __FUNCTION__);
     btif_dm_ssp_reply(&bd_addr, BT_SSP_VARIANT_PASSKEY_CONFIRMATION, 0, 0);
     return;
  }
  /* Set the pairing_cb based on the local & remote authentication requirements
   */
  bond_state_changed(BT_STATUS_SUCCESS, bd_addr, BT_BOND_STATE_BONDING);

  BTIF_TRACE_EVENT("%s: just_works :%d, loc_auth_req =%d, rmt_auth_req =%d ",
      __FUNCTION__,p_ssp_cfm_req->just_works,p_ssp_cfm_req->loc_auth_req,
      p_ssp_cfm_req->rmt_auth_req);
  /* if just_works and bonding bit is not set treat this as temporary */
  if (p_ssp_cfm_req->just_works &&
      !(p_ssp_cfm_req->loc_auth_req & BTM_AUTH_BONDS) &&
      !(p_ssp_cfm_req->rmt_auth_req & BTM_AUTH_BONDS) &&
      !(check_cod((RawAddress*)&p_ssp_cfm_req->bd_addr, COD_HID_POINTING)))
    pairing_cb.bond_type = BOND_TYPE_TEMPORARY;
  else
    pairing_cb.bond_type = BOND_TYPE_PERSISTENT;

  btm_set_bond_type_dev(p_ssp_cfm_req->bd_addr, pairing_cb.bond_type);

  pairing_cb.is_ssp = true;

  /* If JustWorks auto-accept */
  if (p_ssp_cfm_req->just_works) {
    /* Pairing consent for JustWorks NOT needed if:
     * 1. Incoming temporary pairing is detected
     */
    if (is_incoming && pairing_cb.bond_type == BOND_TYPE_TEMPORARY) {
      BTIF_TRACE_EVENT(
          "%s: Auto-accept JustWorks pairing for temporary incoming", __func__);
      btif_dm_ssp_reply(&bd_addr, BT_SSP_VARIANT_CONSENT, true, 0);
      return;
    }
  }

  cod = devclass2uint(p_ssp_cfm_req->dev_class);

  if (cod == 0) {
    LOG_DEBUG(LOG_TAG, "%s cod is 0, set as unclassified", __func__);
    cod = COD_UNCLASSIFIED;
  }

  pairing_cb.sdp_attempts = 0;
  HAL_CBACK(bt_hal_cbacks, ssp_request_cb, &bd_addr, &bd_name, cod,
            (p_ssp_cfm_req->just_works ? BT_SSP_VARIANT_CONSENT
                                       : BT_SSP_VARIANT_PASSKEY_CONFIRMATION),
            p_ssp_cfm_req->num_val);
}

static void btif_dm_ssp_key_notif_evt(tBTA_DM_SP_KEY_NOTIF* p_ssp_key_notif) {
  bt_bdname_t bd_name;
  uint32_t cod;
  int dev_type;

  BTIF_TRACE_DEBUG("%s", __func__);

  /* Remote properties update */
  if (!btif_get_device_type(p_ssp_key_notif->bd_addr, &dev_type)) {
    dev_type = BT_DEVICE_TYPE_BREDR;
  }
  btif_update_remote_properties(
      p_ssp_key_notif->bd_addr, p_ssp_key_notif->bd_name,
      p_ssp_key_notif->dev_class, (tBT_DEVICE_TYPE)dev_type);

  RawAddress bd_addr = p_ssp_key_notif->bd_addr;
  memcpy(bd_name.name, p_ssp_key_notif->bd_name, BD_NAME_LEN);
  bd_name.name[BD_NAME_LEN] = '\0';

  bond_state_changed(BT_STATUS_SUCCESS, bd_addr, BT_BOND_STATE_BONDING);
  pairing_cb.is_ssp = true;
  cod = devclass2uint(p_ssp_key_notif->dev_class);

  if (cod == 0) {
    LOG_DEBUG(LOG_TAG, "%s cod is 0, set as unclassified", __func__);
    cod = COD_UNCLASSIFIED;
  }

  HAL_CBACK(bt_hal_cbacks, ssp_request_cb, &bd_addr, &bd_name, cod,
            BT_SSP_VARIANT_PASSKEY_NOTIFICATION, p_ssp_key_notif->passkey);
}
/*******************************************************************************
 *
 * Function         btif_dm_auth_cmpl_evt
 *
 * Description      Executes authentication complete event in btif context
 *
 * Returns          void
 *
 ******************************************************************************/
static void btif_dm_auth_cmpl_evt(tBTA_DM_AUTH_CMPL* p_auth_cmpl) {
  /* Save link key, if not temporary */
  bt_status_t status = BT_STATUS_FAIL;
  bt_bond_state_t state = BT_BOND_STATE_NONE;

  BTIF_TRACE_DEBUG("%s: bond state=%d, success=%d, key_present=%d", __func__,
                   pairing_cb.state, p_auth_cmpl->success,
                   p_auth_cmpl->key_present);

  if (btm_get_bond_type_dev(p_auth_cmpl->bd_addr) == BOND_TYPE_PERSISTENT) {
    BTIF_TRACE_DEBUG("%s: setting bond type for persistance pairing",
                     __func__);
    pairing_cb.bond_type = BOND_TYPE_PERSISTENT;
  }

  RawAddress bd_addr = p_auth_cmpl->bd_addr;
  if ((p_auth_cmpl->success == true) && (p_auth_cmpl->key_present)) {
    if ((p_auth_cmpl->key_type < HCI_LKEY_TYPE_DEBUG_COMB) ||
        (p_auth_cmpl->key_type == HCI_LKEY_TYPE_AUTH_COMB) ||
        (p_auth_cmpl->key_type == HCI_LKEY_TYPE_CHANGED_COMB) ||
        (p_auth_cmpl->key_type == HCI_LKEY_TYPE_AUTH_COMB_P_256) ||
        pairing_cb.bond_type == BOND_TYPE_PERSISTENT) {
      bt_status_t ret;
      bool status;
      BTIF_TRACE_DEBUG("%s: Storing link key. key_type=0x%x, bond_type=%d",
                       __func__, p_auth_cmpl->key_type, pairing_cb.bond_type);
      if(btif_is_tws_plus_device(&bd_addr)) {
        status = btif_tws_plus_set_dev_type(&bd_addr, TWS_PLUS_DEV_TYPE_PRIMARY);
        ASSERTC(status == TRUE, "Adding TWS_PLUS dev type failed", status);
      }

      ret = btif_storage_add_bonded_device(&bd_addr, p_auth_cmpl->key,
                                           p_auth_cmpl->key_type,
                                           pairing_cb.pin_code_len);
      ASSERTC(ret == BT_STATUS_SUCCESS, "storing link key failed", ret);
    } else {
      BTIF_TRACE_DEBUG(
          "%s: Temporary key. Not storing. key_type=0x%x, bond_type=%d",
          __func__, p_auth_cmpl->key_type, pairing_cb.bond_type);
      if (pairing_cb.bond_type == BOND_TYPE_TEMPORARY) {
        BTIF_TRACE_DEBUG("%s: sending BT_BOND_STATE_NONE for Temp pairing",
                         __func__);
        btif_storage_remove_bonded_device(&bd_addr);
        BTA_DmResetPairingflag(bd_addr);
        bond_state_changed(BT_STATUS_SUCCESS, bd_addr, BT_BOND_STATE_NONE);
        return;
      }
    }
  }

  // Skip SDP for certain  HID Devices
  if (p_auth_cmpl->success) {
#if (BT_IOT_LOGGING_ENABLED == TRUE)
    //save remote info to iot conf file
    btif_iot_update_remote_info(p_auth_cmpl, false, pairing_cb.is_ssp);
#endif

    // We could have received a new link key without going through the pairing
    // flow.  If so, we don't want to perform SDP or any other operations on the
    // authenticated device. Also, make sure that the link key is not derived from
    // secure LTK, because we will need to perform SDP in case of link key
    // derivation to allow bond state change notification for the BR/EDR transport
    // so that the subsequent BR/EDR connections to the remote can use the derived
    // link key.

    if ((p_auth_cmpl->bd_addr != pairing_cb.bd_addr) &&
        (!pairing_cb.ble.is_penc_key_rcvd)) {
      LOG_INFO(LOG_TAG,
               "%s skipping SDP since we did not initiate pairing to %s.",
               __func__, p_auth_cmpl->bd_addr.ToString().c_str());
      return;
    }

    btif_storage_set_remote_addr_type(&bd_addr, p_auth_cmpl->addr_type);
    btif_update_remote_properties(p_auth_cmpl->bd_addr, p_auth_cmpl->bd_name,
                                  NULL, p_auth_cmpl->dev_type);
    pairing_cb.timeout_retries = 0;

    if (check_cod_hid(&bd_addr)) {
      BTIF_TRACE_DEBUG("%s: btif_dm_sdp_delay_timer started",__func__);
      btif_dm_sdp_delay_timer(&bd_addr);
      pairing_cb.sdp_attempts = 1;
      bond_state_changed(BT_STATUS_SUCCESS, bd_addr, BT_BOND_STATE_BONDED);
    } else {
      status = BT_STATUS_SUCCESS;
      state = BT_BOND_STATE_BONDED;

      bool is_crosskey = false;
      /* If bonded due to cross-key, save the static address too*/
      if (pairing_cb.state == BT_BOND_STATE_BONDING &&
          p_auth_cmpl->bd_addr != pairing_cb.bd_addr) {
        BTIF_TRACE_DEBUG(
            "%s: bonding initiated due to cross key, adding static address",
            __func__);
        pairing_cb.static_bdaddr = bd_addr;
        is_crosskey = true;
      }
      if (!is_crosskey ||
          !(stack_config_get_interface()->get_pts_crosskey_sdp_disable())) {
        // Ensure inquiry is stopped before attempting service discovery
        btif_dm_cancel_discovery();

        /* Trigger SDP on the device */
        pairing_cb.sdp_attempts = 1;

        btif_dm_get_remote_services_by_transport(&bd_addr, BT_TRANSPORT_BR_EDR);


        if (is_crosskey) {
          // If bonding occurred due to cross-key pairing, send bonding callback
          // for static address now
          LOG_INFO(LOG_TAG,
                   "%s: send bonding state update for static address %s",
                   __func__, bd_addr.ToString().c_str());
          bond_state_changed(BT_STATUS_SUCCESS, bd_addr, BT_BOND_STATE_BONDING);
        }
        bond_state_changed(BT_STATUS_SUCCESS, bd_addr, BT_BOND_STATE_BONDED);

      }
    }
    // Do not call bond_state_changed_cb yet. Wait until remote service
    // discovery is complete
  } else {
    // Map the HCI fail reason  to  bt status
    switch (p_auth_cmpl->fail_reason) {
      case HCI_ERR_PAGE_TIMEOUT:
      case HCI_ERR_LMP_RESPONSE_TIMEOUT:
        if (pairing_cb.timeout_retries) {
          BTIF_TRACE_WARNING("%s() - Pairing timeout; retrying (%d) ...",
                             __func__, pairing_cb.timeout_retries);
          --pairing_cb.timeout_retries;
          btif_dm_cb_create_bond(bd_addr, BTA_TRANSPORT_UNKNOWN);
          return;
        }
        FALLTHROUGH;
      case HCI_ERR_CONNECTION_TOUT:
        status = BT_STATUS_RMT_DEV_DOWN;
        break;

      case HCI_ERR_PAIRING_NOT_ALLOWED:
        status = BT_STATUS_AUTH_REJECTED;
        break;

      /* Dont fail the bonding for key missing error as stack retry security */
      case HCI_ERR_KEY_MISSING:
        if (p_auth_cmpl->is_sm4_dev) {
          return;
        } else {
          BTIF_TRACE_WARNING("%s() legacy remote ,move bond state to none", __FUNCTION__);
        }

      /* map the auth failure codes, so we can retry pairing if necessary */
        FALLTHROUGH;
      case HCI_ERR_AUTH_FAILURE:
        FALLTHROUGH;
      case HCI_ERR_HOST_REJECT_SECURITY:
        FALLTHROUGH;
      case HCI_ERR_ENCRY_MODE_NOT_ACCEPTABLE:
        FALLTHROUGH;
      case HCI_ERR_UNIT_KEY_USED:
        FALLTHROUGH;
      case HCI_ERR_PAIRING_WITH_UNIT_KEY_NOT_SUPPORTED:
        FALLTHROUGH;
      case HCI_ERR_INSUFFCIENT_SECURITY:
        FALLTHROUGH;
      case HCI_ERR_PEER_USER:
        FALLTHROUGH;
      case HCI_ERR_UNSPECIFIED:
        FALLTHROUGH;
      case HCI_ERR_REPEATED_ATTEMPTS:
        BTIF_TRACE_DEBUG(" %s() Authentication fail reason %d",
                __FUNCTION__, p_auth_cmpl->fail_reason);
        if (pairing_cb.autopair_attempts  == 1) {
          /* Create the Bond once again */
          BTIF_TRACE_WARNING("%s() auto pair failed. Reinitiate Bond",
                             __func__);
          btif_dm_cb_create_bond(bd_addr, BTA_TRANSPORT_UNKNOWN);
          return;
        } else {

          /* if autopair attempts are more than 1, or not attempted */
          status =  BT_STATUS_AUTH_FAILURE;
        }
        break;

      default:
        status = BT_STATUS_FAIL;
        break;
    }
    /* Special Handling for HID Devices */
    if (check_cod(&bd_addr, COD_HID_POINTING)) {
      /* Remove Device as bonded in nvram as authentication failed */
      BTIF_TRACE_DEBUG("%s(): removing hid pointing device from nvram",
                       __func__);
    }
    BTA_DmResetPairingflag(bd_addr);

    if (btif_is_tws_plus_device(&bd_addr)) {
      RawAddress peer_eb_addr;
      if (btif_tws_plus_get_peer_eb_addr(&bd_addr, &peer_eb_addr)) {
        btif_storage_remove_bonded_device(&peer_eb_addr);
        BTA_DmRemoveDevice(peer_eb_addr);
        bond_state_changed(status, peer_eb_addr, state);
      }
    }
    bond_state_changed(status, bd_addr, state);
  }
}

/******************************************************************************
 *
 * Function         btif_dm_search_devices_evt
 *
 * Description      Executes search devices callback events in btif context
 *
 * Returns          void
 *
 *****************************************************************************/
static void btif_dm_search_devices_evt(uint16_t event, char* p_param) {
  tBTA_DM_SEARCH* p_search_data;
  BTIF_TRACE_EVENT("%s event=%s", __func__, dump_dm_search_event(event));

  switch (event) {
    case BTA_DM_DISC_RES_EVT: {
      p_search_data = (tBTA_DM_SEARCH*)p_param;
      /* Remote name update */
      if (strlen((const char*)p_search_data->disc_res.bd_name)) {
        bt_property_t properties[1];
        bt_status_t status;

        properties[0].type = BT_PROPERTY_BDNAME;
        properties[0].val = p_search_data->disc_res.bd_name;
        properties[0].len = strlen((char*)p_search_data->disc_res.bd_name);
        RawAddress& bdaddr = p_search_data->disc_res.bd_addr;

        status =
            btif_storage_set_remote_device_property(&bdaddr, &properties[0]);
        ASSERTC(status == BT_STATUS_SUCCESS,
                "failed to save remote device property", status);
        HAL_CBACK(bt_hal_cbacks, remote_device_properties_cb, status, &bdaddr,
                  1, properties);
      }
      /* TODO: Services? */
    } break;

    case BTA_DM_INQ_RES_EVT: {
      /* inquiry result */
      bt_bdname_t bdname;
      uint8_t remote_name_len;
      tBTA_SERVICE_MASK services = 0;
      uint8_t gid_data[GROUP_DATA_LEN] = {};
      bool is_grpid_data_found = false;

      p_search_data = (tBTA_DM_SEARCH*)p_param;
      RawAddress bdaddr = p_search_data->inq_res.bd_addr;
      RawAddress peer_eb_bdaddr = RawAddress::kEmpty;
      BTIF_TRACE_DEBUG("%s() %s device_type = 0x%x\n", __func__,
                       bdaddr.ToString().c_str(),
                       p_search_data->inq_res.device_type);
      bdname.name[0] = 0;

      if (!check_eir_remote_name(p_search_data, bdname.name, &remote_name_len))
        check_cached_remote_name(p_search_data, bdname.name, &remote_name_len);

      /* Check EIR for remote name and services */
      if (p_search_data->inq_res.p_eir) {
        BTA_GetEirService(p_search_data->inq_res.p_eir,
                          p_search_data->inq_res.eir_len, &services);
        BTIF_TRACE_DEBUG("%s()EIR BTA services = %10X", __func__,
                         (uint32_t)services);
        /* TODO:  Get the service list and check to see which uuids we got and
         * send it back to the client. */
#ifdef ADV_AUDIO_FEATURE
        BTA_GetGroupData(p_search_data->inq_res.p_eir, p_search_data->inq_res.eir_len,
                         gid_data, &is_grpid_data_found);
#endif
      }

      {
        bt_property_t properties[6];
        bt_device_type_t dev_type;
        uint32_t num_properties = 0;
        bt_status_t status;
        int addr_type = 0;
        bt_bdname_t alias;
        memset(&alias, 0, sizeof(alias));
        BTIF_DM_GET_REMOTE_PROP(&bdaddr, BT_PROPERTY_REMOTE_FRIENDLY_NAME,
                      &alias, sizeof(alias), properties[num_properties]);

        memset(properties, 0, sizeof(properties));
        /* RawAddress */
        BTIF_STORAGE_FILL_PROPERTY(&properties[num_properties],
                                   BT_PROPERTY_BDADDR, sizeof(bdaddr), &bdaddr);
        num_properties++;
        /* BD_NAME */
        /* Don't send BDNAME if it is empty */
        /* send alias name as the name if alias name present */
        if (alias.name[0] != '\0') {
          BTIF_STORAGE_FILL_PROPERTY(&properties[num_properties],
                                       BT_PROPERTY_BDNAME,
                                       strlen((char *)alias.name), &alias);
          num_properties++;
        } else if (bdname.name[0]) {
          if((check_eir_is_remote_name_short(p_search_data) == TRUE) &&
               (btif_storage_is_device_bonded(&bdaddr) == BT_STATUS_SUCCESS)) {
            BTIF_TRACE_DEBUG("%s Don't update about the device name ", __FUNCTION__);
          } else {
            BTIF_STORAGE_FILL_PROPERTY(&properties[num_properties],
                                          BT_PROPERTY_BDNAME,
                                       strlen((char *)bdname.name), &bdname);
            num_properties++;
          }
        }

        /* DEV_CLASS */
        uint32_t cod = devclass2uint(p_search_data->inq_res.dev_class);

        if (controller_get_interface()->is_adv_audio_supported() == 0) {
          cod &= ~((uint32_t)1 << ADV_AUDIO_COD_BIT);
          tBTM_INQ_INFO* p_inq_info;
          p_inq_info = BTM_InqDbRead(bdaddr);
          if (p_inq_info) {
            uint2devclass(cod, p_inq_info->results.dev_class);
          }
        }

        BTIF_TRACE_DEBUG("%s cod is 0x%06x", __func__, cod);
#ifdef ADV_AUDIO_FEATURE
        if (check_adv_audio_cod(cod)) {
          BTIF_TRACE_DEBUG("%s Add to ADV Audio Database %s", __func__,
              bdaddr.ToString().c_str());
          adv_audio_device_db[bdaddr] = cod;
        }
#endif
        if (cod != 0) {
          BTIF_STORAGE_FILL_PROPERTY(&properties[num_properties],
                                     BT_PROPERTY_CLASS_OF_DEVICE, sizeof(cod),
                                     &cod);
          num_properties++;
        }

        /* DEV_TYPE */
        /* FixMe: Assumption is that bluetooth.h and BTE enums match */

        /* Verify if the device is dual mode in NVRAM */
        int stored_device_type = 0;
        if (btif_get_device_type(bdaddr, &stored_device_type) &&
            ((stored_device_type != BT_DEVICE_TYPE_BREDR &&
              p_search_data->inq_res.device_type == BT_DEVICE_TYPE_BREDR) ||
             (stored_device_type != BT_DEVICE_TYPE_BLE &&
              p_search_data->inq_res.device_type == BT_DEVICE_TYPE_BLE))) {
          dev_type = (bt_device_type_t)BT_DEVICE_TYPE_DUMO;
        } else {
          dev_type = (bt_device_type_t)p_search_data->inq_res.device_type;
        }

        if (p_search_data->inq_res.device_type == BT_DEVICE_TYPE_BLE)
          addr_type = p_search_data->inq_res.ble_addr_type;
        BTIF_STORAGE_FILL_PROPERTY(&properties[num_properties],
                                   BT_PROPERTY_TYPE_OF_DEVICE, sizeof(dev_type),
                                   &dev_type);
        num_properties++;
        /* RSSI */
        BTIF_STORAGE_FILL_PROPERTY(&properties[num_properties],
                                   BT_PROPERTY_REMOTE_RSSI, sizeof(int8_t),
                                   &(p_search_data->inq_res.rssi));
        num_properties++;
        /*Group Identifier Data*/
        if (is_grpid_data_found) {
          BTIF_STORAGE_FILL_PROPERTY(&properties[num_properties],
                                     (bt_property_type_t)BT_PROPERTY_REMOTE_GROUP_DATA,
                                     sizeof(gid_data), &gid_data);
          num_properties++;
        }

        status =
            btif_storage_add_remote_device(&bdaddr, num_properties, properties);
        ASSERTC(status == BT_STATUS_SUCCESS,
                "failed to save remote device (inquiry)", status);
        status = btif_storage_set_remote_addr_type(&bdaddr, addr_type);
        ASSERTC(status == BT_STATUS_SUCCESS,
                "failed to save remote addr type (inquiry)", status);
        /* Callback to notify upper layer of device */
        HAL_CBACK(bt_hal_cbacks, device_found_cb, num_properties, properties);

        if(twsplus_enabled == true) {
          if( btif_tws_plus_process_eir( p_search_data, &peer_eb_bdaddr)) {
            BTIF_TRACE_DEBUG("%s() %s \n", __func__,
                     peer_eb_bdaddr.ToString().c_str());

            btif_tws_plus_set_peer_eb_addr(&bdaddr, &peer_eb_bdaddr);
          }
        }
      }
    } break;

    case BTA_DM_INQ_CMPL_EVT: {
      do_in_bta_thread(
          FROM_HERE,
          base::Bind(&BTM_BleAdvFilterParamSetup, BTM_BLE_SCAN_COND_DELETE, 0,
                     nullptr, base::Bind(&bte_scan_filt_param_cfg_evt, 0)));
    } break;
    case BTA_DM_DISC_CMPL_EVT: {
      HAL_CBACK(bt_hal_cbacks, discovery_state_changed_cb,
                BT_DISCOVERY_STOPPED);
    } break;
    case BTA_DM_SEARCH_CANCEL_CMPL_EVT: {
      /* if inquiry is not in progress and we get a cancel event, then
       * it means we are done with inquiry, but remote_name fetches are in
       * progress
       *
       * if inquiry  is in progress, then we don't want to act on this
       * cancel_cmpl_evt
       * but instead wait for the cancel_cmpl_evt via the Busy Level
       *
       */
      if (btif_dm_inquiry_in_progress == false) {
        char donglemode_prop[PROPERTY_VALUE_MAX] = "false";
        if(osi_property_get("persist.bluetooth.donglemode", donglemode_prop, "false") &&
            !strcmp(donglemode_prop, "false")) {
          btgatt_filt_param_setup_t adv_filt_param;
          memset(&adv_filt_param, 0, sizeof(btgatt_filt_param_setup_t));
          do_in_bta_thread(
              FROM_HERE,
              base::Bind(&BTM_BleAdvFilterParamSetup, BTM_BLE_SCAN_COND_DELETE, 0,
                         nullptr, base::Bind(&bte_scan_filt_param_cfg_evt, 0)));
        }
        HAL_CBACK(bt_hal_cbacks, discovery_state_changed_cb,
                  BT_DISCOVERY_STOPPED);
      }
    } break;
  }
}



/*******************************************************************************
 *
 * Function         btif_dm_search_services_evt
 *
 * Description      Executes search services event in btif context
 *
 * Returns          void
 *
 ******************************************************************************/
static void btif_dm_search_services_evt(uint16_t event, char* p_param) {
  tBTA_DM_SEARCH* p_data = (tBTA_DM_SEARCH*)p_param;

  BTIF_TRACE_EVENT("%s:  event = %d", __func__, event);
  switch (event) {
    case BTA_DM_DISC_RES_EVT: {
      uint32_t i = 0, j = 0;
      bt_property_t prop[2];
      int num_properties = 0;
      bt_status_t ret;
      bool is_tws_plus_device = false;
      Uuid remote_uuids[BT_MAX_NUM_UUIDS];
      Uuid missed_remote_uuids[BT_MAX_NUM_UUIDS];
      uint8_t missing_uuids_len = 0;
      bt_property_t remote_uuid_prop;

      RawAddress& bd_addr = p_data->disc_res.bd_addr;

      BTIF_TRACE_DEBUG("%s:(result=0x%x, services 0x%x)", __func__,
                       p_data->disc_res.result, p_data->disc_res.services);

      /* retry sdp service search, if sdp fails for pairing bd address,
      ** report sdp results to APP immediately for non pairing addresses
      */
      if ((p_data->disc_res.result != BTA_SUCCESS) &&
          (pairing_cb.state == BT_BOND_STATE_BONDED) &&
          ((p_data->disc_res.bd_addr == pairing_cb.bd_addr) ||
          (p_data->disc_res.bd_addr == pairing_cb.static_bdaddr.address)) &&
          (pairing_cb.sdp_attempts > 0)) {
        if (pairing_cb.sdp_attempts < BTIF_DM_MAX_SDP_ATTEMPTS_AFTER_PAIRING) {
          BTIF_TRACE_WARNING("%s:SDP failed after bonding re-attempting",

                           __func__);
          pairing_cb.sdp_attempts++;
          btif_dm_get_remote_services_by_transport(&bd_addr, BT_TRANSPORT_BR_EDR);
          return;
        } else {
          BTIF_TRACE_WARNING(
            "%s: SDP reached to maximum attempts, sending bond fail to upper layers",
            __func__);
          /* When SDP failed, deleting bonded device from the database and sending
          * disconnect before moving bond state to BOND NONE.
          */
          BTIF_TRACE_WARNING("%s: deleting bonded device from database", __func__);
          btif_storage_remove_bonded_device(&bd_addr);
          BTA_DmRemoveDevice(bd_addr);
          pairing_cb.sdp_attempts = 0;
          bond_state_changed(BT_STATUS_FAIL, pairing_cb.bd_addr, BT_BOND_STATE_NONE);
          return;
        }
      }
      prop[0].type = BT_PROPERTY_UUIDS;
      prop[0].len = 0;
      if ((p_data->disc_res.result == BTA_SUCCESS) &&
          (p_data->disc_res.num_uuids > 0)) {
        prop[0].val = p_data->disc_res.p_uuid_list;
        prop[0].len = p_data->disc_res.num_uuids * Uuid::kNumBytes128;

        for (i = 0; i < p_data->disc_res.num_uuids; i++) {
          std::string temp = ((p_data->disc_res.p_uuid_list + i))->ToString();
          LOG_INFO(LOG_TAG, "%s index:%d uuid:%s", __func__, i, temp.c_str());
        }
      }

      /* onUuidChanged requires getBondedDevices to be populated.
      ** bond_state_changed needs to be sent prior to remote_device_property
      */
      if ((pairing_cb.state == BT_BOND_STATE_BONDED && pairing_cb.sdp_attempts) &&
          (p_data->disc_res.bd_addr == pairing_cb.bd_addr ||
           p_data->disc_res.bd_addr == pairing_cb.static_bdaddr)) {
        LOG_INFO(LOG_TAG, "%s: SDP search done for %s", __func__,
                 bd_addr.ToString().c_str());
        pairing_cb.sdp_attempts = 0;
        BTA_DmResetPairingflag(bd_addr);

        if((is_tws_plus_device = btif_is_tws_plus_device(&bd_addr))) {
            if(twsplus_enabled == true) {
               btif_tws_plus_get_services(&bd_addr);
            } else {
               RawAddress peer_eb_addr;
               if(btif_tws_plus_get_peer_eb_addr(&bd_addr, &peer_eb_addr)) {
                 btif_config_remove(peer_eb_addr.ToString().c_str(),
                     BTIF_STORAGE_PATH_TWS_PLUS_PEER_ADDR);
               }
               btif_config_remove(bd_addr.ToString().c_str(),
                     BTIF_STORAGE_PATH_TWS_PLUS_PEER_ADDR);
               bond_state_changed(BT_STATUS_SUCCESS, bd_addr, BT_BOND_STATE_BONDED);
            }
        }

        // Both SDP and bonding are done, clear pairing control block

        pairing_cb = {};

        // Send one empty UUID to Java to unblock pairing intent when SDP failed
        // or no UUID is discovered
        if (p_data->disc_res.result != BTA_SUCCESS ||
            p_data->disc_res.num_uuids == 0) {
          LOG_INFO(LOG_TAG,
                   "%s: SDP failed, send empty UUID to unblock bonding %s",
                   __func__, bd_addr.ToString().c_str());
          bt_property_t prop_uuids;

          Uuid uuid = {};
          prop_uuids.type = BT_PROPERTY_UUIDS;
          prop_uuids.val = &uuid;
          prop_uuids.len = Uuid::kNumBytes128;

          /* Send the event to the BTIF */
          HAL_CBACK(bt_hal_cbacks, remote_device_properties_cb,
                    BT_STATUS_SUCCESS, &bd_addr, 1, &prop_uuids);
          break;
        }
      }

      // updates extra uuids which are discovered during
      // new sdp search to existing uuid list present in conf file.
      // If conf file has more UUIDs than the sdp search, it will
      // update the conf file UUIDs as the final UUIDs
      BTIF_STORAGE_FILL_PROPERTY(&remote_uuid_prop, BT_PROPERTY_UUIDS,
                                 sizeof(remote_uuids), remote_uuids);
      btif_storage_get_remote_device_property(&bd_addr,
                                        &remote_uuid_prop);
      if(remote_uuid_prop.len && p_data->disc_res.result == BTA_SUCCESS) {
        // compare now
        bool uuid_found = false;
        uint8_t uuid_len = remote_uuid_prop.len / sizeof(Uuid);
        for (i = 0; i < p_data->disc_res.num_uuids; i++) {
          uuid_found = false;
          Uuid* disc_uuid =  reinterpret_cast<Uuid*> (p_data->disc_res.p_uuid_list + i);
          for (j = 0; j < uuid_len; j++) {
            Uuid* base_uuid =  reinterpret_cast<Uuid*> (remote_uuid_prop.val) + j;
            if(*disc_uuid == *base_uuid) {
              uuid_found = true;
              break;
            }
          }
          if(!uuid_found) {
            BTIF_TRACE_WARNING("%s:new uuid found ", __func__);
            memcpy(&missed_remote_uuids[missing_uuids_len++], disc_uuid, sizeof(Uuid));
          }
        }

        // add the missing uuids now
        if(missing_uuids_len) {
          BTIF_TRACE_WARNING("%s :missing_uuids_len = %d ", __func__, missing_uuids_len);
          for (j = 0; j < missing_uuids_len &&
             (unsigned long)remote_uuid_prop.len < BT_MAX_NUM_UUIDS * sizeof(Uuid); j++) {
            memcpy(&remote_uuids[uuid_len + j], &missed_remote_uuids[j], sizeof(Uuid));
            remote_uuid_prop.len += sizeof(Uuid);
          }
        }
        prop[0].type = BT_PROPERTY_UUIDS;
        prop[0].val = remote_uuids;
        prop[0].len = remote_uuid_prop.len;
        ret = btif_storage_set_remote_device_property(&bd_addr, &prop[0]);
        ASSERTC(ret == BT_STATUS_SUCCESS, "storing remote services failed",
                ret);
        prop[0].type = BT_PROPERTY_UUIDS;
        num_properties++;

      } else if (p_data->disc_res.num_uuids != 0) {
        /* Also write this to the NVRAM */
        ret = btif_storage_set_remote_device_property(&bd_addr, &prop[0]);
        ASSERTC(ret == BT_STATUS_SUCCESS, "storing remote services failed",
                ret);
        num_properties++;
      }

      /* Remote name update */
      if (strlen((const char *) p_data->disc_res.bd_name)) {
        prop[1].type = BT_PROPERTY_BDNAME;
        prop[1].val = p_data->disc_res.bd_name;
        prop[1].len = strlen((char *)p_data->disc_res.bd_name);

        ret = btif_storage_set_remote_device_property(&bd_addr, &prop[1]);
        ASSERTC(ret == BT_STATUS_SUCCESS, "failed to save remote device property", ret);
        num_properties++;
      }

      if(!is_tws_plus_device && num_properties > 0) {
          prop[0].type = BT_PROPERTY_UUIDS;
        /* Send the event to the BTIF */
        HAL_CBACK(bt_hal_cbacks, remote_device_properties_cb, BT_STATUS_SUCCESS,
                  &bd_addr, num_properties, prop);
      }
    } break;

    case BTA_DM_DISC_CMPL_EVT:
      /* fixme */
      break;

    case BTA_DM_SEARCH_CANCEL_CMPL_EVT:
      BTIF_TRACE_DEBUG("%s: discovery is stopped", __func__);
      HAL_CBACK(bt_hal_cbacks, discovery_state_changed_cb,
                BT_DISCOVERY_STOPPED);
      break;

    case BTA_DM_DISC_BLE_RES_EVT: {
      BTIF_TRACE_DEBUG("%s: service %s", __func__,
                       p_data->disc_ble_res.service.ToString().c_str());
      int num_properties = 0;
        if (p_data->disc_ble_res.service.As16Bit() == UUID_SERVCLASS_LE_HID ||
          p_data->disc_ble_res.service == UUID_HEARING_AID) {
          BTIF_TRACE_DEBUG("%s: Found HOGP or HEARING AID UUID", __func__);
          bt_property_t prop[2];
          bt_status_t ret;

          const auto& arr = p_data->disc_ble_res.service.To128BitBE();

          RawAddress& bd_addr = p_data->disc_ble_res.bd_addr;
          prop[0].type = BT_PROPERTY_UUIDS;
          prop[0].val = (void*)arr.data();
          prop[0].len = Uuid::kNumBytes128;

          /* Also write this to the NVRAM */
          ret = btif_storage_set_remote_device_property(&bd_addr, &prop[0]);
          ASSERTC(ret == BT_STATUS_SUCCESS, "storing remote services failed",
                  ret);
          num_properties++;

          /* Remote name update */
          if (strnlen((const char*)p_data->disc_ble_res.bd_name, BD_NAME_LEN)) {
            prop[1].type = BT_PROPERTY_BDNAME;
            prop[1].val = p_data->disc_ble_res.bd_name;
            prop[1].len =
                strnlen((char*)p_data->disc_ble_res.bd_name, BD_NAME_LEN);

            ret = btif_storage_set_remote_device_property(&bd_addr, &prop[1]);
            ASSERTC(ret == BT_STATUS_SUCCESS,
                    "failed to save remote device property", ret);
            num_properties++;
          }

          /* Send the event to the BTIF */
          HAL_CBACK(bt_hal_cbacks, remote_device_properties_cb, BT_STATUS_SUCCESS,
                    &bd_addr, num_properties, prop);
        }
    } break;
    default: { ASSERTC(0, "unhandled search services event", event); } break;
  }
}

/*******************************************************************************
 *
 * Function         btif_dm_remote_service_record_evt
 *
 * Description      Executes search service record event in btif context
 *
 * Returns          void
 *
 ******************************************************************************/
static void btif_dm_remote_service_record_evt(uint16_t event, char* p_param) {
  tBTA_DM_SEARCH* p_data = (tBTA_DM_SEARCH*)p_param;

  BTIF_TRACE_EVENT("%s:  event = %d", __func__, event);
  switch (event) {
    case BTA_DM_DISC_RES_EVT: {
      bt_service_record_t rec;
      bt_property_t prop;

      memset(&rec, 0, sizeof(bt_service_record_t));
      RawAddress& bd_addr = p_data->disc_res.bd_addr;

      BTIF_TRACE_DEBUG("%s:(result=0x%x, services 0x%x)", __func__,
                       p_data->disc_res.result, p_data->disc_res.services);
      prop.type = BT_PROPERTY_SERVICE_RECORD;
      prop.val = (void*)&rec;
      prop.len = sizeof(rec);

      if (p_data->disc_res.services & BTA_USER_SERVICE_MASK) {
        /* disc_res.result is overloaded with SCN. Cannot check result */
        p_data->disc_res.services &= ~BTA_USER_SERVICE_MASK;
        /* TODO: Get the UUID as well */
        rec.channel = p_data->disc_res.result - 3;
      }
      /* TODO: Need to get the service name using p_raw_data */
      rec.name[0] = 0;

      HAL_CBACK(bt_hal_cbacks, remote_device_properties_cb, BT_STATUS_SUCCESS,
                &bd_addr, 1, &prop);
    } break;

    default: {
      ASSERTC(0, "unhandled remote service record event", event);
    } break;
  }
}

/*******************************************************************************
 *
 * Function         btif_dm_upstreams_cback
 *
 * Description      Executes UPSTREAMS events in btif context
 *
 * Returns          void
 *
 ******************************************************************************/
static void btif_dm_upstreams_evt(uint16_t event, char* p_param) {
  tBTA_DM_SEC* p_data = (tBTA_DM_SEC*)p_param;
  tBTA_SERVICE_MASK service_mask;
  uint32_t i;
  RawAddress bd_addr;

  BTIF_TRACE_EVENT("%s: ev: %s", __func__, dump_dm_event(event));

  switch (event) {
    case BTA_DM_ENABLE_EVT: {
      BD_NAME bdname;
      bt_status_t status;
      bt_property_t prop;
      prop.type = BT_PROPERTY_BDNAME;
      prop.len = BD_NAME_LEN + 1;
      prop.val = (void*)bdname;

      status = btif_storage_get_adapter_property(&prop);
      if (status == BT_STATUS_SUCCESS) {
        /* A name exists in the storage. Make this the device name */
        BTA_DmSetDeviceName((char*)prop.val);
      } else {
        /* Storage does not have a name yet.
         * Use the default name and write it to the chip
         */
        BTA_DmSetDeviceName(btif_get_default_local_name());
      }

      /* Enable local privacy */
      BTA_DmBleConfigLocalPrivacy(BLE_LOCAL_PRIVACY_ENABLED);

      /* for each of the enabled services in the mask, trigger the profile
       * enable */
      service_mask = btif_get_enabled_services_mask();
      for (i = 0; i <= BTA_MAX_SERVICE_ID; i++) {
        if (service_mask &
            (tBTA_SERVICE_MASK)(BTA_SERVICE_ID_TO_SERVICE_MASK(i))) {
          btif_in_execute_service_request(i, true);
        }
      }

      /* clear control blocks */
      memset(&pairing_cb, 0, sizeof(btif_dm_pairing_cb_t));
      pairing_cb.bond_type = BOND_TYPE_PERSISTENT;

      /* This function will also trigger the adapter_properties_cb
      ** and bonded_devices_info_cb
      */
      btif_storage_load_bonded_devices();

      btif_vendor_update_add_on_features();

      btif_vendor_update_whitelisted_media_players();

      bluetooth::bqr::EnableBtQualityReport(true);
      btif_enable_bluetooth_evt(p_data->enable.status);
    } break;

    case BTA_DM_DISABLE_EVT:
      /* for each of the enabled services in the mask, trigger the profile
       * disable */
      service_mask = btif_get_enabled_services_mask();
      if (service_mask &
          (tBTA_SERVICE_MASK)(BTA_SERVICE_ID_TO_SERVICE_MASK(BTA_BLE_SERVICE_ID))) {
        btif_in_execute_service_request(BTA_BLE_SERVICE_ID, FALSE);
      }
      btif_disable_bluetooth_evt();
      break;

    case BTA_DM_PIN_REQ_EVT:
      btif_dm_pin_req_evt(&p_data->pin_req);
      break;

    case BTA_DM_AUTH_CMPL_EVT:
      btif_dm_auth_cmpl_evt(&p_data->auth_cmpl);
      break;

    case BTA_DM_BOND_CANCEL_CMPL_EVT:
      if (is_bonding_or_sdp()) {
        bd_addr = pairing_cb.bd_addr;
        btm_set_bond_type_dev(pairing_cb.bd_addr, BOND_TYPE_UNKNOWN);
        bond_state_changed((bt_status_t)p_data->bond_cancel_cmpl.result,
                           bd_addr, BT_BOND_STATE_NONE);
		btif_dm_remove_bond(&bd_addr);
      }
      break;

    case BTA_DM_SP_CFM_REQ_EVT:
      btif_dm_ssp_cfm_req_evt(&p_data->cfm_req);
      break;
    case BTA_DM_SP_KEY_NOTIF_EVT:
      btif_dm_ssp_key_notif_evt(&p_data->key_notif);
      break;

    case BTA_DM_DEV_UNPAIRED_EVT:
      bd_addr = p_data->link_down.bd_addr;
      btm_set_bond_type_dev(p_data->link_down.bd_addr, BOND_TYPE_UNKNOWN);

/*special handling for HID devices */
#if (defined(BTA_HH_INCLUDED) && (BTA_HH_INCLUDED == TRUE))
      btif_hh_remove_device(bd_addr);
#endif
#if (defined(BTA_HD_INCLUDED) && (BTA_HD_INCLUDED == TRUE))
      btif_hd_remove_device(bd_addr);
#endif
      btif_hearing_aid_get_interface()->RemoveDevice(bd_addr);
      btif_storage_remove_bonded_device(&bd_addr);
      btif_stack_dev_unpaired(bd_addr);
      BTA_DmResetPairingflag(bd_addr);
      bond_state_changed(BT_STATUS_SUCCESS, bd_addr, BT_BOND_STATE_NONE);
      break;

    case BTA_DM_BUSY_LEVEL_EVT: {
      if (p_data->busy_level.level_flags & BTM_BL_INQUIRY_PAGING_MASK) {
        if (p_data->busy_level.level_flags == BTM_BL_INQUIRY_STARTED) {
          HAL_CBACK(bt_hal_cbacks, discovery_state_changed_cb,
                    BT_DISCOVERY_STARTED);
          btif_dm_inquiry_in_progress = true;
        } else if (p_data->busy_level.level_flags == BTM_BL_INQUIRY_CANCELLED) {
          HAL_CBACK(bt_hal_cbacks, discovery_state_changed_cb,
                    BT_DISCOVERY_STOPPED);
          btif_dm_inquiry_in_progress = false;
        } else if (p_data->busy_level.level_flags == BTM_BL_INQUIRY_COMPLETE) {
          btif_dm_inquiry_in_progress = false;
        }
      }
    } break;

    case BTA_DM_LINK_UP_EVT:
      bd_addr = p_data->link_up.bd_addr;
      BTIF_TRACE_DEBUG("BTA_DM_LINK_UP_EVT. Sending BT_ACL_STATE_CONNECTED");

      if (p_data->link_up.link_type == BT_TRANSPORT_LE) {
        num_active_le_links++;
        BTIF_TRACE_DEBUG("num_active_le_links is %d ", num_active_le_links);
      }

      if (p_data->link_up.link_type == BT_TRANSPORT_BR_EDR) {
        num_active_br_edr_links++;
        BTIF_TRACE_DEBUG("num_active_br_edr_links is %d ", num_active_br_edr_links);
      }
      /* When tuchtones are enabled and 2 EDR HS are connected, if new
       * connection is initated, then tuch tones are send to both connected HS
       * over A2dp.Stream will be suspended after 3 secs and if remote has
       * initiated play in this duartion, multicast must not be enabled with
       * 3 ACL's, hence trigger a2dp suspend.
       * During active muisc streaming no new connection can happen, hence
       * We will get this only when multistreaming is happening due to tuchtones
       */
#if (BTIF_DM_ENABLE_MCAST_RESTRICTIONS == TRUE)
      if (btif_av_get_ongoing_multicast()) {
        // trigger a2dp suspend
        btif_av_trigger_suspend();
      }
#endif
      btif_update_remote_version_property(&bd_addr);

      HAL_CBACK(bt_hal_cbacks, acl_state_changed_cb, BT_STATUS_SUCCESS,
                &bd_addr, BT_ACL_STATE_CONNECTED, HCI_SUCCESS);
      break;

    case BTA_DM_LINK_DOWN_EVT:
      bd_addr = p_data->link_down.bd_addr;
      btm_set_bond_type_dev(p_data->link_down.bd_addr, BOND_TYPE_UNKNOWN);

      BTIF_TRACE_DEBUG("BTA_DM_LINK_DOWN_EVT. Sending BT_ACL_STATE_DISCONNECTED");

      /* For HID pointing device upon authentication is successful, SDP
       * is delayed by 500ms and bond state is updated to BONDED from bonding.
       * If remote sent disconnect before SDP is successful, deleting bonded
       * device from the database and moving bond state to BOND NONE.
       */
      if (pairing_cb.bd_addr == bd_addr && pairing_cb.sdp_attempts !=0 &&
          (check_cod(&bd_addr, COD_HID_POINTING))) {
            BTIF_TRACE_WARNING("%s: deleting bonded device from database", __func__);
            if (!bl_device.sdp_delay_timer &&
                alarm_is_scheduled(bl_device.sdp_delay_timer))
              alarm_cancel(bl_device.sdp_delay_timer);

            btif_storage_remove_bonded_device(&bd_addr);
            BTA_DmRemoveDevice(bd_addr);
            bond_state_changed(BT_STATUS_FAIL, pairing_cb.bd_addr, BT_BOND_STATE_NONE);
      }

      if (num_active_le_links > 0 &&
          p_data->link_down.link_type == BT_TRANSPORT_LE) {
        num_active_le_links--;
        BTIF_TRACE_DEBUG("num_active_le_links is %d ",num_active_le_links);
      }

      if (num_active_br_edr_links > 0 &&
          p_data->link_down.link_type == BT_TRANSPORT_BR_EDR) {
        num_active_br_edr_links--;
        BTIF_TRACE_DEBUG("num_active_br_edr_links is %d ",num_active_br_edr_links);
      }
      btif_av_move_idle(bd_addr);
      BTIF_TRACE_DEBUG(
          "BTA_DM_LINK_DOWN_EVT. Sending BT_ACL_STATE_DISCONNECTED");
      HAL_CBACK(bt_hal_cbacks, acl_state_changed_cb, BT_STATUS_SUCCESS,
                &bd_addr, BT_ACL_STATE_DISCONNECTED,
                static_cast<bt_hci_error_code_t>(btm_get_acl_disc_reason_code()));
      break;

    case BTA_DM_HW_ERROR_EVT:
      BTIF_TRACE_ERROR("Received H/W Error. ");
      /* Flush storage data */
      btif_config_flush();
      usleep(100000); /* 100milliseconds */
      /* Killing the process to force a restart as part of fault tolerance */
      kill(getpid(), SIGKILL);
      break;

    case BTA_DM_BLE_KEY_EVT:
      BTIF_TRACE_DEBUG("BTA_DM_BLE_KEY_EVT key_type=0x%02x ",
                       p_data->ble_key.key_type);

      /* If this pairing is by-product of local initiated GATT client Read or
      Write,
      BTA would not have sent BTA_DM_BLE_SEC_REQ_EVT event and Bond state would
      not
      have setup properly. Setup pairing_cb and notify App about Bonding state
      now*/
      if (pairing_cb.state != BT_BOND_STATE_BONDING) {
        BTIF_TRACE_DEBUG(
            "Bond state not sent to App so far.Notify the app now");
        bond_state_changed(BT_STATUS_SUCCESS, p_data->ble_key.bd_addr,
                           BT_BOND_STATE_BONDING);
      } else if (pairing_cb.bd_addr != p_data->ble_key.bd_addr) {
        BTIF_TRACE_ERROR("BD mismatch discard BLE key_type=%d ",
                         p_data->ble_key.key_type);
        break;
      }

      switch (p_data->ble_key.key_type) {
        case BTA_LE_KEY_PENC:
          BTIF_TRACE_DEBUG("Rcv BTA_LE_KEY_PENC");
          pairing_cb.ble.is_penc_key_rcvd = true;
          pairing_cb.ble.penc_key = p_data->ble_key.p_key_value->penc_key;
          break;

        case BTA_LE_KEY_PID:
          BTIF_TRACE_DEBUG("Rcv BTA_LE_KEY_PID");
          pairing_cb.ble.is_pid_key_rcvd = true;
          pairing_cb.ble.pid_key = p_data->ble_key.p_key_value->pid_key;
          break;

        case BTA_LE_KEY_PCSRK:
          BTIF_TRACE_DEBUG("Rcv BTA_LE_KEY_PCSRK");
          pairing_cb.ble.is_pcsrk_key_rcvd = true;
          pairing_cb.ble.pcsrk_key = p_data->ble_key.p_key_value->pcsrk_key;
          break;

        case BTA_LE_KEY_LENC:
          BTIF_TRACE_DEBUG("Rcv BTA_LE_KEY_LENC");
          pairing_cb.ble.is_lenc_key_rcvd = true;
          pairing_cb.ble.lenc_key = p_data->ble_key.p_key_value->lenc_key;
          break;

        case BTA_LE_KEY_LCSRK:
          BTIF_TRACE_DEBUG("Rcv BTA_LE_KEY_LCSRK");
          pairing_cb.ble.is_lcsrk_key_rcvd = true;
          pairing_cb.ble.lcsrk_key = p_data->ble_key.p_key_value->lcsrk_key;
          break;

        case BTA_LE_KEY_LID:
          BTIF_TRACE_DEBUG("Rcv BTA_LE_KEY_LID");
          pairing_cb.ble.is_lidk_key_rcvd = true;
          break;

        default:
          BTIF_TRACE_ERROR("unknown BLE key type (0x%02x)",
                           p_data->ble_key.key_type);
          break;
      }
      break;
    case BTA_DM_BLE_CONSENT_REQ_EVT:
      BTIF_TRACE_DEBUG("BTA_DM_BLE_CONSENT_REQ_EVT. ");
      btif_dm_ble_sec_req_evt(&p_data->ble_req, true);
      break;
    case BTA_DM_BLE_SEC_REQ_EVT:
      BTIF_TRACE_DEBUG("BTA_DM_BLE_SEC_REQ_EVT. ");
      btif_dm_ble_sec_req_evt(&p_data->ble_req, false);
      break;
    case BTA_DM_BLE_PASSKEY_NOTIF_EVT:
      BTIF_TRACE_DEBUG("BTA_DM_BLE_PASSKEY_NOTIF_EVT. ");
      btif_dm_ble_key_notif_evt(&p_data->key_notif);
      break;
    case BTA_DM_BLE_PASSKEY_REQ_EVT:
      BTIF_TRACE_DEBUG("BTA_DM_BLE_PASSKEY_REQ_EVT. ");
      btif_dm_ble_passkey_req_evt(&p_data->pin_req);
      break;
    case BTA_DM_BLE_NC_REQ_EVT:
      BTIF_TRACE_DEBUG("BTA_DM_BLE_PASSKEY_REQ_EVT. ");
      btif_dm_ble_key_nc_req_evt(&p_data->key_notif);
      break;
    case BTA_DM_BLE_OOB_REQ_EVT:
      BTIF_TRACE_DEBUG("BTA_DM_BLE_OOB_REQ_EVT. ");
      btif_dm_ble_oob_req_evt(&p_data->rmt_oob);
      break;
    case BTA_DM_BLE_SC_OOB_REQ_EVT:
      BTIF_TRACE_DEBUG("BTA_DM_BLE_SC_OOB_REQ_EVT. ");
      btif_dm_ble_sc_oob_req_evt(&p_data->rmt_oob);
      break;
    case BTA_DM_BLE_SC_CR_LOC_OOB_EVT:
      BTIF_TRACE_DEBUG("BTA_DM_BLE_SC_CR_LOC_OOB_EVT");
      btif_dm_proc_loc_oob(BT_TRANSPORT_LE, true,
                           p_data->local_oob_data.local_oob_c,
                           p_data->local_oob_data.local_oob_r);
      break;

    case BTA_DM_BLE_LOCAL_IR_EVT:
      BTIF_TRACE_DEBUG("BTA_DM_BLE_LOCAL_IR_EVT. ");
      ble_local_key_cb.is_id_keys_rcvd = true;
      ble_local_key_cb.id_keys.irk = p_data->ble_id_keys.irk;
      ble_local_key_cb.id_keys.ir = p_data->ble_id_keys.ir;
      ble_local_key_cb.id_keys.dhk = p_data->ble_id_keys.dhk;
      btif_storage_add_ble_local_key(ble_local_key_cb.id_keys.irk,
                                     BTIF_DM_LE_LOCAL_KEY_IRK);
      btif_storage_add_ble_local_key(ble_local_key_cb.id_keys.ir,
                                     BTIF_DM_LE_LOCAL_KEY_IR);
      btif_storage_add_ble_local_key(ble_local_key_cb.id_keys.dhk,
                                     BTIF_DM_LE_LOCAL_KEY_DHK);
      break;
    case BTA_DM_BLE_LOCAL_ER_EVT:
      BTIF_TRACE_DEBUG("BTA_DM_BLE_LOCAL_ER_EVT. ");
      ble_local_key_cb.is_er_rcvd = true;
      ble_local_key_cb.er = p_data->ble_er;
      btif_storage_add_ble_local_key(ble_local_key_cb.er,
                                     BTIF_DM_LE_LOCAL_KEY_ER);
      break;

    case BTA_DM_BLE_AUTH_CMPL_EVT:
      BTIF_TRACE_DEBUG("BTA_DM_BLE_AUTH_CMPL_EVT. ");
      btif_dm_ble_auth_cmpl_evt(&p_data->auth_cmpl);
      break;

    case BTA_DM_LE_FEATURES_READ: {
      tBTM_BLE_VSC_CB cmn_vsc_cb;
      bt_local_le_features_t local_le_features;
      char buf[512];
      bt_property_t prop;
      prop.type = BT_PROPERTY_LOCAL_LE_FEATURES;
      prop.val = (void*)buf;
      prop.len = sizeof(buf);

      /* LE features are not stored in storage. Should be retrived from stack */
      BTM_BleGetVendorCapabilities(&cmn_vsc_cb);
      local_le_features.local_privacy_enabled = BTM_BleLocalPrivacyEnabled();

      prop.len = sizeof(bt_local_le_features_t);
      if (cmn_vsc_cb.filter_support == 1)
        local_le_features.max_adv_filter_supported = cmn_vsc_cb.max_filter;
      else
        local_le_features.max_adv_filter_supported = 0;
      local_le_features.max_adv_instance = cmn_vsc_cb.adv_inst_max;
      local_le_features.max_irk_list_size = cmn_vsc_cb.max_irk_list_sz;
      local_le_features.rpa_offload_supported = cmn_vsc_cb.rpa_offloading;
      local_le_features.activity_energy_info_supported =
          cmn_vsc_cb.energy_support;
      local_le_features.scan_result_storage_size =
          cmn_vsc_cb.tot_scan_results_strg;
      local_le_features.version_supported = cmn_vsc_cb.version_supported;
      local_le_features.total_trackable_advertisers =
          cmn_vsc_cb.total_trackable_advertisers;

      local_le_features.extended_scan_support =
          cmn_vsc_cb.extended_scan_support > 0;
      local_le_features.debug_logging_supported =
          cmn_vsc_cb.debug_logging_supported > 0;

      const controller_t* controller = controller_get_interface();

      local_le_features.le_2m_phy_supported = controller->supports_ble_2m_phy();
      local_le_features.le_coded_phy_supported =
          controller->supports_ble_coded_phy();
      local_le_features.le_extended_advertising_supported =
          controller->supports_ble_extended_advertising();
      local_le_features.le_periodic_advertising_supported =
          controller->supports_ble_periodic_advertising();
      local_le_features.le_maximum_advertising_data_length =
          controller->get_ble_maxium_advertising_data_length();

      local_le_features.dynamic_audio_buffer_supported =
          cmn_vsc_cb.dynamic_audio_buffer_support;

      memcpy(prop.val, &local_le_features, prop.len);
      HAL_CBACK(bt_hal_cbacks, adapter_properties_cb, BT_STATUS_SUCCESS, 1,
                &prop);
      break;
    }

    case BTA_DM_ENER_INFO_READ: {
      btif_activity_energy_info_cb_t* p_ener_data =
          (btif_activity_energy_info_cb_t*)p_param;
      bt_activity_energy_info energy_info;
      energy_info.status = p_ener_data->status;
      energy_info.ctrl_state = p_ener_data->ctrl_state;
      energy_info.rx_time = p_ener_data->rx_time;
      energy_info.tx_time = p_ener_data->tx_time;
      energy_info.idle_time = p_ener_data->idle_time;
      energy_info.energy_used = p_ener_data->energy_used;

      bt_uid_traffic_t* data = uid_set_read_and_clear(uid_set);
      HAL_CBACK(bt_hal_cbacks, energy_info_cb, &energy_info, data);
      osi_free(data);
      break;
    }

    case BTA_DM_PKT_TYPE_CHG_EVT: {
      // update streaming bit rate from av
      break;
    }

    case BTA_DM_SOC_LOGGING_EVT: {
      if ((p_data->soc_logging.soc_log_id == (LOG_ID_STATS_A2DP)) &&
            is_codec_config_dump) {
        BTIF_TRACE_WARNING( " event(%d),dump a2dp configuration", event);
        btif_av_peer_config_dump();
        is_codec_config_dump = false;
      }
        break;
    }

    case BTA_DM_IOT_INFO_EVT: {
      tBTA_DM_IOT_INFO_DATA iot_info = p_data->iot_info;
      BTIF_TRACE_WARNING("BTA_DM_IOT_INFO_EVT");
      btif_vendor_iot_device_broadcast_event(&iot_info.bd_addr, iot_info.error_type, iot_info.error_info,
              iot_info.event_mask, iot_info.event_power_level, iot_info.event_rssi, iot_info.event_link_quality,
              iot_info.event_glitch_count);
      break;
    }

    case BTA_DM_SSR_EVT: {
      BTIF_TRACE_WARNING("BTA_DM_SSR_EVT");
      HAL_CBACK(bt_vendor_callbacks, ssr_vendor_cb);
      break;
    }

    case BTA_DM_REM_NAME_EVT:
      BTIF_TRACE_DEBUG("BTA_DM_REM_NAME_EVT");

      /* remote name */
      if (strlen((char *)p_data->rem_name_evt.bd_name) > 0) {
        bt_property_t properties[1];
        bt_status_t status;

        BTIF_TRACE_DEBUG("name of device = %s", p_data->rem_name_evt.bd_name);
        properties[0].type = BT_PROPERTY_BDNAME;
        properties[0].val = p_data->rem_name_evt.bd_name;
        properties[0].len = strlen((char *)p_data->rem_name_evt.bd_name);
        bd_addr = p_data->rem_name_evt.bd_addr;

        status = btif_storage_set_remote_device_property(&bd_addr, &properties[0]);
        ASSERTC(status == BT_STATUS_SUCCESS, "failed to save remote device property",
            status);
        HAL_CBACK(bt_hal_cbacks, remote_device_properties_cb,
                         status, &bd_addr, 1, properties);
     }

    break;

    case BTA_DM_DISABLE_BQR_EVT: {
      bluetooth::bqr::EnableBtQualityReport(false);
      break;
    }

    case BTA_DM_AUTHORIZE_EVT:
    case BTA_DM_SIG_STRENGTH_EVT:
    case BTA_DM_SP_RMT_OOB_EVT:
    case BTA_DM_SP_KEYPRESS_EVT:
    case BTA_DM_ROLE_CHG_EVT:

    default:
      BTIF_TRACE_WARNING("btif_dm_cback : unhandled event (%d)", event);
      break;
  }

  btif_dm_data_free(event, p_data);
}

/*******************************************************************************
 *
 * Function         btif_dm_generic_evt
 *
 * Description      Executes non-BTA upstream events in BTIF context
 *
 * Returns          void
 *
 ******************************************************************************/
static void btif_dm_generic_evt(uint16_t event, char* p_param) {
  BTIF_TRACE_EVENT("%s: event=%d", __func__, event);
  switch (event) {
    case BTIF_DM_CB_DISCOVERY_STARTED: {
      HAL_CBACK(bt_hal_cbacks, discovery_state_changed_cb,
                BT_DISCOVERY_STARTED);
    } break;

    case BTIF_DM_CB_CREATE_BOND: {
      pairing_cb.timeout_retries = NUM_TIMEOUT_RETRIES;
      btif_dm_create_bond_cb_t* create_bond_cb =
          (btif_dm_create_bond_cb_t*)p_param;
      btif_dm_cb_create_bond(create_bond_cb->bdaddr, create_bond_cb->transport);
    } break;

    case BTIF_DM_CB_REMOVE_BOND: {
      btif_dm_cb_remove_bond((RawAddress*)p_param);
    } break;

    case BTIF_DM_CB_HID_REMOTE_NAME: {
      btif_dm_cb_hid_remote_name((tBTM_REMOTE_DEV_NAME*)p_param);
    } break;

    case BTIF_DM_CB_BOND_STATE_BONDING: {
      bond_state_changed(BT_STATUS_SUCCESS, *((RawAddress*)p_param),
                         BT_BOND_STATE_BONDING);
    } break;
    case BTIF_DM_CB_LE_TX_TEST:
    case BTIF_DM_CB_LE_RX_TEST: {
      uint8_t status;
      STREAM_TO_UINT8(status, p_param);
      HAL_CBACK(bt_hal_cbacks, le_test_mode_cb,
                (status == 0) ? BT_STATUS_SUCCESS : BT_STATUS_FAIL, 0);
    } break;
    case BTIF_DM_CB_LE_TEST_END: {
      uint8_t status;
      uint16_t count = 0;
      STREAM_TO_UINT8(status, p_param);
      if (status == 0) STREAM_TO_UINT16(count, p_param);
      HAL_CBACK(bt_hal_cbacks, le_test_mode_cb,
                (status == 0) ? BT_STATUS_SUCCESS : BT_STATUS_FAIL, count);
    } break;
    default: {
      BTIF_TRACE_WARNING("%s : Unknown event 0x%x", __func__, event);
    } break;
  }
}

/*******************************************************************************
 *
 * Function         bte_dm_evt
 *
 * Description      Switches context from BTE to BTIF for all DM events
 *
 * Returns          void
 *
 ******************************************************************************/

void bte_dm_evt(tBTA_DM_SEC_EVT event, tBTA_DM_SEC* p_data) {
  /* switch context to btif task context (copy full union size for convenience)
   */
  bt_status_t status = btif_transfer_context(
      btif_dm_upstreams_evt, (uint16_t)event, (char*)p_data,
      sizeof(tBTA_DM_SEC), btif_dm_data_copy);

  /* catch any failed context transfers */
  ASSERTC(status == BT_STATUS_SUCCESS, "context transfer failed", status);
}

/*******************************************************************************
 *
 * Function         bte_search_devices_evt
 *
 * Description      Switches context from BTE to BTIF for DM search events
 *
 * Returns          void
 *
 ******************************************************************************/
static void bte_search_devices_evt(tBTA_DM_SEARCH_EVT event,
                                   tBTA_DM_SEARCH* p_data) {
  uint16_t param_len = 0;

  if (p_data) param_len += sizeof(tBTA_DM_SEARCH);
  /* Allocate buffer to hold the pointers (deep copy). The pointers will point
   * to the end of the tBTA_DM_SEARCH */
  switch (event) {
    case BTA_DM_INQ_RES_EVT: {
      if (p_data && p_data->inq_res.p_eir) param_len += p_data->inq_res.eir_len;
    } break;

    case BTA_DM_DISC_RES_EVT: {
      if (p_data && p_data->disc_res.raw_data_size && p_data->disc_res.p_raw_data)
        param_len += p_data->disc_res.raw_data_size;
    } break;
  }
  BTIF_TRACE_DEBUG("%s event=%s param_len=%d", __func__,
                   dump_dm_search_event(event), param_len);

  /* if remote name is available in EIR, set teh flag so that stack doesnt
   * trigger RNR */
  if (p_data && event == BTA_DM_INQ_RES_EVT)
    p_data->inq_res.remt_name_not_required =
        check_eir_remote_name(p_data, NULL, NULL);

  btif_transfer_context(
      btif_dm_search_devices_evt, (uint16_t)event, (char*)p_data, param_len,
      (param_len > sizeof(tBTA_DM_SEARCH)) ? search_devices_copy_cb : NULL);
}


/*******************************************************************************
 *
 * Function         bte_dm_search_services_evt
 *
 * Description      Switches context from BTE to BTIF for DM search services
 *                  event
 *
 * Returns          void
 *
 ******************************************************************************/
static void bte_dm_search_services_evt(tBTA_DM_SEARCH_EVT event,
                                       tBTA_DM_SEARCH* p_data) {
  uint16_t param_len = 0;
  if (p_data) param_len += sizeof(tBTA_DM_SEARCH);
  switch (event) {
    case BTA_DM_DISC_RES_EVT: {
      if ((p_data && p_data->disc_res.result == BTA_SUCCESS) &&
          (p_data->disc_res.num_uuids > 0)) {
        param_len += (p_data->disc_res.num_uuids * Uuid::kNumBytes128);
      }
    } break;
  }
  /* TODO: The only other member that needs a deep copy is the p_raw_data. But
   * not sure
   * if raw_data is needed. */
  btif_transfer_context(
      btif_dm_search_services_evt, event, (char*)p_data, param_len,
      (param_len > sizeof(tBTA_DM_SEARCH)) ? search_services_copy_cb : NULL);
}

/*******************************************************************************
 *
 * Function         bte_dm_remote_service_record_evt
 *
 * Description      Switches context from BTE to BTIF for DM search service
 *                  record event
 *
 * Returns          void
 *
 ******************************************************************************/
static void bte_dm_remote_service_record_evt(tBTA_DM_SEARCH_EVT event,
                                             tBTA_DM_SEARCH* p_data) {
  /* TODO: The only member that needs a deep copy is the p_raw_data. But not
   * sure yet if this is needed. */
  btif_transfer_context(btif_dm_remote_service_record_evt, event, (char*)p_data,
                        sizeof(tBTA_DM_SEARCH), NULL);
}

/*******************************************************************************
 *
 * Function         bta_energy_info_cb
 *
 * Description      Switches context from BTE to BTIF for DM energy info event
 *
 * Returns          void
 *
 ******************************************************************************/
static void bta_energy_info_cb(tBTA_DM_BLE_TX_TIME_MS tx_time,
                               tBTA_DM_BLE_RX_TIME_MS rx_time,
                               tBTA_DM_BLE_IDLE_TIME_MS idle_time,
                               tBTA_DM_BLE_ENERGY_USED energy_used,
                               tBTA_DM_CONTRL_STATE ctrl_state,
                               tBTA_STATUS status) {
  BTIF_TRACE_DEBUG(
      "energy_info_cb-Status:%d,state=%d,tx_t=%ld, rx_t=%ld, "
      "idle_time=%ld,used=%ld",
      status, ctrl_state, tx_time, rx_time, idle_time, energy_used);

  btif_activity_energy_info_cb_t btif_cb;
  btif_cb.status = status;
  btif_cb.ctrl_state = ctrl_state;
  btif_cb.tx_time = (uint64_t)tx_time;
  btif_cb.rx_time = (uint64_t)rx_time;
  btif_cb.idle_time = (uint64_t)idle_time;
  btif_cb.energy_used = (uint64_t)energy_used;
  btif_transfer_context(btif_dm_upstreams_evt, BTA_DM_ENER_INFO_READ,
                        (char*)&btif_cb, sizeof(btif_activity_energy_info_cb_t),
                        NULL);
}

/* Scan filter param config event */
static void bte_scan_filt_param_cfg_evt(uint8_t ref_value, uint8_t avbl_space,
                                        uint8_t action_type, uint8_t status) {
  /* This event occurs on calling BTA_DmBleCfgFilterCondition internally,
  ** and that is why there is no HAL callback
  */
  if (BTA_SUCCESS != status) {
    BTIF_TRACE_ERROR("%s, %d", __func__, status);
  } else {
    BTIF_TRACE_DEBUG("%s", __func__);
  }
}

/*****************************************************************************
 *
 *   btif api functions (no context switch)
 *
 ****************************************************************************/

/*******************************************************************************
 *
 * Function         btif_dm_start_discovery
 *
 * Description      Start device discovery/inquiry
 *
 * Returns          bt_status_t
 *
 ******************************************************************************/
bt_status_t btif_dm_start_discovery(void) {
  tBTA_DM_INQ inq_params;
  tBTA_SERVICE_MASK services = 0;

  BTIF_TRACE_EVENT("%s : pairing_cb.state: 0x%x", __FUNCTION__, pairing_cb.state);

  /* We should not go for inquiry in BONDING STATE. */
  if (pairing_cb.state == BT_BOND_STATE_BONDING)
      return BT_STATUS_BUSY;

  char donglemode_prop[PROPERTY_VALUE_MAX] = "false";
  if(osi_property_get("persist.bluetooth.donglemode", donglemode_prop, "false") &&
      !strcmp(donglemode_prop, "false")) {
    /* Cleanup anything remaining on index 0 */
    do_in_bta_thread(
        FROM_HERE,
        base::Bind(&BTM_BleAdvFilterParamSetup, BTM_BLE_SCAN_COND_DELETE, 0,
                   nullptr, base::Bind(&bte_scan_filt_param_cfg_evt, 0)));

    auto adv_filt_param = std::make_unique<btgatt_filt_param_setup_t>();
    /* Add an allow-all filter on index 0*/
    adv_filt_param->dely_mode = IMMEDIATE_DELY_MODE;
    adv_filt_param->feat_seln = ALLOW_ALL_FILTER;
    adv_filt_param->filt_logic_type = BTA_DM_BLE_PF_FILT_LOGIC_OR;
    adv_filt_param->list_logic_type = BTA_DM_BLE_PF_LIST_LOGIC_OR;
    adv_filt_param->rssi_low_thres = LOWEST_RSSI_VALUE;
    adv_filt_param->rssi_high_thres = LOWEST_RSSI_VALUE;
    do_in_bta_thread(
        FROM_HERE, base::Bind(&BTM_BleAdvFilterParamSetup, BTM_BLE_SCAN_COND_ADD,
                              0, base::Passed(&adv_filt_param),
                              base::Bind(&bte_scan_filt_param_cfg_evt, 0)));
  }

  /* TODO: Do we need to handle multiple inquiries at the same time? */

  /* Set inquiry params and call API */
  inq_params.mode = BTA_DM_GENERAL_INQUIRY | BTA_BLE_GENERAL_INQUIRY;
#if (BTA_HOST_INTERLEAVE_SEARCH == TRUE)
  inq_params.intl_duration[0] = BTIF_DM_INTERLEAVE_DURATION_BR_ONE;
  inq_params.intl_duration[1] = BTIF_DM_INTERLEAVE_DURATION_LE_ONE;
  inq_params.intl_duration[2] = BTIF_DM_INTERLEAVE_DURATION_BR_TWO;
  inq_params.intl_duration[3] = BTIF_DM_INTERLEAVE_DURATION_LE_TWO;
#endif
  inq_params.duration = BTIF_DM_DEFAULT_INQ_MAX_DURATION;

  inq_params.max_resps = BTIF_DM_DEFAULT_INQ_MAX_RESULTS;
  inq_params.report_dup = true;

  inq_params.filter_type = BTA_DM_INQ_CLR;
  /* TODO: Filter device by BDA needs to be implemented here */

  /* Will be enabled to true once inquiry busy level has been received */
  btif_dm_inquiry_in_progress = false;
  /* find nearby devices */
  BTA_DmSearch(&inq_params, services, bte_search_devices_evt);

  return BT_STATUS_SUCCESS;
}

/*******************************************************************************
 *
 * Function         btif_dm_cancel_discovery
 *
 * Description      Cancels search
 *
 * Returns          bt_status_t
 *
 ******************************************************************************/
bt_status_t btif_dm_cancel_discovery(void) {
  BTIF_TRACE_EVENT("%s", __func__);
  BTA_DmSearchCancel();
  return BT_STATUS_SUCCESS;
}

/*******************************************************************************
 *
 * Function         btif_dm_create_bond
 *
 * Description      Initiate bonding with the specified device
 *
 * Returns          bt_status_t
 *
 ******************************************************************************/
bt_status_t btif_dm_create_bond(const RawAddress* bd_addr, int transport) {
  btif_dm_create_bond_cb_t create_bond_cb;
  create_bond_cb.transport = transport;
  create_bond_cb.bdaddr = *bd_addr;

  BTIF_TRACE_EVENT("%s: bd_addr=%s, transport=%d", __func__,
                   bd_addr->ToString().c_str(), transport);
  BTIF_TRACE_EVENT("%s: bd_addr=%s, state=%d", __func__,
                   bd_addr->ToString().c_str(), pairing_cb.state);
  if (pairing_cb.state != BT_BOND_STATE_NONE) return BT_STATUS_BUSY;

  btif_stats_add_bond_event(*bd_addr, BTIF_DM_FUNC_CREATE_BOND,
                            pairing_cb.state);

  btif_transfer_context(btif_dm_generic_evt, BTIF_DM_CB_CREATE_BOND,
                        (char*)&create_bond_cb,
                        sizeof(btif_dm_create_bond_cb_t), NULL);

  return BT_STATUS_SUCCESS;
}

/*******************************************************************************
 *
 * Function         btif_dm_create_bond_out_of_band
 *
 * Description      Initiate bonding with the specified device using out of band
 *                  data
 *
 * Returns          bt_status_t
 *
 *****************************************************************************/
void btif_dm_create_bond_out_of_band(const RawAddress * bd_addr,
                                            tBT_TRANSPORT transport,
                                            const bt_oob_data_t p192_data,
                                            const bt_oob_data_t p256_data) {
  bt_oob_data_t empty_data;
  memset(&empty_data, 0, sizeof(empty_data));

  oob_cb.bdaddr = *bd_addr;
  oob_cb.transport = transport;
  oob_cb.data_present = (int)BTM_OOB_NONE;
  if (memcmp(&p192_data, &empty_data, sizeof(p192_data)) != 0) {
    memcpy(&oob_cb.p192_data, &p192_data, sizeof(bt_oob_data_t));
    oob_cb.data_present = (int)BTM_OOB_PRESENT_192;
  }

  if (memcmp(&p256_data, &empty_data, sizeof(p256_data)) != 0) {
    memcpy(&oob_cb.p256_data, &p256_data, sizeof(bt_oob_data_t));
    if (oob_cb.data_present == (int)BTM_OOB_PRESENT_192) {
      oob_cb.data_present = (int)BTM_OOB_PRESENT_192_AND_256;
    } else {
      oob_cb.data_present = (int)BTM_OOB_PRESENT_256;
    }
  }

  uint8_t empty[] = {0, 0, 0, 0, 0, 0, 0};
  switch (transport) {
    case BT_TRANSPORT_BR_EDR:
      // TODO(182162589): Flesh out classic impl in legacy BTMSec
      // Nothing to do yet, but not an error

      // The controller only supports P192
      switch (oob_cb.data_present) {
        case BTM_OOB_PRESENT_192_AND_256:
          LOG_INFO(LOG_TAG, "Have both P192 and  P256");
          [[fallthrough]];
        case BTM_OOB_PRESENT_192:
          LOG_INFO(LOG_TAG, "Using P192");
          break;
        case BTM_OOB_PRESENT_256:
          LOG_INFO(LOG_TAG, "Using P256");
          [[fallthrough]];
        default:
          // TODO(181889116):
          // Upgrade to support p256 (for now we just ignore P256)
          // because the controllers do not yet support it.
          LOG_ERROR(LOG_TAG, "Invalid data present for controller: %d",
                    oob_cb.data_present);
          bond_state_changed(BT_STATUS_FAIL, *bd_addr, BT_BOND_STATE_NONE);
          return;
      }
      pairing_cb.is_local_initiated = true;
      LOG_ERROR(LOG_TAG, "Classic not implemented yet");
      bond_state_changed(BT_STATUS_FAIL, *bd_addr, BT_BOND_STATE_NONE);
      return;
    case BT_TRANSPORT_LE: {
      // Guess default RANDOM for address type for LE
      tBLE_ADDR_TYPE address_type = BLE_ADDR_RANDOM;
      LOG_INFO(LOG_TAG, "Using LE Transport");
      switch (oob_cb.data_present) {
        case BTM_OOB_PRESENT_192_AND_256:
          LOG_INFO(LOG_TAG, "Have both P192 and  P256");
          [[fallthrough]];
        // Always prefer 256 for LE
        case BTM_OOB_PRESENT_256:
          LOG_INFO(LOG_TAG, "Using P256");
          // If we have an address, lets get the type
          if (memcmp(p256_data.address, empty, 7) != 0) {
            /* byte no 7 is address type in LE Bluetooth Address OOB data */
            address_type = static_cast<tBLE_ADDR_TYPE>(p256_data.address[6]);
          }
          break;
        case BTM_OOB_PRESENT_192:
          LOG_INFO(LOG_TAG, "Using P192");
          // If we have an address, lets get the type
          if (memcmp(p192_data.address, empty, 7) != 0) {
            /* byte no 7 is address type in LE Bluetooth Address OOB data */
            address_type = static_cast<tBLE_ADDR_TYPE>(p192_data.address[6]);
          }
          break;
      }
      pairing_cb.is_local_initiated = true;
      BTM_SecAddBleDevice(*bd_addr, NULL, BT_DEVICE_TYPE_BLE, address_type);
      BTA_DmBond(*bd_addr);
      break;
    }
    default:
      LOG_ERROR(LOG_TAG, "Invalid transport: %d", transport);
      bond_state_changed(BT_STATUS_FAIL, *bd_addr, BT_BOND_STATE_NONE);
      return;
  }
}

/*******************************************************************************
 *
 * Function         btif_dm_cancel_bond
 *
 * Description      Initiate bonding with the specified device
 *
 * Returns          bt_status_t
 *
 ******************************************************************************/

bt_status_t btif_dm_cancel_bond(const RawAddress* bd_addr) {
  BTIF_TRACE_EVENT("%s: bd_addr=%s", __func__, bd_addr->ToString().c_str());

  btif_stats_add_bond_event(*bd_addr, BTIF_DM_FUNC_CANCEL_BOND,
                            pairing_cb.state);

  /* TODO:
  **  1. Restore scan modes
  **  2. special handling for HID devices
  */
  if (is_bonding_or_sdp()) {
    if (pairing_cb.is_ssp) {
      if (pairing_cb.is_le_only) {
        BTA_DmBleSecurityGrant(*bd_addr, BTA_DM_SEC_PAIR_NOT_SPT);
      } else {
        BTA_DmConfirm(*bd_addr, false);
        BTA_DmBondCancel(*bd_addr);
        btif_storage_remove_bonded_device(bd_addr);
      }
    } else {
      if (pairing_cb.is_le_only) {
        BTA_DmBondCancel(*bd_addr);
      } else {
        BTA_DmPinReply(*bd_addr, false, 0, NULL);
      }
      /* Cancel bonding, in case it is in ACL connection setup state */
      BTA_DmBondCancel(*bd_addr);
    }
  }

  return BT_STATUS_SUCCESS;
}

/*******************************************************************************
 *
 * Function         btif_dm_hh_open_failed
 *
 * Description      informs the upper layers if the HH have failed during
 *                  bonding
 *
 * Returns          none
 *
 ******************************************************************************/

void btif_dm_hh_open_failed(RawAddress* bdaddr) {
  if (pairing_cb.state == BT_BOND_STATE_BONDING &&
      *bdaddr == pairing_cb.bd_addr) {
    BTIF_TRACE_WARNING("%s: remove device security record ", __func__);
    btif_storage_remove_bonded_device(bdaddr);
    BTA_DmRemoveDevice(*bdaddr);
    BTA_DmResetPairingflag(pairing_cb.bd_addr);
    bond_state_changed(BT_STATUS_FAIL, *bdaddr, BT_BOND_STATE_NONE);
  }
}

/*******************************************************************************
 *
 * Function         btif_dm_remove_bond
 *
 * Description      Removes bonding with the specified device
 *
 * Returns          bt_status_t
 *
 ******************************************************************************/

bt_status_t btif_dm_remove_bond(const RawAddress* bd_addr) {
  BTIF_TRACE_EVENT("%s: bd_addr=%s", __func__, bd_addr->ToString().c_str());

  btif_stats_add_bond_event(*bd_addr, BTIF_DM_FUNC_REMOVE_BOND,
                            pairing_cb.state);

  btif_transfer_context(btif_dm_generic_evt, BTIF_DM_CB_REMOVE_BOND,
                        (char*)bd_addr, sizeof(RawAddress), NULL);

  return BT_STATUS_SUCCESS;
}

/*******************************************************************************
 *
 * Function         btif_dm_pin_reply
 *
 * Description      BT legacy pairing - PIN code reply
 *
 * Returns          bt_status_t
 *
 ******************************************************************************/

bt_status_t btif_dm_pin_reply(const RawAddress* bd_addr, uint8_t accept,
                              uint8_t pin_len, bt_pin_code_t* pin_code) {
  BTIF_TRACE_EVENT("%s: accept=%d", __func__, accept);
  if (pin_code == NULL || pin_len > PIN_CODE_LEN) return BT_STATUS_FAIL;
  if (pairing_cb.is_le_only) {
    int i;
    uint32_t passkey = 0;
    int multi[] = {100000, 10000, 1000, 100, 10, 1};
    if(pin_len != 6){
      BTIF_TRACE_ERROR("btif_dm_pin_reply: pin length: %d", pin_len);
      return BT_STATUS_FAIL;
    }
    for (i = 0; i < 6; i++) {
      passkey += (multi[i] * (pin_code->pin[i] - '0'));
    }
    BTIF_TRACE_DEBUG("btif_dm_pin_reply: passkey: %d", passkey);
    BTA_DmBlePasskeyReply(*bd_addr, accept, passkey);

  } else {
    BTA_DmPinReply(*bd_addr, accept, pin_len, pin_code->pin);
    if (accept) pairing_cb.pin_code_len = pin_len;
  }
  return BT_STATUS_SUCCESS;
}

/*******************************************************************************
 *
 * Function         btif_dm_ssp_reply
 *
 * Description      BT SSP Reply - Just Works, Numeric Comparison & Passkey
 *                  Entry
 *
 * Returns          bt_status_t
 *
 ******************************************************************************/
bt_status_t btif_dm_ssp_reply(const RawAddress* bd_addr,
                              bt_ssp_variant_t variant, uint8_t accept,
                              UNUSED_ATTR uint32_t passkey) {
  if (variant == BT_SSP_VARIANT_PASSKEY_ENTRY) {
    /* This is not implemented in the stack.
     * For devices with display, this is not needed
    */
    BTIF_TRACE_WARNING("%s: Not implemented", __func__);
    return BT_STATUS_FAIL;
  }
  /* BT_SSP_VARIANT_CONSENT & BT_SSP_VARIANT_PASSKEY_CONFIRMATION supported */
  BTIF_TRACE_EVENT("%s: accept=%d", __func__, accept);
  if (pairing_cb.is_le_only) {
    if (pairing_cb.is_le_nc) {
      BTA_DmBleConfirmReply(*bd_addr, accept);
    } else {
      if (accept)
        BTA_DmBleSecurityGrant(*bd_addr, BTA_DM_SEC_GRANTED);
      else
        BTA_DmBleSecurityGrant(*bd_addr, BTA_DM_SEC_PAIR_NOT_SPT);
    }
  } else {
    BTA_DmConfirm(*bd_addr, accept);
  }
  return BT_STATUS_SUCCESS;
}

/*******************************************************************************
 *
 * Function         btif_dm_get_adapter_property
 *
 * Description     Queries the BTA for the adapter property
 *
 * Returns          bt_status_t
 *
 ******************************************************************************/
bt_status_t btif_dm_get_adapter_property(bt_property_t* prop) {
  BTIF_TRACE_EVENT("%s: type=0x%x", __func__, prop->type);
  switch (prop->type) {
    case BT_PROPERTY_BDNAME: {
      bt_bdname_t* bd_name = (bt_bdname_t*)prop->val;
      strncpy((char*)bd_name->name, (char*)btif_get_default_local_name(),
              sizeof(bd_name->name) - 1);
      bd_name->name[sizeof(bd_name->name) - 1] = 0;
      prop->len = strlen((char*)bd_name->name);
    } break;

    case BT_PROPERTY_ADAPTER_SCAN_MODE: {
      /* if the storage does not have it. Most likely app never set it. Default
       * is NONE */
      bt_scan_mode_t* mode = (bt_scan_mode_t*)prop->val;
      *mode = BT_SCAN_MODE_NONE;
      prop->len = sizeof(bt_scan_mode_t);
    } break;

    case BT_PROPERTY_ADAPTER_DISCOVERY_TIMEOUT: {
      uint32_t* tmt = (uint32_t*)prop->val;
      *tmt = 120; /* default to 120s, if not found in NV */
      prop->len = sizeof(uint32_t);
    } break;

    case BT_PROPERTY_CLASS_OF_DEVICE: {
      DEV_CLASS dev_class = BTA_DM_COD;
      memcpy(prop->val, dev_class, sizeof(DEV_CLASS));
      prop->len = sizeof(DEV_CLASS);
    } break;

    // While fetching IO_CAP* values for the local device, we maintain backward
    // compatibility by using the value from #define macros BTM_LOCAL_IO_CAPS,
    // BTM_LOCAL_IO_CAPS_BLE if the values have never been explicitly set.

    case BT_PROPERTY_LOCAL_IO_CAPS: {
      *(bt_io_cap_t*)prop->val = (bt_io_cap_t)BTM_LOCAL_IO_CAPS;
      prop->len = sizeof(bt_io_cap_t);
    } break;

    case BT_PROPERTY_LOCAL_IO_CAPS_BLE: {
      *(bt_io_cap_t*)prop->val = (bt_io_cap_t)BTM_LOCAL_IO_CAPS_BLE;
      prop->len = sizeof(bt_io_cap_t);
    } break;

    default:
      prop->len = 0;
      return BT_STATUS_FAIL;
  }
  return BT_STATUS_SUCCESS;
}

/*******************************************************************************
 *
 * Function         btif_dm_get_remote_services_from_app
 *
 * Description      Start SDP to get remote services
 *
 * Returns          bt_status_t
 *
 ******************************************************************************/
bt_status_t btif_dm_get_remote_services_from_app(const RawAddress& remote_addr) {
  if (pairing_cb.state == BT_BOND_STATE_BONDING) {
    BTIF_TRACE_WARNING("%s():in bonding state, return busy", __FUNCTION__);
    return BT_STATUS_BUSY;
  }

  BTIF_TRACE_DEBUG("%s():SDP service search from APP", __FUNCTION__);
  return btif_dm_get_remote_services(remote_addr);
}

/*******************************************************************************
 *
 * Function         btif_dm_get_remote_services
 *
 * Description      Start SDP to get remote services
 *
 * Returns          bt_status_t
 *
 ******************************************************************************/
bt_status_t btif_dm_get_remote_services(const RawAddress& remote_addr) {

  if (remote_addr.IsEmpty()) {
    BTIF_TRACE_WARNING("%s: remote_addr is null", __FUNCTION__);
    return BT_STATUS_FAIL;
  }
  BTIF_TRACE_EVENT("%s: remote_addr=%s", __func__, remote_addr.ToString().c_str());
#ifdef ADV_AUDIO_FEATURE
  if (!is_remote_support_adv_audio(remote_addr)) {
    BTA_DmDiscover(remote_addr, BTA_ALL_SERVICE_MASK, bte_dm_search_services_evt,
                   true);
  } else {
    BTA_DmDiscover(remote_addr, BTA_ALL_SERVICE_MASK, bte_dm_adv_audio_search_services_evt,
                   true);
  }
#else
  BTA_DmDiscover(remote_addr, BTA_ALL_SERVICE_MASK, bte_dm_search_services_evt,
               true);
#endif


  return BT_STATUS_SUCCESS;
}

/*******************************************************************************
 *
 * Function         btif_dm_get_remote_services_by_transport
 *
 * Description      Start SDP to get remote services by transport
 *
 * Returns          bt_status_t
 *
 ******************************************************************************/
bt_status_t btif_dm_get_remote_services_by_transport(RawAddress* remote_addr,
                                                     const int transport) {
  BTIF_TRACE_EVENT("%s: transport=%d, remote_addr=%s", __func__, transport,
                   remote_addr->ToString().c_str());

  /* Set the mask extension */
  tBTA_SERVICE_MASK_EXT mask_ext;
  mask_ext.num_uuid = 0;
  mask_ext.p_uuid = NULL;
  mask_ext.srvc_mask = BTA_ALL_SERVICE_MASK;

  /* if the device supports ADV Audio then register different service discovery
   * callback and try to avoid legacy path.
   */
#ifdef ADV_AUDIO_FEATURE
  if ((is_remote_support_adv_audio(*remote_addr))
    || bta_remote_dev_identity_addr_match(*remote_addr)) {
    BTIF_TRACE_EVENT("%s: transport=%d, Adv Audio", __func__, transport);
    BTA_DmDiscoverByTransport(*remote_addr, &mask_ext,
      bte_dm_adv_audio_search_services_evt, true, transport);
  } else {
    BTA_DmDiscoverByTransport(*remote_addr, &mask_ext, bte_dm_search_services_evt,
                            true, transport);
  }
#else
  BTA_DmDiscoverByTransport(*remote_addr, &mask_ext, bte_dm_search_services_evt,
                           true, transport);
#endif
  return BT_STATUS_SUCCESS;
}

/*******************************************************************************
 *
 * Function         btif_dm_get_remote_service_record
 *
 * Description      Start SDP to get remote service record
 *
 *
 * Returns          bt_status_t
 ******************************************************************************/
bt_status_t btif_dm_get_remote_service_record(const RawAddress& remote_addr,
                                              const Uuid& uuid) {
  BTIF_TRACE_EVENT("%s: bd_addr=%s", __func__, remote_addr.ToString().c_str());
  BTA_DmDiscoverUUID(remote_addr, uuid, bte_dm_remote_service_record_evt, true);

  return BT_STATUS_SUCCESS;
}

void btif_dm_execute_service_request(uint16_t event, char* p_param) {
  bool b_enable = false;
  bt_status_t status;
  if (event == BTIF_DM_ENABLE_SERVICE) {
    b_enable = true;
  }
  status =
      btif_in_execute_service_request(*((tBTA_SERVICE_ID*)p_param), b_enable);
  if (status == BT_STATUS_SUCCESS) {
    bt_property_t property;
    Uuid local_uuids[BT_MAX_NUM_UUIDS];

    /* Now send the UUID_PROPERTY_CHANGED event to the upper layer */
    BTIF_STORAGE_FILL_PROPERTY(&property, BT_PROPERTY_UUIDS,
                               sizeof(local_uuids), local_uuids);
    btif_storage_get_adapter_property(&property);
    HAL_CBACK(bt_hal_cbacks, adapter_properties_cb, BT_STATUS_SUCCESS, 1,
              &property);
  }
  return;
}

void btif_dm_proc_io_req(UNUSED_ATTR const RawAddress& bd_addr,
                         UNUSED_ATTR tBTA_IO_CAP* p_io_cap,
                         UNUSED_ATTR tBTA_OOB_DATA* p_oob_data,
                         tBTA_AUTH_REQ* p_auth_req, bool is_orig) {
  uint8_t yes_no_bit = BTA_AUTH_SP_YES & *p_auth_req;
  /* if local initiated:
  **      1. set DD + MITM
  ** if remote initiated:
  **      1. Copy over the auth_req from peer's io_rsp
  **      2. Set the MITM if peer has it set or if peer has DisplayYesNo
  *(iPhone)
  ** as a fallback set MITM+GB if peer had MITM set
  */

  BTIF_TRACE_DEBUG("+%s: p_auth_req=%d", __func__, *p_auth_req);
  if (pairing_cb.is_local_initiated) {
    /* if initing/responding to a dedicated bonding, use dedicate bonding bit */
    *p_auth_req = BTA_AUTH_DD_BOND | BTA_AUTH_SP_YES;
  } else if (!is_orig) {
    /* peer initiated paring. They probably know what they want.
    ** Copy the mitm from peer device.
    */
    BTIF_TRACE_DEBUG("%s: setting p_auth_req to peer's: %d", __func__,
                     pairing_cb.auth_req);
    *p_auth_req = (pairing_cb.auth_req & BTA_AUTH_BONDS);

    /* copy over the MITM bit as well. In addition if the peer has DisplayYesNo,
     * force MITM */
    if ((yes_no_bit) || (pairing_cb.io_cap & BTM_IO_CAP_IO))
      *p_auth_req |= BTA_AUTH_SP_YES;
  } else if (yes_no_bit) {
    /* set the general bonding bit for stored device */
    *p_auth_req = BTA_AUTH_GEN_BOND | yes_no_bit;
  }
  BTIF_TRACE_DEBUG("-%s: p_auth_req=%d", __func__, *p_auth_req);
}

void btif_dm_proc_io_rsp(UNUSED_ATTR const RawAddress& bd_addr,
                         tBTA_IO_CAP io_cap, UNUSED_ATTR tBTA_OOB_DATA oob_data,
                         tBTA_AUTH_REQ auth_req) {
  if (auth_req & BTA_AUTH_BONDS) {
    BTIF_TRACE_DEBUG("%s auth_req:%d", __func__, auth_req);
    pairing_cb.auth_req = auth_req;
    pairing_cb.io_cap = io_cap;
  }
}

void btif_dm_set_oob_for_io_req(tBTA_OOB_DATA* p_has_oob_data) {
  if (is_empty_128bit(oob_cb.p192_data.c)) {
    *p_has_oob_data = false;
  } else {
    *p_has_oob_data = true;
  }
  BTIF_TRACE_DEBUG("%s: *p_has_oob_data=%d", __func__, *p_has_oob_data);
}

void btif_dm_set_oob_for_le_io_req(const RawAddress& bd_addr,
                                   tBTM_OOB_DATA* p_has_oob_data,
                                   tBTM_LE_AUTH_REQ* p_auth_req) {
  switch (oob_cb.data_present) {
    case BTM_OOB_PRESENT_192_AND_256:
      LOG_INFO(LOG_TAG, "Have both P192 and  P256");
      [[fallthrough]];
    // Always prefer 256 for LE
    case BTM_OOB_PRESENT_256:
      LOG_INFO(LOG_TAG, "Using P256");
      if (!is_empty_128bit(oob_cb.p256_data.c) &&
          !is_empty_128bit(oob_cb.p256_data.r)) {
        /* make sure OOB data is for this particular device */
        if (bd_addr == oob_cb.bdaddr) {
          *p_auth_req = ((*p_auth_req) | BTM_LE_AUTH_REQ_SC_ONLY);
          *p_has_oob_data = true;
        } else {
          *p_has_oob_data = false;
          LOG_WARN(LOG_TAG, "P256-1: Remote address didn't match OOB data address");
        }
      } else if (!is_empty_128bit(oob_cb.p256_data.sm_tk)) {
        /* We have security manager TK */

        /* make sure OOB data is for this particular device */
        if (bd_addr == oob_cb.bdaddr) {
          // When using OOB with TK, SC Secure Connections bit must be disabled.
          tBTM_LE_AUTH_REQ mask = ~BTM_LE_AUTH_REQ_SC_ONLY;
          *p_auth_req = ((*p_auth_req) & mask);
          *p_has_oob_data = true;
        } else {
          *p_has_oob_data = false;
          LOG_WARN(LOG_TAG, "P256-2: Remote address didn't match OOB data address");
        }
      } else {
        *p_has_oob_data = false;
      }
      break;
    case BTM_OOB_PRESENT_192:
      LOG_INFO(LOG_TAG, "Using P192");
      if (!is_empty_128bit(oob_cb.p192_data.c) &&
          !is_empty_128bit(oob_cb.p192_data.r)) {
        /* make sure OOB data is for this particular device */
        if (bd_addr == oob_cb.bdaddr) {
          *p_auth_req = ((*p_auth_req) | BTM_LE_AUTH_REQ_SC_ONLY);
          *p_has_oob_data = true;
        } else {
          *p_has_oob_data = false;
          LOG_WARN(LOG_TAG, "P192-1: Remote address didn't match OOB data address");
        }
      } else if (!is_empty_128bit(oob_cb.p192_data.sm_tk)) {
        /* We have security manager TK */

        /* make sure OOB data is for this particular device */
        if (bd_addr == oob_cb.bdaddr) {
          // When using OOB with TK, SC Secure Connections bit must be disabled.
          tBTM_LE_AUTH_REQ mask = ~BTM_LE_AUTH_REQ_SC_ONLY;
          *p_auth_req = ((*p_auth_req) & mask);
          *p_has_oob_data = true;
        } else {
          *p_has_oob_data = false;
          LOG_WARN(LOG_TAG, "P192-2: Remote address didn't match OOB data address");
        }
      } else {
        *p_has_oob_data = false;
      }
      break;
  }
  BTIF_TRACE_DEBUG("%s *p_has_oob_data=%d", __func__, *p_has_oob_data);
}

#ifdef BTIF_DM_OOB_TEST
void btif_dm_load_local_oob(void) {
  char prop_oob[PROPERTY_VALUE_MAX];
  osi_property_get("service.brcm.bt.oob", prop_oob, "3");
  BTIF_TRACE_DEBUG("%s: prop_oob = %s", __func__, prop_oob);
  if (prop_oob[0] != '3') {
    if (is_empty_128bit(oob_cb.p192_data.c)) {
      BTIF_TRACE_DEBUG("%s: read OOB, call BTA_DmLocalOob()", __func__);
      BTA_DmLocalOob();
    }
  }
}

static bool waiting_on_oob_advertiser_start = false;
static uint8_t oob_advertiser_id = 0;
static void stop_oob_advertiser() {
  auto advertiser = get_ble_advertiser_instance();
  advertiser->Unregister(oob_advertiser_id);
  oob_advertiser_id = 0;
}

/*******************************************************************************
 *
 * Function         btif_dm_generate_local_oob_data
 *
 * Description      Initiate oob data fetch from controller
 *
 * Parameters       transport; Classic or LE
 *
 ******************************************************************************/
void btif_dm_generate_local_oob_data(tBT_TRANSPORT transport) {
  LOG_DEBUG(LOG_TAG, "Transport %s", bt_transport_text(transport).c_str());
  if (transport == BT_TRANSPORT_BR_EDR) {
    BTM_ReadLocalOobData();
  } else if (transport == BT_TRANSPORT_LE) {
    // Call create data first, so we don't have to hold on to the address for
    // the state machine lifecycle.  Rather, lets create the data, then start
    // advertising then request the address.
    if (!waiting_on_oob_advertiser_start) {
      if (oob_advertiser_id != 0) {
        stop_oob_advertiser();
      }
      waiting_on_oob_advertiser_start = true;
      SMP_CrLocScOobData();
    } else {
      invoke_oob_data_request_cb(transport, false, Octet16{}, Octet16{},
                                 RawAddress{}, 0x00);
    }
  }
}

// Step Four: CallBack from Step Three
static void get_address_callback(tBT_TRANSPORT transport, bool is_valid,
                                 const Octet16& c, const Octet16& r,
                                 uint8_t address_type, RawAddress address) {
  invoke_oob_data_request_cb(transport, is_valid, c, r, address, address_type);
  waiting_on_oob_advertiser_start = false;
}

// Step Three: CallBack from Step Two, advertise and get address
static void start_advertising_callback(uint8_t id, tBT_TRANSPORT transport,
                                       bool is_valid, const Octet16& c,
                                       const Octet16& r, uint8_t status) {
  if (status != 0) {
    LOG_INFO(LOG_TAG, "OOB get advertiser ID failed with status %hhd", status);
    invoke_oob_data_request_cb(transport, false, c, r, RawAddress{}, 0x00);
    SMP_ClearLocScOobData();
    waiting_on_oob_advertiser_start = false;
    oob_advertiser_id = 0;
    return;
  }
  LOG_DEBUG(LOG_TAG, "OOB advertiser with id %hhd", id);
  auto advertiser = get_ble_advertiser_instance();
  advertiser->GetOwnAddress(
      id, base::Bind(&get_address_callback, transport, is_valid, c, r));
}

static void timeout_cb(uint8_t id, uint8_t status) {
  LOG_INFO(LOG_TAG, "OOB advertiser with id %hhd timed out with status %hhd", id,
           status);
  auto advertiser = get_ble_advertiser_instance();
  advertiser->Unregister(id);
  SMP_ClearLocScOobData();
  waiting_on_oob_advertiser_start = false;
  oob_advertiser_id = 0;
}

// Step Two: CallBack from Step One, advertise and get address
static void id_status_callback(tBT_TRANSPORT transport, bool is_valid,
                               const Octet16& c, const Octet16& r, uint8_t id,
                               uint8_t status) {
  if (status != 0) {
    LOG_INFO(LOG_TAG, "OOB get advertiser ID failed with status %hhd", status);
    invoke_oob_data_request_cb(transport, false, c, r, RawAddress{}, 0x00);
    SMP_ClearLocScOobData();
    waiting_on_oob_advertiser_start = false;
    oob_advertiser_id = 0;
    return;
  }

  oob_advertiser_id = id;

  auto advertiser = get_ble_advertiser_instance();
  AdvertiseParameters parameters;
  parameters.advertising_event_properties = 0x0041 /* connectable, tx power */;
  parameters.min_interval = 0xa0;   // 100 ms
  parameters.max_interval = 0x500;  // 800 ms
  parameters.channel_map = 0x7;     // Use all the channels
  parameters.tx_power = 0;          // 0 dBm
  parameters.primary_advertising_phy = 1;
  parameters.secondary_advertising_phy = 2;
  parameters.scan_request_notification_enable = 0;

  std::vector<uint8_t> advertisement{0x02, 0x01 /* Flags */,
                                     0x02 /* Connectable */};
  std::vector<uint8_t> scan_data{};

  advertiser->StartAdvertising(
      id,
      base::Bind(&start_advertising_callback, id, transport, is_valid, c, r),
      parameters, advertisement, scan_data, 3600 /* timeout_s */,
      base::Bind(&timeout_cb, id));
}

// Step One: Start the advertiser
static void start_oob_advertiser(tBT_TRANSPORT transport, bool is_valid,
                                 const Octet16& c, const Octet16& r) {
  auto advertiser = get_ble_advertiser_instance();
  advertiser->RegisterAdvertiser(
      base::Bind(&id_status_callback, transport, is_valid, c, r));
}

void btif_dm_proc_loc_oob(tBT_TRANSPORT transport, bool is_valid,
                          const Octet16& c, const Octet16& r) {
  // is_valid is important for deciding which OobDataCallback function to use
  if (!is_valid) {
    invoke_oob_data_request_cb(transport, false, c, r, RawAddress{}, 0x00);
    waiting_on_oob_advertiser_start = false;
    return;
  }
  // Now that we have the data, lets start advertising and get the address.
  start_oob_advertiser(transport, is_valid, c, r);
}

/*******************************************************************************
 *
 * Function         btif_dm_get_smp_config
 *
 * Description      Retrieve the SMP pairing options from the bt_stack.conf
 *                  file. To provide specific pairing options for the host
 *                  add a node with label "SmpOptions" to the config file
 *                  and assign it a comma separated list of 5 values in the
 *                  format: auth, io, ikey, rkey, ksize, oob
 *                  eg: PTS_SmpOptions=0xD,0x4,0xf,0xf,0x10
 *
 * Parameters:      tBTE_APPL_CFG*: pointer to struct defining pairing options
 *
 * Returns          true if the options were successfully read, else false
 *
 ******************************************************************************/
bool btif_dm_get_smp_config(tBTE_APPL_CFG* p_cfg) {
  if (!stack_config_get_interface()->get_pts_smp_options()) {
    BTIF_TRACE_DEBUG("%s: SMP options not found in configuration", __func__);
    return false;
  }

  char conf[64];
  const char* recv = stack_config_get_interface()->get_pts_smp_options();
  char* pch;
  char* endptr;

  strncpy(conf, recv, 64);
  conf[63] = 0;  // null terminate

  pch = strtok(conf, ",");
  if (pch != NULL)
    p_cfg->ble_auth_req = (uint8_t)strtoul(pch, &endptr, 16);
  else
    return false;

  pch = strtok(NULL, ",");
  if (pch != NULL)
    p_cfg->ble_io_cap = (uint8_t)strtoul(pch, &endptr, 16);
  else
    return false;

  pch = strtok(NULL, ",");
  if (pch != NULL)
    p_cfg->ble_init_key = (uint8_t)strtoul(pch, &endptr, 16);
  else
    return false;

  pch = strtok(NULL, ",");
  if (pch != NULL)
    p_cfg->ble_resp_key = (uint8_t)strtoul(pch, &endptr, 16);
  else
    return false;

  pch = strtok(NULL, ",");
  if (pch != NULL)
    p_cfg->ble_max_key_size = (uint8_t)strtoul(pch, &endptr, 16);
  else
    return false;

  return true;
}

bool btif_dm_proc_rmt_oob(const RawAddress& bd_addr, Octet16* p_c,
                          Octet16* p_r) {
  const char* path_a = "/data/misc/bluedroid/LOCAL/a.key";
  const char* path_b = "/data/misc/bluedroid/LOCAL/b.key";
  const char* path = NULL;
  char prop_oob[PROPERTY_VALUE_MAX];
  osi_property_get("service.brcm.bt.oob", prop_oob, "3");
  BTIF_TRACE_DEBUG("%s: prop_oob = %s", __func__, prop_oob);
  if (prop_oob[0] == '1')
    path = path_b;
  else if (prop_oob[0] == '2')
    path = path_a;
  if (!path) {
    BTIF_TRACE_DEBUG("%s: can't open path!", __func__);
    return false;
  }

  FILE* fp = fopen(path, "rb");
  if (fp == NULL) {
    BTIF_TRACE_DEBUG("%s: failed to read OOB keys from %s", __func__, path);
    return false;
  }

  BTIF_TRACE_DEBUG("%s: read OOB data from %s", __func__, path);
  fread(p_c->data(), 1, OCTET16_LEN, fp);
  fread(p_r->data(), 1, OCTET16_LEN, fp);
  fclose(fp);

  RawAddress bt_bd_addr = bd_addr;
  btif_transfer_context(btif_dm_generic_evt, BTIF_DM_CB_BOND_STATE_BONDING,
                        (char*)&bt_bd_addr, sizeof(RawAddress), NULL);
  return true;
}
#endif /*  BTIF_DM_OOB_TEST */

static void btif_dm_ble_key_notif_evt(tBTA_DM_SP_KEY_NOTIF* p_ssp_key_notif) {
  RawAddress bd_addr;
  bt_bdname_t bd_name;
  uint32_t cod;
  int dev_type;

  BTIF_TRACE_DEBUG("%s", __func__);

  /* Remote name update */
  if (!btif_get_device_type(p_ssp_key_notif->bd_addr, &dev_type)) {
    dev_type = BT_DEVICE_TYPE_BLE;
  }
  btif_dm_update_ble_remote_properties(p_ssp_key_notif->bd_addr,
                                       p_ssp_key_notif->bd_name,
                                       (tBT_DEVICE_TYPE)dev_type);
  bd_addr = p_ssp_key_notif->bd_addr;
  memcpy(bd_name.name, p_ssp_key_notif->bd_name, BD_NAME_LEN);
  bd_name.name[BD_NAME_LEN] = '\0';

  bond_state_changed(BT_STATUS_SUCCESS, bd_addr, BT_BOND_STATE_BONDING);
  pairing_cb.is_ssp = false;
  cod = COD_UNCLASSIFIED;

  HAL_CBACK(bt_hal_cbacks, ssp_request_cb, &bd_addr, &bd_name, cod,
            BT_SSP_VARIANT_PASSKEY_NOTIFICATION, p_ssp_key_notif->passkey);
}

/*******************************************************************************
 *
 * Function         btif_dm_ble_auth_cmpl_evt
 *
 * Description      Executes authentication complete event in btif context
 *
 * Returns          void
 *
 ******************************************************************************/
static void btif_dm_ble_auth_cmpl_evt(tBTA_DM_AUTH_CMPL* p_auth_cmpl) {
  /* Save link key, if not temporary */
  bt_status_t status = BT_STATUS_FAIL;
  bt_bond_state_t state = BT_BOND_STATE_NONE;

  RawAddress bd_addr = p_auth_cmpl->bd_addr;

  /* Clear OOB data */
  memset(&oob_cb, 0, sizeof(oob_cb));

  if ((p_auth_cmpl->success == true) && (p_auth_cmpl->key_present)) {
    /* store keys */
  }
  if (p_auth_cmpl->success) {
    status = BT_STATUS_SUCCESS;
    state = BT_BOND_STATE_BONDED;
    int addr_type;
    RawAddress bdaddr = p_auth_cmpl->bd_addr;
    if (btif_storage_get_remote_addr_type(&bdaddr, &addr_type) !=
        BT_STATUS_SUCCESS)
      btif_storage_set_remote_addr_type(&bdaddr, p_auth_cmpl->addr_type);

    /* Test for temporary bonding */
    if (btm_get_bond_type_dev(p_auth_cmpl->bd_addr) == BOND_TYPE_TEMPORARY) {
      BTIF_TRACE_DEBUG("%s: sending BT_BOND_STATE_NONE for Temp pairing",
                       __func__);
      btif_storage_remove_bonded_device(&bdaddr);
      state = BT_BOND_STATE_NONE;
    } else {
      btif_dm_save_ble_bonding_keys(bdaddr);
#ifdef ADV_AUDIO_FEATURE
      if (bta_remote_device_is_dumo(bd_addr)) {
        APPL_TRACE_DEBUG("%s Storing BLE KEYS Identity Address ", __func__);
        RawAddress id_addr = bta_get_rem_dev_id_addr(bd_addr);
        if ((id_addr != bdaddr) &&
          (id_addr != RawAddress::kEmpty)) {
          APPL_TRACE_DEBUG("%s Storing BLE KEYS FOR ADDRESS %s", __func__,
            id_addr.ToString().c_str());
          btif_dm_save_ble_bonding_keys(id_addr);

          bt_device_type_t dev_type;
          dev_type = (bt_device_type_t)BT_DEVICE_TYPE_DUMO;
          bt_property_t prop;
          BTIF_STORAGE_FILL_PROPERTY(&prop,
                            BT_PROPERTY_TYPE_OF_DEVICE, sizeof(dev_type),
                            &dev_type);
          //TODO .. Move it and Save at the end of the pairing
          bt_status_t ret =
          btif_storage_set_remote_device_property(&id_addr, &prop);
          ASSERTC(ret == BT_STATUS_SUCCESS, "failed to save remote device type",
            ret);
        }
      }
#endif
      if (!p_auth_cmpl->smp_over_br) {
         btif_dm_get_remote_services_by_transport(&bd_addr, GATT_TRANSPORT_LE);
      } else {
         btif_dm_get_remote_services(bd_addr);
      }
    }
  } else {
    /*Map the HCI fail reason  to  bt status  */
    switch (p_auth_cmpl->fail_reason) {
      case BTA_DM_AUTH_SMP_PAIR_AUTH_FAIL:
      case BTA_DM_AUTH_SMP_CONFIRM_VALUE_FAIL:
      case BTA_DM_AUTH_SMP_UNKNOWN_ERR:
        btif_dm_remove_ble_bonding_keys();
        status = BT_STATUS_AUTH_FAILURE;
        break;

      case BTA_DM_AUTH_SMP_CONN_TOUT: {
        if (btm_sec_is_a_bonded_dev(bd_addr)) {
          uint8_t dev_type;
          uint8_t addr_type;
          BTM_ReadDevInfo(bd_addr, &dev_type, &addr_type);

          if ((pairing_cb.state == BT_BOND_STATE_BONDING) &&
            (dev_type == BT_DEVICE_TYPE_DUMO) &&
            (addr_type == BLE_ADDR_PUBLIC) &&
            !btm_sec_is_a_bonded_dev_by_transport(bd_addr, BT_TRANSPORT_LE)) {
            btif_storage_remove_bonded_device(&bd_addr);
            status = BT_STATUS_AUTH_FAILURE;
            break;
          } else {
            LOG(INFO) << __func__ << " Bonded device addr=" << bd_addr
                    << " timed out - will not remove the keys";
            // Don't send state change to upper layers - otherwise Java think we
            // unbonded, and will disconnect HID profile.
            return;
          }
        }

        btif_dm_remove_ble_bonding_keys();
        status = BT_STATUS_AUTH_FAILURE;
        break;
      }
      case BTA_DM_AUTH_SMP_PAIR_NOT_SUPPORT:
        status = BT_STATUS_AUTH_REJECTED;
        break;
      default:
        btif_dm_remove_ble_bonding_keys();
        status = BT_STATUS_FAIL;
        break;
    }
  }
  if (state == BT_BOND_STATE_BONDED && bd_addr != pairing_cb.static_bdaddr) {
    // Report RPA bonding state to Java in crosskey paring
    bond_state_changed(status, bd_addr, BT_BOND_STATE_BONDING);
  }
  bond_state_changed(status, bd_addr, state);
}

void btif_dm_load_ble_local_keys(void) {
  memset(&ble_local_key_cb, 0, sizeof(btif_dm_local_key_cb_t));

  if (btif_storage_get_ble_local_key(
          BTIF_DM_LE_LOCAL_KEY_ER, &ble_local_key_cb.er) == BT_STATUS_SUCCESS) {
    ble_local_key_cb.is_er_rcvd = true;
    BTIF_TRACE_DEBUG("%s BLE ER key loaded", __func__);
  }

  if ((btif_storage_get_ble_local_key(BTIF_DM_LE_LOCAL_KEY_IR,
                                      &ble_local_key_cb.id_keys.ir) ==
       BT_STATUS_SUCCESS) &&
      (btif_storage_get_ble_local_key(BTIF_DM_LE_LOCAL_KEY_IRK,
                                      &ble_local_key_cb.id_keys.irk) ==
       BT_STATUS_SUCCESS) &&
      (btif_storage_get_ble_local_key(BTIF_DM_LE_LOCAL_KEY_DHK,
                                      &ble_local_key_cb.id_keys.dhk) ==
       BT_STATUS_SUCCESS)) {
    ble_local_key_cb.is_id_keys_rcvd = true;
    BTIF_TRACE_DEBUG("%s BLE ID keys loaded", __func__);
  }
}
void btif_dm_get_ble_local_keys(tBTA_DM_BLE_LOCAL_KEY_MASK* p_key_mask,
                                Octet16* p_er,
                                tBTA_BLE_LOCAL_ID_KEYS* p_id_keys) {
  if (ble_local_key_cb.is_er_rcvd) {
    *p_er = ble_local_key_cb.er;
    *p_key_mask |= BTA_BLE_LOCAL_KEY_TYPE_ER;
  }

  if (ble_local_key_cb.is_id_keys_rcvd) {
    p_id_keys->ir = ble_local_key_cb.id_keys.ir;
    p_id_keys->irk = ble_local_key_cb.id_keys.irk;
    p_id_keys->dhk = ble_local_key_cb.id_keys.dhk;
    *p_key_mask |= BTA_BLE_LOCAL_KEY_TYPE_ID;
  }
  BTIF_TRACE_DEBUG("%s  *p_key_mask=0x%02x", __func__, *p_key_mask);
}

void btif_dm_save_ble_bonding_keys(RawAddress& bd_addr) {
  BTIF_TRACE_DEBUG("%s", __func__);

  if (pairing_cb.ble.is_penc_key_rcvd) {
    btif_storage_add_ble_bonding_key(
        &bd_addr, (uint8_t*)&pairing_cb.ble.penc_key, BTIF_DM_LE_KEY_PENC,
        sizeof(tBTM_LE_PENC_KEYS));
  }

  if (pairing_cb.ble.is_pid_key_rcvd) {
    btif_storage_add_ble_bonding_key(
        &bd_addr, (uint8_t*)&pairing_cb.ble.pid_key, BTIF_DM_LE_KEY_PID,
        sizeof(tBTM_LE_PID_KEYS));
  }

  if (pairing_cb.ble.is_pcsrk_key_rcvd) {
    btif_storage_add_ble_bonding_key(
        &bd_addr, (uint8_t*)&pairing_cb.ble.pcsrk_key, BTIF_DM_LE_KEY_PCSRK,
        sizeof(tBTM_LE_PCSRK_KEYS));
  }

  if (pairing_cb.ble.is_lenc_key_rcvd) {
    btif_storage_add_ble_bonding_key(
        &bd_addr, (uint8_t*)&pairing_cb.ble.lenc_key, BTIF_DM_LE_KEY_LENC,
        sizeof(tBTM_LE_LENC_KEYS));
  }

  if (pairing_cb.ble.is_lcsrk_key_rcvd) {
    btif_storage_add_ble_bonding_key(
        &bd_addr, (uint8_t*)&pairing_cb.ble.lcsrk_key, BTIF_DM_LE_KEY_LCSRK,
        sizeof(tBTM_LE_LCSRK_KEYS));
  }

  if (pairing_cb.ble.is_lidk_key_rcvd) {
    btif_storage_add_ble_bonding_key(&bd_addr, NULL, BTIF_DM_LE_KEY_LID, 0);
  }
}

void btif_dm_remove_ble_bonding_keys(void) {
  BTIF_TRACE_DEBUG("%s", __func__);

  RawAddress bd_addr = pairing_cb.bd_addr;
  btif_storage_remove_ble_bonding_keys(&bd_addr);
}

/*******************************************************************************
 *
 * Function         btif_dm_ble_sec_req_evt
 *
 * Description      Eprocess security request event in btif context
 *
 * Returns          void
 *
 ******************************************************************************/
void btif_dm_ble_sec_req_evt(tBTA_DM_BLE_SEC_REQ* p_ble_req, bool is_consent) {
  bt_bdname_t bd_name;
  uint32_t cod;
  int dev_type;

  BTIF_TRACE_DEBUG("%s", __func__);

  if (!is_consent && pairing_cb.state == BT_BOND_STATE_BONDING) {
    BTIF_TRACE_DEBUG("%s Discard security request", __func__);
    return;
  }

  /* Remote name update */
  if (!btif_get_device_type(p_ble_req->bd_addr, &dev_type)) {
    dev_type = BT_DEVICE_TYPE_BLE;
  }
  btif_dm_update_ble_remote_properties(p_ble_req->bd_addr, p_ble_req->bd_name,
                                       (tBT_DEVICE_TYPE)dev_type);

  RawAddress bd_addr = p_ble_req->bd_addr;
  memcpy(bd_name.name, p_ble_req->bd_name, BD_NAME_LEN);
  bd_name.name[BD_NAME_LEN] = '\0';

  bond_state_changed(BT_STATUS_SUCCESS, bd_addr, BT_BOND_STATE_BONDING);

  pairing_cb.bond_type = BOND_TYPE_PERSISTENT;
  pairing_cb.is_le_only = true;
  pairing_cb.is_le_nc = false;
  pairing_cb.is_ssp = true;
  btm_set_bond_type_dev(p_ble_req->bd_addr, pairing_cb.bond_type);

  cod = COD_UNCLASSIFIED;

  HAL_CBACK(bt_hal_cbacks, ssp_request_cb, &bd_addr, &bd_name, cod,
            BT_SSP_VARIANT_CONSENT, 0);
}

/*******************************************************************************
 *
 * Function         btif_dm_ble_passkey_req_evt
 *
 * Description      Executes pin request event in btif context
 *
 * Returns          void
 *
 ******************************************************************************/
static void btif_dm_ble_passkey_req_evt(tBTA_DM_PIN_REQ* p_pin_req) {
  bt_bdname_t bd_name;
  uint32_t cod;
  int dev_type;

  /* Remote name update */
  if (!btif_get_device_type(p_pin_req->bd_addr, &dev_type)) {
    dev_type = BT_DEVICE_TYPE_BLE;
  }
  btif_dm_update_ble_remote_properties(p_pin_req->bd_addr, p_pin_req->bd_name,
                                       (tBT_DEVICE_TYPE)dev_type);

  RawAddress bd_addr = p_pin_req->bd_addr;
  memcpy(bd_name.name, p_pin_req->bd_name, BD_NAME_LEN);
  bd_name.name[BD_NAME_LEN] = '\0';

  bond_state_changed(BT_STATUS_SUCCESS, bd_addr, BT_BOND_STATE_BONDING);
  pairing_cb.is_le_only = true;

  cod = COD_UNCLASSIFIED;

  HAL_CBACK(bt_hal_cbacks, pin_request_cb, &bd_addr, &bd_name, cod, false);
}
static void btif_dm_ble_key_nc_req_evt(tBTA_DM_SP_KEY_NOTIF* p_notif_req) {
  /* TODO implement key notification for numeric comparison */
  BTIF_TRACE_DEBUG("%s", __func__);

  /* Remote name update */
  btif_update_remote_properties(p_notif_req->bd_addr, p_notif_req->bd_name,
                                NULL, BT_DEVICE_TYPE_BLE);

  RawAddress bd_addr = p_notif_req->bd_addr;

  bt_bdname_t bd_name;
  memcpy(bd_name.name, p_notif_req->bd_name, BD_NAME_LEN);
  bd_name.name[BD_NAME_LEN] = '\0';

  bond_state_changed(BT_STATUS_SUCCESS, bd_addr, BT_BOND_STATE_BONDING);
  pairing_cb.is_ssp = false;
  pairing_cb.is_le_only = true;
  pairing_cb.is_le_nc = true;

  HAL_CBACK(bt_hal_cbacks, ssp_request_cb, &bd_addr, &bd_name, COD_UNCLASSIFIED,
            BT_SSP_VARIANT_PASSKEY_CONFIRMATION, p_notif_req->passkey);
}

static void btif_dm_ble_oob_req_evt(tBTA_DM_SP_RMT_OOB* req_oob_type) {
  BTIF_TRACE_DEBUG("%s", __func__);

  RawAddress bd_addr = req_oob_type->bd_addr;
  /* We already checked if OOB data is present in
   * btif_dm_set_oob_for_le_io_req, but check here again. If it's not present
   * do nothing, pairing will timeout.
   */
  if (is_empty_128bit(oob_cb.p192_data.sm_tk)) {
    return;
  }

  /* make sure OOB data is for this particular device */
  if (req_oob_type->bd_addr != oob_cb.bdaddr) {
    BTIF_TRACE_WARNING("%s: remote address didn't match OOB data address",
                       __func__);
    return;
  }

  /* Remote name update */
  btif_update_remote_properties(req_oob_type->bd_addr, req_oob_type->bd_name,
                                NULL, BT_DEVICE_TYPE_BLE);

  bond_state_changed(BT_STATUS_SUCCESS, bd_addr, BT_BOND_STATE_BONDING);
  pairing_cb.is_ssp = false;
  pairing_cb.is_le_only = true;
  pairing_cb.is_le_nc = false;

  BTM_BleOobDataReply(req_oob_type->bd_addr, 0, 16, oob_cb.p192_data.sm_tk);
}

static void btif_dm_ble_sc_oob_req_evt(tBTA_DM_SP_RMT_OOB* req_oob_type) {
  BTIF_TRACE_DEBUG("%s", __func__);

  RawAddress bd_addr = req_oob_type->bd_addr;
  BTIF_TRACE_DEBUG("%s: bd_addr: %s", __func__, bd_addr.ToString().c_str());
  BTIF_TRACE_DEBUG("%s: oob_cb.bdaddr: %s", __func__,
                   oob_cb.bdaddr.ToString().c_str());

  /* make sure OOB data is for this particular device */
  if (req_oob_type->bd_addr != oob_cb.bdaddr) {
    LOG_ERROR(LOG_TAG, "remote address didn't match OOB data address");
    return;
  }

  /* We already checked if OOB data is present in
   * btif_dm_set_oob_for_le_io_req, but check here again. If it's not present
   * do nothing, pairing will timeout.
   */
  bt_oob_data_t oob_data_to_use = {};
  switch (oob_cb.data_present) {
    case BTM_OOB_PRESENT_192_AND_256:
      LOG_INFO(LOG_TAG, "Have both P192 and  P256");
      [[fallthrough]];
    // Always prefer 256 for LE
    case BTM_OOB_PRESENT_256:
      LOG_INFO(LOG_TAG, "Using P256");
      if (is_empty_128bit(oob_cb.p256_data.c) &&
          is_empty_128bit(oob_cb.p256_data.r)) {
        LOG_WARN(LOG_TAG, "P256 LE SC OOB data is empty");
        return;
      }
      oob_data_to_use = oob_cb.p256_data;
      break;
    case BTM_OOB_PRESENT_192:
      LOG_INFO(LOG_TAG, "Using P192");
      if (is_empty_128bit(oob_cb.p192_data.c) &&
          is_empty_128bit(oob_cb.p192_data.r)) {
        LOG_WARN(LOG_TAG, "P192 LE SC OOB data is empty");
        return;
      }
      oob_data_to_use = oob_cb.p192_data;
      break;
  }

  /* Remote name update */
  btif_update_remote_properties(req_oob_type->bd_addr,
                                oob_data_to_use.device_name, NULL,
                                BT_DEVICE_TYPE_BLE);

  bond_state_changed(BT_STATUS_SUCCESS, bd_addr, BT_BOND_STATE_BONDING);
  pairing_cb.is_ssp = false;
  // TODO: we can derive classic pairing from this one
  pairing_cb.is_le_only = true;
  pairing_cb.is_le_nc = false;
  BTM_BleSecureConnectionOobDataReply(req_oob_type->bd_addr, oob_data_to_use.c,
                                      oob_data_to_use.r);
}

void btif_dm_update_ble_remote_properties(const RawAddress& bd_addr,
                                          BD_NAME bd_name,
                                          tBT_DEVICE_TYPE dev_type) {
  btif_update_remote_properties(bd_addr, bd_name, NULL, dev_type);
}

static void btif_dm_ble_tx_test_cback(void* p) {
  btif_transfer_context(btif_dm_generic_evt, BTIF_DM_CB_LE_TX_TEST, (char*)p, 1,
                        NULL);
}

static void btif_dm_ble_rx_test_cback(void* p) {
  btif_transfer_context(btif_dm_generic_evt, BTIF_DM_CB_LE_RX_TEST, (char*)p, 1,
                        NULL);
}

static void btif_dm_ble_test_end_cback(void* p) {
  btif_transfer_context(btif_dm_generic_evt, BTIF_DM_CB_LE_TEST_END, (char*)p,
                        3, NULL);
}
/*******************************************************************************
 *
 * Function         btif_le_test_mode
 *
 * Description     Sends a HCI BLE Test command to the Controller
 *
 * Returns          BT_STATUS_SUCCESS on success
 *
 ******************************************************************************/
bt_status_t btif_le_test_mode(uint16_t opcode, uint8_t* buf, uint8_t len) {
  switch (opcode) {
    case HCI_BLE_TRANSMITTER_TEST:
      if (len != 3) return BT_STATUS_PARM_INVALID;
      BTM_BleTransmitterTest(buf[0], buf[1], buf[2], btif_dm_ble_tx_test_cback);
      break;
    case HCI_BLE_RECEIVER_TEST:
      if (len != 1) return BT_STATUS_PARM_INVALID;
      BTM_BleReceiverTest(buf[0], btif_dm_ble_rx_test_cback);
      break;
    case HCI_BLE_TEST_END:
      BTM_BleTestEnd(btif_dm_ble_test_end_cback);
      break;
    default:
      BTIF_TRACE_ERROR("%s: Unknown LE Test Mode Command 0x%x", __func__,
                       opcode);
      return BT_STATUS_UNSUPPORTED;
  }
  return BT_STATUS_SUCCESS;
}

void btif_dm_on_disable() {
  /* Cleanup static variables.*/
  num_active_br_edr_links = 0;
  num_active_le_links = 0;

  /* cancel any pending pairing requests */
  if (is_bonding_or_sdp()) {
    BTIF_TRACE_DEBUG("%s: Cancel pending pairing request", __func__);
    btif_dm_cancel_bond(&pairing_cb.bd_addr);
  }
}

void btif_dm_bredr_disable() {
  /* Cleanup static variables.*/
  num_active_br_edr_links = 0;

  /* cancel any pending pairing requests */
  if (pairing_cb.state == BT_BOND_STATE_BONDING) {
    BTIF_TRACE_DEBUG("%s: Cancel pending pairing request", __func__);
    btif_dm_cancel_bond(&pairing_cb.bd_addr);
  }
}
/*******************************************************************************
 *
 * Function         btif_dm_read_energy_info
 *
 * Description     Reads the energy info from controller
 *
 * Returns         void
 *
 ******************************************************************************/
void btif_dm_read_energy_info() { BTA_DmBleGetEnergyInfo(bta_energy_info_cb); }

static char* btif_get_default_local_name() {
  if (btif_default_local_name[0] == '\0') {
    int max_len = sizeof(btif_default_local_name) - 1;
    if (BTM_DEF_LOCAL_NAME[0] != '\0') {
      strncpy(btif_default_local_name, BTM_DEF_LOCAL_NAME, max_len);
    } else {
      char prop_model[PROPERTY_VALUE_MAX];
      osi_property_get(PROPERTY_PRODUCT_MODEL, prop_model, "");
      strncpy(btif_default_local_name, prop_model, max_len);
    }
    btif_default_local_name[max_len] = '\0';
  }
  return btif_default_local_name;
}

__attribute__((no_sanitize("integer")))
static void btif_stats_add_bond_event(const RawAddress& bd_addr,
                                      bt_bond_function_t function,
                                      bt_bond_state_t state) {
  std::unique_lock<std::mutex> lock(bond_event_lock);

  btif_bond_event_t* event = &btif_dm_bond_events[btif_events_end_index];
  event->bd_addr = bd_addr;
  event->function = function;
  event->state = state;
  clock_gettime(CLOCK_REALTIME, &event->timestamp);

  btif_num_bond_events++;
  btif_events_end_index =
      (btif_events_end_index + 1) % (MAX_BTIF_BOND_EVENT_ENTRIES + 1);
  if (btif_events_end_index == btif_events_start_index) {
    btif_events_start_index =
        (btif_events_start_index + 1) % (MAX_BTIF_BOND_EVENT_ENTRIES + 1);
  }

  int type;
  btif_get_device_type(bd_addr, &type);

  system_bt_osi::device_type_t device_type;
  switch (type) {
    case BT_DEVICE_TYPE_BREDR:
      device_type = system_bt_osi::DEVICE_TYPE_BREDR;
      break;
    case BT_DEVICE_TYPE_BLE:
      device_type = system_bt_osi::DEVICE_TYPE_LE;
      break;
    case BT_DEVICE_TYPE_DUMO:
      device_type = system_bt_osi::DEVICE_TYPE_DUMO;
      break;
    default:
      device_type = system_bt_osi::DEVICE_TYPE_UNKNOWN;
      break;
  }

  uint32_t cod = get_cod(&bd_addr);
  uint64_t ts =
      event->timestamp.tv_sec * 1000 + event->timestamp.tv_nsec / 1000000;
  system_bt_osi::BluetoothMetricsLogger::GetInstance()->LogPairEvent(
      0, ts, cod, device_type);
}

void btif_debug_bond_event_dump(int fd) {
  std::unique_lock<std::mutex> lock(bond_event_lock);
  dprintf(fd, "\nBond Events: \n");
  dprintf(fd, "  Total Number of events: %zu\n", btif_num_bond_events);
  if (btif_num_bond_events > 0)
    dprintf(fd,
            "  Time          address            Function             State\n");

  for (size_t i = btif_events_start_index; i != btif_events_end_index;
       i = (i + 1) % (MAX_BTIF_BOND_EVENT_ENTRIES + 1)) {
    btif_bond_event_t* event = &btif_dm_bond_events[i];

    char eventtime[20];
    char temptime[20] = {0};
    struct tm* tstamp = localtime(&event->timestamp.tv_sec);
    if (tstamp) {
      if (strftime(temptime, sizeof(temptime), "%H:%M:%S", tstamp)) {
        snprintf(eventtime, sizeof(eventtime), "%s.%03ld", temptime,
                event->timestamp.tv_nsec / 1000000);
      }
    }

    const char* func_name;
    switch (event->function) {
      case BTIF_DM_FUNC_CREATE_BOND:
        func_name = "btif_dm_create_bond";
        break;
      case BTIF_DM_FUNC_REMOVE_BOND:
        func_name = "btif_dm_remove_bond";
        break;
      case BTIF_DM_FUNC_BOND_STATE_CHANGED:
        func_name = "bond_state_changed ";
        break;
      default:
        func_name = "Invalid value      ";
        break;
    }

    const char* bond_state;
    switch (event->state) {
      case BT_BOND_STATE_NONE:
        bond_state = "BOND_STATE_NONE";
        break;
      case BT_BOND_STATE_BONDING:
        bond_state = "BOND_STATE_BONDING";
        break;
      case BT_BOND_STATE_BONDED:
        bond_state = "BOND_STATE_BONDED";
        break;
      default:
        bond_state = "Invalid bond state";
        break;
    }

    dprintf(fd, "  %s  %s  %s  %s\n", eventtime,
            event->bd_addr.ToString().c_str(), func_name, bond_state);
  }
}

/*******************************************************************************
 *
 * Function        btif_dm_get_br_edr_links.
 *
 * Description     Returns number of active BR/EDR links.
 *
 * Returns         UINT16
 *
 ******************************************************************************/
uint16_t btif_dm_get_br_edr_links() {
    BTIF_TRACE_DEBUG("BR/EDR Link count: %d", num_active_br_edr_links);
    return num_active_br_edr_links;
}

/*******************************************************************************
 *
 * Function        btif_dm_get_le_links.
 *
 * Description     Returns number of active  LE links.
 *
 * Returns         UINT16
 *
 ******************************************************************************/
uint16_t btif_dm_get_le_links() {
    BTIF_TRACE_DEBUG("LE Link count: %d", num_active_le_links);
    return num_active_le_links;
}

/*******************************************************************************
 *
 * Function        btif_get_pairing_cb_info
 *
 * Description     Gets pairing control block information
 *
 * Returns         void
 *
 ******************************************************************************/
void btif_get_pairing_cb_info(bt_bond_state_t* state, uint8_t* sdp_attempts,
                             RawAddress* bd_addr, RawAddress* static_bdaddr) {
  *state = pairing_cb.state;
  *bd_addr = pairing_cb.bd_addr;
  *sdp_attempts = pairing_cb.sdp_attempts;
  *static_bdaddr= pairing_cb.static_bdaddr;
}

/*******************************************************************************
 *
 * Function        btif_inc_sdp_attempts
 *
 * Description     increments sdp attempts during pairing time
 *
 * Returns         void
 *
 ******************************************************************************/
void btif_inc_sdp_attempts() {
  pairing_cb.sdp_attempts++;
}

/*******************************************************************************
 *
 * Function        btif_reset_pairing_cb
 *
 * Description     resets the pairing control block
 *
 * Returns         void
 *
 ******************************************************************************/
void btif_reset_pairing_cb() {
  pairing_cb = {};
}

/*******************************************************************************
 *
 * Function        btif_reset_sdp_attempts
 *
 * Description     resets the sdp discovery attempts during pairing
 *
 * Returns         void
 *
 ******************************************************************************/
void btif_reset_sdp_attempts() {
  pairing_cb.sdp_attempts = 0;
}

#ifdef ADV_AUDIO_FEATURE
/*******************************************************************************
 *
 * Function        btif_store_adv_audio_pair_info
 *
 * Description     storing thein conf file that its adv_audio pairing or not
 *
 * Returns         void
 *
 ******************************************************************************/
void btif_store_adv_audio_pair_info(RawAddress bd_addr) {
  bt_property_t prop_dev;
  int dev_is_adv_audio = pairing_cb.is_adv_audio;
  prop_dev.type = (bt_property_type_t) BT_PROPERTY_REM_DEV_IS_ADV_AUDIO;
  prop_dev.val = (void *)&dev_is_adv_audio;
  prop_dev.len = sizeof(int);
  BTIF_TRACE_WARNING("%s dev_is_adv_audio %d BDADDR %s", __func__,
      dev_is_adv_audio, bd_addr.ToString().c_str());
  int ret = btif_storage_set_remote_device_property(&bd_addr, &prop_dev);
  ASSERTC(ret == BT_STATUS_SUCCESS, "failed to save remote device type",
      ret);
}
#endif
