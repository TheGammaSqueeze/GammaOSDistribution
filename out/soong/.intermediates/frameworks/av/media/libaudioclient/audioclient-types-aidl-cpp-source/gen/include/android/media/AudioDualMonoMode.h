#pragma once

#include <array>
#include <binder/Enums.h>
#include <cstdint>
#include <string>

namespace android {

namespace media {

enum class AudioDualMonoMode : int32_t {
  OFF = 0,
  LR = 1,
  LL = 2,
  RR = 3,
};

[[nodiscard]] static inline std::string toString(AudioDualMonoMode val) {
  switch(val) {
  case AudioDualMonoMode::OFF:
    return "OFF";
  case AudioDualMonoMode::LR:
    return "LR";
  case AudioDualMonoMode::LL:
    return "LL";
  case AudioDualMonoMode::RR:
    return "RR";
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
constexpr inline std::array<::android::media::AudioDualMonoMode, 4> enum_values<::android::media::AudioDualMonoMode> = {
  ::android::media::AudioDualMonoMode::OFF,
  ::android::media::AudioDualMonoMode::LR,
  ::android::media::AudioDualMonoMode::LL,
  ::android::media::AudioDualMonoMode::RR,
};
#pragma clang diagnostic pop

}  // namespace internal

}  // namespace android
