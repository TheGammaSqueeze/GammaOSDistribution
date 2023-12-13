#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <utils/String16.h>
#include <utils/StrongPointer.h>

namespace android {

namespace system {

namespace suspend {

class IWakelockCallback : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(WakelockCallback)
  const int32_t VERSION = 1;
  const std::string HASH = "34506b107801d68c881c2c7368ad4c676aed3e9b";
  virtual ::android::binder::Status notifyAcquired() = 0;
  virtual ::android::binder::Status notifyReleased() = 0;
  virtual int32_t getInterfaceVersion() = 0;
  virtual std::string getInterfaceHash() = 0;
};  // class IWakelockCallback

class IWakelockCallbackDefault : public IWakelockCallback {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status notifyAcquired() override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status notifyReleased() override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  int32_t getInterfaceVersion() override {
    return 0;
  }
  std::string getInterfaceHash() override {
    return "";
  }
};  // class IWakelockCallbackDefault

}  // namespace suspend

}  // namespace system

}  // namespace android
