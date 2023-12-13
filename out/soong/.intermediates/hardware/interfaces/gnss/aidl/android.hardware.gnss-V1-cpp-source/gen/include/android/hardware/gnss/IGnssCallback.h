#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <utils/String16.h>
#include <utils/StrongPointer.h>

namespace android {

namespace hardware {

namespace gnss {

class IGnssCallback : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(GnssCallback)
  const int32_t VERSION = 1;
  const std::string HASH = "10839720b90aaec329521e810d9e0501cfcef0d3";
  enum  : int32_t {
    CAPABILITY_SATELLITE_BLOCKLIST = 512,
    CAPABILITY_CORRELATION_VECTOR = 4096,
    CAPABILITY_SATELLITE_PVT = 8192,
    CAPABILITY_MEASUREMENT_CORRECTIONS_FOR_DRIVING = 16384,
  };
  virtual ::android::binder::Status gnssSetCapabilitiesCb(int32_t capabilities) = 0;
  virtual int32_t getInterfaceVersion() = 0;
  virtual std::string getInterfaceHash() = 0;
};  // class IGnssCallback

class IGnssCallbackDefault : public IGnssCallback {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status gnssSetCapabilitiesCb(int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  int32_t getInterfaceVersion() override {
    return 0;
  }
  std::string getInterfaceHash() override {
    return "";
  }
};  // class IGnssCallbackDefault

}  // namespace gnss

}  // namespace hardware

}  // namespace android
