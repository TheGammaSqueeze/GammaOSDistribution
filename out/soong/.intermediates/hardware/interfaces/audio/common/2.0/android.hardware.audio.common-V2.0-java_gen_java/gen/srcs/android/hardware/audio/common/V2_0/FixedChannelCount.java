package android.hardware.audio.common.V2_0;


public final class FixedChannelCount {
    public static final int FCC_2 = 2;
    public static final int FCC_8 = 8;
    public static final String toString(int o) {
        if (o == FCC_2) {
            return "FCC_2";
        }
        if (o == FCC_8) {
            return "FCC_8";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        if ((o & FCC_2) == FCC_2) {
            list.add("FCC_2");
            flipped |= FCC_2;
        }
        if ((o & FCC_8) == FCC_8) {
            list.add("FCC_8");
            flipped |= FCC_8;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

