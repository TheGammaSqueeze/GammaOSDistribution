package android.hardware.wifi.supplicant.V1_4;


public final class LegacyMode {
    public static final int UNKNOWN = 0;
    /**
     * For 802.11a
     */
    public static final int A_MODE = 1;
    /**
     * For 802.11b
     */
    public static final int B_MODE = 2;
    /**
     * For 802.11g
     */
    public static final int G_MODE = 3;
    public static final String toString(int o) {
        if (o == UNKNOWN) {
            return "UNKNOWN";
        }
        if (o == A_MODE) {
            return "A_MODE";
        }
        if (o == B_MODE) {
            return "B_MODE";
        }
        if (o == G_MODE) {
            return "G_MODE";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("UNKNOWN"); // UNKNOWN == 0
        if ((o & A_MODE) == A_MODE) {
            list.add("A_MODE");
            flipped |= A_MODE;
        }
        if ((o & B_MODE) == B_MODE) {
            list.add("B_MODE");
            flipped |= B_MODE;
        }
        if ((o & G_MODE) == G_MODE) {
            list.add("G_MODE");
            flipped |= G_MODE;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

