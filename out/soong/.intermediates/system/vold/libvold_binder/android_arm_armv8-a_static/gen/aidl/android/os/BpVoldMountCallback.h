#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/os/IVoldMountCallback.h>

namespace android {

namespace os {

class BpVoldMountCallback : public ::android::BpInterface<IVoldMountCallback> {
public:
  explicit BpVoldMountCallback(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpVoldMountCallback() = default;
  ::android::binder::Status onVolumeChecking(::android::base::unique_fd fuseFd, const ::std::string& path, const ::std::string& internalPath, bool* _aidl_return) override;
};  // class BpVoldMountCallback

}  // namespace os

}  // namespace android
