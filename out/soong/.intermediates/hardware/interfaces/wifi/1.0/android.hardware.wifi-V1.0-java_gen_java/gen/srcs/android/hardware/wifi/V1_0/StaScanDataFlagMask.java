package android.hardware.wifi.V1_0;


public final class StaScanDataFlagMask {
    /**
     * Indicates that a scan was interrupted/did not occur so results may be
     * incomplete.
     */
    public static final int INTERRUPTED = 1 /* 1 << 0 */;
    public static final String toString(int o) {
        if (o == INTERRUPTED) {
            return "INTERRUPTED";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        if ((o & INTERRUPTED) == INTERRUPTED) {
            list.add("INTERRUPTED");
            flipped |= INTERRUPTED;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

