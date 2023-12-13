#pragma once

#include "aidl/android/net/metrics/INetdEventListener.h"

#include <android/binder_ibinder.h>

namespace aidl {
namespace android {
namespace net {
namespace metrics {
class BpNetdEventListener : public ::ndk::BpCInterface<INetdEventListener> {
public:
  explicit BpNetdEventListener(const ::ndk::SpAIBinder& binder);
  virtual ~BpNetdEventListener();

  ::ndk::ScopedAStatus onDnsEvent(int32_t in_netId, int32_t in_eventType, int32_t in_returnCode, int32_t in_latencyMs, const std::string& in_hostname, const std::vector<std::string>& in_ipAddresses, int32_t in_ipAddressesCount, int32_t in_uid) override;
  ::ndk::ScopedAStatus onPrivateDnsValidationEvent(int32_t in_netId, const std::string& in_ipAddress, const std::string& in_hostname, bool in_validated) override;
  ::ndk::ScopedAStatus onConnectEvent(int32_t in_netId, int32_t in_error, int32_t in_latencyMs, const std::string& in_ipAddr, int32_t in_port, int32_t in_uid) override;
  ::ndk::ScopedAStatus onWakeupEvent(const std::string& in_prefix, int32_t in_uid, int32_t in_ethertype, int32_t in_ipNextHeader, const std::vector<uint8_t>& in_dstHw, const std::string& in_srcIp, const std::string& in_dstIp, int32_t in_srcPort, int32_t in_dstPort, int64_t in_timestampNs) override;
  ::ndk::ScopedAStatus onTcpSocketStatsEvent(const std::vector<int32_t>& in_networkIds, const std::vector<int32_t>& in_sentPackets, const std::vector<int32_t>& in_lostPackets, const std::vector<int32_t>& in_rttUs, const std::vector<int32_t>& in_sentAckDiffMs) override;
  ::ndk::ScopedAStatus onNat64PrefixEvent(int32_t in_netId, bool in_added, const std::string& in_prefixString, int32_t in_prefixLength) override;
  ::ndk::ScopedAStatus getInterfaceVersion(int32_t* _aidl_return) override;
  ::ndk::ScopedAStatus getInterfaceHash(std::string* _aidl_return) override;
  int32_t _aidl_cached_version = -1;
  std::string _aidl_cached_hash = "-1";
  std::mutex _aidl_cached_hash_mutex;
};
}  // namespace metrics
}  // namespace net
}  // namespace android
}  // namespace aidl
