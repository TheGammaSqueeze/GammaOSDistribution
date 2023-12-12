#define LOG_TAG "android.hardware.drm@1.1::types"

#include <log/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <hidl/Static.h>
#include <hwbinder/ProcessState.h>
#include <utils/Trace.h>
#include <android/hardware/drm/1.1/types.h>
#include <android/hardware/drm/1.1/hwtypes.h>

namespace android {
namespace hardware {
namespace drm {
namespace V1_1 {

::android::status_t readEmbeddedFromParcel(
        const DrmMetricGroup::Attribute &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.name),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::drm::V1_1::DrmMetricGroup::Attribute, name));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.stringValue),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::drm::V1_1::DrmMetricGroup::Attribute, stringValue));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const DrmMetricGroup::Attribute &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.name,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::drm::V1_1::DrmMetricGroup::Attribute, name));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.stringValue,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::drm::V1_1::DrmMetricGroup::Attribute, stringValue));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const DrmMetricGroup::Value &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.componentName),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::drm::V1_1::DrmMetricGroup::Value, componentName));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.stringValue),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::drm::V1_1::DrmMetricGroup::Value, stringValue));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const DrmMetricGroup::Value &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.componentName,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::drm::V1_1::DrmMetricGroup::Value, componentName));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.stringValue,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::drm::V1_1::DrmMetricGroup::Value, stringValue));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const DrmMetricGroup::Metric &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.name),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::drm::V1_1::DrmMetricGroup::Metric, name));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_attributes_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::drm::V1_1::DrmMetricGroup::Attribute> &>(obj.attributes),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::drm::V1_1::DrmMetricGroup::Metric, attributes), &_hidl_attributes_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.attributes.size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::drm::V1_1::DrmMetricGroup::Attribute &>(obj.attributes[_hidl_index_0]),
                parcel,
                _hidl_attributes_child,
                _hidl_index_0 * sizeof(::android::hardware::drm::V1_1::DrmMetricGroup::Attribute));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    size_t _hidl_values_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::drm::V1_1::DrmMetricGroup::Value> &>(obj.values),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::drm::V1_1::DrmMetricGroup::Metric, values), &_hidl_values_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.values.size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::drm::V1_1::DrmMetricGroup::Value &>(obj.values[_hidl_index_0]),
                parcel,
                _hidl_values_child,
                _hidl_index_0 * sizeof(::android::hardware::drm::V1_1::DrmMetricGroup::Value));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const DrmMetricGroup::Metric &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.name,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::drm::V1_1::DrmMetricGroup::Metric, name));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    size_t _hidl_attributes_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.attributes,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::drm::V1_1::DrmMetricGroup::Metric, attributes), &_hidl_attributes_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.attributes.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                obj.attributes[_hidl_index_0],
                parcel,
                _hidl_attributes_child,
                _hidl_index_0 * sizeof(::android::hardware::drm::V1_1::DrmMetricGroup::Attribute));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    size_t _hidl_values_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.values,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::drm::V1_1::DrmMetricGroup::Metric, values), &_hidl_values_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.values.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                obj.values[_hidl_index_0],
                parcel,
                _hidl_values_child,
                _hidl_index_0 * sizeof(::android::hardware::drm::V1_1::DrmMetricGroup::Value));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const DrmMetricGroup &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_metrics_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::drm::V1_1::DrmMetricGroup::Metric> &>(obj.metrics),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::drm::V1_1::DrmMetricGroup, metrics), &_hidl_metrics_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.metrics.size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::hardware::drm::V1_1::DrmMetricGroup::Metric &>(obj.metrics[_hidl_index_0]),
                parcel,
                _hidl_metrics_child,
                _hidl_index_0 * sizeof(::android::hardware::drm::V1_1::DrmMetricGroup::Metric));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const DrmMetricGroup &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_metrics_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.metrics,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::drm::V1_1::DrmMetricGroup, metrics), &_hidl_metrics_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.metrics.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                obj.metrics[_hidl_index_0],
                parcel,
                _hidl_metrics_child,
                _hidl_index_0 * sizeof(::android::hardware::drm::V1_1::DrmMetricGroup::Metric));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const SecureStopRelease &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_opaqueData_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(obj.opaqueData),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::drm::V1_1::SecureStopRelease, opaqueData), &_hidl_opaqueData_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const SecureStopRelease &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_opaqueData_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.opaqueData,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::drm::V1_1::SecureStopRelease, opaqueData), &_hidl_opaqueData_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

static_assert(sizeof(::android::hardware::MQDescriptor<char, ::android::hardware::kSynchronizedReadWrite>) == 32, "wrong size");
static_assert(sizeof(::android::hardware::hidl_handle) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_memory) == 40, "wrong size");
static_assert(sizeof(::android::hardware::hidl_string) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_vec<char>) == 16, "wrong size");

}  // namespace V1_1
}  // namespace drm
}  // namespace hardware
}  // namespace android
