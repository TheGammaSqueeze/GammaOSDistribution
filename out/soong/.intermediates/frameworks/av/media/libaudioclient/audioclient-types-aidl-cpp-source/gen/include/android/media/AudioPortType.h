#pragma once

#include <array>
#include <binder/Enums.h>
#include <cstdint>
#include <string>

namespace android {

namespace media {

enum class AudioPortType : int32_t {
  NONE = 0,
  DEVICE = 1,
  MIX = 2,
  SESSION = 3,
};

[[nodiscard]] static inline std::string toString(AudioPortType val) {
  switch(val) {
  case AudioPortType::NONE:
    return "NONE";
  case AudioPortType::DEVICE:
    return "DEVICE";
  case AudioPortType::MIX:
    return "MIX";
  case AudioPortType::SESSION:
    return "SESSION";
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
constexpr inline std::array<::android::media::AudioPortType, 4> enum_values<::android::media::AudioPortType> = {
  ::android::media::AudioPortType::NONE,
  ::android::media::AudioPortType::DEVICE,
  ::android::media::AudioPortType::MIX,
  ::android::media::AudioPortType::SESSION,
};
#pragma clang diagnostic pop

}  // namespace internal

}  // namespace android
