package android.hardware.wifi.supplicant.V1_2;


public final class DppFailureCode {
    public static final int INVALID_URI = 0;
    public static final int AUTHENTICATION = 1 /* ::android::hardware::wifi::supplicant::V1_2::DppFailureCode.INVALID_URI implicitly + 1 */;
    public static final int NOT_COMPATIBLE = 2 /* ::android::hardware::wifi::supplicant::V1_2::DppFailureCode.AUTHENTICATION implicitly + 1 */;
    public static final int CONFIGURATION = 3 /* ::android::hardware::wifi::supplicant::V1_2::DppFailureCode.NOT_COMPATIBLE implicitly + 1 */;
    public static final int BUSY = 4 /* ::android::hardware::wifi::supplicant::V1_2::DppFailureCode.CONFIGURATION implicitly + 1 */;
    public static final int TIMEOUT = 5 /* ::android::hardware::wifi::supplicant::V1_2::DppFailureCode.BUSY implicitly + 1 */;
    public static final int FAILURE = 6 /* ::android::hardware::wifi::supplicant::V1_2::DppFailureCode.TIMEOUT implicitly + 1 */;
    public static final int NOT_SUPPORTED = 7 /* ::android::hardware::wifi::supplicant::V1_2::DppFailureCode.FAILURE implicitly + 1 */;
    public static final String toString(int o) {
        if (o == INVALID_URI) {
            return "INVALID_URI";
        }
        if (o == AUTHENTICATION) {
            return "AUTHENTICATION";
        }
        if (o == NOT_COMPATIBLE) {
            return "NOT_COMPATIBLE";
        }
        if (o == CONFIGURATION) {
            return "CONFIGURATION";
        }
        if (o == BUSY) {
            return "BUSY";
        }
        if (o == TIMEOUT) {
            return "TIMEOUT";
        }
        if (o == FAILURE) {
            return "FAILURE";
        }
        if (o == NOT_SUPPORTED) {
            return "NOT_SUPPORTED";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("INVALID_URI"); // INVALID_URI == 0
        if ((o & AUTHENTICATION) == AUTHENTICATION) {
            list.add("AUTHENTICATION");
            flipped |= AUTHENTICATION;
        }
        if ((o & NOT_COMPATIBLE) == NOT_COMPATIBLE) {
            list.add("NOT_COMPATIBLE");
            flipped |= NOT_COMPATIBLE;
        }
        if ((o & CONFIGURATION) == CONFIGURATION) {
            list.add("CONFIGURATION");
            flipped |= CONFIGURATION;
        }
        if ((o & BUSY) == BUSY) {
            list.add("BUSY");
            flipped |= BUSY;
        }
        if ((o & TIMEOUT) == TIMEOUT) {
            list.add("TIMEOUT");
            flipped |= TIMEOUT;
        }
        if ((o & FAILURE) == FAILURE) {
            list.add("FAILURE");
            flipped |= FAILURE;
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

