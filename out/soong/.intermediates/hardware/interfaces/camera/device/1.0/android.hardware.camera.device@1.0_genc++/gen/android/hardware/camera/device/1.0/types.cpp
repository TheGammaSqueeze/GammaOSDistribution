#define LOG_TAG "android.hardware.camera.device@1.0::types"

#include <log/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <hidl/Static.h>
#include <hwbinder/ProcessState.h>
#include <utils/Trace.h>
#include <android/hardware/camera/device/1.0/types.h>
#include <android/hardware/camera/device/1.0/hwtypes.h>

namespace android {
namespace hardware {
namespace camera {
namespace device {
namespace V1_0 {

::android::status_t readEmbeddedFromParcel(
        const CameraFrameMetadata &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_faces_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::camera::device::V1_0::CameraFace> &>(obj.faces),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::camera::device::V1_0::CameraFrameMetadata, faces), &_hidl_faces_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const CameraFrameMetadata &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_faces_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.faces,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::camera::device::V1_0::CameraFrameMetadata, faces), &_hidl_faces_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const HandleTimestampMessage &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_handle &>(obj.frameData),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::camera::device::V1_0::HandleTimestampMessage, frameData));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const HandleTimestampMessage &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.frameData,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::camera::device::V1_0::HandleTimestampMessage, frameData));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const VideoFrameMessage &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_handle &>(obj.frameData),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::camera::device::V1_0::VideoFrameMessage, frameData));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const VideoFrameMessage &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.frameData,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::camera::device::V1_0::VideoFrameMessage, frameData));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

static_assert(sizeof(::android::hardware::MQDescriptor<char, ::android::hardware::kSynchronizedReadWrite>) == 32, "wrong size");
static_assert(sizeof(::android::hardware::hidl_handle) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_memory) == 40, "wrong size");
static_assert(sizeof(::android::hardware::hidl_string) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_vec<char>) == 16, "wrong size");

}  // namespace V1_0
}  // namespace device
}  // namespace camera
}  // namespace hardware
}  // namespace android
