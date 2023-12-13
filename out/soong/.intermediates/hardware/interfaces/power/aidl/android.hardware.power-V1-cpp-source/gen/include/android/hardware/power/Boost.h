#pragma once

#include <array>
#include <binder/Enums.h>
#include <cstdint>
#include <string>

namespace android {

namespace hardware {

namespace power {

enum class Boost : int32_t {
  INTERACTION = 0,
  DISPLAY_UPDATE_IMMINENT = 1,
  ML_ACC = 2,
  AUDIO_LAUNCH = 3,
  CAMERA_LAUNCH = 4,
  CAMERA_SHOT = 5,
};

[[nodiscard]] static inline std::string toString(Boost val) {
  switch(val) {
  case Boost::INTERACTION:
    return "INTERACTION";
  case Boost::DISPLAY_UPDATE_IMMINENT:
    return "DISPLAY_UPDATE_IMMINENT";
  case Boost::ML_ACC:
    return "ML_ACC";
  case Boost::AUDIO_LAUNCH:
    return "AUDIO_LAUNCH";
  case Boost::CAMERA_LAUNCH:
    return "CAMERA_LAUNCH";
  case Boost::CAMERA_SHOT:
    return "CAMERA_SHOT";
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
constexpr inline std::array<::android::hardware::power::Boost, 6> enum_values<::android::hardware::power::Boost> = {
  ::android::hardware::power::Boost::INTERACTION,
  ::android::hardware::power::Boost::DISPLAY_UPDATE_IMMINENT,
  ::android::hardware::power::Boost::ML_ACC,
  ::android::hardware::power::Boost::AUDIO_LAUNCH,
  ::android::hardware::power::Boost::CAMERA_LAUNCH,
  ::android::hardware::power::Boost::CAMERA_SHOT,
};
#pragma clang diagnostic pop

}  // namespace internal

}  // namespace android
