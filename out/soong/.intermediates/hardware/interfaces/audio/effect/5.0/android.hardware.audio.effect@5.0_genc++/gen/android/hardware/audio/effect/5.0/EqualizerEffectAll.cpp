#define LOG_TAG "android.hardware.audio.effect@5.0::EqualizerEffect"

#include <log/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <hidl/Static.h>
#include <hwbinder/ProcessState.h>
#include <utils/Trace.h>
#include <android/hidl/manager/1.0/IServiceManager.h>
#include <android/hardware/audio/effect/5.0/BpHwEqualizerEffect.h>
#include <android/hardware/audio/effect/5.0/BnHwEqualizerEffect.h>
#include <android/hardware/audio/effect/5.0/BsEqualizerEffect.h>
#include <android/hardware/audio/effect/5.0/BpHwEffect.h>
#include <android/hidl/base/1.0/BpHwBase.h>
#include <hidl/ServiceManagement.h>

namespace android {
namespace hardware {
namespace audio {
namespace effect {
namespace V5_0 {

::android::status_t readEmbeddedFromParcel(
        const IEqualizerEffect::IEqualizerEffect::AllProperties &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_bandLevels_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<int16_t> &>(obj.bandLevels),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::effect::V5_0::IEqualizerEffect::AllProperties, bandLevels), &_hidl_bandLevels_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const IEqualizerEffect::IEqualizerEffect::AllProperties &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_bandLevels_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.bandLevels,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::audio::effect::V5_0::IEqualizerEffect::AllProperties, bandLevels), &_hidl_bandLevels_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

const char* IEqualizerEffect::descriptor("android.hardware.audio.effect@5.0::IEqualizerEffect");

__attribute__((constructor)) static void static_constructor() {
    ::android::hardware::details::getBnConstructorMap().set(IEqualizerEffect::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hardware::IBinder> {
                return new BnHwEqualizerEffect(static_cast<IEqualizerEffect *>(iIntf));
            });
    ::android::hardware::details::getBsConstructorMap().set(IEqualizerEffect::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hidl::base::V1_0::IBase> {
                return new BsEqualizerEffect(static_cast<IEqualizerEffect *>(iIntf));
            });
}

__attribute__((destructor))static void static_destructor() {
    ::android::hardware::details::getBnConstructorMap().erase(IEqualizerEffect::descriptor);
    ::android::hardware::details::getBsConstructorMap().erase(IEqualizerEffect::descriptor);
}

// Methods from ::android::hardware::audio::effect::V5_0::IEffect follow.
// no default implementation for: ::android::hardware::Return<::android::hardware::audio::effect::V5_0::Result> IEqualizerEffect::init()
// no default implementation for: ::android::hardware::Return<::android::hardware::audio::effect::V5_0::Result> IEqualizerEffect::setConfig(const ::android::hardware::audio::effect::V5_0::EffectConfig& config, const ::android::sp<::android::hardware::audio::effect::V5_0::IEffectBufferProviderCallback>& inputBufferProvider, const ::android::sp<::android::hardware::audio::effect::V5_0::IEffectBufferProviderCallback>& outputBufferProvider)
// no default implementation for: ::android::hardware::Return<::android::hardware::audio::effect::V5_0::Result> IEqualizerEffect::reset()
// no default implementation for: ::android::hardware::Return<::android::hardware::audio::effect::V5_0::Result> IEqualizerEffect::enable()
// no default implementation for: ::android::hardware::Return<::android::hardware::audio::effect::V5_0::Result> IEqualizerEffect::disable()
// no default implementation for: ::android::hardware::Return<::android::hardware::audio::effect::V5_0::Result> IEqualizerEffect::setDevice(::android::hardware::hidl_bitfield<::android::hardware::audio::common::V5_0::AudioDevice> device)
// no default implementation for: ::android::hardware::Return<void> IEqualizerEffect::setAndGetVolume(const ::android::hardware::hidl_vec<uint32_t>& volumes, setAndGetVolume_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<::android::hardware::audio::effect::V5_0::Result> IEqualizerEffect::volumeChangeNotification(const ::android::hardware::hidl_vec<uint32_t>& volumes)
// no default implementation for: ::android::hardware::Return<::android::hardware::audio::effect::V5_0::Result> IEqualizerEffect::setAudioMode(::android::hardware::audio::common::V5_0::AudioMode mode)
// no default implementation for: ::android::hardware::Return<::android::hardware::audio::effect::V5_0::Result> IEqualizerEffect::setConfigReverse(const ::android::hardware::audio::effect::V5_0::EffectConfig& config, const ::android::sp<::android::hardware::audio::effect::V5_0::IEffectBufferProviderCallback>& inputBufferProvider, const ::android::sp<::android::hardware::audio::effect::V5_0::IEffectBufferProviderCallback>& outputBufferProvider)
// no default implementation for: ::android::hardware::Return<::android::hardware::audio::effect::V5_0::Result> IEqualizerEffect::setInputDevice(::android::hardware::hidl_bitfield<::android::hardware::audio::common::V5_0::AudioDevice> device)
// no default implementation for: ::android::hardware::Return<void> IEqualizerEffect::getConfig(getConfig_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IEqualizerEffect::getConfigReverse(getConfigReverse_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IEqualizerEffect::getSupportedAuxChannelsConfigs(uint32_t maxConfigs, getSupportedAuxChannelsConfigs_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IEqualizerEffect::getAuxChannelsConfig(getAuxChannelsConfig_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<::android::hardware::audio::effect::V5_0::Result> IEqualizerEffect::setAuxChannelsConfig(const ::android::hardware::audio::effect::V5_0::EffectAuxChannelsConfig& config)
// no default implementation for: ::android::hardware::Return<::android::hardware::audio::effect::V5_0::Result> IEqualizerEffect::setAudioSource(::android::hardware::audio::common::V5_0::AudioSource source)
// no default implementation for: ::android::hardware::Return<::android::hardware::audio::effect::V5_0::Result> IEqualizerEffect::offload(const ::android::hardware::audio::effect::V5_0::EffectOffloadParameter& param)
// no default implementation for: ::android::hardware::Return<void> IEqualizerEffect::getDescriptor(getDescriptor_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IEqualizerEffect::prepareForProcessing(prepareForProcessing_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<::android::hardware::audio::effect::V5_0::Result> IEqualizerEffect::setProcessBuffers(const ::android::hardware::audio::effect::V5_0::AudioBuffer& inBuffer, const ::android::hardware::audio::effect::V5_0::AudioBuffer& outBuffer)
// no default implementation for: ::android::hardware::Return<void> IEqualizerEffect::command(uint32_t commandId, const ::android::hardware::hidl_vec<uint8_t>& data, uint32_t resultMaxSize, command_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<::android::hardware::audio::effect::V5_0::Result> IEqualizerEffect::setParameter(const ::android::hardware::hidl_vec<uint8_t>& parameter, const ::android::hardware::hidl_vec<uint8_t>& value)
// no default implementation for: ::android::hardware::Return<void> IEqualizerEffect::getParameter(const ::android::hardware::hidl_vec<uint8_t>& parameter, uint32_t valueMaxSize, getParameter_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IEqualizerEffect::getSupportedConfigsForFeature(uint32_t featureId, uint32_t maxConfigs, uint32_t configSize, getSupportedConfigsForFeature_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IEqualizerEffect::getCurrentConfigForFeature(uint32_t featureId, uint32_t configSize, getCurrentConfigForFeature_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<::android::hardware::audio::effect::V5_0::Result> IEqualizerEffect::setCurrentConfigForFeature(uint32_t featureId, const ::android::hardware::hidl_vec<uint8_t>& configData)
// no default implementation for: ::android::hardware::Return<::android::hardware::audio::effect::V5_0::Result> IEqualizerEffect::close()

// Methods from ::android::hardware::audio::effect::V5_0::IEqualizerEffect follow.
// no default implementation for: ::android::hardware::Return<void> IEqualizerEffect::getNumBands(getNumBands_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IEqualizerEffect::getLevelRange(getLevelRange_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<::android::hardware::audio::effect::V5_0::Result> IEqualizerEffect::setBandLevel(uint16_t band, int16_t level)
// no default implementation for: ::android::hardware::Return<void> IEqualizerEffect::getBandLevel(uint16_t band, getBandLevel_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IEqualizerEffect::getBandCenterFrequency(uint16_t band, getBandCenterFrequency_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IEqualizerEffect::getBandFrequencyRange(uint16_t band, getBandFrequencyRange_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IEqualizerEffect::getBandForFrequency(uint32_t freqmHz, getBandForFrequency_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IEqualizerEffect::getPresetNames(getPresetNames_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<::android::hardware::audio::effect::V5_0::Result> IEqualizerEffect::setCurrentPreset(uint16_t preset)
// no default implementation for: ::android::hardware::Return<void> IEqualizerEffect::getCurrentPreset(getCurrentPreset_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<::android::hardware::audio::effect::V5_0::Result> IEqualizerEffect::setAllProperties(const ::android::hardware::audio::effect::V5_0::IEqualizerEffect::AllProperties& properties)
// no default implementation for: ::android::hardware::Return<void> IEqualizerEffect::getAllProperties(getAllProperties_cb _hidl_cb)

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> IEqualizerEffect::interfaceChain(interfaceChain_cb _hidl_cb){
    _hidl_cb({
        ::android::hardware::audio::effect::V5_0::IEqualizerEffect::descriptor,
        ::android::hardware::audio::effect::V5_0::IEffect::descriptor,
        ::android::hidl::base::V1_0::IBase::descriptor,
    });
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IEqualizerEffect::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    (void)fd;
    (void)options;
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IEqualizerEffect::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    _hidl_cb(::android::hardware::audio::effect::V5_0::IEqualizerEffect::descriptor);
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IEqualizerEffect::getHashChain(getHashChain_cb _hidl_cb){
    _hidl_cb({
        (uint8_t[32]){207,53,111,67,10,27,180,47,217,26,246,95,16,94,7,250,132,165,146,125,196,92,54,216,255,206,91,108,19,44,31,60} /* cf356f430a1bb42fd91af65f105e07fa84a5927dc45c36d8ffce5b6c132c1f3c */,
        (uint8_t[32]){68,90,101,234,46,221,28,203,168,168,216,225,200,141,36,198,234,103,229,125,53,95,164,70,171,57,14,32,240,219,20,170} /* 445a65ea2edd1ccba8a8d8e1c88d24c6ea67e57d355fa446ab390e20f0db14aa */,
        (uint8_t[32]){236,127,215,158,208,45,250,133,188,73,148,38,173,174,62,190,35,239,5,36,243,205,105,87,19,147,36,184,59,24,202,76} /* ec7fd79ed02dfa85bc499426adae3ebe23ef0524f3cd6957139324b83b18ca4c */});
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IEqualizerEffect::setHALInstrumentation(){
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> IEqualizerEffect::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    (void)cookie;
    return (recipient != nullptr);
}

::android::hardware::Return<void> IEqualizerEffect::ping(){
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IEqualizerEffect::getDebugInfo(getDebugInfo_cb _hidl_cb){
    ::android::hidl::base::V1_0::DebugInfo info = {};
    info.pid = -1;
    info.ptr = 0;
    info.arch = 
    #if defined(__LP64__)
    ::android::hidl::base::V1_0::DebugInfo::Architecture::IS_64BIT
    #else
    ::android::hidl::base::V1_0::DebugInfo::Architecture::IS_32BIT
    #endif
    ;
    _hidl_cb(info);
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IEqualizerEffect::notifySyspropsChanged(){
    ::android::report_sysprop_change();
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> IEqualizerEffect::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
    return (recipient != nullptr);
}


::android::hardware::Return<::android::sp<::android::hardware::audio::effect::V5_0::IEqualizerEffect>> IEqualizerEffect::castFrom(const ::android::sp<::android::hardware::audio::effect::V5_0::IEqualizerEffect>& parent, bool /* emitError */) {
    return parent;
}

::android::hardware::Return<::android::sp<::android::hardware::audio::effect::V5_0::IEqualizerEffect>> IEqualizerEffect::castFrom(const ::android::sp<::android::hardware::audio::effect::V5_0::IEffect>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<IEqualizerEffect, ::android::hardware::audio::effect::V5_0::IEffect, BpHwEqualizerEffect>(
            parent, "android.hardware.audio.effect@5.0::IEqualizerEffect", emitError);
}

::android::hardware::Return<::android::sp<::android::hardware::audio::effect::V5_0::IEqualizerEffect>> IEqualizerEffect::castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<IEqualizerEffect, ::android::hidl::base::V1_0::IBase, BpHwEqualizerEffect>(
            parent, "android.hardware.audio.effect@5.0::IEqualizerEffect", emitError);
}

BpHwEqualizerEffect::BpHwEqualizerEffect(const ::android::sp<::android::hardware::IBinder> &_hidl_impl)
        : BpInterface<IEqualizerEffect>(_hidl_impl),
          ::android::hardware::details::HidlInstrumentor("android.hardware.audio.effect@5.0", "IEqualizerEffect") {
}

void BpHwEqualizerEffect::onLastStrongRef(const void* id) {
    {
        std::unique_lock<std::mutex> lock(_hidl_mMutex);
        _hidl_mDeathRecipients.clear();
    }

    BpInterface<IEqualizerEffect>::onLastStrongRef(id);
}
// Methods from ::android::hardware::audio::effect::V5_0::IEqualizerEffect follow.
::android::hardware::Return<void> BpHwEqualizerEffect::_hidl_getNumBands(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, getNumBands_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IEqualizerEffect::getNumBands::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.audio.effect", "5.0", "IEqualizerEffect", "getNumBands", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwEqualizerEffect::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(29 /* getNumBands */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::audio::effect::V5_0::Result _hidl_out_retval;
        uint16_t _hidl_out_numBands;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_retval);
        if (_hidl_err != ::android::OK) { return; }

        _hidl_err = _hidl_reply.readUint16(&_hidl_out_numBands);
        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(_hidl_out_retval, _hidl_out_numBands);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_retval);
            _hidl_args.push_back((void *)&_hidl_out_numBands);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.audio.effect", "5.0", "IEqualizerEffect", "getNumBands", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

    });
    if (_hidl_transact_err != ::android::OK) {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    if (!_hidl_status.isOk()) { return _hidl_status; }
    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwEqualizerEffect::_hidl_getLevelRange(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, getLevelRange_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IEqualizerEffect::getLevelRange::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.audio.effect", "5.0", "IEqualizerEffect", "getLevelRange", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwEqualizerEffect::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(30 /* getLevelRange */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::audio::effect::V5_0::Result _hidl_out_retval;
        int16_t _hidl_out_minLevel;
        int16_t _hidl_out_maxLevel;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_retval);
        if (_hidl_err != ::android::OK) { return; }

        _hidl_err = _hidl_reply.readInt16(&_hidl_out_minLevel);
        if (_hidl_err != ::android::OK) { return; }

        _hidl_err = _hidl_reply.readInt16(&_hidl_out_maxLevel);
        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(_hidl_out_retval, _hidl_out_minLevel, _hidl_out_maxLevel);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_retval);
            _hidl_args.push_back((void *)&_hidl_out_minLevel);
            _hidl_args.push_back((void *)&_hidl_out_maxLevel);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.audio.effect", "5.0", "IEqualizerEffect", "getLevelRange", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

    });
    if (_hidl_transact_err != ::android::OK) {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    if (!_hidl_status.isOk()) { return _hidl_status; }
    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<::android::hardware::audio::effect::V5_0::Result> BpHwEqualizerEffect::_hidl_setBandLevel(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint16_t band, int16_t level) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IEqualizerEffect::setBandLevel::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&band);
        _hidl_args.push_back((void *)&level);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.audio.effect", "5.0", "IEqualizerEffect", "setBandLevel", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    ::android::hardware::audio::effect::V5_0::Result _hidl_out_retval;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwEqualizerEffect::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint16(band);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt16(level);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(31 /* setBandLevel */, _hidl_data, &_hidl_reply, 0 /* flags */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_retval);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_retval);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.audio.effect", "5.0", "IEqualizerEffect", "setBandLevel", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<::android::hardware::audio::effect::V5_0::Result>(_hidl_out_retval);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<::android::hardware::audio::effect::V5_0::Result>(_hidl_status);
}

::android::hardware::Return<void> BpHwEqualizerEffect::_hidl_getBandLevel(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint16_t band, getBandLevel_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IEqualizerEffect::getBandLevel::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&band);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.audio.effect", "5.0", "IEqualizerEffect", "getBandLevel", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwEqualizerEffect::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint16(band);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(32 /* getBandLevel */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::audio::effect::V5_0::Result _hidl_out_retval;
        int16_t _hidl_out_level;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_retval);
        if (_hidl_err != ::android::OK) { return; }

        _hidl_err = _hidl_reply.readInt16(&_hidl_out_level);
        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(_hidl_out_retval, _hidl_out_level);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_retval);
            _hidl_args.push_back((void *)&_hidl_out_level);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.audio.effect", "5.0", "IEqualizerEffect", "getBandLevel", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

    });
    if (_hidl_transact_err != ::android::OK) {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    if (!_hidl_status.isOk()) { return _hidl_status; }
    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwEqualizerEffect::_hidl_getBandCenterFrequency(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint16_t band, getBandCenterFrequency_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IEqualizerEffect::getBandCenterFrequency::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&band);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.audio.effect", "5.0", "IEqualizerEffect", "getBandCenterFrequency", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwEqualizerEffect::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint16(band);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(33 /* getBandCenterFrequency */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::audio::effect::V5_0::Result _hidl_out_retval;
        uint32_t _hidl_out_centerFreqmHz;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_retval);
        if (_hidl_err != ::android::OK) { return; }

        _hidl_err = _hidl_reply.readUint32(&_hidl_out_centerFreqmHz);
        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(_hidl_out_retval, _hidl_out_centerFreqmHz);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_retval);
            _hidl_args.push_back((void *)&_hidl_out_centerFreqmHz);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.audio.effect", "5.0", "IEqualizerEffect", "getBandCenterFrequency", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

    });
    if (_hidl_transact_err != ::android::OK) {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    if (!_hidl_status.isOk()) { return _hidl_status; }
    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwEqualizerEffect::_hidl_getBandFrequencyRange(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint16_t band, getBandFrequencyRange_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IEqualizerEffect::getBandFrequencyRange::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&band);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.audio.effect", "5.0", "IEqualizerEffect", "getBandFrequencyRange", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwEqualizerEffect::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint16(band);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(34 /* getBandFrequencyRange */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::audio::effect::V5_0::Result _hidl_out_retval;
        uint32_t _hidl_out_minFreqmHz;
        uint32_t _hidl_out_maxFreqmHz;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_retval);
        if (_hidl_err != ::android::OK) { return; }

        _hidl_err = _hidl_reply.readUint32(&_hidl_out_minFreqmHz);
        if (_hidl_err != ::android::OK) { return; }

        _hidl_err = _hidl_reply.readUint32(&_hidl_out_maxFreqmHz);
        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(_hidl_out_retval, _hidl_out_minFreqmHz, _hidl_out_maxFreqmHz);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_retval);
            _hidl_args.push_back((void *)&_hidl_out_minFreqmHz);
            _hidl_args.push_back((void *)&_hidl_out_maxFreqmHz);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.audio.effect", "5.0", "IEqualizerEffect", "getBandFrequencyRange", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

    });
    if (_hidl_transact_err != ::android::OK) {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    if (!_hidl_status.isOk()) { return _hidl_status; }
    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwEqualizerEffect::_hidl_getBandForFrequency(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint32_t freqmHz, getBandForFrequency_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IEqualizerEffect::getBandForFrequency::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&freqmHz);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.audio.effect", "5.0", "IEqualizerEffect", "getBandForFrequency", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwEqualizerEffect::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(freqmHz);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(35 /* getBandForFrequency */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::audio::effect::V5_0::Result _hidl_out_retval;
        uint16_t _hidl_out_band;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_retval);
        if (_hidl_err != ::android::OK) { return; }

        _hidl_err = _hidl_reply.readUint16(&_hidl_out_band);
        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(_hidl_out_retval, _hidl_out_band);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_retval);
            _hidl_args.push_back((void *)&_hidl_out_band);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.audio.effect", "5.0", "IEqualizerEffect", "getBandForFrequency", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

    });
    if (_hidl_transact_err != ::android::OK) {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    if (!_hidl_status.isOk()) { return _hidl_status; }
    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwEqualizerEffect::_hidl_getPresetNames(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, getPresetNames_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IEqualizerEffect::getPresetNames::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.audio.effect", "5.0", "IEqualizerEffect", "getPresetNames", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwEqualizerEffect::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(36 /* getPresetNames */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::audio::effect::V5_0::Result _hidl_out_retval;
        const ::android::hardware::hidl_vec<::android::hardware::hidl_string>* _hidl_out_names;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_retval);
        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_names_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_names), &_hidl__hidl_out_names_parent,  reinterpret_cast<const void **>(&_hidl_out_names));

        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_names_child;

        _hidl_err = ::android::hardware::readEmbeddedFromParcel(
                const_cast<::android::hardware::hidl_vec<::android::hardware::hidl_string> &>(*_hidl_out_names),
                _hidl_reply,
                _hidl__hidl_out_names_parent,
                0 /* parentOffset */, &_hidl__hidl_out_names_child);

        if (_hidl_err != ::android::OK) { return; }

        for (size_t _hidl_index_0 = 0; _hidl_index_0 < _hidl_out_names->size(); ++_hidl_index_0) {
            _hidl_err = ::android::hardware::readEmbeddedFromParcel(
                    const_cast<::android::hardware::hidl_string &>((*_hidl_out_names)[_hidl_index_0]),
                    _hidl_reply,
                    _hidl__hidl_out_names_child,
                    _hidl_index_0 * sizeof(::android::hardware::hidl_string));

            if (_hidl_err != ::android::OK) { return; }

        }

        _hidl_cb(_hidl_out_retval, *_hidl_out_names);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_retval);
            _hidl_args.push_back((void *)_hidl_out_names);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.audio.effect", "5.0", "IEqualizerEffect", "getPresetNames", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

    });
    if (_hidl_transact_err != ::android::OK) {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    if (!_hidl_status.isOk()) { return _hidl_status; }
    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<::android::hardware::audio::effect::V5_0::Result> BpHwEqualizerEffect::_hidl_setCurrentPreset(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint16_t preset) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IEqualizerEffect::setCurrentPreset::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&preset);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.audio.effect", "5.0", "IEqualizerEffect", "setCurrentPreset", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    ::android::hardware::audio::effect::V5_0::Result _hidl_out_retval;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwEqualizerEffect::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint16(preset);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(37 /* setCurrentPreset */, _hidl_data, &_hidl_reply, 0 /* flags */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_retval);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_retval);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.audio.effect", "5.0", "IEqualizerEffect", "setCurrentPreset", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<::android::hardware::audio::effect::V5_0::Result>(_hidl_out_retval);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<::android::hardware::audio::effect::V5_0::Result>(_hidl_status);
}

::android::hardware::Return<void> BpHwEqualizerEffect::_hidl_getCurrentPreset(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, getCurrentPreset_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IEqualizerEffect::getCurrentPreset::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.audio.effect", "5.0", "IEqualizerEffect", "getCurrentPreset", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwEqualizerEffect::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(38 /* getCurrentPreset */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::audio::effect::V5_0::Result _hidl_out_retval;
        uint16_t _hidl_out_preset;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_retval);
        if (_hidl_err != ::android::OK) { return; }

        _hidl_err = _hidl_reply.readUint16(&_hidl_out_preset);
        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(_hidl_out_retval, _hidl_out_preset);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_retval);
            _hidl_args.push_back((void *)&_hidl_out_preset);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.audio.effect", "5.0", "IEqualizerEffect", "getCurrentPreset", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

    });
    if (_hidl_transact_err != ::android::OK) {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    if (!_hidl_status.isOk()) { return _hidl_status; }
    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<::android::hardware::audio::effect::V5_0::Result> BpHwEqualizerEffect::_hidl_setAllProperties(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::audio::effect::V5_0::IEqualizerEffect::AllProperties& properties) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IEqualizerEffect::setAllProperties::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&properties);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.audio.effect", "5.0", "IEqualizerEffect", "setAllProperties", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    ::android::hardware::audio::effect::V5_0::Result _hidl_out_retval;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwEqualizerEffect::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_properties_parent;

    _hidl_err = _hidl_data.writeBuffer(&properties, sizeof(properties), &_hidl_properties_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = writeEmbeddedToParcel(
            properties,
            &_hidl_data,
            _hidl_properties_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(39 /* setAllProperties */, _hidl_data, &_hidl_reply, 0 /* flags */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_retval);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_retval);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.audio.effect", "5.0", "IEqualizerEffect", "setAllProperties", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<::android::hardware::audio::effect::V5_0::Result>(_hidl_out_retval);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<::android::hardware::audio::effect::V5_0::Result>(_hidl_status);
}

::android::hardware::Return<void> BpHwEqualizerEffect::_hidl_getAllProperties(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, getAllProperties_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IEqualizerEffect::getAllProperties::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.audio.effect", "5.0", "IEqualizerEffect", "getAllProperties", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwEqualizerEffect::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(40 /* getAllProperties */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::audio::effect::V5_0::Result _hidl_out_retval;
        ::android::hardware::audio::effect::V5_0::IEqualizerEffect::AllProperties* _hidl_out_properties;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_retval);
        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_properties_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_properties), &_hidl__hidl_out_properties_parent,  const_cast<const void**>(reinterpret_cast<void **>(&_hidl_out_properties)));
        if (_hidl_err != ::android::OK) { return; }

        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::audio::effect::V5_0::IEqualizerEffect::AllProperties &>(*_hidl_out_properties),
                _hidl_reply,
                _hidl__hidl_out_properties_parent,
                0 /* parentOffset */);

        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(_hidl_out_retval, *_hidl_out_properties);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_retval);
            _hidl_args.push_back((void *)_hidl_out_properties);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.audio.effect", "5.0", "IEqualizerEffect", "getAllProperties", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

    });
    if (_hidl_transact_err != ::android::OK) {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    if (!_hidl_status.isOk()) { return _hidl_status; }
    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}


// Methods from ::android::hardware::audio::effect::V5_0::IEffect follow.
::android::hardware::Return<::android::hardware::audio::effect::V5_0::Result> BpHwEqualizerEffect::init(){
    ::android::hardware::Return<::android::hardware::audio::effect::V5_0::Result>  _hidl_out = ::android::hardware::audio::effect::V5_0::BpHwEffect::_hidl_init(this, this);

    return _hidl_out;
}

::android::hardware::Return<::android::hardware::audio::effect::V5_0::Result> BpHwEqualizerEffect::setConfig(const ::android::hardware::audio::effect::V5_0::EffectConfig& config, const ::android::sp<::android::hardware::audio::effect::V5_0::IEffectBufferProviderCallback>& inputBufferProvider, const ::android::sp<::android::hardware::audio::effect::V5_0::IEffectBufferProviderCallback>& outputBufferProvider){
    ::android::hardware::Return<::android::hardware::audio::effect::V5_0::Result>  _hidl_out = ::android::hardware::audio::effect::V5_0::BpHwEffect::_hidl_setConfig(this, this, config, inputBufferProvider, outputBufferProvider);

    return _hidl_out;
}

::android::hardware::Return<::android::hardware::audio::effect::V5_0::Result> BpHwEqualizerEffect::reset(){
    ::android::hardware::Return<::android::hardware::audio::effect::V5_0::Result>  _hidl_out = ::android::hardware::audio::effect::V5_0::BpHwEffect::_hidl_reset(this, this);

    return _hidl_out;
}

::android::hardware::Return<::android::hardware::audio::effect::V5_0::Result> BpHwEqualizerEffect::enable(){
    ::android::hardware::Return<::android::hardware::audio::effect::V5_0::Result>  _hidl_out = ::android::hardware::audio::effect::V5_0::BpHwEffect::_hidl_enable(this, this);

    return _hidl_out;
}

::android::hardware::Return<::android::hardware::audio::effect::V5_0::Result> BpHwEqualizerEffect::disable(){
    ::android::hardware::Return<::android::hardware::audio::effect::V5_0::Result>  _hidl_out = ::android::hardware::audio::effect::V5_0::BpHwEffect::_hidl_disable(this, this);

    return _hidl_out;
}

::android::hardware::Return<::android::hardware::audio::effect::V5_0::Result> BpHwEqualizerEffect::setDevice(::android::hardware::hidl_bitfield<::android::hardware::audio::common::V5_0::AudioDevice> device){
    ::android::hardware::Return<::android::hardware::audio::effect::V5_0::Result>  _hidl_out = ::android::hardware::audio::effect::V5_0::BpHwEffect::_hidl_setDevice(this, this, device);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwEqualizerEffect::setAndGetVolume(const ::android::hardware::hidl_vec<uint32_t>& volumes, setAndGetVolume_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::audio::effect::V5_0::BpHwEffect::_hidl_setAndGetVolume(this, this, volumes, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<::android::hardware::audio::effect::V5_0::Result> BpHwEqualizerEffect::volumeChangeNotification(const ::android::hardware::hidl_vec<uint32_t>& volumes){
    ::android::hardware::Return<::android::hardware::audio::effect::V5_0::Result>  _hidl_out = ::android::hardware::audio::effect::V5_0::BpHwEffect::_hidl_volumeChangeNotification(this, this, volumes);

    return _hidl_out;
}

::android::hardware::Return<::android::hardware::audio::effect::V5_0::Result> BpHwEqualizerEffect::setAudioMode(::android::hardware::audio::common::V5_0::AudioMode mode){
    ::android::hardware::Return<::android::hardware::audio::effect::V5_0::Result>  _hidl_out = ::android::hardware::audio::effect::V5_0::BpHwEffect::_hidl_setAudioMode(this, this, mode);

    return _hidl_out;
}

::android::hardware::Return<::android::hardware::audio::effect::V5_0::Result> BpHwEqualizerEffect::setConfigReverse(const ::android::hardware::audio::effect::V5_0::EffectConfig& config, const ::android::sp<::android::hardware::audio::effect::V5_0::IEffectBufferProviderCallback>& inputBufferProvider, const ::android::sp<::android::hardware::audio::effect::V5_0::IEffectBufferProviderCallback>& outputBufferProvider){
    ::android::hardware::Return<::android::hardware::audio::effect::V5_0::Result>  _hidl_out = ::android::hardware::audio::effect::V5_0::BpHwEffect::_hidl_setConfigReverse(this, this, config, inputBufferProvider, outputBufferProvider);

    return _hidl_out;
}

::android::hardware::Return<::android::hardware::audio::effect::V5_0::Result> BpHwEqualizerEffect::setInputDevice(::android::hardware::hidl_bitfield<::android::hardware::audio::common::V5_0::AudioDevice> device){
    ::android::hardware::Return<::android::hardware::audio::effect::V5_0::Result>  _hidl_out = ::android::hardware::audio::effect::V5_0::BpHwEffect::_hidl_setInputDevice(this, this, device);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwEqualizerEffect::getConfig(getConfig_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::audio::effect::V5_0::BpHwEffect::_hidl_getConfig(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwEqualizerEffect::getConfigReverse(getConfigReverse_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::audio::effect::V5_0::BpHwEffect::_hidl_getConfigReverse(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwEqualizerEffect::getSupportedAuxChannelsConfigs(uint32_t maxConfigs, getSupportedAuxChannelsConfigs_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::audio::effect::V5_0::BpHwEffect::_hidl_getSupportedAuxChannelsConfigs(this, this, maxConfigs, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwEqualizerEffect::getAuxChannelsConfig(getAuxChannelsConfig_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::audio::effect::V5_0::BpHwEffect::_hidl_getAuxChannelsConfig(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<::android::hardware::audio::effect::V5_0::Result> BpHwEqualizerEffect::setAuxChannelsConfig(const ::android::hardware::audio::effect::V5_0::EffectAuxChannelsConfig& config){
    ::android::hardware::Return<::android::hardware::audio::effect::V5_0::Result>  _hidl_out = ::android::hardware::audio::effect::V5_0::BpHwEffect::_hidl_setAuxChannelsConfig(this, this, config);

    return _hidl_out;
}

::android::hardware::Return<::android::hardware::audio::effect::V5_0::Result> BpHwEqualizerEffect::setAudioSource(::android::hardware::audio::common::V5_0::AudioSource source){
    ::android::hardware::Return<::android::hardware::audio::effect::V5_0::Result>  _hidl_out = ::android::hardware::audio::effect::V5_0::BpHwEffect::_hidl_setAudioSource(this, this, source);

    return _hidl_out;
}

::android::hardware::Return<::android::hardware::audio::effect::V5_0::Result> BpHwEqualizerEffect::offload(const ::android::hardware::audio::effect::V5_0::EffectOffloadParameter& param){
    ::android::hardware::Return<::android::hardware::audio::effect::V5_0::Result>  _hidl_out = ::android::hardware::audio::effect::V5_0::BpHwEffect::_hidl_offload(this, this, param);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwEqualizerEffect::getDescriptor(getDescriptor_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::audio::effect::V5_0::BpHwEffect::_hidl_getDescriptor(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwEqualizerEffect::prepareForProcessing(prepareForProcessing_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::audio::effect::V5_0::BpHwEffect::_hidl_prepareForProcessing(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<::android::hardware::audio::effect::V5_0::Result> BpHwEqualizerEffect::setProcessBuffers(const ::android::hardware::audio::effect::V5_0::AudioBuffer& inBuffer, const ::android::hardware::audio::effect::V5_0::AudioBuffer& outBuffer){
    ::android::hardware::Return<::android::hardware::audio::effect::V5_0::Result>  _hidl_out = ::android::hardware::audio::effect::V5_0::BpHwEffect::_hidl_setProcessBuffers(this, this, inBuffer, outBuffer);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwEqualizerEffect::command(uint32_t commandId, const ::android::hardware::hidl_vec<uint8_t>& data, uint32_t resultMaxSize, command_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::audio::effect::V5_0::BpHwEffect::_hidl_command(this, this, commandId, data, resultMaxSize, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<::android::hardware::audio::effect::V5_0::Result> BpHwEqualizerEffect::setParameter(const ::android::hardware::hidl_vec<uint8_t>& parameter, const ::android::hardware::hidl_vec<uint8_t>& value){
    ::android::hardware::Return<::android::hardware::audio::effect::V5_0::Result>  _hidl_out = ::android::hardware::audio::effect::V5_0::BpHwEffect::_hidl_setParameter(this, this, parameter, value);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwEqualizerEffect::getParameter(const ::android::hardware::hidl_vec<uint8_t>& parameter, uint32_t valueMaxSize, getParameter_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::audio::effect::V5_0::BpHwEffect::_hidl_getParameter(this, this, parameter, valueMaxSize, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwEqualizerEffect::getSupportedConfigsForFeature(uint32_t featureId, uint32_t maxConfigs, uint32_t configSize, getSupportedConfigsForFeature_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::audio::effect::V5_0::BpHwEffect::_hidl_getSupportedConfigsForFeature(this, this, featureId, maxConfigs, configSize, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwEqualizerEffect::getCurrentConfigForFeature(uint32_t featureId, uint32_t configSize, getCurrentConfigForFeature_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::audio::effect::V5_0::BpHwEffect::_hidl_getCurrentConfigForFeature(this, this, featureId, configSize, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<::android::hardware::audio::effect::V5_0::Result> BpHwEqualizerEffect::setCurrentConfigForFeature(uint32_t featureId, const ::android::hardware::hidl_vec<uint8_t>& configData){
    ::android::hardware::Return<::android::hardware::audio::effect::V5_0::Result>  _hidl_out = ::android::hardware::audio::effect::V5_0::BpHwEffect::_hidl_setCurrentConfigForFeature(this, this, featureId, configData);

    return _hidl_out;
}

::android::hardware::Return<::android::hardware::audio::effect::V5_0::Result> BpHwEqualizerEffect::close(){
    ::android::hardware::Return<::android::hardware::audio::effect::V5_0::Result>  _hidl_out = ::android::hardware::audio::effect::V5_0::BpHwEffect::_hidl_close(this, this);

    return _hidl_out;
}


// Methods from ::android::hardware::audio::effect::V5_0::IEqualizerEffect follow.
::android::hardware::Return<void> BpHwEqualizerEffect::getNumBands(getNumBands_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::audio::effect::V5_0::BpHwEqualizerEffect::_hidl_getNumBands(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwEqualizerEffect::getLevelRange(getLevelRange_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::audio::effect::V5_0::BpHwEqualizerEffect::_hidl_getLevelRange(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<::android::hardware::audio::effect::V5_0::Result> BpHwEqualizerEffect::setBandLevel(uint16_t band, int16_t level){
    ::android::hardware::Return<::android::hardware::audio::effect::V5_0::Result>  _hidl_out = ::android::hardware::audio::effect::V5_0::BpHwEqualizerEffect::_hidl_setBandLevel(this, this, band, level);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwEqualizerEffect::getBandLevel(uint16_t band, getBandLevel_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::audio::effect::V5_0::BpHwEqualizerEffect::_hidl_getBandLevel(this, this, band, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwEqualizerEffect::getBandCenterFrequency(uint16_t band, getBandCenterFrequency_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::audio::effect::V5_0::BpHwEqualizerEffect::_hidl_getBandCenterFrequency(this, this, band, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwEqualizerEffect::getBandFrequencyRange(uint16_t band, getBandFrequencyRange_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::audio::effect::V5_0::BpHwEqualizerEffect::_hidl_getBandFrequencyRange(this, this, band, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwEqualizerEffect::getBandForFrequency(uint32_t freqmHz, getBandForFrequency_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::audio::effect::V5_0::BpHwEqualizerEffect::_hidl_getBandForFrequency(this, this, freqmHz, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwEqualizerEffect::getPresetNames(getPresetNames_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::audio::effect::V5_0::BpHwEqualizerEffect::_hidl_getPresetNames(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<::android::hardware::audio::effect::V5_0::Result> BpHwEqualizerEffect::setCurrentPreset(uint16_t preset){
    ::android::hardware::Return<::android::hardware::audio::effect::V5_0::Result>  _hidl_out = ::android::hardware::audio::effect::V5_0::BpHwEqualizerEffect::_hidl_setCurrentPreset(this, this, preset);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwEqualizerEffect::getCurrentPreset(getCurrentPreset_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::audio::effect::V5_0::BpHwEqualizerEffect::_hidl_getCurrentPreset(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<::android::hardware::audio::effect::V5_0::Result> BpHwEqualizerEffect::setAllProperties(const ::android::hardware::audio::effect::V5_0::IEqualizerEffect::AllProperties& properties){
    ::android::hardware::Return<::android::hardware::audio::effect::V5_0::Result>  _hidl_out = ::android::hardware::audio::effect::V5_0::BpHwEqualizerEffect::_hidl_setAllProperties(this, this, properties);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwEqualizerEffect::getAllProperties(getAllProperties_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::audio::effect::V5_0::BpHwEqualizerEffect::_hidl_getAllProperties(this, this, _hidl_cb);

    return _hidl_out;
}


// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BpHwEqualizerEffect::interfaceChain(interfaceChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwEqualizerEffect::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_debug(this, this, fd, options);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwEqualizerEffect::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceDescriptor(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwEqualizerEffect::getHashChain(getHashChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getHashChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwEqualizerEffect::setHALInstrumentation(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_setHALInstrumentation(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwEqualizerEffect::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    ::android::hardware::ProcessState::self()->startThreadPool();
    ::android::hardware::hidl_binder_death_recipient *binder_recipient = new ::android::hardware::hidl_binder_death_recipient(recipient, cookie, this);
    std::unique_lock<std::mutex> lock(_hidl_mMutex);
    _hidl_mDeathRecipients.push_back(binder_recipient);
    return (remote()->linkToDeath(binder_recipient) == ::android::OK);
}

::android::hardware::Return<void> BpHwEqualizerEffect::ping(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_ping(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwEqualizerEffect::getDebugInfo(getDebugInfo_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getDebugInfo(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwEqualizerEffect::notifySyspropsChanged(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_notifySyspropsChanged(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwEqualizerEffect::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
    std::unique_lock<std::mutex> lock(_hidl_mMutex);
    for (auto it = _hidl_mDeathRecipients.rbegin();it != _hidl_mDeathRecipients.rend();++it) {
        if ((*it)->getRecipient() == recipient) {
            ::android::status_t status = remote()->unlinkToDeath(*it);
            _hidl_mDeathRecipients.erase(it.base()-1);
            return status == ::android::OK;
        }
    }
    return false;
}


BnHwEqualizerEffect::BnHwEqualizerEffect(const ::android::sp<IEqualizerEffect> &_hidl_impl)
        : ::android::hidl::base::V1_0::BnHwBase(_hidl_impl, "android.hardware.audio.effect@5.0", "IEqualizerEffect") { 
            _hidl_mImpl = _hidl_impl;
            auto prio = ::android::hardware::getMinSchedulerPolicy(_hidl_impl);
            mSchedPolicy = prio.sched_policy;
            mSchedPriority = prio.prio;
            setRequestingSid(::android::hardware::getRequestingSid(_hidl_impl));
}

BnHwEqualizerEffect::~BnHwEqualizerEffect() {
    ::android::hardware::details::gBnMap->eraseIfEqual(_hidl_mImpl.get(), this);
}

// Methods from ::android::hardware::audio::effect::V5_0::IEqualizerEffect follow.
::android::status_t BnHwEqualizerEffect::_hidl_getNumBands(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwEqualizerEffect::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IEqualizerEffect::getNumBands::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.audio.effect", "5.0", "IEqualizerEffect", "getNumBands", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IEqualizerEffect*>(_hidl_this->getImpl().get())->getNumBands([&](const auto &_hidl_out_retval, const auto &_hidl_out_numBands) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("getNumBands: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_retval);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_err = _hidl_reply->writeUint16(_hidl_out_numBands);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_retval);
            _hidl_args.push_back((void *)&_hidl_out_numBands);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.audio.effect", "5.0", "IEqualizerEffect", "getNumBands", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("getNumBands: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwEqualizerEffect::_hidl_getLevelRange(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwEqualizerEffect::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IEqualizerEffect::getLevelRange::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.audio.effect", "5.0", "IEqualizerEffect", "getLevelRange", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IEqualizerEffect*>(_hidl_this->getImpl().get())->getLevelRange([&](const auto &_hidl_out_retval, const auto &_hidl_out_minLevel, const auto &_hidl_out_maxLevel) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("getLevelRange: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_retval);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_err = _hidl_reply->writeInt16(_hidl_out_minLevel);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_err = _hidl_reply->writeInt16(_hidl_out_maxLevel);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_retval);
            _hidl_args.push_back((void *)&_hidl_out_minLevel);
            _hidl_args.push_back((void *)&_hidl_out_maxLevel);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.audio.effect", "5.0", "IEqualizerEffect", "getLevelRange", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("getLevelRange: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwEqualizerEffect::_hidl_setBandLevel(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwEqualizerEffect::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint16_t band;
    int16_t level;

    _hidl_err = _hidl_data.readUint16(&band);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readInt16(&level);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IEqualizerEffect::setBandLevel::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&band);
        _hidl_args.push_back((void *)&level);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.audio.effect", "5.0", "IEqualizerEffect", "setBandLevel", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::audio::effect::V5_0::Result _hidl_out_retval = static_cast<IEqualizerEffect*>(_hidl_this->getImpl().get())->setBandLevel(band, level);

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_retval);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

_hidl_error:
    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_retval);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.audio.effect", "5.0", "IEqualizerEffect", "setBandLevel", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwEqualizerEffect::_hidl_getBandLevel(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwEqualizerEffect::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint16_t band;

    _hidl_err = _hidl_data.readUint16(&band);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IEqualizerEffect::getBandLevel::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&band);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.audio.effect", "5.0", "IEqualizerEffect", "getBandLevel", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IEqualizerEffect*>(_hidl_this->getImpl().get())->getBandLevel(band, [&](const auto &_hidl_out_retval, const auto &_hidl_out_level) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("getBandLevel: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_retval);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_err = _hidl_reply->writeInt16(_hidl_out_level);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_retval);
            _hidl_args.push_back((void *)&_hidl_out_level);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.audio.effect", "5.0", "IEqualizerEffect", "getBandLevel", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("getBandLevel: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwEqualizerEffect::_hidl_getBandCenterFrequency(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwEqualizerEffect::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint16_t band;

    _hidl_err = _hidl_data.readUint16(&band);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IEqualizerEffect::getBandCenterFrequency::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&band);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.audio.effect", "5.0", "IEqualizerEffect", "getBandCenterFrequency", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IEqualizerEffect*>(_hidl_this->getImpl().get())->getBandCenterFrequency(band, [&](const auto &_hidl_out_retval, const auto &_hidl_out_centerFreqmHz) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("getBandCenterFrequency: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_retval);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_err = _hidl_reply->writeUint32(_hidl_out_centerFreqmHz);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_retval);
            _hidl_args.push_back((void *)&_hidl_out_centerFreqmHz);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.audio.effect", "5.0", "IEqualizerEffect", "getBandCenterFrequency", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("getBandCenterFrequency: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwEqualizerEffect::_hidl_getBandFrequencyRange(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwEqualizerEffect::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint16_t band;

    _hidl_err = _hidl_data.readUint16(&band);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IEqualizerEffect::getBandFrequencyRange::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&band);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.audio.effect", "5.0", "IEqualizerEffect", "getBandFrequencyRange", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IEqualizerEffect*>(_hidl_this->getImpl().get())->getBandFrequencyRange(band, [&](const auto &_hidl_out_retval, const auto &_hidl_out_minFreqmHz, const auto &_hidl_out_maxFreqmHz) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("getBandFrequencyRange: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_retval);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_err = _hidl_reply->writeUint32(_hidl_out_minFreqmHz);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_err = _hidl_reply->writeUint32(_hidl_out_maxFreqmHz);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_retval);
            _hidl_args.push_back((void *)&_hidl_out_minFreqmHz);
            _hidl_args.push_back((void *)&_hidl_out_maxFreqmHz);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.audio.effect", "5.0", "IEqualizerEffect", "getBandFrequencyRange", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("getBandFrequencyRange: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwEqualizerEffect::_hidl_getBandForFrequency(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwEqualizerEffect::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint32_t freqmHz;

    _hidl_err = _hidl_data.readUint32(&freqmHz);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IEqualizerEffect::getBandForFrequency::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&freqmHz);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.audio.effect", "5.0", "IEqualizerEffect", "getBandForFrequency", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IEqualizerEffect*>(_hidl_this->getImpl().get())->getBandForFrequency(freqmHz, [&](const auto &_hidl_out_retval, const auto &_hidl_out_band) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("getBandForFrequency: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_retval);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_err = _hidl_reply->writeUint16(_hidl_out_band);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_retval);
            _hidl_args.push_back((void *)&_hidl_out_band);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.audio.effect", "5.0", "IEqualizerEffect", "getBandForFrequency", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("getBandForFrequency: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwEqualizerEffect::_hidl_getPresetNames(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwEqualizerEffect::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IEqualizerEffect::getPresetNames::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.audio.effect", "5.0", "IEqualizerEffect", "getPresetNames", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IEqualizerEffect*>(_hidl_this->getImpl().get())->getPresetNames([&](const auto &_hidl_out_retval, const auto &_hidl_out_names) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("getPresetNames: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_retval);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_names_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_names, sizeof(_hidl_out_names), &_hidl__hidl_out_names_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_names_child;

        _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                _hidl_out_names,
                _hidl_reply,
                _hidl__hidl_out_names_parent,
                0 /* parentOffset */, &_hidl__hidl_out_names_child);

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        for (size_t _hidl_index_0 = 0; _hidl_index_0 < _hidl_out_names.size(); ++_hidl_index_0) {
            _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                    _hidl_out_names[_hidl_index_0],
                    _hidl_reply,
                    _hidl__hidl_out_names_child,
                    _hidl_index_0 * sizeof(::android::hardware::hidl_string));

            if (_hidl_err != ::android::OK) { goto _hidl_error; }

        }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_retval);
            _hidl_args.push_back((void *)&_hidl_out_names);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.audio.effect", "5.0", "IEqualizerEffect", "getPresetNames", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("getPresetNames: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwEqualizerEffect::_hidl_setCurrentPreset(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwEqualizerEffect::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint16_t preset;

    _hidl_err = _hidl_data.readUint16(&preset);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IEqualizerEffect::setCurrentPreset::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&preset);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.audio.effect", "5.0", "IEqualizerEffect", "setCurrentPreset", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::audio::effect::V5_0::Result _hidl_out_retval = static_cast<IEqualizerEffect*>(_hidl_this->getImpl().get())->setCurrentPreset(preset);

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_retval);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

_hidl_error:
    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_retval);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.audio.effect", "5.0", "IEqualizerEffect", "setCurrentPreset", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwEqualizerEffect::_hidl_getCurrentPreset(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwEqualizerEffect::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IEqualizerEffect::getCurrentPreset::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.audio.effect", "5.0", "IEqualizerEffect", "getCurrentPreset", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IEqualizerEffect*>(_hidl_this->getImpl().get())->getCurrentPreset([&](const auto &_hidl_out_retval, const auto &_hidl_out_preset) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("getCurrentPreset: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_retval);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_err = _hidl_reply->writeUint16(_hidl_out_preset);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_retval);
            _hidl_args.push_back((void *)&_hidl_out_preset);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.audio.effect", "5.0", "IEqualizerEffect", "getCurrentPreset", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("getCurrentPreset: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwEqualizerEffect::_hidl_setAllProperties(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwEqualizerEffect::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::audio::effect::V5_0::IEqualizerEffect::AllProperties* properties;

    size_t _hidl_properties_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*properties), &_hidl_properties_parent,  const_cast<const void**>(reinterpret_cast<void **>(&properties)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::audio::effect::V5_0::IEqualizerEffect::AllProperties &>(*properties),
            _hidl_data,
            _hidl_properties_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IEqualizerEffect::setAllProperties::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)properties);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.audio.effect", "5.0", "IEqualizerEffect", "setAllProperties", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::audio::effect::V5_0::Result _hidl_out_retval = static_cast<IEqualizerEffect*>(_hidl_this->getImpl().get())->setAllProperties(*properties);

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_retval);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

_hidl_error:
    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_retval);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.audio.effect", "5.0", "IEqualizerEffect", "setAllProperties", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwEqualizerEffect::_hidl_getAllProperties(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwEqualizerEffect::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IEqualizerEffect::getAllProperties::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.audio.effect", "5.0", "IEqualizerEffect", "getAllProperties", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IEqualizerEffect*>(_hidl_this->getImpl().get())->getAllProperties([&](const auto &_hidl_out_retval, const auto &_hidl_out_properties) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("getAllProperties: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_retval);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_properties_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_properties, sizeof(_hidl_out_properties), &_hidl__hidl_out_properties_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_err = writeEmbeddedToParcel(
                _hidl_out_properties,
                _hidl_reply,
                _hidl__hidl_out_properties_parent,
                0 /* parentOffset */);

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_retval);
            _hidl_args.push_back((void *)&_hidl_out_properties);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.audio.effect", "5.0", "IEqualizerEffect", "getAllProperties", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("getAllProperties: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}


// Methods from ::android::hardware::audio::effect::V5_0::IEffect follow.

// Methods from ::android::hardware::audio::effect::V5_0::IEqualizerEffect follow.

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BnHwEqualizerEffect::ping() {
    return ::android::hardware::Void();
}
::android::hardware::Return<void> BnHwEqualizerEffect::getDebugInfo(getDebugInfo_cb _hidl_cb) {
    ::android::hidl::base::V1_0::DebugInfo info = {};
    info.pid = ::android::hardware::details::getPidIfSharable();
    info.ptr = ::android::hardware::details::debuggable()? reinterpret_cast<uint64_t>(this) : 0;
    info.arch = 
    #if defined(__LP64__)
    ::android::hidl::base::V1_0::DebugInfo::Architecture::IS_64BIT
    #else
    ::android::hidl::base::V1_0::DebugInfo::Architecture::IS_32BIT
    #endif
    ;
    _hidl_cb(info);
    return ::android::hardware::Void();
}

::android::status_t BnHwEqualizerEffect::onTransact(
        uint32_t _hidl_code,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        uint32_t _hidl_flags,
        TransactCallback _hidl_cb) {
    ::android::status_t _hidl_err = ::android::OK;

    switch (_hidl_code) {
        case 1 /* init */:
        {
            _hidl_err = ::android::hardware::audio::effect::V5_0::BnHwEffect::_hidl_init(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 2 /* setConfig */:
        {
            _hidl_err = ::android::hardware::audio::effect::V5_0::BnHwEffect::_hidl_setConfig(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 3 /* reset */:
        {
            _hidl_err = ::android::hardware::audio::effect::V5_0::BnHwEffect::_hidl_reset(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 4 /* enable */:
        {
            _hidl_err = ::android::hardware::audio::effect::V5_0::BnHwEffect::_hidl_enable(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 5 /* disable */:
        {
            _hidl_err = ::android::hardware::audio::effect::V5_0::BnHwEffect::_hidl_disable(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 6 /* setDevice */:
        {
            _hidl_err = ::android::hardware::audio::effect::V5_0::BnHwEffect::_hidl_setDevice(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 7 /* setAndGetVolume */:
        {
            _hidl_err = ::android::hardware::audio::effect::V5_0::BnHwEffect::_hidl_setAndGetVolume(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 8 /* volumeChangeNotification */:
        {
            _hidl_err = ::android::hardware::audio::effect::V5_0::BnHwEffect::_hidl_volumeChangeNotification(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 9 /* setAudioMode */:
        {
            _hidl_err = ::android::hardware::audio::effect::V5_0::BnHwEffect::_hidl_setAudioMode(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 10 /* setConfigReverse */:
        {
            _hidl_err = ::android::hardware::audio::effect::V5_0::BnHwEffect::_hidl_setConfigReverse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 11 /* setInputDevice */:
        {
            _hidl_err = ::android::hardware::audio::effect::V5_0::BnHwEffect::_hidl_setInputDevice(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 12 /* getConfig */:
        {
            _hidl_err = ::android::hardware::audio::effect::V5_0::BnHwEffect::_hidl_getConfig(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 13 /* getConfigReverse */:
        {
            _hidl_err = ::android::hardware::audio::effect::V5_0::BnHwEffect::_hidl_getConfigReverse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 14 /* getSupportedAuxChannelsConfigs */:
        {
            _hidl_err = ::android::hardware::audio::effect::V5_0::BnHwEffect::_hidl_getSupportedAuxChannelsConfigs(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 15 /* getAuxChannelsConfig */:
        {
            _hidl_err = ::android::hardware::audio::effect::V5_0::BnHwEffect::_hidl_getAuxChannelsConfig(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 16 /* setAuxChannelsConfig */:
        {
            _hidl_err = ::android::hardware::audio::effect::V5_0::BnHwEffect::_hidl_setAuxChannelsConfig(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 17 /* setAudioSource */:
        {
            _hidl_err = ::android::hardware::audio::effect::V5_0::BnHwEffect::_hidl_setAudioSource(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 18 /* offload */:
        {
            _hidl_err = ::android::hardware::audio::effect::V5_0::BnHwEffect::_hidl_offload(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 19 /* getDescriptor */:
        {
            _hidl_err = ::android::hardware::audio::effect::V5_0::BnHwEffect::_hidl_getDescriptor(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 20 /* prepareForProcessing */:
        {
            _hidl_err = ::android::hardware::audio::effect::V5_0::BnHwEffect::_hidl_prepareForProcessing(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 21 /* setProcessBuffers */:
        {
            _hidl_err = ::android::hardware::audio::effect::V5_0::BnHwEffect::_hidl_setProcessBuffers(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 22 /* command */:
        {
            _hidl_err = ::android::hardware::audio::effect::V5_0::BnHwEffect::_hidl_command(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 23 /* setParameter */:
        {
            _hidl_err = ::android::hardware::audio::effect::V5_0::BnHwEffect::_hidl_setParameter(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 24 /* getParameter */:
        {
            _hidl_err = ::android::hardware::audio::effect::V5_0::BnHwEffect::_hidl_getParameter(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 25 /* getSupportedConfigsForFeature */:
        {
            _hidl_err = ::android::hardware::audio::effect::V5_0::BnHwEffect::_hidl_getSupportedConfigsForFeature(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 26 /* getCurrentConfigForFeature */:
        {
            _hidl_err = ::android::hardware::audio::effect::V5_0::BnHwEffect::_hidl_getCurrentConfigForFeature(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 27 /* setCurrentConfigForFeature */:
        {
            _hidl_err = ::android::hardware::audio::effect::V5_0::BnHwEffect::_hidl_setCurrentConfigForFeature(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 28 /* close */:
        {
            _hidl_err = ::android::hardware::audio::effect::V5_0::BnHwEffect::_hidl_close(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 29 /* getNumBands */:
        {
            _hidl_err = ::android::hardware::audio::effect::V5_0::BnHwEqualizerEffect::_hidl_getNumBands(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 30 /* getLevelRange */:
        {
            _hidl_err = ::android::hardware::audio::effect::V5_0::BnHwEqualizerEffect::_hidl_getLevelRange(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 31 /* setBandLevel */:
        {
            _hidl_err = ::android::hardware::audio::effect::V5_0::BnHwEqualizerEffect::_hidl_setBandLevel(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 32 /* getBandLevel */:
        {
            _hidl_err = ::android::hardware::audio::effect::V5_0::BnHwEqualizerEffect::_hidl_getBandLevel(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 33 /* getBandCenterFrequency */:
        {
            _hidl_err = ::android::hardware::audio::effect::V5_0::BnHwEqualizerEffect::_hidl_getBandCenterFrequency(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 34 /* getBandFrequencyRange */:
        {
            _hidl_err = ::android::hardware::audio::effect::V5_0::BnHwEqualizerEffect::_hidl_getBandFrequencyRange(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 35 /* getBandForFrequency */:
        {
            _hidl_err = ::android::hardware::audio::effect::V5_0::BnHwEqualizerEffect::_hidl_getBandForFrequency(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 36 /* getPresetNames */:
        {
            _hidl_err = ::android::hardware::audio::effect::V5_0::BnHwEqualizerEffect::_hidl_getPresetNames(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 37 /* setCurrentPreset */:
        {
            _hidl_err = ::android::hardware::audio::effect::V5_0::BnHwEqualizerEffect::_hidl_setCurrentPreset(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 38 /* getCurrentPreset */:
        {
            _hidl_err = ::android::hardware::audio::effect::V5_0::BnHwEqualizerEffect::_hidl_getCurrentPreset(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 39 /* setAllProperties */:
        {
            _hidl_err = ::android::hardware::audio::effect::V5_0::BnHwEqualizerEffect::_hidl_setAllProperties(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 40 /* getAllProperties */:
        {
            _hidl_err = ::android::hardware::audio::effect::V5_0::BnHwEqualizerEffect::_hidl_getAllProperties(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        default:
        {
            return ::android::hidl::base::V1_0::BnHwBase::onTransact(
                    _hidl_code, _hidl_data, _hidl_reply, _hidl_flags, _hidl_cb);
        }
    }

    if (_hidl_err == ::android::UNEXPECTED_NULL) {
        _hidl_err = ::android::hardware::writeToParcel(
                ::android::hardware::Status::fromExceptionCode(::android::hardware::Status::EX_NULL_POINTER),
                _hidl_reply);
    }return _hidl_err;
}

BsEqualizerEffect::BsEqualizerEffect(const ::android::sp<::android::hardware::audio::effect::V5_0::IEqualizerEffect> impl) : ::android::hardware::details::HidlInstrumentor("android.hardware.audio.effect@5.0", "IEqualizerEffect"), mImpl(impl) {
    mOnewayQueue.start(3000 /* similar limit to binderized */);
}

::android::hardware::Return<void> BsEqualizerEffect::addOnewayTask(std::function<void(void)> fun) {
    if (!mOnewayQueue.push(fun)) {
        return ::android::hardware::Status::fromExceptionCode(
                ::android::hardware::Status::EX_TRANSACTION_FAILED,
                "Passthrough oneway function queue exceeds maximum size.");
    }
    return ::android::hardware::Status();
}

::android::sp<IEqualizerEffect> IEqualizerEffect::tryGetService(const std::string &serviceName, const bool getStub) {
    return ::android::hardware::details::getServiceInternal<BpHwEqualizerEffect>(serviceName, false, getStub);
}

::android::sp<IEqualizerEffect> IEqualizerEffect::getService(const std::string &serviceName, const bool getStub) {
    return ::android::hardware::details::getServiceInternal<BpHwEqualizerEffect>(serviceName, true, getStub);
}

::android::status_t IEqualizerEffect::registerAsService(const std::string &serviceName) {
    return ::android::hardware::details::registerAsServiceInternal(this, serviceName);
}

bool IEqualizerEffect::registerForNotifications(
        const std::string &serviceName,
        const ::android::sp<::android::hidl::manager::V1_0::IServiceNotification> &notification) {
    const ::android::sp<::android::hidl::manager::V1_0::IServiceManager> sm
            = ::android::hardware::defaultServiceManager();
    if (sm == nullptr) {
        return false;
    }
    ::android::hardware::Return<bool> success =
            sm->registerForNotifications("android.hardware.audio.effect@5.0::IEqualizerEffect",
                    serviceName, notification);
    return success.isOk() && success;
}

static_assert(sizeof(::android::hardware::MQDescriptor<char, ::android::hardware::kSynchronizedReadWrite>) == 32, "wrong size");
static_assert(sizeof(::android::hardware::hidl_handle) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_memory) == 40, "wrong size");
static_assert(sizeof(::android::hardware::hidl_string) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_vec<char>) == 16, "wrong size");

}  // namespace V5_0
}  // namespace effect
}  // namespace audio
}  // namespace hardware
}  // namespace android
