#pragma once

#include <array>
#include <binder/Enums.h>
#include <cstdint>
#include <string>

namespace android {

namespace hardware {

namespace identity {

enum class CipherSuite : int32_t {
  CIPHERSUITE_ECDHE_HKDF_ECDSA_WITH_AES_256_GCM_SHA256 = 1,
};

[[nodiscard]] static inline std::string toString(CipherSuite val) {
  switch(val) {
  case CipherSuite::CIPHERSUITE_ECDHE_HKDF_ECDSA_WITH_AES_256_GCM_SHA256:
    return "CIPHERSUITE_ECDHE_HKDF_ECDSA_WITH_AES_256_GCM_SHA256";
  default:
    return std::to_string(static_cast<int32_t>(val));
  }
}

}  // namespace identity

}  // namespace hardware

}  // namespace android
namespace android {

namespace internal {

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wc++17-extensions"
template <>
constexpr inline std::array<::android::hardware::identity::CipherSuite, 1> enum_values<::android::hardware::identity::CipherSuite> = {
  ::android::hardware::identity::CipherSuite::CIPHERSUITE_ECDHE_HKDF_ECDSA_WITH_AES_256_GCM_SHA256,
};
#pragma clang diagnostic pop

}  // namespace internal

}  // namespace android
