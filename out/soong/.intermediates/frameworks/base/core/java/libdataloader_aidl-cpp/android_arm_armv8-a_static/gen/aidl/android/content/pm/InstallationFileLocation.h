#pragma once

#include <array>
#include <binder/Enums.h>
#include <cstdint>
#include <string>

namespace android {

namespace content {

namespace pm {

enum class InstallationFileLocation : int32_t {
  UNKNOWN = -1,
  DATA_APP = 0,
  MEDIA_OBB = 1,
  MEDIA_DATA = 2,
};

[[nodiscard]] static inline std::string toString(InstallationFileLocation val) {
  switch(val) {
  case InstallationFileLocation::UNKNOWN:
    return "UNKNOWN";
  case InstallationFileLocation::DATA_APP:
    return "DATA_APP";
  case InstallationFileLocation::MEDIA_OBB:
    return "MEDIA_OBB";
  case InstallationFileLocation::MEDIA_DATA:
    return "MEDIA_DATA";
  default:
    return std::to_string(static_cast<int32_t>(val));
  }
}

}  // namespace pm

}  // namespace content

}  // namespace android
namespace android {

namespace internal {

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wc++17-extensions"
template <>
constexpr inline std::array<::android::content::pm::InstallationFileLocation, 4> enum_values<::android::content::pm::InstallationFileLocation> = {
  ::android::content::pm::InstallationFileLocation::UNKNOWN,
  ::android::content::pm::InstallationFileLocation::DATA_APP,
  ::android::content::pm::InstallationFileLocation::MEDIA_OBB,
  ::android::content::pm::InstallationFileLocation::MEDIA_DATA,
};
#pragma clang diagnostic pop

}  // namespace internal

}  // namespace android
