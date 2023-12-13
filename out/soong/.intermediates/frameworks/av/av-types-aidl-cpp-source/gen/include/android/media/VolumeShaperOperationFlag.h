#pragma once

#include <array>
#include <binder/Enums.h>
#include <cstdint>
#include <string>

namespace android {

namespace media {

enum class VolumeShaperOperationFlag : int32_t {
  REVERSE = 0,
  TERMINATE = 1,
  JOIN = 2,
  DELAY = 3,
  CREATE_IF_NECESSARY = 4,
};

[[nodiscard]] static inline std::string toString(VolumeShaperOperationFlag val) {
  switch(val) {
  case VolumeShaperOperationFlag::REVERSE:
    return "REVERSE";
  case VolumeShaperOperationFlag::TERMINATE:
    return "TERMINATE";
  case VolumeShaperOperationFlag::JOIN:
    return "JOIN";
  case VolumeShaperOperationFlag::DELAY:
    return "DELAY";
  case VolumeShaperOperationFlag::CREATE_IF_NECESSARY:
    return "CREATE_IF_NECESSARY";
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
constexpr inline std::array<::android::media::VolumeShaperOperationFlag, 5> enum_values<::android::media::VolumeShaperOperationFlag> = {
  ::android::media::VolumeShaperOperationFlag::REVERSE,
  ::android::media::VolumeShaperOperationFlag::TERMINATE,
  ::android::media::VolumeShaperOperationFlag::JOIN,
  ::android::media::VolumeShaperOperationFlag::DELAY,
  ::android::media::VolumeShaperOperationFlag::CREATE_IF_NECESSARY,
};
#pragma clang diagnostic pop

}  // namespace internal

}  // namespace android
