package android.hardware.usb.V1_0;


public final class PortRoleType {
    /**
     * Denotes the data role of the port.
     * The port can either be a "host" or a "device" for data.
     * This maps to the PortDataRole enum.
     */
    public static final int DATA_ROLE = 0;
    /**
     * Denotes the power role of the port.
     * The port can either be a "source" or "sink" for power.
     * This maps to PortPowerRole enum.
     */
    public static final int POWER_ROLE = 1;
    /**
     * USB ports can be a pure DFP port which can only act
     * as a host. A UFP port which can only act as a device.
     * Or a dual role ports which can either can as a host or
     * a device. This property is used to mention them.
     */
    public static final int MODE = 2;
    public static final String toString(int o) {
        if (o == DATA_ROLE) {
            return "DATA_ROLE";
        }
        if (o == POWER_ROLE) {
            return "POWER_ROLE";
        }
        if (o == MODE) {
            return "MODE";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("DATA_ROLE"); // DATA_ROLE == 0
        if ((o & POWER_ROLE) == POWER_ROLE) {
            list.add("POWER_ROLE");
            flipped |= POWER_ROLE;
        }
        if ((o & MODE) == MODE) {
            list.add("MODE");
            flipped |= MODE;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

