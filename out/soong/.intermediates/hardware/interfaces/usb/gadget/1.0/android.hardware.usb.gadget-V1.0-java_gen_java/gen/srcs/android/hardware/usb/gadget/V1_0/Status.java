package android.hardware.usb.gadget.V1_0;


public final class Status {
    public static final int SUCCESS = 0;
    /**
     * Error value when the HAL operation fails for reasons not listed here.
     */
    public static final int ERROR = 1;
    /**
     * USB configuration applied successfully.
     */
    public static final int FUNCTIONS_APPLIED = 2;
    /**
     * USB confgiuration failed to apply.
     */
    public static final int FUNCTIONS_NOT_APPLIED = 3;
    /**
     * USB configuration not supported.
     */
    public static final int CONFIGURATION_NOT_SUPPORTED = 4;
    public static final String toString(int o) {
        if (o == SUCCESS) {
            return "SUCCESS";
        }
        if (o == ERROR) {
            return "ERROR";
        }
        if (o == FUNCTIONS_APPLIED) {
            return "FUNCTIONS_APPLIED";
        }
        if (o == FUNCTIONS_NOT_APPLIED) {
            return "FUNCTIONS_NOT_APPLIED";
        }
        if (o == CONFIGURATION_NOT_SUPPORTED) {
            return "CONFIGURATION_NOT_SUPPORTED";
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
        if ((o & FUNCTIONS_APPLIED) == FUNCTIONS_APPLIED) {
            list.add("FUNCTIONS_APPLIED");
            flipped |= FUNCTIONS_APPLIED;
        }
        if ((o & FUNCTIONS_NOT_APPLIED) == FUNCTIONS_NOT_APPLIED) {
            list.add("FUNCTIONS_NOT_APPLIED");
            flipped |= FUNCTIONS_NOT_APPLIED;
        }
        if ((o & CONFIGURATION_NOT_SUPPORTED) == CONFIGURATION_NOT_SUPPORTED) {
            list.add("CONFIGURATION_NOT_SUPPORTED");
            flipped |= CONFIGURATION_NOT_SUPPORTED;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

