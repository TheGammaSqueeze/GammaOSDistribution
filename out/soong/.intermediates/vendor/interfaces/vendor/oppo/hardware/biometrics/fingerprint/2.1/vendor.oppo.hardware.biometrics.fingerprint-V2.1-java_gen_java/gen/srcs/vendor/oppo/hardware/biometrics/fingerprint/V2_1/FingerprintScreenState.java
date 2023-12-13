package vendor.oppo.hardware.biometrics.fingerprint.V2_1;


public final class FingerprintScreenState {
    public static final int FINGERPRINT_SCREEN_OFF = 0;
    public static final int FINGERPRINT_SCREEN_ON = 1;
    public static final String toString(int o) {
        if (o == FINGERPRINT_SCREEN_OFF) {
            return "FINGERPRINT_SCREEN_OFF";
        }
        if (o == FINGERPRINT_SCREEN_ON) {
            return "FINGERPRINT_SCREEN_ON";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("FINGERPRINT_SCREEN_OFF"); // FINGERPRINT_SCREEN_OFF == 0
        if ((o & FINGERPRINT_SCREEN_ON) == FINGERPRINT_SCREEN_ON) {
            list.add("FINGERPRINT_SCREEN_ON");
            flipped |= FINGERPRINT_SCREEN_ON;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

