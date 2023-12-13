#pragma once

#include <array>
#include <binder/Enums.h>
#include <cstdint>
#include <string>

namespace android {

namespace media {

enum class AudioPolicyDeviceState : int32_t {
  UNAVAILABLE = 0,
  AVAILABLE = 1,
};

[[nodiscard]] static inline std::string toString(AudioPolicyDeviceState val) {
  switch(val) {
  case AudioPolicyDeviceState::UNAVAILABLE:
    return "UNAVAILABLE";
  case AudioPolicyDeviceState::AVAILABLE:
    return "AVAILABLE";
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
constexpr inline std::array<::android::media::AudioPolicyDeviceState, 2> enum_values<::android::media::AudioPolicyDeviceState> = {
  ::android::media::AudioPolicyDeviceState::UNAVAILABLE,
  ::android::media::AudioPolicyDeviceState::AVAILABLE,
};
#pragma clang diagnostic pop

}  // namespace internal

}  // namespace android
