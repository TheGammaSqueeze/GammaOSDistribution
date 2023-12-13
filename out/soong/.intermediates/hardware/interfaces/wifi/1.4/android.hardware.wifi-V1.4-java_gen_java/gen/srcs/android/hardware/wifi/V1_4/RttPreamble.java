package android.hardware.wifi.V1_4;


public final class RttPreamble {
    public static final int LEGACY = 1 /* 0x1 */;
    public static final int HT = 2 /* 0x2 */;
    public static final int VHT = 4 /* 0x4 */;
    /**
     * Preamble type for 11ax
     */
    public static final int HE = 8 /* 0x8 */;
    public static final String toString(int o) {
        if (o == LEGACY) {
            return "LEGACY";
        }
        if (o == HT) {
            return "HT";
        }
        if (o == VHT) {
            return "VHT";
        }
        if (o == HE) {
            return "HE";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        if ((o & LEGACY) == LEGACY) {
            list.add("LEGACY");
            flipped |= LEGACY;
        }
        if ((o & HT) == HT) {
            list.add("HT");
            flipped |= HT;
        }
        if ((o & VHT) == VHT) {
            list.add("VHT");
            flipped |= VHT;
        }
        if ((o & HE) == HE) {
            list.add("HE");
            flipped |= HE;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

