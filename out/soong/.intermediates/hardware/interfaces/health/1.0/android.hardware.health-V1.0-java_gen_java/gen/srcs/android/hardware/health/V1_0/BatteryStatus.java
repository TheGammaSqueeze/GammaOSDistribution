package android.hardware.health.V1_0;


public final class BatteryStatus {
    public static final int UNKNOWN = 1;
    public static final int CHARGING = 2;
    public static final int DISCHARGING = 3;
    /**
     * Battery is *not* charging - special case when charger is present
     * but battery isn't charging
     */
    public static final int NOT_CHARGING = 4;
    public static final int FULL = 5;
    public static final String toString(int o) {
        if (o == UNKNOWN) {
            return "UNKNOWN";
        }
        if (o == CHARGING) {
            return "CHARGING";
        }
        if (o == DISCHARGING) {
            return "DISCHARGING";
        }
        if (o == NOT_CHARGING) {
            return "NOT_CHARGING";
        }
        if (o == FULL) {
            return "FULL";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        if ((o & UNKNOWN) == UNKNOWN) {
            list.add("UNKNOWN");
            flipped |= UNKNOWN;
        }
        if ((o & CHARGING) == CHARGING) {
            list.add("CHARGING");
            flipped |= CHARGING;
        }
        if ((o & DISCHARGING) == DISCHARGING) {
            list.add("DISCHARGING");
            flipped |= DISCHARGING;
        }
        if ((o & NOT_CHARGING) == NOT_CHARGING) {
            list.add("NOT_CHARGING");
            flipped |= NOT_CHARGING;
        }
        if ((o & FULL) == FULL) {
            list.add("FULL");
            flipped |= FULL;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

