package android.hardware.radio.V1_6;


public final class QosPortRange {
    public static final short MIN = 20;
    public static final short MAX = -1;
    public static final String toString(short o) {
        if (o == MIN) {
            return "MIN";
        }
        if (o == MAX) {
            return "MAX";
        }
        return "0x" + Integer.toHexString(Short.toUnsignedInt((short)(o)));
    }

    public static final String dumpBitfield(short o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        short flipped = 0;
        if ((o & MIN) == MIN) {
            list.add("MIN");
            flipped |= MIN;
        }
        if ((o & MAX) == MAX) {
            list.add("MAX");
            flipped |= MAX;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(Short.toUnsignedInt((short)(o & (~flipped)))));
        }
        return String.join(" | ", list);
    }

};

