#define LOG_TAG "android.hardware.gnss@2.0::GnssDebug"

#include <log/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <hidl/Static.h>
#include <hwbinder/ProcessState.h>
#include <utils/Trace.h>
#include <android/hidl/manager/1.0/IServiceManager.h>
#include <android/hardware/gnss/2.0/BpHwGnssDebug.h>
#include <android/hardware/gnss/2.0/BnHwGnssDebug.h>
#include <android/hardware/gnss/2.0/BsGnssDebug.h>
#include <android/hardware/gnss/1.0/BpHwGnssDebug.h>
#include <android/hidl/base/1.0/BpHwBase.h>
#include <hidl/ServiceManagement.h>

namespace android {
namespace hardware {
namespace gnss {
namespace V2_0 {

::android::status_t readEmbeddedFromParcel(
        const IGnssDebug::IGnssDebug::DebugData &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_satelliteDataArray_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::gnss::V2_0::IGnssDebug::SatelliteData> &>(obj.satelliteDataArray),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::gnss::V2_0::IGnssDebug::DebugData, satelliteDataArray), &_hidl_satelliteDataArray_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const IGnssDebug::IGnssDebug::DebugData &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_satelliteDataArray_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.satelliteDataArray,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::gnss::V2_0::IGnssDebug::DebugData, satelliteDataArray), &_hidl_satelliteDataArray_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

const char* IGnssDebug::descriptor("android.hardware.gnss@2.0::IGnssDebug");

__attribute__((constructor)) static void static_constructor() {
    ::android::hardware::details::getBnConstructorMap().set(IGnssDebug::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hardware::IBinder> {
                return new BnHwGnssDebug(static_cast<IGnssDebug *>(iIntf));
            });
    ::android::hardware::details::getBsConstructorMap().set(IGnssDebug::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hidl::base::V1_0::IBase> {
                return new BsGnssDebug(static_cast<IGnssDebug *>(iIntf));
            });
}

__attribute__((destructor))static void static_destructor() {
    ::android::hardware::details::getBnConstructorMap().erase(IGnssDebug::descriptor);
    ::android::hardware::details::getBsConstructorMap().erase(IGnssDebug::descriptor);
}

// Methods from ::android::hardware::gnss::V1_0::IGnssDebug follow.
// no default implementation for: ::android::hardware::Return<void> IGnssDebug::getDebugData(getDebugData_cb _hidl_cb)

// Methods from ::android::hardware::gnss::V2_0::IGnssDebug follow.
// no default implementation for: ::android::hardware::Return<void> IGnssDebug::getDebugData_2_0(getDebugData_2_0_cb _hidl_cb)

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> IGnssDebug::interfaceChain(interfaceChain_cb _hidl_cb){
    _hidl_cb({
        ::android::hardware::gnss::V2_0::IGnssDebug::descriptor,
        ::android::hardware::gnss::V1_0::IGnssDebug::descriptor,
        ::android::hidl::base::V1_0::IBase::descriptor,
    });
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IGnssDebug::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    (void)fd;
    (void)options;
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IGnssDebug::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    _hidl_cb(::android::hardware::gnss::V2_0::IGnssDebug::descriptor);
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IGnssDebug::getHashChain(getHashChain_cb _hidl_cb){
    _hidl_cb({
        (uint8_t[32]){182,112,186,226,171,133,23,51,98,144,83,46,54,69,2,180,219,145,32,52,13,117,71,76,204,132,66,177,177,93,106,183} /* b670bae2ab8517336290532e364502b4db9120340d75474ccc8442b1b15d6ab7 */,
        (uint8_t[32]){69,66,18,43,150,251,242,113,1,203,130,34,186,251,118,231,200,208,50,217,119,221,16,88,237,216,229,136,28,165,117,47} /* 4542122b96fbf27101cb8222bafb76e7c8d032d977dd1058edd8e5881ca5752f */,
        (uint8_t[32]){236,127,215,158,208,45,250,133,188,73,148,38,173,174,62,190,35,239,5,36,243,205,105,87,19,147,36,184,59,24,202,76} /* ec7fd79ed02dfa85bc499426adae3ebe23ef0524f3cd6957139324b83b18ca4c */});
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IGnssDebug::setHALInstrumentation(){
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> IGnssDebug::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    (void)cookie;
    return (recipient != nullptr);
}

::android::hardware::Return<void> IGnssDebug::ping(){
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IGnssDebug::getDebugInfo(getDebugInfo_cb _hidl_cb){
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

::android::hardware::Return<void> IGnssDebug::notifySyspropsChanged(){
    ::android::report_sysprop_change();
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> IGnssDebug::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
    return (recipient != nullptr);
}


::android::hardware::Return<::android::sp<::android::hardware::gnss::V2_0::IGnssDebug>> IGnssDebug::castFrom(const ::android::sp<::android::hardware::gnss::V2_0::IGnssDebug>& parent, bool /* emitError */) {
    return parent;
}

::android::hardware::Return<::android::sp<::android::hardware::gnss::V2_0::IGnssDebug>> IGnssDebug::castFrom(const ::android::sp<::android::hardware::gnss::V1_0::IGnssDebug>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<IGnssDebug, ::android::hardware::gnss::V1_0::IGnssDebug, BpHwGnssDebug>(
            parent, "android.hardware.gnss@2.0::IGnssDebug", emitError);
}

::android::hardware::Return<::android::sp<::android::hardware::gnss::V2_0::IGnssDebug>> IGnssDebug::castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<IGnssDebug, ::android::hidl::base::V1_0::IBase, BpHwGnssDebug>(
            parent, "android.hardware.gnss@2.0::IGnssDebug", emitError);
}

BpHwGnssDebug::BpHwGnssDebug(const ::android::sp<::android::hardware::IBinder> &_hidl_impl)
        : BpInterface<IGnssDebug>(_hidl_impl),
          ::android::hardware::details::HidlInstrumentor("android.hardware.gnss@2.0", "IGnssDebug") {
}

void BpHwGnssDebug::onLastStrongRef(const void* id) {
    {
        std::unique_lock<std::mutex> lock(_hidl_mMutex);
        _hidl_mDeathRecipients.clear();
    }

    BpInterface<IGnssDebug>::onLastStrongRef(id);
}
// Methods from ::android::hardware::gnss::V2_0::IGnssDebug follow.
::android::hardware::Return<void> BpHwGnssDebug::_hidl_getDebugData_2_0(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, getDebugData_2_0_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IGnssDebug::getDebugData_2_0::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.gnss", "2.0", "IGnssDebug", "getDebugData_2_0", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwGnssDebug::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(2 /* getDebugData_2_0 */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::gnss::V2_0::IGnssDebug::DebugData* _hidl_out_debugData;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        size_t _hidl__hidl_out_debugData_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_debugData), &_hidl__hidl_out_debugData_parent,  const_cast<const void**>(reinterpret_cast<void **>(&_hidl_out_debugData)));
        if (_hidl_err != ::android::OK) { return; }

        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::gnss::V2_0::IGnssDebug::DebugData &>(*_hidl_out_debugData),
                _hidl_reply,
                _hidl__hidl_out_debugData_parent,
                0 /* parentOffset */);

        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(*_hidl_out_debugData);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)_hidl_out_debugData);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.gnss", "2.0", "IGnssDebug", "getDebugData_2_0", &_hidl_args);
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


// Methods from ::android::hardware::gnss::V1_0::IGnssDebug follow.
::android::hardware::Return<void> BpHwGnssDebug::getDebugData(getDebugData_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::gnss::V1_0::BpHwGnssDebug::_hidl_getDebugData(this, this, _hidl_cb);

    return _hidl_out;
}


// Methods from ::android::hardware::gnss::V2_0::IGnssDebug follow.
::android::hardware::Return<void> BpHwGnssDebug::getDebugData_2_0(getDebugData_2_0_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::gnss::V2_0::BpHwGnssDebug::_hidl_getDebugData_2_0(this, this, _hidl_cb);

    return _hidl_out;
}


// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BpHwGnssDebug::interfaceChain(interfaceChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwGnssDebug::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_debug(this, this, fd, options);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwGnssDebug::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceDescriptor(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwGnssDebug::getHashChain(getHashChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getHashChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwGnssDebug::setHALInstrumentation(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_setHALInstrumentation(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwGnssDebug::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    ::android::hardware::ProcessState::self()->startThreadPool();
    ::android::hardware::hidl_binder_death_recipient *binder_recipient = new ::android::hardware::hidl_binder_death_recipient(recipient, cookie, this);
    std::unique_lock<std::mutex> lock(_hidl_mMutex);
    _hidl_mDeathRecipients.push_back(binder_recipient);
    return (remote()->linkToDeath(binder_recipient) == ::android::OK);
}

::android::hardware::Return<void> BpHwGnssDebug::ping(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_ping(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwGnssDebug::getDebugInfo(getDebugInfo_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getDebugInfo(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwGnssDebug::notifySyspropsChanged(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_notifySyspropsChanged(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwGnssDebug::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
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


BnHwGnssDebug::BnHwGnssDebug(const ::android::sp<IGnssDebug> &_hidl_impl)
        : ::android::hidl::base::V1_0::BnHwBase(_hidl_impl, "android.hardware.gnss@2.0", "IGnssDebug") { 
            _hidl_mImpl = _hidl_impl;
            auto prio = ::android::hardware::getMinSchedulerPolicy(_hidl_impl);
            mSchedPolicy = prio.sched_policy;
            mSchedPriority = prio.prio;
            setRequestingSid(::android::hardware::getRequestingSid(_hidl_impl));
}

BnHwGnssDebug::~BnHwGnssDebug() {
    ::android::hardware::details::gBnMap->eraseIfEqual(_hidl_mImpl.get(), this);
}

// Methods from ::android::hardware::gnss::V2_0::IGnssDebug follow.
::android::status_t BnHwGnssDebug::_hidl_getDebugData_2_0(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwGnssDebug::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IGnssDebug::getDebugData_2_0::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.gnss", "2.0", "IGnssDebug", "getDebugData_2_0", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IGnssDebug*>(_hidl_this->getImpl().get())->getDebugData_2_0([&](const auto &_hidl_out_debugData) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("getDebugData_2_0: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        size_t _hidl__hidl_out_debugData_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_debugData, sizeof(_hidl_out_debugData), &_hidl__hidl_out_debugData_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_err = writeEmbeddedToParcel(
                _hidl_out_debugData,
                _hidl_reply,
                _hidl__hidl_out_debugData_parent,
                0 /* parentOffset */);

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_debugData);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.gnss", "2.0", "IGnssDebug", "getDebugData_2_0", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("getDebugData_2_0: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}


// Methods from ::android::hardware::gnss::V1_0::IGnssDebug follow.

// Methods from ::android::hardware::gnss::V2_0::IGnssDebug follow.

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BnHwGnssDebug::ping() {
    return ::android::hardware::Void();
}
::android::hardware::Return<void> BnHwGnssDebug::getDebugInfo(getDebugInfo_cb _hidl_cb) {
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

::android::status_t BnHwGnssDebug::onTransact(
        uint32_t _hidl_code,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        uint32_t _hidl_flags,
        TransactCallback _hidl_cb) {
    ::android::status_t _hidl_err = ::android::OK;

    switch (_hidl_code) {
        case 1 /* getDebugData */:
        {
            _hidl_err = ::android::hardware::gnss::V1_0::BnHwGnssDebug::_hidl_getDebugData(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 2 /* getDebugData_2_0 */:
        {
            _hidl_err = ::android::hardware::gnss::V2_0::BnHwGnssDebug::_hidl_getDebugData_2_0(this, _hidl_data, _hidl_reply, _hidl_cb);
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

BsGnssDebug::BsGnssDebug(const ::android::sp<::android::hardware::gnss::V2_0::IGnssDebug> impl) : ::android::hardware::details::HidlInstrumentor("android.hardware.gnss@2.0", "IGnssDebug"), mImpl(impl) {
    mOnewayQueue.start(3000 /* similar limit to binderized */);
}

::android::hardware::Return<void> BsGnssDebug::addOnewayTask(std::function<void(void)> fun) {
    if (!mOnewayQueue.push(fun)) {
        return ::android::hardware::Status::fromExceptionCode(
                ::android::hardware::Status::EX_TRANSACTION_FAILED,
                "Passthrough oneway function queue exceeds maximum size.");
    }
    return ::android::hardware::Status();
}

::android::sp<IGnssDebug> IGnssDebug::tryGetService(const std::string &serviceName, const bool getStub) {
    return ::android::hardware::details::getServiceInternal<BpHwGnssDebug>(serviceName, false, getStub);
}

::android::sp<IGnssDebug> IGnssDebug::getService(const std::string &serviceName, const bool getStub) {
    return ::android::hardware::details::getServiceInternal<BpHwGnssDebug>(serviceName, true, getStub);
}

::android::status_t IGnssDebug::registerAsService(const std::string &serviceName) {
    return ::android::hardware::details::registerAsServiceInternal(this, serviceName);
}

bool IGnssDebug::registerForNotifications(
        const std::string &serviceName,
        const ::android::sp<::android::hidl::manager::V1_0::IServiceNotification> &notification) {
    const ::android::sp<::android::hidl::manager::V1_0::IServiceManager> sm
            = ::android::hardware::defaultServiceManager();
    if (sm == nullptr) {
        return false;
    }
    ::android::hardware::Return<bool> success =
            sm->registerForNotifications("android.hardware.gnss@2.0::IGnssDebug",
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
