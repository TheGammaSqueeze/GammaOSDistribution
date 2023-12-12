#define LOG_TAG "android.hardware.neuralnetworks@1.3::PreparedModelCallback"

#include <log/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <hidl/Static.h>
#include <hwbinder/ProcessState.h>
#include <utils/Trace.h>
#include <android/hidl/manager/1.0/IServiceManager.h>
#include <android/hardware/neuralnetworks/1.3/BpHwPreparedModelCallback.h>
#include <android/hardware/neuralnetworks/1.3/BnHwPreparedModelCallback.h>
#include <android/hardware/neuralnetworks/1.3/BsPreparedModelCallback.h>
#include <android/hardware/neuralnetworks/1.2/BpHwPreparedModelCallback.h>
#include <android/hardware/neuralnetworks/1.0/BpHwPreparedModelCallback.h>
#include <android/hidl/base/1.0/BpHwBase.h>
#include <hidl/ServiceManagement.h>

namespace android {
namespace hardware {
namespace neuralnetworks {
namespace V1_3 {

const char* IPreparedModelCallback::descriptor("android.hardware.neuralnetworks@1.3::IPreparedModelCallback");

__attribute__((constructor)) static void static_constructor() {
    ::android::hardware::details::getBnConstructorMap().set(IPreparedModelCallback::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hardware::IBinder> {
                return new BnHwPreparedModelCallback(static_cast<IPreparedModelCallback *>(iIntf));
            });
    ::android::hardware::details::getBsConstructorMap().set(IPreparedModelCallback::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hidl::base::V1_0::IBase> {
                return new BsPreparedModelCallback(static_cast<IPreparedModelCallback *>(iIntf));
            });
}

__attribute__((destructor))static void static_destructor() {
    ::android::hardware::details::getBnConstructorMap().erase(IPreparedModelCallback::descriptor);
    ::android::hardware::details::getBsConstructorMap().erase(IPreparedModelCallback::descriptor);
}

// Methods from ::android::hardware::neuralnetworks::V1_0::IPreparedModelCallback follow.
// no default implementation for: ::android::hardware::Return<void> IPreparedModelCallback::notify(::android::hardware::neuralnetworks::V1_0::ErrorStatus status, const ::android::sp<::android::hardware::neuralnetworks::V1_0::IPreparedModel>& preparedModel)

// Methods from ::android::hardware::neuralnetworks::V1_2::IPreparedModelCallback follow.
// no default implementation for: ::android::hardware::Return<void> IPreparedModelCallback::notify_1_2(::android::hardware::neuralnetworks::V1_0::ErrorStatus status, const ::android::sp<::android::hardware::neuralnetworks::V1_2::IPreparedModel>& preparedModel)

// Methods from ::android::hardware::neuralnetworks::V1_3::IPreparedModelCallback follow.
// no default implementation for: ::android::hardware::Return<void> IPreparedModelCallback::notify_1_3(::android::hardware::neuralnetworks::V1_3::ErrorStatus status, const ::android::sp<::android::hardware::neuralnetworks::V1_3::IPreparedModel>& preparedModel)

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> IPreparedModelCallback::interfaceChain(interfaceChain_cb _hidl_cb){
    _hidl_cb({
        ::android::hardware::neuralnetworks::V1_3::IPreparedModelCallback::descriptor,
        ::android::hardware::neuralnetworks::V1_2::IPreparedModelCallback::descriptor,
        ::android::hardware::neuralnetworks::V1_0::IPreparedModelCallback::descriptor,
        ::android::hidl::base::V1_0::IBase::descriptor,
    });
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IPreparedModelCallback::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    (void)fd;
    (void)options;
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IPreparedModelCallback::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    _hidl_cb(::android::hardware::neuralnetworks::V1_3::IPreparedModelCallback::descriptor);
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IPreparedModelCallback::getHashChain(getHashChain_cb _hidl_cb){
    _hidl_cb({
        (uint8_t[32]){238,227,67,12,200,108,151,199,180,7,73,88,99,216,251,97,218,111,26,100,183,114,30,119,185,180,144,155,17,177,116,233} /* eee3430cc86c97c7b407495863d8fb61da6f1a64b7721e77b9b4909b11b174e9 */,
        (uint8_t[32]){225,199,52,209,84,94,26,74,231,73,255,29,217,112,74,142,89,76,89,174,167,200,54,49,89,220,37,142,147,224,223,59} /* e1c734d1545e1a4ae749ff1dd9704a8e594c59aea7c8363159dc258e93e0df3b */,
        (uint8_t[32]){115,224,53,115,73,75,169,111,14,113,26,183,241,149,108,91,45,84,195,218,105,12,215,236,244,214,208,242,135,68,119,48} /* 73e03573494ba96f0e711ab7f1956c5b2d54c3da690cd7ecf4d6d0f287447730 */,
        (uint8_t[32]){236,127,215,158,208,45,250,133,188,73,148,38,173,174,62,190,35,239,5,36,243,205,105,87,19,147,36,184,59,24,202,76} /* ec7fd79ed02dfa85bc499426adae3ebe23ef0524f3cd6957139324b83b18ca4c */});
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IPreparedModelCallback::setHALInstrumentation(){
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> IPreparedModelCallback::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    (void)cookie;
    return (recipient != nullptr);
}

::android::hardware::Return<void> IPreparedModelCallback::ping(){
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IPreparedModelCallback::getDebugInfo(getDebugInfo_cb _hidl_cb){
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

::android::hardware::Return<void> IPreparedModelCallback::notifySyspropsChanged(){
    ::android::report_sysprop_change();
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> IPreparedModelCallback::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
    return (recipient != nullptr);
}


::android::hardware::Return<::android::sp<::android::hardware::neuralnetworks::V1_3::IPreparedModelCallback>> IPreparedModelCallback::castFrom(const ::android::sp<::android::hardware::neuralnetworks::V1_3::IPreparedModelCallback>& parent, bool /* emitError */) {
    return parent;
}

::android::hardware::Return<::android::sp<::android::hardware::neuralnetworks::V1_3::IPreparedModelCallback>> IPreparedModelCallback::castFrom(const ::android::sp<::android::hardware::neuralnetworks::V1_2::IPreparedModelCallback>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<IPreparedModelCallback, ::android::hardware::neuralnetworks::V1_2::IPreparedModelCallback, BpHwPreparedModelCallback>(
            parent, "android.hardware.neuralnetworks@1.3::IPreparedModelCallback", emitError);
}

::android::hardware::Return<::android::sp<::android::hardware::neuralnetworks::V1_3::IPreparedModelCallback>> IPreparedModelCallback::castFrom(const ::android::sp<::android::hardware::neuralnetworks::V1_0::IPreparedModelCallback>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<IPreparedModelCallback, ::android::hardware::neuralnetworks::V1_0::IPreparedModelCallback, BpHwPreparedModelCallback>(
            parent, "android.hardware.neuralnetworks@1.3::IPreparedModelCallback", emitError);
}

::android::hardware::Return<::android::sp<::android::hardware::neuralnetworks::V1_3::IPreparedModelCallback>> IPreparedModelCallback::castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<IPreparedModelCallback, ::android::hidl::base::V1_0::IBase, BpHwPreparedModelCallback>(
            parent, "android.hardware.neuralnetworks@1.3::IPreparedModelCallback", emitError);
}

BpHwPreparedModelCallback::BpHwPreparedModelCallback(const ::android::sp<::android::hardware::IBinder> &_hidl_impl)
        : BpInterface<IPreparedModelCallback>(_hidl_impl),
          ::android::hardware::details::HidlInstrumentor("android.hardware.neuralnetworks@1.3", "IPreparedModelCallback") {
}

void BpHwPreparedModelCallback::onLastStrongRef(const void* id) {
    {
        std::unique_lock<std::mutex> lock(_hidl_mMutex);
        _hidl_mDeathRecipients.clear();
    }

    BpInterface<IPreparedModelCallback>::onLastStrongRef(id);
}
// Methods from ::android::hardware::neuralnetworks::V1_3::IPreparedModelCallback follow.
::android::hardware::Return<void> BpHwPreparedModelCallback::_hidl_notify_1_3(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, ::android::hardware::neuralnetworks::V1_3::ErrorStatus status, const ::android::sp<::android::hardware::neuralnetworks::V1_3::IPreparedModel>& preparedModel) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IPreparedModelCallback::notify_1_3::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&status);
        _hidl_args.push_back((void *)&preparedModel);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.neuralnetworks", "1.3", "IPreparedModelCallback", "notify_1_3", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwPreparedModelCallback::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32((int32_t)status);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (preparedModel == nullptr) {
        _hidl_err = _hidl_data.writeStrongBinder(nullptr);
    } else {
        ::android::sp<::android::hardware::IBinder> _hidl_binder = ::android::hardware::getOrCreateCachedBinder(preparedModel.get());
        if (_hidl_binder.get() != nullptr) {
            _hidl_err = _hidl_data.writeStrongBinder(_hidl_binder);
        } else {
            _hidl_err = ::android::UNKNOWN_ERROR;
        }
    }
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    ::android::hardware::ProcessState::self()->startThreadPool();
    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(3 /* notify_1_3 */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.neuralnetworks", "1.3", "IPreparedModelCallback", "notify_1_3", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}


// Methods from ::android::hardware::neuralnetworks::V1_0::IPreparedModelCallback follow.
::android::hardware::Return<void> BpHwPreparedModelCallback::notify(::android::hardware::neuralnetworks::V1_0::ErrorStatus status, const ::android::sp<::android::hardware::neuralnetworks::V1_0::IPreparedModel>& preparedModel){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::neuralnetworks::V1_0::BpHwPreparedModelCallback::_hidl_notify(this, this, status, preparedModel);

    return _hidl_out;
}


// Methods from ::android::hardware::neuralnetworks::V1_2::IPreparedModelCallback follow.
::android::hardware::Return<void> BpHwPreparedModelCallback::notify_1_2(::android::hardware::neuralnetworks::V1_0::ErrorStatus status, const ::android::sp<::android::hardware::neuralnetworks::V1_2::IPreparedModel>& preparedModel){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::neuralnetworks::V1_2::BpHwPreparedModelCallback::_hidl_notify_1_2(this, this, status, preparedModel);

    return _hidl_out;
}


// Methods from ::android::hardware::neuralnetworks::V1_3::IPreparedModelCallback follow.
::android::hardware::Return<void> BpHwPreparedModelCallback::notify_1_3(::android::hardware::neuralnetworks::V1_3::ErrorStatus status, const ::android::sp<::android::hardware::neuralnetworks::V1_3::IPreparedModel>& preparedModel){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::neuralnetworks::V1_3::BpHwPreparedModelCallback::_hidl_notify_1_3(this, this, status, preparedModel);

    return _hidl_out;
}


// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BpHwPreparedModelCallback::interfaceChain(interfaceChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwPreparedModelCallback::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_debug(this, this, fd, options);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwPreparedModelCallback::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceDescriptor(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwPreparedModelCallback::getHashChain(getHashChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getHashChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwPreparedModelCallback::setHALInstrumentation(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_setHALInstrumentation(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwPreparedModelCallback::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    ::android::hardware::ProcessState::self()->startThreadPool();
    ::android::hardware::hidl_binder_death_recipient *binder_recipient = new ::android::hardware::hidl_binder_death_recipient(recipient, cookie, this);
    std::unique_lock<std::mutex> lock(_hidl_mMutex);
    _hidl_mDeathRecipients.push_back(binder_recipient);
    return (remote()->linkToDeath(binder_recipient) == ::android::OK);
}

::android::hardware::Return<void> BpHwPreparedModelCallback::ping(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_ping(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwPreparedModelCallback::getDebugInfo(getDebugInfo_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getDebugInfo(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwPreparedModelCallback::notifySyspropsChanged(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_notifySyspropsChanged(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwPreparedModelCallback::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
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


BnHwPreparedModelCallback::BnHwPreparedModelCallback(const ::android::sp<IPreparedModelCallback> &_hidl_impl)
        : ::android::hidl::base::V1_0::BnHwBase(_hidl_impl, "android.hardware.neuralnetworks@1.3", "IPreparedModelCallback") { 
            _hidl_mImpl = _hidl_impl;
            auto prio = ::android::hardware::getMinSchedulerPolicy(_hidl_impl);
            mSchedPolicy = prio.sched_policy;
            mSchedPriority = prio.prio;
            setRequestingSid(::android::hardware::getRequestingSid(_hidl_impl));
}

BnHwPreparedModelCallback::~BnHwPreparedModelCallback() {
    ::android::hardware::details::gBnMap->eraseIfEqual(_hidl_mImpl.get(), this);
}

// Methods from ::android::hardware::neuralnetworks::V1_3::IPreparedModelCallback follow.
::android::status_t BnHwPreparedModelCallback::_hidl_notify_1_3(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwPreparedModelCallback::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::neuralnetworks::V1_3::ErrorStatus status;
    ::android::sp<::android::hardware::neuralnetworks::V1_3::IPreparedModel> preparedModel;

    _hidl_err = _hidl_data.readInt32((int32_t *)&status);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    {
        ::android::sp<::android::hardware::IBinder> _hidl_binder;
        _hidl_err = _hidl_data.readNullableStrongBinder(&_hidl_binder);
        if (_hidl_err != ::android::OK) { return _hidl_err; }

        preparedModel = ::android::hardware::fromBinder<::android::hardware::neuralnetworks::V1_3::IPreparedModel,::android::hardware::neuralnetworks::V1_3::BpHwPreparedModel,::android::hardware::neuralnetworks::V1_3::BnHwPreparedModel>(_hidl_binder);
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IPreparedModelCallback::notify_1_3::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&status);
        _hidl_args.push_back((void *)&preparedModel);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.neuralnetworks", "1.3", "IPreparedModelCallback", "notify_1_3", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IPreparedModelCallback*>(_hidl_this->getImpl().get())->notify_1_3(status, preparedModel);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.neuralnetworks", "1.3", "IPreparedModelCallback", "notify_1_3", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}


// Methods from ::android::hardware::neuralnetworks::V1_0::IPreparedModelCallback follow.

// Methods from ::android::hardware::neuralnetworks::V1_2::IPreparedModelCallback follow.

// Methods from ::android::hardware::neuralnetworks::V1_3::IPreparedModelCallback follow.

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BnHwPreparedModelCallback::ping() {
    return ::android::hardware::Void();
}
::android::hardware::Return<void> BnHwPreparedModelCallback::getDebugInfo(getDebugInfo_cb _hidl_cb) {
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

::android::status_t BnHwPreparedModelCallback::onTransact(
        uint32_t _hidl_code,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        uint32_t _hidl_flags,
        TransactCallback _hidl_cb) {
    ::android::status_t _hidl_err = ::android::OK;

    switch (_hidl_code) {
        case 1 /* notify */:
        {
            _hidl_err = ::android::hardware::neuralnetworks::V1_0::BnHwPreparedModelCallback::_hidl_notify(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 2 /* notify_1_2 */:
        {
            _hidl_err = ::android::hardware::neuralnetworks::V1_2::BnHwPreparedModelCallback::_hidl_notify_1_2(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 3 /* notify_1_3 */:
        {
            _hidl_err = ::android::hardware::neuralnetworks::V1_3::BnHwPreparedModelCallback::_hidl_notify_1_3(this, _hidl_data, _hidl_reply, _hidl_cb);
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

BsPreparedModelCallback::BsPreparedModelCallback(const ::android::sp<::android::hardware::neuralnetworks::V1_3::IPreparedModelCallback> impl) : ::android::hardware::details::HidlInstrumentor("android.hardware.neuralnetworks@1.3", "IPreparedModelCallback"), mImpl(impl) {
    mOnewayQueue.start(3000 /* similar limit to binderized */);
}

::android::hardware::Return<void> BsPreparedModelCallback::addOnewayTask(std::function<void(void)> fun) {
    if (!mOnewayQueue.push(fun)) {
        return ::android::hardware::Status::fromExceptionCode(
                ::android::hardware::Status::EX_TRANSACTION_FAILED,
                "Passthrough oneway function queue exceeds maximum size.");
    }
    return ::android::hardware::Status();
}

::android::sp<IPreparedModelCallback> IPreparedModelCallback::tryGetService(const std::string &serviceName, const bool getStub) {
    return ::android::hardware::details::getServiceInternal<BpHwPreparedModelCallback>(serviceName, false, getStub);
}

::android::sp<IPreparedModelCallback> IPreparedModelCallback::getService(const std::string &serviceName, const bool getStub) {
    return ::android::hardware::details::getServiceInternal<BpHwPreparedModelCallback>(serviceName, true, getStub);
}

::android::status_t IPreparedModelCallback::registerAsService(const std::string &serviceName) {
    return ::android::hardware::details::registerAsServiceInternal(this, serviceName);
}

bool IPreparedModelCallback::registerForNotifications(
        const std::string &serviceName,
        const ::android::sp<::android::hidl::manager::V1_0::IServiceNotification> &notification) {
    const ::android::sp<::android::hidl::manager::V1_0::IServiceManager> sm
            = ::android::hardware::defaultServiceManager();
    if (sm == nullptr) {
        return false;
    }
    ::android::hardware::Return<bool> success =
            sm->registerForNotifications("android.hardware.neuralnetworks@1.3::IPreparedModelCallback",
                    serviceName, notification);
    return success.isOk() && success;
}

static_assert(sizeof(::android::hardware::MQDescriptor<char, ::android::hardware::kSynchronizedReadWrite>) == 32, "wrong size");
static_assert(sizeof(::android::hardware::hidl_handle) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_memory) == 40, "wrong size");
static_assert(sizeof(::android::hardware::hidl_string) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_vec<char>) == 16, "wrong size");

}  // namespace V1_3
}  // namespace neuralnetworks
}  // namespace hardware
}  // namespace android
