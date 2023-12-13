#pragma once

#include <android/binder_to_string.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <optional>
#include <string>
#include <tuple>
#include <utils/String16.h>

namespace android {

namespace media {

namespace permission {

class Identity : public ::android::Parcelable {
public:
  inline bool operator!=(const Identity& rhs) const {
    return std::tie(uid, pid, packageName, attributionTag) != std::tie(rhs.uid, rhs.pid, rhs.packageName, rhs.attributionTag);
  }
  inline bool operator<(const Identity& rhs) const {
    return std::tie(uid, pid, packageName, attributionTag) < std::tie(rhs.uid, rhs.pid, rhs.packageName, rhs.attributionTag);
  }
  inline bool operator<=(const Identity& rhs) const {
    return std::tie(uid, pid, packageName, attributionTag) <= std::tie(rhs.uid, rhs.pid, rhs.packageName, rhs.attributionTag);
  }
  inline bool operator==(const Identity& rhs) const {
    return std::tie(uid, pid, packageName, attributionTag) == std::tie(rhs.uid, rhs.pid, rhs.packageName, rhs.attributionTag);
  }
  inline bool operator>(const Identity& rhs) const {
    return std::tie(uid, pid, packageName, attributionTag) > std::tie(rhs.uid, rhs.pid, rhs.packageName, rhs.attributionTag);
  }
  inline bool operator>=(const Identity& rhs) const {
    return std::tie(uid, pid, packageName, attributionTag) >= std::tie(rhs.uid, rhs.pid, rhs.packageName, rhs.attributionTag);
  }

  int32_t uid = int32_t(-1);
  int32_t pid = int32_t(-1);
  ::std::optional<::std::string> packageName;
  ::std::optional<::std::string> attributionTag;
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.media.permission.Identity");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "Identity{";
    os << "uid: " << ::android::internal::ToString(uid);
    os << ", pid: " << ::android::internal::ToString(pid);
    os << ", packageName: " << ::android::internal::ToString(packageName);
    os << ", attributionTag: " << ::android::internal::ToString(attributionTag);
    os << "}";
    return os.str();
  }
};  // class Identity

}  // namespace permission

}  // namespace media

}  // namespace android
