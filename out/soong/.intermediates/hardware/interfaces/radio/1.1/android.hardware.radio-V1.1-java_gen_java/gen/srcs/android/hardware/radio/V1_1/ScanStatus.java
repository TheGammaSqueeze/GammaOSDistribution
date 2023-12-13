package android.hardware.radio.V1_1;


public final class ScanStatus {
    public static final int PARTIAL = 1;
    public static final int COMPLETE = 2;
    public static final String toString(int o) {
        if (o == PARTIAL) {
            return "PARTIAL";
        }
        if (o == COMPLETE) {
            return "COMPLETE";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        if ((o & PARTIAL) == PARTIAL) {
            list.add("PARTIAL");
            flipped |= PARTIAL;
        }
        if ((o & COMPLETE) == COMPLETE) {
            list.add("COMPLETE");
            flipped |= COMPLETE;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

