package android.hardware.radio.V1_0;


public final class HardwareConfigState {
    public static final int ENABLED = 0;
    public static final int STANDBY = 1 /* ::android::hardware::radio::V1_0::HardwareConfigState.ENABLED implicitly + 1 */;
    public static final int DISABLED = 2 /* ::android::hardware::radio::V1_0::HardwareConfigState.STANDBY implicitly + 1 */;
    public static final String toString(int o) {
        if (o == ENABLED) {
            return "ENABLED";
        }
        if (o == STANDBY) {
            return "STANDBY";
        }
        if (o == DISABLED) {
            return "DISABLED";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("ENABLED"); // ENABLED == 0
        if ((o & STANDBY) == STANDBY) {
            list.add("STANDBY");
            flipped |= STANDBY;
        }
        if ((o & DISABLED) == DISABLED) {
            list.add("DISABLED");
            flipped |= DISABLED;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

