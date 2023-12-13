#pragma once

#include <array>
#include <binder/Enums.h>
#include <cstdint>
#include <string>

namespace android {

namespace media {

enum class AudioUniqueIdUse : int32_t {
  UNSPECIFIED = 0,
  SESSION = 1,
  MODULE = 2,
  EFFECT = 3,
  PATCH = 4,
  OUTPUT = 5,
  INPUT = 6,
  CLIENT = 7,
};

[[nodiscard]] static inline std::string toString(AudioUniqueIdUse val) {
  switch(val) {
  case AudioUniqueIdUse::UNSPECIFIED:
    return "UNSPECIFIED";
  case AudioUniqueIdUse::SESSION:
    return "SESSION";
  case AudioUniqueIdUse::MODULE:
    return "MODULE";
  case AudioUniqueIdUse::EFFECT:
    return "EFFECT";
  case AudioUniqueIdUse::PATCH:
    return "PATCH";
  case AudioUniqueIdUse::OUTPUT:
    return "OUTPUT";
  case AudioUniqueIdUse::INPUT:
    return "INPUT";
  case AudioUniqueIdUse::CLIENT:
    return "CLIENT";
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
constexpr inline std::array<::android::media::AudioUniqueIdUse, 8> enum_values<::android::media::AudioUniqueIdUse> = {
  ::android::media::AudioUniqueIdUse::UNSPECIFIED,
  ::android::media::AudioUniqueIdUse::SESSION,
  ::android::media::AudioUniqueIdUse::MODULE,
  ::android::media::AudioUniqueIdUse::EFFECT,
  ::android::media::AudioUniqueIdUse::PATCH,
  ::android::media::AudioUniqueIdUse::OUTPUT,
  ::android::media::AudioUniqueIdUse::INPUT,
  ::android::media::AudioUniqueIdUse::CLIENT,
};
#pragma clang diagnostic pop

}  // namespace internal

}  // namespace android
