#pragma once

#include <android/apex/CompressedApexInfo.h>
#include <android/binder_to_string.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <tuple>
#include <utils/String16.h>
#include <vector>

namespace android {

namespace apex {

class CompressedApexInfoList : public ::android::Parcelable {
public:
  inline bool operator!=(const CompressedApexInfoList& rhs) const {
    return std::tie(apexInfos) != std::tie(rhs.apexInfos);
  }
  inline bool operator<(const CompressedApexInfoList& rhs) const {
    return std::tie(apexInfos) < std::tie(rhs.apexInfos);
  }
  inline bool operator<=(const CompressedApexInfoList& rhs) const {
    return std::tie(apexInfos) <= std::tie(rhs.apexInfos);
  }
  inline bool operator==(const CompressedApexInfoList& rhs) const {
    return std::tie(apexInfos) == std::tie(rhs.apexInfos);
  }
  inline bool operator>(const CompressedApexInfoList& rhs) const {
    return std::tie(apexInfos) > std::tie(rhs.apexInfos);
  }
  inline bool operator>=(const CompressedApexInfoList& rhs) const {
    return std::tie(apexInfos) >= std::tie(rhs.apexInfos);
  }

  ::std::vector<::android::apex::CompressedApexInfo> apexInfos;
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.apex.CompressedApexInfoList");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "CompressedApexInfoList{";
    os << "apexInfos: " << ::android::internal::ToString(apexInfos);
    os << "}";
    return os.str();
  }
};  // class CompressedApexInfoList

}  // namespace apex

}  // namespace android
