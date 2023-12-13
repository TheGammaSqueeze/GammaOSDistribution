#pragma once

#include <binder/IInterface.h>
#include <android/os/IHintManager.h>

namespace android {

namespace os {

class BnHintManager : public ::android::BnInterface<IHintManager> {
public:
  static constexpr uint32_t TRANSACTION_createHintSession = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_getHintSessionPreferredRate = ::android::IBinder::FIRST_CALL_TRANSACTION + 1;
  explicit BnHintManager();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnHintManager

}  // namespace os

}  // namespace android
