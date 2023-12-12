#define LOG_TAG "android.hardware.radio@1.1::types"

#include <log/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <hidl/Static.h>
#include <hwbinder/ProcessState.h>
#include <utils/Trace.h>
#include <android/hardware/radio/1.1/types.h>
#include <android/hardware/radio/1.1/hwtypes.h>

namespace android {
namespace hardware {
namespace radio {
namespace V1_1 {

::android::status_t readEmbeddedFromParcel(
        const RadioAccessSpecifier &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_geranBands_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::radio::V1_1::GeranBands> &>(obj.geranBands),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_1::RadioAccessSpecifier, geranBands), &_hidl_geranBands_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_utranBands_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::radio::V1_1::UtranBands> &>(obj.utranBands),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_1::RadioAccessSpecifier, utranBands), &_hidl_utranBands_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_eutranBands_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::radio::V1_1::EutranBands> &>(obj.eutranBands),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_1::RadioAccessSpecifier, eutranBands), &_hidl_eutranBands_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_channels_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<int32_t> &>(obj.channels),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_1::RadioAccessSpecifier, channels), &_hidl_channels_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const RadioAccessSpecifier &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_geranBands_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.geranBands,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_1::RadioAccessSpecifier, geranBands), &_hidl_geranBands_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_utranBands_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.utranBands,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_1::RadioAccessSpecifier, utranBands), &_hidl_utranBands_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_eutranBands_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.eutranBands,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_1::RadioAccessSpecifier, eutranBands), &_hidl_eutranBands_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_channels_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.channels,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_1::RadioAccessSpecifier, channels), &_hidl_channels_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const NetworkScanRequest &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_specifiers_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::radio::V1_1::RadioAccessSpecifier> &>(obj.specifiers),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_1::NetworkScanRequest, specifiers), &_hidl_specifiers_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.specifiers.size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::radio::V1_1::RadioAccessSpecifier &>(obj.specifiers[_hidl_index_0]),
                parcel,
                _hidl_specifiers_child,
                _hidl_index_0 * sizeof(::android::hardware::radio::V1_1::RadioAccessSpecifier));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const NetworkScanRequest &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_specifiers_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.specifiers,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_1::NetworkScanRequest, specifiers), &_hidl_specifiers_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.specifiers.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                obj.specifiers[_hidl_index_0],
                parcel,
                _hidl_specifiers_child,
                _hidl_index_0 * sizeof(::android::hardware::radio::V1_1::RadioAccessSpecifier));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const NetworkScanResult &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_networkInfos_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::radio::V1_0::CellInfo> &>(obj.networkInfos),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_1::NetworkScanResult, networkInfos), &_hidl_networkInfos_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.networkInfos.size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::radio::V1_0::CellInfo &>(obj.networkInfos[_hidl_index_0]),
                parcel,
                _hidl_networkInfos_child,
                _hidl_index_0 * sizeof(::android::hardware::radio::V1_0::CellInfo));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const NetworkScanResult &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_networkInfos_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.networkInfos,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_1::NetworkScanResult, networkInfos), &_hidl_networkInfos_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.networkInfos.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                obj.networkInfos[_hidl_index_0],
                parcel,
                _hidl_networkInfos_child,
                _hidl_index_0 * sizeof(::android::hardware::radio::V1_0::CellInfo));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const KeepaliveRequest &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_sourceAddress_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(obj.sourceAddress),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_1::KeepaliveRequest, sourceAddress), &_hidl_sourceAddress_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_destinationAddress_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(obj.destinationAddress),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_1::KeepaliveRequest, destinationAddress), &_hidl_destinationAddress_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const KeepaliveRequest &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_sourceAddress_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.sourceAddress,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_1::KeepaliveRequest, sourceAddress), &_hidl_sourceAddress_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_destinationAddress_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.destinationAddress,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_1::KeepaliveRequest, destinationAddress), &_hidl_destinationAddress_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const ImsiEncryptionInfo &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.mcc),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_1::ImsiEncryptionInfo, mcc));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.mnc),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_1::ImsiEncryptionInfo, mnc));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_carrierKey_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(obj.carrierKey),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_1::ImsiEncryptionInfo, carrierKey), &_hidl_carrierKey_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.keyIdentifier),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_1::ImsiEncryptionInfo, keyIdentifier));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const ImsiEncryptionInfo &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.mcc,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_1::ImsiEncryptionInfo, mcc));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.mnc,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_1::ImsiEncryptionInfo, mnc));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_carrierKey_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.carrierKey,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_1::ImsiEncryptionInfo, carrierKey), &_hidl_carrierKey_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.keyIdentifier,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_1::ImsiEncryptionInfo, keyIdentifier));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

static_assert(sizeof(::android::hardware::MQDescriptor<char, ::android::hardware::kSynchronizedReadWrite>) == 32, "wrong size");
static_assert(sizeof(::android::hardware::hidl_handle) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_memory) == 40, "wrong size");
static_assert(sizeof(::android::hardware::hidl_string) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_vec<char>) == 16, "wrong size");

}  // namespace V1_1
}  // namespace radio
}  // namespace hardware
}  // namespace android
