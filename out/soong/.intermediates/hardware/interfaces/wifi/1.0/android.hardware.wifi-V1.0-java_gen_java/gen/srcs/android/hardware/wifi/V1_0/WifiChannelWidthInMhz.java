package android.hardware.wifi.V1_0;


public final class WifiChannelWidthInMhz {
    public static final int WIDTH_20 = 0;
    public static final int WIDTH_40 = 1;
    public static final int WIDTH_80 = 2;
    public static final int WIDTH_160 = 3;
    public static final int WIDTH_80P80 = 4;
    public static final int WIDTH_5 = 5;
    public static final int WIDTH_10 = 6;
    public static final int WIDTH_INVALID = -1 /* -1 */;
    public static final String toString(int o) {
        if (o == WIDTH_20) {
            return "WIDTH_20";
        }
        if (o == WIDTH_40) {
            return "WIDTH_40";
        }
        if (o == WIDTH_80) {
            return "WIDTH_80";
        }
        if (o == WIDTH_160) {
            return "WIDTH_160";
        }
        if (o == WIDTH_80P80) {
            return "WIDTH_80P80";
        }
        if (o == WIDTH_5) {
            return "WIDTH_5";
        }
        if (o == WIDTH_10) {
            return "WIDTH_10";
        }
        if (o == WIDTH_INVALID) {
            return "WIDTH_INVALID";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("WIDTH_20"); // WIDTH_20 == 0
        if ((o & WIDTH_40) == WIDTH_40) {
            list.add("WIDTH_40");
            flipped |= WIDTH_40;
        }
        if ((o & WIDTH_80) == WIDTH_80) {
            list.add("WIDTH_80");
            flipped |= WIDTH_80;
        }
        if ((o & WIDTH_160) == WIDTH_160) {
            list.add("WIDTH_160");
            flipped |= WIDTH_160;
        }
        if ((o & WIDTH_80P80) == WIDTH_80P80) {
            list.add("WIDTH_80P80");
            flipped |= WIDTH_80P80;
        }
        if ((o & WIDTH_5) == WIDTH_5) {
            list.add("WIDTH_5");
            flipped |= WIDTH_5;
        }
        if ((o & WIDTH_10) == WIDTH_10) {
            list.add("WIDTH_10");
            flipped |= WIDTH_10;
        }
        if ((o & WIDTH_INVALID) == WIDTH_INVALID) {
            list.add("WIDTH_INVALID");
            flipped |= WIDTH_INVALID;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

