package android.hardware.wifi.V1_0;


public final class NanPublishType {
    public static final int UNSOLICITED = 0;
    public static final int SOLICITED = 1 /* ::android::hardware::wifi::V1_0::NanPublishType.UNSOLICITED implicitly + 1 */;
    public static final int UNSOLICITED_SOLICITED = 2 /* ::android::hardware::wifi::V1_0::NanPublishType.SOLICITED implicitly + 1 */;
    public static final String toString(int o) {
        if (o == UNSOLICITED) {
            return "UNSOLICITED";
        }
        if (o == SOLICITED) {
            return "SOLICITED";
        }
        if (o == UNSOLICITED_SOLICITED) {
            return "UNSOLICITED_SOLICITED";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("UNSOLICITED"); // UNSOLICITED == 0
        if ((o & SOLICITED) == SOLICITED) {
            list.add("SOLICITED");
            flipped |= SOLICITED;
        }
        if ((o & UNSOLICITED_SOLICITED) == UNSOLICITED_SOLICITED) {
            list.add("UNSOLICITED_SOLICITED");
            flipped |= UNSOLICITED_SOLICITED;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

