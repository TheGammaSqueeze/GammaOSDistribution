package android.hardware.radio.V1_6;


public final class SliceServiceType {
    /*
     * Not specified
     */
    public static final byte NONE = 0;
    /*
     * Slice suitable for the handling of 5G enhanced Mobile Broadband
     */
    public static final byte EMBB = 1;
    /**
     * Slice suitable for the handling of ultra-reliable low latency
     * communications
     */
    public static final byte URLLC = 2;
    /*
     * Slice suitable for the handling of massive IoT
     */
    public static final byte MIOT = 3;
    public static final String toString(byte o) {
        if (o == NONE) {
            return "NONE";
        }
        if (o == EMBB) {
            return "EMBB";
        }
        if (o == URLLC) {
            return "URLLC";
        }
        if (o == MIOT) {
            return "MIOT";
        }
        return "0x" + Integer.toHexString(Byte.toUnsignedInt((byte)(o)));
    }

    public static final String dumpBitfield(byte o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        byte flipped = 0;
        list.add("NONE"); // NONE == 0
        if ((o & EMBB) == EMBB) {
            list.add("EMBB");
            flipped |= EMBB;
        }
        if ((o & URLLC) == URLLC) {
            list.add("URLLC");
            flipped |= URLLC;
        }
        if ((o & MIOT) == MIOT) {
            list.add("MIOT");
            flipped |= MIOT;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(Byte.toUnsignedInt((byte)(o & (~flipped)))));
        }
        return String.join(" | ", list);
    }

};

