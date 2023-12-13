package android.hardware.thermal.V1_0;


public final class CoolingType {
    /**
     * Fan cooling device speed in RPM.
     */
    public static final int FAN_RPM = 0;
    public static final String toString(int o) {
        if (o == FAN_RPM) {
            return "FAN_RPM";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("FAN_RPM"); // FAN_RPM == 0
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

