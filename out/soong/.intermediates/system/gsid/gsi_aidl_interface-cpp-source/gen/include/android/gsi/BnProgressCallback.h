#pragma once

#include <binder/IInterface.h>
#include <android/gsi/IProgressCallback.h>

namespace android {

namespace gsi {

class BnProgressCallback : public ::android::BnInterface<IProgressCallback> {
public:
  static constexpr uint32_t TRANSACTION_onProgress = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  explicit BnProgressCallback();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnProgressCallback

}  // namespace gsi

}  // namespace android
