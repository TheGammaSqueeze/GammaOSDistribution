package android.hardware.usb.V1_0;


public final class PortDataRole {
    /**
     * Indicates that the port does not have a data role.
     * In case of DRP, the current data role of the port is only resolved
     * when the type-c handshake happens.
     */
    public static final int NONE = 0;
    /**
     * Indicates that the port is acting as a host for data.
     */
    public static final int HOST = 1;
    /**
     * Indicated that the port is acting as a device for data.
     */
    public static final int DEVICE = 2;
    public static final int NUM_DATA_ROLES = 3;
    public static final String toString(int o) {
        if (o == NONE) {
            return "NONE";
        }
        if (o == HOST) {
            return "HOST";
        }
        if (o == DEVICE) {
            return "DEVICE";
        }
        if (o == NUM_DATA_ROLES) {
            return "NUM_DATA_ROLES";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("NONE"); // NONE == 0
        if ((o & HOST) == HOST) {
            list.add("HOST");
            flipped |= HOST;
        }
        if ((o & DEVICE) == DEVICE) {
            list.add("DEVICE");
            flipped |= DEVICE;
        }
        if ((o & NUM_DATA_ROLES) == NUM_DATA_ROLES) {
            list.add("NUM_DATA_ROLES");
            flipped |= NUM_DATA_ROLES;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

