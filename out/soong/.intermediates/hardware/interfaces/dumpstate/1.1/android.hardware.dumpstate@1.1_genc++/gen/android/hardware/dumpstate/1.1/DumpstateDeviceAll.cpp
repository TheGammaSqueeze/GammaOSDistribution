#define LOG_TAG "android.hardware.dumpstate@1.1::DumpstateDevice"

#include <log/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <hidl/Static.h>
#include <hwbinder/ProcessState.h>
#include <utils/Trace.h>
#include <android/hidl/manager/1.0/IServiceManager.h>
#include <android/hardware/dumpstate/1.1/BpHwDumpstateDevice.h>
#include <android/hardware/dumpstate/1.1/BnHwDumpstateDevice.h>
#include <android/hardware/dumpstate/1.1/BsDumpstateDevice.h>
#include <android/hardware/dumpstate/1.0/BpHwDumpstateDevice.h>
#include <android/hidl/base/1.0/BpHwBase.h>
#include <hidl/ServiceManagement.h>

namespace android {
namespace hardware {
namespace dumpstate {
namespace V1_1 {

const char* IDumpstateDevice::descriptor("android.hardware.dumpstate@1.1::IDumpstateDevice");

__attribute__((constructor)) static void static_constructor() {
    ::android::hardware::details::getBnConstructorMap().set(IDumpstateDevice::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hardware::IBinder> {
                return new BnHwDumpstateDevice(static_cast<IDumpstateDevice *>(iIntf));
            });
    ::android::hardware::details::getBsConstructorMap().set(IDumpstateDevice::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hidl::base::V1_0::IBase> {
                return new BsDumpstateDevice(static_cast<IDumpstateDevice *>(iIntf));
            });
}

__attribute__((destructor))static void static_destructor() {
    ::android::hardware::details::getBnConstructorMap().erase(IDumpstateDevice::descriptor);
    ::android::hardware::details::getBsConstructorMap().erase(IDumpstateDevice::descriptor);
}

// Methods from ::android::hardware::dumpstate::V1_0::IDumpstateDevice follow.
// no default implementation for: ::android::hardware::Return<void> IDumpstateDevice::dumpstateBoard(const ::android::hardware::hidl_handle& h)

// Methods from ::android::hardware::dumpstate::V1_1::IDumpstateDevice follow.
// no default implementation for: ::android::hardware::Return<::android::hardware::dumpstate::V1_1::DumpstateStatus> IDumpstateDevice::dumpstateBoard_1_1(const ::android::hardware::hidl_handle& h, ::android::hardware::dumpstate::V1_1::DumpstateMode mode, uint64_t timeoutMillis)
// no default implementation for: ::android::hardware::Return<void> IDumpstateDevice::setVerboseLoggingEnabled(bool enable)
// no default implementation for: ::android::hardware::Return<bool> IDumpstateDevice::getVerboseLoggingEnabled()

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> IDumpstateDevice::interfaceChain(interfaceChain_cb _hidl_cb){
    _hidl_cb({
        ::android::hardware::dumpstate::V1_1::IDumpstateDevice::descriptor,
        ::android::hardware::dumpstate::V1_0::IDumpstateDevice::descriptor,
        ::android::hidl::base::V1_0::IBase::descriptor,
    });
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IDumpstateDevice::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    (void)fd;
    (void)options;
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IDumpstateDevice::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    _hidl_cb(::android::hardware::dumpstate::V1_1::IDumpstateDevice::descriptor);
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IDumpstateDevice::getHashChain(getHashChain_cb _hidl_cb){
    _hidl_cb({
        (uint8_t[32]){24,107,193,82,174,24,154,180,143,58,118,26,68,221,245,237,208,212,131,7,60,91,108,161,248,2,248,181,4,136,183,84} /* 186bc152ae189ab48f3a761a44ddf5edd0d483073c5b6ca1f802f8b50488b754 */,
        (uint8_t[32]){118,4,133,35,47,108,206,7,248,187,5,227,71,85,9,149,105,150,183,2,247,116,21,238,91,255,5,226,236,90,91,204} /* 760485232f6cce07f8bb05e3475509956996b702f77415ee5bff05e2ec5a5bcc */,
        (uint8_t[32]){236,127,215,158,208,45,250,133,188,73,148,38,173,174,62,190,35,239,5,36,243,205,105,87,19,147,36,184,59,24,202,76} /* ec7fd79ed02dfa85bc499426adae3ebe23ef0524f3cd6957139324b83b18ca4c */});
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IDumpstateDevice::setHALInstrumentation(){
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> IDumpstateDevice::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    (void)cookie;
    return (recipient != nullptr);
}

::android::hardware::Return<void> IDumpstateDevice::ping(){
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IDumpstateDevice::getDebugInfo(getDebugInfo_cb _hidl_cb){
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

::android::hardware::Return<void> IDumpstateDevice::notifySyspropsChanged(){
    ::android::report_sysprop_change();
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> IDumpstateDevice::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
    return (recipient != nullptr);
}


::android::hardware::Return<::android::sp<::android::hardware::dumpstate::V1_1::IDumpstateDevice>> IDumpstateDevice::castFrom(const ::android::sp<::android::hardware::dumpstate::V1_1::IDumpstateDevice>& parent, bool /* emitError */) {
    return parent;
}

::android::hardware::Return<::android::sp<::android::hardware::dumpstate::V1_1::IDumpstateDevice>> IDumpstateDevice::castFrom(const ::android::sp<::android::hardware::dumpstate::V1_0::IDumpstateDevice>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<IDumpstateDevice, ::android::hardware::dumpstate::V1_0::IDumpstateDevice, BpHwDumpstateDevice>(
            parent, "android.hardware.dumpstate@1.1::IDumpstateDevice", emitError);
}

::android::hardware::Return<::android::sp<::android::hardware::dumpstate::V1_1::IDumpstateDevice>> IDumpstateDevice::castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<IDumpstateDevice, ::android::hidl::base::V1_0::IBase, BpHwDumpstateDevice>(
            parent, "android.hardware.dumpstate@1.1::IDumpstateDevice", emitError);
}

BpHwDumpstateDevice::BpHwDumpstateDevice(const ::android::sp<::android::hardware::IBinder> &_hidl_impl)
        : BpInterface<IDumpstateDevice>(_hidl_impl),
          ::android::hardware::details::HidlInstrumentor("android.hardware.dumpstate@1.1", "IDumpstateDevice") {
}

void BpHwDumpstateDevice::onLastStrongRef(const void* id) {
    {
        std::unique_lock<std::mutex> lock(_hidl_mMutex);
        _hidl_mDeathRecipients.clear();
    }

    BpInterface<IDumpstateDevice>::onLastStrongRef(id);
}
// Methods from ::android::hardware::dumpstate::V1_1::IDumpstateDevice follow.
::android::hardware::Return<::android::hardware::dumpstate::V1_1::DumpstateStatus> BpHwDumpstateDevice::_hidl_dumpstateBoard_1_1(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::hidl_handle& h, ::android::hardware::dumpstate::V1_1::DumpstateMode mode, uint64_t timeoutMillis) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IDumpstateDevice::dumpstateBoard_1_1::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&h);
        _hidl_args.push_back((void *)&mode);
        _hidl_args.push_back((void *)&timeoutMillis);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.dumpstate", "1.1", "IDumpstateDevice", "dumpstateBoard_1_1", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    ::android::hardware::dumpstate::V1_1::DumpstateStatus _hidl_out_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwDumpstateDevice::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeNativeHandleNoDup(h);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32((uint32_t)mode);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(timeoutMillis);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(2 /* dumpstateBoard_1_1 */, _hidl_data, &_hidl_reply, 0 /* flags */);
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
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.dumpstate", "1.1", "IDumpstateDevice", "dumpstateBoard_1_1", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<::android::hardware::dumpstate::V1_1::DumpstateStatus>(_hidl_out_status);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<::android::hardware::dumpstate::V1_1::DumpstateStatus>(_hidl_status);
}

::android::hardware::Return<void> BpHwDumpstateDevice::_hidl_setVerboseLoggingEnabled(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, bool enable) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IDumpstateDevice::setVerboseLoggingEnabled::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&enable);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.dumpstate", "1.1", "IDumpstateDevice", "setVerboseLoggingEnabled", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwDumpstateDevice::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeBool(enable);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(3 /* setVerboseLoggingEnabled */, _hidl_data, &_hidl_reply, 0 /* flags */);
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
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.dumpstate", "1.1", "IDumpstateDevice", "setVerboseLoggingEnabled", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}

::android::hardware::Return<bool> BpHwDumpstateDevice::_hidl_getVerboseLoggingEnabled(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IDumpstateDevice::getVerboseLoggingEnabled::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.dumpstate", "1.1", "IDumpstateDevice", "getVerboseLoggingEnabled", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    bool _hidl_out_enabled;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwDumpstateDevice::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(4 /* getVerboseLoggingEnabled */, _hidl_data, &_hidl_reply, 0 /* flags */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readBool(&_hidl_out_enabled);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_enabled);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.dumpstate", "1.1", "IDumpstateDevice", "getVerboseLoggingEnabled", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<bool>(_hidl_out_enabled);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<bool>(_hidl_status);
}


// Methods from ::android::hardware::dumpstate::V1_0::IDumpstateDevice follow.
::android::hardware::Return<void> BpHwDumpstateDevice::dumpstateBoard(const ::android::hardware::hidl_handle& h){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::dumpstate::V1_0::BpHwDumpstateDevice::_hidl_dumpstateBoard(this, this, h);

    return _hidl_out;
}


// Methods from ::android::hardware::dumpstate::V1_1::IDumpstateDevice follow.
::android::hardware::Return<::android::hardware::dumpstate::V1_1::DumpstateStatus> BpHwDumpstateDevice::dumpstateBoard_1_1(const ::android::hardware::hidl_handle& h, ::android::hardware::dumpstate::V1_1::DumpstateMode mode, uint64_t timeoutMillis){
    ::android::hardware::Return<::android::hardware::dumpstate::V1_1::DumpstateStatus>  _hidl_out = ::android::hardware::dumpstate::V1_1::BpHwDumpstateDevice::_hidl_dumpstateBoard_1_1(this, this, h, mode, timeoutMillis);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwDumpstateDevice::setVerboseLoggingEnabled(bool enable){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::dumpstate::V1_1::BpHwDumpstateDevice::_hidl_setVerboseLoggingEnabled(this, this, enable);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwDumpstateDevice::getVerboseLoggingEnabled(){
    ::android::hardware::Return<bool>  _hidl_out = ::android::hardware::dumpstate::V1_1::BpHwDumpstateDevice::_hidl_getVerboseLoggingEnabled(this, this);

    return _hidl_out;
}


// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BpHwDumpstateDevice::interfaceChain(interfaceChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwDumpstateDevice::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_debug(this, this, fd, options);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwDumpstateDevice::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceDescriptor(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwDumpstateDevice::getHashChain(getHashChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getHashChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwDumpstateDevice::setHALInstrumentation(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_setHALInstrumentation(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwDumpstateDevice::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    ::android::hardware::ProcessState::self()->startThreadPool();
    ::android::hardware::hidl_binder_death_recipient *binder_recipient = new ::android::hardware::hidl_binder_death_recipient(recipient, cookie, this);
    std::unique_lock<std::mutex> lock(_hidl_mMutex);
    _hidl_mDeathRecipients.push_back(binder_recipient);
    return (remote()->linkToDeath(binder_recipient) == ::android::OK);
}

::android::hardware::Return<void> BpHwDumpstateDevice::ping(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_ping(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwDumpstateDevice::getDebugInfo(getDebugInfo_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getDebugInfo(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwDumpstateDevice::notifySyspropsChanged(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_notifySyspropsChanged(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwDumpstateDevice::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
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


BnHwDumpstateDevice::BnHwDumpstateDevice(const ::android::sp<IDumpstateDevice> &_hidl_impl)
        : ::android::hidl::base::V1_0::BnHwBase(_hidl_impl, "android.hardware.dumpstate@1.1", "IDumpstateDevice") { 
            _hidl_mImpl = _hidl_impl;
            auto prio = ::android::hardware::getMinSchedulerPolicy(_hidl_impl);
            mSchedPolicy = prio.sched_policy;
            mSchedPriority = prio.prio;
            setRequestingSid(::android::hardware::getRequestingSid(_hidl_impl));
}

BnHwDumpstateDevice::~BnHwDumpstateDevice() {
    ::android::hardware::details::gBnMap->eraseIfEqual(_hidl_mImpl.get(), this);
}

// Methods from ::android::hardware::dumpstate::V1_1::IDumpstateDevice follow.
::android::status_t BnHwDumpstateDevice::_hidl_dumpstateBoard_1_1(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwDumpstateDevice::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::hidl_handle h;
    ::android::hardware::dumpstate::V1_1::DumpstateMode mode;
    uint64_t timeoutMillis;

    const native_handle_t *h_ptr;

    _hidl_err = _hidl_data.readNullableNativeHandleNoDup(&h_ptr);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    h = h_ptr;
    _hidl_err = _hidl_data.readUint32((uint32_t *)&mode);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint64(&timeoutMillis);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IDumpstateDevice::dumpstateBoard_1_1::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&h);
        _hidl_args.push_back((void *)&mode);
        _hidl_args.push_back((void *)&timeoutMillis);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.dumpstate", "1.1", "IDumpstateDevice", "dumpstateBoard_1_1", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::dumpstate::V1_1::DumpstateStatus _hidl_out_status = static_cast<IDumpstateDevice*>(_hidl_this->getImpl().get())->dumpstateBoard_1_1(h, mode, timeoutMillis);

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
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.dumpstate", "1.1", "IDumpstateDevice", "dumpstateBoard_1_1", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwDumpstateDevice::_hidl_setVerboseLoggingEnabled(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwDumpstateDevice::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    bool enable;

    _hidl_err = _hidl_data.readBool(&enable);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IDumpstateDevice::setVerboseLoggingEnabled::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&enable);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.dumpstate", "1.1", "IDumpstateDevice", "setVerboseLoggingEnabled", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IDumpstateDevice*>(_hidl_this->getImpl().get())->setVerboseLoggingEnabled(enable);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.dumpstate", "1.1", "IDumpstateDevice", "setVerboseLoggingEnabled", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}

::android::status_t BnHwDumpstateDevice::_hidl_getVerboseLoggingEnabled(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwDumpstateDevice::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IDumpstateDevice::getVerboseLoggingEnabled::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.dumpstate", "1.1", "IDumpstateDevice", "getVerboseLoggingEnabled", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_out_enabled = static_cast<IDumpstateDevice*>(_hidl_this->getImpl().get())->getVerboseLoggingEnabled();

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeBool(_hidl_out_enabled);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

_hidl_error:
    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_enabled);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.dumpstate", "1.1", "IDumpstateDevice", "getVerboseLoggingEnabled", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}


// Methods from ::android::hardware::dumpstate::V1_0::IDumpstateDevice follow.

// Methods from ::android::hardware::dumpstate::V1_1::IDumpstateDevice follow.

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BnHwDumpstateDevice::ping() {
    return ::android::hardware::Void();
}
::android::hardware::Return<void> BnHwDumpstateDevice::getDebugInfo(getDebugInfo_cb _hidl_cb) {
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

::android::status_t BnHwDumpstateDevice::onTransact(
        uint32_t _hidl_code,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        uint32_t _hidl_flags,
        TransactCallback _hidl_cb) {
    ::android::status_t _hidl_err = ::android::OK;

    switch (_hidl_code) {
        case 1 /* dumpstateBoard */:
        {
            _hidl_err = ::android::hardware::dumpstate::V1_0::BnHwDumpstateDevice::_hidl_dumpstateBoard(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 2 /* dumpstateBoard_1_1 */:
        {
            _hidl_err = ::android::hardware::dumpstate::V1_1::BnHwDumpstateDevice::_hidl_dumpstateBoard_1_1(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 3 /* setVerboseLoggingEnabled */:
        {
            _hidl_err = ::android::hardware::dumpstate::V1_1::BnHwDumpstateDevice::_hidl_setVerboseLoggingEnabled(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 4 /* getVerboseLoggingEnabled */:
        {
            _hidl_err = ::android::hardware::dumpstate::V1_1::BnHwDumpstateDevice::_hidl_getVerboseLoggingEnabled(this, _hidl_data, _hidl_reply, _hidl_cb);
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

BsDumpstateDevice::BsDumpstateDevice(const ::android::sp<::android::hardware::dumpstate::V1_1::IDumpstateDevice> impl) : ::android::hardware::details::HidlInstrumentor("android.hardware.dumpstate@1.1", "IDumpstateDevice"), mImpl(impl) {
    mOnewayQueue.start(3000 /* similar limit to binderized */);
}

::android::hardware::Return<void> BsDumpstateDevice::addOnewayTask(std::function<void(void)> fun) {
    if (!mOnewayQueue.push(fun)) {
        return ::android::hardware::Status::fromExceptionCode(
                ::android::hardware::Status::EX_TRANSACTION_FAILED,
                "Passthrough oneway function queue exceeds maximum size.");
    }
    return ::android::hardware::Status();
}

::android::sp<IDumpstateDevice> IDumpstateDevice::tryGetService(const std::string &serviceName, const bool getStub) {
    return ::android::hardware::details::getServiceInternal<BpHwDumpstateDevice>(serviceName, false, getStub);
}

::android::sp<IDumpstateDevice> IDumpstateDevice::getService(const std::string &serviceName, const bool getStub) {
    return ::android::hardware::details::getServiceInternal<BpHwDumpstateDevice>(serviceName, true, getStub);
}

::android::status_t IDumpstateDevice::registerAsService(const std::string &serviceName) {
    return ::android::hardware::details::registerAsServiceInternal(this, serviceName);
}

bool IDumpstateDevice::registerForNotifications(
        const std::string &serviceName,
        const ::android::sp<::android::hidl::manager::V1_0::IServiceNotification> &notification) {
    const ::android::sp<::android::hidl::manager::V1_0::IServiceManager> sm
            = ::android::hardware::defaultServiceManager();
    if (sm == nullptr) {
        return false;
    }
    ::android::hardware::Return<bool> success =
            sm->registerForNotifications("android.hardware.dumpstate@1.1::IDumpstateDevice",
                    serviceName, notification);
    return success.isOk() && success;
}

static_assert(sizeof(::android::hardware::MQDescriptor<char, ::android::hardware::kSynchronizedReadWrite>) == 32, "wrong size");
static_assert(sizeof(::android::hardware::hidl_handle) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_memory) == 40, "wrong size");
static_assert(sizeof(::android::hardware::hidl_string) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_vec<char>) == 16, "wrong size");

}  // namespace V1_1
}  // namespace dumpstate
}  // namespace hardware
}  // namespace android
