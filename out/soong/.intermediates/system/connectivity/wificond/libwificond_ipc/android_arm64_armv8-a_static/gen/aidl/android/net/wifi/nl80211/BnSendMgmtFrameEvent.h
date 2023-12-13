#pragma once

#include <binder/IInterface.h>
#include <android/net/wifi/nl80211/ISendMgmtFrameEvent.h>

namespace android {

namespace net {

namespace wifi {

namespace nl80211 {

class BnSendMgmtFrameEvent : public ::android::BnInterface<ISendMgmtFrameEvent> {
public:
  static constexpr uint32_t TRANSACTION_OnAck = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_OnFailure = ::android::IBinder::FIRST_CALL_TRANSACTION + 1;
  explicit BnSendMgmtFrameEvent();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnSendMgmtFrameEvent

}  // namespace nl80211

}  // namespace wifi

}  // namespace net

}  // namespace android
