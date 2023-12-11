#define LOG_TAG "android.hardware.audio@7.0::PrimaryDevice"

#include <log/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <hidl/Static.h>
#include <hwbinder/ProcessState.h>
#include <utils/Trace.h>
#include <android/hidl/manager/1.0/IServiceManager.h>
#include <android/hardware/audio/7.0/BpHwPrimaryDevice.h>
#include <android/hardware/audio/7.0/BnHwPrimaryDevice.h>
#include <android/hardware/audio/7.0/BsPrimaryDevice.h>
#include <android/hardware/audio/7.0/BpHwDevice.h>
#include <android/hidl/base/1.0/BpHwBase.h>
#include <hidl/ServiceManagement.h>

namespace android {
namespace hardware {
namespace audio {
namespace V7_0 {

const char* IPrimaryDevice::descriptor("android.hardware.audio@7.0::IPrimaryDevice");

__attribute__((constructor)) static void static_constructor() {
    ::android::hardware::details::getBnConstructorMap().set(IPrimaryDevice::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hardware::IBinder> {
                return new BnHwPrimaryDevice(static_cast<IPrimaryDevice *>(iIntf));
            });
    ::android::hardware::details::getBsConstructorMap().set(IPrimaryDevice::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hidl::base::V1_0::IBase> {
                return new BsPrimaryDevice(static_cast<IPrimaryDevice *>(iIntf));
            });
}

__attribute__((destructor))static void static_destructor() {
    ::android::hardware::details::getBnConstructorMap().erase(IPrimaryDevice::descriptor);
    ::android::hardware::details::getBsConstructorMap().erase(IPrimaryDevice::descriptor);
}

// Methods from ::android::hardware::audio::V7_0::IDevice follow.
// no default implementation for: ::android::hardware::Return<::android::hardware::audio::V7_0::Result> IPrimaryDevice::initCheck()
// no default implementation for: ::android::hardware::Return<::android::hardware::audio::V7_0::Result> IPrimaryDevice::setMasterVolume(float volume)
// no default implementation for: ::android::hardware::Return<void> IPrimaryDevice::getMasterVolume(getMasterVolume_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<::android::hardware::audio::V7_0::Result> IPrimaryDevice::setMicMute(bool mute)
// no default implementation for: ::android::hardware::Return<void> IPrimaryDevice::getMicMute(getMicMute_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<::android::hardware::audio::V7_0::Result> IPrimaryDevice::setMasterMute(bool mute)
// no default implementation for: ::android::hardware::Return<void> IPrimaryDevice::getMasterMute(getMasterMute_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IPrimaryDevice::getInputBufferSize(const ::android::hardware::audio::common::V7_0::AudioConfig& config, getInputBufferSize_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IPrimaryDevice::openOutputStream(int32_t ioHandle, const ::android::hardware::audio::common::V7_0::DeviceAddress& device, const ::android::hardware::audio::common::V7_0::AudioConfig& config, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& flags, const ::android::hardware::audio::common::V7_0::SourceMetadata& sourceMetadata, openOutputStream_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IPrimaryDevice::openInputStream(int32_t ioHandle, const ::android::hardware::audio::common::V7_0::DeviceAddress& device, const ::android::hardware::audio::common::V7_0::AudioConfig& config, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& flags, const ::android::hardware::audio::common::V7_0::SinkMetadata& sinkMetadata, openInputStream_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<bool> IPrimaryDevice::supportsAudioPatches()
// no default implementation for: ::android::hardware::Return<void> IPrimaryDevice::createAudioPatch(const ::android::hardware::hidl_vec<::android::hardware::audio::common::V7_0::AudioPortConfig>& sources, const ::android::hardware::hidl_vec<::android::hardware::audio::common::V7_0::AudioPortConfig>& sinks, createAudioPatch_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IPrimaryDevice::updateAudioPatch(int32_t previousPatch, const ::android::hardware::hidl_vec<::android::hardware::audio::common::V7_0::AudioPortConfig>& sources, const ::android::hardware::hidl_vec<::android::hardware::audio::common::V7_0::AudioPortConfig>& sinks, updateAudioPatch_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<::android::hardware::audio::V7_0::Result> IPrimaryDevice::releaseAudioPatch(int32_t patch)
// no default implementation for: ::android::hardware::Return<void> IPrimaryDevice::getAudioPort(const ::android::hardware::audio::common::V7_0::AudioPort& port, getAudioPort_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<::android::hardware::audio::V7_0::Result> IPrimaryDevice::setAudioPortConfig(const ::android::hardware::audio::common::V7_0::AudioPortConfig& config)
// no default implementation for: ::android::hardware::Return<void> IPrimaryDevice::getHwAvSync(getHwAvSync_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<::android::hardware::audio::V7_0::Result> IPrimaryDevice::setScreenState(bool turnedOn)
// no default implementation for: ::android::hardware::Return<void> IPrimaryDevice::getParameters(const ::android::hardware::hidl_vec<::android::hardware::audio::V7_0::ParameterValue>& context, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& keys, getParameters_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<::android::hardware::audio::V7_0::Result> IPrimaryDevice::setParameters(const ::android::hardware::hidl_vec<::android::hardware::audio::V7_0::ParameterValue>& context, const ::android::hardware::hidl_vec<::android::hardware::audio::V7_0::ParameterValue>& parameters)
// no default implementation for: ::android::hardware::Return<void> IPrimaryDevice::getMicrophones(getMicrophones_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<::android::hardware::audio::V7_0::Result> IPrimaryDevice::setConnectedState(const ::android::hardware::audio::common::V7_0::DeviceAddress& address, bool connected)
// no default implementation for: ::android::hardware::Return<::android::hardware::audio::V7_0::Result> IPrimaryDevice::close()
// no default implementation for: ::android::hardware::Return<::android::hardware::audio::V7_0::Result> IPrimaryDevice::addDeviceEffect(int32_t device, uint64_t effectId)
// no default implementation for: ::android::hardware::Return<::android::hardware::audio::V7_0::Result> IPrimaryDevice::removeDeviceEffect(int32_t device, uint64_t effectId)

// Methods from ::android::hardware::audio::V7_0::IPrimaryDevice follow.
// no default implementation for: ::android::hardware::Return<::android::hardware::audio::V7_0::Result> IPrimaryDevice::setVoiceVolume(float volume)
// no default implementation for: ::android::hardware::Return<::android::hardware::audio::V7_0::Result> IPrimaryDevice::setMode(::android::hardware::audio::common::V7_0::AudioMode mode)
// no default implementation for: ::android::hardware::Return<::android::hardware::audio::V7_0::Result> IPrimaryDevice::setBtScoHeadsetDebugName(const ::android::hardware::hidl_string& name)
// no default implementation for: ::android::hardware::Return<void> IPrimaryDevice::getBtScoNrecEnabled(getBtScoNrecEnabled_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<::android::hardware::audio::V7_0::Result> IPrimaryDevice::setBtScoNrecEnabled(bool enabled)
// no default implementation for: ::android::hardware::Return<void> IPrimaryDevice::getBtScoWidebandEnabled(getBtScoWidebandEnabled_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<::android::hardware::audio::V7_0::Result> IPrimaryDevice::setBtScoWidebandEnabled(bool enabled)
// no default implementation for: ::android::hardware::Return<void> IPrimaryDevice::getBtHfpEnabled(getBtHfpEnabled_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<::android::hardware::audio::V7_0::Result> IPrimaryDevice::setBtHfpEnabled(bool enabled)
// no default implementation for: ::android::hardware::Return<::android::hardware::audio::V7_0::Result> IPrimaryDevice::setBtHfpSampleRate(uint32_t sampleRateHz)
// no default implementation for: ::android::hardware::Return<::android::hardware::audio::V7_0::Result> IPrimaryDevice::setBtHfpVolume(float volume)
// no default implementation for: ::android::hardware::Return<void> IPrimaryDevice::getTtyMode(getTtyMode_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<::android::hardware::audio::V7_0::Result> IPrimaryDevice::setTtyMode(::android::hardware::audio::V7_0::IPrimaryDevice::TtyMode mode)
// no default implementation for: ::android::hardware::Return<void> IPrimaryDevice::getHacEnabled(getHacEnabled_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<::android::hardware::audio::V7_0::Result> IPrimaryDevice::setHacEnabled(bool enabled)
// no default implementation for: ::android::hardware::Return<::android::hardware::audio::V7_0::Result> IPrimaryDevice::updateRotation(::android::hardware::audio::V7_0::IPrimaryDevice::Rotation rotation)

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> IPrimaryDevice::interfaceChain(interfaceChain_cb _hidl_cb){
    _hidl_cb({
        ::android::hardware::audio::V7_0::IPrimaryDevice::descriptor,
        ::android::hardware::audio::V7_0::IDevice::descriptor,
        ::android::hidl::base::V1_0::IBase::descriptor,
    });
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IPrimaryDevice::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    (void)fd;
    (void)options;
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IPrimaryDevice::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    _hidl_cb(::android::hardware::audio::V7_0::IPrimaryDevice::descriptor);
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IPrimaryDevice::getHashChain(getHashChain_cb _hidl_cb){
    _hidl_cb({
        (uint8_t[32]){29,32,30,21,197,83,205,68,198,40,100,172,141,112,57,53,29,223,4,138,126,230,30,56,15,110,251,9,4,68,46,184} /* 1d201e15c553cd44c62864ac8d7039351ddf048a7ee61e380f6efb0904442eb8 */,
        (uint8_t[32]){89,250,104,67,46,55,76,141,59,126,192,152,169,26,30,2,58,44,114,129,16,187,115,50,55,197,81,175,165,146,151,37} /* 59fa68432e374c8d3b7ec098a91a1e023a2c728110bb733237c551afa5929725 */,
        (uint8_t[32]){236,127,215,158,208,45,250,133,188,73,148,38,173,174,62,190,35,239,5,36,243,205,105,87,19,147,36,184,59,24,202,76} /* ec7fd79ed02dfa85bc499426adae3ebe23ef0524f3cd6957139324b83b18ca4c */});
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IPrimaryDevice::setHALInstrumentation(){
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> IPrimaryDevice::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    (void)cookie;
    return (recipient != nullptr);
}

::android::hardware::Return<void> IPrimaryDevice::ping(){
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IPrimaryDevice::getDebugInfo(getDebugInfo_cb _hidl_cb){
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

::android::hardware::Return<void> IPrimaryDevice::notifySyspropsChanged(){
    ::android::report_sysprop_change();
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> IPrimaryDevice::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
    return (recipient != nullptr);
}


::android::hardware::Return<::android::sp<::android::hardware::audio::V7_0::IPrimaryDevice>> IPrimaryDevice::castFrom(const ::android::sp<::android::hardware::audio::V7_0::IPrimaryDevice>& parent, bool /* emitError */) {
    return parent;
}

::android::hardware::Return<::android::sp<::android::hardware::audio::V7_0::IPrimaryDevice>> IPrimaryDevice::castFrom(const ::android::sp<::android::hardware::audio::V7_0::IDevice>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<IPrimaryDevice, ::android::hardware::audio::V7_0::IDevice, BpHwPrimaryDevice>(
            parent, "android.hardware.audio@7.0::IPrimaryDevice", emitError);
}

::android::hardware::Return<::android::sp<::android::hardware::audio::V7_0::IPrimaryDevice>> IPrimaryDevice::castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<IPrimaryDevice, ::android::hidl::base::V1_0::IBase, BpHwPrimaryDevice>(
            parent, "android.hardware.audio@7.0::IPrimaryDevice", emitError);
}

BpHwPrimaryDevice::BpHwPrimaryDevice(const ::android::sp<::android::hardware::IBinder> &_hidl_impl)
        : BpInterface<IPrimaryDevice>(_hidl_impl),
          ::android::hardware::details::HidlInstrumentor("android.hardware.audio@7.0", "IPrimaryDevice") {
}

void BpHwPrimaryDevice::onLastStrongRef(const void* id) {
    {
        std::unique_lock<std::mutex> lock(_hidl_mMutex);
        _hidl_mDeathRecipients.clear();
    }

    BpInterface<IPrimaryDevice>::onLastStrongRef(id);
}
// Methods from ::android::hardware::audio::V7_0::IPrimaryDevice follow.
::android::hardware::Return<::android::hardware::audio::V7_0::Result> BpHwPrimaryDevice::_hidl_setVoiceVolume(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, float volume) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IPrimaryDevice::setVoiceVolume::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&volume);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.audio", "7.0", "IPrimaryDevice", "setVoiceVolume", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    ::android::hardware::audio::V7_0::Result _hidl_out_retval;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwPrimaryDevice::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeFloat(volume);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(26 /* setVoiceVolume */, _hidl_data, &_hidl_reply, 0 /* flags */);
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
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.audio", "7.0", "IPrimaryDevice", "setVoiceVolume", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<::android::hardware::audio::V7_0::Result>(_hidl_out_retval);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<::android::hardware::audio::V7_0::Result>(_hidl_status);
}

::android::hardware::Return<::android::hardware::audio::V7_0::Result> BpHwPrimaryDevice::_hidl_setMode(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, ::android::hardware::audio::common::V7_0::AudioMode mode) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IPrimaryDevice::setMode::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&mode);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.audio", "7.0", "IPrimaryDevice", "setMode", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    ::android::hardware::audio::V7_0::Result _hidl_out_retval;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwPrimaryDevice::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32((int32_t)mode);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(27 /* setMode */, _hidl_data, &_hidl_reply, 0 /* flags */);
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
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.audio", "7.0", "IPrimaryDevice", "setMode", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<::android::hardware::audio::V7_0::Result>(_hidl_out_retval);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<::android::hardware::audio::V7_0::Result>(_hidl_status);
}

::android::hardware::Return<::android::hardware::audio::V7_0::Result> BpHwPrimaryDevice::_hidl_setBtScoHeadsetDebugName(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::hidl_string& name) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IPrimaryDevice::setBtScoHeadsetDebugName::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&name);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.audio", "7.0", "IPrimaryDevice", "setBtScoHeadsetDebugName", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    ::android::hardware::audio::V7_0::Result _hidl_out_retval;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwPrimaryDevice::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_name_parent;

    _hidl_err = _hidl_data.writeBuffer(&name, sizeof(name), &_hidl_name_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            name,
            &_hidl_data,
            _hidl_name_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(28 /* setBtScoHeadsetDebugName */, _hidl_data, &_hidl_reply, 0 /* flags */);
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
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.audio", "7.0", "IPrimaryDevice", "setBtScoHeadsetDebugName", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<::android::hardware::audio::V7_0::Result>(_hidl_out_retval);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<::android::hardware::audio::V7_0::Result>(_hidl_status);
}

::android::hardware::Return<void> BpHwPrimaryDevice::_hidl_getBtScoNrecEnabled(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, getBtScoNrecEnabled_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IPrimaryDevice::getBtScoNrecEnabled::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.audio", "7.0", "IPrimaryDevice", "getBtScoNrecEnabled", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwPrimaryDevice::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(29 /* getBtScoNrecEnabled */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::audio::V7_0::Result _hidl_out_retval;
        bool _hidl_out_enabled;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_retval);
        if (_hidl_err != ::android::OK) { return; }

        _hidl_err = _hidl_reply.readBool(&_hidl_out_enabled);
        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(_hidl_out_retval, _hidl_out_enabled);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_retval);
            _hidl_args.push_back((void *)&_hidl_out_enabled);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.audio", "7.0", "IPrimaryDevice", "getBtScoNrecEnabled", &_hidl_args);
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

::android::hardware::Return<::android::hardware::audio::V7_0::Result> BpHwPrimaryDevice::_hidl_setBtScoNrecEnabled(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, bool enabled) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IPrimaryDevice::setBtScoNrecEnabled::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&enabled);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.audio", "7.0", "IPrimaryDevice", "setBtScoNrecEnabled", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    ::android::hardware::audio::V7_0::Result _hidl_out_retval;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwPrimaryDevice::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeBool(enabled);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(30 /* setBtScoNrecEnabled */, _hidl_data, &_hidl_reply, 0 /* flags */);
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
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.audio", "7.0", "IPrimaryDevice", "setBtScoNrecEnabled", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<::android::hardware::audio::V7_0::Result>(_hidl_out_retval);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<::android::hardware::audio::V7_0::Result>(_hidl_status);
}

::android::hardware::Return<void> BpHwPrimaryDevice::_hidl_getBtScoWidebandEnabled(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, getBtScoWidebandEnabled_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IPrimaryDevice::getBtScoWidebandEnabled::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.audio", "7.0", "IPrimaryDevice", "getBtScoWidebandEnabled", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwPrimaryDevice::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(31 /* getBtScoWidebandEnabled */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::audio::V7_0::Result _hidl_out_retval;
        bool _hidl_out_enabled;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_retval);
        if (_hidl_err != ::android::OK) { return; }

        _hidl_err = _hidl_reply.readBool(&_hidl_out_enabled);
        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(_hidl_out_retval, _hidl_out_enabled);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_retval);
            _hidl_args.push_back((void *)&_hidl_out_enabled);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.audio", "7.0", "IPrimaryDevice", "getBtScoWidebandEnabled", &_hidl_args);
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

::android::hardware::Return<::android::hardware::audio::V7_0::Result> BpHwPrimaryDevice::_hidl_setBtScoWidebandEnabled(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, bool enabled) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IPrimaryDevice::setBtScoWidebandEnabled::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&enabled);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.audio", "7.0", "IPrimaryDevice", "setBtScoWidebandEnabled", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    ::android::hardware::audio::V7_0::Result _hidl_out_retval;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwPrimaryDevice::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeBool(enabled);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(32 /* setBtScoWidebandEnabled */, _hidl_data, &_hidl_reply, 0 /* flags */);
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
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.audio", "7.0", "IPrimaryDevice", "setBtScoWidebandEnabled", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<::android::hardware::audio::V7_0::Result>(_hidl_out_retval);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<::android::hardware::audio::V7_0::Result>(_hidl_status);
}

::android::hardware::Return<void> BpHwPrimaryDevice::_hidl_getBtHfpEnabled(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, getBtHfpEnabled_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IPrimaryDevice::getBtHfpEnabled::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.audio", "7.0", "IPrimaryDevice", "getBtHfpEnabled", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwPrimaryDevice::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(33 /* getBtHfpEnabled */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::audio::V7_0::Result _hidl_out_retval;
        bool _hidl_out_enabled;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_retval);
        if (_hidl_err != ::android::OK) { return; }

        _hidl_err = _hidl_reply.readBool(&_hidl_out_enabled);
        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(_hidl_out_retval, _hidl_out_enabled);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_retval);
            _hidl_args.push_back((void *)&_hidl_out_enabled);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.audio", "7.0", "IPrimaryDevice", "getBtHfpEnabled", &_hidl_args);
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

::android::hardware::Return<::android::hardware::audio::V7_0::Result> BpHwPrimaryDevice::_hidl_setBtHfpEnabled(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, bool enabled) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IPrimaryDevice::setBtHfpEnabled::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&enabled);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.audio", "7.0", "IPrimaryDevice", "setBtHfpEnabled", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    ::android::hardware::audio::V7_0::Result _hidl_out_retval;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwPrimaryDevice::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeBool(enabled);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(34 /* setBtHfpEnabled */, _hidl_data, &_hidl_reply, 0 /* flags */);
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
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.audio", "7.0", "IPrimaryDevice", "setBtHfpEnabled", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<::android::hardware::audio::V7_0::Result>(_hidl_out_retval);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<::android::hardware::audio::V7_0::Result>(_hidl_status);
}

::android::hardware::Return<::android::hardware::audio::V7_0::Result> BpHwPrimaryDevice::_hidl_setBtHfpSampleRate(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint32_t sampleRateHz) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IPrimaryDevice::setBtHfpSampleRate::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&sampleRateHz);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.audio", "7.0", "IPrimaryDevice", "setBtHfpSampleRate", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    ::android::hardware::audio::V7_0::Result _hidl_out_retval;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwPrimaryDevice::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(sampleRateHz);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(35 /* setBtHfpSampleRate */, _hidl_data, &_hidl_reply, 0 /* flags */);
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
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.audio", "7.0", "IPrimaryDevice", "setBtHfpSampleRate", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<::android::hardware::audio::V7_0::Result>(_hidl_out_retval);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<::android::hardware::audio::V7_0::Result>(_hidl_status);
}

::android::hardware::Return<::android::hardware::audio::V7_0::Result> BpHwPrimaryDevice::_hidl_setBtHfpVolume(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, float volume) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IPrimaryDevice::setBtHfpVolume::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&volume);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.audio", "7.0", "IPrimaryDevice", "setBtHfpVolume", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    ::android::hardware::audio::V7_0::Result _hidl_out_retval;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwPrimaryDevice::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeFloat(volume);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(36 /* setBtHfpVolume */, _hidl_data, &_hidl_reply, 0 /* flags */);
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
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.audio", "7.0", "IPrimaryDevice", "setBtHfpVolume", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<::android::hardware::audio::V7_0::Result>(_hidl_out_retval);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<::android::hardware::audio::V7_0::Result>(_hidl_status);
}

::android::hardware::Return<void> BpHwPrimaryDevice::_hidl_getTtyMode(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, getTtyMode_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IPrimaryDevice::getTtyMode::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.audio", "7.0", "IPrimaryDevice", "getTtyMode", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwPrimaryDevice::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(37 /* getTtyMode */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::audio::V7_0::Result _hidl_out_retval;
        ::android::hardware::audio::V7_0::IPrimaryDevice::TtyMode _hidl_out_mode;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_retval);
        if (_hidl_err != ::android::OK) { return; }

        _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_mode);
        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(_hidl_out_retval, _hidl_out_mode);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_retval);
            _hidl_args.push_back((void *)&_hidl_out_mode);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.audio", "7.0", "IPrimaryDevice", "getTtyMode", &_hidl_args);
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

::android::hardware::Return<::android::hardware::audio::V7_0::Result> BpHwPrimaryDevice::_hidl_setTtyMode(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, ::android::hardware::audio::V7_0::IPrimaryDevice::TtyMode mode) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IPrimaryDevice::setTtyMode::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&mode);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.audio", "7.0", "IPrimaryDevice", "setTtyMode", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    ::android::hardware::audio::V7_0::Result _hidl_out_retval;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwPrimaryDevice::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32((int32_t)mode);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(38 /* setTtyMode */, _hidl_data, &_hidl_reply, 0 /* flags */);
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
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.audio", "7.0", "IPrimaryDevice", "setTtyMode", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<::android::hardware::audio::V7_0::Result>(_hidl_out_retval);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<::android::hardware::audio::V7_0::Result>(_hidl_status);
}

::android::hardware::Return<void> BpHwPrimaryDevice::_hidl_getHacEnabled(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, getHacEnabled_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IPrimaryDevice::getHacEnabled::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.audio", "7.0", "IPrimaryDevice", "getHacEnabled", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwPrimaryDevice::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(39 /* getHacEnabled */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::audio::V7_0::Result _hidl_out_retval;
        bool _hidl_out_enabled;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_retval);
        if (_hidl_err != ::android::OK) { return; }

        _hidl_err = _hidl_reply.readBool(&_hidl_out_enabled);
        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(_hidl_out_retval, _hidl_out_enabled);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_retval);
            _hidl_args.push_back((void *)&_hidl_out_enabled);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.audio", "7.0", "IPrimaryDevice", "getHacEnabled", &_hidl_args);
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

::android::hardware::Return<::android::hardware::audio::V7_0::Result> BpHwPrimaryDevice::_hidl_setHacEnabled(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, bool enabled) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IPrimaryDevice::setHacEnabled::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&enabled);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.audio", "7.0", "IPrimaryDevice", "setHacEnabled", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    ::android::hardware::audio::V7_0::Result _hidl_out_retval;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwPrimaryDevice::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeBool(enabled);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(40 /* setHacEnabled */, _hidl_data, &_hidl_reply, 0 /* flags */);
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
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.audio", "7.0", "IPrimaryDevice", "setHacEnabled", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<::android::hardware::audio::V7_0::Result>(_hidl_out_retval);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<::android::hardware::audio::V7_0::Result>(_hidl_status);
}

::android::hardware::Return<::android::hardware::audio::V7_0::Result> BpHwPrimaryDevice::_hidl_updateRotation(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, ::android::hardware::audio::V7_0::IPrimaryDevice::Rotation rotation) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IPrimaryDevice::updateRotation::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&rotation);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.audio", "7.0", "IPrimaryDevice", "updateRotation", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    ::android::hardware::audio::V7_0::Result _hidl_out_retval;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwPrimaryDevice::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32((int32_t)rotation);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(41 /* updateRotation */, _hidl_data, &_hidl_reply, 0 /* flags */);
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
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.audio", "7.0", "IPrimaryDevice", "updateRotation", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<::android::hardware::audio::V7_0::Result>(_hidl_out_retval);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<::android::hardware::audio::V7_0::Result>(_hidl_status);
}


// Methods from ::android::hardware::audio::V7_0::IDevice follow.
::android::hardware::Return<::android::hardware::audio::V7_0::Result> BpHwPrimaryDevice::initCheck(){
    ::android::hardware::Return<::android::hardware::audio::V7_0::Result>  _hidl_out = ::android::hardware::audio::V7_0::BpHwDevice::_hidl_initCheck(this, this);

    return _hidl_out;
}

::android::hardware::Return<::android::hardware::audio::V7_0::Result> BpHwPrimaryDevice::setMasterVolume(float volume){
    ::android::hardware::Return<::android::hardware::audio::V7_0::Result>  _hidl_out = ::android::hardware::audio::V7_0::BpHwDevice::_hidl_setMasterVolume(this, this, volume);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwPrimaryDevice::getMasterVolume(getMasterVolume_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::audio::V7_0::BpHwDevice::_hidl_getMasterVolume(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<::android::hardware::audio::V7_0::Result> BpHwPrimaryDevice::setMicMute(bool mute){
    ::android::hardware::Return<::android::hardware::audio::V7_0::Result>  _hidl_out = ::android::hardware::audio::V7_0::BpHwDevice::_hidl_setMicMute(this, this, mute);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwPrimaryDevice::getMicMute(getMicMute_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::audio::V7_0::BpHwDevice::_hidl_getMicMute(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<::android::hardware::audio::V7_0::Result> BpHwPrimaryDevice::setMasterMute(bool mute){
    ::android::hardware::Return<::android::hardware::audio::V7_0::Result>  _hidl_out = ::android::hardware::audio::V7_0::BpHwDevice::_hidl_setMasterMute(this, this, mute);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwPrimaryDevice::getMasterMute(getMasterMute_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::audio::V7_0::BpHwDevice::_hidl_getMasterMute(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwPrimaryDevice::getInputBufferSize(const ::android::hardware::audio::common::V7_0::AudioConfig& config, getInputBufferSize_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::audio::V7_0::BpHwDevice::_hidl_getInputBufferSize(this, this, config, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwPrimaryDevice::openOutputStream(int32_t ioHandle, const ::android::hardware::audio::common::V7_0::DeviceAddress& device, const ::android::hardware::audio::common::V7_0::AudioConfig& config, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& flags, const ::android::hardware::audio::common::V7_0::SourceMetadata& sourceMetadata, openOutputStream_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::audio::V7_0::BpHwDevice::_hidl_openOutputStream(this, this, ioHandle, device, config, flags, sourceMetadata, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwPrimaryDevice::openInputStream(int32_t ioHandle, const ::android::hardware::audio::common::V7_0::DeviceAddress& device, const ::android::hardware::audio::common::V7_0::AudioConfig& config, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& flags, const ::android::hardware::audio::common::V7_0::SinkMetadata& sinkMetadata, openInputStream_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::audio::V7_0::BpHwDevice::_hidl_openInputStream(this, this, ioHandle, device, config, flags, sinkMetadata, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwPrimaryDevice::supportsAudioPatches(){
    ::android::hardware::Return<bool>  _hidl_out = ::android::hardware::audio::V7_0::BpHwDevice::_hidl_supportsAudioPatches(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwPrimaryDevice::createAudioPatch(const ::android::hardware::hidl_vec<::android::hardware::audio::common::V7_0::AudioPortConfig>& sources, const ::android::hardware::hidl_vec<::android::hardware::audio::common::V7_0::AudioPortConfig>& sinks, createAudioPatch_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::audio::V7_0::BpHwDevice::_hidl_createAudioPatch(this, this, sources, sinks, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwPrimaryDevice::updateAudioPatch(int32_t previousPatch, const ::android::hardware::hidl_vec<::android::hardware::audio::common::V7_0::AudioPortConfig>& sources, const ::android::hardware::hidl_vec<::android::hardware::audio::common::V7_0::AudioPortConfig>& sinks, updateAudioPatch_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::audio::V7_0::BpHwDevice::_hidl_updateAudioPatch(this, this, previousPatch, sources, sinks, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<::android::hardware::audio::V7_0::Result> BpHwPrimaryDevice::releaseAudioPatch(int32_t patch){
    ::android::hardware::Return<::android::hardware::audio::V7_0::Result>  _hidl_out = ::android::hardware::audio::V7_0::BpHwDevice::_hidl_releaseAudioPatch(this, this, patch);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwPrimaryDevice::getAudioPort(const ::android::hardware::audio::common::V7_0::AudioPort& port, getAudioPort_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::audio::V7_0::BpHwDevice::_hidl_getAudioPort(this, this, port, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<::android::hardware::audio::V7_0::Result> BpHwPrimaryDevice::setAudioPortConfig(const ::android::hardware::audio::common::V7_0::AudioPortConfig& config){
    ::android::hardware::Return<::android::hardware::audio::V7_0::Result>  _hidl_out = ::android::hardware::audio::V7_0::BpHwDevice::_hidl_setAudioPortConfig(this, this, config);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwPrimaryDevice::getHwAvSync(getHwAvSync_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::audio::V7_0::BpHwDevice::_hidl_getHwAvSync(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<::android::hardware::audio::V7_0::Result> BpHwPrimaryDevice::setScreenState(bool turnedOn){
    ::android::hardware::Return<::android::hardware::audio::V7_0::Result>  _hidl_out = ::android::hardware::audio::V7_0::BpHwDevice::_hidl_setScreenState(this, this, turnedOn);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwPrimaryDevice::getParameters(const ::android::hardware::hidl_vec<::android::hardware::audio::V7_0::ParameterValue>& context, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& keys, getParameters_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::audio::V7_0::BpHwDevice::_hidl_getParameters(this, this, context, keys, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<::android::hardware::audio::V7_0::Result> BpHwPrimaryDevice::setParameters(const ::android::hardware::hidl_vec<::android::hardware::audio::V7_0::ParameterValue>& context, const ::android::hardware::hidl_vec<::android::hardware::audio::V7_0::ParameterValue>& parameters){
    ::android::hardware::Return<::android::hardware::audio::V7_0::Result>  _hidl_out = ::android::hardware::audio::V7_0::BpHwDevice::_hidl_setParameters(this, this, context, parameters);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwPrimaryDevice::getMicrophones(getMicrophones_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::audio::V7_0::BpHwDevice::_hidl_getMicrophones(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<::android::hardware::audio::V7_0::Result> BpHwPrimaryDevice::setConnectedState(const ::android::hardware::audio::common::V7_0::DeviceAddress& address, bool connected){
    ::android::hardware::Return<::android::hardware::audio::V7_0::Result>  _hidl_out = ::android::hardware::audio::V7_0::BpHwDevice::_hidl_setConnectedState(this, this, address, connected);

    return _hidl_out;
}

::android::hardware::Return<::android::hardware::audio::V7_0::Result> BpHwPrimaryDevice::close(){
    ::android::hardware::Return<::android::hardware::audio::V7_0::Result>  _hidl_out = ::android::hardware::audio::V7_0::BpHwDevice::_hidl_close(this, this);

    return _hidl_out;
}

::android::hardware::Return<::android::hardware::audio::V7_0::Result> BpHwPrimaryDevice::addDeviceEffect(int32_t device, uint64_t effectId){
    ::android::hardware::Return<::android::hardware::audio::V7_0::Result>  _hidl_out = ::android::hardware::audio::V7_0::BpHwDevice::_hidl_addDeviceEffect(this, this, device, effectId);

    return _hidl_out;
}

::android::hardware::Return<::android::hardware::audio::V7_0::Result> BpHwPrimaryDevice::removeDeviceEffect(int32_t device, uint64_t effectId){
    ::android::hardware::Return<::android::hardware::audio::V7_0::Result>  _hidl_out = ::android::hardware::audio::V7_0::BpHwDevice::_hidl_removeDeviceEffect(this, this, device, effectId);

    return _hidl_out;
}


// Methods from ::android::hardware::audio::V7_0::IPrimaryDevice follow.
::android::hardware::Return<::android::hardware::audio::V7_0::Result> BpHwPrimaryDevice::setVoiceVolume(float volume){
    ::android::hardware::Return<::android::hardware::audio::V7_0::Result>  _hidl_out = ::android::hardware::audio::V7_0::BpHwPrimaryDevice::_hidl_setVoiceVolume(this, this, volume);

    return _hidl_out;
}

::android::hardware::Return<::android::hardware::audio::V7_0::Result> BpHwPrimaryDevice::setMode(::android::hardware::audio::common::V7_0::AudioMode mode){
    ::android::hardware::Return<::android::hardware::audio::V7_0::Result>  _hidl_out = ::android::hardware::audio::V7_0::BpHwPrimaryDevice::_hidl_setMode(this, this, mode);

    return _hidl_out;
}

::android::hardware::Return<::android::hardware::audio::V7_0::Result> BpHwPrimaryDevice::setBtScoHeadsetDebugName(const ::android::hardware::hidl_string& name){
    ::android::hardware::Return<::android::hardware::audio::V7_0::Result>  _hidl_out = ::android::hardware::audio::V7_0::BpHwPrimaryDevice::_hidl_setBtScoHeadsetDebugName(this, this, name);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwPrimaryDevice::getBtScoNrecEnabled(getBtScoNrecEnabled_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::audio::V7_0::BpHwPrimaryDevice::_hidl_getBtScoNrecEnabled(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<::android::hardware::audio::V7_0::Result> BpHwPrimaryDevice::setBtScoNrecEnabled(bool enabled){
    ::android::hardware::Return<::android::hardware::audio::V7_0::Result>  _hidl_out = ::android::hardware::audio::V7_0::BpHwPrimaryDevice::_hidl_setBtScoNrecEnabled(this, this, enabled);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwPrimaryDevice::getBtScoWidebandEnabled(getBtScoWidebandEnabled_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::audio::V7_0::BpHwPrimaryDevice::_hidl_getBtScoWidebandEnabled(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<::android::hardware::audio::V7_0::Result> BpHwPrimaryDevice::setBtScoWidebandEnabled(bool enabled){
    ::android::hardware::Return<::android::hardware::audio::V7_0::Result>  _hidl_out = ::android::hardware::audio::V7_0::BpHwPrimaryDevice::_hidl_setBtScoWidebandEnabled(this, this, enabled);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwPrimaryDevice::getBtHfpEnabled(getBtHfpEnabled_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::audio::V7_0::BpHwPrimaryDevice::_hidl_getBtHfpEnabled(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<::android::hardware::audio::V7_0::Result> BpHwPrimaryDevice::setBtHfpEnabled(bool enabled){
    ::android::hardware::Return<::android::hardware::audio::V7_0::Result>  _hidl_out = ::android::hardware::audio::V7_0::BpHwPrimaryDevice::_hidl_setBtHfpEnabled(this, this, enabled);

    return _hidl_out;
}

::android::hardware::Return<::android::hardware::audio::V7_0::Result> BpHwPrimaryDevice::setBtHfpSampleRate(uint32_t sampleRateHz){
    ::android::hardware::Return<::android::hardware::audio::V7_0::Result>  _hidl_out = ::android::hardware::audio::V7_0::BpHwPrimaryDevice::_hidl_setBtHfpSampleRate(this, this, sampleRateHz);

    return _hidl_out;
}

::android::hardware::Return<::android::hardware::audio::V7_0::Result> BpHwPrimaryDevice::setBtHfpVolume(float volume){
    ::android::hardware::Return<::android::hardware::audio::V7_0::Result>  _hidl_out = ::android::hardware::audio::V7_0::BpHwPrimaryDevice::_hidl_setBtHfpVolume(this, this, volume);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwPrimaryDevice::getTtyMode(getTtyMode_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::audio::V7_0::BpHwPrimaryDevice::_hidl_getTtyMode(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<::android::hardware::audio::V7_0::Result> BpHwPrimaryDevice::setTtyMode(::android::hardware::audio::V7_0::IPrimaryDevice::TtyMode mode){
    ::android::hardware::Return<::android::hardware::audio::V7_0::Result>  _hidl_out = ::android::hardware::audio::V7_0::BpHwPrimaryDevice::_hidl_setTtyMode(this, this, mode);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwPrimaryDevice::getHacEnabled(getHacEnabled_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::audio::V7_0::BpHwPrimaryDevice::_hidl_getHacEnabled(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<::android::hardware::audio::V7_0::Result> BpHwPrimaryDevice::setHacEnabled(bool enabled){
    ::android::hardware::Return<::android::hardware::audio::V7_0::Result>  _hidl_out = ::android::hardware::audio::V7_0::BpHwPrimaryDevice::_hidl_setHacEnabled(this, this, enabled);

    return _hidl_out;
}

::android::hardware::Return<::android::hardware::audio::V7_0::Result> BpHwPrimaryDevice::updateRotation(::android::hardware::audio::V7_0::IPrimaryDevice::Rotation rotation){
    ::android::hardware::Return<::android::hardware::audio::V7_0::Result>  _hidl_out = ::android::hardware::audio::V7_0::BpHwPrimaryDevice::_hidl_updateRotation(this, this, rotation);

    return _hidl_out;
}


// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BpHwPrimaryDevice::interfaceChain(interfaceChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwPrimaryDevice::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_debug(this, this, fd, options);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwPrimaryDevice::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceDescriptor(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwPrimaryDevice::getHashChain(getHashChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getHashChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwPrimaryDevice::setHALInstrumentation(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_setHALInstrumentation(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwPrimaryDevice::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    ::android::hardware::ProcessState::self()->startThreadPool();
    ::android::hardware::hidl_binder_death_recipient *binder_recipient = new ::android::hardware::hidl_binder_death_recipient(recipient, cookie, this);
    std::unique_lock<std::mutex> lock(_hidl_mMutex);
    _hidl_mDeathRecipients.push_back(binder_recipient);
    return (remote()->linkToDeath(binder_recipient) == ::android::OK);
}

::android::hardware::Return<void> BpHwPrimaryDevice::ping(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_ping(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwPrimaryDevice::getDebugInfo(getDebugInfo_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getDebugInfo(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwPrimaryDevice::notifySyspropsChanged(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_notifySyspropsChanged(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwPrimaryDevice::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
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


BnHwPrimaryDevice::BnHwPrimaryDevice(const ::android::sp<IPrimaryDevice> &_hidl_impl)
        : ::android::hidl::base::V1_0::BnHwBase(_hidl_impl, "android.hardware.audio@7.0", "IPrimaryDevice") { 
            _hidl_mImpl = _hidl_impl;
            auto prio = ::android::hardware::getMinSchedulerPolicy(_hidl_impl);
            mSchedPolicy = prio.sched_policy;
            mSchedPriority = prio.prio;
            setRequestingSid(::android::hardware::getRequestingSid(_hidl_impl));
}

BnHwPrimaryDevice::~BnHwPrimaryDevice() {
    ::android::hardware::details::gBnMap->eraseIfEqual(_hidl_mImpl.get(), this);
}

// Methods from ::android::hardware::audio::V7_0::IPrimaryDevice follow.
::android::status_t BnHwPrimaryDevice::_hidl_setVoiceVolume(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwPrimaryDevice::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    float volume;

    _hidl_err = _hidl_data.readFloat(&volume);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IPrimaryDevice::setVoiceVolume::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&volume);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.audio", "7.0", "IPrimaryDevice", "setVoiceVolume", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::audio::V7_0::Result _hidl_out_retval = static_cast<IPrimaryDevice*>(_hidl_this->getImpl().get())->setVoiceVolume(volume);

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
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.audio", "7.0", "IPrimaryDevice", "setVoiceVolume", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwPrimaryDevice::_hidl_setMode(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwPrimaryDevice::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::audio::common::V7_0::AudioMode mode;

    _hidl_err = _hidl_data.readInt32((int32_t *)&mode);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IPrimaryDevice::setMode::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&mode);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.audio", "7.0", "IPrimaryDevice", "setMode", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::audio::V7_0::Result _hidl_out_retval = static_cast<IPrimaryDevice*>(_hidl_this->getImpl().get())->setMode(mode);

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
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.audio", "7.0", "IPrimaryDevice", "setMode", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwPrimaryDevice::_hidl_setBtScoHeadsetDebugName(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwPrimaryDevice::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    const ::android::hardware::hidl_string* name;

    size_t _hidl_name_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*name), &_hidl_name_parent,  reinterpret_cast<const void **>(&name));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(*name),
            _hidl_data,
            _hidl_name_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IPrimaryDevice::setBtScoHeadsetDebugName::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)name);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.audio", "7.0", "IPrimaryDevice", "setBtScoHeadsetDebugName", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::audio::V7_0::Result _hidl_out_retval = static_cast<IPrimaryDevice*>(_hidl_this->getImpl().get())->setBtScoHeadsetDebugName(*name);

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
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.audio", "7.0", "IPrimaryDevice", "setBtScoHeadsetDebugName", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwPrimaryDevice::_hidl_getBtScoNrecEnabled(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwPrimaryDevice::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IPrimaryDevice::getBtScoNrecEnabled::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.audio", "7.0", "IPrimaryDevice", "getBtScoNrecEnabled", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IPrimaryDevice*>(_hidl_this->getImpl().get())->getBtScoNrecEnabled([&](const auto &_hidl_out_retval, const auto &_hidl_out_enabled) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("getBtScoNrecEnabled: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_retval);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_err = _hidl_reply->writeBool(_hidl_out_enabled);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_retval);
            _hidl_args.push_back((void *)&_hidl_out_enabled);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.audio", "7.0", "IPrimaryDevice", "getBtScoNrecEnabled", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("getBtScoNrecEnabled: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwPrimaryDevice::_hidl_setBtScoNrecEnabled(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwPrimaryDevice::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    bool enabled;

    _hidl_err = _hidl_data.readBool(&enabled);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IPrimaryDevice::setBtScoNrecEnabled::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&enabled);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.audio", "7.0", "IPrimaryDevice", "setBtScoNrecEnabled", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::audio::V7_0::Result _hidl_out_retval = static_cast<IPrimaryDevice*>(_hidl_this->getImpl().get())->setBtScoNrecEnabled(enabled);

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
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.audio", "7.0", "IPrimaryDevice", "setBtScoNrecEnabled", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwPrimaryDevice::_hidl_getBtScoWidebandEnabled(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwPrimaryDevice::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IPrimaryDevice::getBtScoWidebandEnabled::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.audio", "7.0", "IPrimaryDevice", "getBtScoWidebandEnabled", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IPrimaryDevice*>(_hidl_this->getImpl().get())->getBtScoWidebandEnabled([&](const auto &_hidl_out_retval, const auto &_hidl_out_enabled) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("getBtScoWidebandEnabled: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_retval);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_err = _hidl_reply->writeBool(_hidl_out_enabled);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_retval);
            _hidl_args.push_back((void *)&_hidl_out_enabled);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.audio", "7.0", "IPrimaryDevice", "getBtScoWidebandEnabled", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("getBtScoWidebandEnabled: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwPrimaryDevice::_hidl_setBtScoWidebandEnabled(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwPrimaryDevice::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    bool enabled;

    _hidl_err = _hidl_data.readBool(&enabled);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IPrimaryDevice::setBtScoWidebandEnabled::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&enabled);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.audio", "7.0", "IPrimaryDevice", "setBtScoWidebandEnabled", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::audio::V7_0::Result _hidl_out_retval = static_cast<IPrimaryDevice*>(_hidl_this->getImpl().get())->setBtScoWidebandEnabled(enabled);

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
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.audio", "7.0", "IPrimaryDevice", "setBtScoWidebandEnabled", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwPrimaryDevice::_hidl_getBtHfpEnabled(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwPrimaryDevice::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IPrimaryDevice::getBtHfpEnabled::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.audio", "7.0", "IPrimaryDevice", "getBtHfpEnabled", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IPrimaryDevice*>(_hidl_this->getImpl().get())->getBtHfpEnabled([&](const auto &_hidl_out_retval, const auto &_hidl_out_enabled) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("getBtHfpEnabled: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_retval);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_err = _hidl_reply->writeBool(_hidl_out_enabled);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_retval);
            _hidl_args.push_back((void *)&_hidl_out_enabled);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.audio", "7.0", "IPrimaryDevice", "getBtHfpEnabled", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("getBtHfpEnabled: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwPrimaryDevice::_hidl_setBtHfpEnabled(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwPrimaryDevice::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    bool enabled;

    _hidl_err = _hidl_data.readBool(&enabled);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IPrimaryDevice::setBtHfpEnabled::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&enabled);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.audio", "7.0", "IPrimaryDevice", "setBtHfpEnabled", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::audio::V7_0::Result _hidl_out_retval = static_cast<IPrimaryDevice*>(_hidl_this->getImpl().get())->setBtHfpEnabled(enabled);

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
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.audio", "7.0", "IPrimaryDevice", "setBtHfpEnabled", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwPrimaryDevice::_hidl_setBtHfpSampleRate(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwPrimaryDevice::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint32_t sampleRateHz;

    _hidl_err = _hidl_data.readUint32(&sampleRateHz);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IPrimaryDevice::setBtHfpSampleRate::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&sampleRateHz);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.audio", "7.0", "IPrimaryDevice", "setBtHfpSampleRate", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::audio::V7_0::Result _hidl_out_retval = static_cast<IPrimaryDevice*>(_hidl_this->getImpl().get())->setBtHfpSampleRate(sampleRateHz);

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
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.audio", "7.0", "IPrimaryDevice", "setBtHfpSampleRate", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwPrimaryDevice::_hidl_setBtHfpVolume(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwPrimaryDevice::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    float volume;

    _hidl_err = _hidl_data.readFloat(&volume);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IPrimaryDevice::setBtHfpVolume::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&volume);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.audio", "7.0", "IPrimaryDevice", "setBtHfpVolume", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::audio::V7_0::Result _hidl_out_retval = static_cast<IPrimaryDevice*>(_hidl_this->getImpl().get())->setBtHfpVolume(volume);

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
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.audio", "7.0", "IPrimaryDevice", "setBtHfpVolume", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwPrimaryDevice::_hidl_getTtyMode(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwPrimaryDevice::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IPrimaryDevice::getTtyMode::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.audio", "7.0", "IPrimaryDevice", "getTtyMode", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IPrimaryDevice*>(_hidl_this->getImpl().get())->getTtyMode([&](const auto &_hidl_out_retval, const auto &_hidl_out_mode) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("getTtyMode: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_retval);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_mode);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_retval);
            _hidl_args.push_back((void *)&_hidl_out_mode);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.audio", "7.0", "IPrimaryDevice", "getTtyMode", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("getTtyMode: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwPrimaryDevice::_hidl_setTtyMode(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwPrimaryDevice::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::audio::V7_0::IPrimaryDevice::TtyMode mode;

    _hidl_err = _hidl_data.readInt32((int32_t *)&mode);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IPrimaryDevice::setTtyMode::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&mode);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.audio", "7.0", "IPrimaryDevice", "setTtyMode", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::audio::V7_0::Result _hidl_out_retval = static_cast<IPrimaryDevice*>(_hidl_this->getImpl().get())->setTtyMode(mode);

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
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.audio", "7.0", "IPrimaryDevice", "setTtyMode", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwPrimaryDevice::_hidl_getHacEnabled(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwPrimaryDevice::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IPrimaryDevice::getHacEnabled::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.audio", "7.0", "IPrimaryDevice", "getHacEnabled", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IPrimaryDevice*>(_hidl_this->getImpl().get())->getHacEnabled([&](const auto &_hidl_out_retval, const auto &_hidl_out_enabled) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("getHacEnabled: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_retval);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_err = _hidl_reply->writeBool(_hidl_out_enabled);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_retval);
            _hidl_args.push_back((void *)&_hidl_out_enabled);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.audio", "7.0", "IPrimaryDevice", "getHacEnabled", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("getHacEnabled: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwPrimaryDevice::_hidl_setHacEnabled(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwPrimaryDevice::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    bool enabled;

    _hidl_err = _hidl_data.readBool(&enabled);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IPrimaryDevice::setHacEnabled::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&enabled);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.audio", "7.0", "IPrimaryDevice", "setHacEnabled", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::audio::V7_0::Result _hidl_out_retval = static_cast<IPrimaryDevice*>(_hidl_this->getImpl().get())->setHacEnabled(enabled);

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
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.audio", "7.0", "IPrimaryDevice", "setHacEnabled", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwPrimaryDevice::_hidl_updateRotation(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwPrimaryDevice::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::audio::V7_0::IPrimaryDevice::Rotation rotation;

    _hidl_err = _hidl_data.readInt32((int32_t *)&rotation);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IPrimaryDevice::updateRotation::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&rotation);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.audio", "7.0", "IPrimaryDevice", "updateRotation", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::audio::V7_0::Result _hidl_out_retval = static_cast<IPrimaryDevice*>(_hidl_this->getImpl().get())->updateRotation(rotation);

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
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.audio", "7.0", "IPrimaryDevice", "updateRotation", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}


// Methods from ::android::hardware::audio::V7_0::IDevice follow.

// Methods from ::android::hardware::audio::V7_0::IPrimaryDevice follow.

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BnHwPrimaryDevice::ping() {
    return ::android::hardware::Void();
}
::android::hardware::Return<void> BnHwPrimaryDevice::getDebugInfo(getDebugInfo_cb _hidl_cb) {
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

::android::status_t BnHwPrimaryDevice::onTransact(
        uint32_t _hidl_code,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        uint32_t _hidl_flags,
        TransactCallback _hidl_cb) {
    ::android::status_t _hidl_err = ::android::OK;

    switch (_hidl_code) {
        case 1 /* initCheck */:
        {
            _hidl_err = ::android::hardware::audio::V7_0::BnHwDevice::_hidl_initCheck(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 2 /* setMasterVolume */:
        {
            _hidl_err = ::android::hardware::audio::V7_0::BnHwDevice::_hidl_setMasterVolume(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 3 /* getMasterVolume */:
        {
            _hidl_err = ::android::hardware::audio::V7_0::BnHwDevice::_hidl_getMasterVolume(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 4 /* setMicMute */:
        {
            _hidl_err = ::android::hardware::audio::V7_0::BnHwDevice::_hidl_setMicMute(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 5 /* getMicMute */:
        {
            _hidl_err = ::android::hardware::audio::V7_0::BnHwDevice::_hidl_getMicMute(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 6 /* setMasterMute */:
        {
            _hidl_err = ::android::hardware::audio::V7_0::BnHwDevice::_hidl_setMasterMute(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 7 /* getMasterMute */:
        {
            _hidl_err = ::android::hardware::audio::V7_0::BnHwDevice::_hidl_getMasterMute(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 8 /* getInputBufferSize */:
        {
            _hidl_err = ::android::hardware::audio::V7_0::BnHwDevice::_hidl_getInputBufferSize(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 9 /* openOutputStream */:
        {
            _hidl_err = ::android::hardware::audio::V7_0::BnHwDevice::_hidl_openOutputStream(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 10 /* openInputStream */:
        {
            _hidl_err = ::android::hardware::audio::V7_0::BnHwDevice::_hidl_openInputStream(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 11 /* supportsAudioPatches */:
        {
            _hidl_err = ::android::hardware::audio::V7_0::BnHwDevice::_hidl_supportsAudioPatches(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 12 /* createAudioPatch */:
        {
            _hidl_err = ::android::hardware::audio::V7_0::BnHwDevice::_hidl_createAudioPatch(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 13 /* updateAudioPatch */:
        {
            _hidl_err = ::android::hardware::audio::V7_0::BnHwDevice::_hidl_updateAudioPatch(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 14 /* releaseAudioPatch */:
        {
            _hidl_err = ::android::hardware::audio::V7_0::BnHwDevice::_hidl_releaseAudioPatch(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 15 /* getAudioPort */:
        {
            _hidl_err = ::android::hardware::audio::V7_0::BnHwDevice::_hidl_getAudioPort(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 16 /* setAudioPortConfig */:
        {
            _hidl_err = ::android::hardware::audio::V7_0::BnHwDevice::_hidl_setAudioPortConfig(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 17 /* getHwAvSync */:
        {
            _hidl_err = ::android::hardware::audio::V7_0::BnHwDevice::_hidl_getHwAvSync(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 18 /* setScreenState */:
        {
            _hidl_err = ::android::hardware::audio::V7_0::BnHwDevice::_hidl_setScreenState(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 19 /* getParameters */:
        {
            _hidl_err = ::android::hardware::audio::V7_0::BnHwDevice::_hidl_getParameters(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 20 /* setParameters */:
        {
            _hidl_err = ::android::hardware::audio::V7_0::BnHwDevice::_hidl_setParameters(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 21 /* getMicrophones */:
        {
            _hidl_err = ::android::hardware::audio::V7_0::BnHwDevice::_hidl_getMicrophones(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 22 /* setConnectedState */:
        {
            _hidl_err = ::android::hardware::audio::V7_0::BnHwDevice::_hidl_setConnectedState(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 23 /* close */:
        {
            _hidl_err = ::android::hardware::audio::V7_0::BnHwDevice::_hidl_close(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 24 /* addDeviceEffect */:
        {
            _hidl_err = ::android::hardware::audio::V7_0::BnHwDevice::_hidl_addDeviceEffect(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 25 /* removeDeviceEffect */:
        {
            _hidl_err = ::android::hardware::audio::V7_0::BnHwDevice::_hidl_removeDeviceEffect(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 26 /* setVoiceVolume */:
        {
            _hidl_err = ::android::hardware::audio::V7_0::BnHwPrimaryDevice::_hidl_setVoiceVolume(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 27 /* setMode */:
        {
            _hidl_err = ::android::hardware::audio::V7_0::BnHwPrimaryDevice::_hidl_setMode(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 28 /* setBtScoHeadsetDebugName */:
        {
            _hidl_err = ::android::hardware::audio::V7_0::BnHwPrimaryDevice::_hidl_setBtScoHeadsetDebugName(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 29 /* getBtScoNrecEnabled */:
        {
            _hidl_err = ::android::hardware::audio::V7_0::BnHwPrimaryDevice::_hidl_getBtScoNrecEnabled(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 30 /* setBtScoNrecEnabled */:
        {
            _hidl_err = ::android::hardware::audio::V7_0::BnHwPrimaryDevice::_hidl_setBtScoNrecEnabled(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 31 /* getBtScoWidebandEnabled */:
        {
            _hidl_err = ::android::hardware::audio::V7_0::BnHwPrimaryDevice::_hidl_getBtScoWidebandEnabled(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 32 /* setBtScoWidebandEnabled */:
        {
            _hidl_err = ::android::hardware::audio::V7_0::BnHwPrimaryDevice::_hidl_setBtScoWidebandEnabled(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 33 /* getBtHfpEnabled */:
        {
            _hidl_err = ::android::hardware::audio::V7_0::BnHwPrimaryDevice::_hidl_getBtHfpEnabled(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 34 /* setBtHfpEnabled */:
        {
            _hidl_err = ::android::hardware::audio::V7_0::BnHwPrimaryDevice::_hidl_setBtHfpEnabled(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 35 /* setBtHfpSampleRate */:
        {
            _hidl_err = ::android::hardware::audio::V7_0::BnHwPrimaryDevice::_hidl_setBtHfpSampleRate(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 36 /* setBtHfpVolume */:
        {
            _hidl_err = ::android::hardware::audio::V7_0::BnHwPrimaryDevice::_hidl_setBtHfpVolume(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 37 /* getTtyMode */:
        {
            _hidl_err = ::android::hardware::audio::V7_0::BnHwPrimaryDevice::_hidl_getTtyMode(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 38 /* setTtyMode */:
        {
            _hidl_err = ::android::hardware::audio::V7_0::BnHwPrimaryDevice::_hidl_setTtyMode(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 39 /* getHacEnabled */:
        {
            _hidl_err = ::android::hardware::audio::V7_0::BnHwPrimaryDevice::_hidl_getHacEnabled(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 40 /* setHacEnabled */:
        {
            _hidl_err = ::android::hardware::audio::V7_0::BnHwPrimaryDevice::_hidl_setHacEnabled(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 41 /* updateRotation */:
        {
            _hidl_err = ::android::hardware::audio::V7_0::BnHwPrimaryDevice::_hidl_updateRotation(this, _hidl_data, _hidl_reply, _hidl_cb);
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

BsPrimaryDevice::BsPrimaryDevice(const ::android::sp<::android::hardware::audio::V7_0::IPrimaryDevice> impl) : ::android::hardware::details::HidlInstrumentor("android.hardware.audio@7.0", "IPrimaryDevice"), mImpl(impl) {
    mOnewayQueue.start(3000 /* similar limit to binderized */);
}

::android::hardware::Return<void> BsPrimaryDevice::addOnewayTask(std::function<void(void)> fun) {
    if (!mOnewayQueue.push(fun)) {
        return ::android::hardware::Status::fromExceptionCode(
                ::android::hardware::Status::EX_TRANSACTION_FAILED,
                "Passthrough oneway function queue exceeds maximum size.");
    }
    return ::android::hardware::Status();
}

::android::sp<IPrimaryDevice> IPrimaryDevice::tryGetService(const std::string &serviceName, const bool getStub) {
    return ::android::hardware::details::getServiceInternal<BpHwPrimaryDevice>(serviceName, false, getStub);
}

::android::sp<IPrimaryDevice> IPrimaryDevice::getService(const std::string &serviceName, const bool getStub) {
    return ::android::hardware::details::getServiceInternal<BpHwPrimaryDevice>(serviceName, true, getStub);
}

::android::status_t IPrimaryDevice::registerAsService(const std::string &serviceName) {
    return ::android::hardware::details::registerAsServiceInternal(this, serviceName);
}

bool IPrimaryDevice::registerForNotifications(
        const std::string &serviceName,
        const ::android::sp<::android::hidl::manager::V1_0::IServiceNotification> &notification) {
    const ::android::sp<::android::hidl::manager::V1_0::IServiceManager> sm
            = ::android::hardware::defaultServiceManager();
    if (sm == nullptr) {
        return false;
    }
    ::android::hardware::Return<bool> success =
            sm->registerForNotifications("android.hardware.audio@7.0::IPrimaryDevice",
                    serviceName, notification);
    return success.isOk() && success;
}

static_assert(sizeof(::android::hardware::MQDescriptor<char, ::android::hardware::kSynchronizedReadWrite>) == 32, "wrong size");
static_assert(sizeof(::android::hardware::hidl_handle) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_memory) == 40, "wrong size");
static_assert(sizeof(::android::hardware::hidl_string) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_vec<char>) == 16, "wrong size");

}  // namespace V7_0
}  // namespace audio
}  // namespace hardware
}  // namespace android
