package android.hardware.radio.V1_4;


public final class DataCallFailCause {
    public static final int NONE = 0;
    public static final int OPERATOR_BARRED = 8 /* 0x08 */;
    public static final int NAS_SIGNALLING = 14 /* 0x0E */;
    public static final int INSUFFICIENT_RESOURCES = 26 /* 0x1A */;
    public static final int MISSING_UKNOWN_APN = 27 /* 0x1B */;
    public static final int UNKNOWN_PDP_ADDRESS_TYPE = 28 /* 0x1C */;
    public static final int USER_AUTHENTICATION = 29 /* 0x1D */;
    public static final int ACTIVATION_REJECT_GGSN = 30 /* 0x1E */;
    public static final int ACTIVATION_REJECT_UNSPECIFIED = 31 /* 0x1F */;
    public static final int SERVICE_OPTION_NOT_SUPPORTED = 32 /* 0x20 */;
    public static final int SERVICE_OPTION_NOT_SUBSCRIBED = 33 /* 0x21 */;
    public static final int SERVICE_OPTION_OUT_OF_ORDER = 34 /* 0x22 */;
    public static final int NSAPI_IN_USE = 35 /* 0x23 */;
    public static final int REGULAR_DEACTIVATION = 36 /* 0x24 */;
    public static final int QOS_NOT_ACCEPTED = 37 /* 0x25 */;
    public static final int NETWORK_FAILURE = 38 /* 0x26 */;
    public static final int UMTS_REACTIVATION_REQ = 39 /* 0x27 */;
    public static final int FEATURE_NOT_SUPP = 40 /* 0x28 */;
    public static final int TFT_SEMANTIC_ERROR = 41 /* 0x29 */;
    public static final int TFT_SYTAX_ERROR = 42 /* 0x2A */;
    public static final int UNKNOWN_PDP_CONTEXT = 43 /* 0x2B */;
    public static final int FILTER_SEMANTIC_ERROR = 44 /* 0x2C */;
    public static final int FILTER_SYTAX_ERROR = 45 /* 0x2D */;
    public static final int PDP_WITHOUT_ACTIVE_TFT = 46 /* 0x2E */;
    public static final int ONLY_IPV4_ALLOWED = 50 /* 0x32 */;
    public static final int ONLY_IPV6_ALLOWED = 51 /* 0x33 */;
    public static final int ONLY_SINGLE_BEARER_ALLOWED = 52 /* 0x34 */;
    public static final int ESM_INFO_NOT_RECEIVED = 53 /* 0x35 */;
    public static final int PDN_CONN_DOES_NOT_EXIST = 54 /* 0x36 */;
    public static final int MULTI_CONN_TO_SAME_PDN_NOT_ALLOWED = 55 /* 0x37 */;
    public static final int MAX_ACTIVE_PDP_CONTEXT_REACHED = 65 /* 0x41 */;
    public static final int UNSUPPORTED_APN_IN_CURRENT_PLMN = 66 /* 0x42 */;
    public static final int INVALID_TRANSACTION_ID = 81 /* 0x51 */;
    public static final int MESSAGE_INCORRECT_SEMANTIC = 95 /* 0x5F */;
    public static final int INVALID_MANDATORY_INFO = 96 /* 0x60 */;
    public static final int MESSAGE_TYPE_UNSUPPORTED = 97 /* 0x61 */;
    public static final int MSG_TYPE_NONCOMPATIBLE_STATE = 98 /* 0x62 */;
    public static final int UNKNOWN_INFO_ELEMENT = 99 /* 0x63 */;
    public static final int CONDITIONAL_IE_ERROR = 100 /* 0x64 */;
    public static final int MSG_AND_PROTOCOL_STATE_UNCOMPATIBLE = 101 /* 0x65 */;
    public static final int PROTOCOL_ERRORS = 111 /* 0x6F */;
    public static final int APN_TYPE_CONFLICT = 112 /* 0x70 */;
    public static final int INVALID_PCSCF_ADDR = 113 /* 0x71 */;
    public static final int INTERNAL_CALL_PREEMPT_BY_HIGH_PRIO_APN = 114 /* 0x72 */;
    public static final int EMM_ACCESS_BARRED = 115 /* 0x73 */;
    public static final int EMERGENCY_IFACE_ONLY = 116 /* 0x74 */;
    public static final int IFACE_MISMATCH = 117 /* 0x75 */;
    public static final int COMPANION_IFACE_IN_USE = 118 /* 0x76 */;
    public static final int IP_ADDRESS_MISMATCH = 119 /* 0x77 */;
    public static final int IFACE_AND_POL_FAMILY_MISMATCH = 120 /* 0x78 */;
    public static final int EMM_ACCESS_BARRED_INFINITE_RETRY = 121 /* 0x79 */;
    public static final int AUTH_FAILURE_ON_EMERGENCY_CALL = 122 /* 0x7A */;
    public static final int OEM_DCFAILCAUSE_1 = 4097 /* 0x1001 */;
    public static final int OEM_DCFAILCAUSE_2 = 4098 /* 0x1002 */;
    public static final int OEM_DCFAILCAUSE_3 = 4099 /* 0x1003 */;
    public static final int OEM_DCFAILCAUSE_4 = 4100 /* 0x1004 */;
    public static final int OEM_DCFAILCAUSE_5 = 4101 /* 0x1005 */;
    public static final int OEM_DCFAILCAUSE_6 = 4102 /* 0x1006 */;
    public static final int OEM_DCFAILCAUSE_7 = 4103 /* 0x1007 */;
    public static final int OEM_DCFAILCAUSE_8 = 4104 /* 0x1008 */;
    public static final int OEM_DCFAILCAUSE_9 = 4105 /* 0x1009 */;
    public static final int OEM_DCFAILCAUSE_10 = 4106 /* 0x100A */;
    public static final int OEM_DCFAILCAUSE_11 = 4107 /* 0x100B */;
    public static final int OEM_DCFAILCAUSE_12 = 4108 /* 0x100C */;
    public static final int OEM_DCFAILCAUSE_13 = 4109 /* 0x100D */;
    public static final int OEM_DCFAILCAUSE_14 = 4110 /* 0x100E */;
    public static final int OEM_DCFAILCAUSE_15 = 4111 /* 0x100F */;
    public static final int VOICE_REGISTRATION_FAIL = -1 /* -1 */;
    public static final int DATA_REGISTRATION_FAIL = -2 /* -2 */;
    public static final int SIGNAL_LOST = -3 /* -3 */;
    public static final int PREF_RADIO_TECH_CHANGED = -4 /* -4 */;
    public static final int RADIO_POWER_OFF = -5 /* -5 */;
    public static final int TETHERED_CALL_ACTIVE = -6 /* -6 */;
    public static final int ERROR_UNSPECIFIED = 65535 /* 0xffff */;
    /**
     * Network cannot provide the requested service and PDP context is deactivated because of LLC
     * or SNDCP failure.
     */
    public static final int LLC_SNDCP = 25 /* 0x19 */;
    /**
     * UE requested to modify QoS parameters or the bearer control mode, which is not compatible
     * with the selected bearer control mode.
     */
    public static final int ACTIVATION_REJECTED_BCM_VIOLATION = 48 /* 0x30 */;
    /**
     * Network has already initiated the activation, modification, or deactivation of bearer
     * resources that was requested by the UE.
     */
    public static final int COLLISION_WITH_NETWORK_INITIATED_REQUEST = 56 /* 0x38 */;
    /**
     * Network supports IPv4v6 PDP type only. Non-IP type is not allowed. In LTE mode of operation,
     * this is a PDN throttling cause code, meaning the UE may throttle further requests to the
     * same APN.
     */
    public static final int ONLY_IPV4V6_ALLOWED = 57 /* 0x39 */;
    /**
     * Network supports non-IP PDP type only. IPv4, IPv6 and IPv4v6 is not allowed. In LTE mode of
     * operation, this is a PDN throttling cause code, meaning the UE can throttle further requests
     * to the same APN.
     */
    public static final int ONLY_NON_IP_ALLOWED = 58 /* 0x3A */;
    /**
     * QCI (QoS Class Identifier) indicated in the UE request cannot be supported.
     */
    public static final int UNSUPPORTED_QCI_VALUE = 59 /* 0x3B */;
    /**
     * Procedure requested by the UE was rejected because the bearer handling is not supported.
     */
    public static final int BEARER_HANDLING_NOT_SUPPORTED = 60 /* 0x3C */;
    /**
     * Not receiving a DNS address that was mandatory.
     */
    public static final int INVALID_DNS_ADDR = 123 /* 0x7B */;
    /**
     * Not receiving either a PCSCF or a DNS address, one of them being mandatory.
     */
    public static final int INVALID_PCSCF_OR_DNS_ADDRESS = 124 /* 0x7C */;
    /**
     * Emergency call bring up on a different ePDG.
     */
    public static final int CALL_PREEMPT_BY_EMERGENCY_APN = 127 /* 0x7F */;
    /**
     * UE performs a detach or disconnect PDN action based on TE requirements.
     */
    public static final int UE_INITIATED_DETACH_OR_DISCONNECT = 128 /* 0x80 */;
    /**
     * Reason unspecified for foreign agent rejected MIP (Mobile IP) registration.
     */
    public static final int MIP_FA_REASON_UNSPECIFIED = 2000 /* 0x7D0 */;
    /**
     * Foreign agent administratively prohibited MIP (Mobile IP) registration.
     */
    public static final int MIP_FA_ADMIN_PROHIBITED = 2001 /* 0x7D1 */;
    /**
     * Foreign agent rejected MIP (Mobile IP) registration because of insufficient resources.
     */
    public static final int MIP_FA_INSUFFICIENT_RESOURCES = 2002 /* 0x7D2 */;
    /**
     * Foreign agent rejected MIP (Mobile IP) registration because of MN-AAA authenticator was
     * wrong.
     */
    public static final int MIP_FA_MOBILE_NODE_AUTHENTICATION_FAILURE = 2003 /* 0x7D3 */;
    /**
     * Foreign agent rejected MIP (Mobile IP) registration because of home agent authentication
     * failure.
     */
    public static final int MIP_FA_HOME_AGENT_AUTHENTICATION_FAILURE = 2004 /* 0x7D4 */;
    /**
     * Foreign agent rejected MIP (Mobile IP) registration because of requested lifetime was too
     * long.
     */
    public static final int MIP_FA_REQUESTED_LIFETIME_TOO_LONG = 2005 /* 0x7D5 */;
    /**
     * Foreign agent rejected MIP (Mobile IP) registration because of malformed request.
     */
    public static final int MIP_FA_MALFORMED_REQUEST = 2006 /* 0x7D6 */;
    /**
     * Foreign agent rejected MIP (Mobile IP) registration because of malformed reply.
     */
    public static final int MIP_FA_MALFORMED_REPLY = 2007 /* 0x7D7 */;
    /**
     * Foreign agent rejected MIP (Mobile IP) registration because of requested encapsulation was
     * unavailable.
     */
    public static final int MIP_FA_ENCAPSULATION_UNAVAILABLE = 2008 /* 0x7D8 */;
    /**
     * Foreign agent rejected MIP (Mobile IP) registration of VJ Header Compression was unavailable.
     */
    public static final int MIP_FA_VJ_HEADER_COMPRESSION_UNAVAILABLE = 2009 /* 0x7D9 */;
    /**
     * Foreign agent rejected MIP (Mobile IP) registration because of reverse tunnel was
     * unavailable.
     */
    public static final int MIP_FA_REVERSE_TUNNEL_UNAVAILABLE = 2010 /* 0x7DA */;
    /**
     * Foreign agent rejected MIP (Mobile IP) registration because of reverse tunnel was mandatory
     * but not requested by device.
     */
    public static final int MIP_FA_REVERSE_TUNNEL_IS_MANDATORY = 2011 /* 0x7DB */;
    /**
     * Foreign agent rejected MIP (Mobile IP) registration because of delivery style was not
     * supported.
     */
    public static final int MIP_FA_DELIVERY_STYLE_NOT_SUPPORTED = 2012 /* 0x7DC */;
    /**
     * Foreign agent rejected MIP (Mobile IP) registration because of missing NAI (Network Access
     * Identifier).
     */
    public static final int MIP_FA_MISSING_NAI = 2013 /* 0x7DD */;
    /**
     * Foreign agent rejected MIP (Mobile IP) registration because of missing Home Agent.
     */
    public static final int MIP_FA_MISSING_HOME_AGENT = 2014 /* 0x7DE */;
    /**
     * Foreign agent rejected MIP (Mobile IP) registration because of missing Home Address.
     */
    public static final int MIP_FA_MISSING_HOME_ADDRESS = 2015 /* 0x7DF */;
    /**
     * Foreign agent rejected MIP (Mobile IP) registration because of unknown challenge.
     */
    public static final int MIP_FA_UNKNOWN_CHALLENGE = 2016 /* 0x7E0 */;
    /**
     * Foreign agent rejected MIP (Mobile IP) registration because of missing challenge.
     */
    public static final int MIP_FA_MISSING_CHALLENGE = 2017 /* 0x7E1 */;
    /**
     * Foreign agent rejected MIP (Mobile IP) registration because of stale challenge.
     */
    public static final int MIP_FA_STALE_CHALLENGE = 2018 /* 0x7E2 */;
    /**
     * Reason unspecified for home agent rejected MIP (Mobile IP) registration.
     */
    public static final int MIP_HA_REASON_UNSPECIFIED = 2019 /* 0x7E3 */;
    /**
     * Home agent administratively prohibited MIP (Mobile IP) registration.
     */
    public static final int MIP_HA_ADMIN_PROHIBITED = 2020 /* 0x7E4 */;
    /**
     * Home agent rejected MIP (Mobile IP) registration because of insufficient resources.
     */
    public static final int MIP_HA_INSUFFICIENT_RESOURCES = 2021 /* 0x7E5 */;
    /**
     * Home agent rejected MIP (Mobile IP) registration because of MN-HA authenticator was wrong.
     */
    public static final int MIP_HA_MOBILE_NODE_AUTHENTICATION_FAILURE = 2022 /* 0x7E6 */;
    /**
     * Home agent rejected MIP (Mobile IP) registration because of foreign agent authentication
     * failure.
     */
    public static final int MIP_HA_FOREIGN_AGENT_AUTHENTICATION_FAILURE = 2023 /* 0x7E7 */;
    /**
     * Home agent rejected MIP (Mobile IP) registration because of registration id mismatch.
     */
    public static final int MIP_HA_REGISTRATION_ID_MISMATCH = 2024 /* 0x7E8 */;
    /**
     * Home agent rejected MIP (Mobile IP) registration because of malformed request.
     */
    public static final int MIP_HA_MALFORMED_REQUEST = 2025 /* 0x7E9 */;
    /**
     * Home agent rejected MIP (Mobile IP) registration because of unknown home agent address.
     */
    public static final int MIP_HA_UNKNOWN_HOME_AGENT_ADDRESS = 2026 /* 0x7EA */;
    /**
     * Home agent rejected MIP (Mobile IP) registration because of reverse tunnel was unavailable.
     */
    public static final int MIP_HA_REVERSE_TUNNEL_UNAVAILABLE = 2027 /* 0x7EB */;
    /**
     * Home agent rejected MIP (Mobile IP) registration because of reverse tunnel is mandatory but
     * not requested by device.
     */
    public static final int MIP_HA_REVERSE_TUNNEL_IS_MANDATORY = 2028 /* 0x7EC */;
    /**
     * Home agent rejected MIP (Mobile IP) registration because of encapsulation unavailable.
     */
    public static final int MIP_HA_ENCAPSULATION_UNAVAILABLE = 2029 /* 0x7ED */;
    /**
     * Tearing down is in progress.
     */
    public static final int CLOSE_IN_PROGRESS = 2030 /* 0x7EE */;
    /**
     * Brought down by the network.
     */
    public static final int NETWORK_INITIATED_TERMINATION = 2031 /* 0x7EF */;
    /**
     * Another application in modem preempts the data call.
     */
    public static final int MODEM_APP_PREEMPTED = 2032 /* 0x7F0 */;
    /**
     * IPV4 PDN is in throttled state due to network providing only IPV6 address during the previous
     * VSNCP bringup (subs_limited_to_v6).
     */
    public static final int PDN_IPV4_CALL_DISALLOWED = 2033 /* 0x7F1 */;
    /**
     * IPV4 PDN is in throttled state due to previous VSNCP bringup failure(s).
     */
    public static final int PDN_IPV4_CALL_THROTTLED = 2034 /* 0x7F2 */;
    /**
     * IPV6 PDN is in throttled state due to network providing only IPV4 address during the previous
     * VSNCP bringup (subs_limited_to_v4).
     */
    public static final int PDN_IPV6_CALL_DISALLOWED = 2035 /* 0x7F3 */;
    /**
     * IPV6 PDN is in throttled state due to previous VSNCP bringup failure(s).
     */
    public static final int PDN_IPV6_CALL_THROTTLED = 2036 /* 0x7F4 */;
    /**
     * Modem restart.
     */
    public static final int MODEM_RESTART = 2037 /* 0x7F5 */;
    /**
     * PDP PPP calls are not supported.
     */
    public static final int PDP_PPP_NOT_SUPPORTED = 2038 /* 0x7F6 */;
    /**
     * RAT on which the data call is attempted/connected is no longer the preferred RAT.
     */
    public static final int UNPREFERRED_RAT = 2039 /* 0x7F7 */;
    /**
     * Physical link is in the process of cleanup.
     */
    public static final int PHYSICAL_LINK_CLOSE_IN_PROGRESS = 2040 /* 0x7F8 */;
    /**
     * Interface bring up is attempted for an APN that is yet to be handed over to target RAT.
     */
    public static final int APN_PENDING_HANDOVER = 2041 /* 0x7F9 */;
    /**
     * APN bearer type in the profile does not match preferred network mode.
     */
    public static final int PROFILE_BEARER_INCOMPATIBLE = 2042 /* 0x7FA */;
    /**
     * Card was refreshed or removed.
     */
    public static final int SIM_CARD_CHANGED = 2043 /* 0x7FB */;
    /**
     * Device is going into lower power mode or powering down.
     */
    public static final int LOW_POWER_MODE_OR_POWERING_DOWN = 2044 /* 0x7FC */;
    /**
     * APN has been disabled.
     */
    public static final int APN_DISABLED = 2045 /* 0x7FD */;
    /**
     * Maximum PPP inactivity timer expired.
     */
    public static final int MAX_PPP_INACTIVITY_TIMER_EXPIRED = 2046 /* 0x7FE */;
    /**
     * IPv6 address transfer failed.
     */
    public static final int IPV6_ADDRESS_TRANSFER_FAILED = 2047 /* 0x7FF */;
    /**
     * Target RAT swap failed.
     */
    public static final int TRAT_SWAP_FAILED = 2048 /* 0x800 */;
    /**
     * Device falls back from eHRPD to HRPD.
     */
    public static final int EHRPD_TO_HRPD_FALLBACK = 2049 /* 0x801 */;
    /**
     * UE is in MIP-only configuration but the MIP configuration fails on call bring up due to
     * incorrect provisioning.
     */
    public static final int MIP_CONFIG_FAILURE = 2050 /* 0x802 */;
    /**
     * PDN inactivity timer expired due to no data transmission in a configurable duration of time.
     */
    public static final int PDN_INACTIVITY_TIMER_EXPIRED = 2051 /* 0x803 */;
    /**
     * IPv4 data call bring up is rejected because the UE already maintains the allotted maximum
     * number of IPv4 data connections.
     */
    public static final int MAX_IPV4_CONNECTIONS = 2052 /* 0x804 */;
    /**
     * IPv6 data call bring up is rejected because the UE already maintains the allotted maximum
     * number of IPv6 data connections.
     */
    public static final int MAX_IPV6_CONNECTIONS = 2053 /* 0x805 */;
    /**
     * New PDN bring up is rejected during interface selection because the UE has already allotted
     * the available interfaces for other PDNs.
     */
    public static final int APN_MISMATCH = 2054 /* 0x806 */;
    /**
     * New call bring up is rejected since the existing data call IP type doesn't match the
     * requested IP.
     */
    public static final int IP_VERSION_MISMATCH = 2055 /* 0x807 */;
    /**
     * Dial up networking (DUN) call bring up is rejected since UE is in eHRPD RAT.
     */
    public static final int DUN_CALL_DISALLOWED = 2056 /* 0x808 */;
    /**
     * Rejected/Brought down since UE is transition between EPC and NONEPC RAT.
     */
    public static final int INTERNAL_EPC_NONEPC_TRANSITION = 2057 /* 0x809 */;
    /**
     * The current interface is being in use.
     */
    public static final int INTERFACE_IN_USE = 2058 /* 0x80A */;
    /**
     * PDN connection to the APN is disallowed on the roaming network.
     */
    public static final int APN_DISALLOWED_ON_ROAMING = 2059 /* 0x80B */;
    /**
     * APN-related parameters are changed.
     */
    public static final int APN_PARAMETERS_CHANGED = 2060 /* 0x80C */;
    /**
     * PDN is attempted to be brought up with NULL APN but NULL APN is not supported.
     */
    public static final int NULL_APN_DISALLOWED = 2061 /* 0x80D */;
    /**
     * Thermal level increases and causes calls to be torn down when normal mode of operation is
     * not allowed.
     */
    public static final int THERMAL_MITIGATION = 2062 /* 0x80E */;
    /**
     * PDN Connection to a given APN is disallowed because data is disabled from the device user
     * interface settings.
     */
    public static final int DATA_SETTINGS_DISABLED = 2063 /* 0x80F */;
    /**
     * PDN Connection to a given APN is disallowed because data roaming is disabled from the device
     * user interface settings and the UE is roaming.
     */
    public static final int DATA_ROAMING_SETTINGS_DISABLED = 2064 /* 0x810 */;
    /**
     * DDS (Default data subscription) switch occurs.
     */
    public static final int DDS_SWITCHED = 2065 /* 0x811 */;
    /**
     * PDN being brought up with an APN that is part of forbidden APN Name list.
     */
    public static final int FORBIDDEN_APN_NAME = 2066 /* 0x812 */;
    /**
     * Default data subscription switch is in progress.
     */
    public static final int DDS_SWITCH_IN_PROGRESS = 2067 /* 0x813 */;
    /**
     * Roaming is disallowed during call bring up.
     */
    public static final int CALL_DISALLOWED_IN_ROAMING = 2068 /* 0x814 */;
    /**
     * UE is unable to bring up a non-IP data call because the device is not camped on a NB1 cell.
     */
    public static final int NON_IP_NOT_SUPPORTED = 2069 /* 0x815 */;
    /**
     * Non-IP PDN is in throttled state due to previous VSNCP bringup failure(s).
     */
    public static final int PDN_NON_IP_CALL_THROTTLED = 2070 /* 0x816 */;
    /**
     * Non-IP PDN is in disallowed state due to the network providing only an IP address.
     */
    public static final int PDN_NON_IP_CALL_DISALLOWED = 2071 /* 0x817 */;
    /**
     * Device in CDMA locked state.
     */
    public static final int CDMA_LOCK = 2072 /* 0x818 */;
    /**
     * Received an intercept order from the base station.
     */
    public static final int CDMA_INTERCEPT = 2073 /* 0x819 */;
    /**
     * Receiving a reorder from the base station.
     */
    public static final int CDMA_REORDER = 2074 /* 0x81A */;
    /**
     * Receiving a release from the base station with a SO (Service Option) Reject reason.
     */
    public static final int CDMA_RELEASE_DUE_TO_SO_REJECTION = 2075 /* 0x81B */;
    /**
     * Receiving an incoming call from the base station.
     */
    public static final int CDMA_INCOMING_CALL = 2076 /* 0x81C */;
    /**
     * Received an alert stop from the base station due to incoming only.
     */
    public static final int CDMA_ALERT_STOP = 2077 /* 0x81D */;
    /**
     * Channel acquisition failures. This indicates that device has failed acquiring all the
     * channels in the PRL.
     */
    public static final int CHANNEL_ACQUISITION_FAILURE = 2078 /* 0x81E */;
    /**
     * Maximum access probes transmitted.
     */
    public static final int MAX_ACCESS_PROBE = 2079 /* 0x81F */;
    /**
     * Concurrent service is not supported by base station.
     */
    public static final int CONCURRENT_SERVICE_NOT_SUPPORTED_BY_BASE_STATION = 2080 /* 0x820 */;
    /**
     * There was no response received from the base station.
     */
    public static final int NO_RESPONSE_FROM_BASE_STATION = 2081 /* 0x821 */;
    /**
     * The base station rejecting the call.
     */
    public static final int REJECTED_BY_BASE_STATION = 2082 /* 0x822 */;
    /**
     * The concurrent services requested were not compatible.
     */
    public static final int CONCURRENT_SERVICES_INCOMPATIBLE = 2083 /* 0x823 */;
    /**
     * Device does not have CDMA service.
     */
    public static final int NO_CDMA_SERVICE = 2084 /* 0x824 */;
    /**
     * RUIM not being present.
     */
    public static final int RUIM_NOT_PRESENT = 2085 /* 0x825 */;
    /**
     * Receiving a retry order from the base station.
     */
    public static final int CDMA_RETRY_ORDER = 2086 /* 0x826 */;
    /**
     * Access blocked by the base station.
     */
    public static final int ACCESS_BLOCK = 2087 /* 0x827 */;
    /**
     * Access blocked by the base station for all mobile devices.
     */
    public static final int ACCESS_BLOCK_ALL = 2088 /* 0x828 */;
    /**
     * Maximum access probes for the IS-707B call.
     */
    public static final int IS707B_MAX_ACCESS_PROBES = 2089 /* 0x829 */;
    /**
     * Put device in thermal emergency.
     */
    public static final int THERMAL_EMERGENCY = 2090 /* 0x82A */;
    /**
     * In favor of a voice call or SMS when concurrent voice and data are not supported.
     */
    public static final int CONCURRENT_SERVICES_NOT_ALLOWED = 2091 /* 0x82B */;
    /**
     * The other clients rejected incoming call.
     */
    public static final int INCOMING_CALL_REJECTED = 2092 /* 0x82C */;
    /**
     * No service on the gateway.
     */
    public static final int NO_SERVICE_ON_GATEWAY = 2093 /* 0x82D */;
    /**
     * GPRS context is not available.
     */
    public static final int NO_GPRS_CONTEXT = 2094 /* 0x82E */;
    /**
     * Network refuses service to the MS because either an identity of the MS is not acceptable to
     * the network or the MS does not pass the authentication check.
     */
    public static final int ILLEGAL_MS = 2095 /* 0x82F */;
    /**
     * ME could not be authenticated and the ME used is not acceptable to the network.
     */
    public static final int ILLEGAL_ME = 2096 /* 0x830 */;
    /**
     * Not allowed to operate either GPRS or non-GPRS services.
     */
    public static final int GPRS_SERVICES_AND_NON_GPRS_SERVICES_NOT_ALLOWED = 2097 /* 0x831 */;
    /**
     * MS is not allowed to operate GPRS services.
     */
    public static final int GPRS_SERVICES_NOT_ALLOWED = 2098 /* 0x832 */;
    /**
     * No matching identity or context could be found in the network.
     */
    public static final int MS_IDENTITY_CANNOT_BE_DERIVED_BY_THE_NETWORK = 2099 /* 0x833 */;
    /**
     * Mobile reachable timer has expired, or the GMM context data related to the subscription does
     * not exist in the SGSN.
     */
    public static final int IMPLICITLY_DETACHED = 2100 /* 0x834 */;
    /**
     * UE requests GPRS service, or the network initiates a detach request in a PLMN which does not
     * offer roaming for GPRS services to that MS.
     */
    public static final int PLMN_NOT_ALLOWED = 2101 /* 0x835 */;
    /**
     * MS requests service, or the network initiates a detach request, in a location area where the
     * HPLMN determines that the MS, by subscription, is not allowed to operate.
     */
    public static final int LOCATION_AREA_NOT_ALLOWED = 2102 /* 0x836 */;
    /**
     * UE requests GPRS service or the network initiates a detach request in a PLMN that does not
     * offer roaming for GPRS services.
     */
    public static final int GPRS_SERVICES_NOT_ALLOWED_IN_THIS_PLMN = 2103 /* 0x837 */;
    /**
     * PDP context already exists.
     */
    public static final int PDP_DUPLICATE = 2104 /* 0x838 */;
    /**
     * RAT change on the UE.
     */
    public static final int UE_RAT_CHANGE = 2105 /* 0x839 */;
    /**
     * Network cannot serve a request from the MS due to congestion.
     */
    public static final int CONGESTION = 2106 /* 0x83A */;
    /**
     * MS requests an establishment of the radio access bearers for all active PDP contexts by
     * sending a service request message indicating data to the network, but the SGSN does not have
     * any active PDP context.
     */
    public static final int NO_PDP_CONTEXT_ACTIVATED = 2107 /* 0x83B */;
    /**
     * Access class blocking restrictions for the current camped cell.
     */
    public static final int ACCESS_CLASS_DSAC_REJECTION = 2108 /* 0x83C */;
    /**
     * SM attempts PDP activation for a maximum of four attempts.
     */
    public static final int PDP_ACTIVATE_MAX_RETRY_FAILED = 2109 /* 0x83D */;
    /**
     * Radio access bearer failure.
     */
    public static final int RADIO_ACCESS_BEARER_FAILURE = 2110 /* 0x83E */;
    /**
     * Invalid EPS bearer identity in the request.
     */
    public static final int ESM_UNKNOWN_EPS_BEARER_CONTEXT = 2111 /* 0x83F */;
    /**
     * Data radio bearer is released by the RRC.
     */
    public static final int DRB_RELEASED_BY_RRC = 2112 /* 0x840 */;
    /**
     * Indicate the connection was released.
     */
    public static final int CONNECTION_RELEASED = 2113 /* 0x841 */;
    /**
     * UE is detached.
     */
    public static final int EMM_DETACHED = 2114 /* 0x842 */;
    /**
     * Attach procedure is rejected by the network.
     */
    public static final int EMM_ATTACH_FAILED = 2115 /* 0x843 */;
    /**
     * Attach procedure is started for EMC purposes.
     */
    public static final int EMM_ATTACH_STARTED = 2116 /* 0x844 */;
    /**
     * Service request procedure failure.
     */
    public static final int LTE_NAS_SERVICE_REQUEST_FAILED = 2117 /* 0x845 */;
    /**
     * Active dedicated bearer was requested using the same default bearer ID.
     */
    public static final int DUPLICATE_BEARER_ID = 2118 /* 0x846 */;
    /**
     * Collision scenarios for the UE and network-initiated procedures.
     */
    public static final int ESM_COLLISION_SCENARIOS = 2119 /* 0x847 */;
    /**
     * Bearer must be deactivated to synchronize with the network.
     */
    public static final int ESM_BEARER_DEACTIVATED_TO_SYNC_WITH_NETWORK = 2120 /* 0x848 */;
    /**
     * Active dedicated bearer was requested for an existing default bearer.
     */
    public static final int ESM_NW_ACTIVATED_DED_BEARER_WITH_ID_OF_DEF_BEARER = 2121 /* 0x849 */;
    /**
     * Bad OTA message is received from the network.
     */
    public static final int ESM_BAD_OTA_MESSAGE = 2122 /* 0x84A */;
    /**
     * Download server rejected the call.
     */
    public static final int ESM_DOWNLOAD_SERVER_REJECTED_THE_CALL = 2123 /* 0x84B */;
    /**
     * PDN was disconnected by the downlaod server due to IRAT.
     */
    public static final int ESM_CONTEXT_TRANSFERRED_DUE_TO_IRAT = 2124 /* 0x84C */;
    /**
     * Dedicated bearer will be deactivated regardless of the network response.
     */
    public static final int DS_EXPLICIT_DEACTIVATION = 2125 /* 0x84D */;
    /**
     * No specific local cause is mentioned, usually a valid OTA cause.
     */
    public static final int ESM_LOCAL_CAUSE_NONE = 2126 /* 0x84E */;
    /**
     * Throttling is not needed for this service request failure.
     */
    public static final int LTE_THROTTLING_NOT_REQUIRED = 2127 /* 0x84F */;
    /**
     * Access control list check failure at the lower layer.
     */
    public static final int ACCESS_CONTROL_LIST_CHECK_FAILURE = 2128 /* 0x850 */;
    /**
     * Service is not allowed on the requested PLMN.
     */
    public static final int SERVICE_NOT_ALLOWED_ON_PLMN = 2129 /* 0x851 */;
    /**
     * T3417 timer expiration of the service request procedure.
     */
    public static final int EMM_T3417_EXPIRED = 2130 /* 0x852 */;
    /**
     * Extended service request fails due to expiration of the T3417 EXT timer.
     */
    public static final int EMM_T3417_EXT_EXPIRED = 2131 /* 0x853 */;
    /**
     * Transmission failure of radio resource control (RRC) uplink data.
     */
    public static final int RRC_UPLINK_DATA_TRANSMISSION_FAILURE = 2132 /* 0x854 */;
    /**
     * Radio resource control (RRC) uplink data delivery failed due to a handover.
     */
    public static final int RRC_UPLINK_DELIVERY_FAILED_DUE_TO_HANDOVER = 2133 /* 0x855 */;
    /**
     * Radio resource control (RRC) uplink data delivery failed due to a connection release.
     */
    public static final int RRC_UPLINK_CONNECTION_RELEASE = 2134 /* 0x856 */;
    /**
     * Radio resource control (RRC) uplink data delivery failed due to a radio link failure.
     */
    public static final int RRC_UPLINK_RADIO_LINK_FAILURE = 2135 /* 0x857 */;
    /**
     * Radio resource control (RRC) is not connected but the non-access stratum (NAS) sends an
     * uplink data request.
     */
    public static final int RRC_UPLINK_ERROR_REQUEST_FROM_NAS = 2136 /* 0x858 */;
    /**
     * Radio resource control (RRC) connection failure at access stratum.
     */
    public static final int RRC_CONNECTION_ACCESS_STRATUM_FAILURE = 2137 /* 0x859 */;
    /**
     * Radio resource control (RRC) connection establishment is aborted due to another procedure.
     */
    public static final int RRC_CONNECTION_ANOTHER_PROCEDURE_IN_PROGRESS = 2138 /* 0x85A */;
    /**
     * Radio resource control (RRC) connection establishment failed due to access barrred.
     */
    public static final int RRC_CONNECTION_ACCESS_BARRED = 2139 /* 0x85B */;
    /**
     * Radio resource control (RRC) connection establishment failed due to cell reselection at
     * access stratum.
     */
    public static final int RRC_CONNECTION_CELL_RESELECTION = 2140 /* 0x85C */;
    /**
     * Connection establishment failed due to configuration failure at the radio resource control
     * (RRC).
     */
    public static final int RRC_CONNECTION_CONFIG_FAILURE = 2141 /* 0x85D */;
    /**
     * Radio resource control (RRC) connection could not be established in the time limit.
     */
    public static final int RRC_CONNECTION_TIMER_EXPIRED = 2142 /* 0x85E */;
    /**
     * Connection establishment failed due to a link failure at the radio resource control (RRC).
     */
    public static final int RRC_CONNECTION_LINK_FAILURE = 2143 /* 0x85F */;
    /**
     * Connection establishment failed as the radio resource control (RRC) is not camped on any
     * cell.
     */
    public static final int RRC_CONNECTION_CELL_NOT_CAMPED = 2144 /* 0x860 */;
    /**
     * Connection establishment failed due to a service interval failure at the radio resource
     * control (RRC).
     */
    public static final int RRC_CONNECTION_SYSTEM_INTERVAL_FAILURE = 2145 /* 0x861 */;
    /**
     * Radio resource control (RRC) connection establishment failed due to the network rejecting the
     * UE connection request.
     */
    public static final int RRC_CONNECTION_REJECT_BY_NETWORK = 2146 /* 0x862 */;
    /**
     * Normal radio resource control (RRC) connection release.
     */
    public static final int RRC_CONNECTION_NORMAL_RELEASE = 2147 /* 0x863 */;
    /**
     * Radio resource control (RRC) connection release failed due to radio link failure conditions.
     */
    public static final int RRC_CONNECTION_RADIO_LINK_FAILURE = 2148 /* 0x864 */;
    /**
     * Radio resource control (RRC) connection re-establishment failure.
     */
    public static final int RRC_CONNECTION_REESTABLISHMENT_FAILURE = 2149 /* 0x865 */;
    /**
     * UE is out of service during the call register.
     */
    public static final int RRC_CONNECTION_OUT_OF_SERVICE_DURING_CELL_REGISTER = 2150 /* 0x866 */;
    /**
     * Connection has been released by the radio resource control (RRC) due to an abort request.
     */
    public static final int RRC_CONNECTION_ABORT_REQUEST = 2151 /* 0x867 */;
    /**
     * Radio resource control (RRC) connection released due to a system information block read
     * error.
     */
    public static final int RRC_CONNECTION_SYSTEM_INFORMATION_BLOCK_READ_ERROR = 2152 /* 0x868 */;
    /**
     * Network-initiated detach with reattach.
     */
    public static final int NETWORK_INITIATED_DETACH_WITH_AUTO_REATTACH = 2153 /* 0x869 */;
    /**
     * Network-initiated detach without reattach.
     */
    public static final int NETWORK_INITIATED_DETACH_NO_AUTO_REATTACH = 2154 /* 0x86A */;
    /**
     * ESM procedure maximum attempt timeout failure.
     */
    public static final int ESM_PROCEDURE_TIME_OUT = 2155 /* 0x86B */;
    /**
     * No PDP exists with the given connection ID while modifying or deactivating or activation for
     * an already active PDP.
     */
    public static final int INVALID_CONNECTION_ID = 2156 /* 0x86C */;
    /**
     * Maximum NSAPIs have been exceeded during PDP activation.
     */
    public static final int MAXIMIUM_NSAPIS_EXCEEDED = 2157 /* 0x86D */;
    /**
     * Primary context for NSAPI does not exist.
     */
    public static final int INVALID_PRIMARY_NSAPI = 2158 /* 0x86E */;
    /**
     * Unable to encode the OTA message for MT PDP or deactivate PDP.
     */
    public static final int CANNOT_ENCODE_OTA_MESSAGE = 2159 /* 0x86F */;
    /**
     * Radio access bearer is not established by the lower layers during activation, modification,
     * or deactivation.
     */
    public static final int RADIO_ACCESS_BEARER_SETUP_FAILURE = 2160 /* 0x870 */;
    /**
     * Expiration of the PDP establish timer with a maximum of five retries.
     */
    public static final int PDP_ESTABLISH_TIMEOUT_EXPIRED = 2161 /* 0x871 */;
    /**
     * Expiration of the PDP modify timer with a maximum of four retries.
     */
    public static final int PDP_MODIFY_TIMEOUT_EXPIRED = 2162 /* 0x872 */;
    /**
     * Expiration of the PDP deactivate timer with a maximum of four retries.
     */
    public static final int PDP_INACTIVE_TIMEOUT_EXPIRED = 2163 /* 0x873 */;
    /**
     * PDP activation failed due to RRC_ABORT or a forbidden PLMN.
     */
    public static final int PDP_LOWERLAYER_ERROR = 2164 /* 0x874 */;
    /**
     * MO PDP modify collision when the MT PDP is already in progress.
     */
    public static final int PDP_MODIFY_COLLISION = 2165 /* 0x875 */;
    /**
     * Maximum size of the L2 message was exceeded.
     */
    public static final int MAXINUM_SIZE_OF_L2_MESSAGE_EXCEEDED = 2166 /* 0x876 */;
    /**
     * Non-access stratum (NAS) request was rejected by the network.
     */
    public static final int NAS_REQUEST_REJECTED_BY_NETWORK = 2167 /* 0x877 */;
    /**
     * Radio resource control (RRC) connection establishment failure due to an error in the request
     * message.
     */
    public static final int RRC_CONNECTION_INVALID_REQUEST = 2168 /* 0x878 */;
    /**
     * Radio resource control (RRC) connection establishment failure due to a change in the tracking
     * area ID.
     */
    public static final int RRC_CONNECTION_TRACKING_AREA_ID_CHANGED = 2169 /* 0x879 */;
    /**
     * Radio resource control (RRC) connection establishment failure due to the RF was unavailable.
     */
    public static final int RRC_CONNECTION_RF_UNAVAILABLE = 2170 /* 0x87A */;
    /**
     * Radio resource control (RRC) connection was aborted before deactivating the LTE stack due to
     * a successful LTE to WCDMA/GSM/TD-SCDMA IRAT change.
     */
    public static final int RRC_CONNECTION_ABORTED_DUE_TO_IRAT_CHANGE = 2171 /* 0x87B */;
    /**
     * If the UE has an LTE radio link failure before security is established, the radio resource
     * control (RRC) connection must be released and the UE must return to idle.
     */
    public static final int RRC_CONNECTION_RELEASED_SECURITY_NOT_ACTIVE = 2172 /* 0x87C */;
    /**
     * Radio resource control (RRC) connection was aborted by the non-access stratum (NAS) after an
     * IRAT to LTE IRAT handover.
     */
    public static final int RRC_CONNECTION_ABORTED_AFTER_HANDOVER = 2173 /* 0x87D */;
    /**
     * Radio resource control (RRC) connection was aborted before deactivating the LTE stack after a
     * successful LTE to GSM/EDGE IRAT cell change order procedure.
     */
    public static final int RRC_CONNECTION_ABORTED_AFTER_IRAT_CELL_CHANGE = 2174 /* 0x87E */;
    /**
     * Radio resource control (RRC) connection was aborted in the middle of a LTE to GSM IRAT cell
     * change order procedure.
     */
    public static final int RRC_CONNECTION_ABORTED_DURING_IRAT_CELL_CHANGE = 2175 /* 0x87F */;
    /**
     * IMSI present in the UE is unknown in the home subscriber server.
     */
    public static final int IMSI_UNKNOWN_IN_HOME_SUBSCRIBER_SERVER = 2176 /* 0x880 */;
    /**
     * IMEI of the UE is not accepted by the network.
     */
    public static final int IMEI_NOT_ACCEPTED = 2177 /* 0x881 */;
    /**
     * EPS and non-EPS services are not allowed by the network.
     */
    public static final int EPS_SERVICES_AND_NON_EPS_SERVICES_NOT_ALLOWED = 2178 /* 0x882 */;
    /**
     * EPS services are not allowed in the PLMN.
     */
    public static final int EPS_SERVICES_NOT_ALLOWED_IN_PLMN = 2179 /* 0x883 */;
    /**
     * Mobile switching center is temporarily unreachable.
     */
    public static final int MSC_TEMPORARILY_NOT_REACHABLE = 2180 /* 0x884 */;
    /**
     * CS domain is not available.
     */
    public static final int CS_DOMAIN_NOT_AVAILABLE = 2181 /* 0x885 */;
    /**
     * ESM level failure.
     */
    public static final int ESM_FAILURE = 2182 /* 0x886 */;
    /**
     * MAC level failure.
     */
    public static final int MAC_FAILURE = 2183 /* 0x887 */;
    /**
     * Synchronization failure.
     */
    public static final int SYNCHRONIZATION_FAILURE = 2184 /* 0x888 */;
    /**
     * UE security capabilities mismatch.
     */
    public static final int UE_SECURITY_CAPABILITIES_MISMATCH = 2185 /* 0x889 */;
    /**
     * Unspecified security mode reject.
     */
    public static final int SECURITY_MODE_REJECTED = 2186 /* 0x88A */;
    /**
     * Unacceptable non-EPS authentication.
     */
    public static final int UNACCEPTABLE_NON_EPS_AUTHENTICATION = 2187 /* 0x88B */;
    /**
     * CS fallback call establishment is not allowed.
     */
    public static final int CS_FALLBACK_CALL_ESTABLISHMENT_NOT_ALLOWED = 2188 /* 0x88C */;
    /**
     * No EPS bearer context was activated.
     */
    public static final int NO_EPS_BEARER_CONTEXT_ACTIVATED = 2189 /* 0x88D */;
    /**
     * Invalid EMM state.
     */
    public static final int INVALID_EMM_STATE = 2190 /* 0x88E */;
    /**
     * Non-Access Spectrum layer failure.
     */
    public static final int NAS_LAYER_FAILURE = 2191 /* 0x88F */;
    /**
     * Multiple PDP call feature is disabled.
     */
    public static final int MULTIPLE_PDP_CALL_NOT_ALLOWED = 2192 /* 0x890 */;
    /**
     * Data call has been brought down because EMBMS is not enabled at the RRC layer.
     */
    public static final int EMBMS_NOT_ENABLED = 2193 /* 0x891 */;
    /**
     * Data call was unsuccessfully transferred during the IRAT handover.
     */
    public static final int IRAT_HANDOVER_FAILED = 2194 /* 0x892 */;
    /**
     * EMBMS data call has been successfully brought down.
     */
    public static final int EMBMS_REGULAR_DEACTIVATION = 2195 /* 0x893 */;
    /**
     * Test loop-back data call has been successfully brought down.
     */
    public static final int TEST_LOOPBACK_REGULAR_DEACTIVATION = 2196 /* 0x894 */;
    /**
     * Lower layer registration failure.
     */
    public static final int LOWER_LAYER_REGISTRATION_FAILURE = 2197 /* 0x895 */;
    /**
     * Network initiates a detach on LTE with error cause "data plan has been replenished or has
     * expired".
     */
    public static final int DATA_PLAN_EXPIRED = 2198 /* 0x896 */;
    /**
     * UMTS interface is brought down due to handover from UMTS to iWLAN.
     */
    public static final int UMTS_HANDOVER_TO_IWLAN = 2199 /* 0x897 */;
    /**
     * Received a connection deny due to general or network busy on EVDO network.
     */
    public static final int EVDO_CONNECTION_DENY_BY_GENERAL_OR_NETWORK_BUSY = 2200 /* 0x898 */;
    /**
     * Received a connection deny due to billing or authentication failure on EVDO network.
     */
    public static final int EVDO_CONNECTION_DENY_BY_BILLING_OR_AUTHENTICATION_FAILURE = 2201 /* 0x899 */;
    /**
     * HDR system has been changed due to redirection or the PRL was not preferred.
     */
    public static final int EVDO_HDR_CHANGED = 2202 /* 0x89A */;
    /**
     * Device exited HDR due to redirection or the PRL was not preferred.
     */
    public static final int EVDO_HDR_EXITED = 2203 /* 0x89B */;
    /**
     * Device does not have an HDR session.
     */
    public static final int EVDO_HDR_NO_SESSION = 2204 /* 0x89C */;
    /**
     * It is ending an HDR call origination in favor of a GPS fix.
     */
    public static final int EVDO_USING_GPS_FIX_INSTEAD_OF_HDR_CALL = 2205 /* 0x89D */;
    /**
     * Connection setup on the HDR system was time out.
     */
    public static final int EVDO_HDR_CONNECTION_SETUP_TIMEOUT = 2206 /* 0x89E */;
    /**
     * Device failed to acquire a co-located HDR for origination.
     */
    public static final int FAILED_TO_ACQUIRE_COLOCATED_HDR = 2207 /* 0x89F */;
    /**
     * OTASP commit is in progress.
     */
    public static final int OTASP_COMMIT_IN_PROGRESS = 2208 /* 0x8A0 */;
    /**
     * Device has no hybrid HDR service.
     */
    public static final int NO_HYBRID_HDR_SERVICE = 2209 /* 0x8A1 */;
    /**
     * HDR module could not be obtained because of the RF locked.
     */
    public static final int HDR_NO_LOCK_GRANTED = 2210 /* 0x8A2 */;
    /**
     * DBM or SMS is in progress.
     */
    public static final int DBM_OR_SMS_IN_PROGRESS = 2211 /* 0x8A3 */;
    /**
     * HDR module released the call due to fade.
     */
    public static final int HDR_FADE = 2212 /* 0x8A4 */;
    /**
     * HDR system access failure.
     */
    public static final int HDR_ACCESS_FAILURE = 2213 /* 0x8A5 */;
    /**
     * P_rev supported by 1 base station is less than 6, which is not supported for a 1X data call.
     * The UE must be in the footprint of BS which has p_rev >= 6 to support this SO33 call.
     */
    public static final int UNSUPPORTED_1X_PREV = 2214 /* 0x8A6 */;
    /**
     * Client ended the data call.
     */
    public static final int LOCAL_END = 2215 /* 0x8A7 */;
    /**
     * Device has no service.
     */
    public static final int NO_SERVICE = 2216 /* 0x8A8 */;
    /**
     * Device lost the system due to fade.
     */
    public static final int FADE = 2217 /* 0x8A9 */;
    /**
     * Receiving a release from the base station with no reason.
     */
    public static final int NORMAL_RELEASE = 2218 /* 0x8AA */;
    /**
     * Access attempt is already in progress.
     */
    public static final int ACCESS_ATTEMPT_ALREADY_IN_PROGRESS = 2219 /* 0x8AB */;
    /**
     * Device is in the process of redirecting or handing off to a different target system.
     */
    public static final int REDIRECTION_OR_HANDOFF_IN_PROGRESS = 2220 /* 0x8AC */;
    /**
     * Device is operating in Emergency mode.
     */
    public static final int EMERGENCY_MODE = 2221 /* 0x8AD */;
    /**
     * Device is in use (e.g., voice call).
     */
    public static final int PHONE_IN_USE = 2222 /* 0x8AE */;
    /**
     * Device operational mode is different from the mode requested in the traffic channel bring up.
     */
    public static final int INVALID_MODE = 2223 /* 0x8AF */;
    /**
     * SIM was marked by the network as invalid for the circuit and/or packet service domain.
     */
    public static final int INVALID_SIM_STATE = 2224 /* 0x8B0 */;
    /**
     * There is no co-located HDR.
     */
    public static final int NO_COLLOCATED_HDR = 2225 /* 0x8B1 */;
    /**
     * UE is entering power save mode.
     */
    public static final int UE_IS_ENTERING_POWERSAVE_MODE = 2226 /* 0x8B2 */;
    /**
     * Dual switch from single standby to dual standby is in progress.
     */
    public static final int DUAL_SWITCH = 2227 /* 0x8B3 */;
    /**
     * Data call bring up fails in the PPP setup due to a timeout. (e.g., an LCP conf ack was not
     * received from the network)
     */
    public static final int PPP_TIMEOUT = 2228 /* 0x8B4 */;
    /**
     * Data call bring up fails in the PPP setup due to an authorization failure.
     * (e.g., authorization is required, but not negotiated with the network during an LCP phase)
     */
    public static final int PPP_AUTH_FAILURE = 2229 /* 0x8B5 */;
    /**
     * Data call bring up fails in the PPP setup due to an option mismatch.
     */
    public static final int PPP_OPTION_MISMATCH = 2230 /* 0x8B6 */;
    /**
     * Data call bring up fails in the PPP setup due to a PAP failure.
     */
    public static final int PPP_PAP_FAILURE = 2231 /* 0x8B7 */;
    /**
     * Data call bring up fails in the PPP setup due to a CHAP failure.
     */
    public static final int PPP_CHAP_FAILURE = 2232 /* 0x8B8 */;
    /**
     * Data call bring up fails in the PPP setup because the PPP is in the process of cleaning the
     * previous PPP session.
     */
    public static final int PPP_CLOSE_IN_PROGRESS = 2233 /* 0x8B9 */;
    /**
     * IPv6 interface bring up fails because the network provided only the IPv4 address for the
     * upcoming PDN permanent client can reattempt a IPv6 call bring up after the IPv4 interface is
     * also brought down. However, there is no guarantee that the network will provide a IPv6
     * address.
     */
    public static final int LIMITED_TO_IPV4 = 2234 /* 0x8BA */;
    /**
     * IPv4 interface bring up fails because the network provided only the IPv6 address for the
     * upcoming PDN permanent client can reattempt a IPv4 call bring up after the IPv6 interface is
     * also brought down. However there is no guarantee that the network will provide a IPv4
     * address.
     */
    public static final int LIMITED_TO_IPV6 = 2235 /* 0x8BB */;
    /**
     * Data call bring up fails in the VSNCP phase due to a VSNCP timeout error.
     */
    public static final int VSNCP_TIMEOUT = 2236 /* 0x8BC */;
    /**
     * Data call bring up fails in the VSNCP phase due to a general error. It's used when there is
     * no other specific error code available to report the failure.
     */
    public static final int VSNCP_GEN_ERROR = 2237 /* 0x8BD */;
    /**
     * Data call bring up fails in the VSNCP phase due to a network rejection of the VSNCP
     * configuration request because the requested APN is unauthorized.
     */
    public static final int VSNCP_APN_UNATHORIZED = 2238 /* 0x8BE */;
    /**
     * Data call bring up fails in the VSNCP phase due to a network rejection of the VSNCP
     * configuration request because the PDN limit has been exceeded.
     */
    public static final int VSNCP_PDN_LIMIT_EXCEEDED = 2239 /* 0x8BF */;
    /**
     * Data call bring up fails in the VSNCP phase due to the network rejected the VSNCP
     * configuration request due to no PDN gateway address.
     */
    public static final int VSNCP_NO_PDN_GATEWAY_ADDRESS = 2240 /* 0x8C0 */;
    /**
     * Data call bring up fails in the VSNCP phase due to a network rejection of the VSNCP
     * configuration request because the PDN gateway is unreachable.
     */
    public static final int VSNCP_PDN_GATEWAY_UNREACHABLE = 2241 /* 0x8C1 */;
    /**
     * Data call bring up fails in the VSNCP phase due to a network rejection of the VSNCP
     * configuration request due to a PDN gateway reject.
     */
    public static final int VSNCP_PDN_GATEWAY_REJECT = 2242 /* 0x8C2 */;
    /**
     * Data call bring up fails in the VSNCP phase due to a network rejection of the VSNCP
     * configuration request with the reason of insufficient parameter.
     */
    public static final int VSNCP_INSUFFICIENT_PARAMETERS = 2243 /* 0x8C3 */;
    /**
     * Data call bring up fails in the VSNCP phase due to a network rejection of the VSNCP
     * configuration request with the reason of resource unavailable.
     */
    public static final int VSNCP_RESOURCE_UNAVAILABLE = 2244 /* 0x8C4 */;
    /**
     * Data call bring up fails in the VSNCP phase due to a network rejection of the VSNCP
     * configuration request with the reason of administratively prohibited at the HSGW.
     */
    public static final int VSNCP_ADMINISTRATIVELY_PROHIBITED = 2245 /* 0x8C5 */;
    /**
     * Data call bring up fails in the VSNCP phase due to a network rejection of PDN ID in use, or
     * all existing PDNs are brought down with this end reason because one of the PDN bring up was
     * rejected by the network with the reason of PDN ID in use.
     */
    public static final int VSNCP_PDN_ID_IN_USE = 2246 /* 0x8C6 */;
    /**
     * Data call bring up fails in the VSNCP phase due to a network rejection of the VSNCP
     * configuration request for the reason of subscriber limitation.
     */
    public static final int VSNCP_SUBSCRIBER_LIMITATION = 2247 /* 0x8C7 */;
    /**
     * Data call bring up fails in the VSNCP phase due to a network rejection of the VSNCP
     * configuration request because the PDN exists for this APN.
     */
    public static final int VSNCP_PDN_EXISTS_FOR_THIS_APN = 2248 /* 0x8C8 */;
    /**
     * Data call bring up fails in the VSNCP phase due to a network rejection of the VSNCP
     * configuration request with reconnect to this PDN not allowed, or an active data call is
     * terminated by the network because reconnection to this PDN is not allowed. Upon receiving
     * this error code from the network, the modem infinitely throttles the PDN until the next power
     * cycle.
     */
    public static final int VSNCP_RECONNECT_NOT_ALLOWED = 2249 /* 0x8C9 */;
    /**
     * Device failure to obtain the prefix from the network.
     */
    public static final int IPV6_PREFIX_UNAVAILABLE = 2250 /* 0x8CA */;
    /**
     * System preference change back to SRAT during handoff
     */
    public static final int HANDOFF_PREFERENCE_CHANGED = 2251 /* 0x8CB */;
    public static final String toString(int o) {
        if (o == NONE) {
            return "NONE";
        }
        if (o == OPERATOR_BARRED) {
            return "OPERATOR_BARRED";
        }
        if (o == NAS_SIGNALLING) {
            return "NAS_SIGNALLING";
        }
        if (o == INSUFFICIENT_RESOURCES) {
            return "INSUFFICIENT_RESOURCES";
        }
        if (o == MISSING_UKNOWN_APN) {
            return "MISSING_UKNOWN_APN";
        }
        if (o == UNKNOWN_PDP_ADDRESS_TYPE) {
            return "UNKNOWN_PDP_ADDRESS_TYPE";
        }
        if (o == USER_AUTHENTICATION) {
            return "USER_AUTHENTICATION";
        }
        if (o == ACTIVATION_REJECT_GGSN) {
            return "ACTIVATION_REJECT_GGSN";
        }
        if (o == ACTIVATION_REJECT_UNSPECIFIED) {
            return "ACTIVATION_REJECT_UNSPECIFIED";
        }
        if (o == SERVICE_OPTION_NOT_SUPPORTED) {
            return "SERVICE_OPTION_NOT_SUPPORTED";
        }
        if (o == SERVICE_OPTION_NOT_SUBSCRIBED) {
            return "SERVICE_OPTION_NOT_SUBSCRIBED";
        }
        if (o == SERVICE_OPTION_OUT_OF_ORDER) {
            return "SERVICE_OPTION_OUT_OF_ORDER";
        }
        if (o == NSAPI_IN_USE) {
            return "NSAPI_IN_USE";
        }
        if (o == REGULAR_DEACTIVATION) {
            return "REGULAR_DEACTIVATION";
        }
        if (o == QOS_NOT_ACCEPTED) {
            return "QOS_NOT_ACCEPTED";
        }
        if (o == NETWORK_FAILURE) {
            return "NETWORK_FAILURE";
        }
        if (o == UMTS_REACTIVATION_REQ) {
            return "UMTS_REACTIVATION_REQ";
        }
        if (o == FEATURE_NOT_SUPP) {
            return "FEATURE_NOT_SUPP";
        }
        if (o == TFT_SEMANTIC_ERROR) {
            return "TFT_SEMANTIC_ERROR";
        }
        if (o == TFT_SYTAX_ERROR) {
            return "TFT_SYTAX_ERROR";
        }
        if (o == UNKNOWN_PDP_CONTEXT) {
            return "UNKNOWN_PDP_CONTEXT";
        }
        if (o == FILTER_SEMANTIC_ERROR) {
            return "FILTER_SEMANTIC_ERROR";
        }
        if (o == FILTER_SYTAX_ERROR) {
            return "FILTER_SYTAX_ERROR";
        }
        if (o == PDP_WITHOUT_ACTIVE_TFT) {
            return "PDP_WITHOUT_ACTIVE_TFT";
        }
        if (o == ONLY_IPV4_ALLOWED) {
            return "ONLY_IPV4_ALLOWED";
        }
        if (o == ONLY_IPV6_ALLOWED) {
            return "ONLY_IPV6_ALLOWED";
        }
        if (o == ONLY_SINGLE_BEARER_ALLOWED) {
            return "ONLY_SINGLE_BEARER_ALLOWED";
        }
        if (o == ESM_INFO_NOT_RECEIVED) {
            return "ESM_INFO_NOT_RECEIVED";
        }
        if (o == PDN_CONN_DOES_NOT_EXIST) {
            return "PDN_CONN_DOES_NOT_EXIST";
        }
        if (o == MULTI_CONN_TO_SAME_PDN_NOT_ALLOWED) {
            return "MULTI_CONN_TO_SAME_PDN_NOT_ALLOWED";
        }
        if (o == MAX_ACTIVE_PDP_CONTEXT_REACHED) {
            return "MAX_ACTIVE_PDP_CONTEXT_REACHED";
        }
        if (o == UNSUPPORTED_APN_IN_CURRENT_PLMN) {
            return "UNSUPPORTED_APN_IN_CURRENT_PLMN";
        }
        if (o == INVALID_TRANSACTION_ID) {
            return "INVALID_TRANSACTION_ID";
        }
        if (o == MESSAGE_INCORRECT_SEMANTIC) {
            return "MESSAGE_INCORRECT_SEMANTIC";
        }
        if (o == INVALID_MANDATORY_INFO) {
            return "INVALID_MANDATORY_INFO";
        }
        if (o == MESSAGE_TYPE_UNSUPPORTED) {
            return "MESSAGE_TYPE_UNSUPPORTED";
        }
        if (o == MSG_TYPE_NONCOMPATIBLE_STATE) {
            return "MSG_TYPE_NONCOMPATIBLE_STATE";
        }
        if (o == UNKNOWN_INFO_ELEMENT) {
            return "UNKNOWN_INFO_ELEMENT";
        }
        if (o == CONDITIONAL_IE_ERROR) {
            return "CONDITIONAL_IE_ERROR";
        }
        if (o == MSG_AND_PROTOCOL_STATE_UNCOMPATIBLE) {
            return "MSG_AND_PROTOCOL_STATE_UNCOMPATIBLE";
        }
        if (o == PROTOCOL_ERRORS) {
            return "PROTOCOL_ERRORS";
        }
        if (o == APN_TYPE_CONFLICT) {
            return "APN_TYPE_CONFLICT";
        }
        if (o == INVALID_PCSCF_ADDR) {
            return "INVALID_PCSCF_ADDR";
        }
        if (o == INTERNAL_CALL_PREEMPT_BY_HIGH_PRIO_APN) {
            return "INTERNAL_CALL_PREEMPT_BY_HIGH_PRIO_APN";
        }
        if (o == EMM_ACCESS_BARRED) {
            return "EMM_ACCESS_BARRED";
        }
        if (o == EMERGENCY_IFACE_ONLY) {
            return "EMERGENCY_IFACE_ONLY";
        }
        if (o == IFACE_MISMATCH) {
            return "IFACE_MISMATCH";
        }
        if (o == COMPANION_IFACE_IN_USE) {
            return "COMPANION_IFACE_IN_USE";
        }
        if (o == IP_ADDRESS_MISMATCH) {
            return "IP_ADDRESS_MISMATCH";
        }
        if (o == IFACE_AND_POL_FAMILY_MISMATCH) {
            return "IFACE_AND_POL_FAMILY_MISMATCH";
        }
        if (o == EMM_ACCESS_BARRED_INFINITE_RETRY) {
            return "EMM_ACCESS_BARRED_INFINITE_RETRY";
        }
        if (o == AUTH_FAILURE_ON_EMERGENCY_CALL) {
            return "AUTH_FAILURE_ON_EMERGENCY_CALL";
        }
        if (o == OEM_DCFAILCAUSE_1) {
            return "OEM_DCFAILCAUSE_1";
        }
        if (o == OEM_DCFAILCAUSE_2) {
            return "OEM_DCFAILCAUSE_2";
        }
        if (o == OEM_DCFAILCAUSE_3) {
            return "OEM_DCFAILCAUSE_3";
        }
        if (o == OEM_DCFAILCAUSE_4) {
            return "OEM_DCFAILCAUSE_4";
        }
        if (o == OEM_DCFAILCAUSE_5) {
            return "OEM_DCFAILCAUSE_5";
        }
        if (o == OEM_DCFAILCAUSE_6) {
            return "OEM_DCFAILCAUSE_6";
        }
        if (o == OEM_DCFAILCAUSE_7) {
            return "OEM_DCFAILCAUSE_7";
        }
        if (o == OEM_DCFAILCAUSE_8) {
            return "OEM_DCFAILCAUSE_8";
        }
        if (o == OEM_DCFAILCAUSE_9) {
            return "OEM_DCFAILCAUSE_9";
        }
        if (o == OEM_DCFAILCAUSE_10) {
            return "OEM_DCFAILCAUSE_10";
        }
        if (o == OEM_DCFAILCAUSE_11) {
            return "OEM_DCFAILCAUSE_11";
        }
        if (o == OEM_DCFAILCAUSE_12) {
            return "OEM_DCFAILCAUSE_12";
        }
        if (o == OEM_DCFAILCAUSE_13) {
            return "OEM_DCFAILCAUSE_13";
        }
        if (o == OEM_DCFAILCAUSE_14) {
            return "OEM_DCFAILCAUSE_14";
        }
        if (o == OEM_DCFAILCAUSE_15) {
            return "OEM_DCFAILCAUSE_15";
        }
        if (o == VOICE_REGISTRATION_FAIL) {
            return "VOICE_REGISTRATION_FAIL";
        }
        if (o == DATA_REGISTRATION_FAIL) {
            return "DATA_REGISTRATION_FAIL";
        }
        if (o == SIGNAL_LOST) {
            return "SIGNAL_LOST";
        }
        if (o == PREF_RADIO_TECH_CHANGED) {
            return "PREF_RADIO_TECH_CHANGED";
        }
        if (o == RADIO_POWER_OFF) {
            return "RADIO_POWER_OFF";
        }
        if (o == TETHERED_CALL_ACTIVE) {
            return "TETHERED_CALL_ACTIVE";
        }
        if (o == ERROR_UNSPECIFIED) {
            return "ERROR_UNSPECIFIED";
        }
        if (o == LLC_SNDCP) {
            return "LLC_SNDCP";
        }
        if (o == ACTIVATION_REJECTED_BCM_VIOLATION) {
            return "ACTIVATION_REJECTED_BCM_VIOLATION";
        }
        if (o == COLLISION_WITH_NETWORK_INITIATED_REQUEST) {
            return "COLLISION_WITH_NETWORK_INITIATED_REQUEST";
        }
        if (o == ONLY_IPV4V6_ALLOWED) {
            return "ONLY_IPV4V6_ALLOWED";
        }
        if (o == ONLY_NON_IP_ALLOWED) {
            return "ONLY_NON_IP_ALLOWED";
        }
        if (o == UNSUPPORTED_QCI_VALUE) {
            return "UNSUPPORTED_QCI_VALUE";
        }
        if (o == BEARER_HANDLING_NOT_SUPPORTED) {
            return "BEARER_HANDLING_NOT_SUPPORTED";
        }
        if (o == INVALID_DNS_ADDR) {
            return "INVALID_DNS_ADDR";
        }
        if (o == INVALID_PCSCF_OR_DNS_ADDRESS) {
            return "INVALID_PCSCF_OR_DNS_ADDRESS";
        }
        if (o == CALL_PREEMPT_BY_EMERGENCY_APN) {
            return "CALL_PREEMPT_BY_EMERGENCY_APN";
        }
        if (o == UE_INITIATED_DETACH_OR_DISCONNECT) {
            return "UE_INITIATED_DETACH_OR_DISCONNECT";
        }
        if (o == MIP_FA_REASON_UNSPECIFIED) {
            return "MIP_FA_REASON_UNSPECIFIED";
        }
        if (o == MIP_FA_ADMIN_PROHIBITED) {
            return "MIP_FA_ADMIN_PROHIBITED";
        }
        if (o == MIP_FA_INSUFFICIENT_RESOURCES) {
            return "MIP_FA_INSUFFICIENT_RESOURCES";
        }
        if (o == MIP_FA_MOBILE_NODE_AUTHENTICATION_FAILURE) {
            return "MIP_FA_MOBILE_NODE_AUTHENTICATION_FAILURE";
        }
        if (o == MIP_FA_HOME_AGENT_AUTHENTICATION_FAILURE) {
            return "MIP_FA_HOME_AGENT_AUTHENTICATION_FAILURE";
        }
        if (o == MIP_FA_REQUESTED_LIFETIME_TOO_LONG) {
            return "MIP_FA_REQUESTED_LIFETIME_TOO_LONG";
        }
        if (o == MIP_FA_MALFORMED_REQUEST) {
            return "MIP_FA_MALFORMED_REQUEST";
        }
        if (o == MIP_FA_MALFORMED_REPLY) {
            return "MIP_FA_MALFORMED_REPLY";
        }
        if (o == MIP_FA_ENCAPSULATION_UNAVAILABLE) {
            return "MIP_FA_ENCAPSULATION_UNAVAILABLE";
        }
        if (o == MIP_FA_VJ_HEADER_COMPRESSION_UNAVAILABLE) {
            return "MIP_FA_VJ_HEADER_COMPRESSION_UNAVAILABLE";
        }
        if (o == MIP_FA_REVERSE_TUNNEL_UNAVAILABLE) {
            return "MIP_FA_REVERSE_TUNNEL_UNAVAILABLE";
        }
        if (o == MIP_FA_REVERSE_TUNNEL_IS_MANDATORY) {
            return "MIP_FA_REVERSE_TUNNEL_IS_MANDATORY";
        }
        if (o == MIP_FA_DELIVERY_STYLE_NOT_SUPPORTED) {
            return "MIP_FA_DELIVERY_STYLE_NOT_SUPPORTED";
        }
        if (o == MIP_FA_MISSING_NAI) {
            return "MIP_FA_MISSING_NAI";
        }
        if (o == MIP_FA_MISSING_HOME_AGENT) {
            return "MIP_FA_MISSING_HOME_AGENT";
        }
        if (o == MIP_FA_MISSING_HOME_ADDRESS) {
            return "MIP_FA_MISSING_HOME_ADDRESS";
        }
        if (o == MIP_FA_UNKNOWN_CHALLENGE) {
            return "MIP_FA_UNKNOWN_CHALLENGE";
        }
        if (o == MIP_FA_MISSING_CHALLENGE) {
            return "MIP_FA_MISSING_CHALLENGE";
        }
        if (o == MIP_FA_STALE_CHALLENGE) {
            return "MIP_FA_STALE_CHALLENGE";
        }
        if (o == MIP_HA_REASON_UNSPECIFIED) {
            return "MIP_HA_REASON_UNSPECIFIED";
        }
        if (o == MIP_HA_ADMIN_PROHIBITED) {
            return "MIP_HA_ADMIN_PROHIBITED";
        }
        if (o == MIP_HA_INSUFFICIENT_RESOURCES) {
            return "MIP_HA_INSUFFICIENT_RESOURCES";
        }
        if (o == MIP_HA_MOBILE_NODE_AUTHENTICATION_FAILURE) {
            return "MIP_HA_MOBILE_NODE_AUTHENTICATION_FAILURE";
        }
        if (o == MIP_HA_FOREIGN_AGENT_AUTHENTICATION_FAILURE) {
            return "MIP_HA_FOREIGN_AGENT_AUTHENTICATION_FAILURE";
        }
        if (o == MIP_HA_REGISTRATION_ID_MISMATCH) {
            return "MIP_HA_REGISTRATION_ID_MISMATCH";
        }
        if (o == MIP_HA_MALFORMED_REQUEST) {
            return "MIP_HA_MALFORMED_REQUEST";
        }
        if (o == MIP_HA_UNKNOWN_HOME_AGENT_ADDRESS) {
            return "MIP_HA_UNKNOWN_HOME_AGENT_ADDRESS";
        }
        if (o == MIP_HA_REVERSE_TUNNEL_UNAVAILABLE) {
            return "MIP_HA_REVERSE_TUNNEL_UNAVAILABLE";
        }
        if (o == MIP_HA_REVERSE_TUNNEL_IS_MANDATORY) {
            return "MIP_HA_REVERSE_TUNNEL_IS_MANDATORY";
        }
        if (o == MIP_HA_ENCAPSULATION_UNAVAILABLE) {
            return "MIP_HA_ENCAPSULATION_UNAVAILABLE";
        }
        if (o == CLOSE_IN_PROGRESS) {
            return "CLOSE_IN_PROGRESS";
        }
        if (o == NETWORK_INITIATED_TERMINATION) {
            return "NETWORK_INITIATED_TERMINATION";
        }
        if (o == MODEM_APP_PREEMPTED) {
            return "MODEM_APP_PREEMPTED";
        }
        if (o == PDN_IPV4_CALL_DISALLOWED) {
            return "PDN_IPV4_CALL_DISALLOWED";
        }
        if (o == PDN_IPV4_CALL_THROTTLED) {
            return "PDN_IPV4_CALL_THROTTLED";
        }
        if (o == PDN_IPV6_CALL_DISALLOWED) {
            return "PDN_IPV6_CALL_DISALLOWED";
        }
        if (o == PDN_IPV6_CALL_THROTTLED) {
            return "PDN_IPV6_CALL_THROTTLED";
        }
        if (o == MODEM_RESTART) {
            return "MODEM_RESTART";
        }
        if (o == PDP_PPP_NOT_SUPPORTED) {
            return "PDP_PPP_NOT_SUPPORTED";
        }
        if (o == UNPREFERRED_RAT) {
            return "UNPREFERRED_RAT";
        }
        if (o == PHYSICAL_LINK_CLOSE_IN_PROGRESS) {
            return "PHYSICAL_LINK_CLOSE_IN_PROGRESS";
        }
        if (o == APN_PENDING_HANDOVER) {
            return "APN_PENDING_HANDOVER";
        }
        if (o == PROFILE_BEARER_INCOMPATIBLE) {
            return "PROFILE_BEARER_INCOMPATIBLE";
        }
        if (o == SIM_CARD_CHANGED) {
            return "SIM_CARD_CHANGED";
        }
        if (o == LOW_POWER_MODE_OR_POWERING_DOWN) {
            return "LOW_POWER_MODE_OR_POWERING_DOWN";
        }
        if (o == APN_DISABLED) {
            return "APN_DISABLED";
        }
        if (o == MAX_PPP_INACTIVITY_TIMER_EXPIRED) {
            return "MAX_PPP_INACTIVITY_TIMER_EXPIRED";
        }
        if (o == IPV6_ADDRESS_TRANSFER_FAILED) {
            return "IPV6_ADDRESS_TRANSFER_FAILED";
        }
        if (o == TRAT_SWAP_FAILED) {
            return "TRAT_SWAP_FAILED";
        }
        if (o == EHRPD_TO_HRPD_FALLBACK) {
            return "EHRPD_TO_HRPD_FALLBACK";
        }
        if (o == MIP_CONFIG_FAILURE) {
            return "MIP_CONFIG_FAILURE";
        }
        if (o == PDN_INACTIVITY_TIMER_EXPIRED) {
            return "PDN_INACTIVITY_TIMER_EXPIRED";
        }
        if (o == MAX_IPV4_CONNECTIONS) {
            return "MAX_IPV4_CONNECTIONS";
        }
        if (o == MAX_IPV6_CONNECTIONS) {
            return "MAX_IPV6_CONNECTIONS";
        }
        if (o == APN_MISMATCH) {
            return "APN_MISMATCH";
        }
        if (o == IP_VERSION_MISMATCH) {
            return "IP_VERSION_MISMATCH";
        }
        if (o == DUN_CALL_DISALLOWED) {
            return "DUN_CALL_DISALLOWED";
        }
        if (o == INTERNAL_EPC_NONEPC_TRANSITION) {
            return "INTERNAL_EPC_NONEPC_TRANSITION";
        }
        if (o == INTERFACE_IN_USE) {
            return "INTERFACE_IN_USE";
        }
        if (o == APN_DISALLOWED_ON_ROAMING) {
            return "APN_DISALLOWED_ON_ROAMING";
        }
        if (o == APN_PARAMETERS_CHANGED) {
            return "APN_PARAMETERS_CHANGED";
        }
        if (o == NULL_APN_DISALLOWED) {
            return "NULL_APN_DISALLOWED";
        }
        if (o == THERMAL_MITIGATION) {
            return "THERMAL_MITIGATION";
        }
        if (o == DATA_SETTINGS_DISABLED) {
            return "DATA_SETTINGS_DISABLED";
        }
        if (o == DATA_ROAMING_SETTINGS_DISABLED) {
            return "DATA_ROAMING_SETTINGS_DISABLED";
        }
        if (o == DDS_SWITCHED) {
            return "DDS_SWITCHED";
        }
        if (o == FORBIDDEN_APN_NAME) {
            return "FORBIDDEN_APN_NAME";
        }
        if (o == DDS_SWITCH_IN_PROGRESS) {
            return "DDS_SWITCH_IN_PROGRESS";
        }
        if (o == CALL_DISALLOWED_IN_ROAMING) {
            return "CALL_DISALLOWED_IN_ROAMING";
        }
        if (o == NON_IP_NOT_SUPPORTED) {
            return "NON_IP_NOT_SUPPORTED";
        }
        if (o == PDN_NON_IP_CALL_THROTTLED) {
            return "PDN_NON_IP_CALL_THROTTLED";
        }
        if (o == PDN_NON_IP_CALL_DISALLOWED) {
            return "PDN_NON_IP_CALL_DISALLOWED";
        }
        if (o == CDMA_LOCK) {
            return "CDMA_LOCK";
        }
        if (o == CDMA_INTERCEPT) {
            return "CDMA_INTERCEPT";
        }
        if (o == CDMA_REORDER) {
            return "CDMA_REORDER";
        }
        if (o == CDMA_RELEASE_DUE_TO_SO_REJECTION) {
            return "CDMA_RELEASE_DUE_TO_SO_REJECTION";
        }
        if (o == CDMA_INCOMING_CALL) {
            return "CDMA_INCOMING_CALL";
        }
        if (o == CDMA_ALERT_STOP) {
            return "CDMA_ALERT_STOP";
        }
        if (o == CHANNEL_ACQUISITION_FAILURE) {
            return "CHANNEL_ACQUISITION_FAILURE";
        }
        if (o == MAX_ACCESS_PROBE) {
            return "MAX_ACCESS_PROBE";
        }
        if (o == CONCURRENT_SERVICE_NOT_SUPPORTED_BY_BASE_STATION) {
            return "CONCURRENT_SERVICE_NOT_SUPPORTED_BY_BASE_STATION";
        }
        if (o == NO_RESPONSE_FROM_BASE_STATION) {
            return "NO_RESPONSE_FROM_BASE_STATION";
        }
        if (o == REJECTED_BY_BASE_STATION) {
            return "REJECTED_BY_BASE_STATION";
        }
        if (o == CONCURRENT_SERVICES_INCOMPATIBLE) {
            return "CONCURRENT_SERVICES_INCOMPATIBLE";
        }
        if (o == NO_CDMA_SERVICE) {
            return "NO_CDMA_SERVICE";
        }
        if (o == RUIM_NOT_PRESENT) {
            return "RUIM_NOT_PRESENT";
        }
        if (o == CDMA_RETRY_ORDER) {
            return "CDMA_RETRY_ORDER";
        }
        if (o == ACCESS_BLOCK) {
            return "ACCESS_BLOCK";
        }
        if (o == ACCESS_BLOCK_ALL) {
            return "ACCESS_BLOCK_ALL";
        }
        if (o == IS707B_MAX_ACCESS_PROBES) {
            return "IS707B_MAX_ACCESS_PROBES";
        }
        if (o == THERMAL_EMERGENCY) {
            return "THERMAL_EMERGENCY";
        }
        if (o == CONCURRENT_SERVICES_NOT_ALLOWED) {
            return "CONCURRENT_SERVICES_NOT_ALLOWED";
        }
        if (o == INCOMING_CALL_REJECTED) {
            return "INCOMING_CALL_REJECTED";
        }
        if (o == NO_SERVICE_ON_GATEWAY) {
            return "NO_SERVICE_ON_GATEWAY";
        }
        if (o == NO_GPRS_CONTEXT) {
            return "NO_GPRS_CONTEXT";
        }
        if (o == ILLEGAL_MS) {
            return "ILLEGAL_MS";
        }
        if (o == ILLEGAL_ME) {
            return "ILLEGAL_ME";
        }
        if (o == GPRS_SERVICES_AND_NON_GPRS_SERVICES_NOT_ALLOWED) {
            return "GPRS_SERVICES_AND_NON_GPRS_SERVICES_NOT_ALLOWED";
        }
        if (o == GPRS_SERVICES_NOT_ALLOWED) {
            return "GPRS_SERVICES_NOT_ALLOWED";
        }
        if (o == MS_IDENTITY_CANNOT_BE_DERIVED_BY_THE_NETWORK) {
            return "MS_IDENTITY_CANNOT_BE_DERIVED_BY_THE_NETWORK";
        }
        if (o == IMPLICITLY_DETACHED) {
            return "IMPLICITLY_DETACHED";
        }
        if (o == PLMN_NOT_ALLOWED) {
            return "PLMN_NOT_ALLOWED";
        }
        if (o == LOCATION_AREA_NOT_ALLOWED) {
            return "LOCATION_AREA_NOT_ALLOWED";
        }
        if (o == GPRS_SERVICES_NOT_ALLOWED_IN_THIS_PLMN) {
            return "GPRS_SERVICES_NOT_ALLOWED_IN_THIS_PLMN";
        }
        if (o == PDP_DUPLICATE) {
            return "PDP_DUPLICATE";
        }
        if (o == UE_RAT_CHANGE) {
            return "UE_RAT_CHANGE";
        }
        if (o == CONGESTION) {
            return "CONGESTION";
        }
        if (o == NO_PDP_CONTEXT_ACTIVATED) {
            return "NO_PDP_CONTEXT_ACTIVATED";
        }
        if (o == ACCESS_CLASS_DSAC_REJECTION) {
            return "ACCESS_CLASS_DSAC_REJECTION";
        }
        if (o == PDP_ACTIVATE_MAX_RETRY_FAILED) {
            return "PDP_ACTIVATE_MAX_RETRY_FAILED";
        }
        if (o == RADIO_ACCESS_BEARER_FAILURE) {
            return "RADIO_ACCESS_BEARER_FAILURE";
        }
        if (o == ESM_UNKNOWN_EPS_BEARER_CONTEXT) {
            return "ESM_UNKNOWN_EPS_BEARER_CONTEXT";
        }
        if (o == DRB_RELEASED_BY_RRC) {
            return "DRB_RELEASED_BY_RRC";
        }
        if (o == CONNECTION_RELEASED) {
            return "CONNECTION_RELEASED";
        }
        if (o == EMM_DETACHED) {
            return "EMM_DETACHED";
        }
        if (o == EMM_ATTACH_FAILED) {
            return "EMM_ATTACH_FAILED";
        }
        if (o == EMM_ATTACH_STARTED) {
            return "EMM_ATTACH_STARTED";
        }
        if (o == LTE_NAS_SERVICE_REQUEST_FAILED) {
            return "LTE_NAS_SERVICE_REQUEST_FAILED";
        }
        if (o == DUPLICATE_BEARER_ID) {
            return "DUPLICATE_BEARER_ID";
        }
        if (o == ESM_COLLISION_SCENARIOS) {
            return "ESM_COLLISION_SCENARIOS";
        }
        if (o == ESM_BEARER_DEACTIVATED_TO_SYNC_WITH_NETWORK) {
            return "ESM_BEARER_DEACTIVATED_TO_SYNC_WITH_NETWORK";
        }
        if (o == ESM_NW_ACTIVATED_DED_BEARER_WITH_ID_OF_DEF_BEARER) {
            return "ESM_NW_ACTIVATED_DED_BEARER_WITH_ID_OF_DEF_BEARER";
        }
        if (o == ESM_BAD_OTA_MESSAGE) {
            return "ESM_BAD_OTA_MESSAGE";
        }
        if (o == ESM_DOWNLOAD_SERVER_REJECTED_THE_CALL) {
            return "ESM_DOWNLOAD_SERVER_REJECTED_THE_CALL";
        }
        if (o == ESM_CONTEXT_TRANSFERRED_DUE_TO_IRAT) {
            return "ESM_CONTEXT_TRANSFERRED_DUE_TO_IRAT";
        }
        if (o == DS_EXPLICIT_DEACTIVATION) {
            return "DS_EXPLICIT_DEACTIVATION";
        }
        if (o == ESM_LOCAL_CAUSE_NONE) {
            return "ESM_LOCAL_CAUSE_NONE";
        }
        if (o == LTE_THROTTLING_NOT_REQUIRED) {
            return "LTE_THROTTLING_NOT_REQUIRED";
        }
        if (o == ACCESS_CONTROL_LIST_CHECK_FAILURE) {
            return "ACCESS_CONTROL_LIST_CHECK_FAILURE";
        }
        if (o == SERVICE_NOT_ALLOWED_ON_PLMN) {
            return "SERVICE_NOT_ALLOWED_ON_PLMN";
        }
        if (o == EMM_T3417_EXPIRED) {
            return "EMM_T3417_EXPIRED";
        }
        if (o == EMM_T3417_EXT_EXPIRED) {
            return "EMM_T3417_EXT_EXPIRED";
        }
        if (o == RRC_UPLINK_DATA_TRANSMISSION_FAILURE) {
            return "RRC_UPLINK_DATA_TRANSMISSION_FAILURE";
        }
        if (o == RRC_UPLINK_DELIVERY_FAILED_DUE_TO_HANDOVER) {
            return "RRC_UPLINK_DELIVERY_FAILED_DUE_TO_HANDOVER";
        }
        if (o == RRC_UPLINK_CONNECTION_RELEASE) {
            return "RRC_UPLINK_CONNECTION_RELEASE";
        }
        if (o == RRC_UPLINK_RADIO_LINK_FAILURE) {
            return "RRC_UPLINK_RADIO_LINK_FAILURE";
        }
        if (o == RRC_UPLINK_ERROR_REQUEST_FROM_NAS) {
            return "RRC_UPLINK_ERROR_REQUEST_FROM_NAS";
        }
        if (o == RRC_CONNECTION_ACCESS_STRATUM_FAILURE) {
            return "RRC_CONNECTION_ACCESS_STRATUM_FAILURE";
        }
        if (o == RRC_CONNECTION_ANOTHER_PROCEDURE_IN_PROGRESS) {
            return "RRC_CONNECTION_ANOTHER_PROCEDURE_IN_PROGRESS";
        }
        if (o == RRC_CONNECTION_ACCESS_BARRED) {
            return "RRC_CONNECTION_ACCESS_BARRED";
        }
        if (o == RRC_CONNECTION_CELL_RESELECTION) {
            return "RRC_CONNECTION_CELL_RESELECTION";
        }
        if (o == RRC_CONNECTION_CONFIG_FAILURE) {
            return "RRC_CONNECTION_CONFIG_FAILURE";
        }
        if (o == RRC_CONNECTION_TIMER_EXPIRED) {
            return "RRC_CONNECTION_TIMER_EXPIRED";
        }
        if (o == RRC_CONNECTION_LINK_FAILURE) {
            return "RRC_CONNECTION_LINK_FAILURE";
        }
        if (o == RRC_CONNECTION_CELL_NOT_CAMPED) {
            return "RRC_CONNECTION_CELL_NOT_CAMPED";
        }
        if (o == RRC_CONNECTION_SYSTEM_INTERVAL_FAILURE) {
            return "RRC_CONNECTION_SYSTEM_INTERVAL_FAILURE";
        }
        if (o == RRC_CONNECTION_REJECT_BY_NETWORK) {
            return "RRC_CONNECTION_REJECT_BY_NETWORK";
        }
        if (o == RRC_CONNECTION_NORMAL_RELEASE) {
            return "RRC_CONNECTION_NORMAL_RELEASE";
        }
        if (o == RRC_CONNECTION_RADIO_LINK_FAILURE) {
            return "RRC_CONNECTION_RADIO_LINK_FAILURE";
        }
        if (o == RRC_CONNECTION_REESTABLISHMENT_FAILURE) {
            return "RRC_CONNECTION_REESTABLISHMENT_FAILURE";
        }
        if (o == RRC_CONNECTION_OUT_OF_SERVICE_DURING_CELL_REGISTER) {
            return "RRC_CONNECTION_OUT_OF_SERVICE_DURING_CELL_REGISTER";
        }
        if (o == RRC_CONNECTION_ABORT_REQUEST) {
            return "RRC_CONNECTION_ABORT_REQUEST";
        }
        if (o == RRC_CONNECTION_SYSTEM_INFORMATION_BLOCK_READ_ERROR) {
            return "RRC_CONNECTION_SYSTEM_INFORMATION_BLOCK_READ_ERROR";
        }
        if (o == NETWORK_INITIATED_DETACH_WITH_AUTO_REATTACH) {
            return "NETWORK_INITIATED_DETACH_WITH_AUTO_REATTACH";
        }
        if (o == NETWORK_INITIATED_DETACH_NO_AUTO_REATTACH) {
            return "NETWORK_INITIATED_DETACH_NO_AUTO_REATTACH";
        }
        if (o == ESM_PROCEDURE_TIME_OUT) {
            return "ESM_PROCEDURE_TIME_OUT";
        }
        if (o == INVALID_CONNECTION_ID) {
            return "INVALID_CONNECTION_ID";
        }
        if (o == MAXIMIUM_NSAPIS_EXCEEDED) {
            return "MAXIMIUM_NSAPIS_EXCEEDED";
        }
        if (o == INVALID_PRIMARY_NSAPI) {
            return "INVALID_PRIMARY_NSAPI";
        }
        if (o == CANNOT_ENCODE_OTA_MESSAGE) {
            return "CANNOT_ENCODE_OTA_MESSAGE";
        }
        if (o == RADIO_ACCESS_BEARER_SETUP_FAILURE) {
            return "RADIO_ACCESS_BEARER_SETUP_FAILURE";
        }
        if (o == PDP_ESTABLISH_TIMEOUT_EXPIRED) {
            return "PDP_ESTABLISH_TIMEOUT_EXPIRED";
        }
        if (o == PDP_MODIFY_TIMEOUT_EXPIRED) {
            return "PDP_MODIFY_TIMEOUT_EXPIRED";
        }
        if (o == PDP_INACTIVE_TIMEOUT_EXPIRED) {
            return "PDP_INACTIVE_TIMEOUT_EXPIRED";
        }
        if (o == PDP_LOWERLAYER_ERROR) {
            return "PDP_LOWERLAYER_ERROR";
        }
        if (o == PDP_MODIFY_COLLISION) {
            return "PDP_MODIFY_COLLISION";
        }
        if (o == MAXINUM_SIZE_OF_L2_MESSAGE_EXCEEDED) {
            return "MAXINUM_SIZE_OF_L2_MESSAGE_EXCEEDED";
        }
        if (o == NAS_REQUEST_REJECTED_BY_NETWORK) {
            return "NAS_REQUEST_REJECTED_BY_NETWORK";
        }
        if (o == RRC_CONNECTION_INVALID_REQUEST) {
            return "RRC_CONNECTION_INVALID_REQUEST";
        }
        if (o == RRC_CONNECTION_TRACKING_AREA_ID_CHANGED) {
            return "RRC_CONNECTION_TRACKING_AREA_ID_CHANGED";
        }
        if (o == RRC_CONNECTION_RF_UNAVAILABLE) {
            return "RRC_CONNECTION_RF_UNAVAILABLE";
        }
        if (o == RRC_CONNECTION_ABORTED_DUE_TO_IRAT_CHANGE) {
            return "RRC_CONNECTION_ABORTED_DUE_TO_IRAT_CHANGE";
        }
        if (o == RRC_CONNECTION_RELEASED_SECURITY_NOT_ACTIVE) {
            return "RRC_CONNECTION_RELEASED_SECURITY_NOT_ACTIVE";
        }
        if (o == RRC_CONNECTION_ABORTED_AFTER_HANDOVER) {
            return "RRC_CONNECTION_ABORTED_AFTER_HANDOVER";
        }
        if (o == RRC_CONNECTION_ABORTED_AFTER_IRAT_CELL_CHANGE) {
            return "RRC_CONNECTION_ABORTED_AFTER_IRAT_CELL_CHANGE";
        }
        if (o == RRC_CONNECTION_ABORTED_DURING_IRAT_CELL_CHANGE) {
            return "RRC_CONNECTION_ABORTED_DURING_IRAT_CELL_CHANGE";
        }
        if (o == IMSI_UNKNOWN_IN_HOME_SUBSCRIBER_SERVER) {
            return "IMSI_UNKNOWN_IN_HOME_SUBSCRIBER_SERVER";
        }
        if (o == IMEI_NOT_ACCEPTED) {
            return "IMEI_NOT_ACCEPTED";
        }
        if (o == EPS_SERVICES_AND_NON_EPS_SERVICES_NOT_ALLOWED) {
            return "EPS_SERVICES_AND_NON_EPS_SERVICES_NOT_ALLOWED";
        }
        if (o == EPS_SERVICES_NOT_ALLOWED_IN_PLMN) {
            return "EPS_SERVICES_NOT_ALLOWED_IN_PLMN";
        }
        if (o == MSC_TEMPORARILY_NOT_REACHABLE) {
            return "MSC_TEMPORARILY_NOT_REACHABLE";
        }
        if (o == CS_DOMAIN_NOT_AVAILABLE) {
            return "CS_DOMAIN_NOT_AVAILABLE";
        }
        if (o == ESM_FAILURE) {
            return "ESM_FAILURE";
        }
        if (o == MAC_FAILURE) {
            return "MAC_FAILURE";
        }
        if (o == SYNCHRONIZATION_FAILURE) {
            return "SYNCHRONIZATION_FAILURE";
        }
        if (o == UE_SECURITY_CAPABILITIES_MISMATCH) {
            return "UE_SECURITY_CAPABILITIES_MISMATCH";
        }
        if (o == SECURITY_MODE_REJECTED) {
            return "SECURITY_MODE_REJECTED";
        }
        if (o == UNACCEPTABLE_NON_EPS_AUTHENTICATION) {
            return "UNACCEPTABLE_NON_EPS_AUTHENTICATION";
        }
        if (o == CS_FALLBACK_CALL_ESTABLISHMENT_NOT_ALLOWED) {
            return "CS_FALLBACK_CALL_ESTABLISHMENT_NOT_ALLOWED";
        }
        if (o == NO_EPS_BEARER_CONTEXT_ACTIVATED) {
            return "NO_EPS_BEARER_CONTEXT_ACTIVATED";
        }
        if (o == INVALID_EMM_STATE) {
            return "INVALID_EMM_STATE";
        }
        if (o == NAS_LAYER_FAILURE) {
            return "NAS_LAYER_FAILURE";
        }
        if (o == MULTIPLE_PDP_CALL_NOT_ALLOWED) {
            return "MULTIPLE_PDP_CALL_NOT_ALLOWED";
        }
        if (o == EMBMS_NOT_ENABLED) {
            return "EMBMS_NOT_ENABLED";
        }
        if (o == IRAT_HANDOVER_FAILED) {
            return "IRAT_HANDOVER_FAILED";
        }
        if (o == EMBMS_REGULAR_DEACTIVATION) {
            return "EMBMS_REGULAR_DEACTIVATION";
        }
        if (o == TEST_LOOPBACK_REGULAR_DEACTIVATION) {
            return "TEST_LOOPBACK_REGULAR_DEACTIVATION";
        }
        if (o == LOWER_LAYER_REGISTRATION_FAILURE) {
            return "LOWER_LAYER_REGISTRATION_FAILURE";
        }
        if (o == DATA_PLAN_EXPIRED) {
            return "DATA_PLAN_EXPIRED";
        }
        if (o == UMTS_HANDOVER_TO_IWLAN) {
            return "UMTS_HANDOVER_TO_IWLAN";
        }
        if (o == EVDO_CONNECTION_DENY_BY_GENERAL_OR_NETWORK_BUSY) {
            return "EVDO_CONNECTION_DENY_BY_GENERAL_OR_NETWORK_BUSY";
        }
        if (o == EVDO_CONNECTION_DENY_BY_BILLING_OR_AUTHENTICATION_FAILURE) {
            return "EVDO_CONNECTION_DENY_BY_BILLING_OR_AUTHENTICATION_FAILURE";
        }
        if (o == EVDO_HDR_CHANGED) {
            return "EVDO_HDR_CHANGED";
        }
        if (o == EVDO_HDR_EXITED) {
            return "EVDO_HDR_EXITED";
        }
        if (o == EVDO_HDR_NO_SESSION) {
            return "EVDO_HDR_NO_SESSION";
        }
        if (o == EVDO_USING_GPS_FIX_INSTEAD_OF_HDR_CALL) {
            return "EVDO_USING_GPS_FIX_INSTEAD_OF_HDR_CALL";
        }
        if (o == EVDO_HDR_CONNECTION_SETUP_TIMEOUT) {
            return "EVDO_HDR_CONNECTION_SETUP_TIMEOUT";
        }
        if (o == FAILED_TO_ACQUIRE_COLOCATED_HDR) {
            return "FAILED_TO_ACQUIRE_COLOCATED_HDR";
        }
        if (o == OTASP_COMMIT_IN_PROGRESS) {
            return "OTASP_COMMIT_IN_PROGRESS";
        }
        if (o == NO_HYBRID_HDR_SERVICE) {
            return "NO_HYBRID_HDR_SERVICE";
        }
        if (o == HDR_NO_LOCK_GRANTED) {
            return "HDR_NO_LOCK_GRANTED";
        }
        if (o == DBM_OR_SMS_IN_PROGRESS) {
            return "DBM_OR_SMS_IN_PROGRESS";
        }
        if (o == HDR_FADE) {
            return "HDR_FADE";
        }
        if (o == HDR_ACCESS_FAILURE) {
            return "HDR_ACCESS_FAILURE";
        }
        if (o == UNSUPPORTED_1X_PREV) {
            return "UNSUPPORTED_1X_PREV";
        }
        if (o == LOCAL_END) {
            return "LOCAL_END";
        }
        if (o == NO_SERVICE) {
            return "NO_SERVICE";
        }
        if (o == FADE) {
            return "FADE";
        }
        if (o == NORMAL_RELEASE) {
            return "NORMAL_RELEASE";
        }
        if (o == ACCESS_ATTEMPT_ALREADY_IN_PROGRESS) {
            return "ACCESS_ATTEMPT_ALREADY_IN_PROGRESS";
        }
        if (o == REDIRECTION_OR_HANDOFF_IN_PROGRESS) {
            return "REDIRECTION_OR_HANDOFF_IN_PROGRESS";
        }
        if (o == EMERGENCY_MODE) {
            return "EMERGENCY_MODE";
        }
        if (o == PHONE_IN_USE) {
            return "PHONE_IN_USE";
        }
        if (o == INVALID_MODE) {
            return "INVALID_MODE";
        }
        if (o == INVALID_SIM_STATE) {
            return "INVALID_SIM_STATE";
        }
        if (o == NO_COLLOCATED_HDR) {
            return "NO_COLLOCATED_HDR";
        }
        if (o == UE_IS_ENTERING_POWERSAVE_MODE) {
            return "UE_IS_ENTERING_POWERSAVE_MODE";
        }
        if (o == DUAL_SWITCH) {
            return "DUAL_SWITCH";
        }
        if (o == PPP_TIMEOUT) {
            return "PPP_TIMEOUT";
        }
        if (o == PPP_AUTH_FAILURE) {
            return "PPP_AUTH_FAILURE";
        }
        if (o == PPP_OPTION_MISMATCH) {
            return "PPP_OPTION_MISMATCH";
        }
        if (o == PPP_PAP_FAILURE) {
            return "PPP_PAP_FAILURE";
        }
        if (o == PPP_CHAP_FAILURE) {
            return "PPP_CHAP_FAILURE";
        }
        if (o == PPP_CLOSE_IN_PROGRESS) {
            return "PPP_CLOSE_IN_PROGRESS";
        }
        if (o == LIMITED_TO_IPV4) {
            return "LIMITED_TO_IPV4";
        }
        if (o == LIMITED_TO_IPV6) {
            return "LIMITED_TO_IPV6";
        }
        if (o == VSNCP_TIMEOUT) {
            return "VSNCP_TIMEOUT";
        }
        if (o == VSNCP_GEN_ERROR) {
            return "VSNCP_GEN_ERROR";
        }
        if (o == VSNCP_APN_UNATHORIZED) {
            return "VSNCP_APN_UNATHORIZED";
        }
        if (o == VSNCP_PDN_LIMIT_EXCEEDED) {
            return "VSNCP_PDN_LIMIT_EXCEEDED";
        }
        if (o == VSNCP_NO_PDN_GATEWAY_ADDRESS) {
            return "VSNCP_NO_PDN_GATEWAY_ADDRESS";
        }
        if (o == VSNCP_PDN_GATEWAY_UNREACHABLE) {
            return "VSNCP_PDN_GATEWAY_UNREACHABLE";
        }
        if (o == VSNCP_PDN_GATEWAY_REJECT) {
            return "VSNCP_PDN_GATEWAY_REJECT";
        }
        if (o == VSNCP_INSUFFICIENT_PARAMETERS) {
            return "VSNCP_INSUFFICIENT_PARAMETERS";
        }
        if (o == VSNCP_RESOURCE_UNAVAILABLE) {
            return "VSNCP_RESOURCE_UNAVAILABLE";
        }
        if (o == VSNCP_ADMINISTRATIVELY_PROHIBITED) {
            return "VSNCP_ADMINISTRATIVELY_PROHIBITED";
        }
        if (o == VSNCP_PDN_ID_IN_USE) {
            return "VSNCP_PDN_ID_IN_USE";
        }
        if (o == VSNCP_SUBSCRIBER_LIMITATION) {
            return "VSNCP_SUBSCRIBER_LIMITATION";
        }
        if (o == VSNCP_PDN_EXISTS_FOR_THIS_APN) {
            return "VSNCP_PDN_EXISTS_FOR_THIS_APN";
        }
        if (o == VSNCP_RECONNECT_NOT_ALLOWED) {
            return "VSNCP_RECONNECT_NOT_ALLOWED";
        }
        if (o == IPV6_PREFIX_UNAVAILABLE) {
            return "IPV6_PREFIX_UNAVAILABLE";
        }
        if (o == HANDOFF_PREFERENCE_CHANGED) {
            return "HANDOFF_PREFERENCE_CHANGED";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("NONE"); // NONE == 0
        if ((o & OPERATOR_BARRED) == OPERATOR_BARRED) {
            list.add("OPERATOR_BARRED");
            flipped |= OPERATOR_BARRED;
        }
        if ((o & NAS_SIGNALLING) == NAS_SIGNALLING) {
            list.add("NAS_SIGNALLING");
            flipped |= NAS_SIGNALLING;
        }
        if ((o & INSUFFICIENT_RESOURCES) == INSUFFICIENT_RESOURCES) {
            list.add("INSUFFICIENT_RESOURCES");
            flipped |= INSUFFICIENT_RESOURCES;
        }
        if ((o & MISSING_UKNOWN_APN) == MISSING_UKNOWN_APN) {
            list.add("MISSING_UKNOWN_APN");
            flipped |= MISSING_UKNOWN_APN;
        }
        if ((o & UNKNOWN_PDP_ADDRESS_TYPE) == UNKNOWN_PDP_ADDRESS_TYPE) {
            list.add("UNKNOWN_PDP_ADDRESS_TYPE");
            flipped |= UNKNOWN_PDP_ADDRESS_TYPE;
        }
        if ((o & USER_AUTHENTICATION) == USER_AUTHENTICATION) {
            list.add("USER_AUTHENTICATION");
            flipped |= USER_AUTHENTICATION;
        }
        if ((o & ACTIVATION_REJECT_GGSN) == ACTIVATION_REJECT_GGSN) {
            list.add("ACTIVATION_REJECT_GGSN");
            flipped |= ACTIVATION_REJECT_GGSN;
        }
        if ((o & ACTIVATION_REJECT_UNSPECIFIED) == ACTIVATION_REJECT_UNSPECIFIED) {
            list.add("ACTIVATION_REJECT_UNSPECIFIED");
            flipped |= ACTIVATION_REJECT_UNSPECIFIED;
        }
        if ((o & SERVICE_OPTION_NOT_SUPPORTED) == SERVICE_OPTION_NOT_SUPPORTED) {
            list.add("SERVICE_OPTION_NOT_SUPPORTED");
            flipped |= SERVICE_OPTION_NOT_SUPPORTED;
        }
        if ((o & SERVICE_OPTION_NOT_SUBSCRIBED) == SERVICE_OPTION_NOT_SUBSCRIBED) {
            list.add("SERVICE_OPTION_NOT_SUBSCRIBED");
            flipped |= SERVICE_OPTION_NOT_SUBSCRIBED;
        }
        if ((o & SERVICE_OPTION_OUT_OF_ORDER) == SERVICE_OPTION_OUT_OF_ORDER) {
            list.add("SERVICE_OPTION_OUT_OF_ORDER");
            flipped |= SERVICE_OPTION_OUT_OF_ORDER;
        }
        if ((o & NSAPI_IN_USE) == NSAPI_IN_USE) {
            list.add("NSAPI_IN_USE");
            flipped |= NSAPI_IN_USE;
        }
        if ((o & REGULAR_DEACTIVATION) == REGULAR_DEACTIVATION) {
            list.add("REGULAR_DEACTIVATION");
            flipped |= REGULAR_DEACTIVATION;
        }
        if ((o & QOS_NOT_ACCEPTED) == QOS_NOT_ACCEPTED) {
            list.add("QOS_NOT_ACCEPTED");
            flipped |= QOS_NOT_ACCEPTED;
        }
        if ((o & NETWORK_FAILURE) == NETWORK_FAILURE) {
            list.add("NETWORK_FAILURE");
            flipped |= NETWORK_FAILURE;
        }
        if ((o & UMTS_REACTIVATION_REQ) == UMTS_REACTIVATION_REQ) {
            list.add("UMTS_REACTIVATION_REQ");
            flipped |= UMTS_REACTIVATION_REQ;
        }
        if ((o & FEATURE_NOT_SUPP) == FEATURE_NOT_SUPP) {
            list.add("FEATURE_NOT_SUPP");
            flipped |= FEATURE_NOT_SUPP;
        }
        if ((o & TFT_SEMANTIC_ERROR) == TFT_SEMANTIC_ERROR) {
            list.add("TFT_SEMANTIC_ERROR");
            flipped |= TFT_SEMANTIC_ERROR;
        }
        if ((o & TFT_SYTAX_ERROR) == TFT_SYTAX_ERROR) {
            list.add("TFT_SYTAX_ERROR");
            flipped |= TFT_SYTAX_ERROR;
        }
        if ((o & UNKNOWN_PDP_CONTEXT) == UNKNOWN_PDP_CONTEXT) {
            list.add("UNKNOWN_PDP_CONTEXT");
            flipped |= UNKNOWN_PDP_CONTEXT;
        }
        if ((o & FILTER_SEMANTIC_ERROR) == FILTER_SEMANTIC_ERROR) {
            list.add("FILTER_SEMANTIC_ERROR");
            flipped |= FILTER_SEMANTIC_ERROR;
        }
        if ((o & FILTER_SYTAX_ERROR) == FILTER_SYTAX_ERROR) {
            list.add("FILTER_SYTAX_ERROR");
            flipped |= FILTER_SYTAX_ERROR;
        }
        if ((o & PDP_WITHOUT_ACTIVE_TFT) == PDP_WITHOUT_ACTIVE_TFT) {
            list.add("PDP_WITHOUT_ACTIVE_TFT");
            flipped |= PDP_WITHOUT_ACTIVE_TFT;
        }
        if ((o & ONLY_IPV4_ALLOWED) == ONLY_IPV4_ALLOWED) {
            list.add("ONLY_IPV4_ALLOWED");
            flipped |= ONLY_IPV4_ALLOWED;
        }
        if ((o & ONLY_IPV6_ALLOWED) == ONLY_IPV6_ALLOWED) {
            list.add("ONLY_IPV6_ALLOWED");
            flipped |= ONLY_IPV6_ALLOWED;
        }
        if ((o & ONLY_SINGLE_BEARER_ALLOWED) == ONLY_SINGLE_BEARER_ALLOWED) {
            list.add("ONLY_SINGLE_BEARER_ALLOWED");
            flipped |= ONLY_SINGLE_BEARER_ALLOWED;
        }
        if ((o & ESM_INFO_NOT_RECEIVED) == ESM_INFO_NOT_RECEIVED) {
            list.add("ESM_INFO_NOT_RECEIVED");
            flipped |= ESM_INFO_NOT_RECEIVED;
        }
        if ((o & PDN_CONN_DOES_NOT_EXIST) == PDN_CONN_DOES_NOT_EXIST) {
            list.add("PDN_CONN_DOES_NOT_EXIST");
            flipped |= PDN_CONN_DOES_NOT_EXIST;
        }
        if ((o & MULTI_CONN_TO_SAME_PDN_NOT_ALLOWED) == MULTI_CONN_TO_SAME_PDN_NOT_ALLOWED) {
            list.add("MULTI_CONN_TO_SAME_PDN_NOT_ALLOWED");
            flipped |= MULTI_CONN_TO_SAME_PDN_NOT_ALLOWED;
        }
        if ((o & MAX_ACTIVE_PDP_CONTEXT_REACHED) == MAX_ACTIVE_PDP_CONTEXT_REACHED) {
            list.add("MAX_ACTIVE_PDP_CONTEXT_REACHED");
            flipped |= MAX_ACTIVE_PDP_CONTEXT_REACHED;
        }
        if ((o & UNSUPPORTED_APN_IN_CURRENT_PLMN) == UNSUPPORTED_APN_IN_CURRENT_PLMN) {
            list.add("UNSUPPORTED_APN_IN_CURRENT_PLMN");
            flipped |= UNSUPPORTED_APN_IN_CURRENT_PLMN;
        }
        if ((o & INVALID_TRANSACTION_ID) == INVALID_TRANSACTION_ID) {
            list.add("INVALID_TRANSACTION_ID");
            flipped |= INVALID_TRANSACTION_ID;
        }
        if ((o & MESSAGE_INCORRECT_SEMANTIC) == MESSAGE_INCORRECT_SEMANTIC) {
            list.add("MESSAGE_INCORRECT_SEMANTIC");
            flipped |= MESSAGE_INCORRECT_SEMANTIC;
        }
        if ((o & INVALID_MANDATORY_INFO) == INVALID_MANDATORY_INFO) {
            list.add("INVALID_MANDATORY_INFO");
            flipped |= INVALID_MANDATORY_INFO;
        }
        if ((o & MESSAGE_TYPE_UNSUPPORTED) == MESSAGE_TYPE_UNSUPPORTED) {
            list.add("MESSAGE_TYPE_UNSUPPORTED");
            flipped |= MESSAGE_TYPE_UNSUPPORTED;
        }
        if ((o & MSG_TYPE_NONCOMPATIBLE_STATE) == MSG_TYPE_NONCOMPATIBLE_STATE) {
            list.add("MSG_TYPE_NONCOMPATIBLE_STATE");
            flipped |= MSG_TYPE_NONCOMPATIBLE_STATE;
        }
        if ((o & UNKNOWN_INFO_ELEMENT) == UNKNOWN_INFO_ELEMENT) {
            list.add("UNKNOWN_INFO_ELEMENT");
            flipped |= UNKNOWN_INFO_ELEMENT;
        }
        if ((o & CONDITIONAL_IE_ERROR) == CONDITIONAL_IE_ERROR) {
            list.add("CONDITIONAL_IE_ERROR");
            flipped |= CONDITIONAL_IE_ERROR;
        }
        if ((o & MSG_AND_PROTOCOL_STATE_UNCOMPATIBLE) == MSG_AND_PROTOCOL_STATE_UNCOMPATIBLE) {
            list.add("MSG_AND_PROTOCOL_STATE_UNCOMPATIBLE");
            flipped |= MSG_AND_PROTOCOL_STATE_UNCOMPATIBLE;
        }
        if ((o & PROTOCOL_ERRORS) == PROTOCOL_ERRORS) {
            list.add("PROTOCOL_ERRORS");
            flipped |= PROTOCOL_ERRORS;
        }
        if ((o & APN_TYPE_CONFLICT) == APN_TYPE_CONFLICT) {
            list.add("APN_TYPE_CONFLICT");
            flipped |= APN_TYPE_CONFLICT;
        }
        if ((o & INVALID_PCSCF_ADDR) == INVALID_PCSCF_ADDR) {
            list.add("INVALID_PCSCF_ADDR");
            flipped |= INVALID_PCSCF_ADDR;
        }
        if ((o & INTERNAL_CALL_PREEMPT_BY_HIGH_PRIO_APN) == INTERNAL_CALL_PREEMPT_BY_HIGH_PRIO_APN) {
            list.add("INTERNAL_CALL_PREEMPT_BY_HIGH_PRIO_APN");
            flipped |= INTERNAL_CALL_PREEMPT_BY_HIGH_PRIO_APN;
        }
        if ((o & EMM_ACCESS_BARRED) == EMM_ACCESS_BARRED) {
            list.add("EMM_ACCESS_BARRED");
            flipped |= EMM_ACCESS_BARRED;
        }
        if ((o & EMERGENCY_IFACE_ONLY) == EMERGENCY_IFACE_ONLY) {
            list.add("EMERGENCY_IFACE_ONLY");
            flipped |= EMERGENCY_IFACE_ONLY;
        }
        if ((o & IFACE_MISMATCH) == IFACE_MISMATCH) {
            list.add("IFACE_MISMATCH");
            flipped |= IFACE_MISMATCH;
        }
        if ((o & COMPANION_IFACE_IN_USE) == COMPANION_IFACE_IN_USE) {
            list.add("COMPANION_IFACE_IN_USE");
            flipped |= COMPANION_IFACE_IN_USE;
        }
        if ((o & IP_ADDRESS_MISMATCH) == IP_ADDRESS_MISMATCH) {
            list.add("IP_ADDRESS_MISMATCH");
            flipped |= IP_ADDRESS_MISMATCH;
        }
        if ((o & IFACE_AND_POL_FAMILY_MISMATCH) == IFACE_AND_POL_FAMILY_MISMATCH) {
            list.add("IFACE_AND_POL_FAMILY_MISMATCH");
            flipped |= IFACE_AND_POL_FAMILY_MISMATCH;
        }
        if ((o & EMM_ACCESS_BARRED_INFINITE_RETRY) == EMM_ACCESS_BARRED_INFINITE_RETRY) {
            list.add("EMM_ACCESS_BARRED_INFINITE_RETRY");
            flipped |= EMM_ACCESS_BARRED_INFINITE_RETRY;
        }
        if ((o & AUTH_FAILURE_ON_EMERGENCY_CALL) == AUTH_FAILURE_ON_EMERGENCY_CALL) {
            list.add("AUTH_FAILURE_ON_EMERGENCY_CALL");
            flipped |= AUTH_FAILURE_ON_EMERGENCY_CALL;
        }
        if ((o & OEM_DCFAILCAUSE_1) == OEM_DCFAILCAUSE_1) {
            list.add("OEM_DCFAILCAUSE_1");
            flipped |= OEM_DCFAILCAUSE_1;
        }
        if ((o & OEM_DCFAILCAUSE_2) == OEM_DCFAILCAUSE_2) {
            list.add("OEM_DCFAILCAUSE_2");
            flipped |= OEM_DCFAILCAUSE_2;
        }
        if ((o & OEM_DCFAILCAUSE_3) == OEM_DCFAILCAUSE_3) {
            list.add("OEM_DCFAILCAUSE_3");
            flipped |= OEM_DCFAILCAUSE_3;
        }
        if ((o & OEM_DCFAILCAUSE_4) == OEM_DCFAILCAUSE_4) {
            list.add("OEM_DCFAILCAUSE_4");
            flipped |= OEM_DCFAILCAUSE_4;
        }
        if ((o & OEM_DCFAILCAUSE_5) == OEM_DCFAILCAUSE_5) {
            list.add("OEM_DCFAILCAUSE_5");
            flipped |= OEM_DCFAILCAUSE_5;
        }
        if ((o & OEM_DCFAILCAUSE_6) == OEM_DCFAILCAUSE_6) {
            list.add("OEM_DCFAILCAUSE_6");
            flipped |= OEM_DCFAILCAUSE_6;
        }
        if ((o & OEM_DCFAILCAUSE_7) == OEM_DCFAILCAUSE_7) {
            list.add("OEM_DCFAILCAUSE_7");
            flipped |= OEM_DCFAILCAUSE_7;
        }
        if ((o & OEM_DCFAILCAUSE_8) == OEM_DCFAILCAUSE_8) {
            list.add("OEM_DCFAILCAUSE_8");
            flipped |= OEM_DCFAILCAUSE_8;
        }
        if ((o & OEM_DCFAILCAUSE_9) == OEM_DCFAILCAUSE_9) {
            list.add("OEM_DCFAILCAUSE_9");
            flipped |= OEM_DCFAILCAUSE_9;
        }
        if ((o & OEM_DCFAILCAUSE_10) == OEM_DCFAILCAUSE_10) {
            list.add("OEM_DCFAILCAUSE_10");
            flipped |= OEM_DCFAILCAUSE_10;
        }
        if ((o & OEM_DCFAILCAUSE_11) == OEM_DCFAILCAUSE_11) {
            list.add("OEM_DCFAILCAUSE_11");
            flipped |= OEM_DCFAILCAUSE_11;
        }
        if ((o & OEM_DCFAILCAUSE_12) == OEM_DCFAILCAUSE_12) {
            list.add("OEM_DCFAILCAUSE_12");
            flipped |= OEM_DCFAILCAUSE_12;
        }
        if ((o & OEM_DCFAILCAUSE_13) == OEM_DCFAILCAUSE_13) {
            list.add("OEM_DCFAILCAUSE_13");
            flipped |= OEM_DCFAILCAUSE_13;
        }
        if ((o & OEM_DCFAILCAUSE_14) == OEM_DCFAILCAUSE_14) {
            list.add("OEM_DCFAILCAUSE_14");
            flipped |= OEM_DCFAILCAUSE_14;
        }
        if ((o & OEM_DCFAILCAUSE_15) == OEM_DCFAILCAUSE_15) {
            list.add("OEM_DCFAILCAUSE_15");
            flipped |= OEM_DCFAILCAUSE_15;
        }
        if ((o & VOICE_REGISTRATION_FAIL) == VOICE_REGISTRATION_FAIL) {
            list.add("VOICE_REGISTRATION_FAIL");
            flipped |= VOICE_REGISTRATION_FAIL;
        }
        if ((o & DATA_REGISTRATION_FAIL) == DATA_REGISTRATION_FAIL) {
            list.add("DATA_REGISTRATION_FAIL");
            flipped |= DATA_REGISTRATION_FAIL;
        }
        if ((o & SIGNAL_LOST) == SIGNAL_LOST) {
            list.add("SIGNAL_LOST");
            flipped |= SIGNAL_LOST;
        }
        if ((o & PREF_RADIO_TECH_CHANGED) == PREF_RADIO_TECH_CHANGED) {
            list.add("PREF_RADIO_TECH_CHANGED");
            flipped |= PREF_RADIO_TECH_CHANGED;
        }
        if ((o & RADIO_POWER_OFF) == RADIO_POWER_OFF) {
            list.add("RADIO_POWER_OFF");
            flipped |= RADIO_POWER_OFF;
        }
        if ((o & TETHERED_CALL_ACTIVE) == TETHERED_CALL_ACTIVE) {
            list.add("TETHERED_CALL_ACTIVE");
            flipped |= TETHERED_CALL_ACTIVE;
        }
        if ((o & ERROR_UNSPECIFIED) == ERROR_UNSPECIFIED) {
            list.add("ERROR_UNSPECIFIED");
            flipped |= ERROR_UNSPECIFIED;
        }
        if ((o & LLC_SNDCP) == LLC_SNDCP) {
            list.add("LLC_SNDCP");
            flipped |= LLC_SNDCP;
        }
        if ((o & ACTIVATION_REJECTED_BCM_VIOLATION) == ACTIVATION_REJECTED_BCM_VIOLATION) {
            list.add("ACTIVATION_REJECTED_BCM_VIOLATION");
            flipped |= ACTIVATION_REJECTED_BCM_VIOLATION;
        }
        if ((o & COLLISION_WITH_NETWORK_INITIATED_REQUEST) == COLLISION_WITH_NETWORK_INITIATED_REQUEST) {
            list.add("COLLISION_WITH_NETWORK_INITIATED_REQUEST");
            flipped |= COLLISION_WITH_NETWORK_INITIATED_REQUEST;
        }
        if ((o & ONLY_IPV4V6_ALLOWED) == ONLY_IPV4V6_ALLOWED) {
            list.add("ONLY_IPV4V6_ALLOWED");
            flipped |= ONLY_IPV4V6_ALLOWED;
        }
        if ((o & ONLY_NON_IP_ALLOWED) == ONLY_NON_IP_ALLOWED) {
            list.add("ONLY_NON_IP_ALLOWED");
            flipped |= ONLY_NON_IP_ALLOWED;
        }
        if ((o & UNSUPPORTED_QCI_VALUE) == UNSUPPORTED_QCI_VALUE) {
            list.add("UNSUPPORTED_QCI_VALUE");
            flipped |= UNSUPPORTED_QCI_VALUE;
        }
        if ((o & BEARER_HANDLING_NOT_SUPPORTED) == BEARER_HANDLING_NOT_SUPPORTED) {
            list.add("BEARER_HANDLING_NOT_SUPPORTED");
            flipped |= BEARER_HANDLING_NOT_SUPPORTED;
        }
        if ((o & INVALID_DNS_ADDR) == INVALID_DNS_ADDR) {
            list.add("INVALID_DNS_ADDR");
            flipped |= INVALID_DNS_ADDR;
        }
        if ((o & INVALID_PCSCF_OR_DNS_ADDRESS) == INVALID_PCSCF_OR_DNS_ADDRESS) {
            list.add("INVALID_PCSCF_OR_DNS_ADDRESS");
            flipped |= INVALID_PCSCF_OR_DNS_ADDRESS;
        }
        if ((o & CALL_PREEMPT_BY_EMERGENCY_APN) == CALL_PREEMPT_BY_EMERGENCY_APN) {
            list.add("CALL_PREEMPT_BY_EMERGENCY_APN");
            flipped |= CALL_PREEMPT_BY_EMERGENCY_APN;
        }
        if ((o & UE_INITIATED_DETACH_OR_DISCONNECT) == UE_INITIATED_DETACH_OR_DISCONNECT) {
            list.add("UE_INITIATED_DETACH_OR_DISCONNECT");
            flipped |= UE_INITIATED_DETACH_OR_DISCONNECT;
        }
        if ((o & MIP_FA_REASON_UNSPECIFIED) == MIP_FA_REASON_UNSPECIFIED) {
            list.add("MIP_FA_REASON_UNSPECIFIED");
            flipped |= MIP_FA_REASON_UNSPECIFIED;
        }
        if ((o & MIP_FA_ADMIN_PROHIBITED) == MIP_FA_ADMIN_PROHIBITED) {
            list.add("MIP_FA_ADMIN_PROHIBITED");
            flipped |= MIP_FA_ADMIN_PROHIBITED;
        }
        if ((o & MIP_FA_INSUFFICIENT_RESOURCES) == MIP_FA_INSUFFICIENT_RESOURCES) {
            list.add("MIP_FA_INSUFFICIENT_RESOURCES");
            flipped |= MIP_FA_INSUFFICIENT_RESOURCES;
        }
        if ((o & MIP_FA_MOBILE_NODE_AUTHENTICATION_FAILURE) == MIP_FA_MOBILE_NODE_AUTHENTICATION_FAILURE) {
            list.add("MIP_FA_MOBILE_NODE_AUTHENTICATION_FAILURE");
            flipped |= MIP_FA_MOBILE_NODE_AUTHENTICATION_FAILURE;
        }
        if ((o & MIP_FA_HOME_AGENT_AUTHENTICATION_FAILURE) == MIP_FA_HOME_AGENT_AUTHENTICATION_FAILURE) {
            list.add("MIP_FA_HOME_AGENT_AUTHENTICATION_FAILURE");
            flipped |= MIP_FA_HOME_AGENT_AUTHENTICATION_FAILURE;
        }
        if ((o & MIP_FA_REQUESTED_LIFETIME_TOO_LONG) == MIP_FA_REQUESTED_LIFETIME_TOO_LONG) {
            list.add("MIP_FA_REQUESTED_LIFETIME_TOO_LONG");
            flipped |= MIP_FA_REQUESTED_LIFETIME_TOO_LONG;
        }
        if ((o & MIP_FA_MALFORMED_REQUEST) == MIP_FA_MALFORMED_REQUEST) {
            list.add("MIP_FA_MALFORMED_REQUEST");
            flipped |= MIP_FA_MALFORMED_REQUEST;
        }
        if ((o & MIP_FA_MALFORMED_REPLY) == MIP_FA_MALFORMED_REPLY) {
            list.add("MIP_FA_MALFORMED_REPLY");
            flipped |= MIP_FA_MALFORMED_REPLY;
        }
        if ((o & MIP_FA_ENCAPSULATION_UNAVAILABLE) == MIP_FA_ENCAPSULATION_UNAVAILABLE) {
            list.add("MIP_FA_ENCAPSULATION_UNAVAILABLE");
            flipped |= MIP_FA_ENCAPSULATION_UNAVAILABLE;
        }
        if ((o & MIP_FA_VJ_HEADER_COMPRESSION_UNAVAILABLE) == MIP_FA_VJ_HEADER_COMPRESSION_UNAVAILABLE) {
            list.add("MIP_FA_VJ_HEADER_COMPRESSION_UNAVAILABLE");
            flipped |= MIP_FA_VJ_HEADER_COMPRESSION_UNAVAILABLE;
        }
        if ((o & MIP_FA_REVERSE_TUNNEL_UNAVAILABLE) == MIP_FA_REVERSE_TUNNEL_UNAVAILABLE) {
            list.add("MIP_FA_REVERSE_TUNNEL_UNAVAILABLE");
            flipped |= MIP_FA_REVERSE_TUNNEL_UNAVAILABLE;
        }
        if ((o & MIP_FA_REVERSE_TUNNEL_IS_MANDATORY) == MIP_FA_REVERSE_TUNNEL_IS_MANDATORY) {
            list.add("MIP_FA_REVERSE_TUNNEL_IS_MANDATORY");
            flipped |= MIP_FA_REVERSE_TUNNEL_IS_MANDATORY;
        }
        if ((o & MIP_FA_DELIVERY_STYLE_NOT_SUPPORTED) == MIP_FA_DELIVERY_STYLE_NOT_SUPPORTED) {
            list.add("MIP_FA_DELIVERY_STYLE_NOT_SUPPORTED");
            flipped |= MIP_FA_DELIVERY_STYLE_NOT_SUPPORTED;
        }
        if ((o & MIP_FA_MISSING_NAI) == MIP_FA_MISSING_NAI) {
            list.add("MIP_FA_MISSING_NAI");
            flipped |= MIP_FA_MISSING_NAI;
        }
        if ((o & MIP_FA_MISSING_HOME_AGENT) == MIP_FA_MISSING_HOME_AGENT) {
            list.add("MIP_FA_MISSING_HOME_AGENT");
            flipped |= MIP_FA_MISSING_HOME_AGENT;
        }
        if ((o & MIP_FA_MISSING_HOME_ADDRESS) == MIP_FA_MISSING_HOME_ADDRESS) {
            list.add("MIP_FA_MISSING_HOME_ADDRESS");
            flipped |= MIP_FA_MISSING_HOME_ADDRESS;
        }
        if ((o & MIP_FA_UNKNOWN_CHALLENGE) == MIP_FA_UNKNOWN_CHALLENGE) {
            list.add("MIP_FA_UNKNOWN_CHALLENGE");
            flipped |= MIP_FA_UNKNOWN_CHALLENGE;
        }
        if ((o & MIP_FA_MISSING_CHALLENGE) == MIP_FA_MISSING_CHALLENGE) {
            list.add("MIP_FA_MISSING_CHALLENGE");
            flipped |= MIP_FA_MISSING_CHALLENGE;
        }
        if ((o & MIP_FA_STALE_CHALLENGE) == MIP_FA_STALE_CHALLENGE) {
            list.add("MIP_FA_STALE_CHALLENGE");
            flipped |= MIP_FA_STALE_CHALLENGE;
        }
        if ((o & MIP_HA_REASON_UNSPECIFIED) == MIP_HA_REASON_UNSPECIFIED) {
            list.add("MIP_HA_REASON_UNSPECIFIED");
            flipped |= MIP_HA_REASON_UNSPECIFIED;
        }
        if ((o & MIP_HA_ADMIN_PROHIBITED) == MIP_HA_ADMIN_PROHIBITED) {
            list.add("MIP_HA_ADMIN_PROHIBITED");
            flipped |= MIP_HA_ADMIN_PROHIBITED;
        }
        if ((o & MIP_HA_INSUFFICIENT_RESOURCES) == MIP_HA_INSUFFICIENT_RESOURCES) {
            list.add("MIP_HA_INSUFFICIENT_RESOURCES");
            flipped |= MIP_HA_INSUFFICIENT_RESOURCES;
        }
        if ((o & MIP_HA_MOBILE_NODE_AUTHENTICATION_FAILURE) == MIP_HA_MOBILE_NODE_AUTHENTICATION_FAILURE) {
            list.add("MIP_HA_MOBILE_NODE_AUTHENTICATION_FAILURE");
            flipped |= MIP_HA_MOBILE_NODE_AUTHENTICATION_FAILURE;
        }
        if ((o & MIP_HA_FOREIGN_AGENT_AUTHENTICATION_FAILURE) == MIP_HA_FOREIGN_AGENT_AUTHENTICATION_FAILURE) {
            list.add("MIP_HA_FOREIGN_AGENT_AUTHENTICATION_FAILURE");
            flipped |= MIP_HA_FOREIGN_AGENT_AUTHENTICATION_FAILURE;
        }
        if ((o & MIP_HA_REGISTRATION_ID_MISMATCH) == MIP_HA_REGISTRATION_ID_MISMATCH) {
            list.add("MIP_HA_REGISTRATION_ID_MISMATCH");
            flipped |= MIP_HA_REGISTRATION_ID_MISMATCH;
        }
        if ((o & MIP_HA_MALFORMED_REQUEST) == MIP_HA_MALFORMED_REQUEST) {
            list.add("MIP_HA_MALFORMED_REQUEST");
            flipped |= MIP_HA_MALFORMED_REQUEST;
        }
        if ((o & MIP_HA_UNKNOWN_HOME_AGENT_ADDRESS) == MIP_HA_UNKNOWN_HOME_AGENT_ADDRESS) {
            list.add("MIP_HA_UNKNOWN_HOME_AGENT_ADDRESS");
            flipped |= MIP_HA_UNKNOWN_HOME_AGENT_ADDRESS;
        }
        if ((o & MIP_HA_REVERSE_TUNNEL_UNAVAILABLE) == MIP_HA_REVERSE_TUNNEL_UNAVAILABLE) {
            list.add("MIP_HA_REVERSE_TUNNEL_UNAVAILABLE");
            flipped |= MIP_HA_REVERSE_TUNNEL_UNAVAILABLE;
        }
        if ((o & MIP_HA_REVERSE_TUNNEL_IS_MANDATORY) == MIP_HA_REVERSE_TUNNEL_IS_MANDATORY) {
            list.add("MIP_HA_REVERSE_TUNNEL_IS_MANDATORY");
            flipped |= MIP_HA_REVERSE_TUNNEL_IS_MANDATORY;
        }
        if ((o & MIP_HA_ENCAPSULATION_UNAVAILABLE) == MIP_HA_ENCAPSULATION_UNAVAILABLE) {
            list.add("MIP_HA_ENCAPSULATION_UNAVAILABLE");
            flipped |= MIP_HA_ENCAPSULATION_UNAVAILABLE;
        }
        if ((o & CLOSE_IN_PROGRESS) == CLOSE_IN_PROGRESS) {
            list.add("CLOSE_IN_PROGRESS");
            flipped |= CLOSE_IN_PROGRESS;
        }
        if ((o & NETWORK_INITIATED_TERMINATION) == NETWORK_INITIATED_TERMINATION) {
            list.add("NETWORK_INITIATED_TERMINATION");
            flipped |= NETWORK_INITIATED_TERMINATION;
        }
        if ((o & MODEM_APP_PREEMPTED) == MODEM_APP_PREEMPTED) {
            list.add("MODEM_APP_PREEMPTED");
            flipped |= MODEM_APP_PREEMPTED;
        }
        if ((o & PDN_IPV4_CALL_DISALLOWED) == PDN_IPV4_CALL_DISALLOWED) {
            list.add("PDN_IPV4_CALL_DISALLOWED");
            flipped |= PDN_IPV4_CALL_DISALLOWED;
        }
        if ((o & PDN_IPV4_CALL_THROTTLED) == PDN_IPV4_CALL_THROTTLED) {
            list.add("PDN_IPV4_CALL_THROTTLED");
            flipped |= PDN_IPV4_CALL_THROTTLED;
        }
        if ((o & PDN_IPV6_CALL_DISALLOWED) == PDN_IPV6_CALL_DISALLOWED) {
            list.add("PDN_IPV6_CALL_DISALLOWED");
            flipped |= PDN_IPV6_CALL_DISALLOWED;
        }
        if ((o & PDN_IPV6_CALL_THROTTLED) == PDN_IPV6_CALL_THROTTLED) {
            list.add("PDN_IPV6_CALL_THROTTLED");
            flipped |= PDN_IPV6_CALL_THROTTLED;
        }
        if ((o & MODEM_RESTART) == MODEM_RESTART) {
            list.add("MODEM_RESTART");
            flipped |= MODEM_RESTART;
        }
        if ((o & PDP_PPP_NOT_SUPPORTED) == PDP_PPP_NOT_SUPPORTED) {
            list.add("PDP_PPP_NOT_SUPPORTED");
            flipped |= PDP_PPP_NOT_SUPPORTED;
        }
        if ((o & UNPREFERRED_RAT) == UNPREFERRED_RAT) {
            list.add("UNPREFERRED_RAT");
            flipped |= UNPREFERRED_RAT;
        }
        if ((o & PHYSICAL_LINK_CLOSE_IN_PROGRESS) == PHYSICAL_LINK_CLOSE_IN_PROGRESS) {
            list.add("PHYSICAL_LINK_CLOSE_IN_PROGRESS");
            flipped |= PHYSICAL_LINK_CLOSE_IN_PROGRESS;
        }
        if ((o & APN_PENDING_HANDOVER) == APN_PENDING_HANDOVER) {
            list.add("APN_PENDING_HANDOVER");
            flipped |= APN_PENDING_HANDOVER;
        }
        if ((o & PROFILE_BEARER_INCOMPATIBLE) == PROFILE_BEARER_INCOMPATIBLE) {
            list.add("PROFILE_BEARER_INCOMPATIBLE");
            flipped |= PROFILE_BEARER_INCOMPATIBLE;
        }
        if ((o & SIM_CARD_CHANGED) == SIM_CARD_CHANGED) {
            list.add("SIM_CARD_CHANGED");
            flipped |= SIM_CARD_CHANGED;
        }
        if ((o & LOW_POWER_MODE_OR_POWERING_DOWN) == LOW_POWER_MODE_OR_POWERING_DOWN) {
            list.add("LOW_POWER_MODE_OR_POWERING_DOWN");
            flipped |= LOW_POWER_MODE_OR_POWERING_DOWN;
        }
        if ((o & APN_DISABLED) == APN_DISABLED) {
            list.add("APN_DISABLED");
            flipped |= APN_DISABLED;
        }
        if ((o & MAX_PPP_INACTIVITY_TIMER_EXPIRED) == MAX_PPP_INACTIVITY_TIMER_EXPIRED) {
            list.add("MAX_PPP_INACTIVITY_TIMER_EXPIRED");
            flipped |= MAX_PPP_INACTIVITY_TIMER_EXPIRED;
        }
        if ((o & IPV6_ADDRESS_TRANSFER_FAILED) == IPV6_ADDRESS_TRANSFER_FAILED) {
            list.add("IPV6_ADDRESS_TRANSFER_FAILED");
            flipped |= IPV6_ADDRESS_TRANSFER_FAILED;
        }
        if ((o & TRAT_SWAP_FAILED) == TRAT_SWAP_FAILED) {
            list.add("TRAT_SWAP_FAILED");
            flipped |= TRAT_SWAP_FAILED;
        }
        if ((o & EHRPD_TO_HRPD_FALLBACK) == EHRPD_TO_HRPD_FALLBACK) {
            list.add("EHRPD_TO_HRPD_FALLBACK");
            flipped |= EHRPD_TO_HRPD_FALLBACK;
        }
        if ((o & MIP_CONFIG_FAILURE) == MIP_CONFIG_FAILURE) {
            list.add("MIP_CONFIG_FAILURE");
            flipped |= MIP_CONFIG_FAILURE;
        }
        if ((o & PDN_INACTIVITY_TIMER_EXPIRED) == PDN_INACTIVITY_TIMER_EXPIRED) {
            list.add("PDN_INACTIVITY_TIMER_EXPIRED");
            flipped |= PDN_INACTIVITY_TIMER_EXPIRED;
        }
        if ((o & MAX_IPV4_CONNECTIONS) == MAX_IPV4_CONNECTIONS) {
            list.add("MAX_IPV4_CONNECTIONS");
            flipped |= MAX_IPV4_CONNECTIONS;
        }
        if ((o & MAX_IPV6_CONNECTIONS) == MAX_IPV6_CONNECTIONS) {
            list.add("MAX_IPV6_CONNECTIONS");
            flipped |= MAX_IPV6_CONNECTIONS;
        }
        if ((o & APN_MISMATCH) == APN_MISMATCH) {
            list.add("APN_MISMATCH");
            flipped |= APN_MISMATCH;
        }
        if ((o & IP_VERSION_MISMATCH) == IP_VERSION_MISMATCH) {
            list.add("IP_VERSION_MISMATCH");
            flipped |= IP_VERSION_MISMATCH;
        }
        if ((o & DUN_CALL_DISALLOWED) == DUN_CALL_DISALLOWED) {
            list.add("DUN_CALL_DISALLOWED");
            flipped |= DUN_CALL_DISALLOWED;
        }
        if ((o & INTERNAL_EPC_NONEPC_TRANSITION) == INTERNAL_EPC_NONEPC_TRANSITION) {
            list.add("INTERNAL_EPC_NONEPC_TRANSITION");
            flipped |= INTERNAL_EPC_NONEPC_TRANSITION;
        }
        if ((o & INTERFACE_IN_USE) == INTERFACE_IN_USE) {
            list.add("INTERFACE_IN_USE");
            flipped |= INTERFACE_IN_USE;
        }
        if ((o & APN_DISALLOWED_ON_ROAMING) == APN_DISALLOWED_ON_ROAMING) {
            list.add("APN_DISALLOWED_ON_ROAMING");
            flipped |= APN_DISALLOWED_ON_ROAMING;
        }
        if ((o & APN_PARAMETERS_CHANGED) == APN_PARAMETERS_CHANGED) {
            list.add("APN_PARAMETERS_CHANGED");
            flipped |= APN_PARAMETERS_CHANGED;
        }
        if ((o & NULL_APN_DISALLOWED) == NULL_APN_DISALLOWED) {
            list.add("NULL_APN_DISALLOWED");
            flipped |= NULL_APN_DISALLOWED;
        }
        if ((o & THERMAL_MITIGATION) == THERMAL_MITIGATION) {
            list.add("THERMAL_MITIGATION");
            flipped |= THERMAL_MITIGATION;
        }
        if ((o & DATA_SETTINGS_DISABLED) == DATA_SETTINGS_DISABLED) {
            list.add("DATA_SETTINGS_DISABLED");
            flipped |= DATA_SETTINGS_DISABLED;
        }
        if ((o & DATA_ROAMING_SETTINGS_DISABLED) == DATA_ROAMING_SETTINGS_DISABLED) {
            list.add("DATA_ROAMING_SETTINGS_DISABLED");
            flipped |= DATA_ROAMING_SETTINGS_DISABLED;
        }
        if ((o & DDS_SWITCHED) == DDS_SWITCHED) {
            list.add("DDS_SWITCHED");
            flipped |= DDS_SWITCHED;
        }
        if ((o & FORBIDDEN_APN_NAME) == FORBIDDEN_APN_NAME) {
            list.add("FORBIDDEN_APN_NAME");
            flipped |= FORBIDDEN_APN_NAME;
        }
        if ((o & DDS_SWITCH_IN_PROGRESS) == DDS_SWITCH_IN_PROGRESS) {
            list.add("DDS_SWITCH_IN_PROGRESS");
            flipped |= DDS_SWITCH_IN_PROGRESS;
        }
        if ((o & CALL_DISALLOWED_IN_ROAMING) == CALL_DISALLOWED_IN_ROAMING) {
            list.add("CALL_DISALLOWED_IN_ROAMING");
            flipped |= CALL_DISALLOWED_IN_ROAMING;
        }
        if ((o & NON_IP_NOT_SUPPORTED) == NON_IP_NOT_SUPPORTED) {
            list.add("NON_IP_NOT_SUPPORTED");
            flipped |= NON_IP_NOT_SUPPORTED;
        }
        if ((o & PDN_NON_IP_CALL_THROTTLED) == PDN_NON_IP_CALL_THROTTLED) {
            list.add("PDN_NON_IP_CALL_THROTTLED");
            flipped |= PDN_NON_IP_CALL_THROTTLED;
        }
        if ((o & PDN_NON_IP_CALL_DISALLOWED) == PDN_NON_IP_CALL_DISALLOWED) {
            list.add("PDN_NON_IP_CALL_DISALLOWED");
            flipped |= PDN_NON_IP_CALL_DISALLOWED;
        }
        if ((o & CDMA_LOCK) == CDMA_LOCK) {
            list.add("CDMA_LOCK");
            flipped |= CDMA_LOCK;
        }
        if ((o & CDMA_INTERCEPT) == CDMA_INTERCEPT) {
            list.add("CDMA_INTERCEPT");
            flipped |= CDMA_INTERCEPT;
        }
        if ((o & CDMA_REORDER) == CDMA_REORDER) {
            list.add("CDMA_REORDER");
            flipped |= CDMA_REORDER;
        }
        if ((o & CDMA_RELEASE_DUE_TO_SO_REJECTION) == CDMA_RELEASE_DUE_TO_SO_REJECTION) {
            list.add("CDMA_RELEASE_DUE_TO_SO_REJECTION");
            flipped |= CDMA_RELEASE_DUE_TO_SO_REJECTION;
        }
        if ((o & CDMA_INCOMING_CALL) == CDMA_INCOMING_CALL) {
            list.add("CDMA_INCOMING_CALL");
            flipped |= CDMA_INCOMING_CALL;
        }
        if ((o & CDMA_ALERT_STOP) == CDMA_ALERT_STOP) {
            list.add("CDMA_ALERT_STOP");
            flipped |= CDMA_ALERT_STOP;
        }
        if ((o & CHANNEL_ACQUISITION_FAILURE) == CHANNEL_ACQUISITION_FAILURE) {
            list.add("CHANNEL_ACQUISITION_FAILURE");
            flipped |= CHANNEL_ACQUISITION_FAILURE;
        }
        if ((o & MAX_ACCESS_PROBE) == MAX_ACCESS_PROBE) {
            list.add("MAX_ACCESS_PROBE");
            flipped |= MAX_ACCESS_PROBE;
        }
        if ((o & CONCURRENT_SERVICE_NOT_SUPPORTED_BY_BASE_STATION) == CONCURRENT_SERVICE_NOT_SUPPORTED_BY_BASE_STATION) {
            list.add("CONCURRENT_SERVICE_NOT_SUPPORTED_BY_BASE_STATION");
            flipped |= CONCURRENT_SERVICE_NOT_SUPPORTED_BY_BASE_STATION;
        }
        if ((o & NO_RESPONSE_FROM_BASE_STATION) == NO_RESPONSE_FROM_BASE_STATION) {
            list.add("NO_RESPONSE_FROM_BASE_STATION");
            flipped |= NO_RESPONSE_FROM_BASE_STATION;
        }
        if ((o & REJECTED_BY_BASE_STATION) == REJECTED_BY_BASE_STATION) {
            list.add("REJECTED_BY_BASE_STATION");
            flipped |= REJECTED_BY_BASE_STATION;
        }
        if ((o & CONCURRENT_SERVICES_INCOMPATIBLE) == CONCURRENT_SERVICES_INCOMPATIBLE) {
            list.add("CONCURRENT_SERVICES_INCOMPATIBLE");
            flipped |= CONCURRENT_SERVICES_INCOMPATIBLE;
        }
        if ((o & NO_CDMA_SERVICE) == NO_CDMA_SERVICE) {
            list.add("NO_CDMA_SERVICE");
            flipped |= NO_CDMA_SERVICE;
        }
        if ((o & RUIM_NOT_PRESENT) == RUIM_NOT_PRESENT) {
            list.add("RUIM_NOT_PRESENT");
            flipped |= RUIM_NOT_PRESENT;
        }
        if ((o & CDMA_RETRY_ORDER) == CDMA_RETRY_ORDER) {
            list.add("CDMA_RETRY_ORDER");
            flipped |= CDMA_RETRY_ORDER;
        }
        if ((o & ACCESS_BLOCK) == ACCESS_BLOCK) {
            list.add("ACCESS_BLOCK");
            flipped |= ACCESS_BLOCK;
        }
        if ((o & ACCESS_BLOCK_ALL) == ACCESS_BLOCK_ALL) {
            list.add("ACCESS_BLOCK_ALL");
            flipped |= ACCESS_BLOCK_ALL;
        }
        if ((o & IS707B_MAX_ACCESS_PROBES) == IS707B_MAX_ACCESS_PROBES) {
            list.add("IS707B_MAX_ACCESS_PROBES");
            flipped |= IS707B_MAX_ACCESS_PROBES;
        }
        if ((o & THERMAL_EMERGENCY) == THERMAL_EMERGENCY) {
            list.add("THERMAL_EMERGENCY");
            flipped |= THERMAL_EMERGENCY;
        }
        if ((o & CONCURRENT_SERVICES_NOT_ALLOWED) == CONCURRENT_SERVICES_NOT_ALLOWED) {
            list.add("CONCURRENT_SERVICES_NOT_ALLOWED");
            flipped |= CONCURRENT_SERVICES_NOT_ALLOWED;
        }
        if ((o & INCOMING_CALL_REJECTED) == INCOMING_CALL_REJECTED) {
            list.add("INCOMING_CALL_REJECTED");
            flipped |= INCOMING_CALL_REJECTED;
        }
        if ((o & NO_SERVICE_ON_GATEWAY) == NO_SERVICE_ON_GATEWAY) {
            list.add("NO_SERVICE_ON_GATEWAY");
            flipped |= NO_SERVICE_ON_GATEWAY;
        }
        if ((o & NO_GPRS_CONTEXT) == NO_GPRS_CONTEXT) {
            list.add("NO_GPRS_CONTEXT");
            flipped |= NO_GPRS_CONTEXT;
        }
        if ((o & ILLEGAL_MS) == ILLEGAL_MS) {
            list.add("ILLEGAL_MS");
            flipped |= ILLEGAL_MS;
        }
        if ((o & ILLEGAL_ME) == ILLEGAL_ME) {
            list.add("ILLEGAL_ME");
            flipped |= ILLEGAL_ME;
        }
        if ((o & GPRS_SERVICES_AND_NON_GPRS_SERVICES_NOT_ALLOWED) == GPRS_SERVICES_AND_NON_GPRS_SERVICES_NOT_ALLOWED) {
            list.add("GPRS_SERVICES_AND_NON_GPRS_SERVICES_NOT_ALLOWED");
            flipped |= GPRS_SERVICES_AND_NON_GPRS_SERVICES_NOT_ALLOWED;
        }
        if ((o & GPRS_SERVICES_NOT_ALLOWED) == GPRS_SERVICES_NOT_ALLOWED) {
            list.add("GPRS_SERVICES_NOT_ALLOWED");
            flipped |= GPRS_SERVICES_NOT_ALLOWED;
        }
        if ((o & MS_IDENTITY_CANNOT_BE_DERIVED_BY_THE_NETWORK) == MS_IDENTITY_CANNOT_BE_DERIVED_BY_THE_NETWORK) {
            list.add("MS_IDENTITY_CANNOT_BE_DERIVED_BY_THE_NETWORK");
            flipped |= MS_IDENTITY_CANNOT_BE_DERIVED_BY_THE_NETWORK;
        }
        if ((o & IMPLICITLY_DETACHED) == IMPLICITLY_DETACHED) {
            list.add("IMPLICITLY_DETACHED");
            flipped |= IMPLICITLY_DETACHED;
        }
        if ((o & PLMN_NOT_ALLOWED) == PLMN_NOT_ALLOWED) {
            list.add("PLMN_NOT_ALLOWED");
            flipped |= PLMN_NOT_ALLOWED;
        }
        if ((o & LOCATION_AREA_NOT_ALLOWED) == LOCATION_AREA_NOT_ALLOWED) {
            list.add("LOCATION_AREA_NOT_ALLOWED");
            flipped |= LOCATION_AREA_NOT_ALLOWED;
        }
        if ((o & GPRS_SERVICES_NOT_ALLOWED_IN_THIS_PLMN) == GPRS_SERVICES_NOT_ALLOWED_IN_THIS_PLMN) {
            list.add("GPRS_SERVICES_NOT_ALLOWED_IN_THIS_PLMN");
            flipped |= GPRS_SERVICES_NOT_ALLOWED_IN_THIS_PLMN;
        }
        if ((o & PDP_DUPLICATE) == PDP_DUPLICATE) {
            list.add("PDP_DUPLICATE");
            flipped |= PDP_DUPLICATE;
        }
        if ((o & UE_RAT_CHANGE) == UE_RAT_CHANGE) {
            list.add("UE_RAT_CHANGE");
            flipped |= UE_RAT_CHANGE;
        }
        if ((o & CONGESTION) == CONGESTION) {
            list.add("CONGESTION");
            flipped |= CONGESTION;
        }
        if ((o & NO_PDP_CONTEXT_ACTIVATED) == NO_PDP_CONTEXT_ACTIVATED) {
            list.add("NO_PDP_CONTEXT_ACTIVATED");
            flipped |= NO_PDP_CONTEXT_ACTIVATED;
        }
        if ((o & ACCESS_CLASS_DSAC_REJECTION) == ACCESS_CLASS_DSAC_REJECTION) {
            list.add("ACCESS_CLASS_DSAC_REJECTION");
            flipped |= ACCESS_CLASS_DSAC_REJECTION;
        }
        if ((o & PDP_ACTIVATE_MAX_RETRY_FAILED) == PDP_ACTIVATE_MAX_RETRY_FAILED) {
            list.add("PDP_ACTIVATE_MAX_RETRY_FAILED");
            flipped |= PDP_ACTIVATE_MAX_RETRY_FAILED;
        }
        if ((o & RADIO_ACCESS_BEARER_FAILURE) == RADIO_ACCESS_BEARER_FAILURE) {
            list.add("RADIO_ACCESS_BEARER_FAILURE");
            flipped |= RADIO_ACCESS_BEARER_FAILURE;
        }
        if ((o & ESM_UNKNOWN_EPS_BEARER_CONTEXT) == ESM_UNKNOWN_EPS_BEARER_CONTEXT) {
            list.add("ESM_UNKNOWN_EPS_BEARER_CONTEXT");
            flipped |= ESM_UNKNOWN_EPS_BEARER_CONTEXT;
        }
        if ((o & DRB_RELEASED_BY_RRC) == DRB_RELEASED_BY_RRC) {
            list.add("DRB_RELEASED_BY_RRC");
            flipped |= DRB_RELEASED_BY_RRC;
        }
        if ((o & CONNECTION_RELEASED) == CONNECTION_RELEASED) {
            list.add("CONNECTION_RELEASED");
            flipped |= CONNECTION_RELEASED;
        }
        if ((o & EMM_DETACHED) == EMM_DETACHED) {
            list.add("EMM_DETACHED");
            flipped |= EMM_DETACHED;
        }
        if ((o & EMM_ATTACH_FAILED) == EMM_ATTACH_FAILED) {
            list.add("EMM_ATTACH_FAILED");
            flipped |= EMM_ATTACH_FAILED;
        }
        if ((o & EMM_ATTACH_STARTED) == EMM_ATTACH_STARTED) {
            list.add("EMM_ATTACH_STARTED");
            flipped |= EMM_ATTACH_STARTED;
        }
        if ((o & LTE_NAS_SERVICE_REQUEST_FAILED) == LTE_NAS_SERVICE_REQUEST_FAILED) {
            list.add("LTE_NAS_SERVICE_REQUEST_FAILED");
            flipped |= LTE_NAS_SERVICE_REQUEST_FAILED;
        }
        if ((o & DUPLICATE_BEARER_ID) == DUPLICATE_BEARER_ID) {
            list.add("DUPLICATE_BEARER_ID");
            flipped |= DUPLICATE_BEARER_ID;
        }
        if ((o & ESM_COLLISION_SCENARIOS) == ESM_COLLISION_SCENARIOS) {
            list.add("ESM_COLLISION_SCENARIOS");
            flipped |= ESM_COLLISION_SCENARIOS;
        }
        if ((o & ESM_BEARER_DEACTIVATED_TO_SYNC_WITH_NETWORK) == ESM_BEARER_DEACTIVATED_TO_SYNC_WITH_NETWORK) {
            list.add("ESM_BEARER_DEACTIVATED_TO_SYNC_WITH_NETWORK");
            flipped |= ESM_BEARER_DEACTIVATED_TO_SYNC_WITH_NETWORK;
        }
        if ((o & ESM_NW_ACTIVATED_DED_BEARER_WITH_ID_OF_DEF_BEARER) == ESM_NW_ACTIVATED_DED_BEARER_WITH_ID_OF_DEF_BEARER) {
            list.add("ESM_NW_ACTIVATED_DED_BEARER_WITH_ID_OF_DEF_BEARER");
            flipped |= ESM_NW_ACTIVATED_DED_BEARER_WITH_ID_OF_DEF_BEARER;
        }
        if ((o & ESM_BAD_OTA_MESSAGE) == ESM_BAD_OTA_MESSAGE) {
            list.add("ESM_BAD_OTA_MESSAGE");
            flipped |= ESM_BAD_OTA_MESSAGE;
        }
        if ((o & ESM_DOWNLOAD_SERVER_REJECTED_THE_CALL) == ESM_DOWNLOAD_SERVER_REJECTED_THE_CALL) {
            list.add("ESM_DOWNLOAD_SERVER_REJECTED_THE_CALL");
            flipped |= ESM_DOWNLOAD_SERVER_REJECTED_THE_CALL;
        }
        if ((o & ESM_CONTEXT_TRANSFERRED_DUE_TO_IRAT) == ESM_CONTEXT_TRANSFERRED_DUE_TO_IRAT) {
            list.add("ESM_CONTEXT_TRANSFERRED_DUE_TO_IRAT");
            flipped |= ESM_CONTEXT_TRANSFERRED_DUE_TO_IRAT;
        }
        if ((o & DS_EXPLICIT_DEACTIVATION) == DS_EXPLICIT_DEACTIVATION) {
            list.add("DS_EXPLICIT_DEACTIVATION");
            flipped |= DS_EXPLICIT_DEACTIVATION;
        }
        if ((o & ESM_LOCAL_CAUSE_NONE) == ESM_LOCAL_CAUSE_NONE) {
            list.add("ESM_LOCAL_CAUSE_NONE");
            flipped |= ESM_LOCAL_CAUSE_NONE;
        }
        if ((o & LTE_THROTTLING_NOT_REQUIRED) == LTE_THROTTLING_NOT_REQUIRED) {
            list.add("LTE_THROTTLING_NOT_REQUIRED");
            flipped |= LTE_THROTTLING_NOT_REQUIRED;
        }
        if ((o & ACCESS_CONTROL_LIST_CHECK_FAILURE) == ACCESS_CONTROL_LIST_CHECK_FAILURE) {
            list.add("ACCESS_CONTROL_LIST_CHECK_FAILURE");
            flipped |= ACCESS_CONTROL_LIST_CHECK_FAILURE;
        }
        if ((o & SERVICE_NOT_ALLOWED_ON_PLMN) == SERVICE_NOT_ALLOWED_ON_PLMN) {
            list.add("SERVICE_NOT_ALLOWED_ON_PLMN");
            flipped |= SERVICE_NOT_ALLOWED_ON_PLMN;
        }
        if ((o & EMM_T3417_EXPIRED) == EMM_T3417_EXPIRED) {
            list.add("EMM_T3417_EXPIRED");
            flipped |= EMM_T3417_EXPIRED;
        }
        if ((o & EMM_T3417_EXT_EXPIRED) == EMM_T3417_EXT_EXPIRED) {
            list.add("EMM_T3417_EXT_EXPIRED");
            flipped |= EMM_T3417_EXT_EXPIRED;
        }
        if ((o & RRC_UPLINK_DATA_TRANSMISSION_FAILURE) == RRC_UPLINK_DATA_TRANSMISSION_FAILURE) {
            list.add("RRC_UPLINK_DATA_TRANSMISSION_FAILURE");
            flipped |= RRC_UPLINK_DATA_TRANSMISSION_FAILURE;
        }
        if ((o & RRC_UPLINK_DELIVERY_FAILED_DUE_TO_HANDOVER) == RRC_UPLINK_DELIVERY_FAILED_DUE_TO_HANDOVER) {
            list.add("RRC_UPLINK_DELIVERY_FAILED_DUE_TO_HANDOVER");
            flipped |= RRC_UPLINK_DELIVERY_FAILED_DUE_TO_HANDOVER;
        }
        if ((o & RRC_UPLINK_CONNECTION_RELEASE) == RRC_UPLINK_CONNECTION_RELEASE) {
            list.add("RRC_UPLINK_CONNECTION_RELEASE");
            flipped |= RRC_UPLINK_CONNECTION_RELEASE;
        }
        if ((o & RRC_UPLINK_RADIO_LINK_FAILURE) == RRC_UPLINK_RADIO_LINK_FAILURE) {
            list.add("RRC_UPLINK_RADIO_LINK_FAILURE");
            flipped |= RRC_UPLINK_RADIO_LINK_FAILURE;
        }
        if ((o & RRC_UPLINK_ERROR_REQUEST_FROM_NAS) == RRC_UPLINK_ERROR_REQUEST_FROM_NAS) {
            list.add("RRC_UPLINK_ERROR_REQUEST_FROM_NAS");
            flipped |= RRC_UPLINK_ERROR_REQUEST_FROM_NAS;
        }
        if ((o & RRC_CONNECTION_ACCESS_STRATUM_FAILURE) == RRC_CONNECTION_ACCESS_STRATUM_FAILURE) {
            list.add("RRC_CONNECTION_ACCESS_STRATUM_FAILURE");
            flipped |= RRC_CONNECTION_ACCESS_STRATUM_FAILURE;
        }
        if ((o & RRC_CONNECTION_ANOTHER_PROCEDURE_IN_PROGRESS) == RRC_CONNECTION_ANOTHER_PROCEDURE_IN_PROGRESS) {
            list.add("RRC_CONNECTION_ANOTHER_PROCEDURE_IN_PROGRESS");
            flipped |= RRC_CONNECTION_ANOTHER_PROCEDURE_IN_PROGRESS;
        }
        if ((o & RRC_CONNECTION_ACCESS_BARRED) == RRC_CONNECTION_ACCESS_BARRED) {
            list.add("RRC_CONNECTION_ACCESS_BARRED");
            flipped |= RRC_CONNECTION_ACCESS_BARRED;
        }
        if ((o & RRC_CONNECTION_CELL_RESELECTION) == RRC_CONNECTION_CELL_RESELECTION) {
            list.add("RRC_CONNECTION_CELL_RESELECTION");
            flipped |= RRC_CONNECTION_CELL_RESELECTION;
        }
        if ((o & RRC_CONNECTION_CONFIG_FAILURE) == RRC_CONNECTION_CONFIG_FAILURE) {
            list.add("RRC_CONNECTION_CONFIG_FAILURE");
            flipped |= RRC_CONNECTION_CONFIG_FAILURE;
        }
        if ((o & RRC_CONNECTION_TIMER_EXPIRED) == RRC_CONNECTION_TIMER_EXPIRED) {
            list.add("RRC_CONNECTION_TIMER_EXPIRED");
            flipped |= RRC_CONNECTION_TIMER_EXPIRED;
        }
        if ((o & RRC_CONNECTION_LINK_FAILURE) == RRC_CONNECTION_LINK_FAILURE) {
            list.add("RRC_CONNECTION_LINK_FAILURE");
            flipped |= RRC_CONNECTION_LINK_FAILURE;
        }
        if ((o & RRC_CONNECTION_CELL_NOT_CAMPED) == RRC_CONNECTION_CELL_NOT_CAMPED) {
            list.add("RRC_CONNECTION_CELL_NOT_CAMPED");
            flipped |= RRC_CONNECTION_CELL_NOT_CAMPED;
        }
        if ((o & RRC_CONNECTION_SYSTEM_INTERVAL_FAILURE) == RRC_CONNECTION_SYSTEM_INTERVAL_FAILURE) {
            list.add("RRC_CONNECTION_SYSTEM_INTERVAL_FAILURE");
            flipped |= RRC_CONNECTION_SYSTEM_INTERVAL_FAILURE;
        }
        if ((o & RRC_CONNECTION_REJECT_BY_NETWORK) == RRC_CONNECTION_REJECT_BY_NETWORK) {
            list.add("RRC_CONNECTION_REJECT_BY_NETWORK");
            flipped |= RRC_CONNECTION_REJECT_BY_NETWORK;
        }
        if ((o & RRC_CONNECTION_NORMAL_RELEASE) == RRC_CONNECTION_NORMAL_RELEASE) {
            list.add("RRC_CONNECTION_NORMAL_RELEASE");
            flipped |= RRC_CONNECTION_NORMAL_RELEASE;
        }
        if ((o & RRC_CONNECTION_RADIO_LINK_FAILURE) == RRC_CONNECTION_RADIO_LINK_FAILURE) {
            list.add("RRC_CONNECTION_RADIO_LINK_FAILURE");
            flipped |= RRC_CONNECTION_RADIO_LINK_FAILURE;
        }
        if ((o & RRC_CONNECTION_REESTABLISHMENT_FAILURE) == RRC_CONNECTION_REESTABLISHMENT_FAILURE) {
            list.add("RRC_CONNECTION_REESTABLISHMENT_FAILURE");
            flipped |= RRC_CONNECTION_REESTABLISHMENT_FAILURE;
        }
        if ((o & RRC_CONNECTION_OUT_OF_SERVICE_DURING_CELL_REGISTER) == RRC_CONNECTION_OUT_OF_SERVICE_DURING_CELL_REGISTER) {
            list.add("RRC_CONNECTION_OUT_OF_SERVICE_DURING_CELL_REGISTER");
            flipped |= RRC_CONNECTION_OUT_OF_SERVICE_DURING_CELL_REGISTER;
        }
        if ((o & RRC_CONNECTION_ABORT_REQUEST) == RRC_CONNECTION_ABORT_REQUEST) {
            list.add("RRC_CONNECTION_ABORT_REQUEST");
            flipped |= RRC_CONNECTION_ABORT_REQUEST;
        }
        if ((o & RRC_CONNECTION_SYSTEM_INFORMATION_BLOCK_READ_ERROR) == RRC_CONNECTION_SYSTEM_INFORMATION_BLOCK_READ_ERROR) {
            list.add("RRC_CONNECTION_SYSTEM_INFORMATION_BLOCK_READ_ERROR");
            flipped |= RRC_CONNECTION_SYSTEM_INFORMATION_BLOCK_READ_ERROR;
        }
        if ((o & NETWORK_INITIATED_DETACH_WITH_AUTO_REATTACH) == NETWORK_INITIATED_DETACH_WITH_AUTO_REATTACH) {
            list.add("NETWORK_INITIATED_DETACH_WITH_AUTO_REATTACH");
            flipped |= NETWORK_INITIATED_DETACH_WITH_AUTO_REATTACH;
        }
        if ((o & NETWORK_INITIATED_DETACH_NO_AUTO_REATTACH) == NETWORK_INITIATED_DETACH_NO_AUTO_REATTACH) {
            list.add("NETWORK_INITIATED_DETACH_NO_AUTO_REATTACH");
            flipped |= NETWORK_INITIATED_DETACH_NO_AUTO_REATTACH;
        }
        if ((o & ESM_PROCEDURE_TIME_OUT) == ESM_PROCEDURE_TIME_OUT) {
            list.add("ESM_PROCEDURE_TIME_OUT");
            flipped |= ESM_PROCEDURE_TIME_OUT;
        }
        if ((o & INVALID_CONNECTION_ID) == INVALID_CONNECTION_ID) {
            list.add("INVALID_CONNECTION_ID");
            flipped |= INVALID_CONNECTION_ID;
        }
        if ((o & MAXIMIUM_NSAPIS_EXCEEDED) == MAXIMIUM_NSAPIS_EXCEEDED) {
            list.add("MAXIMIUM_NSAPIS_EXCEEDED");
            flipped |= MAXIMIUM_NSAPIS_EXCEEDED;
        }
        if ((o & INVALID_PRIMARY_NSAPI) == INVALID_PRIMARY_NSAPI) {
            list.add("INVALID_PRIMARY_NSAPI");
            flipped |= INVALID_PRIMARY_NSAPI;
        }
        if ((o & CANNOT_ENCODE_OTA_MESSAGE) == CANNOT_ENCODE_OTA_MESSAGE) {
            list.add("CANNOT_ENCODE_OTA_MESSAGE");
            flipped |= CANNOT_ENCODE_OTA_MESSAGE;
        }
        if ((o & RADIO_ACCESS_BEARER_SETUP_FAILURE) == RADIO_ACCESS_BEARER_SETUP_FAILURE) {
            list.add("RADIO_ACCESS_BEARER_SETUP_FAILURE");
            flipped |= RADIO_ACCESS_BEARER_SETUP_FAILURE;
        }
        if ((o & PDP_ESTABLISH_TIMEOUT_EXPIRED) == PDP_ESTABLISH_TIMEOUT_EXPIRED) {
            list.add("PDP_ESTABLISH_TIMEOUT_EXPIRED");
            flipped |= PDP_ESTABLISH_TIMEOUT_EXPIRED;
        }
        if ((o & PDP_MODIFY_TIMEOUT_EXPIRED) == PDP_MODIFY_TIMEOUT_EXPIRED) {
            list.add("PDP_MODIFY_TIMEOUT_EXPIRED");
            flipped |= PDP_MODIFY_TIMEOUT_EXPIRED;
        }
        if ((o & PDP_INACTIVE_TIMEOUT_EXPIRED) == PDP_INACTIVE_TIMEOUT_EXPIRED) {
            list.add("PDP_INACTIVE_TIMEOUT_EXPIRED");
            flipped |= PDP_INACTIVE_TIMEOUT_EXPIRED;
        }
        if ((o & PDP_LOWERLAYER_ERROR) == PDP_LOWERLAYER_ERROR) {
            list.add("PDP_LOWERLAYER_ERROR");
            flipped |= PDP_LOWERLAYER_ERROR;
        }
        if ((o & PDP_MODIFY_COLLISION) == PDP_MODIFY_COLLISION) {
            list.add("PDP_MODIFY_COLLISION");
            flipped |= PDP_MODIFY_COLLISION;
        }
        if ((o & MAXINUM_SIZE_OF_L2_MESSAGE_EXCEEDED) == MAXINUM_SIZE_OF_L2_MESSAGE_EXCEEDED) {
            list.add("MAXINUM_SIZE_OF_L2_MESSAGE_EXCEEDED");
            flipped |= MAXINUM_SIZE_OF_L2_MESSAGE_EXCEEDED;
        }
        if ((o & NAS_REQUEST_REJECTED_BY_NETWORK) == NAS_REQUEST_REJECTED_BY_NETWORK) {
            list.add("NAS_REQUEST_REJECTED_BY_NETWORK");
            flipped |= NAS_REQUEST_REJECTED_BY_NETWORK;
        }
        if ((o & RRC_CONNECTION_INVALID_REQUEST) == RRC_CONNECTION_INVALID_REQUEST) {
            list.add("RRC_CONNECTION_INVALID_REQUEST");
            flipped |= RRC_CONNECTION_INVALID_REQUEST;
        }
        if ((o & RRC_CONNECTION_TRACKING_AREA_ID_CHANGED) == RRC_CONNECTION_TRACKING_AREA_ID_CHANGED) {
            list.add("RRC_CONNECTION_TRACKING_AREA_ID_CHANGED");
            flipped |= RRC_CONNECTION_TRACKING_AREA_ID_CHANGED;
        }
        if ((o & RRC_CONNECTION_RF_UNAVAILABLE) == RRC_CONNECTION_RF_UNAVAILABLE) {
            list.add("RRC_CONNECTION_RF_UNAVAILABLE");
            flipped |= RRC_CONNECTION_RF_UNAVAILABLE;
        }
        if ((o & RRC_CONNECTION_ABORTED_DUE_TO_IRAT_CHANGE) == RRC_CONNECTION_ABORTED_DUE_TO_IRAT_CHANGE) {
            list.add("RRC_CONNECTION_ABORTED_DUE_TO_IRAT_CHANGE");
            flipped |= RRC_CONNECTION_ABORTED_DUE_TO_IRAT_CHANGE;
        }
        if ((o & RRC_CONNECTION_RELEASED_SECURITY_NOT_ACTIVE) == RRC_CONNECTION_RELEASED_SECURITY_NOT_ACTIVE) {
            list.add("RRC_CONNECTION_RELEASED_SECURITY_NOT_ACTIVE");
            flipped |= RRC_CONNECTION_RELEASED_SECURITY_NOT_ACTIVE;
        }
        if ((o & RRC_CONNECTION_ABORTED_AFTER_HANDOVER) == RRC_CONNECTION_ABORTED_AFTER_HANDOVER) {
            list.add("RRC_CONNECTION_ABORTED_AFTER_HANDOVER");
            flipped |= RRC_CONNECTION_ABORTED_AFTER_HANDOVER;
        }
        if ((o & RRC_CONNECTION_ABORTED_AFTER_IRAT_CELL_CHANGE) == RRC_CONNECTION_ABORTED_AFTER_IRAT_CELL_CHANGE) {
            list.add("RRC_CONNECTION_ABORTED_AFTER_IRAT_CELL_CHANGE");
            flipped |= RRC_CONNECTION_ABORTED_AFTER_IRAT_CELL_CHANGE;
        }
        if ((o & RRC_CONNECTION_ABORTED_DURING_IRAT_CELL_CHANGE) == RRC_CONNECTION_ABORTED_DURING_IRAT_CELL_CHANGE) {
            list.add("RRC_CONNECTION_ABORTED_DURING_IRAT_CELL_CHANGE");
            flipped |= RRC_CONNECTION_ABORTED_DURING_IRAT_CELL_CHANGE;
        }
        if ((o & IMSI_UNKNOWN_IN_HOME_SUBSCRIBER_SERVER) == IMSI_UNKNOWN_IN_HOME_SUBSCRIBER_SERVER) {
            list.add("IMSI_UNKNOWN_IN_HOME_SUBSCRIBER_SERVER");
            flipped |= IMSI_UNKNOWN_IN_HOME_SUBSCRIBER_SERVER;
        }
        if ((o & IMEI_NOT_ACCEPTED) == IMEI_NOT_ACCEPTED) {
            list.add("IMEI_NOT_ACCEPTED");
            flipped |= IMEI_NOT_ACCEPTED;
        }
        if ((o & EPS_SERVICES_AND_NON_EPS_SERVICES_NOT_ALLOWED) == EPS_SERVICES_AND_NON_EPS_SERVICES_NOT_ALLOWED) {
            list.add("EPS_SERVICES_AND_NON_EPS_SERVICES_NOT_ALLOWED");
            flipped |= EPS_SERVICES_AND_NON_EPS_SERVICES_NOT_ALLOWED;
        }
        if ((o & EPS_SERVICES_NOT_ALLOWED_IN_PLMN) == EPS_SERVICES_NOT_ALLOWED_IN_PLMN) {
            list.add("EPS_SERVICES_NOT_ALLOWED_IN_PLMN");
            flipped |= EPS_SERVICES_NOT_ALLOWED_IN_PLMN;
        }
        if ((o & MSC_TEMPORARILY_NOT_REACHABLE) == MSC_TEMPORARILY_NOT_REACHABLE) {
            list.add("MSC_TEMPORARILY_NOT_REACHABLE");
            flipped |= MSC_TEMPORARILY_NOT_REACHABLE;
        }
        if ((o & CS_DOMAIN_NOT_AVAILABLE) == CS_DOMAIN_NOT_AVAILABLE) {
            list.add("CS_DOMAIN_NOT_AVAILABLE");
            flipped |= CS_DOMAIN_NOT_AVAILABLE;
        }
        if ((o & ESM_FAILURE) == ESM_FAILURE) {
            list.add("ESM_FAILURE");
            flipped |= ESM_FAILURE;
        }
        if ((o & MAC_FAILURE) == MAC_FAILURE) {
            list.add("MAC_FAILURE");
            flipped |= MAC_FAILURE;
        }
        if ((o & SYNCHRONIZATION_FAILURE) == SYNCHRONIZATION_FAILURE) {
            list.add("SYNCHRONIZATION_FAILURE");
            flipped |= SYNCHRONIZATION_FAILURE;
        }
        if ((o & UE_SECURITY_CAPABILITIES_MISMATCH) == UE_SECURITY_CAPABILITIES_MISMATCH) {
            list.add("UE_SECURITY_CAPABILITIES_MISMATCH");
            flipped |= UE_SECURITY_CAPABILITIES_MISMATCH;
        }
        if ((o & SECURITY_MODE_REJECTED) == SECURITY_MODE_REJECTED) {
            list.add("SECURITY_MODE_REJECTED");
            flipped |= SECURITY_MODE_REJECTED;
        }
        if ((o & UNACCEPTABLE_NON_EPS_AUTHENTICATION) == UNACCEPTABLE_NON_EPS_AUTHENTICATION) {
            list.add("UNACCEPTABLE_NON_EPS_AUTHENTICATION");
            flipped |= UNACCEPTABLE_NON_EPS_AUTHENTICATION;
        }
        if ((o & CS_FALLBACK_CALL_ESTABLISHMENT_NOT_ALLOWED) == CS_FALLBACK_CALL_ESTABLISHMENT_NOT_ALLOWED) {
            list.add("CS_FALLBACK_CALL_ESTABLISHMENT_NOT_ALLOWED");
            flipped |= CS_FALLBACK_CALL_ESTABLISHMENT_NOT_ALLOWED;
        }
        if ((o & NO_EPS_BEARER_CONTEXT_ACTIVATED) == NO_EPS_BEARER_CONTEXT_ACTIVATED) {
            list.add("NO_EPS_BEARER_CONTEXT_ACTIVATED");
            flipped |= NO_EPS_BEARER_CONTEXT_ACTIVATED;
        }
        if ((o & INVALID_EMM_STATE) == INVALID_EMM_STATE) {
            list.add("INVALID_EMM_STATE");
            flipped |= INVALID_EMM_STATE;
        }
        if ((o & NAS_LAYER_FAILURE) == NAS_LAYER_FAILURE) {
            list.add("NAS_LAYER_FAILURE");
            flipped |= NAS_LAYER_FAILURE;
        }
        if ((o & MULTIPLE_PDP_CALL_NOT_ALLOWED) == MULTIPLE_PDP_CALL_NOT_ALLOWED) {
            list.add("MULTIPLE_PDP_CALL_NOT_ALLOWED");
            flipped |= MULTIPLE_PDP_CALL_NOT_ALLOWED;
        }
        if ((o & EMBMS_NOT_ENABLED) == EMBMS_NOT_ENABLED) {
            list.add("EMBMS_NOT_ENABLED");
            flipped |= EMBMS_NOT_ENABLED;
        }
        if ((o & IRAT_HANDOVER_FAILED) == IRAT_HANDOVER_FAILED) {
            list.add("IRAT_HANDOVER_FAILED");
            flipped |= IRAT_HANDOVER_FAILED;
        }
        if ((o & EMBMS_REGULAR_DEACTIVATION) == EMBMS_REGULAR_DEACTIVATION) {
            list.add("EMBMS_REGULAR_DEACTIVATION");
            flipped |= EMBMS_REGULAR_DEACTIVATION;
        }
        if ((o & TEST_LOOPBACK_REGULAR_DEACTIVATION) == TEST_LOOPBACK_REGULAR_DEACTIVATION) {
            list.add("TEST_LOOPBACK_REGULAR_DEACTIVATION");
            flipped |= TEST_LOOPBACK_REGULAR_DEACTIVATION;
        }
        if ((o & LOWER_LAYER_REGISTRATION_FAILURE) == LOWER_LAYER_REGISTRATION_FAILURE) {
            list.add("LOWER_LAYER_REGISTRATION_FAILURE");
            flipped |= LOWER_LAYER_REGISTRATION_FAILURE;
        }
        if ((o & DATA_PLAN_EXPIRED) == DATA_PLAN_EXPIRED) {
            list.add("DATA_PLAN_EXPIRED");
            flipped |= DATA_PLAN_EXPIRED;
        }
        if ((o & UMTS_HANDOVER_TO_IWLAN) == UMTS_HANDOVER_TO_IWLAN) {
            list.add("UMTS_HANDOVER_TO_IWLAN");
            flipped |= UMTS_HANDOVER_TO_IWLAN;
        }
        if ((o & EVDO_CONNECTION_DENY_BY_GENERAL_OR_NETWORK_BUSY) == EVDO_CONNECTION_DENY_BY_GENERAL_OR_NETWORK_BUSY) {
            list.add("EVDO_CONNECTION_DENY_BY_GENERAL_OR_NETWORK_BUSY");
            flipped |= EVDO_CONNECTION_DENY_BY_GENERAL_OR_NETWORK_BUSY;
        }
        if ((o & EVDO_CONNECTION_DENY_BY_BILLING_OR_AUTHENTICATION_FAILURE) == EVDO_CONNECTION_DENY_BY_BILLING_OR_AUTHENTICATION_FAILURE) {
            list.add("EVDO_CONNECTION_DENY_BY_BILLING_OR_AUTHENTICATION_FAILURE");
            flipped |= EVDO_CONNECTION_DENY_BY_BILLING_OR_AUTHENTICATION_FAILURE;
        }
        if ((o & EVDO_HDR_CHANGED) == EVDO_HDR_CHANGED) {
            list.add("EVDO_HDR_CHANGED");
            flipped |= EVDO_HDR_CHANGED;
        }
        if ((o & EVDO_HDR_EXITED) == EVDO_HDR_EXITED) {
            list.add("EVDO_HDR_EXITED");
            flipped |= EVDO_HDR_EXITED;
        }
        if ((o & EVDO_HDR_NO_SESSION) == EVDO_HDR_NO_SESSION) {
            list.add("EVDO_HDR_NO_SESSION");
            flipped |= EVDO_HDR_NO_SESSION;
        }
        if ((o & EVDO_USING_GPS_FIX_INSTEAD_OF_HDR_CALL) == EVDO_USING_GPS_FIX_INSTEAD_OF_HDR_CALL) {
            list.add("EVDO_USING_GPS_FIX_INSTEAD_OF_HDR_CALL");
            flipped |= EVDO_USING_GPS_FIX_INSTEAD_OF_HDR_CALL;
        }
        if ((o & EVDO_HDR_CONNECTION_SETUP_TIMEOUT) == EVDO_HDR_CONNECTION_SETUP_TIMEOUT) {
            list.add("EVDO_HDR_CONNECTION_SETUP_TIMEOUT");
            flipped |= EVDO_HDR_CONNECTION_SETUP_TIMEOUT;
        }
        if ((o & FAILED_TO_ACQUIRE_COLOCATED_HDR) == FAILED_TO_ACQUIRE_COLOCATED_HDR) {
            list.add("FAILED_TO_ACQUIRE_COLOCATED_HDR");
            flipped |= FAILED_TO_ACQUIRE_COLOCATED_HDR;
        }
        if ((o & OTASP_COMMIT_IN_PROGRESS) == OTASP_COMMIT_IN_PROGRESS) {
            list.add("OTASP_COMMIT_IN_PROGRESS");
            flipped |= OTASP_COMMIT_IN_PROGRESS;
        }
        if ((o & NO_HYBRID_HDR_SERVICE) == NO_HYBRID_HDR_SERVICE) {
            list.add("NO_HYBRID_HDR_SERVICE");
            flipped |= NO_HYBRID_HDR_SERVICE;
        }
        if ((o & HDR_NO_LOCK_GRANTED) == HDR_NO_LOCK_GRANTED) {
            list.add("HDR_NO_LOCK_GRANTED");
            flipped |= HDR_NO_LOCK_GRANTED;
        }
        if ((o & DBM_OR_SMS_IN_PROGRESS) == DBM_OR_SMS_IN_PROGRESS) {
            list.add("DBM_OR_SMS_IN_PROGRESS");
            flipped |= DBM_OR_SMS_IN_PROGRESS;
        }
        if ((o & HDR_FADE) == HDR_FADE) {
            list.add("HDR_FADE");
            flipped |= HDR_FADE;
        }
        if ((o & HDR_ACCESS_FAILURE) == HDR_ACCESS_FAILURE) {
            list.add("HDR_ACCESS_FAILURE");
            flipped |= HDR_ACCESS_FAILURE;
        }
        if ((o & UNSUPPORTED_1X_PREV) == UNSUPPORTED_1X_PREV) {
            list.add("UNSUPPORTED_1X_PREV");
            flipped |= UNSUPPORTED_1X_PREV;
        }
        if ((o & LOCAL_END) == LOCAL_END) {
            list.add("LOCAL_END");
            flipped |= LOCAL_END;
        }
        if ((o & NO_SERVICE) == NO_SERVICE) {
            list.add("NO_SERVICE");
            flipped |= NO_SERVICE;
        }
        if ((o & FADE) == FADE) {
            list.add("FADE");
            flipped |= FADE;
        }
        if ((o & NORMAL_RELEASE) == NORMAL_RELEASE) {
            list.add("NORMAL_RELEASE");
            flipped |= NORMAL_RELEASE;
        }
        if ((o & ACCESS_ATTEMPT_ALREADY_IN_PROGRESS) == ACCESS_ATTEMPT_ALREADY_IN_PROGRESS) {
            list.add("ACCESS_ATTEMPT_ALREADY_IN_PROGRESS");
            flipped |= ACCESS_ATTEMPT_ALREADY_IN_PROGRESS;
        }
        if ((o & REDIRECTION_OR_HANDOFF_IN_PROGRESS) == REDIRECTION_OR_HANDOFF_IN_PROGRESS) {
            list.add("REDIRECTION_OR_HANDOFF_IN_PROGRESS");
            flipped |= REDIRECTION_OR_HANDOFF_IN_PROGRESS;
        }
        if ((o & EMERGENCY_MODE) == EMERGENCY_MODE) {
            list.add("EMERGENCY_MODE");
            flipped |= EMERGENCY_MODE;
        }
        if ((o & PHONE_IN_USE) == PHONE_IN_USE) {
            list.add("PHONE_IN_USE");
            flipped |= PHONE_IN_USE;
        }
        if ((o & INVALID_MODE) == INVALID_MODE) {
            list.add("INVALID_MODE");
            flipped |= INVALID_MODE;
        }
        if ((o & INVALID_SIM_STATE) == INVALID_SIM_STATE) {
            list.add("INVALID_SIM_STATE");
            flipped |= INVALID_SIM_STATE;
        }
        if ((o & NO_COLLOCATED_HDR) == NO_COLLOCATED_HDR) {
            list.add("NO_COLLOCATED_HDR");
            flipped |= NO_COLLOCATED_HDR;
        }
        if ((o & UE_IS_ENTERING_POWERSAVE_MODE) == UE_IS_ENTERING_POWERSAVE_MODE) {
            list.add("UE_IS_ENTERING_POWERSAVE_MODE");
            flipped |= UE_IS_ENTERING_POWERSAVE_MODE;
        }
        if ((o & DUAL_SWITCH) == DUAL_SWITCH) {
            list.add("DUAL_SWITCH");
            flipped |= DUAL_SWITCH;
        }
        if ((o & PPP_TIMEOUT) == PPP_TIMEOUT) {
            list.add("PPP_TIMEOUT");
            flipped |= PPP_TIMEOUT;
        }
        if ((o & PPP_AUTH_FAILURE) == PPP_AUTH_FAILURE) {
            list.add("PPP_AUTH_FAILURE");
            flipped |= PPP_AUTH_FAILURE;
        }
        if ((o & PPP_OPTION_MISMATCH) == PPP_OPTION_MISMATCH) {
            list.add("PPP_OPTION_MISMATCH");
            flipped |= PPP_OPTION_MISMATCH;
        }
        if ((o & PPP_PAP_FAILURE) == PPP_PAP_FAILURE) {
            list.add("PPP_PAP_FAILURE");
            flipped |= PPP_PAP_FAILURE;
        }
        if ((o & PPP_CHAP_FAILURE) == PPP_CHAP_FAILURE) {
            list.add("PPP_CHAP_FAILURE");
            flipped |= PPP_CHAP_FAILURE;
        }
        if ((o & PPP_CLOSE_IN_PROGRESS) == PPP_CLOSE_IN_PROGRESS) {
            list.add("PPP_CLOSE_IN_PROGRESS");
            flipped |= PPP_CLOSE_IN_PROGRESS;
        }
        if ((o & LIMITED_TO_IPV4) == LIMITED_TO_IPV4) {
            list.add("LIMITED_TO_IPV4");
            flipped |= LIMITED_TO_IPV4;
        }
        if ((o & LIMITED_TO_IPV6) == LIMITED_TO_IPV6) {
            list.add("LIMITED_TO_IPV6");
            flipped |= LIMITED_TO_IPV6;
        }
        if ((o & VSNCP_TIMEOUT) == VSNCP_TIMEOUT) {
            list.add("VSNCP_TIMEOUT");
            flipped |= VSNCP_TIMEOUT;
        }
        if ((o & VSNCP_GEN_ERROR) == VSNCP_GEN_ERROR) {
            list.add("VSNCP_GEN_ERROR");
            flipped |= VSNCP_GEN_ERROR;
        }
        if ((o & VSNCP_APN_UNATHORIZED) == VSNCP_APN_UNATHORIZED) {
            list.add("VSNCP_APN_UNATHORIZED");
            flipped |= VSNCP_APN_UNATHORIZED;
        }
        if ((o & VSNCP_PDN_LIMIT_EXCEEDED) == VSNCP_PDN_LIMIT_EXCEEDED) {
            list.add("VSNCP_PDN_LIMIT_EXCEEDED");
            flipped |= VSNCP_PDN_LIMIT_EXCEEDED;
        }
        if ((o & VSNCP_NO_PDN_GATEWAY_ADDRESS) == VSNCP_NO_PDN_GATEWAY_ADDRESS) {
            list.add("VSNCP_NO_PDN_GATEWAY_ADDRESS");
            flipped |= VSNCP_NO_PDN_GATEWAY_ADDRESS;
        }
        if ((o & VSNCP_PDN_GATEWAY_UNREACHABLE) == VSNCP_PDN_GATEWAY_UNREACHABLE) {
            list.add("VSNCP_PDN_GATEWAY_UNREACHABLE");
            flipped |= VSNCP_PDN_GATEWAY_UNREACHABLE;
        }
        if ((o & VSNCP_PDN_GATEWAY_REJECT) == VSNCP_PDN_GATEWAY_REJECT) {
            list.add("VSNCP_PDN_GATEWAY_REJECT");
            flipped |= VSNCP_PDN_GATEWAY_REJECT;
        }
        if ((o & VSNCP_INSUFFICIENT_PARAMETERS) == VSNCP_INSUFFICIENT_PARAMETERS) {
            list.add("VSNCP_INSUFFICIENT_PARAMETERS");
            flipped |= VSNCP_INSUFFICIENT_PARAMETERS;
        }
        if ((o & VSNCP_RESOURCE_UNAVAILABLE) == VSNCP_RESOURCE_UNAVAILABLE) {
            list.add("VSNCP_RESOURCE_UNAVAILABLE");
            flipped |= VSNCP_RESOURCE_UNAVAILABLE;
        }
        if ((o & VSNCP_ADMINISTRATIVELY_PROHIBITED) == VSNCP_ADMINISTRATIVELY_PROHIBITED) {
            list.add("VSNCP_ADMINISTRATIVELY_PROHIBITED");
            flipped |= VSNCP_ADMINISTRATIVELY_PROHIBITED;
        }
        if ((o & VSNCP_PDN_ID_IN_USE) == VSNCP_PDN_ID_IN_USE) {
            list.add("VSNCP_PDN_ID_IN_USE");
            flipped |= VSNCP_PDN_ID_IN_USE;
        }
        if ((o & VSNCP_SUBSCRIBER_LIMITATION) == VSNCP_SUBSCRIBER_LIMITATION) {
            list.add("VSNCP_SUBSCRIBER_LIMITATION");
            flipped |= VSNCP_SUBSCRIBER_LIMITATION;
        }
        if ((o & VSNCP_PDN_EXISTS_FOR_THIS_APN) == VSNCP_PDN_EXISTS_FOR_THIS_APN) {
            list.add("VSNCP_PDN_EXISTS_FOR_THIS_APN");
            flipped |= VSNCP_PDN_EXISTS_FOR_THIS_APN;
        }
        if ((o & VSNCP_RECONNECT_NOT_ALLOWED) == VSNCP_RECONNECT_NOT_ALLOWED) {
            list.add("VSNCP_RECONNECT_NOT_ALLOWED");
            flipped |= VSNCP_RECONNECT_NOT_ALLOWED;
        }
        if ((o & IPV6_PREFIX_UNAVAILABLE) == IPV6_PREFIX_UNAVAILABLE) {
            list.add("IPV6_PREFIX_UNAVAILABLE");
            flipped |= IPV6_PREFIX_UNAVAILABLE;
        }
        if ((o & HANDOFF_PREFERENCE_CHANGED) == HANDOFF_PREFERENCE_CHANGED) {
            list.add("HANDOFF_PREFERENCE_CHANGED");
            flipped |= HANDOFF_PREFERENCE_CHANGED;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

