#pragma once

#include <array>
#include <binder/Enums.h>
#include <cstdint>
#include <string>

namespace android {

namespace media {

enum class SpatializationMode : int8_t {
  SPATIALIZATER_BINAURAL = 0,
  SPATIALIZATER_TRANSAURAL = 1,
};

[[nodiscard]] static inline std::string toString(SpatializationMode val) {
  switch(val) {
  case SpatializationMode::SPATIALIZATER_BINAURAL:
    return "SPATIALIZATER_BINAURAL";
  case SpatializationMode::SPATIALIZATER_TRANSAURAL:
    return "SPATIALIZATER_TRANSAURAL";
  default:
    return std::to_string(static_cast<int8_t>(val));
  }
}

}  // namespace media

}  // namespace android
namespace android {

namespace internal {

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wc++17-extensions"
template <>
constexpr inline std::array<::android::media::SpatializationMode, 2> enum_values<::android::media::SpatializationMode> = {
  ::android::media::SpatializationMode::SPATIALIZATER_BINAURAL,
  ::android::media::SpatializationMode::SPATIALIZATER_TRANSAURAL,
};
#pragma clang diagnostic pop

}  // namespace internal

}  // namespace android
