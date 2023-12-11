#define LOG_TAG "android.hardware.nfc@1.2::Nfc"

#include <log/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <hidl/Static.h>
#include <hwbinder/ProcessState.h>
#include <utils/Trace.h>
#include <android/hidl/manager/1.0/IServiceManager.h>
#include <android/hardware/nfc/1.2/BpHwNfc.h>
#include <android/hardware/nfc/1.2/BnHwNfc.h>
#include <android/hardware/nfc/1.2/BsNfc.h>
#include <android/hardware/nfc/1.1/BpHwNfc.h>
#include <android/hardware/nfc/1.0/BpHwNfc.h>
#include <android/hidl/base/1.0/BpHwBase.h>
#include <hidl/ServiceManagement.h>

namespace android {
namespace hardware {
namespace nfc {
namespace V1_2 {

const char* INfc::descriptor("android.hardware.nfc@1.2::INfc");

__attribute__((constructor)) static void static_constructor() {
    ::android::hardware::details::getBnConstructorMap().set(INfc::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hardware::IBinder> {
                return new BnHwNfc(static_cast<INfc *>(iIntf));
            });
    ::android::hardware::details::getBsConstructorMap().set(INfc::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hidl::base::V1_0::IBase> {
                return new BsNfc(static_cast<INfc *>(iIntf));
            });
}

__attribute__((destructor))static void static_destructor() {
    ::android::hardware::details::getBnConstructorMap().erase(INfc::descriptor);
    ::android::hardware::details::getBsConstructorMap().erase(INfc::descriptor);
}

// Methods from ::android::hardware::nfc::V1_0::INfc follow.
// no default implementation for: ::android::hardware::Return<::android::hardware::nfc::V1_0::NfcStatus> INfc::open(const ::android::sp<::android::hardware::nfc::V1_0::INfcClientCallback>& clientCallback)
// no default implementation for: ::android::hardware::Return<uint32_t> INfc::write(const ::android::hardware::hidl_vec<uint8_t>& data)
// no default implementation for: ::android::hardware::Return<::android::hardware::nfc::V1_0::NfcStatus> INfc::coreInitialized(const ::android::hardware::hidl_vec<uint8_t>& data)
// no default implementation for: ::android::hardware::Return<::android::hardware::nfc::V1_0::NfcStatus> INfc::prediscover()
// no default implementation for: ::android::hardware::Return<::android::hardware::nfc::V1_0::NfcStatus> INfc::close()
// no default implementation for: ::android::hardware::Return<::android::hardware::nfc::V1_0::NfcStatus> INfc::controlGranted()
// no default implementation for: ::android::hardware::Return<::android::hardware::nfc::V1_0::NfcStatus> INfc::powerCycle()

// Methods from ::android::hardware::nfc::V1_1::INfc follow.
// no default implementation for: ::android::hardware::Return<void> INfc::factoryReset()
// no default implementation for: ::android::hardware::Return<::android::hardware::nfc::V1_0::NfcStatus> INfc::closeForPowerOffCase()
// no default implementation for: ::android::hardware::Return<::android::hardware::nfc::V1_0::NfcStatus> INfc::open_1_1(const ::android::sp<::android::hardware::nfc::V1_1::INfcClientCallback>& clientCallback)
// no default implementation for: ::android::hardware::Return<void> INfc::getConfig(getConfig_cb _hidl_cb)

// Methods from ::android::hardware::nfc::V1_2::INfc follow.
// no default implementation for: ::android::hardware::Return<void> INfc::getConfig_1_2(getConfig_1_2_cb _hidl_cb)

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> INfc::interfaceChain(interfaceChain_cb _hidl_cb){
    _hidl_cb({
        ::android::hardware::nfc::V1_2::INfc::descriptor,
        ::android::hardware::nfc::V1_1::INfc::descriptor,
        ::android::hardware::nfc::V1_0::INfc::descriptor,
        ::android::hidl::base::V1_0::IBase::descriptor,
    });
    return ::android::hardware::Void();
}

::android::hardware::Return<void> INfc::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    (void)fd;
    (void)options;
    return ::android::hardware::Void();
}

::android::hardware::Return<void> INfc::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    _hidl_cb(::android::hardware::nfc::V1_2::INfc::descriptor);
    return ::android::hardware::Void();
}

::android::hardware::Return<void> INfc::getHashChain(getHashChain_cb _hidl_cb){
    _hidl_cb({
        (uint8_t[32]){207,122,75,165,22,166,56,249,184,42,36,156,145,251,96,48,66,194,217,202,67,253,90,173,156,246,192,64,30,210,165,215} /* cf7a4ba516a638f9b82a249c91fb603042c2d9ca43fd5aad9cf6c0401ed2a5d7 */,
        (uint8_t[32]){141,61,134,218,11,250,75,240,112,151,13,131,3,198,89,246,127,53,214,112,194,135,212,90,63,84,46,79,237,173,213,120} /* 8d3d86da0bfa4bf070970d8303c659f67f35d670c287d45a3f542e4fedadd578 */,
        (uint8_t[32]){7,172,45,201,82,112,50,30,199,212,195,60,210,94,80,133,160,87,244,127,227,80,214,69,175,111,122,122,17,227,207,87} /* 07ac2dc95270321ec7d4c33cd25e5085a057f47fe350d645af6f7a7a11e3cf57 */,
        (uint8_t[32]){236,127,215,158,208,45,250,133,188,73,148,38,173,174,62,190,35,239,5,36,243,205,105,87,19,147,36,184,59,24,202,76} /* ec7fd79ed02dfa85bc499426adae3ebe23ef0524f3cd6957139324b83b18ca4c */});
    return ::android::hardware::Void();
}

::android::hardware::Return<void> INfc::setHALInstrumentation(){
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> INfc::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    (void)cookie;
    return (recipient != nullptr);
}

::android::hardware::Return<void> INfc::ping(){
    return ::android::hardware::Void();
}

::android::hardware::Return<void> INfc::getDebugInfo(getDebugInfo_cb _hidl_cb){
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

::android::hardware::Return<void> INfc::notifySyspropsChanged(){
    ::android::report_sysprop_change();
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> INfc::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
    return (recipient != nullptr);
}


::android::hardware::Return<::android::sp<::android::hardware::nfc::V1_2::INfc>> INfc::castFrom(const ::android::sp<::android::hardware::nfc::V1_2::INfc>& parent, bool /* emitError */) {
    return parent;
}

::android::hardware::Return<::android::sp<::android::hardware::nfc::V1_2::INfc>> INfc::castFrom(const ::android::sp<::android::hardware::nfc::V1_1::INfc>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<INfc, ::android::hardware::nfc::V1_1::INfc, BpHwNfc>(
            parent, "android.hardware.nfc@1.2::INfc", emitError);
}

::android::hardware::Return<::android::sp<::android::hardware::nfc::V1_2::INfc>> INfc::castFrom(const ::android::sp<::android::hardware::nfc::V1_0::INfc>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<INfc, ::android::hardware::nfc::V1_0::INfc, BpHwNfc>(
            parent, "android.hardware.nfc@1.2::INfc", emitError);
}

::android::hardware::Return<::android::sp<::android::hardware::nfc::V1_2::INfc>> INfc::castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<INfc, ::android::hidl::base::V1_0::IBase, BpHwNfc>(
            parent, "android.hardware.nfc@1.2::INfc", emitError);
}

BpHwNfc::BpHwNfc(const ::android::sp<::android::hardware::IBinder> &_hidl_impl)
        : BpInterface<INfc>(_hidl_impl),
          ::android::hardware::details::HidlInstrumentor("android.hardware.nfc@1.2", "INfc") {
}

void BpHwNfc::onLastStrongRef(const void* id) {
    {
        std::unique_lock<std::mutex> lock(_hidl_mMutex);
        _hidl_mDeathRecipients.clear();
    }

    BpInterface<INfc>::onLastStrongRef(id);
}
// Methods from ::android::hardware::nfc::V1_2::INfc follow.
::android::hardware::Return<void> BpHwNfc::_hidl_getConfig_1_2(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, getConfig_1_2_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::INfc::getConfig_1_2::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.nfc", "1.2", "INfc", "getConfig_1_2", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwNfc::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(12 /* getConfig_1_2 */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::nfc::V1_2::NfcConfig* _hidl_out_config;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        size_t _hidl__hidl_out_config_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_config), &_hidl__hidl_out_config_parent,  const_cast<const void**>(reinterpret_cast<void **>(&_hidl_out_config)));
        if (_hidl_err != ::android::OK) { return; }

        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::nfc::V1_2::NfcConfig &>(*_hidl_out_config),
                _hidl_reply,
                _hidl__hidl_out_config_parent,
                0 /* parentOffset */);

        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(*_hidl_out_config);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)_hidl_out_config);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.nfc", "1.2", "INfc", "getConfig_1_2", &_hidl_args);
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


// Methods from ::android::hardware::nfc::V1_0::INfc follow.
::android::hardware::Return<::android::hardware::nfc::V1_0::NfcStatus> BpHwNfc::open(const ::android::sp<::android::hardware::nfc::V1_0::INfcClientCallback>& clientCallback){
    ::android::hardware::Return<::android::hardware::nfc::V1_0::NfcStatus>  _hidl_out = ::android::hardware::nfc::V1_0::BpHwNfc::_hidl_open(this, this, clientCallback);

    return _hidl_out;
}

::android::hardware::Return<uint32_t> BpHwNfc::write(const ::android::hardware::hidl_vec<uint8_t>& data){
    ::android::hardware::Return<uint32_t>  _hidl_out = ::android::hardware::nfc::V1_0::BpHwNfc::_hidl_write(this, this, data);

    return _hidl_out;
}

::android::hardware::Return<::android::hardware::nfc::V1_0::NfcStatus> BpHwNfc::coreInitialized(const ::android::hardware::hidl_vec<uint8_t>& data){
    ::android::hardware::Return<::android::hardware::nfc::V1_0::NfcStatus>  _hidl_out = ::android::hardware::nfc::V1_0::BpHwNfc::_hidl_coreInitialized(this, this, data);

    return _hidl_out;
}

::android::hardware::Return<::android::hardware::nfc::V1_0::NfcStatus> BpHwNfc::prediscover(){
    ::android::hardware::Return<::android::hardware::nfc::V1_0::NfcStatus>  _hidl_out = ::android::hardware::nfc::V1_0::BpHwNfc::_hidl_prediscover(this, this);

    return _hidl_out;
}

::android::hardware::Return<::android::hardware::nfc::V1_0::NfcStatus> BpHwNfc::close(){
    ::android::hardware::Return<::android::hardware::nfc::V1_0::NfcStatus>  _hidl_out = ::android::hardware::nfc::V1_0::BpHwNfc::_hidl_close(this, this);

    return _hidl_out;
}

::android::hardware::Return<::android::hardware::nfc::V1_0::NfcStatus> BpHwNfc::controlGranted(){
    ::android::hardware::Return<::android::hardware::nfc::V1_0::NfcStatus>  _hidl_out = ::android::hardware::nfc::V1_0::BpHwNfc::_hidl_controlGranted(this, this);

    return _hidl_out;
}

::android::hardware::Return<::android::hardware::nfc::V1_0::NfcStatus> BpHwNfc::powerCycle(){
    ::android::hardware::Return<::android::hardware::nfc::V1_0::NfcStatus>  _hidl_out = ::android::hardware::nfc::V1_0::BpHwNfc::_hidl_powerCycle(this, this);

    return _hidl_out;
}


// Methods from ::android::hardware::nfc::V1_1::INfc follow.
::android::hardware::Return<void> BpHwNfc::factoryReset(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::nfc::V1_1::BpHwNfc::_hidl_factoryReset(this, this);

    return _hidl_out;
}

::android::hardware::Return<::android::hardware::nfc::V1_0::NfcStatus> BpHwNfc::closeForPowerOffCase(){
    ::android::hardware::Return<::android::hardware::nfc::V1_0::NfcStatus>  _hidl_out = ::android::hardware::nfc::V1_1::BpHwNfc::_hidl_closeForPowerOffCase(this, this);

    return _hidl_out;
}

::android::hardware::Return<::android::hardware::nfc::V1_0::NfcStatus> BpHwNfc::open_1_1(const ::android::sp<::android::hardware::nfc::V1_1::INfcClientCallback>& clientCallback){
    ::android::hardware::Return<::android::hardware::nfc::V1_0::NfcStatus>  _hidl_out = ::android::hardware::nfc::V1_1::BpHwNfc::_hidl_open_1_1(this, this, clientCallback);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwNfc::getConfig(getConfig_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::nfc::V1_1::BpHwNfc::_hidl_getConfig(this, this, _hidl_cb);

    return _hidl_out;
}


// Methods from ::android::hardware::nfc::V1_2::INfc follow.
::android::hardware::Return<void> BpHwNfc::getConfig_1_2(getConfig_1_2_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::nfc::V1_2::BpHwNfc::_hidl_getConfig_1_2(this, this, _hidl_cb);

    return _hidl_out;
}


// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BpHwNfc::interfaceChain(interfaceChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwNfc::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_debug(this, this, fd, options);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwNfc::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceDescriptor(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwNfc::getHashChain(getHashChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getHashChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwNfc::setHALInstrumentation(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_setHALInstrumentation(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwNfc::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    ::android::hardware::ProcessState::self()->startThreadPool();
    ::android::hardware::hidl_binder_death_recipient *binder_recipient = new ::android::hardware::hidl_binder_death_recipient(recipient, cookie, this);
    std::unique_lock<std::mutex> lock(_hidl_mMutex);
    _hidl_mDeathRecipients.push_back(binder_recipient);
    return (remote()->linkToDeath(binder_recipient) == ::android::OK);
}

::android::hardware::Return<void> BpHwNfc::ping(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_ping(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwNfc::getDebugInfo(getDebugInfo_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getDebugInfo(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwNfc::notifySyspropsChanged(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_notifySyspropsChanged(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwNfc::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
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


BnHwNfc::BnHwNfc(const ::android::sp<INfc> &_hidl_impl)
        : ::android::hidl::base::V1_0::BnHwBase(_hidl_impl, "android.hardware.nfc@1.2", "INfc") { 
            _hidl_mImpl = _hidl_impl;
            auto prio = ::android::hardware::getMinSchedulerPolicy(_hidl_impl);
            mSchedPolicy = prio.sched_policy;
            mSchedPriority = prio.prio;
            setRequestingSid(::android::hardware::getRequestingSid(_hidl_impl));
}

BnHwNfc::~BnHwNfc() {
    ::android::hardware::details::gBnMap->eraseIfEqual(_hidl_mImpl.get(), this);
}

// Methods from ::android::hardware::nfc::V1_2::INfc follow.
::android::status_t BnHwNfc::_hidl_getConfig_1_2(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwNfc::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::INfc::getConfig_1_2::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.nfc", "1.2", "INfc", "getConfig_1_2", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<INfc*>(_hidl_this->getImpl().get())->getConfig_1_2([&](const auto &_hidl_out_config) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("getConfig_1_2: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        size_t _hidl__hidl_out_config_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_config, sizeof(_hidl_out_config), &_hidl__hidl_out_config_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_err = writeEmbeddedToParcel(
                _hidl_out_config,
                _hidl_reply,
                _hidl__hidl_out_config_parent,
                0 /* parentOffset */);

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_config);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.nfc", "1.2", "INfc", "getConfig_1_2", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("getConfig_1_2: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}


// Methods from ::android::hardware::nfc::V1_0::INfc follow.

// Methods from ::android::hardware::nfc::V1_1::INfc follow.

// Methods from ::android::hardware::nfc::V1_2::INfc follow.

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BnHwNfc::ping() {
    return ::android::hardware::Void();
}
::android::hardware::Return<void> BnHwNfc::getDebugInfo(getDebugInfo_cb _hidl_cb) {
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

::android::status_t BnHwNfc::onTransact(
        uint32_t _hidl_code,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        uint32_t _hidl_flags,
        TransactCallback _hidl_cb) {
    ::android::status_t _hidl_err = ::android::OK;

    switch (_hidl_code) {
        case 1 /* open */:
        {
            _hidl_err = ::android::hardware::nfc::V1_0::BnHwNfc::_hidl_open(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 2 /* write */:
        {
            _hidl_err = ::android::hardware::nfc::V1_0::BnHwNfc::_hidl_write(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 3 /* coreInitialized */:
        {
            _hidl_err = ::android::hardware::nfc::V1_0::BnHwNfc::_hidl_coreInitialized(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 4 /* prediscover */:
        {
            _hidl_err = ::android::hardware::nfc::V1_0::BnHwNfc::_hidl_prediscover(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 5 /* close */:
        {
            _hidl_err = ::android::hardware::nfc::V1_0::BnHwNfc::_hidl_close(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 6 /* controlGranted */:
        {
            _hidl_err = ::android::hardware::nfc::V1_0::BnHwNfc::_hidl_controlGranted(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 7 /* powerCycle */:
        {
            _hidl_err = ::android::hardware::nfc::V1_0::BnHwNfc::_hidl_powerCycle(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 8 /* factoryReset */:
        {
            _hidl_err = ::android::hardware::nfc::V1_1::BnHwNfc::_hidl_factoryReset(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 9 /* closeForPowerOffCase */:
        {
            _hidl_err = ::android::hardware::nfc::V1_1::BnHwNfc::_hidl_closeForPowerOffCase(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 10 /* open_1_1 */:
        {
            _hidl_err = ::android::hardware::nfc::V1_1::BnHwNfc::_hidl_open_1_1(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 11 /* getConfig */:
        {
            _hidl_err = ::android::hardware::nfc::V1_1::BnHwNfc::_hidl_getConfig(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 12 /* getConfig_1_2 */:
        {
            _hidl_err = ::android::hardware::nfc::V1_2::BnHwNfc::_hidl_getConfig_1_2(this, _hidl_data, _hidl_reply, _hidl_cb);
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

BsNfc::BsNfc(const ::android::sp<::android::hardware::nfc::V1_2::INfc> impl) : ::android::hardware::details::HidlInstrumentor("android.hardware.nfc@1.2", "INfc"), mImpl(impl) {
    mOnewayQueue.start(3000 /* similar limit to binderized */);
}

::android::hardware::Return<void> BsNfc::addOnewayTask(std::function<void(void)> fun) {
    if (!mOnewayQueue.push(fun)) {
        return ::android::hardware::Status::fromExceptionCode(
                ::android::hardware::Status::EX_TRANSACTION_FAILED,
                "Passthrough oneway function queue exceeds maximum size.");
    }
    return ::android::hardware::Status();
}

::android::sp<INfc> INfc::tryGetService(const std::string &serviceName, const bool getStub) {
    return ::android::hardware::details::getServiceInternal<BpHwNfc>(serviceName, false, getStub);
}

::android::sp<INfc> INfc::getService(const std::string &serviceName, const bool getStub) {
    return ::android::hardware::details::getServiceInternal<BpHwNfc>(serviceName, true, getStub);
}

::android::status_t INfc::registerAsService(const std::string &serviceName) {
    return ::android::hardware::details::registerAsServiceInternal(this, serviceName);
}

bool INfc::registerForNotifications(
        const std::string &serviceName,
        const ::android::sp<::android::hidl::manager::V1_0::IServiceNotification> &notification) {
    const ::android::sp<::android::hidl::manager::V1_0::IServiceManager> sm
            = ::android::hardware::defaultServiceManager();
    if (sm == nullptr) {
        return false;
    }
    ::android::hardware::Return<bool> success =
            sm->registerForNotifications("android.hardware.nfc@1.2::INfc",
                    serviceName, notification);
    return success.isOk() && success;
}

static_assert(sizeof(::android::hardware::MQDescriptor<char, ::android::hardware::kSynchronizedReadWrite>) == 32, "wrong size");
static_assert(sizeof(::android::hardware::hidl_handle) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_memory) == 40, "wrong size");
static_assert(sizeof(::android::hardware::hidl_string) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_vec<char>) == 16, "wrong size");

}  // namespace V1_2
}  // namespace nfc
}  // namespace hardware
}  // namespace android
