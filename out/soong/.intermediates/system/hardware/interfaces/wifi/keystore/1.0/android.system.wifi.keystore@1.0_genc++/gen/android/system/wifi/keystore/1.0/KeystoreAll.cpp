#define LOG_TAG "android.system.wifi.keystore@1.0::Keystore"

#include <log/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <hidl/Static.h>
#include <hwbinder/ProcessState.h>
#include <utils/Trace.h>
#include <android/hidl/manager/1.0/IServiceManager.h>
#include <android/system/wifi/keystore/1.0/BpHwKeystore.h>
#include <android/system/wifi/keystore/1.0/BnHwKeystore.h>
#include <android/system/wifi/keystore/1.0/BsKeystore.h>
#include <android/hidl/base/1.0/BpHwBase.h>
#include <hidl/ServiceManagement.h>

namespace android {
namespace system {
namespace wifi {
namespace keystore {
namespace V1_0 {

const char* IKeystore::descriptor("android.system.wifi.keystore@1.0::IKeystore");

__attribute__((constructor)) static void static_constructor() {
    ::android::hardware::details::getBnConstructorMap().set(IKeystore::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hardware::IBinder> {
                return new BnHwKeystore(static_cast<IKeystore *>(iIntf));
            });
    ::android::hardware::details::getBsConstructorMap().set(IKeystore::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hidl::base::V1_0::IBase> {
                return new BsKeystore(static_cast<IKeystore *>(iIntf));
            });
}

__attribute__((destructor))static void static_destructor() {
    ::android::hardware::details::getBnConstructorMap().erase(IKeystore::descriptor);
    ::android::hardware::details::getBsConstructorMap().erase(IKeystore::descriptor);
}

// Methods from ::android::system::wifi::keystore::V1_0::IKeystore follow.
// no default implementation for: ::android::hardware::Return<void> IKeystore::getBlob(const ::android::hardware::hidl_string& key, getBlob_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IKeystore::getPublicKey(const ::android::hardware::hidl_string& keyId, getPublicKey_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IKeystore::sign(const ::android::hardware::hidl_string& keyId, const ::android::hardware::hidl_vec<uint8_t>& dataToSign, sign_cb _hidl_cb)

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> IKeystore::interfaceChain(interfaceChain_cb _hidl_cb){
    _hidl_cb({
        ::android::system::wifi::keystore::V1_0::IKeystore::descriptor,
        ::android::hidl::base::V1_0::IBase::descriptor,
    });
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IKeystore::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    (void)fd;
    (void)options;
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IKeystore::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    _hidl_cb(::android::system::wifi::keystore::V1_0::IKeystore::descriptor);
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IKeystore::getHashChain(getHashChain_cb _hidl_cb){
    _hidl_cb({
        (uint8_t[32]){176,255,13,199,86,132,93,209,50,249,152,232,197,95,26,13,126,62,253,138,168,95,98,83,119,111,183,1,40,20,82,75} /* b0ff0dc756845dd132f998e8c55f1a0d7e3efd8aa85f6253776fb7012814524b */,
        (uint8_t[32]){236,127,215,158,208,45,250,133,188,73,148,38,173,174,62,190,35,239,5,36,243,205,105,87,19,147,36,184,59,24,202,76} /* ec7fd79ed02dfa85bc499426adae3ebe23ef0524f3cd6957139324b83b18ca4c */});
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IKeystore::setHALInstrumentation(){
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> IKeystore::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    (void)cookie;
    return (recipient != nullptr);
}

::android::hardware::Return<void> IKeystore::ping(){
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IKeystore::getDebugInfo(getDebugInfo_cb _hidl_cb){
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

::android::hardware::Return<void> IKeystore::notifySyspropsChanged(){
    ::android::report_sysprop_change();
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> IKeystore::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
    return (recipient != nullptr);
}


::android::hardware::Return<::android::sp<::android::system::wifi::keystore::V1_0::IKeystore>> IKeystore::castFrom(const ::android::sp<::android::system::wifi::keystore::V1_0::IKeystore>& parent, bool /* emitError */) {
    return parent;
}

::android::hardware::Return<::android::sp<::android::system::wifi::keystore::V1_0::IKeystore>> IKeystore::castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<IKeystore, ::android::hidl::base::V1_0::IBase, BpHwKeystore>(
            parent, "android.system.wifi.keystore@1.0::IKeystore", emitError);
}

BpHwKeystore::BpHwKeystore(const ::android::sp<::android::hardware::IBinder> &_hidl_impl)
        : BpInterface<IKeystore>(_hidl_impl),
          ::android::hardware::details::HidlInstrumentor("android.system.wifi.keystore@1.0", "IKeystore") {
}

void BpHwKeystore::onLastStrongRef(const void* id) {
    {
        std::unique_lock<std::mutex> lock(_hidl_mMutex);
        _hidl_mDeathRecipients.clear();
    }

    BpInterface<IKeystore>::onLastStrongRef(id);
}
// Methods from ::android::system::wifi::keystore::V1_0::IKeystore follow.
::android::hardware::Return<void> BpHwKeystore::_hidl_getBlob(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::hidl_string& key, getBlob_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IKeystore::getBlob::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&key);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.system.wifi.keystore", "1.0", "IKeystore", "getBlob", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwKeystore::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_key_parent;

    _hidl_err = _hidl_data.writeBuffer(&key, sizeof(key), &_hidl_key_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            key,
            &_hidl_data,
            _hidl_key_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(1 /* getBlob */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::system::wifi::keystore::V1_0::IKeystore::KeystoreStatusCode _hidl_out_status;
        const ::android::hardware::hidl_vec<uint8_t>* _hidl_out_value;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        _hidl_err = _hidl_reply.readUint32((uint32_t *)&_hidl_out_status);
        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_value_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_value), &_hidl__hidl_out_value_parent,  reinterpret_cast<const void **>(&_hidl_out_value));

        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_value_child;

        _hidl_err = ::android::hardware::readEmbeddedFromParcel(
                const_cast<::android::hardware::hidl_vec<uint8_t> &>(*_hidl_out_value),
                _hidl_reply,
                _hidl__hidl_out_value_parent,
                0 /* parentOffset */, &_hidl__hidl_out_value_child);

        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(_hidl_out_status, *_hidl_out_value);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)_hidl_out_value);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.system.wifi.keystore", "1.0", "IKeystore", "getBlob", &_hidl_args);
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

::android::hardware::Return<void> BpHwKeystore::_hidl_getPublicKey(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::hidl_string& keyId, getPublicKey_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IKeystore::getPublicKey::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&keyId);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.system.wifi.keystore", "1.0", "IKeystore", "getPublicKey", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwKeystore::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_keyId_parent;

    _hidl_err = _hidl_data.writeBuffer(&keyId, sizeof(keyId), &_hidl_keyId_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            keyId,
            &_hidl_data,
            _hidl_keyId_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(2 /* getPublicKey */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::system::wifi::keystore::V1_0::IKeystore::KeystoreStatusCode _hidl_out_status;
        const ::android::hardware::hidl_vec<uint8_t>* _hidl_out_publicKey;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        _hidl_err = _hidl_reply.readUint32((uint32_t *)&_hidl_out_status);
        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_publicKey_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_publicKey), &_hidl__hidl_out_publicKey_parent,  reinterpret_cast<const void **>(&_hidl_out_publicKey));

        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_publicKey_child;

        _hidl_err = ::android::hardware::readEmbeddedFromParcel(
                const_cast<::android::hardware::hidl_vec<uint8_t> &>(*_hidl_out_publicKey),
                _hidl_reply,
                _hidl__hidl_out_publicKey_parent,
                0 /* parentOffset */, &_hidl__hidl_out_publicKey_child);

        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(_hidl_out_status, *_hidl_out_publicKey);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)_hidl_out_publicKey);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.system.wifi.keystore", "1.0", "IKeystore", "getPublicKey", &_hidl_args);
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

::android::hardware::Return<void> BpHwKeystore::_hidl_sign(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::hidl_string& keyId, const ::android::hardware::hidl_vec<uint8_t>& dataToSign, sign_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IKeystore::sign::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&keyId);
        _hidl_args.push_back((void *)&dataToSign);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.system.wifi.keystore", "1.0", "IKeystore", "sign", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwKeystore::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_keyId_parent;

    _hidl_err = _hidl_data.writeBuffer(&keyId, sizeof(keyId), &_hidl_keyId_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            keyId,
            &_hidl_data,
            _hidl_keyId_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_dataToSign_parent;

    _hidl_err = _hidl_data.writeBuffer(&dataToSign, sizeof(dataToSign), &_hidl_dataToSign_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_dataToSign_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            dataToSign,
            &_hidl_data,
            _hidl_dataToSign_parent,
            0 /* parentOffset */, &_hidl_dataToSign_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(3 /* sign */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::system::wifi::keystore::V1_0::IKeystore::KeystoreStatusCode _hidl_out_status;
        const ::android::hardware::hidl_vec<uint8_t>* _hidl_out_signedData;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        _hidl_err = _hidl_reply.readUint32((uint32_t *)&_hidl_out_status);
        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_signedData_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_signedData), &_hidl__hidl_out_signedData_parent,  reinterpret_cast<const void **>(&_hidl_out_signedData));

        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_signedData_child;

        _hidl_err = ::android::hardware::readEmbeddedFromParcel(
                const_cast<::android::hardware::hidl_vec<uint8_t> &>(*_hidl_out_signedData),
                _hidl_reply,
                _hidl__hidl_out_signedData_parent,
                0 /* parentOffset */, &_hidl__hidl_out_signedData_child);

        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(_hidl_out_status, *_hidl_out_signedData);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)_hidl_out_signedData);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.system.wifi.keystore", "1.0", "IKeystore", "sign", &_hidl_args);
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


// Methods from ::android::system::wifi::keystore::V1_0::IKeystore follow.
::android::hardware::Return<void> BpHwKeystore::getBlob(const ::android::hardware::hidl_string& key, getBlob_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::system::wifi::keystore::V1_0::BpHwKeystore::_hidl_getBlob(this, this, key, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwKeystore::getPublicKey(const ::android::hardware::hidl_string& keyId, getPublicKey_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::system::wifi::keystore::V1_0::BpHwKeystore::_hidl_getPublicKey(this, this, keyId, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwKeystore::sign(const ::android::hardware::hidl_string& keyId, const ::android::hardware::hidl_vec<uint8_t>& dataToSign, sign_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::system::wifi::keystore::V1_0::BpHwKeystore::_hidl_sign(this, this, keyId, dataToSign, _hidl_cb);

    return _hidl_out;
}


// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BpHwKeystore::interfaceChain(interfaceChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwKeystore::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_debug(this, this, fd, options);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwKeystore::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceDescriptor(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwKeystore::getHashChain(getHashChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getHashChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwKeystore::setHALInstrumentation(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_setHALInstrumentation(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwKeystore::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    ::android::hardware::ProcessState::self()->startThreadPool();
    ::android::hardware::hidl_binder_death_recipient *binder_recipient = new ::android::hardware::hidl_binder_death_recipient(recipient, cookie, this);
    std::unique_lock<std::mutex> lock(_hidl_mMutex);
    _hidl_mDeathRecipients.push_back(binder_recipient);
    return (remote()->linkToDeath(binder_recipient) == ::android::OK);
}

::android::hardware::Return<void> BpHwKeystore::ping(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_ping(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwKeystore::getDebugInfo(getDebugInfo_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getDebugInfo(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwKeystore::notifySyspropsChanged(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_notifySyspropsChanged(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwKeystore::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
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


BnHwKeystore::BnHwKeystore(const ::android::sp<IKeystore> &_hidl_impl)
        : ::android::hidl::base::V1_0::BnHwBase(_hidl_impl, "android.system.wifi.keystore@1.0", "IKeystore") { 
            _hidl_mImpl = _hidl_impl;
            auto prio = ::android::hardware::getMinSchedulerPolicy(_hidl_impl);
            mSchedPolicy = prio.sched_policy;
            mSchedPriority = prio.prio;
            setRequestingSid(::android::hardware::getRequestingSid(_hidl_impl));
}

BnHwKeystore::~BnHwKeystore() {
    ::android::hardware::details::gBnMap->eraseIfEqual(_hidl_mImpl.get(), this);
}

// Methods from ::android::system::wifi::keystore::V1_0::IKeystore follow.
::android::status_t BnHwKeystore::_hidl_getBlob(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwKeystore::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    const ::android::hardware::hidl_string* key;

    size_t _hidl_key_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*key), &_hidl_key_parent,  reinterpret_cast<const void **>(&key));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(*key),
            _hidl_data,
            _hidl_key_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IKeystore::getBlob::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)key);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.system.wifi.keystore", "1.0", "IKeystore", "getBlob", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IKeystore*>(_hidl_this->getImpl().get())->getBlob(*key, [&](const auto &_hidl_out_status, const auto &_hidl_out_value) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("getBlob: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeUint32((uint32_t)_hidl_out_status);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_value_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_value, sizeof(_hidl_out_value), &_hidl__hidl_out_value_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_value_child;

        _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                _hidl_out_value,
                _hidl_reply,
                _hidl__hidl_out_value_parent,
                0 /* parentOffset */, &_hidl__hidl_out_value_child);

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)&_hidl_out_value);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.system.wifi.keystore", "1.0", "IKeystore", "getBlob", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("getBlob: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwKeystore::_hidl_getPublicKey(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwKeystore::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    const ::android::hardware::hidl_string* keyId;

    size_t _hidl_keyId_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*keyId), &_hidl_keyId_parent,  reinterpret_cast<const void **>(&keyId));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(*keyId),
            _hidl_data,
            _hidl_keyId_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IKeystore::getPublicKey::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)keyId);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.system.wifi.keystore", "1.0", "IKeystore", "getPublicKey", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IKeystore*>(_hidl_this->getImpl().get())->getPublicKey(*keyId, [&](const auto &_hidl_out_status, const auto &_hidl_out_publicKey) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("getPublicKey: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeUint32((uint32_t)_hidl_out_status);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_publicKey_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_publicKey, sizeof(_hidl_out_publicKey), &_hidl__hidl_out_publicKey_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_publicKey_child;

        _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                _hidl_out_publicKey,
                _hidl_reply,
                _hidl__hidl_out_publicKey_parent,
                0 /* parentOffset */, &_hidl__hidl_out_publicKey_child);

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)&_hidl_out_publicKey);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.system.wifi.keystore", "1.0", "IKeystore", "getPublicKey", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("getPublicKey: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwKeystore::_hidl_sign(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwKeystore::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    const ::android::hardware::hidl_string* keyId;
    const ::android::hardware::hidl_vec<uint8_t>* dataToSign;

    size_t _hidl_keyId_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*keyId), &_hidl_keyId_parent,  reinterpret_cast<const void **>(&keyId));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(*keyId),
            _hidl_data,
            _hidl_keyId_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_dataToSign_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*dataToSign), &_hidl_dataToSign_parent,  reinterpret_cast<const void **>(&dataToSign));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_dataToSign_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(*dataToSign),
            _hidl_data,
            _hidl_dataToSign_parent,
            0 /* parentOffset */, &_hidl_dataToSign_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IKeystore::sign::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)keyId);
        _hidl_args.push_back((void *)dataToSign);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.system.wifi.keystore", "1.0", "IKeystore", "sign", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IKeystore*>(_hidl_this->getImpl().get())->sign(*keyId, *dataToSign, [&](const auto &_hidl_out_status, const auto &_hidl_out_signedData) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("sign: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeUint32((uint32_t)_hidl_out_status);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_signedData_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_signedData, sizeof(_hidl_out_signedData), &_hidl__hidl_out_signedData_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_signedData_child;

        _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                _hidl_out_signedData,
                _hidl_reply,
                _hidl__hidl_out_signedData_parent,
                0 /* parentOffset */, &_hidl__hidl_out_signedData_child);

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)&_hidl_out_signedData);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.system.wifi.keystore", "1.0", "IKeystore", "sign", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("sign: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}


// Methods from ::android::system::wifi::keystore::V1_0::IKeystore follow.

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BnHwKeystore::ping() {
    return ::android::hardware::Void();
}
::android::hardware::Return<void> BnHwKeystore::getDebugInfo(getDebugInfo_cb _hidl_cb) {
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

::android::status_t BnHwKeystore::onTransact(
        uint32_t _hidl_code,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        uint32_t _hidl_flags,
        TransactCallback _hidl_cb) {
    ::android::status_t _hidl_err = ::android::OK;

    switch (_hidl_code) {
        case 1 /* getBlob */:
        {
            _hidl_err = ::android::system::wifi::keystore::V1_0::BnHwKeystore::_hidl_getBlob(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 2 /* getPublicKey */:
        {
            _hidl_err = ::android::system::wifi::keystore::V1_0::BnHwKeystore::_hidl_getPublicKey(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 3 /* sign */:
        {
            _hidl_err = ::android::system::wifi::keystore::V1_0::BnHwKeystore::_hidl_sign(this, _hidl_data, _hidl_reply, _hidl_cb);
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

BsKeystore::BsKeystore(const ::android::sp<::android::system::wifi::keystore::V1_0::IKeystore> impl) : ::android::hardware::details::HidlInstrumentor("android.system.wifi.keystore@1.0", "IKeystore"), mImpl(impl) {
    mOnewayQueue.start(3000 /* similar limit to binderized */);
}

::android::hardware::Return<void> BsKeystore::addOnewayTask(std::function<void(void)> fun) {
    if (!mOnewayQueue.push(fun)) {
        return ::android::hardware::Status::fromExceptionCode(
                ::android::hardware::Status::EX_TRANSACTION_FAILED,
                "Passthrough oneway function queue exceeds maximum size.");
    }
    return ::android::hardware::Status();
}

::android::sp<IKeystore> IKeystore::tryGetService(const std::string &serviceName, const bool getStub) {
    return ::android::hardware::details::getServiceInternal<BpHwKeystore>(serviceName, false, getStub);
}

::android::sp<IKeystore> IKeystore::getService(const std::string &serviceName, const bool getStub) {
    return ::android::hardware::details::getServiceInternal<BpHwKeystore>(serviceName, true, getStub);
}

::android::status_t IKeystore::registerAsService(const std::string &serviceName) {
    return ::android::hardware::details::registerAsServiceInternal(this, serviceName);
}

bool IKeystore::registerForNotifications(
        const std::string &serviceName,
        const ::android::sp<::android::hidl::manager::V1_0::IServiceNotification> &notification) {
    const ::android::sp<::android::hidl::manager::V1_0::IServiceManager> sm
            = ::android::hardware::defaultServiceManager();
    if (sm == nullptr) {
        return false;
    }
    ::android::hardware::Return<bool> success =
            sm->registerForNotifications("android.system.wifi.keystore@1.0::IKeystore",
                    serviceName, notification);
    return success.isOk() && success;
}

static_assert(sizeof(::android::hardware::MQDescriptor<char, ::android::hardware::kSynchronizedReadWrite>) == 32, "wrong size");
static_assert(sizeof(::android::hardware::hidl_handle) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_memory) == 40, "wrong size");
static_assert(sizeof(::android::hardware::hidl_string) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_vec<char>) == 16, "wrong size");

}  // namespace V1_0
}  // namespace keystore
}  // namespace wifi
}  // namespace system
}  // namespace android
