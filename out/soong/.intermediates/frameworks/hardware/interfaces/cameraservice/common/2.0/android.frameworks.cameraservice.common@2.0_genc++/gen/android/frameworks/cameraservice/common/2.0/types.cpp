#define LOG_TAG "android.frameworks.cameraservice.common@2.0::types"

#include <log/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <hidl/Static.h>
#include <hwbinder/ProcessState.h>
#include <utils/Trace.h>
#include <android/frameworks/cameraservice/common/2.0/types.h>
#include <android/frameworks/cameraservice/common/2.0/hwtypes.h>

namespace android {
namespace frameworks {
namespace cameraservice {
namespace common {
namespace V2_0 {

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
            parentOffset + offsetof(::android::frameworks::cameraservice::common::V2_0::VendorTag, tagName));

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
            parentOffset + offsetof(::android::frameworks::cameraservice::common::V2_0::VendorTag, tagName));

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
            parentOffset + offsetof(::android::frameworks::cameraservice::common::V2_0::VendorTagSection, sectionName));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_tags_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::frameworks::cameraservice::common::V2_0::VendorTag> &>(obj.tags),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::frameworks::cameraservice::common::V2_0::VendorTagSection, tags), &_hidl_tags_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.tags.size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::frameworks::cameraservice::common::V2_0::VendorTag &>(obj.tags[_hidl_index_0]),
                parcel,
                _hidl_tags_child,
                _hidl_index_0 * sizeof(::android::frameworks::cameraservice::common::V2_0::VendorTag));

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
            parentOffset + offsetof(::android::frameworks::cameraservice::common::V2_0::VendorTagSection, sectionName));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_tags_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.tags,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::frameworks::cameraservice::common::V2_0::VendorTagSection, tags), &_hidl_tags_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.tags.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                obj.tags[_hidl_index_0],
                parcel,
                _hidl_tags_child,
                _hidl_index_0 * sizeof(::android::frameworks::cameraservice::common::V2_0::VendorTag));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const ProviderIdAndVendorTagSections &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_vendorTagSections_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::frameworks::cameraservice::common::V2_0::VendorTagSection> &>(obj.vendorTagSections),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::frameworks::cameraservice::common::V2_0::ProviderIdAndVendorTagSections, vendorTagSections), &_hidl_vendorTagSections_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.vendorTagSections.size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::frameworks::cameraservice::common::V2_0::VendorTagSection &>(obj.vendorTagSections[_hidl_index_0]),
                parcel,
                _hidl_vendorTagSections_child,
                _hidl_index_0 * sizeof(::android::frameworks::cameraservice::common::V2_0::VendorTagSection));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const ProviderIdAndVendorTagSections &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_vendorTagSections_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.vendorTagSections,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::frameworks::cameraservice::common::V2_0::ProviderIdAndVendorTagSections, vendorTagSections), &_hidl_vendorTagSections_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.vendorTagSections.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                obj.vendorTagSections[_hidl_index_0],
                parcel,
                _hidl_vendorTagSections_child,
                _hidl_index_0 * sizeof(::android::frameworks::cameraservice::common::V2_0::VendorTagSection));

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
}  // namespace common
}  // namespace cameraservice
}  // namespace frameworks
}  // namespace android
