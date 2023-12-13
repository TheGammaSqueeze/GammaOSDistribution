#pragma once

#include <binder/IInterface.h>
#include <com/android/internal/net/IOemNetdUnsolicitedEventListener.h>

namespace com {

namespace android {

namespace internal {

namespace net {

class BnOemNetdUnsolicitedEventListener : public ::android::BnInterface<IOemNetdUnsolicitedEventListener> {
public:
  static constexpr uint32_t TRANSACTION_onRegistered = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  explicit BnOemNetdUnsolicitedEventListener();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnOemNetdUnsolicitedEventListener

}  // namespace net

}  // namespace internal

}  // namespace android

}  // namespace com
