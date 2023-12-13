#pragma once

#include <android/binder_to_string.h>
#include <android/hardware/security/keymint/SecurityLevel.h>
#include <android/system/keystore2/Authorization.h>
#include <android/system/keystore2/KeyDescriptor.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <optional>
#include <tuple>
#include <utils/String16.h>
#include <vector>

namespace android {

namespace system {

namespace keystore2 {

class KeyMetadata : public ::android::Parcelable {
public:
  inline bool operator!=(const KeyMetadata& rhs) const {
    return std::tie(key, keySecurityLevel, authorizations, certificate, certificateChain, modificationTimeMs) != std::tie(rhs.key, rhs.keySecurityLevel, rhs.authorizations, rhs.certificate, rhs.certificateChain, rhs.modificationTimeMs);
  }
  inline bool operator<(const KeyMetadata& rhs) const {
    return std::tie(key, keySecurityLevel, authorizations, certificate, certificateChain, modificationTimeMs) < std::tie(rhs.key, rhs.keySecurityLevel, rhs.authorizations, rhs.certificate, rhs.certificateChain, rhs.modificationTimeMs);
  }
  inline bool operator<=(const KeyMetadata& rhs) const {
    return std::tie(key, keySecurityLevel, authorizations, certificate, certificateChain, modificationTimeMs) <= std::tie(rhs.key, rhs.keySecurityLevel, rhs.authorizations, rhs.certificate, rhs.certificateChain, rhs.modificationTimeMs);
  }
  inline bool operator==(const KeyMetadata& rhs) const {
    return std::tie(key, keySecurityLevel, authorizations, certificate, certificateChain, modificationTimeMs) == std::tie(rhs.key, rhs.keySecurityLevel, rhs.authorizations, rhs.certificate, rhs.certificateChain, rhs.modificationTimeMs);
  }
  inline bool operator>(const KeyMetadata& rhs) const {
    return std::tie(key, keySecurityLevel, authorizations, certificate, certificateChain, modificationTimeMs) > std::tie(rhs.key, rhs.keySecurityLevel, rhs.authorizations, rhs.certificate, rhs.certificateChain, rhs.modificationTimeMs);
  }
  inline bool operator>=(const KeyMetadata& rhs) const {
    return std::tie(key, keySecurityLevel, authorizations, certificate, certificateChain, modificationTimeMs) >= std::tie(rhs.key, rhs.keySecurityLevel, rhs.authorizations, rhs.certificate, rhs.certificateChain, rhs.modificationTimeMs);
  }

  ::android::system::keystore2::KeyDescriptor key;
  ::android::hardware::security::keymint::SecurityLevel keySecurityLevel = ::android::hardware::security::keymint::SecurityLevel(0);
  ::std::vector<::android::system::keystore2::Authorization> authorizations;
  ::std::optional<::std::vector<uint8_t>> certificate;
  ::std::optional<::std::vector<uint8_t>> certificateChain;
  int64_t modificationTimeMs = int64_t(0L);
  ::android::Parcelable::Stability getStability() const override { return ::android::Parcelable::Stability::STABILITY_VINTF; }
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.system.keystore2.KeyMetadata");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "KeyMetadata{";
    os << "key: " << ::android::internal::ToString(key);
    os << ", keySecurityLevel: " << ::android::internal::ToString(keySecurityLevel);
    os << ", authorizations: " << ::android::internal::ToString(authorizations);
    os << ", certificate: " << ::android::internal::ToString(certificate);
    os << ", certificateChain: " << ::android::internal::ToString(certificateChain);
    os << ", modificationTimeMs: " << ::android::internal::ToString(modificationTimeMs);
    os << "}";
    return os.str();
  }
};  // class KeyMetadata

}  // namespace keystore2

}  // namespace system

}  // namespace android
