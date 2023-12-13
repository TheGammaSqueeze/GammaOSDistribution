#pragma once

#include <array>
#include <binder/Enums.h>
#include <cstdint>
#include <string>

namespace android {

namespace hardware {

namespace security {

namespace keymint {

enum class TagType : int32_t {
  INVALID = 0,
  ENUM = 268435456,
  ENUM_REP = 536870912,
  UINT = 805306368,
  UINT_REP = 1073741824,
  ULONG = 1342177280,
  DATE = 1610612736,
  BOOL = 1879048192,
  BIGNUM = -2147483648,
  BYTES = -1879048192,
  ULONG_REP = -1610612736,
};

[[nodiscard]] static inline std::string toString(TagType val) {
  switch(val) {
  case TagType::INVALID:
    return "INVALID";
  case TagType::ENUM:
    return "ENUM";
  case TagType::ENUM_REP:
    return "ENUM_REP";
  case TagType::UINT:
    return "UINT";
  case TagType::UINT_REP:
    return "UINT_REP";
  case TagType::ULONG:
    return "ULONG";
  case TagType::DATE:
    return "DATE";
  case TagType::BOOL:
    return "BOOL";
  case TagType::BIGNUM:
    return "BIGNUM";
  case TagType::BYTES:
    return "BYTES";
  case TagType::ULONG_REP:
    return "ULONG_REP";
  default:
    return std::to_string(static_cast<int32_t>(val));
  }
}

}  // namespace keymint

}  // namespace security

}  // namespace hardware

}  // namespace android
namespace android {

namespace internal {

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wc++17-extensions"
template <>
constexpr inline std::array<::android::hardware::security::keymint::TagType, 11> enum_values<::android::hardware::security::keymint::TagType> = {
  ::android::hardware::security::keymint::TagType::INVALID,
  ::android::hardware::security::keymint::TagType::ENUM,
  ::android::hardware::security::keymint::TagType::ENUM_REP,
  ::android::hardware::security::keymint::TagType::UINT,
  ::android::hardware::security::keymint::TagType::UINT_REP,
  ::android::hardware::security::keymint::TagType::ULONG,
  ::android::hardware::security::keymint::TagType::DATE,
  ::android::hardware::security::keymint::TagType::BOOL,
  ::android::hardware::security::keymint::TagType::BIGNUM,
  ::android::hardware::security::keymint::TagType::BYTES,
  ::android::hardware::security::keymint::TagType::ULONG_REP,
};
#pragma clang diagnostic pop

}  // namespace internal

}  // namespace android
