package android.hardware.wifi.V1_0;


public final class NanCipherSuiteType {
    public static final int NONE = 0;
    public static final int SHARED_KEY_128_MASK = 1 /* 1 << 0 */;
    public static final int SHARED_KEY_256_MASK = 2 /* 1 << 1 */;
    public static final String toString(int o) {
        if (o == NONE) {
            return "NONE";
        }
        if (o == SHARED_KEY_128_MASK) {
            return "SHARED_KEY_128_MASK";
        }
        if (o == SHARED_KEY_256_MASK) {
            return "SHARED_KEY_256_MASK";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("NONE"); // NONE == 0
        if ((o & SHARED_KEY_128_MASK) == SHARED_KEY_128_MASK) {
            list.add("SHARED_KEY_128_MASK");
            flipped |= SHARED_KEY_128_MASK;
        }
        if ((o & SHARED_KEY_256_MASK) == SHARED_KEY_256_MASK) {
            list.add("SHARED_KEY_256_MASK");
            flipped |= SHARED_KEY_256_MASK;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

