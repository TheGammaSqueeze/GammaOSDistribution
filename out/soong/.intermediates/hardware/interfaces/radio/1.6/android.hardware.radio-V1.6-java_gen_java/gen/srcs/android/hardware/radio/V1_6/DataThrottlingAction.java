package android.hardware.radio.V1_6;


public final class DataThrottlingAction {
    /*
     * Clear all existing data throttling.
     */
    public static final byte NO_DATA_THROTTLING = 0;
    /**
     * Enact secondary carrier data throttling and remove any existing data
     * throttling on anchor carrier.
     */
    public static final byte THROTTLE_SECONDARY_CARRIER = 1;
    /**
     * Enact anchor carrier data throttling and disable data on secondary
     * carrier if currently enabled.
     */
    public static final byte THROTTLE_ANCHOR_CARRIER = 2;
    /**
     * Immediately hold on to current level of throttling.
     */
    public static final byte HOLD = 3;
    public static final String toString(byte o) {
        if (o == NO_DATA_THROTTLING) {
            return "NO_DATA_THROTTLING";
        }
        if (o == THROTTLE_SECONDARY_CARRIER) {
            return "THROTTLE_SECONDARY_CARRIER";
        }
        if (o == THROTTLE_ANCHOR_CARRIER) {
            return "THROTTLE_ANCHOR_CARRIER";
        }
        if (o == HOLD) {
            return "HOLD";
        }
        return "0x" + Integer.toHexString(Byte.toUnsignedInt((byte)(o)));
    }

    public static final String dumpBitfield(byte o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        byte flipped = 0;
        list.add("NO_DATA_THROTTLING"); // NO_DATA_THROTTLING == 0
        if ((o & THROTTLE_SECONDARY_CARRIER) == THROTTLE_SECONDARY_CARRIER) {
            list.add("THROTTLE_SECONDARY_CARRIER");
            flipped |= THROTTLE_SECONDARY_CARRIER;
        }
        if ((o & THROTTLE_ANCHOR_CARRIER) == THROTTLE_ANCHOR_CARRIER) {
            list.add("THROTTLE_ANCHOR_CARRIER");
            flipped |= THROTTLE_ANCHOR_CARRIER;
        }
        if ((o & HOLD) == HOLD) {
            list.add("HOLD");
            flipped |= HOLD;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(Byte.toUnsignedInt((byte)(o & (~flipped)))));
        }
        return String.join(" | ", list);
    }

};

