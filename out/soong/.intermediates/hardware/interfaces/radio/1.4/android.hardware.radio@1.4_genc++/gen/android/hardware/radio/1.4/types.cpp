#define LOG_TAG "android.hardware.radio@1.4::types"

#include <log/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <hidl/Static.h>
#include <hwbinder/ProcessState.h>
#include <utils/Trace.h>
#include <android/hardware/radio/1.4/types.h>
#include <android/hardware/radio/1.4/hwtypes.h>

namespace android {
namespace hardware {
namespace radio {
namespace V1_4 {

::android::status_t readEmbeddedFromParcel(
        const EmergencyNumber &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.number),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_4::EmergencyNumber, number));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.mcc),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_4::EmergencyNumber, mcc));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.mnc),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_4::EmergencyNumber, mnc));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_urns_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::hidl_string> &>(obj.urns),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_4::EmergencyNumber, urns), &_hidl_urns_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.urns.size(); ++_hidl_index_0) {
        _hidl_err = ::android::hardware::readEmbeddedFromParcel(
                const_cast<::android::hardware::hidl_string &>(obj.urns[_hidl_index_0]),
                parcel,
                _hidl_urns_child,
                _hidl_index_0 * sizeof(::android::hardware::hidl_string));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const EmergencyNumber &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.number,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_4::EmergencyNumber, number));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.mcc,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_4::EmergencyNumber, mcc));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.mnc,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_4::EmergencyNumber, mnc));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_urns_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.urns,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_4::EmergencyNumber, urns), &_hidl_urns_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.urns.size(); ++_hidl_index_0) {
        _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                obj.urns[_hidl_index_0],
                parcel,
                _hidl_urns_child,
                _hidl_index_0 * sizeof(::android::hardware::hidl_string));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    return _hidl_err;
}

::android::hardware::radio::V1_4::RadioFrequencyInfo::RadioFrequencyInfo() {
    static_assert(offsetof(::android::hardware::radio::V1_4::RadioFrequencyInfo, hidl_d) == 0, "wrong offset");
    static_assert(offsetof(::android::hardware::radio::V1_4::RadioFrequencyInfo, hidl_u) == 4, "wrong offset");

    ::std::memset(&hidl_u, 0, sizeof(hidl_u));
    ::std::memset(reinterpret_cast<uint8_t*>(this) + 1, 0, 3);
    // no padding to zero starting at offset 8

    hidl_d = hidl_discriminator::range;
    new (&hidl_u.range) ::android::hardware::radio::V1_4::FrequencyRange();
}

::android::hardware::radio::V1_4::RadioFrequencyInfo::~RadioFrequencyInfo() {
    hidl_destructUnion();
}

::android::hardware::radio::V1_4::RadioFrequencyInfo::RadioFrequencyInfo(RadioFrequencyInfo&& other) : ::android::hardware::radio::V1_4::RadioFrequencyInfo() {
    *this = std::move(other);
}

::android::hardware::radio::V1_4::RadioFrequencyInfo::RadioFrequencyInfo(const RadioFrequencyInfo& other) : ::android::hardware::radio::V1_4::RadioFrequencyInfo() {
    *this = other;
}

::android::hardware::radio::V1_4::RadioFrequencyInfo& (::android::hardware::radio::V1_4::RadioFrequencyInfo::operator=)(RadioFrequencyInfo&& other) {
    if (this == &other) { return *this; }

    switch (other.hidl_d) {
        case hidl_discriminator::range: {
            range(std::move(other.hidl_u.range));
            break;
        }
        case hidl_discriminator::channelNumber: {
            channelNumber(std::move(other.hidl_u.channelNumber));
            break;
        }
        default: {
            ::android::hardware::details::logAlwaysFatal((
                    "Unknown union discriminator (value: " +
                    std::to_string((uint8_t) other.hidl_d) + ").").c_str());
        }
    }
    return *this;
}

::android::hardware::radio::V1_4::RadioFrequencyInfo& (::android::hardware::radio::V1_4::RadioFrequencyInfo::operator=)(const RadioFrequencyInfo& other) {
    if (this == &other) { return *this; }

    switch (other.hidl_d) {
        case hidl_discriminator::range: {
            range(other.hidl_u.range);
            break;
        }
        case hidl_discriminator::channelNumber: {
            channelNumber(other.hidl_u.channelNumber);
            break;
        }
        default: {
            ::android::hardware::details::logAlwaysFatal((
                    "Unknown union discriminator (value: " +
                    std::to_string((uint8_t) other.hidl_d) + ").").c_str());
        }
    }
    return *this;
}

void ::android::hardware::radio::V1_4::RadioFrequencyInfo::hidl_destructUnion() {
    switch (hidl_d) {
        case hidl_discriminator::range: {
            ::android::hardware::details::destructElement(&(hidl_u.range));
            break;
        }
        case hidl_discriminator::channelNumber: {
            ::android::hardware::details::destructElement(&(hidl_u.channelNumber));
            break;
        }
        default: {
            ::android::hardware::details::logAlwaysFatal((
                    "Unknown union discriminator (value: " +
                    std::to_string((uint8_t) hidl_d) + ").").c_str());
        }
    }

}

void ::android::hardware::radio::V1_4::RadioFrequencyInfo::range(::android::hardware::radio::V1_4::FrequencyRange o) {
    if (hidl_d != hidl_discriminator::range) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.range) ::android::hardware::radio::V1_4::FrequencyRange(o);
        hidl_d = hidl_discriminator::range;
    }
    else if (&(hidl_u.range) != &o) {
        hidl_u.range = o;
    }
}

::android::hardware::radio::V1_4::FrequencyRange& (::android::hardware::radio::V1_4::RadioFrequencyInfo::range)() {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::range)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::range));
    }

    return hidl_u.range;
}

::android::hardware::radio::V1_4::FrequencyRange (::android::hardware::radio::V1_4::RadioFrequencyInfo::range)() const {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::range)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::range));
    }

    return hidl_u.range;
}

void ::android::hardware::radio::V1_4::RadioFrequencyInfo::channelNumber(int32_t o) {
    if (hidl_d != hidl_discriminator::channelNumber) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.channelNumber) int32_t(o);
        hidl_d = hidl_discriminator::channelNumber;
    }
    else if (&(hidl_u.channelNumber) != &o) {
        hidl_u.channelNumber = o;
    }
}

int32_t& (::android::hardware::radio::V1_4::RadioFrequencyInfo::channelNumber)() {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::channelNumber)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::channelNumber));
    }

    return hidl_u.channelNumber;
}

int32_t (::android::hardware::radio::V1_4::RadioFrequencyInfo::channelNumber)() const {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::channelNumber)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::channelNumber));
    }

    return hidl_u.channelNumber;
}

::android::hardware::radio::V1_4::RadioFrequencyInfo::hidl_union::hidl_union() {}

::android::hardware::radio::V1_4::RadioFrequencyInfo::hidl_union::~hidl_union() {}

::android::hardware::radio::V1_4::RadioFrequencyInfo::hidl_discriminator (::android::hardware::radio::V1_4::RadioFrequencyInfo::getDiscriminator)() const {
    return hidl_d;
}

::android::status_t readEmbeddedFromParcel(
        const PhysicalChannelConfig &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_contextIds_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<int32_t> &>(obj.contextIds),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_4::PhysicalChannelConfig, contextIds), &_hidl_contextIds_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const PhysicalChannelConfig &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_contextIds_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.contextIds,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_4::PhysicalChannelConfig, contextIds), &_hidl_contextIds_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::hardware::radio::V1_4::DataRegStateResult::VopsInfo::VopsInfo() {
    static_assert(offsetof(::android::hardware::radio::V1_4::DataRegStateResult::VopsInfo, hidl_d) == 0, "wrong offset");
    static_assert(offsetof(::android::hardware::radio::V1_4::DataRegStateResult::VopsInfo, hidl_u) == 1, "wrong offset");

    ::std::memset(&hidl_u, 0, sizeof(hidl_u));
    // no padding to zero starting at offset 1
    // no padding to zero starting at offset 3

    hidl_d = hidl_discriminator::noinit;
    new (&hidl_u.noinit) ::android::hidl::safe_union::V1_0::Monostate();
}

::android::hardware::radio::V1_4::DataRegStateResult::VopsInfo::~VopsInfo() {
    hidl_destructUnion();
}

::android::hardware::radio::V1_4::DataRegStateResult::VopsInfo::VopsInfo(VopsInfo&& other) : ::android::hardware::radio::V1_4::DataRegStateResult::VopsInfo() {
    *this = std::move(other);
}

::android::hardware::radio::V1_4::DataRegStateResult::VopsInfo::VopsInfo(const VopsInfo& other) : ::android::hardware::radio::V1_4::DataRegStateResult::VopsInfo() {
    *this = other;
}

::android::hardware::radio::V1_4::DataRegStateResult::VopsInfo& (::android::hardware::radio::V1_4::DataRegStateResult::VopsInfo::operator=)(VopsInfo&& other) {
    if (this == &other) { return *this; }

    switch (other.hidl_d) {
        case hidl_discriminator::noinit: {
            noinit(std::move(other.hidl_u.noinit));
            break;
        }
        case hidl_discriminator::lteVopsInfo: {
            lteVopsInfo(std::move(other.hidl_u.lteVopsInfo));
            break;
        }
        default: {
            ::android::hardware::details::logAlwaysFatal((
                    "Unknown union discriminator (value: " +
                    std::to_string((uint8_t) other.hidl_d) + ").").c_str());
        }
    }
    return *this;
}

::android::hardware::radio::V1_4::DataRegStateResult::VopsInfo& (::android::hardware::radio::V1_4::DataRegStateResult::VopsInfo::operator=)(const VopsInfo& other) {
    if (this == &other) { return *this; }

    switch (other.hidl_d) {
        case hidl_discriminator::noinit: {
            noinit(other.hidl_u.noinit);
            break;
        }
        case hidl_discriminator::lteVopsInfo: {
            lteVopsInfo(other.hidl_u.lteVopsInfo);
            break;
        }
        default: {
            ::android::hardware::details::logAlwaysFatal((
                    "Unknown union discriminator (value: " +
                    std::to_string((uint8_t) other.hidl_d) + ").").c_str());
        }
    }
    return *this;
}

void ::android::hardware::radio::V1_4::DataRegStateResult::VopsInfo::hidl_destructUnion() {
    switch (hidl_d) {
        case hidl_discriminator::noinit: {
            ::android::hardware::details::destructElement(&(hidl_u.noinit));
            break;
        }
        case hidl_discriminator::lteVopsInfo: {
            ::android::hardware::details::destructElement(&(hidl_u.lteVopsInfo));
            break;
        }
        default: {
            ::android::hardware::details::logAlwaysFatal((
                    "Unknown union discriminator (value: " +
                    std::to_string((uint8_t) hidl_d) + ").").c_str());
        }
    }

}

void ::android::hardware::radio::V1_4::DataRegStateResult::VopsInfo::noinit(const ::android::hidl::safe_union::V1_0::Monostate& o) {
    if (hidl_d != hidl_discriminator::noinit) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.noinit) ::android::hidl::safe_union::V1_0::Monostate(o);
        hidl_d = hidl_discriminator::noinit;
    }
    else if (&(hidl_u.noinit) != &o) {
        hidl_u.noinit = o;
    }
}

void ::android::hardware::radio::V1_4::DataRegStateResult::VopsInfo::noinit(::android::hidl::safe_union::V1_0::Monostate&& o) {
    if (hidl_d != hidl_discriminator::noinit) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.noinit) ::android::hidl::safe_union::V1_0::Monostate(std::move(o));
        hidl_d = hidl_discriminator::noinit;
    }
    else if (&(hidl_u.noinit) != &o) {
        hidl_u.noinit = std::move(o);
    }
}

::android::hidl::safe_union::V1_0::Monostate& (::android::hardware::radio::V1_4::DataRegStateResult::VopsInfo::noinit)() {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::noinit)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::noinit));
    }

    return hidl_u.noinit;
}

const ::android::hidl::safe_union::V1_0::Monostate& (::android::hardware::radio::V1_4::DataRegStateResult::VopsInfo::noinit)() const {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::noinit)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::noinit));
    }

    return hidl_u.noinit;
}

void ::android::hardware::radio::V1_4::DataRegStateResult::VopsInfo::lteVopsInfo(const ::android::hardware::radio::V1_4::LteVopsInfo& o) {
    if (hidl_d != hidl_discriminator::lteVopsInfo) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.lteVopsInfo) ::android::hardware::radio::V1_4::LteVopsInfo(o);
        hidl_d = hidl_discriminator::lteVopsInfo;
    }
    else if (&(hidl_u.lteVopsInfo) != &o) {
        hidl_u.lteVopsInfo = o;
    }
}

void ::android::hardware::radio::V1_4::DataRegStateResult::VopsInfo::lteVopsInfo(::android::hardware::radio::V1_4::LteVopsInfo&& o) {
    if (hidl_d != hidl_discriminator::lteVopsInfo) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.lteVopsInfo) ::android::hardware::radio::V1_4::LteVopsInfo(std::move(o));
        hidl_d = hidl_discriminator::lteVopsInfo;
    }
    else if (&(hidl_u.lteVopsInfo) != &o) {
        hidl_u.lteVopsInfo = std::move(o);
    }
}

::android::hardware::radio::V1_4::LteVopsInfo& (::android::hardware::radio::V1_4::DataRegStateResult::VopsInfo::lteVopsInfo)() {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::lteVopsInfo)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::lteVopsInfo));
    }

    return hidl_u.lteVopsInfo;
}

const ::android::hardware::radio::V1_4::LteVopsInfo& (::android::hardware::radio::V1_4::DataRegStateResult::VopsInfo::lteVopsInfo)() const {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::lteVopsInfo)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::lteVopsInfo));
    }

    return hidl_u.lteVopsInfo;
}

::android::hardware::radio::V1_4::DataRegStateResult::VopsInfo::hidl_union::hidl_union() {}

::android::hardware::radio::V1_4::DataRegStateResult::VopsInfo::hidl_union::~hidl_union() {}

::android::hardware::radio::V1_4::DataRegStateResult::VopsInfo::hidl_discriminator (::android::hardware::radio::V1_4::DataRegStateResult::VopsInfo::getDiscriminator)() const {
    return hidl_d;
}

::android::status_t readEmbeddedFromParcel(
        const DataRegStateResult &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::radio::V1_2::DataRegStateResult &>(obj.base),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_4::DataRegStateResult, base));

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
            obj.base,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_4::DataRegStateResult, base));

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
            const_cast<::android::hardware::radio::V1_2::CellInfoLte &>(obj.base),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_4::CellInfoLte, base));

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
            obj.base,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_4::CellInfoLte, base));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const CellIdentityNr &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.mcc),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_4::CellIdentityNr, mcc));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.mnc),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_4::CellIdentityNr, mnc));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::radio::V1_2::CellIdentityOperatorNames &>(obj.operatorNames),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_4::CellIdentityNr, operatorNames));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const CellIdentityNr &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.mcc,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_4::CellIdentityNr, mcc));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.mnc,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_4::CellIdentityNr, mnc));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = writeEmbeddedToParcel(
            obj.operatorNames,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_4::CellIdentityNr, operatorNames));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const CellInfoNr &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::radio::V1_4::CellIdentityNr &>(obj.cellidentity),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_4::CellInfoNr, cellidentity));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const CellInfoNr &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = writeEmbeddedToParcel(
            obj.cellidentity,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_4::CellInfoNr, cellidentity));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const CellInfo::Info &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    switch (obj.getDiscriminator()) {
        case ::android::hardware::radio::V1_4::CellInfo::Info::hidl_discriminator::gsm: {
            _hidl_err = readEmbeddedFromParcel(
                    const_cast<::android::hardware::radio::V1_2::CellInfoGsm &>(obj.gsm()),
                    parcel,
                    parentHandle,
                    parentOffset + obj.hidl_getUnionOffset() /* safe_union: union offset into struct */);

            if (_hidl_err != ::android::OK) { return _hidl_err; }

            break;
        }
        case ::android::hardware::radio::V1_4::CellInfo::Info::hidl_discriminator::cdma: {
            _hidl_err = readEmbeddedFromParcel(
                    const_cast<::android::hardware::radio::V1_2::CellInfoCdma &>(obj.cdma()),
                    parcel,
                    parentHandle,
                    parentOffset + obj.hidl_getUnionOffset() /* safe_union: union offset into struct */);

            if (_hidl_err != ::android::OK) { return _hidl_err; }

            break;
        }
        case ::android::hardware::radio::V1_4::CellInfo::Info::hidl_discriminator::wcdma: {
            _hidl_err = readEmbeddedFromParcel(
                    const_cast<::android::hardware::radio::V1_2::CellInfoWcdma &>(obj.wcdma()),
                    parcel,
                    parentHandle,
                    parentOffset + obj.hidl_getUnionOffset() /* safe_union: union offset into struct */);

            if (_hidl_err != ::android::OK) { return _hidl_err; }

            break;
        }
        case ::android::hardware::radio::V1_4::CellInfo::Info::hidl_discriminator::tdscdma: {
            _hidl_err = readEmbeddedFromParcel(
                    const_cast<::android::hardware::radio::V1_2::CellInfoTdscdma &>(obj.tdscdma()),
                    parcel,
                    parentHandle,
                    parentOffset + obj.hidl_getUnionOffset() /* safe_union: union offset into struct */);

            if (_hidl_err != ::android::OK) { return _hidl_err; }

            break;
        }
        case ::android::hardware::radio::V1_4::CellInfo::Info::hidl_discriminator::lte: {
            _hidl_err = readEmbeddedFromParcel(
                    const_cast<::android::hardware::radio::V1_4::CellInfoLte &>(obj.lte()),
                    parcel,
                    parentHandle,
                    parentOffset + obj.hidl_getUnionOffset() /* safe_union: union offset into struct */);

            if (_hidl_err != ::android::OK) { return _hidl_err; }

            break;
        }
        case ::android::hardware::radio::V1_4::CellInfo::Info::hidl_discriminator::nr: {
            _hidl_err = readEmbeddedFromParcel(
                    const_cast<::android::hardware::radio::V1_4::CellInfoNr &>(obj.nr()),
                    parcel,
                    parentHandle,
                    parentOffset + obj.hidl_getUnionOffset() /* safe_union: union offset into struct */);

            if (_hidl_err != ::android::OK) { return _hidl_err; }

            break;
        }
        default: { break; }
    }
    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const CellInfo::Info &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    switch (obj.getDiscriminator()) {
        case ::android::hardware::radio::V1_4::CellInfo::Info::hidl_discriminator::gsm: {
            _hidl_err = writeEmbeddedToParcel(
                    obj.gsm(),
                    parcel,
                    parentHandle,
                    parentOffset + obj.hidl_getUnionOffset() /* safe_union: union offset into struct */);

            if (_hidl_err != ::android::OK) { return _hidl_err; }

            break;
        }
        case ::android::hardware::radio::V1_4::CellInfo::Info::hidl_discriminator::cdma: {
            _hidl_err = writeEmbeddedToParcel(
                    obj.cdma(),
                    parcel,
                    parentHandle,
                    parentOffset + obj.hidl_getUnionOffset() /* safe_union: union offset into struct */);

            if (_hidl_err != ::android::OK) { return _hidl_err; }

            break;
        }
        case ::android::hardware::radio::V1_4::CellInfo::Info::hidl_discriminator::wcdma: {
            _hidl_err = writeEmbeddedToParcel(
                    obj.wcdma(),
                    parcel,
                    parentHandle,
                    parentOffset + obj.hidl_getUnionOffset() /* safe_union: union offset into struct */);

            if (_hidl_err != ::android::OK) { return _hidl_err; }

            break;
        }
        case ::android::hardware::radio::V1_4::CellInfo::Info::hidl_discriminator::tdscdma: {
            _hidl_err = writeEmbeddedToParcel(
                    obj.tdscdma(),
                    parcel,
                    parentHandle,
                    parentOffset + obj.hidl_getUnionOffset() /* safe_union: union offset into struct */);

            if (_hidl_err != ::android::OK) { return _hidl_err; }

            break;
        }
        case ::android::hardware::radio::V1_4::CellInfo::Info::hidl_discriminator::lte: {
            _hidl_err = writeEmbeddedToParcel(
                    obj.lte(),
                    parcel,
                    parentHandle,
                    parentOffset + obj.hidl_getUnionOffset() /* safe_union: union offset into struct */);

            if (_hidl_err != ::android::OK) { return _hidl_err; }

            break;
        }
        case ::android::hardware::radio::V1_4::CellInfo::Info::hidl_discriminator::nr: {
            _hidl_err = writeEmbeddedToParcel(
                    obj.nr(),
                    parcel,
                    parentHandle,
                    parentOffset + obj.hidl_getUnionOffset() /* safe_union: union offset into struct */);

            if (_hidl_err != ::android::OK) { return _hidl_err; }

            break;
        }
        default: { break; }
    }
    return _hidl_err;
}

::android::hardware::radio::V1_4::CellInfo::Info::Info() {
    static_assert(offsetof(::android::hardware::radio::V1_4::CellInfo::Info, hidl_d) == 0, "wrong offset");
    static_assert(offsetof(::android::hardware::radio::V1_4::CellInfo::Info, hidl_u) == 8, "wrong offset");

    ::std::memset(&hidl_u, 0, sizeof(hidl_u));
    ::std::memset(reinterpret_cast<uint8_t*>(this) + 1, 0, 7);
    // no padding to zero starting at offset 128

    hidl_d = hidl_discriminator::gsm;
    new (&hidl_u.gsm) ::android::hardware::radio::V1_2::CellInfoGsm();
}

::android::hardware::radio::V1_4::CellInfo::Info::~Info() {
    hidl_destructUnion();
}

::android::hardware::radio::V1_4::CellInfo::Info::Info(Info&& other) : ::android::hardware::radio::V1_4::CellInfo::Info() {
    *this = std::move(other);
}

::android::hardware::radio::V1_4::CellInfo::Info::Info(const Info& other) : ::android::hardware::radio::V1_4::CellInfo::Info() {
    *this = other;
}

::android::hardware::radio::V1_4::CellInfo::Info& (::android::hardware::radio::V1_4::CellInfo::Info::operator=)(Info&& other) {
    if (this == &other) { return *this; }

    switch (other.hidl_d) {
        case hidl_discriminator::gsm: {
            gsm(std::move(other.hidl_u.gsm));
            break;
        }
        case hidl_discriminator::cdma: {
            cdma(std::move(other.hidl_u.cdma));
            break;
        }
        case hidl_discriminator::wcdma: {
            wcdma(std::move(other.hidl_u.wcdma));
            break;
        }
        case hidl_discriminator::tdscdma: {
            tdscdma(std::move(other.hidl_u.tdscdma));
            break;
        }
        case hidl_discriminator::lte: {
            lte(std::move(other.hidl_u.lte));
            break;
        }
        case hidl_discriminator::nr: {
            nr(std::move(other.hidl_u.nr));
            break;
        }
        default: {
            ::android::hardware::details::logAlwaysFatal((
                    "Unknown union discriminator (value: " +
                    std::to_string((uint8_t) other.hidl_d) + ").").c_str());
        }
    }
    return *this;
}

::android::hardware::radio::V1_4::CellInfo::Info& (::android::hardware::radio::V1_4::CellInfo::Info::operator=)(const Info& other) {
    if (this == &other) { return *this; }

    switch (other.hidl_d) {
        case hidl_discriminator::gsm: {
            gsm(other.hidl_u.gsm);
            break;
        }
        case hidl_discriminator::cdma: {
            cdma(other.hidl_u.cdma);
            break;
        }
        case hidl_discriminator::wcdma: {
            wcdma(other.hidl_u.wcdma);
            break;
        }
        case hidl_discriminator::tdscdma: {
            tdscdma(other.hidl_u.tdscdma);
            break;
        }
        case hidl_discriminator::lte: {
            lte(other.hidl_u.lte);
            break;
        }
        case hidl_discriminator::nr: {
            nr(other.hidl_u.nr);
            break;
        }
        default: {
            ::android::hardware::details::logAlwaysFatal((
                    "Unknown union discriminator (value: " +
                    std::to_string((uint8_t) other.hidl_d) + ").").c_str());
        }
    }
    return *this;
}

void ::android::hardware::radio::V1_4::CellInfo::Info::hidl_destructUnion() {
    switch (hidl_d) {
        case hidl_discriminator::gsm: {
            ::android::hardware::details::destructElement(&(hidl_u.gsm));
            break;
        }
        case hidl_discriminator::cdma: {
            ::android::hardware::details::destructElement(&(hidl_u.cdma));
            break;
        }
        case hidl_discriminator::wcdma: {
            ::android::hardware::details::destructElement(&(hidl_u.wcdma));
            break;
        }
        case hidl_discriminator::tdscdma: {
            ::android::hardware::details::destructElement(&(hidl_u.tdscdma));
            break;
        }
        case hidl_discriminator::lte: {
            ::android::hardware::details::destructElement(&(hidl_u.lte));
            break;
        }
        case hidl_discriminator::nr: {
            ::android::hardware::details::destructElement(&(hidl_u.nr));
            break;
        }
        default: {
            ::android::hardware::details::logAlwaysFatal((
                    "Unknown union discriminator (value: " +
                    std::to_string((uint8_t) hidl_d) + ").").c_str());
        }
    }

}

void ::android::hardware::radio::V1_4::CellInfo::Info::gsm(const ::android::hardware::radio::V1_2::CellInfoGsm& o) {
    if (hidl_d != hidl_discriminator::gsm) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.gsm) ::android::hardware::radio::V1_2::CellInfoGsm(o);
        hidl_d = hidl_discriminator::gsm;
    }
    else if (&(hidl_u.gsm) != &o) {
        hidl_u.gsm = o;
    }
}

void ::android::hardware::radio::V1_4::CellInfo::Info::gsm(::android::hardware::radio::V1_2::CellInfoGsm&& o) {
    if (hidl_d != hidl_discriminator::gsm) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.gsm) ::android::hardware::radio::V1_2::CellInfoGsm(std::move(o));
        hidl_d = hidl_discriminator::gsm;
    }
    else if (&(hidl_u.gsm) != &o) {
        hidl_u.gsm = std::move(o);
    }
}

::android::hardware::radio::V1_2::CellInfoGsm& (::android::hardware::radio::V1_4::CellInfo::Info::gsm)() {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::gsm)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::gsm));
    }

    return hidl_u.gsm;
}

const ::android::hardware::radio::V1_2::CellInfoGsm& (::android::hardware::radio::V1_4::CellInfo::Info::gsm)() const {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::gsm)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::gsm));
    }

    return hidl_u.gsm;
}

void ::android::hardware::radio::V1_4::CellInfo::Info::cdma(const ::android::hardware::radio::V1_2::CellInfoCdma& o) {
    if (hidl_d != hidl_discriminator::cdma) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.cdma) ::android::hardware::radio::V1_2::CellInfoCdma(o);
        hidl_d = hidl_discriminator::cdma;
    }
    else if (&(hidl_u.cdma) != &o) {
        hidl_u.cdma = o;
    }
}

void ::android::hardware::radio::V1_4::CellInfo::Info::cdma(::android::hardware::radio::V1_2::CellInfoCdma&& o) {
    if (hidl_d != hidl_discriminator::cdma) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.cdma) ::android::hardware::radio::V1_2::CellInfoCdma(std::move(o));
        hidl_d = hidl_discriminator::cdma;
    }
    else if (&(hidl_u.cdma) != &o) {
        hidl_u.cdma = std::move(o);
    }
}

::android::hardware::radio::V1_2::CellInfoCdma& (::android::hardware::radio::V1_4::CellInfo::Info::cdma)() {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::cdma)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::cdma));
    }

    return hidl_u.cdma;
}

const ::android::hardware::radio::V1_2::CellInfoCdma& (::android::hardware::radio::V1_4::CellInfo::Info::cdma)() const {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::cdma)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::cdma));
    }

    return hidl_u.cdma;
}

void ::android::hardware::radio::V1_4::CellInfo::Info::wcdma(const ::android::hardware::radio::V1_2::CellInfoWcdma& o) {
    if (hidl_d != hidl_discriminator::wcdma) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.wcdma) ::android::hardware::radio::V1_2::CellInfoWcdma(o);
        hidl_d = hidl_discriminator::wcdma;
    }
    else if (&(hidl_u.wcdma) != &o) {
        hidl_u.wcdma = o;
    }
}

void ::android::hardware::radio::V1_4::CellInfo::Info::wcdma(::android::hardware::radio::V1_2::CellInfoWcdma&& o) {
    if (hidl_d != hidl_discriminator::wcdma) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.wcdma) ::android::hardware::radio::V1_2::CellInfoWcdma(std::move(o));
        hidl_d = hidl_discriminator::wcdma;
    }
    else if (&(hidl_u.wcdma) != &o) {
        hidl_u.wcdma = std::move(o);
    }
}

::android::hardware::radio::V1_2::CellInfoWcdma& (::android::hardware::radio::V1_4::CellInfo::Info::wcdma)() {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::wcdma)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::wcdma));
    }

    return hidl_u.wcdma;
}

const ::android::hardware::radio::V1_2::CellInfoWcdma& (::android::hardware::radio::V1_4::CellInfo::Info::wcdma)() const {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::wcdma)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::wcdma));
    }

    return hidl_u.wcdma;
}

void ::android::hardware::radio::V1_4::CellInfo::Info::tdscdma(const ::android::hardware::radio::V1_2::CellInfoTdscdma& o) {
    if (hidl_d != hidl_discriminator::tdscdma) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.tdscdma) ::android::hardware::radio::V1_2::CellInfoTdscdma(o);
        hidl_d = hidl_discriminator::tdscdma;
    }
    else if (&(hidl_u.tdscdma) != &o) {
        hidl_u.tdscdma = o;
    }
}

void ::android::hardware::radio::V1_4::CellInfo::Info::tdscdma(::android::hardware::radio::V1_2::CellInfoTdscdma&& o) {
    if (hidl_d != hidl_discriminator::tdscdma) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.tdscdma) ::android::hardware::radio::V1_2::CellInfoTdscdma(std::move(o));
        hidl_d = hidl_discriminator::tdscdma;
    }
    else if (&(hidl_u.tdscdma) != &o) {
        hidl_u.tdscdma = std::move(o);
    }
}

::android::hardware::radio::V1_2::CellInfoTdscdma& (::android::hardware::radio::V1_4::CellInfo::Info::tdscdma)() {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::tdscdma)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::tdscdma));
    }

    return hidl_u.tdscdma;
}

const ::android::hardware::radio::V1_2::CellInfoTdscdma& (::android::hardware::radio::V1_4::CellInfo::Info::tdscdma)() const {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::tdscdma)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::tdscdma));
    }

    return hidl_u.tdscdma;
}

void ::android::hardware::radio::V1_4::CellInfo::Info::lte(const ::android::hardware::radio::V1_4::CellInfoLte& o) {
    if (hidl_d != hidl_discriminator::lte) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.lte) ::android::hardware::radio::V1_4::CellInfoLte(o);
        hidl_d = hidl_discriminator::lte;
    }
    else if (&(hidl_u.lte) != &o) {
        hidl_u.lte = o;
    }
}

void ::android::hardware::radio::V1_4::CellInfo::Info::lte(::android::hardware::radio::V1_4::CellInfoLte&& o) {
    if (hidl_d != hidl_discriminator::lte) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.lte) ::android::hardware::radio::V1_4::CellInfoLte(std::move(o));
        hidl_d = hidl_discriminator::lte;
    }
    else if (&(hidl_u.lte) != &o) {
        hidl_u.lte = std::move(o);
    }
}

::android::hardware::radio::V1_4::CellInfoLte& (::android::hardware::radio::V1_4::CellInfo::Info::lte)() {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::lte)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::lte));
    }

    return hidl_u.lte;
}

const ::android::hardware::radio::V1_4::CellInfoLte& (::android::hardware::radio::V1_4::CellInfo::Info::lte)() const {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::lte)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::lte));
    }

    return hidl_u.lte;
}

void ::android::hardware::radio::V1_4::CellInfo::Info::nr(const ::android::hardware::radio::V1_4::CellInfoNr& o) {
    if (hidl_d != hidl_discriminator::nr) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.nr) ::android::hardware::radio::V1_4::CellInfoNr(o);
        hidl_d = hidl_discriminator::nr;
    }
    else if (&(hidl_u.nr) != &o) {
        hidl_u.nr = o;
    }
}

void ::android::hardware::radio::V1_4::CellInfo::Info::nr(::android::hardware::radio::V1_4::CellInfoNr&& o) {
    if (hidl_d != hidl_discriminator::nr) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.nr) ::android::hardware::radio::V1_4::CellInfoNr(std::move(o));
        hidl_d = hidl_discriminator::nr;
    }
    else if (&(hidl_u.nr) != &o) {
        hidl_u.nr = std::move(o);
    }
}

::android::hardware::radio::V1_4::CellInfoNr& (::android::hardware::radio::V1_4::CellInfo::Info::nr)() {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::nr)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::nr));
    }

    return hidl_u.nr;
}

const ::android::hardware::radio::V1_4::CellInfoNr& (::android::hardware::radio::V1_4::CellInfo::Info::nr)() const {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::nr)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::nr));
    }

    return hidl_u.nr;
}

::android::hardware::radio::V1_4::CellInfo::Info::hidl_union::hidl_union() {}

::android::hardware::radio::V1_4::CellInfo::Info::hidl_union::~hidl_union() {}

::android::hardware::radio::V1_4::CellInfo::Info::hidl_discriminator (::android::hardware::radio::V1_4::CellInfo::Info::getDiscriminator)() const {
    return hidl_d;
}

::android::status_t readEmbeddedFromParcel(
        const CellInfo &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::radio::V1_4::CellInfo::Info &>(obj.info),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_4::CellInfo, info));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const CellInfo &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = writeEmbeddedToParcel(
            obj.info,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_4::CellInfo, info));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

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
            const_cast<::android::hardware::hidl_vec<::android::hardware::radio::V1_4::CellInfo> &>(obj.networkInfos),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_4::NetworkScanResult, networkInfos), &_hidl_networkInfos_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.networkInfos.size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::radio::V1_4::CellInfo &>(obj.networkInfos[_hidl_index_0]),
                parcel,
                _hidl_networkInfos_child,
                _hidl_index_0 * sizeof(::android::hardware::radio::V1_4::CellInfo));

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
            parentOffset + offsetof(::android::hardware::radio::V1_4::NetworkScanResult, networkInfos), &_hidl_networkInfos_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.networkInfos.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                obj.networkInfos[_hidl_index_0],
                parcel,
                _hidl_networkInfos_child,
                _hidl_index_0 * sizeof(::android::hardware::radio::V1_4::CellInfo));

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
            parentOffset + offsetof(::android::hardware::radio::V1_4::DataProfileInfo, apn));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.user),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_4::DataProfileInfo, user));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.password),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_4::DataProfileInfo, password));

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
            parentOffset + offsetof(::android::hardware::radio::V1_4::DataProfileInfo, apn));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.user,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_4::DataProfileInfo, user));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.password,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_4::DataProfileInfo, password));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const CardStatus &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::radio::V1_2::CardStatus &>(obj.base),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_4::CardStatus, base));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.eid),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_4::CardStatus, eid));

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
            parentOffset + offsetof(::android::hardware::radio::V1_4::CardStatus, base));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.eid,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_4::CardStatus, eid));

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
            parentOffset + offsetof(::android::hardware::radio::V1_4::RadioCapability, logicalModemUuid));

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
            parentOffset + offsetof(::android::hardware::radio::V1_4::RadioCapability, logicalModemUuid));

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
            const_cast<::android::hardware::hidl_string &>(obj.ifname),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_4::SetupDataCallResult, ifname));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_addresses_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::hidl_string> &>(obj.addresses),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_4::SetupDataCallResult, addresses), &_hidl_addresses_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.addresses.size(); ++_hidl_index_0) {
        _hidl_err = ::android::hardware::readEmbeddedFromParcel(
                const_cast<::android::hardware::hidl_string &>(obj.addresses[_hidl_index_0]),
                parcel,
                _hidl_addresses_child,
                _hidl_index_0 * sizeof(::android::hardware::hidl_string));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    size_t _hidl_dnses_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::hidl_string> &>(obj.dnses),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_4::SetupDataCallResult, dnses), &_hidl_dnses_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.dnses.size(); ++_hidl_index_0) {
        _hidl_err = ::android::hardware::readEmbeddedFromParcel(
                const_cast<::android::hardware::hidl_string &>(obj.dnses[_hidl_index_0]),
                parcel,
                _hidl_dnses_child,
                _hidl_index_0 * sizeof(::android::hardware::hidl_string));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    size_t _hidl_gateways_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::hidl_string> &>(obj.gateways),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_4::SetupDataCallResult, gateways), &_hidl_gateways_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.gateways.size(); ++_hidl_index_0) {
        _hidl_err = ::android::hardware::readEmbeddedFromParcel(
                const_cast<::android::hardware::hidl_string &>(obj.gateways[_hidl_index_0]),
                parcel,
                _hidl_gateways_child,
                _hidl_index_0 * sizeof(::android::hardware::hidl_string));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    size_t _hidl_pcscf_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::hidl_string> &>(obj.pcscf),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_4::SetupDataCallResult, pcscf), &_hidl_pcscf_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.pcscf.size(); ++_hidl_index_0) {
        _hidl_err = ::android::hardware::readEmbeddedFromParcel(
                const_cast<::android::hardware::hidl_string &>(obj.pcscf[_hidl_index_0]),
                parcel,
                _hidl_pcscf_child,
                _hidl_index_0 * sizeof(::android::hardware::hidl_string));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const SetupDataCallResult &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.ifname,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_4::SetupDataCallResult, ifname));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_addresses_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.addresses,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_4::SetupDataCallResult, addresses), &_hidl_addresses_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.addresses.size(); ++_hidl_index_0) {
        _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                obj.addresses[_hidl_index_0],
                parcel,
                _hidl_addresses_child,
                _hidl_index_0 * sizeof(::android::hardware::hidl_string));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    size_t _hidl_dnses_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.dnses,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_4::SetupDataCallResult, dnses), &_hidl_dnses_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.dnses.size(); ++_hidl_index_0) {
        _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                obj.dnses[_hidl_index_0],
                parcel,
                _hidl_dnses_child,
                _hidl_index_0 * sizeof(::android::hardware::hidl_string));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    size_t _hidl_gateways_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.gateways,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_4::SetupDataCallResult, gateways), &_hidl_gateways_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.gateways.size(); ++_hidl_index_0) {
        _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                obj.gateways[_hidl_index_0],
                parcel,
                _hidl_gateways_child,
                _hidl_index_0 * sizeof(::android::hardware::hidl_string));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    size_t _hidl_pcscf_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.pcscf,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_4::SetupDataCallResult, pcscf), &_hidl_pcscf_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.pcscf.size(); ++_hidl_index_0) {
        _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                obj.pcscf[_hidl_index_0],
                parcel,
                _hidl_pcscf_child,
                _hidl_index_0 * sizeof(::android::hardware::hidl_string));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const CarrierRestrictionsWithPriority &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_allowedCarriers_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::radio::V1_0::Carrier> &>(obj.allowedCarriers),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_4::CarrierRestrictionsWithPriority, allowedCarriers), &_hidl_allowedCarriers_child);

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
            parentOffset + offsetof(::android::hardware::radio::V1_4::CarrierRestrictionsWithPriority, excludedCarriers), &_hidl_excludedCarriers_child);

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
        const CarrierRestrictionsWithPriority &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_allowedCarriers_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.allowedCarriers,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::radio::V1_4::CarrierRestrictionsWithPriority, allowedCarriers), &_hidl_allowedCarriers_child);

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
            parentOffset + offsetof(::android::hardware::radio::V1_4::CarrierRestrictionsWithPriority, excludedCarriers), &_hidl_excludedCarriers_child);

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

static_assert(sizeof(::android::hardware::MQDescriptor<char, ::android::hardware::kSynchronizedReadWrite>) == 32, "wrong size");
static_assert(sizeof(::android::hardware::hidl_handle) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_memory) == 40, "wrong size");
static_assert(sizeof(::android::hardware::hidl_string) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_vec<char>) == 16, "wrong size");

}  // namespace V1_4
}  // namespace radio
}  // namespace hardware
}  // namespace android
