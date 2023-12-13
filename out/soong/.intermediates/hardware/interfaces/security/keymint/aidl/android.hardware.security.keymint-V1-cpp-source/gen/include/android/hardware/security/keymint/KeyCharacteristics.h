#pragma once

#include <android/binder_to_string.h>
#include <android/hardware/security/keymint/KeyParameter.h>
#include <android/hardware/security/keymint/SecurityLevel.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <tuple>
#include <utils/String16.h>
#include <vector>

namespace android {

namespace hardware {

namespace security {

namespace keymint {

class KeyCharacteristics : public ::android::Parcelable {
public:
  inline bool operator!=(const KeyCharacteristics& rhs) const {
    return std::tie(securityLevel, authorizations) != std::tie(rhs.securityLevel, rhs.authorizations);
  }
  inline bool operator<(const KeyCharacteristics& rhs) const {
    return std::tie(securityLevel, authorizations) < std::tie(rhs.securityLevel, rhs.authorizations);
  }
  inline bool operator<=(const KeyCharacteristics& rhs) const {
    return std::tie(securityLevel, authorizations) <= std::tie(rhs.securityLevel, rhs.authorizations);
  }
  inline bool operator==(const KeyCharacteristics& rhs) const {
    return std::tie(securityLevel, authorizations) == std::tie(rhs.securityLevel, rhs.authorizations);
  }
  inline bool operator>(const KeyCharacteristics& rhs) const {
    return std::tie(securityLevel, authorizations) > std::tie(rhs.securityLevel, rhs.authorizations);
  }
  inline bool operator>=(const KeyCharacteristics& rhs) const {
    return std::tie(securityLevel, authorizations) >= std::tie(rhs.securityLevel, rhs.authorizations);
  }

  ::android::hardware::security::keymint::SecurityLevel securityLevel = ::android::hardware::security::keymint::SecurityLevel(::android::hardware::security::keymint::SecurityLevel::SOFTWARE);
  ::std::vector<::android::hardware::security::keymint::KeyParameter> authorizations;
  ::android::Parcelable::Stability getStability() const override { return ::android::Parcelable::Stability::STABILITY_VINTF; }
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.hardware.security.keymint.KeyCharacteristics");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "KeyCharacteristics{";
    os << "securityLevel: " << ::android::internal::ToString(securityLevel);
    os << ", authorizations: " << ::android::internal::ToString(authorizations);
    os << "}";
    return os.str();
  }
};  // class KeyCharacteristics

}  // namespace keymint

}  // namespace security

}  // namespace hardware

}  // namespace android
