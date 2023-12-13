#define LOG_TAG "android.hardware.media.c2@1.2::types"

#include <log/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <hidl/Static.h>
#include <hwbinder/ProcessState.h>
#include <utils/Trace.h>
#include <android/hardware/media/c2/1.2/types.h>
#include <android/hardware/media/c2/1.2/hwtypes.h>

namespace android {
namespace hardware {
namespace media {
namespace c2 {
namespace V1_2 {

::android::status_t readEmbeddedFromParcel(
        const SurfaceSyncObj &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_handle &>(obj.syncMemory),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::media::c2::V1_2::SurfaceSyncObj, syncMemory));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const SurfaceSyncObj &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.syncMemory,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::media::c2::V1_2::SurfaceSyncObj, syncMemory));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

static_assert(sizeof(::android::hardware::MQDescriptor<char, ::android::hardware::kSynchronizedReadWrite>) == 32, "wrong size");
static_assert(sizeof(::android::hardware::hidl_handle) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_memory) == 40, "wrong size");
static_assert(sizeof(::android::hardware::hidl_string) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_vec<char>) == 16, "wrong size");

}  // namespace V1_2
}  // namespace c2
}  // namespace media
}  // namespace hardware
}  // namespace android
