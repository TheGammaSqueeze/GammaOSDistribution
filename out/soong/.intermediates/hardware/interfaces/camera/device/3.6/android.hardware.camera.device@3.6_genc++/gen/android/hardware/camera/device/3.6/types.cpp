#define LOG_TAG "android.hardware.camera.device@3.6::types"

#include <log/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <hidl/Static.h>
#include <hwbinder/ProcessState.h>
#include <utils/Trace.h>
#include <android/hardware/camera/device/3.6/types.h>
#include <android/hardware/camera/device/3.6/hwtypes.h>

namespace android {
namespace hardware {
namespace camera {
namespace device {
namespace V3_6 {

::android::status_t readEmbeddedFromParcel(
        const OfflineRequest &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_pendingStreams_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<int32_t> &>(obj.pendingStreams),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::camera::device::V3_6::OfflineRequest, pendingStreams), &_hidl_pendingStreams_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const OfflineRequest &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_pendingStreams_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.pendingStreams,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::camera::device::V3_6::OfflineRequest, pendingStreams), &_hidl_pendingStreams_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const OfflineStream &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_circulatingBufferIds_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint64_t> &>(obj.circulatingBufferIds),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::camera::device::V3_6::OfflineStream, circulatingBufferIds), &_hidl_circulatingBufferIds_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const OfflineStream &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_circulatingBufferIds_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.circulatingBufferIds,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::camera::device::V3_6::OfflineStream, circulatingBufferIds), &_hidl_circulatingBufferIds_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const CameraOfflineSessionInfo &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_offlineStreams_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::camera::device::V3_6::OfflineStream> &>(obj.offlineStreams),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::camera::device::V3_6::CameraOfflineSessionInfo, offlineStreams), &_hidl_offlineStreams_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.offlineStreams.size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::camera::device::V3_6::OfflineStream &>(obj.offlineStreams[_hidl_index_0]),
                parcel,
                _hidl_offlineStreams_child,
                _hidl_index_0 * sizeof(::android::hardware::camera::device::V3_6::OfflineStream));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    size_t _hidl_offlineRequests_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::camera::device::V3_6::OfflineRequest> &>(obj.offlineRequests),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::camera::device::V3_6::CameraOfflineSessionInfo, offlineRequests), &_hidl_offlineRequests_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.offlineRequests.size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::camera::device::V3_6::OfflineRequest &>(obj.offlineRequests[_hidl_index_0]),
                parcel,
                _hidl_offlineRequests_child,
                _hidl_index_0 * sizeof(::android::hardware::camera::device::V3_6::OfflineRequest));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const CameraOfflineSessionInfo &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_offlineStreams_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.offlineStreams,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::camera::device::V3_6::CameraOfflineSessionInfo, offlineStreams), &_hidl_offlineStreams_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.offlineStreams.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                obj.offlineStreams[_hidl_index_0],
                parcel,
                _hidl_offlineStreams_child,
                _hidl_index_0 * sizeof(::android::hardware::camera::device::V3_6::OfflineStream));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    size_t _hidl_offlineRequests_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.offlineRequests,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::camera::device::V3_6::CameraOfflineSessionInfo, offlineRequests), &_hidl_offlineRequests_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.offlineRequests.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                obj.offlineRequests[_hidl_index_0],
                parcel,
                _hidl_offlineRequests_child,
                _hidl_index_0 * sizeof(::android::hardware::camera::device::V3_6::OfflineRequest));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const HalStream &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::camera::device::V3_4::HalStream &>(obj.v3_4),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::camera::device::V3_6::HalStream, v3_4));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const HalStream &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = writeEmbeddedToParcel(
            obj.v3_4,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::camera::device::V3_6::HalStream, v3_4));

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
            const_cast<::android::hardware::hidl_vec<::android::hardware::camera::device::V3_6::HalStream> &>(obj.streams),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::camera::device::V3_6::HalStreamConfiguration, streams), &_hidl_streams_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.streams.size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::camera::device::V3_6::HalStream &>(obj.streams[_hidl_index_0]),
                parcel,
                _hidl_streams_child,
                _hidl_index_0 * sizeof(::android::hardware::camera::device::V3_6::HalStream));

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
            parentOffset + offsetof(::android::hardware::camera::device::V3_6::HalStreamConfiguration, streams), &_hidl_streams_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.streams.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                obj.streams[_hidl_index_0],
                parcel,
                _hidl_streams_child,
                _hidl_index_0 * sizeof(::android::hardware::camera::device::V3_6::HalStream));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    return _hidl_err;
}

static_assert(sizeof(::android::hardware::MQDescriptor<char, ::android::hardware::kSynchronizedReadWrite>) == 32, "wrong size");
static_assert(sizeof(::android::hardware::hidl_handle) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_memory) == 40, "wrong size");
static_assert(sizeof(::android::hardware::hidl_string) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_vec<char>) == 16, "wrong size");

}  // namespace V3_6
}  // namespace device
}  // namespace camera
}  // namespace hardware
}  // namespace android
