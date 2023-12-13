#pragma once

#include <array>
#include <binder/Enums.h>
#include <cstdint>
#include <string>

namespace android {

namespace media {

enum class VolumeShaperConfigurationType : int32_t {
  ID = 0,
  SCALE = 1,
};

[[nodiscard]] static inline std::string toString(VolumeShaperConfigurationType val) {
  switch(val) {
  case VolumeShaperConfigurationType::ID:
    return "ID";
  case VolumeShaperConfigurationType::SCALE:
    return "SCALE";
  default:
    return std::to_string(static_cast<int32_t>(val));
  }
}

}  // namespace media

}  // namespace android
namespace android {

namespace internal {

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wc++17-extensions"
template <>
constexpr inline std::array<::android::media::VolumeShaperConfigurationType, 2> enum_values<::android::media::VolumeShaperConfigurationType> = {
  ::android::media::VolumeShaperConfigurationType::ID,
  ::android::media::VolumeShaperConfigurationType::SCALE,
};
#pragma clang diagnostic pop

}  // namespace internal

}  // namespace android
