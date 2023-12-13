package android.hardware.contexthub.V1_0;


public final class HostEndPoint {
    public static final short BROADCAST = -1 /* 0xFFFF */;
    public static final short UNSPECIFIED = -2 /* 0xFFFE */;
    public static final String toString(short o) {
        if (o == BROADCAST) {
            return "BROADCAST";
        }
        if (o == UNSPECIFIED) {
            return "UNSPECIFIED";
        }
        return "0x" + Integer.toHexString(Short.toUnsignedInt((short)(o)));
    }

    public static final String dumpBitfield(short o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        short flipped = 0;
        if ((o & BROADCAST) == BROADCAST) {
            list.add("BROADCAST");
            flipped |= BROADCAST;
        }
        if ((o & UNSPECIFIED) == UNSPECIFIED) {
            list.add("UNSPECIFIED");
            flipped |= UNSPECIFIED;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(Short.toUnsignedInt((short)(o & (~flipped)))));
        }
        return String.join(" | ", list);
    }

};

