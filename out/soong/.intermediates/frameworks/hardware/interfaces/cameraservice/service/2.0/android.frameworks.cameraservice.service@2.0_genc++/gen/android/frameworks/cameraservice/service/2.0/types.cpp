#define LOG_TAG "android.frameworks.cameraservice.service@2.0::types"

#include <log/log.h>
#include <cutils/trace.h>
#include <hidl/HidlTransportSupport.h>

#include <hidl/Static.h>
#include <hwbinder/ProcessState.h>
#include <utils/Trace.h>
#include <android/frameworks/cameraservice/service/2.0/types.h>
#include <android/frameworks/cameraservice/service/2.0/hwtypes.h>

namespace android {
namespace frameworks {
namespace cameraservice {
namespace service {
namespace V2_0 {

::android::status_t readEmbeddedFromParcel(
        const CameraStatusAndId &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::readEmbeddedFromParcel(
            const_cast<::android::hardware::hidl_string &>(obj.cameraId),
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::frameworks::cameraservice::service::V2_0::CameraStatusAndId, cameraId));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

::android::status_t writeEmbeddedToParcel(
        const CameraStatusAndId &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset) {
    ::android::status_t _hidl_err = ::android::OK;

    _hidl_err = ::android::hardware::writeEmbeddedToParcel(
            obj.cameraId,
            parcel,
            parentHandle,
            parentOffset + offsetof(::android::frameworks::cameraservice::service::V2_0::CameraStatusAndId, cameraId));

    if (_hidl_err != ::android::OK) { return _hidl_err; }

    return _hidl_err;
}

static_assert(sizeof(::android::hardware::MQDescriptor<char, ::android::hardware::kSynchronizedReadWrite>) == 32, "wrong size");
static_assert(sizeof(::android::hardware::hidl_handle) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_memory) == 40, "wrong size");
static_assert(sizeof(::android::hardware::hidl_string) == 16, "wrong size");
static_assert(sizeof(::android::hardware::hidl_vec<char>) == 16, "wrong size");

}  // namespace V2_0
}  // namespace service
}  // namespace cameraservice
}  // namespace frameworks
}  // namespace android
