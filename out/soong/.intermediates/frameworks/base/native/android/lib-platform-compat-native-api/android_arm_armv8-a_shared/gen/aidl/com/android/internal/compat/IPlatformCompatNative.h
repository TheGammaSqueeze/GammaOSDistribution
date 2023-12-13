#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <string>
#include <utils/StrongPointer.h>

namespace com {

namespace android {

namespace internal {

namespace compat {

class IPlatformCompatNative : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(PlatformCompatNative)
  virtual ::android::binder::Status reportChangeByPackageName(int64_t changeId, const ::std::string& packageName, int32_t userId) = 0;
  virtual ::android::binder::Status reportChangeByUid(int64_t changeId, int32_t uid) = 0;
  virtual ::android::binder::Status isChangeEnabledByPackageName(int64_t changeId, const ::std::string& packageName, int32_t userId, bool* _aidl_return) = 0;
  virtual ::android::binder::Status isChangeEnabledByUid(int64_t changeId, int32_t uid, bool* _aidl_return) = 0;
};  // class IPlatformCompatNative

class IPlatformCompatNativeDefault : public IPlatformCompatNative {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status reportChangeByPackageName(int64_t, const ::std::string&, int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status reportChangeByUid(int64_t, int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status isChangeEnabledByPackageName(int64_t, const ::std::string&, int32_t, bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status isChangeEnabledByUid(int64_t, int32_t, bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IPlatformCompatNativeDefault

}  // namespace compat

}  // namespace internal

}  // namespace android

}  // namespace com
