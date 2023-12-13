package android.hardware.wifi.V1_0;


public final class RttMotionPattern {
    /**
     * Not expected to change location.
     */
    public static final int NOT_EXPECTED = 0;
    /**
     * Expected to change location.
     */
    public static final int EXPECTED = 1;
    /**
     * Movement pattern unknown.
     */
    public static final int UNKNOWN = 2;
    public static final String toString(int o) {
        if (o == NOT_EXPECTED) {
            return "NOT_EXPECTED";
        }
        if (o == EXPECTED) {
            return "EXPECTED";
        }
        if (o == UNKNOWN) {
            return "UNKNOWN";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("NOT_EXPECTED"); // NOT_EXPECTED == 0
        if ((o & EXPECTED) == EXPECTED) {
            list.add("EXPECTED");
            flipped |= EXPECTED;
        }
        if ((o & UNKNOWN) == UNKNOWN) {
            list.add("UNKNOWN");
            flipped |= UNKNOWN;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

