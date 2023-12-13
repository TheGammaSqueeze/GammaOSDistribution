package android.hardware.biometrics.fingerprint.V2_1;


public final class FingerprintAcquiredInfo {
    public static final int ACQUIRED_GOOD = 0;
    /**
     * sensor needs more data, i.e. longer swipe.
     */
    public static final int ACQUIRED_PARTIAL = 1;
    /**
     * image doesn't contain enough detail for recognition
     */
    public static final int ACQUIRED_INSUFFICIENT = 2;
    /**
     * sensor needs to be cleaned
     */
    public static final int ACQUIRED_IMAGER_DIRTY = 3;
    /**
     * mostly swipe-type sensors; not enough data collected
     */
    public static final int ACQUIRED_TOO_SLOW = 4;
    /**
     * vendor-specific acquisition messages start here
     */
    public static final int ACQUIRED_TOO_FAST = 5;
    /**
     * vendor-specific acquisition messages
     */
    public static final int ACQUIRED_VENDOR = 6;
    public static final String toString(int o) {
        if (o == ACQUIRED_GOOD) {
            return "ACQUIRED_GOOD";
        }
        if (o == ACQUIRED_PARTIAL) {
            return "ACQUIRED_PARTIAL";
        }
        if (o == ACQUIRED_INSUFFICIENT) {
            return "ACQUIRED_INSUFFICIENT";
        }
        if (o == ACQUIRED_IMAGER_DIRTY) {
            return "ACQUIRED_IMAGER_DIRTY";
        }
        if (o == ACQUIRED_TOO_SLOW) {
            return "ACQUIRED_TOO_SLOW";
        }
        if (o == ACQUIRED_TOO_FAST) {
            return "ACQUIRED_TOO_FAST";
        }
        if (o == ACQUIRED_VENDOR) {
            return "ACQUIRED_VENDOR";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("ACQUIRED_GOOD"); // ACQUIRED_GOOD == 0
        if ((o & ACQUIRED_PARTIAL) == ACQUIRED_PARTIAL) {
            list.add("ACQUIRED_PARTIAL");
            flipped |= ACQUIRED_PARTIAL;
        }
        if ((o & ACQUIRED_INSUFFICIENT) == ACQUIRED_INSUFFICIENT) {
            list.add("ACQUIRED_INSUFFICIENT");
            flipped |= ACQUIRED_INSUFFICIENT;
        }
        if ((o & ACQUIRED_IMAGER_DIRTY) == ACQUIRED_IMAGER_DIRTY) {
            list.add("ACQUIRED_IMAGER_DIRTY");
            flipped |= ACQUIRED_IMAGER_DIRTY;
        }
        if ((o & ACQUIRED_TOO_SLOW) == ACQUIRED_TOO_SLOW) {
            list.add("ACQUIRED_TOO_SLOW");
            flipped |= ACQUIRED_TOO_SLOW;
        }
        if ((o & ACQUIRED_TOO_FAST) == ACQUIRED_TOO_FAST) {
            list.add("ACQUIRED_TOO_FAST");
            flipped |= ACQUIRED_TOO_FAST;
        }
        if ((o & ACQUIRED_VENDOR) == ACQUIRED_VENDOR) {
            list.add("ACQUIRED_VENDOR");
            flipped |= ACQUIRED_VENDOR;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

