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

class FabricatedOverlayInternalEntry : public ::android::Parcelable {
public:
  inline bool operator!=(const FabricatedOverlayInternalEntry& rhs) const {
    return std::tie(resourceName, dataType, data) != std::tie(rhs.resourceName, rhs.dataType, rhs.data);
  }
  inline bool operator<(const FabricatedOverlayInternalEntry& rhs) const {
    return std::tie(resourceName, dataType, data) < std::tie(rhs.resourceName, rhs.dataType, rhs.data);
  }
  inline bool operator<=(const FabricatedOverlayInternalEntry& rhs) const {
    return std::tie(resourceName, dataType, data) <= std::tie(rhs.resourceName, rhs.dataType, rhs.data);
  }
  inline bool operator==(const FabricatedOverlayInternalEntry& rhs) const {
    return std::tie(resourceName, dataType, data) == std::tie(rhs.resourceName, rhs.dataType, rhs.data);
  }
  inline bool operator>(const FabricatedOverlayInternalEntry& rhs) const {
    return std::tie(resourceName, dataType, data) > std::tie(rhs.resourceName, rhs.dataType, rhs.data);
  }
  inline bool operator>=(const FabricatedOverlayInternalEntry& rhs) const {
    return std::tie(resourceName, dataType, data) >= std::tie(rhs.resourceName, rhs.dataType, rhs.data);
  }

  ::std::string resourceName;
  int32_t dataType = int32_t(0);
  int32_t data = int32_t(0);
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.os.FabricatedOverlayInternalEntry");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "FabricatedOverlayInternalEntry{";
    os << "resourceName: " << ::android::internal::ToString(resourceName);
    os << ", dataType: " << ::android::internal::ToString(dataType);
    os << ", data: " << ::android::internal::ToString(data);
    os << "}";
    return os.str();
  }
};  // class FabricatedOverlayInternalEntry

}  // namespace os

}  // namespace android
