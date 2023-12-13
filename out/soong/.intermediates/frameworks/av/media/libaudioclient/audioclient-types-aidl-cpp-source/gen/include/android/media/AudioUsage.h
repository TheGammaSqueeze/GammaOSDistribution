#pragma once

#include <array>
#include <binder/Enums.h>
#include <cstdint>
#include <string>

namespace android {

namespace media {

enum class AudioUsage : int32_t {
  UNKNOWN = 0,
  MEDIA = 1,
  VOICE_COMMUNICATION = 2,
  VOICE_COMMUNICATION_SIGNALLING = 3,
  ALARM = 4,
  NOTIFICATION = 5,
  NOTIFICATION_TELEPHONY_RINGTONE = 6,
  NOTIFICATION_COMMUNICATION_REQUEST = 7,
  NOTIFICATION_COMMUNICATION_INSTANT = 8,
  NOTIFICATION_COMMUNICATION_DELAYED = 9,
  NOTIFICATION_EVENT = 10,
  ASSISTANCE_ACCESSIBILITY = 11,
  ASSISTANCE_NAVIGATION_GUIDANCE = 12,
  ASSISTANCE_SONIFICATION = 13,
  GAME = 14,
  VIRTUAL_SOURCE = 15,
  ASSISTANT = 16,
  CALL_ASSISTANT = 17,
  EMERGENCY = 1000,
  SAFETY = 1001,
  VEHICLE_STATUS = 1002,
  ANNOUNCEMENT = 1003,
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
  case AudioUsage::NOTIFICATION_COMMUNICATION_REQUEST:
    return "NOTIFICATION_COMMUNICATION_REQUEST";
  case AudioUsage::NOTIFICATION_COMMUNICATION_INSTANT:
    return "NOTIFICATION_COMMUNICATION_INSTANT";
  case AudioUsage::NOTIFICATION_COMMUNICATION_DELAYED:
    return "NOTIFICATION_COMMUNICATION_DELAYED";
  case AudioUsage::NOTIFICATION_EVENT:
    return "NOTIFICATION_EVENT";
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
  case AudioUsage::CALL_ASSISTANT:
    return "CALL_ASSISTANT";
  case AudioUsage::EMERGENCY:
    return "EMERGENCY";
  case AudioUsage::SAFETY:
    return "SAFETY";
  case AudioUsage::VEHICLE_STATUS:
    return "VEHICLE_STATUS";
  case AudioUsage::ANNOUNCEMENT:
    return "ANNOUNCEMENT";
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
constexpr inline std::array<::android::media::AudioUsage, 22> enum_values<::android::media::AudioUsage> = {
  ::android::media::AudioUsage::UNKNOWN,
  ::android::media::AudioUsage::MEDIA,
  ::android::media::AudioUsage::VOICE_COMMUNICATION,
  ::android::media::AudioUsage::VOICE_COMMUNICATION_SIGNALLING,
  ::android::media::AudioUsage::ALARM,
  ::android::media::AudioUsage::NOTIFICATION,
  ::android::media::AudioUsage::NOTIFICATION_TELEPHONY_RINGTONE,
  ::android::media::AudioUsage::NOTIFICATION_COMMUNICATION_REQUEST,
  ::android::media::AudioUsage::NOTIFICATION_COMMUNICATION_INSTANT,
  ::android::media::AudioUsage::NOTIFICATION_COMMUNICATION_DELAYED,
  ::android::media::AudioUsage::NOTIFICATION_EVENT,
  ::android::media::AudioUsage::ASSISTANCE_ACCESSIBILITY,
  ::android::media::AudioUsage::ASSISTANCE_NAVIGATION_GUIDANCE,
  ::android::media::AudioUsage::ASSISTANCE_SONIFICATION,
  ::android::media::AudioUsage::GAME,
  ::android::media::AudioUsage::VIRTUAL_SOURCE,
  ::android::media::AudioUsage::ASSISTANT,
  ::android::media::AudioUsage::CALL_ASSISTANT,
  ::android::media::AudioUsage::EMERGENCY,
  ::android::media::AudioUsage::SAFETY,
  ::android::media::AudioUsage::VEHICLE_STATUS,
  ::android::media::AudioUsage::ANNOUNCEMENT,
};
#pragma clang diagnostic pop

}  // namespace internal

}  // namespace android
