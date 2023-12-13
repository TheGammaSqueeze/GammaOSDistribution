#pragma once

#include <android/binder_to_string.h>
#include <android/hardware/security/keymint/KeyParameter.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <tuple>
#include <utils/String16.h>
#include <vector>

namespace android {

namespace hardware {

namespace security {

namespace keymint {

class AttestationKey : public ::android::Parcelable {
public:
  inline bool operator!=(const AttestationKey& rhs) const {
    return std::tie(keyBlob, attestKeyParams, issuerSubjectName) != std::tie(rhs.keyBlob, rhs.attestKeyParams, rhs.issuerSubjectName);
  }
  inline bool operator<(const AttestationKey& rhs) const {
    return std::tie(keyBlob, attestKeyParams, issuerSubjectName) < std::tie(rhs.keyBlob, rhs.attestKeyParams, rhs.issuerSubjectName);
  }
  inline bool operator<=(const AttestationKey& rhs) const {
    return std::tie(keyBlob, attestKeyParams, issuerSubjectName) <= std::tie(rhs.keyBlob, rhs.attestKeyParams, rhs.issuerSubjectName);
  }
  inline bool operator==(const AttestationKey& rhs) const {
    return std::tie(keyBlob, attestKeyParams, issuerSubjectName) == std::tie(rhs.keyBlob, rhs.attestKeyParams, rhs.issuerSubjectName);
  }
  inline bool operator>(const AttestationKey& rhs) const {
    return std::tie(keyBlob, attestKeyParams, issuerSubjectName) > std::tie(rhs.keyBlob, rhs.attestKeyParams, rhs.issuerSubjectName);
  }
  inline bool operator>=(const AttestationKey& rhs) const {
    return std::tie(keyBlob, attestKeyParams, issuerSubjectName) >= std::tie(rhs.keyBlob, rhs.attestKeyParams, rhs.issuerSubjectName);
  }

  ::std::vector<uint8_t> keyBlob;
  ::std::vector<::android::hardware::security::keymint::KeyParameter> attestKeyParams;
  ::std::vector<uint8_t> issuerSubjectName;
  ::android::Parcelable::Stability getStability() const override { return ::android::Parcelable::Stability::STABILITY_VINTF; }
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.hardware.security.keymint.AttestationKey");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "AttestationKey{";
    os << "keyBlob: " << ::android::internal::ToString(keyBlob);
    os << ", attestKeyParams: " << ::android::internal::ToString(attestKeyParams);
    os << ", issuerSubjectName: " << ::android::internal::ToString(issuerSubjectName);
    os << "}";
    return os.str();
  }
};  // class AttestationKey

}  // namespace keymint

}  // namespace security

}  // namespace hardware

}  // namespace android
