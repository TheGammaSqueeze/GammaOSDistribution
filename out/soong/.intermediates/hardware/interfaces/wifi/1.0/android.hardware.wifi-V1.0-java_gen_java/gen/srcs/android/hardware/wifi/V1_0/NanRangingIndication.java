package android.hardware.wifi.V1_0;


public final class NanRangingIndication {
    public static final int CONTINUOUS_INDICATION_MASK = 1 /* 1 << 0 */;
    public static final int INGRESS_MET_MASK = 2 /* 1 << 1 */;
    public static final int EGRESS_MET_MASK = 4 /* 1 << 2 */;
    public static final String toString(int o) {
        if (o == CONTINUOUS_INDICATION_MASK) {
            return "CONTINUOUS_INDICATION_MASK";
        }
        if (o == INGRESS_MET_MASK) {
            return "INGRESS_MET_MASK";
        }
        if (o == EGRESS_MET_MASK) {
            return "EGRESS_MET_MASK";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        if ((o & CONTINUOUS_INDICATION_MASK) == CONTINUOUS_INDICATION_MASK) {
            list.add("CONTINUOUS_INDICATION_MASK");
            flipped |= CONTINUOUS_INDICATION_MASK;
        }
        if ((o & INGRESS_MET_MASK) == INGRESS_MET_MASK) {
            list.add("INGRESS_MET_MASK");
            flipped |= INGRESS_MET_MASK;
        }
        if ((o & EGRESS_MET_MASK) == EGRESS_MET_MASK) {
            list.add("EGRESS_MET_MASK");
            flipped |= EGRESS_MET_MASK;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

