package android.hardware.wifi.V1_0;


public final class WifiDebugRingBufferVerboseLevel {
    /**
     * Level 0 corresponds to no collection, and it makes log handler
     * stop by no more events from driver.
     */
    public static final int NONE = 0;
    /**
     * Level 1 correspond to normal log level, with minimal user impact.
     * This is the default value.
     */
    public static final int DEFAULT = 1;
    /**
     * Level 2 is enabled when user is lazily trying to reproduce a problem,
     * wifi performances and power can be impacted but device should not
     * otherwise be significantly impacted.
     */
    public static final int VERBOSE = 2;
    /**
     * Level 3 is used when trying to actively debug a problem.
     * This will cause sever performance degradation.
     */
    public static final int EXCESSIVE = 3;
    public static final String toString(int o) {
        if (o == NONE) {
            return "NONE";
        }
        if (o == DEFAULT) {
            return "DEFAULT";
        }
        if (o == VERBOSE) {
            return "VERBOSE";
        }
        if (o == EXCESSIVE) {
            return "EXCESSIVE";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("NONE"); // NONE == 0
        if ((o & DEFAULT) == DEFAULT) {
            list.add("DEFAULT");
            flipped |= DEFAULT;
        }
        if ((o & VERBOSE) == VERBOSE) {
            list.add("VERBOSE");
            flipped |= VERBOSE;
        }
        if ((o & EXCESSIVE) == EXCESSIVE) {
            list.add("EXCESSIVE");
            flipped |= EXCESSIVE;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

