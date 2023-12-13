#pragma once

#include <android/binder_to_string.h>
#include <android/security/identity/EntryParcel.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <string>
#include <tuple>
#include <utils/String16.h>
#include <vector>

namespace android {

namespace security {

namespace identity {

class EntryNamespaceParcel : public ::android::Parcelable {
public:
  inline bool operator!=(const EntryNamespaceParcel& rhs) const {
    return std::tie(namespaceName, entries) != std::tie(rhs.namespaceName, rhs.entries);
  }
  inline bool operator<(const EntryNamespaceParcel& rhs) const {
    return std::tie(namespaceName, entries) < std::tie(rhs.namespaceName, rhs.entries);
  }
  inline bool operator<=(const EntryNamespaceParcel& rhs) const {
    return std::tie(namespaceName, entries) <= std::tie(rhs.namespaceName, rhs.entries);
  }
  inline bool operator==(const EntryNamespaceParcel& rhs) const {
    return std::tie(namespaceName, entries) == std::tie(rhs.namespaceName, rhs.entries);
  }
  inline bool operator>(const EntryNamespaceParcel& rhs) const {
    return std::tie(namespaceName, entries) > std::tie(rhs.namespaceName, rhs.entries);
  }
  inline bool operator>=(const EntryNamespaceParcel& rhs) const {
    return std::tie(namespaceName, entries) >= std::tie(rhs.namespaceName, rhs.entries);
  }

  ::std::string namespaceName;
  ::std::vector<::android::security::identity::EntryParcel> entries;
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.security.identity.EntryNamespaceParcel");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "EntryNamespaceParcel{";
    os << "namespaceName: " << ::android::internal::ToString(namespaceName);
    os << ", entries: " << ::android::internal::ToString(entries);
    os << "}";
    return os.str();
  }
};  // class EntryNamespaceParcel

}  // namespace identity

}  // namespace security

}  // namespace android
