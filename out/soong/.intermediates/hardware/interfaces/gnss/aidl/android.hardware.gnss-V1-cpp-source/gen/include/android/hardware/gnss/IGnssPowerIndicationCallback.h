#pragma once

#include <android/hardware/gnss/GnssPowerStats.h>
#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <utils/String16.h>
#include <utils/StrongPointer.h>

namespace android {

namespace hardware {

namespace gnss {

class IGnssPowerIndicationCallback : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(GnssPowerIndicationCallback)
  const int32_t VERSION = 1;
  const std::string HASH = "10839720b90aaec329521e810d9e0501cfcef0d3";
  enum  : int32_t {
    CAPABILITY_TOTAL = 1,
    CAPABILITY_SINGLEBAND_TRACKING = 2,
    CAPABILITY_MULTIBAND_TRACKING = 4,
    CAPABILITY_SINGLEBAND_ACQUISITION = 8,
    CAPABILITY_MULTIBAND_ACQUISITION = 16,
    CAPABILITY_OTHER_MODES = 32,
  };
  virtual ::android::binder::Status setCapabilitiesCb(int32_t capabilities) = 0;
  virtual ::android::binder::Status gnssPowerStatsCb(const ::android::hardware::gnss::GnssPowerStats& gnssPowerStats) = 0;
  virtual int32_t getInterfaceVersion() = 0;
  virtual std::string getInterfaceHash() = 0;
};  // class IGnssPowerIndicationCallback

class IGnssPowerIndicationCallbackDefault : public IGnssPowerIndicationCallback {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status setCapabilitiesCb(int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status gnssPowerStatsCb(const ::android::hardware::gnss::GnssPowerStats&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  int32_t getInterfaceVersion() override {
    return 0;
  }
  std::string getInterfaceHash() override {
    return "";
  }
};  // class IGnssPowerIndicationCallbackDefault

}  // namespace gnss

}  // namespace hardware

}  // namespace android
