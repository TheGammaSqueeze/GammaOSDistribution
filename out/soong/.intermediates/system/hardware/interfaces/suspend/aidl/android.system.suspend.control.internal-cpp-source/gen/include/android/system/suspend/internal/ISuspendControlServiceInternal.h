#pragma once

#include <android/system/suspend/internal/SuspendInfo.h>
#include <android/system/suspend/internal/WakeLockInfo.h>
#include <android/system/suspend/internal/WakeupInfo.h>
#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <utils/StrongPointer.h>
#include <vector>

namespace android {

namespace system {

namespace suspend {

namespace internal {

class ISuspendControlServiceInternal : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(SuspendControlServiceInternal)
  virtual ::android::binder::Status enableAutosuspend(bool* _aidl_return) = 0;
  virtual ::android::binder::Status forceSuspend(bool* _aidl_return) = 0;
  virtual ::android::binder::Status getWakeLockStats(::std::vector<::android::system::suspend::internal::WakeLockInfo>* _aidl_return) = 0;
  virtual ::android::binder::Status getWakeupStats(::std::vector<::android::system::suspend::internal::WakeupInfo>* _aidl_return) = 0;
  virtual ::android::binder::Status getSuspendStats(::android::system::suspend::internal::SuspendInfo* _aidl_return) = 0;
};  // class ISuspendControlServiceInternal

class ISuspendControlServiceInternalDefault : public ISuspendControlServiceInternal {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status enableAutosuspend(bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status forceSuspend(bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getWakeLockStats(::std::vector<::android::system::suspend::internal::WakeLockInfo>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getWakeupStats(::std::vector<::android::system::suspend::internal::WakeupInfo>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getSuspendStats(::android::system::suspend::internal::SuspendInfo*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class ISuspendControlServiceInternalDefault

}  // namespace internal

}  // namespace suspend

}  // namespace system

}  // namespace android
