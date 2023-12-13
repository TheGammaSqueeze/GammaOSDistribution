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
enum class TranscodingType : int32_t {
  kUnknown = 0,
  kVideoTranscoding = 1,
  kImageTranscoding = 2,
};

[[nodiscard]] static inline std::string toString(TranscodingType val) {
  switch(val) {
  case TranscodingType::kUnknown:
    return "kUnknown";
  case TranscodingType::kVideoTranscoding:
    return "kVideoTranscoding";
  case TranscodingType::kImageTranscoding:
    return "kImageTranscoding";
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
constexpr inline std::array<aidl::android::media::TranscodingType, 3> enum_values<aidl::android::media::TranscodingType> = {
  aidl::android::media::TranscodingType::kUnknown,
  aidl::android::media::TranscodingType::kVideoTranscoding,
  aidl::android::media::TranscodingType::kImageTranscoding,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace android
