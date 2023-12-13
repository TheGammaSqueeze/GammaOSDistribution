#define LOG_TAG "android.hardware.power@1.1::types"

#include <log/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <hidl/Static.h>
#include <hwbinder/ProcessState.h>
#include <utils/Trace.h>
#include <android/hardware/power/1.1/types.h>
#include <android/hardware/power/1.1/hwtypes.h>

namespace android {
namespace hardware {
namespace power {
namespace V1_1 {

::android::status_t readEmbeddedFromParcel(
        const PowerStateSubsystemSleepState &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.name),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::power::V1_1::PowerStateSubsystemSleepState, name));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const PowerStateSubsystemSleepState &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.name,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::power::V1_1::PowerStateSubsystemSleepState, name));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const PowerStateSubsystem &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.name),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::power::V1_1::PowerStateSubsystem, name));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_states_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::power::V1_1::PowerStateSubsystemSleepState> &>(obj.states),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::power::V1_1::PowerStateSubsystem, states), &_hidl_states_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.states.size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::power::V1_1::PowerStateSubsystemSleepState &>(obj.states[_hidl_index_0]),
                parcel,
                _hidl_states_child,
                _hidl_index_0 * sizeof(::android::hardware::power::V1_1::PowerStateSubsystemSleepState));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const PowerStateSubsystem &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.name,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::power::V1_1::PowerStateSubsystem, name));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_states_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.states,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::power::V1_1::PowerStateSubsystem, states), &_hidl_states_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.states.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                obj.states[_hidl_index_0],
                parcel,
                _hidl_states_child,
                _hidl_index_0 * sizeof(::android::hardware::power::V1_1::PowerStateSubsystemSleepState));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    return _hidl_err;
}

static_assert(sizeof(::android::hardware::MQDescriptor<char, ::android::hardware::kSynchronizedReadWrite>) == 32, "wrong size");
static_assert(sizeof(::android::hardware::hidl_handle) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_memory) == 40, "wrong size");
static_assert(sizeof(::android::hardware::hidl_string) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_vec<char>) == 16, "wrong size");

}  // namespace V1_1
}  // namespace power
}  // namespace hardware
}  // namespace android
