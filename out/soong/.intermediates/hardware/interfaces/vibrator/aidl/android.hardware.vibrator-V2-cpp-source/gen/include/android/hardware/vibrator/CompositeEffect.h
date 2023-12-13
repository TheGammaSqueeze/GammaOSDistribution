#pragma once

#include <android/binder_to_string.h>
#include <android/hardware/vibrator/CompositePrimitive.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <tuple>
#include <utils/String16.h>

namespace android {

namespace hardware {

namespace vibrator {

class CompositeEffect : public ::android::Parcelable {
public:
  inline bool operator!=(const CompositeEffect& rhs) const {
    return std::tie(delayMs, primitive, scale) != std::tie(rhs.delayMs, rhs.primitive, rhs.scale);
  }
  inline bool operator<(const CompositeEffect& rhs) const {
    return std::tie(delayMs, primitive, scale) < std::tie(rhs.delayMs, rhs.primitive, rhs.scale);
  }
  inline bool operator<=(const CompositeEffect& rhs) const {
    return std::tie(delayMs, primitive, scale) <= std::tie(rhs.delayMs, rhs.primitive, rhs.scale);
  }
  inline bool operator==(const CompositeEffect& rhs) const {
    return std::tie(delayMs, primitive, scale) == std::tie(rhs.delayMs, rhs.primitive, rhs.scale);
  }
  inline bool operator>(const CompositeEffect& rhs) const {
    return std::tie(delayMs, primitive, scale) > std::tie(rhs.delayMs, rhs.primitive, rhs.scale);
  }
  inline bool operator>=(const CompositeEffect& rhs) const {
    return std::tie(delayMs, primitive, scale) >= std::tie(rhs.delayMs, rhs.primitive, rhs.scale);
  }

  int32_t delayMs = int32_t(0);
  ::android::hardware::vibrator::CompositePrimitive primitive = ::android::hardware::vibrator::CompositePrimitive(::android::hardware::vibrator::CompositePrimitive::NOOP);
  float scale = float(0.000000f);
  ::android::Parcelable::Stability getStability() const override { return ::android::Parcelable::Stability::STABILITY_VINTF; }
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.hardware.vibrator.CompositeEffect");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "CompositeEffect{";
    os << "delayMs: " << ::android::internal::ToString(delayMs);
    os << ", primitive: " << ::android::internal::ToString(primitive);
    os << ", scale: " << ::android::internal::ToString(scale);
    os << "}";
    return os.str();
  }
};  // class CompositeEffect

}  // namespace vibrator

}  // namespace hardware

}  // namespace android
