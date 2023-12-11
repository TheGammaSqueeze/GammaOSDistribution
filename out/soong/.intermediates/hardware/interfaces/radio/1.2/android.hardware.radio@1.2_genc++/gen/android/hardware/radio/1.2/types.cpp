#define LOG_TAG "android.hardware.radio@1.2::types"

#include <log/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <hidl/Static.h>
#include <hwbinder/ProcessState.h>
#include <utils/Trace.h>
#include <android/hardware/radio/1.2/types.h>
#include <android/hardware/radio/1.2/hwtypes.h>

namespace android {
namespace hardware {
namespace radio {
namespace V1_2 {

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
            parentOffset + offsetof(::android::hardware::radio::V1_2::NetworkScanRequest, specifiers), &_hidl_specifiers_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.specifiers.size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::radio::V1_1::RadioAccessSpecifier &>(obj.specifiers[_hidl_index_0]),
                parcel,
                _hidl_specifiers_child,
                _hidl_index_0 * sizeof(::android::hardware::radio::V1_1::RadioAccessSpecifier));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    size_t _hidl_mccMncs_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::hidl_string> &>(obj.mccMncs),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_2::NetworkScanRequest, mccMncs), &_hidl_mccMncs_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.mccMncs.size(); ++_hidl_index_0) {
        _hidl_err = ::android::hardware::readEmbeddedFromParcel(
                const_cast<::android::hardware::hidl_string &>(obj.mccMncs[_hidl_index_0]),
                parcel,
                _hidl_mccMncs_child,
                _hidl_index_0 * sizeof(::android::hardware::hidl_string));

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
            parentOffset + offsetof(::android::hardware::radio::V1_2::NetworkScanRequest, specifiers), &_hidl_specifiers_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.specifiers.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                obj.specifiers[_hidl_index_0],
                parcel,
                _hidl_specifiers_child,
                _hidl_index_0 * sizeof(::android::hardware::radio::V1_1::RadioAccessSpecifier));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    size_t _hidl_mccMncs_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.mccMncs,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_2::NetworkScanRequest, mccMncs), &_hidl_mccMncs_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.mccMncs.size(); ++_hidl_index_0) {
        _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                obj.mccMncs[_hidl_index_0],
                parcel,
                _hidl_mccMncs_child,
                _hidl_index_0 * sizeof(::android::hardware::hidl_string));

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
            const_cast<::android::hardware::hidl_vec<::android::hardware::radio::V1_2::CellInfo> &>(obj.networkInfos),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_2::NetworkScanResult, networkInfos), &_hidl_networkInfos_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.networkInfos.size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::radio::V1_2::CellInfo &>(obj.networkInfos[_hidl_index_0]),
                parcel,
                _hidl_networkInfos_child,
                _hidl_index_0 * sizeof(::android::hardware::radio::V1_2::CellInfo));

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
            parentOffset + offsetof(::android::hardware::radio::V1_2::NetworkScanResult, networkInfos), &_hidl_networkInfos_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.networkInfos.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                obj.networkInfos[_hidl_index_0],
                parcel,
                _hidl_networkInfos_child,
                _hidl_index_0 * sizeof(::android::hardware::radio::V1_2::CellInfo));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const CellIdentityOperatorNames &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.alphaLong),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_2::CellIdentityOperatorNames, alphaLong));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.alphaShort),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_2::CellIdentityOperatorNames, alphaShort));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const CellIdentityOperatorNames &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.alphaLong,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_2::CellIdentityOperatorNames, alphaLong));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.alphaShort,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_2::CellIdentityOperatorNames, alphaShort));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const CellIdentityCdma &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::radio::V1_2::CellIdentityOperatorNames &>(obj.operatorNames),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_2::CellIdentityCdma, operatorNames));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const CellIdentityCdma &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = writeEmbeddedToParcel(
            obj.operatorNames,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_2::CellIdentityCdma, operatorNames));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const CellIdentityGsm &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::radio::V1_0::CellIdentityGsm &>(obj.base),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_2::CellIdentityGsm, base));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::radio::V1_2::CellIdentityOperatorNames &>(obj.operatorNames),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_2::CellIdentityGsm, operatorNames));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const CellIdentityGsm &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = writeEmbeddedToParcel(
            obj.base,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_2::CellIdentityGsm, base));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = writeEmbeddedToParcel(
            obj.operatorNames,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_2::CellIdentityGsm, operatorNames));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const CellIdentityLte &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::radio::V1_0::CellIdentityLte &>(obj.base),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_2::CellIdentityLte, base));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::radio::V1_2::CellIdentityOperatorNames &>(obj.operatorNames),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_2::CellIdentityLte, operatorNames));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const CellIdentityLte &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = writeEmbeddedToParcel(
            obj.base,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_2::CellIdentityLte, base));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = writeEmbeddedToParcel(
            obj.operatorNames,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_2::CellIdentityLte, operatorNames));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const CellIdentityTdscdma &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::radio::V1_0::CellIdentityTdscdma &>(obj.base),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_2::CellIdentityTdscdma, base));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::radio::V1_2::CellIdentityOperatorNames &>(obj.operatorNames),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_2::CellIdentityTdscdma, operatorNames));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const CellIdentityTdscdma &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = writeEmbeddedToParcel(
            obj.base,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_2::CellIdentityTdscdma, base));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = writeEmbeddedToParcel(
            obj.operatorNames,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_2::CellIdentityTdscdma, operatorNames));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const CellIdentityWcdma &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::radio::V1_0::CellIdentityWcdma &>(obj.base),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_2::CellIdentityWcdma, base));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::radio::V1_2::CellIdentityOperatorNames &>(obj.operatorNames),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_2::CellIdentityWcdma, operatorNames));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const CellIdentityWcdma &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = writeEmbeddedToParcel(
            obj.base,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_2::CellIdentityWcdma, base));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = writeEmbeddedToParcel(
            obj.operatorNames,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_2::CellIdentityWcdma, operatorNames));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const CellInfoGsm &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::radio::V1_2::CellIdentityGsm &>(obj.cellIdentityGsm),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_2::CellInfoGsm, cellIdentityGsm));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const CellInfoGsm &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = writeEmbeddedToParcel(
            obj.cellIdentityGsm,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_2::CellInfoGsm, cellIdentityGsm));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const CellInfoWcdma &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::radio::V1_2::CellIdentityWcdma &>(obj.cellIdentityWcdma),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_2::CellInfoWcdma, cellIdentityWcdma));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const CellInfoWcdma &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = writeEmbeddedToParcel(
            obj.cellIdentityWcdma,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_2::CellInfoWcdma, cellIdentityWcdma));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const CellInfoCdma &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::radio::V1_2::CellIdentityCdma &>(obj.cellIdentityCdma),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_2::CellInfoCdma, cellIdentityCdma));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const CellInfoCdma &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = writeEmbeddedToParcel(
            obj.cellIdentityCdma,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_2::CellInfoCdma, cellIdentityCdma));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const CellInfoLte &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::radio::V1_2::CellIdentityLte &>(obj.cellIdentityLte),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_2::CellInfoLte, cellIdentityLte));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const CellInfoLte &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = writeEmbeddedToParcel(
            obj.cellIdentityLte,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_2::CellInfoLte, cellIdentityLte));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const CellInfoTdscdma &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::radio::V1_2::CellIdentityTdscdma &>(obj.cellIdentityTdscdma),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_2::CellInfoTdscdma, cellIdentityTdscdma));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const CellInfoTdscdma &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = writeEmbeddedToParcel(
            obj.cellIdentityTdscdma,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_2::CellInfoTdscdma, cellIdentityTdscdma));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const CellInfo &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_gsm_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::radio::V1_2::CellInfoGsm> &>(obj.gsm),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_2::CellInfo, gsm), &_hidl_gsm_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.gsm.size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::radio::V1_2::CellInfoGsm &>(obj.gsm[_hidl_index_0]),
                parcel,
                _hidl_gsm_child,
                _hidl_index_0 * sizeof(::android::hardware::radio::V1_2::CellInfoGsm));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    size_t _hidl_cdma_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::radio::V1_2::CellInfoCdma> &>(obj.cdma),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_2::CellInfo, cdma), &_hidl_cdma_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.cdma.size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::radio::V1_2::CellInfoCdma &>(obj.cdma[_hidl_index_0]),
                parcel,
                _hidl_cdma_child,
                _hidl_index_0 * sizeof(::android::hardware::radio::V1_2::CellInfoCdma));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    size_t _hidl_lte_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::radio::V1_2::CellInfoLte> &>(obj.lte),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_2::CellInfo, lte), &_hidl_lte_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.lte.size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::radio::V1_2::CellInfoLte &>(obj.lte[_hidl_index_0]),
                parcel,
                _hidl_lte_child,
                _hidl_index_0 * sizeof(::android::hardware::radio::V1_2::CellInfoLte));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    size_t _hidl_wcdma_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::radio::V1_2::CellInfoWcdma> &>(obj.wcdma),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_2::CellInfo, wcdma), &_hidl_wcdma_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.wcdma.size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::radio::V1_2::CellInfoWcdma &>(obj.wcdma[_hidl_index_0]),
                parcel,
                _hidl_wcdma_child,
                _hidl_index_0 * sizeof(::android::hardware::radio::V1_2::CellInfoWcdma));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    size_t _hidl_tdscdma_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::radio::V1_2::CellInfoTdscdma> &>(obj.tdscdma),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_2::CellInfo, tdscdma), &_hidl_tdscdma_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.tdscdma.size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::radio::V1_2::CellInfoTdscdma &>(obj.tdscdma[_hidl_index_0]),
                parcel,
                _hidl_tdscdma_child,
                _hidl_index_0 * sizeof(::android::hardware::radio::V1_2::CellInfoTdscdma));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const CellInfo &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_gsm_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.gsm,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_2::CellInfo, gsm), &_hidl_gsm_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.gsm.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                obj.gsm[_hidl_index_0],
                parcel,
                _hidl_gsm_child,
                _hidl_index_0 * sizeof(::android::hardware::radio::V1_2::CellInfoGsm));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    size_t _hidl_cdma_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.cdma,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_2::CellInfo, cdma), &_hidl_cdma_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.cdma.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                obj.cdma[_hidl_index_0],
                parcel,
                _hidl_cdma_child,
                _hidl_index_0 * sizeof(::android::hardware::radio::V1_2::CellInfoCdma));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    size_t _hidl_lte_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.lte,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_2::CellInfo, lte), &_hidl_lte_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.lte.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                obj.lte[_hidl_index_0],
                parcel,
                _hidl_lte_child,
                _hidl_index_0 * sizeof(::android::hardware::radio::V1_2::CellInfoLte));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    size_t _hidl_wcdma_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.wcdma,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_2::CellInfo, wcdma), &_hidl_wcdma_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.wcdma.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                obj.wcdma[_hidl_index_0],
                parcel,
                _hidl_wcdma_child,
                _hidl_index_0 * sizeof(::android::hardware::radio::V1_2::CellInfoWcdma));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    size_t _hidl_tdscdma_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.tdscdma,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_2::CellInfo, tdscdma), &_hidl_tdscdma_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.tdscdma.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                obj.tdscdma[_hidl_index_0],
                parcel,
                _hidl_tdscdma_child,
                _hidl_index_0 * sizeof(::android::hardware::radio::V1_2::CellInfoTdscdma));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const CardStatus &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::radio::V1_0::CardStatus &>(obj.base),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_2::CardStatus, base));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.atr),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_2::CardStatus, atr));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.iccid),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_2::CardStatus, iccid));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const CardStatus &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = writeEmbeddedToParcel(
            obj.base,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_2::CardStatus, base));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.atr,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_2::CardStatus, atr));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.iccid,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_2::CardStatus, iccid));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const Call &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::radio::V1_0::Call &>(obj.base),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_2::Call, base));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const Call &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = writeEmbeddedToParcel(
            obj.base,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_2::Call, base));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const CellIdentity &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_cellIdentityGsm_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::radio::V1_2::CellIdentityGsm> &>(obj.cellIdentityGsm),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_2::CellIdentity, cellIdentityGsm), &_hidl_cellIdentityGsm_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.cellIdentityGsm.size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::radio::V1_2::CellIdentityGsm &>(obj.cellIdentityGsm[_hidl_index_0]),
                parcel,
                _hidl_cellIdentityGsm_child,
                _hidl_index_0 * sizeof(::android::hardware::radio::V1_2::CellIdentityGsm));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    size_t _hidl_cellIdentityWcdma_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::radio::V1_2::CellIdentityWcdma> &>(obj.cellIdentityWcdma),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_2::CellIdentity, cellIdentityWcdma), &_hidl_cellIdentityWcdma_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.cellIdentityWcdma.size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::radio::V1_2::CellIdentityWcdma &>(obj.cellIdentityWcdma[_hidl_index_0]),
                parcel,
                _hidl_cellIdentityWcdma_child,
                _hidl_index_0 * sizeof(::android::hardware::radio::V1_2::CellIdentityWcdma));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    size_t _hidl_cellIdentityCdma_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::radio::V1_2::CellIdentityCdma> &>(obj.cellIdentityCdma),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_2::CellIdentity, cellIdentityCdma), &_hidl_cellIdentityCdma_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.cellIdentityCdma.size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::radio::V1_2::CellIdentityCdma &>(obj.cellIdentityCdma[_hidl_index_0]),
                parcel,
                _hidl_cellIdentityCdma_child,
                _hidl_index_0 * sizeof(::android::hardware::radio::V1_2::CellIdentityCdma));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    size_t _hidl_cellIdentityLte_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::radio::V1_2::CellIdentityLte> &>(obj.cellIdentityLte),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_2::CellIdentity, cellIdentityLte), &_hidl_cellIdentityLte_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.cellIdentityLte.size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::radio::V1_2::CellIdentityLte &>(obj.cellIdentityLte[_hidl_index_0]),
                parcel,
                _hidl_cellIdentityLte_child,
                _hidl_index_0 * sizeof(::android::hardware::radio::V1_2::CellIdentityLte));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    size_t _hidl_cellIdentityTdscdma_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::radio::V1_2::CellIdentityTdscdma> &>(obj.cellIdentityTdscdma),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_2::CellIdentity, cellIdentityTdscdma), &_hidl_cellIdentityTdscdma_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.cellIdentityTdscdma.size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::radio::V1_2::CellIdentityTdscdma &>(obj.cellIdentityTdscdma[_hidl_index_0]),
                parcel,
                _hidl_cellIdentityTdscdma_child,
                _hidl_index_0 * sizeof(::android::hardware::radio::V1_2::CellIdentityTdscdma));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const CellIdentity &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_cellIdentityGsm_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.cellIdentityGsm,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_2::CellIdentity, cellIdentityGsm), &_hidl_cellIdentityGsm_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.cellIdentityGsm.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                obj.cellIdentityGsm[_hidl_index_0],
                parcel,
                _hidl_cellIdentityGsm_child,
                _hidl_index_0 * sizeof(::android::hardware::radio::V1_2::CellIdentityGsm));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    size_t _hidl_cellIdentityWcdma_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.cellIdentityWcdma,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_2::CellIdentity, cellIdentityWcdma), &_hidl_cellIdentityWcdma_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.cellIdentityWcdma.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                obj.cellIdentityWcdma[_hidl_index_0],
                parcel,
                _hidl_cellIdentityWcdma_child,
                _hidl_index_0 * sizeof(::android::hardware::radio::V1_2::CellIdentityWcdma));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    size_t _hidl_cellIdentityCdma_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.cellIdentityCdma,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_2::CellIdentity, cellIdentityCdma), &_hidl_cellIdentityCdma_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.cellIdentityCdma.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                obj.cellIdentityCdma[_hidl_index_0],
                parcel,
                _hidl_cellIdentityCdma_child,
                _hidl_index_0 * sizeof(::android::hardware::radio::V1_2::CellIdentityCdma));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    size_t _hidl_cellIdentityLte_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.cellIdentityLte,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_2::CellIdentity, cellIdentityLte), &_hidl_cellIdentityLte_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.cellIdentityLte.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                obj.cellIdentityLte[_hidl_index_0],
                parcel,
                _hidl_cellIdentityLte_child,
                _hidl_index_0 * sizeof(::android::hardware::radio::V1_2::CellIdentityLte));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    size_t _hidl_cellIdentityTdscdma_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.cellIdentityTdscdma,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_2::CellIdentity, cellIdentityTdscdma), &_hidl_cellIdentityTdscdma_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.cellIdentityTdscdma.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                obj.cellIdentityTdscdma[_hidl_index_0],
                parcel,
                _hidl_cellIdentityTdscdma_child,
                _hidl_index_0 * sizeof(::android::hardware::radio::V1_2::CellIdentityTdscdma));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const VoiceRegStateResult &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::radio::V1_2::CellIdentity &>(obj.cellIdentity),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_2::VoiceRegStateResult, cellIdentity));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const VoiceRegStateResult &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = writeEmbeddedToParcel(
            obj.cellIdentity,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_2::VoiceRegStateResult, cellIdentity));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const DataRegStateResult &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::radio::V1_2::CellIdentity &>(obj.cellIdentity),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_2::DataRegStateResult, cellIdentity));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const DataRegStateResult &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = writeEmbeddedToParcel(
            obj.cellIdentity,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_2::DataRegStateResult, cellIdentity));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

static_assert(sizeof(::android::hardware::MQDescriptor<char, ::android::hardware::kSynchronizedReadWrite>) == 32, "wrong size");
static_assert(sizeof(::android::hardware::hidl_handle) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_memory) == 40, "wrong size");
static_assert(sizeof(::android::hardware::hidl_string) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_vec<char>) == 16, "wrong size");

}  // namespace V1_2
}  // namespace radio
}  // namespace hardware
}  // namespace android
