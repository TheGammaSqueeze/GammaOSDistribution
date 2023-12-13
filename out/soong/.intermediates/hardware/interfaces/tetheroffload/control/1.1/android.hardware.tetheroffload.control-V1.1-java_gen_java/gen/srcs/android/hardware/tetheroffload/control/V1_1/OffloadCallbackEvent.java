package android.hardware.tetheroffload.control.V1_1;


public final class OffloadCallbackEvent {
    /**
     * Indicate that a working configuration has been programmed and the
     * hardware management process has begun forwarding traffic.
     */
    public static final int OFFLOAD_STARTED = 1;
    /**
     * Indicate that an error has occurred which has disrupted hardware
     * acceleration.  Software routing may still be attempted; however,
     * statistics may be temporarily unavailable.  Statistics may be recovered
     * after OFFLOAD_SUPPORT_AVAILABLE event is fired.
     */
    public static final int OFFLOAD_STOPPED_ERROR = 2;
    /**
     * Indicate that the device has moved to a RAT on which hardware
     * acceleration is not supported.  Subsequent calls to setUpstreamParameters
     * and add/removeDownstream will likely fail and cannot be presumed to be
     * saved inside of the hardware management process.  Upon receiving
     * OFFLOAD_SUPPORT_AVAIALBLE, the client may reprogram the hardware
     * management process to begin offload again.
     */
    public static final int OFFLOAD_STOPPED_UNSUPPORTED = 3;
    /**
     * Indicate that the hardware management process is willing and able to
     * provide support for hardware acceleration at this time.  If applicable,
     * the client may query for statistics.  If offload is desired, the client
     * must reprogram the hardware management process.
     */
    public static final int OFFLOAD_SUPPORT_AVAILABLE = 4;
    /**
     * Hardware acceleration is no longer in effect and must be reprogrammed
     * in order to resume.  This event is fired when the limit, applied in
     * setDataLimit, has expired.  It is recommended that the client query for
     * statistics immediately after receiving this event.
     */
    public static final int OFFLOAD_STOPPED_LIMIT_REACHED = 5;
    /**
     * This event is fired when the quota, applied in setDataWarning, has expired. It is
     * recommended that the client query for statistics immediately after receiving this event.
     * Note that hardware acceleration must not be stopped upon receiving this event.
     */
    public static final int OFFLOAD_WARNING_REACHED = 6;
    public static final String toString(int o) {
        if (o == OFFLOAD_STARTED) {
            return "OFFLOAD_STARTED";
        }
        if (o == OFFLOAD_STOPPED_ERROR) {
            return "OFFLOAD_STOPPED_ERROR";
        }
        if (o == OFFLOAD_STOPPED_UNSUPPORTED) {
            return "OFFLOAD_STOPPED_UNSUPPORTED";
        }
        if (o == OFFLOAD_SUPPORT_AVAILABLE) {
            return "OFFLOAD_SUPPORT_AVAILABLE";
        }
        if (o == OFFLOAD_STOPPED_LIMIT_REACHED) {
            return "OFFLOAD_STOPPED_LIMIT_REACHED";
        }
        if (o == OFFLOAD_WARNING_REACHED) {
            return "OFFLOAD_WARNING_REACHED";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        if ((o & OFFLOAD_STARTED) == OFFLOAD_STARTED) {
            list.add("OFFLOAD_STARTED");
            flipped |= OFFLOAD_STARTED;
        }
        if ((o & OFFLOAD_STOPPED_ERROR) == OFFLOAD_STOPPED_ERROR) {
            list.add("OFFLOAD_STOPPED_ERROR");
            flipped |= OFFLOAD_STOPPED_ERROR;
        }
        if ((o & OFFLOAD_STOPPED_UNSUPPORTED) == OFFLOAD_STOPPED_UNSUPPORTED) {
            list.add("OFFLOAD_STOPPED_UNSUPPORTED");
            flipped |= OFFLOAD_STOPPED_UNSUPPORTED;
        }
        if ((o & OFFLOAD_SUPPORT_AVAILABLE) == OFFLOAD_SUPPORT_AVAILABLE) {
            list.add("OFFLOAD_SUPPORT_AVAILABLE");
            flipped |= OFFLOAD_SUPPORT_AVAILABLE;
        }
        if ((o & OFFLOAD_STOPPED_LIMIT_REACHED) == OFFLOAD_STOPPED_LIMIT_REACHED) {
            list.add("OFFLOAD_STOPPED_LIMIT_REACHED");
            flipped |= OFFLOAD_STOPPED_LIMIT_REACHED;
        }
        if ((o & OFFLOAD_WARNING_REACHED) == OFFLOAD_WARNING_REACHED) {
            list.add("OFFLOAD_WARNING_REACHED");
            flipped |= OFFLOAD_WARNING_REACHED;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

