package android.hardware.radio.V1_0;


public final class RadioError {
    public static final int NONE = 0;
    public static final int RADIO_NOT_AVAILABLE = 1;
    public static final int GENERIC_FAILURE = 2;
    public static final int PASSWORD_INCORRECT = 3;
    public static final int SIM_PIN2 = 4;
    public static final int SIM_PUK2 = 5;
    public static final int REQUEST_NOT_SUPPORTED = 6;
    public static final int CANCELLED = 7;
    public static final int OP_NOT_ALLOWED_DURING_VOICE_CALL = 8;
    public static final int OP_NOT_ALLOWED_BEFORE_REG_TO_NW = 9;
    public static final int SMS_SEND_FAIL_RETRY = 10;
    public static final int SIM_ABSENT = 11;
    public static final int SUBSCRIPTION_NOT_AVAILABLE = 12;
    public static final int MODE_NOT_SUPPORTED = 13;
    public static final int FDN_CHECK_FAILURE = 14;
    public static final int ILLEGAL_SIM_OR_ME = 15;
    public static final int MISSING_RESOURCE = 16;
    public static final int NO_SUCH_ELEMENT = 17;
    public static final int DIAL_MODIFIED_TO_USSD = 18;
    public static final int DIAL_MODIFIED_TO_SS = 19;
    public static final int DIAL_MODIFIED_TO_DIAL = 20;
    public static final int USSD_MODIFIED_TO_DIAL = 21;
    public static final int USSD_MODIFIED_TO_SS = 22;
    public static final int USSD_MODIFIED_TO_USSD = 23;
    public static final int SS_MODIFIED_TO_DIAL = 24;
    public static final int SS_MODIFIED_TO_USSD = 25;
    public static final int SUBSCRIPTION_NOT_SUPPORTED = 26;
    public static final int SS_MODIFIED_TO_SS = 27;
    public static final int LCE_NOT_SUPPORTED = 36;
    public static final int NO_MEMORY = 37;
    public static final int INTERNAL_ERR = 38;
    public static final int SYSTEM_ERR = 39;
    public static final int MODEM_ERR = 40;
    public static final int INVALID_STATE = 41;
    public static final int NO_RESOURCES = 42;
    public static final int SIM_ERR = 43;
    public static final int INVALID_ARGUMENTS = 44;
    public static final int INVALID_SIM_STATE = 45;
    public static final int INVALID_MODEM_STATE = 46;
    public static final int INVALID_CALL_ID = 47;
    public static final int NO_SMS_TO_ACK = 48;
    public static final int NETWORK_ERR = 49;
    public static final int REQUEST_RATE_LIMITED = 50;
    public static final int SIM_BUSY = 51;
    public static final int SIM_FULL = 52;
    public static final int NETWORK_REJECT = 53;
    public static final int OPERATION_NOT_ALLOWED = 54;
    public static final int EMPTY_RECORD = 55;
    public static final int INVALID_SMS_FORMAT = 56;
    public static final int ENCODING_ERR = 57;
    public static final int INVALID_SMSC_ADDRESS = 58;
    public static final int NO_SUCH_ENTRY = 59;
    public static final int NETWORK_NOT_READY = 60;
    public static final int NOT_PROVISIONED = 61;
    public static final int NO_SUBSCRIPTION = 62;
    public static final int NO_NETWORK_FOUND = 63;
    public static final int DEVICE_IN_USE = 64;
    public static final int ABORTED = 65;
    public static final int INVALID_RESPONSE = 66;
    public static final int OEM_ERROR_1 = 501;
    public static final int OEM_ERROR_2 = 502;
    public static final int OEM_ERROR_3 = 503;
    public static final int OEM_ERROR_4 = 504;
    public static final int OEM_ERROR_5 = 505;
    public static final int OEM_ERROR_6 = 506;
    public static final int OEM_ERROR_7 = 507;
    public static final int OEM_ERROR_8 = 508;
    public static final int OEM_ERROR_9 = 509;
    public static final int OEM_ERROR_10 = 510;
    public static final int OEM_ERROR_11 = 511;
    public static final int OEM_ERROR_12 = 512;
    public static final int OEM_ERROR_13 = 513;
    public static final int OEM_ERROR_14 = 514;
    public static final int OEM_ERROR_15 = 515;
    public static final int OEM_ERROR_16 = 516;
    public static final int OEM_ERROR_17 = 517;
    public static final int OEM_ERROR_18 = 518;
    public static final int OEM_ERROR_19 = 519;
    public static final int OEM_ERROR_20 = 520;
    public static final int OEM_ERROR_21 = 521;
    public static final int OEM_ERROR_22 = 522;
    public static final int OEM_ERROR_23 = 523;
    public static final int OEM_ERROR_24 = 524;
    public static final int OEM_ERROR_25 = 525;
    public static final String toString(int o) {
        if (o == NONE) {
            return "NONE";
        }
        if (o == RADIO_NOT_AVAILABLE) {
            return "RADIO_NOT_AVAILABLE";
        }
        if (o == GENERIC_FAILURE) {
            return "GENERIC_FAILURE";
        }
        if (o == PASSWORD_INCORRECT) {
            return "PASSWORD_INCORRECT";
        }
        if (o == SIM_PIN2) {
            return "SIM_PIN2";
        }
        if (o == SIM_PUK2) {
            return "SIM_PUK2";
        }
        if (o == REQUEST_NOT_SUPPORTED) {
            return "REQUEST_NOT_SUPPORTED";
        }
        if (o == CANCELLED) {
            return "CANCELLED";
        }
        if (o == OP_NOT_ALLOWED_DURING_VOICE_CALL) {
            return "OP_NOT_ALLOWED_DURING_VOICE_CALL";
        }
        if (o == OP_NOT_ALLOWED_BEFORE_REG_TO_NW) {
            return "OP_NOT_ALLOWED_BEFORE_REG_TO_NW";
        }
        if (o == SMS_SEND_FAIL_RETRY) {
            return "SMS_SEND_FAIL_RETRY";
        }
        if (o == SIM_ABSENT) {
            return "SIM_ABSENT";
        }
        if (o == SUBSCRIPTION_NOT_AVAILABLE) {
            return "SUBSCRIPTION_NOT_AVAILABLE";
        }
        if (o == MODE_NOT_SUPPORTED) {
            return "MODE_NOT_SUPPORTED";
        }
        if (o == FDN_CHECK_FAILURE) {
            return "FDN_CHECK_FAILURE";
        }
        if (o == ILLEGAL_SIM_OR_ME) {
            return "ILLEGAL_SIM_OR_ME";
        }
        if (o == MISSING_RESOURCE) {
            return "MISSING_RESOURCE";
        }
        if (o == NO_SUCH_ELEMENT) {
            return "NO_SUCH_ELEMENT";
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
        if (o == USSD_MODIFIED_TO_DIAL) {
            return "USSD_MODIFIED_TO_DIAL";
        }
        if (o == USSD_MODIFIED_TO_SS) {
            return "USSD_MODIFIED_TO_SS";
        }
        if (o == USSD_MODIFIED_TO_USSD) {
            return "USSD_MODIFIED_TO_USSD";
        }
        if (o == SS_MODIFIED_TO_DIAL) {
            return "SS_MODIFIED_TO_DIAL";
        }
        if (o == SS_MODIFIED_TO_USSD) {
            return "SS_MODIFIED_TO_USSD";
        }
        if (o == SUBSCRIPTION_NOT_SUPPORTED) {
            return "SUBSCRIPTION_NOT_SUPPORTED";
        }
        if (o == SS_MODIFIED_TO_SS) {
            return "SS_MODIFIED_TO_SS";
        }
        if (o == LCE_NOT_SUPPORTED) {
            return "LCE_NOT_SUPPORTED";
        }
        if (o == NO_MEMORY) {
            return "NO_MEMORY";
        }
        if (o == INTERNAL_ERR) {
            return "INTERNAL_ERR";
        }
        if (o == SYSTEM_ERR) {
            return "SYSTEM_ERR";
        }
        if (o == MODEM_ERR) {
            return "MODEM_ERR";
        }
        if (o == INVALID_STATE) {
            return "INVALID_STATE";
        }
        if (o == NO_RESOURCES) {
            return "NO_RESOURCES";
        }
        if (o == SIM_ERR) {
            return "SIM_ERR";
        }
        if (o == INVALID_ARGUMENTS) {
            return "INVALID_ARGUMENTS";
        }
        if (o == INVALID_SIM_STATE) {
            return "INVALID_SIM_STATE";
        }
        if (o == INVALID_MODEM_STATE) {
            return "INVALID_MODEM_STATE";
        }
        if (o == INVALID_CALL_ID) {
            return "INVALID_CALL_ID";
        }
        if (o == NO_SMS_TO_ACK) {
            return "NO_SMS_TO_ACK";
        }
        if (o == NETWORK_ERR) {
            return "NETWORK_ERR";
        }
        if (o == REQUEST_RATE_LIMITED) {
            return "REQUEST_RATE_LIMITED";
        }
        if (o == SIM_BUSY) {
            return "SIM_BUSY";
        }
        if (o == SIM_FULL) {
            return "SIM_FULL";
        }
        if (o == NETWORK_REJECT) {
            return "NETWORK_REJECT";
        }
        if (o == OPERATION_NOT_ALLOWED) {
            return "OPERATION_NOT_ALLOWED";
        }
        if (o == EMPTY_RECORD) {
            return "EMPTY_RECORD";
        }
        if (o == INVALID_SMS_FORMAT) {
            return "INVALID_SMS_FORMAT";
        }
        if (o == ENCODING_ERR) {
            return "ENCODING_ERR";
        }
        if (o == INVALID_SMSC_ADDRESS) {
            return "INVALID_SMSC_ADDRESS";
        }
        if (o == NO_SUCH_ENTRY) {
            return "NO_SUCH_ENTRY";
        }
        if (o == NETWORK_NOT_READY) {
            return "NETWORK_NOT_READY";
        }
        if (o == NOT_PROVISIONED) {
            return "NOT_PROVISIONED";
        }
        if (o == NO_SUBSCRIPTION) {
            return "NO_SUBSCRIPTION";
        }
        if (o == NO_NETWORK_FOUND) {
            return "NO_NETWORK_FOUND";
        }
        if (o == DEVICE_IN_USE) {
            return "DEVICE_IN_USE";
        }
        if (o == ABORTED) {
            return "ABORTED";
        }
        if (o == INVALID_RESPONSE) {
            return "INVALID_RESPONSE";
        }
        if (o == OEM_ERROR_1) {
            return "OEM_ERROR_1";
        }
        if (o == OEM_ERROR_2) {
            return "OEM_ERROR_2";
        }
        if (o == OEM_ERROR_3) {
            return "OEM_ERROR_3";
        }
        if (o == OEM_ERROR_4) {
            return "OEM_ERROR_4";
        }
        if (o == OEM_ERROR_5) {
            return "OEM_ERROR_5";
        }
        if (o == OEM_ERROR_6) {
            return "OEM_ERROR_6";
        }
        if (o == OEM_ERROR_7) {
            return "OEM_ERROR_7";
        }
        if (o == OEM_ERROR_8) {
            return "OEM_ERROR_8";
        }
        if (o == OEM_ERROR_9) {
            return "OEM_ERROR_9";
        }
        if (o == OEM_ERROR_10) {
            return "OEM_ERROR_10";
        }
        if (o == OEM_ERROR_11) {
            return "OEM_ERROR_11";
        }
        if (o == OEM_ERROR_12) {
            return "OEM_ERROR_12";
        }
        if (o == OEM_ERROR_13) {
            return "OEM_ERROR_13";
        }
        if (o == OEM_ERROR_14) {
            return "OEM_ERROR_14";
        }
        if (o == OEM_ERROR_15) {
            return "OEM_ERROR_15";
        }
        if (o == OEM_ERROR_16) {
            return "OEM_ERROR_16";
        }
        if (o == OEM_ERROR_17) {
            return "OEM_ERROR_17";
        }
        if (o == OEM_ERROR_18) {
            return "OEM_ERROR_18";
        }
        if (o == OEM_ERROR_19) {
            return "OEM_ERROR_19";
        }
        if (o == OEM_ERROR_20) {
            return "OEM_ERROR_20";
        }
        if (o == OEM_ERROR_21) {
            return "OEM_ERROR_21";
        }
        if (o == OEM_ERROR_22) {
            return "OEM_ERROR_22";
        }
        if (o == OEM_ERROR_23) {
            return "OEM_ERROR_23";
        }
        if (o == OEM_ERROR_24) {
            return "OEM_ERROR_24";
        }
        if (o == OEM_ERROR_25) {
            return "OEM_ERROR_25";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("NONE"); // NONE == 0
        if ((o & RADIO_NOT_AVAILABLE) == RADIO_NOT_AVAILABLE) {
            list.add("RADIO_NOT_AVAILABLE");
            flipped |= RADIO_NOT_AVAILABLE;
        }
        if ((o & GENERIC_FAILURE) == GENERIC_FAILURE) {
            list.add("GENERIC_FAILURE");
            flipped |= GENERIC_FAILURE;
        }
        if ((o & PASSWORD_INCORRECT) == PASSWORD_INCORRECT) {
            list.add("PASSWORD_INCORRECT");
            flipped |= PASSWORD_INCORRECT;
        }
        if ((o & SIM_PIN2) == SIM_PIN2) {
            list.add("SIM_PIN2");
            flipped |= SIM_PIN2;
        }
        if ((o & SIM_PUK2) == SIM_PUK2) {
            list.add("SIM_PUK2");
            flipped |= SIM_PUK2;
        }
        if ((o & REQUEST_NOT_SUPPORTED) == REQUEST_NOT_SUPPORTED) {
            list.add("REQUEST_NOT_SUPPORTED");
            flipped |= REQUEST_NOT_SUPPORTED;
        }
        if ((o & CANCELLED) == CANCELLED) {
            list.add("CANCELLED");
            flipped |= CANCELLED;
        }
        if ((o & OP_NOT_ALLOWED_DURING_VOICE_CALL) == OP_NOT_ALLOWED_DURING_VOICE_CALL) {
            list.add("OP_NOT_ALLOWED_DURING_VOICE_CALL");
            flipped |= OP_NOT_ALLOWED_DURING_VOICE_CALL;
        }
        if ((o & OP_NOT_ALLOWED_BEFORE_REG_TO_NW) == OP_NOT_ALLOWED_BEFORE_REG_TO_NW) {
            list.add("OP_NOT_ALLOWED_BEFORE_REG_TO_NW");
            flipped |= OP_NOT_ALLOWED_BEFORE_REG_TO_NW;
        }
        if ((o & SMS_SEND_FAIL_RETRY) == SMS_SEND_FAIL_RETRY) {
            list.add("SMS_SEND_FAIL_RETRY");
            flipped |= SMS_SEND_FAIL_RETRY;
        }
        if ((o & SIM_ABSENT) == SIM_ABSENT) {
            list.add("SIM_ABSENT");
            flipped |= SIM_ABSENT;
        }
        if ((o & SUBSCRIPTION_NOT_AVAILABLE) == SUBSCRIPTION_NOT_AVAILABLE) {
            list.add("SUBSCRIPTION_NOT_AVAILABLE");
            flipped |= SUBSCRIPTION_NOT_AVAILABLE;
        }
        if ((o & MODE_NOT_SUPPORTED) == MODE_NOT_SUPPORTED) {
            list.add("MODE_NOT_SUPPORTED");
            flipped |= MODE_NOT_SUPPORTED;
        }
        if ((o & FDN_CHECK_FAILURE) == FDN_CHECK_FAILURE) {
            list.add("FDN_CHECK_FAILURE");
            flipped |= FDN_CHECK_FAILURE;
        }
        if ((o & ILLEGAL_SIM_OR_ME) == ILLEGAL_SIM_OR_ME) {
            list.add("ILLEGAL_SIM_OR_ME");
            flipped |= ILLEGAL_SIM_OR_ME;
        }
        if ((o & MISSING_RESOURCE) == MISSING_RESOURCE) {
            list.add("MISSING_RESOURCE");
            flipped |= MISSING_RESOURCE;
        }
        if ((o & NO_SUCH_ELEMENT) == NO_SUCH_ELEMENT) {
            list.add("NO_SUCH_ELEMENT");
            flipped |= NO_SUCH_ELEMENT;
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
        if ((o & USSD_MODIFIED_TO_DIAL) == USSD_MODIFIED_TO_DIAL) {
            list.add("USSD_MODIFIED_TO_DIAL");
            flipped |= USSD_MODIFIED_TO_DIAL;
        }
        if ((o & USSD_MODIFIED_TO_SS) == USSD_MODIFIED_TO_SS) {
            list.add("USSD_MODIFIED_TO_SS");
            flipped |= USSD_MODIFIED_TO_SS;
        }
        if ((o & USSD_MODIFIED_TO_USSD) == USSD_MODIFIED_TO_USSD) {
            list.add("USSD_MODIFIED_TO_USSD");
            flipped |= USSD_MODIFIED_TO_USSD;
        }
        if ((o & SS_MODIFIED_TO_DIAL) == SS_MODIFIED_TO_DIAL) {
            list.add("SS_MODIFIED_TO_DIAL");
            flipped |= SS_MODIFIED_TO_DIAL;
        }
        if ((o & SS_MODIFIED_TO_USSD) == SS_MODIFIED_TO_USSD) {
            list.add("SS_MODIFIED_TO_USSD");
            flipped |= SS_MODIFIED_TO_USSD;
        }
        if ((o & SUBSCRIPTION_NOT_SUPPORTED) == SUBSCRIPTION_NOT_SUPPORTED) {
            list.add("SUBSCRIPTION_NOT_SUPPORTED");
            flipped |= SUBSCRIPTION_NOT_SUPPORTED;
        }
        if ((o & SS_MODIFIED_TO_SS) == SS_MODIFIED_TO_SS) {
            list.add("SS_MODIFIED_TO_SS");
            flipped |= SS_MODIFIED_TO_SS;
        }
        if ((o & LCE_NOT_SUPPORTED) == LCE_NOT_SUPPORTED) {
            list.add("LCE_NOT_SUPPORTED");
            flipped |= LCE_NOT_SUPPORTED;
        }
        if ((o & NO_MEMORY) == NO_MEMORY) {
            list.add("NO_MEMORY");
            flipped |= NO_MEMORY;
        }
        if ((o & INTERNAL_ERR) == INTERNAL_ERR) {
            list.add("INTERNAL_ERR");
            flipped |= INTERNAL_ERR;
        }
        if ((o & SYSTEM_ERR) == SYSTEM_ERR) {
            list.add("SYSTEM_ERR");
            flipped |= SYSTEM_ERR;
        }
        if ((o & MODEM_ERR) == MODEM_ERR) {
            list.add("MODEM_ERR");
            flipped |= MODEM_ERR;
        }
        if ((o & INVALID_STATE) == INVALID_STATE) {
            list.add("INVALID_STATE");
            flipped |= INVALID_STATE;
        }
        if ((o & NO_RESOURCES) == NO_RESOURCES) {
            list.add("NO_RESOURCES");
            flipped |= NO_RESOURCES;
        }
        if ((o & SIM_ERR) == SIM_ERR) {
            list.add("SIM_ERR");
            flipped |= SIM_ERR;
        }
        if ((o & INVALID_ARGUMENTS) == INVALID_ARGUMENTS) {
            list.add("INVALID_ARGUMENTS");
            flipped |= INVALID_ARGUMENTS;
        }
        if ((o & INVALID_SIM_STATE) == INVALID_SIM_STATE) {
            list.add("INVALID_SIM_STATE");
            flipped |= INVALID_SIM_STATE;
        }
        if ((o & INVALID_MODEM_STATE) == INVALID_MODEM_STATE) {
            list.add("INVALID_MODEM_STATE");
            flipped |= INVALID_MODEM_STATE;
        }
        if ((o & INVALID_CALL_ID) == INVALID_CALL_ID) {
            list.add("INVALID_CALL_ID");
            flipped |= INVALID_CALL_ID;
        }
        if ((o & NO_SMS_TO_ACK) == NO_SMS_TO_ACK) {
            list.add("NO_SMS_TO_ACK");
            flipped |= NO_SMS_TO_ACK;
        }
        if ((o & NETWORK_ERR) == NETWORK_ERR) {
            list.add("NETWORK_ERR");
            flipped |= NETWORK_ERR;
        }
        if ((o & REQUEST_RATE_LIMITED) == REQUEST_RATE_LIMITED) {
            list.add("REQUEST_RATE_LIMITED");
            flipped |= REQUEST_RATE_LIMITED;
        }
        if ((o & SIM_BUSY) == SIM_BUSY) {
            list.add("SIM_BUSY");
            flipped |= SIM_BUSY;
        }
        if ((o & SIM_FULL) == SIM_FULL) {
            list.add("SIM_FULL");
            flipped |= SIM_FULL;
        }
        if ((o & NETWORK_REJECT) == NETWORK_REJECT) {
            list.add("NETWORK_REJECT");
            flipped |= NETWORK_REJECT;
        }
        if ((o & OPERATION_NOT_ALLOWED) == OPERATION_NOT_ALLOWED) {
            list.add("OPERATION_NOT_ALLOWED");
            flipped |= OPERATION_NOT_ALLOWED;
        }
        if ((o & EMPTY_RECORD) == EMPTY_RECORD) {
            list.add("EMPTY_RECORD");
            flipped |= EMPTY_RECORD;
        }
        if ((o & INVALID_SMS_FORMAT) == INVALID_SMS_FORMAT) {
            list.add("INVALID_SMS_FORMAT");
            flipped |= INVALID_SMS_FORMAT;
        }
        if ((o & ENCODING_ERR) == ENCODING_ERR) {
            list.add("ENCODING_ERR");
            flipped |= ENCODING_ERR;
        }
        if ((o & INVALID_SMSC_ADDRESS) == INVALID_SMSC_ADDRESS) {
            list.add("INVALID_SMSC_ADDRESS");
            flipped |= INVALID_SMSC_ADDRESS;
        }
        if ((o & NO_SUCH_ENTRY) == NO_SUCH_ENTRY) {
            list.add("NO_SUCH_ENTRY");
            flipped |= NO_SUCH_ENTRY;
        }
        if ((o & NETWORK_NOT_READY) == NETWORK_NOT_READY) {
            list.add("NETWORK_NOT_READY");
            flipped |= NETWORK_NOT_READY;
        }
        if ((o & NOT_PROVISIONED) == NOT_PROVISIONED) {
            list.add("NOT_PROVISIONED");
            flipped |= NOT_PROVISIONED;
        }
        if ((o & NO_SUBSCRIPTION) == NO_SUBSCRIPTION) {
            list.add("NO_SUBSCRIPTION");
            flipped |= NO_SUBSCRIPTION;
        }
        if ((o & NO_NETWORK_FOUND) == NO_NETWORK_FOUND) {
            list.add("NO_NETWORK_FOUND");
            flipped |= NO_NETWORK_FOUND;
        }
        if ((o & DEVICE_IN_USE) == DEVICE_IN_USE) {
            list.add("DEVICE_IN_USE");
            flipped |= DEVICE_IN_USE;
        }
        if ((o & ABORTED) == ABORTED) {
            list.add("ABORTED");
            flipped |= ABORTED;
        }
        if ((o & INVALID_RESPONSE) == INVALID_RESPONSE) {
            list.add("INVALID_RESPONSE");
            flipped |= INVALID_RESPONSE;
        }
        if ((o & OEM_ERROR_1) == OEM_ERROR_1) {
            list.add("OEM_ERROR_1");
            flipped |= OEM_ERROR_1;
        }
        if ((o & OEM_ERROR_2) == OEM_ERROR_2) {
            list.add("OEM_ERROR_2");
            flipped |= OEM_ERROR_2;
        }
        if ((o & OEM_ERROR_3) == OEM_ERROR_3) {
            list.add("OEM_ERROR_3");
            flipped |= OEM_ERROR_3;
        }
        if ((o & OEM_ERROR_4) == OEM_ERROR_4) {
            list.add("OEM_ERROR_4");
            flipped |= OEM_ERROR_4;
        }
        if ((o & OEM_ERROR_5) == OEM_ERROR_5) {
            list.add("OEM_ERROR_5");
            flipped |= OEM_ERROR_5;
        }
        if ((o & OEM_ERROR_6) == OEM_ERROR_6) {
            list.add("OEM_ERROR_6");
            flipped |= OEM_ERROR_6;
        }
        if ((o & OEM_ERROR_7) == OEM_ERROR_7) {
            list.add("OEM_ERROR_7");
            flipped |= OEM_ERROR_7;
        }
        if ((o & OEM_ERROR_8) == OEM_ERROR_8) {
            list.add("OEM_ERROR_8");
            flipped |= OEM_ERROR_8;
        }
        if ((o & OEM_ERROR_9) == OEM_ERROR_9) {
            list.add("OEM_ERROR_9");
            flipped |= OEM_ERROR_9;
        }
        if ((o & OEM_ERROR_10) == OEM_ERROR_10) {
            list.add("OEM_ERROR_10");
            flipped |= OEM_ERROR_10;
        }
        if ((o & OEM_ERROR_11) == OEM_ERROR_11) {
            list.add("OEM_ERROR_11");
            flipped |= OEM_ERROR_11;
        }
        if ((o & OEM_ERROR_12) == OEM_ERROR_12) {
            list.add("OEM_ERROR_12");
            flipped |= OEM_ERROR_12;
        }
        if ((o & OEM_ERROR_13) == OEM_ERROR_13) {
            list.add("OEM_ERROR_13");
            flipped |= OEM_ERROR_13;
        }
        if ((o & OEM_ERROR_14) == OEM_ERROR_14) {
            list.add("OEM_ERROR_14");
            flipped |= OEM_ERROR_14;
        }
        if ((o & OEM_ERROR_15) == OEM_ERROR_15) {
            list.add("OEM_ERROR_15");
            flipped |= OEM_ERROR_15;
        }
        if ((o & OEM_ERROR_16) == OEM_ERROR_16) {
            list.add("OEM_ERROR_16");
            flipped |= OEM_ERROR_16;
        }
        if ((o & OEM_ERROR_17) == OEM_ERROR_17) {
            list.add("OEM_ERROR_17");
            flipped |= OEM_ERROR_17;
        }
        if ((o & OEM_ERROR_18) == OEM_ERROR_18) {
            list.add("OEM_ERROR_18");
            flipped |= OEM_ERROR_18;
        }
        if ((o & OEM_ERROR_19) == OEM_ERROR_19) {
            list.add("OEM_ERROR_19");
            flipped |= OEM_ERROR_19;
        }
        if ((o & OEM_ERROR_20) == OEM_ERROR_20) {
            list.add("OEM_ERROR_20");
            flipped |= OEM_ERROR_20;
        }
        if ((o & OEM_ERROR_21) == OEM_ERROR_21) {
            list.add("OEM_ERROR_21");
            flipped |= OEM_ERROR_21;
        }
        if ((o & OEM_ERROR_22) == OEM_ERROR_22) {
            list.add("OEM_ERROR_22");
            flipped |= OEM_ERROR_22;
        }
        if ((o & OEM_ERROR_23) == OEM_ERROR_23) {
            list.add("OEM_ERROR_23");
            flipped |= OEM_ERROR_23;
        }
        if ((o & OEM_ERROR_24) == OEM_ERROR_24) {
            list.add("OEM_ERROR_24");
            flipped |= OEM_ERROR_24;
        }
        if ((o & OEM_ERROR_25) == OEM_ERROR_25) {
            list.add("OEM_ERROR_25");
            flipped |= OEM_ERROR_25;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

