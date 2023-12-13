#pragma once

#include <array>
#include <binder/Enums.h>
#include <cstdint>
#include <string>

namespace android {

namespace media {

enum class VolumeShaperConfigurationOptionFlag : int32_t {
  VOLUME_IN_DBFS = 0,
  CLOCK_TIME = 1,
};

[[nodiscard]] static inline std::string toString(VolumeShaperConfigurationOptionFlag val) {
  switch(val) {
  case VolumeShaperConfigurationOptionFlag::VOLUME_IN_DBFS:
    return "VOLUME_IN_DBFS";
  case VolumeShaperConfigurationOptionFlag::CLOCK_TIME:
    return "CLOCK_TIME";
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
constexpr inline std::array<::android::media::VolumeShaperConfigurationOptionFlag, 2> enum_values<::android::media::VolumeShaperConfigurationOptionFlag> = {
  ::android::media::VolumeShaperConfigurationOptionFlag::VOLUME_IN_DBFS,
  ::android::media::VolumeShaperConfigurationOptionFlag::CLOCK_TIME,
};
#pragma clang diagnostic pop

}  // namespace internal

}  // namespace android
