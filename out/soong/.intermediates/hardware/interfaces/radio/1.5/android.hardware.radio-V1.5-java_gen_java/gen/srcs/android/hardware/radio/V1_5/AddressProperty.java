package android.hardware.radio.V1_5;


public final class AddressProperty {
    public static final int NONE = 0;
    /**
     * Indicates this address is deprecated
     */
    public static final int DEPRECATED = 32 /* 0x20 */;
    public static final String toString(int o) {
        if (o == NONE) {
            return "NONE";
        }
        if (o == DEPRECATED) {
            return "DEPRECATED";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("NONE"); // NONE == 0
        if ((o & DEPRECATED) == DEPRECATED) {
            list.add("DEPRECATED");
            flipped |= DEPRECATED;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

