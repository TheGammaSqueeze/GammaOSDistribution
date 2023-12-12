/*
 * Copyright 2019 The Android Open Source Project
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

#include <stdio.h>
#include "btif_bqr.h"
#include "btif_dm.h"
#include "osi/include/leaky_bonded_queue.h"
#include "osi/include/properties.h"
#include "stack/btm/btm_int.h"
#include "raw_address.h"

void btif_vendor_bqr_delivery_event(const RawAddress* bd_addr, const uint8_t* bqr_raw_data,
    uint32_t bqr_raw_data_len);

namespace bluetooth {
namespace bqr {

using system_bt_osi::LeakyBondedQueue;
using std::chrono::system_clock;

// The instance of BQR event queue
static std::unique_ptr<LeakyBondedQueue<BqrVseSubEvt>> kpBqrEventQueue(
    new LeakyBondedQueue<BqrVseSubEvt>(kBqrEventQueueSize));

bool BqrVseSubEvt::IsEvtToBeParsed(uint8_t quality_report_id) {
  switch (quality_report_id) {
    case QUALITY_REPORT_ID_MONITOR_MODE:
    case QUALITY_REPORT_ID_APPROACH_LSTO:
    case QUALITY_REPORT_ID_A2DP_AUDIO_CHOPPY:
    case QUALITY_REPORT_ID_SCO_VOICE_CHOPPY:
    case QUALITY_REPORT_ID_ROOT_INFLAMMATION:
    case QUALITY_REPORT_ID_CONNECT_FAIL:
      return true;
    default:
      return false;
  }
}

bool BqrVseSubEvt::ParseBqrEvt(uint8_t length, uint8_t* p_param_buf) {
  if (length < 1) {
    LOG(FATAL) << __func__ << ": BQR event doesn't contain report id";
    return false;
  }

  STREAM_TO_UINT8(quality_report_id_, p_param_buf);

  if (!IsEvtToBeParsed(quality_report_id_)) {
    LOG(WARNING) << __func__ << ": not need to parse report(" << loghex(quality_report_id_) << ")";
    return false;
  }
  if (quality_report_id_ == QUALITY_REPORT_ID_ROOT_INFLAMMATION) {
    return true;
  }
  if (length < kBqrParamTotalLen) {
    LOG(FATAL) << __func__
               << ": Parameter total length: " << std::to_string(length)
               << " is abnormal. It shall be not shorter than: "
               << std::to_string(kBqrParamTotalLen);
    return false;
  }

  STREAM_TO_UINT8(packet_types_, p_param_buf);
  STREAM_TO_UINT16(connection_handle_, p_param_buf);
  STREAM_TO_UINT8(connection_role_, p_param_buf);
  STREAM_TO_UINT8(tx_power_level_, p_param_buf);
  STREAM_TO_INT8(rssi_, p_param_buf);
  STREAM_TO_UINT8(snr_, p_param_buf);
  STREAM_TO_UINT8(unused_afh_channel_count_, p_param_buf);
  STREAM_TO_UINT8(afh_select_unideal_channel_count_, p_param_buf);
  STREAM_TO_UINT16(lsto_, p_param_buf);
  STREAM_TO_UINT32(connection_piconet_clock_, p_param_buf);
  STREAM_TO_UINT32(retransmission_count_, p_param_buf);
  STREAM_TO_UINT32(no_rx_count_, p_param_buf);
  STREAM_TO_UINT32(nak_count_, p_param_buf);
  STREAM_TO_UINT32(last_tx_ack_timestamp_, p_param_buf);
  STREAM_TO_UINT32(flow_off_count_, p_param_buf);
  STREAM_TO_UINT32(last_flow_on_timestamp_, p_param_buf);
  STREAM_TO_UINT32(buffer_overflow_bytes_, p_param_buf);
  STREAM_TO_UINT32(buffer_underflow_bytes_, p_param_buf);

  const auto now = system_clock::to_time_t(system_clock::now());
  localtime_r(&now, &tm_timestamp_);

  return true;
}

std::string BqrVseSubEvt::ToString() const {
  std::stringstream ss_return_string;
  ss_return_string << QualityReportIdToString(quality_report_id_)
                   << ", Handle: " << loghex(connection_handle_) << ", "
                   << PacketTypeToString(packet_types_) << ", "
                   << ((connection_role_ == 0) ? "Master" : "Slave ")
                   << ", PwLv: " << loghex(tx_power_level_)
                   << ", RSSI: " << std::to_string(rssi_)
                   << ", SNR: " << std::to_string(snr_) << ", UnusedCh: "
                   << std::to_string(unused_afh_channel_count_)
                   << ", UnidealCh: "
                   << std::to_string(afh_select_unideal_channel_count_)
                   << ", ReTx: " << std::to_string(retransmission_count_)
                   << ", NoRX: " << std::to_string(no_rx_count_)
                   << ", NAK: " << std::to_string(nak_count_)
                   << ", FlowOff: " << std::to_string(flow_off_count_)
                   << ", OverFlow: " << std::to_string(buffer_overflow_bytes_)
                   << ", UndFlow: " << std::to_string(buffer_underflow_bytes_);
  return ss_return_string.str();
}

std::string QualityReportIdToString(uint8_t quality_report_id) {
  switch (quality_report_id) {
    case QUALITY_REPORT_ID_MONITOR_MODE:
      return "Monitoring ";
    case QUALITY_REPORT_ID_APPROACH_LSTO:
      return "Appro LSTO ";
    case QUALITY_REPORT_ID_A2DP_AUDIO_CHOPPY:
      return "A2DP Choppy";
    case QUALITY_REPORT_ID_SCO_VOICE_CHOPPY:
      return "SCO Choppy ";
    case QUALITY_REPORT_ID_CONNECT_FAIL:
      return "CONNECT_FAIL ";
    default:
      return "Invalid    ";
  }
}

std::string PacketTypeToString(uint8_t packet_type) {
  switch (packet_type) {
    case PACKET_TYPE_ID:
      return "ID";
    case PACKET_TYPE_NULL:
      return "NULL";
    case PACKET_TYPE_POLL:
      return "POLL";
    case PACKET_TYPE_FHS:
      return "FHS";
    case PACKET_TYPE_HV1:
      return "HV1";
    case PACKET_TYPE_HV2:
      return "HV2";
    case PACKET_TYPE_HV3:
      return "HV3";
    case PACKET_TYPE_DV:
      return "DV";
    case PACKET_TYPE_EV3:
      return "EV3";
    case PACKET_TYPE_EV4:
      return "EV4";
    case PACKET_TYPE_EV5:
      return "EV5";
    case PACKET_TYPE_2EV3:
      return "2EV3";
    case PACKET_TYPE_2EV5:
      return "2EV5";
    case PACKET_TYPE_3EV3:
      return "3EV3";
    case PACKET_TYPE_3EV5:
      return "3EV5";
    case PACKET_TYPE_DM1:
      return "DM1";
    case PACKET_TYPE_DH1:
      return "DH1";
    case PACKET_TYPE_DM3:
      return "DM3";
    case PACKET_TYPE_DH3:
      return "DH3";
    case PACKET_TYPE_DM5:
      return "DM5";
    case PACKET_TYPE_DH5:
      return "DH5";
    case PACKET_TYPE_AUX1:
      return "AUX1";
    case PACKET_TYPE_2DH1:
      return "2DH1";
    case PACKET_TYPE_2DH3:
      return "2DH3";
    case PACKET_TYPE_2DH5:
      return "2DH5";
    case PACKET_TYPE_3DH1:
      return "3DH1";
    case PACKET_TYPE_3DH3:
      return "3DH3";
    case PACKET_TYPE_3DH5:
      return "3DH5";
    default:
      return "UnKnown ";
  }
}

void AddBqrEventToQueue(uint8_t length, uint8_t* p_stream) {
  std::unique_ptr<BqrVseSubEvt> p_bqr_event = std::make_unique<BqrVseSubEvt>();
  if (!p_bqr_event->ParseBqrEvt(length, p_stream)) {
    LOG(WARNING) << __func__ << ": Fail to parse BQR sub event.";
    return;
  }
  /* BQR RIE Crash reason frame format:
    * 0xff for VSE | 0x04 for parameter length | 0x58 for BQR sub-event code
    * | 0x05 for root inflammation event | 0x00 for error code | 0x** for vendor
    * specific error code(crash reason) | [optional: 0x** for number of vendor specific
    * parameters | 0x** for first parameter id | 0x** for length of first parameter |
    * 0x** for first parameter value | ..so on..]
    */
  if (p_bqr_event->quality_report_id_ == QUALITY_REPORT_ID_ROOT_INFLAMMATION) {
    uint8_t error_code, vendor_error_code;
    STREAM_SKIP_UINT8(p_stream);
    STREAM_TO_UINT8(error_code, p_stream);
    STREAM_TO_UINT8(vendor_error_code, p_stream);
    std::string vs_params = "";
    // Check if we have optional vendor specific params available.
    if (length > bluetooth::bqr::kRootInflammationParamTotalLen) {
      uint8_t param_id, num_of_vs_params;
      STREAM_TO_UINT8(num_of_vs_params, p_stream);
      int pending_bytes = length - bluetooth::bqr::kRootInflammationParamTotalLen - 1;
      vs_params = " vendor specific params: ";
      for (uint8_t i = 1; i <= num_of_vs_params && pending_bytes > 0; ++i) {
        STREAM_TO_UINT8(param_id, p_stream);
        pending_bytes--;
        if (pending_bytes > 0) {
          vs_params += ParseVsBqrRieParams((BqrRieVsParamsId)param_id, &p_stream, pending_bytes);
        }
      }
    }
    LOG(ERROR) << __func__ << " : BQR Root inflammation Reported, error code = "
               << loghex(error_code) << " vendor specific error code = "
               << loghex(vendor_error_code) << vs_params;
    return;
  }
  LOG(WARNING) << *p_bqr_event;

  if (length >= kBqrParamTotalLen + BD_ADDR_LEN) {
    RawAddress bd_addr;
    uint8_t* p_addr = p_stream + kBqrParamTotalLen;
    STREAM_TO_BDADDR(bd_addr, p_addr);
    btif_vendor_bqr_delivery_event(&bd_addr, p_stream, length);
  } else {
    LOG(WARNING) << __func__ << ": BQR event doesn't contain remote address";
  }

  kpBqrEventQueue->Enqueue(p_bqr_event.release());
}

void ConfigBqrA2dpScoThreshold() {
  uint8_t param[20] = {0};
  uint8_t sub_opcode = 0x16;
  uint8_t *p_param = param;
  uint16_t a2dp_choppy_threshold = 0;
  uint16_t sco_choppy_threshold = 0;

  char bqr_prop_threshold[PROPERTY_VALUE_MAX] = {0};
  osi_property_get(kpPropertyChoppyThreshold, bqr_prop_threshold, "");

  sscanf(bqr_prop_threshold, "%hu,%hu", &a2dp_choppy_threshold, &sco_choppy_threshold);

  LOG(WARNING) << __func__<< ": a2dp_choppy_threshold: " << a2dp_choppy_threshold
               << ", sco_choppy_threshold: " << sco_choppy_threshold;

  UINT8_TO_STREAM(p_param, sub_opcode);

  // A2dp glitch ID
  UINT8_TO_STREAM(p_param, QUALITY_REPORT_ID_A2DP_AUDIO_CHOPPY);
  // A2dp glitch config data length
  UINT8_TO_STREAM(p_param, 2);
  // A2dp glitch threshold
  UINT16_TO_STREAM(p_param, a2dp_choppy_threshold == 0 ? 1 : a2dp_choppy_threshold);

  // Sco glitch ID
  UINT8_TO_STREAM(p_param, QUALITY_REPORT_ID_SCO_VOICE_CHOPPY);
  // Sco glitch config data length
  UINT8_TO_STREAM(p_param, 2);
  // Sco glitch threshold
  UINT16_TO_STREAM(p_param, sco_choppy_threshold == 0 ? 1 : sco_choppy_threshold);

  BTM_VendorSpecificCommand(HCI_VS_HOST_LOG_OPCODE, p_param - param, param, NULL);
}

void ConfigureBqrCmpl(uint32_t current_evt_mask) {
  LOG(INFO) << __func__ << ": current_evt_mask: " << loghex(current_evt_mask);
  // (Un)Register for VSE of Bluetooth Quality Report sub event
  tBTM_STATUS btm_status = BTM_BT_Quality_Report_VSE_Register(
      current_evt_mask > kQualityEventMaskAllOff, AddBqrEventToQueue);

  if (btm_status != BTM_SUCCESS) {
    LOG(ERROR) << __func__ << ": Fail to (un)register VSE of BQR sub event."
               << " status: " << btm_status;
  }

  if (current_evt_mask > kQualityEventMaskAllOff) {
    ConfigBqrA2dpScoThreshold();
  }
}

void EnableBtQualityReport(bool is_enable) {
  LOG(INFO) << __func__ << ": is_enable: " << (is_enable);

  char bqr_prop_evtmask[PROPERTY_VALUE_MAX] = {0};
  char bqr_prop_interval_ms[PROPERTY_VALUE_MAX] = {0};
  osi_property_get(kpPropertyEventMask, bqr_prop_evtmask, "");
  osi_property_get(kpPropertyMinReportIntervalMs, bqr_prop_interval_ms, "");

  if (strlen(bqr_prop_evtmask) == 0 || strlen(bqr_prop_interval_ms) == 0) {
   /* By default BQR RIE is enabled and since BQR RIE dont depend on SoC,
    * report interval is 0.
    * For enabling BQR RIE 4th bit should be set considering indexing from 0.
    */
    strlcpy(bqr_prop_evtmask, "16", sizeof(bqr_prop_evtmask));
    strlcpy(bqr_prop_interval_ms, "0", sizeof(bqr_prop_interval_ms));
    LOG(WARNING) << __func__ << ": Bluetooth Quality Report - Root inflammation"
                 << " event enabled," <<" bqr_prop_evtmask: " << bqr_prop_evtmask
                 << ", bqr_prop_interval_ms: " << bqr_prop_interval_ms;
  } else {
    LOG(WARNING) << __func__ << ": Bluetooth Quality Report enabled"
                 <<" bqr_prop_evtmask: " << bqr_prop_evtmask
                 << ", bqr_prop_interval_ms: " << bqr_prop_interval_ms;
  }

  BqrConfiguration bqr_config = {};
  if (is_enable) {
    bqr_config.report_action = REPORT_ACTION_ADD;
    bqr_config.quality_event_mask =
        static_cast<uint32_t>(atoi(bqr_prop_evtmask));
    if (!(bqr_config.quality_event_mask & kQualityEventMaskRootInflammation)) {
      LOG(WARNING) << __func__ << "Enabling Bluetooth Quality Report - Root inflammation event";
      // Enable BQR RIE by default.
      bqr_config.quality_event_mask = bqr_config.quality_event_mask | kQualityEventMaskRootInflammation;
    }
#ifdef BLUEDROID_DEBUG
    // Enable FW dumps by default in userdebug/eng. builds.
    bqr_config.quality_event_mask = bqr_config.quality_event_mask | kQualityEventMaskDebugInfo;
#endif
    bqr_config.minimum_report_interval_ms =
        static_cast<uint16_t>(atoi(bqr_prop_interval_ms));
  } else {
    bqr_config.report_action = REPORT_ACTION_DELETE;
    bqr_config.quality_event_mask = kQualityEventMaskAll;
#ifdef BLUEDROID_DEBUG
    // Dont disable FW dumps in userdebug/eng. builds.
    bqr_config.quality_event_mask = bqr_config.quality_event_mask & ~kQualityEventMaskDebugInfo;
#endif
    bqr_config.minimum_report_interval_ms = kMinReportIntervalNoLimit;
  }

  LOG(INFO) << __func__
            << ": Event Mask: " << loghex(bqr_config.quality_event_mask)
            << ", Interval: " << bqr_config.minimum_report_interval_ms;
  ConfigureBqr(bqr_config);
}

void BqrVscCompleteCallback(tBTM_VSC_CMPL* p_vsc_cmpl_params) {
  if (p_vsc_cmpl_params->param_len < 1) {
    LOG(ERROR) << __func__ << ": The length of returned parameters is less than 1";
    return;
  }

  uint8_t* p_event_param_buf = p_vsc_cmpl_params->p_param_buf;
  uint8_t status = 0xff;
  // [Return Parameter]         | [Size]   | [Purpose]
  // Status                     | 1 octet  | Command complete status
  // Current_Quality_Event_Mask | 4 octets | Indicates current bit mask setting
  STREAM_TO_UINT8(status, p_event_param_buf);
  if (status != HCI_SUCCESS) {
    LOG(ERROR) << __func__ << ": Fail to configure BQR. status: " << loghex(status);
    return;
  }

  if (p_vsc_cmpl_params->param_len != 5) {
    LOG(FATAL) << __func__
               << ": The length of returned parameters is not equal to 5: "
               << std::to_string(p_vsc_cmpl_params->param_len);
    return;
  }

  uint32_t current_quality_event_mask = kQualityEventMaskAllOff;
  STREAM_TO_UINT32(current_quality_event_mask, p_event_param_buf);

  LOG(INFO) << __func__
            << ", current event mask: " << loghex(current_quality_event_mask);
  ConfigureBqrCmpl(current_quality_event_mask);
}

void ConfigureBqr(const BqrConfiguration& bqr_config) {
  if (bqr_config.report_action > REPORT_ACTION_CLEAR ||
      bqr_config.quality_event_mask > kQualityEventMaskAll ||
      bqr_config.minimum_report_interval_ms > kMinReportIntervalMaxMs) {
    LOG(FATAL) << __func__ << ": Invalid Parameter"
               << ", Action: " << (int)bqr_config.report_action
               << ", Mask: " << loghex(bqr_config.quality_event_mask)
               << ", Interval: " << bqr_config.minimum_report_interval_ms;
    return;
  }

  LOG(INFO) << __func__ << ": Action: " << bqr_config.report_action
            << ", Mask: " << loghex(bqr_config.quality_event_mask)
            << ", Interval: " << bqr_config.minimum_report_interval_ms;

  uint8_t param[sizeof(BqrConfiguration)];
  uint8_t* p_param = param;
  UINT8_TO_STREAM(p_param, bqr_config.report_action);
  UINT32_TO_STREAM(p_param, bqr_config.quality_event_mask);
  UINT16_TO_STREAM(p_param, bqr_config.minimum_report_interval_ms);

  BTM_VendorSpecificCommand(HCI_CONTROLLER_BQR_OPCODE_OCF, p_param - param,
                            param, BqrVscCompleteCallback);
}

void DebugDump(int fd) {
  dprintf(fd, "\nBT Quality Report Events: \n");

  if (kpBqrEventQueue->Empty()) {
    dprintf(fd, "Event queue is empty.\n");
    return;
  }

  while (!kpBqrEventQueue->Empty()) {
    std::unique_ptr<BqrVseSubEvt> p_event(kpBqrEventQueue->Dequeue());

    bool warning = (p_event->rssi_ < kCriWarnRssi ||
                    p_event->unused_afh_channel_count_ > kCriWarnUnusedCh);

    std::stringstream ss_timestamp;
    ss_timestamp << std::put_time(&p_event->tm_timestamp_, "%m-%d %H:%M:%S");

    dprintf(fd, "%c  %s %s\n", warning ? '*' : ' ', ss_timestamp.str().c_str(),
            p_event->ToString().c_str());
  }

  dprintf(fd, "\n");
}

std::string ParseVsBqrRieParams(BqrRieVsParamsId param_id,
                                  uint8_t** p_stream, int& pending_bytes) {
  uint8_t param_length;
  STREAM_TO_UINT8(param_length, *p_stream);
  pending_bytes--;
  std::stringstream ss;
  auto parse_array_of_bytes = [&] () {
    pending_bytes -= param_length;
    uint8_t current_byte;
    for (int i = 0; i < param_length; ++i) {
      STREAM_TO_UINT8(current_byte, *p_stream);
      ss << std::uppercase << std::hex << (int)current_byte << " ";
    }
  };
  switch(param_id) {
    case PC_ADDRESS: {
      ss << " PC_ADDRESS: ";
      if (pending_bytes < param_length || param_length != sizeof(uint32_t)) {
        LOG(ERROR) << __func__ << " BQR RIE VS parameter ID " << (int)param_id
                   << " has invalid value or length, ignoring rest of payload";
        ss << "Invalid pc address value/length";
        // Dont parse rest of payload as it might be corrupted and give wrong information.
        pending_bytes = 0;
      } else {
        uint32_t pc_address;
        pending_bytes -= param_length;
        STREAM_TO_UINT32(pc_address, *p_stream);
        ss << std::showbase << std::uppercase << std::hex << pc_address;
      }
      break;
    }
    case MINI_DUMP: {
      ss << " MINI_DUMP: ";
      if (pending_bytes < param_length) {
        LOG(ERROR) << __func__ << " BQR RIE VS parameter ID " << (int)param_id
                   << " has invalid value, ignoring rest of payload";
        ss << "Invalid MINI_DUMP";
        // Dont parse rest of payload as it might be corrupted and give wrong information.
        pending_bytes = 0;
      } else {
        parse_array_of_bytes();
      }
      break;
    }
    case HCI_BUFFER_DUMP: {
      ss << " HCI_BUFFER_DUMP: ";
      if (pending_bytes < param_length) {
        LOG(ERROR) << __func__ << " BQR RIE VS parameter ID " << (int)param_id
                   << " has invalid value, ignoring rest of payload";
        ss << "Invalid HCI_BUFFER_DUMP";
        // Dont parse rest of payload as it might be corrupted and give wrong information.
        pending_bytes = 0;
      } else {
        parse_array_of_bytes();
      }
      break;
    }
    default:
      LOG(ERROR) << __func__ << " BQR RIE VS parameter ID " << (int)param_id
                 << " not found, skipping bytes for this parameter";
      for(int i = 0;i < param_length && pending_bytes > 0; ++i) {
          pending_bytes--;
          STREAM_SKIP_UINT8(*p_stream);
      }
      break;
  }
  return ss.str();
}

}  // namespace bqr
}  // namespace bluetooth
