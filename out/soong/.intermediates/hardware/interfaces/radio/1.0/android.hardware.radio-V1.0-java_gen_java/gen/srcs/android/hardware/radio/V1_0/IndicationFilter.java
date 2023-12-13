package android.hardware.radio.V1_0;


public final class IndicationFilter {
    public static final int NONE = 0;
    public static final int SIGNAL_STRENGTH = 1 /* 1 << 0 */;
    public static final int FULL_NETWORK_STATE = 2 /* 1 << 1 */;
    public static final int DATA_CALL_DORMANCY_CHANGED = 4 /* 1 << 2 */;
    public static final int ALL = 7 /* SIGNAL_STRENGTH | FULL_NETWORK_STATE | DATA_CALL_DORMANCY_CHANGED */;
    public static final String toString(int o) {
        if (o == NONE) {
            return "NONE";
        }
        if (o == SIGNAL_STRENGTH) {
            return "SIGNAL_STRENGTH";
        }
        if (o == FULL_NETWORK_STATE) {
            return "FULL_NETWORK_STATE";
        }
        if (o == DATA_CALL_DORMANCY_CHANGED) {
            return "DATA_CALL_DORMANCY_CHANGED";
        }
        if (o == ALL) {
            return "ALL";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("NONE"); // NONE == 0
        if ((o & SIGNAL_STRENGTH) == SIGNAL_STRENGTH) {
            list.add("SIGNAL_STRENGTH");
            flipped |= SIGNAL_STRENGTH;
        }
        if ((o & FULL_NETWORK_STATE) == FULL_NETWORK_STATE) {
            list.add("FULL_NETWORK_STATE");
            flipped |= FULL_NETWORK_STATE;
        }
        if ((o & DATA_CALL_DORMANCY_CHANGED) == DATA_CALL_DORMANCY_CHANGED) {
            list.add("DATA_CALL_DORMANCY_CHANGED");
            flipped |= DATA_CALL_DORMANCY_CHANGED;
        }
        if ((o & ALL) == ALL) {
            list.add("ALL");
            flipped |= ALL;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

