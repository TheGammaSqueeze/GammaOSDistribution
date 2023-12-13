package android.hardware.tv.cec.V1_0;


public final class Result {
    public static final int SUCCESS = 0;
    public static final int FAILURE_UNKNOWN = 1;
    public static final int FAILURE_INVALID_ARGS = 2;
    public static final int FAILURE_INVALID_STATE = 3;
    public static final int FAILURE_NOT_SUPPORTED = 4;
    public static final int FAILURE_BUSY = 5;
    public static final String toString(int o) {
        if (o == SUCCESS) {
            return "SUCCESS";
        }
        if (o == FAILURE_UNKNOWN) {
            return "FAILURE_UNKNOWN";
        }
        if (o == FAILURE_INVALID_ARGS) {
            return "FAILURE_INVALID_ARGS";
        }
        if (o == FAILURE_INVALID_STATE) {
            return "FAILURE_INVALID_STATE";
        }
        if (o == FAILURE_NOT_SUPPORTED) {
            return "FAILURE_NOT_SUPPORTED";
        }
        if (o == FAILURE_BUSY) {
            return "FAILURE_BUSY";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("SUCCESS"); // SUCCESS == 0
        if ((o & FAILURE_UNKNOWN) == FAILURE_UNKNOWN) {
            list.add("FAILURE_UNKNOWN");
            flipped |= FAILURE_UNKNOWN;
        }
        if ((o & FAILURE_INVALID_ARGS) == FAILURE_INVALID_ARGS) {
            list.add("FAILURE_INVALID_ARGS");
            flipped |= FAILURE_INVALID_ARGS;
        }
        if ((o & FAILURE_INVALID_STATE) == FAILURE_INVALID_STATE) {
            list.add("FAILURE_INVALID_STATE");
            flipped |= FAILURE_INVALID_STATE;
        }
        if ((o & FAILURE_NOT_SUPPORTED) == FAILURE_NOT_SUPPORTED) {
            list.add("FAILURE_NOT_SUPPORTED");
            flipped |= FAILURE_NOT_SUPPORTED;
        }
        if ((o & FAILURE_BUSY) == FAILURE_BUSY) {
            list.add("FAILURE_BUSY");
            flipped |= FAILURE_BUSY;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

