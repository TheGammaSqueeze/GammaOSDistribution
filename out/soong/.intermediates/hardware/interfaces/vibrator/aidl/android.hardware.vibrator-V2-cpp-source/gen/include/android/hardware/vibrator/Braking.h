#pragma once

#include <array>
#include <binder/Enums.h>
#include <cstdint>
#include <string>

namespace android {

namespace hardware {

namespace vibrator {

enum class Braking : int32_t {
  NONE = 0,
  CLAB = 1,
};

[[nodiscard]] static inline std::string toString(Braking val) {
  switch(val) {
  case Braking::NONE:
    return "NONE";
  case Braking::CLAB:
    return "CLAB";
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
constexpr inline std::array<::android::hardware::vibrator::Braking, 2> enum_values<::android::hardware::vibrator::Braking> = {
  ::android::hardware::vibrator::Braking::NONE,
  ::android::hardware::vibrator::Braking::CLAB,
};
#pragma clang diagnostic pop

}  // namespace internal

}  // namespace android
