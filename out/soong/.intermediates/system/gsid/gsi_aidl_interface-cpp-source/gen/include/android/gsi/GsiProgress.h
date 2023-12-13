#pragma once

#include <android/binder_to_string.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <string>
#include <tuple>
#include <utils/String16.h>

namespace android {

namespace gsi {

class GsiProgress : public ::android::Parcelable {
public:
  inline bool operator!=(const GsiProgress& rhs) const {
    return std::tie(step, status, bytes_processed, total_bytes) != std::tie(rhs.step, rhs.status, rhs.bytes_processed, rhs.total_bytes);
  }
  inline bool operator<(const GsiProgress& rhs) const {
    return std::tie(step, status, bytes_processed, total_bytes) < std::tie(rhs.step, rhs.status, rhs.bytes_processed, rhs.total_bytes);
  }
  inline bool operator<=(const GsiProgress& rhs) const {
    return std::tie(step, status, bytes_processed, total_bytes) <= std::tie(rhs.step, rhs.status, rhs.bytes_processed, rhs.total_bytes);
  }
  inline bool operator==(const GsiProgress& rhs) const {
    return std::tie(step, status, bytes_processed, total_bytes) == std::tie(rhs.step, rhs.status, rhs.bytes_processed, rhs.total_bytes);
  }
  inline bool operator>(const GsiProgress& rhs) const {
    return std::tie(step, status, bytes_processed, total_bytes) > std::tie(rhs.step, rhs.status, rhs.bytes_processed, rhs.total_bytes);
  }
  inline bool operator>=(const GsiProgress& rhs) const {
    return std::tie(step, status, bytes_processed, total_bytes) >= std::tie(rhs.step, rhs.status, rhs.bytes_processed, rhs.total_bytes);
  }

  ::std::string step;
  int32_t status = int32_t(0);
  int64_t bytes_processed = int64_t(0L);
  int64_t total_bytes = int64_t(0L);
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.gsi.GsiProgress");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "GsiProgress{";
    os << "step: " << ::android::internal::ToString(step);
    os << ", status: " << ::android::internal::ToString(status);
    os << ", bytes_processed: " << ::android::internal::ToString(bytes_processed);
    os << ", total_bytes: " << ::android::internal::ToString(total_bytes);
    os << "}";
    return os.str();
  }
};  // class GsiProgress

}  // namespace gsi

}  // namespace android
