#define LOG_TAG "android.frameworks.cameraservice.device@2.0::types"

#include <log/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <hidl/Static.h>
#include <hwbinder/ProcessState.h>
#include <utils/Trace.h>
#include <android/frameworks/cameraservice/device/2.0/types.h>
#include <android/frameworks/cameraservice/device/2.0/hwtypes.h>

namespace android {
namespace frameworks {
namespace cameraservice {
namespace device {
namespace V2_0 {

::android::status_t readEmbeddedFromParcel(
        const FmqSizeOrMetadata &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    switch (obj.getDiscriminator()) {
        case ::android::frameworks::cameraservice::device::V2_0::FmqSizeOrMetadata::hidl_discriminator::metadata: {
            size_t _hidl_metadata_child;

            _hidl_err = ::android::hardware::readEmbeddedFromParcel(
                    const_cast<::android::hardware::hidl_vec<uint8_t> &>(obj.metadata()),
                    parcel,
                    parentHandle,
                    parentOffset + obj.hidl_getUnionOffset() /* safe_union: union offset into struct */, &_hidl_metadata_child);

            if (_hidl_err != ::android::OK) { return _hidl_err; }

            break;
        }
        default: { break; }
    }
    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const FmqSizeOrMetadata &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    switch (obj.getDiscriminator()) {
        case ::android::frameworks::cameraservice::device::V2_0::FmqSizeOrMetadata::hidl_discriminator::metadata: {
            size_t _hidl_metadata_child;

            _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                    obj.metadata(),
                    parcel,
                    parentHandle,
                    parentOffset + obj.hidl_getUnionOffset() /* safe_union: union offset into struct */, &_hidl_metadata_child);

            if (_hidl_err != ::android::OK) { return _hidl_err; }

            break;
        }
        default: { break; }
    }
    return _hidl_err;
}

::android::frameworks::cameraservice::device::V2_0::FmqSizeOrMetadata::FmqSizeOrMetadata() {
    static_assert(offsetof(::android::frameworks::cameraservice::device::V2_0::FmqSizeOrMetadata, hidl_d) == 0, "wrong offset");
    static_assert(offsetof(::android::frameworks::cameraservice::device::V2_0::FmqSizeOrMetadata, hidl_u) == 8, "wrong offset");

    ::std::memset(&hidl_u, 0, sizeof(hidl_u));
    ::std::memset(reinterpret_cast<uint8_t*>(this) + 1, 0, 7);
    // no padding to zero starting at offset 24

    hidl_d = hidl_discriminator::fmqMetadataSize;
    new (&hidl_u.fmqMetadataSize) uint64_t();
}

::android::frameworks::cameraservice::device::V2_0::FmqSizeOrMetadata::~FmqSizeOrMetadata() {
    hidl_destructUnion();
}

::android::frameworks::cameraservice::device::V2_0::FmqSizeOrMetadata::FmqSizeOrMetadata(FmqSizeOrMetadata&& other) : ::android::frameworks::cameraservice::device::V2_0::FmqSizeOrMetadata() {
    *this = std::move(other);
}

::android::frameworks::cameraservice::device::V2_0::FmqSizeOrMetadata::FmqSizeOrMetadata(const FmqSizeOrMetadata& other) : ::android::frameworks::cameraservice::device::V2_0::FmqSizeOrMetadata() {
    *this = other;
}

::android::frameworks::cameraservice::device::V2_0::FmqSizeOrMetadata& (::android::frameworks::cameraservice::device::V2_0::FmqSizeOrMetadata::operator=)(FmqSizeOrMetadata&& other) {
    if (this == &other) { return *this; }

    switch (other.hidl_d) {
        case hidl_discriminator::fmqMetadataSize: {
            fmqMetadataSize(std::move(other.hidl_u.fmqMetadataSize));
            break;
        }
        case hidl_discriminator::metadata: {
            metadata(std::move(other.hidl_u.metadata));
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

::android::frameworks::cameraservice::device::V2_0::FmqSizeOrMetadata& (::android::frameworks::cameraservice::device::V2_0::FmqSizeOrMetadata::operator=)(const FmqSizeOrMetadata& other) {
    if (this == &other) { return *this; }

    switch (other.hidl_d) {
        case hidl_discriminator::fmqMetadataSize: {
            fmqMetadataSize(other.hidl_u.fmqMetadataSize);
            break;
        }
        case hidl_discriminator::metadata: {
            metadata(other.hidl_u.metadata);
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

void ::android::frameworks::cameraservice::device::V2_0::FmqSizeOrMetadata::hidl_destructUnion() {
    switch (hidl_d) {
        case hidl_discriminator::fmqMetadataSize: {
            ::android::hardware::details::destructElement(&(hidl_u.fmqMetadataSize));
            break;
        }
        case hidl_discriminator::metadata: {
            ::android::hardware::details::destructElement(&(hidl_u.metadata));
            break;
        }
        default: {
            ::android::hardware::details::logAlwaysFatal((
                    "Unknown union discriminator (value: " +
                    std::to_string((uint8_t) hidl_d) + ").").c_str());
        }
    }

}

void ::android::frameworks::cameraservice::device::V2_0::FmqSizeOrMetadata::fmqMetadataSize(uint64_t o) {
    if (hidl_d != hidl_discriminator::fmqMetadataSize) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.fmqMetadataSize) uint64_t(o);
        hidl_d = hidl_discriminator::fmqMetadataSize;
    }
    else if (&(hidl_u.fmqMetadataSize) != &o) {
        hidl_u.fmqMetadataSize = o;
    }
}

uint64_t& (::android::frameworks::cameraservice::device::V2_0::FmqSizeOrMetadata::fmqMetadataSize)() {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::fmqMetadataSize)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::fmqMetadataSize));
    }

    return hidl_u.fmqMetadataSize;
}

uint64_t (::android::frameworks::cameraservice::device::V2_0::FmqSizeOrMetadata::fmqMetadataSize)() const {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::fmqMetadataSize)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::fmqMetadataSize));
    }

    return hidl_u.fmqMetadataSize;
}

void ::android::frameworks::cameraservice::device::V2_0::FmqSizeOrMetadata::metadata(const ::android::hardware::hidl_vec<uint8_t>& o) {
    if (hidl_d != hidl_discriminator::metadata) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.metadata) ::android::hardware::hidl_vec<uint8_t>(o);
        hidl_d = hidl_discriminator::metadata;
    }
    else if (&(hidl_u.metadata) != &o) {
        hidl_u.metadata = o;
    }
}

void ::android::frameworks::cameraservice::device::V2_0::FmqSizeOrMetadata::metadata(::android::hardware::hidl_vec<uint8_t>&& o) {
    if (hidl_d != hidl_discriminator::metadata) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.metadata) ::android::hardware::hidl_vec<uint8_t>(std::move(o));
        hidl_d = hidl_discriminator::metadata;
    }
    else if (&(hidl_u.metadata) != &o) {
        hidl_u.metadata = std::move(o);
    }
}

::android::hardware::hidl_vec<uint8_t>& (::android::frameworks::cameraservice::device::V2_0::FmqSizeOrMetadata::metadata)() {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::metadata)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::metadata));
    }

    return hidl_u.metadata;
}

const ::android::hardware::hidl_vec<uint8_t>& (::android::frameworks::cameraservice::device::V2_0::FmqSizeOrMetadata::metadata)() const {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::metadata)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::metadata));
    }

    return hidl_u.metadata;
}

::android::frameworks::cameraservice::device::V2_0::FmqSizeOrMetadata::hidl_union::hidl_union() {}

::android::frameworks::cameraservice::device::V2_0::FmqSizeOrMetadata::hidl_union::~hidl_union() {}

::android::frameworks::cameraservice::device::V2_0::FmqSizeOrMetadata::hidl_discriminator (::android::frameworks::cameraservice::device::V2_0::FmqSizeOrMetadata::getDiscriminator)() const {
    return hidl_d;
}

::android::status_t readEmbeddedFromParcel(
        const PhysicalCameraSettings &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.id),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::frameworks::cameraservice::device::V2_0::PhysicalCameraSettings, id));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::frameworks::cameraservice::device::V2_0::FmqSizeOrMetadata &>(obj.settings),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::frameworks::cameraservice::device::V2_0::PhysicalCameraSettings, settings));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const PhysicalCameraSettings &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.id,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::frameworks::cameraservice::device::V2_0::PhysicalCameraSettings, id));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = writeEmbeddedToParcel(
            obj.settings,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::frameworks::cameraservice::device::V2_0::PhysicalCameraSettings, settings));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const CaptureRequest &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_physicalCameraSettings_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::frameworks::cameraservice::device::V2_0::PhysicalCameraSettings> &>(obj.physicalCameraSettings),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::frameworks::cameraservice::device::V2_0::CaptureRequest, physicalCameraSettings), &_hidl_physicalCameraSettings_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.physicalCameraSettings.size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::frameworks::cameraservice::device::V2_0::PhysicalCameraSettings &>(obj.physicalCameraSettings[_hidl_index_0]),
                parcel,
                _hidl_physicalCameraSettings_child,
                _hidl_index_0 * sizeof(::android::frameworks::cameraservice::device::V2_0::PhysicalCameraSettings));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    size_t _hidl_streamAndWindowIds_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::frameworks::cameraservice::device::V2_0::StreamAndWindowId> &>(obj.streamAndWindowIds),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::frameworks::cameraservice::device::V2_0::CaptureRequest, streamAndWindowIds), &_hidl_streamAndWindowIds_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const CaptureRequest &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_physicalCameraSettings_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.physicalCameraSettings,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::frameworks::cameraservice::device::V2_0::CaptureRequest, physicalCameraSettings), &_hidl_physicalCameraSettings_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.physicalCameraSettings.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                obj.physicalCameraSettings[_hidl_index_0],
                parcel,
                _hidl_physicalCameraSettings_child,
                _hidl_index_0 * sizeof(::android::frameworks::cameraservice::device::V2_0::PhysicalCameraSettings));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    size_t _hidl_streamAndWindowIds_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.streamAndWindowIds,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::frameworks::cameraservice::device::V2_0::CaptureRequest, streamAndWindowIds), &_hidl_streamAndWindowIds_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const CaptureResultExtras &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.errorPhysicalCameraId),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::frameworks::cameraservice::device::V2_0::CaptureResultExtras, errorPhysicalCameraId));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const CaptureResultExtras &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.errorPhysicalCameraId,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::frameworks::cameraservice::device::V2_0::CaptureResultExtras, errorPhysicalCameraId));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const PhysicalCaptureResultInfo &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.physicalCameraId),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::frameworks::cameraservice::device::V2_0::PhysicalCaptureResultInfo, physicalCameraId));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::frameworks::cameraservice::device::V2_0::FmqSizeOrMetadata &>(obj.physicalCameraMetadata),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::frameworks::cameraservice::device::V2_0::PhysicalCaptureResultInfo, physicalCameraMetadata));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const PhysicalCaptureResultInfo &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.physicalCameraId,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::frameworks::cameraservice::device::V2_0::PhysicalCaptureResultInfo, physicalCameraId));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = writeEmbeddedToParcel(
            obj.physicalCameraMetadata,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::frameworks::cameraservice::device::V2_0::PhysicalCaptureResultInfo, physicalCameraMetadata));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const OutputConfiguration &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_windowHandles_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::hardware::hidl_handle> &>(obj.windowHandles),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::frameworks::cameraservice::device::V2_0::OutputConfiguration, windowHandles), &_hidl_windowHandles_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.windowHandles.size(); ++_hidl_index_0) {
        _hidl_err = ::android::hardware::readEmbeddedFromParcel(
                const_cast<::android::hardware::hidl_handle &>(obj.windowHandles[_hidl_index_0]),
                parcel,
                _hidl_windowHandles_child,
                _hidl_index_0 * sizeof(::android::hardware::hidl_handle));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.physicalCameraId),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::frameworks::cameraservice::device::V2_0::OutputConfiguration, physicalCameraId));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const OutputConfiguration &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_windowHandles_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.windowHandles,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::frameworks::cameraservice::device::V2_0::OutputConfiguration, windowHandles), &_hidl_windowHandles_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.windowHandles.size(); ++_hidl_index_0) {
        _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                obj.windowHandles[_hidl_index_0],
                parcel,
                _hidl_windowHandles_child,
                _hidl_index_0 * sizeof(::android::hardware::hidl_handle));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.physicalCameraId,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::frameworks::cameraservice::device::V2_0::OutputConfiguration, physicalCameraId));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const SessionConfiguration &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_outputStreams_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<::android::frameworks::cameraservice::device::V2_0::OutputConfiguration> &>(obj.outputStreams),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::frameworks::cameraservice::device::V2_0::SessionConfiguration, outputStreams), &_hidl_outputStreams_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.outputStreams.size(); ++_hidl_index_0) {
        _hidl_err = readEmbeddedFromParcel(
                const_cast<::android::frameworks::cameraservice::device::V2_0::OutputConfiguration &>(obj.outputStreams[_hidl_index_0]),
                parcel,
                _hidl_outputStreams_child,
                _hidl_index_0 * sizeof(::android::frameworks::cameraservice::device::V2_0::OutputConfiguration));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const SessionConfiguration &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_outputStreams_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.outputStreams,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::frameworks::cameraservice::device::V2_0::SessionConfiguration, outputStreams), &_hidl_outputStreams_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.outputStreams.size(); ++_hidl_index_0) {
        _hidl_err = writeEmbeddedToParcel(
                obj.outputStreams[_hidl_index_0],
                parcel,
                _hidl_outputStreams_child,
                _hidl_index_0 * sizeof(::android::frameworks::cameraservice::device::V2_0::OutputConfiguration));

        if (_hidl_err != ::android::OK) { return _hidl_err; }

    }

    return _hidl_err;
}

static_assert(sizeof(::android::hardware::MQDescriptor<char, ::android::hardware::kSynchronizedReadWrite>) == 32, "wrong size");
static_assert(sizeof(::android::hardware::hidl_handle) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_memory) == 40, "wrong size");
static_assert(sizeof(::android::hardware::hidl_string) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_vec<char>) == 16, "wrong size");

}  // namespace V2_0
}  // namespace device
}  // namespace cameraservice
}  // namespace frameworks
}  // namespace android
