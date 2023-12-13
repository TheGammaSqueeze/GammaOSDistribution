package android.hardware.radio.V1_4;


public final class EmergencyCallRouting {
    /**
     * Indicates Android does not require how to handle the corresponding emergency call; it is
     * decided by implementation.
     */
    public static final int UNKNOWN = 0;
    /**
     * Indicates the implementation must handle the call through emergency routing.
     */
    public static final int EMERGENCY = 1;
    /**
     * Indicates the implementation must handle the call through normal call routing.
     */
    public static final int NORMAL = 2;
    public static final String toString(int o) {
        if (o == UNKNOWN) {
            return "UNKNOWN";
        }
        if (o == EMERGENCY) {
            return "EMERGENCY";
        }
        if (o == NORMAL) {
            return "NORMAL";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("UNKNOWN"); // UNKNOWN == 0
        if ((o & EMERGENCY) == EMERGENCY) {
            list.add("EMERGENCY");
            flipped |= EMERGENCY;
        }
        if ((o & NORMAL) == NORMAL) {
            list.add("NORMAL");
            flipped |= NORMAL;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

