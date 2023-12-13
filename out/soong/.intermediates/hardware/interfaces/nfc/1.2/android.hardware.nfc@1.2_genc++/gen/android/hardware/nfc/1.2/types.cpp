#define LOG_TAG "android.hardware.nfc@1.2::types"

#include <log/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <hidl/Static.h>
#include <hwbinder/ProcessState.h>
#include <utils/Trace.h>
#include <android/hardware/nfc/1.2/types.h>
#include <android/hardware/nfc/1.2/hwtypes.h>

namespace android {
namespace hardware {
namespace nfc {
namespace V1_2 {

::android::status_t readEmbeddedFromParcel(
        const NfcConfig &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::nfc::V1_1::NfcConfig &>(obj.v1_1),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::nfc::V1_2::NfcConfig, v1_1));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_offHostRouteUicc_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(obj.offHostRouteUicc),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::nfc::V1_2::NfcConfig, offHostRouteUicc), &_hidl_offHostRouteUicc_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_offHostRouteEse_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(obj.offHostRouteEse),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::nfc::V1_2::NfcConfig, offHostRouteEse), &_hidl_offHostRouteEse_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const NfcConfig &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = writeEmbeddedToParcel(
            obj.v1_1,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::nfc::V1_2::NfcConfig, v1_1));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_offHostRouteUicc_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.offHostRouteUicc,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::nfc::V1_2::NfcConfig, offHostRouteUicc), &_hidl_offHostRouteUicc_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_offHostRouteEse_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.offHostRouteEse,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::nfc::V1_2::NfcConfig, offHostRouteEse), &_hidl_offHostRouteEse_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

static_assert(sizeof(::android::hardware::MQDescriptor<char, ::android::hardware::kSynchronizedReadWrite>) == 32, "wrong size");
static_assert(sizeof(::android::hardware::hidl_handle) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_memory) == 40, "wrong size");
static_assert(sizeof(::android::hardware::hidl_string) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_vec<char>) == 16, "wrong size");

}  // namespace V1_2
}  // namespace nfc
}  // namespace hardware
}  // namespace android
