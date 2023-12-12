#define LOG_TAG "vendor.samsung.hardware.light@3.0::SehLight"

#include <log/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <hidl/Static.h>
#include <hwbinder/ProcessState.h>
#include <utils/Trace.h>
#include <android/hidl/manager/1.0/IServiceManager.h>
#include <vendor/samsung/hardware/light/3.0/BpHwSehLight.h>
#include <vendor/samsung/hardware/light/3.0/BnHwSehLight.h>
#include <vendor/samsung/hardware/light/3.0/BsSehLight.h>
#include <android/hardware/light/2.0/BpHwLight.h>
#include <android/hidl/base/1.0/BpHwBase.h>
#include <hidl/ServiceManagement.h>

namespace vendor {
namespace samsung {
namespace hardware {
namespace light {
namespace V3_0 {

const char* ISehLight::descriptor("vendor.samsung.hardware.light@3.0::ISehLight");

__attribute__((constructor)) static void static_constructor() {
    ::android::hardware::details::getBnConstructorMap().set(ISehLight::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hardware::IBinder> {
                return new BnHwSehLight(static_cast<ISehLight *>(iIntf));
            });
    ::android::hardware::details::getBsConstructorMap().set(ISehLight::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hidl::base::V1_0::IBase> {
                return new BsSehLight(static_cast<ISehLight *>(iIntf));
            });
}

__attribute__((destructor))static void static_destructor() {
    ::android::hardware::details::getBnConstructorMap().erase(ISehLight::descriptor);
    ::android::hardware::details::getBsConstructorMap().erase(ISehLight::descriptor);
}

// Methods from ::android::hardware::light::V2_0::ILight follow.
// no default implementation for: ::android::hardware::Return<::android::hardware::light::V2_0::Status> ISehLight::setLight(::android::hardware::light::V2_0::Type type, const ::android::hardware::light::V2_0::LightState& state)
// no default implementation for: ::android::hardware::Return<void> ISehLight::getSupportedTypes(getSupportedTypes_cb _hidl_cb)

// Methods from ::vendor::samsung::hardware::light::V3_0::ISehLight follow.
// no default implementation for: ::android::hardware::Return<::android::hardware::light::V2_0::Status> ISehLight::sehSetLight(::vendor::samsung::hardware::light::V3_0::SehType i, const ::vendor::samsung::hardware::light::V3_0::SehLightState& sehLightState)

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> ISehLight::interfaceChain(interfaceChain_cb _hidl_cb){
    _hidl_cb({
        ::vendor::samsung::hardware::light::V3_0::ISehLight::descriptor,
        ::android::hardware::light::V2_0::ILight::descriptor,
        ::android::hidl::base::V1_0::IBase::descriptor,
    });
    return ::android::hardware::Void();
}

::android::hardware::Return<void> ISehLight::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    (void)fd;
    (void)options;
    return ::android::hardware::Void();
}

::android::hardware::Return<void> ISehLight::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    _hidl_cb(::vendor::samsung::hardware::light::V3_0::ISehLight::descriptor);
    return ::android::hardware::Void();
}

::android::hardware::Return<void> ISehLight::getHashChain(getHashChain_cb _hidl_cb){
    _hidl_cb({
        (uint8_t[32]){0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0} /* 0000000000000000000000000000000000000000000000000000000000000000 */,
        (uint8_t[32]){212,237,47,14,20,249,233,20,208,177,39,93,46,3,99,25,47,227,10,202,144,89,200,78,219,95,173,21,153,95,158,196} /* d4ed2f0e14f9e914d0b1275d2e0363192fe30aca9059c84edb5fad15995f9ec4 */,
        (uint8_t[32]){236,127,215,158,208,45,250,133,188,73,148,38,173,174,62,190,35,239,5,36,243,205,105,87,19,147,36,184,59,24,202,76} /* ec7fd79ed02dfa85bc499426adae3ebe23ef0524f3cd6957139324b83b18ca4c */});
    return ::android::hardware::Void();
}

::android::hardware::Return<void> ISehLight::setHALInstrumentation(){
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> ISehLight::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    (void)cookie;
    return (recipient != nullptr);
}

::android::hardware::Return<void> ISehLight::ping(){
    return ::android::hardware::Void();
}

::android::hardware::Return<void> ISehLight::getDebugInfo(getDebugInfo_cb _hidl_cb){
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

::android::hardware::Return<void> ISehLight::notifySyspropsChanged(){
    ::android::report_sysprop_change();
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> ISehLight::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
    return (recipient != nullptr);
}


::android::hardware::Return<::android::sp<::vendor::samsung::hardware::light::V3_0::ISehLight>> ISehLight::castFrom(const ::android::sp<::vendor::samsung::hardware::light::V3_0::ISehLight>& parent, bool /* emitError */) {
    return parent;
}

::android::hardware::Return<::android::sp<::vendor::samsung::hardware::light::V3_0::ISehLight>> ISehLight::castFrom(const ::android::sp<::android::hardware::light::V2_0::ILight>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<ISehLight, ::android::hardware::light::V2_0::ILight, BpHwSehLight>(
            parent, "vendor.samsung.hardware.light@3.0::ISehLight", emitError);
}

::android::hardware::Return<::android::sp<::vendor::samsung::hardware::light::V3_0::ISehLight>> ISehLight::castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<ISehLight, ::android::hidl::base::V1_0::IBase, BpHwSehLight>(
            parent, "vendor.samsung.hardware.light@3.0::ISehLight", emitError);
}

BpHwSehLight::BpHwSehLight(const ::android::sp<::android::hardware::IBinder> &_hidl_impl)
        : BpInterface<ISehLight>(_hidl_impl),
          ::android::hardware::details::HidlInstrumentor("vendor.samsung.hardware.light@3.0", "ISehLight") {
}

void BpHwSehLight::onLastStrongRef(const void* id) {
    {
        std::unique_lock<std::mutex> lock(_hidl_mMutex);
        _hidl_mDeathRecipients.clear();
    }

    BpInterface<ISehLight>::onLastStrongRef(id);
}
// Methods from ::vendor::samsung::hardware::light::V3_0::ISehLight follow.
::android::hardware::Return<::android::hardware::light::V2_0::Status> BpHwSehLight::_hidl_sehSetLight(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, ::vendor::samsung::hardware::light::V3_0::SehType i, const ::vendor::samsung::hardware::light::V3_0::SehLightState& sehLightState) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::ISehLight::sehSetLight::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&i);
        _hidl_args.push_back((void *)&sehLightState);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "vendor.samsung.hardware.light", "3.0", "ISehLight", "sehSetLight", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    ::android::hardware::light::V2_0::Status _hidl_out_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwSehLight::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32((uint32_t)i);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_sehLightState_parent;

    _hidl_err = _hidl_data.writeBuffer(&sehLightState, sizeof(sehLightState), &_hidl_sehLightState_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(3 /* sehSetLight */, _hidl_data, &_hidl_reply, 0 /* flags */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (!_hidl_status.isOk()) { return _hidl_status; }

    _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_status);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_status);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "vendor.samsung.hardware.light", "3.0", "ISehLight", "sehSetLight", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<::android::hardware::light::V2_0::Status>(_hidl_out_status);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<::android::hardware::light::V2_0::Status>(_hidl_status);
}


// Methods from ::android::hardware::light::V2_0::ILight follow.
::android::hardware::Return<::android::hardware::light::V2_0::Status> BpHwSehLight::setLight(::android::hardware::light::V2_0::Type type, const ::android::hardware::light::V2_0::LightState& state){
    ::android::hardware::Return<::android::hardware::light::V2_0::Status>  _hidl_out = ::android::hardware::light::V2_0::BpHwLight::_hidl_setLight(this, this, type, state);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwSehLight::getSupportedTypes(getSupportedTypes_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::light::V2_0::BpHwLight::_hidl_getSupportedTypes(this, this, _hidl_cb);

    return _hidl_out;
}


// Methods from ::vendor::samsung::hardware::light::V3_0::ISehLight follow.
::android::hardware::Return<::android::hardware::light::V2_0::Status> BpHwSehLight::sehSetLight(::vendor::samsung::hardware::light::V3_0::SehType i, const ::vendor::samsung::hardware::light::V3_0::SehLightState& sehLightState){
    ::android::hardware::Return<::android::hardware::light::V2_0::Status>  _hidl_out = ::vendor::samsung::hardware::light::V3_0::BpHwSehLight::_hidl_sehSetLight(this, this, i, sehLightState);

    return _hidl_out;
}


// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BpHwSehLight::interfaceChain(interfaceChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwSehLight::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_debug(this, this, fd, options);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwSehLight::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceDescriptor(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwSehLight::getHashChain(getHashChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getHashChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwSehLight::setHALInstrumentation(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_setHALInstrumentation(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwSehLight::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    ::android::hardware::ProcessState::self()->startThreadPool();
    ::android::hardware::hidl_binder_death_recipient *binder_recipient = new ::android::hardware::hidl_binder_death_recipient(recipient, cookie, this);
    std::unique_lock<std::mutex> lock(_hidl_mMutex);
    _hidl_mDeathRecipients.push_back(binder_recipient);
    return (remote()->linkToDeath(binder_recipient) == ::android::OK);
}

::android::hardware::Return<void> BpHwSehLight::ping(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_ping(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwSehLight::getDebugInfo(getDebugInfo_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getDebugInfo(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwSehLight::notifySyspropsChanged(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_notifySyspropsChanged(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwSehLight::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
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


BnHwSehLight::BnHwSehLight(const ::android::sp<ISehLight> &_hidl_impl)
        : ::android::hidl::base::V1_0::BnHwBase(_hidl_impl, "vendor.samsung.hardware.light@3.0", "ISehLight") { 
            _hidl_mImpl = _hidl_impl;
            auto prio = ::android::hardware::getMinSchedulerPolicy(_hidl_impl);
            mSchedPolicy = prio.sched_policy;
            mSchedPriority = prio.prio;
            setRequestingSid(::android::hardware::getRequestingSid(_hidl_impl));
}

BnHwSehLight::~BnHwSehLight() {
    ::android::hardware::details::gBnMap->eraseIfEqual(_hidl_mImpl.get(), this);
}

// Methods from ::vendor::samsung::hardware::light::V3_0::ISehLight follow.
::android::status_t BnHwSehLight::_hidl_sehSetLight(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwSehLight::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::vendor::samsung::hardware::light::V3_0::SehType i;
    ::vendor::samsung::hardware::light::V3_0::SehLightState* sehLightState;

    _hidl_err = _hidl_data.readUint32((uint32_t *)&i);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_sehLightState_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*sehLightState), &_hidl_sehLightState_parent,  const_cast<const void**>(reinterpret_cast<void **>(&sehLightState)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::ISehLight::sehSetLight::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&i);
        _hidl_args.push_back((void *)sehLightState);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "vendor.samsung.hardware.light", "3.0", "ISehLight", "sehSetLight", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::light::V2_0::Status _hidl_out_status = static_cast<ISehLight*>(_hidl_this->getImpl().get())->sehSetLight(i, *sehLightState);

    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_status);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

_hidl_error:
    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&_hidl_out_status);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "vendor.samsung.hardware.light", "3.0", "ISehLight", "sehSetLight", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}


// Methods from ::android::hardware::light::V2_0::ILight follow.

// Methods from ::vendor::samsung::hardware::light::V3_0::ISehLight follow.

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BnHwSehLight::ping() {
    return ::android::hardware::Void();
}
::android::hardware::Return<void> BnHwSehLight::getDebugInfo(getDebugInfo_cb _hidl_cb) {
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

::android::status_t BnHwSehLight::onTransact(
        uint32_t _hidl_code,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        uint32_t _hidl_flags,
        TransactCallback _hidl_cb) {
    ::android::status_t _hidl_err = ::android::OK;

    switch (_hidl_code) {
        case 1 /* setLight */:
        {
            _hidl_err = ::android::hardware::light::V2_0::BnHwLight::_hidl_setLight(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 2 /* getSupportedTypes */:
        {
            _hidl_err = ::android::hardware::light::V2_0::BnHwLight::_hidl_getSupportedTypes(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 3 /* sehSetLight */:
        {
            _hidl_err = ::vendor::samsung::hardware::light::V3_0::BnHwSehLight::_hidl_sehSetLight(this, _hidl_data, _hidl_reply, _hidl_cb);
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

BsSehLight::BsSehLight(const ::android::sp<::vendor::samsung::hardware::light::V3_0::ISehLight> impl) : ::android::hardware::details::HidlInstrumentor("vendor.samsung.hardware.light@3.0", "ISehLight"), mImpl(impl) {
    mOnewayQueue.start(3000 /* similar limit to binderized */);
}

::android::hardware::Return<void> BsSehLight::addOnewayTask(std::function<void(void)> fun) {
    if (!mOnewayQueue.push(fun)) {
        return ::android::hardware::Status::fromExceptionCode(
                ::android::hardware::Status::EX_TRANSACTION_FAILED,
                "Passthrough oneway function queue exceeds maximum size.");
    }
    return ::android::hardware::Status();
}

::android::sp<ISehLight> ISehLight::tryGetService(const std::string &serviceName, const bool getStub) {
    return ::android::hardware::details::getServiceInternal<BpHwSehLight>(serviceName, false, getStub);
}

::android::sp<ISehLight> ISehLight::getService(const std::string &serviceName, const bool getStub) {
    return ::android::hardware::details::getServiceInternal<BpHwSehLight>(serviceName, true, getStub);
}

::android::status_t ISehLight::registerAsService(const std::string &serviceName) {
    return ::android::hardware::details::registerAsServiceInternal(this, serviceName);
}

bool ISehLight::registerForNotifications(
        const std::string &serviceName,
        const ::android::sp<::android::hidl::manager::V1_0::IServiceNotification> &notification) {
    const ::android::sp<::android::hidl::manager::V1_0::IServiceManager> sm
            = ::android::hardware::defaultServiceManager();
    if (sm == nullptr) {
        return false;
    }
    ::android::hardware::Return<bool> success =
            sm->registerForNotifications("vendor.samsung.hardware.light@3.0::ISehLight",
                    serviceName, notification);
    return success.isOk() && success;
}

static_assert(sizeof(::android::hardware::MQDescriptor<char, ::android::hardware::kSynchronizedReadWrite>) == 32, "wrong size");
static_assert(sizeof(::android::hardware::hidl_handle) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_memory) == 40, "wrong size");
static_assert(sizeof(::android::hardware::hidl_string) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_vec<char>) == 16, "wrong size");

}  // namespace V3_0
}  // namespace light
}  // namespace hardware
}  // namespace samsung
}  // namespace vendor
