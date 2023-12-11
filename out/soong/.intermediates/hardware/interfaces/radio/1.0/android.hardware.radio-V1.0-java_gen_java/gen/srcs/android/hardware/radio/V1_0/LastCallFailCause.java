package android.hardware.radio.V1_0;


public final class LastCallFailCause {
    public static final int UNOBTAINABLE_NUMBER = 1;
    public static final int NO_ROUTE_TO_DESTINATION = 3;
    public static final int CHANNEL_UNACCEPTABLE = 6;
    public static final int OPERATOR_DETERMINED_BARRING = 8;
    public static final int NORMAL = 16;
    public static final int BUSY = 17;
    public static final int NO_USER_RESPONDING = 18;
    public static final int NO_ANSWER_FROM_USER = 19;
    public static final int CALL_REJECTED = 21;
    public static final int NUMBER_CHANGED = 22;
    public static final int PREEMPTION = 25;
    public static final int DESTINATION_OUT_OF_ORDER = 27;
    public static final int INVALID_NUMBER_FORMAT = 28;
    public static final int FACILITY_REJECTED = 29;
    public static final int RESP_TO_STATUS_ENQUIRY = 30;
    public static final int NORMAL_UNSPECIFIED = 31;
    public static final int CONGESTION = 34;
    public static final int NETWORK_OUT_OF_ORDER = 38;
    public static final int TEMPORARY_FAILURE = 41;
    public static final int SWITCHING_EQUIPMENT_CONGESTION = 42;
    public static final int ACCESS_INFORMATION_DISCARDED = 43;
    public static final int REQUESTED_CIRCUIT_OR_CHANNEL_NOT_AVAILABLE = 44;
    public static final int RESOURCES_UNAVAILABLE_OR_UNSPECIFIED = 47;
    public static final int QOS_UNAVAILABLE = 49;
    public static final int REQUESTED_FACILITY_NOT_SUBSCRIBED = 50;
    public static final int INCOMING_CALLS_BARRED_WITHIN_CUG = 55;
    public static final int BEARER_CAPABILITY_NOT_AUTHORIZED = 57;
    public static final int BEARER_CAPABILITY_UNAVAILABLE = 58;
    public static final int SERVICE_OPTION_NOT_AVAILABLE = 63;
    public static final int BEARER_SERVICE_NOT_IMPLEMENTED = 65;
    public static final int ACM_LIMIT_EXCEEDED = 68;
    public static final int REQUESTED_FACILITY_NOT_IMPLEMENTED = 69;
    public static final int ONLY_DIGITAL_INFORMATION_BEARER_AVAILABLE = 70;
    public static final int SERVICE_OR_OPTION_NOT_IMPLEMENTED = 79;
    public static final int INVALID_TRANSACTION_IDENTIFIER = 81;
    public static final int USER_NOT_MEMBER_OF_CUG = 87;
    public static final int INCOMPATIBLE_DESTINATION = 88;
    public static final int INVALID_TRANSIT_NW_SELECTION = 91;
    public static final int SEMANTICALLY_INCORRECT_MESSAGE = 95;
    public static final int INVALID_MANDATORY_INFORMATION = 96;
    public static final int MESSAGE_TYPE_NON_IMPLEMENTED = 97;
    public static final int MESSAGE_TYPE_NOT_COMPATIBLE_WITH_PROTOCOL_STATE = 98;
    public static final int INFORMATION_ELEMENT_NON_EXISTENT = 99;
    public static final int CONDITIONAL_IE_ERROR = 100;
    public static final int MESSAGE_NOT_COMPATIBLE_WITH_PROTOCOL_STATE = 101;
    public static final int RECOVERY_ON_TIMER_EXPIRED = 102;
    public static final int PROTOCOL_ERROR_UNSPECIFIED = 111;
    public static final int INTERWORKING_UNSPECIFIED = 127;
    public static final int CALL_BARRED = 240;
    public static final int FDN_BLOCKED = 241;
    public static final int IMSI_UNKNOWN_IN_VLR = 242;
    public static final int IMEI_NOT_ACCEPTED = 243;
    public static final int DIAL_MODIFIED_TO_USSD = 244;
    public static final int DIAL_MODIFIED_TO_SS = 245;
    public static final int DIAL_MODIFIED_TO_DIAL = 246;
    public static final int RADIO_OFF = 247;
    public static final int OUT_OF_SERVICE = 248;
    public static final int NO_VALID_SIM = 249;
    public static final int RADIO_INTERNAL_ERROR = 250;
    public static final int NETWORK_RESP_TIMEOUT = 251;
    public static final int NETWORK_REJECT = 252;
    public static final int RADIO_ACCESS_FAILURE = 253;
    public static final int RADIO_LINK_FAILURE = 254;
    public static final int RADIO_LINK_LOST = 255;
    public static final int RADIO_UPLINK_FAILURE = 256;
    public static final int RADIO_SETUP_FAILURE = 257;
    public static final int RADIO_RELEASE_NORMAL = 258;
    public static final int RADIO_RELEASE_ABNORMAL = 259;
    public static final int ACCESS_CLASS_BLOCKED = 260;
    public static final int NETWORK_DETACH = 261;
    public static final int CDMA_LOCKED_UNTIL_POWER_CYCLE = 1000;
    public static final int CDMA_DROP = 1001;
    public static final int CDMA_INTERCEPT = 1002;
    public static final int CDMA_REORDER = 1003;
    public static final int CDMA_SO_REJECT = 1004;
    public static final int CDMA_RETRY_ORDER = 1005;
    public static final int CDMA_ACCESS_FAILURE = 1006;
    public static final int CDMA_PREEMPTED = 1007;
    public static final int CDMA_NOT_EMERGENCY = 1008;
    public static final int CDMA_ACCESS_BLOCKED = 1009;
    /**
     * OEM specific error codes. Used to distinguish error from
     * CALL_FAIL_ERROR_UNSPECIFIED and help assist debugging
     */
    public static final int OEM_CAUSE_1 = 61441 /* 0xf001 */;
    public static final int OEM_CAUSE_2 = 61442 /* 0xf002 */;
    public static final int OEM_CAUSE_3 = 61443 /* 0xf003 */;
    public static final int OEM_CAUSE_4 = 61444 /* 0xf004 */;
    public static final int OEM_CAUSE_5 = 61445 /* 0xf005 */;
    public static final int OEM_CAUSE_6 = 61446 /* 0xf006 */;
    public static final int OEM_CAUSE_7 = 61447 /* 0xf007 */;
    public static final int OEM_CAUSE_8 = 61448 /* 0xf008 */;
    public static final int OEM_CAUSE_9 = 61449 /* 0xf009 */;
    public static final int OEM_CAUSE_10 = 61450 /* 0xf00a */;
    public static final int OEM_CAUSE_11 = 61451 /* 0xf00b */;
    public static final int OEM_CAUSE_12 = 61452 /* 0xf00c */;
    public static final int OEM_CAUSE_13 = 61453 /* 0xf00d */;
    public static final int OEM_CAUSE_14 = 61454 /* 0xf00e */;
    public static final int OEM_CAUSE_15 = 61455 /* 0xf00f */;
    public static final int ERROR_UNSPECIFIED = 65535 /* 0xffff */;
    public static final String toString(int o) {
        if (o == UNOBTAINABLE_NUMBER) {
            return "UNOBTAINABLE_NUMBER";
        }
        if (o == NO_ROUTE_TO_DESTINATION) {
            return "NO_ROUTE_TO_DESTINATION";
        }
        if (o == CHANNEL_UNACCEPTABLE) {
            return "CHANNEL_UNACCEPTABLE";
        }
        if (o == OPERATOR_DETERMINED_BARRING) {
            return "OPERATOR_DETERMINED_BARRING";
        }
        if (o == NORMAL) {
            return "NORMAL";
        }
        if (o == BUSY) {
            return "BUSY";
        }
        if (o == NO_USER_RESPONDING) {
            return "NO_USER_RESPONDING";
        }
        if (o == NO_ANSWER_FROM_USER) {
            return "NO_ANSWER_FROM_USER";
        }
        if (o == CALL_REJECTED) {
            return "CALL_REJECTED";
        }
        if (o == NUMBER_CHANGED) {
            return "NUMBER_CHANGED";
        }
        if (o == PREEMPTION) {
            return "PREEMPTION";
        }
        if (o == DESTINATION_OUT_OF_ORDER) {
            return "DESTINATION_OUT_OF_ORDER";
        }
        if (o == INVALID_NUMBER_FORMAT) {
            return "INVALID_NUMBER_FORMAT";
        }
        if (o == FACILITY_REJECTED) {
            return "FACILITY_REJECTED";
        }
        if (o == RESP_TO_STATUS_ENQUIRY) {
            return "RESP_TO_STATUS_ENQUIRY";
        }
        if (o == NORMAL_UNSPECIFIED) {
            return "NORMAL_UNSPECIFIED";
        }
        if (o == CONGESTION) {
            return "CONGESTION";
        }
        if (o == NETWORK_OUT_OF_ORDER) {
            return "NETWORK_OUT_OF_ORDER";
        }
        if (o == TEMPORARY_FAILURE) {
            return "TEMPORARY_FAILURE";
        }
        if (o == SWITCHING_EQUIPMENT_CONGESTION) {
            return "SWITCHING_EQUIPMENT_CONGESTION";
        }
        if (o == ACCESS_INFORMATION_DISCARDED) {
            return "ACCESS_INFORMATION_DISCARDED";
        }
        if (o == REQUESTED_CIRCUIT_OR_CHANNEL_NOT_AVAILABLE) {
            return "REQUESTED_CIRCUIT_OR_CHANNEL_NOT_AVAILABLE";
        }
        if (o == RESOURCES_UNAVAILABLE_OR_UNSPECIFIED) {
            return "RESOURCES_UNAVAILABLE_OR_UNSPECIFIED";
        }
        if (o == QOS_UNAVAILABLE) {
            return "QOS_UNAVAILABLE";
        }
        if (o == REQUESTED_FACILITY_NOT_SUBSCRIBED) {
            return "REQUESTED_FACILITY_NOT_SUBSCRIBED";
        }
        if (o == INCOMING_CALLS_BARRED_WITHIN_CUG) {
            return "INCOMING_CALLS_BARRED_WITHIN_CUG";
        }
        if (o == BEARER_CAPABILITY_NOT_AUTHORIZED) {
            return "BEARER_CAPABILITY_NOT_AUTHORIZED";
        }
        if (o == BEARER_CAPABILITY_UNAVAILABLE) {
            return "BEARER_CAPABILITY_UNAVAILABLE";
        }
        if (o == SERVICE_OPTION_NOT_AVAILABLE) {
            return "SERVICE_OPTION_NOT_AVAILABLE";
        }
        if (o == BEARER_SERVICE_NOT_IMPLEMENTED) {
            return "BEARER_SERVICE_NOT_IMPLEMENTED";
        }
        if (o == ACM_LIMIT_EXCEEDED) {
            return "ACM_LIMIT_EXCEEDED";
        }
        if (o == REQUESTED_FACILITY_NOT_IMPLEMENTED) {
            return "REQUESTED_FACILITY_NOT_IMPLEMENTED";
        }
        if (o == ONLY_DIGITAL_INFORMATION_BEARER_AVAILABLE) {
            return "ONLY_DIGITAL_INFORMATION_BEARER_AVAILABLE";
        }
        if (o == SERVICE_OR_OPTION_NOT_IMPLEMENTED) {
            return "SERVICE_OR_OPTION_NOT_IMPLEMENTED";
        }
        if (o == INVALID_TRANSACTION_IDENTIFIER) {
            return "INVALID_TRANSACTION_IDENTIFIER";
        }
        if (o == USER_NOT_MEMBER_OF_CUG) {
            return "USER_NOT_MEMBER_OF_CUG";
        }
        if (o == INCOMPATIBLE_DESTINATION) {
            return "INCOMPATIBLE_DESTINATION";
        }
        if (o == INVALID_TRANSIT_NW_SELECTION) {
            return "INVALID_TRANSIT_NW_SELECTION";
        }
        if (o == SEMANTICALLY_INCORRECT_MESSAGE) {
            return "SEMANTICALLY_INCORRECT_MESSAGE";
        }
        if (o == INVALID_MANDATORY_INFORMATION) {
            return "INVALID_MANDATORY_INFORMATION";
        }
        if (o == MESSAGE_TYPE_NON_IMPLEMENTED) {
            return "MESSAGE_TYPE_NON_IMPLEMENTED";
        }
        if (o == MESSAGE_TYPE_NOT_COMPATIBLE_WITH_PROTOCOL_STATE) {
            return "MESSAGE_TYPE_NOT_COMPATIBLE_WITH_PROTOCOL_STATE";
        }
        if (o == INFORMATION_ELEMENT_NON_EXISTENT) {
            return "INFORMATION_ELEMENT_NON_EXISTENT";
        }
        if (o == CONDITIONAL_IE_ERROR) {
            return "CONDITIONAL_IE_ERROR";
        }
        if (o == MESSAGE_NOT_COMPATIBLE_WITH_PROTOCOL_STATE) {
            return "MESSAGE_NOT_COMPATIBLE_WITH_PROTOCOL_STATE";
        }
        if (o == RECOVERY_ON_TIMER_EXPIRED) {
            return "RECOVERY_ON_TIMER_EXPIRED";
        }
        if (o == PROTOCOL_ERROR_UNSPECIFIED) {
            return "PROTOCOL_ERROR_UNSPECIFIED";
        }
        if (o == INTERWORKING_UNSPECIFIED) {
            return "INTERWORKING_UNSPECIFIED";
        }
        if (o == CALL_BARRED) {
            return "CALL_BARRED";
        }
        if (o == FDN_BLOCKED) {
            return "FDN_BLOCKED";
        }
        if (o == IMSI_UNKNOWN_IN_VLR) {
            return "IMSI_UNKNOWN_IN_VLR";
        }
        if (o == IMEI_NOT_ACCEPTED) {
            return "IMEI_NOT_ACCEPTED";
        }
        if (o == DIAL_MODIFIED_TO_USSD) {
            return "DIAL_MODIFIED_TO_USSD";
        }
        if (o == DIAL_MODIFIED_TO_SS) {
            return "DIAL_MODIFIED_TO_SS";
        }
        if (o == DIAL_MODIFIED_TO_DIAL) {
            return "DIAL_MODIFIED_TO_DIAL";
        }
        if (o == RADIO_OFF) {
            return "RADIO_OFF";
        }
        if (o == OUT_OF_SERVICE) {
            return "OUT_OF_SERVICE";
        }
        if (o == NO_VALID_SIM) {
            return "NO_VALID_SIM";
        }
        if (o == RADIO_INTERNAL_ERROR) {
            return "RADIO_INTERNAL_ERROR";
        }
        if (o == NETWORK_RESP_TIMEOUT) {
            return "NETWORK_RESP_TIMEOUT";
        }
        if (o == NETWORK_REJECT) {
            return "NETWORK_REJECT";
        }
        if (o == RADIO_ACCESS_FAILURE) {
            return "RADIO_ACCESS_FAILURE";
        }
        if (o == RADIO_LINK_FAILURE) {
            return "RADIO_LINK_FAILURE";
        }
        if (o == RADIO_LINK_LOST) {
            return "RADIO_LINK_LOST";
        }
        if (o == RADIO_UPLINK_FAILURE) {
            return "RADIO_UPLINK_FAILURE";
        }
        if (o == RADIO_SETUP_FAILURE) {
            return "RADIO_SETUP_FAILURE";
        }
        if (o == RADIO_RELEASE_NORMAL) {
            return "RADIO_RELEASE_NORMAL";
        }
        if (o == RADIO_RELEASE_ABNORMAL) {
            return "RADIO_RELEASE_ABNORMAL";
        }
        if (o == ACCESS_CLASS_BLOCKED) {
            return "ACCESS_CLASS_BLOCKED";
        }
        if (o == NETWORK_DETACH) {
            return "NETWORK_DETACH";
        }
        if (o == CDMA_LOCKED_UNTIL_POWER_CYCLE) {
            return "CDMA_LOCKED_UNTIL_POWER_CYCLE";
        }
        if (o == CDMA_DROP) {
            return "CDMA_DROP";
        }
        if (o == CDMA_INTERCEPT) {
            return "CDMA_INTERCEPT";
        }
        if (o == CDMA_REORDER) {
            return "CDMA_REORDER";
        }
        if (o == CDMA_SO_REJECT) {
            return "CDMA_SO_REJECT";
        }
        if (o == CDMA_RETRY_ORDER) {
            return "CDMA_RETRY_ORDER";
        }
        if (o == CDMA_ACCESS_FAILURE) {
            return "CDMA_ACCESS_FAILURE";
        }
        if (o == CDMA_PREEMPTED) {
            return "CDMA_PREEMPTED";
        }
        if (o == CDMA_NOT_EMERGENCY) {
            return "CDMA_NOT_EMERGENCY";
        }
        if (o == CDMA_ACCESS_BLOCKED) {
            return "CDMA_ACCESS_BLOCKED";
        }
        if (o == OEM_CAUSE_1) {
            return "OEM_CAUSE_1";
        }
        if (o == OEM_CAUSE_2) {
            return "OEM_CAUSE_2";
        }
        if (o == OEM_CAUSE_3) {
            return "OEM_CAUSE_3";
        }
        if (o == OEM_CAUSE_4) {
            return "OEM_CAUSE_4";
        }
        if (o == OEM_CAUSE_5) {
            return "OEM_CAUSE_5";
        }
        if (o == OEM_CAUSE_6) {
            return "OEM_CAUSE_6";
        }
        if (o == OEM_CAUSE_7) {
            return "OEM_CAUSE_7";
        }
        if (o == OEM_CAUSE_8) {
            return "OEM_CAUSE_8";
        }
        if (o == OEM_CAUSE_9) {
            return "OEM_CAUSE_9";
        }
        if (o == OEM_CAUSE_10) {
            return "OEM_CAUSE_10";
        }
        if (o == OEM_CAUSE_11) {
            return "OEM_CAUSE_11";
        }
        if (o == OEM_CAUSE_12) {
            return "OEM_CAUSE_12";
        }
        if (o == OEM_CAUSE_13) {
            return "OEM_CAUSE_13";
        }
        if (o == OEM_CAUSE_14) {
            return "OEM_CAUSE_14";
        }
        if (o == OEM_CAUSE_15) {
            return "OEM_CAUSE_15";
        }
        if (o == ERROR_UNSPECIFIED) {
            return "ERROR_UNSPECIFIED";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        if ((o & UNOBTAINABLE_NUMBER) == UNOBTAINABLE_NUMBER) {
            list.add("UNOBTAINABLE_NUMBER");
            flipped |= UNOBTAINABLE_NUMBER;
        }
        if ((o & NO_ROUTE_TO_DESTINATION) == NO_ROUTE_TO_DESTINATION) {
            list.add("NO_ROUTE_TO_DESTINATION");
            flipped |= NO_ROUTE_TO_DESTINATION;
        }
        if ((o & CHANNEL_UNACCEPTABLE) == CHANNEL_UNACCEPTABLE) {
            list.add("CHANNEL_UNACCEPTABLE");
            flipped |= CHANNEL_UNACCEPTABLE;
        }
        if ((o & OPERATOR_DETERMINED_BARRING) == OPERATOR_DETERMINED_BARRING) {
            list.add("OPERATOR_DETERMINED_BARRING");
            flipped |= OPERATOR_DETERMINED_BARRING;
        }
        if ((o & NORMAL) == NORMAL) {
            list.add("NORMAL");
            flipped |= NORMAL;
        }
        if ((o & BUSY) == BUSY) {
            list.add("BUSY");
            flipped |= BUSY;
        }
        if ((o & NO_USER_RESPONDING) == NO_USER_RESPONDING) {
            list.add("NO_USER_RESPONDING");
            flipped |= NO_USER_RESPONDING;
        }
        if ((o & NO_ANSWER_FROM_USER) == NO_ANSWER_FROM_USER) {
            list.add("NO_ANSWER_FROM_USER");
            flipped |= NO_ANSWER_FROM_USER;
        }
        if ((o & CALL_REJECTED) == CALL_REJECTED) {
            list.add("CALL_REJECTED");
            flipped |= CALL_REJECTED;
        }
        if ((o & NUMBER_CHANGED) == NUMBER_CHANGED) {
            list.add("NUMBER_CHANGED");
            flipped |= NUMBER_CHANGED;
        }
        if ((o & PREEMPTION) == PREEMPTION) {
            list.add("PREEMPTION");
            flipped |= PREEMPTION;
        }
        if ((o & DESTINATION_OUT_OF_ORDER) == DESTINATION_OUT_OF_ORDER) {
            list.add("DESTINATION_OUT_OF_ORDER");
            flipped |= DESTINATION_OUT_OF_ORDER;
        }
        if ((o & INVALID_NUMBER_FORMAT) == INVALID_NUMBER_FORMAT) {
            list.add("INVALID_NUMBER_FORMAT");
            flipped |= INVALID_NUMBER_FORMAT;
        }
        if ((o & FACILITY_REJECTED) == FACILITY_REJECTED) {
            list.add("FACILITY_REJECTED");
            flipped |= FACILITY_REJECTED;
        }
        if ((o & RESP_TO_STATUS_ENQUIRY) == RESP_TO_STATUS_ENQUIRY) {
            list.add("RESP_TO_STATUS_ENQUIRY");
            flipped |= RESP_TO_STATUS_ENQUIRY;
        }
        if ((o & NORMAL_UNSPECIFIED) == NORMAL_UNSPECIFIED) {
            list.add("NORMAL_UNSPECIFIED");
            flipped |= NORMAL_UNSPECIFIED;
        }
        if ((o & CONGESTION) == CONGESTION) {
            list.add("CONGESTION");
            flipped |= CONGESTION;
        }
        if ((o & NETWORK_OUT_OF_ORDER) == NETWORK_OUT_OF_ORDER) {
            list.add("NETWORK_OUT_OF_ORDER");
            flipped |= NETWORK_OUT_OF_ORDER;
        }
        if ((o & TEMPORARY_FAILURE) == TEMPORARY_FAILURE) {
            list.add("TEMPORARY_FAILURE");
            flipped |= TEMPORARY_FAILURE;
        }
        if ((o & SWITCHING_EQUIPMENT_CONGESTION) == SWITCHING_EQUIPMENT_CONGESTION) {
            list.add("SWITCHING_EQUIPMENT_CONGESTION");
            flipped |= SWITCHING_EQUIPMENT_CONGESTION;
        }
        if ((o & ACCESS_INFORMATION_DISCARDED) == ACCESS_INFORMATION_DISCARDED) {
            list.add("ACCESS_INFORMATION_DISCARDED");
            flipped |= ACCESS_INFORMATION_DISCARDED;
        }
        if ((o & REQUESTED_CIRCUIT_OR_CHANNEL_NOT_AVAILABLE) == REQUESTED_CIRCUIT_OR_CHANNEL_NOT_AVAILABLE) {
            list.add("REQUESTED_CIRCUIT_OR_CHANNEL_NOT_AVAILABLE");
            flipped |= REQUESTED_CIRCUIT_OR_CHANNEL_NOT_AVAILABLE;
        }
        if ((o & RESOURCES_UNAVAILABLE_OR_UNSPECIFIED) == RESOURCES_UNAVAILABLE_OR_UNSPECIFIED) {
            list.add("RESOURCES_UNAVAILABLE_OR_UNSPECIFIED");
            flipped |= RESOURCES_UNAVAILABLE_OR_UNSPECIFIED;
        }
        if ((o & QOS_UNAVAILABLE) == QOS_UNAVAILABLE) {
            list.add("QOS_UNAVAILABLE");
            flipped |= QOS_UNAVAILABLE;
        }
        if ((o & REQUESTED_FACILITY_NOT_SUBSCRIBED) == REQUESTED_FACILITY_NOT_SUBSCRIBED) {
            list.add("REQUESTED_FACILITY_NOT_SUBSCRIBED");
            flipped |= REQUESTED_FACILITY_NOT_SUBSCRIBED;
        }
        if ((o & INCOMING_CALLS_BARRED_WITHIN_CUG) == INCOMING_CALLS_BARRED_WITHIN_CUG) {
            list.add("INCOMING_CALLS_BARRED_WITHIN_CUG");
            flipped |= INCOMING_CALLS_BARRED_WITHIN_CUG;
        }
        if ((o & BEARER_CAPABILITY_NOT_AUTHORIZED) == BEARER_CAPABILITY_NOT_AUTHORIZED) {
            list.add("BEARER_CAPABILITY_NOT_AUTHORIZED");
            flipped |= BEARER_CAPABILITY_NOT_AUTHORIZED;
        }
        if ((o & BEARER_CAPABILITY_UNAVAILABLE) == BEARER_CAPABILITY_UNAVAILABLE) {
            list.add("BEARER_CAPABILITY_UNAVAILABLE");
            flipped |= BEARER_CAPABILITY_UNAVAILABLE;
        }
        if ((o & SERVICE_OPTION_NOT_AVAILABLE) == SERVICE_OPTION_NOT_AVAILABLE) {
            list.add("SERVICE_OPTION_NOT_AVAILABLE");
            flipped |= SERVICE_OPTION_NOT_AVAILABLE;
        }
        if ((o & BEARER_SERVICE_NOT_IMPLEMENTED) == BEARER_SERVICE_NOT_IMPLEMENTED) {
            list.add("BEARER_SERVICE_NOT_IMPLEMENTED");
            flipped |= BEARER_SERVICE_NOT_IMPLEMENTED;
        }
        if ((o & ACM_LIMIT_EXCEEDED) == ACM_LIMIT_EXCEEDED) {
            list.add("ACM_LIMIT_EXCEEDED");
            flipped |= ACM_LIMIT_EXCEEDED;
        }
        if ((o & REQUESTED_FACILITY_NOT_IMPLEMENTED) == REQUESTED_FACILITY_NOT_IMPLEMENTED) {
            list.add("REQUESTED_FACILITY_NOT_IMPLEMENTED");
            flipped |= REQUESTED_FACILITY_NOT_IMPLEMENTED;
        }
        if ((o & ONLY_DIGITAL_INFORMATION_BEARER_AVAILABLE) == ONLY_DIGITAL_INFORMATION_BEARER_AVAILABLE) {
            list.add("ONLY_DIGITAL_INFORMATION_BEARER_AVAILABLE");
            flipped |= ONLY_DIGITAL_INFORMATION_BEARER_AVAILABLE;
        }
        if ((o & SERVICE_OR_OPTION_NOT_IMPLEMENTED) == SERVICE_OR_OPTION_NOT_IMPLEMENTED) {
            list.add("SERVICE_OR_OPTION_NOT_IMPLEMENTED");
            flipped |= SERVICE_OR_OPTION_NOT_IMPLEMENTED;
        }
        if ((o & INVALID_TRANSACTION_IDENTIFIER) == INVALID_TRANSACTION_IDENTIFIER) {
            list.add("INVALID_TRANSACTION_IDENTIFIER");
            flipped |= INVALID_TRANSACTION_IDENTIFIER;
        }
        if ((o & USER_NOT_MEMBER_OF_CUG) == USER_NOT_MEMBER_OF_CUG) {
            list.add("USER_NOT_MEMBER_OF_CUG");
            flipped |= USER_NOT_MEMBER_OF_CUG;
        }
        if ((o & INCOMPATIBLE_DESTINATION) == INCOMPATIBLE_DESTINATION) {
            list.add("INCOMPATIBLE_DESTINATION");
            flipped |= INCOMPATIBLE_DESTINATION;
        }
        if ((o & INVALID_TRANSIT_NW_SELECTION) == INVALID_TRANSIT_NW_SELECTION) {
            list.add("INVALID_TRANSIT_NW_SELECTION");
            flipped |= INVALID_TRANSIT_NW_SELECTION;
        }
        if ((o & SEMANTICALLY_INCORRECT_MESSAGE) == SEMANTICALLY_INCORRECT_MESSAGE) {
            list.add("SEMANTICALLY_INCORRECT_MESSAGE");
            flipped |= SEMANTICALLY_INCORRECT_MESSAGE;
        }
        if ((o & INVALID_MANDATORY_INFORMATION) == INVALID_MANDATORY_INFORMATION) {
            list.add("INVALID_MANDATORY_INFORMATION");
            flipped |= INVALID_MANDATORY_INFORMATION;
        }
        if ((o & MESSAGE_TYPE_NON_IMPLEMENTED) == MESSAGE_TYPE_NON_IMPLEMENTED) {
            list.add("MESSAGE_TYPE_NON_IMPLEMENTED");
            flipped |= MESSAGE_TYPE_NON_IMPLEMENTED;
        }
        if ((o & MESSAGE_TYPE_NOT_COMPATIBLE_WITH_PROTOCOL_STATE) == MESSAGE_TYPE_NOT_COMPATIBLE_WITH_PROTOCOL_STATE) {
            list.add("MESSAGE_TYPE_NOT_COMPATIBLE_WITH_PROTOCOL_STATE");
            flipped |= MESSAGE_TYPE_NOT_COMPATIBLE_WITH_PROTOCOL_STATE;
        }
        if ((o & INFORMATION_ELEMENT_NON_EXISTENT) == INFORMATION_ELEMENT_NON_EXISTENT) {
            list.add("INFORMATION_ELEMENT_NON_EXISTENT");
            flipped |= INFORMATION_ELEMENT_NON_EXISTENT;
        }
        if ((o & CONDITIONAL_IE_ERROR) == CONDITIONAL_IE_ERROR) {
            list.add("CONDITIONAL_IE_ERROR");
            flipped |= CONDITIONAL_IE_ERROR;
        }
        if ((o & MESSAGE_NOT_COMPATIBLE_WITH_PROTOCOL_STATE) == MESSAGE_NOT_COMPATIBLE_WITH_PROTOCOL_STATE) {
            list.add("MESSAGE_NOT_COMPATIBLE_WITH_PROTOCOL_STATE");
            flipped |= MESSAGE_NOT_COMPATIBLE_WITH_PROTOCOL_STATE;
        }
        if ((o & RECOVERY_ON_TIMER_EXPIRED) == RECOVERY_ON_TIMER_EXPIRED) {
            list.add("RECOVERY_ON_TIMER_EXPIRED");
            flipped |= RECOVERY_ON_TIMER_EXPIRED;
        }
        if ((o & PROTOCOL_ERROR_UNSPECIFIED) == PROTOCOL_ERROR_UNSPECIFIED) {
            list.add("PROTOCOL_ERROR_UNSPECIFIED");
            flipped |= PROTOCOL_ERROR_UNSPECIFIED;
        }
        if ((o & INTERWORKING_UNSPECIFIED) == INTERWORKING_UNSPECIFIED) {
            list.add("INTERWORKING_UNSPECIFIED");
            flipped |= INTERWORKING_UNSPECIFIED;
        }
        if ((o & CALL_BARRED) == CALL_BARRED) {
            list.add("CALL_BARRED");
            flipped |= CALL_BARRED;
        }
        if ((o & FDN_BLOCKED) == FDN_BLOCKED) {
            list.add("FDN_BLOCKED");
            flipped |= FDN_BLOCKED;
        }
        if ((o & IMSI_UNKNOWN_IN_VLR) == IMSI_UNKNOWN_IN_VLR) {
            list.add("IMSI_UNKNOWN_IN_VLR");
            flipped |= IMSI_UNKNOWN_IN_VLR;
        }
        if ((o & IMEI_NOT_ACCEPTED) == IMEI_NOT_ACCEPTED) {
            list.add("IMEI_NOT_ACCEPTED");
            flipped |= IMEI_NOT_ACCEPTED;
        }
        if ((o & DIAL_MODIFIED_TO_USSD) == DIAL_MODIFIED_TO_USSD) {
            list.add("DIAL_MODIFIED_TO_USSD");
            flipped |= DIAL_MODIFIED_TO_USSD;
        }
        if ((o & DIAL_MODIFIED_TO_SS) == DIAL_MODIFIED_TO_SS) {
            list.add("DIAL_MODIFIED_TO_SS");
            flipped |= DIAL_MODIFIED_TO_SS;
        }
        if ((o & DIAL_MODIFIED_TO_DIAL) == DIAL_MODIFIED_TO_DIAL) {
            list.add("DIAL_MODIFIED_TO_DIAL");
            flipped |= DIAL_MODIFIED_TO_DIAL;
        }
        if ((o & RADIO_OFF) == RADIO_OFF) {
            list.add("RADIO_OFF");
            flipped |= RADIO_OFF;
        }
        if ((o & OUT_OF_SERVICE) == OUT_OF_SERVICE) {
            list.add("OUT_OF_SERVICE");
            flipped |= OUT_OF_SERVICE;
        }
        if ((o & NO_VALID_SIM) == NO_VALID_SIM) {
            list.add("NO_VALID_SIM");
            flipped |= NO_VALID_SIM;
        }
        if ((o & RADIO_INTERNAL_ERROR) == RADIO_INTERNAL_ERROR) {
            list.add("RADIO_INTERNAL_ERROR");
            flipped |= RADIO_INTERNAL_ERROR;
        }
        if ((o & NETWORK_RESP_TIMEOUT) == NETWORK_RESP_TIMEOUT) {
            list.add("NETWORK_RESP_TIMEOUT");
            flipped |= NETWORK_RESP_TIMEOUT;
        }
        if ((o & NETWORK_REJECT) == NETWORK_REJECT) {
            list.add("NETWORK_REJECT");
            flipped |= NETWORK_REJECT;
        }
        if ((o & RADIO_ACCESS_FAILURE) == RADIO_ACCESS_FAILURE) {
            list.add("RADIO_ACCESS_FAILURE");
            flipped |= RADIO_ACCESS_FAILURE;
        }
        if ((o & RADIO_LINK_FAILURE) == RADIO_LINK_FAILURE) {
            list.add("RADIO_LINK_FAILURE");
            flipped |= RADIO_LINK_FAILURE;
        }
        if ((o & RADIO_LINK_LOST) == RADIO_LINK_LOST) {
            list.add("RADIO_LINK_LOST");
            flipped |= RADIO_LINK_LOST;
        }
        if ((o & RADIO_UPLINK_FAILURE) == RADIO_UPLINK_FAILURE) {
            list.add("RADIO_UPLINK_FAILURE");
            flipped |= RADIO_UPLINK_FAILURE;
        }
        if ((o & RADIO_SETUP_FAILURE) == RADIO_SETUP_FAILURE) {
            list.add("RADIO_SETUP_FAILURE");
            flipped |= RADIO_SETUP_FAILURE;
        }
        if ((o & RADIO_RELEASE_NORMAL) == RADIO_RELEASE_NORMAL) {
            list.add("RADIO_RELEASE_NORMAL");
            flipped |= RADIO_RELEASE_NORMAL;
        }
        if ((o & RADIO_RELEASE_ABNORMAL) == RADIO_RELEASE_ABNORMAL) {
            list.add("RADIO_RELEASE_ABNORMAL");
            flipped |= RADIO_RELEASE_ABNORMAL;
        }
        if ((o & ACCESS_CLASS_BLOCKED) == ACCESS_CLASS_BLOCKED) {
            list.add("ACCESS_CLASS_BLOCKED");
            flipped |= ACCESS_CLASS_BLOCKED;
        }
        if ((o & NETWORK_DETACH) == NETWORK_DETACH) {
            list.add("NETWORK_DETACH");
            flipped |= NETWORK_DETACH;
        }
        if ((o & CDMA_LOCKED_UNTIL_POWER_CYCLE) == CDMA_LOCKED_UNTIL_POWER_CYCLE) {
            list.add("CDMA_LOCKED_UNTIL_POWER_CYCLE");
            flipped |= CDMA_LOCKED_UNTIL_POWER_CYCLE;
        }
        if ((o & CDMA_DROP) == CDMA_DROP) {
            list.add("CDMA_DROP");
            flipped |= CDMA_DROP;
        }
        if ((o & CDMA_INTERCEPT) == CDMA_INTERCEPT) {
            list.add("CDMA_INTERCEPT");
            flipped |= CDMA_INTERCEPT;
        }
        if ((o & CDMA_REORDER) == CDMA_REORDER) {
            list.add("CDMA_REORDER");
            flipped |= CDMA_REORDER;
        }
        if ((o & CDMA_SO_REJECT) == CDMA_SO_REJECT) {
            list.add("CDMA_SO_REJECT");
            flipped |= CDMA_SO_REJECT;
        }
        if ((o & CDMA_RETRY_ORDER) == CDMA_RETRY_ORDER) {
            list.add("CDMA_RETRY_ORDER");
            flipped |= CDMA_RETRY_ORDER;
        }
        if ((o & CDMA_ACCESS_FAILURE) == CDMA_ACCESS_FAILURE) {
            list.add("CDMA_ACCESS_FAILURE");
            flipped |= CDMA_ACCESS_FAILURE;
        }
        if ((o & CDMA_PREEMPTED) == CDMA_PREEMPTED) {
            list.add("CDMA_PREEMPTED");
            flipped |= CDMA_PREEMPTED;
        }
        if ((o & CDMA_NOT_EMERGENCY) == CDMA_NOT_EMERGENCY) {
            list.add("CDMA_NOT_EMERGENCY");
            flipped |= CDMA_NOT_EMERGENCY;
        }
        if ((o & CDMA_ACCESS_BLOCKED) == CDMA_ACCESS_BLOCKED) {
            list.add("CDMA_ACCESS_BLOCKED");
            flipped |= CDMA_ACCESS_BLOCKED;
        }
        if ((o & OEM_CAUSE_1) == OEM_CAUSE_1) {
            list.add("OEM_CAUSE_1");
            flipped |= OEM_CAUSE_1;
        }
        if ((o & OEM_CAUSE_2) == OEM_CAUSE_2) {
            list.add("OEM_CAUSE_2");
            flipped |= OEM_CAUSE_2;
        }
        if ((o & OEM_CAUSE_3) == OEM_CAUSE_3) {
            list.add("OEM_CAUSE_3");
            flipped |= OEM_CAUSE_3;
        }
        if ((o & OEM_CAUSE_4) == OEM_CAUSE_4) {
            list.add("OEM_CAUSE_4");
            flipped |= OEM_CAUSE_4;
        }
        if ((o & OEM_CAUSE_5) == OEM_CAUSE_5) {
            list.add("OEM_CAUSE_5");
            flipped |= OEM_CAUSE_5;
        }
        if ((o & OEM_CAUSE_6) == OEM_CAUSE_6) {
            list.add("OEM_CAUSE_6");
            flipped |= OEM_CAUSE_6;
        }
        if ((o & OEM_CAUSE_7) == OEM_CAUSE_7) {
            list.add("OEM_CAUSE_7");
            flipped |= OEM_CAUSE_7;
        }
        if ((o & OEM_CAUSE_8) == OEM_CAUSE_8) {
            list.add("OEM_CAUSE_8");
            flipped |= OEM_CAUSE_8;
        }
        if ((o & OEM_CAUSE_9) == OEM_CAUSE_9) {
            list.add("OEM_CAUSE_9");
            flipped |= OEM_CAUSE_9;
        }
        if ((o & OEM_CAUSE_10) == OEM_CAUSE_10) {
            list.add("OEM_CAUSE_10");
            flipped |= OEM_CAUSE_10;
        }
        if ((o & OEM_CAUSE_11) == OEM_CAUSE_11) {
            list.add("OEM_CAUSE_11");
            flipped |= OEM_CAUSE_11;
        }
        if ((o & OEM_CAUSE_12) == OEM_CAUSE_12) {
            list.add("OEM_CAUSE_12");
            flipped |= OEM_CAUSE_12;
        }
        if ((o & OEM_CAUSE_13) == OEM_CAUSE_13) {
            list.add("OEM_CAUSE_13");
            flipped |= OEM_CAUSE_13;
        }
        if ((o & OEM_CAUSE_14) == OEM_CAUSE_14) {
            list.add("OEM_CAUSE_14");
            flipped |= OEM_CAUSE_14;
        }
        if ((o & OEM_CAUSE_15) == OEM_CAUSE_15) {
            list.add("OEM_CAUSE_15");
            flipped |= OEM_CAUSE_15;
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

