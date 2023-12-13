#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/os/IThermalStatusListener.h>

namespace android {

namespace os {

class BpThermalStatusListener : public ::android::BpInterface<IThermalStatusListener> {
public:
  explicit BpThermalStatusListener(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpThermalStatusListener() = default;
  ::android::binder::Status onStatusChange(int32_t status) override;
};  // class BpThermalStatusListener

}  // namespace os

}  // namespace android
