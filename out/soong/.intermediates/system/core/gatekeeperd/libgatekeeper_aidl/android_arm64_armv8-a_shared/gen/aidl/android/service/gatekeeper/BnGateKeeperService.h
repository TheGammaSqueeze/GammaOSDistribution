#pragma once

#include <binder/IInterface.h>
#include <android/service/gatekeeper/IGateKeeperService.h>

namespace android {

namespace service {

namespace gatekeeper {

class BnGateKeeperService : public ::android::BnInterface<IGateKeeperService> {
public:
  static constexpr uint32_t TRANSACTION_enroll = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_verify = ::android::IBinder::FIRST_CALL_TRANSACTION + 1;
  static constexpr uint32_t TRANSACTION_verifyChallenge = ::android::IBinder::FIRST_CALL_TRANSACTION + 2;
  static constexpr uint32_t TRANSACTION_getSecureUserId = ::android::IBinder::FIRST_CALL_TRANSACTION + 3;
  static constexpr uint32_t TRANSACTION_clearSecureUserId = ::android::IBinder::FIRST_CALL_TRANSACTION + 4;
  static constexpr uint32_t TRANSACTION_reportDeviceSetupComplete = ::android::IBinder::FIRST_CALL_TRANSACTION + 5;
  explicit BnGateKeeperService();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnGateKeeperService

}  // namespace gatekeeper

}  // namespace service

}  // namespace android
