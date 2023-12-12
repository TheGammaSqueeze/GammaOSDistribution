#define LOG_TAG "android.hardware.camera.device@3.4::types"

#include <log/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <hidl/Static.h>
#include <hwbinder/ProcessState.h>
#include <utils/Trace.h>
#include <android/hardware/camera/device/3.4/types.h>
#include <android/hardware/camera/device/3.4/hwtypes.h>

namespace android {
namespace hardware {
namespace camera {
namespace device {
namespace V3_4 {

::android::status_t readEmbeddedFromParcel(
        const Stream &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.physicalCameraId),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::camera::device::V3_4::Stream, physicalCameraId));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const Stream &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.physicalCameraId,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::camera::device::V3_4::Stream, physicalCameraId));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const StreamConfiguration &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_streams_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::camera::device::V3_4::Stream> &>(obj.streams),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::camera::device::V3_4::StreamConfiguration, streams), &_hidl_streams_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.streams.size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::camera::device::V3_4::Stream &>(obj.streams[_hidl_index_0]),
                parcel,
                _hidl_streams_child,
                _hidl_index_0 * sizeof(::android::hardware::camera::device::V3_4::Stream));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    size_t _hidl_sessionParams_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(obj.sessionParams),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::camera::device::V3_4::StreamConfiguration, sessionParams), &_hidl_sessionParams_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const StreamConfiguration &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_streams_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.streams,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::camera::device::V3_4::StreamConfiguration, streams), &_hidl_streams_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.streams.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                obj.streams[_hidl_index_0],
                parcel,
                _hidl_streams_child,
                _hidl_index_0 * sizeof(::android::hardware::camera::device::V3_4::Stream));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    size_t _hidl_sessionParams_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.sessionParams,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::camera::device::V3_4::StreamConfiguration, sessionParams), &_hidl_sessionParams_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const HalStream &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.physicalCameraId),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::camera::device::V3_4::HalStream, physicalCameraId));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const HalStream &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.physicalCameraId,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::camera::device::V3_4::HalStream, physicalCameraId));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const HalStreamConfiguration &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_streams_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::camera::device::V3_4::HalStream> &>(obj.streams),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::camera::device::V3_4::HalStreamConfiguration, streams), &_hidl_streams_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.streams.size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::camera::device::V3_4::HalStream &>(obj.streams[_hidl_index_0]),
                parcel,
                _hidl_streams_child,
                _hidl_index_0 * sizeof(::android::hardware::camera::device::V3_4::HalStream));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const HalStreamConfiguration &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_streams_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.streams,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::camera::device::V3_4::HalStreamConfiguration, streams), &_hidl_streams_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.streams.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                obj.streams[_hidl_index_0],
                parcel,
                _hidl_streams_child,
                _hidl_index_0 * sizeof(::android::hardware::camera::device::V3_4::HalStream));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const PhysicalCameraSetting &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.physicalCameraId),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::camera::device::V3_4::PhysicalCameraSetting, physicalCameraId));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_settings_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(obj.settings),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::camera::device::V3_4::PhysicalCameraSetting, settings), &_hidl_settings_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const PhysicalCameraSetting &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.physicalCameraId,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::camera::device::V3_4::PhysicalCameraSetting, physicalCameraId));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_settings_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.settings,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::camera::device::V3_4::PhysicalCameraSetting, settings), &_hidl_settings_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const CaptureRequest &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::camera::device::V3_2::CaptureRequest &>(obj.v3_2),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::camera::device::V3_4::CaptureRequest, v3_2));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_physicalCameraSettings_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::camera::device::V3_4::PhysicalCameraSetting> &>(obj.physicalCameraSettings),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::camera::device::V3_4::CaptureRequest, physicalCameraSettings), &_hidl_physicalCameraSettings_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.physicalCameraSettings.size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::camera::device::V3_4::PhysicalCameraSetting &>(obj.physicalCameraSettings[_hidl_index_0]),
                parcel,
                _hidl_physicalCameraSettings_child,
                _hidl_index_0 * sizeof(::android::hardware::camera::device::V3_4::PhysicalCameraSetting));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const CaptureRequest &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = writeEmbeddedToParcel(
            obj.v3_2,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::camera::device::V3_4::CaptureRequest, v3_2));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_physicalCameraSettings_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.physicalCameraSettings,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::camera::device::V3_4::CaptureRequest, physicalCameraSettings), &_hidl_physicalCameraSettings_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.physicalCameraSettings.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                obj.physicalCameraSettings[_hidl_index_0],
                parcel,
                _hidl_physicalCameraSettings_child,
                _hidl_index_0 * sizeof(::android::hardware::camera::device::V3_4::PhysicalCameraSetting));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const PhysicalCameraMetadata &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.physicalCameraId),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::camera::device::V3_4::PhysicalCameraMetadata, physicalCameraId));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_metadata_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(obj.metadata),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::camera::device::V3_4::PhysicalCameraMetadata, metadata), &_hidl_metadata_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const PhysicalCameraMetadata &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.physicalCameraId,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::camera::device::V3_4::PhysicalCameraMetadata, physicalCameraId));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_metadata_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.metadata,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::camera::device::V3_4::PhysicalCameraMetadata, metadata), &_hidl_metadata_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const CaptureResult &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::camera::device::V3_2::CaptureResult &>(obj.v3_2),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::camera::device::V3_4::CaptureResult, v3_2));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_physicalCameraMetadata_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::camera::device::V3_4::PhysicalCameraMetadata> &>(obj.physicalCameraMetadata),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::camera::device::V3_4::CaptureResult, physicalCameraMetadata), &_hidl_physicalCameraMetadata_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.physicalCameraMetadata.size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::camera::device::V3_4::PhysicalCameraMetadata &>(obj.physicalCameraMetadata[_hidl_index_0]),
                parcel,
                _hidl_physicalCameraMetadata_child,
                _hidl_index_0 * sizeof(::android::hardware::camera::device::V3_4::PhysicalCameraMetadata));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const CaptureResult &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = writeEmbeddedToParcel(
            obj.v3_2,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::camera::device::V3_4::CaptureResult, v3_2));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_physicalCameraMetadata_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.physicalCameraMetadata,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::camera::device::V3_4::CaptureResult, physicalCameraMetadata), &_hidl_physicalCameraMetadata_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.physicalCameraMetadata.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                obj.physicalCameraMetadata[_hidl_index_0],
                parcel,
                _hidl_physicalCameraMetadata_child,
                _hidl_index_0 * sizeof(::android::hardware::camera::device::V3_4::PhysicalCameraMetadata));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    return _hidl_err;
}

static_assert(sizeof(::android::hardware::MQDescriptor<char, ::android::hardware::kSynchronizedReadWrite>) == 32, "wrong size");
static_assert(sizeof(::android::hardware::hidl_handle) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_memory) == 40, "wrong size");
static_assert(sizeof(::android::hardware::hidl_string) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_vec<char>) == 16, "wrong size");

}  // namespace V3_4
}  // namespace device
}  // namespace camera
}  // namespace hardware
}  // namespace android
