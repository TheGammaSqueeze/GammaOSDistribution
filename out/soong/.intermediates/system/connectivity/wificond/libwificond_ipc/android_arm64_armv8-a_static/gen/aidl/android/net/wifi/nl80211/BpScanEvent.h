#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/net/wifi/nl80211/IScanEvent.h>

namespace android {

namespace net {

namespace wifi {

namespace nl80211 {

class BpScanEvent : public ::android::BpInterface<IScanEvent> {
public:
  explicit BpScanEvent(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpScanEvent() = default;
  ::android::binder::Status OnScanResultReady() override;
  ::android::binder::Status OnScanFailed() override;
};  // class BpScanEvent

}  // namespace nl80211

}  // namespace wifi

}  // namespace net

}  // namespace android
