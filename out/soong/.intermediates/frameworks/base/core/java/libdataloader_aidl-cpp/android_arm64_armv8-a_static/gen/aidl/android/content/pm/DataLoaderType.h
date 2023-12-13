#pragma once

#include <array>
#include <binder/Enums.h>
#include <cstdint>
#include <string>

namespace android {

namespace content {

namespace pm {

enum class DataLoaderType : int32_t {
  NONE = 0,
  STREAMING = 1,
  INCREMENTAL = 2,
};

[[nodiscard]] static inline std::string toString(DataLoaderType val) {
  switch(val) {
  case DataLoaderType::NONE:
    return "NONE";
  case DataLoaderType::STREAMING:
    return "STREAMING";
  case DataLoaderType::INCREMENTAL:
    return "INCREMENTAL";
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
constexpr inline std::array<::android::content::pm::DataLoaderType, 3> enum_values<::android::content::pm::DataLoaderType> = {
  ::android::content::pm::DataLoaderType::NONE,
  ::android::content::pm::DataLoaderType::STREAMING,
  ::android::content::pm::DataLoaderType::INCREMENTAL,
};
#pragma clang diagnostic pop

}  // namespace internal

}  // namespace android
