#pragma once

#include <android/binder_to_string.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <tuple>
#include <utils/String16.h>

namespace android {

namespace os {

namespace incremental {

class StorageHealthCheckParams : public ::android::Parcelable {
public:
  inline bool operator!=(const StorageHealthCheckParams& rhs) const {
    return std::tie(blockedTimeoutMs, unhealthyTimeoutMs, unhealthyMonitoringMs) != std::tie(rhs.blockedTimeoutMs, rhs.unhealthyTimeoutMs, rhs.unhealthyMonitoringMs);
  }
  inline bool operator<(const StorageHealthCheckParams& rhs) const {
    return std::tie(blockedTimeoutMs, unhealthyTimeoutMs, unhealthyMonitoringMs) < std::tie(rhs.blockedTimeoutMs, rhs.unhealthyTimeoutMs, rhs.unhealthyMonitoringMs);
  }
  inline bool operator<=(const StorageHealthCheckParams& rhs) const {
    return std::tie(blockedTimeoutMs, unhealthyTimeoutMs, unhealthyMonitoringMs) <= std::tie(rhs.blockedTimeoutMs, rhs.unhealthyTimeoutMs, rhs.unhealthyMonitoringMs);
  }
  inline bool operator==(const StorageHealthCheckParams& rhs) const {
    return std::tie(blockedTimeoutMs, unhealthyTimeoutMs, unhealthyMonitoringMs) == std::tie(rhs.blockedTimeoutMs, rhs.unhealthyTimeoutMs, rhs.unhealthyMonitoringMs);
  }
  inline bool operator>(const StorageHealthCheckParams& rhs) const {
    return std::tie(blockedTimeoutMs, unhealthyTimeoutMs, unhealthyMonitoringMs) > std::tie(rhs.blockedTimeoutMs, rhs.unhealthyTimeoutMs, rhs.unhealthyMonitoringMs);
  }
  inline bool operator>=(const StorageHealthCheckParams& rhs) const {
    return std::tie(blockedTimeoutMs, unhealthyTimeoutMs, unhealthyMonitoringMs) >= std::tie(rhs.blockedTimeoutMs, rhs.unhealthyTimeoutMs, rhs.unhealthyMonitoringMs);
  }

  int32_t blockedTimeoutMs = int32_t(0);
  int32_t unhealthyTimeoutMs = int32_t(0);
  int32_t unhealthyMonitoringMs = int32_t(0);
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.os.incremental.StorageHealthCheckParams");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "StorageHealthCheckParams{";
    os << "blockedTimeoutMs: " << ::android::internal::ToString(blockedTimeoutMs);
    os << ", unhealthyTimeoutMs: " << ::android::internal::ToString(unhealthyTimeoutMs);
    os << ", unhealthyMonitoringMs: " << ::android::internal::ToString(unhealthyMonitoringMs);
    os << "}";
    return os.str();
  }
};  // class StorageHealthCheckParams

}  // namespace incremental

}  // namespace os

}  // namespace android
