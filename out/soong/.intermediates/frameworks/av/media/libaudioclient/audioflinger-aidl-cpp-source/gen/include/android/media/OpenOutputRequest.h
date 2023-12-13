#pragma once

#include <android/binder_to_string.h>
#include <android/media/AudioConfig.h>
#include <android/media/AudioConfigBase.h>
#include <android/media/AudioPort.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <tuple>
#include <utils/String16.h>

namespace android {

namespace media {

class OpenOutputRequest : public ::android::Parcelable {
public:
  inline bool operator!=(const OpenOutputRequest& rhs) const {
    return std::tie(module, halConfig, mixerConfig, device, flags) != std::tie(rhs.module, rhs.halConfig, rhs.mixerConfig, rhs.device, rhs.flags);
  }
  inline bool operator<(const OpenOutputRequest& rhs) const {
    return std::tie(module, halConfig, mixerConfig, device, flags) < std::tie(rhs.module, rhs.halConfig, rhs.mixerConfig, rhs.device, rhs.flags);
  }
  inline bool operator<=(const OpenOutputRequest& rhs) const {
    return std::tie(module, halConfig, mixerConfig, device, flags) <= std::tie(rhs.module, rhs.halConfig, rhs.mixerConfig, rhs.device, rhs.flags);
  }
  inline bool operator==(const OpenOutputRequest& rhs) const {
    return std::tie(module, halConfig, mixerConfig, device, flags) == std::tie(rhs.module, rhs.halConfig, rhs.mixerConfig, rhs.device, rhs.flags);
  }
  inline bool operator>(const OpenOutputRequest& rhs) const {
    return std::tie(module, halConfig, mixerConfig, device, flags) > std::tie(rhs.module, rhs.halConfig, rhs.mixerConfig, rhs.device, rhs.flags);
  }
  inline bool operator>=(const OpenOutputRequest& rhs) const {
    return std::tie(module, halConfig, mixerConfig, device, flags) >= std::tie(rhs.module, rhs.halConfig, rhs.mixerConfig, rhs.device, rhs.flags);
  }

  int32_t module = int32_t(0);
  ::android::media::AudioConfig halConfig;
  ::android::media::AudioConfigBase mixerConfig;
  ::android::media::AudioPort device;
  int32_t flags = int32_t(0);
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.media.OpenOutputRequest");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "OpenOutputRequest{";
    os << "module: " << ::android::internal::ToString(module);
    os << ", halConfig: " << ::android::internal::ToString(halConfig);
    os << ", mixerConfig: " << ::android::internal::ToString(mixerConfig);
    os << ", device: " << ::android::internal::ToString(device);
    os << ", flags: " << ::android::internal::ToString(flags);
    os << "}";
    return os.str();
  }
};  // class OpenOutputRequest

}  // namespace media

}  // namespace android
