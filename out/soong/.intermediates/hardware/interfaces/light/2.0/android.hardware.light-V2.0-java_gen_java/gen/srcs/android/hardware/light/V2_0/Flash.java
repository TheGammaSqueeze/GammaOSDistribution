package android.hardware.light.V2_0;


public final class Flash {
    /**
     * Keep the light steady on or off.
     */
    public static final int NONE = 0;
    /**
     * Flash the light at specified rate.
     */
    public static final int TIMED = 1 /* ::android::hardware::light::V2_0::Flash.NONE implicitly + 1 */;
    /**
     * Flash the light using hardware assist.
     */
    public static final int HARDWARE = 2 /* ::android::hardware::light::V2_0::Flash.TIMED implicitly + 1 */;
    public static final String toString(int o) {
        if (o == NONE) {
            return "NONE";
        }
        if (o == TIMED) {
            return "TIMED";
        }
        if (o == HARDWARE) {
            return "HARDWARE";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("NONE"); // NONE == 0
        if ((o & TIMED) == TIMED) {
            list.add("TIMED");
            flipped |= TIMED;
        }
        if ((o & HARDWARE) == HARDWARE) {
            list.add("HARDWARE");
            flipped |= HARDWARE;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

