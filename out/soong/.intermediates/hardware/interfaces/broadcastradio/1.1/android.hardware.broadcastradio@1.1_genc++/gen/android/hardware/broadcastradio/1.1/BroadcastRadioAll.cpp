#define LOG_TAG "android.hardware.broadcastradio@1.1::BroadcastRadio"

#include <log/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <hidl/Static.h>
#include <hwbinder/ProcessState.h>
#include <utils/Trace.h>
#include <android/hidl/manager/1.0/IServiceManager.h>
#include <android/hardware/broadcastradio/1.1/BpHwBroadcastRadio.h>
#include <android/hardware/broadcastradio/1.1/BnHwBroadcastRadio.h>
#include <android/hardware/broadcastradio/1.1/BsBroadcastRadio.h>
#include <android/hardware/broadcastradio/1.0/BpHwBroadcastRadio.h>
#include <android/hidl/base/1.0/BpHwBase.h>
#include <hidl/ServiceManagement.h>

namespace android {
namespace hardware {
namespace broadcastradio {
namespace V1_1 {

const char* IBroadcastRadio::descriptor("android.hardware.broadcastradio@1.1::IBroadcastRadio");

__attribute__((constructor)) static void static_constructor() {
    ::android::hardware::details::getBnConstructorMap().set(IBroadcastRadio::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hardware::IBinder> {
                return new BnHwBroadcastRadio(static_cast<IBroadcastRadio *>(iIntf));
            });
    ::android::hardware::details::getBsConstructorMap().set(IBroadcastRadio::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hidl::base::V1_0::IBase> {
                return new BsBroadcastRadio(static_cast<IBroadcastRadio *>(iIntf));
            });
}

__attribute__((destructor))static void static_destructor() {
    ::android::hardware::details::getBnConstructorMap().erase(IBroadcastRadio::descriptor);
    ::android::hardware::details::getBsConstructorMap().erase(IBroadcastRadio::descriptor);
}

// Methods from ::android::hardware::broadcastradio::V1_0::IBroadcastRadio follow.
// no default implementation for: ::android::hardware::Return<void> IBroadcastRadio::getProperties(getProperties_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IBroadcastRadio::openTuner(const ::android::hardware::broadcastradio::V1_0::BandConfig& config, bool audio, const ::android::sp<::android::hardware::broadcastradio::V1_0::ITunerCallback>& callback, openTuner_cb _hidl_cb)

// Methods from ::android::hardware::broadcastradio::V1_1::IBroadcastRadio follow.
// no default implementation for: ::android::hardware::Return<void> IBroadcastRadio::getProperties_1_1(getProperties_1_1_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IBroadcastRadio::getImage(int32_t id, getImage_cb _hidl_cb)

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> IBroadcastRadio::interfaceChain(interfaceChain_cb _hidl_cb){
    _hidl_cb({
        ::android::hardware::broadcastradio::V1_1::IBroadcastRadio::descriptor,
        ::android::hardware::broadcastradio::V1_0::IBroadcastRadio::descriptor,
        ::android::hidl::base::V1_0::IBase::descriptor,
    });
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IBroadcastRadio::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    (void)fd;
    (void)options;
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IBroadcastRadio::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    _hidl_cb(::android::hardware::broadcastradio::V1_1::IBroadcastRadio::descriptor);
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IBroadcastRadio::getHashChain(getHashChain_cb _hidl_cb){
    _hidl_cb({
        (uint8_t[32]){201,105,148,131,248,206,254,79,155,57,180,185,96,155,118,202,178,221,22,89,160,97,136,5,107,69,121,125,51,125,66,86} /* c9699483f8cefe4f9b39b4b9609b76cab2dd1659a06188056b45797d337d4256 */,
        (uint8_t[32]){169,141,73,242,55,18,167,204,50,125,30,6,2,208,95,111,58,211,44,251,92,116,113,29,0,156,114,102,17,238,28,147} /* a98d49f23712a7cc327d1e0602d05f6f3ad32cfb5c74711d009c726611ee1c93 */,
        (uint8_t[32]){236,127,215,158,208,45,250,133,188,73,148,38,173,174,62,190,35,239,5,36,243,205,105,87,19,147,36,184,59,24,202,76} /* ec7fd79ed02dfa85bc499426adae3ebe23ef0524f3cd6957139324b83b18ca4c */});
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IBroadcastRadio::setHALInstrumentation(){
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> IBroadcastRadio::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    (void)cookie;
    return (recipient != nullptr);
}

::android::hardware::Return<void> IBroadcastRadio::ping(){
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IBroadcastRadio::getDebugInfo(getDebugInfo_cb _hidl_cb){
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

::android::hardware::Return<void> IBroadcastRadio::notifySyspropsChanged(){
    ::android::report_sysprop_change();
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> IBroadcastRadio::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
    return (recipient != nullptr);
}


::android::hardware::Return<::android::sp<::android::hardware::broadcastradio::V1_1::IBroadcastRadio>> IBroadcastRadio::castFrom(const ::android::sp<::android::hardware::broadcastradio::V1_1::IBroadcastRadio>& parent, bool /* emitError */) {
    return parent;
}

::android::hardware::Return<::android::sp<::android::hardware::broadcastradio::V1_1::IBroadcastRadio>> IBroadcastRadio::castFrom(const ::android::sp<::android::hardware::broadcastradio::V1_0::IBroadcastRadio>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<IBroadcastRadio, ::android::hardware::broadcastradio::V1_0::IBroadcastRadio, BpHwBroadcastRadio>(
            parent, "android.hardware.broadcastradio@1.1::IBroadcastRadio", emitError);
}

::android::hardware::Return<::android::sp<::android::hardware::broadcastradio::V1_1::IBroadcastRadio>> IBroadcastRadio::castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<IBroadcastRadio, ::android::hidl::base::V1_0::IBase, BpHwBroadcastRadio>(
            parent, "android.hardware.broadcastradio@1.1::IBroadcastRadio", emitError);
}

BpHwBroadcastRadio::BpHwBroadcastRadio(const ::android::sp<::android::hardware::IBinder> &_hidl_impl)
        : BpInterface<IBroadcastRadio>(_hidl_impl),
          ::android::hardware::details::HidlInstrumentor("android.hardware.broadcastradio@1.1", "IBroadcastRadio") {
}

void BpHwBroadcastRadio::onLastStrongRef(const void* id) {
    {
        std::unique_lock<std::mutex> lock(_hidl_mMutex);
        _hidl_mDeathRecipients.clear();
    }

    BpInterface<IBroadcastRadio>::onLastStrongRef(id);
}
// Methods from ::android::hardware::broadcastradio::V1_1::IBroadcastRadio follow.
::android::hardware::Return<void> BpHwBroadcastRadio::_hidl_getProperties_1_1(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, getProperties_1_1_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IBroadcastRadio::getProperties_1_1::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.broadcastradio", "1.1", "IBroadcastRadio", "getProperties_1_1", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwBroadcastRadio::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(3 /* getProperties_1_1 */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::broadcastradio::V1_1::Properties* _hidl_out_properties;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        size_t _hidl__hidl_out_properties_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_properties), &_hidl__hidl_out_properties_parent,  const_cast<const void**>(reinterpret_cast<void **>(&_hidl_out_properties)));
        if (_hidl_err != ::android::OK) { return; }

        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::broadcastradio::V1_1::Properties &>(*_hidl_out_properties),
                _hidl_reply,
                _hidl__hidl_out_properties_parent,
                0 /* parentOffset */);

        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(*_hidl_out_properties);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)_hidl_out_properties);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.broadcastradio", "1.1", "IBroadcastRadio", "getProperties_1_1", &_hidl_args);
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

::android::hardware::Return<void> BpHwBroadcastRadio::_hidl_getImage(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, int32_t id, getImage_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IBroadcastRadio::getImage::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&id);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.broadcastradio", "1.1", "IBroadcastRadio", "getImage", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwBroadcastRadio::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32(id);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(4 /* getImage */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        const ::android::hardware::hidl_vec<uint8_t>* _hidl_out_image;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        size_t _hidl__hidl_out_image_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_image), &_hidl__hidl_out_image_parent,  reinterpret_cast<const void **>(&_hidl_out_image));

        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_image_child;

        _hidl_err = ::android::hardware::readEmbeddedFromParcel(
                const_cast<::android::hardware::hidl_vec<uint8_t> &>(*_hidl_out_image),
                _hidl_reply,
                _hidl__hidl_out_image_parent,
                0 /* parentOffset */, &_hidl__hidl_out_image_child);

        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(*_hidl_out_image);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)_hidl_out_image);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.broadcastradio", "1.1", "IBroadcastRadio", "getImage", &_hidl_args);
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


// Methods from ::android::hardware::broadcastradio::V1_0::IBroadcastRadio follow.
::android::hardware::Return<void> BpHwBroadcastRadio::getProperties(getProperties_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::broadcastradio::V1_0::BpHwBroadcastRadio::_hidl_getProperties(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwBroadcastRadio::openTuner(const ::android::hardware::broadcastradio::V1_0::BandConfig& config, bool audio, const ::android::sp<::android::hardware::broadcastradio::V1_0::ITunerCallback>& callback, openTuner_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::broadcastradio::V1_0::BpHwBroadcastRadio::_hidl_openTuner(this, this, config, audio, callback, _hidl_cb);

    return _hidl_out;
}


// Methods from ::android::hardware::broadcastradio::V1_1::IBroadcastRadio follow.
::android::hardware::Return<void> BpHwBroadcastRadio::getProperties_1_1(getProperties_1_1_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::broadcastradio::V1_1::BpHwBroadcastRadio::_hidl_getProperties_1_1(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwBroadcastRadio::getImage(int32_t id, getImage_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::broadcastradio::V1_1::BpHwBroadcastRadio::_hidl_getImage(this, this, id, _hidl_cb);

    return _hidl_out;
}


// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BpHwBroadcastRadio::interfaceChain(interfaceChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwBroadcastRadio::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_debug(this, this, fd, options);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwBroadcastRadio::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceDescriptor(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwBroadcastRadio::getHashChain(getHashChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getHashChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwBroadcastRadio::setHALInstrumentation(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_setHALInstrumentation(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwBroadcastRadio::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    ::android::hardware::ProcessState::self()->startThreadPool();
    ::android::hardware::hidl_binder_death_recipient *binder_recipient = new ::android::hardware::hidl_binder_death_recipient(recipient, cookie, this);
    std::unique_lock<std::mutex> lock(_hidl_mMutex);
    _hidl_mDeathRecipients.push_back(binder_recipient);
    return (remote()->linkToDeath(binder_recipient) == ::android::OK);
}

::android::hardware::Return<void> BpHwBroadcastRadio::ping(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_ping(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwBroadcastRadio::getDebugInfo(getDebugInfo_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getDebugInfo(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwBroadcastRadio::notifySyspropsChanged(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_notifySyspropsChanged(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwBroadcastRadio::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
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


BnHwBroadcastRadio::BnHwBroadcastRadio(const ::android::sp<IBroadcastRadio> &_hidl_impl)
        : ::android::hidl::base::V1_0::BnHwBase(_hidl_impl, "android.hardware.broadcastradio@1.1", "IBroadcastRadio") { 
            _hidl_mImpl = _hidl_impl;
            auto prio = ::android::hardware::getMinSchedulerPolicy(_hidl_impl);
            mSchedPolicy = prio.sched_policy;
            mSchedPriority = prio.prio;
            setRequestingSid(::android::hardware::getRequestingSid(_hidl_impl));
}

BnHwBroadcastRadio::~BnHwBroadcastRadio() {
    ::android::hardware::details::gBnMap->eraseIfEqual(_hidl_mImpl.get(), this);
}

// Methods from ::android::hardware::broadcastradio::V1_1::IBroadcastRadio follow.
::android::status_t BnHwBroadcastRadio::_hidl_getProperties_1_1(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwBroadcastRadio::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IBroadcastRadio::getProperties_1_1::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.broadcastradio", "1.1", "IBroadcastRadio", "getProperties_1_1", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IBroadcastRadio*>(_hidl_this->getImpl().get())->getProperties_1_1([&](const auto &_hidl_out_properties) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("getProperties_1_1: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

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
            _hidl_args.push_back((void *)&_hidl_out_properties);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.broadcastradio", "1.1", "IBroadcastRadio", "getProperties_1_1", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("getProperties_1_1: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwBroadcastRadio::_hidl_getImage(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwBroadcastRadio::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    int32_t id;

    _hidl_err = _hidl_data.readInt32(&id);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IBroadcastRadio::getImage::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&id);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.broadcastradio", "1.1", "IBroadcastRadio", "getImage", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IBroadcastRadio*>(_hidl_this->getImpl().get())->getImage(id, [&](const auto &_hidl_out_image) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("getImage: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        size_t _hidl__hidl_out_image_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_image, sizeof(_hidl_out_image), &_hidl__hidl_out_image_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_image_child;

        _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                _hidl_out_image,
                _hidl_reply,
                _hidl__hidl_out_image_parent,
                0 /* parentOffset */, &_hidl__hidl_out_image_child);

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_image);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.broadcastradio", "1.1", "IBroadcastRadio", "getImage", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("getImage: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}


// Methods from ::android::hardware::broadcastradio::V1_0::IBroadcastRadio follow.

// Methods from ::android::hardware::broadcastradio::V1_1::IBroadcastRadio follow.

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BnHwBroadcastRadio::ping() {
    return ::android::hardware::Void();
}
::android::hardware::Return<void> BnHwBroadcastRadio::getDebugInfo(getDebugInfo_cb _hidl_cb) {
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

::android::status_t BnHwBroadcastRadio::onTransact(
        uint32_t _hidl_code,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        uint32_t _hidl_flags,
        TransactCallback _hidl_cb) {
    ::android::status_t _hidl_err = ::android::OK;

    switch (_hidl_code) {
        case 1 /* getProperties */:
        {
            _hidl_err = ::android::hardware::broadcastradio::V1_0::BnHwBroadcastRadio::_hidl_getProperties(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 2 /* openTuner */:
        {
            _hidl_err = ::android::hardware::broadcastradio::V1_0::BnHwBroadcastRadio::_hidl_openTuner(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 3 /* getProperties_1_1 */:
        {
            _hidl_err = ::android::hardware::broadcastradio::V1_1::BnHwBroadcastRadio::_hidl_getProperties_1_1(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 4 /* getImage */:
        {
            _hidl_err = ::android::hardware::broadcastradio::V1_1::BnHwBroadcastRadio::_hidl_getImage(this, _hidl_data, _hidl_reply, _hidl_cb);
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

BsBroadcastRadio::BsBroadcastRadio(const ::android::sp<::android::hardware::broadcastradio::V1_1::IBroadcastRadio> impl) : ::android::hardware::details::HidlInstrumentor("android.hardware.broadcastradio@1.1", "IBroadcastRadio"), mImpl(impl) {
    mOnewayQueue.start(3000 /* similar limit to binderized */);
}

::android::hardware::Return<void> BsBroadcastRadio::addOnewayTask(std::function<void(void)> fun) {
    if (!mOnewayQueue.push(fun)) {
        return ::android::hardware::Status::fromExceptionCode(
                ::android::hardware::Status::EX_TRANSACTION_FAILED,
                "Passthrough oneway function queue exceeds maximum size.");
    }
    return ::android::hardware::Status();
}

::android::sp<IBroadcastRadio> IBroadcastRadio::tryGetService(const std::string &serviceName, const bool getStub) {
    return ::android::hardware::details::getServiceInternal<BpHwBroadcastRadio>(serviceName, false, getStub);
}

::android::sp<IBroadcastRadio> IBroadcastRadio::getService(const std::string &serviceName, const bool getStub) {
    return ::android::hardware::details::getServiceInternal<BpHwBroadcastRadio>(serviceName, true, getStub);
}

::android::status_t IBroadcastRadio::registerAsService(const std::string &serviceName) {
    return ::android::hardware::details::registerAsServiceInternal(this, serviceName);
}

bool IBroadcastRadio::registerForNotifications(
        const std::string &serviceName,
        const ::android::sp<::android::hidl::manager::V1_0::IServiceNotification> &notification) {
    const ::android::sp<::android::hidl::manager::V1_0::IServiceManager> sm
            = ::android::hardware::defaultServiceManager();
    if (sm == nullptr) {
        return false;
    }
    ::android::hardware::Return<bool> success =
            sm->registerForNotifications("android.hardware.broadcastradio@1.1::IBroadcastRadio",
                    serviceName, notification);
    return success.isOk() && success;
}

static_assert(sizeof(::android::hardware::MQDescriptor<char, ::android::hardware::kSynchronizedReadWrite>) == 32, "wrong size");
static_assert(sizeof(::android::hardware::hidl_handle) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_memory) == 40, "wrong size");
static_assert(sizeof(::android::hardware::hidl_string) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_vec<char>) == 16, "wrong size");

}  // namespace V1_1
}  // namespace broadcastradio
}  // namespace hardware
}  // namespace android
