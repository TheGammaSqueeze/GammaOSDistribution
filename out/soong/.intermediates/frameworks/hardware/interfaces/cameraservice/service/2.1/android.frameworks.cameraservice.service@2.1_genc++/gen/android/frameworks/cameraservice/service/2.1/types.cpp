#define LOG_TAG "android.frameworks.cameraservice.service@2.1::types"

#include <log/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <hidl/Static.h>
#include <hwbinder/ProcessState.h>
#include <utils/Trace.h>
#include <android/frameworks/cameraservice/service/2.1/types.h>
#include <android/frameworks/cameraservice/service/2.1/hwtypes.h>

namespace android {
namespace frameworks {
namespace cameraservice {
namespace service {
namespace V2_1 {

::android::status_t readEmbeddedFromParcel(
        const CameraStatusAndId &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::frameworks::cameraservice::service::V2_0::CameraStatusAndId &>(obj.v2_0),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::frameworks::cameraservice::service::V2_1::CameraStatusAndId, v2_0));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_unavailPhysicalCameraIds_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::hidl_string> &>(obj.unavailPhysicalCameraIds),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::frameworks::cameraservice::service::V2_1::CameraStatusAndId, unavailPhysicalCameraIds), &_hidl_unavailPhysicalCameraIds_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.unavailPhysicalCameraIds.size(); ++_hidl_index_0) {
        _hidl_err = ::android::hardware::readEmbeddedFromParcel(
                const_cast<::android::hardware::hidl_string &>(obj.unavailPhysicalCameraIds[_hidl_index_0]),
                parcel,
                _hidl_unavailPhysicalCameraIds_child,
                _hidl_index_0 * sizeof(::android::hardware::hidl_string));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const CameraStatusAndId &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = writeEmbeddedToParcel(
            obj.v2_0,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::frameworks::cameraservice::service::V2_1::CameraStatusAndId, v2_0));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_unavailPhysicalCameraIds_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.unavailPhysicalCameraIds,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::frameworks::cameraservice::service::V2_1::CameraStatusAndId, unavailPhysicalCameraIds), &_hidl_unavailPhysicalCameraIds_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.unavailPhysicalCameraIds.size(); ++_hidl_index_0) {
        _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                obj.unavailPhysicalCameraIds[_hidl_index_0],
                parcel,
                _hidl_unavailPhysicalCameraIds_child,
                _hidl_index_0 * sizeof(::android::hardware::hidl_string));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const PhysicalCameraStatusAndId &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.cameraId),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::frameworks::cameraservice::service::V2_1::PhysicalCameraStatusAndId, cameraId));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.physicalCameraId),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::frameworks::cameraservice::service::V2_1::PhysicalCameraStatusAndId, physicalCameraId));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const PhysicalCameraStatusAndId &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.cameraId,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::frameworks::cameraservice::service::V2_1::PhysicalCameraStatusAndId, cameraId));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.physicalCameraId,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::frameworks::cameraservice::service::V2_1::PhysicalCameraStatusAndId, physicalCameraId));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

static_assert(sizeof(::android::hardware::MQDescriptor<char, ::android::hardware::kSynchronizedReadWrite>) == 32, "wrong size");
static_assert(sizeof(::android::hardware::hidl_handle) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_memory) == 40, "wrong size");
static_assert(sizeof(::android::hardware::hidl_string) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_vec<char>) == 16, "wrong size");

}  // namespace V2_1
}  // namespace service
}  // namespace cameraservice
}  // namespace frameworks
}  // namespace android
