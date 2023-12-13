package android.hardware.usb.V1_0;


public final class PortPowerRole {
    /**
     * Indicates that the port does not have a power role.
     * In case of DRP, the current power role of the port is only resolved
     * when the type-c handshake happens.
     */
    public static final int NONE = 0;
    /**
     * Indicates that the port is supplying power to the other port.
     */
    public static final int SOURCE = 1;
    /**
     * Indicates that the port is sinking power from the other port.
     */
    public static final int SINK = 2;
    public static final int NUM_POWER_ROLES = 3;
    public static final String toString(int o) {
        if (o == NONE) {
            return "NONE";
        }
        if (o == SOURCE) {
            return "SOURCE";
        }
        if (o == SINK) {
            return "SINK";
        }
        if (o == NUM_POWER_ROLES) {
            return "NUM_POWER_ROLES";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("NONE"); // NONE == 0
        if ((o & SOURCE) == SOURCE) {
            list.add("SOURCE");
            flipped |= SOURCE;
        }
        if ((o & SINK) == SINK) {
            list.add("SINK");
            flipped |= SINK;
        }
        if ((o & NUM_POWER_ROLES) == NUM_POWER_ROLES) {
            list.add("NUM_POWER_ROLES");
            flipped |= NUM_POWER_ROLES;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

