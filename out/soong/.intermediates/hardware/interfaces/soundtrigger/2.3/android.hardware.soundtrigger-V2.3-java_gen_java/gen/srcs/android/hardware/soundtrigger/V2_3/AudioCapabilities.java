package android.hardware.soundtrigger.V2_3;


public final class AudioCapabilities {
    /**
     * If set the underlying module supports AEC.
     */
    public static final int ECHO_CANCELLATION = 1 /* 1 << 0 */;
    /**
     * If set, the underlying module supports noise suppression.
     */
    public static final int NOISE_SUPPRESSION = 2 /* 1 << 1 */;
    public static final String toString(int o) {
        if (o == ECHO_CANCELLATION) {
            return "ECHO_CANCELLATION";
        }
        if (o == NOISE_SUPPRESSION) {
            return "NOISE_SUPPRESSION";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        if ((o & ECHO_CANCELLATION) == ECHO_CANCELLATION) {
            list.add("ECHO_CANCELLATION");
            flipped |= ECHO_CANCELLATION;
        }
        if ((o & NOISE_SUPPRESSION) == NOISE_SUPPRESSION) {
            list.add("NOISE_SUPPRESSION");
            flipped |= NOISE_SUPPRESSION;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

