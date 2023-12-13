package android.hardware.radio.V1_0;


public final class UiccSubActStatus {
    public static final int DEACTIVATE = 0;
    public static final int ACTIVATE = 1 /* ::android::hardware::radio::V1_0::UiccSubActStatus.DEACTIVATE implicitly + 1 */;
    public static final String toString(int o) {
        if (o == DEACTIVATE) {
            return "DEACTIVATE";
        }
        if (o == ACTIVATE) {
            return "ACTIVATE";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("DEACTIVATE"); // DEACTIVATE == 0
        if ((o & ACTIVATE) == ACTIVATE) {
            list.add("ACTIVATE");
            flipped |= ACTIVATE;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

