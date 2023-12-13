package android.hardware.radio.V1_0;


public final class CdmaSmsNumberPlan {
    public static final int UNKNOWN = 0;
    public static final int TELEPHONY = 1 /* ::android::hardware::radio::V1_0::CdmaSmsNumberPlan.UNKNOWN implicitly + 1 */;
    public static final int RESERVED_2 = 2 /* ::android::hardware::radio::V1_0::CdmaSmsNumberPlan.TELEPHONY implicitly + 1 */;
    public static final int DATA = 3 /* ::android::hardware::radio::V1_0::CdmaSmsNumberPlan.RESERVED_2 implicitly + 1 */;
    public static final int TELEX = 4 /* ::android::hardware::radio::V1_0::CdmaSmsNumberPlan.DATA implicitly + 1 */;
    public static final int RESERVED_5 = 5 /* ::android::hardware::radio::V1_0::CdmaSmsNumberPlan.TELEX implicitly + 1 */;
    public static final int RESERVED_6 = 6 /* ::android::hardware::radio::V1_0::CdmaSmsNumberPlan.RESERVED_5 implicitly + 1 */;
    public static final int RESERVED_7 = 7 /* ::android::hardware::radio::V1_0::CdmaSmsNumberPlan.RESERVED_6 implicitly + 1 */;
    public static final int RESERVED_8 = 8 /* ::android::hardware::radio::V1_0::CdmaSmsNumberPlan.RESERVED_7 implicitly + 1 */;
    public static final int PRIVATE = 9 /* ::android::hardware::radio::V1_0::CdmaSmsNumberPlan.RESERVED_8 implicitly + 1 */;
    public static final int RESERVED_10 = 10 /* ::android::hardware::radio::V1_0::CdmaSmsNumberPlan.PRIVATE implicitly + 1 */;
    public static final int RESERVED_11 = 11 /* ::android::hardware::radio::V1_0::CdmaSmsNumberPlan.RESERVED_10 implicitly + 1 */;
    public static final int RESERVED_12 = 12 /* ::android::hardware::radio::V1_0::CdmaSmsNumberPlan.RESERVED_11 implicitly + 1 */;
    public static final int RESERVED_13 = 13 /* ::android::hardware::radio::V1_0::CdmaSmsNumberPlan.RESERVED_12 implicitly + 1 */;
    public static final int RESERVED_14 = 14 /* ::android::hardware::radio::V1_0::CdmaSmsNumberPlan.RESERVED_13 implicitly + 1 */;
    public static final int RESERVED_15 = 15 /* ::android::hardware::radio::V1_0::CdmaSmsNumberPlan.RESERVED_14 implicitly + 1 */;
    public static final String toString(int o) {
        if (o == UNKNOWN) {
            return "UNKNOWN";
        }
        if (o == TELEPHONY) {
            return "TELEPHONY";
        }
        if (o == RESERVED_2) {
            return "RESERVED_2";
        }
        if (o == DATA) {
            return "DATA";
        }
        if (o == TELEX) {
            return "TELEX";
        }
        if (o == RESERVED_5) {
            return "RESERVED_5";
        }
        if (o == RESERVED_6) {
            return "RESERVED_6";
        }
        if (o == RESERVED_7) {
            return "RESERVED_7";
        }
        if (o == RESERVED_8) {
            return "RESERVED_8";
        }
        if (o == PRIVATE) {
            return "PRIVATE";
        }
        if (o == RESERVED_10) {
            return "RESERVED_10";
        }
        if (o == RESERVED_11) {
            return "RESERVED_11";
        }
        if (o == RESERVED_12) {
            return "RESERVED_12";
        }
        if (o == RESERVED_13) {
            return "RESERVED_13";
        }
        if (o == RESERVED_14) {
            return "RESERVED_14";
        }
        if (o == RESERVED_15) {
            return "RESERVED_15";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("UNKNOWN"); // UNKNOWN == 0
        if ((o & TELEPHONY) == TELEPHONY) {
            list.add("TELEPHONY");
            flipped |= TELEPHONY;
        }
        if ((o & RESERVED_2) == RESERVED_2) {
            list.add("RESERVED_2");
            flipped |= RESERVED_2;
        }
        if ((o & DATA) == DATA) {
            list.add("DATA");
            flipped |= DATA;
        }
        if ((o & TELEX) == TELEX) {
            list.add("TELEX");
            flipped |= TELEX;
        }
        if ((o & RESERVED_5) == RESERVED_5) {
            list.add("RESERVED_5");
            flipped |= RESERVED_5;
        }
        if ((o & RESERVED_6) == RESERVED_6) {
            list.add("RESERVED_6");
            flipped |= RESERVED_6;
        }
        if ((o & RESERVED_7) == RESERVED_7) {
            list.add("RESERVED_7");
            flipped |= RESERVED_7;
        }
        if ((o & RESERVED_8) == RESERVED_8) {
            list.add("RESERVED_8");
            flipped |= RESERVED_8;
        }
        if ((o & PRIVATE) == PRIVATE) {
            list.add("PRIVATE");
            flipped |= PRIVATE;
        }
        if ((o & RESERVED_10) == RESERVED_10) {
            list.add("RESERVED_10");
            flipped |= RESERVED_10;
        }
        if ((o & RESERVED_11) == RESERVED_11) {
            list.add("RESERVED_11");
            flipped |= RESERVED_11;
        }
        if ((o & RESERVED_12) == RESERVED_12) {
            list.add("RESERVED_12");
            flipped |= RESERVED_12;
        }
        if ((o & RESERVED_13) == RESERVED_13) {
            list.add("RESERVED_13");
            flipped |= RESERVED_13;
        }
        if ((o & RESERVED_14) == RESERVED_14) {
            list.add("RESERVED_14");
            flipped |= RESERVED_14;
        }
        if ((o & RESERVED_15) == RESERVED_15) {
            list.add("RESERVED_15");
            flipped |= RESERVED_15;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

