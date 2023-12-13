#pragma once

#include <android/hardware/gnss/IGnssPsdsCallback.h>
#include <android/hardware/gnss/PsdsType.h>
#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <utils/String16.h>
#include <utils/StrongPointer.h>
#include <vector>

namespace android {

namespace hardware {

namespace gnss {

class IGnssPsds : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(GnssPsds)
  const int32_t VERSION = 1;
  const std::string HASH = "10839720b90aaec329521e810d9e0501cfcef0d3";
  virtual ::android::binder::Status injectPsdsData(::android::hardware::gnss::PsdsType psdsType, const ::std::vector<uint8_t>& psdsData) = 0;
  virtual ::android::binder::Status setCallback(const ::android::sp<::android::hardware::gnss::IGnssPsdsCallback>& callback) = 0;
  virtual int32_t getInterfaceVersion() = 0;
  virtual std::string getInterfaceHash() = 0;
};  // class IGnssPsds

class IGnssPsdsDefault : public IGnssPsds {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status injectPsdsData(::android::hardware::gnss::PsdsType, const ::std::vector<uint8_t>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setCallback(const ::android::sp<::android::hardware::gnss::IGnssPsdsCallback>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  int32_t getInterfaceVersion() override {
    return 0;
  }
  std::string getInterfaceHash() override {
    return "";
  }
};  // class IGnssPsdsDefault

}  // namespace gnss

}  // namespace hardware

}  // namespace android
