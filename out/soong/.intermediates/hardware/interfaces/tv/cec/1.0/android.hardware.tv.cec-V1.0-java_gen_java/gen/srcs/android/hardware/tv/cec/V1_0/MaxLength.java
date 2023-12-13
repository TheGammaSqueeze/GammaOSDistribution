package android.hardware.tv.cec.V1_0;


public final class MaxLength {
    public static final int MESSAGE_BODY = 15;
    public static final String toString(int o) {
        if (o == MESSAGE_BODY) {
            return "MESSAGE_BODY";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        if ((o & MESSAGE_BODY) == MESSAGE_BODY) {
            list.add("MESSAGE_BODY");
            flipped |= MESSAGE_BODY;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

