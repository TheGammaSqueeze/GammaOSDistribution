#define LOG_TAG "android.hardware.audio.common@6.0::types"

#include <log/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <hidl/Static.h>
#include <hwbinder/ProcessState.h>
#include <utils/Trace.h>
#include <android/hardware/audio/common/6.0/types.h>
#include <android/hardware/audio/common/6.0/hwtypes.h>

namespace android {
namespace hardware {
namespace audio {
namespace common {
namespace V6_0 {

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
            parentOffset + offsetof(::android::hardware::audio::common::V6_0::DeviceAddress, busAddress));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.rSubmixAddress),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::common::V6_0::DeviceAddress, rSubmixAddress));

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
            parentOffset + offsetof(::android::hardware::audio::common::V6_0::DeviceAddress, busAddress));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.rSubmixAddress,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::common::V6_0::DeviceAddress, rSubmixAddress));

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
            const_cast<::android::hardware::hidl_vec<::android::hardware::audio::common::V6_0::PlaybackTrackMetadata> &>(obj.tracks),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::common::V6_0::SourceMetadata, tracks), &_hidl_tracks_child);

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
            parentOffset + offsetof(::android::hardware::audio::common::V6_0::SourceMetadata, tracks), &_hidl_tracks_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const RecordTrackMetadata::Destination &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    switch (obj.getDiscriminator()) {
        case ::android::hardware::audio::common::V6_0::RecordTrackMetadata::Destination::hidl_discriminator::device: {
            _hidl_err = readEmbeddedFromParcel(
                    const_cast<::android::hardware::audio::common::V6_0::DeviceAddress &>(obj.device()),
                    parcel,
                    parentHandle,
                    parentOffset + obj.hidl_getUnionOffset() /* safe_union: union offset into struct */);

            if (_hidl_err != ::android::OK) { return _hidl_err; }

            break;
        }
        default: { break; }
    }
    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const RecordTrackMetadata::Destination &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    switch (obj.getDiscriminator()) {
        case ::android::hardware::audio::common::V6_0::RecordTrackMetadata::Destination::hidl_discriminator::device: {
            _hidl_err = writeEmbeddedToParcel(
                    obj.device(),
                    parcel,
                    parentHandle,
                    parentOffset + obj.hidl_getUnionOffset() /* safe_union: union offset into struct */);

            if (_hidl_err != ::android::OK) { return _hidl_err; }

            break;
        }
        default: { break; }
    }
    return _hidl_err;
}

::android::hardware::audio::common::V6_0::RecordTrackMetadata::Destination::Destination() {
    static_assert(offsetof(::android::hardware::audio::common::V6_0::RecordTrackMetadata::Destination, hidl_d) == 0, "wrong offset");
    static_assert(offsetof(::android::hardware::audio::common::V6_0::RecordTrackMetadata::Destination, hidl_u) == 8, "wrong offset");

    ::std::memset(&hidl_u, 0, sizeof(hidl_u));
    ::std::memset(reinterpret_cast<uint8_t*>(this) + 1, 0, 7);
    // no padding to zero starting at offset 56

    hidl_d = hidl_discriminator::unspecified;
    new (&hidl_u.unspecified) ::android::hidl::safe_union::V1_0::Monostate();
}

::android::hardware::audio::common::V6_0::RecordTrackMetadata::Destination::~Destination() {
    hidl_destructUnion();
}

::android::hardware::audio::common::V6_0::RecordTrackMetadata::Destination::Destination(Destination&& other) : ::android::hardware::audio::common::V6_0::RecordTrackMetadata::Destination() {
    *this = std::move(other);
}

::android::hardware::audio::common::V6_0::RecordTrackMetadata::Destination::Destination(const Destination& other) : ::android::hardware::audio::common::V6_0::RecordTrackMetadata::Destination() {
    *this = other;
}

::android::hardware::audio::common::V6_0::RecordTrackMetadata::Destination& (::android::hardware::audio::common::V6_0::RecordTrackMetadata::Destination::operator=)(Destination&& other) {
    if (this == &other) { return *this; }

    switch (other.hidl_d) {
        case hidl_discriminator::unspecified: {
            unspecified(std::move(other.hidl_u.unspecified));
            break;
        }
        case hidl_discriminator::device: {
            device(std::move(other.hidl_u.device));
            break;
        }
        default: {
            ::android::hardware::details::logAlwaysFatal((
                    "Unknown union discriminator (value: " +
                    std::to_string((uint8_t) other.hidl_d) + ").").c_str());
        }
    }
    return *this;
}

::android::hardware::audio::common::V6_0::RecordTrackMetadata::Destination& (::android::hardware::audio::common::V6_0::RecordTrackMetadata::Destination::operator=)(const Destination& other) {
    if (this == &other) { return *this; }

    switch (other.hidl_d) {
        case hidl_discriminator::unspecified: {
            unspecified(other.hidl_u.unspecified);
            break;
        }
        case hidl_discriminator::device: {
            device(other.hidl_u.device);
            break;
        }
        default: {
            ::android::hardware::details::logAlwaysFatal((
                    "Unknown union discriminator (value: " +
                    std::to_string((uint8_t) other.hidl_d) + ").").c_str());
        }
    }
    return *this;
}

void ::android::hardware::audio::common::V6_0::RecordTrackMetadata::Destination::hidl_destructUnion() {
    switch (hidl_d) {
        case hidl_discriminator::unspecified: {
            ::android::hardware::details::destructElement(&(hidl_u.unspecified));
            break;
        }
        case hidl_discriminator::device: {
            ::android::hardware::details::destructElement(&(hidl_u.device));
            break;
        }
        default: {
            ::android::hardware::details::logAlwaysFatal((
                    "Unknown union discriminator (value: " +
                    std::to_string((uint8_t) hidl_d) + ").").c_str());
        }
    }

}

void ::android::hardware::audio::common::V6_0::RecordTrackMetadata::Destination::unspecified(const ::android::hidl::safe_union::V1_0::Monostate& o) {
    if (hidl_d != hidl_discriminator::unspecified) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.unspecified) ::android::hidl::safe_union::V1_0::Monostate(o);
        hidl_d = hidl_discriminator::unspecified;
    }
    else if (&(hidl_u.unspecified) != &o) {
        hidl_u.unspecified = o;
    }
}

void ::android::hardware::audio::common::V6_0::RecordTrackMetadata::Destination::unspecified(::android::hidl::safe_union::V1_0::Monostate&& o) {
    if (hidl_d != hidl_discriminator::unspecified) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.unspecified) ::android::hidl::safe_union::V1_0::Monostate(std::move(o));
        hidl_d = hidl_discriminator::unspecified;
    }
    else if (&(hidl_u.unspecified) != &o) {
        hidl_u.unspecified = std::move(o);
    }
}

::android::hidl::safe_union::V1_0::Monostate& (::android::hardware::audio::common::V6_0::RecordTrackMetadata::Destination::unspecified)() {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::unspecified)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::unspecified));
    }

    return hidl_u.unspecified;
}

const ::android::hidl::safe_union::V1_0::Monostate& (::android::hardware::audio::common::V6_0::RecordTrackMetadata::Destination::unspecified)() const {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::unspecified)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::unspecified));
    }

    return hidl_u.unspecified;
}

void ::android::hardware::audio::common::V6_0::RecordTrackMetadata::Destination::device(const ::android::hardware::audio::common::V6_0::DeviceAddress& o) {
    if (hidl_d != hidl_discriminator::device) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.device) ::android::hardware::audio::common::V6_0::DeviceAddress(o);
        hidl_d = hidl_discriminator::device;
    }
    else if (&(hidl_u.device) != &o) {
        hidl_u.device = o;
    }
}

void ::android::hardware::audio::common::V6_0::RecordTrackMetadata::Destination::device(::android::hardware::audio::common::V6_0::DeviceAddress&& o) {
    if (hidl_d != hidl_discriminator::device) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.device) ::android::hardware::audio::common::V6_0::DeviceAddress(std::move(o));
        hidl_d = hidl_discriminator::device;
    }
    else if (&(hidl_u.device) != &o) {
        hidl_u.device = std::move(o);
    }
}

::android::hardware::audio::common::V6_0::DeviceAddress& (::android::hardware::audio::common::V6_0::RecordTrackMetadata::Destination::device)() {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::device)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::device));
    }

    return hidl_u.device;
}

const ::android::hardware::audio::common::V6_0::DeviceAddress& (::android::hardware::audio::common::V6_0::RecordTrackMetadata::Destination::device)() const {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::device)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::device));
    }

    return hidl_u.device;
}

::android::hardware::audio::common::V6_0::RecordTrackMetadata::Destination::hidl_union::hidl_union() {}

::android::hardware::audio::common::V6_0::RecordTrackMetadata::Destination::hidl_union::~hidl_union() {}

::android::hardware::audio::common::V6_0::RecordTrackMetadata::Destination::hidl_discriminator (::android::hardware::audio::common::V6_0::RecordTrackMetadata::Destination::getDiscriminator)() const {
    return hidl_d;
}

::android::status_t readEmbeddedFromParcel(
        const RecordTrackMetadata &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::audio::common::V6_0::RecordTrackMetadata::Destination &>(obj.destination),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::common::V6_0::RecordTrackMetadata, destination));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const RecordTrackMetadata &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = writeEmbeddedToParcel(
            obj.destination,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::common::V6_0::RecordTrackMetadata, destination));

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
            const_cast<::android::hardware::hidl_vec<::android::hardware::audio::common::V6_0::RecordTrackMetadata> &>(obj.tracks),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::common::V6_0::SinkMetadata, tracks), &_hidl_tracks_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.tracks.size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::audio::common::V6_0::RecordTrackMetadata &>(obj.tracks[_hidl_index_0]),
                parcel,
                _hidl_tracks_child,
                _hidl_index_0 * sizeof(::android::hardware::audio::common::V6_0::RecordTrackMetadata));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

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
            parentOffset + offsetof(::android::hardware::audio::common::V6_0::SinkMetadata, tracks), &_hidl_tracks_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.tracks.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                obj.tracks[_hidl_index_0],
                parcel,
                _hidl_tracks_child,
                _hidl_index_0 * sizeof(::android::hardware::audio::common::V6_0::RecordTrackMetadata));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    return _hidl_err;
}

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
            parentOffset + offsetof(::android::hardware::audio::common::V6_0::AudioPort, name));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_sampleRates_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint32_t> &>(obj.sampleRates),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::common::V6_0::AudioPort, sampleRates), &_hidl_sampleRates_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_channelMasks_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::hidl_bitfield<::android::hardware::audio::common::V6_0::AudioChannelMask>> &>(obj.channelMasks),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::common::V6_0::AudioPort, channelMasks), &_hidl_channelMasks_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_formats_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::audio::common::V6_0::AudioFormat> &>(obj.formats),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::common::V6_0::AudioPort, formats), &_hidl_formats_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_gains_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::audio::common::V6_0::AudioGain> &>(obj.gains),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::common::V6_0::AudioPort, gains), &_hidl_gains_child);

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
            parentOffset + offsetof(::android::hardware::audio::common::V6_0::AudioPort, name));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_sampleRates_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.sampleRates,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::common::V6_0::AudioPort, sampleRates), &_hidl_sampleRates_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_channelMasks_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.channelMasks,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::common::V6_0::AudioPort, channelMasks), &_hidl_channelMasks_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_formats_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.formats,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::common::V6_0::AudioPort, formats), &_hidl_formats_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_gains_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.gains,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::common::V6_0::AudioPort, gains), &_hidl_gains_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

static_assert(sizeof(::android::hardware::MQDescriptor<char, ::android::hardware::kSynchronizedReadWrite>) == 32, "wrong size");
static_assert(sizeof(::android::hardware::hidl_handle) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_memory) == 40, "wrong size");
static_assert(sizeof(::android::hardware::hidl_string) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_vec<char>) == 16, "wrong size");

}  // namespace V6_0
}  // namespace common
}  // namespace audio
}  // namespace hardware
}  // namespace android
