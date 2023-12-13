#pragma once

#include <binder/IInterface.h>
#include <com/google/android/startop/iorap/IIorap.h>

namespace com {

namespace google {

namespace android {

namespace startop {

namespace iorap {

class BnIorap : public ::android::BnInterface<IIorap> {
public:
  static constexpr uint32_t TRANSACTION_setTaskListener = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_onAppLaunchEvent = ::android::IBinder::FIRST_CALL_TRANSACTION + 1;
  static constexpr uint32_t TRANSACTION_onDexOptEvent = ::android::IBinder::FIRST_CALL_TRANSACTION + 2;
  static constexpr uint32_t TRANSACTION_onJobScheduledEvent = ::android::IBinder::FIRST_CALL_TRANSACTION + 3;
  static constexpr uint32_t TRANSACTION_onPackageEvent = ::android::IBinder::FIRST_CALL_TRANSACTION + 4;
  static constexpr uint32_t TRANSACTION_onAppIntentEvent = ::android::IBinder::FIRST_CALL_TRANSACTION + 5;
  static constexpr uint32_t TRANSACTION_onSystemServiceEvent = ::android::IBinder::FIRST_CALL_TRANSACTION + 6;
  static constexpr uint32_t TRANSACTION_onSystemServiceUserEvent = ::android::IBinder::FIRST_CALL_TRANSACTION + 7;
  explicit BnIorap();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnIorap

}  // namespace iorap

}  // namespace startop

}  // namespace android

}  // namespace google

}  // namespace com
