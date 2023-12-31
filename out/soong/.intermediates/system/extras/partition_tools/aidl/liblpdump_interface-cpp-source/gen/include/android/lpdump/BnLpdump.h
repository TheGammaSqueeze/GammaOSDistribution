#pragma once

#include <binder/IInterface.h>
#include <android/lpdump/ILpdump.h>
#include <functional>
#include <android/binder_to_string.h>

namespace android {

namespace lpdump {

class BnLpdump : public ::android::BnInterface<ILpdump> {
public:
  static constexpr uint32_t TRANSACTION_run = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  explicit BnLpdump();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
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
};  // class BnLpdump

}  // namespace lpdump

}  // namespace android
