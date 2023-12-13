package android.hardware.gnss.V2_0;


public final class ElapsedRealtimeFlags {
    /**
     * A valid timestampNs is stored in the data structure.
     */
    public static final short HAS_TIMESTAMP_NS = 1 /* 1 << 0 */;
    /**
     * A valid timeUncertaintyNs is stored in the data structure.
     */
    public static final short HAS_TIME_UNCERTAINTY_NS = 2 /* 1 << 1 */;
    public static final String toString(short o) {
        if (o == HAS_TIMESTAMP_NS) {
            return "HAS_TIMESTAMP_NS";
        }
        if (o == HAS_TIME_UNCERTAINTY_NS) {
            return "HAS_TIME_UNCERTAINTY_NS";
        }
        return "0x" + Integer.toHexString(Short.toUnsignedInt((short)(o)));
    }

    public static final String dumpBitfield(short o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        short flipped = 0;
        if ((o & HAS_TIMESTAMP_NS) == HAS_TIMESTAMP_NS) {
            list.add("HAS_TIMESTAMP_NS");
            flipped |= HAS_TIMESTAMP_NS;
        }
        if ((o & HAS_TIME_UNCERTAINTY_NS) == HAS_TIME_UNCERTAINTY_NS) {
            list.add("HAS_TIME_UNCERTAINTY_NS");
            flipped |= HAS_TIME_UNCERTAINTY_NS;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(Short.toUnsignedInt((short)(o & (~flipped)))));
        }
        return String.join(" | ", list);
    }

};

