#pragma once

#include <array>
#include <binder/Enums.h>
#include <cstdint>
#include <string>

namespace android {

namespace media {

enum class AudioPortConfigType : int32_t {
  SAMPLE_RATE = 0,
  CHANNEL_MASK = 1,
  FORMAT = 2,
  GAIN = 3,
  FLAGS = 4,
};

[[nodiscard]] static inline std::string toString(AudioPortConfigType val) {
  switch(val) {
  case AudioPortConfigType::SAMPLE_RATE:
    return "SAMPLE_RATE";
  case AudioPortConfigType::CHANNEL_MASK:
    return "CHANNEL_MASK";
  case AudioPortConfigType::FORMAT:
    return "FORMAT";
  case AudioPortConfigType::GAIN:
    return "GAIN";
  case AudioPortConfigType::FLAGS:
    return "FLAGS";
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
constexpr inline std::array<::android::media::AudioPortConfigType, 5> enum_values<::android::media::AudioPortConfigType> = {
  ::android::media::AudioPortConfigType::SAMPLE_RATE,
  ::android::media::AudioPortConfigType::CHANNEL_MASK,
  ::android::media::AudioPortConfigType::FORMAT,
  ::android::media::AudioPortConfigType::GAIN,
  ::android::media::AudioPortConfigType::FLAGS,
};
#pragma clang diagnostic pop

}  // namespace internal

}  // namespace android
