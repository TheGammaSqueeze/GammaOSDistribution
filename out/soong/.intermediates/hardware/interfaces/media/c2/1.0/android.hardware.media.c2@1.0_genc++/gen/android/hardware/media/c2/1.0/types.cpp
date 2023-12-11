#define LOG_TAG "android.hardware.media.c2@1.0::types"

#include <log/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <hidl/Static.h>
#include <hwbinder/ProcessState.h>
#include <utils/Trace.h>
#include <android/hardware/media/c2/1.0/types.h>
#include <android/hardware/media/c2/1.0/hwtypes.h>

namespace android {
namespace hardware {
namespace media {
namespace c2 {
namespace V1_0 {

::android::status_t readEmbeddedFromParcel(
        const ParamDescriptor &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.name),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::media::c2::V1_0::ParamDescriptor, name));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_dependencies_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint32_t> &>(obj.dependencies),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::media::c2::V1_0::ParamDescriptor, dependencies), &_hidl_dependencies_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const ParamDescriptor &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.name,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::media::c2::V1_0::ParamDescriptor, name));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_dependencies_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.dependencies,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::media::c2::V1_0::ParamDescriptor, dependencies), &_hidl_dependencies_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const FieldSupportedValues &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    switch (obj.getDiscriminator()) {
        case ::android::hardware::media::c2::V1_0::FieldSupportedValues::hidl_discriminator::values: {
            size_t _hidl_values_child;

            _hidl_err = ::android::hardware::readEmbeddedFromParcel(
                    const_cast<::android::hardware::hidl_vec<uint64_t> &>(obj.values()),
                    parcel,
                    parentHandle,
                    parentOffset + obj.hidl_getUnionOffset() /* safe_union: union offset into struct */, &_hidl_values_child);

            if (_hidl_err != ::android::OK) { return _hidl_err; }

            break;
        }
        case ::android::hardware::media::c2::V1_0::FieldSupportedValues::hidl_discriminator::flags: {
            size_t _hidl_flags_child;

            _hidl_err = ::android::hardware::readEmbeddedFromParcel(
                    const_cast<::android::hardware::hidl_vec<uint64_t> &>(obj.flags()),
                    parcel,
                    parentHandle,
                    parentOffset + obj.hidl_getUnionOffset() /* safe_union: union offset into struct */, &_hidl_flags_child);

            if (_hidl_err != ::android::OK) { return _hidl_err; }

            break;
        }
        default: { break; }
    }
    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const FieldSupportedValues &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    switch (obj.getDiscriminator()) {
        case ::android::hardware::media::c2::V1_0::FieldSupportedValues::hidl_discriminator::values: {
            size_t _hidl_values_child;

            _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                    obj.values(),
                    parcel,
                    parentHandle,
                    parentOffset + obj.hidl_getUnionOffset() /* safe_union: union offset into struct */, &_hidl_values_child);

            if (_hidl_err != ::android::OK) { return _hidl_err; }

            break;
        }
        case ::android::hardware::media::c2::V1_0::FieldSupportedValues::hidl_discriminator::flags: {
            size_t _hidl_flags_child;

            _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                    obj.flags(),
                    parcel,
                    parentHandle,
                    parentOffset + obj.hidl_getUnionOffset() /* safe_union: union offset into struct */, &_hidl_flags_child);

            if (_hidl_err != ::android::OK) { return _hidl_err; }

            break;
        }
        default: { break; }
    }
    return _hidl_err;
}

::android::hardware::media::c2::V1_0::FieldSupportedValues::FieldSupportedValues() {
    static_assert(offsetof(::android::hardware::media::c2::V1_0::FieldSupportedValues, hidl_d) == 0, "wrong offset");
    static_assert(offsetof(::android::hardware::media::c2::V1_0::FieldSupportedValues, hidl_u) == 8, "wrong offset");

    ::std::memset(&hidl_u, 0, sizeof(hidl_u));
    ::std::memset(reinterpret_cast<uint8_t*>(this) + 1, 0, 7);
    // no padding to zero starting at offset 48

    hidl_d = hidl_discriminator::empty;
    new (&hidl_u.empty) ::android::hidl::safe_union::V1_0::Monostate();
}

::android::hardware::media::c2::V1_0::FieldSupportedValues::~FieldSupportedValues() {
    hidl_destructUnion();
}

::android::hardware::media::c2::V1_0::FieldSupportedValues::FieldSupportedValues(FieldSupportedValues&& other) : ::android::hardware::media::c2::V1_0::FieldSupportedValues() {
    *this = std::move(other);
}

::android::hardware::media::c2::V1_0::FieldSupportedValues::FieldSupportedValues(const FieldSupportedValues& other) : ::android::hardware::media::c2::V1_0::FieldSupportedValues() {
    *this = other;
}

::android::hardware::media::c2::V1_0::FieldSupportedValues& (::android::hardware::media::c2::V1_0::FieldSupportedValues::operator=)(FieldSupportedValues&& other) {
    if (this == &other) { return *this; }

    switch (other.hidl_d) {
        case hidl_discriminator::empty: {
            empty(std::move(other.hidl_u.empty));
            break;
        }
        case hidl_discriminator::range: {
            range(std::move(other.hidl_u.range));
            break;
        }
        case hidl_discriminator::values: {
            values(std::move(other.hidl_u.values));
            break;
        }
        case hidl_discriminator::flags: {
            flags(std::move(other.hidl_u.flags));
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

::android::hardware::media::c2::V1_0::FieldSupportedValues& (::android::hardware::media::c2::V1_0::FieldSupportedValues::operator=)(const FieldSupportedValues& other) {
    if (this == &other) { return *this; }

    switch (other.hidl_d) {
        case hidl_discriminator::empty: {
            empty(other.hidl_u.empty);
            break;
        }
        case hidl_discriminator::range: {
            range(other.hidl_u.range);
            break;
        }
        case hidl_discriminator::values: {
            values(other.hidl_u.values);
            break;
        }
        case hidl_discriminator::flags: {
            flags(other.hidl_u.flags);
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

void ::android::hardware::media::c2::V1_0::FieldSupportedValues::hidl_destructUnion() {
    switch (hidl_d) {
        case hidl_discriminator::empty: {
            ::android::hardware::details::destructElement(&(hidl_u.empty));
            break;
        }
        case hidl_discriminator::range: {
            ::android::hardware::details::destructElement(&(hidl_u.range));
            break;
        }
        case hidl_discriminator::values: {
            ::android::hardware::details::destructElement(&(hidl_u.values));
            break;
        }
        case hidl_discriminator::flags: {
            ::android::hardware::details::destructElement(&(hidl_u.flags));
            break;
        }
        default: {
            ::android::hardware::details::logAlwaysFatal((
                    "Unknown union discriminator (value: " +
                    std::to_string((uint8_t) hidl_d) + ").").c_str());
        }
    }

}

void ::android::hardware::media::c2::V1_0::FieldSupportedValues::empty(const ::android::hidl::safe_union::V1_0::Monostate& o) {
    if (hidl_d != hidl_discriminator::empty) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.empty) ::android::hidl::safe_union::V1_0::Monostate(o);
        hidl_d = hidl_discriminator::empty;
    }
    else if (&(hidl_u.empty) != &o) {
        hidl_u.empty = o;
    }
}

void ::android::hardware::media::c2::V1_0::FieldSupportedValues::empty(::android::hidl::safe_union::V1_0::Monostate&& o) {
    if (hidl_d != hidl_discriminator::empty) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.empty) ::android::hidl::safe_union::V1_0::Monostate(std::move(o));
        hidl_d = hidl_discriminator::empty;
    }
    else if (&(hidl_u.empty) != &o) {
        hidl_u.empty = std::move(o);
    }
}

::android::hidl::safe_union::V1_0::Monostate& (::android::hardware::media::c2::V1_0::FieldSupportedValues::empty)() {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::empty)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::empty));
    }

    return hidl_u.empty;
}

const ::android::hidl::safe_union::V1_0::Monostate& (::android::hardware::media::c2::V1_0::FieldSupportedValues::empty)() const {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::empty)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::empty));
    }

    return hidl_u.empty;
}

void ::android::hardware::media::c2::V1_0::FieldSupportedValues::range(const ::android::hardware::media::c2::V1_0::ValueRange& o) {
    if (hidl_d != hidl_discriminator::range) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.range) ::android::hardware::media::c2::V1_0::ValueRange(o);
        hidl_d = hidl_discriminator::range;
    }
    else if (&(hidl_u.range) != &o) {
        hidl_u.range = o;
    }
}

void ::android::hardware::media::c2::V1_0::FieldSupportedValues::range(::android::hardware::media::c2::V1_0::ValueRange&& o) {
    if (hidl_d != hidl_discriminator::range) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.range) ::android::hardware::media::c2::V1_0::ValueRange(std::move(o));
        hidl_d = hidl_discriminator::range;
    }
    else if (&(hidl_u.range) != &o) {
        hidl_u.range = std::move(o);
    }
}

::android::hardware::media::c2::V1_0::ValueRange& (::android::hardware::media::c2::V1_0::FieldSupportedValues::range)() {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::range)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::range));
    }

    return hidl_u.range;
}

const ::android::hardware::media::c2::V1_0::ValueRange& (::android::hardware::media::c2::V1_0::FieldSupportedValues::range)() const {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::range)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::range));
    }

    return hidl_u.range;
}

void ::android::hardware::media::c2::V1_0::FieldSupportedValues::values(const ::android::hardware::hidl_vec<uint64_t>& o) {
    if (hidl_d != hidl_discriminator::values) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.values) ::android::hardware::hidl_vec<uint64_t>(o);
        hidl_d = hidl_discriminator::values;
    }
    else if (&(hidl_u.values) != &o) {
        hidl_u.values = o;
    }
}

void ::android::hardware::media::c2::V1_0::FieldSupportedValues::values(::android::hardware::hidl_vec<uint64_t>&& o) {
    if (hidl_d != hidl_discriminator::values) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.values) ::android::hardware::hidl_vec<uint64_t>(std::move(o));
        hidl_d = hidl_discriminator::values;
    }
    else if (&(hidl_u.values) != &o) {
        hidl_u.values = std::move(o);
    }
}

::android::hardware::hidl_vec<uint64_t>& (::android::hardware::media::c2::V1_0::FieldSupportedValues::values)() {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::values)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::values));
    }

    return hidl_u.values;
}

const ::android::hardware::hidl_vec<uint64_t>& (::android::hardware::media::c2::V1_0::FieldSupportedValues::values)() const {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::values)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::values));
    }

    return hidl_u.values;
}

void ::android::hardware::media::c2::V1_0::FieldSupportedValues::flags(const ::android::hardware::hidl_vec<uint64_t>& o) {
    if (hidl_d != hidl_discriminator::flags) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.flags) ::android::hardware::hidl_vec<uint64_t>(o);
        hidl_d = hidl_discriminator::flags;
    }
    else if (&(hidl_u.flags) != &o) {
        hidl_u.flags = o;
    }
}

void ::android::hardware::media::c2::V1_0::FieldSupportedValues::flags(::android::hardware::hidl_vec<uint64_t>&& o) {
    if (hidl_d != hidl_discriminator::flags) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.flags) ::android::hardware::hidl_vec<uint64_t>(std::move(o));
        hidl_d = hidl_discriminator::flags;
    }
    else if (&(hidl_u.flags) != &o) {
        hidl_u.flags = std::move(o);
    }
}

::android::hardware::hidl_vec<uint64_t>& (::android::hardware::media::c2::V1_0::FieldSupportedValues::flags)() {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::flags)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::flags));
    }

    return hidl_u.flags;
}

const ::android::hardware::hidl_vec<uint64_t>& (::android::hardware::media::c2::V1_0::FieldSupportedValues::flags)() const {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::flags)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::flags));
    }

    return hidl_u.flags;
}

::android::hardware::media::c2::V1_0::FieldSupportedValues::hidl_union::hidl_union() {}

::android::hardware::media::c2::V1_0::FieldSupportedValues::hidl_union::~hidl_union() {}

::android::hardware::media::c2::V1_0::FieldSupportedValues::hidl_discriminator (::android::hardware::media::c2::V1_0::FieldSupportedValues::getDiscriminator)() const {
    return hidl_d;
}

::android::status_t readEmbeddedFromParcel(
        const ParamFieldValues &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_values_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::media::c2::V1_0::FieldSupportedValues> &>(obj.values),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::media::c2::V1_0::ParamFieldValues, values), &_hidl_values_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.values.size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::media::c2::V1_0::FieldSupportedValues &>(obj.values[_hidl_index_0]),
                parcel,
                _hidl_values_child,
                _hidl_index_0 * sizeof(::android::hardware::media::c2::V1_0::FieldSupportedValues));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const ParamFieldValues &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_values_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.values,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::media::c2::V1_0::ParamFieldValues, values), &_hidl_values_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.values.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                obj.values[_hidl_index_0],
                parcel,
                _hidl_values_child,
                _hidl_index_0 * sizeof(::android::hardware::media::c2::V1_0::FieldSupportedValues));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const FieldDescriptor::NamedValue &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.name),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::media::c2::V1_0::FieldDescriptor::NamedValue, name));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const FieldDescriptor::NamedValue &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.name,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::media::c2::V1_0::FieldDescriptor::NamedValue, name));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const FieldDescriptor &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.name),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::media::c2::V1_0::FieldDescriptor, name));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_namedValues_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::media::c2::V1_0::FieldDescriptor::NamedValue> &>(obj.namedValues),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::media::c2::V1_0::FieldDescriptor, namedValues), &_hidl_namedValues_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.namedValues.size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::media::c2::V1_0::FieldDescriptor::NamedValue &>(obj.namedValues[_hidl_index_0]),
                parcel,
                _hidl_namedValues_child,
                _hidl_index_0 * sizeof(::android::hardware::media::c2::V1_0::FieldDescriptor::NamedValue));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const FieldDescriptor &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.name,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::media::c2::V1_0::FieldDescriptor, name));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_namedValues_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.namedValues,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::media::c2::V1_0::FieldDescriptor, namedValues), &_hidl_namedValues_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.namedValues.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                obj.namedValues[_hidl_index_0],
                parcel,
                _hidl_namedValues_child,
                _hidl_index_0 * sizeof(::android::hardware::media::c2::V1_0::FieldDescriptor::NamedValue));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const StructDescriptor &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_fields_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::media::c2::V1_0::FieldDescriptor> &>(obj.fields),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::media::c2::V1_0::StructDescriptor, fields), &_hidl_fields_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.fields.size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::media::c2::V1_0::FieldDescriptor &>(obj.fields[_hidl_index_0]),
                parcel,
                _hidl_fields_child,
                _hidl_index_0 * sizeof(::android::hardware::media::c2::V1_0::FieldDescriptor));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const StructDescriptor &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_fields_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.fields,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::media::c2::V1_0::StructDescriptor, fields), &_hidl_fields_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.fields.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                obj.fields[_hidl_index_0],
                parcel,
                _hidl_fields_child,
                _hidl_index_0 * sizeof(::android::hardware::media::c2::V1_0::FieldDescriptor));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const SettingResult &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::media::c2::V1_0::ParamFieldValues &>(obj.field),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::media::c2::V1_0::SettingResult, field));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_conflicts_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::media::c2::V1_0::ParamFieldValues> &>(obj.conflicts),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::media::c2::V1_0::SettingResult, conflicts), &_hidl_conflicts_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.conflicts.size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::media::c2::V1_0::ParamFieldValues &>(obj.conflicts[_hidl_index_0]),
                parcel,
                _hidl_conflicts_child,
                _hidl_index_0 * sizeof(::android::hardware::media::c2::V1_0::ParamFieldValues));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const SettingResult &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = writeEmbeddedToParcel(
            obj.field,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::media::c2::V1_0::SettingResult, field));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_conflicts_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.conflicts,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::media::c2::V1_0::SettingResult, conflicts), &_hidl_conflicts_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.conflicts.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                obj.conflicts[_hidl_index_0],
                parcel,
                _hidl_conflicts_child,
                _hidl_index_0 * sizeof(::android::hardware::media::c2::V1_0::ParamFieldValues));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const BaseBlock &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    switch (obj.getDiscriminator()) {
        case ::android::hardware::media::c2::V1_0::BaseBlock::hidl_discriminator::nativeBlock: {
            _hidl_err = ::android::hardware::readEmbeddedFromParcel(
                    const_cast<::android::hardware::hidl_handle &>(obj.nativeBlock()),
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
        const BaseBlock &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    switch (obj.getDiscriminator()) {
        case ::android::hardware::media::c2::V1_0::BaseBlock::hidl_discriminator::nativeBlock: {
            _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                    obj.nativeBlock(),
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

::android::hardware::media::c2::V1_0::BaseBlock::BaseBlock() {
    static_assert(offsetof(::android::hardware::media::c2::V1_0::BaseBlock, hidl_d) == 0, "wrong offset");
    static_assert(offsetof(::android::hardware::media::c2::V1_0::BaseBlock, hidl_u) == 8, "wrong offset");

    ::std::memset(&hidl_u, 0, sizeof(hidl_u));
    ::std::memset(reinterpret_cast<uint8_t*>(this) + 1, 0, 7);
    // no padding to zero starting at offset 48

    hidl_d = hidl_discriminator::nativeBlock;
    new (&hidl_u.nativeBlock) ::android::hardware::hidl_handle();
}

::android::hardware::media::c2::V1_0::BaseBlock::~BaseBlock() {
    hidl_destructUnion();
}

::android::hardware::media::c2::V1_0::BaseBlock::BaseBlock(BaseBlock&& other) : ::android::hardware::media::c2::V1_0::BaseBlock() {
    *this = std::move(other);
}

::android::hardware::media::c2::V1_0::BaseBlock::BaseBlock(const BaseBlock& other) : ::android::hardware::media::c2::V1_0::BaseBlock() {
    *this = other;
}

::android::hardware::media::c2::V1_0::BaseBlock& (::android::hardware::media::c2::V1_0::BaseBlock::operator=)(BaseBlock&& other) {
    if (this == &other) { return *this; }

    switch (other.hidl_d) {
        case hidl_discriminator::nativeBlock: {
            nativeBlock(std::move(other.hidl_u.nativeBlock));
            break;
        }
        case hidl_discriminator::pooledBlock: {
            pooledBlock(std::move(other.hidl_u.pooledBlock));
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

::android::hardware::media::c2::V1_0::BaseBlock& (::android::hardware::media::c2::V1_0::BaseBlock::operator=)(const BaseBlock& other) {
    if (this == &other) { return *this; }

    switch (other.hidl_d) {
        case hidl_discriminator::nativeBlock: {
            nativeBlock(other.hidl_u.nativeBlock);
            break;
        }
        case hidl_discriminator::pooledBlock: {
            pooledBlock(other.hidl_u.pooledBlock);
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

void ::android::hardware::media::c2::V1_0::BaseBlock::hidl_destructUnion() {
    switch (hidl_d) {
        case hidl_discriminator::nativeBlock: {
            ::android::hardware::details::destructElement(&(hidl_u.nativeBlock));
            break;
        }
        case hidl_discriminator::pooledBlock: {
            ::android::hardware::details::destructElement(&(hidl_u.pooledBlock));
            break;
        }
        default: {
            ::android::hardware::details::logAlwaysFatal((
                    "Unknown union discriminator (value: " +
                    std::to_string((uint8_t) hidl_d) + ").").c_str());
        }
    }

}

void ::android::hardware::media::c2::V1_0::BaseBlock::nativeBlock(const ::android::hardware::hidl_handle& o) {
    if (hidl_d != hidl_discriminator::nativeBlock) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.nativeBlock) ::android::hardware::hidl_handle(o);
        hidl_d = hidl_discriminator::nativeBlock;
    }
    else if (&(hidl_u.nativeBlock) != &o) {
        hidl_u.nativeBlock = o;
    }
}

void ::android::hardware::media::c2::V1_0::BaseBlock::nativeBlock(::android::hardware::hidl_handle&& o) {
    if (hidl_d != hidl_discriminator::nativeBlock) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.nativeBlock) ::android::hardware::hidl_handle(std::move(o));
        hidl_d = hidl_discriminator::nativeBlock;
    }
    else if (&(hidl_u.nativeBlock) != &o) {
        hidl_u.nativeBlock = std::move(o);
    }
}

::android::hardware::hidl_handle& (::android::hardware::media::c2::V1_0::BaseBlock::nativeBlock)() {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::nativeBlock)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::nativeBlock));
    }

    return hidl_u.nativeBlock;
}

const ::android::hardware::hidl_handle& (::android::hardware::media::c2::V1_0::BaseBlock::nativeBlock)() const {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::nativeBlock)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::nativeBlock));
    }

    return hidl_u.nativeBlock;
}

void ::android::hardware::media::c2::V1_0::BaseBlock::pooledBlock(const ::android::hardware::media::bufferpool::V2_0::BufferStatusMessage& o) {
    if (hidl_d != hidl_discriminator::pooledBlock) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.pooledBlock) ::android::hardware::media::bufferpool::V2_0::BufferStatusMessage(o);
        hidl_d = hidl_discriminator::pooledBlock;
    }
    else if (&(hidl_u.pooledBlock) != &o) {
        hidl_u.pooledBlock = o;
    }
}

void ::android::hardware::media::c2::V1_0::BaseBlock::pooledBlock(::android::hardware::media::bufferpool::V2_0::BufferStatusMessage&& o) {
    if (hidl_d != hidl_discriminator::pooledBlock) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.pooledBlock) ::android::hardware::media::bufferpool::V2_0::BufferStatusMessage(std::move(o));
        hidl_d = hidl_discriminator::pooledBlock;
    }
    else if (&(hidl_u.pooledBlock) != &o) {
        hidl_u.pooledBlock = std::move(o);
    }
}

::android::hardware::media::bufferpool::V2_0::BufferStatusMessage& (::android::hardware::media::c2::V1_0::BaseBlock::pooledBlock)() {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::pooledBlock)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::pooledBlock));
    }

    return hidl_u.pooledBlock;
}

const ::android::hardware::media::bufferpool::V2_0::BufferStatusMessage& (::android::hardware::media::c2::V1_0::BaseBlock::pooledBlock)() const {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::pooledBlock)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::pooledBlock));
    }

    return hidl_u.pooledBlock;
}

::android::hardware::media::c2::V1_0::BaseBlock::hidl_union::hidl_union() {}

::android::hardware::media::c2::V1_0::BaseBlock::hidl_union::~hidl_union() {}

::android::hardware::media::c2::V1_0::BaseBlock::hidl_discriminator (::android::hardware::media::c2::V1_0::BaseBlock::getDiscriminator)() const {
    return hidl_d;
}

::android::status_t readEmbeddedFromParcel(
        const Block &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_meta_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(obj.meta),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::media::c2::V1_0::Block, meta), &_hidl_meta_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_handle &>(obj.fence),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::media::c2::V1_0::Block, fence));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const Block &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_meta_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.meta,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::media::c2::V1_0::Block, meta), &_hidl_meta_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.fence,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::media::c2::V1_0::Block, fence));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const Buffer &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_info_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(obj.info),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::media::c2::V1_0::Buffer, info), &_hidl_info_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_blocks_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::media::c2::V1_0::Block> &>(obj.blocks),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::media::c2::V1_0::Buffer, blocks), &_hidl_blocks_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.blocks.size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::media::c2::V1_0::Block &>(obj.blocks[_hidl_index_0]),
                parcel,
                _hidl_blocks_child,
                _hidl_index_0 * sizeof(::android::hardware::media::c2::V1_0::Block));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const Buffer &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_info_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.info,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::media::c2::V1_0::Buffer, info), &_hidl_info_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_blocks_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.blocks,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::media::c2::V1_0::Buffer, blocks), &_hidl_blocks_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.blocks.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                obj.blocks[_hidl_index_0],
                parcel,
                _hidl_blocks_child,
                _hidl_index_0 * sizeof(::android::hardware::media::c2::V1_0::Block));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const InfoBuffer &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::media::c2::V1_0::Buffer &>(obj.buffer),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::media::c2::V1_0::InfoBuffer, buffer));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const InfoBuffer &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = writeEmbeddedToParcel(
            obj.buffer,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::media::c2::V1_0::InfoBuffer, buffer));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const FrameData &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_buffers_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::media::c2::V1_0::Buffer> &>(obj.buffers),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::media::c2::V1_0::FrameData, buffers), &_hidl_buffers_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.buffers.size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::media::c2::V1_0::Buffer &>(obj.buffers[_hidl_index_0]),
                parcel,
                _hidl_buffers_child,
                _hidl_index_0 * sizeof(::android::hardware::media::c2::V1_0::Buffer));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    size_t _hidl_configUpdate_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(obj.configUpdate),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::media::c2::V1_0::FrameData, configUpdate), &_hidl_configUpdate_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_infoBuffers_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::media::c2::V1_0::InfoBuffer> &>(obj.infoBuffers),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::media::c2::V1_0::FrameData, infoBuffers), &_hidl_infoBuffers_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.infoBuffers.size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::media::c2::V1_0::InfoBuffer &>(obj.infoBuffers[_hidl_index_0]),
                parcel,
                _hidl_infoBuffers_child,
                _hidl_index_0 * sizeof(::android::hardware::media::c2::V1_0::InfoBuffer));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const FrameData &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_buffers_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.buffers,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::media::c2::V1_0::FrameData, buffers), &_hidl_buffers_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.buffers.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                obj.buffers[_hidl_index_0],
                parcel,
                _hidl_buffers_child,
                _hidl_index_0 * sizeof(::android::hardware::media::c2::V1_0::Buffer));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    size_t _hidl_configUpdate_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.configUpdate,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::media::c2::V1_0::FrameData, configUpdate), &_hidl_configUpdate_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_infoBuffers_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.infoBuffers,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::media::c2::V1_0::FrameData, infoBuffers), &_hidl_infoBuffers_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.infoBuffers.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                obj.infoBuffers[_hidl_index_0],
                parcel,
                _hidl_infoBuffers_child,
                _hidl_index_0 * sizeof(::android::hardware::media::c2::V1_0::InfoBuffer));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const Worklet &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_tunings_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(obj.tunings),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::media::c2::V1_0::Worklet, tunings), &_hidl_tunings_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_failures_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::media::c2::V1_0::SettingResult> &>(obj.failures),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::media::c2::V1_0::Worklet, failures), &_hidl_failures_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.failures.size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::media::c2::V1_0::SettingResult &>(obj.failures[_hidl_index_0]),
                parcel,
                _hidl_failures_child,
                _hidl_index_0 * sizeof(::android::hardware::media::c2::V1_0::SettingResult));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::media::c2::V1_0::FrameData &>(obj.output),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::media::c2::V1_0::Worklet, output));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const Worklet &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_tunings_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.tunings,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::media::c2::V1_0::Worklet, tunings), &_hidl_tunings_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_failures_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.failures,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::media::c2::V1_0::Worklet, failures), &_hidl_failures_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.failures.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                obj.failures[_hidl_index_0],
                parcel,
                _hidl_failures_child,
                _hidl_index_0 * sizeof(::android::hardware::media::c2::V1_0::SettingResult));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    _hidl_err = writeEmbeddedToParcel(
            obj.output,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::media::c2::V1_0::Worklet, output));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const Work &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_chainInfo_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(obj.chainInfo),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::media::c2::V1_0::Work, chainInfo), &_hidl_chainInfo_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::media::c2::V1_0::FrameData &>(obj.input),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::media::c2::V1_0::Work, input));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_worklets_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::media::c2::V1_0::Worklet> &>(obj.worklets),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::media::c2::V1_0::Work, worklets), &_hidl_worklets_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.worklets.size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::media::c2::V1_0::Worklet &>(obj.worklets[_hidl_index_0]),
                parcel,
                _hidl_worklets_child,
                _hidl_index_0 * sizeof(::android::hardware::media::c2::V1_0::Worklet));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const Work &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_chainInfo_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.chainInfo,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::media::c2::V1_0::Work, chainInfo), &_hidl_chainInfo_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = writeEmbeddedToParcel(
            obj.input,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::media::c2::V1_0::Work, input));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_worklets_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.worklets,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::media::c2::V1_0::Work, worklets), &_hidl_worklets_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.worklets.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                obj.worklets[_hidl_index_0],
                parcel,
                _hidl_worklets_child,
                _hidl_index_0 * sizeof(::android::hardware::media::c2::V1_0::Worklet));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const WorkBundle &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_works_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::media::c2::V1_0::Work> &>(obj.works),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::media::c2::V1_0::WorkBundle, works), &_hidl_works_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.works.size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::media::c2::V1_0::Work &>(obj.works[_hidl_index_0]),
                parcel,
                _hidl_works_child,
                _hidl_index_0 * sizeof(::android::hardware::media::c2::V1_0::Work));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    size_t _hidl_baseBlocks_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::media::c2::V1_0::BaseBlock> &>(obj.baseBlocks),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::media::c2::V1_0::WorkBundle, baseBlocks), &_hidl_baseBlocks_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.baseBlocks.size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::media::c2::V1_0::BaseBlock &>(obj.baseBlocks[_hidl_index_0]),
                parcel,
                _hidl_baseBlocks_child,
                _hidl_index_0 * sizeof(::android::hardware::media::c2::V1_0::BaseBlock));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const WorkBundle &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_works_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.works,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::media::c2::V1_0::WorkBundle, works), &_hidl_works_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.works.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                obj.works[_hidl_index_0],
                parcel,
                _hidl_works_child,
                _hidl_index_0 * sizeof(::android::hardware::media::c2::V1_0::Work));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    size_t _hidl_baseBlocks_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.baseBlocks,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::media::c2::V1_0::WorkBundle, baseBlocks), &_hidl_baseBlocks_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.baseBlocks.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                obj.baseBlocks[_hidl_index_0],
                parcel,
                _hidl_baseBlocks_child,
                _hidl_index_0 * sizeof(::android::hardware::media::c2::V1_0::BaseBlock));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const FieldSupportedValuesQueryResult &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::media::c2::V1_0::FieldSupportedValues &>(obj.values),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::media::c2::V1_0::FieldSupportedValuesQueryResult, values));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const FieldSupportedValuesQueryResult &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = writeEmbeddedToParcel(
            obj.values,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::media::c2::V1_0::FieldSupportedValuesQueryResult, values));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

static_assert(sizeof(::android::hardware::MQDescriptor<char, ::android::hardware::kSynchronizedReadWrite>) == 32, "wrong size");
static_assert(sizeof(::android::hardware::hidl_handle) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_memory) == 40, "wrong size");
static_assert(sizeof(::android::hardware::hidl_string) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_vec<char>) == 16, "wrong size");

}  // namespace V1_0
}  // namespace c2
}  // namespace media
}  // namespace hardware
}  // namespace android
