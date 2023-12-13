package android.hardware.radio.V1_2;


public final class DataRequestReason {
    /**
     * The reason of the data request is normal
     */
    public static final int NORMAL = 1 /* 0x01 */;
    /**
     * The reason of the data request is device shutdown
     */
    public static final int SHUTDOWN = 2 /* 0x02 */;
    /**
     * The reason of the data request is IWLAN data handover to another transport
     * (e.g. from cellular to wifi or vise versa)
     */
    public static final int HANDOVER = 3 /* 0x03 */;
    public static final String toString(int o) {
        if (o == NORMAL) {
            return "NORMAL";
        }
        if (o == SHUTDOWN) {
            return "SHUTDOWN";
        }
        if (o == HANDOVER) {
            return "HANDOVER";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        if ((o & NORMAL) == NORMAL) {
            list.add("NORMAL");
            flipped |= NORMAL;
        }
        if ((o & SHUTDOWN) == SHUTDOWN) {
            list.add("SHUTDOWN");
            flipped |= SHUTDOWN;
        }
        if ((o & HANDOVER) == HANDOVER) {
            list.add("HANDOVER");
            flipped |= HANDOVER;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

