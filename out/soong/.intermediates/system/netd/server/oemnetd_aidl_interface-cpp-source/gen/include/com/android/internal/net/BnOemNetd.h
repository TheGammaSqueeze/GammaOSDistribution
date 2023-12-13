#pragma once

#include <binder/IInterface.h>
#include <com/android/internal/net/IOemNetd.h>

namespace com {

namespace android {

namespace internal {

namespace net {

class BnOemNetd : public ::android::BnInterface<IOemNetd> {
public:
  static constexpr uint32_t TRANSACTION_isAlive = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_registerOemUnsolicitedEventListener = ::android::IBinder::FIRST_CALL_TRANSACTION + 1;
  explicit BnOemNetd();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnOemNetd

}  // namespace net

}  // namespace internal

}  // namespace android

}  // namespace com
