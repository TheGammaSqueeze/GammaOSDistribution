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
enum class MediaObservableType : int32_t {
  kInvalid = 0,
  kVideoSecureCodec = 1000,
  kVideoNonSecureCodec = 1001,
};

[[nodiscard]] static inline std::string toString(MediaObservableType val) {
  switch(val) {
  case MediaObservableType::kInvalid:
    return "kInvalid";
  case MediaObservableType::kVideoSecureCodec:
    return "kVideoSecureCodec";
  case MediaObservableType::kVideoNonSecureCodec:
    return "kVideoNonSecureCodec";
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
constexpr inline std::array<aidl::android::media::MediaObservableType, 3> enum_values<aidl::android::media::MediaObservableType> = {
  aidl::android::media::MediaObservableType::kInvalid,
  aidl::android::media::MediaObservableType::kVideoSecureCodec,
  aidl::android::media::MediaObservableType::kVideoNonSecureCodec,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace android
