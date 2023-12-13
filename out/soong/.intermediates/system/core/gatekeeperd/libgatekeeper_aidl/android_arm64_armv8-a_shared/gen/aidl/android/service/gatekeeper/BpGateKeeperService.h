#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/service/gatekeeper/IGateKeeperService.h>

namespace android {

namespace service {

namespace gatekeeper {

class BpGateKeeperService : public ::android::BpInterface<IGateKeeperService> {
public:
  explicit BpGateKeeperService(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpGateKeeperService() = default;
  ::android::binder::Status enroll(int32_t userId, const ::std::optional<::std::vector<uint8_t>>& currentPasswordHandle, const ::std::optional<::std::vector<uint8_t>>& currentPassword, const ::std::vector<uint8_t>& desiredPassword, ::android::service::gatekeeper::GateKeeperResponse* _aidl_return) override;
  ::android::binder::Status verify(int32_t userId, const ::std::vector<uint8_t>& enrolledPasswordHandle, const ::std::vector<uint8_t>& providedPassword, ::android::service::gatekeeper::GateKeeperResponse* _aidl_return) override;
  ::android::binder::Status verifyChallenge(int32_t userId, int64_t challenge, const ::std::vector<uint8_t>& enrolledPasswordHandle, const ::std::vector<uint8_t>& providedPassword, ::android::service::gatekeeper::GateKeeperResponse* _aidl_return) override;
  ::android::binder::Status getSecureUserId(int32_t userId, int64_t* _aidl_return) override;
  ::android::binder::Status clearSecureUserId(int32_t userId) override;
  ::android::binder::Status reportDeviceSetupComplete() override;
};  // class BpGateKeeperService

}  // namespace gatekeeper

}  // namespace service

}  // namespace android
