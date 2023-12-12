package android.hardware.radio.V1_5;


public final class RegistrationFailCause {
    /**
     * 0 - None
     */
    public static final int NONE = 0;
    /**
     * 2 - IMSI unknown in HLR
     */
    public static final int IMSI_UNKNOWN_IN_HLR = 2;
    /**
     * 3 - Illegal MS
     */
    public static final int ILLEGAL_MS = 3;
    /**
     * 4 - Illegal ME
     */
    public static final int IMSI_UNKNOWN_IN_VLR = 4;
    /**
     * 5 - PLMN not allowed
     */
    public static final int IMEI_NOT_ACCEPTED = 5;
    /**
     * 6 - Location area not allowed
     */
    public static final int ILLEGAL_ME = 6;
    /**
     * 7 - Roaming not allowed
     */
    public static final int GPRS_SERVICES_NOT_ALLOWED = 7;
    /**
     * 8 - No Suitable Cells in this Location Area
     */
    public static final int GPRS_AND_NON_GPRS_SERVICES_NOT_ALLOWED = 8;
    /**
     * 9 - Network failure
     */
    public static final int MS_IDENTITY_CANNOT_BE_DERIVED_BY_NETWORK = 9;
    /**
     * 10 - Persistent location update reject
     */
    public static final int IMPLICITLY_DETACHED = 10;
    /**
     * 11 - PLMN not allowed
     */
    public static final int PLMN_NOT_ALLOWED = 11;
    /**
     * 12 - Location area not allowed
     */
    public static final int LOCATION_AREA_NOT_ALLOWED = 12;
    /**
     * 13 - Roaming not allowed in this Location Area
     */
    public static final int ROAMING_NOT_ALLOWED = 13;
    /**
     * 14 - GPRS Services not allowed in this PLMN
     */
    public static final int GPRS_SERVICES_NOT_ALLOWED_IN_PLMN = 14;
    /**
     * 15 - No Suitable Cells in this Location Area
     */
    public static final int NO_SUITABLE_CELLS = 15;
    /**
     * 16 - MSC temporarily not reachable
     */
    public static final int MSC_TEMPORARILY_NOT_REACHABLE = 15;
    /**
     * 17 - Network Failure
     */
    public static final int NETWORK_FAILURE = 17;
    /**
     * 20 - MAC Failure
     */
    public static final int MAC_FAILURE = 20;
    /**
     * 21 - Sync Failure
     */
    public static final int SYNC_FAILURE = 21;
    /**
     * 22 - Congestion
     */
    public static final int CONGESTION = 22;
    /**
     * 23 - GSM Authentication unacceptable
     */
    public static final int GSM_AUTHENTICATION_UNACCEPTABLE = 23;
    /**
     * 25 - Not Authorized for this CSG
     */
    public static final int NOT_AUTHORIZED_FOR_THIS_CSG = 25;
    /**
     * 28 SMS provided via GPRS in this routing area
     */
    public static final int SMS_PROVIDED_BY_GPRS_IN_ROUTING_AREA = 26 /* ::android::hardware::radio::V1_5::RegistrationFailCause.NOT_AUTHORIZED_FOR_THIS_CSG implicitly + 1 */;
    /**
     * 32 - Service option not supported
     */
    public static final int SERVICE_OPTION_NOT_SUPPORTED = 32;
    /**
     * 33 - Requested service option not subscribed
     */
    public static final int SERVICE_OPTION_NOT_SUBSCRIBED = 33;
    /**
     * 34 - Service option temporarily out of order
     */
    public static final int SERVICE_OPTION_TEMPORARILY_OUT_OF_ORDER = 34;
    /**
     * 38 - Call cannot be identified
     */
    public static final int CALL_CANNOT_BE_IDENTIFIED = 38;
    /**
     * 40 No PDP context activated
     */
    public static final int NO_PDP_CONTEXT_ACTIVATED = 40;
    /**
     * 48-63 - Retry upon entry into a new cell
     */
    public static final int RETRY_UPON_ENTRY_INTO_NEW_CELL_1 = 48;
    public static final int RETRY_UPON_ENTRY_INTO_NEW_CELL_2 = 49;
    public static final int RETRY_UPON_ENTRY_INTO_NEW_CELL_3 = 50;
    public static final int RETRY_UPON_ENTRY_INTO_NEW_CELL_4 = 51;
    public static final int RETRY_UPON_ENTRY_INTO_NEW_CELL_5 = 52;
    public static final int RETRY_UPON_ENTRY_INTO_NEW_CELL_6 = 53;
    public static final int RETRY_UPON_ENTRY_INTO_NEW_CELL_7 = 54;
    public static final int RETRY_UPON_ENTRY_INTO_NEW_CELL_8 = 55;
    public static final int RETRY_UPON_ENTRY_INTO_NEW_CELL_9 = 56;
    public static final int RETRY_UPON_ENTRY_INTO_NEW_CELL_10 = 57;
    public static final int RETRY_UPON_ENTRY_INTO_NEW_CELL_11 = 58;
    public static final int RETRY_UPON_ENTRY_INTO_NEW_CELL_12 = 59;
    public static final int RETRY_UPON_ENTRY_INTO_NEW_CELL_13 = 60;
    public static final int RETRY_UPON_ENTRY_INTO_NEW_CELL_14 = 61;
    public static final int RETRY_UPON_ENTRY_INTO_NEW_CELL_15 = 62;
    public static final int RETRY_UPON_ENTRY_INTO_NEW_CELL_16 = 63;
    /**
     * 95 - Semantically incorrect message
     */
    public static final int SEMANTICALLY_INCORRECT_MESSAGE = 95;
    /**
     * 96 - Invalid mandatory information
     */
    public static final int INVALID_MANDATORY_INFORMATION = 96;
    /**
     * 97 - Message type non-existent or not implemented
     */
    public static final int MESSAGE_TYPE_NON_EXISTENT_OR_NOT_IMPLEMENTED = 97;
    /**
     * 98 - Message type not compatible with protocol state
     */
    public static final int MESSAGE_TYPE_NOT_COMPATIBLE_WITH_PROTOCOL_STATE = 98;
    /**
     * 99 - Information element non-existent or not implemented
     */
    public static final int INFORMATION_ELEMENT_NON_EXISTENT_OR_NOT_IMPLEMENTED = 99;
    /**
     * 100 - Conditional IE error
     */
    public static final int CONDITIONAL_IE_ERROR = 100;
    /**
     * 101 - Message not compatible with protocol state
     */
    public static final int MESSAGE_NOT_COMPATIBLE_WITH_PROTOCOL_STATE = 101;
    /**
     * 111 - Protocol error, unspecified
     */
    public static final int PROTOCOL_ERROR_UNSPECIFIED = 111;
    public static final String toString(int o) {
        if (o == NONE) {
            return "NONE";
        }
        if (o == IMSI_UNKNOWN_IN_HLR) {
            return "IMSI_UNKNOWN_IN_HLR";
        }
        if (o == ILLEGAL_MS) {
            return "ILLEGAL_MS";
        }
        if (o == IMSI_UNKNOWN_IN_VLR) {
            return "IMSI_UNKNOWN_IN_VLR";
        }
        if (o == IMEI_NOT_ACCEPTED) {
            return "IMEI_NOT_ACCEPTED";
        }
        if (o == ILLEGAL_ME) {
            return "ILLEGAL_ME";
        }
        if (o == GPRS_SERVICES_NOT_ALLOWED) {
            return "GPRS_SERVICES_NOT_ALLOWED";
        }
        if (o == GPRS_AND_NON_GPRS_SERVICES_NOT_ALLOWED) {
            return "GPRS_AND_NON_GPRS_SERVICES_NOT_ALLOWED";
        }
        if (o == MS_IDENTITY_CANNOT_BE_DERIVED_BY_NETWORK) {
            return "MS_IDENTITY_CANNOT_BE_DERIVED_BY_NETWORK";
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
        if (o == ROAMING_NOT_ALLOWED) {
            return "ROAMING_NOT_ALLOWED";
        }
        if (o == GPRS_SERVICES_NOT_ALLOWED_IN_PLMN) {
            return "GPRS_SERVICES_NOT_ALLOWED_IN_PLMN";
        }
        if (o == NO_SUITABLE_CELLS) {
            return "NO_SUITABLE_CELLS";
        }
        if (o == MSC_TEMPORARILY_NOT_REACHABLE) {
            return "MSC_TEMPORARILY_NOT_REACHABLE";
        }
        if (o == NETWORK_FAILURE) {
            return "NETWORK_FAILURE";
        }
        if (o == MAC_FAILURE) {
            return "MAC_FAILURE";
        }
        if (o == SYNC_FAILURE) {
            return "SYNC_FAILURE";
        }
        if (o == CONGESTION) {
            return "CONGESTION";
        }
        if (o == GSM_AUTHENTICATION_UNACCEPTABLE) {
            return "GSM_AUTHENTICATION_UNACCEPTABLE";
        }
        if (o == NOT_AUTHORIZED_FOR_THIS_CSG) {
            return "NOT_AUTHORIZED_FOR_THIS_CSG";
        }
        if (o == SMS_PROVIDED_BY_GPRS_IN_ROUTING_AREA) {
            return "SMS_PROVIDED_BY_GPRS_IN_ROUTING_AREA";
        }
        if (o == SERVICE_OPTION_NOT_SUPPORTED) {
            return "SERVICE_OPTION_NOT_SUPPORTED";
        }
        if (o == SERVICE_OPTION_NOT_SUBSCRIBED) {
            return "SERVICE_OPTION_NOT_SUBSCRIBED";
        }
        if (o == SERVICE_OPTION_TEMPORARILY_OUT_OF_ORDER) {
            return "SERVICE_OPTION_TEMPORARILY_OUT_OF_ORDER";
        }
        if (o == CALL_CANNOT_BE_IDENTIFIED) {
            return "CALL_CANNOT_BE_IDENTIFIED";
        }
        if (o == NO_PDP_CONTEXT_ACTIVATED) {
            return "NO_PDP_CONTEXT_ACTIVATED";
        }
        if (o == RETRY_UPON_ENTRY_INTO_NEW_CELL_1) {
            return "RETRY_UPON_ENTRY_INTO_NEW_CELL_1";
        }
        if (o == RETRY_UPON_ENTRY_INTO_NEW_CELL_2) {
            return "RETRY_UPON_ENTRY_INTO_NEW_CELL_2";
        }
        if (o == RETRY_UPON_ENTRY_INTO_NEW_CELL_3) {
            return "RETRY_UPON_ENTRY_INTO_NEW_CELL_3";
        }
        if (o == RETRY_UPON_ENTRY_INTO_NEW_CELL_4) {
            return "RETRY_UPON_ENTRY_INTO_NEW_CELL_4";
        }
        if (o == RETRY_UPON_ENTRY_INTO_NEW_CELL_5) {
            return "RETRY_UPON_ENTRY_INTO_NEW_CELL_5";
        }
        if (o == RETRY_UPON_ENTRY_INTO_NEW_CELL_6) {
            return "RETRY_UPON_ENTRY_INTO_NEW_CELL_6";
        }
        if (o == RETRY_UPON_ENTRY_INTO_NEW_CELL_7) {
            return "RETRY_UPON_ENTRY_INTO_NEW_CELL_7";
        }
        if (o == RETRY_UPON_ENTRY_INTO_NEW_CELL_8) {
            return "RETRY_UPON_ENTRY_INTO_NEW_CELL_8";
        }
        if (o == RETRY_UPON_ENTRY_INTO_NEW_CELL_9) {
            return "RETRY_UPON_ENTRY_INTO_NEW_CELL_9";
        }
        if (o == RETRY_UPON_ENTRY_INTO_NEW_CELL_10) {
            return "RETRY_UPON_ENTRY_INTO_NEW_CELL_10";
        }
        if (o == RETRY_UPON_ENTRY_INTO_NEW_CELL_11) {
            return "RETRY_UPON_ENTRY_INTO_NEW_CELL_11";
        }
        if (o == RETRY_UPON_ENTRY_INTO_NEW_CELL_12) {
            return "RETRY_UPON_ENTRY_INTO_NEW_CELL_12";
        }
        if (o == RETRY_UPON_ENTRY_INTO_NEW_CELL_13) {
            return "RETRY_UPON_ENTRY_INTO_NEW_CELL_13";
        }
        if (o == RETRY_UPON_ENTRY_INTO_NEW_CELL_14) {
            return "RETRY_UPON_ENTRY_INTO_NEW_CELL_14";
        }
        if (o == RETRY_UPON_ENTRY_INTO_NEW_CELL_15) {
            return "RETRY_UPON_ENTRY_INTO_NEW_CELL_15";
        }
        if (o == RETRY_UPON_ENTRY_INTO_NEW_CELL_16) {
            return "RETRY_UPON_ENTRY_INTO_NEW_CELL_16";
        }
        if (o == SEMANTICALLY_INCORRECT_MESSAGE) {
            return "SEMANTICALLY_INCORRECT_MESSAGE";
        }
        if (o == INVALID_MANDATORY_INFORMATION) {
            return "INVALID_MANDATORY_INFORMATION";
        }
        if (o == MESSAGE_TYPE_NON_EXISTENT_OR_NOT_IMPLEMENTED) {
            return "MESSAGE_TYPE_NON_EXISTENT_OR_NOT_IMPLEMENTED";
        }
        if (o == MESSAGE_TYPE_NOT_COMPATIBLE_WITH_PROTOCOL_STATE) {
            return "MESSAGE_TYPE_NOT_COMPATIBLE_WITH_PROTOCOL_STATE";
        }
        if (o == INFORMATION_ELEMENT_NON_EXISTENT_OR_NOT_IMPLEMENTED) {
            return "INFORMATION_ELEMENT_NON_EXISTENT_OR_NOT_IMPLEMENTED";
        }
        if (o == CONDITIONAL_IE_ERROR) {
            return "CONDITIONAL_IE_ERROR";
        }
        if (o == MESSAGE_NOT_COMPATIBLE_WITH_PROTOCOL_STATE) {
            return "MESSAGE_NOT_COMPATIBLE_WITH_PROTOCOL_STATE";
        }
        if (o == PROTOCOL_ERROR_UNSPECIFIED) {
            return "PROTOCOL_ERROR_UNSPECIFIED";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("NONE"); // NONE == 0
        if ((o & IMSI_UNKNOWN_IN_HLR) == IMSI_UNKNOWN_IN_HLR) {
            list.add("IMSI_UNKNOWN_IN_HLR");
            flipped |= IMSI_UNKNOWN_IN_HLR;
        }
        if ((o & ILLEGAL_MS) == ILLEGAL_MS) {
            list.add("ILLEGAL_MS");
            flipped |= ILLEGAL_MS;
        }
        if ((o & IMSI_UNKNOWN_IN_VLR) == IMSI_UNKNOWN_IN_VLR) {
            list.add("IMSI_UNKNOWN_IN_VLR");
            flipped |= IMSI_UNKNOWN_IN_VLR;
        }
        if ((o & IMEI_NOT_ACCEPTED) == IMEI_NOT_ACCEPTED) {
            list.add("IMEI_NOT_ACCEPTED");
            flipped |= IMEI_NOT_ACCEPTED;
        }
        if ((o & ILLEGAL_ME) == ILLEGAL_ME) {
            list.add("ILLEGAL_ME");
            flipped |= ILLEGAL_ME;
        }
        if ((o & GPRS_SERVICES_NOT_ALLOWED) == GPRS_SERVICES_NOT_ALLOWED) {
            list.add("GPRS_SERVICES_NOT_ALLOWED");
            flipped |= GPRS_SERVICES_NOT_ALLOWED;
        }
        if ((o & GPRS_AND_NON_GPRS_SERVICES_NOT_ALLOWED) == GPRS_AND_NON_GPRS_SERVICES_NOT_ALLOWED) {
            list.add("GPRS_AND_NON_GPRS_SERVICES_NOT_ALLOWED");
            flipped |= GPRS_AND_NON_GPRS_SERVICES_NOT_ALLOWED;
        }
        if ((o & MS_IDENTITY_CANNOT_BE_DERIVED_BY_NETWORK) == MS_IDENTITY_CANNOT_BE_DERIVED_BY_NETWORK) {
            list.add("MS_IDENTITY_CANNOT_BE_DERIVED_BY_NETWORK");
            flipped |= MS_IDENTITY_CANNOT_BE_DERIVED_BY_NETWORK;
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
        if ((o & ROAMING_NOT_ALLOWED) == ROAMING_NOT_ALLOWED) {
            list.add("ROAMING_NOT_ALLOWED");
            flipped |= ROAMING_NOT_ALLOWED;
        }
        if ((o & GPRS_SERVICES_NOT_ALLOWED_IN_PLMN) == GPRS_SERVICES_NOT_ALLOWED_IN_PLMN) {
            list.add("GPRS_SERVICES_NOT_ALLOWED_IN_PLMN");
            flipped |= GPRS_SERVICES_NOT_ALLOWED_IN_PLMN;
        }
        if ((o & NO_SUITABLE_CELLS) == NO_SUITABLE_CELLS) {
            list.add("NO_SUITABLE_CELLS");
            flipped |= NO_SUITABLE_CELLS;
        }
        if ((o & MSC_TEMPORARILY_NOT_REACHABLE) == MSC_TEMPORARILY_NOT_REACHABLE) {
            list.add("MSC_TEMPORARILY_NOT_REACHABLE");
            flipped |= MSC_TEMPORARILY_NOT_REACHABLE;
        }
        if ((o & NETWORK_FAILURE) == NETWORK_FAILURE) {
            list.add("NETWORK_FAILURE");
            flipped |= NETWORK_FAILURE;
        }
        if ((o & MAC_FAILURE) == MAC_FAILURE) {
            list.add("MAC_FAILURE");
            flipped |= MAC_FAILURE;
        }
        if ((o & SYNC_FAILURE) == SYNC_FAILURE) {
            list.add("SYNC_FAILURE");
            flipped |= SYNC_FAILURE;
        }
        if ((o & CONGESTION) == CONGESTION) {
            list.add("CONGESTION");
            flipped |= CONGESTION;
        }
        if ((o & GSM_AUTHENTICATION_UNACCEPTABLE) == GSM_AUTHENTICATION_UNACCEPTABLE) {
            list.add("GSM_AUTHENTICATION_UNACCEPTABLE");
            flipped |= GSM_AUTHENTICATION_UNACCEPTABLE;
        }
        if ((o & NOT_AUTHORIZED_FOR_THIS_CSG) == NOT_AUTHORIZED_FOR_THIS_CSG) {
            list.add("NOT_AUTHORIZED_FOR_THIS_CSG");
            flipped |= NOT_AUTHORIZED_FOR_THIS_CSG;
        }
        if ((o & SMS_PROVIDED_BY_GPRS_IN_ROUTING_AREA) == SMS_PROVIDED_BY_GPRS_IN_ROUTING_AREA) {
            list.add("SMS_PROVIDED_BY_GPRS_IN_ROUTING_AREA");
            flipped |= SMS_PROVIDED_BY_GPRS_IN_ROUTING_AREA;
        }
        if ((o & SERVICE_OPTION_NOT_SUPPORTED) == SERVICE_OPTION_NOT_SUPPORTED) {
            list.add("SERVICE_OPTION_NOT_SUPPORTED");
            flipped |= SERVICE_OPTION_NOT_SUPPORTED;
        }
        if ((o & SERVICE_OPTION_NOT_SUBSCRIBED) == SERVICE_OPTION_NOT_SUBSCRIBED) {
            list.add("SERVICE_OPTION_NOT_SUBSCRIBED");
            flipped |= SERVICE_OPTION_NOT_SUBSCRIBED;
        }
        if ((o & SERVICE_OPTION_TEMPORARILY_OUT_OF_ORDER) == SERVICE_OPTION_TEMPORARILY_OUT_OF_ORDER) {
            list.add("SERVICE_OPTION_TEMPORARILY_OUT_OF_ORDER");
            flipped |= SERVICE_OPTION_TEMPORARILY_OUT_OF_ORDER;
        }
        if ((o & CALL_CANNOT_BE_IDENTIFIED) == CALL_CANNOT_BE_IDENTIFIED) {
            list.add("CALL_CANNOT_BE_IDENTIFIED");
            flipped |= CALL_CANNOT_BE_IDENTIFIED;
        }
        if ((o & NO_PDP_CONTEXT_ACTIVATED) == NO_PDP_CONTEXT_ACTIVATED) {
            list.add("NO_PDP_CONTEXT_ACTIVATED");
            flipped |= NO_PDP_CONTEXT_ACTIVATED;
        }
        if ((o & RETRY_UPON_ENTRY_INTO_NEW_CELL_1) == RETRY_UPON_ENTRY_INTO_NEW_CELL_1) {
            list.add("RETRY_UPON_ENTRY_INTO_NEW_CELL_1");
            flipped |= RETRY_UPON_ENTRY_INTO_NEW_CELL_1;
        }
        if ((o & RETRY_UPON_ENTRY_INTO_NEW_CELL_2) == RETRY_UPON_ENTRY_INTO_NEW_CELL_2) {
            list.add("RETRY_UPON_ENTRY_INTO_NEW_CELL_2");
            flipped |= RETRY_UPON_ENTRY_INTO_NEW_CELL_2;
        }
        if ((o & RETRY_UPON_ENTRY_INTO_NEW_CELL_3) == RETRY_UPON_ENTRY_INTO_NEW_CELL_3) {
            list.add("RETRY_UPON_ENTRY_INTO_NEW_CELL_3");
            flipped |= RETRY_UPON_ENTRY_INTO_NEW_CELL_3;
        }
        if ((o & RETRY_UPON_ENTRY_INTO_NEW_CELL_4) == RETRY_UPON_ENTRY_INTO_NEW_CELL_4) {
            list.add("RETRY_UPON_ENTRY_INTO_NEW_CELL_4");
            flipped |= RETRY_UPON_ENTRY_INTO_NEW_CELL_4;
        }
        if ((o & RETRY_UPON_ENTRY_INTO_NEW_CELL_5) == RETRY_UPON_ENTRY_INTO_NEW_CELL_5) {
            list.add("RETRY_UPON_ENTRY_INTO_NEW_CELL_5");
            flipped |= RETRY_UPON_ENTRY_INTO_NEW_CELL_5;
        }
        if ((o & RETRY_UPON_ENTRY_INTO_NEW_CELL_6) == RETRY_UPON_ENTRY_INTO_NEW_CELL_6) {
            list.add("RETRY_UPON_ENTRY_INTO_NEW_CELL_6");
            flipped |= RETRY_UPON_ENTRY_INTO_NEW_CELL_6;
        }
        if ((o & RETRY_UPON_ENTRY_INTO_NEW_CELL_7) == RETRY_UPON_ENTRY_INTO_NEW_CELL_7) {
            list.add("RETRY_UPON_ENTRY_INTO_NEW_CELL_7");
            flipped |= RETRY_UPON_ENTRY_INTO_NEW_CELL_7;
        }
        if ((o & RETRY_UPON_ENTRY_INTO_NEW_CELL_8) == RETRY_UPON_ENTRY_INTO_NEW_CELL_8) {
            list.add("RETRY_UPON_ENTRY_INTO_NEW_CELL_8");
            flipped |= RETRY_UPON_ENTRY_INTO_NEW_CELL_8;
        }
        if ((o & RETRY_UPON_ENTRY_INTO_NEW_CELL_9) == RETRY_UPON_ENTRY_INTO_NEW_CELL_9) {
            list.add("RETRY_UPON_ENTRY_INTO_NEW_CELL_9");
            flipped |= RETRY_UPON_ENTRY_INTO_NEW_CELL_9;
        }
        if ((o & RETRY_UPON_ENTRY_INTO_NEW_CELL_10) == RETRY_UPON_ENTRY_INTO_NEW_CELL_10) {
            list.add("RETRY_UPON_ENTRY_INTO_NEW_CELL_10");
            flipped |= RETRY_UPON_ENTRY_INTO_NEW_CELL_10;
        }
        if ((o & RETRY_UPON_ENTRY_INTO_NEW_CELL_11) == RETRY_UPON_ENTRY_INTO_NEW_CELL_11) {
            list.add("RETRY_UPON_ENTRY_INTO_NEW_CELL_11");
            flipped |= RETRY_UPON_ENTRY_INTO_NEW_CELL_11;
        }
        if ((o & RETRY_UPON_ENTRY_INTO_NEW_CELL_12) == RETRY_UPON_ENTRY_INTO_NEW_CELL_12) {
            list.add("RETRY_UPON_ENTRY_INTO_NEW_CELL_12");
            flipped |= RETRY_UPON_ENTRY_INTO_NEW_CELL_12;
        }
        if ((o & RETRY_UPON_ENTRY_INTO_NEW_CELL_13) == RETRY_UPON_ENTRY_INTO_NEW_CELL_13) {
            list.add("RETRY_UPON_ENTRY_INTO_NEW_CELL_13");
            flipped |= RETRY_UPON_ENTRY_INTO_NEW_CELL_13;
        }
        if ((o & RETRY_UPON_ENTRY_INTO_NEW_CELL_14) == RETRY_UPON_ENTRY_INTO_NEW_CELL_14) {
            list.add("RETRY_UPON_ENTRY_INTO_NEW_CELL_14");
            flipped |= RETRY_UPON_ENTRY_INTO_NEW_CELL_14;
        }
        if ((o & RETRY_UPON_ENTRY_INTO_NEW_CELL_15) == RETRY_UPON_ENTRY_INTO_NEW_CELL_15) {
            list.add("RETRY_UPON_ENTRY_INTO_NEW_CELL_15");
            flipped |= RETRY_UPON_ENTRY_INTO_NEW_CELL_15;
        }
        if ((o & RETRY_UPON_ENTRY_INTO_NEW_CELL_16) == RETRY_UPON_ENTRY_INTO_NEW_CELL_16) {
            list.add("RETRY_UPON_ENTRY_INTO_NEW_CELL_16");
            flipped |= RETRY_UPON_ENTRY_INTO_NEW_CELL_16;
        }
        if ((o & SEMANTICALLY_INCORRECT_MESSAGE) == SEMANTICALLY_INCORRECT_MESSAGE) {
            list.add("SEMANTICALLY_INCORRECT_MESSAGE");
            flipped |= SEMANTICALLY_INCORRECT_MESSAGE;
        }
        if ((o & INVALID_MANDATORY_INFORMATION) == INVALID_MANDATORY_INFORMATION) {
            list.add("INVALID_MANDATORY_INFORMATION");
            flipped |= INVALID_MANDATORY_INFORMATION;
        }
        if ((o & MESSAGE_TYPE_NON_EXISTENT_OR_NOT_IMPLEMENTED) == MESSAGE_TYPE_NON_EXISTENT_OR_NOT_IMPLEMENTED) {
            list.add("MESSAGE_TYPE_NON_EXISTENT_OR_NOT_IMPLEMENTED");
            flipped |= MESSAGE_TYPE_NON_EXISTENT_OR_NOT_IMPLEMENTED;
        }
        if ((o & MESSAGE_TYPE_NOT_COMPATIBLE_WITH_PROTOCOL_STATE) == MESSAGE_TYPE_NOT_COMPATIBLE_WITH_PROTOCOL_STATE) {
            list.add("MESSAGE_TYPE_NOT_COMPATIBLE_WITH_PROTOCOL_STATE");
            flipped |= MESSAGE_TYPE_NOT_COMPATIBLE_WITH_PROTOCOL_STATE;
        }
        if ((o & INFORMATION_ELEMENT_NON_EXISTENT_OR_NOT_IMPLEMENTED) == INFORMATION_ELEMENT_NON_EXISTENT_OR_NOT_IMPLEMENTED) {
            list.add("INFORMATION_ELEMENT_NON_EXISTENT_OR_NOT_IMPLEMENTED");
            flipped |= INFORMATION_ELEMENT_NON_EXISTENT_OR_NOT_IMPLEMENTED;
        }
        if ((o & CONDITIONAL_IE_ERROR) == CONDITIONAL_IE_ERROR) {
            list.add("CONDITIONAL_IE_ERROR");
            flipped |= CONDITIONAL_IE_ERROR;
        }
        if ((o & MESSAGE_NOT_COMPATIBLE_WITH_PROTOCOL_STATE) == MESSAGE_NOT_COMPATIBLE_WITH_PROTOCOL_STATE) {
            list.add("MESSAGE_NOT_COMPATIBLE_WITH_PROTOCOL_STATE");
            flipped |= MESSAGE_NOT_COMPATIBLE_WITH_PROTOCOL_STATE;
        }
        if ((o & PROTOCOL_ERROR_UNSPECIFIED) == PROTOCOL_ERROR_UNSPECIFIED) {
            list.add("PROTOCOL_ERROR_UNSPECIFIED");
            flipped |= PROTOCOL_ERROR_UNSPECIFIED;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

