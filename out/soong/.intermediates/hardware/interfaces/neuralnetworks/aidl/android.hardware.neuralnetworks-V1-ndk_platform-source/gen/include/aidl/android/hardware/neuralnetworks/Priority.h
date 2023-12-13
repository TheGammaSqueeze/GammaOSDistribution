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
namespace hardware {
namespace neuralnetworks {
enum class Priority : int32_t {
  LOW = 0,
  MEDIUM = 1,
  HIGH = 2,
};

[[nodiscard]] static inline std::string toString(Priority val) {
  switch(val) {
  case Priority::LOW:
    return "LOW";
  case Priority::MEDIUM:
    return "MEDIUM";
  case Priority::HIGH:
    return "HIGH";
  default:
    return std::to_string(static_cast<int32_t>(val));
  }
}
}  // namespace neuralnetworks
}  // namespace hardware
}  // namespace android
}  // namespace aidl
namespace ndk {
namespace internal {
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wc++17-extensions"
template <>
constexpr inline std::array<aidl::android::hardware::neuralnetworks::Priority, 3> enum_values<aidl::android::hardware::neuralnetworks::Priority> = {
  aidl::android::hardware::neuralnetworks::Priority::LOW,
  aidl::android::hardware::neuralnetworks::Priority::MEDIUM,
  aidl::android::hardware::neuralnetworks::Priority::HIGH,
};
#pragma clang diagnostic pop
}  // namespace internal
}  // namespace android
