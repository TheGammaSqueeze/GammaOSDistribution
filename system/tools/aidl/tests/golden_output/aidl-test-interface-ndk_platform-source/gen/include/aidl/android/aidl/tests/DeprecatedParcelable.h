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
namespace aidl {
namespace android {
namespace aidl {
namespace tests {
class __attribute__((deprecated("test"))) DeprecatedParcelable {
public:
  typedef std::false_type fixed_size;
  static const char* descriptor;


  binder_status_t readFromParcel(const AParcel* parcel);
  binder_status_t writeToParcel(AParcel* parcel) const;

  inline bool operator!=(const DeprecatedParcelable&) const {
    return std::tie() != std::tie();
  }
  inline bool operator<(const DeprecatedParcelable&) const {
    return std::tie() < std::tie();
  }
  inline bool operator<=(const DeprecatedParcelable&) const {
    return std::tie() <= std::tie();
  }
  inline bool operator==(const DeprecatedParcelable&) const {
    return std::tie() == std::tie();
  }
  inline bool operator>(const DeprecatedParcelable&) const {
    return std::tie() > std::tie();
  }
  inline bool operator>=(const DeprecatedParcelable&) const {
    return std::tie() >= std::tie();
  }

  static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_LOCAL;
  inline std::string toString() const {
    std::ostringstream os;
    os << "DeprecatedParcelable{";
    os << "}";
    return os.str();
  }
};
}  // namespace tests
}  // namespace aidl
}  // namespace android
}  // namespace aidl
