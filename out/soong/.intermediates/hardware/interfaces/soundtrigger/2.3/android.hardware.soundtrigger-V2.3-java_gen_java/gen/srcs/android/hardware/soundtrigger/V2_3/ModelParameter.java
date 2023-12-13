package android.hardware.soundtrigger.V2_3;


public final class ModelParameter {
    /**
     * Placeholder for invalid model parameter used for returning error or
     * passing an invalid value.
     */
    public static final int INVALID = -1 /* -1 */;
    /**
     * Controls the sensitivity threshold adjustment factor for a given model.
     * Negative value corresponds to less sensitive model (high threshold) and
     * a positive value corresponds to a more sensitive model (low threshold).
     * Default value is 0.
     */
    public static final int THRESHOLD_FACTOR = 0;
    public static final String toString(int o) {
        if (o == INVALID) {
            return "INVALID";
        }
        if (o == THRESHOLD_FACTOR) {
            return "THRESHOLD_FACTOR";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        if ((o & INVALID) == INVALID) {
            list.add("INVALID");
            flipped |= INVALID;
        }
        list.add("THRESHOLD_FACTOR"); // THRESHOLD_FACTOR == 0
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

