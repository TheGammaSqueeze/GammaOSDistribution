package android.hardware.wifi.supplicant.V1_4;


public final class WpaDriverCapabilitiesMask {
    /**
     * Multi Band Operation.
     */
    public static final int MBO = 1 /* 1 << 0 */;
    /**
     * Optimized Connectivity Experience.
     */
    public static final int OCE = 2 /* 1 << 1 */;
    /**
     * WPA3 SAE Public-Key.
     */
    public static final int SAE_PK = 4 /* 1 << 2 */;
    /**
     * Wi-Fi Display R2
     */
    public static final int WFD_R2 = 8 /* 1 << 3 */;
    public static final String toString(int o) {
        if (o == MBO) {
            return "MBO";
        }
        if (o == OCE) {
            return "OCE";
        }
        if (o == SAE_PK) {
            return "SAE_PK";
        }
        if (o == WFD_R2) {
            return "WFD_R2";
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
        if ((o & SAE_PK) == SAE_PK) {
            list.add("SAE_PK");
            flipped |= SAE_PK;
        }
        if ((o & WFD_R2) == WFD_R2) {
            list.add("WFD_R2");
            flipped |= WFD_R2;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

