package android.hardware.radio.V1_0;


public final class CdmaSmsSubaddressType {
    public static final int NSAP = 0;
    public static final int USER_SPECIFIED = 1 /* ::android::hardware::radio::V1_0::CdmaSmsSubaddressType.NSAP implicitly + 1 */;
    public static final String toString(int o) {
        if (o == NSAP) {
            return "NSAP";
        }
        if (o == USER_SPECIFIED) {
            return "USER_SPECIFIED";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("NSAP"); // NSAP == 0
        if ((o & USER_SPECIFIED) == USER_SPECIFIED) {
            list.add("USER_SPECIFIED");
            flipped |= USER_SPECIFIED;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

