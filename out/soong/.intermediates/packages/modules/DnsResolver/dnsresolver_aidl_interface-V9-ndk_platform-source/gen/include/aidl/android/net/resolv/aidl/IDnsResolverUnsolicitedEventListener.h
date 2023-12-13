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
#include <aidl/android/net/resolv/aidl/DnsHealthEventParcel.h>
#include <aidl/android/net/resolv/aidl/Nat64PrefixEventParcel.h>
#include <aidl/android/net/resolv/aidl/PrivateDnsValidationEventParcel.h>

namespace aidl {
namespace android {
namespace net {
namespace resolv {
namespace aidl {
class IDnsResolverUnsolicitedEventListener : public ::ndk::ICInterface {
public:
  static const char* descriptor;
  IDnsResolverUnsolicitedEventListener();
  virtual ~IDnsResolverUnsolicitedEventListener();

  enum : int32_t { DNS_HEALTH_RESULT_OK = 0 };
  enum : int32_t { DNS_HEALTH_RESULT_TIMEOUT = 255 };
  enum : int32_t { PREFIX_OPERATION_ADDED = 1 };
  enum : int32_t { PREFIX_OPERATION_REMOVED = 2 };
  enum : int32_t { VALIDATION_RESULT_SUCCESS = 1 };
  enum : int32_t { VALIDATION_RESULT_FAILURE = 2 };
  static const int32_t version = 9;
  static inline const std::string hash = "882638dc86e8afd0924ecf7c28db6cce572f7e7d";
  static constexpr uint32_t TRANSACTION_onDnsHealthEvent = FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_onNat64PrefixEvent = FIRST_CALL_TRANSACTION + 1;
  static constexpr uint32_t TRANSACTION_onPrivateDnsValidationEvent = FIRST_CALL_TRANSACTION + 2;

  static std::shared_ptr<IDnsResolverUnsolicitedEventListener> fromBinder(const ::ndk::SpAIBinder& binder);
  static binder_status_t writeToParcel(AParcel* parcel, const std::shared_ptr<IDnsResolverUnsolicitedEventListener>& instance);
  static binder_status_t readFromParcel(const AParcel* parcel, std::shared_ptr<IDnsResolverUnsolicitedEventListener>* instance);
  static bool setDefaultImpl(const std::shared_ptr<IDnsResolverUnsolicitedEventListener>& impl);
  static const std::shared_ptr<IDnsResolverUnsolicitedEventListener>& getDefaultImpl();
  virtual ::ndk::ScopedAStatus onDnsHealthEvent(const ::aidl::android::net::resolv::aidl::DnsHealthEventParcel& in_dnsHealthEvent) = 0;
  virtual ::ndk::ScopedAStatus onNat64PrefixEvent(const ::aidl::android::net::resolv::aidl::Nat64PrefixEventParcel& in_nat64PrefixEvent) = 0;
  virtual ::ndk::ScopedAStatus onPrivateDnsValidationEvent(const ::aidl::android::net::resolv::aidl::PrivateDnsValidationEventParcel& in_privateDnsValidationEvent) = 0;
  virtual ::ndk::ScopedAStatus getInterfaceVersion(int32_t* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus getInterfaceHash(std::string* _aidl_return) = 0;
private:
  static std::shared_ptr<IDnsResolverUnsolicitedEventListener> default_impl;
};
class IDnsResolverUnsolicitedEventListenerDefault : public IDnsResolverUnsolicitedEventListener {
public:
  ::ndk::ScopedAStatus onDnsHealthEvent(const ::aidl::android::net::resolv::aidl::DnsHealthEventParcel& in_dnsHealthEvent) override;
  ::ndk::ScopedAStatus onNat64PrefixEvent(const ::aidl::android::net::resolv::aidl::Nat64PrefixEventParcel& in_nat64PrefixEvent) override;
  ::ndk::ScopedAStatus onPrivateDnsValidationEvent(const ::aidl::android::net::resolv::aidl::PrivateDnsValidationEventParcel& in_privateDnsValidationEvent) override;
  ::ndk::ScopedAStatus getInterfaceVersion(int32_t* _aidl_return) override;
  ::ndk::ScopedAStatus getInterfaceHash(std::string* _aidl_return) override;
  ::ndk::SpAIBinder asBinder() override;
  bool isRemote() override;
};
}  // namespace aidl
}  // namespace resolv
}  // namespace net
}  // namespace android
}  // namespace aidl
