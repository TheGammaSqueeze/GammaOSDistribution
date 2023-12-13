package android.hardware.usb.V1_2;


public final class ContaminantDetectionStatus {
    /**
     * Contaminant presence detection is not supported.
     */
    public static final int NOT_SUPPORTED = 0;
    /**
     * Contaminant presence detection is supported but disabled.
     */
    public static final int DISABLED = 1;
    /**
     * Contaminant presence detection is enabled and contaminant not detected.
     */
    public static final int NOT_DETECTED = 2;
    /**
     * Contaminant presence detection is enabled and contaminant detected.
     */
    public static final int DETECTED = 3;
    public static final String toString(int o) {
        if (o == NOT_SUPPORTED) {
            return "NOT_SUPPORTED";
        }
        if (o == DISABLED) {
            return "DISABLED";
        }
        if (o == NOT_DETECTED) {
            return "NOT_DETECTED";
        }
        if (o == DETECTED) {
            return "DETECTED";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("NOT_SUPPORTED"); // NOT_SUPPORTED == 0
        if ((o & DISABLED) == DISABLED) {
            list.add("DISABLED");
            flipped |= DISABLED;
        }
        if ((o & NOT_DETECTED) == NOT_DETECTED) {
            list.add("NOT_DETECTED");
            flipped |= NOT_DETECTED;
        }
        if ((o & DETECTED) == DETECTED) {
            list.add("DETECTED");
            flipped |= DETECTED;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

