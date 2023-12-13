#pragma once

#include <array>
#include <binder/Enums.h>
#include <cstdint>
#include <string>

namespace android {

namespace hardware {

namespace light {

enum class LightType : int8_t {
  BACKLIGHT = 0,
  KEYBOARD = 1,
  BUTTONS = 2,
  BATTERY = 3,
  NOTIFICATIONS = 4,
  ATTENTION = 5,
  BLUETOOTH = 6,
  WIFI = 7,
  MICROPHONE = 8,
};

[[nodiscard]] static inline std::string toString(LightType val) {
  switch(val) {
  case LightType::BACKLIGHT:
    return "BACKLIGHT";
  case LightType::KEYBOARD:
    return "KEYBOARD";
  case LightType::BUTTONS:
    return "BUTTONS";
  case LightType::BATTERY:
    return "BATTERY";
  case LightType::NOTIFICATIONS:
    return "NOTIFICATIONS";
  case LightType::ATTENTION:
    return "ATTENTION";
  case LightType::BLUETOOTH:
    return "BLUETOOTH";
  case LightType::WIFI:
    return "WIFI";
  case LightType::MICROPHONE:
    return "MICROPHONE";
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
constexpr inline std::array<::android::hardware::light::LightType, 9> enum_values<::android::hardware::light::LightType> = {
  ::android::hardware::light::LightType::BACKLIGHT,
  ::android::hardware::light::LightType::KEYBOARD,
  ::android::hardware::light::LightType::BUTTONS,
  ::android::hardware::light::LightType::BATTERY,
  ::android::hardware::light::LightType::NOTIFICATIONS,
  ::android::hardware::light::LightType::ATTENTION,
  ::android::hardware::light::LightType::BLUETOOTH,
  ::android::hardware::light::LightType::WIFI,
  ::android::hardware::light::LightType::MICROPHONE,
};
#pragma clang diagnostic pop

}  // namespace internal

}  // namespace android
