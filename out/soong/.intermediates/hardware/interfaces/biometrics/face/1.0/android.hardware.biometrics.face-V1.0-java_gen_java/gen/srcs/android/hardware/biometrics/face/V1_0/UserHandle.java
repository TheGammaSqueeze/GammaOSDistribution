package android.hardware.biometrics.face.V1_0;


public final class UserHandle {
    public static final int NONE = -1 /* -1 */;
    public static final String toString(int o) {
        if (o == NONE) {
            return "NONE";
        }
        return "0x" + Integer.toHexString(o);
    }

    public static final String dumpBitfield(int o) {
        java.util.ArrayList<String> list = new java.util.ArrayList<>();
        int flipped = 0;
        if ((o & NONE) == NONE) {
            list.add("NONE");
            flipped |= NONE;
        }
        if (o != flipped) {
            list.add("0x" + Integer.toHexString(o & (~flipped)));
        }
        return String.join(" | ", list);
    }

};

