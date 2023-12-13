package android.hardware.radio.V1_1;


public final class ScanType {
    public static final int ONE_SHOT = 0;
    public static final int PERIODIC = 1;
    public static final String toString(int o) {
        if (o == ONE_SHOT) {
            return "ONE_SHOT";
        }
        if (o == PERIODIC) {
            return "PERIODIC";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("ONE_SHOT"); // ONE_SHOT == 0
        if ((o & PERIODIC) == PERIODIC) {
            list.add("PERIODIC");
            flipped |= PERIODIC;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

