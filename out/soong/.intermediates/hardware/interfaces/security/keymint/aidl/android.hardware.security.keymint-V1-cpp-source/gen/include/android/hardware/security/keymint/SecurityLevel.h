#pragma once

#include <array>
#include <binder/Enums.h>
#include <cstdint>
#include <string>

namespace android {

namespace hardware {

namespace security {

namespace keymint {

enum class SecurityLevel : int32_t {
  SOFTWARE = 0,
  TRUSTED_ENVIRONMENT = 1,
  STRONGBOX = 2,
  KEYSTORE = 100,
};

[[nodiscard]] static inline std::string toString(SecurityLevel val) {
  switch(val) {
  case SecurityLevel::SOFTWARE:
    return "SOFTWARE";
  case SecurityLevel::TRUSTED_ENVIRONMENT:
    return "TRUSTED_ENVIRONMENT";
  case SecurityLevel::STRONGBOX:
    return "STRONGBOX";
  case SecurityLevel::KEYSTORE:
    return "KEYSTORE";
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
constexpr inline std::array<::android::hardware::security::keymint::SecurityLevel, 4> enum_values<::android::hardware::security::keymint::SecurityLevel> = {
  ::android::hardware::security::keymint::SecurityLevel::SOFTWARE,
  ::android::hardware::security::keymint::SecurityLevel::TRUSTED_ENVIRONMENT,
  ::android::hardware::security::keymint::SecurityLevel::STRONGBOX,
  ::android::hardware::security::keymint::SecurityLevel::KEYSTORE,
};
#pragma clang diagnostic pop

}  // namespace internal

}  // namespace android
