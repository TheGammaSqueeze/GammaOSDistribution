#define LOG_TAG "android.hardware.bluetooth.audio@2.1::types"

#include <log/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <hidl/Static.h>
#include <hwbinder/ProcessState.h>
#include <utils/Trace.h>
#include <android/hardware/bluetooth/audio/2.1/types.h>
#include <android/hardware/bluetooth/audio/2.1/hwtypes.h>

namespace android {
namespace hardware {
namespace bluetooth {
namespace audio {
namespace V2_1 {

::android::hardware::bluetooth::audio::V2_1::AudioCapabilities::AudioCapabilities() {
    static_assert(offsetof(::android::hardware::bluetooth::audio::V2_1::AudioCapabilities, hidl_d) == 0, "wrong offset");
    static_assert(offsetof(::android::hardware::bluetooth::audio::V2_1::AudioCapabilities, hidl_u) == 4, "wrong offset");

    ::std::memset(&hidl_u, 0, sizeof(hidl_u));
    ::std::memset(reinterpret_cast<uint8_t*>(this) + 1, 0, 3);
    // no padding to zero starting at offset 28

    hidl_d = hidl_discriminator::pcmCapabilities;
    new (&hidl_u.pcmCapabilities) ::android::hardware::bluetooth::audio::V2_1::PcmParameters();
}

::android::hardware::bluetooth::audio::V2_1::AudioCapabilities::~AudioCapabilities() {
    hidl_destructUnion();
}

::android::hardware::bluetooth::audio::V2_1::AudioCapabilities::AudioCapabilities(AudioCapabilities&& other) : ::android::hardware::bluetooth::audio::V2_1::AudioCapabilities() {
    *this = std::move(other);
}

::android::hardware::bluetooth::audio::V2_1::AudioCapabilities::AudioCapabilities(const AudioCapabilities& other) : ::android::hardware::bluetooth::audio::V2_1::AudioCapabilities() {
    *this = other;
}

::android::hardware::bluetooth::audio::V2_1::AudioCapabilities& (::android::hardware::bluetooth::audio::V2_1::AudioCapabilities::operator=)(AudioCapabilities&& other) {
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
        case hidl_discriminator::leAudioCapabilities: {
            leAudioCapabilities(std::move(other.hidl_u.leAudioCapabilities));
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

::android::hardware::bluetooth::audio::V2_1::AudioCapabilities& (::android::hardware::bluetooth::audio::V2_1::AudioCapabilities::operator=)(const AudioCapabilities& other) {
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
        case hidl_discriminator::leAudioCapabilities: {
            leAudioCapabilities(other.hidl_u.leAudioCapabilities);
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

void ::android::hardware::bluetooth::audio::V2_1::AudioCapabilities::hidl_destructUnion() {
    switch (hidl_d) {
        case hidl_discriminator::pcmCapabilities: {
            ::android::hardware::details::destructElement(&(hidl_u.pcmCapabilities));
            break;
        }
        case hidl_discriminator::codecCapabilities: {
            ::android::hardware::details::destructElement(&(hidl_u.codecCapabilities));
            break;
        }
        case hidl_discriminator::leAudioCapabilities: {
            ::android::hardware::details::destructElement(&(hidl_u.leAudioCapabilities));
            break;
        }
        default: {
            ::android::hardware::details::logAlwaysFatal((
                    "Unknown union discriminator (value: " +
                    std::to_string((uint8_t) hidl_d) + ").").c_str());
        }
    }

}

void ::android::hardware::bluetooth::audio::V2_1::AudioCapabilities::pcmCapabilities(const ::android::hardware::bluetooth::audio::V2_1::PcmParameters& o) {
    if (hidl_d != hidl_discriminator::pcmCapabilities) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.pcmCapabilities) ::android::hardware::bluetooth::audio::V2_1::PcmParameters(o);
        hidl_d = hidl_discriminator::pcmCapabilities;
    }
    else if (&(hidl_u.pcmCapabilities) != &o) {
        hidl_u.pcmCapabilities = o;
    }
}

void ::android::hardware::bluetooth::audio::V2_1::AudioCapabilities::pcmCapabilities(::android::hardware::bluetooth::audio::V2_1::PcmParameters&& o) {
    if (hidl_d != hidl_discriminator::pcmCapabilities) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.pcmCapabilities) ::android::hardware::bluetooth::audio::V2_1::PcmParameters(std::move(o));
        hidl_d = hidl_discriminator::pcmCapabilities;
    }
    else if (&(hidl_u.pcmCapabilities) != &o) {
        hidl_u.pcmCapabilities = std::move(o);
    }
}

::android::hardware::bluetooth::audio::V2_1::PcmParameters& (::android::hardware::bluetooth::audio::V2_1::AudioCapabilities::pcmCapabilities)() {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::pcmCapabilities)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::pcmCapabilities));
    }

    return hidl_u.pcmCapabilities;
}

const ::android::hardware::bluetooth::audio::V2_1::PcmParameters& (::android::hardware::bluetooth::audio::V2_1::AudioCapabilities::pcmCapabilities)() const {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::pcmCapabilities)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::pcmCapabilities));
    }

    return hidl_u.pcmCapabilities;
}

void ::android::hardware::bluetooth::audio::V2_1::AudioCapabilities::codecCapabilities(const ::android::hardware::bluetooth::audio::V2_0::CodecCapabilities& o) {
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

void ::android::hardware::bluetooth::audio::V2_1::AudioCapabilities::codecCapabilities(::android::hardware::bluetooth::audio::V2_0::CodecCapabilities&& o) {
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

::android::hardware::bluetooth::audio::V2_0::CodecCapabilities& (::android::hardware::bluetooth::audio::V2_1::AudioCapabilities::codecCapabilities)() {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::codecCapabilities)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::codecCapabilities));
    }

    return hidl_u.codecCapabilities;
}

const ::android::hardware::bluetooth::audio::V2_0::CodecCapabilities& (::android::hardware::bluetooth::audio::V2_1::AudioCapabilities::codecCapabilities)() const {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::codecCapabilities)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::codecCapabilities));
    }

    return hidl_u.codecCapabilities;
}

void ::android::hardware::bluetooth::audio::V2_1::AudioCapabilities::leAudioCapabilities(const ::android::hardware::bluetooth::audio::V2_1::Lc3CodecCapabilities& o) {
    if (hidl_d != hidl_discriminator::leAudioCapabilities) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.leAudioCapabilities) ::android::hardware::bluetooth::audio::V2_1::Lc3CodecCapabilities(o);
        hidl_d = hidl_discriminator::leAudioCapabilities;
    }
    else if (&(hidl_u.leAudioCapabilities) != &o) {
        hidl_u.leAudioCapabilities = o;
    }
}

void ::android::hardware::bluetooth::audio::V2_1::AudioCapabilities::leAudioCapabilities(::android::hardware::bluetooth::audio::V2_1::Lc3CodecCapabilities&& o) {
    if (hidl_d != hidl_discriminator::leAudioCapabilities) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.leAudioCapabilities) ::android::hardware::bluetooth::audio::V2_1::Lc3CodecCapabilities(std::move(o));
        hidl_d = hidl_discriminator::leAudioCapabilities;
    }
    else if (&(hidl_u.leAudioCapabilities) != &o) {
        hidl_u.leAudioCapabilities = std::move(o);
    }
}

::android::hardware::bluetooth::audio::V2_1::Lc3CodecCapabilities& (::android::hardware::bluetooth::audio::V2_1::AudioCapabilities::leAudioCapabilities)() {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::leAudioCapabilities)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::leAudioCapabilities));
    }

    return hidl_u.leAudioCapabilities;
}

const ::android::hardware::bluetooth::audio::V2_1::Lc3CodecCapabilities& (::android::hardware::bluetooth::audio::V2_1::AudioCapabilities::leAudioCapabilities)() const {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::leAudioCapabilities)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::leAudioCapabilities));
    }

    return hidl_u.leAudioCapabilities;
}

::android::hardware::bluetooth::audio::V2_1::AudioCapabilities::hidl_union::hidl_union() {}

::android::hardware::bluetooth::audio::V2_1::AudioCapabilities::hidl_union::~hidl_union() {}

::android::hardware::bluetooth::audio::V2_1::AudioCapabilities::hidl_discriminator (::android::hardware::bluetooth::audio::V2_1::AudioCapabilities::getDiscriminator)() const {
    return hidl_d;
}

::android::hardware::bluetooth::audio::V2_1::AudioConfiguration::AudioConfiguration() {
    static_assert(offsetof(::android::hardware::bluetooth::audio::V2_1::AudioConfiguration, hidl_d) == 0, "wrong offset");
    static_assert(offsetof(::android::hardware::bluetooth::audio::V2_1::AudioConfiguration, hidl_u) == 4, "wrong offset");

    ::std::memset(&hidl_u, 0, sizeof(hidl_u));
    ::std::memset(reinterpret_cast<uint8_t*>(this) + 1, 0, 3);
    // no padding to zero starting at offset 32

    hidl_d = hidl_discriminator::pcmConfig;
    new (&hidl_u.pcmConfig) ::android::hardware::bluetooth::audio::V2_1::PcmParameters();
}

::android::hardware::bluetooth::audio::V2_1::AudioConfiguration::~AudioConfiguration() {
    hidl_destructUnion();
}

::android::hardware::bluetooth::audio::V2_1::AudioConfiguration::AudioConfiguration(AudioConfiguration&& other) : ::android::hardware::bluetooth::audio::V2_1::AudioConfiguration() {
    *this = std::move(other);
}

::android::hardware::bluetooth::audio::V2_1::AudioConfiguration::AudioConfiguration(const AudioConfiguration& other) : ::android::hardware::bluetooth::audio::V2_1::AudioConfiguration() {
    *this = other;
}

::android::hardware::bluetooth::audio::V2_1::AudioConfiguration& (::android::hardware::bluetooth::audio::V2_1::AudioConfiguration::operator=)(AudioConfiguration&& other) {
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
        case hidl_discriminator::leAudioCodecConfig: {
            leAudioCodecConfig(std::move(other.hidl_u.leAudioCodecConfig));
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

::android::hardware::bluetooth::audio::V2_1::AudioConfiguration& (::android::hardware::bluetooth::audio::V2_1::AudioConfiguration::operator=)(const AudioConfiguration& other) {
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
        case hidl_discriminator::leAudioCodecConfig: {
            leAudioCodecConfig(other.hidl_u.leAudioCodecConfig);
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

void ::android::hardware::bluetooth::audio::V2_1::AudioConfiguration::hidl_destructUnion() {
    switch (hidl_d) {
        case hidl_discriminator::pcmConfig: {
            ::android::hardware::details::destructElement(&(hidl_u.pcmConfig));
            break;
        }
        case hidl_discriminator::codecConfig: {
            ::android::hardware::details::destructElement(&(hidl_u.codecConfig));
            break;
        }
        case hidl_discriminator::leAudioCodecConfig: {
            ::android::hardware::details::destructElement(&(hidl_u.leAudioCodecConfig));
            break;
        }
        default: {
            ::android::hardware::details::logAlwaysFatal((
                    "Unknown union discriminator (value: " +
                    std::to_string((uint8_t) hidl_d) + ").").c_str());
        }
    }

}

void ::android::hardware::bluetooth::audio::V2_1::AudioConfiguration::pcmConfig(const ::android::hardware::bluetooth::audio::V2_1::PcmParameters& o) {
    if (hidl_d != hidl_discriminator::pcmConfig) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.pcmConfig) ::android::hardware::bluetooth::audio::V2_1::PcmParameters(o);
        hidl_d = hidl_discriminator::pcmConfig;
    }
    else if (&(hidl_u.pcmConfig) != &o) {
        hidl_u.pcmConfig = o;
    }
}

void ::android::hardware::bluetooth::audio::V2_1::AudioConfiguration::pcmConfig(::android::hardware::bluetooth::audio::V2_1::PcmParameters&& o) {
    if (hidl_d != hidl_discriminator::pcmConfig) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.pcmConfig) ::android::hardware::bluetooth::audio::V2_1::PcmParameters(std::move(o));
        hidl_d = hidl_discriminator::pcmConfig;
    }
    else if (&(hidl_u.pcmConfig) != &o) {
        hidl_u.pcmConfig = std::move(o);
    }
}

::android::hardware::bluetooth::audio::V2_1::PcmParameters& (::android::hardware::bluetooth::audio::V2_1::AudioConfiguration::pcmConfig)() {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::pcmConfig)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::pcmConfig));
    }

    return hidl_u.pcmConfig;
}

const ::android::hardware::bluetooth::audio::V2_1::PcmParameters& (::android::hardware::bluetooth::audio::V2_1::AudioConfiguration::pcmConfig)() const {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::pcmConfig)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::pcmConfig));
    }

    return hidl_u.pcmConfig;
}

void ::android::hardware::bluetooth::audio::V2_1::AudioConfiguration::codecConfig(const ::android::hardware::bluetooth::audio::V2_0::CodecConfiguration& o) {
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

void ::android::hardware::bluetooth::audio::V2_1::AudioConfiguration::codecConfig(::android::hardware::bluetooth::audio::V2_0::CodecConfiguration&& o) {
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

::android::hardware::bluetooth::audio::V2_0::CodecConfiguration& (::android::hardware::bluetooth::audio::V2_1::AudioConfiguration::codecConfig)() {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::codecConfig)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::codecConfig));
    }

    return hidl_u.codecConfig;
}

const ::android::hardware::bluetooth::audio::V2_0::CodecConfiguration& (::android::hardware::bluetooth::audio::V2_1::AudioConfiguration::codecConfig)() const {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::codecConfig)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::codecConfig));
    }

    return hidl_u.codecConfig;
}

void ::android::hardware::bluetooth::audio::V2_1::AudioConfiguration::leAudioCodecConfig(const ::android::hardware::bluetooth::audio::V2_1::Lc3CodecConfiguration& o) {
    if (hidl_d != hidl_discriminator::leAudioCodecConfig) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.leAudioCodecConfig) ::android::hardware::bluetooth::audio::V2_1::Lc3CodecConfiguration(o);
        hidl_d = hidl_discriminator::leAudioCodecConfig;
    }
    else if (&(hidl_u.leAudioCodecConfig) != &o) {
        hidl_u.leAudioCodecConfig = o;
    }
}

void ::android::hardware::bluetooth::audio::V2_1::AudioConfiguration::leAudioCodecConfig(::android::hardware::bluetooth::audio::V2_1::Lc3CodecConfiguration&& o) {
    if (hidl_d != hidl_discriminator::leAudioCodecConfig) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.leAudioCodecConfig) ::android::hardware::bluetooth::audio::V2_1::Lc3CodecConfiguration(std::move(o));
        hidl_d = hidl_discriminator::leAudioCodecConfig;
    }
    else if (&(hidl_u.leAudioCodecConfig) != &o) {
        hidl_u.leAudioCodecConfig = std::move(o);
    }
}

::android::hardware::bluetooth::audio::V2_1::Lc3CodecConfiguration& (::android::hardware::bluetooth::audio::V2_1::AudioConfiguration::leAudioCodecConfig)() {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::leAudioCodecConfig)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::leAudioCodecConfig));
    }

    return hidl_u.leAudioCodecConfig;
}

const ::android::hardware::bluetooth::audio::V2_1::Lc3CodecConfiguration& (::android::hardware::bluetooth::audio::V2_1::AudioConfiguration::leAudioCodecConfig)() const {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::leAudioCodecConfig)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::leAudioCodecConfig));
    }

    return hidl_u.leAudioCodecConfig;
}

::android::hardware::bluetooth::audio::V2_1::AudioConfiguration::hidl_union::hidl_union() {}

::android::hardware::bluetooth::audio::V2_1::AudioConfiguration::hidl_union::~hidl_union() {}

::android::hardware::bluetooth::audio::V2_1::AudioConfiguration::hidl_discriminator (::android::hardware::bluetooth::audio::V2_1::AudioConfiguration::getDiscriminator)() const {
    return hidl_d;
}

static_assert(sizeof(::android::hardware::MQDescriptor<char, ::android::hardware::kSynchronizedReadWrite>) == 32, "wrong size");
static_assert(sizeof(::android::hardware::hidl_handle) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_memory) == 40, "wrong size");
static_assert(sizeof(::android::hardware::hidl_string) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_vec<char>) == 16, "wrong size");

}  // namespace V2_1
}  // namespace audio
}  // namespace bluetooth
}  // namespace hardware
}  // namespace android
