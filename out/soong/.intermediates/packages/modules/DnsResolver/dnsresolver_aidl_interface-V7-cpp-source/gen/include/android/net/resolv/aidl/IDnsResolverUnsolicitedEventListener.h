#pragma once

#include <android/net/resolv/aidl/DnsHealthEventParcel.h>
#include <android/net/resolv/aidl/Nat64PrefixEventParcel.h>
#include <android/net/resolv/aidl/PrivateDnsValidationEventParcel.h>
#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/Status.h>
#include <cstdint>
#include <utils/String16.h>
#include <utils/StrongPointer.h>

namespace android {

namespace net {

namespace resolv {

namespace aidl {

class IDnsResolverUnsolicitedEventListener : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(DnsResolverUnsolicitedEventListener)
  const int32_t VERSION = 7;
  const std::string HASH = "a1dc9394598357ccaa74e96f564e7f248b72bad2";
  enum  : int32_t {
    DNS_HEALTH_RESULT_OK = 0,
    DNS_HEALTH_RESULT_TIMEOUT = 255,
    PREFIX_OPERATION_ADDED = 1,
    PREFIX_OPERATION_REMOVED = 2,
    VALIDATION_RESULT_SUCCESS = 1,
    VALIDATION_RESULT_FAILURE = 2,
  };
  virtual ::android::binder::Status onDnsHealthEvent(const ::android::net::resolv::aidl::DnsHealthEventParcel& dnsHealthEvent) = 0;
  virtual ::android::binder::Status onNat64PrefixEvent(const ::android::net::resolv::aidl::Nat64PrefixEventParcel& nat64PrefixEvent) = 0;
  virtual ::android::binder::Status onPrivateDnsValidationEvent(const ::android::net::resolv::aidl::PrivateDnsValidationEventParcel& privateDnsValidationEvent) = 0;
  virtual int32_t getInterfaceVersion() = 0;
  virtual std::string getInterfaceHash() = 0;
};  // class IDnsResolverUnsolicitedEventListener

class IDnsResolverUnsolicitedEventListenerDefault : public IDnsResolverUnsolicitedEventListener {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status onDnsHealthEvent(const ::android::net::resolv::aidl::DnsHealthEventParcel&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status onNat64PrefixEvent(const ::android::net::resolv::aidl::Nat64PrefixEventParcel&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status onPrivateDnsValidationEvent(const ::android::net::resolv::aidl::PrivateDnsValidationEventParcel&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  int32_t getInterfaceVersion() override {
    return 0;
  }
  std::string getInterfaceHash() override {
    return "";
  }
};  // class IDnsResolverUnsolicitedEventListenerDefault

}  // namespace aidl

}  // namespace resolv

}  // namespace net

}  // namespace android
