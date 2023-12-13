package android.hardware.contexthub.V1_0;


public final class Result {
    public static final int OK = 0;
    public static final int UNKNOWN_FAILURE = 1 /* ::android::hardware::contexthub::V1_0::Result.OK implicitly + 1 */;
    public static final int BAD_PARAMS = 2 /* ::android::hardware::contexthub::V1_0::Result.UNKNOWN_FAILURE implicitly + 1 */;
    public static final int NOT_INIT = 3 /* ::android::hardware::contexthub::V1_0::Result.BAD_PARAMS implicitly + 1 */;
    public static final int TRANSACTION_FAILED = 4 /* ::android::hardware::contexthub::V1_0::Result.NOT_INIT implicitly + 1 */;
    public static final int TRANSACTION_PENDING = 5 /* ::android::hardware::contexthub::V1_0::Result.TRANSACTION_FAILED implicitly + 1 */;
    public static final String toString(int o) {
        if (o == OK) {
            return "OK";
        }
        if (o == UNKNOWN_FAILURE) {
            return "UNKNOWN_FAILURE";
        }
        if (o == BAD_PARAMS) {
            return "BAD_PARAMS";
        }
        if (o == NOT_INIT) {
            return "NOT_INIT";
        }
        if (o == TRANSACTION_FAILED) {
            return "TRANSACTION_FAILED";
        }
        if (o == TRANSACTION_PENDING) {
            return "TRANSACTION_PENDING";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("OK"); // OK == 0
        if ((o & UNKNOWN_FAILURE) == UNKNOWN_FAILURE) {
            list.add("UNKNOWN_FAILURE");
            flipped |= UNKNOWN_FAILURE;
        }
        if ((o & BAD_PARAMS) == BAD_PARAMS) {
            list.add("BAD_PARAMS");
            flipped |= BAD_PARAMS;
        }
        if ((o & NOT_INIT) == NOT_INIT) {
            list.add("NOT_INIT");
            flipped |= NOT_INIT;
        }
        if ((o & TRANSACTION_FAILED) == TRANSACTION_FAILED) {
            list.add("TRANSACTION_FAILED");
            flipped |= TRANSACTION_FAILED;
        }
        if ((o & TRANSACTION_PENDING) == TRANSACTION_PENDING) {
            list.add("TRANSACTION_PENDING");
            flipped |= TRANSACTION_PENDING;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

