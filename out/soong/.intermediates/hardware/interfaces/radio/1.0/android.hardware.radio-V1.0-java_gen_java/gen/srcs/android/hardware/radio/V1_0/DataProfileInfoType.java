package android.hardware.radio.V1_0;


public final class DataProfileInfoType {
    public static final int COMMON = 0;
    public static final int THREE_GPP = 1 /* ::android::hardware::radio::V1_0::DataProfileInfoType.COMMON implicitly + 1 */;
    public static final int THREE_GPP2 = 2 /* ::android::hardware::radio::V1_0::DataProfileInfoType.THREE_GPP implicitly + 1 */;
    public static final String toString(int o) {
        if (o == COMMON) {
            return "COMMON";
        }
        if (o == THREE_GPP) {
            return "THREE_GPP";
        }
        if (o == THREE_GPP2) {
            return "THREE_GPP2";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("COMMON"); // COMMON == 0
        if ((o & THREE_GPP) == THREE_GPP) {
            list.add("THREE_GPP");
            flipped |= THREE_GPP;
        }
        if ((o & THREE_GPP2) == THREE_GPP2) {
            list.add("THREE_GPP2");
            flipped |= THREE_GPP2;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

