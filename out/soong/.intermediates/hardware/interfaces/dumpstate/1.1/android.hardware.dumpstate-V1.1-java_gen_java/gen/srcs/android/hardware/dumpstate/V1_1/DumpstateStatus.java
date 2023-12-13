package android.hardware.dumpstate.V1_1;


public final class DumpstateStatus {
    public static final int OK = 0;
    /**
     * Returned for cases where the device doesn't support the given DumpstateMode (e.g. a phone
     * trying to use DumpstateMode::WEAR).
     */
    public static final int UNSUPPORTED_MODE = 1;
    /**
     * Returned for cases where an IllegalArgumentException is typically appropriate, e.g. missing
     * file descriptors.
     */
    public static final int ILLEGAL_ARGUMENT = 2;
    /**
     * Returned when device logging is not enabled.
     */
    public static final int DEVICE_LOGGING_NOT_ENABLED = 3;
    public static final String toString(int o) {
        if (o == OK) {
            return "OK";
        }
        if (o == UNSUPPORTED_MODE) {
            return "UNSUPPORTED_MODE";
        }
        if (o == ILLEGAL_ARGUMENT) {
            return "ILLEGAL_ARGUMENT";
        }
        if (o == DEVICE_LOGGING_NOT_ENABLED) {
            return "DEVICE_LOGGING_NOT_ENABLED";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("OK"); // OK == 0
        if ((o & UNSUPPORTED_MODE) == UNSUPPORTED_MODE) {
            list.add("UNSUPPORTED_MODE");
            flipped |= UNSUPPORTED_MODE;
        }
        if ((o & ILLEGAL_ARGUMENT) == ILLEGAL_ARGUMENT) {
            list.add("ILLEGAL_ARGUMENT");
            flipped |= ILLEGAL_ARGUMENT;
        }
        if ((o & DEVICE_LOGGING_NOT_ENABLED) == DEVICE_LOGGING_NOT_ENABLED) {
            list.add("DEVICE_LOGGING_NOT_ENABLED");
            flipped |= DEVICE_LOGGING_NOT_ENABLED;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

