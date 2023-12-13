#pragma once

#include <android/binder_to_string.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <tuple>
#include <utils/String16.h>
#include <vector>

namespace android {

namespace apex {

class ApexSessionParams : public ::android::Parcelable {
public:
  inline bool operator!=(const ApexSessionParams& rhs) const {
    return std::tie(sessionId, childSessionIds, hasRollbackEnabled, isRollback, rollbackId) != std::tie(rhs.sessionId, rhs.childSessionIds, rhs.hasRollbackEnabled, rhs.isRollback, rhs.rollbackId);
  }
  inline bool operator<(const ApexSessionParams& rhs) const {
    return std::tie(sessionId, childSessionIds, hasRollbackEnabled, isRollback, rollbackId) < std::tie(rhs.sessionId, rhs.childSessionIds, rhs.hasRollbackEnabled, rhs.isRollback, rhs.rollbackId);
  }
  inline bool operator<=(const ApexSessionParams& rhs) const {
    return std::tie(sessionId, childSessionIds, hasRollbackEnabled, isRollback, rollbackId) <= std::tie(rhs.sessionId, rhs.childSessionIds, rhs.hasRollbackEnabled, rhs.isRollback, rhs.rollbackId);
  }
  inline bool operator==(const ApexSessionParams& rhs) const {
    return std::tie(sessionId, childSessionIds, hasRollbackEnabled, isRollback, rollbackId) == std::tie(rhs.sessionId, rhs.childSessionIds, rhs.hasRollbackEnabled, rhs.isRollback, rhs.rollbackId);
  }
  inline bool operator>(const ApexSessionParams& rhs) const {
    return std::tie(sessionId, childSessionIds, hasRollbackEnabled, isRollback, rollbackId) > std::tie(rhs.sessionId, rhs.childSessionIds, rhs.hasRollbackEnabled, rhs.isRollback, rhs.rollbackId);
  }
  inline bool operator>=(const ApexSessionParams& rhs) const {
    return std::tie(sessionId, childSessionIds, hasRollbackEnabled, isRollback, rollbackId) >= std::tie(rhs.sessionId, rhs.childSessionIds, rhs.hasRollbackEnabled, rhs.isRollback, rhs.rollbackId);
  }

  int32_t sessionId = int32_t(0);
  ::std::vector<int32_t> childSessionIds = ::std::vector<int32_t>({});
  bool hasRollbackEnabled = bool(false);
  bool isRollback = bool(false);
  int32_t rollbackId = int32_t(0);
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.apex.ApexSessionParams");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "ApexSessionParams{";
    os << "sessionId: " << ::android::internal::ToString(sessionId);
    os << ", childSessionIds: " << ::android::internal::ToString(childSessionIds);
    os << ", hasRollbackEnabled: " << ::android::internal::ToString(hasRollbackEnabled);
    os << ", isRollback: " << ::android::internal::ToString(isRollback);
    os << ", rollbackId: " << ::android::internal::ToString(rollbackId);
    os << "}";
    return os.str();
  }
};  // class ApexSessionParams

}  // namespace apex

}  // namespace android
