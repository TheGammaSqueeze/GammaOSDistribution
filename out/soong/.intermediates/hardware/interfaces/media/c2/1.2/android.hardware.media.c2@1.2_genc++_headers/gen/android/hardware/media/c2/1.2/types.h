#ifndef HIDL_GENERATED_ANDROID_HARDWARE_MEDIA_C2_V1_2_TYPES_H
#define HIDL_GENERATED_ANDROID_HARDWARE_MEDIA_C2_V1_2_TYPES_H

#include <hidl/HidlSupport.h>
#include <hidl/MQDescriptor.h>
#include <utils/NativeHandle.h>
#include <utils/misc.h>

namespace android {
namespace hardware {
namespace media {
namespace c2 {
namespace V1_2 {

// Forward declaration for forward reference support:
struct SurfaceSyncObj;

/**
 * Surface(BufferQueue/IGBP) synchronization object regarding # of dequeued
 * output buffers. This keeps # of dequeued buffers from Surface less than
 * configured max # of dequeued buffers all the time.
 */
struct SurfaceSyncObj final {
    /**
     * ASharedMemory for synchronization data. Layout is below
     *
     * |lock(futex)                               4bytes|
     * |conditional_variable(futex)               4bytes|
     * |# of max dequeable buffer                 4bytes|
     * |# of dequeued buffer                      4bytes|
     * |Status of the surface                     4bytes|
     *      INIT        = 0, Configuring surface is not finished.
     *      ACTIVE      = 1, Surface is ready to allocate(dequeue).
     *      SWITCHING   = 2, Switching to the new surface. It is blocked
     *                       to allocate(dequeue) a buffer until switching
     *                       completes.
     */
    ::android::hardware::hidl_handle syncMemory __attribute__ ((aligned(8)));
    /**
     * BufferQueue id.
     */
    uint64_t bqId __attribute__ ((aligned(8)));
    /**
     * Generation id.
     */
    uint32_t generationId __attribute__ ((aligned(4)));
    /**
     * Consumer usage flags. See +ndk
     * libnativewindow#AHardwareBuffer_UsageFlags for possible values.
     */
    uint64_t consumerUsage __attribute__ ((aligned(8)));
};

static_assert(offsetof(::android::hardware::media::c2::V1_2::SurfaceSyncObj, syncMemory) == 0, "wrong offset");
static_assert(offsetof(::android::hardware::media::c2::V1_2::SurfaceSyncObj, bqId) == 16, "wrong offset");
static_assert(offsetof(::android::hardware::media::c2::V1_2::SurfaceSyncObj, generationId) == 24, "wrong offset");
static_assert(offsetof(::android::hardware::media::c2::V1_2::SurfaceSyncObj, consumerUsage) == 32, "wrong offset");
static_assert(sizeof(::android::hardware::media::c2::V1_2::SurfaceSyncObj) == 40, "wrong size");
static_assert(__alignof(::android::hardware::media::c2::V1_2::SurfaceSyncObj) == 8, "wrong alignment");

//
// type declarations for package
//

static inline std::string toString(const ::android::hardware::media::c2::V1_2::SurfaceSyncObj& o);
static inline void PrintTo(const ::android::hardware::media::c2::V1_2::SurfaceSyncObj& o, ::std::ostream*);
// operator== and operator!= are not generated for SurfaceSyncObj

//
// type header definitions for package
//

static inline std::string toString(const ::android::hardware::media::c2::V1_2::SurfaceSyncObj& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".syncMemory = ";
    os += ::android::hardware::toString(o.syncMemory);
    os += ", .bqId = ";
    os += ::android::hardware::toString(o.bqId);
    os += ", .generationId = ";
    os += ::android::hardware::toString(o.generationId);
    os += ", .consumerUsage = ";
    os += ::android::hardware::toString(o.consumerUsage);
    os += "}"; return os;
}

static inline void PrintTo(const ::android::hardware::media::c2::V1_2::SurfaceSyncObj& o, ::std::ostream* os) {
    *os << toString(o);
}

// operator== and operator!= are not generated for SurfaceSyncObj


}  // namespace V1_2
}  // namespace c2
}  // namespace media
}  // namespace hardware
}  // namespace android

//
// global type declarations for package
//


#endif  // HIDL_GENERATED_ANDROID_HARDWARE_MEDIA_C2_V1_2_TYPES_H
