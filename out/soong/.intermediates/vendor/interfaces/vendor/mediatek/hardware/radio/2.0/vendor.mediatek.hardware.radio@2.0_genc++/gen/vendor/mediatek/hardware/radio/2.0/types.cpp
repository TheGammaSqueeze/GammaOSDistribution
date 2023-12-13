#define LOG_TAG "vendor.mediatek.hardware.radio@2.0::types"

#include <log/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <hidl/Static.h>
#include <hwbinder/ProcessState.h>
#include <utils/Trace.h>
#include <vendor/mediatek/hardware/radio/2.0/types.h>
#include <vendor/mediatek/hardware/radio/2.0/hwtypes.h>

namespace vendor {
namespace mediatek {
namespace hardware {
namespace radio {
namespace V2_0 {

::android::status_t readEmbeddedFromParcel(
        const MtkDataProfileInfo &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::radio::V1_0::DataProfileInfo &>(obj.dpi),
            parcel,
            parentHandle,
            parentOffset + offsetof(::vendor::mediatek::hardware::radio::V2_0::MtkDataProfileInfo, dpi));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const MtkDataProfileInfo &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = writeEmbeddedToParcel(
            obj.dpi,
            parcel,
            parentHandle,
            parentOffset + offsetof(::vendor::mediatek::hardware::radio::V2_0::MtkDataProfileInfo, dpi));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const IncomingCallNotification &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.callId),
            parcel,
            parentHandle,
            parentOffset + offsetof(::vendor::mediatek::hardware::radio::V2_0::IncomingCallNotification, callId));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.number),
            parcel,
            parentHandle,
            parentOffset + offsetof(::vendor::mediatek::hardware::radio::V2_0::IncomingCallNotification, number));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.type),
            parcel,
            parentHandle,
            parentOffset + offsetof(::vendor::mediatek::hardware::radio::V2_0::IncomingCallNotification, type));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.callMode),
            parcel,
            parentHandle,
            parentOffset + offsetof(::vendor::mediatek::hardware::radio::V2_0::IncomingCallNotification, callMode));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.seqNo),
            parcel,
            parentHandle,
            parentOffset + offsetof(::vendor::mediatek::hardware::radio::V2_0::IncomingCallNotification, seqNo));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.redirectNumber),
            parcel,
            parentHandle,
            parentOffset + offsetof(::vendor::mediatek::hardware::radio::V2_0::IncomingCallNotification, redirectNumber));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.toNumber),
            parcel,
            parentHandle,
            parentOffset + offsetof(::vendor::mediatek::hardware::radio::V2_0::IncomingCallNotification, toNumber));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const IncomingCallNotification &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.callId,
            parcel,
            parentHandle,
            parentOffset + offsetof(::vendor::mediatek::hardware::radio::V2_0::IncomingCallNotification, callId));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.number,
            parcel,
            parentHandle,
            parentOffset + offsetof(::vendor::mediatek::hardware::radio::V2_0::IncomingCallNotification, number));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.type,
            parcel,
            parentHandle,
            parentOffset + offsetof(::vendor::mediatek::hardware::radio::V2_0::IncomingCallNotification, type));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.callMode,
            parcel,
            parentHandle,
            parentOffset + offsetof(::vendor::mediatek::hardware::radio::V2_0::IncomingCallNotification, callMode));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.seqNo,
            parcel,
            parentHandle,
            parentOffset + offsetof(::vendor::mediatek::hardware::radio::V2_0::IncomingCallNotification, seqNo));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.redirectNumber,
            parcel,
            parentHandle,
            parentOffset + offsetof(::vendor::mediatek::hardware::radio::V2_0::IncomingCallNotification, redirectNumber));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.toNumber,
            parcel,
            parentHandle,
            parentOffset + offsetof(::vendor::mediatek::hardware::radio::V2_0::IncomingCallNotification, toNumber));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const MtkSetupDataCallResult &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::radio::V1_0::SetupDataCallResult &>(obj.dcr),
            parcel,
            parentHandle,
            parentOffset + offsetof(::vendor::mediatek::hardware::radio::V2_0::MtkSetupDataCallResult, dcr));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const MtkSetupDataCallResult &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = writeEmbeddedToParcel(
            obj.dcr,
            parcel,
            parentHandle,
            parentOffset + offsetof(::vendor::mediatek::hardware::radio::V2_0::MtkSetupDataCallResult, dcr));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

static_assert(sizeof(::android::hardware::MQDescriptor<char, ::android::hardware::kSynchronizedReadWrite>) == 32, "wrong size");
static_assert(sizeof(::android::hardware::hidl_handle) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_memory) == 40, "wrong size");
static_assert(sizeof(::android::hardware::hidl_string) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_vec<char>) == 16, "wrong size");

}  // namespace V2_0
}  // namespace radio
}  // namespace hardware
}  // namespace mediatek
}  // namespace vendor
