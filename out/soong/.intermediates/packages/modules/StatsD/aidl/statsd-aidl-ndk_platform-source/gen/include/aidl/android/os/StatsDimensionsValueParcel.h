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
#include <aidl/android/os/StatsDimensionsValueParcel.h>
namespace aidl {
namespace android {
namespace os {
class StatsDimensionsValueParcel {
public:
  typedef std::false_type fixed_size;
  static const char* descriptor;

  int32_t field = 0;
  int32_t valueType = 0;
  std::string stringValue;
  int32_t intValue = 0;
  int64_t longValue = 0L;
  bool boolValue = false;
  float floatValue = 0.000000f;
  std::vector<::aidl::android::os::StatsDimensionsValueParcel> tupleValue;

  binder_status_t readFromParcel(const AParcel* parcel);
  binder_status_t writeToParcel(AParcel* parcel) const;

  inline bool operator!=(const StatsDimensionsValueParcel& rhs) const {
    return std::tie(field, valueType, stringValue, intValue, longValue, boolValue, floatValue, tupleValue) != std::tie(rhs.field, rhs.valueType, rhs.stringValue, rhs.intValue, rhs.longValue, rhs.boolValue, rhs.floatValue, rhs.tupleValue);
  }
  inline bool operator<(const StatsDimensionsValueParcel& rhs) const {
    return std::tie(field, valueType, stringValue, intValue, longValue, boolValue, floatValue, tupleValue) < std::tie(rhs.field, rhs.valueType, rhs.stringValue, rhs.intValue, rhs.longValue, rhs.boolValue, rhs.floatValue, rhs.tupleValue);
  }
  inline bool operator<=(const StatsDimensionsValueParcel& rhs) const {
    return std::tie(field, valueType, stringValue, intValue, longValue, boolValue, floatValue, tupleValue) <= std::tie(rhs.field, rhs.valueType, rhs.stringValue, rhs.intValue, rhs.longValue, rhs.boolValue, rhs.floatValue, rhs.tupleValue);
  }
  inline bool operator==(const StatsDimensionsValueParcel& rhs) const {
    return std::tie(field, valueType, stringValue, intValue, longValue, boolValue, floatValue, tupleValue) == std::tie(rhs.field, rhs.valueType, rhs.stringValue, rhs.intValue, rhs.longValue, rhs.boolValue, rhs.floatValue, rhs.tupleValue);
  }
  inline bool operator>(const StatsDimensionsValueParcel& rhs) const {
    return std::tie(field, valueType, stringValue, intValue, longValue, boolValue, floatValue, tupleValue) > std::tie(rhs.field, rhs.valueType, rhs.stringValue, rhs.intValue, rhs.longValue, rhs.boolValue, rhs.floatValue, rhs.tupleValue);
  }
  inline bool operator>=(const StatsDimensionsValueParcel& rhs) const {
    return std::tie(field, valueType, stringValue, intValue, longValue, boolValue, floatValue, tupleValue) >= std::tie(rhs.field, rhs.valueType, rhs.stringValue, rhs.intValue, rhs.longValue, rhs.boolValue, rhs.floatValue, rhs.tupleValue);
  }

  static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_LOCAL;
  inline std::string toString() const {
    std::ostringstream os;
    os << "StatsDimensionsValueParcel{";
    os << "field: " << ::android::internal::ToString(field);
    os << ", valueType: " << ::android::internal::ToString(valueType);
    os << ", stringValue: " << ::android::internal::ToString(stringValue);
    os << ", intValue: " << ::android::internal::ToString(intValue);
    os << ", longValue: " << ::android::internal::ToString(longValue);
    os << ", boolValue: " << ::android::internal::ToString(boolValue);
    os << ", floatValue: " << ::android::internal::ToString(floatValue);
    os << ", tupleValue: " << ::android::internal::ToString(tupleValue);
    os << "}";
    return os.str();
  }
};
}  // namespace os
}  // namespace android
}  // namespace aidl
