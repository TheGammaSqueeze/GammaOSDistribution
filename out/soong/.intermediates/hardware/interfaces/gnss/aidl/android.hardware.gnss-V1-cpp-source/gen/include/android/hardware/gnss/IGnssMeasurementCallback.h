#pragma once

#include <android/hardware/gnss/GnssData.h>
#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <utils/String16.h>
#include <utils/StrongPointer.h>

namespace android {

namespace hardware {

namespace gnss {

class IGnssMeasurementCallback : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(GnssMeasurementCallback)
  const int32_t VERSION = 1;
  const std::string HASH = "10839720b90aaec329521e810d9e0501cfcef0d3";
  virtual ::android::binder::Status gnssMeasurementCb(const ::android::hardware::gnss::GnssData& data) = 0;
  virtual int32_t getInterfaceVersion() = 0;
  virtual std::string getInterfaceHash() = 0;
};  // class IGnssMeasurementCallback

class IGnssMeasurementCallbackDefault : public IGnssMeasurementCallback {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status gnssMeasurementCb(const ::android::hardware::gnss::GnssData&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  int32_t getInterfaceVersion() override {
    return 0;
  }
  std::string getInterfaceHash() override {
    return "";
  }
};  // class IGnssMeasurementCallbackDefault

}  // namespace gnss

}  // namespace hardware

}  // namespace android
