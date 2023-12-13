#pragma once

#include <array>
#include <binder/Enums.h>
#include <cstdint>
#include <string>

namespace android {

namespace media {

namespace audio {

namespace common {

enum class AudioChannelMask : int32_t {
  REPRESENTATION_POSITION = 0,
  REPRESENTATION_INDEX = 2,
  NONE = 0,
  INVALID = -1073741824,
  OUT_FRONT_LEFT = 1,
  OUT_FRONT_RIGHT = 2,
  OUT_FRONT_CENTER = 4,
  OUT_LOW_FREQUENCY = 8,
  OUT_BACK_LEFT = 16,
  OUT_BACK_RIGHT = 32,
  OUT_FRONT_LEFT_OF_CENTER = 64,
  OUT_FRONT_RIGHT_OF_CENTER = 128,
  OUT_BACK_CENTER = 256,
  OUT_SIDE_LEFT = 512,
  OUT_SIDE_RIGHT = 1024,
  OUT_TOP_CENTER = 2048,
  OUT_TOP_FRONT_LEFT = 4096,
  OUT_TOP_FRONT_CENTER = 8192,
  OUT_TOP_FRONT_RIGHT = 16384,
  OUT_TOP_BACK_LEFT = 32768,
  OUT_TOP_BACK_CENTER = 65536,
  OUT_TOP_BACK_RIGHT = 131072,
  OUT_TOP_SIDE_LEFT = 262144,
  OUT_TOP_SIDE_RIGHT = 524288,
  OUT_HAPTIC_A = 536870912,
  OUT_HAPTIC_B = 268435456,
  IN_LEFT = 4,
  IN_RIGHT = 8,
  IN_FRONT = 16,
  IN_BACK = 32,
  IN_LEFT_PROCESSED = 64,
  IN_RIGHT_PROCESSED = 128,
  IN_FRONT_PROCESSED = 256,
  IN_BACK_PROCESSED = 512,
  IN_PRESSURE = 1024,
  IN_X_AXIS = 2048,
  IN_Y_AXIS = 4096,
  IN_Z_AXIS = 8192,
  IN_BACK_LEFT = 65536,
  IN_BACK_RIGHT = 131072,
  IN_CENTER = 262144,
  IN_LOW_FREQUENCY = 1048576,
  IN_TOP_LEFT = 2097152,
  IN_TOP_RIGHT = 4194304,
  IN_VOICE_UPLINK = 16384,
  IN_VOICE_DNLINK = 32768,
};

[[nodiscard]] static inline std::string toString(AudioChannelMask val) {
  switch(val) {
  case AudioChannelMask::REPRESENTATION_POSITION:
    return "REPRESENTATION_POSITION";
  case AudioChannelMask::REPRESENTATION_INDEX:
    return "REPRESENTATION_INDEX";
  case AudioChannelMask::INVALID:
    return "INVALID";
  case AudioChannelMask::OUT_FRONT_LEFT:
    return "OUT_FRONT_LEFT";
  case AudioChannelMask::OUT_FRONT_CENTER:
    return "OUT_FRONT_CENTER";
  case AudioChannelMask::OUT_LOW_FREQUENCY:
    return "OUT_LOW_FREQUENCY";
  case AudioChannelMask::OUT_BACK_LEFT:
    return "OUT_BACK_LEFT";
  case AudioChannelMask::OUT_BACK_RIGHT:
    return "OUT_BACK_RIGHT";
  case AudioChannelMask::OUT_FRONT_LEFT_OF_CENTER:
    return "OUT_FRONT_LEFT_OF_CENTER";
  case AudioChannelMask::OUT_FRONT_RIGHT_OF_CENTER:
    return "OUT_FRONT_RIGHT_OF_CENTER";
  case AudioChannelMask::OUT_BACK_CENTER:
    return "OUT_BACK_CENTER";
  case AudioChannelMask::OUT_SIDE_LEFT:
    return "OUT_SIDE_LEFT";
  case AudioChannelMask::OUT_SIDE_RIGHT:
    return "OUT_SIDE_RIGHT";
  case AudioChannelMask::OUT_TOP_CENTER:
    return "OUT_TOP_CENTER";
  case AudioChannelMask::OUT_TOP_FRONT_LEFT:
    return "OUT_TOP_FRONT_LEFT";
  case AudioChannelMask::OUT_TOP_FRONT_CENTER:
    return "OUT_TOP_FRONT_CENTER";
  case AudioChannelMask::OUT_TOP_FRONT_RIGHT:
    return "OUT_TOP_FRONT_RIGHT";
  case AudioChannelMask::OUT_TOP_BACK_LEFT:
    return "OUT_TOP_BACK_LEFT";
  case AudioChannelMask::OUT_TOP_BACK_CENTER:
    return "OUT_TOP_BACK_CENTER";
  case AudioChannelMask::OUT_TOP_BACK_RIGHT:
    return "OUT_TOP_BACK_RIGHT";
  case AudioChannelMask::OUT_TOP_SIDE_LEFT:
    return "OUT_TOP_SIDE_LEFT";
  case AudioChannelMask::OUT_TOP_SIDE_RIGHT:
    return "OUT_TOP_SIDE_RIGHT";
  case AudioChannelMask::OUT_HAPTIC_A:
    return "OUT_HAPTIC_A";
  case AudioChannelMask::OUT_HAPTIC_B:
    return "OUT_HAPTIC_B";
  case AudioChannelMask::IN_LOW_FREQUENCY:
    return "IN_LOW_FREQUENCY";
  case AudioChannelMask::IN_TOP_LEFT:
    return "IN_TOP_LEFT";
  case AudioChannelMask::IN_TOP_RIGHT:
    return "IN_TOP_RIGHT";
  default:
    return std::to_string(static_cast<int32_t>(val));
  }
}

}  // namespace common

}  // namespace audio

}  // namespace media

}  // namespace android
namespace android {

namespace internal {

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wc++17-extensions"
template <>
constexpr inline std::array<::android::media::audio::common::AudioChannelMask, 46> enum_values<::android::media::audio::common::AudioChannelMask> = {
  ::android::media::audio::common::AudioChannelMask::REPRESENTATION_POSITION,
  ::android::media::audio::common::AudioChannelMask::REPRESENTATION_INDEX,
  ::android::media::audio::common::AudioChannelMask::NONE,
  ::android::media::audio::common::AudioChannelMask::INVALID,
  ::android::media::audio::common::AudioChannelMask::OUT_FRONT_LEFT,
  ::android::media::audio::common::AudioChannelMask::OUT_FRONT_RIGHT,
  ::android::media::audio::common::AudioChannelMask::OUT_FRONT_CENTER,
  ::android::media::audio::common::AudioChannelMask::OUT_LOW_FREQUENCY,
  ::android::media::audio::common::AudioChannelMask::OUT_BACK_LEFT,
  ::android::media::audio::common::AudioChannelMask::OUT_BACK_RIGHT,
  ::android::media::audio::common::AudioChannelMask::OUT_FRONT_LEFT_OF_CENTER,
  ::android::media::audio::common::AudioChannelMask::OUT_FRONT_RIGHT_OF_CENTER,
  ::android::media::audio::common::AudioChannelMask::OUT_BACK_CENTER,
  ::android::media::audio::common::AudioChannelMask::OUT_SIDE_LEFT,
  ::android::media::audio::common::AudioChannelMask::OUT_SIDE_RIGHT,
  ::android::media::audio::common::AudioChannelMask::OUT_TOP_CENTER,
  ::android::media::audio::common::AudioChannelMask::OUT_TOP_FRONT_LEFT,
  ::android::media::audio::common::AudioChannelMask::OUT_TOP_FRONT_CENTER,
  ::android::media::audio::common::AudioChannelMask::OUT_TOP_FRONT_RIGHT,
  ::android::media::audio::common::AudioChannelMask::OUT_TOP_BACK_LEFT,
  ::android::media::audio::common::AudioChannelMask::OUT_TOP_BACK_CENTER,
  ::android::media::audio::common::AudioChannelMask::OUT_TOP_BACK_RIGHT,
  ::android::media::audio::common::AudioChannelMask::OUT_TOP_SIDE_LEFT,
  ::android::media::audio::common::AudioChannelMask::OUT_TOP_SIDE_RIGHT,
  ::android::media::audio::common::AudioChannelMask::OUT_HAPTIC_A,
  ::android::media::audio::common::AudioChannelMask::OUT_HAPTIC_B,
  ::android::media::audio::common::AudioChannelMask::IN_LEFT,
  ::android::media::audio::common::AudioChannelMask::IN_RIGHT,
  ::android::media::audio::common::AudioChannelMask::IN_FRONT,
  ::android::media::audio::common::AudioChannelMask::IN_BACK,
  ::android::media::audio::common::AudioChannelMask::IN_LEFT_PROCESSED,
  ::android::media::audio::common::AudioChannelMask::IN_RIGHT_PROCESSED,
  ::android::media::audio::common::AudioChannelMask::IN_FRONT_PROCESSED,
  ::android::media::audio::common::AudioChannelMask::IN_BACK_PROCESSED,
  ::android::media::audio::common::AudioChannelMask::IN_PRESSURE,
  ::android::media::audio::common::AudioChannelMask::IN_X_AXIS,
  ::android::media::audio::common::AudioChannelMask::IN_Y_AXIS,
  ::android::media::audio::common::AudioChannelMask::IN_Z_AXIS,
  ::android::media::audio::common::AudioChannelMask::IN_BACK_LEFT,
  ::android::media::audio::common::AudioChannelMask::IN_BACK_RIGHT,
  ::android::media::audio::common::AudioChannelMask::IN_CENTER,
  ::android::media::audio::common::AudioChannelMask::IN_LOW_FREQUENCY,
  ::android::media::audio::common::AudioChannelMask::IN_TOP_LEFT,
  ::android::media::audio::common::AudioChannelMask::IN_TOP_RIGHT,
  ::android::media::audio::common::AudioChannelMask::IN_VOICE_UPLINK,
  ::android::media::audio::common::AudioChannelMask::IN_VOICE_DNLINK,
};
#pragma clang diagnostic pop

}  // namespace internal

}  // namespace android
