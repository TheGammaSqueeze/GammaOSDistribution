#ifndef HIDL_GENERATED_ANDROID_FRAMEWORKS_BUFFERHUB_V1_0_TYPES_H
#define HIDL_GENERATED_ANDROID_FRAMEWORKS_BUFFERHUB_V1_0_TYPES_H

#include <android/hardware/graphics/common/1.2/types.h>

#include <hidl/HidlSupport.h>
#include <hidl/MQDescriptor.h>
#include <utils/NativeHandle.h>
#include <utils/misc.h>

namespace android {
namespace frameworks {
namespace bufferhub {
namespace V1_0 {

// Forward declaration for forward reference support:
enum class BufferHubStatus : uint32_t;
struct BufferTraits;

enum class BufferHubStatus : uint32_t {
    NO_ERROR = 0u,
    ALLOCATION_FAILED = 1u /* ::android::frameworks::bufferhub::V1_0::BufferHubStatus.NO_ERROR implicitly + 1 */,
    INVALID_TOKEN = 2u /* ::android::frameworks::bufferhub::V1_0::BufferHubStatus.ALLOCATION_FAILED implicitly + 1 */,
    BUFFER_FREED = 3u /* ::android::frameworks::bufferhub::V1_0::BufferHubStatus.INVALID_TOKEN implicitly + 1 */,
    CLIENT_CLOSED = 4u /* ::android::frameworks::bufferhub::V1_0::BufferHubStatus.BUFFER_FREED implicitly + 1 */,
    MAX_CLIENT = 5u /* ::android::frameworks::bufferhub::V1_0::BufferHubStatus.CLIENT_CLOSED implicitly + 1 */,
};

/**
 * A struct containing necessary information to create a buffer object.
 */
struct BufferTraits final {
    /**
     * Static descriptors (such as height, width, format) of the buffer.
     */
    ::android::hardware::hidl_array<uint32_t, 10> bufferDesc __attribute__ ((aligned(4)));
    /**
     * Handle comes from android.hardware.graphics.allocator@2.0. Represents
     * the underlying physical buffer object.
     */
    ::android::hardware::hidl_handle bufferHandle __attribute__ ((aligned(8)));
    /**
     * Client-defined handle containing other useful params and fds. The data
     * in the handle may be exposed by ll-ndk clients but in a format that is
     * described by the client. This actual structure will not be exposed.
     */
    ::android::hardware::hidl_handle bufferInfo __attribute__ ((aligned(8)));
};

static_assert(offsetof(::android::frameworks::bufferhub::V1_0::BufferTraits, bufferDesc) == 0, "wrong offset");
static_assert(offsetof(::android::frameworks::bufferhub::V1_0::BufferTraits, bufferHandle) == 40, "wrong offset");
static_assert(offsetof(::android::frameworks::bufferhub::V1_0::BufferTraits, bufferInfo) == 56, "wrong offset");
static_assert(sizeof(::android::frameworks::bufferhub::V1_0::BufferTraits) == 72, "wrong size");
static_assert(__alignof(::android::frameworks::bufferhub::V1_0::BufferTraits) == 8, "wrong alignment");

//
// type declarations for package
//

template<typename>
static inline std::string toString(uint32_t o);
static inline std::string toString(::android::frameworks::bufferhub::V1_0::BufferHubStatus o);
static inline void PrintTo(::android::frameworks::bufferhub::V1_0::BufferHubStatus o, ::std::ostream* os);
constexpr uint32_t operator|(const ::android::frameworks::bufferhub::V1_0::BufferHubStatus lhs, const ::android::frameworks::bufferhub::V1_0::BufferHubStatus rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) | static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator|(const uint32_t lhs, const ::android::frameworks::bufferhub::V1_0::BufferHubStatus rhs) {
    return static_cast<uint32_t>(lhs | static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator|(const ::android::frameworks::bufferhub::V1_0::BufferHubStatus lhs, const uint32_t rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) | rhs);
}
constexpr uint32_t operator&(const ::android::frameworks::bufferhub::V1_0::BufferHubStatus lhs, const ::android::frameworks::bufferhub::V1_0::BufferHubStatus rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) & static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator&(const uint32_t lhs, const ::android::frameworks::bufferhub::V1_0::BufferHubStatus rhs) {
    return static_cast<uint32_t>(lhs & static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator&(const ::android::frameworks::bufferhub::V1_0::BufferHubStatus lhs, const uint32_t rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) & rhs);
}
constexpr uint32_t &operator|=(uint32_t& v, const ::android::frameworks::bufferhub::V1_0::BufferHubStatus e) {
    v |= static_cast<uint32_t>(e);
    return v;
}
constexpr uint32_t &operator&=(uint32_t& v, const ::android::frameworks::bufferhub::V1_0::BufferHubStatus e) {
    v &= static_cast<uint32_t>(e);
    return v;
}

static inline std::string toString(const ::android::frameworks::bufferhub::V1_0::BufferTraits& o);
static inline void PrintTo(const ::android::frameworks::bufferhub::V1_0::BufferTraits& o, ::std::ostream*);
// operator== and operator!= are not generated for BufferTraits

//
// type header definitions for package
//

template<>
inline std::string toString<::android::frameworks::bufferhub::V1_0::BufferHubStatus>(uint32_t o) {
    using ::android::hardware::details::toHexString;
    std::string os;
    ::android::hardware::hidl_bitfield<::android::frameworks::bufferhub::V1_0::BufferHubStatus> flipped = 0;
    bool first = true;
    if ((o & ::android::frameworks::bufferhub::V1_0::BufferHubStatus::NO_ERROR) == static_cast<uint32_t>(::android::frameworks::bufferhub::V1_0::BufferHubStatus::NO_ERROR)) {
        os += (first ? "" : " | ");
        os += "NO_ERROR";
        first = false;
        flipped |= ::android::frameworks::bufferhub::V1_0::BufferHubStatus::NO_ERROR;
    }
    if ((o & ::android::frameworks::bufferhub::V1_0::BufferHubStatus::ALLOCATION_FAILED) == static_cast<uint32_t>(::android::frameworks::bufferhub::V1_0::BufferHubStatus::ALLOCATION_FAILED)) {
        os += (first ? "" : " | ");
        os += "ALLOCATION_FAILED";
        first = false;
        flipped |= ::android::frameworks::bufferhub::V1_0::BufferHubStatus::ALLOCATION_FAILED;
    }
    if ((o & ::android::frameworks::bufferhub::V1_0::BufferHubStatus::INVALID_TOKEN) == static_cast<uint32_t>(::android::frameworks::bufferhub::V1_0::BufferHubStatus::INVALID_TOKEN)) {
        os += (first ? "" : " | ");
        os += "INVALID_TOKEN";
        first = false;
        flipped |= ::android::frameworks::bufferhub::V1_0::BufferHubStatus::INVALID_TOKEN;
    }
    if ((o & ::android::frameworks::bufferhub::V1_0::BufferHubStatus::BUFFER_FREED) == static_cast<uint32_t>(::android::frameworks::bufferhub::V1_0::BufferHubStatus::BUFFER_FREED)) {
        os += (first ? "" : " | ");
        os += "BUFFER_FREED";
        first = false;
        flipped |= ::android::frameworks::bufferhub::V1_0::BufferHubStatus::BUFFER_FREED;
    }
    if ((o & ::android::frameworks::bufferhub::V1_0::BufferHubStatus::CLIENT_CLOSED) == static_cast<uint32_t>(::android::frameworks::bufferhub::V1_0::BufferHubStatus::CLIENT_CLOSED)) {
        os += (first ? "" : " | ");
        os += "CLIENT_CLOSED";
        first = false;
        flipped |= ::android::frameworks::bufferhub::V1_0::BufferHubStatus::CLIENT_CLOSED;
    }
    if ((o & ::android::frameworks::bufferhub::V1_0::BufferHubStatus::MAX_CLIENT) == static_cast<uint32_t>(::android::frameworks::bufferhub::V1_0::BufferHubStatus::MAX_CLIENT)) {
        os += (first ? "" : " | ");
        os += "MAX_CLIENT";
        first = false;
        flipped |= ::android::frameworks::bufferhub::V1_0::BufferHubStatus::MAX_CLIENT;
    }
    if (o != flipped) {
        os += (first ? "" : " | ");
        os += toHexString(o & (~flipped));
    }os += " (";
    os += toHexString(o);
    os += ")";
    return os;
}

static inline std::string toString(::android::frameworks::bufferhub::V1_0::BufferHubStatus o) {
    using ::android::hardware::details::toHexString;
    if (o == ::android::frameworks::bufferhub::V1_0::BufferHubStatus::NO_ERROR) {
        return "NO_ERROR";
    }
    if (o == ::android::frameworks::bufferhub::V1_0::BufferHubStatus::ALLOCATION_FAILED) {
        return "ALLOCATION_FAILED";
    }
    if (o == ::android::frameworks::bufferhub::V1_0::BufferHubStatus::INVALID_TOKEN) {
        return "INVALID_TOKEN";
    }
    if (o == ::android::frameworks::bufferhub::V1_0::BufferHubStatus::BUFFER_FREED) {
        return "BUFFER_FREED";
    }
    if (o == ::android::frameworks::bufferhub::V1_0::BufferHubStatus::CLIENT_CLOSED) {
        return "CLIENT_CLOSED";
    }
    if (o == ::android::frameworks::bufferhub::V1_0::BufferHubStatus::MAX_CLIENT) {
        return "MAX_CLIENT";
    }
    std::string os;
    os += toHexString(static_cast<uint32_t>(o));
    return os;
}

static inline void PrintTo(::android::frameworks::bufferhub::V1_0::BufferHubStatus o, ::std::ostream* os) {
    *os << toString(o);
}

static inline std::string toString(const ::android::frameworks::bufferhub::V1_0::BufferTraits& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".bufferDesc = ";
    os += ::android::hardware::toString(o.bufferDesc);
    os += ", .bufferHandle = ";
    os += ::android::hardware::toString(o.bufferHandle);
    os += ", .bufferInfo = ";
    os += ::android::hardware::toString(o.bufferInfo);
    os += "}"; return os;
}

static inline void PrintTo(const ::android::frameworks::bufferhub::V1_0::BufferTraits& o, ::std::ostream* os) {
    *os << toString(o);
}

// operator== and operator!= are not generated for BufferTraits


}  // namespace V1_0
}  // namespace bufferhub
}  // namespace frameworks
}  // namespace android

//
// global type declarations for package
//

namespace android {
namespace hardware {
namespace details {
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wc++17-extensions"
template<> inline constexpr std::array<::android::frameworks::bufferhub::V1_0::BufferHubStatus, 6> hidl_enum_values<::android::frameworks::bufferhub::V1_0::BufferHubStatus> = {
    ::android::frameworks::bufferhub::V1_0::BufferHubStatus::NO_ERROR,
    ::android::frameworks::bufferhub::V1_0::BufferHubStatus::ALLOCATION_FAILED,
    ::android::frameworks::bufferhub::V1_0::BufferHubStatus::INVALID_TOKEN,
    ::android::frameworks::bufferhub::V1_0::BufferHubStatus::BUFFER_FREED,
    ::android::frameworks::bufferhub::V1_0::BufferHubStatus::CLIENT_CLOSED,
    ::android::frameworks::bufferhub::V1_0::BufferHubStatus::MAX_CLIENT,
};
#pragma clang diagnostic pop
}  // namespace details
}  // namespace hardware
}  // namespace android


#endif  // HIDL_GENERATED_ANDROID_FRAMEWORKS_BUFFERHUB_V1_0_TYPES_H
