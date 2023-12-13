#pragma once

#include <array>
#include <binder/Enums.h>
#include <cstdint>
#include <string>

namespace android {

namespace hardware {

namespace security {

namespace keymint {

enum class HardwareAuthenticatorType : int32_t {
  NONE = 0,
  PASSWORD = 1,
  FINGERPRINT = 2,
  ANY = -1,
};

[[nodiscard]] static inline std::string toString(HardwareAuthenticatorType val) {
  switch(val) {
  case HardwareAuthenticatorType::NONE:
    return "NONE";
  case HardwareAuthenticatorType::PASSWORD:
    return "PASSWORD";
  case HardwareAuthenticatorType::FINGERPRINT:
    return "FINGERPRINT";
  case HardwareAuthenticatorType::ANY:
    return "ANY";
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
constexpr inline std::array<::android::hardware::security::keymint::HardwareAuthenticatorType, 4> enum_values<::android::hardware::security::keymint::HardwareAuthenticatorType> = {
  ::android::hardware::security::keymint::HardwareAuthenticatorType::NONE,
  ::android::hardware::security::keymint::HardwareAuthenticatorType::PASSWORD,
  ::android::hardware::security::keymint::HardwareAuthenticatorType::FINGERPRINT,
  ::android::hardware::security::keymint::HardwareAuthenticatorType::ANY,
};
#pragma clang diagnostic pop

}  // namespace internal

}  // namespace android
