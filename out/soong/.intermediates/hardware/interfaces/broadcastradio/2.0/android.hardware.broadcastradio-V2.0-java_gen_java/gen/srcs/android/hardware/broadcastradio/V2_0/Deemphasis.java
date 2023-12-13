package android.hardware.broadcastradio.V2_0;


public final class Deemphasis {
    public static final byte D50 = 1 /* 1 << 0 */;
    public static final byte D75 = 2 /* 1 << 1 */;
    public static final String toString(byte o) {
        if (o == D50) {
            return "D50";
        }
        if (o == D75) {
            return "D75";
        }
        return "0x" + Integer.toHexString(Byte.toUnsignedInt((byte)(o)));
    }

    public static final String dumpBitfield(byte o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        byte flipped = 0;
        if ((o & D50) == D50) {
            list.add("D50");
            flipped |= D50;
        }
        if ((o & D75) == D75) {
            list.add("D75");
            flipped |= D75;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(Byte.toUnsignedInt((byte)(o & (~flipped)))));
        }
        return String.join(" | ", list);
    }

};

