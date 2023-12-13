package android.hardware.radio.V1_0;


public final class ApnAuthType {
    public static final int NO_PAP_NO_CHAP = 0;
    public static final int PAP_NO_CHAP = 1 /* ::android::hardware::radio::V1_0::ApnAuthType.NO_PAP_NO_CHAP implicitly + 1 */;
    public static final int NO_PAP_CHAP = 2 /* ::android::hardware::radio::V1_0::ApnAuthType.PAP_NO_CHAP implicitly + 1 */;
    public static final int PAP_CHAP = 3 /* ::android::hardware::radio::V1_0::ApnAuthType.NO_PAP_CHAP implicitly + 1 */;
    public static final String toString(int o) {
        if (o == NO_PAP_NO_CHAP) {
            return "NO_PAP_NO_CHAP";
        }
        if (o == PAP_NO_CHAP) {
            return "PAP_NO_CHAP";
        }
        if (o == NO_PAP_CHAP) {
            return "NO_PAP_CHAP";
        }
        if (o == PAP_CHAP) {
            return "PAP_CHAP";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("NO_PAP_NO_CHAP"); // NO_PAP_NO_CHAP == 0
        if ((o & PAP_NO_CHAP) == PAP_NO_CHAP) {
            list.add("PAP_NO_CHAP");
            flipped |= PAP_NO_CHAP;
        }
        if ((o & NO_PAP_CHAP) == NO_PAP_CHAP) {
            list.add("NO_PAP_CHAP");
            flipped |= NO_PAP_CHAP;
        }
        if ((o & PAP_CHAP) == PAP_CHAP) {
            list.add("PAP_CHAP");
            flipped |= PAP_CHAP;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

