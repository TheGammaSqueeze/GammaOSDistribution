#pragma once

#include <array>
#include <binder/Enums.h>
#include <cstdint>
#include <string>

namespace android {

namespace hardware {

namespace security {

namespace keymint {

enum class Algorithm : int32_t {
  RSA = 1,
  EC = 3,
  AES = 32,
  TRIPLE_DES = 33,
  HMAC = 128,
};

[[nodiscard]] static inline std::string toString(Algorithm val) {
  switch(val) {
  case Algorithm::RSA:
    return "RSA";
  case Algorithm::EC:
    return "EC";
  case Algorithm::AES:
    return "AES";
  case Algorithm::TRIPLE_DES:
    return "TRIPLE_DES";
  case Algorithm::HMAC:
    return "HMAC";
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
constexpr inline std::array<::android::hardware::security::keymint::Algorithm, 5> enum_values<::android::hardware::security::keymint::Algorithm> = {
  ::android::hardware::security::keymint::Algorithm::RSA,
  ::android::hardware::security::keymint::Algorithm::EC,
  ::android::hardware::security::keymint::Algorithm::AES,
  ::android::hardware::security::keymint::Algorithm::TRIPLE_DES,
  ::android::hardware::security::keymint::Algorithm::HMAC,
};
#pragma clang diagnostic pop

}  // namespace internal

}  // namespace android
