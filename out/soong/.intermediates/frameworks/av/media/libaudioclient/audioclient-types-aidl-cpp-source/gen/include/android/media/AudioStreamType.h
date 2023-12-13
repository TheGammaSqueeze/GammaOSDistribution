#pragma once

#include <array>
#include <binder/Enums.h>
#include <cstdint>
#include <string>

namespace android {

namespace media {

enum class AudioStreamType : int32_t {
  DEFAULT = -1,
  VOICE_CALL = 0,
  SYSTEM = 1,
  RING = 2,
  MUSIC = 3,
  ALARM = 4,
  NOTIFICATION = 5,
  BLUETOOTH_SCO = 6,
  ENFORCED_AUDIBLE = 7,
  DTMF = 8,
  TTS = 9,
  ACCESSIBILITY = 10,
  ASSISTANT = 11,
  REROUTING = 12,
  PATCH = 13,
  CALL_ASSISTANT = 14,
};

[[nodiscard]] static inline std::string toString(AudioStreamType val) {
  switch(val) {
  case AudioStreamType::DEFAULT:
    return "DEFAULT";
  case AudioStreamType::VOICE_CALL:
    return "VOICE_CALL";
  case AudioStreamType::SYSTEM:
    return "SYSTEM";
  case AudioStreamType::RING:
    return "RING";
  case AudioStreamType::MUSIC:
    return "MUSIC";
  case AudioStreamType::ALARM:
    return "ALARM";
  case AudioStreamType::NOTIFICATION:
    return "NOTIFICATION";
  case AudioStreamType::BLUETOOTH_SCO:
    return "BLUETOOTH_SCO";
  case AudioStreamType::ENFORCED_AUDIBLE:
    return "ENFORCED_AUDIBLE";
  case AudioStreamType::DTMF:
    return "DTMF";
  case AudioStreamType::TTS:
    return "TTS";
  case AudioStreamType::ACCESSIBILITY:
    return "ACCESSIBILITY";
  case AudioStreamType::ASSISTANT:
    return "ASSISTANT";
  case AudioStreamType::REROUTING:
    return "REROUTING";
  case AudioStreamType::PATCH:
    return "PATCH";
  case AudioStreamType::CALL_ASSISTANT:
    return "CALL_ASSISTANT";
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
constexpr inline std::array<::android::media::AudioStreamType, 16> enum_values<::android::media::AudioStreamType> = {
  ::android::media::AudioStreamType::DEFAULT,
  ::android::media::AudioStreamType::VOICE_CALL,
  ::android::media::AudioStreamType::SYSTEM,
  ::android::media::AudioStreamType::RING,
  ::android::media::AudioStreamType::MUSIC,
  ::android::media::AudioStreamType::ALARM,
  ::android::media::AudioStreamType::NOTIFICATION,
  ::android::media::AudioStreamType::BLUETOOTH_SCO,
  ::android::media::AudioStreamType::ENFORCED_AUDIBLE,
  ::android::media::AudioStreamType::DTMF,
  ::android::media::AudioStreamType::TTS,
  ::android::media::AudioStreamType::ACCESSIBILITY,
  ::android::media::AudioStreamType::ASSISTANT,
  ::android::media::AudioStreamType::REROUTING,
  ::android::media::AudioStreamType::PATCH,
  ::android::media::AudioStreamType::CALL_ASSISTANT,
};
#pragma clang diagnostic pop

}  // namespace internal

}  // namespace android
