#pragma once

#include <array>
#include <binder/Enums.h>
#include <cstdint>
#include <string>

namespace android {

namespace hardware {

namespace vibrator {

enum class EffectStrength : int8_t {
  LIGHT = 0,
  MEDIUM = 1,
  STRONG = 2,
};

[[nodiscard]] static inline std::string toString(EffectStrength val) {
  switch(val) {
  case EffectStrength::LIGHT:
    return "LIGHT";
  case EffectStrength::MEDIUM:
    return "MEDIUM";
  case EffectStrength::STRONG:
    return "STRONG";
  default:
    return std::to_string(static_cast<int8_t>(val));
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
constexpr inline std::array<::android::hardware::vibrator::EffectStrength, 3> enum_values<::android::hardware::vibrator::EffectStrength> = {
  ::android::hardware::vibrator::EffectStrength::LIGHT,
  ::android::hardware::vibrator::EffectStrength::MEDIUM,
  ::android::hardware::vibrator::EffectStrength::STRONG,
};
#pragma clang diagnostic pop

}  // namespace internal

}  // namespace android
