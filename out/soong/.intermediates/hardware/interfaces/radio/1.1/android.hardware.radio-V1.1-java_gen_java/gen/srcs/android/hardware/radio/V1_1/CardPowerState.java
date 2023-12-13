package android.hardware.radio.V1_1;


public final class CardPowerState {
    public static final int POWER_DOWN = 0;
    public static final int POWER_UP = 1 /* ::android::hardware::radio::V1_1::CardPowerState.POWER_DOWN implicitly + 1 */;
    public static final int POWER_UP_PASS_THROUGH = 2 /* ::android::hardware::radio::V1_1::CardPowerState.POWER_UP implicitly + 1 */;
    public static final String toString(int o) {
        if (o == POWER_DOWN) {
            return "POWER_DOWN";
        }
        if (o == POWER_UP) {
            return "POWER_UP";
        }
        if (o == POWER_UP_PASS_THROUGH) {
            return "POWER_UP_PASS_THROUGH";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("POWER_DOWN"); // POWER_DOWN == 0
        if ((o & POWER_UP) == POWER_UP) {
            list.add("POWER_UP");
            flipped |= POWER_UP;
        }
        if ((o & POWER_UP_PASS_THROUGH) == POWER_UP_PASS_THROUGH) {
            list.add("POWER_UP_PASS_THROUGH");
            flipped |= POWER_UP_PASS_THROUGH;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

