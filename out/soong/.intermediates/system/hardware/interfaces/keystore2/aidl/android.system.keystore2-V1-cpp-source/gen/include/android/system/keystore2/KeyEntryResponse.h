#pragma once

#include <android/binder_to_string.h>
#include <android/system/keystore2/IKeystoreSecurityLevel.h>
#include <android/system/keystore2/KeyMetadata.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <optional>
#include <tuple>
#include <utils/String16.h>

namespace android {

namespace system {

namespace keystore2 {

class KeyEntryResponse : public ::android::Parcelable {
public:
  inline bool operator!=(const KeyEntryResponse& rhs) const {
    return std::tie(iSecurityLevel, metadata) != std::tie(rhs.iSecurityLevel, rhs.metadata);
  }
  inline bool operator<(const KeyEntryResponse& rhs) const {
    return std::tie(iSecurityLevel, metadata) < std::tie(rhs.iSecurityLevel, rhs.metadata);
  }
  inline bool operator<=(const KeyEntryResponse& rhs) const {
    return std::tie(iSecurityLevel, metadata) <= std::tie(rhs.iSecurityLevel, rhs.metadata);
  }
  inline bool operator==(const KeyEntryResponse& rhs) const {
    return std::tie(iSecurityLevel, metadata) == std::tie(rhs.iSecurityLevel, rhs.metadata);
  }
  inline bool operator>(const KeyEntryResponse& rhs) const {
    return std::tie(iSecurityLevel, metadata) > std::tie(rhs.iSecurityLevel, rhs.metadata);
  }
  inline bool operator>=(const KeyEntryResponse& rhs) const {
    return std::tie(iSecurityLevel, metadata) >= std::tie(rhs.iSecurityLevel, rhs.metadata);
  }

  ::android::sp<::android::system::keystore2::IKeystoreSecurityLevel> iSecurityLevel;
  ::android::system::keystore2::KeyMetadata metadata;
  ::android::Parcelable::Stability getStability() const override { return ::android::Parcelable::Stability::STABILITY_VINTF; }
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.system.keystore2.KeyEntryResponse");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "KeyEntryResponse{";
    os << "iSecurityLevel: " << ::android::internal::ToString(iSecurityLevel);
    os << ", metadata: " << ::android::internal::ToString(metadata);
    os << "}";
    return os.str();
  }
};  // class KeyEntryResponse

}  // namespace keystore2

}  // namespace system

}  // namespace android
