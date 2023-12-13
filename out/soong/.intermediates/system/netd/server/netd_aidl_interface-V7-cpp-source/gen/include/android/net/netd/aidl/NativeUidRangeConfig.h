#pragma once

#include <android/binder_to_string.h>
#include <android/net/UidRangeParcel.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <tuple>
#include <utils/String16.h>
#include <vector>

namespace android {

namespace net {

namespace netd {

namespace aidl {

class NativeUidRangeConfig : public ::android::Parcelable {
public:
  inline bool operator!=(const NativeUidRangeConfig& rhs) const {
    return std::tie(netId, uidRanges, subPriority) != std::tie(rhs.netId, rhs.uidRanges, rhs.subPriority);
  }
  inline bool operator<(const NativeUidRangeConfig& rhs) const {
    return std::tie(netId, uidRanges, subPriority) < std::tie(rhs.netId, rhs.uidRanges, rhs.subPriority);
  }
  inline bool operator<=(const NativeUidRangeConfig& rhs) const {
    return std::tie(netId, uidRanges, subPriority) <= std::tie(rhs.netId, rhs.uidRanges, rhs.subPriority);
  }
  inline bool operator==(const NativeUidRangeConfig& rhs) const {
    return std::tie(netId, uidRanges, subPriority) == std::tie(rhs.netId, rhs.uidRanges, rhs.subPriority);
  }
  inline bool operator>(const NativeUidRangeConfig& rhs) const {
    return std::tie(netId, uidRanges, subPriority) > std::tie(rhs.netId, rhs.uidRanges, rhs.subPriority);
  }
  inline bool operator>=(const NativeUidRangeConfig& rhs) const {
    return std::tie(netId, uidRanges, subPriority) >= std::tie(rhs.netId, rhs.uidRanges, rhs.subPriority);
  }

  int32_t netId = int32_t(0);
  ::std::vector<::android::net::UidRangeParcel> uidRanges;
  int32_t subPriority = int32_t(0);
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.net.netd.aidl.NativeUidRangeConfig");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "NativeUidRangeConfig{";
    os << "netId: " << ::android::internal::ToString(netId);
    os << ", uidRanges: " << ::android::internal::ToString(uidRanges);
    os << ", subPriority: " << ::android::internal::ToString(subPriority);
    os << "}";
    return os.str();
  }
};  // class NativeUidRangeConfig

}  // namespace aidl

}  // namespace netd

}  // namespace net

}  // namespace android
