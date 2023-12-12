#define LOG_TAG "android.hardware.neuralnetworks@1.1::types"

#include <log/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <hidl/Static.h>
#include <hwbinder/ProcessState.h>
#include <utils/Trace.h>
#include <android/hardware/neuralnetworks/1.1/types.h>
#include <android/hardware/neuralnetworks/1.1/hwtypes.h>

namespace android {
namespace hardware {
namespace neuralnetworks {
namespace V1_1 {

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
            parentOffset + offsetof(::android::hardware::neuralnetworks::V1_1::Operation, inputs), &_hidl_inputs_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_outputs_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint32_t> &>(obj.outputs),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::neuralnetworks::V1_1::Operation, outputs), &_hidl_outputs_child);

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
            parentOffset + offsetof(::android::hardware::neuralnetworks::V1_1::Operation, inputs), &_hidl_inputs_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_outputs_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.outputs,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::neuralnetworks::V1_1::Operation, outputs), &_hidl_outputs_child);

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
            const_cast<::android::hardware::hidl_vec<::android::hardware::neuralnetworks::V1_0::Operand> &>(obj.operands),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::neuralnetworks::V1_1::Model, operands), &_hidl_operands_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.operands.size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::neuralnetworks::V1_0::Operand &>(obj.operands[_hidl_index_0]),
                parcel,
                _hidl_operands_child,
                _hidl_index_0 * sizeof(::android::hardware::neuralnetworks::V1_0::Operand));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    size_t _hidl_operations_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::neuralnetworks::V1_1::Operation> &>(obj.operations),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::neuralnetworks::V1_1::Model, operations), &_hidl_operations_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.operations.size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::neuralnetworks::V1_1::Operation &>(obj.operations[_hidl_index_0]),
                parcel,
                _hidl_operations_child,
                _hidl_index_0 * sizeof(::android::hardware::neuralnetworks::V1_1::Operation));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    size_t _hidl_inputIndexes_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint32_t> &>(obj.inputIndexes),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::neuralnetworks::V1_1::Model, inputIndexes), &_hidl_inputIndexes_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_outputIndexes_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint32_t> &>(obj.outputIndexes),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::neuralnetworks::V1_1::Model, outputIndexes), &_hidl_outputIndexes_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_operandValues_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(obj.operandValues),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::neuralnetworks::V1_1::Model, operandValues), &_hidl_operandValues_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_pools_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::hidl_memory> &>(obj.pools),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::neuralnetworks::V1_1::Model, pools), &_hidl_pools_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.pools.size(); ++_hidl_index_0) {
        _hidl_err = ::android::hardware::readEmbeddedFromParcel(
                const_cast<::android::hardware::hidl_memory &>(obj.pools[_hidl_index_0]),
                parcel,
                _hidl_pools_child,
                _hidl_index_0 * sizeof(::android::hardware::hidl_memory));

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
            parentOffset + offsetof(::android::hardware::neuralnetworks::V1_1::Model, operands), &_hidl_operands_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.operands.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                obj.operands[_hidl_index_0],
                parcel,
                _hidl_operands_child,
                _hidl_index_0 * sizeof(::android::hardware::neuralnetworks::V1_0::Operand));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    size_t _hidl_operations_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.operations,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::neuralnetworks::V1_1::Model, operations), &_hidl_operations_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.operations.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                obj.operations[_hidl_index_0],
                parcel,
                _hidl_operations_child,
                _hidl_index_0 * sizeof(::android::hardware::neuralnetworks::V1_1::Operation));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    size_t _hidl_inputIndexes_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.inputIndexes,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::neuralnetworks::V1_1::Model, inputIndexes), &_hidl_inputIndexes_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_outputIndexes_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.outputIndexes,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::neuralnetworks::V1_1::Model, outputIndexes), &_hidl_outputIndexes_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_operandValues_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.operandValues,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::neuralnetworks::V1_1::Model, operandValues), &_hidl_operandValues_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_pools_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.pools,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::neuralnetworks::V1_1::Model, pools), &_hidl_pools_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.pools.size(); ++_hidl_index_0) {
        _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                obj.pools[_hidl_index_0],
                parcel,
                _hidl_pools_child,
                _hidl_index_0 * sizeof(::android::hardware::hidl_memory));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    return _hidl_err;
}

static_assert(sizeof(::android::hardware::MQDescriptor<char, ::android::hardware::kSynchronizedReadWrite>) == 32, "wrong size");
static_assert(sizeof(::android::hardware::hidl_handle) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_memory) == 40, "wrong size");
static_assert(sizeof(::android::hardware::hidl_string) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_vec<char>) == 16, "wrong size");

}  // namespace V1_1
}  // namespace neuralnetworks
}  // namespace hardware
}  // namespace android
