#pragma once

#include <android/binder_interface_utils.h>

#include <cstdint>
#include <memory>
#include <optional>
#include <string>
#include <vector>
#ifdef BINDER_STABILITY_SUPPORT
#include <android/binder_stability.h>
#endif  // BINDER_STABILITY_SUPPORT

namespace aidl {
namespace android {
namespace net {
namespace metrics {
class INetdEventListener : public ::ndk::ICInterface {
public:
  static const char* descriptor;
  INetdEventListener();
  virtual ~INetdEventListener();

  enum : int32_t { EVENT_GETADDRINFO = 1 };
  enum : int32_t { EVENT_GETHOSTBYNAME = 2 };
  enum : int32_t { EVENT_GETHOSTBYADDR = 3 };
  enum : int32_t { EVENT_RES_NSEND = 4 };
  enum : int32_t { REPORTING_LEVEL_NONE = 0 };
  enum : int32_t { REPORTING_LEVEL_METRICS = 1 };
  enum : int32_t { REPORTING_LEVEL_FULL = 2 };
  enum : int32_t { DNS_REPORTED_IP_ADDRESSES_LIMIT = 10 };
  static const int32_t version = 1;
  static inline const std::string hash = "8e27594d285ca7c567d87e8cf74766c27647e02b";
  static constexpr uint32_t TRANSACTION_onDnsEvent = FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_onPrivateDnsValidationEvent = FIRST_CALL_TRANSACTION + 1;
  static constexpr uint32_t TRANSACTION_onConnectEvent = FIRST_CALL_TRANSACTION + 2;
  static constexpr uint32_t TRANSACTION_onWakeupEvent = FIRST_CALL_TRANSACTION + 3;
  static constexpr uint32_t TRANSACTION_onTcpSocketStatsEvent = FIRST_CALL_TRANSACTION + 4;
  static constexpr uint32_t TRANSACTION_onNat64PrefixEvent = FIRST_CALL_TRANSACTION + 5;

  static std::shared_ptr<INetdEventListener> fromBinder(const ::ndk::SpAIBinder& binder);
  static binder_status_t writeToParcel(AParcel* parcel, const std::shared_ptr<INetdEventListener>& instance);
  static binder_status_t readFromParcel(const AParcel* parcel, std::shared_ptr<INetdEventListener>* instance);
  static bool setDefaultImpl(const std::shared_ptr<INetdEventListener>& impl);
  static const std::shared_ptr<INetdEventListener>& getDefaultImpl();
  virtual ::ndk::ScopedAStatus onDnsEvent(int32_t in_netId, int32_t in_eventType, int32_t in_returnCode, int32_t in_latencyMs, const std::string& in_hostname, const std::vector<std::string>& in_ipAddresses, int32_t in_ipAddressesCount, int32_t in_uid) = 0;
  virtual ::ndk::ScopedAStatus onPrivateDnsValidationEvent(int32_t in_netId, const std::string& in_ipAddress, const std::string& in_hostname, bool in_validated) = 0;
  virtual ::ndk::ScopedAStatus onConnectEvent(int32_t in_netId, int32_t in_error, int32_t in_latencyMs, const std::string& in_ipAddr, int32_t in_port, int32_t in_uid) = 0;
  virtual ::ndk::ScopedAStatus onWakeupEvent(const std::string& in_prefix, int32_t in_uid, int32_t in_ethertype, int32_t in_ipNextHeader, const std::vector<uint8_t>& in_dstHw, const std::string& in_srcIp, const std::string& in_dstIp, int32_t in_srcPort, int32_t in_dstPort, int64_t in_timestampNs) = 0;
  virtual ::ndk::ScopedAStatus onTcpSocketStatsEvent(const std::vector<int32_t>& in_networkIds, const std::vector<int32_t>& in_sentPackets, const std::vector<int32_t>& in_lostPackets, const std::vector<int32_t>& in_rttUs, const std::vector<int32_t>& in_sentAckDiffMs) = 0;
  virtual ::ndk::ScopedAStatus onNat64PrefixEvent(int32_t in_netId, bool in_added, const std::string& in_prefixString, int32_t in_prefixLength) = 0;
  virtual ::ndk::ScopedAStatus getInterfaceVersion(int32_t* _aidl_return) = 0;
  virtual ::ndk::ScopedAStatus getInterfaceHash(std::string* _aidl_return) = 0;
private:
  static std::shared_ptr<INetdEventListener> default_impl;
};
class INetdEventListenerDefault : public INetdEventListener {
public:
  ::ndk::ScopedAStatus onDnsEvent(int32_t in_netId, int32_t in_eventType, int32_t in_returnCode, int32_t in_latencyMs, const std::string& in_hostname, const std::vector<std::string>& in_ipAddresses, int32_t in_ipAddressesCount, int32_t in_uid) override;
  ::ndk::ScopedAStatus onPrivateDnsValidationEvent(int32_t in_netId, const std::string& in_ipAddress, const std::string& in_hostname, bool in_validated) override;
  ::ndk::ScopedAStatus onConnectEvent(int32_t in_netId, int32_t in_error, int32_t in_latencyMs, const std::string& in_ipAddr, int32_t in_port, int32_t in_uid) override;
  ::ndk::ScopedAStatus onWakeupEvent(const std::string& in_prefix, int32_t in_uid, int32_t in_ethertype, int32_t in_ipNextHeader, const std::vector<uint8_t>& in_dstHw, const std::string& in_srcIp, const std::string& in_dstIp, int32_t in_srcPort, int32_t in_dstPort, int64_t in_timestampNs) override;
  ::ndk::ScopedAStatus onTcpSocketStatsEvent(const std::vector<int32_t>& in_networkIds, const std::vector<int32_t>& in_sentPackets, const std::vector<int32_t>& in_lostPackets, const std::vector<int32_t>& in_rttUs, const std::vector<int32_t>& in_sentAckDiffMs) override;
  ::ndk::ScopedAStatus onNat64PrefixEvent(int32_t in_netId, bool in_added, const std::string& in_prefixString, int32_t in_prefixLength) override;
  ::ndk::ScopedAStatus getInterfaceVersion(int32_t* _aidl_return) override;
  ::ndk::ScopedAStatus getInterfaceHash(std::string* _aidl_return) override;
  ::ndk::SpAIBinder asBinder() override;
  bool isRemote() override;
};
}  // namespace metrics
}  // namespace net
}  // namespace android
}  // namespace aidl
