package android.hardware.radio.V1_5;


public final class Domain {
    /**
     * Circuit-switched
     */
    public static final int CS = 1 /* 1 << 0 */;
    /**
     * Packet-switched
     */
    public static final int PS = 2 /* 1 << 1 */;
    public static final String toString(int o) {
        if (o == CS) {
            return "CS";
        }
        if (o == PS) {
            return "PS";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        if ((o & CS) == CS) {
            list.add("CS");
            flipped |= CS;
        }
        if ((o & PS) == PS) {
            list.add("PS");
            flipped |= PS;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

