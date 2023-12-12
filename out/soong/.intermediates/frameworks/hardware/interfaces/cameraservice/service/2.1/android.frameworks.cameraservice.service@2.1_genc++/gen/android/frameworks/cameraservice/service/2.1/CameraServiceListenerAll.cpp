#define LOG_TAG "android.frameworks.cameraservice.service@2.1::CameraServiceListener"

#include <log/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <hidl/Static.h>
#include <hwbinder/ProcessState.h>
#include <utils/Trace.h>
#include <android/hidl/manager/1.0/IServiceManager.h>
#include <android/frameworks/cameraservice/service/2.1/BpHwCameraServiceListener.h>
#include <android/frameworks/cameraservice/service/2.1/BnHwCameraServiceListener.h>
#include <android/frameworks/cameraservice/service/2.1/BsCameraServiceListener.h>
#include <android/frameworks/cameraservice/service/2.0/BpHwCameraServiceListener.h>
#include <android/hidl/base/1.0/BpHwBase.h>
#include <hidl/ServiceManagement.h>

namespace android {
namespace frameworks {
namespace cameraservice {
namespace service {
namespace V2_1 {

const char* ICameraServiceListener::descriptor("android.frameworks.cameraservice.service@2.1::ICameraServiceListener");

__attribute__((constructor)) static void static_constructor() {
    ::android::hardware::details::getBnConstructorMap().set(ICameraServiceListener::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hardware::IBinder> {
                return new BnHwCameraServiceListener(static_cast<ICameraServiceListener *>(iIntf));
            });
    ::android::hardware::details::getBsConstructorMap().set(ICameraServiceListener::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hidl::base::V1_0::IBase> {
                return new BsCameraServiceListener(static_cast<ICameraServiceListener *>(iIntf));
            });
}

__attribute__((destructor))static void static_destructor() {
    ::android::hardware::details::getBnConstructorMap().erase(ICameraServiceListener::descriptor);
    ::android::hardware::details::getBsConstructorMap().erase(ICameraServiceListener::descriptor);
}

// Methods from ::android::frameworks::cameraservice::service::V2_0::ICameraServiceListener follow.
// no default implementation for: ::android::hardware::Return<void> ICameraServiceListener::onStatusChanged(const ::android::frameworks::cameraservice::service::V2_0::CameraStatusAndId& statusAndId)

// Methods from ::android::frameworks::cameraservice::service::V2_1::ICameraServiceListener follow.
// no default implementation for: ::android::hardware::Return<void> ICameraServiceListener::onPhysicalCameraStatusChanged(const ::android::frameworks::cameraservice::service::V2_1::PhysicalCameraStatusAndId& statusAndId)

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> ICameraServiceListener::interfaceChain(interfaceChain_cb _hidl_cb){
    _hidl_cb({
        ::android::frameworks::cameraservice::service::V2_1::ICameraServiceListener::descriptor,
        ::android::frameworks::cameraservice::service::V2_0::ICameraServiceListener::descriptor,
        ::android::hidl::base::V1_0::IBase::descriptor,
    });
    return ::android::hardware::Void();
}

::android::hardware::Return<void> ICameraServiceListener::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    (void)fd;
    (void)options;
    return ::android::hardware::Void();
}

::android::hardware::Return<void> ICameraServiceListener::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    _hidl_cb(::android::frameworks::cameraservice::service::V2_1::ICameraServiceListener::descriptor);
    return ::android::hardware::Void();
}

::android::hardware::Return<void> ICameraServiceListener::getHashChain(getHashChain_cb _hidl_cb){
    _hidl_cb({
        (uint8_t[32]){57,45,152,237,82,142,189,94,225,76,158,101,239,99,60,187,238,179,60,116,229,171,27,226,207,216,168,101,172,76,156,134} /* 392d98ed528ebd5ee14c9e65ef633cbbeeb33c74e5ab1be2cfd8a865ac4c9c86 */,
        (uint8_t[32]){124,79,9,136,140,135,90,244,68,231,151,139,199,205,255,156,255,130,250,112,42,36,201,154,29,169,60,148,159,190,18,219} /* 7c4f09888c875af444e7978bc7cdff9cff82fa702a24c99a1da93c949fbe12db */,
        (uint8_t[32]){236,127,215,158,208,45,250,133,188,73,148,38,173,174,62,190,35,239,5,36,243,205,105,87,19,147,36,184,59,24,202,76} /* ec7fd79ed02dfa85bc499426adae3ebe23ef0524f3cd6957139324b83b18ca4c */});
    return ::android::hardware::Void();
}

::android::hardware::Return<void> ICameraServiceListener::setHALInstrumentation(){
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> ICameraServiceListener::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    (void)cookie;
    return (recipient != nullptr);
}

::android::hardware::Return<void> ICameraServiceListener::ping(){
    return ::android::hardware::Void();
}

::android::hardware::Return<void> ICameraServiceListener::getDebugInfo(getDebugInfo_cb _hidl_cb){
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

::android::hardware::Return<void> ICameraServiceListener::notifySyspropsChanged(){
    ::android::report_sysprop_change();
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> ICameraServiceListener::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
    return (recipient != nullptr);
}


::android::hardware::Return<::android::sp<::android::frameworks::cameraservice::service::V2_1::ICameraServiceListener>> ICameraServiceListener::castFrom(const ::android::sp<::android::frameworks::cameraservice::service::V2_1::ICameraServiceListener>& parent, bool /* emitError */) {
    return parent;
}

::android::hardware::Return<::android::sp<::android::frameworks::cameraservice::service::V2_1::ICameraServiceListener>> ICameraServiceListener::castFrom(const ::android::sp<::android::frameworks::cameraservice::service::V2_0::ICameraServiceListener>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<ICameraServiceListener, ::android::frameworks::cameraservice::service::V2_0::ICameraServiceListener, BpHwCameraServiceListener>(
            parent, "android.frameworks.cameraservice.service@2.1::ICameraServiceListener", emitError);
}

::android::hardware::Return<::android::sp<::android::frameworks::cameraservice::service::V2_1::ICameraServiceListener>> ICameraServiceListener::castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<ICameraServiceListener, ::android::hidl::base::V1_0::IBase, BpHwCameraServiceListener>(
            parent, "android.frameworks.cameraservice.service@2.1::ICameraServiceListener", emitError);
}

BpHwCameraServiceListener::BpHwCameraServiceListener(const ::android::sp<::android::hardware::IBinder> &_hidl_impl)
        : BpInterface<ICameraServiceListener>(_hidl_impl),
          ::android::hardware::details::HidlInstrumentor("android.frameworks.cameraservice.service@2.1", "ICameraServiceListener") {
}

void BpHwCameraServiceListener::onLastStrongRef(const void* id) {
    {
        std::unique_lock<std::mutex> lock(_hidl_mMutex);
        _hidl_mDeathRecipients.clear();
    }

    BpInterface<ICameraServiceListener>::onLastStrongRef(id);
}
// Methods from ::android::frameworks::cameraservice::service::V2_1::ICameraServiceListener follow.
::android::hardware::Return<void> BpHwCameraServiceListener::_hidl_onPhysicalCameraStatusChanged(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::frameworks::cameraservice::service::V2_1::PhysicalCameraStatusAndId& statusAndId) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::ICameraServiceListener::onPhysicalCameraStatusChanged::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&statusAndId);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.frameworks.cameraservice.service", "2.1", "ICameraServiceListener", "onPhysicalCameraStatusChanged", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwCameraServiceListener::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_statusAndId_parent;

    _hidl_err = _hidl_data.writeBuffer(&statusAndId, sizeof(statusAndId), &_hidl_statusAndId_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = writeEmbeddedToParcel(
            statusAndId,
            &_hidl_data,
            _hidl_statusAndId_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(2 /* onPhysicalCameraStatusChanged */, _hidl_data, &_hidl_reply, 0 /* flags */ | 1u /* oneway */);
    if (_hidl_transact_err != ::android::OK) 
    {
        _hidl_err = _hidl_transact_err;
        goto _hidl_error;
    }

    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.frameworks.cameraservice.service", "2.1", "ICameraServiceListener", "onPhysicalCameraStatusChanged", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<void>();

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<void>(_hidl_status);
}


// Methods from ::android::frameworks::cameraservice::service::V2_0::ICameraServiceListener follow.
::android::hardware::Return<void> BpHwCameraServiceListener::onStatusChanged(const ::android::frameworks::cameraservice::service::V2_0::CameraStatusAndId& statusAndId){
    ::android::hardware::Return<void>  _hidl_out = ::android::frameworks::cameraservice::service::V2_0::BpHwCameraServiceListener::_hidl_onStatusChanged(this, this, statusAndId);

    return _hidl_out;
}


// Methods from ::android::frameworks::cameraservice::service::V2_1::ICameraServiceListener follow.
::android::hardware::Return<void> BpHwCameraServiceListener::onPhysicalCameraStatusChanged(const ::android::frameworks::cameraservice::service::V2_1::PhysicalCameraStatusAndId& statusAndId){
    ::android::hardware::Return<void>  _hidl_out = ::android::frameworks::cameraservice::service::V2_1::BpHwCameraServiceListener::_hidl_onPhysicalCameraStatusChanged(this, this, statusAndId);

    return _hidl_out;
}


// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BpHwCameraServiceListener::interfaceChain(interfaceChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwCameraServiceListener::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_debug(this, this, fd, options);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwCameraServiceListener::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceDescriptor(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwCameraServiceListener::getHashChain(getHashChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getHashChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwCameraServiceListener::setHALInstrumentation(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_setHALInstrumentation(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwCameraServiceListener::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    ::android::hardware::ProcessState::self()->startThreadPool();
    ::android::hardware::hidl_binder_death_recipient *binder_recipient = new ::android::hardware::hidl_binder_death_recipient(recipient, cookie, this);
    std::unique_lock<std::mutex> lock(_hidl_mMutex);
    _hidl_mDeathRecipients.push_back(binder_recipient);
    return (remote()->linkToDeath(binder_recipient) == ::android::OK);
}

::android::hardware::Return<void> BpHwCameraServiceListener::ping(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_ping(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwCameraServiceListener::getDebugInfo(getDebugInfo_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getDebugInfo(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwCameraServiceListener::notifySyspropsChanged(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_notifySyspropsChanged(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwCameraServiceListener::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
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


BnHwCameraServiceListener::BnHwCameraServiceListener(const ::android::sp<ICameraServiceListener> &_hidl_impl)
        : ::android::hidl::base::V1_0::BnHwBase(_hidl_impl, "android.frameworks.cameraservice.service@2.1", "ICameraServiceListener") { 
            _hidl_mImpl = _hidl_impl;
            auto prio = ::android::hardware::getMinSchedulerPolicy(_hidl_impl);
            mSchedPolicy = prio.sched_policy;
            mSchedPriority = prio.prio;
            setRequestingSid(::android::hardware::getRequestingSid(_hidl_impl));
}

BnHwCameraServiceListener::~BnHwCameraServiceListener() {
    ::android::hardware::details::gBnMap->eraseIfEqual(_hidl_mImpl.get(), this);
}

// Methods from ::android::frameworks::cameraservice::service::V2_1::ICameraServiceListener follow.
::android::status_t BnHwCameraServiceListener::_hidl_onPhysicalCameraStatusChanged(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwCameraServiceListener::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::frameworks::cameraservice::service::V2_1::PhysicalCameraStatusAndId* statusAndId;

    size_t _hidl_statusAndId_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*statusAndId), &_hidl_statusAndId_parent,  const_cast<const void**>(reinterpret_cast<void **>(&statusAndId)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::frameworks::cameraservice::service::V2_1::PhysicalCameraStatusAndId &>(*statusAndId),
            _hidl_data,
            _hidl_statusAndId_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::ICameraServiceListener::onPhysicalCameraStatusChanged::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)statusAndId);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.frameworks.cameraservice.service", "2.1", "ICameraServiceListener", "onPhysicalCameraStatusChanged", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Return<void> _hidl_ret = static_cast<ICameraServiceListener*>(_hidl_this->getImpl().get())->onPhysicalCameraStatusChanged(*statusAndId);

    (void) _hidl_cb;

    atrace_end(ATRACE_TAG_HAL);
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.frameworks.cameraservice.service", "2.1", "ICameraServiceListener", "onPhysicalCameraStatusChanged", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    _hidl_ret.assertOk();
    ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

    return _hidl_err;
}


// Methods from ::android::frameworks::cameraservice::service::V2_0::ICameraServiceListener follow.

// Methods from ::android::frameworks::cameraservice::service::V2_1::ICameraServiceListener follow.

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BnHwCameraServiceListener::ping() {
    return ::android::hardware::Void();
}
::android::hardware::Return<void> BnHwCameraServiceListener::getDebugInfo(getDebugInfo_cb _hidl_cb) {
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

::android::status_t BnHwCameraServiceListener::onTransact(
        uint32_t _hidl_code,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        uint32_t _hidl_flags,
        TransactCallback _hidl_cb) {
    ::android::status_t _hidl_err = ::android::OK;

    switch (_hidl_code) {
        case 1 /* onStatusChanged */:
        {
            _hidl_err = ::android::frameworks::cameraservice::service::V2_0::BnHwCameraServiceListener::_hidl_onStatusChanged(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 2 /* onPhysicalCameraStatusChanged */:
        {
            _hidl_err = ::android::frameworks::cameraservice::service::V2_1::BnHwCameraServiceListener::_hidl_onPhysicalCameraStatusChanged(this, _hidl_data, _hidl_reply, _hidl_cb);
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

BsCameraServiceListener::BsCameraServiceListener(const ::android::sp<::android::frameworks::cameraservice::service::V2_1::ICameraServiceListener> impl) : ::android::hardware::details::HidlInstrumentor("android.frameworks.cameraservice.service@2.1", "ICameraServiceListener"), mImpl(impl) {
    mOnewayQueue.start(3000 /* similar limit to binderized */);
}

::android::hardware::Return<void> BsCameraServiceListener::addOnewayTask(std::function<void(void)> fun) {
    if (!mOnewayQueue.push(fun)) {
        return ::android::hardware::Status::fromExceptionCode(
                ::android::hardware::Status::EX_TRANSACTION_FAILED,
                "Passthrough oneway function queue exceeds maximum size.");
    }
    return ::android::hardware::Status();
}

::android::sp<ICameraServiceListener> ICameraServiceListener::tryGetService(const std::string &serviceName, const bool getStub) {
    return ::android::hardware::details::getServiceInternal<BpHwCameraServiceListener>(serviceName, false, getStub);
}

::android::sp<ICameraServiceListener> ICameraServiceListener::getService(const std::string &serviceName, const bool getStub) {
    return ::android::hardware::details::getServiceInternal<BpHwCameraServiceListener>(serviceName, true, getStub);
}

::android::status_t ICameraServiceListener::registerAsService(const std::string &serviceName) {
    return ::android::hardware::details::registerAsServiceInternal(this, serviceName);
}

bool ICameraServiceListener::registerForNotifications(
        const std::string &serviceName,
        const ::android::sp<::android::hidl::manager::V1_0::IServiceNotification> &notification) {
    const ::android::sp<::android::hidl::manager::V1_0::IServiceManager> sm
            = ::android::hardware::defaultServiceManager();
    if (sm == nullptr) {
        return false;
    }
    ::android::hardware::Return<bool> success =
            sm->registerForNotifications("android.frameworks.cameraservice.service@2.1::ICameraServiceListener",
                    serviceName, notification);
    return success.isOk() && success;
}

static_assert(sizeof(::android::hardware::MQDescriptor<char, ::android::hardware::kSynchronizedReadWrite>) == 32, "wrong size");
static_assert(sizeof(::android::hardware::hidl_handle) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_memory) == 40, "wrong size");
static_assert(sizeof(::android::hardware::hidl_string) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_vec<char>) == 16, "wrong size");

}  // namespace V2_1
}  // namespace service
}  // namespace cameraservice
}  // namespace frameworks
}  // namespace android
