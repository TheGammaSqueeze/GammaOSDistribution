#define LOG_TAG "android.hardware.keymaster@4.0::KeymasterDevice"

#include <log/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <hidl/Static.h>
#include <hwbinder/ProcessState.h>
#include <utils/Trace.h>
#include <android/hidl/manager/1.0/IServiceManager.h>
#include <android/hardware/keymaster/4.0/BpHwKeymasterDevice.h>
#include <android/hardware/keymaster/4.0/BnHwKeymasterDevice.h>
#include <android/hardware/keymaster/4.0/BsKeymasterDevice.h>
#include <android/hidl/base/1.0/BpHwBase.h>
#include <hidl/ServiceManagement.h>

namespace android {
namespace hardware {
namespace keymaster {
namespace V4_0 {

const char* IKeymasterDevice::descriptor("android.hardware.keymaster@4.0::IKeymasterDevice");

__attribute__((constructor)) static void static_constructor() {
    ::android::hardware::details::getBnConstructorMap().set(IKeymasterDevice::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hardware::IBinder> {
                return new BnHwKeymasterDevice(static_cast<IKeymasterDevice *>(iIntf));
            });
    ::android::hardware::details::getBsConstructorMap().set(IKeymasterDevice::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hidl::base::V1_0::IBase> {
                return new BsKeymasterDevice(static_cast<IKeymasterDevice *>(iIntf));
            });
}

__attribute__((destructor))static void static_destructor() {
    ::android::hardware::details::getBnConstructorMap().erase(IKeymasterDevice::descriptor);
    ::android::hardware::details::getBsConstructorMap().erase(IKeymasterDevice::descriptor);
}

// Methods from ::android::hardware::keymaster::V4_0::IKeymasterDevice follow.
// no default implementation for: ::android::hardware::Return<void> IKeymasterDevice::getHardwareInfo(getHardwareInfo_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IKeymasterDevice::getHmacSharingParameters(getHmacSharingParameters_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IKeymasterDevice::computeSharedHmac(const ::android::hardware::hidl_vec<::android::hardware::keymaster::V4_0::HmacSharingParameters>& params, computeSharedHmac_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IKeymasterDevice::verifyAuthorization(uint64_t operationHandle, const ::android::hardware::hidl_vec<::android::hardware::keymaster::V4_0::KeyParameter>& parametersToVerify, const ::android::hardware::keymaster::V4_0::HardwareAuthToken& authToken, verifyAuthorization_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<::android::hardware::keymaster::V4_0::ErrorCode> IKeymasterDevice::addRngEntropy(const ::android::hardware::hidl_vec<uint8_t>& data)
// no default implementation for: ::android::hardware::Return<void> IKeymasterDevice::generateKey(const ::android::hardware::hidl_vec<::android::hardware::keymaster::V4_0::KeyParameter>& keyParams, generateKey_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IKeymasterDevice::importKey(const ::android::hardware::hidl_vec<::android::hardware::keymaster::V4_0::KeyParameter>& keyParams, ::android::hardware::keymaster::V4_0::KeyFormat keyFormat, const ::android::hardware::hidl_vec<uint8_t>& keyData, importKey_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IKeymasterDevice::importWrappedKey(const ::android::hardware::hidl_vec<uint8_t>& wrappedKeyData, const ::android::hardware::hidl_vec<uint8_t>& wrappingKeyBlob, const ::android::hardware::hidl_vec<uint8_t>& maskingKey, const ::android::hardware::hidl_vec<::android::hardware::keymaster::V4_0::KeyParameter>& unwrappingParams, uint64_t passwordSid, uint64_t biometricSid, importWrappedKey_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IKeymasterDevice::getKeyCharacteristics(const ::android::hardware::hidl_vec<uint8_t>& keyBlob, const ::android::hardware::hidl_vec<uint8_t>& clientId, const ::android::hardware::hidl_vec<uint8_t>& appData, getKeyCharacteristics_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IKeymasterDevice::exportKey(::android::hardware::keymaster::V4_0::KeyFormat keyFormat, const ::android::hardware::hidl_vec<uint8_t>& keyBlob, const ::android::hardware::hidl_vec<uint8_t>& clientId, const ::android::hardware::hidl_vec<uint8_t>& appData, exportKey_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IKeymasterDevice::attestKey(const ::android::hardware::hidl_vec<uint8_t>& keyToAttest, const ::android::hardware::hidl_vec<::android::hardware::keymaster::V4_0::KeyParameter>& attestParams, attestKey_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IKeymasterDevice::upgradeKey(const ::android::hardware::hidl_vec<uint8_t>& keyBlobToUpgrade, const ::android::hardware::hidl_vec<::android::hardware::keymaster::V4_0::KeyParameter>& upgradeParams, upgradeKey_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<::android::hardware::keymaster::V4_0::ErrorCode> IKeymasterDevice::deleteKey(const ::android::hardware::hidl_vec<uint8_t>& keyBlob)
// no default implementation for: ::android::hardware::Return<::android::hardware::keymaster::V4_0::ErrorCode> IKeymasterDevice::deleteAllKeys()
// no default implementation for: ::android::hardware::Return<::android::hardware::keymaster::V4_0::ErrorCode> IKeymasterDevice::destroyAttestationIds()
// no default implementation for: ::android::hardware::Return<void> IKeymasterDevice::begin(::android::hardware::keymaster::V4_0::KeyPurpose purpose, const ::android::hardware::hidl_vec<uint8_t>& keyBlob, const ::android::hardware::hidl_vec<::android::hardware::keymaster::V4_0::KeyParameter>& inParams, const ::android::hardware::keymaster::V4_0::HardwareAuthToken& authToken, begin_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IKeymasterDevice::update(uint64_t operationHandle, const ::android::hardware::hidl_vec<::android::hardware::keymaster::V4_0::KeyParameter>& inParams, const ::android::hardware::hidl_vec<uint8_t>& input, const ::android::hardware::keymaster::V4_0::HardwareAuthToken& authToken, const ::android::hardware::keymaster::V4_0::VerificationToken& verificationToken, update_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IKeymasterDevice::finish(uint64_t operationHandle, const ::android::hardware::hidl_vec<::android::hardware::keymaster::V4_0::KeyParameter>& inParams, const ::android::hardware::hidl_vec<uint8_t>& input, const ::android::hardware::hidl_vec<uint8_t>& signature, const ::android::hardware::keymaster::V4_0::HardwareAuthToken& authToken, const ::android::hardware::keymaster::V4_0::VerificationToken& verificationToken, finish_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<::android::hardware::keymaster::V4_0::ErrorCode> IKeymasterDevice::abort(uint64_t operationHandle)

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> IKeymasterDevice::interfaceChain(interfaceChain_cb _hidl_cb){
    _hidl_cb({
        ::android::hardware::keymaster::V4_0::IKeymasterDevice::descriptor,
        ::android::hidl::base::V1_0::IBase::descriptor,
    });
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IKeymasterDevice::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    (void)fd;
    (void)options;
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IKeymasterDevice::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    _hidl_cb(::android::hardware::keymaster::V4_0::IKeymasterDevice::descriptor);
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IKeymasterDevice::getHashChain(getHashChain_cb _hidl_cb){
    _hidl_cb({
        (uint8_t[32]){96,23,180,242,72,31,235,15,255,206,174,129,198,43,195,114,200,152,153,139,45,143,230,159,189,57,133,157,58,49,94,94} /* 6017b4f2481feb0fffceae81c62bc372c898998b2d8fe69fbd39859d3a315e5e */,
        (uint8_t[32]){236,127,215,158,208,45,250,133,188,73,148,38,173,174,62,190,35,239,5,36,243,205,105,87,19,147,36,184,59,24,202,76} /* ec7fd79ed02dfa85bc499426adae3ebe23ef0524f3cd6957139324b83b18ca4c */});
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IKeymasterDevice::setHALInstrumentation(){
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> IKeymasterDevice::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    (void)cookie;
    return (recipient != nullptr);
}

::android::hardware::Return<void> IKeymasterDevice::ping(){
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IKeymasterDevice::getDebugInfo(getDebugInfo_cb _hidl_cb){
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

::android::hardware::Return<void> IKeymasterDevice::notifySyspropsChanged(){
    ::android::report_sysprop_change();
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> IKeymasterDevice::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
    return (recipient != nullptr);
}


::android::hardware::Return<::android::sp<::android::hardware::keymaster::V4_0::IKeymasterDevice>> IKeymasterDevice::castFrom(const ::android::sp<::android::hardware::keymaster::V4_0::IKeymasterDevice>& parent, bool /* emitError */) {
    return parent;
}

::android::hardware::Return<::android::sp<::android::hardware::keymaster::V4_0::IKeymasterDevice>> IKeymasterDevice::castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<IKeymasterDevice, ::android::hidl::base::V1_0::IBase, BpHwKeymasterDevice>(
            parent, "android.hardware.keymaster@4.0::IKeymasterDevice", emitError);
}

BpHwKeymasterDevice::BpHwKeymasterDevice(const ::android::sp<::android::hardware::IBinder> &_hidl_impl)
        : BpInterface<IKeymasterDevice>(_hidl_impl),
          ::android::hardware::details::HidlInstrumentor("android.hardware.keymaster@4.0", "IKeymasterDevice") {
}

void BpHwKeymasterDevice::onLastStrongRef(const void* id) {
    {
        std::unique_lock<std::mutex> lock(_hidl_mMutex);
        _hidl_mDeathRecipients.clear();
    }

    BpInterface<IKeymasterDevice>::onLastStrongRef(id);
}
// Methods from ::android::hardware::keymaster::V4_0::IKeymasterDevice follow.
::android::hardware::Return<void> BpHwKeymasterDevice::_hidl_getHardwareInfo(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, getHardwareInfo_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IKeymasterDevice::getHardwareInfo::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.keymaster", "4.0", "IKeymasterDevice", "getHardwareInfo", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_data.markSensitive();
    _hidl_err = _hidl_data.writeInterfaceToken(BpHwKeymasterDevice::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(1 /* getHardwareInfo */, _hidl_data, &_hidl_reply, 0 /* flags */ | 32u /* clear buf */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::keymaster::V4_0::SecurityLevel _hidl_out_securityLevel;
        const ::android::hardware::hidl_string* _hidl_out_keymasterName;
        const ::android::hardware::hidl_string* _hidl_out_keymasterAuthorName;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        _hidl_err = _hidl_reply.readUint32((uint32_t *)&_hidl_out_securityLevel);
        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_keymasterName_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_keymasterName), &_hidl__hidl_out_keymasterName_parent,  reinterpret_cast<const void **>(&_hidl_out_keymasterName));

        if (_hidl_err != ::android::OK) { return; }

        _hidl_err = ::android::hardware::readEmbeddedFromParcel(
                const_cast<::android::hardware::hidl_string &>(*_hidl_out_keymasterName),
                _hidl_reply,
                _hidl__hidl_out_keymasterName_parent,
                0 /* parentOffset */);

        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_keymasterAuthorName_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_keymasterAuthorName), &_hidl__hidl_out_keymasterAuthorName_parent,  reinterpret_cast<const void **>(&_hidl_out_keymasterAuthorName));

        if (_hidl_err != ::android::OK) { return; }

        _hidl_err = ::android::hardware::readEmbeddedFromParcel(
                const_cast<::android::hardware::hidl_string &>(*_hidl_out_keymasterAuthorName),
                _hidl_reply,
                _hidl__hidl_out_keymasterAuthorName_parent,
                0 /* parentOffset */);

        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(_hidl_out_securityLevel, *_hidl_out_keymasterName, *_hidl_out_keymasterAuthorName);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_securityLevel);
            _hidl_args.push_back((void *)_hidl_out_keymasterName);
            _hidl_args.push_back((void *)_hidl_out_keymasterAuthorName);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.keymaster", "4.0", "IKeymasterDevice", "getHardwareInfo", &_hidl_args);
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

::android::hardware::Return<void> BpHwKeymasterDevice::_hidl_getHmacSharingParameters(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, getHmacSharingParameters_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IKeymasterDevice::getHmacSharingParameters::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.keymaster", "4.0", "IKeymasterDevice", "getHmacSharingParameters", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_data.markSensitive();
    _hidl_err = _hidl_data.writeInterfaceToken(BpHwKeymasterDevice::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(2 /* getHmacSharingParameters */, _hidl_data, &_hidl_reply, 0 /* flags */ | 32u /* clear buf */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::keymaster::V4_0::ErrorCode _hidl_out_error;
        ::android::hardware::keymaster::V4_0::HmacSharingParameters* _hidl_out_params;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_error);
        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_params_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_params), &_hidl__hidl_out_params_parent,  const_cast<const void**>(reinterpret_cast<void **>(&_hidl_out_params)));
        if (_hidl_err != ::android::OK) { return; }

        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::keymaster::V4_0::HmacSharingParameters &>(*_hidl_out_params),
                _hidl_reply,
                _hidl__hidl_out_params_parent,
                0 /* parentOffset */);

        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(_hidl_out_error, *_hidl_out_params);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_error);
            _hidl_args.push_back((void *)_hidl_out_params);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.keymaster", "4.0", "IKeymasterDevice", "getHmacSharingParameters", &_hidl_args);
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

::android::hardware::Return<void> BpHwKeymasterDevice::_hidl_computeSharedHmac(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::hidl_vec<::android::hardware::keymaster::V4_0::HmacSharingParameters>& params, computeSharedHmac_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IKeymasterDevice::computeSharedHmac::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&params);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.keymaster", "4.0", "IKeymasterDevice", "computeSharedHmac", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_data.markSensitive();
    _hidl_err = _hidl_data.writeInterfaceToken(BpHwKeymasterDevice::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_params_parent;

    _hidl_err = _hidl_data.writeBuffer(&params, sizeof(params), &_hidl_params_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_params_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            params,
            &_hidl_data,
            _hidl_params_parent,
            0 /* parentOffset */, &_hidl_params_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < params.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                params[_hidl_index_0],
                &_hidl_data,
                _hidl_params_child,
                _hidl_index_0 * sizeof(::android::hardware::keymaster::V4_0::HmacSharingParameters));

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(3 /* computeSharedHmac */, _hidl_data, &_hidl_reply, 0 /* flags */ | 32u /* clear buf */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::keymaster::V4_0::ErrorCode _hidl_out_error;
        const ::android::hardware::hidl_vec<uint8_t>* _hidl_out_sharingCheck;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_error);
        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_sharingCheck_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_sharingCheck), &_hidl__hidl_out_sharingCheck_parent,  reinterpret_cast<const void **>(&_hidl_out_sharingCheck));

        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_sharingCheck_child;

        _hidl_err = ::android::hardware::readEmbeddedFromParcel(
                const_cast<::android::hardware::hidl_vec<uint8_t> &>(*_hidl_out_sharingCheck),
                _hidl_reply,
                _hidl__hidl_out_sharingCheck_parent,
                0 /* parentOffset */, &_hidl__hidl_out_sharingCheck_child);

        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(_hidl_out_error, *_hidl_out_sharingCheck);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_error);
            _hidl_args.push_back((void *)_hidl_out_sharingCheck);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.keymaster", "4.0", "IKeymasterDevice", "computeSharedHmac", &_hidl_args);
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

::android::hardware::Return<void> BpHwKeymasterDevice::_hidl_verifyAuthorization(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint64_t operationHandle, const ::android::hardware::hidl_vec<::android::hardware::keymaster::V4_0::KeyParameter>& parametersToVerify, const ::android::hardware::keymaster::V4_0::HardwareAuthToken& authToken, verifyAuthorization_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IKeymasterDevice::verifyAuthorization::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&operationHandle);
        _hidl_args.push_back((void *)&parametersToVerify);
        _hidl_args.push_back((void *)&authToken);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.keymaster", "4.0", "IKeymasterDevice", "verifyAuthorization", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_data.markSensitive();
    _hidl_err = _hidl_data.writeInterfaceToken(BpHwKeymasterDevice::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(operationHandle);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_parametersToVerify_parent;

    _hidl_err = _hidl_data.writeBuffer(&parametersToVerify, sizeof(parametersToVerify), &_hidl_parametersToVerify_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_parametersToVerify_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            parametersToVerify,
            &_hidl_data,
            _hidl_parametersToVerify_parent,
            0 /* parentOffset */, &_hidl_parametersToVerify_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < parametersToVerify.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                parametersToVerify[_hidl_index_0],
                &_hidl_data,
                _hidl_parametersToVerify_child,
                _hidl_index_0 * sizeof(::android::hardware::keymaster::V4_0::KeyParameter));

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    }

    size_t _hidl_authToken_parent;

    _hidl_err = _hidl_data.writeBuffer(&authToken, sizeof(authToken), &_hidl_authToken_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = writeEmbeddedToParcel(
            authToken,
            &_hidl_data,
            _hidl_authToken_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(4 /* verifyAuthorization */, _hidl_data, &_hidl_reply, 0 /* flags */ | 32u /* clear buf */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::keymaster::V4_0::ErrorCode _hidl_out_error;
        ::android::hardware::keymaster::V4_0::VerificationToken* _hidl_out_token;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_error);
        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_token_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_token), &_hidl__hidl_out_token_parent,  const_cast<const void**>(reinterpret_cast<void **>(&_hidl_out_token)));
        if (_hidl_err != ::android::OK) { return; }

        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::keymaster::V4_0::VerificationToken &>(*_hidl_out_token),
                _hidl_reply,
                _hidl__hidl_out_token_parent,
                0 /* parentOffset */);

        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(_hidl_out_error, *_hidl_out_token);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_error);
            _hidl_args.push_back((void *)_hidl_out_token);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.keymaster", "4.0", "IKeymasterDevice", "verifyAuthorization", &_hidl_args);
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

::android::hardware::Return<::android::hardware::keymaster::V4_0::ErrorCode> BpHwKeymasterDevice::_hidl_addRngEntropy(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::hidl_vec<uint8_t>& data) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IKeymasterDevice::addRngEntropy::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&data);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.keymaster", "4.0", "IKeymasterDevice", "addRngEntropy", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    ::android::hardware::keymaster::V4_0::ErrorCode _hidl_out_error;

    _hidl_data.markSensitive();
    _hidl_err = _hidl_data.writeInterfaceToken(BpHwKeymasterDevice::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_data_parent;

    _hidl_err = _hidl_data.writeBuffer(&data, sizeof(data), &_hidl_data_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_data_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            data,
            &_hidl_data,
            _hidl_data_parent,
            0 /* parentOffset */, &_hidl_data_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(5 /* addRngEntropy */, _hidl_data, &_hidl_reply, 0 /* flags */ | 32u /* clear buf */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_error);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_error);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.keymaster", "4.0", "IKeymasterDevice", "addRngEntropy", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<::android::hardware::keymaster::V4_0::ErrorCode>(_hidl_out_error);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<::android::hardware::keymaster::V4_0::ErrorCode>(_hidl_status);
}

::android::hardware::Return<void> BpHwKeymasterDevice::_hidl_generateKey(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::hidl_vec<::android::hardware::keymaster::V4_0::KeyParameter>& keyParams, generateKey_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IKeymasterDevice::generateKey::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&keyParams);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.keymaster", "4.0", "IKeymasterDevice", "generateKey", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_data.markSensitive();
    _hidl_err = _hidl_data.writeInterfaceToken(BpHwKeymasterDevice::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_keyParams_parent;

    _hidl_err = _hidl_data.writeBuffer(&keyParams, sizeof(keyParams), &_hidl_keyParams_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_keyParams_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            keyParams,
            &_hidl_data,
            _hidl_keyParams_parent,
            0 /* parentOffset */, &_hidl_keyParams_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < keyParams.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                keyParams[_hidl_index_0],
                &_hidl_data,
                _hidl_keyParams_child,
                _hidl_index_0 * sizeof(::android::hardware::keymaster::V4_0::KeyParameter));

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(6 /* generateKey */, _hidl_data, &_hidl_reply, 0 /* flags */ | 32u /* clear buf */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::keymaster::V4_0::ErrorCode _hidl_out_error;
        const ::android::hardware::hidl_vec<uint8_t>* _hidl_out_keyBlob;
        ::android::hardware::keymaster::V4_0::KeyCharacteristics* _hidl_out_keyCharacteristics;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_error);
        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_keyBlob_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_keyBlob), &_hidl__hidl_out_keyBlob_parent,  reinterpret_cast<const void **>(&_hidl_out_keyBlob));

        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_keyBlob_child;

        _hidl_err = ::android::hardware::readEmbeddedFromParcel(
                const_cast<::android::hardware::hidl_vec<uint8_t> &>(*_hidl_out_keyBlob),
                _hidl_reply,
                _hidl__hidl_out_keyBlob_parent,
                0 /* parentOffset */, &_hidl__hidl_out_keyBlob_child);

        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_keyCharacteristics_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_keyCharacteristics), &_hidl__hidl_out_keyCharacteristics_parent,  const_cast<const void**>(reinterpret_cast<void **>(&_hidl_out_keyCharacteristics)));
        if (_hidl_err != ::android::OK) { return; }

        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::keymaster::V4_0::KeyCharacteristics &>(*_hidl_out_keyCharacteristics),
                _hidl_reply,
                _hidl__hidl_out_keyCharacteristics_parent,
                0 /* parentOffset */);

        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(_hidl_out_error, *_hidl_out_keyBlob, *_hidl_out_keyCharacteristics);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_error);
            _hidl_args.push_back((void *)_hidl_out_keyBlob);
            _hidl_args.push_back((void *)_hidl_out_keyCharacteristics);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.keymaster", "4.0", "IKeymasterDevice", "generateKey", &_hidl_args);
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

::android::hardware::Return<void> BpHwKeymasterDevice::_hidl_importKey(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::hidl_vec<::android::hardware::keymaster::V4_0::KeyParameter>& keyParams, ::android::hardware::keymaster::V4_0::KeyFormat keyFormat, const ::android::hardware::hidl_vec<uint8_t>& keyData, importKey_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IKeymasterDevice::importKey::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&keyParams);
        _hidl_args.push_back((void *)&keyFormat);
        _hidl_args.push_back((void *)&keyData);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.keymaster", "4.0", "IKeymasterDevice", "importKey", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_data.markSensitive();
    _hidl_err = _hidl_data.writeInterfaceToken(BpHwKeymasterDevice::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_keyParams_parent;

    _hidl_err = _hidl_data.writeBuffer(&keyParams, sizeof(keyParams), &_hidl_keyParams_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_keyParams_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            keyParams,
            &_hidl_data,
            _hidl_keyParams_parent,
            0 /* parentOffset */, &_hidl_keyParams_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < keyParams.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                keyParams[_hidl_index_0],
                &_hidl_data,
                _hidl_keyParams_child,
                _hidl_index_0 * sizeof(::android::hardware::keymaster::V4_0::KeyParameter));

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    }

    _hidl_err = _hidl_data.writeUint32((uint32_t)keyFormat);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_keyData_parent;

    _hidl_err = _hidl_data.writeBuffer(&keyData, sizeof(keyData), &_hidl_keyData_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_keyData_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            keyData,
            &_hidl_data,
            _hidl_keyData_parent,
            0 /* parentOffset */, &_hidl_keyData_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(7 /* importKey */, _hidl_data, &_hidl_reply, 0 /* flags */ | 32u /* clear buf */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::keymaster::V4_0::ErrorCode _hidl_out_error;
        const ::android::hardware::hidl_vec<uint8_t>* _hidl_out_keyBlob;
        ::android::hardware::keymaster::V4_0::KeyCharacteristics* _hidl_out_keyCharacteristics;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_error);
        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_keyBlob_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_keyBlob), &_hidl__hidl_out_keyBlob_parent,  reinterpret_cast<const void **>(&_hidl_out_keyBlob));

        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_keyBlob_child;

        _hidl_err = ::android::hardware::readEmbeddedFromParcel(
                const_cast<::android::hardware::hidl_vec<uint8_t> &>(*_hidl_out_keyBlob),
                _hidl_reply,
                _hidl__hidl_out_keyBlob_parent,
                0 /* parentOffset */, &_hidl__hidl_out_keyBlob_child);

        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_keyCharacteristics_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_keyCharacteristics), &_hidl__hidl_out_keyCharacteristics_parent,  const_cast<const void**>(reinterpret_cast<void **>(&_hidl_out_keyCharacteristics)));
        if (_hidl_err != ::android::OK) { return; }

        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::keymaster::V4_0::KeyCharacteristics &>(*_hidl_out_keyCharacteristics),
                _hidl_reply,
                _hidl__hidl_out_keyCharacteristics_parent,
                0 /* parentOffset */);

        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(_hidl_out_error, *_hidl_out_keyBlob, *_hidl_out_keyCharacteristics);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_error);
            _hidl_args.push_back((void *)_hidl_out_keyBlob);
            _hidl_args.push_back((void *)_hidl_out_keyCharacteristics);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.keymaster", "4.0", "IKeymasterDevice", "importKey", &_hidl_args);
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

::android::hardware::Return<void> BpHwKeymasterDevice::_hidl_importWrappedKey(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::hidl_vec<uint8_t>& wrappedKeyData, const ::android::hardware::hidl_vec<uint8_t>& wrappingKeyBlob, const ::android::hardware::hidl_vec<uint8_t>& maskingKey, const ::android::hardware::hidl_vec<::android::hardware::keymaster::V4_0::KeyParameter>& unwrappingParams, uint64_t passwordSid, uint64_t biometricSid, importWrappedKey_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IKeymasterDevice::importWrappedKey::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&wrappedKeyData);
        _hidl_args.push_back((void *)&wrappingKeyBlob);
        _hidl_args.push_back((void *)&maskingKey);
        _hidl_args.push_back((void *)&unwrappingParams);
        _hidl_args.push_back((void *)&passwordSid);
        _hidl_args.push_back((void *)&biometricSid);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.keymaster", "4.0", "IKeymasterDevice", "importWrappedKey", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_data.markSensitive();
    _hidl_err = _hidl_data.writeInterfaceToken(BpHwKeymasterDevice::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_wrappedKeyData_parent;

    _hidl_err = _hidl_data.writeBuffer(&wrappedKeyData, sizeof(wrappedKeyData), &_hidl_wrappedKeyData_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_wrappedKeyData_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            wrappedKeyData,
            &_hidl_data,
            _hidl_wrappedKeyData_parent,
            0 /* parentOffset */, &_hidl_wrappedKeyData_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_wrappingKeyBlob_parent;

    _hidl_err = _hidl_data.writeBuffer(&wrappingKeyBlob, sizeof(wrappingKeyBlob), &_hidl_wrappingKeyBlob_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_wrappingKeyBlob_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            wrappingKeyBlob,
            &_hidl_data,
            _hidl_wrappingKeyBlob_parent,
            0 /* parentOffset */, &_hidl_wrappingKeyBlob_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_maskingKey_parent;

    _hidl_err = _hidl_data.writeBuffer(&maskingKey, sizeof(maskingKey), &_hidl_maskingKey_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_maskingKey_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            maskingKey,
            &_hidl_data,
            _hidl_maskingKey_parent,
            0 /* parentOffset */, &_hidl_maskingKey_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_unwrappingParams_parent;

    _hidl_err = _hidl_data.writeBuffer(&unwrappingParams, sizeof(unwrappingParams), &_hidl_unwrappingParams_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_unwrappingParams_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            unwrappingParams,
            &_hidl_data,
            _hidl_unwrappingParams_parent,
            0 /* parentOffset */, &_hidl_unwrappingParams_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < unwrappingParams.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                unwrappingParams[_hidl_index_0],
                &_hidl_data,
                _hidl_unwrappingParams_child,
                _hidl_index_0 * sizeof(::android::hardware::keymaster::V4_0::KeyParameter));

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    }

    _hidl_err = _hidl_data.writeUint64(passwordSid);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(biometricSid);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(8 /* importWrappedKey */, _hidl_data, &_hidl_reply, 0 /* flags */ | 32u /* clear buf */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::keymaster::V4_0::ErrorCode _hidl_out_error;
        const ::android::hardware::hidl_vec<uint8_t>* _hidl_out_keyBlob;
        ::android::hardware::keymaster::V4_0::KeyCharacteristics* _hidl_out_keyCharacteristics;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_error);
        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_keyBlob_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_keyBlob), &_hidl__hidl_out_keyBlob_parent,  reinterpret_cast<const void **>(&_hidl_out_keyBlob));

        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_keyBlob_child;

        _hidl_err = ::android::hardware::readEmbeddedFromParcel(
                const_cast<::android::hardware::hidl_vec<uint8_t> &>(*_hidl_out_keyBlob),
                _hidl_reply,
                _hidl__hidl_out_keyBlob_parent,
                0 /* parentOffset */, &_hidl__hidl_out_keyBlob_child);

        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_keyCharacteristics_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_keyCharacteristics), &_hidl__hidl_out_keyCharacteristics_parent,  const_cast<const void**>(reinterpret_cast<void **>(&_hidl_out_keyCharacteristics)));
        if (_hidl_err != ::android::OK) { return; }

        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::keymaster::V4_0::KeyCharacteristics &>(*_hidl_out_keyCharacteristics),
                _hidl_reply,
                _hidl__hidl_out_keyCharacteristics_parent,
                0 /* parentOffset */);

        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(_hidl_out_error, *_hidl_out_keyBlob, *_hidl_out_keyCharacteristics);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_error);
            _hidl_args.push_back((void *)_hidl_out_keyBlob);
            _hidl_args.push_back((void *)_hidl_out_keyCharacteristics);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.keymaster", "4.0", "IKeymasterDevice", "importWrappedKey", &_hidl_args);
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

::android::hardware::Return<void> BpHwKeymasterDevice::_hidl_getKeyCharacteristics(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::hidl_vec<uint8_t>& keyBlob, const ::android::hardware::hidl_vec<uint8_t>& clientId, const ::android::hardware::hidl_vec<uint8_t>& appData, getKeyCharacteristics_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IKeymasterDevice::getKeyCharacteristics::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&keyBlob);
        _hidl_args.push_back((void *)&clientId);
        _hidl_args.push_back((void *)&appData);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.keymaster", "4.0", "IKeymasterDevice", "getKeyCharacteristics", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_data.markSensitive();
    _hidl_err = _hidl_data.writeInterfaceToken(BpHwKeymasterDevice::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_keyBlob_parent;

    _hidl_err = _hidl_data.writeBuffer(&keyBlob, sizeof(keyBlob), &_hidl_keyBlob_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_keyBlob_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            keyBlob,
            &_hidl_data,
            _hidl_keyBlob_parent,
            0 /* parentOffset */, &_hidl_keyBlob_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_clientId_parent;

    _hidl_err = _hidl_data.writeBuffer(&clientId, sizeof(clientId), &_hidl_clientId_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_clientId_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            clientId,
            &_hidl_data,
            _hidl_clientId_parent,
            0 /* parentOffset */, &_hidl_clientId_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_appData_parent;

    _hidl_err = _hidl_data.writeBuffer(&appData, sizeof(appData), &_hidl_appData_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_appData_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            appData,
            &_hidl_data,
            _hidl_appData_parent,
            0 /* parentOffset */, &_hidl_appData_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(9 /* getKeyCharacteristics */, _hidl_data, &_hidl_reply, 0 /* flags */ | 32u /* clear buf */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::keymaster::V4_0::ErrorCode _hidl_out_error;
        ::android::hardware::keymaster::V4_0::KeyCharacteristics* _hidl_out_keyCharacteristics;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_error);
        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_keyCharacteristics_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_keyCharacteristics), &_hidl__hidl_out_keyCharacteristics_parent,  const_cast<const void**>(reinterpret_cast<void **>(&_hidl_out_keyCharacteristics)));
        if (_hidl_err != ::android::OK) { return; }

        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::keymaster::V4_0::KeyCharacteristics &>(*_hidl_out_keyCharacteristics),
                _hidl_reply,
                _hidl__hidl_out_keyCharacteristics_parent,
                0 /* parentOffset */);

        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(_hidl_out_error, *_hidl_out_keyCharacteristics);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_error);
            _hidl_args.push_back((void *)_hidl_out_keyCharacteristics);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.keymaster", "4.0", "IKeymasterDevice", "getKeyCharacteristics", &_hidl_args);
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

::android::hardware::Return<void> BpHwKeymasterDevice::_hidl_exportKey(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, ::android::hardware::keymaster::V4_0::KeyFormat keyFormat, const ::android::hardware::hidl_vec<uint8_t>& keyBlob, const ::android::hardware::hidl_vec<uint8_t>& clientId, const ::android::hardware::hidl_vec<uint8_t>& appData, exportKey_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IKeymasterDevice::exportKey::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&keyFormat);
        _hidl_args.push_back((void *)&keyBlob);
        _hidl_args.push_back((void *)&clientId);
        _hidl_args.push_back((void *)&appData);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.keymaster", "4.0", "IKeymasterDevice", "exportKey", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_data.markSensitive();
    _hidl_err = _hidl_data.writeInterfaceToken(BpHwKeymasterDevice::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32((uint32_t)keyFormat);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_keyBlob_parent;

    _hidl_err = _hidl_data.writeBuffer(&keyBlob, sizeof(keyBlob), &_hidl_keyBlob_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_keyBlob_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            keyBlob,
            &_hidl_data,
            _hidl_keyBlob_parent,
            0 /* parentOffset */, &_hidl_keyBlob_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_clientId_parent;

    _hidl_err = _hidl_data.writeBuffer(&clientId, sizeof(clientId), &_hidl_clientId_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_clientId_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            clientId,
            &_hidl_data,
            _hidl_clientId_parent,
            0 /* parentOffset */, &_hidl_clientId_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_appData_parent;

    _hidl_err = _hidl_data.writeBuffer(&appData, sizeof(appData), &_hidl_appData_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_appData_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            appData,
            &_hidl_data,
            _hidl_appData_parent,
            0 /* parentOffset */, &_hidl_appData_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(10 /* exportKey */, _hidl_data, &_hidl_reply, 0 /* flags */ | 32u /* clear buf */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::keymaster::V4_0::ErrorCode _hidl_out_error;
        const ::android::hardware::hidl_vec<uint8_t>* _hidl_out_keyMaterial;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_error);
        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_keyMaterial_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_keyMaterial), &_hidl__hidl_out_keyMaterial_parent,  reinterpret_cast<const void **>(&_hidl_out_keyMaterial));

        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_keyMaterial_child;

        _hidl_err = ::android::hardware::readEmbeddedFromParcel(
                const_cast<::android::hardware::hidl_vec<uint8_t> &>(*_hidl_out_keyMaterial),
                _hidl_reply,
                _hidl__hidl_out_keyMaterial_parent,
                0 /* parentOffset */, &_hidl__hidl_out_keyMaterial_child);

        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(_hidl_out_error, *_hidl_out_keyMaterial);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_error);
            _hidl_args.push_back((void *)_hidl_out_keyMaterial);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.keymaster", "4.0", "IKeymasterDevice", "exportKey", &_hidl_args);
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

::android::hardware::Return<void> BpHwKeymasterDevice::_hidl_attestKey(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::hidl_vec<uint8_t>& keyToAttest, const ::android::hardware::hidl_vec<::android::hardware::keymaster::V4_0::KeyParameter>& attestParams, attestKey_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IKeymasterDevice::attestKey::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&keyToAttest);
        _hidl_args.push_back((void *)&attestParams);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.keymaster", "4.0", "IKeymasterDevice", "attestKey", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_data.markSensitive();
    _hidl_err = _hidl_data.writeInterfaceToken(BpHwKeymasterDevice::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_keyToAttest_parent;

    _hidl_err = _hidl_data.writeBuffer(&keyToAttest, sizeof(keyToAttest), &_hidl_keyToAttest_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_keyToAttest_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            keyToAttest,
            &_hidl_data,
            _hidl_keyToAttest_parent,
            0 /* parentOffset */, &_hidl_keyToAttest_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_attestParams_parent;

    _hidl_err = _hidl_data.writeBuffer(&attestParams, sizeof(attestParams), &_hidl_attestParams_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_attestParams_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            attestParams,
            &_hidl_data,
            _hidl_attestParams_parent,
            0 /* parentOffset */, &_hidl_attestParams_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < attestParams.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                attestParams[_hidl_index_0],
                &_hidl_data,
                _hidl_attestParams_child,
                _hidl_index_0 * sizeof(::android::hardware::keymaster::V4_0::KeyParameter));

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(11 /* attestKey */, _hidl_data, &_hidl_reply, 0 /* flags */ | 32u /* clear buf */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::keymaster::V4_0::ErrorCode _hidl_out_error;
        const ::android::hardware::hidl_vec<::android::hardware::hidl_vec<uint8_t>>* _hidl_out_certChain;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_error);
        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_certChain_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_certChain), &_hidl__hidl_out_certChain_parent,  reinterpret_cast<const void **>(&_hidl_out_certChain));

        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_certChain_child;

        _hidl_err = ::android::hardware::readEmbeddedFromParcel(
                const_cast<::android::hardware::hidl_vec<::android::hardware::hidl_vec<uint8_t>> &>(*_hidl_out_certChain),
                _hidl_reply,
                _hidl__hidl_out_certChain_parent,
                0 /* parentOffset */, &_hidl__hidl_out_certChain_child);

        if (_hidl_err != ::android::OK) { return; }

        for (size_t _hidl_index_0 = 0; _hidl_index_0 < _hidl_out_certChain->size(); ++_hidl_index_0) {
            size_t _hidl__hidl_out_certChain_deref_indexed_child;

            _hidl_err = ::android::hardware::readEmbeddedFromParcel(
                    const_cast<::android::hardware::hidl_vec<uint8_t> &>((*_hidl_out_certChain)[_hidl_index_0]),
                    _hidl_reply,
                    _hidl__hidl_out_certChain_child,
                    _hidl_index_0 * sizeof(::android::hardware::hidl_vec<uint8_t>), &_hidl__hidl_out_certChain_deref_indexed_child);

            if (_hidl_err != ::android::OK) { return; }

        }

        _hidl_cb(_hidl_out_error, *_hidl_out_certChain);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_error);
            _hidl_args.push_back((void *)_hidl_out_certChain);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.keymaster", "4.0", "IKeymasterDevice", "attestKey", &_hidl_args);
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

::android::hardware::Return<void> BpHwKeymasterDevice::_hidl_upgradeKey(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::hidl_vec<uint8_t>& keyBlobToUpgrade, const ::android::hardware::hidl_vec<::android::hardware::keymaster::V4_0::KeyParameter>& upgradeParams, upgradeKey_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IKeymasterDevice::upgradeKey::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&keyBlobToUpgrade);
        _hidl_args.push_back((void *)&upgradeParams);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.keymaster", "4.0", "IKeymasterDevice", "upgradeKey", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_data.markSensitive();
    _hidl_err = _hidl_data.writeInterfaceToken(BpHwKeymasterDevice::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_keyBlobToUpgrade_parent;

    _hidl_err = _hidl_data.writeBuffer(&keyBlobToUpgrade, sizeof(keyBlobToUpgrade), &_hidl_keyBlobToUpgrade_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_keyBlobToUpgrade_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            keyBlobToUpgrade,
            &_hidl_data,
            _hidl_keyBlobToUpgrade_parent,
            0 /* parentOffset */, &_hidl_keyBlobToUpgrade_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_upgradeParams_parent;

    _hidl_err = _hidl_data.writeBuffer(&upgradeParams, sizeof(upgradeParams), &_hidl_upgradeParams_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_upgradeParams_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            upgradeParams,
            &_hidl_data,
            _hidl_upgradeParams_parent,
            0 /* parentOffset */, &_hidl_upgradeParams_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < upgradeParams.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                upgradeParams[_hidl_index_0],
                &_hidl_data,
                _hidl_upgradeParams_child,
                _hidl_index_0 * sizeof(::android::hardware::keymaster::V4_0::KeyParameter));

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(12 /* upgradeKey */, _hidl_data, &_hidl_reply, 0 /* flags */ | 32u /* clear buf */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::keymaster::V4_0::ErrorCode _hidl_out_error;
        const ::android::hardware::hidl_vec<uint8_t>* _hidl_out_upgradedKeyBlob;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_error);
        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_upgradedKeyBlob_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_upgradedKeyBlob), &_hidl__hidl_out_upgradedKeyBlob_parent,  reinterpret_cast<const void **>(&_hidl_out_upgradedKeyBlob));

        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_upgradedKeyBlob_child;

        _hidl_err = ::android::hardware::readEmbeddedFromParcel(
                const_cast<::android::hardware::hidl_vec<uint8_t> &>(*_hidl_out_upgradedKeyBlob),
                _hidl_reply,
                _hidl__hidl_out_upgradedKeyBlob_parent,
                0 /* parentOffset */, &_hidl__hidl_out_upgradedKeyBlob_child);

        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(_hidl_out_error, *_hidl_out_upgradedKeyBlob);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_error);
            _hidl_args.push_back((void *)_hidl_out_upgradedKeyBlob);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.keymaster", "4.0", "IKeymasterDevice", "upgradeKey", &_hidl_args);
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

::android::hardware::Return<::android::hardware::keymaster::V4_0::ErrorCode> BpHwKeymasterDevice::_hidl_deleteKey(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::hidl_vec<uint8_t>& keyBlob) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IKeymasterDevice::deleteKey::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&keyBlob);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.keymaster", "4.0", "IKeymasterDevice", "deleteKey", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    ::android::hardware::keymaster::V4_0::ErrorCode _hidl_out_error;

    _hidl_data.markSensitive();
    _hidl_err = _hidl_data.writeInterfaceToken(BpHwKeymasterDevice::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_keyBlob_parent;

    _hidl_err = _hidl_data.writeBuffer(&keyBlob, sizeof(keyBlob), &_hidl_keyBlob_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_keyBlob_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            keyBlob,
            &_hidl_data,
            _hidl_keyBlob_parent,
            0 /* parentOffset */, &_hidl_keyBlob_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(13 /* deleteKey */, _hidl_data, &_hidl_reply, 0 /* flags */ | 32u /* clear buf */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_error);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_error);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.keymaster", "4.0", "IKeymasterDevice", "deleteKey", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<::android::hardware::keymaster::V4_0::ErrorCode>(_hidl_out_error);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<::android::hardware::keymaster::V4_0::ErrorCode>(_hidl_status);
}

::android::hardware::Return<::android::hardware::keymaster::V4_0::ErrorCode> BpHwKeymasterDevice::_hidl_deleteAllKeys(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IKeymasterDevice::deleteAllKeys::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.keymaster", "4.0", "IKeymasterDevice", "deleteAllKeys", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    ::android::hardware::keymaster::V4_0::ErrorCode _hidl_out_error;

    _hidl_data.markSensitive();
    _hidl_err = _hidl_data.writeInterfaceToken(BpHwKeymasterDevice::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(14 /* deleteAllKeys */, _hidl_data, &_hidl_reply, 0 /* flags */ | 32u /* clear buf */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_error);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_error);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.keymaster", "4.0", "IKeymasterDevice", "deleteAllKeys", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<::android::hardware::keymaster::V4_0::ErrorCode>(_hidl_out_error);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<::android::hardware::keymaster::V4_0::ErrorCode>(_hidl_status);
}

::android::hardware::Return<::android::hardware::keymaster::V4_0::ErrorCode> BpHwKeymasterDevice::_hidl_destroyAttestationIds(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IKeymasterDevice::destroyAttestationIds::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.keymaster", "4.0", "IKeymasterDevice", "destroyAttestationIds", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    ::android::hardware::keymaster::V4_0::ErrorCode _hidl_out_error;

    _hidl_data.markSensitive();
    _hidl_err = _hidl_data.writeInterfaceToken(BpHwKeymasterDevice::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(15 /* destroyAttestationIds */, _hidl_data, &_hidl_reply, 0 /* flags */ | 32u /* clear buf */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_error);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_error);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.keymaster", "4.0", "IKeymasterDevice", "destroyAttestationIds", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<::android::hardware::keymaster::V4_0::ErrorCode>(_hidl_out_error);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<::android::hardware::keymaster::V4_0::ErrorCode>(_hidl_status);
}

::android::hardware::Return<void> BpHwKeymasterDevice::_hidl_begin(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, ::android::hardware::keymaster::V4_0::KeyPurpose purpose, const ::android::hardware::hidl_vec<uint8_t>& keyBlob, const ::android::hardware::hidl_vec<::android::hardware::keymaster::V4_0::KeyParameter>& inParams, const ::android::hardware::keymaster::V4_0::HardwareAuthToken& authToken, begin_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IKeymasterDevice::begin::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&purpose);
        _hidl_args.push_back((void *)&keyBlob);
        _hidl_args.push_back((void *)&inParams);
        _hidl_args.push_back((void *)&authToken);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.keymaster", "4.0", "IKeymasterDevice", "begin", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_data.markSensitive();
    _hidl_err = _hidl_data.writeInterfaceToken(BpHwKeymasterDevice::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32((uint32_t)purpose);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_keyBlob_parent;

    _hidl_err = _hidl_data.writeBuffer(&keyBlob, sizeof(keyBlob), &_hidl_keyBlob_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_keyBlob_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            keyBlob,
            &_hidl_data,
            _hidl_keyBlob_parent,
            0 /* parentOffset */, &_hidl_keyBlob_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_inParams_parent;

    _hidl_err = _hidl_data.writeBuffer(&inParams, sizeof(inParams), &_hidl_inParams_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_inParams_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            inParams,
            &_hidl_data,
            _hidl_inParams_parent,
            0 /* parentOffset */, &_hidl_inParams_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < inParams.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                inParams[_hidl_index_0],
                &_hidl_data,
                _hidl_inParams_child,
                _hidl_index_0 * sizeof(::android::hardware::keymaster::V4_0::KeyParameter));

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    }

    size_t _hidl_authToken_parent;

    _hidl_err = _hidl_data.writeBuffer(&authToken, sizeof(authToken), &_hidl_authToken_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = writeEmbeddedToParcel(
            authToken,
            &_hidl_data,
            _hidl_authToken_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(16 /* begin */, _hidl_data, &_hidl_reply, 0 /* flags */ | 32u /* clear buf */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::keymaster::V4_0::ErrorCode _hidl_out_error;
        const ::android::hardware::hidl_vec<::android::hardware::keymaster::V4_0::KeyParameter>* _hidl_out_outParams;
        uint64_t _hidl_out_operationHandle;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_error);
        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_outParams_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_outParams), &_hidl__hidl_out_outParams_parent,  reinterpret_cast<const void **>(&_hidl_out_outParams));

        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_outParams_child;

        _hidl_err = ::android::hardware::readEmbeddedFromParcel(
                const_cast<::android::hardware::hidl_vec<::android::hardware::keymaster::V4_0::KeyParameter> &>(*_hidl_out_outParams),
                _hidl_reply,
                _hidl__hidl_out_outParams_parent,
                0 /* parentOffset */, &_hidl__hidl_out_outParams_child);

        if (_hidl_err != ::android::OK) { return; }

        for (size_t _hidl_index_0 = 0; _hidl_index_0 < _hidl_out_outParams->size(); ++_hidl_index_0) {
            _hidl_err = readEmbeddedFromParcel(
                    const_cast<::android::hardware::keymaster::V4_0::KeyParameter &>((*_hidl_out_outParams)[_hidl_index_0]),
                    _hidl_reply,
                    _hidl__hidl_out_outParams_child,
                    _hidl_index_0 * sizeof(::android::hardware::keymaster::V4_0::KeyParameter));

            if (_hidl_err != ::android::OK) { return; }

        }

        _hidl_err = _hidl_reply.readUint64(&_hidl_out_operationHandle);
        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(_hidl_out_error, *_hidl_out_outParams, _hidl_out_operationHandle);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_error);
            _hidl_args.push_back((void *)_hidl_out_outParams);
            _hidl_args.push_back((void *)&_hidl_out_operationHandle);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.keymaster", "4.0", "IKeymasterDevice", "begin", &_hidl_args);
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

::android::hardware::Return<void> BpHwKeymasterDevice::_hidl_update(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint64_t operationHandle, const ::android::hardware::hidl_vec<::android::hardware::keymaster::V4_0::KeyParameter>& inParams, const ::android::hardware::hidl_vec<uint8_t>& input, const ::android::hardware::keymaster::V4_0::HardwareAuthToken& authToken, const ::android::hardware::keymaster::V4_0::VerificationToken& verificationToken, update_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IKeymasterDevice::update::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&operationHandle);
        _hidl_args.push_back((void *)&inParams);
        _hidl_args.push_back((void *)&input);
        _hidl_args.push_back((void *)&authToken);
        _hidl_args.push_back((void *)&verificationToken);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.keymaster", "4.0", "IKeymasterDevice", "update", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_data.markSensitive();
    _hidl_err = _hidl_data.writeInterfaceToken(BpHwKeymasterDevice::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(operationHandle);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_inParams_parent;

    _hidl_err = _hidl_data.writeBuffer(&inParams, sizeof(inParams), &_hidl_inParams_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_inParams_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            inParams,
            &_hidl_data,
            _hidl_inParams_parent,
            0 /* parentOffset */, &_hidl_inParams_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < inParams.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                inParams[_hidl_index_0],
                &_hidl_data,
                _hidl_inParams_child,
                _hidl_index_0 * sizeof(::android::hardware::keymaster::V4_0::KeyParameter));

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    }

    size_t _hidl_input_parent;

    _hidl_err = _hidl_data.writeBuffer(&input, sizeof(input), &_hidl_input_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_input_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            input,
            &_hidl_data,
            _hidl_input_parent,
            0 /* parentOffset */, &_hidl_input_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_authToken_parent;

    _hidl_err = _hidl_data.writeBuffer(&authToken, sizeof(authToken), &_hidl_authToken_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = writeEmbeddedToParcel(
            authToken,
            &_hidl_data,
            _hidl_authToken_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_verificationToken_parent;

    _hidl_err = _hidl_data.writeBuffer(&verificationToken, sizeof(verificationToken), &_hidl_verificationToken_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = writeEmbeddedToParcel(
            verificationToken,
            &_hidl_data,
            _hidl_verificationToken_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(17 /* update */, _hidl_data, &_hidl_reply, 0 /* flags */ | 32u /* clear buf */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::keymaster::V4_0::ErrorCode _hidl_out_error;
        uint32_t _hidl_out_inputConsumed;
        const ::android::hardware::hidl_vec<::android::hardware::keymaster::V4_0::KeyParameter>* _hidl_out_outParams;
        const ::android::hardware::hidl_vec<uint8_t>* _hidl_out_output;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_error);
        if (_hidl_err != ::android::OK) { return; }

        _hidl_err = _hidl_reply.readUint32(&_hidl_out_inputConsumed);
        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_outParams_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_outParams), &_hidl__hidl_out_outParams_parent,  reinterpret_cast<const void **>(&_hidl_out_outParams));

        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_outParams_child;

        _hidl_err = ::android::hardware::readEmbeddedFromParcel(
                const_cast<::android::hardware::hidl_vec<::android::hardware::keymaster::V4_0::KeyParameter> &>(*_hidl_out_outParams),
                _hidl_reply,
                _hidl__hidl_out_outParams_parent,
                0 /* parentOffset */, &_hidl__hidl_out_outParams_child);

        if (_hidl_err != ::android::OK) { return; }

        for (size_t _hidl_index_0 = 0; _hidl_index_0 < _hidl_out_outParams->size(); ++_hidl_index_0) {
            _hidl_err = readEmbeddedFromParcel(
                    const_cast<::android::hardware::keymaster::V4_0::KeyParameter &>((*_hidl_out_outParams)[_hidl_index_0]),
                    _hidl_reply,
                    _hidl__hidl_out_outParams_child,
                    _hidl_index_0 * sizeof(::android::hardware::keymaster::V4_0::KeyParameter));

            if (_hidl_err != ::android::OK) { return; }

        }

        size_t _hidl__hidl_out_output_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_output), &_hidl__hidl_out_output_parent,  reinterpret_cast<const void **>(&_hidl_out_output));

        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_output_child;

        _hidl_err = ::android::hardware::readEmbeddedFromParcel(
                const_cast<::android::hardware::hidl_vec<uint8_t> &>(*_hidl_out_output),
                _hidl_reply,
                _hidl__hidl_out_output_parent,
                0 /* parentOffset */, &_hidl__hidl_out_output_child);

        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(_hidl_out_error, _hidl_out_inputConsumed, *_hidl_out_outParams, *_hidl_out_output);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_error);
            _hidl_args.push_back((void *)&_hidl_out_inputConsumed);
            _hidl_args.push_back((void *)_hidl_out_outParams);
            _hidl_args.push_back((void *)_hidl_out_output);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.keymaster", "4.0", "IKeymasterDevice", "update", &_hidl_args);
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

::android::hardware::Return<void> BpHwKeymasterDevice::_hidl_finish(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint64_t operationHandle, const ::android::hardware::hidl_vec<::android::hardware::keymaster::V4_0::KeyParameter>& inParams, const ::android::hardware::hidl_vec<uint8_t>& input, const ::android::hardware::hidl_vec<uint8_t>& signature, const ::android::hardware::keymaster::V4_0::HardwareAuthToken& authToken, const ::android::hardware::keymaster::V4_0::VerificationToken& verificationToken, finish_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IKeymasterDevice::finish::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&operationHandle);
        _hidl_args.push_back((void *)&inParams);
        _hidl_args.push_back((void *)&input);
        _hidl_args.push_back((void *)&signature);
        _hidl_args.push_back((void *)&authToken);
        _hidl_args.push_back((void *)&verificationToken);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.keymaster", "4.0", "IKeymasterDevice", "finish", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_data.markSensitive();
    _hidl_err = _hidl_data.writeInterfaceToken(BpHwKeymasterDevice::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(operationHandle);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_inParams_parent;

    _hidl_err = _hidl_data.writeBuffer(&inParams, sizeof(inParams), &_hidl_inParams_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_inParams_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            inParams,
            &_hidl_data,
            _hidl_inParams_parent,
            0 /* parentOffset */, &_hidl_inParams_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < inParams.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                inParams[_hidl_index_0],
                &_hidl_data,
                _hidl_inParams_child,
                _hidl_index_0 * sizeof(::android::hardware::keymaster::V4_0::KeyParameter));

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    }

    size_t _hidl_input_parent;

    _hidl_err = _hidl_data.writeBuffer(&input, sizeof(input), &_hidl_input_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_input_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            input,
            &_hidl_data,
            _hidl_input_parent,
            0 /* parentOffset */, &_hidl_input_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_signature_parent;

    _hidl_err = _hidl_data.writeBuffer(&signature, sizeof(signature), &_hidl_signature_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_signature_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            signature,
            &_hidl_data,
            _hidl_signature_parent,
            0 /* parentOffset */, &_hidl_signature_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_authToken_parent;

    _hidl_err = _hidl_data.writeBuffer(&authToken, sizeof(authToken), &_hidl_authToken_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = writeEmbeddedToParcel(
            authToken,
            &_hidl_data,
            _hidl_authToken_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_verificationToken_parent;

    _hidl_err = _hidl_data.writeBuffer(&verificationToken, sizeof(verificationToken), &_hidl_verificationToken_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = writeEmbeddedToParcel(
            verificationToken,
            &_hidl_data,
            _hidl_verificationToken_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(18 /* finish */, _hidl_data, &_hidl_reply, 0 /* flags */ | 32u /* clear buf */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::keymaster::V4_0::ErrorCode _hidl_out_error;
        const ::android::hardware::hidl_vec<::android::hardware::keymaster::V4_0::KeyParameter>* _hidl_out_outParams;
        const ::android::hardware::hidl_vec<uint8_t>* _hidl_out_output;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_error);
        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_outParams_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_outParams), &_hidl__hidl_out_outParams_parent,  reinterpret_cast<const void **>(&_hidl_out_outParams));

        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_outParams_child;

        _hidl_err = ::android::hardware::readEmbeddedFromParcel(
                const_cast<::android::hardware::hidl_vec<::android::hardware::keymaster::V4_0::KeyParameter> &>(*_hidl_out_outParams),
                _hidl_reply,
                _hidl__hidl_out_outParams_parent,
                0 /* parentOffset */, &_hidl__hidl_out_outParams_child);

        if (_hidl_err != ::android::OK) { return; }

        for (size_t _hidl_index_0 = 0; _hidl_index_0 < _hidl_out_outParams->size(); ++_hidl_index_0) {
            _hidl_err = readEmbeddedFromParcel(
                    const_cast<::android::hardware::keymaster::V4_0::KeyParameter &>((*_hidl_out_outParams)[_hidl_index_0]),
                    _hidl_reply,
                    _hidl__hidl_out_outParams_child,
                    _hidl_index_0 * sizeof(::android::hardware::keymaster::V4_0::KeyParameter));

            if (_hidl_err != ::android::OK) { return; }

        }

        size_t _hidl__hidl_out_output_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_output), &_hidl__hidl_out_output_parent,  reinterpret_cast<const void **>(&_hidl_out_output));

        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_output_child;

        _hidl_err = ::android::hardware::readEmbeddedFromParcel(
                const_cast<::android::hardware::hidl_vec<uint8_t> &>(*_hidl_out_output),
                _hidl_reply,
                _hidl__hidl_out_output_parent,
                0 /* parentOffset */, &_hidl__hidl_out_output_child);

        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(_hidl_out_error, *_hidl_out_outParams, *_hidl_out_output);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_error);
            _hidl_args.push_back((void *)_hidl_out_outParams);
            _hidl_args.push_back((void *)_hidl_out_output);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.keymaster", "4.0", "IKeymasterDevice", "finish", &_hidl_args);
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

::android::hardware::Return<::android::hardware::keymaster::V4_0::ErrorCode> BpHwKeymasterDevice::_hidl_abort(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint64_t operationHandle) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IKeymasterDevice::abort::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&operationHandle);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.keymaster", "4.0", "IKeymasterDevice", "abort", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    ::android::hardware::keymaster::V4_0::ErrorCode _hidl_out_error;

    _hidl_data.markSensitive();
    _hidl_err = _hidl_data.writeInterfaceToken(BpHwKeymasterDevice::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(operationHandle);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(19 /* abort */, _hidl_data, &_hidl_reply, 0 /* flags */ | 32u /* clear buf */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_error);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_error);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.keymaster", "4.0", "IKeymasterDevice", "abort", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<::android::hardware::keymaster::V4_0::ErrorCode>(_hidl_out_error);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<::android::hardware::keymaster::V4_0::ErrorCode>(_hidl_status);
}


// Methods from ::android::hardware::keymaster::V4_0::IKeymasterDevice follow.
::android::hardware::Return<void> BpHwKeymasterDevice::getHardwareInfo(getHardwareInfo_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::keymaster::V4_0::BpHwKeymasterDevice::_hidl_getHardwareInfo(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwKeymasterDevice::getHmacSharingParameters(getHmacSharingParameters_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::keymaster::V4_0::BpHwKeymasterDevice::_hidl_getHmacSharingParameters(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwKeymasterDevice::computeSharedHmac(const ::android::hardware::hidl_vec<::android::hardware::keymaster::V4_0::HmacSharingParameters>& params, computeSharedHmac_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::keymaster::V4_0::BpHwKeymasterDevice::_hidl_computeSharedHmac(this, this, params, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwKeymasterDevice::verifyAuthorization(uint64_t operationHandle, const ::android::hardware::hidl_vec<::android::hardware::keymaster::V4_0::KeyParameter>& parametersToVerify, const ::android::hardware::keymaster::V4_0::HardwareAuthToken& authToken, verifyAuthorization_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::keymaster::V4_0::BpHwKeymasterDevice::_hidl_verifyAuthorization(this, this, operationHandle, parametersToVerify, authToken, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<::android::hardware::keymaster::V4_0::ErrorCode> BpHwKeymasterDevice::addRngEntropy(const ::android::hardware::hidl_vec<uint8_t>& data){
    ::android::hardware::Return<::android::hardware::keymaster::V4_0::ErrorCode>  _hidl_out = ::android::hardware::keymaster::V4_0::BpHwKeymasterDevice::_hidl_addRngEntropy(this, this, data);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwKeymasterDevice::generateKey(const ::android::hardware::hidl_vec<::android::hardware::keymaster::V4_0::KeyParameter>& keyParams, generateKey_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::keymaster::V4_0::BpHwKeymasterDevice::_hidl_generateKey(this, this, keyParams, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwKeymasterDevice::importKey(const ::android::hardware::hidl_vec<::android::hardware::keymaster::V4_0::KeyParameter>& keyParams, ::android::hardware::keymaster::V4_0::KeyFormat keyFormat, const ::android::hardware::hidl_vec<uint8_t>& keyData, importKey_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::keymaster::V4_0::BpHwKeymasterDevice::_hidl_importKey(this, this, keyParams, keyFormat, keyData, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwKeymasterDevice::importWrappedKey(const ::android::hardware::hidl_vec<uint8_t>& wrappedKeyData, const ::android::hardware::hidl_vec<uint8_t>& wrappingKeyBlob, const ::android::hardware::hidl_vec<uint8_t>& maskingKey, const ::android::hardware::hidl_vec<::android::hardware::keymaster::V4_0::KeyParameter>& unwrappingParams, uint64_t passwordSid, uint64_t biometricSid, importWrappedKey_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::keymaster::V4_0::BpHwKeymasterDevice::_hidl_importWrappedKey(this, this, wrappedKeyData, wrappingKeyBlob, maskingKey, unwrappingParams, passwordSid, biometricSid, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwKeymasterDevice::getKeyCharacteristics(const ::android::hardware::hidl_vec<uint8_t>& keyBlob, const ::android::hardware::hidl_vec<uint8_t>& clientId, const ::android::hardware::hidl_vec<uint8_t>& appData, getKeyCharacteristics_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::keymaster::V4_0::BpHwKeymasterDevice::_hidl_getKeyCharacteristics(this, this, keyBlob, clientId, appData, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwKeymasterDevice::exportKey(::android::hardware::keymaster::V4_0::KeyFormat keyFormat, const ::android::hardware::hidl_vec<uint8_t>& keyBlob, const ::android::hardware::hidl_vec<uint8_t>& clientId, const ::android::hardware::hidl_vec<uint8_t>& appData, exportKey_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::keymaster::V4_0::BpHwKeymasterDevice::_hidl_exportKey(this, this, keyFormat, keyBlob, clientId, appData, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwKeymasterDevice::attestKey(const ::android::hardware::hidl_vec<uint8_t>& keyToAttest, const ::android::hardware::hidl_vec<::android::hardware::keymaster::V4_0::KeyParameter>& attestParams, attestKey_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::keymaster::V4_0::BpHwKeymasterDevice::_hidl_attestKey(this, this, keyToAttest, attestParams, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwKeymasterDevice::upgradeKey(const ::android::hardware::hidl_vec<uint8_t>& keyBlobToUpgrade, const ::android::hardware::hidl_vec<::android::hardware::keymaster::V4_0::KeyParameter>& upgradeParams, upgradeKey_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::keymaster::V4_0::BpHwKeymasterDevice::_hidl_upgradeKey(this, this, keyBlobToUpgrade, upgradeParams, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<::android::hardware::keymaster::V4_0::ErrorCode> BpHwKeymasterDevice::deleteKey(const ::android::hardware::hidl_vec<uint8_t>& keyBlob){
    ::android::hardware::Return<::android::hardware::keymaster::V4_0::ErrorCode>  _hidl_out = ::android::hardware::keymaster::V4_0::BpHwKeymasterDevice::_hidl_deleteKey(this, this, keyBlob);

    return _hidl_out;
}

::android::hardware::Return<::android::hardware::keymaster::V4_0::ErrorCode> BpHwKeymasterDevice::deleteAllKeys(){
    ::android::hardware::Return<::android::hardware::keymaster::V4_0::ErrorCode>  _hidl_out = ::android::hardware::keymaster::V4_0::BpHwKeymasterDevice::_hidl_deleteAllKeys(this, this);

    return _hidl_out;
}

::android::hardware::Return<::android::hardware::keymaster::V4_0::ErrorCode> BpHwKeymasterDevice::destroyAttestationIds(){
    ::android::hardware::Return<::android::hardware::keymaster::V4_0::ErrorCode>  _hidl_out = ::android::hardware::keymaster::V4_0::BpHwKeymasterDevice::_hidl_destroyAttestationIds(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwKeymasterDevice::begin(::android::hardware::keymaster::V4_0::KeyPurpose purpose, const ::android::hardware::hidl_vec<uint8_t>& keyBlob, const ::android::hardware::hidl_vec<::android::hardware::keymaster::V4_0::KeyParameter>& inParams, const ::android::hardware::keymaster::V4_0::HardwareAuthToken& authToken, begin_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::keymaster::V4_0::BpHwKeymasterDevice::_hidl_begin(this, this, purpose, keyBlob, inParams, authToken, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwKeymasterDevice::update(uint64_t operationHandle, const ::android::hardware::hidl_vec<::android::hardware::keymaster::V4_0::KeyParameter>& inParams, const ::android::hardware::hidl_vec<uint8_t>& input, const ::android::hardware::keymaster::V4_0::HardwareAuthToken& authToken, const ::android::hardware::keymaster::V4_0::VerificationToken& verificationToken, update_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::keymaster::V4_0::BpHwKeymasterDevice::_hidl_update(this, this, operationHandle, inParams, input, authToken, verificationToken, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwKeymasterDevice::finish(uint64_t operationHandle, const ::android::hardware::hidl_vec<::android::hardware::keymaster::V4_0::KeyParameter>& inParams, const ::android::hardware::hidl_vec<uint8_t>& input, const ::android::hardware::hidl_vec<uint8_t>& signature, const ::android::hardware::keymaster::V4_0::HardwareAuthToken& authToken, const ::android::hardware::keymaster::V4_0::VerificationToken& verificationToken, finish_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::keymaster::V4_0::BpHwKeymasterDevice::_hidl_finish(this, this, operationHandle, inParams, input, signature, authToken, verificationToken, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<::android::hardware::keymaster::V4_0::ErrorCode> BpHwKeymasterDevice::abort(uint64_t operationHandle){
    ::android::hardware::Return<::android::hardware::keymaster::V4_0::ErrorCode>  _hidl_out = ::android::hardware::keymaster::V4_0::BpHwKeymasterDevice::_hidl_abort(this, this, operationHandle);

    return _hidl_out;
}


// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BpHwKeymasterDevice::interfaceChain(interfaceChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwKeymasterDevice::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_debug(this, this, fd, options);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwKeymasterDevice::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceDescriptor(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwKeymasterDevice::getHashChain(getHashChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getHashChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwKeymasterDevice::setHALInstrumentation(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_setHALInstrumentation(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwKeymasterDevice::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    ::android::hardware::ProcessState::self()->startThreadPool();
    ::android::hardware::hidl_binder_death_recipient *binder_recipient = new ::android::hardware::hidl_binder_death_recipient(recipient, cookie, this);
    std::unique_lock<std::mutex> lock(_hidl_mMutex);
    _hidl_mDeathRecipients.push_back(binder_recipient);
    return (remote()->linkToDeath(binder_recipient) == ::android::OK);
}

::android::hardware::Return<void> BpHwKeymasterDevice::ping(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_ping(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwKeymasterDevice::getDebugInfo(getDebugInfo_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getDebugInfo(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwKeymasterDevice::notifySyspropsChanged(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_notifySyspropsChanged(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwKeymasterDevice::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
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


BnHwKeymasterDevice::BnHwKeymasterDevice(const ::android::sp<IKeymasterDevice> &_hidl_impl)
        : ::android::hidl::base::V1_0::BnHwBase(_hidl_impl, "android.hardware.keymaster@4.0", "IKeymasterDevice") { 
            _hidl_mImpl = _hidl_impl;
            auto prio = ::android::hardware::getMinSchedulerPolicy(_hidl_impl);
            mSchedPolicy = prio.sched_policy;
            mSchedPriority = prio.prio;
            setRequestingSid(::android::hardware::getRequestingSid(_hidl_impl));
}

BnHwKeymasterDevice::~BnHwKeymasterDevice() {
    ::android::hardware::details::gBnMap->eraseIfEqual(_hidl_mImpl.get(), this);
}

// Methods from ::android::hardware::keymaster::V4_0::IKeymasterDevice follow.
::android::status_t BnHwKeymasterDevice::_hidl_getHardwareInfo(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwKeymasterDevice::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IKeymasterDevice::getHardwareInfo::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.keymaster", "4.0", "IKeymasterDevice", "getHardwareInfo", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IKeymasterDevice*>(_hidl_this->getImpl().get())->getHardwareInfo([&](const auto &_hidl_out_securityLevel, const auto &_hidl_out_keymasterName, const auto &_hidl_out_keymasterAuthorName) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("getHardwareInfo: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeUint32((uint32_t)_hidl_out_securityLevel);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_keymasterName_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_keymasterName, sizeof(_hidl_out_keymasterName), &_hidl__hidl_out_keymasterName_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                _hidl_out_keymasterName,
                _hidl_reply,
                _hidl__hidl_out_keymasterName_parent,
                0 /* parentOffset */);

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_keymasterAuthorName_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_keymasterAuthorName, sizeof(_hidl_out_keymasterAuthorName), &_hidl__hidl_out_keymasterAuthorName_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                _hidl_out_keymasterAuthorName,
                _hidl_reply,
                _hidl__hidl_out_keymasterAuthorName_parent,
                0 /* parentOffset */);

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_securityLevel);
            _hidl_args.push_back((void *)&_hidl_out_keymasterName);
            _hidl_args.push_back((void *)&_hidl_out_keymasterAuthorName);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.keymaster", "4.0", "IKeymasterDevice", "getHardwareInfo", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("getHardwareInfo: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwKeymasterDevice::_hidl_getHmacSharingParameters(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwKeymasterDevice::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IKeymasterDevice::getHmacSharingParameters::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.keymaster", "4.0", "IKeymasterDevice", "getHmacSharingParameters", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IKeymasterDevice*>(_hidl_this->getImpl().get())->getHmacSharingParameters([&](const auto &_hidl_out_error, const auto &_hidl_out_params) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("getHmacSharingParameters: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_error);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_params_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_params, sizeof(_hidl_out_params), &_hidl__hidl_out_params_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_err = writeEmbeddedToParcel(
                _hidl_out_params,
                _hidl_reply,
                _hidl__hidl_out_params_parent,
                0 /* parentOffset */);

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_error);
            _hidl_args.push_back((void *)&_hidl_out_params);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.keymaster", "4.0", "IKeymasterDevice", "getHmacSharingParameters", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("getHmacSharingParameters: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwKeymasterDevice::_hidl_computeSharedHmac(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwKeymasterDevice::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    const ::android::hardware::hidl_vec<::android::hardware::keymaster::V4_0::HmacSharingParameters>* params;

    size_t _hidl_params_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*params), &_hidl_params_parent,  reinterpret_cast<const void **>(&params));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_params_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::keymaster::V4_0::HmacSharingParameters> &>(*params),
            _hidl_data,
            _hidl_params_parent,
            0 /* parentOffset */, &_hidl_params_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < params->size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::keymaster::V4_0::HmacSharingParameters &>((*params)[_hidl_index_0]),
                _hidl_data,
                _hidl_params_child,
                _hidl_index_0 * sizeof(::android::hardware::keymaster::V4_0::HmacSharingParameters));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IKeymasterDevice::computeSharedHmac::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)params);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.keymaster", "4.0", "IKeymasterDevice", "computeSharedHmac", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IKeymasterDevice*>(_hidl_this->getImpl().get())->computeSharedHmac(*params, [&](const auto &_hidl_out_error, const auto &_hidl_out_sharingCheck) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("computeSharedHmac: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_error);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_sharingCheck_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_sharingCheck, sizeof(_hidl_out_sharingCheck), &_hidl__hidl_out_sharingCheck_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_sharingCheck_child;

        _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                _hidl_out_sharingCheck,
                _hidl_reply,
                _hidl__hidl_out_sharingCheck_parent,
                0 /* parentOffset */, &_hidl__hidl_out_sharingCheck_child);

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_error);
            _hidl_args.push_back((void *)&_hidl_out_sharingCheck);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.keymaster", "4.0", "IKeymasterDevice", "computeSharedHmac", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("computeSharedHmac: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwKeymasterDevice::_hidl_verifyAuthorization(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwKeymasterDevice::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint64_t operationHandle;
    const ::android::hardware::hidl_vec<::android::hardware::keymaster::V4_0::KeyParameter>* parametersToVerify;
    ::android::hardware::keymaster::V4_0::HardwareAuthToken* authToken;

    _hidl_err = _hidl_data.readUint64(&operationHandle);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_parametersToVerify_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*parametersToVerify), &_hidl_parametersToVerify_parent,  reinterpret_cast<const void **>(&parametersToVerify));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_parametersToVerify_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::keymaster::V4_0::KeyParameter> &>(*parametersToVerify),
            _hidl_data,
            _hidl_parametersToVerify_parent,
            0 /* parentOffset */, &_hidl_parametersToVerify_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < parametersToVerify->size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::keymaster::V4_0::KeyParameter &>((*parametersToVerify)[_hidl_index_0]),
                _hidl_data,
                _hidl_parametersToVerify_child,
                _hidl_index_0 * sizeof(::android::hardware::keymaster::V4_0::KeyParameter));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    size_t _hidl_authToken_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*authToken), &_hidl_authToken_parent,  const_cast<const void**>(reinterpret_cast<void **>(&authToken)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::keymaster::V4_0::HardwareAuthToken &>(*authToken),
            _hidl_data,
            _hidl_authToken_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IKeymasterDevice::verifyAuthorization::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&operationHandle);
        _hidl_args.push_back((void *)parametersToVerify);
        _hidl_args.push_back((void *)authToken);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.keymaster", "4.0", "IKeymasterDevice", "verifyAuthorization", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IKeymasterDevice*>(_hidl_this->getImpl().get())->verifyAuthorization(operationHandle, *parametersToVerify, *authToken, [&](const auto &_hidl_out_error, const auto &_hidl_out_token) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("verifyAuthorization: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_error);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_token_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_token, sizeof(_hidl_out_token), &_hidl__hidl_out_token_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_err = writeEmbeddedToParcel(
                _hidl_out_token,
                _hidl_reply,
                _hidl__hidl_out_token_parent,
                0 /* parentOffset */);

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_error);
            _hidl_args.push_back((void *)&_hidl_out_token);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.keymaster", "4.0", "IKeymasterDevice", "verifyAuthorization", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("verifyAuthorization: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwKeymasterDevice::_hidl_addRngEntropy(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwKeymasterDevice::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    const ::android::hardware::hidl_vec<uint8_t>* data;

    size_t _hidl_data_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*data), &_hidl_data_parent,  reinterpret_cast<const void **>(&data));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_data_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(*data),
            _hidl_data,
            _hidl_data_parent,
            0 /* parentOffset */, &_hidl_data_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IKeymasterDevice::addRngEntropy::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)data);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.keymaster", "4.0", "IKeymasterDevice", "addRngEntropy", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::keymaster::V4_0::ErrorCode _hidl_out_error = static_cast<IKeymasterDevice*>(_hidl_this->getImpl().get())->addRngEntropy(*data);

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_error);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

_hidl_error:
    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_error);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.keymaster", "4.0", "IKeymasterDevice", "addRngEntropy", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwKeymasterDevice::_hidl_generateKey(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwKeymasterDevice::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    const ::android::hardware::hidl_vec<::android::hardware::keymaster::V4_0::KeyParameter>* keyParams;

    size_t _hidl_keyParams_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*keyParams), &_hidl_keyParams_parent,  reinterpret_cast<const void **>(&keyParams));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_keyParams_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::keymaster::V4_0::KeyParameter> &>(*keyParams),
            _hidl_data,
            _hidl_keyParams_parent,
            0 /* parentOffset */, &_hidl_keyParams_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < keyParams->size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::keymaster::V4_0::KeyParameter &>((*keyParams)[_hidl_index_0]),
                _hidl_data,
                _hidl_keyParams_child,
                _hidl_index_0 * sizeof(::android::hardware::keymaster::V4_0::KeyParameter));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IKeymasterDevice::generateKey::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)keyParams);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.keymaster", "4.0", "IKeymasterDevice", "generateKey", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IKeymasterDevice*>(_hidl_this->getImpl().get())->generateKey(*keyParams, [&](const auto &_hidl_out_error, const auto &_hidl_out_keyBlob, const auto &_hidl_out_keyCharacteristics) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("generateKey: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_error);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_keyBlob_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_keyBlob, sizeof(_hidl_out_keyBlob), &_hidl__hidl_out_keyBlob_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_keyBlob_child;

        _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                _hidl_out_keyBlob,
                _hidl_reply,
                _hidl__hidl_out_keyBlob_parent,
                0 /* parentOffset */, &_hidl__hidl_out_keyBlob_child);

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_keyCharacteristics_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_keyCharacteristics, sizeof(_hidl_out_keyCharacteristics), &_hidl__hidl_out_keyCharacteristics_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_err = writeEmbeddedToParcel(
                _hidl_out_keyCharacteristics,
                _hidl_reply,
                _hidl__hidl_out_keyCharacteristics_parent,
                0 /* parentOffset */);

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_error);
            _hidl_args.push_back((void *)&_hidl_out_keyBlob);
            _hidl_args.push_back((void *)&_hidl_out_keyCharacteristics);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.keymaster", "4.0", "IKeymasterDevice", "generateKey", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("generateKey: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwKeymasterDevice::_hidl_importKey(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwKeymasterDevice::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    const ::android::hardware::hidl_vec<::android::hardware::keymaster::V4_0::KeyParameter>* keyParams;
    ::android::hardware::keymaster::V4_0::KeyFormat keyFormat;
    const ::android::hardware::hidl_vec<uint8_t>* keyData;

    size_t _hidl_keyParams_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*keyParams), &_hidl_keyParams_parent,  reinterpret_cast<const void **>(&keyParams));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_keyParams_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::keymaster::V4_0::KeyParameter> &>(*keyParams),
            _hidl_data,
            _hidl_keyParams_parent,
            0 /* parentOffset */, &_hidl_keyParams_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < keyParams->size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::keymaster::V4_0::KeyParameter &>((*keyParams)[_hidl_index_0]),
                _hidl_data,
                _hidl_keyParams_child,
                _hidl_index_0 * sizeof(::android::hardware::keymaster::V4_0::KeyParameter));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    _hidl_err = _hidl_data.readUint32((uint32_t *)&keyFormat);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_keyData_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*keyData), &_hidl_keyData_parent,  reinterpret_cast<const void **>(&keyData));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_keyData_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(*keyData),
            _hidl_data,
            _hidl_keyData_parent,
            0 /* parentOffset */, &_hidl_keyData_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IKeymasterDevice::importKey::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)keyParams);
        _hidl_args.push_back((void *)&keyFormat);
        _hidl_args.push_back((void *)keyData);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.keymaster", "4.0", "IKeymasterDevice", "importKey", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IKeymasterDevice*>(_hidl_this->getImpl().get())->importKey(*keyParams, keyFormat, *keyData, [&](const auto &_hidl_out_error, const auto &_hidl_out_keyBlob, const auto &_hidl_out_keyCharacteristics) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("importKey: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_error);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_keyBlob_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_keyBlob, sizeof(_hidl_out_keyBlob), &_hidl__hidl_out_keyBlob_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_keyBlob_child;

        _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                _hidl_out_keyBlob,
                _hidl_reply,
                _hidl__hidl_out_keyBlob_parent,
                0 /* parentOffset */, &_hidl__hidl_out_keyBlob_child);

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_keyCharacteristics_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_keyCharacteristics, sizeof(_hidl_out_keyCharacteristics), &_hidl__hidl_out_keyCharacteristics_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_err = writeEmbeddedToParcel(
                _hidl_out_keyCharacteristics,
                _hidl_reply,
                _hidl__hidl_out_keyCharacteristics_parent,
                0 /* parentOffset */);

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_error);
            _hidl_args.push_back((void *)&_hidl_out_keyBlob);
            _hidl_args.push_back((void *)&_hidl_out_keyCharacteristics);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.keymaster", "4.0", "IKeymasterDevice", "importKey", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("importKey: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwKeymasterDevice::_hidl_importWrappedKey(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwKeymasterDevice::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    const ::android::hardware::hidl_vec<uint8_t>* wrappedKeyData;
    const ::android::hardware::hidl_vec<uint8_t>* wrappingKeyBlob;
    const ::android::hardware::hidl_vec<uint8_t>* maskingKey;
    const ::android::hardware::hidl_vec<::android::hardware::keymaster::V4_0::KeyParameter>* unwrappingParams;
    uint64_t passwordSid;
    uint64_t biometricSid;

    size_t _hidl_wrappedKeyData_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*wrappedKeyData), &_hidl_wrappedKeyData_parent,  reinterpret_cast<const void **>(&wrappedKeyData));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_wrappedKeyData_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(*wrappedKeyData),
            _hidl_data,
            _hidl_wrappedKeyData_parent,
            0 /* parentOffset */, &_hidl_wrappedKeyData_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_wrappingKeyBlob_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*wrappingKeyBlob), &_hidl_wrappingKeyBlob_parent,  reinterpret_cast<const void **>(&wrappingKeyBlob));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_wrappingKeyBlob_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(*wrappingKeyBlob),
            _hidl_data,
            _hidl_wrappingKeyBlob_parent,
            0 /* parentOffset */, &_hidl_wrappingKeyBlob_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_maskingKey_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*maskingKey), &_hidl_maskingKey_parent,  reinterpret_cast<const void **>(&maskingKey));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_maskingKey_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(*maskingKey),
            _hidl_data,
            _hidl_maskingKey_parent,
            0 /* parentOffset */, &_hidl_maskingKey_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_unwrappingParams_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*unwrappingParams), &_hidl_unwrappingParams_parent,  reinterpret_cast<const void **>(&unwrappingParams));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_unwrappingParams_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::keymaster::V4_0::KeyParameter> &>(*unwrappingParams),
            _hidl_data,
            _hidl_unwrappingParams_parent,
            0 /* parentOffset */, &_hidl_unwrappingParams_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < unwrappingParams->size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::keymaster::V4_0::KeyParameter &>((*unwrappingParams)[_hidl_index_0]),
                _hidl_data,
                _hidl_unwrappingParams_child,
                _hidl_index_0 * sizeof(::android::hardware::keymaster::V4_0::KeyParameter));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    _hidl_err = _hidl_data.readUint64(&passwordSid);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint64(&biometricSid);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IKeymasterDevice::importWrappedKey::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)wrappedKeyData);
        _hidl_args.push_back((void *)wrappingKeyBlob);
        _hidl_args.push_back((void *)maskingKey);
        _hidl_args.push_back((void *)unwrappingParams);
        _hidl_args.push_back((void *)&passwordSid);
        _hidl_args.push_back((void *)&biometricSid);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.keymaster", "4.0", "IKeymasterDevice", "importWrappedKey", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IKeymasterDevice*>(_hidl_this->getImpl().get())->importWrappedKey(*wrappedKeyData, *wrappingKeyBlob, *maskingKey, *unwrappingParams, passwordSid, biometricSid, [&](const auto &_hidl_out_error, const auto &_hidl_out_keyBlob, const auto &_hidl_out_keyCharacteristics) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("importWrappedKey: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_error);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_keyBlob_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_keyBlob, sizeof(_hidl_out_keyBlob), &_hidl__hidl_out_keyBlob_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_keyBlob_child;

        _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                _hidl_out_keyBlob,
                _hidl_reply,
                _hidl__hidl_out_keyBlob_parent,
                0 /* parentOffset */, &_hidl__hidl_out_keyBlob_child);

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_keyCharacteristics_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_keyCharacteristics, sizeof(_hidl_out_keyCharacteristics), &_hidl__hidl_out_keyCharacteristics_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_err = writeEmbeddedToParcel(
                _hidl_out_keyCharacteristics,
                _hidl_reply,
                _hidl__hidl_out_keyCharacteristics_parent,
                0 /* parentOffset */);

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_error);
            _hidl_args.push_back((void *)&_hidl_out_keyBlob);
            _hidl_args.push_back((void *)&_hidl_out_keyCharacteristics);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.keymaster", "4.0", "IKeymasterDevice", "importWrappedKey", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("importWrappedKey: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwKeymasterDevice::_hidl_getKeyCharacteristics(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwKeymasterDevice::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    const ::android::hardware::hidl_vec<uint8_t>* keyBlob;
    const ::android::hardware::hidl_vec<uint8_t>* clientId;
    const ::android::hardware::hidl_vec<uint8_t>* appData;

    size_t _hidl_keyBlob_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*keyBlob), &_hidl_keyBlob_parent,  reinterpret_cast<const void **>(&keyBlob));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_keyBlob_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(*keyBlob),
            _hidl_data,
            _hidl_keyBlob_parent,
            0 /* parentOffset */, &_hidl_keyBlob_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_clientId_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*clientId), &_hidl_clientId_parent,  reinterpret_cast<const void **>(&clientId));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_clientId_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(*clientId),
            _hidl_data,
            _hidl_clientId_parent,
            0 /* parentOffset */, &_hidl_clientId_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_appData_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*appData), &_hidl_appData_parent,  reinterpret_cast<const void **>(&appData));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_appData_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(*appData),
            _hidl_data,
            _hidl_appData_parent,
            0 /* parentOffset */, &_hidl_appData_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IKeymasterDevice::getKeyCharacteristics::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)keyBlob);
        _hidl_args.push_back((void *)clientId);
        _hidl_args.push_back((void *)appData);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.keymaster", "4.0", "IKeymasterDevice", "getKeyCharacteristics", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IKeymasterDevice*>(_hidl_this->getImpl().get())->getKeyCharacteristics(*keyBlob, *clientId, *appData, [&](const auto &_hidl_out_error, const auto &_hidl_out_keyCharacteristics) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("getKeyCharacteristics: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_error);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_keyCharacteristics_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_keyCharacteristics, sizeof(_hidl_out_keyCharacteristics), &_hidl__hidl_out_keyCharacteristics_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_err = writeEmbeddedToParcel(
                _hidl_out_keyCharacteristics,
                _hidl_reply,
                _hidl__hidl_out_keyCharacteristics_parent,
                0 /* parentOffset */);

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_error);
            _hidl_args.push_back((void *)&_hidl_out_keyCharacteristics);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.keymaster", "4.0", "IKeymasterDevice", "getKeyCharacteristics", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("getKeyCharacteristics: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwKeymasterDevice::_hidl_exportKey(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwKeymasterDevice::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::keymaster::V4_0::KeyFormat keyFormat;
    const ::android::hardware::hidl_vec<uint8_t>* keyBlob;
    const ::android::hardware::hidl_vec<uint8_t>* clientId;
    const ::android::hardware::hidl_vec<uint8_t>* appData;

    _hidl_err = _hidl_data.readUint32((uint32_t *)&keyFormat);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_keyBlob_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*keyBlob), &_hidl_keyBlob_parent,  reinterpret_cast<const void **>(&keyBlob));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_keyBlob_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(*keyBlob),
            _hidl_data,
            _hidl_keyBlob_parent,
            0 /* parentOffset */, &_hidl_keyBlob_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_clientId_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*clientId), &_hidl_clientId_parent,  reinterpret_cast<const void **>(&clientId));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_clientId_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(*clientId),
            _hidl_data,
            _hidl_clientId_parent,
            0 /* parentOffset */, &_hidl_clientId_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_appData_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*appData), &_hidl_appData_parent,  reinterpret_cast<const void **>(&appData));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_appData_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(*appData),
            _hidl_data,
            _hidl_appData_parent,
            0 /* parentOffset */, &_hidl_appData_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IKeymasterDevice::exportKey::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&keyFormat);
        _hidl_args.push_back((void *)keyBlob);
        _hidl_args.push_back((void *)clientId);
        _hidl_args.push_back((void *)appData);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.keymaster", "4.0", "IKeymasterDevice", "exportKey", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IKeymasterDevice*>(_hidl_this->getImpl().get())->exportKey(keyFormat, *keyBlob, *clientId, *appData, [&](const auto &_hidl_out_error, const auto &_hidl_out_keyMaterial) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("exportKey: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_error);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_keyMaterial_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_keyMaterial, sizeof(_hidl_out_keyMaterial), &_hidl__hidl_out_keyMaterial_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_keyMaterial_child;

        _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                _hidl_out_keyMaterial,
                _hidl_reply,
                _hidl__hidl_out_keyMaterial_parent,
                0 /* parentOffset */, &_hidl__hidl_out_keyMaterial_child);

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_error);
            _hidl_args.push_back((void *)&_hidl_out_keyMaterial);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.keymaster", "4.0", "IKeymasterDevice", "exportKey", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("exportKey: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwKeymasterDevice::_hidl_attestKey(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwKeymasterDevice::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    const ::android::hardware::hidl_vec<uint8_t>* keyToAttest;
    const ::android::hardware::hidl_vec<::android::hardware::keymaster::V4_0::KeyParameter>* attestParams;

    size_t _hidl_keyToAttest_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*keyToAttest), &_hidl_keyToAttest_parent,  reinterpret_cast<const void **>(&keyToAttest));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_keyToAttest_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(*keyToAttest),
            _hidl_data,
            _hidl_keyToAttest_parent,
            0 /* parentOffset */, &_hidl_keyToAttest_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_attestParams_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*attestParams), &_hidl_attestParams_parent,  reinterpret_cast<const void **>(&attestParams));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_attestParams_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::keymaster::V4_0::KeyParameter> &>(*attestParams),
            _hidl_data,
            _hidl_attestParams_parent,
            0 /* parentOffset */, &_hidl_attestParams_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < attestParams->size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::keymaster::V4_0::KeyParameter &>((*attestParams)[_hidl_index_0]),
                _hidl_data,
                _hidl_attestParams_child,
                _hidl_index_0 * sizeof(::android::hardware::keymaster::V4_0::KeyParameter));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IKeymasterDevice::attestKey::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)keyToAttest);
        _hidl_args.push_back((void *)attestParams);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.keymaster", "4.0", "IKeymasterDevice", "attestKey", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IKeymasterDevice*>(_hidl_this->getImpl().get())->attestKey(*keyToAttest, *attestParams, [&](const auto &_hidl_out_error, const auto &_hidl_out_certChain) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("attestKey: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_error);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_certChain_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_certChain, sizeof(_hidl_out_certChain), &_hidl__hidl_out_certChain_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_certChain_child;

        _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                _hidl_out_certChain,
                _hidl_reply,
                _hidl__hidl_out_certChain_parent,
                0 /* parentOffset */, &_hidl__hidl_out_certChain_child);

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        for (size_t _hidl_index_0 = 0; _hidl_index_0 < _hidl_out_certChain.size(); ++_hidl_index_0) {
            size_t _hidl__hidl_out_certChain_indexed_child;

            _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                    _hidl_out_certChain[_hidl_index_0],
                    _hidl_reply,
                    _hidl__hidl_out_certChain_child,
                    _hidl_index_0 * sizeof(::android::hardware::hidl_vec<uint8_t>), &_hidl__hidl_out_certChain_indexed_child);

            if (_hidl_err != ::android::OK) { goto _hidl_error; }

        }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_error);
            _hidl_args.push_back((void *)&_hidl_out_certChain);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.keymaster", "4.0", "IKeymasterDevice", "attestKey", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("attestKey: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwKeymasterDevice::_hidl_upgradeKey(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwKeymasterDevice::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    const ::android::hardware::hidl_vec<uint8_t>* keyBlobToUpgrade;
    const ::android::hardware::hidl_vec<::android::hardware::keymaster::V4_0::KeyParameter>* upgradeParams;

    size_t _hidl_keyBlobToUpgrade_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*keyBlobToUpgrade), &_hidl_keyBlobToUpgrade_parent,  reinterpret_cast<const void **>(&keyBlobToUpgrade));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_keyBlobToUpgrade_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(*keyBlobToUpgrade),
            _hidl_data,
            _hidl_keyBlobToUpgrade_parent,
            0 /* parentOffset */, &_hidl_keyBlobToUpgrade_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_upgradeParams_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*upgradeParams), &_hidl_upgradeParams_parent,  reinterpret_cast<const void **>(&upgradeParams));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_upgradeParams_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::keymaster::V4_0::KeyParameter> &>(*upgradeParams),
            _hidl_data,
            _hidl_upgradeParams_parent,
            0 /* parentOffset */, &_hidl_upgradeParams_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < upgradeParams->size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::keymaster::V4_0::KeyParameter &>((*upgradeParams)[_hidl_index_0]),
                _hidl_data,
                _hidl_upgradeParams_child,
                _hidl_index_0 * sizeof(::android::hardware::keymaster::V4_0::KeyParameter));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IKeymasterDevice::upgradeKey::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)keyBlobToUpgrade);
        _hidl_args.push_back((void *)upgradeParams);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.keymaster", "4.0", "IKeymasterDevice", "upgradeKey", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IKeymasterDevice*>(_hidl_this->getImpl().get())->upgradeKey(*keyBlobToUpgrade, *upgradeParams, [&](const auto &_hidl_out_error, const auto &_hidl_out_upgradedKeyBlob) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("upgradeKey: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_error);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_upgradedKeyBlob_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_upgradedKeyBlob, sizeof(_hidl_out_upgradedKeyBlob), &_hidl__hidl_out_upgradedKeyBlob_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_upgradedKeyBlob_child;

        _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                _hidl_out_upgradedKeyBlob,
                _hidl_reply,
                _hidl__hidl_out_upgradedKeyBlob_parent,
                0 /* parentOffset */, &_hidl__hidl_out_upgradedKeyBlob_child);

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_error);
            _hidl_args.push_back((void *)&_hidl_out_upgradedKeyBlob);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.keymaster", "4.0", "IKeymasterDevice", "upgradeKey", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("upgradeKey: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwKeymasterDevice::_hidl_deleteKey(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwKeymasterDevice::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    const ::android::hardware::hidl_vec<uint8_t>* keyBlob;

    size_t _hidl_keyBlob_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*keyBlob), &_hidl_keyBlob_parent,  reinterpret_cast<const void **>(&keyBlob));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_keyBlob_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(*keyBlob),
            _hidl_data,
            _hidl_keyBlob_parent,
            0 /* parentOffset */, &_hidl_keyBlob_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IKeymasterDevice::deleteKey::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)keyBlob);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.keymaster", "4.0", "IKeymasterDevice", "deleteKey", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::keymaster::V4_0::ErrorCode _hidl_out_error = static_cast<IKeymasterDevice*>(_hidl_this->getImpl().get())->deleteKey(*keyBlob);

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_error);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

_hidl_error:
    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_error);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.keymaster", "4.0", "IKeymasterDevice", "deleteKey", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwKeymasterDevice::_hidl_deleteAllKeys(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwKeymasterDevice::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IKeymasterDevice::deleteAllKeys::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.keymaster", "4.0", "IKeymasterDevice", "deleteAllKeys", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::keymaster::V4_0::ErrorCode _hidl_out_error = static_cast<IKeymasterDevice*>(_hidl_this->getImpl().get())->deleteAllKeys();

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_error);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

_hidl_error:
    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_error);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.keymaster", "4.0", "IKeymasterDevice", "deleteAllKeys", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwKeymasterDevice::_hidl_destroyAttestationIds(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwKeymasterDevice::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IKeymasterDevice::destroyAttestationIds::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.keymaster", "4.0", "IKeymasterDevice", "destroyAttestationIds", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::keymaster::V4_0::ErrorCode _hidl_out_error = static_cast<IKeymasterDevice*>(_hidl_this->getImpl().get())->destroyAttestationIds();

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_error);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

_hidl_error:
    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_error);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.keymaster", "4.0", "IKeymasterDevice", "destroyAttestationIds", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwKeymasterDevice::_hidl_begin(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwKeymasterDevice::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::keymaster::V4_0::KeyPurpose purpose;
    const ::android::hardware::hidl_vec<uint8_t>* keyBlob;
    const ::android::hardware::hidl_vec<::android::hardware::keymaster::V4_0::KeyParameter>* inParams;
    ::android::hardware::keymaster::V4_0::HardwareAuthToken* authToken;

    _hidl_err = _hidl_data.readUint32((uint32_t *)&purpose);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_keyBlob_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*keyBlob), &_hidl_keyBlob_parent,  reinterpret_cast<const void **>(&keyBlob));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_keyBlob_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(*keyBlob),
            _hidl_data,
            _hidl_keyBlob_parent,
            0 /* parentOffset */, &_hidl_keyBlob_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_inParams_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*inParams), &_hidl_inParams_parent,  reinterpret_cast<const void **>(&inParams));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_inParams_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::keymaster::V4_0::KeyParameter> &>(*inParams),
            _hidl_data,
            _hidl_inParams_parent,
            0 /* parentOffset */, &_hidl_inParams_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < inParams->size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::keymaster::V4_0::KeyParameter &>((*inParams)[_hidl_index_0]),
                _hidl_data,
                _hidl_inParams_child,
                _hidl_index_0 * sizeof(::android::hardware::keymaster::V4_0::KeyParameter));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    size_t _hidl_authToken_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*authToken), &_hidl_authToken_parent,  const_cast<const void**>(reinterpret_cast<void **>(&authToken)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::keymaster::V4_0::HardwareAuthToken &>(*authToken),
            _hidl_data,
            _hidl_authToken_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IKeymasterDevice::begin::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&purpose);
        _hidl_args.push_back((void *)keyBlob);
        _hidl_args.push_back((void *)inParams);
        _hidl_args.push_back((void *)authToken);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.keymaster", "4.0", "IKeymasterDevice", "begin", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IKeymasterDevice*>(_hidl_this->getImpl().get())->begin(purpose, *keyBlob, *inParams, *authToken, [&](const auto &_hidl_out_error, const auto &_hidl_out_outParams, const auto &_hidl_out_operationHandle) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("begin: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_error);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_outParams_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_outParams, sizeof(_hidl_out_outParams), &_hidl__hidl_out_outParams_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_outParams_child;

        _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                _hidl_out_outParams,
                _hidl_reply,
                _hidl__hidl_out_outParams_parent,
                0 /* parentOffset */, &_hidl__hidl_out_outParams_child);

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        for (size_t _hidl_index_0 = 0; _hidl_index_0 < _hidl_out_outParams.size(); ++_hidl_index_0) {
            _hidl_err = writeEmbeddedToParcel(
                    _hidl_out_outParams[_hidl_index_0],
                    _hidl_reply,
                    _hidl__hidl_out_outParams_child,
                    _hidl_index_0 * sizeof(::android::hardware::keymaster::V4_0::KeyParameter));

            if (_hidl_err != ::android::OK) { goto _hidl_error; }

        }

        _hidl_err = _hidl_reply->writeUint64(_hidl_out_operationHandle);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_error);
            _hidl_args.push_back((void *)&_hidl_out_outParams);
            _hidl_args.push_back((void *)&_hidl_out_operationHandle);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.keymaster", "4.0", "IKeymasterDevice", "begin", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("begin: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwKeymasterDevice::_hidl_update(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwKeymasterDevice::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint64_t operationHandle;
    const ::android::hardware::hidl_vec<::android::hardware::keymaster::V4_0::KeyParameter>* inParams;
    const ::android::hardware::hidl_vec<uint8_t>* input;
    ::android::hardware::keymaster::V4_0::HardwareAuthToken* authToken;
    ::android::hardware::keymaster::V4_0::VerificationToken* verificationToken;

    _hidl_err = _hidl_data.readUint64(&operationHandle);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_inParams_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*inParams), &_hidl_inParams_parent,  reinterpret_cast<const void **>(&inParams));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_inParams_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::keymaster::V4_0::KeyParameter> &>(*inParams),
            _hidl_data,
            _hidl_inParams_parent,
            0 /* parentOffset */, &_hidl_inParams_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < inParams->size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::keymaster::V4_0::KeyParameter &>((*inParams)[_hidl_index_0]),
                _hidl_data,
                _hidl_inParams_child,
                _hidl_index_0 * sizeof(::android::hardware::keymaster::V4_0::KeyParameter));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    size_t _hidl_input_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*input), &_hidl_input_parent,  reinterpret_cast<const void **>(&input));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_input_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(*input),
            _hidl_data,
            _hidl_input_parent,
            0 /* parentOffset */, &_hidl_input_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_authToken_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*authToken), &_hidl_authToken_parent,  const_cast<const void**>(reinterpret_cast<void **>(&authToken)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::keymaster::V4_0::HardwareAuthToken &>(*authToken),
            _hidl_data,
            _hidl_authToken_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_verificationToken_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*verificationToken), &_hidl_verificationToken_parent,  const_cast<const void**>(reinterpret_cast<void **>(&verificationToken)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::keymaster::V4_0::VerificationToken &>(*verificationToken),
            _hidl_data,
            _hidl_verificationToken_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IKeymasterDevice::update::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&operationHandle);
        _hidl_args.push_back((void *)inParams);
        _hidl_args.push_back((void *)input);
        _hidl_args.push_back((void *)authToken);
        _hidl_args.push_back((void *)verificationToken);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.keymaster", "4.0", "IKeymasterDevice", "update", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IKeymasterDevice*>(_hidl_this->getImpl().get())->update(operationHandle, *inParams, *input, *authToken, *verificationToken, [&](const auto &_hidl_out_error, const auto &_hidl_out_inputConsumed, const auto &_hidl_out_outParams, const auto &_hidl_out_output) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("update: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_error);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_err = _hidl_reply->writeUint32(_hidl_out_inputConsumed);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_outParams_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_outParams, sizeof(_hidl_out_outParams), &_hidl__hidl_out_outParams_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_outParams_child;

        _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                _hidl_out_outParams,
                _hidl_reply,
                _hidl__hidl_out_outParams_parent,
                0 /* parentOffset */, &_hidl__hidl_out_outParams_child);

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        for (size_t _hidl_index_0 = 0; _hidl_index_0 < _hidl_out_outParams.size(); ++_hidl_index_0) {
            _hidl_err = writeEmbeddedToParcel(
                    _hidl_out_outParams[_hidl_index_0],
                    _hidl_reply,
                    _hidl__hidl_out_outParams_child,
                    _hidl_index_0 * sizeof(::android::hardware::keymaster::V4_0::KeyParameter));

            if (_hidl_err != ::android::OK) { goto _hidl_error; }

        }

        size_t _hidl__hidl_out_output_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_output, sizeof(_hidl_out_output), &_hidl__hidl_out_output_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_output_child;

        _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                _hidl_out_output,
                _hidl_reply,
                _hidl__hidl_out_output_parent,
                0 /* parentOffset */, &_hidl__hidl_out_output_child);

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_error);
            _hidl_args.push_back((void *)&_hidl_out_inputConsumed);
            _hidl_args.push_back((void *)&_hidl_out_outParams);
            _hidl_args.push_back((void *)&_hidl_out_output);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.keymaster", "4.0", "IKeymasterDevice", "update", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("update: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwKeymasterDevice::_hidl_finish(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwKeymasterDevice::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint64_t operationHandle;
    const ::android::hardware::hidl_vec<::android::hardware::keymaster::V4_0::KeyParameter>* inParams;
    const ::android::hardware::hidl_vec<uint8_t>* input;
    const ::android::hardware::hidl_vec<uint8_t>* signature;
    ::android::hardware::keymaster::V4_0::HardwareAuthToken* authToken;
    ::android::hardware::keymaster::V4_0::VerificationToken* verificationToken;

    _hidl_err = _hidl_data.readUint64(&operationHandle);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_inParams_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*inParams), &_hidl_inParams_parent,  reinterpret_cast<const void **>(&inParams));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_inParams_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::keymaster::V4_0::KeyParameter> &>(*inParams),
            _hidl_data,
            _hidl_inParams_parent,
            0 /* parentOffset */, &_hidl_inParams_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < inParams->size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::keymaster::V4_0::KeyParameter &>((*inParams)[_hidl_index_0]),
                _hidl_data,
                _hidl_inParams_child,
                _hidl_index_0 * sizeof(::android::hardware::keymaster::V4_0::KeyParameter));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    size_t _hidl_input_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*input), &_hidl_input_parent,  reinterpret_cast<const void **>(&input));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_input_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(*input),
            _hidl_data,
            _hidl_input_parent,
            0 /* parentOffset */, &_hidl_input_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_signature_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*signature), &_hidl_signature_parent,  reinterpret_cast<const void **>(&signature));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_signature_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(*signature),
            _hidl_data,
            _hidl_signature_parent,
            0 /* parentOffset */, &_hidl_signature_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_authToken_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*authToken), &_hidl_authToken_parent,  const_cast<const void**>(reinterpret_cast<void **>(&authToken)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::keymaster::V4_0::HardwareAuthToken &>(*authToken),
            _hidl_data,
            _hidl_authToken_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_verificationToken_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*verificationToken), &_hidl_verificationToken_parent,  const_cast<const void**>(reinterpret_cast<void **>(&verificationToken)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::keymaster::V4_0::VerificationToken &>(*verificationToken),
            _hidl_data,
            _hidl_verificationToken_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IKeymasterDevice::finish::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&operationHandle);
        _hidl_args.push_back((void *)inParams);
        _hidl_args.push_back((void *)input);
        _hidl_args.push_back((void *)signature);
        _hidl_args.push_back((void *)authToken);
        _hidl_args.push_back((void *)verificationToken);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.keymaster", "4.0", "IKeymasterDevice", "finish", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IKeymasterDevice*>(_hidl_this->getImpl().get())->finish(operationHandle, *inParams, *input, *signature, *authToken, *verificationToken, [&](const auto &_hidl_out_error, const auto &_hidl_out_outParams, const auto &_hidl_out_output) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("finish: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_error);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_outParams_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_outParams, sizeof(_hidl_out_outParams), &_hidl__hidl_out_outParams_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_outParams_child;

        _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                _hidl_out_outParams,
                _hidl_reply,
                _hidl__hidl_out_outParams_parent,
                0 /* parentOffset */, &_hidl__hidl_out_outParams_child);

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        for (size_t _hidl_index_0 = 0; _hidl_index_0 < _hidl_out_outParams.size(); ++_hidl_index_0) {
            _hidl_err = writeEmbeddedToParcel(
                    _hidl_out_outParams[_hidl_index_0],
                    _hidl_reply,
                    _hidl__hidl_out_outParams_child,
                    _hidl_index_0 * sizeof(::android::hardware::keymaster::V4_0::KeyParameter));

            if (_hidl_err != ::android::OK) { goto _hidl_error; }

        }

        size_t _hidl__hidl_out_output_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_output, sizeof(_hidl_out_output), &_hidl__hidl_out_output_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_output_child;

        _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                _hidl_out_output,
                _hidl_reply,
                _hidl__hidl_out_output_parent,
                0 /* parentOffset */, &_hidl__hidl_out_output_child);

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_error);
            _hidl_args.push_back((void *)&_hidl_out_outParams);
            _hidl_args.push_back((void *)&_hidl_out_output);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.keymaster", "4.0", "IKeymasterDevice", "finish", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("finish: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwKeymasterDevice::_hidl_abort(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwKeymasterDevice::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint64_t operationHandle;

    _hidl_err = _hidl_data.readUint64(&operationHandle);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IKeymasterDevice::abort::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&operationHandle);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.keymaster", "4.0", "IKeymasterDevice", "abort", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::keymaster::V4_0::ErrorCode _hidl_out_error = static_cast<IKeymasterDevice*>(_hidl_this->getImpl().get())->abort(operationHandle);

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_error);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

_hidl_error:
    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_error);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.keymaster", "4.0", "IKeymasterDevice", "abort", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}


// Methods from ::android::hardware::keymaster::V4_0::IKeymasterDevice follow.

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BnHwKeymasterDevice::ping() {
    return ::android::hardware::Void();
}
::android::hardware::Return<void> BnHwKeymasterDevice::getDebugInfo(getDebugInfo_cb _hidl_cb) {
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

::android::status_t BnHwKeymasterDevice::onTransact(
        uint32_t _hidl_code,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        uint32_t _hidl_flags,
        TransactCallback _hidl_cb) {
    ::android::status_t _hidl_err = ::android::OK;

    switch (_hidl_code) {
        case 1 /* getHardwareInfo */:
        {
            _hidl_err = ::android::hardware::keymaster::V4_0::BnHwKeymasterDevice::_hidl_getHardwareInfo(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 2 /* getHmacSharingParameters */:
        {
            _hidl_err = ::android::hardware::keymaster::V4_0::BnHwKeymasterDevice::_hidl_getHmacSharingParameters(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 3 /* computeSharedHmac */:
        {
            _hidl_err = ::android::hardware::keymaster::V4_0::BnHwKeymasterDevice::_hidl_computeSharedHmac(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 4 /* verifyAuthorization */:
        {
            _hidl_err = ::android::hardware::keymaster::V4_0::BnHwKeymasterDevice::_hidl_verifyAuthorization(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 5 /* addRngEntropy */:
        {
            _hidl_err = ::android::hardware::keymaster::V4_0::BnHwKeymasterDevice::_hidl_addRngEntropy(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 6 /* generateKey */:
        {
            _hidl_err = ::android::hardware::keymaster::V4_0::BnHwKeymasterDevice::_hidl_generateKey(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 7 /* importKey */:
        {
            _hidl_err = ::android::hardware::keymaster::V4_0::BnHwKeymasterDevice::_hidl_importKey(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 8 /* importWrappedKey */:
        {
            _hidl_err = ::android::hardware::keymaster::V4_0::BnHwKeymasterDevice::_hidl_importWrappedKey(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 9 /* getKeyCharacteristics */:
        {
            _hidl_err = ::android::hardware::keymaster::V4_0::BnHwKeymasterDevice::_hidl_getKeyCharacteristics(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 10 /* exportKey */:
        {
            _hidl_err = ::android::hardware::keymaster::V4_0::BnHwKeymasterDevice::_hidl_exportKey(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 11 /* attestKey */:
        {
            _hidl_err = ::android::hardware::keymaster::V4_0::BnHwKeymasterDevice::_hidl_attestKey(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 12 /* upgradeKey */:
        {
            _hidl_err = ::android::hardware::keymaster::V4_0::BnHwKeymasterDevice::_hidl_upgradeKey(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 13 /* deleteKey */:
        {
            _hidl_err = ::android::hardware::keymaster::V4_0::BnHwKeymasterDevice::_hidl_deleteKey(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 14 /* deleteAllKeys */:
        {
            _hidl_err = ::android::hardware::keymaster::V4_0::BnHwKeymasterDevice::_hidl_deleteAllKeys(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 15 /* destroyAttestationIds */:
        {
            _hidl_err = ::android::hardware::keymaster::V4_0::BnHwKeymasterDevice::_hidl_destroyAttestationIds(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 16 /* begin */:
        {
            _hidl_err = ::android::hardware::keymaster::V4_0::BnHwKeymasterDevice::_hidl_begin(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 17 /* update */:
        {
            _hidl_err = ::android::hardware::keymaster::V4_0::BnHwKeymasterDevice::_hidl_update(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 18 /* finish */:
        {
            _hidl_err = ::android::hardware::keymaster::V4_0::BnHwKeymasterDevice::_hidl_finish(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 19 /* abort */:
        {
            _hidl_err = ::android::hardware::keymaster::V4_0::BnHwKeymasterDevice::_hidl_abort(this, _hidl_data, _hidl_reply, _hidl_cb);
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

BsKeymasterDevice::BsKeymasterDevice(const ::android::sp<::android::hardware::keymaster::V4_0::IKeymasterDevice> impl) : ::android::hardware::details::HidlInstrumentor("android.hardware.keymaster@4.0", "IKeymasterDevice"), mImpl(impl) {
    mOnewayQueue.start(3000 /* similar limit to binderized */);
}

::android::hardware::Return<void> BsKeymasterDevice::addOnewayTask(std::function<void(void)> fun) {
    if (!mOnewayQueue.push(fun)) {
        return ::android::hardware::Status::fromExceptionCode(
                ::android::hardware::Status::EX_TRANSACTION_FAILED,
                "Passthrough oneway function queue exceeds maximum size.");
    }
    return ::android::hardware::Status();
}

::android::sp<IKeymasterDevice> IKeymasterDevice::tryGetService(const std::string &serviceName, const bool getStub) {
    return ::android::hardware::details::getServiceInternal<BpHwKeymasterDevice>(serviceName, false, getStub);
}

::android::sp<IKeymasterDevice> IKeymasterDevice::getService(const std::string &serviceName, const bool getStub) {
    return ::android::hardware::details::getServiceInternal<BpHwKeymasterDevice>(serviceName, true, getStub);
}

::android::status_t IKeymasterDevice::registerAsService(const std::string &serviceName) {
    return ::android::hardware::details::registerAsServiceInternal(this, serviceName);
}

bool IKeymasterDevice::registerForNotifications(
        const std::string &serviceName,
        const ::android::sp<::android::hidl::manager::V1_0::IServiceNotification> &notification) {
    const ::android::sp<::android::hidl::manager::V1_0::IServiceManager> sm
            = ::android::hardware::defaultServiceManager();
    if (sm == nullptr) {
        return false;
    }
    ::android::hardware::Return<bool> success =
            sm->registerForNotifications("android.hardware.keymaster@4.0::IKeymasterDevice",
                    serviceName, notification);
    return success.isOk() && success;
}

static_assert(sizeof(::android::hardware::MQDescriptor<char, ::android::hardware::kSynchronizedReadWrite>) == 32, "wrong size");
static_assert(sizeof(::android::hardware::hidl_handle) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_memory) == 40, "wrong size");
static_assert(sizeof(::android::hardware::hidl_string) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_vec<char>) == 16, "wrong size");

}  // namespace V4_0
}  // namespace keymaster
}  // namespace hardware
}  // namespace android
