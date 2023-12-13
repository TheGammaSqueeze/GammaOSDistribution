package android.hardware.light.V2_0;


public final class Brightness {
    /**
     * Light brightness is managed by a user setting.
     */
    public static final int USER = 0;
    /**
     * Light brightness is managed by a light sensor.
     */
    public static final int SENSOR = 1 /* ::android::hardware::light::V2_0::Brightness.USER implicitly + 1 */;
    /**
     * Use a low-persistence mode for display backlights.
     *
     * When set, the device driver must switch to a mode optimized for low display
     * persistence that is intended to be used when the device is being treated as a
     * head mounted display (HMD). The actual display brightness in this mode is
     * implementation dependent, and any value set for color in LightState may be
     * overridden by the HAL implementation.
     *
     * For an optimal HMD viewing experience, the display must meet the following
     * criteria in this mode:
     * - Gray-to-Gray, White-to-Black, and Black-to-White switching time must be ≤ 3 ms.
     * - The display must support low-persistence with ≤ 3.5 ms persistence.
     *   Persistence is defined as the amount of time for which a pixel is
     *   emitting light for a single frame.
     * - Any "smart panel" or other frame buffering options that increase display
     *   latency are disabled.
     * - Display brightness is set so that the display is still visible to the user
     *   under normal indoor lighting.
     * - The display must update at 60 Hz at least, but higher refresh rates are
     *   recommended for low latency.
     *
     */
    public static final int LOW_PERSISTENCE = 2 /* ::android::hardware::light::V2_0::Brightness.SENSOR implicitly + 1 */;
    public static final String toString(int o) {
        if (o == USER) {
            return "USER";
        }
        if (o == SENSOR) {
            return "SENSOR";
        }
        if (o == LOW_PERSISTENCE) {
            return "LOW_PERSISTENCE";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("USER"); // USER == 0
        if ((o & SENSOR) == SENSOR) {
            list.add("SENSOR");
            flipped |= SENSOR;
        }
        if ((o & LOW_PERSISTENCE) == LOW_PERSISTENCE) {
            list.add("LOW_PERSISTENCE");
            flipped |= LOW_PERSISTENCE;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

