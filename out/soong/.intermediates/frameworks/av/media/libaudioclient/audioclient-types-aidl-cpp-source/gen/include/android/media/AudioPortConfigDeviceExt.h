#pragma once

#include <android/binder_to_string.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <string>
#include <tuple>
#include <utils/String16.h>

namespace android {

namespace media {

class AudioPortConfigDeviceExt : public ::android::Parcelable {
public:
  inline bool operator!=(const AudioPortConfigDeviceExt& rhs) const {
    return std::tie(hwModule, type, address) != std::tie(rhs.hwModule, rhs.type, rhs.address);
  }
  inline bool operator<(const AudioPortConfigDeviceExt& rhs) const {
    return std::tie(hwModule, type, address) < std::tie(rhs.hwModule, rhs.type, rhs.address);
  }
  inline bool operator<=(const AudioPortConfigDeviceExt& rhs) const {
    return std::tie(hwModule, type, address) <= std::tie(rhs.hwModule, rhs.type, rhs.address);
  }
  inline bool operator==(const AudioPortConfigDeviceExt& rhs) const {
    return std::tie(hwModule, type, address) == std::tie(rhs.hwModule, rhs.type, rhs.address);
  }
  inline bool operator>(const AudioPortConfigDeviceExt& rhs) const {
    return std::tie(hwModule, type, address) > std::tie(rhs.hwModule, rhs.type, rhs.address);
  }
  inline bool operator>=(const AudioPortConfigDeviceExt& rhs) const {
    return std::tie(hwModule, type, address) >= std::tie(rhs.hwModule, rhs.type, rhs.address);
  }

  int32_t hwModule = int32_t(0);
  int32_t type = int32_t(0);
  ::std::string address;
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.media.AudioPortConfigDeviceExt");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "AudioPortConfigDeviceExt{";
    os << "hwModule: " << ::android::internal::ToString(hwModule);
    os << ", type: " << ::android::internal::ToString(type);
    os << ", address: " << ::android::internal::ToString(address);
    os << "}";
    return os.str();
  }
};  // class AudioPortConfigDeviceExt

}  // namespace media

}  // namespace android
