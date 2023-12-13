package android.hardware.contexthub.V1_0;


public final class HubMemoryType {
    public static final int MAIN = 0;
    public static final int SECONDARY = 1;
    public static final int TCM = 2;
    public static final String toString(int o) {
        if (o == MAIN) {
            return "MAIN";
        }
        if (o == SECONDARY) {
            return "SECONDARY";
        }
        if (o == TCM) {
            return "TCM";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("MAIN"); // MAIN == 0
        if ((o & SECONDARY) == SECONDARY) {
            list.add("SECONDARY");
            flipped |= SECONDARY;
        }
        if ((o & TCM) == TCM) {
            list.add("TCM");
            flipped |= TCM;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

