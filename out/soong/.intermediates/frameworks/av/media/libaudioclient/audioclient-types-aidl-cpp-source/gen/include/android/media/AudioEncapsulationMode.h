#pragma once

#include <array>
#include <binder/Enums.h>
#include <cstdint>
#include <string>

namespace android {

namespace media {

enum class AudioEncapsulationMode : int32_t {
  NONE = 0,
  ELEMENTARY_STREAM = 1,
  HANDLE = 2,
};

[[nodiscard]] static inline std::string toString(AudioEncapsulationMode val) {
  switch(val) {
  case AudioEncapsulationMode::NONE:
    return "NONE";
  case AudioEncapsulationMode::ELEMENTARY_STREAM:
    return "ELEMENTARY_STREAM";
  case AudioEncapsulationMode::HANDLE:
    return "HANDLE";
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
constexpr inline std::array<::android::media::AudioEncapsulationMode, 3> enum_values<::android::media::AudioEncapsulationMode> = {
  ::android::media::AudioEncapsulationMode::NONE,
  ::android::media::AudioEncapsulationMode::ELEMENTARY_STREAM,
  ::android::media::AudioEncapsulationMode::HANDLE,
};
#pragma clang diagnostic pop

}  // namespace internal

}  // namespace android
