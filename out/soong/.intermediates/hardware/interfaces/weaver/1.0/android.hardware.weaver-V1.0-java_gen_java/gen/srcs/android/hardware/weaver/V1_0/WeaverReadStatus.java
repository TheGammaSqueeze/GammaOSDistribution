package android.hardware.weaver.V1_0;


public final class WeaverReadStatus {
    public static final int OK = 0;
    public static final int FAILED = 1 /* ::android::hardware::weaver::V1_0::WeaverStatus.OK implicitly + 1 */;
    public static final int INCORRECT_KEY = 2 /* ::android::hardware::weaver::V1_0::WeaverStatus.FAILED implicitly + 1 */;
    public static final int THROTTLE = 3 /* ::android::hardware::weaver::V1_0::WeaverReadStatus.INCORRECT_KEY implicitly + 1 */;
    public static final String toString(int o) {
        if (o == OK) {
            return "OK";
        }
        if (o == FAILED) {
            return "FAILED";
        }
        if (o == INCORRECT_KEY) {
            return "INCORRECT_KEY";
        }
        if (o == THROTTLE) {
            return "THROTTLE";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("OK"); // OK == 0
        if ((o & FAILED) == FAILED) {
            list.add("FAILED");
            flipped |= FAILED;
        }
        if ((o & INCORRECT_KEY) == INCORRECT_KEY) {
            list.add("INCORRECT_KEY");
            flipped |= INCORRECT_KEY;
        }
        if ((o & THROTTLE) == THROTTLE) {
            list.add("THROTTLE");
            flipped |= THROTTLE;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

