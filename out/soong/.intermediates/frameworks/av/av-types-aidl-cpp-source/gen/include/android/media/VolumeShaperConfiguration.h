#pragma once

#include <android/binder_to_string.h>
#include <android/media/InterpolatorConfig.h>
#include <android/media/VolumeShaperConfigurationType.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <optional>
#include <tuple>
#include <utils/String16.h>

namespace android {

namespace media {

class VolumeShaperConfiguration : public ::android::Parcelable {
public:
  inline bool operator!=(const VolumeShaperConfiguration& rhs) const {
    return std::tie(type, id, optionFlags, durationMs, interpolatorConfig) != std::tie(rhs.type, rhs.id, rhs.optionFlags, rhs.durationMs, rhs.interpolatorConfig);
  }
  inline bool operator<(const VolumeShaperConfiguration& rhs) const {
    return std::tie(type, id, optionFlags, durationMs, interpolatorConfig) < std::tie(rhs.type, rhs.id, rhs.optionFlags, rhs.durationMs, rhs.interpolatorConfig);
  }
  inline bool operator<=(const VolumeShaperConfiguration& rhs) const {
    return std::tie(type, id, optionFlags, durationMs, interpolatorConfig) <= std::tie(rhs.type, rhs.id, rhs.optionFlags, rhs.durationMs, rhs.interpolatorConfig);
  }
  inline bool operator==(const VolumeShaperConfiguration& rhs) const {
    return std::tie(type, id, optionFlags, durationMs, interpolatorConfig) == std::tie(rhs.type, rhs.id, rhs.optionFlags, rhs.durationMs, rhs.interpolatorConfig);
  }
  inline bool operator>(const VolumeShaperConfiguration& rhs) const {
    return std::tie(type, id, optionFlags, durationMs, interpolatorConfig) > std::tie(rhs.type, rhs.id, rhs.optionFlags, rhs.durationMs, rhs.interpolatorConfig);
  }
  inline bool operator>=(const VolumeShaperConfiguration& rhs) const {
    return std::tie(type, id, optionFlags, durationMs, interpolatorConfig) >= std::tie(rhs.type, rhs.id, rhs.optionFlags, rhs.durationMs, rhs.interpolatorConfig);
  }

  ::android::media::VolumeShaperConfigurationType type = ::android::media::VolumeShaperConfigurationType(::android::media::VolumeShaperConfigurationType::ID);
  int32_t id = int32_t(0);
  int32_t optionFlags = int32_t(0);
  double durationMs = double(0.000000);
  ::std::optional<::android::media::InterpolatorConfig> interpolatorConfig;
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.media.VolumeShaperConfiguration");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "VolumeShaperConfiguration{";
    os << "type: " << ::android::internal::ToString(type);
    os << ", id: " << ::android::internal::ToString(id);
    os << ", optionFlags: " << ::android::internal::ToString(optionFlags);
    os << ", durationMs: " << ::android::internal::ToString(durationMs);
    os << ", interpolatorConfig: " << ::android::internal::ToString(interpolatorConfig);
    os << "}";
    return os.str();
  }
};  // class VolumeShaperConfiguration

}  // namespace media

}  // namespace android
