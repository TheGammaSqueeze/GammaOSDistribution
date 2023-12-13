#pragma once

#include <array>
#include <binder/Enums.h>
#include <cstdint>
#include <string>

namespace android {

namespace media {

enum class AudioPortRole : int32_t {
  NONE = 0,
  SOURCE = 1,
  SINK = 2,
};

[[nodiscard]] static inline std::string toString(AudioPortRole val) {
  switch(val) {
  case AudioPortRole::NONE:
    return "NONE";
  case AudioPortRole::SOURCE:
    return "SOURCE";
  case AudioPortRole::SINK:
    return "SINK";
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
constexpr inline std::array<::android::media::AudioPortRole, 3> enum_values<::android::media::AudioPortRole> = {
  ::android::media::AudioPortRole::NONE,
  ::android::media::AudioPortRole::SOURCE,
  ::android::media::AudioPortRole::SINK,
};
#pragma clang diagnostic pop

}  // namespace internal

}  // namespace android
