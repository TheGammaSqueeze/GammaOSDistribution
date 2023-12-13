#pragma once

#include <array>
#include <binder/Enums.h>
#include <cstdint>
#include <string>

namespace android {

namespace media {

enum class DeviceRole : int32_t {
  NONE = 0,
  PREFERRED = 1,
  DISABLED = 2,
};

[[nodiscard]] static inline std::string toString(DeviceRole val) {
  switch(val) {
  case DeviceRole::NONE:
    return "NONE";
  case DeviceRole::PREFERRED:
    return "PREFERRED";
  case DeviceRole::DISABLED:
    return "DISABLED";
  default:
    return std::to_string(static_cast<int32_t>(val));
  }
}

}  // namespace media

}  // namespace android
namespace android {

namespace internal {

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wc++17-extensions"
template <>
constexpr inline std::array<::android::media::DeviceRole, 3> enum_values<::android::media::DeviceRole> = {
  ::android::media::DeviceRole::NONE,
  ::android::media::DeviceRole::PREFERRED,
  ::android::media::DeviceRole::DISABLED,
};
#pragma clang diagnostic pop

}  // namespace internal

}  // namespace android
