#pragma once

#include <android/binder_to_string.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <string>
#include <tuple>
#include <utils/String16.h>
#include <vector>

namespace android {

namespace security {

namespace identity {

class SecurityHardwareInfoParcel : public ::android::Parcelable {
public:
  inline bool operator!=(const SecurityHardwareInfoParcel& rhs) const {
    return std::tie(directAccess, supportedDocTypes) != std::tie(rhs.directAccess, rhs.supportedDocTypes);
  }
  inline bool operator<(const SecurityHardwareInfoParcel& rhs) const {
    return std::tie(directAccess, supportedDocTypes) < std::tie(rhs.directAccess, rhs.supportedDocTypes);
  }
  inline bool operator<=(const SecurityHardwareInfoParcel& rhs) const {
    return std::tie(directAccess, supportedDocTypes) <= std::tie(rhs.directAccess, rhs.supportedDocTypes);
  }
  inline bool operator==(const SecurityHardwareInfoParcel& rhs) const {
    return std::tie(directAccess, supportedDocTypes) == std::tie(rhs.directAccess, rhs.supportedDocTypes);
  }
  inline bool operator>(const SecurityHardwareInfoParcel& rhs) const {
    return std::tie(directAccess, supportedDocTypes) > std::tie(rhs.directAccess, rhs.supportedDocTypes);
  }
  inline bool operator>=(const SecurityHardwareInfoParcel& rhs) const {
    return std::tie(directAccess, supportedDocTypes) >= std::tie(rhs.directAccess, rhs.supportedDocTypes);
  }

  bool directAccess = bool(false);
  ::std::vector<::std::string> supportedDocTypes;
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.security.identity.SecurityHardwareInfoParcel");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "SecurityHardwareInfoParcel{";
    os << "directAccess: " << ::android::internal::ToString(directAccess);
    os << ", supportedDocTypes: " << ::android::internal::ToString(supportedDocTypes);
    os << "}";
    return os.str();
  }
};  // class SecurityHardwareInfoParcel

}  // namespace identity

}  // namespace security

}  // namespace android
