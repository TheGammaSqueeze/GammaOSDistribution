package android.hardware.radio.V1_6;


public final class SliceStatus {
    public static final byte UNKNOWN = 0;
    public static final byte CONFIGURED = 1 /* ::android::hardware::radio::V1_6::SliceStatus.UNKNOWN implicitly + 1 */;
    public static final byte ALLOWED = 2 /* ::android::hardware::radio::V1_6::SliceStatus.CONFIGURED implicitly + 1 */;
    public static final byte REJECTED_NOT_AVAILABLE_IN_PLMN = 3 /* ::android::hardware::radio::V1_6::SliceStatus.ALLOWED implicitly + 1 */;
    public static final byte REJECTED_NOT_AVAILABLE_IN_REG_AREA = 4 /* ::android::hardware::radio::V1_6::SliceStatus.REJECTED_NOT_AVAILABLE_IN_PLMN implicitly + 1 */;
    public static final byte DEFAULT_CONFIGURED = 5 /* ::android::hardware::radio::V1_6::SliceStatus.REJECTED_NOT_AVAILABLE_IN_REG_AREA implicitly + 1 */;
    public static final String toString(byte o) {
        if (o == UNKNOWN) {
            return "UNKNOWN";
        }
        if (o == CONFIGURED) {
            return "CONFIGURED";
        }
        if (o == ALLOWED) {
            return "ALLOWED";
        }
        if (o == REJECTED_NOT_AVAILABLE_IN_PLMN) {
            return "REJECTED_NOT_AVAILABLE_IN_PLMN";
        }
        if (o == REJECTED_NOT_AVAILABLE_IN_REG_AREA) {
            return "REJECTED_NOT_AVAILABLE_IN_REG_AREA";
        }
        if (o == DEFAULT_CONFIGURED) {
            return "DEFAULT_CONFIGURED";
        }
        return "0x" + Integer.toHexString(Byte.toUnsignedInt((byte)(o)));
    }

    public static final String dumpBitfield(byte o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        byte flipped = 0;
        list.add("UNKNOWN"); // UNKNOWN == 0
        if ((o & CONFIGURED) == CONFIGURED) {
            list.add("CONFIGURED");
            flipped |= CONFIGURED;
        }
        if ((o & ALLOWED) == ALLOWED) {
            list.add("ALLOWED");
            flipped |= ALLOWED;
        }
        if ((o & REJECTED_NOT_AVAILABLE_IN_PLMN) == REJECTED_NOT_AVAILABLE_IN_PLMN) {
            list.add("REJECTED_NOT_AVAILABLE_IN_PLMN");
            flipped |= REJECTED_NOT_AVAILABLE_IN_PLMN;
        }
        if ((o & REJECTED_NOT_AVAILABLE_IN_REG_AREA) == REJECTED_NOT_AVAILABLE_IN_REG_AREA) {
            list.add("REJECTED_NOT_AVAILABLE_IN_REG_AREA");
            flipped |= REJECTED_NOT_AVAILABLE_IN_REG_AREA;
        }
        if ((o & DEFAULT_CONFIGURED) == DEFAULT_CONFIGURED) {
            list.add("DEFAULT_CONFIGURED");
            flipped |= DEFAULT_CONFIGURED;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(Byte.toUnsignedInt((byte)(o & (~flipped)))));
        }
        return String.join(" | ", list);
    }

};

