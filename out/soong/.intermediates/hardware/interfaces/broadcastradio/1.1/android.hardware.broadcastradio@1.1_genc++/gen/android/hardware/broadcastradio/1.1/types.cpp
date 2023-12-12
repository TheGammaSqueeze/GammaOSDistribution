#define LOG_TAG "android.hardware.broadcastradio@1.1::types"

#include <log/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <hidl/Static.h>
#include <hwbinder/ProcessState.h>
#include <utils/Trace.h>
#include <android/hardware/broadcastradio/1.1/types.h>
#include <android/hardware/broadcastradio/1.1/hwtypes.h>

namespace android {
namespace hardware {
namespace broadcastradio {
namespace V1_1 {

::android::status_t readEmbeddedFromParcel(
        const VendorKeyValue &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.key),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::broadcastradio::V1_1::VendorKeyValue, key));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.value),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::broadcastradio::V1_1::VendorKeyValue, value));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const VendorKeyValue &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.key,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::broadcastradio::V1_1::VendorKeyValue, key));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.value,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::broadcastradio::V1_1::VendorKeyValue, value));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const Properties &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::broadcastradio::V1_0::Properties &>(obj.base),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::broadcastradio::V1_1::Properties, base));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_supportedProgramTypes_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint32_t> &>(obj.supportedProgramTypes),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::broadcastradio::V1_1::Properties, supportedProgramTypes), &_hidl_supportedProgramTypes_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_supportedIdentifierTypes_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint32_t> &>(obj.supportedIdentifierTypes),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::broadcastradio::V1_1::Properties, supportedIdentifierTypes), &_hidl_supportedIdentifierTypes_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_vendorInfo_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::broadcastradio::V1_1::VendorKeyValue> &>(obj.vendorInfo),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::broadcastradio::V1_1::Properties, vendorInfo), &_hidl_vendorInfo_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.vendorInfo.size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::broadcastradio::V1_1::VendorKeyValue &>(obj.vendorInfo[_hidl_index_0]),
                parcel,
                _hidl_vendorInfo_child,
                _hidl_index_0 * sizeof(::android::hardware::broadcastradio::V1_1::VendorKeyValue));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const Properties &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = writeEmbeddedToParcel(
            obj.base,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::broadcastradio::V1_1::Properties, base));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_supportedProgramTypes_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.supportedProgramTypes,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::broadcastradio::V1_1::Properties, supportedProgramTypes), &_hidl_supportedProgramTypes_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_supportedIdentifierTypes_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.supportedIdentifierTypes,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::broadcastradio::V1_1::Properties, supportedIdentifierTypes), &_hidl_supportedIdentifierTypes_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_vendorInfo_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.vendorInfo,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::broadcastradio::V1_1::Properties, vendorInfo), &_hidl_vendorInfo_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.vendorInfo.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                obj.vendorInfo[_hidl_index_0],
                parcel,
                _hidl_vendorInfo_child,
                _hidl_index_0 * sizeof(::android::hardware::broadcastradio::V1_1::VendorKeyValue));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const ProgramSelector &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_secondaryIds_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::broadcastradio::V1_1::ProgramIdentifier> &>(obj.secondaryIds),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::broadcastradio::V1_1::ProgramSelector, secondaryIds), &_hidl_secondaryIds_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_vendorIds_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint64_t> &>(obj.vendorIds),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::broadcastradio::V1_1::ProgramSelector, vendorIds), &_hidl_vendorIds_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const ProgramSelector &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_secondaryIds_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.secondaryIds,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::broadcastradio::V1_1::ProgramSelector, secondaryIds), &_hidl_secondaryIds_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_vendorIds_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.vendorIds,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::broadcastradio::V1_1::ProgramSelector, vendorIds), &_hidl_vendorIds_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const ProgramInfo &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::broadcastradio::V1_0::ProgramInfo &>(obj.base),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::broadcastradio::V1_1::ProgramInfo, base));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::broadcastradio::V1_1::ProgramSelector &>(obj.selector),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::broadcastradio::V1_1::ProgramInfo, selector));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_vendorInfo_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::broadcastradio::V1_1::VendorKeyValue> &>(obj.vendorInfo),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::broadcastradio::V1_1::ProgramInfo, vendorInfo), &_hidl_vendorInfo_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.vendorInfo.size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::broadcastradio::V1_1::VendorKeyValue &>(obj.vendorInfo[_hidl_index_0]),
                parcel,
                _hidl_vendorInfo_child,
                _hidl_index_0 * sizeof(::android::hardware::broadcastradio::V1_1::VendorKeyValue));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const ProgramInfo &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = writeEmbeddedToParcel(
            obj.base,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::broadcastradio::V1_1::ProgramInfo, base));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = writeEmbeddedToParcel(
            obj.selector,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::broadcastradio::V1_1::ProgramInfo, selector));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_vendorInfo_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.vendorInfo,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::broadcastradio::V1_1::ProgramInfo, vendorInfo), &_hidl_vendorInfo_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.vendorInfo.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                obj.vendorInfo[_hidl_index_0],
                parcel,
                _hidl_vendorInfo_child,
                _hidl_index_0 * sizeof(::android::hardware::broadcastradio::V1_1::VendorKeyValue));

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
}  // namespace broadcastradio
}  // namespace hardware
}  // namespace android
