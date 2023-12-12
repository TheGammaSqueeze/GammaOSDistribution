#define LOG_TAG "android.hardware.contexthub@1.0::types"

#include <log/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <hidl/Static.h>
#include <hwbinder/ProcessState.h>
#include <utils/Trace.h>
#include <android/hardware/contexthub/1.0/types.h>
#include <android/hardware/contexthub/1.0/hwtypes.h>

namespace android {
namespace hardware {
namespace contexthub {
namespace V1_0 {

::android::status_t readEmbeddedFromParcel(
        const NanoAppBinary &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_customBinary_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(obj.customBinary),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::contexthub::V1_0::NanoAppBinary, customBinary), &_hidl_customBinary_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const NanoAppBinary &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_customBinary_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.customBinary,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::contexthub::V1_0::NanoAppBinary, customBinary), &_hidl_customBinary_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const PhysicalSensor &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.type),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::contexthub::V1_0::PhysicalSensor, type));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.name),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::contexthub::V1_0::PhysicalSensor, name));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.vendor),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::contexthub::V1_0::PhysicalSensor, vendor));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const PhysicalSensor &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.type,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::contexthub::V1_0::PhysicalSensor, type));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.name,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::contexthub::V1_0::PhysicalSensor, name));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.vendor,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::contexthub::V1_0::PhysicalSensor, vendor));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const ContextHub &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.name),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::contexthub::V1_0::ContextHub, name));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.vendor),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::contexthub::V1_0::ContextHub, vendor));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.toolchain),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::contexthub::V1_0::ContextHub, toolchain));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_connectedSensors_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::contexthub::V1_0::PhysicalSensor> &>(obj.connectedSensors),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::contexthub::V1_0::ContextHub, connectedSensors), &_hidl_connectedSensors_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.connectedSensors.size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::contexthub::V1_0::PhysicalSensor &>(obj.connectedSensors[_hidl_index_0]),
                parcel,
                _hidl_connectedSensors_child,
                _hidl_index_0 * sizeof(::android::hardware::contexthub::V1_0::PhysicalSensor));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const ContextHub &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.name,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::contexthub::V1_0::ContextHub, name));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.vendor,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::contexthub::V1_0::ContextHub, vendor));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.toolchain,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::contexthub::V1_0::ContextHub, toolchain));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_connectedSensors_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.connectedSensors,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::contexthub::V1_0::ContextHub, connectedSensors), &_hidl_connectedSensors_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.connectedSensors.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                obj.connectedSensors[_hidl_index_0],
                parcel,
                _hidl_connectedSensors_child,
                _hidl_index_0 * sizeof(::android::hardware::contexthub::V1_0::PhysicalSensor));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const ContextHubMsg &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_msg_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(obj.msg),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::contexthub::V1_0::ContextHubMsg, msg), &_hidl_msg_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const ContextHubMsg &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_msg_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.msg,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::contexthub::V1_0::ContextHubMsg, msg), &_hidl_msg_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const HubAppInfo &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_memUsage_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::contexthub::V1_0::MemRange> &>(obj.memUsage),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::contexthub::V1_0::HubAppInfo, memUsage), &_hidl_memUsage_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const HubAppInfo &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_memUsage_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.memUsage,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::contexthub::V1_0::HubAppInfo, memUsage), &_hidl_memUsage_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

static_assert(sizeof(::android::hardware::MQDescriptor<char, ::android::hardware::kSynchronizedReadWrite>) == 32, "wrong size");
static_assert(sizeof(::android::hardware::hidl_handle) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_memory) == 40, "wrong size");
static_assert(sizeof(::android::hardware::hidl_string) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_vec<char>) == 16, "wrong size");

}  // namespace V1_0
}  // namespace contexthub
}  // namespace hardware
}  // namespace android
