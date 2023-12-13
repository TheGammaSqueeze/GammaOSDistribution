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
#include <aidl/android/hardware/neuralnetworks/DataLocation.h>
namespace aidl {
namespace android {
namespace hardware {
namespace neuralnetworks {
class RequestArgument {
public:
  typedef std::false_type fixed_size;
  static const char* descriptor;

  bool hasNoValue = false;
  ::aidl::android::hardware::neuralnetworks::DataLocation location;
  std::vector<int32_t> dimensions;

  binder_status_t readFromParcel(const AParcel* parcel);
  binder_status_t writeToParcel(AParcel* parcel) const;

  inline bool operator!=(const RequestArgument& rhs) const {
    return std::tie(hasNoValue, location, dimensions) != std::tie(rhs.hasNoValue, rhs.location, rhs.dimensions);
  }
  inline bool operator<(const RequestArgument& rhs) const {
    return std::tie(hasNoValue, location, dimensions) < std::tie(rhs.hasNoValue, rhs.location, rhs.dimensions);
  }
  inline bool operator<=(const RequestArgument& rhs) const {
    return std::tie(hasNoValue, location, dimensions) <= std::tie(rhs.hasNoValue, rhs.location, rhs.dimensions);
  }
  inline bool operator==(const RequestArgument& rhs) const {
    return std::tie(hasNoValue, location, dimensions) == std::tie(rhs.hasNoValue, rhs.location, rhs.dimensions);
  }
  inline bool operator>(const RequestArgument& rhs) const {
    return std::tie(hasNoValue, location, dimensions) > std::tie(rhs.hasNoValue, rhs.location, rhs.dimensions);
  }
  inline bool operator>=(const RequestArgument& rhs) const {
    return std::tie(hasNoValue, location, dimensions) >= std::tie(rhs.hasNoValue, rhs.location, rhs.dimensions);
  }

  static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
  inline std::string toString() const {
    std::ostringstream os;
    os << "RequestArgument{";
    os << "hasNoValue: " << ::android::internal::ToString(hasNoValue);
    os << ", location: " << ::android::internal::ToString(location);
    os << ", dimensions: " << ::android::internal::ToString(dimensions);
    os << "}";
    return os.str();
  }
};
}  // namespace neuralnetworks
}  // namespace hardware
}  // namespace android
}  // namespace aidl
