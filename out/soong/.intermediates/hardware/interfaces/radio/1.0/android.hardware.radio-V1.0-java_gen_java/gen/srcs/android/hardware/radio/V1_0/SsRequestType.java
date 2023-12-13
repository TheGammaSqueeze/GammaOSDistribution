package android.hardware.radio.V1_0;


public final class SsRequestType {
    public static final int ACTIVATION = 0;
    public static final int DEACTIVATION = 1 /* ::android::hardware::radio::V1_0::SsRequestType.ACTIVATION implicitly + 1 */;
    public static final int INTERROGATION = 2 /* ::android::hardware::radio::V1_0::SsRequestType.DEACTIVATION implicitly + 1 */;
    public static final int REGISTRATION = 3 /* ::android::hardware::radio::V1_0::SsRequestType.INTERROGATION implicitly + 1 */;
    public static final int ERASURE = 4 /* ::android::hardware::radio::V1_0::SsRequestType.REGISTRATION implicitly + 1 */;
    public static final String toString(int o) {
        if (o == ACTIVATION) {
            return "ACTIVATION";
        }
        if (o == DEACTIVATION) {
            return "DEACTIVATION";
        }
        if (o == INTERROGATION) {
            return "INTERROGATION";
        }
        if (o == REGISTRATION) {
            return "REGISTRATION";
        }
        if (o == ERASURE) {
            return "ERASURE";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("ACTIVATION"); // ACTIVATION == 0
        if ((o & DEACTIVATION) == DEACTIVATION) {
            list.add("DEACTIVATION");
            flipped |= DEACTIVATION;
        }
        if ((o & INTERROGATION) == INTERROGATION) {
            list.add("INTERROGATION");
            flipped |= INTERROGATION;
        }
        if ((o & REGISTRATION) == REGISTRATION) {
            list.add("REGISTRATION");
            flipped |= REGISTRATION;
        }
        if ((o & ERASURE) == ERASURE) {
            list.add("ERASURE");
            flipped |= ERASURE;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

