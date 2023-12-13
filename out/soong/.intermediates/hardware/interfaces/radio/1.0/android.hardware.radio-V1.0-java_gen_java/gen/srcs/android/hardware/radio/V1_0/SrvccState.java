package android.hardware.radio.V1_0;


public final class SrvccState {
    public static final int HANDOVER_STARTED = 0;
    public static final int HANDOVER_COMPLETED = 1;
    public static final int HANDOVER_FAILED = 2;
    public static final int HANDOVER_CANCELED = 3;
    public static final String toString(int o) {
        if (o == HANDOVER_STARTED) {
            return "HANDOVER_STARTED";
        }
        if (o == HANDOVER_COMPLETED) {
            return "HANDOVER_COMPLETED";
        }
        if (o == HANDOVER_FAILED) {
            return "HANDOVER_FAILED";
        }
        if (o == HANDOVER_CANCELED) {
            return "HANDOVER_CANCELED";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("HANDOVER_STARTED"); // HANDOVER_STARTED == 0
        if ((o & HANDOVER_COMPLETED) == HANDOVER_COMPLETED) {
            list.add("HANDOVER_COMPLETED");
            flipped |= HANDOVER_COMPLETED;
        }
        if ((o & HANDOVER_FAILED) == HANDOVER_FAILED) {
            list.add("HANDOVER_FAILED");
            flipped |= HANDOVER_FAILED;
        }
        if ((o & HANDOVER_CANCELED) == HANDOVER_CANCELED) {
            list.add("HANDOVER_CANCELED");
            flipped |= HANDOVER_CANCELED;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

