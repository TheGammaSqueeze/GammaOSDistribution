#pragma once

#include <android/net/ResolverParamsParcel.h>
#include <android/net/metrics/INetdEventListener.h>
#include <android/net/resolv/aidl/IDnsResolverUnsolicitedEventListener.h>
#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <string>
#include <utils/String16.h>
#include <utils/StrongPointer.h>
#include <vector>

namespace android {

namespace net {

class IDnsResolver : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(DnsResolver)
  const int32_t VERSION = 7;
  const std::string HASH = "a1dc9394598357ccaa74e96f564e7f248b72bad2";
  enum  : int32_t {
    RESOLVER_PARAMS_SAMPLE_VALIDITY = 0,
    RESOLVER_PARAMS_SUCCESS_THRESHOLD = 1,
    RESOLVER_PARAMS_MIN_SAMPLES = 2,
    RESOLVER_PARAMS_MAX_SAMPLES = 3,
    RESOLVER_PARAMS_BASE_TIMEOUT_MSEC = 4,
    RESOLVER_PARAMS_RETRY_COUNT = 5,
    RESOLVER_PARAMS_COUNT = 6,
    RESOLVER_STATS_SUCCESSES = 0,
    RESOLVER_STATS_ERRORS = 1,
    RESOLVER_STATS_TIMEOUTS = 2,
    RESOLVER_STATS_INTERNAL_ERRORS = 3,
    RESOLVER_STATS_RTT_AVG = 4,
    RESOLVER_STATS_LAST_SAMPLE_TIME = 5,
    RESOLVER_STATS_USABLE = 6,
    RESOLVER_STATS_COUNT = 7,
    DNS_RESOLVER_LOG_VERBOSE = 0,
    DNS_RESOLVER_LOG_DEBUG = 1,
    DNS_RESOLVER_LOG_INFO = 2,
    DNS_RESOLVER_LOG_WARNING = 3,
    DNS_RESOLVER_LOG_ERROR = 4,
    TC_MODE_DEFAULT = 0,
    TC_MODE_UDP_TCP = 1,
    TRANSPORT_UNKNOWN = -1,
    TRANSPORT_CELLULAR = 0,
    TRANSPORT_WIFI = 1,
    TRANSPORT_BLUETOOTH = 2,
    TRANSPORT_ETHERNET = 3,
    TRANSPORT_VPN = 4,
    TRANSPORT_WIFI_AWARE = 5,
    TRANSPORT_LOWPAN = 6,
    TRANSPORT_TEST = 7,
  };
  virtual ::android::binder::Status isAlive(bool* _aidl_return) = 0;
  virtual ::android::binder::Status registerEventListener(const ::android::sp<::android::net::metrics::INetdEventListener>& listener) = 0;
  virtual ::android::binder::Status setResolverConfiguration(const ::android::net::ResolverParamsParcel& resolverParams) = 0;
  virtual ::android::binder::Status getResolverInfo(int32_t netId, ::std::vector<::std::string>* servers, ::std::vector<::std::string>* domains, ::std::vector<::std::string>* tlsServers, ::std::vector<int32_t>* params, ::std::vector<int32_t>* stats, ::std::vector<int32_t>* wait_for_pending_req_timeout_count) = 0;
  virtual ::android::binder::Status startPrefix64Discovery(int32_t netId) = 0;
  virtual ::android::binder::Status stopPrefix64Discovery(int32_t netId) = 0;
  virtual ::android::binder::Status getPrefix64(int32_t netId, ::std::string* _aidl_return) = 0;
  virtual ::android::binder::Status createNetworkCache(int32_t netId) = 0;
  virtual ::android::binder::Status destroyNetworkCache(int32_t netId) = 0;
  virtual ::android::binder::Status setLogSeverity(int32_t logSeverity) = 0;
  virtual ::android::binder::Status flushNetworkCache(int32_t netId) = 0;
  virtual ::android::binder::Status setPrefix64(int32_t netId, const ::std::string& prefix) = 0;
  virtual ::android::binder::Status registerUnsolicitedEventListener(const ::android::sp<::android::net::resolv::aidl::IDnsResolverUnsolicitedEventListener>& listener) = 0;
  virtual int32_t getInterfaceVersion() = 0;
  virtual std::string getInterfaceHash() = 0;
};  // class IDnsResolver

class IDnsResolverDefault : public IDnsResolver {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status isAlive(bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status registerEventListener(const ::android::sp<::android::net::metrics::INetdEventListener>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setResolverConfiguration(const ::android::net::ResolverParamsParcel&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getResolverInfo(int32_t, ::std::vector<::std::string>*, ::std::vector<::std::string>*, ::std::vector<::std::string>*, ::std::vector<int32_t>*, ::std::vector<int32_t>*, ::std::vector<int32_t>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status startPrefix64Discovery(int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status stopPrefix64Discovery(int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getPrefix64(int32_t, ::std::string*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status createNetworkCache(int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status destroyNetworkCache(int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setLogSeverity(int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status flushNetworkCache(int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setPrefix64(int32_t, const ::std::string&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status registerUnsolicitedEventListener(const ::android::sp<::android::net::resolv::aidl::IDnsResolverUnsolicitedEventListener>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  int32_t getInterfaceVersion() override {
    return 0;
  }
  std::string getInterfaceHash() override {
    return "";
  }
};  // class IDnsResolverDefault

}  // namespace net

}  // namespace android
