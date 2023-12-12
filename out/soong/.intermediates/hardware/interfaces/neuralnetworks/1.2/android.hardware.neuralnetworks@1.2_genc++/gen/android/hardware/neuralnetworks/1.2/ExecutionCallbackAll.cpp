#define LOG_TAG "android.hardware.neuralnetworks@1.2::ExecutionCallback"

#include <log/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <hidl/Static.h>
#include <hwbinder/ProcessState.h>
#include <utils/Trace.h>
#include <android/hidl/manager/1.0/IServiceManager.h>
#include <android/hardware/neuralnetworks/1.2/BpHwExecutionCallback.h>
#include <android/hardware/neuralnetworks/1.2/BnHwExecutionCallback.h>
#include <android/hardware/neuralnetworks/1.2/BsExecutionCallback.h>
#include <android/hardware/neuralnetworks/1.0/BpHwExecutionCallback.h>
#include <android/hidl/base/1.0/BpHwBase.h>
#include <hidl/ServiceManagement.h>

namespace android {
namespace hardware {
namespace neuralnetworks {
namespace V1_2 {

const char* IExecutionCallback::descriptor("android.hardware.neuralnetworks@1.2::IExecutionCallback");

__attribute__((constructor)) static void static_constructor() {
    ::android::hardware::details::getBnConstructorMap().set(IExecutionCallback::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hardware::IBinder> {
                return new BnHwExecutionCallback(static_cast<IExecutionCallback *>(iIntf));
            });
    ::android::hardware::details::getBsConstructorMap().set(IExecutionCallback::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hidl::base::V1_0::IBase> {
                return new BsExecutionCallback(static_cast<IExecutionCallback *>(iIntf));
            });
}

__attribute__((destructor))static void static_destructor() {
    ::android::hardware::details::getBnConstructorMap().erase(IExecutionCallback::descriptor);
    ::android::hardware::details::getBsConstructorMap().erase(IExecutionCallback::descriptor);
}

// Methods from ::android::hardware::neuralnetworks::V1_0::IExecutionCallback follow.
// no default implementation for: ::android::hardware::Return<void> IExecutionCallback::notify(::android::hardware::neuralnetworks::V1_0::ErrorStatus status)

// Methods from ::android::hardware::neuralnetworks::V1_2::IExecutionCallback follow.
// no default implementation for: ::android::hardware::Return<void> IExecutionCallback::notify_1_2(::android::hardware::neuralnetworks::V1_0::ErrorStatus status, const ::android::hardware::hidl_vec<::android::hardware::neuralnetworks::V1_2::OutputShape>& outputShapes, const ::android::hardware::neuralnetworks::V1_2::Timing& timing)

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> IExecutionCallback::interfaceChain(interfaceChain_cb _hidl_cb){
    _hidl_cb({
        ::android::hardware::neuralnetworks::V1_2::IExecutionCallback::descriptor,
        ::android::hardware::neuralnetworks::V1_0::IExecutionCallback::descriptor,
        ::android::hidl::base::V1_0::IBase::descriptor,
    });
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IExecutionCallback::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    (void)fd;
    (void)options;
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IExecutionCallback::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    _hidl_cb(::android::hardware::neuralnetworks::V1_2::IExecutionCallback::descriptor);
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IExecutionCallback::getHashChain(getHashChain_cb _hidl_cb){
    _hidl_cb({
        (uint8_t[32]){146,113,73,96,209,165,63,194,236,85,115,2,180,28,124,201,61,38,54,216,54,74,68,189,15,133,190,12,146,146,127,248} /* 92714960d1a53fc2ec557302b41c7cc93d2636d8364a44bd0f85be0c92927ff8 */,
        (uint8_t[32]){18,232,220,164,171,125,138,173,208,239,143,27,67,128,33,147,142,35,150,19,158,133,219,46,214,87,131,176,136,0,170,82} /* 12e8dca4ab7d8aadd0ef8f1b438021938e2396139e85db2ed65783b08800aa52 */,
        (uint8_t[32]){236,127,215,158,208,45,250,133,188,73,148,38,173,174,62,190,35,239,5,36,243,205,105,87,19,147,36,184,59,24,202,76} /* ec7fd79ed02dfa85bc499426adae3ebe23ef0524f3cd6957139324b83b18ca4c */});
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IExecutionCallback::setHALInstrumentation(){
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> IExecutionCallback::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    (void)cookie;
    return (recipient != nullptr);
}

::android::hardware::Return<void> IExecutionCallback::ping(){
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IExecutionCallback::getDebugInfo(getDebugInfo_cb _hidl_cb){
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

::android::hardware::Return<void> IExecutionCallback::notifySyspropsChanged(){
    ::android::report_sysprop_change();
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> IExecutionCallback::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
    return (recipient != nullptr);
}


::android::hardware::Return<::android::sp<::android::hardware::neuralnetworks::V1_2::IExecutionCallback>> IExecutionCallback::castFrom(const ::android::sp<::android::hardware::neuralnetworks::V1_2::IExecutionCallback>& parent, bool /* emitError */) {
    return parent;
}

::android::hardware::Return<::android::sp<::android::hardware::neuralnetworks::V1_2::IExecutionCallback>> IExecutionCallback::castFrom(const ::android::sp<::android::hardware::neuralnetworks::V1_0::IExecutionCallback>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<IExecutionCallback, ::android::hardware::neuralnetworks::V1_0::IExecutionCallback, BpHwExecutionCallback>(
            parent, "android.hardware.neuralnetworks@1.2::IExecutionCallback", emitError);
}

::android::hardware::Return<::android::sp<::android::hardware::neuralnetworks::V1_2::IExecutionCallback>> IExecutionCallback::castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<IExecutionCallback, ::android::hidl::base::V1_0::IBase, BpHwExecutionCallback>(
            parent, "android.hardware.neuralnetworks@1.2::IExecutionCallback", emitError);
}

BpHwExecutionCallback::BpHwExecutionCallback(const ::android::sp<::android::hardware::IBinder> &_hidl_impl)
        : BpInterface<IExecutionCallback>(_hidl_impl),
          ::android::hardware::details::HidlInstrumentor("android.hardware.neuralnetworks@1.2", "IExecutionCallback") {
}

void BpHwExecutionCallback::onLastStrongRef(const void* id) {
    {
        std::unique_lock<std::mutex> lock(_hidl_mMutex);
        _hidl_mDeathRecipients.clear();
    }

    BpInterface<IExecutionCallback>::onLastStrongRef(id);
}
// Methods from ::android::hardware::neuralnetworks::V1_2::IExecutionCallback follow.
::android::hardware::Return<void> BpHwExecutionCallback::_hidl_notify_1_2(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, ::android::hardware::neuralnetworks::V1_0::ErrorStatus status, const ::android::hardware::hidl_vec<::android::hardware::neuralnetworks::V1_2::OutputShape>& outputShapes, const ::android::hardware::neuralnetworks::V1_2::Timing& timing) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IExecutionCallback::notify_1_2::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&status);
        _hidl_args.push_back((void *)&outputShapes);
        _hidl_args.push_back((void *)&timing);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.neuralnetworks", "1.2", "IExecutionCallback", "notify_1_2", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwExecutionCallback::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32((int32_t)status);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_outputShapes_parent;

    _hidl_err = _hidl_data.writeBuffer(&outputShapes, sizeof(outputShapes), &_hidl_outputShapes_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_outputShapes_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            outputShapes,
            &_hidl_data,
            _hidl_outputShapes_parent,
            0 /* parentOffset */, &_hidl_outputShapes_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < outputShapes.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                outputShapes[_hidl_index_0],
                &_hidl_data,
                _hidl_outputShapes_child,
                _hidl_index_0 * sizeof(::android::hardware::neuralnetworks::V1_2::OutputShape));

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    }

    size_t _hidl_timing_parent;

    _hidl_err = _hidl_data.writeBuffer(&timing, sizeof(timing), &_hidl_timing_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(2 /* notify_1_2 */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.neuralnetworks", "1.2", "IExecutionCallback", "notify_1_2", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}


// Methods from ::android::hardware::neuralnetworks::V1_0::IExecutionCallback follow.
::android::hardware::Return<void> BpHwExecutionCallback::notify(::android::hardware::neuralnetworks::V1_0::ErrorStatus status){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::neuralnetworks::V1_0::BpHwExecutionCallback::_hidl_notify(this, this, status);

    return _hidl_out;
}


// Methods from ::android::hardware::neuralnetworks::V1_2::IExecutionCallback follow.
::android::hardware::Return<void> BpHwExecutionCallback::notify_1_2(::android::hardware::neuralnetworks::V1_0::ErrorStatus status, const ::android::hardware::hidl_vec<::android::hardware::neuralnetworks::V1_2::OutputShape>& outputShapes, const ::android::hardware::neuralnetworks::V1_2::Timing& timing){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::neuralnetworks::V1_2::BpHwExecutionCallback::_hidl_notify_1_2(this, this, status, outputShapes, timing);

    return _hidl_out;
}


// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BpHwExecutionCallback::interfaceChain(interfaceChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwExecutionCallback::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_debug(this, this, fd, options);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwExecutionCallback::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceDescriptor(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwExecutionCallback::getHashChain(getHashChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getHashChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwExecutionCallback::setHALInstrumentation(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_setHALInstrumentation(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwExecutionCallback::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    ::android::hardware::ProcessState::self()->startThreadPool();
    ::android::hardware::hidl_binder_death_recipient *binder_recipient = new ::android::hardware::hidl_binder_death_recipient(recipient, cookie, this);
    std::unique_lock<std::mutex> lock(_hidl_mMutex);
    _hidl_mDeathRecipients.push_back(binder_recipient);
    return (remote()->linkToDeath(binder_recipient) == ::android::OK);
}

::android::hardware::Return<void> BpHwExecutionCallback::ping(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_ping(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwExecutionCallback::getDebugInfo(getDebugInfo_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getDebugInfo(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwExecutionCallback::notifySyspropsChanged(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_notifySyspropsChanged(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwExecutionCallback::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
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


BnHwExecutionCallback::BnHwExecutionCallback(const ::android::sp<IExecutionCallback> &_hidl_impl)
        : ::android::hidl::base::V1_0::BnHwBase(_hidl_impl, "android.hardware.neuralnetworks@1.2", "IExecutionCallback") { 
            _hidl_mImpl = _hidl_impl;
            auto prio = ::android::hardware::getMinSchedulerPolicy(_hidl_impl);
            mSchedPolicy = prio.sched_policy;
            mSchedPriority = prio.prio;
            setRequestingSid(::android::hardware::getRequestingSid(_hidl_impl));
}

BnHwExecutionCallback::~BnHwExecutionCallback() {
    ::android::hardware::details::gBnMap->eraseIfEqual(_hidl_mImpl.get(), this);
}

// Methods from ::android::hardware::neuralnetworks::V1_2::IExecutionCallback follow.
::android::status_t BnHwExecutionCallback::_hidl_notify_1_2(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwExecutionCallback::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::neuralnetworks::V1_0::ErrorStatus status;
    const ::android::hardware::hidl_vec<::android::hardware::neuralnetworks::V1_2::OutputShape>* outputShapes;
    ::android::hardware::neuralnetworks::V1_2::Timing* timing;

    _hidl_err = _hidl_data.readInt32((int32_t *)&status);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_outputShapes_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*outputShapes), &_hidl_outputShapes_parent,  reinterpret_cast<const void **>(&outputShapes));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_outputShapes_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::neuralnetworks::V1_2::OutputShape> &>(*outputShapes),
            _hidl_data,
            _hidl_outputShapes_parent,
            0 /* parentOffset */, &_hidl_outputShapes_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < outputShapes->size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::neuralnetworks::V1_2::OutputShape &>((*outputShapes)[_hidl_index_0]),
                _hidl_data,
                _hidl_outputShapes_child,
                _hidl_index_0 * sizeof(::android::hardware::neuralnetworks::V1_2::OutputShape));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    size_t _hidl_timing_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*timing), &_hidl_timing_parent,  const_cast<const void**>(reinterpret_cast<void **>(&timing)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IExecutionCallback::notify_1_2::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&status);
        _hidl_args.push_back((void *)outputShapes);
        _hidl_args.push_back((void *)timing);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.neuralnetworks", "1.2", "IExecutionCallback", "notify_1_2", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IExecutionCallback*>(_hidl_this->getImpl().get())->notify_1_2(status, *outputShapes, *timing);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.neuralnetworks", "1.2", "IExecutionCallback", "notify_1_2", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}


// Methods from ::android::hardware::neuralnetworks::V1_0::IExecutionCallback follow.

// Methods from ::android::hardware::neuralnetworks::V1_2::IExecutionCallback follow.

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BnHwExecutionCallback::ping() {
    return ::android::hardware::Void();
}
::android::hardware::Return<void> BnHwExecutionCallback::getDebugInfo(getDebugInfo_cb _hidl_cb) {
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

::android::status_t BnHwExecutionCallback::onTransact(
        uint32_t _hidl_code,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        uint32_t _hidl_flags,
        TransactCallback _hidl_cb) {
    ::android::status_t _hidl_err = ::android::OK;

    switch (_hidl_code) {
        case 1 /* notify */:
        {
            _hidl_err = ::android::hardware::neuralnetworks::V1_0::BnHwExecutionCallback::_hidl_notify(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 2 /* notify_1_2 */:
        {
            _hidl_err = ::android::hardware::neuralnetworks::V1_2::BnHwExecutionCallback::_hidl_notify_1_2(this, _hidl_data, _hidl_reply, _hidl_cb);
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

BsExecutionCallback::BsExecutionCallback(const ::android::sp<::android::hardware::neuralnetworks::V1_2::IExecutionCallback> impl) : ::android::hardware::details::HidlInstrumentor("android.hardware.neuralnetworks@1.2", "IExecutionCallback"), mImpl(impl) {
    mOnewayQueue.start(3000 /* similar limit to binderized */);
}

::android::hardware::Return<void> BsExecutionCallback::addOnewayTask(std::function<void(void)> fun) {
    if (!mOnewayQueue.push(fun)) {
        return ::android::hardware::Status::fromExceptionCode(
                ::android::hardware::Status::EX_TRANSACTION_FAILED,
                "Passthrough oneway function queue exceeds maximum size.");
    }
    return ::android::hardware::Status();
}

::android::sp<IExecutionCallback> IExecutionCallback::tryGetService(const std::string &serviceName, const bool getStub) {
    return ::android::hardware::details::getServiceInternal<BpHwExecutionCallback>(serviceName, false, getStub);
}

::android::sp<IExecutionCallback> IExecutionCallback::getService(const std::string &serviceName, const bool getStub) {
    return ::android::hardware::details::getServiceInternal<BpHwExecutionCallback>(serviceName, true, getStub);
}

::android::status_t IExecutionCallback::registerAsService(const std::string &serviceName) {
    return ::android::hardware::details::registerAsServiceInternal(this, serviceName);
}

bool IExecutionCallback::registerForNotifications(
        const std::string &serviceName,
        const ::android::sp<::android::hidl::manager::V1_0::IServiceNotification> &notification) {
    const ::android::sp<::android::hidl::manager::V1_0::IServiceManager> sm
            = ::android::hardware::defaultServiceManager();
    if (sm == nullptr) {
        return false;
    }
    ::android::hardware::Return<bool> success =
            sm->registerForNotifications("android.hardware.neuralnetworks@1.2::IExecutionCallback",
                    serviceName, notification);
    return success.isOk() && success;
}

static_assert(sizeof(::android::hardware::MQDescriptor<char, ::android::hardware::kSynchronizedReadWrite>) == 32, "wrong size");
static_assert(sizeof(::android::hardware::hidl_handle) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_memory) == 40, "wrong size");
static_assert(sizeof(::android::hardware::hidl_string) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_vec<char>) == 16, "wrong size");

}  // namespace V1_2
}  // namespace neuralnetworks
}  // namespace hardware
}  // namespace android
