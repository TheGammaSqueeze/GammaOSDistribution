package android.hardware.wifi.hostapd.V1_3;


public final class Generation {
    public static final int WIFI_STANDARD_UNKNOWN = -1 /* -1 */;
    public static final int WIFI_STANDARD_LEGACY = 0;
    public static final int WIFI_STANDARD_11N = 1;
    public static final int WIFI_STANDARD_11AC = 2;
    public static final int WIFI_STANDARD_11AX = 3;
    public static final int WIFI_STANDARD_11AD = 4;
    public static final String toString(int o) {
        if (o == WIFI_STANDARD_UNKNOWN) {
            return "WIFI_STANDARD_UNKNOWN";
        }
        if (o == WIFI_STANDARD_LEGACY) {
            return "WIFI_STANDARD_LEGACY";
        }
        if (o == WIFI_STANDARD_11N) {
            return "WIFI_STANDARD_11N";
        }
        if (o == WIFI_STANDARD_11AC) {
            return "WIFI_STANDARD_11AC";
        }
        if (o == WIFI_STANDARD_11AX) {
            return "WIFI_STANDARD_11AX";
        }
        if (o == WIFI_STANDARD_11AD) {
            return "WIFI_STANDARD_11AD";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        if ((o & WIFI_STANDARD_UNKNOWN) == WIFI_STANDARD_UNKNOWN) {
            list.add("WIFI_STANDARD_UNKNOWN");
            flipped |= WIFI_STANDARD_UNKNOWN;
        }
        list.add("WIFI_STANDARD_LEGACY"); // WIFI_STANDARD_LEGACY == 0
        if ((o & WIFI_STANDARD_11N) == WIFI_STANDARD_11N) {
            list.add("WIFI_STANDARD_11N");
            flipped |= WIFI_STANDARD_11N;
        }
        if ((o & WIFI_STANDARD_11AC) == WIFI_STANDARD_11AC) {
            list.add("WIFI_STANDARD_11AC");
            flipped |= WIFI_STANDARD_11AC;
        }
        if ((o & WIFI_STANDARD_11AX) == WIFI_STANDARD_11AX) {
            list.add("WIFI_STANDARD_11AX");
            flipped |= WIFI_STANDARD_11AX;
        }
        if ((o & WIFI_STANDARD_11AD) == WIFI_STANDARD_11AD) {
            list.add("WIFI_STANDARD_11AD");
            flipped |= WIFI_STANDARD_11AD;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

