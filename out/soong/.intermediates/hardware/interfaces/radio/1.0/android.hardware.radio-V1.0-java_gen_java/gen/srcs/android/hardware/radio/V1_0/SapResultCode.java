package android.hardware.radio.V1_0;


public final class SapResultCode {
    public static final int SUCCESS = 0;
    public static final int GENERIC_FAILURE = 1 /* ::android::hardware::radio::V1_0::SapResultCode.SUCCESS implicitly + 1 */;
    public static final int CARD_NOT_ACCESSSIBLE = 2 /* ::android::hardware::radio::V1_0::SapResultCode.GENERIC_FAILURE implicitly + 1 */;
    public static final int CARD_ALREADY_POWERED_OFF = 3 /* ::android::hardware::radio::V1_0::SapResultCode.CARD_NOT_ACCESSSIBLE implicitly + 1 */;
    public static final int CARD_REMOVED = 4 /* ::android::hardware::radio::V1_0::SapResultCode.CARD_ALREADY_POWERED_OFF implicitly + 1 */;
    public static final int CARD_ALREADY_POWERED_ON = 5 /* ::android::hardware::radio::V1_0::SapResultCode.CARD_REMOVED implicitly + 1 */;
    public static final int DATA_NOT_AVAILABLE = 6 /* ::android::hardware::radio::V1_0::SapResultCode.CARD_ALREADY_POWERED_ON implicitly + 1 */;
    public static final int NOT_SUPPORTED = 7 /* ::android::hardware::radio::V1_0::SapResultCode.DATA_NOT_AVAILABLE implicitly + 1 */;
    public static final String toString(int o) {
        if (o == SUCCESS) {
            return "SUCCESS";
        }
        if (o == GENERIC_FAILURE) {
            return "GENERIC_FAILURE";
        }
        if (o == CARD_NOT_ACCESSSIBLE) {
            return "CARD_NOT_ACCESSSIBLE";
        }
        if (o == CARD_ALREADY_POWERED_OFF) {
            return "CARD_ALREADY_POWERED_OFF";
        }
        if (o == CARD_REMOVED) {
            return "CARD_REMOVED";
        }
        if (o == CARD_ALREADY_POWERED_ON) {
            return "CARD_ALREADY_POWERED_ON";
        }
        if (o == DATA_NOT_AVAILABLE) {
            return "DATA_NOT_AVAILABLE";
        }
        if (o == NOT_SUPPORTED) {
            return "NOT_SUPPORTED";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("SUCCESS"); // SUCCESS == 0
        if ((o & GENERIC_FAILURE) == GENERIC_FAILURE) {
            list.add("GENERIC_FAILURE");
            flipped |= GENERIC_FAILURE;
        }
        if ((o & CARD_NOT_ACCESSSIBLE) == CARD_NOT_ACCESSSIBLE) {
            list.add("CARD_NOT_ACCESSSIBLE");
            flipped |= CARD_NOT_ACCESSSIBLE;
        }
        if ((o & CARD_ALREADY_POWERED_OFF) == CARD_ALREADY_POWERED_OFF) {
            list.add("CARD_ALREADY_POWERED_OFF");
            flipped |= CARD_ALREADY_POWERED_OFF;
        }
        if ((o & CARD_REMOVED) == CARD_REMOVED) {
            list.add("CARD_REMOVED");
            flipped |= CARD_REMOVED;
        }
        if ((o & CARD_ALREADY_POWERED_ON) == CARD_ALREADY_POWERED_ON) {
            list.add("CARD_ALREADY_POWERED_ON");
            flipped |= CARD_ALREADY_POWERED_ON;
        }
        if ((o & DATA_NOT_AVAILABLE) == DATA_NOT_AVAILABLE) {
            list.add("DATA_NOT_AVAILABLE");
            flipped |= DATA_NOT_AVAILABLE;
        }
        if ((o & NOT_SUPPORTED) == NOT_SUPPORTED) {
            list.add("NOT_SUPPORTED");
            flipped |= NOT_SUPPORTED;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

