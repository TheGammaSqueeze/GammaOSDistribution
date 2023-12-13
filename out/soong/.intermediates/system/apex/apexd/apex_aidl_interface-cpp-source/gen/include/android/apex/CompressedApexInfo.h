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

class CompressedApexInfo : public ::android::Parcelable {
public:
  inline bool operator!=(const CompressedApexInfo& rhs) const {
    return std::tie(moduleName, versionCode, decompressedSize) != std::tie(rhs.moduleName, rhs.versionCode, rhs.decompressedSize);
  }
  inline bool operator<(const CompressedApexInfo& rhs) const {
    return std::tie(moduleName, versionCode, decompressedSize) < std::tie(rhs.moduleName, rhs.versionCode, rhs.decompressedSize);
  }
  inline bool operator<=(const CompressedApexInfo& rhs) const {
    return std::tie(moduleName, versionCode, decompressedSize) <= std::tie(rhs.moduleName, rhs.versionCode, rhs.decompressedSize);
  }
  inline bool operator==(const CompressedApexInfo& rhs) const {
    return std::tie(moduleName, versionCode, decompressedSize) == std::tie(rhs.moduleName, rhs.versionCode, rhs.decompressedSize);
  }
  inline bool operator>(const CompressedApexInfo& rhs) const {
    return std::tie(moduleName, versionCode, decompressedSize) > std::tie(rhs.moduleName, rhs.versionCode, rhs.decompressedSize);
  }
  inline bool operator>=(const CompressedApexInfo& rhs) const {
    return std::tie(moduleName, versionCode, decompressedSize) >= std::tie(rhs.moduleName, rhs.versionCode, rhs.decompressedSize);
  }

  ::std::string moduleName;
  int64_t versionCode = int64_t(0L);
  int64_t decompressedSize = int64_t(0L);
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.apex.CompressedApexInfo");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "CompressedApexInfo{";
    os << "moduleName: " << ::android::internal::ToString(moduleName);
    os << ", versionCode: " << ::android::internal::ToString(versionCode);
    os << ", decompressedSize: " << ::android::internal::ToString(decompressedSize);
    os << "}";
    return os.str();
  }
};  // class CompressedApexInfo

}  // namespace apex

}  // namespace android
