#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/hardware/security/keymint/IRemotelyProvisionedComponent.h>

namespace android {

namespace hardware {

namespace security {

namespace keymint {

class BpRemotelyProvisionedComponent : public ::android::BpInterface<IRemotelyProvisionedComponent> {
public:
  explicit BpRemotelyProvisionedComponent(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpRemotelyProvisionedComponent() = default;
  ::android::binder::Status getHardwareInfo(::android::hardware::security::keymint::RpcHardwareInfo* _aidl_return) override;
  ::android::binder::Status generateEcdsaP256KeyPair(bool testMode, ::android::hardware::security::keymint::MacedPublicKey* macedPublicKey, ::std::vector<uint8_t>* _aidl_return) override;
  ::android::binder::Status generateCertificateRequest(bool testMode, const ::std::vector<::android::hardware::security::keymint::MacedPublicKey>& keysToSign, const ::std::vector<uint8_t>& endpointEncryptionCertChain, const ::std::vector<uint8_t>& challenge, ::android::hardware::security::keymint::DeviceInfo* deviceInfo, ::android::hardware::security::keymint::ProtectedData* protectedData, ::std::vector<uint8_t>* _aidl_return) override;
  int32_t getInterfaceVersion() override;
  std::string getInterfaceHash() override;
private:
  int32_t cached_version_ = -1;
  std::string cached_hash_ = "-1";
  std::mutex cached_hash_mutex_;
};  // class BpRemotelyProvisionedComponent

}  // namespace keymint

}  // namespace security

}  // namespace hardware

}  // namespace android
