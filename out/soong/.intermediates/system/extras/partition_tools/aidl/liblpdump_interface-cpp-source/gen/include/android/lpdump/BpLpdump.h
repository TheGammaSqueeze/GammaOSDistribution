#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/lpdump/ILpdump.h>
#include <functional>
#include <android/binder_to_string.h>

namespace android {

namespace lpdump {

class BpLpdump : public ::android::BpInterface<ILpdump> {
public:
  explicit BpLpdump(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpLpdump() = default;
  ::android::binder::Status run(const ::std::vector<::std::string>& args, ::std::string* _aidl_return) override;
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
};  // class BpLpdump

}  // namespace lpdump

}  // namespace android
