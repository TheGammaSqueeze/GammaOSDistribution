package android.hardware.contexthub.V1_0;


public final class TransactionResult {
    public static final int SUCCESS = 0;
    public static final int FAILURE = 1 /* ::android::hardware::contexthub::V1_0::TransactionResult.SUCCESS implicitly + 1 */;
    public static final String toString(int o) {
        if (o == SUCCESS) {
            return "SUCCESS";
        }
        if (o == FAILURE) {
            return "FAILURE";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("SUCCESS"); // SUCCESS == 0
        if ((o & FAILURE) == FAILURE) {
            list.add("FAILURE");
            flipped |= FAILURE;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

