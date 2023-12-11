#ifndef HIDL_GENERATED_ANDROID_HARDWARE_AUDIO_COMMON_V7_0_TYPES_H
#define HIDL_GENERATED_ANDROID_HARDWARE_AUDIO_COMMON_V7_0_TYPES_H

#include <android/hidl/safe_union/1.0/types.h>

#include <hidl/HidlSupport.h>
#include <hidl/MQDescriptor.h>
#include <utils/NativeHandle.h>
#include <utils/misc.h>

namespace android {
namespace hardware {
namespace audio {
namespace common {
namespace V7_0 {

// Forward declaration for forward reference support:
struct Uuid;
enum class AudioSessionConsts : int32_t;
struct AudioConfigBase;
struct AudioConfigBaseOptional;
struct AudioProfile;
struct AudioTransport;
enum class AudioMode : int32_t;
struct DeviceAddress;
enum class AudioEncapsulationMode : int32_t;
enum class AudioEncapsulationMetadataType : int32_t;
struct AudioOffloadInfo;
struct AudioConfig;
struct PlaybackTrackMetadata;
struct SourceMetadata;
struct RecordTrackMetadata;
struct SinkMetadata;
struct AudioGain;
struct AudioGainConfig;
struct AudioPortExtendedInfo;
struct AudioPortConfig;
struct AudioPort;

/**
 * Handle type for identifying audio resources. Handles are allocated by the framework.
 */
typedef int32_t AudioIoHandle;

/**
 * Each port has a unique ID or handle allocated by policy manager.
 */
typedef int32_t AudioPortHandle;

/**
 * Each patch is identified by a handle allocated by the HAL.
 */
typedef int32_t AudioPatchHandle;

/**
 * A HW synchronization source returned by the audio HAL.
 */
typedef uint32_t AudioHwSync;

/**
 * Commonly used structure for passing unique identifieds (UUID).
 * For the definition of UUID, refer to ITU-T X.667 spec.
 */
struct Uuid final {
    uint32_t timeLow __attribute__ ((aligned(4)));
    uint16_t timeMid __attribute__ ((aligned(2)));
    uint16_t versionAndTimeHigh __attribute__ ((aligned(2)));
    uint16_t variantAndClockSeqHigh __attribute__ ((aligned(2)));
    ::android::hardware::hidl_array<uint8_t, 6> node __attribute__ ((aligned(1)));
};

static_assert(offsetof(::android::hardware::audio::common::V7_0::Uuid, timeLow) == 0, "wrong offset");
static_assert(offsetof(::android::hardware::audio::common::V7_0::Uuid, timeMid) == 4, "wrong offset");
static_assert(offsetof(::android::hardware::audio::common::V7_0::Uuid, versionAndTimeHigh) == 6, "wrong offset");
static_assert(offsetof(::android::hardware::audio::common::V7_0::Uuid, variantAndClockSeqHigh) == 8, "wrong offset");
static_assert(offsetof(::android::hardware::audio::common::V7_0::Uuid, node) == 10, "wrong offset");
static_assert(sizeof(::android::hardware::audio::common::V7_0::Uuid) == 16, "wrong size");
static_assert(__alignof(::android::hardware::audio::common::V7_0::Uuid) == 4, "wrong alignment");

/*
 *  Audio streams
 *
 *
 *
 * Audio stream type describing the intended use case of a stream.
 * See 'audioStreamType' in audio_policy_configuration.xsd for the
 * list of allowed values.
 *
 * An empty string is used to specify the "default" stream type.
 */
typedef ::android::hardware::hidl_string AudioStreamType;

/**
 * An audio source defines the intended use case for the sound being recorded.
 * See 'audioSource' in audio_policy_configuration.xsd for the
 * list of allowed values.
 */
typedef ::android::hardware::hidl_string AudioSource;

/**
 * An audio session identifier is used to designate the particular
 * playback or recording session (e.g. playback performed by a certain
 * application).
 */
typedef int32_t AudioSession;

enum class AudioSessionConsts : int32_t {
    /**
     * Session for effects attached to a particular sink or source audio device
     * (e.g an effect only applied to a speaker)
     */
    DEVICE = -2 /* -2 */,
    /**
     * Session for effects attached to a particular output stream
     * (value must be less than 0)
     */
    OUTPUT_STAGE = -1 /* -1 */,
    /**
     * Session for effects applied to output mix. These effects can
     * be moved by audio policy manager to another output stream
     * (value must be 0)
     */
    OUTPUT_MIX = 0,
};

/**
 * Audio format indicates audio codec type.
 * See 'audioFormat' in audio_policy_configuration.xsd for the
 * list of allowed values.
 */
typedef ::android::hardware::hidl_string AudioFormat;

/**
 * Audio channel mask indicates presence of particular channels.
 * Note that every value is already a mask comprised of individual
 * channels.
 * See 'audioChannelMask' in audio_policy_configuration.xsd for the
 * list of allowed values.
 */
typedef ::android::hardware::hidl_string AudioChannelMask;

/**
 * Base configuration attributes applicable to any stream of audio.
 */
struct AudioConfigBase final {
    ::android::hardware::hidl_string format __attribute__ ((aligned(8)));
    uint32_t sampleRateHz __attribute__ ((aligned(4)));
    ::android::hardware::hidl_string channelMask __attribute__ ((aligned(8)));
};

static_assert(offsetof(::android::hardware::audio::common::V7_0::AudioConfigBase, format) == 0, "wrong offset");
static_assert(offsetof(::android::hardware::audio::common::V7_0::AudioConfigBase, sampleRateHz) == 16, "wrong offset");
static_assert(offsetof(::android::hardware::audio::common::V7_0::AudioConfigBase, channelMask) == 24, "wrong offset");
static_assert(sizeof(::android::hardware::audio::common::V7_0::AudioConfigBase) == 40, "wrong size");
static_assert(__alignof(::android::hardware::audio::common::V7_0::AudioConfigBase) == 8, "wrong alignment");

/**
 * Base configuration attributes applicable to any stream of audio.
 * Any attribute may be left unspecified.
 */
struct AudioConfigBaseOptional final {
    // Forward declaration for forward reference support:
    struct Format;
    struct SampleRate;
    struct ChannelMask;

    struct Format final {
        enum class hidl_discriminator : uint8_t {
            unspecified = 0,  // ::android::hidl::safe_union::V1_0::Monostate
            value = 1,  // ::android::hardware::hidl_string
        };

        Format();
        ~Format();
        Format(Format&&);
        Format(const Format&);
        Format& operator=(Format&&);
        Format& operator=(const Format&);

        void unspecified(const ::android::hidl::safe_union::V1_0::Monostate&);
        void unspecified(::android::hidl::safe_union::V1_0::Monostate&&);
        ::android::hidl::safe_union::V1_0::Monostate& unspecified();
        const ::android::hidl::safe_union::V1_0::Monostate& unspecified() const;

        void value(const ::android::hardware::hidl_string&);
        void value(::android::hardware::hidl_string&&);
        ::android::hardware::hidl_string& value();
        const ::android::hardware::hidl_string& value() const;

        // Utility methods
        hidl_discriminator getDiscriminator() const;

        constexpr size_t hidl_getUnionOffset() const {
            return offsetof(::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::Format, hidl_u);
        }

    private:
        void hidl_destructUnion();

        hidl_discriminator hidl_d __attribute__ ((aligned(1))) ;
        union hidl_union final {
            ::android::hidl::safe_union::V1_0::Monostate unspecified __attribute__ ((aligned(1)));
            ::android::hardware::hidl_string value __attribute__ ((aligned(8)));

            hidl_union();
            ~hidl_union();
        } hidl_u;

        static_assert(sizeof(::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::Format::hidl_union) == 16, "wrong size");
        static_assert(__alignof(::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::Format::hidl_union) == 8, "wrong alignment");
        static_assert(sizeof(::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::Format::hidl_discriminator) == 1, "wrong size");
        static_assert(__alignof(::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::Format::hidl_discriminator) == 1, "wrong alignment");
    };

    static_assert(sizeof(::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::Format) == 24, "wrong size");
    static_assert(__alignof(::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::Format) == 8, "wrong alignment");

    struct SampleRate final {
        enum class hidl_discriminator : uint8_t {
            unspecified = 0,  // ::android::hidl::safe_union::V1_0::Monostate
            value = 1,  // uint32_t
        };

        SampleRate();
        ~SampleRate();
        SampleRate(SampleRate&&);
        SampleRate(const SampleRate&);
        SampleRate& operator=(SampleRate&&);
        SampleRate& operator=(const SampleRate&);

        void unspecified(const ::android::hidl::safe_union::V1_0::Monostate&);
        void unspecified(::android::hidl::safe_union::V1_0::Monostate&&);
        ::android::hidl::safe_union::V1_0::Monostate& unspecified();
        const ::android::hidl::safe_union::V1_0::Monostate& unspecified() const;

        void value(uint32_t);
        uint32_t& value();
        uint32_t value() const;

        // Utility methods
        hidl_discriminator getDiscriminator() const;

        constexpr size_t hidl_getUnionOffset() const {
            return offsetof(::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::SampleRate, hidl_u);
        }

    private:
        void hidl_destructUnion();

        hidl_discriminator hidl_d __attribute__ ((aligned(1))) ;
        union hidl_union final {
            ::android::hidl::safe_union::V1_0::Monostate unspecified __attribute__ ((aligned(1)));
            uint32_t value __attribute__ ((aligned(4)));

            hidl_union();
            ~hidl_union();
        } hidl_u;

        static_assert(sizeof(::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::SampleRate::hidl_union) == 4, "wrong size");
        static_assert(__alignof(::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::SampleRate::hidl_union) == 4, "wrong alignment");
        static_assert(sizeof(::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::SampleRate::hidl_discriminator) == 1, "wrong size");
        static_assert(__alignof(::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::SampleRate::hidl_discriminator) == 1, "wrong alignment");
    };

    static_assert(sizeof(::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::SampleRate) == 8, "wrong size");
    static_assert(__alignof(::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::SampleRate) == 4, "wrong alignment");

    struct ChannelMask final {
        enum class hidl_discriminator : uint8_t {
            unspecified = 0,  // ::android::hidl::safe_union::V1_0::Monostate
            value = 1,  // ::android::hardware::hidl_string
        };

        ChannelMask();
        ~ChannelMask();
        ChannelMask(ChannelMask&&);
        ChannelMask(const ChannelMask&);
        ChannelMask& operator=(ChannelMask&&);
        ChannelMask& operator=(const ChannelMask&);

        void unspecified(const ::android::hidl::safe_union::V1_0::Monostate&);
        void unspecified(::android::hidl::safe_union::V1_0::Monostate&&);
        ::android::hidl::safe_union::V1_0::Monostate& unspecified();
        const ::android::hidl::safe_union::V1_0::Monostate& unspecified() const;

        void value(const ::android::hardware::hidl_string&);
        void value(::android::hardware::hidl_string&&);
        ::android::hardware::hidl_string& value();
        const ::android::hardware::hidl_string& value() const;

        // Utility methods
        hidl_discriminator getDiscriminator() const;

        constexpr size_t hidl_getUnionOffset() const {
            return offsetof(::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::ChannelMask, hidl_u);
        }

    private:
        void hidl_destructUnion();

        hidl_discriminator hidl_d __attribute__ ((aligned(1))) ;
        union hidl_union final {
            ::android::hidl::safe_union::V1_0::Monostate unspecified __attribute__ ((aligned(1)));
            ::android::hardware::hidl_string value __attribute__ ((aligned(8)));

            hidl_union();
            ~hidl_union();
        } hidl_u;

        static_assert(sizeof(::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::ChannelMask::hidl_union) == 16, "wrong size");
        static_assert(__alignof(::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::ChannelMask::hidl_union) == 8, "wrong alignment");
        static_assert(sizeof(::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::ChannelMask::hidl_discriminator) == 1, "wrong size");
        static_assert(__alignof(::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::ChannelMask::hidl_discriminator) == 1, "wrong alignment");
    };

    static_assert(sizeof(::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::ChannelMask) == 24, "wrong size");
    static_assert(__alignof(::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::ChannelMask) == 8, "wrong alignment");

    ::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::Format format __attribute__ ((aligned(8)));
    ::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::SampleRate sampleRateHz __attribute__ ((aligned(4)));
    ::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::ChannelMask channelMask __attribute__ ((aligned(8)));
};

static_assert(offsetof(::android::hardware::audio::common::V7_0::AudioConfigBaseOptional, format) == 0, "wrong offset");
static_assert(offsetof(::android::hardware::audio::common::V7_0::AudioConfigBaseOptional, sampleRateHz) == 24, "wrong offset");
static_assert(offsetof(::android::hardware::audio::common::V7_0::AudioConfigBaseOptional, channelMask) == 32, "wrong offset");
static_assert(sizeof(::android::hardware::audio::common::V7_0::AudioConfigBaseOptional) == 56, "wrong size");
static_assert(__alignof(::android::hardware::audio::common::V7_0::AudioConfigBaseOptional) == 8, "wrong alignment");

/**
 * Audio encapsulation type indicates the encapsulation type that is required
 * for playback/capture.
 * See 'audioEncapsulationType' in audio_policy_configuration.xsd for the list
 * of allowed values.
 */
typedef ::android::hardware::hidl_string AudioEncapsulationType;

/**
 * Configurations supported for a certain audio format.
 */
struct AudioProfile final {
    ::android::hardware::hidl_string format __attribute__ ((aligned(8)));
    /**
     * List of the sample rates (in Hz) supported by the profile.
     */
    ::android::hardware::hidl_vec<uint32_t> sampleRates __attribute__ ((aligned(8)));
    /**
     * List of channel masks supported by the profile.
     */
    ::android::hardware::hidl_vec<::android::hardware::hidl_string> channelMasks __attribute__ ((aligned(8)));
};

static_assert(offsetof(::android::hardware::audio::common::V7_0::AudioProfile, format) == 0, "wrong offset");
static_assert(offsetof(::android::hardware::audio::common::V7_0::AudioProfile, sampleRates) == 16, "wrong offset");
static_assert(offsetof(::android::hardware::audio::common::V7_0::AudioProfile, channelMasks) == 32, "wrong offset");
static_assert(sizeof(::android::hardware::audio::common::V7_0::AudioProfile) == 48, "wrong size");
static_assert(__alignof(::android::hardware::audio::common::V7_0::AudioProfile) == 8, "wrong alignment");

/**
 * AudioTransport struct describes the capability of an audio port. The
 * capability is described via AudioProfile or raw hardware descriptors for
 * for formats that are not supported by the platform.
 */
struct AudioTransport final {
    // Forward declaration for forward reference support:
    struct AudioCapability;

    struct AudioCapability final {
        enum class hidl_discriminator : uint8_t {
            /**
             * A certain audio format that is known by the platform and its
             * corresponding configuration.
             */
            profile = 0,  // ::android::hardware::audio::common::V7_0::AudioProfile
            /**
             * The audio descriptor that is reported from EDID. See HDMI
             * specification 1.4b section 7 and CEA-861-G section 7.5.2 for more
             * information. When this value is set, it indicates the standard is
             * AUDIO_STANDARD_EDID.
             */
            edid = 1,  // ::android::hardware::hidl_vec<uint8_t>
        };

        AudioCapability();
        ~AudioCapability();
        AudioCapability(AudioCapability&&);
        AudioCapability(const AudioCapability&);
        AudioCapability& operator=(AudioCapability&&);
        AudioCapability& operator=(const AudioCapability&);

        void profile(const ::android::hardware::audio::common::V7_0::AudioProfile&);
        void profile(::android::hardware::audio::common::V7_0::AudioProfile&&);
        ::android::hardware::audio::common::V7_0::AudioProfile& profile();
        const ::android::hardware::audio::common::V7_0::AudioProfile& profile() const;

        void edid(const ::android::hardware::hidl_vec<uint8_t>&);
        void edid(::android::hardware::hidl_vec<uint8_t>&&);
        ::android::hardware::hidl_vec<uint8_t>& edid();
        const ::android::hardware::hidl_vec<uint8_t>& edid() const;

        // Utility methods
        hidl_discriminator getDiscriminator() const;

        constexpr size_t hidl_getUnionOffset() const {
            return offsetof(::android::hardware::audio::common::V7_0::AudioTransport::AudioCapability, hidl_u);
        }

    private:
        void hidl_destructUnion();

        hidl_discriminator hidl_d __attribute__ ((aligned(1))) ;
        union hidl_union final {
            ::android::hardware::audio::common::V7_0::AudioProfile profile __attribute__ ((aligned(8)));
            ::android::hardware::hidl_vec<uint8_t> edid __attribute__ ((aligned(8)));

            hidl_union();
            ~hidl_union();
        } hidl_u;

        static_assert(sizeof(::android::hardware::audio::common::V7_0::AudioTransport::AudioCapability::hidl_union) == 48, "wrong size");
        static_assert(__alignof(::android::hardware::audio::common::V7_0::AudioTransport::AudioCapability::hidl_union) == 8, "wrong alignment");
        static_assert(sizeof(::android::hardware::audio::common::V7_0::AudioTransport::AudioCapability::hidl_discriminator) == 1, "wrong size");
        static_assert(__alignof(::android::hardware::audio::common::V7_0::AudioTransport::AudioCapability::hidl_discriminator) == 1, "wrong alignment");
    };

    static_assert(sizeof(::android::hardware::audio::common::V7_0::AudioTransport::AudioCapability) == 56, "wrong size");
    static_assert(__alignof(::android::hardware::audio::common::V7_0::AudioTransport::AudioCapability) == 8, "wrong alignment");

    ::android::hardware::audio::common::V7_0::AudioTransport::AudioCapability audioCapability __attribute__ ((aligned(8)));
    /**
     * The encapsulation type that is required when the framework is using this
     * format when playing or capturing to/from a stream or device exposing this
     * audio transport.
     */
    ::android::hardware::hidl_string encapsulationType __attribute__ ((aligned(8)));
};

static_assert(offsetof(::android::hardware::audio::common::V7_0::AudioTransport, audioCapability) == 0, "wrong offset");
static_assert(offsetof(::android::hardware::audio::common::V7_0::AudioTransport, encapsulationType) == 56, "wrong offset");
static_assert(sizeof(::android::hardware::audio::common::V7_0::AudioTransport) == 72, "wrong size");
static_assert(__alignof(::android::hardware::audio::common::V7_0::AudioTransport) == 8, "wrong alignment");

/**
 * Major modes for a mobile device. The current mode setting affects audio
 * routing.
 */
enum class AudioMode : int32_t {
    NORMAL = 0,
    RINGTONE = 1,
    /**
     * Calls handled by the telephony stack (Eg: PSTN).
     */
    IN_CALL = 2,
    /**
     * Calls handled by apps (Eg: Hangout).
     */
    IN_COMMUNICATION = 3,
    /**
     * Call screening in progress.
     */
    CALL_SCREEN = 4,
};

/**
 * Audio device specifies type (or category) of audio I/O device
 * (e.g. speaker or headphones).
 * See 'audioDevice' in audio_policy_configuration.xsd for the
 * list of allowed values.
 */
typedef ::android::hardware::hidl_string AudioDevice;

/**
 * Specifies a device address in case when several devices of the same type
 * can be connected (e.g. BT A2DP, USB).
 */
struct DeviceAddress final {
    // Forward declaration for forward reference support:
    struct Address;

    struct Address final {
        // Forward declaration for forward reference support:
        struct Alsa;

        struct Alsa final {
            int32_t card __attribute__ ((aligned(4)));
            int32_t device __attribute__ ((aligned(4)));
        };

        static_assert(offsetof(::android::hardware::audio::common::V7_0::DeviceAddress::Address::Alsa, card) == 0, "wrong offset");
        static_assert(offsetof(::android::hardware::audio::common::V7_0::DeviceAddress::Address::Alsa, device) == 4, "wrong offset");
        static_assert(sizeof(::android::hardware::audio::common::V7_0::DeviceAddress::Address::Alsa) == 8, "wrong size");
        static_assert(__alignof(::android::hardware::audio::common::V7_0::DeviceAddress::Address::Alsa) == 4, "wrong alignment");

        enum class hidl_discriminator : uint8_t {
            /**
             * String uniquely identifying the device among other devices
             * of the same type. Can be empty in case there is only one device
             * of this type.
             *
             * Depending on the device type, its id may be assigned by the framework
             * (this is done for REMOTE_SUBMIX), or specified in the audio policy
             * configuration file (typically done for BUS devices), or assigned
             * by the HAL service. In any case, both framework and HAL must
             * never attempt to parse the value of the id. If the address must
             * be parsed, one of the members below must be used instead of 'id'.
             */
            id = 0,  // ::android::hardware::hidl_string
            /**
             * IEEE 802 MAC address. Set for Bluetooth devices.
             */
            mac = 1,  // ::android::hardware::hidl_array<uint8_t, 6>
            /**
             * IPv4 Address. Set for IPv4 devices.
             */
            ipv4 = 2,  // ::android::hardware::hidl_array<uint8_t, 4>
            /**
             * IPv6 Address. Set for IPv6 devices.
             */
            ipv6 = 3,  // ::android::hardware::hidl_array<uint16_t, 8>
            /**
             * PCI bus Address. Set for USB devices.
             */
            alsa = 4,  // ::android::hardware::audio::common::V7_0::DeviceAddress::Address::Alsa
        };

        Address();
        ~Address();
        Address(Address&&);
        Address(const Address&);
        Address& operator=(Address&&);
        Address& operator=(const Address&);

        void id(const ::android::hardware::hidl_string&);
        void id(::android::hardware::hidl_string&&);
        ::android::hardware::hidl_string& id();
        const ::android::hardware::hidl_string& id() const;

        void mac(const ::android::hardware::hidl_array<uint8_t, 6>&);
        void mac(::android::hardware::hidl_array<uint8_t, 6>&&);
        ::android::hardware::hidl_array<uint8_t, 6>& mac();
        const ::android::hardware::hidl_array<uint8_t, 6>& mac() const;

        void ipv4(const ::android::hardware::hidl_array<uint8_t, 4>&);
        void ipv4(::android::hardware::hidl_array<uint8_t, 4>&&);
        ::android::hardware::hidl_array<uint8_t, 4>& ipv4();
        const ::android::hardware::hidl_array<uint8_t, 4>& ipv4() const;

        void ipv6(const ::android::hardware::hidl_array<uint16_t, 8>&);
        void ipv6(::android::hardware::hidl_array<uint16_t, 8>&&);
        ::android::hardware::hidl_array<uint16_t, 8>& ipv6();
        const ::android::hardware::hidl_array<uint16_t, 8>& ipv6() const;

        void alsa(const ::android::hardware::audio::common::V7_0::DeviceAddress::Address::Alsa&);
        void alsa(::android::hardware::audio::common::V7_0::DeviceAddress::Address::Alsa&&);
        ::android::hardware::audio::common::V7_0::DeviceAddress::Address::Alsa& alsa();
        const ::android::hardware::audio::common::V7_0::DeviceAddress::Address::Alsa& alsa() const;

        // Utility methods
        hidl_discriminator getDiscriminator() const;

        constexpr size_t hidl_getUnionOffset() const {
            return offsetof(::android::hardware::audio::common::V7_0::DeviceAddress::Address, hidl_u);
        }

    private:
        void hidl_destructUnion();

        hidl_discriminator hidl_d __attribute__ ((aligned(1))) ;
        union hidl_union final {
            ::android::hardware::hidl_string id __attribute__ ((aligned(8)));
            ::android::hardware::hidl_array<uint8_t, 6> mac __attribute__ ((aligned(1)));
            ::android::hardware::hidl_array<uint8_t, 4> ipv4 __attribute__ ((aligned(1)));
            ::android::hardware::hidl_array<uint16_t, 8> ipv6 __attribute__ ((aligned(2)));
            ::android::hardware::audio::common::V7_0::DeviceAddress::Address::Alsa alsa __attribute__ ((aligned(4)));

            hidl_union();
            ~hidl_union();
        } hidl_u;

        static_assert(sizeof(::android::hardware::audio::common::V7_0::DeviceAddress::Address::hidl_union) == 16, "wrong size");
        static_assert(__alignof(::android::hardware::audio::common::V7_0::DeviceAddress::Address::hidl_union) == 8, "wrong alignment");
        static_assert(sizeof(::android::hardware::audio::common::V7_0::DeviceAddress::Address::hidl_discriminator) == 1, "wrong size");
        static_assert(__alignof(::android::hardware::audio::common::V7_0::DeviceAddress::Address::hidl_discriminator) == 1, "wrong alignment");
    };

    static_assert(sizeof(::android::hardware::audio::common::V7_0::DeviceAddress::Address) == 24, "wrong size");
    static_assert(__alignof(::android::hardware::audio::common::V7_0::DeviceAddress::Address) == 8, "wrong alignment");

    /**
     * The type of the device.
     */
    ::android::hardware::hidl_string deviceType __attribute__ ((aligned(8)));
    ::android::hardware::audio::common::V7_0::DeviceAddress::Address address __attribute__ ((aligned(8)));
};

static_assert(offsetof(::android::hardware::audio::common::V7_0::DeviceAddress, deviceType) == 0, "wrong offset");
static_assert(offsetof(::android::hardware::audio::common::V7_0::DeviceAddress, address) == 16, "wrong offset");
static_assert(sizeof(::android::hardware::audio::common::V7_0::DeviceAddress) == 40, "wrong size");
static_assert(__alignof(::android::hardware::audio::common::V7_0::DeviceAddress) == 8, "wrong alignment");

/**
 * Audio usage specifies the intended use case for the sound being played.
 * See 'audioUsage' in audio_policy_configuration.xsd for the
 * list of allowed values.
 */
typedef ::android::hardware::hidl_string AudioUsage;

/**
 * Audio content type expresses the general category of the content.
 * See 'audioContentType' in audio_policy_configuration.xsd for the
 * list of allowed values.
 */
typedef ::android::hardware::hidl_string AudioContentType;

/**
 * Encapsulation mode used for sending audio compressed data.
 */
enum class AudioEncapsulationMode : int32_t {
    /**
     * No encapsulation mode for metadata.
     */
    NONE = 0,
    /**
     * Elementary stream payload with metadata
     */
    ELEMENTARY_STREAM = 1,
    /**
     *  Handle-based payload with metadata
     */
    HANDLE = 2,
};

/**
 * Enumeration of metadata types permitted for use by
 * encapsulation mode audio streams.
 */
enum class AudioEncapsulationMetadataType : int32_t {
    /**
     * No metadata.
     */
    NONE = 0,
    /**
     * Encapsulation metadata type for framework tuner information.
     */
    FRAMEWORK_TUNER = 1,
    /**
     * Encapsulation metadata type for DVB AD descriptor.
     * This metadata is formatted per ETSI TS 101 154 Table E.1: AD_descriptor.
     */
    DVB_AD_DESCRIPTOR = 2,
};

/**
 * Additional information about the stream passed to hardware decoders.
 */
struct AudioOffloadInfo final {
    ::android::hardware::audio::common::V7_0::AudioConfigBase base __attribute__ ((aligned(8)));
    ::android::hardware::hidl_string streamType __attribute__ ((aligned(8)));
    uint32_t bitRatePerSecond __attribute__ ((aligned(4)));
    int64_t durationMicroseconds __attribute__ ((aligned(8)));
    bool hasVideo __attribute__ ((aligned(1)));
    bool isStreaming __attribute__ ((aligned(1)));
    uint32_t bitWidth __attribute__ ((aligned(4)));
    uint32_t bufferSize __attribute__ ((aligned(4)));
    ::android::hardware::hidl_string usage __attribute__ ((aligned(8)));
    ::android::hardware::audio::common::V7_0::AudioEncapsulationMode encapsulationMode __attribute__ ((aligned(4)));
    int32_t contentId __attribute__ ((aligned(4)));
    int32_t syncId __attribute__ ((aligned(4)));
};

static_assert(offsetof(::android::hardware::audio::common::V7_0::AudioOffloadInfo, base) == 0, "wrong offset");
static_assert(offsetof(::android::hardware::audio::common::V7_0::AudioOffloadInfo, streamType) == 40, "wrong offset");
static_assert(offsetof(::android::hardware::audio::common::V7_0::AudioOffloadInfo, bitRatePerSecond) == 56, "wrong offset");
static_assert(offsetof(::android::hardware::audio::common::V7_0::AudioOffloadInfo, durationMicroseconds) == 64, "wrong offset");
static_assert(offsetof(::android::hardware::audio::common::V7_0::AudioOffloadInfo, hasVideo) == 72, "wrong offset");
static_assert(offsetof(::android::hardware::audio::common::V7_0::AudioOffloadInfo, isStreaming) == 73, "wrong offset");
static_assert(offsetof(::android::hardware::audio::common::V7_0::AudioOffloadInfo, bitWidth) == 76, "wrong offset");
static_assert(offsetof(::android::hardware::audio::common::V7_0::AudioOffloadInfo, bufferSize) == 80, "wrong offset");
static_assert(offsetof(::android::hardware::audio::common::V7_0::AudioOffloadInfo, usage) == 88, "wrong offset");
static_assert(offsetof(::android::hardware::audio::common::V7_0::AudioOffloadInfo, encapsulationMode) == 104, "wrong offset");
static_assert(offsetof(::android::hardware::audio::common::V7_0::AudioOffloadInfo, contentId) == 108, "wrong offset");
static_assert(offsetof(::android::hardware::audio::common::V7_0::AudioOffloadInfo, syncId) == 112, "wrong offset");
static_assert(sizeof(::android::hardware::audio::common::V7_0::AudioOffloadInfo) == 120, "wrong size");
static_assert(__alignof(::android::hardware::audio::common::V7_0::AudioOffloadInfo) == 8, "wrong alignment");

/**
 * Commonly used audio stream configuration parameters.
 */
struct AudioConfig final {
    // Forward declaration for forward reference support:
    struct OffloadInfo;

    struct OffloadInfo final {
        enum class hidl_discriminator : uint8_t {
            unspecified = 0,  // ::android::hidl::safe_union::V1_0::Monostate
            info = 1,  // ::android::hardware::audio::common::V7_0::AudioOffloadInfo
        };

        OffloadInfo();
        ~OffloadInfo();
        OffloadInfo(OffloadInfo&&);
        OffloadInfo(const OffloadInfo&);
        OffloadInfo& operator=(OffloadInfo&&);
        OffloadInfo& operator=(const OffloadInfo&);

        void unspecified(const ::android::hidl::safe_union::V1_0::Monostate&);
        void unspecified(::android::hidl::safe_union::V1_0::Monostate&&);
        ::android::hidl::safe_union::V1_0::Monostate& unspecified();
        const ::android::hidl::safe_union::V1_0::Monostate& unspecified() const;

        void info(const ::android::hardware::audio::common::V7_0::AudioOffloadInfo&);
        void info(::android::hardware::audio::common::V7_0::AudioOffloadInfo&&);
        ::android::hardware::audio::common::V7_0::AudioOffloadInfo& info();
        const ::android::hardware::audio::common::V7_0::AudioOffloadInfo& info() const;

        // Utility methods
        hidl_discriminator getDiscriminator() const;

        constexpr size_t hidl_getUnionOffset() const {
            return offsetof(::android::hardware::audio::common::V7_0::AudioConfig::OffloadInfo, hidl_u);
        }

    private:
        void hidl_destructUnion();

        hidl_discriminator hidl_d __attribute__ ((aligned(1))) ;
        union hidl_union final {
            ::android::hidl::safe_union::V1_0::Monostate unspecified __attribute__ ((aligned(1)));
            ::android::hardware::audio::common::V7_0::AudioOffloadInfo info __attribute__ ((aligned(8)));

            hidl_union();
            ~hidl_union();
        } hidl_u;

        static_assert(sizeof(::android::hardware::audio::common::V7_0::AudioConfig::OffloadInfo::hidl_union) == 120, "wrong size");
        static_assert(__alignof(::android::hardware::audio::common::V7_0::AudioConfig::OffloadInfo::hidl_union) == 8, "wrong alignment");
        static_assert(sizeof(::android::hardware::audio::common::V7_0::AudioConfig::OffloadInfo::hidl_discriminator) == 1, "wrong size");
        static_assert(__alignof(::android::hardware::audio::common::V7_0::AudioConfig::OffloadInfo::hidl_discriminator) == 1, "wrong alignment");
    };

    static_assert(sizeof(::android::hardware::audio::common::V7_0::AudioConfig::OffloadInfo) == 128, "wrong size");
    static_assert(__alignof(::android::hardware::audio::common::V7_0::AudioConfig::OffloadInfo) == 8, "wrong alignment");

    ::android::hardware::audio::common::V7_0::AudioConfigBase base __attribute__ ((aligned(8)));
    ::android::hardware::audio::common::V7_0::AudioConfig::OffloadInfo offloadInfo __attribute__ ((aligned(8)));
    uint64_t frameCount __attribute__ ((aligned(8)));
};

static_assert(offsetof(::android::hardware::audio::common::V7_0::AudioConfig, base) == 0, "wrong offset");
static_assert(offsetof(::android::hardware::audio::common::V7_0::AudioConfig, offloadInfo) == 40, "wrong offset");
static_assert(offsetof(::android::hardware::audio::common::V7_0::AudioConfig, frameCount) == 168, "wrong offset");
static_assert(sizeof(::android::hardware::audio::common::V7_0::AudioConfig) == 176, "wrong size");
static_assert(__alignof(::android::hardware::audio::common::V7_0::AudioConfig) == 8, "wrong alignment");

/**
 * AudioTag is an additional use case qualifier complementing
 * AudioUsage and AudioContentType. Tags are set by vendor specific applications
 * and must be prefixed by "VX_". Vendor must namespace their tag
 * names to avoid conflicts. See 'vendorExtension' in audio_policy_configuration.xsd
 * for a formal definition.
 */
typedef ::android::hardware::hidl_string AudioTag;

/**
 * Metadata of a playback track for a StreamOut.
 */
struct PlaybackTrackMetadata final {
    ::android::hardware::hidl_string usage __attribute__ ((aligned(8)));
    ::android::hardware::hidl_string contentType __attribute__ ((aligned(8)));
    /**
     * Positive linear gain applied to the track samples. 0 being muted and 1 is no attenuation,
     * 2 means double amplification...
     * Must not be negative.
     */
    float gain __attribute__ ((aligned(4)));
    ::android::hardware::hidl_string channelMask __attribute__ ((aligned(8)));
    /**
     * Tags from AudioTrack audio atttributes
     */
    ::android::hardware::hidl_vec<::android::hardware::hidl_string> tags __attribute__ ((aligned(8)));
};

static_assert(offsetof(::android::hardware::audio::common::V7_0::PlaybackTrackMetadata, usage) == 0, "wrong offset");
static_assert(offsetof(::android::hardware::audio::common::V7_0::PlaybackTrackMetadata, contentType) == 16, "wrong offset");
static_assert(offsetof(::android::hardware::audio::common::V7_0::PlaybackTrackMetadata, gain) == 32, "wrong offset");
static_assert(offsetof(::android::hardware::audio::common::V7_0::PlaybackTrackMetadata, channelMask) == 40, "wrong offset");
static_assert(offsetof(::android::hardware::audio::common::V7_0::PlaybackTrackMetadata, tags) == 56, "wrong offset");
static_assert(sizeof(::android::hardware::audio::common::V7_0::PlaybackTrackMetadata) == 72, "wrong size");
static_assert(__alignof(::android::hardware::audio::common::V7_0::PlaybackTrackMetadata) == 8, "wrong alignment");

/**
 * Metadatas of the source of a StreamOut.
 */
struct SourceMetadata final {
    ::android::hardware::hidl_vec<::android::hardware::audio::common::V7_0::PlaybackTrackMetadata> tracks __attribute__ ((aligned(8)));
};

static_assert(offsetof(::android::hardware::audio::common::V7_0::SourceMetadata, tracks) == 0, "wrong offset");
static_assert(sizeof(::android::hardware::audio::common::V7_0::SourceMetadata) == 16, "wrong size");
static_assert(__alignof(::android::hardware::audio::common::V7_0::SourceMetadata) == 8, "wrong alignment");

/**
 * Metadata of a record track for a StreamIn.
 */
struct RecordTrackMetadata final {
    // Forward declaration for forward reference support:
    struct Destination;

    struct Destination final {
        enum class hidl_discriminator : uint8_t {
            unspecified = 0,  // ::android::hidl::safe_union::V1_0::Monostate
            device = 1,  // ::android::hardware::audio::common::V7_0::DeviceAddress
        };

        Destination();
        ~Destination();
        Destination(Destination&&);
        Destination(const Destination&);
        Destination& operator=(Destination&&);
        Destination& operator=(const Destination&);

        void unspecified(const ::android::hidl::safe_union::V1_0::Monostate&);
        void unspecified(::android::hidl::safe_union::V1_0::Monostate&&);
        ::android::hidl::safe_union::V1_0::Monostate& unspecified();
        const ::android::hidl::safe_union::V1_0::Monostate& unspecified() const;

        void device(const ::android::hardware::audio::common::V7_0::DeviceAddress&);
        void device(::android::hardware::audio::common::V7_0::DeviceAddress&&);
        ::android::hardware::audio::common::V7_0::DeviceAddress& device();
        const ::android::hardware::audio::common::V7_0::DeviceAddress& device() const;

        // Utility methods
        hidl_discriminator getDiscriminator() const;

        constexpr size_t hidl_getUnionOffset() const {
            return offsetof(::android::hardware::audio::common::V7_0::RecordTrackMetadata::Destination, hidl_u);
        }

    private:
        void hidl_destructUnion();

        hidl_discriminator hidl_d __attribute__ ((aligned(1))) ;
        union hidl_union final {
            ::android::hidl::safe_union::V1_0::Monostate unspecified __attribute__ ((aligned(1)));
            ::android::hardware::audio::common::V7_0::DeviceAddress device __attribute__ ((aligned(8)));

            hidl_union();
            ~hidl_union();
        } hidl_u;

        static_assert(sizeof(::android::hardware::audio::common::V7_0::RecordTrackMetadata::Destination::hidl_union) == 40, "wrong size");
        static_assert(__alignof(::android::hardware::audio::common::V7_0::RecordTrackMetadata::Destination::hidl_union) == 8, "wrong alignment");
        static_assert(sizeof(::android::hardware::audio::common::V7_0::RecordTrackMetadata::Destination::hidl_discriminator) == 1, "wrong size");
        static_assert(__alignof(::android::hardware::audio::common::V7_0::RecordTrackMetadata::Destination::hidl_discriminator) == 1, "wrong alignment");
    };

    static_assert(sizeof(::android::hardware::audio::common::V7_0::RecordTrackMetadata::Destination) == 48, "wrong size");
    static_assert(__alignof(::android::hardware::audio::common::V7_0::RecordTrackMetadata::Destination) == 8, "wrong alignment");

    ::android::hardware::hidl_string source __attribute__ ((aligned(8)));
    /**
     * Positive linear gain applied to the track samples. 0 being muted and 1 is no attenuation,
     * 2 means double amplification...
     * Must not be negative.
     */
    float gain __attribute__ ((aligned(4)));
    /**
     * Indicates the destination of an input stream, can be left unspecified.
     */
    ::android::hardware::audio::common::V7_0::RecordTrackMetadata::Destination destination __attribute__ ((aligned(8)));
    ::android::hardware::hidl_string channelMask __attribute__ ((aligned(8)));
    /**
     * Tags from AudioRecord audio atttributes
     */
    ::android::hardware::hidl_vec<::android::hardware::hidl_string> tags __attribute__ ((aligned(8)));
};

static_assert(offsetof(::android::hardware::audio::common::V7_0::RecordTrackMetadata, source) == 0, "wrong offset");
static_assert(offsetof(::android::hardware::audio::common::V7_0::RecordTrackMetadata, gain) == 16, "wrong offset");
static_assert(offsetof(::android::hardware::audio::common::V7_0::RecordTrackMetadata, destination) == 24, "wrong offset");
static_assert(offsetof(::android::hardware::audio::common::V7_0::RecordTrackMetadata, channelMask) == 72, "wrong offset");
static_assert(offsetof(::android::hardware::audio::common::V7_0::RecordTrackMetadata, tags) == 88, "wrong offset");
static_assert(sizeof(::android::hardware::audio::common::V7_0::RecordTrackMetadata) == 104, "wrong size");
static_assert(__alignof(::android::hardware::audio::common::V7_0::RecordTrackMetadata) == 8, "wrong alignment");

/**
 * Metadatas of the sink of a StreamIn.
 */
struct SinkMetadata final {
    ::android::hardware::hidl_vec<::android::hardware::audio::common::V7_0::RecordTrackMetadata> tracks __attribute__ ((aligned(8)));
};

static_assert(offsetof(::android::hardware::audio::common::V7_0::SinkMetadata, tracks) == 0, "wrong offset");
static_assert(sizeof(::android::hardware::audio::common::V7_0::SinkMetadata) == 16, "wrong size");
static_assert(__alignof(::android::hardware::audio::common::V7_0::SinkMetadata) == 8, "wrong alignment");

/*
 *  Volume control
 *
 *
 *
 * Type of gain control exposed by an audio port.
 * See 'audioGainMode' in audio_policy_configuration.xsd for the
 * list of allowed values.
 */
typedef ::android::hardware::hidl_string AudioGainMode;

/**
 * An audio_gain struct is a representation of a gain stage.
 * A gain stage is always attached to an audio port.
 */
struct AudioGain final {
    /**
     * Modes of operation.
     */
    ::android::hardware::hidl_vec<::android::hardware::hidl_string> mode __attribute__ ((aligned(8)));
    /**
     * Channels which gain can be controlled.
     */
    ::android::hardware::hidl_string channelMask __attribute__ ((aligned(8)));
    /**
     * Minimum gain value in millibels.
     */
    int32_t minValue __attribute__ ((aligned(4)));
    /**
     * Maximum gain value in millibels.
     */
    int32_t maxValue __attribute__ ((aligned(4)));
    /**
     * Default gain value in millibels.
     */
    int32_t defaultValue __attribute__ ((aligned(4)));
    /**
     * Gain step in millibels.
     */
    uint32_t stepValue __attribute__ ((aligned(4)));
    /**
     * Ramp duration in ms.
     */
    uint32_t minRampMs __attribute__ ((aligned(4)));
    /**
     * Maximum ramp duration in ms.
     */
    uint32_t maxRampMs __attribute__ ((aligned(4)));
};

static_assert(offsetof(::android::hardware::audio::common::V7_0::AudioGain, mode) == 0, "wrong offset");
static_assert(offsetof(::android::hardware::audio::common::V7_0::AudioGain, channelMask) == 16, "wrong offset");
static_assert(offsetof(::android::hardware::audio::common::V7_0::AudioGain, minValue) == 32, "wrong offset");
static_assert(offsetof(::android::hardware::audio::common::V7_0::AudioGain, maxValue) == 36, "wrong offset");
static_assert(offsetof(::android::hardware::audio::common::V7_0::AudioGain, defaultValue) == 40, "wrong offset");
static_assert(offsetof(::android::hardware::audio::common::V7_0::AudioGain, stepValue) == 44, "wrong offset");
static_assert(offsetof(::android::hardware::audio::common::V7_0::AudioGain, minRampMs) == 48, "wrong offset");
static_assert(offsetof(::android::hardware::audio::common::V7_0::AudioGain, maxRampMs) == 52, "wrong offset");
static_assert(sizeof(::android::hardware::audio::common::V7_0::AudioGain) == 56, "wrong size");
static_assert(__alignof(::android::hardware::audio::common::V7_0::AudioGain) == 8, "wrong alignment");

/**
 * The gain configuration structure is used to get or set the gain values of a
 * given port.
 */
struct AudioGainConfig final {
    /**
     * Index of the corresponding AudioGain in AudioPort.gains.
     */
    int32_t index __attribute__ ((aligned(4)));
    /**
     * Modes of operation.
     */
    ::android::hardware::hidl_vec<::android::hardware::hidl_string> mode __attribute__ ((aligned(8)));
    /**
     * Channels which gain value follows.
     */
    ::android::hardware::hidl_string channelMask __attribute__ ((aligned(8)));
    /**
     * Gain values in millibels for each channel ordered from LSb to MSb in
     * channel mask. The number of values is 1 in joint mode or
     * the number of channels in the channel mask.
     */
    ::android::hardware::hidl_vec<int32_t> values __attribute__ ((aligned(8)));
    /**
     * Ramp duration in ms.
     */
    uint32_t rampDurationMs __attribute__ ((aligned(4)));
};

static_assert(offsetof(::android::hardware::audio::common::V7_0::AudioGainConfig, index) == 0, "wrong offset");
static_assert(offsetof(::android::hardware::audio::common::V7_0::AudioGainConfig, mode) == 8, "wrong offset");
static_assert(offsetof(::android::hardware::audio::common::V7_0::AudioGainConfig, channelMask) == 24, "wrong offset");
static_assert(offsetof(::android::hardware::audio::common::V7_0::AudioGainConfig, values) == 40, "wrong offset");
static_assert(offsetof(::android::hardware::audio::common::V7_0::AudioGainConfig, rampDurationMs) == 56, "wrong offset");
static_assert(sizeof(::android::hardware::audio::common::V7_0::AudioGainConfig) == 64, "wrong size");
static_assert(__alignof(::android::hardware::audio::common::V7_0::AudioGainConfig) == 8, "wrong alignment");

/*
 *  Routing control
 *
 *
 *
 * Types defined here are used to describe an audio source or sink at internal
 * framework interfaces (audio policy, patch panel) or at the audio HAL.
 * Sink and sources are grouped in a concept of “audio port” representing an
 * audio end point at the edge of the system managed by the module exposing
 * the interface.
 *
 *
 * A helper aggregate structure providing parameters that depend on the
 * port role.
 */
struct AudioPortExtendedInfo final {
    // Forward declaration for forward reference support:
    struct AudioPortMixExt;

    struct AudioPortMixExt final {
        // Forward declaration for forward reference support:
        struct UseCase;

        struct UseCase final {
            enum class hidl_discriminator : uint8_t {
                /**
                 * Specified when the port is in the SOURCE role.
                 */
                stream = 0,  // ::android::hardware::hidl_string
                /**
                 * Specified when the port is in the SINK role.
                 */
                source = 1,  // ::android::hardware::hidl_string
            };

            UseCase();
            ~UseCase();
            UseCase(UseCase&&);
            UseCase(const UseCase&);
            UseCase& operator=(UseCase&&);
            UseCase& operator=(const UseCase&);

            void stream(const ::android::hardware::hidl_string&);
            void stream(::android::hardware::hidl_string&&);
            ::android::hardware::hidl_string& stream();
            const ::android::hardware::hidl_string& stream() const;

            void source(const ::android::hardware::hidl_string&);
            void source(::android::hardware::hidl_string&&);
            ::android::hardware::hidl_string& source();
            const ::android::hardware::hidl_string& source() const;

            // Utility methods
            hidl_discriminator getDiscriminator() const;

            constexpr size_t hidl_getUnionOffset() const {
                return offsetof(::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::AudioPortMixExt::UseCase, hidl_u);
            }

        private:
            void hidl_destructUnion();

            hidl_discriminator hidl_d __attribute__ ((aligned(1))) ;
            union hidl_union final {
                ::android::hardware::hidl_string stream __attribute__ ((aligned(8)));
                ::android::hardware::hidl_string source __attribute__ ((aligned(8)));

                hidl_union();
                ~hidl_union();
            } hidl_u;

            static_assert(sizeof(::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::AudioPortMixExt::UseCase::hidl_union) == 16, "wrong size");
            static_assert(__alignof(::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::AudioPortMixExt::UseCase::hidl_union) == 8, "wrong alignment");
            static_assert(sizeof(::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::AudioPortMixExt::UseCase::hidl_discriminator) == 1, "wrong size");
            static_assert(__alignof(::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::AudioPortMixExt::UseCase::hidl_discriminator) == 1, "wrong alignment");
        };

        static_assert(sizeof(::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::AudioPortMixExt::UseCase) == 24, "wrong size");
        static_assert(__alignof(::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::AudioPortMixExt::UseCase) == 8, "wrong alignment");

        /**
         * I/O handle of the input/output stream.
         */
        int32_t ioHandle __attribute__ ((aligned(4)));
        ::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::AudioPortMixExt::UseCase useCase __attribute__ ((aligned(8)));
    };

    static_assert(offsetof(::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::AudioPortMixExt, ioHandle) == 0, "wrong offset");
    static_assert(offsetof(::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::AudioPortMixExt, useCase) == 8, "wrong offset");
    static_assert(sizeof(::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::AudioPortMixExt) == 32, "wrong size");
    static_assert(__alignof(::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::AudioPortMixExt) == 8, "wrong alignment");

    enum class hidl_discriminator : uint8_t {
        /**
         * Set when no information is provided.
         */
        unspecified = 0,  // ::android::hidl::safe_union::V1_0::Monostate
        /**
         * Set when the audio port is an audio device.
         */
        device = 1,  // ::android::hardware::audio::common::V7_0::DeviceAddress
        /**
         * Set when the audio port is a mix. The handle is of a stream.
         */
        mix = 2,  // ::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::AudioPortMixExt
        /**
         * Set when the audio port is an audio session.
         */
        session = 3,  // int32_t
    };

    AudioPortExtendedInfo();
    ~AudioPortExtendedInfo();
    AudioPortExtendedInfo(AudioPortExtendedInfo&&);
    AudioPortExtendedInfo(const AudioPortExtendedInfo&);
    AudioPortExtendedInfo& operator=(AudioPortExtendedInfo&&);
    AudioPortExtendedInfo& operator=(const AudioPortExtendedInfo&);

    void unspecified(const ::android::hidl::safe_union::V1_0::Monostate&);
    void unspecified(::android::hidl::safe_union::V1_0::Monostate&&);
    ::android::hidl::safe_union::V1_0::Monostate& unspecified();
    const ::android::hidl::safe_union::V1_0::Monostate& unspecified() const;

    void device(const ::android::hardware::audio::common::V7_0::DeviceAddress&);
    void device(::android::hardware::audio::common::V7_0::DeviceAddress&&);
    ::android::hardware::audio::common::V7_0::DeviceAddress& device();
    const ::android::hardware::audio::common::V7_0::DeviceAddress& device() const;

    void mix(const ::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::AudioPortMixExt&);
    void mix(::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::AudioPortMixExt&&);
    ::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::AudioPortMixExt& mix();
    const ::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::AudioPortMixExt& mix() const;

    void session(int32_t);
    int32_t& session();
    int32_t session() const;

    // Utility methods
    hidl_discriminator getDiscriminator() const;

    constexpr size_t hidl_getUnionOffset() const {
        return offsetof(::android::hardware::audio::common::V7_0::AudioPortExtendedInfo, hidl_u);
    }

private:
    void hidl_destructUnion();

    hidl_discriminator hidl_d __attribute__ ((aligned(1))) ;
    union hidl_union final {
        ::android::hidl::safe_union::V1_0::Monostate unspecified __attribute__ ((aligned(1)));
        ::android::hardware::audio::common::V7_0::DeviceAddress device __attribute__ ((aligned(8)));
        ::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::AudioPortMixExt mix __attribute__ ((aligned(8)));
        int32_t session __attribute__ ((aligned(4)));

        hidl_union();
        ~hidl_union();
    } hidl_u;

    static_assert(sizeof(::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::hidl_union) == 40, "wrong size");
    static_assert(__alignof(::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::hidl_union) == 8, "wrong alignment");
    static_assert(sizeof(::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::hidl_discriminator) == 1, "wrong size");
    static_assert(__alignof(::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::hidl_discriminator) == 1, "wrong alignment");
};

static_assert(sizeof(::android::hardware::audio::common::V7_0::AudioPortExtendedInfo) == 48, "wrong size");
static_assert(__alignof(::android::hardware::audio::common::V7_0::AudioPortExtendedInfo) == 8, "wrong alignment");

/**
 * Audio port configuration structure used to specify a particular configuration
 * of an audio port.
 */
struct AudioPortConfig final {
    // Forward declaration for forward reference support:
    struct OptionalGain;

    struct OptionalGain final {
        enum class hidl_discriminator : uint8_t {
            unspecified = 0,  // ::android::hidl::safe_union::V1_0::Monostate
            config = 1,  // ::android::hardware::audio::common::V7_0::AudioGainConfig
        };

        OptionalGain();
        ~OptionalGain();
        OptionalGain(OptionalGain&&);
        OptionalGain(const OptionalGain&);
        OptionalGain& operator=(OptionalGain&&);
        OptionalGain& operator=(const OptionalGain&);

        void unspecified(const ::android::hidl::safe_union::V1_0::Monostate&);
        void unspecified(::android::hidl::safe_union::V1_0::Monostate&&);
        ::android::hidl::safe_union::V1_0::Monostate& unspecified();
        const ::android::hidl::safe_union::V1_0::Monostate& unspecified() const;

        void config(const ::android::hardware::audio::common::V7_0::AudioGainConfig&);
        void config(::android::hardware::audio::common::V7_0::AudioGainConfig&&);
        ::android::hardware::audio::common::V7_0::AudioGainConfig& config();
        const ::android::hardware::audio::common::V7_0::AudioGainConfig& config() const;

        // Utility methods
        hidl_discriminator getDiscriminator() const;

        constexpr size_t hidl_getUnionOffset() const {
            return offsetof(::android::hardware::audio::common::V7_0::AudioPortConfig::OptionalGain, hidl_u);
        }

    private:
        void hidl_destructUnion();

        hidl_discriminator hidl_d __attribute__ ((aligned(1))) ;
        union hidl_union final {
            ::android::hidl::safe_union::V1_0::Monostate unspecified __attribute__ ((aligned(1)));
            ::android::hardware::audio::common::V7_0::AudioGainConfig config __attribute__ ((aligned(8)));

            hidl_union();
            ~hidl_union();
        } hidl_u;

        static_assert(sizeof(::android::hardware::audio::common::V7_0::AudioPortConfig::OptionalGain::hidl_union) == 64, "wrong size");
        static_assert(__alignof(::android::hardware::audio::common::V7_0::AudioPortConfig::OptionalGain::hidl_union) == 8, "wrong alignment");
        static_assert(sizeof(::android::hardware::audio::common::V7_0::AudioPortConfig::OptionalGain::hidl_discriminator) == 1, "wrong size");
        static_assert(__alignof(::android::hardware::audio::common::V7_0::AudioPortConfig::OptionalGain::hidl_discriminator) == 1, "wrong alignment");
    };

    static_assert(sizeof(::android::hardware::audio::common::V7_0::AudioPortConfig::OptionalGain) == 72, "wrong size");
    static_assert(__alignof(::android::hardware::audio::common::V7_0::AudioPortConfig::OptionalGain) == 8, "wrong alignment");

    /**
     * The 'id' field is set when it is needed to select the port and
     * apply new configuration for it.
     */
    int32_t id __attribute__ ((aligned(4)));
    /**
     * Basic parameters: sampling rate, format, channel mask.
     */
    ::android::hardware::audio::common::V7_0::AudioConfigBaseOptional base __attribute__ ((aligned(8)));
    /**
     * Associated gain control.
     */
    ::android::hardware::audio::common::V7_0::AudioPortConfig::OptionalGain gain __attribute__ ((aligned(8)));
    /**
     * Parameters that depend on the actual port role.
     */
    ::android::hardware::audio::common::V7_0::AudioPortExtendedInfo ext __attribute__ ((aligned(8)));
};

static_assert(offsetof(::android::hardware::audio::common::V7_0::AudioPortConfig, id) == 0, "wrong offset");
static_assert(offsetof(::android::hardware::audio::common::V7_0::AudioPortConfig, base) == 8, "wrong offset");
static_assert(offsetof(::android::hardware::audio::common::V7_0::AudioPortConfig, gain) == 64, "wrong offset");
static_assert(offsetof(::android::hardware::audio::common::V7_0::AudioPortConfig, ext) == 136, "wrong offset");
static_assert(sizeof(::android::hardware::audio::common::V7_0::AudioPortConfig) == 184, "wrong size");
static_assert(__alignof(::android::hardware::audio::common::V7_0::AudioPortConfig) == 8, "wrong alignment");

/**
 * Audio port structure describes the capabilities of an audio port
 * as well as its current configuration.
 */
struct AudioPort final {
    /**
     * Unique identifier of the port within this HAL service. When calling
     * from the client side functions like IDevice.getAudioPort is it allowed
     * to only specify the 'id' and leave the other fields unspecified.
     */
    int32_t id __attribute__ ((aligned(4)));
    /**
     * Human-readable name describing the function of the port.
     * E.g. "telephony_tx" or "fm_tuner".
     */
    ::android::hardware::hidl_string name __attribute__ ((aligned(8)));
    /**
     * List of audio transports supported by the audio port. This includes
     * supported formats and raw hardware descriptors for formats not supported
     * by the platform.
     */
    ::android::hardware::hidl_vec<::android::hardware::audio::common::V7_0::AudioTransport> transports __attribute__ ((aligned(8)));
    /**
     * List of gain controls attached to the port.
     */
    ::android::hardware::hidl_vec<::android::hardware::audio::common::V7_0::AudioGain> gains __attribute__ ((aligned(8)));
    /**
     * Parameters that depend on the actual port role.
     */
    ::android::hardware::audio::common::V7_0::AudioPortExtendedInfo ext __attribute__ ((aligned(8)));
    /**
     * Current configuration of the audio port, may have all the fields left
     * unspecified.
     */
    ::android::hardware::audio::common::V7_0::AudioPortConfig activeConfig __attribute__ ((aligned(8)));
};

static_assert(offsetof(::android::hardware::audio::common::V7_0::AudioPort, id) == 0, "wrong offset");
static_assert(offsetof(::android::hardware::audio::common::V7_0::AudioPort, name) == 8, "wrong offset");
static_assert(offsetof(::android::hardware::audio::common::V7_0::AudioPort, transports) == 24, "wrong offset");
static_assert(offsetof(::android::hardware::audio::common::V7_0::AudioPort, gains) == 40, "wrong offset");
static_assert(offsetof(::android::hardware::audio::common::V7_0::AudioPort, ext) == 56, "wrong offset");
static_assert(offsetof(::android::hardware::audio::common::V7_0::AudioPort, activeConfig) == 104, "wrong offset");
static_assert(sizeof(::android::hardware::audio::common::V7_0::AudioPort) == 288, "wrong size");
static_assert(__alignof(::android::hardware::audio::common::V7_0::AudioPort) == 8, "wrong alignment");

//
// type declarations for package
//

static inline std::string toString(const ::android::hardware::audio::common::V7_0::Uuid& o);
static inline void PrintTo(const ::android::hardware::audio::common::V7_0::Uuid& o, ::std::ostream*);
static inline bool operator==(const ::android::hardware::audio::common::V7_0::Uuid& lhs, const ::android::hardware::audio::common::V7_0::Uuid& rhs);
static inline bool operator!=(const ::android::hardware::audio::common::V7_0::Uuid& lhs, const ::android::hardware::audio::common::V7_0::Uuid& rhs);

template<typename>
static inline std::string toString(int32_t o);
static inline std::string toString(::android::hardware::audio::common::V7_0::AudioSessionConsts o);
static inline void PrintTo(::android::hardware::audio::common::V7_0::AudioSessionConsts o, ::std::ostream* os);
constexpr int32_t operator|(const ::android::hardware::audio::common::V7_0::AudioSessionConsts lhs, const ::android::hardware::audio::common::V7_0::AudioSessionConsts rhs) {
    return static_cast<int32_t>(static_cast<int32_t>(lhs) | static_cast<int32_t>(rhs));
}
constexpr int32_t operator|(const int32_t lhs, const ::android::hardware::audio::common::V7_0::AudioSessionConsts rhs) {
    return static_cast<int32_t>(lhs | static_cast<int32_t>(rhs));
}
constexpr int32_t operator|(const ::android::hardware::audio::common::V7_0::AudioSessionConsts lhs, const int32_t rhs) {
    return static_cast<int32_t>(static_cast<int32_t>(lhs) | rhs);
}
constexpr int32_t operator&(const ::android::hardware::audio::common::V7_0::AudioSessionConsts lhs, const ::android::hardware::audio::common::V7_0::AudioSessionConsts rhs) {
    return static_cast<int32_t>(static_cast<int32_t>(lhs) & static_cast<int32_t>(rhs));
}
constexpr int32_t operator&(const int32_t lhs, const ::android::hardware::audio::common::V7_0::AudioSessionConsts rhs) {
    return static_cast<int32_t>(lhs & static_cast<int32_t>(rhs));
}
constexpr int32_t operator&(const ::android::hardware::audio::common::V7_0::AudioSessionConsts lhs, const int32_t rhs) {
    return static_cast<int32_t>(static_cast<int32_t>(lhs) & rhs);
}
constexpr int32_t &operator|=(int32_t& v, const ::android::hardware::audio::common::V7_0::AudioSessionConsts e) {
    v |= static_cast<int32_t>(e);
    return v;
}
constexpr int32_t &operator&=(int32_t& v, const ::android::hardware::audio::common::V7_0::AudioSessionConsts e) {
    v &= static_cast<int32_t>(e);
    return v;
}

static inline std::string toString(const ::android::hardware::audio::common::V7_0::AudioConfigBase& o);
static inline void PrintTo(const ::android::hardware::audio::common::V7_0::AudioConfigBase& o, ::std::ostream*);
static inline bool operator==(const ::android::hardware::audio::common::V7_0::AudioConfigBase& lhs, const ::android::hardware::audio::common::V7_0::AudioConfigBase& rhs);
static inline bool operator!=(const ::android::hardware::audio::common::V7_0::AudioConfigBase& lhs, const ::android::hardware::audio::common::V7_0::AudioConfigBase& rhs);

static inline std::string toString(const ::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::Format& o);
static inline void PrintTo(const ::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::Format& o, ::std::ostream*);
static inline bool operator==(const ::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::Format& lhs, const ::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::Format& rhs);
static inline bool operator!=(const ::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::Format& lhs, const ::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::Format& rhs);

static inline std::string toString(const ::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::SampleRate& o);
static inline void PrintTo(const ::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::SampleRate& o, ::std::ostream*);
static inline bool operator==(const ::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::SampleRate& lhs, const ::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::SampleRate& rhs);
static inline bool operator!=(const ::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::SampleRate& lhs, const ::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::SampleRate& rhs);

static inline std::string toString(const ::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::ChannelMask& o);
static inline void PrintTo(const ::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::ChannelMask& o, ::std::ostream*);
static inline bool operator==(const ::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::ChannelMask& lhs, const ::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::ChannelMask& rhs);
static inline bool operator!=(const ::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::ChannelMask& lhs, const ::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::ChannelMask& rhs);

static inline std::string toString(const ::android::hardware::audio::common::V7_0::AudioConfigBaseOptional& o);
static inline void PrintTo(const ::android::hardware::audio::common::V7_0::AudioConfigBaseOptional& o, ::std::ostream*);
static inline bool operator==(const ::android::hardware::audio::common::V7_0::AudioConfigBaseOptional& lhs, const ::android::hardware::audio::common::V7_0::AudioConfigBaseOptional& rhs);
static inline bool operator!=(const ::android::hardware::audio::common::V7_0::AudioConfigBaseOptional& lhs, const ::android::hardware::audio::common::V7_0::AudioConfigBaseOptional& rhs);

static inline std::string toString(const ::android::hardware::audio::common::V7_0::AudioProfile& o);
static inline void PrintTo(const ::android::hardware::audio::common::V7_0::AudioProfile& o, ::std::ostream*);
static inline bool operator==(const ::android::hardware::audio::common::V7_0::AudioProfile& lhs, const ::android::hardware::audio::common::V7_0::AudioProfile& rhs);
static inline bool operator!=(const ::android::hardware::audio::common::V7_0::AudioProfile& lhs, const ::android::hardware::audio::common::V7_0::AudioProfile& rhs);

static inline std::string toString(const ::android::hardware::audio::common::V7_0::AudioTransport::AudioCapability& o);
static inline void PrintTo(const ::android::hardware::audio::common::V7_0::AudioTransport::AudioCapability& o, ::std::ostream*);
static inline bool operator==(const ::android::hardware::audio::common::V7_0::AudioTransport::AudioCapability& lhs, const ::android::hardware::audio::common::V7_0::AudioTransport::AudioCapability& rhs);
static inline bool operator!=(const ::android::hardware::audio::common::V7_0::AudioTransport::AudioCapability& lhs, const ::android::hardware::audio::common::V7_0::AudioTransport::AudioCapability& rhs);

static inline std::string toString(const ::android::hardware::audio::common::V7_0::AudioTransport& o);
static inline void PrintTo(const ::android::hardware::audio::common::V7_0::AudioTransport& o, ::std::ostream*);
static inline bool operator==(const ::android::hardware::audio::common::V7_0::AudioTransport& lhs, const ::android::hardware::audio::common::V7_0::AudioTransport& rhs);
static inline bool operator!=(const ::android::hardware::audio::common::V7_0::AudioTransport& lhs, const ::android::hardware::audio::common::V7_0::AudioTransport& rhs);

template<typename>
static inline std::string toString(int32_t o);
static inline std::string toString(::android::hardware::audio::common::V7_0::AudioMode o);
static inline void PrintTo(::android::hardware::audio::common::V7_0::AudioMode o, ::std::ostream* os);
constexpr int32_t operator|(const ::android::hardware::audio::common::V7_0::AudioMode lhs, const ::android::hardware::audio::common::V7_0::AudioMode rhs) {
    return static_cast<int32_t>(static_cast<int32_t>(lhs) | static_cast<int32_t>(rhs));
}
constexpr int32_t operator|(const int32_t lhs, const ::android::hardware::audio::common::V7_0::AudioMode rhs) {
    return static_cast<int32_t>(lhs | static_cast<int32_t>(rhs));
}
constexpr int32_t operator|(const ::android::hardware::audio::common::V7_0::AudioMode lhs, const int32_t rhs) {
    return static_cast<int32_t>(static_cast<int32_t>(lhs) | rhs);
}
constexpr int32_t operator&(const ::android::hardware::audio::common::V7_0::AudioMode lhs, const ::android::hardware::audio::common::V7_0::AudioMode rhs) {
    return static_cast<int32_t>(static_cast<int32_t>(lhs) & static_cast<int32_t>(rhs));
}
constexpr int32_t operator&(const int32_t lhs, const ::android::hardware::audio::common::V7_0::AudioMode rhs) {
    return static_cast<int32_t>(lhs & static_cast<int32_t>(rhs));
}
constexpr int32_t operator&(const ::android::hardware::audio::common::V7_0::AudioMode lhs, const int32_t rhs) {
    return static_cast<int32_t>(static_cast<int32_t>(lhs) & rhs);
}
constexpr int32_t &operator|=(int32_t& v, const ::android::hardware::audio::common::V7_0::AudioMode e) {
    v |= static_cast<int32_t>(e);
    return v;
}
constexpr int32_t &operator&=(int32_t& v, const ::android::hardware::audio::common::V7_0::AudioMode e) {
    v &= static_cast<int32_t>(e);
    return v;
}

static inline std::string toString(const ::android::hardware::audio::common::V7_0::DeviceAddress::Address::Alsa& o);
static inline void PrintTo(const ::android::hardware::audio::common::V7_0::DeviceAddress::Address::Alsa& o, ::std::ostream*);
static inline bool operator==(const ::android::hardware::audio::common::V7_0::DeviceAddress::Address::Alsa& lhs, const ::android::hardware::audio::common::V7_0::DeviceAddress::Address::Alsa& rhs);
static inline bool operator!=(const ::android::hardware::audio::common::V7_0::DeviceAddress::Address::Alsa& lhs, const ::android::hardware::audio::common::V7_0::DeviceAddress::Address::Alsa& rhs);

static inline std::string toString(const ::android::hardware::audio::common::V7_0::DeviceAddress::Address& o);
static inline void PrintTo(const ::android::hardware::audio::common::V7_0::DeviceAddress::Address& o, ::std::ostream*);
static inline bool operator==(const ::android::hardware::audio::common::V7_0::DeviceAddress::Address& lhs, const ::android::hardware::audio::common::V7_0::DeviceAddress::Address& rhs);
static inline bool operator!=(const ::android::hardware::audio::common::V7_0::DeviceAddress::Address& lhs, const ::android::hardware::audio::common::V7_0::DeviceAddress::Address& rhs);

static inline std::string toString(const ::android::hardware::audio::common::V7_0::DeviceAddress& o);
static inline void PrintTo(const ::android::hardware::audio::common::V7_0::DeviceAddress& o, ::std::ostream*);
static inline bool operator==(const ::android::hardware::audio::common::V7_0::DeviceAddress& lhs, const ::android::hardware::audio::common::V7_0::DeviceAddress& rhs);
static inline bool operator!=(const ::android::hardware::audio::common::V7_0::DeviceAddress& lhs, const ::android::hardware::audio::common::V7_0::DeviceAddress& rhs);

template<typename>
static inline std::string toString(int32_t o);
static inline std::string toString(::android::hardware::audio::common::V7_0::AudioEncapsulationMode o);
static inline void PrintTo(::android::hardware::audio::common::V7_0::AudioEncapsulationMode o, ::std::ostream* os);
constexpr int32_t operator|(const ::android::hardware::audio::common::V7_0::AudioEncapsulationMode lhs, const ::android::hardware::audio::common::V7_0::AudioEncapsulationMode rhs) {
    return static_cast<int32_t>(static_cast<int32_t>(lhs) | static_cast<int32_t>(rhs));
}
constexpr int32_t operator|(const int32_t lhs, const ::android::hardware::audio::common::V7_0::AudioEncapsulationMode rhs) {
    return static_cast<int32_t>(lhs | static_cast<int32_t>(rhs));
}
constexpr int32_t operator|(const ::android::hardware::audio::common::V7_0::AudioEncapsulationMode lhs, const int32_t rhs) {
    return static_cast<int32_t>(static_cast<int32_t>(lhs) | rhs);
}
constexpr int32_t operator&(const ::android::hardware::audio::common::V7_0::AudioEncapsulationMode lhs, const ::android::hardware::audio::common::V7_0::AudioEncapsulationMode rhs) {
    return static_cast<int32_t>(static_cast<int32_t>(lhs) & static_cast<int32_t>(rhs));
}
constexpr int32_t operator&(const int32_t lhs, const ::android::hardware::audio::common::V7_0::AudioEncapsulationMode rhs) {
    return static_cast<int32_t>(lhs & static_cast<int32_t>(rhs));
}
constexpr int32_t operator&(const ::android::hardware::audio::common::V7_0::AudioEncapsulationMode lhs, const int32_t rhs) {
    return static_cast<int32_t>(static_cast<int32_t>(lhs) & rhs);
}
constexpr int32_t &operator|=(int32_t& v, const ::android::hardware::audio::common::V7_0::AudioEncapsulationMode e) {
    v |= static_cast<int32_t>(e);
    return v;
}
constexpr int32_t &operator&=(int32_t& v, const ::android::hardware::audio::common::V7_0::AudioEncapsulationMode e) {
    v &= static_cast<int32_t>(e);
    return v;
}

template<typename>
static inline std::string toString(int32_t o);
static inline std::string toString(::android::hardware::audio::common::V7_0::AudioEncapsulationMetadataType o);
static inline void PrintTo(::android::hardware::audio::common::V7_0::AudioEncapsulationMetadataType o, ::std::ostream* os);
constexpr int32_t operator|(const ::android::hardware::audio::common::V7_0::AudioEncapsulationMetadataType lhs, const ::android::hardware::audio::common::V7_0::AudioEncapsulationMetadataType rhs) {
    return static_cast<int32_t>(static_cast<int32_t>(lhs) | static_cast<int32_t>(rhs));
}
constexpr int32_t operator|(const int32_t lhs, const ::android::hardware::audio::common::V7_0::AudioEncapsulationMetadataType rhs) {
    return static_cast<int32_t>(lhs | static_cast<int32_t>(rhs));
}
constexpr int32_t operator|(const ::android::hardware::audio::common::V7_0::AudioEncapsulationMetadataType lhs, const int32_t rhs) {
    return static_cast<int32_t>(static_cast<int32_t>(lhs) | rhs);
}
constexpr int32_t operator&(const ::android::hardware::audio::common::V7_0::AudioEncapsulationMetadataType lhs, const ::android::hardware::audio::common::V7_0::AudioEncapsulationMetadataType rhs) {
    return static_cast<int32_t>(static_cast<int32_t>(lhs) & static_cast<int32_t>(rhs));
}
constexpr int32_t operator&(const int32_t lhs, const ::android::hardware::audio::common::V7_0::AudioEncapsulationMetadataType rhs) {
    return static_cast<int32_t>(lhs & static_cast<int32_t>(rhs));
}
constexpr int32_t operator&(const ::android::hardware::audio::common::V7_0::AudioEncapsulationMetadataType lhs, const int32_t rhs) {
    return static_cast<int32_t>(static_cast<int32_t>(lhs) & rhs);
}
constexpr int32_t &operator|=(int32_t& v, const ::android::hardware::audio::common::V7_0::AudioEncapsulationMetadataType e) {
    v |= static_cast<int32_t>(e);
    return v;
}
constexpr int32_t &operator&=(int32_t& v, const ::android::hardware::audio::common::V7_0::AudioEncapsulationMetadataType e) {
    v &= static_cast<int32_t>(e);
    return v;
}

static inline std::string toString(const ::android::hardware::audio::common::V7_0::AudioOffloadInfo& o);
static inline void PrintTo(const ::android::hardware::audio::common::V7_0::AudioOffloadInfo& o, ::std::ostream*);
static inline bool operator==(const ::android::hardware::audio::common::V7_0::AudioOffloadInfo& lhs, const ::android::hardware::audio::common::V7_0::AudioOffloadInfo& rhs);
static inline bool operator!=(const ::android::hardware::audio::common::V7_0::AudioOffloadInfo& lhs, const ::android::hardware::audio::common::V7_0::AudioOffloadInfo& rhs);

static inline std::string toString(const ::android::hardware::audio::common::V7_0::AudioConfig::OffloadInfo& o);
static inline void PrintTo(const ::android::hardware::audio::common::V7_0::AudioConfig::OffloadInfo& o, ::std::ostream*);
static inline bool operator==(const ::android::hardware::audio::common::V7_0::AudioConfig::OffloadInfo& lhs, const ::android::hardware::audio::common::V7_0::AudioConfig::OffloadInfo& rhs);
static inline bool operator!=(const ::android::hardware::audio::common::V7_0::AudioConfig::OffloadInfo& lhs, const ::android::hardware::audio::common::V7_0::AudioConfig::OffloadInfo& rhs);

static inline std::string toString(const ::android::hardware::audio::common::V7_0::AudioConfig& o);
static inline void PrintTo(const ::android::hardware::audio::common::V7_0::AudioConfig& o, ::std::ostream*);
static inline bool operator==(const ::android::hardware::audio::common::V7_0::AudioConfig& lhs, const ::android::hardware::audio::common::V7_0::AudioConfig& rhs);
static inline bool operator!=(const ::android::hardware::audio::common::V7_0::AudioConfig& lhs, const ::android::hardware::audio::common::V7_0::AudioConfig& rhs);

static inline std::string toString(const ::android::hardware::audio::common::V7_0::PlaybackTrackMetadata& o);
static inline void PrintTo(const ::android::hardware::audio::common::V7_0::PlaybackTrackMetadata& o, ::std::ostream*);
static inline bool operator==(const ::android::hardware::audio::common::V7_0::PlaybackTrackMetadata& lhs, const ::android::hardware::audio::common::V7_0::PlaybackTrackMetadata& rhs);
static inline bool operator!=(const ::android::hardware::audio::common::V7_0::PlaybackTrackMetadata& lhs, const ::android::hardware::audio::common::V7_0::PlaybackTrackMetadata& rhs);

static inline std::string toString(const ::android::hardware::audio::common::V7_0::SourceMetadata& o);
static inline void PrintTo(const ::android::hardware::audio::common::V7_0::SourceMetadata& o, ::std::ostream*);
static inline bool operator==(const ::android::hardware::audio::common::V7_0::SourceMetadata& lhs, const ::android::hardware::audio::common::V7_0::SourceMetadata& rhs);
static inline bool operator!=(const ::android::hardware::audio::common::V7_0::SourceMetadata& lhs, const ::android::hardware::audio::common::V7_0::SourceMetadata& rhs);

static inline std::string toString(const ::android::hardware::audio::common::V7_0::RecordTrackMetadata::Destination& o);
static inline void PrintTo(const ::android::hardware::audio::common::V7_0::RecordTrackMetadata::Destination& o, ::std::ostream*);
static inline bool operator==(const ::android::hardware::audio::common::V7_0::RecordTrackMetadata::Destination& lhs, const ::android::hardware::audio::common::V7_0::RecordTrackMetadata::Destination& rhs);
static inline bool operator!=(const ::android::hardware::audio::common::V7_0::RecordTrackMetadata::Destination& lhs, const ::android::hardware::audio::common::V7_0::RecordTrackMetadata::Destination& rhs);

static inline std::string toString(const ::android::hardware::audio::common::V7_0::RecordTrackMetadata& o);
static inline void PrintTo(const ::android::hardware::audio::common::V7_0::RecordTrackMetadata& o, ::std::ostream*);
static inline bool operator==(const ::android::hardware::audio::common::V7_0::RecordTrackMetadata& lhs, const ::android::hardware::audio::common::V7_0::RecordTrackMetadata& rhs);
static inline bool operator!=(const ::android::hardware::audio::common::V7_0::RecordTrackMetadata& lhs, const ::android::hardware::audio::common::V7_0::RecordTrackMetadata& rhs);

static inline std::string toString(const ::android::hardware::audio::common::V7_0::SinkMetadata& o);
static inline void PrintTo(const ::android::hardware::audio::common::V7_0::SinkMetadata& o, ::std::ostream*);
static inline bool operator==(const ::android::hardware::audio::common::V7_0::SinkMetadata& lhs, const ::android::hardware::audio::common::V7_0::SinkMetadata& rhs);
static inline bool operator!=(const ::android::hardware::audio::common::V7_0::SinkMetadata& lhs, const ::android::hardware::audio::common::V7_0::SinkMetadata& rhs);

static inline std::string toString(const ::android::hardware::audio::common::V7_0::AudioGain& o);
static inline void PrintTo(const ::android::hardware::audio::common::V7_0::AudioGain& o, ::std::ostream*);
static inline bool operator==(const ::android::hardware::audio::common::V7_0::AudioGain& lhs, const ::android::hardware::audio::common::V7_0::AudioGain& rhs);
static inline bool operator!=(const ::android::hardware::audio::common::V7_0::AudioGain& lhs, const ::android::hardware::audio::common::V7_0::AudioGain& rhs);

static inline std::string toString(const ::android::hardware::audio::common::V7_0::AudioGainConfig& o);
static inline void PrintTo(const ::android::hardware::audio::common::V7_0::AudioGainConfig& o, ::std::ostream*);
static inline bool operator==(const ::android::hardware::audio::common::V7_0::AudioGainConfig& lhs, const ::android::hardware::audio::common::V7_0::AudioGainConfig& rhs);
static inline bool operator!=(const ::android::hardware::audio::common::V7_0::AudioGainConfig& lhs, const ::android::hardware::audio::common::V7_0::AudioGainConfig& rhs);

static inline std::string toString(const ::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::AudioPortMixExt::UseCase& o);
static inline void PrintTo(const ::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::AudioPortMixExt::UseCase& o, ::std::ostream*);
static inline bool operator==(const ::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::AudioPortMixExt::UseCase& lhs, const ::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::AudioPortMixExt::UseCase& rhs);
static inline bool operator!=(const ::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::AudioPortMixExt::UseCase& lhs, const ::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::AudioPortMixExt::UseCase& rhs);

static inline std::string toString(const ::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::AudioPortMixExt& o);
static inline void PrintTo(const ::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::AudioPortMixExt& o, ::std::ostream*);
static inline bool operator==(const ::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::AudioPortMixExt& lhs, const ::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::AudioPortMixExt& rhs);
static inline bool operator!=(const ::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::AudioPortMixExt& lhs, const ::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::AudioPortMixExt& rhs);

static inline std::string toString(const ::android::hardware::audio::common::V7_0::AudioPortExtendedInfo& o);
static inline void PrintTo(const ::android::hardware::audio::common::V7_0::AudioPortExtendedInfo& o, ::std::ostream*);
static inline bool operator==(const ::android::hardware::audio::common::V7_0::AudioPortExtendedInfo& lhs, const ::android::hardware::audio::common::V7_0::AudioPortExtendedInfo& rhs);
static inline bool operator!=(const ::android::hardware::audio::common::V7_0::AudioPortExtendedInfo& lhs, const ::android::hardware::audio::common::V7_0::AudioPortExtendedInfo& rhs);

static inline std::string toString(const ::android::hardware::audio::common::V7_0::AudioPortConfig::OptionalGain& o);
static inline void PrintTo(const ::android::hardware::audio::common::V7_0::AudioPortConfig::OptionalGain& o, ::std::ostream*);
static inline bool operator==(const ::android::hardware::audio::common::V7_0::AudioPortConfig::OptionalGain& lhs, const ::android::hardware::audio::common::V7_0::AudioPortConfig::OptionalGain& rhs);
static inline bool operator!=(const ::android::hardware::audio::common::V7_0::AudioPortConfig::OptionalGain& lhs, const ::android::hardware::audio::common::V7_0::AudioPortConfig::OptionalGain& rhs);

static inline std::string toString(const ::android::hardware::audio::common::V7_0::AudioPortConfig& o);
static inline void PrintTo(const ::android::hardware::audio::common::V7_0::AudioPortConfig& o, ::std::ostream*);
static inline bool operator==(const ::android::hardware::audio::common::V7_0::AudioPortConfig& lhs, const ::android::hardware::audio::common::V7_0::AudioPortConfig& rhs);
static inline bool operator!=(const ::android::hardware::audio::common::V7_0::AudioPortConfig& lhs, const ::android::hardware::audio::common::V7_0::AudioPortConfig& rhs);

static inline std::string toString(const ::android::hardware::audio::common::V7_0::AudioPort& o);
static inline void PrintTo(const ::android::hardware::audio::common::V7_0::AudioPort& o, ::std::ostream*);
static inline bool operator==(const ::android::hardware::audio::common::V7_0::AudioPort& lhs, const ::android::hardware::audio::common::V7_0::AudioPort& rhs);
static inline bool operator!=(const ::android::hardware::audio::common::V7_0::AudioPort& lhs, const ::android::hardware::audio::common::V7_0::AudioPort& rhs);

//
// type header definitions for package
//

static inline std::string toString(const ::android::hardware::audio::common::V7_0::Uuid& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".timeLow = ";
    os += ::android::hardware::toString(o.timeLow);
    os += ", .timeMid = ";
    os += ::android::hardware::toString(o.timeMid);
    os += ", .versionAndTimeHigh = ";
    os += ::android::hardware::toString(o.versionAndTimeHigh);
    os += ", .variantAndClockSeqHigh = ";
    os += ::android::hardware::toString(o.variantAndClockSeqHigh);
    os += ", .node = ";
    os += ::android::hardware::toString(o.node);
    os += "}"; return os;
}

static inline void PrintTo(const ::android::hardware::audio::common::V7_0::Uuid& o, ::std::ostream* os) {
    *os << toString(o);
}

static inline bool operator==(const ::android::hardware::audio::common::V7_0::Uuid& lhs, const ::android::hardware::audio::common::V7_0::Uuid& rhs) {
    if (lhs.timeLow != rhs.timeLow) {
        return false;
    }
    if (lhs.timeMid != rhs.timeMid) {
        return false;
    }
    if (lhs.versionAndTimeHigh != rhs.versionAndTimeHigh) {
        return false;
    }
    if (lhs.variantAndClockSeqHigh != rhs.variantAndClockSeqHigh) {
        return false;
    }
    if (lhs.node != rhs.node) {
        return false;
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::audio::common::V7_0::Uuid& lhs, const ::android::hardware::audio::common::V7_0::Uuid& rhs){
    return !(lhs == rhs);
}

template<>
inline std::string toString<::android::hardware::audio::common::V7_0::AudioSessionConsts>(int32_t o) {
    using ::android::hardware::details::toHexString;
    std::string os;
    ::android::hardware::hidl_bitfield<::android::hardware::audio::common::V7_0::AudioSessionConsts> flipped = 0;
    bool first = true;
    if ((o & ::android::hardware::audio::common::V7_0::AudioSessionConsts::DEVICE) == static_cast<int32_t>(::android::hardware::audio::common::V7_0::AudioSessionConsts::DEVICE)) {
        os += (first ? "" : " | ");
        os += "DEVICE";
        first = false;
        flipped |= ::android::hardware::audio::common::V7_0::AudioSessionConsts::DEVICE;
    }
    if ((o & ::android::hardware::audio::common::V7_0::AudioSessionConsts::OUTPUT_STAGE) == static_cast<int32_t>(::android::hardware::audio::common::V7_0::AudioSessionConsts::OUTPUT_STAGE)) {
        os += (first ? "" : " | ");
        os += "OUTPUT_STAGE";
        first = false;
        flipped |= ::android::hardware::audio::common::V7_0::AudioSessionConsts::OUTPUT_STAGE;
    }
    if ((o & ::android::hardware::audio::common::V7_0::AudioSessionConsts::OUTPUT_MIX) == static_cast<int32_t>(::android::hardware::audio::common::V7_0::AudioSessionConsts::OUTPUT_MIX)) {
        os += (first ? "" : " | ");
        os += "OUTPUT_MIX";
        first = false;
        flipped |= ::android::hardware::audio::common::V7_0::AudioSessionConsts::OUTPUT_MIX;
    }
    if (o != flipped) {
        os += (first ? "" : " | ");
        os += toHexString(o & (~flipped));
    }os += " (";
    os += toHexString(o);
    os += ")";
    return os;
}

static inline std::string toString(::android::hardware::audio::common::V7_0::AudioSessionConsts o) {
    using ::android::hardware::details::toHexString;
    if (o == ::android::hardware::audio::common::V7_0::AudioSessionConsts::DEVICE) {
        return "DEVICE";
    }
    if (o == ::android::hardware::audio::common::V7_0::AudioSessionConsts::OUTPUT_STAGE) {
        return "OUTPUT_STAGE";
    }
    if (o == ::android::hardware::audio::common::V7_0::AudioSessionConsts::OUTPUT_MIX) {
        return "OUTPUT_MIX";
    }
    std::string os;
    os += toHexString(static_cast<int32_t>(o));
    return os;
}

static inline void PrintTo(::android::hardware::audio::common::V7_0::AudioSessionConsts o, ::std::ostream* os) {
    *os << toString(o);
}

static inline std::string toString(const ::android::hardware::audio::common::V7_0::AudioConfigBase& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".format = ";
    os += ::android::hardware::toString(o.format);
    os += ", .sampleRateHz = ";
    os += ::android::hardware::toString(o.sampleRateHz);
    os += ", .channelMask = ";
    os += ::android::hardware::toString(o.channelMask);
    os += "}"; return os;
}

static inline void PrintTo(const ::android::hardware::audio::common::V7_0::AudioConfigBase& o, ::std::ostream* os) {
    *os << toString(o);
}

static inline bool operator==(const ::android::hardware::audio::common::V7_0::AudioConfigBase& lhs, const ::android::hardware::audio::common::V7_0::AudioConfigBase& rhs) {
    if (lhs.format != rhs.format) {
        return false;
    }
    if (lhs.sampleRateHz != rhs.sampleRateHz) {
        return false;
    }
    if (lhs.channelMask != rhs.channelMask) {
        return false;
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::audio::common::V7_0::AudioConfigBase& lhs, const ::android::hardware::audio::common::V7_0::AudioConfigBase& rhs){
    return !(lhs == rhs);
}

static inline std::string toString(const ::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::Format& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";

    switch (o.getDiscriminator()) {
        case ::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::Format::hidl_discriminator::unspecified: {
            os += ".unspecified = ";
            os += toString(o.unspecified());
            break;
        }
        case ::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::Format::hidl_discriminator::value: {
            os += ".value = ";
            os += toString(o.value());
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

static inline void PrintTo(const ::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::Format& o, ::std::ostream* os) {
    *os << toString(o);
}

static inline bool operator==(const ::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::Format& lhs, const ::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::Format& rhs) {
    if (lhs.getDiscriminator() != rhs.getDiscriminator()) {
        return false;
    }
    switch (lhs.getDiscriminator()) {
        case ::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::Format::hidl_discriminator::unspecified: {
            return (lhs.unspecified() == rhs.unspecified());
        }
        case ::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::Format::hidl_discriminator::value: {
            return (lhs.value() == rhs.value());
        }
        default: {
            ::android::hardware::details::logAlwaysFatal((
                    "Unknown union discriminator (value: " +
                    std::to_string((uint8_t) lhs.getDiscriminator()) + ").").c_str());
        }
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::Format& lhs, const ::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::Format& rhs){
    return !(lhs == rhs);
}

static inline std::string toString(const ::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::SampleRate& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";

    switch (o.getDiscriminator()) {
        case ::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::SampleRate::hidl_discriminator::unspecified: {
            os += ".unspecified = ";
            os += toString(o.unspecified());
            break;
        }
        case ::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::SampleRate::hidl_discriminator::value: {
            os += ".value = ";
            os += toString(o.value());
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

static inline void PrintTo(const ::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::SampleRate& o, ::std::ostream* os) {
    *os << toString(o);
}

static inline bool operator==(const ::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::SampleRate& lhs, const ::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::SampleRate& rhs) {
    if (lhs.getDiscriminator() != rhs.getDiscriminator()) {
        return false;
    }
    switch (lhs.getDiscriminator()) {
        case ::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::SampleRate::hidl_discriminator::unspecified: {
            return (lhs.unspecified() == rhs.unspecified());
        }
        case ::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::SampleRate::hidl_discriminator::value: {
            return (lhs.value() == rhs.value());
        }
        default: {
            ::android::hardware::details::logAlwaysFatal((
                    "Unknown union discriminator (value: " +
                    std::to_string((uint8_t) lhs.getDiscriminator()) + ").").c_str());
        }
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::SampleRate& lhs, const ::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::SampleRate& rhs){
    return !(lhs == rhs);
}

static inline std::string toString(const ::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::ChannelMask& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";

    switch (o.getDiscriminator()) {
        case ::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::ChannelMask::hidl_discriminator::unspecified: {
            os += ".unspecified = ";
            os += toString(o.unspecified());
            break;
        }
        case ::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::ChannelMask::hidl_discriminator::value: {
            os += ".value = ";
            os += toString(o.value());
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

static inline void PrintTo(const ::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::ChannelMask& o, ::std::ostream* os) {
    *os << toString(o);
}

static inline bool operator==(const ::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::ChannelMask& lhs, const ::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::ChannelMask& rhs) {
    if (lhs.getDiscriminator() != rhs.getDiscriminator()) {
        return false;
    }
    switch (lhs.getDiscriminator()) {
        case ::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::ChannelMask::hidl_discriminator::unspecified: {
            return (lhs.unspecified() == rhs.unspecified());
        }
        case ::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::ChannelMask::hidl_discriminator::value: {
            return (lhs.value() == rhs.value());
        }
        default: {
            ::android::hardware::details::logAlwaysFatal((
                    "Unknown union discriminator (value: " +
                    std::to_string((uint8_t) lhs.getDiscriminator()) + ").").c_str());
        }
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::ChannelMask& lhs, const ::android::hardware::audio::common::V7_0::AudioConfigBaseOptional::ChannelMask& rhs){
    return !(lhs == rhs);
}

static inline std::string toString(const ::android::hardware::audio::common::V7_0::AudioConfigBaseOptional& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".format = ";
    os += ::android::hardware::audio::common::V7_0::toString(o.format);
    os += ", .sampleRateHz = ";
    os += ::android::hardware::audio::common::V7_0::toString(o.sampleRateHz);
    os += ", .channelMask = ";
    os += ::android::hardware::audio::common::V7_0::toString(o.channelMask);
    os += "}"; return os;
}

static inline void PrintTo(const ::android::hardware::audio::common::V7_0::AudioConfigBaseOptional& o, ::std::ostream* os) {
    *os << toString(o);
}

static inline bool operator==(const ::android::hardware::audio::common::V7_0::AudioConfigBaseOptional& lhs, const ::android::hardware::audio::common::V7_0::AudioConfigBaseOptional& rhs) {
    if (lhs.format != rhs.format) {
        return false;
    }
    if (lhs.sampleRateHz != rhs.sampleRateHz) {
        return false;
    }
    if (lhs.channelMask != rhs.channelMask) {
        return false;
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::audio::common::V7_0::AudioConfigBaseOptional& lhs, const ::android::hardware::audio::common::V7_0::AudioConfigBaseOptional& rhs){
    return !(lhs == rhs);
}

static inline std::string toString(const ::android::hardware::audio::common::V7_0::AudioProfile& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".format = ";
    os += ::android::hardware::toString(o.format);
    os += ", .sampleRates = ";
    os += ::android::hardware::toString(o.sampleRates);
    os += ", .channelMasks = ";
    os += ::android::hardware::toString(o.channelMasks);
    os += "}"; return os;
}

static inline void PrintTo(const ::android::hardware::audio::common::V7_0::AudioProfile& o, ::std::ostream* os) {
    *os << toString(o);
}

static inline bool operator==(const ::android::hardware::audio::common::V7_0::AudioProfile& lhs, const ::android::hardware::audio::common::V7_0::AudioProfile& rhs) {
    if (lhs.format != rhs.format) {
        return false;
    }
    if (lhs.sampleRates != rhs.sampleRates) {
        return false;
    }
    if (lhs.channelMasks != rhs.channelMasks) {
        return false;
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::audio::common::V7_0::AudioProfile& lhs, const ::android::hardware::audio::common::V7_0::AudioProfile& rhs){
    return !(lhs == rhs);
}

static inline std::string toString(const ::android::hardware::audio::common::V7_0::AudioTransport::AudioCapability& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";

    switch (o.getDiscriminator()) {
        case ::android::hardware::audio::common::V7_0::AudioTransport::AudioCapability::hidl_discriminator::profile: {
            os += ".profile = ";
            os += toString(o.profile());
            break;
        }
        case ::android::hardware::audio::common::V7_0::AudioTransport::AudioCapability::hidl_discriminator::edid: {
            os += ".edid = ";
            os += toString(o.edid());
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

static inline void PrintTo(const ::android::hardware::audio::common::V7_0::AudioTransport::AudioCapability& o, ::std::ostream* os) {
    *os << toString(o);
}

static inline bool operator==(const ::android::hardware::audio::common::V7_0::AudioTransport::AudioCapability& lhs, const ::android::hardware::audio::common::V7_0::AudioTransport::AudioCapability& rhs) {
    if (lhs.getDiscriminator() != rhs.getDiscriminator()) {
        return false;
    }
    switch (lhs.getDiscriminator()) {
        case ::android::hardware::audio::common::V7_0::AudioTransport::AudioCapability::hidl_discriminator::profile: {
            return (lhs.profile() == rhs.profile());
        }
        case ::android::hardware::audio::common::V7_0::AudioTransport::AudioCapability::hidl_discriminator::edid: {
            return (lhs.edid() == rhs.edid());
        }
        default: {
            ::android::hardware::details::logAlwaysFatal((
                    "Unknown union discriminator (value: " +
                    std::to_string((uint8_t) lhs.getDiscriminator()) + ").").c_str());
        }
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::audio::common::V7_0::AudioTransport::AudioCapability& lhs, const ::android::hardware::audio::common::V7_0::AudioTransport::AudioCapability& rhs){
    return !(lhs == rhs);
}

static inline std::string toString(const ::android::hardware::audio::common::V7_0::AudioTransport& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".audioCapability = ";
    os += ::android::hardware::audio::common::V7_0::toString(o.audioCapability);
    os += ", .encapsulationType = ";
    os += ::android::hardware::toString(o.encapsulationType);
    os += "}"; return os;
}

static inline void PrintTo(const ::android::hardware::audio::common::V7_0::AudioTransport& o, ::std::ostream* os) {
    *os << toString(o);
}

static inline bool operator==(const ::android::hardware::audio::common::V7_0::AudioTransport& lhs, const ::android::hardware::audio::common::V7_0::AudioTransport& rhs) {
    if (lhs.audioCapability != rhs.audioCapability) {
        return false;
    }
    if (lhs.encapsulationType != rhs.encapsulationType) {
        return false;
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::audio::common::V7_0::AudioTransport& lhs, const ::android::hardware::audio::common::V7_0::AudioTransport& rhs){
    return !(lhs == rhs);
}

template<>
inline std::string toString<::android::hardware::audio::common::V7_0::AudioMode>(int32_t o) {
    using ::android::hardware::details::toHexString;
    std::string os;
    ::android::hardware::hidl_bitfield<::android::hardware::audio::common::V7_0::AudioMode> flipped = 0;
    bool first = true;
    if ((o & ::android::hardware::audio::common::V7_0::AudioMode::NORMAL) == static_cast<int32_t>(::android::hardware::audio::common::V7_0::AudioMode::NORMAL)) {
        os += (first ? "" : " | ");
        os += "NORMAL";
        first = false;
        flipped |= ::android::hardware::audio::common::V7_0::AudioMode::NORMAL;
    }
    if ((o & ::android::hardware::audio::common::V7_0::AudioMode::RINGTONE) == static_cast<int32_t>(::android::hardware::audio::common::V7_0::AudioMode::RINGTONE)) {
        os += (first ? "" : " | ");
        os += "RINGTONE";
        first = false;
        flipped |= ::android::hardware::audio::common::V7_0::AudioMode::RINGTONE;
    }
    if ((o & ::android::hardware::audio::common::V7_0::AudioMode::IN_CALL) == static_cast<int32_t>(::android::hardware::audio::common::V7_0::AudioMode::IN_CALL)) {
        os += (first ? "" : " | ");
        os += "IN_CALL";
        first = false;
        flipped |= ::android::hardware::audio::common::V7_0::AudioMode::IN_CALL;
    }
    if ((o & ::android::hardware::audio::common::V7_0::AudioMode::IN_COMMUNICATION) == static_cast<int32_t>(::android::hardware::audio::common::V7_0::AudioMode::IN_COMMUNICATION)) {
        os += (first ? "" : " | ");
        os += "IN_COMMUNICATION";
        first = false;
        flipped |= ::android::hardware::audio::common::V7_0::AudioMode::IN_COMMUNICATION;
    }
    if ((o & ::android::hardware::audio::common::V7_0::AudioMode::CALL_SCREEN) == static_cast<int32_t>(::android::hardware::audio::common::V7_0::AudioMode::CALL_SCREEN)) {
        os += (first ? "" : " | ");
        os += "CALL_SCREEN";
        first = false;
        flipped |= ::android::hardware::audio::common::V7_0::AudioMode::CALL_SCREEN;
    }
    if (o != flipped) {
        os += (first ? "" : " | ");
        os += toHexString(o & (~flipped));
    }os += " (";
    os += toHexString(o);
    os += ")";
    return os;
}

static inline std::string toString(::android::hardware::audio::common::V7_0::AudioMode o) {
    using ::android::hardware::details::toHexString;
    if (o == ::android::hardware::audio::common::V7_0::AudioMode::NORMAL) {
        return "NORMAL";
    }
    if (o == ::android::hardware::audio::common::V7_0::AudioMode::RINGTONE) {
        return "RINGTONE";
    }
    if (o == ::android::hardware::audio::common::V7_0::AudioMode::IN_CALL) {
        return "IN_CALL";
    }
    if (o == ::android::hardware::audio::common::V7_0::AudioMode::IN_COMMUNICATION) {
        return "IN_COMMUNICATION";
    }
    if (o == ::android::hardware::audio::common::V7_0::AudioMode::CALL_SCREEN) {
        return "CALL_SCREEN";
    }
    std::string os;
    os += toHexString(static_cast<int32_t>(o));
    return os;
}

static inline void PrintTo(::android::hardware::audio::common::V7_0::AudioMode o, ::std::ostream* os) {
    *os << toString(o);
}

static inline std::string toString(const ::android::hardware::audio::common::V7_0::DeviceAddress::Address::Alsa& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".card = ";
    os += ::android::hardware::toString(o.card);
    os += ", .device = ";
    os += ::android::hardware::toString(o.device);
    os += "}"; return os;
}

static inline void PrintTo(const ::android::hardware::audio::common::V7_0::DeviceAddress::Address::Alsa& o, ::std::ostream* os) {
    *os << toString(o);
}

static inline bool operator==(const ::android::hardware::audio::common::V7_0::DeviceAddress::Address::Alsa& lhs, const ::android::hardware::audio::common::V7_0::DeviceAddress::Address::Alsa& rhs) {
    if (lhs.card != rhs.card) {
        return false;
    }
    if (lhs.device != rhs.device) {
        return false;
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::audio::common::V7_0::DeviceAddress::Address::Alsa& lhs, const ::android::hardware::audio::common::V7_0::DeviceAddress::Address::Alsa& rhs){
    return !(lhs == rhs);
}

static inline std::string toString(const ::android::hardware::audio::common::V7_0::DeviceAddress::Address& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";

    switch (o.getDiscriminator()) {
        case ::android::hardware::audio::common::V7_0::DeviceAddress::Address::hidl_discriminator::id: {
            os += ".id = ";
            os += toString(o.id());
            break;
        }
        case ::android::hardware::audio::common::V7_0::DeviceAddress::Address::hidl_discriminator::mac: {
            os += ".mac = ";
            os += toString(o.mac());
            break;
        }
        case ::android::hardware::audio::common::V7_0::DeviceAddress::Address::hidl_discriminator::ipv4: {
            os += ".ipv4 = ";
            os += toString(o.ipv4());
            break;
        }
        case ::android::hardware::audio::common::V7_0::DeviceAddress::Address::hidl_discriminator::ipv6: {
            os += ".ipv6 = ";
            os += toString(o.ipv6());
            break;
        }
        case ::android::hardware::audio::common::V7_0::DeviceAddress::Address::hidl_discriminator::alsa: {
            os += ".alsa = ";
            os += toString(o.alsa());
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

static inline void PrintTo(const ::android::hardware::audio::common::V7_0::DeviceAddress::Address& o, ::std::ostream* os) {
    *os << toString(o);
}

static inline bool operator==(const ::android::hardware::audio::common::V7_0::DeviceAddress::Address& lhs, const ::android::hardware::audio::common::V7_0::DeviceAddress::Address& rhs) {
    if (lhs.getDiscriminator() != rhs.getDiscriminator()) {
        return false;
    }
    switch (lhs.getDiscriminator()) {
        case ::android::hardware::audio::common::V7_0::DeviceAddress::Address::hidl_discriminator::id: {
            return (lhs.id() == rhs.id());
        }
        case ::android::hardware::audio::common::V7_0::DeviceAddress::Address::hidl_discriminator::mac: {
            return (lhs.mac() == rhs.mac());
        }
        case ::android::hardware::audio::common::V7_0::DeviceAddress::Address::hidl_discriminator::ipv4: {
            return (lhs.ipv4() == rhs.ipv4());
        }
        case ::android::hardware::audio::common::V7_0::DeviceAddress::Address::hidl_discriminator::ipv6: {
            return (lhs.ipv6() == rhs.ipv6());
        }
        case ::android::hardware::audio::common::V7_0::DeviceAddress::Address::hidl_discriminator::alsa: {
            return (lhs.alsa() == rhs.alsa());
        }
        default: {
            ::android::hardware::details::logAlwaysFatal((
                    "Unknown union discriminator (value: " +
                    std::to_string((uint8_t) lhs.getDiscriminator()) + ").").c_str());
        }
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::audio::common::V7_0::DeviceAddress::Address& lhs, const ::android::hardware::audio::common::V7_0::DeviceAddress::Address& rhs){
    return !(lhs == rhs);
}

static inline std::string toString(const ::android::hardware::audio::common::V7_0::DeviceAddress& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".deviceType = ";
    os += ::android::hardware::toString(o.deviceType);
    os += ", .address = ";
    os += ::android::hardware::audio::common::V7_0::toString(o.address);
    os += "}"; return os;
}

static inline void PrintTo(const ::android::hardware::audio::common::V7_0::DeviceAddress& o, ::std::ostream* os) {
    *os << toString(o);
}

static inline bool operator==(const ::android::hardware::audio::common::V7_0::DeviceAddress& lhs, const ::android::hardware::audio::common::V7_0::DeviceAddress& rhs) {
    if (lhs.deviceType != rhs.deviceType) {
        return false;
    }
    if (lhs.address != rhs.address) {
        return false;
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::audio::common::V7_0::DeviceAddress& lhs, const ::android::hardware::audio::common::V7_0::DeviceAddress& rhs){
    return !(lhs == rhs);
}

template<>
inline std::string toString<::android::hardware::audio::common::V7_0::AudioEncapsulationMode>(int32_t o) {
    using ::android::hardware::details::toHexString;
    std::string os;
    ::android::hardware::hidl_bitfield<::android::hardware::audio::common::V7_0::AudioEncapsulationMode> flipped = 0;
    bool first = true;
    if ((o & ::android::hardware::audio::common::V7_0::AudioEncapsulationMode::NONE) == static_cast<int32_t>(::android::hardware::audio::common::V7_0::AudioEncapsulationMode::NONE)) {
        os += (first ? "" : " | ");
        os += "NONE";
        first = false;
        flipped |= ::android::hardware::audio::common::V7_0::AudioEncapsulationMode::NONE;
    }
    if ((o & ::android::hardware::audio::common::V7_0::AudioEncapsulationMode::ELEMENTARY_STREAM) == static_cast<int32_t>(::android::hardware::audio::common::V7_0::AudioEncapsulationMode::ELEMENTARY_STREAM)) {
        os += (first ? "" : " | ");
        os += "ELEMENTARY_STREAM";
        first = false;
        flipped |= ::android::hardware::audio::common::V7_0::AudioEncapsulationMode::ELEMENTARY_STREAM;
    }
    if ((o & ::android::hardware::audio::common::V7_0::AudioEncapsulationMode::HANDLE) == static_cast<int32_t>(::android::hardware::audio::common::V7_0::AudioEncapsulationMode::HANDLE)) {
        os += (first ? "" : " | ");
        os += "HANDLE";
        first = false;
        flipped |= ::android::hardware::audio::common::V7_0::AudioEncapsulationMode::HANDLE;
    }
    if (o != flipped) {
        os += (first ? "" : " | ");
        os += toHexString(o & (~flipped));
    }os += " (";
    os += toHexString(o);
    os += ")";
    return os;
}

static inline std::string toString(::android::hardware::audio::common::V7_0::AudioEncapsulationMode o) {
    using ::android::hardware::details::toHexString;
    if (o == ::android::hardware::audio::common::V7_0::AudioEncapsulationMode::NONE) {
        return "NONE";
    }
    if (o == ::android::hardware::audio::common::V7_0::AudioEncapsulationMode::ELEMENTARY_STREAM) {
        return "ELEMENTARY_STREAM";
    }
    if (o == ::android::hardware::audio::common::V7_0::AudioEncapsulationMode::HANDLE) {
        return "HANDLE";
    }
    std::string os;
    os += toHexString(static_cast<int32_t>(o));
    return os;
}

static inline void PrintTo(::android::hardware::audio::common::V7_0::AudioEncapsulationMode o, ::std::ostream* os) {
    *os << toString(o);
}

template<>
inline std::string toString<::android::hardware::audio::common::V7_0::AudioEncapsulationMetadataType>(int32_t o) {
    using ::android::hardware::details::toHexString;
    std::string os;
    ::android::hardware::hidl_bitfield<::android::hardware::audio::common::V7_0::AudioEncapsulationMetadataType> flipped = 0;
    bool first = true;
    if ((o & ::android::hardware::audio::common::V7_0::AudioEncapsulationMetadataType::NONE) == static_cast<int32_t>(::android::hardware::audio::common::V7_0::AudioEncapsulationMetadataType::NONE)) {
        os += (first ? "" : " | ");
        os += "NONE";
        first = false;
        flipped |= ::android::hardware::audio::common::V7_0::AudioEncapsulationMetadataType::NONE;
    }
    if ((o & ::android::hardware::audio::common::V7_0::AudioEncapsulationMetadataType::FRAMEWORK_TUNER) == static_cast<int32_t>(::android::hardware::audio::common::V7_0::AudioEncapsulationMetadataType::FRAMEWORK_TUNER)) {
        os += (first ? "" : " | ");
        os += "FRAMEWORK_TUNER";
        first = false;
        flipped |= ::android::hardware::audio::common::V7_0::AudioEncapsulationMetadataType::FRAMEWORK_TUNER;
    }
    if ((o & ::android::hardware::audio::common::V7_0::AudioEncapsulationMetadataType::DVB_AD_DESCRIPTOR) == static_cast<int32_t>(::android::hardware::audio::common::V7_0::AudioEncapsulationMetadataType::DVB_AD_DESCRIPTOR)) {
        os += (first ? "" : " | ");
        os += "DVB_AD_DESCRIPTOR";
        first = false;
        flipped |= ::android::hardware::audio::common::V7_0::AudioEncapsulationMetadataType::DVB_AD_DESCRIPTOR;
    }
    if (o != flipped) {
        os += (first ? "" : " | ");
        os += toHexString(o & (~flipped));
    }os += " (";
    os += toHexString(o);
    os += ")";
    return os;
}

static inline std::string toString(::android::hardware::audio::common::V7_0::AudioEncapsulationMetadataType o) {
    using ::android::hardware::details::toHexString;
    if (o == ::android::hardware::audio::common::V7_0::AudioEncapsulationMetadataType::NONE) {
        return "NONE";
    }
    if (o == ::android::hardware::audio::common::V7_0::AudioEncapsulationMetadataType::FRAMEWORK_TUNER) {
        return "FRAMEWORK_TUNER";
    }
    if (o == ::android::hardware::audio::common::V7_0::AudioEncapsulationMetadataType::DVB_AD_DESCRIPTOR) {
        return "DVB_AD_DESCRIPTOR";
    }
    std::string os;
    os += toHexString(static_cast<int32_t>(o));
    return os;
}

static inline void PrintTo(::android::hardware::audio::common::V7_0::AudioEncapsulationMetadataType o, ::std::ostream* os) {
    *os << toString(o);
}

static inline std::string toString(const ::android::hardware::audio::common::V7_0::AudioOffloadInfo& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".base = ";
    os += ::android::hardware::audio::common::V7_0::toString(o.base);
    os += ", .streamType = ";
    os += ::android::hardware::toString(o.streamType);
    os += ", .bitRatePerSecond = ";
    os += ::android::hardware::toString(o.bitRatePerSecond);
    os += ", .durationMicroseconds = ";
    os += ::android::hardware::toString(o.durationMicroseconds);
    os += ", .hasVideo = ";
    os += ::android::hardware::toString(o.hasVideo);
    os += ", .isStreaming = ";
    os += ::android::hardware::toString(o.isStreaming);
    os += ", .bitWidth = ";
    os += ::android::hardware::toString(o.bitWidth);
    os += ", .bufferSize = ";
    os += ::android::hardware::toString(o.bufferSize);
    os += ", .usage = ";
    os += ::android::hardware::toString(o.usage);
    os += ", .encapsulationMode = ";
    os += ::android::hardware::audio::common::V7_0::toString(o.encapsulationMode);
    os += ", .contentId = ";
    os += ::android::hardware::toString(o.contentId);
    os += ", .syncId = ";
    os += ::android::hardware::toString(o.syncId);
    os += "}"; return os;
}

static inline void PrintTo(const ::android::hardware::audio::common::V7_0::AudioOffloadInfo& o, ::std::ostream* os) {
    *os << toString(o);
}

static inline bool operator==(const ::android::hardware::audio::common::V7_0::AudioOffloadInfo& lhs, const ::android::hardware::audio::common::V7_0::AudioOffloadInfo& rhs) {
    if (lhs.base != rhs.base) {
        return false;
    }
    if (lhs.streamType != rhs.streamType) {
        return false;
    }
    if (lhs.bitRatePerSecond != rhs.bitRatePerSecond) {
        return false;
    }
    if (lhs.durationMicroseconds != rhs.durationMicroseconds) {
        return false;
    }
    if (lhs.hasVideo != rhs.hasVideo) {
        return false;
    }
    if (lhs.isStreaming != rhs.isStreaming) {
        return false;
    }
    if (lhs.bitWidth != rhs.bitWidth) {
        return false;
    }
    if (lhs.bufferSize != rhs.bufferSize) {
        return false;
    }
    if (lhs.usage != rhs.usage) {
        return false;
    }
    if (lhs.encapsulationMode != rhs.encapsulationMode) {
        return false;
    }
    if (lhs.contentId != rhs.contentId) {
        return false;
    }
    if (lhs.syncId != rhs.syncId) {
        return false;
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::audio::common::V7_0::AudioOffloadInfo& lhs, const ::android::hardware::audio::common::V7_0::AudioOffloadInfo& rhs){
    return !(lhs == rhs);
}

static inline std::string toString(const ::android::hardware::audio::common::V7_0::AudioConfig::OffloadInfo& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";

    switch (o.getDiscriminator()) {
        case ::android::hardware::audio::common::V7_0::AudioConfig::OffloadInfo::hidl_discriminator::unspecified: {
            os += ".unspecified = ";
            os += toString(o.unspecified());
            break;
        }
        case ::android::hardware::audio::common::V7_0::AudioConfig::OffloadInfo::hidl_discriminator::info: {
            os += ".info = ";
            os += toString(o.info());
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

static inline void PrintTo(const ::android::hardware::audio::common::V7_0::AudioConfig::OffloadInfo& o, ::std::ostream* os) {
    *os << toString(o);
}

static inline bool operator==(const ::android::hardware::audio::common::V7_0::AudioConfig::OffloadInfo& lhs, const ::android::hardware::audio::common::V7_0::AudioConfig::OffloadInfo& rhs) {
    if (lhs.getDiscriminator() != rhs.getDiscriminator()) {
        return false;
    }
    switch (lhs.getDiscriminator()) {
        case ::android::hardware::audio::common::V7_0::AudioConfig::OffloadInfo::hidl_discriminator::unspecified: {
            return (lhs.unspecified() == rhs.unspecified());
        }
        case ::android::hardware::audio::common::V7_0::AudioConfig::OffloadInfo::hidl_discriminator::info: {
            return (lhs.info() == rhs.info());
        }
        default: {
            ::android::hardware::details::logAlwaysFatal((
                    "Unknown union discriminator (value: " +
                    std::to_string((uint8_t) lhs.getDiscriminator()) + ").").c_str());
        }
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::audio::common::V7_0::AudioConfig::OffloadInfo& lhs, const ::android::hardware::audio::common::V7_0::AudioConfig::OffloadInfo& rhs){
    return !(lhs == rhs);
}

static inline std::string toString(const ::android::hardware::audio::common::V7_0::AudioConfig& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".base = ";
    os += ::android::hardware::audio::common::V7_0::toString(o.base);
    os += ", .offloadInfo = ";
    os += ::android::hardware::audio::common::V7_0::toString(o.offloadInfo);
    os += ", .frameCount = ";
    os += ::android::hardware::toString(o.frameCount);
    os += "}"; return os;
}

static inline void PrintTo(const ::android::hardware::audio::common::V7_0::AudioConfig& o, ::std::ostream* os) {
    *os << toString(o);
}

static inline bool operator==(const ::android::hardware::audio::common::V7_0::AudioConfig& lhs, const ::android::hardware::audio::common::V7_0::AudioConfig& rhs) {
    if (lhs.base != rhs.base) {
        return false;
    }
    if (lhs.offloadInfo != rhs.offloadInfo) {
        return false;
    }
    if (lhs.frameCount != rhs.frameCount) {
        return false;
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::audio::common::V7_0::AudioConfig& lhs, const ::android::hardware::audio::common::V7_0::AudioConfig& rhs){
    return !(lhs == rhs);
}

static inline std::string toString(const ::android::hardware::audio::common::V7_0::PlaybackTrackMetadata& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".usage = ";
    os += ::android::hardware::toString(o.usage);
    os += ", .contentType = ";
    os += ::android::hardware::toString(o.contentType);
    os += ", .gain = ";
    os += ::android::hardware::toString(o.gain);
    os += ", .channelMask = ";
    os += ::android::hardware::toString(o.channelMask);
    os += ", .tags = ";
    os += ::android::hardware::toString(o.tags);
    os += "}"; return os;
}

static inline void PrintTo(const ::android::hardware::audio::common::V7_0::PlaybackTrackMetadata& o, ::std::ostream* os) {
    *os << toString(o);
}

static inline bool operator==(const ::android::hardware::audio::common::V7_0::PlaybackTrackMetadata& lhs, const ::android::hardware::audio::common::V7_0::PlaybackTrackMetadata& rhs) {
    if (lhs.usage != rhs.usage) {
        return false;
    }
    if (lhs.contentType != rhs.contentType) {
        return false;
    }
    if (lhs.gain != rhs.gain) {
        return false;
    }
    if (lhs.channelMask != rhs.channelMask) {
        return false;
    }
    if (lhs.tags != rhs.tags) {
        return false;
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::audio::common::V7_0::PlaybackTrackMetadata& lhs, const ::android::hardware::audio::common::V7_0::PlaybackTrackMetadata& rhs){
    return !(lhs == rhs);
}

static inline std::string toString(const ::android::hardware::audio::common::V7_0::SourceMetadata& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".tracks = ";
    os += ::android::hardware::toString(o.tracks);
    os += "}"; return os;
}

static inline void PrintTo(const ::android::hardware::audio::common::V7_0::SourceMetadata& o, ::std::ostream* os) {
    *os << toString(o);
}

static inline bool operator==(const ::android::hardware::audio::common::V7_0::SourceMetadata& lhs, const ::android::hardware::audio::common::V7_0::SourceMetadata& rhs) {
    if (lhs.tracks != rhs.tracks) {
        return false;
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::audio::common::V7_0::SourceMetadata& lhs, const ::android::hardware::audio::common::V7_0::SourceMetadata& rhs){
    return !(lhs == rhs);
}

static inline std::string toString(const ::android::hardware::audio::common::V7_0::RecordTrackMetadata::Destination& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";

    switch (o.getDiscriminator()) {
        case ::android::hardware::audio::common::V7_0::RecordTrackMetadata::Destination::hidl_discriminator::unspecified: {
            os += ".unspecified = ";
            os += toString(o.unspecified());
            break;
        }
        case ::android::hardware::audio::common::V7_0::RecordTrackMetadata::Destination::hidl_discriminator::device: {
            os += ".device = ";
            os += toString(o.device());
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

static inline void PrintTo(const ::android::hardware::audio::common::V7_0::RecordTrackMetadata::Destination& o, ::std::ostream* os) {
    *os << toString(o);
}

static inline bool operator==(const ::android::hardware::audio::common::V7_0::RecordTrackMetadata::Destination& lhs, const ::android::hardware::audio::common::V7_0::RecordTrackMetadata::Destination& rhs) {
    if (lhs.getDiscriminator() != rhs.getDiscriminator()) {
        return false;
    }
    switch (lhs.getDiscriminator()) {
        case ::android::hardware::audio::common::V7_0::RecordTrackMetadata::Destination::hidl_discriminator::unspecified: {
            return (lhs.unspecified() == rhs.unspecified());
        }
        case ::android::hardware::audio::common::V7_0::RecordTrackMetadata::Destination::hidl_discriminator::device: {
            return (lhs.device() == rhs.device());
        }
        default: {
            ::android::hardware::details::logAlwaysFatal((
                    "Unknown union discriminator (value: " +
                    std::to_string((uint8_t) lhs.getDiscriminator()) + ").").c_str());
        }
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::audio::common::V7_0::RecordTrackMetadata::Destination& lhs, const ::android::hardware::audio::common::V7_0::RecordTrackMetadata::Destination& rhs){
    return !(lhs == rhs);
}

static inline std::string toString(const ::android::hardware::audio::common::V7_0::RecordTrackMetadata& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".source = ";
    os += ::android::hardware::toString(o.source);
    os += ", .gain = ";
    os += ::android::hardware::toString(o.gain);
    os += ", .destination = ";
    os += ::android::hardware::audio::common::V7_0::toString(o.destination);
    os += ", .channelMask = ";
    os += ::android::hardware::toString(o.channelMask);
    os += ", .tags = ";
    os += ::android::hardware::toString(o.tags);
    os += "}"; return os;
}

static inline void PrintTo(const ::android::hardware::audio::common::V7_0::RecordTrackMetadata& o, ::std::ostream* os) {
    *os << toString(o);
}

static inline bool operator==(const ::android::hardware::audio::common::V7_0::RecordTrackMetadata& lhs, const ::android::hardware::audio::common::V7_0::RecordTrackMetadata& rhs) {
    if (lhs.source != rhs.source) {
        return false;
    }
    if (lhs.gain != rhs.gain) {
        return false;
    }
    if (lhs.destination != rhs.destination) {
        return false;
    }
    if (lhs.channelMask != rhs.channelMask) {
        return false;
    }
    if (lhs.tags != rhs.tags) {
        return false;
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::audio::common::V7_0::RecordTrackMetadata& lhs, const ::android::hardware::audio::common::V7_0::RecordTrackMetadata& rhs){
    return !(lhs == rhs);
}

static inline std::string toString(const ::android::hardware::audio::common::V7_0::SinkMetadata& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".tracks = ";
    os += ::android::hardware::toString(o.tracks);
    os += "}"; return os;
}

static inline void PrintTo(const ::android::hardware::audio::common::V7_0::SinkMetadata& o, ::std::ostream* os) {
    *os << toString(o);
}

static inline bool operator==(const ::android::hardware::audio::common::V7_0::SinkMetadata& lhs, const ::android::hardware::audio::common::V7_0::SinkMetadata& rhs) {
    if (lhs.tracks != rhs.tracks) {
        return false;
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::audio::common::V7_0::SinkMetadata& lhs, const ::android::hardware::audio::common::V7_0::SinkMetadata& rhs){
    return !(lhs == rhs);
}

static inline std::string toString(const ::android::hardware::audio::common::V7_0::AudioGain& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".mode = ";
    os += ::android::hardware::toString(o.mode);
    os += ", .channelMask = ";
    os += ::android::hardware::toString(o.channelMask);
    os += ", .minValue = ";
    os += ::android::hardware::toString(o.minValue);
    os += ", .maxValue = ";
    os += ::android::hardware::toString(o.maxValue);
    os += ", .defaultValue = ";
    os += ::android::hardware::toString(o.defaultValue);
    os += ", .stepValue = ";
    os += ::android::hardware::toString(o.stepValue);
    os += ", .minRampMs = ";
    os += ::android::hardware::toString(o.minRampMs);
    os += ", .maxRampMs = ";
    os += ::android::hardware::toString(o.maxRampMs);
    os += "}"; return os;
}

static inline void PrintTo(const ::android::hardware::audio::common::V7_0::AudioGain& o, ::std::ostream* os) {
    *os << toString(o);
}

static inline bool operator==(const ::android::hardware::audio::common::V7_0::AudioGain& lhs, const ::android::hardware::audio::common::V7_0::AudioGain& rhs) {
    if (lhs.mode != rhs.mode) {
        return false;
    }
    if (lhs.channelMask != rhs.channelMask) {
        return false;
    }
    if (lhs.minValue != rhs.minValue) {
        return false;
    }
    if (lhs.maxValue != rhs.maxValue) {
        return false;
    }
    if (lhs.defaultValue != rhs.defaultValue) {
        return false;
    }
    if (lhs.stepValue != rhs.stepValue) {
        return false;
    }
    if (lhs.minRampMs != rhs.minRampMs) {
        return false;
    }
    if (lhs.maxRampMs != rhs.maxRampMs) {
        return false;
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::audio::common::V7_0::AudioGain& lhs, const ::android::hardware::audio::common::V7_0::AudioGain& rhs){
    return !(lhs == rhs);
}

static inline std::string toString(const ::android::hardware::audio::common::V7_0::AudioGainConfig& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".index = ";
    os += ::android::hardware::toString(o.index);
    os += ", .mode = ";
    os += ::android::hardware::toString(o.mode);
    os += ", .channelMask = ";
    os += ::android::hardware::toString(o.channelMask);
    os += ", .values = ";
    os += ::android::hardware::toString(o.values);
    os += ", .rampDurationMs = ";
    os += ::android::hardware::toString(o.rampDurationMs);
    os += "}"; return os;
}

static inline void PrintTo(const ::android::hardware::audio::common::V7_0::AudioGainConfig& o, ::std::ostream* os) {
    *os << toString(o);
}

static inline bool operator==(const ::android::hardware::audio::common::V7_0::AudioGainConfig& lhs, const ::android::hardware::audio::common::V7_0::AudioGainConfig& rhs) {
    if (lhs.index != rhs.index) {
        return false;
    }
    if (lhs.mode != rhs.mode) {
        return false;
    }
    if (lhs.channelMask != rhs.channelMask) {
        return false;
    }
    if (lhs.values != rhs.values) {
        return false;
    }
    if (lhs.rampDurationMs != rhs.rampDurationMs) {
        return false;
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::audio::common::V7_0::AudioGainConfig& lhs, const ::android::hardware::audio::common::V7_0::AudioGainConfig& rhs){
    return !(lhs == rhs);
}

static inline std::string toString(const ::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::AudioPortMixExt::UseCase& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";

    switch (o.getDiscriminator()) {
        case ::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::AudioPortMixExt::UseCase::hidl_discriminator::stream: {
            os += ".stream = ";
            os += toString(o.stream());
            break;
        }
        case ::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::AudioPortMixExt::UseCase::hidl_discriminator::source: {
            os += ".source = ";
            os += toString(o.source());
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

static inline void PrintTo(const ::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::AudioPortMixExt::UseCase& o, ::std::ostream* os) {
    *os << toString(o);
}

static inline bool operator==(const ::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::AudioPortMixExt::UseCase& lhs, const ::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::AudioPortMixExt::UseCase& rhs) {
    if (lhs.getDiscriminator() != rhs.getDiscriminator()) {
        return false;
    }
    switch (lhs.getDiscriminator()) {
        case ::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::AudioPortMixExt::UseCase::hidl_discriminator::stream: {
            return (lhs.stream() == rhs.stream());
        }
        case ::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::AudioPortMixExt::UseCase::hidl_discriminator::source: {
            return (lhs.source() == rhs.source());
        }
        default: {
            ::android::hardware::details::logAlwaysFatal((
                    "Unknown union discriminator (value: " +
                    std::to_string((uint8_t) lhs.getDiscriminator()) + ").").c_str());
        }
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::AudioPortMixExt::UseCase& lhs, const ::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::AudioPortMixExt::UseCase& rhs){
    return !(lhs == rhs);
}

static inline std::string toString(const ::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::AudioPortMixExt& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".ioHandle = ";
    os += ::android::hardware::toString(o.ioHandle);
    os += ", .useCase = ";
    os += ::android::hardware::audio::common::V7_0::toString(o.useCase);
    os += "}"; return os;
}

static inline void PrintTo(const ::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::AudioPortMixExt& o, ::std::ostream* os) {
    *os << toString(o);
}

static inline bool operator==(const ::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::AudioPortMixExt& lhs, const ::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::AudioPortMixExt& rhs) {
    if (lhs.ioHandle != rhs.ioHandle) {
        return false;
    }
    if (lhs.useCase != rhs.useCase) {
        return false;
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::AudioPortMixExt& lhs, const ::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::AudioPortMixExt& rhs){
    return !(lhs == rhs);
}

static inline std::string toString(const ::android::hardware::audio::common::V7_0::AudioPortExtendedInfo& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";

    switch (o.getDiscriminator()) {
        case ::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::hidl_discriminator::unspecified: {
            os += ".unspecified = ";
            os += toString(o.unspecified());
            break;
        }
        case ::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::hidl_discriminator::device: {
            os += ".device = ";
            os += toString(o.device());
            break;
        }
        case ::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::hidl_discriminator::mix: {
            os += ".mix = ";
            os += toString(o.mix());
            break;
        }
        case ::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::hidl_discriminator::session: {
            os += ".session = ";
            os += toString(o.session());
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

static inline void PrintTo(const ::android::hardware::audio::common::V7_0::AudioPortExtendedInfo& o, ::std::ostream* os) {
    *os << toString(o);
}

static inline bool operator==(const ::android::hardware::audio::common::V7_0::AudioPortExtendedInfo& lhs, const ::android::hardware::audio::common::V7_0::AudioPortExtendedInfo& rhs) {
    if (lhs.getDiscriminator() != rhs.getDiscriminator()) {
        return false;
    }
    switch (lhs.getDiscriminator()) {
        case ::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::hidl_discriminator::unspecified: {
            return (lhs.unspecified() == rhs.unspecified());
        }
        case ::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::hidl_discriminator::device: {
            return (lhs.device() == rhs.device());
        }
        case ::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::hidl_discriminator::mix: {
            return (lhs.mix() == rhs.mix());
        }
        case ::android::hardware::audio::common::V7_0::AudioPortExtendedInfo::hidl_discriminator::session: {
            return (lhs.session() == rhs.session());
        }
        default: {
            ::android::hardware::details::logAlwaysFatal((
                    "Unknown union discriminator (value: " +
                    std::to_string((uint8_t) lhs.getDiscriminator()) + ").").c_str());
        }
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::audio::common::V7_0::AudioPortExtendedInfo& lhs, const ::android::hardware::audio::common::V7_0::AudioPortExtendedInfo& rhs){
    return !(lhs == rhs);
}

static inline std::string toString(const ::android::hardware::audio::common::V7_0::AudioPortConfig::OptionalGain& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";

    switch (o.getDiscriminator()) {
        case ::android::hardware::audio::common::V7_0::AudioPortConfig::OptionalGain::hidl_discriminator::unspecified: {
            os += ".unspecified = ";
            os += toString(o.unspecified());
            break;
        }
        case ::android::hardware::audio::common::V7_0::AudioPortConfig::OptionalGain::hidl_discriminator::config: {
            os += ".config = ";
            os += toString(o.config());
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

static inline void PrintTo(const ::android::hardware::audio::common::V7_0::AudioPortConfig::OptionalGain& o, ::std::ostream* os) {
    *os << toString(o);
}

static inline bool operator==(const ::android::hardware::audio::common::V7_0::AudioPortConfig::OptionalGain& lhs, const ::android::hardware::audio::common::V7_0::AudioPortConfig::OptionalGain& rhs) {
    if (lhs.getDiscriminator() != rhs.getDiscriminator()) {
        return false;
    }
    switch (lhs.getDiscriminator()) {
        case ::android::hardware::audio::common::V7_0::AudioPortConfig::OptionalGain::hidl_discriminator::unspecified: {
            return (lhs.unspecified() == rhs.unspecified());
        }
        case ::android::hardware::audio::common::V7_0::AudioPortConfig::OptionalGain::hidl_discriminator::config: {
            return (lhs.config() == rhs.config());
        }
        default: {
            ::android::hardware::details::logAlwaysFatal((
                    "Unknown union discriminator (value: " +
                    std::to_string((uint8_t) lhs.getDiscriminator()) + ").").c_str());
        }
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::audio::common::V7_0::AudioPortConfig::OptionalGain& lhs, const ::android::hardware::audio::common::V7_0::AudioPortConfig::OptionalGain& rhs){
    return !(lhs == rhs);
}

static inline std::string toString(const ::android::hardware::audio::common::V7_0::AudioPortConfig& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".id = ";
    os += ::android::hardware::toString(o.id);
    os += ", .base = ";
    os += ::android::hardware::audio::common::V7_0::toString(o.base);
    os += ", .gain = ";
    os += ::android::hardware::audio::common::V7_0::toString(o.gain);
    os += ", .ext = ";
    os += ::android::hardware::audio::common::V7_0::toString(o.ext);
    os += "}"; return os;
}

static inline void PrintTo(const ::android::hardware::audio::common::V7_0::AudioPortConfig& o, ::std::ostream* os) {
    *os << toString(o);
}

static inline bool operator==(const ::android::hardware::audio::common::V7_0::AudioPortConfig& lhs, const ::android::hardware::audio::common::V7_0::AudioPortConfig& rhs) {
    if (lhs.id != rhs.id) {
        return false;
    }
    if (lhs.base != rhs.base) {
        return false;
    }
    if (lhs.gain != rhs.gain) {
        return false;
    }
    if (lhs.ext != rhs.ext) {
        return false;
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::audio::common::V7_0::AudioPortConfig& lhs, const ::android::hardware::audio::common::V7_0::AudioPortConfig& rhs){
    return !(lhs == rhs);
}

static inline std::string toString(const ::android::hardware::audio::common::V7_0::AudioPort& o) {
    using ::android::hardware::toString;
    std::string os;
    os += "{";
    os += ".id = ";
    os += ::android::hardware::toString(o.id);
    os += ", .name = ";
    os += ::android::hardware::toString(o.name);
    os += ", .transports = ";
    os += ::android::hardware::toString(o.transports);
    os += ", .gains = ";
    os += ::android::hardware::toString(o.gains);
    os += ", .ext = ";
    os += ::android::hardware::audio::common::V7_0::toString(o.ext);
    os += ", .activeConfig = ";
    os += ::android::hardware::audio::common::V7_0::toString(o.activeConfig);
    os += "}"; return os;
}

static inline void PrintTo(const ::android::hardware::audio::common::V7_0::AudioPort& o, ::std::ostream* os) {
    *os << toString(o);
}

static inline bool operator==(const ::android::hardware::audio::common::V7_0::AudioPort& lhs, const ::android::hardware::audio::common::V7_0::AudioPort& rhs) {
    if (lhs.id != rhs.id) {
        return false;
    }
    if (lhs.name != rhs.name) {
        return false;
    }
    if (lhs.transports != rhs.transports) {
        return false;
    }
    if (lhs.gains != rhs.gains) {
        return false;
    }
    if (lhs.ext != rhs.ext) {
        return false;
    }
    if (lhs.activeConfig != rhs.activeConfig) {
        return false;
    }
    return true;
}

static inline bool operator!=(const ::android::hardware::audio::common::V7_0::AudioPort& lhs, const ::android::hardware::audio::common::V7_0::AudioPort& rhs){
    return !(lhs == rhs);
}


}  // namespace V7_0
}  // namespace common
}  // namespace audio
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
template<> inline constexpr std::array<::android::hardware::audio::common::V7_0::AudioSessionConsts, 3> hidl_enum_values<::android::hardware::audio::common::V7_0::AudioSessionConsts> = {
    ::android::hardware::audio::common::V7_0::AudioSessionConsts::DEVICE,
    ::android::hardware::audio::common::V7_0::AudioSessionConsts::OUTPUT_STAGE,
    ::android::hardware::audio::common::V7_0::AudioSessionConsts::OUTPUT_MIX,
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
template<> inline constexpr std::array<::android::hardware::audio::common::V7_0::AudioMode, 5> hidl_enum_values<::android::hardware::audio::common::V7_0::AudioMode> = {
    ::android::hardware::audio::common::V7_0::AudioMode::NORMAL,
    ::android::hardware::audio::common::V7_0::AudioMode::RINGTONE,
    ::android::hardware::audio::common::V7_0::AudioMode::IN_CALL,
    ::android::hardware::audio::common::V7_0::AudioMode::IN_COMMUNICATION,
    ::android::hardware::audio::common::V7_0::AudioMode::CALL_SCREEN,
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
template<> inline constexpr std::array<::android::hardware::audio::common::V7_0::AudioEncapsulationMode, 3> hidl_enum_values<::android::hardware::audio::common::V7_0::AudioEncapsulationMode> = {
    ::android::hardware::audio::common::V7_0::AudioEncapsulationMode::NONE,
    ::android::hardware::audio::common::V7_0::AudioEncapsulationMode::ELEMENTARY_STREAM,
    ::android::hardware::audio::common::V7_0::AudioEncapsulationMode::HANDLE,
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
template<> inline constexpr std::array<::android::hardware::audio::common::V7_0::AudioEncapsulationMetadataType, 3> hidl_enum_values<::android::hardware::audio::common::V7_0::AudioEncapsulationMetadataType> = {
    ::android::hardware::audio::common::V7_0::AudioEncapsulationMetadataType::NONE,
    ::android::hardware::audio::common::V7_0::AudioEncapsulationMetadataType::FRAMEWORK_TUNER,
    ::android::hardware::audio::common::V7_0::AudioEncapsulationMetadataType::DVB_AD_DESCRIPTOR,
};
#pragma clang diagnostic pop
}  // namespace details
}  // namespace hardware
}  // namespace android


#endif  // HIDL_GENERATED_ANDROID_HARDWARE_AUDIO_COMMON_V7_0_TYPES_H
