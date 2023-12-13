#pragma once

#include <android/binder_to_string.h>
#include <android/media/InterpolatorType.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <tuple>
#include <utils/String16.h>
#include <vector>

namespace android {

namespace media {

class InterpolatorConfig : public ::android::Parcelable {
public:
  inline bool operator!=(const InterpolatorConfig& rhs) const {
    return std::tie(type, firstSlope, lastSlope, xy) != std::tie(rhs.type, rhs.firstSlope, rhs.lastSlope, rhs.xy);
  }
  inline bool operator<(const InterpolatorConfig& rhs) const {
    return std::tie(type, firstSlope, lastSlope, xy) < std::tie(rhs.type, rhs.firstSlope, rhs.lastSlope, rhs.xy);
  }
  inline bool operator<=(const InterpolatorConfig& rhs) const {
    return std::tie(type, firstSlope, lastSlope, xy) <= std::tie(rhs.type, rhs.firstSlope, rhs.lastSlope, rhs.xy);
  }
  inline bool operator==(const InterpolatorConfig& rhs) const {
    return std::tie(type, firstSlope, lastSlope, xy) == std::tie(rhs.type, rhs.firstSlope, rhs.lastSlope, rhs.xy);
  }
  inline bool operator>(const InterpolatorConfig& rhs) const {
    return std::tie(type, firstSlope, lastSlope, xy) > std::tie(rhs.type, rhs.firstSlope, rhs.lastSlope, rhs.xy);
  }
  inline bool operator>=(const InterpolatorConfig& rhs) const {
    return std::tie(type, firstSlope, lastSlope, xy) >= std::tie(rhs.type, rhs.firstSlope, rhs.lastSlope, rhs.xy);
  }

  ::android::media::InterpolatorType type = ::android::media::InterpolatorType(::android::media::InterpolatorType::CUBIC);
  float firstSlope = float(0.000000f);
  float lastSlope = float(0.000000f);
  ::std::vector<float> xy;
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.media.InterpolatorConfig");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "InterpolatorConfig{";
    os << "type: " << ::android::internal::ToString(type);
    os << ", firstSlope: " << ::android::internal::ToString(firstSlope);
    os << ", lastSlope: " << ::android::internal::ToString(lastSlope);
    os << ", xy: " << ::android::internal::ToString(xy);
    os << "}";
    return os.str();
  }
};  // class InterpolatorConfig

}  // namespace media

}  // namespace android
