#ifndef HIDL_GENERATED_VENDOR_SAMSUNG_HARDWARE_LIGHT_V3_0_TYPES_H
#define HIDL_GENERATED_VENDOR_SAMSUNG_HARDWARE_LIGHT_V3_0_TYPES_H

#include <android/hardware/light/2.0/types.h>

#include <hidl/HidlSupport.h>
#include <hidl/MQDescriptor.h>
#include <utils/NativeHandle.h>
#include <utils/misc.h>

namespace vendor {
namespace samsung {
namespace hardware {
namespace light {
namespace V3_0 {

// Forward declaration for forward reference support:
enum class SehType : uint32_t;
struct SehLightState;

enum class SehType : uint32_t {
    BACKLIGHT = 0u,
    KEYBOARD = 1u,
    BUTTONS = 2u,
    BATTERY = 3u,
    NOTIFICATIONS = 4u,
    ATTENTION = 5u,
    BLUETOOTH = 6u,
    WIFI = 7u,
    SUB_BACKLIGHT = 8u,
};

struct SehLightState final {
    /**
     * The color of the LED in ARGB.
     *
     * Do your best here.
     *   - If your light can only do red or green, if they ask for blue,
     *     you should do green.
     *   - If you can only do a brightness ramp, then use this formula:
     *      unsigned char brightness = ((77*((color>>16)&0x00ff))
     *              + (150*((color>>8)&0x00ff)) + (29*(color&0x00ff))) >> 8;
     *   - If you can only do on or off, 0 is off, anything else is on.
     *
     * The high byte should be ignored. Callers will set it to 0xff (which
     * would correspond to 255 alpha).
     */
    uint32_t color __attribute__ ((aligned(4)));
    /**
     * To flash the light at a given rate, set flashMode to LIGHT_FLASH_TIMED,
     * and then flashOnMS should be set to the number of milliseconds to turn
     * the light on, followed by the number of milliseconds to turn the light
     * off.
     */
    ::android::hardware::light::V2_0::Flash flashMode __attribute__ ((aligned(4)));
    int32_t flashOnMs __attribute__ ((aligned(4)));
    int32_t flashOffMs __attribute__ ((aligned(4)));
    ::android::hardware::light::V2_0::Brightness brightnessMode __attribute__ ((aligned(4)));
    int32_t extendedBrightness __attribute__ ((aligned(4)));
};

static_assert(offsetof(::vendor::samsung::hardware::light::V3_0::SehLightState, color) == 0, "wrong offset");
static_assert(offsetof(::vendor::samsung::hardware::light::V3_0::SehLightState, flashMode) == 4, "wrong offset");
static_assert(offsetof(::vendor::samsung::hardware::light::V3_0::SehLightState, flashOnMs) == 8, "wrong offset");
static_assert(offsetof(::vendor::samsung::hardware::light::V3_0::SehLightState, flashOffMs) == 12, "wrong offset");
static_assert(offsetof(::vendor::samsung::hardware::light::V3_0::SehLightState, brightnessMode) == 16, "wrong offset");
static_assert(offsetof(::vendor::samsung::hardware::light::V3_0::SehLightState, extendedBrightness) == 20, "wrong offset");
static_assert(sizeof(::vendor::samsung::hardware::light::V3_0::SehLightState) == 24, "wrong size");
static_assert(__alignof(::vendor::samsung::hardware::light::V3_0::SehLightState) == 4, "wrong alignment");

//
// type declarations for package
//

template<typename>
static inline std::string toString(uint32_t o);
static inline std::string toString(::vendor::samsung::hardware::light::V3_0::SehType o);
static inline void PrintTo(::vendor::samsung::hardware::light::V3_0::SehType o, ::std::ostream* os);
constexpr uint32_t operator|(const ::vendor::samsung::hardware::light::V3_0::SehType lhs, const ::vendor::samsung::hardware::light::V3_0::SehType rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) | static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator|(const uint32_t lhs, const ::vendor::samsung::hardware::light::V3_0::SehType rhs) {
    return static_cast<uint32_t>(lhs | static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator|(const ::vendor::samsung::hardware::light::V3_0::SehType lhs, const uint32_t rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) | rhs);
}
constexpr uint32_t operator&(const ::vendor::samsung::hardware::light::V3_0::SehType lhs, const ::vendor::samsung::hardware::light::V3_0::SehType rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) & static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator&(const uint32_t lhs, const ::vendor::samsung::hardware::light::V3_0::SehType rhs) {
    return static_cast<uint32_t>(lhs & static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator&(const ::vendor::samsung::hardware::light::V3_0::SehType lhs, const uint32_t rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) & rhs);
}
constexpr uint32_t &operator|=(uint32_t& v, const ::vendor::samsung::hardware::light::V3_0::SehType e) {
    v |= static_cast<uint32_t>(e);
    return v;
}
constexpr uint32_t &operator&=(uint32_t& v, const ::vendor::samsung::hardware::light::V3_0::SehType e) {
    v &= static_cast<uint32_t>(e);
    return v;
}

static inline std::string toString(const ::vendor::samsung::hardware::light::V3_0::SehLightState& o);
static inline void PrintTo(const ::vendor::samsung::hardware::light::V3_0::SehLightState& o, ::std::ostream*);
static inline bool operator==(const ::vendor::samsung::hardware::light::V3_0::SehLightState& lhs, const ::vendor::samsung::hardware::light::V3_0::SehLightState& rhs);
static inline bool operator!=(const ::vendor::samsung::hardware::light::V3_0::SehLightState& lhs, const ::vendor::samsung::hardware::light::V3_0::SehLightState& rhs);

//
// type header definitions for package
//

template<>
inline std::string toString<::vendor::samsung::hardware::light::V3_0::SehType>(uint32_t o) {
    using ::android::hardware::details::toHexString;
    std::string os;
    ::android::hardware::hidl_bitfield<::vendor::samsung::hardware::light::V3_0::SehType> flipped = 0;
    bool first = true;
    if ((o & ::vendor::samsung::hardware::light::V3_0::SehType::BACKLIGHT) == static_cast<uint32_t>(::vendor::samsung::hardware::light::V3_0::SehType::BACKLIGHT)) {
        os += (first ? "" : " | ");
        os += "BACKLIGHT";
        first = false;
        flipped |= ::vendor::samsung::hardware::light::V3_0::SehType::BACKLIGHT;
    }
    if ((o & ::vendor::samsung::hardware::light::V3_0::SehType::KEYBOARD) == static_cast<uint32_t>(::vendor::samsung::hardware::light::V3_0::SehType::KEYBOARD)) {
        os += (first ? "" : " | ");
        os += "KEYBOARD";
        first = false;
        flipped |= ::vendor::samsung::hardware::light::V3_0::SehType::KEYBOARD;
    }
    if ((o & ::vendor::samsung::hardware::light::V3_0::SehType::BUTTONS) == static_cast<uint32_t>(::vendor::samsung::hardware::light::V3_0::SehType::BUTTONS)) {
        os += (first ? "" : " | ");
        os += "BUTTONS";
        first = false;
        flipped |= ::vendor::samsung::hardware::light::V3_0::SehType::BUTTONS;
    }
    if ((o & ::vendor::samsung::hardware::light::V3_0::SehType::BATTERY) == static_cast<uint32_t>(::vendor::samsung::hardware::light::V3_0::SehType::BATTERY)) {
        os += (first ? "" : " | ");
        os += "BATTERY";
        first = false;
        flipped |= ::vendor::samsung::hardware::light::V3_0::SehType::BATTERY;
    }
    if ((o & ::vendor::samsung::hardware::light::V3_0::SehType::NOTIFICATIONS) == static_cast<uint32_t>(::vendor::samsung::hardware::light::V3_0::SehType::NOTIFICATIONS)) {
        os += (first ? "" : " | ");
        os += "NOTIFICATIONS";
        first = false;
        flipped |= ::vendor::samsung::hardware::light::V3_0::SehType::NOTIFICATIONS;
    }
    if ((o & ::vendor::samsung::hardware::light::V3_0::SehType::ATTENTION) == static_cast<uint32_t>(::vendor::samsung::hardware::light::V3_0::SehType::ATTENTION)) {
        os += (first ? "" : " | ");
        os += "ATTENTION";
        first = false;
        flipped |= ::vendor::samsung::hardware::light::V3_0::SehType::ATTENTION;
    }
    if ((o & ::vendor::samsung::hardware::light::V3_0::SehType::BLUETOOTH) == static_cast<uint32_t>(::vendor::samsung::hardware::light::V3_0::SehType::BLUETOOTH)) {
        os += (first ? "" : " | ");
        os += "BLUETOOTH";
        first = false;
        flipped |= ::vendor::samsung::hardware::light::V3_0::SehType::BLUETOOTH;
    }
    if ((o & ::vendor::samsung::hardware::light::V3_0::SehType::WIFI) == static_cast<uint32_t>(::vendor::samsung::hardware::light::V3_0::SehType::WIFI)) {
        os += (first ? "" : " | ");
        os += "WIFI";
        first = false;
        flipped |= ::vendor::samsung::hardware::light::V3_0::SehType::WIFI;
    }
    if ((o & ::vendor::samsung::hardware::light::V3_0::SehType::SUB_BACKLIGHT) == static_cast<uint32_t>(::vendor::samsung::hardware::light::V3_0::SehType::SUB_BACKLIGHT)) {
        os += (first ? "" : " | ");
        os += "SUB_BACKLIGHT";
        first = false;
        flipped |= ::vendor::samsung::hardware::light::V3_0::SehType::SUB_BACKLIGHT;
    }
    if (o != flipped) {
        os += (first ? "" : " | ");
        os += toHexString(o & (~flipped));
    }os += " (";
    os += toHexString(o);
    os += ")";
    return os;
}

static inline std::string toString(::vendor::samsung::hardware::light::V3_0::SehType o) {
    using ::android::hardware::details::toHexString;
    if (o == ::vendor::samsung::hardware::light::V3_0::SehType::BACKLIGHT) {
        return "BACKLIGHT";
    }
    if (o == ::vendor::samsung::hardware::light::V3_0::SehType::KEYBOARD) {
        return "KEYBOARD";
    }
    if (o == ::vendor::samsung::hardware::light::V3_0::SehType::BUTTONS) {
        return "BUTTONS";
    }
    if (o == ::vendor::samsung::hardware::light::V3_0::SehType::BATTERY) {
        return "BATTERY";
    }
    if (o == ::vendor::samsung::hardware::light::V3_0::SehType::NOTIFICATIONS) {
        return "NOTIFICATIONS";
    }
    if (o == ::vendor::samsung::hardware::light::V3_0::SehType::ATTENTION) {
        return "ATTENTION";
    }
    if (o == ::vendor::samsung::hardware::light::V3_0::SehType::BLUETOOTH) {
        return "BLUETOOTH";
    }
    if (o == ::vendor::samsung::hardware::light::V3_0::SehType::WIFI) {
        return "WIFI";
    }
    if (o == ::vendor::samsung::hardware::light::V3_0::SehType::SUB_BACKLIGHT) {
        return "SUB_BACKLIGHT";
    }
    std::string os;
    os += toHexString(static_cast<uint32_t>(o));
    return os;
}

static inline void PrintTo(::vendor::samsung::hardware::light::V3_0::SehType o, ::std::ostream* os) {
    *os << toString(o);
}

static inline std::string toString(const ::vendor::samsung::hardware::light::V3_0::SehLightState& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".color = ";
    os += ::android::hardware::toString(o.color);
    os += ", .flashMode = ";
    os += ::android::hardware::light::V2_0::toString(o.flashMode);
    os += ", .flashOnMs = ";
    os += ::android::hardware::toString(o.flashOnMs);
    os += ", .flashOffMs = ";
    os += ::android::hardware::toString(o.flashOffMs);
    os += ", .brightnessMode = ";
    os += ::android::hardware::light::V2_0::toString(o.brightnessMode);
    os += ", .extendedBrightness = ";
    os += ::android::hardware::toString(o.extendedBrightness);
    os += "}"; return os;
}

static inline void PrintTo(const ::vendor::samsung::hardware::light::V3_0::SehLightState& o, ::std::ostream* os) {
    *os << toString(o);
}

static inline bool operator==(const ::vendor::samsung::hardware::light::V3_0::SehLightState& lhs, const ::vendor::samsung::hardware::light::V3_0::SehLightState& rhs) {
    if (lhs.color != rhs.color) {
        return false;
    }
    if (lhs.flashMode != rhs.flashMode) {
        return false;
    }
    if (lhs.flashOnMs != rhs.flashOnMs) {
        return false;
    }
    if (lhs.flashOffMs != rhs.flashOffMs) {
        return false;
    }
    if (lhs.brightnessMode != rhs.brightnessMode) {
        return false;
    }
    if (lhs.extendedBrightness != rhs.extendedBrightness) {
        return false;
    }
    return true;
}

static inline bool operator!=(const ::vendor::samsung::hardware::light::V3_0::SehLightState& lhs, const ::vendor::samsung::hardware::light::V3_0::SehLightState& rhs){
    return !(lhs == rhs);
}


}  // namespace V3_0
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
template<> inline constexpr std::array<::vendor::samsung::hardware::light::V3_0::SehType, 9> hidl_enum_values<::vendor::samsung::hardware::light::V3_0::SehType> = {
    ::vendor::samsung::hardware::light::V3_0::SehType::BACKLIGHT,
    ::vendor::samsung::hardware::light::V3_0::SehType::KEYBOARD,
    ::vendor::samsung::hardware::light::V3_0::SehType::BUTTONS,
    ::vendor::samsung::hardware::light::V3_0::SehType::BATTERY,
    ::vendor::samsung::hardware::light::V3_0::SehType::NOTIFICATIONS,
    ::vendor::samsung::hardware::light::V3_0::SehType::ATTENTION,
    ::vendor::samsung::hardware::light::V3_0::SehType::BLUETOOTH,
    ::vendor::samsung::hardware::light::V3_0::SehType::WIFI,
    ::vendor::samsung::hardware::light::V3_0::SehType::SUB_BACKLIGHT,
};
#pragma clang diagnostic pop
}  // namespace details
}  // namespace hardware
}  // namespace android


#endif  // HIDL_GENERATED_VENDOR_SAMSUNG_HARDWARE_LIGHT_V3_0_TYPES_H
