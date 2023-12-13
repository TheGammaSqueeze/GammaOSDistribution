package android.hardware.radio.V1_0;


public final class SimRefreshType {
    public static final int SIM_FILE_UPDATE = 0;
    public static final int SIM_INIT = 1;
    public static final int SIM_RESET = 2;
    public static final String toString(int o) {
        if (o == SIM_FILE_UPDATE) {
            return "SIM_FILE_UPDATE";
        }
        if (o == SIM_INIT) {
            return "SIM_INIT";
        }
        if (o == SIM_RESET) {
            return "SIM_RESET";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("SIM_FILE_UPDATE"); // SIM_FILE_UPDATE == 0
        if ((o & SIM_INIT) == SIM_INIT) {
            list.add("SIM_INIT");
            flipped |= SIM_INIT;
        }
        if ((o & SIM_RESET) == SIM_RESET) {
            list.add("SIM_RESET");
            flipped |= SIM_RESET;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

