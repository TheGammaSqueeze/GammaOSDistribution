package android.hardware.power.V1_0;


public final class PowerHint {
    /**
     * Foreground app has started or stopped requesting a VSYNC pulse
     * from SurfaceFlinger. If the app has started requesting VSYNC
     * then CPU and GPU load is expected soon, and it may be appropriate
     * to raise speeds of CPU, memory bus, etc. The data parameter is
     * non-zero to indicate VSYNC pulse is now requested, or zero for
     * VSYNC pulse no longer requested.
     */
    public static final int VSYNC = 1 /* 0x00000001 */;
    /**
     * User is interacting with the device, for example, touchscreen
     * events are incoming. CPU and GPU load may be expected soon,
     * and it may be appropriate to raise speeds of CPU, memory bus,
     * etc. The data parameter is the estimated length of the interaction
     * in milliseconds, or 0 if unknown.
     */
    public static final int INTERACTION = 2 /* 0x00000002 */;
    /**
     * DO NOT USE VIDEO_ENCODE/_DECODE!  They will be removed in
     * KLP.
     */
    public static final int VIDEO_ENCODE = 3 /* 0x00000003 */;
    public static final int VIDEO_DECODE = 4 /* 0x00000004 */;
    /**
     * Low power mode is activated or deactivated. Low power mode
     * is intended to save battery at the cost of performance. The data
     * parameter is non-zero when low power mode is activated, and zero
     * when deactivated.
     */
    public static final int LOW_POWER = 5 /* 0x00000005 */;
    /**
     * Sustained Performance mode is actived or deactivated. Sustained
     * performance mode is intended to provide a consistent level of
     * performance for a prolonged amount of time. The data parameter is
     * non-zero when sustained performance mode is activated, and zero
     * when deactivated.
     */
    public static final int SUSTAINED_PERFORMANCE = 6 /* 0x00000006 */;
    /**
     * VR Mode is activated or deactivated. VR mode is intended to
     * provide minimum guarantee for performance for the amount of time the
     * device can sustain it. The data parameter is non-zero when the mode
     * is activated and zero when deactivated.
     */
    public static final int VR_MODE = 7 /* 0x00000007 */;
    /**
     * This hint indicates that an application has been launched. Can be used
     * for device specific optimizations during application launch. The data
     * parameter is non-zero when the application starts to launch and zero when
     * it has been launched.
     */
    public static final int LAUNCH = 8 /* 0x00000008 */;
    public static final String toString(int o) {
        if (o == VSYNC) {
            return "VSYNC";
        }
        if (o == INTERACTION) {
            return "INTERACTION";
        }
        if (o == VIDEO_ENCODE) {
            return "VIDEO_ENCODE";
        }
        if (o == VIDEO_DECODE) {
            return "VIDEO_DECODE";
        }
        if (o == LOW_POWER) {
            return "LOW_POWER";
        }
        if (o == SUSTAINED_PERFORMANCE) {
            return "SUSTAINED_PERFORMANCE";
        }
        if (o == VR_MODE) {
            return "VR_MODE";
        }
        if (o == LAUNCH) {
            return "LAUNCH";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        if ((o & VSYNC) == VSYNC) {
            list.add("VSYNC");
            flipped |= VSYNC;
        }
        if ((o & INTERACTION) == INTERACTION) {
            list.add("INTERACTION");
            flipped |= INTERACTION;
        }
        if ((o & VIDEO_ENCODE) == VIDEO_ENCODE) {
            list.add("VIDEO_ENCODE");
            flipped |= VIDEO_ENCODE;
        }
        if ((o & VIDEO_DECODE) == VIDEO_DECODE) {
            list.add("VIDEO_DECODE");
            flipped |= VIDEO_DECODE;
        }
        if ((o & LOW_POWER) == LOW_POWER) {
            list.add("LOW_POWER");
            flipped |= LOW_POWER;
        }
        if ((o & SUSTAINED_PERFORMANCE) == SUSTAINED_PERFORMANCE) {
            list.add("SUSTAINED_PERFORMANCE");
            flipped |= SUSTAINED_PERFORMANCE;
        }
        if ((o & VR_MODE) == VR_MODE) {
            list.add("VR_MODE");
            flipped |= VR_MODE;
        }
        if ((o & LAUNCH) == LAUNCH) {
            list.add("LAUNCH");
            flipped |= LAUNCH;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

