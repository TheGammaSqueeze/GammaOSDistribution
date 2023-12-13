#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/os/IThermalEventListener.h>

namespace android {

namespace os {

class BpThermalEventListener : public ::android::BpInterface<IThermalEventListener> {
public:
  explicit BpThermalEventListener(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpThermalEventListener() = default;
  ::android::binder::Status notifyThrottling(const ::android::os::Temperature& temperature) override;
};  // class BpThermalEventListener

}  // namespace os

}  // namespace android
