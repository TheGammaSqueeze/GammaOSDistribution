package android.hardware.audio.common.V2_0;


public final class AudioPortRole {
    public static final int NONE = 0;
    public static final int SOURCE = 1 /* ::android::hardware::audio::common::V2_0::AudioPortRole.NONE implicitly + 1 */;
    public static final int SINK = 2 /* ::android::hardware::audio::common::V2_0::AudioPortRole.SOURCE implicitly + 1 */;
    public static final String toString(int o) {
        if (o == NONE) {
            return "NONE";
        }
        if (o == SOURCE) {
            return "SOURCE";
        }
        if (o == SINK) {
            return "SINK";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("NONE"); // NONE == 0
        if ((o & SOURCE) == SOURCE) {
            list.add("SOURCE");
            flipped |= SOURCE;
        }
        if ((o & SINK) == SINK) {
            list.add("SINK");
            flipped |= SINK;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

