#pragma once

#include <array>
#include <binder/Enums.h>
#include <cstdint>
#include <string>

namespace android {

namespace media {

enum class AudioEncapsulationMetadataType : int32_t {
  NONE = 0,
  FRAMEWORK_TUNER = 1,
  DVB_AD_DESCRIPTOR = 2,
};

[[nodiscard]] static inline std::string toString(AudioEncapsulationMetadataType val) {
  switch(val) {
  case AudioEncapsulationMetadataType::NONE:
    return "NONE";
  case AudioEncapsulationMetadataType::FRAMEWORK_TUNER:
    return "FRAMEWORK_TUNER";
  case AudioEncapsulationMetadataType::DVB_AD_DESCRIPTOR:
    return "DVB_AD_DESCRIPTOR";
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
constexpr inline std::array<::android::media::AudioEncapsulationMetadataType, 3> enum_values<::android::media::AudioEncapsulationMetadataType> = {
  ::android::media::AudioEncapsulationMetadataType::NONE,
  ::android::media::AudioEncapsulationMetadataType::FRAMEWORK_TUNER,
  ::android::media::AudioEncapsulationMetadataType::DVB_AD_DESCRIPTOR,
};
#pragma clang diagnostic pop

}  // namespace internal

}  // namespace android
