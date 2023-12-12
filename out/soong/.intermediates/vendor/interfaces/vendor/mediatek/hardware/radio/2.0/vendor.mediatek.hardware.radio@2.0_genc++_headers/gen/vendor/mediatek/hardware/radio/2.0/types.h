#ifndef HIDL_GENERATED_VENDOR_MEDIATEK_HARDWARE_RADIO_V2_0_TYPES_H
#define HIDL_GENERATED_VENDOR_MEDIATEK_HARDWARE_RADIO_V2_0_TYPES_H

#include <android/hardware/radio/1.0/types.h>

#include <hidl/HidlSupport.h>
#include <hidl/MQDescriptor.h>
#include <utils/NativeHandle.h>
#include <utils/misc.h>

namespace vendor {
namespace mediatek {
namespace hardware {
namespace radio {
namespace V2_0 {

// Forward declaration for forward reference support:
struct MtkDataProfileInfo;
struct IncomingCallNotification;
struct MtkSetupDataCallResult;

struct MtkDataProfileInfo final {
    ::android::hardware::radio::V1_0::DataProfileInfo dpi __attribute__ ((aligned(8)));
    int32_t inactiveTimer __attribute__ ((aligned(4)));
};

static_assert(offsetof(::vendor::mediatek::hardware::radio::V2_0::MtkDataProfileInfo, dpi) == 0, "wrong offset");
static_assert(offsetof(::vendor::mediatek::hardware::radio::V2_0::MtkDataProfileInfo, inactiveTimer) == 152, "wrong offset");
static_assert(sizeof(::vendor::mediatek::hardware::radio::V2_0::MtkDataProfileInfo) == 160, "wrong size");
static_assert(__alignof(::vendor::mediatek::hardware::radio::V2_0::MtkDataProfileInfo) == 8, "wrong alignment");

struct IncomingCallNotification final {
    ::android::hardware::hidl_string callId __attribute__ ((aligned(8)));
    ::android::hardware::hidl_string number __attribute__ ((aligned(8)));
    ::android::hardware::hidl_string type __attribute__ ((aligned(8)));
    ::android::hardware::hidl_string callMode __attribute__ ((aligned(8)));
    ::android::hardware::hidl_string seqNo __attribute__ ((aligned(8)));
    ::android::hardware::hidl_string redirectNumber __attribute__ ((aligned(8)));
    ::android::hardware::hidl_string toNumber __attribute__ ((aligned(8)));
};

static_assert(offsetof(::vendor::mediatek::hardware::radio::V2_0::IncomingCallNotification, callId) == 0, "wrong offset");
static_assert(offsetof(::vendor::mediatek::hardware::radio::V2_0::IncomingCallNotification, number) == 16, "wrong offset");
static_assert(offsetof(::vendor::mediatek::hardware::radio::V2_0::IncomingCallNotification, type) == 32, "wrong offset");
static_assert(offsetof(::vendor::mediatek::hardware::radio::V2_0::IncomingCallNotification, callMode) == 48, "wrong offset");
static_assert(offsetof(::vendor::mediatek::hardware::radio::V2_0::IncomingCallNotification, seqNo) == 64, "wrong offset");
static_assert(offsetof(::vendor::mediatek::hardware::radio::V2_0::IncomingCallNotification, redirectNumber) == 80, "wrong offset");
static_assert(offsetof(::vendor::mediatek::hardware::radio::V2_0::IncomingCallNotification, toNumber) == 96, "wrong offset");
static_assert(sizeof(::vendor::mediatek::hardware::radio::V2_0::IncomingCallNotification) == 112, "wrong size");
static_assert(__alignof(::vendor::mediatek::hardware::radio::V2_0::IncomingCallNotification) == 8, "wrong alignment");

struct MtkSetupDataCallResult final {
    ::android::hardware::radio::V1_0::SetupDataCallResult dcr __attribute__ ((aligned(8)));
    int32_t rat __attribute__ ((aligned(4)));
};

static_assert(offsetof(::vendor::mediatek::hardware::radio::V2_0::MtkSetupDataCallResult, dcr) == 0, "wrong offset");
static_assert(offsetof(::vendor::mediatek::hardware::radio::V2_0::MtkSetupDataCallResult, rat) == 120, "wrong offset");
static_assert(sizeof(::vendor::mediatek::hardware::radio::V2_0::MtkSetupDataCallResult) == 128, "wrong size");
static_assert(__alignof(::vendor::mediatek::hardware::radio::V2_0::MtkSetupDataCallResult) == 8, "wrong alignment");

//
// type declarations for package
//

static inline std::string toString(const ::vendor::mediatek::hardware::radio::V2_0::MtkDataProfileInfo& o);
static inline void PrintTo(const ::vendor::mediatek::hardware::radio::V2_0::MtkDataProfileInfo& o, ::std::ostream*);
static inline bool operator==(const ::vendor::mediatek::hardware::radio::V2_0::MtkDataProfileInfo& lhs, const ::vendor::mediatek::hardware::radio::V2_0::MtkDataProfileInfo& rhs);
static inline bool operator!=(const ::vendor::mediatek::hardware::radio::V2_0::MtkDataProfileInfo& lhs, const ::vendor::mediatek::hardware::radio::V2_0::MtkDataProfileInfo& rhs);

static inline std::string toString(const ::vendor::mediatek::hardware::radio::V2_0::IncomingCallNotification& o);
static inline void PrintTo(const ::vendor::mediatek::hardware::radio::V2_0::IncomingCallNotification& o, ::std::ostream*);
static inline bool operator==(const ::vendor::mediatek::hardware::radio::V2_0::IncomingCallNotification& lhs, const ::vendor::mediatek::hardware::radio::V2_0::IncomingCallNotification& rhs);
static inline bool operator!=(const ::vendor::mediatek::hardware::radio::V2_0::IncomingCallNotification& lhs, const ::vendor::mediatek::hardware::radio::V2_0::IncomingCallNotification& rhs);

static inline std::string toString(const ::vendor::mediatek::hardware::radio::V2_0::MtkSetupDataCallResult& o);
static inline void PrintTo(const ::vendor::mediatek::hardware::radio::V2_0::MtkSetupDataCallResult& o, ::std::ostream*);
static inline bool operator==(const ::vendor::mediatek::hardware::radio::V2_0::MtkSetupDataCallResult& lhs, const ::vendor::mediatek::hardware::radio::V2_0::MtkSetupDataCallResult& rhs);
static inline bool operator!=(const ::vendor::mediatek::hardware::radio::V2_0::MtkSetupDataCallResult& lhs, const ::vendor::mediatek::hardware::radio::V2_0::MtkSetupDataCallResult& rhs);

//
// type header definitions for package
//

static inline std::string toString(const ::vendor::mediatek::hardware::radio::V2_0::MtkDataProfileInfo& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".dpi = ";
    os += ::android::hardware::radio::V1_0::toString(o.dpi);
    os += ", .inactiveTimer = ";
    os += ::android::hardware::toString(o.inactiveTimer);
    os += "}"; return os;
}

static inline void PrintTo(const ::vendor::mediatek::hardware::radio::V2_0::MtkDataProfileInfo& o, ::std::ostream* os) {
    *os << toString(o);
}

static inline bool operator==(const ::vendor::mediatek::hardware::radio::V2_0::MtkDataProfileInfo& lhs, const ::vendor::mediatek::hardware::radio::V2_0::MtkDataProfileInfo& rhs) {
    if (lhs.dpi != rhs.dpi) {
        return false;
    }
    if (lhs.inactiveTimer != rhs.inactiveTimer) {
        return false;
    }
    return true;
}

static inline bool operator!=(const ::vendor::mediatek::hardware::radio::V2_0::MtkDataProfileInfo& lhs, const ::vendor::mediatek::hardware::radio::V2_0::MtkDataProfileInfo& rhs){
    return !(lhs == rhs);
}

static inline std::string toString(const ::vendor::mediatek::hardware::radio::V2_0::IncomingCallNotification& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".callId = ";
    os += ::android::hardware::toString(o.callId);
    os += ", .number = ";
    os += ::android::hardware::toString(o.number);
    os += ", .type = ";
    os += ::android::hardware::toString(o.type);
    os += ", .callMode = ";
    os += ::android::hardware::toString(o.callMode);
    os += ", .seqNo = ";
    os += ::android::hardware::toString(o.seqNo);
    os += ", .redirectNumber = ";
    os += ::android::hardware::toString(o.redirectNumber);
    os += ", .toNumber = ";
    os += ::android::hardware::toString(o.toNumber);
    os += "}"; return os;
}

static inline void PrintTo(const ::vendor::mediatek::hardware::radio::V2_0::IncomingCallNotification& o, ::std::ostream* os) {
    *os << toString(o);
}

static inline bool operator==(const ::vendor::mediatek::hardware::radio::V2_0::IncomingCallNotification& lhs, const ::vendor::mediatek::hardware::radio::V2_0::IncomingCallNotification& rhs) {
    if (lhs.callId != rhs.callId) {
        return false;
    }
    if (lhs.number != rhs.number) {
        return false;
    }
    if (lhs.type != rhs.type) {
        return false;
    }
    if (lhs.callMode != rhs.callMode) {
        return false;
    }
    if (lhs.seqNo != rhs.seqNo) {
        return false;
    }
    if (lhs.redirectNumber != rhs.redirectNumber) {
        return false;
    }
    if (lhs.toNumber != rhs.toNumber) {
        return false;
    }
    return true;
}

static inline bool operator!=(const ::vendor::mediatek::hardware::radio::V2_0::IncomingCallNotification& lhs, const ::vendor::mediatek::hardware::radio::V2_0::IncomingCallNotification& rhs){
    return !(lhs == rhs);
}

static inline std::string toString(const ::vendor::mediatek::hardware::radio::V2_0::MtkSetupDataCallResult& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".dcr = ";
    os += ::android::hardware::radio::V1_0::toString(o.dcr);
    os += ", .rat = ";
    os += ::android::hardware::toString(o.rat);
    os += "}"; return os;
}

static inline void PrintTo(const ::vendor::mediatek::hardware::radio::V2_0::MtkSetupDataCallResult& o, ::std::ostream* os) {
    *os << toString(o);
}

static inline bool operator==(const ::vendor::mediatek::hardware::radio::V2_0::MtkSetupDataCallResult& lhs, const ::vendor::mediatek::hardware::radio::V2_0::MtkSetupDataCallResult& rhs) {
    if (lhs.dcr != rhs.dcr) {
        return false;
    }
    if (lhs.rat != rhs.rat) {
        return false;
    }
    return true;
}

static inline bool operator!=(const ::vendor::mediatek::hardware::radio::V2_0::MtkSetupDataCallResult& lhs, const ::vendor::mediatek::hardware::radio::V2_0::MtkSetupDataCallResult& rhs){
    return !(lhs == rhs);
}


}  // namespace V2_0
}  // namespace radio
}  // namespace hardware
}  // namespace mediatek
}  // namespace vendor

//
// global type declarations for package
//


#endif  // HIDL_GENERATED_VENDOR_MEDIATEK_HARDWARE_RADIO_V2_0_TYPES_H
