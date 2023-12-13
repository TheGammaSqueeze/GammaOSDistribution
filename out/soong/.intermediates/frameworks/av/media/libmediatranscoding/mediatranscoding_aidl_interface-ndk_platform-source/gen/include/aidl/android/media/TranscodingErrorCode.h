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
namespace media {
enum class TranscodingErrorCode : int32_t {
  kNoError = 0,
  kDroppedByService = 1,
  kServiceUnavailable = 2,
  kPrivateErrorFirst = 1000,
  kUnknown = 1000,
  kMalformed = 1001,
  kUnsupported = 1002,
  kInvalidParameter = 1003,
  kInvalidOperation = 1004,
  kErrorIO = 1005,
  kInsufficientResources = 1006,
  kWatchdogTimeout = 1007,
  kUidGoneCancelled = 1008,
};

[[nodiscard]] static inline std::string toString(TranscodingErrorCode val) {
  switch(val) {
  case TranscodingErrorCode::kNoError:
    return "kNoError";
  case TranscodingErrorCode::kDroppedByService:
    return "kDroppedByService";
  case TranscodingErrorCode::kServiceUnavailable:
    return "kServiceUnavailable";
  case TranscodingErrorCode::kPrivateErrorFirst:
    return "kPrivateErrorFirst";
  case TranscodingErrorCode::kMalformed:
    return "kMalformed";
  case TranscodingErrorCode::kUnsupported:
    return "kUnsupported";
  case TranscodingErrorCode::kInvalidParameter:
    return "kInvalidParameter";
  case TranscodingErrorCode::kInvalidOperation:
    return "kInvalidOperation";
  case TranscodingErrorCode::kErrorIO:
    return "kErrorIO";
  case TranscodingErrorCode::kInsufficientResources:
    return "kInsufficientResources";
  case TranscodingErrorCode::kWatchdogTimeout:
    return "kWatchdogTimeout";
  case TranscodingErrorCode::kUidGoneCancelled:
    return "kUidGoneCancelled";
  default:
    return std::to_string(static_cast<int32_t>(val));
  }
}
}  // namespace media
}  // namespace android
}  // namespace aidl
namespace ndk {
namespace internal {
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wc++17-extensions"
template <>
constexpr inline std::array<aidl::android::media::TranscodingErrorCode, 13> enum_values<aidl::android::media::TranscodingErrorCode> = {
  aidl::android::media::TranscodingErrorCode::kNoError,
  aidl::android::media::TranscodingErrorCode::kDroppedByService,
  aidl::android::media::TranscodingErrorCode::kServiceUnavailable,
  aidl::android::media::TranscodingErrorCode::kPrivateErrorFirst,
  aidl::android::media::TranscodingErrorCode::kUnknown,
  aidl::android::media::TranscodingErrorCode::kMalformed,
  aidl::android::media::TranscodingErrorCode::kUnsupported,
  aidl::android::media::TranscodingErrorCode::kInvalidParameter,
  aidl::android::media::TranscodingErrorCode::kInvalidOperation,
  aidl::android::media::TranscodingErrorCode::kErrorIO,
  aidl::android::media::TranscodingErrorCode::kInsufficientResources,
  aidl::android::media::TranscodingErrorCode::kWatchdogTimeout,
  aidl::android::media::TranscodingErrorCode::kUidGoneCancelled,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace android
