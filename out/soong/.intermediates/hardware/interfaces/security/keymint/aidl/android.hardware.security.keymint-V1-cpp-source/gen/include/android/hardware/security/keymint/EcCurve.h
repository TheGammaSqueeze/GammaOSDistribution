#pragma once

#include <array>
#include <binder/Enums.h>
#include <cstdint>
#include <string>

namespace android {

namespace hardware {

namespace security {

namespace keymint {

enum class EcCurve : int32_t {
  P_224 = 0,
  P_256 = 1,
  P_384 = 2,
  P_521 = 3,
};

[[nodiscard]] static inline std::string toString(EcCurve val) {
  switch(val) {
  case EcCurve::P_224:
    return "P_224";
  case EcCurve::P_256:
    return "P_256";
  case EcCurve::P_384:
    return "P_384";
  case EcCurve::P_521:
    return "P_521";
  default:
    return std::to_string(static_cast<int32_t>(val));
  }
}

}  // namespace keymint

}  // namespace security

}  // namespace hardware

}  // namespace android
namespace android {

namespace internal {

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wc++17-extensions"
template <>
constexpr inline std::array<::android::hardware::security::keymint::EcCurve, 4> enum_values<::android::hardware::security::keymint::EcCurve> = {
  ::android::hardware::security::keymint::EcCurve::P_224,
  ::android::hardware::security::keymint::EcCurve::P_256,
  ::android::hardware::security::keymint::EcCurve::P_384,
  ::android::hardware::security::keymint::EcCurve::P_521,
};
#pragma clang diagnostic pop

}  // namespace internal

}  // namespace android
