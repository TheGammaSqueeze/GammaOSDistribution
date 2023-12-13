package android.hardware.wifi.V1_0;


public final class RttStatus {
    public static final int SUCCESS = 0;
    /**
     * General failure status
     */
    public static final int FAILURE = 1;
    /**
     * Target STA does not respond to request
     */
    public static final int FAIL_NO_RSP = 2;
    /**
     * Request rejected. Applies to 2-sided RTT only
     */
    public static final int FAIL_REJECTED = 3;
    public static final int FAIL_NOT_SCHEDULED_YET = 4;
    /**
     * Timing measurement times out
     */
    public static final int FAIL_TM_TIMEOUT = 5;
    /**
     * Target on different channel, cannot range
     */
    public static final int FAIL_AP_ON_DIFF_CHANNEL = 6;
    /**
     * Ranging not supported
     */
    public static final int FAIL_NO_CAPABILITY = 7;
    /**
     * Request aborted for unknown reason
     */
    public static final int ABORTED = 8;
    /**
     * Invalid T1-T4 timestamp
     */
    public static final int FAIL_INVALID_TS = 9;
    /**
     * 11mc protocol failed
     */
    public static final int FAIL_PROTOCOL = 10;
    /**
     * Request could not be scheduled
     */
    public static final int FAIL_SCHEDULE = 11;
    /**
     * Responder cannot collaborate at time of request
     */
    public static final int FAIL_BUSY_TRY_LATER = 12;
    /**
     * Bad request args
     */
    public static final int INVALID_REQ = 13;
    /**
     * WiFi not enabled.
     */
    public static final int NO_WIFI = 14;
    /**
     * Responder overrides param info, cannot range with new params
     */
    public static final int FAIL_FTM_PARAM_OVERRIDE = 15;
    public static final String toString(int o) {
        if (o == SUCCESS) {
            return "SUCCESS";
        }
        if (o == FAILURE) {
            return "FAILURE";
        }
        if (o == FAIL_NO_RSP) {
            return "FAIL_NO_RSP";
        }
        if (o == FAIL_REJECTED) {
            return "FAIL_REJECTED";
        }
        if (o == FAIL_NOT_SCHEDULED_YET) {
            return "FAIL_NOT_SCHEDULED_YET";
        }
        if (o == FAIL_TM_TIMEOUT) {
            return "FAIL_TM_TIMEOUT";
        }
        if (o == FAIL_AP_ON_DIFF_CHANNEL) {
            return "FAIL_AP_ON_DIFF_CHANNEL";
        }
        if (o == FAIL_NO_CAPABILITY) {
            return "FAIL_NO_CAPABILITY";
        }
        if (o == ABORTED) {
            return "ABORTED";
        }
        if (o == FAIL_INVALID_TS) {
            return "FAIL_INVALID_TS";
        }
        if (o == FAIL_PROTOCOL) {
            return "FAIL_PROTOCOL";
        }
        if (o == FAIL_SCHEDULE) {
            return "FAIL_SCHEDULE";
        }
        if (o == FAIL_BUSY_TRY_LATER) {
            return "FAIL_BUSY_TRY_LATER";
        }
        if (o == INVALID_REQ) {
            return "INVALID_REQ";
        }
        if (o == NO_WIFI) {
            return "NO_WIFI";
        }
        if (o == FAIL_FTM_PARAM_OVERRIDE) {
            return "FAIL_FTM_PARAM_OVERRIDE";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("SUCCESS"); // SUCCESS == 0
        if ((o & FAILURE) == FAILURE) {
            list.add("FAILURE");
            flipped |= FAILURE;
        }
        if ((o & FAIL_NO_RSP) == FAIL_NO_RSP) {
            list.add("FAIL_NO_RSP");
            flipped |= FAIL_NO_RSP;
        }
        if ((o & FAIL_REJECTED) == FAIL_REJECTED) {
            list.add("FAIL_REJECTED");
            flipped |= FAIL_REJECTED;
        }
        if ((o & FAIL_NOT_SCHEDULED_YET) == FAIL_NOT_SCHEDULED_YET) {
            list.add("FAIL_NOT_SCHEDULED_YET");
            flipped |= FAIL_NOT_SCHEDULED_YET;
        }
        if ((o & FAIL_TM_TIMEOUT) == FAIL_TM_TIMEOUT) {
            list.add("FAIL_TM_TIMEOUT");
            flipped |= FAIL_TM_TIMEOUT;
        }
        if ((o & FAIL_AP_ON_DIFF_CHANNEL) == FAIL_AP_ON_DIFF_CHANNEL) {
            list.add("FAIL_AP_ON_DIFF_CHANNEL");
            flipped |= FAIL_AP_ON_DIFF_CHANNEL;
        }
        if ((o & FAIL_NO_CAPABILITY) == FAIL_NO_CAPABILITY) {
            list.add("FAIL_NO_CAPABILITY");
            flipped |= FAIL_NO_CAPABILITY;
        }
        if ((o & ABORTED) == ABORTED) {
            list.add("ABORTED");
            flipped |= ABORTED;
        }
        if ((o & FAIL_INVALID_TS) == FAIL_INVALID_TS) {
            list.add("FAIL_INVALID_TS");
            flipped |= FAIL_INVALID_TS;
        }
        if ((o & FAIL_PROTOCOL) == FAIL_PROTOCOL) {
            list.add("FAIL_PROTOCOL");
            flipped |= FAIL_PROTOCOL;
        }
        if ((o & FAIL_SCHEDULE) == FAIL_SCHEDULE) {
            list.add("FAIL_SCHEDULE");
            flipped |= FAIL_SCHEDULE;
        }
        if ((o & FAIL_BUSY_TRY_LATER) == FAIL_BUSY_TRY_LATER) {
            list.add("FAIL_BUSY_TRY_LATER");
            flipped |= FAIL_BUSY_TRY_LATER;
        }
        if ((o & INVALID_REQ) == INVALID_REQ) {
            list.add("INVALID_REQ");
            flipped |= INVALID_REQ;
        }
        if ((o & NO_WIFI) == NO_WIFI) {
            list.add("NO_WIFI");
            flipped |= NO_WIFI;
        }
        if ((o & FAIL_FTM_PARAM_OVERRIDE) == FAIL_FTM_PARAM_OVERRIDE) {
            list.add("FAIL_FTM_PARAM_OVERRIDE");
            flipped |= FAIL_FTM_PARAM_OVERRIDE;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

