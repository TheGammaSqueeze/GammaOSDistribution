#define LOG_TAG "android.hardware.keymaster@3.0::types"

#include <log/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <hidl/Static.h>
#include <hwbinder/ProcessState.h>
#include <utils/Trace.h>
#include <android/hardware/keymaster/3.0/types.h>
#include <android/hardware/keymaster/3.0/hwtypes.h>

namespace android {
namespace hardware {
namespace keymaster {
namespace V3_0 {

::android::status_t readEmbeddedFromParcel(
        const KeyParameter &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_blob_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(obj.blob),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::keymaster::V3_0::KeyParameter, blob), &_hidl_blob_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const KeyParameter &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_blob_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.blob,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::keymaster::V3_0::KeyParameter, blob), &_hidl_blob_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const KeyCharacteristics &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_softwareEnforced_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::keymaster::V3_0::KeyParameter> &>(obj.softwareEnforced),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::keymaster::V3_0::KeyCharacteristics, softwareEnforced), &_hidl_softwareEnforced_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.softwareEnforced.size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::keymaster::V3_0::KeyParameter &>(obj.softwareEnforced[_hidl_index_0]),
                parcel,
                _hidl_softwareEnforced_child,
                _hidl_index_0 * sizeof(::android::hardware::keymaster::V3_0::KeyParameter));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    size_t _hidl_teeEnforced_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::keymaster::V3_0::KeyParameter> &>(obj.teeEnforced),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::keymaster::V3_0::KeyCharacteristics, teeEnforced), &_hidl_teeEnforced_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.teeEnforced.size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::keymaster::V3_0::KeyParameter &>(obj.teeEnforced[_hidl_index_0]),
                parcel,
                _hidl_teeEnforced_child,
                _hidl_index_0 * sizeof(::android::hardware::keymaster::V3_0::KeyParameter));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const KeyCharacteristics &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_softwareEnforced_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.softwareEnforced,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::keymaster::V3_0::KeyCharacteristics, softwareEnforced), &_hidl_softwareEnforced_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.softwareEnforced.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                obj.softwareEnforced[_hidl_index_0],
                parcel,
                _hidl_softwareEnforced_child,
                _hidl_index_0 * sizeof(::android::hardware::keymaster::V3_0::KeyParameter));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    size_t _hidl_teeEnforced_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.teeEnforced,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::keymaster::V3_0::KeyCharacteristics, teeEnforced), &_hidl_teeEnforced_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.teeEnforced.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                obj.teeEnforced[_hidl_index_0],
                parcel,
                _hidl_teeEnforced_child,
                _hidl_index_0 * sizeof(::android::hardware::keymaster::V3_0::KeyParameter));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    return _hidl_err;
}

static_assert(sizeof(::android::hardware::MQDescriptor<char, ::android::hardware::kSynchronizedReadWrite>) == 32, "wrong size");
static_assert(sizeof(::android::hardware::hidl_handle) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_memory) == 40, "wrong size");
static_assert(sizeof(::android::hardware::hidl_string) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_vec<char>) == 16, "wrong size");

}  // namespace V3_0
}  // namespace keymaster
}  // namespace hardware
}  // namespace android
