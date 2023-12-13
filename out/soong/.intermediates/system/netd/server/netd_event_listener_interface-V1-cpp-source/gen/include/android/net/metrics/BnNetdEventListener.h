#pragma once

#include <binder/IInterface.h>
#include <android/net/metrics/INetdEventListener.h>

namespace android {

namespace net {

namespace metrics {

class BnNetdEventListener : public ::android::BnInterface<INetdEventListener> {
public:
  static constexpr uint32_t TRANSACTION_onDnsEvent = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_onPrivateDnsValidationEvent = ::android::IBinder::FIRST_CALL_TRANSACTION + 1;
  static constexpr uint32_t TRANSACTION_onConnectEvent = ::android::IBinder::FIRST_CALL_TRANSACTION + 2;
  static constexpr uint32_t TRANSACTION_onWakeupEvent = ::android::IBinder::FIRST_CALL_TRANSACTION + 3;
  static constexpr uint32_t TRANSACTION_onTcpSocketStatsEvent = ::android::IBinder::FIRST_CALL_TRANSACTION + 4;
  static constexpr uint32_t TRANSACTION_onNat64PrefixEvent = ::android::IBinder::FIRST_CALL_TRANSACTION + 5;
  static constexpr uint32_t TRANSACTION_getInterfaceVersion = ::android::IBinder::FIRST_CALL_TRANSACTION + 16777214;
  static constexpr uint32_t TRANSACTION_getInterfaceHash = ::android::IBinder::FIRST_CALL_TRANSACTION + 16777213;
  explicit BnNetdEventListener();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
  int32_t getInterfaceVersion() final;
  std::string getInterfaceHash();
};  // class BnNetdEventListener

}  // namespace metrics

}  // namespace net

}  // namespace android
