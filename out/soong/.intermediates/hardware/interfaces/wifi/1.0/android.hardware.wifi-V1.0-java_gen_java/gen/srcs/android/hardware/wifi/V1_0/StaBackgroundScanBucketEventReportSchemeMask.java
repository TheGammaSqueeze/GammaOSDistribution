package android.hardware.wifi.V1_0;


public final class StaBackgroundScanBucketEventReportSchemeMask {
    /**
     * Report a scan completion event after scan. If this is not set then scan
     * completion events must be reported if report_threshold_percent or
     * report_threshold_num_scans is reached.
     */
    public static final int EACH_SCAN = 1 /* 1 << 0 */;
    /**
     * Forward scan results (beacons/probe responses + IEs) in real time to HAL,
     * in addition to completion events.
     * Note: To keep backward compatibility, fire completion events regardless
     * of REPORT_EVENTS_EACH_SCAN.
     */
    public static final int FULL_RESULTS = 2 /* 1 << 1 */;
    /**
     * Controls if scans for this bucket must be placed in the results buffer.
     */
    public static final int NO_BATCH = 4 /* 1 << 2 */;
    public static final String toString(int o) {
        if (o == EACH_SCAN) {
            return "EACH_SCAN";
        }
        if (o == FULL_RESULTS) {
            return "FULL_RESULTS";
        }
        if (o == NO_BATCH) {
            return "NO_BATCH";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        if ((o & EACH_SCAN) == EACH_SCAN) {
            list.add("EACH_SCAN");
            flipped |= EACH_SCAN;
        }
        if ((o & FULL_RESULTS) == FULL_RESULTS) {
            list.add("FULL_RESULTS");
            flipped |= FULL_RESULTS;
        }
        if ((o & NO_BATCH) == NO_BATCH) {
            list.add("NO_BATCH");
            flipped |= NO_BATCH;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

