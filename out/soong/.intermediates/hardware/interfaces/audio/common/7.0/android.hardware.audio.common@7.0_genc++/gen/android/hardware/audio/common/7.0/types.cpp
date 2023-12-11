#define LOG_TAG "android.hardware.audio.common@7.0::types"

#include <log/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <hidl/Static.h>
#include <hwbinder/ProcessState.h>
#include <utils/Trace.h>
#include <android/hardware/audio/common/7.0/types.h>
#include <android/hardware/audio/common/7.0/hwtypes.h>

namespace android {
namespace hardware {
namespace audio {
namespace common {
namespace V7_0 {

::android::status_t readEmbeddedFromParcel(
        const AudioConfigBase &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.format),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::common::V7_0::AudioConfigBase, format));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.channelMask),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::common::V7_0::AudioConfigBase, channelMask));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const AudioConfigBase &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.format,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::common::V7_0::AudioConfigBase, format));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.channelMask,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::common::V7_0::AudioConfigBase, channelMask));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const AudioConfigBaseOptional::Format &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    switch (obj.getDiscriminator()) {
        case ::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::Format::hidl_discriminator::value: {
            _hidl_err = ::android::hardware::readEmbeddedFromParcel(
                    const_cast<::android::hardware::hidl_string &>(obj.value()),
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
        const AudioConfigBaseOptional::Format &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    switch (obj.getDiscriminator()) {
        case ::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::Format::hidl_discriminator::value: {
            _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                    obj.value(),
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

::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::Format::Format() {
    static_assert(offsetof(::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::Format, hidl_d) == 0, "wrong offset");
    static_assert(offsetof(::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::Format, hidl_u) == 8, "wrong offset");

    ::std::memset(&hidl_u, 0, sizeof(hidl_u));
    ::std::memset(reinterpret_cast<uint8_t*>(this) + 1, 0, 7);
    // no padding to zero starting at offset 24

    hidl_d = hidl_discriminator::unspecified;
    new (&hidl_u.unspecified) ::android::hidl::safe_union::V1_0::Monostate();
}

::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::Format::~Format() {
    hidl_destructUnion();
}

::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::Format::Format(Format&& other) : ::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::Format() {
    *this = std::move(other);
}

::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::Format::Format(const Format& other) : ::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::Format() {
    *this = other;
}

::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::Format& (::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::Format::operator=)(Format&& other) {
    if (this == &other) { return *this; }

    switch (other.hidl_d) {
        case hidl_discriminator::unspecified: {
            unspecified(std::move(other.hidl_u.unspecified));
            break;
        }
        case hidl_discriminator::value: {
            value(std::move(other.hidl_u.value));
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

::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::Format& (::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::Format::operator=)(const Format& other) {
    if (this == &other) { return *this; }

    switch (other.hidl_d) {
        case hidl_discriminator::unspecified: {
            unspecified(other.hidl_u.unspecified);
            break;
        }
        case hidl_discriminator::value: {
            value(other.hidl_u.value);
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

void ::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::Format::hidl_destructUnion() {
    switch (hidl_d) {
        case hidl_discriminator::unspecified: {
            ::android::hardware::details::destructElement(&(hidl_u.unspecified));
            break;
        }
        case hidl_discriminator::value: {
            ::android::hardware::details::destructElement(&(hidl_u.value));
            break;
        }
        default: {
            ::android::hardware::details::logAlwaysFatal((
                    "Unknown union discriminator (value: " +
                    std::to_string((uint8_t) hidl_d) + ").").c_str());
        }
    }

}

void ::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::Format::unspecified(const ::android::hidl::safe_union::V1_0::Monostate& o) {
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

void ::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::Format::unspecified(::android::hidl::safe_union::V1_0::Monostate&& o) {
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

::android::hidl::safe_union::V1_0::Monostate& (::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::Format::unspecified)() {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::unspecified)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::unspecified));
    }

    return hidl_u.unspecified;
}

const ::android::hidl::safe_union::V1_0::Monostate& (::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::Format::unspecified)() const {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::unspecified)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::unspecified));
    }

    return hidl_u.unspecified;
}

void ::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::Format::value(const ::android::hardware::hidl_string& o) {
    if (hidl_d != hidl_discriminator::value) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.value) ::android::hardware::hidl_string(o);
        hidl_d = hidl_discriminator::value;
    }
    else if (&(hidl_u.value) != &o) {
        hidl_u.value = o;
    }
}

void ::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::Format::value(::android::hardware::hidl_string&& o) {
    if (hidl_d != hidl_discriminator::value) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.value) ::android::hardware::hidl_string(std::move(o));
        hidl_d = hidl_discriminator::value;
    }
    else if (&(hidl_u.value) != &o) {
        hidl_u.value = std::move(o);
    }
}

::android::hardware::hidl_string& (::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::Format::value)() {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::value)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::value));
    }

    return hidl_u.value;
}

const ::android::hardware::hidl_string& (::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::Format::value)() const {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::value)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::value));
    }

    return hidl_u.value;
}

::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::Format::hidl_union::hidl_union() {}

::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::Format::hidl_union::~hidl_union() {}

::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::Format::hidl_discriminator (::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::Format::getDiscriminator)() const {
    return hidl_d;
}

::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::SampleRate::SampleRate() {
    static_assert(offsetof(::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::SampleRate, hidl_d) == 0, "wrong offset");
    static_assert(offsetof(::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::SampleRate, hidl_u) == 4, "wrong offset");

    ::std::memset(&hidl_u, 0, sizeof(hidl_u));
    ::std::memset(reinterpret_cast<uint8_t*>(this) + 1, 0, 3);
    // no padding to zero starting at offset 8

    hidl_d = hidl_discriminator::unspecified;
    new (&hidl_u.unspecified) ::android::hidl::safe_union::V1_0::Monostate();
}

::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::SampleRate::~SampleRate() {
    hidl_destructUnion();
}

::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::SampleRate::SampleRate(SampleRate&& other) : ::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::SampleRate() {
    *this = std::move(other);
}

::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::SampleRate::SampleRate(const SampleRate& other) : ::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::SampleRate() {
    *this = other;
}

::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::SampleRate& (::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::SampleRate::operator=)(SampleRate&& other) {
    if (this == &other) { return *this; }

    switch (other.hidl_d) {
        case hidl_discriminator::unspecified: {
            unspecified(std::move(other.hidl_u.unspecified));
            break;
        }
        case hidl_discriminator::value: {
            value(std::move(other.hidl_u.value));
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

::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::SampleRate& (::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::SampleRate::operator=)(const SampleRate& other) {
    if (this == &other) { return *this; }

    switch (other.hidl_d) {
        case hidl_discriminator::unspecified: {
            unspecified(other.hidl_u.unspecified);
            break;
        }
        case hidl_discriminator::value: {
            value(other.hidl_u.value);
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

void ::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::SampleRate::hidl_destructUnion() {
    switch (hidl_d) {
        case hidl_discriminator::unspecified: {
            ::android::hardware::details::destructElement(&(hidl_u.unspecified));
            break;
        }
        case hidl_discriminator::value: {
            ::android::hardware::details::destructElement(&(hidl_u.value));
            break;
        }
        default: {
            ::android::hardware::details::logAlwaysFatal((
                    "Unknown union discriminator (value: " +
                    std::to_string((uint8_t) hidl_d) + ").").c_str());
        }
    }

}

void ::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::SampleRate::unspecified(const ::android::hidl::safe_union::V1_0::Monostate& o) {
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

void ::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::SampleRate::unspecified(::android::hidl::safe_union::V1_0::Monostate&& o) {
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

::android::hidl::safe_union::V1_0::Monostate& (::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::SampleRate::unspecified)() {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::unspecified)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::unspecified));
    }

    return hidl_u.unspecified;
}

const ::android::hidl::safe_union::V1_0::Monostate& (::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::SampleRate::unspecified)() const {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::unspecified)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::unspecified));
    }

    return hidl_u.unspecified;
}

void ::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::SampleRate::value(uint32_t o) {
    if (hidl_d != hidl_discriminator::value) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.value) uint32_t(o);
        hidl_d = hidl_discriminator::value;
    }
    else if (&(hidl_u.value) != &o) {
        hidl_u.value = o;
    }
}

uint32_t& (::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::SampleRate::value)() {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::value)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::value));
    }

    return hidl_u.value;
}

uint32_t (::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::SampleRate::value)() const {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::value)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::value));
    }

    return hidl_u.value;
}

::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::SampleRate::hidl_union::hidl_union() {}

::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::SampleRate::hidl_union::~hidl_union() {}

::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::SampleRate::hidl_discriminator (::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::SampleRate::getDiscriminator)() const {
    return hidl_d;
}

::android::status_t readEmbeddedFromParcel(
        const AudioConfigBaseOptional::ChannelMask &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    switch (obj.getDiscriminator()) {
        case ::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::ChannelMask::hidl_discriminator::value: {
            _hidl_err = ::android::hardware::readEmbeddedFromParcel(
                    const_cast<::android::hardware::hidl_string &>(obj.value()),
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
        const AudioConfigBaseOptional::ChannelMask &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    switch (obj.getDiscriminator()) {
        case ::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::ChannelMask::hidl_discriminator::value: {
            _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                    obj.value(),
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

::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::ChannelMask::ChannelMask() {
    static_assert(offsetof(::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::ChannelMask, hidl_d) == 0, "wrong offset");
    static_assert(offsetof(::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::ChannelMask, hidl_u) == 8, "wrong offset");

    ::std::memset(&hidl_u, 0, sizeof(hidl_u));
    ::std::memset(reinterpret_cast<uint8_t*>(this) + 1, 0, 7);
    // no padding to zero starting at offset 24

    hidl_d = hidl_discriminator::unspecified;
    new (&hidl_u.unspecified) ::android::hidl::safe_union::V1_0::Monostate();
}

::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::ChannelMask::~ChannelMask() {
    hidl_destructUnion();
}

::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::ChannelMask::ChannelMask(ChannelMask&& other) : ::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::ChannelMask() {
    *this = std::move(other);
}

::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::ChannelMask::ChannelMask(const ChannelMask& other) : ::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::ChannelMask() {
    *this = other;
}

::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::ChannelMask& (::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::ChannelMask::operator=)(ChannelMask&& other) {
    if (this == &other) { return *this; }

    switch (other.hidl_d) {
        case hidl_discriminator::unspecified: {
            unspecified(std::move(other.hidl_u.unspecified));
            break;
        }
        case hidl_discriminator::value: {
            value(std::move(other.hidl_u.value));
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

::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::ChannelMask& (::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::ChannelMask::operator=)(const ChannelMask& other) {
    if (this == &other) { return *this; }

    switch (other.hidl_d) {
        case hidl_discriminator::unspecified: {
            unspecified(other.hidl_u.unspecified);
            break;
        }
        case hidl_discriminator::value: {
            value(other.hidl_u.value);
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

void ::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::ChannelMask::hidl_destructUnion() {
    switch (hidl_d) {
        case hidl_discriminator::unspecified: {
            ::android::hardware::details::destructElement(&(hidl_u.unspecified));
            break;
        }
        case hidl_discriminator::value: {
            ::android::hardware::details::destructElement(&(hidl_u.value));
            break;
        }
        default: {
            ::android::hardware::details::logAlwaysFatal((
                    "Unknown union discriminator (value: " +
                    std::to_string((uint8_t) hidl_d) + ").").c_str());
        }
    }

}

void ::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::ChannelMask::unspecified(const ::android::hidl::safe_union::V1_0::Monostate& o) {
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

void ::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::ChannelMask::unspecified(::android::hidl::safe_union::V1_0::Monostate&& o) {
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

::android::hidl::safe_union::V1_0::Monostate& (::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::ChannelMask::unspecified)() {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::unspecified)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::unspecified));
    }

    return hidl_u.unspecified;
}

const ::android::hidl::safe_union::V1_0::Monostate& (::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::ChannelMask::unspecified)() const {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::unspecified)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::unspecified));
    }

    return hidl_u.unspecified;
}

void ::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::ChannelMask::value(const ::android::hardware::hidl_string& o) {
    if (hidl_d != hidl_discriminator::value) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.value) ::android::hardware::hidl_string(o);
        hidl_d = hidl_discriminator::value;
    }
    else if (&(hidl_u.value) != &o) {
        hidl_u.value = o;
    }
}

void ::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::ChannelMask::value(::android::hardware::hidl_string&& o) {
    if (hidl_d != hidl_discriminator::value) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.value) ::android::hardware::hidl_string(std::move(o));
        hidl_d = hidl_discriminator::value;
    }
    else if (&(hidl_u.value) != &o) {
        hidl_u.value = std::move(o);
    }
}

::android::hardware::hidl_string& (::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::ChannelMask::value)() {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::value)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::value));
    }

    return hidl_u.value;
}

const ::android::hardware::hidl_string& (::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::ChannelMask::value)() const {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::value)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::value));
    }

    return hidl_u.value;
}

::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::ChannelMask::hidl_union::hidl_union() {}

::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::ChannelMask::hidl_union::~hidl_union() {}

::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::ChannelMask::hidl_discriminator (::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::ChannelMask::getDiscriminator)() const {
    return hidl_d;
}

::android::status_t readEmbeddedFromParcel(
        const AudioConfigBaseOptional &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::Format &>(obj.format),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::common::V7_0::AudioConfigBaseOptional, format));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::ChannelMask &>(obj.channelMask),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::common::V7_0::AudioConfigBaseOptional, channelMask));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const AudioConfigBaseOptional &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = writeEmbeddedToParcel(
            obj.format,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::common::V7_0::AudioConfigBaseOptional, format));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = writeEmbeddedToParcel(
            obj.channelMask,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::common::V7_0::AudioConfigBaseOptional, channelMask));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const AudioProfile &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.format),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::common::V7_0::AudioProfile, format));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_sampleRates_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint32_t> &>(obj.sampleRates),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::common::V7_0::AudioProfile, sampleRates), &_hidl_sampleRates_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_channelMasks_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::hidl_string> &>(obj.channelMasks),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::common::V7_0::AudioProfile, channelMasks), &_hidl_channelMasks_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.channelMasks.size(); ++_hidl_index_0) {
        _hidl_err = ::android::hardware::readEmbeddedFromParcel(
                const_cast<::android::hardware::hidl_string &>(obj.channelMasks[_hidl_index_0]),
                parcel,
                _hidl_channelMasks_child,
                _hidl_index_0 * sizeof(::android::hardware::hidl_string));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const AudioProfile &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.format,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::common::V7_0::AudioProfile, format));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_sampleRates_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.sampleRates,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::common::V7_0::AudioProfile, sampleRates), &_hidl_sampleRates_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_channelMasks_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.channelMasks,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::common::V7_0::AudioProfile, channelMasks), &_hidl_channelMasks_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.channelMasks.size(); ++_hidl_index_0) {
        _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                obj.channelMasks[_hidl_index_0],
                parcel,
                _hidl_channelMasks_child,
                _hidl_index_0 * sizeof(::android::hardware::hidl_string));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const AudioTransport::AudioCapability &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    switch (obj.getDiscriminator()) {
        case ::android::hardware::audio::common::V7_0::AudioTransport::AudioCapability::hidl_discriminator::profile: {
            _hidl_err = readEmbeddedFromParcel(
                    const_cast<::android::hardware::audio::common::V7_0::AudioProfile &>(obj.profile()),
                    parcel,
                    parentHandle,
                    parentOffset + obj.hidl_getUnionOffset() /* safe_union: union offset into struct */);

            if (_hidl_err != ::android::OK) { return _hidl_err; }

            break;
        }
        case ::android::hardware::audio::common::V7_0::AudioTransport::AudioCapability::hidl_discriminator::edid: {
            size_t _hidl_edid_child;

            _hidl_err = ::android::hardware::readEmbeddedFromParcel(
                    const_cast<::android::hardware::hidl_vec<uint8_t> &>(obj.edid()),
                    parcel,
                    parentHandle,
                    parentOffset + obj.hidl_getUnionOffset() /* safe_union: union offset into struct */, &_hidl_edid_child);

            if (_hidl_err != ::android::OK) { return _hidl_err; }

            break;
        }
        default: { break; }
    }
    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const AudioTransport::AudioCapability &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    switch (obj.getDiscriminator()) {
        case ::android::hardware::audio::common::V7_0::AudioTransport::AudioCapability::hidl_discriminator::profile: {
            _hidl_err = writeEmbeddedToParcel(
                    obj.profile(),
                    parcel,
                    parentHandle,
                    parentOffset + obj.hidl_getUnionOffset() /* safe_union: union offset into struct */);

            if (_hidl_err != ::android::OK) { return _hidl_err; }

            break;
        }
        case ::android::hardware::audio::common::V7_0::AudioTransport::AudioCapability::hidl_discriminator::edid: {
            size_t _hidl_edid_child;

            _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                    obj.edid(),
                    parcel,
                    parentHandle,
                    parentOffset + obj.hidl_getUnionOffset() /* safe_union: union offset into struct */, &_hidl_edid_child);

            if (_hidl_err != ::android::OK) { return _hidl_err; }

            break;
        }
        default: { break; }
    }
    return _hidl_err;
}

::android::hardware::audio::common::V7_0::AudioTransport::AudioCapability::AudioCapability() {
    static_assert(offsetof(::android::hardware::audio::common::V7_0::AudioTransport::AudioCapability, hidl_d) == 0, "wrong offset");
    static_assert(offsetof(::android::hardware::audio::common::V7_0::AudioTransport::AudioCapability, hidl_u) == 8, "wrong offset");

    ::std::memset(&hidl_u, 0, sizeof(hidl_u));
    ::std::memset(reinterpret_cast<uint8_t*>(this) + 1, 0, 7);
    // no padding to zero starting at offset 56

    hidl_d = hidl_discriminator::profile;
    new (&hidl_u.profile) ::android::hardware::audio::common::V7_0::AudioProfile();
}

::android::hardware::audio::common::V7_0::AudioTransport::AudioCapability::~AudioCapability() {
    hidl_destructUnion();
}

::android::hardware::audio::common::V7_0::AudioTransport::AudioCapability::AudioCapability(AudioCapability&& other) : ::android::hardware::audio::common::V7_0::AudioTransport::AudioCapability() {
    *this = std::move(other);
}

::android::hardware::audio::common::V7_0::AudioTransport::AudioCapability::AudioCapability(const AudioCapability& other) : ::android::hardware::audio::common::V7_0::AudioTransport::AudioCapability() {
    *this = other;
}

::android::hardware::audio::common::V7_0::AudioTransport::AudioCapability& (::android::hardware::audio::common::V7_0::AudioTransport::AudioCapability::operator=)(AudioCapability&& other) {
    if (this == &other) { return *this; }

    switch (other.hidl_d) {
        case hidl_discriminator::profile: {
            profile(std::move(other.hidl_u.profile));
            break;
        }
        case hidl_discriminator::edid: {
            edid(std::move(other.hidl_u.edid));
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

::android::hardware::audio::common::V7_0::AudioTransport::AudioCapability& (::android::hardware::audio::common::V7_0::AudioTransport::AudioCapability::operator=)(const AudioCapability& other) {
    if (this == &other) { return *this; }

    switch (other.hidl_d) {
        case hidl_discriminator::profile: {
            profile(other.hidl_u.profile);
            break;
        }
        case hidl_discriminator::edid: {
            edid(other.hidl_u.edid);
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

void ::android::hardware::audio::common::V7_0::AudioTransport::AudioCapability::hidl_destructUnion() {
    switch (hidl_d) {
        case hidl_discriminator::profile: {
            ::android::hardware::details::destructElement(&(hidl_u.profile));
            break;
        }
        case hidl_discriminator::edid: {
            ::android::hardware::details::destructElement(&(hidl_u.edid));
            break;
        }
        default: {
            ::android::hardware::details::logAlwaysFatal((
                    "Unknown union discriminator (value: " +
                    std::to_string((uint8_t) hidl_d) + ").").c_str());
        }
    }

}

void ::android::hardware::audio::common::V7_0::AudioTransport::AudioCapability::profile(const ::android::hardware::audio::common::V7_0::AudioProfile& o) {
    if (hidl_d != hidl_discriminator::profile) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.profile) ::android::hardware::audio::common::V7_0::AudioProfile(o);
        hidl_d = hidl_discriminator::profile;
    }
    else if (&(hidl_u.profile) != &o) {
        hidl_u.profile = o;
    }
}

void ::android::hardware::audio::common::V7_0::AudioTransport::AudioCapability::profile(::android::hardware::audio::common::V7_0::AudioProfile&& o) {
    if (hidl_d != hidl_discriminator::profile) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.profile) ::android::hardware::audio::common::V7_0::AudioProfile(std::move(o));
        hidl_d = hidl_discriminator::profile;
    }
    else if (&(hidl_u.profile) != &o) {
        hidl_u.profile = std::move(o);
    }
}

::android::hardware::audio::common::V7_0::AudioProfile& (::android::hardware::audio::common::V7_0::AudioTransport::AudioCapability::profile)() {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::profile)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::profile));
    }

    return hidl_u.profile;
}

const ::android::hardware::audio::common::V7_0::AudioProfile& (::android::hardware::audio::common::V7_0::AudioTransport::AudioCapability::profile)() const {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::profile)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::profile));
    }

    return hidl_u.profile;
}

void ::android::hardware::audio::common::V7_0::AudioTransport::AudioCapability::edid(const ::android::hardware::hidl_vec<uint8_t>& o) {
    if (hidl_d != hidl_discriminator::edid) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.edid) ::android::hardware::hidl_vec<uint8_t>(o);
        hidl_d = hidl_discriminator::edid;
    }
    else if (&(hidl_u.edid) != &o) {
        hidl_u.edid = o;
    }
}

void ::android::hardware::audio::common::V7_0::AudioTransport::AudioCapability::edid(::android::hardware::hidl_vec<uint8_t>&& o) {
    if (hidl_d != hidl_discriminator::edid) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.edid) ::android::hardware::hidl_vec<uint8_t>(std::move(o));
        hidl_d = hidl_discriminator::edid;
    }
    else if (&(hidl_u.edid) != &o) {
        hidl_u.edid = std::move(o);
    }
}

::android::hardware::hidl_vec<uint8_t>& (::android::hardware::audio::common::V7_0::AudioTransport::AudioCapability::edid)() {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::edid)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::edid));
    }

    return hidl_u.edid;
}

const ::android::hardware::hidl_vec<uint8_t>& (::android::hardware::audio::common::V7_0::AudioTransport::AudioCapability::edid)() const {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::edid)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::edid));
    }

    return hidl_u.edid;
}

::android::hardware::audio::common::V7_0::AudioTransport::AudioCapability::hidl_union::hidl_union() {}

::android::hardware::audio::common::V7_0::AudioTransport::AudioCapability::hidl_union::~hidl_union() {}

::android::hardware::audio::common::V7_0::AudioTransport::AudioCapability::hidl_discriminator (::android::hardware::audio::common::V7_0::AudioTransport::AudioCapability::getDiscriminator)() const {
    return hidl_d;
}

::android::status_t readEmbeddedFromParcel(
        const AudioTransport &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::audio::common::V7_0::AudioTransport::AudioCapability &>(obj.audioCapability),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::common::V7_0::AudioTransport, audioCapability));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.encapsulationType),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::common::V7_0::AudioTransport, encapsulationType));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const AudioTransport &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = writeEmbeddedToParcel(
            obj.audioCapability,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::common::V7_0::AudioTransport, audioCapability));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.encapsulationType,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::common::V7_0::AudioTransport, encapsulationType));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const DeviceAddress::Address &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    switch (obj.getDiscriminator()) {
        case ::android::hardware::audio::common::V7_0::DeviceAddress::Address::hidl_discriminator::id: {
            _hidl_err = ::android::hardware::readEmbeddedFromParcel(
                    const_cast<::android::hardware::hidl_string &>(obj.id()),
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
        const DeviceAddress::Address &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    switch (obj.getDiscriminator()) {
        case ::android::hardware::audio::common::V7_0::DeviceAddress::Address::hidl_discriminator::id: {
            _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                    obj.id(),
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

::android::hardware::audio::common::V7_0::DeviceAddress::Address::Address() {
    static_assert(offsetof(::android::hardware::audio::common::V7_0::DeviceAddress::Address, hidl_d) == 0, "wrong offset");
    static_assert(offsetof(::android::hardware::audio::common::V7_0::DeviceAddress::Address, hidl_u) == 8, "wrong offset");

    ::std::memset(&hidl_u, 0, sizeof(hidl_u));
    ::std::memset(reinterpret_cast<uint8_t*>(this) + 1, 0, 7);
    // no padding to zero starting at offset 24

    hidl_d = hidl_discriminator::id;
    new (&hidl_u.id) ::android::hardware::hidl_string();
}

::android::hardware::audio::common::V7_0::DeviceAddress::Address::~Address() {
    hidl_destructUnion();
}

::android::hardware::audio::common::V7_0::DeviceAddress::Address::Address(Address&& other) : ::android::hardware::audio::common::V7_0::DeviceAddress::Address() {
    *this = std::move(other);
}

::android::hardware::audio::common::V7_0::DeviceAddress::Address::Address(const Address& other) : ::android::hardware::audio::common::V7_0::DeviceAddress::Address() {
    *this = other;
}

::android::hardware::audio::common::V7_0::DeviceAddress::Address& (::android::hardware::audio::common::V7_0::DeviceAddress::Address::operator=)(Address&& other) {
    if (this == &other) { return *this; }

    switch (other.hidl_d) {
        case hidl_discriminator::id: {
            id(std::move(other.hidl_u.id));
            break;
        }
        case hidl_discriminator::mac: {
            mac(std::move(other.hidl_u.mac));
            break;
        }
        case hidl_discriminator::ipv4: {
            ipv4(std::move(other.hidl_u.ipv4));
            break;
        }
        case hidl_discriminator::ipv6: {
            ipv6(std::move(other.hidl_u.ipv6));
            break;
        }
        case hidl_discriminator::alsa: {
            alsa(std::move(other.hidl_u.alsa));
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

::android::hardware::audio::common::V7_0::DeviceAddress::Address& (::android::hardware::audio::common::V7_0::DeviceAddress::Address::operator=)(const Address& other) {
    if (this == &other) { return *this; }

    switch (other.hidl_d) {
        case hidl_discriminator::id: {
            id(other.hidl_u.id);
            break;
        }
        case hidl_discriminator::mac: {
            mac(other.hidl_u.mac);
            break;
        }
        case hidl_discriminator::ipv4: {
            ipv4(other.hidl_u.ipv4);
            break;
        }
        case hidl_discriminator::ipv6: {
            ipv6(other.hidl_u.ipv6);
            break;
        }
        case hidl_discriminator::alsa: {
            alsa(other.hidl_u.alsa);
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

void ::android::hardware::audio::common::V7_0::DeviceAddress::Address::hidl_destructUnion() {
    switch (hidl_d) {
        case hidl_discriminator::id: {
            ::android::hardware::details::destructElement(&(hidl_u.id));
            break;
        }
        case hidl_discriminator::mac: {
            ::android::hardware::details::destructElement(&(hidl_u.mac));
            break;
        }
        case hidl_discriminator::ipv4: {
            ::android::hardware::details::destructElement(&(hidl_u.ipv4));
            break;
        }
        case hidl_discriminator::ipv6: {
            ::android::hardware::details::destructElement(&(hidl_u.ipv6));
            break;
        }
        case hidl_discriminator::alsa: {
            ::android::hardware::details::destructElement(&(hidl_u.alsa));
            break;
        }
        default: {
            ::android::hardware::details::logAlwaysFatal((
                    "Unknown union discriminator (value: " +
                    std::to_string((uint8_t) hidl_d) + ").").c_str());
        }
    }

}

void ::android::hardware::audio::common::V7_0::DeviceAddress::Address::id(const ::android::hardware::hidl_string& o) {
    if (hidl_d != hidl_discriminator::id) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.id) ::android::hardware::hidl_string(o);
        hidl_d = hidl_discriminator::id;
    }
    else if (&(hidl_u.id) != &o) {
        hidl_u.id = o;
    }
}

void ::android::hardware::audio::common::V7_0::DeviceAddress::Address::id(::android::hardware::hidl_string&& o) {
    if (hidl_d != hidl_discriminator::id) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.id) ::android::hardware::hidl_string(std::move(o));
        hidl_d = hidl_discriminator::id;
    }
    else if (&(hidl_u.id) != &o) {
        hidl_u.id = std::move(o);
    }
}

::android::hardware::hidl_string& (::android::hardware::audio::common::V7_0::DeviceAddress::Address::id)() {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::id)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::id));
    }

    return hidl_u.id;
}

const ::android::hardware::hidl_string& (::android::hardware::audio::common::V7_0::DeviceAddress::Address::id)() const {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::id)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::id));
    }

    return hidl_u.id;
}

void ::android::hardware::audio::common::V7_0::DeviceAddress::Address::mac(const ::android::hardware::hidl_array<uint8_t, 6>& o) {
    if (hidl_d != hidl_discriminator::mac) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.mac) ::android::hardware::hidl_array<uint8_t, 6>(o);
        hidl_d = hidl_discriminator::mac;
    }
    else if (&(hidl_u.mac) != &o) {
        hidl_u.mac = o;
    }
}

void ::android::hardware::audio::common::V7_0::DeviceAddress::Address::mac(::android::hardware::hidl_array<uint8_t, 6>&& o) {
    if (hidl_d != hidl_discriminator::mac) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.mac) ::android::hardware::hidl_array<uint8_t, 6>(std::move(o));
        hidl_d = hidl_discriminator::mac;
    }
    else if (&(hidl_u.mac) != &o) {
        hidl_u.mac = std::move(o);
    }
}

::android::hardware::hidl_array<uint8_t, 6>& (::android::hardware::audio::common::V7_0::DeviceAddress::Address::mac)() {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::mac)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::mac));
    }

    return hidl_u.mac;
}

const ::android::hardware::hidl_array<uint8_t, 6>& (::android::hardware::audio::common::V7_0::DeviceAddress::Address::mac)() const {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::mac)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::mac));
    }

    return hidl_u.mac;
}

void ::android::hardware::audio::common::V7_0::DeviceAddress::Address::ipv4(const ::android::hardware::hidl_array<uint8_t, 4>& o) {
    if (hidl_d != hidl_discriminator::ipv4) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.ipv4) ::android::hardware::hidl_array<uint8_t, 4>(o);
        hidl_d = hidl_discriminator::ipv4;
    }
    else if (&(hidl_u.ipv4) != &o) {
        hidl_u.ipv4 = o;
    }
}

void ::android::hardware::audio::common::V7_0::DeviceAddress::Address::ipv4(::android::hardware::hidl_array<uint8_t, 4>&& o) {
    if (hidl_d != hidl_discriminator::ipv4) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.ipv4) ::android::hardware::hidl_array<uint8_t, 4>(std::move(o));
        hidl_d = hidl_discriminator::ipv4;
    }
    else if (&(hidl_u.ipv4) != &o) {
        hidl_u.ipv4 = std::move(o);
    }
}

::android::hardware::hidl_array<uint8_t, 4>& (::android::hardware::audio::common::V7_0::DeviceAddress::Address::ipv4)() {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::ipv4)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::ipv4));
    }

    return hidl_u.ipv4;
}

const ::android::hardware::hidl_array<uint8_t, 4>& (::android::hardware::audio::common::V7_0::DeviceAddress::Address::ipv4)() const {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::ipv4)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::ipv4));
    }

    return hidl_u.ipv4;
}

void ::android::hardware::audio::common::V7_0::DeviceAddress::Address::ipv6(const ::android::hardware::hidl_array<uint16_t, 8>& o) {
    if (hidl_d != hidl_discriminator::ipv6) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.ipv6) ::android::hardware::hidl_array<uint16_t, 8>(o);
        hidl_d = hidl_discriminator::ipv6;
    }
    else if (&(hidl_u.ipv6) != &o) {
        hidl_u.ipv6 = o;
    }
}

void ::android::hardware::audio::common::V7_0::DeviceAddress::Address::ipv6(::android::hardware::hidl_array<uint16_t, 8>&& o) {
    if (hidl_d != hidl_discriminator::ipv6) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.ipv6) ::android::hardware::hidl_array<uint16_t, 8>(std::move(o));
        hidl_d = hidl_discriminator::ipv6;
    }
    else if (&(hidl_u.ipv6) != &o) {
        hidl_u.ipv6 = std::move(o);
    }
}

::android::hardware::hidl_array<uint16_t, 8>& (::android::hardware::audio::common::V7_0::DeviceAddress::Address::ipv6)() {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::ipv6)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::ipv6));
    }

    return hidl_u.ipv6;
}

const ::android::hardware::hidl_array<uint16_t, 8>& (::android::hardware::audio::common::V7_0::DeviceAddress::Address::ipv6)() const {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::ipv6)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::ipv6));
    }

    return hidl_u.ipv6;
}

void ::android::hardware::audio::common::V7_0::DeviceAddress::Address::alsa(const ::android::hardware::audio::common::V7_0::DeviceAddress::Address::Alsa& o) {
    if (hidl_d != hidl_discriminator::alsa) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.alsa) ::android::hardware::audio::common::V7_0::DeviceAddress::Address::Alsa(o);
        hidl_d = hidl_discriminator::alsa;
    }
    else if (&(hidl_u.alsa) != &o) {
        hidl_u.alsa = o;
    }
}

void ::android::hardware::audio::common::V7_0::DeviceAddress::Address::alsa(::android::hardware::audio::common::V7_0::DeviceAddress::Address::Alsa&& o) {
    if (hidl_d != hidl_discriminator::alsa) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.alsa) ::android::hardware::audio::common::V7_0::DeviceAddress::Address::Alsa(std::move(o));
        hidl_d = hidl_discriminator::alsa;
    }
    else if (&(hidl_u.alsa) != &o) {
        hidl_u.alsa = std::move(o);
    }
}

::android::hardware::audio::common::V7_0::DeviceAddress::Address::Alsa& (::android::hardware::audio::common::V7_0::DeviceAddress::Address::alsa)() {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::alsa)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::alsa));
    }

    return hidl_u.alsa;
}

const ::android::hardware::audio::common::V7_0::DeviceAddress::Address::Alsa& (::android::hardware::audio::common::V7_0::DeviceAddress::Address::alsa)() const {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::alsa)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::alsa));
    }

    return hidl_u.alsa;
}

::android::hardware::audio::common::V7_0::DeviceAddress::Address::hidl_union::hidl_union() {}

::android::hardware::audio::common::V7_0::DeviceAddress::Address::hidl_union::~hidl_union() {}

::android::hardware::audio::common::V7_0::DeviceAddress::Address::hidl_discriminator (::android::hardware::audio::common::V7_0::DeviceAddress::Address::getDiscriminator)() const {
    return hidl_d;
}

::android::status_t readEmbeddedFromParcel(
        const DeviceAddress &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.deviceType),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::common::V7_0::DeviceAddress, deviceType));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::audio::common::V7_0::DeviceAddress::Address &>(obj.address),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::common::V7_0::DeviceAddress, address));

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
            obj.deviceType,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::common::V7_0::DeviceAddress, deviceType));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = writeEmbeddedToParcel(
            obj.address,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::common::V7_0::DeviceAddress, address));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const AudioOffloadInfo &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::audio::common::V7_0::AudioConfigBase &>(obj.base),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::common::V7_0::AudioOffloadInfo, base));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.streamType),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::common::V7_0::AudioOffloadInfo, streamType));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.usage),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::common::V7_0::AudioOffloadInfo, usage));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const AudioOffloadInfo &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = writeEmbeddedToParcel(
            obj.base,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::common::V7_0::AudioOffloadInfo, base));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.streamType,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::common::V7_0::AudioOffloadInfo, streamType));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.usage,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::common::V7_0::AudioOffloadInfo, usage));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const AudioConfig::OffloadInfo &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    switch (obj.getDiscriminator()) {
        case ::android::hardware::audio::common::V7_0::AudioConfig::OffloadInfo::hidl_discriminator::info: {
            _hidl_err = readEmbeddedFromParcel(
                    const_cast<::android::hardware::audio::common::V7_0::AudioOffloadInfo &>(obj.info()),
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
        const AudioConfig::OffloadInfo &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    switch (obj.getDiscriminator()) {
        case ::android::hardware::audio::common::V7_0::AudioConfig::OffloadInfo::hidl_discriminator::info: {
            _hidl_err = writeEmbeddedToParcel(
                    obj.info(),
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

::android::hardware::audio::common::V7_0::AudioConfig::OffloadInfo::OffloadInfo() {
    static_assert(offsetof(::android::hardware::audio::common::V7_0::AudioConfig::OffloadInfo, hidl_d) == 0, "wrong offset");
    static_assert(offsetof(::android::hardware::audio::common::V7_0::AudioConfig::OffloadInfo, hidl_u) == 8, "wrong offset");

    ::std::memset(&hidl_u, 0, sizeof(hidl_u));
    ::std::memset(reinterpret_cast<uint8_t*>(this) + 1, 0, 7);
    // no padding to zero starting at offset 128

    hidl_d = hidl_discriminator::unspecified;
    new (&hidl_u.unspecified) ::android::hidl::safe_union::V1_0::Monostate();
}

::android::hardware::audio::common::V7_0::AudioConfig::OffloadInfo::~OffloadInfo() {
    hidl_destructUnion();
}

::android::hardware::audio::common::V7_0::AudioConfig::OffloadInfo::OffloadInfo(OffloadInfo&& other) : ::android::hardware::audio::common::V7_0::AudioConfig::OffloadInfo() {
    *this = std::move(other);
}

::android::hardware::audio::common::V7_0::AudioConfig::OffloadInfo::OffloadInfo(const OffloadInfo& other) : ::android::hardware::audio::common::V7_0::AudioConfig::OffloadInfo() {
    *this = other;
}

::android::hardware::audio::common::V7_0::AudioConfig::OffloadInfo& (::android::hardware::audio::common::V7_0::AudioConfig::OffloadInfo::operator=)(OffloadInfo&& other) {
    if (this == &other) { return *this; }

    switch (other.hidl_d) {
        case hidl_discriminator::unspecified: {
            unspecified(std::move(other.hidl_u.unspecified));
            break;
        }
        case hidl_discriminator::info: {
            info(std::move(other.hidl_u.info));
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

::android::hardware::audio::common::V7_0::AudioConfig::OffloadInfo& (::android::hardware::audio::common::V7_0::AudioConfig::OffloadInfo::operator=)(const OffloadInfo& other) {
    if (this == &other) { return *this; }

    switch (other.hidl_d) {
        case hidl_discriminator::unspecified: {
            unspecified(other.hidl_u.unspecified);
            break;
        }
        case hidl_discriminator::info: {
            info(other.hidl_u.info);
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

void ::android::hardware::audio::common::V7_0::AudioConfig::OffloadInfo::hidl_destructUnion() {
    switch (hidl_d) {
        case hidl_discriminator::unspecified: {
            ::android::hardware::details::destructElement(&(hidl_u.unspecified));
            break;
        }
        case hidl_discriminator::info: {
            ::android::hardware::details::destructElement(&(hidl_u.info));
            break;
        }
        default: {
            ::android::hardware::details::logAlwaysFatal((
                    "Unknown union discriminator (value: " +
                    std::to_string((uint8_t) hidl_d) + ").").c_str());
        }
    }

}

void ::android::hardware::audio::common::V7_0::AudioConfig::OffloadInfo::unspecified(const ::android::hidl::safe_union::V1_0::Monostate& o) {
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

void ::android::hardware::audio::common::V7_0::AudioConfig::OffloadInfo::unspecified(::android::hidl::safe_union::V1_0::Monostate&& o) {
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

::android::hidl::safe_union::V1_0::Monostate& (::android::hardware::audio::common::V7_0::AudioConfig::OffloadInfo::unspecified)() {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::unspecified)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::unspecified));
    }

    return hidl_u.unspecified;
}

const ::android::hidl::safe_union::V1_0::Monostate& (::android::hardware::audio::common::V7_0::AudioConfig::OffloadInfo::unspecified)() const {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::unspecified)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::unspecified));
    }

    return hidl_u.unspecified;
}

void ::android::hardware::audio::common::V7_0::AudioConfig::OffloadInfo::info(const ::android::hardware::audio::common::V7_0::AudioOffloadInfo& o) {
    if (hidl_d != hidl_discriminator::info) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.info) ::android::hardware::audio::common::V7_0::AudioOffloadInfo(o);
        hidl_d = hidl_discriminator::info;
    }
    else if (&(hidl_u.info) != &o) {
        hidl_u.info = o;
    }
}

void ::android::hardware::audio::common::V7_0::AudioConfig::OffloadInfo::info(::android::hardware::audio::common::V7_0::AudioOffloadInfo&& o) {
    if (hidl_d != hidl_discriminator::info) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.info) ::android::hardware::audio::common::V7_0::AudioOffloadInfo(std::move(o));
        hidl_d = hidl_discriminator::info;
    }
    else if (&(hidl_u.info) != &o) {
        hidl_u.info = std::move(o);
    }
}

::android::hardware::audio::common::V7_0::AudioOffloadInfo& (::android::hardware::audio::common::V7_0::AudioConfig::OffloadInfo::info)() {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::info)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::info));
    }

    return hidl_u.info;
}

const ::android::hardware::audio::common::V7_0::AudioOffloadInfo& (::android::hardware::audio::common::V7_0::AudioConfig::OffloadInfo::info)() const {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::info)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::info));
    }

    return hidl_u.info;
}

::android::hardware::audio::common::V7_0::AudioConfig::OffloadInfo::hidl_union::hidl_union() {}

::android::hardware::audio::common::V7_0::AudioConfig::OffloadInfo::hidl_union::~hidl_union() {}

::android::hardware::audio::common::V7_0::AudioConfig::OffloadInfo::hidl_discriminator (::android::hardware::audio::common::V7_0::AudioConfig::OffloadInfo::getDiscriminator)() const {
    return hidl_d;
}

::android::status_t readEmbeddedFromParcel(
        const AudioConfig &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::audio::common::V7_0::AudioConfigBase &>(obj.base),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::common::V7_0::AudioConfig, base));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::audio::common::V7_0::AudioConfig::OffloadInfo &>(obj.offloadInfo),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::common::V7_0::AudioConfig, offloadInfo));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const AudioConfig &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = writeEmbeddedToParcel(
            obj.base,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::common::V7_0::AudioConfig, base));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = writeEmbeddedToParcel(
            obj.offloadInfo,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::common::V7_0::AudioConfig, offloadInfo));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const PlaybackTrackMetadata &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.usage),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::common::V7_0::PlaybackTrackMetadata, usage));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.contentType),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::common::V7_0::PlaybackTrackMetadata, contentType));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.channelMask),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::common::V7_0::PlaybackTrackMetadata, channelMask));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_tags_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::hidl_string> &>(obj.tags),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::common::V7_0::PlaybackTrackMetadata, tags), &_hidl_tags_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.tags.size(); ++_hidl_index_0) {
        _hidl_err = ::android::hardware::readEmbeddedFromParcel(
                const_cast<::android::hardware::hidl_string &>(obj.tags[_hidl_index_0]),
                parcel,
                _hidl_tags_child,
                _hidl_index_0 * sizeof(::android::hardware::hidl_string));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const PlaybackTrackMetadata &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.usage,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::common::V7_0::PlaybackTrackMetadata, usage));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.contentType,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::common::V7_0::PlaybackTrackMetadata, contentType));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.channelMask,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::common::V7_0::PlaybackTrackMetadata, channelMask));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_tags_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.tags,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::common::V7_0::PlaybackTrackMetadata, tags), &_hidl_tags_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.tags.size(); ++_hidl_index_0) {
        _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                obj.tags[_hidl_index_0],
                parcel,
                _hidl_tags_child,
                _hidl_index_0 * sizeof(::android::hardware::hidl_string));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

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
            const_cast<::android::hardware::hidl_vec<::android::hardware::audio::common::V7_0::PlaybackTrackMetadata> &>(obj.tracks),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::common::V7_0::SourceMetadata, tracks), &_hidl_tracks_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.tracks.size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::audio::common::V7_0::PlaybackTrackMetadata &>(obj.tracks[_hidl_index_0]),
                parcel,
                _hidl_tracks_child,
                _hidl_index_0 * sizeof(::android::hardware::audio::common::V7_0::PlaybackTrackMetadata));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

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
            parentOffset + offsetof(::android::hardware::audio::common::V7_0::SourceMetadata, tracks), &_hidl_tracks_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.tracks.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                obj.tracks[_hidl_index_0],
                parcel,
                _hidl_tracks_child,
                _hidl_index_0 * sizeof(::android::hardware::audio::common::V7_0::PlaybackTrackMetadata));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const RecordTrackMetadata::Destination &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    switch (obj.getDiscriminator()) {
        case ::android::hardware::audio::common::V7_0::RecordTrackMetadata::Destination::hidl_discriminator::device: {
            _hidl_err = readEmbeddedFromParcel(
                    const_cast<::android::hardware::audio::common::V7_0::DeviceAddress &>(obj.device()),
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
        case ::android::hardware::audio::common::V7_0::RecordTrackMetadata::Destination::hidl_discriminator::device: {
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

::android::hardware::audio::common::V7_0::RecordTrackMetadata::Destination::Destination() {
    static_assert(offsetof(::android::hardware::audio::common::V7_0::RecordTrackMetadata::Destination, hidl_d) == 0, "wrong offset");
    static_assert(offsetof(::android::hardware::audio::common::V7_0::RecordTrackMetadata::Destination, hidl_u) == 8, "wrong offset");

    ::std::memset(&hidl_u, 0, sizeof(hidl_u));
    ::std::memset(reinterpret_cast<uint8_t*>(this) + 1, 0, 7);
    // no padding to zero starting at offset 48

    hidl_d = hidl_discriminator::unspecified;
    new (&hidl_u.unspecified) ::android::hidl::safe_union::V1_0::Monostate();
}

::android::hardware::audio::common::V7_0::RecordTrackMetadata::Destination::~Destination() {
    hidl_destructUnion();
}

::android::hardware::audio::common::V7_0::RecordTrackMetadata::Destination::Destination(Destination&& other) : ::android::hardware::audio::common::V7_0::RecordTrackMetadata::Destination() {
    *this = std::move(other);
}

::android::hardware::audio::common::V7_0::RecordTrackMetadata::Destination::Destination(const Destination& other) : ::android::hardware::audio::common::V7_0::RecordTrackMetadata::Destination() {
    *this = other;
}

::android::hardware::audio::common::V7_0::RecordTrackMetadata::Destination& (::android::hardware::audio::common::V7_0::RecordTrackMetadata::Destination::operator=)(Destination&& other) {
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

::android::hardware::audio::common::V7_0::RecordTrackMetadata::Destination& (::android::hardware::audio::common::V7_0::RecordTrackMetadata::Destination::operator=)(const Destination& other) {
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

void ::android::hardware::audio::common::V7_0::RecordTrackMetadata::Destination::hidl_destructUnion() {
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

void ::android::hardware::audio::common::V7_0::RecordTrackMetadata::Destination::unspecified(const ::android::hidl::safe_union::V1_0::Monostate& o) {
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

void ::android::hardware::audio::common::V7_0::RecordTrackMetadata::Destination::unspecified(::android::hidl::safe_union::V1_0::Monostate&& o) {
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

::android::hidl::safe_union::V1_0::Monostate& (::android::hardware::audio::common::V7_0::RecordTrackMetadata::Destination::unspecified)() {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::unspecified)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::unspecified));
    }

    return hidl_u.unspecified;
}

const ::android::hidl::safe_union::V1_0::Monostate& (::android::hardware::audio::common::V7_0::RecordTrackMetadata::Destination::unspecified)() const {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::unspecified)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::unspecified));
    }

    return hidl_u.unspecified;
}

void ::android::hardware::audio::common::V7_0::RecordTrackMetadata::Destination::device(const ::android::hardware::audio::common::V7_0::DeviceAddress& o) {
    if (hidl_d != hidl_discriminator::device) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.device) ::android::hardware::audio::common::V7_0::DeviceAddress(o);
        hidl_d = hidl_discriminator::device;
    }
    else if (&(hidl_u.device) != &o) {
        hidl_u.device = o;
    }
}

void ::android::hardware::audio::common::V7_0::RecordTrackMetadata::Destination::device(::android::hardware::audio::common::V7_0::DeviceAddress&& o) {
    if (hidl_d != hidl_discriminator::device) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.device) ::android::hardware::audio::common::V7_0::DeviceAddress(std::move(o));
        hidl_d = hidl_discriminator::device;
    }
    else if (&(hidl_u.device) != &o) {
        hidl_u.device = std::move(o);
    }
}

::android::hardware::audio::common::V7_0::DeviceAddress& (::android::hardware::audio::common::V7_0::RecordTrackMetadata::Destination::device)() {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::device)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::device));
    }

    return hidl_u.device;
}

const ::android::hardware::audio::common::V7_0::DeviceAddress& (::android::hardware::audio::common::V7_0::RecordTrackMetadata::Destination::device)() const {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::device)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::device));
    }

    return hidl_u.device;
}

::android::hardware::audio::common::V7_0::RecordTrackMetadata::Destination::hidl_union::hidl_union() {}

::android::hardware::audio::common::V7_0::RecordTrackMetadata::Destination::hidl_union::~hidl_union() {}

::android::hardware::audio::common::V7_0::RecordTrackMetadata::Destination::hidl_discriminator (::android::hardware::audio::common::V7_0::RecordTrackMetadata::Destination::getDiscriminator)() const {
    return hidl_d;
}

::android::status_t readEmbeddedFromParcel(
        const RecordTrackMetadata &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.source),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::common::V7_0::RecordTrackMetadata, source));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::audio::common::V7_0::RecordTrackMetadata::Destination &>(obj.destination),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::common::V7_0::RecordTrackMetadata, destination));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.channelMask),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::common::V7_0::RecordTrackMetadata, channelMask));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_tags_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::hidl_string> &>(obj.tags),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::common::V7_0::RecordTrackMetadata, tags), &_hidl_tags_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.tags.size(); ++_hidl_index_0) {
        _hidl_err = ::android::hardware::readEmbeddedFromParcel(
                const_cast<::android::hardware::hidl_string &>(obj.tags[_hidl_index_0]),
                parcel,
                _hidl_tags_child,
                _hidl_index_0 * sizeof(::android::hardware::hidl_string));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const RecordTrackMetadata &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.source,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::common::V7_0::RecordTrackMetadata, source));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = writeEmbeddedToParcel(
            obj.destination,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::common::V7_0::RecordTrackMetadata, destination));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.channelMask,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::common::V7_0::RecordTrackMetadata, channelMask));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_tags_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.tags,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::common::V7_0::RecordTrackMetadata, tags), &_hidl_tags_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.tags.size(); ++_hidl_index_0) {
        _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                obj.tags[_hidl_index_0],
                parcel,
                _hidl_tags_child,
                _hidl_index_0 * sizeof(::android::hardware::hidl_string));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

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
            const_cast<::android::hardware::hidl_vec<::android::hardware::audio::common::V7_0::RecordTrackMetadata> &>(obj.tracks),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::common::V7_0::SinkMetadata, tracks), &_hidl_tracks_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.tracks.size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::audio::common::V7_0::RecordTrackMetadata &>(obj.tracks[_hidl_index_0]),
                parcel,
                _hidl_tracks_child,
                _hidl_index_0 * sizeof(::android::hardware::audio::common::V7_0::RecordTrackMetadata));

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
            parentOffset + offsetof(::android::hardware::audio::common::V7_0::SinkMetadata, tracks), &_hidl_tracks_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.tracks.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                obj.tracks[_hidl_index_0],
                parcel,
                _hidl_tracks_child,
                _hidl_index_0 * sizeof(::android::hardware::audio::common::V7_0::RecordTrackMetadata));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const AudioGain &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_mode_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::hidl_string> &>(obj.mode),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::common::V7_0::AudioGain, mode), &_hidl_mode_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.mode.size(); ++_hidl_index_0) {
        _hidl_err = ::android::hardware::readEmbeddedFromParcel(
                const_cast<::android::hardware::hidl_string &>(obj.mode[_hidl_index_0]),
                parcel,
                _hidl_mode_child,
                _hidl_index_0 * sizeof(::android::hardware::hidl_string));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.channelMask),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::common::V7_0::AudioGain, channelMask));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const AudioGain &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_mode_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.mode,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::common::V7_0::AudioGain, mode), &_hidl_mode_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.mode.size(); ++_hidl_index_0) {
        _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                obj.mode[_hidl_index_0],
                parcel,
                _hidl_mode_child,
                _hidl_index_0 * sizeof(::android::hardware::hidl_string));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.channelMask,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::common::V7_0::AudioGain, channelMask));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const AudioGainConfig &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_mode_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::hidl_string> &>(obj.mode),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::common::V7_0::AudioGainConfig, mode), &_hidl_mode_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.mode.size(); ++_hidl_index_0) {
        _hidl_err = ::android::hardware::readEmbeddedFromParcel(
                const_cast<::android::hardware::hidl_string &>(obj.mode[_hidl_index_0]),
                parcel,
                _hidl_mode_child,
                _hidl_index_0 * sizeof(::android::hardware::hidl_string));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.channelMask),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::common::V7_0::AudioGainConfig, channelMask));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_values_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<int32_t> &>(obj.values),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::common::V7_0::AudioGainConfig, values), &_hidl_values_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const AudioGainConfig &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_mode_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.mode,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::common::V7_0::AudioGainConfig, mode), &_hidl_mode_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.mode.size(); ++_hidl_index_0) {
        _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                obj.mode[_hidl_index_0],
                parcel,
                _hidl_mode_child,
                _hidl_index_0 * sizeof(::android::hardware::hidl_string));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.channelMask,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::common::V7_0::AudioGainConfig, channelMask));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_values_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.values,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::common::V7_0::AudioGainConfig, values), &_hidl_values_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const AudioPortExtendedInfo::AudioPortMixExt::UseCase &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    switch (obj.getDiscriminator()) {
        case ::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::AudioPortMixExt::UseCase::hidl_discriminator::stream: {
            _hidl_err = ::android::hardware::readEmbeddedFromParcel(
                    const_cast<::android::hardware::hidl_string &>(obj.stream()),
                    parcel,
                    parentHandle,
                    parentOffset + obj.hidl_getUnionOffset() /* safe_union: union offset into struct */);

            if (_hidl_err != ::android::OK) { return _hidl_err; }

            break;
        }
        case ::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::AudioPortMixExt::UseCase::hidl_discriminator::source: {
            _hidl_err = ::android::hardware::readEmbeddedFromParcel(
                    const_cast<::android::hardware::hidl_string &>(obj.source()),
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
        const AudioPortExtendedInfo::AudioPortMixExt::UseCase &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    switch (obj.getDiscriminator()) {
        case ::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::AudioPortMixExt::UseCase::hidl_discriminator::stream: {
            _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                    obj.stream(),
                    parcel,
                    parentHandle,
                    parentOffset + obj.hidl_getUnionOffset() /* safe_union: union offset into struct */);

            if (_hidl_err != ::android::OK) { return _hidl_err; }

            break;
        }
        case ::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::AudioPortMixExt::UseCase::hidl_discriminator::source: {
            _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                    obj.source(),
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

::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::AudioPortMixExt::UseCase::UseCase() {
    static_assert(offsetof(::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::AudioPortMixExt::UseCase, hidl_d) == 0, "wrong offset");
    static_assert(offsetof(::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::AudioPortMixExt::UseCase, hidl_u) == 8, "wrong offset");

    ::std::memset(&hidl_u, 0, sizeof(hidl_u));
    ::std::memset(reinterpret_cast<uint8_t*>(this) + 1, 0, 7);
    // no padding to zero starting at offset 24

    hidl_d = hidl_discriminator::stream;
    new (&hidl_u.stream) ::android::hardware::hidl_string();
}

::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::AudioPortMixExt::UseCase::~UseCase() {
    hidl_destructUnion();
}

::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::AudioPortMixExt::UseCase::UseCase(UseCase&& other) : ::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::AudioPortMixExt::UseCase() {
    *this = std::move(other);
}

::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::AudioPortMixExt::UseCase::UseCase(const UseCase& other) : ::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::AudioPortMixExt::UseCase() {
    *this = other;
}

::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::AudioPortMixExt::UseCase& (::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::AudioPortMixExt::UseCase::operator=)(UseCase&& other) {
    if (this == &other) { return *this; }

    switch (other.hidl_d) {
        case hidl_discriminator::stream: {
            stream(std::move(other.hidl_u.stream));
            break;
        }
        case hidl_discriminator::source: {
            source(std::move(other.hidl_u.source));
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

::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::AudioPortMixExt::UseCase& (::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::AudioPortMixExt::UseCase::operator=)(const UseCase& other) {
    if (this == &other) { return *this; }

    switch (other.hidl_d) {
        case hidl_discriminator::stream: {
            stream(other.hidl_u.stream);
            break;
        }
        case hidl_discriminator::source: {
            source(other.hidl_u.source);
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

void ::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::AudioPortMixExt::UseCase::hidl_destructUnion() {
    switch (hidl_d) {
        case hidl_discriminator::stream: {
            ::android::hardware::details::destructElement(&(hidl_u.stream));
            break;
        }
        case hidl_discriminator::source: {
            ::android::hardware::details::destructElement(&(hidl_u.source));
            break;
        }
        default: {
            ::android::hardware::details::logAlwaysFatal((
                    "Unknown union discriminator (value: " +
                    std::to_string((uint8_t) hidl_d) + ").").c_str());
        }
    }

}

void ::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::AudioPortMixExt::UseCase::stream(const ::android::hardware::hidl_string& o) {
    if (hidl_d != hidl_discriminator::stream) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.stream) ::android::hardware::hidl_string(o);
        hidl_d = hidl_discriminator::stream;
    }
    else if (&(hidl_u.stream) != &o) {
        hidl_u.stream = o;
    }
}

void ::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::AudioPortMixExt::UseCase::stream(::android::hardware::hidl_string&& o) {
    if (hidl_d != hidl_discriminator::stream) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.stream) ::android::hardware::hidl_string(std::move(o));
        hidl_d = hidl_discriminator::stream;
    }
    else if (&(hidl_u.stream) != &o) {
        hidl_u.stream = std::move(o);
    }
}

::android::hardware::hidl_string& (::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::AudioPortMixExt::UseCase::stream)() {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::stream)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::stream));
    }

    return hidl_u.stream;
}

const ::android::hardware::hidl_string& (::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::AudioPortMixExt::UseCase::stream)() const {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::stream)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::stream));
    }

    return hidl_u.stream;
}

void ::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::AudioPortMixExt::UseCase::source(const ::android::hardware::hidl_string& o) {
    if (hidl_d != hidl_discriminator::source) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.source) ::android::hardware::hidl_string(o);
        hidl_d = hidl_discriminator::source;
    }
    else if (&(hidl_u.source) != &o) {
        hidl_u.source = o;
    }
}

void ::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::AudioPortMixExt::UseCase::source(::android::hardware::hidl_string&& o) {
    if (hidl_d != hidl_discriminator::source) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.source) ::android::hardware::hidl_string(std::move(o));
        hidl_d = hidl_discriminator::source;
    }
    else if (&(hidl_u.source) != &o) {
        hidl_u.source = std::move(o);
    }
}

::android::hardware::hidl_string& (::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::AudioPortMixExt::UseCase::source)() {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::source)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::source));
    }

    return hidl_u.source;
}

const ::android::hardware::hidl_string& (::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::AudioPortMixExt::UseCase::source)() const {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::source)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::source));
    }

    return hidl_u.source;
}

::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::AudioPortMixExt::UseCase::hidl_union::hidl_union() {}

::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::AudioPortMixExt::UseCase::hidl_union::~hidl_union() {}

::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::AudioPortMixExt::UseCase::hidl_discriminator (::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::AudioPortMixExt::UseCase::getDiscriminator)() const {
    return hidl_d;
}

::android::status_t readEmbeddedFromParcel(
        const AudioPortExtendedInfo::AudioPortMixExt &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::AudioPortMixExt::UseCase &>(obj.useCase),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::AudioPortMixExt, useCase));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const AudioPortExtendedInfo::AudioPortMixExt &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = writeEmbeddedToParcel(
            obj.useCase,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::AudioPortMixExt, useCase));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const AudioPortExtendedInfo &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    switch (obj.getDiscriminator()) {
        case ::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::hidl_discriminator::device: {
            _hidl_err = readEmbeddedFromParcel(
                    const_cast<::android::hardware::audio::common::V7_0::DeviceAddress &>(obj.device()),
                    parcel,
                    parentHandle,
                    parentOffset + obj.hidl_getUnionOffset() /* safe_union: union offset into struct */);

            if (_hidl_err != ::android::OK) { return _hidl_err; }

            break;
        }
        case ::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::hidl_discriminator::mix: {
            _hidl_err = readEmbeddedFromParcel(
                    const_cast<::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::AudioPortMixExt &>(obj.mix()),
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
        const AudioPortExtendedInfo &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    switch (obj.getDiscriminator()) {
        case ::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::hidl_discriminator::device: {
            _hidl_err = writeEmbeddedToParcel(
                    obj.device(),
                    parcel,
                    parentHandle,
                    parentOffset + obj.hidl_getUnionOffset() /* safe_union: union offset into struct */);

            if (_hidl_err != ::android::OK) { return _hidl_err; }

            break;
        }
        case ::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::hidl_discriminator::mix: {
            _hidl_err = writeEmbeddedToParcel(
                    obj.mix(),
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

::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::AudioPortExtendedInfo() {
    static_assert(offsetof(::android::hardware::audio::common::V7_0::AudioPortExtendedInfo, hidl_d) == 0, "wrong offset");
    static_assert(offsetof(::android::hardware::audio::common::V7_0::AudioPortExtendedInfo, hidl_u) == 8, "wrong offset");

    ::std::memset(&hidl_u, 0, sizeof(hidl_u));
    ::std::memset(reinterpret_cast<uint8_t*>(this) + 1, 0, 7);
    // no padding to zero starting at offset 48

    hidl_d = hidl_discriminator::unspecified;
    new (&hidl_u.unspecified) ::android::hidl::safe_union::V1_0::Monostate();
}

::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::~AudioPortExtendedInfo() {
    hidl_destructUnion();
}

::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::AudioPortExtendedInfo(AudioPortExtendedInfo&& other) : ::android::hardware::audio::common::V7_0::AudioPortExtendedInfo() {
    *this = std::move(other);
}

::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::AudioPortExtendedInfo(const AudioPortExtendedInfo& other) : ::android::hardware::audio::common::V7_0::AudioPortExtendedInfo() {
    *this = other;
}

::android::hardware::audio::common::V7_0::AudioPortExtendedInfo& (::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::operator=)(AudioPortExtendedInfo&& other) {
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
        case hidl_discriminator::mix: {
            mix(std::move(other.hidl_u.mix));
            break;
        }
        case hidl_discriminator::session: {
            session(std::move(other.hidl_u.session));
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

::android::hardware::audio::common::V7_0::AudioPortExtendedInfo& (::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::operator=)(const AudioPortExtendedInfo& other) {
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
        case hidl_discriminator::mix: {
            mix(other.hidl_u.mix);
            break;
        }
        case hidl_discriminator::session: {
            session(other.hidl_u.session);
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

void ::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::hidl_destructUnion() {
    switch (hidl_d) {
        case hidl_discriminator::unspecified: {
            ::android::hardware::details::destructElement(&(hidl_u.unspecified));
            break;
        }
        case hidl_discriminator::device: {
            ::android::hardware::details::destructElement(&(hidl_u.device));
            break;
        }
        case hidl_discriminator::mix: {
            ::android::hardware::details::destructElement(&(hidl_u.mix));
            break;
        }
        case hidl_discriminator::session: {
            ::android::hardware::details::destructElement(&(hidl_u.session));
            break;
        }
        default: {
            ::android::hardware::details::logAlwaysFatal((
                    "Unknown union discriminator (value: " +
                    std::to_string((uint8_t) hidl_d) + ").").c_str());
        }
    }

}

void ::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::unspecified(const ::android::hidl::safe_union::V1_0::Monostate& o) {
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

void ::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::unspecified(::android::hidl::safe_union::V1_0::Monostate&& o) {
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

::android::hidl::safe_union::V1_0::Monostate& (::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::unspecified)() {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::unspecified)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::unspecified));
    }

    return hidl_u.unspecified;
}

const ::android::hidl::safe_union::V1_0::Monostate& (::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::unspecified)() const {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::unspecified)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::unspecified));
    }

    return hidl_u.unspecified;
}

void ::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::device(const ::android::hardware::audio::common::V7_0::DeviceAddress& o) {
    if (hidl_d != hidl_discriminator::device) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.device) ::android::hardware::audio::common::V7_0::DeviceAddress(o);
        hidl_d = hidl_discriminator::device;
    }
    else if (&(hidl_u.device) != &o) {
        hidl_u.device = o;
    }
}

void ::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::device(::android::hardware::audio::common::V7_0::DeviceAddress&& o) {
    if (hidl_d != hidl_discriminator::device) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.device) ::android::hardware::audio::common::V7_0::DeviceAddress(std::move(o));
        hidl_d = hidl_discriminator::device;
    }
    else if (&(hidl_u.device) != &o) {
        hidl_u.device = std::move(o);
    }
}

::android::hardware::audio::common::V7_0::DeviceAddress& (::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::device)() {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::device)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::device));
    }

    return hidl_u.device;
}

const ::android::hardware::audio::common::V7_0::DeviceAddress& (::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::device)() const {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::device)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::device));
    }

    return hidl_u.device;
}

void ::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::mix(const ::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::AudioPortMixExt& o) {
    if (hidl_d != hidl_discriminator::mix) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.mix) ::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::AudioPortMixExt(o);
        hidl_d = hidl_discriminator::mix;
    }
    else if (&(hidl_u.mix) != &o) {
        hidl_u.mix = o;
    }
}

void ::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::mix(::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::AudioPortMixExt&& o) {
    if (hidl_d != hidl_discriminator::mix) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.mix) ::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::AudioPortMixExt(std::move(o));
        hidl_d = hidl_discriminator::mix;
    }
    else if (&(hidl_u.mix) != &o) {
        hidl_u.mix = std::move(o);
    }
}

::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::AudioPortMixExt& (::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::mix)() {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::mix)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::mix));
    }

    return hidl_u.mix;
}

const ::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::AudioPortMixExt& (::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::mix)() const {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::mix)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::mix));
    }

    return hidl_u.mix;
}

void ::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::session(int32_t o) {
    if (hidl_d != hidl_discriminator::session) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.session) int32_t(o);
        hidl_d = hidl_discriminator::session;
    }
    else if (&(hidl_u.session) != &o) {
        hidl_u.session = o;
    }
}

int32_t& (::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::session)() {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::session)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::session));
    }

    return hidl_u.session;
}

int32_t (::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::session)() const {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::session)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::session));
    }

    return hidl_u.session;
}

::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::hidl_union::hidl_union() {}

::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::hidl_union::~hidl_union() {}

::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::hidl_discriminator (::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::getDiscriminator)() const {
    return hidl_d;
}

::android::status_t readEmbeddedFromParcel(
        const AudioPortConfig::OptionalGain &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    switch (obj.getDiscriminator()) {
        case ::android::hardware::audio::common::V7_0::AudioPortConfig::OptionalGain::hidl_discriminator::config: {
            _hidl_err = readEmbeddedFromParcel(
                    const_cast<::android::hardware::audio::common::V7_0::AudioGainConfig &>(obj.config()),
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
        const AudioPortConfig::OptionalGain &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    switch (obj.getDiscriminator()) {
        case ::android::hardware::audio::common::V7_0::AudioPortConfig::OptionalGain::hidl_discriminator::config: {
            _hidl_err = writeEmbeddedToParcel(
                    obj.config(),
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

::android::hardware::audio::common::V7_0::AudioPortConfig::OptionalGain::OptionalGain() {
    static_assert(offsetof(::android::hardware::audio::common::V7_0::AudioPortConfig::OptionalGain, hidl_d) == 0, "wrong offset");
    static_assert(offsetof(::android::hardware::audio::common::V7_0::AudioPortConfig::OptionalGain, hidl_u) == 8, "wrong offset");

    ::std::memset(&hidl_u, 0, sizeof(hidl_u));
    ::std::memset(reinterpret_cast<uint8_t*>(this) + 1, 0, 7);
    // no padding to zero starting at offset 72

    hidl_d = hidl_discriminator::unspecified;
    new (&hidl_u.unspecified) ::android::hidl::safe_union::V1_0::Monostate();
}

::android::hardware::audio::common::V7_0::AudioPortConfig::OptionalGain::~OptionalGain() {
    hidl_destructUnion();
}

::android::hardware::audio::common::V7_0::AudioPortConfig::OptionalGain::OptionalGain(OptionalGain&& other) : ::android::hardware::audio::common::V7_0::AudioPortConfig::OptionalGain() {
    *this = std::move(other);
}

::android::hardware::audio::common::V7_0::AudioPortConfig::OptionalGain::OptionalGain(const OptionalGain& other) : ::android::hardware::audio::common::V7_0::AudioPortConfig::OptionalGain() {
    *this = other;
}

::android::hardware::audio::common::V7_0::AudioPortConfig::OptionalGain& (::android::hardware::audio::common::V7_0::AudioPortConfig::OptionalGain::operator=)(OptionalGain&& other) {
    if (this == &other) { return *this; }

    switch (other.hidl_d) {
        case hidl_discriminator::unspecified: {
            unspecified(std::move(other.hidl_u.unspecified));
            break;
        }
        case hidl_discriminator::config: {
            config(std::move(other.hidl_u.config));
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

::android::hardware::audio::common::V7_0::AudioPortConfig::OptionalGain& (::android::hardware::audio::common::V7_0::AudioPortConfig::OptionalGain::operator=)(const OptionalGain& other) {
    if (this == &other) { return *this; }

    switch (other.hidl_d) {
        case hidl_discriminator::unspecified: {
            unspecified(other.hidl_u.unspecified);
            break;
        }
        case hidl_discriminator::config: {
            config(other.hidl_u.config);
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

void ::android::hardware::audio::common::V7_0::AudioPortConfig::OptionalGain::hidl_destructUnion() {
    switch (hidl_d) {
        case hidl_discriminator::unspecified: {
            ::android::hardware::details::destructElement(&(hidl_u.unspecified));
            break;
        }
        case hidl_discriminator::config: {
            ::android::hardware::details::destructElement(&(hidl_u.config));
            break;
        }
        default: {
            ::android::hardware::details::logAlwaysFatal((
                    "Unknown union discriminator (value: " +
                    std::to_string((uint8_t) hidl_d) + ").").c_str());
        }
    }

}

void ::android::hardware::audio::common::V7_0::AudioPortConfig::OptionalGain::unspecified(const ::android::hidl::safe_union::V1_0::Monostate& o) {
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

void ::android::hardware::audio::common::V7_0::AudioPortConfig::OptionalGain::unspecified(::android::hidl::safe_union::V1_0::Monostate&& o) {
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

::android::hidl::safe_union::V1_0::Monostate& (::android::hardware::audio::common::V7_0::AudioPortConfig::OptionalGain::unspecified)() {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::unspecified)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::unspecified));
    }

    return hidl_u.unspecified;
}

const ::android::hidl::safe_union::V1_0::Monostate& (::android::hardware::audio::common::V7_0::AudioPortConfig::OptionalGain::unspecified)() const {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::unspecified)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::unspecified));
    }

    return hidl_u.unspecified;
}

void ::android::hardware::audio::common::V7_0::AudioPortConfig::OptionalGain::config(const ::android::hardware::audio::common::V7_0::AudioGainConfig& o) {
    if (hidl_d != hidl_discriminator::config) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.config) ::android::hardware::audio::common::V7_0::AudioGainConfig(o);
        hidl_d = hidl_discriminator::config;
    }
    else if (&(hidl_u.config) != &o) {
        hidl_u.config = o;
    }
}

void ::android::hardware::audio::common::V7_0::AudioPortConfig::OptionalGain::config(::android::hardware::audio::common::V7_0::AudioGainConfig&& o) {
    if (hidl_d != hidl_discriminator::config) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.config) ::android::hardware::audio::common::V7_0::AudioGainConfig(std::move(o));
        hidl_d = hidl_discriminator::config;
    }
    else if (&(hidl_u.config) != &o) {
        hidl_u.config = std::move(o);
    }
}

::android::hardware::audio::common::V7_0::AudioGainConfig& (::android::hardware::audio::common::V7_0::AudioPortConfig::OptionalGain::config)() {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::config)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::config));
    }

    return hidl_u.config;
}

const ::android::hardware::audio::common::V7_0::AudioGainConfig& (::android::hardware::audio::common::V7_0::AudioPortConfig::OptionalGain::config)() const {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::config)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::config));
    }

    return hidl_u.config;
}

::android::hardware::audio::common::V7_0::AudioPortConfig::OptionalGain::hidl_union::hidl_union() {}

::android::hardware::audio::common::V7_0::AudioPortConfig::OptionalGain::hidl_union::~hidl_union() {}

::android::hardware::audio::common::V7_0::AudioPortConfig::OptionalGain::hidl_discriminator (::android::hardware::audio::common::V7_0::AudioPortConfig::OptionalGain::getDiscriminator)() const {
    return hidl_d;
}

::android::status_t readEmbeddedFromParcel(
        const AudioPortConfig &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::audio::common::V7_0::AudioConfigBaseOptional &>(obj.base),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::common::V7_0::AudioPortConfig, base));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::audio::common::V7_0::AudioPortConfig::OptionalGain &>(obj.gain),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::common::V7_0::AudioPortConfig, gain));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::audio::common::V7_0::AudioPortExtendedInfo &>(obj.ext),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::common::V7_0::AudioPortConfig, ext));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const AudioPortConfig &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = writeEmbeddedToParcel(
            obj.base,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::common::V7_0::AudioPortConfig, base));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = writeEmbeddedToParcel(
            obj.gain,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::common::V7_0::AudioPortConfig, gain));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = writeEmbeddedToParcel(
            obj.ext,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::common::V7_0::AudioPortConfig, ext));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

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
            parentOffset + offsetof(::android::hardware::audio::common::V7_0::AudioPort, name));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_transports_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::audio::common::V7_0::AudioTransport> &>(obj.transports),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::common::V7_0::AudioPort, transports), &_hidl_transports_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.transports.size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::audio::common::V7_0::AudioTransport &>(obj.transports[_hidl_index_0]),
                parcel,
                _hidl_transports_child,
                _hidl_index_0 * sizeof(::android::hardware::audio::common::V7_0::AudioTransport));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    size_t _hidl_gains_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::audio::common::V7_0::AudioGain> &>(obj.gains),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::common::V7_0::AudioPort, gains), &_hidl_gains_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.gains.size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::audio::common::V7_0::AudioGain &>(obj.gains[_hidl_index_0]),
                parcel,
                _hidl_gains_child,
                _hidl_index_0 * sizeof(::android::hardware::audio::common::V7_0::AudioGain));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::audio::common::V7_0::AudioPortExtendedInfo &>(obj.ext),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::common::V7_0::AudioPort, ext));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::audio::common::V7_0::AudioPortConfig &>(obj.activeConfig),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::common::V7_0::AudioPort, activeConfig));

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
            parentOffset + offsetof(::android::hardware::audio::common::V7_0::AudioPort, name));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_transports_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.transports,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::common::V7_0::AudioPort, transports), &_hidl_transports_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.transports.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                obj.transports[_hidl_index_0],
                parcel,
                _hidl_transports_child,
                _hidl_index_0 * sizeof(::android::hardware::audio::common::V7_0::AudioTransport));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    size_t _hidl_gains_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.gains,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::common::V7_0::AudioPort, gains), &_hidl_gains_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.gains.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                obj.gains[_hidl_index_0],
                parcel,
                _hidl_gains_child,
                _hidl_index_0 * sizeof(::android::hardware::audio::common::V7_0::AudioGain));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    _hidl_err = writeEmbeddedToParcel(
            obj.ext,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::common::V7_0::AudioPort, ext));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = writeEmbeddedToParcel(
            obj.activeConfig,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::common::V7_0::AudioPort, activeConfig));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

static_assert(sizeof(::android::hardware::MQDescriptor<char, ::android::hardware::kSynchronizedReadWrite>) == 32, "wrong size");
static_assert(sizeof(::android::hardware::hidl_handle) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_memory) == 40, "wrong size");
static_assert(sizeof(::android::hardware::hidl_string) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_vec<char>) == 16, "wrong size");

}  // namespace V7_0
}  // namespace common
}  // namespace audio
}  // namespace hardware
}  // namespace android
