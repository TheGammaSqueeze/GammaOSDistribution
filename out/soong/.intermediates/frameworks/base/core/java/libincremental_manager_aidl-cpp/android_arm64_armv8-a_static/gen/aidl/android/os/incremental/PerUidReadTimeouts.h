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

class PerUidReadTimeouts : public ::android::Parcelable {
public:
  inline bool operator!=(const PerUidReadTimeouts& rhs) const {
    return std::tie(uid, minTimeUs, minPendingTimeUs, maxPendingTimeUs) != std::tie(rhs.uid, rhs.minTimeUs, rhs.minPendingTimeUs, rhs.maxPendingTimeUs);
  }
  inline bool operator<(const PerUidReadTimeouts& rhs) const {
    return std::tie(uid, minTimeUs, minPendingTimeUs, maxPendingTimeUs) < std::tie(rhs.uid, rhs.minTimeUs, rhs.minPendingTimeUs, rhs.maxPendingTimeUs);
  }
  inline bool operator<=(const PerUidReadTimeouts& rhs) const {
    return std::tie(uid, minTimeUs, minPendingTimeUs, maxPendingTimeUs) <= std::tie(rhs.uid, rhs.minTimeUs, rhs.minPendingTimeUs, rhs.maxPendingTimeUs);
  }
  inline bool operator==(const PerUidReadTimeouts& rhs) const {
    return std::tie(uid, minTimeUs, minPendingTimeUs, maxPendingTimeUs) == std::tie(rhs.uid, rhs.minTimeUs, rhs.minPendingTimeUs, rhs.maxPendingTimeUs);
  }
  inline bool operator>(const PerUidReadTimeouts& rhs) const {
    return std::tie(uid, minTimeUs, minPendingTimeUs, maxPendingTimeUs) > std::tie(rhs.uid, rhs.minTimeUs, rhs.minPendingTimeUs, rhs.maxPendingTimeUs);
  }
  inline bool operator>=(const PerUidReadTimeouts& rhs) const {
    return std::tie(uid, minTimeUs, minPendingTimeUs, maxPendingTimeUs) >= std::tie(rhs.uid, rhs.minTimeUs, rhs.minPendingTimeUs, rhs.maxPendingTimeUs);
  }

  int32_t uid = int32_t(0);
  int64_t minTimeUs = int64_t(0L);
  int64_t minPendingTimeUs = int64_t(0L);
  int64_t maxPendingTimeUs = int64_t(0L);
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.os.incremental.PerUidReadTimeouts");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "PerUidReadTimeouts{";
    os << "uid: " << ::android::internal::ToString(uid);
    os << ", minTimeUs: " << ::android::internal::ToString(minTimeUs);
    os << ", minPendingTimeUs: " << ::android::internal::ToString(minPendingTimeUs);
    os << ", maxPendingTimeUs: " << ::android::internal::ToString(maxPendingTimeUs);
    os << "}";
    return os.str();
  }
};  // class PerUidReadTimeouts

}  // namespace incremental

}  // namespace os

}  // namespace android
