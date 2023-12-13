#pragma once

#include <binder/IInterface.h>
#include <android/net/wifi/nl80211/IClientInterface.h>

namespace android {

namespace net {

namespace wifi {

namespace nl80211 {

class BnClientInterface : public ::android::BnInterface<IClientInterface> {
public:
  static constexpr uint32_t TRANSACTION_getPacketCounters = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_signalPoll = ::android::IBinder::FIRST_CALL_TRANSACTION + 1;
  static constexpr uint32_t TRANSACTION_getMacAddress = ::android::IBinder::FIRST_CALL_TRANSACTION + 2;
  static constexpr uint32_t TRANSACTION_getInterfaceName = ::android::IBinder::FIRST_CALL_TRANSACTION + 3;
  static constexpr uint32_t TRANSACTION_getWifiScannerImpl = ::android::IBinder::FIRST_CALL_TRANSACTION + 4;
  static constexpr uint32_t TRANSACTION_SendMgmtFrame = ::android::IBinder::FIRST_CALL_TRANSACTION + 5;
  explicit BnClientInterface();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
};  // class BnClientInterface

}  // namespace nl80211

}  // namespace wifi

}  // namespace net

}  // namespace android
