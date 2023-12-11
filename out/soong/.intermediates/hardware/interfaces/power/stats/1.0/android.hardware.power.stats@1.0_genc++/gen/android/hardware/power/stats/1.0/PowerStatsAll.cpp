#define LOG_TAG "android.hardware.power.stats@1.0::PowerStats"

#include <log/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <hidl/Static.h>
#include <hwbinder/ProcessState.h>
#include <utils/Trace.h>
#include <android/hidl/manager/1.0/IServiceManager.h>
#include <android/hardware/power/stats/1.0/BpHwPowerStats.h>
#include <android/hardware/power/stats/1.0/BnHwPowerStats.h>
#include <android/hardware/power/stats/1.0/BsPowerStats.h>
#include <android/hidl/base/1.0/BpHwBase.h>
#include <hidl/ServiceManagement.h>

namespace android {
namespace hardware {
namespace power {
namespace stats {
namespace V1_0 {

const char* IPowerStats::descriptor("android.hardware.power.stats@1.0::IPowerStats");

__attribute__((constructor)) static void static_constructor() {
    ::android::hardware::details::getBnConstructorMap().set(IPowerStats::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hardware::IBinder> {
                return new BnHwPowerStats(static_cast<IPowerStats *>(iIntf));
            });
    ::android::hardware::details::getBsConstructorMap().set(IPowerStats::descriptor,
            [](void *iIntf) -> ::android::sp<::android::hidl::base::V1_0::IBase> {
                return new BsPowerStats(static_cast<IPowerStats *>(iIntf));
            });
}

__attribute__((destructor))static void static_destructor() {
    ::android::hardware::details::getBnConstructorMap().erase(IPowerStats::descriptor);
    ::android::hardware::details::getBsConstructorMap().erase(IPowerStats::descriptor);
}

// Methods from ::android::hardware::power::stats::V1_0::IPowerStats follow.
// no default implementation for: ::android::hardware::Return<void> IPowerStats::getRailInfo(getRailInfo_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IPowerStats::getEnergyData(const ::android::hardware::hidl_vec<uint32_t>& railIndices, getEnergyData_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IPowerStats::streamEnergyData(uint32_t timeMs, uint32_t samplingRate, streamEnergyData_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IPowerStats::getPowerEntityInfo(getPowerEntityInfo_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IPowerStats::getPowerEntityStateInfo(const ::android::hardware::hidl_vec<uint32_t>& powerEntityIds, getPowerEntityStateInfo_cb _hidl_cb)
// no default implementation for: ::android::hardware::Return<void> IPowerStats::getPowerEntityStateResidencyData(const ::android::hardware::hidl_vec<uint32_t>& powerEntityIds, getPowerEntityStateResidencyData_cb _hidl_cb)

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> IPowerStats::interfaceChain(interfaceChain_cb _hidl_cb){
    _hidl_cb({
        ::android::hardware::power::stats::V1_0::IPowerStats::descriptor,
        ::android::hidl::base::V1_0::IBase::descriptor,
    });
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IPowerStats::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    (void)fd;
    (void)options;
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IPowerStats::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    _hidl_cb(::android::hardware::power::stats::V1_0::IPowerStats::descriptor);
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IPowerStats::getHashChain(getHashChain_cb _hidl_cb){
    _hidl_cb({
        (uint8_t[32]){76,178,82,220,99,114,168,116,174,246,102,185,42,110,149,41,145,90,161,135,82,26,112,15,7,137,6,92,60,112,46,173} /* 4cb252dc6372a874aef666b92a6e9529915aa187521a700f0789065c3c702ead */,
        (uint8_t[32]){236,127,215,158,208,45,250,133,188,73,148,38,173,174,62,190,35,239,5,36,243,205,105,87,19,147,36,184,59,24,202,76} /* ec7fd79ed02dfa85bc499426adae3ebe23ef0524f3cd6957139324b83b18ca4c */});
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IPowerStats::setHALInstrumentation(){
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> IPowerStats::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    (void)cookie;
    return (recipient != nullptr);
}

::android::hardware::Return<void> IPowerStats::ping(){
    return ::android::hardware::Void();
}

::android::hardware::Return<void> IPowerStats::getDebugInfo(getDebugInfo_cb _hidl_cb){
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

::android::hardware::Return<void> IPowerStats::notifySyspropsChanged(){
    ::android::report_sysprop_change();
    return ::android::hardware::Void();
}

::android::hardware::Return<bool> IPowerStats::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
    return (recipient != nullptr);
}


::android::hardware::Return<::android::sp<::android::hardware::power::stats::V1_0::IPowerStats>> IPowerStats::castFrom(const ::android::sp<::android::hardware::power::stats::V1_0::IPowerStats>& parent, bool /* emitError */) {
    return parent;
}

::android::hardware::Return<::android::sp<::android::hardware::power::stats::V1_0::IPowerStats>> IPowerStats::castFrom(const ::android::sp<::android::hidl::base::V1_0::IBase>& parent, bool emitError) {
    return ::android::hardware::details::castInterface<IPowerStats, ::android::hidl::base::V1_0::IBase, BpHwPowerStats>(
            parent, "android.hardware.power.stats@1.0::IPowerStats", emitError);
}

BpHwPowerStats::BpHwPowerStats(const ::android::sp<::android::hardware::IBinder> &_hidl_impl)
        : BpInterface<IPowerStats>(_hidl_impl),
          ::android::hardware::details::HidlInstrumentor("android.hardware.power.stats@1.0", "IPowerStats") {
}

void BpHwPowerStats::onLastStrongRef(const void* id) {
    {
        std::unique_lock<std::mutex> lock(_hidl_mMutex);
        _hidl_mDeathRecipients.clear();
    }

    BpInterface<IPowerStats>::onLastStrongRef(id);
}
// Methods from ::android::hardware::power::stats::V1_0::IPowerStats follow.
::android::hardware::Return<void> BpHwPowerStats::_hidl_getRailInfo(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, getRailInfo_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IPowerStats::getRailInfo::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.power.stats", "1.0", "IPowerStats", "getRailInfo", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwPowerStats::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(1 /* getRailInfo */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        const ::android::hardware::hidl_vec<::android::hardware::power::stats::V1_0::RailInfo>* _hidl_out_rails;
        ::android::hardware::power::stats::V1_0::Status _hidl_out_status;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        size_t _hidl__hidl_out_rails_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_rails), &_hidl__hidl_out_rails_parent,  reinterpret_cast<const void **>(&_hidl_out_rails));

        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_rails_child;

        _hidl_err = ::android::hardware::readEmbeddedFromParcel(
                const_cast<::android::hardware::hidl_vec<::android::hardware::power::stats::V1_0::RailInfo> &>(*_hidl_out_rails),
                _hidl_reply,
                _hidl__hidl_out_rails_parent,
                0 /* parentOffset */, &_hidl__hidl_out_rails_child);

        if (_hidl_err != ::android::OK) { return; }

        for (size_t _hidl_index_0 = 0; _hidl_index_0 < _hidl_out_rails->size(); ++_hidl_index_0) {
            _hidl_err = readEmbeddedFromParcel(
                    const_cast<::android::hardware::power::stats::V1_0::RailInfo &>((*_hidl_out_rails)[_hidl_index_0]),
                    _hidl_reply,
                    _hidl__hidl_out_rails_child,
                    _hidl_index_0 * sizeof(::android::hardware::power::stats::V1_0::RailInfo));

            if (_hidl_err != ::android::OK) { return; }

        }

        _hidl_err = _hidl_reply.readUint32((uint32_t *)&_hidl_out_status);
        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(*_hidl_out_rails, _hidl_out_status);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)_hidl_out_rails);
            _hidl_args.push_back((void *)&_hidl_out_status);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.power.stats", "1.0", "IPowerStats", "getRailInfo", &_hidl_args);
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

::android::hardware::Return<void> BpHwPowerStats::_hidl_getEnergyData(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::hidl_vec<uint32_t>& railIndices, getEnergyData_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IPowerStats::getEnergyData::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&railIndices);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.power.stats", "1.0", "IPowerStats", "getEnergyData", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwPowerStats::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_railIndices_parent;

    _hidl_err = _hidl_data.writeBuffer(&railIndices, sizeof(railIndices), &_hidl_railIndices_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_railIndices_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            railIndices,
            &_hidl_data,
            _hidl_railIndices_parent,
            0 /* parentOffset */, &_hidl_railIndices_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(2 /* getEnergyData */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        const ::android::hardware::hidl_vec<::android::hardware::power::stats::V1_0::EnergyData>* _hidl_out_data;
        ::android::hardware::power::stats::V1_0::Status _hidl_out_status;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        size_t _hidl__hidl_out_data_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_data), &_hidl__hidl_out_data_parent,  reinterpret_cast<const void **>(&_hidl_out_data));

        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_data_child;

        _hidl_err = ::android::hardware::readEmbeddedFromParcel(
                const_cast<::android::hardware::hidl_vec<::android::hardware::power::stats::V1_0::EnergyData> &>(*_hidl_out_data),
                _hidl_reply,
                _hidl__hidl_out_data_parent,
                0 /* parentOffset */, &_hidl__hidl_out_data_child);

        if (_hidl_err != ::android::OK) { return; }

        _hidl_err = _hidl_reply.readUint32((uint32_t *)&_hidl_out_status);
        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(*_hidl_out_data, _hidl_out_status);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)_hidl_out_data);
            _hidl_args.push_back((void *)&_hidl_out_status);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.power.stats", "1.0", "IPowerStats", "getEnergyData", &_hidl_args);
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

::android::hardware::Return<void> BpHwPowerStats::_hidl_streamEnergyData(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, uint32_t timeMs, uint32_t samplingRate, streamEnergyData_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IPowerStats::streamEnergyData::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&timeMs);
        _hidl_args.push_back((void *)&samplingRate);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.power.stats", "1.0", "IPowerStats", "streamEnergyData", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwPowerStats::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(timeMs);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_err = _hidl_data.writeUint32(samplingRate);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(3 /* streamEnergyData */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        const ::android::hardware::MQDescriptorSync<::android::hardware::power::stats::V1_0::EnergyData>* _hidl_out_mqDesc;
        uint32_t _hidl_out_numSamples;
        uint32_t _hidl_out_railsPerSample;
        ::android::hardware::power::stats::V1_0::Status _hidl_out_status;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        size_t _hidl__hidl_out_mqDesc_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_mqDesc), &_hidl__hidl_out_mqDesc_parent,  reinterpret_cast<const void **>(&_hidl_out_mqDesc));

        if (_hidl_err != ::android::OK) { return; }

        _hidl_err = ::android::hardware::readEmbeddedFromParcel(
                const_cast<::android::hardware::MQDescriptorSync<::android::hardware::power::stats::V1_0::EnergyData> &>(*_hidl_out_mqDesc),
                _hidl_reply,
                _hidl__hidl_out_mqDesc_parent,
                0 /* parentOffset */);

        if (_hidl_err != ::android::OK) { return; }

        _hidl_err = _hidl_reply.readUint32(&_hidl_out_numSamples);
        if (_hidl_err != ::android::OK) { return; }

        _hidl_err = _hidl_reply.readUint32(&_hidl_out_railsPerSample);
        if (_hidl_err != ::android::OK) { return; }

        _hidl_err = _hidl_reply.readUint32((uint32_t *)&_hidl_out_status);
        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(*_hidl_out_mqDesc, _hidl_out_numSamples, _hidl_out_railsPerSample, _hidl_out_status);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)_hidl_out_mqDesc);
            _hidl_args.push_back((void *)&_hidl_out_numSamples);
            _hidl_args.push_back((void *)&_hidl_out_railsPerSample);
            _hidl_args.push_back((void *)&_hidl_out_status);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.power.stats", "1.0", "IPowerStats", "streamEnergyData", &_hidl_args);
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

::android::hardware::Return<void> BpHwPowerStats::_hidl_getPowerEntityInfo(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, getPowerEntityInfo_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IPowerStats::getPowerEntityInfo::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.power.stats", "1.0", "IPowerStats", "getPowerEntityInfo", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwPowerStats::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(4 /* getPowerEntityInfo */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        const ::android::hardware::hidl_vec<::android::hardware::power::stats::V1_0::PowerEntityInfo>* _hidl_out_powerEntityInfos;
        ::android::hardware::power::stats::V1_0::Status _hidl_out_status;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        size_t _hidl__hidl_out_powerEntityInfos_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_powerEntityInfos), &_hidl__hidl_out_powerEntityInfos_parent,  reinterpret_cast<const void **>(&_hidl_out_powerEntityInfos));

        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_powerEntityInfos_child;

        _hidl_err = ::android::hardware::readEmbeddedFromParcel(
                const_cast<::android::hardware::hidl_vec<::android::hardware::power::stats::V1_0::PowerEntityInfo> &>(*_hidl_out_powerEntityInfos),
                _hidl_reply,
                _hidl__hidl_out_powerEntityInfos_parent,
                0 /* parentOffset */, &_hidl__hidl_out_powerEntityInfos_child);

        if (_hidl_err != ::android::OK) { return; }

        for (size_t _hidl_index_0 = 0; _hidl_index_0 < _hidl_out_powerEntityInfos->size(); ++_hidl_index_0) {
            _hidl_err = readEmbeddedFromParcel(
                    const_cast<::android::hardware::power::stats::V1_0::PowerEntityInfo &>((*_hidl_out_powerEntityInfos)[_hidl_index_0]),
                    _hidl_reply,
                    _hidl__hidl_out_powerEntityInfos_child,
                    _hidl_index_0 * sizeof(::android::hardware::power::stats::V1_0::PowerEntityInfo));

            if (_hidl_err != ::android::OK) { return; }

        }

        _hidl_err = _hidl_reply.readUint32((uint32_t *)&_hidl_out_status);
        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(*_hidl_out_powerEntityInfos, _hidl_out_status);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)_hidl_out_powerEntityInfos);
            _hidl_args.push_back((void *)&_hidl_out_status);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.power.stats", "1.0", "IPowerStats", "getPowerEntityInfo", &_hidl_args);
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

::android::hardware::Return<void> BpHwPowerStats::_hidl_getPowerEntityStateInfo(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::hidl_vec<uint32_t>& powerEntityIds, getPowerEntityStateInfo_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IPowerStats::getPowerEntityStateInfo::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&powerEntityIds);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.power.stats", "1.0", "IPowerStats", "getPowerEntityStateInfo", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwPowerStats::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_powerEntityIds_parent;

    _hidl_err = _hidl_data.writeBuffer(&powerEntityIds, sizeof(powerEntityIds), &_hidl_powerEntityIds_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_powerEntityIds_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            powerEntityIds,
            &_hidl_data,
            _hidl_powerEntityIds_parent,
            0 /* parentOffset */, &_hidl_powerEntityIds_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(5 /* getPowerEntityStateInfo */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        const ::android::hardware::hidl_vec<::android::hardware::power::stats::V1_0::PowerEntityStateSpace>* _hidl_out_powerEntityStateSpaces;
        ::android::hardware::power::stats::V1_0::Status _hidl_out_status;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        size_t _hidl__hidl_out_powerEntityStateSpaces_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_powerEntityStateSpaces), &_hidl__hidl_out_powerEntityStateSpaces_parent,  reinterpret_cast<const void **>(&_hidl_out_powerEntityStateSpaces));

        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_powerEntityStateSpaces_child;

        _hidl_err = ::android::hardware::readEmbeddedFromParcel(
                const_cast<::android::hardware::hidl_vec<::android::hardware::power::stats::V1_0::PowerEntityStateSpace> &>(*_hidl_out_powerEntityStateSpaces),
                _hidl_reply,
                _hidl__hidl_out_powerEntityStateSpaces_parent,
                0 /* parentOffset */, &_hidl__hidl_out_powerEntityStateSpaces_child);

        if (_hidl_err != ::android::OK) { return; }

        for (size_t _hidl_index_0 = 0; _hidl_index_0 < _hidl_out_powerEntityStateSpaces->size(); ++_hidl_index_0) {
            _hidl_err = readEmbeddedFromParcel(
                    const_cast<::android::hardware::power::stats::V1_0::PowerEntityStateSpace &>((*_hidl_out_powerEntityStateSpaces)[_hidl_index_0]),
                    _hidl_reply,
                    _hidl__hidl_out_powerEntityStateSpaces_child,
                    _hidl_index_0 * sizeof(::android::hardware::power::stats::V1_0::PowerEntityStateSpace));

            if (_hidl_err != ::android::OK) { return; }

        }

        _hidl_err = _hidl_reply.readUint32((uint32_t *)&_hidl_out_status);
        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(*_hidl_out_powerEntityStateSpaces, _hidl_out_status);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)_hidl_out_powerEntityStateSpaces);
            _hidl_args.push_back((void *)&_hidl_out_status);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.power.stats", "1.0", "IPowerStats", "getPowerEntityStateInfo", &_hidl_args);
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

::android::hardware::Return<void> BpHwPowerStats::_hidl_getPowerEntityStateResidencyData(::android::hardware::IInterface *_hidl_this, ::android::hardware::details::HidlInstrumentor *_hidl_this_instrumentor, const ::android::hardware::hidl_vec<uint32_t>& powerEntityIds, getPowerEntityStateResidencyData_cb _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this_instrumentor->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this_instrumentor->getInstrumentationCallbacks();
    #else
    (void) _hidl_this_instrumentor;
    #endif // __ANDROID_DEBUGGABLE__
    ::android::ScopedTrace PASTE(___tracer, __LINE__) (ATRACE_TAG_HAL, "HIDL::IPowerStats::getPowerEntityStateResidencyData::client");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&powerEntityIds);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::CLIENT_API_ENTRY, "android.hardware.power.stats", "1.0", "IPowerStats", "getPowerEntityStateResidencyData", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    ::android::hardware::Parcel _hidl_data;
    ::android::hardware::Parcel _hidl_reply;
    ::android::status_t _hidl_err;
    ::android::status_t _hidl_transact_err;
    ::android::hardware::Status _hidl_status;

    _hidl_err = _hidl_data.writeInterfaceToken(BpHwPowerStats::descriptor);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_powerEntityIds_parent;

    _hidl_err = _hidl_data.writeBuffer(&powerEntityIds, sizeof(powerEntityIds), &_hidl_powerEntityIds_parent);
    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    size_t _hidl_powerEntityIds_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            powerEntityIds,
            &_hidl_data,
            _hidl_powerEntityIds_parent,
            0 /* parentOffset */, &_hidl_powerEntityIds_child);

    if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_transact_err = ::android::hardware::IInterface::asBinder(_hidl_this)->transact(6 /* getPowerEntityStateResidencyData */, _hidl_data, &_hidl_reply, 0 /* flags */, [&] (::android::hardware::Parcel& _hidl_reply) {
        const ::android::hardware::hidl_vec<::android::hardware::power::stats::V1_0::PowerEntityStateResidencyResult>* _hidl_out_stateResidencyResults;
        ::android::hardware::power::stats::V1_0::Status _hidl_out_status;


        _hidl_err = ::android::hardware::readFromParcel(&_hidl_status, _hidl_reply);
        if (_hidl_err != ::android::OK) { return; }

        if (!_hidl_status.isOk()) { return; }

        size_t _hidl__hidl_out_stateResidencyResults_parent;

        _hidl_err = _hidl_reply.readBuffer(sizeof(*_hidl_out_stateResidencyResults), &_hidl__hidl_out_stateResidencyResults_parent,  reinterpret_cast<const void **>(&_hidl_out_stateResidencyResults));

        if (_hidl_err != ::android::OK) { return; }

        size_t _hidl__hidl_out_stateResidencyResults_child;

        _hidl_err = ::android::hardware::readEmbeddedFromParcel(
                const_cast<::android::hardware::hidl_vec<::android::hardware::power::stats::V1_0::PowerEntityStateResidencyResult> &>(*_hidl_out_stateResidencyResults),
                _hidl_reply,
                _hidl__hidl_out_stateResidencyResults_parent,
                0 /* parentOffset */, &_hidl__hidl_out_stateResidencyResults_child);

        if (_hidl_err != ::android::OK) { return; }

        for (size_t _hidl_index_0 = 0; _hidl_index_0 < _hidl_out_stateResidencyResults->size(); ++_hidl_index_0) {
            _hidl_err = readEmbeddedFromParcel(
                    const_cast<::android::hardware::power::stats::V1_0::PowerEntityStateResidencyResult &>((*_hidl_out_stateResidencyResults)[_hidl_index_0]),
                    _hidl_reply,
                    _hidl__hidl_out_stateResidencyResults_child,
                    _hidl_index_0 * sizeof(::android::hardware::power::stats::V1_0::PowerEntityStateResidencyResult));

            if (_hidl_err != ::android::OK) { return; }

        }

        _hidl_err = _hidl_reply.readUint32((uint32_t *)&_hidl_out_status);
        if (_hidl_err != ::android::OK) { return; }

        _hidl_cb(*_hidl_out_stateResidencyResults, _hidl_out_status);

        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)_hidl_out_stateResidencyResults);
            _hidl_args.push_back((void *)&_hidl_out_status);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::CLIENT_API_EXIT, "android.hardware.power.stats", "1.0", "IPowerStats", "getPowerEntityStateResidencyData", &_hidl_args);
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


// Methods from ::android::hardware::power::stats::V1_0::IPowerStats follow.
::android::hardware::Return<void> BpHwPowerStats::getRailInfo(getRailInfo_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::power::stats::V1_0::BpHwPowerStats::_hidl_getRailInfo(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwPowerStats::getEnergyData(const ::android::hardware::hidl_vec<uint32_t>& railIndices, getEnergyData_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::power::stats::V1_0::BpHwPowerStats::_hidl_getEnergyData(this, this, railIndices, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwPowerStats::streamEnergyData(uint32_t timeMs, uint32_t samplingRate, streamEnergyData_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::power::stats::V1_0::BpHwPowerStats::_hidl_streamEnergyData(this, this, timeMs, samplingRate, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwPowerStats::getPowerEntityInfo(getPowerEntityInfo_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::power::stats::V1_0::BpHwPowerStats::_hidl_getPowerEntityInfo(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwPowerStats::getPowerEntityStateInfo(const ::android::hardware::hidl_vec<uint32_t>& powerEntityIds, getPowerEntityStateInfo_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::power::stats::V1_0::BpHwPowerStats::_hidl_getPowerEntityStateInfo(this, this, powerEntityIds, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwPowerStats::getPowerEntityStateResidencyData(const ::android::hardware::hidl_vec<uint32_t>& powerEntityIds, getPowerEntityStateResidencyData_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hardware::power::stats::V1_0::BpHwPowerStats::_hidl_getPowerEntityStateResidencyData(this, this, powerEntityIds, _hidl_cb);

    return _hidl_out;
}


// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BpHwPowerStats::interfaceChain(interfaceChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwPowerStats::debug(const ::android::hardware::hidl_handle& fd, const ::android::hardware::hidl_vec<::android::hardware::hidl_string>& options){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_debug(this, this, fd, options);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwPowerStats::interfaceDescriptor(interfaceDescriptor_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_interfaceDescriptor(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwPowerStats::getHashChain(getHashChain_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getHashChain(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwPowerStats::setHALInstrumentation(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_setHALInstrumentation(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwPowerStats::linkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient, uint64_t cookie){
    ::android::hardware::ProcessState::self()->startThreadPool();
    ::android::hardware::hidl_binder_death_recipient *binder_recipient = new ::android::hardware::hidl_binder_death_recipient(recipient, cookie, this);
    std::unique_lock<std::mutex> lock(_hidl_mMutex);
    _hidl_mDeathRecipients.push_back(binder_recipient);
    return (remote()->linkToDeath(binder_recipient) == ::android::OK);
}

::android::hardware::Return<void> BpHwPowerStats::ping(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_ping(this, this);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwPowerStats::getDebugInfo(getDebugInfo_cb _hidl_cb){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_getDebugInfo(this, this, _hidl_cb);

    return _hidl_out;
}

::android::hardware::Return<void> BpHwPowerStats::notifySyspropsChanged(){
    ::android::hardware::Return<void>  _hidl_out = ::android::hidl::base::V1_0::BpHwBase::_hidl_notifySyspropsChanged(this, this);

    return _hidl_out;
}

::android::hardware::Return<bool> BpHwPowerStats::unlinkToDeath(const ::android::sp<::android::hardware::hidl_death_recipient>& recipient){
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


BnHwPowerStats::BnHwPowerStats(const ::android::sp<IPowerStats> &_hidl_impl)
        : ::android::hidl::base::V1_0::BnHwBase(_hidl_impl, "android.hardware.power.stats@1.0", "IPowerStats") { 
            _hidl_mImpl = _hidl_impl;
            auto prio = ::android::hardware::getMinSchedulerPolicy(_hidl_impl);
            mSchedPolicy = prio.sched_policy;
            mSchedPriority = prio.prio;
            setRequestingSid(::android::hardware::getRequestingSid(_hidl_impl));
}

BnHwPowerStats::~BnHwPowerStats() {
    ::android::hardware::details::gBnMap->eraseIfEqual(_hidl_mImpl.get(), this);
}

// Methods from ::android::hardware::power::stats::V1_0::IPowerStats follow.
::android::status_t BnHwPowerStats::_hidl_getRailInfo(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwPowerStats::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IPowerStats::getRailInfo::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.power.stats", "1.0", "IPowerStats", "getRailInfo", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IPowerStats*>(_hidl_this->getImpl().get())->getRailInfo([&](const auto &_hidl_out_rails, const auto &_hidl_out_status) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("getRailInfo: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        size_t _hidl__hidl_out_rails_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_rails, sizeof(_hidl_out_rails), &_hidl__hidl_out_rails_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_rails_child;

        _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                _hidl_out_rails,
                _hidl_reply,
                _hidl__hidl_out_rails_parent,
                0 /* parentOffset */, &_hidl__hidl_out_rails_child);

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        for (size_t _hidl_index_0 = 0; _hidl_index_0 < _hidl_out_rails.size(); ++_hidl_index_0) {
            _hidl_err = writeEmbeddedToParcel(
                    _hidl_out_rails[_hidl_index_0],
                    _hidl_reply,
                    _hidl__hidl_out_rails_child,
                    _hidl_index_0 * sizeof(::android::hardware::power::stats::V1_0::RailInfo));

            if (_hidl_err != ::android::OK) { goto _hidl_error; }

        }

        _hidl_err = _hidl_reply->writeUint32((uint32_t)_hidl_out_status);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_rails);
            _hidl_args.push_back((void *)&_hidl_out_status);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.power.stats", "1.0", "IPowerStats", "getRailInfo", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("getRailInfo: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwPowerStats::_hidl_getEnergyData(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwPowerStats::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    const ::android::hardware::hidl_vec<uint32_t>* railIndices;

    size_t _hidl_railIndices_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*railIndices), &_hidl_railIndices_parent,  reinterpret_cast<const void **>(&railIndices));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_railIndices_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint32_t> &>(*railIndices),
            _hidl_data,
            _hidl_railIndices_parent,
            0 /* parentOffset */, &_hidl_railIndices_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IPowerStats::getEnergyData::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)railIndices);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.power.stats", "1.0", "IPowerStats", "getEnergyData", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IPowerStats*>(_hidl_this->getImpl().get())->getEnergyData(*railIndices, [&](const auto &_hidl_out_data, const auto &_hidl_out_status) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("getEnergyData: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        size_t _hidl__hidl_out_data_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_data, sizeof(_hidl_out_data), &_hidl__hidl_out_data_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_data_child;

        _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                _hidl_out_data,
                _hidl_reply,
                _hidl__hidl_out_data_parent,
                0 /* parentOffset */, &_hidl__hidl_out_data_child);

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_err = _hidl_reply->writeUint32((uint32_t)_hidl_out_status);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_data);
            _hidl_args.push_back((void *)&_hidl_out_status);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.power.stats", "1.0", "IPowerStats", "getEnergyData", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("getEnergyData: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwPowerStats::_hidl_streamEnergyData(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwPowerStats::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    uint32_t timeMs;
    uint32_t samplingRate;

    _hidl_err = _hidl_data.readUint32(&timeMs);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = _hidl_data.readUint32(&samplingRate);
    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IPowerStats::streamEnergyData::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)&timeMs);
        _hidl_args.push_back((void *)&samplingRate);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.power.stats", "1.0", "IPowerStats", "streamEnergyData", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IPowerStats*>(_hidl_this->getImpl().get())->streamEnergyData(timeMs, samplingRate, [&](const auto &_hidl_out_mqDesc, const auto &_hidl_out_numSamples, const auto &_hidl_out_railsPerSample, const auto &_hidl_out_status) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("streamEnergyData: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        size_t _hidl__hidl_out_mqDesc_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_mqDesc, sizeof(_hidl_out_mqDesc), &_hidl__hidl_out_mqDesc_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                _hidl_out_mqDesc,
                _hidl_reply,
                _hidl__hidl_out_mqDesc_parent,
                0 /* parentOffset */);

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_err = _hidl_reply->writeUint32(_hidl_out_numSamples);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_err = _hidl_reply->writeUint32(_hidl_out_railsPerSample);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        _hidl_err = _hidl_reply->writeUint32((uint32_t)_hidl_out_status);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_mqDesc);
            _hidl_args.push_back((void *)&_hidl_out_numSamples);
            _hidl_args.push_back((void *)&_hidl_out_railsPerSample);
            _hidl_args.push_back((void *)&_hidl_out_status);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.power.stats", "1.0", "IPowerStats", "streamEnergyData", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("streamEnergyData: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwPowerStats::_hidl_getPowerEntityInfo(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwPowerStats::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IPowerStats::getPowerEntityInfo::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.power.stats", "1.0", "IPowerStats", "getPowerEntityInfo", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IPowerStats*>(_hidl_this->getImpl().get())->getPowerEntityInfo([&](const auto &_hidl_out_powerEntityInfos, const auto &_hidl_out_status) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("getPowerEntityInfo: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        size_t _hidl__hidl_out_powerEntityInfos_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_powerEntityInfos, sizeof(_hidl_out_powerEntityInfos), &_hidl__hidl_out_powerEntityInfos_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_powerEntityInfos_child;

        _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                _hidl_out_powerEntityInfos,
                _hidl_reply,
                _hidl__hidl_out_powerEntityInfos_parent,
                0 /* parentOffset */, &_hidl__hidl_out_powerEntityInfos_child);

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        for (size_t _hidl_index_0 = 0; _hidl_index_0 < _hidl_out_powerEntityInfos.size(); ++_hidl_index_0) {
            _hidl_err = writeEmbeddedToParcel(
                    _hidl_out_powerEntityInfos[_hidl_index_0],
                    _hidl_reply,
                    _hidl__hidl_out_powerEntityInfos_child,
                    _hidl_index_0 * sizeof(::android::hardware::power::stats::V1_0::PowerEntityInfo));

            if (_hidl_err != ::android::OK) { goto _hidl_error; }

        }

        _hidl_err = _hidl_reply->writeUint32((uint32_t)_hidl_out_status);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_powerEntityInfos);
            _hidl_args.push_back((void *)&_hidl_out_status);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.power.stats", "1.0", "IPowerStats", "getPowerEntityInfo", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("getPowerEntityInfo: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwPowerStats::_hidl_getPowerEntityStateInfo(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwPowerStats::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    const ::android::hardware::hidl_vec<uint32_t>* powerEntityIds;

    size_t _hidl_powerEntityIds_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*powerEntityIds), &_hidl_powerEntityIds_parent,  reinterpret_cast<const void **>(&powerEntityIds));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_powerEntityIds_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint32_t> &>(*powerEntityIds),
            _hidl_data,
            _hidl_powerEntityIds_parent,
            0 /* parentOffset */, &_hidl_powerEntityIds_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IPowerStats::getPowerEntityStateInfo::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)powerEntityIds);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.power.stats", "1.0", "IPowerStats", "getPowerEntityStateInfo", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IPowerStats*>(_hidl_this->getImpl().get())->getPowerEntityStateInfo(*powerEntityIds, [&](const auto &_hidl_out_powerEntityStateSpaces, const auto &_hidl_out_status) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("getPowerEntityStateInfo: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        size_t _hidl__hidl_out_powerEntityStateSpaces_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_powerEntityStateSpaces, sizeof(_hidl_out_powerEntityStateSpaces), &_hidl__hidl_out_powerEntityStateSpaces_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_powerEntityStateSpaces_child;

        _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                _hidl_out_powerEntityStateSpaces,
                _hidl_reply,
                _hidl__hidl_out_powerEntityStateSpaces_parent,
                0 /* parentOffset */, &_hidl__hidl_out_powerEntityStateSpaces_child);

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        for (size_t _hidl_index_0 = 0; _hidl_index_0 < _hidl_out_powerEntityStateSpaces.size(); ++_hidl_index_0) {
            _hidl_err = writeEmbeddedToParcel(
                    _hidl_out_powerEntityStateSpaces[_hidl_index_0],
                    _hidl_reply,
                    _hidl__hidl_out_powerEntityStateSpaces_child,
                    _hidl_index_0 * sizeof(::android::hardware::power::stats::V1_0::PowerEntityStateSpace));

            if (_hidl_err != ::android::OK) { goto _hidl_error; }

        }

        _hidl_err = _hidl_reply->writeUint32((uint32_t)_hidl_out_status);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_powerEntityStateSpaces);
            _hidl_args.push_back((void *)&_hidl_out_status);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.power.stats", "1.0", "IPowerStats", "getPowerEntityStateInfo", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("getPowerEntityStateInfo: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}

::android::status_t BnHwPowerStats::_hidl_getPowerEntityStateResidencyData(
        ::android::hidl::base::V1_0::BnHwBase* _hidl_this,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        TransactCallback _hidl_cb) {
    #ifdef __ANDROID_DEBUGGABLE__
    bool mEnableInstrumentation = _hidl_this->isInstrumentationEnabled();
    const auto &mInstrumentationCallbacks = _hidl_this->getInstrumentationCallbacks();
    #endif // __ANDROID_DEBUGGABLE__

    ::android::status_t _hidl_err = ::android::OK;
    if (!_hidl_data.enforceInterface(BnHwPowerStats::Pure::descriptor)) {
        _hidl_err = ::android::BAD_TYPE;
        return _hidl_err;
    }

    const ::android::hardware::hidl_vec<uint32_t>* powerEntityIds;

    size_t _hidl_powerEntityIds_parent;

    _hidl_err = _hidl_data.readBuffer(sizeof(*powerEntityIds), &_hidl_powerEntityIds_parent,  reinterpret_cast<const void **>(&powerEntityIds));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_powerEntityIds_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint32_t> &>(*powerEntityIds),
            _hidl_data,
            _hidl_powerEntityIds_parent,
            0 /* parentOffset */, &_hidl_powerEntityIds_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    atrace_begin(ATRACE_TAG_HAL, "HIDL::IPowerStats::getPowerEntityStateResidencyData::server");
    #ifdef __ANDROID_DEBUGGABLE__
    if (UNLIKELY(mEnableInstrumentation)) {
        std::vector<void *> _hidl_args;
        _hidl_args.push_back((void *)powerEntityIds);
        for (const auto &callback: mInstrumentationCallbacks) {
            callback(InstrumentationEvent::SERVER_API_ENTRY, "android.hardware.power.stats", "1.0", "IPowerStats", "getPowerEntityStateResidencyData", &_hidl_args);
        }
    }
    #endif // __ANDROID_DEBUGGABLE__

    bool _hidl_callbackCalled = false;

    ::android::hardware::Return<void> _hidl_ret = static_cast<IPowerStats*>(_hidl_this->getImpl().get())->getPowerEntityStateResidencyData(*powerEntityIds, [&](const auto &_hidl_out_stateResidencyResults, const auto &_hidl_out_status) {
        if (_hidl_callbackCalled) {
            LOG_ALWAYS_FATAL("getPowerEntityStateResidencyData: _hidl_cb called a second time, but must be called once.");
        }
        _hidl_callbackCalled = true;

        ::android::hardware::writeToParcel(::android::hardware::Status::ok(), _hidl_reply);

        size_t _hidl__hidl_out_stateResidencyResults_parent;

        _hidl_err = _hidl_reply->writeBuffer(&_hidl_out_stateResidencyResults, sizeof(_hidl_out_stateResidencyResults), &_hidl__hidl_out_stateResidencyResults_parent);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        size_t _hidl__hidl_out_stateResidencyResults_child;

        _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                _hidl_out_stateResidencyResults,
                _hidl_reply,
                _hidl__hidl_out_stateResidencyResults_parent,
                0 /* parentOffset */, &_hidl__hidl_out_stateResidencyResults_child);

        if (_hidl_err != ::android::OK) { goto _hidl_error; }

        for (size_t _hidl_index_0 = 0; _hidl_index_0 < _hidl_out_stateResidencyResults.size(); ++_hidl_index_0) {
            _hidl_err = writeEmbeddedToParcel(
                    _hidl_out_stateResidencyResults[_hidl_index_0],
                    _hidl_reply,
                    _hidl__hidl_out_stateResidencyResults_child,
                    _hidl_index_0 * sizeof(::android::hardware::power::stats::V1_0::PowerEntityStateResidencyResult));

            if (_hidl_err != ::android::OK) { goto _hidl_error; }

        }

        _hidl_err = _hidl_reply->writeUint32((uint32_t)_hidl_out_status);
        if (_hidl_err != ::android::OK) { goto _hidl_error; }

    _hidl_error:
        atrace_end(ATRACE_TAG_HAL);
        #ifdef __ANDROID_DEBUGGABLE__
        if (UNLIKELY(mEnableInstrumentation)) {
            std::vector<void *> _hidl_args;
            _hidl_args.push_back((void *)&_hidl_out_stateResidencyResults);
            _hidl_args.push_back((void *)&_hidl_out_status);
            for (const auto &callback: mInstrumentationCallbacks) {
                callback(InstrumentationEvent::SERVER_API_EXIT, "android.hardware.power.stats", "1.0", "IPowerStats", "getPowerEntityStateResidencyData", &_hidl_args);
            }
        }
        #endif // __ANDROID_DEBUGGABLE__

        if (_hidl_err != ::android::OK) { return; }
        _hidl_cb(*_hidl_reply);
    });

    _hidl_ret.assertOk();
    if (!_hidl_callbackCalled) {
        LOG_ALWAYS_FATAL("getPowerEntityStateResidencyData: _hidl_cb not called, but must be called once.");
    }

    return _hidl_err;
}


// Methods from ::android::hardware::power::stats::V1_0::IPowerStats follow.

// Methods from ::android::hidl::base::V1_0::IBase follow.
::android::hardware::Return<void> BnHwPowerStats::ping() {
    return ::android::hardware::Void();
}
::android::hardware::Return<void> BnHwPowerStats::getDebugInfo(getDebugInfo_cb _hidl_cb) {
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

::android::status_t BnHwPowerStats::onTransact(
        uint32_t _hidl_code,
        const ::android::hardware::Parcel &_hidl_data,
        ::android::hardware::Parcel *_hidl_reply,
        uint32_t _hidl_flags,
        TransactCallback _hidl_cb) {
    ::android::status_t _hidl_err = ::android::OK;

    switch (_hidl_code) {
        case 1 /* getRailInfo */:
        {
            _hidl_err = ::android::hardware::power::stats::V1_0::BnHwPowerStats::_hidl_getRailInfo(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 2 /* getEnergyData */:
        {
            _hidl_err = ::android::hardware::power::stats::V1_0::BnHwPowerStats::_hidl_getEnergyData(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 3 /* streamEnergyData */:
        {
            _hidl_err = ::android::hardware::power::stats::V1_0::BnHwPowerStats::_hidl_streamEnergyData(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 4 /* getPowerEntityInfo */:
        {
            _hidl_err = ::android::hardware::power::stats::V1_0::BnHwPowerStats::_hidl_getPowerEntityInfo(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 5 /* getPowerEntityStateInfo */:
        {
            _hidl_err = ::android::hardware::power::stats::V1_0::BnHwPowerStats::_hidl_getPowerEntityStateInfo(this, _hidl_data, _hidl_reply, _hidl_cb);
            break;
        }

        case 6 /* getPowerEntityStateResidencyData */:
        {
            _hidl_err = ::android::hardware::power::stats::V1_0::BnHwPowerStats::_hidl_getPowerEntityStateResidencyData(this, _hidl_data, _hidl_reply, _hidl_cb);
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

BsPowerStats::BsPowerStats(const ::android::sp<::android::hardware::power::stats::V1_0::IPowerStats> impl) : ::android::hardware::details::HidlInstrumentor("android.hardware.power.stats@1.0", "IPowerStats"), mImpl(impl) {
    mOnewayQueue.start(3000 /* similar limit to binderized */);
}

::android::hardware::Return<void> BsPowerStats::addOnewayTask(std::function<void(void)> fun) {
    if (!mOnewayQueue.push(fun)) {
        return ::android::hardware::Status::fromExceptionCode(
                ::android::hardware::Status::EX_TRANSACTION_FAILED,
                "Passthrough oneway function queue exceeds maximum size.");
    }
    return ::android::hardware::Status();
}

::android::sp<IPowerStats> IPowerStats::tryGetService(const std::string &serviceName, const bool getStub) {
    return ::android::hardware::details::getServiceInternal<BpHwPowerStats>(serviceName, false, getStub);
}

::android::sp<IPowerStats> IPowerStats::getService(const std::string &serviceName, const bool getStub) {
    return ::android::hardware::details::getServiceInternal<BpHwPowerStats>(serviceName, true, getStub);
}

::android::status_t IPowerStats::registerAsService(const std::string &serviceName) {
    return ::android::hardware::details::registerAsServiceInternal(this, serviceName);
}

bool IPowerStats::registerForNotifications(
        const std::string &serviceName,
        const ::android::sp<::android::hidl::manager::V1_0::IServiceNotification> &notification) {
    const ::android::sp<::android::hidl::manager::V1_0::IServiceManager> sm
            = ::android::hardware::defaultServiceManager();
    if (sm == nullptr) {
        return false;
    }
    ::android::hardware::Return<bool> success =
            sm->registerForNotifications("android.hardware.power.stats@1.0::IPowerStats",
                    serviceName, notification);
    return success.isOk() && success;
}

static_assert(sizeof(::android::hardware::MQDescriptor<char, ::android::hardware::kSynchronizedReadWrite>) == 32, "wrong size");
static_assert(sizeof(::android::hardware::hidl_handle) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_memory) == 40, "wrong size");
static_assert(sizeof(::android::hardware::hidl_string) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_vec<char>) == 16, "wrong size");

}  // namespace V1_0
}  // namespace stats
}  // namespace power
}  // namespace hardware
}  // namespace android
