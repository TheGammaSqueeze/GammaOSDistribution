package android.hardware.audio.common.V2_0;


public final class AudioInterleave {
    public static final int LEFT = 0;
    public static final int RIGHT = 1;
    public static final String toString(int o) {
        if (o == LEFT) {
            return "LEFT";
        }
        if (o == RIGHT) {
            return "RIGHT";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        list.add("LEFT"); // LEFT == 0
        if ((o & RIGHT) == RIGHT) {
            list.add("RIGHT");
            flipped |= RIGHT;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

