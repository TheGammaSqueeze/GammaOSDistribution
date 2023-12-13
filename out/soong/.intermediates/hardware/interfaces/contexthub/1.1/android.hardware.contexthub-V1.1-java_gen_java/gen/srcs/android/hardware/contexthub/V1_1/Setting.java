package android.hardware.contexthub.V1_1;


public final class Setting {
    public static final byte LOCATION = 0;
    public static final String toString(byte o) {
        if (o == LOCATION) {
            return "LOCATION";
        }
        return "0x" + Integer.toHexString(Byte.toUnsignedInt((byte)(o)));
    }

    public static final String dumpBitfield(byte o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        byte flipped = 0;
        list.add("LOCATION"); // LOCATION == 0
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(Byte.toUnsignedInt((byte)(o & (~flipped)))));
        }
        return String.join(" | ", list);
    }

};

