#define LOG_TAG "android.hardware.graphics.common@1.2::types"

#include <log/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <hidl/Static.h>
#include <hwbinder/ProcessState.h>
#include <utils/Trace.h>
#include <android/hardware/graphics/common/1.2/types.h>
#include <android/hardware/graphics/common/1.2/hwtypes.h>

namespace android {
namespace hardware {
namespace graphics {
namespace common {
namespace V1_2 {

::android::status_t readEmbeddedFromParcel(
        const HardwareBuffer &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_handle &>(obj.nativeHandle),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::graphics::common::V1_2::HardwareBuffer, nativeHandle));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const HardwareBuffer &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.nativeHandle,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::graphics::common::V1_2::HardwareBuffer, nativeHandle));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

static_assert(sizeof(::android::hardware::MQDescriptor<char, ::android::hardware::kSynchronizedReadWrite>) == 32, "wrong size");
static_assert(sizeof(::android::hardware::hidl_handle) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_memory) == 40, "wrong size");
static_assert(sizeof(::android::hardware::hidl_string) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_vec<char>) == 16, "wrong size");

}  // namespace V1_2
}  // namespace common
}  // namespace graphics
}  // namespace hardware
}  // namespace android
