#define LOG_TAG "android.hardware.keymaster@4.1::KeymasterDevice"

#include <log/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <hidl/Static.h>
#include <hwbinder/ProcessState.h>
#include <utils/Trace.h>
#include <android/hidl/manager/1.0/IServiceManager.h>
#include <android/hardware/keymaster/4.1/BpHwKeymasterDevice.h>
#include <android/hardware/keymaster/4.1/BnHwKeymasterDevice.h>
#include <android/hardware/keymaster/4.1/BsKeymasterDevice.h>
#include <android/hardware/keymaster/4.0/BpHwKeymasterDevice.h>
#include <android/hidl/base/1.0/BpHwBase.h>
#include <hidl/ServiceManagement.h>

namespace android {
namespace hardware {
namespace keymaster {
namespace V4_1 {

const char* IKeymasterDevice::descriptor("android.hardware.keymaster@4.1::IKeymasterDevice");

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

// Methods from ::android::hardware::keymaster::V4_1::IKeymasterDevice follow.
// no default implementation for: ::android::hardware::Return<::android::hardware::keymaster::V4_1::ErrorCode> IKeymasterDevice::deviceLocked(bool passwordOnly, const ::android::hardware::keymaster::V4_0::VerificationToken& verificationToken)
// no default implementation for: ::android::hardware::Return<::android::hardware::keymaster::V4_1::ErrorCode> IKeymasterDevice::earlyBootEnded()

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> IKeymasterDevice::interfaceChain(interfaceChain_cb _hidl_cb){
    _hidl_cb({
        ::android::hardware::keymaster::V4_1::IKeymasterDevice::descriptor,
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
    _hidl_cb(::android::hardware::keymaster::V4_1::IKeymasterDevice::descriptor);
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IKeymasterDevice::getHashChain(getHashChain_cb _hidl_cb){
    _hidl_cb({
        (uint8_t[32]){218,190,35,221,231,201,227,173,101,198,29,239,115,146,241,134,215,239,231,244,33,111,155,111,156,240,134,55,69,177,169,244} /* dabe23dde7c9e3ad65c61def7392f186d7efe7f4216f9b6f9cf0863745b1a9f4 */,
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


::android::hardware::Return<::android::sp<::android::hardware::keymaster::V4_1::IKeymasterDevice>> IKeymasterDevice::castFrom(const ::android::sp<::android::hardware::keymaster::V4_1::IKeymasterDevice>& parent, bool /* emitError */) {
    return parent;
}

::android::hardware::Return<::android::sp<::android::hardware::keymaster::V4_1::IKeymasterDevice>> IKeymasterDevice::castFrom(const ::android::sp<::android::hardware::keymaster::V4_0::IKeymasterDevice>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<IKeymasterDevice, ::android::hardware::keymaster::V4_0::IKeymasterDevice, BpHwKeymasterDevice>(
            parent, "android.hardware.keymaster@4.1::IKeymasterDevice", emitError);
}

::android::hardware::Return<::android::sp<::android::hardware::keymaster::V4_1::IKeymasterDevice>> IKeymasterDevice::castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<IKeymasterDevice, ::android::hidl::base::V1_0::IBase, BpHwKeymasterDevice>(
            parent, "android.hardware.keymaster@4.1::IKeymasterDevice", emitError);
}

BpHwKeymasterDevice::BpHwKeymasterDevice(const ::android::sp<::android::hardware::IBinder> &_hidl_impl)
        : BpInterface<IKeymasterDevice>(_hidl_impl),
          ::android::hardware::details::HidlInstrumentor("android.hardware.keymaster@4.1", "IKeymasterDevice") {
}

void BpHwKeymasterDevice::onLastStrongRef(const void* id) {
    {
        std::unique_lock<std::mutex> lock(_hidl_mMutex);
        _hidl_mDeathRecipients.clear();
    }

    BpInterface<IKeymasterDevice>::onLastStrongRef(id);
}
// Methods from ::android::hardware::keymaster::V4_1::IKeymasterDevice follow.
::android::hardware::Return<::android::hardware::keymaster::V4_1::ErrorCode> BpHwKeymasterDevice::_hidl_deviceLocked(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, bool passwordOnly, const ::android::hardware::keymaster::V4_0::VerificationToken& verificationToken) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IKeymasterDevice::deviceLocked::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&passwordOnly);
        _hidl_args.push_back((void *)&verificationToken);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.keymaster", "4.1", "IKeymasterDevice", "deviceLocked", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    ::android::hardware::keymaster::V4_1::ErrorCode _hidl_out_error;

    _hidl_data.markSensitive();
    _hidl_err = _hidl_data.writeInterfaceToken(BpHwKeymasterDevice::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeBool(passwordOnly);
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

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(20 /* deviceLocked */, _hidl_data, &_hidl_reply, 0 /* flags */ | 32u /* clear buf */);
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
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.keymaster", "4.1", "IKeymasterDevice", "deviceLocked", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<::android::hardware::keymaster::V4_1::ErrorCode>(_hidl_out_error);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<::android::hardware::keymaster::V4_1::ErrorCode>(_hidl_status);
}

::android::hardware::Return<::android::hardware::keymaster::V4_1::ErrorCode> BpHwKeymasterDevice::_hidl_earlyBootEnded(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IKeymasterDevice::earlyBootEnded::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.keymaster", "4.1", "IKeymasterDevice", "earlyBootEnded", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    ::android::hardware::keymaster::V4_1::ErrorCode _hidl_out_error;

    _hidl_data.markSensitive();
    _hidl_err = _hidl_data.writeInterfaceToken(BpHwKeymasterDevice::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(21 /* earlyBootEnded */, _hidl_data, &_hidl_reply, 0 /* flags */ | 32u /* clear buf */);
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
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.keymaster", "4.1", "IKeymasterDevice", "earlyBootEnded", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<::android::hardware::keymaster::V4_1::ErrorCode>(_hidl_out_error);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<::android::hardware::keymaster::V4_1::ErrorCode>(_hidl_status);
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


// Methods from ::android::hardware::keymaster::V4_1::IKeymasterDevice follow.
::android::hardware::Return<::android::hardware::keymaster::V4_1::ErrorCode> BpHwKeymasterDevice::deviceLocked(bool passwordOnly, const ::android::hardware::keymaster::V4_0::VerificationToken& verificationToken){
    ::android::hardware::Return<::android::hardware::keymaster::V4_1::ErrorCode>  _hidl_out = ::android::hardware::keymaster::V4_1::BpHwKeymasterDevice::_hidl_deviceLocked(this, this, passwordOnly, verificationToken);

    return _hidl_out;
}

::android::hardware::Return<::android::hardware::keymaster::V4_1::ErrorCode> BpHwKeymasterDevice::earlyBootEnded(){
    ::android::hardware::Return<::android::hardware::keymaster::V4_1::ErrorCode>  _hidl_out = ::android::hardware::keymaster::V4_1::BpHwKeymasterDevice::_hidl_earlyBootEnded(this, this);

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
        : ::android::hidl::base::V1_0::BnHwBase(_hidl_impl, "android.hardware.keymaster@4.1", "IKeymasterDevice") { 
            _hidl_mImpl = _hidl_impl;
            auto prio = ::android::hardware::getMinSchedulerPolicy(_hidl_impl);
            mSchedPolicy = prio.sched_policy;
            mSchedPriority = prio.prio;
            setRequestingSid(::android::hardware::getRequestingSid(_hidl_impl));
}

BnHwKeymasterDevice::~BnHwKeymasterDevice() {
    ::android::hardware::details::gBnMap->eraseIfEqual(_hidl_mImpl.get(), this);
}

// Methods from ::android::hardware::keymaster::V4_1::IKeymasterDevice follow.
::android::status_t BnHwKeymasterDevice::_hidl_deviceLocked(
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

    bool passwordOnly;
    ::android::hardware::keymaster::V4_0::VerificationToken* verificationToken;

    _hidl_err = _hidl_data.readBool(&passwordOnly);
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IKeymasterDevice::deviceLocked::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&passwordOnly);
        _hidl_args.push_back((void *)verificationToken);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.keymaster", "4.1", "IKeymasterDevice", "deviceLocked", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::keymaster::V4_1::ErrorCode _hidl_out_error = static_cast<IKeymasterDevice*>(_hidl_this->getImpl().get())->deviceLocked(passwordOnly, *verificationToken);

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
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.keymaster", "4.1", "IKeymasterDevice", "deviceLocked", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwKeymasterDevice::_hidl_earlyBootEnded(
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

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IKeymasterDevice::earlyBootEnded::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.keymaster", "4.1", "IKeymasterDevice", "earlyBootEnded", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::keymaster::V4_1::ErrorCode _hidl_out_error = static_cast<IKeymasterDevice*>(_hidl_this->getImpl().get())->earlyBootEnded();

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
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.keymaster", "4.1", "IKeymasterDevice", "earlyBootEnded", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}


// Methods from ::android::hardware::keymaster::V4_0::IKeymasterDevice follow.

// Methods from ::android::hardware::keymaster::V4_1::IKeymasterDevice follow.

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

        case 20 /* deviceLocked */:
        {
            _hidl_err = ::android::hardware::keymaster::V4_1::BnHwKeymasterDevice::_hidl_deviceLocked(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 21 /* earlyBootEnded */:
        {
            _hidl_err = ::android::hardware::keymaster::V4_1::BnHwKeymasterDevice::_hidl_earlyBootEnded(this, _hidl_data, _hidl_reply, _hidl_cb);
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

BsKeymasterDevice::BsKeymasterDevice(const ::android::sp<::android::hardware::keymaster::V4_1::IKeymasterDevice> impl) : ::android::hardware::details::HidlInstrumentor("android.hardware.keymaster@4.1", "IKeymasterDevice"), mImpl(impl) {
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
            sm->registerForNotifications("android.hardware.keymaster@4.1::IKeymasterDevice",
                    serviceName, notification);
    return success.isOk() && success;
}

static_assert(sizeof(::android::hardware::MQDescriptor<char, ::android::hardware::kSynchronizedReadWrite>) == 32, "wrong size");
static_assert(sizeof(::android::hardware::hidl_handle) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_memory) == 40, "wrong size");
static_assert(sizeof(::android::hardware::hidl_string) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_vec<char>) == 16, "wrong size");

}  // namespace V4_1
}  // namespace keymaster
}  // namespace hardware
}  // namespace android
