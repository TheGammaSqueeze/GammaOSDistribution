#ifndef HIDL_GENERATED_ANDROID_HARDWARE_BLUETOOTH_AUDIO_V2_1_TYPES_H
#define HIDL_GENERATED_ANDROID_HARDWARE_BLUETOOTH_AUDIO_V2_1_TYPES_H

#include <android/hardware/bluetooth/audio/2.0/types.h>

#include <hidl/HidlSupport.h>
#include <hidl/MQDescriptor.h>
#include <utils/NativeHandle.h>
#include <utils/misc.h>

namespace android {
namespace hardware {
namespace bluetooth {
namespace audio {
namespace V2_1 {

// Forward declaration for forward reference support:
enum class SessionType : uint8_t;
enum class CodecType : uint32_t;
enum class SampleRate : uint32_t;
struct PcmParameters;
enum class Lc3FrameDuration : uint8_t;
struct Lc3Parameters;
struct Lc3CodecCapabilities;
struct AudioCapabilities;
struct Lc3CodecConfiguration;
struct AudioConfiguration;

enum class SessionType : uint8_t {
    UNKNOWN = 0,
    /**
     * A2DP legacy that AVDTP media is encoded by Bluetooth Stack
     */
    A2DP_SOFTWARE_ENCODING_DATAPATH = 1 /* ::android::hardware::bluetooth::audio::V2_0::SessionType.UNKNOWN implicitly + 1 */,
    /**
     * The encoding of AVDTP media is done by HW and there is control only
     */
    A2DP_HARDWARE_OFFLOAD_DATAPATH = 2 /* ::android::hardware::bluetooth::audio::V2_0::SessionType.A2DP_SOFTWARE_ENCODING_DATAPATH implicitly + 1 */,
    /**
     * Used when encoded by Bluetooth Stack and streaming to Hearing Aid
     */
    HEARING_AID_SOFTWARE_ENCODING_DATAPATH = 3 /* ::android::hardware::bluetooth::audio::V2_0::SessionType.A2DP_HARDWARE_OFFLOAD_DATAPATH implicitly + 1 */,
    /**
     * Used when encoded by Bluetooth Stack and streaming to LE Audio device
     */
    LE_AUDIO_SOFTWARE_ENCODING_DATAPATH = 4 /* ::android::hardware::bluetooth::audio::V2_0::SessionType.HEARING_AID_SOFTWARE_ENCODING_DATAPATH implicitly + 1 */,
    /**
     * Used when decoded by Bluetooth Stack and streaming to audio framework
     */
    LE_AUDIO_SOFTWARE_DECODED_DATAPATH = 5 /* ::android::hardware::bluetooth::audio::V2_1::SessionType.LE_AUDIO_SOFTWARE_ENCODING_DATAPATH implicitly + 1 */,
    /**
     * Encoding is done by HW an there is control only
     */
    LE_AUDIO_HARDWARE_OFFLOAD_ENCODING_DATAPATH = 6 /* ::android::hardware::bluetooth::audio::V2_1::SessionType.LE_AUDIO_SOFTWARE_DECODED_DATAPATH implicitly + 1 */,
    /**
     * Decoding is done by HW an there is control only
     */
    LE_AUDIO_HARDWARE_OFFLOAD_DECODING_DATAPATH = 7 /* ::android::hardware::bluetooth::audio::V2_1::SessionType.LE_AUDIO_HARDWARE_OFFLOAD_ENCODING_DATAPATH implicitly + 1 */,
};

enum class CodecType : uint32_t {
    UNKNOWN = 0u /* 0x00 */,
    SBC = 1u /* 0x01 */,
    AAC = 2u /* 0x02 */,
    APTX = 4u /* 0x04 */,
    APTX_HD = 8u /* 0x08 */,
    LDAC = 16u /* 0x10 */,
    LC3 = 32u /* 0x20 */,
};

enum class SampleRate : uint32_t {
    RATE_UNKNOWN = 0u /* 0x00 */,
    RATE_44100 = 1u /* 0x01 */,
    RATE_48000 = 2u /* 0x02 */,
    RATE_88200 = 4u /* 0x04 */,
    RATE_96000 = 8u /* 0x08 */,
    RATE_176400 = 16u /* 0x10 */,
    RATE_192000 = 32u /* 0x20 */,
    RATE_16000 = 64u /* 0x40 */,
    RATE_24000 = 128u /* 0x80 */,
    RATE_8000 = 256u /* 0x100 */,
    RATE_32000 = 512u /* 0x200 */,
};

/**
 * Used for Software Encoding audio feed parameters
 */
struct PcmParameters final {
    ::android::hardware::bluetooth::audio::V2_1::SampleRate sampleRate __attribute__ ((aligned(4)));
    ::android::hardware::bluetooth::audio::V2_0::ChannelMode channelMode __attribute__ ((aligned(1)));
    ::android::hardware::bluetooth::audio::V2_0::BitsPerSample bitsPerSample __attribute__ ((aligned(1)));
    /**
     * Data interval for data transfer
     */
    uint32_t dataIntervalUs __attribute__ ((aligned(4)));
};

static_assert(offsetof(::android::hardware::bluetooth::audio::V2_1::PcmParameters, sampleRate) == 0, "wrong offset");
static_assert(offsetof(::android::hardware::bluetooth::audio::V2_1::PcmParameters, channelMode) == 4, "wrong offset");
static_assert(offsetof(::android::hardware::bluetooth::audio::V2_1::PcmParameters, bitsPerSample) == 5, "wrong offset");
static_assert(offsetof(::android::hardware::bluetooth::audio::V2_1::PcmParameters, dataIntervalUs) == 8, "wrong offset");
static_assert(sizeof(::android::hardware::bluetooth::audio::V2_1::PcmParameters) == 12, "wrong size");
static_assert(__alignof(::android::hardware::bluetooth::audio::V2_1::PcmParameters) == 4, "wrong alignment");

enum class Lc3FrameDuration : uint8_t {
    DURATION_10000US = 0 /* 0x00 */,
    DURATION_7500US = 1 /* 0x01 */,
};

/**
 * Used for Hardware Encoding/Decoding LC3 codec parameters.
 */
struct Lc3Parameters final {
    /*
     * PCM is Input for encoder, Output for decoder
     */
    ::android::hardware::bluetooth::audio::V2_0::BitsPerSample pcmBitDepth __attribute__ ((aligned(1)));
    /*
     * codec-specific parameters
     */
    ::android::hardware::bluetooth::audio::V2_1::SampleRate samplingFrequency __attribute__ ((aligned(4)));
    ::android::hardware::bluetooth::audio::V2_1::Lc3FrameDuration frameDuration __attribute__ ((aligned(1)));
    /*
     * length in octets of a codec frame
     */
    uint32_t octetsPerFrame __attribute__ ((aligned(4)));
    /*
     * Number of blocks of codec frames per single SDU (Service Data Unit)
     */
    uint8_t blocksPerSdu __attribute__ ((aligned(1)));
};

static_assert(offsetof(::android::hardware::bluetooth::audio::V2_1::Lc3Parameters, pcmBitDepth) == 0, "wrong offset");
static_assert(offsetof(::android::hardware::bluetooth::audio::V2_1::Lc3Parameters, samplingFrequency) == 4, "wrong offset");
static_assert(offsetof(::android::hardware::bluetooth::audio::V2_1::Lc3Parameters, frameDuration) == 8, "wrong offset");
static_assert(offsetof(::android::hardware::bluetooth::audio::V2_1::Lc3Parameters, octetsPerFrame) == 12, "wrong offset");
static_assert(offsetof(::android::hardware::bluetooth::audio::V2_1::Lc3Parameters, blocksPerSdu) == 16, "wrong offset");
static_assert(sizeof(::android::hardware::bluetooth::audio::V2_1::Lc3Parameters) == 20, "wrong size");
static_assert(__alignof(::android::hardware::bluetooth::audio::V2_1::Lc3Parameters) == 4, "wrong alignment");

/**
 * Used to specify the capabilities of the LC3 codecs supported by Hardware Encoding.
 */
struct Lc3CodecCapabilities final {
    /*
     * This is bitfield, if bit N is set, HW Offloader supports N+1 channels at the same time.
     * Example: 0x27 = 0b00100111: One, two, three or six channels supported.
     */
    uint8_t supportedChannelCounts __attribute__ ((aligned(1)));
    ::android::hardware::bluetooth::audio::V2_1::Lc3Parameters lc3Capabilities __attribute__ ((aligned(4)));
};

static_assert(offsetof(::android::hardware::bluetooth::audio::V2_1::Lc3CodecCapabilities, supportedChannelCounts) == 0, "wrong offset");
static_assert(offsetof(::android::hardware::bluetooth::audio::V2_1::Lc3CodecCapabilities, lc3Capabilities) == 4, "wrong offset");
static_assert(sizeof(::android::hardware::bluetooth::audio::V2_1::Lc3CodecCapabilities) == 24, "wrong size");
static_assert(__alignof(::android::hardware::bluetooth::audio::V2_1::Lc3CodecCapabilities) == 4, "wrong alignment");

/**
 * Used to specify the capabilities of the different session types
 */
struct AudioCapabilities final {
    enum class hidl_discriminator : uint8_t {
        pcmCapabilities = 0,  // ::android::hardware::bluetooth::audio::V2_1::PcmParameters
        codecCapabilities = 1,  // ::android::hardware::bluetooth::audio::V2_0::CodecCapabilities
        leAudioCapabilities = 2,  // ::android::hardware::bluetooth::audio::V2_1::Lc3CodecCapabilities
    };

    AudioCapabilities();
    ~AudioCapabilities();
    AudioCapabilities(AudioCapabilities&&);
    AudioCapabilities(const AudioCapabilities&);
    AudioCapabilities& operator=(AudioCapabilities&&);
    AudioCapabilities& operator=(const AudioCapabilities&);

    void pcmCapabilities(const ::android::hardware::bluetooth::audio::V2_1::PcmParameters&);
    void pcmCapabilities(::android::hardware::bluetooth::audio::V2_1::PcmParameters&&);
    ::android::hardware::bluetooth::audio::V2_1::PcmParameters& pcmCapabilities();
    const ::android::hardware::bluetooth::audio::V2_1::PcmParameters& pcmCapabilities() const;

    void codecCapabilities(const ::android::hardware::bluetooth::audio::V2_0::CodecCapabilities&);
    void codecCapabilities(::android::hardware::bluetooth::audio::V2_0::CodecCapabilities&&);
    ::android::hardware::bluetooth::audio::V2_0::CodecCapabilities& codecCapabilities();
    const ::android::hardware::bluetooth::audio::V2_0::CodecCapabilities& codecCapabilities() const;

    void leAudioCapabilities(const ::android::hardware::bluetooth::audio::V2_1::Lc3CodecCapabilities&);
    void leAudioCapabilities(::android::hardware::bluetooth::audio::V2_1::Lc3CodecCapabilities&&);
    ::android::hardware::bluetooth::audio::V2_1::Lc3CodecCapabilities& leAudioCapabilities();
    const ::android::hardware::bluetooth::audio::V2_1::Lc3CodecCapabilities& leAudioCapabilities() const;

    // Utility methods
    hidl_discriminator getDiscriminator() const;

    constexpr size_t hidl_getUnionOffset() const {
        return offsetof(::android::hardware::bluetooth::audio::V2_1::AudioCapabilities, hidl_u);
    }

private:
    void hidl_destructUnion();

    hidl_discriminator hidl_d __attribute__ ((aligned(1))) ;
    union hidl_union final {
        ::android::hardware::bluetooth::audio::V2_1::PcmParameters pcmCapabilities __attribute__ ((aligned(4)));
        ::android::hardware::bluetooth::audio::V2_0::CodecCapabilities codecCapabilities __attribute__ ((aligned(4)));
        ::android::hardware::bluetooth::audio::V2_1::Lc3CodecCapabilities leAudioCapabilities __attribute__ ((aligned(4)));

        hidl_union();
        ~hidl_union();
    } hidl_u;

    static_assert(sizeof(::android::hardware::bluetooth::audio::V2_1::AudioCapabilities::hidl_union) == 24, "wrong size");
    static_assert(__alignof(::android::hardware::bluetooth::audio::V2_1::AudioCapabilities::hidl_union) == 4, "wrong alignment");
    static_assert(sizeof(::android::hardware::bluetooth::audio::V2_1::AudioCapabilities::hidl_discriminator) == 1, "wrong size");
    static_assert(__alignof(::android::hardware::bluetooth::audio::V2_1::AudioCapabilities::hidl_discriminator) == 1, "wrong alignment");
};

static_assert(sizeof(::android::hardware::bluetooth::audio::V2_1::AudioCapabilities) == 28, "wrong size");
static_assert(__alignof(::android::hardware::bluetooth::audio::V2_1::AudioCapabilities) == 4, "wrong alignment");

/**
 * Used to configure a LC3 Hardware Encoding session.
 */
struct Lc3CodecConfiguration final {
    /*
     * This is also bitfield, specifying how the channels are ordered in the outgoing media packet.
     * Bit meaning is defined in Bluetooth Assigned Numbers.
     */
    uint32_t audioChannelAllocation __attribute__ ((aligned(4)));
    ::android::hardware::bluetooth::audio::V2_1::Lc3Parameters lc3Config __attribute__ ((aligned(4)));
};

static_assert(offsetof(::android::hardware::bluetooth::audio::V2_1::Lc3CodecConfiguration, audioChannelAllocation) == 0, "wrong offset");
static_assert(offsetof(::android::hardware::bluetooth::audio::V2_1::Lc3CodecConfiguration, lc3Config) == 4, "wrong offset");
static_assert(sizeof(::android::hardware::bluetooth::audio::V2_1::Lc3CodecConfiguration) == 24, "wrong size");
static_assert(__alignof(::android::hardware::bluetooth::audio::V2_1::Lc3CodecConfiguration) == 4, "wrong alignment");

/**
 * Used to configure either a Hardware or Software Encoding session based on session type
 */
struct AudioConfiguration final {
    enum class hidl_discriminator : uint8_t {
        pcmConfig = 0,  // ::android::hardware::bluetooth::audio::V2_1::PcmParameters
        codecConfig = 1,  // ::android::hardware::bluetooth::audio::V2_0::CodecConfiguration
        leAudioCodecConfig = 2,  // ::android::hardware::bluetooth::audio::V2_1::Lc3CodecConfiguration
    };

    AudioConfiguration();
    ~AudioConfiguration();
    AudioConfiguration(AudioConfiguration&&);
    AudioConfiguration(const AudioConfiguration&);
    AudioConfiguration& operator=(AudioConfiguration&&);
    AudioConfiguration& operator=(const AudioConfiguration&);

    void pcmConfig(const ::android::hardware::bluetooth::audio::V2_1::PcmParameters&);
    void pcmConfig(::android::hardware::bluetooth::audio::V2_1::PcmParameters&&);
    ::android::hardware::bluetooth::audio::V2_1::PcmParameters& pcmConfig();
    const ::android::hardware::bluetooth::audio::V2_1::PcmParameters& pcmConfig() const;

    void codecConfig(const ::android::hardware::bluetooth::audio::V2_0::CodecConfiguration&);
    void codecConfig(::android::hardware::bluetooth::audio::V2_0::CodecConfiguration&&);
    ::android::hardware::bluetooth::audio::V2_0::CodecConfiguration& codecConfig();
    const ::android::hardware::bluetooth::audio::V2_0::CodecConfiguration& codecConfig() const;

    void leAudioCodecConfig(const ::android::hardware::bluetooth::audio::V2_1::Lc3CodecConfiguration&);
    void leAudioCodecConfig(::android::hardware::bluetooth::audio::V2_1::Lc3CodecConfiguration&&);
    ::android::hardware::bluetooth::audio::V2_1::Lc3CodecConfiguration& leAudioCodecConfig();
    const ::android::hardware::bluetooth::audio::V2_1::Lc3CodecConfiguration& leAudioCodecConfig() const;

    // Utility methods
    hidl_discriminator getDiscriminator() const;

    constexpr size_t hidl_getUnionOffset() const {
        return offsetof(::android::hardware::bluetooth::audio::V2_1::AudioConfiguration, hidl_u);
    }

private:
    void hidl_destructUnion();

    hidl_discriminator hidl_d __attribute__ ((aligned(1))) ;
    union hidl_union final {
        ::android::hardware::bluetooth::audio::V2_1::PcmParameters pcmConfig __attribute__ ((aligned(4)));
        ::android::hardware::bluetooth::audio::V2_0::CodecConfiguration codecConfig __attribute__ ((aligned(4)));
        ::android::hardware::bluetooth::audio::V2_1::Lc3CodecConfiguration leAudioCodecConfig __attribute__ ((aligned(4)));

        hidl_union();
        ~hidl_union();
    } hidl_u;

    static_assert(sizeof(::android::hardware::bluetooth::audio::V2_1::AudioConfiguration::hidl_union) == 28, "wrong size");
    static_assert(__alignof(::android::hardware::bluetooth::audio::V2_1::AudioConfiguration::hidl_union) == 4, "wrong alignment");
    static_assert(sizeof(::android::hardware::bluetooth::audio::V2_1::AudioConfiguration::hidl_discriminator) == 1, "wrong size");
    static_assert(__alignof(::android::hardware::bluetooth::audio::V2_1::AudioConfiguration::hidl_discriminator) == 1, "wrong alignment");
};

static_assert(sizeof(::android::hardware::bluetooth::audio::V2_1::AudioConfiguration) == 32, "wrong size");
static_assert(__alignof(::android::hardware::bluetooth::audio::V2_1::AudioConfiguration) == 4, "wrong alignment");

//
// type declarations for package
//

template<typename>
static inline std::string toString(uint8_t o);
static inline std::string toString(::android::hardware::bluetooth::audio::V2_1::SessionType o);
static inline void PrintTo(::android::hardware::bluetooth::audio::V2_1::SessionType o, ::std::ostream* os);
constexpr uint8_t operator|(const ::android::hardware::bluetooth::audio::V2_1::SessionType lhs, const ::android::hardware::bluetooth::audio::V2_1::SessionType rhs) {
    return static_cast<uint8_t>(static_cast<uint8_t>(lhs) | static_cast<uint8_t>(rhs));
}
constexpr uint8_t operator|(const uint8_t lhs, const ::android::hardware::bluetooth::audio::V2_1::SessionType rhs) {
    return static_cast<uint8_t>(lhs | static_cast<uint8_t>(rhs));
}
constexpr uint8_t operator|(const ::android::hardware::bluetooth::audio::V2_1::SessionType lhs, const uint8_t rhs) {
    return static_cast<uint8_t>(static_cast<uint8_t>(lhs) | rhs);
}
constexpr uint8_t operator&(const ::android::hardware::bluetooth::audio::V2_1::SessionType lhs, const ::android::hardware::bluetooth::audio::V2_1::SessionType rhs) {
    return static_cast<uint8_t>(static_cast<uint8_t>(lhs) & static_cast<uint8_t>(rhs));
}
constexpr uint8_t operator&(const uint8_t lhs, const ::android::hardware::bluetooth::audio::V2_1::SessionType rhs) {
    return static_cast<uint8_t>(lhs & static_cast<uint8_t>(rhs));
}
constexpr uint8_t operator&(const ::android::hardware::bluetooth::audio::V2_1::SessionType lhs, const uint8_t rhs) {
    return static_cast<uint8_t>(static_cast<uint8_t>(lhs) & rhs);
}
constexpr uint8_t &operator|=(uint8_t& v, const ::android::hardware::bluetooth::audio::V2_1::SessionType e) {
    v |= static_cast<uint8_t>(e);
    return v;
}
constexpr uint8_t &operator&=(uint8_t& v, const ::android::hardware::bluetooth::audio::V2_1::SessionType e) {
    v &= static_cast<uint8_t>(e);
    return v;
}

template<typename>
static inline std::string toString(uint32_t o);
static inline std::string toString(::android::hardware::bluetooth::audio::V2_1::CodecType o);
static inline void PrintTo(::android::hardware::bluetooth::audio::V2_1::CodecType o, ::std::ostream* os);
constexpr uint32_t operator|(const ::android::hardware::bluetooth::audio::V2_1::CodecType lhs, const ::android::hardware::bluetooth::audio::V2_1::CodecType rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) | static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator|(const uint32_t lhs, const ::android::hardware::bluetooth::audio::V2_1::CodecType rhs) {
    return static_cast<uint32_t>(lhs | static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator|(const ::android::hardware::bluetooth::audio::V2_1::CodecType lhs, const uint32_t rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) | rhs);
}
constexpr uint32_t operator&(const ::android::hardware::bluetooth::audio::V2_1::CodecType lhs, const ::android::hardware::bluetooth::audio::V2_1::CodecType rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) & static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator&(const uint32_t lhs, const ::android::hardware::bluetooth::audio::V2_1::CodecType rhs) {
    return static_cast<uint32_t>(lhs & static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator&(const ::android::hardware::bluetooth::audio::V2_1::CodecType lhs, const uint32_t rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) & rhs);
}
constexpr uint32_t &operator|=(uint32_t& v, const ::android::hardware::bluetooth::audio::V2_1::CodecType e) {
    v |= static_cast<uint32_t>(e);
    return v;
}
constexpr uint32_t &operator&=(uint32_t& v, const ::android::hardware::bluetooth::audio::V2_1::CodecType e) {
    v &= static_cast<uint32_t>(e);
    return v;
}

template<typename>
static inline std::string toString(uint32_t o);
static inline std::string toString(::android::hardware::bluetooth::audio::V2_1::SampleRate o);
static inline void PrintTo(::android::hardware::bluetooth::audio::V2_1::SampleRate o, ::std::ostream* os);
constexpr uint32_t operator|(const ::android::hardware::bluetooth::audio::V2_1::SampleRate lhs, const ::android::hardware::bluetooth::audio::V2_1::SampleRate rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) | static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator|(const uint32_t lhs, const ::android::hardware::bluetooth::audio::V2_1::SampleRate rhs) {
    return static_cast<uint32_t>(lhs | static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator|(const ::android::hardware::bluetooth::audio::V2_1::SampleRate lhs, const uint32_t rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) | rhs);
}
constexpr uint32_t operator&(const ::android::hardware::bluetooth::audio::V2_1::SampleRate lhs, const ::android::hardware::bluetooth::audio::V2_1::SampleRate rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) & static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator&(const uint32_t lhs, const ::android::hardware::bluetooth::audio::V2_1::SampleRate rhs) {
    return static_cast<uint32_t>(lhs & static_cast<uint32_t>(rhs));
}
constexpr uint32_t operator&(const ::android::hardware::bluetooth::audio::V2_1::SampleRate lhs, const uint32_t rhs) {
    return static_cast<uint32_t>(static_cast<uint32_t>(lhs) & rhs);
}
constexpr uint32_t &operator|=(uint32_t& v, const ::android::hardware::bluetooth::audio::V2_1::SampleRate e) {
    v |= static_cast<uint32_t>(e);
    return v;
}
constexpr uint32_t &operator&=(uint32_t& v, const ::android::hardware::bluetooth::audio::V2_1::SampleRate e) {
    v &= static_cast<uint32_t>(e);
    return v;
}

static inline std::string toString(const ::android::hardware::bluetooth::audio::V2_1::PcmParameters& o);
static inline void PrintTo(const ::android::hardware::bluetooth::audio::V2_1::PcmParameters& o, ::std::ostream*);
static inline bool operator==(const ::android::hardware::bluetooth::audio::V2_1::PcmParameters& lhs, const ::android::hardware::bluetooth::audio::V2_1::PcmParameters& rhs);
static inline bool operator!=(const ::android::hardware::bluetooth::audio::V2_1::PcmParameters& lhs, const ::android::hardware::bluetooth::audio::V2_1::PcmParameters& rhs);

template<typename>
static inline std::string toString(uint8_t o);
static inline std::string toString(::android::hardware::bluetooth::audio::V2_1::Lc3FrameDuration o);
static inline void PrintTo(::android::hardware::bluetooth::audio::V2_1::Lc3FrameDuration o, ::std::ostream* os);
constexpr uint8_t operator|(const ::android::hardware::bluetooth::audio::V2_1::Lc3FrameDuration lhs, const ::android::hardware::bluetooth::audio::V2_1::Lc3FrameDuration rhs) {
    return static_cast<uint8_t>(static_cast<uint8_t>(lhs) | static_cast<uint8_t>(rhs));
}
constexpr uint8_t operator|(const uint8_t lhs, const ::android::hardware::bluetooth::audio::V2_1::Lc3FrameDuration rhs) {
    return static_cast<uint8_t>(lhs | static_cast<uint8_t>(rhs));
}
constexpr uint8_t operator|(const ::android::hardware::bluetooth::audio::V2_1::Lc3FrameDuration lhs, const uint8_t rhs) {
    return static_cast<uint8_t>(static_cast<uint8_t>(lhs) | rhs);
}
constexpr uint8_t operator&(const ::android::hardware::bluetooth::audio::V2_1::Lc3FrameDuration lhs, const ::android::hardware::bluetooth::audio::V2_1::Lc3FrameDuration rhs) {
    return static_cast<uint8_t>(static_cast<uint8_t>(lhs) & static_cast<uint8_t>(rhs));
}
constexpr uint8_t operator&(const uint8_t lhs, const ::android::hardware::bluetooth::audio::V2_1::Lc3FrameDuration rhs) {
    return static_cast<uint8_t>(lhs & static_cast<uint8_t>(rhs));
}
constexpr uint8_t operator&(const ::android::hardware::bluetooth::audio::V2_1::Lc3FrameDuration lhs, const uint8_t rhs) {
    return static_cast<uint8_t>(static_cast<uint8_t>(lhs) & rhs);
}
constexpr uint8_t &operator|=(uint8_t& v, const ::android::hardware::bluetooth::audio::V2_1::Lc3FrameDuration e) {
    v |= static_cast<uint8_t>(e);
    return v;
}
constexpr uint8_t &operator&=(uint8_t& v, const ::android::hardware::bluetooth::audio::V2_1::Lc3FrameDuration e) {
    v &= static_cast<uint8_t>(e);
    return v;
}

static inline std::string toString(const ::android::hardware::bluetooth::audio::V2_1::Lc3Parameters& o);
static inline void PrintTo(const ::android::hardware::bluetooth::audio::V2_1::Lc3Parameters& o, ::std::ostream*);
static inline bool operator==(const ::android::hardware::bluetooth::audio::V2_1::Lc3Parameters& lhs, const ::android::hardware::bluetooth::audio::V2_1::Lc3Parameters& rhs);
static inline bool operator!=(const ::android::hardware::bluetooth::audio::V2_1::Lc3Parameters& lhs, const ::android::hardware::bluetooth::audio::V2_1::Lc3Parameters& rhs);

static inline std::string toString(const ::android::hardware::bluetooth::audio::V2_1::Lc3CodecCapabilities& o);
static inline void PrintTo(const ::android::hardware::bluetooth::audio::V2_1::Lc3CodecCapabilities& o, ::std::ostream*);
static inline bool operator==(const ::android::hardware::bluetooth::audio::V2_1::Lc3CodecCapabilities& lhs, const ::android::hardware::bluetooth::audio::V2_1::Lc3CodecCapabilities& rhs);
static inline bool operator!=(const ::android::hardware::bluetooth::audio::V2_1::Lc3CodecCapabilities& lhs, const ::android::hardware::bluetooth::audio::V2_1::Lc3CodecCapabilities& rhs);

static inline std::string toString(const ::android::hardware::bluetooth::audio::V2_1::AudioCapabilities& o);
static inline void PrintTo(const ::android::hardware::bluetooth::audio::V2_1::AudioCapabilities& o, ::std::ostream*);
static inline bool operator==(const ::android::hardware::bluetooth::audio::V2_1::AudioCapabilities& lhs, const ::android::hardware::bluetooth::audio::V2_1::AudioCapabilities& rhs);
static inline bool operator!=(const ::android::hardware::bluetooth::audio::V2_1::AudioCapabilities& lhs, const ::android::hardware::bluetooth::audio::V2_1::AudioCapabilities& rhs);

static inline std::string toString(const ::android::hardware::bluetooth::audio::V2_1::Lc3CodecConfiguration& o);
static inline void PrintTo(const ::android::hardware::bluetooth::audio::V2_1::Lc3CodecConfiguration& o, ::std::ostream*);
static inline bool operator==(const ::android::hardware::bluetooth::audio::V2_1::Lc3CodecConfiguration& lhs, const ::android::hardware::bluetooth::audio::V2_1::Lc3CodecConfiguration& rhs);
static inline bool operator!=(const ::android::hardware::bluetooth::audio::V2_1::Lc3CodecConfiguration& lhs, const ::android::hardware::bluetooth::audio::V2_1::Lc3CodecConfiguration& rhs);

static inline std::string toString(const ::android::hardware::bluetooth::audio::V2_1::AudioConfiguration& o);
static inline void PrintTo(const ::android::hardware::bluetooth::audio::V2_1::AudioConfiguration& o, ::std::ostream*);
static inline bool operator==(const ::android::hardware::bluetooth::audio::V2_1::AudioConfiguration& lhs, const ::android::hardware::bluetooth::audio::V2_1::AudioConfiguration& rhs);
static inline bool operator!=(const ::android::hardware::bluetooth::audio::V2_1::AudioConfiguration& lhs, const ::android::hardware::bluetooth::audio::V2_1::AudioConfiguration& rhs);

//
// type header definitions for package
//

template<>
inline std::string toString<::android::hardware::bluetooth::audio::V2_1::SessionType>(uint8_t o) {
    using ::android::hardware::details::toHexString;
    std::string os;
    ::android::hardware::hidl_bitfield<::android::hardware::bluetooth::audio::V2_1::SessionType> flipped = 0;
    bool first = true;
    if ((o & ::android::hardware::bluetooth::audio::V2_1::SessionType::UNKNOWN) == static_cast<uint8_t>(::android::hardware::bluetooth::audio::V2_1::SessionType::UNKNOWN)) {
        os += (first ? "" : " | ");
        os += "UNKNOWN";
        first = false;
        flipped |= ::android::hardware::bluetooth::audio::V2_1::SessionType::UNKNOWN;
    }
    if ((o & ::android::hardware::bluetooth::audio::V2_1::SessionType::A2DP_SOFTWARE_ENCODING_DATAPATH) == static_cast<uint8_t>(::android::hardware::bluetooth::audio::V2_1::SessionType::A2DP_SOFTWARE_ENCODING_DATAPATH)) {
        os += (first ? "" : " | ");
        os += "A2DP_SOFTWARE_ENCODING_DATAPATH";
        first = false;
        flipped |= ::android::hardware::bluetooth::audio::V2_1::SessionType::A2DP_SOFTWARE_ENCODING_DATAPATH;
    }
    if ((o & ::android::hardware::bluetooth::audio::V2_1::SessionType::A2DP_HARDWARE_OFFLOAD_DATAPATH) == static_cast<uint8_t>(::android::hardware::bluetooth::audio::V2_1::SessionType::A2DP_HARDWARE_OFFLOAD_DATAPATH)) {
        os += (first ? "" : " | ");
        os += "A2DP_HARDWARE_OFFLOAD_DATAPATH";
        first = false;
        flipped |= ::android::hardware::bluetooth::audio::V2_1::SessionType::A2DP_HARDWARE_OFFLOAD_DATAPATH;
    }
    if ((o & ::android::hardware::bluetooth::audio::V2_1::SessionType::HEARING_AID_SOFTWARE_ENCODING_DATAPATH) == static_cast<uint8_t>(::android::hardware::bluetooth::audio::V2_1::SessionType::HEARING_AID_SOFTWARE_ENCODING_DATAPATH)) {
        os += (first ? "" : " | ");
        os += "HEARING_AID_SOFTWARE_ENCODING_DATAPATH";
        first = false;
        flipped |= ::android::hardware::bluetooth::audio::V2_1::SessionType::HEARING_AID_SOFTWARE_ENCODING_DATAPATH;
    }
    if ((o & ::android::hardware::bluetooth::audio::V2_1::SessionType::LE_AUDIO_SOFTWARE_ENCODING_DATAPATH) == static_cast<uint8_t>(::android::hardware::bluetooth::audio::V2_1::SessionType::LE_AUDIO_SOFTWARE_ENCODING_DATAPATH)) {
        os += (first ? "" : " | ");
        os += "LE_AUDIO_SOFTWARE_ENCODING_DATAPATH";
        first = false;
        flipped |= ::android::hardware::bluetooth::audio::V2_1::SessionType::LE_AUDIO_SOFTWARE_ENCODING_DATAPATH;
    }
    if ((o & ::android::hardware::bluetooth::audio::V2_1::SessionType::LE_AUDIO_SOFTWARE_DECODED_DATAPATH) == static_cast<uint8_t>(::android::hardware::bluetooth::audio::V2_1::SessionType::LE_AUDIO_SOFTWARE_DECODED_DATAPATH)) {
        os += (first ? "" : " | ");
        os += "LE_AUDIO_SOFTWARE_DECODED_DATAPATH";
        first = false;
        flipped |= ::android::hardware::bluetooth::audio::V2_1::SessionType::LE_AUDIO_SOFTWARE_DECODED_DATAPATH;
    }
    if ((o & ::android::hardware::bluetooth::audio::V2_1::SessionType::LE_AUDIO_HARDWARE_OFFLOAD_ENCODING_DATAPATH) == static_cast<uint8_t>(::android::hardware::bluetooth::audio::V2_1::SessionType::LE_AUDIO_HARDWARE_OFFLOAD_ENCODING_DATAPATH)) {
        os += (first ? "" : " | ");
        os += "LE_AUDIO_HARDWARE_OFFLOAD_ENCODING_DATAPATH";
        first = false;
        flipped |= ::android::hardware::bluetooth::audio::V2_1::SessionType::LE_AUDIO_HARDWARE_OFFLOAD_ENCODING_DATAPATH;
    }
    if ((o & ::android::hardware::bluetooth::audio::V2_1::SessionType::LE_AUDIO_HARDWARE_OFFLOAD_DECODING_DATAPATH) == static_cast<uint8_t>(::android::hardware::bluetooth::audio::V2_1::SessionType::LE_AUDIO_HARDWARE_OFFLOAD_DECODING_DATAPATH)) {
        os += (first ? "" : " | ");
        os += "LE_AUDIO_HARDWARE_OFFLOAD_DECODING_DATAPATH";
        first = false;
        flipped |= ::android::hardware::bluetooth::audio::V2_1::SessionType::LE_AUDIO_HARDWARE_OFFLOAD_DECODING_DATAPATH;
    }
    if (o != flipped) {
        os += (first ? "" : " | ");
        os += toHexString(o & (~flipped));
    }os += " (";
    os += toHexString(o);
    os += ")";
    return os;
}

static inline std::string toString(::android::hardware::bluetooth::audio::V2_1::SessionType o) {
    using ::android::hardware::details::toHexString;
    if (o == ::android::hardware::bluetooth::audio::V2_1::SessionType::UNKNOWN) {
        return "UNKNOWN";
    }
    if (o == ::android::hardware::bluetooth::audio::V2_1::SessionType::A2DP_SOFTWARE_ENCODING_DATAPATH) {
        return "A2DP_SOFTWARE_ENCODING_DATAPATH";
    }
    if (o == ::android::hardware::bluetooth::audio::V2_1::SessionType::A2DP_HARDWARE_OFFLOAD_DATAPATH) {
        return "A2DP_HARDWARE_OFFLOAD_DATAPATH";
    }
    if (o == ::android::hardware::bluetooth::audio::V2_1::SessionType::HEARING_AID_SOFTWARE_ENCODING_DATAPATH) {
        return "HEARING_AID_SOFTWARE_ENCODING_DATAPATH";
    }
    if (o == ::android::hardware::bluetooth::audio::V2_1::SessionType::LE_AUDIO_SOFTWARE_ENCODING_DATAPATH) {
        return "LE_AUDIO_SOFTWARE_ENCODING_DATAPATH";
    }
    if (o == ::android::hardware::bluetooth::audio::V2_1::SessionType::LE_AUDIO_SOFTWARE_DECODED_DATAPATH) {
        return "LE_AUDIO_SOFTWARE_DECODED_DATAPATH";
    }
    if (o == ::android::hardware::bluetooth::audio::V2_1::SessionType::LE_AUDIO_HARDWARE_OFFLOAD_ENCODING_DATAPATH) {
        return "LE_AUDIO_HARDWARE_OFFLOAD_ENCODING_DATAPATH";
    }
    if (o == ::android::hardware::bluetooth::audio::V2_1::SessionType::LE_AUDIO_HARDWARE_OFFLOAD_DECODING_DATAPATH) {
        return "LE_AUDIO_HARDWARE_OFFLOAD_DECODING_DATAPATH";
    }
    std::string os;
    os += toHexString(static_cast<uint8_t>(o));
    return os;
}

static inline void PrintTo(::android::hardware::bluetooth::audio::V2_1::SessionType o, ::std::ostream* os) {
    *os << toString(o);
}

template<>
inline std::string toString<::android::hardware::bluetooth::audio::V2_1::CodecType>(uint32_t o) {
    using ::android::hardware::details::toHexString;
    std::string os;
    ::android::hardware::hidl_bitfield<::android::hardware::bluetooth::audio::V2_1::CodecType> flipped = 0;
    bool first = true;
    if ((o & ::android::hardware::bluetooth::audio::V2_1::CodecType::UNKNOWN) == static_cast<uint32_t>(::android::hardware::bluetooth::audio::V2_1::CodecType::UNKNOWN)) {
        os += (first ? "" : " | ");
        os += "UNKNOWN";
        first = false;
        flipped |= ::android::hardware::bluetooth::audio::V2_1::CodecType::UNKNOWN;
    }
    if ((o & ::android::hardware::bluetooth::audio::V2_1::CodecType::SBC) == static_cast<uint32_t>(::android::hardware::bluetooth::audio::V2_1::CodecType::SBC)) {
        os += (first ? "" : " | ");
        os += "SBC";
        first = false;
        flipped |= ::android::hardware::bluetooth::audio::V2_1::CodecType::SBC;
    }
    if ((o & ::android::hardware::bluetooth::audio::V2_1::CodecType::AAC) == static_cast<uint32_t>(::android::hardware::bluetooth::audio::V2_1::CodecType::AAC)) {
        os += (first ? "" : " | ");
        os += "AAC";
        first = false;
        flipped |= ::android::hardware::bluetooth::audio::V2_1::CodecType::AAC;
    }
    if ((o & ::android::hardware::bluetooth::audio::V2_1::CodecType::APTX) == static_cast<uint32_t>(::android::hardware::bluetooth::audio::V2_1::CodecType::APTX)) {
        os += (first ? "" : " | ");
        os += "APTX";
        first = false;
        flipped |= ::android::hardware::bluetooth::audio::V2_1::CodecType::APTX;
    }
    if ((o & ::android::hardware::bluetooth::audio::V2_1::CodecType::APTX_HD) == static_cast<uint32_t>(::android::hardware::bluetooth::audio::V2_1::CodecType::APTX_HD)) {
        os += (first ? "" : " | ");
        os += "APTX_HD";
        first = false;
        flipped |= ::android::hardware::bluetooth::audio::V2_1::CodecType::APTX_HD;
    }
    if ((o & ::android::hardware::bluetooth::audio::V2_1::CodecType::LDAC) == static_cast<uint32_t>(::android::hardware::bluetooth::audio::V2_1::CodecType::LDAC)) {
        os += (first ? "" : " | ");
        os += "LDAC";
        first = false;
        flipped |= ::android::hardware::bluetooth::audio::V2_1::CodecType::LDAC;
    }
    if ((o & ::android::hardware::bluetooth::audio::V2_1::CodecType::LC3) == static_cast<uint32_t>(::android::hardware::bluetooth::audio::V2_1::CodecType::LC3)) {
        os += (first ? "" : " | ");
        os += "LC3";
        first = false;
        flipped |= ::android::hardware::bluetooth::audio::V2_1::CodecType::LC3;
    }
    if (o != flipped) {
        os += (first ? "" : " | ");
        os += toHexString(o & (~flipped));
    }os += " (";
    os += toHexString(o);
    os += ")";
    return os;
}

static inline std::string toString(::android::hardware::bluetooth::audio::V2_1::CodecType o) {
    using ::android::hardware::details::toHexString;
    if (o == ::android::hardware::bluetooth::audio::V2_1::CodecType::UNKNOWN) {
        return "UNKNOWN";
    }
    if (o == ::android::hardware::bluetooth::audio::V2_1::CodecType::SBC) {
        return "SBC";
    }
    if (o == ::android::hardware::bluetooth::audio::V2_1::CodecType::AAC) {
        return "AAC";
    }
    if (o == ::android::hardware::bluetooth::audio::V2_1::CodecType::APTX) {
        return "APTX";
    }
    if (o == ::android::hardware::bluetooth::audio::V2_1::CodecType::APTX_HD) {
        return "APTX_HD";
    }
    if (o == ::android::hardware::bluetooth::audio::V2_1::CodecType::LDAC) {
        return "LDAC";
    }
    if (o == ::android::hardware::bluetooth::audio::V2_1::CodecType::LC3) {
        return "LC3";
    }
    std::string os;
    os += toHexString(static_cast<uint32_t>(o));
    return os;
}

static inline void PrintTo(::android::hardware::bluetooth::audio::V2_1::CodecType o, ::std::ostream* os) {
    *os << toString(o);
}

template<>
inline std::string toString<::android::hardware::bluetooth::audio::V2_1::SampleRate>(uint32_t o) {
    using ::android::hardware::details::toHexString;
    std::string os;
    ::android::hardware::hidl_bitfield<::android::hardware::bluetooth::audio::V2_1::SampleRate> flipped = 0;
    bool first = true;
    if ((o & ::android::hardware::bluetooth::audio::V2_1::SampleRate::RATE_UNKNOWN) == static_cast<uint32_t>(::android::hardware::bluetooth::audio::V2_1::SampleRate::RATE_UNKNOWN)) {
        os += (first ? "" : " | ");
        os += "RATE_UNKNOWN";
        first = false;
        flipped |= ::android::hardware::bluetooth::audio::V2_1::SampleRate::RATE_UNKNOWN;
    }
    if ((o & ::android::hardware::bluetooth::audio::V2_1::SampleRate::RATE_44100) == static_cast<uint32_t>(::android::hardware::bluetooth::audio::V2_1::SampleRate::RATE_44100)) {
        os += (first ? "" : " | ");
        os += "RATE_44100";
        first = false;
        flipped |= ::android::hardware::bluetooth::audio::V2_1::SampleRate::RATE_44100;
    }
    if ((o & ::android::hardware::bluetooth::audio::V2_1::SampleRate::RATE_48000) == static_cast<uint32_t>(::android::hardware::bluetooth::audio::V2_1::SampleRate::RATE_48000)) {
        os += (first ? "" : " | ");
        os += "RATE_48000";
        first = false;
        flipped |= ::android::hardware::bluetooth::audio::V2_1::SampleRate::RATE_48000;
    }
    if ((o & ::android::hardware::bluetooth::audio::V2_1::SampleRate::RATE_88200) == static_cast<uint32_t>(::android::hardware::bluetooth::audio::V2_1::SampleRate::RATE_88200)) {
        os += (first ? "" : " | ");
        os += "RATE_88200";
        first = false;
        flipped |= ::android::hardware::bluetooth::audio::V2_1::SampleRate::RATE_88200;
    }
    if ((o & ::android::hardware::bluetooth::audio::V2_1::SampleRate::RATE_96000) == static_cast<uint32_t>(::android::hardware::bluetooth::audio::V2_1::SampleRate::RATE_96000)) {
        os += (first ? "" : " | ");
        os += "RATE_96000";
        first = false;
        flipped |= ::android::hardware::bluetooth::audio::V2_1::SampleRate::RATE_96000;
    }
    if ((o & ::android::hardware::bluetooth::audio::V2_1::SampleRate::RATE_176400) == static_cast<uint32_t>(::android::hardware::bluetooth::audio::V2_1::SampleRate::RATE_176400)) {
        os += (first ? "" : " | ");
        os += "RATE_176400";
        first = false;
        flipped |= ::android::hardware::bluetooth::audio::V2_1::SampleRate::RATE_176400;
    }
    if ((o & ::android::hardware::bluetooth::audio::V2_1::SampleRate::RATE_192000) == static_cast<uint32_t>(::android::hardware::bluetooth::audio::V2_1::SampleRate::RATE_192000)) {
        os += (first ? "" : " | ");
        os += "RATE_192000";
        first = false;
        flipped |= ::android::hardware::bluetooth::audio::V2_1::SampleRate::RATE_192000;
    }
    if ((o & ::android::hardware::bluetooth::audio::V2_1::SampleRate::RATE_16000) == static_cast<uint32_t>(::android::hardware::bluetooth::audio::V2_1::SampleRate::RATE_16000)) {
        os += (first ? "" : " | ");
        os += "RATE_16000";
        first = false;
        flipped |= ::android::hardware::bluetooth::audio::V2_1::SampleRate::RATE_16000;
    }
    if ((o & ::android::hardware::bluetooth::audio::V2_1::SampleRate::RATE_24000) == static_cast<uint32_t>(::android::hardware::bluetooth::audio::V2_1::SampleRate::RATE_24000)) {
        os += (first ? "" : " | ");
        os += "RATE_24000";
        first = false;
        flipped |= ::android::hardware::bluetooth::audio::V2_1::SampleRate::RATE_24000;
    }
    if ((o & ::android::hardware::bluetooth::audio::V2_1::SampleRate::RATE_8000) == static_cast<uint32_t>(::android::hardware::bluetooth::audio::V2_1::SampleRate::RATE_8000)) {
        os += (first ? "" : " | ");
        os += "RATE_8000";
        first = false;
        flipped |= ::android::hardware::bluetooth::audio::V2_1::SampleRate::RATE_8000;
    }
    if ((o & ::android::hardware::bluetooth::audio::V2_1::SampleRate::RATE_32000) == static_cast<uint32_t>(::android::hardware::bluetooth::audio::V2_1::SampleRate::RATE_32000)) {
        os += (first ? "" : " | ");
        os += "RATE_32000";
        first = false;
        flipped |= ::android::hardware::bluetooth::audio::V2_1::SampleRate::RATE_32000;
    }
    if (o != flipped) {
        os += (first ? "" : " | ");
        os += toHexString(o & (~flipped));
    }os += " (";
    os += toHexString(o);
    os += ")";
    return os;
}

static inline std::string toString(::android::hardware::bluetooth::audio::V2_1::SampleRate o) {
    using ::android::hardware::details::toHexString;
    if (o == ::android::hardware::bluetooth::audio::V2_1::SampleRate::RATE_UNKNOWN) {
        return "RATE_UNKNOWN";
    }
    if (o == ::android::hardware::bluetooth::audio::V2_1::SampleRate::RATE_44100) {
        return "RATE_44100";
    }
    if (o == ::android::hardware::bluetooth::audio::V2_1::SampleRate::RATE_48000) {
        return "RATE_48000";
    }
    if (o == ::android::hardware::bluetooth::audio::V2_1::SampleRate::RATE_88200) {
        return "RATE_88200";
    }
    if (o == ::android::hardware::bluetooth::audio::V2_1::SampleRate::RATE_96000) {
        return "RATE_96000";
    }
    if (o == ::android::hardware::bluetooth::audio::V2_1::SampleRate::RATE_176400) {
        return "RATE_176400";
    }
    if (o == ::android::hardware::bluetooth::audio::V2_1::SampleRate::RATE_192000) {
        return "RATE_192000";
    }
    if (o == ::android::hardware::bluetooth::audio::V2_1::SampleRate::RATE_16000) {
        return "RATE_16000";
    }
    if (o == ::android::hardware::bluetooth::audio::V2_1::SampleRate::RATE_24000) {
        return "RATE_24000";
    }
    if (o == ::android::hardware::bluetooth::audio::V2_1::SampleRate::RATE_8000) {
        return "RATE_8000";
    }
    if (o == ::android::hardware::bluetooth::audio::V2_1::SampleRate::RATE_32000) {
        return "RATE_32000";
    }
    std::string os;
    os += toHexString(static_cast<uint32_t>(o));
    return os;
}

static inline void PrintTo(::android::hardware::bluetooth::audio::V2_1::SampleRate o, ::std::ostream* os) {
    *os << toString(o);
}

static inline std::string toString(const ::android::hardware::bluetooth::audio::V2_1::PcmParameters& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".sampleRate = ";
    os += ::android::hardware::bluetooth::audio::V2_1::toString(o.sampleRate);
    os += ", .channelMode = ";
    os += ::android::hardware::bluetooth::audio::V2_0::toString(o.channelMode);
    os += ", .bitsPerSample = ";
    os += ::android::hardware::bluetooth::audio::V2_0::toString(o.bitsPerSample);
    os += ", .dataIntervalUs = ";
    os += ::android::hardware::toString(o.dataIntervalUs);
    os += "}"; return os;
}

static inline void PrintTo(const ::android::hardware::bluetooth::audio::V2_1::PcmParameters& o, ::std::ostream* os) {
    *os << toString(o);
}

static inline bool operator==(const ::android::hardware::bluetooth::audio::V2_1::PcmParameters& lhs, const ::android::hardware::bluetooth::audio::V2_1::PcmParameters& rhs) {
    if (lhs.sampleRate != rhs.sampleRate) {
        return false;
    }
    if (lhs.channelMode != rhs.channelMode) {
        return false;
    }
    if (lhs.bitsPerSample != rhs.bitsPerSample) {
        return false;
    }
    if (lhs.dataIntervalUs != rhs.dataIntervalUs) {
        return false;
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::bluetooth::audio::V2_1::PcmParameters& lhs, const ::android::hardware::bluetooth::audio::V2_1::PcmParameters& rhs){
    return !(lhs == rhs);
}

template<>
inline std::string toString<::android::hardware::bluetooth::audio::V2_1::Lc3FrameDuration>(uint8_t o) {
    using ::android::hardware::details::toHexString;
    std::string os;
    ::android::hardware::hidl_bitfield<::android::hardware::bluetooth::audio::V2_1::Lc3FrameDuration> flipped = 0;
    bool first = true;
    if ((o & ::android::hardware::bluetooth::audio::V2_1::Lc3FrameDuration::DURATION_10000US) == static_cast<uint8_t>(::android::hardware::bluetooth::audio::V2_1::Lc3FrameDuration::DURATION_10000US)) {
        os += (first ? "" : " | ");
        os += "DURATION_10000US";
        first = false;
        flipped |= ::android::hardware::bluetooth::audio::V2_1::Lc3FrameDuration::DURATION_10000US;
    }
    if ((o & ::android::hardware::bluetooth::audio::V2_1::Lc3FrameDuration::DURATION_7500US) == static_cast<uint8_t>(::android::hardware::bluetooth::audio::V2_1::Lc3FrameDuration::DURATION_7500US)) {
        os += (first ? "" : " | ");
        os += "DURATION_7500US";
        first = false;
        flipped |= ::android::hardware::bluetooth::audio::V2_1::Lc3FrameDuration::DURATION_7500US;
    }
    if (o != flipped) {
        os += (first ? "" : " | ");
        os += toHexString(o & (~flipped));
    }os += " (";
    os += toHexString(o);
    os += ")";
    return os;
}

static inline std::string toString(::android::hardware::bluetooth::audio::V2_1::Lc3FrameDuration o) {
    using ::android::hardware::details::toHexString;
    if (o == ::android::hardware::bluetooth::audio::V2_1::Lc3FrameDuration::DURATION_10000US) {
        return "DURATION_10000US";
    }
    if (o == ::android::hardware::bluetooth::audio::V2_1::Lc3FrameDuration::DURATION_7500US) {
        return "DURATION_7500US";
    }
    std::string os;
    os += toHexString(static_cast<uint8_t>(o));
    return os;
}

static inline void PrintTo(::android::hardware::bluetooth::audio::V2_1::Lc3FrameDuration o, ::std::ostream* os) {
    *os << toString(o);
}

static inline std::string toString(const ::android::hardware::bluetooth::audio::V2_1::Lc3Parameters& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".pcmBitDepth = ";
    os += ::android::hardware::bluetooth::audio::V2_0::toString(o.pcmBitDepth);
    os += ", .samplingFrequency = ";
    os += ::android::hardware::bluetooth::audio::V2_1::toString(o.samplingFrequency);
    os += ", .frameDuration = ";
    os += ::android::hardware::bluetooth::audio::V2_1::toString(o.frameDuration);
    os += ", .octetsPerFrame = ";
    os += ::android::hardware::toString(o.octetsPerFrame);
    os += ", .blocksPerSdu = ";
    os += ::android::hardware::toString(o.blocksPerSdu);
    os += "}"; return os;
}

static inline void PrintTo(const ::android::hardware::bluetooth::audio::V2_1::Lc3Parameters& o, ::std::ostream* os) {
    *os << toString(o);
}

static inline bool operator==(const ::android::hardware::bluetooth::audio::V2_1::Lc3Parameters& lhs, const ::android::hardware::bluetooth::audio::V2_1::Lc3Parameters& rhs) {
    if (lhs.pcmBitDepth != rhs.pcmBitDepth) {
        return false;
    }
    if (lhs.samplingFrequency != rhs.samplingFrequency) {
        return false;
    }
    if (lhs.frameDuration != rhs.frameDuration) {
        return false;
    }
    if (lhs.octetsPerFrame != rhs.octetsPerFrame) {
        return false;
    }
    if (lhs.blocksPerSdu != rhs.blocksPerSdu) {
        return false;
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::bluetooth::audio::V2_1::Lc3Parameters& lhs, const ::android::hardware::bluetooth::audio::V2_1::Lc3Parameters& rhs){
    return !(lhs == rhs);
}

static inline std::string toString(const ::android::hardware::bluetooth::audio::V2_1::Lc3CodecCapabilities& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".supportedChannelCounts = ";
    os += ::android::hardware::toString(o.supportedChannelCounts);
    os += ", .lc3Capabilities = ";
    os += ::android::hardware::bluetooth::audio::V2_1::toString(o.lc3Capabilities);
    os += "}"; return os;
}

static inline void PrintTo(const ::android::hardware::bluetooth::audio::V2_1::Lc3CodecCapabilities& o, ::std::ostream* os) {
    *os << toString(o);
}

static inline bool operator==(const ::android::hardware::bluetooth::audio::V2_1::Lc3CodecCapabilities& lhs, const ::android::hardware::bluetooth::audio::V2_1::Lc3CodecCapabilities& rhs) {
    if (lhs.supportedChannelCounts != rhs.supportedChannelCounts) {
        return false;
    }
    if (lhs.lc3Capabilities != rhs.lc3Capabilities) {
        return false;
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::bluetooth::audio::V2_1::Lc3CodecCapabilities& lhs, const ::android::hardware::bluetooth::audio::V2_1::Lc3CodecCapabilities& rhs){
    return !(lhs == rhs);
}

static inline std::string toString(const ::android::hardware::bluetooth::audio::V2_1::AudioCapabilities& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";

    switch (o.getDiscriminator()) {
        case ::android::hardware::bluetooth::audio::V2_1::AudioCapabilities::hidl_discriminator::pcmCapabilities: {
            os += ".pcmCapabilities = ";
            os += toString(o.pcmCapabilities());
            break;
        }
        case ::android::hardware::bluetooth::audio::V2_1::AudioCapabilities::hidl_discriminator::codecCapabilities: {
            os += ".codecCapabilities = ";
            os += toString(o.codecCapabilities());
            break;
        }
        case ::android::hardware::bluetooth::audio::V2_1::AudioCapabilities::hidl_discriminator::leAudioCapabilities: {
            os += ".leAudioCapabilities = ";
            os += toString(o.leAudioCapabilities());
            break;
        }
        default: {
            ::android::hardware::details::logAlwaysFatal((
                    "Unknown union discriminator (value: " +
                    std::to_string((uint8_t) o.getDiscriminator()) + ").").c_str());
        }
    }
    os += "}"; return os;
}

static inline void PrintTo(const ::android::hardware::bluetooth::audio::V2_1::AudioCapabilities& o, ::std::ostream* os) {
    *os << toString(o);
}

static inline bool operator==(const ::android::hardware::bluetooth::audio::V2_1::AudioCapabilities& lhs, const ::android::hardware::bluetooth::audio::V2_1::AudioCapabilities& rhs) {
    if (lhs.getDiscriminator() != rhs.getDiscriminator()) {
        return false;
    }
    switch (lhs.getDiscriminator()) {
        case ::android::hardware::bluetooth::audio::V2_1::AudioCapabilities::hidl_discriminator::pcmCapabilities: {
            return (lhs.pcmCapabilities() == rhs.pcmCapabilities());
        }
        case ::android::hardware::bluetooth::audio::V2_1::AudioCapabilities::hidl_discriminator::codecCapabilities: {
            return (lhs.codecCapabilities() == rhs.codecCapabilities());
        }
        case ::android::hardware::bluetooth::audio::V2_1::AudioCapabilities::hidl_discriminator::leAudioCapabilities: {
            return (lhs.leAudioCapabilities() == rhs.leAudioCapabilities());
        }
        default: {
            ::android::hardware::details::logAlwaysFatal((
                    "Unknown union discriminator (value: " +
                    std::to_string((uint8_t) lhs.getDiscriminator()) + ").").c_str());
        }
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::bluetooth::audio::V2_1::AudioCapabilities& lhs, const ::android::hardware::bluetooth::audio::V2_1::AudioCapabilities& rhs){
    return !(lhs == rhs);
}

static inline std::string toString(const ::android::hardware::bluetooth::audio::V2_1::Lc3CodecConfiguration& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".audioChannelAllocation = ";
    os += ::android::hardware::toString(o.audioChannelAllocation);
    os += ", .lc3Config = ";
    os += ::android::hardware::bluetooth::audio::V2_1::toString(o.lc3Config);
    os += "}"; return os;
}

static inline void PrintTo(const ::android::hardware::bluetooth::audio::V2_1::Lc3CodecConfiguration& o, ::std::ostream* os) {
    *os << toString(o);
}

static inline bool operator==(const ::android::hardware::bluetooth::audio::V2_1::Lc3CodecConfiguration& lhs, const ::android::hardware::bluetooth::audio::V2_1::Lc3CodecConfiguration& rhs) {
    if (lhs.audioChannelAllocation != rhs.audioChannelAllocation) {
        return false;
    }
    if (lhs.lc3Config != rhs.lc3Config) {
        return false;
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::bluetooth::audio::V2_1::Lc3CodecConfiguration& lhs, const ::android::hardware::bluetooth::audio::V2_1::Lc3CodecConfiguration& rhs){
    return !(lhs == rhs);
}

static inline std::string toString(const ::android::hardware::bluetooth::audio::V2_1::AudioConfiguration& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";

    switch (o.getDiscriminator()) {
        case ::android::hardware::bluetooth::audio::V2_1::AudioConfiguration::hidl_discriminator::pcmConfig: {
            os += ".pcmConfig = ";
            os += toString(o.pcmConfig());
            break;
        }
        case ::android::hardware::bluetooth::audio::V2_1::AudioConfiguration::hidl_discriminator::codecConfig: {
            os += ".codecConfig = ";
            os += toString(o.codecConfig());
            break;
        }
        case ::android::hardware::bluetooth::audio::V2_1::AudioConfiguration::hidl_discriminator::leAudioCodecConfig: {
            os += ".leAudioCodecConfig = ";
            os += toString(o.leAudioCodecConfig());
            break;
        }
        default: {
            ::android::hardware::details::logAlwaysFatal((
                    "Unknown union discriminator (value: " +
                    std::to_string((uint8_t) o.getDiscriminator()) + ").").c_str());
        }
    }
    os += "}"; return os;
}

static inline void PrintTo(const ::android::hardware::bluetooth::audio::V2_1::AudioConfiguration& o, ::std::ostream* os) {
    *os << toString(o);
}

static inline bool operator==(const ::android::hardware::bluetooth::audio::V2_1::AudioConfiguration& lhs, const ::android::hardware::bluetooth::audio::V2_1::AudioConfiguration& rhs) {
    if (lhs.getDiscriminator() != rhs.getDiscriminator()) {
        return false;
    }
    switch (lhs.getDiscriminator()) {
        case ::android::hardware::bluetooth::audio::V2_1::AudioConfiguration::hidl_discriminator::pcmConfig: {
            return (lhs.pcmConfig() == rhs.pcmConfig());
        }
        case ::android::hardware::bluetooth::audio::V2_1::AudioConfiguration::hidl_discriminator::codecConfig: {
            return (lhs.codecConfig() == rhs.codecConfig());
        }
        case ::android::hardware::bluetooth::audio::V2_1::AudioConfiguration::hidl_discriminator::leAudioCodecConfig: {
            return (lhs.leAudioCodecConfig() == rhs.leAudioCodecConfig());
        }
        default: {
            ::android::hardware::details::logAlwaysFatal((
                    "Unknown union discriminator (value: " +
                    std::to_string((uint8_t) lhs.getDiscriminator()) + ").").c_str());
        }
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::bluetooth::audio::V2_1::AudioConfiguration& lhs, const ::android::hardware::bluetooth::audio::V2_1::AudioConfiguration& rhs){
    return !(lhs == rhs);
}


}  // namespace V2_1
}  // namespace audio
}  // namespace bluetooth
}  // namespace hardware
}  // namespace android

//
// global type declarations for package
//

namespace android {
namespace hardware {
namespace details {
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wc++17-extensions"
template<> inline constexpr std::array<::android::hardware::bluetooth::audio::V2_1::SessionType, 8> hidl_enum_values<::android::hardware::bluetooth::audio::V2_1::SessionType> = {
    ::android::hardware::bluetooth::audio::V2_1::SessionType::UNKNOWN,
    ::android::hardware::bluetooth::audio::V2_1::SessionType::A2DP_SOFTWARE_ENCODING_DATAPATH,
    ::android::hardware::bluetooth::audio::V2_1::SessionType::A2DP_HARDWARE_OFFLOAD_DATAPATH,
    ::android::hardware::bluetooth::audio::V2_1::SessionType::HEARING_AID_SOFTWARE_ENCODING_DATAPATH,
    ::android::hardware::bluetooth::audio::V2_1::SessionType::LE_AUDIO_SOFTWARE_ENCODING_DATAPATH,
    ::android::hardware::bluetooth::audio::V2_1::SessionType::LE_AUDIO_SOFTWARE_DECODED_DATAPATH,
    ::android::hardware::bluetooth::audio::V2_1::SessionType::LE_AUDIO_HARDWARE_OFFLOAD_ENCODING_DATAPATH,
    ::android::hardware::bluetooth::audio::V2_1::SessionType::LE_AUDIO_HARDWARE_OFFLOAD_DECODING_DATAPATH,
};
#pragma clang diagnostic pop
}  // namespace details
}  // namespace hardware
}  // namespace android

namespace android {
namespace hardware {
namespace details {
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wc++17-extensions"
template<> inline constexpr std::array<::android::hardware::bluetooth::audio::V2_1::CodecType, 7> hidl_enum_values<::android::hardware::bluetooth::audio::V2_1::CodecType> = {
    ::android::hardware::bluetooth::audio::V2_1::CodecType::UNKNOWN,
    ::android::hardware::bluetooth::audio::V2_1::CodecType::SBC,
    ::android::hardware::bluetooth::audio::V2_1::CodecType::AAC,
    ::android::hardware::bluetooth::audio::V2_1::CodecType::APTX,
    ::android::hardware::bluetooth::audio::V2_1::CodecType::APTX_HD,
    ::android::hardware::bluetooth::audio::V2_1::CodecType::LDAC,
    ::android::hardware::bluetooth::audio::V2_1::CodecType::LC3,
};
#pragma clang diagnostic pop
}  // namespace details
}  // namespace hardware
}  // namespace android

namespace android {
namespace hardware {
namespace details {
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wc++17-extensions"
template<> inline constexpr std::array<::android::hardware::bluetooth::audio::V2_1::SampleRate, 11> hidl_enum_values<::android::hardware::bluetooth::audio::V2_1::SampleRate> = {
    ::android::hardware::bluetooth::audio::V2_1::SampleRate::RATE_UNKNOWN,
    ::android::hardware::bluetooth::audio::V2_1::SampleRate::RATE_44100,
    ::android::hardware::bluetooth::audio::V2_1::SampleRate::RATE_48000,
    ::android::hardware::bluetooth::audio::V2_1::SampleRate::RATE_88200,
    ::android::hardware::bluetooth::audio::V2_1::SampleRate::RATE_96000,
    ::android::hardware::bluetooth::audio::V2_1::SampleRate::RATE_176400,
    ::android::hardware::bluetooth::audio::V2_1::SampleRate::RATE_192000,
    ::android::hardware::bluetooth::audio::V2_1::SampleRate::RATE_16000,
    ::android::hardware::bluetooth::audio::V2_1::SampleRate::RATE_24000,
    ::android::hardware::bluetooth::audio::V2_1::SampleRate::RATE_8000,
    ::android::hardware::bluetooth::audio::V2_1::SampleRate::RATE_32000,
};
#pragma clang diagnostic pop
}  // namespace details
}  // namespace hardware
}  // namespace android

namespace android {
namespace hardware {
namespace details {
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wc++17-extensions"
template<> inline constexpr std::array<::android::hardware::bluetooth::audio::V2_1::Lc3FrameDuration, 2> hidl_enum_values<::android::hardware::bluetooth::audio::V2_1::Lc3FrameDuration> = {
    ::android::hardware::bluetooth::audio::V2_1::Lc3FrameDuration::DURATION_10000US,
    ::android::hardware::bluetooth::audio::V2_1::Lc3FrameDuration::DURATION_7500US,
};
#pragma clang diagnostic pop
}  // namespace details
}  // namespace hardware
}  // namespace android


#endif  // HIDL_GENERATED_ANDROID_HARDWARE_BLUETOOTH_AUDIO_V2_1_TYPES_H
