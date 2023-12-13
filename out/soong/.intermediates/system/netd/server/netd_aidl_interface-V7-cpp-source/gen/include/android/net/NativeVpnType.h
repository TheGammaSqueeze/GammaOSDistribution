#pragma once

#include <array>
#include <binder/Enums.h>
#include <cstdint>
#include <string>

namespace android {

namespace net {

enum class NativeVpnType : int32_t {
  SERVICE = 1,
  PLATFORM = 2,
  LEGACY = 3,
  OEM = 4,
};

[[nodiscard]] static inline std::string toString(NativeVpnType val) {
  switch(val) {
  case NativeVpnType::SERVICE:
    return "SERVICE";
  case NativeVpnType::PLATFORM:
    return "PLATFORM";
  case NativeVpnType::LEGACY:
    return "LEGACY";
  case NativeVpnType::OEM:
    return "OEM";
  default:
    return std::to_string(static_cast<int32_t>(val));
  }
}

}  // namespace net

}  // namespace android
namespace android {

namespace internal {

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wc++17-extensions"
template <>
constexpr inline std::array<::android::net::NativeVpnType, 4> enum_values<::android::net::NativeVpnType> = {
  ::android::net::NativeVpnType::SERVICE,
  ::android::net::NativeVpnType::PLATFORM,
  ::android::net::NativeVpnType::LEGACY,
  ::android::net::NativeVpnType::OEM,
};
#pragma clang diagnostic pop

}  // namespace internal

}  // namespace android
