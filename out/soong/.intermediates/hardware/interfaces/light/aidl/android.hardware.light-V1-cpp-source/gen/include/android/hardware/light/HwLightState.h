#pragma once

#include <android/binder_to_string.h>
#include <android/hardware/light/BrightnessMode.h>
#include <android/hardware/light/FlashMode.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <tuple>
#include <utils/String16.h>

namespace android {

namespace hardware {

namespace light {

class HwLightState : public ::android::Parcelable {
public:
  inline bool operator!=(const HwLightState& rhs) const {
    return std::tie(color, flashMode, flashOnMs, flashOffMs, brightnessMode) != std::tie(rhs.color, rhs.flashMode, rhs.flashOnMs, rhs.flashOffMs, rhs.brightnessMode);
  }
  inline bool operator<(const HwLightState& rhs) const {
    return std::tie(color, flashMode, flashOnMs, flashOffMs, brightnessMode) < std::tie(rhs.color, rhs.flashMode, rhs.flashOnMs, rhs.flashOffMs, rhs.brightnessMode);
  }
  inline bool operator<=(const HwLightState& rhs) const {
    return std::tie(color, flashMode, flashOnMs, flashOffMs, brightnessMode) <= std::tie(rhs.color, rhs.flashMode, rhs.flashOnMs, rhs.flashOffMs, rhs.brightnessMode);
  }
  inline bool operator==(const HwLightState& rhs) const {
    return std::tie(color, flashMode, flashOnMs, flashOffMs, brightnessMode) == std::tie(rhs.color, rhs.flashMode, rhs.flashOnMs, rhs.flashOffMs, rhs.brightnessMode);
  }
  inline bool operator>(const HwLightState& rhs) const {
    return std::tie(color, flashMode, flashOnMs, flashOffMs, brightnessMode) > std::tie(rhs.color, rhs.flashMode, rhs.flashOnMs, rhs.flashOffMs, rhs.brightnessMode);
  }
  inline bool operator>=(const HwLightState& rhs) const {
    return std::tie(color, flashMode, flashOnMs, flashOffMs, brightnessMode) >= std::tie(rhs.color, rhs.flashMode, rhs.flashOnMs, rhs.flashOffMs, rhs.brightnessMode);
  }

  int32_t color = int32_t(0);
  ::android::hardware::light::FlashMode flashMode = ::android::hardware::light::FlashMode(0);
  int32_t flashOnMs = int32_t(0);
  int32_t flashOffMs = int32_t(0);
  ::android::hardware::light::BrightnessMode brightnessMode = ::android::hardware::light::BrightnessMode(0);
  ::android::Parcelable::Stability getStability() const override { return ::android::Parcelable::Stability::STABILITY_VINTF; }
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.hardware.light.HwLightState");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "HwLightState{";
    os << "color: " << ::android::internal::ToString(color);
    os << ", flashMode: " << ::android::internal::ToString(flashMode);
    os << ", flashOnMs: " << ::android::internal::ToString(flashOnMs);
    os << ", flashOffMs: " << ::android::internal::ToString(flashOffMs);
    os << ", brightnessMode: " << ::android::internal::ToString(brightnessMode);
    os << "}";
    return os.str();
  }
};  // class HwLightState

}  // namespace light

}  // namespace hardware

}  // namespace android
