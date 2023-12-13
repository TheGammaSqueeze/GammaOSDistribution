#pragma once

#include <android/binder_to_string.h>
#include <android/media/AudioStreamType.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <tuple>
#include <utils/String16.h>
#include <vector>

namespace android {

namespace media {

class GetOutputForAttrResponse : public ::android::Parcelable {
public:
  inline bool operator!=(const GetOutputForAttrResponse& rhs) const {
    return std::tie(output, stream, selectedDeviceId, portId, secondaryOutputs) != std::tie(rhs.output, rhs.stream, rhs.selectedDeviceId, rhs.portId, rhs.secondaryOutputs);
  }
  inline bool operator<(const GetOutputForAttrResponse& rhs) const {
    return std::tie(output, stream, selectedDeviceId, portId, secondaryOutputs) < std::tie(rhs.output, rhs.stream, rhs.selectedDeviceId, rhs.portId, rhs.secondaryOutputs);
  }
  inline bool operator<=(const GetOutputForAttrResponse& rhs) const {
    return std::tie(output, stream, selectedDeviceId, portId, secondaryOutputs) <= std::tie(rhs.output, rhs.stream, rhs.selectedDeviceId, rhs.portId, rhs.secondaryOutputs);
  }
  inline bool operator==(const GetOutputForAttrResponse& rhs) const {
    return std::tie(output, stream, selectedDeviceId, portId, secondaryOutputs) == std::tie(rhs.output, rhs.stream, rhs.selectedDeviceId, rhs.portId, rhs.secondaryOutputs);
  }
  inline bool operator>(const GetOutputForAttrResponse& rhs) const {
    return std::tie(output, stream, selectedDeviceId, portId, secondaryOutputs) > std::tie(rhs.output, rhs.stream, rhs.selectedDeviceId, rhs.portId, rhs.secondaryOutputs);
  }
  inline bool operator>=(const GetOutputForAttrResponse& rhs) const {
    return std::tie(output, stream, selectedDeviceId, portId, secondaryOutputs) >= std::tie(rhs.output, rhs.stream, rhs.selectedDeviceId, rhs.portId, rhs.secondaryOutputs);
  }

  int32_t output = int32_t(0);
  ::android::media::AudioStreamType stream = ::android::media::AudioStreamType(0);
  int32_t selectedDeviceId = int32_t(0);
  int32_t portId = int32_t(0);
  ::std::vector<int32_t> secondaryOutputs;
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.media.GetOutputForAttrResponse");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "GetOutputForAttrResponse{";
    os << "output: " << ::android::internal::ToString(output);
    os << ", stream: " << ::android::internal::ToString(stream);
    os << ", selectedDeviceId: " << ::android::internal::ToString(selectedDeviceId);
    os << ", portId: " << ::android::internal::ToString(portId);
    os << ", secondaryOutputs: " << ::android::internal::ToString(secondaryOutputs);
    os << "}";
    return os.str();
  }
};  // class GetOutputForAttrResponse

}  // namespace media

}  // namespace android
