package android.hardware.radio.V1_0;


public final class SapStatus {
    public static final int UNKNOWN_ERROR = 0;
    public static final int CARD_RESET = 1 /* ::android::hardware::radio::V1_0::SapStatus.UNKNOWN_ERROR implicitly + 1 */;
    public static final int CARD_NOT_ACCESSIBLE = 2 /* ::android::hardware::radio::V1_0::SapStatus.CARD_RESET implicitly + 1 */;
    public static final int CARD_REMOVED = 3 /* ::android::hardware::radio::V1_0::SapStatus.CARD_NOT_ACCESSIBLE implicitly + 1 */;
    public static final int CARD_INSERTED = 4 /* ::android::hardware::radio::V1_0::SapStatus.CARD_REMOVED implicitly + 1 */;
    public static final int RECOVERED = 5 /* ::android::hardware::radio::V1_0::SapStatus.CARD_INSERTED implicitly + 1 */;
    public static final String toString(int o) {
        if (o == UNKNOWN_ERROR) {
            return "UNKNOWN_ERROR";
        }
        if (o == CARD_RESET) {
            return "CARD_RESET";
        }
        if (o == CARD_NOT_ACCESSIBLE) {
            return "CARD_NOT_ACCESSIBLE";
        }
        if (o == CARD_REMOVED) {
            return "CARD_REMOVED";
        }
        if (o == CARD_INSERTED) {
            return "CARD_INSERTED";
        }
        if (o == RECOVERED) {
            return "RECOVERED";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("UNKNOWN_ERROR"); // UNKNOWN_ERROR == 0
        if ((o & CARD_RESET) == CARD_RESET) {
            list.add("CARD_RESET");
            flipped |= CARD_RESET;
        }
        if ((o & CARD_NOT_ACCESSIBLE) == CARD_NOT_ACCESSIBLE) {
            list.add("CARD_NOT_ACCESSIBLE");
            flipped |= CARD_NOT_ACCESSIBLE;
        }
        if ((o & CARD_REMOVED) == CARD_REMOVED) {
            list.add("CARD_REMOVED");
            flipped |= CARD_REMOVED;
        }
        if ((o & CARD_INSERTED) == CARD_INSERTED) {
            list.add("CARD_INSERTED");
            flipped |= CARD_INSERTED;
        }
        if ((o & RECOVERED) == RECOVERED) {
            list.add("RECOVERED");
            flipped |= RECOVERED;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

