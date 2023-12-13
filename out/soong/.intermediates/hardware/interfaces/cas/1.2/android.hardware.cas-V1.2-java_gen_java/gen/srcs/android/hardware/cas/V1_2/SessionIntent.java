package android.hardware.cas.V1_2;


public final class SessionIntent {
    /**
     * Live Stream.
     */
    public static final int LIVE = 0;
    /**
     * Playback Recorded Stream.
     */
    public static final int PLAYBACK = 1 /* ::android::hardware::cas::V1_2::SessionIntent.LIVE implicitly + 1 */;
    /**
     * Record Live Stream.
     */
    public static final int RECORD = 2 /* ::android::hardware::cas::V1_2::SessionIntent.PLAYBACK implicitly + 1 */;
    /**
     * View the content with Time Shift capability
     */
    public static final int TIMESHIFT = 3 /* ::android::hardware::cas::V1_2::SessionIntent.RECORD implicitly + 1 */;
    public static final String toString(int o) {
        if (o == LIVE) {
            return "LIVE";
        }
        if (o == PLAYBACK) {
            return "PLAYBACK";
        }
        if (o == RECORD) {
            return "RECORD";
        }
        if (o == TIMESHIFT) {
            return "TIMESHIFT";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("LIVE"); // LIVE == 0
        if ((o & PLAYBACK) == PLAYBACK) {
            list.add("PLAYBACK");
            flipped |= PLAYBACK;
        }
        if ((o & RECORD) == RECORD) {
            list.add("RECORD");
            flipped |= RECORD;
        }
        if ((o & TIMESHIFT) == TIMESHIFT) {
            list.add("TIMESHIFT");
            flipped |= TIMESHIFT;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

