#pragma once

#include <array>
#include <binder/Enums.h>
#include <cstdint>
#include <string>

namespace android {

namespace hardware {

namespace security {

namespace keymint {

enum class Digest : int32_t {
  NONE = 0,
  MD5 = 1,
  SHA1 = 2,
  SHA_2_224 = 3,
  SHA_2_256 = 4,
  SHA_2_384 = 5,
  SHA_2_512 = 6,
};

[[nodiscard]] static inline std::string toString(Digest val) {
  switch(val) {
  case Digest::NONE:
    return "NONE";
  case Digest::MD5:
    return "MD5";
  case Digest::SHA1:
    return "SHA1";
  case Digest::SHA_2_224:
    return "SHA_2_224";
  case Digest::SHA_2_256:
    return "SHA_2_256";
  case Digest::SHA_2_384:
    return "SHA_2_384";
  case Digest::SHA_2_512:
    return "SHA_2_512";
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
constexpr inline std::array<::android::hardware::security::keymint::Digest, 7> enum_values<::android::hardware::security::keymint::Digest> = {
  ::android::hardware::security::keymint::Digest::NONE,
  ::android::hardware::security::keymint::Digest::MD5,
  ::android::hardware::security::keymint::Digest::SHA1,
  ::android::hardware::security::keymint::Digest::SHA_2_224,
  ::android::hardware::security::keymint::Digest::SHA_2_256,
  ::android::hardware::security::keymint::Digest::SHA_2_384,
  ::android::hardware::security::keymint::Digest::SHA_2_512,
};
#pragma clang diagnostic pop

}  // namespace internal

}  // namespace android
