package android.hardware.wifi.V1_0;


public final class WifiRateNss {
    public static final int NSS_1x1 = 0;
    public static final int NSS_2x2 = 1;
    public static final int NSS_3x3 = 2;
    public static final int NSS_4x4 = 3;
    public static final String toString(int o) {
        if (o == NSS_1x1) {
            return "NSS_1x1";
        }
        if (o == NSS_2x2) {
            return "NSS_2x2";
        }
        if (o == NSS_3x3) {
            return "NSS_3x3";
        }
        if (o == NSS_4x4) {
            return "NSS_4x4";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("NSS_1x1"); // NSS_1x1 == 0
        if ((o & NSS_2x2) == NSS_2x2) {
            list.add("NSS_2x2");
            flipped |= NSS_2x2;
        }
        if ((o & NSS_3x3) == NSS_3x3) {
            list.add("NSS_3x3");
            flipped |= NSS_3x3;
        }
        if ((o & NSS_4x4) == NSS_4x4) {
            list.add("NSS_4x4");
            flipped |= NSS_4x4;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

