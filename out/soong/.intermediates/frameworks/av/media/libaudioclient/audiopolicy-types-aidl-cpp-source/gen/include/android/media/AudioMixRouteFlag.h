#pragma once

#include <array>
#include <binder/Enums.h>
#include <cstdint>
#include <string>

namespace android {

namespace media {

enum class AudioMixRouteFlag : int32_t {
  RENDER = 0,
  LOOP_BACK = 1,
};

[[nodiscard]] static inline std::string toString(AudioMixRouteFlag val) {
  switch(val) {
  case AudioMixRouteFlag::RENDER:
    return "RENDER";
  case AudioMixRouteFlag::LOOP_BACK:
    return "LOOP_BACK";
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
constexpr inline std::array<::android::media::AudioMixRouteFlag, 2> enum_values<::android::media::AudioMixRouteFlag> = {
  ::android::media::AudioMixRouteFlag::RENDER,
  ::android::media::AudioMixRouteFlag::LOOP_BACK,
};
#pragma clang diagnostic pop

}  // namespace internal

}  // namespace android
