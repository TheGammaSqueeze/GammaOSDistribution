#pragma once

#include <binder/IInterface.h>
#include <android/os/IStoraged.h>

namespace android {

namespace os {

class BnStoraged : public ::android::BnInterface<IStoraged> {
public:
  static constexpr uint32_t TRANSACTION_onUserStarted = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_onUserStopped = ::android::IBinder::FIRST_CALL_TRANSACTION + 1;
  static constexpr uint32_t TRANSACTION_getRecentPerf = ::android::IBinder::FIRST_CALL_TRANSACTION + 2;
  explicit BnStoraged();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnStoraged

}  // namespace os

}  // namespace android
