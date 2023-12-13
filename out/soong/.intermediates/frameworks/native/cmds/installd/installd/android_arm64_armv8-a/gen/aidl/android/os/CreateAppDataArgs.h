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

namespace os {

class CreateAppDataArgs : public ::android::Parcelable {
public:
  inline bool operator!=(const CreateAppDataArgs& rhs) const {
    return std::tie(uuid, packageName, userId, flags, appId, seInfo, targetSdkVersion) != std::tie(rhs.uuid, rhs.packageName, rhs.userId, rhs.flags, rhs.appId, rhs.seInfo, rhs.targetSdkVersion);
  }
  inline bool operator<(const CreateAppDataArgs& rhs) const {
    return std::tie(uuid, packageName, userId, flags, appId, seInfo, targetSdkVersion) < std::tie(rhs.uuid, rhs.packageName, rhs.userId, rhs.flags, rhs.appId, rhs.seInfo, rhs.targetSdkVersion);
  }
  inline bool operator<=(const CreateAppDataArgs& rhs) const {
    return std::tie(uuid, packageName, userId, flags, appId, seInfo, targetSdkVersion) <= std::tie(rhs.uuid, rhs.packageName, rhs.userId, rhs.flags, rhs.appId, rhs.seInfo, rhs.targetSdkVersion);
  }
  inline bool operator==(const CreateAppDataArgs& rhs) const {
    return std::tie(uuid, packageName, userId, flags, appId, seInfo, targetSdkVersion) == std::tie(rhs.uuid, rhs.packageName, rhs.userId, rhs.flags, rhs.appId, rhs.seInfo, rhs.targetSdkVersion);
  }
  inline bool operator>(const CreateAppDataArgs& rhs) const {
    return std::tie(uuid, packageName, userId, flags, appId, seInfo, targetSdkVersion) > std::tie(rhs.uuid, rhs.packageName, rhs.userId, rhs.flags, rhs.appId, rhs.seInfo, rhs.targetSdkVersion);
  }
  inline bool operator>=(const CreateAppDataArgs& rhs) const {
    return std::tie(uuid, packageName, userId, flags, appId, seInfo, targetSdkVersion) >= std::tie(rhs.uuid, rhs.packageName, rhs.userId, rhs.flags, rhs.appId, rhs.seInfo, rhs.targetSdkVersion);
  }

  ::std::optional<::std::string> uuid;
  ::std::string packageName;
  int32_t userId = int32_t(0);
  int32_t flags = int32_t(0);
  int32_t appId = int32_t(0);
  ::std::string seInfo;
  int32_t targetSdkVersion = int32_t(0);
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.os.CreateAppDataArgs");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "CreateAppDataArgs{";
    os << "uuid: " << ::android::internal::ToString(uuid);
    os << ", packageName: " << ::android::internal::ToString(packageName);
    os << ", userId: " << ::android::internal::ToString(userId);
    os << ", flags: " << ::android::internal::ToString(flags);
    os << ", appId: " << ::android::internal::ToString(appId);
    os << ", seInfo: " << ::android::internal::ToString(seInfo);
    os << ", targetSdkVersion: " << ::android::internal::ToString(targetSdkVersion);
    os << "}";
    return os.str();
  }
};  // class CreateAppDataArgs

}  // namespace os

}  // namespace android
