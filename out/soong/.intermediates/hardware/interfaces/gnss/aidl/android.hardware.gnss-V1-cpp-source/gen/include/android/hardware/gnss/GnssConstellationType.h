#pragma once

#include <array>
#include <binder/Enums.h>
#include <cstdint>
#include <string>

namespace android {

namespace hardware {

namespace gnss {

enum class GnssConstellationType : int32_t {
  UNKNOWN = 0,
  GPS = 1,
  SBAS = 2,
  GLONASS = 3,
  QZSS = 4,
  BEIDOU = 5,
  GALILEO = 6,
  IRNSS = 7,
};

[[nodiscard]] static inline std::string toString(GnssConstellationType val) {
  switch(val) {
  case GnssConstellationType::UNKNOWN:
    return "UNKNOWN";
  case GnssConstellationType::GPS:
    return "GPS";
  case GnssConstellationType::SBAS:
    return "SBAS";
  case GnssConstellationType::GLONASS:
    return "GLONASS";
  case GnssConstellationType::QZSS:
    return "QZSS";
  case GnssConstellationType::BEIDOU:
    return "BEIDOU";
  case GnssConstellationType::GALILEO:
    return "GALILEO";
  case GnssConstellationType::IRNSS:
    return "IRNSS";
  default:
    return std::to_string(static_cast<int32_t>(val));
  }
}

}  // namespace gnss

}  // namespace hardware

}  // namespace android
namespace android {

namespace internal {

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wc++17-extensions"
template <>
constexpr inline std::array<::android::hardware::gnss::GnssConstellationType, 8> enum_values<::android::hardware::gnss::GnssConstellationType> = {
  ::android::hardware::gnss::GnssConstellationType::UNKNOWN,
  ::android::hardware::gnss::GnssConstellationType::GPS,
  ::android::hardware::gnss::GnssConstellationType::SBAS,
  ::android::hardware::gnss::GnssConstellationType::GLONASS,
  ::android::hardware::gnss::GnssConstellationType::QZSS,
  ::android::hardware::gnss::GnssConstellationType::BEIDOU,
  ::android::hardware::gnss::GnssConstellationType::GALILEO,
  ::android::hardware::gnss::GnssConstellationType::IRNSS,
};
#pragma clang diagnostic pop

}  // namespace internal

}  // namespace android
