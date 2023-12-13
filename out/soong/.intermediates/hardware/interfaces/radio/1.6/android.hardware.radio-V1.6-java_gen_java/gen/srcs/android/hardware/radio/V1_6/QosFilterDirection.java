package android.hardware.radio.V1_6;


public final class QosFilterDirection {
    public static final byte DOWNLINK = 0;
    public static final byte UPLINK = 1;
    public static final byte BIDIRECTIONAL = 2;
    public static final String toString(byte o) {
        if (o == DOWNLINK) {
            return "DOWNLINK";
        }
        if (o == UPLINK) {
            return "UPLINK";
        }
        if (o == BIDIRECTIONAL) {
            return "BIDIRECTIONAL";
        }
        return "0x" + Integer.toHexString(Byte.toUnsignedInt((byte)(o)));
    }

    public static final String dumpBitfield(byte o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        byte flipped = 0;
        list.add("DOWNLINK"); // DOWNLINK == 0
        if ((o & UPLINK) == UPLINK) {
            list.add("UPLINK");
            flipped |= UPLINK;
        }
        if ((o & BIDIRECTIONAL) == BIDIRECTIONAL) {
            list.add("BIDIRECTIONAL");
            flipped |= BIDIRECTIONAL;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(Byte.toUnsignedInt((byte)(o & (~flipped)))));
        }
        return String.join(" | ", list);
    }

};

