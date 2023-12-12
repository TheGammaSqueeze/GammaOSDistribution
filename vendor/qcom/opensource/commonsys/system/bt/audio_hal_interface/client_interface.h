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

#pragma once

#include <time.h>
#include <mutex>

#include <vendor/qti/hardware/bluetooth_audio/2.0/IBluetoothAudioProvider.h>
#include <vendor/qti/hardware/bluetooth_audio/2.0/types.h>
#include <vendor/qti/hardware/bluetooth_audio/2.1/IBluetoothAudioProvider.h>
#include <vendor/qti/hardware/bluetooth_audio/2.1/types.h>
#include <fmq/MessageQueue.h>
#include <hardware/audio.h>
#include "osi/include/thread.h"

#define BLUETOOTH_AUDIO_PROP_ENABLED \
  "persist.bluetooth.bluetooth_audio_hal.enabled"

namespace bluetooth {
namespace audio {

using audioCapabilities =
      vendor::qti::hardware::bluetooth_audio::V2_0::AudioCapabilities;
using audioCapabilities_2_1 =
      vendor::qti::hardware::bluetooth_audio::V2_1::AudioCapabilities;
using AudioConfiguration =
      vendor::qti::hardware::bluetooth_audio::V2_0::AudioConfiguration;
using AudioConfiguration_2_1 =
      vendor::qti::hardware::bluetooth_audio::V2_1::AudioConfiguration;
using vendor::qti::hardware::bluetooth_audio::V2_0::BitsPerSample;
using vendor::qti::hardware::bluetooth_audio::V2_0::ChannelMode;
using CodecConfiguration =
      vendor::qti::hardware::bluetooth_audio::V2_0::CodecConfiguration;
using CodecConfiguration_2_1 =
      vendor::qti::hardware::bluetooth_audio::V2_1::CodecConfiguration;
using CodecType = vendor::qti::hardware::bluetooth_audio::V2_0::CodecType;
using CodecType_2_1 = vendor::qti::hardware::bluetooth_audio::V2_1::CodecType;
using BluetoothAudioProvider =
      vendor::qti::hardware::bluetooth_audio::V2_0::IBluetoothAudioProvider;
using BluetoothAudioProvider_2_1 =
      vendor::qti::hardware::bluetooth_audio::V2_1::IBluetoothAudioProvider;
using vendor::qti::hardware::bluetooth_audio::V2_0::PcmParameters;
using vendor::qti::hardware::bluetooth_audio::V2_0::SampleRate;
using vendor::qti::hardware::bluetooth_audio::V2_0::SessionType;
using vendor::qti::hardware::bluetooth_audio::V2_0::TimeSpec;
using BluetoothAudioPort =
      vendor::qti::hardware::bluetooth_audio::V2_0::IBluetoothAudioPort;
using BluetoothAudioPort_2_1 =
      vendor::qti::hardware::bluetooth_audio::V2_1::IBluetoothAudioPort;
using vendor::qti::hardware::bluetooth_audio::V2_0::SessionParams;
using BluetoothAudioStatus =
    vendor::qti::hardware::bluetooth_audio::V2_0::Status;

enum class BluetoothAudioCtrlAck : uint8_t {
  SUCCESS_FINISHED = 0,
  PENDING,
  FAILURE_UNSUPPORTED,
  FAILURE_BUSY,
  FAILURE_DISCONNECTING,
  FAILURE,
  FAILURE_LONG_WAIT
};

std::ostream& operator<<(std::ostream& os, const BluetoothAudioCtrlAck& ack);

inline BluetoothAudioStatus BluetoothAudioCtrlAckToHalStatus(
    const BluetoothAudioCtrlAck& ack) {
  switch (ack) {
    case BluetoothAudioCtrlAck::SUCCESS_FINISHED:
      return BluetoothAudioStatus::SUCCESS;
    case BluetoothAudioCtrlAck::FAILURE_UNSUPPORTED:
      return BluetoothAudioStatus::UNSUPPORTED_CODEC_CONFIGURATION;
    case BluetoothAudioCtrlAck::PENDING:
      return BluetoothAudioStatus::SINK_NOT_READY;
    case BluetoothAudioCtrlAck::FAILURE_BUSY:
      return BluetoothAudioStatus::CALL_IN_PROGRESS;
    case BluetoothAudioCtrlAck::FAILURE_DISCONNECTING:
      return BluetoothAudioStatus::FAILURE_DISC_IN_PROGRESS;
    case BluetoothAudioCtrlAck::FAILURE_LONG_WAIT:
      return BluetoothAudioStatus::LW_ERROR;
    default:
      return BluetoothAudioStatus::FAILURE;
  }
}

// An IBluetoothTransportInstance needs to be implemented by a Bluetooth audio
// transport, such as A2DP or Hearing Aid, to handle callbacks from Audio HAL.
class IBluetoothTransportInstance {
 public:
  IBluetoothTransportInstance(SessionType sessionType,
                              AudioConfiguration audioConfig)
      : session_type_(sessionType), audio_config_(std::move(audioConfig)){};
  virtual ~IBluetoothTransportInstance() = default;

  SessionType GetSessionType() const { return session_type_; }

  AudioConfiguration GetAudioConfiguration() const { return audio_config_; }

  void UpdateAudioConfiguration(const AudioConfiguration& audio_config) {
    audio_config_ = audio_config;
  }

  void UpdateSessionType( SessionType& sessionType) {
    session_type_ = sessionType;
  }

  bool IsActvie() {
    return session_type_ != SessionType::UNKNOWN;
  }

  virtual BluetoothAudioCtrlAck StartRequest() = 0;

  virtual BluetoothAudioCtrlAck SuspendRequest() = 0;

  virtual void StopRequest() = 0;

  virtual bool GetPresentationPosition(uint64_t* remote_delay_report_ns,
                                       uint64_t* total_bytes_readed,
                                       timespec* data_position) = 0;

  // Invoked when the transport is requested to reset presentation position
  virtual void ResetPresentationPosition() = 0;

  // Invoked when the transport is requested to log bytes read
  virtual void LogBytesRead(size_t bytes_readed) = 0;

 private:
  SessionType session_type_;
  AudioConfiguration audio_config_;
};
class IBluetoothTransportInstance_2_1 {
 public:
  IBluetoothTransportInstance_2_1(SessionType sessionType,
                              AudioConfiguration_2_1 audioConfig)
      : session_type_(sessionType), audio_config_2_1_(std::move(audioConfig)) {};

  virtual ~IBluetoothTransportInstance_2_1() = default;

  SessionType GetSessionType() const { return session_type_; }

  AudioConfiguration_2_1 GetAudioConfiguration() const { return audio_config_2_1_; }

  //AudioConfiguration_2_1 GetAudioConfiguration_2_1() const { return audio_config_2_1_; }

  void UpdateAudioConfiguration(const AudioConfiguration_2_1& audio_config) {
    audio_config_2_1_ = audio_config;
  }
  void UpdateSessionType( SessionType& sessionType) {
    session_type_ = sessionType;
  }

  bool IsActvie() {
    return session_type_ != SessionType::UNKNOWN;
  }

  virtual BluetoothAudioCtrlAck StartRequest() = 0;

  virtual BluetoothAudioCtrlAck SuspendRequest() = 0;

  virtual void StopRequest() = 0;

  virtual bool GetPresentationPosition(uint64_t* remote_delay_report_ns,
                                       uint64_t* total_bytes_readed,
                                       timespec* data_position) = 0;

  // Invoked when the transport is requested to reset presentation position
  virtual void ResetPresentationPosition() = 0;

  // Invoked when the transport is requested to log bytes read
  virtual void LogBytesRead(size_t bytes_readed) = 0;

 private:
  SessionType session_type_;
  AudioConfiguration_2_1 audio_config_2_1_;
};

// common object is shared between different kind of SessionType
class BluetoothAudioDeathRecipient;

// The client interface connects an IBluetoothTransportInstance to
// IBluetoothAudioProvider and helps to route callbacks to
// IBluetoothTransportInstance
class BluetoothAudioClientInterface {
 public:
  // Constructs an BluetoothAudioClientInterface to communicate to
  // BluetoothAudio HAL. |sink| is the implementation for the transport, and
  // |message_loop| is the thread where callbacks are invoked.
  BluetoothAudioClientInterface(
      IBluetoothTransportInstance* sink,
       thread_t* message_loop, std::mutex* mutex);
  BluetoothAudioClientInterface(
      IBluetoothTransportInstance_2_1* sink,
       thread_t* message_loop, std::mutex* mutex);
  //BluetoothAudioClientInterface();
  ~BluetoothAudioClientInterface() = default;
  std::vector<audioCapabilities> GetAudioCapabilities() const;

  std::vector<audioCapabilities_2_1> GetAudioCapabilities_2_1() const;

  android::sp<BluetoothAudioProvider> GetProvider();

  android::sp<BluetoothAudioProvider_2_1> GetProvider_2_1();

  std::mutex* GetExternalMutex();

  const char* GetHalVersion();

  bool UpdateAudioConfig(const AudioConfiguration& audioConfig);

  bool UpdateAudioConfig_2_1(const AudioConfiguration_2_1& audioConfig);

  int StartSession();

  void StreamStarted(const BluetoothAudioCtrlAck& ack);

  void updateSessionParams(const SessionParams& sessionParams);

  void StreamSuspended(const BluetoothAudioCtrlAck& ack);

  void UpdateDeathHandlerThread(thread_t* message_loop);

  int EndSession();

  // Read data from audio  HAL through fmq
  size_t ReadAudioData(uint8_t* p_buf, uint32_t len);

  // Write data to audio HAL through fmq
  size_t WriteAudioData(uint8_t* p_buf, uint32_t len);

  // Renew the connection and usually is used when HIDL restarted
  void RenewAudioProviderAndSession();

  static constexpr PcmParameters kInvalidPcmConfiguration = {
      .sampleRate = SampleRate::RATE_UNKNOWN,
      .bitsPerSample = BitsPerSample::BITS_UNKNOWN,
      .channelMode = ChannelMode::UNKNOWN};

 private:
  // Helper function to connect to an IBluetoothAudioProvider
  void fetch_audio_provider();

  IBluetoothTransportInstance* sink_;
  IBluetoothTransportInstance_2_1* sink_2_1_;
  android::sp<BluetoothAudioProvider> provider_;
  android::sp<BluetoothAudioProvider_2_1> provider_2_1_;
  android::sp<BluetoothAudioPort> stack_if_;
  android::sp<BluetoothAudioPort_2_1>stack_if_2_1_;
  std::vector<audioCapabilities> capabilities_;
  std::vector<audioCapabilities_2_1> capabilities_2_1_;
  bool session_started_;
  std::unique_ptr<::android::hardware::MessageQueue<
      uint8_t, ::android::hardware::kSynchronizedReadWrite>>
      mDataMQ;
  mutable std::mutex *external_mutex_;
  android::sp<BluetoothAudioDeathRecipient> death_recipient_;
};

}  // namespace audio
}  // namespace bluetooth
