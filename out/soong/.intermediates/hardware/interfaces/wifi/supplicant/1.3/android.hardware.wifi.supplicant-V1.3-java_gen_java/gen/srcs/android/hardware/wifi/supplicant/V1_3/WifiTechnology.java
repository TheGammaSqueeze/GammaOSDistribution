package android.hardware.wifi.supplicant.V1_3;


public final class WifiTechnology {
    public static final int UNKNOWN = 0;
    /**
     * For 802.11a/b/g
     */
    public static final int LEGACY = 1;
    /**
     * For 802.11n
     */
    public static final int HT = 2;
    /**
     * For 802.11ac
     */
    public static final int VHT = 3;
    /**
     * For 802.11ax
     */
    public static final int HE = 4;
    public static final String toString(int o) {
        if (o == UNKNOWN) {
            return "UNKNOWN";
        }
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
        list.add("UNKNOWN"); // UNKNOWN == 0
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

