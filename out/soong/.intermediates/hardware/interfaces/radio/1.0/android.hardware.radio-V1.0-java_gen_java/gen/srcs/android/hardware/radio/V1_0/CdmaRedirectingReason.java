package android.hardware.radio.V1_0;


public final class CdmaRedirectingReason {
    public static final int UNKNOWN = 0;
    public static final int CALL_FORWARDING_BUSY = 1;
    public static final int CALL_FORWARDING_NO_REPLY = 2;
    public static final int CALLED_DTE_OUT_OF_ORDER = 9;
    public static final int CALL_FORWARDING_BY_THE_CALLED_DTE = 10;
    public static final int CALL_FORWARDING_UNCONDITIONAL = 15;
    public static final int RESERVED = 16 /* ::android::hardware::radio::V1_0::CdmaRedirectingReason.CALL_FORWARDING_UNCONDITIONAL implicitly + 1 */;
    public static final String toString(int o) {
        if (o == UNKNOWN) {
            return "UNKNOWN";
        }
        if (o == CALL_FORWARDING_BUSY) {
            return "CALL_FORWARDING_BUSY";
        }
        if (o == CALL_FORWARDING_NO_REPLY) {
            return "CALL_FORWARDING_NO_REPLY";
        }
        if (o == CALLED_DTE_OUT_OF_ORDER) {
            return "CALLED_DTE_OUT_OF_ORDER";
        }
        if (o == CALL_FORWARDING_BY_THE_CALLED_DTE) {
            return "CALL_FORWARDING_BY_THE_CALLED_DTE";
        }
        if (o == CALL_FORWARDING_UNCONDITIONAL) {
            return "CALL_FORWARDING_UNCONDITIONAL";
        }
        if (o == RESERVED) {
            return "RESERVED";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("UNKNOWN"); // UNKNOWN == 0
        if ((o & CALL_FORWARDING_BUSY) == CALL_FORWARDING_BUSY) {
            list.add("CALL_FORWARDING_BUSY");
            flipped |= CALL_FORWARDING_BUSY;
        }
        if ((o & CALL_FORWARDING_NO_REPLY) == CALL_FORWARDING_NO_REPLY) {
            list.add("CALL_FORWARDING_NO_REPLY");
            flipped |= CALL_FORWARDING_NO_REPLY;
        }
        if ((o & CALLED_DTE_OUT_OF_ORDER) == CALLED_DTE_OUT_OF_ORDER) {
            list.add("CALLED_DTE_OUT_OF_ORDER");
            flipped |= CALLED_DTE_OUT_OF_ORDER;
        }
        if ((o & CALL_FORWARDING_BY_THE_CALLED_DTE) == CALL_FORWARDING_BY_THE_CALLED_DTE) {
            list.add("CALL_FORWARDING_BY_THE_CALLED_DTE");
            flipped |= CALL_FORWARDING_BY_THE_CALLED_DTE;
        }
        if ((o & CALL_FORWARDING_UNCONDITIONAL) == CALL_FORWARDING_UNCONDITIONAL) {
            list.add("CALL_FORWARDING_UNCONDITIONAL");
            flipped |= CALL_FORWARDING_UNCONDITIONAL;
        }
        if ((o & RESERVED) == RESERVED) {
            list.add("RESERVED");
            flipped |= RESERVED;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

