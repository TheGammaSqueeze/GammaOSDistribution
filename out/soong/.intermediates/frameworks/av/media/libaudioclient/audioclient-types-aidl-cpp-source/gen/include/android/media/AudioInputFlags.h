#pragma once

#include <array>
#include <binder/Enums.h>
#include <cstdint>
#include <string>

namespace android {

namespace media {

enum class AudioInputFlags : int32_t {
  FAST = 0,
  HW_HOTWORD = 1,
  RAW = 2,
  SYNC = 3,
  MMAP_NOIRQ = 4,
  VOIP_TX = 5,
  HW_AV_SYNC = 6,
  DIRECT = 7,
};

[[nodiscard]] static inline std::string toString(AudioInputFlags val) {
  switch(val) {
  case AudioInputFlags::FAST:
    return "FAST";
  case AudioInputFlags::HW_HOTWORD:
    return "HW_HOTWORD";
  case AudioInputFlags::RAW:
    return "RAW";
  case AudioInputFlags::SYNC:
    return "SYNC";
  case AudioInputFlags::MMAP_NOIRQ:
    return "MMAP_NOIRQ";
  case AudioInputFlags::VOIP_TX:
    return "VOIP_TX";
  case AudioInputFlags::HW_AV_SYNC:
    return "HW_AV_SYNC";
  case AudioInputFlags::DIRECT:
    return "DIRECT";
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
constexpr inline std::array<::android::media::AudioInputFlags, 8> enum_values<::android::media::AudioInputFlags> = {
  ::android::media::AudioInputFlags::FAST,
  ::android::media::AudioInputFlags::HW_HOTWORD,
  ::android::media::AudioInputFlags::RAW,
  ::android::media::AudioInputFlags::SYNC,
  ::android::media::AudioInputFlags::MMAP_NOIRQ,
  ::android::media::AudioInputFlags::VOIP_TX,
  ::android::media::AudioInputFlags::HW_AV_SYNC,
  ::android::media::AudioInputFlags::DIRECT,
};
#pragma clang diagnostic pop

}  // namespace internal

}  // namespace android
