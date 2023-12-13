package android.hardware.audio.common.V2_0;


public final class AudioMixLatencyClass {
    public static final int LOW = 0;
    public static final int NORMAL = 1 /* ::android::hardware::audio::common::V2_0::AudioMixLatencyClass.LOW implicitly + 1 */;
    public static final String toString(int o) {
        if (o == LOW) {
            return "LOW";
        }
        if (o == NORMAL) {
            return "NORMAL";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("LOW"); // LOW == 0
        if ((o & NORMAL) == NORMAL) {
            list.add("NORMAL");
            flipped |= NORMAL;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

