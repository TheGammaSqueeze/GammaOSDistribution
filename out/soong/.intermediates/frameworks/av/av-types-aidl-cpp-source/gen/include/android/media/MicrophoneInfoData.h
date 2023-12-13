#pragma once

#include <android/binder_to_string.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <string>
#include <tuple>
#include <utils/String16.h>
#include <vector>

namespace android {

namespace media {

class MicrophoneInfoData : public ::android::Parcelable {
public:
  inline bool operator!=(const MicrophoneInfoData& rhs) const {
    return std::tie(deviceId, portId, type, address, deviceLocation, deviceGroup, indexInTheGroup, geometricLocation, orientation, frequencies, frequencyResponses, channelMapping, sensitivity, maxSpl, minSpl, directionality) != std::tie(rhs.deviceId, rhs.portId, rhs.type, rhs.address, rhs.deviceLocation, rhs.deviceGroup, rhs.indexInTheGroup, rhs.geometricLocation, rhs.orientation, rhs.frequencies, rhs.frequencyResponses, rhs.channelMapping, rhs.sensitivity, rhs.maxSpl, rhs.minSpl, rhs.directionality);
  }
  inline bool operator<(const MicrophoneInfoData& rhs) const {
    return std::tie(deviceId, portId, type, address, deviceLocation, deviceGroup, indexInTheGroup, geometricLocation, orientation, frequencies, frequencyResponses, channelMapping, sensitivity, maxSpl, minSpl, directionality) < std::tie(rhs.deviceId, rhs.portId, rhs.type, rhs.address, rhs.deviceLocation, rhs.deviceGroup, rhs.indexInTheGroup, rhs.geometricLocation, rhs.orientation, rhs.frequencies, rhs.frequencyResponses, rhs.channelMapping, rhs.sensitivity, rhs.maxSpl, rhs.minSpl, rhs.directionality);
  }
  inline bool operator<=(const MicrophoneInfoData& rhs) const {
    return std::tie(deviceId, portId, type, address, deviceLocation, deviceGroup, indexInTheGroup, geometricLocation, orientation, frequencies, frequencyResponses, channelMapping, sensitivity, maxSpl, minSpl, directionality) <= std::tie(rhs.deviceId, rhs.portId, rhs.type, rhs.address, rhs.deviceLocation, rhs.deviceGroup, rhs.indexInTheGroup, rhs.geometricLocation, rhs.orientation, rhs.frequencies, rhs.frequencyResponses, rhs.channelMapping, rhs.sensitivity, rhs.maxSpl, rhs.minSpl, rhs.directionality);
  }
  inline bool operator==(const MicrophoneInfoData& rhs) const {
    return std::tie(deviceId, portId, type, address, deviceLocation, deviceGroup, indexInTheGroup, geometricLocation, orientation, frequencies, frequencyResponses, channelMapping, sensitivity, maxSpl, minSpl, directionality) == std::tie(rhs.deviceId, rhs.portId, rhs.type, rhs.address, rhs.deviceLocation, rhs.deviceGroup, rhs.indexInTheGroup, rhs.geometricLocation, rhs.orientation, rhs.frequencies, rhs.frequencyResponses, rhs.channelMapping, rhs.sensitivity, rhs.maxSpl, rhs.minSpl, rhs.directionality);
  }
  inline bool operator>(const MicrophoneInfoData& rhs) const {
    return std::tie(deviceId, portId, type, address, deviceLocation, deviceGroup, indexInTheGroup, geometricLocation, orientation, frequencies, frequencyResponses, channelMapping, sensitivity, maxSpl, minSpl, directionality) > std::tie(rhs.deviceId, rhs.portId, rhs.type, rhs.address, rhs.deviceLocation, rhs.deviceGroup, rhs.indexInTheGroup, rhs.geometricLocation, rhs.orientation, rhs.frequencies, rhs.frequencyResponses, rhs.channelMapping, rhs.sensitivity, rhs.maxSpl, rhs.minSpl, rhs.directionality);
  }
  inline bool operator>=(const MicrophoneInfoData& rhs) const {
    return std::tie(deviceId, portId, type, address, deviceLocation, deviceGroup, indexInTheGroup, geometricLocation, orientation, frequencies, frequencyResponses, channelMapping, sensitivity, maxSpl, minSpl, directionality) >= std::tie(rhs.deviceId, rhs.portId, rhs.type, rhs.address, rhs.deviceLocation, rhs.deviceGroup, rhs.indexInTheGroup, rhs.geometricLocation, rhs.orientation, rhs.frequencies, rhs.frequencyResponses, rhs.channelMapping, rhs.sensitivity, rhs.maxSpl, rhs.minSpl, rhs.directionality);
  }

  ::std::string deviceId;
  int32_t portId = int32_t(0);
  int32_t type = int32_t(0);
  ::std::string address;
  int32_t deviceLocation = int32_t(0);
  int32_t deviceGroup = int32_t(0);
  int32_t indexInTheGroup = int32_t(0);
  ::std::vector<float> geometricLocation;
  ::std::vector<float> orientation;
  ::std::vector<float> frequencies;
  ::std::vector<float> frequencyResponses;
  ::std::vector<int32_t> channelMapping;
  float sensitivity = float(0.000000f);
  float maxSpl = float(0.000000f);
  float minSpl = float(0.000000f);
  int32_t directionality = int32_t(0);
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.media.MicrophoneInfoData");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "MicrophoneInfoData{";
    os << "deviceId: " << ::android::internal::ToString(deviceId);
    os << ", portId: " << ::android::internal::ToString(portId);
    os << ", type: " << ::android::internal::ToString(type);
    os << ", address: " << ::android::internal::ToString(address);
    os << ", deviceLocation: " << ::android::internal::ToString(deviceLocation);
    os << ", deviceGroup: " << ::android::internal::ToString(deviceGroup);
    os << ", indexInTheGroup: " << ::android::internal::ToString(indexInTheGroup);
    os << ", geometricLocation: " << ::android::internal::ToString(geometricLocation);
    os << ", orientation: " << ::android::internal::ToString(orientation);
    os << ", frequencies: " << ::android::internal::ToString(frequencies);
    os << ", frequencyResponses: " << ::android::internal::ToString(frequencyResponses);
    os << ", channelMapping: " << ::android::internal::ToString(channelMapping);
    os << ", sensitivity: " << ::android::internal::ToString(sensitivity);
    os << ", maxSpl: " << ::android::internal::ToString(maxSpl);
    os << ", minSpl: " << ::android::internal::ToString(minSpl);
    os << ", directionality: " << ::android::internal::ToString(directionality);
    os << "}";
    return os.str();
  }
};  // class MicrophoneInfoData

}  // namespace media

}  // namespace android
