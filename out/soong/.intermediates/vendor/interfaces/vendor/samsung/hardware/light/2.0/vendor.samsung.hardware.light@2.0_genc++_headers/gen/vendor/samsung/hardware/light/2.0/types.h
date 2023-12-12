#ifndef HIDL_GENERATED_VENDOR_SAMSUNG_HARDWARE_LIGHT_V2_0_TYPES_H
#define HIDL_GENERATED_VENDOR_SAMSUNG_HARDWARE_LIGHT_V2_0_TYPES_H

#include <hidl/HidlSupport.h>
#include <hidl/MQDescriptor.h>
#include <utils/NativeHandle.h>
#include <utils/misc.h>

namespace vendor {
namespace samsung {
namespace hardware {
namespace light {
namespace V2_0 {

// Forward declaration for forward reference support:
enum class SecType : uint32_t;

enum class SecType : uint32_t {
    BACKLIGHT = 0u,
    KEYBOARD = 1u,
    BUTTONS = 2u,
    BATTERY = 3u,
    NOTIFICATIONS = 4u,
    ATTENTION = 5u,
    BLUETOOTH = 6u,
    WIFI = 7u,
    SUBBACKLIGHT = 8u,
    LED_LTE = 9u,
    LED_GIGALTE = 10u,
    LED_WIFI = 11u,
    LED_BATTERY = 12u,
    LED_ALL = 13u,
    COUNT = 14u,
};

//
// type declarations for package
//

template<typename>
static inline std::string toString(uint32_t o);
static inline std::string toString(::vendor::samsung::hardware::light::V2_0::SecType o);
static inline void PrintTo(::vendor::samsung::hardware::light::V2_0::SecType o, ::std::ostream* os);
constexpr uint32_t operator|(const ::vendor::samsung::hardware::light::V2_0::SecType lhs, const ::vendor::samsung::hardware::light::V2_0::SecType rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) | static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator|(const uint32_t lhs, const ::vendor::samsung::hardware::light::V2_0::SecType rhs) {
    return static_cast<uint32_t>(lhs | static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator|(const ::vendor::samsung::hardware::light::V2_0::SecType lhs, const uint32_t rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) | rhs);
}
constexpr uint32_t operator&(const ::vendor::samsung::hardware::light::V2_0::SecType lhs, const ::vendor::samsung::hardware::light::V2_0::SecType rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) & static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator&(const uint32_t lhs, const ::vendor::samsung::hardware::light::V2_0::SecType rhs) {
    return static_cast<uint32_t>(lhs & static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator&(const ::vendor::samsung::hardware::light::V2_0::SecType lhs, const uint32_t rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) & rhs);
}
constexpr uint32_t &operator|=(uint32_t& v, const ::vendor::samsung::hardware::light::V2_0::SecType e) {
    v |= static_cast<uint32_t>(e);
    return v;
}
constexpr uint32_t &operator&=(uint32_t& v, const ::vendor::samsung::hardware::light::V2_0::SecType e) {
    v &= static_cast<uint32_t>(e);
    return v;
}

//
// type header definitions for package
//

template<>
inline std::string toString<::vendor::samsung::hardware::light::V2_0::SecType>(uint32_t o) {
    using ::android::hardware::details::toHexString;
    std::string os;
    ::android::hardware::hidl_bitfield<::vendor::samsung::hardware::light::V2_0::SecType> flipped = 0;
    bool first = true;
    if ((o & ::vendor::samsung::hardware::light::V2_0::SecType::BACKLIGHT) == static_cast<uint32_t>(::vendor::samsung::hardware::light::V2_0::SecType::BACKLIGHT)) {
        os += (first ? "" : " | ");
        os += "BACKLIGHT";
        first = false;
        flipped |= ::vendor::samsung::hardware::light::V2_0::SecType::BACKLIGHT;
    }
    if ((o & ::vendor::samsung::hardware::light::V2_0::SecType::KEYBOARD) == static_cast<uint32_t>(::vendor::samsung::hardware::light::V2_0::SecType::KEYBOARD)) {
        os += (first ? "" : " | ");
        os += "KEYBOARD";
        first = false;
        flipped |= ::vendor::samsung::hardware::light::V2_0::SecType::KEYBOARD;
    }
    if ((o & ::vendor::samsung::hardware::light::V2_0::SecType::BUTTONS) == static_cast<uint32_t>(::vendor::samsung::hardware::light::V2_0::SecType::BUTTONS)) {
        os += (first ? "" : " | ");
        os += "BUTTONS";
        first = false;
        flipped |= ::vendor::samsung::hardware::light::V2_0::SecType::BUTTONS;
    }
    if ((o & ::vendor::samsung::hardware::light::V2_0::SecType::BATTERY) == static_cast<uint32_t>(::vendor::samsung::hardware::light::V2_0::SecType::BATTERY)) {
        os += (first ? "" : " | ");
        os += "BATTERY";
        first = false;
        flipped |= ::vendor::samsung::hardware::light::V2_0::SecType::BATTERY;
    }
    if ((o & ::vendor::samsung::hardware::light::V2_0::SecType::NOTIFICATIONS) == static_cast<uint32_t>(::vendor::samsung::hardware::light::V2_0::SecType::NOTIFICATIONS)) {
        os += (first ? "" : " | ");
        os += "NOTIFICATIONS";
        first = false;
        flipped |= ::vendor::samsung::hardware::light::V2_0::SecType::NOTIFICATIONS;
    }
    if ((o & ::vendor::samsung::hardware::light::V2_0::SecType::ATTENTION) == static_cast<uint32_t>(::vendor::samsung::hardware::light::V2_0::SecType::ATTENTION)) {
        os += (first ? "" : " | ");
        os += "ATTENTION";
        first = false;
        flipped |= ::vendor::samsung::hardware::light::V2_0::SecType::ATTENTION;
    }
    if ((o & ::vendor::samsung::hardware::light::V2_0::SecType::BLUETOOTH) == static_cast<uint32_t>(::vendor::samsung::hardware::light::V2_0::SecType::BLUETOOTH)) {
        os += (first ? "" : " | ");
        os += "BLUETOOTH";
        first = false;
        flipped |= ::vendor::samsung::hardware::light::V2_0::SecType::BLUETOOTH;
    }
    if ((o & ::vendor::samsung::hardware::light::V2_0::SecType::WIFI) == static_cast<uint32_t>(::vendor::samsung::hardware::light::V2_0::SecType::WIFI)) {
        os += (first ? "" : " | ");
        os += "WIFI";
        first = false;
        flipped |= ::vendor::samsung::hardware::light::V2_0::SecType::WIFI;
    }
    if ((o & ::vendor::samsung::hardware::light::V2_0::SecType::SUBBACKLIGHT) == static_cast<uint32_t>(::vendor::samsung::hardware::light::V2_0::SecType::SUBBACKLIGHT)) {
        os += (first ? "" : " | ");
        os += "SUBBACKLIGHT";
        first = false;
        flipped |= ::vendor::samsung::hardware::light::V2_0::SecType::SUBBACKLIGHT;
    }
    if ((o & ::vendor::samsung::hardware::light::V2_0::SecType::LED_LTE) == static_cast<uint32_t>(::vendor::samsung::hardware::light::V2_0::SecType::LED_LTE)) {
        os += (first ? "" : " | ");
        os += "LED_LTE";
        first = false;
        flipped |= ::vendor::samsung::hardware::light::V2_0::SecType::LED_LTE;
    }
    if ((o & ::vendor::samsung::hardware::light::V2_0::SecType::LED_GIGALTE) == static_cast<uint32_t>(::vendor::samsung::hardware::light::V2_0::SecType::LED_GIGALTE)) {
        os += (first ? "" : " | ");
        os += "LED_GIGALTE";
        first = false;
        flipped |= ::vendor::samsung::hardware::light::V2_0::SecType::LED_GIGALTE;
    }
    if ((o & ::vendor::samsung::hardware::light::V2_0::SecType::LED_WIFI) == static_cast<uint32_t>(::vendor::samsung::hardware::light::V2_0::SecType::LED_WIFI)) {
        os += (first ? "" : " | ");
        os += "LED_WIFI";
        first = false;
        flipped |= ::vendor::samsung::hardware::light::V2_0::SecType::LED_WIFI;
    }
    if ((o & ::vendor::samsung::hardware::light::V2_0::SecType::LED_BATTERY) == static_cast<uint32_t>(::vendor::samsung::hardware::light::V2_0::SecType::LED_BATTERY)) {
        os += (first ? "" : " | ");
        os += "LED_BATTERY";
        first = false;
        flipped |= ::vendor::samsung::hardware::light::V2_0::SecType::LED_BATTERY;
    }
    if ((o & ::vendor::samsung::hardware::light::V2_0::SecType::LED_ALL) == static_cast<uint32_t>(::vendor::samsung::hardware::light::V2_0::SecType::LED_ALL)) {
        os += (first ? "" : " | ");
        os += "LED_ALL";
        first = false;
        flipped |= ::vendor::samsung::hardware::light::V2_0::SecType::LED_ALL;
    }
    if ((o & ::vendor::samsung::hardware::light::V2_0::SecType::COUNT) == static_cast<uint32_t>(::vendor::samsung::hardware::light::V2_0::SecType::COUNT)) {
        os += (first ? "" : " | ");
        os += "COUNT";
        first = false;
        flipped |= ::vendor::samsung::hardware::light::V2_0::SecType::COUNT;
    }
    if (o != flipped) {
        os += (first ? "" : " | ");
        os += toHexString(o & (~flipped));
    }os += " (";
    os += toHexString(o);
    os += ")";
    return os;
}

static inline std::string toString(::vendor::samsung::hardware::light::V2_0::SecType o) {
    using ::android::hardware::details::toHexString;
    if (o == ::vendor::samsung::hardware::light::V2_0::SecType::BACKLIGHT) {
        return "BACKLIGHT";
    }
    if (o == ::vendor::samsung::hardware::light::V2_0::SecType::KEYBOARD) {
        return "KEYBOARD";
    }
    if (o == ::vendor::samsung::hardware::light::V2_0::SecType::BUTTONS) {
        return "BUTTONS";
    }
    if (o == ::vendor::samsung::hardware::light::V2_0::SecType::BATTERY) {
        return "BATTERY";
    }
    if (o == ::vendor::samsung::hardware::light::V2_0::SecType::NOTIFICATIONS) {
        return "NOTIFICATIONS";
    }
    if (o == ::vendor::samsung::hardware::light::V2_0::SecType::ATTENTION) {
        return "ATTENTION";
    }
    if (o == ::vendor::samsung::hardware::light::V2_0::SecType::BLUETOOTH) {
        return "BLUETOOTH";
    }
    if (o == ::vendor::samsung::hardware::light::V2_0::SecType::WIFI) {
        return "WIFI";
    }
    if (o == ::vendor::samsung::hardware::light::V2_0::SecType::SUBBACKLIGHT) {
        return "SUBBACKLIGHT";
    }
    if (o == ::vendor::samsung::hardware::light::V2_0::SecType::LED_LTE) {
        return "LED_LTE";
    }
    if (o == ::vendor::samsung::hardware::light::V2_0::SecType::LED_GIGALTE) {
        return "LED_GIGALTE";
    }
    if (o == ::vendor::samsung::hardware::light::V2_0::SecType::LED_WIFI) {
        return "LED_WIFI";
    }
    if (o == ::vendor::samsung::hardware::light::V2_0::SecType::LED_BATTERY) {
        return "LED_BATTERY";
    }
    if (o == ::vendor::samsung::hardware::light::V2_0::SecType::LED_ALL) {
        return "LED_ALL";
    }
    if (o == ::vendor::samsung::hardware::light::V2_0::SecType::COUNT) {
        return "COUNT";
    }
    std::string os;
    os += toHexString(static_cast<uint32_t>(o));
    return os;
}

static inline void PrintTo(::vendor::samsung::hardware::light::V2_0::SecType o, ::std::ostream* os) {
    *os << toString(o);
}


}  // namespace V2_0
}  // namespace light
}  // namespace hardware
}  // namespace samsung
}  // namespace vendor

//
// global type declarations for package
//

namespace android {
namespace hardware {
namespace details {
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wc++17-extensions"
template<> inline constexpr std::array<::vendor::samsung::hardware::light::V2_0::SecType, 15> hidl_enum_values<::vendor::samsung::hardware::light::V2_0::SecType> = {
    ::vendor::samsung::hardware::light::V2_0::SecType::BACKLIGHT,
    ::vendor::samsung::hardware::light::V2_0::SecType::KEYBOARD,
    ::vendor::samsung::hardware::light::V2_0::SecType::BUTTONS,
    ::vendor::samsung::hardware::light::V2_0::SecType::BATTERY,
    ::vendor::samsung::hardware::light::V2_0::SecType::NOTIFICATIONS,
    ::vendor::samsung::hardware::light::V2_0::SecType::ATTENTION,
    ::vendor::samsung::hardware::light::V2_0::SecType::BLUETOOTH,
    ::vendor::samsung::hardware::light::V2_0::SecType::WIFI,
    ::vendor::samsung::hardware::light::V2_0::SecType::SUBBACKLIGHT,
    ::vendor::samsung::hardware::light::V2_0::SecType::LED_LTE,
    ::vendor::samsung::hardware::light::V2_0::SecType::LED_GIGALTE,
    ::vendor::samsung::hardware::light::V2_0::SecType::LED_WIFI,
    ::vendor::samsung::hardware::light::V2_0::SecType::LED_BATTERY,
    ::vendor::samsung::hardware::light::V2_0::SecType::LED_ALL,
    ::vendor::samsung::hardware::light::V2_0::SecType::COUNT,
};
#pragma clang diagnostic pop
}  // namespace details
}  // namespace hardware
}  // namespace android


#endif  // HIDL_GENERATED_VENDOR_SAMSUNG_HARDWARE_LIGHT_V2_0_TYPES_H
