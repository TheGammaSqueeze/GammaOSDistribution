package vendor.oppo.hardware.biometrics.fingerprint.V2_1;


public final class FingerprintAuthType {
    public static final int TYPE_KEYGUARD = 1;
    public static final int TYPE_PAY = 2;
    public static final int TYPE_OTHER = 3;
    public static final String toString(int o) {
        if (o == TYPE_KEYGUARD) {
            return "TYPE_KEYGUARD";
        }
        if (o == TYPE_PAY) {
            return "TYPE_PAY";
        }
        if (o == TYPE_OTHER) {
            return "TYPE_OTHER";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        if ((o & TYPE_KEYGUARD) == TYPE_KEYGUARD) {
            list.add("TYPE_KEYGUARD");
            flipped |= TYPE_KEYGUARD;
        }
        if ((o & TYPE_PAY) == TYPE_PAY) {
            list.add("TYPE_PAY");
            flipped |= TYPE_PAY;
        }
        if ((o & TYPE_OTHER) == TYPE_OTHER) {
            list.add("TYPE_OTHER");
            flipped |= TYPE_OTHER;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

