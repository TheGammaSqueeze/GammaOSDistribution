package android.hardware.audio.common.V2_0;


public final class AudioGainMode {
    public static final int JOINT = 1 /* 0x1 */;
    public static final int CHANNELS = 2 /* 0x2 */;
    public static final int RAMP = 4 /* 0x4 */;
    public static final String toString(int o) {
        if (o == JOINT) {
            return "JOINT";
        }
        if (o == CHANNELS) {
            return "CHANNELS";
        }
        if (o == RAMP) {
            return "RAMP";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        if ((o & JOINT) == JOINT) {
            list.add("JOINT");
            flipped |= JOINT;
        }
        if ((o & CHANNELS) == CHANNELS) {
            list.add("CHANNELS");
            flipped |= CHANNELS;
        }
        if ((o & RAMP) == RAMP) {
            list.add("RAMP");
            flipped |= RAMP;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

