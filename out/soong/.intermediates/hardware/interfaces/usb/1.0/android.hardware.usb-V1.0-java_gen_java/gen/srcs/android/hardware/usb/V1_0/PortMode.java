package android.hardware.usb.V1_0;


public final class PortMode {
    /**
     * Indicates that the port does not have a mode.
     * In case of DRP, the current mode of the port is only resolved
     * when the type-c handshake happens.
     */
    public static final int NONE = 0;
    /**
     * Indicates that port can only act as device for data and sink for power.
     */
    public static final int UFP = 1;
    /**
     * Indicates the port can only act as host for data and source for power.
     */
    public static final int DFP = 2;
    /**
     * Indicates can either act as UFP or DFP at a given point of time.
     */
    public static final int DRP = 3;
    public static final int NUM_MODES = 4;
    public static final String toString(int o) {
        if (o == NONE) {
            return "NONE";
        }
        if (o == UFP) {
            return "UFP";
        }
        if (o == DFP) {
            return "DFP";
        }
        if (o == DRP) {
            return "DRP";
        }
        if (o == NUM_MODES) {
            return "NUM_MODES";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("NONE"); // NONE == 0
        if ((o & UFP) == UFP) {
            list.add("UFP");
            flipped |= UFP;
        }
        if ((o & DFP) == DFP) {
            list.add("DFP");
            flipped |= DFP;
        }
        if ((o & DRP) == DRP) {
            list.add("DRP");
            flipped |= DRP;
        }
        if ((o & NUM_MODES) == NUM_MODES) {
            list.add("NUM_MODES");
            flipped |= NUM_MODES;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

