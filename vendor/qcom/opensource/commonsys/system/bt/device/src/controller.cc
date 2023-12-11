/******************************************************************************
 *
 *  Copyright (C) 2014 Google, Inc.
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

#define LOG_TAG "bt_controller"

#include "device/include/controller.h"

#include <base/logging.h>

#include "bt_types.h"
#include "btcore/include/event_mask.h"
#include "btcore/include/module.h"
#include "btcore/include/version.h"
#include "hcimsgs.h"
#include "osi/include/future.h"
#include "osi/include/properties.h"
#include "stack/include/btm_ble_api.h"
#include "osi/include/log.h"
#include "utils/include/bt_utils.h"
#include <hardware/bt_av.h>
#include "bt_configstore.h"
#include <dlfcn.h>
#include <vector>
#include "stack_config.h"
#include <map>
#include "device/include/interop_config.h"
#include "device/include/profile_config.h"

#define BTSNOOP_ENABLE_PROPERTY "persist.bluetooth.btsnoopenable"
#define BTSNOOP_SOCLOG_PROPERTY "persist.vendor.service.bdroid.soclog"

const bt_event_mask_t BLE_EVENT_MASK = {
    {0x00, 0x00, 0x00, 0x02, 0x4F, 0x0B, 0xFE, 0x7f}};

const bt_event_mask_t CLASSIC_EVENT_MASK = {HCI_DUMO_EVENT_MASK_EXT};

// TODO(zachoverflow): factor out into common module
const uint8_t SCO_HOST_BUFFER_SIZE = 0xff;

#define HCI_SUPPORTED_COMMANDS_ARRAY_SIZE 64
#define MAX_FEATURES_CLASSIC_PAGE_COUNT 3
#define BLE_SUPPORTED_STATES_SIZE 8
#define BLE_SUPPORTED_FEATURES_SIZE 8
#define MAX_LOCAL_SUPPORTED_CODECS_SIZE 8
#define MAX_SUPPORTED_SCRAMBLING_FREQ_SIZE 8
#define MAX_SCRAMBLING_FREQS_SIZE 64
#define ISO_CHANNEL_HOST_SUPPORT_BIT 32
#define UNUSED(x) (void)(x)

#define QHS_TRANSPORT_BREDR 0
#define QHS_TRANSPORT_LE 1
#define QHS_TRANSPORT_LE_ISO 2

/* Disable QHS */
#define QHS_HOST_MODE_HOST_DISABLE 0
/* Enable QHS support */
#define QHS_HOST_MODE_HOST_AWARE 3
/* Disable QHS, QLL and QLMP modes */
#define QHS_HOST_DISABLE_ALL 4

#define QHS_BREDR_MASK 0x01
#define QHS_LE_MASK 0x02
#define QHS_LE_ISO_MASK 0x04

const bt_event_mask_t QBCE_QLM_AND_QLL_EVENT_MASK = {
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x42}};

static const hci_t* hci;
static const hci_packet_factory_t* packet_factory;
static const hci_packet_parser_t* packet_parser;

static RawAddress address;
static bt_version_t bt_version;

static uint8_t supported_commands[HCI_SUPPORTED_COMMANDS_ARRAY_SIZE];
static bt_device_features_t features_classic[MAX_FEATURES_CLASSIC_PAGE_COUNT];
static uint8_t last_features_classic_page_index;

static uint16_t acl_data_size_classic;
static uint16_t acl_data_size_ble;
static uint16_t iso_data_packet_len;
static uint16_t acl_buffer_count_classic;
static uint8_t acl_buffer_count_ble;
static uint8_t total_num_iso_data_packets;

static uint8_t ble_white_list_size;
static uint8_t ble_resolving_list_max_size;
static uint8_t ble_supported_states[BLE_SUPPORTED_STATES_SIZE];
static bt_device_features_t features_ble;
static uint16_t ble_suggested_default_data_length;
static uint16_t ble_maxium_advertising_data_length;
static uint8_t ble_number_of_supported_advertising_sets;
static uint8_t local_supported_codecs[MAX_LOCAL_SUPPORTED_CODECS_SIZE];
static uint8_t std_codec_tx[MAX_LOCAL_SUPPORTED_CODECS_SIZE];
static uint32_t vs_supported_codecs[MAX_LOCAL_SUPPORTED_CODECS_SIZE];
static uint8_t vs_codec_tx[MAX_LOCAL_SUPPORTED_CODECS_SIZE];
static uint8_t scrambling_supported_freqs[MAX_SUPPORTED_SCRAMBLING_FREQ_SIZE];
static uint8_t number_of_local_supported_codecs = 0;
static uint8_t number_of_vs_supported_codecs = 0;
static uint8_t number_of_scrambling_supported_freqs = 0;
static bt_device_soc_add_on_features_t soc_add_on_features;
static uint8_t soc_add_on_features_length = 0;
static uint16_t product_id, response_version;
static bt_device_host_add_on_features_t host_add_on_features;
static uint8_t host_add_on_features_length = 0;
static uint8_t simple_pairing_options = 0;
static uint8_t maximum_encryption_key_size = 0;

static bool readable;
static bool ble_supported;
static bool ble_offload_features_supported;
static bool simple_pairing_supported;
static bool secure_connections_supported;
static bool read_simple_pairing_options_supported;
static bool hci_write_rf_path_compensation_supported;

//BT features related defines
static bt_soc_type_t soc_type = BT_SOC_TYPE_DEFAULT;
static char a2dp_offload_Cap[PROPERTY_VALUE_MAX] = {'\0'};
static bool spilt_a2dp_supported = true;
static bool wipower_supported = false;
static bool aac_frame_ctl_enabled = false;

static bool a2dp_multicast_enabled = false;
static bool twsp_state_supported = false;
static bool max_power_prop_enabled = false;
static uint8_t max_power_prop_value[3];
static bt_configstore_interface_t* bt_configstore_intf = NULL;
static void *bt_configstore_lib_handle = NULL;

static int load_bt_configstore_lib();
bool decode_max_power_values(char *);

// map of codec and its transport
std::map<uint8_t, uint8_t> std_codec_transport;
std::map<uint32_t, uint8_t> vs_codec_transport;

uint8_t g_adv_audio_prop = 0;

void update_soc_codec_transport();

#define AWAIT_COMMAND(command) \
  static_cast<BT_HDR*>(future_await(hci->transmit_command_futured(command)))

// Module lifecycle functions

void send_soc_log_command(bool value) {
  uint8_t param[5] = {0x10,0x03,0x00,0x00,0x01};
  uint8_t param_cherokee[2] = {0x14, 0x01};
  if (!value) {
   // Disable SoC logging
    param[1] = 0x02;
    param_cherokee[1] = 0x00;
  }

  if (soc_type == BT_SOC_TYPE_SMD) {
    LOG_INFO(LOG_TAG, "%s for BT_SOC_SMD.", __func__);
    BTM_VendorSpecificCommand(HCI_VS_HOST_LOG_OPCODE,5,param,NULL);
  } else if (soc_type >= BT_SOC_TYPE_CHEROKEE) {
    LOG_INFO(LOG_TAG, "%s for soc_type: %d", __func__, soc_type);
    BTM_VendorSpecificCommand(HCI_VS_HOST_LOG_OPCODE, 2, param_cherokee, NULL);
  }
}

static bool is_soc_logging_enabled() {
  char btsnoop_enabled[PROPERTY_VALUE_MAX] = "false";
  char btsoclog_enabled[PROPERTY_VALUE_MAX] = {0};
  char donglemode_prop[PROPERTY_VALUE_MAX] = "false";

  if(osi_property_get("persist.bluetooth.donglemode", donglemode_prop, "false") &&
      !strcmp(donglemode_prop, "true")) {
    return false;
  }
  osi_property_get(BTSNOOP_SOCLOG_PROPERTY, btsoclog_enabled, "not-set");

  /*
   * For SMD targets, always check if snoop logs are enabled and
   * ignore the soclog property.
   * For other targets, if soclog property is set, stack doesn't need to
   * send VSC command as BT transport driver will send the command during patch
   * download
   */
  if ((soc_type == BT_SOC_TYPE_SMD) ||
      (strncmp(btsoclog_enabled, "not-set", 7) == 0))
    osi_property_get(BTSNOOP_ENABLE_PROPERTY, btsnoop_enabled, "false");
  else {
    LOG_INFO(LOG_TAG,
      "%s: soclog property set, transport driver will send the logs", __func__);
  }
  return strncmp(btsnoop_enabled, "true", 4) == 0;
}

bool is_soc_lpa_enh_pwr_enabled() {
  char lpa_enh_pwr_enabled[PROPERTY_VALUE_MAX] = {0};
  bt_soc_type_t socs[] = { BT_SOC_TYPE_HASTINGS,
                           BT_SOC_TYPE_CHEROKEE,
                           BT_SOC_TYPE_MOSELLE };
  int i, num = sizeof(socs)/sizeof(socs[0]);

  for (i = 0; i < num; i++) {
    if (soc_type == socs[i]) {
      break;
    }
  }

  if (i >= num) {
    return false;
  }

  osi_property_get("persist.vendor.btstack.enable.lpa", lpa_enh_pwr_enabled, "false");
  return strncmp(lpa_enh_pwr_enabled, "true", 4) == 0;
}

static future_t* start_up(void) {
  BT_HDR* response;
  uint8_t adv_audio_support_mask = 0;
  char adv_audio_property[2] = {};

  osi_property_get("persist.vendor.service.bt.adv_audio_mask", adv_audio_property, "0");
  adv_audio_support_mask = (uint8_t)atoi(adv_audio_property);

  //initialize number_of_scrambling_supported_freqs to 0 during start_up
  number_of_scrambling_supported_freqs = 0;
  soc_add_on_features_length = 0;
  host_add_on_features_length = 0;
  char qhs_value[2] = {};
  uint8_t qhs_support_mask = 0;

// read properties  for offtarget test setup
#if (OFF_TARGET_TEST_ENABLED == TRUE)
   char bt_soc_type[PROPERTY_VALUE_MAX];
   osi_property_get("vendor.qcom.bluetooth.soc", bt_soc_type, NULL);
   osi_property_get("persist.vendor.qcom.bluetooth.a2dp_offload_cap",
          a2dp_offload_Cap, "");
   LOG_INFO(LOG_TAG, "%s soc_type= %s", __func__, bt_soc_type);
   if (!strncmp(bt_soc_type, "hastings", sizeof(bt_soc_type))) {
     soc_type = BT_SOC_TYPE_HASTINGS;
   }
   LOG_INFO(LOG_TAG, "%s soc_type= %d ", __func__, soc_type);
#else
 // get properties from configstore for device
  load_bt_configstore_lib();
  if (bt_configstore_intf != NULL) {
     std::vector<vendor_property_t> vPropList;
     bt_configstore_intf->get_vendor_properties(BT_PROP_ALL, vPropList);

     for (auto&& vendorProp : vPropList) {
        switch(vendorProp.type){
          case BT_PROP_SOC_TYPE:
            char soc_name[32];

            strlcpy(soc_name, vendorProp.value, sizeof(soc_name));
            soc_type = bt_configstore_intf->convert_bt_soc_name_to_soc_type(soc_name);
            LOG_INFO(LOG_TAG, "%s:: soc_name:%s, soc_type = %d", __func__,
                soc_name, soc_type);
            break;

          case BT_PROP_A2DP_OFFLOAD_CAP:
            strlcpy(a2dp_offload_Cap, vendorProp.value, sizeof(a2dp_offload_Cap));
            LOG_INFO(LOG_TAG, "%s:: a2dp_offload_Cap = %s", __func__,
                a2dp_offload_Cap);
            break;

          case BT_PROP_SPILT_A2DP:
            if (!strncasecmp(vendorProp.value, "true", sizeof("true"))) {
              spilt_a2dp_supported = true;
            } else {
              spilt_a2dp_supported = false;
            }

            LOG_INFO(LOG_TAG, "%s:: spilt_a2dp_supported = %d", __func__,
                spilt_a2dp_supported);
            break;

          case BT_PROP_AAC_FRAME_CTL:
            if (!strncasecmp(vendorProp.value, "true", sizeof("true"))) {
              aac_frame_ctl_enabled = true;
            } else {
              aac_frame_ctl_enabled = false;
            }

            LOG_INFO(LOG_TAG, "%s:: aac_frame_ctl_enabled = %d", __func__,
                aac_frame_ctl_enabled);
            break;

          case BT_PROP_WIPOWER:
            if (!strncasecmp(vendorProp.value, "true", sizeof("true"))) {
              wipower_supported = true;
            } else {
              wipower_supported = false;
            }
            LOG_INFO(LOG_TAG, "%s:: wipower_supported = %d", __func__,
                wipower_supported);

           break;

          case BT_PROP_A2DP_MCAST_TEST:
            if (!strncasecmp(vendorProp.value, "true", sizeof("true"))) {
              a2dp_multicast_enabled = true;
            } else {
              a2dp_multicast_enabled = false;
            }
            LOG_INFO(LOG_TAG, "%s:: a2dp_multicast_supported = %d", __func__,
                a2dp_multicast_enabled);
            break;
          case BT_PROP_TWSP_STATE:
            if (!strncasecmp(vendorProp.value, "true", sizeof("true"))) {
              twsp_state_supported = true;
            } else {
              twsp_state_supported = false;
            }
            LOG_INFO(LOG_TAG, "%s:: twsp_state_supported = %d", __func__,
                twsp_state_supported);
           break;
          case BT_PROP_MAX_POWER:
            max_power_prop_enabled = decode_max_power_values((char *)vendorProp.value);
            LOG_INFO(LOG_TAG, "%s:: max_power_prop_enabled = %d", __func__,
                max_power_prop_enabled);
           break;
         default:
            break;
       }
    }
  }
#endif  /* OFF_TARGET_TEST_ENABLED */
  // Send the initial reset command
  response = AWAIT_COMMAND(packet_factory->make_reset());
  packet_parser->parse_generic_command_complete(response);

  // Request the classic buffer size next
  response = AWAIT_COMMAND(packet_factory->make_read_buffer_size());
  packet_parser->parse_read_buffer_size_response(
      response, &acl_data_size_classic, &acl_buffer_count_classic);

  // Tell the controller about our buffer sizes and buffer counts next
  // TODO(zachoverflow): factor this out. eww l2cap contamination. And why just
  // a hardcoded 10?
  response = AWAIT_COMMAND(packet_factory->make_host_buffer_size(
      L2CAP_MTU_SIZE, SCO_HOST_BUFFER_SIZE, L2CAP_HOST_FC_ACL_BUFS, 10));

  packet_parser->parse_generic_command_complete(response);

  if (is_soc_logging_enabled()) {
    LOG_INFO(LOG_TAG, "%s Send command to enable soc logging ", __func__);
    send_soc_log_command(true);
  }

  if (soc_type == BT_SOC_TYPE_SMD || soc_type == BT_SOC_TYPE_CHEROKEE) {
    char donglemode_prop[PROPERTY_VALUE_MAX] = "false";
    if(osi_property_get("persist.bluetooth.donglemode", donglemode_prop, "false") &&
        !strcmp(donglemode_prop, "false")) {
      btm_enable_soc_iot_info_report(is_iot_info_report_enabled());
    }
  }

  if (is_soc_lpa_enh_pwr_enabled()) {
    btm_enable_link_lpa_enh_pwr_ctrl((uint16_t)HCI_INVALID_HANDLE, true);
  }

  // Read the local version info off the controller next, including
  // information such as manufacturer and supported HCI version
  response = AWAIT_COMMAND(packet_factory->make_read_local_version_info());
  packet_parser->parse_read_local_version_info_response(response, &bt_version);

  // Read the bluetooth address off the controller next
  response = AWAIT_COMMAND(packet_factory->make_read_bd_addr());
  packet_parser->parse_read_bd_addr_response(response, &address);

  // Request the controller's supported commands next
  response =
      AWAIT_COMMAND(packet_factory->make_read_local_supported_commands());
  packet_parser->parse_read_local_supported_commands_response(
      response, supported_commands, HCI_SUPPORTED_COMMANDS_ARRAY_SIZE);

  // Read page 0 of the controller features next
  uint8_t page_number = 0;
  response = AWAIT_COMMAND(
      packet_factory->make_read_local_extended_features(page_number));
  packet_parser->parse_read_local_extended_features_response(
      response, &page_number, &last_features_classic_page_index,
      features_classic, MAX_FEATURES_CLASSIC_PAGE_COUNT);

  CHECK(page_number == 0);
  page_number++;

  // Inform the controller what page 0 features we support, based on what
  // it told us it supports. We need to do this first before we request the
  // next page, because the controller's response for page 1 may be
  // dependent on what we configure from page 0
  simple_pairing_supported =
      HCI_SIMPLE_PAIRING_SUPPORTED(features_classic[0].as_array);
  if (simple_pairing_supported) {
    response = AWAIT_COMMAND(
        packet_factory->make_write_simple_pairing_mode(HCI_SP_MODE_ENABLED));
    packet_parser->parse_generic_command_complete(response);
  }

  if (HCI_LE_SPT_SUPPORTED(features_classic[0].as_array)) {
    response = AWAIT_COMMAND(packet_factory->make_ble_write_host_support(
        BTM_BLE_HOST_SUPPORT, BTM_BLE_SIMULTANEOUS_HOST));

    packet_parser->parse_generic_command_complete(response);

    // If we modified the BT_HOST_SUPPORT, we will need ext. feat. page 1
    if (last_features_classic_page_index < 1)
      last_features_classic_page_index = 1;
  }

  // Done telling the controller about what page 0 features we support
  // Request the remaining feature pages
  while (page_number <= last_features_classic_page_index &&
         page_number < MAX_FEATURES_CLASSIC_PAGE_COUNT) {
    response = AWAIT_COMMAND(
        packet_factory->make_read_local_extended_features(page_number));
    packet_parser->parse_read_local_extended_features_response(
        response, &page_number, &last_features_classic_page_index,
        features_classic, MAX_FEATURES_CLASSIC_PAGE_COUNT);

    page_number++;
  }

  char donglemode_prop[PROPERTY_VALUE_MAX] = "false";
  if(osi_property_get("persist.bluetooth.donglemode", donglemode_prop, "false") &&
      !strcmp(donglemode_prop, "false")) {
    // read BLE offload features support from controller
    response = AWAIT_COMMAND(packet_factory->make_ble_read_offload_features_support());
    packet_parser->parse_ble_read_offload_features_response(response, &ble_offload_features_supported);
  }

#if (SC_MODE_INCLUDED == TRUE)
  if(ble_offload_features_supported) {
    secure_connections_supported =
        HCI_SC_CTRLR_SUPPORTED(features_classic[2].as_array);
    bool pts_secure_connections_host_supported_disabled =
       stack_config_get_interface()->get_pts_bredr_secureconnection_host_support_disabled();
    if (pts_secure_connections_host_supported_disabled) {
      LOG_WARN(LOG_TAG, "%s secure connections host support disabled from pts ", __func__);
    }
    if (secure_connections_supported && !pts_secure_connections_host_supported_disabled) {
      response = AWAIT_COMMAND(
          packet_factory->make_write_secure_connections_host_support(
              HCI_SC_MODE_ENABLED));
      packet_parser->parse_generic_command_complete(response);
    }
  }
#endif

  ble_supported = last_features_classic_page_index >= 1 &&
                  HCI_LE_HOST_SUPPORTED(features_classic[1].as_array);
  if (ble_supported) {
    // Request the ble white list size next
    response = AWAIT_COMMAND(packet_factory->make_ble_read_white_list_size());
    packet_parser->parse_ble_read_white_list_size_response(
        response, &ble_white_list_size);

    // Request the ble buffer size next
    if (HCI_LE_READ_BUFFER_SIZE_V2_SUPPORTED(supported_commands)) {
      response = AWAIT_COMMAND(packet_factory->make_ble_read_buffer_size_v2());
      packet_parser->parse_ble_read_buffer_size_response(
          response, &acl_data_size_ble, &acl_buffer_count_ble,
          &iso_data_packet_len, &total_num_iso_data_packets);
    } else {
      response = AWAIT_COMMAND(packet_factory->make_ble_read_buffer_size());
      packet_parser->parse_ble_read_buffer_size_response(
          response, &acl_data_size_ble, &acl_buffer_count_ble, NULL, NULL);
    }

    // Response of 0 indicates ble has the same buffer size as classic
    if (acl_data_size_ble == 0) acl_data_size_ble = acl_data_size_classic;

    // Request the ble supported states next
    response = AWAIT_COMMAND(packet_factory->make_ble_read_supported_states());
    packet_parser->parse_ble_read_supported_states_response(
        response, ble_supported_states, sizeof(ble_supported_states));

    // Request the ble supported features next
    response =
        AWAIT_COMMAND(packet_factory->make_ble_read_local_supported_features());
    packet_parser->parse_ble_read_local_supported_features_response(
        response, &features_ble);

    // Set Host support for Isochrnous channel management
    if (adv_audio_support_mask > 0 && (HCI_LE_CIS_MASTER_SUPPORT(features_ble.as_array)
          || HCI_LE_CIS_SLAVE_SUPPORT(features_ble.as_array))) { //TODO: Add BIS Support check
      response = AWAIT_COMMAND(
          packet_factory->make_ble_set_host_feature_cmd(ISO_CHANNEL_HOST_SUPPORT_BIT, 1));
      packet_parser->parse_ble_set_host_feature_cmd(response);
      HCI_LE_SET_CIS_HOST_SUPPORT(features_ble.as_array);
    }

    if (HCI_LE_ENHANCED_PRIVACY_SUPPORTED(features_ble.as_array)) {
      response =
          AWAIT_COMMAND(packet_factory->make_ble_read_resolving_list_size());
      packet_parser->parse_ble_read_resolving_list_size_response(
          response, &ble_resolving_list_max_size);
    }

    if (HCI_LE_DATA_LEN_EXT_SUPPORTED(features_ble.as_array)) {
      response = AWAIT_COMMAND(
          packet_factory->make_ble_read_suggested_default_data_length());
      packet_parser->parse_ble_read_suggested_default_data_length_response(
          response, &ble_suggested_default_data_length);
    }

    if (HCI_LE_EXTENDED_ADVERTISING_SUPPORTED(features_ble.as_array)) {
      response = AWAIT_COMMAND(
          packet_factory->make_ble_read_maximum_advertising_data_length());
      packet_parser->parse_ble_read_maximum_advertising_data_length(
          response, &ble_maxium_advertising_data_length);

      response = AWAIT_COMMAND(
          packet_factory->make_ble_read_number_of_supported_advertising_sets());
      packet_parser->parse_ble_read_number_of_supported_advertising_sets(
          response, &ble_number_of_supported_advertising_sets);
    } else {
      /* If LE Excended Advertising is not supported, use the default value */
      ble_maxium_advertising_data_length = 31;
    }

    // Set the ble event mask next
    response =
        AWAIT_COMMAND(packet_factory->make_ble_set_event_mask(&BLE_EVENT_MASK));
    packet_parser->parse_generic_command_complete(response);
  }

  if (simple_pairing_supported) {
    response =
        AWAIT_COMMAND(packet_factory->make_set_event_mask(&CLASSIC_EVENT_MASK));
    packet_parser->parse_generic_command_complete(response);
  }

  // read local supported codecs
  if (HCI_READ_LOCAL_CODECS_SUPPORTED_V2(supported_commands)) {
    response =
        AWAIT_COMMAND(packet_factory->make_read_local_supported_codecs_v2());
    packet_parser->parse_read_local_supported_codecs_response(
        response,
        &number_of_local_supported_codecs, local_supported_codecs, std_codec_tx,
        &number_of_vs_supported_codecs, vs_supported_codecs, vs_codec_tx);
    update_soc_codec_transport();
  } else if (HCI_READ_LOCAL_CODECS_SUPPORTED(supported_commands)) {
    response =
        AWAIT_COMMAND(packet_factory->make_read_local_supported_codecs());
    packet_parser->parse_read_local_supported_codecs_response(
        response, &number_of_local_supported_codecs, local_supported_codecs, NULL,
        &number_of_vs_supported_codecs, vs_supported_codecs, NULL);
  }

  read_simple_pairing_options_supported =
      HCI_READ_LOCAL_SIMPLE_PAIRING_OPTIONS_SUPPORTED(supported_commands);

  // read local simple pairing options
  if (read_simple_pairing_options_supported) {
    LOG_DEBUG(LOG_TAG, "%s read local simple pairing options", __func__);
    response =
        AWAIT_COMMAND(packet_factory->make_read_local_simple_pairing_options());
    packet_parser->parse_read_local_simple_paring_options_response(
        response, &simple_pairing_options, &maximum_encryption_key_size);
    LOG_DEBUG(LOG_TAG, "%s simple pairing options is 0x%x", __func__,
        simple_pairing_options);
  }

  // write rf tx & rx path compensation value
  hci_write_rf_path_compensation_supported =
             HCI_WRITE_RF_PATH_COMPENSATION_SUPPORTED(supported_commands);

  if(hci_write_rf_path_compensation_supported) {
    uint16_t tx_path_value = rf_path_loss_values_fetch(RF_PATH_LOSS_ID, RF_TX_PATH_COMPENSATION_VALUE);
    uint16_t rx_path_value = rf_path_loss_values_fetch(RF_PATH_LOSS_ID, RF_RX_PATH_COMPENSATION_VALUE);
    response =
        AWAIT_COMMAND(packet_factory->make_ble_write_rf_path_compensation(tx_path_value, rx_path_value));
    packet_parser->parse_generic_command_complete(response);
    LOG_DEBUG(LOG_TAG, "%s HCI write RF compensation tx value : %d, rx value : %d", __func__,
        tx_path_value, rx_path_value);
  }

  if (bt_configstore_intf != NULL) {
    host_add_on_features_list_t features_list;

    if (bt_configstore_intf->get_host_add_on_features(&features_list)) {
      host_add_on_features_length = features_list.feat_mask_len;
      if (host_add_on_features_length != 0 &&
          host_add_on_features_length <= HOST_ADD_ON_FEATURES_MAX_SIZE)
        memcpy(host_add_on_features.as_array, features_list.features,
            host_add_on_features_length);
    }
  }

  //Read HCI_VS_GET_ADDON_FEATURES_SUPPORT
  if (soc_type >= BT_SOC_TYPE_CHEROKEE) {

    if (bt_configstore_intf != NULL) {
      controller_add_on_features_list_t features_list;

      if (bt_configstore_intf->get_controller_add_on_features(&features_list)){
        product_id = features_list.product_id;
        response_version = features_list.rsp_version;
        soc_add_on_features_length = features_list.feat_mask_len;
        if (soc_add_on_features_length != 0) {
          if (soc_add_on_features_length <= SOC_ADD_ON_FEATURES_MAX_SIZE) {
            memcpy(soc_add_on_features.as_array, features_list.features,
                soc_add_on_features_length);
          } else {
            LOG(FATAL) << __func__ << "invalid soc add on features length: "
              << +soc_add_on_features_length;
          }
        }
      }
    }

    if (!soc_add_on_features_length) {
      response =
            AWAIT_COMMAND(packet_factory->make_read_add_on_features_supported());
      if (response) {

        LOG_DEBUG(LOG_TAG, "%s sending add-on features supported VSC", __func__);
        packet_parser->parse_read_add_on_features_supported_response(
            response, &soc_add_on_features, &soc_add_on_features_length,
            &product_id, &response_version);
      }
    }
    if (!soc_add_on_features_length) {
      // read scrambling support from controller incase of cherokee
      response =
            AWAIT_COMMAND(packet_factory->make_read_scrambling_supported_freqs());
      if (response) {

        LOG_DEBUG(LOG_TAG, "%s sending scrambling support VSC", __func__);
        packet_parser->parse_read_scrambling_supported_freqs_response(
            response, &number_of_scrambling_supported_freqs,
            scrambling_supported_freqs);

        LOG_DEBUG(LOG_TAG, "%s number_of_scrambling_supported_freqs %d", __func__,
                        number_of_scrambling_supported_freqs);
      }
    } else {
        if (HCI_SPLIT_A2DP_SCRAMBLING_DATA_REQUIRED(soc_add_on_features.as_array))  {
          if (HCI_SPLIT_A2DP_44P1KHZ_SAMPLE_FREQ(soc_add_on_features.as_array)) {
            scrambling_supported_freqs[number_of_scrambling_supported_freqs++]
                                = BTAV_A2DP_CODEC_SAMPLE_RATE_44100;
            scrambling_supported_freqs[number_of_scrambling_supported_freqs++]
                                = BTAV_A2DP_CODEC_SAMPLE_RATE_88200;
          }
          if (HCI_SPLIT_A2DP_48KHZ_SAMPLE_FREQ(soc_add_on_features.as_array)) {
            scrambling_supported_freqs[number_of_scrambling_supported_freqs++]
                                = BTAV_A2DP_CODEC_SAMPLE_RATE_48000;
            scrambling_supported_freqs[number_of_scrambling_supported_freqs++]
                                = BTAV_A2DP_CODEC_SAMPLE_RATE_96000;
          }
        }
    }
  }

  if (!HCI_LE_CIS_MASTER_SUPPORT(features_ble.as_array)) {
    adv_audio_support_mask &= ~ADV_AUDIO_UNICAST_FEAT_MASK;
  }
  if (!HCI_LE_PERIODIC_SYNC_TRANSFER_SEND_SUPPORTED(features_ble.as_array)) {
    adv_audio_support_mask &= ~ADV_AUDIO_BCA_FEAT_MASK;
  }
  if (!HCI_LE_ISO_BROADCASTER_SUPPORTED(features_ble.as_array)) {
    adv_audio_support_mask &= ~ADV_AUDIO_BCS_FEAT_MASK;
  }
  snprintf(adv_audio_property, 2, "%d", adv_audio_support_mask);
  osi_property_set("persist.vendor.service.bt.adv_audio_mask", adv_audio_property);

  if (HCI_QBCE_QLE_HCI_SUPPORTED(soc_add_on_features.as_array)) {
    BT_HDR* response;
    char qhs_iso[PROPERTY_VALUE_MAX] = "false";
    property_get("persist.vendor.btstack.qhs_enable", qhs_iso, "false");
    if (!strncmp("true", qhs_iso, 4)) {
        response = AWAIT_COMMAND(packet_factory->make_qbce_set_qhs_host_mode(
                                 QHS_TRANSPORT_LE_ISO, QHS_HOST_MODE_HOST_AWARE));
        packet_parser->parse_generic_command_complete(response);
    } else {
        response = AWAIT_COMMAND(packet_factory->make_qbce_set_qhs_host_mode(
                                 QHS_TRANSPORT_LE_ISO, QHS_HOST_DISABLE_ALL));
        packet_parser->parse_generic_command_complete(response);
    }

    /* This property is for test/debug purpose only */
    osi_property_get("persist.vendor.btstack.qhs_support", qhs_value, "255");
    qhs_support_mask = (uint8_t)atoi(qhs_value);
    if (qhs_support_mask != 0xFF) {
        response = qhs_support_mask & QHS_BREDR_MASK?
                   AWAIT_COMMAND(packet_factory->make_qbce_set_qhs_host_mode(
                                 QHS_TRANSPORT_BREDR, QHS_HOST_MODE_HOST_AWARE)):
                   AWAIT_COMMAND(packet_factory->make_qbce_set_qhs_host_mode(
                                 QHS_TRANSPORT_BREDR, QHS_HOST_DISABLE_ALL));
        packet_parser->parse_generic_command_complete(response);

        response = qhs_support_mask & QHS_LE_MASK?
                   AWAIT_COMMAND(packet_factory->make_qbce_set_qhs_host_mode(
                                 QHS_TRANSPORT_LE, QHS_HOST_MODE_HOST_AWARE)):
                   AWAIT_COMMAND(packet_factory->make_qbce_set_qhs_host_mode(
                                 QHS_TRANSPORT_LE, QHS_HOST_DISABLE_ALL));
        packet_parser->parse_generic_command_complete(response);

        response = qhs_support_mask & QHS_LE_ISO_MASK?
                   AWAIT_COMMAND(packet_factory->make_qbce_set_qhs_host_mode(
                                 QHS_TRANSPORT_LE_ISO, QHS_HOST_MODE_HOST_AWARE)):
                   AWAIT_COMMAND(packet_factory->make_qbce_set_qhs_host_mode(
                                 QHS_TRANSPORT_LE_ISO, QHS_HOST_DISABLE_ALL));
        packet_parser->parse_generic_command_complete(response);
    }

    response = AWAIT_COMMAND(packet_factory->make_qbce_set_qll_event_mask(
                   &QBCE_QLM_AND_QLL_EVENT_MASK));
    packet_parser->parse_generic_command_complete(response);
  }

  if (HCI_QBCE_QCM_HCI_SUPPORTED(soc_add_on_features.as_array)) {
    response = AWAIT_COMMAND(packet_factory->make_qbce_set_qlm_event_mask(
                            &QBCE_QLM_AND_QLL_EVENT_MASK));
    packet_parser->parse_generic_command_complete(response);
  }

  if (!HCI_READ_ENCR_KEY_SIZE_SUPPORTED(supported_commands)) {
    LOG(FATAL) << " Controller must support Read Encryption Key Size command";
  }

  g_adv_audio_prop = adv_audio_support_mask;
  readable = true;
  return future_new_immediate(FUTURE_SUCCESS);
}

static future_t* shut_down(void) {
  if (bt_configstore_lib_handle) {
    dlclose(bt_configstore_lib_handle);
    bt_configstore_lib_handle = NULL;
    bt_configstore_intf = NULL;
  }
  readable = false;
  return future_new_immediate(FUTURE_SUCCESS);
}

EXPORT_SYMBOL extern const module_t controller_module = {
    .name = CONTROLLER_MODULE,
    .init = NULL,
    .start_up = start_up,
    .shut_down = shut_down,
    .clean_up = NULL,
    .dependencies = {HCI_MODULE, NULL}};

// Interface functions

static bool get_is_ready(void) {
  return readable;
}

static const RawAddress* get_address(void) {
  CHECK(readable);
  return &address;
}

static const bt_version_t* get_bt_version(void) {
  CHECK(readable);
  return &bt_version;
}

// TODO(zachoverflow): hide inside, move decoder inside too
static const bt_device_features_t* get_features_classic(int index) {
  CHECK(readable);
  CHECK(index < MAX_FEATURES_CLASSIC_PAGE_COUNT);
  return &features_classic[index];
}

static uint8_t get_last_features_classic_index(void) {
  CHECK(readable);
  return last_features_classic_page_index;
}

static uint8_t* get_local_supported_codecs(uint8_t* number_of_codecs) {
  CHECK(readable);
  if (number_of_local_supported_codecs) {
    *number_of_codecs = number_of_local_supported_codecs;
    return local_supported_codecs;
  }
  return NULL;
}

/* get transport of the corresponding standard codec*/
static uint8_t get_std_supported_codec_transport(uint8_t std_codec_id) {
  CHECK(readable);
  if (number_of_local_supported_codecs) {
    std::map<uint8_t, uint8_t>::iterator it = std_codec_transport.find(std_codec_id);
    if (it != std_codec_transport.end()) {
      return it->second;
    }
  }
  return INVALID_TRANSPORT;
}

/* get vs codecs*/
static uint32_t* get_vs_supported_codecs(uint8_t* number_of_codecs) {
  CHECK(readable);
  if (number_of_vs_supported_codecs) {
    *number_of_codecs = number_of_vs_supported_codecs;
    return vs_supported_codecs;
  }
  return NULL;
}

/* get transport of the corresponding vs codec*/
static uint8_t get_vs_supported_codec_transport(uint32_t vs_codec_id) {
  CHECK(readable);
  if (number_of_vs_supported_codecs) {
    std::map<uint32_t, uint8_t>::iterator it = vs_codec_transport.find(vs_codec_id);
    if (it != vs_codec_transport.end()) {
      return it->second;
    }
  }
  return INVALID_TRANSPORT;
}

static uint8_t* get_scrambling_supported_freqs(uint8_t* number_of_freqs) {
  CHECK(readable);
  if (number_of_scrambling_supported_freqs) {
    *number_of_freqs = number_of_scrambling_supported_freqs;
    return scrambling_supported_freqs;
  }
  return NULL;
}

static const bt_device_features_t* get_features_ble(void) {
  CHECK(readable);
  CHECK(ble_supported);
  return &features_ble;
}

static const uint8_t* get_ble_supported_states(void) {
  CHECK(readable);
  CHECK(ble_supported);
  return ble_supported_states;
}

static bool supports_simple_pairing(void) {
  CHECK(readable);
  return simple_pairing_supported;
}

static bool supports_secure_connections(void) {
  CHECK(readable);
  return secure_connections_supported;
}

static bool supports_simultaneous_le_bredr(void) {
  CHECK(readable);
  return HCI_SIMUL_LE_BREDR_SUPPORTED(features_classic[0].as_array);
}

static bool supports_reading_remote_extended_features(void) {
  CHECK(readable);
  return HCI_READ_REMOTE_EXT_FEATURES_SUPPORTED(supported_commands);
}

static bool supports_interlaced_inquiry_scan(void) {
  CHECK(readable);
  return HCI_LMP_INTERLACED_INQ_SCAN_SUPPORTED(features_classic[0].as_array);
}

static bool supports_rssi_with_inquiry_results(void) {
  CHECK(readable);
  return HCI_LMP_INQ_RSSI_SUPPORTED(features_classic[0].as_array);
}

static bool supports_extended_inquiry_response(void) {
  CHECK(readable);
  return HCI_EXT_INQ_RSP_SUPPORTED(features_classic[0].as_array);
}

static bool supports_master_slave_role_switch(void) {
  CHECK(readable);
  return HCI_SWITCH_SUPPORTED(features_classic[0].as_array);
}

static bool supports_enhanced_setup_synchronous_connection(void) {
  assert(readable);
  return HCI_ENH_SETUP_SYNCH_CONN_SUPPORTED(supported_commands);
}

static bool supports_enhanced_accept_synchronous_connection(void) {
  assert(readable);
  return HCI_ENH_ACCEPT_SYNCH_CONN_SUPPORTED(supported_commands);
}

static bool supports_ble(void) {
  CHECK(readable);
  return ble_supported;
}

static bool supports_ble_privacy(void) {
  CHECK(readable);
  CHECK(ble_supported);
  return HCI_LE_ENHANCED_PRIVACY_SUPPORTED(features_ble.as_array);
}

static bool supports_ble_set_privacy_mode() {
  CHECK(readable);
  CHECK(ble_supported);
  return HCI_LE_ENHANCED_PRIVACY_SUPPORTED(features_ble.as_array) &&
         HCI_LE_SET_PRIVACY_MODE_SUPPORTED(supported_commands);
}

static bool supports_ble_packet_extension(void) {
  CHECK(readable);
  CHECK(ble_supported);
  return HCI_LE_DATA_LEN_EXT_SUPPORTED(features_ble.as_array);
}

static bool supports_ble_connection_parameters_request(void) {
  CHECK(readable);
  CHECK(ble_supported);
  return HCI_LE_CONN_PARAM_REQ_SUPPORTED(features_ble.as_array);
}

static bool supports_ble_offload_features(void) {
  assert(readable);
  assert(ble_supported);
  return ble_offload_features_supported;
}
static bool supports_ble_2m_phy(void) {
  CHECK(readable);
  CHECK(ble_supported);
  return HCI_LE_2M_PHY_SUPPORTED(features_ble.as_array);
}

static bool supports_ble_coded_phy(void) {
  CHECK(readable);
  CHECK(ble_supported);
  return HCI_LE_CODED_PHY_SUPPORTED(features_ble.as_array);
}

static bool supports_ble_extended_advertising(void) {
  CHECK(readable);
  CHECK(ble_supported);
  return HCI_LE_EXTENDED_ADVERTISING_SUPPORTED(features_ble.as_array);
}

static bool supports_ble_periodic_advertising(void) {
  CHECK(readable);
  CHECK(ble_supported);
  return HCI_LE_PERIODIC_ADVERTISING_SUPPORTED(features_ble.as_array);
}

static bool supports_ble_periodic_sync_transfer(void) {
  CHECK(readable);
  CHECK(ble_supported);
  return HCI_LE_PERIODIC_SYNC_TRANSFER_SEND_SUPPORTED(features_ble.as_array);
}

static bool supports_ble_iso_broadcaster(void) {
  CHECK(readable);
  CHECK(ble_supported);
  return HCI_LE_ISO_BROADCASTER_SUPPORTED(features_ble.as_array);
}

static uint16_t get_acl_data_size_classic(void) {
  CHECK(readable);
  return acl_data_size_classic;
}

static uint16_t get_acl_data_size_ble(void) {
  CHECK(readable);
  CHECK(ble_supported);
  return acl_data_size_ble;
}

/* to get max length of data portion in iso packet*/
static uint16_t get_ble_iso_data_packet_len(void) {
  CHECK(readable);
  return iso_data_packet_len;
}

static uint16_t get_acl_packet_size_classic(void) {
  CHECK(readable);
  return acl_data_size_classic + HCI_DATA_PREAMBLE_SIZE;
}

static uint16_t get_acl_packet_size_ble(void) {
  CHECK(readable);
  return acl_data_size_ble + HCI_DATA_PREAMBLE_SIZE;
}

static uint16_t get_ble_suggested_default_data_length(void) {
  CHECK(readable);
  CHECK(ble_supported);
  return ble_suggested_default_data_length;
}

static uint16_t get_ble_maxium_advertising_data_length(void) {
  CHECK(readable);
  CHECK(ble_supported);
  return ble_maxium_advertising_data_length;
}

static uint8_t get_ble_number_of_supported_advertising_sets(void) {
  CHECK(readable);
  CHECK(ble_supported);
  return ble_number_of_supported_advertising_sets;
}

static uint16_t get_acl_buffer_count_classic(void) {
  CHECK(readable);
  return acl_buffer_count_classic;
}

static uint8_t get_acl_buffer_count_ble(void) {
  CHECK(readable);
  CHECK(ble_supported);
  return acl_buffer_count_ble;
}

/* to get number of iso data packets that controller can buffer*/
static uint8_t get_ble_iso_num_data_packets(void) {
  CHECK(readable);
  return total_num_iso_data_packets;
}

static uint8_t get_ble_white_list_size(void) {
  CHECK(readable);
  CHECK(ble_supported);
  return ble_white_list_size;
}

static uint8_t get_ble_resolving_list_max_size(void) {
  CHECK(readable);
  CHECK(ble_supported);
  return ble_resolving_list_max_size;
}

static void set_ble_resolving_list_max_size(int resolving_list_max_size) {
  // Setting "resolving_list_max_size" to 0 is done during cleanup,
  // hence we ignore the "readable" flag already set to false during shutdown.
  if (resolving_list_max_size != 0) {
    CHECK(readable);
  }
  CHECK(ble_supported);
  ble_resolving_list_max_size = resolving_list_max_size;
}

static uint8_t get_le_all_initiating_phys() {
  uint8_t phy = PHY_LE_1M;
  // TODO(jpawlowski): uncomment after next FW udpate
  // if (supports_ble_2m_phy()) phy |= PHY_LE_2M;
  // if (supports_ble_coded_phy()) phy |= PHY_LE_CODED;
  return phy;
}

static const bt_device_soc_add_on_features_t* get_soc_add_on_features(uint8_t *add_on_features_len) {
  CHECK(readable);
  *add_on_features_len = soc_add_on_features_length;
  return &soc_add_on_features;
}

static uint16_t  get_product_id(void) {
  CHECK(readable);
  return product_id;
}

static uint16_t get_response_version(void) {
  CHECK(readable);
  return response_version;
}

static const bt_device_host_add_on_features_t*
      get_host_add_on_features(uint8_t *add_on_features_len) {
  CHECK(readable);
  *add_on_features_len = host_add_on_features_length;
  return &host_add_on_features;
}

static bool supports_read_simple_pairing_options(void) {
  CHECK(readable);
  return read_simple_pairing_options_supported;
}

static bool performs_remote_public_key_validation(void) {
  CHECK(readable);
  if (simple_pairing_options != 0) {
    return HCI_REMOTE_PUBLIC_KEY_VALIDATION_SUPPORTED(simple_pairing_options);
  }
  return false;
}

static bt_soc_type_t get_soc_type() {
  CHECK(readable);
  return soc_type;
}

static const char * get_a2dp_offload_cap() {
  CHECK(readable);
  return a2dp_offload_Cap;
}

static bool supports_spilt_a2dp() {
  CHECK(readable);
  return spilt_a2dp_supported;
}

static bool supports_aac_frame_ctl() {
  CHECK(readable);
  return aac_frame_ctl_enabled;
}

static bool supports_wipower() {
  CHECK(readable);
  return wipower_supported;
}

static bool is_multicast_enabled() {
  return a2dp_multicast_enabled;
}
static bool supports_twsp_remote_state() {
  return twsp_state_supported;
}

/* save transport information of standard and vendor specific codecs */
void update_soc_codec_transport() {
  int number_of_codecs = (number_of_local_supported_codecs > number_of_vs_supported_codecs ?
                            number_of_local_supported_codecs : number_of_vs_supported_codecs);
  for (int i = 0; i < number_of_codecs; i++) {
    if (i < number_of_local_supported_codecs) {
      std_codec_transport.insert(std::make_pair(local_supported_codecs[i], std_codec_tx[i]));
    }
    if (i < number_of_vs_supported_codecs) {
      vs_codec_transport.insert(std::make_pair(vs_supported_codecs[i], vs_codec_tx[i]));
    }
  }
}

/* to check if CIS master role is enabled in LL feture mask*/
static bool is_cis_master_role_supported(void) {
  CHECK(readable);
  return HCI_LE_CIS_MASTER_SUPPORT(features_ble.as_array);
}

/* to check if CIS slave role is enabled in LL feture mask*/
static bool is_cis_slave_role_supported(void) {
  CHECK(readable);
  return HCI_LE_CIS_SLAVE_SUPPORT(features_ble.as_array);
}

/* to check if host support for ISO channel is set in LL Feature Mask*/
static bool is_host_iso_channel_supported(void) {
  CHECK(readable);
  return HCI_LE_ISO_CHNL_HOST_SUPPORT(features_ble.as_array);
}

/* to check if power control feature is enabled in LL Feature mask*/
static bool is_pow_ctr_req_supported(void) {
  CHECK(readable);
  return HCI_LE_POW_CTR_REQ_SUPPORT(features_ble.as_array);
}

/* to check if pathloss manitoring feature is enabled in LL Feature mask*/
static bool is_pathloss_monitoring_supported(void) {
  CHECK(readable);
  return HCI_LE_PATHLOSS_MONITORING_SUPPORT(features_ble.as_array);
}

static bool get_max_power_values(uint8_t *power_val) {
  memcpy(power_val, max_power_prop_value, sizeof(max_power_prop_value));
  return max_power_prop_enabled;
}

static bool is_adv_audio_supported(void) {
    if ((g_adv_audio_prop & ADV_AUDIO_UNICAST_FEAT_MASK) ||
              (g_adv_audio_prop & ADV_AUDIO_BCA_FEAT_MASK)) {
        return true;
    }
    return false;
}

static bool is_qbce_QLE_HCI_supported(void) {
  return HCI_QBCE_QLE_HCI_SUPPORTED(
               soc_add_on_features.as_array);
}

static bool is_qbce_QCM_HCI_supported(void) {
  return HCI_QBCE_QCM_HCI_SUPPORTED(
               soc_add_on_features.as_array);
}

static const controller_t interface = {
    get_is_ready,

    get_address,
    get_bt_version,

    get_features_classic,
    get_last_features_classic_index,

    get_features_ble,
    get_ble_supported_states,

    supports_simple_pairing,
    supports_secure_connections,
    supports_simultaneous_le_bredr,
    supports_reading_remote_extended_features,
    supports_interlaced_inquiry_scan,
    supports_rssi_with_inquiry_results,
    supports_extended_inquiry_response,
    supports_master_slave_role_switch,
    supports_enhanced_setup_synchronous_connection,
    supports_enhanced_accept_synchronous_connection,

    supports_ble,
    supports_ble_packet_extension,
    supports_ble_connection_parameters_request,
    supports_ble_privacy,
    supports_ble_set_privacy_mode,
    supports_ble_2m_phy,
    supports_ble_coded_phy,
    supports_ble_extended_advertising,
    supports_ble_periodic_advertising,
    supports_ble_periodic_sync_transfer,
    supports_ble_iso_broadcaster,

    get_acl_data_size_classic,
    get_acl_data_size_ble,

    get_acl_packet_size_classic,
    get_acl_packet_size_ble,
    get_ble_suggested_default_data_length,
    get_ble_maxium_advertising_data_length,
    get_ble_number_of_supported_advertising_sets,

    get_acl_buffer_count_classic,
    get_acl_buffer_count_ble,

    get_ble_white_list_size,

    get_ble_resolving_list_max_size,
    set_ble_resolving_list_max_size,
    get_local_supported_codecs,
    supports_ble_offload_features,
    get_le_all_initiating_phys,
    get_scrambling_supported_freqs,
    get_soc_add_on_features,
    get_product_id,
    get_response_version,
    get_host_add_on_features,
    supports_read_simple_pairing_options,
    performs_remote_public_key_validation,
    get_soc_type,
    get_a2dp_offload_cap,
    supports_spilt_a2dp,
    supports_aac_frame_ctl,
    supports_wipower,
    is_multicast_enabled,
    supports_twsp_remote_state,
    get_vs_supported_codecs,
    get_ble_iso_data_packet_len,
    get_ble_iso_num_data_packets,
    get_std_supported_codec_transport,
    get_vs_supported_codec_transport,
    is_host_iso_channel_supported,
    is_cis_master_role_supported,
    is_cis_slave_role_supported,
    is_pow_ctr_req_supported,
    is_pathloss_monitoring_supported,
    get_max_power_values,
    is_adv_audio_supported,
    is_qbce_QLE_HCI_supported,
    is_qbce_QCM_HCI_supported,
};

const controller_t* controller_get_interface() {
  static bool loaded = false;
  if (!loaded) {
    loaded = true;

    hci = hci_layer_get_interface();
    packet_factory = hci_packet_factory_get_interface();
    packet_parser = hci_packet_parser_get_interface();
  }

  return &interface;
}

const controller_t* controller_get_test_interface(
    const hci_t* hci_interface,
    const hci_packet_factory_t* packet_factory_interface,
    const hci_packet_parser_t* packet_parser_interface) {
  hci = hci_interface;
  packet_factory = packet_factory_interface;
  packet_parser = packet_parser_interface;
  return &interface;
}

int load_bt_configstore_lib() {
  const char* sym = BT_CONFIG_STORE_INTERFACE_STRING;
  const char* err = "error unknown";
  bt_configstore_lib_handle = dlopen("libbtconfigstore.so", RTLD_NOW);
  if (!bt_configstore_lib_handle) {
    const char* err_str = dlerror();
    LOG(ERROR) << __func__ << ": failed to load Bt Config store library, error="
               << (err_str ? err_str : err);
    goto error;
  }

  // Get the address of the bt_configstore_interface_t.
  bt_configstore_intf = (bt_configstore_interface_t*)dlsym(bt_configstore_lib_handle, sym);
  if (!bt_configstore_intf) {
    LOG(ERROR) << __func__ << ": failed to load symbol from bt config store library"
               << sym;
    goto error;
  }

  // Success.
  LOG(INFO) << __func__ << " loaded HAL: bt_configstore_interface_t=" << bt_configstore_intf
            << ", bt_configstore_lib_handle=" << bt_configstore_lib_handle;

  return 0;

error:
  if (bt_configstore_lib_handle) {
    dlclose(bt_configstore_lib_handle);
    bt_configstore_lib_handle = NULL;
    bt_configstore_intf = NULL;
  }

  return -EINVAL;
}

static inline bool is_byte_valid(char ch)
{
  return ((ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'f') ||
         (ch >= 'A' && ch <= 'F'));
}

bool decode_max_power_values(char * power_val) {
  bool status = false;
  char *token, *reset = power_val;
  int i;

  if (!strcmp(power_val, "false")) {
      LOG_INFO(LOG_TAG, "%s: MAX POW property is not set", __func__);
      return false;
  } else if (!strchr(power_val, '-') || (!strchr(power_val, 'x') &&
             !strchr(power_val, 'X')) || strlen(power_val) != 14) {
    LOG_WARN(LOG_TAG, "%s: MAX POW property is not in required order", __func__);
    return false;
  } else {
    status = true;
    for (i = 0; (i < 3 && status); i++) {
      token = strtok_r(reset, "-", &reset);
      if (token && strlen(token) == 4 && (token[0] == '0' &&
         (token[1] == 'x' || token[1] == 'X') &&
         (is_byte_valid(token[2]) && is_byte_valid(token[3])))) {
      max_power_prop_value[i] = (uint8_t)strtoul(token, NULL, 16);
      } else {
        status = false;
      }
    }
  }

  if (status) {
    LOG_DEBUG(LOG_TAG, "%s MAX_POW_ID: BR MAX POW:%02x, EDR MAX POW:%02x, BLE MAX POW:%02x",
              __func__, max_power_prop_value[0], max_power_prop_value[1],
              max_power_prop_value[2]);
  } else {
    LOG_ERROR(LOG_TAG, "%s: MAX POW property is not in required order", __func__);
  }

  return status;
}
