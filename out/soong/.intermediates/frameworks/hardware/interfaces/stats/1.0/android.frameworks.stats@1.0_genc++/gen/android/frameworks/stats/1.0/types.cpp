#define LOG_TAG "android.frameworks.stats@1.0::types"

#include <log/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <hidl/Static.h>
#include <hwbinder/ProcessState.h>
#include <utils/Trace.h>
#include <android/frameworks/stats/1.0/types.h>
#include <android/frameworks/stats/1.0/hwtypes.h>

namespace android {
namespace frameworks {
namespace stats {
namespace V1_0 {

::android::status_t readEmbeddedFromParcel(
        const ChargeCycles &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_cycleBucket_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<int32_t> &>(obj.cycleBucket),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::frameworks::stats::V1_0::ChargeCycles, cycleBucket), &_hidl_cycleBucket_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const ChargeCycles &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_cycleBucket_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.cycleBucket,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::frameworks::stats::V1_0::ChargeCycles, cycleBucket), &_hidl_cycleBucket_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const VendorAtom::Value &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    switch (obj.getDiscriminator()) {
        case ::android::frameworks::stats::V1_0::VendorAtom::Value::hidl_discriminator::stringValue: {
            _hidl_err = ::android::hardware::readEmbeddedFromParcel(
                    const_cast<::android::hardware::hidl_string &>(obj.stringValue()),
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
        const VendorAtom::Value &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    switch (obj.getDiscriminator()) {
        case ::android::frameworks::stats::V1_0::VendorAtom::Value::hidl_discriminator::stringValue: {
            _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                    obj.stringValue(),
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

::android::frameworks::stats::V1_0::VendorAtom::Value::Value() {
    static_assert(offsetof(::android::frameworks::stats::V1_0::VendorAtom::Value, hidl_d) == 0, "wrong offset");
    static_assert(offsetof(::android::frameworks::stats::V1_0::VendorAtom::Value, hidl_u) == 8, "wrong offset");

    ::std::memset(&hidl_u, 0, sizeof(hidl_u));
    ::std::memset(reinterpret_cast<uint8_t*>(this) + 1, 0, 7);
    // no padding to zero starting at offset 24

    hidl_d = hidl_discriminator::intValue;
    new (&hidl_u.intValue) int32_t();
}

::android::frameworks::stats::V1_0::VendorAtom::Value::~Value() {
    hidl_destructUnion();
}

::android::frameworks::stats::V1_0::VendorAtom::Value::Value(Value&& other) : ::android::frameworks::stats::V1_0::VendorAtom::Value() {
    *this = std::move(other);
}

::android::frameworks::stats::V1_0::VendorAtom::Value::Value(const Value& other) : ::android::frameworks::stats::V1_0::VendorAtom::Value() {
    *this = other;
}

::android::frameworks::stats::V1_0::VendorAtom::Value& (::android::frameworks::stats::V1_0::VendorAtom::Value::operator=)(Value&& other) {
    if (this == &other) { return *this; }

    switch (other.hidl_d) {
        case hidl_discriminator::intValue: {
            intValue(std::move(other.hidl_u.intValue));
            break;
        }
        case hidl_discriminator::longValue: {
            longValue(std::move(other.hidl_u.longValue));
            break;
        }
        case hidl_discriminator::floatValue: {
            floatValue(std::move(other.hidl_u.floatValue));
            break;
        }
        case hidl_discriminator::stringValue: {
            stringValue(std::move(other.hidl_u.stringValue));
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

::android::frameworks::stats::V1_0::VendorAtom::Value& (::android::frameworks::stats::V1_0::VendorAtom::Value::operator=)(const Value& other) {
    if (this == &other) { return *this; }

    switch (other.hidl_d) {
        case hidl_discriminator::intValue: {
            intValue(other.hidl_u.intValue);
            break;
        }
        case hidl_discriminator::longValue: {
            longValue(other.hidl_u.longValue);
            break;
        }
        case hidl_discriminator::floatValue: {
            floatValue(other.hidl_u.floatValue);
            break;
        }
        case hidl_discriminator::stringValue: {
            stringValue(other.hidl_u.stringValue);
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

void ::android::frameworks::stats::V1_0::VendorAtom::Value::hidl_destructUnion() {
    switch (hidl_d) {
        case hidl_discriminator::intValue: {
            ::android::hardware::details::destructElement(&(hidl_u.intValue));
            break;
        }
        case hidl_discriminator::longValue: {
            ::android::hardware::details::destructElement(&(hidl_u.longValue));
            break;
        }
        case hidl_discriminator::floatValue: {
            ::android::hardware::details::destructElement(&(hidl_u.floatValue));
            break;
        }
        case hidl_discriminator::stringValue: {
            ::android::hardware::details::destructElement(&(hidl_u.stringValue));
            break;
        }
        default: {
            ::android::hardware::details::logAlwaysFatal((
                    "Unknown union discriminator (value: " +
                    std::to_string((uint8_t) hidl_d) + ").").c_str());
        }
    }

}

void ::android::frameworks::stats::V1_0::VendorAtom::Value::intValue(int32_t o) {
    if (hidl_d != hidl_discriminator::intValue) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.intValue) int32_t(o);
        hidl_d = hidl_discriminator::intValue;
    }
    else if (&(hidl_u.intValue) != &o) {
        hidl_u.intValue = o;
    }
}

int32_t& (::android::frameworks::stats::V1_0::VendorAtom::Value::intValue)() {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::intValue)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::intValue));
    }

    return hidl_u.intValue;
}

int32_t (::android::frameworks::stats::V1_0::VendorAtom::Value::intValue)() const {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::intValue)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::intValue));
    }

    return hidl_u.intValue;
}

void ::android::frameworks::stats::V1_0::VendorAtom::Value::longValue(int64_t o) {
    if (hidl_d != hidl_discriminator::longValue) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.longValue) int64_t(o);
        hidl_d = hidl_discriminator::longValue;
    }
    else if (&(hidl_u.longValue) != &o) {
        hidl_u.longValue = o;
    }
}

int64_t& (::android::frameworks::stats::V1_0::VendorAtom::Value::longValue)() {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::longValue)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::longValue));
    }

    return hidl_u.longValue;
}

int64_t (::android::frameworks::stats::V1_0::VendorAtom::Value::longValue)() const {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::longValue)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::longValue));
    }

    return hidl_u.longValue;
}

void ::android::frameworks::stats::V1_0::VendorAtom::Value::floatValue(float o) {
    if (hidl_d != hidl_discriminator::floatValue) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.floatValue) float(o);
        hidl_d = hidl_discriminator::floatValue;
    }
    else if (&(hidl_u.floatValue) != &o) {
        hidl_u.floatValue = o;
    }
}

float& (::android::frameworks::stats::V1_0::VendorAtom::Value::floatValue)() {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::floatValue)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::floatValue));
    }

    return hidl_u.floatValue;
}

float (::android::frameworks::stats::V1_0::VendorAtom::Value::floatValue)() const {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::floatValue)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::floatValue));
    }

    return hidl_u.floatValue;
}

void ::android::frameworks::stats::V1_0::VendorAtom::Value::stringValue(const ::android::hardware::hidl_string& o) {
    if (hidl_d != hidl_discriminator::stringValue) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.stringValue) ::android::hardware::hidl_string(o);
        hidl_d = hidl_discriminator::stringValue;
    }
    else if (&(hidl_u.stringValue) != &o) {
        hidl_u.stringValue = o;
    }
}

void ::android::frameworks::stats::V1_0::VendorAtom::Value::stringValue(::android::hardware::hidl_string&& o) {
    if (hidl_d != hidl_discriminator::stringValue) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.stringValue) ::android::hardware::hidl_string(std::move(o));
        hidl_d = hidl_discriminator::stringValue;
    }
    else if (&(hidl_u.stringValue) != &o) {
        hidl_u.stringValue = std::move(o);
    }
}

::android::hardware::hidl_string& (::android::frameworks::stats::V1_0::VendorAtom::Value::stringValue)() {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::stringValue)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::stringValue));
    }

    return hidl_u.stringValue;
}

const ::android::hardware::hidl_string& (::android::frameworks::stats::V1_0::VendorAtom::Value::stringValue)() const {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::stringValue)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::stringValue));
    }

    return hidl_u.stringValue;
}

::android::frameworks::stats::V1_0::VendorAtom::Value::hidl_union::hidl_union() {}

::android::frameworks::stats::V1_0::VendorAtom::Value::hidl_union::~hidl_union() {}

::android::frameworks::stats::V1_0::VendorAtom::Value::hidl_discriminator (::android::frameworks::stats::V1_0::VendorAtom::Value::getDiscriminator)() const {
    return hidl_d;
}

::android::status_t readEmbeddedFromParcel(
        const VendorAtom &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.reverseDomainName),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::frameworks::stats::V1_0::VendorAtom, reverseDomainName));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_values_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::frameworks::stats::V1_0::VendorAtom::Value> &>(obj.values),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::frameworks::stats::V1_0::VendorAtom, values), &_hidl_values_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.values.size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::frameworks::stats::V1_0::VendorAtom::Value &>(obj.values[_hidl_index_0]),
                parcel,
                _hidl_values_child,
                _hidl_index_0 * sizeof(::android::frameworks::stats::V1_0::VendorAtom::Value));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const VendorAtom &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.reverseDomainName,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::frameworks::stats::V1_0::VendorAtom, reverseDomainName));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_values_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.values,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::frameworks::stats::V1_0::VendorAtom, values), &_hidl_values_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.values.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                obj.values[_hidl_index_0],
                parcel,
                _hidl_values_child,
                _hidl_index_0 * sizeof(::android::frameworks::stats::V1_0::VendorAtom::Value));

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
}  // namespace stats
}  // namespace frameworks
}  // namespace android
