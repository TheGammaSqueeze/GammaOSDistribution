package android.hardware.thermal.V2_0;


public final class CoolingType {
    public static final int FAN = 0;
    public static final int BATTERY = 1 /* ::android::hardware::thermal::V2_0::CoolingType.FAN implicitly + 1 */;
    public static final int CPU = 2 /* ::android::hardware::thermal::V2_0::CoolingType.BATTERY implicitly + 1 */;
    public static final int GPU = 3 /* ::android::hardware::thermal::V2_0::CoolingType.CPU implicitly + 1 */;
    public static final int MODEM = 4 /* ::android::hardware::thermal::V2_0::CoolingType.GPU implicitly + 1 */;
    public static final int NPU = 5 /* ::android::hardware::thermal::V2_0::CoolingType.MODEM implicitly + 1 */;
    public static final int COMPONENT = 6 /* ::android::hardware::thermal::V2_0::CoolingType.NPU implicitly + 1 */;
    public static final String toString(int o) {
        if (o == FAN) {
            return "FAN";
        }
        if (o == BATTERY) {
            return "BATTERY";
        }
        if (o == CPU) {
            return "CPU";
        }
        if (o == GPU) {
            return "GPU";
        }
        if (o == MODEM) {
            return "MODEM";
        }
        if (o == NPU) {
            return "NPU";
        }
        if (o == COMPONENT) {
            return "COMPONENT";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("FAN"); // FAN == 0
        if ((o & BATTERY) == BATTERY) {
            list.add("BATTERY");
            flipped |= BATTERY;
        }
        if ((o & CPU) == CPU) {
            list.add("CPU");
            flipped |= CPU;
        }
        if ((o & GPU) == GPU) {
            list.add("GPU");
            flipped |= GPU;
        }
        if ((o & MODEM) == MODEM) {
            list.add("MODEM");
            flipped |= MODEM;
        }
        if ((o & NPU) == NPU) {
            list.add("NPU");
            flipped |= NPU;
        }
        if ((o & COMPONENT) == COMPONENT) {
            list.add("COMPONENT");
            flipped |= COMPONENT;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

