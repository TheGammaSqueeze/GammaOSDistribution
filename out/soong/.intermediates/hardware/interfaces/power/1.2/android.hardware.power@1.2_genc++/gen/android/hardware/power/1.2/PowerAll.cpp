#define LOG_TAG "android.hardware.power@1.2::Power"

#include <log/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <hidl/Static.h>
#include <hwbinder/ProcessState.h>
#include <utils/Trace.h>
#include <android/hidl/manager/1.0/IServiceManager.h>
#include <android/hardware/power/1.2/BpHwPower.h>
#include <android/hardware/power/1.2/BnHwPower.h>
#include <android/hardware/power/1.2/BsPower.h>
#include <android/hardware/power/1.1/BpHwPower.h>
#include <android/hardware/power/1.0/BpHwPower.h>
#include <android/hidl/base/1.0/BpHwBase.h>
#include <hidl/ServiceManagement.h>

namespace android {
namespace hardware {
namespace power {
namespace V1_2 {

const char* IPower::descriptor("android.hardware.power@1.2::IPower");

__attribute__((constructor)) static void static_constructor() {
    ::android::hardware::details::getBnConstructorMap().set(IPower::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hardware::IBinder> {
                return new BnHwPower(static_cast<IPower *>(iIntf));
            });
    ::android::hardware::details::getBsConstructorMap().set(IPower::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hidl::base::V1_0::IBase> {
                return new BsPower(static_cast<IPower *>(iIntf));
            });
}

__attribute__((destructor))static void static_destructor() {
    ::android::hardware::details::getBnConstructorMap().erase(IPower::descriptor);
    ::android::hardware::details::getBsConstructorMap().erase(IPower::descriptor);
}

// Methods from ::android::hardware::power::V1_0::IPower follow.
// no default implementation for: ::android::hardware::Return<void> IPower::setInteractive(bool interactive)
// no default implementation for: ::android::hardware::Return<void> IPower::powerHint(::android::hardware::power::V1_0::PowerHint hint, int32_t data)
// no default implementation for: ::android::hardware::Return<void> IPower::setFeature(::android::hardware::power::V1_0::Feature feature, bool activate)
// no default implementation for: ::android::hardware::Return<void> IPower::getPlatformLowPowerStats(getPlatformLowPowerStats_cb _hidl_cb)

// Methods from ::android::hardware::power::V1_1::IPower follow.
// no default implementation for: ::android::hardware::Return<void> IPower::getSubsystemLowPowerStats(getSubsystemLowPowerStats_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IPower::powerHintAsync(::android::hardware::power::V1_0::PowerHint hint, int32_t data)

// Methods from ::android::hardware::power::V1_2::IPower follow.
// no default implementation for: ::android::hardware::Return<void> IPower::powerHintAsync_1_2(::android::hardware::power::V1_2::PowerHint hint, int32_t data)

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> IPower::interfaceChain(interfaceChain_cb _hidl_cb){
    _hidl_cb({
        ::android::hardware::power::V1_2::IPower::descriptor,
        ::android::hardware::power::V1_1::IPower::descriptor,
        ::android::hardware::power::V1_0::IPower::descriptor,
        ::android::hidl::base::V1_0::IBase::descriptor,
    });
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IPower::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    (void)fd;
    (void)options;
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IPower::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    _hidl_cb(::android::hardware::power::V1_2::IPower::descriptor);
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IPower::getHashChain(getHashChain_cb _hidl_cb){
    _hidl_cb({
        (uint8_t[32]){22,62,17,94,131,63,193,215,124,221,74,140,240,200,51,187,139,141,116,254,53,200,128,254,105,49,1,209,119,116,146,111} /* 163e115e833fc1d77cdd4a8cf0c833bb8b8d74fe35c880fe693101d17774926f */,
        (uint8_t[32]){34,79,157,34,163,103,160,1,111,9,182,220,103,111,83,241,68,102,151,217,220,116,113,99,3,35,41,229,218,85,45,229} /* 224f9d22a367a0016f09b6dc676f53f1446697d9dc747163032329e5da552de5 */,
        (uint8_t[32]){222,238,29,196,148,143,51,175,32,126,16,8,171,160,246,204,7,175,183,144,14,171,83,243,49,146,200,202,193,55,238,252} /* deee1dc4948f33af207e1008aba0f6cc07afb7900eab53f33192c8cac137eefc */,
        (uint8_t[32]){236,127,215,158,208,45,250,133,188,73,148,38,173,174,62,190,35,239,5,36,243,205,105,87,19,147,36,184,59,24,202,76} /* ec7fd79ed02dfa85bc499426adae3ebe23ef0524f3cd6957139324b83b18ca4c */});
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IPower::setHALInstrumentation(){
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> IPower::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    (void)cookie;
    return (recipient != nullptr);
}

::android::hardware::Return<void> IPower::ping(){
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IPower::getDebugInfo(getDebugInfo_cb _hidl_cb){
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

::android::hardware::Return<void> IPower::notifySyspropsChanged(){
    ::android::report_sysprop_change();
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> IPower::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
    return (recipient != nullptr);
}


::android::hardware::Return<::android::sp<::android::hardware::power::V1_2::IPower>> IPower::castFrom(const ::android::sp<::android::hardware::power::V1_2::IPower>& parent, bool /* emitError */) {
    return parent;
}

::android::hardware::Return<::android::sp<::android::hardware::power::V1_2::IPower>> IPower::castFrom(const ::android::sp<::android::hardware::power::V1_1::IPower>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<IPower, ::android::hardware::power::V1_1::IPower, BpHwPower>(
            parent, "android.hardware.power@1.2::IPower", emitError);
}

::android::hardware::Return<::android::sp<::android::hardware::power::V1_2::IPower>> IPower::castFrom(const ::android::sp<::android::hardware::power::V1_0::IPower>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<IPower, ::android::hardware::power::V1_0::IPower, BpHwPower>(
            parent, "android.hardware.power@1.2::IPower", emitError);
}

::android::hardware::Return<::android::sp<::android::hardware::power::V1_2::IPower>> IPower::castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<IPower, ::android::hidl::base::V1_0::IBase, BpHwPower>(
            parent, "android.hardware.power@1.2::IPower", emitError);
}

BpHwPower::BpHwPower(const ::android::sp<::android::hardware::IBinder> &_hidl_impl)
        : BpInterface<IPower>(_hidl_impl),
          ::android::hardware::details::HidlInstrumentor("android.hardware.power@1.2", "IPower") {
}

void BpHwPower::onLastStrongRef(const void* id) {
    {
        std::unique_lock<std::mutex> lock(_hidl_mMutex);
        _hidl_mDeathRecipients.clear();
    }

    BpInterface<IPower>::onLastStrongRef(id);
}
// Methods from ::android::hardware::power::V1_2::IPower follow.
::android::hardware::Return<void> BpHwPower::_hidl_powerHintAsync_1_2(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, ::android::hardware::power::V1_2::PowerHint hint, int32_t data) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IPower::powerHintAsync_1_2::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&hint);
        _hidl_args.push_back((void *)&data);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.power", "1.2", "IPower", "powerHintAsync_1_2", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwPower::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32((uint32_t)hint);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32(data);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(7 /* powerHintAsync_1_2 */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.power", "1.2", "IPower", "powerHintAsync_1_2", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}


// Methods from ::android::hardware::power::V1_0::IPower follow.
::android::hardware::Return<void> BpHwPower::setInteractive(bool interactive){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::power::V1_0::BpHwPower::_hidl_setInteractive(this, this, interactive);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwPower::powerHint(::android::hardware::power::V1_0::PowerHint hint, int32_t data){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::power::V1_0::BpHwPower::_hidl_powerHint(this, this, hint, data);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwPower::setFeature(::android::hardware::power::V1_0::Feature feature, bool activate){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::power::V1_0::BpHwPower::_hidl_setFeature(this, this, feature, activate);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwPower::getPlatformLowPowerStats(getPlatformLowPowerStats_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::power::V1_0::BpHwPower::_hidl_getPlatformLowPowerStats(this, this, _hidl_cb);

    return _hidl_out;
}


// Methods from ::android::hardware::power::V1_1::IPower follow.
::android::hardware::Return<void> BpHwPower::getSubsystemLowPowerStats(getSubsystemLowPowerStats_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::power::V1_1::BpHwPower::_hidl_getSubsystemLowPowerStats(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwPower::powerHintAsync(::android::hardware::power::V1_0::PowerHint hint, int32_t data){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::power::V1_1::BpHwPower::_hidl_powerHintAsync(this, this, hint, data);

    return _hidl_out;
}


// Methods from ::android::hardware::power::V1_2::IPower follow.
::android::hardware::Return<void> BpHwPower::powerHintAsync_1_2(::android::hardware::power::V1_2::PowerHint hint, int32_t data){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::power::V1_2::BpHwPower::_hidl_powerHintAsync_1_2(this, this, hint, data);

    return _hidl_out;
}


// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BpHwPower::interfaceChain(interfaceChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwPower::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_debug(this, this, fd, options);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwPower::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceDescriptor(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwPower::getHashChain(getHashChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getHashChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwPower::setHALInstrumentation(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_setHALInstrumentation(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwPower::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    ::android::hardware::ProcessState::self()->startThreadPool();
    ::android::hardware::hidl_binder_death_recipient *binder_recipient = new ::android::hardware::hidl_binder_death_recipient(recipient, cookie, this);
    std::unique_lock<std::mutex> lock(_hidl_mMutex);
    _hidl_mDeathRecipients.push_back(binder_recipient);
    return (remote()->linkToDeath(binder_recipient) == ::android::OK);
}

::android::hardware::Return<void> BpHwPower::ping(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_ping(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwPower::getDebugInfo(getDebugInfo_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getDebugInfo(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwPower::notifySyspropsChanged(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_notifySyspropsChanged(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwPower::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
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


BnHwPower::BnHwPower(const ::android::sp<IPower> &_hidl_impl)
        : ::android::hidl::base::V1_0::BnHwBase(_hidl_impl, "android.hardware.power@1.2", "IPower") { 
            _hidl_mImpl = _hidl_impl;
            auto prio = ::android::hardware::getMinSchedulerPolicy(_hidl_impl);
            mSchedPolicy = prio.sched_policy;
            mSchedPriority = prio.prio;
            setRequestingSid(::android::hardware::getRequestingSid(_hidl_impl));
}

BnHwPower::~BnHwPower() {
    ::android::hardware::details::gBnMap->eraseIfEqual(_hidl_mImpl.get(), this);
}

// Methods from ::android::hardware::power::V1_2::IPower follow.
::android::status_t BnHwPower::_hidl_powerHintAsync_1_2(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwPower::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::power::V1_2::PowerHint hint;
    int32_t data;

    _hidl_err = _hidl_data.readUint32((uint32_t *)&hint);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readInt32(&data);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IPower::powerHintAsync_1_2::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&hint);
        _hidl_args.push_back((void *)&data);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.power", "1.2", "IPower", "powerHintAsync_1_2", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<IPower*>(_hidl_this->getImpl().get())->powerHintAsync_1_2(hint, data);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.power", "1.2", "IPower", "powerHintAsync_1_2", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}


// Methods from ::android::hardware::power::V1_0::IPower follow.

// Methods from ::android::hardware::power::V1_1::IPower follow.

// Methods from ::android::hardware::power::V1_2::IPower follow.

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BnHwPower::ping() {
    return ::android::hardware::Void();
}
::android::hardware::Return<void> BnHwPower::getDebugInfo(getDebugInfo_cb _hidl_cb) {
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

::android::status_t BnHwPower::onTransact(
        uint32_t _hidl_code,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        uint32_t _hidl_flags,
        TransactCallback _hidl_cb) {
    ::android::status_t _hidl_err = ::android::OK;

    switch (_hidl_code) {
        case 1 /* setInteractive */:
        {
            _hidl_err = ::android::hardware::power::V1_0::BnHwPower::_hidl_setInteractive(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 2 /* powerHint */:
        {
            _hidl_err = ::android::hardware::power::V1_0::BnHwPower::_hidl_powerHint(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 3 /* setFeature */:
        {
            _hidl_err = ::android::hardware::power::V1_0::BnHwPower::_hidl_setFeature(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 4 /* getPlatformLowPowerStats */:
        {
            _hidl_err = ::android::hardware::power::V1_0::BnHwPower::_hidl_getPlatformLowPowerStats(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 5 /* getSubsystemLowPowerStats */:
        {
            _hidl_err = ::android::hardware::power::V1_1::BnHwPower::_hidl_getSubsystemLowPowerStats(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 6 /* powerHintAsync */:
        {
            _hidl_err = ::android::hardware::power::V1_1::BnHwPower::_hidl_powerHintAsync(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 7 /* powerHintAsync_1_2 */:
        {
            _hidl_err = ::android::hardware::power::V1_2::BnHwPower::_hidl_powerHintAsync_1_2(this, _hidl_data, _hidl_reply, _hidl_cb);
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

BsPower::BsPower(const ::android::sp<::android::hardware::power::V1_2::IPower> impl) : ::android::hardware::details::HidlInstrumentor("android.hardware.power@1.2", "IPower"), mImpl(impl) {
    mOnewayQueue.start(3000 /* similar limit to binderized */);
}

::android::hardware::Return<void> BsPower::addOnewayTask(std::function<void(void)> fun) {
    if (!mOnewayQueue.push(fun)) {
        return ::android::hardware::Status::fromExceptionCode(
                ::android::hardware::Status::EX_TRANSACTION_FAILED,
                "Passthrough oneway function queue exceeds maximum size.");
    }
    return ::android::hardware::Status();
}

::android::sp<IPower> IPower::tryGetService(const std::string &serviceName, const bool getStub) {
    return ::android::hardware::details::getServiceInternal<BpHwPower>(serviceName, false, getStub);
}

::android::sp<IPower> IPower::getService(const std::string &serviceName, const bool getStub) {
    return ::android::hardware::details::getServiceInternal<BpHwPower>(serviceName, true, getStub);
}

::android::status_t IPower::registerAsService(const std::string &serviceName) {
    return ::android::hardware::details::registerAsServiceInternal(this, serviceName);
}

bool IPower::registerForNotifications(
        const std::string &serviceName,
        const ::android::sp<::android::hidl::manager::V1_0::IServiceNotification> &notification) {
    const ::android::sp<::android::hidl::manager::V1_0::IServiceManager> sm
            = ::android::hardware::defaultServiceManager();
    if (sm == nullptr) {
        return false;
    }
    ::android::hardware::Return<bool> success =
            sm->registerForNotifications("android.hardware.power@1.2::IPower",
                    serviceName, notification);
    return success.isOk() && success;
}

static_assert(sizeof(::android::hardware::MQDescriptor<char, ::android::hardware::kSynchronizedReadWrite>) == 32, "wrong size");
static_assert(sizeof(::android::hardware::hidl_handle) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_memory) == 40, "wrong size");
static_assert(sizeof(::android::hardware::hidl_string) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_vec<char>) == 16, "wrong size");

}  // namespace V1_2
}  // namespace power
}  // namespace hardware
}  // namespace android
