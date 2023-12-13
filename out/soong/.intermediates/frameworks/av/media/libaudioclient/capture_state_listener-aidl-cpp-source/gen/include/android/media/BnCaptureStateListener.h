#pragma once

#include <binder/IInterface.h>
#include <android/media/ICaptureStateListener.h>

namespace android {

namespace media {

class BnCaptureStateListener : public ::android::BnInterface<ICaptureStateListener> {
public:
  static constexpr uint32_t TRANSACTION_setCaptureState = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  explicit BnCaptureStateListener();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnCaptureStateListener

}  // namespace media

}  // namespace android
