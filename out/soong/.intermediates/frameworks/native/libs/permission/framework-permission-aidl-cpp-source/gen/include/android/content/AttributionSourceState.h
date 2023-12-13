#pragma once

#include <android/binder_to_string.h>
#include <android/content/AttributionSourceState.h>
#include <binder/IBinder.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <optional>
#include <string>
#include <tuple>
#include <utils/String16.h>
#include <vector>

namespace android {

namespace content {

class AttributionSourceState : public ::android::Parcelable {
public:
  inline bool operator!=(const AttributionSourceState& rhs) const {
    return std::tie(pid, uid, packageName, attributionTag, token, renouncedPermissions, next) != std::tie(rhs.pid, rhs.uid, rhs.packageName, rhs.attributionTag, rhs.token, rhs.renouncedPermissions, rhs.next);
  }
  inline bool operator<(const AttributionSourceState& rhs) const {
    return std::tie(pid, uid, packageName, attributionTag, token, renouncedPermissions, next) < std::tie(rhs.pid, rhs.uid, rhs.packageName, rhs.attributionTag, rhs.token, rhs.renouncedPermissions, rhs.next);
  }
  inline bool operator<=(const AttributionSourceState& rhs) const {
    return std::tie(pid, uid, packageName, attributionTag, token, renouncedPermissions, next) <= std::tie(rhs.pid, rhs.uid, rhs.packageName, rhs.attributionTag, rhs.token, rhs.renouncedPermissions, rhs.next);
  }
  inline bool operator==(const AttributionSourceState& rhs) const {
    return std::tie(pid, uid, packageName, attributionTag, token, renouncedPermissions, next) == std::tie(rhs.pid, rhs.uid, rhs.packageName, rhs.attributionTag, rhs.token, rhs.renouncedPermissions, rhs.next);
  }
  inline bool operator>(const AttributionSourceState& rhs) const {
    return std::tie(pid, uid, packageName, attributionTag, token, renouncedPermissions, next) > std::tie(rhs.pid, rhs.uid, rhs.packageName, rhs.attributionTag, rhs.token, rhs.renouncedPermissions, rhs.next);
  }
  inline bool operator>=(const AttributionSourceState& rhs) const {
    return std::tie(pid, uid, packageName, attributionTag, token, renouncedPermissions, next) >= std::tie(rhs.pid, rhs.uid, rhs.packageName, rhs.attributionTag, rhs.token, rhs.renouncedPermissions, rhs.next);
  }

  int32_t pid = int32_t(-1);
  int32_t uid = int32_t(-1);
  ::std::optional<::std::string> packageName;
  ::std::optional<::std::string> attributionTag;
  ::android::sp<::android::IBinder> token;
  ::std::optional<::std::vector<::std::optional<::std::string>>> renouncedPermissions;
  ::std::vector<::android::content::AttributionSourceState> next;
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.content.AttributionSourceState");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "AttributionSourceState{";
    os << "pid: " << ::android::internal::ToString(pid);
    os << ", uid: " << ::android::internal::ToString(uid);
    os << ", packageName: " << ::android::internal::ToString(packageName);
    os << ", attributionTag: " << ::android::internal::ToString(attributionTag);
    os << ", token: " << ::android::internal::ToString(token);
    os << ", renouncedPermissions: " << ::android::internal::ToString(renouncedPermissions);
    os << ", next: " << ::android::internal::ToString(next);
    os << "}";
    return os.str();
  }
};  // class AttributionSourceState

}  // namespace content

}  // namespace android
