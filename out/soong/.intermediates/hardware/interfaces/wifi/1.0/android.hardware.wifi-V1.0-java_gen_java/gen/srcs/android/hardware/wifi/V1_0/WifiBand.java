package android.hardware.wifi.V1_0;


public final class WifiBand {
    public static final int BAND_UNSPECIFIED = 0;
    /**
     * 2.4 GHz.
     */
    public static final int BAND_24GHZ = 1;
    /**
     * 5 GHz without DFS.
     */
    public static final int BAND_5GHZ = 2;
    /**
     * 5 GHz DFS only.
     */
    public static final int BAND_5GHZ_DFS = 4;
    /**
     * 5 GHz with DFS.
     */
    public static final int BAND_5GHZ_WITH_DFS = 6;
    /**
     * 2.4 GHz + 5 GHz; no DFS.
     */
    public static final int BAND_24GHZ_5GHZ = 3;
    /**
     * 2.4 GHz + 5 GHz with DFS
     */
    public static final int BAND_24GHZ_5GHZ_WITH_DFS = 7;
    public static final String toString(int o) {
        if (o == BAND_UNSPECIFIED) {
            return "BAND_UNSPECIFIED";
        }
        if (o == BAND_24GHZ) {
            return "BAND_24GHZ";
        }
        if (o == BAND_5GHZ) {
            return "BAND_5GHZ";
        }
        if (o == BAND_5GHZ_DFS) {
            return "BAND_5GHZ_DFS";
        }
        if (o == BAND_5GHZ_WITH_DFS) {
            return "BAND_5GHZ_WITH_DFS";
        }
        if (o == BAND_24GHZ_5GHZ) {
            return "BAND_24GHZ_5GHZ";
        }
        if (o == BAND_24GHZ_5GHZ_WITH_DFS) {
            return "BAND_24GHZ_5GHZ_WITH_DFS";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("BAND_UNSPECIFIED"); // BAND_UNSPECIFIED == 0
        if ((o & BAND_24GHZ) == BAND_24GHZ) {
            list.add("BAND_24GHZ");
            flipped |= BAND_24GHZ;
        }
        if ((o & BAND_5GHZ) == BAND_5GHZ) {
            list.add("BAND_5GHZ");
            flipped |= BAND_5GHZ;
        }
        if ((o & BAND_5GHZ_DFS) == BAND_5GHZ_DFS) {
            list.add("BAND_5GHZ_DFS");
            flipped |= BAND_5GHZ_DFS;
        }
        if ((o & BAND_5GHZ_WITH_DFS) == BAND_5GHZ_WITH_DFS) {
            list.add("BAND_5GHZ_WITH_DFS");
            flipped |= BAND_5GHZ_WITH_DFS;
        }
        if ((o & BAND_24GHZ_5GHZ) == BAND_24GHZ_5GHZ) {
            list.add("BAND_24GHZ_5GHZ");
            flipped |= BAND_24GHZ_5GHZ;
        }
        if ((o & BAND_24GHZ_5GHZ_WITH_DFS) == BAND_24GHZ_5GHZ_WITH_DFS) {
            list.add("BAND_24GHZ_5GHZ_WITH_DFS");
            flipped |= BAND_24GHZ_5GHZ_WITH_DFS;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

