#pragma once

#include <binder/IInterface.h>
#include <android/system/suspend/internal/ISuspendControlServiceInternal.h>

namespace android {

namespace system {

namespace suspend {

namespace internal {

class BnSuspendControlServiceInternal : public ::android::BnInterface<ISuspendControlServiceInternal> {
public:
  static constexpr uint32_t TRANSACTION_enableAutosuspend = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_forceSuspend = ::android::IBinder::FIRST_CALL_TRANSACTION + 1;
  static constexpr uint32_t TRANSACTION_getWakeLockStats = ::android::IBinder::FIRST_CALL_TRANSACTION + 2;
  static constexpr uint32_t TRANSACTION_getWakeupStats = ::android::IBinder::FIRST_CALL_TRANSACTION + 3;
  static constexpr uint32_t TRANSACTION_getSuspendStats = ::android::IBinder::FIRST_CALL_TRANSACTION + 4;
  explicit BnSuspendControlServiceInternal();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnSuspendControlServiceInternal

}  // namespace internal

}  // namespace suspend

}  // namespace system

}  // namespace android
