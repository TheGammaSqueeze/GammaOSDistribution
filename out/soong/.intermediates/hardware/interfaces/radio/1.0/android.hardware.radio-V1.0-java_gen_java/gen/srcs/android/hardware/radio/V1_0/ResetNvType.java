package android.hardware.radio.V1_0;


public final class ResetNvType {
    public static final int RELOAD = 0;
    public static final int ERASE = 1 /* ::android::hardware::radio::V1_0::ResetNvType.RELOAD implicitly + 1 */;
    public static final int FACTORY_RESET = 2 /* ::android::hardware::radio::V1_0::ResetNvType.ERASE implicitly + 1 */;
    public static final String toString(int o) {
        if (o == RELOAD) {
            return "RELOAD";
        }
        if (o == ERASE) {
            return "ERASE";
        }
        if (o == FACTORY_RESET) {
            return "FACTORY_RESET";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("RELOAD"); // RELOAD == 0
        if ((o & ERASE) == ERASE) {
            list.add("ERASE");
            flipped |= ERASE;
        }
        if ((o & FACTORY_RESET) == FACTORY_RESET) {
            list.add("FACTORY_RESET");
            flipped |= FACTORY_RESET;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

