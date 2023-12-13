package android.hardware.radio.V1_0;


public final class CdmaSmsNumberType {
    public static final int UNKNOWN = 0;
    public static final int INTERNATIONAL_OR_DATA_IP = 1 /* ::android::hardware::radio::V1_0::CdmaSmsNumberType.UNKNOWN implicitly + 1 */;
    public static final int NATIONAL_OR_INTERNET_MAIL = 2 /* ::android::hardware::radio::V1_0::CdmaSmsNumberType.INTERNATIONAL_OR_DATA_IP implicitly + 1 */;
    public static final int NETWORK = 3 /* ::android::hardware::radio::V1_0::CdmaSmsNumberType.NATIONAL_OR_INTERNET_MAIL implicitly + 1 */;
    public static final int SUBSCRIBER = 4 /* ::android::hardware::radio::V1_0::CdmaSmsNumberType.NETWORK implicitly + 1 */;
    public static final int ALPHANUMERIC = 5 /* ::android::hardware::radio::V1_0::CdmaSmsNumberType.SUBSCRIBER implicitly + 1 */;
    public static final int ABBREVIATED = 6 /* ::android::hardware::radio::V1_0::CdmaSmsNumberType.ALPHANUMERIC implicitly + 1 */;
    public static final int RESERVED_7 = 7 /* ::android::hardware::radio::V1_0::CdmaSmsNumberType.ABBREVIATED implicitly + 1 */;
    public static final String toString(int o) {
        if (o == UNKNOWN) {
            return "UNKNOWN";
        }
        if (o == INTERNATIONAL_OR_DATA_IP) {
            return "INTERNATIONAL_OR_DATA_IP";
        }
        if (o == NATIONAL_OR_INTERNET_MAIL) {
            return "NATIONAL_OR_INTERNET_MAIL";
        }
        if (o == NETWORK) {
            return "NETWORK";
        }
        if (o == SUBSCRIBER) {
            return "SUBSCRIBER";
        }
        if (o == ALPHANUMERIC) {
            return "ALPHANUMERIC";
        }
        if (o == ABBREVIATED) {
            return "ABBREVIATED";
        }
        if (o == RESERVED_7) {
            return "RESERVED_7";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("UNKNOWN"); // UNKNOWN == 0
        if ((o & INTERNATIONAL_OR_DATA_IP) == INTERNATIONAL_OR_DATA_IP) {
            list.add("INTERNATIONAL_OR_DATA_IP");
            flipped |= INTERNATIONAL_OR_DATA_IP;
        }
        if ((o & NATIONAL_OR_INTERNET_MAIL) == NATIONAL_OR_INTERNET_MAIL) {
            list.add("NATIONAL_OR_INTERNET_MAIL");
            flipped |= NATIONAL_OR_INTERNET_MAIL;
        }
        if ((o & NETWORK) == NETWORK) {
            list.add("NETWORK");
            flipped |= NETWORK;
        }
        if ((o & SUBSCRIBER) == SUBSCRIBER) {
            list.add("SUBSCRIBER");
            flipped |= SUBSCRIBER;
        }
        if ((o & ALPHANUMERIC) == ALPHANUMERIC) {
            list.add("ALPHANUMERIC");
            flipped |= ALPHANUMERIC;
        }
        if ((o & ABBREVIATED) == ABBREVIATED) {
            list.add("ABBREVIATED");
            flipped |= ABBREVIATED;
        }
        if ((o & RESERVED_7) == RESERVED_7) {
            list.add("RESERVED_7");
            flipped |= RESERVED_7;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

