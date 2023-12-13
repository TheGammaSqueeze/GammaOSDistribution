package android.hardware.gnss.V1_0;


public final class GnssMax {
    /**
     * Maximum number of SVs for gnssSvStatusCb().
     */
    public static final int SVS_COUNT = 64;
    public static final String toString(int o) {
        if (o == SVS_COUNT) {
            return "SVS_COUNT";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        if ((o & SVS_COUNT) == SVS_COUNT) {
            list.add("SVS_COUNT");
            flipped |= SVS_COUNT;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

