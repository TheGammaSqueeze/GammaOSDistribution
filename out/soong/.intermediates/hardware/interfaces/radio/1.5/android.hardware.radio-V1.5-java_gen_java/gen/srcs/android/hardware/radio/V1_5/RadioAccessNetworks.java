package android.hardware.radio.V1_5;


public final class RadioAccessNetworks {
    public static final int GERAN = 1;
    public static final int UTRAN = 2;
    public static final int EUTRAN = 3;
    public static final int UNKNOWN = 0;
    /**
     * Next Generation Radio Access Network
     */
    public static final int NGRAN = 4;
    /**
     * CDMA 2000 Network
     */
    public static final int CDMA2000 = 5;
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
        if (o == UNKNOWN) {
            return "UNKNOWN";
        }
        if (o == NGRAN) {
            return "NGRAN";
        }
        if (o == CDMA2000) {
            return "CDMA2000";
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
        list.add("UNKNOWN"); // UNKNOWN == 0
        if ((o & NGRAN) == NGRAN) {
            list.add("NGRAN");
            flipped |= NGRAN;
        }
        if ((o & CDMA2000) == CDMA2000) {
            list.add("CDMA2000");
            flipped |= CDMA2000;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

