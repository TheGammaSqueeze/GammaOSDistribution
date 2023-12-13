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

class AudioDevice : public ::android::Parcelable {
public:
  inline bool operator!=(const AudioDevice& rhs) const {
    return std::tie(type, address) != std::tie(rhs.type, rhs.address);
  }
  inline bool operator<(const AudioDevice& rhs) const {
    return std::tie(type, address) < std::tie(rhs.type, rhs.address);
  }
  inline bool operator<=(const AudioDevice& rhs) const {
    return std::tie(type, address) <= std::tie(rhs.type, rhs.address);
  }
  inline bool operator==(const AudioDevice& rhs) const {
    return std::tie(type, address) == std::tie(rhs.type, rhs.address);
  }
  inline bool operator>(const AudioDevice& rhs) const {
    return std::tie(type, address) > std::tie(rhs.type, rhs.address);
  }
  inline bool operator>=(const AudioDevice& rhs) const {
    return std::tie(type, address) >= std::tie(rhs.type, rhs.address);
  }

  int32_t type = int32_t(0);
  ::std::string address;
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.media.AudioDevice");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "AudioDevice{";
    os << "type: " << ::android::internal::ToString(type);
    os << ", address: " << ::android::internal::ToString(address);
    os << "}";
    return os.str();
  }
};  // class AudioDevice

}  // namespace media

}  // namespace android
