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
#include <aidl/android/hardware/security/keymint/HardwareAuthToken.h>
#include <aidl/android/hardware/security/secureclock/TimeStampToken.h>
namespace aidl {
namespace android {
namespace security {
namespace authorization {
class AuthorizationTokens {
public:
  typedef std::false_type fixed_size;
  static const char* descriptor;

  ::aidl::android::hardware::security::keymint::HardwareAuthToken authToken;
  ::aidl::android::hardware::security::secureclock::TimeStampToken timestampToken;

  binder_status_t readFromParcel(const AParcel* parcel);
  binder_status_t writeToParcel(AParcel* parcel) const;

  inline bool operator!=(const AuthorizationTokens& rhs) const {
    return std::tie(authToken, timestampToken) != std::tie(rhs.authToken, rhs.timestampToken);
  }
  inline bool operator<(const AuthorizationTokens& rhs) const {
    return std::tie(authToken, timestampToken) < std::tie(rhs.authToken, rhs.timestampToken);
  }
  inline bool operator<=(const AuthorizationTokens& rhs) const {
    return std::tie(authToken, timestampToken) <= std::tie(rhs.authToken, rhs.timestampToken);
  }
  inline bool operator==(const AuthorizationTokens& rhs) const {
    return std::tie(authToken, timestampToken) == std::tie(rhs.authToken, rhs.timestampToken);
  }
  inline bool operator>(const AuthorizationTokens& rhs) const {
    return std::tie(authToken, timestampToken) > std::tie(rhs.authToken, rhs.timestampToken);
  }
  inline bool operator>=(const AuthorizationTokens& rhs) const {
    return std::tie(authToken, timestampToken) >= std::tie(rhs.authToken, rhs.timestampToken);
  }

  static const ::ndk::parcelable_stability_t _aidl_stability = ::ndk::STABILITY_LOCAL;
  inline std::string toString() const {
    std::ostringstream os;
    os << "AuthorizationTokens{";
    os << "authToken: " << ::android::internal::ToString(authToken);
    os << ", timestampToken: " << ::android::internal::ToString(timestampToken);
    os << "}";
    return os.str();
  }
};
}  // namespace authorization
}  // namespace security
}  // namespace android
}  // namespace aidl
