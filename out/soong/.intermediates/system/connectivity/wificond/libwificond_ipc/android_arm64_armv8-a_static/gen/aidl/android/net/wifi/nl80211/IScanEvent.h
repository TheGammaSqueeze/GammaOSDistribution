#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <utils/StrongPointer.h>

namespace android {

namespace net {

namespace wifi {

namespace nl80211 {

class IScanEvent : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(ScanEvent)
  virtual ::android::binder::Status OnScanResultReady() = 0;
  virtual ::android::binder::Status OnScanFailed() = 0;
};  // class IScanEvent

class IScanEventDefault : public IScanEvent {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status OnScanResultReady() override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status OnScanFailed() override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IScanEventDefault

}  // namespace nl80211

}  // namespace wifi

}  // namespace net

}  // namespace android
