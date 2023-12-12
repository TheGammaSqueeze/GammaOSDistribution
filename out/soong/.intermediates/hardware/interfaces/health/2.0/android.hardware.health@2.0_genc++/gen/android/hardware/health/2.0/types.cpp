#define LOG_TAG "android.hardware.health@2.0::types"

#include <log/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <hidl/Static.h>
#include <hwbinder/ProcessState.h>
#include <utils/Trace.h>
#include <android/hardware/health/2.0/types.h>
#include <android/hardware/health/2.0/hwtypes.h>

namespace android {
namespace hardware {
namespace health {
namespace V2_0 {

::android::status_t readEmbeddedFromParcel(
        const StorageAttribute &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.name),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::health::V2_0::StorageAttribute, name));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const StorageAttribute &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.name,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::health::V2_0::StorageAttribute, name));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const StorageInfo &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::health::V2_0::StorageAttribute &>(obj.attr),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::health::V2_0::StorageInfo, attr));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.version),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::health::V2_0::StorageInfo, version));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const StorageInfo &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = writeEmbeddedToParcel(
            obj.attr,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::health::V2_0::StorageInfo, attr));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.version,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::health::V2_0::StorageInfo, version));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const DiskStats &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::health::V2_0::StorageAttribute &>(obj.attr),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::health::V2_0::DiskStats, attr));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const DiskStats &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = writeEmbeddedToParcel(
            obj.attr,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::health::V2_0::DiskStats, attr));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const HealthInfo &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::health::V1_0::HealthInfo &>(obj.legacy),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::health::V2_0::HealthInfo, legacy));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_diskStats_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::health::V2_0::DiskStats> &>(obj.diskStats),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::health::V2_0::HealthInfo, diskStats), &_hidl_diskStats_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.diskStats.size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::health::V2_0::DiskStats &>(obj.diskStats[_hidl_index_0]),
                parcel,
                _hidl_diskStats_child,
                _hidl_index_0 * sizeof(::android::hardware::health::V2_0::DiskStats));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    size_t _hidl_storageInfos_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::health::V2_0::StorageInfo> &>(obj.storageInfos),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::health::V2_0::HealthInfo, storageInfos), &_hidl_storageInfos_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.storageInfos.size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::health::V2_0::StorageInfo &>(obj.storageInfos[_hidl_index_0]),
                parcel,
                _hidl_storageInfos_child,
                _hidl_index_0 * sizeof(::android::hardware::health::V2_0::StorageInfo));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const HealthInfo &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = writeEmbeddedToParcel(
            obj.legacy,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::health::V2_0::HealthInfo, legacy));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_diskStats_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.diskStats,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::health::V2_0::HealthInfo, diskStats), &_hidl_diskStats_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.diskStats.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                obj.diskStats[_hidl_index_0],
                parcel,
                _hidl_diskStats_child,
                _hidl_index_0 * sizeof(::android::hardware::health::V2_0::DiskStats));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    size_t _hidl_storageInfos_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.storageInfos,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::health::V2_0::HealthInfo, storageInfos), &_hidl_storageInfos_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.storageInfos.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                obj.storageInfos[_hidl_index_0],
                parcel,
                _hidl_storageInfos_child,
                _hidl_index_0 * sizeof(::android::hardware::health::V2_0::StorageInfo));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    return _hidl_err;
}

static_assert(sizeof(::android::hardware::MQDescriptor<char, ::android::hardware::kSynchronizedReadWrite>) == 32, "wrong size");
static_assert(sizeof(::android::hardware::hidl_handle) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_memory) == 40, "wrong size");
static_assert(sizeof(::android::hardware::hidl_string) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_vec<char>) == 16, "wrong size");

}  // namespace V2_0
}  // namespace health
}  // namespace hardware
}  // namespace android
