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
#include <aidl/android/hardware/neuralnetworks/OperationType.h>
namespace aidl {
namespace android {
namespace hardware {
namespace neuralnetworks {
class Operation {
public:
  typedef std::false_type fixed_size;
  static const char* descriptor;

  ::aidl::android::hardware::neuralnetworks::OperationType type = ::aidl::android::hardware::neuralnetworks::OperationType::ADD;
  std::vector<int32_t> inputs;
  std::vector<int32_t> outputs;

  binder_status_t readFromParcel(const AParcel* parcel);
  binder_status_t writeToParcel(AParcel* parcel) const;

  inline bool operator!=(const Operation& rhs) const {
    return std::tie(type, inputs, outputs) != std::tie(rhs.type, rhs.inputs, rhs.outputs);
  }
  inline bool operator<(const Operation& rhs) const {
    return std::tie(type, inputs, outputs) < std::tie(rhs.type, rhs.inputs, rhs.outputs);
  }
  inline bool operator<=(const Operation& rhs) const {
    return std::tie(type, inputs, outputs) <= std::tie(rhs.type, rhs.inputs, rhs.outputs);
  }
  inline bool operator==(const Operation& rhs) const {
    return std::tie(type, inputs, outputs) == std::tie(rhs.type, rhs.inputs, rhs.outputs);
  }
  inline bool operator>(const Operation& rhs) const {
    return std::tie(type, inputs, outputs) > std::tie(rhs.type, rhs.inputs, rhs.outputs);
  }
  inline bool operator>=(const Operation& rhs) const {
    return std::tie(type, inputs, outputs) >= std::tie(rhs.type, rhs.inputs, rhs.outputs);
  }

  static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_VINTF;
  inline std::string toString() const {
    std::ostringstream os;
    os << "Operation{";
    os << "type: " << ::android::internal::ToString(type);
    os << ", inputs: " << ::android::internal::ToString(inputs);
    os << ", outputs: " << ::android::internal::ToString(outputs);
    os << "}";
    return os.str();
  }
};
}  // namespace neuralnetworks
}  // namespace hardware
}  // namespace android
}  // namespace aidl
