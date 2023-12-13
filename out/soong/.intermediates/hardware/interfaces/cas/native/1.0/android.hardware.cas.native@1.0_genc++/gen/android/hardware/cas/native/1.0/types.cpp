#define LOG_TAG "android.hardware.cas.native@1.0::types"

#include <log/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <hidl/Static.h>
#include <hwbinder/ProcessState.h>
#include <utils/Trace.h>
#include <android/hardware/cas/native/1.0/types.h>
#include <android/hardware/cas/native/1.0/hwtypes.h>

namespace android {
namespace hardware {
namespace cas {
namespace native {
namespace V1_0 {

::android::status_t readEmbeddedFromParcel(
        const SharedBuffer &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_memory &>(obj.heapBase),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::cas::native::V1_0::SharedBuffer, heapBase));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const SharedBuffer &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.heapBase,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::cas::native::V1_0::SharedBuffer, heapBase));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t readEmbeddedFromParcel(
        const DestinationBuffer &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = readEmbeddedFromParcel(
            const_cast<::android::hardware::cas::native::V1_0::SharedBuffer &>(obj.nonsecureMemory),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::cas::native::V1_0::DestinationBuffer, nonsecureMemory));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_handle &>(obj.secureMemory),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::cas::native::V1_0::DestinationBuffer, secureMemory));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const DestinationBuffer &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = writeEmbeddedToParcel(
            obj.nonsecureMemory,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::cas::native::V1_0::DestinationBuffer, nonsecureMemory));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.secureMemory,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::cas::native::V1_0::DestinationBuffer, secureMemory));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

static_assert(sizeof(::android::hardware::MQDescriptor<char, ::android::hardware::kSynchronizedReadWrite>) == 32, "wrong size");
static_assert(sizeof(::android::hardware::hidl_handle) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_memory) == 40, "wrong size");
static_assert(sizeof(::android::hardware::hidl_string) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_vec<char>) == 16, "wrong size");

}  // namespace V1_0
}  // namespace native
}  // namespace cas
}  // namespace hardware
}  // namespace android
