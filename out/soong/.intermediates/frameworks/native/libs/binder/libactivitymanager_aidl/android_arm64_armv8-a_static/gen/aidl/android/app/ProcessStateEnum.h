#pragma once

#include <array>
#include <binder/Enums.h>
#include <cstdint>
#include <string>

namespace android {

namespace app {

enum class ProcessStateEnum : int32_t {
  UNKNOWN = -1,
  PERSISTENT = 0,
  PERSISTENT_UI = 1,
  TOP = 2,
  BOUND_TOP = 3,
  FOREGROUND_SERVICE = 4,
  BOUND_FOREGROUND_SERVICE = 5,
  IMPORTANT_FOREGROUND = 6,
  IMPORTANT_BACKGROUND = 7,
  TRANSIENT_BACKGROUND = 8,
  BACKUP = 9,
  SERVICE = 10,
  RECEIVER = 11,
  TOP_SLEEPING = 12,
  HEAVY_WEIGHT = 13,
  HOME = 14,
  LAST_ACTIVITY = 15,
  CACHED_ACTIVITY = 16,
  CACHED_ACTIVITY_CLIENT = 17,
  CACHED_RECENT = 18,
  CACHED_EMPTY = 19,
  NONEXISTENT = 20,
};

[[nodiscard]] static inline std::string toString(ProcessStateEnum val) {
  switch(val) {
  case ProcessStateEnum::UNKNOWN:
    return "UNKNOWN";
  case ProcessStateEnum::PERSISTENT:
    return "PERSISTENT";
  case ProcessStateEnum::PERSISTENT_UI:
    return "PERSISTENT_UI";
  case ProcessStateEnum::TOP:
    return "TOP";
  case ProcessStateEnum::BOUND_TOP:
    return "BOUND_TOP";
  case ProcessStateEnum::FOREGROUND_SERVICE:
    return "FOREGROUND_SERVICE";
  case ProcessStateEnum::BOUND_FOREGROUND_SERVICE:
    return "BOUND_FOREGROUND_SERVICE";
  case ProcessStateEnum::IMPORTANT_FOREGROUND:
    return "IMPORTANT_FOREGROUND";
  case ProcessStateEnum::IMPORTANT_BACKGROUND:
    return "IMPORTANT_BACKGROUND";
  case ProcessStateEnum::TRANSIENT_BACKGROUND:
    return "TRANSIENT_BACKGROUND";
  case ProcessStateEnum::BACKUP:
    return "BACKUP";
  case ProcessStateEnum::SERVICE:
    return "SERVICE";
  case ProcessStateEnum::RECEIVER:
    return "RECEIVER";
  case ProcessStateEnum::TOP_SLEEPING:
    return "TOP_SLEEPING";
  case ProcessStateEnum::HEAVY_WEIGHT:
    return "HEAVY_WEIGHT";
  case ProcessStateEnum::HOME:
    return "HOME";
  case ProcessStateEnum::LAST_ACTIVITY:
    return "LAST_ACTIVITY";
  case ProcessStateEnum::CACHED_ACTIVITY:
    return "CACHED_ACTIVITY";
  case ProcessStateEnum::CACHED_ACTIVITY_CLIENT:
    return "CACHED_ACTIVITY_CLIENT";
  case ProcessStateEnum::CACHED_RECENT:
    return "CACHED_RECENT";
  case ProcessStateEnum::CACHED_EMPTY:
    return "CACHED_EMPTY";
  case ProcessStateEnum::NONEXISTENT:
    return "NONEXISTENT";
  default:
    return std::to_string(static_cast<int32_t>(val));
  }
}

}  // namespace app

}  // namespace android
namespace android {

namespace internal {

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wc++17-extensions"
template <>
constexpr inline std::array<::android::app::ProcessStateEnum, 22> enum_values<::android::app::ProcessStateEnum> = {
  ::android::app::ProcessStateEnum::UNKNOWN,
  ::android::app::ProcessStateEnum::PERSISTENT,
  ::android::app::ProcessStateEnum::PERSISTENT_UI,
  ::android::app::ProcessStateEnum::TOP,
  ::android::app::ProcessStateEnum::BOUND_TOP,
  ::android::app::ProcessStateEnum::FOREGROUND_SERVICE,
  ::android::app::ProcessStateEnum::BOUND_FOREGROUND_SERVICE,
  ::android::app::ProcessStateEnum::IMPORTANT_FOREGROUND,
  ::android::app::ProcessStateEnum::IMPORTANT_BACKGROUND,
  ::android::app::ProcessStateEnum::TRANSIENT_BACKGROUND,
  ::android::app::ProcessStateEnum::BACKUP,
  ::android::app::ProcessStateEnum::SERVICE,
  ::android::app::ProcessStateEnum::RECEIVER,
  ::android::app::ProcessStateEnum::TOP_SLEEPING,
  ::android::app::ProcessStateEnum::HEAVY_WEIGHT,
  ::android::app::ProcessStateEnum::HOME,
  ::android::app::ProcessStateEnum::LAST_ACTIVITY,
  ::android::app::ProcessStateEnum::CACHED_ACTIVITY,
  ::android::app::ProcessStateEnum::CACHED_ACTIVITY_CLIENT,
  ::android::app::ProcessStateEnum::CACHED_RECENT,
  ::android::app::ProcessStateEnum::CACHED_EMPTY,
  ::android::app::ProcessStateEnum::NONEXISTENT,
};
#pragma clang diagnostic pop

}  // namespace internal

}  // namespace android
