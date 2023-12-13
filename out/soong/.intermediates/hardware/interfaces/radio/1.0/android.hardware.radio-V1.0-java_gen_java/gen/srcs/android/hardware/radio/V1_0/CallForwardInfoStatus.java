package android.hardware.radio.V1_0;


public final class CallForwardInfoStatus {
    public static final int DISABLE = 0;
    public static final int ENABLE = 1 /* ::android::hardware::radio::V1_0::CallForwardInfoStatus.DISABLE implicitly + 1 */;
    public static final int INTERROGATE = 2 /* ::android::hardware::radio::V1_0::CallForwardInfoStatus.ENABLE implicitly + 1 */;
    public static final int REGISTRATION = 3 /* ::android::hardware::radio::V1_0::CallForwardInfoStatus.INTERROGATE implicitly + 1 */;
    public static final int ERASURE = 4 /* ::android::hardware::radio::V1_0::CallForwardInfoStatus.REGISTRATION implicitly + 1 */;
    public static final String toString(int o) {
        if (o == DISABLE) {
            return "DISABLE";
        }
        if (o == ENABLE) {
            return "ENABLE";
        }
        if (o == INTERROGATE) {
            return "INTERROGATE";
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
        list.add("DISABLE"); // DISABLE == 0
        if ((o & ENABLE) == ENABLE) {
            list.add("ENABLE");
            flipped |= ENABLE;
        }
        if ((o & INTERROGATE) == INTERROGATE) {
            list.add("INTERROGATE");
            flipped |= INTERROGATE;
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

