package android.hardware.wifi.V1_4;


public final class WifiRatePreamble {
    public static final int OFDM = 0;
    public static final int CCK = 1;
    public static final int HT = 2;
    public static final int VHT = 3;
    public static final int RESERVED = 4;
    /**
     * Preamble type for 11ax
     */
    public static final int HE = 5;
    public static final String toString(int o) {
        if (o == OFDM) {
            return "OFDM";
        }
        if (o == CCK) {
            return "CCK";
        }
        if (o == HT) {
            return "HT";
        }
        if (o == VHT) {
            return "VHT";
        }
        if (o == RESERVED) {
            return "RESERVED";
        }
        if (o == HE) {
            return "HE";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("OFDM"); // OFDM == 0
        if ((o & CCK) == CCK) {
            list.add("CCK");
            flipped |= CCK;
        }
        if ((o & HT) == HT) {
            list.add("HT");
            flipped |= HT;
        }
        if ((o & VHT) == VHT) {
            list.add("VHT");
            flipped |= VHT;
        }
        if ((o & RESERVED) == RESERVED) {
            list.add("RESERVED");
            flipped |= RESERVED;
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

