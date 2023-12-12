#define LOG_TAG "android.hardware.audio@4.0::types"

#include <log/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <hidl/Static.h>
#include <hwbinder/ProcessState.h>
#include <utils/Trace.h>
#include <android/hardware/audio/4.0/types.h>
#include <android/hardware/audio/4.0/hwtypes.h>

namespace android {
namespace hardware {
namespace audio {
namespace V4_0 {

::android::status_t readEmbeddedFromParcel(
        const ParameterValue &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.key),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::V4_0::ParameterValue, key));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.value),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::V4_0::ParameterValue, value));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const ParameterValue &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.key,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::V4_0::ParameterValue, key));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.value,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::V4_0::ParameterValue, value));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const DeviceAddress &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.busAddress),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::V4_0::DeviceAddress, busAddress));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.rSubmixAddress),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::V4_0::DeviceAddress, rSubmixAddress));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const DeviceAddress &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.busAddress,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::V4_0::DeviceAddress, busAddress));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.rSubmixAddress,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::V4_0::DeviceAddress, rSubmixAddress));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const MmapBufferInfo &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_memory &>(obj.sharedMemory),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::V4_0::MmapBufferInfo, sharedMemory));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const MmapBufferInfo &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.sharedMemory,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::V4_0::MmapBufferInfo, sharedMemory));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const SourceMetadata &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_tracks_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::audio::V4_0::PlaybackTrackMetadata> &>(obj.tracks),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::V4_0::SourceMetadata, tracks), &_hidl_tracks_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const SourceMetadata &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_tracks_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.tracks,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::V4_0::SourceMetadata, tracks), &_hidl_tracks_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const SinkMetadata &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_tracks_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::audio::V4_0::RecordTrackMetadata> &>(obj.tracks),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::V4_0::SinkMetadata, tracks), &_hidl_tracks_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const SinkMetadata &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_tracks_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.tracks,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::V4_0::SinkMetadata, tracks), &_hidl_tracks_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const MicrophoneInfo &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.deviceId),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::V4_0::MicrophoneInfo, deviceId));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::audio::V4_0::DeviceAddress &>(obj.deviceAddress),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::V4_0::MicrophoneInfo, deviceAddress));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_channelMapping_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::audio::V4_0::AudioMicrophoneChannelMapping> &>(obj.channelMapping),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::V4_0::MicrophoneInfo, channelMapping), &_hidl_channelMapping_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_frequencyResponse_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::audio::V4_0::AudioFrequencyResponsePoint> &>(obj.frequencyResponse),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::V4_0::MicrophoneInfo, frequencyResponse), &_hidl_frequencyResponse_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const MicrophoneInfo &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.deviceId,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::V4_0::MicrophoneInfo, deviceId));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = writeEmbeddedToParcel(
            obj.deviceAddress,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::V4_0::MicrophoneInfo, deviceAddress));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_channelMapping_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.channelMapping,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::V4_0::MicrophoneInfo, channelMapping), &_hidl_channelMapping_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_frequencyResponse_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.frequencyResponse,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::V4_0::MicrophoneInfo, frequencyResponse), &_hidl_frequencyResponse_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

static_assert(sizeof(::android::hardware::MQDescriptor<char, ::android::hardware::kSynchronizedReadWrite>) == 32, "wrong size");
static_assert(sizeof(::android::hardware::hidl_handle) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_memory) == 40, "wrong size");
static_assert(sizeof(::android::hardware::hidl_string) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_vec<char>) == 16, "wrong size");

}  // namespace V4_0
}  // namespace audio
}  // namespace hardware
}  // namespace android
