package android.hardware.radio.V1_6;


public final class EmfIndicator {
    /**
     * Emergency services fallback not supported
     */
    public static final byte EMF_NOT_SUPPORTED = 0;
    /**
     * Emergency services fallback supported in NR connected to 5GCN only
     */
    public static final byte EMF_NR_CONNECTED_TO_5GCN = 1;
    /**
     * Emergency services fallback supported in E-UTRA connected to 5GCN only
     */
    public static final byte EMF_EUTRA_CONNECTED_TO_5GCN = 2;
    /**
     * Emergency services fallback supported in NR connected to 5GCN and E-UTRA
     * connected to 5GCN.
     */
    public static final byte EMF_BOTH_NR_EUTRA_CONNECTED_TO_5GCN = 3;
    public static final String toString(byte o) {
        if (o == EMF_NOT_SUPPORTED) {
            return "EMF_NOT_SUPPORTED";
        }
        if (o == EMF_NR_CONNECTED_TO_5GCN) {
            return "EMF_NR_CONNECTED_TO_5GCN";
        }
        if (o == EMF_EUTRA_CONNECTED_TO_5GCN) {
            return "EMF_EUTRA_CONNECTED_TO_5GCN";
        }
        if (o == EMF_BOTH_NR_EUTRA_CONNECTED_TO_5GCN) {
            return "EMF_BOTH_NR_EUTRA_CONNECTED_TO_5GCN";
        }
        return "0x" + Integer.toHexString(Byte.toUnsignedInt((byte)(o)));
    }

    public static final String dumpBitfield(byte o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        byte flipped = 0;
        list.add("EMF_NOT_SUPPORTED"); // EMF_NOT_SUPPORTED == 0
        if ((o & EMF_NR_CONNECTED_TO_5GCN) == EMF_NR_CONNECTED_TO_5GCN) {
            list.add("EMF_NR_CONNECTED_TO_5GCN");
            flipped |= EMF_NR_CONNECTED_TO_5GCN;
        }
        if ((o & EMF_EUTRA_CONNECTED_TO_5GCN) == EMF_EUTRA_CONNECTED_TO_5GCN) {
            list.add("EMF_EUTRA_CONNECTED_TO_5GCN");
            flipped |= EMF_EUTRA_CONNECTED_TO_5GCN;
        }
        if ((o & EMF_BOTH_NR_EUTRA_CONNECTED_TO_5GCN) == EMF_BOTH_NR_EUTRA_CONNECTED_TO_5GCN) {
            list.add("EMF_BOTH_NR_EUTRA_CONNECTED_TO_5GCN");
            flipped |= EMF_BOTH_NR_EUTRA_CONNECTED_TO_5GCN;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(Byte.toUnsignedInt((byte)(o & (~flipped)))));
        }
        return String.join(" | ", list);
    }

};

