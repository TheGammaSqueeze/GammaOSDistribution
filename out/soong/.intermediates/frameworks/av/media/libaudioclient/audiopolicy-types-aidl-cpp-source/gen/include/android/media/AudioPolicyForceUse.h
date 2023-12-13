#pragma once

#include <array>
#include <binder/Enums.h>
#include <cstdint>
#include <string>

namespace android {

namespace media {

enum class AudioPolicyForceUse : int32_t {
  COMMUNICATION = 0,
  MEDIA = 1,
  RECORD = 2,
  DOCK = 3,
  SYSTEM = 4,
  HDMI_SYSTEM_AUDIO = 5,
  ENCODED_SURROUND = 6,
  VIBRATE_RINGING = 7,
};

[[nodiscard]] static inline std::string toString(AudioPolicyForceUse val) {
  switch(val) {
  case AudioPolicyForceUse::COMMUNICATION:
    return "COMMUNICATION";
  case AudioPolicyForceUse::MEDIA:
    return "MEDIA";
  case AudioPolicyForceUse::RECORD:
    return "RECORD";
  case AudioPolicyForceUse::DOCK:
    return "DOCK";
  case AudioPolicyForceUse::SYSTEM:
    return "SYSTEM";
  case AudioPolicyForceUse::HDMI_SYSTEM_AUDIO:
    return "HDMI_SYSTEM_AUDIO";
  case AudioPolicyForceUse::ENCODED_SURROUND:
    return "ENCODED_SURROUND";
  case AudioPolicyForceUse::VIBRATE_RINGING:
    return "VIBRATE_RINGING";
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
constexpr inline std::array<::android::media::AudioPolicyForceUse, 8> enum_values<::android::media::AudioPolicyForceUse> = {
  ::android::media::AudioPolicyForceUse::COMMUNICATION,
  ::android::media::AudioPolicyForceUse::MEDIA,
  ::android::media::AudioPolicyForceUse::RECORD,
  ::android::media::AudioPolicyForceUse::DOCK,
  ::android::media::AudioPolicyForceUse::SYSTEM,
  ::android::media::AudioPolicyForceUse::HDMI_SYSTEM_AUDIO,
  ::android::media::AudioPolicyForceUse::ENCODED_SURROUND,
  ::android::media::AudioPolicyForceUse::VIBRATE_RINGING,
};
#pragma clang diagnostic pop

}  // namespace internal

}  // namespace android
