#pragma once

#include <android/binder_to_string.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <string>
#include <tuple>
#include <utils/String16.h>

namespace android {

namespace apex {

class ApexInfo : public ::android::Parcelable {
public:
  inline bool operator!=(const ApexInfo& rhs) const {
    return std::tie(moduleName, modulePath, preinstalledModulePath, versionCode, versionName, isFactory, isActive) != std::tie(rhs.moduleName, rhs.modulePath, rhs.preinstalledModulePath, rhs.versionCode, rhs.versionName, rhs.isFactory, rhs.isActive);
  }
  inline bool operator<(const ApexInfo& rhs) const {
    return std::tie(moduleName, modulePath, preinstalledModulePath, versionCode, versionName, isFactory, isActive) < std::tie(rhs.moduleName, rhs.modulePath, rhs.preinstalledModulePath, rhs.versionCode, rhs.versionName, rhs.isFactory, rhs.isActive);
  }
  inline bool operator<=(const ApexInfo& rhs) const {
    return std::tie(moduleName, modulePath, preinstalledModulePath, versionCode, versionName, isFactory, isActive) <= std::tie(rhs.moduleName, rhs.modulePath, rhs.preinstalledModulePath, rhs.versionCode, rhs.versionName, rhs.isFactory, rhs.isActive);
  }
  inline bool operator==(const ApexInfo& rhs) const {
    return std::tie(moduleName, modulePath, preinstalledModulePath, versionCode, versionName, isFactory, isActive) == std::tie(rhs.moduleName, rhs.modulePath, rhs.preinstalledModulePath, rhs.versionCode, rhs.versionName, rhs.isFactory, rhs.isActive);
  }
  inline bool operator>(const ApexInfo& rhs) const {
    return std::tie(moduleName, modulePath, preinstalledModulePath, versionCode, versionName, isFactory, isActive) > std::tie(rhs.moduleName, rhs.modulePath, rhs.preinstalledModulePath, rhs.versionCode, rhs.versionName, rhs.isFactory, rhs.isActive);
  }
  inline bool operator>=(const ApexInfo& rhs) const {
    return std::tie(moduleName, modulePath, preinstalledModulePath, versionCode, versionName, isFactory, isActive) >= std::tie(rhs.moduleName, rhs.modulePath, rhs.preinstalledModulePath, rhs.versionCode, rhs.versionName, rhs.isFactory, rhs.isActive);
  }

  ::std::string moduleName;
  ::std::string modulePath;
  ::std::string preinstalledModulePath;
  int64_t versionCode = int64_t(0L);
  ::std::string versionName;
  bool isFactory = bool(false);
  bool isActive = bool(false);
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.apex.ApexInfo");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "ApexInfo{";
    os << "moduleName: " << ::android::internal::ToString(moduleName);
    os << ", modulePath: " << ::android::internal::ToString(modulePath);
    os << ", preinstalledModulePath: " << ::android::internal::ToString(preinstalledModulePath);
    os << ", versionCode: " << ::android::internal::ToString(versionCode);
    os << ", versionName: " << ::android::internal::ToString(versionName);
    os << ", isFactory: " << ::android::internal::ToString(isFactory);
    os << ", isActive: " << ::android::internal::ToString(isActive);
    os << "}";
    return os.str();
  }
};  // class ApexInfo

}  // namespace apex

}  // namespace android
