#pragma once

#include <array>
#include <binder/Enums.h>
#include <cstdint>
#include <string>

namespace android {

namespace hardware {

namespace security {

namespace keymint {

enum class PaddingMode : int32_t {
  NONE = 1,
  RSA_OAEP = 2,
  RSA_PSS = 3,
  RSA_PKCS1_1_5_ENCRYPT = 4,
  RSA_PKCS1_1_5_SIGN = 5,
  PKCS7 = 64,
};

[[nodiscard]] static inline std::string toString(PaddingMode val) {
  switch(val) {
  case PaddingMode::NONE:
    return "NONE";
  case PaddingMode::RSA_OAEP:
    return "RSA_OAEP";
  case PaddingMode::RSA_PSS:
    return "RSA_PSS";
  case PaddingMode::RSA_PKCS1_1_5_ENCRYPT:
    return "RSA_PKCS1_1_5_ENCRYPT";
  case PaddingMode::RSA_PKCS1_1_5_SIGN:
    return "RSA_PKCS1_1_5_SIGN";
  case PaddingMode::PKCS7:
    return "PKCS7";
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
constexpr inline std::array<::android::hardware::security::keymint::PaddingMode, 6> enum_values<::android::hardware::security::keymint::PaddingMode> = {
  ::android::hardware::security::keymint::PaddingMode::NONE,
  ::android::hardware::security::keymint::PaddingMode::RSA_OAEP,
  ::android::hardware::security::keymint::PaddingMode::RSA_PSS,
  ::android::hardware::security::keymint::PaddingMode::RSA_PKCS1_1_5_ENCRYPT,
  ::android::hardware::security::keymint::PaddingMode::RSA_PKCS1_1_5_SIGN,
  ::android::hardware::security::keymint::PaddingMode::PKCS7,
};
#pragma clang diagnostic pop

}  // namespace internal

}  // namespace android
