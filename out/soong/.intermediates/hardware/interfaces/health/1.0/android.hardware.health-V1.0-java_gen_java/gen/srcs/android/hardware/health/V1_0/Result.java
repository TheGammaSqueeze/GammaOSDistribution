package android.hardware.health.V1_0;


public final class Result {
    public static final int SUCCESS = 0;
    public static final int NOT_SUPPORTED = 1 /* ::android::hardware::health::V1_0::Result.SUCCESS implicitly + 1 */;
    public static final int UNKNOWN = 2 /* ::android::hardware::health::V1_0::Result.NOT_SUPPORTED implicitly + 1 */;
    public static final String toString(int o) {
        if (o == SUCCESS) {
            return "SUCCESS";
        }
        if (o == NOT_SUPPORTED) {
            return "NOT_SUPPORTED";
        }
        if (o == UNKNOWN) {
            return "UNKNOWN";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("SUCCESS"); // SUCCESS == 0
        if ((o & NOT_SUPPORTED) == NOT_SUPPORTED) {
            list.add("NOT_SUPPORTED");
            flipped |= NOT_SUPPORTED;
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

