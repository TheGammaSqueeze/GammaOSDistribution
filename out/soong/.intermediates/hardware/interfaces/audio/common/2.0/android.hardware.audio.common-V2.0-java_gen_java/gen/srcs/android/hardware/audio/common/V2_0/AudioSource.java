package android.hardware.audio.common.V2_0;


public final class AudioSource {
    public static final int DEFAULT = 0;
    public static final int MIC = 1;
    public static final int VOICE_UPLINK = 2;
    public static final int VOICE_DOWNLINK = 3;
    public static final int VOICE_CALL = 4;
    public static final int CAMCORDER = 5;
    public static final int VOICE_RECOGNITION = 6;
    public static final int VOICE_COMMUNICATION = 7;
    /**
     * Source for the mix to be presented remotely. An example of remote
     * presentation is Wifi Display where a dongle attached to a TV can be used
     * to play the mix captured by this audio source.
     */
    public static final int REMOTE_SUBMIX = 8;
    /**
     * Source for unprocessed sound. Usage examples include level measurement
     * and raw signal analysis.
     */
    public static final int UNPROCESSED = 9;
    public static final int CNT = 10 /* ::android::hardware::audio::common::V2_0::AudioSource.UNPROCESSED implicitly + 1 */;
    public static final int MAX = 9 /* CNT - 1 */;
    public static final int FM_TUNER = 1998;
    /**
     * A low-priority, preemptible audio source for for background software
     * hotword detection. Same tuning as VOICE_RECOGNITION.  Used only
     * internally by the framework.
     */
    public static final int HOTWORD = 1999;
    public static final String toString(int o) {
        if (o == DEFAULT) {
            return "DEFAULT";
        }
        if (o == MIC) {
            return "MIC";
        }
        if (o == VOICE_UPLINK) {
            return "VOICE_UPLINK";
        }
        if (o == VOICE_DOWNLINK) {
            return "VOICE_DOWNLINK";
        }
        if (o == VOICE_CALL) {
            return "VOICE_CALL";
        }
        if (o == CAMCORDER) {
            return "CAMCORDER";
        }
        if (o == VOICE_RECOGNITION) {
            return "VOICE_RECOGNITION";
        }
        if (o == VOICE_COMMUNICATION) {
            return "VOICE_COMMUNICATION";
        }
        if (o == REMOTE_SUBMIX) {
            return "REMOTE_SUBMIX";
        }
        if (o == UNPROCESSED) {
            return "UNPROCESSED";
        }
        if (o == CNT) {
            return "CNT";
        }
        if (o == MAX) {
            return "MAX";
        }
        if (o == FM_TUNER) {
            return "FM_TUNER";
        }
        if (o == HOTWORD) {
            return "HOTWORD";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("DEFAULT"); // DEFAULT == 0
        if ((o & MIC) == MIC) {
            list.add("MIC");
            flipped |= MIC;
        }
        if ((o & VOICE_UPLINK) == VOICE_UPLINK) {
            list.add("VOICE_UPLINK");
            flipped |= VOICE_UPLINK;
        }
        if ((o & VOICE_DOWNLINK) == VOICE_DOWNLINK) {
            list.add("VOICE_DOWNLINK");
            flipped |= VOICE_DOWNLINK;
        }
        if ((o & VOICE_CALL) == VOICE_CALL) {
            list.add("VOICE_CALL");
            flipped |= VOICE_CALL;
        }
        if ((o & CAMCORDER) == CAMCORDER) {
            list.add("CAMCORDER");
            flipped |= CAMCORDER;
        }
        if ((o & VOICE_RECOGNITION) == VOICE_RECOGNITION) {
            list.add("VOICE_RECOGNITION");
            flipped |= VOICE_RECOGNITION;
        }
        if ((o & VOICE_COMMUNICATION) == VOICE_COMMUNICATION) {
            list.add("VOICE_COMMUNICATION");
            flipped |= VOICE_COMMUNICATION;
        }
        if ((o & REMOTE_SUBMIX) == REMOTE_SUBMIX) {
            list.add("REMOTE_SUBMIX");
            flipped |= REMOTE_SUBMIX;
        }
        if ((o & UNPROCESSED) == UNPROCESSED) {
            list.add("UNPROCESSED");
            flipped |= UNPROCESSED;
        }
        if ((o & CNT) == CNT) {
            list.add("CNT");
            flipped |= CNT;
        }
        if ((o & MAX) == MAX) {
            list.add("MAX");
            flipped |= MAX;
        }
        if ((o & FM_TUNER) == FM_TUNER) {
            list.add("FM_TUNER");
            flipped |= FM_TUNER;
        }
        if ((o & HOTWORD) == HOTWORD) {
            list.add("HOTWORD");
            flipped |= HOTWORD;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

