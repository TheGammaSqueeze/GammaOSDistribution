#pragma once

#include <android/binder_to_string.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <tuple>
#include <utils/String16.h>
#include <vector>

namespace android {

namespace hardware {

namespace gnss {

class CorrelationVector : public ::android::Parcelable {
public:
  inline bool operator!=(const CorrelationVector& rhs) const {
    return std::tie(frequencyOffsetMps, samplingWidthM, samplingStartM, magnitude) != std::tie(rhs.frequencyOffsetMps, rhs.samplingWidthM, rhs.samplingStartM, rhs.magnitude);
  }
  inline bool operator<(const CorrelationVector& rhs) const {
    return std::tie(frequencyOffsetMps, samplingWidthM, samplingStartM, magnitude) < std::tie(rhs.frequencyOffsetMps, rhs.samplingWidthM, rhs.samplingStartM, rhs.magnitude);
  }
  inline bool operator<=(const CorrelationVector& rhs) const {
    return std::tie(frequencyOffsetMps, samplingWidthM, samplingStartM, magnitude) <= std::tie(rhs.frequencyOffsetMps, rhs.samplingWidthM, rhs.samplingStartM, rhs.magnitude);
  }
  inline bool operator==(const CorrelationVector& rhs) const {
    return std::tie(frequencyOffsetMps, samplingWidthM, samplingStartM, magnitude) == std::tie(rhs.frequencyOffsetMps, rhs.samplingWidthM, rhs.samplingStartM, rhs.magnitude);
  }
  inline bool operator>(const CorrelationVector& rhs) const {
    return std::tie(frequencyOffsetMps, samplingWidthM, samplingStartM, magnitude) > std::tie(rhs.frequencyOffsetMps, rhs.samplingWidthM, rhs.samplingStartM, rhs.magnitude);
  }
  inline bool operator>=(const CorrelationVector& rhs) const {
    return std::tie(frequencyOffsetMps, samplingWidthM, samplingStartM, magnitude) >= std::tie(rhs.frequencyOffsetMps, rhs.samplingWidthM, rhs.samplingStartM, rhs.magnitude);
  }

  double frequencyOffsetMps = double(0.000000);
  double samplingWidthM = double(0.000000);
  double samplingStartM = double(0.000000);
  ::std::vector<int32_t> magnitude;
  ::android::Parcelable::Stability getStability() const override { return ::android::Parcelable::Stability::STABILITY_VINTF; }
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.hardware.gnss.CorrelationVector");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "CorrelationVector{";
    os << "frequencyOffsetMps: " << ::android::internal::ToString(frequencyOffsetMps);
    os << ", samplingWidthM: " << ::android::internal::ToString(samplingWidthM);
    os << ", samplingStartM: " << ::android::internal::ToString(samplingStartM);
    os << ", magnitude: " << ::android::internal::ToString(magnitude);
    os << "}";
    return os.str();
  }
};  // class CorrelationVector

}  // namespace gnss

}  // namespace hardware

}  // namespace android
