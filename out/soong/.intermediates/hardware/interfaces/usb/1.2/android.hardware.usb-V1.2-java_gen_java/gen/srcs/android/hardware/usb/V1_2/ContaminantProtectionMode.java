package android.hardware.usb.V1_2;


public final class ContaminantProtectionMode {
    /**
     * No action performed upon detection of contaminant presence.
     */
    public static final int NONE = 0;
    /**
     * Upon detection of contaminant presence, Port is forced to sink only
     * mode where a port shall only detect chargers until contaminant presence
     * is no longer detected.
     */
    public static final int FORCE_SINK = 1 /* 1 << 0 */;
    /**
     * Upon detection of contaminant presence, Port is forced to source only
     * mode where a port shall only detect usb accessories such as headsets
     * until contaminant presence is no longer detected.
     */
    public static final int FORCE_SOURCE = 2 /* 1 << 1 */;
    /**
     * Upon detection of contaminant presence, port is disabled until contaminant
     * presence is no longer detected. In the disabled state port will
     * not respond to connection of chargers or usb accessories.
     */
    public static final int FORCE_DISABLE = 4 /* 1 << 2 */;
    public static final String toString(int o) {
        if (o == NONE) {
            return "NONE";
        }
        if (o == FORCE_SINK) {
            return "FORCE_SINK";
        }
        if (o == FORCE_SOURCE) {
            return "FORCE_SOURCE";
        }
        if (o == FORCE_DISABLE) {
            return "FORCE_DISABLE";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("NONE"); // NONE == 0
        if ((o & FORCE_SINK) == FORCE_SINK) {
            list.add("FORCE_SINK");
            flipped |= FORCE_SINK;
        }
        if ((o & FORCE_SOURCE) == FORCE_SOURCE) {
            list.add("FORCE_SOURCE");
            flipped |= FORCE_SOURCE;
        }
        if ((o & FORCE_DISABLE) == FORCE_DISABLE) {
            list.add("FORCE_DISABLE");
            flipped |= FORCE_DISABLE;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

