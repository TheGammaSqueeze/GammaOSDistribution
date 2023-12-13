#pragma once

#include <android/hardware/gnss/IGnssPowerIndicationCallback.h>
#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <utils/String16.h>
#include <utils/StrongPointer.h>

namespace android {

namespace hardware {

namespace gnss {

class IGnssPowerIndication : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(GnssPowerIndication)
  const int32_t VERSION = 1;
  const std::string HASH = "10839720b90aaec329521e810d9e0501cfcef0d3";
  virtual ::android::binder::Status setCallback(const ::android::sp<::android::hardware::gnss::IGnssPowerIndicationCallback>& callback) = 0;
  virtual ::android::binder::Status requestGnssPowerStats() = 0;
  virtual int32_t getInterfaceVersion() = 0;
  virtual std::string getInterfaceHash() = 0;
};  // class IGnssPowerIndication

class IGnssPowerIndicationDefault : public IGnssPowerIndication {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status setCallback(const ::android::sp<::android::hardware::gnss::IGnssPowerIndicationCallback>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status requestGnssPowerStats() override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  int32_t getInterfaceVersion() override {
    return 0;
  }
  std::string getInterfaceHash() override {
    return "";
  }
};  // class IGnssPowerIndicationDefault

}  // namespace gnss

}  // namespace hardware

}  // namespace android
