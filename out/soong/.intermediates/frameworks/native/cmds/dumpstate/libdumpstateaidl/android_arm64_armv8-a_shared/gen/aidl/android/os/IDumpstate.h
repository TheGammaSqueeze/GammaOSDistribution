#pragma once

#include <android-base/unique_fd.h>
#include <android/os/IDumpstateListener.h>
#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <string>
#include <utils/StrongPointer.h>

namespace android {

namespace os {

class IDumpstate : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(Dumpstate)
  enum  : int32_t {
    BUGREPORT_MODE_FULL = 0,
    BUGREPORT_MODE_INTERACTIVE = 1,
    BUGREPORT_MODE_REMOTE = 2,
    BUGREPORT_MODE_WEAR = 3,
    BUGREPORT_MODE_TELEPHONY = 4,
    BUGREPORT_MODE_WIFI = 5,
    BUGREPORT_MODE_DEFAULT = 6,
  };
  virtual ::android::binder::Status startBugreport(int32_t callingUid, const ::std::string& callingPackage, ::android::base::unique_fd bugreportFd, ::android::base::unique_fd screenshotFd, int32_t bugreportMode, const ::android::sp<::android::os::IDumpstateListener>& listener, bool isScreenshotRequested) = 0;
  virtual ::android::binder::Status cancelBugreport(int32_t callingUid, const ::std::string& callingPackage) = 0;
};  // class IDumpstate

class IDumpstateDefault : public IDumpstate {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status startBugreport(int32_t, const ::std::string&, ::android::base::unique_fd, ::android::base::unique_fd, int32_t, const ::android::sp<::android::os::IDumpstateListener>&, bool) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status cancelBugreport(int32_t, const ::std::string&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IDumpstateDefault

}  // namespace os

}  // namespace android
