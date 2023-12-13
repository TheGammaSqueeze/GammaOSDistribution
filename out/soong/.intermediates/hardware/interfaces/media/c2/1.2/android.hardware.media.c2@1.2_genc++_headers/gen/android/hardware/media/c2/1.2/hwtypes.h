#ifndef HIDL_GENERATED_ANDROID_HARDWARE_MEDIA_C2_V1_2_HWTYPES_H
#define HIDL_GENERATED_ANDROID_HARDWARE_MEDIA_C2_V1_2_HWTYPES_H

#include <android/hardware/media/c2/1.2/types.h>


#include <hidl/Status.h>
#include <hwbinder/IBinder.h>
#include <hwbinder/Parcel.h>

namespace android {
namespace hardware {
namespace media {
namespace c2 {
namespace V1_2 {
::android::status_t readEmbeddedFromParcel(
        const ::android::hardware::media::c2::V1_2::SurfaceSyncObj &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset);

::android::status_t writeEmbeddedToParcel(
        const ::android::hardware::media::c2::V1_2::SurfaceSyncObj &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset);

}  // namespace V1_2
}  // namespace c2
}  // namespace media
}  // namespace hardware
}  // namespace android

#endif  // HIDL_GENERATED_ANDROID_HARDWARE_MEDIA_C2_V1_2_HWTYPES_H
