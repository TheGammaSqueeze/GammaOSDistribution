#define LOG_TAG "android.hardware.wifi@1.0::types"

#include <log/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <hidl/Static.h>
#include <hwbinder/ProcessState.h>
#include <utils/Trace.h>
#include <android/hardware/wifi/1.0/types.h>
#include <android/hardware/wifi/1.0/hwtypes.h>

namespace android {
namespace hardware {
namespace wifi {
namespace V1_0 {

::android::status_t readEmbeddedFromParcel(
        const WifiStatus &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.description),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::wifi::V1_0::WifiStatus, description));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const WifiStatus &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.description,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::wifi::V1_0::WifiStatus, description));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const WifiInformationElement &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_data_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(obj.data),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::wifi::V1_0::WifiInformationElement, data), &_hidl_data_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const WifiInformationElement &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_data_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.data,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::wifi::V1_0::WifiInformationElement, data), &_hidl_data_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const StaBackgroundScanBucketParameters &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_frequencies_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint32_t> &>(obj.frequencies),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::wifi::V1_0::StaBackgroundScanBucketParameters, frequencies), &_hidl_frequencies_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const StaBackgroundScanBucketParameters &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_frequencies_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.frequencies,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::wifi::V1_0::StaBackgroundScanBucketParameters, frequencies), &_hidl_frequencies_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const StaBackgroundScanParameters &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_buckets_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::wifi::V1_0::StaBackgroundScanBucketParameters> &>(obj.buckets),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::wifi::V1_0::StaBackgroundScanParameters, buckets), &_hidl_buckets_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.buckets.size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::wifi::V1_0::StaBackgroundScanBucketParameters &>(obj.buckets[_hidl_index_0]),
                parcel,
                _hidl_buckets_child,
                _hidl_index_0 * sizeof(::android::hardware::wifi::V1_0::StaBackgroundScanBucketParameters));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const StaBackgroundScanParameters &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_buckets_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.buckets,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::wifi::V1_0::StaBackgroundScanParameters, buckets), &_hidl_buckets_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.buckets.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                obj.buckets[_hidl_index_0],
                parcel,
                _hidl_buckets_child,
                _hidl_index_0 * sizeof(::android::hardware::wifi::V1_0::StaBackgroundScanBucketParameters));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const StaLinkLayerRadioStats &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_txTimeInMsPerLevel_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint32_t> &>(obj.txTimeInMsPerLevel),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::wifi::V1_0::StaLinkLayerRadioStats, txTimeInMsPerLevel), &_hidl_txTimeInMsPerLevel_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const StaLinkLayerRadioStats &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_txTimeInMsPerLevel_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.txTimeInMsPerLevel,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::wifi::V1_0::StaLinkLayerRadioStats, txTimeInMsPerLevel), &_hidl_txTimeInMsPerLevel_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const StaLinkLayerStats &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_radios_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::wifi::V1_0::StaLinkLayerRadioStats> &>(obj.radios),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::wifi::V1_0::StaLinkLayerStats, radios), &_hidl_radios_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.radios.size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::wifi::V1_0::StaLinkLayerRadioStats &>(obj.radios[_hidl_index_0]),
                parcel,
                _hidl_radios_child,
                _hidl_index_0 * sizeof(::android::hardware::wifi::V1_0::StaLinkLayerRadioStats));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const StaLinkLayerStats &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_radios_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.radios,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::wifi::V1_0::StaLinkLayerStats, radios), &_hidl_radios_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.radios.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                obj.radios[_hidl_index_0],
                parcel,
                _hidl_radios_child,
                _hidl_index_0 * sizeof(::android::hardware::wifi::V1_0::StaLinkLayerRadioStats));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const StaScanResult &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_ssid_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(obj.ssid),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::wifi::V1_0::StaScanResult, ssid), &_hidl_ssid_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_informationElements_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::wifi::V1_0::WifiInformationElement> &>(obj.informationElements),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::wifi::V1_0::StaScanResult, informationElements), &_hidl_informationElements_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.informationElements.size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::wifi::V1_0::WifiInformationElement &>(obj.informationElements[_hidl_index_0]),
                parcel,
                _hidl_informationElements_child,
                _hidl_index_0 * sizeof(::android::hardware::wifi::V1_0::WifiInformationElement));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const StaScanResult &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_ssid_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.ssid,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::wifi::V1_0::StaScanResult, ssid), &_hidl_ssid_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_informationElements_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.informationElements,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::wifi::V1_0::StaScanResult, informationElements), &_hidl_informationElements_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.informationElements.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                obj.informationElements[_hidl_index_0],
                parcel,
                _hidl_informationElements_child,
                _hidl_index_0 * sizeof(::android::hardware::wifi::V1_0::WifiInformationElement));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const StaScanData &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_results_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::wifi::V1_0::StaScanResult> &>(obj.results),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::wifi::V1_0::StaScanData, results), &_hidl_results_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.results.size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::wifi::V1_0::StaScanResult &>(obj.results[_hidl_index_0]),
                parcel,
                _hidl_results_child,
                _hidl_index_0 * sizeof(::android::hardware::wifi::V1_0::StaScanResult));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const StaScanData &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_results_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.results,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::wifi::V1_0::StaScanData, results), &_hidl_results_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.results.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                obj.results[_hidl_index_0],
                parcel,
                _hidl_results_child,
                _hidl_index_0 * sizeof(::android::hardware::wifi::V1_0::StaScanResult));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const StaRoamingConfig &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_bssidBlacklist_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::hidl_array<uint8_t, 6>> &>(obj.bssidBlacklist),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::wifi::V1_0::StaRoamingConfig, bssidBlacklist), &_hidl_bssidBlacklist_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_ssidWhitelist_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::hidl_array<uint8_t, 32>> &>(obj.ssidWhitelist),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::wifi::V1_0::StaRoamingConfig, ssidWhitelist), &_hidl_ssidWhitelist_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const StaRoamingConfig &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_bssidBlacklist_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.bssidBlacklist,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::wifi::V1_0::StaRoamingConfig, bssidBlacklist), &_hidl_bssidBlacklist_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_ssidWhitelist_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.ssidWhitelist,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::wifi::V1_0::StaRoamingConfig, ssidWhitelist), &_hidl_ssidWhitelist_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const WifiNanStatus &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.description),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::wifi::V1_0::WifiNanStatus, description));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const WifiNanStatus &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.description,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::wifi::V1_0::WifiNanStatus, description));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const NanDataPathSecurityConfig &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_passphrase_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(obj.passphrase),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::wifi::V1_0::NanDataPathSecurityConfig, passphrase), &_hidl_passphrase_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const NanDataPathSecurityConfig &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_passphrase_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.passphrase,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::wifi::V1_0::NanDataPathSecurityConfig, passphrase), &_hidl_passphrase_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const NanDiscoveryCommonConfig &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_serviceName_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(obj.serviceName),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::wifi::V1_0::NanDiscoveryCommonConfig, serviceName), &_hidl_serviceName_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_serviceSpecificInfo_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(obj.serviceSpecificInfo),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::wifi::V1_0::NanDiscoveryCommonConfig, serviceSpecificInfo), &_hidl_serviceSpecificInfo_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_extendedServiceSpecificInfo_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(obj.extendedServiceSpecificInfo),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::wifi::V1_0::NanDiscoveryCommonConfig, extendedServiceSpecificInfo), &_hidl_extendedServiceSpecificInfo_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_rxMatchFilter_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(obj.rxMatchFilter),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::wifi::V1_0::NanDiscoveryCommonConfig, rxMatchFilter), &_hidl_rxMatchFilter_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_txMatchFilter_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(obj.txMatchFilter),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::wifi::V1_0::NanDiscoveryCommonConfig, txMatchFilter), &_hidl_txMatchFilter_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::wifi::V1_0::NanDataPathSecurityConfig &>(obj.securityConfig),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::wifi::V1_0::NanDiscoveryCommonConfig, securityConfig));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const NanDiscoveryCommonConfig &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_serviceName_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.serviceName,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::wifi::V1_0::NanDiscoveryCommonConfig, serviceName), &_hidl_serviceName_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_serviceSpecificInfo_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.serviceSpecificInfo,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::wifi::V1_0::NanDiscoveryCommonConfig, serviceSpecificInfo), &_hidl_serviceSpecificInfo_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_extendedServiceSpecificInfo_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.extendedServiceSpecificInfo,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::wifi::V1_0::NanDiscoveryCommonConfig, extendedServiceSpecificInfo), &_hidl_extendedServiceSpecificInfo_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_rxMatchFilter_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.rxMatchFilter,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::wifi::V1_0::NanDiscoveryCommonConfig, rxMatchFilter), &_hidl_rxMatchFilter_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_txMatchFilter_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.txMatchFilter,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::wifi::V1_0::NanDiscoveryCommonConfig, txMatchFilter), &_hidl_txMatchFilter_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = writeEmbeddedToParcel(
            obj.securityConfig,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::wifi::V1_0::NanDiscoveryCommonConfig, securityConfig));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const NanPublishRequest &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::wifi::V1_0::NanDiscoveryCommonConfig &>(obj.baseConfigs),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::wifi::V1_0::NanPublishRequest, baseConfigs));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const NanPublishRequest &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = writeEmbeddedToParcel(
            obj.baseConfigs,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::wifi::V1_0::NanPublishRequest, baseConfigs));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const NanSubscribeRequest &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::wifi::V1_0::NanDiscoveryCommonConfig &>(obj.baseConfigs),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::wifi::V1_0::NanSubscribeRequest, baseConfigs));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_intfAddr_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::hidl_array<uint8_t, 6>> &>(obj.intfAddr),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::wifi::V1_0::NanSubscribeRequest, intfAddr), &_hidl_intfAddr_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const NanSubscribeRequest &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = writeEmbeddedToParcel(
            obj.baseConfigs,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::wifi::V1_0::NanSubscribeRequest, baseConfigs));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_intfAddr_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.intfAddr,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::wifi::V1_0::NanSubscribeRequest, intfAddr), &_hidl_intfAddr_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const NanTransmitFollowupRequest &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_serviceSpecificInfo_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(obj.serviceSpecificInfo),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::wifi::V1_0::NanTransmitFollowupRequest, serviceSpecificInfo), &_hidl_serviceSpecificInfo_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_extendedServiceSpecificInfo_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(obj.extendedServiceSpecificInfo),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::wifi::V1_0::NanTransmitFollowupRequest, extendedServiceSpecificInfo), &_hidl_extendedServiceSpecificInfo_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const NanTransmitFollowupRequest &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_serviceSpecificInfo_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.serviceSpecificInfo,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::wifi::V1_0::NanTransmitFollowupRequest, serviceSpecificInfo), &_hidl_serviceSpecificInfo_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_extendedServiceSpecificInfo_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.extendedServiceSpecificInfo,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::wifi::V1_0::NanTransmitFollowupRequest, extendedServiceSpecificInfo), &_hidl_extendedServiceSpecificInfo_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const NanInitiateDataPathRequest &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.ifaceName),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::wifi::V1_0::NanInitiateDataPathRequest, ifaceName));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::wifi::V1_0::NanDataPathSecurityConfig &>(obj.securityConfig),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::wifi::V1_0::NanInitiateDataPathRequest, securityConfig));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_appInfo_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(obj.appInfo),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::wifi::V1_0::NanInitiateDataPathRequest, appInfo), &_hidl_appInfo_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_serviceNameOutOfBand_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(obj.serviceNameOutOfBand),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::wifi::V1_0::NanInitiateDataPathRequest, serviceNameOutOfBand), &_hidl_serviceNameOutOfBand_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const NanInitiateDataPathRequest &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.ifaceName,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::wifi::V1_0::NanInitiateDataPathRequest, ifaceName));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = writeEmbeddedToParcel(
            obj.securityConfig,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::wifi::V1_0::NanInitiateDataPathRequest, securityConfig));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_appInfo_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.appInfo,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::wifi::V1_0::NanInitiateDataPathRequest, appInfo), &_hidl_appInfo_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_serviceNameOutOfBand_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.serviceNameOutOfBand,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::wifi::V1_0::NanInitiateDataPathRequest, serviceNameOutOfBand), &_hidl_serviceNameOutOfBand_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const NanRespondToDataPathIndicationRequest &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.ifaceName),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::wifi::V1_0::NanRespondToDataPathIndicationRequest, ifaceName));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::wifi::V1_0::NanDataPathSecurityConfig &>(obj.securityConfig),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::wifi::V1_0::NanRespondToDataPathIndicationRequest, securityConfig));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_appInfo_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(obj.appInfo),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::wifi::V1_0::NanRespondToDataPathIndicationRequest, appInfo), &_hidl_appInfo_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_serviceNameOutOfBand_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(obj.serviceNameOutOfBand),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::wifi::V1_0::NanRespondToDataPathIndicationRequest, serviceNameOutOfBand), &_hidl_serviceNameOutOfBand_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const NanRespondToDataPathIndicationRequest &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.ifaceName,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::wifi::V1_0::NanRespondToDataPathIndicationRequest, ifaceName));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = writeEmbeddedToParcel(
            obj.securityConfig,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::wifi::V1_0::NanRespondToDataPathIndicationRequest, securityConfig));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_appInfo_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.appInfo,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::wifi::V1_0::NanRespondToDataPathIndicationRequest, appInfo), &_hidl_appInfo_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_serviceNameOutOfBand_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.serviceNameOutOfBand,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::wifi::V1_0::NanRespondToDataPathIndicationRequest, serviceNameOutOfBand), &_hidl_serviceNameOutOfBand_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const NanMatchInd &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_serviceSpecificInfo_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(obj.serviceSpecificInfo),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::wifi::V1_0::NanMatchInd, serviceSpecificInfo), &_hidl_serviceSpecificInfo_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_extendedServiceSpecificInfo_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(obj.extendedServiceSpecificInfo),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::wifi::V1_0::NanMatchInd, extendedServiceSpecificInfo), &_hidl_extendedServiceSpecificInfo_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_matchFilter_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(obj.matchFilter),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::wifi::V1_0::NanMatchInd, matchFilter), &_hidl_matchFilter_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const NanMatchInd &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_serviceSpecificInfo_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.serviceSpecificInfo,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::wifi::V1_0::NanMatchInd, serviceSpecificInfo), &_hidl_serviceSpecificInfo_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_extendedServiceSpecificInfo_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.extendedServiceSpecificInfo,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::wifi::V1_0::NanMatchInd, extendedServiceSpecificInfo), &_hidl_extendedServiceSpecificInfo_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_matchFilter_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.matchFilter,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::wifi::V1_0::NanMatchInd, matchFilter), &_hidl_matchFilter_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const NanFollowupReceivedInd &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_serviceSpecificInfo_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(obj.serviceSpecificInfo),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::wifi::V1_0::NanFollowupReceivedInd, serviceSpecificInfo), &_hidl_serviceSpecificInfo_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_extendedServiceSpecificInfo_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(obj.extendedServiceSpecificInfo),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::wifi::V1_0::NanFollowupReceivedInd, extendedServiceSpecificInfo), &_hidl_extendedServiceSpecificInfo_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const NanFollowupReceivedInd &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_serviceSpecificInfo_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.serviceSpecificInfo,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::wifi::V1_0::NanFollowupReceivedInd, serviceSpecificInfo), &_hidl_serviceSpecificInfo_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_extendedServiceSpecificInfo_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.extendedServiceSpecificInfo,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::wifi::V1_0::NanFollowupReceivedInd, extendedServiceSpecificInfo), &_hidl_extendedServiceSpecificInfo_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const NanDataPathRequestInd &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_appInfo_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(obj.appInfo),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::wifi::V1_0::NanDataPathRequestInd, appInfo), &_hidl_appInfo_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const NanDataPathRequestInd &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_appInfo_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.appInfo,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::wifi::V1_0::NanDataPathRequestInd, appInfo), &_hidl_appInfo_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const NanDataPathConfirmInd &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_appInfo_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(obj.appInfo),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::wifi::V1_0::NanDataPathConfirmInd, appInfo), &_hidl_appInfo_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::wifi::V1_0::WifiNanStatus &>(obj.status),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::wifi::V1_0::NanDataPathConfirmInd, status));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const NanDataPathConfirmInd &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_appInfo_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.appInfo,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::wifi::V1_0::NanDataPathConfirmInd, appInfo), &_hidl_appInfo_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = writeEmbeddedToParcel(
            obj.status,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::wifi::V1_0::NanDataPathConfirmInd, status));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const RttResult &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::wifi::V1_0::WifiInformationElement &>(obj.lci),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::wifi::V1_0::RttResult, lci));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::wifi::V1_0::WifiInformationElement &>(obj.lcr),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::wifi::V1_0::RttResult, lcr));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const RttResult &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = writeEmbeddedToParcel(
            obj.lci,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::wifi::V1_0::RttResult, lci));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = writeEmbeddedToParcel(
            obj.lcr,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::wifi::V1_0::RttResult, lcr));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const RttLcrInformation &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.civicInfo),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::wifi::V1_0::RttLcrInformation, civicInfo));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const RttLcrInformation &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.civicInfo,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::wifi::V1_0::RttLcrInformation, civicInfo));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const WifiDebugRingBufferStatus &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.ringName),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::wifi::V1_0::WifiDebugRingBufferStatus, ringName));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const WifiDebugRingBufferStatus &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.ringName,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::wifi::V1_0::WifiDebugRingBufferStatus, ringName));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const WifiDebugPacketFateFrameInfo &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_frameContent_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(obj.frameContent),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::wifi::V1_0::WifiDebugPacketFateFrameInfo, frameContent), &_hidl_frameContent_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const WifiDebugPacketFateFrameInfo &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_frameContent_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.frameContent,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::wifi::V1_0::WifiDebugPacketFateFrameInfo, frameContent), &_hidl_frameContent_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const WifiDebugTxPacketFateReport &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::wifi::V1_0::WifiDebugPacketFateFrameInfo &>(obj.frameInfo),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::wifi::V1_0::WifiDebugTxPacketFateReport, frameInfo));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const WifiDebugTxPacketFateReport &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = writeEmbeddedToParcel(
            obj.frameInfo,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::wifi::V1_0::WifiDebugTxPacketFateReport, frameInfo));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const WifiDebugRxPacketFateReport &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::wifi::V1_0::WifiDebugPacketFateFrameInfo &>(obj.frameInfo),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::wifi::V1_0::WifiDebugRxPacketFateReport, frameInfo));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const WifiDebugRxPacketFateReport &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = writeEmbeddedToParcel(
            obj.frameInfo,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::wifi::V1_0::WifiDebugRxPacketFateReport, frameInfo));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const WifiDebugHostWakeReasonStats &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_cmdEventWakeCntPerType_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint32_t> &>(obj.cmdEventWakeCntPerType),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::wifi::V1_0::WifiDebugHostWakeReasonStats, cmdEventWakeCntPerType), &_hidl_cmdEventWakeCntPerType_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_driverFwLocalWakeCntPerType_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint32_t> &>(obj.driverFwLocalWakeCntPerType),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::wifi::V1_0::WifiDebugHostWakeReasonStats, driverFwLocalWakeCntPerType), &_hidl_driverFwLocalWakeCntPerType_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const WifiDebugHostWakeReasonStats &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_cmdEventWakeCntPerType_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.cmdEventWakeCntPerType,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::wifi::V1_0::WifiDebugHostWakeReasonStats, cmdEventWakeCntPerType), &_hidl_cmdEventWakeCntPerType_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_driverFwLocalWakeCntPerType_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.driverFwLocalWakeCntPerType,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::wifi::V1_0::WifiDebugHostWakeReasonStats, driverFwLocalWakeCntPerType), &_hidl_driverFwLocalWakeCntPerType_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

static_assert(sizeof(::android::hardware::MQDescriptor<char, ::android::hardware::kSynchronizedReadWrite>) == 32, "wrong size");
static_assert(sizeof(::android::hardware::hidl_handle) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_memory) == 40, "wrong size");
static_assert(sizeof(::android::hardware::hidl_string) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_vec<char>) == 16, "wrong size");

}  // namespace V1_0
}  // namespace wifi
}  // namespace hardware
}  // namespace android
