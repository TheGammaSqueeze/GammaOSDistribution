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
enum class TranscodingSessionPriority : int32_t {
  kUnspecified = 0,
  kLow = 1,
  kNormal = 21,
  kHigh = 31,
};

[[nodiscard]] static inline std::string toString(TranscodingSessionPriority val) {
  switch(val) {
  case TranscodingSessionPriority::kUnspecified:
    return "kUnspecified";
  case TranscodingSessionPriority::kLow:
    return "kLow";
  case TranscodingSessionPriority::kNormal:
    return "kNormal";
  case TranscodingSessionPriority::kHigh:
    return "kHigh";
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
constexpr inline std::array<aidl::android::media::TranscodingSessionPriority, 4> enum_values<aidl::android::media::TranscodingSessionPriority> = {
  aidl::android::media::TranscodingSessionPriority::kUnspecified,
  aidl::android::media::TranscodingSessionPriority::kLow,
  aidl::android::media::TranscodingSessionPriority::kNormal,
  aidl::android::media::TranscodingSessionPriority::kHigh,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace android
