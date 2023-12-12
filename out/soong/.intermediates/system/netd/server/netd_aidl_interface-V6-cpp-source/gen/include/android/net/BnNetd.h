#pragma once

#include <binder/IInterface.h>
#include <android/net/INetd.h>
#include <functional>
#include <android/binder_to_string.h>

namespace android {

namespace net {

class BnNetd : public ::android::BnInterface<INetd> {
public:
  static constexpr uint32_t TRANSACTION_isAlive = ::android::IBinder::FIRST_CALL_TRANSACTION + 0;
  static constexpr uint32_t TRANSACTION_firewallReplaceUidChain = ::android::IBinder::FIRST_CALL_TRANSACTION + 1;
  static constexpr uint32_t TRANSACTION_bandwidthEnableDataSaver = ::android::IBinder::FIRST_CALL_TRANSACTION + 2;
  static constexpr uint32_t TRANSACTION_networkCreatePhysical = ::android::IBinder::FIRST_CALL_TRANSACTION + 3;
  static constexpr uint32_t TRANSACTION_networkCreateVpn = ::android::IBinder::FIRST_CALL_TRANSACTION + 4;
  static constexpr uint32_t TRANSACTION_networkDestroy = ::android::IBinder::FIRST_CALL_TRANSACTION + 5;
  static constexpr uint32_t TRANSACTION_networkAddInterface = ::android::IBinder::FIRST_CALL_TRANSACTION + 6;
  static constexpr uint32_t TRANSACTION_networkRemoveInterface = ::android::IBinder::FIRST_CALL_TRANSACTION + 7;
  static constexpr uint32_t TRANSACTION_networkAddUidRanges = ::android::IBinder::FIRST_CALL_TRANSACTION + 8;
  static constexpr uint32_t TRANSACTION_networkRemoveUidRanges = ::android::IBinder::FIRST_CALL_TRANSACTION + 9;
  static constexpr uint32_t TRANSACTION_networkRejectNonSecureVpn = ::android::IBinder::FIRST_CALL_TRANSACTION + 10;
  static constexpr uint32_t TRANSACTION_socketDestroy = ::android::IBinder::FIRST_CALL_TRANSACTION + 11;
  static constexpr uint32_t TRANSACTION_tetherApplyDnsInterfaces = ::android::IBinder::FIRST_CALL_TRANSACTION + 12;
  static constexpr uint32_t TRANSACTION_tetherGetStats = ::android::IBinder::FIRST_CALL_TRANSACTION + 13;
  static constexpr uint32_t TRANSACTION_interfaceAddAddress = ::android::IBinder::FIRST_CALL_TRANSACTION + 14;
  static constexpr uint32_t TRANSACTION_interfaceDelAddress = ::android::IBinder::FIRST_CALL_TRANSACTION + 15;
  static constexpr uint32_t TRANSACTION_getProcSysNet = ::android::IBinder::FIRST_CALL_TRANSACTION + 16;
  static constexpr uint32_t TRANSACTION_setProcSysNet = ::android::IBinder::FIRST_CALL_TRANSACTION + 17;
  static constexpr uint32_t TRANSACTION_ipSecSetEncapSocketOwner = ::android::IBinder::FIRST_CALL_TRANSACTION + 18;
  static constexpr uint32_t TRANSACTION_ipSecAllocateSpi = ::android::IBinder::FIRST_CALL_TRANSACTION + 19;
  static constexpr uint32_t TRANSACTION_ipSecAddSecurityAssociation = ::android::IBinder::FIRST_CALL_TRANSACTION + 20;
  static constexpr uint32_t TRANSACTION_ipSecDeleteSecurityAssociation = ::android::IBinder::FIRST_CALL_TRANSACTION + 21;
  static constexpr uint32_t TRANSACTION_ipSecApplyTransportModeTransform = ::android::IBinder::FIRST_CALL_TRANSACTION + 22;
  static constexpr uint32_t TRANSACTION_ipSecRemoveTransportModeTransform = ::android::IBinder::FIRST_CALL_TRANSACTION + 23;
  static constexpr uint32_t TRANSACTION_ipSecAddSecurityPolicy = ::android::IBinder::FIRST_CALL_TRANSACTION + 24;
  static constexpr uint32_t TRANSACTION_ipSecUpdateSecurityPolicy = ::android::IBinder::FIRST_CALL_TRANSACTION + 25;
  static constexpr uint32_t TRANSACTION_ipSecDeleteSecurityPolicy = ::android::IBinder::FIRST_CALL_TRANSACTION + 26;
  static constexpr uint32_t TRANSACTION_ipSecAddTunnelInterface = ::android::IBinder::FIRST_CALL_TRANSACTION + 27;
  static constexpr uint32_t TRANSACTION_ipSecUpdateTunnelInterface = ::android::IBinder::FIRST_CALL_TRANSACTION + 28;
  static constexpr uint32_t TRANSACTION_ipSecRemoveTunnelInterface = ::android::IBinder::FIRST_CALL_TRANSACTION + 29;
  static constexpr uint32_t TRANSACTION_wakeupAddInterface = ::android::IBinder::FIRST_CALL_TRANSACTION + 30;
  static constexpr uint32_t TRANSACTION_wakeupDelInterface = ::android::IBinder::FIRST_CALL_TRANSACTION + 31;
  static constexpr uint32_t TRANSACTION_setIPv6AddrGenMode = ::android::IBinder::FIRST_CALL_TRANSACTION + 32;
  static constexpr uint32_t TRANSACTION_idletimerAddInterface = ::android::IBinder::FIRST_CALL_TRANSACTION + 33;
  static constexpr uint32_t TRANSACTION_idletimerRemoveInterface = ::android::IBinder::FIRST_CALL_TRANSACTION + 34;
  static constexpr uint32_t TRANSACTION_strictUidCleartextPenalty = ::android::IBinder::FIRST_CALL_TRANSACTION + 35;
  static constexpr uint32_t TRANSACTION_clatdStart = ::android::IBinder::FIRST_CALL_TRANSACTION + 36;
  static constexpr uint32_t TRANSACTION_clatdStop = ::android::IBinder::FIRST_CALL_TRANSACTION + 37;
  static constexpr uint32_t TRANSACTION_ipfwdEnabled = ::android::IBinder::FIRST_CALL_TRANSACTION + 38;
  static constexpr uint32_t TRANSACTION_ipfwdGetRequesterList = ::android::IBinder::FIRST_CALL_TRANSACTION + 39;
  static constexpr uint32_t TRANSACTION_ipfwdEnableForwarding = ::android::IBinder::FIRST_CALL_TRANSACTION + 40;
  static constexpr uint32_t TRANSACTION_ipfwdDisableForwarding = ::android::IBinder::FIRST_CALL_TRANSACTION + 41;
  static constexpr uint32_t TRANSACTION_ipfwdAddInterfaceForward = ::android::IBinder::FIRST_CALL_TRANSACTION + 42;
  static constexpr uint32_t TRANSACTION_ipfwdRemoveInterfaceForward = ::android::IBinder::FIRST_CALL_TRANSACTION + 43;
  static constexpr uint32_t TRANSACTION_bandwidthSetInterfaceQuota = ::android::IBinder::FIRST_CALL_TRANSACTION + 44;
  static constexpr uint32_t TRANSACTION_bandwidthRemoveInterfaceQuota = ::android::IBinder::FIRST_CALL_TRANSACTION + 45;
  static constexpr uint32_t TRANSACTION_bandwidthSetInterfaceAlert = ::android::IBinder::FIRST_CALL_TRANSACTION + 46;
  static constexpr uint32_t TRANSACTION_bandwidthRemoveInterfaceAlert = ::android::IBinder::FIRST_CALL_TRANSACTION + 47;
  static constexpr uint32_t TRANSACTION_bandwidthSetGlobalAlert = ::android::IBinder::FIRST_CALL_TRANSACTION + 48;
  static constexpr uint32_t TRANSACTION_bandwidthAddNaughtyApp = ::android::IBinder::FIRST_CALL_TRANSACTION + 49;
  static constexpr uint32_t TRANSACTION_bandwidthRemoveNaughtyApp = ::android::IBinder::FIRST_CALL_TRANSACTION + 50;
  static constexpr uint32_t TRANSACTION_bandwidthAddNiceApp = ::android::IBinder::FIRST_CALL_TRANSACTION + 51;
  static constexpr uint32_t TRANSACTION_bandwidthRemoveNiceApp = ::android::IBinder::FIRST_CALL_TRANSACTION + 52;
  static constexpr uint32_t TRANSACTION_tetherStart = ::android::IBinder::FIRST_CALL_TRANSACTION + 53;
  static constexpr uint32_t TRANSACTION_tetherStop = ::android::IBinder::FIRST_CALL_TRANSACTION + 54;
  static constexpr uint32_t TRANSACTION_tetherIsEnabled = ::android::IBinder::FIRST_CALL_TRANSACTION + 55;
  static constexpr uint32_t TRANSACTION_tetherInterfaceAdd = ::android::IBinder::FIRST_CALL_TRANSACTION + 56;
  static constexpr uint32_t TRANSACTION_tetherInterfaceRemove = ::android::IBinder::FIRST_CALL_TRANSACTION + 57;
  static constexpr uint32_t TRANSACTION_tetherInterfaceList = ::android::IBinder::FIRST_CALL_TRANSACTION + 58;
  static constexpr uint32_t TRANSACTION_tetherDnsSet = ::android::IBinder::FIRST_CALL_TRANSACTION + 59;
  static constexpr uint32_t TRANSACTION_tetherDnsList = ::android::IBinder::FIRST_CALL_TRANSACTION + 60;
  static constexpr uint32_t TRANSACTION_networkAddRoute = ::android::IBinder::FIRST_CALL_TRANSACTION + 61;
  static constexpr uint32_t TRANSACTION_networkRemoveRoute = ::android::IBinder::FIRST_CALL_TRANSACTION + 62;
  static constexpr uint32_t TRANSACTION_networkAddLegacyRoute = ::android::IBinder::FIRST_CALL_TRANSACTION + 63;
  static constexpr uint32_t TRANSACTION_networkRemoveLegacyRoute = ::android::IBinder::FIRST_CALL_TRANSACTION + 64;
  static constexpr uint32_t TRANSACTION_networkGetDefault = ::android::IBinder::FIRST_CALL_TRANSACTION + 65;
  static constexpr uint32_t TRANSACTION_networkSetDefault = ::android::IBinder::FIRST_CALL_TRANSACTION + 66;
  static constexpr uint32_t TRANSACTION_networkClearDefault = ::android::IBinder::FIRST_CALL_TRANSACTION + 67;
  static constexpr uint32_t TRANSACTION_networkSetPermissionForNetwork = ::android::IBinder::FIRST_CALL_TRANSACTION + 68;
  static constexpr uint32_t TRANSACTION_networkSetPermissionForUser = ::android::IBinder::FIRST_CALL_TRANSACTION + 69;
  static constexpr uint32_t TRANSACTION_networkClearPermissionForUser = ::android::IBinder::FIRST_CALL_TRANSACTION + 70;
  static constexpr uint32_t TRANSACTION_trafficSetNetPermForUids = ::android::IBinder::FIRST_CALL_TRANSACTION + 71;
  static constexpr uint32_t TRANSACTION_networkSetProtectAllow = ::android::IBinder::FIRST_CALL_TRANSACTION + 72;
  static constexpr uint32_t TRANSACTION_networkSetProtectDeny = ::android::IBinder::FIRST_CALL_TRANSACTION + 73;
  static constexpr uint32_t TRANSACTION_networkCanProtect = ::android::IBinder::FIRST_CALL_TRANSACTION + 74;
  static constexpr uint32_t TRANSACTION_firewallSetFirewallType = ::android::IBinder::FIRST_CALL_TRANSACTION + 75;
  static constexpr uint32_t TRANSACTION_firewallSetInterfaceRule = ::android::IBinder::FIRST_CALL_TRANSACTION + 76;
  static constexpr uint32_t TRANSACTION_firewallSetUidRule = ::android::IBinder::FIRST_CALL_TRANSACTION + 77;
  static constexpr uint32_t TRANSACTION_firewallEnableChildChain = ::android::IBinder::FIRST_CALL_TRANSACTION + 78;
  static constexpr uint32_t TRANSACTION_interfaceGetList = ::android::IBinder::FIRST_CALL_TRANSACTION + 79;
  static constexpr uint32_t TRANSACTION_interfaceGetCfg = ::android::IBinder::FIRST_CALL_TRANSACTION + 80;
  static constexpr uint32_t TRANSACTION_interfaceSetCfg = ::android::IBinder::FIRST_CALL_TRANSACTION + 81;
  static constexpr uint32_t TRANSACTION_interfaceSetIPv6PrivacyExtensions = ::android::IBinder::FIRST_CALL_TRANSACTION + 82;
  static constexpr uint32_t TRANSACTION_interfaceClearAddrs = ::android::IBinder::FIRST_CALL_TRANSACTION + 83;
  static constexpr uint32_t TRANSACTION_interfaceSetEnableIPv6 = ::android::IBinder::FIRST_CALL_TRANSACTION + 84;
  static constexpr uint32_t TRANSACTION_interfaceSetMtu = ::android::IBinder::FIRST_CALL_TRANSACTION + 85;
  static constexpr uint32_t TRANSACTION_tetherAddForward = ::android::IBinder::FIRST_CALL_TRANSACTION + 86;
  static constexpr uint32_t TRANSACTION_tetherRemoveForward = ::android::IBinder::FIRST_CALL_TRANSACTION + 87;
  static constexpr uint32_t TRANSACTION_setTcpRWmemorySize = ::android::IBinder::FIRST_CALL_TRANSACTION + 88;
  static constexpr uint32_t TRANSACTION_registerUnsolicitedEventListener = ::android::IBinder::FIRST_CALL_TRANSACTION + 89;
  static constexpr uint32_t TRANSACTION_firewallAddUidInterfaceRules = ::android::IBinder::FIRST_CALL_TRANSACTION + 90;
  static constexpr uint32_t TRANSACTION_firewallRemoveUidInterfaceRules = ::android::IBinder::FIRST_CALL_TRANSACTION + 91;
  static constexpr uint32_t TRANSACTION_trafficSwapActiveStatsMap = ::android::IBinder::FIRST_CALL_TRANSACTION + 92;
  static constexpr uint32_t TRANSACTION_getOemNetd = ::android::IBinder::FIRST_CALL_TRANSACTION + 93;
  static constexpr uint32_t TRANSACTION_tetherStartWithConfiguration = ::android::IBinder::FIRST_CALL_TRANSACTION + 94;
  static constexpr uint32_t TRANSACTION_getFwmarkForNetwork = ::android::IBinder::FIRST_CALL_TRANSACTION + 95;
  static constexpr uint32_t TRANSACTION_networkAddRouteParcel = ::android::IBinder::FIRST_CALL_TRANSACTION + 96;
  static constexpr uint32_t TRANSACTION_networkUpdateRouteParcel = ::android::IBinder::FIRST_CALL_TRANSACTION + 97;
  static constexpr uint32_t TRANSACTION_networkRemoveRouteParcel = ::android::IBinder::FIRST_CALL_TRANSACTION + 98;
  static constexpr uint32_t TRANSACTION_tetherOffloadRuleAdd = ::android::IBinder::FIRST_CALL_TRANSACTION + 99;
  static constexpr uint32_t TRANSACTION_tetherOffloadRuleRemove = ::android::IBinder::FIRST_CALL_TRANSACTION + 100;
  static constexpr uint32_t TRANSACTION_tetherOffloadGetStats = ::android::IBinder::FIRST_CALL_TRANSACTION + 101;
  static constexpr uint32_t TRANSACTION_tetherOffloadSetInterfaceQuota = ::android::IBinder::FIRST_CALL_TRANSACTION + 102;
  static constexpr uint32_t TRANSACTION_tetherOffloadGetAndClearStats = ::android::IBinder::FIRST_CALL_TRANSACTION + 103;
  static constexpr uint32_t TRANSACTION_networkCreate = ::android::IBinder::FIRST_CALL_TRANSACTION + 104;
  static constexpr uint32_t TRANSACTION_getInterfaceVersion = ::android::IBinder::FIRST_CALL_TRANSACTION + 16777214;
  static constexpr uint32_t TRANSACTION_getInterfaceHash = ::android::IBinder::FIRST_CALL_TRANSACTION + 16777213;
  explicit BnNetd();
  ::android::status_t onTransact(uint32_t _aidl_code, const ::android::Parcel& _aidl_data, ::android::Parcel* _aidl_reply, uint32_t _aidl_flags) override;
  int32_t getInterfaceVersion() final;
  std::string getInterfaceHash();
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
};  // class BnNetd

}  // namespace net

}  // namespace android
