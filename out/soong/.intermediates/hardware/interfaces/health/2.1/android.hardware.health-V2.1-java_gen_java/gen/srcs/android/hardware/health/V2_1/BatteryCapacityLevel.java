package android.hardware.health.V2_1;


public final class BatteryCapacityLevel {
    /**
     * Battery capacity level is unsupported.
     * Battery capacity level must be set to this value if and only if the
     * implementation is unsupported.
     */
    public static final int UNSUPPORTED = -1 /* -1 */;
    /**
     * Battery capacity level is unknown.
     * Battery capacity level must be set to this value if and only if battery
     * is not present or the battery capacity level is unknown/uninitialized.
     */
    public static final int UNKNOWN = 0 /* ::android::hardware::health::V2_1::BatteryCapacityLevel.UNSUPPORTED implicitly + 1 */;
    /**
     * Battery is at critical level. The Android framework must schedule a
     * shutdown when it sees this value from the HAL.
     */
    public static final int CRITICAL = 1 /* ::android::hardware::health::V2_1::BatteryCapacityLevel.UNKNOWN implicitly + 1 */;
    /**
     * Battery is low. The Android framework may limit the performance of
     * the device when it sees this value from the HAL.
     */
    public static final int LOW = 2 /* ::android::hardware::health::V2_1::BatteryCapacityLevel.CRITICAL implicitly + 1 */;
    /**
     * Battery level is normal.
     */
    public static final int NORMAL = 3 /* ::android::hardware::health::V2_1::BatteryCapacityLevel.LOW implicitly + 1 */;
    /**
     * Battery level is high.
     */
    public static final int HIGH = 4 /* ::android::hardware::health::V2_1::BatteryCapacityLevel.NORMAL implicitly + 1 */;
    /**
     * Battery is full. It must be set to FULL if and only if battery level is
     * 100.
     */
    public static final int FULL = 5 /* ::android::hardware::health::V2_1::BatteryCapacityLevel.HIGH implicitly + 1 */;
    public static final String toString(int o) {
        if (o == UNSUPPORTED) {
            return "UNSUPPORTED";
        }
        if (o == UNKNOWN) {
            return "UNKNOWN";
        }
        if (o == CRITICAL) {
            return "CRITICAL";
        }
        if (o == LOW) {
            return "LOW";
        }
        if (o == NORMAL) {
            return "NORMAL";
        }
        if (o == HIGH) {
            return "HIGH";
        }
        if (o == FULL) {
            return "FULL";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        if ((o & UNSUPPORTED) == UNSUPPORTED) {
            list.add("UNSUPPORTED");
            flipped |= UNSUPPORTED;
        }
        list.add("UNKNOWN"); // UNKNOWN == 0
        if ((o & CRITICAL) == CRITICAL) {
            list.add("CRITICAL");
            flipped |= CRITICAL;
        }
        if ((o & LOW) == LOW) {
            list.add("LOW");
            flipped |= LOW;
        }
        if ((o & NORMAL) == NORMAL) {
            list.add("NORMAL");
            flipped |= NORMAL;
        }
        if ((o & HIGH) == HIGH) {
            list.add("HIGH");
            flipped |= HIGH;
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

