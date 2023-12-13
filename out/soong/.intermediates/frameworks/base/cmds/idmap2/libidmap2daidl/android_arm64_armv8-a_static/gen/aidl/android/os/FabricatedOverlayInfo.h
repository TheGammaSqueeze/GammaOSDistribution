#pragma once

#include <android/binder_to_string.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <string>
#include <tuple>
#include <utils/String16.h>

namespace android {

namespace os {

class FabricatedOverlayInfo : public ::android::Parcelable {
public:
  inline bool operator!=(const FabricatedOverlayInfo& rhs) const {
    return std::tie(path, packageName, overlayName, targetPackageName, targetOverlayable) != std::tie(rhs.path, rhs.packageName, rhs.overlayName, rhs.targetPackageName, rhs.targetOverlayable);
  }
  inline bool operator<(const FabricatedOverlayInfo& rhs) const {
    return std::tie(path, packageName, overlayName, targetPackageName, targetOverlayable) < std::tie(rhs.path, rhs.packageName, rhs.overlayName, rhs.targetPackageName, rhs.targetOverlayable);
  }
  inline bool operator<=(const FabricatedOverlayInfo& rhs) const {
    return std::tie(path, packageName, overlayName, targetPackageName, targetOverlayable) <= std::tie(rhs.path, rhs.packageName, rhs.overlayName, rhs.targetPackageName, rhs.targetOverlayable);
  }
  inline bool operator==(const FabricatedOverlayInfo& rhs) const {
    return std::tie(path, packageName, overlayName, targetPackageName, targetOverlayable) == std::tie(rhs.path, rhs.packageName, rhs.overlayName, rhs.targetPackageName, rhs.targetOverlayable);
  }
  inline bool operator>(const FabricatedOverlayInfo& rhs) const {
    return std::tie(path, packageName, overlayName, targetPackageName, targetOverlayable) > std::tie(rhs.path, rhs.packageName, rhs.overlayName, rhs.targetPackageName, rhs.targetOverlayable);
  }
  inline bool operator>=(const FabricatedOverlayInfo& rhs) const {
    return std::tie(path, packageName, overlayName, targetPackageName, targetOverlayable) >= std::tie(rhs.path, rhs.packageName, rhs.overlayName, rhs.targetPackageName, rhs.targetOverlayable);
  }

  ::std::string path;
  ::std::string packageName;
  ::std::string overlayName;
  ::std::string targetPackageName;
  ::std::string targetOverlayable;
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.os.FabricatedOverlayInfo");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "FabricatedOverlayInfo{";
    os << "path: " << ::android::internal::ToString(path);
    os << ", packageName: " << ::android::internal::ToString(packageName);
    os << ", overlayName: " << ::android::internal::ToString(overlayName);
    os << ", targetPackageName: " << ::android::internal::ToString(targetPackageName);
    os << ", targetOverlayable: " << ::android::internal::ToString(targetOverlayable);
    os << "}";
    return os.str();
  }
};  // class FabricatedOverlayInfo

}  // namespace os

}  // namespace android
