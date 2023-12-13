package android.hardware.radio.V1_6;


public final class SscMode {
    public static final byte MODE_1 = 1;
    public static final byte MODE_2 = 2;
    public static final byte MODE_3 = 3;
    public static final String toString(byte o) {
        if (o == MODE_1) {
            return "MODE_1";
        }
        if (o == MODE_2) {
            return "MODE_2";
        }
        if (o == MODE_3) {
            return "MODE_3";
        }
        return "0x" + Integer.toHexString(Byte.toUnsignedInt((byte)(o)));
    }

    public static final String dumpBitfield(byte o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        byte flipped = 0;
        if ((o & MODE_1) == MODE_1) {
            list.add("MODE_1");
            flipped |= MODE_1;
        }
        if ((o & MODE_2) == MODE_2) {
            list.add("MODE_2");
            flipped |= MODE_2;
        }
        if ((o & MODE_3) == MODE_3) {
            list.add("MODE_3");
            flipped |= MODE_3;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(Byte.toUnsignedInt((byte)(o & (~flipped)))));
        }
        return String.join(" | ", list);
    }

};

