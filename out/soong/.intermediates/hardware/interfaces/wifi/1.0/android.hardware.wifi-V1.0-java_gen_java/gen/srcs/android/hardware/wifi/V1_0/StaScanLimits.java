package android.hardware.wifi.V1_0;


public final class StaScanLimits {
    public static final int MAX_CHANNELS = 16;
    public static final int MAX_BUCKETS = 16;
    public static final int MAX_AP_CACHE_PER_SCAN = 32;
    public static final String toString(int o) {
        if (o == MAX_CHANNELS) {
            return "MAX_CHANNELS";
        }
        if (o == MAX_BUCKETS) {
            return "MAX_BUCKETS";
        }
        if (o == MAX_AP_CACHE_PER_SCAN) {
            return "MAX_AP_CACHE_PER_SCAN";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        if ((o & MAX_CHANNELS) == MAX_CHANNELS) {
            list.add("MAX_CHANNELS");
            flipped |= MAX_CHANNELS;
        }
        if ((o & MAX_BUCKETS) == MAX_BUCKETS) {
            list.add("MAX_BUCKETS");
            flipped |= MAX_BUCKETS;
        }
        if ((o & MAX_AP_CACHE_PER_SCAN) == MAX_AP_CACHE_PER_SCAN) {
            list.add("MAX_AP_CACHE_PER_SCAN");
            flipped |= MAX_AP_CACHE_PER_SCAN;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

