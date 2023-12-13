#pragma once

#include <array>
#include <binder/Enums.h>
#include <cstdint>
#include <string>

namespace android {

namespace media {

enum class AudioStandard : int32_t {
  NONE = 0,
  EDID = 1,
};

[[nodiscard]] static inline std::string toString(AudioStandard val) {
  switch(val) {
  case AudioStandard::NONE:
    return "NONE";
  case AudioStandard::EDID:
    return "EDID";
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
constexpr inline std::array<::android::media::AudioStandard, 2> enum_values<::android::media::AudioStandard> = {
  ::android::media::AudioStandard::NONE,
  ::android::media::AudioStandard::EDID,
};
#pragma clang diagnostic pop

}  // namespace internal

}  // namespace android
