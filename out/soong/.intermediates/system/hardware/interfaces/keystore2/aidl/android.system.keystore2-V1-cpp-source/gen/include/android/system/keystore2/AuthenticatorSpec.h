#pragma once

#include <android/binder_to_string.h>
#include <android/hardware/security/keymint/HardwareAuthenticatorType.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <tuple>
#include <utils/String16.h>

namespace android {

namespace system {

namespace keystore2 {

class AuthenticatorSpec : public ::android::Parcelable {
public:
  inline bool operator!=(const AuthenticatorSpec& rhs) const {
    return std::tie(authenticatorType, authenticatorId) != std::tie(rhs.authenticatorType, rhs.authenticatorId);
  }
  inline bool operator<(const AuthenticatorSpec& rhs) const {
    return std::tie(authenticatorType, authenticatorId) < std::tie(rhs.authenticatorType, rhs.authenticatorId);
  }
  inline bool operator<=(const AuthenticatorSpec& rhs) const {
    return std::tie(authenticatorType, authenticatorId) <= std::tie(rhs.authenticatorType, rhs.authenticatorId);
  }
  inline bool operator==(const AuthenticatorSpec& rhs) const {
    return std::tie(authenticatorType, authenticatorId) == std::tie(rhs.authenticatorType, rhs.authenticatorId);
  }
  inline bool operator>(const AuthenticatorSpec& rhs) const {
    return std::tie(authenticatorType, authenticatorId) > std::tie(rhs.authenticatorType, rhs.authenticatorId);
  }
  inline bool operator>=(const AuthenticatorSpec& rhs) const {
    return std::tie(authenticatorType, authenticatorId) >= std::tie(rhs.authenticatorType, rhs.authenticatorId);
  }

  ::android::hardware::security::keymint::HardwareAuthenticatorType authenticatorType = ::android::hardware::security::keymint::HardwareAuthenticatorType(0);
  int64_t authenticatorId = int64_t(0L);
  ::android::Parcelable::Stability getStability() const override { return ::android::Parcelable::Stability::STABILITY_VINTF; }
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.system.keystore2.AuthenticatorSpec");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "AuthenticatorSpec{";
    os << "authenticatorType: " << ::android::internal::ToString(authenticatorType);
    os << ", authenticatorId: " << ::android::internal::ToString(authenticatorId);
    os << "}";
    return os.str();
  }
};  // class AuthenticatorSpec

}  // namespace keystore2

}  // namespace system

}  // namespace android
