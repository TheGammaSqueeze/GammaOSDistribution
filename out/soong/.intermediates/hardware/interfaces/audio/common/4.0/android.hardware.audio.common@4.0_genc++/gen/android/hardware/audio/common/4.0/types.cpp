#define LOG_TAG "android.hardware.audio.common@4.0::types"

#include <log/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <hidl/Static.h>
#include <hwbinder/ProcessState.h>
#include <utils/Trace.h>
#include <android/hardware/audio/common/4.0/types.h>
#include <android/hardware/audio/common/4.0/hwtypes.h>

namespace android {
namespace hardware {
namespace audio {
namespace common {
namespace V4_0 {

::android::status_t readEmbeddedFromParcel(
        const AudioPort &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.name),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::common::V4_0::AudioPort, name));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_sampleRates_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint32_t> &>(obj.sampleRates),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::common::V4_0::AudioPort, sampleRates), &_hidl_sampleRates_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_channelMasks_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::hidl_bitfield<::android::hardware::audio::common::V4_0::AudioChannelMask>> &>(obj.channelMasks),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::common::V4_0::AudioPort, channelMasks), &_hidl_channelMasks_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_formats_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::audio::common::V4_0::AudioFormat> &>(obj.formats),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::common::V4_0::AudioPort, formats), &_hidl_formats_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_gains_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::audio::common::V4_0::AudioGain> &>(obj.gains),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::common::V4_0::AudioPort, gains), &_hidl_gains_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const AudioPort &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.name,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::common::V4_0::AudioPort, name));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_sampleRates_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.sampleRates,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::common::V4_0::AudioPort, sampleRates), &_hidl_sampleRates_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_channelMasks_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.channelMasks,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::common::V4_0::AudioPort, channelMasks), &_hidl_channelMasks_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_formats_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.formats,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::common::V4_0::AudioPort, formats), &_hidl_formats_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_gains_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.gains,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::common::V4_0::AudioPort, gains), &_hidl_gains_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

static_assert(sizeof(::android::hardware::MQDescriptor<char, ::android::hardware::kSynchronizedReadWrite>) == 32, "wrong size");
static_assert(sizeof(::android::hardware::hidl_handle) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_memory) == 40, "wrong size");
static_assert(sizeof(::android::hardware::hidl_string) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_vec<char>) == 16, "wrong size");

}  // namespace V4_0
}  // namespace common
}  // namespace audio
}  // namespace hardware
}  // namespace android
