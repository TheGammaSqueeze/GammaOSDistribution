#define LOG_TAG "android.frameworks.sensorservice@1.0::SensorManager"

#include <log/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <hidl/Static.h>
#include <hwbinder/ProcessState.h>
#include <utils/Trace.h>
#include <android/hidl/manager/1.0/IServiceManager.h>
#include <android/frameworks/sensorservice/1.0/BpHwSensorManager.h>
#include <android/frameworks/sensorservice/1.0/BnHwSensorManager.h>
#include <android/frameworks/sensorservice/1.0/BsSensorManager.h>
#include <android/hidl/base/1.0/BpHwBase.h>
#include <hidl/ServiceManagement.h>

namespace android {
namespace frameworks {
namespace sensorservice {
namespace V1_0 {

const char* ISensorManager::descriptor("android.frameworks.sensorservice@1.0::ISensorManager");

__attribute__((constructor)) static void static_constructor() {
    ::android::hardware::details::getBnConstructorMap().set(ISensorManager::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hardware::IBinder> {
                return new BnHwSensorManager(static_cast<ISensorManager *>(iIntf));
            });
    ::android::hardware::details::getBsConstructorMap().set(ISensorManager::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hidl::base::V1_0::IBase> {
                return new BsSensorManager(static_cast<ISensorManager *>(iIntf));
            });
}

__attribute__((destructor))static void static_destructor() {
    ::android::hardware::details::getBnConstructorMap().erase(ISensorManager::descriptor);
    ::android::hardware::details::getBsConstructorMap().erase(ISensorManager::descriptor);
}

// Methods from ::android::frameworks::sensorservice::V1_0::ISensorManager follow.
// no default implementation for: ::android::hardware::Return<void> ISensorManager::getSensorList(getSensorList_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> ISensorManager::getDefaultSensor(::android::hardware::sensors::V1_0::SensorType type, getDefaultSensor_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> ISensorManager::createAshmemDirectChannel(const ::android::hardware::hidl_memory& mem, uint64_t size, createAshmemDirectChannel_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> ISensorManager::createGrallocDirectChannel(const ::android::hardware::hidl_handle& buffer, uint64_t size, createGrallocDirectChannel_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> ISensorManager::createEventQueue(const ::android::sp<::android::frameworks::sensorservice::V1_0::IEventQueueCallback>& callback, createEventQueue_cb _hidl_cb)

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> ISensorManager::interfaceChain(interfaceChain_cb _hidl_cb){
    _hidl_cb({
        ::android::frameworks::sensorservice::V1_0::ISensorManager::descriptor,
        ::android::hidl::base::V1_0::IBase::descriptor,
    });
    return ::android::hardware::Void();
}

::android::hardware::Return<void> ISensorManager::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    (void)fd;
    (void)options;
    return ::android::hardware::Void();
}

::android::hardware::Return<void> ISensorManager::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    _hidl_cb(::android::frameworks::sensorservice::V1_0::ISensorManager::descriptor);
    return ::android::hardware::Void();
}

::android::hardware::Return<void> ISensorManager::getHashChain(getHashChain_cb _hidl_cb){
    _hidl_cb({
        (uint8_t[32]){36,191,74,183,199,224,215,235,141,206,142,177,172,78,167,189,28,201,92,68,119,159,178,62,19,125,62,135,161,95,172,125} /* 24bf4ab7c7e0d7eb8dce8eb1ac4ea7bd1cc95c44779fb23e137d3e87a15fac7d */,
        (uint8_t[32]){236,127,215,158,208,45,250,133,188,73,148,38,173,174,62,190,35,239,5,36,243,205,105,87,19,147,36,184,59,24,202,76} /* ec7fd79ed02dfa85bc499426adae3ebe23ef0524f3cd6957139324b83b18ca4c */});
    return ::android::hardware::Void();
}

::android::hardware::Return<void> ISensorManager::setHALInstrumentation(){
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> ISensorManager::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    (void)cookie;
    return (recipient != nullptr);
}

::android::hardware::Return<void> ISensorManager::ping(){
    return ::android::hardware::Void();
}

::android::hardware::Return<void> ISensorManager::getDebugInfo(getDebugInfo_cb _hidl_cb){
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

::android::hardware::Return<void> ISensorManager::notifySyspropsChanged(){
    ::android::report_sysprop_change();
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> ISensorManager::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
    return (recipient != nullptr);
}


::android::hardware::Return<::android::sp<::android::frameworks::sensorservice::V1_0::ISensorManager>> ISensorManager::castFrom(const ::android::sp<::android::frameworks::sensorservice::V1_0::ISensorManager>& parent, bool /* emitError */) {
    return parent;
}

::android::hardware::Return<::android::sp<::android::frameworks::sensorservice::V1_0::ISensorManager>> ISensorManager::castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<ISensorManager, ::android::hidl::base::V1_0::IBase, BpHwSensorManager>(
            parent, "android.frameworks.sensorservice@1.0::ISensorManager", emitError);
}

BpHwSensorManager::BpHwSensorManager(const ::android::sp<::android::hardware::IBinder> &_hidl_impl)
        : BpInterface<ISensorManager>(_hidl_impl),
          ::android::hardware::details::HidlInstrumentor("android.frameworks.sensorservice@1.0", "ISensorManager") {
}

void BpHwSensorManager::onLastStrongRef(const void* id) {
    {
        std::unique_lock<std::mutex> lock(_hidl_mMutex);
        _hidl_mDeathRecipients.clear();
    }

    BpInterface<ISensorManager>::onLastStrongRef(id);
}
// Methods from ::android::frameworks::sensorservice::V1_0::ISensorManager follow.
::android::hardware::Return<void> BpHwSensorManager::_hidl_getSensorList(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, getSensorList_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::ISensorManager::getSensorList::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.frameworks.sensorservice", "1.0", "ISensorManager", "getSensorList", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwSensorManager::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(1 /* getSensorList */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        const ::android::hardware::hidl_vec<::android::hardware::sensors::V1_0::SensorInfo>* _hidl_out_list;
        ::android::frameworks::sensorservice::V1_0::Result _hidl_out_result;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        size_t _hidl__hidl_out_list_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_list), &_hidl__hidl_out_list_parent,  reinterpret_cast<const void **>(&_hidl_out_list));

        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_list_child;

        _hidl_err = ::android::hardware::readEmbeddedFromParcel(
                const_cast<::android::hardware::hidl_vec<::android::hardware::sensors::V1_0::SensorInfo> &>(*_hidl_out_list),
                _hidl_reply,
                _hidl__hidl_out_list_parent,
                0 /* parentOffset */, &_hidl__hidl_out_list_child);

        if (_hidl_err != ::android::OK) { return; }

        for (size_t _hidl_index_0 = 0; _hidl_index_0 < _hidl_out_list->size(); ++_hidl_index_0) {
            _hidl_err = readEmbeddedFromParcel(
                    const_cast<::android::hardware::sensors::V1_0::SensorInfo &>((*_hidl_out_list)[_hidl_index_0]),
                    _hidl_reply,
                    _hidl__hidl_out_list_child,
                    _hidl_index_0 * sizeof(::android::hardware::sensors::V1_0::SensorInfo));

            if (_hidl_err != ::android::OK) { return; }

        }

        _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_result);
        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(*_hidl_out_list, _hidl_out_result);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)_hidl_out_list);
            _hidl_args.push_back((void *)&_hidl_out_result);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.frameworks.sensorservice", "1.0", "ISensorManager", "getSensorList", &_hidl_args);
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

::android::hardware::Return<void> BpHwSensorManager::_hidl_getDefaultSensor(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, ::android::hardware::sensors::V1_0::SensorType type, getDefaultSensor_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::ISensorManager::getDefaultSensor::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&type);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.frameworks.sensorservice", "1.0", "ISensorManager", "getDefaultSensor", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwSensorManager::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32((int32_t)type);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(2 /* getDefaultSensor */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::sensors::V1_0::SensorInfo* _hidl_out_sensor;
        ::android::frameworks::sensorservice::V1_0::Result _hidl_out_result;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        size_t _hidl__hidl_out_sensor_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_sensor), &_hidl__hidl_out_sensor_parent,  const_cast<const void**>(reinterpret_cast<void **>(&_hidl_out_sensor)));
        if (_hidl_err != ::android::OK) { return; }

        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::sensors::V1_0::SensorInfo &>(*_hidl_out_sensor),
                _hidl_reply,
                _hidl__hidl_out_sensor_parent,
                0 /* parentOffset */);

        if (_hidl_err != ::android::OK) { return; }

        _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_result);
        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(*_hidl_out_sensor, _hidl_out_result);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)_hidl_out_sensor);
            _hidl_args.push_back((void *)&_hidl_out_result);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.frameworks.sensorservice", "1.0", "ISensorManager", "getDefaultSensor", &_hidl_args);
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

::android::hardware::Return<void> BpHwSensorManager::_hidl_createAshmemDirectChannel(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::hidl_memory& mem, uint64_t size, createAshmemDirectChannel_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::ISensorManager::createAshmemDirectChannel::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&mem);
        _hidl_args.push_back((void *)&size);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.frameworks.sensorservice", "1.0", "ISensorManager", "createAshmemDirectChannel", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwSensorManager::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_mem_parent;

    _hidl_err = _hidl_data.writeBuffer(&mem, sizeof(mem), &_hidl_mem_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            mem,
            &_hidl_data,
            _hidl_mem_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(size);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(3 /* createAshmemDirectChannel */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::sp<::android::frameworks::sensorservice::V1_0::IDirectReportChannel> _hidl_out_chan;
        ::android::frameworks::sensorservice::V1_0::Result _hidl_out_result;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        {
            ::android::sp<::android::hardware::IBinder> _hidl_binder;
            _hidl_err = _hidl_reply.readNullableStrongBinder(&_hidl_binder);
            if (_hidl_err != ::android::OK) { return; }

            _hidl_out_chan = ::android::hardware::fromBinder<::android::frameworks::sensorservice::V1_0::IDirectReportChannel,::android::frameworks::sensorservice::V1_0::BpHwDirectReportChannel,::android::frameworks::sensorservice::V1_0::BnHwDirectReportChannel>(_hidl_binder);
        }

        _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_result);
        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(_hidl_out_chan, _hidl_out_result);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_chan);
            _hidl_args.push_back((void *)&_hidl_out_result);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.frameworks.sensorservice", "1.0", "ISensorManager", "createAshmemDirectChannel", &_hidl_args);
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

::android::hardware::Return<void> BpHwSensorManager::_hidl_createGrallocDirectChannel(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::hidl_handle& buffer, uint64_t size, createGrallocDirectChannel_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::ISensorManager::createGrallocDirectChannel::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&buffer);
        _hidl_args.push_back((void *)&size);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.frameworks.sensorservice", "1.0", "ISensorManager", "createGrallocDirectChannel", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwSensorManager::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeNativeHandleNoDup(buffer);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint64(size);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(4 /* createGrallocDirectChannel */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::sp<::android::frameworks::sensorservice::V1_0::IDirectReportChannel> _hidl_out_chan;
        ::android::frameworks::sensorservice::V1_0::Result _hidl_out_result;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        {
            ::android::sp<::android::hardware::IBinder> _hidl_binder;
            _hidl_err = _hidl_reply.readNullableStrongBinder(&_hidl_binder);
            if (_hidl_err != ::android::OK) { return; }

            _hidl_out_chan = ::android::hardware::fromBinder<::android::frameworks::sensorservice::V1_0::IDirectReportChannel,::android::frameworks::sensorservice::V1_0::BpHwDirectReportChannel,::android::frameworks::sensorservice::V1_0::BnHwDirectReportChannel>(_hidl_binder);
        }

        _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_result);
        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(_hidl_out_chan, _hidl_out_result);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_chan);
            _hidl_args.push_back((void *)&_hidl_out_result);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.frameworks.sensorservice", "1.0", "ISensorManager", "createGrallocDirectChannel", &_hidl_args);
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

::android::hardware::Return<void> BpHwSensorManager::_hidl_createEventQueue(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::sp<::android::frameworks::sensorservice::V1_0::IEventQueueCallback>& callback, createEventQueue_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::ISensorManager::createEventQueue::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&callback);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.frameworks.sensorservice", "1.0", "ISensorManager", "createEventQueue", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwSensorManager::descriptor);
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
    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(5 /* createEventQueue */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::sp<::android::frameworks::sensorservice::V1_0::IEventQueue> _hidl_out_queue;
        ::android::frameworks::sensorservice::V1_0::Result _hidl_out_result;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        {
            ::android::sp<::android::hardware::IBinder> _hidl_binder;
            _hidl_err = _hidl_reply.readNullableStrongBinder(&_hidl_binder);
            if (_hidl_err != ::android::OK) { return; }

            _hidl_out_queue = ::android::hardware::fromBinder<::android::frameworks::sensorservice::V1_0::IEventQueue,::android::frameworks::sensorservice::V1_0::BpHwEventQueue,::android::frameworks::sensorservice::V1_0::BnHwEventQueue>(_hidl_binder);
        }

        _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_result);
        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(_hidl_out_queue, _hidl_out_result);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_queue);
            _hidl_args.push_back((void *)&_hidl_out_result);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.frameworks.sensorservice", "1.0", "ISensorManager", "createEventQueue", &_hidl_args);
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


// Methods from ::android::frameworks::sensorservice::V1_0::ISensorManager follow.
::android::hardware::Return<void> BpHwSensorManager::getSensorList(getSensorList_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::frameworks::sensorservice::V1_0::BpHwSensorManager::_hidl_getSensorList(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwSensorManager::getDefaultSensor(::android::hardware::sensors::V1_0::SensorType type, getDefaultSensor_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::frameworks::sensorservice::V1_0::BpHwSensorManager::_hidl_getDefaultSensor(this, this, type, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwSensorManager::createAshmemDirectChannel(const ::android::hardware::hidl_memory& mem, uint64_t size, createAshmemDirectChannel_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::frameworks::sensorservice::V1_0::BpHwSensorManager::_hidl_createAshmemDirectChannel(this, this, mem, size, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwSensorManager::createGrallocDirectChannel(const ::android::hardware::hidl_handle& buffer, uint64_t size, createGrallocDirectChannel_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::frameworks::sensorservice::V1_0::BpHwSensorManager::_hidl_createGrallocDirectChannel(this, this, buffer, size, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwSensorManager::createEventQueue(const ::android::sp<::android::frameworks::sensorservice::V1_0::IEventQueueCallback>& callback, createEventQueue_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::frameworks::sensorservice::V1_0::BpHwSensorManager::_hidl_createEventQueue(this, this, callback, _hidl_cb);

    return _hidl_out;
}


// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BpHwSensorManager::interfaceChain(interfaceChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwSensorManager::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_debug(this, this, fd, options);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwSensorManager::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceDescriptor(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwSensorManager::getHashChain(getHashChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getHashChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwSensorManager::setHALInstrumentation(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_setHALInstrumentation(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwSensorManager::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    ::android::hardware::ProcessState::self()->startThreadPool();
    ::android::hardware::hidl_binder_death_recipient *binder_recipient = new ::android::hardware::hidl_binder_death_recipient(recipient, cookie, this);
    std::unique_lock<std::mutex> lock(_hidl_mMutex);
    _hidl_mDeathRecipients.push_back(binder_recipient);
    return (remote()->linkToDeath(binder_recipient) == ::android::OK);
}

::android::hardware::Return<void> BpHwSensorManager::ping(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_ping(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwSensorManager::getDebugInfo(getDebugInfo_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getDebugInfo(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwSensorManager::notifySyspropsChanged(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_notifySyspropsChanged(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwSensorManager::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
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


BnHwSensorManager::BnHwSensorManager(const ::android::sp<ISensorManager> &_hidl_impl)
        : ::android::hidl::base::V1_0::BnHwBase(_hidl_impl, "android.frameworks.sensorservice@1.0", "ISensorManager") { 
            _hidl_mImpl = _hidl_impl;
            auto prio = ::android::hardware::getMinSchedulerPolicy(_hidl_impl);
            mSchedPolicy = prio.sched_policy;
            mSchedPriority = prio.prio;
            setRequestingSid(::android::hardware::getRequestingSid(_hidl_impl));
}

BnHwSensorManager::~BnHwSensorManager() {
    ::android::hardware::details::gBnMap->eraseIfEqual(_hidl_mImpl.get(), this);
}

// Methods from ::android::frameworks::sensorservice::V1_0::ISensorManager follow.
::android::status_t BnHwSensorManager::_hidl_getSensorList(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwSensorManager::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::ISensorManager::getSensorList::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.frameworks.sensorservice", "1.0", "ISensorManager", "getSensorList", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<ISensorManager*>(_hidl_this->getImpl().get())->getSensorList([&](const auto &_hidl_out_list, const auto &_hidl_out_result) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("getSensorList: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        size_t _hidl__hidl_out_list_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_list, sizeof(_hidl_out_list), &_hidl__hidl_out_list_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_list_child;

        _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                _hidl_out_list,
                _hidl_reply,
                _hidl__hidl_out_list_parent,
                0 /* parentOffset */, &_hidl__hidl_out_list_child);

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        for (size_t _hidl_index_0 = 0; _hidl_index_0 < _hidl_out_list.size(); ++_hidl_index_0) {
            _hidl_err = writeEmbeddedToParcel(
                    _hidl_out_list[_hidl_index_0],
                    _hidl_reply,
                    _hidl__hidl_out_list_child,
                    _hidl_index_0 * sizeof(::android::hardware::sensors::V1_0::SensorInfo));

            if (_hidl_err != ::android::OK) { goto _hidl_error; }

        }

        _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_result);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_list);
            _hidl_args.push_back((void *)&_hidl_out_result);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.frameworks.sensorservice", "1.0", "ISensorManager", "getSensorList", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("getSensorList: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwSensorManager::_hidl_getDefaultSensor(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwSensorManager::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::sensors::V1_0::SensorType type;

    _hidl_err = _hidl_data.readInt32((int32_t *)&type);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::ISensorManager::getDefaultSensor::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&type);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.frameworks.sensorservice", "1.0", "ISensorManager", "getDefaultSensor", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<ISensorManager*>(_hidl_this->getImpl().get())->getDefaultSensor(type, [&](const auto &_hidl_out_sensor, const auto &_hidl_out_result) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("getDefaultSensor: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        size_t _hidl__hidl_out_sensor_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_sensor, sizeof(_hidl_out_sensor), &_hidl__hidl_out_sensor_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_err = writeEmbeddedToParcel(
                _hidl_out_sensor,
                _hidl_reply,
                _hidl__hidl_out_sensor_parent,
                0 /* parentOffset */);

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_result);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_sensor);
            _hidl_args.push_back((void *)&_hidl_out_result);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.frameworks.sensorservice", "1.0", "ISensorManager", "getDefaultSensor", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("getDefaultSensor: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwSensorManager::_hidl_createAshmemDirectChannel(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwSensorManager::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    const ::android::hardware::hidl_memory* mem;
    uint64_t size;

    size_t _hidl_mem_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*mem), &_hidl_mem_parent,  reinterpret_cast<const void **>(&mem));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_memory &>(*mem),
            _hidl_data,
            _hidl_mem_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint64(&size);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::ISensorManager::createAshmemDirectChannel::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)mem);
        _hidl_args.push_back((void *)&size);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.frameworks.sensorservice", "1.0", "ISensorManager", "createAshmemDirectChannel", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<ISensorManager*>(_hidl_this->getImpl().get())->createAshmemDirectChannel(*mem, size, [&](const auto &_hidl_out_chan, const auto &_hidl_out_result) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("createAshmemDirectChannel: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        if (_hidl_out_chan == nullptr) {
            _hidl_err = _hidl_reply->writeStrongBinder(nullptr);
        } else {
            ::android::sp<::android::hardware::IBinder> _hidl_binder = ::android::hardware::getOrCreateCachedBinder(_hidl_out_chan.get());
            if (_hidl_binder.get() != nullptr) {
                _hidl_err = _hidl_reply->writeStrongBinder(_hidl_binder);
            } else {
                _hidl_err = ::android::UNKNOWN_ERROR;
            }
        }
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_result);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_chan);
            _hidl_args.push_back((void *)&_hidl_out_result);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.frameworks.sensorservice", "1.0", "ISensorManager", "createAshmemDirectChannel", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("createAshmemDirectChannel: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwSensorManager::_hidl_createGrallocDirectChannel(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwSensorManager::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::hidl_handle buffer;
    uint64_t size;

    const native_handle_t *buffer_ptr;

    _hidl_err = _hidl_data.readNullableNativeHandleNoDup(&buffer_ptr);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    buffer = buffer_ptr;
    _hidl_err = _hidl_data.readUint64(&size);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::ISensorManager::createGrallocDirectChannel::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&buffer);
        _hidl_args.push_back((void *)&size);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.frameworks.sensorservice", "1.0", "ISensorManager", "createGrallocDirectChannel", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<ISensorManager*>(_hidl_this->getImpl().get())->createGrallocDirectChannel(buffer, size, [&](const auto &_hidl_out_chan, const auto &_hidl_out_result) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("createGrallocDirectChannel: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        if (_hidl_out_chan == nullptr) {
            _hidl_err = _hidl_reply->writeStrongBinder(nullptr);
        } else {
            ::android::sp<::android::hardware::IBinder> _hidl_binder = ::android::hardware::getOrCreateCachedBinder(_hidl_out_chan.get());
            if (_hidl_binder.get() != nullptr) {
                _hidl_err = _hidl_reply->writeStrongBinder(_hidl_binder);
            } else {
                _hidl_err = ::android::UNKNOWN_ERROR;
            }
        }
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_result);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_chan);
            _hidl_args.push_back((void *)&_hidl_out_result);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.frameworks.sensorservice", "1.0", "ISensorManager", "createGrallocDirectChannel", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("createGrallocDirectChannel: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwSensorManager::_hidl_createEventQueue(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwSensorManager::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::sp<::android::frameworks::sensorservice::V1_0::IEventQueueCallback> callback;

    {
        ::android::sp<::android::hardware::IBinder> _hidl_binder;
        _hidl_err = _hidl_data.readNullableStrongBinder(&_hidl_binder);
        if (_hidl_err != ::android::OK) { return _hidl_err; }

        callback = ::android::hardware::fromBinder<::android::frameworks::sensorservice::V1_0::IEventQueueCallback,::android::frameworks::sensorservice::V1_0::BpHwEventQueueCallback,::android::frameworks::sensorservice::V1_0::BnHwEventQueueCallback>(_hidl_binder);
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::ISensorManager::createEventQueue::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&callback);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.frameworks.sensorservice", "1.0", "ISensorManager", "createEventQueue", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<ISensorManager*>(_hidl_this->getImpl().get())->createEventQueue(callback, [&](const auto &_hidl_out_queue, const auto &_hidl_out_result) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("createEventQueue: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        if (_hidl_out_queue == nullptr) {
            _hidl_err = _hidl_reply->writeStrongBinder(nullptr);
        } else {
            ::android::sp<::android::hardware::IBinder> _hidl_binder = ::android::hardware::getOrCreateCachedBinder(_hidl_out_queue.get());
            if (_hidl_binder.get() != nullptr) {
                _hidl_err = _hidl_reply->writeStrongBinder(_hidl_binder);
            } else {
                _hidl_err = ::android::UNKNOWN_ERROR;
            }
        }
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_result);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_queue);
            _hidl_args.push_back((void *)&_hidl_out_result);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.frameworks.sensorservice", "1.0", "ISensorManager", "createEventQueue", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("createEventQueue: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}


// Methods from ::android::frameworks::sensorservice::V1_0::ISensorManager follow.

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BnHwSensorManager::ping() {
    return ::android::hardware::Void();
}
::android::hardware::Return<void> BnHwSensorManager::getDebugInfo(getDebugInfo_cb _hidl_cb) {
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

::android::status_t BnHwSensorManager::onTransact(
        uint32_t _hidl_code,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        uint32_t _hidl_flags,
        TransactCallback _hidl_cb) {
    ::android::status_t _hidl_err = ::android::OK;

    switch (_hidl_code) {
        case 1 /* getSensorList */:
        {
            _hidl_err = ::android::frameworks::sensorservice::V1_0::BnHwSensorManager::_hidl_getSensorList(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 2 /* getDefaultSensor */:
        {
            _hidl_err = ::android::frameworks::sensorservice::V1_0::BnHwSensorManager::_hidl_getDefaultSensor(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 3 /* createAshmemDirectChannel */:
        {
            _hidl_err = ::android::frameworks::sensorservice::V1_0::BnHwSensorManager::_hidl_createAshmemDirectChannel(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 4 /* createGrallocDirectChannel */:
        {
            _hidl_err = ::android::frameworks::sensorservice::V1_0::BnHwSensorManager::_hidl_createGrallocDirectChannel(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 5 /* createEventQueue */:
        {
            _hidl_err = ::android::frameworks::sensorservice::V1_0::BnHwSensorManager::_hidl_createEventQueue(this, _hidl_data, _hidl_reply, _hidl_cb);
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

BsSensorManager::BsSensorManager(const ::android::sp<::android::frameworks::sensorservice::V1_0::ISensorManager> impl) : ::android::hardware::details::HidlInstrumentor("android.frameworks.sensorservice@1.0", "ISensorManager"), mImpl(impl) {
    mOnewayQueue.start(3000 /* similar limit to binderized */);
}

::android::hardware::Return<void> BsSensorManager::addOnewayTask(std::function<void(void)> fun) {
    if (!mOnewayQueue.push(fun)) {
        return ::android::hardware::Status::fromExceptionCode(
                ::android::hardware::Status::EX_TRANSACTION_FAILED,
                "Passthrough oneway function queue exceeds maximum size.");
    }
    return ::android::hardware::Status();
}

::android::sp<ISensorManager> ISensorManager::tryGetService(const std::string &serviceName, const bool getStub) {
    return ::android::hardware::details::getServiceInternal<BpHwSensorManager>(serviceName, false, getStub);
}

::android::sp<ISensorManager> ISensorManager::getService(const std::string &serviceName, const bool getStub) {
    return ::android::hardware::details::getServiceInternal<BpHwSensorManager>(serviceName, true, getStub);
}

::android::status_t ISensorManager::registerAsService(const std::string &serviceName) {
    return ::android::hardware::details::registerAsServiceInternal(this, serviceName);
}

bool ISensorManager::registerForNotifications(
        const std::string &serviceName,
        const ::android::sp<::android::hidl::manager::V1_0::IServiceNotification> &notification) {
    const ::android::sp<::android::hidl::manager::V1_0::IServiceManager> sm
            = ::android::hardware::defaultServiceManager();
    if (sm == nullptr) {
        return false;
    }
    ::android::hardware::Return<bool> success =
            sm->registerForNotifications("android.frameworks.sensorservice@1.0::ISensorManager",
                    serviceName, notification);
    return success.isOk() && success;
}

static_assert(sizeof(::android::hardware::MQDescriptor<char, ::android::hardware::kSynchronizedReadWrite>) == 32, "wrong size");
static_assert(sizeof(::android::hardware::hidl_handle) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_memory) == 40, "wrong size");
static_assert(sizeof(::android::hardware::hidl_string) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_vec<char>) == 16, "wrong size");

}  // namespace V1_0
}  // namespace sensorservice
}  // namespace frameworks
}  // namespace android
