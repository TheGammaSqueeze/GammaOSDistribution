package android.hardware.wifi.V1_0;


public final class NanDataPathSecurityType {
    public static final int OPEN = 0;
    public static final int PMK = 1 /* ::android::hardware::wifi::V1_0::NanDataPathSecurityType.OPEN implicitly + 1 */;
    public static final int PASSPHRASE = 2 /* ::android::hardware::wifi::V1_0::NanDataPathSecurityType.PMK implicitly + 1 */;
    public static final String toString(int o) {
        if (o == OPEN) {
            return "OPEN";
        }
        if (o == PMK) {
            return "PMK";
        }
        if (o == PASSPHRASE) {
            return "PASSPHRASE";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("OPEN"); // OPEN == 0
        if ((o & PMK) == PMK) {
            list.add("PMK");
            flipped |= PMK;
        }
        if ((o & PASSPHRASE) == PASSPHRASE) {
            list.add("PASSPHRASE");
            flipped |= PASSPHRASE;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

