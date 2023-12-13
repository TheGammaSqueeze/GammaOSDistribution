#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <utils/StrongPointer.h>

namespace android {

namespace net {

namespace wifi {

namespace nl80211 {

class IPnoScanEvent : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(PnoScanEvent)
  virtual ::android::binder::Status OnPnoNetworkFound() = 0;
  virtual ::android::binder::Status OnPnoScanFailed() = 0;
};  // class IPnoScanEvent

class IPnoScanEventDefault : public IPnoScanEvent {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status OnPnoNetworkFound() override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status OnPnoScanFailed() override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
};  // class IPnoScanEventDefault

}  // namespace nl80211

}  // namespace wifi

}  // namespace net

}  // namespace android
