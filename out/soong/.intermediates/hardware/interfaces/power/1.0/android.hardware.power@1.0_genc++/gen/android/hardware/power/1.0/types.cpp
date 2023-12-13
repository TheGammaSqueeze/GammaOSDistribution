#define LOG_TAG "android.hardware.power@1.0::types"

#include <log/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <hidl/Static.h>
#include <hwbinder/ProcessState.h>
#include <utils/Trace.h>
#include <android/hardware/power/1.0/types.h>
#include <android/hardware/power/1.0/hwtypes.h>

namespace android {
namespace hardware {
namespace power {
namespace V1_0 {

::android::status_t readEmbeddedFromParcel(
        const PowerStateVoter &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.name),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::power::V1_0::PowerStateVoter, name));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const PowerStateVoter &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.name,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::power::V1_0::PowerStateVoter, name));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const PowerStatePlatformSleepState &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.name),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::power::V1_0::PowerStatePlatformSleepState, name));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_voters_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::power::V1_0::PowerStateVoter> &>(obj.voters),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::power::V1_0::PowerStatePlatformSleepState, voters), &_hidl_voters_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.voters.size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::power::V1_0::PowerStateVoter &>(obj.voters[_hidl_index_0]),
                parcel,
                _hidl_voters_child,
                _hidl_index_0 * sizeof(::android::hardware::power::V1_0::PowerStateVoter));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const PowerStatePlatformSleepState &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.name,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::power::V1_0::PowerStatePlatformSleepState, name));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_voters_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.voters,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::power::V1_0::PowerStatePlatformSleepState, voters), &_hidl_voters_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.voters.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                obj.voters[_hidl_index_0],
                parcel,
                _hidl_voters_child,
                _hidl_index_0 * sizeof(::android::hardware::power::V1_0::PowerStateVoter));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    return _hidl_err;
}

static_assert(sizeof(::android::hardware::MQDescriptor<char, ::android::hardware::kSynchronizedReadWrite>) == 32, "wrong size");
static_assert(sizeof(::android::hardware::hidl_handle) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_memory) == 40, "wrong size");
static_assert(sizeof(::android::hardware::hidl_string) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_vec<char>) == 16, "wrong size");

}  // namespace V1_0
}  // namespace power
}  // namespace hardware
}  // namespace android
