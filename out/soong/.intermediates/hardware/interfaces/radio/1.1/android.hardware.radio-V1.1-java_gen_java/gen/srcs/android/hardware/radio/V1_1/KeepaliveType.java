package android.hardware.radio.V1_1;


public final class KeepaliveType {
    public static final int NATT_IPV4 = 0;
    public static final int NATT_IPV6 = 1;
    public static final String toString(int o) {
        if (o == NATT_IPV4) {
            return "NATT_IPV4";
        }
        if (o == NATT_IPV6) {
            return "NATT_IPV6";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("NATT_IPV4"); // NATT_IPV4 == 0
        if ((o & NATT_IPV6) == NATT_IPV6) {
            list.add("NATT_IPV6");
            flipped |= NATT_IPV6;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

