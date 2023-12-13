#pragma once

#include <array>
#include <binder/Enums.h>
#include <cstdint>
#include <string>

namespace android {

namespace media {

enum class AudioFlag : int32_t {
  AUDIBILITY_ENFORCED = 0,
  SECURE = 1,
  SCO = 2,
  BEACON = 3,
  HW_AV_SYNC = 4,
  HW_HOTWORD = 5,
  BYPASS_INTERRUPTION_POLICY = 6,
  BYPASS_MUTE = 7,
  LOW_LATENCY = 8,
  DEEP_BUFFER = 9,
  NO_MEDIA_PROJECTION = 10,
  MUTE_HAPTIC = 11,
  NO_SYSTEM_CAPTURE = 12,
  CAPTURE_PRIVATE = 13,
  CONTENT_SPATIALIZED = 14,
  NEVER_SPATIALIZE = 15,
};

[[nodiscard]] static inline std::string toString(AudioFlag val) {
  switch(val) {
  case AudioFlag::AUDIBILITY_ENFORCED:
    return "AUDIBILITY_ENFORCED";
  case AudioFlag::SECURE:
    return "SECURE";
  case AudioFlag::SCO:
    return "SCO";
  case AudioFlag::BEACON:
    return "BEACON";
  case AudioFlag::HW_AV_SYNC:
    return "HW_AV_SYNC";
  case AudioFlag::HW_HOTWORD:
    return "HW_HOTWORD";
  case AudioFlag::BYPASS_INTERRUPTION_POLICY:
    return "BYPASS_INTERRUPTION_POLICY";
  case AudioFlag::BYPASS_MUTE:
    return "BYPASS_MUTE";
  case AudioFlag::LOW_LATENCY:
    return "LOW_LATENCY";
  case AudioFlag::DEEP_BUFFER:
    return "DEEP_BUFFER";
  case AudioFlag::NO_MEDIA_PROJECTION:
    return "NO_MEDIA_PROJECTION";
  case AudioFlag::MUTE_HAPTIC:
    return "MUTE_HAPTIC";
  case AudioFlag::NO_SYSTEM_CAPTURE:
    return "NO_SYSTEM_CAPTURE";
  case AudioFlag::CAPTURE_PRIVATE:
    return "CAPTURE_PRIVATE";
  case AudioFlag::CONTENT_SPATIALIZED:
    return "CONTENT_SPATIALIZED";
  case AudioFlag::NEVER_SPATIALIZE:
    return "NEVER_SPATIALIZE";
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
constexpr inline std::array<::android::media::AudioFlag, 16> enum_values<::android::media::AudioFlag> = {
  ::android::media::AudioFlag::AUDIBILITY_ENFORCED,
  ::android::media::AudioFlag::SECURE,
  ::android::media::AudioFlag::SCO,
  ::android::media::AudioFlag::BEACON,
  ::android::media::AudioFlag::HW_AV_SYNC,
  ::android::media::AudioFlag::HW_HOTWORD,
  ::android::media::AudioFlag::BYPASS_INTERRUPTION_POLICY,
  ::android::media::AudioFlag::BYPASS_MUTE,
  ::android::media::AudioFlag::LOW_LATENCY,
  ::android::media::AudioFlag::DEEP_BUFFER,
  ::android::media::AudioFlag::NO_MEDIA_PROJECTION,
  ::android::media::AudioFlag::MUTE_HAPTIC,
  ::android::media::AudioFlag::NO_SYSTEM_CAPTURE,
  ::android::media::AudioFlag::CAPTURE_PRIVATE,
  ::android::media::AudioFlag::CONTENT_SPATIALIZED,
  ::android::media::AudioFlag::NEVER_SPATIALIZE,
};
#pragma clang diagnostic pop

}  // namespace internal

}  // namespace android
