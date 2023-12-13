package android.hardware.biometrics.face.V1_0;


public final class FaceError {
    /**
     * A hardware error has occurred that cannot be resolved. Try again later.
     */
    public static final int HW_UNAVAILABLE = 1;
    /**
     * The current enroll or authenticate operation could not be completed,
     * e.g. the sensor was unable to process the current image or the HAT was
     * invalid.
     */
    public static final int UNABLE_TO_PROCESS = 2;
    /**
     * The current operation took too long to complete. This is intended to
     * prevent programs from blocking the face HAL indefinitely. The timeout is
     * framework and sensor-specific, but is generally on the order of 30
     * seconds.
     *
     * The timeout is a device-specific time meant to optimize power. For
     * example after 30 seconds of searching for a face it can be use to
     * indicate that the implementation is no longer looking and the framework
     * should restart the operation on the next user interaction.
     */
    public static final int TIMEOUT = 3;
    /**
     * The current operation could not be completed because there is not enough
     * storage space remaining to do so.
     */
    public static final int NO_SPACE = 4;
    /**
     * The current operation has been cancelled. This may happen if a new
     * request (authenticate, remove, enumerate, enroll) is initiated while
     * an on-going operation is in progress, or if cancel() was called.
     */
    public static final int CANCELED = 5;
    /**
     * The current remove operation could not be completed; the face template
     * provided could not be removed.
     */
    public static final int UNABLE_TO_REMOVE = 6;
    /**
     * Face authentication is locked out due to too many unsuccessful attempts.
     * This is a "soft" lockout, and authentication can be restarted after
     * a period of time, generally on the order of 30 seconds.
     */
    public static final int LOCKOUT = 7;
    /**
     * Used to enable a vendor-specific error message.
     */
    public static final int VENDOR = 8;
    /**
     * Face authentication is disabled until the user unlocks with strong
     * authentication (PIN/Pattern/Password).
     */
    public static final int LOCKOUT_PERMANENT = 9;
    public static final String toString(int o) {
        if (o == HW_UNAVAILABLE) {
            return "HW_UNAVAILABLE";
        }
        if (o == UNABLE_TO_PROCESS) {
            return "UNABLE_TO_PROCESS";
        }
        if (o == TIMEOUT) {
            return "TIMEOUT";
        }
        if (o == NO_SPACE) {
            return "NO_SPACE";
        }
        if (o == CANCELED) {
            return "CANCELED";
        }
        if (o == UNABLE_TO_REMOVE) {
            return "UNABLE_TO_REMOVE";
        }
        if (o == LOCKOUT) {
            return "LOCKOUT";
        }
        if (o == VENDOR) {
            return "VENDOR";
        }
        if (o == LOCKOUT_PERMANENT) {
            return "LOCKOUT_PERMANENT";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        if ((o & HW_UNAVAILABLE) == HW_UNAVAILABLE) {
            list.add("HW_UNAVAILABLE");
            flipped |= HW_UNAVAILABLE;
        }
        if ((o & UNABLE_TO_PROCESS) == UNABLE_TO_PROCESS) {
            list.add("UNABLE_TO_PROCESS");
            flipped |= UNABLE_TO_PROCESS;
        }
        if ((o & TIMEOUT) == TIMEOUT) {
            list.add("TIMEOUT");
            flipped |= TIMEOUT;
        }
        if ((o & NO_SPACE) == NO_SPACE) {
            list.add("NO_SPACE");
            flipped |= NO_SPACE;
        }
        if ((o & CANCELED) == CANCELED) {
            list.add("CANCELED");
            flipped |= CANCELED;
        }
        if ((o & UNABLE_TO_REMOVE) == UNABLE_TO_REMOVE) {
            list.add("UNABLE_TO_REMOVE");
            flipped |= UNABLE_TO_REMOVE;
        }
        if ((o & LOCKOUT) == LOCKOUT) {
            list.add("LOCKOUT");
            flipped |= LOCKOUT;
        }
        if ((o & VENDOR) == VENDOR) {
            list.add("VENDOR");
            flipped |= VENDOR;
        }
        if ((o & LOCKOUT_PERMANENT) == LOCKOUT_PERMANENT) {
            list.add("LOCKOUT_PERMANENT");
            flipped |= LOCKOUT_PERMANENT;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

