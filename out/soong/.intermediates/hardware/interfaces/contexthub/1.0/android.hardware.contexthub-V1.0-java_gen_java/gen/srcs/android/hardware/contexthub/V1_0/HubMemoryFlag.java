package android.hardware.contexthub.V1_0;


public final class HubMemoryFlag {
    public static final int READ = 1 /* 1 << 0 */;
    public static final int WRITE = 2 /* 1 << 1 */;
    public static final int EXEC = 4 /* 1 << 2 */;
    public static final String toString(int o) {
        if (o == READ) {
            return "READ";
        }
        if (o == WRITE) {
            return "WRITE";
        }
        if (o == EXEC) {
            return "EXEC";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        if ((o & READ) == READ) {
            list.add("READ");
            flipped |= READ;
        }
        if ((o & WRITE) == WRITE) {
            list.add("WRITE");
            flipped |= WRITE;
        }
        if ((o & EXEC) == EXEC) {
            list.add("EXEC");
            flipped |= EXEC;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

