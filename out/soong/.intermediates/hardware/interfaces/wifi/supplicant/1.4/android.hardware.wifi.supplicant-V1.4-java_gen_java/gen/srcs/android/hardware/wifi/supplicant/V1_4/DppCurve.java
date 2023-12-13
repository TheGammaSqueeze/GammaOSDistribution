package android.hardware.wifi.supplicant.V1_4;


public final class DppCurve {
    public static final int PRIME256V1 = 0;
    public static final int SECP384R1 = 1 /* ::android::hardware::wifi::supplicant::V1_4::DppCurve.PRIME256V1 implicitly + 1 */;
    public static final int SECP521R1 = 2 /* ::android::hardware::wifi::supplicant::V1_4::DppCurve.SECP384R1 implicitly + 1 */;
    public static final int BRAINPOOLP256R1 = 3 /* ::android::hardware::wifi::supplicant::V1_4::DppCurve.SECP521R1 implicitly + 1 */;
    public static final int BRAINPOOLP384R1 = 4 /* ::android::hardware::wifi::supplicant::V1_4::DppCurve.BRAINPOOLP256R1 implicitly + 1 */;
    public static final int BRAINPOOLP512R1 = 5 /* ::android::hardware::wifi::supplicant::V1_4::DppCurve.BRAINPOOLP384R1 implicitly + 1 */;
    public static final String toString(int o) {
        if (o == PRIME256V1) {
            return "PRIME256V1";
        }
        if (o == SECP384R1) {
            return "SECP384R1";
        }
        if (o == SECP521R1) {
            return "SECP521R1";
        }
        if (o == BRAINPOOLP256R1) {
            return "BRAINPOOLP256R1";
        }
        if (o == BRAINPOOLP384R1) {
            return "BRAINPOOLP384R1";
        }
        if (o == BRAINPOOLP512R1) {
            return "BRAINPOOLP512R1";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("PRIME256V1"); // PRIME256V1 == 0
        if ((o & SECP384R1) == SECP384R1) {
            list.add("SECP384R1");
            flipped |= SECP384R1;
        }
        if ((o & SECP521R1) == SECP521R1) {
            list.add("SECP521R1");
            flipped |= SECP521R1;
        }
        if ((o & BRAINPOOLP256R1) == BRAINPOOLP256R1) {
            list.add("BRAINPOOLP256R1");
            flipped |= BRAINPOOLP256R1;
        }
        if ((o & BRAINPOOLP384R1) == BRAINPOOLP384R1) {
            list.add("BRAINPOOLP384R1");
            flipped |= BRAINPOOLP384R1;
        }
        if ((o & BRAINPOOLP512R1) == BRAINPOOLP512R1) {
            list.add("BRAINPOOLP512R1");
            flipped |= BRAINPOOLP512R1;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

