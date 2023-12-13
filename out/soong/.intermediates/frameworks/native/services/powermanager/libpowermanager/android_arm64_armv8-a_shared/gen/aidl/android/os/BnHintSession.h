#pragma once

#include <binder/IInterface.h>
#include <android/os/IHintSession.h>

namespace android {

namespace os {

class BnHintSession : public ::android::BnInterface<IHintSession> {
public:
  static constexpr uint32_t TRANSACTION_updateTargetWorkDuration = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_reportActualWorkDuration = ::android::IBinder::FIRST_CALL_TRANSACTION + 1;
  static constexpr uint32_t TRANSACTION_close = ::android::IBinder::FIRST_CALL_TRANSACTION + 2;
  explicit BnHintSession();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnHintSession

}  // namespace os

}  // namespace android
