#pragma once

#include <android/binder_to_string.h>
#include <binder/Parcel.h>
#include <binder/Status.h>
#include <cstdint>
#include <string>
#include <tuple>
#include <utils/String16.h>

namespace android {

namespace apex {

class ApexSessionInfo : public ::android::Parcelable {
public:
  inline bool operator!=(const ApexSessionInfo& rhs) const {
    return std::tie(sessionId, isUnknown, isVerified, isStaged, isActivated, isRevertInProgress, isActivationFailed, isSuccess, isReverted, isRevertFailed, crashingNativeProcess, errorMessage) != std::tie(rhs.sessionId, rhs.isUnknown, rhs.isVerified, rhs.isStaged, rhs.isActivated, rhs.isRevertInProgress, rhs.isActivationFailed, rhs.isSuccess, rhs.isReverted, rhs.isRevertFailed, rhs.crashingNativeProcess, rhs.errorMessage);
  }
  inline bool operator<(const ApexSessionInfo& rhs) const {
    return std::tie(sessionId, isUnknown, isVerified, isStaged, isActivated, isRevertInProgress, isActivationFailed, isSuccess, isReverted, isRevertFailed, crashingNativeProcess, errorMessage) < std::tie(rhs.sessionId, rhs.isUnknown, rhs.isVerified, rhs.isStaged, rhs.isActivated, rhs.isRevertInProgress, rhs.isActivationFailed, rhs.isSuccess, rhs.isReverted, rhs.isRevertFailed, rhs.crashingNativeProcess, rhs.errorMessage);
  }
  inline bool operator<=(const ApexSessionInfo& rhs) const {
    return std::tie(sessionId, isUnknown, isVerified, isStaged, isActivated, isRevertInProgress, isActivationFailed, isSuccess, isReverted, isRevertFailed, crashingNativeProcess, errorMessage) <= std::tie(rhs.sessionId, rhs.isUnknown, rhs.isVerified, rhs.isStaged, rhs.isActivated, rhs.isRevertInProgress, rhs.isActivationFailed, rhs.isSuccess, rhs.isReverted, rhs.isRevertFailed, rhs.crashingNativeProcess, rhs.errorMessage);
  }
  inline bool operator==(const ApexSessionInfo& rhs) const {
    return std::tie(sessionId, isUnknown, isVerified, isStaged, isActivated, isRevertInProgress, isActivationFailed, isSuccess, isReverted, isRevertFailed, crashingNativeProcess, errorMessage) == std::tie(rhs.sessionId, rhs.isUnknown, rhs.isVerified, rhs.isStaged, rhs.isActivated, rhs.isRevertInProgress, rhs.isActivationFailed, rhs.isSuccess, rhs.isReverted, rhs.isRevertFailed, rhs.crashingNativeProcess, rhs.errorMessage);
  }
  inline bool operator>(const ApexSessionInfo& rhs) const {
    return std::tie(sessionId, isUnknown, isVerified, isStaged, isActivated, isRevertInProgress, isActivationFailed, isSuccess, isReverted, isRevertFailed, crashingNativeProcess, errorMessage) > std::tie(rhs.sessionId, rhs.isUnknown, rhs.isVerified, rhs.isStaged, rhs.isActivated, rhs.isRevertInProgress, rhs.isActivationFailed, rhs.isSuccess, rhs.isReverted, rhs.isRevertFailed, rhs.crashingNativeProcess, rhs.errorMessage);
  }
  inline bool operator>=(const ApexSessionInfo& rhs) const {
    return std::tie(sessionId, isUnknown, isVerified, isStaged, isActivated, isRevertInProgress, isActivationFailed, isSuccess, isReverted, isRevertFailed, crashingNativeProcess, errorMessage) >= std::tie(rhs.sessionId, rhs.isUnknown, rhs.isVerified, rhs.isStaged, rhs.isActivated, rhs.isRevertInProgress, rhs.isActivationFailed, rhs.isSuccess, rhs.isReverted, rhs.isRevertFailed, rhs.crashingNativeProcess, rhs.errorMessage);
  }

  int32_t sessionId = int32_t(0);
  bool isUnknown = bool(false);
  bool isVerified = bool(false);
  bool isStaged = bool(false);
  bool isActivated = bool(false);
  bool isRevertInProgress = bool(false);
  bool isActivationFailed = bool(false);
  bool isSuccess = bool(false);
  bool isReverted = bool(false);
  bool isRevertFailed = bool(false);
  ::std::string crashingNativeProcess;
  ::std::string errorMessage;
  ::android::status_t readFromParcel(const ::android::Parcel* _aidl_parcel) final;
  ::android::status_t writeToParcel(::android::Parcel* _aidl_parcel) const final;
  static const ::android::String16& getParcelableDescriptor() {
    static const ::android::StaticString16 DESCIPTOR (u"android.apex.ApexSessionInfo");
    return DESCIPTOR;
  }
  inline std::string toString() const {
    std::ostringstream os;
    os << "ApexSessionInfo{";
    os << "sessionId: " << ::android::internal::ToString(sessionId);
    os << ", isUnknown: " << ::android::internal::ToString(isUnknown);
    os << ", isVerified: " << ::android::internal::ToString(isVerified);
    os << ", isStaged: " << ::android::internal::ToString(isStaged);
    os << ", isActivated: " << ::android::internal::ToString(isActivated);
    os << ", isRevertInProgress: " << ::android::internal::ToString(isRevertInProgress);
    os << ", isActivationFailed: " << ::android::internal::ToString(isActivationFailed);
    os << ", isSuccess: " << ::android::internal::ToString(isSuccess);
    os << ", isReverted: " << ::android::internal::ToString(isReverted);
    os << ", isRevertFailed: " << ::android::internal::ToString(isRevertFailed);
    os << ", crashingNativeProcess: " << ::android::internal::ToString(crashingNativeProcess);
    os << ", errorMessage: " << ::android::internal::ToString(errorMessage);
    os << "}";
    return os.str();
  }
};  // class ApexSessionInfo

}  // namespace apex

}  // namespace android
