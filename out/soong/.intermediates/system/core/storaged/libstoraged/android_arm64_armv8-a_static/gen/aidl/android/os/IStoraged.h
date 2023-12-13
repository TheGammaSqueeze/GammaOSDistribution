#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <utils/StrongPointer.h>

namespace android {

namespace os {

class IStoraged : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(Storaged)
  virtual ::android::binder::Status onUserStarted(int32_t userId) = 0;
  virtual ::android::binder::Status onUserStopped(int32_t userId) = 0;
  virtual ::android::binder::Status getRecentPerf(int32_t* _aidl_return) = 0;
};  // class IStoraged

class IStoragedDefault : public IStoraged {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status onUserStarted(int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status onUserStopped(int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getRecentPerf(int32_t*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IStoragedDefault

}  // namespace os

}  // namespace android
