package android.hardware.radio.V1_0;


public final class RadioIndicationType {
    public static final int UNSOLICITED = 0;
    public static final int UNSOLICITED_ACK_EXP = 1 /* ::android::hardware::radio::V1_0::RadioIndicationType.UNSOLICITED implicitly + 1 */;
    public static final String toString(int o) {
        if (o == UNSOLICITED) {
            return "UNSOLICITED";
        }
        if (o == UNSOLICITED_ACK_EXP) {
            return "UNSOLICITED_ACK_EXP";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("UNSOLICITED"); // UNSOLICITED == 0
        if ((o & UNSOLICITED_ACK_EXP) == UNSOLICITED_ACK_EXP) {
            list.add("UNSOLICITED_ACK_EXP");
            flipped |= UNSOLICITED_ACK_EXP;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

