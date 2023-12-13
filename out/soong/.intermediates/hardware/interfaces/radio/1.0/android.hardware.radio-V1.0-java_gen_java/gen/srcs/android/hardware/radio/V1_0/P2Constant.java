package android.hardware.radio.V1_0;


public final class P2Constant {
    public static final int NO_P2 = -1 /* -1 */;
    public static final String toString(int o) {
        if (o == NO_P2) {
            return "NO_P2";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        if ((o & NO_P2) == NO_P2) {
            list.add("NO_P2");
            flipped |= NO_P2;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

