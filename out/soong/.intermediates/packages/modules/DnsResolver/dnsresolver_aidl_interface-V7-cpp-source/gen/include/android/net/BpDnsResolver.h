#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/net/IDnsResolver.h>

namespace android {

namespace net {

class BpDnsResolver : public ::android::BpInterface<IDnsResolver> {
public:
  explicit BpDnsResolver(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpDnsResolver() = default;
  ::android::binder::Status isAlive(bool* _aidl_return) override;
  ::android::binder::Status registerEventListener(const ::android::sp<::android::net::metrics::INetdEventListener>& listener) override;
  ::android::binder::Status setResolverConfiguration(const ::android::net::ResolverParamsParcel& resolverParams) override;
  ::android::binder::Status getResolverInfo(int32_t netId, ::std::vector<::std::string>* servers, ::std::vector<::std::string>* domains, ::std::vector<::std::string>* tlsServers, ::std::vector<int32_t>* params, ::std::vector<int32_t>* stats, ::std::vector<int32_t>* wait_for_pending_req_timeout_count) override;
  ::android::binder::Status startPrefix64Discovery(int32_t netId) override;
  ::android::binder::Status stopPrefix64Discovery(int32_t netId) override;
  ::android::binder::Status getPrefix64(int32_t netId, ::std::string* _aidl_return) override;
  ::android::binder::Status createNetworkCache(int32_t netId) override;
  ::android::binder::Status destroyNetworkCache(int32_t netId) override;
  ::android::binder::Status setLogSeverity(int32_t logSeverity) override;
  ::android::binder::Status flushNetworkCache(int32_t netId) override;
  ::android::binder::Status setPrefix64(int32_t netId, const ::std::string& prefix) override;
  ::android::binder::Status registerUnsolicitedEventListener(const ::android::sp<::android::net::resolv::aidl::IDnsResolverUnsolicitedEventListener>& listener) override;
  int32_t getInterfaceVersion() override;
  std::string getInterfaceHash() override;
private:
  int32_t cached_version_ = -1;
  std::string cached_hash_ = "-1";
  std::mutex cached_hash_mutex_;
};  // class BpDnsResolver

}  // namespace net

}  // namespace android
