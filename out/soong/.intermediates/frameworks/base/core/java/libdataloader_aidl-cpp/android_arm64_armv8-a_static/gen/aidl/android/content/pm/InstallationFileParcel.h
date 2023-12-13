#pragma once

#include <android/binder_to_string.h>
#include <android/content/pm/InstallationFileLocation.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <tuple>
#include <utils/String16.h>
#include <vector>

namespace android {

namespace content {

namespace pm {

class InstallationFileParcel : public ::android::Parcelable {
public:
  inline bool operator!=(const InstallationFileParcel& rhs) const {
    return std::tie(name, location, size, metadata, signature) != std::tie(rhs.name, rhs.location, rhs.size, rhs.metadata, rhs.signature);
  }
  inline bool operator<(const InstallationFileParcel& rhs) const {
    return std::tie(name, location, size, metadata, signature) < std::tie(rhs.name, rhs.location, rhs.size, rhs.metadata, rhs.signature);
  }
  inline bool operator<=(const InstallationFileParcel& rhs) const {
    return std::tie(name, location, size, metadata, signature) <= std::tie(rhs.name, rhs.location, rhs.size, rhs.metadata, rhs.signature);
  }
  inline bool operator==(const InstallationFileParcel& rhs) const {
    return std::tie(name, location, size, metadata, signature) == std::tie(rhs.name, rhs.location, rhs.size, rhs.metadata, rhs.signature);
  }
  inline bool operator>(const InstallationFileParcel& rhs) const {
    return std::tie(name, location, size, metadata, signature) > std::tie(rhs.name, rhs.location, rhs.size, rhs.metadata, rhs.signature);
  }
  inline bool operator>=(const InstallationFileParcel& rhs) const {
    return std::tie(name, location, size, metadata, signature) >= std::tie(rhs.name, rhs.location, rhs.size, rhs.metadata, rhs.signature);
  }

  ::android::String16 name;
  ::android::content::pm::InstallationFileLocation location = ::android::content::pm::InstallationFileLocation(::android::content::pm::InstallationFileLocation::UNKNOWN);
  int64_t size = int64_t(0L);
  ::std::vector<uint8_t> metadata;
  ::std::vector<uint8_t> signature;
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.content.pm.InstallationFileParcel");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "InstallationFileParcel{";
    os << "name: " << ::android::internal::ToString(name);
    os << ", location: " << ::android::internal::ToString(location);
    os << ", size: " << ::android::internal::ToString(size);
    os << ", metadata: " << ::android::internal::ToString(metadata);
    os << ", signature: " << ::android::internal::ToString(signature);
    os << "}";
    return os.str();
  }
};  // class InstallationFileParcel

}  // namespace pm

}  // namespace content

}  // namespace android
