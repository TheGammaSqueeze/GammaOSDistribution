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
enum class MediaObservableEvent : int64_t {
  kBusy = 1L,
  kIdle = 2L,
  kAll = -1L,
};

[[nodiscard]] static inline std::string toString(MediaObservableEvent val) {
  switch(val) {
  case MediaObservableEvent::kBusy:
    return "kBusy";
  case MediaObservableEvent::kIdle:
    return "kIdle";
  case MediaObservableEvent::kAll:
    return "kAll";
  default:
    return std::to_string(static_cast<int64_t>(val));
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
constexpr inline std::array<aidl::android::media::MediaObservableEvent, 3> enum_values<aidl::android::media::MediaObservableEvent> = {
  aidl::android::media::MediaObservableEvent::kBusy,
  aidl::android::media::MediaObservableEvent::kIdle,
  aidl::android::media::MediaObservableEvent::kAll,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace android
