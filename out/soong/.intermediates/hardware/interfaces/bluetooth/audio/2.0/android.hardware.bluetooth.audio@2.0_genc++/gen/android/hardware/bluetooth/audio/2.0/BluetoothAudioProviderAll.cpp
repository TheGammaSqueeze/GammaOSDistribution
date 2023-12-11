#define LOG_TAG "android.hardware.bluetooth.audio@2.0::BluetoothAudioProvider"

#include <log/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <hidl/Static.h>
#include <hwbinder/ProcessState.h>
#include <utils/Trace.h>
#include <android/hidl/manager/1.0/IServiceManager.h>
#include <android/hardware/bluetooth/audio/2.0/BpHwBluetoothAudioProvider.h>
#include <android/hardware/bluetooth/audio/2.0/BnHwBluetoothAudioProvider.h>
#include <android/hardware/bluetooth/audio/2.0/BsBluetoothAudioProvider.h>
#include <android/hidl/base/1.0/BpHwBase.h>
#include <hidl/ServiceManagement.h>

namespace android {
namespace hardware {
namespace bluetooth {
namespace audio {
namespace V2_0 {

const char* IBluetoothAudioProvider::descriptor("android.hardware.bluetooth.audio@2.0::IBluetoothAudioProvider");

__attribute__((constructor)) static void static_constructor() {
    ::android::hardware::details::getBnConstructorMap().set(IBluetoothAudioProvider::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hardware::IBinder> {
                return new BnHwBluetoothAudioProvider(static_cast<IBluetoothAudioProvider *>(iIntf));
            });
    ::android::hardware::details::getBsConstructorMap().set(IBluetoothAudioProvider::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hidl::base::V1_0::IBase> {
                return new BsBluetoothAudioProvider(static_cast<IBluetoothAudioProvider *>(iIntf));
            });
}

__attribute__((destructor))static void static_destructor() {
    ::android::hardware::details::getBnConstructorMap().erase(IBluetoothAudioProvider::descriptor);
    ::android::hardware::details::getBsConstructorMap().erase(IBluetoothAudioProvider::descriptor);
}

// Methods from ::android::hardware::bluetooth::audio::V2_0::IBluetoothAudioProvider follow.
// no default implementation for: ::android::hardware::Return<void> IBluetoothAudioProvider::startSession(const ::android::sp<::android::hardware::bluetooth::audio::V2_0::IBluetoothAudioPort>& hostIf, const ::android::hardware::bluetooth::audio::V2_0::AudioConfiguration& audioConfig, startSession_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IBluetoothAudioProvider::streamStarted(::android::hardware::bluetooth::audio::V2_0::Status status)
// no default implementation for: ::android::hardware::Return<void> IBluetoothAudioProvider::streamSuspended(::android::hardware::bluetooth::audio::V2_0::Status status)
// no default implementation for: ::android::hardware::Return<void> IBluetoothAudioProvider::endSession()

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> IBluetoothAudioProvider::interfaceChain(interfaceChain_cb _hidl_cb){
    _hidl_cb({
        ::android::hardware::bluetooth::audio::V2_0::IBluetoothAudioProvider::descriptor,
        ::android::hidl::base::V1_0::IBase::descriptor,
    });
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IBluetoothAudioProvider::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    (void)fd;
    (void)options;
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IBluetoothAudioProvider::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    _hidl_cb(::android::hardware::bluetooth::audio::V2_0::IBluetoothAudioProvider::descriptor);
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IBluetoothAudioProvider::getHashChain(getHashChain_cb _hidl_cb){
    _hidl_cb({
        (uint8_t[32]){251,156,64,228,222,171,64,190,84,118,71,112,120,254,61,138,74,68,149,253,157,238,244,50,24,120,209,105,214,117,198,51} /* fb9c40e4deab40be5476477078fe3d8a4a4495fd9deef4321878d169d675c633 */,
        (uint8_t[32]){236,127,215,158,208,45,250,133,188,73,148,38,173,174,62,190,35,239,5,36,243,205,105,87,19,147,36,184,59,24,202,76} /* ec7fd79ed02dfa85bc499426adae3ebe23ef0524f3cd6957139324b83b18ca4c */});
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IBluetoothAudioProvider::setHALInstrumentation(){
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> IBluetoothAudioProvider::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    (void)cookie;
    return (recipient != nullptr);
}

::android::hardware::Return<void> IBluetoothAudioProvider::ping(){
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IBluetoothAudioProvider::getDebugInfo(getDebugInfo_cb _hidl_cb){
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

::android::hardware::Return<void> IBluetoothAudioProvider::notifySyspropsChanged(){
    ::android::report_sysprop_change();
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> IBluetoothAudioProvider::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
    return (recipient != nullptr);
}


::android::hardware::Return<::android::sp<::android::hardware::bluetooth::audio::V2_0::IBluetoothAudioProvider>> IBluetoothAudioProvider::castFrom(const ::android::sp<::android::hardware::bluetooth::audio::V2_0::IBluetoothAudioProvider>& parent, bool /* emitError */) {
    return parent;
}

::android::hardware::Return<::android::sp<::android::hardware::bluetooth::audio::V2_0::IBluetoothAudioProvider>> IBluetoothAudioProvider::castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<IBluetoothAudioProvider, ::android::hidl::base::V1_0::IBase, BpHwBluetoothAudioProvider>(
            parent, "android.hardware.bluetooth.audio@2.0::IBluetoothAudioProvider", emitError);
}

BpHwBluetoothAudioProvider::BpHwBluetoothAudioProvider(const ::android::sp<::android::hardware::IBinder> &_hidl_impl)
        : BpInterface<IBluetoothAudioProvider>(_hidl_impl),
          ::android::hardware::details::HidlInstrumentor("android.hardware.bluetooth.audio@2.0", "IBluetoothAudioProvider") {
}

void BpHwBluetoothAudioProvider::onLastStrongRef(const void* id) {
    {
        std::unique_lock<std::mutex> lock(_hidl_mMutex);
        _hidl_mDeathRecipients.clear();
    }

    BpInterface<IBluetoothAudioProvider>::onLastStrongRef(id);
}
// Methods from ::android::hardware::bluetooth::audio::V2_0::IBluetoothAudioProvider follow.
::android::hardware::Return<void> BpHwBluetoothAudioProvider::_hidl_startSession(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::sp<::android::hardware::bluetooth::audio::V2_0::IBluetoothAudioPort>& hostIf, const ::android::hardware::bluetooth::audio::V2_0::AudioConfiguration& audioConfig, startSession_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IBluetoothAudioProvider::startSession::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&hostIf);
        _hidl_args.push_back((void *)&audioConfig);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.bluetooth.audio", "2.0", "IBluetoothAudioProvider", "startSession", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwBluetoothAudioProvider::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (hostIf == nullptr) {
        _hidl_err = _hidl_data.writeStrongBinder(nullptr);
    } else {
        ::android::sp<::android::hardware::IBinder> _hidl_binder = ::android::hardware::getOrCreateCachedBinder(hostIf.get());
        if (_hidl_binder.get() != nullptr) {
            _hidl_err = _hidl_data.writeStrongBinder(_hidl_binder);
        } else {
            _hidl_err = ::android::UNKNOWN_ERROR;
        }
    }
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_audioConfig_parent;

    _hidl_err = _hidl_data.writeBuffer(&audioConfig, sizeof(audioConfig), &_hidl_audioConfig_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    ::android::hardware::ProcessState::self()->startThreadPool();
    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(1 /* startSession */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::bluetooth::audio::V2_0::Status _hidl_out_status;
        const ::android::hardware::MQDescriptorSync<uint8_t>* _hidl_out_dataMQ;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        _hidl_err = _hidl_reply.readUint8((uint8_t *)&_hidl_out_status);
        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_dataMQ_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_dataMQ), &_hidl__hidl_out_dataMQ_parent,  reinterpret_cast<const void **>(&_hidl_out_dataMQ));

        if (_hidl_err != ::android::OK) { return; }

        _hidl_err = ::android::hardware::readEmbeddedFromParcel(
                const_cast<::android::hardware::MQDescriptorSync<uint8_t> &>(*_hidl_out_dataMQ),
                _hidl_reply,
                _hidl__hidl_out_dataMQ_parent,
                0 /* parentOffset */);

        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(_hidl_out_status, *_hidl_out_dataMQ);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)_hidl_out_dataMQ);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.bluetooth.audio", "2.0", "IBluetoothAudioProvider", "startSession", &_hidl_args);
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

::android::hardware::Return<void> BpHwBluetoothAudioProvider::_hidl_streamStarted(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, ::android::hardware::bluetooth::audio::V2_0::Status status) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IBluetoothAudioProvider::streamStarted::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&status);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.bluetooth.audio", "2.0", "IBluetoothAudioProvider", "streamStarted", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwBluetoothAudioProvider::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint8((uint8_t)status);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(2 /* streamStarted */, _hidl_data, &_hidl_reply, 0 /* flags */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.bluetooth.audio", "2.0", "IBluetoothAudioProvider", "streamStarted", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwBluetoothAudioProvider::_hidl_streamSuspended(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, ::android::hardware::bluetooth::audio::V2_0::Status status) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IBluetoothAudioProvider::streamSuspended::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&status);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.bluetooth.audio", "2.0", "IBluetoothAudioProvider", "streamSuspended", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwBluetoothAudioProvider::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint8((uint8_t)status);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(3 /* streamSuspended */, _hidl_data, &_hidl_reply, 0 /* flags */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.bluetooth.audio", "2.0", "IBluetoothAudioProvider", "streamSuspended", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<void> BpHwBluetoothAudioProvider::_hidl_endSession(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IBluetoothAudioProvider::endSession::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.bluetooth.audio", "2.0", "IBluetoothAudioProvider", "endSession", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwBluetoothAudioProvider::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(4 /* endSession */, _hidl_data, &_hidl_reply, 0 /* flags */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.bluetooth.audio", "2.0", "IBluetoothAudioProvider", "endSession", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}


// Methods from ::android::hardware::bluetooth::audio::V2_0::IBluetoothAudioProvider follow.
::android::hardware::Return<void> BpHwBluetoothAudioProvider::startSession(const ::android::sp<::android::hardware::bluetooth::audio::V2_0::IBluetoothAudioPort>& hostIf, const ::android::hardware::bluetooth::audio::V2_0::AudioConfiguration& audioConfig, startSession_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::bluetooth::audio::V2_0::BpHwBluetoothAudioProvider::_hidl_startSession(this, this, hostIf, audioConfig, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwBluetoothAudioProvider::streamStarted(::android::hardware::bluetooth::audio::V2_0::Status status){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::bluetooth::audio::V2_0::BpHwBluetoothAudioProvider::_hidl_streamStarted(this, this, status);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwBluetoothAudioProvider::streamSuspended(::android::hardware::bluetooth::audio::V2_0::Status status){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::bluetooth::audio::V2_0::BpHwBluetoothAudioProvider::_hidl_streamSuspended(this, this, status);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwBluetoothAudioProvider::endSession(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::bluetooth::audio::V2_0::BpHwBluetoothAudioProvider::_hidl_endSession(this, this);

    return _hidl_out;
}


// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BpHwBluetoothAudioProvider::interfaceChain(interfaceChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwBluetoothAudioProvider::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_debug(this, this, fd, options);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwBluetoothAudioProvider::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceDescriptor(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwBluetoothAudioProvider::getHashChain(getHashChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getHashChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwBluetoothAudioProvider::setHALInstrumentation(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_setHALInstrumentation(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwBluetoothAudioProvider::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    ::android::hardware::ProcessState::self()->startThreadPool();
    ::android::hardware::hidl_binder_death_recipient *binder_recipient = new ::android::hardware::hidl_binder_death_recipient(recipient, cookie, this);
    std::unique_lock<std::mutex> lock(_hidl_mMutex);
    _hidl_mDeathRecipients.push_back(binder_recipient);
    return (remote()->linkToDeath(binder_recipient) == ::android::OK);
}

::android::hardware::Return<void> BpHwBluetoothAudioProvider::ping(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_ping(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwBluetoothAudioProvider::getDebugInfo(getDebugInfo_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getDebugInfo(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwBluetoothAudioProvider::notifySyspropsChanged(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_notifySyspropsChanged(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwBluetoothAudioProvider::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
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


BnHwBluetoothAudioProvider::BnHwBluetoothAudioProvider(const ::android::sp<IBluetoothAudioProvider> &_hidl_impl)
        : ::android::hidl::base::V1_0::BnHwBase(_hidl_impl, "android.hardware.bluetooth.audio@2.0", "IBluetoothAudioProvider") { 
            _hidl_mImpl = _hidl_impl;
            auto prio = ::android::hardware::getMinSchedulerPolicy(_hidl_impl);
            mSchedPolicy = prio.sched_policy;
            mSchedPriority = prio.prio;
            setRequestingSid(::android::hardware::getRequestingSid(_hidl_impl));
}

BnHwBluetoothAudioProvider::~BnHwBluetoothAudioProvider() {
    ::android::hardware::details::gBnMap->eraseIfEqual(_hidl_mImpl.get(), this);
}

// Methods from ::android::hardware::bluetooth::audio::V2_0::IBluetoothAudioProvider follow.
::android::status_t BnHwBluetoothAudioProvider::_hidl_startSession(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwBluetoothAudioProvider::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::sp<::android::hardware::bluetooth::audio::V2_0::IBluetoothAudioPort> hostIf;
    ::android::hardware::bluetooth::audio::V2_0::AudioConfiguration* audioConfig;

    {
        ::android::sp<::android::hardware::IBinder> _hidl_binder;
        _hidl_err = _hidl_data.readNullableStrongBinder(&_hidl_binder);
        if (_hidl_err != ::android::OK) { return _hidl_err; }

        hostIf = ::android::hardware::fromBinder<::android::hardware::bluetooth::audio::V2_0::IBluetoothAudioPort,::android::hardware::bluetooth::audio::V2_0::BpHwBluetoothAudioPort,::android::hardware::bluetooth::audio::V2_0::BnHwBluetoothAudioPort>(_hidl_binder);
    }

    size_t _hidl_audioConfig_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*audioConfig), &_hidl_audioConfig_parent,  const_cast<const void**>(reinterpret_cast<void **>(&audioConfig)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IBluetoothAudioProvider::startSession::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&hostIf);
        _hidl_args.push_back((void *)audioConfig);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.bluetooth.audio", "2.0", "IBluetoothAudioProvider", "startSession", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IBluetoothAudioProvider*>(_hidl_this->getImpl().get())->startSession(hostIf, *audioConfig, [&](const auto &_hidl_out_status, const auto &_hidl_out_dataMQ) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("startSession: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeUint8((uint8_t)_hidl_out_status);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_dataMQ_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_dataMQ, sizeof(_hidl_out_dataMQ), &_hidl__hidl_out_dataMQ_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                _hidl_out_dataMQ,
                _hidl_reply,
                _hidl__hidl_out_dataMQ_parent,
                0 /* parentOffset */);

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)&_hidl_out_dataMQ);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.bluetooth.audio", "2.0", "IBluetoothAudioProvider", "startSession", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("startSession: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwBluetoothAudioProvider::_hidl_streamStarted(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwBluetoothAudioProvider::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::bluetooth::audio::V2_0::Status status;

    _hidl_err = _hidl_data.readUint8((uint8_t *)&status);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IBluetoothAudioProvider::streamStarted::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&status);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.bluetooth.audio", "2.0", "IBluetoothAudioProvider", "streamStarted", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IBluetoothAudioProvider*>(_hidl_this->getImpl().get())->streamStarted(status);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.bluetooth.audio", "2.0", "IBluetoothAudioProvider", "streamStarted", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwBluetoothAudioProvider::_hidl_streamSuspended(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwBluetoothAudioProvider::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::bluetooth::audio::V2_0::Status status;

    _hidl_err = _hidl_data.readUint8((uint8_t *)&status);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IBluetoothAudioProvider::streamSuspended::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&status);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.bluetooth.audio", "2.0", "IBluetoothAudioProvider", "streamSuspended", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IBluetoothAudioProvider*>(_hidl_this->getImpl().get())->streamSuspended(status);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.bluetooth.audio", "2.0", "IBluetoothAudioProvider", "streamSuspended", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwBluetoothAudioProvider::_hidl_endSession(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwBluetoothAudioProvider::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IBluetoothAudioProvider::endSession::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.bluetooth.audio", "2.0", "IBluetoothAudioProvider", "endSession", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IBluetoothAudioProvider*>(_hidl_this->getImpl().get())->endSession();

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.bluetooth.audio", "2.0", "IBluetoothAudioProvider", "endSession", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}


// Methods from ::android::hardware::bluetooth::audio::V2_0::IBluetoothAudioProvider follow.

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BnHwBluetoothAudioProvider::ping() {
    return ::android::hardware::Void();
}
::android::hardware::Return<void> BnHwBluetoothAudioProvider::getDebugInfo(getDebugInfo_cb _hidl_cb) {
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

::android::status_t BnHwBluetoothAudioProvider::onTransact(
        uint32_t _hidl_code,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        uint32_t _hidl_flags,
        TransactCallback _hidl_cb) {
    ::android::status_t _hidl_err = ::android::OK;

    switch (_hidl_code) {
        case 1 /* startSession */:
        {
            _hidl_err = ::android::hardware::bluetooth::audio::V2_0::BnHwBluetoothAudioProvider::_hidl_startSession(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 2 /* streamStarted */:
        {
            _hidl_err = ::android::hardware::bluetooth::audio::V2_0::BnHwBluetoothAudioProvider::_hidl_streamStarted(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 3 /* streamSuspended */:
        {
            _hidl_err = ::android::hardware::bluetooth::audio::V2_0::BnHwBluetoothAudioProvider::_hidl_streamSuspended(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 4 /* endSession */:
        {
            _hidl_err = ::android::hardware::bluetooth::audio::V2_0::BnHwBluetoothAudioProvider::_hidl_endSession(this, _hidl_data, _hidl_reply, _hidl_cb);
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

BsBluetoothAudioProvider::BsBluetoothAudioProvider(const ::android::sp<::android::hardware::bluetooth::audio::V2_0::IBluetoothAudioProvider> impl) : ::android::hardware::details::HidlInstrumentor("android.hardware.bluetooth.audio@2.0", "IBluetoothAudioProvider"), mImpl(impl) {
    mOnewayQueue.start(3000 /* similar limit to binderized */);
}

::android::hardware::Return<void> BsBluetoothAudioProvider::addOnewayTask(std::function<void(void)> fun) {
    if (!mOnewayQueue.push(fun)) {
        return ::android::hardware::Status::fromExceptionCode(
                ::android::hardware::Status::EX_TRANSACTION_FAILED,
                "Passthrough oneway function queue exceeds maximum size.");
    }
    return ::android::hardware::Status();
}

::android::sp<IBluetoothAudioProvider> IBluetoothAudioProvider::tryGetService(const std::string &serviceName, const bool getStub) {
    return ::android::hardware::details::getServiceInternal<BpHwBluetoothAudioProvider>(serviceName, false, getStub);
}

::android::sp<IBluetoothAudioProvider> IBluetoothAudioProvider::getService(const std::string &serviceName, const bool getStub) {
    return ::android::hardware::details::getServiceInternal<BpHwBluetoothAudioProvider>(serviceName, true, getStub);
}

::android::status_t IBluetoothAudioProvider::registerAsService(const std::string &serviceName) {
    return ::android::hardware::details::registerAsServiceInternal(this, serviceName);
}

bool IBluetoothAudioProvider::registerForNotifications(
        const std::string &serviceName,
        const ::android::sp<::android::hidl::manager::V1_0::IServiceNotification> &notification) {
    const ::android::sp<::android::hidl::manager::V1_0::IServiceManager> sm
            = ::android::hardware::defaultServiceManager();
    if (sm == nullptr) {
        return false;
    }
    ::android::hardware::Return<bool> success =
            sm->registerForNotifications("android.hardware.bluetooth.audio@2.0::IBluetoothAudioProvider",
                    serviceName, notification);
    return success.isOk() && success;
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
