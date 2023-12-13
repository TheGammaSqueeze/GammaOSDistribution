#pragma once

#include <android/binder_to_string.h>
#include <android/hardware/light/LightType.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <tuple>
#include <utils/String16.h>

namespace android {

namespace hardware {

namespace light {

class HwLight : public ::android::Parcelable {
public:
  inline bool operator!=(const HwLight& rhs) const {
    return std::tie(id, ordinal, type) != std::tie(rhs.id, rhs.ordinal, rhs.type);
  }
  inline bool operator<(const HwLight& rhs) const {
    return std::tie(id, ordinal, type) < std::tie(rhs.id, rhs.ordinal, rhs.type);
  }
  inline bool operator<=(const HwLight& rhs) const {
    return std::tie(id, ordinal, type) <= std::tie(rhs.id, rhs.ordinal, rhs.type);
  }
  inline bool operator==(const HwLight& rhs) const {
    return std::tie(id, ordinal, type) == std::tie(rhs.id, rhs.ordinal, rhs.type);
  }
  inline bool operator>(const HwLight& rhs) const {
    return std::tie(id, ordinal, type) > std::tie(rhs.id, rhs.ordinal, rhs.type);
  }
  inline bool operator>=(const HwLight& rhs) const {
    return std::tie(id, ordinal, type) >= std::tie(rhs.id, rhs.ordinal, rhs.type);
  }

  int32_t id = int32_t(0);
  int32_t ordinal = int32_t(0);
  ::android::hardware::light::LightType type = ::android::hardware::light::LightType(0);
  ::android::Parcelable::Stability getStability() const override { return ::android::Parcelable::Stability::STABILITY_VINTF; }
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.hardware.light.HwLight");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "HwLight{";
    os << "id: " << ::android::internal::ToString(id);
    os << ", ordinal: " << ::android::internal::ToString(ordinal);
    os << ", type: " << ::android::internal::ToString(type);
    os << "}";
    return os.str();
  }
};  // class HwLight

}  // namespace light

}  // namespace hardware

}  // namespace android
