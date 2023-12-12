#define LOG_TAG "android.frameworks.cameraservice.service@2.2::CameraService"

#include <log/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <hidl/Static.h>
#include <hwbinder/ProcessState.h>
#include <utils/Trace.h>
#include <android/hidl/manager/1.0/IServiceManager.h>
#include <android/frameworks/cameraservice/service/2.2/BpHwCameraService.h>
#include <android/frameworks/cameraservice/service/2.2/BnHwCameraService.h>
#include <android/frameworks/cameraservice/service/2.2/BsCameraService.h>
#include <android/frameworks/cameraservice/service/2.1/BpHwCameraService.h>
#include <android/frameworks/cameraservice/service/2.0/BpHwCameraService.h>
#include <android/hidl/base/1.0/BpHwBase.h>
#include <hidl/ServiceManagement.h>

namespace android {
namespace frameworks {
namespace cameraservice {
namespace service {
namespace V2_2 {

const char* ICameraService::descriptor("android.frameworks.cameraservice.service@2.2::ICameraService");

__attribute__((constructor)) static void static_constructor() {
    ::android::hardware::details::getBnConstructorMap().set(ICameraService::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hardware::IBinder> {
                return new BnHwCameraService(static_cast<ICameraService *>(iIntf));
            });
    ::android::hardware::details::getBsConstructorMap().set(ICameraService::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hidl::base::V1_0::IBase> {
                return new BsCameraService(static_cast<ICameraService *>(iIntf));
            });
}

__attribute__((destructor))static void static_destructor() {
    ::android::hardware::details::getBnConstructorMap().erase(ICameraService::descriptor);
    ::android::hardware::details::getBsConstructorMap().erase(ICameraService::descriptor);
}

// Methods from ::android::frameworks::cameraservice::service::V2_0::ICameraService follow.
// no default implementation for: ::android::hardware::Return<void> ICameraService::connectDevice(const ::android::sp<::android::frameworks::cameraservice::device::V2_0::ICameraDeviceCallback>& callback, const ::android::hardware::hidl_string& cameraId, connectDevice_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> ICameraService::addListener(const ::android::sp<::android::frameworks::cameraservice::service::V2_0::ICameraServiceListener>& listener, addListener_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<::android::frameworks::cameraservice::common::V2_0::Status> ICameraService::removeListener(const ::android::sp<::android::frameworks::cameraservice::service::V2_0::ICameraServiceListener>& listener)
// no default implementation for: ::android::hardware::Return<void> ICameraService::getCameraCharacteristics(const ::android::hardware::hidl_string& cameraId, getCameraCharacteristics_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> ICameraService::getCameraVendorTagSections(getCameraVendorTagSections_cb _hidl_cb)

// Methods from ::android::frameworks::cameraservice::service::V2_1::ICameraService follow.
// no default implementation for: ::android::hardware::Return<void> ICameraService::addListener_2_1(const ::android::sp<::android::frameworks::cameraservice::service::V2_1::ICameraServiceListener>& listener, addListener_2_1_cb _hidl_cb)

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> ICameraService::interfaceChain(interfaceChain_cb _hidl_cb){
    _hidl_cb({
        ::android::frameworks::cameraservice::service::V2_2::ICameraService::descriptor,
        ::android::frameworks::cameraservice::service::V2_1::ICameraService::descriptor,
        ::android::frameworks::cameraservice::service::V2_0::ICameraService::descriptor,
        ::android::hidl::base::V1_0::IBase::descriptor,
    });
    return ::android::hardware::Void();
}

::android::hardware::Return<void> ICameraService::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    (void)fd;
    (void)options;
    return ::android::hardware::Void();
}

::android::hardware::Return<void> ICameraService::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    _hidl_cb(::android::frameworks::cameraservice::service::V2_2::ICameraService::descriptor);
    return ::android::hardware::Void();
}

::android::hardware::Return<void> ICameraService::getHashChain(getHashChain_cb _hidl_cb){
    _hidl_cb({
        (uint8_t[32]){41,89,182,242,181,78,117,198,150,95,109,220,144,212,200,160,103,61,85,133,250,154,173,42,176,63,1,241,183,107,25,69} /* 2959b6f2b54e75c6965f6ddc90d4c8a0673d5585fa9aad2ab03f01f1b76b1945 */,
        (uint8_t[32]){245,188,218,14,85,210,207,42,143,157,94,188,67,109,111,150,126,33,8,53,220,74,196,234,1,76,209,43,196,118,99,158} /* f5bcda0e55d2cf2a8f9d5ebc436d6f967e210835dc4ac4ea014cd12bc476639e */,
        (uint8_t[32]){180,93,196,152,235,113,60,162,253,216,235,30,165,127,171,203,109,203,179,46,37,166,78,237,56,46,112,12,244,158,110,51} /* b45dc498eb713ca2fdd8eb1ea57fabcb6dcbb32e25a64eed382e700cf49e6e33 */,
        (uint8_t[32]){236,127,215,158,208,45,250,133,188,73,148,38,173,174,62,190,35,239,5,36,243,205,105,87,19,147,36,184,59,24,202,76} /* ec7fd79ed02dfa85bc499426adae3ebe23ef0524f3cd6957139324b83b18ca4c */});
    return ::android::hardware::Void();
}

::android::hardware::Return<void> ICameraService::setHALInstrumentation(){
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> ICameraService::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    (void)cookie;
    return (recipient != nullptr);
}

::android::hardware::Return<void> ICameraService::ping(){
    return ::android::hardware::Void();
}

::android::hardware::Return<void> ICameraService::getDebugInfo(getDebugInfo_cb _hidl_cb){
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

::android::hardware::Return<void> ICameraService::notifySyspropsChanged(){
    ::android::report_sysprop_change();
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> ICameraService::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
    return (recipient != nullptr);
}


::android::hardware::Return<::android::sp<::android::frameworks::cameraservice::service::V2_2::ICameraService>> ICameraService::castFrom(const ::android::sp<::android::frameworks::cameraservice::service::V2_2::ICameraService>& parent, bool /* emitError */) {
    return parent;
}

::android::hardware::Return<::android::sp<::android::frameworks::cameraservice::service::V2_2::ICameraService>> ICameraService::castFrom(const ::android::sp<::android::frameworks::cameraservice::service::V2_1::ICameraService>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<ICameraService, ::android::frameworks::cameraservice::service::V2_1::ICameraService, BpHwCameraService>(
            parent, "android.frameworks.cameraservice.service@2.2::ICameraService", emitError);
}

::android::hardware::Return<::android::sp<::android::frameworks::cameraservice::service::V2_2::ICameraService>> ICameraService::castFrom(const ::android::sp<::android::frameworks::cameraservice::service::V2_0::ICameraService>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<ICameraService, ::android::frameworks::cameraservice::service::V2_0::ICameraService, BpHwCameraService>(
            parent, "android.frameworks.cameraservice.service@2.2::ICameraService", emitError);
}

::android::hardware::Return<::android::sp<::android::frameworks::cameraservice::service::V2_2::ICameraService>> ICameraService::castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<ICameraService, ::android::hidl::base::V1_0::IBase, BpHwCameraService>(
            parent, "android.frameworks.cameraservice.service@2.2::ICameraService", emitError);
}

BpHwCameraService::BpHwCameraService(const ::android::sp<::android::hardware::IBinder> &_hidl_impl)
        : BpInterface<ICameraService>(_hidl_impl),
          ::android::hardware::details::HidlInstrumentor("android.frameworks.cameraservice.service@2.2", "ICameraService") {
}

void BpHwCameraService::onLastStrongRef(const void* id) {
    {
        std::unique_lock<std::mutex> lock(_hidl_mMutex);
        _hidl_mDeathRecipients.clear();
    }

    BpInterface<ICameraService>::onLastStrongRef(id);
}

// Methods from ::android::frameworks::cameraservice::service::V2_0::ICameraService follow.
::android::hardware::Return<void> BpHwCameraService::connectDevice(const ::android::sp<::android::frameworks::cameraservice::device::V2_0::ICameraDeviceCallback>& callback, const ::android::hardware::hidl_string& cameraId, connectDevice_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::frameworks::cameraservice::service::V2_0::BpHwCameraService::_hidl_connectDevice(this, this, callback, cameraId, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwCameraService::addListener(const ::android::sp<::android::frameworks::cameraservice::service::V2_0::ICameraServiceListener>& listener, addListener_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::frameworks::cameraservice::service::V2_0::BpHwCameraService::_hidl_addListener(this, this, listener, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<::android::frameworks::cameraservice::common::V2_0::Status> BpHwCameraService::removeListener(const ::android::sp<::android::frameworks::cameraservice::service::V2_0::ICameraServiceListener>& listener){
    ::android::hardware::Return<::android::frameworks::cameraservice::common::V2_0::Status>  _hidl_out = ::android::frameworks::cameraservice::service::V2_0::BpHwCameraService::_hidl_removeListener(this, this, listener);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwCameraService::getCameraCharacteristics(const ::android::hardware::hidl_string& cameraId, getCameraCharacteristics_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::frameworks::cameraservice::service::V2_0::BpHwCameraService::_hidl_getCameraCharacteristics(this, this, cameraId, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwCameraService::getCameraVendorTagSections(getCameraVendorTagSections_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::frameworks::cameraservice::service::V2_0::BpHwCameraService::_hidl_getCameraVendorTagSections(this, this, _hidl_cb);

    return _hidl_out;
}


// Methods from ::android::frameworks::cameraservice::service::V2_1::ICameraService follow.
::android::hardware::Return<void> BpHwCameraService::addListener_2_1(const ::android::sp<::android::frameworks::cameraservice::service::V2_1::ICameraServiceListener>& listener, addListener_2_1_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::frameworks::cameraservice::service::V2_1::BpHwCameraService::_hidl_addListener_2_1(this, this, listener, _hidl_cb);

    return _hidl_out;
}


// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BpHwCameraService::interfaceChain(interfaceChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwCameraService::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_debug(this, this, fd, options);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwCameraService::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceDescriptor(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwCameraService::getHashChain(getHashChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getHashChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwCameraService::setHALInstrumentation(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_setHALInstrumentation(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwCameraService::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    ::android::hardware::ProcessState::self()->startThreadPool();
    ::android::hardware::hidl_binder_death_recipient *binder_recipient = new ::android::hardware::hidl_binder_death_recipient(recipient, cookie, this);
    std::unique_lock<std::mutex> lock(_hidl_mMutex);
    _hidl_mDeathRecipients.push_back(binder_recipient);
    return (remote()->linkToDeath(binder_recipient) == ::android::OK);
}

::android::hardware::Return<void> BpHwCameraService::ping(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_ping(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwCameraService::getDebugInfo(getDebugInfo_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getDebugInfo(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwCameraService::notifySyspropsChanged(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_notifySyspropsChanged(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwCameraService::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
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


BnHwCameraService::BnHwCameraService(const ::android::sp<ICameraService> &_hidl_impl)
        : ::android::hidl::base::V1_0::BnHwBase(_hidl_impl, "android.frameworks.cameraservice.service@2.2", "ICameraService") { 
            _hidl_mImpl = _hidl_impl;
            auto prio = ::android::hardware::getMinSchedulerPolicy(_hidl_impl);
            mSchedPolicy = prio.sched_policy;
            mSchedPriority = prio.prio;
            setRequestingSid(::android::hardware::getRequestingSid(_hidl_impl));
}

BnHwCameraService::~BnHwCameraService() {
    ::android::hardware::details::gBnMap->eraseIfEqual(_hidl_mImpl.get(), this);
}


// Methods from ::android::frameworks::cameraservice::service::V2_0::ICameraService follow.

// Methods from ::android::frameworks::cameraservice::service::V2_1::ICameraService follow.

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BnHwCameraService::ping() {
    return ::android::hardware::Void();
}
::android::hardware::Return<void> BnHwCameraService::getDebugInfo(getDebugInfo_cb _hidl_cb) {
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

::android::status_t BnHwCameraService::onTransact(
        uint32_t _hidl_code,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        uint32_t _hidl_flags,
        TransactCallback _hidl_cb) {
    ::android::status_t _hidl_err = ::android::OK;

    switch (_hidl_code) {
        case 1 /* connectDevice */:
        {
            _hidl_err = ::android::frameworks::cameraservice::service::V2_0::BnHwCameraService::_hidl_connectDevice(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 2 /* addListener */:
        {
            _hidl_err = ::android::frameworks::cameraservice::service::V2_0::BnHwCameraService::_hidl_addListener(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 3 /* removeListener */:
        {
            _hidl_err = ::android::frameworks::cameraservice::service::V2_0::BnHwCameraService::_hidl_removeListener(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 4 /* getCameraCharacteristics */:
        {
            _hidl_err = ::android::frameworks::cameraservice::service::V2_0::BnHwCameraService::_hidl_getCameraCharacteristics(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 5 /* getCameraVendorTagSections */:
        {
            _hidl_err = ::android::frameworks::cameraservice::service::V2_0::BnHwCameraService::_hidl_getCameraVendorTagSections(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 6 /* addListener_2_1 */:
        {
            _hidl_err = ::android::frameworks::cameraservice::service::V2_1::BnHwCameraService::_hidl_addListener_2_1(this, _hidl_data, _hidl_reply, _hidl_cb);
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

BsCameraService::BsCameraService(const ::android::sp<::android::frameworks::cameraservice::service::V2_2::ICameraService> impl) : ::android::hardware::details::HidlInstrumentor("android.frameworks.cameraservice.service@2.2", "ICameraService"), mImpl(impl) {
    mOnewayQueue.start(3000 /* similar limit to binderized */);
}

::android::hardware::Return<void> BsCameraService::addOnewayTask(std::function<void(void)> fun) {
    if (!mOnewayQueue.push(fun)) {
        return ::android::hardware::Status::fromExceptionCode(
                ::android::hardware::Status::EX_TRANSACTION_FAILED,
                "Passthrough oneway function queue exceeds maximum size.");
    }
    return ::android::hardware::Status();
}

::android::sp<ICameraService> ICameraService::tryGetService(const std::string &serviceName, const bool getStub) {
    return ::android::hardware::details::getServiceInternal<BpHwCameraService>(serviceName, false, getStub);
}

::android::sp<ICameraService> ICameraService::getService(const std::string &serviceName, const bool getStub) {
    return ::android::hardware::details::getServiceInternal<BpHwCameraService>(serviceName, true, getStub);
}

::android::status_t ICameraService::registerAsService(const std::string &serviceName) {
    return ::android::hardware::details::registerAsServiceInternal(this, serviceName);
}

bool ICameraService::registerForNotifications(
        const std::string &serviceName,
        const ::android::sp<::android::hidl::manager::V1_0::IServiceNotification> &notification) {
    const ::android::sp<::android::hidl::manager::V1_0::IServiceManager> sm
            = ::android::hardware::defaultServiceManager();
    if (sm == nullptr) {
        return false;
    }
    ::android::hardware::Return<bool> success =
            sm->registerForNotifications("android.frameworks.cameraservice.service@2.2::ICameraService",
                    serviceName, notification);
    return success.isOk() && success;
}

static_assert(sizeof(::android::hardware::MQDescriptor<char, ::android::hardware::kSynchronizedReadWrite>) == 32, "wrong size");
static_assert(sizeof(::android::hardware::hidl_handle) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_memory) == 40, "wrong size");
static_assert(sizeof(::android::hardware::hidl_string) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_vec<char>) == 16, "wrong size");

}  // namespace V2_2
}  // namespace service
}  // namespace cameraservice
}  // namespace frameworks
}  // namespace android
