#pragma once

#include <android/binder_to_string.h>
#include <android/hardware/vibrator/Braking.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <tuple>
#include <utils/String16.h>

namespace android {

namespace hardware {

namespace vibrator {

class BrakingPwle : public ::android::Parcelable {
public:
  inline bool operator!=(const BrakingPwle& rhs) const {
    return std::tie(braking, duration) != std::tie(rhs.braking, rhs.duration);
  }
  inline bool operator<(const BrakingPwle& rhs) const {
    return std::tie(braking, duration) < std::tie(rhs.braking, rhs.duration);
  }
  inline bool operator<=(const BrakingPwle& rhs) const {
    return std::tie(braking, duration) <= std::tie(rhs.braking, rhs.duration);
  }
  inline bool operator==(const BrakingPwle& rhs) const {
    return std::tie(braking, duration) == std::tie(rhs.braking, rhs.duration);
  }
  inline bool operator>(const BrakingPwle& rhs) const {
    return std::tie(braking, duration) > std::tie(rhs.braking, rhs.duration);
  }
  inline bool operator>=(const BrakingPwle& rhs) const {
    return std::tie(braking, duration) >= std::tie(rhs.braking, rhs.duration);
  }

  ::android::hardware::vibrator::Braking braking = ::android::hardware::vibrator::Braking(0);
  int32_t duration = int32_t(0);
  ::android::Parcelable::Stability getStability() const override { return ::android::Parcelable::Stability::STABILITY_VINTF; }
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.hardware.vibrator.BrakingPwle");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "BrakingPwle{";
    os << "braking: " << ::android::internal::ToString(braking);
    os << ", duration: " << ::android::internal::ToString(duration);
    os << "}";
    return os.str();
  }
};  // class BrakingPwle

}  // namespace vibrator

}  // namespace hardware

}  // namespace android
