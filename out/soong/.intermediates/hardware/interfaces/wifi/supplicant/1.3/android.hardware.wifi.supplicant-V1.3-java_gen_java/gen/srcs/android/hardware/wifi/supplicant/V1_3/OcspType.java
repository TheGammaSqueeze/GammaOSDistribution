package android.hardware.wifi.supplicant.V1_3;


public final class OcspType {
    public static final int NONE = 0;
    public static final int REQUEST_CERT_STATUS = 1 /* ::android::hardware::wifi::supplicant::V1_3::OcspType.NONE implicitly + 1 */;
    public static final int REQUIRE_CERT_STATUS = 2 /* ::android::hardware::wifi::supplicant::V1_3::OcspType.REQUEST_CERT_STATUS implicitly + 1 */;
    public static final int REQUIRE_ALL_CERTS_STATUS = 3 /* ::android::hardware::wifi::supplicant::V1_3::OcspType.REQUIRE_CERT_STATUS implicitly + 1 */;
    public static final String toString(int o) {
        if (o == NONE) {
            return "NONE";
        }
        if (o == REQUEST_CERT_STATUS) {
            return "REQUEST_CERT_STATUS";
        }
        if (o == REQUIRE_CERT_STATUS) {
            return "REQUIRE_CERT_STATUS";
        }
        if (o == REQUIRE_ALL_CERTS_STATUS) {
            return "REQUIRE_ALL_CERTS_STATUS";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("NONE"); // NONE == 0
        if ((o & REQUEST_CERT_STATUS) == REQUEST_CERT_STATUS) {
            list.add("REQUEST_CERT_STATUS");
            flipped |= REQUEST_CERT_STATUS;
        }
        if ((o & REQUIRE_CERT_STATUS) == REQUIRE_CERT_STATUS) {
            list.add("REQUIRE_CERT_STATUS");
            flipped |= REQUIRE_CERT_STATUS;
        }
        if ((o & REQUIRE_ALL_CERTS_STATUS) == REQUIRE_ALL_CERTS_STATUS) {
            list.add("REQUIRE_ALL_CERTS_STATUS");
            flipped |= REQUIRE_ALL_CERTS_STATUS;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

