package android.hardware.tv.cec.V1_0;


public final class CecDeviceType {
    public static final int INACTIVE = -1 /* -1 */;
    public static final int TV = 0;
    public static final int RECORDER = 1;
    public static final int TUNER = 3;
    public static final int PLAYBACK = 4;
    public static final int AUDIO_SYSTEM = 5;
    public static final int MAX = 5 /* AUDIO_SYSTEM */;
    public static final String toString(int o) {
        if (o == INACTIVE) {
            return "INACTIVE";
        }
        if (o == TV) {
            return "TV";
        }
        if (o == RECORDER) {
            return "RECORDER";
        }
        if (o == TUNER) {
            return "TUNER";
        }
        if (o == PLAYBACK) {
            return "PLAYBACK";
        }
        if (o == AUDIO_SYSTEM) {
            return "AUDIO_SYSTEM";
        }
        if (o == MAX) {
            return "MAX";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        if ((o & INACTIVE) == INACTIVE) {
            list.add("INACTIVE");
            flipped |= INACTIVE;
        }
        list.add("TV"); // TV == 0
        if ((o & RECORDER) == RECORDER) {
            list.add("RECORDER");
            flipped |= RECORDER;
        }
        if ((o & TUNER) == TUNER) {
            list.add("TUNER");
            flipped |= TUNER;
        }
        if ((o & PLAYBACK) == PLAYBACK) {
            list.add("PLAYBACK");
            flipped |= PLAYBACK;
        }
        if ((o & AUDIO_SYSTEM) == AUDIO_SYSTEM) {
            list.add("AUDIO_SYSTEM");
            flipped |= AUDIO_SYSTEM;
        }
        if ((o & MAX) == MAX) {
            list.add("MAX");
            flipped |= MAX;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

