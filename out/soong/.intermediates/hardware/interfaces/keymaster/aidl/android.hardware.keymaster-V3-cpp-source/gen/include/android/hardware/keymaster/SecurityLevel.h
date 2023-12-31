#pragma once

#include <array>
#include <binder/Enums.h>
#include <cstdint>
#include <string>

namespace android {

namespace hardware {

namespace keymaster {

enum class SecurityLevel : int32_t {
  SOFTWARE = 0,
  TRUSTED_ENVIRONMENT = 1,
  STRONGBOX = 2,
};

[[nodiscard]] static inline std::string toString(SecurityLevel val) {
  switch(val) {
  case SecurityLevel::SOFTWARE:
    return "SOFTWARE";
  case SecurityLevel::TRUSTED_ENVIRONMENT:
    return "TRUSTED_ENVIRONMENT";
  case SecurityLevel::STRONGBOX:
    return "STRONGBOX";
  default:
    return std::to_string(static_cast<int32_t>(val));
  }
}

}  // namespace keymaster

}  // namespace hardware

}  // namespace android
namespace android {

namespace internal {

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wc++17-extensions"
template <>
constexpr inline std::array<::android::hardware::keymaster::SecurityLevel, 3> enum_values<::android::hardware::keymaster::SecurityLevel> = {
  ::android::hardware::keymaster::SecurityLevel::SOFTWARE,
  ::android::hardware::keymaster::SecurityLevel::TRUSTED_ENVIRONMENT,
  ::android::hardware::keymaster::SecurityLevel::STRONGBOX,
};
#pragma clang diagnostic pop

}  // namespace internal

}  // namespace android
