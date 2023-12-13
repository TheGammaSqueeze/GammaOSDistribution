#pragma once

#include <android/binder_to_string.h>
#include <android/os/FabricatedOverlayInternalEntry.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <string>
#include <tuple>
#include <utils/String16.h>
#include <vector>

namespace android {

namespace os {

class FabricatedOverlayInternal : public ::android::Parcelable {
public:
  inline bool operator!=(const FabricatedOverlayInternal& rhs) const {
    return std::tie(packageName, overlayName, targetPackageName, targetOverlayable, entries) != std::tie(rhs.packageName, rhs.overlayName, rhs.targetPackageName, rhs.targetOverlayable, rhs.entries);
  }
  inline bool operator<(const FabricatedOverlayInternal& rhs) const {
    return std::tie(packageName, overlayName, targetPackageName, targetOverlayable, entries) < std::tie(rhs.packageName, rhs.overlayName, rhs.targetPackageName, rhs.targetOverlayable, rhs.entries);
  }
  inline bool operator<=(const FabricatedOverlayInternal& rhs) const {
    return std::tie(packageName, overlayName, targetPackageName, targetOverlayable, entries) <= std::tie(rhs.packageName, rhs.overlayName, rhs.targetPackageName, rhs.targetOverlayable, rhs.entries);
  }
  inline bool operator==(const FabricatedOverlayInternal& rhs) const {
    return std::tie(packageName, overlayName, targetPackageName, targetOverlayable, entries) == std::tie(rhs.packageName, rhs.overlayName, rhs.targetPackageName, rhs.targetOverlayable, rhs.entries);
  }
  inline bool operator>(const FabricatedOverlayInternal& rhs) const {
    return std::tie(packageName, overlayName, targetPackageName, targetOverlayable, entries) > std::tie(rhs.packageName, rhs.overlayName, rhs.targetPackageName, rhs.targetOverlayable, rhs.entries);
  }
  inline bool operator>=(const FabricatedOverlayInternal& rhs) const {
    return std::tie(packageName, overlayName, targetPackageName, targetOverlayable, entries) >= std::tie(rhs.packageName, rhs.overlayName, rhs.targetPackageName, rhs.targetOverlayable, rhs.entries);
  }

  ::std::string packageName;
  ::std::string overlayName;
  ::std::string targetPackageName;
  ::std::string targetOverlayable;
  ::std::vector<::android::os::FabricatedOverlayInternalEntry> entries;
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.os.FabricatedOverlayInternal");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "FabricatedOverlayInternal{";
    os << "packageName: " << ::android::internal::ToString(packageName);
    os << ", overlayName: " << ::android::internal::ToString(overlayName);
    os << ", targetPackageName: " << ::android::internal::ToString(targetPackageName);
    os << ", targetOverlayable: " << ::android::internal::ToString(targetOverlayable);
    os << ", entries: " << ::android::internal::ToString(entries);
    os << "}";
    return os.str();
  }
};  // class FabricatedOverlayInternal

}  // namespace os

}  // namespace android
