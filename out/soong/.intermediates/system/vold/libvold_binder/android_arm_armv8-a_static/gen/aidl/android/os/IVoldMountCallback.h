#pragma once

#include <android-base/unique_fd.h>
#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <string>
#include <utils/StrongPointer.h>

namespace android {

namespace os {

class IVoldMountCallback : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(VoldMountCallback)
  virtual ::android::binder::Status onVolumeChecking(::android::base::unique_fd fuseFd, const ::std::string& path, const ::std::string& internalPath, bool* _aidl_return) = 0;
};  // class IVoldMountCallback

class IVoldMountCallbackDefault : public IVoldMountCallback {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status onVolumeChecking(::android::base::unique_fd, const ::std::string&, const ::std::string&, bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IVoldMountCallbackDefault

}  // namespace os

}  // namespace android
