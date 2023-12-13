#pragma once

#include <array>
#include <binder/Enums.h>
#include <cstdint>
#include <string>

namespace android {

namespace media {

enum class AudioMode : int32_t {
  INVALID = -2,
  CURRENT = -1,
  NORMAL = 0,
  RINGTONE = 1,
  IN_CALL = 2,
  IN_COMMUNICATION = 3,
  CALL_SCREEN = 4,
};

[[nodiscard]] static inline std::string toString(AudioMode val) {
  switch(val) {
  case AudioMode::INVALID:
    return "INVALID";
  case AudioMode::CURRENT:
    return "CURRENT";
  case AudioMode::NORMAL:
    return "NORMAL";
  case AudioMode::RINGTONE:
    return "RINGTONE";
  case AudioMode::IN_CALL:
    return "IN_CALL";
  case AudioMode::IN_COMMUNICATION:
    return "IN_COMMUNICATION";
  case AudioMode::CALL_SCREEN:
    return "CALL_SCREEN";
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
constexpr inline std::array<::android::media::AudioMode, 7> enum_values<::android::media::AudioMode> = {
  ::android::media::AudioMode::INVALID,
  ::android::media::AudioMode::CURRENT,
  ::android::media::AudioMode::NORMAL,
  ::android::media::AudioMode::RINGTONE,
  ::android::media::AudioMode::IN_CALL,
  ::android::media::AudioMode::IN_COMMUNICATION,
  ::android::media::AudioMode::CALL_SCREEN,
};
#pragma clang diagnostic pop

}  // namespace internal

}  // namespace android
