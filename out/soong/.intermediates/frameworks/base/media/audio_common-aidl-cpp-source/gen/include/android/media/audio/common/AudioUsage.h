#pragma once

#include <array>
#include <binder/Enums.h>
#include <cstdint>
#include <string>

namespace android {

namespace media {

namespace audio {

namespace common {

enum class AudioUsage : int32_t {
  UNKNOWN = 0,
  MEDIA = 1,
  VOICE_COMMUNICATION = 2,
  VOICE_COMMUNICATION_SIGNALLING = 3,
  ALARM = 4,
  NOTIFICATION = 5,
  NOTIFICATION_TELEPHONY_RINGTONE = 6,
  ASSISTANCE_ACCESSIBILITY = 11,
  ASSISTANCE_NAVIGATION_GUIDANCE = 12,
  ASSISTANCE_SONIFICATION = 13,
  GAME = 14,
  VIRTUAL_SOURCE = 15,
  ASSISTANT = 16,
};

[[nodiscard]] static inline std::string toString(AudioUsage val) {
  switch(val) {
  case AudioUsage::UNKNOWN:
    return "UNKNOWN";
  case AudioUsage::MEDIA:
    return "MEDIA";
  case AudioUsage::VOICE_COMMUNICATION:
    return "VOICE_COMMUNICATION";
  case AudioUsage::VOICE_COMMUNICATION_SIGNALLING:
    return "VOICE_COMMUNICATION_SIGNALLING";
  case AudioUsage::ALARM:
    return "ALARM";
  case AudioUsage::NOTIFICATION:
    return "NOTIFICATION";
  case AudioUsage::NOTIFICATION_TELEPHONY_RINGTONE:
    return "NOTIFICATION_TELEPHONY_RINGTONE";
  case AudioUsage::ASSISTANCE_ACCESSIBILITY:
    return "ASSISTANCE_ACCESSIBILITY";
  case AudioUsage::ASSISTANCE_NAVIGATION_GUIDANCE:
    return "ASSISTANCE_NAVIGATION_GUIDANCE";
  case AudioUsage::ASSISTANCE_SONIFICATION:
    return "ASSISTANCE_SONIFICATION";
  case AudioUsage::GAME:
    return "GAME";
  case AudioUsage::VIRTUAL_SOURCE:
    return "VIRTUAL_SOURCE";
  case AudioUsage::ASSISTANT:
    return "ASSISTANT";
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
constexpr inline std::array<::android::media::audio::common::AudioUsage, 13> enum_values<::android::media::audio::common::AudioUsage> = {
  ::android::media::audio::common::AudioUsage::UNKNOWN,
  ::android::media::audio::common::AudioUsage::MEDIA,
  ::android::media::audio::common::AudioUsage::VOICE_COMMUNICATION,
  ::android::media::audio::common::AudioUsage::VOICE_COMMUNICATION_SIGNALLING,
  ::android::media::audio::common::AudioUsage::ALARM,
  ::android::media::audio::common::AudioUsage::NOTIFICATION,
  ::android::media::audio::common::AudioUsage::NOTIFICATION_TELEPHONY_RINGTONE,
  ::android::media::audio::common::AudioUsage::ASSISTANCE_ACCESSIBILITY,
  ::android::media::audio::common::AudioUsage::ASSISTANCE_NAVIGATION_GUIDANCE,
  ::android::media::audio::common::AudioUsage::ASSISTANCE_SONIFICATION,
  ::android::media::audio::common::AudioUsage::GAME,
  ::android::media::audio::common::AudioUsage::VIRTUAL_SOURCE,
  ::android::media::audio::common::AudioUsage::ASSISTANT,
};
#pragma clang diagnostic pop

}  // namespace internal

}  // namespace android
