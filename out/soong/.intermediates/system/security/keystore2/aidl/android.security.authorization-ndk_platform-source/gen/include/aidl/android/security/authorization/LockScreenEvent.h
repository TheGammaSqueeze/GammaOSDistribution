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
enum class LockScreenEvent : int32_t {
  UNLOCK = 0,
  LOCK = 1,
};

[[nodiscard]] static inline std::string toString(LockScreenEvent val) {
  switch(val) {
  case LockScreenEvent::UNLOCK:
    return "UNLOCK";
  case LockScreenEvent::LOCK:
    return "LOCK";
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
constexpr inline std::array<aidl::android::security::authorization::LockScreenEvent, 2> enum_values<aidl::android::security::authorization::LockScreenEvent> = {
  aidl::android::security::authorization::LockScreenEvent::UNLOCK,
  aidl::android::security::authorization::LockScreenEvent::LOCK,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace android
