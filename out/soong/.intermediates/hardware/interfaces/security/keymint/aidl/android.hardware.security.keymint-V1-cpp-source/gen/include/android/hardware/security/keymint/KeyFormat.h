#pragma once

#include <array>
#include <binder/Enums.h>
#include <cstdint>
#include <string>

namespace android {

namespace hardware {

namespace security {

namespace keymint {

enum class KeyFormat : int32_t {
  X509 = 0,
  PKCS8 = 1,
  RAW = 3,
};

[[nodiscard]] static inline std::string toString(KeyFormat val) {
  switch(val) {
  case KeyFormat::X509:
    return "X509";
  case KeyFormat::PKCS8:
    return "PKCS8";
  case KeyFormat::RAW:
    return "RAW";
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
constexpr inline std::array<::android::hardware::security::keymint::KeyFormat, 3> enum_values<::android::hardware::security::keymint::KeyFormat> = {
  ::android::hardware::security::keymint::KeyFormat::X509,
  ::android::hardware::security::keymint::KeyFormat::PKCS8,
  ::android::hardware::security::keymint::KeyFormat::RAW,
};
#pragma clang diagnostic pop

}  // namespace internal

}  // namespace android
