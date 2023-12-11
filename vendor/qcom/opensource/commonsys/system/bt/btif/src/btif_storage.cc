/******************************************************************************
 *
 *  Copyright (c) 2014 The Android Open Source Project
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
 *  Filename:      btif_storage.c
 *
 *  Description:   Stores the local BT adapter and remote device properties in
 *                 NVRAM storage, typically as xml file in the
 *                 mobile's filesystem
 *
 *
 */

#define LOG_TAG "bt_btif_storage"

#include "btif_storage.h"

#include <alloca.h>
#include <base/logging.h>
#include <ctype.h>
#include <log/log.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "bt_common.h"
#include "bta_closure_api.h"
#include "bta_hd_api.h"
#include "bta_hearing_aid_api.h"
#include "bta_hh_api.h"
#include "btif_api.h"
#include "btif_config.h"
#include "btif_hd.h"
#include "btif_hh.h"
#include "btif_util.h"
#include "device/include/controller.h"
#include "osi/include/allocator.h"
#include "osi/include/compat.h"
#include "osi/include/config.h"
#include "osi/include/log.h"
#include "osi/include/osi.h"
#include <inttypes.h>
#include "stack/gatt/gatt_int.h"
#include "stack/gatt/eatt_int.h"

using base::Bind;
using bluetooth::Uuid;

/*******************************************************************************
 *  Constants & Macros
 ******************************************************************************/

// TODO(armansito): Find a better way than using a hardcoded path.
#define BTIF_STORAGE_PATH_BLUEDROID "/data/misc/bluedroid"

//#define BTIF_STORAGE_PATH_ADAPTER_INFO "adapter_info"
//#define BTIF_STORAGE_PATH_REMOTE_DEVICES "remote_devices"
#define BTIF_STORAGE_PATH_REMOTE_DEVTIME "Timestamp"
#define BTIF_STORAGE_PATH_REMOTE_DEVCLASS "DevClass"
#define BTIF_STORAGE_PATH_REMOTE_DEVTYPE "DevType"
#define BTIF_STORAGE_PATH_REMOTE_NAME "Name"
#define BTIF_STORAGE_PATH_REMOTE_VER_MFCT "Manufacturer"
#define BTIF_STORAGE_PATH_REMOTE_VER_VER "LmpVer"
#define BTIF_STORAGE_PATH_REMOTE_VER_SUBVER "LmpSubVer"
#define BTIF_STORAGE_PATH_REMOTE_VALID_ADDR "ValidAddr"
#define BTIF_STORAGE_PATH_REMOTE_MAPPING_ADDR "MapAddr"
#define BTIF_STORAGE_PATH_REMOTE_ADV_AUDIO "IsAdvAudio"

//#define BTIF_STORAGE_PATH_REMOTE_LINKKEYS "remote_linkkeys"
#define BTIF_STORAGE_PATH_REMOTE_ALIASE "Aliase"
#define BTIF_STORAGE_PATH_REMOTE_DGROUP "DGroup"
#define BTIF_STORAGE_PATH_REMOTE_SERVICE "Service"
#define BTIF_STORAGE_PATH_ADV_AUDIO_REMOTE_SERVICE "AdvAudioService"
#define BTIF_STORAGE_PATH_REMOTE_HIDINFO "HidInfo"
#define BTIF_STORAGE_KEY_ADAPTER_NAME "Name"
#define BTIF_STORAGE_KEY_ADAPTER_SCANMODE "ScanMode"
#define BTIF_STORAGE_KEY_LOCAL_IO_CAPS "LocalIOCaps"
#define BTIF_STORAGE_KEY_LOCAL_IO_CAPS_BLE "LocalIOCapsBLE"
#define BTIF_STORAGE_KEY_ADAPTER_DISC_TIMEOUT "DiscoveryTimeout"
#define BTIF_STORAGE_KEY_EATT_SUPPORT "EattSupport"
#define BTIF_STORAGE_KEY_CLIENT_SUPP_FEAT "ClientSupportedFeaturesChar"

/* This is a local property to add a device found */
#define BT_PROPERTY_REMOTE_DEVICE_TIMESTAMP 0xFF

// TODO: This macro should be converted to a function
#define BTIF_STORAGE_GET_ADAPTER_PROP(s, t, v, l, p) \
  do {                                               \
    (p).type = (t);                                  \
    (p).val = (v);                                   \
    (p).len = (l);                                   \
    s = btif_storage_get_adapter_property(&(p));     \
  } while (0)

// TODO: This macro should be converted to a function
#define BTIF_STORAGE_GET_REMOTE_PROP(b, t, v, l, p)     \
  do {                                                  \
    (p).type = (t);                                     \
    (p).val = (v);                                      \
    (p).len = (l);                                      \
    btif_storage_get_remote_device_property((b), &(p)); \
  } while (0)

#define STORAGE_BDADDR_STRING_SZ (18) /* 00:11:22:33:44:55 */
#define STORAGE_UUID_STRING_SIZE \
  (36 + 1) /* 00001200-0000-1000-8000-00805f9b34fb; */
#define STORAGE_PINLEN_STRING_MAX_SIZE (2)  /* ascii pinlen max chars */
#define STORAGE_KEYTYPE_STRING_MAX_SIZE (1) /* ascii keytype max chars */

#define STORAGE_KEY_TYPE_MAX (10)

#define STORAGE_HID_ATRR_MASK_SIZE (4)
#define STORAGE_HID_SUB_CLASS_SIZE (2)
#define STORAGE_HID_APP_ID_SIZE (2)
#define STORAGE_HID_VENDOR_ID_SIZE (4)
#define STORAGE_HID_PRODUCT_ID_SIZE (4)
#define STORAGE_HID_VERSION_SIZE (4)
#define STORAGE_HID_CTRY_CODE_SIZE (2)
#define STORAGE_HID_DESC_LEN_SIZE (4)
#define STORAGE_HID_DESC_MAX_SIZE (2 * 512)

/* <18 char bd addr> <space> LIST< <36 char uuid> <;> > <keytype (dec)> <pinlen>
 */
#define BTIF_REMOTE_SERVICES_ENTRY_SIZE_MAX      \
  (STORAGE_BDADDR_STRING_SZ + 1 +                \
   STORAGE_UUID_STRING_SIZE * BT_MAX_NUM_UUIDS + \
   STORAGE_PINLEN_STRING_MAX_SIZE + STORAGE_KEYTYPE_STRING_MAX_SIZE)

#define STORAGE_REMOTE_LINKKEYS_ENTRY_SIZE (LINK_KEY_LEN * 2 + 1 + 2 + 1 + 2)

/* <18 char bd addr> <space>LIST <attr_mask> <space> > <sub_class> <space>
   <app_id> <space>
                                <vendor_id> <space> > <product_id> <space>
   <version> <space>
                                <ctry_code> <space> > <desc_len> <space>
   <desc_list> <space> */
#define BTIF_HID_INFO_ENTRY_SIZE_MAX                                  \
  (STORAGE_BDADDR_STRING_SZ + 1 + STORAGE_HID_ATRR_MASK_SIZE + 1 +    \
   STORAGE_HID_SUB_CLASS_SIZE + 1 + STORAGE_HID_APP_ID_SIZE + 1 +     \
   STORAGE_HID_VENDOR_ID_SIZE + 1 + STORAGE_HID_PRODUCT_ID_SIZE + 1 + \
   STORAGE_HID_VERSION_SIZE + 1 + STORAGE_HID_CTRY_CODE_SIZE + 1 +    \
   STORAGE_HID_DESC_LEN_SIZE + 1 + STORAGE_HID_DESC_MAX_SIZE + 1)

/* currently remote services is the potentially largest entry */
#define BTIF_STORAGE_MAX_LINE_SZ BTIF_REMOTE_SERVICES_ENTRY_SIZE_MAX

/* check against unv max entry size at compile time */
#if (BTIF_STORAGE_ENTRY_MAX_SIZE > UNV_MAXLINE_LENGTH)
#error "btif storage entry size exceeds unv max line size"
#endif

/*******************************************************************************
 *  External functions
 ******************************************************************************/

extern void btif_gatts_add_bonded_dev_from_nv(const RawAddress& bda);

#ifdef ADV_AUDIO_FEATURE
extern bool is_remote_support_adv_audio(const RawAddress remote_bdaddr);
#endif
/*******************************************************************************
 *  Internal Functions
 ******************************************************************************/

static bt_status_t btif_in_fetch_bonded_ble_device(
    const char* remote_bd_addr, int add,
    list_t** p_bonded_devices);
static bt_status_t btif_in_fetch_bonded_device(const char* bdstr, int *dev_type);

bool btif_has_ble_keys(const char* bdstr);

static bool prop_upd(const RawAddress* remote_bd_addr, bt_property_t *prop);
/*******************************************************************************
 *  Static functions
 ******************************************************************************/
static bool prop_upd(const RawAddress* remote_bd_addr, bt_property_t *prop)
{
  std::string addrstr;
  const char* bdstr = addrstr.c_str();
  int name_length = 0;
  char value[1024];
  bool ret = true;

  if(!prop || prop->len <= 0 || prop->len > (int)sizeof(value) - 1) {
    BTIF_TRACE_ERROR("%s: prop is null or length of prop is invalid", __func__);
    return false;
  }

  if(remote_bd_addr) {
    addrstr = remote_bd_addr->ToString();
    bdstr = addrstr.c_str();
  }

  BTIF_TRACE_DEBUG("%s: in, bd addr:%s, prop type:%d, len:%d", __func__, bdstr, prop->type,
              prop->len);

  switch((uint8_t)prop->type) {
    case BT_PROPERTY_REMOTE_DEVICE_TIMESTAMP:
      btif_config_set_int(bdstr, BTIF_STORAGE_PATH_REMOTE_DEVTIME,
                  (int)time(NULL));
      break;
    case BT_PROPERTY_BDNAME:
      name_length = prop->len > BTM_MAX_LOC_BD_NAME_LEN ? BTM_MAX_LOC_BD_NAME_LEN:
          prop->len;
      strlcpy(value, (char*)prop->val, name_length + 1);
      if (remote_bd_addr)
        btif_config_set_str(bdstr, BTIF_STORAGE_PATH_REMOTE_NAME, value);
      else {
        btif_config_set_str("Adapter", BTIF_STORAGE_KEY_ADAPTER_NAME, value);
        btif_config_flush();
      }
      break;
    case BT_PROPERTY_REMOTE_FRIENDLY_NAME:
      strlcpy(value, (char*)prop->val, prop->len + 1);
      btif_config_set_str(bdstr, BTIF_STORAGE_PATH_REMOTE_ALIASE, value);
      break;
    case BT_PROPERTY_ADAPTER_SCAN_MODE:
      btif_config_set_int("Adapter", BTIF_STORAGE_KEY_ADAPTER_SCANMODE,
                  *(int*)prop->val);
      break;
    case BT_PROPERTY_LOCAL_IO_CAPS:
      btif_config_set_int("Adapter", BTIF_STORAGE_KEY_LOCAL_IO_CAPS,
                          *(int*)prop->val);
      break;
    case BT_PROPERTY_LOCAL_IO_CAPS_BLE:
      btif_config_set_int("Adapter", BTIF_STORAGE_KEY_LOCAL_IO_CAPS_BLE,
                          *(int*)prop->val);
      break;
    case BT_PROPERTY_ADAPTER_DISCOVERY_TIMEOUT:
      btif_config_set_int("Adapter", BTIF_STORAGE_KEY_ADAPTER_DISC_TIMEOUT,
                  *(int*)prop->val);
      break;
    case BT_PROPERTY_CLASS_OF_DEVICE:
      btif_config_set_int(bdstr, BTIF_STORAGE_PATH_REMOTE_DEVCLASS,
                  *(int*)prop->val);
      break;
    case BT_PROPERTY_TYPE_OF_DEVICE:
      btif_config_set_int(bdstr, BTIF_STORAGE_PATH_REMOTE_DEVTYPE,
                  *(int*)prop->val);
      break;
    case BT_PROPERTY_REM_DEViCE_VALID_ADDR:
      btif_config_set_int(bdstr, BTIF_STORAGE_PATH_REMOTE_VALID_ADDR,
                *(int*)prop->val);
      break;
    case BT_PROPERTY_REM_DEV_IS_ADV_AUDIO:
      btif_config_set_int(bdstr, BTIF_STORAGE_PATH_REMOTE_ADV_AUDIO,
                *(int*)prop->val);
      break;
    case BT_PROPERTY_REM_DEV_IDENT_BD_ADDR:
    {
      RawAddress peer_addr;
      peer_addr = *(RawAddress *)prop->val;
      btif_config_set_str(bdstr, BTIF_STORAGE_PATH_REMOTE_MAPPING_ADDR,
        (char*) peer_addr.ToString().c_str());
    }
      break;
    case BT_PROPERTY_UUIDS:
      {
        std::string val;
        size_t cnt = (prop->len) / sizeof(Uuid);
        for (size_t i = 0; i < cnt; i++) {
          val += (reinterpret_cast<Uuid*>(prop->val) + i)->ToString() + " ";
        }
        btif_config_set_str(bdstr, BTIF_STORAGE_PATH_REMOTE_SERVICE, val.c_str());
      }
      break;
    case BT_PROPERTY_REMOTE_VERSION_INFO:
      {
        bt_remote_version_t* info = (bt_remote_version_t*)prop->val;
        if(!info){
          BTIF_TRACE_ERROR("%s: version info is null", __func__);
          ret = false;
          break;
        }
        btif_config_set_int(bdstr, BTIF_STORAGE_PATH_REMOTE_VER_MFCT,
                    info->manufacturer);
        btif_config_set_int(bdstr, BTIF_STORAGE_PATH_REMOTE_VER_VER,
                    info->version);
        btif_config_set_int(bdstr, BTIF_STORAGE_PATH_REMOTE_VER_SUBVER,
                    info->sub_ver);
      }
      break;
    case BT_PROPERTY_ADV_AUDIO_UUIDS:
      {
        std::string val;
        size_t cnt = (prop->len) / sizeof(Uuid);
        for (size_t i = 0; i < cnt; i++) {
          Uuid* tmp_uuid;
          tmp_uuid = ((Uuid*)(prop->val) + i);
          BTIF_TRACE_DEBUG(" %s  index %d", tmp_uuid->ToString().c_str(), i);
          val += tmp_uuid->ToString() + " ";
          //val += (reinterpret_cast<Uuid*>(prop->val) + i)->ToString() + " ";
        }
        btif_config_set_str(bdstr, BTIF_STORAGE_PATH_ADV_AUDIO_REMOTE_SERVICE, val.c_str());
      }
      break;
    default:
      BTIF_TRACE_ERROR("%s: Unknown prop type:%d", __func__, prop->type);
      ret = false;
      break;
  }

  return ret;
}

static int prop2cfgs(const RawAddress* remote_bd_addr, bt_property_t* prop, int count) {
  std::string addrstr;
  const char* bdstr = addrstr.c_str();
  int dev_type = BT_DEVICE_TYPE_BREDR, c;
  int ret = 0;

  if (remote_bd_addr) {
      addrstr = remote_bd_addr->ToString();
      bdstr = addrstr.c_str();
  }

  for(c = 0; c<count; c++, prop++)
  {
      ret |= (int)prop_upd(remote_bd_addr, prop);
  }

  /* save changes if the device was bonded */
  if (ret && btif_in_fetch_bonded_device(bdstr, &dev_type) == BT_STATUS_SUCCESS) {
    // flush is expensive, avoid for BLE devices during BLE Scanning
    if(dev_type == BT_DEVICE_TYPE_BREDR) {
      btif_config_flush();
    } else {
      btif_config_save();
    }
  }

  return ret;
}

static int prop2cfg(const RawAddress* remote_bd_addr, bt_property_t* prop) {
  std::string addrstr;
  const char* bdstr = addrstr.c_str();
  int dev_type = BT_DEVICE_TYPE_BREDR;
  int ret;

  if(remote_bd_addr) {
    addrstr = remote_bd_addr->ToString();
    bdstr = addrstr.c_str();
  }

  ret = (int)prop_upd(remote_bd_addr, prop);
  if(!ret) {
      BTIF_TRACE_ERROR("%s: prop_upd fail", __func__);
  }
  /* save changes if the device was bonded */
  if (ret && btif_in_fetch_bonded_device(bdstr, &dev_type) == BT_STATUS_SUCCESS) {
    // flush is expensive, avoid for BLE devices during BLE Scanning
    if(dev_type == BT_DEVICE_TYPE_BREDR) {
      btif_config_flush();
#ifdef ADV_AUDIO_FEATURE
    } else if (remote_bd_addr && is_remote_support_adv_audio(*remote_bd_addr)) {
      btif_config_flush();
#endif
    } else {
      btif_config_save();
    }
  }

  return ret;
}

static int cfg2prop(const RawAddress* remote_bd_addr, bt_property_t* prop) {
  std::string addrstr;
  const char* bdstr = addrstr.c_str();
  if (remote_bd_addr) {
    addrstr = remote_bd_addr->ToString();
    bdstr = addrstr.c_str();
  }
  BTIF_TRACE_DEBUG("in, bd addr:%s, prop type:%d, len:%d", bdstr, prop->type,
                   prop->len);
  if (prop->len <= 0) {
    BTIF_TRACE_ERROR("property type:%d, len:%d is invalid", prop->type,
                     prop->len);
    return false;
  }
  int ret = false;
  switch ((uint8_t)prop->type) {
    case BT_PROPERTY_REMOTE_DEVICE_TIMESTAMP:
      if (prop->len >= (int)sizeof(int))
        ret = btif_config_get_int(bdstr, BTIF_STORAGE_PATH_REMOTE_DEVTIME,
                                  (int*)prop->val);
      break;
    case BT_PROPERTY_BDNAME: {
      int len = prop->len;
      if (remote_bd_addr)
        ret = btif_config_get_str(bdstr, BTIF_STORAGE_PATH_REMOTE_NAME,
                                  (char*)prop->val, &len);
      else
        ret = btif_config_get_str("Adapter", BTIF_STORAGE_KEY_ADAPTER_NAME,
                                  (char*)prop->val, &len);
      if (ret && len && len <= prop->len)
        prop->len = len - 1;
      else {
        prop->len = 0;
        ret = false;
      }
      break;
    }
    case BT_PROPERTY_REMOTE_FRIENDLY_NAME: {
      int len = prop->len;
      ret = btif_config_get_str(bdstr, BTIF_STORAGE_PATH_REMOTE_ALIASE,
                                (char*)prop->val, &len);
      if (ret && len && len <= prop->len)
        prop->len = len - 1;
      else {
        prop->len = 0;
        ret = false;
      }
      break;
    }

    case BT_PROPERTY_GROUP_DETAILS: {
      BTIF_TRACE_DEBUG("loading device group details: %s", BTIF_STORAGE_PATH_REMOTE_DGROUP);
      int len = prop->len;
      ret = btif_config_get_str(bdstr, BTIF_STORAGE_PATH_REMOTE_DGROUP,
                                (char*)prop->val, &len);
      BTIF_TRACE_DEBUG("loading group details val: %s ret = %d", prop->val, ret);
      if (ret && len && len <= prop->len)
        prop->len = len - 1;
      else {
        prop->len = 0;
        ret = false;
      }
      break;
    }

    case BT_PROPERTY_ADAPTER_SCAN_MODE:
      if (prop->len >= (int)sizeof(int))
        ret = btif_config_get_int("Adapter", BTIF_STORAGE_KEY_ADAPTER_SCANMODE,
                                  (int*)prop->val);
      break;

    case BT_PROPERTY_LOCAL_IO_CAPS:
      if (prop->len >= (int)sizeof(int))
        ret = btif_config_get_int("Adapter", BTIF_STORAGE_KEY_LOCAL_IO_CAPS,
                                  (int*)prop->val);
      break;
    case BT_PROPERTY_LOCAL_IO_CAPS_BLE:
      if (prop->len >= (int)sizeof(int))
        ret = btif_config_get_int("Adapter", BTIF_STORAGE_KEY_LOCAL_IO_CAPS_BLE,
                                  (int*)prop->val);
      break;

    case BT_PROPERTY_ADAPTER_DISCOVERY_TIMEOUT:
      if (prop->len >= (int)sizeof(int))
        ret = btif_config_get_int(
            "Adapter", BTIF_STORAGE_KEY_ADAPTER_DISC_TIMEOUT, (int*)prop->val);
      break;
    case BT_PROPERTY_CLASS_OF_DEVICE:
      if (prop->len >= (int)sizeof(int))
        ret = btif_config_get_int(bdstr, BTIF_STORAGE_PATH_REMOTE_DEVCLASS,
                                  (int*)prop->val);
      break;
    case BT_PROPERTY_TYPE_OF_DEVICE:
      if (prop->len >= (int)sizeof(int))
        ret = btif_config_get_int(bdstr, BTIF_STORAGE_PATH_REMOTE_DEVTYPE,
                                  (int*)prop->val);
      break;
    case BT_PROPERTY_REM_DEViCE_VALID_ADDR:
      if (prop->len >= (int)sizeof(int))
        ret = btif_config_get_int(bdstr, BTIF_STORAGE_PATH_REMOTE_VALID_ADDR,
                                  (int*)prop->val);
      break;
    case BT_PROPERTY_REM_DEV_IS_ADV_AUDIO:
      if (prop->len >= (int)sizeof(int))
        ret = btif_config_get_int(bdstr, BTIF_STORAGE_PATH_REMOTE_ADV_AUDIO,
                                  (int*)prop->val);
      break;
    case BT_PROPERTY_REM_DEV_IDENT_BD_ADDR:
    {
      int len = prop->len;
      BTIF_TRACE_DEBUG("%s() BT_PROPERTY_REM_DEV_IDENT_BD_ADDR %s", __func__, bdstr);
      if (prop->len >= (int)sizeof(RawAddress))
        ret = btif_config_get_str(bdstr, BTIF_STORAGE_PATH_REMOTE_MAPPING_ADDR,
                                  (char*)prop->val, &len);
    }
      break;
    case BT_PROPERTY_UUIDS: {
      char value[1280];
      int size = sizeof(value);
      if (btif_config_get_str(bdstr, BTIF_STORAGE_PATH_REMOTE_SERVICE, value,
                              &size)) {
        Uuid* p_uuid = reinterpret_cast<Uuid*>(prop->val);
        size_t num_uuids =
            btif_split_uuids_string(value, p_uuid, BT_MAX_NUM_UUIDS);
        prop->len = num_uuids * sizeof(Uuid);
        ret = true;
      } else {
        prop->val = NULL;
        prop->len = 0;
      }
    } break;
    case BT_PROPERTY_ADV_AUDIO_UUIDS: {
      char value[1280];
      int size = sizeof(value);
      if (btif_config_get_str(bdstr, BTIF_STORAGE_PATH_ADV_AUDIO_REMOTE_SERVICE, value,
                              &size)) {
        Uuid* p_uuid = reinterpret_cast<Uuid*>(prop->val);
        size_t num_uuids =
            btif_split_uuids_string(value, p_uuid, BT_MAX_NUM_UUIDS);
        prop->len = num_uuids * sizeof(Uuid);
        ret = true;
      } else {
        prop->val = NULL;
        prop->len = 0;
      }
    } break;

    case BT_PROPERTY_REMOTE_VERSION_INFO: {
      bt_remote_version_t* info = (bt_remote_version_t*)prop->val;

      if (prop->len >= (int)sizeof(bt_remote_version_t)) {
        ret = btif_config_get_int(bdstr, BTIF_STORAGE_PATH_REMOTE_VER_MFCT,
                                  &info->manufacturer);

        if (ret == true)
          ret = btif_config_get_int(bdstr, BTIF_STORAGE_PATH_REMOTE_VER_VER,
                                    &info->version);

        if (ret == true)
          ret = btif_config_get_int(bdstr, BTIF_STORAGE_PATH_REMOTE_VER_SUBVER,
                                    &info->sub_ver);
      }
    } break;

    default:
      BTIF_TRACE_ERROR("Unknow prop type:%d", prop->type);
      return false;
  }
  return ret;
}

/*******************************************************************************
 *
 * Function         btif_in_fetch_bonded_devices
 *
 * Description      Internal helper function to fetch the bonded devices
 *                  from NVRAM
 *
 * Returns          BT_STATUS_SUCCESS if successful, BT_STATUS_FAIL otherwise
 *
 ******************************************************************************/
static bt_status_t btif_in_fetch_bonded_device(const char* bdstr, int *p_dev_type) {
  bool bt_linkkey_file_found = false;
  bool bt_ltk_found = false;

  LinkKey link_key;
  size_t size = link_key.size();
  if (btif_config_get_bin(bdstr, "LinkKey", link_key.data(), &size)) {
    int linkkey_type;
    if (btif_config_get_int(bdstr, "LinkKeyType", &linkkey_type)) {
      bt_linkkey_file_found = true;
    } else {
      bt_linkkey_file_found = false;
    }
  }

  if (btif_in_fetch_bonded_ble_device(bdstr, false, NULL) == BT_STATUS_SUCCESS)
    bt_ltk_found = true;

  if(!bt_ltk_found && !bt_linkkey_file_found) {
    BTIF_TRACE_DEBUG("Remote device:%s, no link key or ble key found", bdstr);
    return BT_STATUS_FAIL;
  } else {
    btif_config_get_int(bdstr, "DevType", p_dev_type);
  }

  return BT_STATUS_SUCCESS;
}

/*******************************************************************************
 *
 * Function         btif_in_fetch_bonded_devices
 *
 * Description      Internal helper function to fetch the bonded devices
 *                  from NVRAM
 *
 * Returns          BT_STATUS_SUCCESS if successful, BT_STATUS_FAIL otherwise
 *
 ******************************************************************************/
static bt_status_t btif_in_fetch_bonded_devices(
    list_t** p_bonded_devices, int add) {

  bool bt_linkkey_file_found = false;
  int device_type;

  for (const btif_config_section_iter_t* iter = btif_config_section_begin();
       iter != btif_config_section_end();
       iter = btif_config_section_next(iter)) {
    const char* name = btif_config_section_name(iter);
    if (!RawAddress::IsValidAddress(name)) continue;

    BTIF_TRACE_DEBUG("Remote device:%s", name);
    LinkKey link_key;
    size_t size = sizeof(link_key);
    if (btif_config_get_bin(name, "LinkKey", link_key.data(), &size)) {
      int linkkey_type;
      if (btif_config_get_int(name, "LinkKeyType", &linkkey_type)) {
        RawAddress bd_addr;
        RawAddress::FromString(name, bd_addr);
        if (add) {
          DEV_CLASS dev_class = {0, 0, 0};
          int cod;
          int pin_length = 0;
          if (btif_config_get_int(name, "DevClass", &cod))
            uint2devclass((uint32_t)cod, dev_class);
          btif_config_get_int(name, "PinLength", &pin_length);
          BTA_DmAddDevice(bd_addr, dev_class, link_key, 0, 0,
                          (uint8_t)linkkey_type, 0, pin_length);

          if (btif_config_get_int(name, "DevType", &device_type) &&
              (device_type == BT_DEVICE_TYPE_DUMO)) {
            btif_gatts_add_bonded_dev_from_nv(bd_addr);
          }
        }
        bt_linkkey_file_found = true;
        RawAddress *remote_addr =  (RawAddress *)osi_malloc(sizeof(RawAddress));
        memcpy(remote_addr, &bd_addr, RawAddress::kLength);
        list_append(*p_bonded_devices, remote_addr);
      } else {
        bt_linkkey_file_found = false;
      }
    }
    if (!btif_in_fetch_bonded_ble_device(name, add, p_bonded_devices) &&
        !bt_linkkey_file_found) {
      BTIF_TRACE_DEBUG("Remote device:%s, no link key or ble key found", name);
    }
  }
  return BT_STATUS_SUCCESS;
}

static void btif_read_le_key(const uint8_t key_type, const size_t key_len,
                             RawAddress bd_addr, const uint8_t addr_type,
                             const bool add_key, bool* device_added,
                             bool* key_found) {
  CHECK(device_added);
  CHECK(key_found);

  tBTA_LE_KEY_VALUE key;
  memset(&key, 0, sizeof(key));

  if (btif_storage_get_ble_bonding_key(&bd_addr, key_type, (uint8_t*)&key,
                                       key_len) == BT_STATUS_SUCCESS) {
    if (add_key) {
      if (!*device_added) {
        BTA_DmAddBleDevice(bd_addr, addr_type, BT_DEVICE_TYPE_BLE);
        *device_added = true;
      }

      BTIF_TRACE_DEBUG("%s() Adding key type %d for %s", __func__, key_type,
                       bd_addr.ToString().c_str());
      BTA_DmAddBleKey(bd_addr, &key, key_type);
    }

    *key_found = true;
  }
}

/*******************************************************************************
 * Functions
 *
 * Functions are synchronous and can be called by both from internal modules
 * such as BTIF_DM and by external entiries from HAL via BTIF_context_switch.
 * For OUT parameters, the caller is expected to provide the memory.
 * Caller is expected to provide a valid pointer to 'property->value' based on
 * the property->type.
 ******************************************************************************/

/*******************************************************************************
 *
 * Function         btif_split_uuids_string
 *
 * Description      Internal helper function to split the string of UUIDs
 *                  read from the NVRAM to an array
 *
 * Returns          Number of UUIDs parsed from the supplied string
 *
 ******************************************************************************/
size_t btif_split_uuids_string(const char* str, bluetooth::Uuid* p_uuid,
                               size_t max_uuids) {
  CHECK(str);
  CHECK(p_uuid);

  size_t num_uuids = 0;
  while (str && num_uuids < max_uuids) {
    bool is_valid;
    bluetooth::Uuid tmp =
        Uuid::FromString(std::string(str, Uuid::kString128BitLen), &is_valid);
    if (!is_valid) break;

    *p_uuid = tmp;
    p_uuid++;

    num_uuids++;
    str = strchr(str, ' ');
    if (str) str++;
  }

  return num_uuids;
}

/**
 * Helper function for fetching a local Input/Output capability property. If not
 * set, it returns the default value.
 */
static uint8_t btif_storage_get_io_cap_property(bt_property_type_t type,
                                                uint8_t default_value) {
  char buf[sizeof(int)];

  bt_property_t property;
  property.type = type;
  property.val = (void*)buf;
  property.len = sizeof(int);

  bt_status_t ret = btif_storage_get_adapter_property(&property);

  return (ret == BT_STATUS_SUCCESS) ? (uint8_t)(*(int*)property.val)
                                    : default_value;
}

/*******************************************************************************
 *
 * Function         btif_storage_get_io_caps
 *
 * Description      BTIF storage API - Fetches the local Input/Output
 *                  capabilities of the device.
 *
 * Returns          Returns local IO Capability of device. If not stored,
 *                  returns BTM_LOCAL_IO_CAPS.
 *
 ******************************************************************************/
uint8_t btif_storage_get_local_io_caps() {
  return btif_storage_get_io_cap_property(BT_PROPERTY_LOCAL_IO_CAPS,
                                          BTM_LOCAL_IO_CAPS);
}

/*******************************************************************************
 *
 * Function         btif_storage_get_io_caps_ble
 *
 * Description      BTIF storage API - Fetches the local Input/Output
 *                  capabilities of the BLE device.
 *
 * Returns          Returns local IO Capability of BLE device. If not stored,
 *                  returns BTM_LOCAL_IO_CAPS_BLE.
 *
 ******************************************************************************/
uint8_t btif_storage_get_local_io_caps_ble() {
  return btif_storage_get_io_cap_property(BT_PROPERTY_LOCAL_IO_CAPS_BLE,
                                          BTM_LOCAL_IO_CAPS_BLE);
}

/*******************************************************************************
 *
 * Function         btif_storage_get_adapter_property
 *
 * Description      BTIF storage API - Fetches the adapter property->type
 *                  from NVRAM and fills property->val.
 *                  Caller should provide memory for property->val and
 *                  set the property->val
 *
 * Returns          BT_STATUS_SUCCESS if the fetch was successful,
 *                  BT_STATUS_FAIL otherwise
 *
 ******************************************************************************/
bt_status_t btif_storage_get_adapter_property(bt_property_t* property) {
  /* Special handling for adapter address and BONDED_DEVICES */
  if (property->type == BT_PROPERTY_BDADDR) {
    RawAddress* bd_addr = (RawAddress*)property->val;
    /* Fetch the local BD ADDR */
    const controller_t* controller = controller_get_interface();
    if (controller->get_is_ready() == false) {
      LOG_ERROR(LOG_TAG,
                "%s: Controller not ready! Unable to return Bluetooth Address",
                __func__);
      *bd_addr = RawAddress::kEmpty;
      return BT_STATUS_FAIL;
    } else {
      LOG_ERROR(LOG_TAG, "%s: Controller ready!", __func__);
      *bd_addr = *controller->get_address();
    }
    property->len = RawAddress::kLength;
    return BT_STATUS_SUCCESS;
  } else if (property->type == BT_PROPERTY_ADAPTER_BONDED_DEVICES) {
    list_t *bonded_devices = list_new(osi_free);
    int len = 0;
    int i = 0;
    property->len = 0;

    btif_in_fetch_bonded_devices(&bonded_devices, 0);

    BTIF_TRACE_DEBUG(
        "%s: Number of bonded devices: %zu "
        "Property:BT_PROPERTY_ADAPTER_BONDED_DEVICES",
        __func__, list_length(bonded_devices));

    if (list_length(bonded_devices)) {
      property->len = list_length(bonded_devices) * RawAddress::kLength;
      RawAddress* devices_list = (RawAddress*)osi_malloc(property->len);
      property->val = devices_list;
      for (list_node_t* node = list_begin(bonded_devices);
            node != list_end(bonded_devices); node = list_next(node), i++) {
        memcpy(&devices_list[i], list_node(node), RawAddress::kLength);
        len = len + RawAddress::kLength;
      }
    }

    /* if there are no bonded_devices, then length shall be 0 */
    list_free(bonded_devices);
    return BT_STATUS_SUCCESS;
  } else if (property->type == BT_PROPERTY_UUIDS) {
    /* publish list of local supported services */
    Uuid* p_uuid = reinterpret_cast<Uuid*>(property->val);
    uint32_t num_uuids = 0;
    uint64_t i;

    tBTA_SERVICE_MASK service_mask = btif_get_enabled_services_mask();
    LOG_INFO(LOG_TAG, "%s service_mask:0x%" PRIx64, __func__,service_mask);
    for (i = 0; i < BTA_MAX_SERVICE_ID; i++) {
      /* This should eventually become a function when more services are enabled
       */
      if (service_mask & ((tBTA_SERVICE_MASK)1 << i)) {
        switch (i) {
          case BTA_HFP_SERVICE_ID: {
            *(p_uuid + num_uuids) =
                Uuid::From16Bit(UUID_SERVCLASS_AG_HANDSFREE);
            num_uuids++;
          }
          FALLTHROUGH;
          /* intentional fall through: Send both BFP & HSP UUIDs if HFP is
           * enabled */
          case BTA_HSP_SERVICE_ID: {
            *(p_uuid + num_uuids) =
                Uuid::From16Bit(UUID_SERVCLASS_HEADSET_AUDIO_GATEWAY);
            num_uuids++;
          } break;
          case BTA_A2DP_SOURCE_SERVICE_ID: {
            *(p_uuid + num_uuids) =
                Uuid::From16Bit(UUID_SERVCLASS_AUDIO_SOURCE);
            num_uuids++;
          } break;
          case BTA_A2DP_SINK_SERVICE_ID: {
            *(p_uuid + num_uuids) = Uuid::From16Bit(UUID_SERVCLASS_AUDIO_SINK);
            num_uuids++;
          } break;
          case BTA_HFP_HS_SERVICE_ID: {
            *(p_uuid + num_uuids) =
                Uuid::From16Bit(UUID_SERVCLASS_HF_HANDSFREE);
            num_uuids++;
          } break;
        }
      }
    }
    property->len = (num_uuids) * sizeof(Uuid);
    return BT_STATUS_SUCCESS;
  }

  /* fall through for other properties */
  if (!cfg2prop(NULL, property)) {
    return btif_dm_get_adapter_property(property);
  }
  return BT_STATUS_SUCCESS;
}

/*******************************************************************************
 *
 * Function         btif_storage_set_adapter_property
 *
 * Description      BTIF storage API - Stores the adapter property
 *                  to NVRAM
 *
 * Returns          BT_STATUS_SUCCESS if the store was successful,
 *                  BT_STATUS_FAIL otherwise
 *
 ******************************************************************************/
bt_status_t btif_storage_set_adapter_property(bt_property_t* property) {
  return prop2cfg(NULL, property) ? BT_STATUS_SUCCESS : BT_STATUS_FAIL;
}

/*******************************************************************************
 *
 * Function         btif_storage_get_remote_device_property
 *
 * Description      BTIF storage API - Fetches the remote device property->type
 *                  from NVRAM and fills property->val.
 *                  Caller should provide memory for property->val and
 *                  set the property->val
 *
 * Returns          BT_STATUS_SUCCESS if the fetch was successful,
 *                  BT_STATUS_FAIL otherwise
 *
 ******************************************************************************/
bt_status_t btif_storage_get_remote_device_property(
    const RawAddress* remote_bd_addr, bt_property_t* property) {
  return cfg2prop(remote_bd_addr, property) ? BT_STATUS_SUCCESS
                                            : BT_STATUS_FAIL;
}
/*******************************************************************************
 *
 * Function         btif_storage_set_remote_device_property
 *
 * Description      BTIF storage API - Stores the remote device property
 *                  to NVRAM
 *
 * Returns          BT_STATUS_SUCCESS if the store was successful,
 *                  BT_STATUS_FAIL otherwise
 *
 ******************************************************************************/
bt_status_t btif_storage_set_remote_device_property(
    const RawAddress* remote_bd_addr, bt_property_t* property) {
  return prop2cfg(remote_bd_addr, property) ? BT_STATUS_SUCCESS
                                            : BT_STATUS_FAIL;
}

/*******************************************************************************
 *
 * Function         btif_storage_set_remote_device_properties
 *
 * Description      BTIF storage API - Stores the remote device properties
 *                  to NVRAM
 *
 * Returns          BT_STATUS_SUCCESS if the store was successful,
 *                  BT_STATUS_FAIL otherwise
 *
 ******************************************************************************/
bt_status_t btif_storage_set_remote_device_properties(
    const RawAddress* remote_bd_addr, bt_property_t* property, int number) {
  return prop2cfgs(remote_bd_addr, property, number) ? BT_STATUS_SUCCESS
                                            : BT_STATUS_FAIL;
}

/*******************************************************************************
 *
 * Function         btif_storage_add_remote_device
 *
 * Description      BTIF storage API - Adds a newly discovered device to NVRAM
 *                  along with the timestamp. Also, stores the various
 *                  properties - RSSI, BDADDR, NAME (if found in EIR)
 *
 * Returns          BT_STATUS_SUCCESS if the store was successful,
 *                  BT_STATUS_FAIL otherwise
 *
 ******************************************************************************/
bt_status_t btif_storage_add_remote_device(const RawAddress* remote_bd_addr,
                                           uint32_t num_properties,
                                           bt_property_t* properties) {
  uint32_t i = 0;
  /* TODO: If writing a property, fails do we go back undo the earlier
   * written properties? */
  for (i = 0; i < num_properties; i++) {
    /* Ignore the RSSI as this is not stored in DB */
    if (properties[i].type == BT_PROPERTY_REMOTE_RSSI) continue;

    /* address for remote device needs special handling as we also store
     * timestamp */
    if (properties[i].type == BT_PROPERTY_BDADDR) {
      bt_property_t addr_prop;
      memcpy(&addr_prop, &properties[i], sizeof(bt_property_t));
      addr_prop.type = (bt_property_type_t)BT_PROPERTY_REMOTE_DEVICE_TIMESTAMP;
      btif_storage_set_remote_device_property(remote_bd_addr, &addr_prop);
    } else {
      btif_storage_set_remote_device_property(remote_bd_addr, &properties[i]);
    }
  }
  return BT_STATUS_SUCCESS;
}

/*******************************************************************************
 *
 * Function         btif_storage_add_bonded_device
 *
 * Description      BTIF storage API - Adds the newly bonded device to NVRAM
 *                  along with the link-key, Key type and Pin key length
 *
 * Returns          BT_STATUS_SUCCESS if the store was successful,
 *                  BT_STATUS_FAIL otherwise
 *
 ******************************************************************************/

bt_status_t btif_storage_add_bonded_device(RawAddress* remote_bd_addr,
                                           LinkKey link_key, uint8_t key_type,
                                           uint8_t pin_length) {
  std::string addrstr = remote_bd_addr->ToString();
  const char* bdstr = addrstr.c_str();
  int ret = btif_config_set_int(bdstr, "LinkKeyType", (int)key_type);
  ret &= btif_config_set_int(bdstr, "PinLength", (int)pin_length);
  ret &=
      btif_config_set_bin(bdstr, "LinkKey", link_key.data(), link_key.size());

  if (is_restricted_mode()) {
    BTIF_TRACE_WARNING("%s: '%s' pairing will be removed if unrestricted",
                       __func__, bdstr);
    btif_config_set_int(bdstr, "Restricted", 1);
  }

  /* write bonded info immediately */
  btif_config_flush();
  return ret ? BT_STATUS_SUCCESS : BT_STATUS_FAIL;
}

/*******************************************************************************
 *
 * Function         btif_storage_remove_bonded_device
 *
 * Description      BTIF storage API - Deletes the bonded device from NVRAM
 *
 * Returns          BT_STATUS_SUCCESS if the deletion was successful,
 *                  BT_STATUS_FAIL otherwise
 *
 ******************************************************************************/
bt_status_t btif_storage_remove_bonded_device(
    const RawAddress* remote_bd_addr) {
  std::string addrstr = remote_bd_addr->ToString();
  const char* bdstr = addrstr.c_str();
  BTIF_TRACE_DEBUG("in bd addr:%s", bdstr);

  btif_storage_remove_ble_bonding_keys(remote_bd_addr);

  int ret = 1;
  if (btif_config_exist(bdstr, "LinkKeyType"))
    ret &= btif_config_remove(bdstr, "LinkKeyType");
  if (btif_config_exist(bdstr, "PinLength"))
    ret &= btif_config_remove(bdstr, "PinLength");
  if (btif_config_exist(bdstr, "LinkKey"))
    ret &= btif_config_remove(bdstr, "LinkKey");
  if (btif_config_exist(bdstr, "Timestamp"))
    ret &= btif_config_remove(bdstr, "Timestamp");
  if (btif_config_exist(bdstr, "DevClass"))
    ret &= btif_config_remove(bdstr, "DevClass");
  if (btif_config_exist(bdstr, "DevType"))
    ret &= btif_config_remove(bdstr, "DevType");
  if (btif_config_exist(bdstr, "AddrType"))
    ret &= btif_config_remove(bdstr, "AddrType");
  if (btif_config_exist(bdstr, "Manufacturer"))
    ret &= btif_config_remove(bdstr, "Manufacturer");
  if (btif_config_exist(bdstr, "LmpVer"))
    ret &= btif_config_remove(bdstr, "LmpVer");
  if (btif_config_exist(bdstr, "LmpSubVer"))
    ret &= btif_config_remove(bdstr, "LmpSubVer");
  if (btif_config_exist(bdstr, "Service"))
    ret &= btif_config_remove(bdstr, "Service");
  if (btif_config_exist(bdstr, "A2dpVersion"))
    ret &= btif_config_remove(bdstr, "A2dpVersion");
  if (btif_config_exist(bdstr, "AvdtpVersion"))
    ret &= btif_config_remove(bdstr, "AvdtpVersion");
  if (btif_config_exist(bdstr, "HfpVersion"))
    ret &= btif_config_remove(bdstr, "HfpVersion");
  if (btif_config_exist(bdstr, "AvrcpTgVersion"))
    ret &= btif_config_remove(bdstr, "AvrcpTgVersion");
  if (btif_config_exist(bdstr, "PbapPceVersion"))
    ret &= btif_config_remove(bdstr, "PbapPceVersion");
  if (btif_config_exist(bdstr, "VendorID"))
    ret &= btif_config_remove(bdstr, "VendorID");
  if (btif_config_exist(bdstr, "ProductID"))
    ret &= btif_config_remove(bdstr, "ProductID");
  if (btif_config_exist(bdstr, "ProductVersion"))
    ret &= btif_config_remove(bdstr, "ProductVersion");
  if (btif_config_exist(bdstr, MAP_MCE_VERSION_CONFIG_KEY))
    ret &= btif_config_remove(bdstr, MAP_MCE_VERSION_CONFIG_KEY);
  if (btif_config_exist(bdstr, BTIF_STORAGE_KEY_EATT_SUPPORT))
    ret &= btif_config_remove(bdstr, BTIF_STORAGE_KEY_EATT_SUPPORT);
  if (btif_config_exist(bdstr, BTIF_STORAGE_KEY_CLIENT_SUPP_FEAT))
    ret &= btif_config_remove(bdstr, BTIF_STORAGE_KEY_CLIENT_SUPP_FEAT);
  if (btif_config_exist(bdstr, "ValidAddr"))
    ret &= btif_config_remove(bdstr, "ValidAddr");
  if (btif_config_exist(bdstr, "MapAddr"))
    ret &= btif_config_remove(bdstr, "MapAddr");
  if (btif_config_exist(bdstr, "AdvAudioService"))
    ret &= btif_config_remove(bdstr, "AdvAudioService");
  if (btif_config_exist(bdstr, "IsAdvAudio"))
    ret &= btif_config_remove(bdstr, "IsAdvAudio");
  if (btif_config_exist(bdstr, "QLL_FEATURES"))
    ret &= btif_config_remove(bdstr, "QLL_FEATURES");
  if (btif_config_exist(bdstr, "QCM_PHY_STATE"))
    ret &= btif_config_remove(bdstr, "QCM_PHY_STATE");
  /* Retaining TwsPlusPeerAddr , AvrcpCtVersion and AvrcpFeatures
     as these are needed even after unpair */
  /* write bonded info immediately */
  btif_config_flush();
  return ret ? BT_STATUS_SUCCESS : BT_STATUS_FAIL;
}

/* Some devices hardcode sample LTK value from spec, instead of generating one.
 * Treat such devices as insecure, and remove such bonds when bluetooth
 * restarts. Removing them after disconnection is handled separately.
 *
 * We still allow such devices to bond in order to give the user a chance to
 * update firmware.
 */
static void remove_devices_with_sample_ltk() {
  std::vector<RawAddress> bad_ltk;
  for (const btif_config_section_iter_t* iter = btif_config_section_begin();
       iter != btif_config_section_end();
       iter = btif_config_section_next(iter)) {
    const std::string name(btif_config_section_name(iter));
    if (!RawAddress::IsValidAddress(name)) {
      continue;
    }

    RawAddress bd_addr;
    RawAddress::FromString(name, bd_addr);

    tBTA_LE_KEY_VALUE key;
    memset(&key, 0, sizeof(key));

    if (btif_storage_get_ble_bonding_key(
            &bd_addr, BTIF_DM_LE_KEY_PENC, (uint8_t*)&key,
            sizeof(tBTM_LE_PENC_KEYS)) == BT_STATUS_SUCCESS) {
      if (is_sample_ltk(key.penc_key.ltk)) {
        bad_ltk.push_back(bd_addr);
      }
    }
  }

  for (RawAddress address : bad_ltk) {
    android_errorWriteLog(0x534e4554, "128437297");
    LOG(ERROR) << __func__
               << ": removing bond to device using test TLK: " << address;

    btif_storage_remove_bonded_device(&address);
  }
}

/*******************************************************************************
**
** Function         btif_storage_is_device_bonded
**
** Description      BTIF storage API - checks if device present in bonded list
**
** Returns          BT_STATUS_SUCCESS if the device is bonded
**                  BT_STATUS_FAIL otherwise
**
*******************************************************************************/
bt_status_t btif_storage_is_device_bonded(RawAddress *remote_bd_addr) {


  char bdstr[18] = {'\0'};
  snprintf(bdstr, sizeof(bdstr), "%02x:%02x:%02x:%02x:%02x:%02x",
                                  remote_bd_addr->address[0],
                                  remote_bd_addr->address[1],
                                  remote_bd_addr->address[2],
                                  remote_bd_addr->address[3],
                                  remote_bd_addr->address[4],
                                  remote_bd_addr->address[5]);
  if((btif_config_exist(bdstr, "LinkKey")) &&
     (btif_config_exist(bdstr, "LinkKeyType")))
    return BT_STATUS_SUCCESS;
  else
    return BT_STATUS_FAIL;
}

void btif_storage_get_remote_services(RawAddress *p_addr, Uuid *actual_rem_uuids,
        int num_uuids) {

  Uuid remote_uuids[BT_MAX_NUM_UUIDS];
  Uuid remote_le_uuids[BT_MAX_NUM_UUIDS];
  bt_property_t prop;

  prop.type = BT_PROPERTY_UUIDS;
  prop.val = &remote_uuids[0];
  prop.len = sizeof(remote_uuids);
  btif_storage_get_remote_device_property(p_addr, &prop);

  int i, valid_uuids = 0;
  for (i = 0; i < BT_MAX_NUM_UUIDS; i++) {
    if (remote_uuids[i] != Uuid::kEmpty) {
      BTIF_TRACE_EVENT("%s: UUID %s index %d ", __func__,
        remote_uuids[i].ToString().c_str());
      actual_rem_uuids[valid_uuids] = remote_uuids[i];
      valid_uuids++;
    }
  }
  prop.type = (bt_property_type_t)BT_PROPERTY_ADV_AUDIO_UUIDS;
  prop.val = &remote_le_uuids[0];
  prop.len = sizeof(remote_le_uuids);
  btif_storage_get_remote_device_property(p_addr, &prop);

  int final_valid_index = valid_uuids;
  for (i = 0; i < BT_MAX_NUM_UUIDS && final_valid_index < BT_MAX_NUM_UUIDS; i++) {
    if (remote_le_uuids[i] != Uuid::kEmpty) {
      BTIF_TRACE_EVENT("%s: UUID %s index %d ", __func__,
        remote_le_uuids[i].ToString().c_str());
      actual_rem_uuids[final_valid_index] = remote_le_uuids[i];
      final_valid_index++;
    }
  }
}

/*******************************************************************************
**
 * Function         btif_storage_load_bonded_devices
 *
 * Description      BTIF storage API - Loads all the bonded devices from NVRAM
 *                  and adds to the BTA.
 *                  Additionally, this API also invokes the adaper_properties_cb
 *                  and remote_device_properties_cb for each of the bonded
 *                  devices.
 *
 * Returns          BT_STATUS_SUCCESS if successful, BT_STATUS_FAIL otherwise
 *
 ******************************************************************************/
bt_status_t btif_storage_load_bonded_devices(void) {
  list_t *bonded_devices = list_new(osi_free);
  uint32_t i = 0;
  bt_property_t adapter_props[6];
  uint32_t num_props = 0;
  bt_property_t remote_properties[8]; // is 8 sufficient ?
  RawAddress addr;
  bt_bdname_t name, alias;
  bt_scan_mode_t mode;
  uint32_t disc_timeout;
  Uuid local_uuids[BT_MAX_NUM_UUIDS];
  Uuid remote_uuids[BT_MAX_NUM_UUIDS] = {};
  bt_status_t status;

  remove_devices_with_sample_ltk();

  btif_in_fetch_bonded_devices(&bonded_devices, 1);

  /* Now send the adapter_properties_cb with all adapter_properties */
  {
    memset(adapter_props, 0, sizeof(adapter_props));

    /* address */
    BTIF_STORAGE_GET_ADAPTER_PROP(status, BT_PROPERTY_BDADDR, &addr,
                                  sizeof(addr), adapter_props[num_props]);
    // Add BT_PROPERTY_BDADDR property into list only when successful.
    // Otherwise, skip this property entry.
    if (status == BT_STATUS_SUCCESS) {
      num_props++;
    }

    /* BD_NAME */
    BTIF_STORAGE_GET_ADAPTER_PROP(status, BT_PROPERTY_BDNAME, &name,
                                  sizeof(name), adapter_props[num_props]);
    num_props++;

    /* SCAN_MODE */
    /* TODO: At the time of BT on, always report the scan mode as 0 irrespective
     of the scan_mode during the previous enable cycle.
     This needs to be re-visited as part of the app/stack enable sequence
     synchronization */
    mode = BT_SCAN_MODE_NONE;
    adapter_props[num_props].type = BT_PROPERTY_ADAPTER_SCAN_MODE;
    adapter_props[num_props].len = sizeof(mode);
    adapter_props[num_props].val = &mode;
    num_props++;

    /* DISC_TIMEOUT */
    BTIF_STORAGE_GET_ADAPTER_PROP(status, BT_PROPERTY_ADAPTER_DISCOVERY_TIMEOUT,
                                  &disc_timeout, sizeof(disc_timeout),
                                  adapter_props[num_props]);
    num_props++;

    /* BONDED_DEVICES */
    RawAddress* devices_list = (RawAddress*)osi_malloc(
        sizeof(RawAddress) * list_length(bonded_devices));
    adapter_props[num_props].type = BT_PROPERTY_ADAPTER_BONDED_DEVICES;
    adapter_props[num_props].len =
        list_length(bonded_devices) * sizeof(RawAddress);
    adapter_props[num_props].val = devices_list;
    for (list_node_t* node = list_begin(bonded_devices);
      node != list_end(bonded_devices); node = list_next(node), i++) {
      memcpy(&devices_list[i], list_node(node), RawAddress::kLength);
    }
    num_props++;

    /* LOCAL UUIDs */
    BTIF_STORAGE_GET_ADAPTER_PROP(status, BT_PROPERTY_UUIDS, local_uuids,
                                  sizeof(local_uuids),
                                  adapter_props[num_props]);
    num_props++;

    btif_adapter_properties_evt(BT_STATUS_SUCCESS, num_props, adapter_props);

    osi_free(devices_list);
  }

  BTIF_TRACE_EVENT("%s: %zu bonded devices found", __func__,
                   list_length(bonded_devices));

  {
    for (list_node_t* node = list_begin(bonded_devices);
         node != list_end(bonded_devices); node = list_next(node)) {
      RawAddress* p_remote_addr;

      /*
       * TODO: improve handling of missing fields in NVRAM.
       */
      uint32_t cod = 0;
      uint32_t devtype = 0;
      int validAddr = 1;
      RawAddress mapping_addr;
      char group_details[512] = {0};

      num_props = 0;
      p_remote_addr = (RawAddress *)list_node(node);
      memset(remote_properties, 0, sizeof(remote_properties));
      memset(remote_uuids, 0, sizeof(remote_uuids));
      BTIF_STORAGE_GET_REMOTE_PROP(p_remote_addr,
          (bt_property_type_t)BT_PROPERTY_REM_DEViCE_VALID_ADDR,
          &validAddr, sizeof(int), remote_properties[num_props]);
      num_props++;

      BTIF_STORAGE_GET_REMOTE_PROP(p_remote_addr, BT_PROPERTY_BDNAME, &name,
                                   sizeof(name), remote_properties[num_props]);
      num_props++;

      BTIF_STORAGE_GET_REMOTE_PROP(p_remote_addr,
                                   BT_PROPERTY_REMOTE_FRIENDLY_NAME, &alias,
                                   sizeof(alias), remote_properties[num_props]);
      num_props++;

      BTIF_STORAGE_GET_REMOTE_PROP(p_remote_addr, BT_PROPERTY_CLASS_OF_DEVICE,
                                   &cod, sizeof(cod),
                                   remote_properties[num_props]);
      num_props++;

      BTIF_STORAGE_GET_REMOTE_PROP(p_remote_addr, BT_PROPERTY_TYPE_OF_DEVICE,
                                   &devtype, sizeof(devtype),
                                   remote_properties[num_props]);
      num_props++;

      char addr_map[1024] = "";
      int addr_len = RawAddress::kLength;
      BTIF_STORAGE_GET_REMOTE_PROP(p_remote_addr, (bt_property_type_t)BT_PROPERTY_REM_DEV_IDENT_BD_ADDR,
                                   addr_map, addr_len,
                                   remote_properties[num_props]);
      RawAddress::FromString(addr_map, mapping_addr);
      remote_properties[num_props].val = &mapping_addr;
      remote_properties[num_props].len = RawAddress::kLength;
      num_props++;

      btif_storage_get_remote_services(p_remote_addr, remote_uuids,
        sizeof(remote_uuids));


      remote_properties[num_props].val = remote_uuids;
      remote_properties[num_props].len = sizeof(remote_uuids);
      remote_properties[num_props].type = BT_PROPERTY_UUIDS;
      num_props++;
      for (int i = 0; i < BT_MAX_NUM_UUIDS; i++) {
        if (remote_uuids[i] != Uuid::kEmpty) {
          BTIF_TRACE_EVENT("%s: index %d UUID %s", __func__,
            i, remote_uuids[i].ToString().c_str());
        }
      }

      BTIF_STORAGE_GET_REMOTE_PROP(p_remote_addr, (bt_property_type_t)BT_PROPERTY_GROUP_DETAILS,
                                   group_details, sizeof(group_details),
                                   remote_properties[num_props]);

      BTIF_TRACE_EVENT("%s: num_props = %d group_details = %s",__func__ ,
                          num_props, group_details); //debug
      num_props++;
      btif_remote_properties_evt(BT_STATUS_SUCCESS, p_remote_addr, num_props,
                                 remote_properties);
    }
  }
  list_free(bonded_devices);
  return BT_STATUS_SUCCESS;
}

/*******************************************************************************
 *
 * Function         btif_storage_add_ble_bonding_key
 *
 * Description      BTIF storage API - Adds the newly bonded device to NVRAM
 *                  along with the ble-key, Key type and Pin key length
 *
 * Returns          BT_STATUS_SUCCESS if the store was successful,
 *                  BT_STATUS_FAIL otherwise
 *
 ******************************************************************************/

bt_status_t btif_storage_add_ble_bonding_key(RawAddress* remote_bd_addr,
                                             const uint8_t* key,
                                             uint8_t key_type,
                                             uint8_t key_length) {
  const char* name;
  switch (key_type) {
    case BTIF_DM_LE_KEY_PENC:
      name = "LE_KEY_PENC";
      break;
    case BTIF_DM_LE_KEY_PID:
      name = "LE_KEY_PID";
      break;
    case BTIF_DM_LE_KEY_PCSRK:
      name = "LE_KEY_PCSRK";
      break;
    case BTIF_DM_LE_KEY_LENC:
      name = "LE_KEY_LENC";
      break;
    case BTIF_DM_LE_KEY_LCSRK:
      name = "LE_KEY_LCSRK";
      break;
    case BTIF_DM_LE_KEY_LID:
      name = "LE_KEY_LID";
      break;
    default:
      return BT_STATUS_FAIL;
  }
  int ret = btif_config_set_bin(remote_bd_addr->ToString().c_str(), name, key,
                                key_length);
  btif_config_save();
  return ret ? BT_STATUS_SUCCESS : BT_STATUS_FAIL;
}

/*******************************************************************************
 *
 * Function         btif_storage_get_ble_bonding_key
 *
 * Description
 *
 * Returns          BT_STATUS_SUCCESS if the fetch was successful,
 *                  BT_STATUS_FAIL otherwise
 *
 ******************************************************************************/
bt_status_t btif_storage_get_ble_bonding_key(RawAddress* remote_bd_addr,
                                             uint8_t key_type,
                                             uint8_t* key_value,
                                             int key_length) {
  const char* name;
  switch (key_type) {
    case BTIF_DM_LE_KEY_PENC:
      name = "LE_KEY_PENC";
      break;
    case BTIF_DM_LE_KEY_PID:
      name = "LE_KEY_PID";
      break;
    case BTIF_DM_LE_KEY_PCSRK:
      name = "LE_KEY_PCSRK";
      break;
    case BTIF_DM_LE_KEY_LENC:
      name = "LE_KEY_LENC";
      break;
    case BTIF_DM_LE_KEY_LCSRK:
      name = "LE_KEY_LCSRK";
      break;
    case BTIF_DM_LE_KEY_LID:
      name = "LE_KEY_LID";
      break;
    default:
      return BT_STATUS_FAIL;
  }
  size_t length = key_length;
  int ret = btif_config_get_bin(remote_bd_addr->ToString().c_str(), name,
                                key_value, &length);
  return ret ? BT_STATUS_SUCCESS : BT_STATUS_FAIL;
}

/*******************************************************************************
 *
 * Function         btif_storage_remove_ble_keys
 *
 * Description      BTIF storage API - Deletes the bonded device from NVRAM
 *
 * Returns          BT_STATUS_SUCCESS if the deletion was successful,
 *                  BT_STATUS_FAIL otherwise
 *
 ******************************************************************************/
bt_status_t btif_storage_remove_ble_bonding_keys(
    const RawAddress* remote_bd_addr) {
  std::string addrstr = remote_bd_addr->ToString();
  const char* bdstr = addrstr.c_str();
  BTIF_TRACE_DEBUG(" %s in bd addr:%s", __func__, bdstr);
  int ret = 1;
  if (btif_config_exist(bdstr, "LE_KEY_PENC"))
    ret &= btif_config_remove(bdstr, "LE_KEY_PENC");
  if (btif_config_exist(bdstr, "LE_KEY_PID"))
    ret &= btif_config_remove(bdstr, "LE_KEY_PID");
  if (btif_config_exist(bdstr, "LE_KEY_PCSRK"))
    ret &= btif_config_remove(bdstr, "LE_KEY_PCSRK");
  if (btif_config_exist(bdstr, "LE_KEY_LENC"))
    ret &= btif_config_remove(bdstr, "LE_KEY_LENC");
  if (btif_config_exist(bdstr, "LE_KEY_LCSRK"))
    ret &= btif_config_remove(bdstr, "LE_KEY_LCSRK");
  if (btif_config_exist(bdstr, "LE_KEY_LID"))
    ret &= btif_config_remove(bdstr, "LE_KEY_LID");
  btif_config_save();
  return ret ? BT_STATUS_SUCCESS : BT_STATUS_FAIL;
}

/*******************************************************************************
 *
 * Function         btif_storage_add_ble_local_key
 *
 * Description      BTIF storage API - Adds the ble key to NVRAM
 *
 * Returns          BT_STATUS_SUCCESS if the store was successful,
 *                  BT_STATUS_FAIL otherwise
 *
 ******************************************************************************/
bt_status_t btif_storage_add_ble_local_key(const Octet16& key,
                                           uint8_t key_type) {
  const char* name;
  switch (key_type) {
    case BTIF_DM_LE_LOCAL_KEY_IR:
      name = "LE_LOCAL_KEY_IR";
      break;
    case BTIF_DM_LE_LOCAL_KEY_IRK:
      name = "LE_LOCAL_KEY_IRK";
      break;
    case BTIF_DM_LE_LOCAL_KEY_DHK:
      name = "LE_LOCAL_KEY_DHK";
      break;
    case BTIF_DM_LE_LOCAL_KEY_ER:
      name = "LE_LOCAL_KEY_ER";
      break;
    default:
      return BT_STATUS_FAIL;
  }
  int ret = btif_config_set_bin("Adapter", name, key.data(), key.size());
  btif_config_save();
  return ret ? BT_STATUS_SUCCESS : BT_STATUS_FAIL;
}

/** Stores local key of |key_type| into |key_value|
 * Returns BT_STATUS_SUCCESS if the fetch was successful, BT_STATUS_FAIL
 * otherwise
 */
bt_status_t btif_storage_get_ble_local_key(uint8_t key_type,
                                           Octet16* key_value) {
  const char* name;
  switch (key_type) {
    case BTIF_DM_LE_LOCAL_KEY_IR:
      name = "LE_LOCAL_KEY_IR";
      break;
    case BTIF_DM_LE_LOCAL_KEY_IRK:
      name = "LE_LOCAL_KEY_IRK";
      break;
    case BTIF_DM_LE_LOCAL_KEY_DHK:
      name = "LE_LOCAL_KEY_DHK";
      break;
    case BTIF_DM_LE_LOCAL_KEY_ER:
      name = "LE_LOCAL_KEY_ER";
      break;
    default:
      return BT_STATUS_FAIL;
  }
  size_t length = key_value->size();
  int ret = btif_config_get_bin("Adapter", name, key_value->data(), &length);
  return ret ? BT_STATUS_SUCCESS : BT_STATUS_FAIL;
}

/*******************************************************************************
 *
 * Function         btif_storage_remove_ble_local_keys
 *
 * Description      BTIF storage API - Deletes the bonded device from NVRAM
 *
 * Returns          BT_STATUS_SUCCESS if the deletion was successful,
 *                  BT_STATUS_FAIL otherwise
 *
 ******************************************************************************/
bt_status_t btif_storage_remove_ble_local_keys(void) {
  int ret = 1;
  if (btif_config_exist("Adapter", "LE_LOCAL_KEY_IR"))
    ret &= btif_config_remove("Adapter", "LE_LOCAL_KEY_IR");
  if (btif_config_exist("Adapter", "LE_LOCAL_KEY_IRK"))
    ret &= btif_config_remove("Adapter", "LE_LOCAL_KEY_IRK");
  if (btif_config_exist("Adapter", "LE_LOCAL_KEY_DHK"))
    ret &= btif_config_remove("Adapter", "LE_LOCAL_KEY_DHK");
  if (btif_config_exist("Adapter", "LE_LOCAL_KEY_ER"))
    ret &= btif_config_remove("Adapter", "LE_LOCAL_KEY_ER");
  btif_config_save();
  return ret ? BT_STATUS_SUCCESS : BT_STATUS_FAIL;
}

static bt_status_t btif_in_fetch_bonded_ble_device(
    const char* remote_bd_addr, int add,
    list_t** p_bonded_devices) {
  int device_type;
  int addr_type;
  bool device_added = false;
  bool key_found = false;

  if (!btif_config_get_int(remote_bd_addr, "DevType", &device_type))
    return BT_STATUS_FAIL;

  if ((device_type & BT_DEVICE_TYPE_BLE) == BT_DEVICE_TYPE_BLE ||
      btif_has_ble_keys(remote_bd_addr)) {
    BTIF_TRACE_DEBUG("%s Found a LE device: %s", __func__, remote_bd_addr);

    RawAddress bd_addr;
    RawAddress::FromString(remote_bd_addr, bd_addr);

    if (btif_storage_get_remote_addr_type(&bd_addr, &addr_type) !=
        BT_STATUS_SUCCESS) {
      /* Try to read address type from device info, if not present,
      then it defaults to BLE_ADDR_PUBLIC */
      uint8_t tmp_dev_type;
      uint8_t tmp_addr_type;
      BTM_ReadDevInfo(bd_addr, &tmp_dev_type, &tmp_addr_type);
      addr_type = tmp_addr_type;

      btif_storage_set_remote_addr_type(&bd_addr, addr_type);
    }

    btif_read_le_key(BTIF_DM_LE_KEY_PENC, sizeof(tBTM_LE_PENC_KEYS), bd_addr,
                     addr_type, add, &device_added, &key_found);

    btif_read_le_key(BTIF_DM_LE_KEY_PID, sizeof(tBTM_LE_PID_KEYS), bd_addr,
                     addr_type, add, &device_added, &key_found);

    btif_read_le_key(BTIF_DM_LE_KEY_LID, sizeof(tBTM_LE_PID_KEYS), bd_addr,
                     addr_type, add, &device_added, &key_found);

    btif_read_le_key(BTIF_DM_LE_KEY_PCSRK, sizeof(tBTM_LE_PCSRK_KEYS), bd_addr,
                     addr_type, add, &device_added, &key_found);

    btif_read_le_key(BTIF_DM_LE_KEY_LENC, sizeof(tBTM_LE_LENC_KEYS), bd_addr,
                     addr_type, add, &device_added, &key_found);

    btif_read_le_key(BTIF_DM_LE_KEY_LCSRK, sizeof(tBTM_LE_LCSRK_KEYS), bd_addr,
                     addr_type, add, &device_added, &key_found);

    // Fill in the bonded devices
    if (device_added) {
        RawAddress *remote_addr =  (RawAddress*)osi_malloc(sizeof(RawAddress));
        memcpy(remote_addr, &bd_addr, RawAddress::kLength);
        list_append(*p_bonded_devices, remote_addr);
        btif_gatts_add_bonded_dev_from_nv(bd_addr);
    }

    if (key_found) return BT_STATUS_SUCCESS;
  }
  return BT_STATUS_FAIL;
}

bt_status_t btif_storage_set_remote_addr_type(const RawAddress* remote_bd_addr,
                                              uint8_t addr_type) {
  int ret = btif_config_set_int(remote_bd_addr->ToString().c_str(), "AddrType",
                                (int)addr_type);
  return ret ? BT_STATUS_SUCCESS : BT_STATUS_FAIL;
}

bool btif_has_ble_keys(const char* bdstr) {
  return btif_config_exist(bdstr, "LE_KEY_PENC");
}

/*******************************************************************************
 *
 * Function         btif_storage_get_remote_addr_type
 *
 * Description      BTIF storage API - Fetches the remote addr type
 *
 * Returns          BT_STATUS_SUCCESS if the fetch was successful,
 *                  BT_STATUS_FAIL otherwise
 *
 ******************************************************************************/
bt_status_t btif_storage_get_remote_addr_type(const RawAddress* remote_bd_addr,
                                              int* addr_type) {
  int ret = btif_config_get_int(remote_bd_addr->ToString().c_str(), "AddrType",
                                addr_type);
  return ret ? BT_STATUS_SUCCESS : BT_STATUS_FAIL;
}
/*******************************************************************************
 *
 * Function         btif_storage_add_hid_device_info
 *
 * Description      BTIF storage API - Adds the hid information of bonded hid
 *                  devices-to NVRAM
 *
 * Returns          BT_STATUS_SUCCESS if the store was successful,
 *                  BT_STATUS_FAIL otherwise
 *
 ******************************************************************************/

bt_status_t btif_storage_add_hid_device_info(
    RawAddress* remote_bd_addr, uint16_t attr_mask, uint8_t sub_class,
    uint8_t app_id, uint16_t vendor_id, uint16_t product_id, uint16_t version,
    uint8_t ctry_code, uint16_t ssr_max_latency, uint16_t ssr_min_tout,
    uint16_t dl_len, uint8_t* dsc_list) {
  BTIF_TRACE_DEBUG("btif_storage_add_hid_device_info:");
  std::string addrstr = remote_bd_addr->ToString();
  const char* bdstr = addrstr.c_str();
  btif_config_set_int(bdstr, "HidAttrMask", attr_mask);
  btif_config_set_int(bdstr, "HidSubClass", sub_class);
  btif_config_set_int(bdstr, "HidAppId", app_id);
  btif_config_set_int(bdstr, "HidVendorId", vendor_id);
  btif_config_set_int(bdstr, "HidProductId", product_id);
  btif_config_set_int(bdstr, "HidVersion", version);
  btif_config_set_int(bdstr, "HidCountryCode", ctry_code);
  btif_config_set_int(bdstr, "HidSSRMaxLatency", ssr_max_latency);
  btif_config_set_int(bdstr, "HidSSRMinTimeout", ssr_min_tout);
  if (dl_len > 0) btif_config_set_bin(bdstr, "HidDescriptor", dsc_list, dl_len);
  btif_config_save();
  return BT_STATUS_SUCCESS;
}

/*******************************************************************************
 *
 * Function         btif_storage_load_bonded_hid_info
 *
 * Description      BTIF storage API - Loads hid info for all the bonded devices
 *                  from NVRAM and adds those devices  to the BTA_HH.
 *
 * Returns          BT_STATUS_SUCCESS if successful, BT_STATUS_FAIL otherwise
 *
 ******************************************************************************/
bt_status_t btif_storage_load_bonded_hid_info(void) {
  RawAddress bd_addr;
  tBTA_HH_DEV_DSCP_INFO dscp_info;
  uint16_t attr_mask;
  uint8_t sub_class;
  uint8_t app_id;
  int     dev_type;

  memset(&dscp_info, 0, sizeof(dscp_info));
  for (const btif_config_section_iter_t* iter = btif_config_section_begin();
       iter != btif_config_section_end();
       iter = btif_config_section_next(iter)) {
    const char* name = btif_config_section_name(iter);
    if (!RawAddress::IsValidAddress(name)) continue;

    BTIF_TRACE_DEBUG("Remote device:%s", name);
    int value;
    if (btif_in_fetch_bonded_device(name, &dev_type) == BT_STATUS_SUCCESS) {
      if (btif_config_get_int(name, "HidAttrMask", &value)) {
        attr_mask = (uint16_t)value;

        btif_config_get_int(name, "HidSubClass", &value);
        sub_class = (uint8_t)value;

        btif_config_get_int(name, "HidAppId", &value);
        app_id = (uint8_t)value;

        btif_config_get_int(name, "HidVendorId", &value);
        dscp_info.vendor_id = (uint16_t)value;

        btif_config_get_int(name, "HidProductId", &value);
        dscp_info.product_id = (uint16_t)value;

        btif_config_get_int(name, "HidVersion", &value);
        dscp_info.version = (uint8_t)value;

        btif_config_get_int(name, "HidCountryCode", &value);
        dscp_info.ctry_code = (uint8_t)value;

        value = 0;
        btif_config_get_int(name, "HidSSRMaxLatency", &value);
        dscp_info.ssr_max_latency = (uint16_t)value;

        value = 0;
        btif_config_get_int(name, "HidSSRMinTimeout", &value);
        dscp_info.ssr_min_tout = (uint16_t)value;

        size_t len = btif_config_get_bin_length(name, "HidDescriptor");
        if (len > 0) {
          dscp_info.descriptor.dl_len = (uint16_t)len;
          dscp_info.descriptor.dsc_list = (uint8_t*)alloca(len);
          btif_config_get_bin(name, "HidDescriptor",
                              (uint8_t*)dscp_info.descriptor.dsc_list, &len);
        }
        RawAddress::FromString(name, bd_addr);
        // add extracted information to BTA HH
        if (btif_hh_add_added_dev(bd_addr, attr_mask)) {
          BTA_HhAddDev(bd_addr, attr_mask, sub_class, app_id, dscp_info);
        }
      }
    } else {
      if (btif_config_get_int(name, "HidAttrMask", &value)) {
        RawAddress::FromString(name, bd_addr);
        btif_storage_remove_hid_info(&bd_addr);
      }
    }
  }

  return BT_STATUS_SUCCESS;
}

/*******************************************************************************
 *
 * Function         btif_storage_remove_hid_info
 *
 * Description      BTIF storage API - Deletes the bonded hid device info from
 *                  NVRAM
 *
 * Returns          BT_STATUS_SUCCESS if the deletion was successful,
 *                  BT_STATUS_FAIL otherwise
 *
 ******************************************************************************/
bt_status_t btif_storage_remove_hid_info(RawAddress* remote_bd_addr) {
  std::string addrstr = remote_bd_addr->ToString();
  const char* bdstr = addrstr.c_str();

  btif_config_remove(bdstr, "HidAttrMask");
  btif_config_remove(bdstr, "HidSubClass");
  btif_config_remove(bdstr, "HidAppId");
  btif_config_remove(bdstr, "HidVendorId");
  btif_config_remove(bdstr, "HidProductId");
  btif_config_remove(bdstr, "HidVersion");
  btif_config_remove(bdstr, "HidCountryCode");
  btif_config_remove(bdstr, "HidSSRMaxLatency");
  btif_config_remove(bdstr, "HidSSRMinTimeout");
  btif_config_remove(bdstr, "HidDescriptor");
  btif_config_save();
  return BT_STATUS_SUCCESS;
}

constexpr char HEARING_AID_READ_PSM_HANDLE[] = "HearingAidReadPsmHandle";
constexpr char HEARING_AID_CAPABILITIES[] = "HearingAidCapabilities";
constexpr char HEARING_AID_CODECS[] = "HearingAidCodecs";
constexpr char HEARING_AID_AUDIO_CONTROL_POINT[] =
    "HearingAidAudioControlPoint";
constexpr char HEARING_AID_VOLUME_HANDLE[] = "HearingAidVolumeHandle";
constexpr char HEARING_AID_AUDIO_STATUS_HANDLE[] =
    "HearingAidAudioStatusHandle";
constexpr char HEARING_AID_AUDIO_STATUS_CCC_HANDLE[] =
    "HearingAidAudioStatusCccHandle";
constexpr char HEARING_AID_SERVICE_CHANGED_CCC_HANDLE[] =
    "HearingAidServiceChangedCccHandle";
constexpr char HEARING_AID_SYNC_ID[] = "HearingAidSyncId";
constexpr char HEARING_AID_RENDER_DELAY[] = "HearingAidRenderDelay";
constexpr char HEARING_AID_PREPARATION_DELAY[] = "HearingAidPreparationDelay";
constexpr char HEARING_AID_IS_ACCEPTLISTED[] = "HearingAidIsAcceptlisted";

void btif_storage_add_hearing_aid(const HearingDevice& dev_info) {
  do_in_jni_thread(
      FROM_HERE,
      Bind(
          [](const HearingDevice& dev_info) {
            std::string addrstr = dev_info.address.ToString();
            const char *bdstr = addrstr.c_str();
            VLOG(2) << "saving hearing aid device: " << bdstr;
            btif_config_set_int(bdstr, HEARING_AID_SERVICE_CHANGED_CCC_HANDLE,
                                dev_info.service_changed_ccc_handle);
            btif_config_set_int(bdstr, HEARING_AID_READ_PSM_HANDLE,
                                dev_info.read_psm_handle);
            btif_config_set_int(bdstr, HEARING_AID_CAPABILITIES,
                                dev_info.capabilities);
            btif_config_set_int(bdstr, HEARING_AID_CODECS, dev_info.codecs);
            btif_config_set_int(bdstr, HEARING_AID_AUDIO_CONTROL_POINT,
                                dev_info.audio_control_point_handle);
            btif_config_set_int(bdstr, HEARING_AID_VOLUME_HANDLE,
                                dev_info.volume_handle);
            btif_config_set_int(bdstr, HEARING_AID_AUDIO_STATUS_HANDLE,
                                dev_info.audio_status_handle);
            btif_config_set_int(bdstr, HEARING_AID_AUDIO_STATUS_CCC_HANDLE,
                                dev_info.audio_status_ccc_handle);
            btif_config_set_uint64(bdstr, HEARING_AID_SYNC_ID,
                                   dev_info.hi_sync_id);
            btif_config_set_int(bdstr, HEARING_AID_RENDER_DELAY,
                                dev_info.render_delay);
            btif_config_set_int(bdstr, HEARING_AID_PREPARATION_DELAY,
                                dev_info.preparation_delay);
            btif_config_set_int(bdstr, HEARING_AID_IS_ACCEPTLISTED, true);
            btif_config_save();
          },
          dev_info));
}

/** Loads information about bonded hearing aid devices */
void btif_storage_load_bonded_hearing_aids() {
  // TODO: this code is not thread safe, it can corrupt config content.
  // b/67595284
  int device_type;

  for (const btif_config_section_iter_t* iter = btif_config_section_begin();
       iter != btif_config_section_end();
       iter = btif_config_section_next(iter)) {
    const char* name = btif_config_section_name(iter);
    if (!RawAddress::IsValidAddress(name)) continue;

    int size = STORAGE_UUID_STRING_SIZE * HEARINGAID_MAX_NUM_UUIDS;
    char uuid_str[size];
    bool isHearingaidDevice = false;
    if (btif_config_get_str(name, BTIF_STORAGE_PATH_REMOTE_SERVICE, uuid_str,
                            &size)) {
      Uuid p_uuid[HEARINGAID_MAX_NUM_UUIDS];
      size_t num_uuids =
          btif_split_uuids_string(uuid_str, p_uuid, HEARINGAID_MAX_NUM_UUIDS);
      for (size_t i = 0; i < num_uuids; i++) {
        if (p_uuid[i] == Uuid::FromString("FDF0")) {
          isHearingaidDevice = true;
          break;
        }
      }
    }
    if (!isHearingaidDevice) {
      continue;
    }

    BTIF_TRACE_DEBUG("Remote device:%s", name);

    if (btif_in_fetch_bonded_device(name, &device_type) != BT_STATUS_SUCCESS) {
      RawAddress bd_addr;
      RawAddress::FromString(name, bd_addr);
      btif_storage_remove_hearing_aid(bd_addr);
      continue;
    }

    int value;
    uint8_t capabilities = 0;
    if (btif_config_get_int(name, HEARING_AID_CAPABILITIES, &value))
      capabilities = value;

    uint16_t codecs = 0;
    if (btif_config_get_int(name, HEARING_AID_CODECS, &value)) codecs = value;

    uint16_t audio_control_point_handle = 0;
    if (btif_config_get_int(name, HEARING_AID_AUDIO_CONTROL_POINT, &value))
      audio_control_point_handle = value;

    uint16_t audio_status_handle = 0;
    if (btif_config_get_int(name, HEARING_AID_AUDIO_STATUS_HANDLE, &value))
      audio_status_handle = value;

    uint16_t audio_status_ccc_handle = 0;
    if (btif_config_get_int(name, HEARING_AID_AUDIO_STATUS_CCC_HANDLE, &value))
      audio_status_ccc_handle = value;

    uint16_t service_changed_ccc_handle = 0;
    if (btif_config_get_int(name, HEARING_AID_SERVICE_CHANGED_CCC_HANDLE,
                            &value))
      service_changed_ccc_handle = value;

    uint16_t volume_handle = 0;
    if (btif_config_get_int(name, HEARING_AID_VOLUME_HANDLE, &value))
      volume_handle = value;

    uint16_t read_psm_handle = 0;
    if (btif_config_get_int(name, HEARING_AID_READ_PSM_HANDLE, &value))
      read_psm_handle = value;

    uint64_t lvalue;
    uint64_t hi_sync_id = 0;
    if (btif_config_get_uint64(name, HEARING_AID_SYNC_ID, &lvalue))
      hi_sync_id = lvalue;

    uint16_t render_delay = 0;
    if (btif_config_get_int(name, HEARING_AID_RENDER_DELAY, &value))
      render_delay = value;

    uint16_t preparation_delay = 0;
    if (btif_config_get_int(name, HEARING_AID_PREPARATION_DELAY, &value))
      preparation_delay = value;

    uint16_t is_acceptlisted = 0;
    if (btif_config_get_int(name, HEARING_AID_IS_ACCEPTLISTED, &value))
      is_acceptlisted = value;

    RawAddress bd_addr;
    RawAddress::FromString(name, bd_addr);

    // add extracted information to BTA Hearing Aid
    do_in_bta_thread(
        FROM_HERE,
        Bind(&HearingAid::AddFromStorage,
             HearingDevice(bd_addr, capabilities, codecs,
                           audio_control_point_handle, audio_status_handle,
                           audio_status_ccc_handle, service_changed_ccc_handle,
                           volume_handle, read_psm_handle, hi_sync_id,
                           render_delay, preparation_delay),
             is_acceptlisted));
  }
}

/** Deletes the bonded hearing aid device info from NVRAM */
void btif_storage_remove_hearing_aid(const RawAddress& address) {
  std::string bdstr = address.ToString();
  const char *addrstr = bdstr.c_str();

  btif_config_remove(addrstr, HEARING_AID_READ_PSM_HANDLE);
  btif_config_remove(addrstr, HEARING_AID_CAPABILITIES);
  btif_config_remove(addrstr, HEARING_AID_CODECS);
  btif_config_remove(addrstr, HEARING_AID_AUDIO_CONTROL_POINT);
  btif_config_remove(addrstr, HEARING_AID_VOLUME_HANDLE);
  btif_config_remove(addrstr, HEARING_AID_AUDIO_STATUS_HANDLE);
  btif_config_remove(addrstr, HEARING_AID_AUDIO_STATUS_CCC_HANDLE);
  btif_config_remove(addrstr, HEARING_AID_SERVICE_CHANGED_CCC_HANDLE);
  btif_config_remove(addrstr, HEARING_AID_SYNC_ID);
  btif_config_remove(addrstr, HEARING_AID_RENDER_DELAY);
  btif_config_remove(addrstr, HEARING_AID_PREPARATION_DELAY);
  btif_config_remove(addrstr, HEARING_AID_IS_ACCEPTLISTED);
  btif_config_save();
}

/** Set/Unset the hearing aid device HEARING_AID_IS_WHITE_LISTED flag. */
void btif_storage_set_hearing_aid_acceptlist(const RawAddress& address,
                                             bool add_to_acceptlist) {
  std::string addrstr = address.ToString();
  const char *bdstr = addrstr.c_str();
  btif_config_set_int(bdstr, HEARING_AID_IS_ACCEPTLISTED, add_to_acceptlist);
  btif_config_save();
}

/** Get the hearing aid device properties. */
bool btif_storage_get_hearing_aid_prop(
    const RawAddress& address, uint8_t* capabilities, uint64_t* hi_sync_id,
    uint16_t* render_delay, uint16_t* preparation_delay, uint16_t* codecs) {
  std::string bdstr = address.ToString();
  const char *addrstr = bdstr.c_str();

  int value;
  if (btif_config_get_int(addrstr, HEARING_AID_CAPABILITIES, &value)) {
    *capabilities = value;
  } else {
    return false;
  }

  if (btif_config_get_int(addrstr, HEARING_AID_CODECS, &value)) {
    *codecs = value;
  } else {
    return false;
  }

  if (btif_config_get_int(addrstr, HEARING_AID_RENDER_DELAY, &value)) {
    *render_delay = value;
  } else {
    return false;
  }

  if (btif_config_get_int(addrstr, HEARING_AID_PREPARATION_DELAY, &value)) {
    *preparation_delay = value;
  } else {
    return false;
  }

  uint64_t lvalue;
  if (btif_config_get_uint64(addrstr, HEARING_AID_SYNC_ID, &lvalue)) {
    *hi_sync_id = lvalue;
  } else {
    return false;
  }

  return true;
}

/*******************************************************************************
 *
 * Function         btif_storage_is_restricted_device
 *
 * Description      BTIF storage API - checks if this device is a restricted
 *                  device
 *
 * Returns          true  if the device is labeled as restricted
 *                  false otherwise
 *
 ******************************************************************************/
bool btif_storage_is_restricted_device(const RawAddress* remote_bd_addr) {
  return btif_config_exist(remote_bd_addr->ToString().c_str(), "Restricted");
}

int btif_storage_get_num_bonded_devices(void) {
  uint32_t num_bonded_devices = 0;
  list_t *bonded_devices = list_new(osi_free);
  btif_in_fetch_bonded_devices(&bonded_devices, 0);
  if (bonded_devices != NULL) {
    num_bonded_devices = list_length(bonded_devices);
    list_free(bonded_devices);
  }
  return num_bonded_devices;
}

/*******************************************************************************
 * Function         btif_storage_load_hidd
 *
 * Description      Loads hidd bonded device and "plugs" it into hidd
 *
 * Returns          BT_STATUS_SUCCESS if successful, BT_STATUS_FAIL otherwise
 *
 ******************************************************************************/
bt_status_t btif_storage_load_hidd(void) {
  int dev_type;

  for (const btif_config_section_iter_t* iter = btif_config_section_begin();
       iter != btif_config_section_end();
       iter = btif_config_section_next(iter)) {
    const char* name = btif_config_section_name(iter);
    if (!RawAddress::IsValidAddress(name)) continue;

    BTIF_TRACE_DEBUG("Remote device:%s", name);
    int value;
    if (btif_in_fetch_bonded_device(name, &dev_type) == BT_STATUS_SUCCESS) {
      if (btif_config_get_int(name, "HidDeviceCabled", &value)) {
        RawAddress bd_addr;
        RawAddress::FromString(name, bd_addr);
        BTA_HdAddDevice(bd_addr);
        break;
      }
    }
  }

  return BT_STATUS_SUCCESS;
}

/*******************************************************************************
 *
 * Function         btif_storage_set_hidd
 *
 * Description      Stores hidd bonded device info in nvram.
 *
 * Returns          BT_STATUS_SUCCESS
 *
 ******************************************************************************/
bt_status_t btif_storage_set_hidd(RawAddress* remote_bd_addr) {
  btif_config_set_int(remote_bd_addr->ToString().c_str(), "HidDeviceCabled", 1);
  btif_config_save();
  return BT_STATUS_SUCCESS;
}

/*******************************************************************************
 *
 * Function         btif_storage_remove_hidd
 *
 * Description      Removes hidd bonded device info from nvram
 *
 * Returns          BT_STATUS_SUCCESS
 *
 ******************************************************************************/
bt_status_t btif_storage_remove_hidd(RawAddress* remote_bd_addr) {
  btif_config_remove(remote_bd_addr->ToString().c_str(), "HidDeviceCabled");
  btif_config_save();

  return BT_STATUS_SUCCESS;
}

// Get the name of a device from btif for interop database matching.
bool btif_storage_get_stored_remote_name(const RawAddress& bd_addr,
                                         char* name) {
  bt_property_t property;
  property.type = BT_PROPERTY_BDNAME;
  property.len = BTM_MAX_REM_BD_NAME_LEN;
  property.val = name;

  return (btif_storage_get_remote_device_property(&bd_addr, &property) ==
          BT_STATUS_SUCCESS);
}

/*******************************************************************************
 *
 * Function         btif_storage_load_bonded_eatt_devices
 *
 * Description      BTIF storage API - Loads all the bonded devices from NVRAM
 *                  with EATT support.
 *
 * Returns          void
 *
 ******************************************************************************/
void btif_storage_load_bonded_eatt_devices() {
  RawAddress bd_addr;
  int is_eatt_supported = 0;

  for (const btif_config_section_iter_t* iter = btif_config_section_begin();
       iter != btif_config_section_end(); iter = btif_config_section_next(iter)) {
    const char* name = btif_config_section_name(iter);
    if (!RawAddress::IsValidAddress(name)) continue;

    btif_config_get_int(name, BTIF_STORAGE_KEY_EATT_SUPPORT,
                        &is_eatt_supported);
    if (!is_eatt_supported) {
      continue;
    }

    RawAddress::FromString(name, bd_addr);
    BTIF_TRACE_DEBUG("BD addr :%s", bd_addr.ToString().c_str());
    gatt_add_eatt_device(bd_addr);
  }
}

/*******************************************************************************
 *
 * Function         btif_storage_add_eatt_support
 *
 * Description      BTIF storage API - Add EATT support for bd_addr
 *                  in btif storage.
 *
 * Returns          void
 *
 ******************************************************************************/
void btif_storage_add_eatt_support(const RawAddress& bd_addr) {
  do_in_jni_thread(FROM_HERE,
                   Bind(
                       [](const RawAddress& bd_addr) {
                         std::string bda_str = bd_addr.ToString();
                         btif_config_set_int(
                             bda_str.c_str(), BTIF_STORAGE_KEY_EATT_SUPPORT, true);
                         btif_config_save();
                       },
                       bd_addr));
}

/*******************************************************************************
 *
 * Function         btif_storage_get_cl_supp_feat
 *
 * Description      BTIF storage API - Get client supported features characteristic
 *                  value for a remote bda from btif storage.
 *
 *
 * Returns          value of the characteristic
 *
 ******************************************************************************/
uint8_t btif_storage_get_cl_supp_feat(const RawAddress& bda) {
  std::string bda_str = bda.ToString();
  int value = 0;

  btif_config_get_int(bda_str.c_str(), BTIF_STORAGE_KEY_CLIENT_SUPP_FEAT, &value);
  return value;
}

void btif_storage_set_cl_supp_feat(const RawAddress& bda, uint8_t value) {
  do_in_jni_thread(
      FROM_HERE, Bind(
                     [](const RawAddress& bda, uint8_t value) {
                       std::string bda_str = bda.ToString();
                       btif_config_set_int(
                           bda_str.c_str(), BTIF_STORAGE_KEY_CLIENT_SUPP_FEAT, value);
                       btif_config_save();
                     },
                     bda, value));
}

RawAddress btif_get_map_address(RawAddress bda) {
  char addr_map[1024] = "";
  int addr_len = 1024;
  RawAddress mapping_addr = RawAddress::kEmpty;
  bt_property_t addr_map_prop;

  std::string addrstr = bda.ToString();
  const char* bdstr = addrstr.c_str();
  if (btif_config_exist(bdstr, "MapAddr")) {
    BTIF_STORAGE_GET_REMOTE_PROP(&bda, (bt_property_type_t)BT_PROPERTY_REM_DEV_IDENT_BD_ADDR,
        addr_map, addr_len,
        addr_map_prop);
    RawAddress::FromString(addr_map, mapping_addr);
  } else {
    BTIF_TRACE_DEBUG("%s Configure entry not present ", __func__);
  }

  return mapping_addr;
}

/*
 * Whenever calling this API, Please guard the call with
 * ADV_AUDIO_FEATURE flag. This API is used by ADV_AUDIO feature only.
 */
int btif_get_is_adv_audio_pair_info(RawAddress bda) {
  int is_adv_audio = 0;
  bt_property_t get_adv_audio_support;

  std::string addrstr = bda.ToString();
  const char* bdstr = addrstr.c_str();
  if (btif_config_exist(bdstr, "IsAdvAudio")) {
    BTIF_STORAGE_GET_REMOTE_PROP(&bda, (bt_property_type_t)BT_PROPERTY_REM_DEV_IS_ADV_AUDIO,
        &is_adv_audio, sizeof(is_adv_audio),
        get_adv_audio_support);
    BTIF_TRACE_DEBUG("%s is_adv_audio %d", __func__, is_adv_audio);
  } else {
    BTIF_TRACE_DEBUG("%s Configure entry not present ", __func__);
  }

  return is_adv_audio;
}
