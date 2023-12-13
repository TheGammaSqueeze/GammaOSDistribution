#pragma once

#include <array>
#include <binder/Enums.h>
#include <cstdint>
#include <string>

namespace android {

namespace media {

enum class AudioIoConfigEvent : int32_t {
  OUTPUT_REGISTERED = 0,
  OUTPUT_OPENED = 1,
  OUTPUT_CLOSED = 2,
  OUTPUT_CONFIG_CHANGED = 3,
  INPUT_REGISTERED = 4,
  INPUT_OPENED = 5,
  INPUT_CLOSED = 6,
  INPUT_CONFIG_CHANGED = 7,
  CLIENT_STARTED = 8,
};

[[nodiscard]] static inline std::string toString(AudioIoConfigEvent val) {
  switch(val) {
  case AudioIoConfigEvent::OUTPUT_REGISTERED:
    return "OUTPUT_REGISTERED";
  case AudioIoConfigEvent::OUTPUT_OPENED:
    return "OUTPUT_OPENED";
  case AudioIoConfigEvent::OUTPUT_CLOSED:
    return "OUTPUT_CLOSED";
  case AudioIoConfigEvent::OUTPUT_CONFIG_CHANGED:
    return "OUTPUT_CONFIG_CHANGED";
  case AudioIoConfigEvent::INPUT_REGISTERED:
    return "INPUT_REGISTERED";
  case AudioIoConfigEvent::INPUT_OPENED:
    return "INPUT_OPENED";
  case AudioIoConfigEvent::INPUT_CLOSED:
    return "INPUT_CLOSED";
  case AudioIoConfigEvent::INPUT_CONFIG_CHANGED:
    return "INPUT_CONFIG_CHANGED";
  case AudioIoConfigEvent::CLIENT_STARTED:
    return "CLIENT_STARTED";
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
constexpr inline std::array<::android::media::AudioIoConfigEvent, 9> enum_values<::android::media::AudioIoConfigEvent> = {
  ::android::media::AudioIoConfigEvent::OUTPUT_REGISTERED,
  ::android::media::AudioIoConfigEvent::OUTPUT_OPENED,
  ::android::media::AudioIoConfigEvent::OUTPUT_CLOSED,
  ::android::media::AudioIoConfigEvent::OUTPUT_CONFIG_CHANGED,
  ::android::media::AudioIoConfigEvent::INPUT_REGISTERED,
  ::android::media::AudioIoConfigEvent::INPUT_OPENED,
  ::android::media::AudioIoConfigEvent::INPUT_CLOSED,
  ::android::media::AudioIoConfigEvent::INPUT_CONFIG_CHANGED,
  ::android::media::AudioIoConfigEvent::CLIENT_STARTED,
};
#pragma clang diagnostic pop

}  // namespace internal

}  // namespace android
