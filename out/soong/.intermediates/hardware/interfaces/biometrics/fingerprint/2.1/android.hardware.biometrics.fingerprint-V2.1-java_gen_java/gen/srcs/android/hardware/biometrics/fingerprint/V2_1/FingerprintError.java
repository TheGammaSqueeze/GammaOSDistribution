package android.hardware.biometrics.fingerprint.V2_1;


public final class FingerprintError {
    /**
     * Used for testing, no error returned
     */
    public static final int ERROR_NO_ERROR = 0;
    /**
     * The hardware has an error that can't be resolved.
     */
    public static final int ERROR_HW_UNAVAILABLE = 1;
    /**
     * Bad data; operation can't continue
     */
    public static final int ERROR_UNABLE_TO_PROCESS = 2;
    /**
     * The operation has timed out waiting for user input.
     */
    public static final int ERROR_TIMEOUT = 3;
    /**
     * No space available to store a template
     */
    public static final int ERROR_NO_SPACE = 4;
    /**
     * The current operation has been canceled
     */
    public static final int ERROR_CANCELED = 5;
    /**
     * Unable to remove a template
     */
    public static final int ERROR_UNABLE_TO_REMOVE = 6;
    /**
     * The hardware is in lockout due to too many attempts
     */
    public static final int ERROR_LOCKOUT = 7;
    /**
     * Vendor-specific error message
     */
    public static final int ERROR_VENDOR = 8;
    public static final String toString(int o) {
        if (o == ERROR_NO_ERROR) {
            return "ERROR_NO_ERROR";
        }
        if (o == ERROR_HW_UNAVAILABLE) {
            return "ERROR_HW_UNAVAILABLE";
        }
        if (o == ERROR_UNABLE_TO_PROCESS) {
            return "ERROR_UNABLE_TO_PROCESS";
        }
        if (o == ERROR_TIMEOUT) {
            return "ERROR_TIMEOUT";
        }
        if (o == ERROR_NO_SPACE) {
            return "ERROR_NO_SPACE";
        }
        if (o == ERROR_CANCELED) {
            return "ERROR_CANCELED";
        }
        if (o == ERROR_UNABLE_TO_REMOVE) {
            return "ERROR_UNABLE_TO_REMOVE";
        }
        if (o == ERROR_LOCKOUT) {
            return "ERROR_LOCKOUT";
        }
        if (o == ERROR_VENDOR) {
            return "ERROR_VENDOR";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("ERROR_NO_ERROR"); // ERROR_NO_ERROR == 0
        if ((o & ERROR_HW_UNAVAILABLE) == ERROR_HW_UNAVAILABLE) {
            list.add("ERROR_HW_UNAVAILABLE");
            flipped |= ERROR_HW_UNAVAILABLE;
        }
        if ((o & ERROR_UNABLE_TO_PROCESS) == ERROR_UNABLE_TO_PROCESS) {
            list.add("ERROR_UNABLE_TO_PROCESS");
            flipped |= ERROR_UNABLE_TO_PROCESS;
        }
        if ((o & ERROR_TIMEOUT) == ERROR_TIMEOUT) {
            list.add("ERROR_TIMEOUT");
            flipped |= ERROR_TIMEOUT;
        }
        if ((o & ERROR_NO_SPACE) == ERROR_NO_SPACE) {
            list.add("ERROR_NO_SPACE");
            flipped |= ERROR_NO_SPACE;
        }
        if ((o & ERROR_CANCELED) == ERROR_CANCELED) {
            list.add("ERROR_CANCELED");
            flipped |= ERROR_CANCELED;
        }
        if ((o & ERROR_UNABLE_TO_REMOVE) == ERROR_UNABLE_TO_REMOVE) {
            list.add("ERROR_UNABLE_TO_REMOVE");
            flipped |= ERROR_UNABLE_TO_REMOVE;
        }
        if ((o & ERROR_LOCKOUT) == ERROR_LOCKOUT) {
            list.add("ERROR_LOCKOUT");
            flipped |= ERROR_LOCKOUT;
        }
        if ((o & ERROR_VENDOR) == ERROR_VENDOR) {
            list.add("ERROR_VENDOR");
            flipped |= ERROR_VENDOR;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

