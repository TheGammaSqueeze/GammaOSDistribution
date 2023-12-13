#pragma once

#include <android/binder_to_string.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <string>
#include <tuple>
#include <utils/String16.h>

namespace android {

namespace security {

namespace identity {

class RequestEntryParcel : public ::android::Parcelable {
public:
  inline bool operator!=(const RequestEntryParcel& rhs) const {
    return std::tie(name) != std::tie(rhs.name);
  }
  inline bool operator<(const RequestEntryParcel& rhs) const {
    return std::tie(name) < std::tie(rhs.name);
  }
  inline bool operator<=(const RequestEntryParcel& rhs) const {
    return std::tie(name) <= std::tie(rhs.name);
  }
  inline bool operator==(const RequestEntryParcel& rhs) const {
    return std::tie(name) == std::tie(rhs.name);
  }
  inline bool operator>(const RequestEntryParcel& rhs) const {
    return std::tie(name) > std::tie(rhs.name);
  }
  inline bool operator>=(const RequestEntryParcel& rhs) const {
    return std::tie(name) >= std::tie(rhs.name);
  }

  ::std::string name;
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.security.identity.RequestEntryParcel");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "RequestEntryParcel{";
    os << "name: " << ::android::internal::ToString(name);
    os << "}";
    return os.str();
  }
};  // class RequestEntryParcel

}  // namespace identity

}  // namespace security

}  // namespace android
