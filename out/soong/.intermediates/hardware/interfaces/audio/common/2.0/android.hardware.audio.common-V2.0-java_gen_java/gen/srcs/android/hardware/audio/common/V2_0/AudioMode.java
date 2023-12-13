package android.hardware.audio.common.V2_0;


public final class AudioMode {
    public static final int INVALID = -2 /* -2 */;
    public static final int CURRENT = -1 /* -1 */;
    public static final int NORMAL = 0;
    public static final int RINGTONE = 1;
    public static final int IN_CALL = 2;
    public static final int IN_COMMUNICATION = 3;
    public static final int CNT = 4 /* ::android::hardware::audio::common::V2_0::AudioMode.IN_COMMUNICATION implicitly + 1 */;
    public static final int MAX = 3 /* CNT - 1 */;
    public static final String toString(int o) {
        if (o == INVALID) {
            return "INVALID";
        }
        if (o == CURRENT) {
            return "CURRENT";
        }
        if (o == NORMAL) {
            return "NORMAL";
        }
        if (o == RINGTONE) {
            return "RINGTONE";
        }
        if (o == IN_CALL) {
            return "IN_CALL";
        }
        if (o == IN_COMMUNICATION) {
            return "IN_COMMUNICATION";
        }
        if (o == CNT) {
            return "CNT";
        }
        if (o == MAX) {
            return "MAX";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        if ((o & INVALID) == INVALID) {
            list.add("INVALID");
            flipped |= INVALID;
        }
        if ((o & CURRENT) == CURRENT) {
            list.add("CURRENT");
            flipped |= CURRENT;
        }
        list.add("NORMAL"); // NORMAL == 0
        if ((o & RINGTONE) == RINGTONE) {
            list.add("RINGTONE");
            flipped |= RINGTONE;
        }
        if ((o & IN_CALL) == IN_CALL) {
            list.add("IN_CALL");
            flipped |= IN_CALL;
        }
        if ((o & IN_COMMUNICATION) == IN_COMMUNICATION) {
            list.add("IN_COMMUNICATION");
            flipped |= IN_COMMUNICATION;
        }
        if ((o & CNT) == CNT) {
            list.add("CNT");
            flipped |= CNT;
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

