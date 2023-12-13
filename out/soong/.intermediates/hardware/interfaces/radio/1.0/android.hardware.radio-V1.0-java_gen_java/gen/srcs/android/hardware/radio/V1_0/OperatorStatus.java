package android.hardware.radio.V1_0;


public final class OperatorStatus {
    public static final int UNKNOWN = 0;
    public static final int AVAILABLE = 1 /* ::android::hardware::radio::V1_0::OperatorStatus.UNKNOWN implicitly + 1 */;
    public static final int CURRENT = 2 /* ::android::hardware::radio::V1_0::OperatorStatus.AVAILABLE implicitly + 1 */;
    public static final int FORBIDDEN = 3 /* ::android::hardware::radio::V1_0::OperatorStatus.CURRENT implicitly + 1 */;
    public static final String toString(int o) {
        if (o == UNKNOWN) {
            return "UNKNOWN";
        }
        if (o == AVAILABLE) {
            return "AVAILABLE";
        }
        if (o == CURRENT) {
            return "CURRENT";
        }
        if (o == FORBIDDEN) {
            return "FORBIDDEN";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("UNKNOWN"); // UNKNOWN == 0
        if ((o & AVAILABLE) == AVAILABLE) {
            list.add("AVAILABLE");
            flipped |= AVAILABLE;
        }
        if ((o & CURRENT) == CURRENT) {
            list.add("CURRENT");
            flipped |= CURRENT;
        }
        if ((o & FORBIDDEN) == FORBIDDEN) {
            list.add("FORBIDDEN");
            flipped |= FORBIDDEN;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

