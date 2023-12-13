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
enum class MediaResourceType : int32_t {
  kUnspecified = 0,
  kSecureCodec = 1,
  kNonSecureCodec = 2,
  kGraphicMemory = 3,
  kCpuBoost = 4,
  kBattery = 5,
  kDrmSession = 6,
};

[[nodiscard]] static inline std::string toString(MediaResourceType val) {
  switch(val) {
  case MediaResourceType::kUnspecified:
    return "kUnspecified";
  case MediaResourceType::kSecureCodec:
    return "kSecureCodec";
  case MediaResourceType::kNonSecureCodec:
    return "kNonSecureCodec";
  case MediaResourceType::kGraphicMemory:
    return "kGraphicMemory";
  case MediaResourceType::kCpuBoost:
    return "kCpuBoost";
  case MediaResourceType::kBattery:
    return "kBattery";
  case MediaResourceType::kDrmSession:
    return "kDrmSession";
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
constexpr inline std::array<aidl::android::media::MediaResourceType, 7> enum_values<aidl::android::media::MediaResourceType> = {
  aidl::android::media::MediaResourceType::kUnspecified,
  aidl::android::media::MediaResourceType::kSecureCodec,
  aidl::android::media::MediaResourceType::kNonSecureCodec,
  aidl::android::media::MediaResourceType::kGraphicMemory,
  aidl::android::media::MediaResourceType::kCpuBoost,
  aidl::android::media::MediaResourceType::kBattery,
  aidl::android::media::MediaResourceType::kDrmSession,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace android
