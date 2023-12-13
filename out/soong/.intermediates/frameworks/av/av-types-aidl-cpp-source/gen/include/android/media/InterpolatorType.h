#pragma once

#include <array>
#include <binder/Enums.h>
#include <cstdint>
#include <string>

namespace android {

namespace media {

enum class InterpolatorType : int32_t {
  STEP = 0,
  LINEAR = 1,
  CUBIC = 2,
  CUBIC_MONOTONIC = 3,
};

[[nodiscard]] static inline std::string toString(InterpolatorType val) {
  switch(val) {
  case InterpolatorType::STEP:
    return "STEP";
  case InterpolatorType::LINEAR:
    return "LINEAR";
  case InterpolatorType::CUBIC:
    return "CUBIC";
  case InterpolatorType::CUBIC_MONOTONIC:
    return "CUBIC_MONOTONIC";
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
constexpr inline std::array<::android::media::InterpolatorType, 4> enum_values<::android::media::InterpolatorType> = {
  ::android::media::InterpolatorType::STEP,
  ::android::media::InterpolatorType::LINEAR,
  ::android::media::InterpolatorType::CUBIC,
  ::android::media::InterpolatorType::CUBIC_MONOTONIC,
};
#pragma clang diagnostic pop

}  // namespace internal

}  // namespace android
