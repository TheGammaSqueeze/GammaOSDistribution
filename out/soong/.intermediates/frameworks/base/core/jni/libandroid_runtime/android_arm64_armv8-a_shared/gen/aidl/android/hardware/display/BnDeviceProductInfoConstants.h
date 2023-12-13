#pragma once

#include <binder/IInterface.h>
#include <android/hardware/display/IDeviceProductInfoConstants.h>

namespace android {

namespace hardware {

namespace display {

class BnDeviceProductInfoConstants : public ::android::BnInterface<IDeviceProductInfoConstants> {
public:
  explicit BnDeviceProductInfoConstants();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnDeviceProductInfoConstants

}  // namespace display

}  // namespace hardware

}  // namespace android
