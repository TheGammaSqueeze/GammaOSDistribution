#pragma once

#include <array>
#include <binder/Enums.h>
#include <cstdint>
#include <string>

namespace android {

namespace media {

enum class AudioGainMode : int32_t {
  JOINT = 0,
  CHANNELS = 1,
  RAMP = 2,
};

[[nodiscard]] static inline std::string toString(AudioGainMode val) {
  switch(val) {
  case AudioGainMode::JOINT:
    return "JOINT";
  case AudioGainMode::CHANNELS:
    return "CHANNELS";
  case AudioGainMode::RAMP:
    return "RAMP";
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
constexpr inline std::array<::android::media::AudioGainMode, 3> enum_values<::android::media::AudioGainMode> = {
  ::android::media::AudioGainMode::JOINT,
  ::android::media::AudioGainMode::CHANNELS,
  ::android::media::AudioGainMode::RAMP,
};
#pragma clang diagnostic pop

}  // namespace internal

}  // namespace android
