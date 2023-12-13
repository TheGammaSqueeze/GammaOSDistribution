#pragma once

#include "aidl/android/net/IDnsResolver.h"

#include <android/binder_ibinder.h>
#include <functional>
#include <chrono>
#include <sstream>

namespace aidl {
namespace android {
namespace net {
class BpDnsResolver : public ::ndk::BpCInterface<IDnsResolver> {
public:
  explicit BpDnsResolver(const ::ndk::SpAIBinder& binder);
  virtual ~BpDnsResolver();

  ::ndk::ScopedAStatus isAlive(bool* _aidl_return) override;
  ::ndk::ScopedAStatus registerEventListener(const std::shared_ptr<::aidl::android::net::metrics::INetdEventListener>& in_listener) override;
  ::ndk::ScopedAStatus setResolverConfiguration(const ::aidl::android::net::ResolverParamsParcel& in_resolverParams) override;
  ::ndk::ScopedAStatus getResolverInfo(int32_t in_netId, std::vector<std::string>* out_servers, std::vector<std::string>* out_domains, std::vector<std::string>* out_tlsServers, std::vector<int32_t>* out_params, std::vector<int32_t>* out_stats, std::vector<int32_t>* out_wait_for_pending_req_timeout_count) override;
  ::ndk::ScopedAStatus startPrefix64Discovery(int32_t in_netId) override;
  ::ndk::ScopedAStatus stopPrefix64Discovery(int32_t in_netId) override;
  ::ndk::ScopedAStatus getPrefix64(int32_t in_netId, std::string* _aidl_return) override;
  ::ndk::ScopedAStatus createNetworkCache(int32_t in_netId) override;
  ::ndk::ScopedAStatus destroyNetworkCache(int32_t in_netId) override;
  ::ndk::ScopedAStatus setLogSeverity(int32_t in_logSeverity) override;
  ::ndk::ScopedAStatus flushNetworkCache(int32_t in_netId) override;
  ::ndk::ScopedAStatus setPrefix64(int32_t in_netId, const std::string& in_prefix) override;
  ::ndk::ScopedAStatus registerUnsolicitedEventListener(const std::shared_ptr<::aidl::android::net::resolv::aidl::IDnsResolverUnsolicitedEventListener>& in_listener) override;
  ::ndk::ScopedAStatus setResolverOptions(int32_t in_netId, const ::aidl::android::net::ResolverOptionsParcel& in_optionParams) override;
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
}  // namespace net
}  // namespace android
}  // namespace aidl
