#define LOG_TAG "android.hardware.cas@1.0::Cas"

#include <log/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <hidl/Static.h>
#include <hwbinder/ProcessState.h>
#include <utils/Trace.h>
#include <android/hidl/manager/1.0/IServiceManager.h>
#include <android/hardware/cas/1.0/BpHwCas.h>
#include <android/hardware/cas/1.0/BnHwCas.h>
#include <android/hardware/cas/1.0/BsCas.h>
#include <android/hidl/base/1.0/BpHwBase.h>
#include <hidl/ServiceManagement.h>

namespace android {
namespace hardware {
namespace cas {
namespace V1_0 {

const char* ICas::descriptor("android.hardware.cas@1.0::ICas");

__attribute__((constructor)) static void static_constructor() {
    ::android::hardware::details::getBnConstructorMap().set(ICas::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hardware::IBinder> {
                return new BnHwCas(static_cast<ICas *>(iIntf));
            });
    ::android::hardware::details::getBsConstructorMap().set(ICas::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hidl::base::V1_0::IBase> {
                return new BsCas(static_cast<ICas *>(iIntf));
            });
}

__attribute__((destructor))static void static_destructor() {
    ::android::hardware::details::getBnConstructorMap().erase(ICas::descriptor);
    ::android::hardware::details::getBsConstructorMap().erase(ICas::descriptor);
}

// Methods from ::android::hardware::cas::V1_0::ICas follow.
// no default implementation for: ::android::hardware::Return<::android::hardware::cas::V1_0::Status> ICas::setPrivateData(const ::android::hardware::hidl_vec<uint8_t>& pvtData)
// no default implementation for: ::android::hardware::Return<void> ICas::openSession(openSession_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<::android::hardware::cas::V1_0::Status> ICas::closeSession(const ::android::hardware::hidl_vec<uint8_t>& sessionId)
// no default implementation for: ::android::hardware::Return<::android::hardware::cas::V1_0::Status> ICas::setSessionPrivateData(const ::android::hardware::hidl_vec<uint8_t>& sessionId, const ::android::hardware::hidl_vec<uint8_t>& pvtData)
// no default implementation for: ::android::hardware::Return<::android::hardware::cas::V1_0::Status> ICas::processEcm(const ::android::hardware::hidl_vec<uint8_t>& sessionId, const ::android::hardware::hidl_vec<uint8_t>& ecm)
// no default implementation for: ::android::hardware::Return<::android::hardware::cas::V1_0::Status> ICas::processEmm(const ::android::hardware::hidl_vec<uint8_t>& emm)
// no default implementation for: ::android::hardware::Return<::android::hardware::cas::V1_0::Status> ICas::sendEvent(int32_t event, int32_t arg, const ::android::hardware::hidl_vec<uint8_t>& eventData)
// no default implementation for: ::android::hardware::Return<::android::hardware::cas::V1_0::Status> ICas::provision(const ::android::hardware::hidl_string& provisionString)
// no default implementation for: ::android::hardware::Return<::android::hardware::cas::V1_0::Status> ICas::refreshEntitlements(int32_t refreshType, const ::android::hardware::hidl_vec<uint8_t>& refreshData)
// no default implementation for: ::android::hardware::Return<::android::hardware::cas::V1_0::Status> ICas::release()

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> ICas::interfaceChain(interfaceChain_cb _hidl_cb){
    _hidl_cb({
        ::android::hardware::cas::V1_0::ICas::descriptor,
        ::android::hidl::base::V1_0::IBase::descriptor,
    });
    return ::android::hardware::Void();
}

::android::hardware::Return<void> ICas::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    (void)fd;
    (void)options;
    return ::android::hardware::Void();
}

::android::hardware::Return<void> ICas::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    _hidl_cb(::android::hardware::cas::V1_0::ICas::descriptor);
    return ::android::hardware::Void();
}

::android::hardware::Return<void> ICas::getHashChain(getHashChain_cb _hidl_cb){
    _hidl_cb({
        (uint8_t[32]){14,101,107,161,186,193,20,97,161,112,150,239,117,43,105,210,75,0,13,130,14,245,101,47,1,80,160,249,115,29,84,194} /* 0e656ba1bac11461a17096ef752b69d24b000d820ef5652f0150a0f9731d54c2 */,
        (uint8_t[32]){236,127,215,158,208,45,250,133,188,73,148,38,173,174,62,190,35,239,5,36,243,205,105,87,19,147,36,184,59,24,202,76} /* ec7fd79ed02dfa85bc499426adae3ebe23ef0524f3cd6957139324b83b18ca4c */});
    return ::android::hardware::Void();
}

::android::hardware::Return<void> ICas::setHALInstrumentation(){
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> ICas::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    (void)cookie;
    return (recipient != nullptr);
}

::android::hardware::Return<void> ICas::ping(){
    return ::android::hardware::Void();
}

::android::hardware::Return<void> ICas::getDebugInfo(getDebugInfo_cb _hidl_cb){
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

::android::hardware::Return<void> ICas::notifySyspropsChanged(){
    ::android::report_sysprop_change();
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> ICas::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
    return (recipient != nullptr);
}


::android::hardware::Return<::android::sp<::android::hardware::cas::V1_0::ICas>> ICas::castFrom(const ::android::sp<::android::hardware::cas::V1_0::ICas>& parent, bool /* emitError */) {
    return parent;
}

::android::hardware::Return<::android::sp<::android::hardware::cas::V1_0::ICas>> ICas::castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<ICas, ::android::hidl::base::V1_0::IBase, BpHwCas>(
            parent, "android.hardware.cas@1.0::ICas", emitError);
}

BpHwCas::BpHwCas(const ::android::sp<::android::hardware::IBinder> &_hidl_impl)
        : BpInterface<ICas>(_hidl_impl),
          ::android::hardware::details::HidlInstrumentor("android.hardware.cas@1.0", "ICas") {
}

void BpHwCas::onLastStrongRef(const void* id) {
    {
        std::unique_lock<std::mutex> lock(_hidl_mMutex);
        _hidl_mDeathRecipients.clear();
    }

    BpInterface<ICas>::onLastStrongRef(id);
}
// Methods from ::android::hardware::cas::V1_0::ICas follow.
::android::hardware::Return<::android::hardware::cas::V1_0::Status> BpHwCas::_hidl_setPrivateData(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::hidl_vec<uint8_t>& pvtData) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::ICas::setPrivateData::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&pvtData);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.cas", "1.0", "ICas", "setPrivateData", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    ::android::hardware::cas::V1_0::Status _hidl_out_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwCas::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_pvtData_parent;

    _hidl_err = _hidl_data.writeBuffer(&pvtData, sizeof(pvtData), &_hidl_pvtData_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_pvtData_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            pvtData,
            &_hidl_data,
            _hidl_pvtData_parent,
            0 /* parentOffset */, &_hidl_pvtData_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(1 /* setPrivateData */, _hidl_data, &_hidl_reply, 0 /* flags */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readUint32((uint32_t *)&_hidl_out_status);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_status);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.cas", "1.0", "ICas", "setPrivateData", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<::android::hardware::cas::V1_0::Status>(_hidl_out_status);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<::android::hardware::cas::V1_0::Status>(_hidl_status);
}

::android::hardware::Return<void> BpHwCas::_hidl_openSession(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, openSession_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::ICas::openSession::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.cas", "1.0", "ICas", "openSession", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwCas::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(2 /* openSession */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::cas::V1_0::Status _hidl_out_status;
        const ::android::hardware::hidl_vec<uint8_t>* _hidl_out_sessionId;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        _hidl_err = _hidl_reply.readUint32((uint32_t *)&_hidl_out_status);
        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_sessionId_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_sessionId), &_hidl__hidl_out_sessionId_parent,  reinterpret_cast<const void **>(&_hidl_out_sessionId));

        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_sessionId_child;

        _hidl_err = ::android::hardware::readEmbeddedFromParcel(
                const_cast<::android::hardware::hidl_vec<uint8_t> &>(*_hidl_out_sessionId),
                _hidl_reply,
                _hidl__hidl_out_sessionId_parent,
                0 /* parentOffset */, &_hidl__hidl_out_sessionId_child);

        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(_hidl_out_status, *_hidl_out_sessionId);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)_hidl_out_sessionId);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.cas", "1.0", "ICas", "openSession", &_hidl_args);
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

::android::hardware::Return<::android::hardware::cas::V1_0::Status> BpHwCas::_hidl_closeSession(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::hidl_vec<uint8_t>& sessionId) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::ICas::closeSession::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&sessionId);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.cas", "1.0", "ICas", "closeSession", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    ::android::hardware::cas::V1_0::Status _hidl_out_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwCas::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_sessionId_parent;

    _hidl_err = _hidl_data.writeBuffer(&sessionId, sizeof(sessionId), &_hidl_sessionId_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_sessionId_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            sessionId,
            &_hidl_data,
            _hidl_sessionId_parent,
            0 /* parentOffset */, &_hidl_sessionId_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(3 /* closeSession */, _hidl_data, &_hidl_reply, 0 /* flags */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readUint32((uint32_t *)&_hidl_out_status);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_status);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.cas", "1.0", "ICas", "closeSession", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<::android::hardware::cas::V1_0::Status>(_hidl_out_status);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<::android::hardware::cas::V1_0::Status>(_hidl_status);
}

::android::hardware::Return<::android::hardware::cas::V1_0::Status> BpHwCas::_hidl_setSessionPrivateData(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::hidl_vec<uint8_t>& sessionId, const ::android::hardware::hidl_vec<uint8_t>& pvtData) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::ICas::setSessionPrivateData::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&sessionId);
        _hidl_args.push_back((void *)&pvtData);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.cas", "1.0", "ICas", "setSessionPrivateData", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    ::android::hardware::cas::V1_0::Status _hidl_out_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwCas::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_sessionId_parent;

    _hidl_err = _hidl_data.writeBuffer(&sessionId, sizeof(sessionId), &_hidl_sessionId_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_sessionId_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            sessionId,
            &_hidl_data,
            _hidl_sessionId_parent,
            0 /* parentOffset */, &_hidl_sessionId_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_pvtData_parent;

    _hidl_err = _hidl_data.writeBuffer(&pvtData, sizeof(pvtData), &_hidl_pvtData_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_pvtData_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            pvtData,
            &_hidl_data,
            _hidl_pvtData_parent,
            0 /* parentOffset */, &_hidl_pvtData_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(4 /* setSessionPrivateData */, _hidl_data, &_hidl_reply, 0 /* flags */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readUint32((uint32_t *)&_hidl_out_status);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_status);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.cas", "1.0", "ICas", "setSessionPrivateData", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<::android::hardware::cas::V1_0::Status>(_hidl_out_status);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<::android::hardware::cas::V1_0::Status>(_hidl_status);
}

::android::hardware::Return<::android::hardware::cas::V1_0::Status> BpHwCas::_hidl_processEcm(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::hidl_vec<uint8_t>& sessionId, const ::android::hardware::hidl_vec<uint8_t>& ecm) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::ICas::processEcm::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&sessionId);
        _hidl_args.push_back((void *)&ecm);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.cas", "1.0", "ICas", "processEcm", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    ::android::hardware::cas::V1_0::Status _hidl_out_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwCas::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_sessionId_parent;

    _hidl_err = _hidl_data.writeBuffer(&sessionId, sizeof(sessionId), &_hidl_sessionId_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_sessionId_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            sessionId,
            &_hidl_data,
            _hidl_sessionId_parent,
            0 /* parentOffset */, &_hidl_sessionId_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_ecm_parent;

    _hidl_err = _hidl_data.writeBuffer(&ecm, sizeof(ecm), &_hidl_ecm_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_ecm_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            ecm,
            &_hidl_data,
            _hidl_ecm_parent,
            0 /* parentOffset */, &_hidl_ecm_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(5 /* processEcm */, _hidl_data, &_hidl_reply, 0 /* flags */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readUint32((uint32_t *)&_hidl_out_status);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_status);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.cas", "1.0", "ICas", "processEcm", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<::android::hardware::cas::V1_0::Status>(_hidl_out_status);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<::android::hardware::cas::V1_0::Status>(_hidl_status);
}

::android::hardware::Return<::android::hardware::cas::V1_0::Status> BpHwCas::_hidl_processEmm(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::hidl_vec<uint8_t>& emm) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::ICas::processEmm::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&emm);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.cas", "1.0", "ICas", "processEmm", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    ::android::hardware::cas::V1_0::Status _hidl_out_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwCas::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_emm_parent;

    _hidl_err = _hidl_data.writeBuffer(&emm, sizeof(emm), &_hidl_emm_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_emm_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            emm,
            &_hidl_data,
            _hidl_emm_parent,
            0 /* parentOffset */, &_hidl_emm_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(6 /* processEmm */, _hidl_data, &_hidl_reply, 0 /* flags */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readUint32((uint32_t *)&_hidl_out_status);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_status);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.cas", "1.0", "ICas", "processEmm", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<::android::hardware::cas::V1_0::Status>(_hidl_out_status);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<::android::hardware::cas::V1_0::Status>(_hidl_status);
}

::android::hardware::Return<::android::hardware::cas::V1_0::Status> BpHwCas::_hidl_sendEvent(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, int32_t event, int32_t arg, const ::android::hardware::hidl_vec<uint8_t>& eventData) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::ICas::sendEvent::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&event);
        _hidl_args.push_back((void *)&arg);
        _hidl_args.push_back((void *)&eventData);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.cas", "1.0", "ICas", "sendEvent", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    ::android::hardware::cas::V1_0::Status _hidl_out_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwCas::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32(event);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32(arg);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_eventData_parent;

    _hidl_err = _hidl_data.writeBuffer(&eventData, sizeof(eventData), &_hidl_eventData_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_eventData_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            eventData,
            &_hidl_data,
            _hidl_eventData_parent,
            0 /* parentOffset */, &_hidl_eventData_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(7 /* sendEvent */, _hidl_data, &_hidl_reply, 0 /* flags */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readUint32((uint32_t *)&_hidl_out_status);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_status);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.cas", "1.0", "ICas", "sendEvent", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<::android::hardware::cas::V1_0::Status>(_hidl_out_status);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<::android::hardware::cas::V1_0::Status>(_hidl_status);
}

::android::hardware::Return<::android::hardware::cas::V1_0::Status> BpHwCas::_hidl_provision(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::hidl_string& provisionString) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::ICas::provision::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&provisionString);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.cas", "1.0", "ICas", "provision", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    ::android::hardware::cas::V1_0::Status _hidl_out_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwCas::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_provisionString_parent;

    _hidl_err = _hidl_data.writeBuffer(&provisionString, sizeof(provisionString), &_hidl_provisionString_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            provisionString,
            &_hidl_data,
            _hidl_provisionString_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(8 /* provision */, _hidl_data, &_hidl_reply, 0 /* flags */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readUint32((uint32_t *)&_hidl_out_status);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_status);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.cas", "1.0", "ICas", "provision", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<::android::hardware::cas::V1_0::Status>(_hidl_out_status);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<::android::hardware::cas::V1_0::Status>(_hidl_status);
}

::android::hardware::Return<::android::hardware::cas::V1_0::Status> BpHwCas::_hidl_refreshEntitlements(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, int32_t refreshType, const ::android::hardware::hidl_vec<uint8_t>& refreshData) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::ICas::refreshEntitlements::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&refreshType);
        _hidl_args.push_back((void *)&refreshData);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.cas", "1.0", "ICas", "refreshEntitlements", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    ::android::hardware::cas::V1_0::Status _hidl_out_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwCas::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32(refreshType);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_refreshData_parent;

    _hidl_err = _hidl_data.writeBuffer(&refreshData, sizeof(refreshData), &_hidl_refreshData_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_refreshData_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            refreshData,
            &_hidl_data,
            _hidl_refreshData_parent,
            0 /* parentOffset */, &_hidl_refreshData_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(9 /* refreshEntitlements */, _hidl_data, &_hidl_reply, 0 /* flags */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readUint32((uint32_t *)&_hidl_out_status);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_status);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.cas", "1.0", "ICas", "refreshEntitlements", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<::android::hardware::cas::V1_0::Status>(_hidl_out_status);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<::android::hardware::cas::V1_0::Status>(_hidl_status);
}

::android::hardware::Return<::android::hardware::cas::V1_0::Status> BpHwCas::_hidl_release(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::ICas::release::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.cas", "1.0", "ICas", "release", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    ::android::hardware::cas::V1_0::Status _hidl_out_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwCas::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(10 /* release */, _hidl_data, &_hidl_reply, 0 /* flags */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readUint32((uint32_t *)&_hidl_out_status);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_status);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.cas", "1.0", "ICas", "release", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<::android::hardware::cas::V1_0::Status>(_hidl_out_status);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<::android::hardware::cas::V1_0::Status>(_hidl_status);
}


// Methods from ::android::hardware::cas::V1_0::ICas follow.
::android::hardware::Return<::android::hardware::cas::V1_0::Status> BpHwCas::setPrivateData(const ::android::hardware::hidl_vec<uint8_t>& pvtData){
    ::android::hardware::Return<::android::hardware::cas::V1_0::Status>  _hidl_out = ::android::hardware::cas::V1_0::BpHwCas::_hidl_setPrivateData(this, this, pvtData);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwCas::openSession(openSession_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::cas::V1_0::BpHwCas::_hidl_openSession(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<::android::hardware::cas::V1_0::Status> BpHwCas::closeSession(const ::android::hardware::hidl_vec<uint8_t>& sessionId){
    ::android::hardware::Return<::android::hardware::cas::V1_0::Status>  _hidl_out = ::android::hardware::cas::V1_0::BpHwCas::_hidl_closeSession(this, this, sessionId);

    return _hidl_out;
}

::android::hardware::Return<::android::hardware::cas::V1_0::Status> BpHwCas::setSessionPrivateData(const ::android::hardware::hidl_vec<uint8_t>& sessionId, const ::android::hardware::hidl_vec<uint8_t>& pvtData){
    ::android::hardware::Return<::android::hardware::cas::V1_0::Status>  _hidl_out = ::android::hardware::cas::V1_0::BpHwCas::_hidl_setSessionPrivateData(this, this, sessionId, pvtData);

    return _hidl_out;
}

::android::hardware::Return<::android::hardware::cas::V1_0::Status> BpHwCas::processEcm(const ::android::hardware::hidl_vec<uint8_t>& sessionId, const ::android::hardware::hidl_vec<uint8_t>& ecm){
    ::android::hardware::Return<::android::hardware::cas::V1_0::Status>  _hidl_out = ::android::hardware::cas::V1_0::BpHwCas::_hidl_processEcm(this, this, sessionId, ecm);

    return _hidl_out;
}

::android::hardware::Return<::android::hardware::cas::V1_0::Status> BpHwCas::processEmm(const ::android::hardware::hidl_vec<uint8_t>& emm){
    ::android::hardware::Return<::android::hardware::cas::V1_0::Status>  _hidl_out = ::android::hardware::cas::V1_0::BpHwCas::_hidl_processEmm(this, this, emm);

    return _hidl_out;
}

::android::hardware::Return<::android::hardware::cas::V1_0::Status> BpHwCas::sendEvent(int32_t event, int32_t arg, const ::android::hardware::hidl_vec<uint8_t>& eventData){
    ::android::hardware::Return<::android::hardware::cas::V1_0::Status>  _hidl_out = ::android::hardware::cas::V1_0::BpHwCas::_hidl_sendEvent(this, this, event, arg, eventData);

    return _hidl_out;
}

::android::hardware::Return<::android::hardware::cas::V1_0::Status> BpHwCas::provision(const ::android::hardware::hidl_string& provisionString){
    ::android::hardware::Return<::android::hardware::cas::V1_0::Status>  _hidl_out = ::android::hardware::cas::V1_0::BpHwCas::_hidl_provision(this, this, provisionString);

    return _hidl_out;
}

::android::hardware::Return<::android::hardware::cas::V1_0::Status> BpHwCas::refreshEntitlements(int32_t refreshType, const ::android::hardware::hidl_vec<uint8_t>& refreshData){
    ::android::hardware::Return<::android::hardware::cas::V1_0::Status>  _hidl_out = ::android::hardware::cas::V1_0::BpHwCas::_hidl_refreshEntitlements(this, this, refreshType, refreshData);

    return _hidl_out;
}

::android::hardware::Return<::android::hardware::cas::V1_0::Status> BpHwCas::release(){
    ::android::hardware::Return<::android::hardware::cas::V1_0::Status>  _hidl_out = ::android::hardware::cas::V1_0::BpHwCas::_hidl_release(this, this);

    return _hidl_out;
}


// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BpHwCas::interfaceChain(interfaceChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwCas::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_debug(this, this, fd, options);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwCas::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceDescriptor(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwCas::getHashChain(getHashChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getHashChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwCas::setHALInstrumentation(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_setHALInstrumentation(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwCas::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    ::android::hardware::ProcessState::self()->startThreadPool();
    ::android::hardware::hidl_binder_death_recipient *binder_recipient = new ::android::hardware::hidl_binder_death_recipient(recipient, cookie, this);
    std::unique_lock<std::mutex> lock(_hidl_mMutex);
    _hidl_mDeathRecipients.push_back(binder_recipient);
    return (remote()->linkToDeath(binder_recipient) == ::android::OK);
}

::android::hardware::Return<void> BpHwCas::ping(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_ping(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwCas::getDebugInfo(getDebugInfo_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getDebugInfo(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwCas::notifySyspropsChanged(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_notifySyspropsChanged(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwCas::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
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


BnHwCas::BnHwCas(const ::android::sp<ICas> &_hidl_impl)
        : ::android::hidl::base::V1_0::BnHwBase(_hidl_impl, "android.hardware.cas@1.0", "ICas") { 
            _hidl_mImpl = _hidl_impl;
            auto prio = ::android::hardware::getMinSchedulerPolicy(_hidl_impl);
            mSchedPolicy = prio.sched_policy;
            mSchedPriority = prio.prio;
            setRequestingSid(::android::hardware::getRequestingSid(_hidl_impl));
}

BnHwCas::~BnHwCas() {
    ::android::hardware::details::gBnMap->eraseIfEqual(_hidl_mImpl.get(), this);
}

// Methods from ::android::hardware::cas::V1_0::ICas follow.
::android::status_t BnHwCas::_hidl_setPrivateData(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwCas::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    const ::android::hardware::hidl_vec<uint8_t>* pvtData;

    size_t _hidl_pvtData_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*pvtData), &_hidl_pvtData_parent,  reinterpret_cast<const void **>(&pvtData));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_pvtData_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(*pvtData),
            _hidl_data,
            _hidl_pvtData_parent,
            0 /* parentOffset */, &_hidl_pvtData_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::ICas::setPrivateData::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)pvtData);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.cas", "1.0", "ICas", "setPrivateData", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::cas::V1_0::Status _hidl_out_status = static_cast<ICas*>(_hidl_this->getImpl().get())->setPrivateData(*pvtData);

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeUint32((uint32_t)_hidl_out_status);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

_hidl_error:
    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_status);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.cas", "1.0", "ICas", "setPrivateData", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwCas::_hidl_openSession(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwCas::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::ICas::openSession::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.cas", "1.0", "ICas", "openSession", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<ICas*>(_hidl_this->getImpl().get())->openSession([&](const auto &_hidl_out_status, const auto &_hidl_out_sessionId) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("openSession: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeUint32((uint32_t)_hidl_out_status);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_sessionId_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_sessionId, sizeof(_hidl_out_sessionId), &_hidl__hidl_out_sessionId_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_sessionId_child;

        _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                _hidl_out_sessionId,
                _hidl_reply,
                _hidl__hidl_out_sessionId_parent,
                0 /* parentOffset */, &_hidl__hidl_out_sessionId_child);

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)&_hidl_out_sessionId);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.cas", "1.0", "ICas", "openSession", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("openSession: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwCas::_hidl_closeSession(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwCas::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    const ::android::hardware::hidl_vec<uint8_t>* sessionId;

    size_t _hidl_sessionId_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*sessionId), &_hidl_sessionId_parent,  reinterpret_cast<const void **>(&sessionId));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_sessionId_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(*sessionId),
            _hidl_data,
            _hidl_sessionId_parent,
            0 /* parentOffset */, &_hidl_sessionId_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::ICas::closeSession::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)sessionId);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.cas", "1.0", "ICas", "closeSession", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::cas::V1_0::Status _hidl_out_status = static_cast<ICas*>(_hidl_this->getImpl().get())->closeSession(*sessionId);

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeUint32((uint32_t)_hidl_out_status);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

_hidl_error:
    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_status);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.cas", "1.0", "ICas", "closeSession", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwCas::_hidl_setSessionPrivateData(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwCas::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    const ::android::hardware::hidl_vec<uint8_t>* sessionId;
    const ::android::hardware::hidl_vec<uint8_t>* pvtData;

    size_t _hidl_sessionId_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*sessionId), &_hidl_sessionId_parent,  reinterpret_cast<const void **>(&sessionId));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_sessionId_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(*sessionId),
            _hidl_data,
            _hidl_sessionId_parent,
            0 /* parentOffset */, &_hidl_sessionId_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_pvtData_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*pvtData), &_hidl_pvtData_parent,  reinterpret_cast<const void **>(&pvtData));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_pvtData_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(*pvtData),
            _hidl_data,
            _hidl_pvtData_parent,
            0 /* parentOffset */, &_hidl_pvtData_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::ICas::setSessionPrivateData::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)sessionId);
        _hidl_args.push_back((void *)pvtData);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.cas", "1.0", "ICas", "setSessionPrivateData", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::cas::V1_0::Status _hidl_out_status = static_cast<ICas*>(_hidl_this->getImpl().get())->setSessionPrivateData(*sessionId, *pvtData);

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeUint32((uint32_t)_hidl_out_status);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

_hidl_error:
    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_status);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.cas", "1.0", "ICas", "setSessionPrivateData", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwCas::_hidl_processEcm(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwCas::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    const ::android::hardware::hidl_vec<uint8_t>* sessionId;
    const ::android::hardware::hidl_vec<uint8_t>* ecm;

    size_t _hidl_sessionId_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*sessionId), &_hidl_sessionId_parent,  reinterpret_cast<const void **>(&sessionId));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_sessionId_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(*sessionId),
            _hidl_data,
            _hidl_sessionId_parent,
            0 /* parentOffset */, &_hidl_sessionId_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_ecm_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*ecm), &_hidl_ecm_parent,  reinterpret_cast<const void **>(&ecm));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_ecm_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(*ecm),
            _hidl_data,
            _hidl_ecm_parent,
            0 /* parentOffset */, &_hidl_ecm_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::ICas::processEcm::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)sessionId);
        _hidl_args.push_back((void *)ecm);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.cas", "1.0", "ICas", "processEcm", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::cas::V1_0::Status _hidl_out_status = static_cast<ICas*>(_hidl_this->getImpl().get())->processEcm(*sessionId, *ecm);

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeUint32((uint32_t)_hidl_out_status);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

_hidl_error:
    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_status);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.cas", "1.0", "ICas", "processEcm", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwCas::_hidl_processEmm(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwCas::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    const ::android::hardware::hidl_vec<uint8_t>* emm;

    size_t _hidl_emm_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*emm), &_hidl_emm_parent,  reinterpret_cast<const void **>(&emm));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_emm_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(*emm),
            _hidl_data,
            _hidl_emm_parent,
            0 /* parentOffset */, &_hidl_emm_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::ICas::processEmm::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)emm);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.cas", "1.0", "ICas", "processEmm", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::cas::V1_0::Status _hidl_out_status = static_cast<ICas*>(_hidl_this->getImpl().get())->processEmm(*emm);

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeUint32((uint32_t)_hidl_out_status);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

_hidl_error:
    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_status);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.cas", "1.0", "ICas", "processEmm", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwCas::_hidl_sendEvent(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwCas::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    int32_t event;
    int32_t arg;
    const ::android::hardware::hidl_vec<uint8_t>* eventData;

    _hidl_err = _hidl_data.readInt32(&event);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readInt32(&arg);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_eventData_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*eventData), &_hidl_eventData_parent,  reinterpret_cast<const void **>(&eventData));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_eventData_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(*eventData),
            _hidl_data,
            _hidl_eventData_parent,
            0 /* parentOffset */, &_hidl_eventData_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::ICas::sendEvent::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&event);
        _hidl_args.push_back((void *)&arg);
        _hidl_args.push_back((void *)eventData);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.cas", "1.0", "ICas", "sendEvent", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::cas::V1_0::Status _hidl_out_status = static_cast<ICas*>(_hidl_this->getImpl().get())->sendEvent(event, arg, *eventData);

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeUint32((uint32_t)_hidl_out_status);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

_hidl_error:
    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_status);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.cas", "1.0", "ICas", "sendEvent", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwCas::_hidl_provision(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwCas::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    const ::android::hardware::hidl_string* provisionString;

    size_t _hidl_provisionString_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*provisionString), &_hidl_provisionString_parent,  reinterpret_cast<const void **>(&provisionString));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(*provisionString),
            _hidl_data,
            _hidl_provisionString_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::ICas::provision::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)provisionString);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.cas", "1.0", "ICas", "provision", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::cas::V1_0::Status _hidl_out_status = static_cast<ICas*>(_hidl_this->getImpl().get())->provision(*provisionString);

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeUint32((uint32_t)_hidl_out_status);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

_hidl_error:
    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_status);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.cas", "1.0", "ICas", "provision", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwCas::_hidl_refreshEntitlements(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwCas::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    int32_t refreshType;
    const ::android::hardware::hidl_vec<uint8_t>* refreshData;

    _hidl_err = _hidl_data.readInt32(&refreshType);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_refreshData_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*refreshData), &_hidl_refreshData_parent,  reinterpret_cast<const void **>(&refreshData));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_refreshData_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(*refreshData),
            _hidl_data,
            _hidl_refreshData_parent,
            0 /* parentOffset */, &_hidl_refreshData_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::ICas::refreshEntitlements::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&refreshType);
        _hidl_args.push_back((void *)refreshData);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.cas", "1.0", "ICas", "refreshEntitlements", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::cas::V1_0::Status _hidl_out_status = static_cast<ICas*>(_hidl_this->getImpl().get())->refreshEntitlements(refreshType, *refreshData);

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeUint32((uint32_t)_hidl_out_status);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

_hidl_error:
    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_status);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.cas", "1.0", "ICas", "refreshEntitlements", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwCas::_hidl_release(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwCas::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::ICas::release::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.cas", "1.0", "ICas", "release", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::cas::V1_0::Status _hidl_out_status = static_cast<ICas*>(_hidl_this->getImpl().get())->release();

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeUint32((uint32_t)_hidl_out_status);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

_hidl_error:
    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_status);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.cas", "1.0", "ICas", "release", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}


// Methods from ::android::hardware::cas::V1_0::ICas follow.

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BnHwCas::ping() {
    return ::android::hardware::Void();
}
::android::hardware::Return<void> BnHwCas::getDebugInfo(getDebugInfo_cb _hidl_cb) {
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

::android::status_t BnHwCas::onTransact(
        uint32_t _hidl_code,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        uint32_t _hidl_flags,
        TransactCallback _hidl_cb) {
    ::android::status_t _hidl_err = ::android::OK;

    switch (_hidl_code) {
        case 1 /* setPrivateData */:
        {
            _hidl_err = ::android::hardware::cas::V1_0::BnHwCas::_hidl_setPrivateData(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 2 /* openSession */:
        {
            _hidl_err = ::android::hardware::cas::V1_0::BnHwCas::_hidl_openSession(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 3 /* closeSession */:
        {
            _hidl_err = ::android::hardware::cas::V1_0::BnHwCas::_hidl_closeSession(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 4 /* setSessionPrivateData */:
        {
            _hidl_err = ::android::hardware::cas::V1_0::BnHwCas::_hidl_setSessionPrivateData(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 5 /* processEcm */:
        {
            _hidl_err = ::android::hardware::cas::V1_0::BnHwCas::_hidl_processEcm(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 6 /* processEmm */:
        {
            _hidl_err = ::android::hardware::cas::V1_0::BnHwCas::_hidl_processEmm(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 7 /* sendEvent */:
        {
            _hidl_err = ::android::hardware::cas::V1_0::BnHwCas::_hidl_sendEvent(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 8 /* provision */:
        {
            _hidl_err = ::android::hardware::cas::V1_0::BnHwCas::_hidl_provision(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 9 /* refreshEntitlements */:
        {
            _hidl_err = ::android::hardware::cas::V1_0::BnHwCas::_hidl_refreshEntitlements(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 10 /* release */:
        {
            _hidl_err = ::android::hardware::cas::V1_0::BnHwCas::_hidl_release(this, _hidl_data, _hidl_reply, _hidl_cb);
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

BsCas::BsCas(const ::android::sp<::android::hardware::cas::V1_0::ICas> impl) : ::android::hardware::details::HidlInstrumentor("android.hardware.cas@1.0", "ICas"), mImpl(impl) {
    mOnewayQueue.start(3000 /* similar limit to binderized */);
}

::android::hardware::Return<void> BsCas::addOnewayTask(std::function<void(void)> fun) {
    if (!mOnewayQueue.push(fun)) {
        return ::android::hardware::Status::fromExceptionCode(
                ::android::hardware::Status::EX_TRANSACTION_FAILED,
                "Passthrough oneway function queue exceeds maximum size.");
    }
    return ::android::hardware::Status();
}

::android::sp<ICas> ICas::tryGetService(const std::string &serviceName, const bool getStub) {
    return ::android::hardware::details::getServiceInternal<BpHwCas>(serviceName, false, getStub);
}

::android::sp<ICas> ICas::getService(const std::string &serviceName, const bool getStub) {
    return ::android::hardware::details::getServiceInternal<BpHwCas>(serviceName, true, getStub);
}

::android::status_t ICas::registerAsService(const std::string &serviceName) {
    return ::android::hardware::details::registerAsServiceInternal(this, serviceName);
}

bool ICas::registerForNotifications(
        const std::string &serviceName,
        const ::android::sp<::android::hidl::manager::V1_0::IServiceNotification> &notification) {
    const ::android::sp<::android::hidl::manager::V1_0::IServiceManager> sm
            = ::android::hardware::defaultServiceManager();
    if (sm == nullptr) {
        return false;
    }
    ::android::hardware::Return<bool> success =
            sm->registerForNotifications("android.hardware.cas@1.0::ICas",
                    serviceName, notification);
    return success.isOk() && success;
}

static_assert(sizeof(::android::hardware::MQDescriptor<char, ::android::hardware::kSynchronizedReadWrite>) == 32, "wrong size");
static_assert(sizeof(::android::hardware::hidl_handle) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_memory) == 40, "wrong size");
static_assert(sizeof(::android::hardware::hidl_string) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_vec<char>) == 16, "wrong size");

}  // namespace V1_0
}  // namespace cas
}  // namespace hardware
}  // namespace android
