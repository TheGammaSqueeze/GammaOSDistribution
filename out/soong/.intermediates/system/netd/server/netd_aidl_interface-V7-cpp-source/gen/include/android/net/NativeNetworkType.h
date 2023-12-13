#pragma once

#include <array>
#include <binder/Enums.h>
#include <cstdint>
#include <string>

namespace android {

namespace net {

enum class NativeNetworkType : int32_t {
  PHYSICAL = 0,
  VIRTUAL = 1,
};

[[nodiscard]] static inline std::string toString(NativeNetworkType val) {
  switch(val) {
  case NativeNetworkType::PHYSICAL:
    return "PHYSICAL";
  case NativeNetworkType::VIRTUAL:
    return "VIRTUAL";
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
constexpr inline std::array<::android::net::NativeNetworkType, 2> enum_values<::android::net::NativeNetworkType> = {
  ::android::net::NativeNetworkType::PHYSICAL,
  ::android::net::NativeNetworkType::VIRTUAL,
};
#pragma clang diagnostic pop

}  // namespace internal

}  // namespace android
