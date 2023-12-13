package android.hardware.radio.V1_0;


public final class HardwareConfigType {
    public static final int MODEM = 0;
    public static final int SIM = 1 /* ::android::hardware::radio::V1_0::HardwareConfigType.MODEM implicitly + 1 */;
    public static final String toString(int o) {
        if (o == MODEM) {
            return "MODEM";
        }
        if (o == SIM) {
            return "SIM";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("MODEM"); // MODEM == 0
        if ((o & SIM) == SIM) {
            list.add("SIM");
            flipped |= SIM;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

