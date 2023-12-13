package android.hardware.radio.V1_2;


public final class CellConnectionStatus {
    /**
     * Cell is not a serving cell.
     */
    public static final int NONE = 0;
    /**
     * UE has connection to cell for signalling and possibly data (3GPP 36.331, 25.331).
     */
    public static final int PRIMARY_SERVING = 1 /* ::android::hardware::radio::V1_2::CellConnectionStatus.NONE implicitly + 1 */;
    /**
     * UE has connection to cell for data (3GPP 36.331, 25.331).
     */
    public static final int SECONDARY_SERVING = 2 /* ::android::hardware::radio::V1_2::CellConnectionStatus.PRIMARY_SERVING implicitly + 1 */;
    public static final String toString(int o) {
        if (o == NONE) {
            return "NONE";
        }
        if (o == PRIMARY_SERVING) {
            return "PRIMARY_SERVING";
        }
        if (o == SECONDARY_SERVING) {
            return "SECONDARY_SERVING";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("NONE"); // NONE == 0
        if ((o & PRIMARY_SERVING) == PRIMARY_SERVING) {
            list.add("PRIMARY_SERVING");
            flipped |= PRIMARY_SERVING;
        }
        if ((o & SECONDARY_SERVING) == SECONDARY_SERVING) {
            list.add("SECONDARY_SERVING");
            flipped |= SECONDARY_SERVING;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

