#pragma once

#include <binder/IInterface.h>
#include <android/net/INetdUnsolicitedEventListener.h>
#include <functional>
#include <android/binder_to_string.h>

namespace android {

namespace net {

class BnNetdUnsolicitedEventListener : public ::android::BnInterface<INetdUnsolicitedEventListener> {
public:
  static constexpr uint32_t TRANSACTION_onInterfaceClassActivityChanged = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_onQuotaLimitReached = ::android::IBinder::FIRST_CALL_TRANSACTION + 1;
  static constexpr uint32_t TRANSACTION_onInterfaceDnsServerInfo = ::android::IBinder::FIRST_CALL_TRANSACTION + 2;
  static constexpr uint32_t TRANSACTION_onInterfaceAddressUpdated = ::android::IBinder::FIRST_CALL_TRANSACTION + 3;
  static constexpr uint32_t TRANSACTION_onInterfaceAddressRemoved = ::android::IBinder::FIRST_CALL_TRANSACTION + 4;
  static constexpr uint32_t TRANSACTION_onInterfaceAdded = ::android::IBinder::FIRST_CALL_TRANSACTION + 5;
  static constexpr uint32_t TRANSACTION_onInterfaceRemoved = ::android::IBinder::FIRST_CALL_TRANSACTION + 6;
  static constexpr uint32_t TRANSACTION_onInterfaceChanged = ::android::IBinder::FIRST_CALL_TRANSACTION + 7;
  static constexpr uint32_t TRANSACTION_onInterfaceLinkStateChanged = ::android::IBinder::FIRST_CALL_TRANSACTION + 8;
  static constexpr uint32_t TRANSACTION_onRouteChanged = ::android::IBinder::FIRST_CALL_TRANSACTION + 9;
  static constexpr uint32_t TRANSACTION_onStrictCleartextDetected = ::android::IBinder::FIRST_CALL_TRANSACTION + 10;
  static constexpr uint32_t TRANSACTION_getInterfaceVersion = ::android::IBinder::FIRST_CALL_TRANSACTION + 16777214;
  static constexpr uint32_t TRANSACTION_getInterfaceHash = ::android::IBinder::FIRST_CALL_TRANSACTION + 16777213;
  explicit BnNetdUnsolicitedEventListener();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
  int32_t getInterfaceVersion() final;
  std::string getInterfaceHash();
  struct TransactionLog {
    double duration_ms;
    std::string interface_name;
    std::string method_name;
    const void* proxy_address;
    const void* stub_address;
    std::vector<std::pair<std::string, std::string>> input_args;
    std::vector<std::pair<std::string, std::string>> output_args;
    std::string result;
    std::string exception_message;
    int32_t exception_code;
    int32_t transaction_error;
    int32_t service_specific_error_code;
  };
  static std::function<void(const TransactionLog&)> logFunc;
};  // class BnNetdUnsolicitedEventListener

}  // namespace net

}  // namespace android
