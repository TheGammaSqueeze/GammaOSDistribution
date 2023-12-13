package android.hardware.radio.V1_0;


public final class SsTeleserviceType {
    public static final int ALL_TELE_AND_BEARER_SERVICES = 0;
    public static final int ALL_TELESEVICES = 1 /* ::android::hardware::radio::V1_0::SsTeleserviceType.ALL_TELE_AND_BEARER_SERVICES implicitly + 1 */;
    public static final int TELEPHONY = 2 /* ::android::hardware::radio::V1_0::SsTeleserviceType.ALL_TELESEVICES implicitly + 1 */;
    public static final int ALL_DATA_TELESERVICES = 3 /* ::android::hardware::radio::V1_0::SsTeleserviceType.TELEPHONY implicitly + 1 */;
    public static final int SMS_SERVICES = 4 /* ::android::hardware::radio::V1_0::SsTeleserviceType.ALL_DATA_TELESERVICES implicitly + 1 */;
    public static final int ALL_TELESERVICES_EXCEPT_SMS = 5 /* ::android::hardware::radio::V1_0::SsTeleserviceType.SMS_SERVICES implicitly + 1 */;
    public static final String toString(int o) {
        if (o == ALL_TELE_AND_BEARER_SERVICES) {
            return "ALL_TELE_AND_BEARER_SERVICES";
        }
        if (o == ALL_TELESEVICES) {
            return "ALL_TELESEVICES";
        }
        if (o == TELEPHONY) {
            return "TELEPHONY";
        }
        if (o == ALL_DATA_TELESERVICES) {
            return "ALL_DATA_TELESERVICES";
        }
        if (o == SMS_SERVICES) {
            return "SMS_SERVICES";
        }
        if (o == ALL_TELESERVICES_EXCEPT_SMS) {
            return "ALL_TELESERVICES_EXCEPT_SMS";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("ALL_TELE_AND_BEARER_SERVICES"); // ALL_TELE_AND_BEARER_SERVICES == 0
        if ((o & ALL_TELESEVICES) == ALL_TELESEVICES) {
            list.add("ALL_TELESEVICES");
            flipped |= ALL_TELESEVICES;
        }
        if ((o & TELEPHONY) == TELEPHONY) {
            list.add("TELEPHONY");
            flipped |= TELEPHONY;
        }
        if ((o & ALL_DATA_TELESERVICES) == ALL_DATA_TELESERVICES) {
            list.add("ALL_DATA_TELESERVICES");
            flipped |= ALL_DATA_TELESERVICES;
        }
        if ((o & SMS_SERVICES) == SMS_SERVICES) {
            list.add("SMS_SERVICES");
            flipped |= SMS_SERVICES;
        }
        if ((o & ALL_TELESERVICES_EXCEPT_SMS) == ALL_TELESERVICES_EXCEPT_SMS) {
            list.add("ALL_TELESERVICES_EXCEPT_SMS");
            flipped |= ALL_TELESERVICES_EXCEPT_SMS;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

