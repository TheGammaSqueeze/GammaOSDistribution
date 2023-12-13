package android.hardware.wifi.supplicant.V1_3;


public final class DppProgressCode {
    public static final int AUTHENTICATION_SUCCESS = 0;
    public static final int RESPONSE_PENDING = 1 /* ::android::hardware::wifi::supplicant::V1_2::DppProgressCode.AUTHENTICATION_SUCCESS implicitly + 1 */;
    public static final int CONFIGURATION_SENT_WAITING_RESPONSE = 2 /* ::android::hardware::wifi::supplicant::V1_2::DppProgressCode.RESPONSE_PENDING implicitly + 1 */;
    public static final int CONFIGURATION_ACCEPTED = 3 /* ::android::hardware::wifi::supplicant::V1_3::DppProgressCode.CONFIGURATION_SENT_WAITING_RESPONSE implicitly + 1 */;
    public static final String toString(int o) {
        if (o == AUTHENTICATION_SUCCESS) {
            return "AUTHENTICATION_SUCCESS";
        }
        if (o == RESPONSE_PENDING) {
            return "RESPONSE_PENDING";
        }
        if (o == CONFIGURATION_SENT_WAITING_RESPONSE) {
            return "CONFIGURATION_SENT_WAITING_RESPONSE";
        }
        if (o == CONFIGURATION_ACCEPTED) {
            return "CONFIGURATION_ACCEPTED";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("AUTHENTICATION_SUCCESS"); // AUTHENTICATION_SUCCESS == 0
        if ((o & RESPONSE_PENDING) == RESPONSE_PENDING) {
            list.add("RESPONSE_PENDING");
            flipped |= RESPONSE_PENDING;
        }
        if ((o & CONFIGURATION_SENT_WAITING_RESPONSE) == CONFIGURATION_SENT_WAITING_RESPONSE) {
            list.add("CONFIGURATION_SENT_WAITING_RESPONSE");
            flipped |= CONFIGURATION_SENT_WAITING_RESPONSE;
        }
        if ((o & CONFIGURATION_ACCEPTED) == CONFIGURATION_ACCEPTED) {
            list.add("CONFIGURATION_ACCEPTED");
            flipped |= CONFIGURATION_ACCEPTED;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

