package android.hardware.radio.V1_0;


public final class RadioCapabilityPhase {
    public static final int CONFIGURED = 0;
    public static final int START = 1;
    public static final int APPLY = 2;
    public static final int UNSOL_RSP = 3;
    public static final int FINISH = 4;
    public static final String toString(int o) {
        if (o == CONFIGURED) {
            return "CONFIGURED";
        }
        if (o == START) {
            return "START";
        }
        if (o == APPLY) {
            return "APPLY";
        }
        if (o == UNSOL_RSP) {
            return "UNSOL_RSP";
        }
        if (o == FINISH) {
            return "FINISH";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("CONFIGURED"); // CONFIGURED == 0
        if ((o & START) == START) {
            list.add("START");
            flipped |= START;
        }
        if ((o & APPLY) == APPLY) {
            list.add("APPLY");
            flipped |= APPLY;
        }
        if ((o & UNSOL_RSP) == UNSOL_RSP) {
            list.add("UNSOL_RSP");
            flipped |= UNSOL_RSP;
        }
        if ((o & FINISH) == FINISH) {
            list.add("FINISH");
            flipped |= FINISH;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

