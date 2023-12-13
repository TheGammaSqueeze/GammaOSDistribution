package android.hardware.audio.common.V2_0;


public final class AudioPortType {
    public static final int NONE = 0;
    public static final int DEVICE = 1 /* ::android::hardware::audio::common::V2_0::AudioPortType.NONE implicitly + 1 */;
    public static final int MIX = 2 /* ::android::hardware::audio::common::V2_0::AudioPortType.DEVICE implicitly + 1 */;
    public static final int SESSION = 3 /* ::android::hardware::audio::common::V2_0::AudioPortType.MIX implicitly + 1 */;
    public static final String toString(int o) {
        if (o == NONE) {
            return "NONE";
        }
        if (o == DEVICE) {
            return "DEVICE";
        }
        if (o == MIX) {
            return "MIX";
        }
        if (o == SESSION) {
            return "SESSION";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("NONE"); // NONE == 0
        if ((o & DEVICE) == DEVICE) {
            list.add("DEVICE");
            flipped |= DEVICE;
        }
        if ((o & MIX) == MIX) {
            list.add("MIX");
            flipped |= MIX;
        }
        if ((o & SESSION) == SESSION) {
            list.add("SESSION");
            flipped |= SESSION;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

