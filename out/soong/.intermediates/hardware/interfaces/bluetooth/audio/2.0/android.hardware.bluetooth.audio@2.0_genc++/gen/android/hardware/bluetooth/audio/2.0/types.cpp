#define LOG_TAG "android.hardware.bluetooth.audio@2.0::types"

#include <log/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <hidl/Static.h>
#include <hwbinder/ProcessState.h>
#include <utils/Trace.h>
#include <android/hardware/bluetooth/audio/2.0/types.h>
#include <android/hardware/bluetooth/audio/2.0/hwtypes.h>

namespace android {
namespace hardware {
namespace bluetooth {
namespace audio {
namespace V2_0 {

::android::hardware::bluetooth::audio::V2_0::CodecCapabilities::Capabilities::Capabilities() {
    static_assert(offsetof(::android::hardware::bluetooth::audio::V2_0::CodecCapabilities::Capabilities, hidl_d) == 0, "wrong offset");
    static_assert(offsetof(::android::hardware::bluetooth::audio::V2_0::CodecCapabilities::Capabilities, hidl_u) == 4, "wrong offset");

    ::std::memset(&hidl_u, 0, sizeof(hidl_u));
    ::std::memset(reinterpret_cast<uint8_t*>(this) + 1, 0, 3);
    // no padding to zero starting at offset 16

    hidl_d = hidl_discriminator::sbcCapabilities;
    new (&hidl_u.sbcCapabilities) ::android::hardware::bluetooth::audio::V2_0::SbcParameters();
}

::android::hardware::bluetooth::audio::V2_0::CodecCapabilities::Capabilities::~Capabilities() {
    hidl_destructUnion();
}

::android::hardware::bluetooth::audio::V2_0::CodecCapabilities::Capabilities::Capabilities(Capabilities&& other) : ::android::hardware::bluetooth::audio::V2_0::CodecCapabilities::Capabilities() {
    *this = std::move(other);
}

::android::hardware::bluetooth::audio::V2_0::CodecCapabilities::Capabilities::Capabilities(const Capabilities& other) : ::android::hardware::bluetooth::audio::V2_0::CodecCapabilities::Capabilities() {
    *this = other;
}

::android::hardware::bluetooth::audio::V2_0::CodecCapabilities::Capabilities& (::android::hardware::bluetooth::audio::V2_0::CodecCapabilities::Capabilities::operator=)(Capabilities&& other) {
    if (this == &other) { return *this; }

    switch (other.hidl_d) {
        case hidl_discriminator::sbcCapabilities: {
            sbcCapabilities(std::move(other.hidl_u.sbcCapabilities));
            break;
        }
        case hidl_discriminator::aacCapabilities: {
            aacCapabilities(std::move(other.hidl_u.aacCapabilities));
            break;
        }
        case hidl_discriminator::ldacCapabilities: {
            ldacCapabilities(std::move(other.hidl_u.ldacCapabilities));
            break;
        }
        case hidl_discriminator::aptxCapabilities: {
            aptxCapabilities(std::move(other.hidl_u.aptxCapabilities));
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

::android::hardware::bluetooth::audio::V2_0::CodecCapabilities::Capabilities& (::android::hardware::bluetooth::audio::V2_0::CodecCapabilities::Capabilities::operator=)(const Capabilities& other) {
    if (this == &other) { return *this; }

    switch (other.hidl_d) {
        case hidl_discriminator::sbcCapabilities: {
            sbcCapabilities(other.hidl_u.sbcCapabilities);
            break;
        }
        case hidl_discriminator::aacCapabilities: {
            aacCapabilities(other.hidl_u.aacCapabilities);
            break;
        }
        case hidl_discriminator::ldacCapabilities: {
            ldacCapabilities(other.hidl_u.ldacCapabilities);
            break;
        }
        case hidl_discriminator::aptxCapabilities: {
            aptxCapabilities(other.hidl_u.aptxCapabilities);
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

void ::android::hardware::bluetooth::audio::V2_0::CodecCapabilities::Capabilities::hidl_destructUnion() {
    switch (hidl_d) {
        case hidl_discriminator::sbcCapabilities: {
            ::android::hardware::details::destructElement(&(hidl_u.sbcCapabilities));
            break;
        }
        case hidl_discriminator::aacCapabilities: {
            ::android::hardware::details::destructElement(&(hidl_u.aacCapabilities));
            break;
        }
        case hidl_discriminator::ldacCapabilities: {
            ::android::hardware::details::destructElement(&(hidl_u.ldacCapabilities));
            break;
        }
        case hidl_discriminator::aptxCapabilities: {
            ::android::hardware::details::destructElement(&(hidl_u.aptxCapabilities));
            break;
        }
        default: {
            ::android::hardware::details::logAlwaysFatal((
                    "Unknown union discriminator (value: " +
                    std::to_string((uint8_t) hidl_d) + ").").c_str());
        }
    }

}

void ::android::hardware::bluetooth::audio::V2_0::CodecCapabilities::Capabilities::sbcCapabilities(const ::android::hardware::bluetooth::audio::V2_0::SbcParameters& o) {
    if (hidl_d != hidl_discriminator::sbcCapabilities) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.sbcCapabilities) ::android::hardware::bluetooth::audio::V2_0::SbcParameters(o);
        hidl_d = hidl_discriminator::sbcCapabilities;
    }
    else if (&(hidl_u.sbcCapabilities) != &o) {
        hidl_u.sbcCapabilities = o;
    }
}

void ::android::hardware::bluetooth::audio::V2_0::CodecCapabilities::Capabilities::sbcCapabilities(::android::hardware::bluetooth::audio::V2_0::SbcParameters&& o) {
    if (hidl_d != hidl_discriminator::sbcCapabilities) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.sbcCapabilities) ::android::hardware::bluetooth::audio::V2_0::SbcParameters(std::move(o));
        hidl_d = hidl_discriminator::sbcCapabilities;
    }
    else if (&(hidl_u.sbcCapabilities) != &o) {
        hidl_u.sbcCapabilities = std::move(o);
    }
}

::android::hardware::bluetooth::audio::V2_0::SbcParameters& (::android::hardware::bluetooth::audio::V2_0::CodecCapabilities::Capabilities::sbcCapabilities)() {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::sbcCapabilities)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::sbcCapabilities));
    }

    return hidl_u.sbcCapabilities;
}

const ::android::hardware::bluetooth::audio::V2_0::SbcParameters& (::android::hardware::bluetooth::audio::V2_0::CodecCapabilities::Capabilities::sbcCapabilities)() const {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::sbcCapabilities)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::sbcCapabilities));
    }

    return hidl_u.sbcCapabilities;
}

void ::android::hardware::bluetooth::audio::V2_0::CodecCapabilities::Capabilities::aacCapabilities(const ::android::hardware::bluetooth::audio::V2_0::AacParameters& o) {
    if (hidl_d != hidl_discriminator::aacCapabilities) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.aacCapabilities) ::android::hardware::bluetooth::audio::V2_0::AacParameters(o);
        hidl_d = hidl_discriminator::aacCapabilities;
    }
    else if (&(hidl_u.aacCapabilities) != &o) {
        hidl_u.aacCapabilities = o;
    }
}

void ::android::hardware::bluetooth::audio::V2_0::CodecCapabilities::Capabilities::aacCapabilities(::android::hardware::bluetooth::audio::V2_0::AacParameters&& o) {
    if (hidl_d != hidl_discriminator::aacCapabilities) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.aacCapabilities) ::android::hardware::bluetooth::audio::V2_0::AacParameters(std::move(o));
        hidl_d = hidl_discriminator::aacCapabilities;
    }
    else if (&(hidl_u.aacCapabilities) != &o) {
        hidl_u.aacCapabilities = std::move(o);
    }
}

::android::hardware::bluetooth::audio::V2_0::AacParameters& (::android::hardware::bluetooth::audio::V2_0::CodecCapabilities::Capabilities::aacCapabilities)() {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::aacCapabilities)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::aacCapabilities));
    }

    return hidl_u.aacCapabilities;
}

const ::android::hardware::bluetooth::audio::V2_0::AacParameters& (::android::hardware::bluetooth::audio::V2_0::CodecCapabilities::Capabilities::aacCapabilities)() const {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::aacCapabilities)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::aacCapabilities));
    }

    return hidl_u.aacCapabilities;
}

void ::android::hardware::bluetooth::audio::V2_0::CodecCapabilities::Capabilities::ldacCapabilities(const ::android::hardware::bluetooth::audio::V2_0::LdacParameters& o) {
    if (hidl_d != hidl_discriminator::ldacCapabilities) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.ldacCapabilities) ::android::hardware::bluetooth::audio::V2_0::LdacParameters(o);
        hidl_d = hidl_discriminator::ldacCapabilities;
    }
    else if (&(hidl_u.ldacCapabilities) != &o) {
        hidl_u.ldacCapabilities = o;
    }
}

void ::android::hardware::bluetooth::audio::V2_0::CodecCapabilities::Capabilities::ldacCapabilities(::android::hardware::bluetooth::audio::V2_0::LdacParameters&& o) {
    if (hidl_d != hidl_discriminator::ldacCapabilities) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.ldacCapabilities) ::android::hardware::bluetooth::audio::V2_0::LdacParameters(std::move(o));
        hidl_d = hidl_discriminator::ldacCapabilities;
    }
    else if (&(hidl_u.ldacCapabilities) != &o) {
        hidl_u.ldacCapabilities = std::move(o);
    }
}

::android::hardware::bluetooth::audio::V2_0::LdacParameters& (::android::hardware::bluetooth::audio::V2_0::CodecCapabilities::Capabilities::ldacCapabilities)() {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::ldacCapabilities)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::ldacCapabilities));
    }

    return hidl_u.ldacCapabilities;
}

const ::android::hardware::bluetooth::audio::V2_0::LdacParameters& (::android::hardware::bluetooth::audio::V2_0::CodecCapabilities::Capabilities::ldacCapabilities)() const {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::ldacCapabilities)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::ldacCapabilities));
    }

    return hidl_u.ldacCapabilities;
}

void ::android::hardware::bluetooth::audio::V2_0::CodecCapabilities::Capabilities::aptxCapabilities(const ::android::hardware::bluetooth::audio::V2_0::AptxParameters& o) {
    if (hidl_d != hidl_discriminator::aptxCapabilities) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.aptxCapabilities) ::android::hardware::bluetooth::audio::V2_0::AptxParameters(o);
        hidl_d = hidl_discriminator::aptxCapabilities;
    }
    else if (&(hidl_u.aptxCapabilities) != &o) {
        hidl_u.aptxCapabilities = o;
    }
}

void ::android::hardware::bluetooth::audio::V2_0::CodecCapabilities::Capabilities::aptxCapabilities(::android::hardware::bluetooth::audio::V2_0::AptxParameters&& o) {
    if (hidl_d != hidl_discriminator::aptxCapabilities) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.aptxCapabilities) ::android::hardware::bluetooth::audio::V2_0::AptxParameters(std::move(o));
        hidl_d = hidl_discriminator::aptxCapabilities;
    }
    else if (&(hidl_u.aptxCapabilities) != &o) {
        hidl_u.aptxCapabilities = std::move(o);
    }
}

::android::hardware::bluetooth::audio::V2_0::AptxParameters& (::android::hardware::bluetooth::audio::V2_0::CodecCapabilities::Capabilities::aptxCapabilities)() {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::aptxCapabilities)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::aptxCapabilities));
    }

    return hidl_u.aptxCapabilities;
}

const ::android::hardware::bluetooth::audio::V2_0::AptxParameters& (::android::hardware::bluetooth::audio::V2_0::CodecCapabilities::Capabilities::aptxCapabilities)() const {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::aptxCapabilities)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::aptxCapabilities));
    }

    return hidl_u.aptxCapabilities;
}

::android::hardware::bluetooth::audio::V2_0::CodecCapabilities::Capabilities::hidl_union::hidl_union() {}

::android::hardware::bluetooth::audio::V2_0::CodecCapabilities::Capabilities::hidl_union::~hidl_union() {}

::android::hardware::bluetooth::audio::V2_0::CodecCapabilities::Capabilities::hidl_discriminator (::android::hardware::bluetooth::audio::V2_0::CodecCapabilities::Capabilities::getDiscriminator)() const {
    return hidl_d;
}

::android::hardware::bluetooth::audio::V2_0::AudioCapabilities::AudioCapabilities() {
    static_assert(offsetof(::android::hardware::bluetooth::audio::V2_0::AudioCapabilities, hidl_d) == 0, "wrong offset");
    static_assert(offsetof(::android::hardware::bluetooth::audio::V2_0::AudioCapabilities, hidl_u) == 4, "wrong offset");

    ::std::memset(&hidl_u, 0, sizeof(hidl_u));
    ::std::memset(reinterpret_cast<uint8_t*>(this) + 1, 0, 3);
    // no padding to zero starting at offset 24

    hidl_d = hidl_discriminator::pcmCapabilities;
    new (&hidl_u.pcmCapabilities) ::android::hardware::bluetooth::audio::V2_0::PcmParameters();
}

::android::hardware::bluetooth::audio::V2_0::AudioCapabilities::~AudioCapabilities() {
    hidl_destructUnion();
}

::android::hardware::bluetooth::audio::V2_0::AudioCapabilities::AudioCapabilities(AudioCapabilities&& other) : ::android::hardware::bluetooth::audio::V2_0::AudioCapabilities() {
    *this = std::move(other);
}

::android::hardware::bluetooth::audio::V2_0::AudioCapabilities::AudioCapabilities(const AudioCapabilities& other) : ::android::hardware::bluetooth::audio::V2_0::AudioCapabilities() {
    *this = other;
}

::android::hardware::bluetooth::audio::V2_0::AudioCapabilities& (::android::hardware::bluetooth::audio::V2_0::AudioCapabilities::operator=)(AudioCapabilities&& other) {
    if (this == &other) { return *this; }

    switch (other.hidl_d) {
        case hidl_discriminator::pcmCapabilities: {
            pcmCapabilities(std::move(other.hidl_u.pcmCapabilities));
            break;
        }
        case hidl_discriminator::codecCapabilities: {
            codecCapabilities(std::move(other.hidl_u.codecCapabilities));
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

::android::hardware::bluetooth::audio::V2_0::AudioCapabilities& (::android::hardware::bluetooth::audio::V2_0::AudioCapabilities::operator=)(const AudioCapabilities& other) {
    if (this == &other) { return *this; }

    switch (other.hidl_d) {
        case hidl_discriminator::pcmCapabilities: {
            pcmCapabilities(other.hidl_u.pcmCapabilities);
            break;
        }
        case hidl_discriminator::codecCapabilities: {
            codecCapabilities(other.hidl_u.codecCapabilities);
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

void ::android::hardware::bluetooth::audio::V2_0::AudioCapabilities::hidl_destructUnion() {
    switch (hidl_d) {
        case hidl_discriminator::pcmCapabilities: {
            ::android::hardware::details::destructElement(&(hidl_u.pcmCapabilities));
            break;
        }
        case hidl_discriminator::codecCapabilities: {
            ::android::hardware::details::destructElement(&(hidl_u.codecCapabilities));
            break;
        }
        default: {
            ::android::hardware::details::logAlwaysFatal((
                    "Unknown union discriminator (value: " +
                    std::to_string((uint8_t) hidl_d) + ").").c_str());
        }
    }

}

void ::android::hardware::bluetooth::audio::V2_0::AudioCapabilities::pcmCapabilities(const ::android::hardware::bluetooth::audio::V2_0::PcmParameters& o) {
    if (hidl_d != hidl_discriminator::pcmCapabilities) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.pcmCapabilities) ::android::hardware::bluetooth::audio::V2_0::PcmParameters(o);
        hidl_d = hidl_discriminator::pcmCapabilities;
    }
    else if (&(hidl_u.pcmCapabilities) != &o) {
        hidl_u.pcmCapabilities = o;
    }
}

void ::android::hardware::bluetooth::audio::V2_0::AudioCapabilities::pcmCapabilities(::android::hardware::bluetooth::audio::V2_0::PcmParameters&& o) {
    if (hidl_d != hidl_discriminator::pcmCapabilities) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.pcmCapabilities) ::android::hardware::bluetooth::audio::V2_0::PcmParameters(std::move(o));
        hidl_d = hidl_discriminator::pcmCapabilities;
    }
    else if (&(hidl_u.pcmCapabilities) != &o) {
        hidl_u.pcmCapabilities = std::move(o);
    }
}

::android::hardware::bluetooth::audio::V2_0::PcmParameters& (::android::hardware::bluetooth::audio::V2_0::AudioCapabilities::pcmCapabilities)() {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::pcmCapabilities)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::pcmCapabilities));
    }

    return hidl_u.pcmCapabilities;
}

const ::android::hardware::bluetooth::audio::V2_0::PcmParameters& (::android::hardware::bluetooth::audio::V2_0::AudioCapabilities::pcmCapabilities)() const {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::pcmCapabilities)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::pcmCapabilities));
    }

    return hidl_u.pcmCapabilities;
}

void ::android::hardware::bluetooth::audio::V2_0::AudioCapabilities::codecCapabilities(const ::android::hardware::bluetooth::audio::V2_0::CodecCapabilities& o) {
    if (hidl_d != hidl_discriminator::codecCapabilities) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.codecCapabilities) ::android::hardware::bluetooth::audio::V2_0::CodecCapabilities(o);
        hidl_d = hidl_discriminator::codecCapabilities;
    }
    else if (&(hidl_u.codecCapabilities) != &o) {
        hidl_u.codecCapabilities = o;
    }
}

void ::android::hardware::bluetooth::audio::V2_0::AudioCapabilities::codecCapabilities(::android::hardware::bluetooth::audio::V2_0::CodecCapabilities&& o) {
    if (hidl_d != hidl_discriminator::codecCapabilities) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.codecCapabilities) ::android::hardware::bluetooth::audio::V2_0::CodecCapabilities(std::move(o));
        hidl_d = hidl_discriminator::codecCapabilities;
    }
    else if (&(hidl_u.codecCapabilities) != &o) {
        hidl_u.codecCapabilities = std::move(o);
    }
}

::android::hardware::bluetooth::audio::V2_0::CodecCapabilities& (::android::hardware::bluetooth::audio::V2_0::AudioCapabilities::codecCapabilities)() {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::codecCapabilities)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::codecCapabilities));
    }

    return hidl_u.codecCapabilities;
}

const ::android::hardware::bluetooth::audio::V2_0::CodecCapabilities& (::android::hardware::bluetooth::audio::V2_0::AudioCapabilities::codecCapabilities)() const {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::codecCapabilities)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::codecCapabilities));
    }

    return hidl_u.codecCapabilities;
}

::android::hardware::bluetooth::audio::V2_0::AudioCapabilities::hidl_union::hidl_union() {}

::android::hardware::bluetooth::audio::V2_0::AudioCapabilities::hidl_union::~hidl_union() {}

::android::hardware::bluetooth::audio::V2_0::AudioCapabilities::hidl_discriminator (::android::hardware::bluetooth::audio::V2_0::AudioCapabilities::getDiscriminator)() const {
    return hidl_d;
}

::android::hardware::bluetooth::audio::V2_0::CodecConfiguration::CodecSpecific::CodecSpecific() {
    static_assert(offsetof(::android::hardware::bluetooth::audio::V2_0::CodecConfiguration::CodecSpecific, hidl_d) == 0, "wrong offset");
    static_assert(offsetof(::android::hardware::bluetooth::audio::V2_0::CodecConfiguration::CodecSpecific, hidl_u) == 4, "wrong offset");

    ::std::memset(&hidl_u, 0, sizeof(hidl_u));
    ::std::memset(reinterpret_cast<uint8_t*>(this) + 1, 0, 3);
    // no padding to zero starting at offset 16

    hidl_d = hidl_discriminator::sbcConfig;
    new (&hidl_u.sbcConfig) ::android::hardware::bluetooth::audio::V2_0::SbcParameters();
}

::android::hardware::bluetooth::audio::V2_0::CodecConfiguration::CodecSpecific::~CodecSpecific() {
    hidl_destructUnion();
}

::android::hardware::bluetooth::audio::V2_0::CodecConfiguration::CodecSpecific::CodecSpecific(CodecSpecific&& other) : ::android::hardware::bluetooth::audio::V2_0::CodecConfiguration::CodecSpecific() {
    *this = std::move(other);
}

::android::hardware::bluetooth::audio::V2_0::CodecConfiguration::CodecSpecific::CodecSpecific(const CodecSpecific& other) : ::android::hardware::bluetooth::audio::V2_0::CodecConfiguration::CodecSpecific() {
    *this = other;
}

::android::hardware::bluetooth::audio::V2_0::CodecConfiguration::CodecSpecific& (::android::hardware::bluetooth::audio::V2_0::CodecConfiguration::CodecSpecific::operator=)(CodecSpecific&& other) {
    if (this == &other) { return *this; }

    switch (other.hidl_d) {
        case hidl_discriminator::sbcConfig: {
            sbcConfig(std::move(other.hidl_u.sbcConfig));
            break;
        }
        case hidl_discriminator::aacConfig: {
            aacConfig(std::move(other.hidl_u.aacConfig));
            break;
        }
        case hidl_discriminator::ldacConfig: {
            ldacConfig(std::move(other.hidl_u.ldacConfig));
            break;
        }
        case hidl_discriminator::aptxConfig: {
            aptxConfig(std::move(other.hidl_u.aptxConfig));
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

::android::hardware::bluetooth::audio::V2_0::CodecConfiguration::CodecSpecific& (::android::hardware::bluetooth::audio::V2_0::CodecConfiguration::CodecSpecific::operator=)(const CodecSpecific& other) {
    if (this == &other) { return *this; }

    switch (other.hidl_d) {
        case hidl_discriminator::sbcConfig: {
            sbcConfig(other.hidl_u.sbcConfig);
            break;
        }
        case hidl_discriminator::aacConfig: {
            aacConfig(other.hidl_u.aacConfig);
            break;
        }
        case hidl_discriminator::ldacConfig: {
            ldacConfig(other.hidl_u.ldacConfig);
            break;
        }
        case hidl_discriminator::aptxConfig: {
            aptxConfig(other.hidl_u.aptxConfig);
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

void ::android::hardware::bluetooth::audio::V2_0::CodecConfiguration::CodecSpecific::hidl_destructUnion() {
    switch (hidl_d) {
        case hidl_discriminator::sbcConfig: {
            ::android::hardware::details::destructElement(&(hidl_u.sbcConfig));
            break;
        }
        case hidl_discriminator::aacConfig: {
            ::android::hardware::details::destructElement(&(hidl_u.aacConfig));
            break;
        }
        case hidl_discriminator::ldacConfig: {
            ::android::hardware::details::destructElement(&(hidl_u.ldacConfig));
            break;
        }
        case hidl_discriminator::aptxConfig: {
            ::android::hardware::details::destructElement(&(hidl_u.aptxConfig));
            break;
        }
        default: {
            ::android::hardware::details::logAlwaysFatal((
                    "Unknown union discriminator (value: " +
                    std::to_string((uint8_t) hidl_d) + ").").c_str());
        }
    }

}

void ::android::hardware::bluetooth::audio::V2_0::CodecConfiguration::CodecSpecific::sbcConfig(const ::android::hardware::bluetooth::audio::V2_0::SbcParameters& o) {
    if (hidl_d != hidl_discriminator::sbcConfig) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.sbcConfig) ::android::hardware::bluetooth::audio::V2_0::SbcParameters(o);
        hidl_d = hidl_discriminator::sbcConfig;
    }
    else if (&(hidl_u.sbcConfig) != &o) {
        hidl_u.sbcConfig = o;
    }
}

void ::android::hardware::bluetooth::audio::V2_0::CodecConfiguration::CodecSpecific::sbcConfig(::android::hardware::bluetooth::audio::V2_0::SbcParameters&& o) {
    if (hidl_d != hidl_discriminator::sbcConfig) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.sbcConfig) ::android::hardware::bluetooth::audio::V2_0::SbcParameters(std::move(o));
        hidl_d = hidl_discriminator::sbcConfig;
    }
    else if (&(hidl_u.sbcConfig) != &o) {
        hidl_u.sbcConfig = std::move(o);
    }
}

::android::hardware::bluetooth::audio::V2_0::SbcParameters& (::android::hardware::bluetooth::audio::V2_0::CodecConfiguration::CodecSpecific::sbcConfig)() {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::sbcConfig)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::sbcConfig));
    }

    return hidl_u.sbcConfig;
}

const ::android::hardware::bluetooth::audio::V2_0::SbcParameters& (::android::hardware::bluetooth::audio::V2_0::CodecConfiguration::CodecSpecific::sbcConfig)() const {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::sbcConfig)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::sbcConfig));
    }

    return hidl_u.sbcConfig;
}

void ::android::hardware::bluetooth::audio::V2_0::CodecConfiguration::CodecSpecific::aacConfig(const ::android::hardware::bluetooth::audio::V2_0::AacParameters& o) {
    if (hidl_d != hidl_discriminator::aacConfig) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.aacConfig) ::android::hardware::bluetooth::audio::V2_0::AacParameters(o);
        hidl_d = hidl_discriminator::aacConfig;
    }
    else if (&(hidl_u.aacConfig) != &o) {
        hidl_u.aacConfig = o;
    }
}

void ::android::hardware::bluetooth::audio::V2_0::CodecConfiguration::CodecSpecific::aacConfig(::android::hardware::bluetooth::audio::V2_0::AacParameters&& o) {
    if (hidl_d != hidl_discriminator::aacConfig) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.aacConfig) ::android::hardware::bluetooth::audio::V2_0::AacParameters(std::move(o));
        hidl_d = hidl_discriminator::aacConfig;
    }
    else if (&(hidl_u.aacConfig) != &o) {
        hidl_u.aacConfig = std::move(o);
    }
}

::android::hardware::bluetooth::audio::V2_0::AacParameters& (::android::hardware::bluetooth::audio::V2_0::CodecConfiguration::CodecSpecific::aacConfig)() {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::aacConfig)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::aacConfig));
    }

    return hidl_u.aacConfig;
}

const ::android::hardware::bluetooth::audio::V2_0::AacParameters& (::android::hardware::bluetooth::audio::V2_0::CodecConfiguration::CodecSpecific::aacConfig)() const {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::aacConfig)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::aacConfig));
    }

    return hidl_u.aacConfig;
}

void ::android::hardware::bluetooth::audio::V2_0::CodecConfiguration::CodecSpecific::ldacConfig(const ::android::hardware::bluetooth::audio::V2_0::LdacParameters& o) {
    if (hidl_d != hidl_discriminator::ldacConfig) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.ldacConfig) ::android::hardware::bluetooth::audio::V2_0::LdacParameters(o);
        hidl_d = hidl_discriminator::ldacConfig;
    }
    else if (&(hidl_u.ldacConfig) != &o) {
        hidl_u.ldacConfig = o;
    }
}

void ::android::hardware::bluetooth::audio::V2_0::CodecConfiguration::CodecSpecific::ldacConfig(::android::hardware::bluetooth::audio::V2_0::LdacParameters&& o) {
    if (hidl_d != hidl_discriminator::ldacConfig) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.ldacConfig) ::android::hardware::bluetooth::audio::V2_0::LdacParameters(std::move(o));
        hidl_d = hidl_discriminator::ldacConfig;
    }
    else if (&(hidl_u.ldacConfig) != &o) {
        hidl_u.ldacConfig = std::move(o);
    }
}

::android::hardware::bluetooth::audio::V2_0::LdacParameters& (::android::hardware::bluetooth::audio::V2_0::CodecConfiguration::CodecSpecific::ldacConfig)() {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::ldacConfig)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::ldacConfig));
    }

    return hidl_u.ldacConfig;
}

const ::android::hardware::bluetooth::audio::V2_0::LdacParameters& (::android::hardware::bluetooth::audio::V2_0::CodecConfiguration::CodecSpecific::ldacConfig)() const {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::ldacConfig)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::ldacConfig));
    }

    return hidl_u.ldacConfig;
}

void ::android::hardware::bluetooth::audio::V2_0::CodecConfiguration::CodecSpecific::aptxConfig(const ::android::hardware::bluetooth::audio::V2_0::AptxParameters& o) {
    if (hidl_d != hidl_discriminator::aptxConfig) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.aptxConfig) ::android::hardware::bluetooth::audio::V2_0::AptxParameters(o);
        hidl_d = hidl_discriminator::aptxConfig;
    }
    else if (&(hidl_u.aptxConfig) != &o) {
        hidl_u.aptxConfig = o;
    }
}

void ::android::hardware::bluetooth::audio::V2_0::CodecConfiguration::CodecSpecific::aptxConfig(::android::hardware::bluetooth::audio::V2_0::AptxParameters&& o) {
    if (hidl_d != hidl_discriminator::aptxConfig) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.aptxConfig) ::android::hardware::bluetooth::audio::V2_0::AptxParameters(std::move(o));
        hidl_d = hidl_discriminator::aptxConfig;
    }
    else if (&(hidl_u.aptxConfig) != &o) {
        hidl_u.aptxConfig = std::move(o);
    }
}

::android::hardware::bluetooth::audio::V2_0::AptxParameters& (::android::hardware::bluetooth::audio::V2_0::CodecConfiguration::CodecSpecific::aptxConfig)() {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::aptxConfig)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::aptxConfig));
    }

    return hidl_u.aptxConfig;
}

const ::android::hardware::bluetooth::audio::V2_0::AptxParameters& (::android::hardware::bluetooth::audio::V2_0::CodecConfiguration::CodecSpecific::aptxConfig)() const {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::aptxConfig)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::aptxConfig));
    }

    return hidl_u.aptxConfig;
}

::android::hardware::bluetooth::audio::V2_0::CodecConfiguration::CodecSpecific::hidl_union::hidl_union() {}

::android::hardware::bluetooth::audio::V2_0::CodecConfiguration::CodecSpecific::hidl_union::~hidl_union() {}

::android::hardware::bluetooth::audio::V2_0::CodecConfiguration::CodecSpecific::hidl_discriminator (::android::hardware::bluetooth::audio::V2_0::CodecConfiguration::CodecSpecific::getDiscriminator)() const {
    return hidl_d;
}

::android::hardware::bluetooth::audio::V2_0::AudioConfiguration::AudioConfiguration() {
    static_assert(offsetof(::android::hardware::bluetooth::audio::V2_0::AudioConfiguration, hidl_d) == 0, "wrong offset");
    static_assert(offsetof(::android::hardware::bluetooth::audio::V2_0::AudioConfiguration, hidl_u) == 4, "wrong offset");

    ::std::memset(&hidl_u, 0, sizeof(hidl_u));
    ::std::memset(reinterpret_cast<uint8_t*>(this) + 1, 0, 3);
    // no padding to zero starting at offset 32

    hidl_d = hidl_discriminator::pcmConfig;
    new (&hidl_u.pcmConfig) ::android::hardware::bluetooth::audio::V2_0::PcmParameters();
}

::android::hardware::bluetooth::audio::V2_0::AudioConfiguration::~AudioConfiguration() {
    hidl_destructUnion();
}

::android::hardware::bluetooth::audio::V2_0::AudioConfiguration::AudioConfiguration(AudioConfiguration&& other) : ::android::hardware::bluetooth::audio::V2_0::AudioConfiguration() {
    *this = std::move(other);
}

::android::hardware::bluetooth::audio::V2_0::AudioConfiguration::AudioConfiguration(const AudioConfiguration& other) : ::android::hardware::bluetooth::audio::V2_0::AudioConfiguration() {
    *this = other;
}

::android::hardware::bluetooth::audio::V2_0::AudioConfiguration& (::android::hardware::bluetooth::audio::V2_0::AudioConfiguration::operator=)(AudioConfiguration&& other) {
    if (this == &other) { return *this; }

    switch (other.hidl_d) {
        case hidl_discriminator::pcmConfig: {
            pcmConfig(std::move(other.hidl_u.pcmConfig));
            break;
        }
        case hidl_discriminator::codecConfig: {
            codecConfig(std::move(other.hidl_u.codecConfig));
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

::android::hardware::bluetooth::audio::V2_0::AudioConfiguration& (::android::hardware::bluetooth::audio::V2_0::AudioConfiguration::operator=)(const AudioConfiguration& other) {
    if (this == &other) { return *this; }

    switch (other.hidl_d) {
        case hidl_discriminator::pcmConfig: {
            pcmConfig(other.hidl_u.pcmConfig);
            break;
        }
        case hidl_discriminator::codecConfig: {
            codecConfig(other.hidl_u.codecConfig);
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

void ::android::hardware::bluetooth::audio::V2_0::AudioConfiguration::hidl_destructUnion() {
    switch (hidl_d) {
        case hidl_discriminator::pcmConfig: {
            ::android::hardware::details::destructElement(&(hidl_u.pcmConfig));
            break;
        }
        case hidl_discriminator::codecConfig: {
            ::android::hardware::details::destructElement(&(hidl_u.codecConfig));
            break;
        }
        default: {
            ::android::hardware::details::logAlwaysFatal((
                    "Unknown union discriminator (value: " +
                    std::to_string((uint8_t) hidl_d) + ").").c_str());
        }
    }

}

void ::android::hardware::bluetooth::audio::V2_0::AudioConfiguration::pcmConfig(const ::android::hardware::bluetooth::audio::V2_0::PcmParameters& o) {
    if (hidl_d != hidl_discriminator::pcmConfig) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.pcmConfig) ::android::hardware::bluetooth::audio::V2_0::PcmParameters(o);
        hidl_d = hidl_discriminator::pcmConfig;
    }
    else if (&(hidl_u.pcmConfig) != &o) {
        hidl_u.pcmConfig = o;
    }
}

void ::android::hardware::bluetooth::audio::V2_0::AudioConfiguration::pcmConfig(::android::hardware::bluetooth::audio::V2_0::PcmParameters&& o) {
    if (hidl_d != hidl_discriminator::pcmConfig) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.pcmConfig) ::android::hardware::bluetooth::audio::V2_0::PcmParameters(std::move(o));
        hidl_d = hidl_discriminator::pcmConfig;
    }
    else if (&(hidl_u.pcmConfig) != &o) {
        hidl_u.pcmConfig = std::move(o);
    }
}

::android::hardware::bluetooth::audio::V2_0::PcmParameters& (::android::hardware::bluetooth::audio::V2_0::AudioConfiguration::pcmConfig)() {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::pcmConfig)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::pcmConfig));
    }

    return hidl_u.pcmConfig;
}

const ::android::hardware::bluetooth::audio::V2_0::PcmParameters& (::android::hardware::bluetooth::audio::V2_0::AudioConfiguration::pcmConfig)() const {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::pcmConfig)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::pcmConfig));
    }

    return hidl_u.pcmConfig;
}

void ::android::hardware::bluetooth::audio::V2_0::AudioConfiguration::codecConfig(const ::android::hardware::bluetooth::audio::V2_0::CodecConfiguration& o) {
    if (hidl_d != hidl_discriminator::codecConfig) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.codecConfig) ::android::hardware::bluetooth::audio::V2_0::CodecConfiguration(o);
        hidl_d = hidl_discriminator::codecConfig;
    }
    else if (&(hidl_u.codecConfig) != &o) {
        hidl_u.codecConfig = o;
    }
}

void ::android::hardware::bluetooth::audio::V2_0::AudioConfiguration::codecConfig(::android::hardware::bluetooth::audio::V2_0::CodecConfiguration&& o) {
    if (hidl_d != hidl_discriminator::codecConfig) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.codecConfig) ::android::hardware::bluetooth::audio::V2_0::CodecConfiguration(std::move(o));
        hidl_d = hidl_discriminator::codecConfig;
    }
    else if (&(hidl_u.codecConfig) != &o) {
        hidl_u.codecConfig = std::move(o);
    }
}

::android::hardware::bluetooth::audio::V2_0::CodecConfiguration& (::android::hardware::bluetooth::audio::V2_0::AudioConfiguration::codecConfig)() {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::codecConfig)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::codecConfig));
    }

    return hidl_u.codecConfig;
}

const ::android::hardware::bluetooth::audio::V2_0::CodecConfiguration& (::android::hardware::bluetooth::audio::V2_0::AudioConfiguration::codecConfig)() const {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::codecConfig)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::codecConfig));
    }

    return hidl_u.codecConfig;
}

::android::hardware::bluetooth::audio::V2_0::AudioConfiguration::hidl_union::hidl_union() {}

::android::hardware::bluetooth::audio::V2_0::AudioConfiguration::hidl_union::~hidl_union() {}

::android::hardware::bluetooth::audio::V2_0::AudioConfiguration::hidl_discriminator (::android::hardware::bluetooth::audio::V2_0::AudioConfiguration::getDiscriminator)() const {
    return hidl_d;
}

static_assert(sizeof(::android::hardware::MQDescriptor<char, ::android::hardware::kSynchronizedReadWrite>) == 32, "wrong size");
static_assert(sizeof(::android::hardware::hidl_handle) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_memory) == 40, "wrong size");
static_assert(sizeof(::android::hardware::hidl_string) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_vec<char>) == 16, "wrong size");

}  // namespace V2_0
}  // namespace audio
}  // namespace bluetooth
}  // namespace hardware
}  // namespace android
