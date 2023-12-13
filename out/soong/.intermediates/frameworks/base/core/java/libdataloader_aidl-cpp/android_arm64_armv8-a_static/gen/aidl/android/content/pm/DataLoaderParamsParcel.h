#pragma once

#include <android/binder_to_string.h>
#include <android/content/pm/DataLoaderType.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <string>
#include <tuple>
#include <utils/String16.h>

namespace android {

namespace content {

namespace pm {

class DataLoaderParamsParcel : public ::android::Parcelable {
public:
  inline bool operator!=(const DataLoaderParamsParcel& rhs) const {
    return std::tie(type, packageName, className, arguments) != std::tie(rhs.type, rhs.packageName, rhs.className, rhs.arguments);
  }
  inline bool operator<(const DataLoaderParamsParcel& rhs) const {
    return std::tie(type, packageName, className, arguments) < std::tie(rhs.type, rhs.packageName, rhs.className, rhs.arguments);
  }
  inline bool operator<=(const DataLoaderParamsParcel& rhs) const {
    return std::tie(type, packageName, className, arguments) <= std::tie(rhs.type, rhs.packageName, rhs.className, rhs.arguments);
  }
  inline bool operator==(const DataLoaderParamsParcel& rhs) const {
    return std::tie(type, packageName, className, arguments) == std::tie(rhs.type, rhs.packageName, rhs.className, rhs.arguments);
  }
  inline bool operator>(const DataLoaderParamsParcel& rhs) const {
    return std::tie(type, packageName, className, arguments) > std::tie(rhs.type, rhs.packageName, rhs.className, rhs.arguments);
  }
  inline bool operator>=(const DataLoaderParamsParcel& rhs) const {
    return std::tie(type, packageName, className, arguments) >= std::tie(rhs.type, rhs.packageName, rhs.className, rhs.arguments);
  }

  ::android::content::pm::DataLoaderType type = ::android::content::pm::DataLoaderType(::android::content::pm::DataLoaderType::NONE);
  ::std::string packageName;
  ::std::string className;
  ::std::string arguments;
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.content.pm.DataLoaderParamsParcel");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "DataLoaderParamsParcel{";
    os << "type: " << ::android::internal::ToString(type);
    os << ", packageName: " << ::android::internal::ToString(packageName);
    os << ", className: " << ::android::internal::ToString(className);
    os << ", arguments: " << ::android::internal::ToString(arguments);
    os << "}";
    return os.str();
  }
};  // class DataLoaderParamsParcel

}  // namespace pm

}  // namespace content

}  // namespace android
