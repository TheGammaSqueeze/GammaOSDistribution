package android.hardware.radio.V1_0;


public final class DeviceStateType {
    public static final int POWER_SAVE_MODE = 0;
    public static final int CHARGING_STATE = 1 /* ::android::hardware::radio::V1_0::DeviceStateType.POWER_SAVE_MODE implicitly + 1 */;
    public static final int LOW_DATA_EXPECTED = 2 /* ::android::hardware::radio::V1_0::DeviceStateType.CHARGING_STATE implicitly + 1 */;
    public static final String toString(int o) {
        if (o == POWER_SAVE_MODE) {
            return "POWER_SAVE_MODE";
        }
        if (o == CHARGING_STATE) {
            return "CHARGING_STATE";
        }
        if (o == LOW_DATA_EXPECTED) {
            return "LOW_DATA_EXPECTED";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("POWER_SAVE_MODE"); // POWER_SAVE_MODE == 0
        if ((o & CHARGING_STATE) == CHARGING_STATE) {
            list.add("CHARGING_STATE");
            flipped |= CHARGING_STATE;
        }
        if ((o & LOW_DATA_EXPECTED) == LOW_DATA_EXPECTED) {
            list.add("LOW_DATA_EXPECTED");
            flipped |= LOW_DATA_EXPECTED;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

