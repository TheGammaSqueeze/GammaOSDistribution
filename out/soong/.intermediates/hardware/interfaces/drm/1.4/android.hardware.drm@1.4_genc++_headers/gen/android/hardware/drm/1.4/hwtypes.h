#ifndef HIDL_GENERATED_ANDROID_HARDWARE_DRM_V1_4_HWTYPES_H
#define HIDL_GENERATED_ANDROID_HARDWARE_DRM_V1_4_HWTYPES_H

#include <android/hardware/drm/1.4/types.h>

#include <android/hardware/drm/1.2/hwtypes.h>

#include <hidl/Status.h>
#include <hwbinder/IBinder.h>
#include <hwbinder/Parcel.h>

namespace android {
namespace hardware {
namespace drm {
namespace V1_4 {
::android::status_t readEmbeddedFromParcel(
        const ::android::hardware::drm::V1_4::LogMessage &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset);

::android::status_t writeEmbeddedToParcel(
        const ::android::hardware::drm::V1_4::LogMessage &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset);

}  // namespace V1_4
}  // namespace drm
}  // namespace hardware
}  // namespace android

#endif  // HIDL_GENERATED_ANDROID_HARDWARE_DRM_V1_4_HWTYPES_H
