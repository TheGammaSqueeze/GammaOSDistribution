#pragma once

#include "aidl/android/net/resolv/aidl/IDnsResolverUnsolicitedEventListener.h"

#include <android/binder_ibinder.h>
#include <functional>
#include <chrono>
#include <sstream>

namespace aidl {
namespace android {
namespace net {
namespace resolv {
namespace aidl {
class BpDnsResolverUnsolicitedEventListener : public ::ndk::BpCInterface<IDnsResolverUnsolicitedEventListener> {
public:
  explicit BpDnsResolverUnsolicitedEventListener(const ::ndk::SpAIBinder& binder);
  virtual ~BpDnsResolverUnsolicitedEventListener();

  ::ndk::ScopedAStatus onDnsHealthEvent(const ::aidl::android::net::resolv::aidl::DnsHealthEventParcel& in_dnsHealthEvent) override;
  ::ndk::ScopedAStatus onNat64PrefixEvent(const ::aidl::android::net::resolv::aidl::Nat64PrefixEventParcel& in_nat64PrefixEvent) override;
  ::ndk::ScopedAStatus onPrivateDnsValidationEvent(const ::aidl::android::net::resolv::aidl::PrivateDnsValidationEventParcel& in_privateDnsValidationEvent) override;
  ::ndk::ScopedAStatus getInterfaceVersion(int32_t* _aidl_return) override;
  ::ndk::ScopedAStatus getInterfaceHash(std::string* _aidl_return) override;
  int32_t _aidl_cached_version = -1;
  std::string _aidl_cached_hash = "-1";
  std::mutex _aidl_cached_hash_mutex;
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
};
}  // namespace aidl
}  // namespace resolv
}  // namespace net
}  // namespace android
}  // namespace aidl
