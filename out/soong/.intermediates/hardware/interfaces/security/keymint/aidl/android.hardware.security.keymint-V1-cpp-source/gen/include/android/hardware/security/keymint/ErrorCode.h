#pragma once

#include <array>
#include <binder/Enums.h>
#include <cstdint>
#include <string>

namespace android {

namespace hardware {

namespace security {

namespace keymint {

enum class ErrorCode : int32_t {
  OK = 0,
  ROOT_OF_TRUST_ALREADY_SET = -1,
  UNSUPPORTED_PURPOSE = -2,
  INCOMPATIBLE_PURPOSE = -3,
  UNSUPPORTED_ALGORITHM = -4,
  INCOMPATIBLE_ALGORITHM = -5,
  UNSUPPORTED_KEY_SIZE = -6,
  UNSUPPORTED_BLOCK_MODE = -7,
  INCOMPATIBLE_BLOCK_MODE = -8,
  UNSUPPORTED_MAC_LENGTH = -9,
  UNSUPPORTED_PADDING_MODE = -10,
  INCOMPATIBLE_PADDING_MODE = -11,
  UNSUPPORTED_DIGEST = -12,
  INCOMPATIBLE_DIGEST = -13,
  INVALID_EXPIRATION_TIME = -14,
  INVALID_USER_ID = -15,
  INVALID_AUTHORIZATION_TIMEOUT = -16,
  UNSUPPORTED_KEY_FORMAT = -17,
  INCOMPATIBLE_KEY_FORMAT = -18,
  UNSUPPORTED_KEY_ENCRYPTION_ALGORITHM = -19,
  UNSUPPORTED_KEY_VERIFICATION_ALGORITHM = -20,
  INVALID_INPUT_LENGTH = -21,
  KEY_EXPORT_OPTIONS_INVALID = -22,
  DELEGATION_NOT_ALLOWED = -23,
  KEY_NOT_YET_VALID = -24,
  KEY_EXPIRED = -25,
  KEY_USER_NOT_AUTHENTICATED = -26,
  OUTPUT_PARAMETER_NULL = -27,
  INVALID_OPERATION_HANDLE = -28,
  INSUFFICIENT_BUFFER_SPACE = -29,
  VERIFICATION_FAILED = -30,
  TOO_MANY_OPERATIONS = -31,
  UNEXPECTED_NULL_POINTER = -32,
  INVALID_KEY_BLOB = -33,
  IMPORTED_KEY_NOT_ENCRYPTED = -34,
  IMPORTED_KEY_DECRYPTION_FAILED = -35,
  IMPORTED_KEY_NOT_SIGNED = -36,
  IMPORTED_KEY_VERIFICATION_FAILED = -37,
  INVALID_ARGUMENT = -38,
  UNSUPPORTED_TAG = -39,
  INVALID_TAG = -40,
  MEMORY_ALLOCATION_FAILED = -41,
  IMPORT_PARAMETER_MISMATCH = -44,
  SECURE_HW_ACCESS_DENIED = -45,
  OPERATION_CANCELLED = -46,
  CONCURRENT_ACCESS_CONFLICT = -47,
  SECURE_HW_BUSY = -48,
  SECURE_HW_COMMUNICATION_FAILED = -49,
  UNSUPPORTED_EC_FIELD = -50,
  MISSING_NONCE = -51,
  INVALID_NONCE = -52,
  MISSING_MAC_LENGTH = -53,
  KEY_RATE_LIMIT_EXCEEDED = -54,
  CALLER_NONCE_PROHIBITED = -55,
  KEY_MAX_OPS_EXCEEDED = -56,
  INVALID_MAC_LENGTH = -57,
  MISSING_MIN_MAC_LENGTH = -58,
  UNSUPPORTED_MIN_MAC_LENGTH = -59,
  UNSUPPORTED_KDF = -60,
  UNSUPPORTED_EC_CURVE = -61,
  KEY_REQUIRES_UPGRADE = -62,
  ATTESTATION_CHALLENGE_MISSING = -63,
  KEYMINT_NOT_CONFIGURED = -64,
  ATTESTATION_APPLICATION_ID_MISSING = -65,
  CANNOT_ATTEST_IDS = -66,
  ROLLBACK_RESISTANCE_UNAVAILABLE = -67,
  HARDWARE_TYPE_UNAVAILABLE = -68,
  PROOF_OF_PRESENCE_REQUIRED = -69,
  CONCURRENT_PROOF_OF_PRESENCE_REQUESTED = -70,
  NO_USER_CONFIRMATION = -71,
  DEVICE_LOCKED = -72,
  EARLY_BOOT_ENDED = -73,
  ATTESTATION_KEYS_NOT_PROVISIONED = -74,
  ATTESTATION_IDS_NOT_PROVISIONED = -75,
  INVALID_OPERATION = -76,
  STORAGE_KEY_UNSUPPORTED = -77,
  INCOMPATIBLE_MGF_DIGEST = -78,
  UNSUPPORTED_MGF_DIGEST = -79,
  MISSING_NOT_BEFORE = -80,
  MISSING_NOT_AFTER = -81,
  MISSING_ISSUER_SUBJECT = -82,
  INVALID_ISSUER_SUBJECT = -83,
  BOOT_LEVEL_EXCEEDED = -84,
  HARDWARE_NOT_YET_AVAILABLE = -85,
  UNIMPLEMENTED = -100,
  VERSION_MISMATCH = -101,
  UNKNOWN_ERROR = -1000,
};

[[nodiscard]] static inline std::string toString(ErrorCode val) {
  switch(val) {
  case ErrorCode::OK:
    return "OK";
  case ErrorCode::ROOT_OF_TRUST_ALREADY_SET:
    return "ROOT_OF_TRUST_ALREADY_SET";
  case ErrorCode::UNSUPPORTED_PURPOSE:
    return "UNSUPPORTED_PURPOSE";
  case ErrorCode::INCOMPATIBLE_PURPOSE:
    return "INCOMPATIBLE_PURPOSE";
  case ErrorCode::UNSUPPORTED_ALGORITHM:
    return "UNSUPPORTED_ALGORITHM";
  case ErrorCode::INCOMPATIBLE_ALGORITHM:
    return "INCOMPATIBLE_ALGORITHM";
  case ErrorCode::UNSUPPORTED_KEY_SIZE:
    return "UNSUPPORTED_KEY_SIZE";
  case ErrorCode::UNSUPPORTED_BLOCK_MODE:
    return "UNSUPPORTED_BLOCK_MODE";
  case ErrorCode::INCOMPATIBLE_BLOCK_MODE:
    return "INCOMPATIBLE_BLOCK_MODE";
  case ErrorCode::UNSUPPORTED_MAC_LENGTH:
    return "UNSUPPORTED_MAC_LENGTH";
  case ErrorCode::UNSUPPORTED_PADDING_MODE:
    return "UNSUPPORTED_PADDING_MODE";
  case ErrorCode::INCOMPATIBLE_PADDING_MODE:
    return "INCOMPATIBLE_PADDING_MODE";
  case ErrorCode::UNSUPPORTED_DIGEST:
    return "UNSUPPORTED_DIGEST";
  case ErrorCode::INCOMPATIBLE_DIGEST:
    return "INCOMPATIBLE_DIGEST";
  case ErrorCode::INVALID_EXPIRATION_TIME:
    return "INVALID_EXPIRATION_TIME";
  case ErrorCode::INVALID_USER_ID:
    return "INVALID_USER_ID";
  case ErrorCode::INVALID_AUTHORIZATION_TIMEOUT:
    return "INVALID_AUTHORIZATION_TIMEOUT";
  case ErrorCode::UNSUPPORTED_KEY_FORMAT:
    return "UNSUPPORTED_KEY_FORMAT";
  case ErrorCode::INCOMPATIBLE_KEY_FORMAT:
    return "INCOMPATIBLE_KEY_FORMAT";
  case ErrorCode::UNSUPPORTED_KEY_ENCRYPTION_ALGORITHM:
    return "UNSUPPORTED_KEY_ENCRYPTION_ALGORITHM";
  case ErrorCode::UNSUPPORTED_KEY_VERIFICATION_ALGORITHM:
    return "UNSUPPORTED_KEY_VERIFICATION_ALGORITHM";
  case ErrorCode::INVALID_INPUT_LENGTH:
    return "INVALID_INPUT_LENGTH";
  case ErrorCode::KEY_EXPORT_OPTIONS_INVALID:
    return "KEY_EXPORT_OPTIONS_INVALID";
  case ErrorCode::DELEGATION_NOT_ALLOWED:
    return "DELEGATION_NOT_ALLOWED";
  case ErrorCode::KEY_NOT_YET_VALID:
    return "KEY_NOT_YET_VALID";
  case ErrorCode::KEY_EXPIRED:
    return "KEY_EXPIRED";
  case ErrorCode::KEY_USER_NOT_AUTHENTICATED:
    return "KEY_USER_NOT_AUTHENTICATED";
  case ErrorCode::OUTPUT_PARAMETER_NULL:
    return "OUTPUT_PARAMETER_NULL";
  case ErrorCode::INVALID_OPERATION_HANDLE:
    return "INVALID_OPERATION_HANDLE";
  case ErrorCode::INSUFFICIENT_BUFFER_SPACE:
    return "INSUFFICIENT_BUFFER_SPACE";
  case ErrorCode::VERIFICATION_FAILED:
    return "VERIFICATION_FAILED";
  case ErrorCode::TOO_MANY_OPERATIONS:
    return "TOO_MANY_OPERATIONS";
  case ErrorCode::UNEXPECTED_NULL_POINTER:
    return "UNEXPECTED_NULL_POINTER";
  case ErrorCode::INVALID_KEY_BLOB:
    return "INVALID_KEY_BLOB";
  case ErrorCode::IMPORTED_KEY_NOT_ENCRYPTED:
    return "IMPORTED_KEY_NOT_ENCRYPTED";
  case ErrorCode::IMPORTED_KEY_DECRYPTION_FAILED:
    return "IMPORTED_KEY_DECRYPTION_FAILED";
  case ErrorCode::IMPORTED_KEY_NOT_SIGNED:
    return "IMPORTED_KEY_NOT_SIGNED";
  case ErrorCode::IMPORTED_KEY_VERIFICATION_FAILED:
    return "IMPORTED_KEY_VERIFICATION_FAILED";
  case ErrorCode::INVALID_ARGUMENT:
    return "INVALID_ARGUMENT";
  case ErrorCode::UNSUPPORTED_TAG:
    return "UNSUPPORTED_TAG";
  case ErrorCode::INVALID_TAG:
    return "INVALID_TAG";
  case ErrorCode::MEMORY_ALLOCATION_FAILED:
    return "MEMORY_ALLOCATION_FAILED";
  case ErrorCode::IMPORT_PARAMETER_MISMATCH:
    return "IMPORT_PARAMETER_MISMATCH";
  case ErrorCode::SECURE_HW_ACCESS_DENIED:
    return "SECURE_HW_ACCESS_DENIED";
  case ErrorCode::OPERATION_CANCELLED:
    return "OPERATION_CANCELLED";
  case ErrorCode::CONCURRENT_ACCESS_CONFLICT:
    return "CONCURRENT_ACCESS_CONFLICT";
  case ErrorCode::SECURE_HW_BUSY:
    return "SECURE_HW_BUSY";
  case ErrorCode::SECURE_HW_COMMUNICATION_FAILED:
    return "SECURE_HW_COMMUNICATION_FAILED";
  case ErrorCode::UNSUPPORTED_EC_FIELD:
    return "UNSUPPORTED_EC_FIELD";
  case ErrorCode::MISSING_NONCE:
    return "MISSING_NONCE";
  case ErrorCode::INVALID_NONCE:
    return "INVALID_NONCE";
  case ErrorCode::MISSING_MAC_LENGTH:
    return "MISSING_MAC_LENGTH";
  case ErrorCode::KEY_RATE_LIMIT_EXCEEDED:
    return "KEY_RATE_LIMIT_EXCEEDED";
  case ErrorCode::CALLER_NONCE_PROHIBITED:
    return "CALLER_NONCE_PROHIBITED";
  case ErrorCode::KEY_MAX_OPS_EXCEEDED:
    return "KEY_MAX_OPS_EXCEEDED";
  case ErrorCode::INVALID_MAC_LENGTH:
    return "INVALID_MAC_LENGTH";
  case ErrorCode::MISSING_MIN_MAC_LENGTH:
    return "MISSING_MIN_MAC_LENGTH";
  case ErrorCode::UNSUPPORTED_MIN_MAC_LENGTH:
    return "UNSUPPORTED_MIN_MAC_LENGTH";
  case ErrorCode::UNSUPPORTED_KDF:
    return "UNSUPPORTED_KDF";
  case ErrorCode::UNSUPPORTED_EC_CURVE:
    return "UNSUPPORTED_EC_CURVE";
  case ErrorCode::KEY_REQUIRES_UPGRADE:
    return "KEY_REQUIRES_UPGRADE";
  case ErrorCode::ATTESTATION_CHALLENGE_MISSING:
    return "ATTESTATION_CHALLENGE_MISSING";
  case ErrorCode::KEYMINT_NOT_CONFIGURED:
    return "KEYMINT_NOT_CONFIGURED";
  case ErrorCode::ATTESTATION_APPLICATION_ID_MISSING:
    return "ATTESTATION_APPLICATION_ID_MISSING";
  case ErrorCode::CANNOT_ATTEST_IDS:
    return "CANNOT_ATTEST_IDS";
  case ErrorCode::ROLLBACK_RESISTANCE_UNAVAILABLE:
    return "ROLLBACK_RESISTANCE_UNAVAILABLE";
  case ErrorCode::HARDWARE_TYPE_UNAVAILABLE:
    return "HARDWARE_TYPE_UNAVAILABLE";
  case ErrorCode::PROOF_OF_PRESENCE_REQUIRED:
    return "PROOF_OF_PRESENCE_REQUIRED";
  case ErrorCode::CONCURRENT_PROOF_OF_PRESENCE_REQUESTED:
    return "CONCURRENT_PROOF_OF_PRESENCE_REQUESTED";
  case ErrorCode::NO_USER_CONFIRMATION:
    return "NO_USER_CONFIRMATION";
  case ErrorCode::DEVICE_LOCKED:
    return "DEVICE_LOCKED";
  case ErrorCode::EARLY_BOOT_ENDED:
    return "EARLY_BOOT_ENDED";
  case ErrorCode::ATTESTATION_KEYS_NOT_PROVISIONED:
    return "ATTESTATION_KEYS_NOT_PROVISIONED";
  case ErrorCode::ATTESTATION_IDS_NOT_PROVISIONED:
    return "ATTESTATION_IDS_NOT_PROVISIONED";
  case ErrorCode::INVALID_OPERATION:
    return "INVALID_OPERATION";
  case ErrorCode::STORAGE_KEY_UNSUPPORTED:
    return "STORAGE_KEY_UNSUPPORTED";
  case ErrorCode::INCOMPATIBLE_MGF_DIGEST:
    return "INCOMPATIBLE_MGF_DIGEST";
  case ErrorCode::UNSUPPORTED_MGF_DIGEST:
    return "UNSUPPORTED_MGF_DIGEST";
  case ErrorCode::MISSING_NOT_BEFORE:
    return "MISSING_NOT_BEFORE";
  case ErrorCode::MISSING_NOT_AFTER:
    return "MISSING_NOT_AFTER";
  case ErrorCode::MISSING_ISSUER_SUBJECT:
    return "MISSING_ISSUER_SUBJECT";
  case ErrorCode::INVALID_ISSUER_SUBJECT:
    return "INVALID_ISSUER_SUBJECT";
  case ErrorCode::BOOT_LEVEL_EXCEEDED:
    return "BOOT_LEVEL_EXCEEDED";
  case ErrorCode::HARDWARE_NOT_YET_AVAILABLE:
    return "HARDWARE_NOT_YET_AVAILABLE";
  case ErrorCode::UNIMPLEMENTED:
    return "UNIMPLEMENTED";
  case ErrorCode::VERSION_MISMATCH:
    return "VERSION_MISMATCH";
  case ErrorCode::UNKNOWN_ERROR:
    return "UNKNOWN_ERROR";
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
constexpr inline std::array<::android::hardware::security::keymint::ErrorCode, 87> enum_values<::android::hardware::security::keymint::ErrorCode> = {
  ::android::hardware::security::keymint::ErrorCode::OK,
  ::android::hardware::security::keymint::ErrorCode::ROOT_OF_TRUST_ALREADY_SET,
  ::android::hardware::security::keymint::ErrorCode::UNSUPPORTED_PURPOSE,
  ::android::hardware::security::keymint::ErrorCode::INCOMPATIBLE_PURPOSE,
  ::android::hardware::security::keymint::ErrorCode::UNSUPPORTED_ALGORITHM,
  ::android::hardware::security::keymint::ErrorCode::INCOMPATIBLE_ALGORITHM,
  ::android::hardware::security::keymint::ErrorCode::UNSUPPORTED_KEY_SIZE,
  ::android::hardware::security::keymint::ErrorCode::UNSUPPORTED_BLOCK_MODE,
  ::android::hardware::security::keymint::ErrorCode::INCOMPATIBLE_BLOCK_MODE,
  ::android::hardware::security::keymint::ErrorCode::UNSUPPORTED_MAC_LENGTH,
  ::android::hardware::security::keymint::ErrorCode::UNSUPPORTED_PADDING_MODE,
  ::android::hardware::security::keymint::ErrorCode::INCOMPATIBLE_PADDING_MODE,
  ::android::hardware::security::keymint::ErrorCode::UNSUPPORTED_DIGEST,
  ::android::hardware::security::keymint::ErrorCode::INCOMPATIBLE_DIGEST,
  ::android::hardware::security::keymint::ErrorCode::INVALID_EXPIRATION_TIME,
  ::android::hardware::security::keymint::ErrorCode::INVALID_USER_ID,
  ::android::hardware::security::keymint::ErrorCode::INVALID_AUTHORIZATION_TIMEOUT,
  ::android::hardware::security::keymint::ErrorCode::UNSUPPORTED_KEY_FORMAT,
  ::android::hardware::security::keymint::ErrorCode::INCOMPATIBLE_KEY_FORMAT,
  ::android::hardware::security::keymint::ErrorCode::UNSUPPORTED_KEY_ENCRYPTION_ALGORITHM,
  ::android::hardware::security::keymint::ErrorCode::UNSUPPORTED_KEY_VERIFICATION_ALGORITHM,
  ::android::hardware::security::keymint::ErrorCode::INVALID_INPUT_LENGTH,
  ::android::hardware::security::keymint::ErrorCode::KEY_EXPORT_OPTIONS_INVALID,
  ::android::hardware::security::keymint::ErrorCode::DELEGATION_NOT_ALLOWED,
  ::android::hardware::security::keymint::ErrorCode::KEY_NOT_YET_VALID,
  ::android::hardware::security::keymint::ErrorCode::KEY_EXPIRED,
  ::android::hardware::security::keymint::ErrorCode::KEY_USER_NOT_AUTHENTICATED,
  ::android::hardware::security::keymint::ErrorCode::OUTPUT_PARAMETER_NULL,
  ::android::hardware::security::keymint::ErrorCode::INVALID_OPERATION_HANDLE,
  ::android::hardware::security::keymint::ErrorCode::INSUFFICIENT_BUFFER_SPACE,
  ::android::hardware::security::keymint::ErrorCode::VERIFICATION_FAILED,
  ::android::hardware::security::keymint::ErrorCode::TOO_MANY_OPERATIONS,
  ::android::hardware::security::keymint::ErrorCode::UNEXPECTED_NULL_POINTER,
  ::android::hardware::security::keymint::ErrorCode::INVALID_KEY_BLOB,
  ::android::hardware::security::keymint::ErrorCode::IMPORTED_KEY_NOT_ENCRYPTED,
  ::android::hardware::security::keymint::ErrorCode::IMPORTED_KEY_DECRYPTION_FAILED,
  ::android::hardware::security::keymint::ErrorCode::IMPORTED_KEY_NOT_SIGNED,
  ::android::hardware::security::keymint::ErrorCode::IMPORTED_KEY_VERIFICATION_FAILED,
  ::android::hardware::security::keymint::ErrorCode::INVALID_ARGUMENT,
  ::android::hardware::security::keymint::ErrorCode::UNSUPPORTED_TAG,
  ::android::hardware::security::keymint::ErrorCode::INVALID_TAG,
  ::android::hardware::security::keymint::ErrorCode::MEMORY_ALLOCATION_FAILED,
  ::android::hardware::security::keymint::ErrorCode::IMPORT_PARAMETER_MISMATCH,
  ::android::hardware::security::keymint::ErrorCode::SECURE_HW_ACCESS_DENIED,
  ::android::hardware::security::keymint::ErrorCode::OPERATION_CANCELLED,
  ::android::hardware::security::keymint::ErrorCode::CONCURRENT_ACCESS_CONFLICT,
  ::android::hardware::security::keymint::ErrorCode::SECURE_HW_BUSY,
  ::android::hardware::security::keymint::ErrorCode::SECURE_HW_COMMUNICATION_FAILED,
  ::android::hardware::security::keymint::ErrorCode::UNSUPPORTED_EC_FIELD,
  ::android::hardware::security::keymint::ErrorCode::MISSING_NONCE,
  ::android::hardware::security::keymint::ErrorCode::INVALID_NONCE,
  ::android::hardware::security::keymint::ErrorCode::MISSING_MAC_LENGTH,
  ::android::hardware::security::keymint::ErrorCode::KEY_RATE_LIMIT_EXCEEDED,
  ::android::hardware::security::keymint::ErrorCode::CALLER_NONCE_PROHIBITED,
  ::android::hardware::security::keymint::ErrorCode::KEY_MAX_OPS_EXCEEDED,
  ::android::hardware::security::keymint::ErrorCode::INVALID_MAC_LENGTH,
  ::android::hardware::security::keymint::ErrorCode::MISSING_MIN_MAC_LENGTH,
  ::android::hardware::security::keymint::ErrorCode::UNSUPPORTED_MIN_MAC_LENGTH,
  ::android::hardware::security::keymint::ErrorCode::UNSUPPORTED_KDF,
  ::android::hardware::security::keymint::ErrorCode::UNSUPPORTED_EC_CURVE,
  ::android::hardware::security::keymint::ErrorCode::KEY_REQUIRES_UPGRADE,
  ::android::hardware::security::keymint::ErrorCode::ATTESTATION_CHALLENGE_MISSING,
  ::android::hardware::security::keymint::ErrorCode::KEYMINT_NOT_CONFIGURED,
  ::android::hardware::security::keymint::ErrorCode::ATTESTATION_APPLICATION_ID_MISSING,
  ::android::hardware::security::keymint::ErrorCode::CANNOT_ATTEST_IDS,
  ::android::hardware::security::keymint::ErrorCode::ROLLBACK_RESISTANCE_UNAVAILABLE,
  ::android::hardware::security::keymint::ErrorCode::HARDWARE_TYPE_UNAVAILABLE,
  ::android::hardware::security::keymint::ErrorCode::PROOF_OF_PRESENCE_REQUIRED,
  ::android::hardware::security::keymint::ErrorCode::CONCURRENT_PROOF_OF_PRESENCE_REQUESTED,
  ::android::hardware::security::keymint::ErrorCode::NO_USER_CONFIRMATION,
  ::android::hardware::security::keymint::ErrorCode::DEVICE_LOCKED,
  ::android::hardware::security::keymint::ErrorCode::EARLY_BOOT_ENDED,
  ::android::hardware::security::keymint::ErrorCode::ATTESTATION_KEYS_NOT_PROVISIONED,
  ::android::hardware::security::keymint::ErrorCode::ATTESTATION_IDS_NOT_PROVISIONED,
  ::android::hardware::security::keymint::ErrorCode::INVALID_OPERATION,
  ::android::hardware::security::keymint::ErrorCode::STORAGE_KEY_UNSUPPORTED,
  ::android::hardware::security::keymint::ErrorCode::INCOMPATIBLE_MGF_DIGEST,
  ::android::hardware::security::keymint::ErrorCode::UNSUPPORTED_MGF_DIGEST,
  ::android::hardware::security::keymint::ErrorCode::MISSING_NOT_BEFORE,
  ::android::hardware::security::keymint::ErrorCode::MISSING_NOT_AFTER,
  ::android::hardware::security::keymint::ErrorCode::MISSING_ISSUER_SUBJECT,
  ::android::hardware::security::keymint::ErrorCode::INVALID_ISSUER_SUBJECT,
  ::android::hardware::security::keymint::ErrorCode::BOOT_LEVEL_EXCEEDED,
  ::android::hardware::security::keymint::ErrorCode::HARDWARE_NOT_YET_AVAILABLE,
  ::android::hardware::security::keymint::ErrorCode::UNIMPLEMENTED,
  ::android::hardware::security::keymint::ErrorCode::VERSION_MISMATCH,
  ::android::hardware::security::keymint::ErrorCode::UNKNOWN_ERROR,
};
#pragma clang diagnostic pop

}  // namespace internal

}  // namespace android
