#define LOG_TAG "android.frameworks.bufferhub@1.0::types"

#include <log/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <hidl/Static.h>
#include <hwbinder/ProcessState.h>
#include <utils/Trace.h>
#include <android/frameworks/bufferhub/1.0/types.h>
#include <android/frameworks/bufferhub/1.0/hwtypes.h>

namespace android {
namespace frameworks {
namespace bufferhub {
namespace V1_0 {

::android::status_t readEmbeddedFromParcel(
        const BufferTraits &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_handle &>(obj.bufferHandle),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::frameworks::bufferhub::V1_0::BufferTraits, bufferHandle));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_handle &>(obj.bufferInfo),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::frameworks::bufferhub::V1_0::BufferTraits, bufferInfo));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const BufferTraits &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.bufferHandle,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::frameworks::bufferhub::V1_0::BufferTraits, bufferHandle));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.bufferInfo,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::frameworks::bufferhub::V1_0::BufferTraits, bufferInfo));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

static_assert(sizeof(::android::hardware::MQDescriptor<char, ::android::hardware::kSynchronizedReadWrite>) == 32, "wrong size");
static_assert(sizeof(::android::hardware::hidl_handle) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_memory) == 40, "wrong size");
static_assert(sizeof(::android::hardware::hidl_string) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_vec<char>) == 16, "wrong size");

}  // namespace V1_0
}  // namespace bufferhub
}  // namespace frameworks
}  // namespace android
