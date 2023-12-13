package android.hardware.radio.V1_0;


public final class SmsAcknowledgeFailCause {
    public static final int MEMORY_CAPACITY_EXCEEDED = 211 /* 0xD3 */;
    public static final int UNSPECIFIED_ERROR = 255 /* 0XFF */;
    public static final String toString(int o) {
        if (o == MEMORY_CAPACITY_EXCEEDED) {
            return "MEMORY_CAPACITY_EXCEEDED";
        }
        if (o == UNSPECIFIED_ERROR) {
            return "UNSPECIFIED_ERROR";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        if ((o & MEMORY_CAPACITY_EXCEEDED) == MEMORY_CAPACITY_EXCEEDED) {
            list.add("MEMORY_CAPACITY_EXCEEDED");
            flipped |= MEMORY_CAPACITY_EXCEEDED;
        }
        if ((o & UNSPECIFIED_ERROR) == UNSPECIFIED_ERROR) {
            list.add("UNSPECIFIED_ERROR");
            flipped |= UNSPECIFIED_ERROR;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

