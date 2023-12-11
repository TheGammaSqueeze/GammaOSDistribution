#ifndef HIDL_GENERATED_ANDROID_HARDWARE_DRM_V1_4_TYPES_H
#define HIDL_GENERATED_ANDROID_HARDWARE_DRM_V1_4_TYPES_H

#include <android/hardware/drm/1.2/types.h>

#include <hidl/HidlSupport.h>
#include <hidl/MQDescriptor.h>
#include <utils/NativeHandle.h>
#include <utils/misc.h>

namespace android {
namespace hardware {
namespace drm {
namespace V1_4 {

// Forward declaration for forward reference support:
enum class LogPriority : uint32_t;
struct LogMessage;
enum class Status : uint32_t;

enum class LogPriority : uint32_t {
    UNKNOWN = 0u,
    DEFAULT = 1u /* ::android::hardware::drm::V1_4::LogPriority.UNKNOWN implicitly + 1 */,
    VERBOSE = 2u /* ::android::hardware::drm::V1_4::LogPriority.DEFAULT implicitly + 1 */,
    DEBUG = 3u /* ::android::hardware::drm::V1_4::LogPriority.VERBOSE implicitly + 1 */,
    INFO = 4u /* ::android::hardware::drm::V1_4::LogPriority.DEBUG implicitly + 1 */,
    WARN = 5u /* ::android::hardware::drm::V1_4::LogPriority.INFO implicitly + 1 */,
    ERROR = 6u /* ::android::hardware::drm::V1_4::LogPriority.WARN implicitly + 1 */,
    FATAL = 7u /* ::android::hardware::drm::V1_4::LogPriority.ERROR implicitly + 1 */,
};

/**
 * Returned by getLogMessages to report error diagnostics to the
 * app.
 *
 * The |message| field is for informational purposes only, and
 * NOT meant to be parsed programmatically when handling errors.
 * For programmatic error handling, please check the return |Status|
 * of APIs instead.
 */
struct LogMessage final {
    /**
     * Epoch time in milliseconds.
     */
    int64_t timeMs __attribute__ ((aligned(8)));
    ::android::hardware::drm::V1_4::LogPriority priority __attribute__ ((aligned(4)));
    ::android::hardware::hidl_string message __attribute__ ((aligned(8)));
};

static_assert(offsetof(::android::hardware::drm::V1_4::LogMessage, timeMs) == 0, "wrong offset");
static_assert(offsetof(::android::hardware::drm::V1_4::LogMessage, priority) == 8, "wrong offset");
static_assert(offsetof(::android::hardware::drm::V1_4::LogMessage, message) == 16, "wrong offset");
static_assert(sizeof(::android::hardware::drm::V1_4::LogMessage) == 32, "wrong size");
static_assert(__alignof(::android::hardware::drm::V1_4::LogMessage) == 8, "wrong alignment");

enum class Status : uint32_t {
    /**
     * The DRM plugin must return OK when an operation completes without any
     * errors.
     */
    OK = 0u,
    /**
     * The DRM plugin must return ERROR_DRM_NO_LICENSE, when decryption is
     * attempted and no license keys have been provided.
     */
    ERROR_DRM_NO_LICENSE = 1u /* ::android::hardware::drm::V1_0::Status.OK implicitly + 1 */,
    /**
     * ERROR_DRM_LICENSE_EXPIRED must be returned when an attempt is made
     * to use a license and the keys in that license have expired.
     */
    ERROR_DRM_LICENSE_EXPIRED = 2u /* ::android::hardware::drm::V1_0::Status.ERROR_DRM_NO_LICENSE implicitly + 1 */,
    /**
     * The DRM plugin must return ERROR_DRM_SESSION_NOT_OPENED when an
     * attempt is made to use a session that has not been opened.
     */
    ERROR_DRM_SESSION_NOT_OPENED = 3u /* ::android::hardware::drm::V1_0::Status.ERROR_DRM_LICENSE_EXPIRED implicitly + 1 */,
    /**
     * The DRM plugin must return ERROR_DRM_CANNOT_HANDLE when an unsupported
     * data format or operation is attempted.
     */
    ERROR_DRM_CANNOT_HANDLE = 4u /* ::android::hardware::drm::V1_0::Status.ERROR_DRM_SESSION_NOT_OPENED implicitly + 1 */,
    /**
     * ERROR_DRM_INVALID_STATE must be returned when the device is in a state
     * where it is not able to perform decryption.
     */
    ERROR_DRM_INVALID_STATE = 5u /* ::android::hardware::drm::V1_0::Status.ERROR_DRM_CANNOT_HANDLE implicitly + 1 */,
    /**
     * The DRM plugin must return BAD_VALUE whenever an illegal parameter is
     * passed to one of the interface functions.
     */
    BAD_VALUE = 6u /* ::android::hardware::drm::V1_0::Status.ERROR_DRM_INVALID_STATE implicitly + 1 */,
    /**
     * The DRM plugin must return ERROR_DRM_NOT_PROVISIONED from getKeyRequest,
     * openSession or provideKeyResponse when the device has not yet been
     * provisioned.
     */
    ERROR_DRM_NOT_PROVISIONED = 7u /* ::android::hardware::drm::V1_0::Status.BAD_VALUE implicitly + 1 */,
    /**
     * ERROR_DRM_RESOURCE_BUSY must be returned when resources, such as drm
     * sessions or secure buffers are not available to perform a requested
     * operation because they are already in use.
     */
    ERROR_DRM_RESOURCE_BUSY = 8u /* ::android::hardware::drm::V1_0::Status.ERROR_DRM_NOT_PROVISIONED implicitly + 1 */,
    /**
     * The DRM Plugin must return ERROR_DRM_INSUFFICIENT_OUTPUT_PROTECTION
     * when the output protection level enabled on the device is not
     * sufficient to meet the requirements in the license policy.  HDCP is an
     * example of a form of output protection.
     */
    ERROR_DRM_INSUFFICIENT_OUTPUT_PROTECTION = 9u /* ::android::hardware::drm::V1_0::Status.ERROR_DRM_RESOURCE_BUSY implicitly + 1 */,
    /**
     * The DRM Plugin must return ERROR_DRM_DEVICE_REVOKED from
     * provideProvisionResponse and provideKeyResponse if the response indicates
     * that the device has been revoked. Device revocation means that the device
     * is no longer permitted to play content.
     */
    ERROR_DRM_DEVICE_REVOKED = 10u /* ::android::hardware::drm::V1_0::Status.ERROR_DRM_INSUFFICIENT_OUTPUT_PROTECTION implicitly + 1 */,
    /**
     * The DRM Plugin must return ERROR_DRM_DECRYPT if the CryptoPlugin
     * decrypt operation fails.
     */
    ERROR_DRM_DECRYPT = 11u /* ::android::hardware::drm::V1_0::Status.ERROR_DRM_DEVICE_REVOKED implicitly + 1 */,
    /**
     * ERROR_DRM_UNKNOWN must be returned when a fatal failure occurs and no
     * other defined error is appropriate.
     */
    ERROR_DRM_UNKNOWN = 12u /* ::android::hardware::drm::V1_0::Status.ERROR_DRM_DECRYPT implicitly + 1 */,
    /**
     * The drm HAL module must return ERROR_DRM_INSUFFICIENT_SECURITY
     * from the crypto plugin decrypt method when the security level
     * of the device is not sufficient to meet the requirements in the
     * license policy.
     */
    ERROR_DRM_INSUFFICIENT_SECURITY = 13u /* ::android::hardware::drm::V1_0::Status.ERROR_DRM_UNKNOWN implicitly + 1 */,
    /**
     * The drm HAL module must return ERROR_FRAME_TOO_LARGE from the
     * decrypt method when the frame being decrypted into the secure
     * output buffer exceeds the size of the buffer.
     */
    ERROR_DRM_FRAME_TOO_LARGE = 14u /* ::android::hardware::drm::V1_2::Status.ERROR_DRM_INSUFFICIENT_SECURITY implicitly + 1 */,
    /**
     * This error must be returned from any session method when an
     * attempt is made to use the session after the crypto hardware
     * state has been invalidated. Some devices are not able to
     * retain crypto session state across device suspend/resume which
     * results in invalid session state.
     */
    ERROR_DRM_SESSION_LOST_STATE = 15u /* ::android::hardware::drm::V1_2::Status.ERROR_DRM_FRAME_TOO_LARGE implicitly + 1 */,
    /**
     * The drm HAL module must return this error if client
     * applications using the hal are temporarily exceeding the
     * capacity of available crypto resources such that a retry of
     * the operation is likely to succeed.
     */
    ERROR_DRM_RESOURCE_CONTENTION = 16u /* ::android::hardware::drm::V1_2::Status.ERROR_DRM_SESSION_LOST_STATE implicitly + 1 */,
    /**
     * queueSecureInput buffer called with 0 subsamples.
     */
    CANNOT_DECRYPT_ZERO_SUBSAMPLES = 17u /* ::android::hardware::drm::V1_2::Status.ERROR_DRM_RESOURCE_CONTENTION implicitly + 1 */,
    /**
     * An error happened within the crypto library used by the drm plugin.
     */
    CRYPTO_LIBRARY_ERROR = 18u /* ::android::hardware::drm::V1_4::Status.CANNOT_DECRYPT_ZERO_SUBSAMPLES implicitly + 1 */,
    /**
     * Non-specific error reported by the device OEM subsystem.
     */
    GENERAL_OEM_ERROR = 19u /* ::android::hardware::drm::V1_4::Status.CRYPTO_LIBRARY_ERROR implicitly + 1 */,
    /**
     * Unexpected internal failure in the drm/crypto plugin.
     */
    GENERAL_PLUGIN_ERROR = 20u /* ::android::hardware::drm::V1_4::Status.GENERAL_OEM_ERROR implicitly + 1 */,
    /**
     * The init data parameter passed to getKeyRequest is empty or invalid.
     */
    INIT_DATA_INVALID = 21u /* ::android::hardware::drm::V1_4::Status.GENERAL_PLUGIN_ERROR implicitly + 1 */,
    /**
     * Either the key was not loaded from the license before attempting the
     * operation, or the key ID parameter provided by the app is incorrect.
     */
    KEY_NOT_LOADED = 22u /* ::android::hardware::drm::V1_4::Status.INIT_DATA_INVALID implicitly + 1 */,
    /**
     * The license response was empty, fields are missing or otherwise unable
     * to be parsed.
     */
    LICENSE_PARSE_ERROR = 23u /* ::android::hardware::drm::V1_4::Status.KEY_NOT_LOADED implicitly + 1 */,
    /**
     * The operation (e.g. to renew or persist a license) is prohibited by the
     * license policy.
     */
    LICENSE_POLICY_ERROR = 24u /* ::android::hardware::drm::V1_4::Status.LICENSE_PARSE_ERROR implicitly + 1 */,
    /**
     * Failed to generate a release request because a field in the stored
     * license is empty or malformed.
     */
    LICENSE_RELEASE_ERROR = 25u /* ::android::hardware::drm::V1_4::Status.LICENSE_POLICY_ERROR implicitly + 1 */,
    /**
     * The license server detected an error in the license request.
     */
    LICENSE_REQUEST_REJECTED = 26u /* ::android::hardware::drm::V1_4::Status.LICENSE_RELEASE_ERROR implicitly + 1 */,
    /**
     * Failed to restore an offline license because a field is empty or
     * malformed.
     */
    LICENSE_RESTORE_ERROR = 27u /* ::android::hardware::drm::V1_4::Status.LICENSE_REQUEST_REJECTED implicitly + 1 */,
    /**
     * License is in an invalid state for the attempted operation.
     */
    LICENSE_STATE_ERROR = 28u /* ::android::hardware::drm::V1_4::Status.LICENSE_RESTORE_ERROR implicitly + 1 */,
    /**
     * Certificate is malformed or is of the wrong type.
     */
    MALFORMED_CERTIFICATE = 29u /* ::android::hardware::drm::V1_4::Status.LICENSE_STATE_ERROR implicitly + 1 */,
    /**
     * Failure in the media framework.
     */
    MEDIA_FRAMEWORK_ERROR = 30u /* ::android::hardware::drm::V1_4::Status.MALFORMED_CERTIFICATE implicitly + 1 */,
    /**
     * Certificate has not been set.
     */
    MISSING_CERTIFICATE = 31u /* ::android::hardware::drm::V1_4::Status.MEDIA_FRAMEWORK_ERROR implicitly + 1 */,
    /**
     * There was an error loading the provisioned certificate.
     */
    PROVISIONING_CERTIFICATE_ERROR = 32u /* ::android::hardware::drm::V1_4::Status.MISSING_CERTIFICATE implicitly + 1 */,
    /**
     * Required steps where not performed before provisioning was attempted.
     */
    PROVISIONING_CONFIGURATION_ERROR = 33u /* ::android::hardware::drm::V1_4::Status.PROVISIONING_CERTIFICATE_ERROR implicitly + 1 */,
    /**
     * The provisioning response was empty, fields are missing or otherwise
     * unable to be parsed.
     */
    PROVISIONING_PARSE_ERROR = 34u /* ::android::hardware::drm::V1_4::Status.PROVISIONING_CONFIGURATION_ERROR implicitly + 1 */,
    /**
     * The provisioning server detected an error in the provisioning request.
     */
    PROVISIONING_REQUEST_REJECTED = 35u /* ::android::hardware::drm::V1_4::Status.PROVISIONING_PARSE_ERROR implicitly + 1 */,
    /**
     * Provisioning failed in a way that is likely to succeed on a subsequent
     * attempt.
     */
    RETRYABLE_PROVISIONING_ERROR = 36u /* ::android::hardware::drm::V1_4::Status.PROVISIONING_REQUEST_REJECTED implicitly + 1 */,
    /**
     * Failed to generate a secure stop request because a field in the stored
     * license is empty or malformed.
     */
    SECURE_STOP_RELEASE_ERROR = 37u /* ::android::hardware::drm::V1_4::Status.RETRYABLE_PROVISIONING_ERROR implicitly + 1 */,
    /**
     * The plugin was unable to read data from the filesystem.
     */
    STORAGE_READ_FAILURE = 38u /* ::android::hardware::drm::V1_4::Status.SECURE_STOP_RELEASE_ERROR implicitly + 1 */,
    /**
     * The plugin was unable to write data to the filesystem.
     */
    STORAGE_WRITE_FAILURE = 39u /* ::android::hardware::drm::V1_4::Status.STORAGE_READ_FAILURE implicitly + 1 */,
};

//
// type declarations for package
//

template<typename>
static inline std::string toString(uint32_t o);
static inline std::string toString(::android::hardware::drm::V1_4::LogPriority o);
static inline void PrintTo(::android::hardware::drm::V1_4::LogPriority o, ::std::ostream* os);
constexpr uint32_t operator|(const ::android::hardware::drm::V1_4::LogPriority lhs, const ::android::hardware::drm::V1_4::LogPriority rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) | static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator|(const uint32_t lhs, const ::android::hardware::drm::V1_4::LogPriority rhs) {
    return static_cast<uint32_t>(lhs | static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator|(const ::android::hardware::drm::V1_4::LogPriority lhs, const uint32_t rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) | rhs);
}
constexpr uint32_t operator&(const ::android::hardware::drm::V1_4::LogPriority lhs, const ::android::hardware::drm::V1_4::LogPriority rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) & static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator&(const uint32_t lhs, const ::android::hardware::drm::V1_4::LogPriority rhs) {
    return static_cast<uint32_t>(lhs & static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator&(const ::android::hardware::drm::V1_4::LogPriority lhs, const uint32_t rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) & rhs);
}
constexpr uint32_t &operator|=(uint32_t& v, const ::android::hardware::drm::V1_4::LogPriority e) {
    v |= static_cast<uint32_t>(e);
    return v;
}
constexpr uint32_t &operator&=(uint32_t& v, const ::android::hardware::drm::V1_4::LogPriority e) {
    v &= static_cast<uint32_t>(e);
    return v;
}

static inline std::string toString(const ::android::hardware::drm::V1_4::LogMessage& o);
static inline void PrintTo(const ::android::hardware::drm::V1_4::LogMessage& o, ::std::ostream*);
static inline bool operator==(const ::android::hardware::drm::V1_4::LogMessage& lhs, const ::android::hardware::drm::V1_4::LogMessage& rhs);
static inline bool operator!=(const ::android::hardware::drm::V1_4::LogMessage& lhs, const ::android::hardware::drm::V1_4::LogMessage& rhs);

template<typename>
static inline std::string toString(uint32_t o);
static inline std::string toString(::android::hardware::drm::V1_4::Status o);
static inline void PrintTo(::android::hardware::drm::V1_4::Status o, ::std::ostream* os);
constexpr uint32_t operator|(const ::android::hardware::drm::V1_4::Status lhs, const ::android::hardware::drm::V1_4::Status rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) | static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator|(const uint32_t lhs, const ::android::hardware::drm::V1_4::Status rhs) {
    return static_cast<uint32_t>(lhs | static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator|(const ::android::hardware::drm::V1_4::Status lhs, const uint32_t rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) | rhs);
}
constexpr uint32_t operator&(const ::android::hardware::drm::V1_4::Status lhs, const ::android::hardware::drm::V1_4::Status rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) & static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator&(const uint32_t lhs, const ::android::hardware::drm::V1_4::Status rhs) {
    return static_cast<uint32_t>(lhs & static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator&(const ::android::hardware::drm::V1_4::Status lhs, const uint32_t rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) & rhs);
}
constexpr uint32_t &operator|=(uint32_t& v, const ::android::hardware::drm::V1_4::Status e) {
    v |= static_cast<uint32_t>(e);
    return v;
}
constexpr uint32_t &operator&=(uint32_t& v, const ::android::hardware::drm::V1_4::Status e) {
    v &= static_cast<uint32_t>(e);
    return v;
}

//
// type header definitions for package
//

template<>
inline std::string toString<::android::hardware::drm::V1_4::LogPriority>(uint32_t o) {
    using ::android::hardware::details::toHexString;
    std::string os;
    ::android::hardware::hidl_bitfield<::android::hardware::drm::V1_4::LogPriority> flipped = 0;
    bool first = true;
    if ((o & ::android::hardware::drm::V1_4::LogPriority::UNKNOWN) == static_cast<uint32_t>(::android::hardware::drm::V1_4::LogPriority::UNKNOWN)) {
        os += (first ? "" : " | ");
        os += "UNKNOWN";
        first = false;
        flipped |= ::android::hardware::drm::V1_4::LogPriority::UNKNOWN;
    }
    if ((o & ::android::hardware::drm::V1_4::LogPriority::DEFAULT) == static_cast<uint32_t>(::android::hardware::drm::V1_4::LogPriority::DEFAULT)) {
        os += (first ? "" : " | ");
        os += "DEFAULT";
        first = false;
        flipped |= ::android::hardware::drm::V1_4::LogPriority::DEFAULT;
    }
    if ((o & ::android::hardware::drm::V1_4::LogPriority::VERBOSE) == static_cast<uint32_t>(::android::hardware::drm::V1_4::LogPriority::VERBOSE)) {
        os += (first ? "" : " | ");
        os += "VERBOSE";
        first = false;
        flipped |= ::android::hardware::drm::V1_4::LogPriority::VERBOSE;
    }
    if ((o & ::android::hardware::drm::V1_4::LogPriority::DEBUG) == static_cast<uint32_t>(::android::hardware::drm::V1_4::LogPriority::DEBUG)) {
        os += (first ? "" : " | ");
        os += "DEBUG";
        first = false;
        flipped |= ::android::hardware::drm::V1_4::LogPriority::DEBUG;
    }
    if ((o & ::android::hardware::drm::V1_4::LogPriority::INFO) == static_cast<uint32_t>(::android::hardware::drm::V1_4::LogPriority::INFO)) {
        os += (first ? "" : " | ");
        os += "INFO";
        first = false;
        flipped |= ::android::hardware::drm::V1_4::LogPriority::INFO;
    }
    if ((o & ::android::hardware::drm::V1_4::LogPriority::WARN) == static_cast<uint32_t>(::android::hardware::drm::V1_4::LogPriority::WARN)) {
        os += (first ? "" : " | ");
        os += "WARN";
        first = false;
        flipped |= ::android::hardware::drm::V1_4::LogPriority::WARN;
    }
    if ((o & ::android::hardware::drm::V1_4::LogPriority::ERROR) == static_cast<uint32_t>(::android::hardware::drm::V1_4::LogPriority::ERROR)) {
        os += (first ? "" : " | ");
        os += "ERROR";
        first = false;
        flipped |= ::android::hardware::drm::V1_4::LogPriority::ERROR;
    }
    if ((o & ::android::hardware::drm::V1_4::LogPriority::FATAL) == static_cast<uint32_t>(::android::hardware::drm::V1_4::LogPriority::FATAL)) {
        os += (first ? "" : " | ");
        os += "FATAL";
        first = false;
        flipped |= ::android::hardware::drm::V1_4::LogPriority::FATAL;
    }
    if (o != flipped) {
        os += (first ? "" : " | ");
        os += toHexString(o & (~flipped));
    }os += " (";
    os += toHexString(o);
    os += ")";
    return os;
}

static inline std::string toString(::android::hardware::drm::V1_4::LogPriority o) {
    using ::android::hardware::details::toHexString;
    if (o == ::android::hardware::drm::V1_4::LogPriority::UNKNOWN) {
        return "UNKNOWN";
    }
    if (o == ::android::hardware::drm::V1_4::LogPriority::DEFAULT) {
        return "DEFAULT";
    }
    if (o == ::android::hardware::drm::V1_4::LogPriority::VERBOSE) {
        return "VERBOSE";
    }
    if (o == ::android::hardware::drm::V1_4::LogPriority::DEBUG) {
        return "DEBUG";
    }
    if (o == ::android::hardware::drm::V1_4::LogPriority::INFO) {
        return "INFO";
    }
    if (o == ::android::hardware::drm::V1_4::LogPriority::WARN) {
        return "WARN";
    }
    if (o == ::android::hardware::drm::V1_4::LogPriority::ERROR) {
        return "ERROR";
    }
    if (o == ::android::hardware::drm::V1_4::LogPriority::FATAL) {
        return "FATAL";
    }
    std::string os;
    os += toHexString(static_cast<uint32_t>(o));
    return os;
}

static inline void PrintTo(::android::hardware::drm::V1_4::LogPriority o, ::std::ostream* os) {
    *os << toString(o);
}

static inline std::string toString(const ::android::hardware::drm::V1_4::LogMessage& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".timeMs = ";
    os += ::android::hardware::toString(o.timeMs);
    os += ", .priority = ";
    os += ::android::hardware::drm::V1_4::toString(o.priority);
    os += ", .message = ";
    os += ::android::hardware::toString(o.message);
    os += "}"; return os;
}

static inline void PrintTo(const ::android::hardware::drm::V1_4::LogMessage& o, ::std::ostream* os) {
    *os << toString(o);
}

static inline bool operator==(const ::android::hardware::drm::V1_4::LogMessage& lhs, const ::android::hardware::drm::V1_4::LogMessage& rhs) {
    if (lhs.timeMs != rhs.timeMs) {
        return false;
    }
    if (lhs.priority != rhs.priority) {
        return false;
    }
    if (lhs.message != rhs.message) {
        return false;
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::drm::V1_4::LogMessage& lhs, const ::android::hardware::drm::V1_4::LogMessage& rhs){
    return !(lhs == rhs);
}

template<>
inline std::string toString<::android::hardware::drm::V1_4::Status>(uint32_t o) {
    using ::android::hardware::details::toHexString;
    std::string os;
    ::android::hardware::hidl_bitfield<::android::hardware::drm::V1_4::Status> flipped = 0;
    bool first = true;
    if ((o & ::android::hardware::drm::V1_4::Status::OK) == static_cast<uint32_t>(::android::hardware::drm::V1_4::Status::OK)) {
        os += (first ? "" : " | ");
        os += "OK";
        first = false;
        flipped |= ::android::hardware::drm::V1_4::Status::OK;
    }
    if ((o & ::android::hardware::drm::V1_4::Status::ERROR_DRM_NO_LICENSE) == static_cast<uint32_t>(::android::hardware::drm::V1_4::Status::ERROR_DRM_NO_LICENSE)) {
        os += (first ? "" : " | ");
        os += "ERROR_DRM_NO_LICENSE";
        first = false;
        flipped |= ::android::hardware::drm::V1_4::Status::ERROR_DRM_NO_LICENSE;
    }
    if ((o & ::android::hardware::drm::V1_4::Status::ERROR_DRM_LICENSE_EXPIRED) == static_cast<uint32_t>(::android::hardware::drm::V1_4::Status::ERROR_DRM_LICENSE_EXPIRED)) {
        os += (first ? "" : " | ");
        os += "ERROR_DRM_LICENSE_EXPIRED";
        first = false;
        flipped |= ::android::hardware::drm::V1_4::Status::ERROR_DRM_LICENSE_EXPIRED;
    }
    if ((o & ::android::hardware::drm::V1_4::Status::ERROR_DRM_SESSION_NOT_OPENED) == static_cast<uint32_t>(::android::hardware::drm::V1_4::Status::ERROR_DRM_SESSION_NOT_OPENED)) {
        os += (first ? "" : " | ");
        os += "ERROR_DRM_SESSION_NOT_OPENED";
        first = false;
        flipped |= ::android::hardware::drm::V1_4::Status::ERROR_DRM_SESSION_NOT_OPENED;
    }
    if ((o & ::android::hardware::drm::V1_4::Status::ERROR_DRM_CANNOT_HANDLE) == static_cast<uint32_t>(::android::hardware::drm::V1_4::Status::ERROR_DRM_CANNOT_HANDLE)) {
        os += (first ? "" : " | ");
        os += "ERROR_DRM_CANNOT_HANDLE";
        first = false;
        flipped |= ::android::hardware::drm::V1_4::Status::ERROR_DRM_CANNOT_HANDLE;
    }
    if ((o & ::android::hardware::drm::V1_4::Status::ERROR_DRM_INVALID_STATE) == static_cast<uint32_t>(::android::hardware::drm::V1_4::Status::ERROR_DRM_INVALID_STATE)) {
        os += (first ? "" : " | ");
        os += "ERROR_DRM_INVALID_STATE";
        first = false;
        flipped |= ::android::hardware::drm::V1_4::Status::ERROR_DRM_INVALID_STATE;
    }
    if ((o & ::android::hardware::drm::V1_4::Status::BAD_VALUE) == static_cast<uint32_t>(::android::hardware::drm::V1_4::Status::BAD_VALUE)) {
        os += (first ? "" : " | ");
        os += "BAD_VALUE";
        first = false;
        flipped |= ::android::hardware::drm::V1_4::Status::BAD_VALUE;
    }
    if ((o & ::android::hardware::drm::V1_4::Status::ERROR_DRM_NOT_PROVISIONED) == static_cast<uint32_t>(::android::hardware::drm::V1_4::Status::ERROR_DRM_NOT_PROVISIONED)) {
        os += (first ? "" : " | ");
        os += "ERROR_DRM_NOT_PROVISIONED";
        first = false;
        flipped |= ::android::hardware::drm::V1_4::Status::ERROR_DRM_NOT_PROVISIONED;
    }
    if ((o & ::android::hardware::drm::V1_4::Status::ERROR_DRM_RESOURCE_BUSY) == static_cast<uint32_t>(::android::hardware::drm::V1_4::Status::ERROR_DRM_RESOURCE_BUSY)) {
        os += (first ? "" : " | ");
        os += "ERROR_DRM_RESOURCE_BUSY";
        first = false;
        flipped |= ::android::hardware::drm::V1_4::Status::ERROR_DRM_RESOURCE_BUSY;
    }
    if ((o & ::android::hardware::drm::V1_4::Status::ERROR_DRM_INSUFFICIENT_OUTPUT_PROTECTION) == static_cast<uint32_t>(::android::hardware::drm::V1_4::Status::ERROR_DRM_INSUFFICIENT_OUTPUT_PROTECTION)) {
        os += (first ? "" : " | ");
        os += "ERROR_DRM_INSUFFICIENT_OUTPUT_PROTECTION";
        first = false;
        flipped |= ::android::hardware::drm::V1_4::Status::ERROR_DRM_INSUFFICIENT_OUTPUT_PROTECTION;
    }
    if ((o & ::android::hardware::drm::V1_4::Status::ERROR_DRM_DEVICE_REVOKED) == static_cast<uint32_t>(::android::hardware::drm::V1_4::Status::ERROR_DRM_DEVICE_REVOKED)) {
        os += (first ? "" : " | ");
        os += "ERROR_DRM_DEVICE_REVOKED";
        first = false;
        flipped |= ::android::hardware::drm::V1_4::Status::ERROR_DRM_DEVICE_REVOKED;
    }
    if ((o & ::android::hardware::drm::V1_4::Status::ERROR_DRM_DECRYPT) == static_cast<uint32_t>(::android::hardware::drm::V1_4::Status::ERROR_DRM_DECRYPT)) {
        os += (first ? "" : " | ");
        os += "ERROR_DRM_DECRYPT";
        first = false;
        flipped |= ::android::hardware::drm::V1_4::Status::ERROR_DRM_DECRYPT;
    }
    if ((o & ::android::hardware::drm::V1_4::Status::ERROR_DRM_UNKNOWN) == static_cast<uint32_t>(::android::hardware::drm::V1_4::Status::ERROR_DRM_UNKNOWN)) {
        os += (first ? "" : " | ");
        os += "ERROR_DRM_UNKNOWN";
        first = false;
        flipped |= ::android::hardware::drm::V1_4::Status::ERROR_DRM_UNKNOWN;
    }
    if ((o & ::android::hardware::drm::V1_4::Status::ERROR_DRM_INSUFFICIENT_SECURITY) == static_cast<uint32_t>(::android::hardware::drm::V1_4::Status::ERROR_DRM_INSUFFICIENT_SECURITY)) {
        os += (first ? "" : " | ");
        os += "ERROR_DRM_INSUFFICIENT_SECURITY";
        first = false;
        flipped |= ::android::hardware::drm::V1_4::Status::ERROR_DRM_INSUFFICIENT_SECURITY;
    }
    if ((o & ::android::hardware::drm::V1_4::Status::ERROR_DRM_FRAME_TOO_LARGE) == static_cast<uint32_t>(::android::hardware::drm::V1_4::Status::ERROR_DRM_FRAME_TOO_LARGE)) {
        os += (first ? "" : " | ");
        os += "ERROR_DRM_FRAME_TOO_LARGE";
        first = false;
        flipped |= ::android::hardware::drm::V1_4::Status::ERROR_DRM_FRAME_TOO_LARGE;
    }
    if ((o & ::android::hardware::drm::V1_4::Status::ERROR_DRM_SESSION_LOST_STATE) == static_cast<uint32_t>(::android::hardware::drm::V1_4::Status::ERROR_DRM_SESSION_LOST_STATE)) {
        os += (first ? "" : " | ");
        os += "ERROR_DRM_SESSION_LOST_STATE";
        first = false;
        flipped |= ::android::hardware::drm::V1_4::Status::ERROR_DRM_SESSION_LOST_STATE;
    }
    if ((o & ::android::hardware::drm::V1_4::Status::ERROR_DRM_RESOURCE_CONTENTION) == static_cast<uint32_t>(::android::hardware::drm::V1_4::Status::ERROR_DRM_RESOURCE_CONTENTION)) {
        os += (first ? "" : " | ");
        os += "ERROR_DRM_RESOURCE_CONTENTION";
        first = false;
        flipped |= ::android::hardware::drm::V1_4::Status::ERROR_DRM_RESOURCE_CONTENTION;
    }
    if ((o & ::android::hardware::drm::V1_4::Status::CANNOT_DECRYPT_ZERO_SUBSAMPLES) == static_cast<uint32_t>(::android::hardware::drm::V1_4::Status::CANNOT_DECRYPT_ZERO_SUBSAMPLES)) {
        os += (first ? "" : " | ");
        os += "CANNOT_DECRYPT_ZERO_SUBSAMPLES";
        first = false;
        flipped |= ::android::hardware::drm::V1_4::Status::CANNOT_DECRYPT_ZERO_SUBSAMPLES;
    }
    if ((o & ::android::hardware::drm::V1_4::Status::CRYPTO_LIBRARY_ERROR) == static_cast<uint32_t>(::android::hardware::drm::V1_4::Status::CRYPTO_LIBRARY_ERROR)) {
        os += (first ? "" : " | ");
        os += "CRYPTO_LIBRARY_ERROR";
        first = false;
        flipped |= ::android::hardware::drm::V1_4::Status::CRYPTO_LIBRARY_ERROR;
    }
    if ((o & ::android::hardware::drm::V1_4::Status::GENERAL_OEM_ERROR) == static_cast<uint32_t>(::android::hardware::drm::V1_4::Status::GENERAL_OEM_ERROR)) {
        os += (first ? "" : " | ");
        os += "GENERAL_OEM_ERROR";
        first = false;
        flipped |= ::android::hardware::drm::V1_4::Status::GENERAL_OEM_ERROR;
    }
    if ((o & ::android::hardware::drm::V1_4::Status::GENERAL_PLUGIN_ERROR) == static_cast<uint32_t>(::android::hardware::drm::V1_4::Status::GENERAL_PLUGIN_ERROR)) {
        os += (first ? "" : " | ");
        os += "GENERAL_PLUGIN_ERROR";
        first = false;
        flipped |= ::android::hardware::drm::V1_4::Status::GENERAL_PLUGIN_ERROR;
    }
    if ((o & ::android::hardware::drm::V1_4::Status::INIT_DATA_INVALID) == static_cast<uint32_t>(::android::hardware::drm::V1_4::Status::INIT_DATA_INVALID)) {
        os += (first ? "" : " | ");
        os += "INIT_DATA_INVALID";
        first = false;
        flipped |= ::android::hardware::drm::V1_4::Status::INIT_DATA_INVALID;
    }
    if ((o & ::android::hardware::drm::V1_4::Status::KEY_NOT_LOADED) == static_cast<uint32_t>(::android::hardware::drm::V1_4::Status::KEY_NOT_LOADED)) {
        os += (first ? "" : " | ");
        os += "KEY_NOT_LOADED";
        first = false;
        flipped |= ::android::hardware::drm::V1_4::Status::KEY_NOT_LOADED;
    }
    if ((o & ::android::hardware::drm::V1_4::Status::LICENSE_PARSE_ERROR) == static_cast<uint32_t>(::android::hardware::drm::V1_4::Status::LICENSE_PARSE_ERROR)) {
        os += (first ? "" : " | ");
        os += "LICENSE_PARSE_ERROR";
        first = false;
        flipped |= ::android::hardware::drm::V1_4::Status::LICENSE_PARSE_ERROR;
    }
    if ((o & ::android::hardware::drm::V1_4::Status::LICENSE_POLICY_ERROR) == static_cast<uint32_t>(::android::hardware::drm::V1_4::Status::LICENSE_POLICY_ERROR)) {
        os += (first ? "" : " | ");
        os += "LICENSE_POLICY_ERROR";
        first = false;
        flipped |= ::android::hardware::drm::V1_4::Status::LICENSE_POLICY_ERROR;
    }
    if ((o & ::android::hardware::drm::V1_4::Status::LICENSE_RELEASE_ERROR) == static_cast<uint32_t>(::android::hardware::drm::V1_4::Status::LICENSE_RELEASE_ERROR)) {
        os += (first ? "" : " | ");
        os += "LICENSE_RELEASE_ERROR";
        first = false;
        flipped |= ::android::hardware::drm::V1_4::Status::LICENSE_RELEASE_ERROR;
    }
    if ((o & ::android::hardware::drm::V1_4::Status::LICENSE_REQUEST_REJECTED) == static_cast<uint32_t>(::android::hardware::drm::V1_4::Status::LICENSE_REQUEST_REJECTED)) {
        os += (first ? "" : " | ");
        os += "LICENSE_REQUEST_REJECTED";
        first = false;
        flipped |= ::android::hardware::drm::V1_4::Status::LICENSE_REQUEST_REJECTED;
    }
    if ((o & ::android::hardware::drm::V1_4::Status::LICENSE_RESTORE_ERROR) == static_cast<uint32_t>(::android::hardware::drm::V1_4::Status::LICENSE_RESTORE_ERROR)) {
        os += (first ? "" : " | ");
        os += "LICENSE_RESTORE_ERROR";
        first = false;
        flipped |= ::android::hardware::drm::V1_4::Status::LICENSE_RESTORE_ERROR;
    }
    if ((o & ::android::hardware::drm::V1_4::Status::LICENSE_STATE_ERROR) == static_cast<uint32_t>(::android::hardware::drm::V1_4::Status::LICENSE_STATE_ERROR)) {
        os += (first ? "" : " | ");
        os += "LICENSE_STATE_ERROR";
        first = false;
        flipped |= ::android::hardware::drm::V1_4::Status::LICENSE_STATE_ERROR;
    }
    if ((o & ::android::hardware::drm::V1_4::Status::MALFORMED_CERTIFICATE) == static_cast<uint32_t>(::android::hardware::drm::V1_4::Status::MALFORMED_CERTIFICATE)) {
        os += (first ? "" : " | ");
        os += "MALFORMED_CERTIFICATE";
        first = false;
        flipped |= ::android::hardware::drm::V1_4::Status::MALFORMED_CERTIFICATE;
    }
    if ((o & ::android::hardware::drm::V1_4::Status::MEDIA_FRAMEWORK_ERROR) == static_cast<uint32_t>(::android::hardware::drm::V1_4::Status::MEDIA_FRAMEWORK_ERROR)) {
        os += (first ? "" : " | ");
        os += "MEDIA_FRAMEWORK_ERROR";
        first = false;
        flipped |= ::android::hardware::drm::V1_4::Status::MEDIA_FRAMEWORK_ERROR;
    }
    if ((o & ::android::hardware::drm::V1_4::Status::MISSING_CERTIFICATE) == static_cast<uint32_t>(::android::hardware::drm::V1_4::Status::MISSING_CERTIFICATE)) {
        os += (first ? "" : " | ");
        os += "MISSING_CERTIFICATE";
        first = false;
        flipped |= ::android::hardware::drm::V1_4::Status::MISSING_CERTIFICATE;
    }
    if ((o & ::android::hardware::drm::V1_4::Status::PROVISIONING_CERTIFICATE_ERROR) == static_cast<uint32_t>(::android::hardware::drm::V1_4::Status::PROVISIONING_CERTIFICATE_ERROR)) {
        os += (first ? "" : " | ");
        os += "PROVISIONING_CERTIFICATE_ERROR";
        first = false;
        flipped |= ::android::hardware::drm::V1_4::Status::PROVISIONING_CERTIFICATE_ERROR;
    }
    if ((o & ::android::hardware::drm::V1_4::Status::PROVISIONING_CONFIGURATION_ERROR) == static_cast<uint32_t>(::android::hardware::drm::V1_4::Status::PROVISIONING_CONFIGURATION_ERROR)) {
        os += (first ? "" : " | ");
        os += "PROVISIONING_CONFIGURATION_ERROR";
        first = false;
        flipped |= ::android::hardware::drm::V1_4::Status::PROVISIONING_CONFIGURATION_ERROR;
    }
    if ((o & ::android::hardware::drm::V1_4::Status::PROVISIONING_PARSE_ERROR) == static_cast<uint32_t>(::android::hardware::drm::V1_4::Status::PROVISIONING_PARSE_ERROR)) {
        os += (first ? "" : " | ");
        os += "PROVISIONING_PARSE_ERROR";
        first = false;
        flipped |= ::android::hardware::drm::V1_4::Status::PROVISIONING_PARSE_ERROR;
    }
    if ((o & ::android::hardware::drm::V1_4::Status::PROVISIONING_REQUEST_REJECTED) == static_cast<uint32_t>(::android::hardware::drm::V1_4::Status::PROVISIONING_REQUEST_REJECTED)) {
        os += (first ? "" : " | ");
        os += "PROVISIONING_REQUEST_REJECTED";
        first = false;
        flipped |= ::android::hardware::drm::V1_4::Status::PROVISIONING_REQUEST_REJECTED;
    }
    if ((o & ::android::hardware::drm::V1_4::Status::RETRYABLE_PROVISIONING_ERROR) == static_cast<uint32_t>(::android::hardware::drm::V1_4::Status::RETRYABLE_PROVISIONING_ERROR)) {
        os += (first ? "" : " | ");
        os += "RETRYABLE_PROVISIONING_ERROR";
        first = false;
        flipped |= ::android::hardware::drm::V1_4::Status::RETRYABLE_PROVISIONING_ERROR;
    }
    if ((o & ::android::hardware::drm::V1_4::Status::SECURE_STOP_RELEASE_ERROR) == static_cast<uint32_t>(::android::hardware::drm::V1_4::Status::SECURE_STOP_RELEASE_ERROR)) {
        os += (first ? "" : " | ");
        os += "SECURE_STOP_RELEASE_ERROR";
        first = false;
        flipped |= ::android::hardware::drm::V1_4::Status::SECURE_STOP_RELEASE_ERROR;
    }
    if ((o & ::android::hardware::drm::V1_4::Status::STORAGE_READ_FAILURE) == static_cast<uint32_t>(::android::hardware::drm::V1_4::Status::STORAGE_READ_FAILURE)) {
        os += (first ? "" : " | ");
        os += "STORAGE_READ_FAILURE";
        first = false;
        flipped |= ::android::hardware::drm::V1_4::Status::STORAGE_READ_FAILURE;
    }
    if ((o & ::android::hardware::drm::V1_4::Status::STORAGE_WRITE_FAILURE) == static_cast<uint32_t>(::android::hardware::drm::V1_4::Status::STORAGE_WRITE_FAILURE)) {
        os += (first ? "" : " | ");
        os += "STORAGE_WRITE_FAILURE";
        first = false;
        flipped |= ::android::hardware::drm::V1_4::Status::STORAGE_WRITE_FAILURE;
    }
    if (o != flipped) {
        os += (first ? "" : " | ");
        os += toHexString(o & (~flipped));
    }os += " (";
    os += toHexString(o);
    os += ")";
    return os;
}

static inline std::string toString(::android::hardware::drm::V1_4::Status o) {
    using ::android::hardware::details::toHexString;
    if (o == ::android::hardware::drm::V1_4::Status::OK) {
        return "OK";
    }
    if (o == ::android::hardware::drm::V1_4::Status::ERROR_DRM_NO_LICENSE) {
        return "ERROR_DRM_NO_LICENSE";
    }
    if (o == ::android::hardware::drm::V1_4::Status::ERROR_DRM_LICENSE_EXPIRED) {
        return "ERROR_DRM_LICENSE_EXPIRED";
    }
    if (o == ::android::hardware::drm::V1_4::Status::ERROR_DRM_SESSION_NOT_OPENED) {
        return "ERROR_DRM_SESSION_NOT_OPENED";
    }
    if (o == ::android::hardware::drm::V1_4::Status::ERROR_DRM_CANNOT_HANDLE) {
        return "ERROR_DRM_CANNOT_HANDLE";
    }
    if (o == ::android::hardware::drm::V1_4::Status::ERROR_DRM_INVALID_STATE) {
        return "ERROR_DRM_INVALID_STATE";
    }
    if (o == ::android::hardware::drm::V1_4::Status::BAD_VALUE) {
        return "BAD_VALUE";
    }
    if (o == ::android::hardware::drm::V1_4::Status::ERROR_DRM_NOT_PROVISIONED) {
        return "ERROR_DRM_NOT_PROVISIONED";
    }
    if (o == ::android::hardware::drm::V1_4::Status::ERROR_DRM_RESOURCE_BUSY) {
        return "ERROR_DRM_RESOURCE_BUSY";
    }
    if (o == ::android::hardware::drm::V1_4::Status::ERROR_DRM_INSUFFICIENT_OUTPUT_PROTECTION) {
        return "ERROR_DRM_INSUFFICIENT_OUTPUT_PROTECTION";
    }
    if (o == ::android::hardware::drm::V1_4::Status::ERROR_DRM_DEVICE_REVOKED) {
        return "ERROR_DRM_DEVICE_REVOKED";
    }
    if (o == ::android::hardware::drm::V1_4::Status::ERROR_DRM_DECRYPT) {
        return "ERROR_DRM_DECRYPT";
    }
    if (o == ::android::hardware::drm::V1_4::Status::ERROR_DRM_UNKNOWN) {
        return "ERROR_DRM_UNKNOWN";
    }
    if (o == ::android::hardware::drm::V1_4::Status::ERROR_DRM_INSUFFICIENT_SECURITY) {
        return "ERROR_DRM_INSUFFICIENT_SECURITY";
    }
    if (o == ::android::hardware::drm::V1_4::Status::ERROR_DRM_FRAME_TOO_LARGE) {
        return "ERROR_DRM_FRAME_TOO_LARGE";
    }
    if (o == ::android::hardware::drm::V1_4::Status::ERROR_DRM_SESSION_LOST_STATE) {
        return "ERROR_DRM_SESSION_LOST_STATE";
    }
    if (o == ::android::hardware::drm::V1_4::Status::ERROR_DRM_RESOURCE_CONTENTION) {
        return "ERROR_DRM_RESOURCE_CONTENTION";
    }
    if (o == ::android::hardware::drm::V1_4::Status::CANNOT_DECRYPT_ZERO_SUBSAMPLES) {
        return "CANNOT_DECRYPT_ZERO_SUBSAMPLES";
    }
    if (o == ::android::hardware::drm::V1_4::Status::CRYPTO_LIBRARY_ERROR) {
        return "CRYPTO_LIBRARY_ERROR";
    }
    if (o == ::android::hardware::drm::V1_4::Status::GENERAL_OEM_ERROR) {
        return "GENERAL_OEM_ERROR";
    }
    if (o == ::android::hardware::drm::V1_4::Status::GENERAL_PLUGIN_ERROR) {
        return "GENERAL_PLUGIN_ERROR";
    }
    if (o == ::android::hardware::drm::V1_4::Status::INIT_DATA_INVALID) {
        return "INIT_DATA_INVALID";
    }
    if (o == ::android::hardware::drm::V1_4::Status::KEY_NOT_LOADED) {
        return "KEY_NOT_LOADED";
    }
    if (o == ::android::hardware::drm::V1_4::Status::LICENSE_PARSE_ERROR) {
        return "LICENSE_PARSE_ERROR";
    }
    if (o == ::android::hardware::drm::V1_4::Status::LICENSE_POLICY_ERROR) {
        return "LICENSE_POLICY_ERROR";
    }
    if (o == ::android::hardware::drm::V1_4::Status::LICENSE_RELEASE_ERROR) {
        return "LICENSE_RELEASE_ERROR";
    }
    if (o == ::android::hardware::drm::V1_4::Status::LICENSE_REQUEST_REJECTED) {
        return "LICENSE_REQUEST_REJECTED";
    }
    if (o == ::android::hardware::drm::V1_4::Status::LICENSE_RESTORE_ERROR) {
        return "LICENSE_RESTORE_ERROR";
    }
    if (o == ::android::hardware::drm::V1_4::Status::LICENSE_STATE_ERROR) {
        return "LICENSE_STATE_ERROR";
    }
    if (o == ::android::hardware::drm::V1_4::Status::MALFORMED_CERTIFICATE) {
        return "MALFORMED_CERTIFICATE";
    }
    if (o == ::android::hardware::drm::V1_4::Status::MEDIA_FRAMEWORK_ERROR) {
        return "MEDIA_FRAMEWORK_ERROR";
    }
    if (o == ::android::hardware::drm::V1_4::Status::MISSING_CERTIFICATE) {
        return "MISSING_CERTIFICATE";
    }
    if (o == ::android::hardware::drm::V1_4::Status::PROVISIONING_CERTIFICATE_ERROR) {
        return "PROVISIONING_CERTIFICATE_ERROR";
    }
    if (o == ::android::hardware::drm::V1_4::Status::PROVISIONING_CONFIGURATION_ERROR) {
        return "PROVISIONING_CONFIGURATION_ERROR";
    }
    if (o == ::android::hardware::drm::V1_4::Status::PROVISIONING_PARSE_ERROR) {
        return "PROVISIONING_PARSE_ERROR";
    }
    if (o == ::android::hardware::drm::V1_4::Status::PROVISIONING_REQUEST_REJECTED) {
        return "PROVISIONING_REQUEST_REJECTED";
    }
    if (o == ::android::hardware::drm::V1_4::Status::RETRYABLE_PROVISIONING_ERROR) {
        return "RETRYABLE_PROVISIONING_ERROR";
    }
    if (o == ::android::hardware::drm::V1_4::Status::SECURE_STOP_RELEASE_ERROR) {
        return "SECURE_STOP_RELEASE_ERROR";
    }
    if (o == ::android::hardware::drm::V1_4::Status::STORAGE_READ_FAILURE) {
        return "STORAGE_READ_FAILURE";
    }
    if (o == ::android::hardware::drm::V1_4::Status::STORAGE_WRITE_FAILURE) {
        return "STORAGE_WRITE_FAILURE";
    }
    std::string os;
    os += toHexString(static_cast<uint32_t>(o));
    return os;
}

static inline void PrintTo(::android::hardware::drm::V1_4::Status o, ::std::ostream* os) {
    *os << toString(o);
}


}  // namespace V1_4
}  // namespace drm
}  // namespace hardware
}  // namespace android

//
// global type declarations for package
//

namespace android {
namespace hardware {
namespace details {
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wc++17-extensions"
template<> inline constexpr std::array<::android::hardware::drm::V1_4::LogPriority, 8> hidl_enum_values<::android::hardware::drm::V1_4::LogPriority> = {
    ::android::hardware::drm::V1_4::LogPriority::UNKNOWN,
    ::android::hardware::drm::V1_4::LogPriority::DEFAULT,
    ::android::hardware::drm::V1_4::LogPriority::VERBOSE,
    ::android::hardware::drm::V1_4::LogPriority::DEBUG,
    ::android::hardware::drm::V1_4::LogPriority::INFO,
    ::android::hardware::drm::V1_4::LogPriority::WARN,
    ::android::hardware::drm::V1_4::LogPriority::ERROR,
    ::android::hardware::drm::V1_4::LogPriority::FATAL,
};
#pragma clang diagnostic pop
}  // namespace details
}  // namespace hardware
}  // namespace android

namespace android {
namespace hardware {
namespace details {
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wc++17-extensions"
template<> inline constexpr std::array<::android::hardware::drm::V1_4::Status, 40> hidl_enum_values<::android::hardware::drm::V1_4::Status> = {
    ::android::hardware::drm::V1_4::Status::OK,
    ::android::hardware::drm::V1_4::Status::ERROR_DRM_NO_LICENSE,
    ::android::hardware::drm::V1_4::Status::ERROR_DRM_LICENSE_EXPIRED,
    ::android::hardware::drm::V1_4::Status::ERROR_DRM_SESSION_NOT_OPENED,
    ::android::hardware::drm::V1_4::Status::ERROR_DRM_CANNOT_HANDLE,
    ::android::hardware::drm::V1_4::Status::ERROR_DRM_INVALID_STATE,
    ::android::hardware::drm::V1_4::Status::BAD_VALUE,
    ::android::hardware::drm::V1_4::Status::ERROR_DRM_NOT_PROVISIONED,
    ::android::hardware::drm::V1_4::Status::ERROR_DRM_RESOURCE_BUSY,
    ::android::hardware::drm::V1_4::Status::ERROR_DRM_INSUFFICIENT_OUTPUT_PROTECTION,
    ::android::hardware::drm::V1_4::Status::ERROR_DRM_DEVICE_REVOKED,
    ::android::hardware::drm::V1_4::Status::ERROR_DRM_DECRYPT,
    ::android::hardware::drm::V1_4::Status::ERROR_DRM_UNKNOWN,
    ::android::hardware::drm::V1_4::Status::ERROR_DRM_INSUFFICIENT_SECURITY,
    ::android::hardware::drm::V1_4::Status::ERROR_DRM_FRAME_TOO_LARGE,
    ::android::hardware::drm::V1_4::Status::ERROR_DRM_SESSION_LOST_STATE,
    ::android::hardware::drm::V1_4::Status::ERROR_DRM_RESOURCE_CONTENTION,
    ::android::hardware::drm::V1_4::Status::CANNOT_DECRYPT_ZERO_SUBSAMPLES,
    ::android::hardware::drm::V1_4::Status::CRYPTO_LIBRARY_ERROR,
    ::android::hardware::drm::V1_4::Status::GENERAL_OEM_ERROR,
    ::android::hardware::drm::V1_4::Status::GENERAL_PLUGIN_ERROR,
    ::android::hardware::drm::V1_4::Status::INIT_DATA_INVALID,
    ::android::hardware::drm::V1_4::Status::KEY_NOT_LOADED,
    ::android::hardware::drm::V1_4::Status::LICENSE_PARSE_ERROR,
    ::android::hardware::drm::V1_4::Status::LICENSE_POLICY_ERROR,
    ::android::hardware::drm::V1_4::Status::LICENSE_RELEASE_ERROR,
    ::android::hardware::drm::V1_4::Status::LICENSE_REQUEST_REJECTED,
    ::android::hardware::drm::V1_4::Status::LICENSE_RESTORE_ERROR,
    ::android::hardware::drm::V1_4::Status::LICENSE_STATE_ERROR,
    ::android::hardware::drm::V1_4::Status::MALFORMED_CERTIFICATE,
    ::android::hardware::drm::V1_4::Status::MEDIA_FRAMEWORK_ERROR,
    ::android::hardware::drm::V1_4::Status::MISSING_CERTIFICATE,
    ::android::hardware::drm::V1_4::Status::PROVISIONING_CERTIFICATE_ERROR,
    ::android::hardware::drm::V1_4::Status::PROVISIONING_CONFIGURATION_ERROR,
    ::android::hardware::drm::V1_4::Status::PROVISIONING_PARSE_ERROR,
    ::android::hardware::drm::V1_4::Status::PROVISIONING_REQUEST_REJECTED,
    ::android::hardware::drm::V1_4::Status::RETRYABLE_PROVISIONING_ERROR,
    ::android::hardware::drm::V1_4::Status::SECURE_STOP_RELEASE_ERROR,
    ::android::hardware::drm::V1_4::Status::STORAGE_READ_FAILURE,
    ::android::hardware::drm::V1_4::Status::STORAGE_WRITE_FAILURE,
};
#pragma clang diagnostic pop
}  // namespace details
}  // namespace hardware
}  // namespace android


#endif  // HIDL_GENERATED_ANDROID_HARDWARE_DRM_V1_4_TYPES_H
