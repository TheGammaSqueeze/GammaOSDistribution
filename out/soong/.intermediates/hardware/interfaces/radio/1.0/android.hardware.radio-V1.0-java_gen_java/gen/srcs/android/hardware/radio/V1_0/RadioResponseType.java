package android.hardware.radio.V1_0;


public final class RadioResponseType {
    public static final int SOLICITED = 0;
    public static final int SOLICITED_ACK = 1 /* ::android::hardware::radio::V1_0::RadioResponseType.SOLICITED implicitly + 1 */;
    public static final int SOLICITED_ACK_EXP = 2 /* ::android::hardware::radio::V1_0::RadioResponseType.SOLICITED_ACK implicitly + 1 */;
    public static final String toString(int o) {
        if (o == SOLICITED) {
            return "SOLICITED";
        }
        if (o == SOLICITED_ACK) {
            return "SOLICITED_ACK";
        }
        if (o == SOLICITED_ACK_EXP) {
            return "SOLICITED_ACK_EXP";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("SOLICITED"); // SOLICITED == 0
        if ((o & SOLICITED_ACK) == SOLICITED_ACK) {
            list.add("SOLICITED_ACK");
            flipped |= SOLICITED_ACK;
        }
        if ((o & SOLICITED_ACK_EXP) == SOLICITED_ACK_EXP) {
            list.add("SOLICITED_ACK_EXP");
            flipped |= SOLICITED_ACK_EXP;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

