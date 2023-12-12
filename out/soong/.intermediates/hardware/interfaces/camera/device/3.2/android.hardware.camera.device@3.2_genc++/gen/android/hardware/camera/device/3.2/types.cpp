#define LOG_TAG "android.hardware.camera.device@3.2::types"

#include <log/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <hidl/Static.h>
#include <hwbinder/ProcessState.h>
#include <utils/Trace.h>
#include <android/hardware/camera/device/3.2/types.h>
#include <android/hardware/camera/device/3.2/hwtypes.h>

namespace android {
namespace hardware {
namespace camera {
namespace device {
namespace V3_2 {

::android::status_t readEmbeddedFromParcel(
        const StreamConfiguration &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_streams_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::camera::device::V3_2::Stream> &>(obj.streams),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::camera::device::V3_2::StreamConfiguration, streams), &_hidl_streams_child);

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
            parentOffset + offsetof(::android::hardware::camera::device::V3_2::StreamConfiguration, streams), &_hidl_streams_child);

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
            const_cast<::android::hardware::hidl_vec<::android::hardware::camera::device::V3_2::HalStream> &>(obj.streams),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::camera::device::V3_2::HalStreamConfiguration, streams), &_hidl_streams_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

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
            parentOffset + offsetof(::android::hardware::camera::device::V3_2::HalStreamConfiguration, streams), &_hidl_streams_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const StreamBuffer &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_handle &>(obj.buffer),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::camera::device::V3_2::StreamBuffer, buffer));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_handle &>(obj.acquireFence),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::camera::device::V3_2::StreamBuffer, acquireFence));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_handle &>(obj.releaseFence),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::camera::device::V3_2::StreamBuffer, releaseFence));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const StreamBuffer &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.buffer,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::camera::device::V3_2::StreamBuffer, buffer));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.acquireFence,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::camera::device::V3_2::StreamBuffer, acquireFence));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.releaseFence,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::camera::device::V3_2::StreamBuffer, releaseFence));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const CaptureRequest &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_settings_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(obj.settings),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::camera::device::V3_2::CaptureRequest, settings), &_hidl_settings_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::camera::device::V3_2::StreamBuffer &>(obj.inputBuffer),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::camera::device::V3_2::CaptureRequest, inputBuffer));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_outputBuffers_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::camera::device::V3_2::StreamBuffer> &>(obj.outputBuffers),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::camera::device::V3_2::CaptureRequest, outputBuffers), &_hidl_outputBuffers_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.outputBuffers.size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::camera::device::V3_2::StreamBuffer &>(obj.outputBuffers[_hidl_index_0]),
                parcel,
                _hidl_outputBuffers_child,
                _hidl_index_0 * sizeof(::android::hardware::camera::device::V3_2::StreamBuffer));

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

    size_t _hidl_settings_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.settings,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::camera::device::V3_2::CaptureRequest, settings), &_hidl_settings_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = writeEmbeddedToParcel(
            obj.inputBuffer,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::camera::device::V3_2::CaptureRequest, inputBuffer));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_outputBuffers_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.outputBuffers,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::camera::device::V3_2::CaptureRequest, outputBuffers), &_hidl_outputBuffers_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.outputBuffers.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                obj.outputBuffers[_hidl_index_0],
                parcel,
                _hidl_outputBuffers_child,
                _hidl_index_0 * sizeof(::android::hardware::camera::device::V3_2::StreamBuffer));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const CaptureResult &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_result_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(obj.result),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::camera::device::V3_2::CaptureResult, result), &_hidl_result_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_outputBuffers_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::camera::device::V3_2::StreamBuffer> &>(obj.outputBuffers),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::camera::device::V3_2::CaptureResult, outputBuffers), &_hidl_outputBuffers_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.outputBuffers.size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::camera::device::V3_2::StreamBuffer &>(obj.outputBuffers[_hidl_index_0]),
                parcel,
                _hidl_outputBuffers_child,
                _hidl_index_0 * sizeof(::android::hardware::camera::device::V3_2::StreamBuffer));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::camera::device::V3_2::StreamBuffer &>(obj.inputBuffer),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::camera::device::V3_2::CaptureResult, inputBuffer));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const CaptureResult &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_result_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.result,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::camera::device::V3_2::CaptureResult, result), &_hidl_result_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_outputBuffers_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.outputBuffers,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::camera::device::V3_2::CaptureResult, outputBuffers), &_hidl_outputBuffers_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.outputBuffers.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                obj.outputBuffers[_hidl_index_0],
                parcel,
                _hidl_outputBuffers_child,
                _hidl_index_0 * sizeof(::android::hardware::camera::device::V3_2::StreamBuffer));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    _hidl_err = writeEmbeddedToParcel(
            obj.inputBuffer,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::camera::device::V3_2::CaptureResult, inputBuffer));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

static_assert(sizeof(::android::hardware::MQDescriptor<char, ::android::hardware::kSynchronizedReadWrite>) == 32, "wrong size");
static_assert(sizeof(::android::hardware::hidl_handle) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_memory) == 40, "wrong size");
static_assert(sizeof(::android::hardware::hidl_string) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_vec<char>) == 16, "wrong size");

}  // namespace V3_2
}  // namespace device
}  // namespace camera
}  // namespace hardware
}  // namespace android
