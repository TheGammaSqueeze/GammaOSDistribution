#pragma once

#include <binder/IInterface.h>
#include <android/net/wifi/nl80211/IPnoScanEvent.h>

namespace android {

namespace net {

namespace wifi {

namespace nl80211 {

class BnPnoScanEvent : public ::android::BnInterface<IPnoScanEvent> {
public:
  static constexpr uint32_t TRANSACTION_OnPnoNetworkFound = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_OnPnoScanFailed = ::android::IBinder::FIRST_CALL_TRANSACTION + 1;
  explicit BnPnoScanEvent();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnPnoScanEvent

}  // namespace nl80211

}  // namespace wifi

}  // namespace net

}  // namespace android
