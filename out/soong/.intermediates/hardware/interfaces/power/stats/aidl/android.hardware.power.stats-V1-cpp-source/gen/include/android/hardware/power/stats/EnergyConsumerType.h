#pragma once

#include <array>
#include <binder/Enums.h>
#include <cstdint>
#include <string>

namespace android {

namespace hardware {

namespace power {

namespace stats {

enum class EnergyConsumerType : int8_t {
  OTHER = 0,
  BLUETOOTH = 1,
  CPU_CLUSTER = 2,
  DISPLAY = 3,
  GNSS = 4,
  MOBILE_RADIO = 5,
  WIFI = 6,
};

[[nodiscard]] static inline std::string toString(EnergyConsumerType val) {
  switch(val) {
  case EnergyConsumerType::OTHER:
    return "OTHER";
  case EnergyConsumerType::BLUETOOTH:
    return "BLUETOOTH";
  case EnergyConsumerType::CPU_CLUSTER:
    return "CPU_CLUSTER";
  case EnergyConsumerType::DISPLAY:
    return "DISPLAY";
  case EnergyConsumerType::GNSS:
    return "GNSS";
  case EnergyConsumerType::MOBILE_RADIO:
    return "MOBILE_RADIO";
  case EnergyConsumerType::WIFI:
    return "WIFI";
  default:
    return std::to_string(static_cast<int8_t>(val));
  }
}

}  // namespace stats

}  // namespace power

}  // namespace hardware

}  // namespace android
namespace android {

namespace internal {

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wc++17-extensions"
template <>
constexpr inline std::array<::android::hardware::power::stats::EnergyConsumerType, 7> enum_values<::android::hardware::power::stats::EnergyConsumerType> = {
  ::android::hardware::power::stats::EnergyConsumerType::OTHER,
  ::android::hardware::power::stats::EnergyConsumerType::BLUETOOTH,
  ::android::hardware::power::stats::EnergyConsumerType::CPU_CLUSTER,
  ::android::hardware::power::stats::EnergyConsumerType::DISPLAY,
  ::android::hardware::power::stats::EnergyConsumerType::GNSS,
  ::android::hardware::power::stats::EnergyConsumerType::MOBILE_RADIO,
  ::android::hardware::power::stats::EnergyConsumerType::WIFI,
};
#pragma clang diagnostic pop

}  // namespace internal

}  // namespace android
