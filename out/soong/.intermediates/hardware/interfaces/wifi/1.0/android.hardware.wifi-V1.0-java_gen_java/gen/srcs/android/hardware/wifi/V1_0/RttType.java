package android.hardware.wifi.V1_0;


public final class RttType {
    public static final int ONE_SIDED = 1 /* 0x1 */;
    public static final int TWO_SIDED = 2 /* 0x2 */;
    public static final String toString(int o) {
        if (o == ONE_SIDED) {
            return "ONE_SIDED";
        }
        if (o == TWO_SIDED) {
            return "TWO_SIDED";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        if ((o & ONE_SIDED) == ONE_SIDED) {
            list.add("ONE_SIDED");
            flipped |= ONE_SIDED;
        }
        if ((o & TWO_SIDED) == TWO_SIDED) {
            list.add("TWO_SIDED");
            flipped |= TWO_SIDED;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

