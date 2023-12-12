package android.hardware.radio.V1_0;


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
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

