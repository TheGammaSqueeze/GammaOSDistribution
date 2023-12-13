#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/os/IVoldTaskListener.h>

namespace android {

namespace os {

class BpVoldTaskListener : public ::android::BpInterface<IVoldTaskListener> {
public:
  explicit BpVoldTaskListener(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpVoldTaskListener() = default;
  ::android::binder::Status onStatus(int32_t status, const ::android::os::PersistableBundle& extras) override;
  ::android::binder::Status onFinished(int32_t status, const ::android::os::PersistableBundle& extras) override;
};  // class BpVoldTaskListener

}  // namespace os

}  // namespace android
