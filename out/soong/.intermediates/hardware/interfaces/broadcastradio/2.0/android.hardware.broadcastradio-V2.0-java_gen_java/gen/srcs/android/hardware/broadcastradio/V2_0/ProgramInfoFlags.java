package android.hardware.broadcastradio.V2_0;


public final class ProgramInfoFlags {
    /**
     * Set when the program is currently playing live stream.
     * This may result in a slightly altered reception parameters,
     * usually targetted at reduced latency.
     */
    public static final int LIVE = 1 /* 1 << 0 */;
    /**
     * Radio stream is not playing, ie. due to bad reception conditions or
     * buffering. In this state volume knob MAY be disabled to prevent user
     * increasing volume too much.
     */
    public static final int MUTED = 2 /* 1 << 1 */;
    /**
     * Station broadcasts traffic information regularly,
     * but not necessarily right now.
     */
    public static final int TRAFFIC_PROGRAM = 4 /* 1 << 2 */;
    /**
     * Station is broadcasting traffic information at the very moment.
     */
    public static final int TRAFFIC_ANNOUNCEMENT = 8 /* 1 << 3 */;
    /**
     * Tuned to a program (not playing static).
     *
     * It's the same condition that would stop a seek operation
     * (ie: ITunerSession::scan()).
     *
     * By definition, this flag must be set for all items on the program list.
     */
    public static final int TUNED = 16 /* 1 << 4 */;
    /**
     * Audio stream is MONO if this bit is not set.
     */
    public static final int STEREO = 32 /* 1 << 5 */;
    public static final String toString(int o) {
        if (o == LIVE) {
            return "LIVE";
        }
        if (o == MUTED) {
            return "MUTED";
        }
        if (o == TRAFFIC_PROGRAM) {
            return "TRAFFIC_PROGRAM";
        }
        if (o == TRAFFIC_ANNOUNCEMENT) {
            return "TRAFFIC_ANNOUNCEMENT";
        }
        if (o == TUNED) {
            return "TUNED";
        }
        if (o == STEREO) {
            return "STEREO";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        if ((o & LIVE) == LIVE) {
            list.add("LIVE");
            flipped |= LIVE;
        }
        if ((o & MUTED) == MUTED) {
            list.add("MUTED");
            flipped |= MUTED;
        }
        if ((o & TRAFFIC_PROGRAM) == TRAFFIC_PROGRAM) {
            list.add("TRAFFIC_PROGRAM");
            flipped |= TRAFFIC_PROGRAM;
        }
        if ((o & TRAFFIC_ANNOUNCEMENT) == TRAFFIC_ANNOUNCEMENT) {
            list.add("TRAFFIC_ANNOUNCEMENT");
            flipped |= TRAFFIC_ANNOUNCEMENT;
        }
        if ((o & TUNED) == TUNED) {
            list.add("TUNED");
            flipped |= TUNED;
        }
        if ((o & STEREO) == STEREO) {
            list.add("STEREO");
            flipped |= STEREO;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

