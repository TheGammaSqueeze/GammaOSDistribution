#pragma once

#include <array>
#include <binder/Enums.h>
#include <cstdint>
#include <string>

namespace android {

namespace media {

enum class AudioContentType : int32_t {
  UNKNOWN = 0,
  SPEECH = 1,
  MUSIC = 2,
  MOVIE = 3,
  SONIFICATION = 4,
};

[[nodiscard]] static inline std::string toString(AudioContentType val) {
  switch(val) {
  case AudioContentType::UNKNOWN:
    return "UNKNOWN";
  case AudioContentType::SPEECH:
    return "SPEECH";
  case AudioContentType::MUSIC:
    return "MUSIC";
  case AudioContentType::MOVIE:
    return "MOVIE";
  case AudioContentType::SONIFICATION:
    return "SONIFICATION";
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
constexpr inline std::array<::android::media::AudioContentType, 5> enum_values<::android::media::AudioContentType> = {
  ::android::media::AudioContentType::UNKNOWN,
  ::android::media::AudioContentType::SPEECH,
  ::android::media::AudioContentType::MUSIC,
  ::android::media::AudioContentType::MOVIE,
  ::android::media::AudioContentType::SONIFICATION,
};
#pragma clang diagnostic pop

}  // namespace internal

}  // namespace android
