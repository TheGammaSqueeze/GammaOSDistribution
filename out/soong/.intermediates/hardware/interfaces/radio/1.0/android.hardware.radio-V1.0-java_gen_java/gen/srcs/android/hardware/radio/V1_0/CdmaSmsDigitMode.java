package android.hardware.radio.V1_0;


public final class CdmaSmsDigitMode {
    public static final int FOUR_BIT = 0;
    public static final int EIGHT_BIT = 1 /* ::android::hardware::radio::V1_0::CdmaSmsDigitMode.FOUR_BIT implicitly + 1 */;
    public static final String toString(int o) {
        if (o == FOUR_BIT) {
            return "FOUR_BIT";
        }
        if (o == EIGHT_BIT) {
            return "EIGHT_BIT";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("FOUR_BIT"); // FOUR_BIT == 0
        if ((o & EIGHT_BIT) == EIGHT_BIT) {
            list.add("EIGHT_BIT");
            flipped |= EIGHT_BIT;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

