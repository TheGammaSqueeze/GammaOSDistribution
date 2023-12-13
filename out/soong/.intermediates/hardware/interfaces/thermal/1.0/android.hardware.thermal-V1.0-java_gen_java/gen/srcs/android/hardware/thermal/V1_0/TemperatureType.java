package android.hardware.thermal.V1_0;


public final class TemperatureType {
    public static final int UNKNOWN = -1 /* -1 */;
    public static final int CPU = 0;
    public static final int GPU = 1;
    public static final int BATTERY = 2;
    public static final int SKIN = 3;
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
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

