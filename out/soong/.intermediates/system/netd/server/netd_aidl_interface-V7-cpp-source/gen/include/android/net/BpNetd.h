#pragma once

#include <binder/IBinder.h>
#include <binder/IInterface.h>
#include <utils/Errors.h>
#include <android/net/INetd.h>
#include <functional>
#include <android/binder_to_string.h>

namespace android {

namespace net {

class BpNetd : public ::android::BpInterface<INetd> {
public:
  explicit BpNetd(const ::android::sp<::android::IBinder>& _aidl_impl);
  virtual ~BpNetd() = default;
  ::android::binder::Status isAlive(bool* _aidl_return) override;
  ::android::binder::Status firewallReplaceUidChain(const ::std::string& chainName, bool isAllowlist, const ::std::vector<int32_t>& uids, bool* _aidl_return) override;
  ::android::binder::Status bandwidthEnableDataSaver(bool enable, bool* _aidl_return) override;
  ::android::binder::Status networkCreatePhysical(int32_t netId, int32_t permission) override __attribute__((deprecated("use networkCreate() instead.")));
  ::android::binder::Status networkCreateVpn(int32_t netId, bool secure) override __attribute__((deprecated("use networkCreate() instead.")));
  ::android::binder::Status networkDestroy(int32_t netId) override;
  ::android::binder::Status networkAddInterface(int32_t netId, const ::std::string& iface) override;
  ::android::binder::Status networkRemoveInterface(int32_t netId, const ::std::string& iface) override;
  ::android::binder::Status networkAddUidRanges(int32_t netId, const ::std::vector<::android::net::UidRangeParcel>& uidRanges) override;
  ::android::binder::Status networkRemoveUidRanges(int32_t netId, const ::std::vector<::android::net::UidRangeParcel>& uidRanges) override;
  ::android::binder::Status networkRejectNonSecureVpn(bool add, const ::std::vector<::android::net::UidRangeParcel>& uidRanges) override;
  ::android::binder::Status socketDestroy(const ::std::vector<::android::net::UidRangeParcel>& uidRanges, const ::std::vector<int32_t>& exemptUids) override;
  ::android::binder::Status tetherApplyDnsInterfaces(bool* _aidl_return) override;
  ::android::binder::Status tetherGetStats(::std::vector<::android::net::TetherStatsParcel>* _aidl_return) override;
  ::android::binder::Status interfaceAddAddress(const ::std::string& ifName, const ::std::string& addrString, int32_t prefixLength) override;
  ::android::binder::Status interfaceDelAddress(const ::std::string& ifName, const ::std::string& addrString, int32_t prefixLength) override;
  ::android::binder::Status getProcSysNet(int32_t ipversion, int32_t which, const ::std::string& ifname, const ::std::string& parameter, ::std::string* _aidl_return) override;
  ::android::binder::Status setProcSysNet(int32_t ipversion, int32_t which, const ::std::string& ifname, const ::std::string& parameter, const ::std::string& value) override;
  ::android::binder::Status ipSecSetEncapSocketOwner(const ::android::os::ParcelFileDescriptor& socket, int32_t newUid) override;
  ::android::binder::Status ipSecAllocateSpi(int32_t transformId, const ::std::string& sourceAddress, const ::std::string& destinationAddress, int32_t spi, int32_t* _aidl_return) override;
  ::android::binder::Status ipSecAddSecurityAssociation(int32_t transformId, int32_t mode, const ::std::string& sourceAddress, const ::std::string& destinationAddress, int32_t underlyingNetId, int32_t spi, int32_t markValue, int32_t markMask, const ::std::string& authAlgo, const ::std::vector<uint8_t>& authKey, int32_t authTruncBits, const ::std::string& cryptAlgo, const ::std::vector<uint8_t>& cryptKey, int32_t cryptTruncBits, const ::std::string& aeadAlgo, const ::std::vector<uint8_t>& aeadKey, int32_t aeadIcvBits, int32_t encapType, int32_t encapLocalPort, int32_t encapRemotePort, int32_t interfaceId) override;
  ::android::binder::Status ipSecDeleteSecurityAssociation(int32_t transformId, const ::std::string& sourceAddress, const ::std::string& destinationAddress, int32_t spi, int32_t markValue, int32_t markMask, int32_t interfaceId) override;
  ::android::binder::Status ipSecApplyTransportModeTransform(const ::android::os::ParcelFileDescriptor& socket, int32_t transformId, int32_t direction, const ::std::string& sourceAddress, const ::std::string& destinationAddress, int32_t spi) override;
  ::android::binder::Status ipSecRemoveTransportModeTransform(const ::android::os::ParcelFileDescriptor& socket) override;
  ::android::binder::Status ipSecAddSecurityPolicy(int32_t transformId, int32_t selAddrFamily, int32_t direction, const ::std::string& tmplSrcAddress, const ::std::string& tmplDstAddress, int32_t spi, int32_t markValue, int32_t markMask, int32_t interfaceId) override;
  ::android::binder::Status ipSecUpdateSecurityPolicy(int32_t transformId, int32_t selAddrFamily, int32_t direction, const ::std::string& tmplSrcAddress, const ::std::string& tmplDstAddress, int32_t spi, int32_t markValue, int32_t markMask, int32_t interfaceId) override;
  ::android::binder::Status ipSecDeleteSecurityPolicy(int32_t transformId, int32_t selAddrFamily, int32_t direction, int32_t markValue, int32_t markMask, int32_t interfaceId) override;
  ::android::binder::Status ipSecAddTunnelInterface(const ::std::string& deviceName, const ::std::string& localAddress, const ::std::string& remoteAddress, int32_t iKey, int32_t oKey, int32_t interfaceId) override;
  ::android::binder::Status ipSecUpdateTunnelInterface(const ::std::string& deviceName, const ::std::string& localAddress, const ::std::string& remoteAddress, int32_t iKey, int32_t oKey, int32_t interfaceId) override;
  ::android::binder::Status ipSecRemoveTunnelInterface(const ::std::string& deviceName) override;
  ::android::binder::Status wakeupAddInterface(const ::std::string& ifName, const ::std::string& prefix, int32_t mark, int32_t mask) override;
  ::android::binder::Status wakeupDelInterface(const ::std::string& ifName, const ::std::string& prefix, int32_t mark, int32_t mask) override;
  ::android::binder::Status setIPv6AddrGenMode(const ::std::string& ifName, int32_t mode) override;
  ::android::binder::Status idletimerAddInterface(const ::std::string& ifName, int32_t timeout, const ::std::string& classLabel) override;
  ::android::binder::Status idletimerRemoveInterface(const ::std::string& ifName, int32_t timeout, const ::std::string& classLabel) override;
  ::android::binder::Status strictUidCleartextPenalty(int32_t uid, int32_t policyPenalty) override;
  ::android::binder::Status clatdStart(const ::std::string& ifName, const ::std::string& nat64Prefix, ::std::string* _aidl_return) override;
  ::android::binder::Status clatdStop(const ::std::string& ifName) override;
  ::android::binder::Status ipfwdEnabled(bool* _aidl_return) override;
  ::android::binder::Status ipfwdGetRequesterList(::std::vector<::std::string>* _aidl_return) override;
  ::android::binder::Status ipfwdEnableForwarding(const ::std::string& requester) override;
  ::android::binder::Status ipfwdDisableForwarding(const ::std::string& requester) override;
  ::android::binder::Status ipfwdAddInterfaceForward(const ::std::string& fromIface, const ::std::string& toIface) override;
  ::android::binder::Status ipfwdRemoveInterfaceForward(const ::std::string& fromIface, const ::std::string& toIface) override;
  ::android::binder::Status bandwidthSetInterfaceQuota(const ::std::string& ifName, int64_t bytes) override;
  ::android::binder::Status bandwidthRemoveInterfaceQuota(const ::std::string& ifName) override;
  ::android::binder::Status bandwidthSetInterfaceAlert(const ::std::string& ifName, int64_t bytes) override;
  ::android::binder::Status bandwidthRemoveInterfaceAlert(const ::std::string& ifName) override;
  ::android::binder::Status bandwidthSetGlobalAlert(int64_t bytes) override;
  ::android::binder::Status bandwidthAddNaughtyApp(int32_t uid) override;
  ::android::binder::Status bandwidthRemoveNaughtyApp(int32_t uid) override;
  ::android::binder::Status bandwidthAddNiceApp(int32_t uid) override;
  ::android::binder::Status bandwidthRemoveNiceApp(int32_t uid) override;
  ::android::binder::Status tetherStart(const ::std::vector<::std::string>& dhcpRanges) override;
  ::android::binder::Status tetherStop() override;
  ::android::binder::Status tetherIsEnabled(bool* _aidl_return) override;
  ::android::binder::Status tetherInterfaceAdd(const ::std::string& ifName) override;
  ::android::binder::Status tetherInterfaceRemove(const ::std::string& ifName) override;
  ::android::binder::Status tetherInterfaceList(::std::vector<::std::string>* _aidl_return) override;
  ::android::binder::Status tetherDnsSet(int32_t netId, const ::std::vector<::std::string>& dnsAddrs) override;
  ::android::binder::Status tetherDnsList(::std::vector<::std::string>* _aidl_return) override;
  ::android::binder::Status networkAddRoute(int32_t netId, const ::std::string& ifName, const ::std::string& destination, const ::std::string& nextHop) override;
  ::android::binder::Status networkRemoveRoute(int32_t netId, const ::std::string& ifName, const ::std::string& destination, const ::std::string& nextHop) override;
  ::android::binder::Status networkAddLegacyRoute(int32_t netId, const ::std::string& ifName, const ::std::string& destination, const ::std::string& nextHop, int32_t uid) override;
  ::android::binder::Status networkRemoveLegacyRoute(int32_t netId, const ::std::string& ifName, const ::std::string& destination, const ::std::string& nextHop, int32_t uid) override;
  ::android::binder::Status networkGetDefault(int32_t* _aidl_return) override;
  ::android::binder::Status networkSetDefault(int32_t netId) override;
  ::android::binder::Status networkClearDefault() override;
  ::android::binder::Status networkSetPermissionForNetwork(int32_t netId, int32_t permission) override;
  ::android::binder::Status networkSetPermissionForUser(int32_t permission, const ::std::vector<int32_t>& uids) override;
  ::android::binder::Status networkClearPermissionForUser(const ::std::vector<int32_t>& uids) override;
  ::android::binder::Status trafficSetNetPermForUids(int32_t permission, const ::std::vector<int32_t>& uids) override;
  ::android::binder::Status networkSetProtectAllow(int32_t uid) override;
  ::android::binder::Status networkSetProtectDeny(int32_t uid) override;
  ::android::binder::Status networkCanProtect(int32_t uid, bool* _aidl_return) override;
  ::android::binder::Status firewallSetFirewallType(int32_t firewalltype) override;
  ::android::binder::Status firewallSetInterfaceRule(const ::std::string& ifName, int32_t firewallRule) override;
  ::android::binder::Status firewallSetUidRule(int32_t childChain, int32_t uid, int32_t firewallRule) override;
  ::android::binder::Status firewallEnableChildChain(int32_t childChain, bool enable) override;
  ::android::binder::Status interfaceGetList(::std::vector<::std::string>* _aidl_return) override;
  ::android::binder::Status interfaceGetCfg(const ::std::string& ifName, ::android::net::InterfaceConfigurationParcel* _aidl_return) override;
  ::android::binder::Status interfaceSetCfg(const ::android::net::InterfaceConfigurationParcel& cfg) override;
  ::android::binder::Status interfaceSetIPv6PrivacyExtensions(const ::std::string& ifName, bool enable) override;
  ::android::binder::Status interfaceClearAddrs(const ::std::string& ifName) override;
  ::android::binder::Status interfaceSetEnableIPv6(const ::std::string& ifName, bool enable) override;
  ::android::binder::Status interfaceSetMtu(const ::std::string& ifName, int32_t mtu) override;
  ::android::binder::Status tetherAddForward(const ::std::string& intIface, const ::std::string& extIface) override;
  ::android::binder::Status tetherRemoveForward(const ::std::string& intIface, const ::std::string& extIface) override;
  ::android::binder::Status setTcpRWmemorySize(const ::std::string& rmemValues, const ::std::string& wmemValues) override;
  ::android::binder::Status registerUnsolicitedEventListener(const ::android::sp<::android::net::INetdUnsolicitedEventListener>& listener) override;
  ::android::binder::Status firewallAddUidInterfaceRules(const ::std::string& ifName, const ::std::vector<int32_t>& uids) override;
  ::android::binder::Status firewallRemoveUidInterfaceRules(const ::std::vector<int32_t>& uids) override;
  ::android::binder::Status trafficSwapActiveStatsMap() override;
  ::android::binder::Status getOemNetd(::android::sp<::android::IBinder>* _aidl_return) override;
  ::android::binder::Status tetherStartWithConfiguration(const ::android::net::TetherConfigParcel& config) override;
  ::android::binder::Status getFwmarkForNetwork(int32_t netId, ::android::net::MarkMaskParcel* _aidl_return) override;
  ::android::binder::Status networkAddRouteParcel(int32_t netId, const ::android::net::RouteInfoParcel& routeInfo) override;
  ::android::binder::Status networkUpdateRouteParcel(int32_t netId, const ::android::net::RouteInfoParcel& routeInfo) override;
  ::android::binder::Status networkRemoveRouteParcel(int32_t netId, const ::android::net::RouteInfoParcel& routeInfo) override;
  ::android::binder::Status tetherOffloadRuleAdd(const ::android::net::TetherOffloadRuleParcel& rule) override;
  ::android::binder::Status tetherOffloadRuleRemove(const ::android::net::TetherOffloadRuleParcel& rule) override;
  ::android::binder::Status tetherOffloadGetStats(::std::vector<::android::net::TetherStatsParcel>* _aidl_return) override;
  ::android::binder::Status tetherOffloadSetInterfaceQuota(int32_t ifIndex, int64_t quotaBytes) override;
  ::android::binder::Status tetherOffloadGetAndClearStats(int32_t ifIndex, ::android::net::TetherStatsParcel* _aidl_return) override;
  ::android::binder::Status networkCreate(const ::android::net::NativeNetworkConfig& config) override;
  ::android::binder::Status networkAddUidRangesParcel(const ::android::net::netd::aidl::NativeUidRangeConfig& uidRangesConfig) override;
  ::android::binder::Status networkRemoveUidRangesParcel(const ::android::net::netd::aidl::NativeUidRangeConfig& uidRangesConfig) override;
  int32_t getInterfaceVersion() override;
  std::string getInterfaceHash() override;
  struct TransactionLog {
    double duration_ms;
    std::string interface_name;
    std::string method_name;
    const void* proxy_address;
    const void* stub_address;
    std::vector<std::pair<std::string, std::string>> input_args;
    std::vector<std::pair<std::string, std::string>> output_args;
    std::string result;
    std::string exception_message;
    int32_t exception_code;
    int32_t transaction_error;
    int32_t service_specific_error_code;
  };
  static std::function<void(const TransactionLog&)> logFunc;
private:
  int32_t cached_version_ = -1;
  std::string cached_hash_ = "-1";
  std::mutex cached_hash_mutex_;
};  // class BpNetd

}  // namespace net

}  // namespace android
