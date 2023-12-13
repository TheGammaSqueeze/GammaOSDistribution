#pragma once

#include <android/binder_interface_utils.h>
#include <functional>
#include <chrono>
#include <sstream>

#include <cstdint>
#include <memory>
#include <optional>
#include <string>
#include <vector>
#ifdef BINDER_STABILITY_SUPPORT
#include <android/binder_stability.h>
#endif  // BINDER_STABILITY_SUPPORT
#include <aidl/android/net/ResolverOptionsParcel.h>
#include <aidl/android/net/ResolverParamsParcel.h>
#include <aidl/android/net/metrics/INetdEventListener.h>
#include <aidl/android/net/resolv/aidl/IDnsResolverUnsolicitedEventListener.h>

namespace aidl {
namespace android {
namespace net {
class IDnsResolver : public ::ndk::ICInterface {
public:
  static const char* descriptor;
  IDnsResolver();
  virtual ~IDnsResolver();

  enum : int32_t { RESOLVER_PARAMS_SAMPLE_VALIDITY = 0 };
  enum : int32_t { RESOLVER_PARAMS_SUCCESS_THRESHOLD = 1 };
  enum : int32_t { RESOLVER_PARAMS_MIN_SAMPLES = 2 };
  enum : int32_t { RESOLVER_PARAMS_MAX_SAMPLES = 3 };
  enum : int32_t { RESOLVER_PARAMS_BASE_TIMEOUT_MSEC = 4 };
  enum : int32_t { RESOLVER_PARAMS_RETRY_COUNT = 5 };
  enum : int32_t { RESOLVER_PARAMS_COUNT = 6 };
  enum : int32_t { RESOLVER_STATS_SUCCESSES = 0 };
  enum : int32_t { RESOLVER_STATS_ERRORS = 1 };
  enum : int32_t { RESOLVER_STATS_TIMEOUTS = 2 };
  enum : int32_t { RESOLVER_STATS_INTERNAL_ERRORS = 3 };
  enum : int32_t { RESOLVER_STATS_RTT_AVG = 4 };
  enum : int32_t { RESOLVER_STATS_LAST_SAMPLE_TIME = 5 };
  enum : int32_t { RESOLVER_STATS_USABLE = 6 };
  enum : int32_t { RESOLVER_STATS_COUNT = 7 };
  enum : int32_t { DNS_RESOLVER_LOG_VERBOSE = 0 };
  enum : int32_t { DNS_RESOLVER_LOG_DEBUG = 1 };
  enum : int32_t { DNS_RESOLVER_LOG_INFO = 2 };
  enum : int32_t { DNS_RESOLVER_LOG_WARNING = 3 };
  enum : int32_t { DNS_RESOLVER_LOG_ERROR = 4 };
  enum : int32_t { TC_MODE_DEFAULT = 0 };
  enum : int32_t { TC_MODE_UDP_TCP = 1 };
  enum : int32_t { TRANSPORT_UNKNOWN = -1 };
  enum : int32_t { TRANSPORT_CELLULAR = 0 };
  enum : int32_t { TRANSPORT_WIFI = 1 };
  enum : int32_t { TRANSPORT_BLUETOOTH = 2 };
  enum : int32_t { TRANSPORT_ETHERNET = 3 };
  enum : int32_t { TRANSPORT_VPN = 4 };
  enum : int32_t { TRANSPORT_WIFI_AWARE = 5 };
  enum : int32_t { TRANSPORT_LOWPAN = 6 };
  enum : int32_t { TRANSPORT_TEST = 7 };
  enum : int32_t { TRANSPORT_USB = 8 };
  static const int32_t version = 9;
  static inline const std::string hash = "882638dc86e8afd0924ecf7c28db6cce572f7e7d";
  static constexpr uint32_t TRANSACTION_isAlive = FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_registerEventListener = FIRST_CALL_TRANSACTION + 1;
  static constexpr uint32_t TRANSACTION_setResolverConfiguration = FIRST_CALL_TRANSACTION + 2;
  static constexpr uint32_t TRANSACTION_getResolverInfo = FIRST_CALL_TRANSACTION + 3;
  static constexpr uint32_t TRANSACTION_startPrefix64Discovery = FIRST_CALL_TRANSACTION + 4;
  static constexpr uint32_t TRANSACTION_stopPrefix64Discovery = FIRST_CALL_TRANSACTION + 5;
  static constexpr uint32_t TRANSACTION_getPrefix64 = FIRST_CALL_TRANSACTION + 6;
  static constexpr uint32_t TRANSACTION_createNetworkCache = FIRST_CALL_TRANSACTION + 7;
  static constexpr uint32_t TRANSACTION_destroyNetworkCache = FIRST_CALL_TRANSACTION + 8;
  static constexpr uint32_t TRANSACTION_setLogSeverity = FIRST_CALL_TRANSACTION + 9;
  static constexpr uint32_t TRANSACTION_flushNetworkCache = FIRST_CALL_TRANSACTION + 10;
  static constexpr uint32_t TRANSACTION_setPrefix64 = FIRST_CALL_TRANSACTION + 11;
  static constexpr uint32_t TRANSACTION_registerUnsolicitedEventListener = FIRST_CALL_TRANSACTION + 12;
  static constexpr uint32_t TRANSACTION_setResolverOptions = FIRST_CALL_TRANSACTION + 13;

  static std::shared_ptr<IDnsResolver> fromBinder(const ::ndk::SpAIBinder& binder);
  static binder_status_t writeToParcel(AParcel* parcel, const std::shared_ptr<IDnsResolver>& instance);
  static binder_status_t readFromParcel(const AParcel* parcel, std::shared_ptr<IDnsResolver>* instance);
  static bool setDefaultImpl(const std::shared_ptr<IDnsResolver>& impl);
  static const std::shared_ptr<IDnsResolver>& getDefaultImpl();
  virtual ::ndk::ScopedAStatus isAlive(bool* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus registerEventListener(const std::shared_ptr<::aidl::android::net::metrics::INetdEventListener>& in_listener) = 0;
  virtual ::ndk::ScopedAStatus setResolverConfiguration(const ::aidl::android::net::ResolverParamsParcel& in_resolverParams) = 0;
  virtual ::ndk::ScopedAStatus getResolverInfo(int32_t in_netId, std::vector<std::string>* out_servers, std::vector<std::string>* out_domains, std::vector<std::string>* out_tlsServers, std::vector<int32_t>* out_params, std::vector<int32_t>* out_stats, std::vector<int32_t>* out_wait_for_pending_req_timeout_count) = 0;
  virtual ::ndk::ScopedAStatus startPrefix64Discovery(int32_t in_netId) = 0;
  virtual ::ndk::ScopedAStatus stopPrefix64Discovery(int32_t in_netId) = 0;
  virtual ::ndk::ScopedAStatus getPrefix64(int32_t in_netId, std::string* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus createNetworkCache(int32_t in_netId) = 0;
  virtual ::ndk::ScopedAStatus destroyNetworkCache(int32_t in_netId) = 0;
  virtual ::ndk::ScopedAStatus setLogSeverity(int32_t in_logSeverity) = 0;
  virtual ::ndk::ScopedAStatus flushNetworkCache(int32_t in_netId) = 0;
  virtual ::ndk::ScopedAStatus setPrefix64(int32_t in_netId, const std::string& in_prefix) = 0;
  virtual ::ndk::ScopedAStatus registerUnsolicitedEventListener(const std::shared_ptr<::aidl::android::net::resolv::aidl::IDnsResolverUnsolicitedEventListener>& in_listener) = 0;
  virtual ::ndk::ScopedAStatus setResolverOptions(int32_t in_netId, const ::aidl::android::net::ResolverOptionsParcel& in_optionParams) = 0;
  virtual ::ndk::ScopedAStatus getInterfaceVersion(int32_t* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus getInterfaceHash(std::string* _aidl_return) = 0;
private:
  static std::shared_ptr<IDnsResolver> default_impl;
};
class IDnsResolverDefault : public IDnsResolver {
public:
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
  ::ndk::SpAIBinder asBinder() override;
  bool isRemote() override;
};
}  // namespace net
}  // namespace android
}  // namespace aidl
