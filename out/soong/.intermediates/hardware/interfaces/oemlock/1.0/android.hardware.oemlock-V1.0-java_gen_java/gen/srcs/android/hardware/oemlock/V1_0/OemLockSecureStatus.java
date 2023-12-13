package android.hardware.oemlock.V1_0;


public final class OemLockSecureStatus {
    /**
     * The operation completed successfully.
     */
    public static final int OK = 0;
    /**
     * The operation encountered a problem.
     */
    public static final int FAILED = 1 /* ::android::hardware::oemlock::V1_0::OemLockStatus.OK implicitly + 1 */;
    /**
     * An invalid signature was provided so the operation was not performed.
     */
    public static final int INVALID_SIGNATURE = 2 /* ::android::hardware::oemlock::V1_0::OemLockStatus.FAILED implicitly + 1 */;
    public static final String toString(int o) {
        if (o == OK) {
            return "OK";
        }
        if (o == FAILED) {
            return "FAILED";
        }
        if (o == INVALID_SIGNATURE) {
            return "INVALID_SIGNATURE";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("OK"); // OK == 0
        if ((o & FAILED) == FAILED) {
            list.add("FAILED");
            flipped |= FAILED;
        }
        if ((o & INVALID_SIGNATURE) == INVALID_SIGNATURE) {
            list.add("INVALID_SIGNATURE");
            flipped |= INVALID_SIGNATURE;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

