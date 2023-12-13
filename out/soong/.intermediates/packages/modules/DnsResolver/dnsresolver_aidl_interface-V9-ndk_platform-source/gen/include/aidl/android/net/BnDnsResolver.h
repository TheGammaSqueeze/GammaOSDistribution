#pragma once

#include "aidl/android/net/IDnsResolver.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
namespace net {
class BnDnsResolver : public ::ndk::BnCInterface<IDnsResolver> {
public:
  BnDnsResolver();
  virtual ~BnDnsResolver();
  ::ndk::ScopedAStatus getInterfaceVersion(int32_t* _aidl_return) final;
  ::ndk::ScopedAStatus getInterfaceHash(std::string* _aidl_return) final;
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
protected:
  ::ndk::SpAIBinder createBinder() override;
private:
};
}  // namespace net
}  // namespace android
}  // namespace aidl
