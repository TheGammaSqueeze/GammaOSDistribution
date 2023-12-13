#pragma once

#include <array>
#include <binder/Enums.h>
#include <cstdint>
#include <string>

namespace android {

namespace media {

enum class AudioMixLatencyClass : int32_t {
  LOW = 0,
  NORMAL = 1,
};

[[nodiscard]] static inline std::string toString(AudioMixLatencyClass val) {
  switch(val) {
  case AudioMixLatencyClass::LOW:
    return "LOW";
  case AudioMixLatencyClass::NORMAL:
    return "NORMAL";
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
constexpr inline std::array<::android::media::AudioMixLatencyClass, 2> enum_values<::android::media::AudioMixLatencyClass> = {
  ::android::media::AudioMixLatencyClass::LOW,
  ::android::media::AudioMixLatencyClass::NORMAL,
};
#pragma clang diagnostic pop

}  // namespace internal

}  // namespace android
