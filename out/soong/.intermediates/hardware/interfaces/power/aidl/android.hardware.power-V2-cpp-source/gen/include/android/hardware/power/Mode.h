#pragma once

#include <array>
#include <binder/Enums.h>
#include <cstdint>
#include <string>

namespace android {

namespace hardware {

namespace power {

enum class Mode : int32_t {
  DOUBLE_TAP_TO_WAKE = 0,
  LOW_POWER = 1,
  SUSTAINED_PERFORMANCE = 2,
  FIXED_PERFORMANCE = 3,
  VR = 4,
  LAUNCH = 5,
  EXPENSIVE_RENDERING = 6,
  INTERACTIVE = 7,
  DEVICE_IDLE = 8,
  DISPLAY_INACTIVE = 9,
  AUDIO_STREAMING_LOW_LATENCY = 10,
  CAMERA_STREAMING_SECURE = 11,
  CAMERA_STREAMING_LOW = 12,
  CAMERA_STREAMING_MID = 13,
  CAMERA_STREAMING_HIGH = 14,
};

[[nodiscard]] static inline std::string toString(Mode val) {
  switch(val) {
  case Mode::DOUBLE_TAP_TO_WAKE:
    return "DOUBLE_TAP_TO_WAKE";
  case Mode::LOW_POWER:
    return "LOW_POWER";
  case Mode::SUSTAINED_PERFORMANCE:
    return "SUSTAINED_PERFORMANCE";
  case Mode::FIXED_PERFORMANCE:
    return "FIXED_PERFORMANCE";
  case Mode::VR:
    return "VR";
  case Mode::LAUNCH:
    return "LAUNCH";
  case Mode::EXPENSIVE_RENDERING:
    return "EXPENSIVE_RENDERING";
  case Mode::INTERACTIVE:
    return "INTERACTIVE";
  case Mode::DEVICE_IDLE:
    return "DEVICE_IDLE";
  case Mode::DISPLAY_INACTIVE:
    return "DISPLAY_INACTIVE";
  case Mode::AUDIO_STREAMING_LOW_LATENCY:
    return "AUDIO_STREAMING_LOW_LATENCY";
  case Mode::CAMERA_STREAMING_SECURE:
    return "CAMERA_STREAMING_SECURE";
  case Mode::CAMERA_STREAMING_LOW:
    return "CAMERA_STREAMING_LOW";
  case Mode::CAMERA_STREAMING_MID:
    return "CAMERA_STREAMING_MID";
  case Mode::CAMERA_STREAMING_HIGH:
    return "CAMERA_STREAMING_HIGH";
  default:
    return std::to_string(static_cast<int32_t>(val));
  }
}

}  // namespace power

}  // namespace hardware

}  // namespace android
namespace android {

namespace internal {

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wc++17-extensions"
template <>
constexpr inline std::array<::android::hardware::power::Mode, 15> enum_values<::android::hardware::power::Mode> = {
  ::android::hardware::power::Mode::DOUBLE_TAP_TO_WAKE,
  ::android::hardware::power::Mode::LOW_POWER,
  ::android::hardware::power::Mode::SUSTAINED_PERFORMANCE,
  ::android::hardware::power::Mode::FIXED_PERFORMANCE,
  ::android::hardware::power::Mode::VR,
  ::android::hardware::power::Mode::LAUNCH,
  ::android::hardware::power::Mode::EXPENSIVE_RENDERING,
  ::android::hardware::power::Mode::INTERACTIVE,
  ::android::hardware::power::Mode::DEVICE_IDLE,
  ::android::hardware::power::Mode::DISPLAY_INACTIVE,
  ::android::hardware::power::Mode::AUDIO_STREAMING_LOW_LATENCY,
  ::android::hardware::power::Mode::CAMERA_STREAMING_SECURE,
  ::android::hardware::power::Mode::CAMERA_STREAMING_LOW,
  ::android::hardware::power::Mode::CAMERA_STREAMING_MID,
  ::android::hardware::power::Mode::CAMERA_STREAMING_HIGH,
};
#pragma clang diagnostic pop

}  // namespace internal

}  // namespace android
