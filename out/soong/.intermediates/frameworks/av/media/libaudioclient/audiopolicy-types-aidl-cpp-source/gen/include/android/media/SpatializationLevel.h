#pragma once

#include <array>
#include <binder/Enums.h>
#include <cstdint>
#include <string>

namespace android {

namespace media {

enum class SpatializationLevel : int8_t {
  NONE = 0,
  SPATIALIZER_MULTICHANNEL = 1,
  SPATIALIZER_MCHAN_BED_PLUS_OBJECTS = 2,
};

[[nodiscard]] static inline std::string toString(SpatializationLevel val) {
  switch(val) {
  case SpatializationLevel::NONE:
    return "NONE";
  case SpatializationLevel::SPATIALIZER_MULTICHANNEL:
    return "SPATIALIZER_MULTICHANNEL";
  case SpatializationLevel::SPATIALIZER_MCHAN_BED_PLUS_OBJECTS:
    return "SPATIALIZER_MCHAN_BED_PLUS_OBJECTS";
  default:
    return std::to_string(static_cast<int8_t>(val));
  }
}

}  // namespace media

}  // namespace android
namespace android {

namespace internal {

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wc++17-extensions"
template <>
constexpr inline std::array<::android::media::SpatializationLevel, 3> enum_values<::android::media::SpatializationLevel> = {
  ::android::media::SpatializationLevel::NONE,
  ::android::media::SpatializationLevel::SPATIALIZER_MULTICHANNEL,
  ::android::media::SpatializationLevel::SPATIALIZER_MCHAN_BED_PLUS_OBJECTS,
};
#pragma clang diagnostic pop

}  // namespace internal

}  // namespace android
