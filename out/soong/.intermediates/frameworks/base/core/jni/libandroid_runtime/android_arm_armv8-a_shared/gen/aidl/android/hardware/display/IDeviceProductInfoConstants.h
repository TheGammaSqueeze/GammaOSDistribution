#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <utils/StrongPointer.h>

namespace android {

namespace hardware {

namespace display {

class IDeviceProductInfoConstants : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(DeviceProductInfoConstants)
  enum  : int32_t {
    CONNECTION_TO_SINK_UNKNOWN = 0,
    CONNECTION_TO_SINK_BUILT_IN = 1,
    CONNECTION_TO_SINK_DIRECT = 2,
    CONNECTION_TO_SINK_TRANSITIVE = 3,
  };
};  // class IDeviceProductInfoConstants

class IDeviceProductInfoConstantsDefault : public IDeviceProductInfoConstants {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
};  // class IDeviceProductInfoConstantsDefault

}  // namespace display

}  // namespace hardware

}  // namespace android
