#pragma once

#include <array>
#include <binder/Enums.h>
#include <cstdint>
#include <string>

namespace android {

namespace system {

namespace keystore2 {

enum class Domain : int32_t {
  APP = 0,
  GRANT = 1,
  SELINUX = 2,
  BLOB = 3,
  KEY_ID = 4,
};

[[nodiscard]] static inline std::string toString(Domain val) {
  switch(val) {
  case Domain::APP:
    return "APP";
  case Domain::GRANT:
    return "GRANT";
  case Domain::SELINUX:
    return "SELINUX";
  case Domain::BLOB:
    return "BLOB";
  case Domain::KEY_ID:
    return "KEY_ID";
  default:
    return std::to_string(static_cast<int32_t>(val));
  }
}

}  // namespace keystore2

}  // namespace system

}  // namespace android
namespace android {

namespace internal {

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wc++17-extensions"
template <>
constexpr inline std::array<::android::system::keystore2::Domain, 5> enum_values<::android::system::keystore2::Domain> = {
  ::android::system::keystore2::Domain::APP,
  ::android::system::keystore2::Domain::GRANT,
  ::android::system::keystore2::Domain::SELINUX,
  ::android::system::keystore2::Domain::BLOB,
  ::android::system::keystore2::Domain::KEY_ID,
};
#pragma clang diagnostic pop

}  // namespace internal

}  // namespace android
