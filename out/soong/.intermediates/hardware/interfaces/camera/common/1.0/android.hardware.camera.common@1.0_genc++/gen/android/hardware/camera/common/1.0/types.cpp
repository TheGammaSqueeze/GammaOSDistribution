#define LOG_TAG "android.hardware.camera.common@1.0::types"

#include <log/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <hidl/Static.h>
#include <hwbinder/ProcessState.h>
#include <utils/Trace.h>
#include <android/hardware/camera/common/1.0/types.h>
#include <android/hardware/camera/common/1.0/hwtypes.h>

namespace android {
namespace hardware {
namespace camera {
namespace common {
namespace V1_0 {

::android::status_t readEmbeddedFromParcel(
        const VendorTag &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.tagName),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::camera::common::V1_0::VendorTag, tagName));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const VendorTag &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.tagName,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::camera::common::V1_0::VendorTag, tagName));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const VendorTagSection &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.sectionName),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::camera::common::V1_0::VendorTagSection, sectionName));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_tags_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::camera::common::V1_0::VendorTag> &>(obj.tags),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::camera::common::V1_0::VendorTagSection, tags), &_hidl_tags_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.tags.size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::camera::common::V1_0::VendorTag &>(obj.tags[_hidl_index_0]),
                parcel,
                _hidl_tags_child,
                _hidl_index_0 * sizeof(::android::hardware::camera::common::V1_0::VendorTag));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const VendorTagSection &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.sectionName,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::camera::common::V1_0::VendorTagSection, sectionName));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_tags_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.tags,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::camera::common::V1_0::VendorTagSection, tags), &_hidl_tags_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.tags.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                obj.tags[_hidl_index_0],
                parcel,
                _hidl_tags_child,
                _hidl_index_0 * sizeof(::android::hardware::camera::common::V1_0::VendorTag));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const CameraResourceCost &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_conflictingDevices_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::hidl_string> &>(obj.conflictingDevices),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::camera::common::V1_0::CameraResourceCost, conflictingDevices), &_hidl_conflictingDevices_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.conflictingDevices.size(); ++_hidl_index_0) {
        _hidl_err = ::android::hardware::readEmbeddedFromParcel(
                const_cast<::android::hardware::hidl_string &>(obj.conflictingDevices[_hidl_index_0]),
                parcel,
                _hidl_conflictingDevices_child,
                _hidl_index_0 * sizeof(::android::hardware::hidl_string));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const CameraResourceCost &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_conflictingDevices_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.conflictingDevices,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::camera::common::V1_0::CameraResourceCost, conflictingDevices), &_hidl_conflictingDevices_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.conflictingDevices.size(); ++_hidl_index_0) {
        _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                obj.conflictingDevices[_hidl_index_0],
                parcel,
                _hidl_conflictingDevices_child,
                _hidl_index_0 * sizeof(::android::hardware::hidl_string));

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
}  // namespace common
}  // namespace camera
}  // namespace hardware
}  // namespace android
