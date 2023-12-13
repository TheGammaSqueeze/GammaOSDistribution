#pragma once

#include <array>
#include <binder/Enums.h>
#include <cstdint>
#include <string>

namespace android {

namespace media {

enum class AudioOutputFlags : int32_t {
  DIRECT = 0,
  PRIMARY = 1,
  FAST = 2,
  DEEP_BUFFER = 3,
  COMPRESS_OFFLOAD = 4,
  NON_BLOCKING = 5,
  HW_AV_SYNC = 6,
  TTS = 7,
  RAW = 8,
  SYNC = 9,
  IEC958_NONAUDIO = 10,
  DIRECT_PCM = 11,
  MMAP_NOIRQ = 12,
  VOIP_RX = 13,
  INCALL_MUSIC = 14,
  GAPLESS_OFFLOAD = 15,
};

[[nodiscard]] static inline std::string toString(AudioOutputFlags val) {
  switch(val) {
  case AudioOutputFlags::DIRECT:
    return "DIRECT";
  case AudioOutputFlags::PRIMARY:
    return "PRIMARY";
  case AudioOutputFlags::FAST:
    return "FAST";
  case AudioOutputFlags::DEEP_BUFFER:
    return "DEEP_BUFFER";
  case AudioOutputFlags::COMPRESS_OFFLOAD:
    return "COMPRESS_OFFLOAD";
  case AudioOutputFlags::NON_BLOCKING:
    return "NON_BLOCKING";
  case AudioOutputFlags::HW_AV_SYNC:
    return "HW_AV_SYNC";
  case AudioOutputFlags::TTS:
    return "TTS";
  case AudioOutputFlags::RAW:
    return "RAW";
  case AudioOutputFlags::SYNC:
    return "SYNC";
  case AudioOutputFlags::IEC958_NONAUDIO:
    return "IEC958_NONAUDIO";
  case AudioOutputFlags::DIRECT_PCM:
    return "DIRECT_PCM";
  case AudioOutputFlags::MMAP_NOIRQ:
    return "MMAP_NOIRQ";
  case AudioOutputFlags::VOIP_RX:
    return "VOIP_RX";
  case AudioOutputFlags::INCALL_MUSIC:
    return "INCALL_MUSIC";
  case AudioOutputFlags::GAPLESS_OFFLOAD:
    return "GAPLESS_OFFLOAD";
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
constexpr inline std::array<::android::media::AudioOutputFlags, 16> enum_values<::android::media::AudioOutputFlags> = {
  ::android::media::AudioOutputFlags::DIRECT,
  ::android::media::AudioOutputFlags::PRIMARY,
  ::android::media::AudioOutputFlags::FAST,
  ::android::media::AudioOutputFlags::DEEP_BUFFER,
  ::android::media::AudioOutputFlags::COMPRESS_OFFLOAD,
  ::android::media::AudioOutputFlags::NON_BLOCKING,
  ::android::media::AudioOutputFlags::HW_AV_SYNC,
  ::android::media::AudioOutputFlags::TTS,
  ::android::media::AudioOutputFlags::RAW,
  ::android::media::AudioOutputFlags::SYNC,
  ::android::media::AudioOutputFlags::IEC958_NONAUDIO,
  ::android::media::AudioOutputFlags::DIRECT_PCM,
  ::android::media::AudioOutputFlags::MMAP_NOIRQ,
  ::android::media::AudioOutputFlags::VOIP_RX,
  ::android::media::AudioOutputFlags::INCALL_MUSIC,
  ::android::media::AudioOutputFlags::GAPLESS_OFFLOAD,
};
#pragma clang diagnostic pop

}  // namespace internal

}  // namespace android
