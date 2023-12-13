package android.hardware.wifi.supplicant.V1_2;


public final class DppProgressCode {
    public static final int AUTHENTICATION_SUCCESS = 0;
    public static final int RESPONSE_PENDING = 1 /* ::android::hardware::wifi::supplicant::V1_2::DppProgressCode.AUTHENTICATION_SUCCESS implicitly + 1 */;
    public static final String toString(int o) {
        if (o == AUTHENTICATION_SUCCESS) {
            return "AUTHENTICATION_SUCCESS";
        }
        if (o == RESPONSE_PENDING) {
            return "RESPONSE_PENDING";
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
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

