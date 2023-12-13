#pragma once

#include <android/binder_to_string.h>
#include <android/media/AudioDevice.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <tuple>
#include <utils/String16.h>

namespace android {

namespace media {

class AudioPortDeviceExt : public ::android::Parcelable {
public:
  inline bool operator!=(const AudioPortDeviceExt& rhs) const {
    return std::tie(hwModule, device, encapsulationModes, encapsulationMetadataTypes) != std::tie(rhs.hwModule, rhs.device, rhs.encapsulationModes, rhs.encapsulationMetadataTypes);
  }
  inline bool operator<(const AudioPortDeviceExt& rhs) const {
    return std::tie(hwModule, device, encapsulationModes, encapsulationMetadataTypes) < std::tie(rhs.hwModule, rhs.device, rhs.encapsulationModes, rhs.encapsulationMetadataTypes);
  }
  inline bool operator<=(const AudioPortDeviceExt& rhs) const {
    return std::tie(hwModule, device, encapsulationModes, encapsulationMetadataTypes) <= std::tie(rhs.hwModule, rhs.device, rhs.encapsulationModes, rhs.encapsulationMetadataTypes);
  }
  inline bool operator==(const AudioPortDeviceExt& rhs) const {
    return std::tie(hwModule, device, encapsulationModes, encapsulationMetadataTypes) == std::tie(rhs.hwModule, rhs.device, rhs.encapsulationModes, rhs.encapsulationMetadataTypes);
  }
  inline bool operator>(const AudioPortDeviceExt& rhs) const {
    return std::tie(hwModule, device, encapsulationModes, encapsulationMetadataTypes) > std::tie(rhs.hwModule, rhs.device, rhs.encapsulationModes, rhs.encapsulationMetadataTypes);
  }
  inline bool operator>=(const AudioPortDeviceExt& rhs) const {
    return std::tie(hwModule, device, encapsulationModes, encapsulationMetadataTypes) >= std::tie(rhs.hwModule, rhs.device, rhs.encapsulationModes, rhs.encapsulationMetadataTypes);
  }

  int32_t hwModule = int32_t(0);
  ::android::media::AudioDevice device;
  int32_t encapsulationModes = int32_t(0);
  int32_t encapsulationMetadataTypes = int32_t(0);
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.media.AudioPortDeviceExt");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "AudioPortDeviceExt{";
    os << "hwModule: " << ::android::internal::ToString(hwModule);
    os << ", device: " << ::android::internal::ToString(device);
    os << ", encapsulationModes: " << ::android::internal::ToString(encapsulationModes);
    os << ", encapsulationMetadataTypes: " << ::android::internal::ToString(encapsulationMetadataTypes);
    os << "}";
    return os.str();
  }
};  // class AudioPortDeviceExt

}  // namespace media

}  // namespace android
