#define LOG_TAG "android.hardware.broadcastradio@1.0::types"

#include <log/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <hidl/Static.h>
#include <hwbinder/ProcessState.h>
#include <utils/Trace.h>
#include <android/hardware/broadcastradio/1.0/types.h>
#include <android/hardware/broadcastradio/1.0/hwtypes.h>

namespace android {
namespace hardware {
namespace broadcastradio {
namespace V1_0 {

::android::status_t readEmbeddedFromParcel(
        const BandConfig &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_spacings_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint32_t> &>(obj.spacings),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::broadcastradio::V1_0::BandConfig, spacings), &_hidl_spacings_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const BandConfig &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_spacings_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.spacings,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::broadcastradio::V1_0::BandConfig, spacings), &_hidl_spacings_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const Properties &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.implementor),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::broadcastradio::V1_0::Properties, implementor));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.product),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::broadcastradio::V1_0::Properties, product));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.version),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::broadcastradio::V1_0::Properties, version));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.serial),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::broadcastradio::V1_0::Properties, serial));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_bands_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::broadcastradio::V1_0::BandConfig> &>(obj.bands),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::broadcastradio::V1_0::Properties, bands), &_hidl_bands_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.bands.size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::broadcastradio::V1_0::BandConfig &>(obj.bands[_hidl_index_0]),
                parcel,
                _hidl_bands_child,
                _hidl_index_0 * sizeof(::android::hardware::broadcastradio::V1_0::BandConfig));

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

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.implementor,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::broadcastradio::V1_0::Properties, implementor));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.product,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::broadcastradio::V1_0::Properties, product));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.version,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::broadcastradio::V1_0::Properties, version));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.serial,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::broadcastradio::V1_0::Properties, serial));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_bands_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.bands,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::broadcastradio::V1_0::Properties, bands), &_hidl_bands_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.bands.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                obj.bands[_hidl_index_0],
                parcel,
                _hidl_bands_child,
                _hidl_index_0 * sizeof(::android::hardware::broadcastradio::V1_0::BandConfig));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const MetaData &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.stringValue),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::broadcastradio::V1_0::MetaData, stringValue));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_rawValue_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(obj.rawValue),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::broadcastradio::V1_0::MetaData, rawValue), &_hidl_rawValue_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const MetaData &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.stringValue,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::broadcastradio::V1_0::MetaData, stringValue));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_rawValue_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.rawValue,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::broadcastradio::V1_0::MetaData, rawValue), &_hidl_rawValue_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const ProgramInfo &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_metadata_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::broadcastradio::V1_0::MetaData> &>(obj.metadata),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::broadcastradio::V1_0::ProgramInfo, metadata), &_hidl_metadata_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.metadata.size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::broadcastradio::V1_0::MetaData &>(obj.metadata[_hidl_index_0]),
                parcel,
                _hidl_metadata_child,
                _hidl_index_0 * sizeof(::android::hardware::broadcastradio::V1_0::MetaData));

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

    size_t _hidl_metadata_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.metadata,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::broadcastradio::V1_0::ProgramInfo, metadata), &_hidl_metadata_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.metadata.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                obj.metadata[_hidl_index_0],
                parcel,
                _hidl_metadata_child,
                _hidl_index_0 * sizeof(::android::hardware::broadcastradio::V1_0::MetaData));

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
}  // namespace broadcastradio
}  // namespace hardware
}  // namespace android
