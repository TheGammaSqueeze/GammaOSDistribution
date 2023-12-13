#pragma once

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

namespace metrics {

class INetdEventListener : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(NetdEventListener)
  const int32_t VERSION = 1;
  const std::string HASH = "8e27594d285ca7c567d87e8cf74766c27647e02b";
  enum  : int32_t {
    EVENT_GETADDRINFO = 1,
    EVENT_GETHOSTBYNAME = 2,
    EVENT_GETHOSTBYADDR = 3,
    EVENT_RES_NSEND = 4,
    REPORTING_LEVEL_NONE = 0,
    REPORTING_LEVEL_METRICS = 1,
    REPORTING_LEVEL_FULL = 2,
    DNS_REPORTED_IP_ADDRESSES_LIMIT = 10,
  };
  virtual ::android::binder::Status onDnsEvent(int32_t netId, int32_t eventType, int32_t returnCode, int32_t latencyMs, const ::std::string& hostname, const ::std::vector<::std::string>& ipAddresses, int32_t ipAddressesCount, int32_t uid) = 0;
  virtual ::android::binder::Status onPrivateDnsValidationEvent(int32_t netId, const ::android::String16& ipAddress, const ::android::String16& hostname, bool validated) = 0;
  virtual ::android::binder::Status onConnectEvent(int32_t netId, int32_t error, int32_t latencyMs, const ::android::String16& ipAddr, int32_t port, int32_t uid) = 0;
  virtual ::android::binder::Status onWakeupEvent(const ::android::String16& prefix, int32_t uid, int32_t ethertype, int32_t ipNextHeader, const ::std::vector<uint8_t>& dstHw, const ::android::String16& srcIp, const ::android::String16& dstIp, int32_t srcPort, int32_t dstPort, int64_t timestampNs) = 0;
  virtual ::android::binder::Status onTcpSocketStatsEvent(const ::std::vector<int32_t>& networkIds, const ::std::vector<int32_t>& sentPackets, const ::std::vector<int32_t>& lostPackets, const ::std::vector<int32_t>& rttUs, const ::std::vector<int32_t>& sentAckDiffMs) = 0;
  virtual ::android::binder::Status onNat64PrefixEvent(int32_t netId, bool added, const ::std::string& prefixString, int32_t prefixLength) = 0;
  virtual int32_t getInterfaceVersion() = 0;
  virtual std::string getInterfaceHash() = 0;
};  // class INetdEventListener

class INetdEventListenerDefault : public INetdEventListener {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status onDnsEvent(int32_t, int32_t, int32_t, int32_t, const ::std::string&, const ::std::vector<::std::string>&, int32_t, int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status onPrivateDnsValidationEvent(int32_t, const ::android::String16&, const ::android::String16&, bool) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status onConnectEvent(int32_t, int32_t, int32_t, const ::android::String16&, int32_t, int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status onWakeupEvent(const ::android::String16&, int32_t, int32_t, int32_t, const ::std::vector<uint8_t>&, const ::android::String16&, const ::android::String16&, int32_t, int32_t, int64_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status onTcpSocketStatsEvent(const ::std::vector<int32_t>&, const ::std::vector<int32_t>&, const ::std::vector<int32_t>&, const ::std::vector<int32_t>&, const ::std::vector<int32_t>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status onNat64PrefixEvent(int32_t, bool, const ::std::string&, int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  int32_t getInterfaceVersion() override {
    return 0;
  }
  std::string getInterfaceHash() override {
    return "";
  }
};  // class INetdEventListenerDefault

}  // namespace metrics

}  // namespace net

}  // namespace android
