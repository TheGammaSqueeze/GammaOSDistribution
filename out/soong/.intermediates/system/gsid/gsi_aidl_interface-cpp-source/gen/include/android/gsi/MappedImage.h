#pragma once

#include <android/binder_to_string.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <string>
#include <tuple>
#include <utils/String16.h>

namespace android {

namespace gsi {

class MappedImage : public ::android::Parcelable {
public:
  inline bool operator!=(const MappedImage& rhs) const {
    return std::tie(path) != std::tie(rhs.path);
  }
  inline bool operator<(const MappedImage& rhs) const {
    return std::tie(path) < std::tie(rhs.path);
  }
  inline bool operator<=(const MappedImage& rhs) const {
    return std::tie(path) <= std::tie(rhs.path);
  }
  inline bool operator==(const MappedImage& rhs) const {
    return std::tie(path) == std::tie(rhs.path);
  }
  inline bool operator>(const MappedImage& rhs) const {
    return std::tie(path) > std::tie(rhs.path);
  }
  inline bool operator>=(const MappedImage& rhs) const {
    return std::tie(path) >= std::tie(rhs.path);
  }

  ::std::string path;
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.gsi.MappedImage");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "MappedImage{";
    os << "path: " << ::android::internal::ToString(path);
    os << "}";
    return os.str();
  }
};  // class MappedImage

}  // namespace gsi

}  // namespace android
