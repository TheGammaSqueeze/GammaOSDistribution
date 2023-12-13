package android.hardware.wifi.V1_0;


public final class NanMatchAlg {
    public static final int MATCH_ONCE = 0;
    public static final int MATCH_CONTINUOUS = 1 /* ::android::hardware::wifi::V1_0::NanMatchAlg.MATCH_ONCE implicitly + 1 */;
    public static final int MATCH_NEVER = 2 /* ::android::hardware::wifi::V1_0::NanMatchAlg.MATCH_CONTINUOUS implicitly + 1 */;
    public static final String toString(int o) {
        if (o == MATCH_ONCE) {
            return "MATCH_ONCE";
        }
        if (o == MATCH_CONTINUOUS) {
            return "MATCH_CONTINUOUS";
        }
        if (o == MATCH_NEVER) {
            return "MATCH_NEVER";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("MATCH_ONCE"); // MATCH_ONCE == 0
        if ((o & MATCH_CONTINUOUS) == MATCH_CONTINUOUS) {
            list.add("MATCH_CONTINUOUS");
            flipped |= MATCH_CONTINUOUS;
        }
        if ((o & MATCH_NEVER) == MATCH_NEVER) {
            list.add("MATCH_NEVER");
            flipped |= MATCH_NEVER;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

