package android.hardware.contexthub.V1_0;


public final class NanoAppFlags {
    public static final int SIGNED = 1 /* 1 << 0 */;
    public static final int ENCRYPTED = 2 /* 1 << 1 */;
    public static final String toString(int o) {
        if (o == SIGNED) {
            return "SIGNED";
        }
        if (o == ENCRYPTED) {
            return "ENCRYPTED";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        if ((o & SIGNED) == SIGNED) {
            list.add("SIGNED");
            flipped |= SIGNED;
        }
        if ((o & ENCRYPTED) == ENCRYPTED) {
            list.add("ENCRYPTED");
            flipped |= ENCRYPTED;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

