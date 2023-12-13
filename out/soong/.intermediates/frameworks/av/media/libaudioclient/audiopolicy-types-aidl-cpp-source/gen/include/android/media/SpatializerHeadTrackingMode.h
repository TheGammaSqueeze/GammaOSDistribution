#pragma once

#include <array>
#include <binder/Enums.h>
#include <cstdint>
#include <string>

namespace android {

namespace media {

enum class SpatializerHeadTrackingMode : int8_t {
  OTHER = 0,
  DISABLED = 1,
  RELATIVE_WORLD = 2,
  RELATIVE_SCREEN = 3,
};

[[nodiscard]] static inline std::string toString(SpatializerHeadTrackingMode val) {
  switch(val) {
  case SpatializerHeadTrackingMode::OTHER:
    return "OTHER";
  case SpatializerHeadTrackingMode::DISABLED:
    return "DISABLED";
  case SpatializerHeadTrackingMode::RELATIVE_WORLD:
    return "RELATIVE_WORLD";
  case SpatializerHeadTrackingMode::RELATIVE_SCREEN:
    return "RELATIVE_SCREEN";
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
constexpr inline std::array<::android::media::SpatializerHeadTrackingMode, 4> enum_values<::android::media::SpatializerHeadTrackingMode> = {
  ::android::media::SpatializerHeadTrackingMode::OTHER,
  ::android::media::SpatializerHeadTrackingMode::DISABLED,
  ::android::media::SpatializerHeadTrackingMode::RELATIVE_WORLD,
  ::android::media::SpatializerHeadTrackingMode::RELATIVE_SCREEN,
};
#pragma clang diagnostic pop

}  // namespace internal

}  // namespace android
