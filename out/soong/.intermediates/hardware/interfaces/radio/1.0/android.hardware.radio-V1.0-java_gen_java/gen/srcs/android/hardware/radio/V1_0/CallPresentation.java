package android.hardware.radio.V1_0;


public final class CallPresentation {
    public static final int ALLOWED = 0;
    public static final int RESTRICTED = 1 /* ::android::hardware::radio::V1_0::CallPresentation.ALLOWED implicitly + 1 */;
    public static final int UNKNOWN = 2 /* ::android::hardware::radio::V1_0::CallPresentation.RESTRICTED implicitly + 1 */;
    public static final int PAYPHONE = 3 /* ::android::hardware::radio::V1_0::CallPresentation.UNKNOWN implicitly + 1 */;
    public static final String toString(int o) {
        if (o == ALLOWED) {
            return "ALLOWED";
        }
        if (o == RESTRICTED) {
            return "RESTRICTED";
        }
        if (o == UNKNOWN) {
            return "UNKNOWN";
        }
        if (o == PAYPHONE) {
            return "PAYPHONE";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("ALLOWED"); // ALLOWED == 0
        if ((o & RESTRICTED) == RESTRICTED) {
            list.add("RESTRICTED");
            flipped |= RESTRICTED;
        }
        if ((o & UNKNOWN) == UNKNOWN) {
            list.add("UNKNOWN");
            flipped |= UNKNOWN;
        }
        if ((o & PAYPHONE) == PAYPHONE) {
            list.add("PAYPHONE");
            flipped |= PAYPHONE;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

