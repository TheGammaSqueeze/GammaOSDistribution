#pragma once

#include <android/binder_to_string.h>
#include <android/hardware/security/keymint/SecurityLevel.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <string>
#include <tuple>
#include <utils/String16.h>

namespace android {

namespace hardware {

namespace security {

namespace keymint {

class KeyMintHardwareInfo : public ::android::Parcelable {
public:
  inline bool operator!=(const KeyMintHardwareInfo& rhs) const {
    return std::tie(versionNumber, securityLevel, keyMintName, keyMintAuthorName, timestampTokenRequired) != std::tie(rhs.versionNumber, rhs.securityLevel, rhs.keyMintName, rhs.keyMintAuthorName, rhs.timestampTokenRequired);
  }
  inline bool operator<(const KeyMintHardwareInfo& rhs) const {
    return std::tie(versionNumber, securityLevel, keyMintName, keyMintAuthorName, timestampTokenRequired) < std::tie(rhs.versionNumber, rhs.securityLevel, rhs.keyMintName, rhs.keyMintAuthorName, rhs.timestampTokenRequired);
  }
  inline bool operator<=(const KeyMintHardwareInfo& rhs) const {
    return std::tie(versionNumber, securityLevel, keyMintName, keyMintAuthorName, timestampTokenRequired) <= std::tie(rhs.versionNumber, rhs.securityLevel, rhs.keyMintName, rhs.keyMintAuthorName, rhs.timestampTokenRequired);
  }
  inline bool operator==(const KeyMintHardwareInfo& rhs) const {
    return std::tie(versionNumber, securityLevel, keyMintName, keyMintAuthorName, timestampTokenRequired) == std::tie(rhs.versionNumber, rhs.securityLevel, rhs.keyMintName, rhs.keyMintAuthorName, rhs.timestampTokenRequired);
  }
  inline bool operator>(const KeyMintHardwareInfo& rhs) const {
    return std::tie(versionNumber, securityLevel, keyMintName, keyMintAuthorName, timestampTokenRequired) > std::tie(rhs.versionNumber, rhs.securityLevel, rhs.keyMintName, rhs.keyMintAuthorName, rhs.timestampTokenRequired);
  }
  inline bool operator>=(const KeyMintHardwareInfo& rhs) const {
    return std::tie(versionNumber, securityLevel, keyMintName, keyMintAuthorName, timestampTokenRequired) >= std::tie(rhs.versionNumber, rhs.securityLevel, rhs.keyMintName, rhs.keyMintAuthorName, rhs.timestampTokenRequired);
  }

  int32_t versionNumber = int32_t(0);
  ::android::hardware::security::keymint::SecurityLevel securityLevel = ::android::hardware::security::keymint::SecurityLevel(::android::hardware::security::keymint::SecurityLevel::SOFTWARE);
  ::std::string keyMintName;
  ::std::string keyMintAuthorName;
  bool timestampTokenRequired = bool(false);
  ::android::Parcelable::Stability getStability() const override { return ::android::Parcelable::Stability::STABILITY_VINTF; }
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.hardware.security.keymint.KeyMintHardwareInfo");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "KeyMintHardwareInfo{";
    os << "versionNumber: " << ::android::internal::ToString(versionNumber);
    os << ", securityLevel: " << ::android::internal::ToString(securityLevel);
    os << ", keyMintName: " << ::android::internal::ToString(keyMintName);
    os << ", keyMintAuthorName: " << ::android::internal::ToString(keyMintAuthorName);
    os << ", timestampTokenRequired: " << ::android::internal::ToString(timestampTokenRequired);
    os << "}";
    return os.str();
  }
};  // class KeyMintHardwareInfo

}  // namespace keymint

}  // namespace security

}  // namespace hardware

}  // namespace android
