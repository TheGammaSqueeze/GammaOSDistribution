#define LOG_TAG "android.hardware.radio@1.0::types"

#include <log/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <hidl/Static.h>
#include <hwbinder/ProcessState.h>
#include <utils/Trace.h>
#include <android/hardware/radio/1.0/types.h>
#include <android/hardware/radio/1.0/hwtypes.h>

namespace android {
namespace hardware {
namespace radio {
namespace V1_0 {

::android::status_t readEmbeddedFromParcel(
        const NeighboringCell &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.cid),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::NeighboringCell, cid));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const NeighboringCell &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.cid,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::NeighboringCell, cid));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const AppStatus &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.aidPtr),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::AppStatus, aidPtr));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.appLabelPtr),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::AppStatus, appLabelPtr));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const AppStatus &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.aidPtr,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::AppStatus, aidPtr));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.appLabelPtr,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::AppStatus, appLabelPtr));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const CardStatus &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_applications_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::radio::V1_0::AppStatus> &>(obj.applications),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::CardStatus, applications), &_hidl_applications_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.applications.size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::radio::V1_0::AppStatus &>(obj.applications[_hidl_index_0]),
                parcel,
                _hidl_applications_child,
                _hidl_index_0 * sizeof(::android::hardware::radio::V1_0::AppStatus));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const CardStatus &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_applications_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.applications,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::CardStatus, applications), &_hidl_applications_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.applications.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                obj.applications[_hidl_index_0],
                parcel,
                _hidl_applications_child,
                _hidl_index_0 * sizeof(::android::hardware::radio::V1_0::AppStatus));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const UusInfo &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.uusData),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::UusInfo, uusData));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const UusInfo &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.uusData,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::UusInfo, uusData));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const Call &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.number),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::Call, number));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.name),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::Call, name));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_uusInfo_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::radio::V1_0::UusInfo> &>(obj.uusInfo),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::Call, uusInfo), &_hidl_uusInfo_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.uusInfo.size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::radio::V1_0::UusInfo &>(obj.uusInfo[_hidl_index_0]),
                parcel,
                _hidl_uusInfo_child,
                _hidl_index_0 * sizeof(::android::hardware::radio::V1_0::UusInfo));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const Call &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.number,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::Call, number));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.name,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::Call, name));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_uusInfo_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.uusInfo,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::Call, uusInfo), &_hidl_uusInfo_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.uusInfo.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                obj.uusInfo[_hidl_index_0],
                parcel,
                _hidl_uusInfo_child,
                _hidl_index_0 * sizeof(::android::hardware::radio::V1_0::UusInfo));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const Dial &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.address),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::Dial, address));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_uusInfo_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::radio::V1_0::UusInfo> &>(obj.uusInfo),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::Dial, uusInfo), &_hidl_uusInfo_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.uusInfo.size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::radio::V1_0::UusInfo &>(obj.uusInfo[_hidl_index_0]),
                parcel,
                _hidl_uusInfo_child,
                _hidl_index_0 * sizeof(::android::hardware::radio::V1_0::UusInfo));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const Dial &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.address,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::Dial, address));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_uusInfo_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.uusInfo,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::Dial, uusInfo), &_hidl_uusInfo_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.uusInfo.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                obj.uusInfo[_hidl_index_0],
                parcel,
                _hidl_uusInfo_child,
                _hidl_index_0 * sizeof(::android::hardware::radio::V1_0::UusInfo));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const LastCallFailCauseInfo &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.vendorCause),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::LastCallFailCauseInfo, vendorCause));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const LastCallFailCauseInfo &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.vendorCause,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::LastCallFailCauseInfo, vendorCause));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const SendSmsResult &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.ackPDU),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::SendSmsResult, ackPDU));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const SendSmsResult &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.ackPDU,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::SendSmsResult, ackPDU));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const SetupDataCallResult &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.type),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::SetupDataCallResult, type));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.ifname),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::SetupDataCallResult, ifname));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.addresses),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::SetupDataCallResult, addresses));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.dnses),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::SetupDataCallResult, dnses));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.gateways),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::SetupDataCallResult, gateways));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.pcscf),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::SetupDataCallResult, pcscf));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const SetupDataCallResult &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.type,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::SetupDataCallResult, type));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.ifname,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::SetupDataCallResult, ifname));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.addresses,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::SetupDataCallResult, addresses));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.dnses,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::SetupDataCallResult, dnses));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.gateways,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::SetupDataCallResult, gateways));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.pcscf,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::SetupDataCallResult, pcscf));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const IccIo &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.path),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::IccIo, path));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.data),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::IccIo, data));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.pin2),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::IccIo, pin2));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.aid),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::IccIo, aid));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const IccIo &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.path,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::IccIo, path));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.data,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::IccIo, data));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.pin2,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::IccIo, pin2));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.aid,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::IccIo, aid));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const IccIoResult &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.simResponse),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::IccIoResult, simResponse));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const IccIoResult &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.simResponse,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::IccIoResult, simResponse));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const CallForwardInfo &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.number),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::CallForwardInfo, number));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const CallForwardInfo &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.number,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::CallForwardInfo, number));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const OperatorInfo &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.alphaLong),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::OperatorInfo, alphaLong));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.alphaShort),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::OperatorInfo, alphaShort));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.operatorNumeric),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::OperatorInfo, operatorNumeric));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const OperatorInfo &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.alphaLong,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::OperatorInfo, alphaLong));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.alphaShort,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::OperatorInfo, alphaShort));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.operatorNumeric,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::OperatorInfo, operatorNumeric));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const SmsWriteArgs &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.pdu),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::SmsWriteArgs, pdu));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.smsc),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::SmsWriteArgs, smsc));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const SmsWriteArgs &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.pdu,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::SmsWriteArgs, pdu));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.smsc,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::SmsWriteArgs, smsc));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const CdmaSmsAddress &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_digits_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(obj.digits),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::CdmaSmsAddress, digits), &_hidl_digits_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const CdmaSmsAddress &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_digits_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.digits,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::CdmaSmsAddress, digits), &_hidl_digits_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const CdmaSmsSubaddress &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_digits_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(obj.digits),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::CdmaSmsSubaddress, digits), &_hidl_digits_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const CdmaSmsSubaddress &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_digits_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.digits,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::CdmaSmsSubaddress, digits), &_hidl_digits_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const CdmaSmsMessage &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::radio::V1_0::CdmaSmsAddress &>(obj.address),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::CdmaSmsMessage, address));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::radio::V1_0::CdmaSmsSubaddress &>(obj.subAddress),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::CdmaSmsMessage, subAddress));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_bearerData_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(obj.bearerData),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::CdmaSmsMessage, bearerData), &_hidl_bearerData_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const CdmaSmsMessage &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = writeEmbeddedToParcel(
            obj.address,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::CdmaSmsMessage, address));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = writeEmbeddedToParcel(
            obj.subAddress,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::CdmaSmsMessage, subAddress));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_bearerData_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.bearerData,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::CdmaSmsMessage, bearerData), &_hidl_bearerData_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const CdmaSmsWriteArgs &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::radio::V1_0::CdmaSmsMessage &>(obj.message),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::CdmaSmsWriteArgs, message));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const CdmaSmsWriteArgs &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = writeEmbeddedToParcel(
            obj.message,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::CdmaSmsWriteArgs, message));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const CellIdentityGsm &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.mcc),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::CellIdentityGsm, mcc));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.mnc),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::CellIdentityGsm, mnc));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const CellIdentityGsm &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.mcc,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::CellIdentityGsm, mcc));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.mnc,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::CellIdentityGsm, mnc));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const CellIdentityWcdma &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.mcc),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::CellIdentityWcdma, mcc));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.mnc),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::CellIdentityWcdma, mnc));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const CellIdentityWcdma &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.mcc,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::CellIdentityWcdma, mcc));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.mnc,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::CellIdentityWcdma, mnc));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const CellIdentityLte &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.mcc),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::CellIdentityLte, mcc));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.mnc),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::CellIdentityLte, mnc));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const CellIdentityLte &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.mcc,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::CellIdentityLte, mcc));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.mnc,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::CellIdentityLte, mnc));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const CellIdentityTdscdma &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.mcc),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::CellIdentityTdscdma, mcc));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.mnc),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::CellIdentityTdscdma, mnc));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const CellIdentityTdscdma &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.mcc,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::CellIdentityTdscdma, mcc));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.mnc,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::CellIdentityTdscdma, mnc));

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
            const_cast<::android::hardware::radio::V1_0::CellIdentityGsm &>(obj.cellIdentityGsm),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::CellInfoGsm, cellIdentityGsm));

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
            parentOffset + offsetof(::android::hardware::radio::V1_0::CellInfoGsm, cellIdentityGsm));

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
            const_cast<::android::hardware::radio::V1_0::CellIdentityWcdma &>(obj.cellIdentityWcdma),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::CellInfoWcdma, cellIdentityWcdma));

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
            parentOffset + offsetof(::android::hardware::radio::V1_0::CellInfoWcdma, cellIdentityWcdma));

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
            const_cast<::android::hardware::radio::V1_0::CellIdentityLte &>(obj.cellIdentityLte),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::CellInfoLte, cellIdentityLte));

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
            parentOffset + offsetof(::android::hardware::radio::V1_0::CellInfoLte, cellIdentityLte));

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
            const_cast<::android::hardware::radio::V1_0::CellIdentityTdscdma &>(obj.cellIdentityTdscdma),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::CellInfoTdscdma, cellIdentityTdscdma));

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
            parentOffset + offsetof(::android::hardware::radio::V1_0::CellInfoTdscdma, cellIdentityTdscdma));

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
            const_cast<::android::hardware::hidl_vec<::android::hardware::radio::V1_0::CellInfoGsm> &>(obj.gsm),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::CellInfo, gsm), &_hidl_gsm_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.gsm.size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::radio::V1_0::CellInfoGsm &>(obj.gsm[_hidl_index_0]),
                parcel,
                _hidl_gsm_child,
                _hidl_index_0 * sizeof(::android::hardware::radio::V1_0::CellInfoGsm));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    size_t _hidl_cdma_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::radio::V1_0::CellInfoCdma> &>(obj.cdma),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::CellInfo, cdma), &_hidl_cdma_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_lte_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::radio::V1_0::CellInfoLte> &>(obj.lte),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::CellInfo, lte), &_hidl_lte_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.lte.size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::radio::V1_0::CellInfoLte &>(obj.lte[_hidl_index_0]),
                parcel,
                _hidl_lte_child,
                _hidl_index_0 * sizeof(::android::hardware::radio::V1_0::CellInfoLte));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    size_t _hidl_wcdma_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::radio::V1_0::CellInfoWcdma> &>(obj.wcdma),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::CellInfo, wcdma), &_hidl_wcdma_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.wcdma.size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::radio::V1_0::CellInfoWcdma &>(obj.wcdma[_hidl_index_0]),
                parcel,
                _hidl_wcdma_child,
                _hidl_index_0 * sizeof(::android::hardware::radio::V1_0::CellInfoWcdma));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    size_t _hidl_tdscdma_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::radio::V1_0::CellInfoTdscdma> &>(obj.tdscdma),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::CellInfo, tdscdma), &_hidl_tdscdma_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.tdscdma.size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::radio::V1_0::CellInfoTdscdma &>(obj.tdscdma[_hidl_index_0]),
                parcel,
                _hidl_tdscdma_child,
                _hidl_index_0 * sizeof(::android::hardware::radio::V1_0::CellInfoTdscdma));

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
            parentOffset + offsetof(::android::hardware::radio::V1_0::CellInfo, gsm), &_hidl_gsm_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.gsm.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                obj.gsm[_hidl_index_0],
                parcel,
                _hidl_gsm_child,
                _hidl_index_0 * sizeof(::android::hardware::radio::V1_0::CellInfoGsm));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    size_t _hidl_cdma_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.cdma,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::CellInfo, cdma), &_hidl_cdma_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_lte_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.lte,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::CellInfo, lte), &_hidl_lte_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.lte.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                obj.lte[_hidl_index_0],
                parcel,
                _hidl_lte_child,
                _hidl_index_0 * sizeof(::android::hardware::radio::V1_0::CellInfoLte));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    size_t _hidl_wcdma_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.wcdma,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::CellInfo, wcdma), &_hidl_wcdma_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.wcdma.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                obj.wcdma[_hidl_index_0],
                parcel,
                _hidl_wcdma_child,
                _hidl_index_0 * sizeof(::android::hardware::radio::V1_0::CellInfoWcdma));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    size_t _hidl_tdscdma_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.tdscdma,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::CellInfo, tdscdma), &_hidl_tdscdma_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.tdscdma.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                obj.tdscdma[_hidl_index_0],
                parcel,
                _hidl_tdscdma_child,
                _hidl_index_0 * sizeof(::android::hardware::radio::V1_0::CellInfoTdscdma));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

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
            const_cast<::android::hardware::hidl_vec<::android::hardware::radio::V1_0::CellIdentityGsm> &>(obj.cellIdentityGsm),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::CellIdentity, cellIdentityGsm), &_hidl_cellIdentityGsm_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.cellIdentityGsm.size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::radio::V1_0::CellIdentityGsm &>(obj.cellIdentityGsm[_hidl_index_0]),
                parcel,
                _hidl_cellIdentityGsm_child,
                _hidl_index_0 * sizeof(::android::hardware::radio::V1_0::CellIdentityGsm));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    size_t _hidl_cellIdentityWcdma_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::radio::V1_0::CellIdentityWcdma> &>(obj.cellIdentityWcdma),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::CellIdentity, cellIdentityWcdma), &_hidl_cellIdentityWcdma_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.cellIdentityWcdma.size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::radio::V1_0::CellIdentityWcdma &>(obj.cellIdentityWcdma[_hidl_index_0]),
                parcel,
                _hidl_cellIdentityWcdma_child,
                _hidl_index_0 * sizeof(::android::hardware::radio::V1_0::CellIdentityWcdma));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    size_t _hidl_cellIdentityCdma_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::radio::V1_0::CellIdentityCdma> &>(obj.cellIdentityCdma),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::CellIdentity, cellIdentityCdma), &_hidl_cellIdentityCdma_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_cellIdentityLte_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::radio::V1_0::CellIdentityLte> &>(obj.cellIdentityLte),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::CellIdentity, cellIdentityLte), &_hidl_cellIdentityLte_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.cellIdentityLte.size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::radio::V1_0::CellIdentityLte &>(obj.cellIdentityLte[_hidl_index_0]),
                parcel,
                _hidl_cellIdentityLte_child,
                _hidl_index_0 * sizeof(::android::hardware::radio::V1_0::CellIdentityLte));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    size_t _hidl_cellIdentityTdscdma_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::radio::V1_0::CellIdentityTdscdma> &>(obj.cellIdentityTdscdma),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::CellIdentity, cellIdentityTdscdma), &_hidl_cellIdentityTdscdma_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.cellIdentityTdscdma.size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::radio::V1_0::CellIdentityTdscdma &>(obj.cellIdentityTdscdma[_hidl_index_0]),
                parcel,
                _hidl_cellIdentityTdscdma_child,
                _hidl_index_0 * sizeof(::android::hardware::radio::V1_0::CellIdentityTdscdma));

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
            parentOffset + offsetof(::android::hardware::radio::V1_0::CellIdentity, cellIdentityGsm), &_hidl_cellIdentityGsm_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.cellIdentityGsm.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                obj.cellIdentityGsm[_hidl_index_0],
                parcel,
                _hidl_cellIdentityGsm_child,
                _hidl_index_0 * sizeof(::android::hardware::radio::V1_0::CellIdentityGsm));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    size_t _hidl_cellIdentityWcdma_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.cellIdentityWcdma,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::CellIdentity, cellIdentityWcdma), &_hidl_cellIdentityWcdma_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.cellIdentityWcdma.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                obj.cellIdentityWcdma[_hidl_index_0],
                parcel,
                _hidl_cellIdentityWcdma_child,
                _hidl_index_0 * sizeof(::android::hardware::radio::V1_0::CellIdentityWcdma));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    size_t _hidl_cellIdentityCdma_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.cellIdentityCdma,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::CellIdentity, cellIdentityCdma), &_hidl_cellIdentityCdma_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_cellIdentityLte_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.cellIdentityLte,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::CellIdentity, cellIdentityLte), &_hidl_cellIdentityLte_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.cellIdentityLte.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                obj.cellIdentityLte[_hidl_index_0],
                parcel,
                _hidl_cellIdentityLte_child,
                _hidl_index_0 * sizeof(::android::hardware::radio::V1_0::CellIdentityLte));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    size_t _hidl_cellIdentityTdscdma_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.cellIdentityTdscdma,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::CellIdentity, cellIdentityTdscdma), &_hidl_cellIdentityTdscdma_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.cellIdentityTdscdma.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                obj.cellIdentityTdscdma[_hidl_index_0],
                parcel,
                _hidl_cellIdentityTdscdma_child,
                _hidl_index_0 * sizeof(::android::hardware::radio::V1_0::CellIdentityTdscdma));

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
            const_cast<::android::hardware::radio::V1_0::CellIdentity &>(obj.cellIdentity),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::VoiceRegStateResult, cellIdentity));

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
            parentOffset + offsetof(::android::hardware::radio::V1_0::VoiceRegStateResult, cellIdentity));

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
            const_cast<::android::hardware::radio::V1_0::CellIdentity &>(obj.cellIdentity),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::DataRegStateResult, cellIdentity));

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
            parentOffset + offsetof(::android::hardware::radio::V1_0::DataRegStateResult, cellIdentity));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const GsmSmsMessage &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.smscPdu),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::GsmSmsMessage, smscPdu));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.pdu),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::GsmSmsMessage, pdu));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const GsmSmsMessage &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.smscPdu,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::GsmSmsMessage, smscPdu));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.pdu,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::GsmSmsMessage, pdu));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const ImsSmsMessage &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_cdmaMessage_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::radio::V1_0::CdmaSmsMessage> &>(obj.cdmaMessage),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::ImsSmsMessage, cdmaMessage), &_hidl_cdmaMessage_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.cdmaMessage.size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::radio::V1_0::CdmaSmsMessage &>(obj.cdmaMessage[_hidl_index_0]),
                parcel,
                _hidl_cdmaMessage_child,
                _hidl_index_0 * sizeof(::android::hardware::radio::V1_0::CdmaSmsMessage));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    size_t _hidl_gsmMessage_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::radio::V1_0::GsmSmsMessage> &>(obj.gsmMessage),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::ImsSmsMessage, gsmMessage), &_hidl_gsmMessage_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.gsmMessage.size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::radio::V1_0::GsmSmsMessage &>(obj.gsmMessage[_hidl_index_0]),
                parcel,
                _hidl_gsmMessage_child,
                _hidl_index_0 * sizeof(::android::hardware::radio::V1_0::GsmSmsMessage));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const ImsSmsMessage &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_cdmaMessage_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.cdmaMessage,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::ImsSmsMessage, cdmaMessage), &_hidl_cdmaMessage_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.cdmaMessage.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                obj.cdmaMessage[_hidl_index_0],
                parcel,
                _hidl_cdmaMessage_child,
                _hidl_index_0 * sizeof(::android::hardware::radio::V1_0::CdmaSmsMessage));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    size_t _hidl_gsmMessage_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.gsmMessage,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::ImsSmsMessage, gsmMessage), &_hidl_gsmMessage_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.gsmMessage.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                obj.gsmMessage[_hidl_index_0],
                parcel,
                _hidl_gsmMessage_child,
                _hidl_index_0 * sizeof(::android::hardware::radio::V1_0::GsmSmsMessage));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const SimApdu &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.data),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::SimApdu, data));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const SimApdu &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.data,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::SimApdu, data));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const NvWriteItem &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.value),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::NvWriteItem, value));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const NvWriteItem &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.value,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::NvWriteItem, value));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const HardwareConfigSim &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.modemUuid),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::HardwareConfigSim, modemUuid));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const HardwareConfigSim &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.modemUuid,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::HardwareConfigSim, modemUuid));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const HardwareConfig &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.uuid),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::HardwareConfig, uuid));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_modem_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::radio::V1_0::HardwareConfigModem> &>(obj.modem),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::HardwareConfig, modem), &_hidl_modem_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_sim_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::radio::V1_0::HardwareConfigSim> &>(obj.sim),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::HardwareConfig, sim), &_hidl_sim_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.sim.size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::radio::V1_0::HardwareConfigSim &>(obj.sim[_hidl_index_0]),
                parcel,
                _hidl_sim_child,
                _hidl_index_0 * sizeof(::android::hardware::radio::V1_0::HardwareConfigSim));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const HardwareConfig &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.uuid,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::HardwareConfig, uuid));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_modem_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.modem,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::HardwareConfig, modem), &_hidl_modem_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_sim_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.sim,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::HardwareConfig, sim), &_hidl_sim_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.sim.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                obj.sim[_hidl_index_0],
                parcel,
                _hidl_sim_child,
                _hidl_index_0 * sizeof(::android::hardware::radio::V1_0::HardwareConfigSim));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const DataProfileInfo &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.apn),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::DataProfileInfo, apn));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.protocol),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::DataProfileInfo, protocol));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.roamingProtocol),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::DataProfileInfo, roamingProtocol));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.user),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::DataProfileInfo, user));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.password),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::DataProfileInfo, password));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.mvnoMatchData),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::DataProfileInfo, mvnoMatchData));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const DataProfileInfo &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.apn,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::DataProfileInfo, apn));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.protocol,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::DataProfileInfo, protocol));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.roamingProtocol,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::DataProfileInfo, roamingProtocol));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.user,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::DataProfileInfo, user));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.password,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::DataProfileInfo, password));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.mvnoMatchData,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::DataProfileInfo, mvnoMatchData));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const RadioCapability &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.logicalModemUuid),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::RadioCapability, logicalModemUuid));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const RadioCapability &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.logicalModemUuid,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::RadioCapability, logicalModemUuid));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const Carrier &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.mcc),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::Carrier, mcc));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.mnc),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::Carrier, mnc));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.matchData),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::Carrier, matchData));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const Carrier &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.mcc,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::Carrier, mcc));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.mnc,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::Carrier, mnc));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.matchData,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::Carrier, matchData));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const CarrierRestrictions &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_allowedCarriers_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::radio::V1_0::Carrier> &>(obj.allowedCarriers),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::CarrierRestrictions, allowedCarriers), &_hidl_allowedCarriers_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.allowedCarriers.size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::radio::V1_0::Carrier &>(obj.allowedCarriers[_hidl_index_0]),
                parcel,
                _hidl_allowedCarriers_child,
                _hidl_index_0 * sizeof(::android::hardware::radio::V1_0::Carrier));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    size_t _hidl_excludedCarriers_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::radio::V1_0::Carrier> &>(obj.excludedCarriers),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::CarrierRestrictions, excludedCarriers), &_hidl_excludedCarriers_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.excludedCarriers.size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::radio::V1_0::Carrier &>(obj.excludedCarriers[_hidl_index_0]),
                parcel,
                _hidl_excludedCarriers_child,
                _hidl_index_0 * sizeof(::android::hardware::radio::V1_0::Carrier));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const CarrierRestrictions &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_allowedCarriers_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.allowedCarriers,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::CarrierRestrictions, allowedCarriers), &_hidl_allowedCarriers_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.allowedCarriers.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                obj.allowedCarriers[_hidl_index_0],
                parcel,
                _hidl_allowedCarriers_child,
                _hidl_index_0 * sizeof(::android::hardware::radio::V1_0::Carrier));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    size_t _hidl_excludedCarriers_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.excludedCarriers,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::CarrierRestrictions, excludedCarriers), &_hidl_excludedCarriers_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.excludedCarriers.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                obj.excludedCarriers[_hidl_index_0],
                parcel,
                _hidl_excludedCarriers_child,
                _hidl_index_0 * sizeof(::android::hardware::radio::V1_0::Carrier));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const SuppSvcNotification &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.number),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::SuppSvcNotification, number));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const SuppSvcNotification &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.number,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::SuppSvcNotification, number));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const SimRefreshResult &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.aid),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::SimRefreshResult, aid));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const SimRefreshResult &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.aid,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::SimRefreshResult, aid));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const CdmaCallWaiting &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.number),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::CdmaCallWaiting, number));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.name),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::CdmaCallWaiting, name));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const CdmaCallWaiting &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.number,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::CdmaCallWaiting, number));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.name,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::CdmaCallWaiting, name));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const CdmaDisplayInfoRecord &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.alphaBuf),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::CdmaDisplayInfoRecord, alphaBuf));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const CdmaDisplayInfoRecord &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.alphaBuf,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::CdmaDisplayInfoRecord, alphaBuf));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const CdmaNumberInfoRecord &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.number),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::CdmaNumberInfoRecord, number));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const CdmaNumberInfoRecord &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.number,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::CdmaNumberInfoRecord, number));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const CdmaRedirectingNumberInfoRecord &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::radio::V1_0::CdmaNumberInfoRecord &>(obj.redirectingNumber),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::CdmaRedirectingNumberInfoRecord, redirectingNumber));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const CdmaRedirectingNumberInfoRecord &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = writeEmbeddedToParcel(
            obj.redirectingNumber,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::CdmaRedirectingNumberInfoRecord, redirectingNumber));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const CdmaInformationRecord &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_display_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::radio::V1_0::CdmaDisplayInfoRecord> &>(obj.display),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::CdmaInformationRecord, display), &_hidl_display_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.display.size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::radio::V1_0::CdmaDisplayInfoRecord &>(obj.display[_hidl_index_0]),
                parcel,
                _hidl_display_child,
                _hidl_index_0 * sizeof(::android::hardware::radio::V1_0::CdmaDisplayInfoRecord));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    size_t _hidl_number_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::radio::V1_0::CdmaNumberInfoRecord> &>(obj.number),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::CdmaInformationRecord, number), &_hidl_number_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.number.size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::radio::V1_0::CdmaNumberInfoRecord &>(obj.number[_hidl_index_0]),
                parcel,
                _hidl_number_child,
                _hidl_index_0 * sizeof(::android::hardware::radio::V1_0::CdmaNumberInfoRecord));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    size_t _hidl_signal_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::radio::V1_0::CdmaSignalInfoRecord> &>(obj.signal),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::CdmaInformationRecord, signal), &_hidl_signal_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_redir_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::radio::V1_0::CdmaRedirectingNumberInfoRecord> &>(obj.redir),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::CdmaInformationRecord, redir), &_hidl_redir_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.redir.size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::radio::V1_0::CdmaRedirectingNumberInfoRecord &>(obj.redir[_hidl_index_0]),
                parcel,
                _hidl_redir_child,
                _hidl_index_0 * sizeof(::android::hardware::radio::V1_0::CdmaRedirectingNumberInfoRecord));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    size_t _hidl_lineCtrl_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::radio::V1_0::CdmaLineControlInfoRecord> &>(obj.lineCtrl),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::CdmaInformationRecord, lineCtrl), &_hidl_lineCtrl_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_clir_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::radio::V1_0::CdmaT53ClirInfoRecord> &>(obj.clir),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::CdmaInformationRecord, clir), &_hidl_clir_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_audioCtrl_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::radio::V1_0::CdmaT53AudioControlInfoRecord> &>(obj.audioCtrl),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::CdmaInformationRecord, audioCtrl), &_hidl_audioCtrl_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const CdmaInformationRecord &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_display_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.display,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::CdmaInformationRecord, display), &_hidl_display_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.display.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                obj.display[_hidl_index_0],
                parcel,
                _hidl_display_child,
                _hidl_index_0 * sizeof(::android::hardware::radio::V1_0::CdmaDisplayInfoRecord));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    size_t _hidl_number_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.number,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::CdmaInformationRecord, number), &_hidl_number_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.number.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                obj.number[_hidl_index_0],
                parcel,
                _hidl_number_child,
                _hidl_index_0 * sizeof(::android::hardware::radio::V1_0::CdmaNumberInfoRecord));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    size_t _hidl_signal_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.signal,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::CdmaInformationRecord, signal), &_hidl_signal_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_redir_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.redir,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::CdmaInformationRecord, redir), &_hidl_redir_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.redir.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                obj.redir[_hidl_index_0],
                parcel,
                _hidl_redir_child,
                _hidl_index_0 * sizeof(::android::hardware::radio::V1_0::CdmaRedirectingNumberInfoRecord));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    size_t _hidl_lineCtrl_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.lineCtrl,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::CdmaInformationRecord, lineCtrl), &_hidl_lineCtrl_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_clir_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.clir,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::CdmaInformationRecord, clir), &_hidl_clir_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_audioCtrl_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.audioCtrl,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::CdmaInformationRecord, audioCtrl), &_hidl_audioCtrl_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const CdmaInformationRecords &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_infoRec_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::radio::V1_0::CdmaInformationRecord> &>(obj.infoRec),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::CdmaInformationRecords, infoRec), &_hidl_infoRec_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.infoRec.size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::radio::V1_0::CdmaInformationRecord &>(obj.infoRec[_hidl_index_0]),
                parcel,
                _hidl_infoRec_child,
                _hidl_index_0 * sizeof(::android::hardware::radio::V1_0::CdmaInformationRecord));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const CdmaInformationRecords &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_infoRec_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.infoRec,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::CdmaInformationRecords, infoRec), &_hidl_infoRec_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.infoRec.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                obj.infoRec[_hidl_index_0],
                parcel,
                _hidl_infoRec_child,
                _hidl_index_0 * sizeof(::android::hardware::radio::V1_0::CdmaInformationRecord));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const CfData &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_cfInfo_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::radio::V1_0::CallForwardInfo> &>(obj.cfInfo),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::CfData, cfInfo), &_hidl_cfInfo_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.cfInfo.size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::radio::V1_0::CallForwardInfo &>(obj.cfInfo[_hidl_index_0]),
                parcel,
                _hidl_cfInfo_child,
                _hidl_index_0 * sizeof(::android::hardware::radio::V1_0::CallForwardInfo));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const CfData &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_cfInfo_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.cfInfo,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::CfData, cfInfo), &_hidl_cfInfo_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.cfInfo.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                obj.cfInfo[_hidl_index_0],
                parcel,
                _hidl_cfInfo_child,
                _hidl_index_0 * sizeof(::android::hardware::radio::V1_0::CallForwardInfo));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const SsInfoData &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_ssInfo_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<int32_t> &>(obj.ssInfo),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::SsInfoData, ssInfo), &_hidl_ssInfo_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const SsInfoData &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_ssInfo_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.ssInfo,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::SsInfoData, ssInfo), &_hidl_ssInfo_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const StkCcUnsolSsResult &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_ssInfo_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::radio::V1_0::SsInfoData> &>(obj.ssInfo),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::StkCcUnsolSsResult, ssInfo), &_hidl_ssInfo_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.ssInfo.size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::radio::V1_0::SsInfoData &>(obj.ssInfo[_hidl_index_0]),
                parcel,
                _hidl_ssInfo_child,
                _hidl_index_0 * sizeof(::android::hardware::radio::V1_0::SsInfoData));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    size_t _hidl_cfData_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::radio::V1_0::CfData> &>(obj.cfData),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::StkCcUnsolSsResult, cfData), &_hidl_cfData_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.cfData.size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::radio::V1_0::CfData &>(obj.cfData[_hidl_index_0]),
                parcel,
                _hidl_cfData_child,
                _hidl_index_0 * sizeof(::android::hardware::radio::V1_0::CfData));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const StkCcUnsolSsResult &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_ssInfo_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.ssInfo,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::StkCcUnsolSsResult, ssInfo), &_hidl_ssInfo_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.ssInfo.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                obj.ssInfo[_hidl_index_0],
                parcel,
                _hidl_ssInfo_child,
                _hidl_index_0 * sizeof(::android::hardware::radio::V1_0::SsInfoData));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    size_t _hidl_cfData_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.cfData,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::StkCcUnsolSsResult, cfData), &_hidl_cfData_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.cfData.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                obj.cfData[_hidl_index_0],
                parcel,
                _hidl_cfData_child,
                _hidl_index_0 * sizeof(::android::hardware::radio::V1_0::CfData));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const PcoDataInfo &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.bearerProto),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::PcoDataInfo, bearerProto));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_contents_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(obj.contents),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::PcoDataInfo, contents), &_hidl_contents_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const PcoDataInfo &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.bearerProto,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::PcoDataInfo, bearerProto));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_contents_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.contents,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_0::PcoDataInfo, contents), &_hidl_contents_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

static_assert(sizeof(::android::hardware::MQDescriptor<char, ::android::hardware::kSynchronizedReadWrite>) == 32, "wrong size");
static_assert(sizeof(::android::hardware::hidl_handle) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_memory) == 40, "wrong size");
static_assert(sizeof(::android::hardware::hidl_string) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_vec<char>) == 16, "wrong size");

}  // namespace V1_0
}  // namespace radio
}  // namespace hardware
}  // namespace android
