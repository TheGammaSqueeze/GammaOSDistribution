#pragma once

#include <array>
#include <binder/Enums.h>
#include <cstdint>
#include <string>

namespace android {

namespace hardware {

namespace security {

namespace keymint {

enum class BlockMode : int32_t {
  ECB = 1,
  CBC = 2,
  CTR = 3,
  GCM = 32,
};

[[nodiscard]] static inline std::string toString(BlockMode val) {
  switch(val) {
  case BlockMode::ECB:
    return "ECB";
  case BlockMode::CBC:
    return "CBC";
  case BlockMode::CTR:
    return "CTR";
  case BlockMode::GCM:
    return "GCM";
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
constexpr inline std::array<::android::hardware::security::keymint::BlockMode, 4> enum_values<::android::hardware::security::keymint::BlockMode> = {
  ::android::hardware::security::keymint::BlockMode::ECB,
  ::android::hardware::security::keymint::BlockMode::CBC,
  ::android::hardware::security::keymint::BlockMode::CTR,
  ::android::hardware::security::keymint::BlockMode::GCM,
};
#pragma clang diagnostic pop

}  // namespace internal

}  // namespace android
