package android.hardware.wifi.supplicant.V1_3;


public final class DppSuccessCode {
    /*
     * Replaces @1.2::onDppSuccessConfigSent()
     */
    public static final int CONFIGURATION_SENT = 0;
    public static final int CONFIGURATION_APPLIED = 1 /* ::android::hardware::wifi::supplicant::V1_3::DppSuccessCode.CONFIGURATION_SENT implicitly + 1 */;
    public static final String toString(int o) {
        if (o == CONFIGURATION_SENT) {
            return "CONFIGURATION_SENT";
        }
        if (o == CONFIGURATION_APPLIED) {
            return "CONFIGURATION_APPLIED";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("CONFIGURATION_SENT"); // CONFIGURATION_SENT == 0
        if ((o & CONFIGURATION_APPLIED) == CONFIGURATION_APPLIED) {
            list.add("CONFIGURATION_APPLIED");
            flipped |= CONFIGURATION_APPLIED;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

