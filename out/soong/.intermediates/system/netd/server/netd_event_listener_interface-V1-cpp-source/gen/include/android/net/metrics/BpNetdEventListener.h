#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/net/metrics/INetdEventListener.h>

namespace android {

namespace net {

namespace metrics {

class BpNetdEventListener : public ::android::BpInterface<INetdEventListener> {
public:
  explicit BpNetdEventListener(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpNetdEventListener() = default;
  ::android::binder::Status onDnsEvent(int32_t netId, int32_t eventType, int32_t returnCode, int32_t latencyMs, const ::std::string& hostname, const ::std::vector<::std::string>& ipAddresses, int32_t ipAddressesCount, int32_t uid) override;
  ::android::binder::Status onPrivateDnsValidationEvent(int32_t netId, const ::android::String16& ipAddress, const ::android::String16& hostname, bool validated) override;
  ::android::binder::Status onConnectEvent(int32_t netId, int32_t error, int32_t latencyMs, const ::android::String16& ipAddr, int32_t port, int32_t uid) override;
  ::android::binder::Status onWakeupEvent(const ::android::String16& prefix, int32_t uid, int32_t ethertype, int32_t ipNextHeader, const ::std::vector<uint8_t>& dstHw, const ::android::String16& srcIp, const ::android::String16& dstIp, int32_t srcPort, int32_t dstPort, int64_t timestampNs) override;
  ::android::binder::Status onTcpSocketStatsEvent(const ::std::vector<int32_t>& networkIds, const ::std::vector<int32_t>& sentPackets, const ::std::vector<int32_t>& lostPackets, const ::std::vector<int32_t>& rttUs, const ::std::vector<int32_t>& sentAckDiffMs) override;
  ::android::binder::Status onNat64PrefixEvent(int32_t netId, bool added, const ::std::string& prefixString, int32_t prefixLength) override;
  int32_t getInterfaceVersion() override;
  std::string getInterfaceHash() override;
private:
  int32_t cached_version_ = -1;
  std::string cached_hash_ = "-1";
  std::mutex cached_hash_mutex_;
};  // class BpNetdEventListener

}  // namespace metrics

}  // namespace net

}  // namespace android
