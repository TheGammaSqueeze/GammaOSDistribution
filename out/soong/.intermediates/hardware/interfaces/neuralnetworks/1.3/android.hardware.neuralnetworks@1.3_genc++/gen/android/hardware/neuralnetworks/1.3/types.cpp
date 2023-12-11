#define LOG_TAG "android.hardware.neuralnetworks@1.3::types"

#include <log/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <hidl/Static.h>
#include <hwbinder/ProcessState.h>
#include <utils/Trace.h>
#include <android/hardware/neuralnetworks/1.3/types.h>
#include <android/hardware/neuralnetworks/1.3/hwtypes.h>

namespace android {
namespace hardware {
namespace neuralnetworks {
namespace V1_3 {

::android::status_t readEmbeddedFromParcel(
        const Capabilities &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_operandPerformance_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::neuralnetworks::V1_3::Capabilities::OperandPerformance> &>(obj.operandPerformance),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::neuralnetworks::V1_3::Capabilities, operandPerformance), &_hidl_operandPerformance_child);

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
            parentOffset + offsetof(::android::hardware::neuralnetworks::V1_3::Capabilities, operandPerformance), &_hidl_operandPerformance_child);

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
            parentOffset + offsetof(::android::hardware::neuralnetworks::V1_3::Operation, inputs), &_hidl_inputs_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_outputs_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint32_t> &>(obj.outputs),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::neuralnetworks::V1_3::Operation, outputs), &_hidl_outputs_child);

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
            parentOffset + offsetof(::android::hardware::neuralnetworks::V1_3::Operation, inputs), &_hidl_inputs_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_outputs_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.outputs,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::neuralnetworks::V1_3::Operation, outputs), &_hidl_outputs_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
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
            parentOffset + offsetof(::android::hardware::neuralnetworks::V1_3::Operand, dimensions), &_hidl_dimensions_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::neuralnetworks::V1_2::Operand::ExtraParams &>(obj.extraParams),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::neuralnetworks::V1_3::Operand, extraParams));

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
            parentOffset + offsetof(::android::hardware::neuralnetworks::V1_3::Operand, dimensions), &_hidl_dimensions_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = writeEmbeddedToParcel(
            obj.extraParams,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::neuralnetworks::V1_3::Operand, extraParams));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const Subgraph &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_operands_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::neuralnetworks::V1_3::Operand> &>(obj.operands),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::neuralnetworks::V1_3::Subgraph, operands), &_hidl_operands_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.operands.size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::neuralnetworks::V1_3::Operand &>(obj.operands[_hidl_index_0]),
                parcel,
                _hidl_operands_child,
                _hidl_index_0 * sizeof(::android::hardware::neuralnetworks::V1_3::Operand));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    size_t _hidl_operations_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::neuralnetworks::V1_3::Operation> &>(obj.operations),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::neuralnetworks::V1_3::Subgraph, operations), &_hidl_operations_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.operations.size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::neuralnetworks::V1_3::Operation &>(obj.operations[_hidl_index_0]),
                parcel,
                _hidl_operations_child,
                _hidl_index_0 * sizeof(::android::hardware::neuralnetworks::V1_3::Operation));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    size_t _hidl_inputIndexes_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint32_t> &>(obj.inputIndexes),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::neuralnetworks::V1_3::Subgraph, inputIndexes), &_hidl_inputIndexes_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_outputIndexes_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint32_t> &>(obj.outputIndexes),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::neuralnetworks::V1_3::Subgraph, outputIndexes), &_hidl_outputIndexes_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const Subgraph &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_operands_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.operands,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::neuralnetworks::V1_3::Subgraph, operands), &_hidl_operands_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.operands.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                obj.operands[_hidl_index_0],
                parcel,
                _hidl_operands_child,
                _hidl_index_0 * sizeof(::android::hardware::neuralnetworks::V1_3::Operand));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    size_t _hidl_operations_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.operations,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::neuralnetworks::V1_3::Subgraph, operations), &_hidl_operations_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.operations.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                obj.operations[_hidl_index_0],
                parcel,
                _hidl_operations_child,
                _hidl_index_0 * sizeof(::android::hardware::neuralnetworks::V1_3::Operation));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    size_t _hidl_inputIndexes_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.inputIndexes,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::neuralnetworks::V1_3::Subgraph, inputIndexes), &_hidl_inputIndexes_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_outputIndexes_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.outputIndexes,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::neuralnetworks::V1_3::Subgraph, outputIndexes), &_hidl_outputIndexes_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const Model &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::neuralnetworks::V1_3::Subgraph &>(obj.main),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::neuralnetworks::V1_3::Model, main));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_referenced_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::neuralnetworks::V1_3::Subgraph> &>(obj.referenced),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::neuralnetworks::V1_3::Model, referenced), &_hidl_referenced_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.referenced.size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::neuralnetworks::V1_3::Subgraph &>(obj.referenced[_hidl_index_0]),
                parcel,
                _hidl_referenced_child,
                _hidl_index_0 * sizeof(::android::hardware::neuralnetworks::V1_3::Subgraph));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    size_t _hidl_operandValues_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(obj.operandValues),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::neuralnetworks::V1_3::Model, operandValues), &_hidl_operandValues_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_pools_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::hidl_memory> &>(obj.pools),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::neuralnetworks::V1_3::Model, pools), &_hidl_pools_child);

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
            parentOffset + offsetof(::android::hardware::neuralnetworks::V1_3::Model, extensionNameToPrefix), &_hidl_extensionNameToPrefix_child);

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

    _hidl_err = writeEmbeddedToParcel(
            obj.main,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::neuralnetworks::V1_3::Model, main));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_referenced_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.referenced,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::neuralnetworks::V1_3::Model, referenced), &_hidl_referenced_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.referenced.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                obj.referenced[_hidl_index_0],
                parcel,
                _hidl_referenced_child,
                _hidl_index_0 * sizeof(::android::hardware::neuralnetworks::V1_3::Subgraph));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    size_t _hidl_operandValues_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.operandValues,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::neuralnetworks::V1_3::Model, operandValues), &_hidl_operandValues_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_pools_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.pools,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::neuralnetworks::V1_3::Model, pools), &_hidl_pools_child);

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
            parentOffset + offsetof(::android::hardware::neuralnetworks::V1_3::Model, extensionNameToPrefix), &_hidl_extensionNameToPrefix_child);

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
        const BufferDesc &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_dimensions_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint32_t> &>(obj.dimensions),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::neuralnetworks::V1_3::BufferDesc, dimensions), &_hidl_dimensions_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const BufferDesc &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_dimensions_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.dimensions,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::neuralnetworks::V1_3::BufferDesc, dimensions), &_hidl_dimensions_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const Request::MemoryPool &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    switch (obj.getDiscriminator()) {
        case ::android::hardware::neuralnetworks::V1_3::Request::MemoryPool::hidl_discriminator::hidlMemory: {
            _hidl_err = ::android::hardware::readEmbeddedFromParcel(
                    const_cast<::android::hardware::hidl_memory &>(obj.hidlMemory()),
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
        const Request::MemoryPool &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    switch (obj.getDiscriminator()) {
        case ::android::hardware::neuralnetworks::V1_3::Request::MemoryPool::hidl_discriminator::hidlMemory: {
            _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                    obj.hidlMemory(),
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

::android::hardware::neuralnetworks::V1_3::Request::MemoryPool::MemoryPool() {
    static_assert(offsetof(::android::hardware::neuralnetworks::V1_3::Request::MemoryPool, hidl_d) == 0, "wrong offset");
    static_assert(offsetof(::android::hardware::neuralnetworks::V1_3::Request::MemoryPool, hidl_u) == 8, "wrong offset");

    ::std::memset(&hidl_u, 0, sizeof(hidl_u));
    ::std::memset(reinterpret_cast<uint8_t*>(this) + 1, 0, 7);
    // no padding to zero starting at offset 48

    hidl_d = hidl_discriminator::hidlMemory;
    new (&hidl_u.hidlMemory) ::android::hardware::hidl_memory();
}

::android::hardware::neuralnetworks::V1_3::Request::MemoryPool::~MemoryPool() {
    hidl_destructUnion();
}

::android::hardware::neuralnetworks::V1_3::Request::MemoryPool::MemoryPool(MemoryPool&& other) : ::android::hardware::neuralnetworks::V1_3::Request::MemoryPool() {
    *this = std::move(other);
}

::android::hardware::neuralnetworks::V1_3::Request::MemoryPool::MemoryPool(const MemoryPool& other) : ::android::hardware::neuralnetworks::V1_3::Request::MemoryPool() {
    *this = other;
}

::android::hardware::neuralnetworks::V1_3::Request::MemoryPool& (::android::hardware::neuralnetworks::V1_3::Request::MemoryPool::operator=)(MemoryPool&& other) {
    if (this == &other) { return *this; }

    switch (other.hidl_d) {
        case hidl_discriminator::hidlMemory: {
            hidlMemory(std::move(other.hidl_u.hidlMemory));
            break;
        }
        case hidl_discriminator::token: {
            token(std::move(other.hidl_u.token));
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

::android::hardware::neuralnetworks::V1_3::Request::MemoryPool& (::android::hardware::neuralnetworks::V1_3::Request::MemoryPool::operator=)(const MemoryPool& other) {
    if (this == &other) { return *this; }

    switch (other.hidl_d) {
        case hidl_discriminator::hidlMemory: {
            hidlMemory(other.hidl_u.hidlMemory);
            break;
        }
        case hidl_discriminator::token: {
            token(other.hidl_u.token);
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

void ::android::hardware::neuralnetworks::V1_3::Request::MemoryPool::hidl_destructUnion() {
    switch (hidl_d) {
        case hidl_discriminator::hidlMemory: {
            ::android::hardware::details::destructElement(&(hidl_u.hidlMemory));
            break;
        }
        case hidl_discriminator::token: {
            ::android::hardware::details::destructElement(&(hidl_u.token));
            break;
        }
        default: {
            ::android::hardware::details::logAlwaysFatal((
                    "Unknown union discriminator (value: " +
                    std::to_string((uint8_t) hidl_d) + ").").c_str());
        }
    }

}

void ::android::hardware::neuralnetworks::V1_3::Request::MemoryPool::hidlMemory(const ::android::hardware::hidl_memory& o) {
    if (hidl_d != hidl_discriminator::hidlMemory) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.hidlMemory) ::android::hardware::hidl_memory(o);
        hidl_d = hidl_discriminator::hidlMemory;
    }
    else if (&(hidl_u.hidlMemory) != &o) {
        hidl_u.hidlMemory = o;
    }
}

void ::android::hardware::neuralnetworks::V1_3::Request::MemoryPool::hidlMemory(::android::hardware::hidl_memory&& o) {
    if (hidl_d != hidl_discriminator::hidlMemory) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.hidlMemory) ::android::hardware::hidl_memory(std::move(o));
        hidl_d = hidl_discriminator::hidlMemory;
    }
    else if (&(hidl_u.hidlMemory) != &o) {
        hidl_u.hidlMemory = std::move(o);
    }
}

::android::hardware::hidl_memory& (::android::hardware::neuralnetworks::V1_3::Request::MemoryPool::hidlMemory)() {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::hidlMemory)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::hidlMemory));
    }

    return hidl_u.hidlMemory;
}

const ::android::hardware::hidl_memory& (::android::hardware::neuralnetworks::V1_3::Request::MemoryPool::hidlMemory)() const {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::hidlMemory)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::hidlMemory));
    }

    return hidl_u.hidlMemory;
}

void ::android::hardware::neuralnetworks::V1_3::Request::MemoryPool::token(uint32_t o) {
    if (hidl_d != hidl_discriminator::token) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.token) uint32_t(o);
        hidl_d = hidl_discriminator::token;
    }
    else if (&(hidl_u.token) != &o) {
        hidl_u.token = o;
    }
}

uint32_t& (::android::hardware::neuralnetworks::V1_3::Request::MemoryPool::token)() {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::token)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::token));
    }

    return hidl_u.token;
}

uint32_t (::android::hardware::neuralnetworks::V1_3::Request::MemoryPool::token)() const {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::token)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::token));
    }

    return hidl_u.token;
}

::android::hardware::neuralnetworks::V1_3::Request::MemoryPool::hidl_union::hidl_union() {}

::android::hardware::neuralnetworks::V1_3::Request::MemoryPool::hidl_union::~hidl_union() {}

::android::hardware::neuralnetworks::V1_3::Request::MemoryPool::hidl_discriminator (::android::hardware::neuralnetworks::V1_3::Request::MemoryPool::getDiscriminator)() const {
    return hidl_d;
}

::android::status_t readEmbeddedFromParcel(
        const Request &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_inputs_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::neuralnetworks::V1_0::RequestArgument> &>(obj.inputs),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::neuralnetworks::V1_3::Request, inputs), &_hidl_inputs_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.inputs.size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::neuralnetworks::V1_0::RequestArgument &>(obj.inputs[_hidl_index_0]),
                parcel,
                _hidl_inputs_child,
                _hidl_index_0 * sizeof(::android::hardware::neuralnetworks::V1_0::RequestArgument));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    size_t _hidl_outputs_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::neuralnetworks::V1_0::RequestArgument> &>(obj.outputs),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::neuralnetworks::V1_3::Request, outputs), &_hidl_outputs_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.outputs.size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::neuralnetworks::V1_0::RequestArgument &>(obj.outputs[_hidl_index_0]),
                parcel,
                _hidl_outputs_child,
                _hidl_index_0 * sizeof(::android::hardware::neuralnetworks::V1_0::RequestArgument));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    size_t _hidl_pools_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::neuralnetworks::V1_3::Request::MemoryPool> &>(obj.pools),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::neuralnetworks::V1_3::Request, pools), &_hidl_pools_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.pools.size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::neuralnetworks::V1_3::Request::MemoryPool &>(obj.pools[_hidl_index_0]),
                parcel,
                _hidl_pools_child,
                _hidl_index_0 * sizeof(::android::hardware::neuralnetworks::V1_3::Request::MemoryPool));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const Request &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_inputs_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.inputs,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::neuralnetworks::V1_3::Request, inputs), &_hidl_inputs_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.inputs.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                obj.inputs[_hidl_index_0],
                parcel,
                _hidl_inputs_child,
                _hidl_index_0 * sizeof(::android::hardware::neuralnetworks::V1_0::RequestArgument));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    size_t _hidl_outputs_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.outputs,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::neuralnetworks::V1_3::Request, outputs), &_hidl_outputs_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.outputs.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                obj.outputs[_hidl_index_0],
                parcel,
                _hidl_outputs_child,
                _hidl_index_0 * sizeof(::android::hardware::neuralnetworks::V1_0::RequestArgument));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    size_t _hidl_pools_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.pools,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::neuralnetworks::V1_3::Request, pools), &_hidl_pools_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.pools.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                obj.pools[_hidl_index_0],
                parcel,
                _hidl_pools_child,
                _hidl_index_0 * sizeof(::android::hardware::neuralnetworks::V1_3::Request::MemoryPool));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    return _hidl_err;
}

::android::hardware::neuralnetworks::V1_3::OptionalTimePoint::OptionalTimePoint() {
    static_assert(offsetof(::android::hardware::neuralnetworks::V1_3::OptionalTimePoint, hidl_d) == 0, "wrong offset");
    static_assert(offsetof(::android::hardware::neuralnetworks::V1_3::OptionalTimePoint, hidl_u) == 8, "wrong offset");

    ::std::memset(&hidl_u, 0, sizeof(hidl_u));
    ::std::memset(reinterpret_cast<uint8_t*>(this) + 1, 0, 7);
    // no padding to zero starting at offset 16

    hidl_d = hidl_discriminator::none;
    new (&hidl_u.none) ::android::hidl::safe_union::V1_0::Monostate();
}

::android::hardware::neuralnetworks::V1_3::OptionalTimePoint::~OptionalTimePoint() {
    hidl_destructUnion();
}

::android::hardware::neuralnetworks::V1_3::OptionalTimePoint::OptionalTimePoint(OptionalTimePoint&& other) : ::android::hardware::neuralnetworks::V1_3::OptionalTimePoint() {
    *this = std::move(other);
}

::android::hardware::neuralnetworks::V1_3::OptionalTimePoint::OptionalTimePoint(const OptionalTimePoint& other) : ::android::hardware::neuralnetworks::V1_3::OptionalTimePoint() {
    *this = other;
}

::android::hardware::neuralnetworks::V1_3::OptionalTimePoint& (::android::hardware::neuralnetworks::V1_3::OptionalTimePoint::operator=)(OptionalTimePoint&& other) {
    if (this == &other) { return *this; }

    switch (other.hidl_d) {
        case hidl_discriminator::none: {
            none(std::move(other.hidl_u.none));
            break;
        }
        case hidl_discriminator::nanosecondsSinceEpoch: {
            nanosecondsSinceEpoch(std::move(other.hidl_u.nanosecondsSinceEpoch));
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

::android::hardware::neuralnetworks::V1_3::OptionalTimePoint& (::android::hardware::neuralnetworks::V1_3::OptionalTimePoint::operator=)(const OptionalTimePoint& other) {
    if (this == &other) { return *this; }

    switch (other.hidl_d) {
        case hidl_discriminator::none: {
            none(other.hidl_u.none);
            break;
        }
        case hidl_discriminator::nanosecondsSinceEpoch: {
            nanosecondsSinceEpoch(other.hidl_u.nanosecondsSinceEpoch);
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

void ::android::hardware::neuralnetworks::V1_3::OptionalTimePoint::hidl_destructUnion() {
    switch (hidl_d) {
        case hidl_discriminator::none: {
            ::android::hardware::details::destructElement(&(hidl_u.none));
            break;
        }
        case hidl_discriminator::nanosecondsSinceEpoch: {
            ::android::hardware::details::destructElement(&(hidl_u.nanosecondsSinceEpoch));
            break;
        }
        default: {
            ::android::hardware::details::logAlwaysFatal((
                    "Unknown union discriminator (value: " +
                    std::to_string((uint8_t) hidl_d) + ").").c_str());
        }
    }

}

void ::android::hardware::neuralnetworks::V1_3::OptionalTimePoint::none(const ::android::hidl::safe_union::V1_0::Monostate& o) {
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

void ::android::hardware::neuralnetworks::V1_3::OptionalTimePoint::none(::android::hidl::safe_union::V1_0::Monostate&& o) {
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

::android::hidl::safe_union::V1_0::Monostate& (::android::hardware::neuralnetworks::V1_3::OptionalTimePoint::none)() {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::none)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::none));
    }

    return hidl_u.none;
}

const ::android::hidl::safe_union::V1_0::Monostate& (::android::hardware::neuralnetworks::V1_3::OptionalTimePoint::none)() const {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::none)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::none));
    }

    return hidl_u.none;
}

void ::android::hardware::neuralnetworks::V1_3::OptionalTimePoint::nanosecondsSinceEpoch(uint64_t o) {
    if (hidl_d != hidl_discriminator::nanosecondsSinceEpoch) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.nanosecondsSinceEpoch) uint64_t(o);
        hidl_d = hidl_discriminator::nanosecondsSinceEpoch;
    }
    else if (&(hidl_u.nanosecondsSinceEpoch) != &o) {
        hidl_u.nanosecondsSinceEpoch = o;
    }
}

uint64_t& (::android::hardware::neuralnetworks::V1_3::OptionalTimePoint::nanosecondsSinceEpoch)() {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::nanosecondsSinceEpoch)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::nanosecondsSinceEpoch));
    }

    return hidl_u.nanosecondsSinceEpoch;
}

uint64_t (::android::hardware::neuralnetworks::V1_3::OptionalTimePoint::nanosecondsSinceEpoch)() const {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::nanosecondsSinceEpoch)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::nanosecondsSinceEpoch));
    }

    return hidl_u.nanosecondsSinceEpoch;
}

::android::hardware::neuralnetworks::V1_3::OptionalTimePoint::hidl_union::hidl_union() {}

::android::hardware::neuralnetworks::V1_3::OptionalTimePoint::hidl_union::~hidl_union() {}

::android::hardware::neuralnetworks::V1_3::OptionalTimePoint::hidl_discriminator (::android::hardware::neuralnetworks::V1_3::OptionalTimePoint::getDiscriminator)() const {
    return hidl_d;
}

::android::hardware::neuralnetworks::V1_3::OptionalTimeoutDuration::OptionalTimeoutDuration() {
    static_assert(offsetof(::android::hardware::neuralnetworks::V1_3::OptionalTimeoutDuration, hidl_d) == 0, "wrong offset");
    static_assert(offsetof(::android::hardware::neuralnetworks::V1_3::OptionalTimeoutDuration, hidl_u) == 8, "wrong offset");

    ::std::memset(&hidl_u, 0, sizeof(hidl_u));
    ::std::memset(reinterpret_cast<uint8_t*>(this) + 1, 0, 7);
    // no padding to zero starting at offset 16

    hidl_d = hidl_discriminator::none;
    new (&hidl_u.none) ::android::hidl::safe_union::V1_0::Monostate();
}

::android::hardware::neuralnetworks::V1_3::OptionalTimeoutDuration::~OptionalTimeoutDuration() {
    hidl_destructUnion();
}

::android::hardware::neuralnetworks::V1_3::OptionalTimeoutDuration::OptionalTimeoutDuration(OptionalTimeoutDuration&& other) : ::android::hardware::neuralnetworks::V1_3::OptionalTimeoutDuration() {
    *this = std::move(other);
}

::android::hardware::neuralnetworks::V1_3::OptionalTimeoutDuration::OptionalTimeoutDuration(const OptionalTimeoutDuration& other) : ::android::hardware::neuralnetworks::V1_3::OptionalTimeoutDuration() {
    *this = other;
}

::android::hardware::neuralnetworks::V1_3::OptionalTimeoutDuration& (::android::hardware::neuralnetworks::V1_3::OptionalTimeoutDuration::operator=)(OptionalTimeoutDuration&& other) {
    if (this == &other) { return *this; }

    switch (other.hidl_d) {
        case hidl_discriminator::none: {
            none(std::move(other.hidl_u.none));
            break;
        }
        case hidl_discriminator::nanoseconds: {
            nanoseconds(std::move(other.hidl_u.nanoseconds));
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

::android::hardware::neuralnetworks::V1_3::OptionalTimeoutDuration& (::android::hardware::neuralnetworks::V1_3::OptionalTimeoutDuration::operator=)(const OptionalTimeoutDuration& other) {
    if (this == &other) { return *this; }

    switch (other.hidl_d) {
        case hidl_discriminator::none: {
            none(other.hidl_u.none);
            break;
        }
        case hidl_discriminator::nanoseconds: {
            nanoseconds(other.hidl_u.nanoseconds);
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

void ::android::hardware::neuralnetworks::V1_3::OptionalTimeoutDuration::hidl_destructUnion() {
    switch (hidl_d) {
        case hidl_discriminator::none: {
            ::android::hardware::details::destructElement(&(hidl_u.none));
            break;
        }
        case hidl_discriminator::nanoseconds: {
            ::android::hardware::details::destructElement(&(hidl_u.nanoseconds));
            break;
        }
        default: {
            ::android::hardware::details::logAlwaysFatal((
                    "Unknown union discriminator (value: " +
                    std::to_string((uint8_t) hidl_d) + ").").c_str());
        }
    }

}

void ::android::hardware::neuralnetworks::V1_3::OptionalTimeoutDuration::none(const ::android::hidl::safe_union::V1_0::Monostate& o) {
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

void ::android::hardware::neuralnetworks::V1_3::OptionalTimeoutDuration::none(::android::hidl::safe_union::V1_0::Monostate&& o) {
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

::android::hidl::safe_union::V1_0::Monostate& (::android::hardware::neuralnetworks::V1_3::OptionalTimeoutDuration::none)() {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::none)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::none));
    }

    return hidl_u.none;
}

const ::android::hidl::safe_union::V1_0::Monostate& (::android::hardware::neuralnetworks::V1_3::OptionalTimeoutDuration::none)() const {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::none)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::none));
    }

    return hidl_u.none;
}

void ::android::hardware::neuralnetworks::V1_3::OptionalTimeoutDuration::nanoseconds(uint64_t o) {
    if (hidl_d != hidl_discriminator::nanoseconds) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.nanoseconds) uint64_t(o);
        hidl_d = hidl_discriminator::nanoseconds;
    }
    else if (&(hidl_u.nanoseconds) != &o) {
        hidl_u.nanoseconds = o;
    }
}

uint64_t& (::android::hardware::neuralnetworks::V1_3::OptionalTimeoutDuration::nanoseconds)() {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::nanoseconds)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::nanoseconds));
    }

    return hidl_u.nanoseconds;
}

uint64_t (::android::hardware::neuralnetworks::V1_3::OptionalTimeoutDuration::nanoseconds)() const {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::nanoseconds)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::nanoseconds));
    }

    return hidl_u.nanoseconds;
}

::android::hardware::neuralnetworks::V1_3::OptionalTimeoutDuration::hidl_union::hidl_union() {}

::android::hardware::neuralnetworks::V1_3::OptionalTimeoutDuration::hidl_union::~hidl_union() {}

::android::hardware::neuralnetworks::V1_3::OptionalTimeoutDuration::hidl_discriminator (::android::hardware::neuralnetworks::V1_3::OptionalTimeoutDuration::getDiscriminator)() const {
    return hidl_d;
}

static_assert(sizeof(::android::hardware::MQDescriptor<char, ::android::hardware::kSynchronizedReadWrite>) == 32, "wrong size");
static_assert(sizeof(::android::hardware::hidl_handle) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_memory) == 40, "wrong size");
static_assert(sizeof(::android::hardware::hidl_string) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_vec<char>) == 16, "wrong size");

}  // namespace V1_3
}  // namespace neuralnetworks
}  // namespace hardware
}  // namespace android
