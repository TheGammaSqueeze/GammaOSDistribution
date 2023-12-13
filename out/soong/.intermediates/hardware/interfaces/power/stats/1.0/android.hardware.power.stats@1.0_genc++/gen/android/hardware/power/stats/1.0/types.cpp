#define LOG_TAG "android.hardware.power.stats@1.0::types"

#include <log/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <hidl/Static.h>
#include <hwbinder/ProcessState.h>
#include <utils/Trace.h>
#include <android/hardware/power/stats/1.0/types.h>
#include <android/hardware/power/stats/1.0/hwtypes.h>

namespace android {
namespace hardware {
namespace power {
namespace stats {
namespace V1_0 {

::android::status_t readEmbeddedFromParcel(
        const RailInfo &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.railName),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::power::stats::V1_0::RailInfo, railName));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.subsysName),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::power::stats::V1_0::RailInfo, subsysName));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const RailInfo &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.railName,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::power::stats::V1_0::RailInfo, railName));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.subsysName,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::power::stats::V1_0::RailInfo, subsysName));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const PowerEntityInfo &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.powerEntityName),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::power::stats::V1_0::PowerEntityInfo, powerEntityName));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const PowerEntityInfo &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.powerEntityName,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::power::stats::V1_0::PowerEntityInfo, powerEntityName));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const PowerEntityStateInfo &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.powerEntityStateName),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::power::stats::V1_0::PowerEntityStateInfo, powerEntityStateName));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const PowerEntityStateInfo &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.powerEntityStateName,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::power::stats::V1_0::PowerEntityStateInfo, powerEntityStateName));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const PowerEntityStateSpace &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_states_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::power::stats::V1_0::PowerEntityStateInfo> &>(obj.states),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::power::stats::V1_0::PowerEntityStateSpace, states), &_hidl_states_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.states.size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::power::stats::V1_0::PowerEntityStateInfo &>(obj.states[_hidl_index_0]),
                parcel,
                _hidl_states_child,
                _hidl_index_0 * sizeof(::android::hardware::power::stats::V1_0::PowerEntityStateInfo));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const PowerEntityStateSpace &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_states_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.states,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::power::stats::V1_0::PowerEntityStateSpace, states), &_hidl_states_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.states.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                obj.states[_hidl_index_0],
                parcel,
                _hidl_states_child,
                _hidl_index_0 * sizeof(::android::hardware::power::stats::V1_0::PowerEntityStateInfo));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const PowerEntityStateResidencyResult &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_stateResidencyData_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::power::stats::V1_0::PowerEntityStateResidencyData> &>(obj.stateResidencyData),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::power::stats::V1_0::PowerEntityStateResidencyResult, stateResidencyData), &_hidl_stateResidencyData_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const PowerEntityStateResidencyResult &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_stateResidencyData_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.stateResidencyData,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::power::stats::V1_0::PowerEntityStateResidencyResult, stateResidencyData), &_hidl_stateResidencyData_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
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
