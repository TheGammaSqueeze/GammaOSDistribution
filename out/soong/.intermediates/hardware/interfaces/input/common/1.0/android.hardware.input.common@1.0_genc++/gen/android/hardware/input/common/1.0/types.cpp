#define LOG_TAG "android.hardware.input.common@1.0::types"

#include <log/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <hidl/Static.h>
#include <hwbinder/ProcessState.h>
#include <utils/Trace.h>
#include <android/hardware/input/common/1.0/types.h>
#include <android/hardware/input/common/1.0/hwtypes.h>

namespace android {
namespace hardware {
namespace input {
namespace common {
namespace V1_0 {

::android::status_t readEmbeddedFromParcel(
        const PointerCoords &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_values_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<float> &>(obj.values),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::input::common::V1_0::PointerCoords, values), &_hidl_values_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const PointerCoords &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_values_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.values,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::input::common::V1_0::PointerCoords, values), &_hidl_values_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const VideoFrame &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_data_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<int16_t> &>(obj.data),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::input::common::V1_0::VideoFrame, data), &_hidl_data_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const VideoFrame &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_data_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.data,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::input::common::V1_0::VideoFrame, data), &_hidl_data_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const MotionEvent &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_pointerProperties_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::input::common::V1_0::PointerProperties> &>(obj.pointerProperties),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::input::common::V1_0::MotionEvent, pointerProperties), &_hidl_pointerProperties_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_pointerCoords_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::input::common::V1_0::PointerCoords> &>(obj.pointerCoords),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::input::common::V1_0::MotionEvent, pointerCoords), &_hidl_pointerCoords_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.pointerCoords.size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::input::common::V1_0::PointerCoords &>(obj.pointerCoords[_hidl_index_0]),
                parcel,
                _hidl_pointerCoords_child,
                _hidl_index_0 * sizeof(::android::hardware::input::common::V1_0::PointerCoords));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    size_t _hidl_frames_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::input::common::V1_0::VideoFrame> &>(obj.frames),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::input::common::V1_0::MotionEvent, frames), &_hidl_frames_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.frames.size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::input::common::V1_0::VideoFrame &>(obj.frames[_hidl_index_0]),
                parcel,
                _hidl_frames_child,
                _hidl_index_0 * sizeof(::android::hardware::input::common::V1_0::VideoFrame));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const MotionEvent &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_pointerProperties_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.pointerProperties,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::input::common::V1_0::MotionEvent, pointerProperties), &_hidl_pointerProperties_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_pointerCoords_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.pointerCoords,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::input::common::V1_0::MotionEvent, pointerCoords), &_hidl_pointerCoords_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.pointerCoords.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                obj.pointerCoords[_hidl_index_0],
                parcel,
                _hidl_pointerCoords_child,
                _hidl_index_0 * sizeof(::android::hardware::input::common::V1_0::PointerCoords));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    size_t _hidl_frames_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.frames,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::input::common::V1_0::MotionEvent, frames), &_hidl_frames_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.frames.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                obj.frames[_hidl_index_0],
                parcel,
                _hidl_frames_child,
                _hidl_index_0 * sizeof(::android::hardware::input::common::V1_0::VideoFrame));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    return _hidl_err;
}

static_assert(sizeof(::android::hardware::MQDescriptor<char, ::android::hardware::kSynchronizedReadWrite>) == 32, "wrong size");
static_assert(sizeof(::android::hardware::hidl_handle) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_memory) == 40, "wrong size");
static_assert(sizeof(::android::hardware::hidl_string) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_vec<char>) == 16, "wrong size");

}  // namespace V1_0
}  // namespace common
}  // namespace input
}  // namespace hardware
}  // namespace android
