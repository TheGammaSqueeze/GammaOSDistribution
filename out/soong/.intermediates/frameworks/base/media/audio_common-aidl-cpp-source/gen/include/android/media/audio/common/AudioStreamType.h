#pragma once

#include <array>
#include <binder/Enums.h>
#include <cstdint>
#include <string>

namespace android {

namespace media {

namespace audio {

namespace common {

enum class AudioStreamType : int32_t {
  DEFAULT = -1,
  MIN = 0,
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
};

[[nodiscard]] static inline std::string toString(AudioStreamType val) {
  switch(val) {
  case AudioStreamType::DEFAULT:
    return "DEFAULT";
  case AudioStreamType::MIN:
    return "MIN";
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
  default:
    return std::to_string(static_cast<int32_t>(val));
  }
}

}  // namespace common

}  // namespace audio

}  // namespace media

}  // namespace android
namespace android {

namespace internal {

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wc++17-extensions"
template <>
constexpr inline std::array<::android::media::audio::common::AudioStreamType, 13> enum_values<::android::media::audio::common::AudioStreamType> = {
  ::android::media::audio::common::AudioStreamType::DEFAULT,
  ::android::media::audio::common::AudioStreamType::MIN,
  ::android::media::audio::common::AudioStreamType::VOICE_CALL,
  ::android::media::audio::common::AudioStreamType::SYSTEM,
  ::android::media::audio::common::AudioStreamType::RING,
  ::android::media::audio::common::AudioStreamType::MUSIC,
  ::android::media::audio::common::AudioStreamType::ALARM,
  ::android::media::audio::common::AudioStreamType::NOTIFICATION,
  ::android::media::audio::common::AudioStreamType::BLUETOOTH_SCO,
  ::android::media::audio::common::AudioStreamType::ENFORCED_AUDIBLE,
  ::android::media::audio::common::AudioStreamType::DTMF,
  ::android::media::audio::common::AudioStreamType::TTS,
  ::android::media::audio::common::AudioStreamType::ACCESSIBILITY,
};
#pragma clang diagnostic pop

}  // namespace internal

}  // namespace android
