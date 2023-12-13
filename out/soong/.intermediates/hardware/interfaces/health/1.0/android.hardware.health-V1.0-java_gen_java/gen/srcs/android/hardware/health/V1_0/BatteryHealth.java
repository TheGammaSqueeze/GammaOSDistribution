package android.hardware.health.V1_0;


public final class BatteryHealth {
    public static final int UNKNOWN = 1;
    public static final int GOOD = 2;
    public static final int OVERHEAT = 3;
    public static final int DEAD = 4;
    public static final int OVER_VOLTAGE = 5;
    /**
     * Battery experienced an unknown/unspecifid failure.
     */
    public static final int UNSPECIFIED_FAILURE = 6;
    public static final int COLD = 7;
    public static final String toString(int o) {
        if (o == UNKNOWN) {
            return "UNKNOWN";
        }
        if (o == GOOD) {
            return "GOOD";
        }
        if (o == OVERHEAT) {
            return "OVERHEAT";
        }
        if (o == DEAD) {
            return "DEAD";
        }
        if (o == OVER_VOLTAGE) {
            return "OVER_VOLTAGE";
        }
        if (o == UNSPECIFIED_FAILURE) {
            return "UNSPECIFIED_FAILURE";
        }
        if (o == COLD) {
            return "COLD";
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
        if ((o & GOOD) == GOOD) {
            list.add("GOOD");
            flipped |= GOOD;
        }
        if ((o & OVERHEAT) == OVERHEAT) {
            list.add("OVERHEAT");
            flipped |= OVERHEAT;
        }
        if ((o & DEAD) == DEAD) {
            list.add("DEAD");
            flipped |= DEAD;
        }
        if ((o & OVER_VOLTAGE) == OVER_VOLTAGE) {
            list.add("OVER_VOLTAGE");
            flipped |= OVER_VOLTAGE;
        }
        if ((o & UNSPECIFIED_FAILURE) == UNSPECIFIED_FAILURE) {
            list.add("UNSPECIFIED_FAILURE");
            flipped |= UNSPECIFIED_FAILURE;
        }
        if ((o & COLD) == COLD) {
            list.add("COLD");
            flipped |= COLD;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

