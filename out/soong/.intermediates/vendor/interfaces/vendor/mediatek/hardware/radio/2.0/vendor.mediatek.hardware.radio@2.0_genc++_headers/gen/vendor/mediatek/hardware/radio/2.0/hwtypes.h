#ifndef HIDL_GENERATED_VENDOR_MEDIATEK_HARDWARE_RADIO_V2_0_HWTYPES_H
#define HIDL_GENERATED_VENDOR_MEDIATEK_HARDWARE_RADIO_V2_0_HWTYPES_H

#include <vendor/mediatek/hardware/radio/2.0/types.h>

#include <android/hardware/radio/1.0/hwtypes.h>

#include <hidl/Status.h>
#include <hwbinder/IBinder.h>
#include <hwbinder/Parcel.h>

namespace vendor {
namespace mediatek {
namespace hardware {
namespace radio {
namespace V2_0 {
::android::status_t readEmbeddedFromParcel(
        const ::vendor::mediatek::hardware::radio::V2_0::MtkDataProfileInfo &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset);

::android::status_t writeEmbeddedToParcel(
        const ::vendor::mediatek::hardware::radio::V2_0::MtkDataProfileInfo &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset);

::android::status_t readEmbeddedFromParcel(
        const ::vendor::mediatek::hardware::radio::V2_0::IncomingCallNotification &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset);

::android::status_t writeEmbeddedToParcel(
        const ::vendor::mediatek::hardware::radio::V2_0::IncomingCallNotification &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset);

::android::status_t readEmbeddedFromParcel(
        const ::vendor::mediatek::hardware::radio::V2_0::MtkSetupDataCallResult &obj,
        const ::android::hardware::Parcel &parcel,
        size_t parentHandle,
        size_t parentOffset);

::android::status_t writeEmbeddedToParcel(
        const ::vendor::mediatek::hardware::radio::V2_0::MtkSetupDataCallResult &obj,
        ::android::hardware::Parcel *parcel,
        size_t parentHandle,
        size_t parentOffset);

}  // namespace V2_0
}  // namespace radio
}  // namespace hardware
}  // namespace mediatek
}  // namespace vendor

#endif  // HIDL_GENERATED_VENDOR_MEDIATEK_HARDWARE_RADIO_V2_0_HWTYPES_H
