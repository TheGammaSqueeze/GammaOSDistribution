#pragma once

#include <android/binder_to_string.h>
#include <android/security/identity/ResultEntryParcel.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <string>
#include <tuple>
#include <utils/String16.h>
#include <vector>

namespace android {

namespace security {

namespace identity {

class ResultNamespaceParcel : public ::android::Parcelable {
public:
  inline bool operator!=(const ResultNamespaceParcel& rhs) const {
    return std::tie(namespaceName, entries) != std::tie(rhs.namespaceName, rhs.entries);
  }
  inline bool operator<(const ResultNamespaceParcel& rhs) const {
    return std::tie(namespaceName, entries) < std::tie(rhs.namespaceName, rhs.entries);
  }
  inline bool operator<=(const ResultNamespaceParcel& rhs) const {
    return std::tie(namespaceName, entries) <= std::tie(rhs.namespaceName, rhs.entries);
  }
  inline bool operator==(const ResultNamespaceParcel& rhs) const {
    return std::tie(namespaceName, entries) == std::tie(rhs.namespaceName, rhs.entries);
  }
  inline bool operator>(const ResultNamespaceParcel& rhs) const {
    return std::tie(namespaceName, entries) > std::tie(rhs.namespaceName, rhs.entries);
  }
  inline bool operator>=(const ResultNamespaceParcel& rhs) const {
    return std::tie(namespaceName, entries) >= std::tie(rhs.namespaceName, rhs.entries);
  }

  ::std::string namespaceName;
  ::std::vector<::android::security::identity::ResultEntryParcel> entries;
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.security.identity.ResultNamespaceParcel");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "ResultNamespaceParcel{";
    os << "namespaceName: " << ::android::internal::ToString(namespaceName);
    os << ", entries: " << ::android::internal::ToString(entries);
    os << "}";
    return os.str();
  }
};  // class ResultNamespaceParcel

}  // namespace identity

}  // namespace security

}  // namespace android
