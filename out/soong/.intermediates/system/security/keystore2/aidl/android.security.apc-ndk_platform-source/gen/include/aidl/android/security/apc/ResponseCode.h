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
namespace apc {
enum class ResponseCode : int32_t {
  OK = 0,
  CANCELLED = 1,
  ABORTED = 2,
  OPERATION_PENDING = 3,
  IGNORED = 4,
  SYSTEM_ERROR = 5,
  UNIMPLEMENTED = 6,
  PERMISSION_DENIED = 30,
};

[[nodiscard]] static inline std::string toString(ResponseCode val) {
  switch(val) {
  case ResponseCode::OK:
    return "OK";
  case ResponseCode::CANCELLED:
    return "CANCELLED";
  case ResponseCode::ABORTED:
    return "ABORTED";
  case ResponseCode::OPERATION_PENDING:
    return "OPERATION_PENDING";
  case ResponseCode::IGNORED:
    return "IGNORED";
  case ResponseCode::SYSTEM_ERROR:
    return "SYSTEM_ERROR";
  case ResponseCode::UNIMPLEMENTED:
    return "UNIMPLEMENTED";
  case ResponseCode::PERMISSION_DENIED:
    return "PERMISSION_DENIED";
  default:
    return std::to_string(static_cast<int32_t>(val));
  }
}
}  // namespace apc
}  // namespace security
}  // namespace android
}  // namespace aidl
namespace ndk {
namespace internal {
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wc++17-extensions"
template <>
constexpr inline std::array<aidl::android::security::apc::ResponseCode, 8> enum_values<aidl::android::security::apc::ResponseCode> = {
  aidl::android::security::apc::ResponseCode::OK,
  aidl::android::security::apc::ResponseCode::CANCELLED,
  aidl::android::security::apc::ResponseCode::ABORTED,
  aidl::android::security::apc::ResponseCode::OPERATION_PENDING,
  aidl::android::security::apc::ResponseCode::IGNORED,
  aidl::android::security::apc::ResponseCode::SYSTEM_ERROR,
  aidl::android::security::apc::ResponseCode::UNIMPLEMENTED,
  aidl::android::security::apc::ResponseCode::PERMISSION_DENIED,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace android
