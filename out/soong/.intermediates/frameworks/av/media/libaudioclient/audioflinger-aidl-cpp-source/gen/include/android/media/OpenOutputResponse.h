#pragma once

#include <android/binder_to_string.h>
#include <android/media/AudioConfig.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <tuple>
#include <utils/String16.h>

namespace android {

namespace media {

class OpenOutputResponse : public ::android::Parcelable {
public:
  inline bool operator!=(const OpenOutputResponse& rhs) const {
    return std::tie(output, config, latencyMs, flags) != std::tie(rhs.output, rhs.config, rhs.latencyMs, rhs.flags);
  }
  inline bool operator<(const OpenOutputResponse& rhs) const {
    return std::tie(output, config, latencyMs, flags) < std::tie(rhs.output, rhs.config, rhs.latencyMs, rhs.flags);
  }
  inline bool operator<=(const OpenOutputResponse& rhs) const {
    return std::tie(output, config, latencyMs, flags) <= std::tie(rhs.output, rhs.config, rhs.latencyMs, rhs.flags);
  }
  inline bool operator==(const OpenOutputResponse& rhs) const {
    return std::tie(output, config, latencyMs, flags) == std::tie(rhs.output, rhs.config, rhs.latencyMs, rhs.flags);
  }
  inline bool operator>(const OpenOutputResponse& rhs) const {
    return std::tie(output, config, latencyMs, flags) > std::tie(rhs.output, rhs.config, rhs.latencyMs, rhs.flags);
  }
  inline bool operator>=(const OpenOutputResponse& rhs) const {
    return std::tie(output, config, latencyMs, flags) >= std::tie(rhs.output, rhs.config, rhs.latencyMs, rhs.flags);
  }

  int32_t output = int32_t(0);
  ::android::media::AudioConfig config;
  int32_t latencyMs = int32_t(0);
  int32_t flags = int32_t(0);
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.media.OpenOutputResponse");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "OpenOutputResponse{";
    os << "output: " << ::android::internal::ToString(output);
    os << ", config: " << ::android::internal::ToString(config);
    os << ", latencyMs: " << ::android::internal::ToString(latencyMs);
    os << ", flags: " << ::android::internal::ToString(flags);
    os << "}";
    return os.str();
  }
};  // class OpenOutputResponse

}  // namespace media

}  // namespace android
