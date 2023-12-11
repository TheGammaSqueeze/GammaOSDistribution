#define LOG_TAG "android.hardware.bluetooth.audio@2.1::BluetoothAudioProvidersFactory"

#include <log/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <hidl/Static.h>
#include <hwbinder/ProcessState.h>
#include <utils/Trace.h>
#include <android/hidl/manager/1.0/IServiceManager.h>
#include <android/hardware/bluetooth/audio/2.1/BpHwBluetoothAudioProvidersFactory.h>
#include <android/hardware/bluetooth/audio/2.1/BnHwBluetoothAudioProvidersFactory.h>
#include <android/hardware/bluetooth/audio/2.1/BsBluetoothAudioProvidersFactory.h>
#include <android/hardware/bluetooth/audio/2.0/BpHwBluetoothAudioProvidersFactory.h>
#include <android/hidl/base/1.0/BpHwBase.h>
#include <hidl/ServiceManagement.h>

namespace android {
namespace hardware {
namespace bluetooth {
namespace audio {
namespace V2_1 {

const char* IBluetoothAudioProvidersFactory::descriptor("android.hardware.bluetooth.audio@2.1::IBluetoothAudioProvidersFactory");

__attribute__((constructor)) static void static_constructor() {
    ::android::hardware::details::getBnConstructorMap().set(IBluetoothAudioProvidersFactory::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hardware::IBinder> {
                return new BnHwBluetoothAudioProvidersFactory(static_cast<IBluetoothAudioProvidersFactory *>(iIntf));
            });
    ::android::hardware::details::getBsConstructorMap().set(IBluetoothAudioProvidersFactory::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hidl::base::V1_0::IBase> {
                return new BsBluetoothAudioProvidersFactory(static_cast<IBluetoothAudioProvidersFactory *>(iIntf));
            });
}

__attribute__((destructor))static void static_destructor() {
    ::android::hardware::details::getBnConstructorMap().erase(IBluetoothAudioProvidersFactory::descriptor);
    ::android::hardware::details::getBsConstructorMap().erase(IBluetoothAudioProvidersFactory::descriptor);
}

// Methods from ::android::hardware::bluetooth::audio::V2_0::IBluetoothAudioProvidersFactory follow.
// no default implementation for: ::android::hardware::Return<void> IBluetoothAudioProvidersFactory::openProvider(::android::hardware::bluetooth::audio::V2_0::SessionType sessionType, openProvider_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IBluetoothAudioProvidersFactory::getProviderCapabilities(::android::hardware::bluetooth::audio::V2_0::SessionType sessionType, getProviderCapabilities_cb _hidl_cb)

// Methods from ::android::hardware::bluetooth::audio::V2_1::IBluetoothAudioProvidersFactory follow.
// no default implementation for: ::android::hardware::Return<void> IBluetoothAudioProvidersFactory::openProvider_2_1(::android::hardware::bluetooth::audio::V2_1::SessionType sessionType, openProvider_2_1_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IBluetoothAudioProvidersFactory::getProviderCapabilities_2_1(::android::hardware::bluetooth::audio::V2_1::SessionType sessionType, getProviderCapabilities_2_1_cb _hidl_cb)

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> IBluetoothAudioProvidersFactory::interfaceChain(interfaceChain_cb _hidl_cb){
    _hidl_cb({
        ::android::hardware::bluetooth::audio::V2_1::IBluetoothAudioProvidersFactory::descriptor,
        ::android::hardware::bluetooth::audio::V2_0::IBluetoothAudioProvidersFactory::descriptor,
        ::android::hidl::base::V1_0::IBase::descriptor,
    });
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IBluetoothAudioProvidersFactory::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    (void)fd;
    (void)options;
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IBluetoothAudioProvidersFactory::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    _hidl_cb(::android::hardware::bluetooth::audio::V2_1::IBluetoothAudioProvidersFactory::descriptor);
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IBluetoothAudioProvidersFactory::getHashChain(getHashChain_cb _hidl_cb){
    _hidl_cb({
        (uint8_t[32]){212,23,169,33,44,143,150,227,160,106,47,34,28,140,87,86,199,101,53,91,43,129,222,43,42,101,212,201,238,232,84,1} /* d417a9212c8f96e3a06a2f221c8c5756c765355b2b81de2b2a65d4c9eee85401 */,
        (uint8_t[32]){247,67,31,62,62,78,51,135,252,111,39,166,207,66,62,221,205,130,74,57,93,196,52,157,48,44,153,90,180,74,152,149} /* f7431f3e3e4e3387fc6f27a6cf423eddcd824a395dc4349d302c995ab44a9895 */,
        (uint8_t[32]){236,127,215,158,208,45,250,133,188,73,148,38,173,174,62,190,35,239,5,36,243,205,105,87,19,147,36,184,59,24,202,76} /* ec7fd79ed02dfa85bc499426adae3ebe23ef0524f3cd6957139324b83b18ca4c */});
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IBluetoothAudioProvidersFactory::setHALInstrumentation(){
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> IBluetoothAudioProvidersFactory::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    (void)cookie;
    return (recipient != nullptr);
}

::android::hardware::Return<void> IBluetoothAudioProvidersFactory::ping(){
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IBluetoothAudioProvidersFactory::getDebugInfo(getDebugInfo_cb _hidl_cb){
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

::android::hardware::Return<void> IBluetoothAudioProvidersFactory::notifySyspropsChanged(){
    ::android::report_sysprop_change();
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> IBluetoothAudioProvidersFactory::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
    return (recipient != nullptr);
}


::android::hardware::Return<::android::sp<::android::hardware::bluetooth::audio::V2_1::IBluetoothAudioProvidersFactory>> IBluetoothAudioProvidersFactory::castFrom(const ::android::sp<::android::hardware::bluetooth::audio::V2_1::IBluetoothAudioProvidersFactory>& parent, bool /* emitError */) {
    return parent;
}

::android::hardware::Return<::android::sp<::android::hardware::bluetooth::audio::V2_1::IBluetoothAudioProvidersFactory>> IBluetoothAudioProvidersFactory::castFrom(const ::android::sp<::android::hardware::bluetooth::audio::V2_0::IBluetoothAudioProvidersFactory>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<IBluetoothAudioProvidersFactory, ::android::hardware::bluetooth::audio::V2_0::IBluetoothAudioProvidersFactory, BpHwBluetoothAudioProvidersFactory>(
            parent, "android.hardware.bluetooth.audio@2.1::IBluetoothAudioProvidersFactory", emitError);
}

::android::hardware::Return<::android::sp<::android::hardware::bluetooth::audio::V2_1::IBluetoothAudioProvidersFactory>> IBluetoothAudioProvidersFactory::castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<IBluetoothAudioProvidersFactory, ::android::hidl::base::V1_0::IBase, BpHwBluetoothAudioProvidersFactory>(
            parent, "android.hardware.bluetooth.audio@2.1::IBluetoothAudioProvidersFactory", emitError);
}

BpHwBluetoothAudioProvidersFactory::BpHwBluetoothAudioProvidersFactory(const ::android::sp<::android::hardware::IBinder> &_hidl_impl)
        : BpInterface<IBluetoothAudioProvidersFactory>(_hidl_impl),
          ::android::hardware::details::HidlInstrumentor("android.hardware.bluetooth.audio@2.1", "IBluetoothAudioProvidersFactory") {
}

void BpHwBluetoothAudioProvidersFactory::onLastStrongRef(const void* id) {
    {
        std::unique_lock<std::mutex> lock(_hidl_mMutex);
        _hidl_mDeathRecipients.clear();
    }

    BpInterface<IBluetoothAudioProvidersFactory>::onLastStrongRef(id);
}
// Methods from ::android::hardware::bluetooth::audio::V2_1::IBluetoothAudioProvidersFactory follow.
::android::hardware::Return<void> BpHwBluetoothAudioProvidersFactory::_hidl_openProvider_2_1(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, ::android::hardware::bluetooth::audio::V2_1::SessionType sessionType, openProvider_2_1_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IBluetoothAudioProvidersFactory::openProvider_2_1::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&sessionType);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.bluetooth.audio", "2.1", "IBluetoothAudioProvidersFactory", "openProvider_2_1", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwBluetoothAudioProvidersFactory::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint8((uint8_t)sessionType);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(3 /* openProvider_2_1 */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::bluetooth::audio::V2_0::Status _hidl_out_status;
        ::android::sp<::android::hardware::bluetooth::audio::V2_1::IBluetoothAudioProvider> _hidl_out_provider;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        _hidl_err = _hidl_reply.readUint8((uint8_t *)&_hidl_out_status);
        if (_hidl_err != ::android::OK) { return; }

        {
            ::android::sp<::android::hardware::IBinder> _hidl_binder;
            _hidl_err = _hidl_reply.readNullableStrongBinder(&_hidl_binder);
            if (_hidl_err != ::android::OK) { return; }

            _hidl_out_provider = ::android::hardware::fromBinder<::android::hardware::bluetooth::audio::V2_1::IBluetoothAudioProvider,::android::hardware::bluetooth::audio::V2_1::BpHwBluetoothAudioProvider,::android::hardware::bluetooth::audio::V2_1::BnHwBluetoothAudioProvider>(_hidl_binder);
        }

        _hidl_cb(_hidl_out_status, _hidl_out_provider);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)&_hidl_out_provider);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.bluetooth.audio", "2.1", "IBluetoothAudioProvidersFactory", "openProvider_2_1", &_hidl_args);
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

::android::hardware::Return<void> BpHwBluetoothAudioProvidersFactory::_hidl_getProviderCapabilities_2_1(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, ::android::hardware::bluetooth::audio::V2_1::SessionType sessionType, getProviderCapabilities_2_1_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IBluetoothAudioProvidersFactory::getProviderCapabilities_2_1::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&sessionType);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.bluetooth.audio", "2.1", "IBluetoothAudioProvidersFactory", "getProviderCapabilities_2_1", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwBluetoothAudioProvidersFactory::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint8((uint8_t)sessionType);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(4 /* getProviderCapabilities_2_1 */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        const ::android::hardware::hidl_vec<::android::hardware::bluetooth::audio::V2_1::AudioCapabilities>* _hidl_out_audioCapabilities;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        size_t _hidl__hidl_out_audioCapabilities_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_audioCapabilities), &_hidl__hidl_out_audioCapabilities_parent,  reinterpret_cast<const void **>(&_hidl_out_audioCapabilities));

        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_audioCapabilities_child;

        _hidl_err = ::android::hardware::readEmbeddedFromParcel(
                const_cast<::android::hardware::hidl_vec<::android::hardware::bluetooth::audio::V2_1::AudioCapabilities> &>(*_hidl_out_audioCapabilities),
                _hidl_reply,
                _hidl__hidl_out_audioCapabilities_parent,
                0 /* parentOffset */, &_hidl__hidl_out_audioCapabilities_child);

        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(*_hidl_out_audioCapabilities);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)_hidl_out_audioCapabilities);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.bluetooth.audio", "2.1", "IBluetoothAudioProvidersFactory", "getProviderCapabilities_2_1", &_hidl_args);
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


// Methods from ::android::hardware::bluetooth::audio::V2_0::IBluetoothAudioProvidersFactory follow.
::android::hardware::Return<void> BpHwBluetoothAudioProvidersFactory::openProvider(::android::hardware::bluetooth::audio::V2_0::SessionType sessionType, openProvider_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::bluetooth::audio::V2_0::BpHwBluetoothAudioProvidersFactory::_hidl_openProvider(this, this, sessionType, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwBluetoothAudioProvidersFactory::getProviderCapabilities(::android::hardware::bluetooth::audio::V2_0::SessionType sessionType, getProviderCapabilities_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::bluetooth::audio::V2_0::BpHwBluetoothAudioProvidersFactory::_hidl_getProviderCapabilities(this, this, sessionType, _hidl_cb);

    return _hidl_out;
}


// Methods from ::android::hardware::bluetooth::audio::V2_1::IBluetoothAudioProvidersFactory follow.
::android::hardware::Return<void> BpHwBluetoothAudioProvidersFactory::openProvider_2_1(::android::hardware::bluetooth::audio::V2_1::SessionType sessionType, openProvider_2_1_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::bluetooth::audio::V2_1::BpHwBluetoothAudioProvidersFactory::_hidl_openProvider_2_1(this, this, sessionType, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwBluetoothAudioProvidersFactory::getProviderCapabilities_2_1(::android::hardware::bluetooth::audio::V2_1::SessionType sessionType, getProviderCapabilities_2_1_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::bluetooth::audio::V2_1::BpHwBluetoothAudioProvidersFactory::_hidl_getProviderCapabilities_2_1(this, this, sessionType, _hidl_cb);

    return _hidl_out;
}


// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BpHwBluetoothAudioProvidersFactory::interfaceChain(interfaceChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwBluetoothAudioProvidersFactory::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_debug(this, this, fd, options);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwBluetoothAudioProvidersFactory::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceDescriptor(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwBluetoothAudioProvidersFactory::getHashChain(getHashChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getHashChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwBluetoothAudioProvidersFactory::setHALInstrumentation(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_setHALInstrumentation(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwBluetoothAudioProvidersFactory::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    ::android::hardware::ProcessState::self()->startThreadPool();
    ::android::hardware::hidl_binder_death_recipient *binder_recipient = new ::android::hardware::hidl_binder_death_recipient(recipient, cookie, this);
    std::unique_lock<std::mutex> lock(_hidl_mMutex);
    _hidl_mDeathRecipients.push_back(binder_recipient);
    return (remote()->linkToDeath(binder_recipient) == ::android::OK);
}

::android::hardware::Return<void> BpHwBluetoothAudioProvidersFactory::ping(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_ping(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwBluetoothAudioProvidersFactory::getDebugInfo(getDebugInfo_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getDebugInfo(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwBluetoothAudioProvidersFactory::notifySyspropsChanged(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_notifySyspropsChanged(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwBluetoothAudioProvidersFactory::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
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


BnHwBluetoothAudioProvidersFactory::BnHwBluetoothAudioProvidersFactory(const ::android::sp<IBluetoothAudioProvidersFactory> &_hidl_impl)
        : ::android::hidl::base::V1_0::BnHwBase(_hidl_impl, "android.hardware.bluetooth.audio@2.1", "IBluetoothAudioProvidersFactory") { 
            _hidl_mImpl = _hidl_impl;
            auto prio = ::android::hardware::getMinSchedulerPolicy(_hidl_impl);
            mSchedPolicy = prio.sched_policy;
            mSchedPriority = prio.prio;
            setRequestingSid(::android::hardware::getRequestingSid(_hidl_impl));
}

BnHwBluetoothAudioProvidersFactory::~BnHwBluetoothAudioProvidersFactory() {
    ::android::hardware::details::gBnMap->eraseIfEqual(_hidl_mImpl.get(), this);
}

// Methods from ::android::hardware::bluetooth::audio::V2_1::IBluetoothAudioProvidersFactory follow.
::android::status_t BnHwBluetoothAudioProvidersFactory::_hidl_openProvider_2_1(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwBluetoothAudioProvidersFactory::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::bluetooth::audio::V2_1::SessionType sessionType;

    _hidl_err = _hidl_data.readUint8((uint8_t *)&sessionType);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IBluetoothAudioProvidersFactory::openProvider_2_1::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&sessionType);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.bluetooth.audio", "2.1", "IBluetoothAudioProvidersFactory", "openProvider_2_1", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IBluetoothAudioProvidersFactory*>(_hidl_this->getImpl().get())->openProvider_2_1(sessionType, [&](const auto &_hidl_out_status, const auto &_hidl_out_provider) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("openProvider_2_1: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeUint8((uint8_t)_hidl_out_status);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        if (_hidl_out_provider == nullptr) {
            _hidl_err = _hidl_reply->writeStrongBinder(nullptr);
        } else {
            ::android::sp<::android::hardware::IBinder> _hidl_binder = ::android::hardware::getOrCreateCachedBinder(_hidl_out_provider.get());
            if (_hidl_binder.get() != nullptr) {
                _hidl_err = _hidl_reply->writeStrongBinder(_hidl_binder);
            } else {
                _hidl_err = ::android::UNKNOWN_ERROR;
            }
        }
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)&_hidl_out_provider);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.bluetooth.audio", "2.1", "IBluetoothAudioProvidersFactory", "openProvider_2_1", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("openProvider_2_1: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwBluetoothAudioProvidersFactory::_hidl_getProviderCapabilities_2_1(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwBluetoothAudioProvidersFactory::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::bluetooth::audio::V2_1::SessionType sessionType;

    _hidl_err = _hidl_data.readUint8((uint8_t *)&sessionType);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IBluetoothAudioProvidersFactory::getProviderCapabilities_2_1::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&sessionType);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.bluetooth.audio", "2.1", "IBluetoothAudioProvidersFactory", "getProviderCapabilities_2_1", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IBluetoothAudioProvidersFactory*>(_hidl_this->getImpl().get())->getProviderCapabilities_2_1(sessionType, [&](const auto &_hidl_out_audioCapabilities) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("getProviderCapabilities_2_1: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        size_t _hidl__hidl_out_audioCapabilities_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_audioCapabilities, sizeof(_hidl_out_audioCapabilities), &_hidl__hidl_out_audioCapabilities_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_audioCapabilities_child;

        _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                _hidl_out_audioCapabilities,
                _hidl_reply,
                _hidl__hidl_out_audioCapabilities_parent,
                0 /* parentOffset */, &_hidl__hidl_out_audioCapabilities_child);

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_audioCapabilities);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.bluetooth.audio", "2.1", "IBluetoothAudioProvidersFactory", "getProviderCapabilities_2_1", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("getProviderCapabilities_2_1: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}


// Methods from ::android::hardware::bluetooth::audio::V2_0::IBluetoothAudioProvidersFactory follow.

// Methods from ::android::hardware::bluetooth::audio::V2_1::IBluetoothAudioProvidersFactory follow.

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BnHwBluetoothAudioProvidersFactory::ping() {
    return ::android::hardware::Void();
}
::android::hardware::Return<void> BnHwBluetoothAudioProvidersFactory::getDebugInfo(getDebugInfo_cb _hidl_cb) {
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

::android::status_t BnHwBluetoothAudioProvidersFactory::onTransact(
        uint32_t _hidl_code,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        uint32_t _hidl_flags,
        TransactCallback _hidl_cb) {
    ::android::status_t _hidl_err = ::android::OK;

    switch (_hidl_code) {
        case 1 /* openProvider */:
        {
            _hidl_err = ::android::hardware::bluetooth::audio::V2_0::BnHwBluetoothAudioProvidersFactory::_hidl_openProvider(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 2 /* getProviderCapabilities */:
        {
            _hidl_err = ::android::hardware::bluetooth::audio::V2_0::BnHwBluetoothAudioProvidersFactory::_hidl_getProviderCapabilities(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 3 /* openProvider_2_1 */:
        {
            _hidl_err = ::android::hardware::bluetooth::audio::V2_1::BnHwBluetoothAudioProvidersFactory::_hidl_openProvider_2_1(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 4 /* getProviderCapabilities_2_1 */:
        {
            _hidl_err = ::android::hardware::bluetooth::audio::V2_1::BnHwBluetoothAudioProvidersFactory::_hidl_getProviderCapabilities_2_1(this, _hidl_data, _hidl_reply, _hidl_cb);
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

BsBluetoothAudioProvidersFactory::BsBluetoothAudioProvidersFactory(const ::android::sp<::android::hardware::bluetooth::audio::V2_1::IBluetoothAudioProvidersFactory> impl) : ::android::hardware::details::HidlInstrumentor("android.hardware.bluetooth.audio@2.1", "IBluetoothAudioProvidersFactory"), mImpl(impl) {
    mOnewayQueue.start(3000 /* similar limit to binderized */);
}

::android::hardware::Return<void> BsBluetoothAudioProvidersFactory::addOnewayTask(std::function<void(void)> fun) {
    if (!mOnewayQueue.push(fun)) {
        return ::android::hardware::Status::fromExceptionCode(
                ::android::hardware::Status::EX_TRANSACTION_FAILED,
                "Passthrough oneway function queue exceeds maximum size.");
    }
    return ::android::hardware::Status();
}

::android::sp<IBluetoothAudioProvidersFactory> IBluetoothAudioProvidersFactory::tryGetService(const std::string &serviceName, const bool getStub) {
    return ::android::hardware::details::getServiceInternal<BpHwBluetoothAudioProvidersFactory>(serviceName, false, getStub);
}

::android::sp<IBluetoothAudioProvidersFactory> IBluetoothAudioProvidersFactory::getService(const std::string &serviceName, const bool getStub) {
    return ::android::hardware::details::getServiceInternal<BpHwBluetoothAudioProvidersFactory>(serviceName, true, getStub);
}

::android::status_t IBluetoothAudioProvidersFactory::registerAsService(const std::string &serviceName) {
    return ::android::hardware::details::registerAsServiceInternal(this, serviceName);
}

bool IBluetoothAudioProvidersFactory::registerForNotifications(
        const std::string &serviceName,
        const ::android::sp<::android::hidl::manager::V1_0::IServiceNotification> &notification) {
    const ::android::sp<::android::hidl::manager::V1_0::IServiceManager> sm
            = ::android::hardware::defaultServiceManager();
    if (sm == nullptr) {
        return false;
    }
    ::android::hardware::Return<bool> success =
            sm->registerForNotifications("android.hardware.bluetooth.audio@2.1::IBluetoothAudioProvidersFactory",
                    serviceName, notification);
    return success.isOk() && success;
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
