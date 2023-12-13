#pragma once

#include <binder/IInterface.h>
#include <com/android/internal/compat/IPlatformCompatNative.h>

namespace com {

namespace android {

namespace internal {

namespace compat {

class BnPlatformCompatNative : public ::android::BnInterface<IPlatformCompatNative> {
public:
  static constexpr uint32_t TRANSACTION_reportChangeByPackageName = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_reportChangeByUid = ::android::IBinder::FIRST_CALL_TRANSACTION + 1;
  static constexpr uint32_t TRANSACTION_isChangeEnabledByPackageName = ::android::IBinder::FIRST_CALL_TRANSACTION + 2;
  static constexpr uint32_t TRANSACTION_isChangeEnabledByUid = ::android::IBinder::FIRST_CALL_TRANSACTION + 3;
  explicit BnPlatformCompatNative();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnPlatformCompatNative

}  // namespace compat

}  // namespace internal

}  // namespace android

}  // namespace com
