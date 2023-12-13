#pragma once

#include <array>
#include <binder/Enums.h>
#include <cstdint>
#include <string>

namespace android {

namespace media {

enum class AudioMixCallbackFlag : int32_t {
  NOTIFY_ACTIVITY = 0,
};

[[nodiscard]] static inline std::string toString(AudioMixCallbackFlag val) {
  switch(val) {
  case AudioMixCallbackFlag::NOTIFY_ACTIVITY:
    return "NOTIFY_ACTIVITY";
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
constexpr inline std::array<::android::media::AudioMixCallbackFlag, 1> enum_values<::android::media::AudioMixCallbackFlag> = {
  ::android::media::AudioMixCallbackFlag::NOTIFY_ACTIVITY,
};
#pragma clang diagnostic pop

}  // namespace internal

}  // namespace android
