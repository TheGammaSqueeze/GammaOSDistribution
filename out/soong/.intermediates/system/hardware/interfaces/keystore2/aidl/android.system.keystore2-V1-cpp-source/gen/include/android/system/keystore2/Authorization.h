#pragma once

#include <android/binder_to_string.h>
#include <android/hardware/security/keymint/KeyParameter.h>
#include <android/hardware/security/keymint/SecurityLevel.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <tuple>
#include <utils/String16.h>

namespace android {

namespace system {

namespace keystore2 {

class Authorization : public ::android::Parcelable {
public:
  inline bool operator!=(const Authorization& rhs) const {
    return std::tie(securityLevel, keyParameter) != std::tie(rhs.securityLevel, rhs.keyParameter);
  }
  inline bool operator<(const Authorization& rhs) const {
    return std::tie(securityLevel, keyParameter) < std::tie(rhs.securityLevel, rhs.keyParameter);
  }
  inline bool operator<=(const Authorization& rhs) const {
    return std::tie(securityLevel, keyParameter) <= std::tie(rhs.securityLevel, rhs.keyParameter);
  }
  inline bool operator==(const Authorization& rhs) const {
    return std::tie(securityLevel, keyParameter) == std::tie(rhs.securityLevel, rhs.keyParameter);
  }
  inline bool operator>(const Authorization& rhs) const {
    return std::tie(securityLevel, keyParameter) > std::tie(rhs.securityLevel, rhs.keyParameter);
  }
  inline bool operator>=(const Authorization& rhs) const {
    return std::tie(securityLevel, keyParameter) >= std::tie(rhs.securityLevel, rhs.keyParameter);
  }

  ::android::hardware::security::keymint::SecurityLevel securityLevel = ::android::hardware::security::keymint::SecurityLevel(0);
  ::android::hardware::security::keymint::KeyParameter keyParameter;
  ::android::Parcelable::Stability getStability() const override { return ::android::Parcelable::Stability::STABILITY_VINTF; }
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.system.keystore2.Authorization");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "Authorization{";
    os << "securityLevel: " << ::android::internal::ToString(securityLevel);
    os << ", keyParameter: " << ::android::internal::ToString(keyParameter);
    os << "}";
    return os.str();
  }
};  // class Authorization

}  // namespace keystore2

}  // namespace system

}  // namespace android
