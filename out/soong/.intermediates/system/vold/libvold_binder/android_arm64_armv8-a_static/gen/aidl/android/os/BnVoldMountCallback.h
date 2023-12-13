#pragma once

#include <binder/IInterface.h>
#include <android/os/IVoldMountCallback.h>

namespace android {

namespace os {

class BnVoldMountCallback : public ::android::BnInterface<IVoldMountCallback> {
public:
  static constexpr uint32_t TRANSACTION_onVolumeChecking = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  explicit BnVoldMountCallback();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnVoldMountCallback

}  // namespace os

}  // namespace android
