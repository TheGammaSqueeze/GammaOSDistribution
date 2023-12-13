#pragma once

#include <android/binder_to_string.h>
#include <android/media/AudioConfig.h>
#include <android/media/AudioDevice.h>
#include <android/media/AudioSourceType.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <tuple>
#include <utils/String16.h>

namespace android {

namespace media {

class OpenInputRequest : public ::android::Parcelable {
public:
  inline bool operator!=(const OpenInputRequest& rhs) const {
    return std::tie(module, input, config, device, source, flags) != std::tie(rhs.module, rhs.input, rhs.config, rhs.device, rhs.source, rhs.flags);
  }
  inline bool operator<(const OpenInputRequest& rhs) const {
    return std::tie(module, input, config, device, source, flags) < std::tie(rhs.module, rhs.input, rhs.config, rhs.device, rhs.source, rhs.flags);
  }
  inline bool operator<=(const OpenInputRequest& rhs) const {
    return std::tie(module, input, config, device, source, flags) <= std::tie(rhs.module, rhs.input, rhs.config, rhs.device, rhs.source, rhs.flags);
  }
  inline bool operator==(const OpenInputRequest& rhs) const {
    return std::tie(module, input, config, device, source, flags) == std::tie(rhs.module, rhs.input, rhs.config, rhs.device, rhs.source, rhs.flags);
  }
  inline bool operator>(const OpenInputRequest& rhs) const {
    return std::tie(module, input, config, device, source, flags) > std::tie(rhs.module, rhs.input, rhs.config, rhs.device, rhs.source, rhs.flags);
  }
  inline bool operator>=(const OpenInputRequest& rhs) const {
    return std::tie(module, input, config, device, source, flags) >= std::tie(rhs.module, rhs.input, rhs.config, rhs.device, rhs.source, rhs.flags);
  }

  int32_t module = int32_t(0);
  int32_t input = int32_t(0);
  ::android::media::AudioConfig config;
  ::android::media::AudioDevice device;
  ::android::media::AudioSourceType source = ::android::media::AudioSourceType(0);
  int32_t flags = int32_t(0);
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.media.OpenInputRequest");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "OpenInputRequest{";
    os << "module: " << ::android::internal::ToString(module);
    os << ", input: " << ::android::internal::ToString(input);
    os << ", config: " << ::android::internal::ToString(config);
    os << ", device: " << ::android::internal::ToString(device);
    os << ", source: " << ::android::internal::ToString(source);
    os << ", flags: " << ::android::internal::ToString(flags);
    os << "}";
    return os.str();
  }
};  // class OpenInputRequest

}  // namespace media

}  // namespace android
