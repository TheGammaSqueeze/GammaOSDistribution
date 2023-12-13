package android.hardware.audio.common.V2_0;


public final class AudioPortConfigMask {
    public static final int SAMPLE_RATE = 1 /* 0x1 */;
    public static final int CHANNEL_MASK = 2 /* 0x2 */;
    public static final int FORMAT = 4 /* 0x4 */;
    public static final int GAIN = 8 /* 0x8 */;
    public static final int ALL = 15 /* SAMPLE_RATE | CHANNEL_MASK | FORMAT | GAIN */;
    public static final String toString(int o) {
        if (o == SAMPLE_RATE) {
            return "SAMPLE_RATE";
        }
        if (o == CHANNEL_MASK) {
            return "CHANNEL_MASK";
        }
        if (o == FORMAT) {
            return "FORMAT";
        }
        if (o == GAIN) {
            return "GAIN";
        }
        if (o == ALL) {
            return "ALL";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        if ((o & SAMPLE_RATE) == SAMPLE_RATE) {
            list.add("SAMPLE_RATE");
            flipped |= SAMPLE_RATE;
        }
        if ((o & CHANNEL_MASK) == CHANNEL_MASK) {
            list.add("CHANNEL_MASK");
            flipped |= CHANNEL_MASK;
        }
        if ((o & FORMAT) == FORMAT) {
            list.add("FORMAT");
            flipped |= FORMAT;
        }
        if ((o & GAIN) == GAIN) {
            list.add("GAIN");
            flipped |= GAIN;
        }
        if ((o & ALL) == ALL) {
            list.add("ALL");
            flipped |= ALL;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

