#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/hardware/identity/IIdentityCredential.h>

namespace android {

namespace hardware {

namespace identity {

class BpIdentityCredential : public ::android::BpInterface<IIdentityCredential> {
public:
  explicit BpIdentityCredential(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpIdentityCredential() = default;
  ::android::binder::Status deleteCredential(::std::vector<uint8_t>* _aidl_return) override __attribute__((deprecated("use deleteCredentalWithChallenge() instead.")));
  ::android::binder::Status createEphemeralKeyPair(::std::vector<uint8_t>* _aidl_return) override;
  ::android::binder::Status setReaderEphemeralPublicKey(const ::std::vector<uint8_t>& publicKey) override;
  ::android::binder::Status createAuthChallenge(int64_t* _aidl_return) override;
  ::android::binder::Status startRetrieval(const ::std::vector<::android::hardware::identity::SecureAccessControlProfile>& accessControlProfiles, const ::android::hardware::keymaster::HardwareAuthToken& authToken, const ::std::vector<uint8_t>& itemsRequest, const ::std::vector<uint8_t>& signingKeyBlob, const ::std::vector<uint8_t>& sessionTranscript, const ::std::vector<uint8_t>& readerSignature, const ::std::vector<int32_t>& requestCounts) override;
  ::android::binder::Status startRetrieveEntryValue(const ::std::string& nameSpace, const ::std::string& name, int32_t entrySize, const ::std::vector<int32_t>& accessControlProfileIds) override;
  ::android::binder::Status retrieveEntryValue(const ::std::vector<uint8_t>& encryptedContent, ::std::vector<uint8_t>* _aidl_return) override;
  ::android::binder::Status finishRetrieval(::std::vector<uint8_t>* mac, ::std::vector<uint8_t>* deviceNameSpaces) override;
  ::android::binder::Status generateSigningKeyPair(::std::vector<uint8_t>* signingKeyBlob, ::android::hardware::identity::Certificate* _aidl_return) override;
  ::android::binder::Status setRequestedNamespaces(const ::std::vector<::android::hardware::identity::RequestNamespace>& requestNamespaces) override;
  ::android::binder::Status setVerificationToken(const ::android::hardware::keymaster::VerificationToken& verificationToken) override;
  ::android::binder::Status deleteCredentialWithChallenge(const ::std::vector<uint8_t>& challenge, ::std::vector<uint8_t>* _aidl_return) override;
  ::android::binder::Status proveOwnership(const ::std::vector<uint8_t>& challenge, ::std::vector<uint8_t>* _aidl_return) override;
  ::android::binder::Status updateCredential(::android::sp<::android::hardware::identity::IWritableIdentityCredential>* _aidl_return) override;
  int32_t getInterfaceVersion() override;
  std::string getInterfaceHash() override;
private:
  int32_t cached_version_ = -1;
  std::string cached_hash_ = "-1";
  std::mutex cached_hash_mutex_;
};  // class BpIdentityCredential

}  // namespace identity

}  // namespace hardware

}  // namespace android
