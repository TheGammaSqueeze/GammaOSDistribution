package android.hardware.wifi.V1_0;


public final class NanParamSizeLimits {
    /**
     * Minimum length of Passphrase argument for data-path configuration
     */
    public static final int MIN_PASSPHRASE_LENGTH = 8;
    /**
     * Maximum length of Passphrase argument for data-path configuration
     */
    public static final int MAX_PASSPHRASE_LENGTH = 63;
    public static final String toString(int o) {
        if (o == MIN_PASSPHRASE_LENGTH) {
            return "MIN_PASSPHRASE_LENGTH";
        }
        if (o == MAX_PASSPHRASE_LENGTH) {
            return "MAX_PASSPHRASE_LENGTH";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        if ((o & MIN_PASSPHRASE_LENGTH) == MIN_PASSPHRASE_LENGTH) {
            list.add("MIN_PASSPHRASE_LENGTH");
            flipped |= MIN_PASSPHRASE_LENGTH;
        }
        if ((o & MAX_PASSPHRASE_LENGTH) == MAX_PASSPHRASE_LENGTH) {
            list.add("MAX_PASSPHRASE_LENGTH");
            flipped |= MAX_PASSPHRASE_LENGTH;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

