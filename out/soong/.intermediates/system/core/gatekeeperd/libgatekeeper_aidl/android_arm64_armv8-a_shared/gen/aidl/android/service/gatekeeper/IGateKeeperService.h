#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <gatekeeper/GateKeeperResponse.h>
#include <optional>
#include <utils/StrongPointer.h>
#include <vector>

namespace android {

namespace service {

namespace gatekeeper {

class IGateKeeperService : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(GateKeeperService)
  virtual ::android::binder::Status enroll(int32_t userId, const ::std::optional<::std::vector<uint8_t>>& currentPasswordHandle, const ::std::optional<::std::vector<uint8_t>>& currentPassword, const ::std::vector<uint8_t>& desiredPassword, ::android::service::gatekeeper::GateKeeperResponse* _aidl_return) = 0;
  virtual ::android::binder::Status verify(int32_t userId, const ::std::vector<uint8_t>& enrolledPasswordHandle, const ::std::vector<uint8_t>& providedPassword, ::android::service::gatekeeper::GateKeeperResponse* _aidl_return) = 0;
  virtual ::android::binder::Status verifyChallenge(int32_t userId, int64_t challenge, const ::std::vector<uint8_t>& enrolledPasswordHandle, const ::std::vector<uint8_t>& providedPassword, ::android::service::gatekeeper::GateKeeperResponse* _aidl_return) = 0;
  virtual ::android::binder::Status getSecureUserId(int32_t userId, int64_t* _aidl_return) = 0;
  virtual ::android::binder::Status clearSecureUserId(int32_t userId) = 0;
  virtual ::android::binder::Status reportDeviceSetupComplete() = 0;
};  // class IGateKeeperService

class IGateKeeperServiceDefault : public IGateKeeperService {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status enroll(int32_t, const ::std::optional<::std::vector<uint8_t>>&, const ::std::optional<::std::vector<uint8_t>>&, const ::std::vector<uint8_t>&, ::android::service::gatekeeper::GateKeeperResponse*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status verify(int32_t, const ::std::vector<uint8_t>&, const ::std::vector<uint8_t>&, ::android::service::gatekeeper::GateKeeperResponse*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status verifyChallenge(int32_t, int64_t, const ::std::vector<uint8_t>&, const ::std::vector<uint8_t>&, ::android::service::gatekeeper::GateKeeperResponse*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getSecureUserId(int32_t, int64_t*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status clearSecureUserId(int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status reportDeviceSetupComplete() override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IGateKeeperServiceDefault

}  // namespace gatekeeper

}  // namespace service

}  // namespace android
