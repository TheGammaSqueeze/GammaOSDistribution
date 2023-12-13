#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/net/wifi/nl80211/IPnoScanEvent.h>

namespace android {

namespace net {

namespace wifi {

namespace nl80211 {

class BpPnoScanEvent : public ::android::BpInterface<IPnoScanEvent> {
public:
  explicit BpPnoScanEvent(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpPnoScanEvent() = default;
  ::android::binder::Status OnPnoNetworkFound() override;
  ::android::binder::Status OnPnoScanFailed() override;
};  // class BpPnoScanEvent

}  // namespace nl80211

}  // namespace wifi

}  // namespace net

}  // namespace android
