package android.hardware.radio.V1_0;


public final class LceStatus {
    public static final int NOT_SUPPORTED = 0;
    public static final int STOPPED = 1 /* ::android::hardware::radio::V1_0::LceStatus.NOT_SUPPORTED implicitly + 1 */;
    public static final int ACTIVE = 2 /* ::android::hardware::radio::V1_0::LceStatus.STOPPED implicitly + 1 */;
    public static final String toString(int o) {
        if (o == NOT_SUPPORTED) {
            return "NOT_SUPPORTED";
        }
        if (o == STOPPED) {
            return "STOPPED";
        }
        if (o == ACTIVE) {
            return "ACTIVE";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("NOT_SUPPORTED"); // NOT_SUPPORTED == 0
        if ((o & STOPPED) == STOPPED) {
            list.add("STOPPED");
            flipped |= STOPPED;
        }
        if ((o & ACTIVE) == ACTIVE) {
            list.add("ACTIVE");
            flipped |= ACTIVE;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

