#pragma once

#include <binder/IInterface.h>
#include <android/os/IVoldTaskListener.h>

namespace android {

namespace os {

class BnVoldTaskListener : public ::android::BnInterface<IVoldTaskListener> {
public:
  static constexpr uint32_t TRANSACTION_onStatus = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_onFinished = ::android::IBinder::FIRST_CALL_TRANSACTION + 1;
  explicit BnVoldTaskListener();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnVoldTaskListener

}  // namespace os

}  // namespace android
