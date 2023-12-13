#define LOG_TAG "android.hardware.drm@1.2::types"

#include <log/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <hidl/Static.h>
#include <hwbinder/ProcessState.h>
#include <utils/Trace.h>
#include <android/hardware/drm/1.2/types.h>
#include <android/hardware/drm/1.2/hwtypes.h>

namespace android {
namespace hardware {
namespace drm {
namespace V1_2 {

::android::status_t readEmbeddedFromParcel(
        const KeyStatus &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_keyId_child;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_vec<uint8_t> &>(obj.keyId),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::drm::V1_2::KeyStatus, keyId), &_hidl_keyId_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const KeyStatus &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    size_t _hidl_keyId_child;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.keyId,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::hardware::drm::V1_2::KeyStatus, keyId), &_hidl_keyId_child);

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

static_assert(sizeof(::android::hardware::MQDescriptor<char, ::android::hardware::kSynchronizedReadWrite>) == 32, "wrong size");
static_assert(sizeof(::android::hardware::hidl_handle) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_memory) == 40, "wrong size");
static_assert(sizeof(::android::hardware::hidl_string) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_vec<char>) == 16, "wrong size");

}  // namespace V1_2
}  // namespace drm
}  // namespace hardware
}  // namespace android
