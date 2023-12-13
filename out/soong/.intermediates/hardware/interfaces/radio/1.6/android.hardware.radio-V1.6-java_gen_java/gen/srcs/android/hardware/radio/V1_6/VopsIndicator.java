package android.hardware.radio.V1_6;


public final class VopsIndicator {
    /**
     * IMS voice over PS session not supported
     */
    public static final byte VOPS_NOT_SUPPORTED = 0;
    /**
     * IMS voice over PS session supported over 3GPP access
     */
    public static final byte VOPS_OVER_3GPP = 1;
    /**
     * IMS voice over PS session supported over non-3GPP access
     */
    public static final byte VOPS_OVER_NON_3GPP = 2;
    public static final String toString(byte o) {
        if (o == VOPS_NOT_SUPPORTED) {
            return "VOPS_NOT_SUPPORTED";
        }
        if (o == VOPS_OVER_3GPP) {
            return "VOPS_OVER_3GPP";
        }
        if (o == VOPS_OVER_NON_3GPP) {
            return "VOPS_OVER_NON_3GPP";
        }
        return "0x" + Integer.toHexString(Byte.toUnsignedInt((byte)(o)));
    }

    public static final String dumpBitfield(byte o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        byte flipped = 0;
        list.add("VOPS_NOT_SUPPORTED"); // VOPS_NOT_SUPPORTED == 0
        if ((o & VOPS_OVER_3GPP) == VOPS_OVER_3GPP) {
            list.add("VOPS_OVER_3GPP");
            flipped |= VOPS_OVER_3GPP;
        }
        if ((o & VOPS_OVER_NON_3GPP) == VOPS_OVER_NON_3GPP) {
            list.add("VOPS_OVER_NON_3GPP");
            flipped |= VOPS_OVER_NON_3GPP;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(Byte.toUnsignedInt((byte)(o & (~flipped)))));
        }
        return String.join(" | ", list);
    }

};

