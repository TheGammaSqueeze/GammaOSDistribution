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

namespace security {

namespace keymint {

class DeviceInfo : public ::android::Parcelable {
public:
  inline bool operator!=(const DeviceInfo& rhs) const {
    return std::tie(deviceInfo) != std::tie(rhs.deviceInfo);
  }
  inline bool operator<(const DeviceInfo& rhs) const {
    return std::tie(deviceInfo) < std::tie(rhs.deviceInfo);
  }
  inline bool operator<=(const DeviceInfo& rhs) const {
    return std::tie(deviceInfo) <= std::tie(rhs.deviceInfo);
  }
  inline bool operator==(const DeviceInfo& rhs) const {
    return std::tie(deviceInfo) == std::tie(rhs.deviceInfo);
  }
  inline bool operator>(const DeviceInfo& rhs) const {
    return std::tie(deviceInfo) > std::tie(rhs.deviceInfo);
  }
  inline bool operator>=(const DeviceInfo& rhs) const {
    return std::tie(deviceInfo) >= std::tie(rhs.deviceInfo);
  }

  ::std::vector<uint8_t> deviceInfo;
  ::android::Parcelable::Stability getStability() const override { return ::android::Parcelable::Stability::STABILITY_VINTF; }
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.hardware.security.keymint.DeviceInfo");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "DeviceInfo{";
    os << "deviceInfo: " << ::android::internal::ToString(deviceInfo);
    os << "}";
    return os.str();
  }
};  // class DeviceInfo

}  // namespace keymint

}  // namespace security

}  // namespace hardware

}  // namespace android
