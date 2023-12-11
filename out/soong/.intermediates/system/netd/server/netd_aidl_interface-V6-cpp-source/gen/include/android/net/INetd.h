#pragma once

#include <android/net/INetdUnsolicitedEventListener.h>
#include <android/net/InterfaceConfigurationParcel.h>
#include <android/net/MarkMaskParcel.h>
#include <android/net/NativeNetworkConfig.h>
#include <android/net/RouteInfoParcel.h>
#include <android/net/TetherConfigParcel.h>
#include <android/net/TetherOffloadRuleParcel.h>
#include <android/net/TetherStatsParcel.h>
#include <android/net/UidRangeParcel.h>
#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <binder/ParcelFileDescriptor.h>
#include <binder/Status.h>
#include <cstdint>
#include <string>
#include <utils/String16.h>
#include <utils/StrongPointer.h>
#include <vector>

namespace android {

namespace net {

class INetd : public ::android::IInterface {
public:
  DECLARE_META_INTERFACE(Netd)
  const int32_t VERSION = 6;
  const std::string HASH = "b08451d9673b09cba84f1fd8740e1fdac64ff7be";
  enum  : int32_t {
    IPV4 = 4,
    IPV6 = 6,
    CONF = 1,
    NEIGH = 2,
    IPV6_ADDR_GEN_MODE_EUI64 = 0,
    IPV6_ADDR_GEN_MODE_NONE = 1,
    IPV6_ADDR_GEN_MODE_STABLE_PRIVACY = 2,
    IPV6_ADDR_GEN_MODE_RANDOM = 3,
    IPV6_ADDR_GEN_MODE_DEFAULT = 0,
    PENALTY_POLICY_ACCEPT = 1,
    PENALTY_POLICY_LOG = 2,
    PENALTY_POLICY_REJECT = 3,
    LOCAL_NET_ID = 99,
    DUMMY_NET_ID = 51,
    UNREACHABLE_NET_ID = 52,
    PERMISSION_NONE = 0,
    PERMISSION_NETWORK = 1,
    PERMISSION_SYSTEM = 2,
    NO_PERMISSIONS = 0,
    PERMISSION_INTERNET = 4,
    PERMISSION_UPDATE_DEVICE_STATS = 8,
    PERMISSION_UNINSTALLED = -1,
    FIREWALL_WHITELIST __attribute__((deprecated("use FIREWALL_ALLOWLIST."))) = 0,
    FIREWALL_ALLOWLIST = 0,
    FIREWALL_BLACKLIST __attribute__((deprecated("use FIREWALL_DENYLIST."))) = 1,
    FIREWALL_DENYLIST = 1,
    FIREWALL_RULE_ALLOW = 1,
    FIREWALL_RULE_DENY = 2,
    FIREWALL_CHAIN_NONE = 0,
    FIREWALL_CHAIN_DOZABLE = 1,
    FIREWALL_CHAIN_STANDBY = 2,
    FIREWALL_CHAIN_POWERSAVE = 3,
    FIREWALL_CHAIN_RESTRICTED = 4,
  };
  static const ::android::String16& IPSEC_INTERFACE_PREFIX();
  static const ::android::String16& NEXTHOP_NONE();
  static const ::android::String16& NEXTHOP_UNREACHABLE();
  static const ::android::String16& NEXTHOP_THROW();
  static const ::android::String16& IF_STATE_UP();
  static const ::android::String16& IF_STATE_DOWN();
  static const ::android::String16& IF_FLAG_BROADCAST();
  static const ::android::String16& IF_FLAG_LOOPBACK();
  static const ::android::String16& IF_FLAG_POINTOPOINT();
  static const ::android::String16& IF_FLAG_RUNNING();
  static const ::android::String16& IF_FLAG_MULTICAST();
  virtual ::android::binder::Status isAlive(bool* _aidl_return) = 0;
  virtual ::android::binder::Status firewallReplaceUidChain(const ::std::string& chainName, bool isAllowlist, const ::std::vector<int32_t>& uids, bool* _aidl_return) = 0;
  virtual ::android::binder::Status bandwidthEnableDataSaver(bool enable, bool* _aidl_return) = 0;
  virtual ::android::binder::Status networkCreatePhysical(int32_t netId, int32_t permission) __attribute__((deprecated("use networkCreate() instead."))) = 0;
  virtual ::android::binder::Status networkCreateVpn(int32_t netId, bool secure) __attribute__((deprecated("use networkCreate() instead."))) = 0;
  virtual ::android::binder::Status networkDestroy(int32_t netId) = 0;
  virtual ::android::binder::Status networkAddInterface(int32_t netId, const ::std::string& iface) = 0;
  virtual ::android::binder::Status networkRemoveInterface(int32_t netId, const ::std::string& iface) = 0;
  virtual ::android::binder::Status networkAddUidRanges(int32_t netId, const ::std::vector<::android::net::UidRangeParcel>& uidRanges) = 0;
  virtual ::android::binder::Status networkRemoveUidRanges(int32_t netId, const ::std::vector<::android::net::UidRangeParcel>& uidRanges) = 0;
  virtual ::android::binder::Status networkRejectNonSecureVpn(bool add, const ::std::vector<::android::net::UidRangeParcel>& uidRanges) = 0;
  virtual ::android::binder::Status socketDestroy(const ::std::vector<::android::net::UidRangeParcel>& uidRanges, const ::std::vector<int32_t>& exemptUids) = 0;
  virtual ::android::binder::Status tetherApplyDnsInterfaces(bool* _aidl_return) = 0;
  virtual ::android::binder::Status tetherGetStats(::std::vector<::android::net::TetherStatsParcel>* _aidl_return) = 0;
  virtual ::android::binder::Status interfaceAddAddress(const ::std::string& ifName, const ::std::string& addrString, int32_t prefixLength) = 0;
  virtual ::android::binder::Status interfaceDelAddress(const ::std::string& ifName, const ::std::string& addrString, int32_t prefixLength) = 0;
  virtual ::android::binder::Status getProcSysNet(int32_t ipversion, int32_t which, const ::std::string& ifname, const ::std::string& parameter, ::std::string* _aidl_return) = 0;
  virtual ::android::binder::Status setProcSysNet(int32_t ipversion, int32_t which, const ::std::string& ifname, const ::std::string& parameter, const ::std::string& value) = 0;
  virtual ::android::binder::Status ipSecSetEncapSocketOwner(const ::android::os::ParcelFileDescriptor& socket, int32_t newUid) = 0;
  virtual ::android::binder::Status ipSecAllocateSpi(int32_t transformId, const ::std::string& sourceAddress, const ::std::string& destinationAddress, int32_t spi, int32_t* _aidl_return) = 0;
  virtual ::android::binder::Status ipSecAddSecurityAssociation(int32_t transformId, int32_t mode, const ::std::string& sourceAddress, const ::std::string& destinationAddress, int32_t underlyingNetId, int32_t spi, int32_t markValue, int32_t markMask, const ::std::string& authAlgo, const ::std::vector<uint8_t>& authKey, int32_t authTruncBits, const ::std::string& cryptAlgo, const ::std::vector<uint8_t>& cryptKey, int32_t cryptTruncBits, const ::std::string& aeadAlgo, const ::std::vector<uint8_t>& aeadKey, int32_t aeadIcvBits, int32_t encapType, int32_t encapLocalPort, int32_t encapRemotePort, int32_t interfaceId) = 0;
  virtual ::android::binder::Status ipSecDeleteSecurityAssociation(int32_t transformId, const ::std::string& sourceAddress, const ::std::string& destinationAddress, int32_t spi, int32_t markValue, int32_t markMask, int32_t interfaceId) = 0;
  virtual ::android::binder::Status ipSecApplyTransportModeTransform(const ::android::os::ParcelFileDescriptor& socket, int32_t transformId, int32_t direction, const ::std::string& sourceAddress, const ::std::string& destinationAddress, int32_t spi) = 0;
  virtual ::android::binder::Status ipSecRemoveTransportModeTransform(const ::android::os::ParcelFileDescriptor& socket) = 0;
  virtual ::android::binder::Status ipSecAddSecurityPolicy(int32_t transformId, int32_t selAddrFamily, int32_t direction, const ::std::string& tmplSrcAddress, const ::std::string& tmplDstAddress, int32_t spi, int32_t markValue, int32_t markMask, int32_t interfaceId) = 0;
  virtual ::android::binder::Status ipSecUpdateSecurityPolicy(int32_t transformId, int32_t selAddrFamily, int32_t direction, const ::std::string& tmplSrcAddress, const ::std::string& tmplDstAddress, int32_t spi, int32_t markValue, int32_t markMask, int32_t interfaceId) = 0;
  virtual ::android::binder::Status ipSecDeleteSecurityPolicy(int32_t transformId, int32_t selAddrFamily, int32_t direction, int32_t markValue, int32_t markMask, int32_t interfaceId) = 0;
  virtual ::android::binder::Status ipSecAddTunnelInterface(const ::std::string& deviceName, const ::std::string& localAddress, const ::std::string& remoteAddress, int32_t iKey, int32_t oKey, int32_t interfaceId) = 0;
  virtual ::android::binder::Status ipSecUpdateTunnelInterface(const ::std::string& deviceName, const ::std::string& localAddress, const ::std::string& remoteAddress, int32_t iKey, int32_t oKey, int32_t interfaceId) = 0;
  virtual ::android::binder::Status ipSecRemoveTunnelInterface(const ::std::string& deviceName) = 0;
  virtual ::android::binder::Status wakeupAddInterface(const ::std::string& ifName, const ::std::string& prefix, int32_t mark, int32_t mask) = 0;
  virtual ::android::binder::Status wakeupDelInterface(const ::std::string& ifName, const ::std::string& prefix, int32_t mark, int32_t mask) = 0;
  virtual ::android::binder::Status setIPv6AddrGenMode(const ::std::string& ifName, int32_t mode) = 0;
  virtual ::android::binder::Status idletimerAddInterface(const ::std::string& ifName, int32_t timeout, const ::std::string& classLabel) = 0;
  virtual ::android::binder::Status idletimerRemoveInterface(const ::std::string& ifName, int32_t timeout, const ::std::string& classLabel) = 0;
  virtual ::android::binder::Status strictUidCleartextPenalty(int32_t uid, int32_t policyPenalty) = 0;
  virtual ::android::binder::Status clatdStart(const ::std::string& ifName, const ::std::string& nat64Prefix, ::std::string* _aidl_return) = 0;
  virtual ::android::binder::Status clatdStop(const ::std::string& ifName) = 0;
  virtual ::android::binder::Status ipfwdEnabled(bool* _aidl_return) = 0;
  virtual ::android::binder::Status ipfwdGetRequesterList(::std::vector<::std::string>* _aidl_return) = 0;
  virtual ::android::binder::Status ipfwdEnableForwarding(const ::std::string& requester) = 0;
  virtual ::android::binder::Status ipfwdDisableForwarding(const ::std::string& requester) = 0;
  virtual ::android::binder::Status ipfwdAddInterfaceForward(const ::std::string& fromIface, const ::std::string& toIface) = 0;
  virtual ::android::binder::Status ipfwdRemoveInterfaceForward(const ::std::string& fromIface, const ::std::string& toIface) = 0;
  virtual ::android::binder::Status bandwidthSetInterfaceQuota(const ::std::string& ifName, int64_t bytes) = 0;
  virtual ::android::binder::Status bandwidthRemoveInterfaceQuota(const ::std::string& ifName) = 0;
  virtual ::android::binder::Status bandwidthSetInterfaceAlert(const ::std::string& ifName, int64_t bytes) = 0;
  virtual ::android::binder::Status bandwidthRemoveInterfaceAlert(const ::std::string& ifName) = 0;
  virtual ::android::binder::Status bandwidthSetGlobalAlert(int64_t bytes) = 0;
  virtual ::android::binder::Status bandwidthAddNaughtyApp(int32_t uid) = 0;
  virtual ::android::binder::Status bandwidthRemoveNaughtyApp(int32_t uid) = 0;
  virtual ::android::binder::Status bandwidthAddNiceApp(int32_t uid) = 0;
  virtual ::android::binder::Status bandwidthRemoveNiceApp(int32_t uid) = 0;
  virtual ::android::binder::Status tetherStart(const ::std::vector<::std::string>& dhcpRanges) = 0;
  virtual ::android::binder::Status tetherStop() = 0;
  virtual ::android::binder::Status tetherIsEnabled(bool* _aidl_return) = 0;
  virtual ::android::binder::Status tetherInterfaceAdd(const ::std::string& ifName) = 0;
  virtual ::android::binder::Status tetherInterfaceRemove(const ::std::string& ifName) = 0;
  virtual ::android::binder::Status tetherInterfaceList(::std::vector<::std::string>* _aidl_return) = 0;
  virtual ::android::binder::Status tetherDnsSet(int32_t netId, const ::std::vector<::std::string>& dnsAddrs) = 0;
  virtual ::android::binder::Status tetherDnsList(::std::vector<::std::string>* _aidl_return) = 0;
  virtual ::android::binder::Status networkAddRoute(int32_t netId, const ::std::string& ifName, const ::std::string& destination, const ::std::string& nextHop) = 0;
  virtual ::android::binder::Status networkRemoveRoute(int32_t netId, const ::std::string& ifName, const ::std::string& destination, const ::std::string& nextHop) = 0;
  virtual ::android::binder::Status networkAddLegacyRoute(int32_t netId, const ::std::string& ifName, const ::std::string& destination, const ::std::string& nextHop, int32_t uid) = 0;
  virtual ::android::binder::Status networkRemoveLegacyRoute(int32_t netId, const ::std::string& ifName, const ::std::string& destination, const ::std::string& nextHop, int32_t uid) = 0;
  virtual ::android::binder::Status networkGetDefault(int32_t* _aidl_return) = 0;
  virtual ::android::binder::Status networkSetDefault(int32_t netId) = 0;
  virtual ::android::binder::Status networkClearDefault() = 0;
  virtual ::android::binder::Status networkSetPermissionForNetwork(int32_t netId, int32_t permission) = 0;
  virtual ::android::binder::Status networkSetPermissionForUser(int32_t permission, const ::std::vector<int32_t>& uids) = 0;
  virtual ::android::binder::Status networkClearPermissionForUser(const ::std::vector<int32_t>& uids) = 0;
  virtual ::android::binder::Status trafficSetNetPermForUids(int32_t permission, const ::std::vector<int32_t>& uids) = 0;
  virtual ::android::binder::Status networkSetProtectAllow(int32_t uid) = 0;
  virtual ::android::binder::Status networkSetProtectDeny(int32_t uid) = 0;
  virtual ::android::binder::Status networkCanProtect(int32_t uid, bool* _aidl_return) = 0;
  virtual ::android::binder::Status firewallSetFirewallType(int32_t firewalltype) = 0;
  virtual ::android::binder::Status firewallSetInterfaceRule(const ::std::string& ifName, int32_t firewallRule) = 0;
  virtual ::android::binder::Status firewallSetUidRule(int32_t childChain, int32_t uid, int32_t firewallRule) = 0;
  virtual ::android::binder::Status firewallEnableChildChain(int32_t childChain, bool enable) = 0;
  virtual ::android::binder::Status interfaceGetList(::std::vector<::std::string>* _aidl_return) = 0;
  virtual ::android::binder::Status interfaceGetCfg(const ::std::string& ifName, ::android::net::InterfaceConfigurationParcel* _aidl_return) = 0;
  virtual ::android::binder::Status interfaceSetCfg(const ::android::net::InterfaceConfigurationParcel& cfg) = 0;
  virtual ::android::binder::Status interfaceSetIPv6PrivacyExtensions(const ::std::string& ifName, bool enable) = 0;
  virtual ::android::binder::Status interfaceClearAddrs(const ::std::string& ifName) = 0;
  virtual ::android::binder::Status interfaceSetEnableIPv6(const ::std::string& ifName, bool enable) = 0;
  virtual ::android::binder::Status interfaceSetMtu(const ::std::string& ifName, int32_t mtu) = 0;
  virtual ::android::binder::Status tetherAddForward(const ::std::string& intIface, const ::std::string& extIface) = 0;
  virtual ::android::binder::Status tetherRemoveForward(const ::std::string& intIface, const ::std::string& extIface) = 0;
  virtual ::android::binder::Status setTcpRWmemorySize(const ::std::string& rmemValues, const ::std::string& wmemValues) = 0;
  virtual ::android::binder::Status registerUnsolicitedEventListener(const ::android::sp<::android::net::INetdUnsolicitedEventListener>& listener) = 0;
  virtual ::android::binder::Status firewallAddUidInterfaceRules(const ::std::string& ifName, const ::std::vector<int32_t>& uids) = 0;
  virtual ::android::binder::Status firewallRemoveUidInterfaceRules(const ::std::vector<int32_t>& uids) = 0;
  virtual ::android::binder::Status trafficSwapActiveStatsMap() = 0;
  virtual ::android::binder::Status getOemNetd(::android::sp<::android::IBinder>* _aidl_return) = 0;
  virtual ::android::binder::Status tetherStartWithConfiguration(const ::android::net::TetherConfigParcel& config) = 0;
  virtual ::android::binder::Status getFwmarkForNetwork(int32_t netId, ::android::net::MarkMaskParcel* _aidl_return) = 0;
  virtual ::android::binder::Status networkAddRouteParcel(int32_t netId, const ::android::net::RouteInfoParcel& routeInfo) = 0;
  virtual ::android::binder::Status networkUpdateRouteParcel(int32_t netId, const ::android::net::RouteInfoParcel& routeInfo) = 0;
  virtual ::android::binder::Status networkRemoveRouteParcel(int32_t netId, const ::android::net::RouteInfoParcel& routeInfo) = 0;
  virtual ::android::binder::Status tetherOffloadRuleAdd(const ::android::net::TetherOffloadRuleParcel& rule) = 0;
  virtual ::android::binder::Status tetherOffloadRuleRemove(const ::android::net::TetherOffloadRuleParcel& rule) = 0;
  virtual ::android::binder::Status tetherOffloadGetStats(::std::vector<::android::net::TetherStatsParcel>* _aidl_return) = 0;
  virtual ::android::binder::Status tetherOffloadSetInterfaceQuota(int32_t ifIndex, int64_t quotaBytes) = 0;
  virtual ::android::binder::Status tetherOffloadGetAndClearStats(int32_t ifIndex, ::android::net::TetherStatsParcel* _aidl_return) = 0;
  virtual ::android::binder::Status networkCreate(const ::android::net::NativeNetworkConfig& config) = 0;
  virtual int32_t getInterfaceVersion() = 0;
  virtual std::string getInterfaceHash() = 0;
};  // class INetd

class INetdDefault : public INetd {
public:
  ::android::IBinder* onAsBinder() override {
    return nullptr;
  }
  ::android::binder::Status isAlive(bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status firewallReplaceUidChain(const ::std::string&, bool, const ::std::vector<int32_t>&, bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status bandwidthEnableDataSaver(bool, bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status networkCreatePhysical(int32_t, int32_t) override __attribute__((deprecated("use networkCreate() instead."))) {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status networkCreateVpn(int32_t, bool) override __attribute__((deprecated("use networkCreate() instead."))) {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status networkDestroy(int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status networkAddInterface(int32_t, const ::std::string&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status networkRemoveInterface(int32_t, const ::std::string&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status networkAddUidRanges(int32_t, const ::std::vector<::android::net::UidRangeParcel>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status networkRemoveUidRanges(int32_t, const ::std::vector<::android::net::UidRangeParcel>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status networkRejectNonSecureVpn(bool, const ::std::vector<::android::net::UidRangeParcel>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status socketDestroy(const ::std::vector<::android::net::UidRangeParcel>&, const ::std::vector<int32_t>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status tetherApplyDnsInterfaces(bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status tetherGetStats(::std::vector<::android::net::TetherStatsParcel>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status interfaceAddAddress(const ::std::string&, const ::std::string&, int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status interfaceDelAddress(const ::std::string&, const ::std::string&, int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getProcSysNet(int32_t, int32_t, const ::std::string&, const ::std::string&, ::std::string*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setProcSysNet(int32_t, int32_t, const ::std::string&, const ::std::string&, const ::std::string&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status ipSecSetEncapSocketOwner(const ::android::os::ParcelFileDescriptor&, int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status ipSecAllocateSpi(int32_t, const ::std::string&, const ::std::string&, int32_t, int32_t*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status ipSecAddSecurityAssociation(int32_t, int32_t, const ::std::string&, const ::std::string&, int32_t, int32_t, int32_t, int32_t, const ::std::string&, const ::std::vector<uint8_t>&, int32_t, const ::std::string&, const ::std::vector<uint8_t>&, int32_t, const ::std::string&, const ::std::vector<uint8_t>&, int32_t, int32_t, int32_t, int32_t, int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status ipSecDeleteSecurityAssociation(int32_t, const ::std::string&, const ::std::string&, int32_t, int32_t, int32_t, int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status ipSecApplyTransportModeTransform(const ::android::os::ParcelFileDescriptor&, int32_t, int32_t, const ::std::string&, const ::std::string&, int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status ipSecRemoveTransportModeTransform(const ::android::os::ParcelFileDescriptor&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status ipSecAddSecurityPolicy(int32_t, int32_t, int32_t, const ::std::string&, const ::std::string&, int32_t, int32_t, int32_t, int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status ipSecUpdateSecurityPolicy(int32_t, int32_t, int32_t, const ::std::string&, const ::std::string&, int32_t, int32_t, int32_t, int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status ipSecDeleteSecurityPolicy(int32_t, int32_t, int32_t, int32_t, int32_t, int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status ipSecAddTunnelInterface(const ::std::string&, const ::std::string&, const ::std::string&, int32_t, int32_t, int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status ipSecUpdateTunnelInterface(const ::std::string&, const ::std::string&, const ::std::string&, int32_t, int32_t, int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status ipSecRemoveTunnelInterface(const ::std::string&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status wakeupAddInterface(const ::std::string&, const ::std::string&, int32_t, int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status wakeupDelInterface(const ::std::string&, const ::std::string&, int32_t, int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setIPv6AddrGenMode(const ::std::string&, int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status idletimerAddInterface(const ::std::string&, int32_t, const ::std::string&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status idletimerRemoveInterface(const ::std::string&, int32_t, const ::std::string&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status strictUidCleartextPenalty(int32_t, int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status clatdStart(const ::std::string&, const ::std::string&, ::std::string*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status clatdStop(const ::std::string&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status ipfwdEnabled(bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status ipfwdGetRequesterList(::std::vector<::std::string>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status ipfwdEnableForwarding(const ::std::string&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status ipfwdDisableForwarding(const ::std::string&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status ipfwdAddInterfaceForward(const ::std::string&, const ::std::string&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status ipfwdRemoveInterfaceForward(const ::std::string&, const ::std::string&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status bandwidthSetInterfaceQuota(const ::std::string&, int64_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status bandwidthRemoveInterfaceQuota(const ::std::string&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status bandwidthSetInterfaceAlert(const ::std::string&, int64_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status bandwidthRemoveInterfaceAlert(const ::std::string&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status bandwidthSetGlobalAlert(int64_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status bandwidthAddNaughtyApp(int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status bandwidthRemoveNaughtyApp(int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status bandwidthAddNiceApp(int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status bandwidthRemoveNiceApp(int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status tetherStart(const ::std::vector<::std::string>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status tetherStop() override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status tetherIsEnabled(bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status tetherInterfaceAdd(const ::std::string&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status tetherInterfaceRemove(const ::std::string&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status tetherInterfaceList(::std::vector<::std::string>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status tetherDnsSet(int32_t, const ::std::vector<::std::string>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status tetherDnsList(::std::vector<::std::string>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status networkAddRoute(int32_t, const ::std::string&, const ::std::string&, const ::std::string&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status networkRemoveRoute(int32_t, const ::std::string&, const ::std::string&, const ::std::string&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status networkAddLegacyRoute(int32_t, const ::std::string&, const ::std::string&, const ::std::string&, int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status networkRemoveLegacyRoute(int32_t, const ::std::string&, const ::std::string&, const ::std::string&, int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status networkGetDefault(int32_t*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status networkSetDefault(int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status networkClearDefault() override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status networkSetPermissionForNetwork(int32_t, int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status networkSetPermissionForUser(int32_t, const ::std::vector<int32_t>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status networkClearPermissionForUser(const ::std::vector<int32_t>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status trafficSetNetPermForUids(int32_t, const ::std::vector<int32_t>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status networkSetProtectAllow(int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status networkSetProtectDeny(int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status networkCanProtect(int32_t, bool*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status firewallSetFirewallType(int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status firewallSetInterfaceRule(const ::std::string&, int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status firewallSetUidRule(int32_t, int32_t, int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status firewallEnableChildChain(int32_t, bool) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status interfaceGetList(::std::vector<::std::string>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status interfaceGetCfg(const ::std::string&, ::android::net::InterfaceConfigurationParcel*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status interfaceSetCfg(const ::android::net::InterfaceConfigurationParcel&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status interfaceSetIPv6PrivacyExtensions(const ::std::string&, bool) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status interfaceClearAddrs(const ::std::string&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status interfaceSetEnableIPv6(const ::std::string&, bool) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status interfaceSetMtu(const ::std::string&, int32_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status tetherAddForward(const ::std::string&, const ::std::string&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status tetherRemoveForward(const ::std::string&, const ::std::string&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status setTcpRWmemorySize(const ::std::string&, const ::std::string&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status registerUnsolicitedEventListener(const ::android::sp<::android::net::INetdUnsolicitedEventListener>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status firewallAddUidInterfaceRules(const ::std::string&, const ::std::vector<int32_t>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status firewallRemoveUidInterfaceRules(const ::std::vector<int32_t>&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status trafficSwapActiveStatsMap() override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getOemNetd(::android::sp<::android::IBinder>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status tetherStartWithConfiguration(const ::android::net::TetherConfigParcel&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status getFwmarkForNetwork(int32_t, ::android::net::MarkMaskParcel*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status networkAddRouteParcel(int32_t, const ::android::net::RouteInfoParcel&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status networkUpdateRouteParcel(int32_t, const ::android::net::RouteInfoParcel&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status networkRemoveRouteParcel(int32_t, const ::android::net::RouteInfoParcel&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status tetherOffloadRuleAdd(const ::android::net::TetherOffloadRuleParcel&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status tetherOffloadRuleRemove(const ::android::net::TetherOffloadRuleParcel&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status tetherOffloadGetStats(::std::vector<::android::net::TetherStatsParcel>*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status tetherOffloadSetInterfaceQuota(int32_t, int64_t) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status tetherOffloadGetAndClearStats(int32_t, ::android::net::TetherStatsParcel*) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  ::android::binder::Status networkCreate(const ::android::net::NativeNetworkConfig&) override {
    return ::android::binder::Status::fromStatusT(::android::UNKNOWN_TRANSACTION);
  }
  int32_t getInterfaceVersion() override {
    return 0;
  }
  std::string getInterfaceHash() override {
    return "";
  }
};  // class INetdDefault

}  // namespace net

}  // namespace android
