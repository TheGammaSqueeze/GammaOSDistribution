#define LOG_TAG "android.hardware.gnss@2.0::GnssBatching"

#include <log/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <hidl/Static.h>
#include <hwbinder/ProcessState.h>
#include <utils/Trace.h>
#include <android/hidl/manager/1.0/IServiceManager.h>
#include <android/hardware/gnss/2.0/BpHwGnssBatching.h>
#include <android/hardware/gnss/2.0/BnHwGnssBatching.h>
#include <android/hardware/gnss/2.0/BsGnssBatching.h>
#include <android/hardware/gnss/1.0/BpHwGnssBatching.h>
#include <android/hidl/base/1.0/BpHwBase.h>
#include <hidl/ServiceManagement.h>

namespace android {
namespace hardware {
namespace gnss {
namespace V2_0 {

const char* IGnssBatching::descriptor("android.hardware.gnss@2.0::IGnssBatching");

__attribute__((constructor)) static void static_constructor() {
    ::android::hardware::details::getBnConstructorMap().set(IGnssBatching::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hardware::IBinder> {
                return new BnHwGnssBatching(static_cast<IGnssBatching *>(iIntf));
            });
    ::android::hardware::details::getBsConstructorMap().set(IGnssBatching::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hidl::base::V1_0::IBase> {
                return new BsGnssBatching(static_cast<IGnssBatching *>(iIntf));
            });
}

__attribute__((destructor))static void static_destructor() {
    ::android::hardware::details::getBnConstructorMap().erase(IGnssBatching::descriptor);
    ::android::hardware::details::getBsConstructorMap().erase(IGnssBatching::descriptor);
}

// Methods from ::android::hardware::gnss::V1_0::IGnssBatching follow.
// no default implementation for: ::android::hardware::Return<bool> IGnssBatching::init(const ::android::sp<::android::hardware::gnss::V1_0::IGnssBatchingCallback>& callback)
// no default implementation for: ::android::hardware::Return<uint16_t> IGnssBatching::getBatchSize()
// no default implementation for: ::android::hardware::Return<bool> IGnssBatching::start(const ::android::hardware::gnss::V1_0::IGnssBatching::Options& options)
// no default implementation for: ::android::hardware::Return<void> IGnssBatching::flush()
// no default implementation for: ::android::hardware::Return<bool> IGnssBatching::stop()
// no default implementation for: ::android::hardware::Return<void> IGnssBatching::cleanup()

// Methods from ::android::hardware::gnss::V2_0::IGnssBatching follow.
// no default implementation for: ::android::hardware::Return<bool> IGnssBatching::init_2_0(const ::android::sp<::android::hardware::gnss::V2_0::IGnssBatchingCallback>& callback)

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> IGnssBatching::interfaceChain(interfaceChain_cb _hidl_cb){
    _hidl_cb({
        ::android::hardware::gnss::V2_0::IGnssBatching::descriptor,
        ::android::hardware::gnss::V1_0::IGnssBatching::descriptor,
        ::android::hidl::base::V1_0::IBase::descriptor,
    });
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IGnssBatching::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    (void)fd;
    (void)options;
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IGnssBatching::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    _hidl_cb(::android::hardware::gnss::V2_0::IGnssBatching::descriptor);
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IGnssBatching::getHashChain(getHashChain_cb _hidl_cb){
    _hidl_cb({
        (uint8_t[32]){219,107,223,109,252,94,223,108,133,210,148,73,118,219,137,146,39,171,181,16,121,200,147,135,67,83,195,34,52,44,80,182} /* db6bdf6dfc5edf6c85d2944976db899227abb51079c893874353c322342c50b6 */,
        (uint8_t[32]){176,92,152,60,135,195,55,110,20,82,35,104,140,59,84,27,94,17,184,39,242,17,227,141,90,49,175,28,163,162,226,34} /* b05c983c87c3376e145223688c3b541b5e11b827f211e38d5a31af1ca3a2e222 */,
        (uint8_t[32]){236,127,215,158,208,45,250,133,188,73,148,38,173,174,62,190,35,239,5,36,243,205,105,87,19,147,36,184,59,24,202,76} /* ec7fd79ed02dfa85bc499426adae3ebe23ef0524f3cd6957139324b83b18ca4c */});
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IGnssBatching::setHALInstrumentation(){
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> IGnssBatching::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    (void)cookie;
    return (recipient != nullptr);
}

::android::hardware::Return<void> IGnssBatching::ping(){
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IGnssBatching::getDebugInfo(getDebugInfo_cb _hidl_cb){
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

::android::hardware::Return<void> IGnssBatching::notifySyspropsChanged(){
    ::android::report_sysprop_change();
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> IGnssBatching::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
    return (recipient != nullptr);
}


::android::hardware::Return<::android::sp<::android::hardware::gnss::V2_0::IGnssBatching>> IGnssBatching::castFrom(const ::android::sp<::android::hardware::gnss::V2_0::IGnssBatching>& parent, bool /* emitError */) {
    return parent;
}

::android::hardware::Return<::android::sp<::android::hardware::gnss::V2_0::IGnssBatching>> IGnssBatching::castFrom(const ::android::sp<::android::hardware::gnss::V1_0::IGnssBatching>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<IGnssBatching, ::android::hardware::gnss::V1_0::IGnssBatching, BpHwGnssBatching>(
            parent, "android.hardware.gnss@2.0::IGnssBatching", emitError);
}

::android::hardware::Return<::android::sp<::android::hardware::gnss::V2_0::IGnssBatching>> IGnssBatching::castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<IGnssBatching, ::android::hidl::base::V1_0::IBase, BpHwGnssBatching>(
            parent, "android.hardware.gnss@2.0::IGnssBatching", emitError);
}

BpHwGnssBatching::BpHwGnssBatching(const ::android::sp<::android::hardware::IBinder> &_hidl_impl)
        : BpInterface<IGnssBatching>(_hidl_impl),
          ::android::hardware::details::HidlInstrumentor("android.hardware.gnss@2.0", "IGnssBatching") {
}

void BpHwGnssBatching::onLastStrongRef(const void* id) {
    {
        std::unique_lock<std::mutex> lock(_hidl_mMutex);
        _hidl_mDeathRecipients.clear();
    }

    BpInterface<IGnssBatching>::onLastStrongRef(id);
}
// Methods from ::android::hardware::gnss::V2_0::IGnssBatching follow.
::android::hardware::Return<bool> BpHwGnssBatching::_hidl_init_2_0(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::sp<::android::hardware::gnss::V2_0::IGnssBatchingCallback>& callback) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IGnssBatching::init_2_0::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&callback);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.gnss", "2.0", "IGnssBatching", "init_2_0", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    bool _hidl_out_success;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwGnssBatching::descriptor);
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

    ::android::hardware::ProcessState::self()->startThreadPool();
    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(7 /* init_2_0 */, _hidl_data, &_hidl_reply, 0 /* flags */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readBool(&_hidl_out_success);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_success);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.gnss", "2.0", "IGnssBatching", "init_2_0", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<bool>(_hidl_out_success);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<bool>(_hidl_status);
}


// Methods from ::android::hardware::gnss::V1_0::IGnssBatching follow.
::android::hardware::Return<bool> BpHwGnssBatching::init(const ::android::sp<::android::hardware::gnss::V1_0::IGnssBatchingCallback>& callback){
    ::android::hardware::Return<bool>  _hidl_out = ::android::hardware::gnss::V1_0::BpHwGnssBatching::_hidl_init(this, this, callback);

    return _hidl_out;
}

::android::hardware::Return<uint16_t> BpHwGnssBatching::getBatchSize(){
    ::android::hardware::Return<uint16_t>  _hidl_out = ::android::hardware::gnss::V1_0::BpHwGnssBatching::_hidl_getBatchSize(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwGnssBatching::start(const ::android::hardware::gnss::V1_0::IGnssBatching::Options& options){
    ::android::hardware::Return<bool>  _hidl_out = ::android::hardware::gnss::V1_0::BpHwGnssBatching::_hidl_start(this, this, options);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwGnssBatching::flush(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::gnss::V1_0::BpHwGnssBatching::_hidl_flush(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwGnssBatching::stop(){
    ::android::hardware::Return<bool>  _hidl_out = ::android::hardware::gnss::V1_0::BpHwGnssBatching::_hidl_stop(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwGnssBatching::cleanup(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::gnss::V1_0::BpHwGnssBatching::_hidl_cleanup(this, this);

    return _hidl_out;
}


// Methods from ::android::hardware::gnss::V2_0::IGnssBatching follow.
::android::hardware::Return<bool> BpHwGnssBatching::init_2_0(const ::android::sp<::android::hardware::gnss::V2_0::IGnssBatchingCallback>& callback){
    ::android::hardware::Return<bool>  _hidl_out = ::android::hardware::gnss::V2_0::BpHwGnssBatching::_hidl_init_2_0(this, this, callback);

    return _hidl_out;
}


// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BpHwGnssBatching::interfaceChain(interfaceChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwGnssBatching::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_debug(this, this, fd, options);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwGnssBatching::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceDescriptor(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwGnssBatching::getHashChain(getHashChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getHashChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwGnssBatching::setHALInstrumentation(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_setHALInstrumentation(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwGnssBatching::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    ::android::hardware::ProcessState::self()->startThreadPool();
    ::android::hardware::hidl_binder_death_recipient *binder_recipient = new ::android::hardware::hidl_binder_death_recipient(recipient, cookie, this);
    std::unique_lock<std::mutex> lock(_hidl_mMutex);
    _hidl_mDeathRecipients.push_back(binder_recipient);
    return (remote()->linkToDeath(binder_recipient) == ::android::OK);
}

::android::hardware::Return<void> BpHwGnssBatching::ping(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_ping(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwGnssBatching::getDebugInfo(getDebugInfo_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getDebugInfo(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwGnssBatching::notifySyspropsChanged(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_notifySyspropsChanged(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwGnssBatching::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
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


BnHwGnssBatching::BnHwGnssBatching(const ::android::sp<IGnssBatching> &_hidl_impl)
        : ::android::hidl::base::V1_0::BnHwBase(_hidl_impl, "android.hardware.gnss@2.0", "IGnssBatching") { 
            _hidl_mImpl = _hidl_impl;
            auto prio = ::android::hardware::getMinSchedulerPolicy(_hidl_impl);
            mSchedPolicy = prio.sched_policy;
            mSchedPriority = prio.prio;
            setRequestingSid(::android::hardware::getRequestingSid(_hidl_impl));
}

BnHwGnssBatching::~BnHwGnssBatching() {
    ::android::hardware::details::gBnMap->eraseIfEqual(_hidl_mImpl.get(), this);
}

// Methods from ::android::hardware::gnss::V2_0::IGnssBatching follow.
::android::status_t BnHwGnssBatching::_hidl_init_2_0(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwGnssBatching::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::sp<::android::hardware::gnss::V2_0::IGnssBatchingCallback> callback;

    {
        ::android::sp<::android::hardware::IBinder> _hidl_binder;
        _hidl_err = _hidl_data.readNullableStrongBinder(&_hidl_binder);
        if (_hidl_err != ::android::OK) { return _hidl_err; }

        callback = ::android::hardware::fromBinder<::android::hardware::gnss::V2_0::IGnssBatchingCallback,::android::hardware::gnss::V2_0::BpHwGnssBatchingCallback,::android::hardware::gnss::V2_0::BnHwGnssBatchingCallback>(_hidl_binder);
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IGnssBatching::init_2_0::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&callback);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.gnss", "2.0", "IGnssBatching", "init_2_0", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_out_success = static_cast<IGnssBatching*>(_hidl_this->getImpl().get())->init_2_0(callback);

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeBool(_hidl_out_success);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

_hidl_error:
    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_success);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.gnss", "2.0", "IGnssBatching", "init_2_0", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}


// Methods from ::android::hardware::gnss::V1_0::IGnssBatching follow.

// Methods from ::android::hardware::gnss::V2_0::IGnssBatching follow.

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BnHwGnssBatching::ping() {
    return ::android::hardware::Void();
}
::android::hardware::Return<void> BnHwGnssBatching::getDebugInfo(getDebugInfo_cb _hidl_cb) {
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

::android::status_t BnHwGnssBatching::onTransact(
        uint32_t _hidl_code,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        uint32_t _hidl_flags,
        TransactCallback _hidl_cb) {
    ::android::status_t _hidl_err = ::android::OK;

    switch (_hidl_code) {
        case 1 /* init */:
        {
            _hidl_err = ::android::hardware::gnss::V1_0::BnHwGnssBatching::_hidl_init(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 2 /* getBatchSize */:
        {
            _hidl_err = ::android::hardware::gnss::V1_0::BnHwGnssBatching::_hidl_getBatchSize(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 3 /* start */:
        {
            _hidl_err = ::android::hardware::gnss::V1_0::BnHwGnssBatching::_hidl_start(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 4 /* flush */:
        {
            _hidl_err = ::android::hardware::gnss::V1_0::BnHwGnssBatching::_hidl_flush(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 5 /* stop */:
        {
            _hidl_err = ::android::hardware::gnss::V1_0::BnHwGnssBatching::_hidl_stop(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 6 /* cleanup */:
        {
            _hidl_err = ::android::hardware::gnss::V1_0::BnHwGnssBatching::_hidl_cleanup(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 7 /* init_2_0 */:
        {
            _hidl_err = ::android::hardware::gnss::V2_0::BnHwGnssBatching::_hidl_init_2_0(this, _hidl_data, _hidl_reply, _hidl_cb);
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

BsGnssBatching::BsGnssBatching(const ::android::sp<::android::hardware::gnss::V2_0::IGnssBatching> impl) : ::android::hardware::details::HidlInstrumentor("android.hardware.gnss@2.0", "IGnssBatching"), mImpl(impl) {
    mOnewayQueue.start(3000 /* similar limit to binderized */);
}

::android::hardware::Return<void> BsGnssBatching::addOnewayTask(std::function<void(void)> fun) {
    if (!mOnewayQueue.push(fun)) {
        return ::android::hardware::Status::fromExceptionCode(
                ::android::hardware::Status::EX_TRANSACTION_FAILED,
                "Passthrough oneway function queue exceeds maximum size.");
    }
    return ::android::hardware::Status();
}

::android::sp<IGnssBatching> IGnssBatching::tryGetService(const std::string &serviceName, const bool getStub) {
    return ::android::hardware::details::getServiceInternal<BpHwGnssBatching>(serviceName, false, getStub);
}

::android::sp<IGnssBatching> IGnssBatching::getService(const std::string &serviceName, const bool getStub) {
    return ::android::hardware::details::getServiceInternal<BpHwGnssBatching>(serviceName, true, getStub);
}

::android::status_t IGnssBatching::registerAsService(const std::string &serviceName) {
    return ::android::hardware::details::registerAsServiceInternal(this, serviceName);
}

bool IGnssBatching::registerForNotifications(
        const std::string &serviceName,
        const ::android::sp<::android::hidl::manager::V1_0::IServiceNotification> &notification) {
    const ::android::sp<::android::hidl::manager::V1_0::IServiceManager> sm
            = ::android::hardware::defaultServiceManager();
    if (sm == nullptr) {
        return false;
    }
    ::android::hardware::Return<bool> success =
            sm->registerForNotifications("android.hardware.gnss@2.0::IGnssBatching",
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
