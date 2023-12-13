#define LOG_TAG "android.hardware.camera.provider@2.7::types"

#include <log/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <hidl/Static.h>
#include <hwbinder/ProcessState.h>
#include <utils/Trace.h>
#include <android/hardware/camera/provider/2.7/types.h>
#include <android/hardware/camera/provider/2.7/hwtypes.h>

namespace android {
namespace hardware {
namespace camera {
namespace provider {
namespace V2_7 {

::android::status_t readEmbeddedFromParcel(
        const CameraIdAndStreamCombination &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.cameraId),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::camera::provider::V2_7::CameraIdAndStreamCombination, cameraId));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::camera::device::V3_7::StreamConfiguration &>(obj.streamConfiguration),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::camera::provider::V2_7::CameraIdAndStreamCombination, streamConfiguration));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const CameraIdAndStreamCombination &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.cameraId,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::camera::provider::V2_7::CameraIdAndStreamCombination, cameraId));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = writeEmbeddedToParcel(
            obj.streamConfiguration,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::camera::provider::V2_7::CameraIdAndStreamCombination, streamConfiguration));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

static_assert(sizeof(::android::hardware::MQDescriptor<char, ::android::hardware::kSynchronizedReadWrite>) == 32, "wrong size");
static_assert(sizeof(::android::hardware::hidl_handle) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_memory) == 40, "wrong size");
static_assert(sizeof(::android::hardware::hidl_string) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_vec<char>) == 16, "wrong size");

}  // namespace V2_7
}  // namespace provider
}  // namespace camera
}  // namespace hardware
}  // namespace android
