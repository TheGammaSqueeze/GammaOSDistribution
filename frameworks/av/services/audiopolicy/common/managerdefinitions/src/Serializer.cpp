/*
 * Copyright (C) 2015 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#define LOG_TAG "APM::Serializer"
//#define LOG_NDEBUG 0

#include <memory>
#include <string>
#include <utility>
#include <variant>

#include <libxml/parser.h>
#include <libxml/xinclude.h>
#include <media/convert.h>
#include <utils/Log.h>
#include <utils/StrongPointer.h>
#include <utils/Errors.h>
#include <utils/RefBase.h>
#include <cutils/properties.h>
#include "Serializer.h"
#include "TypeConverter.h"

namespace android {

namespace {

static bool forceDisableA2dpOffload = false;

using utilities::convertTo;

static inline bool maybeVendorExtension(const std::string& s) {
    // Only checks whether the string starts with the "vendor prefix".
    static const std::string vendorPrefix = "VX_";
    return s.size() > vendorPrefix.size() && s.substr(0, vendorPrefix.size()) == vendorPrefix;
}

template<typename E, typename C>
struct AndroidCollectionTraits {
    typedef sp<E> Element;
    typedef C Collection;
    typedef void* PtrSerializingCtx;

    static status_t addElementToCollection(const Element &element, Collection *collection) {
        return collection->add(element) >= 0 ? NO_ERROR : BAD_VALUE;
    }
};

template<typename C>
struct StdCollectionTraits {
    typedef C Collection;
    typedef typename C::value_type Element;
    typedef void* PtrSerializingCtx;

    static status_t addElementToCollection(const Element &element, Collection *collection) {
        auto pair = collection->insert(element);
        return pair.second ? NO_ERROR : BAD_VALUE;
    }
};

struct AudioGainTraits : public AndroidCollectionTraits<AudioGain, AudioGains>
{
    static constexpr const char *tag = "gain";
    static constexpr const char *collectionTag = "gains";

    struct Attributes
    {
        /** gain modes supported, e.g. AUDIO_GAIN_MODE_CHANNELS. */
        static constexpr const char *mode = "mode";
        /** controlled channels, needed if mode AUDIO_GAIN_MODE_CHANNELS. */
        static constexpr const char *channelMask = "channel_mask";
        static constexpr const char *minValueMB = "minValueMB"; /**< min value in millibel. */
        static constexpr const char *maxValueMB = "maxValueMB"; /**< max value in millibel. */
        /** default value in millibel. */
        static constexpr const char *defaultValueMB = "defaultValueMB";
        static constexpr const char *stepValueMB = "stepValueMB"; /**< step value in millibel. */
        /** needed if mode AUDIO_GAIN_MODE_RAMP. */
        static constexpr const char *minRampMs = "minRampMs";
        /** needed if mode AUDIO_GAIN_MODE_RAMP. */
        static constexpr const char *maxRampMs = "maxRampMs";
        /** needed to allow use setPortGain instead of setStreamVolume. */
        static constexpr const char *useForVolume = "useForVolume";

    };

    // No children
};

// A profile section contains a name,  one audio format and the list of supported sampling rates
// and channel masks for this format
struct AudioProfileTraits : public AndroidCollectionTraits<AudioProfile, AudioProfileVector>
{
    static constexpr const char *tag = "profile";
    static constexpr const char *collectionTag = "profiles";

    struct Attributes
    {
        static constexpr const char *samplingRates = "samplingRates";
        static constexpr const char *format = "format";
        static constexpr const char *channelMasks = "channelMasks";
    };
};

struct MixPortTraits : public AndroidCollectionTraits<IOProfile, IOProfileCollection>
{
    static constexpr const char *tag = "mixPort";
    static constexpr const char *collectionTag = "mixPorts";

    struct Attributes
    {
        static constexpr const char *name = "name";
        static constexpr const char *role = "role";
        static constexpr const char *roleSource = "source"; /**< <attribute role source value>. */
        static constexpr const char *flags = "flags";
        static constexpr const char *maxOpenCount = "maxOpenCount";
        static constexpr const char *maxActiveCount = "maxActiveCount";
    };

    // Children: GainTraits
};

struct DevicePortTraits : public AndroidCollectionTraits<DeviceDescriptor, DeviceVector>
{
    static constexpr const char *tag = "devicePort";
    static constexpr const char *collectionTag = "devicePorts";

    struct Attributes
    {
        /**  <device tag name>: any string without space. */
        static constexpr const char *tagName = "tagName";
        static constexpr const char *type = "type"; /**< <device type>. */
        static constexpr const char *role = "role"; /**< <device role: sink or source>. */
        static constexpr const char *roleSource = "source"; /**< <attribute role source value>. */
        /** optional: device address, char string less than 64. */
        static constexpr const char *address = "address";
        /** optional: the list of encoded audio formats that are known to be supported. */
        static constexpr const char *encodedFormats = "encodedFormats";
    };

    // Children: GainTraits (optional)
};

struct RouteTraits : public AndroidCollectionTraits<AudioRoute, AudioRouteVector>
{
    static constexpr const char *tag = "route";
    static constexpr const char *collectionTag = "routes";

    struct Attributes
    {
        static constexpr const char *type = "type"; /**< <route type>: mix or mux. */
        static constexpr const char *typeMix = "mix"; /**< type attribute mix value. */
        static constexpr const char *sink = "sink"; /**< <sink: involved in this route>. */
        /** sources: all source that can be involved in this route. */
        static constexpr const char *sources = "sources";
    };

    typedef HwModule *PtrSerializingCtx;
};

struct ModuleTraits : public AndroidCollectionTraits<HwModule, HwModuleCollection>
{
    static constexpr const char *tag = "module";
    static constexpr const char *collectionTag = "modules";

    static constexpr const char *childAttachedDevicesTag = "attachedDevices";
    static constexpr const char *childAttachedDeviceTag = "item";
    static constexpr const char *childDefaultOutputDeviceTag = "defaultOutputDevice";

    struct Attributes
    {
        static constexpr const char *name = "name";
        static constexpr const char *version = "halVersion";
    };

    typedef AudioPolicyConfig *PtrSerializingCtx;

    // Children: mixPortTraits, devicePortTraits, and routeTraits
    // Need to call deserialize on each child
};

struct GlobalConfigTraits
{
    typedef std::monostate Element;

    static constexpr const char *tag = "globalConfiguration";

    struct Attributes
    {
        static constexpr const char *speakerDrcEnabled = "speaker_drc_enabled";
        static constexpr const char *callScreenModeSupported= "call_screen_mode_supported";
        static constexpr const char *engineLibrarySuffix = "engine_library";
    };

    typedef AudioPolicyConfig *PtrSerializingCtx;
};

struct SurroundSoundTraits
{
    typedef std::monostate Element;

    static constexpr const char *tag = "surroundSound";

    typedef AudioPolicyConfig *PtrSerializingCtx;
    // Children: SurroundSoundFormatTraits
};

struct SurroundSoundFormatTraits : public StdCollectionTraits<AudioPolicyConfig::SurroundFormats>
{
    static constexpr const char *tag = "format";
    static constexpr const char *collectionTag = "formats";

    struct Attributes
    {
        static constexpr const char *name = "name";
        static constexpr const char *subformats = "subformats";
    };
};

class PolicySerializer
{
public:
    status_t deserialize(const char *configFile, AudioPolicyConfig *config,
            bool ignoreVendorExtensions = false);

    template <class Trait>
    status_t deserializeCollection(const xmlNode *cur,
            typename Trait::Collection *collection,
            typename Trait::PtrSerializingCtx serializingContext);
    template <class Trait>
    std::variant<status_t, typename Trait::Element> deserialize(const xmlNode *cur,
            typename Trait::PtrSerializingCtx serializingContext);

private:
    static constexpr const char *rootName = "audioPolicyConfiguration";
    static constexpr const char *versionAttribute = "version";

    typedef AudioPolicyConfig Element;

    bool mIgnoreVendorExtensions = false;
    std::string mChannelMasksSeparator = ",";
    std::string mSamplingRatesSeparator = ",";
    std::string mFlagsSeparator = "|";
    std::string mMixPortName = "";

    // Children: ModulesTraits, VolumeTraits, SurroundSoundTraits (optional)
};

// Deleter using free() for use with std::unique_ptr<>. See also UniqueCPtr<> below.
struct FreeDelete {
    // NOTE: Deleting a const object is valid but free() takes a non-const pointer.
    void operator()(const void* ptr) const {
        free(const_cast<void*>(ptr));
    }
};

// Alias for std::unique_ptr<> that uses the C function free() to delete objects.
template <typename T>
using UniqueCPtr = std::unique_ptr<T, FreeDelete>;

template <class T>
constexpr void (*xmlDeleter)(T* t);
template <>
constexpr auto xmlDeleter<xmlDoc> = xmlFreeDoc;
template <>
constexpr auto xmlDeleter<xmlChar> = [](xmlChar *s) { xmlFree(s); };

/** @return a unique_ptr with the correct deleter for the libxml2 object. */
template <class T>
constexpr auto make_xmlUnique(T *t) {
    // Wrap deleter in lambda to enable empty base optimization
    auto deleter = [](T *t) { xmlDeleter<T>(t); };
    return std::unique_ptr<T, decltype(deleter)>{t, deleter};
}

std::string getXmlAttribute(const xmlNode *cur, const char *attribute)
{
    auto xmlValue = make_xmlUnique(xmlGetProp(cur, reinterpret_cast<const xmlChar*>(attribute)));
    if (xmlValue == nullptr) {
        return "";
    }
    std::string value(reinterpret_cast<const char*>(xmlValue.get()));
    return value;
}

template <class Trait>
const xmlNode* getReference(const xmlNode *cur, const std::string &refName)
{
    for (; cur != NULL; cur = cur->next) {
        if (!xmlStrcmp(cur->name, reinterpret_cast<const xmlChar*>(Trait::collectionTag))) {
            for (const xmlNode *child = cur->children; child != NULL; child = child->next) {
                if ((!xmlStrcmp(child->name,
                                        reinterpret_cast<const xmlChar*>(Trait::referenceTag)))) {
                    std::string name = getXmlAttribute(child, Trait::Attributes::referenceName);
                    if (refName == name) {
                        return child;
                    }
                }
            }
        }
    }
    return NULL;
}

template <class Trait>
status_t PolicySerializer::deserializeCollection(const xmlNode *cur,
        typename Trait::Collection *collection,
        typename Trait::PtrSerializingCtx serializingContext)
{
    for (cur = cur->xmlChildrenNode; cur != NULL; cur = cur->next) {
        const xmlNode *child = NULL;
        if (!xmlStrcmp(cur->name, reinterpret_cast<const xmlChar*>(Trait::collectionTag))) {
            child = cur->xmlChildrenNode;
        } else if (!xmlStrcmp(cur->name, reinterpret_cast<const xmlChar*>(Trait::tag))) {
            child = cur;
        }
        for (; child != NULL; child = child->next) {
            if (!xmlStrcmp(child->name, reinterpret_cast<const xmlChar*>(Trait::tag))) {
                auto maybeElement = deserialize<Trait>(child, serializingContext);
                if (maybeElement.index() == 1) {
                    status_t status = Trait::addElementToCollection(
                            std::get<1>(maybeElement), collection);
                    if (status != NO_ERROR) {
                        ALOGE("%s: could not add element to %s collection", __func__,
                            Trait::collectionTag);
                        return status;
                    }
                } else if (mIgnoreVendorExtensions && std::get<status_t>(maybeElement) == NO_INIT) {
                    // Skip a vendor extension element.
                } else {
                    ALOGE("Ignoring...");
                }
            }
        }
        if (!xmlStrcmp(cur->name, reinterpret_cast<const xmlChar*>(Trait::tag))) {
            return NO_ERROR;
        }
    }
    return NO_ERROR;
}

template<>
std::variant<status_t, AudioGainTraits::Element> PolicySerializer::deserialize<AudioGainTraits>(
        const xmlNode *cur, AudioGainTraits::PtrSerializingCtx /*serializingContext*/)
{
    using Attributes = AudioGainTraits::Attributes;

    static uint32_t index = 0;
    AudioGainTraits::Element gain = new AudioGain(index++, true);

    std::string mode = getXmlAttribute(cur, Attributes::mode);
    if (!mode.empty()) {
        gain->setMode(GainModeConverter::maskFromString(mode, " "));
    }

    std::string channelsLiteral = getXmlAttribute(cur, Attributes::channelMask);
    if (!channelsLiteral.empty()) {
        gain->setChannelMask(channelMaskFromString(channelsLiteral));
    }

    std::string minValueMBLiteral = getXmlAttribute(cur, Attributes::minValueMB);
    int32_t minValueMB;
    if (!minValueMBLiteral.empty() && convertTo(minValueMBLiteral, minValueMB)) {
        gain->setMinValueInMb(minValueMB);
    }

    std::string maxValueMBLiteral = getXmlAttribute(cur, Attributes::maxValueMB);
    int32_t maxValueMB;
    if (!maxValueMBLiteral.empty() && convertTo(maxValueMBLiteral, maxValueMB)) {
        gain->setMaxValueInMb(maxValueMB);
    }

    std::string defaultValueMBLiteral = getXmlAttribute(cur, Attributes::defaultValueMB);
    int32_t defaultValueMB;
    if (!defaultValueMBLiteral.empty() && convertTo(defaultValueMBLiteral, defaultValueMB)) {
        gain->setDefaultValueInMb(defaultValueMB);
    }

    std::string stepValueMBLiteral = getXmlAttribute(cur, Attributes::stepValueMB);
    uint32_t stepValueMB;
    if (!stepValueMBLiteral.empty() && convertTo(stepValueMBLiteral, stepValueMB)) {
        gain->setStepValueInMb(stepValueMB);
    }

    std::string minRampMsLiteral = getXmlAttribute(cur, Attributes::minRampMs);
    uint32_t minRampMs;
    if (!minRampMsLiteral.empty() && convertTo(minRampMsLiteral, minRampMs)) {
        gain->setMinRampInMs(minRampMs);
    }

    std::string maxRampMsLiteral = getXmlAttribute(cur, Attributes::maxRampMs);
    uint32_t maxRampMs;
    if (!maxRampMsLiteral.empty() && convertTo(maxRampMsLiteral, maxRampMs)) {
        gain->setMaxRampInMs(maxRampMs);
    }
    std::string useForVolumeLiteral = getXmlAttribute(cur, Attributes::useForVolume);
    bool useForVolume = false;
    if (!useForVolumeLiteral.empty() && convertTo(useForVolumeLiteral, useForVolume)) {
        gain->setUseForVolume(useForVolume);
    }
    ALOGV("%s: adding new gain mode %08x channel mask %08x min mB %d max mB %d UseForVolume: %d",
          __func__, gain->getMode(), gain->getChannelMask(), gain->getMinValueInMb(),
          gain->getMaxValueInMb(), useForVolume);

    if (gain->getMode() != 0) {
        return gain;
    } else {
        return BAD_VALUE;
    }
}

static bool fixedEarpieceChannels = false;
template<>
std::variant<status_t, AudioProfileTraits::Element>
PolicySerializer::deserialize<AudioProfileTraits>(
        const xmlNode *cur, AudioProfileTraits::PtrSerializingCtx serializingContext)
{
    using Attributes = AudioProfileTraits::Attributes;
    bool isOutput = serializingContext != nullptr;

    std::string samplingRates = getXmlAttribute(cur, Attributes::samplingRates);
    std::string format = getXmlAttribute(cur, Attributes::format);
    std::string channels = getXmlAttribute(cur, Attributes::channelMasks);
    ChannelTraits::Collection channelsMask = channelMasksFromString(channels, mChannelMasksSeparator.c_str());

    //Some Foxconn devices have wrong earpiece channel mask, leading to no channel mask
    if(channelsMask.size() == 1 && *channelsMask.begin() == AUDIO_CHANNEL_IN_MONO && isOutput) {
        fixedEarpieceChannels = true;
        channelsMask = channelMasksFromString("AUDIO_CHANNEL_OUT_MONO", ",");
    }

    // This breaks in-game voice chat and audio in some messaging apps causing it to play with a higher pitch and speed
    bool disableStereoVoip = property_get_bool("persist.sys.phh.disable_stereo_voip", false);
    if (disableStereoVoip && mMixPortName == "voip_rx") {
        ALOGI("%s: disabling stereo support on voip_rx", __func__);
        channelsMask = channelMasksFromString("AUDIO_CHANNEL_OUT_MONO", ",");
    }

    if (mIgnoreVendorExtensions && maybeVendorExtension(format)) {
        ALOGI("%s: vendor extension format \"%s\" skipped", __func__, format.c_str());
        return NO_INIT;
    }
    AudioProfileTraits::Element profile = new AudioProfile(formatFromString(format, gDynamicFormat),
            channelsMask,
            samplingRatesFromString(samplingRates, mSamplingRatesSeparator.c_str()));

    profile->setDynamicFormat(profile->getFormat() == gDynamicFormat);
    profile->setDynamicChannels(profile->getChannels().empty());
    profile->setDynamicRate(profile->getSampleRates().empty());

    return profile;
}

template<>
std::variant<status_t, MixPortTraits::Element> PolicySerializer::deserialize<MixPortTraits>(
        const xmlNode *child, MixPortTraits::PtrSerializingCtx /*serializingContext*/)
{
    using Attributes = MixPortTraits::Attributes;

    std::string name = getXmlAttribute(child, Attributes::name);
    mMixPortName = name;
    if (name.empty()) {
        ALOGE("%s: No %s found", __func__, Attributes::name);
        return BAD_VALUE;
    }
    ALOGV("%s: %s %s=%s", __func__, MixPortTraits::tag, Attributes::name, name.c_str());
    std::string role = getXmlAttribute(child, Attributes::role);
    if (role.empty()) {
        ALOGE("%s: No %s found", __func__, Attributes::role);
        return BAD_VALUE;
    }
    ALOGV("%s: Role=%s", __func__, role.c_str());
    audio_port_role_t portRole = (role == Attributes::roleSource) ?
            AUDIO_PORT_ROLE_SOURCE : AUDIO_PORT_ROLE_SINK;

    MixPortTraits::Element mixPort = new IOProfile(name, portRole);

    AudioProfileTraits::Collection profiles;
    status_t status = deserializeCollection<AudioProfileTraits>(child, &profiles, NULL);
    if (status != NO_ERROR) {
        return status;
    }
    if (profiles.empty()) {
        profiles.add(AudioProfile::createFullDynamic(gDynamicFormat));
    }
    // The audio profiles are in order of listed in audio policy configuration file.
    // Sort audio profiles accroding to the format.
    sortAudioProfiles(profiles);
    mixPort->setAudioProfiles(profiles);

    std::string flags = getXmlAttribute(child, Attributes::flags);
    if (!flags.empty()) {
        // Source role
        if (portRole == AUDIO_PORT_ROLE_SOURCE) {
            mixPort->setFlags(OutputFlagConverter::maskFromString(flags, mFlagsSeparator.c_str()));
        } else {
            // Sink role
            mixPort->setFlags(InputFlagConverter::maskFromString(flags, mFlagsSeparator.c_str()));
        }
    }
    std::string maxOpenCount = getXmlAttribute(child, Attributes::maxOpenCount);
    if (!maxOpenCount.empty()) {
        convertTo(maxOpenCount, mixPort->maxOpenCount);
    }
    std::string maxActiveCount = getXmlAttribute(child, Attributes::maxActiveCount);
    if (!maxActiveCount.empty()) {
        convertTo(maxActiveCount, mixPort->maxActiveCount);
    }
    // Deserialize children
    AudioGainTraits::Collection gains;
    status = deserializeCollection<AudioGainTraits>(child, &gains, NULL);
    if (status != NO_ERROR) {
        return status;
    }
    mixPort->setGains(gains);

    return mixPort;
}

template<>
std::variant<status_t, DevicePortTraits::Element> PolicySerializer::deserialize<DevicePortTraits>(
        const xmlNode *cur, DevicePortTraits::PtrSerializingCtx /*serializingContext*/)
{
    using Attributes = DevicePortTraits::Attributes;
    auto& tag = DevicePortTraits::tag;

    std::string name = getXmlAttribute(cur, Attributes::tagName);
    if (name.empty()) {
        ALOGE("%s: No %s found", __func__, Attributes::tagName);
        return BAD_VALUE;
    }
    ALOGV("%s: %s %s=%s", __func__, tag, Attributes::tagName, name.c_str());
    std::string typeName = getXmlAttribute(cur, Attributes::type);
    if (typeName.empty()) {
        ALOGE("%s: no type for %s", __func__, name.c_str());
        return BAD_VALUE;
    }
    ALOGV("%s: %s %s=%s", __func__, tag, Attributes::type, typeName.c_str());
    std::string role = getXmlAttribute(cur, Attributes::role);
    if (role.empty()) {
        ALOGE("%s: No %s found", __func__, Attributes::role);
        return BAD_VALUE;
    }
    ALOGV("%s: %s %s=%s", __func__, tag, Attributes::role, role.c_str());
    audio_port_role_t portRole = (role == Attributes::roleSource) ?
                AUDIO_PORT_ROLE_SOURCE : AUDIO_PORT_ROLE_SINK;

    if (mIgnoreVendorExtensions && maybeVendorExtension(typeName)) {
        ALOGI("%s: vendor extension device type \"%s\" skipped", __func__, typeName.c_str());
        return NO_INIT;
    }
    audio_devices_t type = AUDIO_DEVICE_NONE;
    if (!DeviceConverter::fromString(typeName, type) ||
            (!audio_is_input_device(type) && portRole == AUDIO_PORT_ROLE_SOURCE) ||
            (!audio_is_output_devices(type) && portRole == AUDIO_PORT_ROLE_SINK)) {
        ALOGW("%s: bad type %08x", __func__, type);
        return BAD_VALUE;
    }
    std::string encodedFormatsLiteral = getXmlAttribute(cur, Attributes::encodedFormats);
    ALOGV("%s: %s %s=%s", __func__, tag, Attributes::encodedFormats, encodedFormatsLiteral.c_str());
    FormatVector encodedFormats;
    if (!encodedFormatsLiteral.empty()) {
        encodedFormats = formatsFromString(encodedFormatsLiteral, " ");
    }
    std::string address = getXmlAttribute(cur, Attributes::address);
    DevicePortTraits::Element deviceDesc =
            new DeviceDescriptor(type, name, address, encodedFormats);

    AudioProfileTraits::Collection profiles;
    status_t status;
    if(audio_is_output_devices(type))
        status = deserializeCollection<AudioProfileTraits>(cur, &profiles, (AudioProfileTraits::PtrSerializingCtx)1);
    else
        status = deserializeCollection<AudioProfileTraits>(cur, &profiles, NULL);
    if (status != NO_ERROR) {
        return status;
    }
    if (profiles.empty()) {
        profiles.add(AudioProfile::createFullDynamic(gDynamicFormat));
    }
    // The audio profiles are in order of listed in audio policy configuration file.
    // Sort audio profiles accroding to the format.
    sortAudioProfiles(profiles);
    deviceDesc->setAudioProfiles(profiles);

    // Deserialize AudioGain children
    status = deserializeCollection<AudioGainTraits>(cur, &deviceDesc->mGains, NULL);
    if (status != NO_ERROR) {
        return status;
    }
    ALOGV("%s: adding device tag %s type %08x address %s", __func__,
          deviceDesc->getName().c_str(), type, deviceDesc->address().c_str());
    return deviceDesc;
}

char* trim(char * s) {
    int l = strlen(s);

    if (l > 0) {
      while (isspace(s[l - 1])) --l;
      while (*s && isspace(*s)) ++s, --l;
    }

    return strndup(s, l);
}

template<>
std::variant<status_t, RouteTraits::Element> PolicySerializer::deserialize<RouteTraits>(
        const xmlNode *cur, RouteTraits::PtrSerializingCtx ctx)
{
    using Attributes = RouteTraits::Attributes;

    std::string type = getXmlAttribute(cur, Attributes::type);
    if (type.empty()) {
        ALOGE("%s: No %s found", __func__, Attributes::type);
        return BAD_VALUE;
    }
    audio_route_type_t routeType = (type == Attributes::typeMix) ?
                AUDIO_ROUTE_MIX : AUDIO_ROUTE_MUX;

    ALOGV("%s: %s %s=%s", __func__, RouteTraits::tag, Attributes::type, type.c_str());
    RouteTraits::Element route = new AudioRoute(routeType);

    std::string sinkAttr = getXmlAttribute(cur, Attributes::sink);
    if (sinkAttr.empty()) {
        ALOGE("%s: No %s found", __func__, Attributes::sink);
        return BAD_VALUE;
    }
    // Convert Sink name to port pointer
    sp<PolicyAudioPort> sink = ctx->findPortByTagName(sinkAttr);
    if (sink == NULL && !mIgnoreVendorExtensions) {
        ALOGE("%s: no sink found with name=%s", __func__, sinkAttr.c_str());
        return BAD_VALUE;
    } else if (sink == NULL) {
        ALOGW("Skipping route to sink \"%s\" as it likely has vendor extension type",
                sinkAttr.c_str());
        return NO_INIT;
    }
    route->setSink(sink);

    std::string sourcesAttr = getXmlAttribute(cur, Attributes::sources);
    if (sourcesAttr.empty()) {
        ALOGE("%s: No %s found", __func__, Attributes::sources);
        return BAD_VALUE;
    }
    // Tokenize and Convert Sources name to port pointer
    PolicyAudioPortVector sources;
    UniqueCPtr<char> sourcesLiteral{strndup(
                sourcesAttr.c_str(), strlen(sourcesAttr.c_str()))};
    char *devTag = strtok(sourcesLiteral.get(), ",");
    while (devTag != NULL) {
        if (strlen(devTag) != 0) {
            sp<PolicyAudioPort> source = ctx->findPortByTagName(devTag);
            if (source == NULL) {
                source = ctx->findPortByTagName(trim(devTag));
	    }
            if (source == NULL && false) {
                ALOGE("%s: no source found with name=%s", __func__, devTag);
                return BAD_VALUE;
            } else if (source == NULL) {
                ALOGW("Skipping route source \"%s\" as it likely has vendor extension type",
                        devTag);
            } else {
                sources.add(source);
            }
        }
        devTag = strtok(NULL, ",");
    }

    sink->addRoute(route);
    for (size_t i = 0; i < sources.size(); i++) {
        sp<PolicyAudioPort> source = sources.itemAt(i);
        source->addRoute(route);
    }
    route->setSources(sources);
    return route;
}

static void fixupQualcommBtScoRoute(RouteTraits::Collection& routes, DevicePortTraits::Collection& devicePorts, HwModule* ctx) {
    // On many Qualcomm devices, there is a BT SCO Headset Mic => primary input mix
    // But Telephony Rx => BT SCO Headset route is missing
    // When we detect such case, add the missing route

    // If we have:
    // <route type="mix" sink="Telephony Tx" sources="voice_tx"/>
    // <route type="mix" sink="primary input" sources="Built-In Mic,Built-In Back Mic,Wired Headset Mic,BT SCO Headset Mic"/>
    // <devicePort tagName="BT SCO Headset" type="AUDIO_DEVICE_OUT_BLUETOOTH_SCO_HEADSET" role="sink" />
    // And no <route type="mix" sink="BT SCO Headset" />

    // Add:
    // <route type="mix" sink="BT SCO Headset" sources="primary output,deep_buffer,compressed_offload,Telephony Rx"/>
    bool foundBtScoHeadsetDevice = false;
    for(const auto& device: devicePorts) {
        if(device->getTagName() == "BT SCO Headset") {
            foundBtScoHeadsetDevice = true;
            break;
        }
    }
    if(!foundBtScoHeadsetDevice) {
        ALOGE("No BT SCO Headset device found, don't patch policy");
        return;
    }

    bool foundTelephony = false;
    bool foundBtScoInput = false;
    bool foundScoHeadsetRoute = false;
    for(const auto& route: routes) {
        ALOGE("Looking at route %d\n", route->getType());
        if(route->getType() != AUDIO_ROUTE_MIX)
            continue;
        auto sink = route->getSink();
        ALOGE("... With sink %s\n", sink->getTagName().c_str());
        if(sink->getTagName() == "Telephony Tx") {
            foundTelephony = true;
            continue;
        }
        if(sink->getTagName() == "BT SCO Headset") {
            foundScoHeadsetRoute = true;
            break;
        }
        for(const auto& source: route->getSources()) {
            ALOGE("... With source %s\n", source->getTagName().c_str());
            if(source->getTagName() == "BT SCO Headset Mic") {
                foundBtScoInput = true;
                break;
            }
        }
    }
    //The route we want to add is already there
    ALOGE("Done looking for existing routes");
    if(foundScoHeadsetRoute)
        return;

    ALOGE("No existing route found... %d %d", foundTelephony ? 1 : 0, foundBtScoInput ? 1 : 0);
    //We couldn't find the routes we assume are required for the function we want to add
    if(!foundTelephony || !foundBtScoInput)
        return;
    ALOGE("Adding our own.");

    // Add:
    // <route type="mix" sink="BT SCO Headset" sources="primary output,deep_buffer,compressed_offload,Telephony Rx"/>
    AudioRoute *newRoute = new AudioRoute(AUDIO_ROUTE_MIX);

    auto sink = ctx->findPortByTagName("BT SCO Headset");
    ALOGE("Got sink %p\n", sink.get());
    newRoute->setSink(sink);

    Vector<sp<PolicyAudioPort>> sources;
    for(const auto& sourceName: {
            "primary output",
            "deep_buffer",
            "compressed_offload",
            "Telephony Rx"
            }) {
        auto source = ctx->findPortByTagName(sourceName);
        ALOGE("Got source %p\n", source.get());
        if (source.get() != nullptr) {
            sources.add(source);
            source->addRoute(newRoute);
        }
    }

    newRoute->setSources(sources);

    sink->addRoute(newRoute);

    auto ret = routes.add(newRoute);
    ALOGE("route add returned %zd", ret);
}

template<>
std::variant<status_t, ModuleTraits::Element> PolicySerializer::deserialize<ModuleTraits>(
        const xmlNode *cur, ModuleTraits::PtrSerializingCtx ctx)
{
    using Attributes = ModuleTraits::Attributes;
    auto& tag = ModuleTraits::tag;
    auto& childAttachedDevicesTag = ModuleTraits::childAttachedDevicesTag;
    auto& childAttachedDeviceTag = ModuleTraits::childAttachedDeviceTag;
    auto& childDefaultOutputDeviceTag = ModuleTraits::childDefaultOutputDeviceTag;

    std::string name = getXmlAttribute(cur, Attributes::name);
    if (name.empty()) {
        ALOGE("%s: No %s found", __func__, Attributes::name);
        return BAD_VALUE;
    }
    uint32_t versionMajor = 0, versionMinor = 0;
    std::string versionLiteral = getXmlAttribute(cur, Attributes::version);
    if (!versionLiteral.empty()) {
        sscanf(versionLiteral.c_str(), "%u.%u", &versionMajor, &versionMinor);
        ALOGV("%s: mHalVersion = major %u minor %u",  __func__,
              versionMajor, versionMajor);
    }

    ALOGV("%s: %s %s=%s", __func__, ModuleTraits::tag, Attributes::name, name.c_str());

    ModuleTraits::Element module = new HwModule(name.c_str(), versionMajor, versionMinor);

    // Deserialize children: Audio Mix Port, Audio Device Ports (Source/Sink), Audio Routes
    bool isA2dpModule = strcmp(name.c_str(), "a2dp") == 0;
    bool isPrimaryModule = strcmp(name.c_str(), "primary") == 0;

    MixPortTraits::Collection mixPorts;
    status_t status = deserializeCollection<MixPortTraits>(cur, &mixPorts, NULL);
    if (status != NO_ERROR) {
        return status;
    }
    if(forceDisableA2dpOffload && isA2dpModule) {
        for(const auto& mixPort: mixPorts) {
            ALOGE("Disable a2dp offload...? %s", mixPort->getTagName().c_str());
            //"a2dp" sw module already has a2dp out
            if(mixPort->getTagName() == "a2dp output") {
                forceDisableA2dpOffload = false;
                break;
            }
        }
    }
    if(forceDisableA2dpOffload && isA2dpModule) {
        //Add
        //<mixPort name="a2dp output" role="source"/>
        auto mixPort = new IOProfile("a2dp output", AUDIO_PORT_ROLE_SOURCE);
        AudioProfileTraits::Collection profiles;
        profiles.add(AudioProfile::createFullDynamic());
        mixPort->setAudioProfiles(profiles);
        mixPorts.push_back(mixPort);
    }
    module->setProfiles(mixPorts);

    DevicePortTraits::Collection devicePorts;
    status = deserializeCollection<DevicePortTraits>(cur, &devicePorts, NULL);
    if (status != NO_ERROR) {
        return status;
    }
    Vector<std::string> a2dpOuts;
    a2dpOuts.push_back("BT A2DP Out");
    a2dpOuts.push_back("BT A2DP Headphones");
    a2dpOuts.push_back("BT A2DP Speaker");
    if(forceDisableA2dpOffload) {
        if(isA2dpModule) {
            //<devicePort tagName="BT A2DP Out" type="AUDIO_DEVICE_OUT_BLUETOOTH_A2DP" role="sink" address="lhdc_a2dp">
            //  <profile name="" format="AUDIO_FORMAT_PCM_16_BIT"
            //      samplingRates="44100,48000,96000"
            //      channelMasks="AUDIO_CHANNEL_OUT_STEREO"/>
            //</devicePort>
            if(true) {
                FormatVector formats;
                //auto devicePortOut = new DeviceDescriptor(AUDIO_DEVICE_OUT_BLUETOOTH_A2DP, formats, "BT A2DP Out");
                auto devicePortOut = new DeviceDescriptor(AUDIO_DEVICE_OUT_BLUETOOTH_A2DP, "BT A2DP Out");
                AudioProfileTraits::Collection profiles;
                ChannelTraits::Collection channels;
                channels.insert(AUDIO_CHANNEL_OUT_STEREO);
                SampleRateSet sampleRates;
                sampleRates.insert(44100);
                sampleRates.insert(48000);
                sampleRates.insert(96000);
                auto profile = new AudioProfile(AUDIO_FORMAT_PCM_16_BIT, channels, sampleRates);
                profiles.add(profile);
                devicePortOut->setAudioProfiles(profiles);
                devicePortOut->setAddress("lhdc_a2dp");
                devicePorts.add(devicePortOut);
            }
            //<devicePort tagName="BT A2DP Headphones" type="AUDIO_DEVICE_OUT_BLUETOOTH_A2DP_HEADPHONES" role="sink" address="lhdc_a2dp">
            //  <profile name="" format="AUDIO_FORMAT_PCM_16_BIT"
            //      samplingRates="44100,48000,96000"
            //      channelMasks="AUDIO_CHANNEL_OUT_STEREO"/>
            //</devicePort>
            if(true) {
                FormatVector formats;
                auto devicePortOut = new DeviceDescriptor(AUDIO_DEVICE_OUT_BLUETOOTH_A2DP_HEADPHONES, "BT A2DP Headphones");
                AudioProfileTraits::Collection profiles;
                ChannelTraits::Collection channels;
                channels.insert(AUDIO_CHANNEL_OUT_STEREO);
                SampleRateSet sampleRates;
                sampleRates.insert(44100);
                sampleRates.insert(48000);
                sampleRates.insert(96000);
                auto profile = new AudioProfile(AUDIO_FORMAT_PCM_16_BIT, channels, sampleRates);
                profiles.add(profile);
                devicePortOut->setAudioProfiles(profiles);
                devicePortOut->setAddress("lhdc_a2dp");
                devicePorts.add(devicePortOut);
            }
            //<devicePort tagName="BT A2DP Speaker" type="AUDIO_DEVICE_OUT_BLUETOOTH_A2DP_SPEAKER" role="sink" address="lhdc_a2dp">
            //  <profile name="" format="AUDIO_FORMAT_PCM_16_BIT"
            //      samplingRates="44100,48000,96000"
            //      channelMasks="AUDIO_CHANNEL_OUT_STEREO"/>
            //</devicePort>
            if(true) {
                FormatVector formats;
                auto devicePortOut = new DeviceDescriptor(AUDIO_DEVICE_OUT_BLUETOOTH_A2DP_SPEAKER, "BT A2DP Speaker");
                AudioProfileTraits::Collection profiles;
                ChannelTraits::Collection channels;
                channels.insert(AUDIO_CHANNEL_OUT_STEREO);
                SampleRateSet sampleRates;
                sampleRates.insert(44100);
                sampleRates.insert(48000);
                sampleRates.insert(96000);
                auto profile = new AudioProfile(AUDIO_FORMAT_PCM_16_BIT, channels, sampleRates);
                profiles.add(profile);
                devicePortOut->setAudioProfiles(profiles);
                devicePortOut->setAddress("lhdc_a2dp");
                devicePorts.add(devicePortOut);

            }
        } else if(isPrimaryModule) {
            for(const auto& out: a2dpOuts) {
                auto iterA = std::find_if(devicePorts.begin(), devicePorts.end(), [out](const auto port) {
                        if(port->getTagName() == out) return true;
                        return false;
                        });
                if(iterA != devicePorts.end()) {
                    ALOGE("Erasing device port %s", (*iterA)->getTagName().c_str());
                    devicePorts.erase(iterA);
                }
            }
        }
    }
    module->setDeclaredDevices(devicePorts);

    RouteTraits::Collection routes;
    status = deserializeCollection<RouteTraits>(cur, &routes, module.get());
    if (status != NO_ERROR) {
        return status;
    }
    if(forceDisableA2dpOffload) {
        if(strcmp(name.c_str(), "primary") == 0) {
            for(const auto& out: a2dpOuts) {
                auto iterA = std::find_if(routes.begin(), routes.end(), [out](const auto route) {
                        if(route->getType() != AUDIO_ROUTE_MIX)
                        return false;
                        auto sink = route->getSink();
                        if(sink->getTagName() == out) {
                            return true;
                        }
                        return false;
                });
                if(iterA != routes.end()) {
                    auto sink = (*iterA)->getSink()->getTagName();
                    ALOGE("Erasing route %s", sink.c_str());
                    routes.erase(iterA);
                }
            }
        } else if(isA2dpModule) {
            //<route type="mix" sink="BT A2DP Out"
            //  sources="a2dp output"/>
            if(true) {
                auto newRoute = new AudioRoute(AUDIO_ROUTE_MIX);
                auto sink = module->findPortByTagName("BT A2DP Out");
                auto source = module->findPortByTagName("a2dp output");
                newRoute->setSink(sink);
                Vector<sp<PolicyAudioPort>> sources;
                sources.add(source);

                sink->addRoute(newRoute);
                source->addRoute(newRoute);
                newRoute->setSources(sources);

                routes.add(newRoute);
            }
            //<route type="mix" sink="BT A2DP Headphones"
            //  sources="a2dp output"/>
            if(true) {
                auto newRoute = new AudioRoute(AUDIO_ROUTE_MIX);
                auto sink = module->findPortByTagName("BT A2DP Headphones");
                auto source = module->findPortByTagName("a2dp output");
                newRoute->setSink(sink);
                Vector<sp<PolicyAudioPort>> sources;
                sources.add(source);

                sink->addRoute(newRoute);
                source->addRoute(newRoute);
                newRoute->setSources(sources);
                routes.add(newRoute);
            }
            //<route type="mix" sink="BT A2DP Speaker"
            //  sources="a2dp output"/>
            if(true) {
                auto newRoute = new AudioRoute(AUDIO_ROUTE_MIX);
                auto sink = module->findPortByTagName("BT A2DP Speaker");
                auto source = module->findPortByTagName("a2dp output");
                newRoute->setSink(sink);
                Vector<sp<PolicyAudioPort>> sources;
                sources.add(source);

                sink->addRoute(newRoute);
                source->addRoute(newRoute);
                newRoute->setSources(sources);
                routes.add(newRoute);
            }
        }
    }
    ALOGE("Good morning");
    fixupQualcommBtScoRoute(routes, devicePorts, module.get());
    ALOGE("Good morning2");
    module->setRoutes(routes);

    for (const xmlNode *children = cur->xmlChildrenNode; children != NULL;
         children = children->next) {
        if (!xmlStrcmp(children->name, reinterpret_cast<const xmlChar*>(childAttachedDevicesTag))) {
            ALOGV("%s: %s %s found", __func__, tag, childAttachedDevicesTag);
            for (const xmlNode *child = children->xmlChildrenNode; child != NULL;
                 child = child->next) {
                if (!xmlStrcmp(child->name,
                                reinterpret_cast<const xmlChar*>(childAttachedDeviceTag))) {
                    auto attachedDevice = make_xmlUnique(xmlNodeListGetString(
                                    child->doc, child->xmlChildrenNode, 1));
                    if (attachedDevice != nullptr) {
                        ALOGV("%s: %s %s=%s", __func__, tag, childAttachedDeviceTag,
                                reinterpret_cast<const char*>(attachedDevice.get()));
                        sp<DeviceDescriptor> device = module->getDeclaredDevices().
                                getDeviceFromTagName(std::string(reinterpret_cast<const char*>(
                                                        attachedDevice.get())));
                        if (device == nullptr) {
                            ALOGW("Skipped attached device \"%s\" because it likely uses a vendor"
                                    "extension type",
                                    reinterpret_cast<const char*>(attachedDevice.get()));
                            continue;
                        }
                        ctx->addDevice(device);
                    }
                }
            }
        }
        if (!xmlStrcmp(children->name,
                        reinterpret_cast<const xmlChar*>(childDefaultOutputDeviceTag))) {
            auto defaultOutputDevice = make_xmlUnique(xmlNodeListGetString(
                            children->doc, children->xmlChildrenNode, 1));
            if (defaultOutputDevice != nullptr) {
                ALOGV("%s: %s %s=%s", __func__, tag, childDefaultOutputDeviceTag,
                        reinterpret_cast<const char*>(defaultOutputDevice.get()));
                sp<DeviceDescriptor> device = module->getDeclaredDevices().getDeviceFromTagName(
                        std::string(reinterpret_cast<const char*>(defaultOutputDevice.get())));
                if (device != 0 && ctx->getDefaultOutputDevice() == 0) {
                    ctx->setDefaultOutputDevice(device);
                    ALOGV("%s: default is %08x",
                            __func__, ctx->getDefaultOutputDevice()->type());
                }
            }
        }
    }

    if(fixedEarpieceChannels) {
        sp<DeviceDescriptor> device =
            module->getDeclaredDevices().getDeviceFromTagName("Earpiece");
        if(device != 0)
            ctx->addDevice(device);
        fixedEarpieceChannels = false;
    }
    return module;
}

template<>
std::variant<status_t, GlobalConfigTraits::Element>
PolicySerializer::deserialize<GlobalConfigTraits>(
        const xmlNode *root, GlobalConfigTraits::PtrSerializingCtx config)
{
    using Attributes = GlobalConfigTraits::Attributes;

    for (const xmlNode *cur = root->xmlChildrenNode; cur != NULL; cur = cur->next) {
        if (!xmlStrcmp(cur->name, reinterpret_cast<const xmlChar*>(GlobalConfigTraits::tag))) {
            bool value;
            std::string attr = getXmlAttribute(cur, Attributes::speakerDrcEnabled);
            if (!attr.empty() &&
                    convertTo<std::string, bool>(attr, value)) {
                config->setSpeakerDrcEnabled(value);
            }
            attr = getXmlAttribute(cur, Attributes::callScreenModeSupported);
            if (!attr.empty() &&
                    convertTo<std::string, bool>(attr, value)) {
                config->setCallScreenModeSupported(value);
            }
            std::string engineLibrarySuffix = getXmlAttribute(cur, Attributes::engineLibrarySuffix);
            if (!engineLibrarySuffix.empty()) {
                config->setEngineLibraryNameSuffix(engineLibrarySuffix);
            }
            return NO_ERROR;
        }
    }
    return NO_ERROR;
}

template<>
std::variant<status_t, SurroundSoundTraits::Element>
PolicySerializer::deserialize<SurroundSoundTraits>(
        const xmlNode *root, SurroundSoundTraits::PtrSerializingCtx config)
{
    config->setDefaultSurroundFormats();

    for (const xmlNode *cur = root->xmlChildrenNode; cur != NULL; cur = cur->next) {
        if (!xmlStrcmp(cur->name, reinterpret_cast<const xmlChar*>(SurroundSoundTraits::tag))) {
            AudioPolicyConfig::SurroundFormats formats;
            status_t status = deserializeCollection<SurroundSoundFormatTraits>(
                    cur, &formats, nullptr);
            if (status == NO_ERROR) {
                config->setSurroundFormats(formats);
            }
            return NO_ERROR;
        }
    }
    return NO_ERROR;
}

template<>
std::variant<status_t, SurroundSoundFormatTraits::Element>
PolicySerializer::deserialize<SurroundSoundFormatTraits>(
        const xmlNode *cur, SurroundSoundFormatTraits::PtrSerializingCtx /*serializingContext*/)
{
    using Attributes = SurroundSoundFormatTraits::Attributes;

    std::string formatLiteral = getXmlAttribute(cur, Attributes::name);
    if (formatLiteral.empty()) {
        ALOGE("%s: No %s found for a surround format", __func__, Attributes::name);
        return BAD_VALUE;
    }
    if (mIgnoreVendorExtensions && maybeVendorExtension(formatLiteral)) {
        ALOGI("%s: vendor extension format \"%s\" skipped", __func__, formatLiteral.c_str());
        return NO_INIT;
    }
    audio_format_t format = formatFromString(formatLiteral);
    if (format == AUDIO_FORMAT_DEFAULT) {
        ALOGE("%s: Unrecognized format %s", __func__, formatLiteral.c_str());
        return BAD_VALUE;
    }
    SurroundSoundFormatTraits::Element pair = std::make_pair(
            format, SurroundSoundFormatTraits::Collection::mapped_type{});

    std::string subformatsLiteral = getXmlAttribute(cur, Attributes::subformats);
    if (subformatsLiteral.empty()) return pair;
    FormatVector subformats = formatsFromString(subformatsLiteral, " ");
    for (const auto& subformat : subformats) {
        auto result = pair.second.insert(subformat);
        if (!result.second) {
            ALOGE("%s: could not add subformat %x to collection", __func__, subformat);
            return BAD_VALUE;
        }
    }
    return pair;
}

status_t PolicySerializer::deserialize(const char *configFile, AudioPolicyConfig *config,
                                       bool ignoreVendorExtensions)
{
    mIgnoreVendorExtensions = ignoreVendorExtensions;
    auto doc = make_xmlUnique(xmlParseFile(configFile));
    if (doc == nullptr) {
        ALOGE("%s: Could not parse %s document.", __func__, configFile);
        return BAD_VALUE;
    }
    xmlNodePtr root = xmlDocGetRootElement(doc.get());
    if (root == NULL) {
        ALOGE("%s: Could not parse %s document: empty.", __func__, configFile);
        return BAD_VALUE;
    }
    if (xmlXIncludeProcess(doc.get()) < 0) {
        ALOGE("%s: libxml failed to resolve XIncludes on %s document.", __func__, configFile);
    }

    if (xmlStrcmp(root->name, reinterpret_cast<const xmlChar*>(rootName)))  {
        ALOGE("%s: No %s root element found in xml data %s.", __func__, rootName,
                reinterpret_cast<const char*>(root->name));
        return BAD_VALUE;
    }

    std::string version = getXmlAttribute(root, versionAttribute);
    if (version.empty()) {
        ALOGE("%s: No version found in root node %s", __func__, rootName);
        return BAD_VALUE;
    }
    if (version == "7.0") {
        mChannelMasksSeparator = mSamplingRatesSeparator = mFlagsSeparator = " ";
    } else if (version != "1.0") {
        ALOGE("%s: Version does not match; expected \"1.0\" or \"7.0\" got \"%s\"",
                __func__, version.c_str());
        return BAD_VALUE;
    }
    // Let's deserialize children
    // Modules
    ModuleTraits::Collection modules;
    status_t status = deserializeCollection<ModuleTraits>(root, &modules, config);
    if (status != NO_ERROR) {
        return status;
    }

    // Remove modules called bluetooth, bluetooth_qti or a2dp, and inject our own
    if(forceDisableA2dpOffload) {
	    for(auto it = modules.begin(); it != modules.end(); it++) {
		    const char *name = (*it)->getName();
		    if(strcmp(name, "a2dp") == 0 ||
				    strcmp(name, "a2dpsink") == 0 ||
				    strcmp(name, "bluetooth") == 0 ||
				    strcmp(name, "bluetooth_qti") == 0) {

			    ALOGE("Removed module %s\n", name);
			    it = modules.erase(it);
		    }
		    if(it == modules.end()) break;
	    }
	    const char* a2dpFileName = "/system/etc/a2dp_audio_policy_configuration.xml";
	    if (version == "7.0")
		    a2dpFileName = "/system/etc/a2dp_audio_policy_configuration_7_0.xml";
	    auto doc = make_xmlUnique(xmlParseFile(a2dpFileName));
	    xmlNodePtr root = xmlDocGetRootElement(doc.get());
	    auto maybeA2dpModule = deserialize<ModuleTraits>(root, config);
	    modules.add(std::get<1>(maybeA2dpModule));
    }

    config->setHwModules(modules);

    // Global Configuration
    deserialize<GlobalConfigTraits>(root, config);

    // Surround configuration
    deserialize<SurroundSoundTraits>(root, config);

    return android::OK;
}

}  // namespace

status_t deserializeAudioPolicyFile(const char *fileName, AudioPolicyConfig *config)
{
    PolicySerializer serializer;
    forceDisableA2dpOffload = property_get_bool("persist.sys.phh.disable_a2dp_offload", false);
    status_t status = serializer.deserialize(fileName, config);
    if (status != OK) config->clear();
    return status;
}

status_t deserializeAudioPolicyFileForVts(const char *fileName, AudioPolicyConfig *config)
{
    PolicySerializer serializer;
    forceDisableA2dpOffload = property_get_bool("persist.sys.phh.disable_a2dp_offload", false);
    status_t status = serializer.deserialize(fileName, config, true /*ignoreVendorExtensions*/);
    if (status != OK) config->clear();
    return status;
}

} // namespace android
