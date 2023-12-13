package android.hardware.audio.common.V2_0;


public final class AudioSessionConsts {
    /**
     * Session for effects attached to a particular output stream
     * (value must be less than 0)
     */
    public static final int OUTPUT_STAGE = -1 /* -1 */;
    /**
     * Session for effects applied to output mix. These effects can
     * be moved by audio policy manager to another output stream
     * (value must be 0)
     */
    public static final int OUTPUT_MIX = 0;
    /**
     * Application does not specify an explicit session ID to be used, and
     * requests a new session ID to be allocated. Corresponds to
     * AudioManager.AUDIO_SESSION_ID_GENERATE and
     * AudioSystem.AUDIO_SESSION_ALLOCATE.
     */
    public static final int ALLOCATE = 0;
    /**
     * For use with AudioRecord::start(), this indicates no trigger session.
     * It is also used with output tracks and patch tracks, which never have a
     * session.
     */
    public static final int NONE = 0;
    public static final String toString(int o) {
        if (o == OUTPUT_STAGE) {
            return "OUTPUT_STAGE";
        }
        if (o == OUTPUT_MIX) {
            return "OUTPUT_MIX";
        }
        if (o == ALLOCATE) {
            return "ALLOCATE";
        }
        if (o == NONE) {
            return "NONE";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        if ((o & OUTPUT_STAGE) == OUTPUT_STAGE) {
            list.add("OUTPUT_STAGE");
            flipped |= OUTPUT_STAGE;
        }
        list.add("OUTPUT_MIX"); // OUTPUT_MIX == 0
        list.add("ALLOCATE"); // ALLOCATE == 0
        list.add("NONE"); // NONE == 0
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

