#pragma once

#include <android/binder_to_string.h>
#include <android/media/AudioConfig.h>
#include <android/media/AudioDevice.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <tuple>
#include <utils/String16.h>

namespace android {

namespace media {

class OpenInputResponse : public ::android::Parcelable {
public:
  inline bool operator!=(const OpenInputResponse& rhs) const {
    return std::tie(input, config, device) != std::tie(rhs.input, rhs.config, rhs.device);
  }
  inline bool operator<(const OpenInputResponse& rhs) const {
    return std::tie(input, config, device) < std::tie(rhs.input, rhs.config, rhs.device);
  }
  inline bool operator<=(const OpenInputResponse& rhs) const {
    return std::tie(input, config, device) <= std::tie(rhs.input, rhs.config, rhs.device);
  }
  inline bool operator==(const OpenInputResponse& rhs) const {
    return std::tie(input, config, device) == std::tie(rhs.input, rhs.config, rhs.device);
  }
  inline bool operator>(const OpenInputResponse& rhs) const {
    return std::tie(input, config, device) > std::tie(rhs.input, rhs.config, rhs.device);
  }
  inline bool operator>=(const OpenInputResponse& rhs) const {
    return std::tie(input, config, device) >= std::tie(rhs.input, rhs.config, rhs.device);
  }

  int32_t input = int32_t(0);
  ::android::media::AudioConfig config;
  ::android::media::AudioDevice device;
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.media.OpenInputResponse");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "OpenInputResponse{";
    os << "input: " << ::android::internal::ToString(input);
    os << ", config: " << ::android::internal::ToString(config);
    os << ", device: " << ::android::internal::ToString(device);
    os << "}";
    return os.str();
  }
};  // class OpenInputResponse

}  // namespace media

}  // namespace android
