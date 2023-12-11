#define LOG_TAG "android.hardware.neuralnetworks@1.2::types"

#include <log/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <hidl/Static.h>
#include <hwbinder/ProcessState.h>
#include <utils/Trace.h>
#include <android/hardware/neuralnetworks/1.2/types.h>
#include <android/hardware/neuralnetworks/1.2/hwtypes.h>

namespace android {
namespace hardware {
namespace neuralnetworks {
namespace V1_2 {

::android::status_t readEmbeddedFromParcel(
        const Capabilities &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_operandPerformance_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::neuralnetworks::V1_2::Capabilities::OperandPerformance> &>(obj.operandPerformance),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::neuralnetworks::V1_2::Capabilities, operandPerformance), &_hidl_operandPerformance_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const Capabilities &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_operandPerformance_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.operandPerformance,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::neuralnetworks::V1_2::Capabilities, operandPerformance), &_hidl_operandPerformance_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const Operation &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_inputs_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint32_t> &>(obj.inputs),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::neuralnetworks::V1_2::Operation, inputs), &_hidl_inputs_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_outputs_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint32_t> &>(obj.outputs),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::neuralnetworks::V1_2::Operation, outputs), &_hidl_outputs_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const Operation &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_inputs_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.inputs,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::neuralnetworks::V1_2::Operation, inputs), &_hidl_inputs_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_outputs_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.outputs,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::neuralnetworks::V1_2::Operation, outputs), &_hidl_outputs_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const SymmPerChannelQuantParams &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_scales_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<float> &>(obj.scales),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::neuralnetworks::V1_2::SymmPerChannelQuantParams, scales), &_hidl_scales_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const SymmPerChannelQuantParams &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_scales_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.scales,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::neuralnetworks::V1_2::SymmPerChannelQuantParams, scales), &_hidl_scales_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const Operand::ExtraParams &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    switch (obj.getDiscriminator()) {
        case ::android::hardware::neuralnetworks::V1_2::Operand::ExtraParams::hidl_discriminator::channelQuant: {
            _hidl_err = readEmbeddedFromParcel(
                    const_cast<::android::hardware::neuralnetworks::V1_2::SymmPerChannelQuantParams &>(obj.channelQuant()),
                    parcel,
                    parentHandle,
                    parentOffset + obj.hidl_getUnionOffset() /* safe_union: union offset into struct */);

            if (_hidl_err != ::android::OK) { return _hidl_err; }

            break;
        }
        case ::android::hardware::neuralnetworks::V1_2::Operand::ExtraParams::hidl_discriminator::extension: {
            size_t _hidl_extension_child;

            _hidl_err = ::android::hardware::readEmbeddedFromParcel(
                    const_cast<::android::hardware::hidl_vec<uint8_t> &>(obj.extension()),
                    parcel,
                    parentHandle,
                    parentOffset + obj.hidl_getUnionOffset() /* safe_union: union offset into struct */, &_hidl_extension_child);

            if (_hidl_err != ::android::OK) { return _hidl_err; }

            break;
        }
        default: { break; }
    }
    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const Operand::ExtraParams &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    switch (obj.getDiscriminator()) {
        case ::android::hardware::neuralnetworks::V1_2::Operand::ExtraParams::hidl_discriminator::channelQuant: {
            _hidl_err = writeEmbeddedToParcel(
                    obj.channelQuant(),
                    parcel,
                    parentHandle,
                    parentOffset + obj.hidl_getUnionOffset() /* safe_union: union offset into struct */);

            if (_hidl_err != ::android::OK) { return _hidl_err; }

            break;
        }
        case ::android::hardware::neuralnetworks::V1_2::Operand::ExtraParams::hidl_discriminator::extension: {
            size_t _hidl_extension_child;

            _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                    obj.extension(),
                    parcel,
                    parentHandle,
                    parentOffset + obj.hidl_getUnionOffset() /* safe_union: union offset into struct */, &_hidl_extension_child);

            if (_hidl_err != ::android::OK) { return _hidl_err; }

            break;
        }
        default: { break; }
    }
    return _hidl_err;
}

::android::hardware::neuralnetworks::V1_2::Operand::ExtraParams::ExtraParams() {
    static_assert(offsetof(::android::hardware::neuralnetworks::V1_2::Operand::ExtraParams, hidl_d) == 0, "wrong offset");
    static_assert(offsetof(::android::hardware::neuralnetworks::V1_2::Operand::ExtraParams, hidl_u) == 8, "wrong offset");

    ::std::memset(&hidl_u, 0, sizeof(hidl_u));
    ::std::memset(reinterpret_cast<uint8_t*>(this) + 1, 0, 7);
    // no padding to zero starting at offset 32

    hidl_d = hidl_discriminator::none;
    new (&hidl_u.none) ::android::hidl::safe_union::V1_0::Monostate();
}

::android::hardware::neuralnetworks::V1_2::Operand::ExtraParams::~ExtraParams() {
    hidl_destructUnion();
}

::android::hardware::neuralnetworks::V1_2::Operand::ExtraParams::ExtraParams(ExtraParams&& other) : ::android::hardware::neuralnetworks::V1_2::Operand::ExtraParams() {
    *this = std::move(other);
}

::android::hardware::neuralnetworks::V1_2::Operand::ExtraParams::ExtraParams(const ExtraParams& other) : ::android::hardware::neuralnetworks::V1_2::Operand::ExtraParams() {
    *this = other;
}

::android::hardware::neuralnetworks::V1_2::Operand::ExtraParams& (::android::hardware::neuralnetworks::V1_2::Operand::ExtraParams::operator=)(ExtraParams&& other) {
    if (this == &other) { return *this; }

    switch (other.hidl_d) {
        case hidl_discriminator::none: {
            none(std::move(other.hidl_u.none));
            break;
        }
        case hidl_discriminator::channelQuant: {
            channelQuant(std::move(other.hidl_u.channelQuant));
            break;
        }
        case hidl_discriminator::extension: {
            extension(std::move(other.hidl_u.extension));
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

::android::hardware::neuralnetworks::V1_2::Operand::ExtraParams& (::android::hardware::neuralnetworks::V1_2::Operand::ExtraParams::operator=)(const ExtraParams& other) {
    if (this == &other) { return *this; }

    switch (other.hidl_d) {
        case hidl_discriminator::none: {
            none(other.hidl_u.none);
            break;
        }
        case hidl_discriminator::channelQuant: {
            channelQuant(other.hidl_u.channelQuant);
            break;
        }
        case hidl_discriminator::extension: {
            extension(other.hidl_u.extension);
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

void ::android::hardware::neuralnetworks::V1_2::Operand::ExtraParams::hidl_destructUnion() {
    switch (hidl_d) {
        case hidl_discriminator::none: {
            ::android::hardware::details::destructElement(&(hidl_u.none));
            break;
        }
        case hidl_discriminator::channelQuant: {
            ::android::hardware::details::destructElement(&(hidl_u.channelQuant));
            break;
        }
        case hidl_discriminator::extension: {
            ::android::hardware::details::destructElement(&(hidl_u.extension));
            break;
        }
        default: {
            ::android::hardware::details::logAlwaysFatal((
                    "Unknown union discriminator (value: " +
                    std::to_string((uint8_t) hidl_d) + ").").c_str());
        }
    }

}

void ::android::hardware::neuralnetworks::V1_2::Operand::ExtraParams::none(const ::android::hidl::safe_union::V1_0::Monostate& o) {
    if (hidl_d != hidl_discriminator::none) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.none) ::android::hidl::safe_union::V1_0::Monostate(o);
        hidl_d = hidl_discriminator::none;
    }
    else if (&(hidl_u.none) != &o) {
        hidl_u.none = o;
    }
}

void ::android::hardware::neuralnetworks::V1_2::Operand::ExtraParams::none(::android::hidl::safe_union::V1_0::Monostate&& o) {
    if (hidl_d != hidl_discriminator::none) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.none) ::android::hidl::safe_union::V1_0::Monostate(std::move(o));
        hidl_d = hidl_discriminator::none;
    }
    else if (&(hidl_u.none) != &o) {
        hidl_u.none = std::move(o);
    }
}

::android::hidl::safe_union::V1_0::Monostate& (::android::hardware::neuralnetworks::V1_2::Operand::ExtraParams::none)() {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::none)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::none));
    }

    return hidl_u.none;
}

const ::android::hidl::safe_union::V1_0::Monostate& (::android::hardware::neuralnetworks::V1_2::Operand::ExtraParams::none)() const {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::none)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::none));
    }

    return hidl_u.none;
}

void ::android::hardware::neuralnetworks::V1_2::Operand::ExtraParams::channelQuant(const ::android::hardware::neuralnetworks::V1_2::SymmPerChannelQuantParams& o) {
    if (hidl_d != hidl_discriminator::channelQuant) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.channelQuant) ::android::hardware::neuralnetworks::V1_2::SymmPerChannelQuantParams(o);
        hidl_d = hidl_discriminator::channelQuant;
    }
    else if (&(hidl_u.channelQuant) != &o) {
        hidl_u.channelQuant = o;
    }
}

void ::android::hardware::neuralnetworks::V1_2::Operand::ExtraParams::channelQuant(::android::hardware::neuralnetworks::V1_2::SymmPerChannelQuantParams&& o) {
    if (hidl_d != hidl_discriminator::channelQuant) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.channelQuant) ::android::hardware::neuralnetworks::V1_2::SymmPerChannelQuantParams(std::move(o));
        hidl_d = hidl_discriminator::channelQuant;
    }
    else if (&(hidl_u.channelQuant) != &o) {
        hidl_u.channelQuant = std::move(o);
    }
}

::android::hardware::neuralnetworks::V1_2::SymmPerChannelQuantParams& (::android::hardware::neuralnetworks::V1_2::Operand::ExtraParams::channelQuant)() {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::channelQuant)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::channelQuant));
    }

    return hidl_u.channelQuant;
}

const ::android::hardware::neuralnetworks::V1_2::SymmPerChannelQuantParams& (::android::hardware::neuralnetworks::V1_2::Operand::ExtraParams::channelQuant)() const {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::channelQuant)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::channelQuant));
    }

    return hidl_u.channelQuant;
}

void ::android::hardware::neuralnetworks::V1_2::Operand::ExtraParams::extension(const ::android::hardware::hidl_vec<uint8_t>& o) {
    if (hidl_d != hidl_discriminator::extension) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.extension) ::android::hardware::hidl_vec<uint8_t>(o);
        hidl_d = hidl_discriminator::extension;
    }
    else if (&(hidl_u.extension) != &o) {
        hidl_u.extension = o;
    }
}

void ::android::hardware::neuralnetworks::V1_2::Operand::ExtraParams::extension(::android::hardware::hidl_vec<uint8_t>&& o) {
    if (hidl_d != hidl_discriminator::extension) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.extension) ::android::hardware::hidl_vec<uint8_t>(std::move(o));
        hidl_d = hidl_discriminator::extension;
    }
    else if (&(hidl_u.extension) != &o) {
        hidl_u.extension = std::move(o);
    }
}

::android::hardware::hidl_vec<uint8_t>& (::android::hardware::neuralnetworks::V1_2::Operand::ExtraParams::extension)() {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::extension)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::extension));
    }

    return hidl_u.extension;
}

const ::android::hardware::hidl_vec<uint8_t>& (::android::hardware::neuralnetworks::V1_2::Operand::ExtraParams::extension)() const {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::extension)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::extension));
    }

    return hidl_u.extension;
}

::android::hardware::neuralnetworks::V1_2::Operand::ExtraParams::hidl_union::hidl_union() {}

::android::hardware::neuralnetworks::V1_2::Operand::ExtraParams::hidl_union::~hidl_union() {}

::android::hardware::neuralnetworks::V1_2::Operand::ExtraParams::hidl_discriminator (::android::hardware::neuralnetworks::V1_2::Operand::ExtraParams::getDiscriminator)() const {
    return hidl_d;
}

::android::status_t readEmbeddedFromParcel(
        const Operand &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_dimensions_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint32_t> &>(obj.dimensions),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::neuralnetworks::V1_2::Operand, dimensions), &_hidl_dimensions_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::neuralnetworks::V1_2::Operand::ExtraParams &>(obj.extraParams),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::neuralnetworks::V1_2::Operand, extraParams));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const Operand &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_dimensions_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.dimensions,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::neuralnetworks::V1_2::Operand, dimensions), &_hidl_dimensions_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = writeEmbeddedToParcel(
            obj.extraParams,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::neuralnetworks::V1_2::Operand, extraParams));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const Model::ExtensionNameAndPrefix &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.name),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::neuralnetworks::V1_2::Model::ExtensionNameAndPrefix, name));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const Model::ExtensionNameAndPrefix &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.name,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::neuralnetworks::V1_2::Model::ExtensionNameAndPrefix, name));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const Model &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_operands_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::neuralnetworks::V1_2::Operand> &>(obj.operands),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::neuralnetworks::V1_2::Model, operands), &_hidl_operands_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.operands.size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::neuralnetworks::V1_2::Operand &>(obj.operands[_hidl_index_0]),
                parcel,
                _hidl_operands_child,
                _hidl_index_0 * sizeof(::android::hardware::neuralnetworks::V1_2::Operand));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    size_t _hidl_operations_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::neuralnetworks::V1_2::Operation> &>(obj.operations),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::neuralnetworks::V1_2::Model, operations), &_hidl_operations_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.operations.size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::neuralnetworks::V1_2::Operation &>(obj.operations[_hidl_index_0]),
                parcel,
                _hidl_operations_child,
                _hidl_index_0 * sizeof(::android::hardware::neuralnetworks::V1_2::Operation));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    size_t _hidl_inputIndexes_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint32_t> &>(obj.inputIndexes),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::neuralnetworks::V1_2::Model, inputIndexes), &_hidl_inputIndexes_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_outputIndexes_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint32_t> &>(obj.outputIndexes),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::neuralnetworks::V1_2::Model, outputIndexes), &_hidl_outputIndexes_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_operandValues_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(obj.operandValues),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::neuralnetworks::V1_2::Model, operandValues), &_hidl_operandValues_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_pools_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::hidl_memory> &>(obj.pools),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::neuralnetworks::V1_2::Model, pools), &_hidl_pools_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.pools.size(); ++_hidl_index_0) {
        _hidl_err = ::android::hardware::readEmbeddedFromParcel(
                const_cast<::android::hardware::hidl_memory &>(obj.pools[_hidl_index_0]),
                parcel,
                _hidl_pools_child,
                _hidl_index_0 * sizeof(::android::hardware::hidl_memory));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    size_t _hidl_extensionNameToPrefix_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::neuralnetworks::V1_2::Model::ExtensionNameAndPrefix> &>(obj.extensionNameToPrefix),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::neuralnetworks::V1_2::Model, extensionNameToPrefix), &_hidl_extensionNameToPrefix_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.extensionNameToPrefix.size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::neuralnetworks::V1_2::Model::ExtensionNameAndPrefix &>(obj.extensionNameToPrefix[_hidl_index_0]),
                parcel,
                _hidl_extensionNameToPrefix_child,
                _hidl_index_0 * sizeof(::android::hardware::neuralnetworks::V1_2::Model::ExtensionNameAndPrefix));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const Model &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_operands_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.operands,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::neuralnetworks::V1_2::Model, operands), &_hidl_operands_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.operands.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                obj.operands[_hidl_index_0],
                parcel,
                _hidl_operands_child,
                _hidl_index_0 * sizeof(::android::hardware::neuralnetworks::V1_2::Operand));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    size_t _hidl_operations_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.operations,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::neuralnetworks::V1_2::Model, operations), &_hidl_operations_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.operations.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                obj.operations[_hidl_index_0],
                parcel,
                _hidl_operations_child,
                _hidl_index_0 * sizeof(::android::hardware::neuralnetworks::V1_2::Operation));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    size_t _hidl_inputIndexes_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.inputIndexes,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::neuralnetworks::V1_2::Model, inputIndexes), &_hidl_inputIndexes_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_outputIndexes_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.outputIndexes,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::neuralnetworks::V1_2::Model, outputIndexes), &_hidl_outputIndexes_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_operandValues_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.operandValues,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::neuralnetworks::V1_2::Model, operandValues), &_hidl_operandValues_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_pools_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.pools,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::neuralnetworks::V1_2::Model, pools), &_hidl_pools_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.pools.size(); ++_hidl_index_0) {
        _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                obj.pools[_hidl_index_0],
                parcel,
                _hidl_pools_child,
                _hidl_index_0 * sizeof(::android::hardware::hidl_memory));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    size_t _hidl_extensionNameToPrefix_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.extensionNameToPrefix,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::neuralnetworks::V1_2::Model, extensionNameToPrefix), &_hidl_extensionNameToPrefix_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.extensionNameToPrefix.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                obj.extensionNameToPrefix[_hidl_index_0],
                parcel,
                _hidl_extensionNameToPrefix_child,
                _hidl_index_0 * sizeof(::android::hardware::neuralnetworks::V1_2::Model::ExtensionNameAndPrefix));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const OutputShape &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_dimensions_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint32_t> &>(obj.dimensions),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::neuralnetworks::V1_2::OutputShape, dimensions), &_hidl_dimensions_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const OutputShape &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_dimensions_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.dimensions,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::neuralnetworks::V1_2::OutputShape, dimensions), &_hidl_dimensions_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::hardware::neuralnetworks::V1_2::FmqRequestDatum::FmqRequestDatum() {
    static_assert(offsetof(::android::hardware::neuralnetworks::V1_2::FmqRequestDatum, hidl_d) == 0, "wrong offset");
    static_assert(offsetof(::android::hardware::neuralnetworks::V1_2::FmqRequestDatum, hidl_u) == 4, "wrong offset");

    ::std::memset(&hidl_u, 0, sizeof(hidl_u));
    ::std::memset(reinterpret_cast<uint8_t*>(this) + 1, 0, 3);
    // no padding to zero starting at offset 24

    hidl_d = hidl_discriminator::packetInformation;
    new (&hidl_u.packetInformation) ::android::hardware::neuralnetworks::V1_2::FmqRequestDatum::PacketInformation();
}

::android::hardware::neuralnetworks::V1_2::FmqRequestDatum::~FmqRequestDatum() {
    hidl_destructUnion();
}

::android::hardware::neuralnetworks::V1_2::FmqRequestDatum::FmqRequestDatum(FmqRequestDatum&& other) : ::android::hardware::neuralnetworks::V1_2::FmqRequestDatum() {
    *this = std::move(other);
}

::android::hardware::neuralnetworks::V1_2::FmqRequestDatum::FmqRequestDatum(const FmqRequestDatum& other) : ::android::hardware::neuralnetworks::V1_2::FmqRequestDatum() {
    *this = other;
}

::android::hardware::neuralnetworks::V1_2::FmqRequestDatum& (::android::hardware::neuralnetworks::V1_2::FmqRequestDatum::operator=)(FmqRequestDatum&& other) {
    if (this == &other) { return *this; }

    switch (other.hidl_d) {
        case hidl_discriminator::packetInformation: {
            packetInformation(std::move(other.hidl_u.packetInformation));
            break;
        }
        case hidl_discriminator::inputOperandInformation: {
            inputOperandInformation(std::move(other.hidl_u.inputOperandInformation));
            break;
        }
        case hidl_discriminator::inputOperandDimensionValue: {
            inputOperandDimensionValue(std::move(other.hidl_u.inputOperandDimensionValue));
            break;
        }
        case hidl_discriminator::outputOperandInformation: {
            outputOperandInformation(std::move(other.hidl_u.outputOperandInformation));
            break;
        }
        case hidl_discriminator::outputOperandDimensionValue: {
            outputOperandDimensionValue(std::move(other.hidl_u.outputOperandDimensionValue));
            break;
        }
        case hidl_discriminator::poolIdentifier: {
            poolIdentifier(std::move(other.hidl_u.poolIdentifier));
            break;
        }
        case hidl_discriminator::measureTiming: {
            measureTiming(std::move(other.hidl_u.measureTiming));
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

::android::hardware::neuralnetworks::V1_2::FmqRequestDatum& (::android::hardware::neuralnetworks::V1_2::FmqRequestDatum::operator=)(const FmqRequestDatum& other) {
    if (this == &other) { return *this; }

    switch (other.hidl_d) {
        case hidl_discriminator::packetInformation: {
            packetInformation(other.hidl_u.packetInformation);
            break;
        }
        case hidl_discriminator::inputOperandInformation: {
            inputOperandInformation(other.hidl_u.inputOperandInformation);
            break;
        }
        case hidl_discriminator::inputOperandDimensionValue: {
            inputOperandDimensionValue(other.hidl_u.inputOperandDimensionValue);
            break;
        }
        case hidl_discriminator::outputOperandInformation: {
            outputOperandInformation(other.hidl_u.outputOperandInformation);
            break;
        }
        case hidl_discriminator::outputOperandDimensionValue: {
            outputOperandDimensionValue(other.hidl_u.outputOperandDimensionValue);
            break;
        }
        case hidl_discriminator::poolIdentifier: {
            poolIdentifier(other.hidl_u.poolIdentifier);
            break;
        }
        case hidl_discriminator::measureTiming: {
            measureTiming(other.hidl_u.measureTiming);
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

void ::android::hardware::neuralnetworks::V1_2::FmqRequestDatum::hidl_destructUnion() {
    switch (hidl_d) {
        case hidl_discriminator::packetInformation: {
            ::android::hardware::details::destructElement(&(hidl_u.packetInformation));
            break;
        }
        case hidl_discriminator::inputOperandInformation: {
            ::android::hardware::details::destructElement(&(hidl_u.inputOperandInformation));
            break;
        }
        case hidl_discriminator::inputOperandDimensionValue: {
            ::android::hardware::details::destructElement(&(hidl_u.inputOperandDimensionValue));
            break;
        }
        case hidl_discriminator::outputOperandInformation: {
            ::android::hardware::details::destructElement(&(hidl_u.outputOperandInformation));
            break;
        }
        case hidl_discriminator::outputOperandDimensionValue: {
            ::android::hardware::details::destructElement(&(hidl_u.outputOperandDimensionValue));
            break;
        }
        case hidl_discriminator::poolIdentifier: {
            ::android::hardware::details::destructElement(&(hidl_u.poolIdentifier));
            break;
        }
        case hidl_discriminator::measureTiming: {
            ::android::hardware::details::destructElement(&(hidl_u.measureTiming));
            break;
        }
        default: {
            ::android::hardware::details::logAlwaysFatal((
                    "Unknown union discriminator (value: " +
                    std::to_string((uint8_t) hidl_d) + ").").c_str());
        }
    }

}

void ::android::hardware::neuralnetworks::V1_2::FmqRequestDatum::packetInformation(const ::android::hardware::neuralnetworks::V1_2::FmqRequestDatum::PacketInformation& o) {
    if (hidl_d != hidl_discriminator::packetInformation) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.packetInformation) ::android::hardware::neuralnetworks::V1_2::FmqRequestDatum::PacketInformation(o);
        hidl_d = hidl_discriminator::packetInformation;
    }
    else if (&(hidl_u.packetInformation) != &o) {
        hidl_u.packetInformation = o;
    }
}

void ::android::hardware::neuralnetworks::V1_2::FmqRequestDatum::packetInformation(::android::hardware::neuralnetworks::V1_2::FmqRequestDatum::PacketInformation&& o) {
    if (hidl_d != hidl_discriminator::packetInformation) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.packetInformation) ::android::hardware::neuralnetworks::V1_2::FmqRequestDatum::PacketInformation(std::move(o));
        hidl_d = hidl_discriminator::packetInformation;
    }
    else if (&(hidl_u.packetInformation) != &o) {
        hidl_u.packetInformation = std::move(o);
    }
}

::android::hardware::neuralnetworks::V1_2::FmqRequestDatum::PacketInformation& (::android::hardware::neuralnetworks::V1_2::FmqRequestDatum::packetInformation)() {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::packetInformation)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::packetInformation));
    }

    return hidl_u.packetInformation;
}

const ::android::hardware::neuralnetworks::V1_2::FmqRequestDatum::PacketInformation& (::android::hardware::neuralnetworks::V1_2::FmqRequestDatum::packetInformation)() const {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::packetInformation)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::packetInformation));
    }

    return hidl_u.packetInformation;
}

void ::android::hardware::neuralnetworks::V1_2::FmqRequestDatum::inputOperandInformation(const ::android::hardware::neuralnetworks::V1_2::FmqRequestDatum::OperandInformation& o) {
    if (hidl_d != hidl_discriminator::inputOperandInformation) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.inputOperandInformation) ::android::hardware::neuralnetworks::V1_2::FmqRequestDatum::OperandInformation(o);
        hidl_d = hidl_discriminator::inputOperandInformation;
    }
    else if (&(hidl_u.inputOperandInformation) != &o) {
        hidl_u.inputOperandInformation = o;
    }
}

void ::android::hardware::neuralnetworks::V1_2::FmqRequestDatum::inputOperandInformation(::android::hardware::neuralnetworks::V1_2::FmqRequestDatum::OperandInformation&& o) {
    if (hidl_d != hidl_discriminator::inputOperandInformation) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.inputOperandInformation) ::android::hardware::neuralnetworks::V1_2::FmqRequestDatum::OperandInformation(std::move(o));
        hidl_d = hidl_discriminator::inputOperandInformation;
    }
    else if (&(hidl_u.inputOperandInformation) != &o) {
        hidl_u.inputOperandInformation = std::move(o);
    }
}

::android::hardware::neuralnetworks::V1_2::FmqRequestDatum::OperandInformation& (::android::hardware::neuralnetworks::V1_2::FmqRequestDatum::inputOperandInformation)() {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::inputOperandInformation)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::inputOperandInformation));
    }

    return hidl_u.inputOperandInformation;
}

const ::android::hardware::neuralnetworks::V1_2::FmqRequestDatum::OperandInformation& (::android::hardware::neuralnetworks::V1_2::FmqRequestDatum::inputOperandInformation)() const {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::inputOperandInformation)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::inputOperandInformation));
    }

    return hidl_u.inputOperandInformation;
}

void ::android::hardware::neuralnetworks::V1_2::FmqRequestDatum::inputOperandDimensionValue(uint32_t o) {
    if (hidl_d != hidl_discriminator::inputOperandDimensionValue) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.inputOperandDimensionValue) uint32_t(o);
        hidl_d = hidl_discriminator::inputOperandDimensionValue;
    }
    else if (&(hidl_u.inputOperandDimensionValue) != &o) {
        hidl_u.inputOperandDimensionValue = o;
    }
}

uint32_t& (::android::hardware::neuralnetworks::V1_2::FmqRequestDatum::inputOperandDimensionValue)() {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::inputOperandDimensionValue)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::inputOperandDimensionValue));
    }

    return hidl_u.inputOperandDimensionValue;
}

uint32_t (::android::hardware::neuralnetworks::V1_2::FmqRequestDatum::inputOperandDimensionValue)() const {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::inputOperandDimensionValue)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::inputOperandDimensionValue));
    }

    return hidl_u.inputOperandDimensionValue;
}

void ::android::hardware::neuralnetworks::V1_2::FmqRequestDatum::outputOperandInformation(const ::android::hardware::neuralnetworks::V1_2::FmqRequestDatum::OperandInformation& o) {
    if (hidl_d != hidl_discriminator::outputOperandInformation) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.outputOperandInformation) ::android::hardware::neuralnetworks::V1_2::FmqRequestDatum::OperandInformation(o);
        hidl_d = hidl_discriminator::outputOperandInformation;
    }
    else if (&(hidl_u.outputOperandInformation) != &o) {
        hidl_u.outputOperandInformation = o;
    }
}

void ::android::hardware::neuralnetworks::V1_2::FmqRequestDatum::outputOperandInformation(::android::hardware::neuralnetworks::V1_2::FmqRequestDatum::OperandInformation&& o) {
    if (hidl_d != hidl_discriminator::outputOperandInformation) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.outputOperandInformation) ::android::hardware::neuralnetworks::V1_2::FmqRequestDatum::OperandInformation(std::move(o));
        hidl_d = hidl_discriminator::outputOperandInformation;
    }
    else if (&(hidl_u.outputOperandInformation) != &o) {
        hidl_u.outputOperandInformation = std::move(o);
    }
}

::android::hardware::neuralnetworks::V1_2::FmqRequestDatum::OperandInformation& (::android::hardware::neuralnetworks::V1_2::FmqRequestDatum::outputOperandInformation)() {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::outputOperandInformation)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::outputOperandInformation));
    }

    return hidl_u.outputOperandInformation;
}

const ::android::hardware::neuralnetworks::V1_2::FmqRequestDatum::OperandInformation& (::android::hardware::neuralnetworks::V1_2::FmqRequestDatum::outputOperandInformation)() const {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::outputOperandInformation)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::outputOperandInformation));
    }

    return hidl_u.outputOperandInformation;
}

void ::android::hardware::neuralnetworks::V1_2::FmqRequestDatum::outputOperandDimensionValue(uint32_t o) {
    if (hidl_d != hidl_discriminator::outputOperandDimensionValue) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.outputOperandDimensionValue) uint32_t(o);
        hidl_d = hidl_discriminator::outputOperandDimensionValue;
    }
    else if (&(hidl_u.outputOperandDimensionValue) != &o) {
        hidl_u.outputOperandDimensionValue = o;
    }
}

uint32_t& (::android::hardware::neuralnetworks::V1_2::FmqRequestDatum::outputOperandDimensionValue)() {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::outputOperandDimensionValue)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::outputOperandDimensionValue));
    }

    return hidl_u.outputOperandDimensionValue;
}

uint32_t (::android::hardware::neuralnetworks::V1_2::FmqRequestDatum::outputOperandDimensionValue)() const {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::outputOperandDimensionValue)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::outputOperandDimensionValue));
    }

    return hidl_u.outputOperandDimensionValue;
}

void ::android::hardware::neuralnetworks::V1_2::FmqRequestDatum::poolIdentifier(int32_t o) {
    if (hidl_d != hidl_discriminator::poolIdentifier) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.poolIdentifier) int32_t(o);
        hidl_d = hidl_discriminator::poolIdentifier;
    }
    else if (&(hidl_u.poolIdentifier) != &o) {
        hidl_u.poolIdentifier = o;
    }
}

int32_t& (::android::hardware::neuralnetworks::V1_2::FmqRequestDatum::poolIdentifier)() {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::poolIdentifier)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::poolIdentifier));
    }

    return hidl_u.poolIdentifier;
}

int32_t (::android::hardware::neuralnetworks::V1_2::FmqRequestDatum::poolIdentifier)() const {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::poolIdentifier)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::poolIdentifier));
    }

    return hidl_u.poolIdentifier;
}

void ::android::hardware::neuralnetworks::V1_2::FmqRequestDatum::measureTiming(::android::hardware::neuralnetworks::V1_2::MeasureTiming o) {
    if (hidl_d != hidl_discriminator::measureTiming) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.measureTiming) ::android::hardware::neuralnetworks::V1_2::MeasureTiming(o);
        hidl_d = hidl_discriminator::measureTiming;
    }
    else if (&(hidl_u.measureTiming) != &o) {
        hidl_u.measureTiming = o;
    }
}

::android::hardware::neuralnetworks::V1_2::MeasureTiming& (::android::hardware::neuralnetworks::V1_2::FmqRequestDatum::measureTiming)() {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::measureTiming)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::measureTiming));
    }

    return hidl_u.measureTiming;
}

::android::hardware::neuralnetworks::V1_2::MeasureTiming (::android::hardware::neuralnetworks::V1_2::FmqRequestDatum::measureTiming)() const {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::measureTiming)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::measureTiming));
    }

    return hidl_u.measureTiming;
}

::android::hardware::neuralnetworks::V1_2::FmqRequestDatum::hidl_union::hidl_union() {}

::android::hardware::neuralnetworks::V1_2::FmqRequestDatum::hidl_union::~hidl_union() {}

::android::hardware::neuralnetworks::V1_2::FmqRequestDatum::hidl_discriminator (::android::hardware::neuralnetworks::V1_2::FmqRequestDatum::getDiscriminator)() const {
    return hidl_d;
}

::android::hardware::neuralnetworks::V1_2::FmqResultDatum::FmqResultDatum() {
    static_assert(offsetof(::android::hardware::neuralnetworks::V1_2::FmqResultDatum, hidl_d) == 0, "wrong offset");
    static_assert(offsetof(::android::hardware::neuralnetworks::V1_2::FmqResultDatum, hidl_u) == 8, "wrong offset");

    ::std::memset(&hidl_u, 0, sizeof(hidl_u));
    ::std::memset(reinterpret_cast<uint8_t*>(this) + 1, 0, 7);
    // no padding to zero starting at offset 24

    hidl_d = hidl_discriminator::packetInformation;
    new (&hidl_u.packetInformation) ::android::hardware::neuralnetworks::V1_2::FmqResultDatum::PacketInformation();
}

::android::hardware::neuralnetworks::V1_2::FmqResultDatum::~FmqResultDatum() {
    hidl_destructUnion();
}

::android::hardware::neuralnetworks::V1_2::FmqResultDatum::FmqResultDatum(FmqResultDatum&& other) : ::android::hardware::neuralnetworks::V1_2::FmqResultDatum() {
    *this = std::move(other);
}

::android::hardware::neuralnetworks::V1_2::FmqResultDatum::FmqResultDatum(const FmqResultDatum& other) : ::android::hardware::neuralnetworks::V1_2::FmqResultDatum() {
    *this = other;
}

::android::hardware::neuralnetworks::V1_2::FmqResultDatum& (::android::hardware::neuralnetworks::V1_2::FmqResultDatum::operator=)(FmqResultDatum&& other) {
    if (this == &other) { return *this; }

    switch (other.hidl_d) {
        case hidl_discriminator::packetInformation: {
            packetInformation(std::move(other.hidl_u.packetInformation));
            break;
        }
        case hidl_discriminator::operandInformation: {
            operandInformation(std::move(other.hidl_u.operandInformation));
            break;
        }
        case hidl_discriminator::operandDimensionValue: {
            operandDimensionValue(std::move(other.hidl_u.operandDimensionValue));
            break;
        }
        case hidl_discriminator::executionTiming: {
            executionTiming(std::move(other.hidl_u.executionTiming));
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

::android::hardware::neuralnetworks::V1_2::FmqResultDatum& (::android::hardware::neuralnetworks::V1_2::FmqResultDatum::operator=)(const FmqResultDatum& other) {
    if (this == &other) { return *this; }

    switch (other.hidl_d) {
        case hidl_discriminator::packetInformation: {
            packetInformation(other.hidl_u.packetInformation);
            break;
        }
        case hidl_discriminator::operandInformation: {
            operandInformation(other.hidl_u.operandInformation);
            break;
        }
        case hidl_discriminator::operandDimensionValue: {
            operandDimensionValue(other.hidl_u.operandDimensionValue);
            break;
        }
        case hidl_discriminator::executionTiming: {
            executionTiming(other.hidl_u.executionTiming);
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

void ::android::hardware::neuralnetworks::V1_2::FmqResultDatum::hidl_destructUnion() {
    switch (hidl_d) {
        case hidl_discriminator::packetInformation: {
            ::android::hardware::details::destructElement(&(hidl_u.packetInformation));
            break;
        }
        case hidl_discriminator::operandInformation: {
            ::android::hardware::details::destructElement(&(hidl_u.operandInformation));
            break;
        }
        case hidl_discriminator::operandDimensionValue: {
            ::android::hardware::details::destructElement(&(hidl_u.operandDimensionValue));
            break;
        }
        case hidl_discriminator::executionTiming: {
            ::android::hardware::details::destructElement(&(hidl_u.executionTiming));
            break;
        }
        default: {
            ::android::hardware::details::logAlwaysFatal((
                    "Unknown union discriminator (value: " +
                    std::to_string((uint8_t) hidl_d) + ").").c_str());
        }
    }

}

void ::android::hardware::neuralnetworks::V1_2::FmqResultDatum::packetInformation(const ::android::hardware::neuralnetworks::V1_2::FmqResultDatum::PacketInformation& o) {
    if (hidl_d != hidl_discriminator::packetInformation) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.packetInformation) ::android::hardware::neuralnetworks::V1_2::FmqResultDatum::PacketInformation(o);
        hidl_d = hidl_discriminator::packetInformation;
    }
    else if (&(hidl_u.packetInformation) != &o) {
        hidl_u.packetInformation = o;
    }
}

void ::android::hardware::neuralnetworks::V1_2::FmqResultDatum::packetInformation(::android::hardware::neuralnetworks::V1_2::FmqResultDatum::PacketInformation&& o) {
    if (hidl_d != hidl_discriminator::packetInformation) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.packetInformation) ::android::hardware::neuralnetworks::V1_2::FmqResultDatum::PacketInformation(std::move(o));
        hidl_d = hidl_discriminator::packetInformation;
    }
    else if (&(hidl_u.packetInformation) != &o) {
        hidl_u.packetInformation = std::move(o);
    }
}

::android::hardware::neuralnetworks::V1_2::FmqResultDatum::PacketInformation& (::android::hardware::neuralnetworks::V1_2::FmqResultDatum::packetInformation)() {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::packetInformation)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::packetInformation));
    }

    return hidl_u.packetInformation;
}

const ::android::hardware::neuralnetworks::V1_2::FmqResultDatum::PacketInformation& (::android::hardware::neuralnetworks::V1_2::FmqResultDatum::packetInformation)() const {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::packetInformation)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::packetInformation));
    }

    return hidl_u.packetInformation;
}

void ::android::hardware::neuralnetworks::V1_2::FmqResultDatum::operandInformation(const ::android::hardware::neuralnetworks::V1_2::FmqResultDatum::OperandInformation& o) {
    if (hidl_d != hidl_discriminator::operandInformation) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.operandInformation) ::android::hardware::neuralnetworks::V1_2::FmqResultDatum::OperandInformation(o);
        hidl_d = hidl_discriminator::operandInformation;
    }
    else if (&(hidl_u.operandInformation) != &o) {
        hidl_u.operandInformation = o;
    }
}

void ::android::hardware::neuralnetworks::V1_2::FmqResultDatum::operandInformation(::android::hardware::neuralnetworks::V1_2::FmqResultDatum::OperandInformation&& o) {
    if (hidl_d != hidl_discriminator::operandInformation) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.operandInformation) ::android::hardware::neuralnetworks::V1_2::FmqResultDatum::OperandInformation(std::move(o));
        hidl_d = hidl_discriminator::operandInformation;
    }
    else if (&(hidl_u.operandInformation) != &o) {
        hidl_u.operandInformation = std::move(o);
    }
}

::android::hardware::neuralnetworks::V1_2::FmqResultDatum::OperandInformation& (::android::hardware::neuralnetworks::V1_2::FmqResultDatum::operandInformation)() {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::operandInformation)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::operandInformation));
    }

    return hidl_u.operandInformation;
}

const ::android::hardware::neuralnetworks::V1_2::FmqResultDatum::OperandInformation& (::android::hardware::neuralnetworks::V1_2::FmqResultDatum::operandInformation)() const {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::operandInformation)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::operandInformation));
    }

    return hidl_u.operandInformation;
}

void ::android::hardware::neuralnetworks::V1_2::FmqResultDatum::operandDimensionValue(uint32_t o) {
    if (hidl_d != hidl_discriminator::operandDimensionValue) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.operandDimensionValue) uint32_t(o);
        hidl_d = hidl_discriminator::operandDimensionValue;
    }
    else if (&(hidl_u.operandDimensionValue) != &o) {
        hidl_u.operandDimensionValue = o;
    }
}

uint32_t& (::android::hardware::neuralnetworks::V1_2::FmqResultDatum::operandDimensionValue)() {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::operandDimensionValue)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::operandDimensionValue));
    }

    return hidl_u.operandDimensionValue;
}

uint32_t (::android::hardware::neuralnetworks::V1_2::FmqResultDatum::operandDimensionValue)() const {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::operandDimensionValue)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::operandDimensionValue));
    }

    return hidl_u.operandDimensionValue;
}

void ::android::hardware::neuralnetworks::V1_2::FmqResultDatum::executionTiming(const ::android::hardware::neuralnetworks::V1_2::Timing& o) {
    if (hidl_d != hidl_discriminator::executionTiming) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.executionTiming) ::android::hardware::neuralnetworks::V1_2::Timing(o);
        hidl_d = hidl_discriminator::executionTiming;
    }
    else if (&(hidl_u.executionTiming) != &o) {
        hidl_u.executionTiming = o;
    }
}

void ::android::hardware::neuralnetworks::V1_2::FmqResultDatum::executionTiming(::android::hardware::neuralnetworks::V1_2::Timing&& o) {
    if (hidl_d != hidl_discriminator::executionTiming) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.executionTiming) ::android::hardware::neuralnetworks::V1_2::Timing(std::move(o));
        hidl_d = hidl_discriminator::executionTiming;
    }
    else if (&(hidl_u.executionTiming) != &o) {
        hidl_u.executionTiming = std::move(o);
    }
}

::android::hardware::neuralnetworks::V1_2::Timing& (::android::hardware::neuralnetworks::V1_2::FmqResultDatum::executionTiming)() {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::executionTiming)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::executionTiming));
    }

    return hidl_u.executionTiming;
}

const ::android::hardware::neuralnetworks::V1_2::Timing& (::android::hardware::neuralnetworks::V1_2::FmqResultDatum::executionTiming)() const {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::executionTiming)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::executionTiming));
    }

    return hidl_u.executionTiming;
}

::android::hardware::neuralnetworks::V1_2::FmqResultDatum::hidl_union::hidl_union() {}

::android::hardware::neuralnetworks::V1_2::FmqResultDatum::hidl_union::~hidl_union() {}

::android::hardware::neuralnetworks::V1_2::FmqResultDatum::hidl_discriminator (::android::hardware::neuralnetworks::V1_2::FmqResultDatum::getDiscriminator)() const {
    return hidl_d;
}

::android::status_t readEmbeddedFromParcel(
        const Extension &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.name),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::neuralnetworks::V1_2::Extension, name));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_operandTypes_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::neuralnetworks::V1_2::Extension::OperandTypeInformation> &>(obj.operandTypes),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::neuralnetworks::V1_2::Extension, operandTypes), &_hidl_operandTypes_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const Extension &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.name,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::neuralnetworks::V1_2::Extension, name));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_operandTypes_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.operandTypes,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::neuralnetworks::V1_2::Extension, operandTypes), &_hidl_operandTypes_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

static_assert(sizeof(::android::hardware::MQDescriptor<char, ::android::hardware::kSynchronizedReadWrite>) == 32, "wrong size");
static_assert(sizeof(::android::hardware::hidl_handle) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_memory) == 40, "wrong size");
static_assert(sizeof(::android::hardware::hidl_string) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_vec<char>) == 16, "wrong size");

}  // namespace V1_2
}  // namespace neuralnetworks
}  // namespace hardware
}  // namespace android
