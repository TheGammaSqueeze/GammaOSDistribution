package android.hardware.radio.V1_2;


public final class IncrementalResultsPeriodicityRange {
    public static final int MIN = 1;
    public static final int MAX = 10;
    public static final String toString(int o) {
        if (o == MIN) {
            return "MIN";
        }
        if (o == MAX) {
            return "MAX";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        if ((o & MIN) == MIN) {
            list.add("MIN");
            flipped |= MIN;
        }
        if ((o & MAX) == MAX) {
            list.add("MAX");
            flipped |= MAX;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

