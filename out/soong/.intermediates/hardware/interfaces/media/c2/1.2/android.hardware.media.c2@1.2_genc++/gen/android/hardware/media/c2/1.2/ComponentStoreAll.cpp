#define LOG_TAG "android.hardware.media.c2@1.2::ComponentStore"

#include <log/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <hidl/Static.h>
#include <hwbinder/ProcessState.h>
#include <utils/Trace.h>
#include <android/hidl/manager/1.0/IServiceManager.h>
#include <android/hardware/media/c2/1.2/BpHwComponentStore.h>
#include <android/hardware/media/c2/1.2/BnHwComponentStore.h>
#include <android/hardware/media/c2/1.2/BsComponentStore.h>
#include <android/hardware/media/c2/1.1/BpHwComponentStore.h>
#include <android/hardware/media/c2/1.0/BpHwComponentStore.h>
#include <android/hidl/base/1.0/BpHwBase.h>
#include <hidl/ServiceManagement.h>

namespace android {
namespace hardware {
namespace media {
namespace c2 {
namespace V1_2 {

const char* IComponentStore::descriptor("android.hardware.media.c2@1.2::IComponentStore");

__attribute__((constructor)) static void static_constructor() {
    ::android::hardware::details::getBnConstructorMap().set(IComponentStore::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hardware::IBinder> {
                return new BnHwComponentStore(static_cast<IComponentStore *>(iIntf));
            });
    ::android::hardware::details::getBsConstructorMap().set(IComponentStore::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hidl::base::V1_0::IBase> {
                return new BsComponentStore(static_cast<IComponentStore *>(iIntf));
            });
}

__attribute__((destructor))static void static_destructor() {
    ::android::hardware::details::getBnConstructorMap().erase(IComponentStore::descriptor);
    ::android::hardware::details::getBsConstructorMap().erase(IComponentStore::descriptor);
}

// Methods from ::android::hardware::media::c2::V1_0::IComponentStore follow.
// no default implementation for: ::android::hardware::Return<void> IComponentStore::createComponent(const ::android::hardware::hidl_string& name, const ::android::sp<::android::hardware::media::c2::V1_0::IComponentListener>& listener, const ::android::sp<::android::hardware::media::bufferpool::V2_0::IClientManager>& pool, createComponent_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IComponentStore::createInterface(const ::android::hardware::hidl_string& name, createInterface_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IComponentStore::listComponents(listComponents_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IComponentStore::createInputSurface(createInputSurface_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IComponentStore::getStructDescriptors(const ::android::hardware::hidl_vec<uint32_t>& indices, getStructDescriptors_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<::android::hardware::media::c2::V1_0::Status> IComponentStore::copyBuffer(const ::android::hardware::media::c2::V1_0::Buffer& src, const ::android::hardware::media::c2::V1_0::Buffer& dst)
// no default implementation for: ::android::hardware::Return<::android::sp<::android::hardware::media::bufferpool::V2_0::IClientManager>> IComponentStore::getPoolClientManager()
// no default implementation for: ::android::hardware::Return<::android::sp<::android::hardware::media::c2::V1_0::IConfigurable>> IComponentStore::getConfigurable()

// Methods from ::android::hardware::media::c2::V1_1::IComponentStore follow.
// no default implementation for: ::android::hardware::Return<void> IComponentStore::createComponent_1_1(const ::android::hardware::hidl_string& name, const ::android::sp<::android::hardware::media::c2::V1_0::IComponentListener>& listener, const ::android::sp<::android::hardware::media::bufferpool::V2_0::IClientManager>& pool, createComponent_1_1_cb _hidl_cb)

// Methods from ::android::hardware::media::c2::V1_2::IComponentStore follow.
// no default implementation for: ::android::hardware::Return<void> IComponentStore::createComponent_1_2(const ::android::hardware::hidl_string& name, const ::android::sp<::android::hardware::media::c2::V1_0::IComponentListener>& listener, const ::android::sp<::android::hardware::media::bufferpool::V2_0::IClientManager>& pool, createComponent_1_2_cb _hidl_cb)

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> IComponentStore::interfaceChain(interfaceChain_cb _hidl_cb){
    _hidl_cb({
        ::android::hardware::media::c2::V1_2::IComponentStore::descriptor,
        ::android::hardware::media::c2::V1_1::IComponentStore::descriptor,
        ::android::hardware::media::c2::V1_0::IComponentStore::descriptor,
        ::android::hidl::base::V1_0::IBase::descriptor,
    });
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IComponentStore::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    (void)fd;
    (void)options;
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IComponentStore::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    _hidl_cb(::android::hardware::media::c2::V1_2::IComponentStore::descriptor);
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IComponentStore::getHashChain(getHashChain_cb _hidl_cb){
    _hidl_cb({
        (uint8_t[32]){252,209,127,184,108,27,85,112,200,181,93,133,95,210,171,147,228,162,198,98,157,155,169,55,67,114,146,132,105,170,217,97} /* fcd17fb86c1b5570c8b55d855fd2ab93e4a2c6629d9ba9374372928469aad961 */,
        (uint8_t[32]){163,237,221,155,189,200,126,140,34,118,64,112,3,125,209,21,79,28,240,6,230,251,169,51,100,196,248,93,76,19,74,25} /* a3eddd9bbdc87e8c22764070037dd1154f1cf006e6fba93364c4f85d4c134a19 */,
        (uint8_t[32]){67,215,11,205,198,59,61,4,43,172,60,50,151,245,217,65,223,171,189,8,243,206,185,107,96,22,204,20,246,227,75,163} /* 43d70bcdc63b3d042bac3c3297f5d941dfabbd08f3ceb96b6016cc14f6e34ba3 */,
        (uint8_t[32]){236,127,215,158,208,45,250,133,188,73,148,38,173,174,62,190,35,239,5,36,243,205,105,87,19,147,36,184,59,24,202,76} /* ec7fd79ed02dfa85bc499426adae3ebe23ef0524f3cd6957139324b83b18ca4c */});
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IComponentStore::setHALInstrumentation(){
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> IComponentStore::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    (void)cookie;
    return (recipient != nullptr);
}

::android::hardware::Return<void> IComponentStore::ping(){
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IComponentStore::getDebugInfo(getDebugInfo_cb _hidl_cb){
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

::android::hardware::Return<void> IComponentStore::notifySyspropsChanged(){
    ::android::report_sysprop_change();
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> IComponentStore::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
    return (recipient != nullptr);
}


::android::hardware::Return<::android::sp<::android::hardware::media::c2::V1_2::IComponentStore>> IComponentStore::castFrom(const ::android::sp<::android::hardware::media::c2::V1_2::IComponentStore>& parent, bool /* emitError */) {
    return parent;
}

::android::hardware::Return<::android::sp<::android::hardware::media::c2::V1_2::IComponentStore>> IComponentStore::castFrom(const ::android::sp<::android::hardware::media::c2::V1_1::IComponentStore>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<IComponentStore, ::android::hardware::media::c2::V1_1::IComponentStore, BpHwComponentStore>(
            parent, "android.hardware.media.c2@1.2::IComponentStore", emitError);
}

::android::hardware::Return<::android::sp<::android::hardware::media::c2::V1_2::IComponentStore>> IComponentStore::castFrom(const ::android::sp<::android::hardware::media::c2::V1_0::IComponentStore>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<IComponentStore, ::android::hardware::media::c2::V1_0::IComponentStore, BpHwComponentStore>(
            parent, "android.hardware.media.c2@1.2::IComponentStore", emitError);
}

::android::hardware::Return<::android::sp<::android::hardware::media::c2::V1_2::IComponentStore>> IComponentStore::castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<IComponentStore, ::android::hidl::base::V1_0::IBase, BpHwComponentStore>(
            parent, "android.hardware.media.c2@1.2::IComponentStore", emitError);
}

BpHwComponentStore::BpHwComponentStore(const ::android::sp<::android::hardware::IBinder> &_hidl_impl)
        : BpInterface<IComponentStore>(_hidl_impl),
          ::android::hardware::details::HidlInstrumentor("android.hardware.media.c2@1.2", "IComponentStore") {
}

void BpHwComponentStore::onLastStrongRef(const void* id) {
    {
        std::unique_lock<std::mutex> lock(_hidl_mMutex);
        _hidl_mDeathRecipients.clear();
    }

    BpInterface<IComponentStore>::onLastStrongRef(id);
}
// Methods from ::android::hardware::media::c2::V1_2::IComponentStore follow.
::android::hardware::Return<void> BpHwComponentStore::_hidl_createComponent_1_2(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::hidl_string& name, const ::android::sp<::android::hardware::media::c2::V1_0::IComponentListener>& listener, const ::android::sp<::android::hardware::media::bufferpool::V2_0::IClientManager>& pool, createComponent_1_2_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IComponentStore::createComponent_1_2::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&name);
        _hidl_args.push_back((void *)&listener);
        _hidl_args.push_back((void *)&pool);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.media.c2", "1.2", "IComponentStore", "createComponent_1_2", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwComponentStore::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_name_parent;

    _hidl_err = _hidl_data.writeBuffer(&name, sizeof(name), &_hidl_name_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            name,
            &_hidl_data,
            _hidl_name_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (listener == nullptr) {
        _hidl_err = _hidl_data.writeStrongBinder(nullptr);
    } else {
        ::android::sp<::android::hardware::IBinder> _hidl_binder = ::android::hardware::getOrCreateCachedBinder(listener.get());
        if (_hidl_binder.get() != nullptr) {
            _hidl_err = _hidl_data.writeStrongBinder(_hidl_binder);
        } else {
            _hidl_err = ::android::UNKNOWN_ERROR;
        }
    }
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    if (pool == nullptr) {
        _hidl_err = _hidl_data.writeStrongBinder(nullptr);
    } else {
        ::android::sp<::android::hardware::IBinder> _hidl_binder = ::android::hardware::getOrCreateCachedBinder(pool.get());
        if (_hidl_binder.get() != nullptr) {
            _hidl_err = _hidl_data.writeStrongBinder(_hidl_binder);
        } else {
            _hidl_err = ::android::UNKNOWN_ERROR;
        }
    }
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    ::android::hardware::ProcessState::self()->startThreadPool();
    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(10 /* createComponent_1_2 */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::media::c2::V1_0::Status _hidl_out_status;
        ::android::sp<::android::hardware::media::c2::V1_2::IComponent> _hidl_out_comp;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_status);
        if (_hidl_err != ::android::OK) { return; }

        {
            ::android::sp<::android::hardware::IBinder> _hidl_binder;
            _hidl_err = _hidl_reply.readNullableStrongBinder(&_hidl_binder);
            if (_hidl_err != ::android::OK) { return; }

            _hidl_out_comp = ::android::hardware::fromBinder<::android::hardware::media::c2::V1_2::IComponent,::android::hardware::media::c2::V1_2::BpHwComponent,::android::hardware::media::c2::V1_2::BnHwComponent>(_hidl_binder);
        }

        _hidl_cb(_hidl_out_status, _hidl_out_comp);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)&_hidl_out_comp);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.media.c2", "1.2", "IComponentStore", "createComponent_1_2", &_hidl_args);
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


// Methods from ::android::hardware::media::c2::V1_0::IComponentStore follow.
::android::hardware::Return<void> BpHwComponentStore::createComponent(const ::android::hardware::hidl_string& name, const ::android::sp<::android::hardware::media::c2::V1_0::IComponentListener>& listener, const ::android::sp<::android::hardware::media::bufferpool::V2_0::IClientManager>& pool, createComponent_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::media::c2::V1_0::BpHwComponentStore::_hidl_createComponent(this, this, name, listener, pool, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwComponentStore::createInterface(const ::android::hardware::hidl_string& name, createInterface_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::media::c2::V1_0::BpHwComponentStore::_hidl_createInterface(this, this, name, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwComponentStore::listComponents(listComponents_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::media::c2::V1_0::BpHwComponentStore::_hidl_listComponents(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwComponentStore::createInputSurface(createInputSurface_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::media::c2::V1_0::BpHwComponentStore::_hidl_createInputSurface(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwComponentStore::getStructDescriptors(const ::android::hardware::hidl_vec<uint32_t>& indices, getStructDescriptors_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::media::c2::V1_0::BpHwComponentStore::_hidl_getStructDescriptors(this, this, indices, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<::android::hardware::media::c2::V1_0::Status> BpHwComponentStore::copyBuffer(const ::android::hardware::media::c2::V1_0::Buffer& src, const ::android::hardware::media::c2::V1_0::Buffer& dst){
    ::android::hardware::Return<::android::hardware::media::c2::V1_0::Status>  _hidl_out = ::android::hardware::media::c2::V1_0::BpHwComponentStore::_hidl_copyBuffer(this, this, src, dst);

    return _hidl_out;
}

::android::hardware::Return<::android::sp<::android::hardware::media::bufferpool::V2_0::IClientManager>> BpHwComponentStore::getPoolClientManager(){
    ::android::hardware::Return<::android::sp<::android::hardware::media::bufferpool::V2_0::IClientManager>>  _hidl_out = ::android::hardware::media::c2::V1_0::BpHwComponentStore::_hidl_getPoolClientManager(this, this);

    return _hidl_out;
}

::android::hardware::Return<::android::sp<::android::hardware::media::c2::V1_0::IConfigurable>> BpHwComponentStore::getConfigurable(){
    ::android::hardware::Return<::android::sp<::android::hardware::media::c2::V1_0::IConfigurable>>  _hidl_out = ::android::hardware::media::c2::V1_0::BpHwComponentStore::_hidl_getConfigurable(this, this);

    return _hidl_out;
}


// Methods from ::android::hardware::media::c2::V1_1::IComponentStore follow.
::android::hardware::Return<void> BpHwComponentStore::createComponent_1_1(const ::android::hardware::hidl_string& name, const ::android::sp<::android::hardware::media::c2::V1_0::IComponentListener>& listener, const ::android::sp<::android::hardware::media::bufferpool::V2_0::IClientManager>& pool, createComponent_1_1_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::media::c2::V1_1::BpHwComponentStore::_hidl_createComponent_1_1(this, this, name, listener, pool, _hidl_cb);

    return _hidl_out;
}


// Methods from ::android::hardware::media::c2::V1_2::IComponentStore follow.
::android::hardware::Return<void> BpHwComponentStore::createComponent_1_2(const ::android::hardware::hidl_string& name, const ::android::sp<::android::hardware::media::c2::V1_0::IComponentListener>& listener, const ::android::sp<::android::hardware::media::bufferpool::V2_0::IClientManager>& pool, createComponent_1_2_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::media::c2::V1_2::BpHwComponentStore::_hidl_createComponent_1_2(this, this, name, listener, pool, _hidl_cb);

    return _hidl_out;
}


// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BpHwComponentStore::interfaceChain(interfaceChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwComponentStore::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_debug(this, this, fd, options);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwComponentStore::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceDescriptor(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwComponentStore::getHashChain(getHashChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getHashChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwComponentStore::setHALInstrumentation(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_setHALInstrumentation(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwComponentStore::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    ::android::hardware::ProcessState::self()->startThreadPool();
    ::android::hardware::hidl_binder_death_recipient *binder_recipient = new ::android::hardware::hidl_binder_death_recipient(recipient, cookie, this);
    std::unique_lock<std::mutex> lock(_hidl_mMutex);
    _hidl_mDeathRecipients.push_back(binder_recipient);
    return (remote()->linkToDeath(binder_recipient) == ::android::OK);
}

::android::hardware::Return<void> BpHwComponentStore::ping(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_ping(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwComponentStore::getDebugInfo(getDebugInfo_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getDebugInfo(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwComponentStore::notifySyspropsChanged(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_notifySyspropsChanged(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwComponentStore::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
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


BnHwComponentStore::BnHwComponentStore(const ::android::sp<IComponentStore> &_hidl_impl)
        : ::android::hidl::base::V1_0::BnHwBase(_hidl_impl, "android.hardware.media.c2@1.2", "IComponentStore") { 
            _hidl_mImpl = _hidl_impl;
            auto prio = ::android::hardware::getMinSchedulerPolicy(_hidl_impl);
            mSchedPolicy = prio.sched_policy;
            mSchedPriority = prio.prio;
            setRequestingSid(::android::hardware::getRequestingSid(_hidl_impl));
}

BnHwComponentStore::~BnHwComponentStore() {
    ::android::hardware::details::gBnMap->eraseIfEqual(_hidl_mImpl.get(), this);
}

// Methods from ::android::hardware::media::c2::V1_2::IComponentStore follow.
::android::status_t BnHwComponentStore::_hidl_createComponent_1_2(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwComponentStore::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    const ::android::hardware::hidl_string* name;
    ::android::sp<::android::hardware::media::c2::V1_0::IComponentListener> listener;
    ::android::sp<::android::hardware::media::bufferpool::V2_0::IClientManager> pool;

    size_t _hidl_name_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*name), &_hidl_name_parent,  reinterpret_cast<const void **>(&name));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(*name),
            _hidl_data,
            _hidl_name_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    {
        ::android::sp<::android::hardware::IBinder> _hidl_binder;
        _hidl_err = _hidl_data.readNullableStrongBinder(&_hidl_binder);
        if (_hidl_err != ::android::OK) { return _hidl_err; }

        listener = ::android::hardware::fromBinder<::android::hardware::media::c2::V1_0::IComponentListener,::android::hardware::media::c2::V1_0::BpHwComponentListener,::android::hardware::media::c2::V1_0::BnHwComponentListener>(_hidl_binder);
    }

    {
        ::android::sp<::android::hardware::IBinder> _hidl_binder;
        _hidl_err = _hidl_data.readNullableStrongBinder(&_hidl_binder);
        if (_hidl_err != ::android::OK) { return _hidl_err; }

        pool = ::android::hardware::fromBinder<::android::hardware::media::bufferpool::V2_0::IClientManager,::android::hardware::media::bufferpool::V2_0::BpHwClientManager,::android::hardware::media::bufferpool::V2_0::BnHwClientManager>(_hidl_binder);
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IComponentStore::createComponent_1_2::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)name);
        _hidl_args.push_back((void *)&listener);
        _hidl_args.push_back((void *)&pool);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.media.c2", "1.2", "IComponentStore", "createComponent_1_2", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IComponentStore*>(_hidl_this->getImpl().get())->createComponent_1_2(*name, listener, pool, [&](const auto &_hidl_out_status, const auto &_hidl_out_comp) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("createComponent_1_2: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_status);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        if (_hidl_out_comp == nullptr) {
            _hidl_err = _hidl_reply->writeStrongBinder(nullptr);
        } else {
            ::android::sp<::android::hardware::IBinder> _hidl_binder = ::android::hardware::getOrCreateCachedBinder(_hidl_out_comp.get());
            if (_hidl_binder.get() != nullptr) {
                _hidl_err = _hidl_reply->writeStrongBinder(_hidl_binder);
            } else {
                _hidl_err = ::android::UNKNOWN_ERROR;
            }
        }
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)&_hidl_out_comp);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.media.c2", "1.2", "IComponentStore", "createComponent_1_2", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("createComponent_1_2: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}


// Methods from ::android::hardware::media::c2::V1_0::IComponentStore follow.

// Methods from ::android::hardware::media::c2::V1_1::IComponentStore follow.

// Methods from ::android::hardware::media::c2::V1_2::IComponentStore follow.

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BnHwComponentStore::ping() {
    return ::android::hardware::Void();
}
::android::hardware::Return<void> BnHwComponentStore::getDebugInfo(getDebugInfo_cb _hidl_cb) {
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

::android::status_t BnHwComponentStore::onTransact(
        uint32_t _hidl_code,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        uint32_t _hidl_flags,
        TransactCallback _hidl_cb) {
    ::android::status_t _hidl_err = ::android::OK;

    switch (_hidl_code) {
        case 1 /* createComponent */:
        {
            _hidl_err = ::android::hardware::media::c2::V1_0::BnHwComponentStore::_hidl_createComponent(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 2 /* createInterface */:
        {
            _hidl_err = ::android::hardware::media::c2::V1_0::BnHwComponentStore::_hidl_createInterface(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 3 /* listComponents */:
        {
            _hidl_err = ::android::hardware::media::c2::V1_0::BnHwComponentStore::_hidl_listComponents(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 4 /* createInputSurface */:
        {
            _hidl_err = ::android::hardware::media::c2::V1_0::BnHwComponentStore::_hidl_createInputSurface(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 5 /* getStructDescriptors */:
        {
            _hidl_err = ::android::hardware::media::c2::V1_0::BnHwComponentStore::_hidl_getStructDescriptors(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 6 /* copyBuffer */:
        {
            _hidl_err = ::android::hardware::media::c2::V1_0::BnHwComponentStore::_hidl_copyBuffer(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 7 /* getPoolClientManager */:
        {
            _hidl_err = ::android::hardware::media::c2::V1_0::BnHwComponentStore::_hidl_getPoolClientManager(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 8 /* getConfigurable */:
        {
            _hidl_err = ::android::hardware::media::c2::V1_0::BnHwComponentStore::_hidl_getConfigurable(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 9 /* createComponent_1_1 */:
        {
            _hidl_err = ::android::hardware::media::c2::V1_1::BnHwComponentStore::_hidl_createComponent_1_1(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 10 /* createComponent_1_2 */:
        {
            _hidl_err = ::android::hardware::media::c2::V1_2::BnHwComponentStore::_hidl_createComponent_1_2(this, _hidl_data, _hidl_reply, _hidl_cb);
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

BsComponentStore::BsComponentStore(const ::android::sp<::android::hardware::media::c2::V1_2::IComponentStore> impl) : ::android::hardware::details::HidlInstrumentor("android.hardware.media.c2@1.2", "IComponentStore"), mImpl(impl) {
    mOnewayQueue.start(3000 /* similar limit to binderized */);
}

::android::hardware::Return<void> BsComponentStore::addOnewayTask(std::function<void(void)> fun) {
    if (!mOnewayQueue.push(fun)) {
        return ::android::hardware::Status::fromExceptionCode(
                ::android::hardware::Status::EX_TRANSACTION_FAILED,
                "Passthrough oneway function queue exceeds maximum size.");
    }
    return ::android::hardware::Status();
}

::android::sp<IComponentStore> IComponentStore::tryGetService(const std::string &serviceName, const bool getStub) {
    return ::android::hardware::details::getServiceInternal<BpHwComponentStore>(serviceName, false, getStub);
}

::android::sp<IComponentStore> IComponentStore::getService(const std::string &serviceName, const bool getStub) {
    return ::android::hardware::details::getServiceInternal<BpHwComponentStore>(serviceName, true, getStub);
}

::android::status_t IComponentStore::registerAsService(const std::string &serviceName) {
    return ::android::hardware::details::registerAsServiceInternal(this, serviceName);
}

bool IComponentStore::registerForNotifications(
        const std::string &serviceName,
        const ::android::sp<::android::hidl::manager::V1_0::IServiceNotification> &notification) {
    const ::android::sp<::android::hidl::manager::V1_0::IServiceManager> sm
            = ::android::hardware::defaultServiceManager();
    if (sm == nullptr) {
        return false;
    }
    ::android::hardware::Return<bool> success =
            sm->registerForNotifications("android.hardware.media.c2@1.2::IComponentStore",
                    serviceName, notification);
    return success.isOk() && success;
}

static_assert(sizeof(::android::hardware::MQDescriptor<char, ::android::hardware::kSynchronizedReadWrite>) == 32, "wrong size");
static_assert(sizeof(::android::hardware::hidl_handle) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_memory) == 40, "wrong size");
static_assert(sizeof(::android::hardware::hidl_string) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_vec<char>) == 16, "wrong size");

}  // namespace V1_2
}  // namespace c2
}  // namespace media
}  // namespace hardware
}  // namespace android
