package android.hardware.radio.V1_4;


public final class AccessNetwork {
    /**
     * GSM EDGE Radio Access Network
     */
    public static final int GERAN = 1;
    /**
     * Universal Terrestrial Radio Access Network
     */
    public static final int UTRAN = 2;
    /**
     * Evolved Universal Terrestrial Radio Access Network
     */
    public static final int EUTRAN = 3;
    /**
     * CDMA 2000 network
     */
    public static final int CDMA2000 = 4;
    /**
     * Interworking Wireless LAN
     */
    public static final int IWLAN = 5;
    /**
     * Unknown access network
     */
    public static final int UNKNOWN = 0;
    public static final String toString(int o) {
        if (o == GERAN) {
            return "GERAN";
        }
        if (o == UTRAN) {
            return "UTRAN";
        }
        if (o == EUTRAN) {
            return "EUTRAN";
        }
        if (o == CDMA2000) {
            return "CDMA2000";
        }
        if (o == IWLAN) {
            return "IWLAN";
        }
        if (o == UNKNOWN) {
            return "UNKNOWN";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        if ((o & GERAN) == GERAN) {
            list.add("GERAN");
            flipped |= GERAN;
        }
        if ((o & UTRAN) == UTRAN) {
            list.add("UTRAN");
            flipped |= UTRAN;
        }
        if ((o & EUTRAN) == EUTRAN) {
            list.add("EUTRAN");
            flipped |= EUTRAN;
        }
        if ((o & CDMA2000) == CDMA2000) {
            list.add("CDMA2000");
            flipped |= CDMA2000;
        }
        if ((o & IWLAN) == IWLAN) {
            list.add("IWLAN");
            flipped |= IWLAN;
        }
        list.add("UNKNOWN"); // UNKNOWN == 0
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

