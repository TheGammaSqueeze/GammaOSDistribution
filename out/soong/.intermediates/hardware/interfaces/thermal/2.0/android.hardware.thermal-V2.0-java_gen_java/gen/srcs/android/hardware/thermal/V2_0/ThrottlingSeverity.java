package android.hardware.thermal.V2_0;


public final class ThrottlingSeverity {
    /**
     * Not under throttling.
     */
    public static final int NONE = 0;
    /**
     * Light throttling where UX is not impacted.
     */
    public static final int LIGHT = 1 /* ::android::hardware::thermal::V2_0::ThrottlingSeverity.NONE implicitly + 1 */;
    /**
     * Moderate throttling where UX is not largely impacted.
     */
    public static final int MODERATE = 2 /* ::android::hardware::thermal::V2_0::ThrottlingSeverity.LIGHT implicitly + 1 */;
    /**
     * Severe throttling where UX is largely impacted.
     * Similar to 1.0 throttlingThreshold.
     */
    public static final int SEVERE = 3 /* ::android::hardware::thermal::V2_0::ThrottlingSeverity.MODERATE implicitly + 1 */;
    /**
     * Platform has done everything to reduce power.
     */
    public static final int CRITICAL = 4 /* ::android::hardware::thermal::V2_0::ThrottlingSeverity.SEVERE implicitly + 1 */;
    /**
     * Key components in platform are shutting down due to thermal condition.
     * Device functionalities will be limited.
     */
    public static final int EMERGENCY = 5 /* ::android::hardware::thermal::V2_0::ThrottlingSeverity.CRITICAL implicitly + 1 */;
    /**
     * Need shutdown immediately.
     */
    public static final int SHUTDOWN = 6 /* ::android::hardware::thermal::V2_0::ThrottlingSeverity.EMERGENCY implicitly + 1 */;
    public static final String toString(int o) {
        if (o == NONE) {
            return "NONE";
        }
        if (o == LIGHT) {
            return "LIGHT";
        }
        if (o == MODERATE) {
            return "MODERATE";
        }
        if (o == SEVERE) {
            return "SEVERE";
        }
        if (o == CRITICAL) {
            return "CRITICAL";
        }
        if (o == EMERGENCY) {
            return "EMERGENCY";
        }
        if (o == SHUTDOWN) {
            return "SHUTDOWN";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("NONE"); // NONE == 0
        if ((o & LIGHT) == LIGHT) {
            list.add("LIGHT");
            flipped |= LIGHT;
        }
        if ((o & MODERATE) == MODERATE) {
            list.add("MODERATE");
            flipped |= MODERATE;
        }
        if ((o & SEVERE) == SEVERE) {
            list.add("SEVERE");
            flipped |= SEVERE;
        }
        if ((o & CRITICAL) == CRITICAL) {
            list.add("CRITICAL");
            flipped |= CRITICAL;
        }
        if ((o & EMERGENCY) == EMERGENCY) {
            list.add("EMERGENCY");
            flipped |= EMERGENCY;
        }
        if ((o & SHUTDOWN) == SHUTDOWN) {
            list.add("SHUTDOWN");
            flipped |= SHUTDOWN;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

