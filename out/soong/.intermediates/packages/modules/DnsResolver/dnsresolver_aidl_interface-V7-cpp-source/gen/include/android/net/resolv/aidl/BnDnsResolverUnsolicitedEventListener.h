#pragma once

#include <binder/IInterface.h>
#include <android/net/resolv/aidl/IDnsResolverUnsolicitedEventListener.h>

namespace android {

namespace net {

namespace resolv {

namespace aidl {

class BnDnsResolverUnsolicitedEventListener : public ::android::BnInterface<IDnsResolverUnsolicitedEventListener> {
public:
  static constexpr uint32_t TRANSACTION_onDnsHealthEvent = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_onNat64PrefixEvent = ::android::IBinder::FIRST_CALL_TRANSACTION + 1;
  static constexpr uint32_t TRANSACTION_onPrivateDnsValidationEvent = ::android::IBinder::FIRST_CALL_TRANSACTION + 2;
  static constexpr uint32_t TRANSACTION_getInterfaceVersion = ::android::IBinder::FIRST_CALL_TRANSACTION + 16777214;
  static constexpr uint32_t TRANSACTION_getInterfaceHash = ::android::IBinder::FIRST_CALL_TRANSACTION + 16777213;
  explicit BnDnsResolverUnsolicitedEventListener();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
  int32_t getInterfaceVersion() final;
  std::string getInterfaceHash();
};  // class BnDnsResolverUnsolicitedEventListener

}  // namespace aidl

}  // namespace resolv

}  // namespace net

}  // namespace android
