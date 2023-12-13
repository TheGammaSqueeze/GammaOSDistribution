#pragma once

#include <android/binder_to_string.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <string>
#include <tuple>
#include <utils/String16.h>

namespace android {

namespace os {

namespace storage {

class CrateMetadata : public ::android::Parcelable {
public:
  inline bool operator!=(const CrateMetadata& rhs) const {
    return std::tie(uid, packageName, id) != std::tie(rhs.uid, rhs.packageName, rhs.id);
  }
  inline bool operator<(const CrateMetadata& rhs) const {
    return std::tie(uid, packageName, id) < std::tie(rhs.uid, rhs.packageName, rhs.id);
  }
  inline bool operator<=(const CrateMetadata& rhs) const {
    return std::tie(uid, packageName, id) <= std::tie(rhs.uid, rhs.packageName, rhs.id);
  }
  inline bool operator==(const CrateMetadata& rhs) const {
    return std::tie(uid, packageName, id) == std::tie(rhs.uid, rhs.packageName, rhs.id);
  }
  inline bool operator>(const CrateMetadata& rhs) const {
    return std::tie(uid, packageName, id) > std::tie(rhs.uid, rhs.packageName, rhs.id);
  }
  inline bool operator>=(const CrateMetadata& rhs) const {
    return std::tie(uid, packageName, id) >= std::tie(rhs.uid, rhs.packageName, rhs.id);
  }

  int32_t uid = int32_t(0);
  ::std::string packageName;
  ::std::string id;
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.os.storage.CrateMetadata");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "CrateMetadata{";
    os << "uid: " << ::android::internal::ToString(uid);
    os << ", packageName: " << ::android::internal::ToString(packageName);
    os << ", id: " << ::android::internal::ToString(id);
    os << "}";
    return os.str();
  }
};  // class CrateMetadata

}  // namespace storage

}  // namespace os

}  // namespace android
