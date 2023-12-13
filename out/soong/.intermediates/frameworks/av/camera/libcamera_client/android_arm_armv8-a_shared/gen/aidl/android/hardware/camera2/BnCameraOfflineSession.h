#pragma once

#include <binder/IInterface.h>
#include <android/hardware/camera2/ICameraOfflineSession.h>

namespace android {

namespace hardware {

namespace camera2 {

class BnCameraOfflineSession : public ::android::BnInterface<ICameraOfflineSession> {
public:
  static constexpr uint32_t TRANSACTION_disconnect = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  explicit BnCameraOfflineSession();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnCameraOfflineSession

}  // namespace camera2

}  // namespace hardware

}  // namespace android
