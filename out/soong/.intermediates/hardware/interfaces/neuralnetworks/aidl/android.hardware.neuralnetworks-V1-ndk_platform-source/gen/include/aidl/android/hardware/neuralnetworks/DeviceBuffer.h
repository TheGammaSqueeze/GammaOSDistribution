#pragma once
#include <android/binder_interface_utils.h>
#include <android/binder_parcelable_utils.h>
#include <android/binder_to_string.h>
#include <cstdint>
#include <memory>
#include <optional>
#include <string>
#include <vector>
#ifdef BINDER_STABILITY_SUPPORT
#include <android/binder_stability.h>
#endif  // BINDER_STABILITY_SUPPORT
#include <aidl/android/hardware/neuralnetworks/IBuffer.h>
namespace aidl {
namespace android {
namespace hardware {
namespace neuralnetworks {
class DeviceBuffer {
public:
  typedef std::false_type fixed_size;
  static const char* descriptor;

  std::shared_ptr<::aidl::android::hardware::neuralnetworks::IBuffer> buffer;
  int32_t token = 0;

  binder_status_t readFromParcel(const AParcel* parcel);
  binder_status_t writeToParcel(AParcel* parcel) const;

  inline bool operator!=(const DeviceBuffer& rhs) const {
    return std::tie(buffer, token) != std::tie(rhs.buffer, rhs.token);
  }
  inline bool operator<(const DeviceBuffer& rhs) const {
    return std::tie(buffer, token) < std::tie(rhs.buffer, rhs.token);
  }
  inline bool operator<=(const DeviceBuffer& rhs) const {
    return std::tie(buffer, token) <= std::tie(rhs.buffer, rhs.token);
  }
  inline bool operator==(const DeviceBuffer& rhs) const {
    return std::tie(buffer, token) == std::tie(rhs.buffer, rhs.token);
  }
  inline bool operator>(const DeviceBuffer& rhs) const {
    return std::tie(buffer, token) > std::tie(rhs.buffer, rhs.token);
  }
  inline bool operator>=(const DeviceBuffer& rhs) const {
    return std::tie(buffer, token) >= std::tie(rhs.buffer, rhs.token);
  }

  static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
  inline std::string toString() const {
    std::ostringstream os;
    os << "DeviceBuffer{";
    os << "buffer: " << ::android::internal::ToString(buffer);
    os << ", token: " << ::android::internal::ToString(token);
    os << "}";
    return os.str();
  }
};
}  // namespace neuralnetworks
}  // namespace hardware
}  // namespace android
}  // namespace aidl
