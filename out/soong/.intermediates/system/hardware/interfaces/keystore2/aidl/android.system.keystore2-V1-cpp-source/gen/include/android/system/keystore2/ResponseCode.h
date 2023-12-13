#pragma once

#include <array>
#include <binder/Enums.h>
#include <cstdint>
#include <string>

namespace android {

namespace system {

namespace keystore2 {

enum class ResponseCode : int32_t {
  LOCKED = 2,
  UNINITIALIZED = 3,
  SYSTEM_ERROR = 4,
  PERMISSION_DENIED = 6,
  KEY_NOT_FOUND = 7,
  VALUE_CORRUPTED = 8,
  KEY_PERMANENTLY_INVALIDATED = 17,
  BACKEND_BUSY = 18,
  OPERATION_BUSY = 19,
  INVALID_ARGUMENT = 20,
  TOO_MUCH_DATA = 21,
  OUT_OF_KEYS = 22,
};

[[nodiscard]] static inline std::string toString(ResponseCode val) {
  switch(val) {
  case ResponseCode::LOCKED:
    return "LOCKED";
  case ResponseCode::UNINITIALIZED:
    return "UNINITIALIZED";
  case ResponseCode::SYSTEM_ERROR:
    return "SYSTEM_ERROR";
  case ResponseCode::PERMISSION_DENIED:
    return "PERMISSION_DENIED";
  case ResponseCode::KEY_NOT_FOUND:
    return "KEY_NOT_FOUND";
  case ResponseCode::VALUE_CORRUPTED:
    return "VALUE_CORRUPTED";
  case ResponseCode::KEY_PERMANENTLY_INVALIDATED:
    return "KEY_PERMANENTLY_INVALIDATED";
  case ResponseCode::BACKEND_BUSY:
    return "BACKEND_BUSY";
  case ResponseCode::OPERATION_BUSY:
    return "OPERATION_BUSY";
  case ResponseCode::INVALID_ARGUMENT:
    return "INVALID_ARGUMENT";
  case ResponseCode::TOO_MUCH_DATA:
    return "TOO_MUCH_DATA";
  case ResponseCode::OUT_OF_KEYS:
    return "OUT_OF_KEYS";
  default:
    return std::to_string(static_cast<int32_t>(val));
  }
}

}  // namespace keystore2

}  // namespace system

}  // namespace android
namespace android {

namespace internal {

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wc++17-extensions"
template <>
constexpr inline std::array<::android::system::keystore2::ResponseCode, 12> enum_values<::android::system::keystore2::ResponseCode> = {
  ::android::system::keystore2::ResponseCode::LOCKED,
  ::android::system::keystore2::ResponseCode::UNINITIALIZED,
  ::android::system::keystore2::ResponseCode::SYSTEM_ERROR,
  ::android::system::keystore2::ResponseCode::PERMISSION_DENIED,
  ::android::system::keystore2::ResponseCode::KEY_NOT_FOUND,
  ::android::system::keystore2::ResponseCode::VALUE_CORRUPTED,
  ::android::system::keystore2::ResponseCode::KEY_PERMANENTLY_INVALIDATED,
  ::android::system::keystore2::ResponseCode::BACKEND_BUSY,
  ::android::system::keystore2::ResponseCode::OPERATION_BUSY,
  ::android::system::keystore2::ResponseCode::INVALID_ARGUMENT,
  ::android::system::keystore2::ResponseCode::TOO_MUCH_DATA,
  ::android::system::keystore2::ResponseCode::OUT_OF_KEYS,
};
#pragma clang diagnostic pop

}  // namespace internal

}  // namespace android
