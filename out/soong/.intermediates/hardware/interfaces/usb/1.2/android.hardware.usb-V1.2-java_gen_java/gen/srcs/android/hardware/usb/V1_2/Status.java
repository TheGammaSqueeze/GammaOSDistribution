package android.hardware.usb.V1_2;


public final class Status {
    public static final int SUCCESS = 0;
    /**
     * error value when the HAL operation fails for reasons not listed here.
     */
    public static final int ERROR = 1;
    /**
     * error value returned when input argument is invalid.
     */
    public static final int INVALID_ARGUMENT = 2;
    /**
     * error value returned when role string is unrecognized.
     */
    public static final int UNRECOGNIZED_ROLE = 3;
    /**
     * Error value returned when the operation is not supported.
     */
    public static final int NOT_SUPPORTED = 4;
    public static final String toString(int o) {
        if (o == SUCCESS) {
            return "SUCCESS";
        }
        if (o == ERROR) {
            return "ERROR";
        }
        if (o == INVALID_ARGUMENT) {
            return "INVALID_ARGUMENT";
        }
        if (o == UNRECOGNIZED_ROLE) {
            return "UNRECOGNIZED_ROLE";
        }
        if (o == NOT_SUPPORTED) {
            return "NOT_SUPPORTED";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("SUCCESS"); // SUCCESS == 0
        if ((o & ERROR) == ERROR) {
            list.add("ERROR");
            flipped |= ERROR;
        }
        if ((o & INVALID_ARGUMENT) == INVALID_ARGUMENT) {
            list.add("INVALID_ARGUMENT");
            flipped |= INVALID_ARGUMENT;
        }
        if ((o & UNRECOGNIZED_ROLE) == UNRECOGNIZED_ROLE) {
            list.add("UNRECOGNIZED_ROLE");
            flipped |= UNRECOGNIZED_ROLE;
        }
        if ((o & NOT_SUPPORTED) == NOT_SUPPORTED) {
            list.add("NOT_SUPPORTED");
            flipped |= NOT_SUPPORTED;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

