#define LOG_TAG "android.hardware.health@1.0::types"

#include <log/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <hidl/Static.h>
#include <hwbinder/ProcessState.h>
#include <utils/Trace.h>
#include <android/hardware/health/1.0/types.h>
#include <android/hardware/health/1.0/hwtypes.h>

namespace android {
namespace hardware {
namespace health {
namespace V1_0 {

::android::status_t readEmbeddedFromParcel(
        const HealthConfig &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.batteryStatusPath),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::health::V1_0::HealthConfig, batteryStatusPath));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.batteryHealthPath),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::health::V1_0::HealthConfig, batteryHealthPath));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.batteryPresentPath),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::health::V1_0::HealthConfig, batteryPresentPath));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.batteryCapacityPath),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::health::V1_0::HealthConfig, batteryCapacityPath));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.batteryVoltagePath),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::health::V1_0::HealthConfig, batteryVoltagePath));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.batteryTemperaturePath),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::health::V1_0::HealthConfig, batteryTemperaturePath));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.batteryTechnologyPath),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::health::V1_0::HealthConfig, batteryTechnologyPath));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.batteryCurrentNowPath),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::health::V1_0::HealthConfig, batteryCurrentNowPath));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.batteryCurrentAvgPath),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::health::V1_0::HealthConfig, batteryCurrentAvgPath));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.batteryChargeCounterPath),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::health::V1_0::HealthConfig, batteryChargeCounterPath));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.batteryFullChargePath),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::health::V1_0::HealthConfig, batteryFullChargePath));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.batteryCycleCountPath),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::health::V1_0::HealthConfig, batteryCycleCountPath));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const HealthConfig &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.batteryStatusPath,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::health::V1_0::HealthConfig, batteryStatusPath));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.batteryHealthPath,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::health::V1_0::HealthConfig, batteryHealthPath));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.batteryPresentPath,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::health::V1_0::HealthConfig, batteryPresentPath));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.batteryCapacityPath,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::health::V1_0::HealthConfig, batteryCapacityPath));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.batteryVoltagePath,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::health::V1_0::HealthConfig, batteryVoltagePath));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.batteryTemperaturePath,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::health::V1_0::HealthConfig, batteryTemperaturePath));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.batteryTechnologyPath,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::health::V1_0::HealthConfig, batteryTechnologyPath));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.batteryCurrentNowPath,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::health::V1_0::HealthConfig, batteryCurrentNowPath));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.batteryCurrentAvgPath,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::health::V1_0::HealthConfig, batteryCurrentAvgPath));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.batteryChargeCounterPath,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::health::V1_0::HealthConfig, batteryChargeCounterPath));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.batteryFullChargePath,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::health::V1_0::HealthConfig, batteryFullChargePath));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.batteryCycleCountPath,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::health::V1_0::HealthConfig, batteryCycleCountPath));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const HealthInfo &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.batteryTechnology),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::health::V1_0::HealthInfo, batteryTechnology));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const HealthInfo &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.batteryTechnology,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::health::V1_0::HealthInfo, batteryTechnology));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

static_assert(sizeof(::android::hardware::MQDescriptor<char, ::android::hardware::kSynchronizedReadWrite>) == 32, "wrong size");
static_assert(sizeof(::android::hardware::hidl_handle) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_memory) == 40, "wrong size");
static_assert(sizeof(::android::hardware::hidl_string) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_vec<char>) == 16, "wrong size");

}  // namespace V1_0
}  // namespace health
}  // namespace hardware
}  // namespace android
