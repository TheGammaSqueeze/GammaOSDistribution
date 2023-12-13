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
enum class MediaResourceSubType : int32_t {
  kUnspecifiedSubType = 0,
  kAudioCodec = 1,
  kVideoCodec = 2,
};

[[nodiscard]] static inline std::string toString(MediaResourceSubType val) {
  switch(val) {
  case MediaResourceSubType::kUnspecifiedSubType:
    return "kUnspecifiedSubType";
  case MediaResourceSubType::kAudioCodec:
    return "kAudioCodec";
  case MediaResourceSubType::kVideoCodec:
    return "kVideoCodec";
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
constexpr inline std::array<aidl::android::media::MediaResourceSubType, 3> enum_values<aidl::android::media::MediaResourceSubType> = {
  aidl::android::media::MediaResourceSubType::kUnspecifiedSubType,
  aidl::android::media::MediaResourceSubType::kAudioCodec,
  aidl::android::media::MediaResourceSubType::kVideoCodec,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace android
