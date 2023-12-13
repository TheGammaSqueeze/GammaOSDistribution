package android.hardware.radio.V1_6;


public final class PublicKeyType {
    public static final byte EPDG = 1;
    public static final byte WLAN = 2;
    public static final String toString(byte o) {
        if (o == EPDG) {
            return "EPDG";
        }
        if (o == WLAN) {
            return "WLAN";
        }
        return "0x" + Integer.toHexString(Byte.toUnsignedInt((byte)(o)));
    }

    public static final String dumpBitfield(byte o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        byte flipped = 0;
        if ((o & EPDG) == EPDG) {
            list.add("EPDG");
            flipped |= EPDG;
        }
        if ((o & WLAN) == WLAN) {
            list.add("WLAN");
            flipped |= WLAN;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(Byte.toUnsignedInt((byte)(o & (~flipped)))));
        }
        return String.join(" | ", list);
    }

};

