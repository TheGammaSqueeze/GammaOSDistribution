package android.hardware.contexthub.V1_0;


public final class AsyncEventType {
    public static final int RESTARTED = 1;
    public static final String toString(int o) {
        if (o == RESTARTED) {
            return "RESTARTED";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        if ((o & RESTARTED) == RESTARTED) {
            list.add("RESTARTED");
            flipped |= RESTARTED;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

