package android.hardware.power.V1_0;


public final class Feature {
    /**
     * Enabling/Disabling this feature will allow/disallow the system
     * to wake up by tapping the screen twice.
     */
    public static final int POWER_FEATURE_DOUBLE_TAP_TO_WAKE = 1 /* 0x00000001 */;
    public static final String toString(int o) {
        if (o == POWER_FEATURE_DOUBLE_TAP_TO_WAKE) {
            return "POWER_FEATURE_DOUBLE_TAP_TO_WAKE";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        if ((o & POWER_FEATURE_DOUBLE_TAP_TO_WAKE) == POWER_FEATURE_DOUBLE_TAP_TO_WAKE) {
            list.add("POWER_FEATURE_DOUBLE_TAP_TO_WAKE");
            flipped |= POWER_FEATURE_DOUBLE_TAP_TO_WAKE;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

