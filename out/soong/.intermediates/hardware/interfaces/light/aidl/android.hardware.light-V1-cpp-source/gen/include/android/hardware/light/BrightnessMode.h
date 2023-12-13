#pragma once

#include <array>
#include <binder/Enums.h>
#include <cstdint>
#include <string>

namespace android {

namespace hardware {

namespace light {

enum class BrightnessMode : int8_t {
  USER = 0,
  SENSOR = 1,
  LOW_PERSISTENCE = 2,
};

[[nodiscard]] static inline std::string toString(BrightnessMode val) {
  switch(val) {
  case BrightnessMode::USER:
    return "USER";
  case BrightnessMode::SENSOR:
    return "SENSOR";
  case BrightnessMode::LOW_PERSISTENCE:
    return "LOW_PERSISTENCE";
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
constexpr inline std::array<::android::hardware::light::BrightnessMode, 3> enum_values<::android::hardware::light::BrightnessMode> = {
  ::android::hardware::light::BrightnessMode::USER,
  ::android::hardware::light::BrightnessMode::SENSOR,
  ::android::hardware::light::BrightnessMode::LOW_PERSISTENCE,
};
#pragma clang diagnostic pop

}  // namespace internal

}  // namespace android
