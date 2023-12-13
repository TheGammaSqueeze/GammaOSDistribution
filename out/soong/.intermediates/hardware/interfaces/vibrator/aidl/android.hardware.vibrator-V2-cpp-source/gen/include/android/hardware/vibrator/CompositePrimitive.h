#pragma once

#include <array>
#include <binder/Enums.h>
#include <cstdint>
#include <string>

namespace android {

namespace hardware {

namespace vibrator {

enum class CompositePrimitive : int32_t {
  NOOP = 0,
  CLICK = 1,
  THUD = 2,
  SPIN = 3,
  QUICK_RISE = 4,
  SLOW_RISE = 5,
  QUICK_FALL = 6,
  LIGHT_TICK = 7,
  LOW_TICK = 8,
};

[[nodiscard]] static inline std::string toString(CompositePrimitive val) {
  switch(val) {
  case CompositePrimitive::NOOP:
    return "NOOP";
  case CompositePrimitive::CLICK:
    return "CLICK";
  case CompositePrimitive::THUD:
    return "THUD";
  case CompositePrimitive::SPIN:
    return "SPIN";
  case CompositePrimitive::QUICK_RISE:
    return "QUICK_RISE";
  case CompositePrimitive::SLOW_RISE:
    return "SLOW_RISE";
  case CompositePrimitive::QUICK_FALL:
    return "QUICK_FALL";
  case CompositePrimitive::LIGHT_TICK:
    return "LIGHT_TICK";
  case CompositePrimitive::LOW_TICK:
    return "LOW_TICK";
  default:
    return std::to_string(static_cast<int32_t>(val));
  }
}

}  // namespace vibrator

}  // namespace hardware

}  // namespace android
namespace android {

namespace internal {

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wc++17-extensions"
template <>
constexpr inline std::array<::android::hardware::vibrator::CompositePrimitive, 9> enum_values<::android::hardware::vibrator::CompositePrimitive> = {
  ::android::hardware::vibrator::CompositePrimitive::NOOP,
  ::android::hardware::vibrator::CompositePrimitive::CLICK,
  ::android::hardware::vibrator::CompositePrimitive::THUD,
  ::android::hardware::vibrator::CompositePrimitive::SPIN,
  ::android::hardware::vibrator::CompositePrimitive::QUICK_RISE,
  ::android::hardware::vibrator::CompositePrimitive::SLOW_RISE,
  ::android::hardware::vibrator::CompositePrimitive::QUICK_FALL,
  ::android::hardware::vibrator::CompositePrimitive::LIGHT_TICK,
  ::android::hardware::vibrator::CompositePrimitive::LOW_TICK,
};
#pragma clang diagnostic pop

}  // namespace internal

}  // namespace android
