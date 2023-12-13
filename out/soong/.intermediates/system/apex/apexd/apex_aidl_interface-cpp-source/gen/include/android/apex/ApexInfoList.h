#pragma once

#include <android/apex/ApexInfo.h>
#include <android/binder_to_string.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <tuple>
#include <utils/String16.h>
#include <vector>

namespace android {

namespace apex {

class ApexInfoList : public ::android::Parcelable {
public:
  inline bool operator!=(const ApexInfoList& rhs) const {
    return std::tie(apexInfos) != std::tie(rhs.apexInfos);
  }
  inline bool operator<(const ApexInfoList& rhs) const {
    return std::tie(apexInfos) < std::tie(rhs.apexInfos);
  }
  inline bool operator<=(const ApexInfoList& rhs) const {
    return std::tie(apexInfos) <= std::tie(rhs.apexInfos);
  }
  inline bool operator==(const ApexInfoList& rhs) const {
    return std::tie(apexInfos) == std::tie(rhs.apexInfos);
  }
  inline bool operator>(const ApexInfoList& rhs) const {
    return std::tie(apexInfos) > std::tie(rhs.apexInfos);
  }
  inline bool operator>=(const ApexInfoList& rhs) const {
    return std::tie(apexInfos) >= std::tie(rhs.apexInfos);
  }

  ::std::vector<::android::apex::ApexInfo> apexInfos;
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.apex.ApexInfoList");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "ApexInfoList{";
    os << "apexInfos: " << ::android::internal::ToString(apexInfos);
    os << "}";
    return os.str();
  }
};  // class ApexInfoList

}  // namespace apex

}  // namespace android
