package android.hardware.vibrator.V1_0;


public final class Status {
    public static final int OK = 0;
    public static final int UNKNOWN_ERROR = 1 /* ::android::hardware::vibrator::V1_0::Status.OK implicitly + 1 */;
    public static final int BAD_VALUE = 2 /* ::android::hardware::vibrator::V1_0::Status.UNKNOWN_ERROR implicitly + 1 */;
    public static final int UNSUPPORTED_OPERATION = 3 /* ::android::hardware::vibrator::V1_0::Status.BAD_VALUE implicitly + 1 */;
    public static final String toString(int o) {
        if (o == OK) {
            return "OK";
        }
        if (o == UNKNOWN_ERROR) {
            return "UNKNOWN_ERROR";
        }
        if (o == BAD_VALUE) {
            return "BAD_VALUE";
        }
        if (o == UNSUPPORTED_OPERATION) {
            return "UNSUPPORTED_OPERATION";
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
        if ((o & BAD_VALUE) == BAD_VALUE) {
            list.add("BAD_VALUE");
            flipped |= BAD_VALUE;
        }
        if ((o & UNSUPPORTED_OPERATION) == UNSUPPORTED_OPERATION) {
            list.add("UNSUPPORTED_OPERATION");
            flipped |= UNSUPPORTED_OPERATION;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

