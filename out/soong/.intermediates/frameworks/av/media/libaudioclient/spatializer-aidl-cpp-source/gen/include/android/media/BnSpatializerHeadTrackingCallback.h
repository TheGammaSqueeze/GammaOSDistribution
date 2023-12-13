#pragma once

#include <binder/IInterface.h>
#include <android/media/ISpatializerHeadTrackingCallback.h>

namespace android {

namespace media {

class BnSpatializerHeadTrackingCallback : public ::android::BnInterface<ISpatializerHeadTrackingCallback> {
public:
  static constexpr uint32_t TRANSACTION_onHeadTrackingModeChanged = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_onHeadToSoundStagePoseUpdated = ::android::IBinder::FIRST_CALL_TRANSACTION + 1;
  explicit BnSpatializerHeadTrackingCallback();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnSpatializerHeadTrackingCallback

}  // namespace media

}  // namespace android
