#pragma once

#include <array>
#include <binder/Enums.h>
#include <cstdint>
#include <string>

namespace android {

namespace media {

enum class AudioPolicyForcedConfig : int32_t {
  NONE = 0,
  SPEAKER = 1,
  HEADPHONES = 2,
  BT_SCO = 3,
  BT_A2DP = 4,
  WIRED_ACCESSORY = 5,
  BT_CAR_DOCK = 6,
  BT_DESK_DOCK = 7,
  ANALOG_DOCK = 8,
  DIGITAL_DOCK = 9,
  NO_BT_A2DP = 10,
  SYSTEM_ENFORCED = 11,
  HDMI_SYSTEM_AUDIO_ENFORCED = 12,
  ENCODED_SURROUND_NEVER = 13,
  ENCODED_SURROUND_ALWAYS = 14,
  ENCODED_SURROUND_MANUAL = 15,
};

[[nodiscard]] static inline std::string toString(AudioPolicyForcedConfig val) {
  switch(val) {
  case AudioPolicyForcedConfig::NONE:
    return "NONE";
  case AudioPolicyForcedConfig::SPEAKER:
    return "SPEAKER";
  case AudioPolicyForcedConfig::HEADPHONES:
    return "HEADPHONES";
  case AudioPolicyForcedConfig::BT_SCO:
    return "BT_SCO";
  case AudioPolicyForcedConfig::BT_A2DP:
    return "BT_A2DP";
  case AudioPolicyForcedConfig::WIRED_ACCESSORY:
    return "WIRED_ACCESSORY";
  case AudioPolicyForcedConfig::BT_CAR_DOCK:
    return "BT_CAR_DOCK";
  case AudioPolicyForcedConfig::BT_DESK_DOCK:
    return "BT_DESK_DOCK";
  case AudioPolicyForcedConfig::ANALOG_DOCK:
    return "ANALOG_DOCK";
  case AudioPolicyForcedConfig::DIGITAL_DOCK:
    return "DIGITAL_DOCK";
  case AudioPolicyForcedConfig::NO_BT_A2DP:
    return "NO_BT_A2DP";
  case AudioPolicyForcedConfig::SYSTEM_ENFORCED:
    return "SYSTEM_ENFORCED";
  case AudioPolicyForcedConfig::HDMI_SYSTEM_AUDIO_ENFORCED:
    return "HDMI_SYSTEM_AUDIO_ENFORCED";
  case AudioPolicyForcedConfig::ENCODED_SURROUND_NEVER:
    return "ENCODED_SURROUND_NEVER";
  case AudioPolicyForcedConfig::ENCODED_SURROUND_ALWAYS:
    return "ENCODED_SURROUND_ALWAYS";
  case AudioPolicyForcedConfig::ENCODED_SURROUND_MANUAL:
    return "ENCODED_SURROUND_MANUAL";
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
constexpr inline std::array<::android::media::AudioPolicyForcedConfig, 16> enum_values<::android::media::AudioPolicyForcedConfig> = {
  ::android::media::AudioPolicyForcedConfig::NONE,
  ::android::media::AudioPolicyForcedConfig::SPEAKER,
  ::android::media::AudioPolicyForcedConfig::HEADPHONES,
  ::android::media::AudioPolicyForcedConfig::BT_SCO,
  ::android::media::AudioPolicyForcedConfig::BT_A2DP,
  ::android::media::AudioPolicyForcedConfig::WIRED_ACCESSORY,
  ::android::media::AudioPolicyForcedConfig::BT_CAR_DOCK,
  ::android::media::AudioPolicyForcedConfig::BT_DESK_DOCK,
  ::android::media::AudioPolicyForcedConfig::ANALOG_DOCK,
  ::android::media::AudioPolicyForcedConfig::DIGITAL_DOCK,
  ::android::media::AudioPolicyForcedConfig::NO_BT_A2DP,
  ::android::media::AudioPolicyForcedConfig::SYSTEM_ENFORCED,
  ::android::media::AudioPolicyForcedConfig::HDMI_SYSTEM_AUDIO_ENFORCED,
  ::android::media::AudioPolicyForcedConfig::ENCODED_SURROUND_NEVER,
  ::android::media::AudioPolicyForcedConfig::ENCODED_SURROUND_ALWAYS,
  ::android::media::AudioPolicyForcedConfig::ENCODED_SURROUND_MANUAL,
};
#pragma clang diagnostic pop

}  // namespace internal

}  // namespace android
