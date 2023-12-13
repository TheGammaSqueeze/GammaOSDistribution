#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/system/suspend/internal/ISuspendControlServiceInternal.h>

namespace android {

namespace system {

namespace suspend {

namespace internal {

class BpSuspendControlServiceInternal : public ::android::BpInterface<ISuspendControlServiceInternal> {
public:
  explicit BpSuspendControlServiceInternal(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpSuspendControlServiceInternal() = default;
  ::android::binder::Status enableAutosuspend(bool* _aidl_return) override;
  ::android::binder::Status forceSuspend(bool* _aidl_return) override;
  ::android::binder::Status getWakeLockStats(::std::vector<::android::system::suspend::internal::WakeLockInfo>* _aidl_return) override;
  ::android::binder::Status getWakeupStats(::std::vector<::android::system::suspend::internal::WakeupInfo>* _aidl_return) override;
  ::android::binder::Status getSuspendStats(::android::system::suspend::internal::SuspendInfo* _aidl_return) override;
};  // class BpSuspendControlServiceInternal

}  // namespace internal

}  // namespace suspend

}  // namespace system

}  // namespace android
