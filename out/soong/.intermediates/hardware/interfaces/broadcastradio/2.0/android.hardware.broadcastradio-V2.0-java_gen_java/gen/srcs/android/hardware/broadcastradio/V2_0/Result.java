package android.hardware.broadcastradio.V2_0;


public final class Result {
    public static final int OK = 0;
    public static final int UNKNOWN_ERROR = 1 /* ::android::hardware::broadcastradio::V2_0::Result.OK implicitly + 1 */;
    public static final int INTERNAL_ERROR = 2 /* ::android::hardware::broadcastradio::V2_0::Result.UNKNOWN_ERROR implicitly + 1 */;
    public static final int INVALID_ARGUMENTS = 3 /* ::android::hardware::broadcastradio::V2_0::Result.INTERNAL_ERROR implicitly + 1 */;
    public static final int INVALID_STATE = 4 /* ::android::hardware::broadcastradio::V2_0::Result.INVALID_ARGUMENTS implicitly + 1 */;
    public static final int NOT_SUPPORTED = 5 /* ::android::hardware::broadcastradio::V2_0::Result.INVALID_STATE implicitly + 1 */;
    public static final int TIMEOUT = 6 /* ::android::hardware::broadcastradio::V2_0::Result.NOT_SUPPORTED implicitly + 1 */;
    public static final String toString(int o) {
        if (o == OK) {
            return "OK";
        }
        if (o == UNKNOWN_ERROR) {
            return "UNKNOWN_ERROR";
        }
        if (o == INTERNAL_ERROR) {
            return "INTERNAL_ERROR";
        }
        if (o == INVALID_ARGUMENTS) {
            return "INVALID_ARGUMENTS";
        }
        if (o == INVALID_STATE) {
            return "INVALID_STATE";
        }
        if (o == NOT_SUPPORTED) {
            return "NOT_SUPPORTED";
        }
        if (o == TIMEOUT) {
            return "TIMEOUT";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("OK"); // OK == 0
        if ((o & UNKNOWN_ERROR) == UNKNOWN_ERROR) {
            list.add("UNKNOWN_ERROR");
            flipped |= UNKNOWN_ERROR;
        }
        if ((o & INTERNAL_ERROR) == INTERNAL_ERROR) {
            list.add("INTERNAL_ERROR");
            flipped |= INTERNAL_ERROR;
        }
        if ((o & INVALID_ARGUMENTS) == INVALID_ARGUMENTS) {
            list.add("INVALID_ARGUMENTS");
            flipped |= INVALID_ARGUMENTS;
        }
        if ((o & INVALID_STATE) == INVALID_STATE) {
            list.add("INVALID_STATE");
            flipped |= INVALID_STATE;
        }
        if ((o & NOT_SUPPORTED) == NOT_SUPPORTED) {
            list.add("NOT_SUPPORTED");
            flipped |= NOT_SUPPORTED;
        }
        if ((o & TIMEOUT) == TIMEOUT) {
            list.add("TIMEOUT");
            flipped |= TIMEOUT;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

