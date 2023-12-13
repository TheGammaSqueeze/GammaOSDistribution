#pragma once

#include <binder/IInterface.h>
#include <android/permission/IPermissionChecker.h>

namespace android {

namespace permission {

class BnPermissionChecker : public ::android::BnInterface<IPermissionChecker> {
public:
  static constexpr uint32_t TRANSACTION_checkPermission = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_finishDataDelivery = ::android::IBinder::FIRST_CALL_TRANSACTION + 1;
  static constexpr uint32_t TRANSACTION_checkOp = ::android::IBinder::FIRST_CALL_TRANSACTION + 2;
  explicit BnPermissionChecker();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnPermissionChecker

}  // namespace permission

}  // namespace android
