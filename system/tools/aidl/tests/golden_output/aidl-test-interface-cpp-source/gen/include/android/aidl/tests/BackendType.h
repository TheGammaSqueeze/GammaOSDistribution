#pragma once

#include <array>
#include <binder/Enums.h>
#include <cstdint>
#include <string>

namespace android {

namespace aidl {

namespace tests {

enum class BackendType : int8_t {
  CPP = 0,
  JAVA = 1,
  NDK = 2,
  RUST = 3,
};

[[nodiscard]] static inline std::string toString(BackendType val) {
  switch(val) {
  case BackendType::CPP:
    return "CPP";
  case BackendType::JAVA:
    return "JAVA";
  case BackendType::NDK:
    return "NDK";
  case BackendType::RUST:
    return "RUST";
  default:
    return std::to_string(static_cast<int8_t>(val));
  }
}

}  // namespace tests

}  // namespace aidl

}  // namespace android
namespace android {

namespace internal {

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wc++17-extensions"
template <>
constexpr inline std::array<::android::aidl::tests::BackendType, 4> enum_values<::android::aidl::tests::BackendType> = {
  ::android::aidl::tests::BackendType::CPP,
  ::android::aidl::tests::BackendType::JAVA,
  ::android::aidl::tests::BackendType::NDK,
  ::android::aidl::tests::BackendType::RUST,
};
#pragma clang diagnostic pop

}  // namespace internal

}  // namespace android
