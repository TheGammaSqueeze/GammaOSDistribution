package android.hardware.wifi.hostapd.V1_3;


public final class Bandwidth {
    public static final int WIFI_BANDWIDTH_INVALID = 0;
    public static final int WIFI_BANDWIDTH_20_NOHT = 1;
    public static final int WIFI_BANDWIDTH_20 = 2;
    public static final int WIFI_BANDWIDTH_40 = 3;
    public static final int WIFI_BANDWIDTH_80 = 4;
    public static final int WIFI_BANDWIDTH_80P80 = 5;
    public static final int WIFI_BANDWIDTH_160 = 6;
    public static final int WIFI_BANDWIDTH_2160 = 7;
    public static final int WIFI_BANDWIDTH_4320 = 8;
    public static final int WIFI_BANDWIDTH_6480 = 9;
    public static final int WIFI_BANDWIDTH_8640 = 10;
    public static final String toString(int o) {
        if (o == WIFI_BANDWIDTH_INVALID) {
            return "WIFI_BANDWIDTH_INVALID";
        }
        if (o == WIFI_BANDWIDTH_20_NOHT) {
            return "WIFI_BANDWIDTH_20_NOHT";
        }
        if (o == WIFI_BANDWIDTH_20) {
            return "WIFI_BANDWIDTH_20";
        }
        if (o == WIFI_BANDWIDTH_40) {
            return "WIFI_BANDWIDTH_40";
        }
        if (o == WIFI_BANDWIDTH_80) {
            return "WIFI_BANDWIDTH_80";
        }
        if (o == WIFI_BANDWIDTH_80P80) {
            return "WIFI_BANDWIDTH_80P80";
        }
        if (o == WIFI_BANDWIDTH_160) {
            return "WIFI_BANDWIDTH_160";
        }
        if (o == WIFI_BANDWIDTH_2160) {
            return "WIFI_BANDWIDTH_2160";
        }
        if (o == WIFI_BANDWIDTH_4320) {
            return "WIFI_BANDWIDTH_4320";
        }
        if (o == WIFI_BANDWIDTH_6480) {
            return "WIFI_BANDWIDTH_6480";
        }
        if (o == WIFI_BANDWIDTH_8640) {
            return "WIFI_BANDWIDTH_8640";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("WIFI_BANDWIDTH_INVALID"); // WIFI_BANDWIDTH_INVALID == 0
        if ((o & WIFI_BANDWIDTH_20_NOHT) == WIFI_BANDWIDTH_20_NOHT) {
            list.add("WIFI_BANDWIDTH_20_NOHT");
            flipped |= WIFI_BANDWIDTH_20_NOHT;
        }
        if ((o & WIFI_BANDWIDTH_20) == WIFI_BANDWIDTH_20) {
            list.add("WIFI_BANDWIDTH_20");
            flipped |= WIFI_BANDWIDTH_20;
        }
        if ((o & WIFI_BANDWIDTH_40) == WIFI_BANDWIDTH_40) {
            list.add("WIFI_BANDWIDTH_40");
            flipped |= WIFI_BANDWIDTH_40;
        }
        if ((o & WIFI_BANDWIDTH_80) == WIFI_BANDWIDTH_80) {
            list.add("WIFI_BANDWIDTH_80");
            flipped |= WIFI_BANDWIDTH_80;
        }
        if ((o & WIFI_BANDWIDTH_80P80) == WIFI_BANDWIDTH_80P80) {
            list.add("WIFI_BANDWIDTH_80P80");
            flipped |= WIFI_BANDWIDTH_80P80;
        }
        if ((o & WIFI_BANDWIDTH_160) == WIFI_BANDWIDTH_160) {
            list.add("WIFI_BANDWIDTH_160");
            flipped |= WIFI_BANDWIDTH_160;
        }
        if ((o & WIFI_BANDWIDTH_2160) == WIFI_BANDWIDTH_2160) {
            list.add("WIFI_BANDWIDTH_2160");
            flipped |= WIFI_BANDWIDTH_2160;
        }
        if ((o & WIFI_BANDWIDTH_4320) == WIFI_BANDWIDTH_4320) {
            list.add("WIFI_BANDWIDTH_4320");
            flipped |= WIFI_BANDWIDTH_4320;
        }
        if ((o & WIFI_BANDWIDTH_6480) == WIFI_BANDWIDTH_6480) {
            list.add("WIFI_BANDWIDTH_6480");
            flipped |= WIFI_BANDWIDTH_6480;
        }
        if ((o & WIFI_BANDWIDTH_8640) == WIFI_BANDWIDTH_8640) {
            list.add("WIFI_BANDWIDTH_8640");
            flipped |= WIFI_BANDWIDTH_8640;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

