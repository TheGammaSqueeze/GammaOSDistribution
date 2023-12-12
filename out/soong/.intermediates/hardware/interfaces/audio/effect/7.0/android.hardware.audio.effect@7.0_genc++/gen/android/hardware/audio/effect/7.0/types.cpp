#define LOG_TAG "android.hardware.audio.effect@7.0::types"

#include <log/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <hidl/Static.h>
#include <hwbinder/ProcessState.h>
#include <utils/Trace.h>
#include <android/hardware/audio/effect/7.0/types.h>
#include <android/hardware/audio/effect/7.0/hwtypes.h>

namespace android {
namespace hardware {
namespace audio {
namespace effect {
namespace V7_0 {

::android::status_t readEmbeddedFromParcel(
        const EffectDescriptor &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.name),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::effect::V7_0::EffectDescriptor, name));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.implementor),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::effect::V7_0::EffectDescriptor, implementor));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const EffectDescriptor &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.name,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::effect::V7_0::EffectDescriptor, name));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.implementor,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::effect::V7_0::EffectDescriptor, implementor));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const AudioBuffer &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_memory &>(obj.data),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::effect::V7_0::AudioBuffer, data));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const AudioBuffer &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.data,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::effect::V7_0::AudioBuffer, data));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const EffectBufferConfig::OptionalBuffer &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    switch (obj.getDiscriminator()) {
        case ::android::hardware::audio::effect::V7_0::EffectBufferConfig::OptionalBuffer::hidl_discriminator::buf: {
            _hidl_err = readEmbeddedFromParcel(
                    const_cast<::android::hardware::audio::effect::V7_0::AudioBuffer &>(obj.buf()),
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
        const EffectBufferConfig::OptionalBuffer &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    switch (obj.getDiscriminator()) {
        case ::android::hardware::audio::effect::V7_0::EffectBufferConfig::OptionalBuffer::hidl_discriminator::buf: {
            _hidl_err = writeEmbeddedToParcel(
                    obj.buf(),
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

::android::hardware::audio::effect::V7_0::EffectBufferConfig::OptionalBuffer::OptionalBuffer() {
    static_assert(offsetof(::android::hardware::audio::effect::V7_0::EffectBufferConfig::OptionalBuffer, hidl_d) == 0, "wrong offset");
    static_assert(offsetof(::android::hardware::audio::effect::V7_0::EffectBufferConfig::OptionalBuffer, hidl_u) == 8, "wrong offset");

    ::std::memset(&hidl_u, 0, sizeof(hidl_u));
    ::std::memset(reinterpret_cast<uint8_t*>(this) + 1, 0, 7);
    // no padding to zero starting at offset 64

    hidl_d = hidl_discriminator::unspecified;
    new (&hidl_u.unspecified) ::android::hidl::safe_union::V1_0::Monostate();
}

::android::hardware::audio::effect::V7_0::EffectBufferConfig::OptionalBuffer::~OptionalBuffer() {
    hidl_destructUnion();
}

::android::hardware::audio::effect::V7_0::EffectBufferConfig::OptionalBuffer::OptionalBuffer(OptionalBuffer&& other) : ::android::hardware::audio::effect::V7_0::EffectBufferConfig::OptionalBuffer() {
    *this = std::move(other);
}

::android::hardware::audio::effect::V7_0::EffectBufferConfig::OptionalBuffer::OptionalBuffer(const OptionalBuffer& other) : ::android::hardware::audio::effect::V7_0::EffectBufferConfig::OptionalBuffer() {
    *this = other;
}

::android::hardware::audio::effect::V7_0::EffectBufferConfig::OptionalBuffer& (::android::hardware::audio::effect::V7_0::EffectBufferConfig::OptionalBuffer::operator=)(OptionalBuffer&& other) {
    if (this == &other) { return *this; }

    switch (other.hidl_d) {
        case hidl_discriminator::unspecified: {
            unspecified(std::move(other.hidl_u.unspecified));
            break;
        }
        case hidl_discriminator::buf: {
            buf(std::move(other.hidl_u.buf));
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

::android::hardware::audio::effect::V7_0::EffectBufferConfig::OptionalBuffer& (::android::hardware::audio::effect::V7_0::EffectBufferConfig::OptionalBuffer::operator=)(const OptionalBuffer& other) {
    if (this == &other) { return *this; }

    switch (other.hidl_d) {
        case hidl_discriminator::unspecified: {
            unspecified(other.hidl_u.unspecified);
            break;
        }
        case hidl_discriminator::buf: {
            buf(other.hidl_u.buf);
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

void ::android::hardware::audio::effect::V7_0::EffectBufferConfig::OptionalBuffer::hidl_destructUnion() {
    switch (hidl_d) {
        case hidl_discriminator::unspecified: {
            ::android::hardware::details::destructElement(&(hidl_u.unspecified));
            break;
        }
        case hidl_discriminator::buf: {
            ::android::hardware::details::destructElement(&(hidl_u.buf));
            break;
        }
        default: {
            ::android::hardware::details::logAlwaysFatal((
                    "Unknown union discriminator (value: " +
                    std::to_string((uint8_t) hidl_d) + ").").c_str());
        }
    }

}

void ::android::hardware::audio::effect::V7_0::EffectBufferConfig::OptionalBuffer::unspecified(const ::android::hidl::safe_union::V1_0::Monostate& o) {
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

void ::android::hardware::audio::effect::V7_0::EffectBufferConfig::OptionalBuffer::unspecified(::android::hidl::safe_union::V1_0::Monostate&& o) {
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

::android::hidl::safe_union::V1_0::Monostate& (::android::hardware::audio::effect::V7_0::EffectBufferConfig::OptionalBuffer::unspecified)() {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::unspecified)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::unspecified));
    }

    return hidl_u.unspecified;
}

const ::android::hidl::safe_union::V1_0::Monostate& (::android::hardware::audio::effect::V7_0::EffectBufferConfig::OptionalBuffer::unspecified)() const {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::unspecified)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::unspecified));
    }

    return hidl_u.unspecified;
}

void ::android::hardware::audio::effect::V7_0::EffectBufferConfig::OptionalBuffer::buf(const ::android::hardware::audio::effect::V7_0::AudioBuffer& o) {
    if (hidl_d != hidl_discriminator::buf) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.buf) ::android::hardware::audio::effect::V7_0::AudioBuffer(o);
        hidl_d = hidl_discriminator::buf;
    }
    else if (&(hidl_u.buf) != &o) {
        hidl_u.buf = o;
    }
}

void ::android::hardware::audio::effect::V7_0::EffectBufferConfig::OptionalBuffer::buf(::android::hardware::audio::effect::V7_0::AudioBuffer&& o) {
    if (hidl_d != hidl_discriminator::buf) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.buf) ::android::hardware::audio::effect::V7_0::AudioBuffer(std::move(o));
        hidl_d = hidl_discriminator::buf;
    }
    else if (&(hidl_u.buf) != &o) {
        hidl_u.buf = std::move(o);
    }
}

::android::hardware::audio::effect::V7_0::AudioBuffer& (::android::hardware::audio::effect::V7_0::EffectBufferConfig::OptionalBuffer::buf)() {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::buf)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::buf));
    }

    return hidl_u.buf;
}

const ::android::hardware::audio::effect::V7_0::AudioBuffer& (::android::hardware::audio::effect::V7_0::EffectBufferConfig::OptionalBuffer::buf)() const {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::buf)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::buf));
    }

    return hidl_u.buf;
}

::android::hardware::audio::effect::V7_0::EffectBufferConfig::OptionalBuffer::hidl_union::hidl_union() {}

::android::hardware::audio::effect::V7_0::EffectBufferConfig::OptionalBuffer::hidl_union::~hidl_union() {}

::android::hardware::audio::effect::V7_0::EffectBufferConfig::OptionalBuffer::hidl_discriminator (::android::hardware::audio::effect::V7_0::EffectBufferConfig::OptionalBuffer::getDiscriminator)() const {
    return hidl_d;
}

::android::hardware::audio::effect::V7_0::EffectBufferConfig::OptionalAccessMode::OptionalAccessMode() {
    static_assert(offsetof(::android::hardware::audio::effect::V7_0::EffectBufferConfig::OptionalAccessMode, hidl_d) == 0, "wrong offset");
    static_assert(offsetof(::android::hardware::audio::effect::V7_0::EffectBufferConfig::OptionalAccessMode, hidl_u) == 4, "wrong offset");

    ::std::memset(&hidl_u, 0, sizeof(hidl_u));
    ::std::memset(reinterpret_cast<uint8_t*>(this) + 1, 0, 3);
    // no padding to zero starting at offset 8

    hidl_d = hidl_discriminator::unspecified;
    new (&hidl_u.unspecified) ::android::hidl::safe_union::V1_0::Monostate();
}

::android::hardware::audio::effect::V7_0::EffectBufferConfig::OptionalAccessMode::~OptionalAccessMode() {
    hidl_destructUnion();
}

::android::hardware::audio::effect::V7_0::EffectBufferConfig::OptionalAccessMode::OptionalAccessMode(OptionalAccessMode&& other) : ::android::hardware::audio::effect::V7_0::EffectBufferConfig::OptionalAccessMode() {
    *this = std::move(other);
}

::android::hardware::audio::effect::V7_0::EffectBufferConfig::OptionalAccessMode::OptionalAccessMode(const OptionalAccessMode& other) : ::android::hardware::audio::effect::V7_0::EffectBufferConfig::OptionalAccessMode() {
    *this = other;
}

::android::hardware::audio::effect::V7_0::EffectBufferConfig::OptionalAccessMode& (::android::hardware::audio::effect::V7_0::EffectBufferConfig::OptionalAccessMode::operator=)(OptionalAccessMode&& other) {
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

::android::hardware::audio::effect::V7_0::EffectBufferConfig::OptionalAccessMode& (::android::hardware::audio::effect::V7_0::EffectBufferConfig::OptionalAccessMode::operator=)(const OptionalAccessMode& other) {
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

void ::android::hardware::audio::effect::V7_0::EffectBufferConfig::OptionalAccessMode::hidl_destructUnion() {
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

void ::android::hardware::audio::effect::V7_0::EffectBufferConfig::OptionalAccessMode::unspecified(const ::android::hidl::safe_union::V1_0::Monostate& o) {
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

void ::android::hardware::audio::effect::V7_0::EffectBufferConfig::OptionalAccessMode::unspecified(::android::hidl::safe_union::V1_0::Monostate&& o) {
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

::android::hidl::safe_union::V1_0::Monostate& (::android::hardware::audio::effect::V7_0::EffectBufferConfig::OptionalAccessMode::unspecified)() {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::unspecified)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::unspecified));
    }

    return hidl_u.unspecified;
}

const ::android::hidl::safe_union::V1_0::Monostate& (::android::hardware::audio::effect::V7_0::EffectBufferConfig::OptionalAccessMode::unspecified)() const {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::unspecified)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::unspecified));
    }

    return hidl_u.unspecified;
}

void ::android::hardware::audio::effect::V7_0::EffectBufferConfig::OptionalAccessMode::value(::android::hardware::audio::effect::V7_0::EffectBufferAccess o) {
    if (hidl_d != hidl_discriminator::value) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.value) ::android::hardware::audio::effect::V7_0::EffectBufferAccess(o);
        hidl_d = hidl_discriminator::value;
    }
    else if (&(hidl_u.value) != &o) {
        hidl_u.value = o;
    }
}

::android::hardware::audio::effect::V7_0::EffectBufferAccess& (::android::hardware::audio::effect::V7_0::EffectBufferConfig::OptionalAccessMode::value)() {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::value)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::value));
    }

    return hidl_u.value;
}

::android::hardware::audio::effect::V7_0::EffectBufferAccess (::android::hardware::audio::effect::V7_0::EffectBufferConfig::OptionalAccessMode::value)() const {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::value)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::value));
    }

    return hidl_u.value;
}

::android::hardware::audio::effect::V7_0::EffectBufferConfig::OptionalAccessMode::hidl_union::hidl_union() {}

::android::hardware::audio::effect::V7_0::EffectBufferConfig::OptionalAccessMode::hidl_union::~hidl_union() {}

::android::hardware::audio::effect::V7_0::EffectBufferConfig::OptionalAccessMode::hidl_discriminator (::android::hardware::audio::effect::V7_0::EffectBufferConfig::OptionalAccessMode::getDiscriminator)() const {
    return hidl_d;
}

::android::status_t readEmbeddedFromParcel(
        const EffectBufferConfig &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::audio::effect::V7_0::EffectBufferConfig::OptionalBuffer &>(obj.buffer),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::effect::V7_0::EffectBufferConfig, buffer));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::audio::common::V7_0::AudioConfigBaseOptional &>(obj.base),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::effect::V7_0::EffectBufferConfig, base));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const EffectBufferConfig &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = writeEmbeddedToParcel(
            obj.buffer,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::effect::V7_0::EffectBufferConfig, buffer));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = writeEmbeddedToParcel(
            obj.base,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::effect::V7_0::EffectBufferConfig, base));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const EffectConfig &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::audio::effect::V7_0::EffectBufferConfig &>(obj.inputCfg),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::effect::V7_0::EffectConfig, inputCfg));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::audio::effect::V7_0::EffectBufferConfig &>(obj.outputCfg),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::effect::V7_0::EffectConfig, outputCfg));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const EffectConfig &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = writeEmbeddedToParcel(
            obj.inputCfg,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::effect::V7_0::EffectConfig, inputCfg));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = writeEmbeddedToParcel(
            obj.outputCfg,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::effect::V7_0::EffectConfig, outputCfg));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const EffectAuxChannelsConfig &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.mainChannels),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::effect::V7_0::EffectAuxChannelsConfig, mainChannels));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.auxChannels),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::effect::V7_0::EffectAuxChannelsConfig, auxChannels));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const EffectAuxChannelsConfig &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.mainChannels,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::effect::V7_0::EffectAuxChannelsConfig, mainChannels));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.auxChannels,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::effect::V7_0::EffectAuxChannelsConfig, auxChannels));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

static_assert(sizeof(::android::hardware::MQDescriptor<char, ::android::hardware::kSynchronizedReadWrite>) == 32, "wrong size");
static_assert(sizeof(::android::hardware::hidl_handle) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_memory) == 40, "wrong size");
static_assert(sizeof(::android::hardware::hidl_string) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_vec<char>) == 16, "wrong size");

}  // namespace V7_0
}  // namespace effect
}  // namespace audio
}  // namespace hardware
}  // namespace android
