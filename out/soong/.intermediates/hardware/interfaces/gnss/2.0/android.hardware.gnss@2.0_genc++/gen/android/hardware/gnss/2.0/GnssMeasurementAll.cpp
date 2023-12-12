#define LOG_TAG "android.hardware.gnss@2.0::GnssMeasurement"

#include <log/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <hidl/Static.h>
#include <hwbinder/ProcessState.h>
#include <utils/Trace.h>
#include <android/hidl/manager/1.0/IServiceManager.h>
#include <android/hardware/gnss/2.0/BpHwGnssMeasurement.h>
#include <android/hardware/gnss/2.0/BnHwGnssMeasurement.h>
#include <android/hardware/gnss/2.0/BsGnssMeasurement.h>
#include <android/hardware/gnss/1.1/BpHwGnssMeasurement.h>
#include <android/hardware/gnss/1.0/BpHwGnssMeasurement.h>
#include <android/hidl/base/1.0/BpHwBase.h>
#include <hidl/ServiceManagement.h>

namespace android {
namespace hardware {
namespace gnss {
namespace V2_0 {

const char* IGnssMeasurement::descriptor("android.hardware.gnss@2.0::IGnssMeasurement");

__attribute__((constructor)) static void static_constructor() {
    ::android::hardware::details::getBnConstructorMap().set(IGnssMeasurement::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hardware::IBinder> {
                return new BnHwGnssMeasurement(static_cast<IGnssMeasurement *>(iIntf));
            });
    ::android::hardware::details::getBsConstructorMap().set(IGnssMeasurement::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hidl::base::V1_0::IBase> {
                return new BsGnssMeasurement(static_cast<IGnssMeasurement *>(iIntf));
            });
}

__attribute__((destructor))static void static_destructor() {
    ::android::hardware::details::getBnConstructorMap().erase(IGnssMeasurement::descriptor);
    ::android::hardware::details::getBsConstructorMap().erase(IGnssMeasurement::descriptor);
}

// Methods from ::android::hardware::gnss::V1_0::IGnssMeasurement follow.
// no default implementation for: ::android::hardware::Return<::android::hardware::gnss::V1_0::IGnssMeasurement::GnssMeasurementStatus> IGnssMeasurement::setCallback(const ::android::sp<::android::hardware::gnss::V1_0::IGnssMeasurementCallback>& callback)
// no default implementation for: ::android::hardware::Return<void> IGnssMeasurement::close()

// Methods from ::android::hardware::gnss::V1_1::IGnssMeasurement follow.
// no default implementation for: ::android::hardware::Return<::android::hardware::gnss::V1_0::IGnssMeasurement::GnssMeasurementStatus> IGnssMeasurement::setCallback_1_1(const ::android::sp<::android::hardware::gnss::V1_1::IGnssMeasurementCallback>& callback, bool enableFullTracking)

// Methods from ::android::hardware::gnss::V2_0::IGnssMeasurement follow.
// no default implementation for: ::android::hardware::Return<::android::hardware::gnss::V1_0::IGnssMeasurement::GnssMeasurementStatus> IGnssMeasurement::setCallback_2_0(const ::android::sp<::android::hardware::gnss::V2_0::IGnssMeasurementCallback>& callback, bool enableFullTracking)

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> IGnssMeasurement::interfaceChain(interfaceChain_cb _hidl_cb){
    _hidl_cb({
        ::android::hardware::gnss::V2_0::IGnssMeasurement::descriptor,
        ::android::hardware::gnss::V1_1::IGnssMeasurement::descriptor,
        ::android::hardware::gnss::V1_0::IGnssMeasurement::descriptor,
        ::android::hidl::base::V1_0::IBase::descriptor,
    });
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IGnssMeasurement::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    (void)fd;
    (void)options;
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IGnssMeasurement::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    _hidl_cb(::android::hardware::gnss::V2_0::IGnssMeasurement::descriptor);
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IGnssMeasurement::getHashChain(getHashChain_cb _hidl_cb){
    _hidl_cb({
        (uint8_t[32]){198,119,89,245,214,56,125,39,59,102,114,145,128,208,54,144,232,39,240,182,184,212,225,60,226,255,66,211,27,34,64,101} /* c67759f5d6387d273b66729180d03690e827f0b6b8d4e13ce2ff42d31b224065 */,
        (uint8_t[32]){26,7,209,56,62,132,124,61,235,105,110,199,162,201,227,59,150,131,119,41,69,102,4,72,160,16,177,128,99,218,103,164} /* 1a07d1383e847c3deb696ec7a2c9e33b9683772945660448a010b18063da67a4 */,
        (uint8_t[32]){158,168,152,123,177,8,156,140,93,123,103,134,101,117,184,102,239,81,96,69,2,29,158,252,195,124,99,82,188,224,114,163} /* 9ea8987bb1089c8c5d7b67866575b866ef516045021d9efcc37c6352bce072a3 */,
        (uint8_t[32]){236,127,215,158,208,45,250,133,188,73,148,38,173,174,62,190,35,239,5,36,243,205,105,87,19,147,36,184,59,24,202,76} /* ec7fd79ed02dfa85bc499426adae3ebe23ef0524f3cd6957139324b83b18ca4c */});
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IGnssMeasurement::setHALInstrumentation(){
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> IGnssMeasurement::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    (void)cookie;
    return (recipient != nullptr);
}

::android::hardware::Return<void> IGnssMeasurement::ping(){
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IGnssMeasurement::getDebugInfo(getDebugInfo_cb _hidl_cb){
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

::android::hardware::Return<void> IGnssMeasurement::notifySyspropsChanged(){
    ::android::report_sysprop_change();
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> IGnssMeasurement::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
    return (recipient != nullptr);
}


::android::hardware::Return<::android::sp<::android::hardware::gnss::V2_0::IGnssMeasurement>> IGnssMeasurement::castFrom(const ::android::sp<::android::hardware::gnss::V2_0::IGnssMeasurement>& parent, bool /* emitError */) {
    return parent;
}

::android::hardware::Return<::android::sp<::android::hardware::gnss::V2_0::IGnssMeasurement>> IGnssMeasurement::castFrom(const ::android::sp<::android::hardware::gnss::V1_1::IGnssMeasurement>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<IGnssMeasurement, ::android::hardware::gnss::V1_1::IGnssMeasurement, BpHwGnssMeasurement>(
            parent, "android.hardware.gnss@2.0::IGnssMeasurement", emitError);
}

::android::hardware::Return<::android::sp<::android::hardware::gnss::V2_0::IGnssMeasurement>> IGnssMeasurement::castFrom(const ::android::sp<::android::hardware::gnss::V1_0::IGnssMeasurement>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<IGnssMeasurement, ::android::hardware::gnss::V1_0::IGnssMeasurement, BpHwGnssMeasurement>(
            parent, "android.hardware.gnss@2.0::IGnssMeasurement", emitError);
}

::android::hardware::Return<::android::sp<::android::hardware::gnss::V2_0::IGnssMeasurement>> IGnssMeasurement::castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<IGnssMeasurement, ::android::hidl::base::V1_0::IBase, BpHwGnssMeasurement>(
            parent, "android.hardware.gnss@2.0::IGnssMeasurement", emitError);
}

BpHwGnssMeasurement::BpHwGnssMeasurement(const ::android::sp<::android::hardware::IBinder> &_hidl_impl)
        : BpInterface<IGnssMeasurement>(_hidl_impl),
          ::android::hardware::details::HidlInstrumentor("android.hardware.gnss@2.0", "IGnssMeasurement") {
}

void BpHwGnssMeasurement::onLastStrongRef(const void* id) {
    {
        std::unique_lock<std::mutex> lock(_hidl_mMutex);
        _hidl_mDeathRecipients.clear();
    }

    BpInterface<IGnssMeasurement>::onLastStrongRef(id);
}
// Methods from ::android::hardware::gnss::V2_0::IGnssMeasurement follow.
::android::hardware::Return<::android::hardware::gnss::V1_0::IGnssMeasurement::GnssMeasurementStatus> BpHwGnssMeasurement::_hidl_setCallback_2_0(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::sp<::android::hardware::gnss::V2_0::IGnssMeasurementCallback>& callback, bool enableFullTracking) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IGnssMeasurement::setCallback_2_0::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&callback);
        _hidl_args.push_back((void *)&enableFullTracking);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.gnss", "2.0", "IGnssMeasurement", "setCallback_2_0", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    ::android::hardware::gnss::V1_0::IGnssMeasurement::GnssMeasurementStatus _hidl_out_initRet;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwGnssMeasurement::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (callback == nullptr) {
        _hidl_err = _hidl_data.writeStrongBinder(nullptr);
    } else {
        ::android::sp<::android::hardware::IBinder> _hidl_binder = ::android::hardware::getOrCreateCachedBinder(callback.get());
        if (_hidl_binder.get() != nullptr) {
            _hidl_err = _hidl_data.writeStrongBinder(_hidl_binder);
        } else {
            _hidl_err = ::android::UNKNOWN_ERROR;
        }
    }
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeBool(enableFullTracking);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    ::android::hardware::ProcessState::self()->startThreadPool();
    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(4 /* setCallback_2_0 */, _hidl_data, &_hidl_reply, 0 /* flags */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_initRet);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_initRet);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.gnss", "2.0", "IGnssMeasurement", "setCallback_2_0", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<::android::hardware::gnss::V1_0::IGnssMeasurement::GnssMeasurementStatus>(_hidl_out_initRet);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<::android::hardware::gnss::V1_0::IGnssMeasurement::GnssMeasurementStatus>(_hidl_status);
}


// Methods from ::android::hardware::gnss::V1_0::IGnssMeasurement follow.
::android::hardware::Return<::android::hardware::gnss::V1_0::IGnssMeasurement::GnssMeasurementStatus> BpHwGnssMeasurement::setCallback(const ::android::sp<::android::hardware::gnss::V1_0::IGnssMeasurementCallback>& callback){
    ::android::hardware::Return<::android::hardware::gnss::V1_0::IGnssMeasurement::GnssMeasurementStatus>  _hidl_out = ::android::hardware::gnss::V1_0::BpHwGnssMeasurement::_hidl_setCallback(this, this, callback);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwGnssMeasurement::close(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::gnss::V1_0::BpHwGnssMeasurement::_hidl_close(this, this);

    return _hidl_out;
}


// Methods from ::android::hardware::gnss::V1_1::IGnssMeasurement follow.
::android::hardware::Return<::android::hardware::gnss::V1_0::IGnssMeasurement::GnssMeasurementStatus> BpHwGnssMeasurement::setCallback_1_1(const ::android::sp<::android::hardware::gnss::V1_1::IGnssMeasurementCallback>& callback, bool enableFullTracking){
    ::android::hardware::Return<::android::hardware::gnss::V1_0::IGnssMeasurement::GnssMeasurementStatus>  _hidl_out = ::android::hardware::gnss::V1_1::BpHwGnssMeasurement::_hidl_setCallback_1_1(this, this, callback, enableFullTracking);

    return _hidl_out;
}


// Methods from ::android::hardware::gnss::V2_0::IGnssMeasurement follow.
::android::hardware::Return<::android::hardware::gnss::V1_0::IGnssMeasurement::GnssMeasurementStatus> BpHwGnssMeasurement::setCallback_2_0(const ::android::sp<::android::hardware::gnss::V2_0::IGnssMeasurementCallback>& callback, bool enableFullTracking){
    ::android::hardware::Return<::android::hardware::gnss::V1_0::IGnssMeasurement::GnssMeasurementStatus>  _hidl_out = ::android::hardware::gnss::V2_0::BpHwGnssMeasurement::_hidl_setCallback_2_0(this, this, callback, enableFullTracking);

    return _hidl_out;
}


// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BpHwGnssMeasurement::interfaceChain(interfaceChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwGnssMeasurement::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_debug(this, this, fd, options);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwGnssMeasurement::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceDescriptor(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwGnssMeasurement::getHashChain(getHashChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getHashChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwGnssMeasurement::setHALInstrumentation(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_setHALInstrumentation(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwGnssMeasurement::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    ::android::hardware::ProcessState::self()->startThreadPool();
    ::android::hardware::hidl_binder_death_recipient *binder_recipient = new ::android::hardware::hidl_binder_death_recipient(recipient, cookie, this);
    std::unique_lock<std::mutex> lock(_hidl_mMutex);
    _hidl_mDeathRecipients.push_back(binder_recipient);
    return (remote()->linkToDeath(binder_recipient) == ::android::OK);
}

::android::hardware::Return<void> BpHwGnssMeasurement::ping(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_ping(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwGnssMeasurement::getDebugInfo(getDebugInfo_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getDebugInfo(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwGnssMeasurement::notifySyspropsChanged(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_notifySyspropsChanged(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwGnssMeasurement::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
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


BnHwGnssMeasurement::BnHwGnssMeasurement(const ::android::sp<IGnssMeasurement> &_hidl_impl)
        : ::android::hidl::base::V1_0::BnHwBase(_hidl_impl, "android.hardware.gnss@2.0", "IGnssMeasurement") { 
            _hidl_mImpl = _hidl_impl;
            auto prio = ::android::hardware::getMinSchedulerPolicy(_hidl_impl);
            mSchedPolicy = prio.sched_policy;
            mSchedPriority = prio.prio;
            setRequestingSid(::android::hardware::getRequestingSid(_hidl_impl));
}

BnHwGnssMeasurement::~BnHwGnssMeasurement() {
    ::android::hardware::details::gBnMap->eraseIfEqual(_hidl_mImpl.get(), this);
}

// Methods from ::android::hardware::gnss::V2_0::IGnssMeasurement follow.
::android::status_t BnHwGnssMeasurement::_hidl_setCallback_2_0(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwGnssMeasurement::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::sp<::android::hardware::gnss::V2_0::IGnssMeasurementCallback> callback;
    bool enableFullTracking;

    {
        ::android::sp<::android::hardware::IBinder> _hidl_binder;
        _hidl_err = _hidl_data.readNullableStrongBinder(&_hidl_binder);
        if (_hidl_err != ::android::OK) { return _hidl_err; }

        callback = ::android::hardware::fromBinder<::android::hardware::gnss::V2_0::IGnssMeasurementCallback,::android::hardware::gnss::V2_0::BpHwGnssMeasurementCallback,::android::hardware::gnss::V2_0::BnHwGnssMeasurementCallback>(_hidl_binder);
    }

    _hidl_err = _hidl_data.readBool(&enableFullTracking);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IGnssMeasurement::setCallback_2_0::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&callback);
        _hidl_args.push_back((void *)&enableFullTracking);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.gnss", "2.0", "IGnssMeasurement", "setCallback_2_0", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::gnss::V1_0::IGnssMeasurement::GnssMeasurementStatus _hidl_out_initRet = static_cast<IGnssMeasurement*>(_hidl_this->getImpl().get())->setCallback_2_0(callback, enableFullTracking);

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_initRet);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

_hidl_error:
    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_initRet);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.gnss", "2.0", "IGnssMeasurement", "setCallback_2_0", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}


// Methods from ::android::hardware::gnss::V1_0::IGnssMeasurement follow.

// Methods from ::android::hardware::gnss::V1_1::IGnssMeasurement follow.

// Methods from ::android::hardware::gnss::V2_0::IGnssMeasurement follow.

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BnHwGnssMeasurement::ping() {
    return ::android::hardware::Void();
}
::android::hardware::Return<void> BnHwGnssMeasurement::getDebugInfo(getDebugInfo_cb _hidl_cb) {
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

::android::status_t BnHwGnssMeasurement::onTransact(
        uint32_t _hidl_code,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        uint32_t _hidl_flags,
        TransactCallback _hidl_cb) {
    ::android::status_t _hidl_err = ::android::OK;

    switch (_hidl_code) {
        case 1 /* setCallback */:
        {
            _hidl_err = ::android::hardware::gnss::V1_0::BnHwGnssMeasurement::_hidl_setCallback(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 2 /* close */:
        {
            _hidl_err = ::android::hardware::gnss::V1_0::BnHwGnssMeasurement::_hidl_close(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 3 /* setCallback_1_1 */:
        {
            _hidl_err = ::android::hardware::gnss::V1_1::BnHwGnssMeasurement::_hidl_setCallback_1_1(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 4 /* setCallback_2_0 */:
        {
            _hidl_err = ::android::hardware::gnss::V2_0::BnHwGnssMeasurement::_hidl_setCallback_2_0(this, _hidl_data, _hidl_reply, _hidl_cb);
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

BsGnssMeasurement::BsGnssMeasurement(const ::android::sp<::android::hardware::gnss::V2_0::IGnssMeasurement> impl) : ::android::hardware::details::HidlInstrumentor("android.hardware.gnss@2.0", "IGnssMeasurement"), mImpl(impl) {
    mOnewayQueue.start(3000 /* similar limit to binderized */);
}

::android::hardware::Return<void> BsGnssMeasurement::addOnewayTask(std::function<void(void)> fun) {
    if (!mOnewayQueue.push(fun)) {
        return ::android::hardware::Status::fromExceptionCode(
                ::android::hardware::Status::EX_TRANSACTION_FAILED,
                "Passthrough oneway function queue exceeds maximum size.");
    }
    return ::android::hardware::Status();
}

::android::sp<IGnssMeasurement> IGnssMeasurement::tryGetService(const std::string &serviceName, const bool getStub) {
    return ::android::hardware::details::getServiceInternal<BpHwGnssMeasurement>(serviceName, false, getStub);
}

::android::sp<IGnssMeasurement> IGnssMeasurement::getService(const std::string &serviceName, const bool getStub) {
    return ::android::hardware::details::getServiceInternal<BpHwGnssMeasurement>(serviceName, true, getStub);
}

::android::status_t IGnssMeasurement::registerAsService(const std::string &serviceName) {
    return ::android::hardware::details::registerAsServiceInternal(this, serviceName);
}

bool IGnssMeasurement::registerForNotifications(
        const std::string &serviceName,
        const ::android::sp<::android::hidl::manager::V1_0::IServiceNotification> &notification) {
    const ::android::sp<::android::hidl::manager::V1_0::IServiceManager> sm
            = ::android::hardware::defaultServiceManager();
    if (sm == nullptr) {
        return false;
    }
    ::android::hardware::Return<bool> success =
            sm->registerForNotifications("android.hardware.gnss@2.0::IGnssMeasurement",
                    serviceName, notification);
    return success.isOk() && success;
}

static_assert(sizeof(::android::hardware::MQDescriptor<char, ::android::hardware::kSynchronizedReadWrite>) == 32, "wrong size");
static_assert(sizeof(::android::hardware::hidl_handle) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_memory) == 40, "wrong size");
static_assert(sizeof(::android::hardware::hidl_string) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_vec<char>) == 16, "wrong size");

}  // namespace V2_0
}  // namespace gnss
}  // namespace hardware
}  // namespace android
