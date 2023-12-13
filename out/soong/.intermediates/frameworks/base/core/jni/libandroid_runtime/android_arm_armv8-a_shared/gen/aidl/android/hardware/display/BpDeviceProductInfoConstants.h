#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/hardware/display/IDeviceProductInfoConstants.h>

namespace android {

namespace hardware {

namespace display {

class BpDeviceProductInfoConstants : public ::android::BpInterface<IDeviceProductInfoConstants> {
public:
  explicit BpDeviceProductInfoConstants(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpDeviceProductInfoConstants() = default;
};  // class BpDeviceProductInfoConstants

}  // namespace display

}  // namespace hardware

}  // namespace android
