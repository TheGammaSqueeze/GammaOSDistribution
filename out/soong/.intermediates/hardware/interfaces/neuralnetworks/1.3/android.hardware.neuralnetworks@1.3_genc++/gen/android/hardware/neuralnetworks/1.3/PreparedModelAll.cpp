#define LOG_TAG "android.hardware.neuralnetworks@1.3::PreparedModel"

#include <log/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <hidl/Static.h>
#include <hwbinder/ProcessState.h>
#include <utils/Trace.h>
#include <android/hidl/manager/1.0/IServiceManager.h>
#include <android/hardware/neuralnetworks/1.3/BpHwPreparedModel.h>
#include <android/hardware/neuralnetworks/1.3/BnHwPreparedModel.h>
#include <android/hardware/neuralnetworks/1.3/BsPreparedModel.h>
#include <android/hardware/neuralnetworks/1.2/BpHwPreparedModel.h>
#include <android/hardware/neuralnetworks/1.0/BpHwPreparedModel.h>
#include <android/hidl/base/1.0/BpHwBase.h>
#include <hidl/ServiceManagement.h>

namespace android {
namespace hardware {
namespace neuralnetworks {
namespace V1_3 {

const char* IPreparedModel::descriptor("android.hardware.neuralnetworks@1.3::IPreparedModel");

__attribute__((constructor)) static void static_constructor() {
    ::android::hardware::details::getBnConstructorMap().set(IPreparedModel::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hardware::IBinder> {
                return new BnHwPreparedModel(static_cast<IPreparedModel *>(iIntf));
            });
    ::android::hardware::details::getBsConstructorMap().set(IPreparedModel::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hidl::base::V1_0::IBase> {
                return new BsPreparedModel(static_cast<IPreparedModel *>(iIntf));
            });
}

__attribute__((destructor))static void static_destructor() {
    ::android::hardware::details::getBnConstructorMap().erase(IPreparedModel::descriptor);
    ::android::hardware::details::getBsConstructorMap().erase(IPreparedModel::descriptor);
}

// Methods from ::android::hardware::neuralnetworks::V1_0::IPreparedModel follow.
// no default implementation for: ::android::hardware::Return<::android::hardware::neuralnetworks::V1_0::ErrorStatus> IPreparedModel::execute(const ::android::hardware::neuralnetworks::V1_0::Request& request, const ::android::sp<::android::hardware::neuralnetworks::V1_0::IExecutionCallback>& callback)

// Methods from ::android::hardware::neuralnetworks::V1_2::IPreparedModel follow.
// no default implementation for: ::android::hardware::Return<::android::hardware::neuralnetworks::V1_0::ErrorStatus> IPreparedModel::execute_1_2(const ::android::hardware::neuralnetworks::V1_0::Request& request, ::android::hardware::neuralnetworks::V1_2::MeasureTiming measure, const ::android::sp<::android::hardware::neuralnetworks::V1_2::IExecutionCallback>& callback)
// no default implementation for: ::android::hardware::Return<void> IPreparedModel::executeSynchronously(const ::android::hardware::neuralnetworks::V1_0::Request& request, ::android::hardware::neuralnetworks::V1_2::MeasureTiming measure, executeSynchronously_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IPreparedModel::configureExecutionBurst(const ::android::sp<::android::hardware::neuralnetworks::V1_2::IBurstCallback>& callback, const ::android::hardware::MQDescriptorSync<::android::hardware::neuralnetworks::V1_2::FmqRequestDatum>& requestChannel, const ::android::hardware::MQDescriptorSync<::android::hardware::neuralnetworks::V1_2::FmqResultDatum>& resultChannel, configureExecutionBurst_cb _hidl_cb)

// Methods from ::android::hardware::neuralnetworks::V1_3::IPreparedModel follow.
// no default implementation for: ::android::hardware::Return<::android::hardware::neuralnetworks::V1_3::ErrorStatus> IPreparedModel::execute_1_3(const ::android::hardware::neuralnetworks::V1_3::Request& request, ::android::hardware::neuralnetworks::V1_2::MeasureTiming measure, const ::android::hardware::neuralnetworks::V1_3::OptionalTimePoint& deadline, const ::android::hardware::neuralnetworks::V1_3::OptionalTimeoutDuration& loopTimeoutDuration, const ::android::sp<::android::hardware::neuralnetworks::V1_3::IExecutionCallback>& callback)
// no default implementation for: ::android::hardware::Return<void> IPreparedModel::executeSynchronously_1_3(const ::android::hardware::neuralnetworks::V1_3::Request& request, ::android::hardware::neuralnetworks::V1_2::MeasureTiming measure, const ::android::hardware::neuralnetworks::V1_3::OptionalTimePoint& deadline, const ::android::hardware::neuralnetworks::V1_3::OptionalTimeoutDuration& loopTimeoutDuration, executeSynchronously_1_3_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IPreparedModel::executeFenced(const ::android::hardware::neuralnetworks::V1_3::Request& request, const ::android::hardware::hidl_vec<::android::hardware::hidl_handle>& waitFor, ::android::hardware::neuralnetworks::V1_2::MeasureTiming measure, const ::android::hardware::neuralnetworks::V1_3::OptionalTimePoint& deadline, const ::android::hardware::neuralnetworks::V1_3::OptionalTimeoutDuration& loopTimeoutDuration, const ::android::hardware::neuralnetworks::V1_3::OptionalTimeoutDuration& duration, executeFenced_cb _hidl_cb)

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> IPreparedModel::interfaceChain(interfaceChain_cb _hidl_cb){
    _hidl_cb({
        ::android::hardware::neuralnetworks::V1_3::IPreparedModel::descriptor,
        ::android::hardware::neuralnetworks::V1_2::IPreparedModel::descriptor,
        ::android::hardware::neuralnetworks::V1_0::IPreparedModel::descriptor,
        ::android::hidl::base::V1_0::IBase::descriptor,
    });
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IPreparedModel::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    (void)fd;
    (void)options;
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IPreparedModel::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    _hidl_cb(::android::hardware::neuralnetworks::V1_3::IPreparedModel::descriptor);
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IPreparedModel::getHashChain(getHashChain_cb _hidl_cb){
    _hidl_cb({
        (uint8_t[32]){15,223,173,98,194,236,51,181,46,102,135,0,78,90,25,113,192,45,16,185,62,228,210,109,245,204,255,124,224,50,73,74} /* 0fdfad62c2ec33b52e6687004e5a1971c02d10b93ee4d26df5ccff7ce032494a */,
        (uint8_t[32]){64,231,28,214,147,222,91,131,35,37,197,216,240,129,242,255,32,167,186,43,137,212,1,206,229,180,179,235,14,36,22,129} /* 40e71cd693de5b832325c5d8f081f2ff20a7ba2b89d401cee5b4b3eb0e241681 */,
        (uint8_t[32]){235,47,160,200,131,194,24,93,81,75,224,184,76,23,155,40,55,83,239,12,27,119,180,91,79,53,155,210,59,186,139,117} /* eb2fa0c883c2185d514be0b84c179b283753ef0c1b77b45b4f359bd23bba8b75 */,
        (uint8_t[32]){236,127,215,158,208,45,250,133,188,73,148,38,173,174,62,190,35,239,5,36,243,205,105,87,19,147,36,184,59,24,202,76} /* ec7fd79ed02dfa85bc499426adae3ebe23ef0524f3cd6957139324b83b18ca4c */});
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IPreparedModel::setHALInstrumentation(){
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> IPreparedModel::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    (void)cookie;
    return (recipient != nullptr);
}

::android::hardware::Return<void> IPreparedModel::ping(){
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IPreparedModel::getDebugInfo(getDebugInfo_cb _hidl_cb){
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

::android::hardware::Return<void> IPreparedModel::notifySyspropsChanged(){
    ::android::report_sysprop_change();
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> IPreparedModel::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
    return (recipient != nullptr);
}


::android::hardware::Return<::android::sp<::android::hardware::neuralnetworks::V1_3::IPreparedModel>> IPreparedModel::castFrom(const ::android::sp<::android::hardware::neuralnetworks::V1_3::IPreparedModel>& parent, bool /* emitError */) {
    return parent;
}

::android::hardware::Return<::android::sp<::android::hardware::neuralnetworks::V1_3::IPreparedModel>> IPreparedModel::castFrom(const ::android::sp<::android::hardware::neuralnetworks::V1_2::IPreparedModel>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<IPreparedModel, ::android::hardware::neuralnetworks::V1_2::IPreparedModel, BpHwPreparedModel>(
            parent, "android.hardware.neuralnetworks@1.3::IPreparedModel", emitError);
}

::android::hardware::Return<::android::sp<::android::hardware::neuralnetworks::V1_3::IPreparedModel>> IPreparedModel::castFrom(const ::android::sp<::android::hardware::neuralnetworks::V1_0::IPreparedModel>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<IPreparedModel, ::android::hardware::neuralnetworks::V1_0::IPreparedModel, BpHwPreparedModel>(
            parent, "android.hardware.neuralnetworks@1.3::IPreparedModel", emitError);
}

::android::hardware::Return<::android::sp<::android::hardware::neuralnetworks::V1_3::IPreparedModel>> IPreparedModel::castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<IPreparedModel, ::android::hidl::base::V1_0::IBase, BpHwPreparedModel>(
            parent, "android.hardware.neuralnetworks@1.3::IPreparedModel", emitError);
}

BpHwPreparedModel::BpHwPreparedModel(const ::android::sp<::android::hardware::IBinder> &_hidl_impl)
        : BpInterface<IPreparedModel>(_hidl_impl),
          ::android::hardware::details::HidlInstrumentor("android.hardware.neuralnetworks@1.3", "IPreparedModel") {
}

void BpHwPreparedModel::onLastStrongRef(const void* id) {
    {
        std::unique_lock<std::mutex> lock(_hidl_mMutex);
        _hidl_mDeathRecipients.clear();
    }

    BpInterface<IPreparedModel>::onLastStrongRef(id);
}
// Methods from ::android::hardware::neuralnetworks::V1_3::IPreparedModel follow.
::android::hardware::Return<::android::hardware::neuralnetworks::V1_3::ErrorStatus> BpHwPreparedModel::_hidl_execute_1_3(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::neuralnetworks::V1_3::Request& request, ::android::hardware::neuralnetworks::V1_2::MeasureTiming measure, const ::android::hardware::neuralnetworks::V1_3::OptionalTimePoint& deadline, const ::android::hardware::neuralnetworks::V1_3::OptionalTimeoutDuration& loopTimeoutDuration, const ::android::sp<::android::hardware::neuralnetworks::V1_3::IExecutionCallback>& callback) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IPreparedModel::execute_1_3::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&request);
        _hidl_args.push_back((void *)&measure);
        _hidl_args.push_back((void *)&deadline);
        _hidl_args.push_back((void *)&loopTimeoutDuration);
        _hidl_args.push_back((void *)&callback);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.neuralnetworks", "1.3", "IPreparedModel", "execute_1_3", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    ::android::hardware::neuralnetworks::V1_3::ErrorStatus _hidl_out_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwPreparedModel::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_request_parent;

    _hidl_err = _hidl_data.writeBuffer(&request, sizeof(request), &_hidl_request_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = writeEmbeddedToParcel(
            request,
            &_hidl_data,
            _hidl_request_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32((int32_t)measure);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_deadline_parent;

    _hidl_err = _hidl_data.writeBuffer(&deadline, sizeof(deadline), &_hidl_deadline_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_loopTimeoutDuration_parent;

    _hidl_err = _hidl_data.writeBuffer(&loopTimeoutDuration, sizeof(loopTimeoutDuration), &_hidl_loopTimeoutDuration_parent);
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
    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(5 /* execute_1_3 */, _hidl_data, &_hidl_reply, 0 /* flags */);
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
            callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.neuralnetworks", "1.3", "IPreparedModel", "execute_1_3", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    return ::android::hardware::Return<::android::hardware::neuralnetworks::V1_3::ErrorStatus>(_hidl_out_status);

_hidl_error:
    _hidl_status.setFromStatusT(_hidl_err);
    return ::android::hardware::Return<::android::hardware::neuralnetworks::V1_3::ErrorStatus>(_hidl_status);
}

::android::hardware::Return<void> BpHwPreparedModel::_hidl_executeSynchronously_1_3(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::neuralnetworks::V1_3::Request& request, ::android::hardware::neuralnetworks::V1_2::MeasureTiming measure, const ::android::hardware::neuralnetworks::V1_3::OptionalTimePoint& deadline, const ::android::hardware::neuralnetworks::V1_3::OptionalTimeoutDuration& loopTimeoutDuration, executeSynchronously_1_3_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IPreparedModel::executeSynchronously_1_3::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&request);
        _hidl_args.push_back((void *)&measure);
        _hidl_args.push_back((void *)&deadline);
        _hidl_args.push_back((void *)&loopTimeoutDuration);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.neuralnetworks", "1.3", "IPreparedModel", "executeSynchronously_1_3", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwPreparedModel::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_request_parent;

    _hidl_err = _hidl_data.writeBuffer(&request, sizeof(request), &_hidl_request_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = writeEmbeddedToParcel(
            request,
            &_hidl_data,
            _hidl_request_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeInt32((int32_t)measure);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_deadline_parent;

    _hidl_err = _hidl_data.writeBuffer(&deadline, sizeof(deadline), &_hidl_deadline_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_loopTimeoutDuration_parent;

    _hidl_err = _hidl_data.writeBuffer(&loopTimeoutDuration, sizeof(loopTimeoutDuration), &_hidl_loopTimeoutDuration_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(6 /* executeSynchronously_1_3 */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::neuralnetworks::V1_3::ErrorStatus _hidl_out_status;
        const ::android::hardware::hidl_vec<::android::hardware::neuralnetworks::V1_2::OutputShape>* _hidl_out_outputShapes;
        ::android::hardware::neuralnetworks::V1_2::Timing* _hidl_out_timing;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_status);
        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_outputShapes_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_outputShapes), &_hidl__hidl_out_outputShapes_parent,  reinterpret_cast<const void **>(&_hidl_out_outputShapes));

        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_outputShapes_child;

        _hidl_err = ::android::hardware::readEmbeddedFromParcel(
                const_cast<::android::hardware::hidl_vec<::android::hardware::neuralnetworks::V1_2::OutputShape> &>(*_hidl_out_outputShapes),
                _hidl_reply,
                _hidl__hidl_out_outputShapes_parent,
                0 /* parentOffset */, &_hidl__hidl_out_outputShapes_child);

        if (_hidl_err != ::android::OK) { return; }

        for (size_t _hidl_index_0 = 0; _hidl_index_0 < _hidl_out_outputShapes->size(); ++_hidl_index_0) {
            _hidl_err = readEmbeddedFromParcel(
                    const_cast<::android::hardware::neuralnetworks::V1_2::OutputShape &>((*_hidl_out_outputShapes)[_hidl_index_0]),
                    _hidl_reply,
                    _hidl__hidl_out_outputShapes_child,
                    _hidl_index_0 * sizeof(::android::hardware::neuralnetworks::V1_2::OutputShape));

            if (_hidl_err != ::android::OK) { return; }

        }

        size_t _hidl__hidl_out_timing_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_timing), &_hidl__hidl_out_timing_parent,  const_cast<const void**>(reinterpret_cast<void **>(&_hidl_out_timing)));
        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(_hidl_out_status, *_hidl_out_outputShapes, *_hidl_out_timing);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)_hidl_out_outputShapes);
            _hidl_args.push_back((void *)_hidl_out_timing);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.neuralnetworks", "1.3", "IPreparedModel", "executeSynchronously_1_3", &_hidl_args);
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

::android::hardware::Return<void> BpHwPreparedModel::_hidl_executeFenced(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::neuralnetworks::V1_3::Request& request, const ::android::hardware::hidl_vec<::android::hardware::hidl_handle>& waitFor, ::android::hardware::neuralnetworks::V1_2::MeasureTiming measure, const ::android::hardware::neuralnetworks::V1_3::OptionalTimePoint& deadline, const ::android::hardware::neuralnetworks::V1_3::OptionalTimeoutDuration& loopTimeoutDuration, const ::android::hardware::neuralnetworks::V1_3::OptionalTimeoutDuration& duration, executeFenced_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IPreparedModel::executeFenced::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&request);
        _hidl_args.push_back((void *)&waitFor);
        _hidl_args.push_back((void *)&measure);
        _hidl_args.push_back((void *)&deadline);
        _hidl_args.push_back((void *)&loopTimeoutDuration);
        _hidl_args.push_back((void *)&duration);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.neuralnetworks", "1.3", "IPreparedModel", "executeFenced", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwPreparedModel::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_request_parent;

    _hidl_err = _hidl_data.writeBuffer(&request, sizeof(request), &_hidl_request_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = writeEmbeddedToParcel(
            request,
            &_hidl_data,
            _hidl_request_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_waitFor_parent;

    _hidl_err = _hidl_data.writeBuffer(&waitFor, sizeof(waitFor), &_hidl_waitFor_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_waitFor_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            waitFor,
            &_hidl_data,
            _hidl_waitFor_parent,
            0 /* parentOffset */, &_hidl_waitFor_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < waitFor.size(); ++_hidl_index_0) {
        _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                waitFor[_hidl_index_0],
                &_hidl_data,
                _hidl_waitFor_child,
                _hidl_index_0 * sizeof(::android::hardware::hidl_handle));

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    }

    _hidl_err = _hidl_data.writeInt32((int32_t)measure);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_deadline_parent;

    _hidl_err = _hidl_data.writeBuffer(&deadline, sizeof(deadline), &_hidl_deadline_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_loopTimeoutDuration_parent;

    _hidl_err = _hidl_data.writeBuffer(&loopTimeoutDuration, sizeof(loopTimeoutDuration), &_hidl_loopTimeoutDuration_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_duration_parent;

    _hidl_err = _hidl_data.writeBuffer(&duration, sizeof(duration), &_hidl_duration_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(7 /* executeFenced */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        ::android::hardware::neuralnetworks::V1_3::ErrorStatus _hidl_out_status;
        ::android::hardware::hidl_handle _hidl_out_syncFence;
        ::android::sp<::android::hardware::neuralnetworks::V1_3::IFencedExecutionCallback> _hidl_out_callback;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        _hidl_err = _hidl_reply.readInt32((int32_t *)&_hidl_out_status);
        if (_hidl_err != ::android::OK) { return; }

        const native_handle_t *_hidl_out_syncFence_ptr;

        _hidl_err = _hidl_reply.readNullableNativeHandleNoDup(&_hidl_out_syncFence_ptr);

        if (_hidl_err != ::android::OK) { return; }

        _hidl_out_syncFence = _hidl_out_syncFence_ptr;
        {
            ::android::sp<::android::hardware::IBinder> _hidl_binder;
            _hidl_err = _hidl_reply.readNullableStrongBinder(&_hidl_binder);
            if (_hidl_err != ::android::OK) { return; }

            _hidl_out_callback = ::android::hardware::fromBinder<::android::hardware::neuralnetworks::V1_3::IFencedExecutionCallback,::android::hardware::neuralnetworks::V1_3::BpHwFencedExecutionCallback,::android::hardware::neuralnetworks::V1_3::BnHwFencedExecutionCallback>(_hidl_binder);
        }

        _hidl_cb(_hidl_out_status, _hidl_out_syncFence, _hidl_out_callback);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)&_hidl_out_syncFence);
            _hidl_args.push_back((void *)&_hidl_out_callback);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.neuralnetworks", "1.3", "IPreparedModel", "executeFenced", &_hidl_args);
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


// Methods from ::android::hardware::neuralnetworks::V1_0::IPreparedModel follow.
::android::hardware::Return<::android::hardware::neuralnetworks::V1_0::ErrorStatus> BpHwPreparedModel::execute(const ::android::hardware::neuralnetworks::V1_0::Request& request, const ::android::sp<::android::hardware::neuralnetworks::V1_0::IExecutionCallback>& callback){
    ::android::hardware::Return<::android::hardware::neuralnetworks::V1_0::ErrorStatus>  _hidl_out = ::android::hardware::neuralnetworks::V1_0::BpHwPreparedModel::_hidl_execute(this, this, request, callback);

    return _hidl_out;
}


// Methods from ::android::hardware::neuralnetworks::V1_2::IPreparedModel follow.
::android::hardware::Return<::android::hardware::neuralnetworks::V1_0::ErrorStatus> BpHwPreparedModel::execute_1_2(const ::android::hardware::neuralnetworks::V1_0::Request& request, ::android::hardware::neuralnetworks::V1_2::MeasureTiming measure, const ::android::sp<::android::hardware::neuralnetworks::V1_2::IExecutionCallback>& callback){
    ::android::hardware::Return<::android::hardware::neuralnetworks::V1_0::ErrorStatus>  _hidl_out = ::android::hardware::neuralnetworks::V1_2::BpHwPreparedModel::_hidl_execute_1_2(this, this, request, measure, callback);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwPreparedModel::executeSynchronously(const ::android::hardware::neuralnetworks::V1_0::Request& request, ::android::hardware::neuralnetworks::V1_2::MeasureTiming measure, executeSynchronously_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::neuralnetworks::V1_2::BpHwPreparedModel::_hidl_executeSynchronously(this, this, request, measure, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwPreparedModel::configureExecutionBurst(const ::android::sp<::android::hardware::neuralnetworks::V1_2::IBurstCallback>& callback, const ::android::hardware::MQDescriptorSync<::android::hardware::neuralnetworks::V1_2::FmqRequestDatum>& requestChannel, const ::android::hardware::MQDescriptorSync<::android::hardware::neuralnetworks::V1_2::FmqResultDatum>& resultChannel, configureExecutionBurst_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::neuralnetworks::V1_2::BpHwPreparedModel::_hidl_configureExecutionBurst(this, this, callback, requestChannel, resultChannel, _hidl_cb);

    return _hidl_out;
}


// Methods from ::android::hardware::neuralnetworks::V1_3::IPreparedModel follow.
::android::hardware::Return<::android::hardware::neuralnetworks::V1_3::ErrorStatus> BpHwPreparedModel::execute_1_3(const ::android::hardware::neuralnetworks::V1_3::Request& request, ::android::hardware::neuralnetworks::V1_2::MeasureTiming measure, const ::android::hardware::neuralnetworks::V1_3::OptionalTimePoint& deadline, const ::android::hardware::neuralnetworks::V1_3::OptionalTimeoutDuration& loopTimeoutDuration, const ::android::sp<::android::hardware::neuralnetworks::V1_3::IExecutionCallback>& callback){
    ::android::hardware::Return<::android::hardware::neuralnetworks::V1_3::ErrorStatus>  _hidl_out = ::android::hardware::neuralnetworks::V1_3::BpHwPreparedModel::_hidl_execute_1_3(this, this, request, measure, deadline, loopTimeoutDuration, callback);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwPreparedModel::executeSynchronously_1_3(const ::android::hardware::neuralnetworks::V1_3::Request& request, ::android::hardware::neuralnetworks::V1_2::MeasureTiming measure, const ::android::hardware::neuralnetworks::V1_3::OptionalTimePoint& deadline, const ::android::hardware::neuralnetworks::V1_3::OptionalTimeoutDuration& loopTimeoutDuration, executeSynchronously_1_3_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::neuralnetworks::V1_3::BpHwPreparedModel::_hidl_executeSynchronously_1_3(this, this, request, measure, deadline, loopTimeoutDuration, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwPreparedModel::executeFenced(const ::android::hardware::neuralnetworks::V1_3::Request& request, const ::android::hardware::hidl_vec<::android::hardware::hidl_handle>& waitFor, ::android::hardware::neuralnetworks::V1_2::MeasureTiming measure, const ::android::hardware::neuralnetworks::V1_3::OptionalTimePoint& deadline, const ::android::hardware::neuralnetworks::V1_3::OptionalTimeoutDuration& loopTimeoutDuration, const ::android::hardware::neuralnetworks::V1_3::OptionalTimeoutDuration& duration, executeFenced_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::neuralnetworks::V1_3::BpHwPreparedModel::_hidl_executeFenced(this, this, request, waitFor, measure, deadline, loopTimeoutDuration, duration, _hidl_cb);

    return _hidl_out;
}


// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BpHwPreparedModel::interfaceChain(interfaceChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwPreparedModel::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_debug(this, this, fd, options);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwPreparedModel::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceDescriptor(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwPreparedModel::getHashChain(getHashChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getHashChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwPreparedModel::setHALInstrumentation(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_setHALInstrumentation(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwPreparedModel::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    ::android::hardware::ProcessState::self()->startThreadPool();
    ::android::hardware::hidl_binder_death_recipient *binder_recipient = new ::android::hardware::hidl_binder_death_recipient(recipient, cookie, this);
    std::unique_lock<std::mutex> lock(_hidl_mMutex);
    _hidl_mDeathRecipients.push_back(binder_recipient);
    return (remote()->linkToDeath(binder_recipient) == ::android::OK);
}

::android::hardware::Return<void> BpHwPreparedModel::ping(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_ping(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwPreparedModel::getDebugInfo(getDebugInfo_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getDebugInfo(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwPreparedModel::notifySyspropsChanged(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_notifySyspropsChanged(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwPreparedModel::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
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


BnHwPreparedModel::BnHwPreparedModel(const ::android::sp<IPreparedModel> &_hidl_impl)
        : ::android::hidl::base::V1_0::BnHwBase(_hidl_impl, "android.hardware.neuralnetworks@1.3", "IPreparedModel") { 
            _hidl_mImpl = _hidl_impl;
            auto prio = ::android::hardware::getMinSchedulerPolicy(_hidl_impl);
            mSchedPolicy = prio.sched_policy;
            mSchedPriority = prio.prio;
            setRequestingSid(::android::hardware::getRequestingSid(_hidl_impl));
}

BnHwPreparedModel::~BnHwPreparedModel() {
    ::android::hardware::details::gBnMap->eraseIfEqual(_hidl_mImpl.get(), this);
}

// Methods from ::android::hardware::neuralnetworks::V1_3::IPreparedModel follow.
::android::status_t BnHwPreparedModel::_hidl_execute_1_3(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwPreparedModel::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::neuralnetworks::V1_3::Request* request;
    ::android::hardware::neuralnetworks::V1_2::MeasureTiming measure;
    ::android::hardware::neuralnetworks::V1_3::OptionalTimePoint* deadline;
    ::android::hardware::neuralnetworks::V1_3::OptionalTimeoutDuration* loopTimeoutDuration;
    ::android::sp<::android::hardware::neuralnetworks::V1_3::IExecutionCallback> callback;

    size_t _hidl_request_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*request), &_hidl_request_parent,  const_cast<const void**>(reinterpret_cast<void **>(&request)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::neuralnetworks::V1_3::Request &>(*request),
            _hidl_data,
            _hidl_request_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readInt32((int32_t *)&measure);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_deadline_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*deadline), &_hidl_deadline_parent,  const_cast<const void**>(reinterpret_cast<void **>(&deadline)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_loopTimeoutDuration_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*loopTimeoutDuration), &_hidl_loopTimeoutDuration_parent,  const_cast<const void**>(reinterpret_cast<void **>(&loopTimeoutDuration)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    {
        ::android::sp<::android::hardware::IBinder> _hidl_binder;
        _hidl_err = _hidl_data.readNullableStrongBinder(&_hidl_binder);
        if (_hidl_err != ::android::OK) { return _hidl_err; }

        callback = ::android::hardware::fromBinder<::android::hardware::neuralnetworks::V1_3::IExecutionCallback,::android::hardware::neuralnetworks::V1_3::BpHwExecutionCallback,::android::hardware::neuralnetworks::V1_3::BnHwExecutionCallback>(_hidl_binder);
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IPreparedModel::execute_1_3::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)request);
        _hidl_args.push_back((void *)&measure);
        _hidl_args.push_back((void *)deadline);
        _hidl_args.push_back((void *)loopTimeoutDuration);
        _hidl_args.push_back((void *)&callback);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.neuralnetworks", "1.3", "IPreparedModel", "execute_1_3", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::neuralnetworks::V1_3::ErrorStatus _hidl_out_status = static_cast<IPreparedModel*>(_hidl_this->getImpl().get())->execute_1_3(*request, measure, *deadline, *loopTimeoutDuration, callback);

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
            callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.neuralnetworks", "1.3", "IPreparedModel", "execute_1_3", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    if (_hidl_err != ::android::OK) { return _hidl_err; }
    _hidl_cb(*_hidl_reply);
    return _hidl_err;
}

::android::status_t BnHwPreparedModel::_hidl_executeSynchronously_1_3(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwPreparedModel::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::neuralnetworks::V1_3::Request* request;
    ::android::hardware::neuralnetworks::V1_2::MeasureTiming measure;
    ::android::hardware::neuralnetworks::V1_3::OptionalTimePoint* deadline;
    ::android::hardware::neuralnetworks::V1_3::OptionalTimeoutDuration* loopTimeoutDuration;

    size_t _hidl_request_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*request), &_hidl_request_parent,  const_cast<const void**>(reinterpret_cast<void **>(&request)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::neuralnetworks::V1_3::Request &>(*request),
            _hidl_data,
            _hidl_request_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readInt32((int32_t *)&measure);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_deadline_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*deadline), &_hidl_deadline_parent,  const_cast<const void**>(reinterpret_cast<void **>(&deadline)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_loopTimeoutDuration_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*loopTimeoutDuration), &_hidl_loopTimeoutDuration_parent,  const_cast<const void**>(reinterpret_cast<void **>(&loopTimeoutDuration)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IPreparedModel::executeSynchronously_1_3::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)request);
        _hidl_args.push_back((void *)&measure);
        _hidl_args.push_back((void *)deadline);
        _hidl_args.push_back((void *)loopTimeoutDuration);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.neuralnetworks", "1.3", "IPreparedModel", "executeSynchronously_1_3", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IPreparedModel*>(_hidl_this->getImpl().get())->executeSynchronously_1_3(*request, measure, *deadline, *loopTimeoutDuration, [&](const auto &_hidl_out_status, const auto &_hidl_out_outputShapes, const auto &_hidl_out_timing) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("executeSynchronously_1_3: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_status);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_outputShapes_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_outputShapes, sizeof(_hidl_out_outputShapes), &_hidl__hidl_out_outputShapes_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_outputShapes_child;

        _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                _hidl_out_outputShapes,
                _hidl_reply,
                _hidl__hidl_out_outputShapes_parent,
                0 /* parentOffset */, &_hidl__hidl_out_outputShapes_child);

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        for (size_t _hidl_index_0 = 0; _hidl_index_0 < _hidl_out_outputShapes.size(); ++_hidl_index_0) {
            _hidl_err = writeEmbeddedToParcel(
                    _hidl_out_outputShapes[_hidl_index_0],
                    _hidl_reply,
                    _hidl__hidl_out_outputShapes_child,
                    _hidl_index_0 * sizeof(::android::hardware::neuralnetworks::V1_2::OutputShape));

            if (_hidl_err != ::android::OK) { goto _hidl_error; }

        }

        size_t _hidl__hidl_out_timing_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_timing, sizeof(_hidl_out_timing), &_hidl__hidl_out_timing_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_status);
            _hidl_args.push_back((void *)&_hidl_out_outputShapes);
            _hidl_args.push_back((void *)&_hidl_out_timing);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.neuralnetworks", "1.3", "IPreparedModel", "executeSynchronously_1_3", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("executeSynchronously_1_3: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwPreparedModel::_hidl_executeFenced(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwPreparedModel::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    ::android::hardware::neuralnetworks::V1_3::Request* request;
    const ::android::hardware::hidl_vec<::android::hardware::hidl_handle>* waitFor;
    ::android::hardware::neuralnetworks::V1_2::MeasureTiming measure;
    ::android::hardware::neuralnetworks::V1_3::OptionalTimePoint* deadline;
    ::android::hardware::neuralnetworks::V1_3::OptionalTimeoutDuration* loopTimeoutDuration;
    ::android::hardware::neuralnetworks::V1_3::OptionalTimeoutDuration* duration;

    size_t _hidl_request_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*request), &_hidl_request_parent,  const_cast<const void**>(reinterpret_cast<void **>(&request)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::neuralnetworks::V1_3::Request &>(*request),
            _hidl_data,
            _hidl_request_parent,
            0 /* parentOffset */);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_waitFor_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*waitFor), &_hidl_waitFor_parent,  reinterpret_cast<const void **>(&waitFor));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_waitFor_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::hidl_handle> &>(*waitFor),
            _hidl_data,
            _hidl_waitFor_parent,
            0 /* parentOffset */, &_hidl_waitFor_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < waitFor->size(); ++_hidl_index_0) {
        _hidl_err = ::android::hardware::readEmbeddedFromParcel(
                const_cast<::android::hardware::hidl_handle &>((*waitFor)[_hidl_index_0]),
                _hidl_data,
                _hidl_waitFor_child,
                _hidl_index_0 * sizeof(::android::hardware::hidl_handle));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    _hidl_err = _hidl_data.readInt32((int32_t *)&measure);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_deadline_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*deadline), &_hidl_deadline_parent,  const_cast<const void**>(reinterpret_cast<void **>(&deadline)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_loopTimeoutDuration_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*loopTimeoutDuration), &_hidl_loopTimeoutDuration_parent,  const_cast<const void**>(reinterpret_cast<void **>(&loopTimeoutDuration)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_duration_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*duration), &_hidl_duration_parent,  const_cast<const void**>(reinterpret_cast<void **>(&duration)));
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IPreparedModel::executeFenced::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)request);
        _hidl_args.push_back((void *)waitFor);
        _hidl_args.push_back((void *)&measure);
        _hidl_args.push_back((void *)deadline);
        _hidl_args.push_back((void *)loopTimeoutDuration);
        _hidl_args.push_back((void *)duration);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.neuralnetworks", "1.3", "IPreparedModel", "executeFenced", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IPreparedModel*>(_hidl_this->getImpl().get())->executeFenced(*request, *waitFor, measure, *deadline, *loopTimeoutDuration, *duration, [&](const auto &_hidl_out_status, const auto &_hidl_out_syncFence, const auto &_hidl_out_callback) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("executeFenced: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        _hidl_err = _hidl_reply->writeInt32((int32_t)_hidl_out_status);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_err = _hidl_reply->writeNativeHandleNoDup(_hidl_out_syncFence);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        if (_hidl_out_callback == nullptr) {
            _hidl_err = _hidl_reply->writeStrongBinder(nullptr);
        } else {
            ::android::sp<::android::hardware::IBinder> _hidl_binder = ::android::hardware::getOrCreateCachedBinder(_hidl_out_callback.get());
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
            _hidl_args.push_back((void *)&_hidl_out_syncFence);
            _hidl_args.push_back((void *)&_hidl_out_callback);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.neuralnetworks", "1.3", "IPreparedModel", "executeFenced", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("executeFenced: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}


// Methods from ::android::hardware::neuralnetworks::V1_0::IPreparedModel follow.

// Methods from ::android::hardware::neuralnetworks::V1_2::IPreparedModel follow.

// Methods from ::android::hardware::neuralnetworks::V1_3::IPreparedModel follow.

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BnHwPreparedModel::ping() {
    return ::android::hardware::Void();
}
::android::hardware::Return<void> BnHwPreparedModel::getDebugInfo(getDebugInfo_cb _hidl_cb) {
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

::android::status_t BnHwPreparedModel::onTransact(
        uint32_t _hidl_code,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        uint32_t _hidl_flags,
        TransactCallback _hidl_cb) {
    ::android::status_t _hidl_err = ::android::OK;

    switch (_hidl_code) {
        case 1 /* execute */:
        {
            _hidl_err = ::android::hardware::neuralnetworks::V1_0::BnHwPreparedModel::_hidl_execute(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 2 /* execute_1_2 */:
        {
            _hidl_err = ::android::hardware::neuralnetworks::V1_2::BnHwPreparedModel::_hidl_execute_1_2(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 3 /* executeSynchronously */:
        {
            _hidl_err = ::android::hardware::neuralnetworks::V1_2::BnHwPreparedModel::_hidl_executeSynchronously(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 4 /* configureExecutionBurst */:
        {
            _hidl_err = ::android::hardware::neuralnetworks::V1_2::BnHwPreparedModel::_hidl_configureExecutionBurst(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 5 /* execute_1_3 */:
        {
            _hidl_err = ::android::hardware::neuralnetworks::V1_3::BnHwPreparedModel::_hidl_execute_1_3(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 6 /* executeSynchronously_1_3 */:
        {
            _hidl_err = ::android::hardware::neuralnetworks::V1_3::BnHwPreparedModel::_hidl_executeSynchronously_1_3(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 7 /* executeFenced */:
        {
            _hidl_err = ::android::hardware::neuralnetworks::V1_3::BnHwPreparedModel::_hidl_executeFenced(this, _hidl_data, _hidl_reply, _hidl_cb);
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

BsPreparedModel::BsPreparedModel(const ::android::sp<::android::hardware::neuralnetworks::V1_3::IPreparedModel> impl) : ::android::hardware::details::HidlInstrumentor("android.hardware.neuralnetworks@1.3", "IPreparedModel"), mImpl(impl) {
    mOnewayQueue.start(3000 /* similar limit to binderized */);
}

::android::hardware::Return<void> BsPreparedModel::addOnewayTask(std::function<void(void)> fun) {
    if (!mOnewayQueue.push(fun)) {
        return ::android::hardware::Status::fromExceptionCode(
                ::android::hardware::Status::EX_TRANSACTION_FAILED,
                "Passthrough oneway function queue exceeds maximum size.");
    }
    return ::android::hardware::Status();
}

::android::sp<IPreparedModel> IPreparedModel::tryGetService(const std::string &serviceName, const bool getStub) {
    return ::android::hardware::details::getServiceInternal<BpHwPreparedModel>(serviceName, false, getStub);
}

::android::sp<IPreparedModel> IPreparedModel::getService(const std::string &serviceName, const bool getStub) {
    return ::android::hardware::details::getServiceInternal<BpHwPreparedModel>(serviceName, true, getStub);
}

::android::status_t IPreparedModel::registerAsService(const std::string &serviceName) {
    return ::android::hardware::details::registerAsServiceInternal(this, serviceName);
}

bool IPreparedModel::registerForNotifications(
        const std::string &serviceName,
        const ::android::sp<::android::hidl::manager::V1_0::IServiceNotification> &notification) {
    const ::android::sp<::android::hidl::manager::V1_0::IServiceManager> sm
            = ::android::hardware::defaultServiceManager();
    if (sm == nullptr) {
        return false;
    }
    ::android::hardware::Return<bool> success =
            sm->registerForNotifications("android.hardware.neuralnetworks@1.3::IPreparedModel",
                    serviceName, notification);
    return success.isOk() && success;
}

static_assert(sizeof(::android::hardware::MQDescriptor<char, ::android::hardware::kSynchronizedReadWrite>) == 32, "wrong size");
static_assert(sizeof(::android::hardware::hidl_handle) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_memory) == 40, "wrong size");
static_assert(sizeof(::android::hardware::hidl_string) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_vec<char>) == 16, "wrong size");

}  // namespace V1_3
}  // namespace neuralnetworks
}  // namespace hardware
}  // namespace android
