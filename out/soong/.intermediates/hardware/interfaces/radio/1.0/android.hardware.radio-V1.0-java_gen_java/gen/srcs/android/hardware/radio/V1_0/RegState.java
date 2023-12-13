package android.hardware.radio.V1_0;


public final class RegState {
    public static final int NOT_REG_MT_NOT_SEARCHING_OP = 0;
    public static final int REG_HOME = 1;
    public static final int NOT_REG_MT_SEARCHING_OP = 2;
    public static final int REG_DENIED = 3;
    public static final int UNKNOWN = 4;
    public static final int REG_ROAMING = 5;
    public static final int NOT_REG_MT_NOT_SEARCHING_OP_EM = 10;
    public static final int NOT_REG_MT_SEARCHING_OP_EM = 12;
    public static final int REG_DENIED_EM = 13;
    public static final int UNKNOWN_EM = 14;
    public static final String toString(int o) {
        if (o == NOT_REG_MT_NOT_SEARCHING_OP) {
            return "NOT_REG_MT_NOT_SEARCHING_OP";
        }
        if (o == REG_HOME) {
            return "REG_HOME";
        }
        if (o == NOT_REG_MT_SEARCHING_OP) {
            return "NOT_REG_MT_SEARCHING_OP";
        }
        if (o == REG_DENIED) {
            return "REG_DENIED";
        }
        if (o == UNKNOWN) {
            return "UNKNOWN";
        }
        if (o == REG_ROAMING) {
            return "REG_ROAMING";
        }
        if (o == NOT_REG_MT_NOT_SEARCHING_OP_EM) {
            return "NOT_REG_MT_NOT_SEARCHING_OP_EM";
        }
        if (o == NOT_REG_MT_SEARCHING_OP_EM) {
            return "NOT_REG_MT_SEARCHING_OP_EM";
        }
        if (o == REG_DENIED_EM) {
            return "REG_DENIED_EM";
        }
        if (o == UNKNOWN_EM) {
            return "UNKNOWN_EM";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("NOT_REG_MT_NOT_SEARCHING_OP"); // NOT_REG_MT_NOT_SEARCHING_OP == 0
        if ((o & REG_HOME) == REG_HOME) {
            list.add("REG_HOME");
            flipped |= REG_HOME;
        }
        if ((o & NOT_REG_MT_SEARCHING_OP) == NOT_REG_MT_SEARCHING_OP) {
            list.add("NOT_REG_MT_SEARCHING_OP");
            flipped |= NOT_REG_MT_SEARCHING_OP;
        }
        if ((o & REG_DENIED) == REG_DENIED) {
            list.add("REG_DENIED");
            flipped |= REG_DENIED;
        }
        if ((o & UNKNOWN) == UNKNOWN) {
            list.add("UNKNOWN");
            flipped |= UNKNOWN;
        }
        if ((o & REG_ROAMING) == REG_ROAMING) {
            list.add("REG_ROAMING");
            flipped |= REG_ROAMING;
        }
        if ((o & NOT_REG_MT_NOT_SEARCHING_OP_EM) == NOT_REG_MT_NOT_SEARCHING_OP_EM) {
            list.add("NOT_REG_MT_NOT_SEARCHING_OP_EM");
            flipped |= NOT_REG_MT_NOT_SEARCHING_OP_EM;
        }
        if ((o & NOT_REG_MT_SEARCHING_OP_EM) == NOT_REG_MT_SEARCHING_OP_EM) {
            list.add("NOT_REG_MT_SEARCHING_OP_EM");
            flipped |= NOT_REG_MT_SEARCHING_OP_EM;
        }
        if ((o & REG_DENIED_EM) == REG_DENIED_EM) {
            list.add("REG_DENIED_EM");
            flipped |= REG_DENIED_EM;
        }
        if ((o & UNKNOWN_EM) == UNKNOWN_EM) {
            list.add("UNKNOWN_EM");
            flipped |= UNKNOWN_EM;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

