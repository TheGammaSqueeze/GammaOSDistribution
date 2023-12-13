#pragma once

#include <array>
#include <binder/Enums.h>
#include <cstdint>
#include <string>

namespace android {

namespace media {

enum class AudioOffloadMode : int32_t {
  NOT_SUPPORTED = 0,
  SUPPORTED = 1,
  GAPLESS_SUPPORTED = 2,
};

[[nodiscard]] static inline std::string toString(AudioOffloadMode val) {
  switch(val) {
  case AudioOffloadMode::NOT_SUPPORTED:
    return "NOT_SUPPORTED";
  case AudioOffloadMode::SUPPORTED:
    return "SUPPORTED";
  case AudioOffloadMode::GAPLESS_SUPPORTED:
    return "GAPLESS_SUPPORTED";
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
constexpr inline std::array<::android::media::AudioOffloadMode, 3> enum_values<::android::media::AudioOffloadMode> = {
  ::android::media::AudioOffloadMode::NOT_SUPPORTED,
  ::android::media::AudioOffloadMode::SUPPORTED,
  ::android::media::AudioOffloadMode::GAPLESS_SUPPORTED,
};
#pragma clang diagnostic pop

}  // namespace internal

}  // namespace android
