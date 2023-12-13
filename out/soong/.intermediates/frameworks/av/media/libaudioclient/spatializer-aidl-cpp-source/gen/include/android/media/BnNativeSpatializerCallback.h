#pragma once

#include <binder/IInterface.h>
#include <android/media/INativeSpatializerCallback.h>

namespace android {

namespace media {

class BnNativeSpatializerCallback : public ::android::BnInterface<INativeSpatializerCallback> {
public:
  static constexpr uint32_t TRANSACTION_onLevelChanged = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_onOutputChanged = ::android::IBinder::FIRST_CALL_TRANSACTION + 1;
  explicit BnNativeSpatializerCallback();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnNativeSpatializerCallback

}  // namespace media

}  // namespace android
