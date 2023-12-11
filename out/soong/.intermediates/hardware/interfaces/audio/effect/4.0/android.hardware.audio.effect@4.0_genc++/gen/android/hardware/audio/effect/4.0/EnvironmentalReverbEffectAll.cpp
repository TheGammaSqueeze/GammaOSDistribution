#define LOG_TAG "android.hardware.audio.effect@4.0::EnvironmentalReverbEffect"

#include <log/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <hidl/Static.h>
#include <hwbinder/ProcessState.h>
#include <utils/Trace.h>
#include <android/hidl/manager/1.0/IServiceManager.h>
#include <android/hardware/audio/effect/4.0/BpHwEnvironmentalReverbEffect.h>
#include <android/hardware/audio/effect/4.0/BnHwEnvironmentalReverbEffect.h>
#include <android/hardware/audio/effect/4.0/BsEnvironmentalReverbEffect.h>
#include <android/hardware/audio/effect/4.0/BpHwEffect.h>
#include <android/hidl/base/1.0/BpHwBase.h>
#include <hidl/ServiceManagement.h>

namespace android {
namespace hardware {
namespace audio {
namespace effect {
namespace V4_0 {

const char* IEnvironmentalReverbEffect::descriptor("android.hardware.audio.effect@4.0::IEnvironmentalReverbEffect");

__attribute__((constructor)) static void static_constructor() {
    ::android::hardware::details::getBnConstructorMap().set(IEnvironmentalReverbEffect::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hardware::IBinder> {
                return new BnHwEnvironmentalReverbEffect(static_cast<IEnvironmentalReverbEffect *>(iIntf));
            });
    ::android::hardware::details::getBsConstructorMap().set(IEnvironmentalReverbEffect::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hidl::base::V1_0::IBase> {
                return new BsEnvironmentalReverbEffect(static_cast<IEnvironmentalReverbEffect *>(iIntf));
            });
}

__attribute__((destructor))static void static_destructor() {
    ::android::hardware::details::getBnConstructorMap().erase(IEnvironmentalReverbEffect::descriptor);
    ::android::hardware::details::getBsConstructorMap().erase(IEnvironmentalReverbEffect::descriptor);
}

// Methods from ::android::hardware::audio::effect::V4_0::IEffect follow.
// no default implementation for: ::android::hardware::Return<::android::hardware::audio::effect::V4_0::Result> IEnvironmentalReverbEffect::init()
// no default implementation for: ::android::hardware::Return<::android::hardware::audio::effect::V4_0::Result> IEnvironmentalReverbEffect::setConfig(const ::android::hardware::audio::effect::V4_0::EffectConfig& config, const ::android::sp<::android::hardware::audio::effect::V4_0::IEffectBufferProviderCallback>& inputBufferProvider, const ::android::sp<::android::hardware::audio::effect::V4_0::IEffectBufferProviderCallback>& outputBufferProvider)
// no default implementation for: ::android::hardware::Return<::android::hardware::audio::effect::V4_0::Result> IEnvironmentalReverbEffect::reset()
// no default implementation for: ::android::hardware::Return<::android::hardware::audio::effect::V4_0::Result> IEnvironmentalReverbEffect::enable()
// no default implementation for: ::android::hardware::Return<::android::hardware::audio::effect::V4_0::Result> IEnvironmentalReverbEffect::disable()
// no default implementation for: ::android::hardware::Return<::android::hardware::audio::effect::V4_0::Result> IEnvironmentalReverbEffect::setDevice(::android::hardware::hidl_bitfield<::android::hardware::audio::common::V4_0::AudioDevice> device)
// no default implementation for: ::android::hardware::Return<void> IEnvironmentalReverbEffect::setAndGetVolume(const ::android::hardware::hidl_vec<uint32_t>& volumes, setAndGetVolume_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<::android::hardware::audio::effect::V4_0::Result> IEnvironmentalReverbEffect::volumeChangeNotification(const ::android::hardware::hidl_vec<uint32_t>& volumes)
// no default implementation for: ::android::hardware::Return<::android::hardware::audio::effect::V4_0::Result> IEnvironmentalReverbEffect::setAudioMode(::android::hardware::audio::common::V4_0::AudioMode mode)
// no default implementation for: ::android::hardware::Return<::android::hardware::audio::effect::V4_0::Result> IEnvironmentalReverbEffect::setConfigReverse(const ::android::hardware::audio::effect::V4_0::EffectConfig& config, const ::android::sp<::android::hardware::audio::effect::V4_0::IEffectBufferProviderCallback>& inputBufferProvider, const ::android::sp<::android::hardware::audio::effect::V4_0::IEffectBufferProviderCallback>& outputBufferProvider)
// no default implementation for: ::android::hardware::Return<::android::hardware::audio::effect::V4_0::Result> IEnvironmentalReverbEffect::setInputDevice(::android::hardware::hidl_bitfield<::android::hardware::audio::common::V4_0::AudioDevice> device)
// no default implementation for: ::android::hardware::Return<void> IEnvironmentalReverbEffect::getConfig(getConfig_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IEnvironmentalReverbEffect::getConfigReverse(getConfigReverse_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IEnvironmentalReverbEffect::getSupportedAuxChannelsConfigs(uint32_t maxConfigs, getSupportedAuxChannelsConfigs_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IEnvironmentalReverbEffect::getAuxChannelsConfig(getAuxChannelsConfig_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<::android::hardware::audio::effect::V4_0::Result> IEnvironmentalReverbEffect::setAuxChannelsConfig(const ::android::hardware::audio::effect::V4_0::EffectAuxChannelsConfig& config)
// no default implementation for: ::android::hardware::Return<::android::hardware::audio::effect::V4_0::Result> IEnvironmentalReverbEffect::setAudioSource(::android::hardware::audio::common::V4_0::AudioSource source)
// no default implementation for: ::android::hardware::Return<::android::hardware::audio::effect::V4_0::Result> IEnvironmentalReverbEffect::offload(const ::android::hardware::audio::effect::V4_0::EffectOffloadParameter& param)
// no default implementation for: ::android::hardware::Return<void> IEnvironmentalReverbEffect::getDescriptor(getDescriptor_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IEnvironmentalReverbEffect::prepareForProcessing(prepareForProcessing_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<::android::hardware::audio::effect::V4_0::Result> IEnvironmentalReverbEffect::setProcessBuffers(const ::android::hardware::audio::effect::V4_0::AudioBuffer& inBuffer, const ::android::hardware::audio::effect::V4_0::AudioBuffer& outBuffer)
// no default implementation for: ::android::hardware::Return<void> IEnvironmentalReverbEffect::command(uint32_t commandId, const ::android::hardware::hidl_vec<uint8_t>& data, uint32_t resultMaxSize, command_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<::android::hardware::audio::effect::V4_0::Result> IEnvironmentalReverbEffect::setParameter(const ::android::hardware::hidl_vec<uint8_t>& parameter, const ::android::hardware::hidl_vec<uint8_t>& value)
// no default implementation for: ::android::hardware::Return<void> IEnvironmentalReverbEffect::getParameter(const ::android::hardware::hidl_vec<uint8_t>& parameter, uint32_t valueMaxSize, getParameter_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IEnvironmentalReverbEffect::getSupportedConfigsForFeature(uint32_t featureId, uint32_t maxConfigs, uint32_t configSize, getSupportedConfigsForFeature_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IEnvironmentalReverbEffect::getCurrentConfigForFeature(uint32_t featureId, uint32_t configSize, getCurrentConfigForFeature_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<::android::hardware::audio::effect::V4_0::Result> IEnvironmentalReverbEffect::setCurrentConfigForFeature(uint32_t featureId, const ::android::hardware::hidl_vec<uint8_t>& configData)
// no default implementation for: ::android::hardware::Return<::android::hardware::audio::effect::V4_0::Result> IEnvironmentalReverbEffect::close()

// Methods from ::android::hardware::audio::effect::V4_0::IEnvironmentalReverbEffect follow.
// no default implementation for: ::android::hardware::Return<::android::hardware::audio::effect::V4_0::Result> IEnvironmentalReverbEffect::setBypass(bool bypass)
// no default implementation for: ::android::hardware::Return<void> IEnvironmentalReverbEffect::getBypass(getBypass_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<::android::hardware::audio::effect::V4_0::Result> IEnvironmentalReverbEffect::setRoomLevel(int16_t roomLevel)
// no default implementation for: ::android::hardware::Return<void> IEnvironmentalReverbEffect::getRoomLevel(getRoomLevel_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<::android::hardware::audio::effect::V4_0::Result> IEnvironmentalReverbEffect::setRoomHfLevel(int16_t roomHfLevel)
// no default implementation for: ::android::hardware::Return<void> IEnvironmentalReverbEffect::getRoomHfLevel(getRoomHfLevel_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<::android::hardware::audio::effect::V4_0::Result> IEnvironmentalReverbEffect::setDecayTime(uint32_t decayTime)
// no default implementation for: ::android::hardware::Return<void> IEnvironmentalReverbEffect::getDecayTime(getDecayTime_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<::android::hardware::audio::effect::V4_0::Result> IEnvironmentalReverbEffect::setDecayHfRatio(int16_t decayHfRatio)
// no default implementation for: ::android::hardware::Return<void> IEnvironmentalReverbEffect::getDecayHfRatio(getDecayHfRatio_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<::android::hardware::audio::effect::V4_0::Result> IEnvironmentalReverbEffect::setReflectionsLevel(int16_t reflectionsLevel)
// no default implementation for: ::android::hardware::Return<void> IEnvironmentalReverbEffect::getReflectionsLevel(getReflectionsLevel_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<::android::hardware::audio::effect::V4_0::Result> IEnvironmentalReverbEffect::setReflectionsDelay(uint32_t reflectionsDelay)
// no default implementation for: ::android::hardware::Return<void> IEnvironmentalReverbEffect::getReflectionsDelay(getReflectionsDelay_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<::android::hardware::audio::effect::V4_0::Result> IEnvironmentalReverbEffect::setReverbLevel(int16_t reverbLevel)
// no default implementation for: ::android::hardware::Return<void> IEnvironmentalReverbEffect::getReverbLevel(getReverbLevel_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<::android::hardware::audio::effect::V4_0::Result> IEnvironmentalReverbEffect::setReverbDelay(uint32_t reverDelay)
// no default implementation for: ::android::hardware::Return<void> IEnvironmentalReverbEffect::getReverbDelay(getReverbDelay_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<::android::hardware::audio::effect::V4_0::Result> IEnvironmentalReverbEffect::setDiffusion(int16_t diffusion)
// no default implementation for: ::android::hardware::Return<void> IEnvironmentalReverbEffect::getDiffusion(getDiffusion_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<::android::hardware::audio::effect::V4_0::Result> IEnvironmentalReverbEffect::setDensity(int16_t density)
// no default implementation for: ::android::hardware::Return<void> IEnvironmentalReverbEffect::getDensity(getDensity_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<::android::hardware::audio::effect::V4_0::Result> IEnvironmentalReverbEffect::setAllProperties(const ::android::hardware::audio::effect::V4_0::IEnvironmentalReverbEffect::AllProperties& properties)
// no default implementation for: ::android::hardware::Return<void> IEnvironmentalReverbEffect::getAllProperties(getAllProperties_cb _hidl_cb)

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> IEnvironmentalReverbEffect::interfaceChain(interfaceChain_cb _hidl_cb){
    _hidl_cb({
        ::android::hardware::audio::effect::V4_0::IEnvironmentalReverbEffect::descriptor,
        ::android::hardware::audio::effect::V4_0::IEffect::descriptor,
        ::android::hidl::base::V1_0::IBase::descriptor,
    });
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IEnvironmentalReverbEffect::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    (void)fd;
    (void)options;
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IEnvironmentalReverbEffect::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    _hidl_cb(::android::hardware::audio::effect::V4_0::IEnvironmentalReverbEffect::descriptor);
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IEnvironmentalReverbEffect::getHashChain(getHashChain_cb _hidl_cb){
    _hidl_cb({
        (uint8_t[32]){131,153,128,199,197,190,121,218,107,149,253,185,53,74,98,176,68,7,180,176,132,116,155,122,33,210,195,64,119,61,118,56} /* 839980c7c5be79da6b95fdb9354a62b04407b4b084749b7a21d2c340773d7638 */,
        (uint8_t[32]){186,200,27,255,190,38,97,213,182,131,144,135,210,221,58,39,237,237,102,230,12,108,118,211,92,104,213,64,20,205,92,6} /* bac81bffbe2661d5b6839087d2dd3a27eded66e60c6c76d35c68d54014cd5c06 */,
        (uint8_t[32]){236,127,215,158,208,45,250,133,188,73,148,38,173,174,62,190,35,239,5,36,243,205,105,87,19,147,36,184,59,24,202,76} /* ec7fd79ed02dfa85bc499426adae3ebe23ef0524f3cd6957139324b83b18ca4c */});
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IEnvironmentalReverbEffect::setHALInstrumentation(){
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> IEnvironmentalReverbEffect::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    (void)cookie;
    return (recipient != nullptr);
}

::android::hardware::Return<void> IEnvironmentalReverbEffect::ping(){
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IEnvironmentalReverbEffect::getDebugInfo(getDebugInfo_cb _hidl_cb){
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

::android::hardware::Return<void> IEnvironmentalReverbEffect::notifySyspropsChanged(){
    ::android::report_sysprop_change();
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> IEnvironmentalReverbEffect::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
    return (recipient != nullptr);
}


::android::hardware::Return<::android::sp<::android::hardware::audio::effect::V4_0::IEnvironmentalReverbEffect>> IEnvironmentalReverbEffect::castFrom(const ::android::sp<::android::hardware::audio::effect::V4_0::IEnvironmentalReverbEffect>& parent, bool /* emitError */) {
    return parent;
}

::android::hardware::Return<::android::sp<::android::hardware::audio::effect::V4_0::IEnvironmentalReverbEffect>> IEnvironmentalReverbEffect::castFrom(const ::android::sp<::android::hardware::audio::effect::V4_0::IEffect>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<IEnvironmentalReverbEffect, ::android::hardware::audio::effect::V4_0::IEffect, BpHwEnvironmentalReverbEffect>(
            parent, "android.hardware.audio.effect@4.0::IEnvironmentalReverbEffect", emitError);
}

::android::hardware::Return<::android::sp<::android::hardware::audio::effect::V4_0::IEnvironmentalReverbEffect>> IEnvironmentalReverbEffect::castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<IEnvironmentalReverbEffect, ::android::hidl::base::V1_0::IBase, BpHwEnvironmentalReverbEffect>(
            parent, "android.hardware.audio.effect@4.0::IEnvironmentalReverbEffect", emitError);
}

BpHwEnvironmentalReverbEffect::BpHwEnvironmentalReverbEffect(const ::android::sp<::android::hardware::IBinder> &_hidl_impl)
        : BpInterface<IEnvironmentalReverbEffect>(_hidl_impl),
          ::android::hardware::details::HidlInstrumentor("android.hardware.audio.effect@4.0", "IEnvironmentalReverbEffect") {
}

void BpHwEnvironmentalReverbEffect::onLastStrongRef(const void* id) {
    {
        std::unique_lock<std::mutex> lock(_hidl_mMutex);
        _hidl_mDeathRecipients.clear();
    }

    BpInterface<IEnvironmentalReverbEffect>::onLastStrongRef(id);
}
// Methods from ::android::hardware::audio::effect::V4_0::IEnvironmentalReverbEffect follow.
::android::hardware::Return<::android::hardware::audio::effect::V4_0::Result> BpHwEnvironmentalReverbEffect::_hidl_setBypass(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, bool bypass) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IEnvironmentalReverbEffect::setBypass::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&bypass);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.audio.effect", "4.0", "IEnvironmentalReverbEffect", "setBypass", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    ::android::hardware::audio::effect::V4_0::Result _hidl_out_retval;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwEnvironmentalReverbEffect::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeBool(bypass);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(29 /* setBypass */, _hidl_data, &_hidl_reply, 0 /* flags */);
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
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.audio.effect", "4.0", "IEnvironmentalReverbEffect", "setBypass", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<::android::hardware::audio::effect::V4_0::Result>(_hidl_out_retval);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<::android::hardware::audio::effect::V4_0::Result>(_hidl_status);
}

::android::hardware::Return<void> BpHwEnvironmentalReverbEffect::_hidl_getBypass(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, getBypass_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IEnvironmentalReverbEffect::getBypass::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.audio.effect", "4.0", "IEnvironmentalReverbEffect", "getBypass", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwEnvironmentalReverbEffect::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(30 /* getBypass */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::audio::effect::V4_0::Result _hidl_out_retval;
        bool _hidl_out_bypass;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_retval);
        if (_hidl_err != ::android::OK) { return; }

        _hidl_err = _hidl_reply.readBool(&_hidl_out_bypass);
        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(_hidl_out_retval, _hidl_out_bypass);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_retval);
            _hidl_args.push_back((void *)&_hidl_out_bypass);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.audio.effect", "4.0", "IEnvironmentalReverbEffect", "getBypass", &_hidl_args);
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

::android::hardware::Return<::android::hardware::audio::effect::V4_0::Result> BpHwEnvironmentalReverbEffect::_hidl_setRoomLevel(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, int16_t roomLevel) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IEnvironmentalReverbEffect::setRoomLevel::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&roomLevel);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.audio.effect", "4.0", "IEnvironmentalReverbEffect", "setRoomLevel", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    ::android::hardware::audio::effect::V4_0::Result _hidl_out_retval;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwEnvironmentalReverbEffect::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt16(roomLevel);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(31 /* setRoomLevel */, _hidl_data, &_hidl_reply, 0 /* flags */);
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
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.audio.effect", "4.0", "IEnvironmentalReverbEffect", "setRoomLevel", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<::android::hardware::audio::effect::V4_0::Result>(_hidl_out_retval);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<::android::hardware::audio::effect::V4_0::Result>(_hidl_status);
}

::android::hardware::Return<void> BpHwEnvironmentalReverbEffect::_hidl_getRoomLevel(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, getRoomLevel_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IEnvironmentalReverbEffect::getRoomLevel::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.audio.effect", "4.0", "IEnvironmentalReverbEffect", "getRoomLevel", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwEnvironmentalReverbEffect::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(32 /* getRoomLevel */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::audio::effect::V4_0::Result _hidl_out_retval;
        int16_t _hidl_out_roomLevel;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_retval);
        if (_hidl_err != ::android::OK) { return; }

        _hidl_err = _hidl_reply.readInt16(&_hidl_out_roomLevel);
        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(_hidl_out_retval, _hidl_out_roomLevel);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_retval);
            _hidl_args.push_back((void *)&_hidl_out_roomLevel);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.audio.effect", "4.0", "IEnvironmentalReverbEffect", "getRoomLevel", &_hidl_args);
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

::android::hardware::Return<::android::hardware::audio::effect::V4_0::Result> BpHwEnvironmentalReverbEffect::_hidl_setRoomHfLevel(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, int16_t roomHfLevel) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IEnvironmentalReverbEffect::setRoomHfLevel::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&roomHfLevel);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.audio.effect", "4.0", "IEnvironmentalReverbEffect", "setRoomHfLevel", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    ::android::hardware::audio::effect::V4_0::Result _hidl_out_retval;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwEnvironmentalReverbEffect::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt16(roomHfLevel);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(33 /* setRoomHfLevel */, _hidl_data, &_hidl_reply, 0 /* flags */);
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
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.audio.effect", "4.0", "IEnvironmentalReverbEffect", "setRoomHfLevel", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<::android::hardware::audio::effect::V4_0::Result>(_hidl_out_retval);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<::android::hardware::audio::effect::V4_0::Result>(_hidl_status);
}

::android::hardware::Return<void> BpHwEnvironmentalReverbEffect::_hidl_getRoomHfLevel(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, getRoomHfLevel_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IEnvironmentalReverbEffect::getRoomHfLevel::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.audio.effect", "4.0", "IEnvironmentalReverbEffect", "getRoomHfLevel", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwEnvironmentalReverbEffect::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(34 /* getRoomHfLevel */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::audio::effect::V4_0::Result _hidl_out_retval;
        int16_t _hidl_out_roomHfLevel;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_retval);
        if (_hidl_err != ::android::OK) { return; }

        _hidl_err = _hidl_reply.readInt16(&_hidl_out_roomHfLevel);
        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(_hidl_out_retval, _hidl_out_roomHfLevel);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_retval);
            _hidl_args.push_back((void *)&_hidl_out_roomHfLevel);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.audio.effect", "4.0", "IEnvironmentalReverbEffect", "getRoomHfLevel", &_hidl_args);
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

::android::hardware::Return<::android::hardware::audio::effect::V4_0::Result> BpHwEnvironmentalReverbEffect::_hidl_setDecayTime(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint32_t decayTime) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IEnvironmentalReverbEffect::setDecayTime::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&decayTime);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.audio.effect", "4.0", "IEnvironmentalReverbEffect", "setDecayTime", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    ::android::hardware::audio::effect::V4_0::Result _hidl_out_retval;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwEnvironmentalReverbEffect::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(decayTime);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(35 /* setDecayTime */, _hidl_data, &_hidl_reply, 0 /* flags */);
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
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.audio.effect", "4.0", "IEnvironmentalReverbEffect", "setDecayTime", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<::android::hardware::audio::effect::V4_0::Result>(_hidl_out_retval);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<::android::hardware::audio::effect::V4_0::Result>(_hidl_status);
}

::android::hardware::Return<void> BpHwEnvironmentalReverbEffect::_hidl_getDecayTime(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, getDecayTime_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IEnvironmentalReverbEffect::getDecayTime::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.audio.effect", "4.0", "IEnvironmentalReverbEffect", "getDecayTime", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwEnvironmentalReverbEffect::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(36 /* getDecayTime */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::audio::effect::V4_0::Result _hidl_out_retval;
        uint32_t _hidl_out_decayTime;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_retval);
        if (_hidl_err != ::android::OK) { return; }

        _hidl_err = _hidl_reply.readUint32(&_hidl_out_decayTime);
        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(_hidl_out_retval, _hidl_out_decayTime);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_retval);
            _hidl_args.push_back((void *)&_hidl_out_decayTime);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.audio.effect", "4.0", "IEnvironmentalReverbEffect", "getDecayTime", &_hidl_args);
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

::android::hardware::Return<::android::hardware::audio::effect::V4_0::Result> BpHwEnvironmentalReverbEffect::_hidl_setDecayHfRatio(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, int16_t decayHfRatio) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IEnvironmentalReverbEffect::setDecayHfRatio::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&decayHfRatio);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.audio.effect", "4.0", "IEnvironmentalReverbEffect", "setDecayHfRatio", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    ::android::hardware::audio::effect::V4_0::Result _hidl_out_retval;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwEnvironmentalReverbEffect::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt16(decayHfRatio);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(37 /* setDecayHfRatio */, _hidl_data, &_hidl_reply, 0 /* flags */);
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
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.audio.effect", "4.0", "IEnvironmentalReverbEffect", "setDecayHfRatio", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<::android::hardware::audio::effect::V4_0::Result>(_hidl_out_retval);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<::android::hardware::audio::effect::V4_0::Result>(_hidl_status);
}

::android::hardware::Return<void> BpHwEnvironmentalReverbEffect::_hidl_getDecayHfRatio(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, getDecayHfRatio_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IEnvironmentalReverbEffect::getDecayHfRatio::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.audio.effect", "4.0", "IEnvironmentalReverbEffect", "getDecayHfRatio", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwEnvironmentalReverbEffect::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(38 /* getDecayHfRatio */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::audio::effect::V4_0::Result _hidl_out_retval;
        int16_t _hidl_out_decayHfRatio;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_retval);
        if (_hidl_err != ::android::OK) { return; }

        _hidl_err = _hidl_reply.readInt16(&_hidl_out_decayHfRatio);
        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(_hidl_out_retval, _hidl_out_decayHfRatio);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_retval);
            _hidl_args.push_back((void *)&_hidl_out_decayHfRatio);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.audio.effect", "4.0", "IEnvironmentalReverbEffect", "getDecayHfRatio", &_hidl_args);
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

::android::hardware::Return<::android::hardware::audio::effect::V4_0::Result> BpHwEnvironmentalReverbEffect::_hidl_setReflectionsLevel(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, int16_t reflectionsLevel) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IEnvironmentalReverbEffect::setReflectionsLevel::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&reflectionsLevel);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.audio.effect", "4.0", "IEnvironmentalReverbEffect", "setReflectionsLevel", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    ::android::hardware::audio::effect::V4_0::Result _hidl_out_retval;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwEnvironmentalReverbEffect::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt16(reflectionsLevel);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(39 /* setReflectionsLevel */, _hidl_data, &_hidl_reply, 0 /* flags */);
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
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.audio.effect", "4.0", "IEnvironmentalReverbEffect", "setReflectionsLevel", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<::android::hardware::audio::effect::V4_0::Result>(_hidl_out_retval);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<::android::hardware::audio::effect::V4_0::Result>(_hidl_status);
}

::android::hardware::Return<void> BpHwEnvironmentalReverbEffect::_hidl_getReflectionsLevel(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, getReflectionsLevel_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IEnvironmentalReverbEffect::getReflectionsLevel::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.audio.effect", "4.0", "IEnvironmentalReverbEffect", "getReflectionsLevel", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwEnvironmentalReverbEffect::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(40 /* getReflectionsLevel */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::audio::effect::V4_0::Result _hidl_out_retval;
        int16_t _hidl_out_reflectionsLevel;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_retval);
        if (_hidl_err != ::android::OK) { return; }

        _hidl_err = _hidl_reply.readInt16(&_hidl_out_reflectionsLevel);
        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(_hidl_out_retval, _hidl_out_reflectionsLevel);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_retval);
            _hidl_args.push_back((void *)&_hidl_out_reflectionsLevel);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.audio.effect", "4.0", "IEnvironmentalReverbEffect", "getReflectionsLevel", &_hidl_args);
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

::android::hardware::Return<::android::hardware::audio::effect::V4_0::Result> BpHwEnvironmentalReverbEffect::_hidl_setReflectionsDelay(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint32_t reflectionsDelay) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IEnvironmentalReverbEffect::setReflectionsDelay::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&reflectionsDelay);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.audio.effect", "4.0", "IEnvironmentalReverbEffect", "setReflectionsDelay", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    ::android::hardware::audio::effect::V4_0::Result _hidl_out_retval;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwEnvironmentalReverbEffect::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(reflectionsDelay);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(41 /* setReflectionsDelay */, _hidl_data, &_hidl_reply, 0 /* flags */);
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
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.audio.effect", "4.0", "IEnvironmentalReverbEffect", "setReflectionsDelay", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<::android::hardware::audio::effect::V4_0::Result>(_hidl_out_retval);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<::android::hardware::audio::effect::V4_0::Result>(_hidl_status);
}

::android::hardware::Return<void> BpHwEnvironmentalReverbEffect::_hidl_getReflectionsDelay(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, getReflectionsDelay_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IEnvironmentalReverbEffect::getReflectionsDelay::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.audio.effect", "4.0", "IEnvironmentalReverbEffect", "getReflectionsDelay", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwEnvironmentalReverbEffect::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(42 /* getReflectionsDelay */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::audio::effect::V4_0::Result _hidl_out_retval;
        uint32_t _hidl_out_reflectionsDelay;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_retval);
        if (_hidl_err != ::android::OK) { return; }

        _hidl_err = _hidl_reply.readUint32(&_hidl_out_reflectionsDelay);
        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(_hidl_out_retval, _hidl_out_reflectionsDelay);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_retval);
            _hidl_args.push_back((void *)&_hidl_out_reflectionsDelay);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.audio.effect", "4.0", "IEnvironmentalReverbEffect", "getReflectionsDelay", &_hidl_args);
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

::android::hardware::Return<::android::hardware::audio::effect::V4_0::Result> BpHwEnvironmentalReverbEffect::_hidl_setReverbLevel(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, int16_t reverbLevel) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IEnvironmentalReverbEffect::setReverbLevel::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&reverbLevel);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.audio.effect", "4.0", "IEnvironmentalReverbEffect", "setReverbLevel", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    ::android::hardware::audio::effect::V4_0::Result _hidl_out_retval;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwEnvironmentalReverbEffect::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt16(reverbLevel);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(43 /* setReverbLevel */, _hidl_data, &_hidl_reply, 0 /* flags */);
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
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.audio.effect", "4.0", "IEnvironmentalReverbEffect", "setReverbLevel", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<::android::hardware::audio::effect::V4_0::Result>(_hidl_out_retval);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<::android::hardware::audio::effect::V4_0::Result>(_hidl_status);
}

::android::hardware::Return<void> BpHwEnvironmentalReverbEffect::_hidl_getReverbLevel(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, getReverbLevel_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IEnvironmentalReverbEffect::getReverbLevel::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.audio.effect", "4.0", "IEnvironmentalReverbEffect", "getReverbLevel", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwEnvironmentalReverbEffect::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(44 /* getReverbLevel */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::audio::effect::V4_0::Result _hidl_out_retval;
        int16_t _hidl_out_reverbLevel;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_retval);
        if (_hidl_err != ::android::OK) { return; }

        _hidl_err = _hidl_reply.readInt16(&_hidl_out_reverbLevel);
        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(_hidl_out_retval, _hidl_out_reverbLevel);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_retval);
            _hidl_args.push_back((void *)&_hidl_out_reverbLevel);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.audio.effect", "4.0", "IEnvironmentalReverbEffect", "getReverbLevel", &_hidl_args);
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

::android::hardware::Return<::android::hardware::audio::effect::V4_0::Result> BpHwEnvironmentalReverbEffect::_hidl_setReverbDelay(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint32_t reverDelay) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IEnvironmentalReverbEffect::setReverbDelay::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&reverDelay);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.audio.effect", "4.0", "IEnvironmentalReverbEffect", "setReverbDelay", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    ::android::hardware::audio::effect::V4_0::Result _hidl_out_retval;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwEnvironmentalReverbEffect::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(reverDelay);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(45 /* setReverbDelay */, _hidl_data, &_hidl_reply, 0 /* flags */);
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
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.audio.effect", "4.0", "IEnvironmentalReverbEffect", "setReverbDelay", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<::android::hardware::audio::effect::V4_0::Result>(_hidl_out_retval);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<::android::hardware::audio::effect::V4_0::Result>(_hidl_status);
}

::android::hardware::Return<void> BpHwEnvironmentalReverbEffect::_hidl_getReverbDelay(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, getReverbDelay_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IEnvironmentalReverbEffect::getReverbDelay::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.audio.effect", "4.0", "IEnvironmentalReverbEffect", "getReverbDelay", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwEnvironmentalReverbEffect::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(46 /* getReverbDelay */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::audio::effect::V4_0::Result _hidl_out_retval;
        uint32_t _hidl_out_reverbDelay;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_retval);
        if (_hidl_err != ::android::OK) { return; }

        _hidl_err = _hidl_reply.readUint32(&_hidl_out_reverbDelay);
        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(_hidl_out_retval, _hidl_out_reverbDelay);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_retval);
            _hidl_args.push_back((void *)&_hidl_out_reverbDelay);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.audio.effect", "4.0", "IEnvironmentalReverbEffect", "getReverbDelay", &_hidl_args);
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

::android::hardware::Return<::android::hardware::audio::effect::V4_0::Result> BpHwEnvironmentalReverbEffect::_hidl_setDiffusion(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, int16_t diffusion) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IEnvironmentalReverbEffect::setDiffusion::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&diffusion);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.audio.effect", "4.0", "IEnvironmentalReverbEffect", "setDiffusion", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    ::android::hardware::audio::effect::V4_0::Result _hidl_out_retval;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwEnvironmentalReverbEffect::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt16(diffusion);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(47 /* setDiffusion */, _hidl_data, &_hidl_reply, 0 /* flags */);
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
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.audio.effect", "4.0", "IEnvironmentalReverbEffect", "setDiffusion", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<::android::hardware::audio::effect::V4_0::Result>(_hidl_out_retval);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<::android::hardware::audio::effect::V4_0::Result>(_hidl_status);
}

::android::hardware::Return<void> BpHwEnvironmentalReverbEffect::_hidl_getDiffusion(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, getDiffusion_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IEnvironmentalReverbEffect::getDiffusion::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.audio.effect", "4.0", "IEnvironmentalReverbEffect", "getDiffusion", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwEnvironmentalReverbEffect::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(48 /* getDiffusion */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::audio::effect::V4_0::Result _hidl_out_retval;
        int16_t _hidl_out_diffusion;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_retval);
        if (_hidl_err != ::android::OK) { return; }

        _hidl_err = _hidl_reply.readInt16(&_hidl_out_diffusion);
        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(_hidl_out_retval, _hidl_out_diffusion);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_retval);
            _hidl_args.push_back((void *)&_hidl_out_diffusion);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.audio.effect", "4.0", "IEnvironmentalReverbEffect", "getDiffusion", &_hidl_args);
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

::android::hardware::Return<::android::hardware::audio::effect::V4_0::Result> BpHwEnvironmentalReverbEffect::_hidl_setDensity(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, int16_t density) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IEnvironmentalReverbEffect::setDensity::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&density);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.audio.effect", "4.0", "IEnvironmentalReverbEffect", "setDensity", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    ::android::hardware::audio::effect::V4_0::Result _hidl_out_retval;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwEnvironmentalReverbEffect::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt16(density);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(49 /* setDensity */, _hidl_data, &_hidl_reply, 0 /* flags */);
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
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.audio.effect", "4.0", "IEnvironmentalReverbEffect", "setDensity", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<::android::hardware::audio::effect::V4_0::Result>(_hidl_out_retval);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<::android::hardware::audio::effect::V4_0::Result>(_hidl_status);
}

::android::hardware::Return<void> BpHwEnvironmentalReverbEffect::_hidl_getDensity(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, getDensity_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IEnvironmentalReverbEffect::getDensity::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.audio.effect", "4.0", "IEnvironmentalReverbEffect", "getDensity", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwEnvironmentalReverbEffect::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(50 /* getDensity */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::audio::effect::V4_0::Result _hidl_out_retval;
        int16_t _hidl_out_density;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_retval);
        if (_hidl_err != ::android::OK) { return; }

        _hidl_err = _hidl_reply.readInt16(&_hidl_out_density);
        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(_hidl_out_retval, _hidl_out_density);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_retval);
            _hidl_args.push_back((void *)&_hidl_out_density);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.audio.effect", "4.0", "IEnvironmentalReverbEffect", "getDensity", &_hidl_args);
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

::android::hardware::Return<::android::hardware::audio::effect::V4_0::Result> BpHwEnvironmentalReverbEffect::_hidl_setAllProperties(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::audio::effect::V4_0::IEnvironmentalReverbEffect::AllProperties& properties) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IEnvironmentalReverbEffect::setAllProperties::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&properties);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.audio.effect", "4.0", "IEnvironmentalReverbEffect", "setAllProperties", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    ::android::hardware::audio::effect::V4_0::Result _hidl_out_retval;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwEnvironmentalReverbEffect::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_properties_parent;

    _hidl_err = _hidl_data.writeBuffer(&properties, sizeof(properties), &_hidl_properties_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(51 /* setAllProperties */, _hidl_data, &_hidl_reply, 0 /* flags */);
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
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.audio.effect", "4.0", "IEnvironmentalReverbEffect", "setAllProperties", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<::android::hardware::audio::effect::V4_0::Result>(_hidl_out_retval);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<::android::hardware::audio::effect::V4_0::Result>(_hidl_status);
}

::android::hardware::Return<void> BpHwEnvironmentalReverbEffect::_hidl_getAllProperties(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, getAllProperties_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IEnvironmentalReverbEffect::getAllProperties::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.audio.effect", "4.0", "IEnvironmentalReverbEffect", "getAllProperties", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwEnvironmentalReverbEffect::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(52 /* getAllProperties */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::audio::effect::V4_0::Result _hidl_out_retval;
        ::android::hardware::audio::effect::V4_0::IEnvironmentalReverbEffect::AllProperties* _hidl_out_properties;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_retval);
        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_properties_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_properties), &_hidl__hidl_out_properties_parent,  const_cast<const void**>(reinterpret_cast<void **>(&_hidl_out_properties)));
        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(_hidl_out_retval, *_hidl_out_properties);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_retval);
            _hidl_args.push_back((void *)_hidl_out_properties);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.audio.effect", "4.0", "IEnvironmentalReverbEffect", "getAllProperties", &_hidl_args);
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


// Methods from ::android::hardware::audio::effect::V4_0::IEffect follow.
::android::hardware::Return<::android::hardware::audio::effect::V4_0::Result> BpHwEnvironmentalReverbEffect::init(){
    ::android::hardware::Return<::android::hardware::audio::effect::V4_0::Result>  _hidl_out = ::android::hardware::audio::effect::V4_0::BpHwEffect::_hidl_init(this, this);

    return _hidl_out;
}

::android::hardware::Return<::android::hardware::audio::effect::V4_0::Result> BpHwEnvironmentalReverbEffect::setConfig(const ::android::hardware::audio::effect::V4_0::EffectConfig& config, const ::android::sp<::android::hardware::audio::effect::V4_0::IEffectBufferProviderCallback>& inputBufferProvider, const ::android::sp<::android::hardware::audio::effect::V4_0::IEffectBufferProviderCallback>& outputBufferProvider){
    ::android::hardware::Return<::android::hardware::audio::effect::V4_0::Result>  _hidl_out = ::android::hardware::audio::effect::V4_0::BpHwEffect::_hidl_setConfig(this, this, config, inputBufferProvider, outputBufferProvider);

    return _hidl_out;
}

::android::hardware::Return<::android::hardware::audio::effect::V4_0::Result> BpHwEnvironmentalReverbEffect::reset(){
    ::android::hardware::Return<::android::hardware::audio::effect::V4_0::Result>  _hidl_out = ::android::hardware::audio::effect::V4_0::BpHwEffect::_hidl_reset(this, this);

    return _hidl_out;
}

::android::hardware::Return<::android::hardware::audio::effect::V4_0::Result> BpHwEnvironmentalReverbEffect::enable(){
    ::android::hardware::Return<::android::hardware::audio::effect::V4_0::Result>  _hidl_out = ::android::hardware::audio::effect::V4_0::BpHwEffect::_hidl_enable(this, this);

    return _hidl_out;
}

::android::hardware::Return<::android::hardware::audio::effect::V4_0::Result> BpHwEnvironmentalReverbEffect::disable(){
    ::android::hardware::Return<::android::hardware::audio::effect::V4_0::Result>  _hidl_out = ::android::hardware::audio::effect::V4_0::BpHwEffect::_hidl_disable(this, this);

    return _hidl_out;
}

::android::hardware::Return<::android::hardware::audio::effect::V4_0::Result> BpHwEnvironmentalReverbEffect::setDevice(::android::hardware::hidl_bitfield<::android::hardware::audio::common::V4_0::AudioDevice> device){
    ::android::hardware::Return<::android::hardware::audio::effect::V4_0::Result>  _hidl_out = ::android::hardware::audio::effect::V4_0::BpHwEffect::_hidl_setDevice(this, this, device);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwEnvironmentalReverbEffect::setAndGetVolume(const ::android::hardware::hidl_vec<uint32_t>& volumes, setAndGetVolume_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::audio::effect::V4_0::BpHwEffect::_hidl_setAndGetVolume(this, this, volumes, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<::android::hardware::audio::effect::V4_0::Result> BpHwEnvironmentalReverbEffect::volumeChangeNotification(const ::android::hardware::hidl_vec<uint32_t>& volumes){
    ::android::hardware::Return<::android::hardware::audio::effect::V4_0::Result>  _hidl_out = ::android::hardware::audio::effect::V4_0::BpHwEffect::_hidl_volumeChangeNotification(this, this, volumes);

    return _hidl_out;
}

::android::hardware::Return<::android::hardware::audio::effect::V4_0::Result> BpHwEnvironmentalReverbEffect::setAudioMode(::android::hardware::audio::common::V4_0::AudioMode mode){
    ::android::hardware::Return<::android::hardware::audio::effect::V4_0::Result>  _hidl_out = ::android::hardware::audio::effect::V4_0::BpHwEffect::_hidl_setAudioMode(this, this, mode);

    return _hidl_out;
}

::android::hardware::Return<::android::hardware::audio::effect::V4_0::Result> BpHwEnvironmentalReverbEffect::setConfigReverse(const ::android::hardware::audio::effect::V4_0::EffectConfig& config, const ::android::sp<::android::hardware::audio::effect::V4_0::IEffectBufferProviderCallback>& inputBufferProvider, const ::android::sp<::android::hardware::audio::effect::V4_0::IEffectBufferProviderCallback>& outputBufferProvider){
    ::android::hardware::Return<::android::hardware::audio::effect::V4_0::Result>  _hidl_out = ::android::hardware::audio::effect::V4_0::BpHwEffect::_hidl_setConfigReverse(this, this, config, inputBufferProvider, outputBufferProvider);

    return _hidl_out;
}

::android::hardware::Return<::android::hardware::audio::effect::V4_0::Result> BpHwEnvironmentalReverbEffect::setInputDevice(::android::hardware::hidl_bitfield<::android::hardware::audio::common::V4_0::AudioDevice> device){
    ::android::hardware::Return<::android::hardware::audio::effect::V4_0::Result>  _hidl_out = ::android::hardware::audio::effect::V4_0::BpHwEffect::_hidl_setInputDevice(this, this, device);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwEnvironmentalReverbEffect::getConfig(getConfig_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::audio::effect::V4_0::BpHwEffect::_hidl_getConfig(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwEnvironmentalReverbEffect::getConfigReverse(getConfigReverse_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::audio::effect::V4_0::BpHwEffect::_hidl_getConfigReverse(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwEnvironmentalReverbEffect::getSupportedAuxChannelsConfigs(uint32_t maxConfigs, getSupportedAuxChannelsConfigs_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::audio::effect::V4_0::BpHwEffect::_hidl_getSupportedAuxChannelsConfigs(this, this, maxConfigs, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwEnvironmentalReverbEffect::getAuxChannelsConfig(getAuxChannelsConfig_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::audio::effect::V4_0::BpHwEffect::_hidl_getAuxChannelsConfig(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<::android::hardware::audio::effect::V4_0::Result> BpHwEnvironmentalReverbEffect::setAuxChannelsConfig(const ::android::hardware::audio::effect::V4_0::EffectAuxChannelsConfig& config){
    ::android::hardware::Return<::android::hardware::audio::effect::V4_0::Result>  _hidl_out = ::android::hardware::audio::effect::V4_0::BpHwEffect::_hidl_setAuxChannelsConfig(this, this, config);

    return _hidl_out;
}

::android::hardware::Return<::android::hardware::audio::effect::V4_0::Result> BpHwEnvironmentalReverbEffect::setAudioSource(::android::hardware::audio::common::V4_0::AudioSource source){
    ::android::hardware::Return<::android::hardware::audio::effect::V4_0::Result>  _hidl_out = ::android::hardware::audio::effect::V4_0::BpHwEffect::_hidl_setAudioSource(this, this, source);

    return _hidl_out;
}

::android::hardware::Return<::android::hardware::audio::effect::V4_0::Result> BpHwEnvironmentalReverbEffect::offload(const ::android::hardware::audio::effect::V4_0::EffectOffloadParameter& param){
    ::android::hardware::Return<::android::hardware::audio::effect::V4_0::Result>  _hidl_out = ::android::hardware::audio::effect::V4_0::BpHwEffect::_hidl_offload(this, this, param);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwEnvironmentalReverbEffect::getDescriptor(getDescriptor_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::audio::effect::V4_0::BpHwEffect::_hidl_getDescriptor(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwEnvironmentalReverbEffect::prepareForProcessing(prepareForProcessing_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::audio::effect::V4_0::BpHwEffect::_hidl_prepareForProcessing(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<::android::hardware::audio::effect::V4_0::Result> BpHwEnvironmentalReverbEffect::setProcessBuffers(const ::android::hardware::audio::effect::V4_0::AudioBuffer& inBuffer, const ::android::hardware::audio::effect::V4_0::AudioBuffer& outBuffer){
    ::android::hardware::Return<::android::hardware::audio::effect::V4_0::Result>  _hidl_out = ::android::hardware::audio::effect::V4_0::BpHwEffect::_hidl_setProcessBuffers(this, this, inBuffer, outBuffer);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwEnvironmentalReverbEffect::command(uint32_t commandId, const ::android::hardware::hidl_vec<uint8_t>& data, uint32_t resultMaxSize, command_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::audio::effect::V4_0::BpHwEffect::_hidl_command(this, this, commandId, data, resultMaxSize, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<::android::hardware::audio::effect::V4_0::Result> BpHwEnvironmentalReverbEffect::setParameter(const ::android::hardware::hidl_vec<uint8_t>& parameter, const ::android::hardware::hidl_vec<uint8_t>& value){
    ::android::hardware::Return<::android::hardware::audio::effect::V4_0::Result>  _hidl_out = ::android::hardware::audio::effect::V4_0::BpHwEffect::_hidl_setParameter(this, this, parameter, value);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwEnvironmentalReverbEffect::getParameter(const ::android::hardware::hidl_vec<uint8_t>& parameter, uint32_t valueMaxSize, getParameter_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::audio::effect::V4_0::BpHwEffect::_hidl_getParameter(this, this, parameter, valueMaxSize, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwEnvironmentalReverbEffect::getSupportedConfigsForFeature(uint32_t featureId, uint32_t maxConfigs, uint32_t configSize, getSupportedConfigsForFeature_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::audio::effect::V4_0::BpHwEffect::_hidl_getSupportedConfigsForFeature(this, this, featureId, maxConfigs, configSize, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwEnvironmentalReverbEffect::getCurrentConfigForFeature(uint32_t featureId, uint32_t configSize, getCurrentConfigForFeature_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::audio::effect::V4_0::BpHwEffect::_hidl_getCurrentConfigForFeature(this, this, featureId, configSize, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<::android::hardware::audio::effect::V4_0::Result> BpHwEnvironmentalReverbEffect::setCurrentConfigForFeature(uint32_t featureId, const ::android::hardware::hidl_vec<uint8_t>& configData){
    ::android::hardware::Return<::android::hardware::audio::effect::V4_0::Result>  _hidl_out = ::android::hardware::audio::effect::V4_0::BpHwEffect::_hidl_setCurrentConfigForFeature(this, this, featureId, configData);

    return _hidl_out;
}

::android::hardware::Return<::android::hardware::audio::effect::V4_0::Result> BpHwEnvironmentalReverbEffect::close(){
    ::android::hardware::Return<::android::hardware::audio::effect::V4_0::Result>  _hidl_out = ::android::hardware::audio::effect::V4_0::BpHwEffect::_hidl_close(this, this);

    return _hidl_out;
}


// Methods from ::android::hardware::audio::effect::V4_0::IEnvironmentalReverbEffect follow.
::android::hardware::Return<::android::hardware::audio::effect::V4_0::Result> BpHwEnvironmentalReverbEffect::setBypass(bool bypass){
    ::android::hardware::Return<::android::hardware::audio::effect::V4_0::Result>  _hidl_out = ::android::hardware::audio::effect::V4_0::BpHwEnvironmentalReverbEffect::_hidl_setBypass(this, this, bypass);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwEnvironmentalReverbEffect::getBypass(getBypass_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::audio::effect::V4_0::BpHwEnvironmentalReverbEffect::_hidl_getBypass(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<::android::hardware::audio::effect::V4_0::Result> BpHwEnvironmentalReverbEffect::setRoomLevel(int16_t roomLevel){
    ::android::hardware::Return<::android::hardware::audio::effect::V4_0::Result>  _hidl_out = ::android::hardware::audio::effect::V4_0::BpHwEnvironmentalReverbEffect::_hidl_setRoomLevel(this, this, roomLevel);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwEnvironmentalReverbEffect::getRoomLevel(getRoomLevel_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::audio::effect::V4_0::BpHwEnvironmentalReverbEffect::_hidl_getRoomLevel(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<::android::hardware::audio::effect::V4_0::Result> BpHwEnvironmentalReverbEffect::setRoomHfLevel(int16_t roomHfLevel){
    ::android::hardware::Return<::android::hardware::audio::effect::V4_0::Result>  _hidl_out = ::android::hardware::audio::effect::V4_0::BpHwEnvironmentalReverbEffect::_hidl_setRoomHfLevel(this, this, roomHfLevel);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwEnvironmentalReverbEffect::getRoomHfLevel(getRoomHfLevel_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::audio::effect::V4_0::BpHwEnvironmentalReverbEffect::_hidl_getRoomHfLevel(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<::android::hardware::audio::effect::V4_0::Result> BpHwEnvironmentalReverbEffect::setDecayTime(uint32_t decayTime){
    ::android::hardware::Return<::android::hardware::audio::effect::V4_0::Result>  _hidl_out = ::android::hardware::audio::effect::V4_0::BpHwEnvironmentalReverbEffect::_hidl_setDecayTime(this, this, decayTime);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwEnvironmentalReverbEffect::getDecayTime(getDecayTime_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::audio::effect::V4_0::BpHwEnvironmentalReverbEffect::_hidl_getDecayTime(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<::android::hardware::audio::effect::V4_0::Result> BpHwEnvironmentalReverbEffect::setDecayHfRatio(int16_t decayHfRatio){
    ::android::hardware::Return<::android::hardware::audio::effect::V4_0::Result>  _hidl_out = ::android::hardware::audio::effect::V4_0::BpHwEnvironmentalReverbEffect::_hidl_setDecayHfRatio(this, this, decayHfRatio);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwEnvironmentalReverbEffect::getDecayHfRatio(getDecayHfRatio_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::audio::effect::V4_0::BpHwEnvironmentalReverbEffect::_hidl_getDecayHfRatio(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<::android::hardware::audio::effect::V4_0::Result> BpHwEnvironmentalReverbEffect::setReflectionsLevel(int16_t reflectionsLevel){
    ::android::hardware::Return<::android::hardware::audio::effect::V4_0::Result>  _hidl_out = ::android::hardware::audio::effect::V4_0::BpHwEnvironmentalReverbEffect::_hidl_setReflectionsLevel(this, this, reflectionsLevel);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwEnvironmentalReverbEffect::getReflectionsLevel(getReflectionsLevel_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::audio::effect::V4_0::BpHwEnvironmentalReverbEffect::_hidl_getReflectionsLevel(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<::android::hardware::audio::effect::V4_0::Result> BpHwEnvironmentalReverbEffect::setReflectionsDelay(uint32_t reflectionsDelay){
    ::android::hardware::Return<::android::hardware::audio::effect::V4_0::Result>  _hidl_out = ::android::hardware::audio::effect::V4_0::BpHwEnvironmentalReverbEffect::_hidl_setReflectionsDelay(this, this, reflectionsDelay);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwEnvironmentalReverbEffect::getReflectionsDelay(getReflectionsDelay_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::audio::effect::V4_0::BpHwEnvironmentalReverbEffect::_hidl_getReflectionsDelay(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<::android::hardware::audio::effect::V4_0::Result> BpHwEnvironmentalReverbEffect::setReverbLevel(int16_t reverbLevel){
    ::android::hardware::Return<::android::hardware::audio::effect::V4_0::Result>  _hidl_out = ::android::hardware::audio::effect::V4_0::BpHwEnvironmentalReverbEffect::_hidl_setReverbLevel(this, this, reverbLevel);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwEnvironmentalReverbEffect::getReverbLevel(getReverbLevel_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::audio::effect::V4_0::BpHwEnvironmentalReverbEffect::_hidl_getReverbLevel(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<::android::hardware::audio::effect::V4_0::Result> BpHwEnvironmentalReverbEffect::setReverbDelay(uint32_t reverDelay){
    ::android::hardware::Return<::android::hardware::audio::effect::V4_0::Result>  _hidl_out = ::android::hardware::audio::effect::V4_0::BpHwEnvironmentalReverbEffect::_hidl_setReverbDelay(this, this, reverDelay);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwEnvironmentalReverbEffect::getReverbDelay(getReverbDelay_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::audio::effect::V4_0::BpHwEnvironmentalReverbEffect::_hidl_getReverbDelay(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<::android::hardware::audio::effect::V4_0::Result> BpHwEnvironmentalReverbEffect::setDiffusion(int16_t diffusion){
    ::android::hardware::Return<::android::hardware::audio::effect::V4_0::Result>  _hidl_out = ::android::hardware::audio::effect::V4_0::BpHwEnvironmentalReverbEffect::_hidl_setDiffusion(this, this, diffusion);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwEnvironmentalReverbEffect::getDiffusion(getDiffusion_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::audio::effect::V4_0::BpHwEnvironmentalReverbEffect::_hidl_getDiffusion(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<::android::hardware::audio::effect::V4_0::Result> BpHwEnvironmentalReverbEffect::setDensity(int16_t density){
    ::android::hardware::Return<::android::hardware::audio::effect::V4_0::Result>  _hidl_out = ::android::hardware::audio::effect::V4_0::BpHwEnvironmentalReverbEffect::_hidl_setDensity(this, this, density);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwEnvironmentalReverbEffect::getDensity(getDensity_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::audio::effect::V4_0::BpHwEnvironmentalReverbEffect::_hidl_getDensity(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<::android::hardware::audio::effect::V4_0::Result> BpHwEnvironmentalReverbEffect::setAllProperties(const ::android::hardware::audio::effect::V4_0::IEnvironmentalReverbEffect::AllProperties& properties){
    ::android::hardware::Return<::android::hardware::audio::effect::V4_0::Result>  _hidl_out = ::android::hardware::audio::effect::V4_0::BpHwEnvironmentalReverbEffect::_hidl_setAllProperties(this, this, properties);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwEnvironmentalReverbEffect::getAllProperties(getAllProperties_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::audio::effect::V4_0::BpHwEnvironmentalReverbEffect::_hidl_getAllProperties(this, this, _hidl_cb);

    return _hidl_out;
}


// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BpHwEnvironmentalReverbEffect::interfaceChain(interfaceChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwEnvironmentalReverbEffect::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_debug(this, this, fd, options);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwEnvironmentalReverbEffect::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceDescriptor(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwEnvironmentalReverbEffect::getHashChain(getHashChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getHashChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwEnvironmentalReverbEffect::setHALInstrumentation(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_setHALInstrumentation(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwEnvironmentalReverbEffect::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    ::android::hardware::ProcessState::self()->startThreadPool();
    ::android::hardware::hidl_binder_death_recipient *binder_recipient = new ::android::hardware::hidl_binder_death_recipient(recipient, cookie, this);
    std::unique_lock<std::mutex> lock(_hidl_mMutex);
    _hidl_mDeathRecipients.push_back(binder_recipient);
    return (remote()->linkToDeath(binder_recipient) == ::android::OK);
}

::android::hardware::Return<void> BpHwEnvironmentalReverbEffect::ping(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_ping(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwEnvironmentalReverbEffect::getDebugInfo(getDebugInfo_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getDebugInfo(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwEnvironmentalReverbEffect::notifySyspropsChanged(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_notifySyspropsChanged(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwEnvironmentalReverbEffect::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
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


BnHwEnvironmentalReverbEffect::BnHwEnvironmentalReverbEffect(const ::android::sp<IEnvironmentalReverbEffect> &_hidl_impl)
        : ::android::hidl::base::V1_0::BnHwBase(_hidl_impl, "android.hardware.audio.effect@4.0", "IEnvironmentalReverbEffect") { 
            _hidl_mImpl = _hidl_impl;
            auto prio = ::android::hardware::getMinSchedulerPolicy(_hidl_impl);
            mSchedPolicy = prio.sched_policy;
            mSchedPriority = prio.prio;
            setRequestingSid(::android::hardware::getRequestingSid(_hidl_impl));
}

BnHwEnvironmentalReverbEffect::~BnHwEnvironmentalReverbEffect() {
    ::android::hardware::details::gBnMap->eraseIfEqual(_hidl_mImpl.get(), this);
}

// Methods from ::android::hardware::audio::effect::V4_0::IEnvironmentalReverbEffect follow.
::android::status_t BnHwEnvironmentalReverbEffect::_hidl_setBypass(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwEnvironmentalReverbEffect::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    bool bypass;

    _hidl_err = _hidl_data.readBool(&bypass);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IEnvironmentalReverbEffect::setBypass::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&bypass);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.audio.effect", "4.0", "IEnvironmentalReverbEffect", "setBypass", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::audio::effect::V4_0::Result _hidl_out_retval = static_cast<IEnvironmentalReverbEffect*>(_hidl_this->getImpl().get())->setBypass(bypass);

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
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.audio.effect", "4.0", "IEnvironmentalReverbEffect", "setBypass", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwEnvironmentalReverbEffect::_hidl_getBypass(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwEnvironmentalReverbEffect::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IEnvironmentalReverbEffect::getBypass::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.audio.effect", "4.0", "IEnvironmentalReverbEffect", "getBypass", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IEnvironmentalReverbEffect*>(_hidl_this->getImpl().get())->getBypass([&](const auto &_hidl_out_retval, const auto &_hidl_out_bypass) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("getBypass: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_retval);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_err = _hidl_reply->writeBool(_hidl_out_bypass);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_retval);
            _hidl_args.push_back((void *)&_hidl_out_bypass);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.audio.effect", "4.0", "IEnvironmentalReverbEffect", "getBypass", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("getBypass: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwEnvironmentalReverbEffect::_hidl_setRoomLevel(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwEnvironmentalReverbEffect::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    int16_t roomLevel;

    _hidl_err = _hidl_data.readInt16(&roomLevel);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IEnvironmentalReverbEffect::setRoomLevel::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&roomLevel);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.audio.effect", "4.0", "IEnvironmentalReverbEffect", "setRoomLevel", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::audio::effect::V4_0::Result _hidl_out_retval = static_cast<IEnvironmentalReverbEffect*>(_hidl_this->getImpl().get())->setRoomLevel(roomLevel);

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
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.audio.effect", "4.0", "IEnvironmentalReverbEffect", "setRoomLevel", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwEnvironmentalReverbEffect::_hidl_getRoomLevel(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwEnvironmentalReverbEffect::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IEnvironmentalReverbEffect::getRoomLevel::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.audio.effect", "4.0", "IEnvironmentalReverbEffect", "getRoomLevel", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IEnvironmentalReverbEffect*>(_hidl_this->getImpl().get())->getRoomLevel([&](const auto &_hidl_out_retval, const auto &_hidl_out_roomLevel) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("getRoomLevel: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_retval);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_err = _hidl_reply->writeInt16(_hidl_out_roomLevel);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_retval);
            _hidl_args.push_back((void *)&_hidl_out_roomLevel);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.audio.effect", "4.0", "IEnvironmentalReverbEffect", "getRoomLevel", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("getRoomLevel: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwEnvironmentalReverbEffect::_hidl_setRoomHfLevel(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwEnvironmentalReverbEffect::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    int16_t roomHfLevel;

    _hidl_err = _hidl_data.readInt16(&roomHfLevel);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IEnvironmentalReverbEffect::setRoomHfLevel::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&roomHfLevel);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.audio.effect", "4.0", "IEnvironmentalReverbEffect", "setRoomHfLevel", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::audio::effect::V4_0::Result _hidl_out_retval = static_cast<IEnvironmentalReverbEffect*>(_hidl_this->getImpl().get())->setRoomHfLevel(roomHfLevel);

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
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.audio.effect", "4.0", "IEnvironmentalReverbEffect", "setRoomHfLevel", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwEnvironmentalReverbEffect::_hidl_getRoomHfLevel(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwEnvironmentalReverbEffect::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IEnvironmentalReverbEffect::getRoomHfLevel::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.audio.effect", "4.0", "IEnvironmentalReverbEffect", "getRoomHfLevel", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IEnvironmentalReverbEffect*>(_hidl_this->getImpl().get())->getRoomHfLevel([&](const auto &_hidl_out_retval, const auto &_hidl_out_roomHfLevel) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("getRoomHfLevel: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_retval);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_err = _hidl_reply->writeInt16(_hidl_out_roomHfLevel);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_retval);
            _hidl_args.push_back((void *)&_hidl_out_roomHfLevel);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.audio.effect", "4.0", "IEnvironmentalReverbEffect", "getRoomHfLevel", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("getRoomHfLevel: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwEnvironmentalReverbEffect::_hidl_setDecayTime(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwEnvironmentalReverbEffect::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint32_t decayTime;

    _hidl_err = _hidl_data.readUint32(&decayTime);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IEnvironmentalReverbEffect::setDecayTime::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&decayTime);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.audio.effect", "4.0", "IEnvironmentalReverbEffect", "setDecayTime", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::audio::effect::V4_0::Result _hidl_out_retval = static_cast<IEnvironmentalReverbEffect*>(_hidl_this->getImpl().get())->setDecayTime(decayTime);

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
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.audio.effect", "4.0", "IEnvironmentalReverbEffect", "setDecayTime", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwEnvironmentalReverbEffect::_hidl_getDecayTime(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwEnvironmentalReverbEffect::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IEnvironmentalReverbEffect::getDecayTime::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.audio.effect", "4.0", "IEnvironmentalReverbEffect", "getDecayTime", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IEnvironmentalReverbEffect*>(_hidl_this->getImpl().get())->getDecayTime([&](const auto &_hidl_out_retval, const auto &_hidl_out_decayTime) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("getDecayTime: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_retval);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_err = _hidl_reply->writeUint32(_hidl_out_decayTime);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_retval);
            _hidl_args.push_back((void *)&_hidl_out_decayTime);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.audio.effect", "4.0", "IEnvironmentalReverbEffect", "getDecayTime", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("getDecayTime: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwEnvironmentalReverbEffect::_hidl_setDecayHfRatio(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwEnvironmentalReverbEffect::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    int16_t decayHfRatio;

    _hidl_err = _hidl_data.readInt16(&decayHfRatio);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IEnvironmentalReverbEffect::setDecayHfRatio::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&decayHfRatio);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.audio.effect", "4.0", "IEnvironmentalReverbEffect", "setDecayHfRatio", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::audio::effect::V4_0::Result _hidl_out_retval = static_cast<IEnvironmentalReverbEffect*>(_hidl_this->getImpl().get())->setDecayHfRatio(decayHfRatio);

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
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.audio.effect", "4.0", "IEnvironmentalReverbEffect", "setDecayHfRatio", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwEnvironmentalReverbEffect::_hidl_getDecayHfRatio(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwEnvironmentalReverbEffect::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IEnvironmentalReverbEffect::getDecayHfRatio::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.audio.effect", "4.0", "IEnvironmentalReverbEffect", "getDecayHfRatio", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IEnvironmentalReverbEffect*>(_hidl_this->getImpl().get())->getDecayHfRatio([&](const auto &_hidl_out_retval, const auto &_hidl_out_decayHfRatio) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("getDecayHfRatio: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_retval);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_err = _hidl_reply->writeInt16(_hidl_out_decayHfRatio);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_retval);
            _hidl_args.push_back((void *)&_hidl_out_decayHfRatio);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.audio.effect", "4.0", "IEnvironmentalReverbEffect", "getDecayHfRatio", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("getDecayHfRatio: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwEnvironmentalReverbEffect::_hidl_setReflectionsLevel(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwEnvironmentalReverbEffect::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    int16_t reflectionsLevel;

    _hidl_err = _hidl_data.readInt16(&reflectionsLevel);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IEnvironmentalReverbEffect::setReflectionsLevel::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&reflectionsLevel);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.audio.effect", "4.0", "IEnvironmentalReverbEffect", "setReflectionsLevel", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::audio::effect::V4_0::Result _hidl_out_retval = static_cast<IEnvironmentalReverbEffect*>(_hidl_this->getImpl().get())->setReflectionsLevel(reflectionsLevel);

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
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.audio.effect", "4.0", "IEnvironmentalReverbEffect", "setReflectionsLevel", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwEnvironmentalReverbEffect::_hidl_getReflectionsLevel(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwEnvironmentalReverbEffect::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IEnvironmentalReverbEffect::getReflectionsLevel::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.audio.effect", "4.0", "IEnvironmentalReverbEffect", "getReflectionsLevel", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IEnvironmentalReverbEffect*>(_hidl_this->getImpl().get())->getReflectionsLevel([&](const auto &_hidl_out_retval, const auto &_hidl_out_reflectionsLevel) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("getReflectionsLevel: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_retval);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_err = _hidl_reply->writeInt16(_hidl_out_reflectionsLevel);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_retval);
            _hidl_args.push_back((void *)&_hidl_out_reflectionsLevel);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.audio.effect", "4.0", "IEnvironmentalReverbEffect", "getReflectionsLevel", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("getReflectionsLevel: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwEnvironmentalReverbEffect::_hidl_setReflectionsDelay(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwEnvironmentalReverbEffect::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint32_t reflectionsDelay;

    _hidl_err = _hidl_data.readUint32(&reflectionsDelay);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IEnvironmentalReverbEffect::setReflectionsDelay::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&reflectionsDelay);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.audio.effect", "4.0", "IEnvironmentalReverbEffect", "setReflectionsDelay", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::audio::effect::V4_0::Result _hidl_out_retval = static_cast<IEnvironmentalReverbEffect*>(_hidl_this->getImpl().get())->setReflectionsDelay(reflectionsDelay);

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
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.audio.effect", "4.0", "IEnvironmentalReverbEffect", "setReflectionsDelay", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwEnvironmentalReverbEffect::_hidl_getReflectionsDelay(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwEnvironmentalReverbEffect::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IEnvironmentalReverbEffect::getReflectionsDelay::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.audio.effect", "4.0", "IEnvironmentalReverbEffect", "getReflectionsDelay", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IEnvironmentalReverbEffect*>(_hidl_this->getImpl().get())->getReflectionsDelay([&](const auto &_hidl_out_retval, const auto &_hidl_out_reflectionsDelay) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("getReflectionsDelay: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_retval);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_err = _hidl_reply->writeUint32(_hidl_out_reflectionsDelay);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_retval);
            _hidl_args.push_back((void *)&_hidl_out_reflectionsDelay);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.audio.effect", "4.0", "IEnvironmentalReverbEffect", "getReflectionsDelay", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("getReflectionsDelay: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwEnvironmentalReverbEffect::_hidl_setReverbLevel(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwEnvironmentalReverbEffect::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    int16_t reverbLevel;

    _hidl_err = _hidl_data.readInt16(&reverbLevel);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IEnvironmentalReverbEffect::setReverbLevel::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&reverbLevel);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.audio.effect", "4.0", "IEnvironmentalReverbEffect", "setReverbLevel", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::audio::effect::V4_0::Result _hidl_out_retval = static_cast<IEnvironmentalReverbEffect*>(_hidl_this->getImpl().get())->setReverbLevel(reverbLevel);

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
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.audio.effect", "4.0", "IEnvironmentalReverbEffect", "setReverbLevel", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwEnvironmentalReverbEffect::_hidl_getReverbLevel(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwEnvironmentalReverbEffect::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IEnvironmentalReverbEffect::getReverbLevel::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.audio.effect", "4.0", "IEnvironmentalReverbEffect", "getReverbLevel", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IEnvironmentalReverbEffect*>(_hidl_this->getImpl().get())->getReverbLevel([&](const auto &_hidl_out_retval, const auto &_hidl_out_reverbLevel) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("getReverbLevel: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_retval);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_err = _hidl_reply->writeInt16(_hidl_out_reverbLevel);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_retval);
            _hidl_args.push_back((void *)&_hidl_out_reverbLevel);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.audio.effect", "4.0", "IEnvironmentalReverbEffect", "getReverbLevel", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("getReverbLevel: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwEnvironmentalReverbEffect::_hidl_setReverbDelay(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwEnvironmentalReverbEffect::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint32_t reverDelay;

    _hidl_err = _hidl_data.readUint32(&reverDelay);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IEnvironmentalReverbEffect::setReverbDelay::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&reverDelay);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.audio.effect", "4.0", "IEnvironmentalReverbEffect", "setReverbDelay", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::audio::effect::V4_0::Result _hidl_out_retval = static_cast<IEnvironmentalReverbEffect*>(_hidl_this->getImpl().get())->setReverbDelay(reverDelay);

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
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.audio.effect", "4.0", "IEnvironmentalReverbEffect", "setReverbDelay", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwEnvironmentalReverbEffect::_hidl_getReverbDelay(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwEnvironmentalReverbEffect::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IEnvironmentalReverbEffect::getReverbDelay::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.audio.effect", "4.0", "IEnvironmentalReverbEffect", "getReverbDelay", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IEnvironmentalReverbEffect*>(_hidl_this->getImpl().get())->getReverbDelay([&](const auto &_hidl_out_retval, const auto &_hidl_out_reverbDelay) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("getReverbDelay: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_retval);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_err = _hidl_reply->writeUint32(_hidl_out_reverbDelay);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_retval);
            _hidl_args.push_back((void *)&_hidl_out_reverbDelay);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.audio.effect", "4.0", "IEnvironmentalReverbEffect", "getReverbDelay", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("getReverbDelay: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwEnvironmentalReverbEffect::_hidl_setDiffusion(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwEnvironmentalReverbEffect::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    int16_t diffusion;

    _hidl_err = _hidl_data.readInt16(&diffusion);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IEnvironmentalReverbEffect::setDiffusion::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&diffusion);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.audio.effect", "4.0", "IEnvironmentalReverbEffect", "setDiffusion", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::audio::effect::V4_0::Result _hidl_out_retval = static_cast<IEnvironmentalReverbEffect*>(_hidl_this->getImpl().get())->setDiffusion(diffusion);

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
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.audio.effect", "4.0", "IEnvironmentalReverbEffect", "setDiffusion", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwEnvironmentalReverbEffect::_hidl_getDiffusion(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwEnvironmentalReverbEffect::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IEnvironmentalReverbEffect::getDiffusion::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.audio.effect", "4.0", "IEnvironmentalReverbEffect", "getDiffusion", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IEnvironmentalReverbEffect*>(_hidl_this->getImpl().get())->getDiffusion([&](const auto &_hidl_out_retval, const auto &_hidl_out_diffusion) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("getDiffusion: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_retval);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_err = _hidl_reply->writeInt16(_hidl_out_diffusion);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_retval);
            _hidl_args.push_back((void *)&_hidl_out_diffusion);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.audio.effect", "4.0", "IEnvironmentalReverbEffect", "getDiffusion", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("getDiffusion: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwEnvironmentalReverbEffect::_hidl_setDensity(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwEnvironmentalReverbEffect::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    int16_t density;

    _hidl_err = _hidl_data.readInt16(&density);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IEnvironmentalReverbEffect::setDensity::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&density);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.audio.effect", "4.0", "IEnvironmentalReverbEffect", "setDensity", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::audio::effect::V4_0::Result _hidl_out_retval = static_cast<IEnvironmentalReverbEffect*>(_hidl_this->getImpl().get())->setDensity(density);

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
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.audio.effect", "4.0", "IEnvironmentalReverbEffect", "setDensity", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwEnvironmentalReverbEffect::_hidl_getDensity(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwEnvironmentalReverbEffect::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IEnvironmentalReverbEffect::getDensity::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.audio.effect", "4.0", "IEnvironmentalReverbEffect", "getDensity", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IEnvironmentalReverbEffect*>(_hidl_this->getImpl().get())->getDensity([&](const auto &_hidl_out_retval, const auto &_hidl_out_density) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("getDensity: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_retval);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_err = _hidl_reply->writeInt16(_hidl_out_density);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_retval);
            _hidl_args.push_back((void *)&_hidl_out_density);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.audio.effect", "4.0", "IEnvironmentalReverbEffect", "getDensity", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("getDensity: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwEnvironmentalReverbEffect::_hidl_setAllProperties(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwEnvironmentalReverbEffect::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::audio::effect::V4_0::IEnvironmentalReverbEffect::AllProperties* properties;

    size_t _hidl_properties_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*properties), &_hidl_properties_parent,  const_cast<const void**>(reinterpret_cast<void **>(&properties)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IEnvironmentalReverbEffect::setAllProperties::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)properties);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.audio.effect", "4.0", "IEnvironmentalReverbEffect", "setAllProperties", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::audio::effect::V4_0::Result _hidl_out_retval = static_cast<IEnvironmentalReverbEffect*>(_hidl_this->getImpl().get())->setAllProperties(*properties);

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
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.audio.effect", "4.0", "IEnvironmentalReverbEffect", "setAllProperties", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwEnvironmentalReverbEffect::_hidl_getAllProperties(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwEnvironmentalReverbEffect::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IEnvironmentalReverbEffect::getAllProperties::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.audio.effect", "4.0", "IEnvironmentalReverbEffect", "getAllProperties", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IEnvironmentalReverbEffect*>(_hidl_this->getImpl().get())->getAllProperties([&](const auto &_hidl_out_retval, const auto &_hidl_out_properties) {
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

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_retval);
            _hidl_args.push_back((void *)&_hidl_out_properties);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.audio.effect", "4.0", "IEnvironmentalReverbEffect", "getAllProperties", &_hidl_args);
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


// Methods from ::android::hardware::audio::effect::V4_0::IEffect follow.

// Methods from ::android::hardware::audio::effect::V4_0::IEnvironmentalReverbEffect follow.

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BnHwEnvironmentalReverbEffect::ping() {
    return ::android::hardware::Void();
}
::android::hardware::Return<void> BnHwEnvironmentalReverbEffect::getDebugInfo(getDebugInfo_cb _hidl_cb) {
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

::android::status_t BnHwEnvironmentalReverbEffect::onTransact(
        uint32_t _hidl_code,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        uint32_t _hidl_flags,
        TransactCallback _hidl_cb) {
    ::android::status_t _hidl_err = ::android::OK;

    switch (_hidl_code) {
        case 1 /* init */:
        {
            _hidl_err = ::android::hardware::audio::effect::V4_0::BnHwEffect::_hidl_init(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 2 /* setConfig */:
        {
            _hidl_err = ::android::hardware::audio::effect::V4_0::BnHwEffect::_hidl_setConfig(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 3 /* reset */:
        {
            _hidl_err = ::android::hardware::audio::effect::V4_0::BnHwEffect::_hidl_reset(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 4 /* enable */:
        {
            _hidl_err = ::android::hardware::audio::effect::V4_0::BnHwEffect::_hidl_enable(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 5 /* disable */:
        {
            _hidl_err = ::android::hardware::audio::effect::V4_0::BnHwEffect::_hidl_disable(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 6 /* setDevice */:
        {
            _hidl_err = ::android::hardware::audio::effect::V4_0::BnHwEffect::_hidl_setDevice(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 7 /* setAndGetVolume */:
        {
            _hidl_err = ::android::hardware::audio::effect::V4_0::BnHwEffect::_hidl_setAndGetVolume(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 8 /* volumeChangeNotification */:
        {
            _hidl_err = ::android::hardware::audio::effect::V4_0::BnHwEffect::_hidl_volumeChangeNotification(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 9 /* setAudioMode */:
        {
            _hidl_err = ::android::hardware::audio::effect::V4_0::BnHwEffect::_hidl_setAudioMode(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 10 /* setConfigReverse */:
        {
            _hidl_err = ::android::hardware::audio::effect::V4_0::BnHwEffect::_hidl_setConfigReverse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 11 /* setInputDevice */:
        {
            _hidl_err = ::android::hardware::audio::effect::V4_0::BnHwEffect::_hidl_setInputDevice(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 12 /* getConfig */:
        {
            _hidl_err = ::android::hardware::audio::effect::V4_0::BnHwEffect::_hidl_getConfig(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 13 /* getConfigReverse */:
        {
            _hidl_err = ::android::hardware::audio::effect::V4_0::BnHwEffect::_hidl_getConfigReverse(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 14 /* getSupportedAuxChannelsConfigs */:
        {
            _hidl_err = ::android::hardware::audio::effect::V4_0::BnHwEffect::_hidl_getSupportedAuxChannelsConfigs(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 15 /* getAuxChannelsConfig */:
        {
            _hidl_err = ::android::hardware::audio::effect::V4_0::BnHwEffect::_hidl_getAuxChannelsConfig(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 16 /* setAuxChannelsConfig */:
        {
            _hidl_err = ::android::hardware::audio::effect::V4_0::BnHwEffect::_hidl_setAuxChannelsConfig(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 17 /* setAudioSource */:
        {
            _hidl_err = ::android::hardware::audio::effect::V4_0::BnHwEffect::_hidl_setAudioSource(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 18 /* offload */:
        {
            _hidl_err = ::android::hardware::audio::effect::V4_0::BnHwEffect::_hidl_offload(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 19 /* getDescriptor */:
        {
            _hidl_err = ::android::hardware::audio::effect::V4_0::BnHwEffect::_hidl_getDescriptor(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 20 /* prepareForProcessing */:
        {
            _hidl_err = ::android::hardware::audio::effect::V4_0::BnHwEffect::_hidl_prepareForProcessing(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 21 /* setProcessBuffers */:
        {
            _hidl_err = ::android::hardware::audio::effect::V4_0::BnHwEffect::_hidl_setProcessBuffers(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 22 /* command */:
        {
            _hidl_err = ::android::hardware::audio::effect::V4_0::BnHwEffect::_hidl_command(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 23 /* setParameter */:
        {
            _hidl_err = ::android::hardware::audio::effect::V4_0::BnHwEffect::_hidl_setParameter(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 24 /* getParameter */:
        {
            _hidl_err = ::android::hardware::audio::effect::V4_0::BnHwEffect::_hidl_getParameter(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 25 /* getSupportedConfigsForFeature */:
        {
            _hidl_err = ::android::hardware::audio::effect::V4_0::BnHwEffect::_hidl_getSupportedConfigsForFeature(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 26 /* getCurrentConfigForFeature */:
        {
            _hidl_err = ::android::hardware::audio::effect::V4_0::BnHwEffect::_hidl_getCurrentConfigForFeature(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 27 /* setCurrentConfigForFeature */:
        {
            _hidl_err = ::android::hardware::audio::effect::V4_0::BnHwEffect::_hidl_setCurrentConfigForFeature(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 28 /* close */:
        {
            _hidl_err = ::android::hardware::audio::effect::V4_0::BnHwEffect::_hidl_close(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 29 /* setBypass */:
        {
            _hidl_err = ::android::hardware::audio::effect::V4_0::BnHwEnvironmentalReverbEffect::_hidl_setBypass(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 30 /* getBypass */:
        {
            _hidl_err = ::android::hardware::audio::effect::V4_0::BnHwEnvironmentalReverbEffect::_hidl_getBypass(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 31 /* setRoomLevel */:
        {
            _hidl_err = ::android::hardware::audio::effect::V4_0::BnHwEnvironmentalReverbEffect::_hidl_setRoomLevel(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 32 /* getRoomLevel */:
        {
            _hidl_err = ::android::hardware::audio::effect::V4_0::BnHwEnvironmentalReverbEffect::_hidl_getRoomLevel(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 33 /* setRoomHfLevel */:
        {
            _hidl_err = ::android::hardware::audio::effect::V4_0::BnHwEnvironmentalReverbEffect::_hidl_setRoomHfLevel(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 34 /* getRoomHfLevel */:
        {
            _hidl_err = ::android::hardware::audio::effect::V4_0::BnHwEnvironmentalReverbEffect::_hidl_getRoomHfLevel(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 35 /* setDecayTime */:
        {
            _hidl_err = ::android::hardware::audio::effect::V4_0::BnHwEnvironmentalReverbEffect::_hidl_setDecayTime(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 36 /* getDecayTime */:
        {
            _hidl_err = ::android::hardware::audio::effect::V4_0::BnHwEnvironmentalReverbEffect::_hidl_getDecayTime(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 37 /* setDecayHfRatio */:
        {
            _hidl_err = ::android::hardware::audio::effect::V4_0::BnHwEnvironmentalReverbEffect::_hidl_setDecayHfRatio(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 38 /* getDecayHfRatio */:
        {
            _hidl_err = ::android::hardware::audio::effect::V4_0::BnHwEnvironmentalReverbEffect::_hidl_getDecayHfRatio(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 39 /* setReflectionsLevel */:
        {
            _hidl_err = ::android::hardware::audio::effect::V4_0::BnHwEnvironmentalReverbEffect::_hidl_setReflectionsLevel(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 40 /* getReflectionsLevel */:
        {
            _hidl_err = ::android::hardware::audio::effect::V4_0::BnHwEnvironmentalReverbEffect::_hidl_getReflectionsLevel(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 41 /* setReflectionsDelay */:
        {
            _hidl_err = ::android::hardware::audio::effect::V4_0::BnHwEnvironmentalReverbEffect::_hidl_setReflectionsDelay(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 42 /* getReflectionsDelay */:
        {
            _hidl_err = ::android::hardware::audio::effect::V4_0::BnHwEnvironmentalReverbEffect::_hidl_getReflectionsDelay(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 43 /* setReverbLevel */:
        {
            _hidl_err = ::android::hardware::audio::effect::V4_0::BnHwEnvironmentalReverbEffect::_hidl_setReverbLevel(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 44 /* getReverbLevel */:
        {
            _hidl_err = ::android::hardware::audio::effect::V4_0::BnHwEnvironmentalReverbEffect::_hidl_getReverbLevel(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 45 /* setReverbDelay */:
        {
            _hidl_err = ::android::hardware::audio::effect::V4_0::BnHwEnvironmentalReverbEffect::_hidl_setReverbDelay(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 46 /* getReverbDelay */:
        {
            _hidl_err = ::android::hardware::audio::effect::V4_0::BnHwEnvironmentalReverbEffect::_hidl_getReverbDelay(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 47 /* setDiffusion */:
        {
            _hidl_err = ::android::hardware::audio::effect::V4_0::BnHwEnvironmentalReverbEffect::_hidl_setDiffusion(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 48 /* getDiffusion */:
        {
            _hidl_err = ::android::hardware::audio::effect::V4_0::BnHwEnvironmentalReverbEffect::_hidl_getDiffusion(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 49 /* setDensity */:
        {
            _hidl_err = ::android::hardware::audio::effect::V4_0::BnHwEnvironmentalReverbEffect::_hidl_setDensity(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 50 /* getDensity */:
        {
            _hidl_err = ::android::hardware::audio::effect::V4_0::BnHwEnvironmentalReverbEffect::_hidl_getDensity(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 51 /* setAllProperties */:
        {
            _hidl_err = ::android::hardware::audio::effect::V4_0::BnHwEnvironmentalReverbEffect::_hidl_setAllProperties(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 52 /* getAllProperties */:
        {
            _hidl_err = ::android::hardware::audio::effect::V4_0::BnHwEnvironmentalReverbEffect::_hidl_getAllProperties(this, _hidl_data, _hidl_reply, _hidl_cb);
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

BsEnvironmentalReverbEffect::BsEnvironmentalReverbEffect(const ::android::sp<::android::hardware::audio::effect::V4_0::IEnvironmentalReverbEffect> impl) : ::android::hardware::details::HidlInstrumentor("android.hardware.audio.effect@4.0", "IEnvironmentalReverbEffect"), mImpl(impl) {
    mOnewayQueue.start(3000 /* similar limit to binderized */);
}

::android::hardware::Return<void> BsEnvironmentalReverbEffect::addOnewayTask(std::function<void(void)> fun) {
    if (!mOnewayQueue.push(fun)) {
        return ::android::hardware::Status::fromExceptionCode(
                ::android::hardware::Status::EX_TRANSACTION_FAILED,
                "Passthrough oneway function queue exceeds maximum size.");
    }
    return ::android::hardware::Status();
}

::android::sp<IEnvironmentalReverbEffect> IEnvironmentalReverbEffect::tryGetService(const std::string &serviceName, const bool getStub) {
    return ::android::hardware::details::getServiceInternal<BpHwEnvironmentalReverbEffect>(serviceName, false, getStub);
}

::android::sp<IEnvironmentalReverbEffect> IEnvironmentalReverbEffect::getService(const std::string &serviceName, const bool getStub) {
    return ::android::hardware::details::getServiceInternal<BpHwEnvironmentalReverbEffect>(serviceName, true, getStub);
}

::android::status_t IEnvironmentalReverbEffect::registerAsService(const std::string &serviceName) {
    return ::android::hardware::details::registerAsServiceInternal(this, serviceName);
}

bool IEnvironmentalReverbEffect::registerForNotifications(
        const std::string &serviceName,
        const ::android::sp<::android::hidl::manager::V1_0::IServiceNotification> &notification) {
    const ::android::sp<::android::hidl::manager::V1_0::IServiceManager> sm
            = ::android::hardware::defaultServiceManager();
    if (sm == nullptr) {
        return false;
    }
    ::android::hardware::Return<bool> success =
            sm->registerForNotifications("android.hardware.audio.effect@4.0::IEnvironmentalReverbEffect",
                    serviceName, notification);
    return success.isOk() && success;
}

static_assert(sizeof(::android::hardware::MQDescriptor<char, ::android::hardware::kSynchronizedReadWrite>) == 32, "wrong size");
static_assert(sizeof(::android::hardware::hidl_handle) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_memory) == 40, "wrong size");
static_assert(sizeof(::android::hardware::hidl_string) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_vec<char>) == 16, "wrong size");

}  // namespace V4_0
}  // namespace effect
}  // namespace audio
}  // namespace hardware
}  // namespace android
