package android.hardware.wifi.V1_0;


public final class NanStatusType {
    public static final int SUCCESS = 0;
    /**
     * NAN Discovery Engine/Host driver failures
     */
    public static final int INTERNAL_FAILURE = 1;
    /**
     * NAN OTA failures
     */
    public static final int PROTOCOL_FAILURE = 2;
    /**
     * The publish/subscribe discovery session id is invalid
     */
    public static final int INVALID_SESSION_ID = 3;
    /**
     * Out of resources to fufill request
     */
    public static final int NO_RESOURCES_AVAILABLE = 4;
    /**
     * Invalid arguments passed
     */
    public static final int INVALID_ARGS = 5;
    /**
     * Invalid peer id
     */
    public static final int INVALID_PEER_ID = 6;
    /**
     * Invalid NAN data-path (ndp) id
     */
    public static final int INVALID_NDP_ID = 7;
    /**
     * Attempting to enable NAN when not available, e.g. wifi is disabled
     */
    public static final int NAN_NOT_ALLOWED = 8;
    /**
     * Over the air ACK not received
     */
    public static final int NO_OTA_ACK = 9;
    /**
     * Attempting to enable NAN when already enabled
     */
    public static final int ALREADY_ENABLED = 10;
    /**
     * Can't queue tx followup message foor transmission
     */
    public static final int FOLLOWUP_TX_QUEUE_FULL = 11;
    /**
     * Unsupported concurrency of NAN and another feature - NAN disabled
     */
    public static final int UNSUPPORTED_CONCURRENCY_NAN_DISABLED = 12;
    public static final String toString(int o) {
        if (o == SUCCESS) {
            return "SUCCESS";
        }
        if (o == INTERNAL_FAILURE) {
            return "INTERNAL_FAILURE";
        }
        if (o == PROTOCOL_FAILURE) {
            return "PROTOCOL_FAILURE";
        }
        if (o == INVALID_SESSION_ID) {
            return "INVALID_SESSION_ID";
        }
        if (o == NO_RESOURCES_AVAILABLE) {
            return "NO_RESOURCES_AVAILABLE";
        }
        if (o == INVALID_ARGS) {
            return "INVALID_ARGS";
        }
        if (o == INVALID_PEER_ID) {
            return "INVALID_PEER_ID";
        }
        if (o == INVALID_NDP_ID) {
            return "INVALID_NDP_ID";
        }
        if (o == NAN_NOT_ALLOWED) {
            return "NAN_NOT_ALLOWED";
        }
        if (o == NO_OTA_ACK) {
            return "NO_OTA_ACK";
        }
        if (o == ALREADY_ENABLED) {
            return "ALREADY_ENABLED";
        }
        if (o == FOLLOWUP_TX_QUEUE_FULL) {
            return "FOLLOWUP_TX_QUEUE_FULL";
        }
        if (o == UNSUPPORTED_CONCURRENCY_NAN_DISABLED) {
            return "UNSUPPORTED_CONCURRENCY_NAN_DISABLED";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("SUCCESS"); // SUCCESS == 0
        if ((o & INTERNAL_FAILURE) == INTERNAL_FAILURE) {
            list.add("INTERNAL_FAILURE");
            flipped |= INTERNAL_FAILURE;
        }
        if ((o & PROTOCOL_FAILURE) == PROTOCOL_FAILURE) {
            list.add("PROTOCOL_FAILURE");
            flipped |= PROTOCOL_FAILURE;
        }
        if ((o & INVALID_SESSION_ID) == INVALID_SESSION_ID) {
            list.add("INVALID_SESSION_ID");
            flipped |= INVALID_SESSION_ID;
        }
        if ((o & NO_RESOURCES_AVAILABLE) == NO_RESOURCES_AVAILABLE) {
            list.add("NO_RESOURCES_AVAILABLE");
            flipped |= NO_RESOURCES_AVAILABLE;
        }
        if ((o & INVALID_ARGS) == INVALID_ARGS) {
            list.add("INVALID_ARGS");
            flipped |= INVALID_ARGS;
        }
        if ((o & INVALID_PEER_ID) == INVALID_PEER_ID) {
            list.add("INVALID_PEER_ID");
            flipped |= INVALID_PEER_ID;
        }
        if ((o & INVALID_NDP_ID) == INVALID_NDP_ID) {
            list.add("INVALID_NDP_ID");
            flipped |= INVALID_NDP_ID;
        }
        if ((o & NAN_NOT_ALLOWED) == NAN_NOT_ALLOWED) {
            list.add("NAN_NOT_ALLOWED");
            flipped |= NAN_NOT_ALLOWED;
        }
        if ((o & NO_OTA_ACK) == NO_OTA_ACK) {
            list.add("NO_OTA_ACK");
            flipped |= NO_OTA_ACK;
        }
        if ((o & ALREADY_ENABLED) == ALREADY_ENABLED) {
            list.add("ALREADY_ENABLED");
            flipped |= ALREADY_ENABLED;
        }
        if ((o & FOLLOWUP_TX_QUEUE_FULL) == FOLLOWUP_TX_QUEUE_FULL) {
            list.add("FOLLOWUP_TX_QUEUE_FULL");
            flipped |= FOLLOWUP_TX_QUEUE_FULL;
        }
        if ((o & UNSUPPORTED_CONCURRENCY_NAN_DISABLED) == UNSUPPORTED_CONCURRENCY_NAN_DISABLED) {
            list.add("UNSUPPORTED_CONCURRENCY_NAN_DISABLED");
            flipped |= UNSUPPORTED_CONCURRENCY_NAN_DISABLED;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

