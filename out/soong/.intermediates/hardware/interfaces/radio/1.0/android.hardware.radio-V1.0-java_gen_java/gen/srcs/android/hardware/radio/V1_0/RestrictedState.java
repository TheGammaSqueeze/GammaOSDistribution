package android.hardware.radio.V1_0;


public final class RestrictedState {
    public static final int NONE = 0 /* 0x00 */;
    public static final int CS_EMERGENCY = 1 /* 0x01 */;
    public static final int CS_NORMAL = 2 /* 0x02 */;
    public static final int CS_ALL = 4 /* 0x04 */;
    public static final int PS_ALL = 16 /* 0x10 */;
    public static final String toString(int o) {
        if (o == NONE) {
            return "NONE";
        }
        if (o == CS_EMERGENCY) {
            return "CS_EMERGENCY";
        }
        if (o == CS_NORMAL) {
            return "CS_NORMAL";
        }
        if (o == CS_ALL) {
            return "CS_ALL";
        }
        if (o == PS_ALL) {
            return "PS_ALL";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("NONE"); // NONE == 0
        if ((o & CS_EMERGENCY) == CS_EMERGENCY) {
            list.add("CS_EMERGENCY");
            flipped |= CS_EMERGENCY;
        }
        if ((o & CS_NORMAL) == CS_NORMAL) {
            list.add("CS_NORMAL");
            flipped |= CS_NORMAL;
        }
        if ((o & CS_ALL) == CS_ALL) {
            list.add("CS_ALL");
            flipped |= CS_ALL;
        }
        if ((o & PS_ALL) == PS_ALL) {
            list.add("PS_ALL");
            flipped |= PS_ALL;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

