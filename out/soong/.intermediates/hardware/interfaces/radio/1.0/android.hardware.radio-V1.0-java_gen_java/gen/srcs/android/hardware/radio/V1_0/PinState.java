package android.hardware.radio.V1_0;


public final class PinState {
    public static final int UNKNOWN = 0;
    public static final int ENABLED_NOT_VERIFIED = 1 /* ::android::hardware::radio::V1_0::PinState.UNKNOWN implicitly + 1 */;
    public static final int ENABLED_VERIFIED = 2 /* ::android::hardware::radio::V1_0::PinState.ENABLED_NOT_VERIFIED implicitly + 1 */;
    public static final int DISABLED = 3 /* ::android::hardware::radio::V1_0::PinState.ENABLED_VERIFIED implicitly + 1 */;
    public static final int ENABLED_BLOCKED = 4 /* ::android::hardware::radio::V1_0::PinState.DISABLED implicitly + 1 */;
    public static final int ENABLED_PERM_BLOCKED = 5 /* ::android::hardware::radio::V1_0::PinState.ENABLED_BLOCKED implicitly + 1 */;
    public static final String toString(int o) {
        if (o == UNKNOWN) {
            return "UNKNOWN";
        }
        if (o == ENABLED_NOT_VERIFIED) {
            return "ENABLED_NOT_VERIFIED";
        }
        if (o == ENABLED_VERIFIED) {
            return "ENABLED_VERIFIED";
        }
        if (o == DISABLED) {
            return "DISABLED";
        }
        if (o == ENABLED_BLOCKED) {
            return "ENABLED_BLOCKED";
        }
        if (o == ENABLED_PERM_BLOCKED) {
            return "ENABLED_PERM_BLOCKED";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("UNKNOWN"); // UNKNOWN == 0
        if ((o & ENABLED_NOT_VERIFIED) == ENABLED_NOT_VERIFIED) {
            list.add("ENABLED_NOT_VERIFIED");
            flipped |= ENABLED_NOT_VERIFIED;
        }
        if ((o & ENABLED_VERIFIED) == ENABLED_VERIFIED) {
            list.add("ENABLED_VERIFIED");
            flipped |= ENABLED_VERIFIED;
        }
        if ((o & DISABLED) == DISABLED) {
            list.add("DISABLED");
            flipped |= DISABLED;
        }
        if ((o & ENABLED_BLOCKED) == ENABLED_BLOCKED) {
            list.add("ENABLED_BLOCKED");
            flipped |= ENABLED_BLOCKED;
        }
        if ((o & ENABLED_PERM_BLOCKED) == ENABLED_PERM_BLOCKED) {
            list.add("ENABLED_PERM_BLOCKED");
            flipped |= ENABLED_PERM_BLOCKED;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

