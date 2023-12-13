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
namespace maintenance {
enum class UserState : int32_t {
  UNINITIALIZED = 0,
  LSKF_UNLOCKED = 1,
  LSKF_LOCKED = 2,
};

[[nodiscard]] static inline std::string toString(UserState val) {
  switch(val) {
  case UserState::UNINITIALIZED:
    return "UNINITIALIZED";
  case UserState::LSKF_UNLOCKED:
    return "LSKF_UNLOCKED";
  case UserState::LSKF_LOCKED:
    return "LSKF_LOCKED";
  default:
    return std::to_string(static_cast<int32_t>(val));
  }
}
}  // namespace maintenance
}  // namespace security
}  // namespace android
}  // namespace aidl
namespace ndk {
namespace internal {
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wc++17-extensions"
template <>
constexpr inline std::array<aidl::android::security::maintenance::UserState, 3> enum_values<aidl::android::security::maintenance::UserState> = {
  aidl::android::security::maintenance::UserState::UNINITIALIZED,
  aidl::android::security::maintenance::UserState::LSKF_UNLOCKED,
  aidl::android::security::maintenance::UserState::LSKF_LOCKED,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace android
