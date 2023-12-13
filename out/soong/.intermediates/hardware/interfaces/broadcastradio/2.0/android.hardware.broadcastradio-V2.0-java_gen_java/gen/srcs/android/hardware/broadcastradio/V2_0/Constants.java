package android.hardware.broadcastradio.V2_0;


public final class Constants {
    /**
     * Invalid identifier for IBroadcastRadio::getImage.
     */
    public static final int INVALID_IMAGE = 0;
    /**
     * If the antenna is disconnected from the beginning, the
     * onAntennaStateChange callback must be called within this time.
     */
    public static final int ANTENNA_DISCONNECTED_TIMEOUT_MS = 100;
    public static final int LIST_COMPLETE_TIMEOUT_MS = 300000;
    public static final String toString(int o) {
        if (o == INVALID_IMAGE) {
            return "INVALID_IMAGE";
        }
        if (o == ANTENNA_DISCONNECTED_TIMEOUT_MS) {
            return "ANTENNA_DISCONNECTED_TIMEOUT_MS";
        }
        if (o == LIST_COMPLETE_TIMEOUT_MS) {
            return "LIST_COMPLETE_TIMEOUT_MS";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("INVALID_IMAGE"); // INVALID_IMAGE == 0
        if ((o & ANTENNA_DISCONNECTED_TIMEOUT_MS) == ANTENNA_DISCONNECTED_TIMEOUT_MS) {
            list.add("ANTENNA_DISCONNECTED_TIMEOUT_MS");
            flipped |= ANTENNA_DISCONNECTED_TIMEOUT_MS;
        }
        if ((o & LIST_COMPLETE_TIMEOUT_MS) == LIST_COMPLETE_TIMEOUT_MS) {
            list.add("LIST_COMPLETE_TIMEOUT_MS");
            flipped |= LIST_COMPLETE_TIMEOUT_MS;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

