#pragma once

#include <binder/IInterface.h>
#include <android/system/suspend/IWakelockCallback.h>

namespace android {

namespace system {

namespace suspend {

class BnWakelockCallback : public ::android::BnInterface<IWakelockCallback> {
public:
  static constexpr uint32_t TRANSACTION_notifyAcquired = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_notifyReleased = ::android::IBinder::FIRST_CALL_TRANSACTION + 1;
  static constexpr uint32_t TRANSACTION_getInterfaceVersion = ::android::IBinder::FIRST_CALL_TRANSACTION + 16777214;
  static constexpr uint32_t TRANSACTION_getInterfaceHash = ::android::IBinder::FIRST_CALL_TRANSACTION + 16777213;
  explicit BnWakelockCallback();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
  int32_t getInterfaceVersion() final;
  std::string getInterfaceHash();
};  // class BnWakelockCallback

}  // namespace suspend

}  // namespace system

}  // namespace android
