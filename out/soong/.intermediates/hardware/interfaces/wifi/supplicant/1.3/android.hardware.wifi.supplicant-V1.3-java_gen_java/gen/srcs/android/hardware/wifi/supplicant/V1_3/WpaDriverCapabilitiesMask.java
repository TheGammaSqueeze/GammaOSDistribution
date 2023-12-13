package android.hardware.wifi.supplicant.V1_3;


public final class WpaDriverCapabilitiesMask {
    /**
     * Multi Band Operation.
     */
    public static final int MBO = 1 /* 1 << 0 */;
    /**
     * Optimized Connectivity Experience.
     */
    public static final int OCE = 2 /* 1 << 1 */;
    public static final String toString(int o) {
        if (o == MBO) {
            return "MBO";
        }
        if (o == OCE) {
            return "OCE";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        if ((o & MBO) == MBO) {
            list.add("MBO");
            flipped |= MBO;
        }
        if ((o & OCE) == OCE) {
            list.add("OCE");
            flipped |= OCE;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

