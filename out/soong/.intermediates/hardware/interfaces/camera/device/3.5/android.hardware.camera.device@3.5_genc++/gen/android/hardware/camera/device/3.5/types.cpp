#define LOG_TAG "android.hardware.camera.device@3.5::types"

#include <log/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <hidl/Static.h>
#include <hwbinder/ProcessState.h>
#include <utils/Trace.h>
#include <android/hardware/camera/device/3.5/types.h>
#include <android/hardware/camera/device/3.5/hwtypes.h>

namespace android {
namespace hardware {
namespace camera {
namespace device {
namespace V3_5 {

::android::status_t readEmbeddedFromParcel(
        const StreamConfiguration &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::camera::device::V3_4::StreamConfiguration &>(obj.v3_4),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::camera::device::V3_5::StreamConfiguration, v3_4));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const StreamConfiguration &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = writeEmbeddedToParcel(
            obj.v3_4,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::camera::device::V3_5::StreamConfiguration, v3_4));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const StreamBuffersVal &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    switch (obj.getDiscriminator()) {
        case ::android::hardware::camera::device::V3_5::StreamBuffersVal::hidl_discriminator::buffers: {
            size_t _hidl_buffers_child;

            _hidl_err = ::android::hardware::readEmbeddedFromParcel(
                    const_cast<::android::hardware::hidl_vec<::android::hardware::camera::device::V3_2::StreamBuffer> &>(obj.buffers()),
                    parcel,
                    parentHandle,
                    parentOffset + obj.hidl_getUnionOffset() /* safe_union: union offset into struct */, &_hidl_buffers_child);

            if (_hidl_err != ::android::OK) { return _hidl_err; }

            for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.buffers().size(); ++_hidl_index_0) {
                _hidl_err = readEmbeddedFromParcel(
                        const_cast<::android::hardware::camera::device::V3_2::StreamBuffer &>(obj.buffers()[_hidl_index_0]),
                        parcel,
                        _hidl_buffers_child,
                        _hidl_index_0 * sizeof(::android::hardware::camera::device::V3_2::StreamBuffer));

                if (_hidl_err != ::android::OK) { return _hidl_err; }

            }

            break;
        }
        default: { break; }
    }
    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const StreamBuffersVal &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    switch (obj.getDiscriminator()) {
        case ::android::hardware::camera::device::V3_5::StreamBuffersVal::hidl_discriminator::buffers: {
            size_t _hidl_buffers_child;

            _hidl_err = ::android::hardware::writeEmbeddedToParcel(
                    obj.buffers(),
                    parcel,
                    parentHandle,
                    parentOffset + obj.hidl_getUnionOffset() /* safe_union: union offset into struct */, &_hidl_buffers_child);

            if (_hidl_err != ::android::OK) { return _hidl_err; }

            for (size_t _hidl_index_0 = 0; _hidl_index_0 < obj.buffers().size(); ++_hidl_index_0) {
                _hidl_err = writeEmbeddedToParcel(
                        obj.buffers()[_hidl_index_0],
                        parcel,
                        _hidl_buffers_child,
                        _hidl_index_0 * sizeof(::android::hardware::camera::device::V3_2::StreamBuffer));

                if (_hidl_err != ::android::OK) { return _hidl_err; }

            }

            break;
        }
        default: { break; }
    }
    return _hidl_err;
}

::android::hardware::camera::device::V3_5::StreamBuffersVal::StreamBuffersVal() {
    static_assert(offsetof(::android::hardware::camera::device::V3_5::StreamBuffersVal, hidl_d) == 0, "wrong offset");
    static_assert(offsetof(::android::hardware::camera::device::V3_5::StreamBuffersVal, hidl_u) == 8, "wrong offset");

    ::std::memset(&hidl_u, 0, sizeof(hidl_u));
    ::std::memset(reinterpret_cast<uint8_t*>(this) + 1, 0, 7);
    // no padding to zero starting at offset 24

    hidl_d = hidl_discriminator::error;
    new (&hidl_u.error) ::android::hardware::camera::device::V3_5::StreamBufferRequestError();
}

::android::hardware::camera::device::V3_5::StreamBuffersVal::~StreamBuffersVal() {
    hidl_destructUnion();
}

::android::hardware::camera::device::V3_5::StreamBuffersVal::StreamBuffersVal(StreamBuffersVal&& other) : ::android::hardware::camera::device::V3_5::StreamBuffersVal() {
    *this = std::move(other);
}

::android::hardware::camera::device::V3_5::StreamBuffersVal::StreamBuffersVal(const StreamBuffersVal& other) : ::android::hardware::camera::device::V3_5::StreamBuffersVal() {
    *this = other;
}

::android::hardware::camera::device::V3_5::StreamBuffersVal& (::android::hardware::camera::device::V3_5::StreamBuffersVal::operator=)(StreamBuffersVal&& other) {
    if (this == &other) { return *this; }

    switch (other.hidl_d) {
        case hidl_discriminator::error: {
            error(std::move(other.hidl_u.error));
            break;
        }
        case hidl_discriminator::buffers: {
            buffers(std::move(other.hidl_u.buffers));
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

::android::hardware::camera::device::V3_5::StreamBuffersVal& (::android::hardware::camera::device::V3_5::StreamBuffersVal::operator=)(const StreamBuffersVal& other) {
    if (this == &other) { return *this; }

    switch (other.hidl_d) {
        case hidl_discriminator::error: {
            error(other.hidl_u.error);
            break;
        }
        case hidl_discriminator::buffers: {
            buffers(other.hidl_u.buffers);
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

void ::android::hardware::camera::device::V3_5::StreamBuffersVal::hidl_destructUnion() {
    switch (hidl_d) {
        case hidl_discriminator::error: {
            ::android::hardware::details::destructElement(&(hidl_u.error));
            break;
        }
        case hidl_discriminator::buffers: {
            ::android::hardware::details::destructElement(&(hidl_u.buffers));
            break;
        }
        default: {
            ::android::hardware::details::logAlwaysFatal((
                    "Unknown union discriminator (value: " +
                    std::to_string((uint8_t) hidl_d) + ").").c_str());
        }
    }

}

void ::android::hardware::camera::device::V3_5::StreamBuffersVal::error(::android::hardware::camera::device::V3_5::StreamBufferRequestError o) {
    if (hidl_d != hidl_discriminator::error) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.error) ::android::hardware::camera::device::V3_5::StreamBufferRequestError(o);
        hidl_d = hidl_discriminator::error;
    }
    else if (&(hidl_u.error) != &o) {
        hidl_u.error = o;
    }
}

::android::hardware::camera::device::V3_5::StreamBufferRequestError& (::android::hardware::camera::device::V3_5::StreamBuffersVal::error)() {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::error)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::error));
    }

    return hidl_u.error;
}

::android::hardware::camera::device::V3_5::StreamBufferRequestError (::android::hardware::camera::device::V3_5::StreamBuffersVal::error)() const {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::error)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::error));
    }

    return hidl_u.error;
}

void ::android::hardware::camera::device::V3_5::StreamBuffersVal::buffers(const ::android::hardware::hidl_vec<::android::hardware::camera::device::V3_2::StreamBuffer>& o) {
    if (hidl_d != hidl_discriminator::buffers) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.buffers) ::android::hardware::hidl_vec<::android::hardware::camera::device::V3_2::StreamBuffer>(o);
        hidl_d = hidl_discriminator::buffers;
    }
    else if (&(hidl_u.buffers) != &o) {
        hidl_u.buffers = o;
    }
}

void ::android::hardware::camera::device::V3_5::StreamBuffersVal::buffers(::android::hardware::hidl_vec<::android::hardware::camera::device::V3_2::StreamBuffer>&& o) {
    if (hidl_d != hidl_discriminator::buffers) {
        hidl_destructUnion();
        ::std::memset(&hidl_u, 0, sizeof(hidl_u));

        new (&hidl_u.buffers) ::android::hardware::hidl_vec<::android::hardware::camera::device::V3_2::StreamBuffer>(std::move(o));
        hidl_d = hidl_discriminator::buffers;
    }
    else if (&(hidl_u.buffers) != &o) {
        hidl_u.buffers = std::move(o);
    }
}

::android::hardware::hidl_vec<::android::hardware::camera::device::V3_2::StreamBuffer>& (::android::hardware::camera::device::V3_5::StreamBuffersVal::buffers)() {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::buffers)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::buffers));
    }

    return hidl_u.buffers;
}

const ::android::hardware::hidl_vec<::android::hardware::camera::device::V3_2::StreamBuffer>& (::android::hardware::camera::device::V3_5::StreamBuffersVal::buffers)() const {
    if (CC_UNLIKELY(hidl_d != hidl_discriminator::buffers)) {
        LOG_ALWAYS_FATAL("Bad safe_union access: safe_union has discriminator %" PRIu64 " but discriminator %" PRIu64 " was accessed.",
                static_cast<uint64_t>(hidl_d), static_cast<uint64_t>(hidl_discriminator::buffers));
    }

    return hidl_u.buffers;
}

::android::hardware::camera::device::V3_5::StreamBuffersVal::hidl_union::hidl_union() {}

::android::hardware::camera::device::V3_5::StreamBuffersVal::hidl_union::~hidl_union() {}

::android::hardware::camera::device::V3_5::StreamBuffersVal::hidl_discriminator (::android::hardware::camera::device::V3_5::StreamBuffersVal::getDiscriminator)() const {
    return hidl_d;
}

::android::status_t readEmbeddedFromParcel(
        const StreamBufferRet &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::camera::device::V3_5::StreamBuffersVal &>(obj.val),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::camera::device::V3_5::StreamBufferRet, val));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const StreamBufferRet &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = writeEmbeddedToParcel(
            obj.val,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::camera::device::V3_5::StreamBufferRet, val));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

static_assert(sizeof(::android::hardware::MQDescriptor<char, ::android::hardware::kSynchronizedReadWrite>) == 32, "wrong size");
static_assert(sizeof(::android::hardware::hidl_handle) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_memory) == 40, "wrong size");
static_assert(sizeof(::android::hardware::hidl_string) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_vec<char>) == 16, "wrong size");

}  // namespace V3_5
}  // namespace device
}  // namespace camera
}  // namespace hardware
}  // namespace android
