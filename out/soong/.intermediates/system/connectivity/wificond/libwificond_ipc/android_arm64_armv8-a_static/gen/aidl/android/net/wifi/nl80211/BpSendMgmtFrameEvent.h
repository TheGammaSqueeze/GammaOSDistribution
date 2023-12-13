#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/net/wifi/nl80211/ISendMgmtFrameEvent.h>

namespace android {

namespace net {

namespace wifi {

namespace nl80211 {

class BpSendMgmtFrameEvent : public ::android::BpInterface<ISendMgmtFrameEvent> {
public:
  explicit BpSendMgmtFrameEvent(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpSendMgmtFrameEvent() = default;
  ::android::binder::Status OnAck(int32_t elapsedTimeMs) override;
  ::android::binder::Status OnFailure(int32_t reason) override;
};  // class BpSendMgmtFrameEvent

}  // namespace nl80211

}  // namespace wifi

}  // namespace net

}  // namespace android
