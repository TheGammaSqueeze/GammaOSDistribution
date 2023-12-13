package android.hardware.radio.V1_0;


public final class TtyMode {
    public static final int OFF = 0;
    public static final int FULL = 1 /* ::android::hardware::radio::V1_0::TtyMode.OFF implicitly + 1 */;
    public static final int HCO = 2 /* ::android::hardware::radio::V1_0::TtyMode.FULL implicitly + 1 */;
    public static final int VCO = 3 /* ::android::hardware::radio::V1_0::TtyMode.HCO implicitly + 1 */;
    public static final String toString(int o) {
        if (o == OFF) {
            return "OFF";
        }
        if (o == FULL) {
            return "FULL";
        }
        if (o == HCO) {
            return "HCO";
        }
        if (o == VCO) {
            return "VCO";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("OFF"); // OFF == 0
        if ((o & FULL) == FULL) {
            list.add("FULL");
            flipped |= FULL;
        }
        if ((o & HCO) == HCO) {
            list.add("HCO");
            flipped |= HCO;
        }
        if ((o & VCO) == VCO) {
            list.add("VCO");
            flipped |= VCO;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

