#pragma once

#include <android/binder_to_string.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <tuple>
#include <utils/String16.h>

namespace android {

namespace media {

class GetInputForAttrResponse : public ::android::Parcelable {
public:
  inline bool operator!=(const GetInputForAttrResponse& rhs) const {
    return std::tie(input, selectedDeviceId, portId) != std::tie(rhs.input, rhs.selectedDeviceId, rhs.portId);
  }
  inline bool operator<(const GetInputForAttrResponse& rhs) const {
    return std::tie(input, selectedDeviceId, portId) < std::tie(rhs.input, rhs.selectedDeviceId, rhs.portId);
  }
  inline bool operator<=(const GetInputForAttrResponse& rhs) const {
    return std::tie(input, selectedDeviceId, portId) <= std::tie(rhs.input, rhs.selectedDeviceId, rhs.portId);
  }
  inline bool operator==(const GetInputForAttrResponse& rhs) const {
    return std::tie(input, selectedDeviceId, portId) == std::tie(rhs.input, rhs.selectedDeviceId, rhs.portId);
  }
  inline bool operator>(const GetInputForAttrResponse& rhs) const {
    return std::tie(input, selectedDeviceId, portId) > std::tie(rhs.input, rhs.selectedDeviceId, rhs.portId);
  }
  inline bool operator>=(const GetInputForAttrResponse& rhs) const {
    return std::tie(input, selectedDeviceId, portId) >= std::tie(rhs.input, rhs.selectedDeviceId, rhs.portId);
  }

  int32_t input = int32_t(0);
  int32_t selectedDeviceId = int32_t(0);
  int32_t portId = int32_t(0);
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.media.GetInputForAttrResponse");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "GetInputForAttrResponse{";
    os << "input: " << ::android::internal::ToString(input);
    os << ", selectedDeviceId: " << ::android::internal::ToString(selectedDeviceId);
    os << ", portId: " << ::android::internal::ToString(portId);
    os << "}";
    return os.str();
  }
};  // class GetInputForAttrResponse

}  // namespace media

}  // namespace android
