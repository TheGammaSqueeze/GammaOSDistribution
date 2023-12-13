package android.hardware.health.V2_1;


public final class Constants {
    public static final long BATTERY_CHARGE_TIME_TO_FULL_NOW_SECONDS_UNSUPPORTED = -1L /* -1 */;
    public static final String toString(long o) {
        if (o == BATTERY_CHARGE_TIME_TO_FULL_NOW_SECONDS_UNSUPPORTED) {
            return "BATTERY_CHARGE_TIME_TO_FULL_NOW_SECONDS_UNSUPPORTED";
        }
        return "0x" + Long.toHexString(o);
    }

    public static final String dumpBitfield(long o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        long flipped = 0;
        if ((o & BATTERY_CHARGE_TIME_TO_FULL_NOW_SECONDS_UNSUPPORTED) == BATTERY_CHARGE_TIME_TO_FULL_NOW_SECONDS_UNSUPPORTED) {
            list.add("BATTERY_CHARGE_TIME_TO_FULL_NOW_SECONDS_UNSUPPORTED");
            flipped |= BATTERY_CHARGE_TIME_TO_FULL_NOW_SECONDS_UNSUPPORTED;
        }
        if (o != flipped) {
            list.add("0x" + Long.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

