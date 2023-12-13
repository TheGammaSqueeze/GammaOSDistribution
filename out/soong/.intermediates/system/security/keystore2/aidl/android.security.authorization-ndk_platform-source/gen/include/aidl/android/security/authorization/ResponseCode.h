#pragma once

#include <cstdint>
#include <memory>
#include <optional>
#include <string>
#include <vector>
#ifdef BINDER_STABILITY_SUPPORT
#include <android/binder_stability.h>
#endif  // BINDER_STABILITY_SUPPORT
#include <array>
#include <android/binder_enums.h>
namespace aidl {
namespace android {
namespace security {
namespace authorization {
enum class ResponseCode : int32_t {
  NO_AUTH_TOKEN_FOUND = 1,
  AUTH_TOKEN_EXPIRED = 2,
  SYSTEM_ERROR = 4,
  PERMISSION_DENIED = 6,
  KEY_NOT_FOUND = 7,
  VALUE_CORRUPTED = 8,
  INVALID_ARGUMENT = 20,
};

[[nodiscard]] static inline std::string toString(ResponseCode val) {
  switch(val) {
  case ResponseCode::NO_AUTH_TOKEN_FOUND:
    return "NO_AUTH_TOKEN_FOUND";
  case ResponseCode::AUTH_TOKEN_EXPIRED:
    return "AUTH_TOKEN_EXPIRED";
  case ResponseCode::SYSTEM_ERROR:
    return "SYSTEM_ERROR";
  case ResponseCode::PERMISSION_DENIED:
    return "PERMISSION_DENIED";
  case ResponseCode::KEY_NOT_FOUND:
    return "KEY_NOT_FOUND";
  case ResponseCode::VALUE_CORRUPTED:
    return "VALUE_CORRUPTED";
  case ResponseCode::INVALID_ARGUMENT:
    return "INVALID_ARGUMENT";
  default:
    return std::to_string(static_cast<int32_t>(val));
  }
}
}  // namespace authorization
}  // namespace security
}  // namespace android
}  // namespace aidl
namespace ndk {
namespace internal {
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wc++17-extensions"
template <>
constexpr inline std::array<aidl::android::security::authorization::ResponseCode, 7> enum_values<aidl::android::security::authorization::ResponseCode> = {
  aidl::android::security::authorization::ResponseCode::NO_AUTH_TOKEN_FOUND,
  aidl::android::security::authorization::ResponseCode::AUTH_TOKEN_EXPIRED,
  aidl::android::security::authorization::ResponseCode::SYSTEM_ERROR,
  aidl::android::security::authorization::ResponseCode::PERMISSION_DENIED,
  aidl::android::security::authorization::ResponseCode::KEY_NOT_FOUND,
  aidl::android::security::authorization::ResponseCode::VALUE_CORRUPTED,
  aidl::android::security::authorization::ResponseCode::INVALID_ARGUMENT,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace android
