package android.hardware.radio.V1_6;


public final class QosFlowIdRange {
    public static final byte MIN = 1;
    public static final byte MAX = 63;
    public static final String toString(byte o) {
        if (o == MIN) {
            return "MIN";
        }
        if (o == MAX) {
            return "MAX";
        }
        return "0x" + Integer.toHexString(Byte.toUnsignedInt((byte)(o)));
    }

    public static final String dumpBitfield(byte o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        byte flipped = 0;
        if ((o & MIN) == MIN) {
            list.add("MIN");
            flipped |= MIN;
        }
        if ((o & MAX) == MAX) {
            list.add("MAX");
            flipped |= MAX;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(Byte.toUnsignedInt((byte)(o & (~flipped)))));
        }
        return String.join(" | ", list);
    }

};

