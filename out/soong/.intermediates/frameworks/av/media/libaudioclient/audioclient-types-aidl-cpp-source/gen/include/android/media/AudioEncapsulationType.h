#pragma once

#include <array>
#include <binder/Enums.h>
#include <cstdint>
#include <string>

namespace android {

namespace media {

enum class AudioEncapsulationType : int32_t {
  NONE = 0,
  IEC61937 = 1,
};

[[nodiscard]] static inline std::string toString(AudioEncapsulationType val) {
  switch(val) {
  case AudioEncapsulationType::NONE:
    return "NONE";
  case AudioEncapsulationType::IEC61937:
    return "IEC61937";
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
constexpr inline std::array<::android::media::AudioEncapsulationType, 2> enum_values<::android::media::AudioEncapsulationType> = {
  ::android::media::AudioEncapsulationType::NONE,
  ::android::media::AudioEncapsulationType::IEC61937,
};
#pragma clang diagnostic pop

}  // namespace internal

}  // namespace android
