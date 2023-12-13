package android.hardware.radio.V1_6;


public final class EmcIndicator {
    /**
     * Emergency services not supported
     */
    public static final byte EMC_NOT_SUPPORTED = 0;
    /**
     * Emergency services supported in NR connected to 5GCN only
     */
    public static final byte EMC_NR_CONNECTED_TO_5GCN = 1;
    /**
     * Emergency services supported in E-UTRA connected to 5GCN only
     */
    public static final byte EMC_EUTRA_CONNECTED_TO_5GCN = 2;
    /**
     * Emergency services supported in NR connected to 5GCN and E-UTRA connected to 5GCN
     */
    public static final byte EMC_BOTH_NR_EUTRA_CONNECTED_TO_5GCN = 3;
    public static final String toString(byte o) {
        if (o == EMC_NOT_SUPPORTED) {
            return "EMC_NOT_SUPPORTED";
        }
        if (o == EMC_NR_CONNECTED_TO_5GCN) {
            return "EMC_NR_CONNECTED_TO_5GCN";
        }
        if (o == EMC_EUTRA_CONNECTED_TO_5GCN) {
            return "EMC_EUTRA_CONNECTED_TO_5GCN";
        }
        if (o == EMC_BOTH_NR_EUTRA_CONNECTED_TO_5GCN) {
            return "EMC_BOTH_NR_EUTRA_CONNECTED_TO_5GCN";
        }
        return "0x" + Integer.toHexString(Byte.toUnsignedInt((byte)(o)));
    }

    public static final String dumpBitfield(byte o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        byte flipped = 0;
        list.add("EMC_NOT_SUPPORTED"); // EMC_NOT_SUPPORTED == 0
        if ((o & EMC_NR_CONNECTED_TO_5GCN) == EMC_NR_CONNECTED_TO_5GCN) {
            list.add("EMC_NR_CONNECTED_TO_5GCN");
            flipped |= EMC_NR_CONNECTED_TO_5GCN;
        }
        if ((o & EMC_EUTRA_CONNECTED_TO_5GCN) == EMC_EUTRA_CONNECTED_TO_5GCN) {
            list.add("EMC_EUTRA_CONNECTED_TO_5GCN");
            flipped |= EMC_EUTRA_CONNECTED_TO_5GCN;
        }
        if ((o & EMC_BOTH_NR_EUTRA_CONNECTED_TO_5GCN) == EMC_BOTH_NR_EUTRA_CONNECTED_TO_5GCN) {
            list.add("EMC_BOTH_NR_EUTRA_CONNECTED_TO_5GCN");
            flipped |= EMC_BOTH_NR_EUTRA_CONNECTED_TO_5GCN;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(Byte.toUnsignedInt((byte)(o & (~flipped)))));
        }
        return String.join(" | ", list);
    }

};

