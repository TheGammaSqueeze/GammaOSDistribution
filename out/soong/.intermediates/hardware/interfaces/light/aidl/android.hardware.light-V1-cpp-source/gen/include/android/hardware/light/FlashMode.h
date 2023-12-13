#pragma once

#include <array>
#include <binder/Enums.h>
#include <cstdint>
#include <string>

namespace android {

namespace hardware {

namespace light {

enum class FlashMode : int8_t {
  NONE = 0,
  TIMED = 1,
  HARDWARE = 2,
};

[[nodiscard]] static inline std::string toString(FlashMode val) {
  switch(val) {
  case FlashMode::NONE:
    return "NONE";
  case FlashMode::TIMED:
    return "TIMED";
  case FlashMode::HARDWARE:
    return "HARDWARE";
  default:
    return std::to_string(static_cast<int8_t>(val));
  }
}

}  // namespace light

}  // namespace hardware

}  // namespace android
namespace android {

namespace internal {

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wc++17-extensions"
template <>
constexpr inline std::array<::android::hardware::light::FlashMode, 3> enum_values<::android::hardware::light::FlashMode> = {
  ::android::hardware::light::FlashMode::NONE,
  ::android::hardware::light::FlashMode::TIMED,
  ::android::hardware::light::FlashMode::HARDWARE,
};
#pragma clang diagnostic pop

}  // namespace internal

}  // namespace android
