#pragma once

#include <array>
#include <binder/Enums.h>
#include <cstdint>
#include <string>

namespace android {

namespace media {

enum class AudioMixType : int32_t {
  PLAYERS = 0,
  RECORDERS = 1,
};

[[nodiscard]] static inline std::string toString(AudioMixType val) {
  switch(val) {
  case AudioMixType::PLAYERS:
    return "PLAYERS";
  case AudioMixType::RECORDERS:
    return "RECORDERS";
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
constexpr inline std::array<::android::media::AudioMixType, 2> enum_values<::android::media::AudioMixType> = {
  ::android::media::AudioMixType::PLAYERS,
  ::android::media::AudioMixType::RECORDERS,
};
#pragma clang diagnostic pop

}  // namespace internal

}  // namespace android
