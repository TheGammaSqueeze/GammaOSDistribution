#pragma once

#include <android/system/suspend/ISuspendCallback.h>
#include <android/system/suspend/IWakelockCallback.h>
#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <string>
#include <utils/String16.h>
#include <utils/StrongPointer.h>

namespace android {

namespace system {

namespace suspend {

class ISuspendControlService : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(SuspendControlService)
  const int32_t VERSION = 1;
  const std::string HASH = "34506b107801d68c881c2c7368ad4c676aed3e9b";
  virtual ::android::binder::Status registerCallback(const ::android::sp<::android::system::suspend::ISuspendCallback>& callback, bool* _aidl_return) = 0;
  virtual ::android::binder::Status registerWakelockCallback(const ::android::sp<::android::system::suspend::IWakelockCallback>& callback, const ::std::string& name, bool* _aidl_return) = 0;
  virtual int32_t getInterfaceVersion() = 0;
  virtual std::string getInterfaceHash() = 0;
};  // class ISuspendControlService

class ISuspendControlServiceDefault : public ISuspendControlService {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status registerCallback(const ::android::sp<::android::system::suspend::ISuspendCallback>&, bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status registerWakelockCallback(const ::android::sp<::android::system::suspend::IWakelockCallback>&, const ::std::string&, bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  int32_t getInterfaceVersion() override {
    return 0;
  }
  std::string getInterfaceHash() override {
    return "";
  }
};  // class ISuspendControlServiceDefault

}  // namespace suspend

}  // namespace system

}  // namespace android
