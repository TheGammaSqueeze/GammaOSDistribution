/*
 * Copyright (C) 2020, The Linux Foundation. All rights reserved.
 * Not a Contribution.
 */
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

#include "a2dp_encoding.h"
#include "client_interface.h"

#include "a2dp_sbc_constants.h"
#include "a2dp_vendor_ldac_constants.h"
#include "a2dp_vendor_aptx_adaptive.h"
#include "a2dp_aac.h"
#include "bta/av/bta_av_int.h"
#include "btif_a2dp_source.h"
#include "btif_av.h"
#include "btif_av_co.h"
#include "btif_hf.h"
#include "osi/include/properties.h"
#include "a2dp_sbc.h"
#include <a2dp_vendor.h>
#include "controller.h"
#include "btif_bat.h"
#include "btif_ahim.h"

extern bool audio_start_awaited;
extern void btif_av_reset_reconfig_flag();
extern bool btif_av_current_device_is_tws();
extern void btif_a2dp_source_encoder_init(void);

#define AAC_SAMPLE_SIZE  1024
#define AAC_LATM_HEADER  12

namespace {

using vendor::qti::hardware::bluetooth_audio::V2_0::AacObjectType;
using vendor::qti::hardware::bluetooth_audio::V2_0::AacVariableBitRate;
using CodecType =
      vendor::qti::hardware::bluetooth_audio::V2_0::CodecType;
using CodecType_2_1 =
      vendor::qti::hardware::bluetooth_audio::V2_1::CodecType;
using vendor::qti::hardware::bluetooth_audio::V2_0::LdacChannelMode;
using vendor::qti::hardware::bluetooth_audio::V2_0::LdacQualityIndex;
using vendor::qti::hardware::bluetooth_audio::V2_0::SbcAllocMethod;
using vendor::qti::hardware::bluetooth_audio::V2_0::SbcBlockLength;
using vendor::qti::hardware::bluetooth_audio::V2_0::SbcChannelMode;
using vendor::qti::hardware::bluetooth_audio::V2_0::SbcNumSubbands;
using vendor::qti::hardware::bluetooth_audio::V2_0::AptxAdaptiveChannelMode;
using vendor::qti::hardware::bluetooth_audio::V2_0::AptxMode;
using vendor::qti::hardware::bluetooth_audio::V2_0::SessionParams;
using vendor::qti::hardware::bluetooth_audio::V2_0::SessionParamType;
using vendor::qti::hardware::bluetooth_audio::V2_0::SinkLatency;
using vendor::qti::hardware::bluetooth_audio::V2_0::InputMode;
using AudioConfiguration = vendor::qti::hardware::bluetooth_audio::V2_0::AudioConfiguration;
using AudioConfiguration_2_1 = vendor::qti::hardware::bluetooth_audio::V2_1::AudioConfiguration;
using CodecConfiguration =
      vendor::qti::hardware::bluetooth_audio::V2_0::CodecConfiguration;
using CodecConfiguration_2_1 =
      vendor::qti::hardware::bluetooth_audio::V2_1::CodecConfiguration;
using vendor::qti::hardware::bluetooth_audio::V2_1::ExtSampleRate;
using vendor::qti::hardware::bluetooth_audio::V2_1::LC3ChannelMode;
//using ::bluetooth::audio::AudioConfiguration;
using ::bluetooth::audio::BitsPerSample;
using ::bluetooth::audio::BluetoothAudioCtrlAck;
using ::bluetooth::audio::ChannelMode;
//using ::bluetooth::audio::CodecConfiguration;
using ::bluetooth::audio::PcmParameters;
using ::bluetooth::audio::SampleRate;
using ::bluetooth::audio::SessionType;

std::mutex internal_mutex_;
std::condition_variable ack_wait_cv;
tA2DP_CTRL_ACK ack_status;

#define BA_SIMULCAST 3
#define CHANNEL_MONO 0x00000000 //Mono/Unspecified
#define CHANNEL_FL   0x00000001 //Front Left
#define CHANNEL_FR   0x00000002 //Front Right
#define CHANNEL_FC   0x00000004 //Front Centre
#define CHANNEL_LFE  0x00000008 //Low Frequency Effect
#define CHANNEL_BL   0x00000010 //Back Left
#define CHANNEL_BR   0x00000020 //Back Right
#define FROM_AIR     0x01
#define TO_AIR       0x00

#define  ADV_AUD_CODEC_SAMPLE_RATE_NONE    0x0
#define  ADV_AUD_CODEC_SAMPLE_RATE_44100   0x1 << 0
#define  ADV_AUD_CODEC_SAMPLE_RATE_48000   0x1 << 1
#define  ADV_AUD_CODEC_SAMPLE_RATE_88200   0x1 << 2
#define  ADV_AUD_CODEC_SAMPLE_RATE_96000   0x1 << 3
#define  ADV_AUD_CODEC_SAMPLE_RATE_176400  0x1 << 4
#define  ADV_AUD_CODEC_SAMPLE_RATE_192000  0x1 << 5
#define  ADV_AUD_CODEC_SAMPLE_RATE_16000   0x1 << 6
#define  ADV_AUD_CODEC_SAMPLE_RATE_24000   0x1 << 7
#define  ADV_AUD_CODEC_SAMPLE_RATE_32000   0x1 << 8
#define  ADV_AUD_CODEC_SAMPLE_RATE_8000    0x1 << 9

#define WMCP_PROFILE       0x04
#define GCP_RX_PROFILE     0x20

#define  RX_ONLY_CONFIG    0x1
#define  TX_ONLY_CONFIG    0x2
#define  TX_RX_BOTH_CONFIG 0x3

BluetoothAudioCtrlAck a2dp_ack_to_bt_audio_ctrl_ack(tA2DP_CTRL_ACK ack);

// Provide call-in APIs for the Bluetooth Audio HAL
class A2dpTransport : public ::bluetooth::audio::IBluetoothTransportInstance {
 public:
  A2dpTransport(SessionType sessionType, AudioConfiguration audioConfig)
      : IBluetoothTransportInstance(sessionType, std::move(audioConfig)),
        a2dp_pending_cmd_(A2DP_CTRL_CMD_NONE),
        remote_delay_report_(0),
        total_bytes_read_(0),
        data_position_({}){};

  BluetoothAudioCtrlAck StartRequest() override {
    // Check if a previous request is not finished
    /*
     * Don't send START request to stack while we are in a call.
     * Some headsets such as "Sony MW600", don't allow AVDTP START
     * while in a call, and respond with BAD_STATE.
     */
    tA2DP_CTRL_ACK status = A2DP_CTRL_ACK_FAILURE;
    if(!IsActvie()) {
      LOG(WARNING) << __func__ << ": Not active";
      return a2dp_ack_to_bt_audio_ctrl_ack(status);
    }
    status = ProcessRequest(A2DP_CTRL_CMD_START);
    return a2dp_ack_to_bt_audio_ctrl_ack(status);
  }

  BluetoothAudioCtrlAck SuspendRequest() override {
    tA2DP_CTRL_ACK status = A2DP_CTRL_ACK_FAILURE;
    if(!IsActvie()) {
      LOG(WARNING) << __func__ << ": Not active";
      return a2dp_ack_to_bt_audio_ctrl_ack(status);
    }
    status = ProcessRequest(A2DP_CTRL_CMD_SUSPEND);
    return a2dp_ack_to_bt_audio_ctrl_ack(status);
  }

  void StopRequest() override {
    if(!IsActvie()) {
      LOG(WARNING) << __func__ << ": Not active";
      return;
    }
    ProcessRequest(A2DP_CTRL_CMD_STOP);
  }

  bool GetPresentationPosition(uint64_t* remote_delay_report,
                               uint64_t* total_bytes_read,
                               timespec* data_position) override {
    if(!IsActvie()) {
      LOG(WARNING) << __func__ << ": Not active";
      return false;
    }
    *remote_delay_report = remote_delay_report_;
    *total_bytes_read = total_bytes_read_;
    *data_position = data_position_;
    VLOG(2) << __func__ << ": delay=" << remote_delay_report_
            << "/10ms, data=" << total_bytes_read_
            << " byte(s), timestamp=" << data_position_.tv_sec << "."
            << data_position_.tv_nsec << "s";
    return true;
  }

  void UpdatePendingCmd(tA2DP_CTRL_CMD cmd) {
    a2dp_pending_cmd_ = cmd;
  }

  tA2DP_CTRL_CMD GetPendingCmd() const { return a2dp_pending_cmd_; }

  void ResetPendingCmd() {
    LOG(WARNING) << "ResetPendingCmd  " << a2dp_pending_cmd_;
    a2dp_pending_cmd_ = A2DP_CTRL_CMD_NONE;
 }

  void ResetPresentationPosition() override {
    remote_delay_report_ = 0;
    total_bytes_read_ = 0;
    data_position_ = {};
  }

  void LogBytesRead(size_t bytes_read) override {
    if (bytes_read != 0) {
      total_bytes_read_ += bytes_read;
      clock_gettime(CLOCK_MONOTONIC, &data_position_);
    }
  }

  // delay reports from AVDTP is based on 1/10 ms (100us)
  void SetRemoteDelay(uint16_t delay_report) {
    remote_delay_report_ = delay_report;
  }

  void Init(SessionType sessionType, AudioConfiguration audioConfig) {
    a2dp_pending_cmd_ = A2DP_CTRL_CMD_NONE;
    remote_delay_report_ = 0;
    total_bytes_read_ = 0;
    data_position_ = {};
    UpdateSessionType(sessionType);
    UpdateAudioConfiguration(audioConfig);
  }

  void Cleanup() {
    a2dp_pending_cmd_ = A2DP_CTRL_CMD_NONE;
    remote_delay_report_ = 0;
    total_bytes_read_ = 0;
    data_position_ = {};
    SessionType sessionType = SessionType::UNKNOWN;
    UpdateSessionType(sessionType);
  }

 private:
  tA2DP_CTRL_ACK ProcessRequest(tA2DP_CTRL_CMD cmd) {
    ack_status = A2DP_CTRL_ACK_PENDING;
    btif_dispatch_sm_event(BTIF_AV_PROCESS_HIDL_REQ_EVT, (char*)&cmd,
                           sizeof(cmd));
    return ack_status;
  }
  tA2DP_CTRL_CMD a2dp_pending_cmd_;
  uint16_t remote_delay_report_;
  uint64_t total_bytes_read_;
  timespec data_position_;

};
class A2dpTransport_2_1 : public ::bluetooth::audio::IBluetoothTransportInstance_2_1 {
 public:
  A2dpTransport_2_1(SessionType sessionType, AudioConfiguration_2_1 audioConfig)
      : IBluetoothTransportInstance_2_1(sessionType, std::move(audioConfig)),
        a2dp_pending_cmd_(A2DP_CTRL_CMD_NONE),
        remote_delay_report_(0),
        total_bytes_read_(0),
        data_position_({}){};

  BluetoothAudioCtrlAck StartRequest() override {
    // Check if a previous request is not finished
    /*
     * Don't send START request to stack while we are in a call.
     * Some headsets such as "Sony MW600", don't allow AVDTP START
     * while in a call, and respond with BAD_STATE.
     */
    tA2DP_CTRL_ACK status = A2DP_CTRL_ACK_FAILURE;
    if(!IsActvie()) {
      LOG(WARNING) << __func__ << ": Not active";
      return a2dp_ack_to_bt_audio_ctrl_ack(status);
    }
    status = ProcessRequest(A2DP_CTRL_CMD_START);
    return a2dp_ack_to_bt_audio_ctrl_ack(status);
  }

  BluetoothAudioCtrlAck SuspendRequest() override {
    tA2DP_CTRL_ACK status = A2DP_CTRL_ACK_FAILURE;
    if(!IsActvie()) {
      LOG(WARNING) << __func__ << ": Not active";
      return a2dp_ack_to_bt_audio_ctrl_ack(status);
    }
    status = ProcessRequest(A2DP_CTRL_CMD_SUSPEND);
    return a2dp_ack_to_bt_audio_ctrl_ack(status);
  }

  void StopRequest() override {
    if(!IsActvie()) {
      LOG(WARNING) << __func__ << ": Not active";
      return;
    }
    ProcessRequest(A2DP_CTRL_CMD_STOP);
  }

  bool GetPresentationPosition(uint64_t* remote_delay_report,
                               uint64_t* total_bytes_read,
                               timespec* data_position) override {
    if(!IsActvie()) {
      LOG(WARNING) << __func__ << ": Not active";
      return false;
    }
    *remote_delay_report = remote_delay_report_;
    *total_bytes_read = total_bytes_read_;
    *data_position = data_position_;
    VLOG(2) << __func__ << ": delay=" << remote_delay_report_
            << "/10ms, data=" << total_bytes_read_
            << " byte(s), timestamp=" << data_position_.tv_sec << "."
            << data_position_.tv_nsec << "s";
    return true;
  }

  void UpdatePendingCmd(tA2DP_CTRL_CMD cmd) {
    a2dp_pending_cmd_ = cmd;
  }

  tA2DP_CTRL_CMD GetPendingCmd() const { return a2dp_pending_cmd_; }

  void ResetPendingCmd() {
    LOG(WARNING) << "ResetPendingCmd  " << a2dp_pending_cmd_;
    a2dp_pending_cmd_ = A2DP_CTRL_CMD_NONE;
 }

  void ResetPresentationPosition() override {
    remote_delay_report_ = 0;
    total_bytes_read_ = 0;
    data_position_ = {};
  }

  void LogBytesRead(size_t bytes_read) override {
    if (bytes_read != 0) {
      total_bytes_read_ += bytes_read;
      clock_gettime(CLOCK_MONOTONIC, &data_position_);
    }
  }

  // delay reports from AVDTP is based on 1/10 ms (100us)
  void SetRemoteDelay(uint16_t delay_report) {
    remote_delay_report_ = delay_report;
  }

  void Init(SessionType sessionType, AudioConfiguration_2_1 audioConfig) {
    a2dp_pending_cmd_ = A2DP_CTRL_CMD_NONE;
    remote_delay_report_ = 0;
    total_bytes_read_ = 0;
    data_position_ = {};
    UpdateSessionType(sessionType);
    UpdateAudioConfiguration(audioConfig);
  }

  void Cleanup() {
    a2dp_pending_cmd_ = A2DP_CTRL_CMD_NONE;
    remote_delay_report_ = 0;
    total_bytes_read_ = 0;
    data_position_ = {};
    SessionType sessionType = SessionType::UNKNOWN;
    UpdateSessionType(sessionType);
  }

 private:
  tA2DP_CTRL_ACK ProcessRequest(tA2DP_CTRL_CMD cmd) {
    ack_status = A2DP_CTRL_ACK_PENDING;
#if AHIM_ENABLED
    btif_ahim_process_request(cmd);
#else
    btif_dispatch_sm_event(BTIF_AV_PROCESS_HIDL_REQ_EVT, (char*)&cmd,
                          sizeof(cmd));
#endif
    return ack_status;
  }
  tA2DP_CTRL_CMD a2dp_pending_cmd_;
  uint16_t remote_delay_report_;
  uint64_t total_bytes_read_;
  timespec data_position_;

};

A2dpTransport* a2dp_sink = nullptr;
A2dpTransport_2_1* a2dp_sink_2_1 = nullptr;
thread_t* death_handler_thread = nullptr;

// Common interface to call-out into Bluetooth Audio HAL
bluetooth::audio::BluetoothAudioClientInterface* a2dp_hal_clientif = nullptr;
auto session_type = SessionType::UNKNOWN;
btav_a2dp_codec_index_t sw_codec_type = BTAV_A2DP_CODEC_INDEX_SOURCE_MIN;
uint16_t session_peer_mtu = 0;

// Save the value if the remote reports its delay before a2dp_sink is
// initialized
uint16_t remote_delay = 0;

bool is_session_started = false;
bool btaudio_a2dp_supported = false;
bool is_configured = false;
bool is_playing = false;
bool is_hal_version_fetched = false;
bool hal_2_1_enabled = false;

BluetoothAudioCtrlAck a2dp_ack_to_bt_audio_ctrl_ack(tA2DP_CTRL_ACK ack) {
  switch (ack) {
    case A2DP_CTRL_ACK_SUCCESS:
      return BluetoothAudioCtrlAck::SUCCESS_FINISHED;
    case A2DP_CTRL_ACK_PENDING:
      return BluetoothAudioCtrlAck::PENDING;
    case A2DP_CTRL_ACK_INCALL_FAILURE:
      return BluetoothAudioCtrlAck::FAILURE_BUSY;
    case A2DP_CTRL_ACK_DISCONNECT_IN_PROGRESS:
      return BluetoothAudioCtrlAck::FAILURE_DISCONNECTING;
    case A2DP_CTRL_ACK_UNSUPPORTED: /* Offloading but resource failure */
      return BluetoothAudioCtrlAck::FAILURE_UNSUPPORTED;
    case A2DP_CTRL_ACK_FAILURE:
      return BluetoothAudioCtrlAck::FAILURE;
    case A2DP_CTRL_ACK_LONG_WAIT_ERR:
      return BluetoothAudioCtrlAck::FAILURE_LONG_WAIT;
    default:
      return BluetoothAudioCtrlAck::FAILURE;
  }
}

SampleRate a2dp_codec_to_hal_sample_rate(
    const btav_a2dp_codec_config_t& a2dp_codec_config) {
  switch (a2dp_codec_config.sample_rate) {
    case BTAV_A2DP_CODEC_SAMPLE_RATE_44100:
      return SampleRate::RATE_44100;
    case BTAV_A2DP_CODEC_SAMPLE_RATE_48000:
      return SampleRate::RATE_48000;
    case BTAV_A2DP_CODEC_SAMPLE_RATE_88200:
      return SampleRate::RATE_88200;
    case BTAV_A2DP_CODEC_SAMPLE_RATE_96000:
      return SampleRate::RATE_96000;
    case BTAV_A2DP_CODEC_SAMPLE_RATE_176400:
      return SampleRate::RATE_176400;
    case BTAV_A2DP_CODEC_SAMPLE_RATE_192000:
      return SampleRate::RATE_192000;
    case BTAV_A2DP_CODEC_SAMPLE_RATE_16000:
      return SampleRate::RATE_16000;
    case BTAV_A2DP_CODEC_SAMPLE_RATE_24000:
      return SampleRate::RATE_24000;
    default:
      return SampleRate::RATE_UNKNOWN;
  }
}

BitsPerSample a2dp_codec_to_hal_bits_per_sample(
    const btav_a2dp_codec_config_t& a2dp_codec_config) {
  switch (a2dp_codec_config.bits_per_sample) {
    case BTAV_A2DP_CODEC_BITS_PER_SAMPLE_16:
      return BitsPerSample::BITS_16;
    case BTAV_A2DP_CODEC_BITS_PER_SAMPLE_24:
      return BitsPerSample::BITS_24;
    case BTAV_A2DP_CODEC_BITS_PER_SAMPLE_32:
      return BitsPerSample::BITS_32;
    default:
      return BitsPerSample::BITS_UNKNOWN;
  }
}

ChannelMode a2dp_codec_to_hal_channel_mode(
    const btav_a2dp_codec_config_t& a2dp_codec_config) {
  switch (a2dp_codec_config.channel_mode) {
    case BTAV_A2DP_CODEC_CHANNEL_MODE_MONO:
      return ChannelMode::MONO;
    case BTAV_A2DP_CODEC_CHANNEL_MODE_STEREO:
      return ChannelMode::STEREO;
    default:
      return ChannelMode::UNKNOWN;
  }
}

LdacQualityIndex a2dp_codec_to_hal_ldac_quality_index (
    const btav_a2dp_codec_config_t& a2dp_codec_config) {
  switch (a2dp_codec_config.codec_specific_1) {
    case 1000:
      return LdacQualityIndex::QUALITY_HIGH;
    case 1001:
      return LdacQualityIndex::QUALITY_MID;
    case 1002:
      return LdacQualityIndex::QUALITY_LOW;
    case 1003:
      return LdacQualityIndex::QUALITY_ABR;
    default:
      return LdacQualityIndex::QUALITY_ABR;
  }
}

uint16_t ba_codec_to_hal_frame_size(uint8_t frame_size) {
  uint16_t ba_hal_frame_size = 512;
  switch(frame_size)
  {
    case A2D_CELT_FRAME_SIZE_64:
        ba_hal_frame_size = 64;
        break;
    case A2D_CELT_FRAME_SIZE_128:
        ba_hal_frame_size = 128;
        break;
    case A2D_CELT_FRAME_SIZE_256:
        ba_hal_frame_size = 256;
        break;
    case A2D_CELT_FRAME_SIZE_512:
        ba_hal_frame_size = 512;
        break;
    default:
        ALOGE("CELT: unknown frame size");
  }
  return ba_hal_frame_size;
}

ChannelMode ba_codec_to_hal_channel_mode(uint8_t channel_mode) {
  switch (channel_mode) {
    case A2D_CELT_CH_MONO:
      return ChannelMode::MONO;
    case A2D_CELT_CH_STEREO:
      return ChannelMode::STEREO;
    default:
      return ChannelMode::UNKNOWN;
  }
}

SampleRate ba_codec_to_hal_sample_rate(uint8_t sample_rate) {
  switch (sample_rate) {
    case A2D_CELT_SAMP_FREQ_44:
      return SampleRate::RATE_44100;
    case A2D_CELT_SAMP_FREQ_48:
      return SampleRate::RATE_48000;
    case A2D_CELT_SAMP_FREQ_32:
      return SampleRate::RATE_32000;
    default:
      return SampleRate::RATE_UNKNOWN;
  }
}

ExtSampleRate btif_lc3_sample_rate(uint16_t rate) {
  LOG(ERROR) << __func__
               << ": sample_rate: " << rate;

  switch (rate) {
    case ADV_AUD_CODEC_SAMPLE_RATE_44100:
      return ExtSampleRate::RATE_44100;
    case ADV_AUD_CODEC_SAMPLE_RATE_48000:
      return ExtSampleRate::RATE_48000;
    case ADV_AUD_CODEC_SAMPLE_RATE_32000:
      return ExtSampleRate::RATE_32000;
    case ADV_AUD_CODEC_SAMPLE_RATE_24000:
      return ExtSampleRate::RATE_24000_2;
    case ADV_AUD_CODEC_SAMPLE_RATE_16000:
      return ExtSampleRate::RATE_16000;
    case ADV_AUD_CODEC_SAMPLE_RATE_8000:
      return ExtSampleRate::RATE_8000;
    case ADV_AUD_CODEC_SAMPLE_RATE_88200:
      return ExtSampleRate::RATE_88200;
    case ADV_AUD_CODEC_SAMPLE_RATE_96000:
      return ExtSampleRate::RATE_96000;
    case ADV_AUD_CODEC_SAMPLE_RATE_176400:
      return ExtSampleRate::RATE_176400;
    case ADV_AUD_CODEC_SAMPLE_RATE_192000:
      return ExtSampleRate::RATE_192000;
    default:
      return ExtSampleRate::RATE_UNKNOWN;
  }
}

LC3ChannelMode btif_lc3_channel_mode(uint8_t mode) {
  switch (mode) {
    case BTAV_A2DP_CODEC_CHANNEL_MODE_MONO:
      return LC3ChannelMode::MONO;
    case BTAV_A2DP_CODEC_CHANNEL_MODE_STEREO:
      return LC3ChannelMode::STEREO;
    case 4://to be defined common to bap
      return LC3ChannelMode::JOINT_STEREO;
    case 8://to be defined common to bap
      return LC3ChannelMode::CH_5_1;
    default:
      return LC3ChannelMode::UNKNOWN;
  }
}

bool a2dp_is_audio_codec_config_params_changed(
                        CodecConfiguration* codec_config) {
  A2dpCodecConfig* a2dp_codec_configs = bta_av_get_a2dp_current_codec();
  uint8_t p_codec_info[AVDT_CODEC_SIZE];
  bool changed = false;
  if (codec_config == nullptr) return false;
  if (a2dp_codec_configs == nullptr) {
    LOG(WARNING) << __func__ << ": failure to get A2DP codec config";
    return false;
  }

  btav_a2dp_codec_config_t current_codec = a2dp_codec_configs->getCodecConfig();
  LOG(ERROR) << __func__
             << ": current codec_type=" << current_codec.codec_type
             << ": hidl codec type=" << ( uint32_t) codec_config->codecType;
  tBT_A2DP_OFFLOAD a2dp_offload;
  a2dp_codec_configs->getCodecSpecificConfig(&a2dp_offload);
  memset(p_codec_info, 0, AVDT_CODEC_SIZE);
  if (!a2dp_codec_configs->copyOutOtaCodecConfig(p_codec_info))
  {
    LOG(ERROR) << "No valid codec config";
    return false;
  }
  switch (current_codec.codec_type) {
    case BTAV_A2DP_CODEC_INDEX_SOURCE_SBC:
      [[fallthrough]];
    case BTAV_A2DP_CODEC_INDEX_SINK_SBC: {
      if(codec_config->codecType != CodecType::SBC) {
        changed = true;
        break;
      }
      auto sbc_config = codec_config->config.sbcConfig;
      if(sbc_config.sampleRate !=
          a2dp_codec_to_hal_sample_rate(current_codec)) {
        changed = true;
        break;
      }
      if(sbc_config.bitsPerSample !=
          a2dp_codec_to_hal_bits_per_sample(current_codec)) {
        changed = true;
        break;
      }
      uint8_t channel_mode = a2dp_offload.codec_info[0] & A2DP_SBC_IE_CH_MD_MSK;
      switch (channel_mode) {
        case A2DP_SBC_IE_CH_MD_JOINT:
          if(sbc_config.channelMode != SbcChannelMode::JOINT_STEREO) {
            changed = true;
          }
          break;
        case A2DP_SBC_IE_CH_MD_STEREO:
          if(sbc_config.channelMode != SbcChannelMode::STEREO) {
            changed = true;
          }
          break;
        case A2DP_SBC_IE_CH_MD_DUAL:
          if(sbc_config.channelMode != SbcChannelMode::DUAL) {
            changed = true;
          }
          break;
        case A2DP_SBC_IE_CH_MD_MONO:
          if(sbc_config.channelMode != SbcChannelMode::MONO) {
            changed = true;
          }
          break;
        default:
          LOG(ERROR) << __func__
                     << ": Unknown SBC channel_mode=" << channel_mode;
          break;
      }
      break;
    }
    case BTAV_A2DP_CODEC_INDEX_SOURCE_AAC:
      [[fallthrough]];
    case BTAV_A2DP_CODEC_INDEX_SINK_AAC: {
      if(codec_config->codecType != CodecType::AAC) {
        changed = true;
        break;
      }
      auto aac_config = codec_config->config.aacConfig;
      if(aac_config.sampleRate != a2dp_codec_to_hal_sample_rate(current_codec)){
        changed = true;
        break;
      }
      if(aac_config.channelMode != a2dp_codec_to_hal_channel_mode
                                    (current_codec)) {
        changed = true;
        break;
      }
      if(aac_config.bitsPerSample !=
          a2dp_codec_to_hal_bits_per_sample(current_codec)) {
        changed = true;
        break;
      }
      break;
    }
    case BTAV_A2DP_CODEC_INDEX_SOURCE_APTX:
      [[fallthrough]];
    case BTAV_A2DP_CODEC_INDEX_SOURCE_APTX_HD: {
      if (current_codec.codec_type == BTAV_A2DP_CODEC_INDEX_SOURCE_APTX) {
        if(codec_config->codecType != CodecType::APTX) {
          changed = true;
          break;
        }
      } else {
        if(codec_config->codecType != CodecType::APTX_HD) {
          changed = true;
          break;
        }
      }
      auto aptx_config = codec_config->config.aptxConfig;
      if(aptx_config.sampleRate !=
             a2dp_codec_to_hal_sample_rate(current_codec)) {
        changed = true;
        break;
      }
      if(aptx_config.channelMode !=
          a2dp_codec_to_hal_channel_mode(current_codec)) {
        changed = true;
        break;
      }
      if(aptx_config.bitsPerSample !=
          a2dp_codec_to_hal_bits_per_sample(current_codec)) {
        changed = true;
        break;
      }
      break;
    }
    case BTAV_A2DP_CODEC_INDEX_SOURCE_APTX_ADAPTIVE: {
      tA2DP_APTX_ADAPTIVE_CIE adaptive_cie;
      if(codec_config->codecType != CodecType::APTX_ADAPTIVE) {
        changed = true;
        break;
      }
      auto aptx_adaptive_config = codec_config->config.aptxAdaptiveConfig;
      if(aptx_adaptive_config.sampleRate !=
                a2dp_codec_to_hal_sample_rate(current_codec)) {
        changed = true;
        break;
      }
      if(aptx_adaptive_config.bitsPerSample !=
          a2dp_codec_to_hal_bits_per_sample(current_codec)) {
        changed = true;
        break;
      }
      if(!A2DP_GetAptxAdaptiveCIE(p_codec_info, &adaptive_cie)) {
        LOG(ERROR) << __func__ << ": Unable to get Aptx Adaptive CIE";
        break;
      }
      if(aptx_adaptive_config.channelMode !=
                               static_cast<AptxAdaptiveChannelMode>
                                (adaptive_cie.channelMode)) {
        changed = true;
        break;
      }
      break;
    }
    case BTAV_A2DP_CODEC_INDEX_SOURCE_LDAC: {
      if(codec_config->codecType != CodecType::LDAC) {
        changed = true;
        break;
      }
      auto ldac_config = codec_config->config.ldacConfig;
      if(ldac_config.sampleRate !=
           a2dp_codec_to_hal_sample_rate(current_codec)) {
        changed = true;
        break;
      }

      if(ldac_config.bitsPerSample !=
          a2dp_codec_to_hal_bits_per_sample(current_codec)) {
        changed = true;
        break;
      }
      switch (a2dp_offload.codec_info[6]) {
        case A2DP_LDAC_QUALITY_HIGH:
        case A2DP_LDAC_QUALITY_MID:
        case A2DP_LDAC_QUALITY_LOW:
        case A2DP_LDAC_QUALITY_ABR_OFFLOAD:
          if (ldac_config.qualityIndex != a2dp_codec_to_hal_ldac_quality_index(current_codec)) {
            changed = true;
          }
          break;
        default:
          LOG(ERROR) << __func__ << ": Unknown LDAC quality index="
                     << a2dp_offload.codec_info[6];
          break;
      }
      switch (a2dp_offload.codec_info[7]) {
        case A2DP_LDAC_CHANNEL_MODE_STEREO:
          if(ldac_config.channelMode != LdacChannelMode::STEREO) {
            changed = true;
          }
          break;
        case A2DP_LDAC_CHANNEL_MODE_DUAL:
          if(ldac_config.channelMode != LdacChannelMode::DUAL) {
            changed = true;
          }
          break;
        case A2DP_LDAC_CHANNEL_MODE_MONO:
          if(ldac_config.channelMode != LdacChannelMode::MONO) {
            changed = true;
          }
          break;
        default:
          LOG(ERROR) << __func__ << ": Unknown LDAC channel_mode="
                     << a2dp_offload.codec_info[7];
          break;
      }
      break;
    }
    case BTAV_A2DP_CODEC_INDEX_SOURCE_APTX_TWS: {
      //SampleRate sampleRate;
      //ChannelMode channelMode;
      //uint8_t syncMode;
      if(codec_config->codecType != CodecType::APTX_TWS) {
        changed = true;
        break;
      }
      auto aptx_tws_config = codec_config->config.aptxTwsConfig;
      if(aptx_tws_config.sampleRate !=
               a2dp_codec_to_hal_sample_rate(current_codec)) {
        changed = true;
        break;
      }
      if(aptx_tws_config.channelMode !=
                a2dp_codec_to_hal_channel_mode(current_codec)) {
        changed = true;
        break;
      }
      break;
    }
    case BTAV_A2DP_CODEC_INDEX_MAX:
      [[fallthrough]];
    default:
      LOG(ERROR) << __func__
                 << ": Unknown codec_type=" << current_codec.codec_type;
      break;
  }
  return changed;
}

bool a2dp_is_audio_codec_config_params_changed_2_1(
                        CodecConfiguration_2_1* codec_config) {
  A2dpCodecConfig* a2dp_codec_configs = bta_av_get_a2dp_current_codec();
  uint8_t p_codec_info[AVDT_CODEC_SIZE];
  bool changed = false;
  if (codec_config == nullptr) return false;
  if (a2dp_codec_configs == nullptr) {
    LOG(WARNING) << __func__ << ": failure to get A2DP codec config";
    return false;
  }
/*
  if (codec_config->codecType == LC3) {
  }
*/
  btav_a2dp_codec_config_t current_codec = a2dp_codec_configs->getCodecConfig();
  LOG(ERROR) << __func__
             << ": current codec_type=" << current_codec.codec_type
             << ": hidl codec type=" << ( uint32_t) codec_config->codecType;
  tBT_A2DP_OFFLOAD a2dp_offload;
  a2dp_codec_configs->getCodecSpecificConfig(&a2dp_offload);
  memset(p_codec_info, 0, AVDT_CODEC_SIZE);
  if (!a2dp_codec_configs->copyOutOtaCodecConfig(p_codec_info))
  {
    LOG(ERROR) << "No valid codec config";
    return false;
  }
  switch (current_codec.codec_type) {
    case BTAV_A2DP_CODEC_INDEX_SOURCE_SBC:
      [[fallthrough]];
    case BTAV_A2DP_CODEC_INDEX_SINK_SBC: {
      if(codec_config->codecType != CodecType_2_1::SBC) {
        changed = true;
        break;
      }
      auto sbc_config = codec_config->config.sbcConfig;
      if(sbc_config.sampleRate !=
          a2dp_codec_to_hal_sample_rate(current_codec)) {
        changed = true;
        break;
      }
      if(sbc_config.bitsPerSample !=
          a2dp_codec_to_hal_bits_per_sample(current_codec)) {
        changed = true;
        break;
      }
      uint8_t channel_mode = a2dp_offload.codec_info[0] & A2DP_SBC_IE_CH_MD_MSK;
      switch (channel_mode) {
        case A2DP_SBC_IE_CH_MD_JOINT:
          if(sbc_config.channelMode != SbcChannelMode::JOINT_STEREO) {
            changed = true;
          }
          break;
        case A2DP_SBC_IE_CH_MD_STEREO:
          if(sbc_config.channelMode != SbcChannelMode::STEREO) {
            changed = true;
          }
          break;
        case A2DP_SBC_IE_CH_MD_DUAL:
          if(sbc_config.channelMode != SbcChannelMode::DUAL) {
            changed = true;
          }
          break;
        case A2DP_SBC_IE_CH_MD_MONO:
          if(sbc_config.channelMode != SbcChannelMode::MONO) {
            changed = true;
          }
          break;
        default:
          LOG(ERROR) << __func__
                     << ": Unknown SBC channel_mode=" << channel_mode;
          break;
      }
      break;
    }
    case BTAV_A2DP_CODEC_INDEX_SOURCE_AAC:
      [[fallthrough]];
    case BTAV_A2DP_CODEC_INDEX_SINK_AAC: {
      if(codec_config->codecType != CodecType_2_1::AAC) {
        changed = true;
        break;
      }
      auto aac_config = codec_config->config.aacConfig;
      if(aac_config.sampleRate != a2dp_codec_to_hal_sample_rate(current_codec)){
        changed = true;
        break;
      }
      if(aac_config.channelMode != a2dp_codec_to_hal_channel_mode
                                    (current_codec)) {
        changed = true;
        break;
      }
      if(aac_config.bitsPerSample !=
          a2dp_codec_to_hal_bits_per_sample(current_codec)) {
        changed = true;
        break;
      }
      break;
    }
    case BTAV_A2DP_CODEC_INDEX_SOURCE_APTX:
      [[fallthrough]];
    case BTAV_A2DP_CODEC_INDEX_SOURCE_APTX_HD: {
      if (current_codec.codec_type == BTAV_A2DP_CODEC_INDEX_SOURCE_APTX) {
        if(codec_config->codecType != CodecType_2_1::APTX) {
          changed = true;
          break;
        }
      } else {
        if(codec_config->codecType != CodecType_2_1::APTX_HD) {
          changed = true;
          break;
        }
      }
      auto aptx_config = codec_config->config.aptxConfig;
      if(aptx_config.sampleRate !=
             a2dp_codec_to_hal_sample_rate(current_codec)) {
        changed = true;
        break;
      }
      if(aptx_config.channelMode !=
          a2dp_codec_to_hal_channel_mode(current_codec)) {
        changed = true;
        break;
      }
      if(aptx_config.bitsPerSample !=
          a2dp_codec_to_hal_bits_per_sample(current_codec)) {
        changed = true;
        break;
      }
      break;
    }
    case BTAV_A2DP_CODEC_INDEX_SOURCE_APTX_ADAPTIVE: {
      tA2DP_APTX_ADAPTIVE_CIE adaptive_cie;
      if(codec_config->codecType != CodecType_2_1::APTX_ADAPTIVE) {
        changed = true;
        break;
      }
      auto aptx_adaptive_config = codec_config->config.aptxAdaptiveConfig;
      if(aptx_adaptive_config.sampleRate !=
                a2dp_codec_to_hal_sample_rate(current_codec)) {
        changed = true;
        break;
      }
      if(aptx_adaptive_config.bitsPerSample !=
          a2dp_codec_to_hal_bits_per_sample(current_codec)) {
        changed = true;
        break;
      }
      if(!A2DP_GetAptxAdaptiveCIE(p_codec_info, &adaptive_cie)) {
        LOG(ERROR) << __func__ << ": Unable to get Aptx Adaptive CIE";
        break;
      }
      if(aptx_adaptive_config.channelMode !=
                               static_cast<AptxAdaptiveChannelMode>
                                (adaptive_cie.channelMode)) {
        changed = true;
        break;
      }
      break;
    }
    case BTAV_A2DP_CODEC_INDEX_SOURCE_LDAC: {
      if(codec_config->codecType != CodecType_2_1::LDAC) {
        changed = true;
        break;
      }
      auto ldac_config = codec_config->config.ldacConfig;
      if(ldac_config.sampleRate !=
           a2dp_codec_to_hal_sample_rate(current_codec)) {
        changed = true;
        break;
      }

      if(ldac_config.bitsPerSample !=
          a2dp_codec_to_hal_bits_per_sample(current_codec)) {
        changed = true;
        break;
      }
      switch (a2dp_offload.codec_info[6]) {
        case A2DP_LDAC_QUALITY_HIGH:
        case A2DP_LDAC_QUALITY_MID:
        case A2DP_LDAC_QUALITY_LOW:
        case A2DP_LDAC_QUALITY_ABR_OFFLOAD:
          if (ldac_config.qualityIndex != a2dp_codec_to_hal_ldac_quality_index(current_codec)) {
            changed = true;
          }
          break;
        default:
          LOG(ERROR) << __func__ << ": Unknown LDAC quality index="
                     << a2dp_offload.codec_info[6];
          break;
      }
      switch (a2dp_offload.codec_info[7]) {
        case A2DP_LDAC_CHANNEL_MODE_STEREO:
          if(ldac_config.channelMode != LdacChannelMode::STEREO) {
            changed = true;
          }
          break;
        case A2DP_LDAC_CHANNEL_MODE_DUAL:
          if(ldac_config.channelMode != LdacChannelMode::DUAL) {
            changed = true;
          }
          break;
        case A2DP_LDAC_CHANNEL_MODE_MONO:
          if(ldac_config.channelMode != LdacChannelMode::MONO) {
            changed = true;
          }
          break;
        default:
          LOG(ERROR) << __func__ << ": Unknown LDAC channel_mode="
                     << a2dp_offload.codec_info[7];
          break;
      }
      break;
    }
    case BTAV_A2DP_CODEC_INDEX_SOURCE_APTX_TWS: {
      //SampleRate sampleRate;
      //ChannelMode channelMode;
      //uint8_t syncMode;
      if(codec_config->codecType != CodecType_2_1::APTX_TWS) {
        changed = true;
        break;
      }
      auto aptx_tws_config = codec_config->config.aptxTwsConfig;
      if(aptx_tws_config.sampleRate !=
               a2dp_codec_to_hal_sample_rate(current_codec)) {
        changed = true;
        break;
      }
      if(aptx_tws_config.channelMode !=
                a2dp_codec_to_hal_channel_mode(current_codec)) {
        changed = true;
        break;
      }
      break;
    }
    case BTAV_A2DP_CODEC_INDEX_MAX:
      [[fallthrough]];
    default:
      LOG(ERROR) << __func__
                 << ": Unknown codec_type=" << current_codec.codec_type;
      break;
  }
  return changed;
}

bool a2dp_get_selected_hal_codec_config(CodecConfiguration* codec_config) {
  A2dpCodecConfig* a2dp_codec_configs = bta_av_get_a2dp_current_codec();
  uint8_t p_codec_info[AVDT_CODEC_SIZE];
  uint8_t codec_type;
  uint32_t bitrate = 0;
  tA2DP_ENCODER_INIT_PEER_PARAMS peer_param;
  if (codec_config == nullptr) return false;

  if (btif_ba_is_active())
  {
    codec_config->codecType = CodecType::BA_CELT;
    codec_config->config.baCeltConfig = {};
    auto ba_celt_config = codec_config->config.baCeltConfig;

    ba_celt_config.sampleRate = ba_codec_to_hal_sample_rate(btif_ba_get_sample_rate());
    if (ba_celt_config.sampleRate == SampleRate::RATE_UNKNOWN) {
      LOG(ERROR) << __func__
        << ": Unknown CELT sample_rate=" << btif_ba_get_sample_rate();
      return false;
    }
    ba_celt_config.channelMode = ba_codec_to_hal_channel_mode(btif_ba_get_channel_mode());
    if (ba_celt_config.channelMode == ChannelMode::UNKNOWN) {
      LOG(ERROR) << __func__ << ": Unknown CELT channel_mode="
        << btif_ba_get_channel_mode();
      return false;
    }
    ba_celt_config.frameSize = ba_codec_to_hal_frame_size(btif_ba_get_frame_size());
    ba_celt_config.complexity = btif_ba_get_complexity();
    ba_celt_config.predictionMode = btif_ba_get_prediction_mode();
    ba_celt_config.vbrFlag = btif_ba_get_vbr_flag();
    codec_config->encodedAudioBitrate = btif_ba_get_bitrate();
    codec_config->config.baCeltConfig = ba_celt_config;
    // fill the scrambling support flag
    codec_config->isScramblingEnabled = btif_av_is_scrambling_enabled();
    LOG(INFO) << __func__ << ": Celt codec, CodecConfiguration=" << toString(*codec_config);
    return true;
  }

  if (a2dp_codec_configs == nullptr) {
    LOG(WARNING) << __func__ << ": failure to get A2DP codec config";
    return false;
  }
  btav_a2dp_codec_config_t current_codec = a2dp_codec_configs->getCodecConfig();
  tBT_A2DP_OFFLOAD a2dp_offload;
  a2dp_codec_configs->getCodecSpecificConfig(&a2dp_offload);
  memset(p_codec_info, 0, AVDT_CODEC_SIZE);
  if (!a2dp_codec_configs->copyOutOtaCodecConfig(p_codec_info))
  {
    LOG(ERROR) << "No valid codec config";
    return false;
  }

  // fill the scrambling support flag
  codec_config->isScramblingEnabled = btif_av_is_scrambling_enabled();

  switch (current_codec.codec_type) {
    case BTAV_A2DP_CODEC_INDEX_SOURCE_SBC:
      [[fallthrough]];
    case BTAV_A2DP_CODEC_INDEX_SINK_SBC: {
      codec_config->codecType = CodecType::SBC;
      codec_config->config.sbcConfig = {};
      auto sbc_config = codec_config->config.sbcConfig;
      sbc_config.sampleRate = a2dp_codec_to_hal_sample_rate(current_codec);
      if (sbc_config.sampleRate == SampleRate::RATE_UNKNOWN) {
        LOG(ERROR) << __func__
                   << ": Unknown SBC sample_rate=" << current_codec.sample_rate;
        return false;
      }
      uint8_t channel_mode = a2dp_offload.codec_info[0] & A2DP_SBC_IE_CH_MD_MSK;
      switch (channel_mode) {
        case A2DP_SBC_IE_CH_MD_JOINT:
          sbc_config.channelMode = SbcChannelMode::JOINT_STEREO;
          break;
        case A2DP_SBC_IE_CH_MD_STEREO:
          sbc_config.channelMode = SbcChannelMode::STEREO;
          break;
        case A2DP_SBC_IE_CH_MD_DUAL:
          sbc_config.channelMode = SbcChannelMode::DUAL;
          break;
        case A2DP_SBC_IE_CH_MD_MONO:
          sbc_config.channelMode = SbcChannelMode::MONO;
          break;
        default:
          LOG(ERROR) << __func__
                     << ": Unknown SBC channel_mode=" << channel_mode;
          sbc_config.channelMode = SbcChannelMode::UNKNOWN;
          return false;
      }
      uint8_t block_length =
          a2dp_offload.codec_info[1] & A2DP_SBC_IE_BLOCKS_MSK;
      switch (block_length) {
        case A2DP_SBC_IE_BLOCKS_4:
          sbc_config.blockLength = SbcBlockLength::BLOCKS_4;
          break;
        case A2DP_SBC_IE_BLOCKS_8:
          sbc_config.blockLength = SbcBlockLength::BLOCKS_8;
          break;
        case A2DP_SBC_IE_BLOCKS_12:
          sbc_config.blockLength = SbcBlockLength::BLOCKS_12;
          break;
        case A2DP_SBC_IE_BLOCKS_16:
          sbc_config.blockLength = SbcBlockLength::BLOCKS_16;
          break;
        default:
          LOG(ERROR) << __func__
                     << ": Unknown SBC block_length=" << block_length;
          return false;
      }
      uint8_t sub_bands = a2dp_offload.codec_info[1] & A2DP_SBC_IE_SUBBAND_MSK;
      switch (sub_bands) {
        case A2DP_SBC_IE_SUBBAND_4:
          sbc_config.numSubbands = SbcNumSubbands::SUBBAND_4;
          break;
        case A2DP_SBC_IE_SUBBAND_8:
          sbc_config.numSubbands = SbcNumSubbands::SUBBAND_8;
          break;
        default:
          LOG(ERROR) << __func__ << ": Unknown SBC Subbands=" << sub_bands;
          return false;
      }
      uint8_t alloc_method =
          a2dp_offload.codec_info[1] & A2DP_SBC_IE_ALLOC_MD_MSK;
      switch (alloc_method) {
        case A2DP_SBC_IE_ALLOC_MD_S:
          sbc_config.allocMethod = SbcAllocMethod::ALLOC_MD_S;
          break;
        case A2DP_SBC_IE_ALLOC_MD_L:
          sbc_config.allocMethod = SbcAllocMethod::ALLOC_MD_L;
          break;
        default:
          LOG(ERROR) << __func__
                     << ": Unknown SBC alloc_method=" << alloc_method;
          return false;
      }
      sbc_config.minBitpool = a2dp_offload.codec_info[2];
      sbc_config.maxBitpool = a2dp_offload.codec_info[3];
      sbc_config.bitsPerSample =
          a2dp_codec_to_hal_bits_per_sample(current_codec);
      if (sbc_config.bitsPerSample == BitsPerSample::BITS_UNKNOWN) {
        LOG(ERROR) << __func__ << ": Unknown SBC bits_per_sample="
                   << current_codec.bits_per_sample;
        return false;
      }
      codec_config->config.sbcConfig = sbc_config;
      break;
    }

    case BTAV_A2DP_CODEC_INDEX_SOURCE_AAC:
      [[fallthrough]];
    case BTAV_A2DP_CODEC_INDEX_SINK_AAC: {
      codec_config->codecType = CodecType::AAC;
      codec_config->config.aacConfig = {};
      auto aac_config = codec_config->config.aacConfig;
      // TODO(cheneyni): add more supported types.
      aac_config.objectType = AacObjectType::MPEG2_LC;
      aac_config.sampleRate = a2dp_codec_to_hal_sample_rate(current_codec);
      if (aac_config.sampleRate == SampleRate::RATE_UNKNOWN) {
        LOG(ERROR) << __func__
                   << ": Unknown AAC sample_rate=" << current_codec.sample_rate;
        return false;
      }
      aac_config.channelMode = a2dp_codec_to_hal_channel_mode(current_codec);
      if (aac_config.channelMode == ChannelMode::UNKNOWN) {
        LOG(ERROR) << __func__ << ": Unknown AAC channel_mode="
                   << current_codec.channel_mode;
        return false;
      }
      uint8_t vbr_enabled =
              a2dp_offload.codec_info[1] & A2DP_AAC_VARIABLE_BIT_RATE_MASK;
      switch (vbr_enabled) {
        case A2DP_AAC_VARIABLE_BIT_RATE_ENABLED:
          LOG(INFO) << __func__ << " Enabled AAC VBR =" << +vbr_enabled;
          aac_config.variableBitRateEnabled = AacVariableBitRate::ENABLED;
          break;
        case A2DP_AAC_VARIABLE_BIT_RATE_DISABLED:
          LOG(INFO) << __func__ << " Disabled AAC VBR =" << +vbr_enabled;
          aac_config.variableBitRateEnabled = AacVariableBitRate::DISABLED;
          break;
        default:
          LOG(ERROR) << __func__ << ": Unknown AAC VBR=" << +vbr_enabled;
          return false;
      }
      aac_config.bitsPerSample =
          a2dp_codec_to_hal_bits_per_sample(current_codec);
      if (aac_config.bitsPerSample == BitsPerSample::BITS_UNKNOWN) {
        LOG(ERROR) << __func__ << ": Unknown AAC bits_per_sample="
                   << current_codec.bits_per_sample;
        return false;
      }
      codec_config->config.aacConfig = aac_config;
      break;
    }
    case BTAV_A2DP_CODEC_INDEX_SOURCE_APTX:
      [[fallthrough]];
    case BTAV_A2DP_CODEC_INDEX_SOURCE_APTX_HD: {
      if (current_codec.codec_type == BTAV_A2DP_CODEC_INDEX_SOURCE_APTX) {
        codec_config->codecType = CodecType::APTX;
      } else {
        codec_config->codecType = CodecType::APTX_HD;
      }
      codec_config->config.aptxConfig = {};
      auto aptx_config = codec_config->config.aptxConfig;
      aptx_config.sampleRate = a2dp_codec_to_hal_sample_rate(current_codec);
      if (aptx_config.sampleRate == SampleRate::RATE_UNKNOWN) {
        LOG(ERROR) << __func__ << ": Unknown aptX sample_rate="
                   << current_codec.sample_rate;
        return false;
      }
      aptx_config.channelMode = a2dp_codec_to_hal_channel_mode(current_codec);
      if (aptx_config.channelMode == ChannelMode::UNKNOWN) {
        LOG(ERROR) << __func__ << ": Unknown aptX channel_mode="
                   << current_codec.channel_mode;
        return false;
      }
      aptx_config.bitsPerSample =
          a2dp_codec_to_hal_bits_per_sample(current_codec);
      if (aptx_config.bitsPerSample == BitsPerSample::BITS_UNKNOWN) {
        LOG(ERROR) << __func__ << ": Unknown aptX bits_per_sample="
                   << current_codec.bits_per_sample;
        return false;
      }
      codec_config->config.aptxConfig = aptx_config;
      break;
    }
    case BTAV_A2DP_CODEC_INDEX_SOURCE_APTX_ADAPTIVE: {
      tA2DP_APTX_ADAPTIVE_CIE adaptive_cie;
      codec_config->codecType = CodecType::APTX_ADAPTIVE;
      codec_config->config.aptxAdaptiveConfig = {};
      auto aptx_adaptive_config = codec_config->config.aptxAdaptiveConfig;
      aptx_adaptive_config.sampleRate = a2dp_codec_to_hal_sample_rate(current_codec);
      if (aptx_adaptive_config.sampleRate == SampleRate::RATE_UNKNOWN) {
        LOG(ERROR) << __func__ << ": Unknown LDAC sample_rate="
                   << current_codec.sample_rate;
        return false;
      }
      aptx_adaptive_config.bitsPerSample =
          a2dp_codec_to_hal_bits_per_sample(current_codec);
      if (aptx_adaptive_config.bitsPerSample == BitsPerSample::BITS_UNKNOWN) {
        LOG(ERROR) << __func__ << ": Unknown aptX adaptive bits_per_sample="
                   << current_codec.bits_per_sample;
        return false;
      }
      if(!A2DP_GetAptxAdaptiveCIE(p_codec_info, &adaptive_cie)) {
        LOG(ERROR) << __func__ << ": Unable to get Aptx Adaptive CIE";
        return false;
      }
      aptx_adaptive_config.channelMode = static_cast<AptxAdaptiveChannelMode>
                                        (adaptive_cie.channelMode);
      if (aptx_adaptive_config.channelMode >=
                 AptxAdaptiveChannelMode::UNKNOWN) {
        LOG(ERROR) << __func__ << ": Unknown aptX adaptive channel_mode="
                   << adaptive_cie.channelMode;
        return false;
      }
      aptx_adaptive_config.aptxMode = static_cast<AptxMode>
                            (btif_av_get_aptx_mode_info());
      aptx_adaptive_config.sinkBuffering = { 20, 50, 20, 50, 20, 50 };
      aptx_adaptive_config.ttp = { adaptive_cie.aptx_data.ttp_ll_0, adaptive_cie.aptx_data.ttp_ll_1,
                                   adaptive_cie.aptx_data.ttp_hq_0, adaptive_cie.aptx_data.ttp_hq_1,
                                   adaptive_cie.aptx_data.ttp_tws_0, adaptive_cie.aptx_data.ttp_tws_1
                                 };
      if (btif_av_current_device_is_tws()) {
        aptx_adaptive_config.inputMode = static_cast<InputMode>(0x01);
      } else {
        aptx_adaptive_config.inputMode = static_cast<InputMode>(0x00);
      }
      aptx_adaptive_config.inputFadeDuration = 0xff;
      aptx_adaptive_config.aptxAdaptiveConfigStream[0] =  adaptive_cie.aptx_data.cap_ext_ver_num;
      aptx_adaptive_config.aptxAdaptiveConfigStream[1] =  adaptive_cie.aptx_data.aptx_adaptive_sup_features & 0x000000FF;
      aptx_adaptive_config.aptxAdaptiveConfigStream[2] =  ((adaptive_cie.aptx_data.aptx_adaptive_sup_features & 0x0000FF00) >> 8);
      aptx_adaptive_config.aptxAdaptiveConfigStream[3] =  ((adaptive_cie.aptx_data.aptx_adaptive_sup_features & 0x00FF0000) >> 16);
      aptx_adaptive_config.aptxAdaptiveConfigStream[4] =  ((adaptive_cie.aptx_data.aptx_adaptive_sup_features & 0xFF000000) >> 24);
      aptx_adaptive_config.aptxAdaptiveConfigStream[5] =  adaptive_cie.aptx_data.first_setup_pref;
      aptx_adaptive_config.aptxAdaptiveConfigStream[6] =  adaptive_cie.aptx_data.second_setup_pref;
      aptx_adaptive_config.aptxAdaptiveConfigStream[7] =  adaptive_cie.aptx_data.third_setup_pref;
      aptx_adaptive_config.aptxAdaptiveConfigStream[8] =  adaptive_cie.aptx_data.fourth_setup_pref;
      aptx_adaptive_config.aptxAdaptiveConfigStream[9] =  adaptive_cie.aptx_data.eoc0;
      aptx_adaptive_config.aptxAdaptiveConfigStream[10] =  adaptive_cie.aptx_data.eoc1;

      codec_config->config.aptxAdaptiveConfig = aptx_adaptive_config;
      break;
    }
    case BTAV_A2DP_CODEC_INDEX_SOURCE_LDAC: {
      codec_config->codecType = CodecType::LDAC;
      codec_config->config.ldacConfig = {};
      auto ldac_config = codec_config->config.ldacConfig;
      ldac_config.sampleRate = a2dp_codec_to_hal_sample_rate(current_codec);
      if (ldac_config.sampleRate == SampleRate::RATE_UNKNOWN) {
        LOG(ERROR) << __func__ << ": Unknown LDAC sample_rate="
                   << current_codec.sample_rate;
        return false;
      }
      switch (a2dp_offload.codec_info[7]) {
        case A2DP_LDAC_CHANNEL_MODE_STEREO:
          ldac_config.channelMode = LdacChannelMode::STEREO;
          break;
        case A2DP_LDAC_CHANNEL_MODE_DUAL:
          ldac_config.channelMode = LdacChannelMode::DUAL;
          break;
        case A2DP_LDAC_CHANNEL_MODE_MONO:
          ldac_config.channelMode = LdacChannelMode::MONO;
          break;
        default:
          LOG(ERROR) << __func__ << ": Unknown LDAC channel_mode="
                     << a2dp_offload.codec_info[7];
          ldac_config.channelMode = LdacChannelMode::UNKNOWN;
          return false;
      }
      switch (a2dp_offload.codec_info[6]) {
        case A2DP_LDAC_QUALITY_HIGH:
          ldac_config.qualityIndex = LdacQualityIndex::QUALITY_HIGH;
          break;
        case A2DP_LDAC_QUALITY_MID:
          ldac_config.qualityIndex = LdacQualityIndex::QUALITY_MID;
          break;
        case A2DP_LDAC_QUALITY_LOW:
          ldac_config.qualityIndex = LdacQualityIndex::QUALITY_LOW;
          break;
        case A2DP_LDAC_QUALITY_ABR_OFFLOAD:
          ldac_config.qualityIndex = LdacQualityIndex::QUALITY_ABR;
          break;
        default:
          LOG(ERROR) << __func__ << ": Unknown LDAC QualityIndex="
                     << a2dp_offload.codec_info[6];
          return false;
      }
      ldac_config.bitsPerSample =
          a2dp_codec_to_hal_bits_per_sample(current_codec);
      if (ldac_config.bitsPerSample == BitsPerSample::BITS_UNKNOWN) {
        LOG(ERROR) << __func__ << ": Unknown LDAC bits_per_sample="
                   << current_codec.bits_per_sample;
        return false;
      }
      codec_config->config.ldacConfig = ldac_config;
      break;
    }
    case BTAV_A2DP_CODEC_INDEX_SOURCE_APTX_TWS: {
      codec_config->codecType = CodecType::APTX_TWS;
      codec_config->config.aptxTwsConfig = {};
      auto aptx_tws_config = codec_config->config.aptxTwsConfig;
      aptx_tws_config.sampleRate = a2dp_codec_to_hal_sample_rate(current_codec);
      if (aptx_tws_config.sampleRate == SampleRate::RATE_UNKNOWN) {
        LOG(ERROR) << __func__ << ": Unknown aptX tws sample_rate="
                   << current_codec.sample_rate;
        return false;
      }
      aptx_tws_config.channelMode = a2dp_codec_to_hal_channel_mode(current_codec);
      if (aptx_tws_config.channelMode == ChannelMode::UNKNOWN) {
        LOG(ERROR) << __func__ << ": Unknown aptX tws channel_mode="
                   << current_codec.channel_mode;
        return false;
      }
      aptx_tws_config.syncMode = 0x02;
      codec_config->config.aptxTwsConfig = aptx_tws_config;
      break;
    }
    case BTAV_A2DP_CODEC_INDEX_MAX:
      [[fallthrough]];
    default:
      LOG(ERROR) << __func__
                 << ": Unknown codec_type=" << current_codec.codec_type;
      codec_config->codecType = CodecType::UNKNOWN;
      codec_config->config = {};
      return false;
  }
  bta_av_co_get_peer_params(&peer_param);
  codec_type = A2DP_GetCodecType((const uint8_t*)p_codec_info);
  LOG(INFO) << __func__ << ": codec_type" << codec_type;
  // Obtain the MTU
  codec_config->peerMtu = peer_param.peer_mtu - A2DP_HEADER_SIZE;
  if (A2DP_MEDIA_CT_SBC == codec_type) {
    bitrate = A2DP_GetOffloadBitrateSbc(a2dp_codec_configs, peer_param.is_peer_edr);
    LOG(INFO) << __func__ << "SBC bitrate" << bitrate;
    codec_config->encodedAudioBitrate = bitrate * 1000;
  }
  else if (A2DP_MEDIA_CT_NON_A2DP == codec_type) {
    int samplerate = A2DP_GetTrackSampleRate(p_codec_info);
    if ((A2DP_VendorCodecGetVendorId(p_codec_info)) == A2DP_LDAC_VENDOR_ID) {
      codec_config->encodedAudioBitrate = A2DP_GetTrackBitRate(p_codec_info);
      LOG(INFO) << __func__ << "LDAC bitrate" << codec_config->encodedAudioBitrate;
    } else {
      /* BR = (Sampl_Rate * PCM_DEPTH * CHNL)/Compression_Ratio */
      int bits_per_sample = 16; // TODO
      codec_config->encodedAudioBitrate = (samplerate * bits_per_sample * 2)/4;
      LOG(INFO) << __func__ << "Aptx bitrate" << codec_config->encodedAudioBitrate;
    }
  }
  else if (A2DP_MEDIA_CT_AAC == codec_type) {
    bool is_AAC_frame_ctrl_stack_enable =
                    controller_get_interface()->supports_aac_frame_ctl();
    uint32_t codec_based_bit_rate = 0;
    uint32_t mtu_based_bit_rate = 0;
    LOG(INFO) << __func__ << "Stack AAC frame control enabled"
                          << is_AAC_frame_ctrl_stack_enable;
    tA2DP_AAC_CIE aac_cie;
    if(!A2DP_GetAacCIE(p_codec_info, &aac_cie)) {
      LOG(ERROR) << __func__ << ": Unable to get AAC CIE";
      return false;
    }
    codec_based_bit_rate = aac_cie.bitRate;

    if (is_AAC_frame_ctrl_stack_enable) {
      int sample_rate = A2DP_GetTrackSampleRate(p_codec_info);
      mtu_based_bit_rate = (peer_param.peer_mtu - AAC_LATM_HEADER)
                                          * (8 * sample_rate / AAC_SAMPLE_SIZE);
      LOG(INFO) << __func__ << "sample_rate " << sample_rate;
      LOG(INFO) << __func__ << " peer_mtu " << peer_param.peer_mtu;
      LOG(INFO) << __func__ << " codec_bit_rate " << codec_based_bit_rate
                << " MTU bitrate " << mtu_based_bit_rate;
      codec_config->encodedAudioBitrate = (codec_based_bit_rate < mtu_based_bit_rate) ?
                                           codec_based_bit_rate:mtu_based_bit_rate;
    } else {
      codec_config->encodedAudioBitrate = codec_based_bit_rate;
    }
  }
  LOG(INFO) << __func__ << ": CodecConfiguration=" << toString(*codec_config);
  return true;
}
bool a2dp_get_selected_hal_codec_config_2_1(CodecConfiguration_2_1* codec_config, int profile) {
  LOG(INFO) << __func__ << ": profile_type: " << profile;
  A2dpCodecConfig* a2dp_codec_configs = bta_av_get_a2dp_current_codec();
  uint8_t p_codec_info[AVDT_CODEC_SIZE];
  uint8_t codec_type;
  uint32_t bitrate = 0;
  int cis_count = 2;
  tA2DP_ENCODER_INIT_PEER_PARAMS peer_param;
  if (codec_config == nullptr) return false;

  if (btif_ba_is_active()) {
    codec_config->codecType = CodecType_2_1::BA_CELT;
    codec_config->config.baCeltConfig = {};
    auto ba_celt_config = codec_config->config.baCeltConfig;

    ba_celt_config.sampleRate = ba_codec_to_hal_sample_rate(btif_ba_get_sample_rate());
    if (ba_celt_config.sampleRate == SampleRate::RATE_UNKNOWN) {
      LOG(ERROR) << __func__
        << ": Unknown CELT sample_rate=" << btif_ba_get_sample_rate();
      return false;
    }
    ba_celt_config.channelMode = ba_codec_to_hal_channel_mode(btif_ba_get_channel_mode());
    if (ba_celt_config.channelMode == ChannelMode::UNKNOWN) {
      LOG(ERROR) << __func__ << ": Unknown CELT channel_mode="
        << btif_ba_get_channel_mode();
      return false;
    }
    ba_celt_config.frameSize = ba_codec_to_hal_frame_size(btif_ba_get_frame_size());
    ba_celt_config.complexity = btif_ba_get_complexity();
    ba_celt_config.predictionMode = btif_ba_get_prediction_mode();
    ba_celt_config.vbrFlag = btif_ba_get_vbr_flag();
    codec_config->encodedAudioBitrate = btif_ba_get_bitrate();
    codec_config->config.baCeltConfig = ba_celt_config;
    // fill the scrambling support flag
    codec_config->isScramblingEnabled = btif_av_is_scrambling_enabled();
    LOG(INFO) << __func__ << ": Celt codec, CodecConfiguration=" << toString(*codec_config);
    return true;
  }

/********LC3 Codec */
  if (profile == BROADCAST) {
    //Populate LC3 codec info
    codec_config->codecType = CodecType_2_1::LC3;
    codec_config->config.lc3Config = {};
    auto lc3Config = codec_config->config.lc3Config;

    lc3Config.rxConfigSet |= TX_ONLY_CONFIG;
    lc3Config.txConfig.sampleRate = btif_lc3_sample_rate(
          pclient_cbs[profile - 1]->get_sample_rate_cb(lc3Config.rxConfigSet));
    lc3Config.txConfig.channelMode = btif_lc3_channel_mode(
          pclient_cbs[profile - 1]->get_channel_mode_cb(lc3Config.rxConfigSet));
    lc3Config.txConfig.bitrate =
          pclient_cbs[profile - 1]->get_bitrate_cb(lc3Config.rxConfigSet);
    lc3Config.txConfig.octetsPerFrame =
          pclient_cbs[profile - 1]->get_mtu_cb(lc3Config.txConfig.bitrate,
                                               lc3Config.rxConfigSet);
    lc3Config.txConfig.frameDuration =
          pclient_cbs[profile - 1]->get_frame_length_cb(lc3Config.rxConfigSet);
    lc3Config.txConfig.bitsPerSample = BitsPerSample::BITS_24;
    lc3Config.txConfig.numBlocks = 1;

    uint8_t cs[16] = {0};
    for (int i = 0; i  < 16; i++) {
      lc3Config.codecSpecific[i] = cs[i];
    }
    lc3Config.defaultQlevel = 3;
    lc3Config.mode = pclient_cbs[profile - 1]->mode;
    lc3Config.decoderOuputChannels = 0;

    int numBises = pclient_cbs[profile - 1]->get_ch_count_cb();
    bool simulcast = pclient_cbs[profile -1]->get_simulcast_status_cb();
    if (simulcast) {
      //Reset Tx flag and set only Rx flag.
      if (lc3Config.rxConfigSet & TX_ONLY_CONFIG) {
        lc3Config.rxConfigSet &= ~TX_ONLY_CONFIG;
      }

      lc3Config.rxConfigSet |= RX_ONLY_CONFIG;
      lc3Config.rxConfig.sampleRate = ExtSampleRate::RATE_16000;
      lc3Config.rxConfig.channelMode = LC3ChannelMode::STEREO;
      lc3Config.rxConfig.bitrate = 48000;
      lc3Config.rxConfig.octetsPerFrame = 60;
      lc3Config.rxConfig.frameDuration = 10000;
      lc3Config.rxConfig.bitsPerSample = BitsPerSample::BITS_24;
      lc3Config.mode = BA_SIMULCAST;
    }

    lc3Config.NumStreamIDGroup = numBises;
    for (int i = 0; i < numBises; i++) {
      if (lc3Config.txConfig.channelMode == LC3ChannelMode::STEREO) {
        lc3Config.streamMap[(i*3)] = (CHANNEL_FL + (i % 2));
      } else if (lc3Config.txConfig.channelMode == LC3ChannelMode::JOINT_STEREO) {
        lc3Config.streamMap[(i*3)] = (CHANNEL_FR | CHANNEL_FL);
      } else {
        lc3Config.streamMap[(i*3)] = CHANNEL_MONO;
      }
      lc3Config.streamMap[(i*3)+1] = i;
      lc3Config.streamMap[(i*3)+2] = 0;
    }

    // To make sure QSSI builds with VBC changes won't
    // break existing features on older Vendor AUs.
    // Ensured this, with below flag by making rxConfigSet to 0
    // if Tx only or both Tx/Rx set, and same has been manipulated
    // in vendor layer to ensure session has been established properly.
    if (lc3Config.rxConfigSet & TX_ONLY_CONFIG) {
      lc3Config.rxConfigSet  = 0;
    }

    codec_config->config.lc3Config = lc3Config;

    LOG(INFO) << __func__ << ": LC3 codec for broadcast, CodecConfiguration="
                          << toString(*codec_config);
    return true;
  }

  if (profile == AUDIO_GROUP_MGR) {
    codec_config->codecType = CodecType_2_1::LC3;
    codec_config->config.lc3Config = {};
    auto lc3Config = codec_config->config.lc3Config;
    uint16_t type = pclient_cbs[profile - 1]->get_profile_status_cb();
    LOG(ERROR) << __func__ << ": type: " << type;

    /* rxConfigSet = 1 for Rx only
     * rxConfigSet = 2 for Tx only
     * rxConfigSet = 3 for Tx+Rx
     */
    lc3Config.rxConfigSet |= TX_ONLY_CONFIG;

    if (type != WMCP_PROFILE) {
      lc3Config.txConfig.sampleRate = btif_lc3_sample_rate(
           pclient_cbs[profile - 1]->get_sample_rate_cb(lc3Config.rxConfigSet));
      lc3Config.txConfig.channelMode = btif_lc3_channel_mode(
           pclient_cbs[profile - 1]->get_channel_mode_cb(lc3Config.rxConfigSet));

      if (lc3Config.txConfig.channelMode == LC3ChannelMode::JOINT_STEREO ||
          lc3Config.txConfig.channelMode == LC3ChannelMode::MONO) {
        cis_count = 1;
      }

      lc3Config.txConfig.bitrate =
           pclient_cbs[profile - 1]->get_bitrate_cb(lc3Config.rxConfigSet);
      lc3Config.txConfig.octetsPerFrame =
           pclient_cbs[profile - 1]->get_mtu_cb(0, lc3Config.rxConfigSet);
      lc3Config.txConfig.frameDuration =
           pclient_cbs[profile - 1]->get_frame_length_cb(lc3Config.rxConfigSet);

      lc3Config.txConfig.bitsPerSample = BitsPerSample::BITS_24;
      lc3Config.txConfig.numBlocks = 1;
    }

    uint8_t cs[16] = {0};
    for (int i = 0; i  < 16; i++) {
      lc3Config.codecSpecific[i] = cs[i];
    }

    if (type == WMCP_PROFILE) {
      if (lc3Config.rxConfigSet & TX_ONLY_CONFIG) {
        lc3Config.rxConfigSet &= ~TX_ONLY_CONFIG;
      }
      lc3Config.rxConfigSet |= RX_ONLY_CONFIG;
    }

    if (pclient_cbs[profile - 1]->get_is_codec_type_lc3q(
                                     lc3Config.rxConfigSet)) {
      LOG(ERROR) << __func__ << ": Lc3q params are updated";
      lc3Config.codecSpecific[0] = 0x0F;  //Vendor Metadata Length
      lc3Config.codecSpecific[1] = 0xFF;  //Vendor META data type
      lc3Config.codecSpecific[2] = 0x0A;  //Qtil ID
      lc3Config.codecSpecific[3] = 0x00;
      lc3Config.codecSpecific[4] = 0x0B;  //Vendor Metadata length
      lc3Config.codecSpecific[5] = 0x10;  //LC3Q Type
      //0x01;  //LC3Q version
      lc3Config.codecSpecific[6] =
         pclient_cbs[profile - 1]->get_lc3q_ver(lc3Config.rxConfigSet);
    }

    lc3Config.defaultQlevel = 0;
    lc3Config.mode = pclient_cbs[profile - 1]->mode;
    lc3Config.decoderOuputChannels = 0;

    if (type == WMCP_PROFILE) {
      LOG(ERROR) << __func__ << ": Filling Tx dummy values";
      lc3Config.txConfig.sampleRate = ExtSampleRate::RATE_48000;
      lc3Config.txConfig.channelMode = LC3ChannelMode::STEREO;
      lc3Config.txConfig.bitrate = 80000;
      lc3Config.txConfig.octetsPerFrame = 100;
      lc3Config.txConfig.frameDuration = 10000;
      lc3Config.txConfig.bitsPerSample = BitsPerSample::BITS_24;
      lc3Config.txConfig.numBlocks = 1;

      //reset Tx config and set only rx config when SREC is enabled
      if (lc3Config.rxConfigSet & TX_ONLY_CONFIG) {
        lc3Config.rxConfigSet &= ~TX_ONLY_CONFIG;
      }

      lc3Config.rxConfigSet |= RX_ONLY_CONFIG;
      lc3Config.rxConfig.sampleRate = btif_lc3_sample_rate(
          pclient_cbs[profile - 1]->get_sample_rate_cb(lc3Config.rxConfigSet));
      lc3Config.rxConfig.channelMode = btif_lc3_channel_mode(
          pclient_cbs[profile - 1]->get_channel_mode_cb(lc3Config.rxConfigSet));

      if( lc3Config.rxConfig.channelMode == LC3ChannelMode::JOINT_STEREO ||
          lc3Config.rxConfig.channelMode == LC3ChannelMode::MONO) {
        cis_count = 1;
      }

      lc3Config.rxConfig.bitrate =
          pclient_cbs[profile - 1]->get_bitrate_cb(lc3Config.rxConfigSet);
      lc3Config.rxConfig.octetsPerFrame =
          pclient_cbs[profile - 1]->get_mtu_cb(0, lc3Config.rxConfigSet);
      lc3Config.rxConfig.frameDuration =
          pclient_cbs[profile - 1]->get_frame_length_cb(lc3Config.rxConfigSet);
      lc3Config.rxConfig.bitsPerSample = BitsPerSample::BITS_24;
      lc3Config.rxConfig.numBlocks = 1;
    } else if (type == GCP_RX_PROFILE) {
      LOG(ERROR) << __func__ << ": Filling Gaming VBC values";

      lc3Config.rxConfigSet |= TX_RX_BOTH_CONFIG; //For Gaming VBC
      lc3Config.rxConfig.sampleRate = btif_lc3_sample_rate(
          pclient_cbs[profile - 1]->get_sample_rate_cb(lc3Config.rxConfigSet));
      lc3Config.rxConfig.channelMode = btif_lc3_channel_mode(
          pclient_cbs[profile - 1]->get_channel_mode_cb(lc3Config.rxConfigSet));

      if( lc3Config.rxConfig.channelMode == LC3ChannelMode::JOINT_STEREO ||
          lc3Config.rxConfig.channelMode == LC3ChannelMode::MONO) {
        cis_count = 1;
      }

      lc3Config.rxConfig.bitrate =
          pclient_cbs[profile - 1]->get_bitrate_cb(lc3Config.rxConfigSet);
      lc3Config.rxConfig.octetsPerFrame =
          pclient_cbs[profile - 1]->get_mtu_cb(0, lc3Config.rxConfigSet);
      lc3Config.rxConfig.frameDuration =
          pclient_cbs[profile - 1]->get_frame_length_cb(lc3Config.rxConfigSet);
      lc3Config.rxConfig.bitsPerSample = BitsPerSample::BITS_24;
      lc3Config.rxConfig.numBlocks = 1;

      //LC3Q related Info for VBC
      if (pclient_cbs[profile - 1]->get_is_codec_type_lc3q(lc3Config.rxConfigSet)) {
        LOG(ERROR) << __func__ << ": VBC Lc3q params are updated";
        lc3Config.codecSpecific[0] = 0x0F;  //Vendor Metadata Length
        lc3Config.codecSpecific[1] = 0xFF;  //Vendor META data type
        lc3Config.codecSpecific[2] = 0x0A;  //Qtil ID
        lc3Config.codecSpecific[3] = 0x00;
        lc3Config.codecSpecific[4] = 0x0B;  //Vendor Metadata length
        lc3Config.codecSpecific[5] = 0x10;  //LC3Q Type
        //0x01;  //LC3Q version
        lc3Config.codecSpecific[6] =
          pclient_cbs[profile - 1]->get_lc3q_ver(lc3Config.rxConfigSet);
      }
    }
    lc3Config.NumStreamIDGroup = cis_count;

    // To Air
    for (int i = 0; i < cis_count; i++) {
      if (lc3Config.txConfig.channelMode == LC3ChannelMode::STEREO) {//TODO:change rx in wmcp case
        lc3Config.streamMap[(i*3)] = (CHANNEL_FL + (i % 2));
        LOG(ERROR) << __func__ << ": Stereo config of ToAir";
      } else if (lc3Config.txConfig.channelMode == LC3ChannelMode::JOINT_STEREO) {
        LOG(ERROR) << __func__ << ": joint Stereo config of ToAir";
        lc3Config.streamMap[(i*3)] = (CHANNEL_FR | CHANNEL_FL);
      } else {
        lc3Config.streamMap[(i*3)] = i;
      }
      lc3Config.streamMap[(i*3)+1] = i;
      lc3Config.streamMap[(i*3)+2] = TO_AIR;
    }

    // From Air
    if ((lc3Config.rxConfigSet == RX_ONLY_CONFIG) ||
        (lc3Config.rxConfigSet == TX_RX_BOTH_CONFIG)) {
      lc3Config.decoderOuputChannels = cis_count;
      for (int i = cis_count, j = 0; i < cis_count*2; i++, j++) {
        if (((type == WMCP_PROFILE) || (type == GCP_RX_PROFILE)) ?
             lc3Config.rxConfig.channelMode == LC3ChannelMode::STEREO :
             lc3Config.txConfig.channelMode == LC3ChannelMode::STEREO) {//TODO:change rx in wmcp case
          lc3Config.streamMap[(i*3)] = (CHANNEL_FL + (i % 2));
          LOG(ERROR) << __func__ << ": Stereo/VBC config of FromAir";
        } else if (lc3Config.txConfig.channelMode == LC3ChannelMode::JOINT_STEREO) {
          lc3Config.streamMap[(i*3)] = (CHANNEL_FR | CHANNEL_FL);
        } else {
          lc3Config.streamMap[(i*3)] = CHANNEL_MONO;
        }
        lc3Config.streamMap[(i*3)+1] = j; // stream ID
        lc3Config.streamMap[(i*3)+2] = FROM_AIR;  // direction
      }
      lc3Config.NumStreamIDGroup += cis_count;
    }

    // To make sure QSSI builds with VBC changes won't
    // break existing features on older Vendor AUs.
    // Ensured this, with below flag by making rxConfigSet to 0
    // if Tx only or both Tx/Rx set, and same has been manipulated
    // in vendor layer to ensure session has been established properly.
    if (lc3Config.rxConfigSet & TX_ONLY_CONFIG) {
      lc3Config.rxConfigSet  = 0;
    }

    codec_config->config.lc3Config = lc3Config;

    LOG(INFO) << __func__ << ": LC3 codec, CodecConfiguration="
                          << toString(*codec_config);
    return true;
  }

/********LC3 Codec */
  if (a2dp_codec_configs == nullptr) {
    LOG(WARNING) << __func__ << ": failure to get A2DP codec config";
    return false;
  }

  btav_a2dp_codec_config_t current_codec = a2dp_codec_configs->getCodecConfig();
  tBT_A2DP_OFFLOAD a2dp_offload;
  a2dp_codec_configs->getCodecSpecificConfig(&a2dp_offload);
  memset(p_codec_info, 0, AVDT_CODEC_SIZE);
  if (!a2dp_codec_configs->copyOutOtaCodecConfig(p_codec_info))
  {
    LOG(ERROR) << "No valid codec config";
    return false;
  }

  // fill the scrambling support flag
  codec_config->isScramblingEnabled = btif_av_is_scrambling_enabled();

  switch (current_codec.codec_type) {
    case BTAV_A2DP_CODEC_INDEX_SOURCE_SBC:
      [[fallthrough]];
    case BTAV_A2DP_CODEC_INDEX_SINK_SBC: {
      codec_config->codecType = CodecType_2_1::SBC;
      codec_config->config.sbcConfig = {};
      auto sbc_config = codec_config->config.sbcConfig;
      sbc_config.sampleRate = a2dp_codec_to_hal_sample_rate(current_codec);
      if (sbc_config.sampleRate == SampleRate::RATE_UNKNOWN) {
        LOG(ERROR) << __func__
                   << ": Unknown SBC sample_rate=" << current_codec.sample_rate;
        return false;
      }
      uint8_t channel_mode = a2dp_offload.codec_info[0] & A2DP_SBC_IE_CH_MD_MSK;
      switch (channel_mode) {
        case A2DP_SBC_IE_CH_MD_JOINT:
          sbc_config.channelMode = SbcChannelMode::JOINT_STEREO;
          break;
        case A2DP_SBC_IE_CH_MD_STEREO:
          sbc_config.channelMode = SbcChannelMode::STEREO;
          break;
        case A2DP_SBC_IE_CH_MD_DUAL:
          sbc_config.channelMode = SbcChannelMode::DUAL;
          break;
        case A2DP_SBC_IE_CH_MD_MONO:
          sbc_config.channelMode = SbcChannelMode::MONO;
          break;
        default:
          LOG(ERROR) << __func__
                     << ": Unknown SBC channel_mode=" << channel_mode;
          sbc_config.channelMode = SbcChannelMode::UNKNOWN;
          return false;
      }
      uint8_t block_length =
          a2dp_offload.codec_info[1] & A2DP_SBC_IE_BLOCKS_MSK;
      switch (block_length) {
        case A2DP_SBC_IE_BLOCKS_4:
          sbc_config.blockLength = SbcBlockLength::BLOCKS_4;
          break;
        case A2DP_SBC_IE_BLOCKS_8:
          sbc_config.blockLength = SbcBlockLength::BLOCKS_8;
          break;
        case A2DP_SBC_IE_BLOCKS_12:
          sbc_config.blockLength = SbcBlockLength::BLOCKS_12;
          break;
        case A2DP_SBC_IE_BLOCKS_16:
          sbc_config.blockLength = SbcBlockLength::BLOCKS_16;
          break;
        default:
          LOG(ERROR) << __func__
                     << ": Unknown SBC block_length=" << block_length;
          return false;
      }
      uint8_t sub_bands = a2dp_offload.codec_info[1] & A2DP_SBC_IE_SUBBAND_MSK;
      switch (sub_bands) {
        case A2DP_SBC_IE_SUBBAND_4:
          sbc_config.numSubbands = SbcNumSubbands::SUBBAND_4;
          break;
        case A2DP_SBC_IE_SUBBAND_8:
          sbc_config.numSubbands = SbcNumSubbands::SUBBAND_8;
          break;
        default:
          LOG(ERROR) << __func__ << ": Unknown SBC Subbands=" << sub_bands;
          return false;
      }
      uint8_t alloc_method =
          a2dp_offload.codec_info[1] & A2DP_SBC_IE_ALLOC_MD_MSK;
      switch (alloc_method) {
        case A2DP_SBC_IE_ALLOC_MD_S:
          sbc_config.allocMethod = SbcAllocMethod::ALLOC_MD_S;
          break;
        case A2DP_SBC_IE_ALLOC_MD_L:
          sbc_config.allocMethod = SbcAllocMethod::ALLOC_MD_L;
          break;
        default:
          LOG(ERROR) << __func__
                     << ": Unknown SBC alloc_method=" << alloc_method;
          return false;
      }
      sbc_config.minBitpool = a2dp_offload.codec_info[2];
      sbc_config.maxBitpool = a2dp_offload.codec_info[3];
      sbc_config.bitsPerSample =
          a2dp_codec_to_hal_bits_per_sample(current_codec);
      if (sbc_config.bitsPerSample == BitsPerSample::BITS_UNKNOWN) {
        LOG(ERROR) << __func__ << ": Unknown SBC bits_per_sample="
                   << current_codec.bits_per_sample;
        return false;
      }
      codec_config->config.sbcConfig = sbc_config;
      break;
    }

    case BTAV_A2DP_CODEC_INDEX_SOURCE_AAC:
      [[fallthrough]];
    case BTAV_A2DP_CODEC_INDEX_SINK_AAC: {
      codec_config->codecType = CodecType_2_1::AAC;
      codec_config->config.aacConfig = {};
      auto aac_config = codec_config->config.aacConfig;
      // TODO(cheneyni): add more supported types.
      aac_config.objectType = AacObjectType::MPEG2_LC;
      aac_config.sampleRate = a2dp_codec_to_hal_sample_rate(current_codec);
      if (aac_config.sampleRate == SampleRate::RATE_UNKNOWN) {
        LOG(ERROR) << __func__
                   << ": Unknown AAC sample_rate=" << current_codec.sample_rate;
        return false;
      }
      aac_config.channelMode = a2dp_codec_to_hal_channel_mode(current_codec);
      if (aac_config.channelMode == ChannelMode::UNKNOWN) {
        LOG(ERROR) << __func__ << ": Unknown AAC channel_mode="
                   << current_codec.channel_mode;
        return false;
      }
      uint8_t vbr_enabled =
              a2dp_offload.codec_info[1] & A2DP_AAC_VARIABLE_BIT_RATE_MASK;
      switch (vbr_enabled) {
        case A2DP_AAC_VARIABLE_BIT_RATE_ENABLED:
          LOG(INFO) << __func__ << " Enabled AAC VBR =" << +vbr_enabled;
          aac_config.variableBitRateEnabled = AacVariableBitRate::ENABLED;
          break;
        case A2DP_AAC_VARIABLE_BIT_RATE_DISABLED:
          LOG(INFO) << __func__ << " Disabled AAC VBR =" << +vbr_enabled;
          aac_config.variableBitRateEnabled = AacVariableBitRate::DISABLED;
          break;
        default:
          LOG(ERROR) << __func__ << ": Unknown AAC VBR=" << +vbr_enabled;
          return false;
      }
      aac_config.bitsPerSample =
          a2dp_codec_to_hal_bits_per_sample(current_codec);
      if (aac_config.bitsPerSample == BitsPerSample::BITS_UNKNOWN) {
        LOG(ERROR) << __func__ << ": Unknown AAC bits_per_sample="
                   << current_codec.bits_per_sample;
        return false;
      }
      codec_config->config.aacConfig = aac_config;
      break;
    }
    case BTAV_A2DP_CODEC_INDEX_SOURCE_APTX:
      [[fallthrough]];
    case BTAV_A2DP_CODEC_INDEX_SOURCE_APTX_HD: {
      if (current_codec.codec_type == BTAV_A2DP_CODEC_INDEX_SOURCE_APTX) {
        codec_config->codecType = CodecType_2_1::APTX;
      } else {
        codec_config->codecType = CodecType_2_1::APTX_HD;
      }
      codec_config->config.aptxConfig = {};
      auto aptx_config = codec_config->config.aptxConfig;
      aptx_config.sampleRate = a2dp_codec_to_hal_sample_rate(current_codec);
      if (aptx_config.sampleRate == SampleRate::RATE_UNKNOWN) {
        LOG(ERROR) << __func__ << ": Unknown aptX sample_rate="
                   << current_codec.sample_rate;
        return false;
      }
      aptx_config.channelMode = a2dp_codec_to_hal_channel_mode(current_codec);
      if (aptx_config.channelMode == ChannelMode::UNKNOWN) {
        LOG(ERROR) << __func__ << ": Unknown aptX channel_mode="
                   << current_codec.channel_mode;
        return false;
      }
      aptx_config.bitsPerSample =
          a2dp_codec_to_hal_bits_per_sample(current_codec);
      if (aptx_config.bitsPerSample == BitsPerSample::BITS_UNKNOWN) {
        LOG(ERROR) << __func__ << ": Unknown aptX bits_per_sample="
                   << current_codec.bits_per_sample;
        return false;
      }
      codec_config->config.aptxConfig = aptx_config;
      break;
    }
    case BTAV_A2DP_CODEC_INDEX_SOURCE_APTX_ADAPTIVE: {
      tA2DP_APTX_ADAPTIVE_CIE adaptive_cie;
      codec_config->codecType = CodecType_2_1::APTX_ADAPTIVE;
      codec_config->config.aptxAdaptiveConfig = {};
      auto aptx_adaptive_config = codec_config->config.aptxAdaptiveConfig;
      aptx_adaptive_config.sampleRate = a2dp_codec_to_hal_sample_rate(current_codec);
      if (aptx_adaptive_config.sampleRate == SampleRate::RATE_UNKNOWN) {
        LOG(ERROR) << __func__ << ": Unknown LDAC sample_rate="
                   << current_codec.sample_rate;
        return false;
      }
      aptx_adaptive_config.bitsPerSample =
          a2dp_codec_to_hal_bits_per_sample(current_codec);
      if (aptx_adaptive_config.bitsPerSample == BitsPerSample::BITS_UNKNOWN) {
        LOG(ERROR) << __func__ << ": Unknown aptX adaptive bits_per_sample="
                   << current_codec.bits_per_sample;
        return false;
      }
      if(!A2DP_GetAptxAdaptiveCIE(p_codec_info, &adaptive_cie)) {
        LOG(ERROR) << __func__ << ": Unable to get Aptx Adaptive CIE";
        return false;
      }
      aptx_adaptive_config.channelMode = static_cast<AptxAdaptiveChannelMode>
                                        (adaptive_cie.channelMode);
      if (aptx_adaptive_config.channelMode >=
                 AptxAdaptiveChannelMode::UNKNOWN) {
        LOG(ERROR) << __func__ << ": Unknown aptX adaptive channel_mode="
                   << adaptive_cie.channelMode;
        return false;
      }
      aptx_adaptive_config.aptxMode = static_cast<AptxMode>
                            (btif_av_get_aptx_mode_info());
      aptx_adaptive_config.sinkBuffering = { 20, 50, 20, 50, 20, 50 };
      aptx_adaptive_config.ttp = { adaptive_cie.aptx_data.ttp_ll_0, adaptive_cie.aptx_data.ttp_ll_1,
                                   adaptive_cie.aptx_data.ttp_hq_0, adaptive_cie.aptx_data.ttp_hq_1,
                                   adaptive_cie.aptx_data.ttp_tws_0, adaptive_cie.aptx_data.ttp_tws_1
                                 };
      if (btif_av_current_device_is_tws()) {
        aptx_adaptive_config.inputMode = static_cast<InputMode>(0x01);
      } else {
        aptx_adaptive_config.inputMode = static_cast<InputMode>(0x00);
      }
      aptx_adaptive_config.inputFadeDuration = 0xff;
      aptx_adaptive_config.aptxAdaptiveConfigStream[0] =  adaptive_cie.aptx_data.cap_ext_ver_num;
      aptx_adaptive_config.aptxAdaptiveConfigStream[1] =  adaptive_cie.aptx_data.aptx_adaptive_sup_features & 0x000000FF;
      aptx_adaptive_config.aptxAdaptiveConfigStream[2] =  ((adaptive_cie.aptx_data.aptx_adaptive_sup_features & 0x0000FF00) >> 8);
      aptx_adaptive_config.aptxAdaptiveConfigStream[3] =  ((adaptive_cie.aptx_data.aptx_adaptive_sup_features & 0x00FF0000) >> 16);
      aptx_adaptive_config.aptxAdaptiveConfigStream[4] =  ((adaptive_cie.aptx_data.aptx_adaptive_sup_features & 0xFF000000) >> 24);
      aptx_adaptive_config.aptxAdaptiveConfigStream[5] =  adaptive_cie.aptx_data.first_setup_pref;
      aptx_adaptive_config.aptxAdaptiveConfigStream[6] =  adaptive_cie.aptx_data.second_setup_pref;
      aptx_adaptive_config.aptxAdaptiveConfigStream[7] =  adaptive_cie.aptx_data.third_setup_pref;
      aptx_adaptive_config.aptxAdaptiveConfigStream[8] =  adaptive_cie.aptx_data.fourth_setup_pref;
      aptx_adaptive_config.aptxAdaptiveConfigStream[9] =  adaptive_cie.aptx_data.eoc0;
      aptx_adaptive_config.aptxAdaptiveConfigStream[10] =  adaptive_cie.aptx_data.eoc1;

      codec_config->config.aptxAdaptiveConfig = aptx_adaptive_config;
      break;
    }
    case BTAV_A2DP_CODEC_INDEX_SOURCE_LDAC: {
      codec_config->codecType = CodecType_2_1::LDAC;
      codec_config->config.ldacConfig = {};
      auto ldac_config = codec_config->config.ldacConfig;
      ldac_config.sampleRate = a2dp_codec_to_hal_sample_rate(current_codec);
      if (ldac_config.sampleRate == SampleRate::RATE_UNKNOWN) {
        LOG(ERROR) << __func__ << ": Unknown LDAC sample_rate="
                   << current_codec.sample_rate;
        return false;
      }
      switch (a2dp_offload.codec_info[7]) {
        case A2DP_LDAC_CHANNEL_MODE_STEREO:
          ldac_config.channelMode = LdacChannelMode::STEREO;
          break;
        case A2DP_LDAC_CHANNEL_MODE_DUAL:
          ldac_config.channelMode = LdacChannelMode::DUAL;
          break;
        case A2DP_LDAC_CHANNEL_MODE_MONO:
          ldac_config.channelMode = LdacChannelMode::MONO;
          break;
        default:
          LOG(ERROR) << __func__ << ": Unknown LDAC channel_mode="
                     << a2dp_offload.codec_info[7];
          ldac_config.channelMode = LdacChannelMode::UNKNOWN;
          return false;
      }
      switch (a2dp_offload.codec_info[6]) {
        case A2DP_LDAC_QUALITY_HIGH:
          ldac_config.qualityIndex = LdacQualityIndex::QUALITY_HIGH;
          break;
        case A2DP_LDAC_QUALITY_MID:
          ldac_config.qualityIndex = LdacQualityIndex::QUALITY_MID;
          break;
        case A2DP_LDAC_QUALITY_LOW:
          ldac_config.qualityIndex = LdacQualityIndex::QUALITY_LOW;
          break;
        case A2DP_LDAC_QUALITY_ABR_OFFLOAD:
          ldac_config.qualityIndex = LdacQualityIndex::QUALITY_ABR;
          break;
        default:
          LOG(ERROR) << __func__ << ": Unknown LDAC QualityIndex="
                     << a2dp_offload.codec_info[6];
          return false;
      }
      ldac_config.bitsPerSample =
          a2dp_codec_to_hal_bits_per_sample(current_codec);
      if (ldac_config.bitsPerSample == BitsPerSample::BITS_UNKNOWN) {
        LOG(ERROR) << __func__ << ": Unknown LDAC bits_per_sample="
                   << current_codec.bits_per_sample;
        return false;
      }
      codec_config->config.ldacConfig = ldac_config;
      break;
    }
    case BTAV_A2DP_CODEC_INDEX_SOURCE_APTX_TWS: {
      codec_config->codecType = CodecType_2_1::APTX_TWS;
      codec_config->config.aptxTwsConfig = {};
      auto aptx_tws_config = codec_config->config.aptxTwsConfig;
      aptx_tws_config.sampleRate = a2dp_codec_to_hal_sample_rate(current_codec);
      if (aptx_tws_config.sampleRate == SampleRate::RATE_UNKNOWN) {
        LOG(ERROR) << __func__ << ": Unknown aptX tws sample_rate="
                   << current_codec.sample_rate;
        return false;
      }
      aptx_tws_config.channelMode = a2dp_codec_to_hal_channel_mode(current_codec);
      if (aptx_tws_config.channelMode == ChannelMode::UNKNOWN) {
        LOG(ERROR) << __func__ << ": Unknown aptX tws channel_mode="
                   << current_codec.channel_mode;
        return false;
      }
      aptx_tws_config.syncMode = 0x02;
      codec_config->config.aptxTwsConfig = aptx_tws_config;
      break;
    }
    case BTAV_A2DP_CODEC_INDEX_MAX:
      [[fallthrough]];
    default:
      LOG(ERROR) << __func__
                 << ": Unknown codec_type=" << current_codec.codec_type;
      codec_config->codecType = CodecType_2_1::UNKNOWN;
      codec_config->config = {};
      return false;
  }
  bta_av_co_get_peer_params(&peer_param);
  codec_type = A2DP_GetCodecType((const uint8_t*)p_codec_info);
  LOG(INFO) << __func__ << ": codec_type" << codec_type;
  // Obtain the MTU
  codec_config->peerMtu = peer_param.peer_mtu - A2DP_HEADER_SIZE;
  if (A2DP_MEDIA_CT_SBC == codec_type) {
    bitrate = A2DP_GetOffloadBitrateSbc(a2dp_codec_configs, peer_param.is_peer_edr);
    LOG(INFO) << __func__ << "SBC bitrate" << bitrate;
    codec_config->encodedAudioBitrate = bitrate * 1000;
  }
  else if (A2DP_MEDIA_CT_NON_A2DP == codec_type) {
    int samplerate = A2DP_GetTrackSampleRate(p_codec_info);
    if ((A2DP_VendorCodecGetVendorId(p_codec_info)) == A2DP_LDAC_VENDOR_ID) {
      codec_config->encodedAudioBitrate = A2DP_GetTrackBitRate(p_codec_info);
      LOG(INFO) << __func__ << "LDAC bitrate" << codec_config->encodedAudioBitrate;
    } else {
      /* BR = (Sampl_Rate * PCM_DEPTH * CHNL)/Compression_Ratio */
      int bits_per_sample = 16; // TODO
      codec_config->encodedAudioBitrate = (samplerate * bits_per_sample * 2)/4;
      LOG(INFO) << __func__ << "Aptx bitrate" << codec_config->encodedAudioBitrate;
    }
  }
  else if (A2DP_MEDIA_CT_AAC == codec_type) {
    bool is_AAC_frame_ctrl_stack_enable =
                    controller_get_interface()->supports_aac_frame_ctl();
    uint32_t codec_based_bit_rate = 0;
    uint32_t mtu_based_bit_rate = 0;
    LOG(INFO) << __func__ << "Stack AAC frame control enabled"
                          << is_AAC_frame_ctrl_stack_enable;
    tA2DP_AAC_CIE aac_cie;
    if(!A2DP_GetAacCIE(p_codec_info, &aac_cie)) {
      LOG(ERROR) << __func__ << ": Unable to get AAC CIE";
      return false;
    }
    codec_based_bit_rate = aac_cie.bitRate;

    if (is_AAC_frame_ctrl_stack_enable) {
      int sample_rate = A2DP_GetTrackSampleRate(p_codec_info);
      mtu_based_bit_rate = (peer_param.peer_mtu - AAC_LATM_HEADER)
                                          * (8 * sample_rate / AAC_SAMPLE_SIZE);
      LOG(INFO) << __func__ << "sample_rate " << sample_rate;
      LOG(INFO) << __func__ << " peer_mtu " << peer_param.peer_mtu;
      LOG(INFO) << __func__ << " codec_bit_rate " << codec_based_bit_rate
                << " MTU bitrate " << mtu_based_bit_rate;
      codec_config->encodedAudioBitrate = (codec_based_bit_rate < mtu_based_bit_rate) ?
                                           codec_based_bit_rate:mtu_based_bit_rate;
    } else {
      codec_config->encodedAudioBitrate = codec_based_bit_rate;
    }
  }
  LOG(INFO) << __func__ << ": CodecConfiguration=" << toString(*codec_config);
  return true;
}
bool a2dp_get_selected_hal_pcm_config(PcmParameters* pcm_config) {
  if (pcm_config == nullptr) return false;
  A2dpCodecConfig* a2dp_codec_configs = bta_av_get_a2dp_current_codec();
  if (a2dp_codec_configs == nullptr) {
    LOG(WARNING) << __func__ << ": failure to get A2DP codec config";
    *pcm_config = ::bluetooth::audio::BluetoothAudioClientInterface::
        kInvalidPcmConfiguration;
    return false;
  }

  btav_a2dp_codec_config_t current_codec = a2dp_codec_configs->getCodecConfig();
  pcm_config->sampleRate = a2dp_codec_to_hal_sample_rate(current_codec);
  pcm_config->bitsPerSample = a2dp_codec_to_hal_bits_per_sample(current_codec);
  pcm_config->channelMode = a2dp_codec_to_hal_channel_mode(current_codec);
  return (pcm_config->sampleRate != SampleRate::RATE_UNKNOWN &&
          pcm_config->bitsPerSample != BitsPerSample::BITS_UNKNOWN &&
          pcm_config->channelMode != ChannelMode::UNKNOWN);
}

bool a2dp_is_audio_pcm_config_params_changed(PcmParameters* pcm_config) {
  if (pcm_config == nullptr) return false;
  A2dpCodecConfig* a2dp_codec_configs = bta_av_get_a2dp_current_codec();
  if (a2dp_codec_configs == nullptr) {
    LOG(WARNING) << __func__ << ": failure to get A2DP codec config";
    *pcm_config = ::bluetooth::audio::BluetoothAudioClientInterface::
        kInvalidPcmConfiguration;
    return false;
  }

  btav_a2dp_codec_config_t current_codec = a2dp_codec_configs->getCodecConfig();
  if((pcm_config->sampleRate != a2dp_codec_to_hal_sample_rate(current_codec)) ||
     (pcm_config->bitsPerSample !=
          a2dp_codec_to_hal_bits_per_sample(current_codec)) ||
     (pcm_config->channelMode !=
          a2dp_codec_to_hal_channel_mode(current_codec))) {
    return true;
  }
  return false;
}
}  // namespace

namespace bluetooth {
namespace audio {
namespace a2dp {

// Checking if new bluetooth_audio is supported
bool is_hal_2_0_supported() {
  if (!is_configured) {
    btaudio_a2dp_supported =
      property_get_bool(BLUETOOTH_AUDIO_PROP_ENABLED, true);
    is_configured = true;
  }
  return btaudio_a2dp_supported;
}
void get_hal_version() {
  LOG(WARNING) << __func__;
  if (!is_hal_version_fetched) {
    bluetooth::audio::BluetoothAudioClientInterface* hal_clientif = nullptr;
    IBluetoothTransportInstance_2_1* sink = nullptr;
    hal_clientif = new bluetooth::audio::BluetoothAudioClientInterface(
     sink, nullptr, nullptr);
    if (!strcmp(hal_clientif->GetHalVersion(),"hal_2_1")) {
      LOG(WARNING) << __func__ << ":hal version 2.1";
      hal_2_1_enabled = true;
      is_hal_version_fetched = true;
    }
  }
}

// Checking if new bluetooth_audio is enabled
bool is_hal_2_0_enabled() { return ((a2dp_sink_2_1 && a2dp_sink_2_1->IsActvie()) ||
                                     (a2dp_sink && a2dp_sink->IsActvie())); }

// Initialize BluetoothAudio HAL: openProvider
#if AHIM_ENABLED
bool init( thread_t* message_loop, uint8_t profile) {
#else
bool init( thread_t* message_loop) {
#endif

  LOG(WARNING) << __func__;
  std::unique_lock<std::mutex> guard(internal_mutex_);
  if (!is_hal_2_0_supported()) {
    LOG(ERROR) << __func__ << ": BluetoothAudio HAL is not supported";
    return false;
  }

  get_hal_version();
  if (hal_2_1_enabled) {
    AudioConfiguration_2_1 audio_config{};
#if AHIM_ENABLED
    if (profile == A2DP) {
#endif
      if (btif_av_is_split_a2dp_enabled()) {
        CodecConfiguration_2_1 codec_config{};
        if (!a2dp_get_selected_hal_codec_config_2_1(&codec_config, profile)) {
          LOG(ERROR) << __func__ << ": Failed to get CodecConfiguration";
          return false;
        }
        audio_config.codecConfig = codec_config;
        LOG(WARNING) << __func__ << ":Session type OFFLOAD";
        session_type = SessionType::A2DP_HARDWARE_OFFLOAD_DATAPATH;
      } else {
        PcmParameters pcm_config{};
        if (!a2dp_get_selected_hal_pcm_config(&pcm_config)) {
          LOG(ERROR) << __func__ << ": Failed to get PcmConfiguration";
          return false;
        }
        audio_config.pcmConfig = pcm_config;
        session_type = SessionType::A2DP_SOFTWARE_ENCODING_DATAPATH;
      }
#if AHIM_ENABLED
    } else if(profile == AUDIO_GROUP_MGR || profile == BROADCAST) {
        CodecConfiguration_2_1 codec_config{};
        if (!a2dp_get_selected_hal_codec_config_2_1(&codec_config, profile)) {
          LOG(ERROR) << __func__ << ": Failed to get CodecConfiguration";
          return false;
        }
        audio_config.codecConfig = codec_config;
        LOG(WARNING) << __func__ << ":Session type OFFLOAD";
        session_type = SessionType::A2DP_HARDWARE_OFFLOAD_DATAPATH;
    }
#endif

      if(a2dp_sink_2_1 == nullptr) {
        LOG(WARNING) << __func__ << "Init A2dpTransport_2_1";
        a2dp_sink_2_1 = new A2dpTransport_2_1(session_type, audio_config);
      } else {
        a2dp_sink_2_1->Init(session_type, audio_config);
      }
      if(a2dp_hal_clientif == nullptr) {
        a2dp_hal_clientif = new bluetooth::audio::BluetoothAudioClientInterface(
        a2dp_sink_2_1, message_loop, &internal_mutex_);
        death_handler_thread = message_loop;
      } else if(death_handler_thread != message_loop) {
        death_handler_thread = message_loop;
       //update the client interface as well
        LOG(WARNING) << __func__ << ": updating death handler thread  "
                     << death_handler_thread;
        a2dp_hal_clientif->UpdateDeathHandlerThread(death_handler_thread);
      }
      if (remote_delay != 0) {
        LOG(INFO) << __func__ << ": restore DELAY "
                  << static_cast<float>(remote_delay / 10.0) << " ms";
        a2dp_sink_2_1->SetRemoteDelay(remote_delay);
        remote_delay = 0;
      }
    }else {
       AudioConfiguration audio_config{};
       if (btif_av_is_split_a2dp_enabled()) {
         CodecConfiguration codec_config{};
         if (!a2dp_get_selected_hal_codec_config(&codec_config)) {
           LOG(ERROR) << __func__ << ": Failed to get CodecConfiguration";
           return false;
         }
         audio_config.codecConfig = codec_config;
         session_type = SessionType::A2DP_HARDWARE_OFFLOAD_DATAPATH;
       } else {
         PcmParameters pcm_config{};
        if (!a2dp_get_selected_hal_pcm_config(&pcm_config)) {
          LOG(ERROR) << __func__ << ": Failed to get PcmConfiguration";
          return false;
        }
        audio_config.pcmConfig = pcm_config;
        session_type = SessionType::A2DP_SOFTWARE_ENCODING_DATAPATH;
      }
      if(a2dp_sink == nullptr) {
        a2dp_sink = new A2dpTransport(session_type, audio_config);
      } else {
        a2dp_sink->Init(session_type, audio_config);
      }
      if(a2dp_hal_clientif == nullptr) {
        a2dp_hal_clientif = new bluetooth::audio::BluetoothAudioClientInterface(
          a2dp_sink, message_loop, &internal_mutex_);
        death_handler_thread = message_loop;
      } else if(death_handler_thread != message_loop) {
        death_handler_thread = message_loop;
        //update the client interface as well
        LOG(WARNING) << __func__ << ": updating death handler thread  "
                     << death_handler_thread;
        a2dp_hal_clientif->UpdateDeathHandlerThread(death_handler_thread);
      }

      if (remote_delay != 0) {
        LOG(INFO) << __func__ << ": restore DELAY "
                  << static_cast<float>(remote_delay / 10.0) << " ms";
        a2dp_sink->SetRemoteDelay(remote_delay);
        remote_delay = 0;
      }
    }
  return true;
}

// Clean up BluetoothAudio HAL
void cleanup() {
  LOG(WARNING) << __func__ << ": end_session has been called.";
  end_session();
}


// check for audio feeding params are same for newly set up codec vs
// what was already set up on hidl side
bool is_restart_session_needed() {
  std::unique_lock<std::mutex> guard(internal_mutex_);
  bool split_enabled = btif_av_is_split_a2dp_enabled();
  if (!is_hal_2_0_enabled()) {
    LOG(ERROR) << __func__ << ": BluetoothAudio HAL is not enabled";
    return false;
  }
  if (a2dp_sink_2_1) {
    AudioConfiguration_2_1 audio_config = a2dp_sink_2_1->GetAudioConfiguration();
    if (split_enabled && session_type ==
                   SessionType::A2DP_HARDWARE_OFFLOAD_DATAPATH) {
      return a2dp_is_audio_codec_config_params_changed_2_1(
                       &audio_config.codecConfig);
    } else if(!split_enabled && session_type ==
                   SessionType::A2DP_SOFTWARE_ENCODING_DATAPATH) {
      A2dpCodecConfig* a2dp_codec_configs = bta_av_get_a2dp_current_codec();
      if (a2dp_codec_configs == nullptr) {
        LOG(WARNING) << __func__ << ": failure to get A2DP codec config";
        return false;
      }
      btav_a2dp_codec_config_t current_codec = a2dp_codec_configs->getCodecConfig();
      LOG(ERROR) << __func__ <<  sw_codec_type << " " <<  current_codec.codec_type;
      if(sw_codec_type != current_codec.codec_type) {
        LOG(ERROR) << __func__ << ": codec differed ";
        return true;
      }
      return a2dp_is_audio_pcm_config_params_changed(
                       &audio_config.pcmConfig);
    } else {
      return true;
    }
  } else {
    AudioConfiguration audio_config = a2dp_sink->GetAudioConfiguration();
    if (split_enabled && session_type ==
                   SessionType::A2DP_HARDWARE_OFFLOAD_DATAPATH) {
      return a2dp_is_audio_codec_config_params_changed(
                       &audio_config.codecConfig);
    } else if(!split_enabled && session_type ==
                   SessionType::A2DP_SOFTWARE_ENCODING_DATAPATH) {
      A2dpCodecConfig* a2dp_codec_configs = bta_av_get_a2dp_current_codec();
      if (a2dp_codec_configs == nullptr) {
        LOG(WARNING) << __func__ << ": failure to get A2DP codec config";
        return false;
      }
      btav_a2dp_codec_config_t current_codec = a2dp_codec_configs->getCodecConfig();
      LOG(ERROR) << __func__ <<  sw_codec_type << " " <<  current_codec.codec_type;
      if(sw_codec_type != current_codec.codec_type) {
        LOG(ERROR) << __func__ << ": codec differed ";
        return true;
      }
      return a2dp_is_audio_pcm_config_params_changed(
                       &audio_config.pcmConfig);
    } else {
      return true;
    }
  }
}

void update_session_params(SessionParamType param_type) {
  std::unique_lock<std::mutex> guard(internal_mutex_);
  if (!is_hal_2_0_enabled() || !is_session_started) {
    LOG(ERROR) << __func__ << ": BluetoothAudio HAL is not enabled/started";
    return;
  }
  if (a2dp_sink_2_1) {
    AudioConfiguration_2_1 audio_config = a2dp_sink_2_1->GetAudioConfiguration();
    CodecConfiguration_2_1 *codec_config = &audio_config.codecConfig;
    if(SessionParamType::MTU == param_type) {
      tA2DP_ENCODER_INIT_PEER_PARAMS peer_param;
      bta_av_co_get_peer_params(&peer_param);
      if(session_peer_mtu != peer_param.peer_mtu) {
        LOG(INFO) << __func__ << ": updating peer mtu";
        if(session_type == SessionType::A2DP_HARDWARE_OFFLOAD_DATAPATH) {
          codec_config->peerMtu =  peer_param.peer_mtu -
                                               A2DP_HEADER_SIZE;
          a2dp_hal_clientif->UpdateAudioConfig_2_1(audio_config);
          SessionParams session_params{};
          session_params.paramType = SessionParamType::MTU;
          session_params.param.mtu = codec_config->peerMtu;
          a2dp_hal_clientif->updateSessionParams(session_params);
        } else if(session_type == SessionType::A2DP_SOFTWARE_ENCODING_DATAPATH) {
          btif_a2dp_source_encoder_init();
        }
     }
   }
  } else {
    AudioConfiguration audio_config = a2dp_sink->GetAudioConfiguration();
    CodecConfiguration *codec_config = &audio_config.codecConfig;
    if(SessionParamType::MTU == param_type) {
      tA2DP_ENCODER_INIT_PEER_PARAMS peer_param;
      bta_av_co_get_peer_params(&peer_param);
      if(session_peer_mtu != peer_param.peer_mtu) {
        LOG(INFO) << __func__ << ": updating peer mtu";
        if(session_type == SessionType::A2DP_HARDWARE_OFFLOAD_DATAPATH) {
          codec_config->peerMtu =  peer_param.peer_mtu -
                                               A2DP_HEADER_SIZE;
          a2dp_hal_clientif->UpdateAudioConfig(audio_config);
          SessionParams session_params{};
          session_params.paramType = SessionParamType::MTU;
          session_params.param.mtu = codec_config->peerMtu;
          a2dp_hal_clientif->updateSessionParams(session_params);
        } else if(session_type == SessionType::A2DP_SOFTWARE_ENCODING_DATAPATH) {
          btif_a2dp_source_encoder_init();
        }
      }
    }
  }
}

// Set up the codec into BluetoothAudio HAL
#if AHIM_ENABLED
bool setup_codec(uint8_t profile) {
#else
bool setup_codec() {
#endif

  std::unique_lock<std::mutex> guard(internal_mutex_);
  tA2DP_ENCODER_INIT_PEER_PARAMS peer_param;
  if (!is_hal_2_0_enabled()) {
    LOG(ERROR) << __func__ << ": BluetoothAudio HAL is not enabled";
    return false;
  }
  if (a2dp_sink_2_1) {
     AudioConfiguration_2_1 audio_config{};

#if AHIM_ENABLED
     if (profile == A2DP || profile == AUDIO_GROUP_MGR) {
#endif
       if (session_type == SessionType::A2DP_HARDWARE_OFFLOAD_DATAPATH) {
         CodecConfiguration_2_1 codec_config{};
         if (!a2dp_get_selected_hal_codec_config_2_1(&codec_config, profile)) {
           LOG(ERROR) << __func__ << ": Failed to get CodecConfiguration";
           return false;
         }
         audio_config.codecConfig = codec_config;
       } else if (session_type == SessionType::A2DP_SOFTWARE_ENCODING_DATAPATH) {
         PcmParameters pcm_config{};
         if (!a2dp_get_selected_hal_pcm_config(&pcm_config)) {
           LOG(ERROR) << __func__ << ": Failed to get PcmConfiguration";
           return false;
         }
         A2dpCodecConfig* a2dp_codec_configs = bta_av_get_a2dp_current_codec();
         if (a2dp_codec_configs == nullptr) {
           LOG(WARNING) << __func__ << ": failure to get A2DP codec config";
           return false;
         }
         btav_a2dp_codec_config_t current_codec = a2dp_codec_configs->getCodecConfig();
         audio_config.pcmConfig = pcm_config;
         sw_codec_type = current_codec.codec_type;
       }
       //store the MTU as well
       bta_av_co_get_peer_params(&peer_param);
       session_peer_mtu = peer_param.peer_mtu;
#if AHIM_ENABLED
     }
#endif
     return a2dp_hal_clientif->UpdateAudioConfig_2_1(audio_config);
  } else {
    AudioConfiguration audio_config{};
    if (session_type == SessionType::A2DP_HARDWARE_OFFLOAD_DATAPATH) {
      CodecConfiguration codec_config{};
      if (!a2dp_get_selected_hal_codec_config(&codec_config)) {
        LOG(ERROR) << __func__ << ": Failed to get CodecConfiguration";
        return false;
      }
      audio_config.codecConfig = codec_config;
    } else if (session_type == SessionType::A2DP_SOFTWARE_ENCODING_DATAPATH) {
      PcmParameters pcm_config{};
      if (!a2dp_get_selected_hal_pcm_config(&pcm_config)) {
        LOG(ERROR) << __func__ << ": Failed to get PcmConfiguration";
        return false;
      }
      A2dpCodecConfig* a2dp_codec_configs = bta_av_get_a2dp_current_codec();
      if (a2dp_codec_configs == nullptr) {
        LOG(WARNING) << __func__ << ": failure to get A2DP codec config";
        return false;
      }
      btav_a2dp_codec_config_t current_codec = a2dp_codec_configs->getCodecConfig();
      audio_config.pcmConfig = pcm_config;
      sw_codec_type = current_codec.codec_type;
    }
    //store the MTU as well
    bta_av_co_get_peer_params(&peer_param);
    session_peer_mtu = peer_param.peer_mtu;
    return a2dp_hal_clientif->UpdateAudioConfig(audio_config);
  }
}

void start_session() {
  std::unique_lock<std::mutex> guard(internal_mutex_);
  if (!is_hal_2_0_enabled()) {
    LOG(ERROR) << __func__ << ": BluetoothAudio HAL is not enabled";
    return;
  } else if(is_session_started) {
    LOG(ERROR) << __func__ << ": BluetoothAudio HAL session is already started";
    return;
  }
  LOG(WARNING) << __func__;
  is_playing = false;
  a2dp_hal_clientif->StartSession();
  is_session_started = true;
}

void end_session() {
  std::unique_lock<std::mutex> guard(internal_mutex_);
  if (!is_hal_2_0_enabled()) {
    LOG(ERROR) << __func__ << ": BluetoothAudio HAL is not enabled";
    return;
  } else if(!is_session_started) {
    LOG(ERROR) << __func__ << ": BluetoothAudio HAL session is not started";
    return;
  }
  LOG(WARNING) << __func__;
  tA2DP_CTRL_CMD pending_cmd = A2DP_CTRL_CMD_NONE;
  if (a2dp_sink_2_1)
    pending_cmd = a2dp_sink_2_1->GetPendingCmd();
  else
    pending_cmd = a2dp_sink->GetPendingCmd();
  if (pending_cmd == A2DP_CTRL_CMD_START) {
    LOG(INFO) << __func__ << ":honoring pending A2DP_CTRL_CMD_START";
    a2dp_hal_clientif->StreamStarted(a2dp_ack_to_bt_audio_ctrl_ack
                    (A2DP_CTRL_ACK_DISCONNECT_IN_PROGRESS));
  } else if (pending_cmd == A2DP_CTRL_CMD_SUSPEND) {
    LOG(INFO) << __func__ << ":honoring pending A2DP_CTRL_CMD_SUSPEND/STOP";
    a2dp_hal_clientif->StreamSuspended(a2dp_ack_to_bt_audio_ctrl_ack
                    (A2DP_CTRL_ACK_DISCONNECT_IN_PROGRESS));
  }
  if (a2dp_sink_2_1) {
    a2dp_sink_2_1->Cleanup();
  } else {
    a2dp_sink->Cleanup();
  }
  //a2dp_sink->Cleanup();
  audio_start_awaited = false;
  btif_av_reset_reconfig_flag();
  is_playing = false;
  a2dp_hal_clientif->EndSession();
  sw_codec_type = BTAV_A2DP_CODEC_INDEX_SOURCE_MIN;
  session_peer_mtu = 0;
  session_type = SessionType::UNKNOWN;
  is_session_started = false;
  death_handler_thread = nullptr;
  remote_delay = 0;
}

tA2DP_CTRL_CMD get_pending_command() {
  std::unique_lock<std::mutex> guard(internal_mutex_);
  tA2DP_CTRL_CMD pending_cmd = A2DP_CTRL_CMD_NONE;
  if (!is_hal_2_0_enabled()) {
    LOG(ERROR) << __func__ << ": BluetoothAudio HAL is not enabled";
  } else {
    if (a2dp_sink_2_1)
      pending_cmd = a2dp_sink_2_1->GetPendingCmd();
    else
      pending_cmd = a2dp_sink->GetPendingCmd();
  }
  return pending_cmd;
}

void reset_pending_command() {
  std::unique_lock<std::mutex> guard(internal_mutex_);
  if (!is_hal_2_0_enabled()) {
    LOG(ERROR) << __func__ << ": BluetoothAudio HAL is not enabled";
    return;
  }
  if (a2dp_sink_2_1)
    a2dp_sink_2_1->ResetPendingCmd();
  else
    a2dp_sink->ResetPendingCmd();
}

void update_pending_command(tA2DP_CTRL_CMD cmd) {
  std::unique_lock<std::mutex> guard(internal_mutex_);
  if (!is_hal_2_0_enabled()) {
    LOG(ERROR) << __func__ << ": BluetoothAudio HAL is not enabled";
    return;
  }
  if (a2dp_sink_2_1)
    a2dp_sink_2_1->UpdatePendingCmd(cmd);
  else
    a2dp_sink->UpdatePendingCmd(cmd);
}

void ack_stream_started(const tA2DP_CTRL_ACK& ack) {
  std::unique_lock<std::mutex> guard(internal_mutex_);
  if (!is_hal_2_0_enabled()) {
    LOG(ERROR) << __func__ << ": BluetoothAudio HAL is not enabled";
    return;
  }
  auto ctrl_ack = a2dp_ack_to_bt_audio_ctrl_ack(ack);
  LOG(INFO) << __func__ << ": result=" << ctrl_ack;
  tA2DP_CTRL_CMD pending_cmd = A2DP_CTRL_CMD_NONE;
  if (a2dp_sink_2_1)
    pending_cmd = a2dp_sink_2_1->GetPendingCmd();
  else
    pending_cmd = a2dp_sink->GetPendingCmd();
  if (pending_cmd == A2DP_CTRL_CMD_START) {
    a2dp_hal_clientif->StreamStarted(ctrl_ack);
  } else {
    LOG(WARNING) << __func__ << ": pending=" << pending_cmd
                 << " ignore result=" << ctrl_ack;
    return;
  }
  if(ctrl_ack == BluetoothAudioCtrlAck::SUCCESS_FINISHED) {
    is_playing = true;
  }
  if (ctrl_ack != BluetoothAudioCtrlAck::PENDING) {
    if (a2dp_sink_2_1)
      a2dp_sink_2_1->ResetPendingCmd();
    else
      a2dp_sink->ResetPendingCmd();
  }
}

void ack_stream_suspended(const tA2DP_CTRL_ACK& ack) {
  std::unique_lock<std::mutex> guard(internal_mutex_);
  if (!is_hal_2_0_enabled()) {
    LOG(ERROR) << __func__ << ": BluetoothAudio HAL is not enabled";
    return;
  }
  auto ctrl_ack = a2dp_ack_to_bt_audio_ctrl_ack(ack);
  LOG(INFO) << __func__ << ": result=" << ctrl_ack;
  tA2DP_CTRL_CMD pending_cmd = A2DP_CTRL_CMD_NONE;
  if (a2dp_sink_2_1)
    pending_cmd = a2dp_sink_2_1->GetPendingCmd();
  else
    pending_cmd = a2dp_sink->GetPendingCmd();
  if (pending_cmd == A2DP_CTRL_CMD_SUSPEND) {
    a2dp_hal_clientif->StreamSuspended(ctrl_ack);
  } else if (pending_cmd == A2DP_CTRL_CMD_STOP) {
    LOG(INFO) << __func__ << ": A2DP_CTRL_CMD_STOP result=" << ctrl_ack;
  } else {
    LOG(WARNING) << __func__ << ": pending=" << pending_cmd
                 << " ignore result=" << ctrl_ack;
    return;
  }
  if(ctrl_ack == BluetoothAudioCtrlAck::SUCCESS_FINISHED) {
    is_playing = false;
  }
  if (ctrl_ack != BluetoothAudioCtrlAck::PENDING) {
    if (a2dp_sink_2_1)
      a2dp_sink_2_1->ResetPendingCmd();
    else
      a2dp_sink->ResetPendingCmd();
  }
}

// Read from the FMQ of BluetoothAudio HAL
size_t read(uint8_t* p_buf, uint32_t len) {
  std::unique_lock<std::mutex> guard(internal_mutex_);
  if (!is_hal_2_0_enabled()) {
    LOG(ERROR) << __func__ << ": BluetoothAudio HAL is not enabled";
    return 0;
  } else if (session_type != SessionType::A2DP_SOFTWARE_ENCODING_DATAPATH) {
    LOG(ERROR) << __func__ << ": session_type=" << toString(session_type)
               << " is not A2DP_SOFTWARE_ENCODING_DATAPATH";
    return 0;
  }
  return a2dp_hal_clientif->ReadAudioData(p_buf, len);
}

// Update A2DP delay report to BluetoothAudio HAL
void set_remote_delay(uint16_t delay_report) {
  std::unique_lock<std::mutex> guard(internal_mutex_);
  SessionParams session_params{};
  if (!is_hal_2_0_enabled()) {
    LOG(INFO) << __func__ << ":  not ready for DelayReport "
              << static_cast<float>(delay_report / 10.0) << " ms";
    remote_delay = delay_report;
    return;
  }
  LOG(INFO) << __func__ << ": DELAY " << static_cast<float>(delay_report / 10.0)
            << " ms";
  session_params.paramType = SessionParamType::SINK_LATENCY;
  session_params.param.sinkLatency = {delay_report, 0x00, {}};
  if (a2dp_sink_2_1)
    a2dp_sink_2_1->SetRemoteDelay(delay_report);
  else
    a2dp_sink->SetRemoteDelay(delay_report);

  if (is_session_started) {
   a2dp_hal_clientif->updateSessionParams(session_params);
  }

}

bool is_streaming() {
  std::unique_lock<std::mutex> guard(internal_mutex_);
  if (!is_hal_2_0_enabled()) {
    LOG(ERROR) << __func__ << ": BluetoothAudio HAL is not enabled";
    return false;
  }
  return is_playing;
}


SessionType get_session_type() {
  std::unique_lock<std::mutex> guard(internal_mutex_);
  if (!is_hal_2_0_enabled()) {
    LOG(ERROR) << __func__ << ": BluetoothAudio HAL is not enabled";
    return SessionType::UNKNOWN;
  }
  return session_type;
}

}  // namespace a2dp
}  // namespace audio
}  // namespace bluetooth
