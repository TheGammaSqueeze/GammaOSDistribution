package android.hardware.wifi.V1_0;


public final class RttBw {
    public static final int BW_5MHZ = 1 /* 0x01 */;
    public static final int BW_10MHZ = 2 /* 0x02 */;
    public static final int BW_20MHZ = 4 /* 0x04 */;
    public static final int BW_40MHZ = 8 /* 0x08 */;
    public static final int BW_80MHZ = 16 /* 0x10 */;
    public static final int BW_160MHZ = 32 /* 0x20 */;
    public static final String toString(int o) {
        if (o == BW_5MHZ) {
            return "BW_5MHZ";
        }
        if (o == BW_10MHZ) {
            return "BW_10MHZ";
        }
        if (o == BW_20MHZ) {
            return "BW_20MHZ";
        }
        if (o == BW_40MHZ) {
            return "BW_40MHZ";
        }
        if (o == BW_80MHZ) {
            return "BW_80MHZ";
        }
        if (o == BW_160MHZ) {
            return "BW_160MHZ";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        if ((o & BW_5MHZ) == BW_5MHZ) {
            list.add("BW_5MHZ");
            flipped |= BW_5MHZ;
        }
        if ((o & BW_10MHZ) == BW_10MHZ) {
            list.add("BW_10MHZ");
            flipped |= BW_10MHZ;
        }
        if ((o & BW_20MHZ) == BW_20MHZ) {
            list.add("BW_20MHZ");
            flipped |= BW_20MHZ;
        }
        if ((o & BW_40MHZ) == BW_40MHZ) {
            list.add("BW_40MHZ");
            flipped |= BW_40MHZ;
        }
        if ((o & BW_80MHZ) == BW_80MHZ) {
            list.add("BW_80MHZ");
            flipped |= BW_80MHZ;
        }
        if ((o & BW_160MHZ) == BW_160MHZ) {
            list.add("BW_160MHZ");
            flipped |= BW_160MHZ;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

