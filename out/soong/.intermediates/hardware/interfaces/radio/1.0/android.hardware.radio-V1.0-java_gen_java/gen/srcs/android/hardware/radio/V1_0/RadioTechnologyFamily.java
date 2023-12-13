package android.hardware.radio.V1_0;


public final class RadioTechnologyFamily {
    public static final int THREE_GPP = 0;
    public static final int THREE_GPP2 = 1 /* ::android::hardware::radio::V1_0::RadioTechnologyFamily.THREE_GPP implicitly + 1 */;
    public static final String toString(int o) {
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
        list.add("THREE_GPP"); // THREE_GPP == 0
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

