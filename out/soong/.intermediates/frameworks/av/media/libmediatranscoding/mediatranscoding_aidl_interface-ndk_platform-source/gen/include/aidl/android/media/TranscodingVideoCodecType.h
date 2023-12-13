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
enum class TranscodingVideoCodecType : int32_t {
  kUnspecified = 0,
  kAvc = 1,
  kHevc = 2,
};

[[nodiscard]] static inline std::string toString(TranscodingVideoCodecType val) {
  switch(val) {
  case TranscodingVideoCodecType::kUnspecified:
    return "kUnspecified";
  case TranscodingVideoCodecType::kAvc:
    return "kAvc";
  case TranscodingVideoCodecType::kHevc:
    return "kHevc";
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
constexpr inline std::array<aidl::android::media::TranscodingVideoCodecType, 3> enum_values<aidl::android::media::TranscodingVideoCodecType> = {
  aidl::android::media::TranscodingVideoCodecType::kUnspecified,
  aidl::android::media::TranscodingVideoCodecType::kAvc,
  aidl::android::media::TranscodingVideoCodecType::kHevc,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace android
