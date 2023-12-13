#pragma once

#include <android/binder_to_string.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <tuple>
#include <utils/String16.h>

namespace android {

namespace hardware {

namespace vibrator {

class ActivePwle : public ::android::Parcelable {
public:
  inline bool operator!=(const ActivePwle& rhs) const {
    return std::tie(startAmplitude, startFrequency, endAmplitude, endFrequency, duration) != std::tie(rhs.startAmplitude, rhs.startFrequency, rhs.endAmplitude, rhs.endFrequency, rhs.duration);
  }
  inline bool operator<(const ActivePwle& rhs) const {
    return std::tie(startAmplitude, startFrequency, endAmplitude, endFrequency, duration) < std::tie(rhs.startAmplitude, rhs.startFrequency, rhs.endAmplitude, rhs.endFrequency, rhs.duration);
  }
  inline bool operator<=(const ActivePwle& rhs) const {
    return std::tie(startAmplitude, startFrequency, endAmplitude, endFrequency, duration) <= std::tie(rhs.startAmplitude, rhs.startFrequency, rhs.endAmplitude, rhs.endFrequency, rhs.duration);
  }
  inline bool operator==(const ActivePwle& rhs) const {
    return std::tie(startAmplitude, startFrequency, endAmplitude, endFrequency, duration) == std::tie(rhs.startAmplitude, rhs.startFrequency, rhs.endAmplitude, rhs.endFrequency, rhs.duration);
  }
  inline bool operator>(const ActivePwle& rhs) const {
    return std::tie(startAmplitude, startFrequency, endAmplitude, endFrequency, duration) > std::tie(rhs.startAmplitude, rhs.startFrequency, rhs.endAmplitude, rhs.endFrequency, rhs.duration);
  }
  inline bool operator>=(const ActivePwle& rhs) const {
    return std::tie(startAmplitude, startFrequency, endAmplitude, endFrequency, duration) >= std::tie(rhs.startAmplitude, rhs.startFrequency, rhs.endAmplitude, rhs.endFrequency, rhs.duration);
  }

  float startAmplitude = float(0.000000f);
  float startFrequency = float(0.000000f);
  float endAmplitude = float(0.000000f);
  float endFrequency = float(0.000000f);
  int32_t duration = int32_t(0);
  ::android::Parcelable::Stability getStability() const override { return ::android::Parcelable::Stability::STABILITY_VINTF; }
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.hardware.vibrator.ActivePwle");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "ActivePwle{";
    os << "startAmplitude: " << ::android::internal::ToString(startAmplitude);
    os << ", startFrequency: " << ::android::internal::ToString(startFrequency);
    os << ", endAmplitude: " << ::android::internal::ToString(endAmplitude);
    os << ", endFrequency: " << ::android::internal::ToString(endFrequency);
    os << ", duration: " << ::android::internal::ToString(duration);
    os << "}";
    return os.str();
  }
};  // class ActivePwle

}  // namespace vibrator

}  // namespace hardware

}  // namespace android
