#define LOG_TAG "android.hardware.gatekeeper@1.0::Gatekeeper"

#include <log/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <hidl/Static.h>
#include <hwbinder/ProcessState.h>
#include <utils/Trace.h>
#include <android/hidl/manager/1.0/IServiceManager.h>
#include <android/hardware/gatekeeper/1.0/BpHwGatekeeper.h>
#include <android/hardware/gatekeeper/1.0/BnHwGatekeeper.h>
#include <android/hardware/gatekeeper/1.0/BsGatekeeper.h>
#include <android/hidl/base/1.0/BpHwBase.h>
#include <hidl/ServiceManagement.h>

namespace android {
namespace hardware {
namespace gatekeeper {
namespace V1_0 {

const char* IGatekeeper::descriptor("android.hardware.gatekeeper@1.0::IGatekeeper");

__attribute__((constructor)) static void static_constructor() {
    ::android::hardware::details::getBnConstructorMap().set(IGatekeeper::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hardware::IBinder> {
                return new BnHwGatekeeper(static_cast<IGatekeeper *>(iIntf));
            });
    ::android::hardware::details::getBsConstructorMap().set(IGatekeeper::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hidl::base::V1_0::IBase> {
                return new BsGatekeeper(static_cast<IGatekeeper *>(iIntf));
            });
}

__attribute__((destructor))static void static_destructor() {
    ::android::hardware::details::getBnConstructorMap().erase(IGatekeeper::descriptor);
    ::android::hardware::details::getBsConstructorMap().erase(IGatekeeper::descriptor);
}

// Methods from ::android::hardware::gatekeeper::V1_0::IGatekeeper follow.
// no default implementation for: ::android::hardware::Return<void> IGatekeeper::enroll(uint32_t uid, const ::android::hardware::hidl_vec<uint8_t>& currentPasswordHandle, const ::android::hardware::hidl_vec<uint8_t>& currentPassword, const ::android::hardware::hidl_vec<uint8_t>& desiredPassword, enroll_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IGatekeeper::verify(uint32_t uid, uint64_t challenge, const ::android::hardware::hidl_vec<uint8_t>& enrolledPasswordHandle, const ::android::hardware::hidl_vec<uint8_t>& providedPassword, verify_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IGatekeeper::deleteUser(uint32_t uid, deleteUser_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IGatekeeper::deleteAllUsers(deleteAllUsers_cb _hidl_cb)

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> IGatekeeper::interfaceChain(interfaceChain_cb _hidl_cb){
    _hidl_cb({
        ::android::hardware::gatekeeper::V1_0::IGatekeeper::descriptor,
        ::android::hidl::base::V1_0::IBase::descriptor,
    });
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IGatekeeper::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    (void)fd;
    (void)options;
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IGatekeeper::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    _hidl_cb(::android::hardware::gatekeeper::V1_0::IGatekeeper::descriptor);
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IGatekeeper::getHashChain(getHashChain_cb _hidl_cb){
    _hidl_cb({
        (uint8_t[32]){150,121,242,122,66,247,87,129,200,153,62,241,99,237,146,128,138,25,40,222,24,102,57,131,72,65,208,184,227,38,230,61} /* 9679f27a42f75781c8993ef163ed92808a1928de186639834841d0b8e326e63d */,
        (uint8_t[32]){236,127,215,158,208,45,250,133,188,73,148,38,173,174,62,190,35,239,5,36,243,205,105,87,19,147,36,184,59,24,202,76} /* ec7fd79ed02dfa85bc499426adae3ebe23ef0524f3cd6957139324b83b18ca4c */});
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IGatekeeper::setHALInstrumentation(){
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> IGatekeeper::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    (void)cookie;
    return (recipient != nullptr);
}

::android::hardware::Return<void> IGatekeeper::ping(){
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IGatekeeper::getDebugInfo(getDebugInfo_cb _hidl_cb){
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

::android::hardware::Return<void> IGatekeeper::notifySyspropsChanged(){
    ::android::report_sysprop_change();
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> IGatekeeper::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
    return (recipient != nullptr);
}


::android::hardware::Return<::android::sp<::android::hardware::gatekeeper::V1_0::IGatekeeper>> IGatekeeper::castFrom(const ::android::sp<::android::hardware::gatekeeper::V1_0::IGatekeeper>& parent, bool /* emitError */) {
    return parent;
}

::android::hardware::Return<::android::sp<::android::hardware::gatekeeper::V1_0::IGatekeeper>> IGatekeeper::castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<IGatekeeper, ::android::hidl::base::V1_0::IBase, BpHwGatekeeper>(
            parent, "android.hardware.gatekeeper@1.0::IGatekeeper", emitError);
}

BpHwGatekeeper::BpHwGatekeeper(const ::android::sp<::android::hardware::IBinder> &_hidl_impl)
        : BpInterface<IGatekeeper>(_hidl_impl),
          ::android::hardware::details::HidlInstrumentor("android.hardware.gatekeeper@1.0", "IGatekeeper") {
}

void BpHwGatekeeper::onLastStrongRef(const void* id) {
    {
        std::unique_lock<std::mutex> lock(_hidl_mMutex);
        _hidl_mDeathRecipients.clear();
    }

    BpInterface<IGatekeeper>::onLastStrongRef(id);
}
// Methods from ::android::hardware::gatekeeper::V1_0::IGatekeeper follow.
::android::hardware::Return<void> BpHwGatekeeper::_hidl_enroll(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint32_t uid, const ::android::hardware::hidl_vec<uint8_t>& currentPasswordHandle, const ::android::hardware::hidl_vec<uint8_t>& currentPassword, const ::android::hardware::hidl_vec<uint8_t>& desiredPassword, enroll_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IGatekeeper::enroll::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&uid);
        _hidl_args.push_back((void *)&currentPasswordHandle);
        _hidl_args.push_back((void *)&currentPassword);
        _hidl_args.push_back((void *)&desiredPassword);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.gatekeeper", "1.0", "IGatekeeper", "enroll", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_data.markSensitive();
    _hidl_err = _hidl_data.writeInterfaceToken(BpHwGatekeeper::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(uid);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_currentPasswordHandle_parent;

    _hidl_err = _hidl_data.writeBuffer(&currentPasswordHandle, sizeof(currentPasswordHandle), &_hidl_currentPasswordHandle_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_currentPasswordHandle_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            currentPasswordHandle,
            &_hidl_data,
            _hidl_currentPasswordHandle_parent,
            0 /* parentOffset */, &_hidl_currentPasswordHandle_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_currentPassword_parent;

    _hidl_err = _hidl_data.writeBuffer(&currentPassword, sizeof(currentPassword), &_hidl_currentPassword_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_currentPassword_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            currentPassword,
            &_hidl_data,
            _hidl_currentPassword_parent,
            0 /* parentOffset */, &_hidl_currentPassword_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_desiredPassword_parent;

    _hidl_err = _hidl_data.writeBuffer(&desiredPassword, sizeof(desiredPassword), &_hidl_desiredPassword_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_desiredPassword_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            desiredPassword,
            &_hidl_data,
            _hidl_desiredPassword_parent,
            0 /* parentOffset */, &_hidl_desiredPassword_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(1 /* enroll */, _hidl_data, &_hidl_reply, 0 /* flags */ | 32u /* clear buf */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::gatekeeper::V1_0::GatekeeperResponse* _hidl_out_response;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        size_t _hidl__hidl_out_response_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_response), &_hidl__hidl_out_response_parent,  const_cast<const void**>(reinterpret_cast<void **>(&_hidl_out_response)));
        if (_hidl_err != ::android::OK) { return; }

        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::gatekeeper::V1_0::GatekeeperResponse &>(*_hidl_out_response),
                _hidl_reply,
                _hidl__hidl_out_response_parent,
                0 /* parentOffset */);

        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(*_hidl_out_response);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)_hidl_out_response);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.gatekeeper", "1.0", "IGatekeeper", "enroll", &_hidl_args);
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

::android::hardware::Return<void> BpHwGatekeeper::_hidl_verify(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint32_t uid, uint64_t challenge, const ::android::hardware::hidl_vec<uint8_t>& enrolledPasswordHandle, const ::android::hardware::hidl_vec<uint8_t>& providedPassword, verify_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IGatekeeper::verify::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&uid);
        _hidl_args.push_back((void *)&challenge);
        _hidl_args.push_back((void *)&enrolledPasswordHandle);
        _hidl_args.push_back((void *)&providedPassword);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.gatekeeper", "1.0", "IGatekeeper", "verify", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_data.markSensitive();
    _hidl_err = _hidl_data.writeInterfaceToken(BpHwGatekeeper::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(uid);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(challenge);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_enrolledPasswordHandle_parent;

    _hidl_err = _hidl_data.writeBuffer(&enrolledPasswordHandle, sizeof(enrolledPasswordHandle), &_hidl_enrolledPasswordHandle_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_enrolledPasswordHandle_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            enrolledPasswordHandle,
            &_hidl_data,
            _hidl_enrolledPasswordHandle_parent,
            0 /* parentOffset */, &_hidl_enrolledPasswordHandle_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_providedPassword_parent;

    _hidl_err = _hidl_data.writeBuffer(&providedPassword, sizeof(providedPassword), &_hidl_providedPassword_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_providedPassword_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            providedPassword,
            &_hidl_data,
            _hidl_providedPassword_parent,
            0 /* parentOffset */, &_hidl_providedPassword_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(2 /* verify */, _hidl_data, &_hidl_reply, 0 /* flags */ | 32u /* clear buf */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::gatekeeper::V1_0::GatekeeperResponse* _hidl_out_response;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        size_t _hidl__hidl_out_response_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_response), &_hidl__hidl_out_response_parent,  const_cast<const void**>(reinterpret_cast<void **>(&_hidl_out_response)));
        if (_hidl_err != ::android::OK) { return; }

        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::gatekeeper::V1_0::GatekeeperResponse &>(*_hidl_out_response),
                _hidl_reply,
                _hidl__hidl_out_response_parent,
                0 /* parentOffset */);

        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(*_hidl_out_response);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)_hidl_out_response);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.gatekeeper", "1.0", "IGatekeeper", "verify", &_hidl_args);
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

::android::hardware::Return<void> BpHwGatekeeper::_hidl_deleteUser(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint32_t uid, deleteUser_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IGatekeeper::deleteUser::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&uid);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.gatekeeper", "1.0", "IGatekeeper", "deleteUser", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_data.markSensitive();
    _hidl_err = _hidl_data.writeInterfaceToken(BpHwGatekeeper::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(uid);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(3 /* deleteUser */, _hidl_data, &_hidl_reply, 0 /* flags */ | 32u /* clear buf */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::gatekeeper::V1_0::GatekeeperResponse* _hidl_out_response;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        size_t _hidl__hidl_out_response_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_response), &_hidl__hidl_out_response_parent,  const_cast<const void**>(reinterpret_cast<void **>(&_hidl_out_response)));
        if (_hidl_err != ::android::OK) { return; }

        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::gatekeeper::V1_0::GatekeeperResponse &>(*_hidl_out_response),
                _hidl_reply,
                _hidl__hidl_out_response_parent,
                0 /* parentOffset */);

        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(*_hidl_out_response);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)_hidl_out_response);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.gatekeeper", "1.0", "IGatekeeper", "deleteUser", &_hidl_args);
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

::android::hardware::Return<void> BpHwGatekeeper::_hidl_deleteAllUsers(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, deleteAllUsers_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IGatekeeper::deleteAllUsers::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.gatekeeper", "1.0", "IGatekeeper", "deleteAllUsers", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_data.markSensitive();
    _hidl_err = _hidl_data.writeInterfaceToken(BpHwGatekeeper::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(4 /* deleteAllUsers */, _hidl_data, &_hidl_reply, 0 /* flags */ | 32u /* clear buf */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::gatekeeper::V1_0::GatekeeperResponse* _hidl_out_response;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        size_t _hidl__hidl_out_response_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_response), &_hidl__hidl_out_response_parent,  const_cast<const void**>(reinterpret_cast<void **>(&_hidl_out_response)));
        if (_hidl_err != ::android::OK) { return; }

        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::gatekeeper::V1_0::GatekeeperResponse &>(*_hidl_out_response),
                _hidl_reply,
                _hidl__hidl_out_response_parent,
                0 /* parentOffset */);

        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(*_hidl_out_response);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)_hidl_out_response);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.gatekeeper", "1.0", "IGatekeeper", "deleteAllUsers", &_hidl_args);
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


// Methods from ::android::hardware::gatekeeper::V1_0::IGatekeeper follow.
::android::hardware::Return<void> BpHwGatekeeper::enroll(uint32_t uid, const ::android::hardware::hidl_vec<uint8_t>& currentPasswordHandle, const ::android::hardware::hidl_vec<uint8_t>& currentPassword, const ::android::hardware::hidl_vec<uint8_t>& desiredPassword, enroll_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::gatekeeper::V1_0::BpHwGatekeeper::_hidl_enroll(this, this, uid, currentPasswordHandle, currentPassword, desiredPassword, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwGatekeeper::verify(uint32_t uid, uint64_t challenge, const ::android::hardware::hidl_vec<uint8_t>& enrolledPasswordHandle, const ::android::hardware::hidl_vec<uint8_t>& providedPassword, verify_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::gatekeeper::V1_0::BpHwGatekeeper::_hidl_verify(this, this, uid, challenge, enrolledPasswordHandle, providedPassword, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwGatekeeper::deleteUser(uint32_t uid, deleteUser_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::gatekeeper::V1_0::BpHwGatekeeper::_hidl_deleteUser(this, this, uid, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwGatekeeper::deleteAllUsers(deleteAllUsers_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::gatekeeper::V1_0::BpHwGatekeeper::_hidl_deleteAllUsers(this, this, _hidl_cb);

    return _hidl_out;
}


// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BpHwGatekeeper::interfaceChain(interfaceChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwGatekeeper::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_debug(this, this, fd, options);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwGatekeeper::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceDescriptor(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwGatekeeper::getHashChain(getHashChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getHashChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwGatekeeper::setHALInstrumentation(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_setHALInstrumentation(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwGatekeeper::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    ::android::hardware::ProcessState::self()->startThreadPool();
    ::android::hardware::hidl_binder_death_recipient *binder_recipient = new ::android::hardware::hidl_binder_death_recipient(recipient, cookie, this);
    std::unique_lock<std::mutex> lock(_hidl_mMutex);
    _hidl_mDeathRecipients.push_back(binder_recipient);
    return (remote()->linkToDeath(binder_recipient) == ::android::OK);
}

::android::hardware::Return<void> BpHwGatekeeper::ping(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_ping(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwGatekeeper::getDebugInfo(getDebugInfo_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getDebugInfo(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwGatekeeper::notifySyspropsChanged(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_notifySyspropsChanged(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwGatekeeper::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
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


BnHwGatekeeper::BnHwGatekeeper(const ::android::sp<IGatekeeper> &_hidl_impl)
        : ::android::hidl::base::V1_0::BnHwBase(_hidl_impl, "android.hardware.gatekeeper@1.0", "IGatekeeper") { 
            _hidl_mImpl = _hidl_impl;
            auto prio = ::android::hardware::getMinSchedulerPolicy(_hidl_impl);
            mSchedPolicy = prio.sched_policy;
            mSchedPriority = prio.prio;
            setRequestingSid(::android::hardware::getRequestingSid(_hidl_impl));
}

BnHwGatekeeper::~BnHwGatekeeper() {
    ::android::hardware::details::gBnMap->eraseIfEqual(_hidl_mImpl.get(), this);
}

// Methods from ::android::hardware::gatekeeper::V1_0::IGatekeeper follow.
::android::status_t BnHwGatekeeper::_hidl_enroll(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwGatekeeper::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint32_t uid;
    const ::android::hardware::hidl_vec<uint8_t>* currentPasswordHandle;
    const ::android::hardware::hidl_vec<uint8_t>* currentPassword;
    const ::android::hardware::hidl_vec<uint8_t>* desiredPassword;

    _hidl_err = _hidl_data.readUint32(&uid);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_currentPasswordHandle_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*currentPasswordHandle), &_hidl_currentPasswordHandle_parent,  reinterpret_cast<const void **>(&currentPasswordHandle));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_currentPasswordHandle_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(*currentPasswordHandle),
            _hidl_data,
            _hidl_currentPasswordHandle_parent,
            0 /* parentOffset */, &_hidl_currentPasswordHandle_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_currentPassword_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*currentPassword), &_hidl_currentPassword_parent,  reinterpret_cast<const void **>(&currentPassword));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_currentPassword_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(*currentPassword),
            _hidl_data,
            _hidl_currentPassword_parent,
            0 /* parentOffset */, &_hidl_currentPassword_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_desiredPassword_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*desiredPassword), &_hidl_desiredPassword_parent,  reinterpret_cast<const void **>(&desiredPassword));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_desiredPassword_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(*desiredPassword),
            _hidl_data,
            _hidl_desiredPassword_parent,
            0 /* parentOffset */, &_hidl_desiredPassword_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IGatekeeper::enroll::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&uid);
        _hidl_args.push_back((void *)currentPasswordHandle);
        _hidl_args.push_back((void *)currentPassword);
        _hidl_args.push_back((void *)desiredPassword);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.gatekeeper", "1.0", "IGatekeeper", "enroll", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IGatekeeper*>(_hidl_this->getImpl().get())->enroll(uid, *currentPasswordHandle, *currentPassword, *desiredPassword, [&](const auto &_hidl_out_response) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("enroll: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        size_t _hidl__hidl_out_response_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_response, sizeof(_hidl_out_response), &_hidl__hidl_out_response_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_err = writeEmbeddedToParcel(
                _hidl_out_response,
                _hidl_reply,
                _hidl__hidl_out_response_parent,
                0 /* parentOffset */);

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_response);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.gatekeeper", "1.0", "IGatekeeper", "enroll", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("enroll: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwGatekeeper::_hidl_verify(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwGatekeeper::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint32_t uid;
    uint64_t challenge;
    const ::android::hardware::hidl_vec<uint8_t>* enrolledPasswordHandle;
    const ::android::hardware::hidl_vec<uint8_t>* providedPassword;

    _hidl_err = _hidl_data.readUint32(&uid);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint64(&challenge);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_enrolledPasswordHandle_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*enrolledPasswordHandle), &_hidl_enrolledPasswordHandle_parent,  reinterpret_cast<const void **>(&enrolledPasswordHandle));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_enrolledPasswordHandle_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(*enrolledPasswordHandle),
            _hidl_data,
            _hidl_enrolledPasswordHandle_parent,
            0 /* parentOffset */, &_hidl_enrolledPasswordHandle_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_providedPassword_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*providedPassword), &_hidl_providedPassword_parent,  reinterpret_cast<const void **>(&providedPassword));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_providedPassword_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(*providedPassword),
            _hidl_data,
            _hidl_providedPassword_parent,
            0 /* parentOffset */, &_hidl_providedPassword_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IGatekeeper::verify::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&uid);
        _hidl_args.push_back((void *)&challenge);
        _hidl_args.push_back((void *)enrolledPasswordHandle);
        _hidl_args.push_back((void *)providedPassword);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.gatekeeper", "1.0", "IGatekeeper", "verify", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IGatekeeper*>(_hidl_this->getImpl().get())->verify(uid, challenge, *enrolledPasswordHandle, *providedPassword, [&](const auto &_hidl_out_response) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("verify: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        size_t _hidl__hidl_out_response_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_response, sizeof(_hidl_out_response), &_hidl__hidl_out_response_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_err = writeEmbeddedToParcel(
                _hidl_out_response,
                _hidl_reply,
                _hidl__hidl_out_response_parent,
                0 /* parentOffset */);

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_response);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.gatekeeper", "1.0", "IGatekeeper", "verify", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("verify: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwGatekeeper::_hidl_deleteUser(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwGatekeeper::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint32_t uid;

    _hidl_err = _hidl_data.readUint32(&uid);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IGatekeeper::deleteUser::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&uid);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.gatekeeper", "1.0", "IGatekeeper", "deleteUser", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IGatekeeper*>(_hidl_this->getImpl().get())->deleteUser(uid, [&](const auto &_hidl_out_response) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("deleteUser: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        size_t _hidl__hidl_out_response_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_response, sizeof(_hidl_out_response), &_hidl__hidl_out_response_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_err = writeEmbeddedToParcel(
                _hidl_out_response,
                _hidl_reply,
                _hidl__hidl_out_response_parent,
                0 /* parentOffset */);

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_response);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.gatekeeper", "1.0", "IGatekeeper", "deleteUser", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("deleteUser: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwGatekeeper::_hidl_deleteAllUsers(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwGatekeeper::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IGatekeeper::deleteAllUsers::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.gatekeeper", "1.0", "IGatekeeper", "deleteAllUsers", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IGatekeeper*>(_hidl_this->getImpl().get())->deleteAllUsers([&](const auto &_hidl_out_response) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("deleteAllUsers: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        size_t _hidl__hidl_out_response_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_response, sizeof(_hidl_out_response), &_hidl__hidl_out_response_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_err = writeEmbeddedToParcel(
                _hidl_out_response,
                _hidl_reply,
                _hidl__hidl_out_response_parent,
                0 /* parentOffset */);

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_response);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.gatekeeper", "1.0", "IGatekeeper", "deleteAllUsers", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("deleteAllUsers: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}


// Methods from ::android::hardware::gatekeeper::V1_0::IGatekeeper follow.

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BnHwGatekeeper::ping() {
    return ::android::hardware::Void();
}
::android::hardware::Return<void> BnHwGatekeeper::getDebugInfo(getDebugInfo_cb _hidl_cb) {
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

::android::status_t BnHwGatekeeper::onTransact(
        uint32_t _hidl_code,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        uint32_t _hidl_flags,
        TransactCallback _hidl_cb) {
    ::android::status_t _hidl_err = ::android::OK;

    switch (_hidl_code) {
        case 1 /* enroll */:
        {
            _hidl_err = ::android::hardware::gatekeeper::V1_0::BnHwGatekeeper::_hidl_enroll(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 2 /* verify */:
        {
            _hidl_err = ::android::hardware::gatekeeper::V1_0::BnHwGatekeeper::_hidl_verify(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 3 /* deleteUser */:
        {
            _hidl_err = ::android::hardware::gatekeeper::V1_0::BnHwGatekeeper::_hidl_deleteUser(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 4 /* deleteAllUsers */:
        {
            _hidl_err = ::android::hardware::gatekeeper::V1_0::BnHwGatekeeper::_hidl_deleteAllUsers(this, _hidl_data, _hidl_reply, _hidl_cb);
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

BsGatekeeper::BsGatekeeper(const ::android::sp<::android::hardware::gatekeeper::V1_0::IGatekeeper> impl) : ::android::hardware::details::HidlInstrumentor("android.hardware.gatekeeper@1.0", "IGatekeeper"), mImpl(impl) {
    mOnewayQueue.start(3000 /* similar limit to binderized */);
}

::android::hardware::Return<void> BsGatekeeper::addOnewayTask(std::function<void(void)> fun) {
    if (!mOnewayQueue.push(fun)) {
        return ::android::hardware::Status::fromExceptionCode(
                ::android::hardware::Status::EX_TRANSACTION_FAILED,
                "Passthrough oneway function queue exceeds maximum size.");
    }
    return ::android::hardware::Status();
}

::android::sp<IGatekeeper> IGatekeeper::tryGetService(const std::string &serviceName, const bool getStub) {
    return ::android::hardware::details::getServiceInternal<BpHwGatekeeper>(serviceName, false, getStub);
}

::android::sp<IGatekeeper> IGatekeeper::getService(const std::string &serviceName, const bool getStub) {
    return ::android::hardware::details::getServiceInternal<BpHwGatekeeper>(serviceName, true, getStub);
}

::android::status_t IGatekeeper::registerAsService(const std::string &serviceName) {
    return ::android::hardware::details::registerAsServiceInternal(this, serviceName);
}

bool IGatekeeper::registerForNotifications(
        const std::string &serviceName,
        const ::android::sp<::android::hidl::manager::V1_0::IServiceNotification> &notification) {
    const ::android::sp<::android::hidl::manager::V1_0::IServiceManager> sm
            = ::android::hardware::defaultServiceManager();
    if (sm == nullptr) {
        return false;
    }
    ::android::hardware::Return<bool> success =
            sm->registerForNotifications("android.hardware.gatekeeper@1.0::IGatekeeper",
                    serviceName, notification);
    return success.isOk() && success;
}

static_assert(sizeof(::android::hardware::MQDescriptor<char, ::android::hardware::kSynchronizedReadWrite>) == 32, "wrong size");
static_assert(sizeof(::android::hardware::hidl_handle) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_memory) == 40, "wrong size");
static_assert(sizeof(::android::hardware::hidl_string) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_vec<char>) == 16, "wrong size");

}  // namespace V1_0
}  // namespace gatekeeper
}  // namespace hardware
}  // namespace android
