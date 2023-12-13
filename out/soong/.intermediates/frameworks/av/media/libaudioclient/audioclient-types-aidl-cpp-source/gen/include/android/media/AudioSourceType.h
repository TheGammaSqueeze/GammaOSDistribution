#pragma once

#include <array>
#include <binder/Enums.h>
#include <cstdint>
#include <string>

namespace android {

namespace media {

enum class AudioSourceType : int32_t {
  INVALID = -1,
  DEFAULT = 0,
  MIC = 1,
  VOICE_UPLINK = 2,
  VOICE_DOWNLINK = 3,
  VOICE_CALL = 4,
  CAMCORDER = 5,
  VOICE_RECOGNITION = 6,
  VOICE_COMMUNICATION = 7,
  REMOTE_SUBMIX = 8,
  UNPROCESSED = 9,
  VOICE_PERFORMANCE = 10,
  ECHO_REFERENCE = 1997,
  FM_TUNER = 1998,
  HOTWORD = 1999,
};

[[nodiscard]] static inline std::string toString(AudioSourceType val) {
  switch(val) {
  case AudioSourceType::INVALID:
    return "INVALID";
  case AudioSourceType::DEFAULT:
    return "DEFAULT";
  case AudioSourceType::MIC:
    return "MIC";
  case AudioSourceType::VOICE_UPLINK:
    return "VOICE_UPLINK";
  case AudioSourceType::VOICE_DOWNLINK:
    return "VOICE_DOWNLINK";
  case AudioSourceType::VOICE_CALL:
    return "VOICE_CALL";
  case AudioSourceType::CAMCORDER:
    return "CAMCORDER";
  case AudioSourceType::VOICE_RECOGNITION:
    return "VOICE_RECOGNITION";
  case AudioSourceType::VOICE_COMMUNICATION:
    return "VOICE_COMMUNICATION";
  case AudioSourceType::REMOTE_SUBMIX:
    return "REMOTE_SUBMIX";
  case AudioSourceType::UNPROCESSED:
    return "UNPROCESSED";
  case AudioSourceType::VOICE_PERFORMANCE:
    return "VOICE_PERFORMANCE";
  case AudioSourceType::ECHO_REFERENCE:
    return "ECHO_REFERENCE";
  case AudioSourceType::FM_TUNER:
    return "FM_TUNER";
  case AudioSourceType::HOTWORD:
    return "HOTWORD";
  default:
    return std::to_string(static_cast<int32_t>(val));
  }
}

}  // namespace media

}  // namespace android
namespace android {

namespace internal {

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wc++17-extensions"
template <>
constexpr inline std::array<::android::media::AudioSourceType, 15> enum_values<::android::media::AudioSourceType> = {
  ::android::media::AudioSourceType::INVALID,
  ::android::media::AudioSourceType::DEFAULT,
  ::android::media::AudioSourceType::MIC,
  ::android::media::AudioSourceType::VOICE_UPLINK,
  ::android::media::AudioSourceType::VOICE_DOWNLINK,
  ::android::media::AudioSourceType::VOICE_CALL,
  ::android::media::AudioSourceType::CAMCORDER,
  ::android::media::AudioSourceType::VOICE_RECOGNITION,
  ::android::media::AudioSourceType::VOICE_COMMUNICATION,
  ::android::media::AudioSourceType::REMOTE_SUBMIX,
  ::android::media::AudioSourceType::UNPROCESSED,
  ::android::media::AudioSourceType::VOICE_PERFORMANCE,
  ::android::media::AudioSourceType::ECHO_REFERENCE,
  ::android::media::AudioSourceType::FM_TUNER,
  ::android::media::AudioSourceType::HOTWORD,
};
#pragma clang diagnostic pop

}  // namespace internal

}  // namespace android
