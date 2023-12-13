package android.hardware.thermal.V2_0;


public final class TemperatureType {
    public static final int UNKNOWN = -1 /* -1 */;
    public static final int CPU = 0;
    public static final int GPU = 1;
    public static final int BATTERY = 2;
    public static final int SKIN = 3;
    public static final int USB_PORT = 4;
    public static final int POWER_AMPLIFIER = 5;
    /**
     * Battery Charge Limit - virtual thermal sensors
     */
    public static final int BCL_VOLTAGE = 6;
    public static final int BCL_CURRENT = 7;
    public static final int BCL_PERCENTAGE = 8;
    /**
     * Neural Processing Unit
     */
    public static final int NPU = 9;
    public static final String toString(int o) {
        if (o == UNKNOWN) {
            return "UNKNOWN";
        }
        if (o == CPU) {
            return "CPU";
        }
        if (o == GPU) {
            return "GPU";
        }
        if (o == BATTERY) {
            return "BATTERY";
        }
        if (o == SKIN) {
            return "SKIN";
        }
        if (o == USB_PORT) {
            return "USB_PORT";
        }
        if (o == POWER_AMPLIFIER) {
            return "POWER_AMPLIFIER";
        }
        if (o == BCL_VOLTAGE) {
            return "BCL_VOLTAGE";
        }
        if (o == BCL_CURRENT) {
            return "BCL_CURRENT";
        }
        if (o == BCL_PERCENTAGE) {
            return "BCL_PERCENTAGE";
        }
        if (o == NPU) {
            return "NPU";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        if ((o & UNKNOWN) == UNKNOWN) {
            list.add("UNKNOWN");
            flipped |= UNKNOWN;
        }
        list.add("CPU"); // CPU == 0
        if ((o & GPU) == GPU) {
            list.add("GPU");
            flipped |= GPU;
        }
        if ((o & BATTERY) == BATTERY) {
            list.add("BATTERY");
            flipped |= BATTERY;
        }
        if ((o & SKIN) == SKIN) {
            list.add("SKIN");
            flipped |= SKIN;
        }
        if ((o & USB_PORT) == USB_PORT) {
            list.add("USB_PORT");
            flipped |= USB_PORT;
        }
        if ((o & POWER_AMPLIFIER) == POWER_AMPLIFIER) {
            list.add("POWER_AMPLIFIER");
            flipped |= POWER_AMPLIFIER;
        }
        if ((o & BCL_VOLTAGE) == BCL_VOLTAGE) {
            list.add("BCL_VOLTAGE");
            flipped |= BCL_VOLTAGE;
        }
        if ((o & BCL_CURRENT) == BCL_CURRENT) {
            list.add("BCL_CURRENT");
            flipped |= BCL_CURRENT;
        }
        if ((o & BCL_PERCENTAGE) == BCL_PERCENTAGE) {
            list.add("BCL_PERCENTAGE");
            flipped |= BCL_PERCENTAGE;
        }
        if ((o & NPU) == NPU) {
            list.add("NPU");
            flipped |= NPU;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

