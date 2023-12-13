#define LOG_TAG "android.hardware.graphics.mapper@3.0::types"

#include <log/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <hidl/Static.h>
#include <hwbinder/ProcessState.h>
#include <utils/Trace.h>
#include <android/hardware/graphics/mapper/3.0/types.h>
#include <android/hardware/graphics/mapper/3.0/hwtypes.h>

namespace android {
namespace hardware {
namespace graphics {
namespace mapper {
namespace V3_0 {

::android::status_t readEmbeddedFromParcel(
        const YCbCrLayout &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    (void) parcel;
    (void) parentHandle;
    (void) (parentOffset + offsetof(::android::hardware::graphics::mapper::V3_0::YCbCrLayout, y));
    (void)obj.y;
    LOG_ALWAYS_FATAL("Pointer is only supported in passthrough mode");

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    (void) parcel;
    (void) parentHandle;
    (void) (parentOffset + offsetof(::android::hardware::graphics::mapper::V3_0::YCbCrLayout, cb));
    (void)obj.cb;
    LOG_ALWAYS_FATAL("Pointer is only supported in passthrough mode");

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    (void) parcel;
    (void) parentHandle;
    (void) (parentOffset + offsetof(::android::hardware::graphics::mapper::V3_0::YCbCrLayout, cr));
    (void)obj.cr;
    LOG_ALWAYS_FATAL("Pointer is only supported in passthrough mode");

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const YCbCrLayout &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    (void) parcel;
    (void) parentHandle;
    (void) (parentOffset + offsetof(::android::hardware::graphics::mapper::V3_0::YCbCrLayout, y));
    (void)obj.y;
    LOG_ALWAYS_FATAL("Pointer is only supported in passthrough mode");

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    (void) parcel;
    (void) parentHandle;
    (void) (parentOffset + offsetof(::android::hardware::graphics::mapper::V3_0::YCbCrLayout, cb));
    (void)obj.cb;
    LOG_ALWAYS_FATAL("Pointer is only supported in passthrough mode");

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    (void) parcel;
    (void) parentHandle;
    (void) (parentOffset + offsetof(::android::hardware::graphics::mapper::V3_0::YCbCrLayout, cr));
    (void)obj.cr;
    LOG_ALWAYS_FATAL("Pointer is only supported in passthrough mode");

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

static_assert(sizeof(::android::hardware::MQDescriptor<char, ::android::hardware::kSynchronizedReadWrite>) == 32, "wrong size");
static_assert(sizeof(::android::hardware::hidl_handle) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_memory) == 40, "wrong size");
static_assert(sizeof(::android::hardware::hidl_string) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_vec<char>) == 16, "wrong size");

}  // namespace V3_0
}  // namespace mapper
}  // namespace graphics
}  // namespace hardware
}  // namespace android
