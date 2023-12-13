#ifndef HIDL_GENERATED_VENDOR_XIAOMI_HARDWARE_MOTOR_V1_0_TYPES_H
#define HIDL_GENERATED_VENDOR_XIAOMI_HARDWARE_MOTOR_V1_0_TYPES_H

#include <hidl/HidlSupport.h>
#include <hidl/MQDescriptor.h>
#include <utils/NativeHandle.h>
#include <utils/misc.h>

namespace vendor {
namespace xiaomi {
namespace hardware {
namespace motor {
namespace V1_0 {

// Forward declaration for forward reference support:
struct MotorEvent;

struct MotorEvent final {
    int32_t vaalue __attribute__ ((aligned(4)));
    int32_t cookie __attribute__ ((aligned(4)));
};

static_assert(offsetof(::vendor::xiaomi::hardware::motor::V1_0::MotorEvent, vaalue) == 0, "wrong offset");
static_assert(offsetof(::vendor::xiaomi::hardware::motor::V1_0::MotorEvent, cookie) == 4, "wrong offset");
static_assert(sizeof(::vendor::xiaomi::hardware::motor::V1_0::MotorEvent) == 8, "wrong size");
static_assert(__alignof(::vendor::xiaomi::hardware::motor::V1_0::MotorEvent) == 4, "wrong alignment");

//
// type declarations for package
//

static inline std::string toString(const ::vendor::xiaomi::hardware::motor::V1_0::MotorEvent& o);
static inline void PrintTo(const ::vendor::xiaomi::hardware::motor::V1_0::MotorEvent& o, ::std::ostream*);
static inline bool operator==(const ::vendor::xiaomi::hardware::motor::V1_0::MotorEvent& lhs, const ::vendor::xiaomi::hardware::motor::V1_0::MotorEvent& rhs);
static inline bool operator!=(const ::vendor::xiaomi::hardware::motor::V1_0::MotorEvent& lhs, const ::vendor::xiaomi::hardware::motor::V1_0::MotorEvent& rhs);

//
// type header definitions for package
//

static inline std::string toString(const ::vendor::xiaomi::hardware::motor::V1_0::MotorEvent& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".vaalue = ";
    os += ::android::hardware::toString(o.vaalue);
    os += ", .cookie = ";
    os += ::android::hardware::toString(o.cookie);
    os += "}"; return os;
}

static inline void PrintTo(const ::vendor::xiaomi::hardware::motor::V1_0::MotorEvent& o, ::std::ostream* os) {
    *os << toString(o);
}

static inline bool operator==(const ::vendor::xiaomi::hardware::motor::V1_0::MotorEvent& lhs, const ::vendor::xiaomi::hardware::motor::V1_0::MotorEvent& rhs) {
    if (lhs.vaalue != rhs.vaalue) {
        return false;
    }
    if (lhs.cookie != rhs.cookie) {
        return false;
    }
    return true;
}

static inline bool operator!=(const ::vendor::xiaomi::hardware::motor::V1_0::MotorEvent& lhs, const ::vendor::xiaomi::hardware::motor::V1_0::MotorEvent& rhs){
    return !(lhs == rhs);
}


}  // namespace V1_0
}  // namespace motor
}  // namespace hardware
}  // namespace xiaomi
}  // namespace vendor

//
// global type declarations for package
//


#endif  // HIDL_GENERATED_VENDOR_XIAOMI_HARDWARE_MOTOR_V1_0_TYPES_H
