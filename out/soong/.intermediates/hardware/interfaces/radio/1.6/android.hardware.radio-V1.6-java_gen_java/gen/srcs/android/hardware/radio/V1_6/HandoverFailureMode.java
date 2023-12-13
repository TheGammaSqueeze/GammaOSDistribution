package android.hardware.radio.V1_6;


public final class HandoverFailureMode {
    /**
     * On data handover failure, fallback to the source data transport when the
     * fail cause is due to a hand off preference change.
     */
    public static final byte LEGACY = 0;
    /**
     * On data handover failure, fallback to the source data transport.
     */
    public static final byte DO_FALLBACK = 1;
    /**
     * On data handover failure, retry the handover instead of falling back to
     * the source data transport.
     */
    public static final byte NO_FALLBACK_RETRY_HANDOVER = 2;
    /**
     * On data handover failure, setup a new data connection by sending a normal
     * request to the underlying data service.
     */
    public static final byte NO_FALLBACK_RETRY_SETUP_NORMAL = 3;
    public static final String toString(byte o) {
        if (o == LEGACY) {
            return "LEGACY";
        }
        if (o == DO_FALLBACK) {
            return "DO_FALLBACK";
        }
        if (o == NO_FALLBACK_RETRY_HANDOVER) {
            return "NO_FALLBACK_RETRY_HANDOVER";
        }
        if (o == NO_FALLBACK_RETRY_SETUP_NORMAL) {
            return "NO_FALLBACK_RETRY_SETUP_NORMAL";
        }
        return "0x" + Integer.toHexString(Byte.toUnsignedInt((byte)(o)));
    }

    public static final String dumpBitfield(byte o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        byte flipped = 0;
        list.add("LEGACY"); // LEGACY == 0
        if ((o & DO_FALLBACK) == DO_FALLBACK) {
            list.add("DO_FALLBACK");
            flipped |= DO_FALLBACK;
        }
        if ((o & NO_FALLBACK_RETRY_HANDOVER) == NO_FALLBACK_RETRY_HANDOVER) {
            list.add("NO_FALLBACK_RETRY_HANDOVER");
            flipped |= NO_FALLBACK_RETRY_HANDOVER;
        }
        if ((o & NO_FALLBACK_RETRY_SETUP_NORMAL) == NO_FALLBACK_RETRY_SETUP_NORMAL) {
            list.add("NO_FALLBACK_RETRY_SETUP_NORMAL");
            flipped |= NO_FALLBACK_RETRY_SETUP_NORMAL;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(Byte.toUnsignedInt((byte)(o & (~flipped)))));
        }
        return String.join(" | ", list);
    }

};

