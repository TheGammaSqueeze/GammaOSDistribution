#ifndef HIDL_GENERATED_ANDROID_FRAMEWORKS_BUFFERHUB_V1_0_HWTYPES_H
#define HIDL_GENERATED_ANDROID_FRAMEWORKS_BUFFERHUB_V1_0_HWTYPES_H

#include <android/frameworks/bufferhub/1.0/types.h>

#include <android/hardware/graphics/common/1.2/hwtypes.h>

#include <hidl/Status.h>
#include <hwbinder/IBinder.h>
#include <hwbinder/Parcel.h>

namespace android {
namespace frameworks {
namespace bufferhub {
namespace V1_0 {
::android::status_t readEmbeddedFromParcel(
        const ::android::frameworks::bufferhub::V1_0::BufferTraits &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset);

::android::status_t writeEmbeddedToParcel(
        const ::android::frameworks::bufferhub::V1_0::BufferTraits &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset);

}  // namespace V1_0
}  // namespace bufferhub
}  // namespace frameworks
}  // namespace android

#endif  // HIDL_GENERATED_ANDROID_FRAMEWORKS_BUFFERHUB_V1_0_HWTYPES_H
