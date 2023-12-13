#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/net/resolv/aidl/IDnsResolverUnsolicitedEventListener.h>

namespace android {

namespace net {

namespace resolv {

namespace aidl {

class BpDnsResolverUnsolicitedEventListener : public ::android::BpInterface<IDnsResolverUnsolicitedEventListener> {
public:
  explicit BpDnsResolverUnsolicitedEventListener(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpDnsResolverUnsolicitedEventListener() = default;
  ::android::binder::Status onDnsHealthEvent(const ::android::net::resolv::aidl::DnsHealthEventParcel& dnsHealthEvent) override;
  ::android::binder::Status onNat64PrefixEvent(const ::android::net::resolv::aidl::Nat64PrefixEventParcel& nat64PrefixEvent) override;
  ::android::binder::Status onPrivateDnsValidationEvent(const ::android::net::resolv::aidl::PrivateDnsValidationEventParcel& privateDnsValidationEvent) override;
  int32_t getInterfaceVersion() override;
  std::string getInterfaceHash() override;
private:
  int32_t cached_version_ = -1;
  std::string cached_hash_ = "-1";
  std::mutex cached_hash_mutex_;
};  // class BpDnsResolverUnsolicitedEventListener

}  // namespace aidl

}  // namespace resolv

}  // namespace net

}  // namespace android
