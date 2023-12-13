#pragma once

#include <android/hardware/gnss/PsdsType.h>
#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <utils/String16.h>
#include <utils/StrongPointer.h>

namespace android {

namespace hardware {

namespace gnss {

class IGnssPsdsCallback : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(GnssPsdsCallback)
  const int32_t VERSION = 1;
  const std::string HASH = "10839720b90aaec329521e810d9e0501cfcef0d3";
  virtual ::android::binder::Status downloadRequestCb(::android::hardware::gnss::PsdsType psdsType) = 0;
  virtual int32_t getInterfaceVersion() = 0;
  virtual std::string getInterfaceHash() = 0;
};  // class IGnssPsdsCallback

class IGnssPsdsCallbackDefault : public IGnssPsdsCallback {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status downloadRequestCb(::android::hardware::gnss::PsdsType) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  int32_t getInterfaceVersion() override {
    return 0;
  }
  std::string getInterfaceHash() override {
    return "";
  }
};  // class IGnssPsdsCallbackDefault

}  // namespace gnss

}  // namespace hardware

}  // namespace android
